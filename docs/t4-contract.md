# T4 — parameterized native bundles

*Drafted 2026-08-03 (W4′, after the T5 arc closed).  **Status: T4 IS
COMPLETE (2026-08-08) — every slice shipped with its exit gate green;
the ledger below records each mechanism, commit, and gate.  §7 records
the entry ratifications.**  Normative parents:
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

## 0.1 Completion ledger (2026-08-08)

Every slice's mechanism lives in its §3 as-built; this is the one-screen
map of what shipped where and which gate holds it.

| slice | commit | shipped | exit gate |
|---|---|---|---|
| (0) determinism re-established | (gate run) | 08-03 | plan-determinism 2×full-golden clean; tie-group mechanism fix |
| (1a) kernel-local slot requisitions | 5b54f85 | 08-06 | airtight `sibling-requisition-changes-no-key` + `asymmetric-consumption-shares-the-kernel` (pre-fix failure demonstrated) |
| (2a) canonical emission order + kernel clusters | 355c2fe | 08-07 | `tu-determinism` tier (the 18-of-42 permuted-TU defect, dead); plan bytes unmoved |
| (2b) name-free kernel clusters | 407ba3b | 08-07 | `cluster-name-freedom` + `cross-instance-cluster-collapse` (n1's two instances → ONE cluster fn) |
| (2c) descriptor attach protocol | cd318e9 | 08-08 | `symmetric-shared-kernel-in-one-cohort` + `double-attach-byte-identical` (one `.so`, two frames); tiered 9/9 over descriptor artifacts |
| (3) attachment identity + accept re-key | 6b08d6c | 08-08 | airtight `struct-library-shares-a-kernel-key` (the RF1 gap, closed); `attachment-records-disaggregate` + `per-attachment-recount-agreement` + `per-instance-fire-attribution` via the `(attachments)` verb |
| (4) per-rule selective emission | (this commit) | 08-08 | `mixed-tier-{even,odd,none}` + one FULL golden sweep under `SLOG_NATIVE_COVERAGE=even SLOG_OPT=0` (168/168) |

What §4 promised is now real: **T6's prerequisite is met** (native tasks
construct against daemon-supplied frames at attach time), **T3b's tier
decisions can be per-kernel** (the descriptor is the unit), and the
dual-executor differential's native leg stops being per-instance work.

**Standing residue, all recorded in place:** the greedy index packer's
subset-chain re-packing and lattice-master re-homing (slice 1a as-built,
residues (i)/(iii)); writer-emit masters ACCEPTED on measurement
(17/1172 kernels, all `$sup`); flavored artifacts still export the (2b)
`slog_plugin` spine (differential-only; migrate on need); the
`(RuleId, VariantTag)` stat rekey deferred to T0's durable-RuleKey arc
(slice 3 as-built records why); cold-compile overhead ~17→~29 min on the
golden tier with the small-kernel per-`.so` re-merge as the lever if it
starts to matter; `SLOG_PLAN_ABI=1` is an interp-only compatibility mode
(2c as-built).

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

### 1.1 A cheaper path, measured and refuted (2026-08-03)

Before committing to the slice order below, one shortcut deserved a
measurement.  Production artifact identity is NOT `KernelPlanKey` — that
function is called only from tests — it is the job hash plus the
**content-addressed `.o` cache**, keyed on each TU's comment-stripped
source with clusters named by the hash of their emitted body
(fast-compile §14).  So the hypothesis was: strip relation names out of
the generated rule bodies and the existing cache would start sharing
clusters across instances (and across programs with the same rule
shapes), delivering T4's compile-time benefit with no ABI change at all.

It does not hold.  Over the cold golden suite — **592 generated TUs, 37 MB
of text** — normalizing every relation/struct/index name literal, every
stratum name and every content-derived cluster function name collapses
**0** TUs: 592 distinct before, 592 after.  The decisive small case says
why: for `n1_instances`, even normalizing EVERY string literal, value ref
and function name leaves left's TU (17,611 chars) and right's (19,499)
different, because each TU carries the WHOLE PROGRAM's relation
registration prelude (all 17 relations, in every TU) and right's unit
holds an extra rule that grouping put there (B2).

So name-freedom alone buys nothing measurable.  The sharing that T4
promises needs the unit to be kernel-shaped (B2) and its prelude to be
kernel-local (B1) — which is the expensive work, not a way around it.
The measurement's value is exactly this: it was proposed to de-risk a
cheap path and it killed it.

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

- **(0) Determinism re-established.**  *(Shipped 2026-08-03.)*  Run the plan-determinism gate; close
  rf1-contract's tie-group defect if it still reproduces (its documented
  fix direction: make the rid assignment reuse the canonical walk's order
  including minted temp names, or give the sort key a same-stratum
  tie-group ordinal shared by both walks).  Exit: two clean full golden
  tiers with identical `build/` filename sets and byte-identical `.plan`
  sets, `examples/verify/verify.slog` included.
  *As-built (2026-08-03):* the gate PASSES clean — two full golden tiers
  (167/167 each), **2621 `build/` filename entries identical, 506 `.plan`
  files byte-identical**.  The 2026-07-29 tie-group defect did NOT
  reproduce, so the fix landed on the strength of the mechanism rather
  than a failing run: `sort` is stable, so a tie group kept SET-ITERATION
  order, and the rid walk (canonical-plan.rkt `entry<?`) orders crules by
  canonical text — which CONTAINS the minted temp name.  The rid ↔ temp
  pairing therefore followed the temp walk's arbitrary choice while each
  rid's recorded SOURCE did not, so `(rule-meta (rid N) (source LOC))`
  flipped run to run.  `canonical-rule-order` now breaks ties by source
  location, the same way the rid walk does, and the property under test
  is input-order independence: `tests/unit/planner-tests.rkt` asserts the
  two keys genuinely TIE and that both input orders yield source order
  (pre-fix, a stable sort returned `:83` before `:79` — demonstrated
  directly before landing).  A residual tie — alpha-equivalent AND
  same-location, e.g. a `|`-split rule's derivatives — is genuinely
  interchangeable, because their metas are identical too.  Note for
  slice 1: after RF1's split this churn would live in DebugMap only and
  could not move a KernelExecPlan or its key.
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
  *Status (2026-08-06):* RF1 shipped the split (ABI 2 default 003af8b,
  goldens of record 142dd45), so this slice is banked EXCEPT the
  rf1-contract "Known limitation": slot PAYLOADS carry stratum-union
  orderings, which leaves the bytes-unchanged exit property unprovable.
  That residue is slice (1a) below.
- **(1a) ENTRY SLICE — kernel-local requisitions (ratified 2026-08-06:
  FIX, not accept).**  A kernel's slot payload keeps only identity fields
  (kind, arity, a struct's canonical master ordering, a lattice's spec)
  plus the orderings ITS OWN exec ops reference — which are derivable:
  every ordering-consuming op (`scan`/`join*`/`emit`/`mkstruct`/`tycheck`/
  `absent-*`) names its ordering inline.  The stratum union moves nowhere:
  the cohort `(declarations …)` block already carries it and installs
  first (plan.cpp's rule-free declarations plan, `declared`-set dedup), so
  the daemon's index set is unchanged; only the hashed bytes stop carrying
  sibling requisitions.  Rationale: index maintenance is storage-side
  (`Relation::addIndex`, idempotent; relations maintain their own
  orderings on ingest), so "which indexes exist" is attachment
  environment, not kernel computation — the same doctrine as §5's
  "nothing may make a kernel's bytes depend on its attachment".  This is
  a second global re-key, accepted deliberately at the cheapest moment it
  will ever have (no artifact cache keys on kernel keys yet; goldens one
  day old; re-record sanctioned same-commit per RF1 slice 4).  Deciding
  the other way and fixing later would re-key AFTER T4/T3b content-address
  on the keys.  Exit: the bytes-unchanged property of slice (1) holds and
  is GATED (add an unrelated same-level rule requisitioning a new ordering
  on a bound relation ⇒ untouched kernel's key byte-identical); asymmetric
  cross-program consumption of a library's exports no longer forfeits
  sharing; abi2-airtight + abi2-differential + rf0-roundtrip +
  plan-determinism green; plan goldens re-recorded in the same commit.
  *As-built (2026-08-06).*  Slot payloads are own-use: kind + arity
  (+ a lattice's spec/decomp) + exactly the orderings the kernel's ops
  reference — full-side from `join*`/`exists`/`absent*`/`emit`/`mkstruct`
  and join3 arm orders, delta-side from probe drivers, `join-old/new` and
  `absent-old/new/ever` delta orders and viewed join3 arms, plus two
  implicit consumers tracked explicitly: `emit-lat` marks its slot's
  MASTER (the merge layout the daemon validates via `front()`), and
  `tycheck` attributes its ordering to the by-name malformed_deduction
  service slot.  Scan drivers are nominal (plan.h: `order` empty), so a
  scan-only PLAIN slot legitimately carries NO orderings; the daemon's
  "no master ordering" pre-check now applies only to the rule-free
  declarations carrier, which owns registration — `validate_order` and
  the registration walk's own master check still guard every consumption
  point.  **Two same-day refutations shaped the final rule:**
  (1) the first draft kept EVERY decl's leading index as "identity" and
  the new sibling gate refuted it — a plain relation's master is the
  packer's EMPTY-selection assignment, and the empty selection is
  subset-compatible with every chain, so a sibling's new selection
  re-homed `edge`'s master `(0 2 1)`→`(1 0 2)` and re-keyed a kernel
  through an ordering it never uses; (2) the pure-own-use overcorrection
  was refuted by the golden tier (11 lattice-family fixtures) — a
  delta-scan-driven lattice consumer marks no ordering and the decoder's
  grammar refuses a bare lattice slot ("lacks spec/decomp/index").
  Final rule: STRUCT and LATTICE slots keep their leading master
  unconditionally — a struct's content master is canonically pinned
  `(1..n 0)` (sibling-independent by construction), a lattice's merge
  master is semantic and grammar-required — while PLAIN relations ride
  nothing.  KNOWN RESIDUE (next layer, not this slice): (i) the greedy
  index packer serves subset-CHAINS with one ordering, so a sibling
  selection subset-related to a kernel's own can legitimately re-pack
  the ordering its op bytes embed; (ii) a WRITER kernel's `emit` embeds
  its target's master, so empty-selection master re-homing still re-keys
  writers (readers are now immune); (iii) lattice masters share the
  empty-selection churn risk in principle (their slot keeps the master).
  All trace to program-global index packing; fixing them means canonical
  per-relation masters or kernel-local packing — measure before deciding,
  at slice 2 entry.
  *MEASURED at slice 2a (2026-08-07, full golden suite, 506 cohorts):*
  5713 plain relation decls, 214 (3.7%) with non-identity masters; 1172
  kernels, 1038 writers, and only **17 kernels (1.5%) embed a re-homable
  master in an emit op — every one a `$sup` supplementary relation**,
  whose names embed program-specific hashes and therefore never
  cross-program-share regardless.  DECIDED: residue (ii) is ACCEPTED —
  canonical masters would cost an index on every relation to protect
  kernels that cannot benefit.  Residues (i)/(iii) stay recorded;
  revisit only if a real sharing workload surfaces them.  Gates: airtight 10/10 (two new checks, pre-fix
  failure demonstrated: 8/10 with exactly (g)+(h) failing), differential
  11/11 ×2 drafts, rf0 round-trip 6 fixtures clean, plan-determinism
  506/2621 byte-identical, unit 419, golden 167 (after refutation 2's
  fix), plan goldens re-recorded same-commit.
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
  *Sub-sliced 2026-08-07 (ratified: (2a) as the bridge, then complete
  T4).*  The 2026-08-06 code survey found the daemon half nearly free
  (operators.h is already `Relation*`/`Index**`-parameterized; the
  `add_flavored_*` ladders and the cohort declarations installer are the
  daemon-owned declaration half, built for interp; the dlopen path is 35
  lines) and the risk concentrated in emit-cpp's dormant textual
  machinery.  Hence:
  - **(2a) Kernel-shaped TUs, names still welded.**  `write-cpp` receives
    the ProgramModel and the canonical (rid, tag) map; rule emission
    order becomes canonical RuleId order (the debt T1 §11 explicitly
    deferred here); clusters partition BY KERNEL (large kernels
    sub-bucket by the existing content-hash within the kernel — the
    one-time `.o` re-bucket is sanctioned by execution-tiers §10); the
    stratum spine keeps constants/declarations/metadata/beginStratum/
    push/continueRun and calls kernel cluster functions in manifest
    order.  Exit: two clean compiles produce BYTE-IDENTICAL generated
    `.cpp` (the property measured failing 18/42 on 2026-08-03 becomes a
    gate); goldens green under DEFAULT opt (native leg) and interp; stat
    exact-once audit green; plan bytes UNCHANGED (plan-goldens passes
    without re-record).  No sharing claimed.
    *As-built (2026-08-07, SHIPPED).*  One ordering authority:
    `kernel-parts` returns its canonical `ordered` list (5th value),
    `canonicalize-cprog/abi2+groups` exposes per-manifest-kernel crule
    groups, and `write-cpp` takes `#:kernel-groups` — emitting rules in
    plan order (single-TU inline and split paths both) and clustering
    per kernel, oversized kernels sub-bucketed by the pre-2a crule-id
    hash WITHIN the kernel.  The grouping is checked as a permutation of
    the cprog's rules, loudly.  The cohort is now computed
    UNCONDITIONALLY in emit-stratum-cpp (not just when shipped/dumped):
    TU text must not fork on SLOG_PLAN_ABI, or the `.so` cache would key
    on an env var.  Legacy order/bucketing survives only for
    model-less hand-built cprogs.  Comparison is COMMENT-STRIPPED text
    (the `.o` cache's own normalization): raw bytes still differ in the
    `// <crule>` debug comments, which carry gensym spellings and are
    excluded from every hash — content permutation, the real 18/42
    defect, is dead.  Gate: `tests/tu-determinism.sh` (run-all tier
    `tu-determinism`, OUTSIDE ALL like abi2) — 7 fixtures including
    examples/kcfa (17 part TUs, the split path), 71 TUs total.
    Validated: tu-det 7/7, unit 419, golden 167/167 under DEFAULT opt
    (the registration-order change is results-invisible, as the
    interp-leg differential predicted) and 167/167 interp, stats audit,
    plan-goldens PASSED WITHOUT RE-RECORD (zero plan-byte drift from
    the +groups refactor), abi2 10/10 + differential, plan-determinism
    506 plans + 2633 filenames byte-identical (build/ entry count moved
    2621→2633: per-kernel clustering makes more, smaller part TUs for
    multi-kernel split strata — both runs identical).
  - **(2b) Name-free rule bodies.**  The head-array micro-frame
    (`head_rel[i]`) generalizes to every relation reference; task
    `bind(Database*)` becomes frame-driven; `keep-names` and the
    relation-name value-ref hazard retire with the names.  Exit:
    n1_instances' two library kernels emit byte-identical kernel cluster
    text, and the content-addressed `.o` cache collapses them — the
    compile-time payoff lands here, before any daemon change.
    *Entry findings (2026-08-07, recorded before implementation):*
    (α) `bumpFires("<loc>", "<tag>")` bakes the variant tag, which
    carries instance-qualified relation names (`delta:left.path`) — for
    clusters to collapse, TAGS become spine-supplied frame data (a
    per-rule string table beside the relation frame); LOCS stay baked
    (a library rule's file:line is instance-independent, and the stats
    audit's (loc, tag) key spelling must not change — interp's
    statsTag must keep matching).  (β) **tycheck `accept` sets carry
    struct NAMES inside hashed exec bytes** (canonicalize-crule passes
    the accept types through unresolved) — a live RF1 gap: a library
    kernel whose rules tycheck against instance-qualified structs does
    NOT share its plan key across instances; n1's proven sharing is
    tables-only.  The TU side is fixable in (2b) without moving plan
    bytes (spine-supplied sid tables, like α).  The PLAN side is a
    sanctioned re-key (accept names → slots) and is deliberately NOT
    spent in (2b): batch it with the next planned re-key (the slice-3
    stat rekey, or 2c's descriptor landing), and record it in the
    airtight gate's known-gaps note until then.
    *As-built (2026-08-07).*  Kernel cluster text is fully name-free:
    every relation reference is `f[slot]` against the kernel's binding
    frame (`slot` from the plan's own rel-ix, exported through
    `canonicalize-cprog/abi2+groups` — the frame layout authority is the
    binding schema, not a second derivation); accepted tycheck structs
    ride a frame APPENDIX (slot table first, then first-use order); the
    stats key arrives as spine-supplied `vloc`/`vtag` tables — BOTH
    halves, because the loc is instance-qualified too
    (`right#1@lib.slog:4`), which the first cut missed;
    `prim-error-check` emits through the same loc expression; and
    instance-derived index member names (`left_edgeindex3`) dropped to
    neutral `elocal` spellings — the last collapse blocker, found by
    diffing the two path-kernel clusters.  Cluster signature:
    `slog_rules_c<H>(db, s, Relation* const* f, const char* const* vl,
    const char* const* vt)`; the spine fills STATIC frames (tasks retain
    the pointers past `slog_plugin`'s return) and calls kernels in
    manifest order; byte-identical clusters collide on their
    content-hash name and DEDUP to one TU — the spine calling one
    function twice with two frames IS the sharing.  Park continuations
    and registrations thread `f`/`vloc`/`vtag`.  Kernel-groups now
    ALWAYS split (spine + kernel clusters, small strata included — the
    motivating programs are small); single-TU and name-baked emission
    survive only for model-less cprogs.  Cluster `keep-names` is `'()`
    (the v_-prefix hazard retires outside the spine).  PROVEN on
    n1_instances: left.path and right.path kernels (different strata)
    emit ONE cluster function, zero `getRelation` literals in any part
    TU, and the prelude/settings strata share cross-program at job-hash
    level as before.  Gate grew two checks: `cluster-name-freedom` and
    `cross-instance-cluster-collapse`.
    Validated: tu-det 9/9, unit 419, golden 167/167 DEFAULT opt and
    167/167 interp, tiered 9/9 (the hot swap works over multi-TU
    frame-mode plugins, lattice case included — after fixing the
    harness's own assumption that one stratum = one `.cpp`: its
    hand-compiled swap `.so` must link spine + parts), stats exact-once
    audit (the (loc,tag) key spelling survived the move to spine
    tables), plan-goldens WITHOUT re-record, abi2 10/10 + differential
    11/11, full session battery, plan-determinism 506 plans
    byte-identical.  TWO RECORDED COSTS: (i) cold golden-tier wall time
    ~17→~29 min — the always-split overhead on per-fixture cold
    compiles, the `.o` cache's worst case (warm edit loops are where
    per-kernel `.o`s pay it back; 2c may re-merge small kernels per-.so
    if this matters — judge there); (ii) kcfa's TU count 28→68.
    Flavored-native TUs keep name-bearing `static_assert` arms
    (differential-only, never shipped) — recorded, not fixed.
  - **(2c) The attach protocol.**  The `.so` exports the descriptor;
    `slog_plugin` splits into daemon-driven attach; declarations install
    through the SAME cohort declarations plan the interp path uses (one
    mechanism); the T3a upgrade seam keeps its soundness argument
    (replacement lands on the same `Stratum*`, no re-push accounting).
    Exit: the slice-2 exit above.
    *As-planned (2026-08-08, entry design).*  The descriptor carries NO
    name data: per kernel only {exec key, frame width, rule count,
    attach fn}, plus a constants-init fn and the accel-rel name list
    (compiler-computed, not in the plan; the `.so` is program-specific
    so names in the SPINE-side descriptor cost nothing).  Everything
    name-bearing is daemon-derived from the sibling `.plan`: frames from
    the binding schema, the tycheck-accept APPENDIX by the same
    first-use walk the emitter does (frame-width cross-check catches
    divergence), `vl` verbatim from DebugMap sources, `vt` from the
    STRUCTURED slot-relative variant + binding names ("delta:" + name —
    no display-string surgery).  vt/vl indexing moves bucket-local →
    kernel-ord so the daemon passes full-kernel tables to every
    sub-bucket.  Path-only protocol preserved: run_plugin dispatches on
    the descriptor symbol; a descriptor `.so` with no sibling `.plan`
    refuses loudly (the re-emit-on-miss doctrine).  beginStratum[Delta]
    chosen from the PLAN's flavor; upgrade = the same name-identity
    seam.  SCOPE: normal/delta flavors only — flavored (`_count`/
    `_maint*`) TUs keep the 2b `slog_plugin` spine (differential-only,
    never shipped; migrate at slice 3/4), and 2c's validation closes
    the 2b gap of never having RUN flavored-native by adding a
    SLOG_FLAVORED_NATIVE smoke.  New fixture n1_symmetric (two
    same-LEVEL instances ⇒ one stratum, two same-key kernels, ONE `.so`
    attached twice with distinct frames — the slice-2 exit case arising
    naturally).
    *As-built (2026-08-08).*  daemon.h `NativeKernelCode`/
    `NativeCodeDescriptor`; normal/delta spines export
    `slog_code_descriptor()` and NOTHING else — no `slog_plugin`, no
    relation creation, no frame building; the spine keeps only constant
    defs+init, cluster forward decls, per-kernel attach wrappers, the
    accel name table, and the descriptor.  run_plugin dispatches on the
    descriptor symbol; `attach_native_descriptor` (plan-count.cpp)
    derives the sibling `.plan` by first-dot stem, seals it, and
    `install_native_cohort` validates abi/kernel-count/exec-keys (the
    manifest keys now ride DecodedKernelPlan.exec_key)/rule-counts/
    frame-widths as seal refusals, installs the rule-free declarations
    carrier via the SAME `populate_normal_stratum` the interp path uses,
    builds frames (binding schema + the tycheck-accept first-use walk)
    and loc/tag tables (DebugMap sources verbatim with the "<unknown>"
    spelling; tags from the structured driver + kernel-local dynamic
    membership), calls the factories, reuses `add_read_manifest`, and
    pushes.  Attach storage (frames + string tables) is daemon-lifetime,
    like the dlopen handles.  beginStratum[Delta] from the PLAN flavor —
    the T3a name-identity upgrade seam is untouched, and the tiered swap
    harness drives descriptor `.so`s through it directly.
    SLOG_PLAN_ABI=1 is now an interp-only compatibility mode (a
    descriptor artifact refuses against an ABI-1 sibling at the key
    check, loudly).  PROVEN: n1_symmetric under SLOG_OPT=0 — one
    stratum's descriptor declares two kernels with ONE exec key and one
    cluster function attached twice with distinct frames; native
    answer.csv byte-identical to interp.  Gates grown: tu-determinism
    +2 checks (symmetric-shared-kernel-in-one-cohort,
    double-attach-byte-identical); abi2-differential +1 leg
    (counted-session-flavored-native — the first harness that EXECUTES
    the flavored native artifacts, closing 2b's untested gap).
- **(3) Attachment identity (item 2's second half).**  Per-attachment
  read/write VersionId maps and per-attachment RuleIds, so stats,
  provenance, watches and the count/walk audits stay per-instance while
  the code is shared.  Exit: `$stat_fires` and level-1 watches attribute
  to the right instance with one artifact attached twice; a recount over
  the shared kernel agrees with the sidecar per attachment.
  *Re-scoped at entry (2026-08-08), on a measured fact:* after (2c) the
  loc/tag tables are daemon-built per kernel from the plan's DebugMap,
  and locs are instance-qualified — n1_symmetric's fires table shows
  distinct `a#0@…`/`b#1@…` keys with symmetric counts, so the stats half
  of the exit HOLDS BY CONSTRUCTION.  Slice 3 therefore carries:
  **(3a) the batched accept re-key** — tycheck accept struct names move
  out of hashed exec bytes into slot references (the RF1 gap recorded at
  2b entry, finding β): accepted structs join the kernel's rel-order at
  first use, exec carries `(struct (rel N))`, the DECODER boundary
  rewrites slots back to names in the synthesized ABI-1 view (seal,
  interp, whynot unchanged — the same adaptation pattern as variants),
  and the TU's accept-appendix machinery retires (accepts are ordinary
  slots; the native frame is the binding schema exactly).  The re-key is
  NARROW: only tycheck-bearing kernels move.  **(3b) attachment
  records** — per attached kernel, both executors: exec key + write
  (name, VersionId) pairs + read names on the Stratum, the runtime
  identity T6 binds to; exit tests pin the per-instance fires fact and
  per-instance recount agreement over a shared kernel.  **DEFERRED with
  reasoning:** the `(RuleId, VariantTag)` stat rekey (execution-tiers
  §2.1's T0/T2 deviation) — instance-qualified locs already attribute
  correctly, the audit's aggregation unit is unchanged, and the rekey's
  real owner is T0's durable-RuleKey arc; spending it here would churn
  stats goldens for no attribution gain.
  *As-built (2026-08-08).*  (3a): `canonicalize-crule`'s tycheck arm
  resolves accepted struct names through `rel!` — exec carries
  `(accept (struct (rel N)))`; accepted structs join the kernel's
  rel-order at first use (a NEW collection walk, audited against the
  slice-0.1 lesson list); the decoder handles BOTH spellings (`TypePlan`
  gains a slot field, `parse_kernel_plan` post-resolves slots to names
  once bindings exist), so seal, bind, whynot and stale plans are all
  untouched; the TU's accept-appendix machinery retired (the frame IS
  the binding schema; `install_native_cohort` dropped its appendix
  walk).  Gate: airtight grew `struct-library-shares-a-kernel-key`
  (generated ty_lib/ty_twice fixture; self-validating — it requires
  slot-relative accepts to be present, so it refutes pre-3a emitters by
  construction).  (3b): `Stratum::KernelAttachment` {exec_key, write
  (name, VersionId) pairs, read names} recorded per attached kernel in
  BOTH install paths, captured under the same armed bind environment
  the stratum-wide maps use at push; cleared by `clearForUpgrade` (the
  replacement re-records); consumed by the NEW `(attachments)` protocol
  verb (additive; modeled on `breaks`).  Live proof: n1_symmetric's
  stratum shows two records sharing one exec key with distinct write
  maps (`a.path`@17 / `b.path`@14) and per-instance reads.  Gate grew
  three checks: `per-instance-fire-attribution` (the measured fact,
  pinned), `attachment-records-disaggregate` (drive.rkt replays the
  native pipeline and asserts a shared key with distinct writes), and
  `per-attachment-recount-agreement` (two forced recounts reproduce
  identical countrows per attachment, and the symmetric fixture's
  a/b count multisets match modulo the name — a cross-attachment mixup
  breaks either immediately; NOTE count sidecars establish lazily, so
  the check anchors on the last two recount markers).
- **(4) Per-rule selective emission (item 4).**  With the unit at kernel
  granularity, emission can drop to per-rule: compile the hot rules of a
  kernel natively and leave the rest interpreted, coverage still
  native ∪ interp.  Exit: a kernel running mixed native/interp rules
  produces results byte-identical to either pure tier.
  *As-built (2026-08-08).*  The MECHANISM ships; policy stays T3b's.
  `SLOG_NATIVE_COVERAGE` (all|even|odd|none, over kernel rule-def ords)
  is the deterministic test knob, cache-keyed in progstr beside the
  semijoin/wcoj toggles (a partial artifact must never stand in for a
  full one); flavored TUs pin `all` (a partial differential executor
  would compare nothing).  Descriptor interface bumps to 3
  (`interface_abi` — renamed from plan_abi with honest semantics; a
  stale interface-2 artifact refuses unambiguously): `NativeKernelCode`
  gains `{ncovered, covered}` — nullptr covered means all-or-nothing by
  ncovered, an ordinal list means partial, zero coverage means a null
  attach and the kernel runs fully interpreted.  The daemon validates
  coverage structurally (subset, strict, attach/coverage agreement) and
  attaches the interpreted complement from the SAME sealed plan through
  ord-filtered `attach_normal_rules` — coverage is native ∪ interp
  exactly, by construction.  Emitters skip clusters for uncovered rules
  (kernel-ord vt/vl indexing from (2c) makes partial tables Just Work).
  PROVEN: n1_symmetric under =even shows 2-rule kernels with ordinal 0
  native and ordinal 1 interpreted, golden-identical; =none runs whole
  programs through descriptor artifacts with zero clusters.  Gate grew
  `mixed-tier-{even,odd,none}` (the golden runner under each mode IS
  the equivalence check); the chain adds one FULL golden pass under
  =even.  Residual debt recorded: flavored artifacts still export the
  (2b) `slog_plugin` spine — exercised by the differential's
  flavored-native leg, migrating whenever a real consumer needs
  flavored descriptors.

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

## 7. Review questions — answered 2026-08-06

1. **Sequencing across streams.**  Slice 1 IS RF1's 4-way split (pin 2).
   Does that work land as RF1 slices 1–2 in the reflection stream and T4
   consume it, or does T4 absorb it?  The measurement says T4 cannot
   proceed without it, so the choice is about ownership and commit
   boundaries, not about whether.
   *Answered by events:* RF1 owned it and completed 2026-08-06 (all six
   exit gates, 142dd45).  T4 consumes; slice (1)'s residue is (1a).
2. **How far to take the descriptor.**  Minimum is slots + orderings +
   rule ids.  Maximum is RF1's full CohortManifest with the sharded-SCC
   coordinator.  Proposal: the minimum that lets slice 2's refusal be
   structural, deferring the coordinator to slice 1's manifest work.
   *Half-answered by events:* RF1 built the CohortManifest.  The native
   `CodeDescriptor`'s extent remains a SLICE 2 entry question.
   *Ratified 2026-08-07:* the minimum — one descriptor per `.so` with
   per-kernel sub-tables mirroring the cohort manifest shape (slot
   kinds/arities/orderings, per-slot factories, variant fingerprints);
   the sharded-SCC coordinator waits for a real sharded case (today's
   cluster split is clang-parallelism bucketing, not SCC sharding).
3. **Where relation creation lives after slice 2.**  Proposal: entirely
   daemon-side (the N3 boundary machinery already creates declared
   storage; the artifact stops calling `addRelation` at all).  This makes
   an artifact pure code, but it moves index requisition into the
   install path — worth confirming before the emission change.
   *Still open — gates slice 2, not entry.*  Note (1a) strengthens the
   proposal: the cohort declarations plan already owns cohort-wide
   creation + requisition on the interpreted path.
   *Ratified 2026-08-07:* entirely daemon-side, by REUSING the cohort
   declarations plan the interp path installs (`.plan`/`.so` already
   pair by stem) — one declaration mechanism, not two; the artifact
   becomes pure code.  The compiler-internal-relations hole closes
   naturally (the declarations plan carries temps).
4. **Does the recount of pin 4 need a migration story** for long-lived
   databases, or is "counts are a recomputable cache, re-establish them"
   sufficient at this stage?  (M0's doctrine says the latter; the question
   is whether any saved database in `data/` is expensive enough to matter.)
   *Answered by events:* the RF1 flip (003af8b) WAS this event; the
   doctrine held with no migration.  (1a)'s re-key repeats the same shape.
5. **Ratified 2026-08-06 (entry decisions, Tom):** (a) decl payloads =
   FIX NOW, kernel-local requisitions (slice 1a), not accept-as-identity;
   (b) sequencing = entry slice now, then REASSESS before committing to
   slice 2's emit-cpp lift (vs RF2 mount / T3b first).  Payoff honesty
   from §4 stands: today's compile-time win is near-theoretical; the
   entry slice is bought for the exit property and T6, at the cheapest
   re-key moment.
