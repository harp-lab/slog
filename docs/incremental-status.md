# Incremental Slog implementation ledger

**Reviewed:** 2026-07-14 after M5 slice 1 (struct identity) and the
join3 cross-layer regression
**Normative design:** `docs/incremental.md`

This file records what the tree currently implements and where it differs
from the normative design. It is intentionally historical and operational.
If prose here conflicts with `incremental.md`, the latter defines the target
semantics and this file identifies migration work.

## Baseline

The implementation is green under the current regression gates:

- session workflow harness: 528/528 (now including the wcoj join3
  cross-layer block, the M5 id-stability and embedded-id blocks — both
  import and flat-open halves — and the M4S battery);
- native count checks: 177/177; struct identity battery: 31/31;
- quick harness: unit 163/163, diagnostics 14/14, stats, arena, sequence,
  counts, wcoj3, and structid all pass;
- focused incremental stress: 14/14 gates pass. M3, M4T, and M6L ten-epoch
  signed-stream oracles pass with 1, 2, and 8 workers; their large workloads
  survive phase-attributed forced pause/resume; the
  M6L replacement test crosses the runtime split-batch boundary; recovery
  injection passes; and the latest 240-key report measured 212.626 ms cold
  versus 93.977 ms warm (0.4420), with 479 contributor rows; and
- all modified Racket modules compile with `raco make`.

These tests satisfy the M0.4, M1, M3, and first two M6L exit audits described
below. They establish count reconstruction, version/input semantics, precise
signed support maintenance, and stratified lattice replacement propagation on
their certified surfaces.

The post-slice hardening checkpoint found no product correctness defect. It
did expose and correct one test setup that exceeded the session protocol's
inline tuple limit before reaching the intended runtime split-batch boundary.
The permanent boundary case now uses 2,048 arity-two tuples (4,096 words),
which stays within the protocol limit while crossing the 4,095-word runtime
batch limit.

## Resume point

Begin a future incremental-maintenance review with this ledger, then read
`docs/m4t-contract.md`, `docs/m5-contract.md`, and `docs/m4s-contract.md`
(all implemented) and §4.5–§4.7 in `docs/incremental.md`.
`docs/m6l-contract.md` records the completed lattice admission boundary.
`docs/counted-interp-contract.md` is COMPLETE (all four slices,
2026-07-18; as-builts and the exit-audit note below): the interpreter is
the default executor for `_count` and all maintenance flavors, native
flavored artifacts survive only as the differential's second executor
(`SLOG_FLAVORED_NATIVE`), and M4N — the next milestone — adds its
anti-delta variants as interpreter variants in the same harness.

M4T slices 1 and 2 are shipped; the milestone's table surface is complete.
Edits may target recursive head relations (foundation-aware overlay), and
multi-version chains ride the tip route because the rebound guard already
diverts mid-cone version edges to the anchored walk. Only historical
anchors remain outside M4T, permanently owned by the anchored walk.

M5 slice 1 is shipped: struct intern identity is separated from live
membership through a tombstone dictionary, and clear-and-rerun over struct
cones is id-stable. M4S is shipped in full (slices 1–3, 2026-07-17):
struct cones ride the M1/M3 acyclic routes and the M4T recursive sweep on
that substrate, and the tombstone persistence policy is pinned and
implemented (the chain is the sidecar). The remaining implementation
queue, in the decided order, is:

1. **M7 — recursive lattice/rank repair** (interpreter-first per roadmap
   P4, as interpreter variants on the admitted counted core; the counted
   interpreter and M4N are complete — see their exit audits below).
   `docs/m7-contract.md` (2026-07-23) is the certification target and the
   **single admission gate**; the sub-slices below are implementation
   order only, not separately certified admissions. Admission stays off
   until (b) lands, so no sub-slice weakens fallback:
   - (a) **sidecar substrate** — same-SCC contributor retention plus the
     new rank-witness sidecar (eager forward maintenance) and its
     coverage/certification plumbing; regressions still fall back; gated
     by the fresh-recount oracles.
   - (b) **repair fixpoint on plain tables** — M4T candidate seeding, the
     rank-unchanged exclusion, value re-join from live contributors,
     replacement pairs; opens admission. Fixtures: recursive value
     regression, rank corpse fire, contributor collapse/loser retention.
   - (c) **struct-keyed cones + persistence** — M5 tombstone identity
     across delete/reseed/relearn; load re-establishment from the exact
     historical writers, or certified fallback when that is impossible.
   - (d) **hygiene + exit** — recount abort/retry and replacement-journal
     hygiene, named-fallback routing, the warm multi-worker fuzz,
     sidecar-memory reporting, and the exit audit (the M4N slice-4
     shape).

   Scope note: the `m6l-negation-fallback` route (~ × lattices) does
   **not** clear with M7 slice 1 — the contract keeps negation over a
   changing lattice key on clear-and-rerun until a later, separately
   certified slice.

The handoff gates are `tests/run-all.sh --quick`, `tests/run-all.sh session`,
and `tests/run-all.sh incremental-stress`. The complete orchestrator remains
the arc-end gate.

The W0 checkpoint is test-green: all 17 orchestrator harnesses passed across
sandbox-compatible runs, including clean-build goldens, API, tiered, pause,
compression, and SMT coverage. The M5 input-ledger follow-up is closed
(2026-07-17): both struct-heap recording sites are fixture-pinned — the
import half by `m5-keep-*` (2026-07-15) and the flat-open half by
`m5-open-*`, whose `recount` leg is the regression detector (inheritance
shadows the ledger on the rerun path; the count round's coverage audit
does not).

## Shipped implementation

### Phase 0

- **0.A — stratified negation:** parser, safety, signed dependency metadata,
  stratification rejection, absent probes, lattice-key restrictions, and
  tests are shipped.
- **B0 — version registry/environment:** physical relation ownership is
  separate from name binding; `RelBinding {pos, Relation*}` chains and
  `bind_pos` support positional lookup. Written relations are copied at a
  segment boundary; untouched relations alias.
- **B1/B2 — bounded re-entry:** downstream cone replay and per-version
  clear-and-rerun provide sound Phase-0 handling for unsupported or
  non-monotone updates.
- **B3 — re-entry hygiene:** task registrations are replaced/cleared on
  re-push rather than growing without bound.
- **B4/B5/B6 — routing and delta entry:** positive monotone changes can enter
  lazily compiled set-only `_delta` flavors with exact-once staging. M1's
  counted route now uses the separate `_maint1` flavor.
- **0.C — anchored batch actions:** inline and bin-backed batches,
  position-addressed queries, pipeline introspection, recipe logging, and
  payload placement are shipped.
- **0.D — rename/drop/link:** rename and drop are environment operations;
  flat hot-links and import maps are shipped. A chained hot-link is refused
  with a freeze-first diagnostic.
- **0.E — save/load/freeze:** recipe layers, replay through the live session
  machinery, downstream unseeded replay after mutable negative edits, flat
  freeze, and the workflow/fuzz harness are shipped.

### M0.1 through M0.4

- **M0.1:** packed `input | nonrec | rec` sidecar words exist for tables and
  structs, with checked arithmetic. Sidecars are not ordinary indices and do
  not persist.
- **M0.2:** lazily compiled `_count` flavors enumerate all-full rule plans,
  including wide temp paths and deterministic error emissions. Legacy count
  establishment remains table/struct-only; M6L can explicitly add root
  lattice contributor targets. Nullary counted heads remain excluded.
- **M0.3:** `session-recount!`, count invalidation, per-binding counted flags,
  positional/cone walks, lazy skipping, and count dumps are shipped.
- **M0.4a — identity/topology:** the daemon assigns monotone VersionIds within
  an EvaluationId; versions carry persistent VersionKeys, predecessor IDs,
  schema identity, and exact direct-input state. Stratum instances capture
  exact read/write `(name, VersionId)` maps at their original bind
  environment. Session program events allocate Layer/Event/Slot-based keys,
  and JIT injection creates an input-only successor with an explicit key.
- **M0.4b — input ledger:** direct assertions and inheritance masks are
  authoritative per VersionId. Ordered `+/-` batches normalize against that
  baseline before mutation; normalized overlays persist by VersionKey.
  Program ground facts are non-recursive program support, not editable input.
- **M0.4c — recount runtime:** recount targets exact VersionIds, binds every
  count plugin to its captured historical read/write maps, seeds direct and
  one-per-tuple inheritance support, and builds all target sidecars in private
  epochs. Each VersionId owns its semantic writer IDs; maintenance
  incarnations are excluded, and commit requires exact writer coverage plus
  live/sidecar coverage before an all-target atomic publish. Failure aborts
  scratch state and a retry starts fresh. Relation-scoped recount is
  correctness-first and currently closes the full prefix. A capability action
  explicitly reports recount, precise-deletion, fallback, and exclusion kind.
- **M0.4d — persistence/oracle:** new saves write version-format 1,
  LayerId, descriptors, compatibility anchors, and VersionKey-based overlays;
  legacy ordinal recipes remain readable. Replays receive fresh EvaluationIds
  while retaining persistent VersionKeys. A slow Racket interpreter
  alpha-renames relation references to exact VersionIds, reconstructs input
  and inheritance foundation, interprets canonical `_count` operational IR,
  and diffs every recount-capable version in the live and persisted test
  matrix independently of daemon sidecars.

### M1 — positive signed maintenance

- **Settled revisions:** each evaluation owns an `UpdateEpochId`. JIT
  mutations begin against an expected revision, serialize in the daemon, and
  atomically advance it. Pipeline replies and committed count sidecars expose
  the revision they describe; stale expected revisions are refused.
- **Counted maintenance flavor:** `_maint1` uses exact delta occurrence plans
  with instantiation-injective staging temps. Contributions carry support kind
  and sign into a maintenance sink; premise-only rows do not become live
  tuples. `_delta` remains the legacy positive set-only flavor.
- **Presence-transition chaining:** each update owns a VersionId-keyed journal
  of distinct absent-to-present transitions. Downstream SCCs stage only those
  transitions, while all derivation occurrences still update sidecars for
  already-live heads. Adding direct support to a derived-live tuple updates
  only its input bit and emits no false premise transition. This works across
  recursive SCCs, multiple strata, repeated relation occurrences,
  simultaneous body deltas, and inherited successor versions.
- **Capability and fallback:** positive-arity plain-table cones with positive
  reads and plain-table heads enter `_maint1`; M6L additionally admits its
  certified root lattice head and acyclic positive plain-table consumers.
  Negation, structs, nullary relations, recursive lattice consumers,
  downstream lattice writers, and diagnostic/fallible cones retain
  clear-and-rerun semantics.
- **Injection semantics:** low-level injection remains an input-only successor
  and never retargets historical writers. `session-inject-and-reopen!` applies
  the new input while it is input-only, then creates explicit inherited
  program output slots and semantic writer maps. Later positive edits can use
  M1 through that new version edge.
- **Recoverable failure:** overflow, underflow, or post-update live/count
  coverage failure keeps authoritative set content, invalidates count caches,
  and advances the settled revision as `counts-invalid`; forced recount heals
  the cache. The signed-underflow path is exercised directly even though user
  retractions remain outside M1.

### M3 — acyclic deletion

- **Negative maintenance flavor:** `_maint3neg` plans every lost rule
  instantiation by its leftmost deleted body occurrence. Joins before the
  driver read post-state FULL (`N`); joins after it read the duplicate-free
  union of FULL and the current negative delta (`O`). This covers simultaneous
  input changes, self-joins, and repeated occurrences exactly once.
- **Baseline-aware input removal:** direct support can be removed without
  erasing inherited support. Removing inherited support records a mask and
  preserves direct support. Only a final one-to-zero support transition point-
  deletes the row from all live indices and enters the VersionId-keyed
  negative transition journal.
- **Support and storage invariant:** negative rule consequences use checked
  signed non-recursive counts. Support-only decrements update the sidecar but
  do not propagate; last-support decrements remove both the live row and the
  zero sidecar key. The runtime audits live/count agreement before retaining a
  counted result.
- **Mixed scheduling:** a flush with both signs runs the complete acyclic
  negative cone before the M1 positive cone and publishes one settled update
  revision. Positive and negative transition journals are separate, so a
  tuple's history inside the epoch cannot be confused across signs. Journal
  interning is synchronized because maintenance tasks for distinct head
  relations run concurrently; the shared update-valid flag is atomic.
- **Capability and fallback:** compiler metadata certifies whether each
  stratum is acyclic. Counted positive-body, positive-arity plain-table cones
  enter M3; M6L adds an acyclic root contributor sink plus stratified
  plain-table consumers. Admission mismatch, arithmetic drift, recursive
  lattice strata, negation, downstream lattice writers, structs, nullary
  relations, and unsupported version topology use the normalized-overlay
  clear-and-rerun path.

### M6L slices 1–2 — acyclic lattice repair and stratified propagation

- **Contributor state:** lattice `_count` sinks retain every emitted
  `(key..., payload)` contributor in the existing packed support sidecar.
  Commit reduces those rows by the declared lattice join and requires exact
  agreement with the resident payload map. Contributor certification is
  recomputable, version-local, and separately observable through
  `lattice-contributor-state`; it is never persisted as semantic truth.
- **Signed repair:** lattice maintenance sinks fold signed contributor support,
  intern affected keys, recompute each key once, and replace or remove the
  visible payload across every registered map ordering. Losing, winning,
  final, duplicate, and mixed remove/add cases retain live/count coverage.
- **Admission:** the route requires a root lattice produced inside an acyclic
  positive plain-table cone and no direct lattice edit. Acyclic positive
  plain-table consumers may read the closed lattice value; recursive
  producers/consumers, negation, downstream lattice writers, inheritance, and
  historical edits remain on clear-and-rerun.
- **Replacement transport:** repairs are coalesced by `(VersionId, key)` for
  the complete update epoch. Producer negative and positive phases settle
  first; consumers then receive only the epoch-entry row negatively and the
  final row positively. Read-only lattice deltas bypass ordinary merge tasks,
  so staged old rows never mutate the resident payload map.
- **Compatibility:** ordinary `count-state` and explicit legacy recounts stay
  table/struct-only. Conditional capability reporting uses
  `(reason lattice-contributor-recount)`; topology, not storage class, decides
  leaf versus stratified admission.

### M4T slice 1 — recursive plain-table deletion

- **Sweep flavor:** `_maint4neg` shares M3's leftmost-deleted-occurrence
  partition and signed sinks; only the maintenance interner changes, to DRed
  mode. A live row is over-deleted on FOUNDATION loss (`direct or nonrec>0`)
  rather than presence loss, keeping its sidecar entry while any support
  remains; a row absent from live indices that still owns an entry is a dead
  candidate absorbing later decrements without re-staging or invalidating.
  The retained false-transition rows drive the next round through the
  ordinary fixpoint loop, so rounds, N = FULL, and O = FULL ∪ DeltaMinus come
  from machinery M3 already shipped.
- **Candidate state:** the epoch's negative journal plus retained sidecar
  entries; there is no separate candidate structure. Each tuple enters
  candidacy at most once because staging requires live membership.
- **Reseed:** the `dred-reseed` action scans the swept relations' journal
  rows after the complete negative walk; survivors (`rec > 0`) are reinserted
  into every live ordering and journaled +1 so the unmodified M1 positive
  walk performs the rebuild, including relearning zero-count candidates from
  reseeded premises. Reply: `(dred-reseeded R D)`.
- **Schedule:** M3's cone-wide negative-then-positive walk with reseed
  between the phases. Downstream strata stage their DeltaMinus while every
  journaled row is still absent from FULL — staging a reseeded row while
  live would double-decrement self-join partitions — and the positive walk
  runs whenever reseed restored anything, even for negative-only batches. A
  tuple restored by reseed or relearn reaches downstream in both journals as
  an exact cancelling cascade.
- **Routing:** counted, single-version, tip-edited plain-table cones mixing
  certified acyclic strata (running `_maint3neg`) and recursive SCC strata
  (running `_maint4neg`), with no lattice in the cone and no edited relation
  dynamic in a recursive stratum. Fully acyclic cones keep the M3 route.
  Route messages: `(route maintain-recursive-negative N)`, the reseed
  report, and the existing positive-walk message.
- **Substrate fix:** maintained point mutations (`MaintainTask` inserts,
  `insertTupleAllIndicesPreservingCounts`,
  `removeTupleAllIndicesPreservingCounts`) now cover every registered
  non-seeded full ordering. Previously M1 inserts touched only the running
  flavor's master ordering, silently leaving other flavors' orderings stale
  — a latent bug that M3's fixtures never exposed because no multi-column
  head was ever read through a second ordering.

### M4T slice 2 — recursive-head edits and inheritance admission

- **Foundation-aware overlay:** `set-overlay-negative-dred`
  (`Relation::setInputOverlayNegativeDred`) applies retractions to
  relations dynamic in a recursive cone stratum with the sweep's own fold:
  support-only decrement while another foundation survives; candidacy on
  foundation loss with `rec > 0` (row leaves live indices, journaled −1,
  sidecar entry retained); ordinary presence loss at zero. The session's
  M4T route selects the verb per edited relation; every other route keeps
  the presence-semantics verb, which is equivalent outside recursive
  strata.
- **Inheritance admission:** the single-version-chain gate is gone.
  `cone-of`'s rebound guard already diverts mid-cone version edges to the
  anchored walk, so on the tip route inherited support is a settled
  predecessor's stable nonrec contribution: it never enters candidacy
  without an explicit mask edit, and masking an inherited recursive-head
  row composes with candidacy and reseed (the mask persists while
  presence returns through derivation).
- **Substrate fix:** clear-and-rerun re-materializes the cleared
  relations' input baseline (`Relation::rematerializeInputBaseline`:
  unmasked predecessor rows plus direct assertions), mirroring the
  anchored walk's `refreshVersion`. Before the fix, a fallback rerun
  silently dropped direct assertions on derived relations and the next
  count epoch aborted on the orphaned sidecar seed.

### M5 slice 1 — struct intern identity separated from live membership

- **Storage split:** the intern dictionary is the live master ordering plus
  a per-bucket content-to-id tombstone store (`Relation::struct_tombstones`,
  bucketed by the master ordering's leading content column — exactly
  `InternStructTask`'s routing, preserving per-bucket task exclusivity).
  Live and dead mappings are disjoint by construction; forward-only
  evaluations never materialize a tombstone.
- **Resurrection:** a live-master miss in `InternStructTask` consults the
  bucket's tombstones and reuses the retained id without allocating; the
  import path's `internStructTuple` does the same via
  `takeTombstoneByFields`. Verbatim ingestion
  (`insertTupleAllIndicesPreservingCounts`) reconciles a matching tombstone
  and fatals on a mismatched id — the previously silent cross-version
  remint hazard is now an audit.
- **Removal retains identity:** `removeTuple`/`removeTuples` (Phase-0 input
  edits) and the new `tombstoneStructRow` point verb (all non-seeded
  orderings; M4S's sweep hook) install the mapping they drop.
- **Clear discipline:** re-derivation clears (`clear-rel`, `clear-rel-at`,
  `refreshVersion`) use `clearContentsToTombstones`, so fallback
  clear-and-rerun over struct cones now RESURRECTS the original ids —
  including direct assertions and inherited rows that embed struct ids.
  Id-space-severing paths (`loadRelation` disk refresh) drop tombstones;
  `newVersion` copies them (the dictionary is version state).
- **Persistence limitation:** tombstones are session-local; saves carry
  live content verbatim as before. Identity across a save/load boundary is
  guaranteed for content live at save time; dead-content resurrection
  stability across saves waits for M4S's persistence decision.
- **Observability:** the `dump-ids` action (`(idrow W)` rows plus
  `(idsdone N tombstones)`) exposes raw id words and the tombstone count.
- **Tests:** `tests/struct-identity-tests.cpp` (`structid` quick-gate
  target: resurrection, no-recycle, all-orderings removal, verbatim
  reconciliation, drift fatals, severance, version copy) and the
  `m5-ids-*` session block (id stability across a routed clear-and-rerun,
  tombstone consumption on reappearance).
- **Embedded-id leg (2026-07-15):** the deferred exit-criterion-2 fixture
  (`m5-keep-*`: frozen mini bin-db asserts `(out (pair 7 8))` directly,
  nothing re-derives it, cone clear-and-rerun) exposed and fixed a real
  input-ledger hole — `importDatabaseBIN` recorded a direct-input
  payload's table rows but not its struct heap, and flat-open
  `markLatestRelationsDirect` had the same pre-M5 struct exclusion, so
  the restored table row's embedded id stayed tombstoned and silently
  decoded as garbage. Both sites now record struct instances as direct
  input; the baseline's verbatim re-insert reconciles the tombstone
  (drift still fatals). See `docs/m5-contract.md` exit criterion 2.
- **Embedded-id leg, open half (2026-07-17):** the flat-open site is now
  fixture-pinned too (`m5-open-*`: `--out-db` root asserting
  `(out (pair 7 8))`, opened as the session base). The rerun path cannot
  detect this half — the opened version is every tip's predecessor, so
  `rematerializeInputBaseline` restores through unmasked inheritance
  regardless of the recording — but the count round walks the opened
  version itself: without the input bit its struct instance carries no
  support kind and the coverage audit fatals the daemon (verified by
  reverting the exclusion). The block's `recount` is the regression
  detector; the edit cycle and forced recount pin decode, id stability,
  and the re-derived support shape.
- **No admission change:** struct cones still route to clear-and-rerun and
  struct counts remain diagnostic; M4S owns route admission.

### M4S slice 1 fixtures — fallback-first (2026-07-15)

The `m4s-*` blocks in `tests/session-tests.sh` land the contract's fixture
battery asserting today's fallback: struct diamond with tail, recursive
construction self-join, the `(p P) --> (q (bar P))` pass-through chain,
multi-constructor support, import-then-edit over a would-be-admissible
(lattice-free) cone, a mixed-sign epoch, and the named fallbacks (struct
relation as edit target, lattice+struct cone, negation+struct cone).  Each
deletion asserts `(route rerun ...)` plus M5 identity (dump-ids stability,
embedded-id decode) and compares hand-verified support words across a lazy
heal and a forced fresh recount; `FLIP(M4S slice N)` comments mark the
localized precise-route edits.  Save/load mid-stream (slice 3) and the
randomized hardening are deliberately deferred.

Landing them exposed one substrate hole, fixed because the diamond fixture
cannot run without it (its recount op fatals the daemon mid-drive and its
contract-mandated id-stability assertion is otherwise false):

- **Permuted struct master across flavors.**  The greedy index packer
  could unify a struct's intern MASTER ordering with a permuted probe
  selection (the diamond's delta flavor chose `(2 1 0)` for `pnode` while
  the semantic flavor held `(1 2 0)`), so two flavors owned two disjoint
  "masters" and whichever one a flavor never wrote went silently stale:
  `clearContentsToTombstones` walked the empty one and REMINTED every id
  across clear-and-rerun (an M5 violation), and a count round after a
  delta-entry flush fataled with "derived an uninterned instance".  Fix
  (compiler-only): `choose-indices` (compiler/operationalization.rkt) pins
  every flavor's struct full-content selection to the canonical ordering
  `(1 2 ... n 0)`; permuted probes get secondary orderings, so the
  canonical master is the unique id-last ordering and every runtime master
  authority resolves to it.  The M4T "every registered ordering is
  somebody's authority" lesson, recurring between flavors; base2-shaped
  fixtures missed it because their structs are never read back.

The recorded retraction-misreport gap closed with slice 1 (below): the
negative sign is now refused by name on the normalization error path
(`session.rkt` consults the live schema only when the generic error would
fire), keeping the positive sign's `set-overlay` refusal untouched.

### M4S slice 1 — acyclic struct-cone admission (2026-07-17)

Struct relations are admissible interior cone members on the M1 positive
and M3 acyclic negative routes; the chain, multictor, mixed-sign, and
import fixtures are flipped to their precise-route assertions.

- **Daemon:** `emit_struct_maint` (signed content-only emission, 0 id
  placeholder) and `MaintainStructTask` (one task per relation at
  phase_intern: sign-directed id resolution — ordinary intern path with
  tombstone resurrection when positive, PROBE-ONLY via live master then
  the non-erosive `peekTombstone` when negative, miss = epoch-invalidating
  fold error; id-keyed sidecar fold; `tombstoneStructRow` /
  `insertTupleAllIndicesPreservingCounts` membership transitions;
  journaled transitions retained as next-iteration delta).  Signed overlay
  verbs gained by-name struct/lattice guards (defense in depth — a
  content-arity tuple must never reach a struct overlay fold).
  Capability line: structs now advertise `(precise-delete conditional)
  (reason struct-recount)`.
- **Compiler:** `session.rkt` accepts `struct-recount` capabilities and
  gates routes on `struct-cone-admissible?` (no struct edit target, no
  lattice in the cone, all strata acyclic; M4T/M6L2 routes additionally
  require struct-free cones until slice 2).  `emit-cpp.rkt` emits the
  maintenance struct sink and registers `MaintainStructTask` (the
  recursive sweep flavor still refuses struct heads loudly).
  `join-planning.rkt`: struct occurrences outside a non-temp partition —
  the content→id RESOLUTION joins of staged struct-head follow-ups — get
  the `'new` (`FULL ∪ DeltaMinus`) view in the negative flavor; the dead
  row leaves FULL at the fold one iteration before its follow-up fires,
  and temp-driven versions otherwise probe all-FULL (exact for tables
  because instantiation-injective temps carry every bound value; the
  struct id does not exist at stage-1 emit time).
- **Semantics validated by the flipped battery:** support-only decrements
  keep rows live under their original ids; last-support transitions
  tombstone with identity retained; constructor coupling holds (struct row
  and sibling head rows gain/lose together); a mixed-sign epoch resurrects
  the id within one epoch; import-ledger foundation survives maintained
  deletion; healed sidecars equal forced recounts everywhere; embedded ids
  decode after every settlement.

### M4S slices 2+3 — recursive sweep + persistence (2026-07-17)

Slice 2 admits struct cones to the M4T sweep; slice 3 pins and implements
the tombstone persistence policy. Diamond, selfjoin, and the new dredhead
fixtures assert sweep routes, reseed/discard counts, and id resurrection;
the persist fixture pins the save/load policy.

- **The sweep rode slice 1's fold almost verbatim** — `MaintainStructTask`
  already carried the DRed policy (over-delete on `cnt_foundation` loss,
  dead-candidate absorption through the non-erosive tombstone peek), and
  `dredReseedCandidates`/`dredReseedRow` needed NO struct changes: the
  reseed's verbatim reinsert reconciles the retained tombstone (the
  contract's verb-mapping table), and relearns resurrect through the
  ordinary intern path.
- **The one genuinely new mechanism (`join-tomb`):** the selfjoin fixture
  exposed that a staged struct-head follow-up's content→id RESOLUTION join
  cannot be a view join in the sweep — a round may tombstone the head
  arbitrarily many rounds before the last follow-up decrement referencing
  it, and the retained delta witness lives one round (slice 1's `'new`
  view broke exactly there: 8 candidates over-reseeded, unfounded rows
  survived, and recount fataled on unsupported live rows).  Resolution
  joins now lower to `(join-tomb ...)` → `join_probe_tomb` (live master,
  then `peekTombstone`), a distinct c-op so partition occurrences keep
  their exact N/O views — a dictionary there would double-decrement.
- **Routing:** `struct-cone-admissible?` drops its acyclicity clause; the
  m4t route requires it (struct edit targets and lattice+struct cones
  still refuse by name); m1 admits recursive struct cones (the rebuild and
  re-add legs).
- **Persistence (slice 3):** tombstones never persist.
  `Database::reconstructStructTombstones` — invoked once at the end of
  every session load via the `reconstruct-tombstones` action — walks each
  struct chain root→tip computing `dict(v) = (live(pred) ∪ dict(pred)) −
  live(v)` (nearer ancestor wins; severance markers reset; keying mirrors
  `getMasterIndex` exactly via the new non-fatal `tryMasterIndex`, with a
  canonical-order fallback for fresh successors holding only the identity
  default).  As built, recipe replay re-mints most mappings by re-running
  the same routes; the pass closes the invariant independent of them and
  is the seam future verbatim chain loads (N4) ride.  The formula is
  pinned by the `structid` unit battery (43 checks; simulated
  dictionary-less load over a registered 2-version chain, ancestor-id
  resurrection, idempotence); the session fixture pins the end-to-end
  policy and never compares tombstone counts across the boundary.
- **Hardening found along the way:** `emitInputStates` refuses wrong-arity
  (including empty) tuples by name instead of reading past a null
  `data()` pointer — a malformed driver request could segfault the daemon.

### WCOJ ternary joins × incremental artifacts

The `wcoj-tri-*`/`wcoj-rec-*` session block (over
`tests/session/wcoj_tri.slog` and `wcoj_tri_rec.slog`) closes the
`docs/wcoj.md` §15 cross-layer gap: it asserts a `join3` action is present
in the normal, `_count`, `_maint1`, and `_maint3neg`/`_maint4neg` `.plan`
sidecars of the artifacts each run compiles, and gates maintained support
sidecars against forced fresh recounts across positive maintenance,
acyclic deletion, the recursive DRed sweep (behind the foundation-aware
overlay verb on the recursive head), and relearning.

Legacy labels retained by code comments and tests map as follows:

- **A1–A8:** parse, safety, stratification, operationalization, runtime
  absence probes, lattice hardening, polarity metadata, and negation tests;
- **B0–B6:** version environment, replay cone, clear/rerun, re-entry hygiene,
  routing, delta flavor, and exact-once staging;
- **C1–C5:** actions/queries, recipe format, session log, bulk policy, and
  payload placement (`C0` in a few comments means the positional bind/anchored
  walk hardening that shipped with this group);
- **D1–D5:** environment rename/drop, schema threading, shared replay verbs,
  import name maps, and flat hot-links; and
- **E0–E4:** anchor hardening, save, replay, freeze, and workflow harness.

Primary anchors:

- `compiler/session.rkt` — session recipe, routing, recount, and batch log;
- `compiler/compile.rkt`, `compiler/join-planning.rkt`,
  `compiler/emit-cpp.rkt` — count/delta/maintenance flavors;
- `daemon/database.h`, `daemon/operators.h`, `daemon/counts.h` — version
  bindings, sidecars, and count tasks; and
- `tests/session-tests.sh`, `tests/api/count-ir-oracle.rkt`,
  `tests/api/stream-fuzz.rkt`, `tests/api/acyclic-stream-fuzz.rkt`,
  `tests/api/lattice-stream-fuzz.rkt`, `tests/api/lattice-recovery.rkt`,
  `tests/incremental-stress.sh`, and `tests/counts-tests.cpp` — present
  regression coverage.

## Known limitations and deviations

These remain explicit capability boundaries or future correctness work.

1. **Struct cones are precise on every counted route (M4S complete);
   struct edit targets and lattice+struct cones refuse by name,
   permanently.** Struct relations are admissible interior members of
   M1/M3 acyclic cones and M4T-swept recursive cones, with load-bearing
   id-keyed counts; direct edits targeting a struct relation are refused
   by name (import-delta carries struct-embedding input), and lattices
   anywhere in a struct cone wait for M7's shapes. Tombstone persistence
   follows the chain-is-the-sidecar policy (never saved, reconstructed
   at load).
2. **Recursive signed deletion is tip-local and plain-table only.** M4T
   handles counted recursive plain-table cones reached by any tip-local
   edit, including edits targeting the recursive head (foundation-aware
   overlay verb) and multi-version chains (inherited support is a stable
   nonrec barrier on the tip route). Mid-cone version edges divert to the
   anchored walk via the rebound guard; historical anchors keep the
   anchored walk permanently.
3. **Precise negation maintenance is absent.** Current absent probes implement
   set construction. M4N still needs anti-delta variants and transition
   scheduling.
4. **Recursive lattice repair is not enabled.** Contributor repair and
   old-to-new propagation are precise for certified root/acyclic producers and
   stratified acyclic plain-table consumers. Recursive producer/consumer
   regression remains M4T/M7 fallback work; negation and downstream lattice
   writers are also excluded.
5. **Chained hot-links remain refused.** Freeze the target first or load it as
   a base chain.
6. **Low-level injection is intentionally input-only.** `inject-version`
   creates a distinct successor and overlay target but does not silently
   retarget historical rule writers. Derivation requires the explicit
   `inject-and-reopen` semantic event; only its explicit inheritance policy is
   currently accepted.

## M0.4 exit audit — complete

Every recount-capable VersionId in the current relational, recursive,
version-barrier, struct-diagnostic, negation, and lattice-boundary matrix
matches the independent desugared operational-IR count. The matrix covers
injection, inheritance, masks, rename/drop/redeclare, import/link, freeze, and
save/load. Unsupported IR fails loudly instead of being certified by default.

The authoritative semantic-writer set is compared exactly at commit. Injected
writer omission aborts the whole scratch epoch, as does forced test-width
overflow; both preserve the last committed sidecars and correct set content,
and retry succeeds. Positive recount cannot underflow; M1 directly exercises
recoverable signed underflow as a cache-invalidation gate, and M3 exercises
real direct and inherited user decrements.

## M1 exit audit — complete

Capability-certified positive table edits now maintain both set content and
support counts. Regression coverage compares maintained counts with a forced
fresh recount after recursive, multi-stratum, simultaneous, repeated-
occurrence, support-only, overflow-recovery, and explicit version-inheritance
updates. It also replays the saved reopen topology into a fresh EvaluationId
and checks it with the independent VersionId oracle. Expected-revision
rejection, count-establishment fallback, and recoverable signed underflow are
covered.

M1's positive surface remains valid for recursive plain-table cones. This is
not permission to use M3 negative maintenance for recursive deletion, structs,
lattices, nullary relations, negation, or implicit injection reactivation.

## M3 exit audit — complete

Capability-certified acyclic table edits now maintain set content and support
counts under direct removal, inherited masking, and mixed negative/positive
flushes. Deterministic coverage includes support-only and last-support
decrements, repeated body occurrences, self-joins, downstream strata,
inject-and-reopen inheritance, maintained-versus-recounted sidecars, and an
explicit recursive program that must route to clear-and-rerun.

The signed-stream differential harness generates legal ordered edits over two
inputs and retains one warm maintained session for ten flushes. After each
flush it compares every input, derived relation, and support sidecar with a
separate fresh session and forced recount; the tested session is not refreshed
by the oracle. Fixed session seeds and independent one-, two-, and eight-worker
stress seeds cover both edit diversity and scheduling. Forced-pause coverage
now attributes the pause to the negative maintenance phase itself. The M3
surface is therefore closed. M6L stratified repair now builds on it; M4T
remains the separate recursive plain-table deletion milestone.

## M4T slice 1 audit — implemented

Deterministic fixtures settle on the precise route with maintained sidecars
equal to forced fresh recounts: the §5.2 symmetric unfounded cycle (both
tuples over-deleted, neither reseeded), the §5.3 diamond with tail
(`path(1,4)` reseeded from surviving recursive support, `path(1,5)`
relearned by the rebuild), closure by self-join over the swept relation
(repeated occurrences across multi-driver rounds; a purely recursively
founded survivor reseeds), a two-SCC bridge whose sweeps both run inside
one topological negative walk, and a mixed-sign epoch that deletes,
reseeds, relearns, and inserts a genuinely new edge in one revision. An
edit targeting the recursive head itself pins the named fallback.

Randomized recursive signed streams (`tests/api/recursive-stream-fuzz.rkt`)
toggle edges over a dense cyclic universe for ten flushes — plus, since
slice 2, one direct assertion toggle on the recursive head per flush — and
compare every flush's content and support sidecars — including an acyclic
downstream consumer reading the swept relation twice — against fresh
rerun-plus-forced-recount sessions; the stress harness runs independent
seeds under one, two, and eight workers. A forced-pause epoch
(`recursive-pause-stress.rkt`, 800 diamonds under `SLOG_MAX_MS=1`) mixes
head-row and edge deletions in one revision, crosses several pause/resume
boundaries inside the sweep/reseed/rebuild epoch, and settles counts-valid
with exact reseed counts and sizes.

Slice 2's deterministic fixtures pin: the zero-rec head deletion
degenerating inside the sweep epoch, the derived-and-asserted head
deletion (candidacy at apply, reseed, downstream relearn), the unfounded
pair fed by a direct head assertion, the inherited-input mask whose
successor sweep finds only support-only barriers, the inherited head-row
mask that reseeds from successor-local recursive support, the mid-cone
version edge diverting to the anchored walk, and the clear-and-rerun
input-baseline regression.

## M6L slices 1–2 audit — implemented

The deterministic matrix covers losing, winning, final-key, duplicate,
net-no-change, appearance/disappearance, and mixed contributor updates. It
also covers max and flat lattice payload shapes, multi-column keys, reversed
consumer index ordering, multiple producer strata, and a save/reopen that
begins uncertified and repairs its contributor cache before precise admission.
The stratified fixtures prove that a mixed update publishes no intermediate
payload, maintains downstream tables, and reproduces content and both
sidecars under forced recount.

The ten-epoch randomized streams retain warm maintained sessions and compare
each flush's content and sidecars with independent fresh recount sessions
under one, two, and eight workers. Forced pause/resume is attributed after the
replacement consumer phase begins, and the 2,048-key case crosses the runtime
split-batch boundary. Recovery gates inject recount abort, semantic-writer
omission, contributor overflow/fallback, cache healing, and a next-epoch
replacement-journal check. Named fallback fixtures cover recursive producers,
recursive consumers, negated lattice consumers, downstream lattice writers,
direct lattice overlay refusal, and inherited successors. This is the M6L
slices 1–2 hardening checkpoint; the admission boundary remains intentionally
closed while work moves to M4T.

## Counted interpreter exit audit — complete

The production interpreter is the default executor for every flavored
variant: count rounds and all three maintenance flavors parse, seal, bind,
and execute through the sealed-plan seam with zero changes to the frozen
core, and the compiler no longer schedules flavored clang (the sidecars are
the artifact; `SLOG_FLAVORED_NATIVE` rebuilds the native flavored plugins
as the differential's second executor).  The read side composed almost
entirely from the frozen monotone vocabulary — the negative pre-state union
view is the frozen new-view equation over post-overlay indices — plus
thread-0 registrations: kind-tagged and signed sinks that call the native
emitters verbatim into the unchanged CountTask/Maintain*Task folds, the
mkstruct resolution cursor with the settled-fixpoint closure fatal, and the
join-tomb cursor with the live-master-then-dictionary policy.

Deterministic coverage rode the existing batteries with every flavored
epoch interpreted: the session battery green on both executors (528/528
default-interpreted and 528/528 under `SLOG_FLAVORED_NATIVE=1`), with
maintained-equals-forced countrow comparisons, lattice contributor state
under `recount-lattices-force`, struct id stability and resurrection
blocks, and the independent count-IR oracle as the triangle's third leg.
The permanent dual-executor differential lives in the quick-tier interp
harness (38 cases): per-flavor sidecar byte-equality against the native
tasks plus hand-pinned words, disaggregated fires, the chained-construction
closure fatal, the prim-fault error-arm regression, and the typed-refusal
battery over the plan attributes (semijoin absence, tomb and view
admissibility, fold-kind identity).

Adversarial scheduling over the interpreted routes: the signed-stream fuzz
harnesses retained warm maintained sessions for ten flushes against fresh
recompute-and-forced-recount oracles under one, two, and eight workers
(m3/m4t/m6l seeds), and forced pause/resume attributed to the maintenance
phases ran under the one-millisecond slice budget — 14/14 with every
maintenance epoch interpreted.  Compression×counts and the accelerator
sidecars ran green (104/104) with interpreted count rounds on replay.  The
differential earned its keep twice before the flip: the prim-fault
error-arm use-after-free (kind-less batches freeing count sidecars
mid-round) and the lattice-driven consumer refusal (flavored scan drivers
are kind-agnostic — a consumer epoch is driven by the staged replacement
rows in the lattice's own delta).  M4N's anti-delta variants now land as
interpreter variants and new conformance cases in this same harness.

### M3 retrospective and forward implications

- **Occurrence ownership is part of the contract.** M1 uses the rightmost new
  occurrence (`N / DeltaPlus / O`); M3 uses the leftmost deleted occurrence
  (`N / DeltaMinus / O`). Either dual convention could be exact, but prose,
  planner marks, runtime views, and repeated-occurrence tests must name the
  same one. The stale plan text did not, and was corrected during M3.
- **Scheduling metadata is concurrent state.** A strengthened per-flush fuzz
  oracle exposed an intermittent equal-size/different-content `p`/`q` result.
  Parallel maintenance tasks for two heads were mutating one transition hash
  without synchronization, occasionally dropping the downstream signal. Both
  signed journals are now locked and update validity is atomic. This same rule
  applies to future lattice repair and DRed candidate scheduling.
- **Storage capability is not semantic capability.** Plain tables can remove a
  tuple from every index, but `precise-delete` remains conditional until the
  complete version cone is counted and certified acyclic with supported rule
  kinds. Capability reports should continue separating local mechanism from
  cone admission.
- **Zero has one representation.** A last-support decrement removes the live
  tuple and its sidecar key. Keeping a stored zero would create two encodings
  for absence and weaken live/count coverage audits.
- **Versions remain explicit barriers.** Editing an existing input overlay and
  injecting/reopening a successor are different API operations. M3 maintains
  inherited removal through a mask on the successor without mutating its
  predecessor. Historical/back-anchored edits remain correct through replay;
  they are not silently admitted to the tip-only precise route.
- **Do not stretch M3 into recursion.** M4T needs explicit candidate identity,
  round-scoped live visibility, a foundation barrier, reseed, and positive
  rebuild. M3's immediate zero-support point deletion is useful substrate, not
  a foundedness algorithm. M6L similarly needs contributor identity per key,
  rather than treating the currently visible lattice payload as a tuple count.
- **The input baseline is not a rule consequence.** Clear-and-rerun must
  re-materialize direct assertions and unmasked inheritance for every
  cleared relation before re-derivation; re-running rules alone quietly
  loses input rows on derived relations, and the loss only surfaces when a
  later count epoch finds the overlay-seeded sidecar key absent. The
  anchored walk's `refreshVersion` always knew this; the tip rerun did
  not. Any new "clear then rebuild" path must start from the normalized
  overlay, not from an empty relation.
- **Every registered ordering is somebody's authority.** M4T's all-orderings
  removal exposed that M1's maintenance inserts populated only the running
  flavor's master ordering, leaving the semantic stratum's differently
  permuted ordering silently stale. Distinct flavors legitimately requisition
  distinct orderings on one resident relation; a maintained mutation must
  cover them all (seeded-only orderings excepted), or the next stratum to
  read a stale one under-derives without any error. Fixture relations whose
  multi-column heads are never read back masked this for two milestones —
  new fixtures should include a head that is also a join input.

## M4N intersection-matrix ledger (slice 3, 2026-07-22)

The standing vetting campaign's first installment: every composition of
stratified negation with another feature is either PRECISE (a named
battery block proves maintained-equals-forced), FALLBACK (a named test
asserts the refusal and the recompute), or EXCLUDED (pinned in
m4n-contract.md with its owner).  "Precise" always means: admission is a
session predicate, mis-staging is a typed daemon fault, and the epoch
commits counts-valid.

| composition | status | evidence / owner |
|---|---|---|
| ~ x acyclic readers, edited negated input | PRECISE (slice 1) | `m4n-*` block: 4-flush canon, sibling pre/post split, healed-equals-forced |
| ~ x recursive readers (DRed sweep), edited negated input | PRECISE (slice 2) | `m4n-sweep-*`: absent-ever corpse probes; the double-decrement hazard is a live fixture |
| ~ x derived negated relation, acyclic readers, loss-only reader positives | PRECISE (slice 3) | `m4n-derived-precise-*`, `b4-neg-*` (the historic 0.A8 reserved case) |
| ~ x derived negated relation, reader-positive GAINS | FALLBACK: producer-precise + reader-suffix rerun, decided per flush from the epoch journals | `m4n-derived-gains-detected`; general unlock = the `join-pre` XOR join view (late slice 3 / M7) |
| ~ x derived negated relation, recursive readers | FALLBACK: producer-precise + reader-suffix rerun | `m4n-sweep-derived-suffix-reruns`; compose after `join-pre` |
| mixed edited + derived negated relations in one cone | FALLBACK: full rerun (the slice-1/2 admission hole, closed) | `m4n-mixed-negs-hole-closed` |
| ~ x inheritance / masks (inject-reopen) | PRECISE on both routes | `m4n-inherit-*`, `m4n-sweep-inherit-*` |
| ~ x demand, blocker outside the demand cone | PRECISE | `m4n-demand-*` |
| ~ x demand, blocker inside the demand cone | EXCLUDED via structs (demand memoization is struct-backed) | `m4n-demand-inside-fallback` |
| ~ x temps | subsumed: maintenance planning stages temps only for struct construction, so ~ x temps c ~ x structs; flat conjunctive bodies plan temp-free at any width (probed to 6 clauses) | planner probe 2026-07-22; struct row below |
| ~ x structs in the cone | EXCLUDED (pinned, M4S owns the tombstone interplay) | `m4s-negstruct`, `m4n_demand_inside` |
| ~ x lattices | EXCLUDED (pinned, M7 owns; NOT cleared by M7 slice 1 — m7-contract.md keeps it on clear-and-rerun until a later separately certified slice) | `m6l-negation-fallback` (also 'negw-shaped) |
| prefix/wildcard negation ('negw) | FALLBACK by shape (prefix absence is not row-transition-maintainable) | `m4n-negw-fallback` |
| relation read both + and ~ in one cone | FALLBACK | `m4n-mixedread-fallback` |
| ~ under `SLOG_FLAVORED_NATIVE` | FALLBACK at admission (anti-delta variants have no native leg; emit-cpp static_asserts) | `m4n-native-fallback` |
| maintenance x body CONSTANTS (any flavor, ~ or not) | PRECISE after the slice-3 fix -- constant-bearing driver clauses hung every maintenance flavor since M1 (keyed delta-index probes never drain in a maintenance epoch); drivers now lift constants to full-shape scans and the seal refuses probe drivers under maint flavors | `m1-body-const-*`; flavor ABI ci1-v2 (plans now abi-keyed like .so's) |

## M4N exit audit — complete

Precise stratified negation is maintained end-to-end on the interpreter:
acyclic readers over edited negated inputs (slice 1, the finalize-upfront
Option-2 route with drive/view staging), recursive sweep readers (slice 2,
the absent-ever table), and derived negated relations (slice 3, the
producer-precise/journal-sign-decided schedule), with the intersection
matrix above naming every composition's status and the exclusions' owners
(structs -> M4S follow-up, lattices -> M7, `join-pre` and derived x
recursive recorded as unlocks).

Deterministic coverage: the session battery's m4n blocks — the four-flush
acyclic canon with the pairwise sibling split, the sweep cascade whose
mixed flush is the slice-2 double-decrement hazard live, self-join
closure, inheritance masks on both routes, demand split by cone shape,
the mixed input+derived admission-hole regression, five named fallbacks,
and the maintenance x body-constant fixture — all healed-equals-forced,
plus count-IR oracle legs on both canon runs (the triangle's third leg
over interpreted negation plans).

Adversarial coverage (incremental-stress): a combined negation
signed-stream oracle (acyclic + sweep readers in one program, ten
mixed-sign warm flushes diffed per flush against fresh recompute and
forced recounts) under 1/2/8 workers; a derived-negated boundary hammer
whose flush generator cycles route classes so BOTH sides of the
journal-sign decision fire every run (asserted), with the
constant-column negated atom keeping the body-constant fix in the loop,
under 1/2/8 workers; and a forced pause/resume epoch whose pauses
attribute to the negation stratum's `_maint3neg` phase at the
1-millisecond budget, settling with a forced recount.

Slice-by-slice discoveries the audit banks: the sweep needs its own
partition table (absent-ever; the acyclic table provably double-counts
or leaves holes across rounds); reseeded rows self-exclude from
anti-delta reads via the delta index; corpse exclusion by ordinal is the
discipline negated probes must mirror; and three latent defects found
and fixed by the campaign — the slice-1/2 mixed-negation admission hole,
the maintenance x body-constant hang present since M1 (with the
flavor-ABI plan-keying gap it exposed), and the slice-4 fuzzer's
**expired-witness catch**: absent-ever's loss witness read the staged
delta indices, but the retained delta witness lives only one round (the
join-tomb lesson) while corpse-driven probes fire in ANY later round —
a lost premise plus a lost blocker in one sweep flush produced a phantom
decrement (loud underflow on dead heads; silent count corruption on
heads surviving via other derivations).  The witness is now a bind-time
snapshot of the epoch's negative journal (round-stable by the epoch
lifecycle; edit-sized by admission), pinned by `m4n-lostwitness-*` and
seed 7108 of the negation fuzzer.

## Migration and compatibility

- Existing recipes using relation names and version ordinals remain readable.
  During replay, resolve them to VersionKeys using the original recipe and
  persist VersionKeys only in newly written layers.
- Do not rewrite ancestor layers merely to assign new identifiers. The first
  new-format descendant stores a compatibility map from each canonical legacy
  DAG node/path and recipe event to allocated Layer/Event/Slot IDs. Expected
  legacy stamps validate the mapping but do not define it: an in-place history
  edit must make descendants stale without silently changing identity. Detect
  ambiguous paths and collisions, and never derive a new-format LayerId from
  a digest that includes the ID.
- Counts, count epochs, live struct membership, and compiler plan identity do
  not enter the on-disk compatibility contract.
- A rename is an aliasing event, not a new version. A drop is a severance, not
  deletion of historical versions. A later declaration under the same name
  starts a fresh version chain.

## Decision log

- The target least-fixpoint oracle uses an alpha-renamed immutable version program;
  it is independent of runtime copying and recount machinery.
- VersionKeys identify logical pipeline slots, not presentation ordinals or
  content snapshots. Runtime VersionIds identify their materialization within
  one recipe evaluation.
- Inheritance contributes one nonrec foundation support per active tuple;
  inherited support can be masked locally without mutating the predecessor.
- Editing changes one VersionInstance overlay; injection creates a distinct
  successor VersionInstance. Historical injection is a recipe branch.
- Version identity and settled-state revision are separate. M1 implements the
  latter as an evaluation-local optimistic update epoch; it is not persistent
  descriptor identity.
- Counts are transactional, recomputable cache and never persistent truth.
- Capability-based fallback remains permanent, including after precise DRed
  ships.
- Existing Slog lattices (M6L) and a possible SQL aggregate feature (M6A) are
  separate milestones.
