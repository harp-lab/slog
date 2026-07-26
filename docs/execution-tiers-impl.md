# Execution tiers: implementation decisions and prototyped mechanisms

2026-07-14. Companion to [execution-tiers.md](execution-tiers.md). Sections
1–7 are the design-phase record (decisions D1–D18, prototype results,
liftable code, change map); **section 0 tracks as-built execution status**
and is the place to resume from in a new session.

## 0. Execution status (updated 2026-07-16)

**T1 SHIPPED** in `50bb329` (`execution tiers and interpretation prep`).
The changed set was:

```text
new       compiler/canonical-plan.rkt        the pass + serializer + KernelPlanKey
new       tests/unit/canonical-plan-tests.rkt  12-case battery (suite `unit` tier)
modified  compiler/ir-stack.rkt              kernel-plan? as Level 7
modified  compiler/operationalization.rkt    latchk gensym -> per-rule latchk_<n>
modified  compiler/compile.rkt               build/<hash>.plan sidecar, every flavor
```

Verified: quick tier 7/7 (unit, diag, **stats** — the exact-once audit
passing is the T1 gate that generated C++ is unchanged, arena, seq, counts,
wcoj3); 16/16 lattice goldens over the changed latchk path (`latchk_0`
confirmed in a real `.cprog`); cross-process plan-key determinism on a
3-stratum lattice program exercising the ground-value probe; 31 `.plan`
sidecars validate against `kernel-plan?`.

**T2 operator-kernel preparation is now executable, but not lifted into the
daemon.** [tests/interp-operator-tests.cpp](../tests/interp-operator-tests.cpp)
is a standalone design/conformance test over the real daemon headers. It now
contains the VM, pausable cursors, observation ports, continuation ownership,
and a narrow `Plan -> seal -> bind -> bucket task -> attempt-local candidates
-> real emit` vertical slice. It is deliberately the only implementation file
in this slice; no production daemon/compiler/protocol file was changed.

Verified on 2026-07-15: Clang and GCC optimized builds; ASan+UBSan; all 163
Racket unit tests; the 12 canonical-plan tests; the existing WCOJ3 operator
test; and the standalone interpreter battery. See §7 for the production start
order and the findings that must survive the lift.

**Deliberate deviation from execution-tiers.md T1.3 (recorded there too):**
`bumpFires` keeps its aggregated `(loc, base-tag)` key — emit-cpp documents
same-driver variants sharing a key as the exact-once audit's unit, and the
daemon cannot resolve RuleIds until T0's rule-meta registration.
Disaggregated RuleVariantId identity lives only in the `.plan` sidecar for
now. Also deferred: single-TU emission-order canonicalization (to T4 phase
B, with the slot rewrite), prim opcode numbering (to T2, when the daemon
dispatch table exists — plans carry a sorted prim name table).

**Update 2026-07-15 (contract pins + T2-A0):** the "either order" question
below is resolved — the progressive fork was ratified (roadmap §3.1): T0 and
T2-A proceed IN PARALLEL, meeting at the decoded/sealed builder interface,
with contracts pinned first. See docs/rf1-contract.md (minimal-for-T2 Plan
ABI 2 split — the one plan re-key), docs/t0-contract.md (protocol grammar,
verb reservations, identity keys), docs/interp-core-contract.md (freeze
list, freeze trigger, thread 0/1 extension seams). **T2-A0 is done**: the
operator test is the `interp` harness in `tests/run-all.sh` (quick tier;
needs `-fopenmp` — the fixture instantiates `Relation::sendBatch`, which
references `omp_get_thread_num`).

**Determinism finding (2026-07-15, measured; sharpened same evening):**
legacy TU text is run-unstable — crule emission ORDER varies across
compiler runs (gensym'd symbols perturb hash iteration order) on top of
the gensym'd `__t*`/`temp*`/derived `slog_rules_*` names; `deep_fact`'s TU
showed ~12k normalized diff lines across two consecutive same-tree runs.
The canonical `.plan` layer is byte-stable **except where gensym'd temp
relation names reach it**: of 498 fresh plans vs the `build-post2/`
corpus, 273 were byte-identical, 73 differed only via temp gensyms
(spellings in decls/`dynamic`/VariantTags, and — for 47 — D4 sort-order
perturbation, since the canonical sort key contains the spelling), and
152 sat under MOVED stems with byte-identical content (`eb30565e` ≡
corpus `453edaee`). **Slice 0 (SHIPPED same day, rf1-contract.md
as-built) resolved the full picture:** the moved stems were NOT
job-hash churn — `progstr` precedes planning and two symmetric clean
runs measured 2941/2941 filenames byte-identical; the discrepancies
were asymmetric compile sets (cold `config/cache`, wall-clock-lazy
action plugins) and cross-era corpus comparison. Slice 0 made temp
names deterministic (`temp[<flavor>]<level>x<n>` in canonical rule
order), fixed the one genuine pre-cache-key gensym (anonymous inline
union, modules.rkt), and fixed two further plan-layer instabilities its
gate exposed (non-total D4 sort key; temp column order over gensym'd
variable spellings). Post-slice-0: 500/500 plans byte-identical across
runs. Remaining: TU emission-ORDER canonicalization stays at T4 phase B
(`__t*` local gensyms still churn TU text → `.o`-cache misses only);
wholesale TU byte-diffs remain an invalid gate methodology. The pre-existing
`$sup`/`_lam` checkout-path dependence was closed 2026-07-20:
`source-name-key` normalizes provenance relative to the compilation root before
hashing, a two-clone unit test pins the key, and `dem_lambda` passes in both
native and interpreted modes with the repository-relative golden.

**Update 2026-07-15 (T2-A1 done):** the production interpreter core is
extracted into `daemon/interp.h` (namespace `slog::interp`, ~710 lines):
immutable `Program` (rule_id, D3 `variant_ordinal`, display `variant`,
`nregs`, ops, `driver_regs`, preloads), `TupleView`, the `PrefixCursor`
family with `current()` (impl §3.2 spelling), the five-state `Machine`
with ONE policy-templated transition loop instantiated twice
(`run_fast`/`run_observed`; the production `run` selects the fast
instantiation on a zero effective event mask), post-transition
mask-gated events carrying the variant ordinal and a bounded
attempt-scratch payload view, and the contract's three-range opcode
reservation as named constants + static_asserts (core 0–95, thread-0
96–159, thread-1 160–191, both reserved ranges empty). At that checkpoint the
fixture instantiated the core while seal/bind remained test-side (it is lifted
below); `make -C daemon interp-check` is a compile-only
standalone check under the daemon's flags. Verified: clang/gcc -O2,
ASan+UBSan, `run-all.sh interp arena seq counts wcoj3 structid`,
`make -C daemon`.

**Update 2026-07-16 (T2-A2/A3 engine path landed):** `daemon/plan.h` now owns
the production decoded/sealed/bound normal-set vocabulary and the real
`InterpReadTask`; `daemon/plan.cpp` owns the out-of-line full-arity factories,
and `daemon/runtime.cpp` is the shared home of the daemon index factories.
Seal validates register dataflow, relation slot/arity/kind, requisitioned
orders, head ports, RuleVariant uniqueness, operand-bank bounds, and exact
factory coverage before bind. Production drivers stream the live delta or
prefix index (no materialized driver table), and bound sink ports feed the
existing `emit<A>` family through task-owned batches (diagnostic candidate
vectors are disabled on this path). The VM gained only the representation
pieces the production lift required: an erased cloneable outer-driver cursor
and `emitn` over an immutable register-operand bank, preserving fixed-size ops
while covering the daemon's complete arity range.

The A3 task runs through `Stratum`'s existing read scheduler, 128-transition
deadline polls, `pushPaused`, and the existing write/intern barriers. Its
recursive admission fixture compares **per-iteration deltas and disaggregated
variant fires** against the fused native `read_delta`/`join_probe`/`emit` path
under the same two-worker scheduler, and drives clean-boundary pause/resume.
The production factory path is also exercised above the old 2/3-arity
prototype (arity 4, including `emitn`).

**Update 2026-07-16 (T0 sidecar half of slice (b) landed):** the reusable
`sexp.h`/`sexp.cpp` reader is bounded (16 MiB / 1M nodes / depth 256 for
sidecars), and `plan.cpp` now owns the ABI-1 decoder for relation binding
schemas, storage-neutral constants,
RuleVariant identity/source metadata, and rule forms. Unsupported but
well-framed canonical operators decode to immutable capability markers and are
refused at seal; no parser or factory lookup reaches a worker thread. Typed
parse and D16 seal classes cover ABI/flavor, register bounds/dataflow,
relation slot/kind/arity, constant slots, order/requisition, bound prefixes,
head coverage, RuleVariant uniqueness, factory coverage, and binding.

The fixture `tests/data/t0-normal-set.plan` is byte-for-byte real
`canonical-plan.rkt` output, including the standard unused service-struct
prelude. It parses, seals, selectively binds only referenced ordinary-set
slots, and executes through the real scheduler/emit path. As an additional
corpus audit, the reader parsed all 857 sidecars then present in `build/` and
`build-post2/`. This completes the `.plan -> decoded -> sealed -> bound ->
task` seam; it does **not** complete T0 slice (b)'s entry modes or T0's command
dispatcher/builders, and it is not T3 tier selection (`SLOG_OPT=interp` remains
ahead).

**Update 2026-07-16 (T2-B group (i) landed):** the same ABI-1 path now
decodes, seals, and binds `join-old`, `join-new`, `exists`, and `absent`, plus
full/delta index requisitions. Old/new and filter implementations are
arity-erased cursor registrations behind the frozen tri-state interface; no VM
opcode or state-machine change was needed. K=0 old/new view scans and K=0
absence are covered, while ordinary full-view K=0 joins remain in their later
group. Factory ladders resolve at bind, so read workers clone bound prototypes.
The focused conformance test compares view rows and fire multiplicity against
the native helper semantics and exercises typed seal/bind refusals.

**Update 2026-07-16 (T2-B group (ii) landed):** canonical `let`/copy,
`letp`, `eq`, `cmp`, and `tycheck` now preserve ordered pre/body/head
placement through the same decoder and seal. Seal proves register dataflow,
the declared primitive table, exact arity and total/partial ABI, accept tags,
and the five-column malformed effect shape. Bind resolves shared
`prims.h`/`seq_prims.h` functions, runtime struct ids, and ordinary/struct
sinks once. The VM additions stay inside the reserved core opcode region:
straight-line total/copy ops do not invent observation ports, while partial,
comparison, primitive-error, and type-check outcomes reuse guard events and
the existing backtrack arm. `tycheck` follows `fire` exactly as native code
does and stages `(rid, relation, column, bad)` through a bound
`malformed_deduction` struct port. A parsed differential exercises pre
evaluation, continuation slicing, partial absence, the type diversion, and
ordinary/effect production sinks against the shared native control flow.

**Update 2026-07-16 (T2-B group (iii) landed):** canonical two-arm `join3`
now decodes, seals, binds, and executes as one tri-state cursor level. The
composite owns two independently arity-erased key-simple arms and performs the
native symmetric seek/leapfrog loop under `WorkBudget`; FULL/OLD/NEW is
runtime data inside the already-erased arm, avoiding three duplicate factory
ladders without changing view equations. `seek` and `advance_past` remain
private to those arms. The only general cursor addition is lazy
`premise_count()`/`premise(i)` with a one-row default, allowing a join3 proof
to retain both positioned rows. All nine view pairings are differential-tested
against native `join3`, including budget-1 continuation cloning, fires,
parsed production sinks, and typed refusal classes.
The fixture also pairs a three-column arm with a two-column arm to pin the
linear independent-arity factory rather than only same-arity triangles.

**Update 2026-07-16 (T2-B group (iv) landed; core frozen):** canonical
`join-lat` and `absent-lat` now decode, seal, bind, and execute behind the
same tri-state cursor interface. A lattice storage row of arity `A` binds a
payload-map index of key arity `A-1`; seal requires a full physical ordering
whose last column is the payload and proves the K-column bound prefix. One
cursor/factory ladder implements K=0 all-bucket joins, K>0 prefix joins, and
pre/body absence, with lazy key-plus-payload proof scratch and no premise for
absence. Binding checks the concrete map-index type before the typed cast.
Native differentials cover non-identity key order, rows, fires, absence,
budget-zero pause/clone continuation, production sinks, and typed refusals.
No opcode, VM arm, or public cursor method changed. All four pre-freeze groups
are now green, so the interpreter core is frozen under the joint-review rule;
this satisfies the progressive-fork dependency but not the full daemon F
gate.

**Update 2026-07-16 (Q1 slice 1 + R2 engine surface landed):**
`daemon/query.h`/`query.cpp` now own a second, main-thread query context with a
master-index `scan-full` driver, capture-only `yield` sink, bounded pages,
continuation slicing, cancellation, and one-active-query admission. The
client-neutral result mode is the R2 register's `?`/`?count`/`?exists` split,
and the bound plan exposes a structured `explain` record. Query execution
reuses the frozen machine and bound-sink seam without adding an opcode, VM
arm, relation batch, `RunState::paused_tasks` entry, or phase cursor.

`InternTable::probe_value`, `Database::probeString`, and
`Database::probeMpz` resolve short strings and normalized bignums without an
insert; a miss seals the bound query as unsatisfiable. Strings longer than
`SEQ_BLEAF_MAX`, malformed literals, delta views, absent existing indices,
and all primitive computes are conservatively refused in this first slice.
The fixture covers paged rows, count/exists, zero cursor budget, cancellation,
all four quiescent admission labels, one-query serialization, probe hits and
misses, and typed refusals. It snapshots every fixture master row plus exact
string/mpz/collection/sequence heap counts before and after the successful,
paused, cancelled, empty, and refused paths.

**Update 2026-07-16 (Q1 slice 2 engine forkpoint landed):** `ScanFullPlan`
registers are now nominal-column mappings. An empty requested order selects a
deterministic existing catalog order at bind and remaps the physical driver
tuple before entering the frozen VM; `explain` marks this
`scan-plus-filter`. An explicit requested order remains exact and refuses a
missing concrete index. Neither path calls `addIndex`.

The query compute registry is intentionally separate from the ordinary rule
registry. Its first audited set contains the four numeric comparison guards,
`tofloat`, `size`/`sidx`/`shas`, and
`aslst`/`llen`/`lref`/`lidx`/`lmem`. Checked adapters reject wrong runtime
types as a row miss before the shared kernel can write `PendingError`; every
admitted result is immediate or already interned. Paging exceptions now
cancel and release the one-query lease before they propagate. The fixture
pins reverse-only physical order, nominal remapping, paged fallback,
total/partial/guard computes over mixed runtime types, cancellation, paging
failure, master rows, all four heap counters, and pending-error scratch.

**Update 2026-07-17 (Q1 slice 3 catalog planner landed):**
`compiler/query-plan.rkt` is the transport-free construction boundary between
a selected catalog snapshot and `query.h::Plan`. Its snapshot keeps logical
name/type declarations separate from exact VersionKey, materialized full
orders, and tuple-count facts. Planning validates types, safe negation,
relation capabilities, and the query-only primitive whitelist, then performs
a memoized deterministic search over existing positive index prefixes. It
emits stable bindings/registers, eagerly scheduled guards/absence/computes,
and structured scan-plus-filter, probe-plus-filter, and forced-join-order
explanations. It never requisitions an index. Ten focused cases and the full
212-test compiler unit battery pass.

**Update 2026-07-17 (Q1 slice 4 / T2-B ordinary K=0 landed):**
`DynamicProbeCursor<A>` now treats an empty key-register vector as a
full-view body scan across all hash buckets. Nonzero prefixes retain their
single-bucket path, and the separate probe-driver capability remains K>=1.
No opcode, VM arm, or public cursor method changed. A parsed ABI-1 K=0 join
now seals; its native differential pins non-identity physical order,
Cartesian fire multiplicity, proof rows, and pause/clone continuation. Query
binding labels a K=0 body cursor as degraded, and the hygiene fixture executes
a paged body scan plus equality without changing rows, heaps, or pending-error
scratch. The pure planner includes K=0 choices in its deterministic cost
search and explains them as body scan-plus-filter. The expanded planner
battery has 11 focused cases; all 213 compiler unit tests and the optimized
native interpreter/query battery pass.

**Update 2026-07-17 (Q1 slice 5 / catalog-to-daemon meeting contract
landed):** `query-catalog-from-boundary` now consumes an N2/N3-shaped triple:
logical declarations `C_k`, the selected QName-to-VersionKey environment
`E_k`, and runtime materialization facts keyed by VersionKey. It checks
declaration/environment/materialization referential integrity and kind/arity
agreement, while retaining empty storage declarations instead of discovering
the catalog from nonempty daemon relations.

The planner serializes one canonical ABI-1 `query-plan` payload containing
BoundaryKey/generation, dense relation slots, exact VersionKeys, existing
full orders, tuple counts, registers, literals, operations, driver,
projection, and result mode. `daemon/query.cpp` decodes that payload through
the shared bounded S-expression reader into `DecodedPlan`, seals it through
the existing query audit into `SealedRequest`, and binds every runtime slot by
VersionKey alone. QName is display metadata and no bind path requisitions an
index. A checked-in payload is generated byte-for-byte by the Racket planner,
then parsed, sealed, VersionKey-bound, paged, and executed by the C++ battery;
malformed dense slots, wrong ABI, and same-name/wrong-VersionKey bindings are
typed refusals.

At this checkpoint the tree had neither N2/N3's persistent boundary-catalog
producer nor T0's generic dispatcher. The dispatcher has since landed and, as
of 2026-07-23, embeds this payload unchanged under `query`, checks generation
and quiescent phase admission, binds exact VersionKeys, and owns
`query-page`/`query-cancel`. One connection-scoped cursor refuses every
non-query command/plugin path until completion or cancellation. Structured
row/page sentinels and the protocol transcript are now live. N3-B now supplies
live committed BoundaryKey/catalog authority: binding first selects the direct
boundary snapshot, then checks each QName's exact VersionKey. N3-C now
supplies the independent SID/TypeKey descriptor registry and boundary-aware
historical struct rendering. N4 still owns persistence of that history and
the REPL still owns checked `#N` value-handle lifetimes before R2 can expose
rich expandable typed values.

**Update 2026-07-19 (T2-B normal `once`/`seeded` landed):** normal plans now
seal both unit-driver forms. Bound-rule registration carries an explicit
`every`/`once`/`seeded` schedule outside the frozen VM: `once` enters the
first-iteration queue, while normal `seeded` enters the replay-only queue and
reruns every iteration iff the run was externally seeded. Counted plans keep
their existing interpretation of the seeded plan shape as a one-shot settled
recount. The executable differential compares fresh and externally-seeded
runs against fused native tasks at boundary deltas, final rows, and exact fire
totals; maintenance flavors retain a typed refusal for unit drivers. No VM op,
state-machine arm, or cursor interface changed.

**Update 2026-07-19 (T2-B normal temp/struct sinks landed):** normal
`emit-temp` now binds the existing nominal, append-only `emit_temp` sink; a
typed bind check distinguishes compiler temporaries from ordinary set
relations. Normal `mkstruct` stages master-content fields with a zero id and
leaves content dedup, tombstone resurrection, and id allocation to the
unchanged `InternStructTask`. A seeded normal construction binds the master
index and calls `emit_struct_checked`, so full-join replay skips already-live
content and reaches fixpoint. Normal scan-delta drivers may consume temp,
struct, and lattice deltas, which closes the staged follow-up paths without
changing the VM. Native differentials pin duplicate
temp preservation, boundary-by-boundary staging waves, exact assigned struct
ids, seeded replay fires, and one-time struct-delta consumption.

**Update 2026-07-19 (T2-B normal lattice/declaration path and interpreter-only
route landed):** normal `emit-lat` now stages nominal contribution rows for the
unchanged `LatticeInternTask`; declaration install reconstructs set, temp,
struct, and lattice relations, full/delta/seeded-only indices, native
write/intern/map-write tasks, decompositions, oracle bindings, and sequence
indices from the sealed plan. Probe drivers were corrected to the compiler's
actual ABI: they prefix-probe requisitioned **DELTA** BTree indices for every
storage kind. Canonical `cjoin` lowers at seal time to the frozen primitive op
with one hidden pre-parsed lattice-spec register, and ordinary struct filters
reuse the native BTree filter cursor. The cold installer preserves the native
reverse declaration walk so constructor tags, collection hashes, and rendered
map order remain identical. `SLOG_OPT=interp` now sends normal and delta
`.plan` artifacts directly to `slogd`, invoking neither compilation nor
`dlopen` for those strata; separate action plugins remain native. The existing
native stratum modes remain unchanged.

The focused interpreter/native battery and a 29-program lattice/sequence/SMT
matrix are green. The formerly shared `dem_lambda` mismatch was repaired
2026-07-20 by making demand-generated source keys compilation-root-relative;
its targeted native run is green and the full `SLOG_OPT=interp` golden suite
is now mechanically green at 165/165.

**Next up (post-freeze ratified order):**

- **T0** — slice (a)'s dispatcher/catalog surface and slice (d)'s uniform
  pause record are landed. Slice (b)'s checked entry state machine and legacy
  shims are landed; finish its provisional command builder and resident-count
  tier-policy refusals next. Slice (c)'s
  identity keys + rule-meta + D9 fire vectors remains a fork-gate substrate
  chore; the level-0 watch implementation follows the fork on slice (d)'s
  record.
- **T2-B trunk groups under frozen interfaces** — the monotone normal
  vocabulary, lattice sinks, declaration-built tasks, and compiler-driven
  `SLOG_OPT=interp` route are landed. The checkout-independent `dem_lambda`
  baseline is repaired; record the mechanically clean full-suite gate;
  stale caches that predate `.plan` must re-emit on miss.
- **Progressive-fork workstreams** — Q1's first engine slice and the
  client-neutral R2 result modes, catalog planning, and the typed QueryPlan
  wire/builder boundary are landed; continue with the N2/N3 catalog producer,
  T0 query protocol, then the R2 client surface. Counted interpreter to M4N
  may proceed independently. Both extend only the pinned seams and follow the
  ownership/joint-review rules.
- **RF1** — per docs/rf1-contract.md; the four-way ABI split re-keys plans
  once; T2-A consumes the post-split KernelExecPlan shape.
- **M4S** — starts immediately under the progressive fork (thread-0 spine).

Implementation gotchas already hit once (do not rediscover): the
`all:`/`delta:` tag prefix is dynamic-rels membership, so input-only
relations scan as `all:`; the cprog constants hash is keyed value→name;
`*_base.slog`/`*_lib.slog` files are multi-file-test helpers that fail
standalone by design — never glob them into `run-tests.sh` args.

Two original working prototypes live in `/tmp/slog-tiers-proto/` (session
artifacts; the liftable parts are inlined here), and the interpreter work now
has the permanent executable test linked above:

- `interp_proto.cpp` — the arity-erased cursor layer and a register-machine
  rule interpreter, compiled against the **real** daemon headers
  (`clang++ -O2 -Wall -std=c++20 -pthread -I daemon interp_proto.cpp -lgmp`,
  the same recipe as `tests/wcoj3-operator-tests.cpp`), raced against the
  exact fused loop shape `emit-cpp` generates, with differential checksums.
- `canon-proto.rkt` — the canonical KernelPlan pass run over **real** `cprog`s
  from the actual front half (the `tests/unit/wcoj3-tests.rkt` harness:
  `load-program-list` → typecheck → stratify → `plan-stratum` →
  `build-cprog`), serialized and verified byte-identical across separate
  Racket processes.

## 1. Measured results

### 1.1 Interpreter overhead (P1)

Workloads: copy rule (scan 20M rows, emit); one-level join
`edge(a,b), edge(b,c) → (a,b,c)` at fanout ~100 (~20M outputs); the same plus
a `neq` guard; a two-level join at fanout ~10 (~20M outputs). All variants
emit into identical batch vectors and must produce equal checksums (they do).

```text
variant                ms         rows   factor     ns/row
copy/native         118.0     20000000    1.00x      5.90
copy/vm             153.6     20000000    1.30x      7.68
join/native         199.1     20195961    1.00x      9.86
join/virt           192.5     20195961    0.97x      9.53
join/fnptr          220.9     20195961    1.11x     10.94
join/vm             243.3     20195961    1.22x     12.05
joinG/native        198.3     20195741    1.00x      9.82
joinG/vm            260.3     20195741    1.31x     12.89
join2/native        414.3     19986967    1.00x     20.73
join2/vm            506.4     19986967    1.22x     25.34
```

Conclusions:

1. **The full register-machine interpreter costs 1.2–1.3× native on the read
   side**, across copy, shallow, guarded, and nested join shapes.
2. **Nesting depth does not amplify overhead** (1-level 1.22×, 2-level 1.22×):
   per-row BTree work grows with depth while dispatch amortizes.
3. **Cursor erasure is free.** A virtual-dispatch pull cursor alone runs at
   parity with the fused native loop (0.97×, i.e. noise): `lower_bound` and
   node traversal dominate; one indirect call per row vanishes under them.
   The "faster" function-pointer + inline-state variant is actually *slower*
   (1.11×) and more code.
4. Since write/intern phases are shared code under either executor, **whole-
   iteration interpreted slowdown will be under these read-side factors** —
   strongly supporting interp-only defaults for everything but proven-hot
   recursive kernels.

Caveats: single-threaded, warm cache, uniform random keys, batch emit stands
in for the real `sendBatch` path (identical for both sides), no OpenMP
contention. T2 must re-verify on `bench/` harnesses; these numbers size the
thresholds, they do not replace `bench/regress.sh`.

### 1.2 Canonicalization (P2)

The pass ran over real lowered plans for (a) the recursive triangle (which
lowers to three exact-semi-naive `join3` crules), (b) a compute/prims rule,
(c) a body-constant rule. Findings:

1. **Deterministic**: serialized plans are byte-identical across separate
   Racket processes (three runs compared).
2. The walker covering the full c-op grammar (registers, relation slots,
   constant slots, prim collection) is ~90 lines (section 3.3); the plan for
   a stratum is ~1–2 KB of text at these scales.
3. Two real identity findings and several mechanical ones — section 4.

### 1.3 Pause/debug/operator-chain prototype (P3, 2026-07-15)

The permanent
[interpreter operator test](../tests/interp-operator-tests.cpp) adds a second,
deliberately dispatch-dominated benchmark (200K driver rows, 800K emitted
candidates) and, more importantly, executable correctness tests for pausing
and observation. Across repeated local runs:

```text
path                         factor vs fused native
unobserved fast VM                 2.2–2.6x
micro-stepped observed VM          3.7–5.0x
```

This is a stress ceiling, not a replacement for §1.1: it minimizes BTree work
per dispatch, whereas the realistic joins remain 1.2–1.3x. It nevertheless
pins an implementation rule: **ordinary execution and rich observation need
separately compiled loops** (or compile-time policy specializations). An
effective event mask of zero selects the fast loop. The observed loop pays for
post-transition event construction, breakpoints, and optional lazy proof
capture; native O0/O2 remains the right escape hatch for hot SCCs.

The test also verifies every VM quantum from 1 through 31, a cursor that
pauses repeatedly inside the search for one match, a 96-level cursor stack,
all event/breakpoint ports, bounded proof capture, and continuation cloning
under Clang, GCC, ASan, and UBSan.

## 2. Crystallized decisions

**D1. Cursor representation: virtual dispatch, state inline, tri-state
pull.** One abstract `PrefixCursor { open(regs), next(regs, budget) }`, where
`next` returns `match | exhausted | paused`; concrete `Probe<A,K>` holds the
btree iterator pair and bound key inline and writes output registers itself.
The current match remains positioned until the next call, so proof capture can
read it lazily without copying on the unobserved path. Ordinary cursors expose
one proof row by default; join3 exposes both positioned arms. Measured at
parity with fused native; no function-pointer tables, no placement new. The
join3 composite uses the same public tri-state pull shape, while its typed
arms keep `seek`/`advance_past` private. A boolean `next` is insufficient
because an intersection can exhaust a work slice before it either finds a
match or proves exhaustion.

**D2. Rule executor: register machine with explicit level stack.** Register
file of plain `u64` (16 default, sized from the plan's `nregs`); ops in a
`std::vector<Op>`; switch dispatch; probe levels push their op index onto a
level stack so backtracking and mid-nest pausing are array operations. The
complete backtracking loop is ~60 lines (section 3.1) and was validated
differentially. Deadline polling: every 128 driver tuples (the
`read_delta_sliced` cadence) plus inside long cursor loops. The level stack is
plan-sized, not an illustrative fixed array: real cached plans observed during
P3 reached 85 cursor levels and 251 registers; the permanent test exercises
96 levels.

**D3. VariantTag must include a version ordinal — the doc's §2.1 as written
is insufficient.** Prototyped fact: the recursive triangle lowers to *three*
crules whose driver-derived tag is identically `delta:edge`, differing only in
view assignment (full/full, old/old, full/old). Today's stat label
`(loc, "delta:edge")` deliberately *aggregates* them — fine for `$stat_fires`,
fatal for slot mapping and executor replacement. Fix: the canonical pass
numbers same-source-rule crules in canonical order and the tag becomes e.g.
`delta:edge#0..#2` (flavor kind suffixed as today). RuleVariantId uniqueness
becomes a seal-time validation error, not an assumption.

**D4. Canonical rule order: sort crules by their canonical serialization.**
Today's order is `(set->list planned-rules)` (`operationalization.rkt:134`) —
deterministic for fixed content in one Racket version, but *edit-unstable*
(any rule addition can reorder every hash bucket). Sorting by serialized
canonical text is edit-stable, which is what RuleId stability across program
edits (and golden plan files) actually needs. RuleIds are assigned in that
order.

**D5. Slot tables.** Relation slots: decls sorted canonically, slot = index
(the prototype's `(rel N ...)` table). Constant slots: **the cprog constants
hash is keyed value→global-name** (verified; not name→value) — the pass
inverts it and emits `(k slot name value)` entries sorted by name. Primitive
opcodes: two-phase — collect prim symbols during the walk, freeze a sorted
table, rewrite on a second pass (the prototype keeps names to stay readable;
the real pass emits opcodes).

**D6. Plan transport: one `write`-printed form per line over the existing
line framing.** A kernel plan serializes to a single S-expression; `write`
produces one line; the dispatcher already reads lines. No length-prefixed
framing until a measured need exists. `pretty-write` is for humans and
goldens; both `read` the same.

**D7. Probe-only interning has a rope-sized hole.** Short strings
(≤ `SEQ_BLEAF_MAX`) need only a non-allocating `InternTable` lookup beside
`intern_string` (`database.h:2552`) — straightforward. But
`encodeString` for longer content **builds rope nodes in the sequence arena**
(`database.h:2610-2616`, `seq_arena->build_bytes`), which is an allocation a
read-only query must not perform. The content-defined chunking is a pure
function of the bytes, so a `probeString` can compute would-be node keys in
scratch memory and look them up without inserting — but that is a real
`seq.h` work item. **v1 queries reject string literals longer than
`SEQ_BLEAF_MAX` with a structured error** rather than blocking on it; same
policy for collection literals pending an arena dry-run probe.

**D8. QueryContext: a second, smaller RunState-shaped context.** Owns its own
task cursor, budget/deadline, and output pages; never touches
`RunState::paused_tasks` or phase cursors. Admission: daemon idle,
`RUN_AT_BOUNDARY`, mid-read suspension, or `RUN_READ_COMPLETE` — all states
where master indices are quiescent (the read phase never mutates master).
v1 runs one query at a time on the main thread (the shipped suspend already
guarantees the worker region has exited; pausing.md §8 made the same
observation for read-only plugins).

**D9. Per-attempt fire stats become an array — and get cheaper than today.**
`bumpFires` currently locks a `std::map<pair<string,string>, u64>`
(`database.h:3942-3960`). Dense RuleVariant ordinals (D3/D4) turn this into a
plain per-attempt `std::vector<u64>` indexed by ordinal, merged into the
durable table at read commit. This simultaneously provides the
`ReadAttempt` discard semantics (drop the vector) and removes a string-keyed
map from the hot path. Do this in T1/T2, not T6 — it is a prerequisite
made cheap, not a rider.

**D10. One `installStratum(entry_mode)` replaces the beginStratum /
beginStratumDelta pair.** `fresh` performs the deferred
`reloadInsertBatches` ordering exactly as `beginStratum`
(`daemon.h:200-244`); `resident-delta` / `resident-count` perform the
positional bind with no reload exactly as `beginStratumDelta`
(`daemon.h:293-315`); the hot-swap twin-registration path becomes an explicit
`upgrade` attachment rather than a name-match side effect. Validation refuses
tier swaps/restarts against `resident-count` (execution-tiers.md §9.1).

**D11. Interpreter task integration.** `InterpReadTask : Task`, one instance
per (rule variant, bucket), constructed at plan install; owns its VM,
register file, and bound cursor table; `bind()` resolves `Relation*`/index
pointers exactly where native tasks do it today. Parking reuses
`pushPaused`/`paused_tasks` unchanged: a parked interpreter continuation
carries live btree iterators, which is safe for exactly the same reason the
native `(rt, ri)` park is safe — indices are immutable until the finalize
that a suspension skips — and must be discarded at any finalize, which the
existing copy-for-resume ownership rule already enforces. A parked task pins
the immutable decoded/bound program generation; it must never hold a raw
pointer into an install object that an upgrade can retire.

**D12. Adapter/factory ladders live in the daemon, once.** The precedent is
already shipped and measured: moving the `makeIndex` arity ladder out-of-line
into slogd cut a median stratum's clang -O2 from ~10s to ~4.6s
(`index.h:244-250`, fast-compile.md §7.1). The cursor factories (per (A,K)),
task factories (write/intern/lattice/count per arity), and prim tables follow
the same pattern: instantiated once in `slogd.cpp`, reached through the
daemon's exported symbols.

**D13. Head sinks erase the existing emit family.** The interpreter calls the
same `emit`/`emit_temp`/`emit_struct`/`emit_lat` templates
(`operators.h:520-616`) through a bound sink table built like the cursors —
no second emit implementation, so send-shard formatting, error structs, and
struct-id placeholder behavior are shared by construction. Every emit opcode
carries an explicit bound sink port, and every attempt-local candidate retains
that port. Head selection must not be reconstructed from candidate order.

**D14. VM ops carry pre-resolved operands, not names.** Bound at install:
cursor index, register numbers, constant slot values already materialized
into a constant register bank at frame setup (so `(pre (let r k))` becomes a
register preload executed once per task, not per tuple).

**D15. Debug events are post-transition and proof payloads are lazy.** Driver,
probe match/miss/exhaustion, guard pass/fail, instantiation, and emit are stable
ports. A breakpoint observes state after the semantic transition has committed
to the read attempt, so resume cannot retrigger it. Events carry RuleVariant,
op index, and bound cursor/sink port; driver/register/current-premise views are
materialized only when an enabled observer requests them. Proof counts and
failure frontiers are bounded explicitly.

**D16. Seal against the daemon capability table.** Register bounds/dataflow,
relation slots and arities, ordering permutations and requisition, bound-prefix
availability, head coverage, and RuleVariant uniqueness are seal errors. The
seal also checks that every `(operator kind, A, K, view)` has an instantiated
daemon factory. A syntactically valid plan must never discover a factory-ladder
miss on a worker thread.

**D17. Driver partition contracts stay distinct.** A delta scan consumes the
relation's even round-robin `read_buckets`; those bucket numbers are not tuple
hashes. A partially bound probe driver probes one shared prefix and partitions
matches by `buckethash(first freshly bound column)`. A fully bound probe has
one task. These three cases share no inferred generic "bucket" rule.

**D18. Candidate, accepted insert, and committed delta are different event
levels.** A satisfying body increments `fire` once, then may produce several
head candidates. An existing master row can reject a candidate at the shared
emit sink. Trace/provenance may report that attempted derivation, but a level-1
watch settles only accepted changes before commit. Attempt-owned candidates,
batches, and fire counters can be discarded and replayed from immutable input;
cross-tier mid-read takeover restarts rather than translating live iterators.

## 3. Liftable code

### 3.1 The VM inner loop (validated shape for `daemon/interp.h`)

The following is the original throughput skeleton. It records the compact
backtracking structure, but its boolean cursor calls predate D1's internal
pause result and its fixed `level_ip[8]` is illustrative only. The executable
[operator test](../tests/interp-operator-tests.cpp) is authoritative for the
state machine (`need_driver | dispatch | first_cursor_match | advance |
done`), plan-sized level storage, post-transition stops, and continuation
copying.

```cpp
enum class OpK : u8 { probe, guard_neq, /*...,*/ emit };
struct Op { OpK k; u8 cursor; u16 a, b, c; };

// One driver tuple through the rule body: nested-loop backtracking over an
// explicit stack of open cursor levels. level_ip[d] = op index of level d.
inline void run_driver_tuple(Batch& out)
{
  int level_ip[8]; int depth = 0; size_t ip = 0;
  for (;;)
  {
    if (ip == ops.size())                      // one full instantiation done
    {
      if (depth == 0) return;
      ip = level_ip[depth - 1]; goto advance;  // resume deepest level
    }
    switch (ops[ip].k)
    {
      case OpK::probe:
      {
        PrefixCursor& cur = *cursors[ops[ip].cursor];
        if (cur.open(regs) && cur.next(regs)) { level_ip[depth++] = ip; ++ip; continue; }
        if (depth == 0) return;                // empty probe: backtrack
        ip = level_ip[depth - 1]; goto advance;
      }
      case OpK::guard_neq:
        if (regs[ops[ip].a] != regs[ops[ip].b]) { ++ip; continue; }
        if (depth == 0) return;
        ip = level_ip[depth - 1]; goto advance;
      case OpK::emit: /* bound sink */ ++ip; continue;
    }
  advance:
    for (;;)                                   // advance deepest open cursor
    {
      PrefixCursor& cur = *cursors[ops[ip].cursor];
      if (cur.next(regs)) { ++ip; break; }
      if (--depth == 0) return;
      ip = level_ip[depth - 1];
    }
  }
}
```

Pausing mid-nest = park (`ip`, `depth`, `level_ip[]`, cursors, regs) — all
plain state, no C++ stack capture. `letp` failure and `tycheck` failure are
the `guard` arm's backtrack (row abandon); `absent` is a probe arm that
*fails* on `open()` success.

### 3.2 The cursor (validated shape)

```cpp
struct PrefixCursor
{
  virtual ~PrefixCursor() = default;
  virtual std::unique_ptr<PrefixCursor> clone() const = 0;
  virtual void open(const u64* regs) = 0; // build key, lower_bound
  virtual CursorResult next(u64* regs, WorkBudget&) = 0;
  virtual TupleView current() const = 0;  // valid while positioned; debug only
};

template <u16 A, u16 K>
struct Probe final : PrefixCursor
{
  Index** index; u16 keyreg[K]; u16 outreg[A - K];
  typename BTreeIndex<A>::iterator it, end;
  std::array<u64, A> key{};
  bool positioned = false;
  void open(const u64* regs) override
  {
    for (u16 i = 0; i < K; ++i) key[i] = regs[keyreg[i]];
    for (u16 i = K; i < A; ++i) key[i] = 0;
    auto* idx = static_cast<BTreeIndex<A>*>(index[buckethash(key[0])]);
    it = idx->lower_bound(key); end = idx->end();
    positioned = false;
  }
  CursorResult next(u64* regs, WorkBudget& budget) override
  {
    if (positioned) { ++it; positioned = false; }
    if (it == end) return CursorResult::exhausted;
    const std::array<u64, A>& m = *it;
    for (u16 c = 0; c < K; ++c)
      if (m[c] != key[c]) return CursorResult::exhausted;
    if (!budget.tick()) return CursorResult::paused;
    for (u16 i = K; i < A; ++i) regs[outreg[i - K]] = m[i];
    positioned = true;
    return CursorResult::match;
  }
};
```

Variants needed beyond `Probe<A,K>`: full-scan (K=0 all-bucket, for `scan-full`
and K=0 negation), delta-scan driver (wrapping `getReadBucket` RefVecs),
old/new exclusion probes (the `join-old`/`join-new` dord logic),
map-index probe (`BTreeMapIndex<KA>`, binds payload last), absence probes
(open-only), and the join3 composite. All are arity-laddered factories in
`plan.cpp` (D12); join3 erases each arm independently rather than
instantiating the left/right arity cross-product.

### 3.3 The canonicalization walker (validated shape for
`compiler/canonical-plan.rkt`)

The essential move — one `reg!` resolver distinguishing constants from
variables, one clause per c-op form:

```racket
(define regs (make-hash))
(define (reg! v)
  (cond [(const-slot v) => (lambda (k) `(k ,k))]
        [else `(r ,(hash-ref! regs v (lambda () (hash-count regs))))]))
(define (op->canon op)
  (match op
    [`(join ,rel ,ord ,K ,xs ...) `(join ,(rel! rel) ,ord ,K ,@(map reg! xs))]
    [`(join3 ,cycle ,arms ...)
     `(join3 ,(reg! cycle)
             ,@(for/list ([arm arms])
                 (match-define `(,view ,rel ,ord ,K ,dind ,ys ...) arm)
                 `(,view ,(rel! rel) ,ord ,K ,dind ,@(map reg! ys))))]
    [`(let ,x (,f ,ys ...)) `(let ,(reg! x) (prim ,(prim! f) ,@(map reg! ys)))]
    ;; ... one clause per remaining c-op/hop/driver form (grammar:
    ;; ir-stack.rkt:239-441); the prototype covers all of them in ~90 lines
    ))
```

First-use order is: `pre` ops, driver, body, head — note that `pre` runs
*before* the driver (constants load there for probe drivers), so registers 0..
are not necessarily the driver's columns.

### 3.4 A real serialized plan (prototype output, recursive triangle)

```text
(kernel-plan
 (stratum 0)
 (relations
  (rel 0 (relation edge 2 (0 1) (1 0) (delta 0 1) (delta 1 0)))
  (rel 1 (relation error 1 (0)))
  (rel 5 (struct malformed_deduction 5 (1 2 3 4 0) (0 1 2 3 4)))
  ...)                     ; every stratum also declares the error structs
 (constants) (prims) (dynamic edge)
 (rules
  (rule-def (id 0)
   (variant delta:edge (nregs 3) (pre)
    (driver (scan (rel 0) (r 0) (r 1)))
    (body (join3 (r 2) (full (rel 0) (0 1) 1 () (r 0) (r 2))
                        (full (rel 0) (0 1) 1 () (r 1) (r 2))))
    (head (emit (rel 0) (0 1) (r 2) (r 0)))))
  (rule-def (id 1)
   (variant delta:edge (nregs 3) (pre)   ; <-- SAME tag: needs #ordinal (D3)
    (driver (scan (rel 0) (r 0) (r 1)))
    (body (join3 (r 2) (old (rel 0) (1 0) 1 (1 0) (r 1) (r 2))
                        (old (rel 0) (0 1) 1 (0 1) (r 0) (r 2))))
    (head (emit (rel 0) (0 1) (r 1) (r 0)))))
  ...))
```

Body-constant rules produce exactly the doc's `pre` shape:
`(pre (let (r 0) (k 0))) (driver (probe (rel 0) (1 0) 1 (r 0) (r 1)))`.

## 4. Nonobvious findings to carry into the refactor

1. **VariantTag collision** (D3): same-source-rule semi-naive versions share
   the driver tag; identity needs the ordinal. Corollary: today's exact-once
   fires audit *aggregates* those versions per `(loc, label)`; the cross-tier
   instantiation-multiset gate must compare at the disaggregated
   RuleVariantId level, then aggregate for the existing goldens.
2. **The constants hash is keyed value→name**, not name→value
   (`globalize-constants`); the canonical pass inverts it. Constant globals
   are already content-derived symbols, so slot values are stable.
3. **Every stratum's decl list includes the side-channel error structs**
   (`error`, `malformed_deduction`, `div_by_zero`, ...). Binding frames
   therefore always contain those slots, and the two-class side-channel
   doctrine (incremental.md) shows up in every plan — the plan validator
   should treat them as a fixed prelude rather than per-program surprise.
4. **Rope strings break naive probe-only interning** (D7): long-string
   literals in queries need an arena dry-run probe or a v1 rejection.
5. **Parked interpreter continuations hold live btree iterators** — safe
   across mid-read suspension for the same reason native `(rt,ri)` parks are
   safe, invalid after any finalize; the existing copy-for-resume ownership
   rule covers this with no new mechanism (D11).
6. **Source-location strings must be module-relative** in `rule-meta`: the
   prototype's temp-file paths leaked into the plan and broke cross-run
   diffs until normalized. Golden plan files require repo-relative paths
   (RuleKey construction should never embed absolute paths).
7. **`pre` ops run before the driver** — a VM that assumes "driver binds
   regs 0..n first" mis-executes probe-driver rules (D14 removes the trap by
   preloading constants at frame setup).
8. **The `(paused ...)`/`(fixpoint ...)` message contract is load-bearing**:
   `runslog.rkt`'s driver loop and `tests/pause-tests.sh` parse the exact
   8-field shape (`daemon.h:1120-1132`). Protocol work must keep those
   replies byte-compatible until the driver migrates (dual-stack).
9. **Edit-stability, not run-stability, is the real canonicalization
   requirement** (D4): `set->list` order is already reproducible for
   identical input on one Racket build; what it lacks is stability under
   program *edits*, which is what durable RuleIds and plan goldens need.

## 5. File-by-file change map

Compiler (all under `compiler/`):

- **NEW `canonical-plan.rkt`** — the T1 pass: canonical crule sort, RuleId/
  VariantTag(+ordinal) assignment, register/slot allocation, deterministic
  serializer, plan goldens support. Prototype: `canon-proto.rkt`.
- **`ir-stack.rkt`** — add the kernel-plan grammar predicates beside the
  cprog ones (`ir-stack.rkt:239-441` is the source grammar the walker
  mirrors); no changes to existing levels.
- **`operationalization.rkt`** — intern the one residual `gensymb`
  (`latchk`, `operationalization.rkt:954`) deterministically; otherwise
  untouched (the pass consumes its output).
- **`compile.rkt`** — invoke the canonical pass per job after `build-cprog`;
  write/streams plans; the tier-designation classifier (§5.3 defaults) and
  tier-profile sidecar read/write; retire the text-hash manifest
  (`compile.rkt:210-234`) once RuleIds flow.
- **`emit-cpp.rkt`** — phase A (with T1): consume RuleId/VariantTag for
  `bumpFires` keys (`emit-cpp.rkt:912-922`) while still walking crules;
  phase B (with T4): consume the canonical plan's slots (relation strings
  out of generated code, `emit-cpp.rkt:201-408` and the `readrel` block
  `emit-cpp.rkt:1305-1322`); shard bucketing moves from emitted-text hash
  (`emit-cpp.rkt:1415-1432`) to canonical-variant hash.
- **`runslog.rkt` / `actions.rkt` / `session.rkt`** — dual-stack driver:
  send plan installs before artifacts; retire compiled action verbs one at a
  time against protocol equivalents; keep the `(paused ...)` parse compatible
  throughout (finding 8).

Daemon (all under `daemon/`):

- **`slogd.cpp`** — dispatcher: lines beginning `(` route to the command
  parser; bare lines stay plugin paths (`slogd.cpp:144-157` and the TCP twin);
  the pre-instantiated cursor/task factory ladders live here beside
  `makeIndex` (D12).
- **NEW `plan.h`** — S-expression plan parser, seal-time validation
  (slot/ABI/coverage/capability/entry-mode), the provisional builders.
- **NEW `interp.h`** — `PrefixCursor` family, `InterpReadTask`, the VM
  (section 3.1/3.2), bound sink tables (D13).
- **AS-BUILT `query.h` / `query.cpp`** — `QueryContext`, `scan-full` driver,
  capture-only `yield` pagination, rows/count/exists modes, cancellation,
  exact existing-index bind, and probe-only literal consumer (D7/D8). Catalog
  planning and protocol verbs remain.
- **`daemon.h`** — `installStratum(entry_mode)` unifying
  `beginStratum`/`beginStratumDelta`/upgrade (`daemon.h:200-315`, D10);
  attachment/load verbs; PauseToken/UpdateEpoch unification.
- **`database.h`** — `RUN_READ_COMPLETE` in the position enum
  (`database.h:1977-1981`) and the `ReadCompletion` gate branch
  (`database.h:6003-6024`); per-attempt fire vectors replacing the
  string-keyed map (`database.h:3942-3960`, D9); probe-only
  `probeString`/collection lookups beside `intern_string`/`encodeString`
  (`database.h:2552, 2610`).
- **`operators.h`** — unchanged semantics; the cursor layer wraps the same
  probe logic (`join_probe` `operators.h:97`, `Join3PrefixCursor`
  `operators.h:117`); head sinks reused as-is (`operators.h:520-616`).

Tests:

- `tests/unit/` canonical-plan battery: determinism (two-process diff), plan
  goldens for representative programs, VariantTag-ordinal uniqueness.
- [C++ interpreter operator tests](../tests/interp-operator-tests.cpp)
  following the `wcoj3-operator-tests.cpp` pattern (standalone build,
  differential vs a logical model), including pause/continuation/debug and
  the narrow seal/bind/real-index/real-emit vertical slice; retain the
  native-vs-VM differential as a permanent fixture.
- The `SLOG_OPT=interp` full-suite run (execution-tiers.md gate 12.3) and the
  disaggregated fires comparison (gate 12.2, finding 1).

## 6. Threshold hypotheses for the tier policy (to verify in T2/T3)

From section 1.1, pending `bench/` validation:

- interp-only defaults are safe wherever read cost ≤ ~1.3× matters less than
  seconds of clang — i.e. everything in §5.3's default list, with margin;
- promotion: compile when projected remaining interpreted time for the SCC
  exceeds ~3× the estimated O0 build cost (estimate from cluster count ×
  measured per-cluster O0 cost, both already tracked by the build cache);
- demotion: a kernel whose profile shows fixpoint reached before O0 would
  have attached in each of the last N sessions skips compilation.

## 7. Where to start T2 (recorded 2026-07-15)

Start with **T2-A, the normal-set operator kernel**, independently of the
RuleId/SCC refactor and before attempting the full canonical opcode language.
The permanent
[operator test](../tests/interp-operator-tests.cpp) is the executable
specification for this slice.

### T2-A0: land the conformance fixture

- Keep the test standalone against real daemon headers, like the WCOJ3 test.
- Preserve the logical-model differential, every-quantum continuation tests,
  internal-cursor pause, post-transition breakpoints, bounded proofs, real
  index/order probes, real emit dedup, and seal/bind rejection battery.
- Add it to the appropriate quick/operator test tier before extracting code,
  so every later lift is continuously differential against the prototype.

### T2-A1: extract the production-neutral interpreter core

- Create `daemon/interp.h` with immutable `DecodedRule`/`Op`, `CursorResult`,
  `WorkBudget`, `PrefixCursor`, explicit VM state, plan-sized registers/level
  stack, and a pinned program generation.
- Provide separately compiled fast and observed policies with shared semantic
  helpers. Keep candidate sink ports explicit and breakpoint stops
  post-transition. A zero effective event mask must select the fast policy.
- Move the test to instantiate this production core; do not integrate `Task`,
  protocol parsing, SCC policy, or hot swap in this sub-slice.

### T2-A2: seal and bind the narrow vertical vocabulary — engine path done

- Add the in-memory decoded/sealed/bound interfaces in `daemon/plan.h` (the T0
  dispatcher may parse into them later): constant preloads; delta-scan and
  delta-prefix-probe drivers; full-prefix set probes; `neq`; one `fire`; and
  ordinary set heads.
- Seal register dataflow, slot/arity/order ABI, requested indices, head ports,
  and the factory capability table. Bind direct `Relation*`, `Index**`, cursor
  factories, primitive pointers when introduced, and head sinks exactly once.
- Instantiate the `(A,K)` cursor/sink ladders out of line beside `makeIndex` in
  `slogd.cpp`. The 2/3-arity test ladder is only a prototype convenience;
  production coverage must match the daemon's supported arity range.
- Parse at least one real T1 `.plan` sidecar into this path as soon as the T0
  S-expression reader exists; until then, construct the same decoded object in
  C++ and keep parser concerns out of worker execution.

### T2-A3: attach one real `InterpReadTask` — done

- Construct one task per `(RuleVariant, bucket)` and run it through the existing
  read scheduler, `pushPaused`, deadline/stop plumbing, and write/intern phases.
- Preserve the distinct driver partitions: scan `read_buckets`, partially
  bound probe by first-free-column hash, fully bound probe as one task.
- Use the existing emit family through attempt/task-owned bound sink batches;
  do not allocate diagnostic `vector<vector<u64>>` candidates in the hot path.
  Keep enough attempt ownership that T5 settle and T6 discard/replay do not
  require changing the opcode or sink ABI.
- First admission gate: one representative recursive normal-set program has
  identical per-iteration deltas and disaggregated RuleVariant fire counts
  under interpreter and O0/O2.

### T2-B: expand vocabulary only after T2-A is green

Add in conformance-sized groups: `once`/`seeded` and K=0 scans; old/new and
absence cursors; map/lattice probes; primitive/`letp`/type operations; join3;
then temp/struct/lattice/count sinks and declaration-built write/intern tasks.
Groups (i) old/new/absence, (ii) primitives/types, (iii) join3, and (iv)
map/lattice probes are landed; ordinary full-view K=0 landed post-freeze on
2026-07-17; normal `once`/`seeded`, temp, and struct conformance landed on
2026-07-19; normal lattice sinks, declaration-built tasks, and the
compiler-driven interpreter-only route landed later that day. The interpreter
core is frozen as of 2026-07-16; every post-freeze group stayed within its
registration, binding, and sink extension seams.

Do **not** pull T3 tier scheduling, T5 watch-settle UI, or T6 transactional
mid-read replacement into T2-A. The kernel must preserve their seams—observed
policy, lazy proof views, attempt-local sink identity, pinned generations—but
T2 first ships boundary-safe interpreted execution. T0 protocol/identity work
can proceed in parallel and meet T2 at the decoded/sealed builder interface.
