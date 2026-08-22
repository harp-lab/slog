# Join-planning assessment (2026-08-15; selection V0–V4 shipped 2026-08-22)

Prompted by a report that *simple queries on large knowledge graphs run
slower than expected, apparently in the join planning*. This assesses the
rule join planner's ability to produce good join orders in practice, with
reproduced failing examples, and lays out general improvement options that
need neither worst-case-optimal joins (WCOJ) nor deep dynamic profiling.

## TL;DR

The rule join planner (`compiler/join-planning.rkt`) is **data-blind**. Its
join order comes from a purely structural greedy score
(`join-score`: `bound·100 − free·35 + enables·20`, `best-occurrence`
`:1009`) with **no relation size, cardinality, selectivity, or key
statistic** anywhere. When relations share arity — the common case — the
score ties and the **driver is chosen by source-clause order**.

*Update 2026-08-20 (post S1/S1b, `e63ca3a`):* the candidate comparison for
searched rules is now a ladder — expand-count → **driver `join-score`** →
free-variable-sequence profile (S1b; demoted below the driver score after
the dem_lambda regression) → expand positions → occurrence id (drivers:
last-written wins; tail ties follow source order). Observed consequences,
pinned by the cardsel suite below: a **constant-bound column still baits
the driver** (and no spelling fixes it — the score is source-order
independent), and **congruent drivers still fall to source order**. S1b
fixed the profile-distinguishable shapes; everything that ties or misleads
the profile remains data-blind.

Two masking mechanisms hide this in some shapes but neither reorders and
neither covers the "simple query on a large KG" shape:

- **WCOJ3** (`join3`) fires only for ternary **cycles** (triangles) —
  acyclic path/star queries never use it.
- **Semijoin filters** (Yannakakis-style) need **≥3 join clauses** and only
  *prune before an expanding join*; they cannot undo driving from a large
  relation.

Result: the same simple query, written two logically-identical ways, picks
opposite drivers and runs **100×–260× apart**, with the gap **widening
quadratically** as the KG grows. This matches the report exactly.

## Reproduced failures

All measured with `SLOG_OPT=0` (interpreter tier; the native tier consumes
the *same* order, see below). "default" = WCOJ + semijoin on. Sources in
`bench/path_driver.slog`, `bench/star_driver.slog` and their `_good` twins;
data via `bench/gen.py` (`bench_pathdriver`, `bench_stardriver`). The
**cardsel suite** (`bench/card_*.slog` + `bench/card-study.sh`, below)
extends these with self-generating cases covering every blowup class the
runtime-selection design must fix.

A path `X → hub → Z` filtered by a 3-row selective `sel(X,_)`, all relations
arity 2, `big1`/`big2` = N rows through a single hub (`big1 ▷◁ big2` = N²):

| query (identical logic) | N | default config | maskers off |
|---|---|---|---|
| `sel` written **last**  (drives from sel, 3 rows) | 8000 | **3 ms** | 3 ms |
| `sel` written **first** (drives from big2, 8000 rows) | 8000 | **366 ms** | 361 ms |
| `sel` written **last** | 16000 | **5 ms** | — |
| `sel` written **first** | 16000 | **1323 ms** | — |

- **100× at N=8k, 258× at N=16k** — the ratio grows with the graph (the bad
  plan is O(N²), the good one O(N)).
- **Neither masker helps.** This is a 2-join acyclic path: below semijoin's
  ≥3-join threshold and not a WCOJ cycle. 366 ms default ≈ 361 ms with
  everything off.
- The **selective relation written *first*** — the intuitive "good
  practice" — produces the **slow** plan. Empirically the greedy driver
  favors the *last-written* clause on a tie, which is arbitrary with respect
  to size. (A specific, fixable tie-break bug worth its own look.)

A 4-relation star (3 joins, so the semijoin threshold **is** met):

| query | default config | maskers off |
|---|---|---|
| `sa` last (drives from sa, 3 rows) | 4.5 ms | 4.0 ms |
| `sa` first (drives from `a`, 8000 rows) | 374 ms | 438 ms |

Semijoin fires here but only trims ~15% (438 → 374 ms): **filtering cannot
undo driving from the large relation.** So the pathology is broad, not
confined to sub-threshold queries.

For contrast, the genuinely cyclic case (`bench/hub_closing_tri.slog`, a
triangle) at N=1500 is 27 ms raw vs ~1 ms with WCOJ/semijoin — there the
maskers *are* doing the heavy lifting, because a triangle's n² intermediate
is unavoidable for *any* scalar binary-join order (AGM bound). That case
legitimately needs WCOJ or a semijoin; the path/star cases above do not —
a better *order* fixes them outright.

## Root cause and where order is decided

- Order is fixed entirely in `plan-stratum` → `plan-rule-versions`
  (`join-planning.rkt:568`) → `schedule-body-actions` (`:1182`), a greedy
  loop calling `best-occurrence`/`join-score` per step. Everything after
  (`operationalization.rkt`, index selection, codegen) only *lowers* the
  already-fixed order.
- **Both tiers consume the same order.** `compile.rkt:809-811` plans → one
  `cprog`; `:842-852` derives the `.plan` the daemon interpreter runs and
  `:869-872` the native C++, from that same `cprog`. Any ordering fix lands
  once in the shared planner and reaches interp + O0 + O2 automatically.
- **Signals the planner has but does not use for ordering:** relation kind
  (table/struct/lattice/temp), arity, lattice key-arity (an FD), struct-id
  functional dependency, dynamic/static status. **Signals it lacks
  entirely:** any row count, cardinality, selectivity, histogram, or index
  cost. There is *no channel* carrying sizes into `plan-stratum` today.
- A cardinality-aware planner **already exists** for interactive `?`
  queries — `query-plan.rkt` (`estimate-probe:561`, `best-probe-choice:570`)
  — fed by a runtime `query-boundary` tuple-count snapshot. It is entirely
  disjoint from rule compilation and never wired into `join-planning.rkt`.

## Sizes are not available at compile time

A plan is compiled as a **pure function of the program text** and cached by
program hash; it precedes any database. Proof: the same program over a
21-tuple database and a 100,001-tuple database compiles to the **identical
plan `abcd4fb4`**. The plan cache key (`compile.rkt:229`, `progstr`) folds
only program text, compiler/daemon fingerprints, and settings — no data. So
whatever ordering the planner picks is fixed before any relation exists and
is reused across every DB the artifact ever runs against.

Consequences for a size-aware planner:

- **A single compile-time plan cannot be right on databases with opposite
  skew.** If relation A is small on KG1 and B is small on KG2, the one
  cached order is optimal for at most one of them. (Now a runnable A/B:
  `bench/card_skew_a.slog` vs `card_skew_b.slog` — one plan, 246× apart.)
- **Input (EDB) sizes are knowable at data-bind time** — the daemon has each
  loaded relation's row count for free the moment it attaches the DB — but
  that is *after* the cached artifact exists, so using it is a replan when
  the data appears (a recompile), not a compile-time read.
- **IDB / recursive relation sizes are unknowable statically at all** — they
  are the output of the fixpoint, and a recursive relation grows during its
  own evaluation.

This is the fact that motivates runtime selection (below): the only place
the deciding signal exists cheaply, without profiling a representative
database, is *at run time*, and the only way to exploit it without a recompile
is to have the alternatives already compiled.

## Test-coverage gap

- `planner-tests.rkt` (12 cases): all **determinism / structural-shape /
  error-rejection**. **Zero** tests check that a chosen order is *good* on
  data; test #3 explicitly accepts either join order. `index-selection` and
  `semijoin` tests verify the mechanism is *placed*, never that it *pays
  off*.
- **No latency, intermediate-size, or iteration-ceiling assertion** is wired
  into any runner. The only perf gate, `bench/regress.sh`, is manual,
  machine-local, unwired, and its 4 programs contain no skewed star.
- The 309–1624× semijoin speedups are a one-time `bench.sh` measurement,
  **not pinned** — a regression to O(n²) passes the whole suite.
- The current (data-blind) order **is frozen** in plan goldens
  (`plan-expected/sj_tri.plans`), so any ordering improvement must re-record
  — a friction cost, not a quality check.

*Update 2026-08-20:* the asserted ratio gate now exists as
`CARD_ASSERT=1 bench/card-study.sh` (twin-diff equivalence + seven ratio
gates over the blowup classes). It is deliberately **not** wired into any
default battery — these are long-running cardinality studies — but it is
the tripwire each J-phase below should run before landing.

**Net:** nothing in the *default* suite would fail if the planner regressed
to a bad join order on a large KG.

## General improvement options (no WCOJ, no deep profiling)

Ranked by leverage. All land in the shared planner, so all replicate across
interp/compile and compose with the existing lower-level mechanics
(semijoin, WCOJ, index selection stay as-is and only get *better inputs*).

1. **Use relation sizes to choose the join order — but note WHERE the sizes
   come from (the big win, with a caveat established below).** Sizes are the
   signal that fixes every case above (drive from the smallest/most-selective
   relation). The subtlety, proven in "Sizes are not available at compile
   time" above, is that a plan is compiled as a pure function of the program
   and cached by program hash — it precedes any database — so the sizes do
   **not** exist when the single plan is chosen. Getting them means either a
   bind-time replan (a recompile when the DB appears) or, better, **runtime
   selection among precompiled alternatives** (see "Proposed direction"
   below). `query-plan.rkt` already orders by size, but only because it runs
   at *query time* against a live boundary — not a cached compile artifact.

2. **A cost-based greedy (or bounded DP) over the body using those sizes.**
   Standard industrial approach: greedy-with-cardinality avoids the bad
   driver and the exploding intermediate; bounded DP (bodies are small)
   gives near-optimal orders. No representative-DB profiling required —
   static row counts + selectivity propagation through equijoin keys is
   enough for reliable good orders.

3. **Use the functional-dependency signals already present, even without
   sizes.** Prefer a driver/next-clause whose bound columns form a **key**
   (lattice key-arity, struct-id FD, declared unique columns) — those joins
   are provably non-expanding. This is a strict improvement over the pure
   structural score and needs no new data channel.

4. **Fix the tie-break.** Today equal-arity relations tie and the driver
   falls to source-clause order (empirically the *last* clause). Even absent
   full cardinality, breaking ties toward the relation with the smaller
   estimated size — or simply *not* toward source position — removes the
   "same query, 100× apart depending on spelling" fragility.

5. **Make semijoin/Yannakakis cheaper to reach** (lower the ≥3-join
   threshold, place a selective-relation existence filter before the first
   expanding join). This helps acyclic shapes but is complementary, not a
   substitute: it cannot fix driving from the large relation (see the star
   result), so it should ride on top of (1)–(3), not replace them.

### Guardrails for any change

- **Determinism must hold.** The canonical rule/clause order
  (`canonical-rule-order`, `rule-sort-key`) is a correctness invariant; a
  cardinality tie-break must itself be a total, input-order-independent
  function (e.g. size then canonical id), so `plan-determinism.sh` stays
  green.
- **Plan goldens will churn** (`plan-expected/sj_tri.plans` and every
  `.plan`); re-record is expected and sanctioned for a planning change.
- **Add an order-quality gate.** Now built: `bench/card-study.sh` (opt-in;
  see the suite section below). Wire `CARD_ASSERT=1` into a cardsel tier as
  the J-phases land.

## Runtime plan selection + bounded measurement

**Status — SHIPPED V0–V4, 2026-08-20/22** (`8564861` work counters,
`e08af3b` J1 arms, `7550680` J2 counts selector, `60b727f` V3 measurement
layer, V4 = the R5 tripwire + R1 rescue and the all-capped rate rule),
behind `SLOG_MULTIPLAN` (flag off ⇒ plan bytes unchanged, gated
by plan-goldens + plan-determinism). Design history: mechanism sketch and
verified anchors 2026-08-15; racing rejected; measurement layer and
decisions R1–R5 ratified 2026-08-20; built and measured through 08-21.
The ratified-design sections below are kept as the rationale record; the
**As built** section right after records where implementation corrected
the design.

### As built (V0–V3): the architecture that shipped

- **V0 — work counters.** The interpreter's per-row tick and driver-row
  pull accumulate in `Attempt` beside `fires` (settled once per
  `run_loop` invocation at every exit), merge on complete only, and
  publish as `$stat_work(loc, tag, ticks, driver_rows)` — keyed by the
  FULL variant, so work attributes per ARM while fires stay
  audit-aggregated under the stripped tag.
- **V1 — arms are sibling rule-defs, not a `(choose)` form.** An eligible
  version's alternative order is a second rule-def sharing prov→rid and
  (for tail arms) the driver→base tag; canonical-plan's existing
  `(rid, tag)` grouping mints the `#N` ordinals, seal uniqueness holds on
  the suffixed variants, and fire identity is untouched.  The mark rides
  the crule kind slot into an ABI-2 `(attrs (arm n gid))` exec entry —
  the **gid** (kernel-unique, minted along plan-stratum's canonical walk)
  is the group key, because closed-rule whole-order arms carry different
  drivers, hence different tags.  Dynamic tail arms come from a
  `#:banned-first` re-run of the greedy scheduler; closed-rule arms are
  the already-enumerated drive-from-each candidates, retained one per
  DISTINCT driver relation (cap 4).  Arm crules never enter native
  coverage; index needs union automatically (eager-union default).
- **V2/V3 — the selection gate.** ALL arms attach; each shares an
  `ArmGroup` cell, and the task gate in `InterpReadTask::work` lets
  exactly one arm do work per iteration.  The pick memoizes per **read
  epoch** (`Database::read_epoch`, bumped at the `EndIterCompletion`
  barrier): every task and any abort-REPLAY of one iteration sees the
  same pick — the T6 determinism story survives — while each new
  iteration re-selects against its own delta.  Selection = the **counts
  screen** (arms within 2× of the smallest driver by
  `tupleCount() + deltaLiveCount()`; the skew class resolves here at zero
  probe cost) then **bounded emission-free probes** of the near-tied
  arms: `make_probe_execution` runs the arm's own machine over the frozen
  read state with null sinks, no stepper, and a swallowed error channel,
  metered by the V0 counters under `SLOG_MEASURE_BUDGET` (default 4096,
  one 8× escalation when every candidate caps).  **The budget cap is the
  blowup detector**: a bad arm's probe hits the cap and is abandoned
  free — probes are invisible to every audit, stat, and sink because
  fires/work merge only on the complete path a probe never takes.  The
  first group task of an epoch claims and probes; siblings spin-yield
  for the bounded duration.  `SLOG_FORCE_ARM` forces (test hook);
  `SLOG_ARM_DEBUG=1` traces screens, probes, and picks.

**Corrections the implementation made to the ratified design:**

1. **Attach-time counts read ZERO** — the between-strata reload re-stages
   prior content as delta batches, so masters are empty until the first
   intern.  Selection therefore lives at first task execution (the gate),
   not at attach, and the size signal is `tupleCount() + deltaLiveCount()`
   (the new `Relation::deltaLiveCount`, accelRecordRound's counting
   idiom).
2. **`BoundRule::attach` COPIES the rule** into its tasks' shared
   ownership; the group must adopt the OWNED copies (the
   bind_kernel_plan originals die when `attach_normal_rules` returns).
   Task-time probes against the originals read freed memory — found as
   two crashes and garbage picks, fixed by `ArmGroup::adopt` inside
   `attach`.
3. **No tripwire or rescue was needed for the entry suite.**  Per-epoch
   probing with the budget cap subsumed the ratified R5 tripwire for
   every case whose delta the probe can traverse or cap on — including
   the single-row monster (its probe caps).  The R5/R1 machinery is
   NOT dead: `bench/card_probe_blind.slog` (below) is its motivating
   case.
4. **Whole-order arms fire under driver-named tags** (`all:<driver>`), so
   the arm-invariant is the per-LOC fires total; tail arms keep exact
   per-key fires identity.  Gates sum over tags for closed arms.
5. **Entry measurement subsumed "measure at stratum entry for flagged
   rules"**: the near-tie screen IS the flag, evaluated per group per
   epoch, so no compiler-side sensitivity flag was needed for
   measurement (the emission gate in the planner still bounds which
   rules carry arms at all).

**Measured (unforced, one artifact per case; interp tier):**

| case | static bad | selected (V3) | oracle | note |
|---|---:|---:|---:|---|
| `card_skew_a` / `_b` | 4994 | 25.5 / 23.3 ms | 16.5 | counts screen only, no probes |
| `card_bait` | 4148 | ~3.8 s incl. index build | 1077 | needs `SLOG_MEM_MAX=16G` (below) |
| `card_corr` | 9479 | 128 ms | 83 | probes resolve exactly-tied counts |
| `card_flip_ac` / `_ca` | 69446 / 85350 | 1846 / 1822 ms | 2071 | **beats the hand-split oracle**; both arms run, per phase |
| `card_monster_ac` | 38810 | 69.6 ms | 57 | the single-row monster's probe caps |
| `card_probe_blind` | 128.7 s unrescued | **0.92 s** | 0.55 s | the V4 rescue (below) |
| `card_probe_late` | ~2× that | 1.0 s | 0.6 s | TWO rescues, independent epochs |
| `card_probe_rate` | 35.6 s | 0.80 s | 0.49 s | the all-capped rate rule |

`bench/card-study.sh` now runs both worlds (static gates + selection
gates, `CARD_ASSERT=1` to enforce) and is the standing gate for every
later phase.

**V4 — the tripwire and rescue (shipped 2026-08-22).**  A blowup the
probe's budget horizon cannot see (`card_probe_blind`: one 2×10⁹-probe
wing hidden in 20k-row deltas; both arms' probes cap blind on clean
rows, and sampling cannot reliably find one row in 20k) is caught DURING
execution: each choice-group task checks, at deterministic slice
boundaries, `meter > C_floor + k·ĉ·rows` (R5; ĉ = the epoch's winning
probe rate, `SLOG_TRIP_FLOOR`/`SLOG_TRIP_K`, flat C_init for unprobed
picks).  On a trip the task ABANDONS its arm at the current driver row:
completed rows' fires merge from the last driver-boundary snapshot
(`Attempt::fires_at_driver`), the partially-expanded row's fires die
with the attempt, and the bucket's remainder — INCLUDING a full redo of
that row — transplants to the best alternative (chosen by probing the
remainder), fast-forwarded via `Machine::skip_driver` and re-queued
through the pause machinery as a gate-exempt rescued task.  Exact-once
holds literally: rows 1..j−1 fire under the old arm, rows j..n under the
new, and the redone row's flushed partials dedup at intern — which is
why arm eligibility requires ordinary-table HEADS (a temp head would
double follow-up fires; order-sensitive lattice merges could change
values).  Only SAME-DRIVER (tail) arms are transplantable — a
whole-order arm's different driver re-partitions the work, enforcing the
ratified "closed drivers are unswitchable mid-run" structurally.
Rescued tasks never re-trip (K=2 would ping-pong); `SLOG_NO_RESCUE=1`
disables.  Measured: probe_blind 128.7 s → 0.92 s (1.8× oracle);
probe_late's TWO hidden monsters rescue independently across epochs
(per-epoch trip state); and the sibling selection fix — when every
candidate probe caps at both budget rungs, compare PROGRESS (driver rows
traversed) instead of tied raw meters — takes `card_probe_rate`'s
uniformly-40× arm from 35.6 s to 0.80 s with no trip at all.  Battery:
rescue-content / rescue-footprint (both arm tags in one run) /
rescue-fires-loc-total over `tests/multiplan/pblind_mini.slog`.

**The index-cost finding, and the knobs (shipped 2026-08-22).**  The
eager arm-union built several new 9M-row orderings for `card_bait` and
the systemd-run 4G cgroup cap OOM-killed slogd **silently at install
time** (the in-daemon OOM diagnostics never see a cgroup kill; the
runslog EOF error names this cause and the remedies).
`SLOG_MULTIPLAN_INDEX` (job-hashed) now selects the policy:

- **`eager`** (default, unchanged): union every arm's needs.
- **`free`** ≡ budget:0 — alternatives are admitted only when they add
  ZERO new FULL orderings beyond the primary-only plan (delta orderings
  are delta-sized and ride free under every policy); a group reduced to
  its primary is unmarked entirely.  Headline: `card_bait` under free
  completes at the DEFAULT 4G cap picking `all:boo` — the good arm fit
  the primary's orderings all along — gated at ≤6× `bait_good` in the
  study, no OOM, no union build.
- **`budget:N`** — deterministic rank-order admission while each
  relation gains ≤N new FULL orderings.  Honest caveat: the budget
  counts ORDERINGS, not bytes — `budget:1` on bait still admits one
  9M-row ordering per big relation and still OOMs at 4G; byte-aware
  budgeting (rows × orderings estimate) is the noted refinement.
- **lazy** (declare-then-materialize-on-selection) remains the follow-on
  slice: it needs a third "declared" state in the seal contract's
  `validate_order` and a counts-nominate → backfill → probe selection
  flow, and it can never apply to a J3-promoted native arm (generated
  code cannot wait for a backfill).

Free-mode admission is implemented as the budget machinery at N=0,
between the primary-only needs fold and `choose-indices`, with dropped
arms unmarked pre-lowering — so a free-mode plan's index declarations
match the flag-off plan's.  Battery: index-free-drops-unrealizable /
index-budget-keeps (flip_mini's alternate needs one new b-reverse
ordering) / index-free-keeps-zero-cost-arms (skew_mini keeps a
delta-only alternative with answers identical to eager).

### The idea

Two layers, cheap-first:

1. **Selection (counts).** Compile a small set (K ≈ 2–4) of alternative
   join orders per size-sensitive rule into the **same cached artifact**,
   and choose one at run time from actual relation row counts. Every valid
   order computes the identical instantiation set, so the pick has no
   correctness risk; the alternatives derive from one program text, so the
   **cache key is unchanged** and there is **no recompile when the DB
   changes**.
2. **Measurement (bounded, emission-free).** Counts cannot see cross-clause
   correlation, composition, or per-iteration drift (`card_corr`,
   `card_flip`, `card_monster` below are constructive proofs). Where counts
   are structurally insufficient, run the candidate arms over a **bounded,
   deterministic sample of real driver tuples with counting sinks** — the
   same interpreter machine, emitting nothing — and pick from the measured
   work. Measurement is rare (stratum entry for flagged rules; mid-fixpoint
   only on a tripwire) and its cost is capped in ticks.

The design thesis, stated once: **separate measurement from execution.**
Fully adaptive engines interleave them (reorder mid-join on observed
blowup); in Slog that would force the exact-once audit and the counted
flavors to police the executor. Instead the production path stays
straight-line (compiled arms, exact-once, audit-clean) and measurement is a
side activity that cannot perturb any semantic state because it never
emits. There is **no rollback anywhere** in this design — measurement runs
have nothing to roll back, and production runs never restart (a switch
governs only not-yet-processed driver tuples).

Two verified compiler facts make the selection layer smaller than it
sounds:

- **The candidates are already enumerated.** For closed/seeded rules the
  planner already builds one complete candidate order per legal driver
  (`enumerate-drivers?`, `join-planning.rkt:756-759`, capped by
  `wcoj3-search-cap`) and discards all but the argmax. Plan-set emission =
  retain top-K of a list the planner already constructs.
- **Reordering is exactness-safe by construction.** The FULL/OLD/NEW/TOMB
  views that make semi-naive and the count/M4N/M4S/DRed^c flavors exact
  bind to *logical occurrence ordinals* assigned before driver choice and
  scheduling (`join-planning.rkt:589-592` — "views immune to later action
  reordering"). Any alternative order of a version derives the identical
  instantiation set under every flavor. This is the load-bearing
  soundness fact.

### The two choice surfaces

- **Closed and seeded rules** (`drivers`, `join-planning.rkt:760-784`) — a
  whole-order choice among drive-from-each candidates. Resolved **once at
  stratum entry**: these rules run once per stratum, and the task fan-out
  depends on the driver kind (`task_count()`, `plan.h:2267`), so the pick
  must land before `BoundRule::attach` (`plan.h:2481`). Because arms of a
  closed rule may have **different drivers**, and a driver switch
  re-partitions the work, a closed rule's driver is **unswitchable
  mid-run** — which is why entry measurement is *mandatory* for flagged
  closed rules (R3 below): one shot, no rescue.
- **Dynamic (semi-naive) rules** — the delta versions all still run, one
  per dynamic join (`:776`); the choice is the **tail order within each
  version** (`schedule-body-actions:1182`). The driver — and hence
  `task_count()` — is identical across arms, so the pick can be a per-rule
  index read in `make_execution` (`plan.h:2314`) and legally changed
  between iterations, and (with the rescue below) at driver-tuple
  boundaries within one. Temp-driven versions keep their driver (temps
  have no indices, `:772`); only their tails are choosable.

### Why counts, not clocks — racing assessed and its value salvaged

The other mechanism on the table was **plan racing**: every N iterations
run all K arms of a rule, keep whichever finishes first. Rejected as a
*control* mechanism, on grounded reasons:

1. **No cancellation primitive at the right granularity.** The only abort
   in the tree is `abortReadAttempt` (`database.h:5074`) — it discards the
   **entire read phase** and is restart-grade. Nothing cancels *one
   rule's* half-executed tasks inside a phase; send shards carry no
   per-producer attribution (`database.h:737-745`). Worse, admission
   (`abortObstacle:5005`) refuses the `count`/`maint*` flavors outright.
2. **Duplicate derivations under the counted flavors.** K arms racing over
   the same delta each derive every fact. Set semantics dedups; DRed^c
   derivation counts and the exact-once fire audit do not — the suite
   asserts *literal* fire counts.
3. **The verdict is stale by construction.** Delta sizes swing across
   iterations; row counts are re-readable every iteration for the price of
   a comparison.
4. **Timing-as-control makes behavior load-dependent** — un-replayable
   performance, a selector whose decisions cannot be reproduced from a bug
   report. (Nuance, verified: *which tier executed* is already
   load-dependent today — promotion pickup is a filesystem poll — and the
   gates deliberately assert content and fire totals, never executor
   identity. That precedent makes clock-driven arm choice *tolerable*, not
   *good*; see R2.)

**The salvage (this is the 2026-08-20 refinement):** racing's genuine value
— it observes real relative cost on real data, correlations included — is
obtained deterministically by the measurement layer, because **the losers
never emit**. An emission-free arm probe under a tick budget needs no
abort machinery (nothing to discard), cannot double-derive (nothing
staged), and is a pure function of DB state (budgets in ticks, sampling by
hash). Measurement subsumes what racing was for, at a bounded, rare cost.

### The determinism boundary (R2, ratified)

**Counters are the only control input.** Row counts, tick counters,
measured per-row rates — all pure functions of database state. Wall-clock
time is logged as a diagnostic (`$stat_fixpoint` already carries it) and
is **never consulted for control**, not even as a "prompt" for a
counts-verified decision: the tick counter must exist anyway for the
tripwire, is cheaper than a clock read, and attributes blame to a rule,
which a stratum wall clock cannot. Accepted cost: native-executed rules
have no tripwire until native tick accumulation ships (J3); until then
they are covered by entry measurement and per-iteration counts only.

One verified caveat: "deterministic function of DB state" is **not** the
same as "same arm chosen on replay". The accel seed reservoir injects
sampled tuples before replay (`accelRecordRound`, `database.h:7637`), so
entry-time sizes on a seeded replay legitimately differ and the selector
may pick a different arm there. That is sound — arms are logically
equivalent — but it means **gates must assert content equality and
`$stat_fires` equality, never arm identity.**

### Fire identity survives — with one structural constraint

Verified: nothing in the fire/stat path keys on plan bytes. The fire key
is `(loc, tag)` where `tag` strips the `#ordinal` suffix
(`plan.h:1850-1870`, the N5/stats-4 unification), and the base tag names
the **driver relation** — which the arms of one version share. K
alternative orders of a version land on the same fire slot by existing
design.

The constraint that shapes the plan format: **a choice group must be a
sub-structure inside ONE `rule-def`/crule, never K separate rule-defs.**
The scheduler runs every attached task unconditionally
(`runPhase`/`task_at`, `database.h:6358-6388`); K separate rule-defs would
all attach, all fire, multiply `$stat_fires` by K, and fail the exact-once
audit hard. One rule-def, K cursor ladders inside it, exactly one executed
per (version, iteration).

**Arm-vocabulary uniformity across flavors (new, required):** the
count/maint artifact flavors re-plan independently, so J1 must emit the
*same tail orders under the same arm indices* across a rule's flavor
twins — the same uniformity doctrine that governs semantic source
transforms (`incremental.md` §8B.3). A verdict formed in the set world
must name an arm every twin has.

### The measurement layer (ratified 2026-08-20)

**The primitive.** "Measure arm k of rule R" = build a `BoundExecution`
for that arm with **counting sinks** and run it over a bounded sample of
driver tuples, then discard the attempt. Every piece exists:

- The Q1 query path already runs the *same* `interp::Machine` with a
  non-emitting counting sink (`query::Mode {rows,count,exists}`,
  `query.h:23`, sink at `query.cpp:1032-1078`) — the executor is proven.
- Work is already metered: `WorkBudget::tick()` fires exactly once per
  yielded cursor row (`interp.h:200-209`, `:302`; join3 `plan.cpp:2242`)
  and is currently discarded. Accumulate it (and driver rows consumed)
  into `Attempt` beside `fires` — the merge-on-complete precedent is
  `plan.h:2444-2454`.
- Fires are attempt-local and merge only on completion; an abandoned
  attempt merges nothing and sent nothing. **Exact-once and every counted
  flavor are untouched by construction** — measurement needs no abort, no
  staging, no admission policy.

**The measured statistic.** ĉ = ticks per driver row, per arm. Arms of a
dynamic version share the driver, so they are measured over the *same*
deterministic driver prefix/sample — directly comparable.

**Sampling (deterministic, effectively random).** Prefix samples are
biased (btree order is key order; hubs cluster), so sample driver tuples
whose hash lands in a window, seeded by `(rule, iteration, epoch)` — a
pure function of DB state, replayable, yet unbiased in the statistical
sense. Per-driver-tuple subtrees are independent and costs are additive
across the partition, so the sample mean is unbiased with standard
concentration; and the decision is a *ranking* of K ≈ 2–4 arms whose
interesting gaps are 10–100×, not 1.2×. When arms don't separate at
budget B, run survivors at 2B (successive halving); a genuinely tied pair
doesn't matter to get right. A mis-pick from an unlucky sample is a
bounded-loss event, not a permanent one — the tripwire self-corrects.

**When measurement runs (R3).**

- **Stratum entry, not DB load:** a stratum's true inputs (including
  upstream IDB) first exist at its entry; a global load-time pass would
  measure empty relations for downstream strata. For stratum 0 this *is*
  effectively "at EDB+rule load". Entry measurement runs for gate-flagged
  rules whose count-predicted work exceeds `c·K·B` (never spend 16k probes
  optimizing a 5k-probe rule) — and **always** for flagged closed rules
  (their driver is unswitchable mid-run; one shot). Cross-stratum IDB
  shifts are thereby handled without any tripwire: the next stratum's own
  entry measurement sees them.
- **Steady state:** per-iteration reselection is **counts-only** with
  hysteresis (J2b). No measurement on quiet iterations.
- **On the tripwire:** mid-fixpoint drift only (a recursive relation
  changing character during its own inference — the rare residual).

**The blow-up tripwire (R5).** Not an absolute total (that conflates plan
quality with delta size); a **rate**:

    trip  iff  ticks > C_floor + k · ĉ · driver_rows_consumed

with ĉ the arm's own measured rate (baseline from entry measurement or
the last re-measure) and a flat `C_init` ceiling for never-measured rules.
Implementation: bump the allowance by `k·ĉ` at each `need_driver`, compare
at the existing budget-check sites. Self-scaling: a genuinely expensive
rule has a large ĉ and never re-trips *for being expensive* — it trips
only when this iteration's per-row cost exceeds its own established rate
by k×, i.e. exactly "the data now behaves differently than when measured".
After a trip and re-measure: **challenger wins** → switch, adopt its ĉ;
**incumbent wins** (every arm is about this expensive) → ratchet ĉ up to
reality and double k (capped) — two or three trips converge any hard rule
to "least-bad arm, uninterrupted" and raise a diagnostic that the rule
needs WCOJ/factoring, not ordering. Guards: one trip per (rule,
iteration); re-measure only when projected remaining work ≫ K·B.
Proposed defaults, all runtime-tunable and **in no cache key**:
`B = 4096` (→32k by halving), `k = 8` (→64 cap), `C_floor = 10⁶`,
`C_init = 10⁸`.

**The rescue — no rollback, resume under the winner.** On trip: the
rule's tasks pause at **driver-tuple boundaries** (the parking machinery
exists — `pushPaused`, value-keyed continuations; the boundary observable
is `need_driver` with an empty level stack, `interp.h:723-735`);
measurement probes the alternatives over a sample of the *remaining*
driver tuples; the remainder resumes under the winner by continuation
transplant (build the winning arm's execution with its driver cursor
sought to the saved position — value keys, not iterators, the `wcoj.md`
§13 convention). Work already done under the old arm stands: it is
correct, just expensive. Because instantiations partition exactly by
driver tuple and arms share the driver, "tuples 1..k under A, k+1..n
under B" enumerates each instantiation exactly once. If the tripped rule
was running native, the remainder runs interpreted (an `InterpReadTask`
over the residual range — no executor-swap machinery needed); next
iteration the winner runs native if compiled (J3), interp otherwise.

**R1 — the flavor support matrix for mid-subtree switching.** The one
place granularity matters: the ceiling can be hit *inside* one driver
tuple's subtree (`card_monster`: ~10⁹ probes in a single subtree).
Abandoning a half-expanded subtree and redoing that tuple under the new
arm is:

- **Allowed for set flavors.** The abandoned partial's tuples are already
  in shards, but the redo's duplicates collapse at intern — emit-time
  dedup is only against the pre-read master, so same-read duplicates are
  already routine and absorbed (`operators.h:1126-1155`); and the
  abandoned attempt never merged its fires, so the redo's complete merge
  keeps `$stat_fires` literally exact.
- **Refused for count/maint flavors** — signed contributions are
  deliberately not idempotent (multiplicity is the semantics), so those
  flavors switch **only at driver boundaries**. This mirrors the existing
  admission line (`abortObstacle` refuses count/maint for phase aborts).

Why the asymmetry is nearly free in practice: **counting is
architecturally downstream of a set-semantics traversal.** The forward
hot path — where blowups live — is set-flavored and gets the full rescue.
Recount rounds re-run joins over data the set world already settled, and
counts-based selection re-derives the same choices (pure function of the
same DB states) — a count round tripping is nearly impossible (edge:
a fresh recount over a DB built purely incrementally, which retains every
boundary-granularity tool). Maint rounds run over deletion cones —
typically small, and boundary-granularity switching applies in full. The
one accepted exposure: a counted-flavor rule can be forced to finish one
monstrous subtree under the bad arm before switching.

**R4 — selection state is ephemeral.** Per rule-version: chosen arm,
measured ĉ, ratchet k, last-trip marker — a few words. Survives
pause/resume within a run; **reset at stratum entry and on daemon
restart/reload/replay**. It is reconstructible (the next entry
measurement rebuilds it), staleness is actively harmful (post-restart data
can differ — the seeded-replay caveat), and persisting it would touch
every snapshot and replay format for nothing. A restart is
indistinguishable from a fresh run with respect to selection — the
easiest thing to reason about in a bug report.

**Index policy (the D3 cost, ratified defaults).** Each ordering is 32
btrees holding full permuted tuple copies: an extra ordering ≈ +1× that
relation's index memory. Policy tiers:

1. **Default: eager union.** Requisition the union of the arms' index
   needs at compile time. The J1 sensitivity gate keeps the blast radius
   small — most rules keep K=1 — so "overload" in practice means a
   handful of extra orderings on the rules that earn them.
2. **Knob: free-arms-only.** Retain only alternative orders whose bound
   sets pack into orderings the argmax plan already requisitions (the
   `query-plan.rkt` discipline of enumerating only realizable orders).
   Zero index cost; rules with no free alternative keep K=1.
3. **Knob: lazy lifecycle.** Declare each arm's needs in the plan;
   materialize on first selection via the existing idempotent backfill
   (`Relation::addIndex`, `database.h:1784-1848`), **strictly inside the
   single-threaded per-round seams** (`ensureReorgBuffers` reallocation is
   not safe against a concurrent reorg); drop orderings unused for M
   iterations. Note measurement is index-bound too — an arm must have its
   indices before it can be probed — so lazy mode nominates candidates by
   counts first, backfills, then measures.

### Isolation inventory — what this must not touch, and why it doesn't

The arm is an execution detail **below fire identity**. Invariant: exactly
one arm of each rule-version executes per (driver tuple, iteration). Above
that line:

| feature | interaction | why safe |
|---|---|---|
| exact semi-naive + count/M4N/M4S/DRed^c | reordering inside a version | views bind to logical ordinals pre-scheduling (`join-planning.rkt:589-592`); identical instantiations for any arm; flavor twins get uniform arm vocabularies |
| exact-once fire audit / `$stat_fires` | fires from an arm | `(loc, tag)` key strips `#ordinal`; arms share the driver-named base tag; one-rule-def constraint above; abandoned attempts never merge |
| measurement runs | side effects | none — counting sinks emit nothing, stage nothing, merge nothing; budgets in ticks |
| mid-run switch | duplicate derivations | driver-tuple partition ⇒ exact-once at boundaries for all flavors; mid-subtree redo set-flavor-only (R1) |
| lattices | order-sensitive merges | **excluded from choice groups initially**: an extern or float lattice merge is the one place order can change the *logical* result (`db-compression.md:512-535`) |
| RF5 activation (A2/A3 cone) | plan-set rides the program payload | arms of a rule have identical relation-level read/write sets → write-set narrowing, push filters, retirement unaffected; the plan-set swaps atomically with activation; selection state is ephemeral, so activation carries none |
| plan/.so cache | key discipline | the *policy* (flag, K, candidate rule, index mode) joins the settings block of the job hash (`compile.rkt:236-250`); the runtime *pick*, ĉ baselines, and tripwire constants never enter any key |
| tiered native (T3b/T4) | which arms exist natively | J1/J2: choice-group rules simply **leave native coverage** — T4 partial coverage runs the complement interpreted *by construction* (`attach_normal_rules(..., &covered)`); J3 compiles the dominant arm (or a K×-cluster) and adds the native tick counter |
| T6 executor swap | selection flip on a compiled rule | not needed: the rescue runs the residual range interpreted; the production ladder stays monotone interp→O0→O2 |
| plan goldens | .plan shape | flag off → arm 0 ≡ today's argmax, byte-identical; flag on → goldens grow choice groups; re-record sanctioned |
| semijoin / WCOJ | per-arm | applied within each candidate order; compose, don't compete (see the suite's join3-chaining findings) |
| replay / compression | reproducibility | replay re-executes every instantiation exactly once; the selector is deterministic from DB state; selection state resets; gates assert content + fires, never arm identity |
| pause/resume, snapshots | new state | none persisted (R4) |

### Where the hooks land (verified anchors)

Compiler — all inside the planner and the existing emission seam:

- Candidate retention: keep top-K at `join-planning.rkt:845-848`; K tail
  schedules per dynamic version via `schedule-body-actions:1182` re-runs;
  uniform emission across flavor twins.
- Choice node: inside one `rule-def` in the canonical plan
  (base-tag/`#N` grouping, `canonical-plan.rkt:373-390`).
- Emission: `.plan` and native TUs both derive from the one `cprog`
  (`compile.rkt:842-871`); native ignores arms > 0 until J3. Interp arms
  cost **zero clang** — plan bytes only (largest plan in tree is ~24×
  under the 16 MiB reader cap).

Daemon — selection:

- Decode: the body-op loop of `decode_rule` (`plan.cpp:585-686`) grows a
  `(choose (alt …) …)` form; unrecognized forms already degrade gracefully
  via `out.unsupported`. Each arm seals through `seal_rule` (`plan.h:555`)
  into its own cursor ladder.
- Whole-order pick (closed/seeded): stratum entry — the `continueStratum`
  `starting` block (`database.h:6541-6574`) — before `BoundRule::attach`.
- Tail pick (dynamic): per-rule current-arm atomic read in
  `make_execution` (`plan.h:2314`), recomputed at `EndIterCompletion`
  (`database.h:9435`, the seam that already hosts `accelRecordRound` and
  `rankRecordRound`).
- Sizes: `Relation::tupleCount()` (`database.h:1924`) — 32 O(1) btree size
  reads. Delta live-counts: sum post-reorg `read_buckets` sizes
  (`accelRecordRound` pass-1 precedent, `:7653-7657`). **Not `$stat_*`** —
  `$stat_size` is a dump-time snapshot.

Daemon — measurement (verified 2026-08-20):

- Work tick: `WorkBudget::tick()` fires once per yielded cursor row
  (`interp.h:200-209`, `:302`; join3 `plan.cpp:2242`) — accumulate into
  `Attempt` (`interp.h:544-555`) beside `fires`; merge precedent
  `plan.h:2444-2454` (`bumpFiresSlot` on `StopReason::complete` only).
- Non-emitting executor: the Q1 counting sink over the same
  `interp::Machine` (`query.h:23`, `query.cpp:1032-1078`).
- Driver boundary: `need_driver` with empty level stack
  (`interp.h:723-735`); parked continuations carry value-keyed driver
  positions (`plan.h:2425-2479`, `pushPaused` at `:2474-2476`).
- Why measurement must not emit: sinks stream 4095-word `InsertBatch`es
  into send shards mid-task (`operators.h:537-551`) and shards have no
  per-producer attribution (`database.h:737-745`) — emitted work is
  unrecallable below phase granularity.
- Native tick (J3): the `SliceCtx` pause checks already count rows
  (`operators.h:65-75`, `:289-310`) — accumulate per rule when choice
  rules go native.
- Btree caveat: interior nodes store **no subtree sizes** (tlx), so a
  bound-prefix cardinality costs O(rows scanned) — there is no O(log n)
  range count. Any prefix probe must be budget-capped; this is why the
  measurement primitive is tick-budgeted execution, not "count the range".

### Phased roadmap (statuses as of 2026-08-21)

- **SHIPPED — J1 (`e08af3b`), J2 (`7550680`), J2b-as-V3 (`60b727f`)**:
  see "As built" above.  J2b shipped as per-iteration emission-free
  probing rather than counts-with-hysteresis — the probe subsumes the
  counts signal for tail arms (which always tie on counts) and needs no
  hysteresis at current budgets (≤ ~74k meter per group-iteration worst
  case, negligible against any real iteration).
- **SHIPPED — V4, the R5 tripwire + R1 rescue** (see "As built"): gated
  by `card_probe_blind`/`card_probe_late`/`card_probe_rate` at ≤3× their
  oracles in `bench/card-study.sh`.  Counted flavors carry no arms, so
  the R1 boundary-only restriction is currently vacuous by construction;
  it binds when flavor-uniform arms arrive.
- **SHIPPED — the index-policy knobs** (`SLOG_MULTIPLAN_INDEX`; see the
  index-cost finding above).  Lazy materialization remains the follow-on.
- **SHIPPED — J3 phases 1 + 1b: native dominant-arm promotion.**  Phase 1
  (`SLOG_NATIVE_ARM=n`, job-hashed): a named arm competes for native
  coverage under the ordinary tier policy; at attach a group whose arm's
  ordinal the native artifact covers PINS (`ArmGroup::pinned`) -- the
  native task runs unconditionally, the interp siblings are the
  permanently gated complement, selection/tripwire freeze (promotion's
  premise: selection converged).  Codegen hazard fixed en route: emit-cpp
  kind consumers treat truthy kinds as COUNT kinds, so arm kinds read as
  #f there.  Measured (`bench/card_native.slog`, a live head-fed 14-prim
  compute chain): the walk stratum 1139 → 456 ms (2.5×); study gate ≥1.2×
  on summed fixpoint.  Phase 1b (the profile loop): the daemon emits a
  per-fixpoint `(arms (g GID ARM CONVERGED "LOC") ...)` report; runslog
  records CONVERGED picks into the arm-advisory sidecar
  (`compiler/arm-profile.rkt`, `build/profile/arms.rktd`, keyed
  (loc, gid)); the next compile applies them in tier-policy and folds the
  program-relevant advisory set into the job hash (PGO semantics -- one
  recompile per new advisory, stable thereafter).  **Convergence** =
  pinned, or ≥4 epochs selected with zero pick changes AND ZERO RESCUES —
  the rescue is task-local and invisible to pick counters, so without the
  rescues guard a probe-blind group could converge onto an arm whose
  monster the rescue was saving it from, and pinning would disable the
  rescue.  Advisories are correctness-safe by construction (they can only
  name a valid sibling arm) and performance-risky exactly like the tier
  profile's cross-program sharing: opposite-skew datasets must not share
  a profile.  Escapes: delete the store, `SLOG_NO_ARM_ADVISORIES=1`, or
  the explicit `SLOG_NATIVE_ARM` (wins outright).  Known limitation:
  closed-rule groups select once per run and never reach 4 epochs, so
  they are never advised — cross-RUN stability accounting is the noted
  refinement.  Still pending: phase 2 (native tick accumulation:
  $stat_work parity + tripwire on pinned rules), phase 3 (native rescue,
  evidence-gated).
- **J3 — native tier for choice rules** (unchanged shape: dominant-arm
  or K×-cluster; requires the native tick accumulator for tripwire
  parity).
- **J0 — size-blind robustness (compiler-only, partially landed;
  deprioritized).**  With runtime selection shipped, the static-score
  fixes matter mainly for flag-off users; the const-bait case is
  handled by the selector (bait picks a 100-row driver), and the
  dem_lambda history shows the static score cannot distinguish a
  selective constant probe from a bait without data.
  S1/S1b (`e63ca3a`) fixed the compute cliff and profile-distinguishable
  expand ties *inside the searched world*; S2/S3 (`6c26f46`, `bd23002`)
  degraded the cap cliff and added gated fragment factoring.  Still open
  in principle: the scalar/greedy driver score, FD/key-aware preference
  (option 3), and the tie polarity (option 4).

Every phase lands behind the card-study gate (`CARD_ASSERT=1
bench/card-study.sh` covers the static ratios AND the selection
ratios); targeted batteries per phase, full suite at arc end per the
standing test discipline.

### The cardsel blowup suite (BUILT and measured 2026-08-20)

`bench/card_*.slog` + `bench/card-study.sh` — twelve **self-generating**
programs (stratum 0 builds the pathological data with `(+ x 1)`-style
rules; no external DBs, no generator script), each pathological program
paired with an oracle twin computing the byte-identical answer. **Not in
any default battery**; `CARD_ASSERT=1` enforces the ratio gates. Measured
at HEAD `bd23002`, interp tier, 8-thread dev machine (query-stratum ms):

| case | bad | oracle | gap | gates |
|---|---:|---:|---:|---|
| `card_bait` (vs `_good`) | 4148 | 1154 | 3.6× wall, ~30× ops | J0 / any size-awareness |
| `card_skew_a` vs `_a_good` (spelling) | 5480 | 16.1 | **340×** | J2 counts |
| `card_skew_a` vs `_b` (same plan, mirrored data) | 5480 | 22.3 | **246×** | the impossibility proof |
| `card_corr` (vs `_good`) | 9479 | 93.1 | **102×** | J2's entry measurement |
| `card_flip_ac`/`_ca` vs `_oracle` | 69446 / 85350 | 2071 | 34× / 41× | J2b tripwire + re-measure |
| `card_monster_ac` vs `_ca` | 38810 | 74.2 | **523×** | mid-subtree rescue (R1) |

What each case proves:

1. **`card_bait`** — the literal `(foo x)(bar x 7 y)(baz x y w)(boo y)`
   shape: the constant-bound column wins the driver score, the plan scans
   the 9M-row `bar` and checks `foo` per row, and **no spelling fixes it**
   (the score is source-order independent). Linear class — the op-ratio is
   ~30× but both twins share a ~1.1s stratum-setup floor over the 18M-row
   relations, so the wall ratio understates it; on a real billion-row
   relation the absolute cost is the story.
2. **`card_skew`** — congruent all-binary endpoints (dead second columns
   keep every candidate's profile tied) fall to the occurrence-id
   tie-break. `_a` vs `_a_good`: same data, reversed spelling, 340×.
   `_a` vs `_b`: **byte-identical rule text — one compiled plan — over
   opposite-skew datasets, 246× apart.** No static planner can be right
   for both; counts (|fa| vs |fb| = 10 vs 100k) separate trivially.
3. **`card_corr`** — same rule text as skew, but **every count-level
   signal ties**: |fa|=|fb|, |m|=|n|, identical distinct counts and
   fanout histograms in both directions (each relation = a 50k identity
   strip + one 1000×1000 block). Only block *composition* (m's output
   range = n's input range) makes drive-from-fb chain block-into-block for
   ~10⁹ probes. A counts-only selector flips a coin here; bounded entry
   measurement separates 102× immediately.
4. **`card_flip`** — a 200-iteration recursive walk carrying the choice
   join inside the recursion; the profitable tail order flips at
   iteration 100. Relation sizes and the per-iteration delta (1 row) are
   **constant across the flip** — counts cannot see it at any granularity,
   and no static tail wins (each spelling pays ~10⁹ probes in one phase).
   Only the tripwire + re-measurement gets the oracle's 2.1s.
5. **`card_monster`** — a two-entry recursive rule where iteration 42
   hangs a 5000×40×5000 wing off one entry: ~10⁹ probes inside **one
   driver tuple's subtree** (work ≫ every relation's size; blocks are
   200k rows), the other entry ~4 ops. Entry measurement cannot see it
   (iteration-specific); driver-boundary switching cannot rescue it (the
   delta is one row). This is the case that justifies R1's mid-subtree
   rescue for set flavors.

**Planner findings made while constructing the suite (worth keeping):**

- The post-S1b candidate ladder, observed: expand-count → driver
  `join-score` → free-seq profile → expand positions → occurrence id
  (drivers: last-written wins ties; tail ties follow source order).
- **join3 chaining genuinely defuses naive blowup shapes.** Two earlier
  drafts of flip/monster were rescued by the planner: a 2-step tail whose
  last step closes a cycle with a bound-prefix arm became a leapfrog
  intersection, and a 4-chain with selective ends got both ends bound
  first and the middle closed by `join3` on the shared variable. The
  suite defeats this only via the documented arm-kind cliff (payload
  columns break key-simple eligibility) — i.e. these tests also pin the
  boundary of what static WCOJ covers, and anything inside that boundary
  should stay the planner's job, not the selector's.
- Calibration: interp aggregate probe/visit rate on these shapes ≈ 0.4G
  ops/s (matches the bowtie study's O2 figure); per-stratum `(fixpoint)`
  ms includes frame setup (~1.1s at 18M rows, ~80ms at 2M) — ratio gates
  for linear-class cases must budget for that floor.
- **`$stat_fires` is blind to every one of these blowups** (`card_monster`
  fires exactly once at iteration 42) — probes without fires are invisible
  today. The tripwire tick is the missing observable, independent of its
  control role.

### Open design questions (updated 2026-08-20)

- **ANSWERED — signature form:** ĉ = measured ticks per driver row from
  the bounded probe, not a static cost formula. Counts remain the cheap
  screen; the fanout upgrade (per-index distinct-leading counters,
  maintainable O(1) at insert) is an optional refinement, not a
  prerequisite.
- **ANSWERED — hysteresis and persistence:** R5's ratchet; R4's
  reset-on-restart.
- **ANSWERED — selector placement/cost and native budget:** unchanged from
  the 2026-08-15 refinement (entry reads ride a paid seam; choice rules
  ship interp-only until J3).
- **OPEN — native tick accumulation shape:** per-rule counter placement in
  generated C++ (J3-era; small).
- **OPEN — entry-measurement parallelization:** the entry pass is
  single-threaded and bounded (K·B ticks per flagged rule); parallelize as
  read tasks only if a large program shows it on a profile.
- **OPEN — J3 shape:** `(ordinal, arm)` coverage vs K×-cluster selector
  branch (unchanged).

### Relationship to the options above

This is the concrete, recompile-free realization of options (1) and (2):
size-aware ordering without the bind-time replan, by moving the size read
to run time and pre-paying the alternatives into the cached artifact — and
the measurement layer covers the correlation/drift cases (options 1–2 can
never see them from per-relation statistics at all, as `card_corr` proves
constructively). Options (3) (FD/key-aware) and (4) (tie-break) are J0 —
they improve the structural default order each candidate starts from and
reduce how often a choice group is even needed.

## Files

- Failing examples: `bench/path_driver.slog`, `bench/star_driver.slog` and
  `_good` twins (`bench/gen.py`); the cardsel suite `bench/card_bait*.slog`,
  `bench/card_skew_*.slog`, `bench/card_corr*.slog`,
  `bench/card_flip_*.slog`, `bench/card_monster_*.slog`, and the XFAIL
  `bench/card_probe_blind.slog`; harness `bench/card-study.sh` (opt-in;
  `CARD_ASSERT=1` gates static ratios AND selection ratios).
- Shipped selection machinery (V0–V3): compiler — `multiplan-enabled`
  (`params.rkt`; job-hashed in `compile.rkt`), arm generation + gid mint
  (`join-planning.rkt`, `#:banned-first` in `schedule-body-actions`), arm
  marks (`ir-shared.rkt` `arm-mark!`/`planned-rule-arm`, transferred
  across `globalize-constants`), kind vocabulary (`ir-stack.rkt`),
  `(attrs (arm n gid))` emission (`canonical-plan.rkt`), native exclusion
  (`tier-policy.rkt`); daemon — attrs decode + re-application
  (`plan.cpp`), `ArmGroup`/`currentPick`/`selectPick`/`probe_arm_meter` +
  `make_probe_execution` + `NullSink` + the task gate (`plan.h`),
  `read_epoch` + `deltaLiveCount` (`database.h`), group wiring
  (`plan-count.cpp` `attach_normal_rules`).
- Knobs: `SLOG_MULTIPLAN`, `SLOG_MULTIPLAN_INDEX=eager|free|budget:N`
  (compile-time, job-hashed); `SLOG_MEASURE_BUDGET` (runtime, default
  4096), `SLOG_TRIP_FLOOR` (1e6) / `SLOG_TRIP_K` (8), `SLOG_FORCE_ARM`
  (runtime test hook), `SLOG_NO_RESCUE`, `SLOG_ARM_DEBUG` — runtime
  knobs never enter any cache key.
- Batteries: `tests/multiplan-tests.sh` (18 checks) over
  `tests/multiplan/{flip_mini,skew_mini_a,skew_mini_b,corr_mini}.slog` —
  always-on, fast; the full-scale study stays opt-in.
- Planner: `compiler/join-planning.rkt` (`join-score:991`,
  `best-occurrence:1009`, `schedule-body-actions:1182`; candidate
  enumeration `:756-784`, retention seam `:845-848`, ordinal-bound views
  `:589-592`); weights `compiler/params.rkt`; toggles `SLOG_NO_WCOJ3`,
  `SLOG_NO_SEMIJOIN`.
- Cardinality-aware precedent: `compiler/query-plan.rkt` (`estimate-probe`,
  `best-probe-choice`).
- Daemon selection seams: `daemon/database.h` — `runLoop:6419`,
  `continueStratum:6536`, `EndIterCompletion:9435`, `tupleCount:1924`,
  `abortReadAttempt:5074` / `abortObstacle:5005`, `publishStratumStats`;
  `daemon/plan.cpp` — `decode_rule:466`; `daemon/plan.h` —
  `seal_rule:555`, `make_execution:2314`, `attach:2481`, fire identity
  `:1850-1870`; `daemon/plan-count.cpp` — partial coverage `:989`, `:2035`.
- Daemon measurement seams: `daemon/interp.h` — `WorkBudget::tick:200-209`
  (per-row tick `:302`), `Attempt:544-555`, `need_driver:723-735`;
  `daemon/plan.h:2425-2479` (task work loop, flush-and-park, fires merge
  `:2444-2454`); `daemon/query.h:23` + `daemon/query.cpp:1032-1078`
  (counting sink); `daemon/operators.h:537-551` + `daemon/database.h:737-745`
  (why emitted work is unrecallable); `daemon/operators.h:65-75`, `:289-310`
  (native slice ticks); `Relation::addIndex` backfill `database.h:1784-1848`
  (lazy index lifecycle).
- Cache keys: `compiler/compile.rkt:229-251` (settings block `:236-250`),
  `compiler/tools.rkt:1095` (`o-cache-key`).
- Nondeterminism doctrine + replay: `docs/db-compression.md:160-178`,
  `:291-293`, `:496-535`; flavor-uniformity doctrine
  `docs/incremental.md` §8B.3.
