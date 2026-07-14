# Merging saved databases

*Design + IO-improvement plan for loading one database and merging a second into
it, then running further rules over the union. 2026-07-03.*

Status: **P1 core merge shipped 2026-07-06.** Online `import` remaps strings,
structs, bignums, and canonical collections, then unions tables and joins
lattice rows. P2 hardening and the offline merge command remain designs.
Sections 1–9 preserve the original plan; section 10 records what shipped and
where it differs.

---

## 1. Goal

Today the daemon can `open` exactly one stored database and run a program over
it (daemon.h `open` → `loadDatabaseBIN`). We want:

> `open dbA`, then **merge in** `dbB` (disjoint declarations, or overlapping /
> mergeable same-name relations), then run a further program over the union.

Overlapping relations should reconcile by meaning: tables **union**, lattice
relations **join per key**, struct instances **dedup by content**. Disjoint
declarations simply coexist. Also useful offline: `dbA + dbB → dbC` on disk.

## 2. Why this is hard: three database-local id spaces

Slog values are NaN-boxed `u64`s (`types.h`). Two of the tag classes carry ids
that are only meaningful *within the database that assigned them*, and both are
baked directly into every stored tuple word:

| Value class | Encodes | Assigned by | Portable across DBs? |
|---|---|---|---|
| `s32` / `float` | the value itself | — | **Yes** — self-encoding, pass through untouched |
| string (`is_str`) | 35-bit intern id | FNV low-21 bucket + collision **position** in bucket (`intern.h:95-142`) | **No** — order-dependent |
| struct (`is_struct`) | 14-bit **type** id (bits 51:38) + 38-bit **instance** id (low 5 = bucket, rest = per-bucket counter) | type = declaration-order counter (`addStruct`→`struct_id_max++`); instance = `intern_allocators[bucket]` in `InternStructTask` | **No** — both are per-DB sequences |
| collection node (`is_cnode`, intern tag 2 — NEW 2026-07-05, `daemon/arena.h`) | 35-bit intern id into the collection arena (`value.nodes/`) | content-hash low-26 bits + collision position, like strings | **No** — order-dependent; AND the node *contents* embed other id-space words |

> **Merge addendum required (2026-07-05):** collection nodes are a FOURTH
> database-local id space, and they are worse than strings in two ways the
> staged remap (§4.2) must handle: (a) node contents embed child-node,
> string, and struct words, so nodes must be remapped **children-first**
> like struct instances; (b) a Patricia trie's *shape is a function of its
> key words* — remapping leaf keys (string/struct ids from `dbB`) makes the
> field-wise-remapped tree non-canonical and structurally wrong for its new
> keys.  Field-wise remap is therefore UNSOUND for cnodes whose keys are
> interned words: the import pass must instead extract each trie's
> (remapped-key, remapped-value) entries and **rebuild the canonical trie
> via the arena kernels**.  Int/float-keyed tries (self-encoding keys) may
> ride the cheap path.  Lattice stage-4 ordering: remap+rebuild collections
> BEFORE any per-key lattice join whose payloads are tree ids.

> **Bignum addendum (2026-07-09, docs/primitives.md §14):** interned mpz
> bignums (intern tag 1, `value.mpz/`) are another content-addressed
> database-local id space — but a LEAF one like strings, not a rebuild one:
> only s32-range ints stay self-encoding, and an out-of-range int word
> re-interns by value into the destination (the `is_mpz` arm of
> `importDatabaseBIN`'s remap, next to the `is_mono_str` arm).  Already
> handled in the shipped import pass, alongside sequence-node rebuild.

So merging `dbB` into `dbA` means re-encoding, in *every* `dbB` tuple word:
its string ids, its struct type ids, and its struct instance ids — while ints
and floats ride through unchanged.

Two structural facts make this tractable and are the whole basis of the design:

1. **In the shipped flat format, relation name is the schema-reconciliation
   key.** It is not a timeless schema identity: the namespaced target gives
   names meaning at a pipeline boundary and records declaration, VersionKey,
   and TypeKey metadata separately (see [modules.md](modules.md)). Struct
   *type* ids are **not** baked into generated `.so`s — generated code resolves
   them by name at runtime
   (`InternStructTask: struct_id = rel->getStructId()`; declarations guarded
   `if (r==0)` in `emit-cpp.rkt` `add-write-task`). Type ids are an internal
   runtime detail; only the *name* is stable. So reconciliation is by name, and
   type-id remapping is a tiny name→id table.
2. **Struct instances are content-addressed and value words are self-typing.**
   `InternStructTask` already dedups instances by content on the master index
   (`operators.h:377-426`); rules emit a `0`-placeholder id and let the task
   assign it (`operators.h:189`). And `is_struct`/`is_str` let a rewrite pass
   decide per-word what to remap with no schema knowledge. So merge is
   fundamentally a **re-interning** problem: feed `dbB`'s content back through
   the interners and dedup/id-assignment fall out for free.

Struct instances form a **finite acyclic DAG** — a struct can only be built from
values that already exist, so children are interned before parents. That gives a
well-founded order for remapping.

## 3. Design space considered

Three independent designs were developed and adversarially critiqued.

**A / B — re-ingest + staged remap (recommended).** Reconcile relations by name;
recover `dbB`'s ids by replaying its content through a *fresh scratch* interner
(so its own ids reproduce exactly); build one `old-word → new-word` remap in
dependency order (strings → struct types → struct instances) reusing
`InternStructTask`/`InternTable` for content-dedup and fresh-id assignment; then
rewrite and ingest `dbB`'s table/lattice rows so union and per-key join come free
from the existing btree set / `BTreeMapIndex` join. **No on-disk format change.**
A and B are the same core algorithm; A loads the source into a throwaway scratch
`Database` (simpler, higher peak RAM ≈ dbA+dbB), B replays only a scratch string
table plus a `fieldtab` (leaner). **Recommendation: hybrid** — A's scratch-DB
source loader (free string-id reproduction + random-access-by-id via the lookup
index) with B's single explicit `old→new` memo.

**C — content-addressed "north star" (deferred).** Make instance ids a strong
hash of transitive content and string collision-order content-sorted, so merge
becomes near-trivial union with automatic dedup. Elegant, but: it mandates a
**format-version bump + full golden re-baseline + lockstep `tools.rkt` change**;
the 35-bit string / 33-bit instance-body budgets **cannot be collision-free**
(birthday walls at ~185k strings, a few million structs), so collision
arbitration re-introduces exactly the order-dependence it set out to remove; and
it is **wrong** that lattice payloads are never ids (a `flat str`/`flat any`
lattice value *is* a string/struct id — `lattice-check.rkt:71`, `types.h:88`).
Keep C's one durable win (order-independent ids for canonical N-way/offline
merges) as a **future** option, revisited only if reproducibility demands it.

## 4. Recommended design in detail

### 4.1 Schema reconciliation (up-front, before any value is touched)

Walk `dbB`'s relation directories. Parse each (see robust parsing in §6) into
`(name, category, arity, [struct-id | lattice-spec])`, where category is `table`
/ `struct` / `lattice`. For each, match `dbA`'s relation *of the same name*:

- **absent in dbA** → create it: `addRelation` / `addStruct` /
  `addStruct`+`setLatticeFromSpec`, at `dbB`'s arity + lattice spec.
- **present** → validate: category must match (table↔table, struct↔struct,
  lattice↔lattice), arity must be equal, and for lattices the canonical spec
  token (`latticeSpec()`) must be byte-equal (min≠max, differing floor/ceiling =
  conflict). Any mismatch → **fatal with a precise diagnostic**, replacing the
  blanket dup-name fatal at `loadDatabaseBIN` (`database.h:1415`).

This is a *complete pass that runs to the end before any interning*, so a bad
import never leaves a half-merged state (see atomicity, §6). Struct-type
reconciliation falls straight out: same name → shared dest type id
(`R_type[srcType] = getStructId()`); new name → fresh `addStruct`.

**Conflict policy** is a parameter: `error` (default), or a `#:prefix` / rename
that namespaces `dbB`'s relation names so they land disjoint (also lets the same
DB be imported twice, or a self-merge under a namespace). Reserved
compiler-synthesized relations (`_enum`, `clo`, `applyN`, closure structs,
demand `f`/`f_ans`) **always** collide by name, so they always take the
reconcile path — they must match exactly on kind+arity or fatal (see §7).

### 4.2 The staged remap (dependency order)

One global `unordered_map<u64,u64> remap` (old `dbB` word → merged word) covers
strings and struct instances; `unordered_map<u32,u32> R_type` covers type ids.

**Stage 1 — strings (no dependencies).** The recovery problem: `dbB`'s 35-bit
ids are order-dependent and `loadStringsBIN` interns straight into the *live*
table, yielding *new* ids, not `dbB`'s. Fix: replay `dbB`'s `value.strings`
into a **fresh empty** `InternTable` in file order (reproduces `dbB` ids exactly
— each FNV bucket lives wholly in one partition, so collision positions
reproduce). For each string `s`: `old = scratch.intern(s)`,
`new = dbA.intern_string(s)`, record `remap[str_word(old)] = str_word(new)`.
`dbA`'s interner dedups by content, so the string *sets* union with no
collisions.

**Stage 2 — struct types (name-keyed today).** From §4.1:
`R_type[srcSID] = destSID`. Under namespaced catalogs this becomes a checked
source-TypeKey/member to destination-TypeKey/SID map. A compatible existing
destination member reuses its TypeKey; importing as a new independent
namespace mints one. The transitive value-rewrite algorithm is unchanged.

**Stage 3 — struct instances (the crux; acyclic DAG).** A `remapWord(w)`:
`is_s32`/`is_float` → `w`; `is_str` → `remap[w]` (stage 1); `is_struct` →
`remapStruct(w)`; **anything else** (reserved `slog_null`/`slog_lat_top`, and —
until supported — other intern tags) → see the *total dispatch* guard in §5.
`remapStruct(W)`: memoized; look up `W`'s fields (from the scratch DB's lookup
index, or B's `fieldtab`), `remapWord` each field **first** (descends into
children), then intern the remapped-field content tuple into the dest relation
`R_type[type(W)]` via `internStructTuple` (the exact `InternStructTask` body,
§4.3). Content hit → existing id word (dedup/union); miss → fresh id, and record
`remap[W]=newW`. **The traversal must be an explicit worklist / iterative
post-order, not native recursion** — a 10⁶-element cons list or deep AST is
acyclic but would overflow the C++ stack (§5).

**Stage 4 — tables & lattices.** Every referent is now in `remap`. Rewrite each
`dbB` row word-by-word with `remapWord`, then materialize into the dest
relation via the id-preserving direct-insert path (§4.3). Tables → btree set
union; lattices → per-key `lat_join`. **For `flat` lattices, the value column
too must be `remapWord`'d before the join** — else two content-equal-but-id-
different payloads compare unequal and the key spuriously collapses to
`slog_lat_top` (`types.h:123`).

**Correctness.** `R_type` is a name-keyed bijection built once. Strings are
content-addressed and idempotent. `remapStruct` is a memoized post-order over a
finite acyclic DAG with children-before-parents, so it terminates, visits each
instance once, and coalesces structurally-identical DAGs from both DBs to one
id (true union with sharing). `remap` is keyed strictly on *old* `dbB` words and
only ever fed words read from `dbB`, so there is no double-remap. Lattice join
is commutative/associative/idempotent, so order-independent. **Self-merge is a
no-op** (everything dedups/joins) — a strong sanity check.

### 4.3 Reuse of existing machinery

- **Strings**: `InternTable::intern_value`, unchanged.
- **Struct content-dedup + id assignment**: factor `InternStructTask::work`'s
  per-tuple body (`operators.h:395-423`) into a callable
  `Relation::internStructTuple(fields) → u64` and call it from both the task and
  the merge, so dedup semantics stay in lockstep.
- **Table union / lattice join**: the existing `ingestDelta` cold path
  (`database.h:680-691`) already inserts verbatim into every registered index
  (btree set-dedup; `BTreeMapIndex` `lat_join` merge). Reuse it for stage 4.
- **Id-preserving materialization of already-interned structs**: `ingestDelta`
  inserts tuples *without reassigning ids* — this is the path merged/opened
  struct instances must use, **not** `InternStructTask` (which would re-ID them;
  see §7.1).

### 4.4 API surface and pipeline integration

- **Core**: `Database::importDatabaseBIN(src_dir, ConflictPolicy, prefix="")`
  implementing §4.1–§4.2, plus helpers `internStructTuple` and
  `ensureStructIndices` (register+**populate** a content-first master + id-first
  lookup index on freshly-opened struct relations that only have
  `ensureDefaultIndex`'s identity ordering — §5).
- **Daemon verb** (`daemon.h`, mirrors `open`):
  `import(name){ db->importDatabaseBIN("data/"+name+"/"); needs_reload=true; }`.
- **`actions.rkt`**: `(import ,db)` → `d->import(db)` for online;
  `(merge-db ,a ,b ,c)` → `open a; importDatabaseBIN(b); writeDatabaseBIN(c)` for
  offline. **No compiler/codegen change** (structs resolve type ids by name at
  runtime).
- **Pipeline**: `import` mutates only cold-path indices, then `needs_reload=true`
  makes the next `beginStratum` reload re-stage the *union* as iteration-zero
  delta — zero pipeline changes. Offline `A+B→C` composes existing verbs and
  needs no new offline driver.
- **Parallelism**: stage 3 is a serial host-side traversal (DAG deps + shared
  memo/allocators — matches `ingestDelta`/`loadRelationBIN`); stage 4, once
  `remap` is complete, is embarrassingly parallel and can be bucket-partitioned
  like `WriteTask` later.

## 5. Mandatory correctness guards

These are non-negotiable in the merge implementation; each maps to a concrete
failure the critics reproduced.

1. **Global (not per-file) allocator seeding.** See §7.1 — fix `readBIN`/
   `readGzBIN` to accumulate the max instance id across **all** of a relation's
   bucket files (or have merge rescan the dest's true per-bucket max) before
   interning any source instance. Without this, a fresh `dbB` instance is handed
   an id a `dbA` instance already owns.
2. **`readGzBIN` decode fix.** Replace `word >> 28` (`database.h:589`) with
   `decode_struct_perbucketid(word, bucket_bits)` to match `readBIN` — else a
   gz-loaded source seeds the allocator with ~2³⁶ garbage and the next id
   overflows the 38-bit instance field into the type-id field.
3. **Total per-word dispatch.** `remapWord` must be total over the tag space:
   `is_s32`/`is_str`/`is_struct`/`is_float`, identity copy-through for
   `slog_null`/`slog_lat_top`, and a **fatal** on any other intern tag (mpz,
   `types.h:39`) — never copy an unrecognized word verbatim.
4. **Iterative post-order**, not native recursion, in `remapStruct` — deep
   acyclic structures (cons lists, ASTs) are the canonical struct workload and
   would blow the stack.
5. **Index registration/routing consistency.** `ensureStructIndices` adds only
   orderings the relation *lacks* (the content-first master `[1..A-1,0]`) and
   reuses the existing identity index as the lookup index — never re-`addIndex`
   the `[0..A-1]` ordering (that allocates a fresh empty array, discarding
   `dbA`'s data, `database.h:314`). Populate the master *and* probe it with
   **identical** `buckethash(master-lead-content-column)` routing — mismatched
   routing makes dedup silently miss and duplicates instances.
6. **Source-decode vs dest-encode strictly separated.** The same numeric type id
   means different structs across DBs and struct words carry no self-validating
   tag; resolve `decode_struct_id(srcWord)` only through the *source* type map,
   encode only through dest `addStruct`/`getStructId`, and assert the source id
   is a source-map key before every field descent. Never call the live db's
   `getStructById` on a not-yet-remapped word.
7. **Flat-lattice payload remap before join** (§4.2 stage 4).
8. **14-bit type-id ceiling check** (`is_struct` requires `0 < sid < 0x3fff`);
   `addStruct` has no bound (`database.h:827`). N-way struct-heavy merges can
   exhaust it → silent corruption. Add a bounded error.
9. **Robust directory parsing** before trusting any external DB (§6).

## 6. Pre-existing IO bugs and robustness gaps (fix before/with merge)

Merge is the first feature to read two independently-authored DBs, so it
*amplifies* every latent read-path weakness. Ranked by severity:

**High**
- **Per-file allocator seeding** (`database.h:538,571-573`): `max_id_seen` is a
  per-`readBIN`-call local, and the allocators are overwritten to *that file's*
  max+1 at the end of *every* call; `readRelationFiles` calls it once per bucket
  file (`database.h:1357`), so the allocators end seeded to the *last* file's
  local max+1 — not the global max. **Already a bug** for open-then-intern-a-new-
  struct (collision), and fatal for merge. → seed globally/per-bucket.
- **`readGzBIN` `word>>28`** (`database.h:589`): guard #2 above.
- **`tools.rkt` string ids** (`tools.rkt:101`): `convert-db-folder` encodes a
  string id as `(coll_n<<32)|fnv32`, but the daemon's `InternTable` keeps only
  the low **26** hash bits and puts the collision counter at bit 26; it also
  hashes code points, not UTF-8 bytes. Offline-built DBs' string refs don't
  resolve after the daemon re-interns. Fix `convert-db-folder` to mirror
  `InternTable` exactly, **or** mandate daemon-only offline merge and add a
  round-trip test. (Blocks using `convert-db-folder` output as a merge input.)
- **String-id reconstruction into a non-empty table** (`database.h:1314`):
  `loadStringsBIN`'s re-intern-in-order is faithful only into an *empty* table;
  `loadRelationBIN`/`refreshRelationBIN`/any online import shift collision
  positions and mis-resolve values. This is the string-side merge blocker; §4.2
  stage 1 (scratch replay + explicit remap) is the fix.

**Medium**
- **`readGzBIN` short-read** (`database.h:583`): `GzReadFile::read` returns a
  byte count; the loop treats 1–7 trailing bytes as a full word → silent
  corruption. Use `== 8` and fatal on a 1–7 remainder.
- **Substring dir classification/parsing** (`database.h:1381`): `find("struct.")`
  etc. run on the *full path*, and arity/id/spec are carved at the *first*
  `.arity.`/`.id.`/`.spec.`; an ancestor dir or a dotted relation name
  misclassifies or mis-splits, and `atoi` silently yields arity 0. Parse only
  `path::filename()`, anchor prefixes with `starts_with` at 0, split on the
  **last** `.arity.`, validate numeric, bound arity ≤ 32 (`index.h`).
- **`relationDirBIN` runtime-order dir naming** (`database.h:1173`): reconstructs
  a struct/lattice dir from the *in-memory* (declaration-order) type id / spec,
  so `loadRelationBIN`/`relationChangedOnDisk` silently no-op or fatal when the
  build order differs. Locate a relation's dir by **name-glob** (`*.NAME.arity.*`)
  and read the id/spec from the matched dir (as `loadDatabaseBIN` does).
- **Zero-arity relations** (`database.h:1165`): `writeAllFactsBIN` writes nothing
  for arity 0, so a propositional fact is dropped on round-trip; and a malformed
  non-empty arity-0 file → `i % arity` **SIGFPE** (no `arity>0` guard on the read
  path). Persist a presence marker; guard the readers.

**Low**
- **Native byte order + no header** (`database.h:534`): tuple words are
  native-endian with no magic/version/endianness marker, and `readBIN` opens in
  text mode. Cross-machine merge silently garbles. Add a small header (magic,
  format version, endianness, **compiler/schema fingerprint** — §7) and reject
  incompatible DBs. This becomes **mandatory** for merge (cross-provenance DBs
  are the point) and is the version field a future north-star migration needs.
- **`GzReadFile` inflates one byte per call** (`gzfile.h:122`) — O(n) overhead
  makes gz merges impractically slow; buffer input. `BinReadFile::read` returns a
  bool, not a count — divergent contract, a trap when generalizing readers.
- **`writeAllFactsBIN` `wordbuf[1280]` and read batches** have no arity bound;
  a corrupt/hostile `.arity.<huge>` overflows. Bound-check at registration.
- **mtime-only refresh + uncaught `directory_iterator`** (`database.h:1190`):
  races, and a concurrent write/remove throws and aborts the daemon. Pair mtime
  with a content signature; wrap iteration in try/catch (online import may read a
  dir still being written).

## 7. Deeper semantic prerequisites

### 7.1 Struct-id stability across the reload (the load-bearing question)

Confirmed: rules emit structs with a `0` id placeholder and `InternStructTask`
assigns the id (`operators.h:189,417`); so *within re-derivation*, a struct and
everything referencing it are recomputed together and ids may freely shift —
internally consistent. The danger is **struct-referencing data carried as EDB
across a program boundary** (exactly what open + merge + run does): the opened
instances are ingested verbatim by `ingestDelta` (id-preserving), **but** the
`beginStratum` reload (`reloadInsertBatches` dumps tuples + `ClearAllIndices`,
`database.h:1490-1528`) re-stages them, and if the next stratum routes them
through `InternStructTask` they get **new** ids while the referencing rows keep
the old ones → dangling.

**This must be pinned down empirically before building merge on top** (open a
struct DB, run a trivial stratum, assert struct-referencing rows are byte-
identical across the boundary). The safe design principle either way:
**already-interned struct instances (opened or merged) are materialized and
reloaded via the id-preserving direct-insert path (`ingestDelta`), never re-run
through `InternStructTask`** — only genuinely new structs produced by rules go
through the interner.

> **PINNED (2026-07-05): struct ids are stable across open → reload → stratum,
> by construction.** Mechanism (verified by code + experiment, then refined
> under adversarial review): the master index's *static* `WriteTask` ingests
> the reloaded delta **verbatim** (old nonzero ids intact) in phase_write of
> iteration 0, and the reloaded delta then never reaches `InternStructTask`
> at all — the read barrier's `finalizeAll()` swaps the delta for the read
> phase's output *before* phase_intern runs. Only fresh rule-produced rows
> (id `0`) flow through the interner, deduping by content against the
> verbatim rows and allocating **above** the loaded ids — which is exactly
> why the §6 allocator-seeding fix is load-bearing: with per-file overwrite
> seeding, 8 of 200 fresh structs in the experiment re-issued owned ids, and
> the referencing table silently collapsed 400 → 392 rows (silent data loss +
> ambiguous references; no crash). Fixture + regression:
> `tests/api/structdb.slog`, `tests/api/structuse.slog`, `api-tests.sh` §7.
> Two consequences for merge P1: (a) imported instances materialized via
> `ingestDelta` ride the same verbatim-WriteTask path on the next reload, so
> id preservation holds — provided allocators are seeded ≥ the merged max;
> (b) **reload does NOT content-canonicalize the master index** — a dbB row
> imported with content that dbA already holds under a different id would be
> blind-inserted as a second (content, id) tuple and persist forever, so
> content-dedup/remap MUST happen at import time (`internStructTuple`), never
> deferred to "the next reload's intern pass".

### 7.2 EDB vs IDB and merge-then-run soundness

`writeDatabaseBIN` persists *every* non-empty relation with no input/derived
tag. Re-running rules over a union is **monotone** (`emit` skips existing tuples,
`operators.h:148`) — it can only add. So a **derived** fact carried in from
`dbB` whose grounding is absent in the union persists forever (nothing can
retract it). The merged-then-run state is then neither DB's fixpoint nor the
from-scratch fixpoint over unioned inputs. This directly affects demand `f_ans`
and lattice results.

Resolution options: (a) add an **input-relation marker** to the format and merge
only inputs, re-deriving all IDB by re-running; or (b) ship merge+run explicitly
as a **monotone over-approximation** and gate sound retraction on the future
`DRed^c` (docs/incremental.md). Recommend (a) as the north for correctness, (b)
as the honest interim contract.

### 7.3 Incremental / counting substrate interplay

The planned `DRed^c` change (docs/incremental.md §6.1) turns the master-index
value from a set element into `Count`/`SCount` counters computed over *that DB's*
fact universe. These are **not** arithmetic-combinable across independent
materializations. Decide now: a merged DB is **counts-invalid** and requires a
full stratified re-derivation before any incremental +/- op. Merge and
incrementality both redefine the same index-value slot — settle the interaction
before either ships to avoid a rewrite.

### 7.4 Other cross-DB concerns

- **mpz bigints** (`mpz_intern_tag`, `types.h:39`): a second interned domain with
  no runtime table yet. Guard #3 fatals on it until a scratch-replay+remap and a
  real `mpz` `InternTable` exist.
- **enums / `_enum`**: enum constants and `true`/`false` are `_enum` **struct**
  instances (`modules.rkt:178`, `type-system.rkt`), so they're handled *by luck*
  of being generic structs — verify the struct pass visits `_enum` (incl. orphan
  instances referenced only from a column) and that a `bool`/`flat-any` payload
  holding an `_enum` word is caught by `remapWord`.
- **Reserved relations** (`_enum`, `clo`, `applyN`, closure structs, demand
  `f`/`f_ans`) always collide by name across programs; a compiler/schema
  fingerprint in the header (§6) should gate incompatible merges, with exact
  kind+arity match required.

## 8. Atomicity

`writeDatabaseBIN` does `remove_all` then parallel writes (`database.h:1294`),
which is neither crash-atomic nor safe if a task throws — an interrupted offline
`write-db` can destroy the output dir (catastrophic when `c == a`). Online
import mutates the live `Database` incrementally, so a mid-import fatal leaves it
half-merged (only "safe" because `fatal()` aborts the whole process — wrong for a
long-lived daemon). Fixes: offline → write to a temp dir + atomic rename, fsync
before rename, refuse output-name == any input-name; online → validate-all-
schemas-then-mutate (§4.1) and prefer build-into-scratch-then-swap so a bad
import is rejected cleanly and the daemon continues.

## 9. Non-goals (explicit scope boundaries)

- **Deletion / retraction** — merge is additive union/join only (see §7.2).
- **Cyclic struct instances / mutable collections** — the acyclic-DAG invariant
  is load-bearing; the docs/primitives.md §two-interner crux (mid-phase cyclic
  merge) is out of scope.
- **Canonical (order-independent) merged ids** — deferred with north-star C;
  merged ids are content-equivalent but import-order-dependent, so compare merged
  DBs by **content, not bytes**, and canonicalize reconciliation by sorting
  incoming relations by name.

## 10. Phased plan

- **P0 — prerequisites** (small, high value on their own): fix per-file allocator
  seeding, `readGzBIN` `word>>28` + short-read, robust dir parsing +
  name-glob `relationDirBIN`, arity bounds, and **empirically verify §7.1**.

  **STATUS: DONE 2026-07-05** (daemon/database.h + gzfile.h + compiler):
  `seedInternAllocators` accumulates via max across a relation's bucket
  files (the counter-experiment showed the overwrite bug silently corrupts:
  see §7.1); `readGzBIN` decodes with `decode_struct_perbucketid`; BOTH
  readers fatal on truncated trailing words and on arity 0; one validating
  `parseRelationDirName` (filename-anchored prefixes, LAST-`.arity.` split,
  all-digits checks, arity ≤ 32, struct id < 0x3fff) now backs the
  `loadDatabaseBIN` scan, and a name that CLAIMS a relation prefix but
  fails validation is a loud fatal, not a silent skip; read paths locate
  dirs via `findRelationDirBIN` (name-scan; fatal on ambiguity, shape
  conflict, or a struct dir under a FOREIGN type id — cross-session struct
  refresh stays a loud refusal until P1's remap); the write path removes
  stale same-name dirs and refuses to persist arity > 32 (open couldn't
  load it back); `addStruct` fatals at the 14-bit ceiling; `.gz` routing is
  by filename suffix, not path substring. **`GzReadFile::read` was
  rewritten** (gzfile.h): the old one-byte-per-inflate loop *stranded
  unconsumed compressed bytes* whenever pending window-match output filled
  the caller's buffer — repetitive (well-compressing) data silently lost
  rows (50k identical words read back as 592 corrupt ones, no error);
  input is now buffered across calls and a mid-member EOF is a loud
  truncation fatal. Compiler parity: `db-manifest-from-name`
  (runslog.rkt) now parses entry basenames with anchored full-charset
  patterns (was: unanchored `\w+` over the absolute path — apostrophe
  names vanished from the manifest and their facts were destroyed on
  reload; ancestor dirs could poison every manifest), validates bounds,
  and errors on malformed/duplicate names; `convert-db-folder` (tools.rkt)
  bounds arity to 1..32 (arity-0 CSVs previously hung it forever).
  §7.1 pinned (see above). NOT yet fixed (P2 as planned): zero-arity
  persistence (round-trip still drops propositional facts — the readers
  now refuse rather than SIGFPE), `tools.rkt` string-id scheme,
  header/atomicity, mtime races, `writeRelationBIN` not co-persisting
  struct relations its rows reference (partial-write contract).
- **P1 — core merge**: `importDatabaseBIN` (§4), `internStructTuple` factoring,
  `ensureStructIndices`, `import` + `merge-db` verbs, guards §5, id-preserving
  reload for already-interned structs (§7.1). Restrict/flag EDB-vs-IDB per §7.2.

  **STATUS: SHIPPED 2026-07-06** (`Database::importDatabaseBIN`,
  `Daemon::import`, the `(import db)` action, `import:DB` in
  send-actions).  As designed (A/B hybrid): a scratch `Database` loads the
  source (fresh interners reproduce its ids; single-threaded, no strata);
  schema reconciliation validates everything before any dest mutation;
  ONE iterative children-first worklist remaps words across all FOUR id
  spaces — strings re-intern by content, struct instances content-dedup
  against a host-side map that mirrors `InternStructTask`'s content-key
  and bucket routing (fresh ids draw from the same per-bucket allocators,
  so §7.1 id-preservation composes), and **collection nodes rebuild via
  the dest arena's kernels** (never field-wise — remapped keys change the
  canonical shape); rows then ingest id-preservingly, lattice payloads
  joining per key through `BTreeMapIndex::insertTuple` (including
  `LAT_EXTERN` collection joins).  Deviations from §4: no
  `ensureStructIndices`/`internStructTuple` factoring — the host-side
  content map replaces the b-tree master probe entirely (no addIndex
  clobber risk, guard #5 moot), and dedup for FUTURE rule interns still
  agrees because fresh ids use InternStructTask's routing + allocators.
  Import is reachability-driven, so unreferenced source arena nodes are
  not copied.  Tested: api-tests §8 — `open A; import B` is CSV-identical
  to the from-scratch fixpoint over the unioned facts across strings,
  struct dedup, rebuilt string-keyed collections, `(min int)` per-key
  join, and `(set int)` union; self-merge is a no-op.  §7.2 stands as the
  honest contract: merge-then-run is a monotone over-approximation.
  Still open (P2): offline `merge-db` one-shot verb, atomicity
  (scratch-then-swap), header/fingerprint gating, counts-invalid flag.
- **P2 — hardening**: header (magic/version/endianness/fingerprint) + reject
  incompatible; atomic offline write + scratch-swap online; gz buffering;
  concurrency-safe iteration; counts-invalid flag (§7.3); mpz/enum guards.
- **P3 — optional**: north-star content-addressing (C) if canonical ids are
  needed; parallelize stage 4.

### 10.1 Namespaced catalog integration

The shipped importer discovers a source schema from relation directories and
reconciles flat names. That remains the data-plane mechanism, but module
namespaces add a control-plane preflight:

1. load the source's persisted declaration catalog, including empty members;
2. apply one structured source-prefix to destination-prefix substitution;
3. validate every overlapping declaration graph and collect missing members;
4. choose destination VersionKeys and TypeKeys atomically;
5. declare the complete destination namespace; and only then
6. run the existing string/struct/collection word remapper and row ingestion.

An older database with no catalog can still use the present kind/arity/lattice
ABI reconciliation, but tooling must label that check as legacy/partial. Empty
members and field-type graphs cannot be inferred from its data directories.

Root replay and independent import have different identity behavior. Replaying
the same recipe lineage preserves VersionKeys and TypeKeys, though a fresh
daemon may assign different VersionIds and SIDs. Importing under a fresh
namespace creates new destination keys; importing onto compatible existing
members reuses the destination keys. Neither case changes the recursive
source-word to destination-word canonicalization described above.

## 11. Testing

A **differential** harness asserting `merge(a,b)` == a from-scratch load of the
union. Fixtures built by `write-db` (not `convert-db-folder`, until §6 fixed).
Cases: self-merge idempotence, overlapping-table union, lattice per-key join
(incl. `flat-any`/`flat-str` payload remap), nested cons-list / AST struct
dedup, orphan struct only referenced from a column, enum/`bool` cross-DB,
struct-referencing EDB across the reload (§7.1), N-way + reversed order
(content-equal), and import of a concurrently-written dir. Extend
`tests/api-tests.sh` (currently single-DB open/write/refresh/sizes only).

## 12. Effort

Core merge (P1) ≈ 350–500 LOC, daemon-side: `importDatabaseBIN` + `remapWord`/
iterative `remapStruct` + scan helpers (~250) in `database.h`; `internStructTuple`
factoring (~30, no behavior change) + `ensureStructIndices` (~30); `Daemon::import`
(~8); `actions.rkt` two verbs (~6). No codegen changes. P0 prerequisites are
small localized fixes. P2 header/atomicity/gz are independent hardening. Heaviest
risk is index routing/population parity (§5.5) and the §7.1 reload semantics.
