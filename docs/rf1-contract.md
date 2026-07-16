# RF1 ProgramModel + Plan ABI 2 contract

**Status:** design contract (2026-07-15); not yet implemented.
This file consolidates the RF1 decisions ratified 2026-07-15 at the
**minimal-for-T2** scope; it does not reopen them.
[execution-tiers.md](execution-tiers.md) §2/§4/§11 and
[execution-tiers-impl.md](execution-tiers-impl.md) (D3–D6, D9, findings)
remain normative for the identity model and the interpreter contract;
[slog-reflection.md](slog-reflection.md) §15/§17/§18 for the reflection
staging; [roadmap.md](roadmap.md) §1/§3 (W1) for scheduling. The
convention follows `m4s-contract.md` and `m5-contract.md`: everything
not explicitly changed here keeps its current shape, and the T1 pass
(`compiler/canonical-plan.rkt`, shipped `50bb329`) is the substrate
this arc extends, not replaces.

RF1 exists because T2's plan installer is the first production consumer
of the `.plan` sidecar, and whatever shape it consumes ossifies
(slog-reflection §18.1 — the migration-free window closes the day T2
ships). It rides W1 as one IR-hygiene arc with N0
([n0-seam-map.md](n0-seam-map.md)); N0's gate is byte-identical C++
*and unchanged plan keys*, so the two arcs land in either order and the
single plan re-key is attributed to RF1 alone.

## What RF1 pins

1. Four-way split of the T1 `.plan` monolith (ABI 1 grammar:
   `ir-stack.rkt:444–483`) into **KernelExecPlan / DebugMap / binding
   schema / cohort manifest** — ABI 2.
2. **Per-kernel (per-SCC) plans**, with a compatibility adapter
   preserving today's merged-per-stratum consumption. The adapter
   retires at T4, not in RF1.
3. **RuleId per D4** (crules sorted by canonical serialization —
   edit-stable) and **VariantTag ordinals per D3** retained; RuleIds
   are *referenced* by KernelExecPlan and *defined*, with lineage, in
   DebugMap.
4. **ProgramModel at minimal-for-T2 scope**: SCC condensation +
   source-rule lineage preserved through simplification/lowering — just
   enough to emit DebugMap lineage, the cohort manifest, and persistent
   RuleKey construction (T0 consumes those). slog-reflection §15 RF1
   bullet 5 (model queries replacing downstream SCC reconstruction) is
   staged OUT to RF1.5 behind the adapter and is not in this exit gate.
5. **Program-tuple struct-ification** (n0-seam-map Seam 2) rides this
   arc as the coordinated IR-hygiene half.
6. **Flavored-plan attribute vocabulary reserved now** — including
   probe-only `mkstruct` as an attribute, resolving m4s-contract.md
   open question 1.
7. **This is THE one scheduled plan re-key** (roadmap §7).
8. **Determinism doctrine** updated with the 2026-07-15 TU-instability
   finding: plan-layer identity is the only run-stable identity; plan
   goldens become the golden format of record.
9. emit-cpp semantics are untouched in this arc: generated C++ is
   byte-identical before/after (the T1 gate, re-run).

## The four schemas

Today one sidecar per (stratum, flavor) — written at
`compile.rkt:587–589` — mixes executor content, lineage, and cohort
facts. ABI 2 separates them by reader. All four parts inherit T1's
canonicalization doctrine (every unordered container sorted,
`canonical-plan.rkt:27–31`), and the RF0 round-trip findings
(slog-reflection §15) shape the grammar: `join3` stays the one
genuinely nested op (finding 1); variable-length integer lists get one
canonical sequence encoding (finding 2); field existence is fixed per
opcode, closing the `seeded-only` index-marker straggler that
`ir-stack.rkt`'s `index?` accepts but the grammar comment omits
(finding 3); the open sexp vocabularies — lattice merge specs, `cjoin`
collection specs, oracle/seqindex attachment decls — are closed
(finding 4); dual-shape `let` becomes an explicit union (finding 5).

### KernelExecPlan

Everything the executor binds, and nothing else:

- ops (`pre`/driver/body/head), `nregs`, driver kinds
  (once/seeded/scan/probe);
- VariantTag with D3 ordinals; kernel-local RuleId references;
- relation slot table — structural only: slot, arity, kind, orderings,
  index requisitions (`plain`/`delta`/`seeded-only`, all three);
- constant slot table with materialized values (D14's constant
  register bank loads from here);
- prim table (sorted names now; opcodes when the daemon dispatch table
  exists, per T1's deferral);
- dynamic-rel set, as slots;
- plan attributes (flavor plus the reserved vocabulary below).

Readers: the T2 installer/sealer (`daemon/plan.h`), D9's per-attempt
fire vectors (dense RuleVariant ordinals index them), emit-cpp at T4
phase B, and the KernelPlanKey hash — the key covers exactly this part.

May NOT appear: daemon-resolvable names, source locations, display
strings, module paths, RuleKey lineage, cohort/stratification facts.
The exec plan is name-free so that a rename or N1 qualification
rewrites the binding schema without touching it, and so T4's
alpha-normalized KernelPlanKey gate goes live over this key without
another re-key. Consequence: VariantTag's relation component is stored
slot-relative; the familiar `delta:edge#1` spelling is a *display*
form derived through the binding schema (stats goldens keep it).

### DebugMap

Per kernel, keyed by kernel-local RuleId:

- RuleKey lineage — the persistent Layer/Event/Slot-substrate key
  inputs T0 assembles (roadmap P2);
- module-relative source locations (impl finding 6: repo/temp-absolute
  paths broke cross-run diffs once already; never embed them);
- display names and rule text;
- the crule→source-rule mapping (which variants lower from which
  source rule), from ProgramModel lineage.

ABI 1's `(meta (rule-meta (rid n) (source loc)) ...)` block is the
embryo of this part and migrates into it.

Readers: T0 rule-meta registration and catalog verbs, the W2 stats
rekey (locations for `$stat_fires` display), tycheck/error rendering,
REPL `explain`, watch UIs. Loaded **lazily**; NEVER read on the
execution hot path (slog-reflection §17's resist list).

May NOT appear: anything load-bearing for execution. No DebugMap field
may feed KernelPlanKey, seal validation, or executor binding — a
kernel must install and run with its DebugMap absent.

### Binding schema

The slot → (name, arity, kind) table the daemon resolves at bind time:
relation slots to daemon relation names, struct slots to struct
type-ids, service-relation references into the cohort prelude. This is
the seam where N1/N3 later substitute qualified names and TypeKeys
without touching KernelExecPlan — the entire point of its existence as
a separate part.

Readers: the daemon binder at install/attach (BindingFrame
construction, execution-tiers §2.3/§3), the compat adapter, the N2/N3
catalog planner.

May NOT appear: ops, registers, physical `Relation*`/VersionIds
(attachment-time state — writer attribution is per AttachmentId,
execution-tiers §2.2), display metadata beyond the resolvable name.
The binding schema is outside the KernelPlanKey hash.

### Cohort manifest

Per (stratum, flavor) install unit:

- kernel membership: the KernelPlanKeys forming the cohort, with
  SccInstance identity per kernel (semantic SCC id distinct from the
  pipeline ordinal, execution-tiers §2.2) and the (kernel, local
  RuleId) → evaluation-RuleId mapping;
- runtime services as a **fixed prelude** — the side-channel error
  structs (`error`, `malformed_deduction`, `div_by_zero`, ...) declared
  once per cohort rather than re-declared in every kernel's slot table
  (impl finding 3: the validator treats them as a prelude, not a
  per-program surprise); kernels that reference them do so through
  binding-schema service references;
- stratification/scheduling info: level order, recursive/static
  classification, dependency facts the installer needs.

Readers: the T2 installer (which kernels form the stratum it installs),
T0 catalog verbs, the compat adapter, T3 tier designations, T4
coordinator manifests, RF2's image packaging.

May NOT appear: per-kernel exec content (ops, registers, slot tables)
or source lineage — it points at kernels and DebugMaps, it does not
contain them.

## ProgramModel: scope and non-goals

The compiler today computes the SCC condensation and immediately
discards it: `stratify-rules` returns bare `(stratum level rules)`
(`stratify.rkt:230–235`), and downstream passes recompute SCC structure
when they need it (e.g. `compile.rkt:379–392` re-runs `tarjan-scc-ids`
for the recursive/linear classification). Source-rule identity is
likewise dissolved by simplification (`|` splits, wildcards, demand and
sequence expansion mint rules with no recorded origin).

Minimal-for-T2 scope — the ProgramModel preserves, as a first-class
compiler value threaded beside the existing pipeline:

1. the SCC condensation: scc-of, condensation edges, levels;
2. source-rule origin/lineage per derived rule, surviving
   simplification and lowering to the crule level.

That is *exactly enough* to emit the DebugMap's crule→source-rule
mapping, the cohort manifest's kernel membership, and the inputs for
persistent RuleKey construction (T0). Nothing else.

**Non-goals, explicitly staged out to RF1.5** (behind the adapter, not
in this contract's exit gate): replacing downstream SCC reconstruction
with model queries (slog-reflection §15 RF1 bullet 5) — the
compression sampler, recursion classifiers, and every other consumer
keep their current computations untouched.

**Program-tuple struct-ification** rides this arc (Seam 2): the
positional `(program ...)` tuples in `modules.rkt` — whose arity drifts
2→4→5 through the pipeline (`modules.rkt:88–95, 738, 793, 840`;
predicate `ir-stack.rkt:64–66`) — become a named struct with accessors.
Pure representation change; the byte-identical C++ gate covers it.

## Identity and the one re-key

### VariantTag, spelled out

A source rule lowers to several crules — its semi-naive versions (a
two-dynamic-clause rule yields a `delta:`-driven version per clause,
with full/old view assignments on the others). A **VariantTag
identifies one such version within its plan.** Today it is a string
built from the *driver*: `once`, `all:<relname>`, or `delta:<relname>`,
plus the `#0..#n` ordinal T1 added because same-source-rule versions
can share a driver (D3 — the recursive triangle lowers to three crules
all tagged `delta:edge`). The tag serves three roles:

1. **plan identity** — `(variant "delta:edge#1")` in every rule-def,
   hashed into KernelPlanKey (`canonical-plan.rkt:146–155`);
2. **fire stats** — `bumpFires` keys `(rule_loc, base tag)` — no
   ordinal, deliberately aggregated (`database.h:4139–4143`) — and the
   stats goldens pin the rendered spellings
   (`tests/stats-expected/*.fires`; note the harness already
   normalizes temp names to the literal `temp<N>`);
3. **the interpreter's disaggregated conformance identity** —
   RuleVariantId = (RuleId, tag + ordinal)
   (interp-core-contract.md, conformance obligation 2).

**The decision:** in the *stored* KernelExecPlan, the tag's relation
component becomes the driver's **slot** (exact spelling — structured
`(delta (rel 0) 1)` vs `"delta:0#1"` — is open question 3), because
the exec plan is name-free. The familiar `delta:edge#1` remains the
**display** identity everywhere a human or a golden sees a tag,
derived by joining the slot through the binding schema. Invariants the
change must preserve:

- display spellings byte-identical to today's for every existing
  golden — the derivation is a pure function of (view, driver name,
  ordinal);
- ordinals unchanged (D3 numbering in canonical order);
- one derivation site: once W2's stats rekey lands, the daemon
  rule-meta table renders display tags for both executors; until then
  native keeps its baked strings and cross-executor comparison happens
  only at the aggregated-golden level — exactly today's comparison.

**Why (what breaks otherwise):** a rename — or N1 qualifying `edge` to
`m.edge` — would change every VariantTag string naming that relation,
hence every KernelPlanKey in its strata: a pure rename would re-key
plans and recompile kernels in which nothing structural changed, and
T4's alpha-normalized key gate could never hold. Slot-relative tags
are what make "rename = a binding-schema edit" true. The temp-name
defect (determinism doctrine below) is the same failure observed from
the other side: a name with per-run spelling reaching tags made plan
identity wobble per run.

### RuleId and the re-key

RuleId assignment keeps D4 (crules sorted by canonical serialization —
edit-stable, the property plan goldens and durable ids actually need,
impl finding 9) and D3's VariantTag ordinals. The kernel split cannot
perturb either: a source rule's variants all share their heads' SCC
(rules join the stratum of their heads, `stratify.rkt:222–228`), so no
D3 ordinal group ever spans kernels.

Because kernels are content-addressed individually, RuleIds inside a
KernelExecPlan are **kernel-local** (dense, D4 order within the
kernel); the cohort manifest owns the evaluation-wide mapping. A
kernel's bytes — and hence its KernelPlanKey — never depend on sibling
kernels.

**This is THE one scheduled plan re-key** (roadmap §7: "W1 re-keys
plans once"). `kernel-plan-key` changes exactly once, from ABI 1's
monolith hash to the hash of the canonical KernelExecPlan part; the
`abi` field bumps 1→2. Migration is free: T1's rule already states
that stale caches predate `.plan` — consumers re-emit on miss
(`compile.rkt:585–586`), and sidecars regenerate from cached `.cprog`s
without rebuilding any `.so` (the `.so` job hash keys on
pre-simplification inputs, `compile.rkt:128–147`, untouched here).
Counts compose per the standing doctrine: a KernelPlanKey change
invalidates count sidecars (execution-tiers §2.2), which are
recomputable caches — sessions spanning the re-key recount, never
remap.

**Per-kernel is the production shape — no reaggregation (ratified
2026-07-15).** The runtime stratum remains the *install unit* (one
`.so`/install per stratum flavor), but a stratum is represented as
what it is: the cohort manifest's ordered list of kernel plans. Every
consumer — the T2 installer, tests, the W2 stats rekey — walks that
list; nothing ever fuses per-kernel plans back into a merged
stratum-level plan, and no code exists whose only purpose is
conforming to the pre-split view. A runtime stratum groups SCC
instances without fusing their KernelPlanKeys (execution-tiers §2.2).
Correctness of the partition is proven directly (slice 2 tests):
every crule of the stratum lands in exactly one kernel; the union of
kernel rule sets equals the stratum's rule set; per-kernel slot
resolution binds each relation to the same daemon object the merged
view would have; and the byte-identical-C++ gate plus the full suite
prove behavior unchanged. What remains "adapter" is only the
manifest-driven grouping in the installer, which is permanent — T4
later attaches kernels individually through the same manifest.

## Flavored-plan attributes (the M4S resolution)

ABI 2 defines a closed plan-attribute vocabulary **now**; the flavored
planners emit the attributes when M4N/M7 land. Attributes live in
KernelExecPlan and are hashed (they change executor behavior):

- **`no-semijoin-reopt`** on counted/maintenance plans. Semijoin
  filters are already disabled at planning for these flavors
  (`compile.rkt:671, 689`); the attribute makes that an explicit plan
  property the interpreter must respect rather than a convention it
  infers from flavor (execution-tiers §4.3 — the counted-admissibility
  requirement).
- **Fold kinds**: the prov-keyed count kinds
  (`join-planning.rkt:150–155`; count-round architecture §8B) ride as
  per-rule attributes, so the counted interpreter drives the shared
  `cnt_*` folds with the same kind discrimination today's `/<kind>`
  tag suffix carries.
- **Probe-only `mkstruct`**: an ATTRIBUTE on the existing `mkstruct`
  op, **not a distinct c-op**. This resolves the compiler-shape half of
  `m4s-contract.md` "open implementation questions" item 1: negative-
  phase maintenance plans mark `mkstruct` probe-only; the probe
  semantics (live master, then tombstones, fold error on double miss)
  are owned by m4s-contract.md — the plan schema owns only the marker.
  When M4S's flavored planners start emitting struct-headed `_maint*`
  plans, m4s-contract.md should point here for the shape.

## Determinism doctrine

New finding, measured 2026-07-15: **legacy TU text is RUN-UNSTABLE.**
Crule emission order varies across compiler runs of the *same tree*
(gensym'd symbols perturb hash iteration order), and locals/temps are
gensym'd (`__tXXXX`/`tempXXXX`, plus the derived `slog_rules_<hash>`
cluster names). Measured: ~12k-line normalized diffs on
`tests/deep_fact.slog`'s TU across two consecutive runs. The canonical
`.plan` for the same TU is **byte-identical** across runs.

The evening wholesale measurement (full golden suite vs the
`build-post2/` corpus, then run-vs-run) sharpened the boundary: **temp
relation names are the one contaminant that reaches the plan layer.**
Classification of 498 fresh plans: 273 byte-identical to the corpus;
73 differ *only* via temp gensyms — 26 as spellings (decl list,
`dynamic` list, `"delta:tempXXXX"` VariantTags), 47 additionally as
**D4 sort-order perturbation** (the canonical sort runs over serialized
text that contains the temp spelling; token multisets match, order
does not); 152 appear under **moved job-hash filenames** — verified
byte-identical content under a different stem (`eb30565e` ≡ corpus
`453edaee`), so gensym'd names also reach some `progstr` job-hash
input, churning `.so`-cache filenames run to run (5/758 stems moved in
one morning run, 219/758 in an evening run of the same tree).
Temp-free strata (e.g. `deep_fact`'s) are fully stable at every layer.

Consequences, pinned:

- **Deterministic temp naming is an RF1 prerequisite — slice 0, not
  T4 phase B.** Plan-layer identity is RF1's entire product; today it
  holds only for temp-free strata. Temp relation names move to a
  canonical scheme (per-stratum counter in canonical rule order — the
  shipped `latchk_<n>` precedent; no gensym reaches a relation name),
  which kills all four symptoms at the root: plan-byte spellings, D4
  sort order, KernelPlanKey stability, and the job-hash filename
  churn. Slice 0 includes the audit pinning exactly which `progstr`
  input carries the gensym'd names across strata. One-time churn:
  every temp-bearing TU/`.so` cache entry regenerates once — a
  recorded cost, not a risk. Stats goldens do NOT churn: the harness
  already normalizes temp names to `temp<N>` (see
  `tests/stats-expected/stat_dem.fires`), and once names are
  deterministic that normalization becomes retirable.
- **Plan-layer identity is then the run-stable identity.** RF1's four
  schemas inherit T1's canonicalization guarantees, verified by
  two-run AND two-process byte-equality tests over **all four parts**,
  explicitly including temp-bearing and multi-stratum programs.
- **TU emission-ORDER canonicalization stays deferred to T4 phase B**
  (the slot rewrite). Until then the content-addressed `.o` cache's
  cross-session hit rate remains degraded for TUs whose *local
  variable* gensyms (`__tXXXX`) churn text — a smaller residue once
  temp names are canonical. Correctness is unaffected throughout: the
  `.so` cache misses spuriously, it never collides.
- **Plan goldens are viable now and become the golden format of
  record** — the first installment of slog-reflection §18.7's
  image-based goldens, in textual form.

## Slices

0. **Deterministic temp naming + job-hash input audit** (the
   determinism-doctrine prerequisite; independently landable, smallest
   possible arc). Canonical temp names per the `latchk_<n>` precedent;
   the audit pinning which `progstr` input carries gensym'd names;
   regeneration of affected caches and any temp-embedding stats
   goldens.
   *Tests:* two consecutive full-suite runs produce byte-identical
   `.plan` sets AND identical `build/` filename sets; the wholesale
   plan comparison harness (this doc's evening measurement) wired as a
   repeatable check.

   *As-built checkpoint (2026-07-15, slice 0 SHIPPED):*
   - **Mint site.** The one temp mint was `(gensymb 'temp)` at
     join-planning.rkt:389 (`gensymb` = utils.rkt:53: `temp` + 4
     pseudo-random chars + global counter). Temps now mint as
     `temp[<flavor>]<level>x<n>`: a per-stratum counter walked in
     canonical rule order — `rule-sort-key` (join-planning.rkt) sorts
     the stratum's typed rules by their provenance-stripped,
     variable-blind serialization (variables rename to first-occurrence
     ordinals; gensym'd variable spellings — wildcards `__*`, split
     `_t*`, tycheck reporting vars — churn both raw text and Racket
     set-iteration order, so neither can drive the walk; ties are
     alpha-equivalent and plan-invariant). `<level>` = stratum level
     threaded through `plan-all` (temps of different strata coexist BY
     NAME in one daemon database: emit-cpp.rkt:449 reuses an existing
     relation of the same name, fatal on arity mismatch). The flavor
     tag ∈ {`""`,`c`,`m`,`n`,`r`,`d`} keeps count/maintenance/delta
     replans' temps disjoint from the normal flavor's (flavored temps
     can differ in arity — a counted temp is wide) exactly as gensym's
     always-fresh names did. All-alphanumeric on purpose:
     tests/stats-tests.sh normalizes `temp[A-Za-z0-9]+`, so the fires
     goldens pass unchanged (that normalization is now retirable).
   - **The job-hash audit refuted the leak hypothesis.** progstr
     (compile.rkt info0–info4 + fingerprints + toggles) is computed
     PRE-planning; an env-gated component dump (`SLOG_DUMP_PROGSTR=
     <dir>`, kept as the audit instrument) over two symmetric clean
     full-suite runs showed all 163 program progstrs and all 2941
     build/ filenames byte-identical BEFORE the fix. Temp names never
     reach the job hash. The historically observed "moved stems" were
     asymmetric compile SETS, not renames: config/default-config.slog
     and its `action-<hash>` plugins compile only when config/cache is
     cold (config.rkt do-load-config!), so two runs can differ in which
     stems exist at all. The one true pre-cache-key gensym was the
     anonymous-inline-union name (modules.rkt:408), empirically proven
     to churn progstr on a scratch program (`union2OMR1` vs
     `union9HW91` in info1/info2); it now derives from the flattened
     member list (`_union_<m1>_<m2>…`, the lattice-anon-name
     precedent). No suite program uses the feature (inline anonymous
     unions currently fail typecheck end-to-end — separate, pre-existing
     issue).
   - **Second plan-layer instability found and fixed.** 7/500 suite
     plans churned with NO temps involved: the D4 sort key (canonical
     text) was not total — alpha-equivalent crules from different
     source rules tie, and the stable sort preserved upstream
     set-iteration order, flipping the (rid, position) pairing run to
     run. canonical-plan.rkt now breaks ties by location, then variant
     tag.
   - **Third instability, exposed BY the name fix: temp COLUMN order.**
     `carried` was sorted `symbol<?` over variable names
     (join-planning.rkt), so gensym'd variable spellings flipped the
     temp's column order — and with it the follow-up's scan/emit
     register pairing — run to run (measured: 35/500 plans still
     churned once names were deterministic; pre-fix this was masked
     inside the temp-name diffs). Columns now order by first
     occurrence in the rule's clause list, which is run-stable (it
     drives scheduling, whose plans were already byte-stable). One
     planner unit expectation updated to the occurrence order.
   - **Measured.** Pre-fix: 118/500 plans churned across two clean
     full-suite runs (111 via temp gensyms, 7 via D4 ties); build/
     filename sets and progstrs were already stable. Post-fix: 0/500 —
     tests/plan-determinism.sh (two full golden tiers from clean
     build/, asserting identical filename sets + byte-identical .plan
     sets) is the repeatable check; manual/slice gate, deliberately not
     wired into run-all.sh (~10 min per run). The filename assertion
     excludes `action-*` plugins: those are runtime-DEMAND-compiled
     client artifacts, and the `(continue)` action compiles lazily the
     first time any fixpoint hits a wall-clock pause budget
     (runslog.rkt:266) — a slow run mints it, a fast run never does.
     cprog/TU text remains run-varying via local `__t*` variable
     gensyms — T4 phase B's residue, unchanged and out of scope.
   - **Checkout-path caveat discovered en route:** `$sup`/`_lam` names
     embed `fnv(ABSOLUTE file path) mod 100000` (demand.rkt:369,716),
     so stats fires goldens (`$sup4873…` = /home/tom/slog) and
     dem_lambda's golden only match from the primary checkout — a
     worktree run fails both for path reasons, not nondeterminism.
     Run-to-run determinism on one tree is unaffected, but slice 4's
     plan goldens of record will inherit the path-dependence through
     `delta:$sup…` VariantTags unless $sup naming goes checkout-
     relative first.
1. **ProgramModel + program struct** (compiler-internal, zero
   behavior). The named program struct replacing the positional
   tuples; the ProgramModel record carrying condensation + lineage out
   of `stratify-rules` and through simplification/lowering.
   *Tests:* byte-identical generated C++ and `.cprog`s on
   representative programs (the stats exact-once audit is the cheap
   gate, as in T1); lineage unit battery — a `|`-split rule maps both
   derived rules to one source rule, a demand-minted rule records its
   origin, an unlocated (`#f`-loc) crule remains its own identity.
2. **The ABI 2 split, per-kernel plans, and the adapter** (the
   re-key). `canonical-plan.rkt` partitions a stratum's crules by head
   SCC using the ProgramModel, emits the four parts per kernel plus
   the cohort manifest, bumps `abi` to 2, moves the error-struct
   prelude into the manifest, and re-keys; consumers walk the
   manifest's kernel list (per-kernel-native, no reaggregation).
   *Tests:* extended `tests/unit/canonical-plan-tests.rkt` — the split
   is airtight (editing a DebugMap-only fact never changes any
   KernelPlanKey; moving a rule between files changes DebugMap only;
   renaming a relation changes the binding schema only);
   partition-correctness (every stratum crule in exactly one kernel;
   union of kernel rule sets ≡ stratum rule set; per-kernel slot
   resolution binds identically to the pre-split view); two-run +
   two-process byte equality over all four parts; the RF0 harness
   (`tests/reflect/rf0-roundtrip.rkt`) updated to ABI 2 so the
   relational round-trip gate is preserved.
3. **Attribute vocabulary + flavored emission for shipped flavors.**
   Schema validators for the closed attribute set; the `_count` and
   `_maint*` planners (which exist today) emit `no-semijoin-reopt` and
   fold kinds now; probe-only `mkstruct` is schema-reserved with no
   emitter until M4S.
   *Tests:* count/maintenance-flavor plan goldens showing the
   attributes; validator rejection of unknown attributes; normal-flavor
   plans carry none.
4. **Plan goldens of record.** Golden `.plan` sets for a
   deep_fact-class giant ground-rule program, a lattice program, a
   demand program, and a join3/wcoj program; wired as a suite tier
   beside the existing goldens.
   *Tests:* the goldens themselves, plus a golden-stability run
   (recompile twice, diff) pinning the determinism doctrine.

Slices 3 and 4 are independent of each other and may land in either
order after slice 2.

## Exit gates

1. **Byte-identical generated C++** vs pre-RF1 across the suite —
   emit-cpp semantics untouched in this arc (the exact-once
   instantiation audit and goldens are the mechanism, as for T1).
2. **Full suite green.**
3. **Plan goldens** for the four representative program classes
   (deep_fact-class ground rules, lattice, demand, join3/wcoj) landed
   and green.
4. **Two-run + two-process determinism** — byte equality over all four
   schema parts, including temp-bearing and multi-stratum programs,
   plus run-stable `build/` filenames (slice 0's product).
5. **Canonical-plan unit battery extended** with the split/adapter
   cases of slice 2.
6. **Partition correctness proven directly** (the slice-2 battery):
   exhaustive crule coverage, identical slot binding, and behavior
   unchanged under the byte-identical-C++ gate — per-kernel-native,
   with no reaggregated compatibility view anywhere in the tree.

Not gated here, by design: RF1.5 model queries, any daemon consumer
(T2 owns installation), the stats rekey (W2), TU-text canonicalization
(T4 phase B).

## Open implementation questions (pinned, not blocking)

1. **Sidecar layout:** four files per kernel versus one
   `build/<hash>.plan` carrying the four labeled parts. Interacts with
   atomic writes (`call-with-atomic-output`) and re-emit-on-miss;
   whichever is chosen, the KernelPlanKey hashes the KernelExecPlan
   part alone.
2. **Constant slot order:** D5 sorts by content-derived global name;
   ABI 2 may sort by serialized value and demote the name to DebugMap.
   Downgraded to a spelling choice: const global names are themselves
   content-derived (`const<sha24>` of the value,
   `operationalization.rkt:294–298`), so both bases are rename-immune
   and deterministic — pick one before the re-key, since it defines
   the hashed bytes, but nothing hangs on which.
3. **Stored VariantTag spelling:** the slot-relative form
   (`delta:0#1` vs a structured `(delta (rel 0) 1)`), and exactly
   where the name-rendered display form is derived for the W2 stats
   rekey and existing fires goldens.
4. **Attachment decls** (oracle, seqindex): binding schema versus
   cohort-manifest services, and the closed grammar for their
   vocabularies (RF0 finding 4).
5. **The canonical sequence-value encoding** for integer lists (RF0
   finding 2) — load-bearing for RF2's fact encoding; the ABI 2
   textual grammar should keep list-valued fields in one shape so the
   future encoder needs no per-field special cases.
