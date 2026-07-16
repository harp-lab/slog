# Interpreter core contract: freeze list, trigger, extension seams

**Status:** design contract (2026-07-15); **core extracted at T2-A1
(2026-07-15): `daemon/interp.h` now holds the production core in
namespace `slog::interp`, the fixture instantiates it, and the three
fixture deviations below are resolved** (Event carries the D3 variant
ordinal; Event payloads are bounded `TupleView`s into attempt-owned
scratch, valid for the observer callback; the cursor accessor is
`current()` returning a non-owning `TupleView`). Fixture line citations
below refer to the pre-extraction fixture as of commit `fb9bc77`; the
behaviors are unchanged and remain covered by the same tests. Decisions
here were ratified 2026-07-15 with the progressive fork (roadmap.md
§3.1); this file consolidates them and does not reopen them. `execution-tiers.md` (§4, §6, §12) and `execution-tiers-impl.md`
(§0, D1–D18, §7) remain normative for content;
[tests/interp-operator-tests.cpp](../tests/interp-operator-tests.cpp)
is the **authoritative executable specification** for every frozen
behavior below and is cited by name and line throughout ("the
fixture"). The convention follows `m4s-contract.md` and
`m5-contract.md`: everything not explicitly frozen is the T2-A1
implementer's choice, and everything not explicitly seamed is core.

This is the document that makes the ratified fork safe: the interpreter
partitions three ways (monotone core = trunk, frozen; counted =
thread 0; query = thread 1), and the partition only protects the
threads if the core's interfaces stop moving at a named moment and the
two extension seams are pinned before anyone builds on them.

## What freezes and when

**The trigger is deliberately NOT the full T2-B monotone suite.** The
core freezes when three things are green:

1. **T2-A's first admission gate** (impl §7 T2-A3; tiers §12 gates
   1–2): one representative recursive normal-set program produces
   identical per-iteration content deltas and identical
   **disaggregated** RuleVariant fire counts under the interpreter and
   under O0/O2.
2. **T2-B conformance group (i): old/new and absence cursors** — the
   first vocabulary added *without* touching the state machine. This
   group proves the cursor seam: view-selecting cursors (`join-old` /
   `join-new` dord exclusion) and open-only absence probes land as
   cursor-factory registrations plus seal capability entries, nothing
   else.
3. **T2-B conformance group (ii): prims / `letp` / `tycheck`** — the
   first non-cursor vocabulary. This group proves the opcode seam:
   bound `PrimFn` dispatch and row-abandoning guard arms land as new
   ops in reserved opcode space, with backtracking reusing the frozen
   `advance` arm.
4. **T2-B conformance group (iii): the real `Join3PrefixCursor`
   erasure** — pulled inside the pre-freeze set (conservative trigger,
   ratified 2026-07-15): whether the cursor interface needs
   `seek`/`advance_past` (tiers §4.1's sketch carries them; the frozen
   `PrefixCursor` does not) is resolved *before* the freeze, not by a
   post-freeze joint review.
5. **T2-B conformance group (iv): map/lattice probes** —
   `BTreeMapIndex` binds its payload last; the other named interface
   risk, likewise resolved pre-freeze.

From that point, roadmap §3.1 criterion 5 applies: **post-freeze
changes to the core's dispatch, vocabulary layout, or cursor layer
require joint review.** The remaining T2-B groups (once/seeded and K=0
scans, temp/struct/lattice/count sinks, declaration-built write/intern
tasks) land as trunk chores *under* the frozen interfaces, each with
its delta/fires conformance tests — all of them registration-and-sink
additions by design, which is why they can safely follow the freeze.
Criterion 1's full-suite `SLOG_OPT=interp` run completes during the
fork rather than gating it.

**Rationale.** The design risk this freeze would normally guard against
was already absorbed: D1–D18 were prototyped against real daemon
headers, the throughput question is measured (1.2–1.3× native on
realistic joins, impl §1.1), and the fixture is an executable spec
covering every quantum from 1 to 31, intra-match cursor pauses, a
96-level stack, all eight event ports, and the seal/bind rejection
battery. Groups (i) and (ii) are chosen because together they exercise
both registration tables — exactly the seams thread 0 and thread 1
will extend; groups (iii) and (iv) are the two constructs that could
plausibly force a cursor-interface change, pulled inside the pre-freeze
set by the conservative-trigger ratification of 2026-07-15 so the
freeze list is complete when declared. The residual risk after that is
only the unnamed unknown, and every post-freeze group is a
registration-and-sink addition by design; if one nevertheless forces
an interface change it is handled by joint review, not by declaring
the freeze void.

## The frozen interfaces

Post-freeze, each item below changes only under joint review. Citations
are to the fixture unless another file is named.

### Cursors

**`PrefixCursor`** (`interp-operator-tests.cpp:49-56`): `clone()`,
`open(const u64* regs)`, `next(u64* regs, WorkBudget&)`, and the
current-row view. Frozen properties:

- **Tri-state `next`** returning **`CursorResult`**
  `{ match | exhausted | paused }` (line 36, D1). A boolean is
  insufficient because a join3 intersection can exhaust a work slice
  before either finding a match or proving exhaustion; `SlowCursor`
  (lines 116–164) is the executable witness, and
  `test_cursor_internal_pause_and_continuation_copy` (lines 1213–1262)
  proves repeated intra-match pauses with continuation cloning.
- **Positioned-until-next-call**: a match remains positioned on the
  underlying iterator until the following `next` advances it
  (`ProbeCursor::positioned`, lines 69, 90–104), so debug capture reads
  the current premise lazily with **no copy on the unobserved path**;
  unpositioned reads return nothing (lines 106–110). The fixture spells
  the accessor `current_row()` (owning copy, observed path only); the
  production core may spell it `current()` returning a non-owning
  `TupleView` (impl §3.2) — the *semantics* are the freeze, the
  spelling is T2-A1's.
- A pause is returned **before** output registers are written (line
  100): a paused cursor has committed nothing.

### Budget and cadence

**`WorkBudget`** (lines 38–47): a counted `tick()`; cursors consume
ticks inside their search loops and return `paused` on expiry. The
production deadline cadence is D2's: **poll every 128 driver tuples**
(the `read_delta_sliced` cadence) plus inside long cursor loops. The
fixture generalizes the cadence and proves correctness at *every*
budget — all transition quanta 1..31 with a continuation at every
boundary (`test_uninterrupted_and_every_quantum`, lines 1182–1211) — so
128 is a performance choice inside a correctness-guaranteed family, not
a semantic constant.

### Op layout and constant preloads

**`OpK` / `Op` / `Program`** (lines 166–181): fixed small-struct ops in
a flat vector, switch-dispatched. Frozen doctrine (D14): **ops carry
pre-resolved operands** — cursor/sink indices and register numbers,
never names — and **constants are preloaded into the register file once
at frame setup**, not per tuple (`Machine` constructor `preloads`,
lines 446, 456; plan-level `RulePlan::preloads`, line 763; exercised
with a probe driver at lines 1500–1505). Corollary already trapped
once: `pre` ops run *before* the driver, so driver columns map through
an explicit register list (`load_driver_regs`, lines 297–304) and are
not assumed to be registers 0..n (impl finding 7). The numeric values
of `OpK` members are **not** frozen — see the reservation section.

### The VM state machine

**`MachineState`** `{ need_driver | dispatch | first_cursor_match |
advance | done }` (lines 273–279) and **`StopReason`**
`{ complete | quantum | cursor | breakpoint }` (line 280). Frozen
properties (D2):

- **Plan-sized register file and level stack** — `regs` sized from the
  plan's `nregs` (line 449), `levels` a growable vector (line 291).
  Real cached plans observed during P3 reach **85 cursor levels and 251
  registers**; the fixture exercises **96 levels**
  (`test_plan_sized_deep_cursor_stack`, lines 1292–1323) precisely so
  the design sketch's illustrative `level_ip[8]` can never become
  implementation.
- Backtracking is an array operation on the level stack (`backtrack`,
  lines 314–321); mid-nest pausing parks plain state, no C++ stack
  capture.
- **A cursor pause commits nothing; every committed semantic transition
  completes before any debug stop** (comment at lines 322–323; the
  `transition` loop, lines 324–438).

### Bound sink ports

**Head selection is never reconstructed from candidate order** (D13).
Every emit opcode carries an explicit bound sink port (the emit arms
reuse `Op::cursor` as the port, lines 416–433; `Event::port`, line
201), and every attempt-local candidate retains it
(`Attempt::output_sinks`, line 267; per-port routing in
`BoundRule::apply`, lines 1124–1137). The multi-head test asserts
per-sink candidate counts with one `fire` per satisfying body (lines
1480–1481), and the nested-ternary test asserts port stability under
breakpoints (lines 1632–1634). Sinks **erase the existing emit
family** — the fixture's `emit_rows` calls the real `emit<A>` templates
against real indices with real dedup (lines 1069–1091, exercised by a
pre-inserted duplicate at line 1443); there is no second emit
implementation (D13, `operators.h:520-616`).

### The fast/observed policy split

**Ordinary execution and rich observation are separately compiled
loops** (§1.3): the micro-stepped observed loop (`Machine::run` over
`transition`, lines 474–485) pays for post-transition event
construction, breakpoints, and proof capture; the fast loop
(`Machine::run_fast`, lines 491–618, doctrine comment at 487–490) polls
a cheap transition counter and saves live state only on expiry. **An
effective event mask of zero selects the fast loop**; the executable
form of that rule is `test_zero_mask_observer_has_zero_callbacks`
(lines 1399–1416) — an attached observer with mask 0 receives zero
callbacks. Measured stress ceiling (dispatch-dominated, impl §1.3):
fast VM 2.2–2.6× fused native, micro-stepped observed 3.7–5.0× —
versus 1.2–1.3× on realistic joins (§1.1). Merging the loops would
silently tax the default tier; the split is frozen.

### Breakpoints and proofs

**Debug events are post-transition and proof payloads are lazy and
bounded** (D15). The eight stable ports are `EventK` `{ driver,
probe_match, probe_miss, probe_exhausted, guard_pass, guard_fail,
instantiation, emit }` (lines 183–192), mask-gated per event
(`event_bit` line 194, `debug_event` lines 306–312). Events carry rule
identity, source op index, bound port, and the emitted tuple inline
(lines 196–204); driver/premise views materialize only on observer
request, reading positioned cursors (`DebugView::proof`, lines
212–227); proof counts are bounded explicitly
(`RecordingDebug::proof_limit` / `omitted_proofs`, lines 238–261,
asserted at lines 1386–1387). A breakpoint observes state *after* the
transition committed into the read attempt, so resume never retriggers
it (`test_breakpoints_are_post_transition_and_non_retriggering`, lines
1325–1364; an emit breakpoint stops after exactly one newly committed
candidate, lines 1349–1352).

### Pinned generations and park/copy-for-resume

**A parked task pins the immutable decoded program generation** (D11):
`Machine` holds `shared_ptr<const Program>` and shared immutable driver
rows (lines 284–285); `continuation()` (lines 469–472) clones registers,
levels, and **cursors with live iterator state** (copy constructor,
lines 459–467). `test_parked_task_pins_immutable_program` (lines
1275–1290) runs a continuation after its install-side program object is
gone. Parked continuations holding live btree iterators are safe across
mid-read suspension for exactly the reason native `(rt, ri)` parks are
safe — indices are immutable until a finalize — and must be discarded
at any finalize; the existing copy-for-resume ownership rule covers
this with no new mechanism (impl finding 5).

### Driver partitions

**The three driver partition contracts stay distinct** (D17), sharing
no inferred generic "bucket" rule:

| driver | partition | fixture |
|---|---|---|
| delta scan | the relation's even round-robin `read_buckets`; bucket numbers are **not** tuple hashes | `driver_rows` scan arm over `getReadBucket`, lines 1008–1016 |
| partially bound probe | one shared prefix probe, matches partitioned by `buckethash` of the first freshly bound column | lines 1026–1053 |
| fully bound probe | **one** atomic task, not 32 duplicates | `task_count()`, lines 1105–1110; asserted at line 1536 |

Seal-time capability doctrine rides with this (D16): `supports_probe`
(lines 824–827) is deliberately the same table as the bind-time factory
ladder, so a syntactically valid plan can never discover a
factory-ladder miss on a worker thread; the rejection battery is
`test_seal_and_binding_rejections` (lines 1659–1718).

### Fixture deviations to resolve at T2-A1 (not frozen)

Three places where the fixture's spelling is a prototype convenience the
lift must NOT freeze (verified 2026-07-15):

1. **`Event` identity is incomplete**: the fixture's `Event` carries
   `rule_id` only (line 198) and `Program::variant` (line 178) is never
   propagated into events. Production events carry the **D3 RuleVariant
   ordinal** — conformance obligation 2 (disaggregated multiset
   equality) is impossible to observe per-event without it.
2. **`Event`'s inline `std::array<u64, 3>` tuple** (line 202) is a
   3-arity prototype shortcut; production events carry a bounded view
   consistent with D15's lazy payload doctrine, not a fixed inline
   array.
3. **`current_row()` returns an owning copy**; production spells it
   `current()` returning a non-owning `TupleView` (impl §3.2), as
   already noted under Cursors — semantics frozen, spelling not.

## Extension seams

Two seams, two owners (roadmap §7). Each thread extends the core only
through its own files and its own registration-table ranges. **Neither
thread touches the other's registration tables, and any change to core
dispatch, the frozen interfaces above, or the shared tables' core
ranges is joint review.**

### Thread 0 — semantics (counted/maintenance)

Owns: flavored opcodes, `counts.h` folds, maintenance sinks, route
admission, recount. All of it lives in **separate files and separate
registration tables** from the core — flavored ops register into the
thread-0 opcode range, flavored cursors and sinks into the thread-0
regions of the factory tables. The counted interpreter is admissible
only under tiers §4.3: it enumerates the exact instantiation multiset
native code would (no existence shortcuts; counted plans arrive with
semijoin filters disabled and the interpreter respects the plan
attribute rather than re-optimizing), and it drives the identical
shared sidecar fold (`cnt_apply` / `cnt_try_apply` in
`daemon/counts.h`) and transition tasks — never a re-implementation.

### Thread 1 — interaction (read-only queries)

Owns: `daemon/query.h` — the query drivers, sinks, and context. Pinned
shape (D8): **`QueryContext` is a second, smaller RunState-shaped
context** with its own task cursor, its own budget/deadline, and its
own output pages; it **never touches `RunState::paused_tasks`** or
phase cursors. Admission only at **quiescent-master states**: daemon
idle, `RUN_AT_BOUNDARY`, a mid-read suspension, or a
`RUN_READ_COMPLETE` pre-commit pause — states where master indices are
immutable. v1 runs **one query at a time on the main thread** (the
shipped suspend already guarantees the worker region has exited).

Thread-1 vocabulary: the `scan-full` driver, the `yield` sink and
pagination, and the **probe-only interner entry points** (D7). The
probe-only hole is pinned: short strings need only a non-allocating
`InternTable` lookup, but `encodeString` for longer content builds rope
nodes in the sequence arena — an allocation a read-only query must not
perform. **v1 rejects string literals longer than `SEQ_BLEAF_MAX` with
a structured error, and collection literals likewise**, pending an
arena dry-run probe that computes would-be node keys in scratch memory.

## Opcode and registration-table reservations

The core monotone vocabulary, thread-0 flavored ops, and thread-1 query
ops each get a **reserved contiguous range** so registrations never
collide:

```text
core monotone      0–95     frozen at the trigger; joint review after
thread 0 flavored  96–159   counted/maintenance ops
thread 1 query     160–191  scan-full / yield / probe-only ops
```

These numerals are a proposal: **the exact boundaries are the T2-A1
implementer's choice — the pin is the reservation in three disjoint
contiguous ranges**, sized generously enough that neither thread ever
petitions for core space. The same doctrine applies to the
**cursor-factory and sink-factory registration tables** (D12's
out-of-line ladders in `slogd.cpp`): three disjoint regions, core
region frozen, each thread registering only in its own. A registration
outside one's own range, or a collision, is an install-time fatal, not
a silent overwrite.

## Conformance obligations

Every extension — both threads, and the trunk's remaining T2-B groups —
inherits:

1. **Per-iteration content-delta equality** against native where native
   exists, after every iteration, not merely the same final CSV (tiers
   §12 gate 1).
2. **Disaggregated instantiation-multiset equality**: per-RuleVariantId
   fire counts match native exactly. Compare **disaggregated first,
   then aggregate** for the legacy `$stat_fires` goldens — today's
   exact-once audit aggregates same-driver semi-naive versions per
   `(loc, base-tag)`, which is fine for stats and fatal for executor
   replacement (impl finding 1, D3; tiers §12 gate 2).
3. **Counted extensions** additionally prove **maintained-sidecar
   equality against forced recounts** across the whole existing
   incremental battery under `SLOG_OPT=interp` (tiers §4.3; roadmap
   §4.1).
4. **Query extensions** prove the **Q1 hygiene gate**: after any query
   — including failed, cancelled, and paused-state queries — the
   database is **bit-identical**: master indices, sidecars, counts,
   stats, and all interner heaps (tiers §12 gate 4).

And one standing fixture obligation: the fixture itself is permanent.
It was wired into `tests/run-all.sh`'s quick tier on 2026-07-15 (the
`interp` harness; note it builds with `-fopenmp` because instantiating
`Relation::sendBatch` references `omp_get_thread_num` — a flag every
future header-level lift inherits). **Every T2 lift keeps it green and
extends it** — T2-A1 re-points it at the extracted production core, and
each vocabulary group adds its differential cases. It is the seed of
roadmap §4.1's permanent dual-executor differential.

## Non-goals and preserved seams

T2-A ships boundary-safe interpreted execution and nothing else (impl
§7). Explicitly out of scope:

- **no T3 tier scheduling** — no promotion budgets, profile sidecars,
  or core arbiter;
- **no T5 watch-settle UI** — level-1 provenance watches wait for the
  sync gate;
- **no T6 transactional mid-read replacement** — cross-tier takeover
  restarts from immutable input rather than translating live iterators.

But the freeze list **deliberately preserves their seams** (D18), so
all three remain buildable without opcode or sink ABI changes: the
separately compiled observed policy and lazy proof views are T5's
substrate; attempt-local sink identity — candidates, batches, and fire
counters owned by the attempt, discardable and replayable
(`Attempt`, lines 263–271; the modeled abandoned-attempt takeover at
lines 1600–1617) — is T6's substrate; pinned program generations are
what tier swap and hot upgrade retire safely. Candidate, accepted
insert, and committed delta stay distinct event levels: a satisfying
body fires once, may produce several head candidates, and an existing
master row can reject a candidate at the shared sink — trace may report
the attempt, but settlement sees only accepted changes (D18).
