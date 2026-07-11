# Fully Incremental Slog: Sessions, Insertion, and Deletion of Input Facts

**Status:** design / pre-implementation. Revised 2026-07-08 against the current
codebase: the compiler now HAS SCC stratification (the 2026-07 rewrite), the
read phase is push-operator based, pausing and lattices L0+L1 are shipped, and
db-compression (recompute-on-load, `docs/db-compression.md`) is fully shipped
forward-incremental — §8A below pins the composition contract with it. Code
anchors throughout were re-verified 2026-07-08; M2's scope shrank accordingly
(§6.4, §9).
**Second revision, 2026-07-08 (same day):** restructured around the workflows.
A new §0 defines the *incremental-session model* and **Phase 0** — full
*forward* incrementality with **no counters**: streaming input batches into a
live or reloaded fixpoint, deletion by bounded recompute, stratified negation
(currently absent from the language — a gating sub-phase), relation
rename/drop between pipeline segments, hot-linking existing databases into a
running program, and the delta-layer IO that saves, loads, and continues a fed
session as a new linked `data/` database. The DRed^c core (§1–§8A) is
unchanged in substance and becomes Phases 1–2 (§9); external docs' references
to §1, §6.1, §7A, and milestones M0–M7 remain valid.
**Goal:** make slog programs incrementally maintainable in *both* directions — a stream
of insertions **and deletions** of EDB (input) facts is applied to a materialised
database and every derived relation/struct is updated to exactly the least-fixpoint it
would have had if the new input had been loaded from scratch, without recomputing from
scratch — and make the *session* (the growing pipeline of programs, batches,
renames, and links) a first-class, saveable, resumable object.

This document captures the full design worked out in discussion: the workflows
and session model (§0), the theory that constrains deletion (§1–§5), the
algorithm we chose for it (DRed^c), and — concretely — every change we expect
to make and where it lands in the codebase.

---

## 0. The incremental-session model, and Phase 0: forward incrementality first

*(added 2026-07-08, 2nd revision; all code anchors verified against the tree
the same day)*

This section is the result of stepping back from the DRed^c machinery and
asking what workflows the feature must actually serve. Two observations drive
the restructuring:

1. **Most of the user-visible value needs no counters.** Streaming *positive*
   batches into a monotone fixpoint is ordinary semi-naïve continuation.
   Deletion and non-monotone updates are *sound today* via bounded recompute
   (clear the affected downstream strata and re-run them — the same reasoning
   that made db-compression's edit-and-propagate "sound for free",
   db-compression.md §12), just not O(change). Counters (Phase 1) and DRed^c
   (Phase 2) then *shrink the granularity* of that recompute — they are
   performance refinements of a semantics Phase 0 already delivers (§0.11).
2. **The IO story is the actual product.** A session — programs, batches,
   renames, links — must be a saveable, replayable, extendable object. The
   db-compression DAG (`META` manifests, `prog.sexpr`, signatures,
   `db-load-steps`) is 80 % of that object already; Phase 0 finishes it by
   making *increments* first-class recipe steps with a bin-file
   representation, rather than an afterthought bolted onto `edits`.

One gap gates everything: **the language has no negation.** `~` is lexed to a
`'not` token (lexer.rkt:60) that no parser rule consumes (parse-atom,
parser.rkt:130-191, errors on it; it is in neither the operator table
:381-394 nor the keyword set :397-398); stratify.rkt:20-22 states outright
that stratification is currently an optimisation, not a semantic requirement.
Aggregation exists only as lattices — which is the *right* foundation
(monotone-use calculus, lattice-check.rkt) — but the classical
`~(foo x 1)`-style stratified guard, its safety checks, and its runtime
antijoin are all missing. The incremental driver needs negation's *polarity
metadata* (which downstream edges are non-monotone) even to route a batch, so
shoring this up is sub-phase **0.A**, first (§0.8).

### 0.1 The workflows (W1–W9)

A slog pipeline is a long sequence of SCC-strata arising from any mix of: SCC
condensation of one program (stratify.rkt), user-level `run` sequencing over
modules (linearize-programs / thread-manifests, modules.rkt:744-797), and a
new program run atop a loaded DB whose chain embeds its own programs
(db-compression §10). The session model must make all of these ordinary:

- **W1 — run & stream.** Run a program from scratch; at fixpoint, feed
  batches of new input facts into any relation; each batch updates the
  fixpoint without a from-scratch rerun.
- **W2 — load & stream.** `-d NAME` a saved chain (replay-from-origin), then
  W1 against the reconstituted fixpoint. Loading and running-from-scratch
  must land in the *same* streamable state.
- **W3 — save a fed session.** A save after increments **always** creates a
  NEW `data/X` layer linked to the old chain — ancestors are never mutated
  (copy-on-write over the immutable DAG, db-compression §7). The increments
  are stored *inside X* as bin-file deltas plus recipe metadata recording
  where in the program tree each batch applies (§0.4, §0.10) — even when the
  target relation lives "way up" the chain.
- **W4 — move & continue.** Load X on another machine/day, stream more, save
  again. Chains grow; every link stays replayable and verifiable.
- **W5 — pipeline by rename.** Rename or drop relations between pipeline
  segments, so program A's `foo` *becomes* program B's `bar` — one relation,
  one copy, no `(bar x) <-- (foo x)` prop rule (§0.7).
- **W6 — hot-link.** Attach an existing DB **with its full program chain**
  to a live session: "all tuples of relation X over there are, from this
  point on, also tuples of relation Z here" (§0.9).
- **W7 — freeze.** Cut a chain: materialise and write a plain root with no
  history. `--flatten` exists at save time (db-compression §7.3,
  runslog.rkt:651-657 writes `#:kind 'flat`); Phase 0 adds the missing
  `slog db freeze` verb for freezing an *existing* chain (§0.10).
- **W8 — front-end editing.** An editor watches source changes and submits
  deletions + insertions of AST facts; the session absorbs them. (Phase 0 by
  bounded recompute; Phases 1–2 make it precise. Whether the front end must
  split delete/insert into two batches: **no** — §0.6.)
- **W9 — self-unrolling pipelines & time travel.** A program that *extends
  its own pipeline*: e.g. a program analysis framed as a refinement loop —
  run the analysis, declaratively compute (atop the results) where and how
  to refine precision, materialise the refinement, run the same analysis
  again — unrolled some small N× into the pipeline. Requirements this
  forces: the **same cached `.so`s must be instantiable at many pipeline
  positions without recompiling** (name resolution must be positional, not
  baked in — §0.5's version environment), and the result must be
  **introspectable across time** — "show me relation R as it stood at
  pipeline point 24" is a lookup, not a replay (§0.4).

### 0.2 A session is a recipe of anchored steps; a save is a delta layer

The unifying mental model — an event-sourced database, where events carry an
*anchor* into the pipeline:

> A **session** = a base chain (possibly empty) + a **recipe**: the ordered
> pipeline of steps `run <program-segment>`, `rename R S`, `drop R`,
> `link <db> <name-map>` — plus, attached to any **pipeline point P** in
> that pipeline (a stratum/segment boundary), signed **batches**
> `batch ± <rel> <payload> @P`. The resident daemon holds the
> *materialisation* of the pipeline; the driver (runslog.rkt) holds the
> recipe. **Saving serialises the recipe** (with its batch payloads and
> program sources) as one new `data/X` layer whose manifest links the base
> chain — loading a DB is therefore always loading a whole
> DB-plus-programming-session and building atop it. **Loading replays the
> recipe** with the *same* machinery used live, so load-and-continue is one
> code path (§0.10), exactly as db-compression made load = replay.

**Mutation semantics within a live session (decided 2026-07-08).** Batches
are *attachments to pipeline points*, not a layered edit history:

- The session holds, per (pipeline point P, relation), a signed batch set.
  Ad-hoc updates issued later against the same P **mutate that set in
  place**: adding tuple T at P and then retracting T *at the same P*
  collapse to nothing — the pair is simply absent from any subsequent save.
- An add of T anchored at P and a delete of T anchored at a **later** point
  P′ do *not* collapse: both are recorded and both are saved — they mean "T
  exists in the pipeline from P up to P′", which is a genuine semantic
  content of the session (readers between P and P′ see T; readers after P′
  don't).
- There is **no intra-session version history of the edits themselves** —
  no undo layers, no per-edit provenance beyond the collapsed batch sets.
  Layered, stratified history arises exactly one way: **save, then load,
  then keep working** — each save is an immutable layer, and the next
  session's batches anchor into the loaded pipeline (which may reach back
  into ancestor layers' pipeline points; the anchor is saved with the new
  layer, ancestors untouched).

This subsumes and extends what already exists:

- A db-compression layer is the special case "recipe = one `run` step" (plus
  `edits`). A pure merge is "recipe = empty" with a 2-entry manifest (§7.2
  there). A **pure-batch layer** — increments saved with no new program — is
  "recipe = batches only": manifest → base, empty program. All uniform.
- The shipped `edits` file (`(add-tuple REL v…)`, applied on load right
  after its layer opens — dbtool.rkt:147, runslog load steps) is the
  degenerate batch step: inline payload, anchored at the layer's entry
  point. Phase 0 grows it into the `recipe` file (§0.10) rather than
  inventing a parallel mechanism; the in-place `edits`-on-an-ancestor verb
  (`slog db edit` + stale-propagation) survives as the *mutate-history*
  operation, distinct from the normal append-only flow (same "reproduce vs.
  mutate are different verbs" honesty note as db-compression §12).
- Immutability, staleness, `gc`, atomic writes, signatures, drift
  attribution: inherited unchanged from db-compression §7/§11.

### 0.3 Batches: one abstraction, three transports

A **batch** is `(sign, target-relation, payload)` anchored at a pipeline
point (§0.2, §0.4). Payloads have three transports, chosen by size — but
they are *one* concept, and two of the three already reduce to existing
machinery:

1. **Inline (small, ≲ 2k tuples).** Values baked as literals into a generated
   action plugin — the `add-tuple` path (actions.rkt `(add-tuple …)` →
   `Daemon::addTuple`) generalised to
   `(add-batch REL ((v …) …))` and `(del-batch REL ((v …) …))`. This is the
   W8/editor case. The .so bake cost is fine at this scale (it is how inline
   ground rules already work); past a few thousand tuples it is not (the known
   ~10k inline-facts ceiling) — bulk client data enters via transport 3
   (CSV→root conversion, or an existing DB).
2. **Bin-backed (bulk, layer-owned).** The payload is an ordinary **mini bin
   database** — a directory written by the daemon's canonical writer,
   closure-complete, carrying its own `value.strings`/`value.nodes`.
   Applying it = `importDatabaseBIN` (database.h:2760-3022), whose
   children-first content remap already solves all four id spaces. Stored
   inside the saving layer as `delta.<k>/` (§0.10). The daemon is the only
   producer of these (client-side bin writers are deliberately NOT a goal):
   they arise at save time — consolidating a long session's accumulated
   inline batches into one payload — or by embedding a converted CSV root
   the user doesn't want as a standing link.
3. **Linked-DB (huge / provenance-bearing).** The payload is a *reference*
   to an existing `data/` database (and hence its whole chain), plus a
   name-map: `(link DB ((X Z) …))`. Same import machinery with a rename map
   (§0.9); the manifest records the edge so replay rebuilds it recursively
   (db-load-steps, dbtool.rkt:171-191, is already recursive and memoised).

Rules of the road:

- **Batches apply at stratum boundaries only.** `open`/`import`/`add-tuple`
  are already refused mid-suspend (refuseIfSuspended, daemon.h:115-124);
  batches inherit that. With pausing shipped, boundaries are frequent; a
  batch arriving mid-fixpoint queues (driver-side) until the next boundary.
- **A batch may mix signs and relations at the API** (a front-end
  convenience); the *driver* folds it into the per-(point, relation) signed
  batch sets, applying §0.2's same-point collapse (§0.6). The on-disk
  recipe stores the collapsed, decomposed form.
- **Under Phase 1 counting, batch application points become exact-once
  boundaries** — the same §8 discipline as iteration-0. Design the staging
  path now so a batch's tuples enter the delta exactly once (no double-stage
  on the reload path), or Phase 1 inherits corrupted counts.

### 0.4 Relations across time: version chains and anchors (rewritten 2026-07-08)

*(The first draft of this section claimed batch position normalizes away
entirely — "a relation completes in exactly one stratum". That is true
within ONE stratified program segment (all rules heading R condense into
R's SCC, so one segment gives R one completion point) but FALSE across a
pipeline: `run` sequencing, a new program atop a loaded DB, and
mid-pipeline imports all let a later segment write R again, and strata in
between read the earlier content. Position matters — at exactly the
granularity of those update events.)*

**The model: a relation name denotes a chain of versions.** Along the
pipeline, `R` is really `R@1, R@2, R@3, …`, delimited by **update events**:

- a program segment whose rules have head `R` (each segment writing R
  contributes exactly one version — within a segment, one completion point);
- a merge/`link` importing into `R` at a boundary (§0.9);
- an ad-hoc batch point `@P` targeting `R` (§0.2);
- `(drop R)` — *severs* the chain: a later (re-)declaration of `R` starts a
  fresh, empty chain under the same name;
- `(rename R S)` — pure *rebinding*: `S`'s first version IS `R`'s last
  version (same physical object, zero data movement); `R` is unbound after.

**Semantics = desugaring; implementation = environment.** The *meaning* of
the pipeline is the one big stratified program obtained by α-renaming the
versions apart and inserting an implicit inheritance rule
`R@(k+1) ⊇ R@k` at each boundary (omitted where a drop severed the chain).
We deliberately do **not** implement it that way — no gensym, no
recompile-per-instance (that would defeat the `.so` cache and W9's
same-program-at-many-points unrolling). Instead the daemon keeps a
**version environment** (§0.5): physical relations keyed by version, and a
per-pipeline-position map name→version that generated code's by-name
lookups resolve through at plugin-bind time.

**What survives of the old normalization claim** (now correctly scoped):
*within one version's span*, where exactly a batch anchors is immaterial to
the final fixpoint — so the anchor's real granularity is
**(relation, version)**. And version boundaries are *source/recipe-level*
facts — which segments write R is fixed by rule heads in source plus recipe
events, never by how the compiler condenses SCCs within a segment — so
**version ordinals are stable across recompiles** and are what the saved
recipe stores. No stored SCC indices (they are positional and drift); the
rule-id sets in META `strata` remain the diagnostic cross-check.

**Addressing (decided).** The user-facing handle is a **pipeline point**:
"give me `R` at point P=24". Imprecise addresses resolve under the hood to
the last write at-or-before P — if R was last updated at 17 and not again
until 29, `R@24 ≡ R@17`. The default, address-free query means "latest
version". Dropped or renamed-away names remain addressable at old points
(their versions persist in the old part of the pipeline — nothing is
discarded). Phase 0 exposes this as API/actions (versioned `lookup` /
`dump-rel` / `sizes`, and a pipeline-introspection action so a front end
can (re)discover the pipeline map from a live daemon rather than only from
compiling); richer surface syntax and human-readable point naming are
deliberately deferred — reserve the API seams, don't overbuild (per
discussion 2026-07-08).

**Materialisation policy (decided).** A boundary creates a new physical
version **only for relations actually written at it**; untouched names
alias their predecessor version in the environment (`R@24` *is* `R@17` —
logical identity, no copy, no storage). When R *is* written at a boundary,
the new version is a **full physical copy** of the predecessor's master
index (plus the update) — deliberately NOT an overlay/passthrough over the
old version, because reads-through-layers would make every join potentially
a multi-version join and demand new codegen. Future-work note (explicitly
parked): copy-on-write / layered master indices and delta-over-base
representations, if unrolled workflows make eager copies too heavy.

**Counts per version (Phase 1 forward-pointer).** Under the desugared
semantics the inheritance rule gives every inherited tuple one `nonrec`
derivation in the new version, so each version's `(nonrec, rec)` are
self-contained — and version boundaries become hard `nonrec>0` barriers:
a future DRed^c sweep triggered in one segment can never tunnel into an
earlier version. The version structure is what makes Phase 2's deletion
*local* — bounded per-segment sweeps instead of whole-pipeline ones.

### 0.5 The runtime: the version environment, re-entry modes, and the monotonicity cone

**The version environment (new, daemon-side — the load-bearing piece).**
The physical registry keys relations by **version id**; per pipeline
position, an environment maps name → version. Today's single global
name→Relation map (`Database::relations`) becomes the environment of the *latest*
position. Generated code already resolves relations **by name at
registration time** (`getRelation("R")` during plugin bind — the identity
invariant db-merge pinned), so the change is confined to bind time: when a
stratum plugin is pushed at pipeline position P, its lookups resolve
through P's environment. Consequences, all deliberate:

- **The same cached `.so` is instantiable at many pipeline positions with
  no recompilation** — each push binds the versions current at its
  position. This is what W9's self-unrolling pipelines require, and why we
  reject the desugaring implementation (gensym'd `R_3` baked into generated
  code would force a rebuild per instance).
- **Rename/drop are environment operations** (§0.7): a rename rebinds a
  name to an existing version; a drop unbinds it. No physical rekeying, no
  data movement; old versions stay registered and addressable (§0.4).
- **Run time is untouched** — after bind, tasks hold direct pointers as
  today; the environment is consulted only at push/bind and by the
  versioned query actions.
- The front end mirrors the environment from the recipe it compiled, and a
  **pipeline-introspection action** lets it re-derive the map from a live
  daemon (needed after loading a saved session it didn't build).

The rest of the substrate is closer than it looks: strata stay resident
after running (daemon.h:18-27); re-sending a stratum's cached `.so` path
re-registers its tasks, and `beginStratum` (daemon.h) performs the
deferred whole-DB reload — every relation re-staged as the new stratum's
iteration-0 delta (`Database::reloadInsertBatches`). `add-tuple`
already sets `needs_reload`. What's missing is captured in two places: the
"re-running an old stratum needs its task `Index**` bindings re-bound"
caveat (daemon.h header comment) and pausing.md §12's deliberately-cut `bind()` seam.

**Cone analysis (compiler+driver-side, new).** Over the **version graph**
(rule dependency edges within segments + inheritance edges between
versions, §0.4): `cone(R@k)` = everything reachable from version k of R —
the later versions of R itself and every dependent relation-version. Plus a
per-edge **monotone bit**: an edge is non-monotone if it is a negation read
(§0.8) or a read of a lattice-valued relation across the re-entry boundary
(an ascended value can invalidate downstream facts derived from the old
value — precise change-splitting across strata is DRed_L, deferred to M7;
Phase 0 is conservative). The per-segment half comes from the stratified
condensation and is exported in the stratum sidecar manifest
(write-stratum-manifest, compile.rkt:194-204); the cross-segment half is
recipe-level and lives in the driver.

**Three re-entry modes.** All are framed against the version model: a batch
anchored at `R@k` first updates that version's master index (for an
alias-only boundary this *creates* the physical version: copy predecessor,
apply batch — §0.4's materialisation rule), then propagates through
`cone(R@k)` by one of:

1. **Replay-entry (exists today; O(data-in-cone); sound for monotone
   cones).** Re-push the cached `.so` of each cone stratum in topological
   order; each `beginStratum` re-stages everything as iteration-0 delta;
   every rule re-fires; set-semantics dedup absorbs the old, the new
   propagates. These are precisely the mechanics that already carry
   edit-and-propagate's full re-replay — Phase 0's contribution is
   **cone-limiting** (skip strata outside the cone) and skipping the
   recompile (the `.so` cache makes re-push cheap). The pipeline vector
   grows with each re-push (scc_id = position at push, `Daemon::push`);
   fine functionally, curbed later by the bind()-reuse path.
2. **Clear-and-rerun (small additions; sound for EVERYTHING — deletions and
   non-monotone cones).** As (1), but first **rebuild the anchored version
   without the retracted tuples** (copy predecessor, minus deletes, plus
   adds) and **clear the downstream cone versions** (per-relation
   `clearIndices` — contents only, registrations persist). Then re-run the
   suffix. Everything below/outside the cone is final throughout, so this
   is a from-scratch run of a pipeline *suffix* — the true fixpoint of the
   edited input, retraction included, by the same argument that made
   replay-deletion sound (db-compression §12). Struct relations cleared in
   the cone re-mint ids on re-derivation; every referent of those ids is
   itself in the cone (it got the id via a join downstream of the struct
   relation), so no dangling ids — and allocators stay monotone (never
   reuse), with a compressed save+reload compacting them eventually
   (§8A.5).
3. **Delta-entry (O(change) — the default we are building toward).** Stage
   *only the batch* as the re-entered stratum's iteration-0 delta (a
   delta-preserving variant of the reload) and let semi-naïve run. Within
   R's *own* segment this works with today's compiled versions (R is
   dynamic there — per-position delta versions exist). The catch, stated
   plainly: **for downstream strata there is no compiled entry point that
   accepts "just the new R tuples."** For body relations from earlier
   strata the compiler assumes they are finished and emits a single
   run-once variant scanning the whole relation — so when a batch later
   lands in R, the only compiled paths downstream either rescan everything
   (mode 1/2) or don't fire at all; feeding a delta to a variant whose
   fixed driver is a different body relation silently under-derives
   (verified against the planner's dynamic-rels → `static?` flow,
   operationalization.rkt `split-old-marks` → emit-cpp.rkt `static?`). The fix is to **also
   emit delta-driven variants for cross-stratum body relations** — the
   same trick semi-naïve already uses within an SCC, extended across
   stratum boundaries. **Since the fully incremental workflow is the
   product default (decided 2026-07-08), these variants are the default,
   not opt-in** — no `(stream R)`-style declaration. The extra read-task
   compile cost (real: docs/fast-compile.md's task-count analysis) is an
   engineering problem with known levers: compile the delta-variant flavor
   of a stratum **lazily**, the first time a batch actually targets one of
   its inputs (it is just another cached artifact — `build/<hash>.so` today,
   `build/<hash>.delta.so` then), tiered -O0/-O2, and an opt-out flag for
   one-shot batch runs that will never see an increment. Under counting
   (Phase 1) this mode stops being optional: modes 1–2's re-firing is
   absorbed by set dedup today but would double-count — by M0, delta-entry
   is the required path for streamed batches.

**Routing rule (the whole driver policy):** positive batch + all-monotone
cone → delta-entry when the flavor is compiled, replay-entry until then;
anything with a negative sign or a non-monotone edge in the cone →
clear-and-rerun of the affected cone. All three end with the strata's
`(fixpoint)` handshake and compose with pausing budgets unchanged
(`continueRun`, daemon.h).

**Memory posture (decided).** The whole pipeline — every materialised
version's master index — is **held in memory by default**; that is what
makes "new input anywhere, low-latency recompute" the default workflow.
Secondary/join indices are kept only for versions that live strata read and
are rebuildable on demand; disk spill for cold versions is a flagged later
optimisation, not a Phase 0 concern.

#### 0.5.1 0.B+0.C as built (2026-07-11): version substrate, re-entry modes, routing, delta-entry, anchors

What shipped, and the decisions the design left open:

- **The latest map stays.** `Database::relations` remains the name→Relation
  map every run-loop walk (finalize/reorg/reload/orphan-restore), save, and
  default `getRelation` uses — it is now defined as *the latest
  environment*, non-owning. Ownership moved to `rel_registry` (every
  physical version ever, creation-ordered); `rel_bindings` holds per-name
  chains of `{pos, Relation*}` binding events. Every registration site
  funnels through `Database::registerRelation` (addRelation/addStruct/
  loadDatabaseBIN/ensureStatsRelation/newVersion), so the three structures
  cannot drift. Old versions leave `relations` at a boundary and thereby
  leave every run/save/reload path for free — no filtering anywhere.
- **Positions are boundary-event counts, not SCC ids.** A monotone counter
  (`Database::pipeline_pos`): each `open`/`import`/`import-path`/
  `import-layer`, each `begin-segment`, and each fresh stratum occupies the
  current position and advances it (`Daemon::push` stamps
  `Stratum::pipeline_pos`; the hot-swap re-push path neither stamps nor
  advances). Distinct positions per event keep a segment boundary from
  shadowing the load it follows at the same position. Version ordinals per
  name (= index in its chain) stay recipe-stable as §0.4 requires.
- **Boundaries are driver-announced.** The daemon cannot infer a segment's
  write-set from a path-only `.so` push, and versioning per *writing
  stratum* would be wrong anyway (side channels like `error` are written by
  many strata of one segment). So the driver sends a `begin-segment`
  action naming the segment's writes: the union of its strata's `.meta`
  `dynamic-rels` (the manifests' first consumer) plus the relation names of
  its frozen ground-fact databases (their import follows the boundary —
  frozen rows are segment writes). runslog emits it when running atop a
  `-d` input and before each replayed layer's strata; fresh runs skip the
  no-op. The daemon replies `(segment P N)`; every driver reader tolerates
  the extra line.
- **`newVersion` copy mechanics.** Registration copy: arity, struct id
  VERBATIM (downstream rows embed it; `structs_by_id` memo follows the
  latest version), lattice spec re-registered via
  `setLatticeFromSpec(spec, cnode_arena)`, and per-bucket
  `intern_allocators` copied verbatim (both versions mint from one id
  space — a fresh allocator would collide with ids the predecessor
  issued). Content copy: `ensureDefaultIndex` + `forEachNominal` →
  `insertTupleAllIndices` — id-preserving, lattice payload maps merge.
  The copy lands in the default identity index and is normalized by the
  next reload's dump+clear+restage exactly like an opened database; the
  predecessor's indices are never touched. Copies only settled (indexed)
  content — boundaries sit between strata where deltas are drained.
- **Addressing shipped with B0** (pulled forward from C1, API-seams-now):
  `getRelationAt(name, P)` (last binding ≤ P) under a `(pipeline)`
  introspection action — `(pipeline (pos P) (rel NAME (v ORD POS SIZE) …)
  …)` — plus `(sizes-at P)` and `(dump-rel REL P)` action variants.
  `Database::bind_pos` (set via `setBindPosition`) makes `getRelation`
  resolve positionally at plugin-bind time; **no consumer yet** — B1's
  guard sidesteps it, B2's positional re-binding consumes it.
- **B1 — cone-limited replay-entry (same day).** The session driver's
  `reenter` op: after a latest-anchored batch (`add-tuple`), re-push the
  cached `.so` of each cone stratum in pipeline order; each `beginStratum`
  re-stages the whole DB as iteration-0 delta, indices re-register from
  scratch (the reload had cleared registrations — exactly why re-push works
  where resident-task reuse would dangle), set-dedup absorbs, the batch
  propagates. The daemon needed nothing beyond introspection — the re-push
  mechanics existed; B1's content is *driver policy*:
  - **Cone assembly** chains the `.meta` `reads`/`dynamic-rels` manifests
    (A7's cone consumer): S is in cone(R) iff it reads R or a relation a
    cone stratum below produced.
  - **Anchor filter.** Only strata bound *at-or-after the target's last
    binding position* are candidates — earlier strata read a predecessor
    version and must not re-fire. `(pipeline)` introspection now carries
    per-stratum bind positions (`(strata (s SCC POS "NAME") …)`) so the
    driver reads this live instead of mirroring the event counter.
  - **Latest-binding soundness guard.** A re-pushed stratum binds the
    LATEST environment, which equals its own position's environment only
    if nothing it touches (reads or writes) was rebound after it; the
    driver refuses otherwise (positional re-binding + boundary
    re-materialisation is clear-and-rerun's job, B2). Likewise any
    neg/lat edge into the cone refuses toward B2 (the §0.5 routing rule's
    non-monotone arm).
  - **Re-entry pushes open NO version boundary** (no begin-segment): a
    latest-anchored batch updates the current version in place — its span
    extends to now (§0.2/§0.4); re-derived tuples belong to the same
    versions.
  - Non-cone relations survive the re-entry reload via
    `restoreOrphanRelations` (indices cleared, content re-materialised
    from their own dumped shards) — the keep-alive discipline api-tests §9
    already pinned.
- **B2 — deletions + clear-and-rerun (same day).** Primitives:
  `Relation::removeTuple` (dump-filter-rebuild — btrees have no
  point-delete; O(relation) by design until M0's counters) under a
  `(del-tuple REL v…)` action, refused for lattice/struct relations
  (retract inputs, not derivations); `(clear-rel REL)` = `clearContents`
  on the latest version — contents only, registrations and intern
  allocators persist. Driver `rerun` op: same cone/anchor/rebound-guard as
  `reenter` but ignoring the monotone bit — clear each cone-written
  relation, then re-push the cone; the re-run's iteration-0 reload stages
  base ± batch without the stale derivations, so the suffix runs from
  scratch (the mode-2 soundness argument). Decisions:
  - **Clear-set = cone `dynamic-rels` minus relations also written by
    non-cone strata** — the shared diagnostic side channels (`error`,
    `$seq_*`, …) must not lose their out-of-cone content; stale in-cone
    diagnostic rows are accepted for Phase 0. A *genuine* IDB relation
    with writers in and out of the cone implies a cross-segment rebinding,
    which the rebound guard already refused.
  - **When the rebound guard passes, every cone head's version IS latest**
    (nothing a cone stratum touches was rebound after it) — so
    latest-environment re-push is exact and B0's `bind_pos` stays
    unconsumed. The guard-failing case (batches anchored at old points
    under later rewrites) needs positional re-binding, a position-aware
    reload variant, and boundary re-materialisation — deferred to 0.C's
    anchored batches, where it first becomes expressible.
  - **Struct relations in the cone** re-mint ids on re-derivation exactly
    as §0.5 mode 2 prescribes (allocators monotone through
    `clearContents`); referents are themselves in the cone, so content
    stays closed (asserted by rendering).
  - The **reserved `~` + increments case (0.A8)** is now covered: a
    monotone ADD through a negation shrinks the complement, a deletion
    grows it; `reenter` refuses the neg cone toward `rerun`.
- **B3 — re-entry hygiene: decided for idempotent re-registration + husk
  clearing (same day).** `Daemon::push` now frees the task objects of any
  already-run same-name (= same content hash) stratum the push supersedes
  — its bindings dangle at the next reload anyway and it never re-runs —
  leaving a cheap husk (name/scc_id/fixpoint_msg; task destructors live in
  the retained `.so`, the hot-swap safety argument). Long-lived sessions
  hold live tasks only for each stratum's latest incarnation. The
  pausing.md §12 `bind()`-reuse seam (no pipeline growth at all) stays
  parked: re-entry cost is dominated by the whole-DB reload — B5's target
  — not task re-construction, so reuse buys little and costs a re-bind
  pass on every write/intern task class. Validated by a 30-cycle
  add-tuple/reenter stress (exact closure content throughout).
- **B4 — the routing rule lives in `compiler/session.rkt` (same day),**
  not inside `slog-run-file` — sessions are a different lifecycle than the
  one-shot batch run, and the module is the seam both the CLI harness
  (`tests/api/session-drive.rkt`, now a thin shell) and a future
  interactive front end drive. `make-session`/`session-open!`/
  `session-run!`/`session-batch!`/`session-flush!`/`session-close!`:
  - **Batch sets + collapse (§0.2):** `session-batch!` queues signed
    tuples per (tip, relation); a same-point opposite-signed pair
    collapses to nothing in the pending set; re-queuing a sign is
    idempotent. Batches apply only between fixpoints (the driver is
    synchronous, so refuseIfSuspended semantics compose trivially), and
    pausing composes through the same one-line-per-unit
    `(paused …)`→`(continue)` loop as runslog.
  - **`session-flush!` = the §0.5 routing rule:** apply all collapsed
    edits, take ONE introspection snapshot, union the per-relation cones
    (deduped, pipeline-ordered); all-adds + all-monotone union →
    replay-entry (`(route reenter N)`), with the delta-entry branch
    stubbed on `delta-flavor-available?` (always `#f` until 0.B5 —
    "delta-entry when compiled, replay-entry until then"); any deletion
    or neg/lat edge routes the whole union through clear-and-rerun
    (`(route rerun N M)`) — sound for everything, so mixing per-relation
    modes inside one flush is never attempted.
  - Anchors are tip-only in Phase-0-B4; the recipe protocol (0.C) adds
    point arguments, and the rebound guard already refuses the cases
    that need them.
- **B5 — delta-entry, single-hop first (same day).** The flavor is one
  planner seam plus one daemon seam:
  - **Compiler:** under the `delta-entry-flavor` parameter,
    `emit-stratum-cpp` re-plans the same job with the stratum's positive
    table/struct INPUTS added to the planner's dynamic set — the existing
    version machinery then emits per-position delta-driven variants for
    them (with the exact-semi-naïve `R_old` splits), replacing the
    run-once full scans; their delta indices and write tasks follow from
    the generic requisition flow. `build-cprog`'s dynamic set stays
    head-based, so input-driven read tasks register ONCE — exact, an
    input's delta is nonempty only at iteration 0. The plugin registers
    under `beginStratumDelta`; artifacts are `build/<hash>_delta.*`
    (underscore: the name rides into the daemon stratum name), -O0,
    compiled by `ensure-delta-so` LAZILY on the first increment ("delta-
    entry when compiled" — the first increment pays the compile, cached
    thereafter). Every `sbuild` carries the thunk.
  - **Daemon:** `beginStratumDelta` = no reload, every live index
    (registrations AND contents) survives, `needs_reload` stays armed for
    the next normal push; `stageTuple` = the batch enters the pending
    send-shards ONLY (→ iteration-0 delta; the run's write phase
    integrates it into full — the B6 exact-once path); and `addIndex` now
    **backfills a newly-registered full ordering from existing content**
    — a delta re-push registers fresh join orderings against a live
    database with no reload to populate them; an empty-but-registered
    index would silently under-derive. (No-op on all pre-existing paths:
    post-reload registrations find nothing indexed.)
  - **Routing:** `session-flush!` delta-enters when the union cone is a
    SINGLE stratum (all-adds + monotone). Multi-stratum cones stay on
    replay-entry: one cone stratum's novel derivations are not observable
    as the next one's delta pre-M0 — boundary capture is exactly M0's
    presence-transition machinery, so chaining lands there rather than
    growing a parallel set-semantics mechanism now.
  - Verified O(change): the fire audit of a one-edge increment into the
    TC fixture shows the copy rule firing exactly once and the recursive
    rule exactly 3× (the three new join pairs); three consecutive delta
    flushes keep exact closure content with live indices surviving across
    `beginStratumDelta` boundaries.
- **B6 — exact-once staging, asserted (same day).** One entry path:
  `stageTuple` → send-shards → iteration-0 delta (never insert-plus-
  restage). The test pins the delta flush's `$stat_fires` rows to the
  exact O(change) counts — a double-staged batch would double the
  once-variant fires and the pinned counts could not appear. This is the
  discipline M0's counters inherit (§0.3, §8).
- **0.C — anchored batches, the session log, and the recipe (same day).**
  The piece 0.B's guards refused toward, now built:
  - **C0, the positional machinery.** The run loops (finalize/reorg/
    buffers/accounting/orphan-restore) walk the whole VERSION REGISTRY,
    not just the latest environment -- closed versions cost a few
    empty-vector checks per iteration, and a positionally re-entered
    stratum's old-version reads/writes participate exactly like current
    ones. `(bind-at P)` arms one beginStratum..push window: the reload
    runs positionally (`reloadInsertBatchesAt` restages the
    P-environment -- each name resolved at P -- leaving later versions
    untouched; `needs_reload` stays armed for the next normal push) and
    registrations resolve through P. `refreshVersion(rel, ord)`
    re-materialises an inheritance boundary: clear, re-copy the
    predecessor, and RE-SEED the intern allocators from it -- without the
    re-seed, re-derivation downstream of a rebuilt predecessor mints ids
    the old copy already handed out (cross-version collision).
  - **C1 actions**: `(add-batch REL P ((v…)…))` / `(del-batch …)`
    (multi-tuple, one plugin per batch; P = -1 for the tip, else the
    version current at P; apply-only -- the driver owns propagation;
    lattice/struct targets refused), `(stage-batch …)` (the exact-once
    staging path, batched), `(bind-at P)`, `(clear-rel-at REL P)`,
    `(refresh-version REL ORD)`, `(lookup-at REL P v…)`, and
    `(import-delta DIR ((X Z)…))` -- the first real caller of
    importDatabaseBIN's rename map (the D4 seam), tip-anchored, advancing
    the position counter like open.
  - **C3, the anchored walk** (`compiler/session.rkt`). Anchors resolve
    against the live chains: an anchor at the LATEST version routes
    through the tip rule (delta/reenter/rerun, unchanged); an older
    version takes the walk -- apply the batch to the anchored version in
    place, then replay the pipeline suffix over the edited history.  Two
    passes: (1) forward over strata by position, growing the affected set
    through manifest HEADS -- a new `.meta` field, pure rule heads,
    because `dynamic-rels`' diagnostic side channels would make every
    stratum affected by every other -- with a stratum re-running iff it
    reads OR heads an affected relation; (2) position-ordered events,
    bindings < batch re-applies < strata at equal positions: an affected
    relation's binding at/after the anchor rebuilds (ordinal 0 clears,
    ordinal k>0 refreshes -- the anchored version itself is exempt, its
    rebuild IS the batch apply), logged batches at a rebuilt version
    re-apply right after its rebuild (span semantics: a batch anchored in
    a version belongs to the whole span, so it re-applies at the
    version's binding, not its wall-clock arrival), and re-run strata go
    bind-at + re-push.  Multiple anchored groups walk separately in
    ascending anchor order (simple over clever; they compose).  Deleting
    an independently re-derivable row keeps the replay-deletion caveat.
  - **The session log** (`session-applied`): per-(relation,
    version-binding) signed tuple sets with live same-point collapse --
    an add flushed and later deleted at the same version vanishes from
    the log entirely (§0.2's "absent from any subsequent save", tested);
    the walk's re-application draws from exactly this log, which is what
    makes rebuilt boundaries keep their batches.
  - **C2, the recipe.** `session-recipe` = the ordered open/run/
    import-delta steps + the collapsed batch entries anchored as
    `(batch REL (v ORDINAL) adds dels)` -- ordinals resolved against the
    live chains at serialisation, never raw positions (§0.4 stability).
    dbmeta.rkt gains `write-recipe`/`read-recipe`/`db-has-recipe?` and
    `recipe-digest` (covers step order, anchors, inline payloads
    verbatim, and bin payloads by directory content digest).  0.E1 wires
    it into the layer save.
  - **C4+C5.** The inline transport refuses > `inline-batch-max` (2048,
    env-overridable) tuples per (anchor, relation) per flush, pointing at
    the bulk door: a fact stream (docs/freeze.md §3, the external-
    producer contract) -> `slog-freeze` -> mini bin-db ->
    `session-import-delta!` (tested at 3000 rows).
    `externalize-recipe-payloads` copies payload dirs into a saving
    layer's `delta.<k>/` and rewrites their steps to relative
    `(delta k)` references; `recipe-payload-dir` is the load-side
    inverse.
  - **Guarded holes:** anchored replay across an import-delta step
    refuses (the walk cannot re-order an import; 0.E2's recipe rebuild
    owns it), as do anchors preceding every version of their relation.
- **Known imprecisions, accepted for B0:** un-anchored `add-tuple` and all
  imports mutate the *current tip* in place (a batch/link as its own
  version event arrives with 0.C/0.D); during a chain load, a layer's
  sample import + edits run before its `begin-segment`, so they land in
  the predecessor versions — final content is unchanged (the copy + replay
  dedup absorb it), and precise per-layer addressing on loads is 0.E2's
  recipe rebuild. Multi-`run` programs compile to one segment (recipe
  granularity, 0.C).
- **Tests:** `tests/session-tests.sh` (driven by
  `tests/api/session-drive.rkt`, the embryo of 0.B4's routing driver) —
  two-segment chains over plain tables with positional sizes/dumps; a
  struct+lattice session (id stability through copied allocators, payload
  ascent isolated to the new version) diffed against the from-scratch
  union-program oracle; cone-limiting over independent components (exactly
  one stratum re-fires); the cross-segment anchor filter (segment 1's path
  stratum stays parked while segment 2's absorbs the batch); and the
  rebound guard refusing toward B2. The whole compression battery
  regression-covers replayed-layer boundaries.

### 0.6 Deletion in Phase 0, and "must the front end split batches?"

Under the version model a **pipeline-point deletion is a forward
operation**: "delete T at P" defines the content of the version *at P*
(predecessor minus T) — it never reaches back into earlier versions, whose
readers correctly keep seeing T (§0.2's add-at-P/delete-at-P′ semantics).
Materialising it is §0.5 mode 2: rebuild the anchored version without T,
clear the downstream cone, re-run the suffix. Sound with zero counting
machinery, at stratum granularity.

Phase 0 scope, stated precisely: the headline deliverable is **additions
anchored anywhere** (per the 2026-07-08 decision), but the recipe format,
the collapse rules (§0.2), and the batch actions are **sign-complete from
day one** — they must be, for the same-point collapse semantics to be
well-defined — and since clear-and-rerun is being built anyway for
non-monotone *positive* cones, negative batches ride the same path at no
extra machinery. What Phase 0 does NOT attempt is *precise* (sub-cone)
deletion; the DRed^c phases keep the same driver and routing, replacing
"clear the cone" with "run the three-phase negative/reseed/positive sweep
over it" — deletions get cheaper, not different, and version boundaries
bound each sweep (§0.4's barrier property).

The W8 question — must an editor submit "delete these AST facts" then
"insert these" as two ordered updates? **No.** A mixed batch at one anchor
is fine at the API. Phase 0: the driver folds it into the point's batch set
(collapsing same-point add/delete pairs), rebuilds the version once, reruns
the cone once — no phasing exists to violate. Phases 1–2: the *engine*
imposes the phasing internally (the §4 sweep runs its negative fixpoint,
reseed, then positive fixpoint over whatever the batch contained); the
input protocol stays "a set of signed tuples". Front ends may still find
two batches natural; the semantics is identical either way, and identical
to one batch.

### 0.7 Renames and drops between segments

The motivating case (W5): program A produces `foo`; program B consumes
`bar`. Today you keep both relations and a prop rule — double storage, an
extra join, and a spurious stratum edge. Instead: **`(rename foo bar)` as a
recipe step between segments** — one relation, whose *name changes at a
pipeline point*; `(drop baz)` similarly ends a relation's visibility (and
reclaims its memory).

Semantics and checks (rewritten for the version model — renames get
*simpler* under it, not more complex):

- **Both are environment operations on the version chain (§0.4, §0.5) —
  zero data movement.** `(rename R S)` rebinds: `S`'s first version IS
  `R`'s last version (the same physical master index); `R` is unbound
  after. `(drop R)` unbinds: the name is free, but R's versions persist in
  the old part of the pipeline, addressable at old points (§0.4) — "kept,
  not destroyed" is the invariant. A later segment (re-)declaring `R`
  starts a **fresh, empty version chain** under that name (a severed
  boundary — no inheritance rule).
- A rename/drop sits *between* pipeline segments, where the relation's
  current version is complete (its stratum has run). After a drop, later
  reads of `R` are compile errors (until/unless re-declared).
- **Checks come free from manifest threading.** Programs already compile
  against a threaded manifest (thread-manifests, modules.rkt:792-797;
  update-manifest's arity/kind conflict fatals :756-790). A rename step
  transforms the manifest (move R's schema entry to S); a drop deletes it.
  Later segments' references then resolve — or fail loudly — with no new
  analysis. Stratified-negation interactions (a later `~S`, or `~R` after a
  drop) are caught by the same resolution.
- **Implementation: compiler-threaded AND daemon-visible.** The
  compile-time half is the manifest transform above. The runtime half is
  the environment update (§0.5): `(rename-rel R S)` / `(drop-rel R)`
  actions mutate the *current-position* name→version map — NOT a rekey of
  a global physical registry (the first draft of this section said "rekey
  the relations map"; under versions that is wrong — old bindings at old
  positions must keep resolving). Already-bound strata are unaffected
  (they hold direct pointers). Mind restoreOrphanRelations
  (`restoreOrphanRelations`, database.h), which resurrects import-only relations — a
  dropped binding must not qualify. The daemon seeing the rename keeps the
  `(schema)` action and **saved directory names** aligned with the visible
  schema — a save after a rename writes the final materialisation under
  `table.bar.…/`, and a fresh load of that layer needs no alias table.
- **Recipe + replay:** both ops are recorded as anchored recipe steps and
  re-applied at the same position on load. This *is* db-compression §12's
  designed-but-unbuilt `(rename R S)` / `(drop R)` edit ops — build once,
  serve both the in-place `edits` path and the session recipe.

### 0.8 Sub-phase 0.A: stratified negation, and hardening aggregation

> **STATUS: SHIPPED 2026-07-11** (A1–A8 complete; all worked as designed,
> plus scope decisions and one classification bug recorded in §0.8.1 below).

Why this gates Phase 0 rather than trailing it: (a) the routing rule (§0.5)
needs per-edge polarity — which does not exist because negation does not
exist; (b) adding negation *after* streaming ships would silently break the
"all cones are monotone" assumption baked into a counterless driver; (c) the
stratification checks negation forces are the same checks aggregation should
already have been getting.

**Current state (verified 2026-07-08):** `~` lexes to `'not` (lexer.rkt:60),
nothing consumes it; stratify.rkt builds positive-only edges
(body→head + co-head all-pairs, :115-141), Tarjan-condenses (:68-103),
levels (:145-158), merges same-level SCCs (:161-173) — no polarity, no
rejection, and its header (:20-22) documents stratification as purely an
optimisation. No runtime antijoin exists; the semijoin work added only the
positive `exists_probe` (operators.h:140-159). Aggregation is lattices-only
(min/max/count/flat/set/map valuespecs, modules.rkt:305-338) with a real
monotone-use calculus that runs per-stratum after stratification
(lattice-check.rkt:137-147, in-SCC monotonicity enforcement :185-366) — but
unbounded-recursion termination is a warning, not an error (:390-435), and
none of it is exercised by a single `~` test (`grep '~' tests/*.slog` is
empty).

**The build (design):**

- **Syntax.** `~(rel a b …)` as a body atom only — the `'not` token prefixed
  to an ordinary clause; constants (`~(foo x 1)`), wildcards (`~(foo x _)`),
  and lattice-relation keys (`~(best k)` = "no value at key k") all
  permitted. No head negation; no `!`/`not` synonyms.
- **Safety (range restriction).** Every variable of a negated atom must be
  bound by a positive body atom (or be a constant/wildcard). Checked in the
  front end with source provenance.
- **Stratification becomes semantic.** Edges carry polarity; after
  condensation, any negative edge with both endpoints in one SCC is a
  compile error ("negation through recursion — not stratified", naming the
  rule and cycle). Nothing else changes: a cross-SCC negative edge already
  forces `level(head) ≥ level(body)+1` like any edge, and same-level merged
  SCCs are mutually unreachable, so *negated relations are always closed
  (strictly lower stratum) at read time* — exactly the property the runtime
  leans on. Update the stratify.rkt header: stratification is now
  load-bearing.
- **Runtime = negated semijoin.** A negated atom compiles to an
  **`absent_probe`** — the one-line negation of `exists_probe`
  (operators.h:140-159) — placed after the positive join has bound its
  variables, with index requisition on the negated relation for the
  bound-column prefix riding the same flow the semijoin filters added
  (operationalization.rkt:210-283). Because the negated relation is closed,
  the probe always targets a full (never delta) index and needs no
  semi-naïve versions. This is deliberately the *smallest possible* runtime
  footprint for negation.
- **Aggregation hardening.** The lattice calculus already implements
  "Tier-1 stratified aggregation falls out free" (docs/lattices.md §5.3;
  §7A.6 here). 0.A adds: negation-over-lattice-keys (above); polarity
  awareness in lattice-check (a negated read is a non-monotone read —
  in-SCC cases are already excluded by the stratification error, so this is
  bookkeeping, plus tests); and a decision recorded here: the
  unbounded-min/max recursion **warning stays a warning** (it is a
  termination heuristic, not a soundness issue — same stance as
  lattice-check today).
- **Polarity metadata out the back.** Per relation: `cone(R)` and the
  monotone bit per cone edge (negation edges; lattice-read edges per §0.5),
  written into the stratum sidecar manifests for the driver. This is also
  M2's "per-body-clause same-SCC bit" (§6.4) arriving early — tag the IR
  once, serve both consumers.
- **Incrementality interaction, stated plainly:** a positive batch into R
  where some downstream rule reads `~R` is a *non-monotone* update (new
  facts can retract derived ones). The routing rule (§0.5) already handles
  it — that cone is clear-and-rerun. Under Phase 2, negation slots into
  DRed^c as signed propagation through absent_probe with flipped sign
  (standard DRed treatment); nothing in 0.A's design forecloses it.

#### 0.8.1 As built (2026-07-11): scope decisions and deviations

The design above shipped as written. What it under-specified, decided
during the build:

- **Clause form through the stack.** `~(rel a b …)` is
  `(syn prov ~ inner-atom)` from the parser on; at the flat level every
  argument is a plain variable — constants lift into positive const
  clauses (safe: they always ground), and `_` wildcards gensym to the
  established `__`-prefixed dead-var convention (seq-expand's), marking
  the probe's *unconstrained* columns. `ir-shared.rkt` owns the accessors
  (`neg-clause?`/`neg-rel`/`neg-args`/`neg-wildcard-var?`); planning
  classifies negated atoms as **guards** (fire once inputs ground, only
  prune, never drive — no semi-naïve versions, as designed).
- **Rejected forms** (each a located error; tests/diag-tests.sh §6–12):
  head negation; nested patterns under `~` (their positive reading —
  "the struct exists AND is absent" — diverges from pure negation; bind
  positively first, then negate over the variable/id); collection and
  sequence literals under `~` (same reason, caught pre-desugar in
  collections.rkt); `|` under `~` (the or-split would distribute into
  alternative RULES, reading `~(A|B)` as `~A OR ~B` — a De Morgan
  violation; write the conjunction `~A ~B`); double negation; negating
  structs and enums (interned existence is an evaluation artifact);
  negating demand-moded judgments (absence of a lazily-grown answer is
  not observable; demand.rkt).
- **Side-channel-grown relations cannot be negated** — a class the design
  missed: `error` (+ the error-arm structs, rejected as structs anyway),
  extern oracle answer tables, decomposition targets (`R_has`/`R_at`),
  and the sequence-occurrence relations (`$seq_at`/`$seq_atr`). All are
  re-derived through side channels whose rows land in *iteration 1's
  delta* on a seeded run, so a static absent probe at iteration 0 would
  observe false absence. Positive readers survive this because they are
  delta-driven (monotone); an absent probe is not. Rejected in
  type-system.rkt's negated-atom case.
- **Same bug, facts-stratum flavor (FIXED):** `ground-fact-rules`
  (P0.5's EDB split) classified a rule reading only *constant-class*
  relations as ground — pulling `rule ~(h _) --> (f 1)` into the level-0
  facts stratum, where its once-task absent probe raced h's own
  iteration-0 writes (caught by the compression oracle: replay derived a
  row the oracle lacked). A rule with any negated read is now never
  ground-classified; its heads are genuine IDB, regenerated by replay.
- **Runtime.** `absent_probe` is *not quite* the one-line negation of
  `exists_probe`: at K = 0 (an all-wildcard atom = emptiness test) the
  bound prefix names no bucket, so emptiness consults every bucket —
  `exists_probe<A,0>` would consult only `buckethash(0)`.
  `absent_probe_lat` mirrors it over the payload map (`~(best k)` = "no
  value at key k", key columns only). Both always probe FULL indices of
  closed relations; `absent`/`absent-lat` c-ops mirror the semijoin
  `exists` op and may also sit in the crule's PRE slot (a negation whose
  key is all-constant/all-wildcard fires before the driver, aborting the
  whole task).
- **A6 decision recorded:** the unbounded-min/max recursion warning
  (lattice-check.rkt) **stays a warning**. Polarity bookkeeping added: a
  still-ascending lattice value cannot key a negated atom (the probe's
  answer could flip as the value ascends); negating a still-ascending
  relation itself is already the stratification error.
- **A7 metadata shape.** Per-stratum `.meta` gains
  `(reads (R kind …) …)` with kinds `pos`/`neg`/`lat` (lattice-value
  reads conservatively non-monotone per §0.5), and per-rule
  `(neg-body …)`/`(lat-body …)` alongside the existing rec/same-scc
  fields. cone(R) falls out by chaining manifests; a cone is monotone
  iff every edge is plain `pos`. No consumer yet — 0.B's driver reads it.
- **Tests.** Goldens `neg_diff` (set difference), `neg_reach`
  (complement-guarded recursive reachability), `neg_const` (`~(f x 1)`,
  string constants), `neg_wild` (wildcards, emptiness, pre-slot probe),
  `neg_lat` (lattice keys), `neg_struct_key` (negation keyed by a
  positively-bound struct id); rejection units in diag-tests.sh (§6–13);
  polarity unit tests in tests/unit/stratify-tests.rkt; negation ×
  compression in the oracle-diff default set (neg_reach, neg_wild — all
  per levels). The `~` + increments case stays reserved for 0.B's
  harness as planned.

### 0.9 Hot-linking a database into a live session

W6, made precise: `(link DB ((X Z) …)) @P` as a recipe step means "the
relations X… of `data/DB` — a database with its own chain and programs — are
imported, under names Z…, as a positive batch anchored at pipeline point P"
(creating a new version of each Z there, like any other update event, §0.4).

- **Mechanism = import with a name-map.** `importDatabaseBIN` already
  reconciles schema by name and content-remaps all four id spaces
  (database.h:2779-2812, 2883-2992); the name-map is a parameter it doesn't
  take yet — and it is precisely db-merge.md's designed-but-unshipped
  rename/`#:prefix` conflict policy (:125-130), generalised. One new
  parameter serves both features. A relation filter (import only X…) rides
  along.
- **Provenance.** The manifest records the link edge (name + stamp), so the
  DAG knows `data/DB` is now an input: `slog db tree` shows it, staleness
  applies to it, `gc`/`rm` respect it, and **replay materialises DB's chain
  recursively** (db-load-steps already recurses and memoises diamonds)
  before importing at the recorded position.
- **Downstream, it's just a batch** into Z — routed by §0.5 like any other
  (monotone cone → replay/delta-entry; non-monotone → clear-and-rerun).
- **Honesty note inherited from db-merge §7.2:** a linked DB's facts arrive
  as *facts* — merge-then-run is a monotone over-approximation; if the link
  target's grounding later changes upstream in ITS chain, propagation into
  *this* session is by that chain's staleness + re-replay, composing with
  edit-and-propagate. (Under Phase 2, a re-replayed link diffs old→new into
  signed batches instead.)

### 0.10 On disk: the delta layer, freeze, and the counters-ready format

The layer format (db-compression §8) grows three things:

```
data/<name>/
  META                # + fields: recipe? (bool), counted? (Phase 1)
  recipe              # NEW — the session's pipeline steps + anchored batches
                      #   (supersedes `edits` for this layer's own history;
                      #   `edits` remains the mutate-an-ancestor verb):
                      #     (run <segment-id>)                   → prog.sexpr segment
                      #     (rename R S) | (drop R)              → at their pipeline position
                      #     (batch + REL @P (inline (v …) …))    → small, baked
                      #     (batch - REL @P (inline (v …) …))
                      #     (batch + REL @P (bin delta.3))       → bulk, bin-backed
                      #     (link DB ((X Z) …) @P)
                      #   @P = the anchor: a pipeline point, stored robustly as
                      #   (relation, version-ordinal) / boundary event (§0.4) —
                      #   never a raw SCC index; P may reach back into ANCESTOR
                      #   layers' pipelines (back-insertion, this layer's key
                      #   power) — ancestors themselves are never touched.
                      #   Batches are stored COLLAPSED (§0.2): same-point
                      #   add/delete pairs are absent; adds and deletes at
                      #   different points both persist.
  delta.<k>/          # NEW — the k-th bin-backed payload: a self-contained
                      #   mini bin-db (canonical writer; own value.strings/
                      #   value.nodes; closure-complete), applied by import
  prog.sexpr          # may now hold MULTIPLE segments (entry per run step)
  <relation dirs>, signature, signature.edited   # as today
```

- **Stored vs. recomputed: intermediate versions are NOT stored.** A save
  writes the recipe (with anchors + payloads) and, per policy, the
  materialisation of each relation's **final** version. Every intermediate
  version is derivable — load replays the recipe and rebuilds the whole
  versioned pipeline in memory, after which point-addressed queries (§0.4)
  work exactly as they did live. This is the same store-the-recipe-not-the-
  derivation bet db-compression already made, applied to time as well as to
  tuples. (If introspection-heavy workflows later want *warm* old versions
  on load without replay, persisting selected intermediate versions is a
  compatible extension — a `per`-like knob over time; parked.)
- **Load = replay the recipe with the live machinery.** `db-load-steps`
  gains the new step kinds; each executes exactly as it would in a live
  session (materialise version → route → fixpoint). One code path for W1 vs
  W2, by construction. The recipe digest (extending `db-chain-edits-digest`,
  §11.2's re-baseline machinery) covers batch payload hashes, anchors,
  renames, and links, so drift verification composes unchanged: the layer's
  `signature` is computed over its post-recipe fixpoint at save and checked
  after replay.
- **What a pure-batch layer keeps.** Its "IDB" for sampling/signature
  purposes = the relations its anchored cones recomputed (they now differ
  from every ancestor's signature); unchanged relations are the ancestors'
  problem. `per` applies to that cone set as usual. (Detail to pin at
  implementation: signature scope = cone rels + target rels; inherit
  ancestors' signatures for the rest.)
- **Default policy shift (accepted 2026-07-08): databases are incremental
  by default.** The normal save keeps master indices whole
  (`per = 100 %` for session saves — auto-`per` compression remains an
  explicit opt-in for archival layers), and — once Phase 1 lands — persists
  the two counters with them: a per-bucket sidecar `k.counts.bin` (two s64
  per tuple, in `0.bin` tuple order) beside each `k.bin`, gated by META
  `counted?` + `compiler-stamp` (counters are invalid across semantic
  compiler changes even when the tuple set isn't — §8A.3, now revised from
  "defer" to "planned default"). A stamp-matching `per=100` load then skips
  even the count-establishing round: **load → immediately streamable and
  incrementally maintainable**. Roots need no counts file (EDB counts are
  definitionally `(1,0)`).
- **Freeze.** `--flatten` at save time exists; add `slog db freeze NAME
  [--as NEW]` = load/replay the chain, `writeDatabaseBIN` the
  materialisation as a standalone root (`kind 'flat`), no manifest, no
  recipe — the sanctioned way to cut history (share data without its
  recipe), accepting it can no longer be replayed, edited through, or
  hot-linked *as a chain*.

### 0.11 The granularity ladder (how Phases 1–2 refine Phase 0)

The three phases are one design at three recompute granularities — the
driver, routing rule, recipe, and IO built in Phase 0 are permanent:

| | update handled by | granularity | new machinery |
|---|---|---|---|
| **Phase 0** | semi-naïve append (monotone) / clear-and-rerun cone (else) | stratum | version chains + environment, re-entry, cone metadata, anchored batches, recipe IO, negation |
| **Phase 1** (M0–M3) | signed counts; deletion precise where non-recursive | tuple (acyclic) | Count/SCount values (per version), signed emit/aggregate, persisted counters |
| **Phase 2** (M4–M7) | DRed^c 3-phase per segment, bounded by version barriers | tuple (general) | candidate set C, reseed, barrier; lattice/rank unification |

Reading the table bottom-up is the implementation dependency; reading it
top-down is the user experience: behaviour is fixed from Phase 0 on, and
each phase only makes updates cheaper. In particular Phase 0's
clear-and-rerun *is* the "resident-stratum re-binding" work item that §6.5
and §8A.5 already identified as shared with db-compression — after Phase 0
it exists, and DRed^c's three-phase driver (§4) drops into the same seam.

---

## 1. Why this is hard: pure counting is unsound for recursion

The tempting design is: give every tuple a *proof count* (number of derivations),
increment on insert, decrement on delete, and remove a tuple when its count hits 0.
This is finite and terminating in slog (we count *one-step* derivations from
currently-present facts, driven by semi-naïve iteration, **not** derivation trees — so
the count of a tuple in a cycle stays finite). And it is **sound and precise for
non-recursive programs**.

It is **not sound for recursive programs**, because a count tells you *how many* proofs
a tuple has, never *whether any of them is still grounded in surviving input*. Across a
recursive cycle, tuples keep each other's counts positive while collectively having lost
all external support — the **unfounded self-supporting cycle**.

### Canonical counterexample (Motik et al.)

```
R(y,x) :- R(x,y).          % symmetric closure; R is EDB + IDB
EDB: R(a,b)
```

After inserting `R(a,b)`: counts are `R(a,b)=2` (1 from the EDB fact, 1 derived from
`R(b,a)`), `R(b,a)=1`. Now **delete EDB `R(a,b)`**: decrement its EDB proof → `R(a,b)=1`,
still `>0`, so it survives; because it survives, `R(b,a)` keeps its derivation and stays
at 1. Final state `R(a,b)=1, R(b,a)=1` — **both wrongly retained**. They prop each other
up forever ("analogous to why reference counting is not a general GC strategy").

The same shape appears as `reachable(a),reachable(b)` in a two-cycle after the `source`
fact that founded them is deleted: the edge cycle survives and mutually supports the
pair even though nothing grounds it anymore.

### Why the naïve intuition (the TC/`path` case) *seemed* to work

Transitive closure over edges deletes correctly under pure counting **only because the
deleted EDB (`edge`) appears inside every recursive proof step**, so deleting an edge
drives all dependent counts to zero directly. The failure case is deleting a fact *below*
a cycle that stays structurally intact. General soundness therefore requires re-checking
**foundedness**, which counts alone cannot do.

### Theory backing this

- Counting a tuple's derivation trees over a cycle is *infinite*; incremental view
  maintenance by counting diverges for recursive views over cyclic data.
- Datalog over a semiring converges **iff the semiring is stable**; ℕ (bag / counting
  semantics) is **not stable**. A finite per-tuple derivation-tree count is not even
  well-defined for recursive Datalog over cycles.
- This is exactly the gap DRed (Delete and Re-derive) was invented to fill.

See §12 for citations.

---

## 2. The chosen algorithm: DRed^c

We adopt **DRed^c** (counting-augmented Delete/Re-derive): Hu, Motik, Horrocks,
*"Optimised Maintenance of Datalog Materialisations"*, AAAI 2018. It combines the
precision of counting on the easy (non-recursive) part with DRed's foundedness repair on
the recursive part, and — crucially for slog — **it does not require evaluating rules
"backwards"** (matching a head to a fact and running the partial body as a query). That
property is why it fits slog's forward, push-operator engine.

DRed^c gives us:

- **Full precision on non-recursive derivations** — counters decide membership exactly,
  no over-deletion, no re-derivation.
- **Sound recursion** — over-delete the suspect region, then re-derive what is still
  founded, restoring the least fixpoint (kills unfounded cycles).
- **A cheap re-derivation** — counters identify the re-foundable frontier without
  backward search.

### Alternatives considered (and why not, for now)

| Approach | Correctness | Fit to slog | Verdict |
|---|---|---|---|
| Pure counting | Unsound for recursion | Trivial | Rejected (see §1) |
| **DRed^c** | Sound | *Extends* current engine; no backward rules | **Chosen** |
| DBSP nested incremental circuits | Sound, O(change) | Codegen rewrite (integration/differentiation ops, nested recursive circuits) | Future |
| Differential dataflow (timestamp lattice) | Sound, O(change) even deep in recursion | Engine *replacement* (versioned traces, progress tracking); ~2–4× memory | Future |

---

## 3. Core concepts

### 3.1 Two counters per fact

Each fact carries two signed counters in its relation's master index:

- **`nonrec`** — number of derivations via rules whose body is entirely in *earlier
  strata* (including base/EDB rules). These are **foundation** proofs.
- **`rec`** — number of derivations via rules with a body predicate in the **same SCC**
  as the head. These are **circular-capable** proofs.

`present(t) := nonrec + rec > 0`. The classification of each *rule* as recursive vs
non-recursive is static (see §4.5), so each rule bumps exactly one of the two counters.

The two counters are the whole reason DRed^c beats plain DRed:

- `nonrec > 0` ⟹ the fact is grounded in an earlier stratum and is **provably still
  true** after any update within this stratum → it is a hard barrier that stops
  over-deletion.
- After the negative fixpoint, `rec > 0` on an over-deleted fact is an **O(1) certificate
  that a surviving derivation still exists** (support that did not route through the
  deleted region) → it can be re-founded in one step, with its count already correct,
  without re-firing its rules.

### 3.2 Two roles per tuple (the key mental model)

Two different things flow through evaluation; do not conflate them:

1. **Counter updates** happen when a tuple is produced (or loses a derivation) **as a
   consequence** of a join. This is the only place `(nonrec, rec)` mutate.
2. **Delta records** `(tuple, sign)` are **propagation signals** — "this tuple changed
   presence; use it as a **premise** to drive the next round of joins." The `sign`
   (+1 appeared / −1 disappeared) tells the downstream aggregate whether joins *through*
   this premise should add to or subtract from **its consequences'** counters.

A delta record therefore carries **no `(Δnonrec, Δrec)` for the tuple itself** — that
tuple's counters were already finalised when it was produced as a consequence. Every
tuple plays both roles: as a consequence its counters are updated; as a premise it is a
signed signal driving further joins.

### 3.3 Presence ≠ counts during an update

Between phases a fact can be **over-deleted** (removed from the live set) while `rec > 0`.
So membership cannot be read off the counters during an update. We track over-deleted
facts explicitly in a transient **candidate set `C`** (§3.4).

### 3.4 The candidate set `C`

`C` is the per-update set of **over-deleted** (speculatively removed) facts. It is
required because counters alone cannot encode "removed but rec>0". It is **not a new
kind of structure**: it is an instance of the existing delta/index machinery
(`BTreeIndex<A>` / the `deltaindices` handles) given a different *lifecycle* —
"accumulate until reseed" instead of "merge into the main index." One handle per
relation, populated only in the negative phase.

---

## 4. The algorithm

Process the program's strata in **topological order** (lowest first). Within a stratum,
run three phases in sequence. Topological order is what makes it a single sweep with no
mutual iteration: when stratum *k* is processed, every earlier stratum is final, so each
fact's `nonrec` counter (which counts only earlier-stratum support) is **stable**
throughout — that stability is what makes the `nonrec>0` barrier sound.

```
for each stratum S in topological order:
    1. NEGATIVE fixpoint   (apply − input deltas to S; over-delete; accumulate C)
    2. RESEED scan         (adjudicate C: rec>0 → re-found; rec==0 → delete)
    3. POSITIVE fixpoint   (apply + deltas: reseeds + genuine inserts; rebuild)
    // facts that truly died escape S as − input deltas to later strata
    // facts newly true escape S as + input deltas to later strata
```

### 4.1 Negative fixpoint (over-deletion)

Drive `Δ⁻` through the **same** compiled join pipeline as forward evaluation. The
aggregate step decrements consequence counters:

```
over-delete(h):                      # when a consequence h loses presence and nonrec==0
    if h not in C:
        C.insert(h)                  # explicit candidate set
        push (h, -1) onto Δ⁻         # propagation signal → decrement h's consequences
    # h stays physically in the main index for now; its counters remain
```

Propagation rule (in the generic aggregate, selected by polarity):

- Decrement the appropriate counter of every consequence reached.
- If a consequence has `nonrec > 0` → **protected**: record the decrement, **do not
  propagate** (stop).
- If a consequence has `nonrec == 0` and its presence drops → **over-delete** it (add to
  `C`, push `−1`), regardless of remaining `rec`.
- A fact is over-deleted at most once per update (the `not in C` guard); later reaches
  only decrement its counters further.

After this fixpoint settles, for every fact `rec` equals the number of its derivations
through **surviving** (non-over-deleted, non-deleted) facts — because over-deleting a
supporter decremented it. Hence `rec > 0` ⟺ re-foundable from a surviving fact.

### 4.2 Reseed scan (between phases)

Iterate **`C`** (not the relation — `O(|over-deleted|)`):

```
reseed():
    for t in C:
        if t.rec > 0:
            push (t, +1) onto Δ⁺      # presence signal to rebuild t's cone; counters already correct
            C.erase(t)                # t survives
        else:
            delete t from the main index   # (0,0): truly gone for now; may be re-derived below
```

Deleting the `rec==0` candidates here (rather than leaving them "absent but physically
present") keeps the positive phase's full-index joins correct **without a per-tuple
liveness branch on the hot path** — after reseed, the index holds only live tuples.

The `(t, +1)` pushed for a re-founded fact is a **propagation signal only**. `t`'s own
`(nonrec, rec)` are already correct; the increments it triggers land on **`t`'s
consequences** (the downstream cone the negative phase wrongly tore down).

### 4.3 Positive fixpoint (insertion / rebuild)

Drive `Δ⁺` (reseeds **plus** genuinely new inserted facts) through the same join
pipeline. The aggregate step increments consequence counters; a consequence whose
presence rises `0 → +` is pushed onto the output delta and (if it was a `rec==0`
candidate deleted at reseed) re-inserted fresh. This rebuilds the torn-down cone and
relearns any fact that is genuinely re-foundable — including facts that dropped to
`(0,0)` mid-update but come back once their founding route is re-established.

### 4.4 The uniform aggregate

The single place counters mutate; identical in both phases except for the propagation
predicate, which is chosen by a polarity flag:

```
aggregate(c, incoming signed derivations, polarity):
    was = present(c)
    c.nonrec += Σ(nonrec-tagged signs)     # "local contributor count" for this iteration
    c.rec    += Σ(rec-tagged signs)
    now = present(c)
    if was != now:
        if polarity == NEGATIVE and now == false and c.nonrec == 0:
            over-delete(c)                 # add to C, push (c,-1)
        elif polarity == NEGATIVE and now == false and c.nonrec > 0:
            pass                           # protected: decremented but not propagated
        else:  # POSITIVE, presence 0 -> +
            push (c, +1) onto Δ⁺
    # counters mutate here (c as consequence); the pushed record is a premise-signal
```

Note the "was == now" case (count changed, presence didn't): **do not propagate**. This
is the finiteness property — re-derivations of an already-present tuple bump its count
but never re-enter the delta, so counts stay finite and each fixpoint terminates.

---

## 5. Worked examples

### 5.1 Unfounded cycle stays deleted (Motik)

```
R(y,x) :- R(x,y).   EDB: R(a,b)
init:  R(a,b) = (nonrec 1, rec 1)     R(b,a) = (nonrec 0, rec 1)
delete EDB R(a,b):
  negative: R(a,b).nonrec 1→0; presence still true (rec 1) but nonrec==0 →
            over-delete R(a,b), push −1 → decrements R(b,a).rec 1→0 →
            over-delete R(b,a), push −1 → decrements R(a,b).rec 1→0.  C = {R(a,b),R(b,a)}
  reseed:   both have rec==0 → delete from index. No Δ⁺ seeds.
  positive: nothing to propagate.
  result:   both gone.  Correct.
```

### 5.2 Over-delete then one-step re-found, and a (0,0) relearn (diamond + chain)

```
path(x,y) :- edge(x,y).             % nonrecursive → nonrec
path(x,z) :- path(x,y), edge(y,z).  % recursive    → rec
EDB edges: a→b, a→e, e→b, b→c        % a reaches b directly AND via a→e→b

init:  path(a,b)=(1,1)   path(a,c)=(0,1)   path(a,e)=(1,0)  path(e,b)=(1,0)  path(b,c)=(1,0)

delete edge a→b:
  negative: path(a,b).nonrec 1→0; nonrec==0 → over-delete path(a,b), push −1
            → path(a,b),edge(b,c) decrements path(a,c).rec 1→0 → (0,0) →
              over-delete path(a,c).           C = {path(a,b)@(0,1), path(a,c)@(0,0)}
  reseed:   path(a,b).rec = 1 (from path(a,e),edge(e,b), both surviving) → push (path(a,b),+1); keep.
            path(a,c).rec = 0 → delete from index.
  positive: path(a,b) drives path(a,b),edge(b,c) → re-derive path(a,c): rec 0→1, re-inserted.
  result:   path(a,b)=(0,1), path(a,c)=(0,1).  Correct (a→e→b→c keeps both).
```

`path(a,b)` was re-founded cheaply in the **reseed** (its own `rec` survived).
`path(a,c)` genuinely hit `(0,0)` and was **relearned only in the positive fixpoint**,
once `path(a,b)` re-propagated.

---

## 6. Where every change lands

Two layers, and the split is what preserves "compile each rule once":

- **Per-rule compiled code** — the `ReadTask` join pipeline emitted inline by
  `emit-cpp.rkt`. Direction-agnostic: reads a delta, probes indices, hands
  presence-transition records to the aggregate. **The sign is data**, not code — so this
  is compiled **once per rule** and shared across the negative and positive phases.
- **Generic per-arity machinery** — `WriteTask<A>`, `InternTask<N>`, `InternStructTask<N>`
  in `operators.h`, instantiated per relation/bucket. **Every asymmetry between the
  phases lives here or in the driver**, never in per-rule code.

### 6.1 Data structures — `daemon/index.h`, `daemon/database.h`

*(anchors 2026-07-08: `BTreeIndex<A>` over `tlx::btree_set<array<u64,A>>` is
index.h:61; the map-valued `BTreeMapIndex<KA>` over `tlx::btree_map<array<u64,KA>,
u64>` ALREADY EXISTS at index.h:104 — built for lattices, it is the working
precedent for a value-carrying master index and for §7A.7's "extensible
index-value slot". A relation's index arrays live in `Relation::indices`
(database.h:128) with a parallel `deltaindices` table (database.h:129), selected
by `getIndex(ord, delta)` (database.h:506); per-bucket
`intern_allocators`/`getInternAlloc`/`getStructId` at database.h:138/298/263.)*

- Master index value changes from a set element to a mapped value:
  - relations: `btree_map<std::array<u64,A>, Count>` where `struct Count { s64 nonrec; s64 rec; };`
    — mechanically, a `BTreeMapIndex`-style index with a struct value instead of
    the lattice's single `u64` payload word.
  - structs: value `struct SCount { u64 id; s64 nonrec; s64 rec; };` — **`id` stays in
    the value so it survives over-delete/reseed** (see §7).
  - Counters live in the **value**, never in the key (else the same tuple at two counts
    becomes two keys and dedup/probe ordering breaks). Use **signed** `s64`: negative
    weights must exist *in transit* during propagation.
- Delta/probe indices that don't need counts can stay sets.
- Add, per relation, a handle for the transient candidate set `C` (§3.4) — reuse the
  existing `deltaindices` machinery; populated only in the negative phase.
- Relation gains: stratum id and, per index, the rule-derived rec/nonrec tag needed by
  the aggregate.

### 6.2 Operators — `daemon/operators.h`

*(re-anchored 2026-07-08 to the push-operator refactor; the read phase is now a
family of fused template operators with pausable `_sliced` variants, and the
lattice path already ships a value-carrying merge task — both work in our
favour.)*

- Read phase — **unchanged, sign-agnostic**: `read_delta` (l.40) /
  `read_delta_sliced` (l.62, pausing), `join_probe` (l.94) / `join_probe_sliced`
  (l.116), `exists_probe` (l.148, semijoin filter), `join_all` (l.166),
  `join_probe_lat` (l.182), `join_all_lat` (l.196). The `_sliced` variants are
  where pausing lives — and ONLY here, which is what keeps §6.5's
  pausing-composes-for-free claim true.
- `emit` (l.214): today it **dedup-skips at emit time** (`head_index->contains`)
  — replace with a **counting, signed** producer that records `(tuple, sign)`
  tagged with the rule's static rec/nonrec bit into the batch — **no emit-time
  dedup-skip** (we must count re-derivations of existing tuples). Removing this
  skip is also why the exact-once delta convention becomes load-bearing (§8/§8A:
  a double-fired instantiation was harmless under set semantics, it corrupts
  counts).
- `emit_temp` (l.232): temps are stratum-transient plumbing (no persistence) —
  sign-agnostic, likely unchanged.
- `emit_struct` (l.253): same signed treatment, but the id slot stays a 0
  placeholder — `InternStructTask` owns dedup + id (already true today, by
  design comment at l.248-251).
- `InternTask` (l.371) → **counting aggregator** implementing §4.4: sum per-tuple signed
  contributions, update `(nonrec, rec)`, apply the polarity-selected propagation
  predicate (over-delete + `C` on negative; push Δ⁺ on positive).
- `InternStructTask` (l.497): same aggregation, preserving `id`; presence 0→+ allocates
  id only for genuinely new content (content-dedup via `lower_bound` on content
  columns, l.525-532; id mint at l.537); presence →0 tombstones (does not
  recycle id).
- Lattice tasks `MapWriteTask` (l.411) and `LatticeInternTask` (l.454) already
  implement value-carrying merge with change-splitting (subsumed contributions
  nulled, ascending values rewritten in place and propagated) — the §7A.7
  "value-carrying delta" hook is half-built; DRed_L (docs/lattices.md) slots in
  at M7.
- **New generic task: `ReseedTask<A>`** — §4.2 scan of `C`.
- `WriteTask` (l.331): learn to *remove* index entries (reseed's `rec==0` deletes and the
  final sweep), not only insert.

### 6.3 Codegen — `compiler/emit-cpp.rkt`

- Emit `emit` → the counting/signed producer, parameterised by the rule's static
  `IS_REC` bit and a phase-supplied sign.
- Instantiate the new generic tasks (`ReseedTask<A>`, counting `InternTask`) per relation/
  bucket alongside the existing `WriteTask`/`InternTask`/`InternStructTask`
  registration (the `addTask`/`addIndex` wiring; read tasks register at
  emit-cpp.rkt (`addTask`/`addTaskSeeded` registration) with the `static?` once-only flag).
- No per-rule deletion variant is emitted — the negative phase reuses the same
  per-position semi-naïve delta-join variants already generated for insertion
  (join-planning.rkt picks the delta-driven clause per version; the planner is
  the 2026-07 staging/scheduling/versions rewrite).

### 6.4 Compiler pass — `compiler/stratify.rkt` (mostly built) + tagging (net-new)

**Current state (baseline — REWRITTEN 2026-07-08; the earlier version of this
section predated the 2026-07 compiler rewrite and described a compiler with no
stratification at all).** The compiler now HAS genuine SCC stratification:

- `compiler/stratify.rkt`: `stratify-rules` builds the rule dependency graph
  (body→head edges, plus all-pairs among a rule's own heads so co-heads land in
  one SCC), runs Tarjan (`tarjan-scc-ids`, :68), condenses, and assigns
  `scc-level = 1 + max(pred levels)` (:145). Rules are grouped into **one
  stratum per DAG level** — independent same-level SCCs are merged (:163).
  `rule-head-rels` / `rule-body-rels` (:53/:57) expose per-rule relation sets.
- `compiler/compile.rkt`: `compile-strata` (:345) drives it — **one stratum →
  one `.so`**, run in topological order by the driver with a daemon reload
  between strata (`beginStratum`/`needs_reload`, daemon.h:153/:64). A
  `#:split-facts?` mode pulls iteration-0 (body-less) rules into a level-0
  facts stratum (db-compression P0.5). `jobs->db-partition` (:299) already
  computes the per-run `idb-rels`/`edb-rels`/`mixed-rels`/`strata-range`/
  `productive-rels` partition.
- Per-stratum, `dynamic-rels` = the union of the stratum's own head relations
  (operationalization.rkt:84 → join-planning.rkt `dynamic?` :102 →
  emit-cpp.rkt `static?` :447): a read task whose driver clause reads only
  lower-stratum relations is registered once-only; others iterate.

**The useful structural fact:** because an inter-SCC dependency edge forces a
strictly greater level, two SCCs merged into one stratum are mutually
unreachable — so *a rule's body relation lies in the same stratum iff it lies in
the same SCC*. Hence the DRed^c classification needs no new analysis:

> a rule is **recursive** (bumps `rec`) iff some body relation ∈ its stratum's
> `dynamic-rels`; else **non-recursive** (bumps `nonrec`). Body-less/facts
> rules and EDB ingestion are `nonrec` by definition.

What remains for M2 is therefore **tagging and threading, not analysis**:

- Expose the per-rule rec/nonrec bit (and, for §7A's monotonicity checks, the
  per-body-clause same-SCC bit) as an explicit IR attribute — today the
  information exists only implicitly via `dynamic-rels` membership at emit time.
- Thread the bit into `emit`'s counter choice and the aggregate's barrier
  (§6.2), and into the stratum manifest the driver consumes.
- The daemon still has no SCC/stratum concept of its own beyond the resident
  stratum pipeline; the `Stratum::dynamic_rels` seam comment
  (database.h:877-879) and the daemon.h header note (:22-26, "re-running an old
  stratum requires re-binding") mark exactly where the three-phase driver (§4,
  §6.5) attaches. That re-binding work is shared with db-compression's
  edit-and-propagate ambition (db-compression.md §12) — build it once.

### 6.5 Driver — `daemon/database.h` fixpoint loop

*(re-anchored 2026-07-08: the per-stratum fixpoint is `runLoop` (database.h:1348)
with `runPhase` per phase (:1329) — write → read (suspendable) → intern →
`reorgAll` per iteration; the budgeted outer entry is `continueStratum` (:1437),
driven by `Daemon::continueRun` (daemon.h:291); `reorgDelta` is Relation-level
at :557; termination is `latest_any_rec` (:1062), set by `finalizeAll` on any
non-empty fresh delta and consumed by `EndIterCompletion` (:3037) → ACT_FIXPOINT
when nothing new; deferred reloads run through `reloadInsertBatches` (:2957) /
`beginStratum` (daemon.h:153).)*

- Generalise the phase loop to carry a **polarity** and run the three-phase, per-stratum
  schedule of §4.
- Between negative-phase iterations, accumulate the delta into `C` instead of merging
  into the main index; between positive-phase iterations, merge as today
  (`finalizeAll`/`reorgAll`).
- **Termination keys on presence transitions, not count changes** — the invariant
  maps directly onto `latest_any_rec`: `finalizeAll` must register only tuples
  whose PRESENCE changed (the §4.4 aggregate already pushes only those into the
  outgoing delta, so the existing "non-empty new delta" test keeps working) —
  otherwise a re-derivation that only bumps a count spins the loop. Revisit the
  arity-0 / `reorgDelta` guard from the earlier OOM fix under this new invariant.
- **Pausing (`docs/pausing.md`, now shipped) composes for free.** Pausing lives
  entirely in the read (delta-producing) phase — precisely the `_sliced`
  operators of §6.2 plus `ReadCompletion`'s mid-read suspend (:3013) — and is
  *exact* (park a continuation at the outer-loop position, resume there — no
  redo), while the counting aggregate (where `(nonrec,rec)` and `C` mutate) runs
  to completion. So a pause only ever leaves un-consumed delta records and never
  touches the counters — keep it that way (any counting phase that needs pausing
  must be resumable by an exact cursor, not by discard-and-rerun, since the
  counters are not idempotent). One NEW caveat since checkpoint-on-pause
  shipped: `writeDatabaseSerialBIN` (:2377) checkpoints a paused PARTIAL
  database; a partial fixpoint's counters are not reconstructible from its
  tuples, so once counting lands a checkpoint must either persist the counters
  or be treated as witness-only on resume (replay from EDB re-establishes
  counts) — see §8A.

### 6.6 Input protocol — `daemon/slogd.cpp` + `compiler/actions.rkt`

*(re-anchored 2026-07-08: the daemon protocol is one plugin path per line —
`run_stdin` (slogd.cpp:137) / `run_tcp` (:170); every verb beyond
`continue`/`continue-boundary`/`close` is a compiled action plugin from
`actions.rkt`. A positive single-fact path ALREADY exists: the `add-tuple`
action (actions.rkt:77) → `Daemon::addTuple` (daemon.h:240) →
`insertTupleAllIndices` + `needs_reload`, built for db-compression's
edit-and-propagate.)*

- Extend the `add-tuple` action family with a **sign** (`del-tuple`, or a signed
  batch action) feeding per-thread delta shards rather than direct index
  insertion — the existing action-plugin path is the natural transport; no new
  wire protocol is needed. *(2nd revision: this is Phase 0's batch protocol,
  §0.3 — inline `add-batch`/`del-batch` plugins for small payloads,
  import-of-a-mini-bin-db for bulk, link-with-name-map for whole databases.
  Phase 1/2 change what the daemon does with a batch, not how it arrives.)*
- Batch a set of changes and run one three-phase sweep per batch.
- db-compression's `edits` files (`(add-tuple REL v…)`, applied at layer
  boundaries on load) become the persistent face of the same mechanism: once
  DRed^c exists, `(del REL v…)` edits stop requiring full downstream re-replay
  (db-compression.md §12) and instead drive a negative sweep through the
  resident strata.

---

## 7. Structs: specific concerns

- Structs are derived (via `emit_struct`) and interned (`InternStructTask`), mapping
  content → id. With counting the master index maps content → `(id, nonrec, rec)`.
- **Id stability across over-delete/reseed is mandatory.** Other tuples embed a struct's
  id; if reseed/rederivation hands out a fresh id, every referent dangles. Keep `id` in
  the value, **tombstone at presence 0, never recycle** an id until a foundedness-safe
  reclamation pass proves no live referent remains (initially: never reclaim).
- Per-bucket id allocators (`operators.h` intern allocators) must not treat a tombstoned
  slot as free.

---

## 7A. Aggregation, rank, and lattice-valued recursion (plan-ahead)

> **See also `docs/lattices.md`** — the full batch-first design for
> lattice-valued relations (declarations, monotone-use calculus, runtime,
> milestones), written to slot into this section's M6/M7. It sharpens one
> point here: value-change deltas should travel as replacement *pairs*
> `(key, old, new)` so ⊑-increasing changes route through the monotone phase
> (IncA/DRed_L "change splitting") instead of the negative fixpoint.
> *2026-07-08: lattices L0+L1 are now SHIPPED* — `BTreeMapIndex` (index.h:104),
> `LatticeInternTask`/`MapWriteTask` (operators.h:454/:411), and the batch
> change-splitting behaviour (subsumed contributions nulled, ascending values
> rewritten in place and propagated) exist in the runtime, as do the extern
> set/map collection lattices (arena.h `merge_spec`). The §7A.7 "extensible
> index-value slot" and "value-carrying delta" hooks are therefore half-built
> already; M6/M7 extend working machinery rather than introducing it.

Aggregation is deferred past the first incremental milestones (M0–M4 do plain recursion),
but the substrate must **anticipate** it, because the mechanism that makes recursive
aggregation work is the *same* mechanism that makes recursive deletion precise. Get the
value slot, the delta format, and the rel-env right now and aggregation slots in without a
rewrite.

### 7A.1 An aggregate is a semiring fold — so it inherits stability exactly

An aggregate is a `⊕`-fold over a group. Putting one inside recursion therefore converges
**iff its semiring is *stable*** — the same condition from §1 (Abo Khamis et al., PODS
2022). Concretely:

- **tropical `(min,+)` is stable** → recursive `MIN`/`MAX` converges (shortest path,
  min-label connected components). Safe recursively.
- **`ℕ (+,×)` is not stable** → recursive `SUM`/`COUNT` diverges over cycles — the *exact*
  same failure as plain derivation counting in §1. Not safe recursively.

So recursive aggregation is not impossible; it is possible **precisely for the stable
(monotonic) aggregates**. The escape hatch and its practical test have names:
**monotonic aggregation** (Ross & Sagiv, PODS 1992 / JCSS 1997) and **pre-mappability
(PreM)** (Zaniolo, Yang, Das, Shkapsky, Condie, Interlandi, TPLP 2017; DeALS/BigDatalog),
which says exactly when `min`/`max` (and constrained `count`/`sum`) may be pushed inside a
fixpoint while preserving the least-fixpoint answer.

### 7A.2 Two kinds of per-fact state — keep them separate

Do not conflate foundedness with the aggregate value; they are orthogonal and both needed.

1. **Foundedness state** of the aggregate *result* tuple `agg(group,value)` — tracked with
   the same `(nonrec, rec)` / rank machinery as any derived tuple.
2. **Aggregate value state** — function-specific auxiliary state:

   | Aggregate | State per group | Deletion |
   |---|---|---|
   | `COUNT` | contributor count | trivial (−1; retract at 0) |
   | `SUM` / `AVG` | running sum + count | trivial (subtract; count says when empty) |
   | `MIN` / `MAX` | **whole contributor multiset** (sorted `BTreeIndex` by `(group,value)`) | *hard*: deleting the current extreme needs the next one |

   (Mumick/Quass/Mumick, SIGMOD 1997 — COUNT is kept precisely *so deletion works*;
   Palpanas et al., VLDB 2002 — the MIN/MAX auxiliary structure.)

Two rules that make this fit our framework:

- **Aggregate over the *set* of founded contributors, each once — not weighted by
  derivation count.** A contributor's `rec/nonrec` count governs *its* membership; while
  present it contributes once. The aggregate value is driven by contributors' **presence
  transitions** (the `±1` signals from §3.2/§4.4), never by raw counts.
- **A value change is `retract-old + insert-new`.** `agg(g,5) → agg(g,7)` emits
  `−agg(g,5), +agg(g,7)` — ordinary signed deltas, no new downstream mechanism.

### 7A.3 Rank *is* a recursive-min aggregate (the unification)

The `rank` from §"count+rank" (minimum derivation depth) is itself a recursive `MIN`
aggregate over the tropical semiring: `rank(t) = 1 + min over derivations of max(premise
ranks)`. So **foundedness-rank maintenance and recursive `MIN`/`MAX` aggregation are the
same computation**, and their hard case is the same: deleting the input that supplied the
current best = **decremental shortest path** = recompute the value from survivors and
propagate the regression. Build rank repair for foundedness and you have recursive
monotonic aggregation for free (and vice-versa).

### 7A.4 Rank-rebuilding vs. the `rec/nonrec` algorithm — same shape, finer grain

`(nonrec, rec)` is a **coarse, membership-only, 2-bucket approximation of rank**:
`nonrec>0` ≈ "grounded below this stratum" (a low, bounded rank); `rec`-only ≈ "rank
determined inside the SCC." DRed^c resolves the in-SCC part **bluntly** — over-delete the
region, rebuild from the boundary. Rank-rebuilding is the **fine-grained generalization**:

| | DRed^c `(nonrec,rec)` | rank-rebuilding (tropical) |
|---|---|---|
| per fact | 2 integer counters | 1 lattice value (+ how to find next-best) |
| resolves foundedness by | over-delete region + forward rederive | recompute value from survivors, propagate *regressions* only |
| over-work | can tear down + rebuild a whole region | touches only facts whose value actually changes |
| deletion style | invalidate-then-rebuild | Ramalingam–Reps decremental-SSSP |
| also gives you | membership | membership **and** the aggregate value |

Both share the skeleton — *localized recomputation triggered by deletion, bounded by a
well-foundedness/stability property* — and both face the same memory/compute trade: to
find the next-best derivation *without* re-running rules you must store per-derivation
info (heavy); DRed^c and forward-rebuild avoid that by re-deriving from the boundary.
`(nonrec,rec)` is simply the degenerate case of rank; rank is the version that also does
aggregation.

### 7A.5 The dovetail: user-declared stable semiring / semilattice

The crisp payoff — **one mechanism, parameterised by a semiring.** Let a relation declare
the lattice/semiring it aggregates over: a domain, `⊕` (combine — associative,
commutative; idempotent for a semilattice), `⊥`, and the order. The engine maintains the
lattice value incrementally with the shared rank-rebuild machinery. Built-in instances:

- **Boolean present-lattice** → plain membership (the DRed^c default).
- **tropical depth** → foundedness rank (internal, for recursive relations).
- **user lattices** → `min`/`max`/shortest-path/custom monotonic aggregates.

**Stability is the compile-time admissibility check:** a stable/monotone semiring may be
used *recursively* (Tier 2 below); a non-stable one (`SUM`/`COUNT`) is allowed only
*stratified* (Tier 1) or **rejected** with a clear error — the ℕ-not-stable boundary made
into a diagnostic. (Lattice-typed relations echo Bloom^L: Conway, Marczak, Alvaro,
Hellerstein, Maier, SoCC 2012.)

### 7A.6 Implementation tiers

1. **Tier 1 — Stratified aggregation (safe baseline; covers ~all practical use).** Require
   the group relation in a *strictly lower stratum* (M2 gives this; enforce + reject
   same-SCC here). Keep `(count,sum)` per group for `COUNT`/`SUM`/`AVG`; a sorted
   `BTreeIndex` multiset per group for `MIN`/`MAX`. Contributor presence-transitions drive
   it; value changes emit `retract-old + insert-new`. **Deletion is fully precise — no
   over-delete/rederive** (non-recursive w.r.t. its input). Drops straight into the
   three-phase driver as a higher-stratum relation.
2. **Tier 2 — Recursive monotonic aggregation (stable semiring).** Allow same-SCC
   `MIN`/`MAX`/user-lattice when PreM/monotonicity passes. Value = lattice element per
   group; lattice-semi-naïve for insertion (monotone, easy); deletion = the rank-repair
   path, **shared with foundedness**.
3. **Tier 3 — Reject recursive non-stable aggregation** (`SUM`/`COUNT` over cycles) unless
   acyclic grounding / a PreM certificate is proven.

### 7A.7 Forward-compatibility hooks to build during M0–M4

Even though aggregation ships later, these choices in the early milestones avoid a rewrite:

- **Extensible index-value slot.** Do not hardcode `struct Count { s64 nonrec, rec; }` as
  the only shape — make the per-relation value a configurable type so a relation can later
  carry a rank / lattice accumulator (or a `(count,sum)` / multiset handle) instead of
  bare counters.
- **Value-carrying delta records.** Allow a delta record to carry a payload, not only a
  sign, so `retract-old + insert-new` value changes and lattice deltas fit the same
  transport (§3.2 already separates the premise-signal from the counter update — extend
  the signal to optionally carry a value).
- **A semiring/lattice annotation slot in the rel-env / manifest**, default =
  support-counting (membership). This is where a user later declares `min`/`max`/custom.
- **M2 must also expose, per rule, the same-SCC bit per body predicate** — needed to
  classify recursive-vs-stratified aggregation and to run the monotonicity/PreM check.
- **Anticipate an aggregate rule form in the IR** (group-by vars + combine op) even if
  unimplemented, so `operationalization.rkt` doesn't need reshaping later.

## 8. Known caveats to design in now

- **Semi-naïve delta convention — now load-bearing in BOTH directions.** Negative
  propagation must respect the standard "delta-in-one-position against the
  pre-deletion state" convention, or two deleted supporters of one derivation
  double-decrement the consequence. slog already generates the per-position
  delta-join variants for insertion; the negative phase reuses them, but the
  **driver must sequence old/new state consistently.** The positive direction has
  the same requirement once counting lands: **iteration 0 (delta = the whole
  reloaded database) must fire each rule instantiation EXACTLY once.** Under set
  semantics a double-fire was absorbed by dedup and invisible; under counting it
  permanently corrupts counters. This is the headline M0 test (§10) — verify the
  2026-07 join planner's per-position versions partition instantiations exactly
  at the reload/iteration-0 boundary, not just mid-run.
- **Termination invariant** (§6.5): presence transitions, not count changes.
- **Struct id stability** (§7).
- **Demand supplementaries are DRed-transparent** (2026-07-10,
  docs/demand.md §5): the `$sup...` relations the demand transform emits
  for unkeyable answer-return joins are ordinary derived tables with
  ordinary rules — they take counters, retract, and re-derive like any
  relation, and their deletion deltas run the same keyed plans that make
  derivation cheap.  No special-casing anywhere in DRed^c; on
  compression replay they regenerate (derived, never pinned).
- **`C` lifecycle correctness:** after the positive phase, any candidate still at `(0,0)`
  that was not rebuilt is physically removed; anything rebuilt has a positive count and
  stays. (In the reseed formulation of §4.2, `rec==0` candidates are removed at reseed
  and only re-inserted if the positive phase re-derives them — equivalent.)

---

## 8A. Composition contract with db-compression (added 2026-07-08)

`docs/db-compression.md` shipped (2026-07-07) with loading defined as
**always-replay-from-origin**, and its layers may drop derived tuples from disk.
This section pins how that composes with DRed^c — the constraints are real but
all favourable.

### 8A.1 Dropped tuples on disk do NOT thwart incrementality

`(nonrec, rec)` are a deterministic function of `(EDB + edits, program)`: the
least fixpoint is deterministic, and the counters count one-step derivations
from it, which semi-naïve enumerates exactly once. So **any load path that
replays to fixpoint under a counting engine ends with exact counters**, no
matter how much was dropped on disk. Compression drops tuples, never
information — "load, replay, counts established, fully incremental from there"
is the operating model. Deletion **edits** compose the same way: today they are
sound via full re-replay (db-compression.md §12); under DRed^c they become the
negative input batches of §4.

### 8A.2 The one soundness trap: never ingest the kept sample as counted presence

A compressed load imports each layer's kept sample before replaying. Under
counting, a kept tuple ingested with any positive count is corrupted forever —
replay re-derives it and adds the true counts *on top*. Worse than imprecise: a
spurious `nonrec > 0` makes the fact **permanently undeletable** (the §4.1
barrier protects it from every future negative sweep). The contract:

- kept **table/lattice tuples** are ingested as *witness only* — they do not
  enter the live set with counts; replay re-derives and counts them. (Their
  seeding value was always marginal — db-compression.md §13: seeds never reduce
  join work, only rounds.)
- kept **struct-heap rows** are ingested as **tombstones** — id preserved,
  counters zero, absent-until-rederived. This is *exactly* the §7 tombstone
  shape DRed^c needs anyway: `InternStructTask` content-matches the tombstone,
  reuses its id, and bumps its counters — id stability and count correctness
  from one mechanism.

### 8A.3 `per = 100 %` loads come out incremental-ready for free

The `per=100%` "immediate fixpoint self-check" fires every rule once over the
full database and derives nothing new — under counting, **that single round IS
the count computation** (one-step derivations from the fixpoint). Expensive
layers kept whole therefore pay nothing extra to become DRed^c-ready. Corollary:
a `--trust` load that skips the check would leave counters at zero — trust-mode
and incremental-readiness are mutually exclusive unless counters are persisted.

*(Revised 2026-07-08, 2nd revision: counter persistence is now the PLANNED
DEFAULT, not deferred — §0.10. Databases are incremental by default; session
saves keep master indices whole and, once Phase 1 lands, write a per-bucket
`k.counts.bin` sidecar (two s64 per tuple, in tuple order) beside each
`k.bin`, gated by META `counted?` + a `compiler-stamp` match — counters are
invalidated by any semantic compiler change even when the tuple set is not,
in which case the load falls back to the count-establishing replay round.
Roots synthesise `(1,0)` and store nothing. This makes a stamp-matching
`per=100` load immediately streamable with zero replay — the trust-mode
corollary above dissolves for such loads.)*

### 8A.4 Checkpoints need a count story

`writeDatabaseSerialBIN` checkpoints a paused PARTIAL database
(db-compression.md P2.3). Partial-fixpoint counters are not reconstructible from
the tuple set, so when counting lands either (a) the checkpoint format persists
counters, or (b) a resumed checkpoint is treated as witness/tombstones per §8A.2
and the replay restarts from the EDB (monotonicity makes any subset a sound
seed; only the count-establishing work is repeated). Decide at M0.

### 8A.5 Mutual payoffs

- **DRed^c gives the compression DAG O(change) edits:** edit-and-propagate stops
  re-replaying dependent layers and instead drives one three-phase sweep through
  the resident strata. The "re-firing an old resident stratum needs index
  re-binding" caveat (db-compression.md §12) is exactly the §6.5 driver work —
  build it once.
- **Compression gives DRed^c its struct-id reclamation pass:** §7 says
  tombstoned ids are never recycled online; a compressed save+reload compacts
  them for free (count-zero tombstones are not saved; replay re-mints densely).
- **The compression harness gives the count oracle:** `tests/compression/run.sh`
  already content-diffs a compressed load against a from-scratch run; extending
  it to also diff *counters* tests the whole §8A contract in one shot (§10).

---

## 9. Phased implementation plan (restructured 2026-07-08, 2nd revision)

Three phases (§0.11 is the one-table summary). **Phase 0** ships the
user-visible incremental workflows with no counting machinery and builds the
substrate — stratified negation, stratum re-entry, batch transport, recipe
IO — that Phases 1–2 then make precise. The milestone names **M0–M7 are
preserved** inside Phases 1–2 (external docs reference them). Every
sub-milestone is independently testable and delivers value before the next.

### Phase 0 — Forward-incremental sessions (design: §0)

**0.A — Stratified negation + aggregation hardening (first; gates the rest — §0.8).
SHIPPED 2026-07-11 — all eight items done; see §0.8.1 for as-built decisions.**

- *A1 — parse `~`.* ✓ Consumed the `'not` token in `parse-atom` as a
  body-atom prefix producing `(syn prov ~ atom)`; constants lift positively,
  wildcards ride the `__`-dead-var convention; no head negation.
- *A2 — safety check.* ✓ Negated-atom variables must be positively bound;
  checked in typecheck-rule with rule location (binders = relation atoms,
  struct patterns, constants, computes incl. head-side).
- *A3 — semantic stratification.* ✓ Negative edges kept with rule
  provenance (stratify.rkt); post-condensation intra-SCC negative edge is
  the "negation through recursion — not stratified" error naming rule +
  cycle; header claim rewritten (stratification is load-bearing).
- *A4 — operationalize.* ✓ Negated atom → `absent`/`absent-lat` filter
  c-op scheduled as a guard, index requisitioned on the bound-column
  prefix riding the semijoin flow; may sit in the PRE slot.
- *A5 — runtime.* ✓ `absent_probe` + `absent_probe_lat` (operators.h);
  K = 0 emptiness consults every bucket (a plain negated exists_probe
  would not). Always full-index, never sliced, no semi-naïve versions.
- *A6 — aggregation hardening.* ✓ Negation-over-lattice-keys (keys-only
  arity, payload-map probe); lattice-check rejects still-ascending values
  keying a negated atom; the unbounded-min/max warning STAYS a warning.
- *A7 — polarity/cone metadata.* ✓ `.meta` gains per-stratum
  `(reads (R pos|neg|lat …) …)` + per-rule `(neg-body …)`/`(lat-body …)`;
  cone assembly documented at write-stratum-manifest (consumer = 0.B).
- *A8 — tests.* ✓ Six `neg_*` goldens; rejection units (diag-tests.sh);
  stratify polarity unit tests; negation × compression oracle cases (which
  caught the ground-fact-rules classification bug, §0.8.1); the `~` +
  increments case stays reserved for 0.B's harness.

**0.B — The version substrate, stratum re-entry & the increment driver (§0.4, §0.5).**

- *B0 — version registry + environment (the load-bearing new piece).*
  **SHIPPED 2026-07-11 — see §0.5.1 for as-built decisions.**
  Physical relations keyed by version; per-pipeline-position name→version
  map; `getRelation`-by-name resolves through the environment of the
  position being bound (the former global map is now the latest-position
  environment; ownership in `rel_registry`, chains in `rel_bindings`).
  Alias-if-unchanged / full-copy-if-written materialisation (§0.4); version
  creation at driver-announced `begin-segment` boundaries (copy
  predecessor; anchored-batch materialisation lands with 0.C). Same cached
  `.so` bindable at many positions (the W9 requirement — `bind_pos` exists,
  B1 wires it). Versioned addressing resolves "R at P" to the last write
  ≤ P (`(pipeline)`, `(sizes-at P)`, `(dump-rel R P)` actions).
- *B1 — cone-limited replay-entry.* **SHIPPED 2026-07-11 — see §0.5.1.**
  Driver-side: apply batch to the anchored
  version, re-push cached cone-strata `.so`s in topological order (mechanics
  exist: `beginStratum`/`reloadInsertBatches`); skip strata outside the cone using A7 + recipe-level
  cone metadata. *(As built: cone + anchor filter + latest-binding/monotone
  guards in the session driver's `reenter`; guarded cases route to B2;
  promotion into runslog's batch flow is B4.)*
- *B2 — per-relation clear + clear-and-rerun.* **SHIPPED 2026-07-11 — see
  §0.5.1.** `clearContents` on one
  version (contents only, registrations persist); version rebuild minus
  retracted tuples (`del-tuple`/`removeTuple`); driver orchestration
  "rebuild anchor version, clear cone versions, then B1" (`rerun` op).
  Struct relations in the cone re-mint ids as designed. *(Guard-failing
  anchors — positional re-binding + boundary re-materialisation — deferred
  to 0.C where anchored batches make them expressible.)*
- *B3 — re-entry hygiene.* **SHIPPED 2026-07-11 — see §0.5.1.** Either the pausing.md §12 `bind()` re-bind seam
  (reuse resident task objects; pipeline stops growing) or idempotent
  re-registration on re-push with old-task clearing — pick after measuring
  B1's pipeline-growth cost. *(Decided: re-registration + husk clearing in
  `Daemon::push`; the reload, not registration, dominates re-entry, so
  bind()-reuse stays parked.)*
- *B4 — routing rule in runslog.rkt.* **SHIPPED 2026-07-11 — see §0.5.1
  (placed in `compiler/session.rkt`, the session-lifecycle module, rather
  than the one-shot `slog-run-file`).** positive+monotone → delta-entry when
  compiled, replay-entry until then; else clear-and-rerun; queue batches to
  stratum boundaries (refuseIfSuspended semantics); fold incoming updates
  into per-(point, relation) batch sets with same-point collapse (§0.2);
  compose with pausing budgets.
- *B5 — delta-entry (O(change)), default-on, lazily compiled.* **SHIPPED
  2026-07-11 (single-hop; see §0.5.1) — multi-stratum chaining rides M0's
  presence transitions.** Delta-
  preserving reload variant (stage only the batch, not the whole DB);
  delta-driven variants for cross-stratum body relations (join planner:
  dynamic-rels ∪ inputs) compiled as a separate cached flavor
  (`build/<hash>_delta.O0.so` as built) **on first increment targeting that stratum's
  inputs** — no surface declaration, fully-incremental is the default; an
  opt-out flag for one-shot batch runs. Required (not optional) by Phase 1 —
  replay-entry's re-fire is dedup-absorbed today but would double-count.
- *B6 — exact-once staging discipline.* **SHIPPED 2026-07-11 — see
  §0.5.1.** One entry path for a batch's tuples
  into delta (no double-stage across reload), asserted by test now (the
  pinned fire-audit counts of a delta flush), load-
  bearing at M0 (§0.3, §8).

**0.C — Batch protocol, anchors & the session recipe (§0.2–§0.4).
SHIPPED 2026-07-11 — see §0.5.1 for as-built decisions (anchored walk,
positional machinery, heads manifest field, log collapse); C2's save/load
wiring lands with 0.E as planned.**

- *C1 — actions.* `(add-batch REL @P ((v…)…))`, `(del-batch REL @P …)`
  (multi-tuple add-tuple generalisation in actions.rkt, plus the anchor);
  `(import-delta DIR [(X Z)…] @P)` = import a mini bin-db as a batch payload;
  **versioned queries**: `lookup`/`dump-rel`/`sizes` gain an optional
  pipeline-point argument, plus a pipeline-introspection action (dump the
  point→(name→version) map) so a front end can re-derive the pipeline from a
  live daemon (§0.4 — API seams now, surface syntax later).
- *C2 — recipe format.* `recipe` file + dbmeta.rkt (de)serialisers; steps as
  §0.10 with anchors stored as (relation, version-ordinal)/boundary events;
  digest extension of `db-chain-edits-digest` covering payload hashes and
  anchors.
- *C3 — session log + collapse.* The driver maintains per-(point, relation)
  signed batch sets, collapsing same-point add/delete pairs live (§0.2);
  save serialises the collapsed sets. Optional informational
  observed-stratum field per batch.
- *C4 — bulk path.* Document + test CSV→root→link for bulk client data; fix
  the inline threshold (~2k) above which the driver refuses inline transport.
- *C5 — payload placement.* Bin payloads written/moved into the saving
  layer's `delta.<k>/`; relative references from `recipe`.

**0.D — Renames, drops, hot-links (§0.7, §0.9).**

- *D1 — daemon actions.* `(rename-rel R S)` / `(drop-rel R)` as
  **environment operations** (§0.5, §0.7): rebind/unbind the name in the
  current-position map — NOT a rekey of the physical registry (old versions
  at old positions must keep resolving); dropped bindings exempt from
  restoreOrphanRelations resurrection; both refuse-if-suspended; `(schema)`
  reflects the current environment.
- *D2 — manifest ops.* Rename/drop transforms in update-manifest threading
  (modules.rkt:756-797); later-segment resolution errors come free.
- *D3 — recipe + replay,* shared with db-compression §12's `(rename R S)`/
  `(drop R)` edit ops — one implementation for both.
- *D4 — import name-map.* Optional rename-map + relation-filter parameters on
  `importDatabaseBIN` (database.h:2760-3022) — also discharges db-merge's
  unshipped conflict policy (db-merge.md :125-130).
- *D5 — `(link DB map)` step.* Manifest edge recording; recursive
  materialisation on replay (db-load-steps recursion, dbtool.rkt:171-191);
  routed downstream as a batch.

**0.E — Session save/load/freeze + the workflow harness (§0.10).**

- *E1 — delta-layer save.* Save-after-increments always creates a new linked
  layer (extend write-compressed-metas, runslog.rkt:644-692); pure-batch
  layers (empty program) supported; signature scope = cone/target relations;
  default `per=100` for session saves.
- *E2 — load = replay the recipe* with the live streaming machinery (extend
  db-load-steps + the runslog step loop, runslog.rkt:404-425), **rebuilding
  the versioned pipeline in memory** so point-addressed queries and further
  anchored batches work identically post-load (§0.10's "loading a DB is
  loading a session"); verify via recipe digest + signatures (§11.2
  machinery).
- *E3 — `slog db freeze NAME [--as NEW]`* (load, write flat root).
- *E4 — the workflow harness* (tests, §10): stream-equivalence fuzzer with
  anchored/back-inserted batches, save/load/continue chains, collapse-rule
  and versioned-query cases, rename/link/negation-cone cases, api-tests.sh
  keep-alive additions.

**Phase 0 exit criterion:** for every harness program, any split of its EDB
into base + randomly-interleaved signed batches **anchored at arbitrary
pipeline points, including points inside ancestor layers** — applied live
(W1), applied after a load (W2), saved mid-stream and resumed elsewhere
(W3/W4), routed through a rename (W5) or a hot-link (W6) — produces a
database content-equal to the from-scratch run on the equivalent
desugared/edited program, with every saved link verifiable, point-addressed
queries resolving correctly (last-write-≤-P), same-point add/delete pairs
absent from saves, and `slog db freeze` cutting an equal flat copy (W7).

### Phase 1 — The counting substrate & precise non-recursive deletion (M0–M3)

1. **M0 — Signed-count substrate.** `Count`/`SCount` index values; signed deltas;
   counting `emit`/`InternTask` with presence-transition propagation. Insertion still
   monotone, but now counter-based. Verify identical results to today plus correct
   counts — headline tests: **iteration-0 exact-once firing** (§8, and 0.B6's
   staging discipline) and the **compressed-load count oracle** (§8A.5, §10).
   The §8A.2 witness/tombstone ingestion rule for compressed loads and the
   §8A.4 checkpoint decision land here too — they define what "load a saved
   db under counting" means. Phase 0's replay-entry mode is retired for
   streamed batches in favour of delta-entry (0.B5) — re-firing over the
   whole DB double-counts.
2. **M1 — Bidirectional input protocol.** The Phase 0 batch actions (0.C1)
   gain signed *semantics*: negative payloads feed delta shards instead of
   triggering clear-and-rerun. The wire/recipe format does not change.
   **M1.5 — persisted counters** (§0.10, §8A.3 revised): `k.counts.bin`
   sidecars, META `counted?`, compiler-stamp gating, fallback recount round.
3. **M2 — rec/nonrec tagging (stratification EXISTS since the 2026-07 rewrite;
   the same-SCC/polarity IR attribute EXISTS since 0.A7).** Thread the
   per-rule bit into `emit`'s counter choice and the manifest. No behaviour
   change yet for insertion. *Was "build SCC + topological stratification
   from scratch"; now tagging + threading only, partly discharged by 0.A7.*
4. **M3 — Non-recursive deletion.** For acyclic strata, signed counting is sound and
   complete both directions. The §0.5 routing rule sends deletions with
   acyclic cones down the counting path instead of clear-and-rerun. Ship full
   incrementality for non-recursive programs. Big, safe milestone.

### Phase 2 — Recursive deletion & aggregation (M4–M7)

5. **M4 — Recursive deletion (DRed^c).** Candidate set `C`, negative fixpoint with the
   `nonrec>0` barrier, `ReseedTask`, three-phase driver. The resident-stratum
   re-entry/re-binding it needs (§6.5, §8A.5) **exists after Phase 0** — the
   three-phase sweep drops into the 0.B seam. This is the hard milestone.
6. **M5 — Struct GC discipline.** Tombstoning, id stability, (optional) safe
   reclamation — noting §8A.5: a compressed save+reload already compacts
   tombstoned ids, so online reclamation can stay "never".
7. **M6 — Stratified aggregation** (§7A Tier 1). `COUNT`/`SUM`/`AVG` via `(count,sum)`;
   `MIN`/`MAX` via a per-group sorted multiset; value changes as `retract-old+insert-new`.
   Fully precise deletion; no new recursion machinery. Requires only the M2 strata + the
   §7A.7 hooks (and composes with 0.A's negation checks — a non-stable
   aggregate is admitted exactly where a negation would be).
8. **M7 — Recursive monotonic aggregation** (§7A Tier 2). User-declared stable
   semiring/semilattice; lattice-valued relations; rank-precise foundedness sharing the
   same rank-rebuild path. This is where `(nonrec,rec)` optionally generalises to a full
   tropical rank (§7A.4), and where DRed_L retires §0.5's conservative
   "lattice reads are non-monotone edges" cone rule. Tier 3 rejection of
   non-stable recursive aggregates lands here too, as a compile-time
   diagnostic.

The Phase 0–M4 substrate should already carry the §7A.7 forward-compatibility
hooks so M6/M7 are additive, not a rewrite.

---

## 10. Testing strategy

### Phase 0: the workflow harness (no counters to check yet — content is the oracle)

Everything below is oracle-diff against a from-scratch run on the final EDB,
in the style of `tests/compression/run.sh`:

- **Stream-equivalence fuzzer (the core Phase 0 test).** For each harness
  program: split its EDB into base + k batches; anchor batches at random
  pipeline points (not just "now" — including back-insertions into earlier
  points and, in chained runs, into ancestor layers' pipelines) via each
  transport (inline / mini-bin / link), positive first, deletions once 0.B2
  lands; assert final content-equality with the from-scratch run on the
  equivalent edited input. Fuzz over (program, split, anchors, batch order,
  transport, thread count).
- **Version semantics.** (a) add T at P, delete T at the same P → absent
  from the save and from every version (collapse, §0.2); (b) add T at P,
  delete T at P′>P → readers between P and P′ see T's consequences, readers
  after P′ don't, and BOTH steps appear in the save; (c) point-addressed
  queries: R updated at 17 and 29 → `R@24 ≡ R@17`, default query = latest;
  (d) a dropped/renamed-away name remains addressable at old points; a
  re-declared name starts an empty chain.
- **`.so` reuse across positions (W9 seed test).** Push the same cached
  stratum `.so` at two pipeline positions with different environments
  (post-rename); assert each instance binds its position's versions and no
  recompile occurred (cache hit observed).
- **Save/load/continue chains (W3/W4).** Run → stream → save → load →
  stream → save → load; assert each load's replay verifies (recipe digest +
  signatures), the final content matches one straight-line run, and
  point-addressed queries answer identically before the save and after the
  load (the rebuilt pipeline, §0.10). Include a pure-batch layer (no new
  program) and a back-inserted anchor into an ancestor layer in the chain.
- **Negation cone correctness.** A `~R`-guarded program fed positive batches
  into R: derived facts must *retract* (clear-and-rerun routing); the same
  program under a batch into an unrelated relation must NOT rerun the
  negation cone (cone-limiting observed via the daemon's fixpoint traces).
- **Rename/drop pipelining (W5).** A-produces-foo → `(rename foo bar)` →
  B-consumes-bar, live and through a save/load; a post-rename re-declaration
  of `foo` is a fresh relation; a read of a dropped name is a compile error.
- **Hot-link (W6).** Link an old DB's X as Z mid-session; content oracle;
  `slog db tree` shows the edge; replay materialises the linked chain.
- **Freeze (W7).** `slog db freeze` output is content-equal to the chain's
  materialisation and loads with no replay.
- **Exact-once staging (0.B6, forward-compat for M0).** Assert a batch's
  tuples enter delta staging exactly once across the reload path — checked
  now by instrumentation, load-bearing under counting later.

### Phases 1–2: the literature's counterexamples

The literature's counterexamples are the test suite. Each must match a from-scratch batch
recompute after a randomised insert/delete sequence:

- `R(y,x):-R(x,y)` symmetric closure — insert then delete the seed (unfounded cycle).
- `reachable` with `source` deletion leaving a live edge-cycle (unfounded cycle archetype).
- TC over cyclic graphs, deleting edges (must *stay* correct — the case pure counting
  handled).
- Diamond + chain (§5.2): over-delete then one-step re-found, plus a `(0,0)` relearn.
- SCC collapse: delete the single edge bridging two strongly-connected blobs.
- **Iteration-0 exact-once (M0 headline, §8):** run a program whose rules have
  multiple same-relation body clauses through a save → load → reload cycle
  (delta = whole db at reload) and assert every tuple's counts equal the
  from-scratch run's counts — a double-fired instantiation shows up as an
  inflated count even though the tuple SET matches.
- **Compressed-load count oracle (§8A.5):** extend `tests/compression/run.sh` to
  diff per-tuple counts (not just content) between a compressed load at each
  `per` and the from-scratch oracle — this exercises the §8A.2 witness/tombstone
  ingestion rule, id-preserving tombstone resurrection, and count regeneration
  in one harness.
- **Differential fuzzing:** random `±tuple` streams vs. full recompute, across programs
  with structs and multiple strata.

---

## 11. Future directions (not in scope)

- **DBSP nested incremental circuits** for O(change) recursion without over-deletion
  waste — a codegen project atop `emit-cpp.rkt` (integration/differentiation operators,
  nested recursive circuits).
- **Differential dataflow** (timestamp lattice, versioned traces) for O(change) even deep
  in recursion — an engine replacement with ~2–4× memory and a progress-tracking
  subsystem. Reach for it only if deep-recursion incremental performance demands it.

---

## 12. References

- A. Gupta, I. S. Mumick, V. S. Subrahmanian. *Maintaining Views Incrementally.* SIGMOD
  1993. (Counting algorithm and DRed; counting fails on recursion.)
- P. Hu, B. Motik, I. Horrocks. *Optimised Maintenance of Datalog Materialisations.*
  AAAI 2018. arXiv:1711.03987. (**DRed^c**: nonrec/rec split counters, three phases, no
  backward evaluation.)
- B. Motik, Y. Nenov, R. Piro, I. Horrocks. *Incremental Update of Datalog Materialisation:
  The Backward/Forward Algorithm.* AAAI 2015. (Foundedness via backward proof search.)
- B. Motik, Y. Nenov, R. Piro, I. Horrocks. *Maintenance of Datalog Materialisations
  Revisited.* Artificial Intelligence 269 (2019). (FBF; unifies DRed / B/F / counting.)
- M. Budiu, T. Chajed, F. McSherry, L. Ryzhyk, V. Tannen. *DBSP: Automatic Incremental
  View Maintenance for Rich Query Languages.* VLDB 2023. (Z-sets; recursion via nested
  circuits with `distinct`; least-fixpoint recomputation, not derivation counts.)
- F. McSherry, D. Murray, R. Isaacs, M. Isard. *Differential Dataflow.* CIDR 2013.
  L. Ryzhyk, M. Budiu. *Differential Datalog.* Datalog 2.0, 2019. (Signed multiplicities
  over a timestamp lattice.)
- T. Green, G. Karvounarakis, V. Tannen. *Provenance Semirings.* PODS 2007.
  M. Abo Khamis, H. Ngo, R. Pichler, D. Suciu, Y. Wang. *Convergence of Datalog over
  (Pre-)Semirings.* PODS 2022 / JACM 2024. (ℕ is not stable → counting diverges on
  recursion; stable semirings converge — the aggregation admissibility condition.)

### Aggregation

- K. Ross, Y. Sagiv. *Monotonic Aggregation in Deductive Databases.* PODS 1992 / JCSS
  54(1) 1997. (Aggregation monotone over a lattice composes with recursion.)
- C. Zaniolo, M. Yang, A. Das, A. Shkapsky, T. Condie, M. Interlandi. *Fixpoint Semantics
  and Optimization of Recursive Datalog Programs with Aggregates.* TPLP 2017. (**PreM** —
  when min/max/count/sum are safe inside a fixpoint; DeALS/BigDatalog.)
- I. Mumick, D. Quass, B. Mumick. *Maintenance of Data Cubes and Summary Tables in a
  Warehouse.* SIGMOD 1997. (Self-maintainable aggregates; COUNT retained for deletion.)
- T. Palpanas, R. Sidle, R. Cochrane, H. Pirahesh. *Incremental Maintenance for
  Non-Distributive Aggregate Functions.* VLDB 2002. (MIN/MAX auxiliary structures.)
- N. Conway, W. Marczak, P. Alvaro, J. Hellerstein, D. Maier. *Logic and Lattices for
  Distributed Programming* (Bloom^L). SoCC 2012. (Lattice-typed, monotone-composable
  relations.)
