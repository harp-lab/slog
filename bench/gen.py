#!/usr/bin/env python3
"""Random-graph generators for slog join-pipeline stress tests.

Writes each graph directly as a slog binary database under data/bench_*/
(the daemon's BIN format: data/<db>/table.<name>.arity.<A>/0.bin holding
raw little-endian u64 words, arity words per tuple, s32-encoded) -- inline
`facts` blocks funnel every fact through one compiled rule, which is fine
for tests but not for hundred-thousand-edge graphs.  Query programs run
against these with `racket slog.rkt -d bench_<graph> ...`.

All generation is seeded: regenerating produces identical databases.

Usage:  python3 bench/gen.py
"""

import os
import random
import shutil
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def s32_encode(v):
    """NaN-boxed 32-bit integer (daemon/types.h s32_encode)."""
    return 0x7FF0000000000000 | (1 << 35) | (v & 0xFFFFFFFF)


def write_bin_db(dbname, rels):
    """rels: dict name -> (arity, iterable of int tuples)."""
    d = os.path.join(ROOT, "data", dbname)
    shutil.rmtree(d, ignore_errors=True)
    os.makedirs(os.path.join(d, "value.strings"))
    total = 0
    for name, (arity, tuples) in rels.items():
        rd = os.path.join(d, "table.%s.arity.%d" % (name, arity))
        os.makedirs(rd)
        with open(os.path.join(rd, "0.bin"), "wb") as f:
            for t in tuples:
                assert len(t) == arity
                f.write(struct.pack("<%dQ" % arity, *map(s32_encode, t)))
                total += 1
    print("  data/%-24s %8d tuples" % (dbname, total))


def er_graph(rng, n, m, self_loops=False):
    """Erdos-Renyi-ish: m distinct directed edges over n nodes."""
    edges = set()
    while len(edges) < m:
        a = rng.randrange(n)
        b = rng.randrange(n)
        if not self_loops and a == b:
            continue
        edges.add((a, b))
    return sorted(edges)


def double_star(n, hub=0):
    """Bipartite explosion: n spokes -> hub, hub -> n other spokes.
    Number of 2-paths through the hub is n^2."""
    r = [(i, hub) for i in range(1, n + 1)]           # spokes -> hub
    s = [(hub, j) for j in range(n + 1, 2 * n + 1)]   # hub -> other spokes
    return r, s


def planted_cliques(rng, n, m, sizes):
    """Sparse ER background + planted cliques (all ordered pairs, both
    directions, no self loops) on disjoint node ranges above the id space."""
    edges = set(er_graph(rng, n, m))
    base = n
    for k in sizes:
        nodes = list(range(base, base + k))
        base += k
        for a in nodes:
            for b in nodes:
                if a != b:
                    edges.add((a, b))
    return sorted(edges)


def broom_tree(spine, fanout):
    """A chain of `spine` nodes (0 -> 1 -> ... -> spine-1), each spine node
    also parenting `fanout` leaves.  Deep (levels stay small, so
    same-generation stays ~n*fanout) but fanout/(fanout+1) of every level
    is leaves -- the shape where same-generation's "does PY have children?"
    filter saves a full fan-out per pruned pair.  (A uniform random tree
    has average out-degree < 1, so there the filter saves ~1 probe per
    probe spent -- net zero; and a shallow preferential-attachment tree
    makes sg itself quadratic in the level sizes and OOMs.)"""
    edges = [(i, i + 1) for i in range(spine - 1)]
    nxt = spine
    for i in range(spine):
        for _ in range(fanout):
            edges.append((i, nxt))
            nxt += 1
    return edges


def bipartite_random(rng, nl, nr, m):
    """Directed bipartite edges in both directions: has 4-cycles but NO odd
    cycles (no triangles/5-cycles) -- binary joins still enumerate 2-paths."""
    edges = set()
    while len(edges) < m:
        a = rng.randrange(nl)
        b = rng.randrange(nr)
        if rng.random() < 0.5:
            edges.add((a, nl + b))
        else:
            edges.add((nl + b, a))
    return sorted(edges)


def main():
    print("writing binary databases under data/")

    # -- er: triangle stress (dense) -----------------------------------------
    rng = random.Random(1)
    write_bin_db("bench_er", {"edge": (2, er_graph(rng, 10000, 600000))})

    # -- er_mid: 4-cycle stress (4 joins over deg-20 keeps 3-paths ~80M) -----
    rng = random.Random(7)
    write_bin_db("bench_er_mid", {"edge": (2, er_graph(rng, 10000, 200000))})

    # -- er_sparse: 5-cycle stress (5 joins amplify) + reachability ----------
    rng = random.Random(2)
    write_bin_db("bench_er_sparse",
                 {"edge": (2, er_graph(rng, 10000, 100000)),
                  "source": (1, [(i,) for i in range(200)])})

    # -- hub: THE pathological case ------------------------------------------
    # R join S enumerates n^2 pairs; T (attributed, 3 cols so it can never
    # be the driver) is disjoint from R/S, so a semijoin filter after the
    # driver prunes everything: O(n^2) -> O(n).
    n = 40000
    r, s = double_star(n)
    t = [(90000001, 90000002, 7)]
    write_bin_db("bench_hub", {"redge": (2, r), "sedge": (2, s),
                               "tedge": (3, t)})

    # -- hub_closing: same explosion, T selective (k spokes participate) -----
    rng = random.Random(3)
    k = 60
    chosen = rng.sample(range(1, n + 1), k)
    t2 = sorted((n + 1 + (i % n), a, i) for i, a in enumerate(chosen))
    write_bin_db("bench_hub_closing", {"redge": (2, r), "sedge": (2, s),
                                       "tedge": (3, t2)})

    # -- cliques: planted cliques in sparse noise ----------------------------
    rng = random.Random(4)
    write_bin_db("bench_cliques",
                 {"edge": (2, planted_cliques(rng, 6000, 150000,
                                              [12, 10, 10, 8, 8, 6, 6]))})

    # -- tree: same-generation with recursion-internal filters ---------------
    write_bin_db("bench_tree", {"edge": (2, broom_tree(5000, 20))})

    # -- walk: the hub pathology INSIDE recursion -----------------------------
    # visit(A) expands through the hub to ALL n spokes each iteration, then
    # tedge (a 16-ary tree, child<-parent) keeps only A's children.  With
    # filters, a leaf A is pruned for one probe instead of an n-way
    # expansion; internal nodes are 1/16 of the tree, so OFF ~ n^2 while
    # ON ~ n^2/16 + n.  Fixpoint depth = tree depth (4).
    n = 30000
    fan = 16
    tree = [(c, (c - 2) // fan + 1, c) for c in range(2, n + 1)]
    write_bin_db("bench_walk",
                 {"redge": (2, ((i, 0) for i in range(1, n + 1))),
                  "sedge": (2, ((0, j) for j in range(1, n + 1))),
                  "tedge": (3, tree),
                  "visit": (1, [(1,)])})

    # -- bipartite: no odd cycles at all -------------------------------------
    rng = random.Random(5)
    write_bin_db("bench_bipartite",
                 {"edge": (2, bipartite_random(rng, 2000, 2000, 500000))})


if __name__ == "__main__":
    main()
