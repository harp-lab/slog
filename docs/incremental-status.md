# Incremental Slog implementation ledger

**Reviewed:** 2026-07-12 at `cf01a3d`  
**Normative design:** `docs/incremental.md`

This file records what the tree currently implements and where it differs
from the normative design. It is intentionally historical and operational.
If prose here conflicts with `incremental.md`, the latter defines the target
semantics and this file identifies migration work.

## Baseline

The shipped session substrate is healthy under its current semantics:

- native/unit suite: 164/164 at the review point;
- session workflow harness: 157/157 at the review point; and
- the worktree may contain unrelated documentation edits, so these numbers
  describe the reviewed implementation baseline, not a clean-tree claim.

These tests establish that Phase 0 and the existing count-round substrate did
not regress. They do **not** establish the M0.4 version/provenance semantics or
precise deletion.

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
  lazily compiled `_delta` flavors with exact-once staging for the shipped
  single-hop set-semantics path. Multi-stratum counted chaining remains M1.
- **0.C — anchored batch actions:** inline and bin-backed batches,
  position-addressed queries, pipeline introspection, recipe logging, and
  payload placement are shipped.
- **0.D — rename/drop/link:** rename and drop are environment operations;
  flat hot-links and import maps are shipped. A chained hot-link is refused
  with a freeze-first diagnostic.
- **0.E — save/load/freeze:** recipe layers, replay through the live session
  machinery, downstream unseeded replay after mutable negative edits, flat
  freeze, and the workflow/fuzz harness are shipped.

### M0.1 through M0.3

- **M0.1:** packed `input | nonrec | rec` sidecar words exist for tables and
  structs, with checked arithmetic. Sidecars are not ordinary indices and do
  not persist.
- **M0.2:** lazily compiled `_count` flavors enumerate all-full rule plans,
  including wide temp paths and deterministic error emissions. Lattice writes
  and nullary counted heads are excluded.
- **M0.3:** `session-recount!`, count invalidation, per-binding counted flags,
  positional/cone walks, lazy skipping, and count dumps are shipped.

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
  `compiler/emit-cpp.rkt` — count/delta flavors;
- `daemon/database.h`, `daemon/operators.h`, `daemon/counts.h` — version
  bindings, sidecars, and count tasks; and
- `tests/session-tests.sh`, `tests/api/stream-fuzz.rkt`,
  `tests/counts-tests.cpp` — present regression coverage.

## Known deviations from the normative plan

These are correctness work, not optional cleanup.

1. **No explicit version identity.** Runtime identity is a `Relation*` plus a
   name/position binding. Saved anchors are name/version-ordinal recipes.
   There is no daemon `VersionId`, persistent `VersionKey`, immutable LayerId,
   recipe EvaluationId, or creation-event identity.
2. **Writer provenance is incomplete.** A relation version does not own an
   exact list of the stratum instances that wrote it. Driver metadata groups
   strata by names and positions, which is not robust to aliases, severance,
   repeated program instances, or compiler regrouping.
3. **Recount binds the wrong semantic environment.** A tip recount runs all
   selected historical strata against the tip environment; `#:at P` binds
   all selected strata at P. The target design binds every stratum instance at
   its original environment and credits only the VersionIds it actually
   wrote.
4. **A current test encodes duplicate historical support.** The M0.3
   multi-segment count case expects a tip tuple to receive contributions from
   both historical copies of a rule, even where the earlier writer could not
   see a later input. Replace this with the version-barrier oracle before
   trusting counts for deletion.
5. **Semantic foundation is not represented.** The count word's input bit is
   being used as both provenance and cache. There is no authoritative ledger
   for direct assertions, active inheritance, inheritance masks, root/import/
   link origin, and version creation.
6. **Ground program facts are misclassified.** Count planning currently tags
   body-less rules as `input`. They are non-recursive program derivations;
   changing or removing them is a program/recipe update, not an input edit.
7. **Same-point signed collapse is baseline-blind.** `log-applied!` cancels an
   opposite sign without consulting direct or inherited support. Starting
   from inherited `T`, `+T` then `-T` can disappear from the saved recipe even
   though the final meaning should contain an inheritance mask.
8. **Count walks are not transactional.** `mark-counted` can discard some
   partial sidecars, but there is no private epoch, mutation barrier, complete
   live-tuple coverage audit, or atomic commit of a version cone.
9. **Precise negation maintenance is absent.** Current absent probes implement
   set construction. A sign flip is not a negative-delta implementation;
   M4N needs dedicated anti-delta variants and transition scheduling.
10. **Struct identity and liveness are coupled.** The struct master index is
    both the content-to-ID intern dictionary and live relational membership.
    Recursive deletion needs tombstoned identity separate from join-visible
    membership, so M5 precedes M4S.
11. **Signed counted transport is incomplete.** `_delta` does not yet carry
    the M1 support-kind/sign contract through every temp and sink, and the
    exact positive/negative occurrence partitions have not been audited.
12. **Nullary counted heads and chained hot-links remain explicit refusals.**
    They must stay on fallback/refusal paths until implemented; neither may
    silently become “counted.”
13. **Struct recount is not deletion certification.** Count tasks can produce
    struct sidecars, but current master storage cannot distinguish a live
    relational row from an intern tombstone. Struct versions stay outside the
    precise-deletion capability set until M5.
14. **Count arithmetic currently terminates the daemon.** Packed counter
    under/overflow is fatal. The target behavior is a loud count invalidation
    followed by semantic set rebuild; saturation is never correct.

## M0.4 blocking gate

M0.4 is the next milestone. It is split into four reviewable gates; do not
begin M1 precise maintenance until all four exit:

1. **M0.4a — identity/topology:** descriptors, instances, Layer/Event/Slot/
   Version IDs, original stratum bindings, exact writer sets, and VersionId-
   keyed state.
2. **M0.4b — semantic input ledger:** baseline-aware direct assertions and
   inheritance masks, proper root/import/link support, and ground facts as
   nonrec program support.
3. **M0.4c — recount:** explicit VersionId targets, original-environment
   writer enumeration, foundation seeding, private epochs, coverage/closure/
   drift audits, failure retry, and explicit capability exclusions.
4. **M0.4d — persistence/oracle:** META/recipe migration, legacy anchor
   replay, branch isolation, save/load/freeze round trips, and per-version
   comparison with a slow operational-IR enumerator over the desugared
   from-scratch materialization.

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

- The least-fixpoint oracle uses an alpha-renamed immutable version program;
  it is independent of runtime copying and recount machinery.
- VersionKeys identify logical pipeline slots, not presentation ordinals or
  content snapshots. Runtime VersionIds identify their materialization within
  one recipe evaluation.
- Inheritance contributes one nonrec foundation support per active tuple;
  inherited support can be masked locally without mutating the predecessor.
- Counts are transactional, recomputable cache and never persistent truth.
- Capability-based fallback remains permanent, including after precise DRed
  ships.
- Existing Slog lattices (M6L) and a possible SQL aggregate feature (M6A) are
  separate milestones.
