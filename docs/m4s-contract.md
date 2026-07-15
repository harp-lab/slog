# M4S recursive struct deletion contract

**Status:** design contract (2026-07-15); not yet implemented.
`incremental.md` §7 (M5-then-M4S) and §4.5–§4.7 remain normative; this
file pins admission, the struct verb mapping, the embedded-id settlement
invariant, and the tombstone persistence policy. The convention follows
`m4t-contract.md` and `m5-contract.md`: everything not explicitly
admitted keeps clear-and-rerun, and fallback is never weakened.

M4S rides two substrates verbatim and adds no new phase machinery:

- **M4T** owns rounds, journals, the candidate lifecycle, the
  foundation barrier, reseed, and the positive rebuild (`_maint1` /
  `_maint3neg` / `_maint4neg`, `dred-reseed`); and
- **M5** owns identity: the tombstone dictionary, `tombstoneStructRow`,
  intern/import resurrection, verbatim reconciliation with drift fatals,
  and id-stable clears.

One prerequisite already landed (2026-07-15, with the `m5-keep-*`
fixture): direct-input imports and flat opens record the payload's
**struct heap** in the input ledger exactly like table rows, so
`rematerializeInputBaseline` restores struct rows nothing re-derives.
Without that, the settlement invariant below is false before M4S even
starts.

## What M4S admits

Struct relations become admissible **interior cone members** on all
three counted maintenance routes — M1 positive, M3 acyclic negative,
M4T recursive sweep — as rule heads (`mkstruct`) and body occurrences,
in acyclic and recursive strata alike. Struct support counts flip from
diagnostic to load-bearing on admitted routes; the
`(reason struct-diagnostic)` capability exclusion disappears for cones
this contract covers.

Still refused by name:

- an **edited relation that is itself a struct relation** (direct
  struct-row edits are inexpressible inline and their overlay semantics
  are deferred; import-delta remains the vehicle for struct-embedding
  input, and it creates versions, not overlay edits);
- lattices anywhere in the cone (M6L/M7), negation edges (M4N), nullary
  relations, diagnostic/fallible heads, unsupported side-channel kinds;
- mid-cone version edges (rebound guard → anchored walk) and
  historical/back-anchored edits (anchored walk, permanently);
- uncounted or capability-uncertified cones.

## Verb mapping: the M4T lifecycle over M5 verbs

The candidate lifecycle transfers verb-for-verb; the fold policy is
M4T's, only the physical mutation verbs change:

| lifecycle step | plain table (M4T) | struct relation (M4S) |
|---|---|---|
| over-delete on foundation loss | `removeTupleAllIndicesPreservingCounts` | `tombstoneStructRow` (all non-seeded orderings; mapping retained) |
| dead-candidate absorption | absent row + retained sidecar entry | tombstoned id + retained sidecar entry (fold by id; no re-staging) |
| reseed of a surviving candidate | verbatim reinsert, journal +1 | same insert — `reconcileTombstone` consumes the mapping, id unchanged |
| relearn during rebuild | ordinary M1 insert of an absent head | intern-path resurrection (`takeTombstone`): same id, ordinary delta row |
| discard at `rec = 0` | row absent, sidecar key erased | row stays **tombstoned** (identity retained), sidecar key erased |

Two consequences worth stating:

1. **Sidecar keys are stable by construction.** Struct count sidecars
   key on the id column alone (`incremental.md` §6.1); the M5 identity
   invariant makes that key survive any delete/reseed/relearn cycle, so
   the cancelling cascade (a row reaching downstream in both journals)
   folds against one key. A reminted id would orphan the entry — that
   failure mode is exactly what M5 exists to remove.
2. **M5's rule-7 audit is epoch-scoped, as designed.** Inside a sweep
   epoch a tombstoned id may hold a sidecar entry (a dead candidate
   absorbing decrements); at settlement the audit shape is restored: a
   tombstoned id has no live row and no sidecar entry.

## Negative-phase `mkstruct` is probe-only

Maintenance flavors enumerate **lost** instantiations, whose head
content was necessarily interned when the instantiation originally
fired. A `mkstruct` in a negative-phase plan therefore resolves the id
by **probe only** — against the live master first, then the bucket's
tombstones (an earlier round may already have tombstoned the head; the
decrement must land on the retained id — dead-candidate absorption). A
probe miss in both is a fold error and invalidates the epoch: it means
the claimed instantiation could never have fired. Negative-phase
`mkstruct` never allocates and never resurrects.

The positive rebuild uses the ordinary intern path unchanged:
live-master dedup, tombstone resurrection, fresh allocation above the
monotone allocator — in that order.

## The embedded-id settlement invariant

This is the obligation M4T never had: struct ids flow as *values* into
other relations' rows, including values nested inside interned
collections and sequences.

> **At epoch settlement, every struct id embedded in any live row of
> any relation — at any nesting depth through interned values — maps to
> a live row of its struct relation.**

Why it holds on admitted routes:

1. **Constructor coupling.** An instantiation whose head constructs a
   struct row supports both the struct relation's row and the sibling
   head rows with the same multiplicity; they gain and lose support
   together.
2. **Pass-through foundedness.** An id bound from a body column occurs
   in a live founded row only if its derivation tree is founded; every
   binding of the id in that tree traces back to either a constructor
   instantiation (which supports the struct row, by 1) or an input row
   embedding the id (covered by 3). The sweep exists precisely to remove
   unfounded cycles, so settled-live implies founded.
3. **Input ledger coverage.** Direct assertions embedding ids — imports
   and flat opens — record the struct heap as direct input (the landed
   prerequisite), so the struct row holds input foundation whenever the
   embedding row does.

Mid-epoch violations are expected and permitted: update epochs are
deliberately inconsistent while phases run. Only settlement is audited.

**Audit:** a test-scoped walk (fixture harness, not production) decodes
every live row's embedded ids — descending through collection/sequence
arena values — and asserts each resolves to a live struct row.
Production keeps M5's cheap audits (drift fatals, rule-7 shape); the
full walk is too expensive to run outside fixtures.

## Journals and downstream staging

Struct journal rows are storage rows (id first, content columns after),
carried verbatim. Downstream strata stage struct DeltaMinus exactly as
tables stage theirs; body occurrences of struct relations probe by
whatever orderings the reading plans requisitioned, which the id-led and
content-led orderings already serve. Journal locking, the atomic
update-valid flag, and the negative-walk-before-reseed ordering are
M4T's, unchanged.

## Persistence policy: the chain is the sidecar

The M5-deferred decision, resolved: **tombstones never persist.** Saves
carry live set content verbatim, unchanged in format. Identity for dead
content across a save/load boundary is **reconstructed from the saved
chain itself**: for each struct relation version, walking root to tip,

```text
dict(v) = (live(pred(v)) ∪ dict(pred(v))) − live(v)
```

— content live in an ancestor but not in `v` is a tombstone of `v`,
with the ancestor's id. Reconstruction may be lazy (deferred until the
first epoch or clear touches the relation); that is implementation
freedom, not contract.

Why this is sound and complete:

- **Counts doctrine extended.** Counts are recomputable cache, never
  persistent truth; the dictionary's dead half is likewise derivable
  from persistent truth (the chain's live content), so persisting it
  would create a second source of the same fact.
- **Completeness.** By the settlement invariant, per version, no live
  row embeds an id that is dead in that version. Content dead in
  *every* saved version therefore has no referent anywhere in the save;
  losing its mapping is unobservable, and a post-load remint of that
  content cannot collide with anything. Single-version saves need no
  dictionary at all.
- **The collision hazard is exactly covered.** The dangerous case is
  content dead at tip but live in an ancestor: a post-load re-derivation
  that reminted would later collide with verbatim inheritance
  (`refreshVersion` copies ancestor rows with their ids — drift fatal).
  Chain reconstruction restores precisely those mappings, so
  re-derivation resurrects instead.
- **Severance rules unchanged.** `loadRelation` disk refresh, merge
  scratch teardown, and freeze still drop tombstones (M5); import remap
  still rebuilds ids through the four-id-space memo.

One observable consequence for tests: tombstone *counts* (`dump-ids`'s
second field) are not preserved across save/load — only mappings
derivable from the chain are. Fixtures compare live id sets and
embedded-id validity across the boundary, never tombstone counts.

## Slices

1. **Acyclic struct cones** — M1 positive and M3 negative admission with
   struct heads/bodies: probe-only negative `mkstruct`,
   `tombstoneStructRow` wiring in the maintenance sink, route admission
   for acyclic cones, embedded-id fixtures.
2. **Recursive sweep admission** — `_maint4neg` over SCCs containing
   struct relations: dead-candidate absorption by id, reseed/relearn
   resurrection, the foundation-aware overlay composing with struct
   heads (edits still target plain tables).
3. **Persistence** — chain reconstruction at load (or lazily), the
   save/load mid-stream fixtures, and the `m5-contract.md` persistence
   caveat retired.

Slice 3 is independent of 1–2 and may land in any order; note the gap it
closes already exists today (clear-and-rerun mints tombstones that
saves silently drop).

## Required fixtures

Deterministic, first landed asserting fallback + route reporting, then
flipped to the precise route:

- **struct diamond with tail** (`m4t_diamond` analog with a `pair`
  head): one foundation route deleted; the over-deleted struct row
  reseeds from surviving recursive support, the dependent row relearns —
  both under their **original ids** (`dump-ids` before/after equality),
  sidecars equal to forced fresh recount.
- **recursive construction self-join**: closure that constructs struct
  terms recursively; cutting the cycle over-deletes and reseeds
  constructed rows.
- **pass-through chain**: `(p P) --> (q (foo P))` — nested embedding
  across two struct relations; the settlement walk validates every
  embedded id after mixed deletions.
- **multi-constructor support**: identical content constructed by two
  rules; deleting one input is a support-only decrement (row stays
  live), deleting both tombstones it.
- **import-then-edit on the precise route**: the `m5-keep` shape over a
  counted admissible cone — maintained deletion (no rerun) keeps the
  imported row's embedded id valid, and the struct row's input
  foundation comes from the ledger.
- **mixed-sign epoch**: delete and re-add the same content in one flush;
  the id survives via within-epoch resurrection.
- **save/load mid-stream**: a maintained session saves after deletions;
  after reload, re-deriving chain-live dead content resurrects the
  ancestor id (chain reconstruction), fresh content mints above the
  allocators, and inherited verbatim copies reconcile without drift.
- **named fallback fixtures**: an edit targeting a struct relation
  (refused by name), lattice+struct cone, negation+struct cone.
- **randomized hardening**: extend `recursive-stream-fuzz` with a
  struct-headed rule and an embedded-id consumer; per-flush oracle
  comparison of content and sidecars against fresh recount sessions
  under one, two, and eight workers; within-session id stability checked
  via `dump-ids` across epochs; forced-pause epochs attributed to the
  sweep with struct candidates outstanding.

Every case compares settled content and every support component with a
fresh recomputation plus forced recount (§10's two oracles and the
cross-flavor check).

## Open implementation questions (pinned, not blocking)

1. The compiler shape of probe-only negative `mkstruct`: a plan
   attribute on the existing `mkstruct` op versus a distinct c-op; the
   flavored planners must also start *emitting* struct-headed rule plans
   for `_maint*` (they were never compiled for struct cones before).
2. Whether journal staging of struct DeltaMinus needs any additional
   index requisition beyond what reading plans already demand.
3. The lazy-versus-eager reconstruction default for slice 3, measured on
   a large loaded chain.
