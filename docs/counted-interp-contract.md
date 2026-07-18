# Counted interpreter contract: admissibility for `_count` and maintenance flavors

Drafted 2026-07-17, at the head of thread 0's spine (roadmap §4.1). The
milestone makes the production interpreter (daemon/plan.h, plan.cpp —
the core frozen 2026-07-16 per interp-core-contract.md) an admissible
executor for the counted and maintenance flavors, so that M4N's
anti-delta variants and M7's lattice/rank repair are implemented as
interpreter variants and never write a line of emit-cpp (roadmap P4;
execution-tiers §4.3, §5.3). This document pins what "admissible"
means, what already exists, the plan-attribute doctrine, the
per-flavor definition of sidecar equality, the slices, and the exit
audit. Authorities: execution-tiers.md §4.3/§5.1/§5.3/§12,
interp-core-contract.md (thread-0 seam and conformance obligation 3),
incremental.md §8B, roadmap §4.1.

## What admissibility means

Execution-tiers §4.3 imposes exactly two obligations, and the gate is
their conjunction across the existing battery:

1. **Exact instantiation multiset.** The interpreter enumerates the
   same rule-instantiation multiset as native code for every flavored
   variant — no existence shortcut in counted join enumeration, no
   re-optimization of the sealed plan. The canonical unit of counting
   is a rule instantiation in the operational IR, bijective through
   physical planning (incremental.md §8B.3); fires are compared
   **disaggregated first** (per RuleVariantId), then aggregated for the
   legacy `$stat_fires` goldens (interp-core obligation 2 — the
   exact-once audit's per-(loc, base-tag) aggregation is fine for stats
   and fatal for executor replacement).
2. **The identical shared folds.** Counted execution drives
   `cnt_apply`/`cnt_try_apply`/`cnt_try_apply_signed` (daemon/counts.h)
   and the existing transition tasks — never a re-implementation.

Gate: **fires-multiset equality plus maintained-sidecar equality
against forced recounts, across the whole existing incremental battery
under interpreter routing** (tiers §12 gates 2 and the §4.3 corollary;
interp-core conformance obligation 3). Content equality alone is
insufficient.

## Ground truth (what already exists)

The milestone is smaller than it sounds, because the write side of
counted execution is already executor-neutral:

- **Flavored plans are already canonical sidecars.** The compiler
  emits ABI-1 `(kernel-plan (abi 1) (flavor count|maint1|maint3neg|
  maint4neg) ...)` files beside every stratum hash in build/
  (e.g. `<hash>_count.plan`), through the same RF1 pipeline the T0
  reader already parses. Counted plans arrive with semijoin filters
  stripped and seeded drivers explicit. The production seal is the
  precise starting line: it currently refuses every non-normal flavor
  with a typed `SealErrorK::flavor` ("T2-A admits normal flavor
  only", daemon/plan.cpp) — slice 1 lifts `count`, slices 2–3 lift the
  maintenance flavors, and the refusal stays for anything unlifted.
- **Count/maintenance tasks are generic templates** (tiers §5.1):
  `CountTask`, `MaintainTask`, `LatticeMaintainTask`,
  `MaintainStructTask` in daemon/operators.h, plus the write/intern/
  lattice ladder. Native flavored .so's contribute per-arity
  instantiation and registration boilerplate — nothing semantic. The
  interpreter's genuinely new surface is the **read side only**: the
  flavored rules' join enumeration, the fires it produces, and the
  sinks that hand signed, prov-keyed batches to those template tasks.
- **The monotone read vocabulary is frozen and conformant.** T2-B
  closed all four pre-freeze groups (joins incl. old/new views and
  K=0 scans, prims/`letp`/`tycheck`, `join3`, map/lattice probes) with
  per-iteration delta and fire differentials against native. Seeded
  and `_delta` shapes are inside the frozen monotone vocabulary.
- **The independent count oracle exists**: tests/api/count-ir-oracle.rkt
  recomputes versioned counts from pipeline + ledger + `_count.cprog`,
  already wired into session-tests.sh (`versioned_count_oracle`). The
  interpreter differential makes the vetting a triangle: native,
  interpreter, Racket oracle.
- **This does not wait for T3a.** T3a (cold-start `SLOG_OPT=interp`
  for semantic strata) is a trunk chore that replaces clang at
  cold start. Count rounds and maintenance epochs are resident-path
  (beginStratumDelta entry, session verbs); the counted interpreter
  installs flavored plans through the T2-A production factory seam
  that already exists in slogd, orthogonal to how the monotone
  strata were built.

## Plan-attribute doctrine

The interpreter executes the sealed flavored plan **verbatim**. Each
attribute below is a pinned refusal-or-respect, not a preference; every
one has a history:

1. **Semijoin filters disabled.** Counted plans carry no `exists`
   c-ops; the interpreter must not reintroduce an existence shortcut in
   any join level (tiers §4.3; docs/semijoin-filters.md exclusion).
2. **Canonical master ordering per flavor.** Every resident flavor
   maintains the one id-last canonical master
   (operationalization.rkt choose-indices, the M4S packer lesson:
   permuted "masters" silently forget the intern dictionary). The
   interpreter maintains exactly the orderings the plan requisitions
   and consults the master the plan names.
3. **Explicit delta orderings.** Delta views are explicit requisitions
   in the plan (T2-B group (i)); no ordering is derived at bind time.
4. **Exclusion views for self-joins.** `join_probe_old`'s
   R_old = full − delta equation for ≥2-dynamic-clause rules is part
   of the fire multiset's definition (exact semi-naive); the counted
   VM uses the same view equations the native helpers do.
5. **Seeded-only index gating.** Seeded re-entry rules see the
   seeded-only index set (the staging×replay two-level classification);
   flavored variants inherit the same gating the plan records.
6. **No tier motion.** Counted and maintenance epochs are unreachable
   by tier swap or restart (tiers §12 gate 13, decision 6). Flavored
   variants are interp-only by default (§5.3); admission removes the
   native flavored path from the default schedule rather than racing it.

A plan whose attributes the VM cannot honor is a typed install-time
refusal (the T2-B refusal style), never a silent degradation.

**ABI-1 interim (pinned at slice 1, 2026-07-18):** rf1-contract.md's
flavored-plan attributes (`no-semijoin-reopt`, per-rule fold kinds,
probe-only `mkstruct`) are ABI-2 vocabulary, and ABI 2 has not landed.
Slice 1 consumes ABI-1 sidecars as they exist: the fold kind decodes
from the rule variant's `/<kind>` suffix (the same discrimination the
attribute will carry — rf1-contract.md "Fold kinds"), and
semijoin-off is enforced as a seal CHECK — an `exists`/`absent-exists`
op inside a `(flavor count)` plan is a typed seal refusal, which is
strictly stronger than trusting a convention. When the ABI-2 split
lands, the kind attribute supersedes the suffix decode and the check
becomes attribute verification; nothing else in this contract moves.

## What sidecar equality means, per flavor

"Maintained-sidecar equality against forced recounts" is pinned as:
after every maintenance epoch or count round, for every counted
(relation, version) in the touched cone,

- **tables:** the kind-decomposed sidecar word of every row —
  input/nonrec/rec components, prov-keyed kinds — equals the word a
  forced fresh recount (`recount-force`) derives from the settled
  content; membership transitions agree (no row present in one and
  absent in the other); `count-state` flags and revisions agree.
- **lattices:** per-key contributor components equal the forced
  recount's (`recount-lattices-force`; M6L contributor-reduce), and
  payload maps agree.
- **structs:** id-keyed sidecar folds equal forced recount; the
  tombstone dictionary's membership split (live vs dead) is identical;
  embedded ids in dependent rows decode identically (the M5/M4S
  settlement invariant).

Comparisons run under the session verbs that already exist
(`dump-counts`, `count-state`, `dump-ids`, `lattice-contributor-state`)
so the differential needs no new observability surface.

## Ownership and seams

Thread 0 work under interp-core-contract.md's seam discipline:
flavored opcodes register in the thread-0 range (96–159 as proposed
there; the pin is disjointness), flavored cursors/sinks in the
thread-0 regions of the factory tables, all in separate files from the
frozen core. No core opcode, VM arm, cursor method, or dispatch change
without joint review. Route admission, session verbs, and reseed
protocols do not move in this milestone.

## Slices

1. **Counted differential harness + `_count` flavor.** Parse/seal/bind
   `(flavor count)` plans through the production reader; a count sink
   folds each fire's prov-keyed kind through `cnt_apply` into the
   sidecar exactly as `CountTask` does natively; seeded drivers, wide
   carried temps, and exclusion views ride the frozen vocabulary.
   Fixture: recount and recount-force through the VM on the counts/
   wcoj3/session count batteries produce byte-identical sidecars and
   disaggregated-fire equality against native, plus count-IR-oracle
   agreement. The differential harness lands here as a permanent
   fixture (extending the quick-tier `interp` harness), with typed
   refusals for the flavors slices 2–3 haven't covered yet.
2. **Positive maintenance (`_maint1`).** Delta-entry maintained
   rebuild/relearn on the M1/M3 acyclic routes and the M6L lattice
   producer/consumer phases: signed batches from interpreted reads
   feed the unchanged `MaintainTask`/`LatticeMaintainTask` templates.
   Gate: healed-equals-forced across the existing m1/m3/m6l blocks
   with the epoch's reads interpreted.
3. **Negative and recursive flavors (`_maint3neg`, `_maint4neg`).**
   Anti-join reads over signed transitions, the DRed sweep drivers,
   and the struct-cone specials: join-tomb resolution probes (live
   master then dictionary; partition occurrences never see the
   dictionary), `MaintainStructTask` absorption, reseed/relearn
   resurrection — all sinks unchanged. Gate: the M4T/M4S/wcoj-rec
   fixture batteries with interpreted maintenance reads, id stability
   included.
4. **Routing + exit audit.** Flavored variants default to interp-only
   (§5.3): the planner stops scheduling flavored clang, the session
   routes counted/maintenance epochs to the VM, and native flavored
   execution remains available only as the differential's second
   executor. Exit audit in the established style: the full incremental
   battery (session, incremental-stress, compression×counts,
   accel) green with interpreted flavors; dual-executor differential
   on every maintenance epoch where both executors exist; adversarial
   scheduling (1/2/8-worker seeds × randomized slice budgets,
   `SLOG_MAX_MS=1`-class) over the new routes; pause/resume injection
   attributed to counted phases (M0.3's walk-close protocol: partial
   rounds drop junk, never publish).

Slice 1 is the admission keystone; 2 and 3 are strictly ordered after
it (they reuse its harness), and 4 flips the default only after 1–3
hold. M4N starts on the slice-4 exit; the M4N anti-delta variants then
become new conformance cases in the same harness rather than a new
mechanism (execution-tiers §11 sequencing note).

## Non-goals

- **No new counting semantics.** Counts remain a recomputable cache
  (incremental.md §8B); no change to kinds, words, or the two-class
  side-channel doctrine.
- **No route-admission motion.** Which cones ride precise routes vs
  clear-and-rerun is unchanged; this milestone changes who executes
  the reads, not when.
- **No counted queries.** Thread 1's query engine stays monotone;
  counted epochs stay unwatchable at level 1 (tiers §7.3) until the
  post-M7 preview/apply revisit, if ever.
- **No emit-cpp for flavors, ever again.** After slice 4 the flavored
  emit-cpp paths are frozen legacy for the differential only; M4N/M7
  add interpreter variants exclusively.

## Exit audit

The milestone exits when, in one review: (a) the slice-4 routing is
the default and the full incremental battery is green with interpreted
flavors under all three worker seeds; (b) the dual-executor
differential and count-IR-oracle triangle hold on every epoch of that
run — disaggregated fires, per-flavor sidecar equality as defined
above, content deltas; (c) forced recounts inserted at randomized
epochs match maintained state everywhere; and (d) the counted plan
attributes are each covered by a typed-refusal or fidelity test
(semijoin absence, canonical master, delta requisitions, exclusion
views, seeded gating, no-tier-motion). The audit note lands in
incremental-status.md with the battery counts, in the established
style.
