# M5 struct identity contract

**Status:** implemented (slice 1, 2026-07-14). `incremental.md` §7 (and
the M5/M4S milestone entries) remains normative; this file pins the
identity invariant, the storage split, and the operation-by-operation
dictionary discipline that separates struct intern identity from live
membership without weakening fallback. The convention follows
`m4t-contract.md` and `m6l-contract.md`: everything not explicitly
admitted keeps its current behavior, and struct relations stay outside
every precise deletion route until M4S flips them in against this
contract. As built: the tombstone store and verbs live in
`daemon/database.h` (Relation), resurrection in
`daemon/operators.h` (`InternStructTask`) and the import path's
`internStructTuple`; `tests/struct-identity-tests.cpp` (the `structid`
quick-gate target) and the `m5-ids-*` block in `tests/session-tests.sh`
(via the `dump-ids` action) are the exit fixtures.

## The coupling being separated

A struct relation's master ordering (content columns first, id column
last — `Relation::getMasterIndex`) is today both:

1. the content-to-ID intern dictionary — `InternStructTask` dedups a
   candidate row by `lower_bound` over the master's content prefix and
   allocates `struct_encode(type, (alloc << bucket_bits) | bucket)` from
   the per-bucket allocator on a miss; and
2. live relational membership — the same B-tree (with the id-led lookup
   ordering and any requisitioned secondaries) is what joins read.

Removing a dead struct row from the live indices therefore forgets its
identity: re-derivation would remint a fresh id (allocators are monotone
and never reused), and every embedded referent of the old id — including
rows a predecessor version still holds, and direct assertions restored by
`rematerializeInputBaseline` — silently dangles. `daemon/daemon.h`'s
`clearRelation` documents exactly this as the current clear-and-rerun
policy ("cleared struct relations re-mint ids on re-derivation"), which is
tolerable only because the rerun clears the complete downstream cone;
input rows that embed struct ids already sit outside that tolerance.

## Identity invariant

For one evaluation's id space (shared across the versions of a chain —
allocators are carried by `copyInternAllocatorsFrom`):

> Per struct relation version, content-to-ID is a partial function,
> independent of liveness: at most one id maps any content, an id is
> never reassigned to different content, the same content is never given
> a second id while the dictionary retains its first, and ids are never
> recycled online.

Reminting is admissible only when every referent is simultaneously
rebuilt under the same operation: flat freeze/compaction (normative
§0.10) and the id-space-severing loads below. The invariant makes struct
count sidecar keys (`the id column alone`, §6.1) stable across any
future delete/reseed/relearn cycle — that stability is the entire point:
M4S's sweep folds signed support by id, and a reminted id would orphan
the sidecar entry and break the cancelling cascade.

## Storage split

**Dictionary = live master ∪ tombstone store.** The live master ordering
remains the authority for LIVE content-to-ID mappings, unchanged in
layout and cost. A new per-bucket tombstone store (bucketed by
`buckethash` of the master's leading content column, exactly like the
intern allocators, so `InternStructTask`'s per-bucket exclusivity is
preserved) maps the content-column key of each DEAD row to its retained
id word. The two are disjoint by construction: installing a tombstone
removes the live row; resurrecting removes the tombstone. Content
simultaneously live and tombstoned — or tombstoned with an id different
from a live occurrence — is identity drift and fails loudly.

Forward-only evaluations never materialize a tombstone; the store costs
nothing until something dies.

**Membership authority is unchanged:** live master and secondary indices
define join-visible membership, coverage audits, and
`hasLiveCountKey`. A tombstone is not live: it is invisible to every
join view, every dump, every save of set content, and the §4.2 rule-7
audit ("the struct tombstone rule": a tombstoned id must have no live
row and — outside a DRed epoch — no sidecar entry).

## Operation discipline

- **Intern (`InternStructTask`):** dup-check the live master first (the
  hot path is unchanged); on a miss, consult the bucket's tombstones. A
  tombstone hit is a **resurrection**: write the retained id into the
  batch, erase the tombstone, insert into the master — from there the row
  is an ordinary first-derivation delta row (exactly-once staging,
  downstream flow, and count contributions identical to a fresh insert).
  Only a miss in both allocates a fresh id.
- **Point removal (`tombstoneStructRow`, new):** remove the row from
  every registered non-seeded ordering — master, lookup, and secondaries,
  honoring M4T's all-orderings lesson — and install the content→id
  tombstone. This verb is the struct analog of
  `removeTupleAllIndicesPreservingCounts` and is what M4S's sweep,
  foundation-aware overlay, and dead-candidate discard will call; sidecar
  retention follows the flavor's fold policy, not this verb.
- **Verbatim ingestion (`insertTupleAllIndices` on a struct relation):**
  rows arriving with ids already assigned (version re-copy, anchored
  `refreshVersion`, replay reload) must reconcile: no tombstone — insert;
  tombstone with the same id — resurrection by copy (erase and insert);
  tombstone with a different id — identity drift, fatal. This turns the
  previously silent cross-version remint hazard into an audit.
- **Re-derivation clears (`clear-rel`, `clear-rel-at`,
  `refreshVersion`):** clearing a struct relation converts every live
  master row into a tombstone instead of forgetting it (dictionary
  content survives; membership empties). The rerun's re-derivations then
  resurrect their original ids, making fallback clear-and-rerun
  **id-stable**: saves, goldens, cross-version diffs, and — critically —
  direct assertions and inherited rows that embed struct ids remain valid
  across the rerun. This deliberately replaces the documented remint
  policy in `clearRelation`; update that comment with the implementation.
- **Id-space-severing clears (`loadRelation` refresh-from-disk, database
  merge/import, freeze):** these replace the id space wholesale (disk ids
  arrive verbatim; merge remaps through the four-id-space memo). They
  drop tombstones before ingesting — retaining them would let an
  unrelated database's content collide with a stale mapping and break the
  function property. A load is a severance, not a deletion.
- **Version copy (segment boundary):** a written struct relation's copy
  carries live contents (as today), the tombstone store, and the
  allocators. The dictionary is version state; dropping tombstones at a
  boundary would remint across versions of one chain.

## Persistence (resolved by M4S slice 3, 2026-07-17)

The slice-1 limitation is retired. M4S pinned the policy
(`docs/m4s-contract.md` "the chain is the sidecar"): tombstones never
persist — saves write live set content verbatim, unchanged — and a load
reconstructs each struct version's dead half from the chain itself
(recipe replay re-runs the same clears and re-derivations, and
`Database::reconstructStructTombstones` closes the invariant with
`dict(v) = (live(pred) ∪ dict(pred)) − live(v)` independent of each
step's route). Content dead in every loaded version has no referent
anywhere in the load (the settlement invariant), so its missing mapping
is unobservable. Tombstone counts are not preserved across the boundary;
fixtures compare live id sets and embedded-id validity only.

## What M4S buys with this

The M4T candidate lifecycle transfers verb-for-verb: over-delete on
foundation loss = `tombstoneStructRow` (sidecar entry retained while
support remains, keyed by the now-stable id); dead-candidate absorption =
tombstoned id with a retained sidecar entry; reseed = resurrection of the
journaled survivors; relearn = the intern path's ordinary resurrection.
No struct row is join-visible while dead, and every reappearance —
reseed, relearn, later re-derivation, or verbatim re-copy — reuses the
original id (`incremental.md` M5 exit). M4S remains a separate milestone:
route admission, journal integration, and the struct `_maint4neg`
artifacts are out of scope here.

## Slice 1 exit criteria

1. **Unit battery (daemon):** resurrection reuses the original id; fresh
   content after a tombstone allocates above it (no recycle); a
   tombstoned row is absent from master, lookup, and every secondary
   ordering; verbatim re-insert with a mismatched id fatals; clear-to-
   tombstone plus re-derivation round-trips the dictionary.
2. **Session fixture:** a cone containing a struct relation, edited so it
   routes to clear-and-rerun, settles with the SAME struct ids before and
   after the rerun (observable via dumped embedded ids), including a
   direct assertion embedding a struct id that survives the rerun intact.
   Fresh-run goldens are unchanged (forward-only runs never tombstone).

   *Closed 2026-07-15 (`m5-keep-*` in `tests/session-tests.sh`), and the
   embedded-id leg found a real hole: `importDatabaseBIN` recorded a
   direct-input payload's table rows in the input ledger but not its
   struct heap, so after a clear-and-rerun the restored table row's
   embedded id stayed tombstoned and silently decoded as garbage
   (`(pair 0.0 0.0)`) — `reconcileTombstone` audits only the struct
   relation itself, never ids embedded in plain rows. Fix: a direct-input
   import records each materialized struct instance as direct input
   exactly like its table rows, and the flat-open `markLatestRelationsDirect`
   drops the same pre-M5 struct exclusion — both restores now ride the
   baseline's verbatim re-insert, which reconciles the tombstone and
   fatals on drift. The exclusions were pre-M5 fossils: verbatim baseline
   restore of struct rows was only made sound by this contract.
3. **No admission change:** struct cones still route to clear-and-rerun
   (`(reason struct-diagnostic)` capability lines unchanged); struct
   counts remain diagnostic-only.
4. The quick, session, and incremental-stress gates stay green.
