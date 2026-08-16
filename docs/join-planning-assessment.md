# Join-planning assessment (2026-08-15)

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
data via `bench/gen.py` (`bench_pathdriver`, `bench_stardriver`).

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
  cached order is optimal for at most one of them.
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

**Net:** nothing in the suite would fail if the planner regressed to a bad
join order on a large KG.

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
- **Add an order-quality gate.** Wire the `bench/*_driver.slog` shapes (and
  the existing skewed bench shapes) into a test that asserts a *ratio*
  bound (bad-spelling / good-spelling within k×), so a future regression to
  a data-blind order fails loudly — the coverage hole that let this exist.

## Proposed direction: runtime plan selection by cardinality

**Status — DESIGN NOTE, UNDER DEVELOPMENT. Not implemented.**
First pass 2026-08-15 (mechanism sketch, case studies). Refined the same
day: compiler and daemon anchor points verified in-tree, the racing
alternative assessed and rejected as a control mechanism, phased roadmap
adopted. Numbers cited are from the reproduced failures above, not from a
built implementation.

### The idea

Compile a small set (K ≈ 2–3) of alternative join orders per
size-sensitive rule into the **same cached artifact**, and choose one **at
run time** from actual relation row counts. Every valid order of a rule
computes the identical instantiation set, so the runtime picks the
cheapest with no correctness risk; the alternatives all derive from one
program text, so the **cache key is unchanged** and there is **no
recompile when the DB changes**.

Two verified compiler facts make this smaller than it sounds:

- **The candidates are already enumerated.** For closed/seeded rules the
  planner already builds one complete candidate order per legal driver
  (`enumerate-drivers?`, `join-planning.rkt:756-759`, capped by
  `wcoj3-search-cap`) and discards all but the argmax (`candidate-better?`
  sort, `:845-848`). Plan-set emission = retain top-K of a list the
  planner already constructs.
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
  must land before `BoundRule::attach` (`plan.h:2481`).
- **Dynamic (semi-naive) rules** — the delta versions all still run, one
  per dynamic join (`:776`); the choice is the **tail order within each
  version** (`schedule-body-actions:1182`; K tails = re-runs of the same
  scheduler under forced-first / size-greedy variation). The driver — and
  hence `task_count()` — is identical across arms, so the pick can be a
  per-rule index read in `make_execution` (`plan.h:2314`) and legally
  changed between iterations. Temp-driven versions keep their driver
  (temps have no indices, `:772`); only their tails are choosable.

### Why counts, not clocks — the racing alternative assessed

The other mechanism on the table was **plan racing**: every N iterations
run all K arms of a rule, keep whichever finishes first, drop the rest,
reuse the winner between races. Rejected as a *control* mechanism, on
grounded reasons:

1. **No cancellation primitive at the right granularity.** The only abort
   in the tree is `abortReadAttempt` (`database.h:5074`) — it discards the
   **entire read phase** (send shards, staged fires, harvest, proofs) and
   is restart-grade, initiated from outside over the protocol. Nothing
   cancels *one rule's* half-executed tasks inside a phase. Worse,
   admission (`abortObstacle:5005`) refuses the `count`/`maint*` flavors
   outright — the abort-based salvage is unavailable exactly where racing
   is unsound:
2. **Duplicate derivations under the counted flavors.** K arms racing over
   the same delta each derive every fact. Set semantics dedups; DRed^c
   derivation counts and the exact-once fire audit do not — the suite
   asserts *literal* fire counts (`tests/session-tests.sh:286-287`,
   `stats-tests.sh:95`, `t6-restart.sh:151`). A sound race must fully
   stage-and-abort every loser: a new per-rule transactional machine,
   built to obtain a signal counts deliver for free.
3. **The verdict is stale by construction.** A race measures relative cost
   on *this iteration's* delta; delta sizes swing across iterations, so
   the winner is out of date the moment it is crowned. Row counts are
   re-readable every iteration for the price of a comparison.
4. **Timing-as-control makes behavior load-dependent.** Nuance, verified:
   this would *not* break correctness gates — every arm computes the same
   logical fixpoint, and the byte image is already nondeterministic
   (struct ids are minted in encounter order; `db-compression.md:160-178`,
   `:496-503`; the comparison discipline is content-based throughout). But
   *which plan ran*, the work done, and the selection state would differ
   run to run and machine to machine: un-replayable performance,
   nondeterministic answers to "why was this run slow", a selector whose
   decisions cannot be reproduced from a bug report. Counts make the same
   class of decision deterministically.

Against those costs, racing's genuine edge over counts — it sees constant
factors (cache locality, index quality) a size model cannot — is
second-order next to the 100–260× order-of-growth wins counts capture.

**The salvageable core** (parked as phase J4 below, likely never needed):
if measured adaptation is ever wanted, measure **deterministic work
counters** (tuples probed/scanned per arm), collected by *alternating*
arms across iterations — never racing within one. Counters are pure
functions of the data, so everything stays reproducible.

### The determinism boundary

Design rule for every phase: **every control input to plan selection is a
pure function of database state** — row counts, work counters — never
wall-clock time. Time may be logged as a diagnostic; it is never consulted
for control.

One verified caveat: "deterministic function of DB state" is **not** the
same as "same arm chosen on replay". The accel seed reservoir injects
sampled tuples before replay (`accelRecordRound`, `database.h:7637`) and
flips the seeded task set on (`rs.seeded_run`, `:6556`), so entry-time
sizes on a seeded replay legitimately differ from the original run and the
selector may pick a different arm there. That is sound — arms are
logically equivalent, and replay re-fires every instantiation exactly once
regardless (`db-compression.md:291-293`) — but it means **gates must
assert content equality and `$stat_fires` equality, never arm identity.**

### Fire identity survives — with one structural constraint

Verified: nothing in the fire/stat path keys on plan bytes. The fire key
is `(loc, tag)` where `tag` strips the `#ordinal` suffix
(`plan.h:1850-1870`, the N5/stats-4 unification), and the base tag names
the **driver relation** (`canonical-plan.rkt:373-390`) — which the arms of
one version share. K alternative orders of a version land on the same fire
slot by existing design; the `#ordinal`-strip rule was written for exactly
this shape.

The constraint that shapes the plan format: **a choice group must be a
sub-structure inside ONE `rule-def`/crule, never K separate rule-defs.**
The scheduler runs every attached task unconditionally
(`runPhase`/`task_at`, `database.h:6358-6388`); K separate rule-defs would
all attach, all fire, multiply `$stat_fires` by K, and fail the exact-once
audit hard. One rule-def, K cursor ladders inside it, exactly one executed
per (version, iteration).

The chosen arm is published as a *diagnostic* (a column beside
`$stat_fixpoint` in `publishStratumStats`, `database.h:7258`) — never as
an identity input.

### Isolation inventory — what this must not touch, and why it doesn't

The arm is an execution detail **below fire identity**. Invariant: exactly
one arm of each rule-version executes per iteration. Above that line:

| feature | interaction | why safe |
|---|---|---|
| exact semi-naive + count/M4N/M4S/DRed^c | reordering inside a version | views bind to logical ordinals pre-scheduling (`join-planning.rkt:589-592`); identical instantiations for any arm |
| exact-once fire audit / `$stat_fires` | fires from an arm | `(loc, tag)` key strips `#ordinal`; arms share the driver-named base tag; one-rule-def constraint above |
| lattices | order-sensitive merges | **excluded from choice groups initially**: an extern or float lattice merge is the one place order can change the *logical* result (`db-compression.md:512-535`) |
| RF5 activation (A2/A3 cone) | plan-set rides the program payload | arms of a rule have identical relation-level read/write sets → write-set narrowing, push filters, retirement unaffected; the plan-set swaps atomically with activation |
| plan/.so cache | key discipline | the *policy* (flag, K, candidate rule) joins the settings block of the job hash (`compile.rkt:236-250`, beside `semijoin-filters-enabled`); the runtime *pick* never enters any key (the `:839-841` "TU text must not fork on an env var" discipline); `o-cache-key` (`tools.rkt:1095`) is content-addressed and needs no change |
| tiered native (T3b/T4) | which arms exist natively | J1/J2: choice-group rules simply **leave native coverage** — T4 partial coverage runs the complement interpreted *by construction* (`attach_normal_rules(..., &covered)`, `plan-count.cpp:989`, `:2035`); no swap machinery involved. J3 decides between K×-in-cluster codegen with a selector branch and an `(ordinal, arm)` coverage axis |
| T6 executor swap | selection flip on a compiled rule | not a swap at all under the coverage route (the production ladder is monotone interp→O0→O2 and never daemon-initiated, `compile.rkt:1053-1055`); the T6 `readAbortedPristine` seam (`daemon.h:312`) exists if a mid-read flip is ever needed |
| plan goldens | .plan shape | flag off → arm 0 ≡ today's argmax, byte-identical; flag on → goldens grow choice groups and `#N` suffixing can flip (golden-visible, `$stat`-invisible); re-record sanctioned |
| semijoin / WCOJ | per-arm | applied within each candidate order; compose, don't compete |
| replay / compression | reproducibility | replay re-executes every instantiation exactly once; the selector is deterministic from DB state; seeded-replay caveat above (gates assert content + fires, not arm identity) |

### Where the hooks land (verified anchors)

Compiler — all inside the planner and the existing emission seam:

- Candidate retention: keep top-K at `join-planning.rkt:845-848`; K tail
  schedules per dynamic version via `schedule-body-actions:1182` re-runs.
- Choice node: inside one `rule-def` in the canonical plan
  (base-tag/`#N` grouping, `canonical-plan.rkt:373-390`). The `exec_key`
  changes — an expected new artifact identity, not a break (attachment
  audits carry reads/writes independently, `database.h:2521-2543`).
- Emission: `.plan` and native TUs both derive from the one `cprog`
  (`compile.rkt:842-871`); native ignores arms > 0 until J3.

Daemon — the "few driver hooks", now concrete:

- Decode: the body-op loop of `decode_rule` (`plan.cpp:585-686`) grows a
  `(choose (alt …) …)` form; unrecognized forms already degrade gracefully
  via `out.unsupported`, so old daemons refuse cleanly. Each arm seals
  through the existing `seal_rule` (`plan.h:555`) into its own cursor
  ladder (`SealedRule::cursors`, `plan.h:346`).
- Whole-order pick (closed/seeded): at stratum entry — the
  `continueStratum` `starting` block (`database.h:6541-6574`), which
  already pays for a registry-wide `totalTuples()` — before
  `BoundRule::attach`.
- Tail pick (dynamic versions): a per-rule current-arm atomic read in
  `make_execution` (`plan.h:2314`, the relation `frame` already in hand),
  recomputed once per iteration at `EndIterCompletion`
  (`database.h:9435`) — the existing single-threaded per-round hook that
  already hosts `accelRecordRound` and `rankRecordRound`.
- Sizes: `Relation::tupleCount()` (`database.h:1924`) — 32 O(1) btree
  size reads, no scan; from a bound rule, `frame[slot]->tupleCount()`.
  Live delta counts have **no O(1) source** (batch rows can be nulled in
  place): the cheapest exact form is summing the post-reorg `read_buckets`
  RefVec sizes (precedent: `accelRecordRound` pass 1, `:7653-7657`).
  **Not `$stat_*`** — `$stat_size` is a dump-time snapshot
  (`:7293-7306`), not a runtime oracle.

### Phased roadmap (bang-for-buck order)

- **J0 — size-blind robustness + the tripwire (compiler-only, small).**
  (i) Fix the tie-break (option 4) and prefer key-bound / provably
  non-expanding drivers (option 3) in `join-score`. No format change, no
  daemon change; kills the "spelling decides 100×" fragility before any
  size plumbing exists. (ii) Wire the `bench/*_driver` pairs into an
  asserted ratio gate (bad-spelling ≤ k× good-spelling) **first**, so
  every later phase has a tripwire. Re-record plan goldens (sanctioned).
- **J1 — plan-set emission (compiler-only, behind `SLOG_MULTIPLAN`).**
  Retain top-K candidates for closed/seeded rules; K=2 tails per dynamic
  version. Sensitivity gate: only multi-join rules with no key-bound
  driver and tied/near-tied scores get K>1 — and no lattice-merging rules
  — so most rules keep one plan. Arm 0 = today's argmax (flag off →
  byte-identical plans). Choice-group rules drop out of native coverage
  (interp-only entry — the `SLOG_PLAN_ABI` precedent).
- **J2 — the daemon selector (the one real daemon change).** Decode +
  seal arms; whole-order pick at stratum entry, tail pick at fixpoint
  entry stored per BoundRule; arm = argmin of a per-arm cost signature
  over `tupleCount()` reads. Chosen arm published as a diagnostic.
- **J2b — per-iteration tail reselection with hysteresis.** Recompute at
  `EndIterCompletion` from delta live-counts; switch only on an estimated
  ≥k× win (thrash guard). Still counts-only, still reproducible. This
  subsumes the useful part of "re-decide every N iterations" with none of
  racing's costs. (Revises the first draft's "no per-iteration
  re-selection" stance: the worry there was dynamic *profiling*; an O(K)
  count comparison at a seam that already hosts two per-round samplers is
  not profiling.)
- **J3 — native tier for choice rules.** Two candidate shapes, decided by
  profile data once J2 shows which choice rules stay hot: (a) K× codegen
  inside the covered rule's cluster with the selector branch in generated
  C++ (simple; bounded by the sensitivity gate), or (b) an
  `(ordinal, arm)` coverage axis compiling only the dominant arm
  (`crule-natively-covered?` is the single policy function either way).
  The policy knob joins the job-hash settings block.
- **J4 — measured adaptation (probably never).** Only if the case studies
  show counts mis-selecting: deterministic work counters, alternation
  across iterations, wall-clock never a control input.

Each phase lands behind the J0 ratio gate; targeted batteries per phase,
full suite at arc end per the standing test discipline.

### Motivating case studies (to develop before/with implementation)

Optimizations should be motivated by measured need, not asserted. Each case
below should become a runnable A/B (a bench pair + a size table + the expected
selector choice), so it doubles as the regression gate the coverage gap above
calls for (assert bad-spelling / good-spelling within k×). Ranked by how
cleanly each justifies the mechanism:

1. **Selective-seed reachability** — *acute, fixed outright, BUILT.* The
   "start from a small set and expand through a high-fan-out relation"
   pattern. `bench/path_driver.slog`: 380 ms vs 3 ms at N=8k (258× at N=16k),
   the driver flipping with clause order. The selector reads `sel=3`,
   `big1/big2=8000` and drives from `sel` regardless of spelling.
2. **Snowflake / star dimension join** — *acute, common on KGs, BUILT.* A
   central edge/fact relation joined to several dimension relations, one
   highly selective. `bench/star_driver.slog`: 417 ms vs 4.7 ms. *Which*
   dimension is selective depends on the query constants and the data — not
   knowable at compile time — so the driver must be chosen at run time.
3. **Same query, two graphs — the impossibility proof** — *the core
   justification, TO BUILD as a runnable A/B.* One program, two DBs with
   opposite skew (A small on KG1, B small on KG2). A single cached plan is
   optimal for at most one; runtime selection is the only fix. Partially
   demonstrated already (identical plan `abcd4fb4` over 21- vs 100k-tuple
   DBs); the A/B to build is the *opposite-skew flip* where the winning
   driver differs by DB.
4. **Recursive reachability tail order** — *the honest bounded case, TO
   BUILD.* Transitive closure joined with a selective filter: the delta
   variants all run, but the tail order (apply the filter before or after the
   edge expansion) matters and depends on selectivity. This case study should
   quantify entry-time-only (J2) against per-iteration reselection (J2b)
   against an oracle — it is the J2 → J2b decision, and it decides whether
   recursive rules are worth K>1 at all.

### Open design questions (updated)

- **ANSWERED — selector placement/cost:** the anchors above; entry-time
  reads ride an already-paid seam, per-iteration reads are
  `thread_count × 32` vector-size reads at `EndIterCompletion`.
- **ANSWERED — native codegen budget:** dissolved by the coverage route
  (J1 ships choice rules interp-only; J3 compiles at most the dominant arm,
  or a K× cluster bounded by the sensitivity gate).
- **NARROWED — candidate-set policy:** closed rules K = drive-eligible
  joins (usually 2–4); dynamic tails start at K=2 (structural argmax +
  size-greedy).
- **OPEN — signature form:** driver size alone, or driver size × a
  first-join fanout bound? Start minimal; case study 4 decides if more is
  needed.
- **OPEN — hysteresis constant k, and selection-state persistence:** does
  the last-chosen arm survive pause/resume and daemon restart? Position:
  it is reconstructible optimization state; reset-on-restart is acceptable
  and keeps it out of every snapshot format.
- **OPEN — J3 shape:** `(ordinal, arm)` coverage vs K×-cluster selector
  branch (see roadmap).

### Relationship to the options above

This is the concrete, recompile-free realization of options (1) and (2) in
"General improvement options": it delivers size-aware ordering without the
bind-time replan, by moving the size read to run time and pre-paying the
alternatives into the cached artifact. Options (3) (FD/key-aware) and (4)
(tie-break) are J0 — they improve the structural default order each
candidate starts from and reduce how often a choice group is even needed
(a key-bound driver needs no alternatives).

## Files

- Failing examples: `bench/path_driver.slog`, `bench/path_driver_good.slog`,
  `bench/star_driver.slog`, `bench/star_driver_good.slog`; generators in
  `bench/gen.py` (`bench_pathdriver`, `bench_stardriver`).
- Planner: `compiler/join-planning.rkt` (`join-score:991`,
  `best-occurrence:1009`, `schedule-body-actions:1182`; candidate
  enumeration `:756-784`, retention seam `:845-848`, ordinal-bound views
  `:589-592`); weights `compiler/params.rkt:34-36`; toggles
  `SLOG_NO_WCOJ3`, `SLOG_NO_SEMIJOIN`.
- Cardinality-aware precedent: `compiler/query-plan.rkt` (`estimate-probe`,
  `best-probe-choice`).
- Daemon seams: `daemon/database.h` — `runLoop:6419` (iteration loop
  `:6448`), `continueStratum:6536` (stratum entry `:6541`),
  `EndIterCompletion:9435`, `tupleCount:1924`,
  `abortReadAttempt:5074` / `abortObstacle:5005`,
  `publishStratumStats:7258`; `daemon/plan.cpp` — `decode_rule:466`
  (body ops `:585-686`), `bind_kernel_plan:2590`; `daemon/plan.h` —
  `seal_rule:555`, `SealedRule:342`, `make_execution:2314`,
  `attach:2481`, fire identity `:1850-1870`; `daemon/plan-count.cpp` —
  partial coverage `:989`, `:2035`.
- Cache keys: `compiler/compile.rkt:229-251` (settings block `:236-250`),
  `compiler/tools.rkt:1095` (`o-cache-key`).
- Nondeterminism doctrine + replay: `docs/db-compression.md:160-178`,
  `:291-293`, `:496-535`.
