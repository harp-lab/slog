# M7 rank witnesses (built 2026-07-23, removed 2026-09-10)

> **FROZEN HISTORICAL RECORD (2026-09-10).**  This file preserves the design
> and as-built notes of the M7 rank-witness sidecar so the live contract
> ([../m7-contract.md](../m7-contract.md)) can describe only what runs.
> Nothing here is maintained.

## What it was

Per-tuple *first-derivation-round* stamps for every relation its stratum
both writes and reads (the same-SCC members), kept in a per-relation
`btree_map` sidecar bucketed like the count sidecars, stamped first-seen-wins
on the sentinel thread in `EndIterCompletion` after each iteration's delta was
finalized and interned.  Certification: `(rank-witness-state (rnk NAME ORD
1|2) ...)` — 1 = stamped from an empty relation (exact), 2 = invalidated by a
warm re-entry or a bypassing point mutation; the `(dump-ranks REL)` verb
listed `(rankrow REL key.. ROUND)`.  Dying rows' stamps were erased at the
three genuine-deletion sites (count, maintain, lattice-maintain tasks) and at
the reseed discard.

## Why it was built

M7's direction (ratified 2026-07-23) treated foundedness-rank regression and
recursive lattice-value regression as one shape — "find the next surviving
X" — and planned a *rank-unchanged exclusion* in the repair fixpoint: a
candidate whose best surviving rank is unchanged is neither re-derived nor
re-fired, the rank analogue of M4N's absent-ever sweep exclusion.  The stamps
were sub-slice (a)'s substrate for that exclusion.  Under fair semi-naive
evaluation the round of first derivation *is* the recursive minimum over
derivations of (1 + max body rank), deterministic across worker counts and
stable across pause slices, so recording it at the barrier was the cheapest
exact source.

## Why it was removed

1. **The consumer was never built, deliberately.**  Sub-slice (b)
   (2026-07-24) found that pessimistic value retraction, exact contributor
   counting, and dead-candidate absorption already prevent corpse-fire
   double-counting and break unfounded 0-weight cycles (certified against
   fresh recounts).  The contract ratified the *value-unchanged skip* as the
   operative re-fire exclusion and demoted the rank comparison to "an
   admissible optimization behind the round seam, if workload measurements
   show cascade waste".  From then on nothing read a stamp's value: the
   count/maintain tasks only erased dying rows' stamps, the capability report
   consulted validity (to label the reason `lattice-rank-repair`), and the
   only value reader was the debug dump.
2. **The stamps could not have served maintenance past one epoch.**  A
   maintenance epoch restarts round numbering and DRed over-deletes every
   touched derived-only row, so the sidecar went honestly invalid (state 2)
   at the first warm re-entry — exactly what the fixtures asserted.  Exact
   ranks through a sweep need the per-derivation rank folds §7A.2 reserves,
   which were never scheduled.
3. **It was the largest serial cost in every recursive fixpoint.**  Phase
   timers (stats.md §1.5) showed the barrier stamping — one `btree_map`
   probe+insert per new tuple of every recursive relation, on one thread —
   at 25 % of transitive-closure fixpoints on one thread and up to 75 % at
   six, for one-shot evaluations that could never be asked to repair.
   Removing it: a 7.9M-tuple closure 16.6 → 12.3 s at one thread, 7.1 →
   2.7 s at six; a 2001-iteration chain closure 4.1 → 1.1 s at six threads.

## What replaced it

A one-bit structural mark: `Relation::recursive_cone_member`, set at stratum
entry for relations the executing stratum both writes and reads (skipping
transient count/recount incarnations, as the old marking did).  Selective
lattices among them report `(reason lattice-recursive-repair)` — the same
conditional capability the rank sidecar's *existence* used to signal under
the name `lattice-rank-repair`; `compiler/session.rkt` maps both spellings'
successor to the `'lattice` route class.  The fixtures `m7_rec_min` and
`m7_rank_diamond` keep their routes and content assertions; their
`rank-witness-state` / `dump-ranks` steps and `(rnk ...)` / `(rankrow ...)`
assertions were dropped with the verbs.

## If the rank-comparison gate is ever built

- It needs the per-derivation rank folds first, or it is valid for one
  repair epoch per session only.
- Record rounds inside `InternTask`, where the new row is already in hand
  on a warm cache line and the work is bucket-parallel; for plain relations
  intern's bucket (master ordering = identity, lead column 0) coincides with
  a storage-column-0 sidecar, so no locking is needed; struct relations
  intern by their first content column and would need the sidecar keyed
  the same way.
- Never on the sentinel thread at the barrier: serial O(new tuples) per
  iteration is the scaling ceiling of the whole fixpoint.
