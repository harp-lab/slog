# M7 recursive lattice repair contract

**Status:** slice 1 implemented and audited (2026-07-24; sub-slices (a)–(d),
exit audit in [incremental-status.md](incremental-status.md); as-built
annotations inline).  `incremental.md` §7A remains normative; this file pins
the state, admission, and repair lifecycle M7 adds on top of the shipped M6L
stratified-deletion foundation ([m6l-contract.md](m6l-contract.md)).

**2026-09-10:** the per-tuple *rank-witness* sidecar that sub-slice (a) built
as substrate for a rank-comparison re-fire exclusion was removed.  The
exclusion was never built — the value-unchanged skip proved sufficient and
was ratified as the operative mechanism on 2026-07-24 — and the stamping was
the largest serial cost in every recursive fixpoint.  The design, the
as-built notes, and the conditions under which a rank gate could return are
frozen in [history/m7-rank-witnesses.md](history/m7-rank-witnesses.md).
This file now describes only what runs.

Direction ratified 2026-07-23:

- **One mechanism.** Recursive lattice *value* regression and foundedness
  regression have the same shape — "find the next surviving X from retained
  state" (§7A.3) — and share one candidate, scheduling, and
  replacement-delta substrate (§7A.4).  As built, membership foundedness is
  carried by DRed^c support counts and the value-unchanged skip; no separate
  rank state exists (see the 2026-09-10 status note).
- **Stored-contributor repair.** The retained state is per-key contributors
  (extending M6L's `Contrib`). A regression finds the next surviving value
  from retained state with no full re-derivation. This reuses shipped machinery (M6L contributor state, the
  M4T DRed^c candidate/reseed path); the cost is sidecar memory, revisited
  only if the §7A.3 workload measurements later justify a localized-re-eval
  variant behind the same seam; the truncated top-k interpolation and the
  retention-class hook it needs are sketched in
  [aggregate-retention.md](aggregate-retention.md) (future, experimental).
- **Interpreter-first, freeze-compliant.** M7's repair rounds execute as VM
  plan flavors, like the shipped counted/maintenance and M4N variants; no
  native leg is added (under `SLOG_FLAVORED_NATIVE=1` the recursive
  lattice routes fall back at admission, mirroring M4N's
  `m4n-native-fallback`). Contributor sinks are registration/binding/sink
  additions under the frozen interpreter core
  ([interp-core-contract.md](interp-core-contract.md)); new opcodes, if any,
  land in reserved opcode space, and no frozen state-machine arm changes.

M7 retires the M6L recursive-producer/recursive-consumer fallback *only* for
the monotone, stability-certified forms below. Everything else stays on
clear-and-rerun.

## Semantic state

One recomputable cache, version-local, never serialized as semantic truth. A
load establishes it from the exact historical writers before precise
admission, or falls back — identical to M6L's contributor-cache rule.

**Contributor state (recursive extension of M6L `Contrib(L)`).**
   `Contrib(L) = { (key..., payload) }` is retained even when the lattice head
   is *same-SCC* (recursive). Rows keep the ordinary packed
   `input | nonrec | rec` support word; two instantiations emitting one
   contributor collapse without one retraction erasing the other. Losing
   payloads are retained so a regression has the next value to fall to. The
   visible lattice entry is the semilattice join of the currently live
   contributor rows.  Foundedness stays a *separate* axis from value
   (§7A.2): the support word decides liveness.

The sidecar preserves the same VersionId, writer, count-epoch, and coverage
invariants as an ordinary hidden relation, exactly as M6L requires of its
contributor sidecar.

Retention class is part of certification: the cache is *complete* in M7.
The repair fixpoint consults it only through the next-surviving-value
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
- **Re-fire exclusion** (ratified 2026-07-24): the sweep's pessimistic
  value retraction, exact contributor counting, and dead-candidate
  absorption prevent corpse-fire double-counting and break unfounded value
  cycles (the 0-weight-cycle fixtures, certified against fresh recounts).
  The *value-unchanged skip* is the operative exclusion.  A finer
  rank-unchanged exclusion (skip a candidate whose best surviving derivation
  rank is unchanged) remains an admissible optimization behind the same
  round seam if workload measurements ever show cascade waste; it would need
  per-derivation rank folds to stay exact across repair epochs, and its
  history is in [history/m7-rank-witnesses.md](history/m7-rank-witnesses.md).
- **Value**: for each affected lattice key, recompute the join of live
  contributors. Reseed/relearn consults retained contributors (and, for
  struct-keyed cones, the M5 tombstone dictionary) to restore the value
  without re-running the producing cone.

Monotone ascending changes never enter this fixpoint; they take M6L's
monotone insertion path. Only regressions do.

## Replacement transition

Per affected key, repaired exactly once per epoch, extending M6L's four cases
into the recursive rounds:

- unchanged join: no visible transition;
- absent to present: `DeltaPlus(key, new)`;
- present to absent: `DeltaMinus(key, old)`;
- changed payload: the atomic replacement pair `DeltaMinus(key, old)` then
  `DeltaPlus(key, new)` in one update epoch.

The visible payload map, contributor state, replacement journal, and settled
revision must agree at commit; any arithmetic, coverage, writer, or repair
failure invalidates the cache and completes through clear-and-rerun.

## Admission ladder

**Slice 1 — recursive stable lattice repair.** Admit a recursive (same-SCC)
cone that is:

- positive and monotone-use-checked (the language's existing in-SCC checks);
- plain-table, or struct-keyed via the M5 tombstone dictionary;
- headed by a *trusted built-in* semilattice (min, max, flat, count-lattice,
  set, map).
  *As built (2026-07-24, vetting):* SELECTIVE joins only — min, max, and
  count (whose join is max).  Selectivity is what grounds the repair:
  value preservation pins the surviving (key, payload) row, so row-level
  candidacy carries foundedness.  A non-selective join (set/map unions;
  flat's ⊤ conflict state) can preserve the value across *distinct* rows,
  letting an unfounded cycle hide behind the value-unchanged skip — the
  set-lattice vetting probe demonstrated exactly this.  Non-selective
  heads report `(reason lattice-nonselective-recount)`, keep M6L's acyclic
  routes, and stay on clear-and-rerun recursively until the finer
  per-element contributor identity §7A.2 reserves is built.
  The refusal is CONE-WIDE, not per-head: a cone is repaired as one
  fixpoint, so the hazard belongs to the cone rather than to the head that
  carries it, and one non-selective head drags an otherwise admissible
  selective SCC back to rerun with it.  That is a real precision loss, so
  `lattice-retention-shape?` pins it against a fixture (`m7-mixed-*`) —
  narrowing the gate to the offending head, once §7A.2 makes it sound, is
  a deliberate decision against a failing assertion rather than a drift.

Maintain contributors; repair regressions from stored state through the
fixpoint above.

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
- a contributor cache that cannot be exactly re-established at load;
- historical/back-anchored edits.

Direct lattice assertions and contributor inheritance remain refused by the
session overlay, as in M6L.

## Required fixtures

Correctness uses M6L's two oracles plus the cross-flavor check (§10): content
equality with fresh recipe replay, and maintained values equal to a forced
fresh version-local recount.

- **Recursive value regression:** recursive `min`/`max` over a cyclic graph;
  delete the winning contributor on a cycle and confirm the value regresses to
  the next surviving contributor, not to clear-and-rerun.
- **Corpse fire:** a diamond/refound (and SCC bridge, symmetric cycle,
  cyclic transitive closure from §10's foundedness list) where a later round's
  re-fire of an over-deleted tuple would double-decrement unless excluded —
  the analogue of `m4n_sweep`'s round-3 case (fixture `m7_rank_diamond`,
  whose name predates the rank sidecar's removal).
- **Contributor collapse and loser retention:** two derivations supporting one
  `(key, payload)`; regression falls to a retained losing payload.
- **Struct-keyed recursive lattice:** reuses M5 tombstone identity across
  delete/reseed/relearn with stable ids.
- **Persistence:** save/reopen; load re-establishes the contributor cache
  from the exact historical writers (certifying it) before the first
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

The DRed^c candidate set, affected-key interning, and replacement journal are
shared scheduling state and must be synchronized like the M1/M3/M6L
transition journals. Forced pause/resume is attributed to the repair round it
interrupts and crosses the runtime split-batch boundary.  Nothing O(new
tuples) runs serially at the iteration barrier on this path (the removed rank
stamping did, and was the fixpoint's scaling ceiling — stats.md §1.5).

Runtime reports `(reason lattice-recursive-repair)` as a conditional local
capability for a selective lattice its stratum both writes and reads (the
`recursive_cone_member` mark set at stratum entry); storage-class inspection
is never sufficient admission. Session route messages distinguish recursive
lattice-value repair and named fallback, and prove the complete admitted
recursive-cone shape — mirror of M6L's producer/consumer route reporting.

Deterministic value, shape, struct, persistence, recovery, and fallback cases
are executable gates; randomized repair runs the warm multi-worker fuzz
against fresh recount oracles. Cold-versus-warm performance and
contributor-sidecar memory reporting are separate gates per §7A's
"performance only after correctness" rule.
