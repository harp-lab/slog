# Incremental Slog implementation ledger

**Reviewed:** 2026-07-13 after M6L stratified-repair slices 1–2
**Normative design:** `docs/incremental.md`

This file records what the tree currently implements and where it differs
from the normative design. It is intentionally historical and operational.
If prose here conflicts with `incremental.md`, the latter defines the target
semantics and this file identifies migration work.

## Baseline

The implementation is green under the current regression gates:

- session workflow harness: 275/275;
- native count checks: 177/177;
- quick harness: unit 137/137, diagnostics 14/14, stats, arena, sequence, and
  counts all pass;
- focused incremental stress: M3 and M6L signed-stream oracles pass with 1,
  2, and 8 workers; the M3 product and M6L replacement workloads survive
  forced pause/resume; the M6L 240-key report measured 118.692 ms cold versus
  69.882 ms warm (0.5888), with 479 contributor rows; and
- all modified Racket modules compile with `raco make`.

These tests satisfy the M0.4, M1, M3, and first two M6L exit audits described
below. They establish count reconstruction, version/input semantics, precise
signed support maintenance, and stratified lattice replacement propagation on
their certified surfaces.

## Resume point

Begin a future incremental-maintenance review with this ledger, then read the
M4T milestone and §4.5–§4.7 in `docs/incremental.md`. The narrower
`docs/m6l-contract.md` records the completed lattice admission boundary; it is
not the next implementation queue.

The next milestone is **M4T, recursive deletion for positive plain tables**.
Its first reviewable vertical slice should:

1. pin a focused M4T contract and failing fixtures for an unfounded symmetric
   cycle and an over-deleted-but-refounded diamond;
2. admit only counted, positive-arity, positive-only recursive plain-table
   SCCs reached by a tip-local direct edit, retaining clear-and-rerun for
   structs, lattices, negation, inheritance, and historical edits;
3. add a VersionId-local candidate set, negative-round removal, a foundation
   barrier, reseed, and the existing counted positive rebuild;
4. compare every settled result and sidecar with a fresh recomputation, then
   add multi-worker and forced-pause coverage; and
5. expand admission only after the narrow route is independently certified.

The handoff gates are `tests/run-all.sh --quick`, `tests/run-all.sh session`,
and `tests/run-all.sh incremental-stress`. The complete orchestrator remains
the arc-end gate.

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
  `tests/api/lattice-stream-fuzz.rkt`, `tests/incremental-stress.sh`, and
  `tests/counts-tests.cpp` — present regression coverage.

## Known limitations and deviations

These remain explicit capability boundaries or future correctness work.

1. **Struct identity and liveness remain coupled.** The struct master index is
   both the content-to-ID intern dictionary and live relational membership.
   Struct counts are diagnostic only until M5 separates tombstoned identity
   from join-visible membership.
2. **Recursive signed deletion is not enabled.** M3 handles acyclic table
   cones. Recursive SCCs still require M4T's candidate over-deletion,
   foundation barrier, reseed, and positive rebuild; pure proof counting would
   retain unfounded cycles.
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
inputs, compares every input and derived relation with a fresh unseeded
session, and forces recounts to compare derived support rows after each flush.
The M3 surface is therefore closed. M6L stratified repair now builds on it;
M4T remains the separate recursive plain-table deletion milestone.

## M6L slices 1–2 audit — implemented

The deterministic fixture covers a losing contributor, winning regression,
final-key removal, duplicate support, a mixed negative/positive flush, and a
forced contributor recount. The stratified fixture additionally proves a
mixed update publishes no intermediate payload, maintains its downstream
table, and reproduces both sidecars under forced recount. Randomized streams
compare every flush with a fresh unseeded clear-and-rerun session under one,
two, and eight workers; forced pause/resume and cold-versus-warm contributor
reporting are separate gates. A recursive-consumer fixture remains on the
named fallback route.

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
