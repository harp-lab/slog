# M7 recursive lattice/rank repair contract

**Status:** slice 1 implemented and audited (2026-07-24; sub-slices (a)–(d),
exit audit in [incremental-status.md](incremental-status.md); as-built
annotations inline).  `incremental.md` §7A remains normative; this file pins
the state, admission, and repair lifecycle M7 adds on top of the shipped M6L
stratified-deletion foundation ([m6l-contract.md](m6l-contract.md)).

Direction ratified 2026-07-23:

- **Both regressions, one mechanism.** Recursive lattice *value* regression
  and foundedness *rank* regression have the same shape — "find the next
  surviving X from retained state" (§7A.3) — and share one candidate,
  scheduling, and replacement-delta substrate (§7A.4). M7 implements them
  together rather than as two features.
- **Stored-contributor repair.** The retained state is per-key contributors
  (extending M6L's `Contrib`) plus per-tuple rank witnesses. A regression
  finds the next surviving value/rank from retained state with no full
  re-derivation. This reuses shipped machinery (M6L contributor state, the
  M4T DRed^c candidate/reseed path); the cost is sidecar memory, revisited
  only if the §7A.3 workload measurements later justify a localized-re-eval
  variant behind the same seam; the truncated top-k interpolation and the
  retention-class hook it needs are sketched in
  [aggregate-retention.md](aggregate-retention.md) (future, experimental).
- **Interpreter-first, freeze-compliant.** M7's repair rounds execute as VM
  plan flavors, like the shipped counted/maintenance and M4N variants; no
  native leg is added (under `SLOG_FLAVORED_NATIVE=1` the recursive
  lattice/rank routes fall back at admission, mirroring M4N's
  `m4n-native-fallback`). Contributor sinks and rank-witness folds are
  registration/binding/sink additions under the frozen interpreter core
  ([interp-core-contract.md](interp-core-contract.md)); new opcodes, if any,
  land in reserved opcode space, and no frozen state-machine arm changes.

M7 retires the M6L recursive-producer/recursive-consumer fallback *only* for
the monotone, stability-certified forms below. Everything else stays on
clear-and-rerun.

## Semantic state

Two recomputable caches, both version-local, neither serialized as semantic
truth. A load establishes them from the exact historical writers before
precise admission, or falls back — identical to M6L's contributor-cache rule.

1. **Contributor state (recursive extension of M6L `Contrib(L)`).**
   `Contrib(L) = { (key..., payload) }` is retained even when the lattice head
   is *same-SCC* (recursive). Rows keep the ordinary packed
   `input | nonrec | rec` support word; two instantiations emitting one
   contributor collapse without one retraction erasing the other. Losing
   payloads are retained so a regression has the next value to fall to. The
   visible lattice entry is the semilattice join of the currently live
   contributor rows.

2. **Rank witnesses.** For each live tuple in an admitted recursive cone,
   retain the best surviving derivation rank — the recursive minimum over its
   contributors' derivation depths (§7A.3). Foundedness stays a *separate*
   axis from value (§7A.2): the support word decides liveness; the rank
   witness decides which round a recursive re-fire is admissible in.
   *As built (2026-07-24):* first-derivation-round stamps are exact for any
   from-scratch evaluation and kept honest through repair by erasure
   hygiene; maintenance and count incarnations neither stamp nor blanket-
   invalidate (their round numbering restarts).  A repair epoch that
   reseeds or re-derives rows of a relation downgrades that relation's
   witness certification — DRed over-deletes every touched derived-only
   row, and a derivation-grain rank recompute for tables needs the finer
   per-derivation contributor identity §7A.2 deliberately reserves.
   Lattice keys retain contributor-grain stamps the repair can consult.
   Per-derivation rank folds behind the repair seam are the deferred
   precise mechanism, measured before adoption like the retention seam.

Both sidecars preserve the same VersionId, writer, count-epoch, and coverage
invariants as an ordinary hidden relation, exactly as M6L requires of its
contributor sidecar.

Retention class is part of certification: both caches are *complete* in M7.
The repair fixpoint consults them only through the next-surviving-value/rank
seam, so a future truncated retention class
([aggregate-retention.md](aggregate-retention.md)) can slot in without
redesign; no caller may assume contributor completeness as an ambient fact.

## The repair fixpoint

A signed input phase seeds a DRed^c candidate set and over-deletes live
membership after its driving round, reusing the M4T recursive-deletion path
(`set-overlay-negative-dred`, candidate cones). Repair then runs as a bounded
fixpoint of rounds over the candidate cone:

- **Membership** (DRed^c, coarse): a candidate whose support is fully gone is
  retracted; one whose support survives is retained — the M4T/M4N behaviour,
  unchanged.
- **Rank** (finer): recompute each candidate's best surviving rank from its
  live contributors. A candidate whose best rank is *unchanged* is neither
  re-derived nor re-fired — this is the rank analogue of M4N's absent-ever
  sweep exclusion, and it is what keeps recursive over-deletion from
  double-counting a corpse fire across rounds.
  *As built (ratified 2026-07-24):* the sweep's pessimistic value
  retraction, exact contributor counting, and dead-candidate absorption
  already prevent corpse-fire double-counting and break unfounded value
  cycles (the 0-weight-cycle fixtures, certified against fresh recounts) —
  the value-unchanged skip is the operative re-fire exclusion, and the
  rank comparison is an admissible *optimization* of it rather than a
  soundness precondition. Rank witnesses keep their per-tuple obligations
  below; the rank-comparison gate may be added behind the same round seam
  if workload measurements show cascade waste.
- **Value**: for each affected lattice key, recompute the join of live
  contributors. Reseed/relearn consults retained contributors (and, for
  struct-keyed cones, the M5 tombstone dictionary) to restore the value
  without re-running the producing cone.

Monotone ascending changes never enter this fixpoint; they take M6L's
monotone insertion path. Only regressions (value or rank) do.

## Replacement transition

Per affected key, repaired exactly once per epoch, extending M6L's four cases
into the recursive rounds:

- unchanged join: no visible transition;
- absent to present: `DeltaPlus(key, new)`;
- present to absent: `DeltaMinus(key, old)`;
- changed payload: the atomic replacement pair `DeltaMinus(key, old)` then
  `DeltaPlus(key, new)` in one update epoch.

A rank change that does not change membership or value is internal and
publishes nothing. The visible payload map, contributor state, rank witnesses,
replacement journal, and settled revision must agree at commit; any
arithmetic, coverage, writer, rank, or repair failure invalidates the caches
and completes through clear-and-rerun.

## Admission ladder

**Slice 1 — recursive stable lattice/rank repair (both, unified).** Admit a
recursive (same-SCC) cone that is:

- positive and monotone-use-checked (the language's existing in-SCC checks);
- plain-table, or struct-keyed via the M5 tombstone dictionary;
- headed by a *trusted built-in* semilattice (min, max, flat, count-lattice,
  set, map) — or foundedness rank, which is a recursive-min instance of the
  same shape.

Maintain contributors and rank witnesses; repair regressions from stored
state through the fixpoint above.

Slice 1 is implemented through four internal sub-slices — substrate, repair
fixpoint, structs + persistence, hygiene + exit — tracked in
[incremental-status.md](incremental-status.md). They are implementation
order only: this contract remains the single certification target, and
admission stays off until the repair-fixpoint sub-slice lands, so no
sub-slice weakens fallback.

Until a later slice is separately certified, fall back (clear-and-rerun) for:

- a user-defined recursive lattice whose stability is asserted but not a
  trusted built-in or a checkable certificate (§7A.1);
- negation over the changing lattice key that M4N does not already cover
  (the shipped `m6l-negation-fallback` route remains in force);
- SQL-style non-idempotent SUM/COUNT/AVG folds (those are M6A, a separate
  language feature, never an alias for the count semilattice);
- struct/nullary/diagnostic/fallible or unsupported side-channel cones;
- a contributor or rank cache that cannot be exactly re-established at load;
- historical/back-anchored edits.

Direct lattice assertions and contributor inheritance remain refused by the
session overlay, as in M6L.

## Required fixtures

Correctness uses M6L's two oracles plus the cross-flavor check (§10): content
equality with fresh recipe replay, and maintained value/rank equal to a
forced fresh version-local recount.

- **Recursive value regression:** recursive `min`/`max` over a cyclic graph;
  delete the winning contributor on a cycle and confirm the value regresses to
  the next surviving contributor, not to clear-and-rerun.
- **Rank corpse fire:** a diamond/refound (and SCC bridge, symmetric cycle,
  cyclic transitive closure from §10's foundedness list) where a later round's
  re-fire of an over-deleted tuple would double-decrement unless excluded by
  an unchanged best rank — the rank analogue of `m4n_sweep`'s round-3 case.
- **Contributor collapse and loser retention:** two derivations supporting one
  `(key, payload)`; regression falls to a retained losing payload.
- **Struct-keyed recursive lattice:** reuses M5 tombstone identity across
  delete/reseed/relearn with stable ids.
- **Persistence:** save/reopen; load re-establishes the contributor and rank
  caches from the exact historical writers (certifying them) before the first
  regression repairs precisely — plus a companion case where exact
  re-establishment is impossible and the regression confirms the fallback
  route instead.
- **Transaction hygiene:** recount abort/retry, counter overflow fallback,
  healing, and next-epoch replacement-journal hygiene.
- **Named fallback:** uncertified user recursive fold, negated changing key,
  and SQL-style aggregate each hit clear-and-rerun with a distinct route.
- **Warm fuzz:** a maintained recursive-lattice session held across ten epochs
  under one, two, and eight workers, compared every flush against an
  independent fresh recount oracle (the `tests/incremental-stress.sh` shape).

## Concurrency and observability

The DRed^c candidate set, affected-key interning, replacement journal, and
rank-witness updates are shared scheduling state and must be synchronized like
the M1/M3/M6L transition journals. Forced pause/resume is attributed to the
repair round it interrupts and crosses the runtime split-batch boundary.

Runtime reports `(reason lattice-rank-repair)` as a conditional local
capability; storage-class inspection is never sufficient admission. Session
route messages distinguish recursive lattice-value repair, rank repair, and
named fallback, and prove the complete admitted recursive-cone shape — mirror
of M6L's producer/consumer route reporting.
`(lattice-contributor-state ...)` is extended to report rank-witness
certification alongside contributor certification.

Deterministic value, rank, shape, struct, persistence, recovery, and fallback
cases are executable gates; randomized repair runs the warm multi-worker fuzz
against fresh recount oracles. Cold-versus-warm performance and sidecar-memory
reporting (contributor plus rank witnesses) are separate gates per §7A's
"performance only after correctness" rule.
