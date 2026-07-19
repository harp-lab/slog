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

**Correction discovered at slice 1 implementation (2026-07-18):** the
drafting claim that counted plans already arrive semijoin-stripped was
aspiration, not fact.  `compile.rkt` disabled `semijoin-filters-enabled`
only for the two negative maintenance flavors; `ensure-count-so` left it
at its default, so `_count` plans for rules with three or more positive
clauses (the `n>=3` lookahead gate) carried `exists` c-ops — four plans
in the extant build/ corpus.  Those probes were fire-multiset-neutral
(a semijoin filter prunes only zero-instantiation prefixes, and at a
settled fixpoint its FULL-only probe is exact), so no sidecar or golden
was ever affected — but the doctrine's point is that counted
admissibility should not rest on that argument.  Slice 1 made the
doctrine true at the source: the count flavor now plans with
`semijoin-filters-enabled #f`, `incremental-flavor-abi` bumped
(`m4t-v1` → `ci1-v1`) so every cached flavored artifact and its sidecar
regenerates once, and the seal CHECK refuses any `exists` that
nevertheless appears (the refusal message names sidecar staleness as
the likely cause).  `_maint1` still plans with semijoin lookahead
enabled; slice 2 decides whether to strip it there under the same
doctrine or justify the positive-maintenance exception explicitly.

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

**Slice 4 as-built (2026-07-18).** Flavored variants are interp-only by
default:

- **The compiler stops scheduling flavored clang.**  Each
  `ensure-*-so` now ensures the canonical SIDECARS exist (.cprog +
  .plan, the .plan as the re-emit-on-miss marker per the T1 doctrine)
  and returns the flavored plugin path without running clang; under
  `SLOG_FLAVORED_NATIVE` it builds and returns the native artifact
  exactly as before — the differential's second executor.
- **The daemon routes flavored epochs to the VM by default.**  The
  run_plugin interception is default-on for all four flavored stems
  (the interim `SLOG_COUNT_INTERP` knob is retired); the path the
  session sends is unchanged — the daemon swaps to the sealed sidecar
  internally, and an install failure stays a loud fatal, never a
  silent native fallback.  Corrupted-sidecar probes confirm both
  directions: default + corrupt plan = fatal (interp is really the
  route); `SLOG_FLAVORED_NATIVE=1` builds the .so and dlopens it.
- **No emit-cpp for flavors, ever again** (the non-goal, now
  structural): the flavored emit-cpp paths still exist solely to build
  the differential's native artifacts under `SLOG_FLAVORED_NATIVE`;
  M4N/M7 add interpreter variants exclusively.
- **Exit audit:** recorded in incremental-status.md with the battery
  counts (session default/native legs, incremental-stress worker
  seeds + SLOG_MAX_MS=1 pause injection over the interpreted routes,
  compression×counts + accel).

**Slices 2-3 as-built (2026-07-18).** The three maintenance flavors ride
the slice-1 seam with, again, zero frozen-core changes — the negative
pre-state union view is literally the frozen `new` equation
(FULL ∪ (Δ − FULL)) over the post-overlay indices, so no maintenance
view needed new cursor code:

- **Decode/seal.** `maint1`/`maint3neg`/`maint4neg` seal with
  flavor-static signs (+1/−1/−1); fold kinds decode from the same
  `/<kind>` suffix; `join-tomb` decodes as a full-content struct master
  probe admitted for the negative flavors alone (typed refusals
  elsewhere); struct probes admit old/new views under maintenance (the
  M4S union-view resolution shapes); counted mkstruct lowering stays
  count-only — a maintenance construction emits its content fields with
  the 0-placeholder id for `MaintainStructTask`'s serial resolution.
  The semijoin question the correction note left open is settled the
  light way: `maint1` keeps lookahead admitted and the VM executes any
  `exists` verbatim (its FULL-only probe over-approximates both the
  full and old views, pruning only zero-instantiation prefixes — and
  the 312-plan corpus carries none); the negative flavors keep the
  seal CHECK (`compile.rkt` strips them for exactly the union-view
  soundness hole).
- **Thread-0 additions.** Signed sinks calling the native emitters
  verbatim (`emit_maint`/`emit_lattice_maint`/`emit_struct_maint`); the
  `TombProbeCursor` (live master first, dictionary only on a complete
  live miss, no row on a double miss — `join_probe_tomb`'s exact
  policy); `install_maint_stratum` mirroring the native maintenance
  plugin: full write/intern machinery for non-maintained relations
  (the full-index writer skips negative-sign batches; the delta-index
  writers feed the exclusion and union views), one serial
  `Maintain*Task`/`LatticeMaintainTask` per maintained head (dred for
  maint4neg), maintained-head classification = rule sink targets only
  (prim-error arms keep ordinary machinery, unlike the count flavor),
  and the shared fire-once rule: scans over NON-dynamic relations (the
  staged transitions) run first-iteration-only, dynamic scans chase
  the ripple.  The registration ladders live in their own -O0
  translation unit (plan-flavored-tasks.cpp): instantiating the
  storage templates across the arity range dominated -O2 compile time.
- **Fixtures** (permanent, quick-tier `interp` harness): the maint1
  occurrence-partitioned TC heal (all:/rec over R_old plus the
  delta-driven ripple; healed words hand-pinned and native-differential),
  the maint3neg dual-partition self-join deletion (post-FULL and
  pre-union versions decrementing each deleted pair exactly once), the
  join-tomb resolution differential (live hit / dictionary hit / double
  miss against native `join_probe_tomb`, DRed fold erasing the swept
  head), and the flavored refusal battery (unknown flavors, tomb
  outside negative maintenance, exists in negative flavors, exists
  admitted in maint1).  Fixture staging lesson: signed premise
  transitions must be SENT (`sendBatch`, exactly
  `stageUpdateTransitions`) — a delta staged by direct insertion is
  wiped by the run's entry finalize.
- **The driver-kind divergence the session gate caught.** The first
  full VM-routed run failed all 39 M6L cases from one root cause: a
  lattice CONSUMER epoch is driven by the staged replacement rows in
  the lattice's own delta (`(driver (scan ...))` over a lattice slot),
  and the seal's scan-driver check demanded an ordinary set relation —
  a typed install fatal that killed each lattice case's daemon.  The
  same shape covers struct-driven sweep versions (`delta:pnode/rec`).
  Flavored scan drivers are now kind-agnostic (delta buckets read the
  same regardless of storage kind); probe drivers and every
  normal-flavor driver stay plain-only.
- **Routing (interim):** the `SLOG_COUNT_INTERP=1` hook now intercepts
  all four flavored stems and dispatches by sealed flavor; a
  corrupted-sidecar probe on a maintained stratum confirms the epoch
  path.  Session gates: 528/528 native and 528/528 under
  `SLOG_COUNT_INTERP=1` — every count round AND every maintenance
  epoch (m1/m3/m6l healed-equals-forced, m4t/m4s sweep-reseed-relearn
  with id stability, wcoj-rec) through the VM, with the countrow
  goldens, `recount-lattices-force` contributor comparisons, dump-ids
  stability blocks, and the count-IR oracle as the independent legs.

**Slice 1 as-built (2026-07-18).** Landed with zero changes to the
frozen core — no opcode, VM arm, cursor method, or dispatch moved; the
whole read side composes from the frozen vocabulary plus thread-0
factory registrations:

- **Decode/seal (plan.cpp, plan.h):** `(driver (once))`/`(driver
  (seeded))` decode as one-empty-row dispatch (the enumeration rides
  K=0 body scans over FULL views — the Q1 slice-4 cursor); `(temp name
  arity)` declarations keep their temp bit; `emit-temp`/`emit-lat`
  heads decode as nominal-order head kinds; `mkstruct` heads decode
  with the id register (nominal column 0) first.  The seal admits
  flavors `normal|count` (`maint*` stay typed `flavor` refusals),
  requires the `/<kind>` suffix on every counted variant (typed
  `variant_identity` refusal otherwise), and enforces the semijoin-off
  CHECK.  Counted plans may probe struct masters (the resolution-join
  shape); views on struct probes refuse.
- **The mkstruct lowering.** A counted mkstruct head lowers at seal to
  a pre-fire resolution probe over the content-first/id-last master
  (bound = arity−1, suffix = the id register) plus a post-fire
  nominal-order emit.  The bound cursor is a thread-0 wrapper over the
  ordinary erased probe whose zero-match exhaustion is a loud fatal —
  emit_struct_count's closure stance — and chained constructions
  (deep_fact-class, one construction's id feeding the next's content)
  compose as ordinary nested cursor levels.  No new opcode.
- **Thread-0 sinks (plan-count.cpp):** CountSetSink → `emit_count`
  (closure CHECK, kind tag), TempSink → `emit_temp` (no dedup, no
  kind), KindBatchSink → `emit_lattice_count` (lattice heads and
  resolved struct rows), StructCountSink → `emit_struct_count` (the
  counted tycheck diversion).  All batches reach the unchanged
  CountTask/CountStructTask folds; underflow/overflow/ceiling policy
  rides `tryApplyCount` untouched.
- **The installer** (`install_count_stratum`) mirrors the native
  flavored plugin effect for effect: getRelation-or-add (temps via
  `addTempRelation`; a missing lattice is fatal), full-order index
  requisitions only, counted-head classification = rule sink targets
  (emit/mkstruct/emit-lat, tycheck's malformed_deduction) ∪ the
  declared prim-error arms, per-bucket CountTask/CountStructTask at
  phase_intern, fire-once scheduling for once/seeded rules and
  every-iteration per-bucket tasks for temp-driven scans, sorted
  addReadRel manifest (resolve cursors excluded, matching the native
  derivation), addDynamicRel from the plan's `(dynamic ...)` list, and
  the `beginStratumDelta` → push → continueRun entry.  Counted rounds
  keep the native `$stat_fires` identity: fires bump under (source
  location, base driver tag) — no `/<kind>`, no `#<ordinal>` — so
  cross-executor comparison stays at the aggregated level while the
  harness compares disaggregated per-variant counts directly.
- **Routing (interim):** `SLOG_COUNT_INTERP=1` routes `_count` plugin
  paths through parse/seal/install of the sidecar plan instead of
  dlopen (slogd's run_plugin); default routing is untouched until
  slice 4.  An install failure under the knob is fatal, never a silent
  native fallback.
- **The error-arm divergence the differential caught.** The first
  full `SLOG_COUNT_INTERP=1` session run failed exactly one case
  (m03d, §8B.4 error-arm counting): the VM's primitive-fault path
  still bound the normal flavor's `emit_pending_error`, whose
  kind-less set-semantics batch tripped the M0.3 kind-less-batch
  invalidation at finalize — `clearCounts` FREED the count sidecars
  the registered CountStructTasks captured at construction, a
  use-after-free (ASan-confirmed) that silently killed the daemon.
  Counted rules now bind `emit_pending_error_count` wrappers carrying
  the rule's fold kind, matching native counted codegen; the regression
  is pinned by a permanent fixture case (prim fault → one nonrec arm
  contribution, sidecars alive, fire count excludes the abandoned
  instantiation).
- **The differential fixture** (permanent, quick-tier `interp`
  harness): recursive two-kind sidecar equality (seeded/nonrec +
  seeded/rec vs the native counting tasks, byte-identical words plus a
  hand-pinned expectation), the temp-chain/struct case (wide temp,
  content→id resolution join, CountStructTask id keying, same-source
  fires aggregation), chained mkstruct with a forked-child fatal on
  unsettled content, the prim-fault arm-contribution case above,
  master-content immutability and no-sidecar-on-inputs checks, and the
  typed-refusal battery (maint flavors, missing /kind, exists-in-count
  in body and pre positions, absent admitted, counted-only forms
  refused in normal plans, struct-probe views).
  The session battery ran green natively (528/528) and under
  `SLOG_COUNT_INTERP=1` (528/528 — every recount/recount-force through
  the VM, countrow goldens and the count-IR oracle as the third
  triangle leg).

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
