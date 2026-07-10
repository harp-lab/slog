# 8. Lattices

Chapter 3 left a wart: computing path costs derived *every* cost of
*every* path — and on a cyclic graph, that never ends. What we wanted
was one number per node: the **best** cost so far, only ever improving.
Lattices are Slog's way of saying exactly that.

## Shortest paths, properly

```
lattice (cost (min int #:floor 0))
table (edge int int int)
table (dist int cost)          ;; a MAP: node ⟼ least cost

rule
(edge 1 2 4)
(edge 1 3 1)
(edge 3 2 2)
(edge 2 4 5)
(edge 4 1 1)

rule (dist 1 0)
rule (dist X C) (edge X Y W) --> (dist Y (+ C W))
```

`lattice` declares a value **type** equipped with a merge rule — here,
integers merged by `min`. Giving `dist`'s last column that type changes
the relation's meaning: it becomes a *map* from node to a single merged
value. Deriving `(dist Y 9)` doesn't insert a row; it **contributes**
9, and the stored value keeps whichever is smaller. Watch what that
does — this graph even has a cycle (4 loops back to 1):

```
$ racket slog.rkt --debug-dir out/sssp sssp.slog
$ sort -n out/sssp/dist.csv
1   0
2   3
3   1
4   8
```

One row per node, each the true shortest distance, and the cycle
converged by itself — a trip around the loop is never an improvement,
so it contributes nothing new. Compare chapter 3's output (multiple
rows per node) and the difference is stark: same rule, but the
declaration told Slog *what kind of thing* the value is, and the engine
kept only the best.

`#:floor 0` clamps values below at zero, which is what makes
termination a guarantee rather than your problem (with negative-weight
cycles, costs could otherwise "improve" forever; omit the floor and the
compiler warns you that termination is on you).

## The soundness rule, in plain terms

While `dist` is still being computed, its values are provisional —
today's 9 may be beaten by tomorrow's 3. So inside the rules that are
still improving `dist`, Slog only lets you use a cost in ways that
*stay valid as the value improves*: contribute it onward through
arithmetic that preserves order (`(+ C W)` above), bound it from above
(`(< C 12)` — once true, improving C keeps it true), or ignore it.
Anything that could be *invalidated* by a later improvement — storing a
snapshot in an ordinary relation, using it as a lookup key, testing
`(> C 5)` — is a compile error **in those rules**, and perfectly legal
in later rules that merely read the finished result. You don't manage
this boundary; the compiler infers which rules feed which and enforces
it. The classic dataflow-analysis bug ("I concluded something from a
value that then changed") is a type error here.

## Two more lattices

**`(flat T)`** turns any type into the three-level "nothing yet / this
exact value / conflicting values" ladder — the shape of constant
propagation. Distinct contributions collapse to `(top)`:

```
union (value (vnum int) (vstr str))
lattice (fv (flat value))
table (assign int int value)   ;; label, register, constant
table (flow int int)
table (regval int int fv)      ;; MAP: (label, register) ⟼ known value

rule (assign L R K) --> (regval L R K)
rule (flow L L2) (regval L R V) --> (regval L2 R V)
```

Set register 11 to `(vnum 1)` on one branch and `(vstr "two")` on the
other, and after the join it reads `(top)` — "more than one value
reaches here". Registers set consistently keep their constant. This
works over *any* value type, including your own trees.

**`(count)`** is the little ladder 0 < 1 < ∞ ("none / exactly one /
many"), the workhorse of analyses that need to know whether something
is unique. Contribute `(one)` per observation; evidence of a second
distinct observation contributes `(inf)`.

After a lattice relation is finished, later rules can extract freely:

```
rule (regval L R V) (= V (top)) --> (conflict L R)
```

## Cheat sheet

| Form | Example | Meaning |
|---|---|---|
| declare | `lattice (cost (min int #:floor 0))` | a value type with a merge; floor/ceiling clamp and guarantee termination |
| merges available | `(min int)` `(max int)` `(min float)` `(max float)` `(count)` `(flat T)` | numeric best; 0/1/∞; equal-or-conflict |
| map relation | `table (dist int cost)` | lattice-typed last column ⇒ one merged row per key |
| contribute | `--> (dist Y (+ C W))` | heads merge instead of insert |
| read current | `(dist X C)` in a body | binds the best-so-far value |
| allowed while improving | monotone math (`(+ C W)`, `(min C x)`), upper bounds (`(< C k)`), `(= V (top))`, `(= V (inf))` | uses that survive improvement |
| rejected while improving | plain-column copies, keys, `(> C k)`, `(= V (one))` | anything a later improvement could invalidate |
| afterwards | anything | later rules read final values freely |
| count constants | `(one)` `(inf)`, combine with `(cplus a b)` | the 0/1/∞ ladder |
