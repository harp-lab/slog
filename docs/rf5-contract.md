# RF5 — semantic program and module-instance replacement

**Status (2026-08-13): RF5-B IS COMPLETE.** The two-arc join is merged;
the first joint battery runs the producer and consumer together
(`compiler/change-pcs.rkt` bridges the sealed set into the frozen fixture
grammar; tier `rf5-join`); the mapped data-overlay suffix replays live
through the candidate rules; the §10 additional cases are pinned (tier
`rf5-gate`: split commits, cross-instance merge refuses typed on the torn
clustering, identical/duplicate/reactivation/suffix cases live); and §6's
initial surface — `replace instance ALIAS with "LIB.slog"`, `preview`,
`activate` — runs at the prompt over `session-activate-pcs!`.  RF5-C
(precise healing) and RF5-D (historical branches) remain open, as does
widening the sever closure to the resident∪candidate clustering union.
This document
turns the high-level RF5 program-image plan in
[slog-reflection.md](slog-reflection.md) into an end-to-end replacement
contract. It is the review target for roadmap W5'. Nothing here describes
the already-shipped O0/O2 executor hot swap: that swap preserves one semantic
plan and changes only its implementation. RF5 changes the program's meaning
and must repair materialized relations.

The motivating operation is:

> Load a recipe-bearing analysis, select one instantiated module occurrence,
> replace it with another implementation or configuration, and publish the
> recomputed result atomically while retaining the old boundary for history
> and comparison.

The first correctness implementation may clear and rerun the affected cone.
Precise rule-delta maintenance is an optimization behind the same transaction,
not a prerequisite for the user workflow.

**Program-arc implementation ledger (2026-08-09).** RF1.5's first query
slice is implemented in `compiler/program-model.rkt`: deterministic
image-local rule occurrences, provenance-blind alpha-normalized rule and model
fingerprints, writer sets, typed positive/negative/derived dependency edges,
member-named SCC and condensation queries, old/new union cones, and a
duplicate-multiplicity-aware semantic-model diff. The fingerprint is
deliberately labeled as a `ProgramModel` fingerprint: declarations, instance
bindings, services, and execution plans must join it in the later sealed
`ProgramImage` and `ProgramChangeSet`; this slice does not guess them. The
focused RF1/RF1.5 battery and the full compiler unit suite cover the adapter.

**RF2 checkpoint (2026-08-09).** `compiler/program-image.rkt` now seals one
content-addressed, versioned package containing canonical declarations, source
tokens and digests, lexical module/source occurrence slots and bindings, the
RF1.5 rule/dependency/SCC graph, and zero or more complete Plan-ABI-2 cohort
terms. Its reader validates the content key, dense references, source and rule
digests, module/source closure, dependency causes, recomputed SCC partition
and levels, condensation edges, model fingerprint, and cohort ABI before
returning a value. `emit-program-image` writes one atomic `.pimg` per program;
`SLOG_EMIT_PROGRAM_IMAGES=<dir>` enables the compiler producer without
changing the runtime-facing `compile-strata` result. Declaration-only
programs, two instances of one source, save/load, tampering, cache hits, and a
complete textual golden are covered.

RF2-B adds an independent bounded C++ decoder in `daemon/program-image.cpp`.
`mount-program-image` verifies the outer SHA-256 content seal, closed format
and Plan ABI, dense and in-range occurrence slots, source/rule/cohort digests,
dependency causes, a recomputed SCC partition, condensation edges, and levels
before publishing an immutable connection-scoped mount. `catalog programs`
and `catalog program KEY [sources|rules|kernels|plans|activation]` expose typed record
streams; the REPL presents the same data through `images`, `image mount`, and
`image KEY ...`. Duplicate mounts are cache hits, missing files are typed
cache misses, and unmount releases only the decoded view. Images do not enter
the user `Database` or database saves, so application rules cannot mutate
them. RF3 now owns complete executable verification/binding and may
additively materialize a mounted image's interpreted cohorts at a settled
tip; it does not replace an active program or heal existing derived state.
The first physical mount is deliberately the compact
decoded control-catalog object rather than a frozen user subdatabase; a later
meta-program surface may materialize the same records through freeze/import
without changing ProgramImage identity.

**RF5-A checkpoint (2026-08-10).** `compiler/program-change.rkt` provides
image-bound module handles and persistent draft revisions for explicit
preserve/replace/remove/add operations over module, rule, and relation-output
occurrences. Sealing requires total old/new coverage; duplicate use of an old
identity or either side's local slot is a hard error, so filenames, aliases,
and relation basenames never become inferred lineage. The sealed,
content-addressed `ProgramChangeSet` carries both image identities, inventory
counts, all lineage, separate source/occurrence, normalized semantic, and
execution-plan diffs, complete old/new writer and member-named SCC graphs,
affected roots, the union old/new cone, exact ABI-2 kernel/binding reuse,
required services, and compiler-known typed refusals. Oracle demand-to-answer
side channels and attachment changes are semantic dependency/cone inputs;
ground facts use the compiler's constant-class closure rather than a
body-empty approximation. Relation-shape and alias/type changes become typed
refusals before any runtime mutation. Its strict, byte/depth-bounded version-1
codec has a byte-complete golden built from two ordinary compiler-produced
ABI-2 images and an independent RF5-B wire consumer in
`tests/api/program-change-consumer.rkt`. That consumer imports neither image
nor change-set structs and cross-checks both image seals, inventories, model
keys, compiler key, and Plan ABI. The artifact contains no live
`VersionId`, maintenance route, boundary allocation, or publication choice.
No session or daemon mutation path is reachable from this module. The REPL
command grammar and live-boundary resolution begin at RF5-B; RF5-A's
`seal-program-draft` is the compiler-side sealed-preview operation.

## 1. Scope and non-goals

RF5 covers semantic replacement of:

- one complete program occurrence;
- one or more lexical `ModuleInstanceKey` occurrences inside that program;
- source rules, program ground facts, namespace bindings, and compile-time
  semantic options; and
- a module template with another template under the same compatible home and
  binding contract.

RF5 does not:

- mutate a running rule or task graph one row at a time;
- overload ordinary EDB `add`/`del` with program edits;
- treat O0/O2 availability or artifact paths as semantics;
- infer that a missing declaration means `drop`;
- equate two module instances because their aliases or source paths match; or
- make a flat/frozen database recover derivation provenance it discarded.

A flat/frozen database can be used as a new input root, but all of its tuples
are then foundations. Removing rules that originally produced some of those
tuples cannot retract them. Exact replacement requires a recipe-bearing
database with the target program image, input boundary, and overlays.

### 1.1 What the current tree already supplies

RF5 is not starting from an unstructured compiler:

- N1 gives every lexical occurrence an occurrence tree, home, binding map,
  and persisted `ModuleInstanceKey`; N4 carries those records through a saved
  boundary bundle and the REPL already has a structured catalog projection.
- RF1's `ProgramModel` preserves the qualified SCC condensation and the
  available source-rule lineage, while Plan ABI 2 separates canonical kernel
  execution, binding, debug, and cohort data.
- The session has immutable `ProgramInstanceKey`, `BoundaryKey`, `VersionKey`,
  and `TypeKey` recipe identities plus prepared/committed daemon boundaries.
- Incremental maintenance already has version dependency cones, count epochs,
  DRed/repair routes, and a permanent bounded clear-and-rerun fallback.
- T5 supplies the pre-commit gate, candidate inspection, `why`/`whynot`, and
  commit/replay/abort vocabulary RF5 can reuse.

The missing implementation is exactly the RF5 bridge: RF2's mounted sealed
source/program image; RF1.5-level normalized program queries/fingerprints;
cross-image occurrence and relation-slot lineage; the three compiler diffs;
a program-update boundary and descendant-recipe planner; and the draft/
preview/activate REPL commands. RF1's current `ProgramModel` is intentionally
minimal-for-execution and must be extended rather than mistaken for a ready
program-diff API.

## 2. Identity and lineage across images

An active `ProgramImage` and all of its `ModuleInstanceKey`, `RuleKey`, and
output `VersionKey` values are immutable. A replacement never reuses those
keys for different content. It creates a new `ProgramInstanceKey`, new module
and rule occurrence keys, and fresh output version slots where the replacement
or its suffix writes.

The draft records explicit correspondence rather than pretending the keys are
stable across program generations:

```text
ProgramReplacement(old_program_instance, new_program_slot)
ModuleLineage(old_module_instance, new_module_slot, edit_kind)
RuleLineage(old_rule_key, new_rule_slot, edit_kind)          ; diagnostic
RelationSlotLineage(old_version_key, new_output_slot, kind) ; semantic
```

`edit_kind` is `preserved`, `modified`, `removed`, or `added`. Rule lineage is
for source navigation, statistics continuity, and explanations; it is not the
semantic proof that a rule is unchanged. `RelationSlotLineage` is part of the
activation plan and is required to transfer anchored direct-input overlays and
to replay a suffix. It is never guessed from a basename.

The old key and new key coexist because old `dbN` handles remain meaningful.
Reactivating a previously used image can reuse its content-addressed image,
kernel plans, and native artifacts, but it still creates a fresh temporal
program occurrence and fresh output VersionKeys.

### 2.1 Selecting an instantiated module

The user selects the old occurrence by `ModuleInstanceKey` through a REPL
handle such as `m7`, not by source filename or alias alone. The replacement
operation retains the occurrence's home and formal-to-actual bindings unless
the draft changes them explicitly. A different template placed under that
home is therefore a replacement; the same template placed under a new home is
an additional generative instance.

Aliases remain presentation. If a draft moves an instance to a different
home, changes incompatible public declarations, or cannot provide an exact
relation-slot mapping, it is a migration rather than an RF5 hot replacement
and must use explicit namespace creation/drop/mapping operations.

## 3. The semantic oracle

Let program occurrence `P` consume boundary `B`, produce boundary `C`, and be
followed by recipe suffix `S`. Replacing `P` with sealed candidate `P2` means:

1. retain the immutable recipe prefix through `B`;
2. evaluate the complete `P2` at `B` from its exact captured input versions;
3. replay `S` against explicit old-to-new relation-slot lineage; and
4. compute the least fixpoint of that descendant recipe from scratch.

The published result must equal that oracle. The live implementation may
reuse prefix materializations, unchanged relation versions, counts, kernels,
and artifacts only when doing so produces the same result.

In particular, replacement is **not** an ordinary program segment appended to
`C`. An appended segment inherits all of `C`, including tuples supported only
by removed rules. A replacement output is founded from `B` plus `P2` and the
replayed suffix, not from `P`'s old derived output.

The program-update boundary creates successor versions for the union of old
and new affected writes. If an old module was the only writer of relation `R`
and the candidate no longer writes `R`, the new boundary still advances `R`
and rebuilds it from surviving prefix/input support; it must not leave the old
`R` binding in place merely because `P2` omitted the declaration.

## 4. One edit produces three different diffs

No single textual or compiled-rule diff is authoritative for every purpose.
The compiler service returns three related products.

### 4.1 Source/occurrence diff

This diff describes templates, module occurrences, source rules, ground
facts, source spans, options, homes, and bindings. It drives REPL display and
the explicit lineage tables. Moving or reformatting a rule may change this
diff without changing database semantics.

Format 1 reserves an explicit options section but its semantic-option
vocabulary is currently empty. Executor flavor, optimization level, and
artifact availability are execution choices and must not be smuggled into
that section. Adding a semantic compile-time option requires a format review,
canonical carrier, and affected-root rule rather than silent inference.

### 4.2 Semantic program diff

This is computed after source closure resolution, module qualification,
formal-to-actual binding, desugaring, type checking, and normalization, but
before semi-naive execution variants and executor packaging. Its rule
fingerprint is alpha-normalized and excludes source spans, local RuleIds,
artifact state, and presentation aliases.

It contains at least:

```text
declarations added / compatibility-checked / explicitly retired
semantic rules and program facts added / removed
binding and literal-option changes
positive, negative, lattice, side-table, and oracle dependency-edge changes
old and new writer sets per qualified relation
old and new SCC condensation graphs
affected-root relations
```

A source-level modification is semantically a removal plus an addition. The
diff retains occurrence multiplicity as well as the set of normalized rule
operators: if an identical rule remains through another source occurrence,
removing one duplicate may leave least-fixpoint membership unchanged but it
still changes derivation support counts and must be recounted or decremented.
Module boundaries do not bound the impact: cross-instance rules can place
several instances in one SCC, so the compiler recomputes the qualified
dependency graph rather than unloading a namespace-shaped runtime object.

The initial affected roots are the heads of added/removed rules and facts,
relations whose writer sets, bindings, or service attachments changed, and
members affected by a catalog operation. Oracle demand-to-answer edges are
explicit side-channel dependencies even though no source rule owns them. The
healing cone is reachability from those roots through the union of the old and
new dependency graphs. Using only the new graph
would miss consumers that disappear; using only the old graph would miss new
consumers.

### 4.3 Execution-plan diff

The plan diff compares canonical `KernelExecPlan`s, binding frames, services,
and `KernelPlanKey`s. It decides which interpreter/native executors and cached
artifacts can be reused. It does not decide whether materialized tuples or
count sidecars can be reused: an unchanged kernel bound to different input
VersionKeys is the same code but a different semantic instance.

The compiler owns these three diffs and the old/new SCC correspondence. The
session owns recipe branching, VersionKey lineage, the live version graph,
and maintenance-route selection. The daemon owns private materialization,
task installation, count epochs, and atomic boundary publication. The REPL is
a client of those authorities, never a fourth diff engine.

## 5. Module replacement and tuning

`replace instance m7 ...` removes the rules and ground-fact support attributed
to the selected old occurrence and adds the candidate occurrence under the
recorded home/bindings. It does not remove contributions made by other module
instances merely because they write the same relation.

Declaration omission remains non-destructive. Public catalog members formerly
declared by the old instance stay declared unless the proposal contains an
explicit checked retirement/drop. Their materialization can nevertheless
lose tuples because the old writer disappeared. Incompatible shapes are
rejected before evaluation; a user who wants a new shape chooses a fresh
namespace and an explicit migration.

“A different tuning” has three cases:

1. **Data tuning.** Facts in an already-bound `tuning.*` namespace change.
   Use ordinary signed input edits; RF5 is unnecessary.
2. **Binding tuning.** The instance changes from `tuning = tune0` to
   `tuning = tune1`. The template may be identical, but the binding-frame and
   read-edge diff is semantic and uses RF5 activation.
3. **Compile-time tuning.** An option changes generated rules, literals, or
   declarations. It becomes part of the source/semantic image and uses the
   ordinary program diff.

Executor tuning (`interp`, O0, O2, shard selection) is never a program edit.

## 6. REPL workflow

The initial RF5 surface uses immutable handles and the existing pre-commit
gate vocabulary:

```text
open analysis
progs                         ; p3 is the target ProgramInstanceKey
modules p3                    ; m7 is one lexical ModuleInstanceKey

draft p3 as d1
replace instance m7 in d1 with "analyze-v2.slog"
  with syntax = syn, tuning = tune1, output = model

preview d1                    ; validate, seal i4, show all three diffs
activate i4 hold              ; build/heal privately, then pause pre-commit
diff db3 candidate model.*
why candidate (model.answer ...)
commit                        ; publishes one new dbN + recipe event
```

`draft` and `preview` are control-plane operations and cannot affect the
active fixpoint. `preview` snapshots one draft revision; editing `d1` later
does not mutate sealed image `i4`. Its report includes:

- the selected old/new program and module occurrence lineage;
- source rules/facts added, removed, and preserved;
- bindings and declarations changed;
- SCCs split, merged, added, or removed;
- affected writer roots and the old/new dependency cone;
- proposed relation-slot mappings and any ambiguous/refused suffix anchor;
- planned route per component (`precise`, `recount`, `clear-rerun`); and
- expected artifact reuse separately from semantic-state reuse.

`activate i4` behaves like another semantic event: without `hold` or an armed
level-1 watch it may commit automatically after all audits. `hold` guarantees
the existing pre-commit pause, where queries explicitly select `candidate` or
an old `dbN`; unqualified queries continue to select the last committed
boundary. `commit` publishes the candidate atomically, and `abort` discards
all private versions and tasks.

There is no visible “uninstall old module, run, install new module” interval.
The old image remains active and queryable while the candidate settles. To
swap back after commit, activate the earlier sealed image as another new
program occurrence; history is never rewritten in place.

Useful companion operations, in the same command family, are:

```text
remove instance m7 from d1
instantiate "extra.slog" as extra in d1 with input = model
edit d1                         ; open the draft source/proposal in $EDITOR
discard d1
```

The existing bare `edit` of the scratch buffer should therefore become
`edit scratch`; RF5 `edit d1` always names a draft and cannot silently edit
the committed image.

## 7. Prepare, heal, and publish

Activation is one update epoch:

1. **Validate/seal.** Check the draft revision, source closure, schemas,
   bindings, stratification, services, and the three compiler diffs. Failure
   changes no live state.
2. **Plan the descendant recipe.** Allocate a new layer/program event,
   boundary, module/rule occurrences, output VersionKeys, TypeKeys for truly
   new nominal types, and explicit relation-slot lineage. Preserve compatible
   TypeKeys for replacement successors. A modified alias/type declaration is
   an RF5-A refusal until the runtime arc supplies an explicit compatible
   TypeKey/SID migration; unchanged relation spelling is not compatibility
   evidence by itself.
3. **Prepare privately.** Install the candidate writer graph and private
   output versions. Old committed tasks and versions remain untouched.
4. **Heal.** Reuse unaffected prefix slots. For each affected SCC/cone choose
   a certified signed route or clear and rerun from the replacement input
   boundary. Replay transferable direct assertions, inheritance masks, and
   the admitted recipe suffix against explicit slot lineage.
5. **Recount/audit.** A writer-set change invalidates affected count epochs.
   Commit only after live membership, writer coverage, contributor state,
   struct identity, and the semantic oracle's supported audits agree.
6. **Pause or publish.** Expose the candidate only through an explicit
   candidate handle at the pre-commit gate. Commit atomically installs the
   new image, task graph, boundary, version bindings, counts, and recipe
   event; abort discards them together.

Queries pinned to an old boundary need no restart. A query following “latest”
must see either the old or new committed boundary, never a mixture. T6 owns
transactional restart for a read attempt crossing publication; RF5 must not
invent a second read-consistency mechanism.

### 7.1 Correctness-first route

The first RF5 activation route is deliberately coarse:

- retain the immutable prefix through the target program's input boundary;
- rebuild every relation in the union old/new affected writer cone in private
  successor slots;
- rerun the complete candidate SCCs and admitted recipe suffix; and
- establish fresh counts before publication.

This is already incremental at the recipe/cone granularity and avoids a full
database reload. It is the mandatory fallback permanently.

### 7.2 Precise routes

Later admission can specialize without changing the transaction:

- a positive rule addition in a topology-stable positive SCC starts from the
  old fixpoint, runs the complete affected successor SCC, and propagates new
  membership transitions;
- a nonrecursive rule deletion enumerates the removed rule's old support and
  decrements counted heads;
- a recursive deletion uses the existing DRed foundation/candidate repair;
- negation, lattice replacement, structs, inheritance, and mixed cones use
  their existing capability certificates; and
- any SCC split/merge, binding ambiguity, unsupported service, arithmetic
  failure, or count-coverage failure falls back before publication.

“Same compiled bytes” never grants a precise semantic route by itself.

## 8. Recipe suffixes and initial admission

Replacing the latest program occurrence in a loaded analysis may still have a
suffix of data batches. RF5 maps those anchors through explicit relation-slot
lineage and replays them in order. Direct assertions remain direct assertions;
program ground facts remain program support and disappear when their source
rule/fact disappears.

The first admitted RF5 slice may support:

- the latest program occurrence in the recipe;
- any following signed input-overlay batches whose anchors map uniquely; and
- no later program, attach/link, rename/drop, or schema-migration event.

It must issue a typed `historical-program-replacement` refusal for a more
complex suffix, not append the candidate at the tip and call that replacement.
The full historical form builds a descendant branch, recompiles/rebinds each
later program occurrence, maps every stable anchor explicitly, and publishes
the reconstructed suffix atomically. That is a later RF5 slice and is the
point at which general `fork`/`checkout` UI may become worthwhile.

## 9. Persistence and replay

A committed replacement recipe event stores:

- the base program/image and selected occurrence keys;
- the complete captured candidate source image or an immutable sealed image
  plus its compiler/PlanABI identity;
- the edit proposal and explicit occurrence/relation lineage;
- the normalized semantic diff digest and boundary/output slot tables; and
- the admitted suffix mapping.

Maintenance route, timing, executor tier, and artifact availability are
diagnostic observations, not replay semantics. Replay reconstructs the
candidate and descendant recipe and checks the persisted semantic diff and
slot plan. A compiler that produces a different normalized image or mapping
for the same recorded event causes a typed replay refusal; it never silently
accepts a newly inferred correspondence.

## 10. Delivery slices and gates

1. **RF5-A — drafts and compiler diff (complete 2026-08-09).** Module
   handles, immutable draft revisions, preserve/replace/remove/add operations,
   sealed previews, the three-diff result, explicit total lineage, frozen
   serialization/golden consumer, and no daemon mutation.
2. **RF5-B — correctness-first activation (complete 2026-08-13).**
   Latest-program replacement, mapped data-overlay suffix (replayed live
   through the candidate rules), private cone rebuild, recount, pre-commit
   inspection, atomic publish/abort, save/replay; the joint battery
   (`rf5-join`), the §10 case battery (`rf5-gate`), and the prompt surface
   (`replace instance`/`preview`/`activate`).
3. **RF5-C — precise healing.** Admit positive additions, acyclic deletions,
   and recursive DRed one capability-certified surface at a time; compare
   every result and sidecar with RF5-B's fresh cone oracle.
4. **RF5-D — historical branch replacement.** Recompile/rebind a general
   recipe suffix, explicit conflict resolution, and optional branch UI.

### 10.1 Parallel implementation handoff

The roadmap's [W5′ two-arc plan](roadmap.md#w5-two-arc-implementation-plan-ratified-2026-08-08)
implements RF5-A on the program/reflection arc and RF5-B on the join with the
runtime/transaction arc.  The serialized pre-join handoff is a
`ProgramChangeSet`: base and candidate image identities, explicit occurrence
and proposed relation-slot lineage, all three compiler diffs, old/new writer
and SCC graphs, affected roots and union-graph cone, required services, and
compiler-known refusals.  It contains no live `VersionId`, maintenance route,
or publication decision.

The session validates that change set against the selected committed boundary
and resolves it into an `ActivationPlan`.  That plan adds successor
`VersionKey` allocation, accepted slot lineage, mapped recipe-suffix replay,
route/fallback choices, invalidated count epochs, and T6 publication policy.
The daemon executes the plan privately and returns its audit/pre-commit
result; it does not recompute compiler lineage or semantic diffs.  Golden
serialized change sets are the test ABI between the two arcs until the first
joint battery makes the producer and consumer executable together.

RF1.5, RF2's container/query layer, and pure RF5-A diff/lineage work may begin
on the RF1/Plan-ABI-2 baseline while T4's landing commit is still being
vetted, provided they avoid T4's lowering, native emission, descriptor attach,
and daemon integration surfaces.  Final plan-diff goldens, RF4 artifact
catalog wiring, and all RF5-B activation work consume the landed T4 behavior.
The full runtime arc begins at that T4 landing commit; only isolated T0(c)
identity fixtures are worth starting earlier.

The RF5-B exit gate is the roadmap capstone, made concrete:

1. save and load a large analysis containing two instances of one template;
2. select exactly one instance by ModuleInstanceKey and replace it with a
   changed binding or rule set;
3. prove the other instance and every outside-of-cone VersionKey are reused;
4. prove removed rule/fact support disappears, additions reach fixpoint, and
   affected counts equal a fresh descendant-recipe recount;
5. abort once at the pre-commit gate and prove the old boundary unchanged;
6. commit, save, reload, and reproduce the new boundary and image keys;
7. preserve compatible struct TypeKeys/SIDs and reject an incompatible shape
   before mutation; and
8. compare `why`/`whynot`, old versus candidate, for one gained and one lost
   fact.

Additional required cases are an SCC split, an SCC merge across two module
instances, an identical-semantic replacement (metadata-only), duplicate
semantic source rules, a data-tuning edit that correctly stays on the normal
batch path, an ambiguous suffix mapping refusal, failure during recount, and
reactivation of a previously sealed image without identity reuse.

## 11. Decisions still requiring review

The contract deliberately leaves only these policy choices open:

1. whether `preview` always materializes a bounded dry-run sample or remains
   compile/diff-only until R5 `whatif` supplies cost estimates;
2. the exact syntax for explicit declaration retirement and relation-slot
   mapping during a migration; and
3. whether RF5-D and general session branching share one command surface or
   merely one recipe implementation.

The identity, semantic oracle, three compiler diffs, private activation,
fallback, and no-inferred-lineage rules are not contingent on those choices.
