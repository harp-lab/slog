# First-class rules, tiered execution, and interpreted queries

2026-07-14. **Design proposal; not implemented.** Revised the same day after a
review against the shipped substrate (pausing/tiered-swap machinery, the
incremental/count architecture, and the in-flight WCOJ3 operators). This
document consolidates the execution-tier, parameterized-code, REPL debugging,
query, and iteration-replay designs that were previously spread across:

- [pausing.md](pausing.md), for the existing sliceable read phase, clean
  iteration-boundary suspension, and the query-while-paused seams;
- [fast-compile.md](fast-compile.md), for the existing O0/O2 artifacts and
  boundary hot swap;
- [modules.md](modules.md), for module instances, namespace binding, and
  alpha-normalized code reuse; and
- [repl.md](repl.md), for watches, provisional `runN` boundaries, and stable
  relation/type/value handles.

Section 14 lists exactly what this document supersedes or reverses in those
documents. **[execution-tiers-impl.md](execution-tiers-impl.md)** is the
companion implementation guide: crystallized decisions (D1–D14), two working
prototypes with measured results (interpreter read-side overhead 1.2–1.3×
native; canonical-plan pass deterministic over real cprogs), liftable code,
and the file-by-file change map. The central proposal is:

> The front end emits a canonical lowered plan and first-class rule identities
> before any native compilation. The daemon executes that plan with a prebuilt
> interpreter by default, and native compilation is a targeted optimization
> applied only where structural or measured evidence says it pays — primarily
> recursive SCCs. The same interpreter supplies provenance, stepping, why-not
> explanations, and the REPL's ad-hoc read-only queries.

The intended lifecycle is therefore:

```text
canonical KernelPlan -> interpret now
                          |-- hot enough?  -> O0 when ready -> O2 when ready
                          |-- observed?    -> instrumented debug mode
                          +-- QueryPlan    -> read-only interpreted query
```

Native code contains no provenance or breakpoint instrumentation. Debugging is
an execution policy on first-class SCC/rule instances, not another source
program and not facts inserted into the database. Queries are read-only plans
executed against quiescent master indices, not compiled action plugins.

## 1. Decisions and design constraints

The design commits to the following.

1. **Planning remains in the Racket front end.** Module resolution,
   typechecking, stratification, join planning, exact semi-naive
   operationalization, and canonical slot allocation do not move into the
   daemon. This applies to ad-hoc queries too: the REPL/front end plans a
   query against the boundary catalog and sends the daemon an executable
   QueryPlan.
2. **The daemon receives executable plans.** The interpreted form is a small
   S-expression transliteration of canonical `crule`s: dense value registers,
   relation/type/constant slots, selected index orderings, drivers, joins,
   guards, and heads. Source provenance is registered separately and referred
   to by rule identity.
3. **Rules, executable variants, SCC instances, code bundles, runtime strata,
   and relation versions have distinct identities.** Names and pipeline
   positions remain metadata, never a substitute for identity.
4. **The interpreter is the default executor; native code is an optimization.**
   Every rule variant is executable from its plan alone. Compilation is
   selective (section 5): recursive SCCs default to the full tier ladder;
   most other work is interpreted or capped at O0. Nothing in the system may
   assume a native artifact exists.
5. **VariantTag is an open set.** Today's lowered variants already include the
   flavor families `normal`, `seeded/replay`, `_delta`, `_maint1`,
   `_maint3neg`, `_maint4neg`, `_count`; M4N will add negated-body-driven
   variants with pre/post state. The tag taxonomy and every ABI that carries
   it must admit new tags without renumbering old ones.
6. **Count and signed-maintenance variants are excluded from mid-flight tier
   changes.** They are never tier-swapped inside a read, never read-restarted,
   and initially not level-1 watchable (sections 7 and 8). Their entry paths
   are protected by explicit entry modes in the protocol, not by stratum-name
   accident (section 9.1).
7. **Native artifacts are parameterized at attachment time.** A canonical
   ordered binding frame resolves relation slots to exact `Relation*` objects,
   type slots to type descriptors/SIDs, and oracle slots to bindings. Tasks
   cache direct relation/index/function pointers; no binding lookup occurs in
   the fixpoint hot path.
8. **Compilation and scheduling units are separate.** A runtime stratum may
   hold several independent module-SCC kernel instances without merging their
   code cache identities.
9. **Large SCCs split deterministically.** All physical shards share one
   semantic plan hash and the same complete binding ABI. Rule shards register
   read executors only; the SCC coordinator registers declarations,
   write/intern tasks, and metadata once.
10. **O0/O2 native read rules remain clean.** Installing a provenance watch,
    breakpoint, step request, or why-not request enables interpreted execution
    for the affected SCC instance. Removing the last such observer permits an
    automatic return to the best native tier. Cheap *observation* watches
    (section 7.1) do not force interpretation.
11. **Bound operations are cursor-shaped.** The generic unit the interpreter
    binds is an arity-erased sorted prefix cursor constructed once at bind
    time — not merely a probe function — so that scans, probes, semijoin
    filters, and the WCOJ3 leapfrog arms are all instances of one abstraction
    (section 4.1).
12. **Interpreter time slices are short.** An interpreted continue call
    targets at most roughly 500 ms and checks its deadline within join
    enumeration — including inside `join3` intersection loops — not merely
    between rules. Native continues retain the coarser 5–10 second interactive
    work unit, with their existing exact outer-driver slicing.
13. **The first cross-tier mid-read takeover restarts the read attempt.** The
    read phase is made explicitly transactional: discard its uncommitted
    batches and accounting, reset rule cursors, and rerun the same immutable
    input delta under the new executor. Portable cursor handoff is a recorded
    idea, not a milestone (section 8.3).
14. **A watched iteration pauses before commit** (level-1 watches only). When
    a completed interpreted read has candidate watch hits, keep the old
    driving delta and the new send batches alive, preview the watched keys
    against the immutable master indices, and pause before `finalizeAll`. The
    client can commit those outputs or discard them and replay the identical
    read with different instrumentation. This applies to monotone
    set-semantics evaluation only (section 7.3).
15. **Read-only queries never mutate the database.** No relation, index,
    sidecar, count, or interner (string, collection, struct) changes as a
    result of a query. Literals are resolved by probe-only interning; a miss
    means an empty result, never an allocation (section 6.2).
16. **Execution-tier events are not semantic events.** Tier swaps, debug
    pauses, watch replays, and queries never enter the session recipe and
    never affect the logical fixpoint. The recipe records programs, imports,
    renames, drops, links, and input overrides only (incremental.md §0.2);
    executors and artifacts are caches.

## 2. The identity model

The daemon needs a rule abstraction as deliberate as its existing relation
abstraction. Several superficially similar identifiers must not be collapsed.

### 2.1 Source rule and executable variant identities

```text
RuleKey        durable semantic source-rule occurrence
RuleId         evaluation-local compact id supplied by the front end
VariantTag     one lowered executable variant of that source rule (open set)
RuleVariantId  (RuleId, VariantTag)
NativeSlot     local ordinal exported by one native code artifact
```

A source rule can lower to several `crule`s: different delta drivers,
fire-once/seeded forms, and incremental/count/maintenance forms. Watches and
ordinary statistics often aggregate by `RuleId`; exact execution, replacement,
and debugging address `RuleVariantId`.

The driver alone does not name a variant (prototyped fact — impl doc §1.2/D3):
a recursive rule's exact-semi-naive versions all share one driver-derived tag
(`delta:edge` three times, differing only in full/old/new view assignment), so
`VariantTag` carries a canonical version ordinal (`delta:edge#0..#2`, flavor
kind suffixed). RuleVariantId uniqueness is a seal-time validation error, not
an assumption.

`RuleKey` should derive from stable program/module occurrence identity and the
lexical rule occurrence, not source text alone. The front end assigns compact
`RuleId`s for one evaluation and registers metadata separately:

```text
(rule-meta r17
  (key ...opaque persistent RuleKey...)
  (module-instance m4)
  (source "scc.slog" 83 4)
  (text "rule ..."))
```

The interpreted definition contains no repeated source provenance:

```text
(rule-def r17
  (variant delta-edge
    (pre ...)
    (driver (scan rel0 reg0 reg1))
    (body ...)
    (head ...)))
```

**Reconciliation with pausing.md §6.** pausing.md deliberately chose rule id =
31-bit hash of source text (plus an occurrence counter) so that ids never
perturb the `.so` cache key, with SCC ids daemon-assigned at push. This design
retires both. The cache-stability rationale is preserved *by construction*
rather than by hashing: native artifacts export anonymous `NativeSlot`s, and
the attachment-time `load` command maps slots to `RuleId`s (section 3), so
compact ids never appear inside any compiled artifact. The manifest sidecar
that carried text-hash ids (`compile.rkt` `rule-id-of`) is retired with it.
Two deferred pausing.md items are picked up here rather than dropped:
`malformed_deduction` gains the emitting `RuleId` through the `tycheck` head
op's plan identity, and `$stat_fires` keying moves from
`(source-location-string, variant-string)` to `(RuleId, VariantTag)` with the
location available via `rule-meta`.

### 2.2 Kernel, SCC, and stratum identities

```text
KernelPlanKey      hash of canonical lowered module-SCC plan
KernelInstanceKey  one attachment of that plan to a binding frame
SccInstanceKey     semantic SCC occurrence in the expanded/bound program
RuntimeStratumId   execution/scheduling container, possibly several SCCs
CodeId             one loaded native bundle/shard
AttachmentId       one CodeId attached to one Kernel/SCC instance
```

The daemon's current SCC id is effectively a pipeline ordinal. The new model
retains an ordinal for display and scheduling but gives the semantic SCC a
separate stable identity.

A runtime stratum may group independent same-level SCC instances to retain the
current reload/fixpoint efficiency. It does not fuse their `KernelPlanKey`s or
their rule identities. Conversely, a real cycle introduced by namespace
binding or cross-module rules changes the global SCC context and therefore the
canonical plan/dynamic-slot classification.

Three constraints from the incremental architecture attach here:

- **KernelPlanKey change invalidates counts.** Derivation counts are defined
  over canonical-IR rule instantiations and are explicitly not portable across
  compiler/operational-IR changes (incremental.md §8B.3). A new
  `KernelPlanKey` for a kernel therefore invalidates any count sidecars whose
  contributions were established under the old plan; they are recomputable
  caches and must be re-established, never remapped.
- **Writer attribution is an identity distinct from the plan key.** Counts and
  the walk/recount machinery key on `VersionId` plus the recorded writer
  StratumInstances at the *original* bind environment (incremental.md §0.4,
  §4.2). One `KernelPlanKey` is reused across many attachments, so writer-set
  audits can never be satisfied by the plan key; each `AttachmentId` must
  record its exact read/write `(name, VersionId)` maps, exactly as strata
  capture `read_versions`/`write_versions` today.
- **PauseToken and UpdateEpochId unify.** M1's optimistic expected-revision
  admission and this document's generation-checked pause tokens are the same
  mechanism: a client presents the generation it believes is current, and a
  stale generation is refused before any mutation. Build one, use it for both.

### 2.3 Relation identity in rules

Interpreted and native plans refer to relation slots, never daemon strings:

```text
rel0 : graph.edge   table(2), requires indices (0 1), (1 0), delta (0 1)
rel1 : graph.scc    table(2), requires index (0 1)
rel2 : graph.Node   struct(3), type slot type0
```

An attachment supplies exact evaluation-local relation versions:

```text
BindingFrame.relations[0] = Relation* for VersionId 81
BindingFrame.relations[1] = Relation* for VersionId 94
BindingFrame.relations[2] = Relation* for VersionId 72
```

The friendly qualified names and persistent VersionKeys stay in the catalog
and diagnostics. The task stores direct `Relation*`, `Index**`, primitive
function, and type-descriptor pointers after binding.

## 3. The daemon rule abstraction

One possible runtime shape is:

```text
RuleInstance
  RuleId / RuleKey / source metadata
  owning SccInstance
  interpreted RuleVariant plans
  native factories by (variant, tier, CodeId, NativeSlot)
  tier designation: interp-only | o0-max | tiered      (section 5)
  per-variant counters and diagnostics
  current read-attempt progress

SccInstance
  SccInstanceKey / KernelInstanceKey / KernelPlanKey
  BindingFrame (+ recorded read/write VersionId maps)
  ordered RuleInstances
  dynamic output RelationIds
  permanent write/intern/internal tasks (constructed from the plan)
  active execution policy: auto | interpreted
  available native tiers/shards
  level-1 watches, breakpoints, and why-not requests

RuntimeStratum
  ordered SccInstances
  entry mode: fresh | resident-delta | resident-count   (section 9.1)
  RunState and iteration number
  immutable current input delta during read
  active ReadAttempt
```

The `auto` SCC policy chooses the best currently available native variant per
rule/shard, falling back to interpreted variants. `interpreted` forces every
rule variant in that SCC through the interpreter so provenance and granular
control are complete. Different independent SCCs grouped in one runtime
stratum may use different policies.

Native `.so` code exports a descriptor and rule factory table rather than a
single entry point that constructs and immediately runs an anonymous stratum:

```text
CodeDescriptor
  PlanABI version
  KernelPlanKey
  binding ABI descriptor
  shard id/count
  NativeSlot -> variant-shape fingerprint
  factory[NativeSlot]
```

Loading maps every local slot to an already registered `RuleVariantId`:

```text
(load "build/K.O0.so"
  (tier o0)
  (into scc5)
  (relations v81 v94 v72 ...)
  (rules (0 r17 delta-edge)
         (1 r17 delta-vertex)
         (2 r23 once)))
```

The daemon validates the native descriptor against the interpreted plan:
semantic plan hash, variant shape, relation/type slot ABI, index requirements,
head relations, once/every/seeded classification, and — for counted or
maintenance variants — the relation-kind capability of every bound relation
(incremental.md §8B.4), so an executor can never be attached over a relation
kind excluded from that flavor. A path is only a load location; `CodeId` and
`AttachmentId` are the runtime identities because the same path can be
instantiated several times.

Because compilation is selective, a native artifact need not cover every rule
in its kernel. The descriptor's manifest declares which slots are intentionally
absent; seal-time coverage validation checks that native slots plus
interp-designated rules exactly cover the kernel's rule set.

## 4. Canonical plan and interpreter

The current `cprog` is nearly the desired plan language. Add a canonical pass
after operationalization:

- variables -> dense `u16` registers;
- relation/type/constant/primitive names -> dense slots/opcodes;
- rule provenance -> `RuleId`/`VariantTag` references;
- declaration and index requirements -> canonical sorted descriptors; and
- every unordered Racket set/hash -> a deterministic sequence.

The known nondeterminism this pass must fix is small and enumerable:

1. crule order originates as `(set->list planned-rules)` in
   `operationalization.rkt` (the planner returns a `for/set`); canonical order
   becomes `RuleId` order.
2. `cprog-dynamic-rels` is a set and `cprog-constants` is a hash
   (`ir-stack.rkt`); both serialize as sorted sequences.
3. One residual `gensymb` survives lowering (the `latchk` temporary for
   ground-value lattice negation); it must be interned deterministically.
4. Constant globals are already content-derived (de-gensym'd for the per-`.o`
   cache) — a head start, not new work.
5. Index descriptors are already largely sorted at construction; the
   requirement sets they derive from are hashes and need normalization at the
   boundary.

The first wire representation can remain simple S-expressions. The daemon is
parsing a versioned execution plan, not Slog source, and performs no planning.
If parsing or transfer later matters, the same PlanABI can gain a compact
binary encoding without changing semantics.

### 4.1 Bound operations are cursors

Plan installation resolves each generic operation once. The existing `Index`
cold interface has no generic prefix probe; all probing today is templated
free functions downcast to `BTreeIndex<A>`/`BTreeMapIndex<KA>` from
arity-aware generated code — including the new WCOJ3 machinery
(`Join3PrefixCursor`, `join3` in `daemon/operators.h`). The interpreter's
binding layer therefore constructs, once per bound operation, an arity-erased
**prefix cursor**: positioned by a bound register prefix, exposing the
remaining columns as a sorted stream with `next`, `seek(key)`, and
`advance_past(key)`.

This one abstraction covers the whole operator family:

- a **scan** is a cursor with an empty prefix over the delta (or full) index;
- a **probe** (`join`, `join-old`, `join-new`, `join-lat`) is a cursor over a
  full/old/new view enumerated to exhaustion;
- a **semijoin filter** (`exists`, `absent`, `absent-lat`) asks the cursor
  only for non-emptiness; and
- a **`join3` arm** is exactly a `Join3PrefixCursor`: two cursors co-iterate
  by leapfrog `seek`, and the interpreter's deadline poll sits inside the
  intersection loop.

Adapter tables are built at bind time by downcasting there, so the interpreter
calls stored functions rather than switching on arity or searching names per
tuple. Native code keeps calling the templated functions directly; the cursor
layer is the interpreter's erasure of the same functions, not a second
implementation.

The full conformance vocabulary the interpreter must cover (from
`ir-stack.rkt`, including the in-flight WCOJ3 additions):

```text
drivers   scan | probe | once | seeded          (+ scan-full, queries only)
body ops  join | join-old | join-new | join3 | exists | absent | absent-lat
          join-lat | let | letp | cjoin | eq | neq | cmp
head ops  let | letp | cjoin | mkstruct | emit | emit-temp | emit-lat
          tycheck                                (+ yield, queries only)
```

`letp` (row-abandoning partial primitives) and `cjoin` (spec-aware pointwise
lattice join) are easy to forget and must be first-class from the start.

Primitive opcodes bind to `PrimFn`s. The primitive audit is largely already
favorable: generated code dispatches through the shared `prims.h`/
`seq_prims.h` functions today, so primitive, type-test, struct-intern,
lattice-merge, and oracle semantics are naturally shared. The genuinely
duplicated semantics live in the emitters' inline join loops — exactly what
the cursor layer replaces. The native emitter should be understood as a
partial evaluator of `KernelPlan`, not a second definition of the language.

### 4.2 Interpreter task state

An interpreted rule task owns:

- a register vector;
- program counter;
- explicit nested join/iterator stack (cursor stack);
- outer driver cursor;
- bound operation table;
- task-local output batches; and
- optional `DebugSink*`.

It uses the same bucket/task scheduler as native rules. It checks the short
deadline while advancing every potentially long scan/join level, allowing a
precise continuation inside a nested join. With `DebugSink == nullptr`, it
allocates no proof trees and serves as the default execution tier. With a
sink, the same state supplies stepping, match/failure observations, and
provenance.

### 4.3 Counted execution in the interpreter

The canonical unit of counting is a rule instantiation in the operational IR,
bijective through physical planning (incremental.md §8B.3). For the
interpreter to be admissible as a counted/maintenance executor — which is what
makes flavored variants interp-only by default (section 5.3) — it must:

- enumerate the exact same instantiation multiset as native code, taking no
  existence shortcut in counted join enumeration (semijoin filters are already
  disabled in counted plans; the interpreter must respect the same plan
  attribute rather than re-optimizing); and
- drive the identical shared sidecar fold (`cnt_apply`/`cnt_try_apply` in
  `daemon/counts.h`) and transition tasks, not a re-implementation.

The corresponding gate is instantiation-multiset equality, not merely content
equality (section 12).

## 5. Selective compilation: what never compiles

Today every stratum compiles, every flavor of every stratum compiles to its
own `.so` (`_delta`, `_count`, `_maint1`, `_maint3neg`, `_maint4neg`), and
every generated TU re-instantiates the per-arity task/index template ladder.
Measured suite time is dominated by clang. The interpreter dissolves most of
this: compilation stops being the price of admission and becomes a targeted
optimization.

### 5.1 Tasks that need no codegen at all

Write, intern, struct-intern, lattice, map-write, count, maintenance, and
seq-index tasks are *already* generic templates in `daemon/operators.h`;
generated code contributes nothing to them but per-arity instantiation and
registration boilerplate. Under this design the daemon pre-instantiates the
arity ladder once (in `slogd` itself) and exposes factory tables; plan
installation constructs and registers these tasks directly from the canonical
declarations. Consequences:

- write/intern machinery requires zero per-program compilation, ever;
- generated TUs shrink to read-rule bodies only, since the template ladder
  and registration boilerplate leave the per-program artifact — so the strata
  that *do* compile also compile faster; and
- the reload-ordering and index-requisition invariants move from generated
  code into one plan-installation path, where they are checked once.

### 5.2 Do we need compilation for a copy rule?

No. A copy/rename/projection/filter rule is one driver cursor, zero or few
guards, and an emit. Its read-side cost is dominated by index iteration and
batch append — shared library code under either executor; interpretation adds
a bounded per-tuple dispatch overhead on the read side only, while the row's
downstream intern cost is identical. And in an acyclic stratum the rule body
runs a bounded number of times over its input, so the total overhead is one
constant factor on one pass — against a fixed multi-second clang bill.

(Exact one-to-one copy rules overlap with the incremental substrate's rename/
link environment ops, which execute zero code. Where the front end can prove a
copy rule is a pure rename it may become a catalog op instead; that is an
independent optimization, noted here only so the two mechanisms are not
conflated.)

### 5.3 Rule execution classes

Every `RuleVariantId` carries a tier designation:

```text
interp-only   never compiled; the interpreter is its permanent executor
o0-max        compiled to O0 when warranted; never queued for O2
tiered        full ladder: interpret -> O0 -> O2, as today
```

Default classification at planning time:

- **interp-only**: ground-fact/`once` rules; copy, rename, projection, and
  filter shapes (no dynamic joins); seeded/replay variants; *all* flavored
  variants (`_delta`, `_count`, `_maint*`) — count rounds run once over full
  indices and maintenance runs on user edits, so they are cold by definition;
  and every rule in a small acyclic stratum.
- **o0-max**: join-bearing rules in acyclic strata over large inputs; anything
  measurably warm that a single pass cannot dominate.
- **tiered**: rules in recursive SCCs, which amortize compile cost over many
  iterations. These still begin interpreted (the cold-start property) with O0
  queued immediately at priority 1.

The classification is a *default*, refined by two feedback paths:

- **Promotion.** Interpreted slice accounting gives exact per-SCC/per-rule
  cost. If an interpreted SCC exceeds a budget (a small multiple of its
  estimated O0 compile cost) without reaching fixpoint, its compile jobs jump
  the queue; the artifact attaches at the next boundary (or via read restart
  once T6 exists). A pathological acyclic join therefore self-rescues.
- **Demotion via the tier-profile sidecar.** A small per-kernel profile keyed
  by `KernelPlanKey` (iterations to fixpoint, interpreted ms, native ms,
  whether O0 ever arrived before fixpoint) is written beside the build cache.
  Later sessions consult it: kernels that historically fixpoint before O0
  could attach skip compilation entirely; known-hot kernels compile eagerly.
  The profile is a cache — deleting it only costs rediscovery.

Flavored variants gain a matching escalation: a session showing sustained
maintenance load on one kernel may promote its maintenance variants to
`o0-max`. The exclusions in section 1.6 are about *mid-flight* changes;
attaching a native maintenance executor between epochs at a clean boundary is
permitted.

Environment surface: `SLOG_OPT` gains `interp` (force interp-only everywhere —
the differential-testing and no-toolchain mode) alongside `tiered`/`0`/`2`;
the default `tiered` now means "selective per this section." Per-rule source
annotations are possible later but are not part of the first implementation.

### 5.4 Consequences worth stating as goals

- **Fewer, smaller artifacts.** Only compile-worthy rules are emitted, so TUs
  shrink, the content-addressed `.o` cache holds fewer clusters, and O2
  budget concentrates on the top rules by measured fires.
- **Zero-clang warm runs.** With profile sidecars populated and caches warm, a
  typical test-suite or small-program run should invoke clang approximately
  never. Track this as a measured metric, not a slogan.
- **No-toolchain deployment.** A daemon without clang installed remains fully
  functional at interpreted speed. This makes `slog` runnable in environments
  where shipping a C++ toolchain is unacceptable.
- **The interpreter is the fallback executor for unknown kinds**, converting
  incremental.md §8B.4's "unknown kinds route to fallback recompute" into
  "route to the interpreter."

### 5.5 Tier scheduling and CPU allocation

The compile pool, the interpreter workers, the native OpenMP team, detached O2
batches, and external oracle backends all contend for the same cores; today
each subsystem sizes itself as if alone. Introduce one daemon-owned core
budget from which all of these draw. The initial policy remains simple:

```text
interpreter workers = ceil(P / 2)
compiler pool       = max(floor(P / 2) - 1, 1)
```

with roughly one core left for the front end, daemon coordination, and TCP
handling; `P <= 2` uses one interpreter worker and one nice'd compiler
process. This is a starting policy, not a design commitment — the arbiter is
the design commitment. It must also subsume fast-compile.md §5's existing
`min(nproc, jobs)` subprocess pool and `nice`-d O2 jobs rather than adding a
second uncoordinated pool.

Compilation jobs have a strict priority order:

1. O0 shards for the currently executing SCC (including promotions);
2. O0 shards for future SCCs, in topological/pipeline order; and
3. every O2 job last, still subject to single-flight cache claims and low OS
   priority.

The compiler streams each sealed SCC plan to the daemon as soon as lowering
finishes rather than waiting for every SCC's C++ emission. An SCC that reaches
fixpoint before O0 arrives simply proceeds; the profile sidecar records that
outcome and future sessions skip the build.

## 6. Ad-hoc read-only queries

The REPL needs two different verbs, and only one of them extends the database:

- **adding programs/modules/rules** — from files or ad hoc at the command
  line — is a semantic recipe event (incremental.md §0.2) admitted through
  the ordinary pipeline. Selective compilation makes this fast: a small
  ad-hoc module or single rule is interp-only, so "add a rule, see results
  now" costs no clang.
- **read-only queries** are not recipe events, not database extensions, and
  must leave the database bit-identical. These were previously imagined as
  JIT-compiled point-query action plugins (pausing.md §8(a)) with query values
  baked into plugin source; the interpreter is the strictly better path: no
  clang in the loop, an argument channel by construction, and one execution
  semantics shared with rules.

### 6.1 QueryPlan

A query is a read-only `KernelPlan` produced by the same front end:
the REPL resolves names against the selected boundary catalog (repl.md §1),
typechecks, and plans a non-recursive body over **existing indices only**,
using relation size statistics for join ordering. Differences from a rule
plan:

- **drivers**: `scan-full` — iterate a master (full) index bucket-by-bucket,
  without any delta or reload. This is exactly the scan-full-index driver
  mode pausing.md §8(b) reserved.
- **head**: `yield` — stream result rows to the client in bounded pages
  rather than emitting into any relation. `count` and `exists` short forms
  avoid materializing rows at all.
- **no index requisition.** Building an index is a mutation and a memory
  commitment; the planner uses what exists and falls back to scan-plus-filter
  (the interpreter can always do this), reporting the degradation through
  `explain`. An explicit `(materialize-index @v ord)` mutating command may be
  added later; it is not a query.
- **no fixpoint.** v1 queries are conjunctive bodies with guards, computes,
  and (optionally) negation-as-absence with snapshot semantics. A recursive
  query is a module addition, full stop. Materialized recursive views can be
  revisited once ordinary queries are proven.

Query results render through the ordinary value printer and `#N` handles
(repl.md §5), so large rows are browsable without a second inspection
facility.

### 6.2 Read-only discipline

Decision 15 is enforced mechanically, not by convention:

- **Probe-only interning.** Query literals (strings, collections, struct
  patterns) resolve through probe variants of the interners: a string absent
  from the string heap makes the equality unsatisfiable and the query returns
  no rows — it is never allocated. This requires probe-only entry points
  beside `encodeString`/collection `put`, which are also independently useful
  for level-0 watches.
- **Compute restrictions.** v1 rejects query computes that would mint new
  interned values (string construction, collection construction). A later
  version may route such values through a query-local scratch interner whose
  ids never escape (results are decoded before hitting the wire), but that is
  explicitly deferred.
- **No emission paths.** `yield` is the only sink; `emit*`, `mkstruct`-into-
  relation, and lattice heads are rejected in query plans by the front end
  and by seal-time validation in the daemon.

### 6.3 Admission and consistency

Queries execute in a `QueryContext` — the second `RunState`-like context
pausing.md §8(b) anticipated — budgeted, sliceable, and cancellable like
everything else. v1 runs one query at a time.

Master indices are immutable during the read phase, so a query may run in any
**quiescent-master** state: daemon idle, `RUN_AT_BOUNDARY`, a mid-read
suspension, or a `RUN_READ_COMPLETE` pre-commit pause. It may not run during
write/intern phases. This composes directly with debugging: "remain paused and
inspect" at a watch pause *means* running queries against the paused snapshot.
At a pre-commit pause, queries see committed master state only; candidate
uncommitted rows are the business of the watch-settle preview (section 7.2),
not of general queries.

Negation in a query evaluates against the same snapshot ("as of this pause"),
which is exactly what a debugger user expects but should be labeled in
`explain` output when the queried strata have not closed.

### 6.4 Protocol surface

```text
(query q7 (plan ...) (page 500))
(query-next q7 (page 500))
(query-cancel q7)
(explain r17)              ; canonical plan for a rule variant
(explain q7)               ; chosen driver, orderings, join order, join3 use
(catalog ...)              ; boundary catalog/type-registry introspection
```

`(lookup rel v...)` survives as sugar for a one-row query. The catalog verbs
are repl.md §7's introspection surface; the daemon returns structured records
keyed by VersionKey/TypeKey, never mangled strings.

## 7. Debug policy and watches

Watches split into two tiers with different costs and different guarantees.
Both address relations by exact VersionKey/VersionId resolved by the client
(repl.md §6); the daemon never follows latest names.

### 7.1 Level 0: observation watches (native-safe, ships early)

Exactly repl.md §6's design, adopted unchanged: relation size and
per-iteration added/removed counts, exact-tuple appearance/disappearance, and
iteration/stratum/boundary events, all evaluated at coherent barriers where
the finalized delta already exists — under **any** executor, including O2.
Hits aggregate into one structured pause; "notification" versus "breakpoint"
is client policy. No proofs, no replay, no interpreter required. Level-0
watches ship as soon as the command protocol exists and make the REPL useful
years of milestones before provenance does.

### 7.2 Level 1: provenance watches settle at a pre-commit gate

Installing the first provenance watch, breakpoint, step request, or why-not
target enables `interpreted` policy for every SCC that can write the target
relation; removing the last such observer returns those SCCs to `auto`.

The interpreter observes rule attempts during read and retains lightweight
candidate proof records keyed by emitted head content. It does not declare a
database watch hit merely because a rule attempted an emit.

The present read barrier immediately calls `finalizeAll` when every read task
finishes (`ReadCompletion`); note precisely what that does: it frees the old
driving delta and unions per-thread send shards into the new delta — master
indices change only in the subsequent intern phase. Pausing after intern would
be too late for cheap replay; pausing before `finalizeAll` costs nothing.

Add a `RUN_READ_COMPLETE` pre-commit state. If a completed read has candidate
watch hits, the barrier skips `finalizeAll`, just as a mid-read suspension
does, even though no read work remains. At that point:

- the old delta and its immutable indices still drive an exact replay;
- all new candidate rows are complete in per-thread send shards;
- no master relation or sidecar has changed; and
- the interpreter's candidate derivations are complete.

A read-only `WatchSettle` operation then previews only watched keys against
the immutable master state. For ordinary tables, an emitted tuple absent from
the master guarantees that one duplicate copy will survive. Struct heads
compare content rather than their not-yet-assigned id. Lattice heads reduce
all contributions for each watched key with the same join operation used by
`LatticeInternTask`, reporting the final value only if it ascends the master.

Intern behavior should be factored as a shared transition:

```text
settle(master value, candidate contributions) -> accepted value / no change
apply(accepted transition)                    -> mutate master/sidecar
```

Normal intern performs both; `WatchSettle` performs only `settle` for active
watched keys. This prevents the debugger and normal interner from silently
developing different table/lattice semantics.

The watch gate correlates accepted watched changes with candidate derivations,
aggregates every hit, and returns one structured **pre-commit** pause. The
client may:

- commit, running the ordinary finalize/write/intern continuation exactly
  once;
- replay, deleting send batches/debug records and rerunning the same read from
  its origin, normally with deeper stepping or explanation budgets; or
- remain paused at the start-of-read snapshot for inspection — including
  running ad-hoc queries against it (section 6.3).

Thus a watch means "would genuinely appear if this attempt commits," while
retaining the cheap replay property that would be lost after index mutation.

### 7.3 Scope decision: monotone evaluation only, and shared refactors

The pre-commit gate's premises — master and sidecars unchanged during read,
replay of the same delta is exact — are **false** for signed maintenance:
M3/M4T fold non-idempotent sidecar support counts and remove over-deleted rows
from live indices mid-phase, and the whole update-epoch model is deliberately
mid-epoch-inconsistent. This is a decision, not an open question:

- Level-1 watches and read replay ship restricted to **monotone
  set-semantics flavors** (normal, seeded, `_delta` forward evaluation).
- Counted and signed-maintenance epochs are **non-watchable at level 1 and
  non-replayable** until a genuine sidecar preview/apply exists. That work is
  its own later milestone, not a rider on T5.
- The **struct** settle/apply split is the same refactor as M5's separation of
  intern identity from live membership; T5's struct case is sequenced after
  (or co-designed with) M5, never built independently.
- The **lattice** settle builds on M6L's shipped contributor-reduce (staged
  old rows never mutate the resident payload map); M7's regression repair
  later extends the apply side only.

### 7.4 Provenance representation

Do not allocate a tree for every partial join. The interpreter already holds
the current driver tuple, matched premise tuples, computed registers, and
guard outcomes on its explicit cursor stack. It materializes a proof only when
a head matches an active watch, using budgets such as:

- maximum derivations per watched tuple;
- maximum proof nodes/bytes per pause;
- maximum displayed collection/value expansion; and
- canonical first-N plus an omitted-derivation count.

### 7.5 Why-not

A ground why-not target selects only rules that can emit its relation, unifies
the requested head fields with those rules, and records each failure frontier:
missing driver/probe match, missing join match, failed comparison, partial
primitive failure, unexpected witness for a negated atom, or incompatible head
computation/type check.

The first scope is "why was this not emitted in this captured iteration?" A
whole-fixpoint why-not query over full indices needs recursive memoization and
cycle reporting and remains a later layer over the same interpreter.

## 8. Pausing, replay, and cross-tier takeover

Interpreter and native continuations have different representations. A native
task preserves only its outer driver cursor; the interpreter may pause inside
any nested join. Translating an arbitrary interpreter stack into generated C++
continuation objects is not a one-line change and is not attempted.

### 8.1 Transactional read restart (smaller than it looks)

The existing read phase has the decisive property: it reads immutable indices
and writes only fresh output. Formalize one invocation as a `ReadAttempt`:

```text
ReadAttempt
  generation id
  input delta identity
  executor generation per SCC/rule
  task cursors/continuations
  per-task/per-thread output batches
  provisional fire/stat counters
  provisional error/oracle side effects
```

If a tier/policy change arrives mid-read:

1. bring all workers to a read suspension — **this step is already shipped**
   (pausing.md's mid-read suspend with parked continuations, skipping
   `finalizeAll`);
2. abort the current `ReadAttempt` without `finalizeAll`;
3. delete its send batches and interpreted/native continuations;
4. discard its provisional counters/debug records/error emissions;
5. reset every rule/bucket task to the origin over the same immutable input
   delta;
6. activate the new executor selection; and
7. rerun the read phase.

The genuinely new work is steps 2–5: disposal and provisional accounting, plus
the side-effect audit below. No master rollback is needed because intern has
not begun. The interpreter's ~500 ms work unit bounds ordinary wasted work. If
native code arrives after read/intern completes, the ordinary shipped boundary
swap applies and nothing is discarded.

Restart applies to monotone flavors only (decision 6); counted and
signed-maintenance reads are never restarted.

The restart supports both directions:

- interpreter -> O0/O2 when compilation finishes or a promotion fires; and
- native -> interpreter when a user enables level-1 debugging mid-SCC.

At a `RUN_READ_COMPLETE` watch pause the same path is simpler still: no
parked/in-flight continuations exist, the old delta is intact; `commit`
continues through `finalizeAll`, `replay` clears the send shards and resets
cursors.

This separates two operations that should not both be called rollback:
**read-attempt abort/replay** is cheap because master indices are unchanged;
**post-intern iteration undo** would require index/sidecar undo logs and is
not part of this proposal. The daemon should never promise the second when the
first is sufficient.

### 8.2 The read-phase side-effect audit, by name

The audit demanded before restart can be called transactional is concrete:

- **Fire/stat counters.** `bumpFires` currently accumulates into the
  daemon-global `fire_counts` map during read and drains at fixpoint; a replay
  would double-count. Stats become per-`ReadAttempt` staging merged at commit
  — which also supplies watch-replay's "discard provisional counters" for
  free.
- **Oracle dispatch.** `OracleDispatchTask` runs in the read phase and
  mutates the registry's `answered` set while submitting to external
  backends. Restart safety currently rides on the answered-set suppressing
  re-submission; that idempotence must be verified and stated, or dispatch
  staged until read commit. Harvested answers land in send shards
  (discardable) but also materialize collections append-only.
- **Pending-error scratch.** Per-thread `pending_errors` prim state is
  transient and must be cleared on abort; emitted error facts are in send
  shards and are discarded with them.
- **String/collection interning.** Append-only and tolerated across
  abort/replay, exactly as the shipped suspend machinery already tolerates it
  (pausing.md §9.7). Struct ids are assigned at intern, never during read
  (the read-side emit writes an id placeholder), so no struct identity leaks
  from an aborted attempt.

### 8.3 Recorded idea: portable outer cursors

Both executors could eventually share daemon-owned per-rule/bucket run state
(`unstarted | running(outer cursor) | completed`), letting native tasks take
over an interpreter's unfinished outer positions without repeating output.
This is recorded for completeness; transactional restart is the correctness
fallback and there is no current plan to build handoff.

## 9. S-expression command protocol

Replace the raw `.so`-path protocol and scattered compiled action plugins with
a small, line-framed S-expression command language. A provisional SCC/stratum
builder is not runnable until sealed:

```text
(scc-begin scc5
  (key ...)
  (kernel-plan k9)
  (relations (rel0 v81) (rel1 v94) ...))

(rule-meta r17 ...)
(rule-def r17 ...canonical variants...)
(scc-add-rule scc5 r17)
(scc-seal scc5)

(stratum-begin st3 (entry fresh))
(stratum-add-scc st3 scc5)
(stratum-seal st3)

(load "build/K.O0.so" (tier o0) (into scc5) ...)

(watch-add (tuple v94 56 9) (level 0))
(watch-add (tuple v94 56 9) (level 1) (provenance #t))
(why-not-add (tuple v94 56 9))
(watch-remove w2)

(query q7 (plan ...) (page 500))
(explain r17)
(catalog ...)

(continue (until event-or-fixpoint) (ms 500))
(resume p42 (action commit))
(replay p42 (executor interpreted) (proof-budget 10000))
(debug-on scc5)
(debug-off scc5)
(close)
```

The protocol exposes the small object model rather than generic
`(disable "path")` operations: disabling a path is ambiguous when one DSO is
attached multiple times, and tier activation is an atomic policy change over
validated rule slots.

All mutating builder/load commands acknowledge success or return a structured
error. Connection loss before `*-seal` discards the provisional object. Pause,
continue, and epoch commands carry the unified generation token (section 2.2)
so a stale client cannot advance a newer run state.

### 9.1 Entry modes are explicit

Today the resident count/delta entry (`beginStratumDelta`: positional bind,
indices stay resident, no reload, no iteration-0 delta) is distinguished from
fresh entry (`beginStratum`: deferred reload before re-registration) only by
which function generated code happens to call — and is protected from the
hot-swap path only because flavored strata have distinct *names*. The generic
protocol removes that accidental firewall, so the distinction becomes an
explicit, validated attribute:

```text
(stratum-begin st3 (entry fresh))
(stratum-begin st9 (entry resident-delta))
(stratum-begin stC (entry resident-count (at <pipeline-pos>)))
```

Seal-time validation enforces the combinations: `resident-*` entries perform
no reload and require positional/version binding against the recorded
historical environment (incremental.md §4.2 — a historical stratum is always
recounted at its *original* environment); tier policy refuses swap/restart
against `resident-count` strata (decision 6); and the reload-before-
re-registration ordering invariant of fresh entry moves into one checked
installation path instead of being a property of generated code.

### 9.2 Migration

The path-only protocol and the command protocol run dual-stack during
transition: a line that parses as a bare path dispatches as today; a line
that parses as a command dispatches to the new layer. The compiled action
plugins (`(continue ...)`, `(continue-boundary)`, `(lookup ...)`, `(schema)`,
dump/save actions) are retired verb-by-verb as the protocol grows equivalents;
this is a replacement of shipped surface and each retirement needs its
driver-loop counterpart updated in the same change.

## 10. Native code layout and deterministic splitting

`KernelPlanKey` is computed after alpha-normalizing module-instance paths to
relation/type slots and after recording the binding alias partition and global
SCC dynamic/static classification. Two independent instantiations of the same
SCC library then have the same plan key and physical code. (This gate becomes
meaningful when modules.md's instantiation ships; the identity design must not
preclude it.)

The physical packing unit stays what it is today — one `.so` per runtime
stratum — now exporting per-SCC factory tables rather than a monolithic entry
point. The logical cache/identity unit is the module-SCC kernel; whether
kernels later get their own files is a loader-overhead question to revisit
with real module distributions, not a prerequisite.

For a large SCC, shards are bucketed by hash of the **canonical rule-variant
text** mod a power-of-two shard count — replacing today's bucketing by emitted
C++ text, which is stable across runs but not across emitter changes. This
re-buckets the content-addressed `.o` cache once at cutover; the finer
`.o`-level cache continues to absorb edit locality underneath. All shards
export the same plan/binding ABI and receive the full binding frame. A
coordinator descriptor registers declarations, index requirements, write/
intern tasks, and SCC metadata once; shards contribute disjoint native
read-rule slots. The daemon seals a native executor generation only when its
manifest proves complete coverage (native slots plus interp-designated rules).

## 11. Implementation sequence

Phases are ordered so that each ships something independently testable, and so
the sequence composes with the incremental queue (M5 -> M4S -> M4N -> M7).

### T1: canonical KernelPlan (first; standalone compiler work)

**Status 2026-07-14: SHIPPED** — `compiler/canonical-plan.rkt` (pass,
serializer, KernelPlanKey), `kernel-plan?` as ir-stack Level 7, the
`latchk` gensym replaced by a deterministic per-rule counter
(post-escape `latchk_<n>`, compiler-reserved single underscore), and a
`build/<hash>.plan` sidecar written beside every flavor's `.cprog` by
`emit-stratum-cpp`. Battery: `tests/unit/canonical-plan-tests.rkt` (12
cases: determinism, round-trip, D3 ordinals, dense registers, constant
slots, join3 rewrite, tag conventions, wcoj3-toggle key change); verified
non-vacuously deterministic across separate Racket processes on a
3-stratum lattice program exercising the latchk path.

1. Land after the WCOJ3 vocabulary settles, so the plan language is
   canonicalized once, `join3` included. *(done)*
2. Dense register and relation/type/constant/primitive slot allocation after
   `build-cprog`; deterministic crule order; the section-4 nondeterminism
   worklist. *(done — prims ride as a sorted name table; opcode numbers
   assign when the daemon's dispatch table exists, T2)*
3. Stable RuleId + VariantTag assignment before C++ emission. *(done, in the
   plan sidecar)* **Deliberate deviation:** `$stat_fires`/`bumpFires` keeps
   its aggregated `(loc, base-tag)` key. emit-cpp documents that same-driver
   variants of one rule share a key as the exact-once audit's unit, and the
   daemon cannot resolve RuleIds until rule-meta registration exists — so
   the stat rekey moves to T0/T2, and generated C++ stays byte-identical
   now. Disaggregated RuleVariantId identity lives in the plan.
4. Gate: emitted C++ is content-identical before/after canonicalization;
   the exact-once instantiation audit and goldens stay green. *(achieved:
   quick tier 7/7 including stats; 16/16 lattice goldens over the changed
   latchk path)*

Cached `.so`s built before this pass have no `.plan` sidecar; plan consumers
(T2+) must re-emit on a miss rather than assume presence. The single-TU
emission-order canonicalization (emit in RuleId order) is deferred to T4
phase B alongside the slot rewrite, so this slice changes zero generated
bytes.

### T0: identities and protocol substrate (parallel with T1)

1. Persistent RuleKey/SccInstanceKey construction; compact evaluation-local
   RuleId/RelationId/SccId allocation; semantic SCC identity separated from
   pipeline ordinal.
2. Line-framed S-expression parser/dispatcher, structured replies, dual-stack
   with the path protocol.
3. Provisional builders, seal-time validation, explicit entry modes (9.1).
4. Catalog/introspection verbs (repl.md §7) and **level-0 watches** — the
   protocol's first user-visible payoff, no interpreter required.

### T2: daemon interpreter

1. Arity-erased prefix-cursor adapters for set and lattice indices, including
   `Join3PrefixCursor` erasure; shared primitive dispatch and bound `PrimFn`s.
2. The full section-4.1 conformance vocabulary: scan/probe/once/seeded
   drivers, explicit cursor stacks, guards, `letp`/`cjoin`, type checks,
   negation probes, existing head sinks.
3. Task-factory construction of write/intern/lattice/count tasks from plan
   declarations (5.1) — the arity ladder moves into `slogd`.
4. Integration with buckets, short deadlines, suspension, and the existing
   write/intern pipeline.
5. Gates: per-iteration content-delta equality against O0/O2 **and**
   instantiation-multiset equality via the fires audit (section 12).

### T3: cold-start and selective tier scheduling

1. Install/seal plans before waiting for clang; interpret immediately.
2. Rule tier designations, default classification, the promotion budget, and
   the tier-profile sidecar (5.3).
3. Core-budget arbiter and compile priority queue (5.5).
4. Artifact selection (cached O2 -> cached O0 -> interpret) and the shipped
   boundary swap for arrivals. **No mid-read takeover yet** — with 500 ms
   interpreter slices, boundary-only swapping already bounds the wait.
5. `SLOG_OPT=interp`; the interp-only full-suite differential run becomes a CI
   fixture.

### Q1: query engine (after T2; independent of T4)

1. `scan-full` driver, `yield` sink, `QueryContext` with budgets and
   cancellation.
2. Probe-only interner entry points; front-end query planning over existing
   indices with size-based ordering; `explain`.
3. Quiescent-master admission (idle/boundary/mid-read-suspend/pre-commit) and
   pagination protocol.
4. `(lookup ...)` re-expressed as sugar; the JIT'd point-query action retired.

### T4: parameterized native bundles

1. Replace baked relation strings with canonical binding slots; export
   `CodeDescriptor` and per-native-slot task factories.
2. Attach one artifact repeatedly with distinct BindingFrames/RuleIds; record
   per-attachment read/write VersionId maps (2.2).
3. Separate module-SCC code units from runtime-stratum grouping; coordinator
   manifests for sharded SCCs; coverage = native ∪ interp-designated.
4. Per-rule (rather than per-kernel) selective emission becomes possible here;
   before T4, selective compilation operates at kernel granularity.

### T5: interpreted debugging (level 1; struct case gated on M5)

1. Per-SCC `auto`/`interpreted` policy and observer ownership.
2. `RUN_READ_COMPLETE`, candidate derivation capture, read-only `WatchSettle`
   for plain tables; lattice settle over M6L's contributor-reduce; struct
   settle co-designed with M5's intern-identity/membership split.
3. Bounded proof rendering and first-iteration why-not failure trees.
4. Monotone-only enforcement (7.3); counted/maintenance epochs report
   "not level-1 watchable" as a structured error.

### T6: transactional mid-read replacement (last)

1. `ReadAttempt` generations; per-attempt provisional stats; disposal of
   complete/partial send shards.
2. The named side-effect audit (8.2): staged or verified-idempotent oracle
   dispatch, cleared error scratch, tolerated append-only interning.
3. Abort/reset/restart under a different executor; stress interpreter->O0/O2
   and native->debug flips at pathological sub-second budgets.
4. Monotone flavors only; `resident-count`/maintenance strata refuse restart
   at validation.

Sequencing against the incremental queue: T0/T1/T2 run in parallel with
M5/M4S with no collisions, provided entry modes and writer attribution are in
the protocol from day one. T5's struct settle waits for M5. VariantTag stays
open ahead of M4N, and the M4N variants become interpreter conformance cases
when they exist. The counted-sidecar preview/apply (which would lift 7.3's
restriction) is scheduled after M7, if at all.

## 12. Correctness and performance gates

1. Interpreter, O0, O2, and every boundary-tier mix produce identical
   content-based deltas after every iteration, not merely the same final CSV.
2. **Instantiation-multiset equality:** per-rule fire counts match exactly
   across executors, verified with the existing always-on `$stat_fires`
   exact-once audit and goldens. This is the gate that admits the interpreter
   to counted execution; content equality alone is insufficient.
3. The full test suite passes under `SLOG_OPT=interp` with content-identical
   goldens — and this differential run is retained permanently as a fuzzing
   oracle for the compiler: any emitter bug that diverges from the
   interpreter's independent semantics is caught by comparison rather than by
   golden curation.
4. **Query hygiene:** after any query (including failed, cancelled, and
   paused-state queries), the database is bit-identical — master indices,
   sidecars, counts, stats, and all interner heaps. Verified by save/compare
   and interner size counters.
5. Parameterized double instantiation shares CodeId/KernelPlanKey but has
   distinct RuleInstance/SCC/Relation identities and unambiguous stats.
6. A large sharded SCC has exact rule-slot coverage (native plus
   interp-designated) with no duplicated write/intern task and no missing
   variant.
7. Aborting a read attempt leaves master indices, deltas, counts, oracle
   answers, error facts, stats, and output batches equivalent to a fresh read.
8. Repeated interpreter yields resume inside nested joins — including inside a
   `join3` intersection — without dropping or duplicating an instantiation.
9. Installing/removing a watch toggles only affected SCC instances; a level-0
   watch never changes executor policy; another instance of the same shared
   code may remain native under a level-1 watch elsewhere.
10. A watched tuple with several attempted derivations but one accepted insert
    produces one pre-commit watch hit with bounded multiple proof trees;
    replay leaves the old delta/master intact and commit applies the change
    once.
11. Why-not reports every producing rule/head occurrence and a precise bounded
    failure frontier without changing database contents.
12. **Selective-compilation sanity:** a pathological interpreted acyclic join
    triggers promotion and self-rescues; a tiny recursive kernel with a warm
    profile sidecar runs zero clang; warm-cache suite runs report their clang
    invocation count and it trends to zero.
13. Count rounds and maintenance epochs are unreachable by tier swaps,
    restarts, and level-1 watches, enforced at protocol validation — a test
    drives each refusal.
14. Core allocation does not oversubscribe interpreter workers, the native
    OpenMP team, compiler jobs, and oracle backends on ordinary `P >= 3`
    machines; priority tests show current-SCC O0 beating future O0 and all O2
    work.
15. Warm cached O2 behavior remains direct and pays no interpreter setup
    beyond plan/manifest validation already needed for identity.

## 13. Details still to pin down

1. **Exact persistent RuleKey construction.** Must compose with
   ModuleInstanceKey, duplicate source rules, stored recipes, and replay. (The
   cache-stability question is resolved by slot mapping; the durability
   question is not.)
2. **Interpreter performance envelope.** First measurements exist (impl doc
   §1.1): read-side factors of 1.30× (copy), 1.22× (1- and 2-level joins),
   1.31× (join+guard) against the exact fused native loop shape, with cursor
   erasure itself at parity — single-threaded microbenchmarks. Remaining
   work: re-verify on `bench/` harnesses under OpenMP and real `sendBatch`
   paths (`bench/regress.sh` gates the result) and set the §5.3 thresholds
   from those numbers.
3. **Probe-only interning and query computes.** The probe entry points beside
   `encodeString`/collection `put`; whether v2 queries get a scratch interner
   with wire-time decoding, and how struct-pattern literals probe the struct
   interner.
4. **Query negation semantics while paused.** Snapshot semantics are chosen;
   decide how `explain`/results label absence over strata the active run has
   not closed.
5. **Read-attempt side effects.** Specify oracle dispatch and pending-error
   transactional behavior (8.2) before mid-read restart ships; decide staged
   dispatch vs verified idempotence.
6. **Counted-sidecar preview/apply.** The milestone that would lift the 7.3
   monotone restriction: shared settle/apply over `cnt_*` transitions,
   sequenced after M7 if pursued at all.
7. **Tier-profile sidecar format.** Location beside the build cache, keyed by
   KernelPlanKey; which fields (iterations, interpreted ms, O0 arrival
   relative to fixpoint) and staleness policy.
8. **Per-rule vs per-kernel compile granularity cutover.** Before T4,
   selective compilation is per-kernel; define the T4-era policy for emitting
   only compile-worthy rules and how the `.o` cluster map absorbs it.
9. **Small-machine core split.** `P = 1`/`P = 2` behavior for interpreter +
   nice'd compiler sharing; interaction with oracle backend processes.
10. **Whole-fixpoint why-not.** Tabling, recursive cycles, negation, and
    explanation-size budgets, after captured-iteration why-not is useful.

## 14. What this document supersedes or changes

Explicitly, so the paper trail matches the code trail:

- **pausing.md §6 (rule/SCC ids):** the 31-bit source-text-hash rule id and
  daemon-assigned ordinal SCC id are superseded by
  RuleKey/RuleId/SccInstanceKey (2.1); cache stability is preserved via
  NativeSlot mapping instead of text hashing. The deferred
  `malformed_deduction` rule-id wiring is picked up (2.1).
- **pausing.md §8(a) (JIT'd point-query actions):** superseded by interpreted
  QueryPlans (6); `(lookup ...)` becomes protocol sugar. The "args
  side-channel" problem disappears because the protocol carries plans.
- **pausing.md §8(b) (query seams):** consumed, not dropped — the scan-full
  driver mode becomes `scan-full` (6.1), the second RunState context becomes
  `QueryContext` (6.3), and the `bind(db)` re-bind seam generalizes into the
  BindingFrame (2.3).
- **repl.md §6 (watch design):** adopted verbatim as level-0 watches (7.1);
  the pre-commit provenance gate (7.2) is layered above it rather than
  replacing it. repl.md's names/handles/printing/catalog sections are
  unchanged and this document depends on them.
- **fast-compile.md §5 (pool sizing):** the standalone `min(nproc, jobs)`
  pool is subsumed by the daemon-owned core-budget arbiter (5.5); single-
  flight `.so.building` claims, `nice`-d O2, and the per-cluster `.o` cache
  carry over unchanged.
- **fast-compile.md (tier ladder):** "always compile, start at O0" becomes
  "interpret by default, compile selectively" (5); the shipped boundary
  hot-swap (`clearForUpgrade` + `beginStratum` twin re-registration) is
  retained as the attachment mechanism for arriving artifacts.
- **modules.md §8.4 (alpha-normalized reuse):** remains optional for modules
  itself, but the identity model here is designed so that shared
  KernelPlanKey across instantiations is achievable when instantiation ships;
  gate 12.5 applies from that point, not before.
- **The `.so`-path protocol and compiled action plugins:** replaced
  verb-by-verb by the command protocol (9.2), dual-stack during migration.
- **`$stat_fires` keying:** moves from `(location-string, variant-string)` to
  `(RuleId, VariantTag)`, with locations resolved through `rule-meta`.

The intended conceptual rule is simple: **the daemon knows what every rule,
variant, SCC, relation version, and code attachment is; interpreted and native
tiers are interchangeable implementations of the same registered plan;
compilation is an optimization the evidence must earn, never a precondition;
queries read and never write; and debugging changes the executor/observer,
never the Slog program or database semantics.**
