# M4N contract: precise stratified negation

Drafted 2026-07-19, at the head of thread 0's spine (roadmap §4.1),
immediately after the counted-interpreter milestone closed.  M4N makes
negative edges precise: today every update crossing a `~` edge
clear-and-reruns its cone (incremental.md §0.8), even when the rest of
the cone rides M1/M3/M4T/M4S routes.  The milestone emits and maintains
the negated-body-driven variants of §0.8 — as interpreter variants
exclusively, riding the seam the counted-interpreter milestone built —
and lifts the route layer's blanket "any neg edge into the cone is
non-monotone" refusal for the admitted shapes.  Authorities:
incremental.md §0.8/§4.5–§4.7/§10, counted-interp-contract.md (the
executor seam and per-flavor sidecar-equality definitions),
docs/incremental-status.md §0.A (shipped forward-only negation and the
polarity manifests), roadmap §4.1.

## What precision means

For `H(x) :- A(x), ~B(x)` (incremental.md §0.8):

- a presence transition **+B(x)** must enumerate matching surviving
  `A(x)` rows and emit **−H(x)**;
- a presence transition **−B(x)** must, after B is final, enumerate
  matching `A(x)` rows and emit **+H(x)**.

Precision is the same standard every M milestone carries: maintained
content and kind-decomposed support words equal a forced fresh recount
after every flush, and the instantiation multiset behind them is exact —
each gained or lost instantiation contributes exactly once, under the
same occurrence-partition discipline M1/M3 pinned for positive premises,
now extended across polarity.

## Ground truth (what already exists)

- **Forward-only negation is shipped and hardened** (0.A): `~` is range
  restricted, rejected through recursion (a negated premise is always a
  strictly lower, settled stratum), compiles to absence probes
  (`absent`/`absent-lat`, K=0 included), and carries per-edge polarity
  in the stratum manifests (`read-stratum-meta`'s reads entries) that
  the route layer already consults.
- **The executor seam is complete.** Flavored variants are interp-only
  by default; maintenance plans seal, bind, and execute through the VM
  with signed sinks into the unchanged `Maintain*Task` folds; the union
  pre-state view is the frozen `new`-view equation; per-sign staged
  transitions (`stage-update-transitions signed ±1`, premise-kind rows)
  drive maintenance epochs.  M4N's variants are new PLANS and thread-0
  registrations, not new machinery.
- **Counting through negation is already exact at rest**: `_count`
  plans carry `absent` probes over settled strata (the `neg_reach`
  battery case and its count-IR-oracle leg) — M4N is a
  maintenance-flavor milestone only.
- **The route layer refuses precisely** (`session.rkt`): a cone is
  non-monotone iff any edge INTO it is neg/lat; M4N narrows this to
  lattice edges (M6L/M7 own those) plus the exclusions pinned below.

## Doctrine

1. **The finality barrier is stratification itself.**  Because `~` is
   rejected through recursion, the negated relation's stratum completes
   its whole per-stratum schedule (negative fixpoint → reseed →
   positive fixpoint, §4.7) before any reading stratum's epoch begins.
   M4N adds NO new cross-stratum scheduling; "pre/post transition
   scheduling" is entirely the staging protocol of pin 3.

2. **Anti-delta variants, per negated occurrence, per flavor, with
   inverted polarity.**  For each negated occurrence `~B` in a rule,
   the maintenance planners emit:
   - in the NEGATIVE flavors: a version driven by B's settled
     **positive** transitions (ΔB⁺ = losses of `~B`), emitting sign −1;
   - in the POSITIVE flavor: a version driven by B's settled
     **negative** transitions (ΔB⁻ = gains of `~B`), emitting sign +1.
   The existing positive-premise-driven versions gain explicit
   pre/post-state absence probes over their negated occurrences.  All
   variants keep the rule's own nonrec/rec fold kind (`~B` is never
   in-SCC, so negation never flips a rule's classification).

3. **The staging protocol (this is the milestone's crux).**  A reader's
   epoch must see BOTH signs of a negated premise's settled transitions,
   in different roles:
   - the anti-delta sign **drives** (ordinary premise-kind staged rows
     scanned by the anti-delta version's delta driver);
   - the opposite sign stages as a **view-only** contribution so
     absence-at-pre is expressible: pre(B) membership is
     `(x ∈ post(B) ∧ x ∉ ΔB⁺) ∨ x ∈ ΔB⁻`, and its negation needs ΔB⁻
     visible even though those rows are already gone from B's live
     indices.  The union half is again the frozen `new`-view equation;
     the subtraction half (`∉ ΔB⁺`) is the exclusion discipline
     `join-old` already implements on the positive side.
   The session's flush pipeline gains the polarity flip at negative
   edges: which sign stages into which phase of which stratum is a pure
   function of the polarity manifests, and mis-staging must be a typed
   refusal, not a silent wrong answer.  Whether view-only rows ride the
   existing premise-kind vehicle or a distinct staged kind is slice-1's
   choice; the pin is the two roles and the per-sign discipline.

4. **Pre/post absence views are explicit plan ops.**  By direct analogy
   with `join-old`/`join-new`: the ABI-1 grammar gains pre/post-state
   absence forms (working spellings `absent-old`/`absent-new`, carrying
   the delta ordering exactly as the join views do), emitted by the
   maintenance planners and serialized by canonical-plan.  They execute
   as thread-0 cursor registrations composing the frozen absence probe
   with the staged transition views — no new opcode, no VM arm, no
   cursor-interface change (the counted-interpreter precedent: every
   view so far has been a cursor-factory composition).  The count
   flavor keeps plain `absent` (settled state, both views coincide).

5. **The exact partition extends across polarity.**  Retractions of
   `(A(x), ¬B(x))` partition exactly: lost-A-driven versions evaluate
   `~B` at PRE state; gained-B-driven (anti-delta) versions evaluate
   `A` at the surviving/post state — the same dual-ownership convention
   M1/M3 pinned (rightmost-new / leftmost-deleted), extended so that no
   gained/lost instantiation is counted twice between a premise-driven
   and an anti-delta version.  Repeated negated occurrences and
   mixed-polarity self-overlaps (`H(x) :- A(x), ~A'(x)` shapes over one
   relation's different versions) get the same `#ordinal` occurrence
   treatment as positive repeats.

6. **Interpreter variants exclusively; the differential is the oracle
   triangle.**  Native flavored emit-cpp is frozen legacy and is NOT
   extended for M4N (roadmap P4, discharged at the counted-interpreter
   flip).  Consequently the anti-delta variants have no native second
   executor: their differential legs are (a) content equality with
   from-scratch replay, (b) the count-IR oracle extended over the
   negated-variant IR, and (c) maintained-equals-forced recount — the
   §10 strategy — plus the existing native leg for everything the
   pre-M4N flavors still cover under `SLOG_FLAVORED_NATIVE`.

## Route admission and exclusions

Admission extends `m3-eligible?`/`m4t-eligible?`-class certification
with polarity awareness: a neg edge into the cone is admissible when the
negated relation is table-kind, its stratum is inside (or below) the
certified cone, and the reader's shape is otherwise admitted.  Pinned
exclusions (each a tested named fallback, in the M4S style):

- **negation × struct cones** stays on clear-and-rerun (the
  `m4s-negstruct` fixture keeps its `(route rerun ...)` assertion) until
  a dedicated follow-up slice proves the tombstone interplay;
- **negation × lattices** stays with M6L's refusals (M7 owns recursive
  lattice repair);
- negation of demand-grown, intern-only, oracle, and value-side-table
  relations remains rejected by the shipped type checks (§0.8).

## Slices

1. **Acyclic readers (the §0.8 canon).**  Planner emission of
   anti-delta versions + pre/post absence ops for rules read by acyclic
   strata; ABI-1 grammar + canonical-plan serialization; seal/bind/
   cursor registrations (thread-0); the session staging polarity flip
   and admission for acyclic negation-bearing table cones.  Fixtures:
   the `H :- A, ~B` canon under +B/−B/mixed flushes, repeated negated
   occurrences, a two-negation rule, negation under temps (staged
   chains), healed-equals-forced plus the count-IR oracle on every
   case, and typed refusals for mis-staged polarity.
2. **Recursive readers.**  Negative edges into M4T-class recursive
   strata: anti-delta drives interleave with the DRed sweep's exact
   partitions (candidates, reseed, relearn); foundation semantics
   unchanged (`~B` support is nonrec by construction).  Gate: the M4T
   battery shapes re-cut with a negated premise, id-stability included
   where struct interiors appear below the negation.
3. **Admission completion + intersections.**  Inheritance and masks
   across negative edges (inject-reopen fixtures), negation × demand
   shapes, the intersection-matrix ledger rows for negation × {temps,
   recursion, inheritance, structs(excluded), lattices(excluded)}
   each tested-by-name or consciously excluded; route-refusal batteries
   for every exclusion.
4. **Exit audit** in the established style: the deterministic matrix
   plus the signed-stream fuzz harnesses extended to generate negative
   edges (m3/m4t-class programs with `~`), ten-flush warm sessions vs
   fresh recompute and forced recounts under 1/2/8 workers, forced
   pause/resume attributed to the anti-delta phases at the
   1-millisecond budget, and the oracle triangle on every epoch.  The
   audit note lands in incremental-status.md with battery counts.

## Non-goals

- No change to forward-only semantics, polarity typechecks, or the
  rejected-through-recursion rule.
- No counting-semantics change: kinds, words, and the two-class
  side-channel doctrine are untouched; `_count` plans keep plain
  `absent`.
- No struct-cone or lattice negation admission (pinned exclusions
  above).
- No native flavored codegen, ever (P4).

## Exit audit

The milestone exits when, in one review: (a) negation-bearing acyclic
and recursive table cones ride precise routes by default with the full
incremental battery green; (b) every admitted fixture holds
maintained-equals-forced sidecar equality and count-IR-oracle agreement,
and the fuzz legs hold under all three worker seeds with pause
injection; (c) every exclusion routes to its named fallback under a
test; and (d) the staging-polarity and absence-view plan attributes are
each covered by a typed-refusal or fidelity case.  The audit note lands
in incremental-status.md, and M7 opens on its completion.
