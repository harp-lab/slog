# Weaving, namespaces, and instantiation: the generalizations behind `$stat_*`

2026-07-11.  **Exploration, not spec.**  This doc captures the design
space that the runtime-stats work (docs/stats.md) opened up: `$stat_*`
turns out to be a single filled-in cell of a much larger grid, and this
records the axes, the one soundness law that governs all of them, what
is detectable/automatic vs. what must be intentional, and how a user
could eventually reach these features.  Nothing here is committed.

## 0. Why stats forced the question

Stats relations are computed *at every stratum boundary* and read by *no
rule*.  They are therefore outside the stratification DAG entirely --
not a node in it, but a monitor sampling it.  That raised the general
question: what *is* the class of "computations woven across the strata,"
when is it sound, when is it a merge-forcing accident, and is it a
feature a user could wield?

## 1. Four axes; stats is where they meet

The features being circled factor into orthogonal-but-composing axes:

1. **Namespaces** -- scoping for names.  `stats.sizes`, not `$stat_size`.
2. **Weave points / lifecycle scopes** -- the structural events a
   subprogram attaches to.  These are *nested temporal scopes the engine
   already runs*: `session ⊃ round ⊃ stratum ⊃ iteration`.
3. **Version addressing** -- naming a relation at a point in evaluation
   time: `last.R`/`next.R`, `R`/`R'`, old/new.  The runtime already
   materializes these (`delta_R`, and `R_old = full − delta` from the
   exact-seminaive work).
4. **Parametric instantiation (functors)** -- instantiate a namespaced
   subprogram N times over different data, wire the copies with glue.

`$stat_*` = a built-in **monitor** (axis 2, stratum+iteration scope)
that reads **per-iteration versions** (axis 3) and writes into a
reserved **namespace** (axis 1, hand-rolled as a `$` prefix because
axis 1 doesn't exist yet).  "The same program twice with machinery
between" is axis 4.  Stats is the first cell filled in.

## 2. The one law

> A woven or instanced subprogram is **stratification-safe iff it reads
> only state already committed at its weave point (snapshots, prior
> versions) and writes to names nothing in the main DAG reads back.
> Writing into the DAG's *future* forces a merge -- or, under negation,
> is a stratification error.**

Everything below is a consequence of this law.

### 2.1 Detection (answers "can this be found automatically?")

A relation that "fires in every stratum and forces a merge" is exactly
one sitting on cycles that span otherwise-independent SCCs.  **The
stratifier already computes this** -- it is *why* those strata merge.
What is missing is *classification*:

- **sink-shaped** cross-stratum relation (contributions in from many
  strata, no read-back) -- provably safe to peel out as a boundary
  **monitor**, leaving the strata separate.  Automatable.
- **non-sink** (genuine feedback into the DAG) -- the merge is real;
  peeling would change results.  Must stay merged; the right output is a
  *diagnostic*: "strata 3–7 merged because relation `G` is read back at
  foo.slog:42 -- this is a real cycle, not a monitor."

This is a lever on the **large-SCC compile-cost problem**
(build-issues-notes): if part of what fused a giant stratum is
sink-shaped (a global accumulator, an assert/log relation, a running
count), peeling it into a monitor shrinks the SCC that must go through
the 32-arity BTree-ladder codegen.  The diagnostic pays for itself even
before any peeling is automated.

### 2.2 Intentional vs. automatic

The **sink** case can be fully automatic -- it is semantics-preserving.
The **non-sink** case must be intentional, because it changes results.
So the feature has an automatic tier (peel provable monitors) and a
declared tier (the user *asks* for a scan/functor and accepts the law).

## 3. The two woven shapes

"A subprogram compiled into every stratum that feeds one into the next"
splits in two, distinguished precisely by the law:

- **Monitor (sink, no feed-forward):** reads the boundary snapshot,
  writes to a namespace nothing reads back.  Order-independent,
  mergeless, safe.  *Stats is this.*
- **Scan (feed-forward accumulator):** reads the snapshot at boundary
  *i*, produces state consumed at boundary *i+1* by the *same* woven
  subprogram -- a fold threaded *through* the scope sequence, orthogonal
  to the data DAG.  Sound as long as the accumulator is read only by the
  scan, not the DAG.

The runtime already runs one instance of each internally: a monitor
(stats, at stratum scope) and a scan (the seed-accelerator's per-round
quota reservoir, at round scope -- db-compression §4.4).

## 4. Namespaces make the sigils principled

Modules today are textual-include (`modules.rkt resolve-include`); every
relation lives in one flat namespace.  That is *why* `$stat_`, `$seq_`,
`$sup` exist -- hand-rolled namespaces enforced by string prefix.  Real
**reserved namespaces** (`stats.`, `seq.`, `sup.`) principle-ize them:

- `stats.sizes` cannot collide with a user `sizes`.  A user relation
  `rel_sizes` and a machinery `stats.rel_sizes` coexist trivially.
- Namespaces carry **policy**: `stats.*` = ephemeral + golden-excluded
  (the `$stat_`-prefix exclusion in `writeDatabaseBIN` becomes a
  namespace property, not a string test); `seq.*`/`sup.*` =
  persistent-but-internal.
- **Introspection caveat:** namespacing solves *naming*, not the read
  law.  A rule reading `stats.sizes` still depends on all strata
  finishing -- a stratification hazard.  So `stats` stays a
  read-out-of-band namespace (CSV / api `lookup`); an in-language
  read-only-after-final-stratum *view* is a separate feature.

## 5. Functors, double-instantiation, last/next

Aspects and functors are **duals**: a monitor weaves *one* subprogram at
*many* points over *one* data instance; a functor instantiates *many*
copies over *different* data instances.  "The same program twice under
two namespaces with machinery between" is the functor; the
`last.R`/`next.R` coupling is a *scan over two functored instances run
together*.

Less speculative than it sounds, because the substrate exists:

- **`last`/`next` already live in the runtime.** `delta_R` and
  `R_old = full − delta` are materialized for self-joins.  So exposing
  iteration-relative versions (`R` / `R'`) is *surfacing* existing
  state, not inventing it -- gated behind the law (handing user rules a
  prior version is the negation problem again).
- **Incrementality is already "the same program twice with machinery
  between."** DRed^c maintains the old derivation and the new and diffs
  them.  With namespaced functors, `old = P(DB₀); new = P(DB₁);
  Δ = diff(old,new)` expresses the incremental engine as user-level
  glue, the engine being the machinery in between.
- **Parametric analyses already instantiate by fact.** `kcfa` / `mcfa` /
  `schemecfa` pick precision via facts (`mlimit`).  A functor would let
  you instantiate the *same* analysis module at two precisions under two
  namespaces and assert containment -- one program, two instances, a
  glue rule between.

## 6. The unifying picture: scopes × namespaces × versions

Every special thing the engine does is a weave over a nested temporal
scope:

| scope | sequence | current weaver |
|---|---|---|
| iteration | semi-naive rounds | (delta bookkeeping) |
| stratum | SCC pipeline order | **stats monitor** |
| round | seed-accelerator / compression | **quota-reservoir scan** |
| session | incremental edits | **DRed^c old/new** |

A principled design is the full grid: at any scope, either the system
*or the user* attaches a subprogram (monitor or scan), addressing
relations by `(namespace, version)`.  Stats fills `(stratum, monitor)`.
The open design work is making the other cells addressable with one
mechanism instead of four bespoke ones.

## 7. What a user would do with it

Drop-in reusable modules that ride any program under a namespace:

- `assert.` -- monitor: `count(bad) == 0` after each stratum, else emit
  an error fact (cf. the SMT-verify demos).
- `trace.` / `prof.` -- monitor: per-rule provenance / hot-rule
  profiling (a user-space `stats.work`).
- differential -- functor: run an analysis at two precisions, diff.
- outer-fixpoint -- scan: the seed-accelerator / compression round loops
  made user-expressible.

## 8. Open questions

- **Surface syntax.**  How does a user *declare* a weave?  A module-level
  annotation (`@monitor(stratum)`), a reserved namespace with implied
  scope, or an explicit `(weave scope module ...)` form?
- **Version syntax.**  `R'` vs `last.R` vs `R@k`; which versions are
  legal to read where (only committed-past, per the law).
- **Functor binding.**  How are a module's free relations bound at
  instantiation, and how is glue between two instances written without
  reintroducing a merge?
- **Automatic sink-peeling.**  Worth doing for the large-SCC win, or is
  the diagnostic (report the merge cause) enough for now?
- **Cost of exposing internals.**  `R_old` is materialized only for
  ≥2-dynamic-clause rules today; making `R'` generally readable may
  force it more widely.
- **Relation to lattices/demand.**  Monotone-use calculus (lattices.md)
  and demand already have their own cross-stratum reasoning; a weave
  mechanism must not fight them.
