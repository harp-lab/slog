# Dominators, the dominator tree, and natural loops

The control-flow trio at the heart of every optimizing compiler —
dominators, immediate dominators, back edges, natural loops, nesting
depth — as one forward fixpoint over canonical sets, in ~15 rules.
It is the mirror image of `examples/regex`: that one is all `demand`
(backward, on-request, memoized); this one is all convergence
(ascending lattice columns, read only once closed).

| the textbook algorithm | in Slog |
|---|---|
| intersect predecessors' dom-sets until no change | grow the *complement*: union-lattice sets of non-domination witnesses |
| "every path passes through d" (a ∀, needs negation) | absence from a closed canonical set — `cmem` totally answers 0 |
| "don't read the sets until they've converged" (a comment) | a stratum boundary the compiler infers — and reading early is a *lattice-soundness error*, not a wrong answer |
| idom = argmin over the dominator chain | one join: the unique `d` with `domset(d) = domset(n) \ {n}`, an O(1) comparison of interned sets |

## Running

```
racket compiler/run.rkt --no-banner --debug-dir out/domtree examples/domtree/domtree.slog
```

The input CFG is a doubly nested loop whose inner body is an if/else
diamond. Things to look at:

- `domset.csv` — one canonical set per block. However many witness
  singletons were unioned in, equal contents is one interned value.
- `idom.csv` — the dominator tree. Note `"join" → "body"`: neither
  branch of the diamond dominates the join point, the branch node does.
- `backedge.csv` — found from dominance alone (`edge a h` where `h`
  dominates `a`): `join→inner` and `latch→outer`.
- `loop.csv`, `depth.csv` — natural loop membership and nesting depth;
  depth reads 0/1/2 exactly like the source indentation.

The "reading early is an error" row of the table is real: move the
`cmem` test into the same SCC that is still growing the set and the
compiler stops with

```
lattice-check: primitive (cmem s a) is not a whitelisted monotone
transfer for a still-ascending (set ...) value
```

— the classic dataflow bug ("concluded something from a value that
then changed") is unwritable.

## Where it could go

This is the entry ticket to a compiler middle-end: add `def`/`use`
facts per block and loop-invariant code motion, SSA φ-placement (via
dominance frontiers, one more rule pattern over `domset`), and
irreducibility detection (a loop entered around its header) are each a
handful of rules on top of these tables.

The example is a golden test: `tests/run-tests.sh examples/domtree/domtree.slog`.
