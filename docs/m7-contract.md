# M7 recursive lattice/rank repair contract

**Status:** draft (2026-07-23). `incremental.md` §7A remains normative; this
file pins the state, admission, and repair lifecycle M7 adds on top of the
shipped M6L stratified-deletion foundation ([m6l-contract.md](m6l-contract.md)).

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
  variant behind the same seam.

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

Both sidecars preserve the same VersionId, writer, count-epoch, and coverage
invariants as an ordinary hidden relation, exactly as M6L requires of its
contributor sidecar.

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

Until a later slice is separately certified, fall back (clear-and-rerun) for:

- a user-defined recursive lattice whose stability is asserted but not a
  trusted built-in or a checkable certificate (§7A.1);
- negation over the changing lattice key that M4N does not already cover;
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
- **Persistence:** save/reopen from an uncertified contributor+rank cache,
  then exact repair on the first regression.
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
