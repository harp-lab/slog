# Strongly connected components in Slog

There are two materially different answers to “can Slog compute SCCs?”

## The idiomatic answer: mutual reachability

[`scc.slog`](scc.slog) is the version to start with.  Its computational core
is only four rules:

```slog
rule (edge x y) --> (vertex x) (vertex y)
rule (vertex x) --> (reachable x x)
rule (reachable x y) (edge y z) --> (reachable x z)

rule (reachable x y) (reachable y x)
     (= singleton (cins (cmap) y))
  --> (scc x singleton)
```

`scc(x, C)` maps every vertex to the canonical set containing its component.
Vertices in the same component receive the same interned set value, so `C` is
also a generic component identifier.  This avoids choosing a representative
from values of type `any`, for which Slog deliberately exposes no semantic
total order.  In CSV output a native set currently renders as a map to unit,
for example `{1:1 2:1 3:1}`.

The input declaration is `edge(any, any)`.  Edge rows may come from facts,
other rules, an `include`, a prerequisite `run`, or a loaded database.  Slog
does not currently parameterize a library over a relation name, so rename the
declaration/rule occurrences if the source relation is not called `edge`.
With only a two-column edge relation, isolated vertices are unrepresentable;
explicit `vertex` rows can be added when the surrounding model has them.

This version is declarative, parallel, indexed, and semi-naive.  It also
materializes transitive closure.  Its worst-case result space is
`Theta(|V|^2)` even when every SCC is a singleton.  That is often acceptable
when the graph is modest, reachability is useful elsewhere, or components are
large; it is the wrong representation for a very large sparse DAG.

## Literal Tarjan: possible, but not a good runtime fit

[`tarjan.slog`](tarjan.slog) is a working functional transcription of
Tarjan's algorithm.  It first closes the edge relation into canonical vertex
and adjacency lists, then threads this immutable state through recursive
demands:

```text
[next-index, stack, index-map, lowlink-map, on-stack-set, components-set]
```

At the algorithmic level it discovers each vertex once and examines each
outgoing edge once.  It therefore avoids the all-pairs `reachable` relation.
It is nevertheless neither short nor a production-quality linear-time
implementation in Slog:

- DFS is inherently sequential here, so dependent demand calls advance over
  many global fixpoint barriers and cannot use Slog's graph parallelism.
- Every state is a new persistent list/map/set value and is retained in
  request, answer, and continuation relations.
- Native collection updates add trie/sequence work to each logical step.
- The traversal order comes from `set2lst`.  Correctness is independent of
  that order, but it must not be interpreted as numeric or lexical order.

On the seven-vertex graph embedded in both examples, the mutual-reachability
stratum takes 7 fixpoint iterations and materializes 26 reachable pairs.  The
main demand SCC of the Tarjan transcription takes 120 iterations.  Both emit
the same result:

```text
1,2,3 -> {1,2,3}
4,5   -> {4,5}
6     -> {6}
7     -> {7}
```

The Tarjan version can still be useful as an executable specification, or as
a pure-Slog fallback when quadratic closure storage is the hard constraint.
Measure it on the actual graph before choosing it.

## Recommendation for large graphs

For genuinely large sparse graphs, the right addition is a native,
relation-level SCC operator.  It should scan a settled two-column relation,
compress arbitrary Slog vertex words to dense indices, run iterative Tarjan
or Kosaraju in `O(|V| + |E|)` time and space, then emit `(vertex, component)`
rows.  A canonical component set is the most stable generic identifier; an
integer assigned by traversal order is smaller but not semantically stable.

A value-level primitive taking one aggregated adjacency map is another
possible extension, but it first packs the whole relation into a collection
and returns one large value.  Direct relation access is a better long-term
operator boundary.  Ordinary Slog primitives and demands are row/value
oriented today, so neither route exists as a few-line library definition.

## Running and checking

```console
SLOG_NO_MEM_CAP=1 racket compiler/run.rkt --no-banner --sizes \
  --debug-dir /tmp/slog-scc examples/scc/scc.slog

SLOG_NO_MEM_CAP=1 racket compiler/run.rkt --no-banner --sizes \
  --debug-dir /tmp/slog-tarjan examples/scc/tarjan.slog

diff -u <(sort /tmp/slog-scc/scc.csv) \
        <(sort /tmp/slog-tarjan/scc.csv)
```

`SLOG_NO_MEM_CAP=1` only avoids `systemd-run` in environments without a user
systemd bus; omit it on a normally configured host.
