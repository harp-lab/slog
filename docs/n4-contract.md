# N4 contract: durable boundaries and namespace attachment

**Status 2026-07-27: N4 is complete.** Both slices are as-built and gated.
N4-A's durable bundle, format cut, save, restore-on-open, replay audit, and
boundary-backed REPL projection are in `compiler/catalog.rkt`,
`compiler/dbmeta.rkt`, `compiler/session.rkt`, and `compiler/repl.rkt` (§4.1);
N4-B's attachment planner, driver, and `attach DB [SOURCE] as DEST` command
are in the same modules (§5.1). The one deliberate deviation from the written
work orders is recorded in §4.1: the bundle field is optional at the format
level, because work order 3's own escape hatch has to be representable.

2026-07-26. **Design pinned.** N4 is exactly
two implementation slices. N0-N3 already provide the in-memory QName,
catalog, transactional-boundary, history, and TypeKey/SID substrate; N1 adds
module occurrences and bindings. N4 makes that state self-describing on disk,
consumable by the existing REPL, and attachable as one checked namespace.

N4 does not add a runtime module object, privacy or export lists, type
parameters, live cross-database aliases, lifecycle watches, or a second REPL.

## 1. Why two slices are enough

The remaining work has one clean audit boundary:

1. **N4-A — durable boundary bundle and catalog-backed REPL.** Saving and
   opening the same database lineage preserves its logical catalog and stable
   keys without rediscovering schema from tuple directories or source text.
   The existing REPL consumes that structured boundary data.
2. **N4-B — mapped namespace attachment.** A saved root or dependency-closed
   subtree is imported under one destination prefix through a complete,
   atomic QName/VersionKey/TypeKey plan.

N4-A is read/restore work: it must not invent cross-database identity rules.
N4-B is generative mutation: it must not invent another persistence format.
This separation gives each slice a useful exit and lets attachment depend on a
proven durable bundle. One slice would mix format correctness with the more
dangerous cross-database mutation path; more than two would mostly split
codec, daemon, and REPL plumbing that cannot be tested meaningfully alone.

The numbered work orders inside each slice are implementation steps, not
additional slices.

## 2. As-built substrate N4 must reuse

N4 starts from these shipped contracts:

- `compiler/names.rkt` is the QName component authority. Persistence stores
  components; no N4 reader infers identity by splitting a dotted display
  string.
- `compiler/catalog.rkt` owns `DeclarationDescriptor`, `Catalog`,
  `Boundary`, `BoundaryPlan`, path transforms, and compatibility checks.
- N3 prepare/commit/abort owns atomic publication, eager empty relation slots,
  VersionKey indexing, committed boundary history, and the TypeKey/SID
  registry.
- N1 recipes already retain `ProgramInstanceKey`, `ModuleInstanceKey`, homes,
  lexical occurrence paths, and formal-to-actual bindings.
- `compiler/session.rkt` already has a logical boundary head and ordered
  boundary plans. The daemon catalog supplies materialization facts; it is not
  a replacement source-level type graph.
- `compiler/repl.rkt` and `repl/` already provide the interactive server,
  client, canvas, structured result transport, and command-completion reducer.
  N4 adds a catalog adapter to them; `compiler/run.rkt` is not a new REPL
  implementation target.

No second declaration codec, compatibility checker, boundary transaction, or
terminal state model is permitted.

## 3. The durable boundary bundle

N4-A bumps the database format and places one canonical
`boundary-bundle` value directly in `META`. A separate `CATALOG` file is not
part of N4. `META` is already atomically written, version-gated, stable-order,
human-readable, and included in the database stamp; keeping one atomic
metadata object avoids a two-file commit protocol.

Conceptually the bundle contains:

```text
BoundaryBundle {
  bundle_format
  selected_head: Boundary
  boundary_history: BoundaryRecord*
  versions: VersionRecord*
  types: TypeRecord*
  programs: ProgramRecord*
}
```

The records carry:

- the selected `BoundaryKey`, complete normalized declarations,
  memberships, nominal QName-to-TypeKey map, and QName-to-VersionKey
  environment;
- ordered committed boundary records and their predecessor/delta or transform
  information;
- VersionKey, predecessor VersionKey, storage kind, qualified name at the
  selected boundary, and materialization availability;
- TypeKey, stored arity, saved SID encoding, and current or historical
  constructor names;
- ProgramInstanceKeys, input/output BoundaryKeys, and the associated
  ModuleInstanceKeys, homes, lexical paths, and bindings.

The selected head is a complete snapshot, not a recipe that must be replayed
to discover the current schema. History may be stored as validated transition
records rather than repeated full catalog snapshots. A historical handle is
queryable only when its materialization was loaded or replayed; metadata-only
history is displayed as such, never silently rebound to the latest relation.

Root open/replay preserves BoundaryKeys, VersionKeys, TypeKeys,
ProgramInstanceKeys, and ModuleInstanceKeys. Runtime SIDs may change, so the
loader builds an explicit saved-SID-to-live-SID map. `EvaluationId` remains
runtime-local: an opened boundary handle is `(new EvaluationId,
persisted BoundaryKey)`.

## 4. N4-A — durable boundary bundle and catalog-backed REPL

### Outcome

A saved database is self-describing before any source is recompiled or tuple
directory is scanned. Empty declarations, qualified field graphs, nominal
types, module metadata, and stable keys survive save/open and compressed
replay. The existing REPL can browse and complete against the selected
logical boundary rather than a name/size approximation.

### Work order

1. **One canonical codec.** Add complete catalog/boundary/bundle
   datum codecs and validators in `compiler/catalog.rkt`. Reuse the existing
   TypeRef, lattice, declaration, BoundaryPlan, transform, and module-instance
   codecs. `compiler/dbmeta.rkt` owns placement and format gating only.
2. **One format cut.** Bump `slog-db-format-version`; add the
   `boundary-bundle` META field and include it in normal stamp validation.
   New saves always write it. A malformed, internally inconsistent, or
   unsupported bundle fails before daemon mutation.
3. **Save a committed snapshot.** `session-save!`, one-shot saves, freeze,
   and any direct database-creation/import tool capture the selected public
   boundary, boundary history, version/type descriptors, and program/module
   records. A creator that cannot supply exact declaration metadata does not
   emit an N4 database. Saving while a prepared boundary is leased is
   refused.
4. **Restore schema before rows.** Open reads and validates the bundle first,
   installs every logical storage declaration through the N3 boundary/type
   machinery, establishes the saved-TypeKey-to-live-SID map, and only then
   loads tuple/interner materialization. Relation directories may still omit
   empty members.
5. **Audit replay rather than trust it.** Compressed recipe replay rebuilds
   its normal boundary chain, then compares the reconstructed selected head
   and stable-key records with the stored bundle. Source drift or recipe/key
   divergence is a load failure, not a reason to replace the bundle silently.
6. **Publish one structured REPL projection.** Replace
   `compiler/repl.rkt`'s live catalog/schema join with a projection of the
   session's selected logical boundary plus daemon size/materialization
   observations. Add structured boundary history, module/program records,
   bindings, version chains, and type records. Feed relation and namespace
   paths into the existing Rust completion inventory.
7. **Finish the transition.** The N2-B catalog-less adoption bridge is not a
   permanent N4 mode. During migration an old database may be replayed and
   re-saved when its recipe reconstructs an exact catalog; a pure legacy root
   without exact declaration metadata must be regenerated. N4 catalog,
   attach, and REPL identity operations refuse a catalog-less input loudly.

### 4.1 As-built (2026-07-26) and the residue

**Landed (work orders 1-3).**

- `compiler/catalog.rkt` owns the whole codec: `boundary->datum` /
  `datum->boundary` plus `BoundaryRecord`, `VersionRecord`, `TypeRecord`,
  `ProgramRecord`, and `BoundaryBundle` with `validate-boundary-bundle`.
  History records reuse the shipped BoundaryPlan and transform-plan codecs
  verbatim; module records reuse the N1 module-instance codec. No second
  declaration codec exists.
- `compiler/dbmeta.rkt` owns placement and gating only:
  `slog-db-format-version` is 2, `boundary-bundle` is a META field, a present
  bundle must validate on both write and read, and the bundle is part of
  `compute-db-stamp`'s identity. Deliberate deviation from work order 2's
  "new saves always write it": the field is OPTIONAL at the format level,
  because work order 3's own escape hatch (a creator with no exact
  declaration metadata) has to be representable in a format-2 file. Work
  order 7's loud refusals, not a required field, are what keep a catalog-less
  database out of N4 operations.
- `compiler/session.rkt` accumulates the bundle from committed state rather
  than rediscovering it: one head-assignment point (`install-head!`), one
  history append per committed transition (program boundaries *and* N3-D
  transforms), program/module records per compiled group, a TypeKey-to-every-
  qualified-spelling map, and a prepared-boundary lease that `session-save!`
  refuses to save over. Materialization availability is "the daemon still
  binds this VersionKey", so superseded and dropped versions persist as
  metadata-only records. A save also fails loudly on a catalog-vs-ABI stored
  arity disagreement.
- A legacy environment event (import, link, inject) severs the committed
  chain. The bundle does not paper over that: the history RESTARTS at the
  re-adopted base, program records for the severed lineage are dropped, and a
  surviving successor's pre-restart predecessor VersionKey is closed with a
  metadata-only record so the link stays true without claiming more.
- A session with no exact head writes **no** bundle rather than guessing.

Measured today, and the reason work order 5's audit must compare the head and
stable keys rather than whole records: opening a bundle-carrying layer and
re-saving it reproduces an identical head BoundaryKey, catalog, VersionKey
environment, TypeKey set, and ProgramInstanceKey list -- the recipe replay
rebuilds the plans under their persisted LayerId and events. What does *not*
reproduce is the chain's BASE. `session-open!` clears the head, so the
replayed first program re-adopts through `legacy-planning-boundary` and the
saved bundle's `initial` record becomes a `legacy-b1:<EvaluationId>:<pos>`
key -- a runtime-scoped id in durable state, and a different `input` on the
program record. That is transitional: work order 4 restores the persisted
head on open, at which point the replay has a real base and the legacy
adoption drops out of this path entirely.

**Work order 3, other creators.** `session-save!` and `slog db freeze` both
emit bundles. Freeze reaches its catalog through the recipe-chain loader hook,
which now returns the loaded session's bundle, and cuts the history: a flat
root's bundle is its head restated as its own base, keeping every TypeRecord
because live rows still embed those SIDs. Two creators deliberately do NOT
emit one, and are refused by N4 operations rather than guessed at: the
one-shot driver (`slog PROG --out-db`) never runs the N3 boundary protocol --
it drives `begin-segment`, so it holds no BoundaryKey, VersionKey, or TypeKey
to persist -- and `csv2db` writes no managed META at all. Giving the one-shot
driver an exact bundle means routing it through the boundary planner, which is
a change to that driver, not to N4.

**Work orders 4-5, and the daemon change that turned out to be unnecessary.**
The obvious reading of "install every logical storage declaration" is to adopt
a verbatim-loaded environment, and that is *not* expressible today:
`loadDatabaseBIN` fatals on a pre-existing relation, and after it the
relations carry no VersionKey, which `prepareBoundary` rejects both ways
(`retain` demands a key match, an initial `create` demands the relation be
absent). It would need a new `adopt` action kind. The resolution is to not
do the verbatim load at all: `restore-database!` prepares the persisted head
as ordinary initial creates -- which the shipped admission rules already
accept for names the daemon does not hold -- imports the rows into that
boundary's private slots, and commits. Schema genuinely precedes rows, the
BoundaryKey/VersionKeys/TypeKeys are the persisted ones, and no daemon change
was required.

Which route a database takes follows from what it is, and the two are
complementary rather than alternatives:

- A **recipe layer** rebuilds its own boundary chain by replay, so the stored
  bundle is work order 5's *audit*: `audit-restored-bundle!` compares the
  reconstructed head, declaration graph, VersionKey environment, TypeKey
  registry, and program/module keys against it, and a mismatch fails the open.
- A **root with no recipe** (a frozen database) has nothing to reconstruct, so
  the bundle *is* the head. There the audit is vacuous by construction; what
  protects it is bundle validation, the stamp (which covers the bundle), and
  `restore-database!`'s refusal to admit a relation directory the catalog does
  not declare.

`restore-database!` reads the bundle through `database-boundary-bundle`, not
through `dbtool.rkt`'s `db-meta-of` -- that helper deliberately swallows a
malformed META and reports the database as unmanaged, which for the restore
path would silently degrade a corrupt bundle to a legacy load.

**Whether to restore depends only on the database, never on the plan it
appears in, and that is load-bearing.** A restore re-interns rows and gives
the base a logical head, so anything computed against that base -- a recipe
layer's persisted BoundaryPlans, a compressed layer's heap-trimmed kept
sample -- must see the same base when it was saved and when it is loaded.
Restore is deterministic (one fixed action order into a fresh daemon), so a
rule that is a function of the database alone is symmetric by construction.
A rule that also consulted the surrounding load plan -- "restore only a
standalone `(open DB)`, keep chains on the verbatim path" -- looks safer and
is not: it restores while saving a layer onto a frozen root and does not
while loading it back, and `replay-boundary-plan` then refuses the recipe it
just wrote. The `n4c-stacked-*` cases pin that round trip.

**Work order 6.** `live-catalog` now projects the session's selected boundary
-- declarations, qualified field graph, stored arity, VersionKey, and
BoundaryKey -- and asks the daemon only for row counts, the one thing the
boundary cannot know. A declared-but-empty relation therefore appears in
`tables`, which the old catalog/schema join could never show. The `catalog`
command adds the structured projection: committed boundary history, program
records with their module instances, homes, lexical paths and bindings,
version chains, and type records with every qualified spelling a TypeKey has
carried. `CompletionInventory` gained `relations` and `namespaces`, harvested
from those payloads, so relation arguments and `attach ... as` complete
against what the catalog declares.

**Work order 7.** `attach` and the REPL `catalog` command refuse a
catalog-less input loudly, and a corrupt bundle fails the open. The N2-B
adoption bridge remains only as the migration path the work order explicitly
allows: `legacy-live-catalog` still answers `tables` for an input no program
has re-declared, because that is a name/size observation rather than an
identity operation.

**Residue.** Two §5 refusals -- a corrupt nested value and an exhausted SID
space -- are proven only at the unit level, because provoking either through a
live daemon needs fault injection that does not exist. There is no executable
REPL transcript for `attach` or `catalog`; both are gated by Racket unit tests
over their projections plus the Rust completion cases.

### Gates

N4-A exits only when tests prove all of the following:

- a qualified bundle containing tables, lattices, structs, nested values, and
  at least one empty declaration round-trips through save/open;
- BoundaryKeys, VersionKeys, TypeKeys, program/module keys, homes, and
  bindings are equal after root open and compressed replay, while a forced SID
  reassignment still decodes every nested value correctly;
- an empty declaration is visible in the catalog and REPL completion before
  any tuple is loaded into it;
- rename/drop history retains old qualified spellings and TypeKeys, and an
  unnamed historical constructor renders through its TypeKey;
- relative lookup resolves against an explicitly selected boundary handle,
  absolute VersionKey lookup never falls forward to latest, and unavailable
  historical materialization refuses clearly;
- corrupt bundle, duplicate key, dangling TypeRef/membership, catalog-vs-BIN
  ABI mismatch, replay divergence, and missing required bundle all fail before
  public state changes; and
- unit, compiler, protocol, complete session, and Rust/Racket REPL gates remain
  green.

Suggested focused homes are `tests/unit/n4-bundle-tests.rkt`, an `n4a-*`
session block, protocol catalog/history cases, and an executable plain REPL
transcript with dotted completion and an empty member.

## 5. N4-B — mapped namespace attachment

### Outcome

One saved database root or dependency-closed namespace subtree can be attached
under one destination path. The entire schema and type map is checked before
content changes, and the result publishes as one ordinary N3 boundary.

The interactive spelling is:

```text
attach DB as DEST
attach DB SOURCE as DEST
```

The first form maps the saved root to `DEST`; the second selects `SOURCE.*`
and maps it to `DEST.*`. `SOURCE` and `DEST` are structured QName paths.
Multiple independent mappings use multiple attachment events; N4 does not add
an arbitrary many-prefix mapping language.

The canonical Racket API is `session-attach!`. The persisted recipe event
records the source database stamp and BoundaryKey, source/destination paths,
the destination BoundaryKey, and the exact VersionKey/TypeKey maps. Replay
reconstructs the plan and refuses divergence.

Existing `import-delta` remains a content-only bulk-input operation and
existing `link` remains a legacy database reference. Neither is silently
given schema-attachment semantics.

### Mapping rules

- Select every declaration and membership below `SOURCE`. The selection must
  be dependency-closed: a field TypeRef or membership edge that escapes the
  selected subtree makes the attachment refuse. Attaching the saved root is
  always closed.
- Substitute the source prefix with `DEST` component-wise and validate the
  complete resulting declaration graph against the selected destination
  boundary. Extra destination members are retained. Missing compatible
  members are added. Ordinary persisted declarations require exact
  compatibility; N1's directional formal `any` wildcard is not an attachment
  rule.
- A fresh destination relation receives a fresh destination VersionKey. An
  existing compatible relation receives a normal successor only when source
  content is imported into it. Empty compatible existing members are not
  advanced merely because they appeared in the source bundle.
- A fresh destination nominal receives a fresh destination TypeKey and live
  SID. A compatible already-existing destination nominal reuses its
  destination TypeKey/SID. Independent attachment never makes source and
  destination nominal identity equal merely because their shapes match.
- Build one explicit source-TypeKey/source-SID to
  destination-TypeKey/destination-SID map, then reuse the shipped transitive
  word remapper for structs and nested values.
- Attachment is additive data import. It does not delete destination rows or
  create a live alias to the source database.

### Work order

1. Read and validate the N4-A bundle, select the source subtree, close and
   rewrite its catalog, and produce a pure attachment plan without contacting
   the daemon.
2. Compare the rewritten graph with the destination boundary and allocate all
   declaration, VersionKey, TypeKey, and SID decisions up front.
3. Prepare one private N3 output boundary, restore missing empty members, and
   import/remap all source materialization into the private target slots.
   Commit only after the complete import succeeds; any schema, key, decoding,
   or content failure aborts without publishing a name, relation version, or
   catalog entry.
4. Record the self-auditing attachment plan in recipe and boundary metadata.
   Expose its source/destination and type/version maps through the structured
   history projection so the existing REPL can display and complete the new
   namespace.

### 5.1 As-built (2026-07-27)

- **The allocator is `plan-boundary`, unchanged.** Its shipped behaviour is
  already §5's mapping rules: an added declaration mints a fresh VersionKey,
  an existing one advances only when it is in the write set, an added struct
  mints a fresh TypeKey while an existing one keeps the destination's, and an
  overlapping declaration must be exactly equal or the plan refuses. N4-B
  therefore adds no second compatibility checker, key allocator, or codec --
  it only computes the selection, the rewrite, and the write set.
- **`plan-attachment` is pure.** It takes the source bundle, the destination
  boundary, and the set of source relations that actually carry rows; it
  touches neither daemon nor filesystem. Dependency closure, prefix
  substitution, leaf-vs-namespace shape, the VersionKey/TypeKey maps, and the
  import list are all decided before anything moves.
- **`session-attach!` publishes one N3 boundary.** Prepare, import into the
  prepared boundary's private slots, commit. `getRelation` resolves through
  the prepared overlay, so the shipped `importDatabaseBIN` -- which already
  maps struct type ids by relation name and rebuilds collections through the
  destination arena -- is the transitive word remapper §5 asks for. Any
  failure between prepare and commit aborts.
- **The recipe step is self-auditing.** `(attach DB <attachment-plan>)`
  carries the source stamp and BoundaryKey, both paths, and the exact
  VersionKey/TypeKey maps; replay recomputes the plan and refuses divergence
  in the source catalog, the destination boundary, or the source's content
  coverage. The attachment also enters the durable bundle's committed
  boundary history under a new `attachment` origin kind.

Two things the as-built path had to settle that §5 does not mention:

- **Builtin membership members do not move.** A catalog may carry a
  membership whose *member* is a primitive rather than a declaration
  (`cmap` in `coll`). Prefixing it would invent a declaration that exists on
  neither side, so only selected declarations are rewritten, and closure
  ignores endpoints that are not declarations at all. Without this even the
  saved root -- which §5 says is always closed -- would refuse.
- **Internal relations are never attached.** The `$seq_*`/`$sup_*` machinery
  is materialized on disk but carries no QName and is execution state, not
  schema. A root attach therefore stages a filtered payload holding only the
  selected relation directories plus the whole interner/heap, so the importer
  cannot create an unplanned relation at the destination. When the selection
  covers every relation directory, the source directory is used as-is.

The attachment is exposed through the structured history projection N4-A
work order 6 added: `catalog` reports it as a committed boundary in the
history, and the destination's relations and namespaces feed the REPL's
completion inventory. Remaining residue is listed at the end of §4.1.

### Gates

N4-B exits only when tests prove all of the following:

- attach a saved root at a fresh dotted destination and attach a nested,
  dependency-closed subtree at a differently named destination;
- attach a bundle with an empty member and no corresponding tuple directory;
- attach into a compatible partial destination, reuse its established
  TypeKeys, add missing declarations atomically, merge source rows, and retain
  destination-only members;
- attach the same source twice at two fresh destinations and prove distinct
  relation versions, TypeKeys/SIDs, and data isolation;
- remap structs nested through structs, sequences, sets, maps, and lattices;
- reject an escaping dependency, incompatible declaration, occupied leaf vs
  namespace, duplicate destination key, corrupt nested value, or exhausted SID
  space before any public mutation;
- attach from a compressed/chained saved database by selecting its materialized
  boundary, not by scanning only its final layer's directories;
- preserve the recorded mapping through save/replay, rename the attached
  namespace afterward, and keep old boundary handles and absolute VersionKeys
  truthful; and
- unit, compiler, protocol, complete session, import/remap, and Rust/Racket
  REPL gates remain green.

Suggested focused homes are `tests/unit/n4-attach-tests.rkt`, an `n4b-*`
session block with pre/post catalog snapshots, daemon protocol atomicity
cases, and one REPL transcript covering attach, completion, history, and
lookup.

## 6. Exit and explicit non-goals

N4 is complete when both slices pass their focused gates and the full
regression suites, new databases are self-describing, and no N4 operation
reconstructs logical schema from relation-directory names or the daemon's
flat codegen manifest.

Still deferred:

- privacy, export lists, capability ports, and type parameters;
- live mounts, aliases, copy-on-write database links, or cross-database query
  syntax;
- arbitrary multi-prefix attachment in one event;
- internal `$stat_*`/`$seq_*` namespace migration and lifecycle
  watch/breakpoint work owned by N5; and
- garbage collection of historical keys, types, or materializations.
