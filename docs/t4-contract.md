# T4 — parameterized native bundles (contract draft)

*Drafted 2026-08-03 (W4′, after the T5 arc closed).  **Status: design
contract, pending review — §7 holds the questions.**  Normative parents:
[execution-tiers.md](execution-tiers.md) §2.2 (the identity ladder), §2.3
(relation identity in rules), §11's T4 item list;
[rf1-contract.md](rf1-contract.md) (the 4-way ABI split, whose
KernelExecPlan/BindingSchema separation T4 consumes);
[n1-contract.md](n1-contract.md) (module instances, T4's motivating case).
This document pins what T4 must be true of, the slice order, and the exit
gates; the parents stay authoritative for mechanism.*

## 0. What T4 is for

One sentence: **make a compiled artifact a function of a KERNEL, so one
artifact can serve every attachment of that kernel** — the property the
interpreter has had since T2 and native code has never had.

execution-tiers §11 lists four items: canonical binding slots plus a
`CodeDescriptor` and per-native-slot task factories (1); one artifact
attached repeatedly with distinct BindingFrames/RuleIds, recording
per-attachment read/write VersionId maps (2); module-SCC code units
separated from runtime-stratum grouping, with coordinator manifests for
sharded SCCs (3); and per-rule rather than per-kernel selective emission
(4).

## 1. The measurement (2026-08-03, `tests/n1_instances.slog`)

The motivating program instantiates one library twice:

```
instantiate "n1_graph_lib.slog" as left
instantiate "n1_graph_lib.slog" as right
```

A clean compile produces, among six kernel plans, one per instance —
`5079b034.plan` (left) and `c949ab35.plan` (right).  They are NOT
alpha-equivalent, and every reason they differ is a T4 blocker:

- **B1 — the relation table is program-global and name-bearing.**  Both
  plans list all 18 relations of the whole program (`answer`, `left.edge`,
  `left.path`, `right.edge`, `right.path`, `seed`, plus the service
  structs) with their qualified names, though each kernel touches three.
  So a kernel's bytes depend on sibling kernels and on unrelated
  declarations — RF1 lists the opposite ("a kernel's bytes never depend on
  sibling kernels") as a property to be PROVEN, and it is not true today.
- **B2 — the code unit is the runtime stratum, not the module-SCC.**
  left's unit holds exactly its two rules; right's holds THREE, because
  the root program's `rule (seed X Y) --> (left.edge X Y)` sits at the same
  stratification level and was grouped with it.  One instance's artifact
  therefore contains a rule belonging to another module and writing
  another instance's relation.  Two instances of one library cannot share
  an artifact while the unit is a scheduling container.
- **B3 — native codegen bakes names as string literals.**  `emit-cpp.rkt`
  emits `db->getRelation("left.edge")` (and `addRelation`/`addStruct`/
  `addIndex` likewise), and `slog_plugin(Daemon*)` builds its stratum by
  name.  The artifact is welded to one binding environment.
- **B4 — `KernelPlanKey` hashes the names, the sources and the whole
  table.**  `kernel-plan-key` (canonical-plan.rkt) is the sha256 of the
  entire serialized plan, `(meta (rule-meta … (source …)))` and the
  relation table included.  Even with B1–B3 fixed, the key would still
  separate two identical kernels.

**Consequence for the slice order: T4 cannot start with its item 1.**
Parameterizing the native artifact buys nothing while the unit it
parameterizes is a stratum-shaped mixture (B2) whose plan text is
program-global (B1) and whose key is name-bearing (B4).  The item order in
§11 is a list of properties, not a schedule.

## 2. Standing pins

1. **The interpreter is the reference implementation.**  A sealed kernel
   plan is already slot-addressed and bound through a frame
   (`bind_kernel_plan(plan, db)` resolves `bindings[i].name` to a
   `Relation*`).  T4 does not invent a binding model; it gives native code
   the one that exists, and where the two disagree the interpreter is
   right.
2. **One re-key, and it is RF1's.**  RF1 promises exactly one plan re-key
   (ABI 1 → the 4-way split) and states that "T4's alpha-normalized
   KernelPlanKey gate goes live over this key without another re-key".
   T4 therefore must NOT invent a second normalization: B1/B4 are fixed by
   landing the split, not by patching the current serialization.
3. **Coverage is native ∪ interp-designated, always.**  Every kernel runs
   somewhere at every moment of the transition; a kernel whose native
   artifact is absent, stale, or refused runs interpreted, which is
   already the shipped default for flavored work.
4. **Counts are recomputable, never remapped.**  A `KernelPlanKey` change
   invalidates count sidecars established under the old plan
   (incremental.md §8B.3).  The re-key of pin 2 is therefore a
   recount-forcing event, and the slice that lands it says so in its exit
   gate rather than trying to preserve sidecars.
5. **Writer attribution is per attachment, not per plan.**  One
   `KernelPlanKey` serves many attachments, so each `AttachmentId` records
   its own read/write `(name, VersionId)` maps — the audit that counts and
   the walk machinery key on (incremental.md §0.4, §4.2).  This is why
   item 2's "record per-attachment maps" is not optional bookkeeping: it
   is what keeps DRed^c sound once artifacts are shared.
6. **Determinism is a precondition, not a consequence.**  Artifact reuse
   is content-addressed, so a plan whose bytes churn cannot be reused
   safely.  `tests/plan-determinism.sh` is the gate; rf1-contract's open
   tie-group defect (alpha-equivalent rules pairing rids with temps
   independently, `examples/verify/verify.slog`) must be closed or proven
   absent before any slice claims sharing.

## 3. Slices

- **(0) Determinism re-established.**  Run the plan-determinism gate; close
  rf1-contract's tie-group defect if it still reproduces (its documented
  fix direction: make the rid assignment reuse the canonical walk's order
  including minted temp names, or give the sort key a same-stratum
  tie-group ordinal shared by both walks).  Exit: two clean full golden
  tiers with identical `build/` filename sets and byte-identical `.plan`
  sets, `examples/verify/verify.slog` included.
  *(2026-08-03: a 3-run spot check over verify.slog was byte-identical;
  the full gate was started, then invalidated by a concurrent build of
  mine and needs a clean re-run.  Unverified, not clean.)*
- **(1) The kernel becomes the unit (B1 + B2).**  Split the code unit from
  the scheduling container: a plan is emitted per module-SCC, its relation
  table is KERNEL-LOCAL (only the slots that kernel binds), and runtime
  strata become an ordered grouping of kernel instances rather than the
  thing that gets compiled.  Coordinator manifests describe a sharded
  SCC's parts.  This is where RF1's split lands (pin 2), so it carries the
  one re-key and the recount it forces (pin 4).  Exit: `n1_instances`
  emits ONE kernel plan for the library, attached twice; a kernel's bytes
  are unchanged by adding an unrelated declaration or an unrelated rule at
  the same level (the property RF1 asks to be proven); full suite green
  with counts re-established.
- **(2) Native slot indirection (B3).**  `emit-cpp` stops emitting names:
  relation access becomes a frame index, and the artifact exports a
  `CodeDescriptor` (slot table with kind/arity/required orderings, rule
  variants with their kernel-local ids) plus per-native-slot task
  factories.  `slog_plugin` splits in two: the daemon owns relation
  creation and stratum construction (it already does, through the N3
  boundary machinery), and the artifact owns only `slog_attach(Daemon*,
  const AttachRequest*)`.  Exit: one `.so` attached twice in one run with
  distinct frames, byte-identical results to two separate artifacts;
  descriptor/frame mismatch refuses structurally rather than
  null-dereferencing (the `v_c<k>` mangling crash of 2026-07-11 is the
  cautionary case — a name mismatch across TUs segfaulted in `bind`).
- **(3) Attachment identity (item 2's second half).**  Per-attachment
  read/write VersionId maps and per-attachment RuleIds, so stats,
  provenance, watches and the count/walk audits stay per-instance while
  the code is shared.  Exit: `$stat_fires` and level-1 watches attribute
  to the right instance with one artifact attached twice; a recount over
  the shared kernel agrees with the sidecar per attachment.
- **(4) Per-rule selective emission (item 4).**  With the unit at kernel
  granularity, emission can drop to per-rule: compile the hot rules of a
  kernel natively and leave the rest interpreted, coverage still
  native ∪ interp.  Exit: a kernel running mixed native/interp rules
  produces results byte-identical to either pure tier.

## 4. What this unlocks (why it is worth the re-key)

- **Compile time.**  A library instantiated N times compiles once.  The
  measured case is 2; the r7rs/analyzer programs instantiate far more.
- **T6.**  Transactional mid-read replacement needs a native task to be
  constructible against a frame at runtime; a name-welded artifact cannot
  be swapped in mid-read.
- **T3b policy.**  Per-SCC tier decisions become per-kernel decisions
  shared across instances, so a hot library pays for one compile and every
  instance gets the tier.
- **The differential.**  With one artifact per kernel, the native leg of
  the dual-executor differential stops being per-instance work, which is
  what makes it affordable to keep running as instances multiply.

## 5. Exclusions

Interpreted-path changes (the model is already right).  New flavors — the
interpreter-before-new-flavors rule stands, and T4 touches emission only.
Cross-kernel fusion or inlining.  Anything that would make a kernel's
bytes depend on its attachment.  T6's mid-read replacement itself.

## 6. Risk register

- **The re-key is wide.**  Every artifact hash and every count sidecar
  moves once.  Mitigation: land it as slice 1's own commit with the
  plan-determinism gate before and after, and treat recount as expected
  output rather than a regression.
- **`emit-cpp.rkt` has been dormant since W1** (roadmap: "dormant between
  the W1 ABI split and T4").  Its determinism machinery
  (`canonicalize-vrefs`, content-addressed clusters, per-TU counters) is
  load-bearing and subtle; slice 2 must keep TU text a pure function of
  its rules, and the `keep-names` protection disappears along with the
  names, which is a simplification but also a behavior change to prove.
- **Struct/lattice slots carry more than a name** (type ids, lattice
  specs, master orderings).  The descriptor must carry enough that a frame
  can be validated, or slice 2 trades a name mismatch for a shape
  mismatch.
- **Scheduling regressions.**  Runtime strata group same-level SCCs
  deliberately, for reload and fixpoint efficiency; slice 1 must keep that
  grouping while changing only what gets compiled.

## 7. Review questions

1. **Sequencing across streams.**  Slice 1 IS RF1's 4-way split (pin 2).
   Does that work land as RF1 slices 1–2 in the reflection stream and T4
   consume it, or does T4 absorb it?  The measurement says T4 cannot
   proceed without it, so the choice is about ownership and commit
   boundaries, not about whether.
2. **How far to take the descriptor.**  Minimum is slots + orderings +
   rule ids.  Maximum is RF1's full CohortManifest with the sharded-SCC
   coordinator.  Proposal: the minimum that lets slice 2's refusal be
   structural, deferring the coordinator to slice 1's manifest work.
3. **Where relation creation lives after slice 2.**  Proposal: entirely
   daemon-side (the N3 boundary machinery already creates declared
   storage; the artifact stops calling `addRelation` at all).  This makes
   an artifact pure code, but it moves index requisition into the
   install path — worth confirming before the emission change.
4. **Does the recount of pin 4 need a migration story** for long-lived
   databases, or is "counts are a recomputable cache, re-establish them"
   sufficient at this stage?  (M0's doctrine says the latter; the question
   is whether any saved database in `data/` is expensive enough to matter.)
