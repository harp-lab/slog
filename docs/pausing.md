# Pausable Fixpoints: Bounded Work Units, Suspendable Rules, and a Client-Driven Run Protocol

*Design + sprint plan, 2026-07-06. Status: **implemented** (2026-07-06). The
suspend/resume core, sliced scan driver, `continueRun` API, driver loops,
actions, and SCC/rule ids landed together and pass a byte-identical
pathological-budget test. See "Implementation notes" at the end for the two
scoped-down pieces (probe/once slicing, and wiring the rule id into
`malformed_deduction`) whose seams are cut but whose full form is deferred.*

*2026-07-14: partially superseded by
[execution-tiers.md](execution-tiers.md) — the §6 text-hash rule id / ordinal
SCC id scheme is replaced by RuleKey/RuleId/SccInstanceKey, the §8(a) JIT'd
point-query direction is replaced by interpreted read-only QueryPlans, and the
§8(b) seams (scan-full driver, second RunState context, `bind(db)`) are
consumed by that design. The shipped suspend/resume mechanics described here
remain current.*

## 1. Goal

Today, running a stratum blocks the daemon until that stratum's full fixpoint,
however long that takes and however much memory it eats. This sprint inverts
control: the daemon only ever performs a **bounded unit of work** — bounded in
wall time and in memory growth — and then reports back either `(fixpoint ...)`
or `(paused ...)`. The client (driver, REPL, front end) polls "continue" until
fixpoint, and between polls it can query sizes, look up tuples, report live
progress, or decide to stop a runaway program. The daemon's job is to do a
coarse chunk of work and to pause **only in states it can resume exactly**.

Three capabilities compose to make this work:

1. **Sliceable rules**: any read-phase task can pause itself mid-scan (~0.5s
   slices), remember its position, and requeue a continuation.
2. **Suspendable fixpoints**: the whole iteration loop can stop cleanly at an
   iteration boundary *or mid-read-phase*, park its state in memory, and
   resume on a later call.
3. **A continue-fixpoint API**: `Daemon::continueRun(budget)` replaces the
   blocking run as the unit the generated plugins request; budgets are
   client-tunable with good defaults.

Plus supporting infrastructure: integer ids for rules and SCCs (usable in
`(error ...)` facts, `(paused ...)` messages, and a future stats API), and a
uniform driver protocol.

## 2. Where we start: the machinery today

- The compiler (stratify.rkt) Tarjan-SCCs the relation-dependency graph and
  merges same-level (independent) SCCs into **strata**; one `.so` per stratum.
  A stratum is named by its 8-hex cache hash. Rules have no identity after
  compilation (anonymous generated `ReadTask*` classes).
- Each generated plugin does: `s = d->beginStratum(name)` (which performs the
  deferred between-strata reload), registers relations/indices/tasks, then
  `d->push(s); d->run();`. `Daemon::run()` (daemon.h) loops over unrun
  pipeline strata calling `Database::runStratum`, **blocking to full fixpoint**,
  then emits `(fixpoint <name> <iters> <ms>)`. There is no way to run part of
  a fixpoint, no SCC ids, and no way to interrupt.
- `runStratum` (database.h) spins an OpenMP region; each iteration is:
  iteration barrier → **write** phase (insert last delta into all indices) →
  **read** phase (rule tasks; output to per-thread send shards; the read
  barrier's completion unions shards into the next delta) → **intern** phase
  (dedup new delta against master indices) → parallel reorg (re-bucketize
  delta) → repeat while any relation grew. Workers claim tasks via an atomic
  `fetch_add` cursor over the stratum's `once[phase]` / `every[phase]`
  vectors. A task's `work()` is uninterruptible.
- Strata stay resident after running (the incremental seam), but their tasks'
  `Index**` bindings dangle after the next reload — re-running an old stratum
  would need a re-binding pass that does not exist yet.

**The property everything below leans on:** during the read phase, nothing a
read task consumes is mutated. Indices are written only in the write/intern
phases; the delta and its bucketized views stay valid until the read barrier's
`finalizeAll`; rule output goes only into fresh send batches. So the read
phase is suspendable *by construction* — stop handing out tasks, remember
positions, and everything a resumed task needs is still sitting there. And
because the daemon is idle between plugin calls, suspended state simply lives
in the existing `Database`/`Stratum` objects across calls. No serialization.

## 3. Layer A — sliceable read tasks

### Task interface and the copy-for-resume model

`Task::work()` becomes `bool work()` — true means finished, false means the
task paused itself. (Daemon header changes are in every `.so` cache key, so
all cached plugins rebuild automatically; no stale-plugin hazard.)

**The resumption point is remembered per rule, and there are no separate
"resume variants" of rules.** There is one generated task class per rule
pipeline, and at first run a task is simply a task resuming at the origin —
(0,0), or whatever the start point is for its driver shape. When a running
task hits its slice deadline, it **constructs a copy of itself carrying the
pause position and pushes that copy onto the current phase's queue**, then
returns. The canonical task objects in `once[]`/`every[]` are never mutated —
they always start from the origin (which is exactly what the next iteration
needs) — and the parked copies are one-shot continuations owned by the queue
(deleted when they complete or when the stratum tears down).

### Resume state per driver shape

Pause granularity is **the outermost loop only** (decided for v1). Inner join
levels always run to completion for the current outer element.

- `scan` driver (`read_delta` — every recursive rule): position is two
  integers `(thread t, ref index i)` into the bucketized delta view. Exact
  and trivial.
- `probe` driver, and `once` rules whose first op is `join_all`/`join_probe`:
  position is the **last-processed match tuple** (`std::array<u64,A>`).
  Because indices are immutable and sorted for the whole read phase, resuming
  is `lower_bound(saved_key)` + skip-the-equal-one. Deterministic and exact.
- Fact rules / fully-computed `once` rules: no slicing (they are microscopic).

A single source tuple with a pathologically skewed inner join can overshoot
its slice; we accept that in v1. Two mitigations make it mostly harmless: the
memory budget still trips mid-tuple (emission is counted continuously), and
blowups that matter are blowups that emit. Deeper (per-join-level)
continuations are a well-understood v2 — the same immutability argument makes
a saved key per level valid — but the codegen surgery is not worth it until
profiling shows real overshoots.

### The slice check: no cleverness required

`std::chrono::steady_clock::now()` on Linux is a vDSO call (~20–25ns, no
syscall, no shared state, no contention). Each task checks every 128–256
outer tuples via a thread-local counter mask — well under a nanosecond per
tuple amortized. No ticker thread, no stored unix time (monotonic clock
internally; unix ms only in messages, since wall time jumps under NTP).

The check compares against a slice deadline of
`min(task_start + slice_ms, global_deadline)` — which automatically
implements "per-task timeout that shrinks as the overall budget nears" — and
also reads one relaxed atomic `stop_requested` flag so a memory trip pauses
tasks immediately.

### Memory proxy: count emitted words at the choke point

`Relation::sendBatch` is the single choke point for all produced tuples: one
`fetch_add` of the batch's word count per ~4k-word flush (negligible).
`words × 8` is the growth estimate. Conveniently, `emit()` already dedups
against the head index before batching, so this counter is close to *true*
growth — the classic "transitive closure re-derives everything each
iteration" noise mostly doesn't inflate it. `emit_temp`/`emit_struct` don't
pre-dedup, so there it over-estimates, which is the safe direction for an
explosion guard.

### Requeueing mechanics

The dispatcher today is an atomic cursor over fixed vectors — nothing can be
pushed. Add a small mutex-protected `paused_tasks` vector per phase (pauses
happen ~2/sec/thread; contention is irrelevant) with its own claim cursor.
Claim order: paused continuations first, then the main cursor. Termination is
safe because only a worker that just pushed a continuation can leave work
stranded, and that worker always re-enters the claim loop.

## 4. Layer B — suspending and resuming the fixpoint loop

Split `runStratum` into `startStratum` (current initialization) and
`continueStratum(Budget)`, which spins the parallel region and returns one of
three outcomes:

1. **Fixpoint reached** — as today.
2. **Paused at an iteration boundary** — the sentinel checks the global
   budget after each intern+reorg; if blown, all threads exit the region
   cleanly. The cleanest suspend state.
3. **Suspended mid-read-phase** — when `stop_requested` fires (global
   deadline passed, or emitted words × 8 exceed the memory budget): workers
   stop claiming; in-flight tasks pause at their next slice check and park
   their continuation copies; everyone rendezvouses at the read barrier,
   whose completion **skips `finalizeAll`**, and the sentinel skips the
   cursor reset. Then all threads exit the region.

**The key correctness point:** never finalize a partial read phase.
Finalizing a half-read delta and moving on would silently drop the unrun
rules' derivations from this delta — a semi-naive soundness violation. On
suspend, the current delta, its bucketized views, and the delta indices all
stay alive (they are untouched until the finalize we skipped), so resume
re-enters the read phase with the existing cursor position plus the parked
continuations, **skipping the iteration barrier and write phase** for the
in-progress iteration.

The current position is encoded explicitly as a small enum —
`{fresh, at_iteration_boundary, mid_read}` — inside a new `RunState` struct
(see §8) rather than inferred, and `runLoop` dispatches on it at entry
(mid-read resume also skips the sentinel's iteration-0 promote/reorg).

**Write and intern phases never check the budget.** They are linear in the
delta the read phase produced, and the read-phase memory budget bounds that
delta; a budget that expires during write/intern takes effect at the next
iteration boundary. Internal strata (the reload's `runStratum(&s,false)`,
disk ingestion) run unbudgeted and must never inherit a stop flag.

### A suspended database is a consistent snapshot

Mid-read, the master indices hold everything derived through the current
iteration's write phase — a coherent "everything derived so far" set. So
`(sizes)`, CSV dumps, `(write-db ...)`, and point-query actions are all safe
and meaningful against a suspended daemon. This is what makes the
poll-and-inspect workflow real, with zero extra machinery.

### Guardrails

While suspended, the `Daemon` refuses anything that would reload or clear
indices — `beginStratum` (it triggers the deferred reload!), `open`,
`import`, `loadRelation`/`refresh` — with a clear `(error suspended ...)`.
Read-only actions remain allowed. Without this, sending the next stratum
mid-suspend would dangle every parked task's index bindings.

## 5. Layer C — the Daemon API and messages

```cpp
struct RunBudget {
  u64 max_ms    = 8000;   // wall budget for this call
  u64 slice_ms  = 500;    // per-task slice
  u64 mem_bytes = 0;      // 0 = auto: max(100MB, 2% of RSS at call start)
};
void Daemon::continueRun(RunBudget b = {});  // one bounded unit of work
// run() remains as the blocking loop-of-continueRun, for internal use.
```

`continueRun` picks up `pipeline[next_unrun]`, starts or resumes it, and
emits exactly one of:

```
(fixpoint <scc-id> <name> <iters> <ms>)
(paused <scc-id> <name> <iter> <phase> <new-tuples> <ms-this-call> <ms-total> <reason>)
```

- `<phase>` is `iter` (clean boundary) or `read` (mid-phase suspend).
- `<reason>` is `time` or `memory`.
- `<new-tuples>` is post-dedup growth since the stratum started: exact
  (tuple-count diff) at boundaries, emitted-words estimate mid-read.
- Memory baseline: one read of `/proc/self/statm` per call (the honest
  number; composes with the existing `SLOG_MEM_MAX=4G` systemd cap — defaults
  keep baseline + budget comfortably under it). Growth during the call is
  tracked by the emitted-words counter.

**Idempotence:** `continueRun` with nothing unrun and nothing suspended
re-emits the last stratum's `(fixpoint ...)` message verbatim (stats cached
on the Stratum). A client's "continue until fixpoint" loop therefore
terminates on the same condition with no special cases; demanding a continue
at the final fixpoint just reconfirms it. An entirely empty pipeline answers
`(idle)`.

**Generated plugins switch from `d->run()` to `d->push(s);
d->continueRun();`** — the daemon does one coarse unit per plugin; the client
drives. A cached action plugin `(continue [ms] [mem])` (one `.so`, reused for
every poll) is what clients stream after each `(paused ...)`.

Example session, driver's-eye view:

```
→ build/000878c0.so                        ; stratum 3 registers itself + first unit
← (paused 3 "000878c0" 17 read 2113480 8003 8003 time)
→ build/continue-a1b2.so
← (paused 3 "000878c0" 41 iter 5240122 8001 16004 time)
→ build/sizes-....so                       ; legal against the suspended DB
← (relation_size path 5240122) ...
→ build/continue-a1b2.so
← (fixpoint 3 "000878c0" 63 4211.02)
→ build/00fc9c52.so                        ; only now the next stratum
```

## 6. Rule and SCC integer ids

One **program-wide rule id** suffices (no SCC+rule compound key); the manifest
maps id → SCC/source. But how ids are chosen matters, because they are baked
into generated C++ that is content-hashed for the `.so` cache:

- Sequential numbering across the program would couple every stratum's
  generated source to the whole program's rule list — editing one rule would
  shift later ids and invalidate every downstream cached `.so` (a real JIT
  latency regression). Same trap for SCC ids as baked-in pipeline positions.
- **Rule id = 31-bit hash of the rule's source text** (not its location —
  line shifts would churn ids), with an occurrence counter disambiguating
  identical duplicate rules. Fits a NaN-boxed s32. Editing a rule perturbs
  only its own stratum's cache. Ids are assigned pre-or-split so all
  split/staged descendants of one source rule share its id.
- **SCC id = assigned by the daemon at push time** (its pipeline position),
  never baked into the `.so`. The daemon knows the order; the compiler's
  sidecar manifest lists strata in the same order, so the front end
  correlates id ↔ hash-name ↔ source trivially.
- `malformed_deduction` rows carry the **int rule id** in place of the
  current source-location value; the front end resolves and diagnoses from
  the manifest.
- The compiler writes a sidecar manifest next to the build artifacts
  (`build/<hash>.meta`): rule id → source text/location, strata in pipeline
  order. The daemon stays dumb about source text.
- This also positions the deferred **stats API**: generated tasks already
  carry their rule id, so per-rule counters (tuples in/out, time) can later
  be plain task members aggregated by id at report time — zero contention.

## 7. Driver and protocol changes (uniform for batch and interactive)

All runs — including plain batch `slog.rkt` runs — go through the bounded
continue loop; for now the driver simply always continues until fixpoint
(easy to refine later into policies: growth alarms, user prompts, live
dashboards).

- `runslog.rkt slog-run-file` becomes response-driven: send stratum k's
  `.so`, then read daemon lines — `(paused ...)` → send the continue action;
  `(fixpoint ...)` for k → proceed to stratum k+1; `(error ...)` → abort.
  A small Racket reader thread drains stdout continuously and posts events
  on an async channel; the main thread compiles and sends. Continuous
  draining is *required*, not just nice — chatty paused messages would
  otherwise eventually fill the pipe and deadlock.
- The client always knows which fixpoint it is waiting for: it compiled the
  program, knows the stratum list, and sends each `.so` itself. It must not
  send stratum k+1 until k's fixpoint (the guardrail would refuse it anyway).
- **Compilation pipelining is preserved.** Verified: compile.rkt runs the
  Racket passes for stratum k+1 in a chain of futures while k is handled, and
  the clang compile (`finish-jit`) runs on the driver's main thread right
  after k's path is sent — clang for k+1 overlaps the daemon executing k, in
  separate processes. The new loop keeps this: force `finish-jit` for k+1
  while polling k's continue loop. The only new constraint — don't *send*
  k+1 until k fixpoints — doesn't delay compiling it.
- `daemon/slogd.rkt` (TCP console) gets the same loop and is where live
  progress reporting shines.

## 8. Querying while paused: assessment and what we anticipate now

A suspended database is a consistent snapshot and the worker region has
exited, so the daemon's main thread has exclusive access — read-only plugins
are completely safe. Three tiers:

**(a) JIT'd point-query actions — do now (one ships this sprint).** The
existing actions.rkt pattern: a tiny cached `.so` that walks an index and
emits results, e.g. `(lookup rel v1 v2 ...)` → probe the master index, emit
`(found rel 0|1)` or matching rows. The path-only protocol has no argument
channel, so query values are baked into the plugin source — a *new* query
value costs one ~1–3s clang. But the motivating workflow — "poll whether
tuple X has appeared yet between pauses" — repeats the *same* query, compiled
once and free thereafter. Adequate now; an args side-channel is easy later
work if ad-hoc querying gets hot.

**(b) Full query programs (rules/SCCs) against the paused DB in-daemon —
defer, but pre-carve the seams.** Blocked today by the reload discipline
(`beginStratum` dumps and clears all indices, destroying parked bindings and
the staged delta) and by the run machinery being a global singleton on
`Database`. Needs three things eventually: a task **re-bind** pass, a
**scan-full-index driver mode** (read iteration-0 input from master indices
without the global reload), and per-run-context state. The first two are the
exact seams selective SCC re-runs and incremental recomputation also need.
**Anticipated in this sprint at near-zero cost:** (1) all new run state
(cursors, suspend position, paused vectors, budgets, stop flags) lives in one
`RunState` struct inside Database, not loose members, so a second context is
possible later; (2) task index-lookup is a separate `bind(db)` method the
constructor calls — the rebinding seam.

**(c) Snapshot escape hatch — free today, document it.** `(write-db tmp)`
while suspended is consistent; open the copy in a second slogd and run
arbitrarily complex programs against it with zero new machinery. Heavy (full
serialize/reload) but fully general — right for deep offline diagnosis,
wrong for tight polling.

## 9. Correctness invariants (the traps, and how the design avoids them)

1. **Never finalize a partial read phase** — suspend skips `finalizeAll` and
   the cursor reset; delta, bucketized views, and delta indices stay alive
   (refs are valid until the finalize that didn't happen).
2. **Resume entry** — mid-read resume skips the iteration barrier and write
   phase for the in-progress iteration, and the iteration-0 promote/reorg;
   hence the explicit position enum, never inference.
3. **Canonical tasks are immutable** — the copy-for-resume model means the
   objects in `once[]`/`every[]` always start from the origin (what the next
   iteration needs); parked copies are one-shot, owned and deleted by the
   queue. No reset-on-completion bookkeeping to get wrong.
4. **Partial send batches flush on pause** — everything emitted before the
   pause was fully processed; positions are saved after processing, so no
   tuple repeats or drops across a pause boundary.
5. **`latest_any_rec` untouched by suspend** — it is set by finalize (skipped)
   and reset by the iteration barrier (skipped on resume).
6. **Internal strata bypass budgets** and are unreachable while suspended
   (guardrails), so `running`/cursors can't be clobbered mid-suspend.
7. **Read-phase prim side effects** (string interning, collection-arena
   allocation) are append-only and persist across suspend — harmless.
8. **Header-keyed caches** — the Task signature change lives in daemon
   headers, which are in every plugin cache key, so all `.so`s rebuild.

## 10. Defaults

| Knob | Default | Notes |
|---|---|---|
| `max_ms` | 8000 | wall budget per continue call |
| `slice_ms` | 500 | per-task slice; effective deadline `min(slice, global)` |
| `mem_bytes` | auto | `max(100MB, 2% of RSS at call start)` |
| clock check | every 128 outer tuples | steady_clock via vDSO, ~20ns/read |
| all of the above | overridable | via `(continue [ms] [mem])` parameters |

## 11. The sprint

One sprint, all steps landing together — each step is independently
testable, but the payoff (and the golden-equivalence test) needs the full
stack. We should be able to get all of these done in one thoughtfully
executed sprint:

1. **Suspend/resume core (`daemon/database.h`)** — the risky heart, built and
   stress-tested first. `Task::work() → bool`; `RunState` struct (per-phase
   cursors, paused-task vector + mutex + cursor, position enum, budgets,
   `stop_requested`, emitted-words counter bumped in `sendBatch`); claim-loop
   stop checks; `ReadCompletion` skips finalize on suspend; sentinel skips
   the cursor reset; `runStratum` split into start + `continueStratum(Budget)`
   returning a status; RSS baseline; internal strata unbudgeted.
2. **Sliced drivers (`daemon/operators.h` + `compiler/emit-cpp.rkt`)** —
   slice-context `read_delta` (resume `(t,i)`); resume-from-last-key variants
   of `join_probe`/`join_all` for probe/once drivers; the 128-tuple clock
   check against `min(slice, global)` plus the stop flag; generated ReadTasks
   get resume-position constructor parameters (origin by default — one class,
   no resume variants), the copy-and-requeue pause path, the rule-id member,
   and `bool work()`; plugin tail becomes `d->push(s); d->continueRun();`.
3. **Daemon API (`daemon/daemon.h`)** — `continueRun(RunBudget)` with the §10
   defaults; daemon-assigned SCC ids at push; the `(fixpoint ...)`/
   `(paused ...)` message formats; idempotent fixpoint re-emit + `(idle)`;
   suspended guardrails on `beginStratum`/`open`/`import`/load/refresh.
4. **Ids + manifest (compiler)** — rule-id assignment as 31-bit source-text
   hash with occurrence disambiguation, pre-or-split; sidecar manifest
   `build/<hash>.meta` (rule id → text/location; strata in pipeline order);
   `malformed_deduction` carries the rule id (operationalization + emit).
5. **Actions (`compiler/actions.rkt`)** — `(continue [ms] [mem])` and a first
   point-query action `(lookup rel v...)`.
6. **Driver loops** — `runslog.rkt` interleaved send/read with reader thread
   and async channel (continue-until-fixpoint per stratum, paused lines
   surfaced as progress); `daemon/slogd.rkt` console equivalent.
7. **Tests** — the trust-establishing one first: the same program run with
   pathological budgets (e.g. `max_ms=25`, forcing dozens of mid-read
   suspends) vs. unbudgeted → **byte-identical final CSVs**. Plus api-tests:
   a paused-then-fixpoint sequence observed; `(sizes)`/`(lookup)` correct
   while suspended; mutating actions refused while suspended; idempotent
   continue at fixpoint; a memory-budget trip on a blowup program; the full
   golden suite green under default budgets (most tests never pause).

## 12. Explicitly deferred (with their seams already cut)

- **Deeper (per-join-level) continuations** — valid by index immutability;
  invasive codegen; wait for profiling evidence of slice overshoot.
- **Selective SCC re-run / pre-pushed pipelines** — needs the task `bind()`
  re-binding pass (seam cut in step 2) plus a delta-preserving reload story.
- **In-daemon query pipelines against a paused DB** — needs re-bind, a
  scan-full-index driver mode, and a second `RunState` context (struct
  introduced in step 1).
- **Args side-channel for actions** — if per-value JIT'd lookups get hot.
- **The stats API** — rule/SCC ids and per-task counters make it cheap; a
  later sprint defines the message surface.

## 13. Implementation notes (what landed 2026-07-06)

We settled on **Regime 1 only**: every read-phase rule pauses at its OUTER loop
and parks a continuation that resumes at an EXACT position — zero redo, and
sound without any idempotence assumption (so it stays correct when the counting
incremental substrate of `incremental.md` lands). Validated by
`tests/pause-tests.sh`: a 250-edge chain (~63k paths, scan driver) and a
constant-bound fan-out (40k pairs, probe driver) each suspend repeatedly under a
pathological budget and produce byte-for-byte the same CSVs as an unbudgeted
run. Concretely:

- `daemon/database.h`: `Task::work()→bool`; a `RunState` struct (phase cursors,
  the paused-continuation queue, the `RunBudget`, steady-clock deadline,
  `stop_requested`/`mem_tripped` flags, the `sendBatch` emitted-words counter,
  the total-RSS `mem_cap`, and the suspend position enum); `runStratum` split
  into `continueStratum(RunBudget, starting, tofixpoint)` (the bounded unit)
  with a blocking unbudgeted `runStratum` wrapper for internal strata;
  `ReadCompletion` skips `finalizeAll` on a mid-read suspend; `EndIterCompletion`
  makes the fixpoint/boundary-suspend/continue decision once so all workers
  agree, and also re-checks RSS there.
- `daemon/operators.h`: `read_delta_sliced` (scan, resume `(t,i)`) and
  `join_probe_sliced` (probe driver, resume from last match key), both with the
  128-tuple `SliceCtx` clock/stop check.
- `daemon/daemon.h`: `continueRun` with an env-configurable default budget,
  daemon-assigned SCC ids at push, the `(fixpoint …)`/`(paused …)` messages,
  idempotent re-emit + `(idle)`, and the suspended guardrails.
- `compiler/emit-cpp.rkt`: **all** read-phase rules slice via their outer loop —
  a `scan` driver and a probe driver with free columns get resume-position
  members, a `bind(db)` method (the re-binding seam), the copy-and-requeue pause
  path, and `bool work()`. A fully-bound probe (≤1 match) and a fact `once` rule
  (no joins, fixed output) are bounded, so they run atomically. Plugin tail is
  `d->push(s); d->continueRun();`.
- `compiler/actions.rkt`: `(continue [ms [mem]])` and a point-query `(lookup
  rel v…)`; the daemon also special-cases the literal `(continue)` line.
- `compiler/{runslog,compile}.rkt`, `daemon/slogd.rkt`: the response-driven
  continue loop (compile pipelining preserved) whose default is to continue to
  the final fixpoint; the sidecar manifest `build/<hash>.meta`; console
  auto-continue.

**Memory cap (§5).** `mem_bytes` is a TOTAL RSS soft cap checked against the
honest `/proc/self/statm` figure (re-read at the `sendBatch` choke point about
every 2 MiB, and once per iteration boundary). When RSS reaches it the read
phase pauses with reason `memory`; the drivers, whose default is to continue to
fixpoint, treat that as fatal and abort cleanly (a clear "out of memory" error,
non-zero exit) rather than climbing into the systemd `SLOG_MEM_MAX` cgroup cap
and being OOM-killed. Defaults: `SLOG_MEM_BYTES` soft cap tracks ~90% of the
`SLOG_MEM_MAX` hard cap (default 4 GiB → ~3.6 GiB soft), both overridable; a
run under the cap completes normally.

**Deferred (seams cut).** (1) *Mid-inner (Regime 2) pausing* — interrupting a
single outer tuple whose inner fan-out alone blows the budget — is not built;
such a tuple overshoots (rare, and the memory cap still bounds its growth). (2)
`malformed_deduction` still carries the source-location string, not the int
rule id; the stable ids + manifest exist, but wiring the id in needs a
display-time resolver and churns the tycheck goldens.

Also: while suspended the guardrails refuse **binary** DB writes
(`write-db`/`write-rel`) and reloads (they run internal strata / mutate indices
that would clobber the single `RunState`); CSV writes, `(sizes)`, and
`(lookup)` (read-only) remain allowed against the consistent suspended
snapshot, and a client continues to fixpoint before persisting anyway.
