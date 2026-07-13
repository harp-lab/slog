# Semijoin existence filters

*(2026-07-03; implemented in operationalization.rkt "Semijoin filters",
daemon/operators.h `exists_probe`, emitted by emit-cpp.rkt as `(exists ...)`
ops; toggle: `SLOG_NO_SEMIJOIN=1`, params.rkt `semijoin-filters-enabled`.)*

## 1. The problem

A rule body compiles to one fused push pipeline per semi-naive version:
driver scan/probe, then a chain of index probes, each binding more
variables.  The pipeline's cost is the number of partial tuples that flow
through each stage — and a stage that binds fresh variables (an *expanding*
join) can multiply that number.  When a *later* clause would reject most of
what an expanding join produces, the classic pathology appears: the
pipeline enumerates an intermediate far larger than both input and output.

The star join is the canonical case.  With `R` = spokes→hub, `S` =
hub→spokes, and a selective third relation `T`:

    rule (redge A B) (sedge B C) (tedge C A W) --> (tri A B C)

`R ⋈ S` enumerates n² (a, hub, c) triples before `T` rejects them —
Ω(n²) work for O(n)-sized input and (possibly empty) output.

## 2. What we do: Yannakakis-style lookahead, pipelined

Yannakakis' algorithm (VLDB 1981) evaluates acyclic queries in O(N + OUT)
by running a *semijoin program* first: every relation is reduced to the
tuples that can participate in the final join.  Materializing full semijoin
passes is too invasive for a fused pipeline (and measurably ~5x overhead
when applied blindly — Birler et al., PVLDB 2024), but the same pruning
drops into the pipeline as a *filter*:

> Just before each expanding join, for every future clause of the schedule
> that already has some of its columns bound, probe that clause's relation
> once — "does ANY tuple match these bound columns?" — and abandon the
> partial tuple on a miss.

The filter is one `lower_bound` + prefix compare per partial tuple
(`exists_probe<A,K>`, daemon/operators.h) against an index whose ordering
leads with exactly the bound columns.  In the star join above the filter
runs right after the driver and kills every non-participating spoke before
the n-way fan-out: O(n²) collapses to O(n).

## 3. Conservative placement policy

Filters are chosen by `semijoin-filters` (operationalization.rkt), a pure
function of the planned rule body that both the select-set pass (index
requisition) and the lowering pass consume — so the index a filter probes
is always registered, by construction.  The policy:

  - place filters only immediately **before an expanding join** (one that
    binds at least one fresh variable): a filter before a non-expanding
    probe could only reorder two constant-cost checks;
  - filter a future clause only when its bound-column set is non-empty and
    has **grown** since the last filter placed for it;
  - **deduplicate** identical probes at the same point;
  - **skip** lattice relations (payload maps, no set index), temp relations
    (index-free by design), and structs probed only on their id column (an
    interned id is present by construction);
  - a rule with fewer than three join clauses gets no filters at all — the
    common transitive-closure/path shape is untouched.

Consequences: `path(X,Z) :- path(X,Y), edge(Y,Z)` compiles exactly as
before; the triangle query gains one probe per driver tuple; a k-cycle
query gains one destination-keyed probe; a star join gains the probe that
saves it.

## 4. Index requisition

A filter needs an index of the future clause's relation whose ordering
leads with the filter's bound columns.  Each filter's column set is fed
into the same select-set machinery joins use (`add-select-sets`), so the
selection is folded into a compatible prefix chain when possible; the
resulting index is written by the standard per-iteration `WriteTask`s and
reloaded across strata like any other.  For 2-ary relations the filter
selections usually coincide with an
ordering some join already demanded; the typical genuinely-new cost is a
destination-keyed `(1 0)` ordering for cyclic queries.  Operationalization's
greedy prefix-chain packer folds subset-compatible filter and join selections
into one ordering.

## 5. Soundness under semi-naive evaluation

A filter probes the same full-index snapshot (`getIndex(ord, false)`) that
the future join itself reads in the same read phase — indices mutate only
in the write/intern phases.  So a pruned partial tuple could not have
joined *this iteration*.  If the future clause's relation grows *later*,
semi-naive evaluation already re-derives the combination through that
clause's own delta-driven rule version, exactly as it would without
filters.  Filters never probe deltas and are never placed before the
driver, so no version's delta semantics change.  (This is the standard SIP
soundness argument; cf. Souffle's existence checks and the predicate-
transfer literature.)

## 6. What filters cannot do (and what would)

Prefix-existence pruning recovers the acyclic/Yannakakis wins but **cannot
fix dense cyclic queries**: counting triangles on a bipartite-plus-noise
graph still enumerates every 2-path, because every node has *some*
out-edge — the filter passes everything, and only a worst-case-optimal
join (LFTJ-style k-way intersection, AGM bound) closes that gap.  The
benchmark `bench/tri_bipartite.slog` pins this boundary.

Natural next steps, in rough order of value:

  1. **Bloom sidecars**: replace the btree probe with an L1-resident Bloom
     filter per (relation, column-set), rebuilt per iteration from deltas —
     cheaper probes, same policy (Predicate Transfer, CIDR 2024; RPT,
     SIGMOD 2025).
  2. **Adaptive disabling**: count probe hit-rates per filter at runtime
     and stop probing when a filter passes ~everything (LIP, PVLDB 2017).
  3. **Backjumping** on the final clause's misses (TreeTracker, TODS
     2025): gets the full O(N + OUT) guarantee for acyclic bodies with no
     upfront passes.
  4. A ternary **WCOJ operator** for the cyclic cores that filters
     provably cannot help.

## 7. Measurements

See `bench/` (generators + runner: `python3 bench/gen.py`, then
`bench/bench.sh`; each program declares its input database in a `;; db:`
header line).  Timings are the daemon's per-stratum fixpoint wall time
(`(fixpoint <name> <iters> <ms>)`), medians over 3 runs on an 8-core
machine, filters OFF (`SLOG_NO_SEMIJOIN=1`) vs ON, outputs diffed for
equality (all identical).  2026-07-03:

    test              graph                          off-ms    on-ms   speedup
    tri_er            ER n=10k m=600k                 258.4    294.6     0.88x
    cyc4_er           ER n=10k m=200k                 380.9    384.8     0.99x
    cyc5_er           ER n=10k m=100k                 507.2    504.4     1.01x
    tri_bipartite     bipartite 2k+2k m=500k          293.9    265.9     1.11x
    clique4_cliques   ER n=6k m=150k + cliques         91.3     98.3     0.93x
    hub_tri           double star n=40k              1513.8      4.9      309x
    hub_closing_tri   double star + 60 closers       2190.4      8.4      261x
    walk_hub          recursive hub walk n=30k       6774.5    277.7     24.4x
    sg_tree           same-gen, broom 5000x20         151.0    146.7     1.03x
    reach_er          multi-source TC                1082.1   1086.4     1.00x

Star-join scaling (`bench/scaling.sh`, one run per point): OFF grows
quadratically in the spoke count, ON linearly, so the speedup grows
without bound —

    n (spokes)      off-ms      on-ms    speedup
        10000         75.4        1.3        58x
        20000        280.9        2.2       128x
        40000       1040.6        4.9       212x
        80000       4588.6       10.2       450x
       160000      29884.0       18.4      1624x

Reading the table: the star join (static and recursive) is the class the
filters exist for; `walk_hub` shows the win repeating every fixpoint
iteration.  Filter overhead when nothing prunes sits inside a ±10% noise
band (tri_er's 600k never-pruning probes are the honest worst case, ~7-12%).
`sg_tree` is the instructive wash: an existence probe costs about one join
probe, and in same-generation the guarded expansion averages one child —
prune-rate alone doesn't pay; the *fan-out behind the check* must.
`tri_bipartite` pins the boundary that needs WCOJ, not filters.
