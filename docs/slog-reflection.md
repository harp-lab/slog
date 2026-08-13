# Reflective Slog program images and code as data

2026-07-14. **Design brainstorm; no implementation commitment yet.** This
document records a possible deeper foundation for the program-model,
interpreter, execution-tier, REPL, debugging, and incremental-program-edit
work. It is deliberately broader than
[execution-tiers.md](execution-tiers.md), which remains the current execution
design, and [repl-ux.md](repl-ux.md), which remains the interaction-design
brainstorm. The purpose here is to decide whether a reflective program image
should become the common exchange model before the daemon grows several new
bespoke representations. A same-day review pass added §18 — the staging
verdict, de-risking precedents, and refinements — and relabeled §15's
experiment slices **RF0–RF5** so they cannot be confused with
[repl-ux.md](repl-ux.md)'s REPL slices R0–R5.

The candidate thesis is:

> A Slog program, its lowered execution plans, its source/debug maps, and many
> of the graphs produced while inspecting it can be represented as typed Slog
> data in an immutable reflective program image. The compiler may still be
> written in Racket and the daemon in C++; the daemon validates and decodes the
> image into compact interpreter/native task objects. Those objects are
> materialized execution caches of the program image, not a second anonymous
> definition of the program.

This is meaningfully deeper than making every REPL result look like a tree,
but substantially less radical than interpreting every operator by repeatedly
probing meta-relations, or rewriting the compiler in Slog. A Slog-in-Slog
compiler or reference interpreter remains an appealing distant experiment,
not a prerequisite. The practical proposal is closer to a database-backed
bytecode image with first-class source, identity, and graph structure.

## 1. Why consider this now

Several planned features independently need overlapping descriptions of the
same things:

- the compiler needs source-rule origins, dependency edges, SCCs, lowering
  lineage, operator plans, index requirements, and artifact keys;
- the daemon needs validated kernels, bindings, executable variants, tier
  attachments, task ownership, counters, and debug positions;
- the REPL needs rules, plans, schemas, histories, proof/why-not graphs,
  traces, compiler diagnostics, tier state, and artifact state;
- the incremental engine needs durable program/rule/kernel identities and a
  coherent description of program changes; and
- future Slog meta-programs may want to query or transform programs just as
  ordinary programs query or transform syntax trees, SMT formulas, schemas,
  and other interned values today.

Building unrelated C++ records, Racket S-expressions, sidecar manifests,
protocol records, and REPL presentation nodes for each feature would work,
but would create many translations and many opportunities for identity and
semantics to drift. A typed reflective image could be the common persisted and
queryable interchange, while each component retains the specialized in-memory
representation it needs.

The current canonical plan work is especially well placed for this decision.
The `.plan` format does not yet have a production daemon consumer, so its ABI
can still be split into real per-SCC plans, source/debug maps, bindings, and
cohort manifests without a migration burden.

## 2. First preserve the real program graph

Reflection does not replace the program-model refactor; it gives that model a
natural external form.

Today `stratify.rkt` computes exact relation SCCs and their condensation DAG,
then discards SCC identity by grouping all independent SCCs at one dependency
level into `(stratum level rules)`. Later passes reconstruct parts of the SCC
graph, infer recursion indirectly from a stratum-wide dynamic set, and call a
whole-stratum canonical plan a `KernelPlan`.

The compiler should first produce an intentional `ProgramModel` after type
checking and dependency analysis:

```text
ProgramModel
  declarations and relation identities
  source rules, origins, and lowering lineage
  dependency edges with polarity and cause
  logical SCCs
  execution kernels
  same-level execution cohorts
  runtime-service requirements and feedback edges
```

It should expose queries such as `kernel-of-rule`, `kernel-of-relation`,
`writers-of-relation`, `same-kernel?`, `kernel-predecessors`, and
`cohort-of-kernel`, rather than asking downstream passes to rediscover those
facts from sets of relation names.

Three units must remain distinct:

| unit | meaning | owns |
|---|---|---|
| **execution kernel** | one logical SCC plus any attached runtime feedback services | semantic/tier/debug identity and executable variants |
| **execution cohort** | independent kernels safe to co-run at one dependency level | shared barriers, reload, and coordinator services |
| **code bundle** | an arbitrary physical packing of native variant factories | `.o`/`.so` caching, loading, and attachment |

Same-level SCCs should continue to share one OpenMP team and fixpoint loop.
They need not become separate runtime strata or separate `.so` files. They
must merely stop losing their individual identities. A cohort containing 200
simple acyclic kernels can flatten all their interpreted tasks into the same
queues; a few hot recursive kernels can use native executors; no rule says
that the physical code bundle count must equal either 200 or one.

The logical dependency graph is not quite the entire execution graph.
Oracle demand/answer flow, sequence occurrence indexing, decomposition
relations, and diagnostic/error paths include daemon-produced edges that are
partly hidden from ordinary stratification today. The model needs explicit
`ServiceNode`/`ServiceRequirement` records. A diagnostic sink must not merge
every kernel that can report an error, while an oracle answer that feeds a
requesting rule really is feedback that must remain in the requesting
kernel's execution closure.

## 3. One substrate does not mean one representation

The compiler, daemon, and REPL are allowed to have specialized
representations. In fact, they should.

```text
Racket compiler structs
        |
        | validate + serialize
        v
immutable reflective ProgramImage (typed Slog data)
        |
        | validate + seal + bind
        v
C++ KernelInstance / BoundOp / ReadTask objects
        |
        | observe by stable ids
        v
REPL presentation graph
```

The important property is that the translations are explicit, versioned, and
round-trippable. The compiler's internal `ProgramModel` can use immutable
Racket structs and convenient sets/hashes. The daemon should use dense arrays,
direct `Relation*`/index pointers, function pointers, and explicit cursor
stacks. The REPL should use budgeted presentation nodes. None of those facts
argues against making the authoritative exchange image typed Slog data.

A useful slogan is:

> **Uniform substrate, typed domain schemas, specialized materializations.**

The alternative slogan, “one untyped node table for absolutely everything,”
should be rejected. It would discard the very invariants that make plans safe
to execute and pleasant to query.

## 4. Trees are rooted term graphs

`repl-ux.md` proposes “one tree to render them all.” That remains the right UI
idea, but the underlying objects are not all trees:

- source ASTs are mostly trees with shared source/provenance objects;
- interned values and SMT formulas are DAGs;
- module and relation dependencies are graphs;
- recursive proof explanations may be DAGs or cyclic graphs;
- why-not results contain alternative failure frontiers;
- traces are ordered event streams; and
- operator programs are ordered regions with cross-references.

The common presentation abstraction should therefore be a **rooted term
graph**: typed nodes, labeled fields/edges, explicit sequences, stable/shared
node references, and one or more roots. A tree view unfolds that graph under a
budget, marking shared/cyclic nodes with handles. This preserves the single
REPL navigation engine without forcing every authoritative schema into a
generic tree encoding.

There can be a small universal presentation vocabulary—scalar, record,
sequence, reference, edge, annotation—but source rules, plan operations,
proof nodes, and artifacts should retain typed schemas underneath it. Each
domain supplies a projection into the presentation graph.

This distinction also makes export natural: the same proof graph can render
as an expandable terminal tree, JSON, DOT, or HTML without changing how proof
identity is stored.

## 5. The reflective program image

A `ProgramImage` is an immutable, sealed, typed subdatabase produced by a
specific compiler/PlanABI. Conceptually it contains several linked schemas.
The names below illustrate the relational shape; they are not proposed final
surface syntax.

### 5.1 Source and semantic graph

```text
slog.program.image(
  image_key, compiler_key, plan_abi, root_program_instance)

slog.program.rule(
  image_key, rule_slot, rule_key, module_instance, source_span, ast_root)

slog.program.dependency(
  image_key, from_relation, to_relation, polarity, cause_rule, edge_kind)

slog.program.kernel(
  image_key, kernel_slot, scc_instance_key, recursive, level)

slog.program.kernel_relation(image_key, kernel_slot, relation_slot, role)
slog.program.kernel_rule(image_key, kernel_slot, rule_slot, ordinal)
slog.program.kernel_edge(image_key, from_kernel, to_kernel, edge_kind)
slog.program.cohort(image_key, cohort_slot, level)
slog.program.cohort_kernel(image_key, cohort_slot, kernel_slot, ordinal)
```

`rule_slot` and `kernel_slot` are dense image-local references. `RuleKey` and
`SccInstanceKey` are durable occurrence identities. Location and source text
are metadata, never substitutes for occurrence identity.

### 5.2 Executable plans

Each real execution kernel has a canonical `KernelExecPlan`:

```text
slog.plan.kernel(plan_key, plan_abi, capability_set, semantic_fingerprint)
slog.plan.relation_slot(plan_key, rel_slot, schema, required_views)
slog.plan.type_slot(plan_key, type_slot, requirement)
slog.plan.constant_slot(plan_key, const_slot, value)
slog.plan.primitive_slot(plan_key, prim_slot, primitive_key)
slog.plan.rule_slot(plan_key, rule_slot, shape)
slog.plan.variant(plan_key, variant_slot, rule_slot, variant_info)
slog.plan.op(plan_key, variant_slot, region, pc, op)
```

`region` distinguishes pre-driver, driver, body, and head. `pc` or an
equivalent sequence position makes order explicit; relation set semantics
must never be asked to recover operator order.

An `op` should be a closed typed union such as `Scan`, `Probe`, `Join`,
`Join3`, `Exists`, `Absent`, `Prim`, `Compare`, `MakeStruct`, `Emit`, and
`TypeCheck`, with dense register and slot operands. A generic `(opcode,
operands)` record may be convenient in the compact wire layer, but seal-time
validation must recover a typed closed vocabulary.

### 5.3 Debug and lowering maps

Source provenance does not belong indiscriminately in the executable plan
hash:

```text
slog.debug.rule(image_key, rule_slot, rule_key, source_span, source_text)
slog.debug.variant(image_key, plan_key, variant_slot, lowering_lineage, label)
slog.debug.op(image_key, plan_key, variant_slot, pc, source_clause, source_vars)
```

The daemon can then report an `(image_key, plan_key, variant_slot, pc)` event;
the REPL resolves it into source and variable names without native code
containing provenance strings.

There is one important exception. A source/rule identity emitted as an actual
Slog diagnostic fact is semantically observable. Such a value must be an
explicit origin/binding operand of the executable template rather than being
silently removed as “only debug metadata.”

### 5.4 Bindings and instances

A reusable plan contains local slots, not evaluation-local `RuleId`s or
daemon pointers:

```text
slog.program.kernel_instance(
  image_key, kernel_instance, kernel_slot, plan_key, binding_key)

slog.program.bind_relation(binding_key, rel_slot, version_key)
slog.program.bind_type(binding_key, type_slot, type_key)
slog.program.bind_rule(binding_key, rule_slot, rule_id)
slog.program.bind_origin(binding_key, origin_slot, origin_value)
```

The live daemon resolves those keys to `VersionId`, SID/type descriptors,
`Relation*`, `Index*`, and evaluation-local compact ids. Raw pointers and
cursor state never enter the durable reflective image.

This fixes a tension in the current canonical plan: a `KernelPlanKey` cannot
both be reusable across module attachments and hash attachment-specific
`RuleId`/source metadata. The plan should contain `RuleSlot` and
`VariantSlot`; the binding/debug image maps those to the attached occurrence.

## 6. Build tasks from the database; do not execute by chasing it

There are several possible depths of “Slog interprets Slog.” They should not
be conflated.

### 6.1 Presentation-only reflection

The REPL converts bespoke records into generic trees. This is useful but
superficial: Slog rules cannot query program structure, and each subsystem
still invents its own authoritative representation.

### 6.2 Reflective image plus decoded interpreter (recommended)

The compiler emits the reflective image. At installation the daemon:

1. reads the image through ordinary relation/index probes or a compact
   equivalent serialization;
2. validates and seals the complete snapshot;
3. resolves slots through the binding frame;
4. creates immutable compact op arrays and bound-operation tables;
5. constructs `ReadTask` objects with register files and cursor stacks; and
6. records the exact image/plan/variant identities on every task.

The hot loop then follows dense arrays and bound function/index pointers. It
does not look up `slog.plan.op` for each tuple or join match. Optional
instrumentation emits events carrying stable plan positions, so the task
strictly reflects its source image without paying database-probe overhead on
every instruction.

This is the attractive halfway point suggested by the interpreter work: much
closer to a prebuilt bytecode VM than a meta-circular relational evaluator,
but with the bytecode itself represented as an inspectable Slog database.
The expected overhead remains the function/virtual-pointer and interpreter
dispatch cost already being prototyped, not a fresh B-tree lookup for every
operator step.

### 6.3 Direct relational plan interpreter

A very slow executor could walk `slog.plan.*` relations directly. It could be
valuable as:

- a small reference semantics;
- a differential oracle for the decoded interpreter and native emitter;
- a teaching demonstration of Slog interpreting a Slog plan; or
- a bootstrap/emergency executor for tiny plans.

It should not be the production default. Besides performance, it complicates
continuations: every operator lookup becomes another database cursor whose
snapshot and lifetime must be represented.

### 6.4 Compiler or interpreter written in Slog

A Slog implementation of type checking, stratification, planning, or plan
interpretation would be a fascinating dogfooding project once reflection is
stable. It is not a reason to delay the Racket `ProgramModel` or the C++
decoded interpreter. The reflective schemas would make that later experiment
possible without committing to it now.

## 7. Interpreted and native tiers are materializations

Under this model the program image is authoritative and executors are caches:

```text
KernelExecPlan
  + BindingFrame
      -> decoded interpreted ReadTasks
      -> O0 native factories
      -> O2 native factories
      -> debug interpreted ReadTasks
```

The daemon seals coverage so every `VariantSlot` has exactly one selected
executor and no overlaps. Independent kernels in one cohort may choose
different tiers. Shared declaration, write, intern, sequence-index, and
oracle coordinator tasks are constructed once from the cohort/service image;
native bundles contribute read-rule factories only.

Simple closed-input copy/projection/filter rules can remain permanently
interpreted. A cohort with hundreds of them therefore produces no hundreds of
`.so` files—and may produce no native artifact at all. Large acyclic joins
remain eligible for cardinality/profile-based native preselection because
they may have only one pass in which to pay their interpreted cost.

Native physical packing remains independent:

```text
slog.cache.artifact(
  artifact_key, compiler_key, target_abi, tier, bundle_manifest_hash,
  content_hash)

slog.cache.artifact_variant(
  artifact_key, plan_key, variant_slot, native_slot, shape_fingerprint)
```

One bundle may contain selected variants from one kernel, several kernels in
one cohort, or a compiler promotion batch. A native descriptor carries no
evaluation-local rule ids or relation names. Attachment validates the
descriptor against the reflective plan and supplies the binding frame.

This moves semantic SCC separation earlier than T4 in
`execution-tiers.md`. T4 can then focus on reusable parameterized native
attachments, alpha-normalized module instances, and selective bundle
coverage rather than being responsible for discovering the kernel boundary.

## 8. The semantic firewall: object plane and control plane

Reflection creates a dangerous temptation: if something can be represented
as a Slog fact, perhaps every running application rule should be able to read
and write it. That cannot be the default.

Suppose ordinary application rules can read:

```text
slog.compiled_O2(kernel, artifact)
```

and derive user facts from it. The logical result would then depend on cache
contents, machine speed, compiler load, and the moment clang finished. This
violates the execution-tier rule that tier changes are non-semantic. The same
problem applies to breakpoints, traces, allocation statistics, and many debug
events.

The reflective world therefore needs at least two authority domains.

### 8.1 Object plane

The application database and the immutable description of the active program
image. A program may be allowed to query selected `slog.program.*` and
`slog.plan.*` relations as closed inputs. Those inputs are fixed for the
entire program execution. If a later program image changes them, ordinary
incremental dependency propagation may update analyses derived from the old
image.

### 8.2 Control/observation plane

Artifacts, compiler queues, executor attachments, runtime counters, traces,
debug graphs, edit drafts, and activation requests. The REPL and explicit
meta-program evaluations may query these through the same Slog query and tree
interfaces, but active application rules cannot make application facts depend
on them.

This can be implemented as separate mounted subdatabases, relation
capabilities, or distinct query contexts. The exact mechanism is open; the
semantic distinction is not.

Some control records are durable history and some are volatile observations:

- `ArtifactKey`, compiler fingerprint, target ABI, and content hash may be
  retained indefinitely;
- a `/tmp/...so` path is only an availability hint and may disappear;
- `CodeId`, `AttachmentId`, live pointer bindings, and compile progress are
  evaluation-local;
- proof/trace materialization is bounded and optional; and
- tier availability never enters replay semantics.

The REPL can still make the two planes feel uniform. “Uniformly queryable” is
not the same promise as “every relation may participate in the active
fixpoint.”

## 9. The compiler as an oracle-style service

The SMT analogy is fruitful, with one qualification. An SMT oracle answers a
demand inside a logical fixpoint and its recorded answer becomes discovered
input. Compilation chooses an executor for semantics already fixed by the
plan; compiler timing and success must not affect the logical result as long
as the interpreter is available.

It is therefore better to call this an **oracle-style content-addressed
service** than to expose it immediately as an ordinary `extern` relation in
the object plane.

There are really two services:

### 9.1 Program compiler service

```text
ProgramCompileRequest(
  source_image_key, compiler_key, options_key, target_plan_abi)

ProgramCompileResult(
  request_key, status, program_image_key, diagnostic_root)
```

It parses/validates/types/stratifies/lowers a source or typed-AST image and
returns a sealed reflective program image. This service runs at a program
activation boundary, not in the middle of executing the program being
replaced.

### 9.2 Native materialization service

```text
NativeCompileRequest(
  plan_key_set, coverage_set, tier, compiler_key, target_abi)

NativeCompileResult(
  request_key, status, artifact_key, descriptor_hash, diagnostics)
```

It asynchronously produces a cache artifact. The running cohort continues
interpreted; arrival merely permits a validated boundary tier swap.

Both services can reuse useful oracle infrastructure: bounded worker pools,
deduplicated content requests, status/progress, cancellation, recorded
results, and demand/answer introspection. They need a stricter trust and ABI
contract than SMT. The daemon must never `dlopen` an arbitrary path merely
because a fact names it; it accepts only an artifact produced by a trusted
compiler/toolchain policy whose descriptor and content hash validate.

An artifact record is a claim that content was built, not a promise that a
temporary file still exists. A missing artifact is a cache miss that can be
rebuilt, never a broken program.

## 10. Program editing and incremental healing

The concrete replacement semantics, cross-image module/rule/version lineage,
compiler diff products, REPL transaction, and delivery gates are specified in
[rf5-contract.md](rf5-contract.md). This section gives the architectural
model; the RF5 contract owns the executable plan.

Representing programs as facts makes source-to-source and IR-to-IR
transformation pleasantly natural. It does **not** make a program change an
ordinary base-fact insertion.

Changing a rule changes the derivation function, writer set, counts, and
possibly the SCC/stratum schedule. The incremental architecture still needs a
program-update transaction that validates the new program and heals affected
relation versions. Treating an inserted `slog.plan.op` row as ordinary EDB
would not accomplish that.

The safe model is immutable images plus drafts:

1. The active `ProgramImage P` is sealed and read-only for the duration of its
   execution.
2. The REPL or a Slog meta-program creates a draft/proposal derived from P.
3. A proposal may edit source AST/rules, bindings, or—under a more privileged
   expert interface—lowered plan facts.
4. Commit snapshots the complete draft atomically. Intermediate malformed
   states are never executable.
5. The compiler service validates, type checks, re-stratifies, lowers, and
   seals successor image P2, or returns a reflective diagnostic graph.
6. The session records a program-version event and computes the affected
   writer/change cone. Existing count/replay machinery incrementally heals
   what it can and uses clear-and-rerun fallback where it cannot prove a safe
   differential update.
7. P2 runs interpreted immediately; O0/O2 materializations are requested as
   evidence warrants. P and all old artifacts remain valid historical/cache
   objects.

A running Slog program may eventually derive `ProgramEditProposal` facts.
Those proposals are outputs of the current fixpoint, not mutations of the
code currently executing. An explicit controller can commit one at the next
program boundary, producing an outer sequence of program versions. This
phase separation prevents the paradoxical case where a rule deletes or
rewrites itself halfway through enumerating its own driver.

An automatic outer meta-fixpoint—run P, derive proposal, compile P2, heal,
repeat—could be designed later with explicit convergence and resource limits.
It should never emerge accidentally from ordinary relation mutability.

Direct editing of lowered plans should be deferred. Source/typed-AST edits
are reconstructible and can pass through the full compiler. A hand-edited
plan requires the daemon's complete verifier and can silently change
operational multiplicities relevant to counted execution even when final set
contents look plausible.

## 11. Reflection for proofs, traces, why-not, and compiler IR

The same substrate is valuable beyond active plans.

### 11.1 Proof and why-not graphs

```text
slog.proof.graph(proof_key, image_key, boundary_key, target_fact, mode)
slog.proof.node(proof_key, node_id, kind, rule_key, variant_slot, payload)
slog.proof.edge(proof_key, from_node, role, ordinal, to_node)
slog.proof.frontier(proof_key, node_id, failure_kind, expected, observed)
```

These graphs can be generated in a bounded control-plane overlay and only
persisted when the user asks. Recursive proof cycles and shared subproofs stay
graphs; the REPL presents a budgeted tree view.

### 11.2 Debug traces

```text
slog.trace.run(trace_key, execution_id, image_key, attempt_generation)
slog.trace.event(trace_key, event_no, iteration, kernel, variant, pc,
                 port, binding_snapshot, outcome)
```

Ordering is explicit. Trace facts are observations of one execution attempt,
not derivations in the application database. Aborted/replayed attempts remain
distinguishable by generation.

### 11.3 Compiler passes

The compiler could optionally expose source, simplified, typed, planned, and
lowered roots:

```text
slog.ir.result(input_key, compiler_key, pass_name, output_root)
slog.ir.lineage(output_node, input_node, transformation, ordinal)
```

Retaining every intermediate of every build forever is unnecessary. The
source/semantic model, executable plan, and debug map are primary program
image data. Other pass images can be content-addressed, generated on demand,
and evicted like native artifacts. This would nevertheless make `explain
r17` and compiler-debugging tools unusually powerful: a user could walk from
one source rule through splitting, staging, semi-naive variants, index
selection, and final op positions using the same REPL graph machinery.

## 12. Identity, hashing, and persistence

Reflection only helps if identities remain deliberate.

```text
ProgramInstanceKey  one temporal recipe occurrence
ModuleInstanceKey   one lexical module occurrence
RuleKey             one lexical source-rule occurrence
SccInstanceKey      one semantic SCC occurrence in the expanded program

ProgramImageKey     one sealed reflective program version
KernelPlanKey       content key of a canonical executable template
ArtifactKey         content/toolchain key of one native bundle

RuleId/KernelId     evaluation-local compact ids
RuleSlot/RelSlot    plan-local compact ids
VariantSlot         plan-local executable ordinal
NativeSlot          artifact-local factory ordinal
CodeId/AttachmentId live daemon identities
```

Do not rely on a runtime struct word/SID as the durable identity of a
reflective node. Struct ids are evaluation-local storage values; durable keys
and image-local slots must be explicit.

`KernelPlanKey` hashes executable structure and semantic literal constants,
including the declared shape of binding/origin slots. It should exclude
attachment-specific relation versions, evaluation-local `RuleId`s, source
text, display labels, artifact paths, and debug-only provenance. The
`ProgramImageKey` can bind a set of plans to source/debug maps, occurrence
identities, cohorts, and exact bindings.

Canonicalization needs explicit ordering everywhere. A Slog relation is a
set; operator programs, source alternatives, variant ordinals, trace events,
and binding vectors are sequences. They must carry ordinals or canonical
sequence values. “Read the relation in storage order” is never part of the
PlanABI.

Persistence policy should distinguish:

- **durable:** source/program images, recipe identities, active plan/debug
  maps, committed program edits;
- **reconstructible:** typed/planned intermediate images, tier profiles,
  native artifact descriptors;
- **volatile/materialized:** `.so` paths, task objects, pointer bindings,
  query cursors, in-flight compiler status, unpinned traces; and
- **optionally retained observations:** proof graphs, trace exports, compiler
  diagnostics, benchmark profiles.

## 13. Validation and the trust boundary

A program image is ordinary queryable data but untrusted executable input
until sealed. The installer must validate at least:

- schema/PlanABI/compiler compatibility;
- unique and in-range slots and ordinals;
- complete kernel/rule/variant membership;
- dependency/SCC/cohort invariants;
- register definite assignment and operand types;
- relation arity/kind and bound-column correctness;
- legal index/view requirements;
- primitive and type-test capability;
- legal head writes and once/every/seeded classification;
- counted/maintenance flavor restrictions;
- service ownership and feedback closure;
- debug-map references, without trusting debug data for execution;
- exact executor coverage; and
- native descriptor/plan/binding ABI agreement.

Seal the complete image atomically. Relational edits naturally pass through
temporarily invalid states—an op may be inserted before its relation slot, or
a rule removed before its kernel membership edge. The daemon must never
incrementally mutate a live task graph one row at a time in response to those
draft states.

Once sealed, the decoded object graph records its `ProgramImageKey` and
`KernelPlanKey`s. Any proposed edit creates a new image/generation. This is
the invariant behind the claim that live task objects “strictly reflect” the
Slog namespace/subdatabase representing them.

## 14. Costs and risks

The proposal is not free.

1. **Schema evolution becomes PlanABI evolution.** Reflective schemas need
   versioned readers, migrations or cache misses, and explicit compatibility
   errors.
2. **The daemon still needs C++ objects.** Reflection removes anonymous and
   duplicated definitions; it does not eliminate task/cursor/index classes.
3. **Metadata can be large.** Full source ASTs, every compiler pass, proofs,
   and traces need separate retention budgets.
4. **Mounting system relations has runtime cost.** A reserved read-only
   catalog/subdatabase should not be repeatedly reloaded into every user
   stratum or accidentally receive per-worker send buffers.
5. **Bootstrapping must be explicit.** The daemon needs a small built-in
   schema/decoder for the reflective image before it can interpret reflected
   schemas. Reflection reduces the trusted core; it cannot erase it.
6. **Meta-level authority is subtle.** Queryable code, editable drafts, and
   executable active images must be visibly different states.
7. **Code availability is nondeterministic.** Artifact facts require the
   object/control semantic firewall.
8. **Incremental code changes are harder than fact changes.** Program-as-data
   makes them expressible and diffable, not automatically correct.

These are reasons to stage the work, not reasons to discard the central
image/materialization idea.

## 15. A small experiment before commitment

The first experiment can be compiler-only and behavior-preserving. Slices
are labeled RF0–RF5 (RF = reflection) so cross-document planning stays
unambiguous; repl-ux.md owns the plain R0–R5 labels.

### RF0: reflective round trip

1. Define typed schemas for Plan ABI 2's kernel plan, debug map, and cohort
   manifest.
2. Convert several real existing `.plan` sidecars into a temporary reflective
   fact database or equivalent in-memory relation set.
3. Decode them back to the canonical plan and prove byte-identical
   serialization and identical `KernelPlanKey`.
4. Query/render the image through a generic rooted-term-graph projection.
5. Measure fact count, encoded size, load/probe cost, and decoded compact-array
   size on the largest existing plans.

This answers whether the relational encoding is pleasant and affordable
without changing the daemon or compiler pipeline.

**Results (2026-07-15, `tests/reflect/rf0-roundtrip.rkt`):** the encoding
is pleasant and affordable. All **560/560** `.plan` sidecars in a warm
build cache (all six flavors) round-trip **byte-identical and
KernelPlanKey-identical** — decoded from *shuffled*, text-serialized
facts, so order-independence is proven, not assumed; deleting one fact or
swapping two `pc` ordinals breaks the gate as it should. A separate
`read`→`write` idempotence check confirms the `.plan` format itself has
no ambiguity. Scale: the largest plan (~400 KB) encodes as ~68k facts
(~170 facts/KB); fact text is ~4.5× the sexp bytes (the repeated
plan/rule/region/pc key prefix dominates); plan→facts ~3 ms, facts→plan
~20–60 ms including index building; the whole-repo sweep runs in seconds.
The schema needed 27 fact relations. Findings that should shape RF1's
Plan ABI 2 schemas:

1. **`join3` is the one genuinely nested op** — it needs per-arm child
   facts (a two-level `(pc, arm, pos)` key); a single flat
   `slog.plan.op` row cannot hold it.
2. **Variable-length integer lists** (index column orders, `ord`/`dord`
   operands) are ~60% of all facts and the whole size multiplier —
   worth one canonical sequence-value encoding rather than per-element
   position facts.
3. **Empty-vs-missing needs explicit existence facts** where the opcode
   does not fix a field's existence (relation index lists) — and this
   surfaced a live grammar straggler: a third index marker
   (`seeded-only`) that `ir-stack.rkt`'s `index?` accepts but the
   serializer's grammar comment omits.
4. **Open sexp vocabularies** (lattice merge specs, `cjoin` collection
   specs, oracle/seqindex attachment decls) fell back to a rooted
   term-tree encoding; the production schema should close them.
5. **Dual-shape `let`** (ref-copy vs prim call) decodes by the presence
   of a sibling fact — workable, but the typed schema should make the
   union explicit.

The probe script provides `plan->facts`/`facts->plan` for reuse and is
the seed of the image-based-goldens idea (§18.7).

### RF1: program model and real kernelization

1. Preserve the SCC condensation graph in a new compiler `ProgramModel`.
2. Retain source-rule origin/lineage through simplification and lowering.
3. Split same-level cohorts into individually identified kernel plans while
   retaining a compatibility adapter to the old merged strata.
4. Represent runtime services explicitly.
5. Replace downstream SCC reconstruction with model queries.

### RF2: read-only program-image mount

1. Have the compiler emit one sealed reflective image package per program or
   cohort, packaging many kernels without creating many filesystem files.
2. Mount it read-only in the daemon/control catalog.
3. Add introspection queries for programs, rules, kernels, plans, and source
   maps before using it for execution.
4. Verify save/load and cache-miss behavior.

**RF2 checkpoint (deep gate 2026-08-10):** the compiler-side logical container,
read-only daemon mount, and introspection surface are implemented.
`program-image.rkt` binds canonical declarations,
captured source tokens, lexical module/source occurrences, RF1.5 semantic
queries, and complete ABI-2 cohorts into one validated content-addressed
`.pimg`; `compile.rkt` exposes the producer and an opt-in
`SLOG_EMIT_PROGRAM_IMAGES` hook. The complete package round-trips through a
textual golden, rejects a changed seal/format, preserves two instantiations of
one source as distinct occurrences, and treats a missing output as a
reconstructible cache miss. Both compiler readers now apply explicit byte and
structural-depth quotas. The daemon's independent bounded decoder verifies
the content seal, format/ABI, dense references, embedded digests, dependency
causes, declaration/module/rule canonical order, a recomputed ProgramModel
fingerprint, SCC partition, condensation edges, and component levels,
then publishes an immutable connection-scoped mount. `catalog programs` and
`catalog program KEY [sources|rules|kernels|plans]` expose structured streams;
the REPL's `images` and `image` commands render them. Duplicate mounts report
a cache hit, missing/tampered packages are typed refusals, unmount is
non-destructive, and ordinary relation catalogs remain unchanged before and
after the lifecycle.

This chooses a compact decoded control-catalog object as RF2's first physical
mount. A mount alone is not inserted into the user `Database`, saved with
application facts, admitted to application rules, or executed. That firewall
gives introspection no accidental write or execution authority. A future Slog
meta-program surface can materialize the same records through the
freeze/import substrate; RF3's separate activation command owns complete
executable-plan verification, binding, and task construction.

### RF3: decoded interpreter

1. Build compact bound ops and generic service tasks from the mounted image.
2. Run the existing differential gates against native execution.
3. Keep the old native plugin path in parallel until the image path is proven.
4. Add the deliberately slow direct-image interpreter only if useful as a
   testing oracle.

**RF3 checkpoint (deep gate 2026-08-10): complete.** A mounted image now has one
generation-gated additive activation path. Before publishing its first task,
the daemon checks exact `ProgramModel`-component/manifest coverage, recomputes
every manifest `KernelExecPlan` key, decodes every embedded ABI-2 cohort
through the production bounded reader, seals every compact operator program,
and preflights all database-dependent relation shapes and capabilities. Each
logical cohort remains one scheduling stratum containing its declarations
carrier and kernel-local bound programs; no kernel is flattened back into a
program-wide unit.

Manifest coverage is defined over writer-containing ProgramModel components;
input-only SCCs do not invent kernels. Compiler-produced prelude kernels are
accepted as empty-member execution support and excluded from semantic
component coverage. The same definition is enforced by the Racket image
validator and the C++ activation boundary, including programs with more than
ten SCCs where dense numeric slot order differs from textual order.

Activation deliberately installs one cohort at a time. Ordinary bounded
`continue` drives cohort N to fixpoint, then registration of cohort N+1
consumes the runtime's deferred full-to-delta reload. This is the same
lifecycle as the native and standalone-plan paths and is required for
multi-level programs. The activation catalog reports pending/settled state,
duplicate activation is idempotent, active images cannot be unmounted, and
the REPL exposes `image KEY activate` plus the `activation` view. A two-cohort,
multi-head program runs through both a forced native artifact and the mounted
decoded interpreter and produces the same settled result; malformed model /
manifest coverage is refused before task installation. The old native plugin
and descriptor paths are unchanged and remain the parallel executor for RF4
coverage/materialization work.

This is additive startup/extension, not program replacement. It does not
create drafts, infer lineage, heal a writer cone, or publish a successor
program version; those authorities remain RF5-A/RF5-B. The optional slow
direct relational interpreter was not added—the production decoded VM already
provides the useful differential boundary without a second semantics.

### RF4: kernel-aware native materialization

1. Make native descriptors identify plan/variant slots.
2. Register artifact and attachment observations in the control catalog.
3. Support partial native coverage without rebuilding unrelated interpreted
   kernels.
4. Treat missing cached files as rebuildable misses.

**RF4 checkpoint (2026-08-09): complete.** T4's coverage-bearing descriptor
already identifies the sealed kernel plan, descriptor-native slot, and dense
variant slots, and already runs partial coverage as native plus the decoded
complement. RF4 now records the content-addressed artifact and each live
attachment's exact coverage partition in the control catalog. The
image-local `materializations` view joins those observations back to immutable
plan/kernel slots; an absent or vanished `.so` is reported as `cache-state
miss` with full interpreted coverage. Paths remain volatile hints, and none
of these observations enter application relations or save/replay semantics.
The gates observe shared native attachments, a true mixed variant partition,
the matching image-slot join, and a loaded artifact becoming a rebuildable
miss after its copied cache file is removed. The detailed identity and catalog
contract is [rf4-contract.md](rf4-contract.md).

### RF5: draft program transformations

1. Expose immutable source/program images to explicit meta-program runs.
2. Produce `ProgramEditProposal` images, not live mutations.
3. Add validate/seal/preview/commit at a program boundary.
4. Produce separate source/occurrence, normalized semantic, and execution-plan
   diffs; record explicit old/new module and relation-slot lineage rather than
   inferring correspondence from names or source locations.
5. Connect activation to private incremental writer/cone healing and the
   permanent clear-and-rerun fallback, then publish the image, bindings,
   versions, counts, and recipe event atomically.
6. Ship instantiated-module replacement and binding-tuning as the first
   end-to-end workflow in [rf5-contract.md](rf5-contract.md).
7. Only then consider automatic outer meta-fixpoints or direct expert plan
   editing.

**RF5-A checkpoint (deep gate 2026-08-10): complete.**
`compiler/program-change.rkt` implements exact image-bound module handles,
immutable draft revisions, explicit preserve/replace/remove/add lineage for
module, rule, and prospective relation-output slots, and a sealed
content-addressed `ProgramChangeSet`. Sealing refuses incomplete or reused
lineage and computes three distinct products: occurrence/source changes;
normalized declaration/rule/fact/dependency/writer/SCC changes with affected
roots and the union old/new cone; and ABI-2 cohort/kernel/binding/service
changes with reusable `KernelPlanKey` multiplicity. Incompatible mapped
relation shapes and modified alias/type declarations become typed compiler
refusals rather than mutations. Oracle side channels and service attachment
changes enter the union cone, while source facts share the compiler's
constant-class classification. Format 1 is pinned by two ordinary
compiler-produced ABI-2 images plus
`tests/change-expected/rf5a-rule-removal.pchange`, and consumed through the
independent `tests/api/program-change-consumer.rkt` without producer structs or
codecs. Both compiler readers are byte/depth bounded; the codec admits only
closed canonical data and contains no live `VersionId`, route, or publication
decision. RF5-B now owns resolving the artifact against a
committed boundary, private cone rebuild/recount, and atomic publish/abort.

## 16. Questions to work through

1. Is the reflective image stored in the ordinary database engine, a
   read-only mounted system subdatabase using the same value format, or a
   compact file with a relational view? “Queryable as Slog” does not force
   one physical answer.
2. Which reflective relations may an ordinary object-plane program read?
   Source and plan structure are deterministic; runtime artifacts and debug
   observations are not.
3. Does every program receive an implicit `slog.self` binding to its own
   image, or must reflection be imported explicitly?
4. Is `ProgramImageKey` content-addressed, recipe-occurrence-addressed, or a
   record joining a content key to occurrence keys? The likely answer is the
   third.
5. What is the smallest typed op schema that is pleasant both to query and to
   decode? One struct per opcode is explicit; one compact opcode/operand union
   is smaller.
6. Should index selection be canonical per kernel, or should kernel plans
   express logical selection requirements while a cohort binder chooses
   shared physical indices?
7. How are built-in service nodes represented without making diagnostics,
   oracles, or sequence indices look like ordinary user rules?
8. Which compiler IR passes deserve persistent images, and which should be
   generated only for `explain compiler ...`?
9. **Resolved for RF5:** lexical `RuleKey`s do not survive as the same key
   across immutable program occurrences. A draft records explicit old/new
   `RuleLineage` for navigation, while an alpha-normalized semantic
   fingerprint decides whether database semantics changed; see
   [rf5-contract.md](rf5-contract.md) §2 and §4.
10. Can a meta-program inspect its own source image while producing a
    successor proposal without creating an accidental dependency of its
    application facts on control-plane state?
11. Should compiler services reuse the existing oracle registry or only its
    queue/memo abstractions? Program activation has different transactional
    and trust requirements from an in-fixpoint `extern` answer.
12. How are artifact hashes checked or signed before loading, especially if a
    future remote compiler populates the cache?
13. What retention/GC roots keep old program images, proof graphs, and
    artifact records alive?
14. Is a Slog-in-Slog reference interpreter valuable enough to become a
    conformance oracle, or merely a delightful demonstration?

## 17. What seems worth pushing forward, and what to resist

The following ideas appear strong enough to shape the near-term design:

- a first-class compiler `ProgramModel` preserving rules, edges, SCC kernels,
  cohorts, and services;
- Plan ABI 2 split into `KernelExecPlan`, `DebugMap`, binding schema, and
  cohort manifest;
- a typed immutable reflective `ProgramImage` as the common persisted and
  queryable exchange;
- daemon interpreter/native objects as validated materialized views of that
  image;
- plan-local structured slots instead of source-location or display-string
  identities;
- one rooted-term-graph projection for REPL navigation across values, plans,
  proofs, why-not, traces, and compiler IR;
- artifact/compiler state represented in a Slog-shaped control catalog but
  fenced out of application semantics; and
- program edits as immutable proposals compiled and activated atomically at
  boundaries, with incremental healing afterward.

The following should be resisted or explicitly deferred:

- one `.so` or one runtime stratum per semantic SCC;
- one universal untyped node relation as the authoritative schema for every
  object;
- database probes of plan facts in every production interpreter hot step;
- ordinary application facts depending on O0/O2 availability, debug state,
  compiler timing, or cache paths;
- treating a temporary `.so` path as durable truth;
- exposing raw pointers/cursor state as persistent reflective values;
- incrementally mutating a live task graph one reflective row at a time;
- allowing a rule to rewrite the active program halfway through its own
  fixpoint; and
- assuming that program-fact deltas can use ordinary EDB incrementality
  without a program-version activation protocol.

The most promising cut is therefore not “Slog literally executes every
operator by querying its own rule tables.” It is:

> **Programs are immutable typed Slog databases; execution engines are fast,
> validated materializations of those databases; introspection and
> transformation operate on the databases; activation changes program images
> only at explicit semantic boundaries.**

That model captures most of the meta-circular elegance and practical
introspection benefits while preserving a small, fast, and auditable runtime
core. It also leaves the genuinely meta-circular future open: once programs
and plans are ordinary typed Slog data, writing more of the compiler or a
reference interpreter in Slog becomes an experiment rather than a redesign.

## 18. Review addendum: staging verdict and refinements

2026-07-14, same-day review pass. The sections above ask whether the
reflective image should become the common exchange model; this section
records the resulting verdict and several refinements worth pinning.

### 18.1 Two layers with different urgency

The proposal decomposes into a logical layer and a physical layer, and the
tempting framing — "reflection versus prototyping the C++ directly first" —
is a false binary because the layers have opposite timing constraints.

- The **logical layer** — the compiler `ProgramModel` (RF1), the §12
  identity taxonomy, and the Plan ABI split into `KernelExecPlan`,
  `DebugMap`, binding schema, and cohort manifest — must land **before**
  the daemon interpreter (execution-tiers T2) hardens. T2's plan installer
  is the first production consumer of the `.plan` sidecar; whatever shape
  it consumes will ossify, and §1's migration-free window closes the day it
  ships. This layer is barely extra work: T2 must parse *some* format, and
  stats.md §4, execution-tiers.md §2, and the incremental substrate have
  already independently converged on the same durable keys. Three documents
  defining the same identities separately is itself the argument for one
  authoritative home.
- The **physical layer** — storing images as actual Slog subdatabases, the
  mount, the control catalog, and any meta-program surface — should land
  **after** T2/T3 prove the interpreter, exactly as RF2–RF5 stage it.

Adopting the logical schema decomposition now does not force the physical
answer; every option in §16.1 remains open.

### 18.2 Precedents that de-risk the design

Three existing mechanisms make the central bet much less exotic than it
first appears.

1. **The system-catalog pattern.** Every serious RDBMS stores its schema as
   rows (`pg_catalog`) and executes through decoded caches (the relcache)
   that are rebuilt on invalidation and changed only at transaction
   boundaries. §6.2's decode-at-install model is that proven architecture
   applied to plans, which such systems also cache in decoded form.
2. **`$stat_*` is the shipped embryo of the control plane.** stats.md §2's
   boundary-observer law already implements a runtime-owned namespace that
   active rules cannot read, excluded from saves and goldens. §8's firewall
   generalizes a working mechanism rather than inventing one.
3. **Freeze/import is the mount substrate.** An image is a frozen database
   produced by the compiler. `slog-freeze` already turns fact streams into
   `.bin` databases through the daemon encoder, and `importDatabaseBIN`
   already performs the four-id-space remap. RF2 should ride that machinery
   — packaging, content addressing, read-only mounting — rather than
   defining a new format. This is the likely physical answer to §16.1.

### 18.3 An image is an ordinary value; only activation is special

The sharpest open question about the `slog.*` schemas — special namespace,
or real manipulable data? — resolves cleanly: **as a value, a ProgramImage
is ordinary** (sealed, typed, immutable; queryable, joinable, transformable,
diffable), and **only the binding of image to executor is special**, changing
solely at validated activation boundaries. A symmetry worth stating:
stratification is phase separation in the object language; program
generations are phase separation in the meta language. Negation needed
strata; self-modification needs activation boundaries. Neither is a
limitation to apologize for.

Consequently the fully automatic loop — a meta-program reads images, derives
new source-level rules, the compiler service seals a successor image, a
controller activates it at the next boundary, and incremental healing
repairs the cone — is legal and expressible under §10's staged model. What
can never exist is a rule whose head writes the plan tables of the fixpoint
executing it.

### 18.4 The service-contract spectrum

The oracle analogy (§9) sharpens into a spectrum, because the three services
have different — in one case opposite — semantic contracts:

| service | contract of its answers |
|---|---|
| SMT oracle | discovered inputs: pinned, replayed, semantically real |
| program compiler | semantically real, but only at activation boundaries |
| native materialization | semantically invisible, always |

All three share queue/memo/pool/racing infrastructure. Neither compiler
service may reuse the `extern` pinning contract: the compression-pinning
machinery that makes SMT sound (answers become replayed inputs) is exactly
what compile results must never receive.

### 18.5 Derived watches: the first meta-program worth building

Declarative debugging is the near-term flagship use. A meta-query over
`slog.program.dependency` derives `WatchRequest` facts in the control plane;
the session applies them through the ordinary watch protocol. repl.md §6's
invariant — watches are protocol capabilities, never program facts — stays
intact: rules derive *requests*, the client installs them.

Two properties make this compelling. First, "which relations could
transitively contribute to a derivation of `(model.error _)`" is literally a
Datalog query — ancestors in the rule-dependency graph filtered by head
unification — so watch cones, blame sets, and why-not frontier chases are
the language's home turf. Second, watches derived by rules are **semantic
rather than lexical**: "watch whatever feeds `model.error`" re-derives
correctly after a refactor, where a handle pinned to one `VersionKey` dies
with its version. Refactor-surviving watches are a capability no comparable
system offers.

### 18.6 Program diffs are on the incremental critical path

Two clarifications on "extending incrementality to rules." First, rule
deltas are still not EDB deltas — §10 and §17's resist list stand. But the
incremental program-edit milestones need durable rule identity and
**structured program diffs** to compute healing cones regardless of this
document's fate; without the image, an ad-hoc diff format gets invented
under another name. The image is therefore on the incremental critical path,
not beside it. Second, *analyses over* images are ordinary programs over
closed inputs, so when image P2 replaces P, lint results, rule call graphs,
and derived watch sets heal through the ordinary maintenance machinery.
Program-analysis results that update incrementally as programs are edited
compose for free.

### 18.7 Image-based goldens: the selfish payoff

Make images the golden format for compiler tests. Assertions such as "this
rule's plan uses `join3`" or "this SCC split into three kernels" become
relational facts instead of string matches over emitted C++ or curated CSVs,
and compiler-regression triage becomes a relational diff of two images
through the same diff machinery the REPL already plans for data. This pays
back during T2–T4 development itself, long before any reflective feature
ships — and it forces the encoding to be pleasant early, which is RF0's
question.

### 18.8 The sidequest test and the recommended order

The test for elegance-chasing: *which parts would be built anyway under
different names?* The ProgramModel (T4 needs kernel boundaries, stats needs
execution identities, incremental needs writer attribution), the ABI split
(T2 needs a wire format), the identity taxonomy (three documents demand it),
and the firewall (needed the moment watches meet the recipe) — roughly the
load-bearing majority — are already-committed work that reflection merely
names coherently. The severable remainder — physical mount, meta-program
surface, self-hosting — is staged last (RF2, RF5, beyond). A vision whose
elegant core is its load-bearing core passes the test. The failure mode to
guard against is the inverse one: shipping T2 against a monolithic bespoke
ABI and paying a migration after consumers exist.

Recommended order, coordinated with the cross-stream plan in
[roadmap.md](roadmap.md):

1. **Now, with/before T2:** RF1 and the four-way ABI split, adopted as the
   logical structure of T2's wire format; RF0 as a roughly one-week probe
   over the largest real `.plan` sidecars, with measurements recorded here.
2. **In T2 from day one:** every task records
   `(image_key, plan_key, variant_slot, pc)` — the "strictly reflects"
   invariant costs almost nothing at install time and cannot be retrofitted
   cheaply.
3. **After T2/T3:** RF2 via the freeze/import machinery; image-based
   compiler goldens; a first Slog-written lint over the mounted image as
   the control-plane proof of concept.
4. **After the REPL's first slices and M7:** derived watches (§18.5) as the
   flagship meta-query; then RF5 draft/activate with incremental healing.
5. **Explicitly parked:** direct plan editing, the automatic outer
   meta-fixpoint, and self-hosted compiler passes — until the above is
   boring. When self-hosting is attempted, it should proceed a pass at a
   time (stratification is transitive closure plus SCC condensation, the
   language's home ground), each pass differentially tested against the
   Racket implementation, both emitting images.
