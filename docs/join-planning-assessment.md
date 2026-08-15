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

**Status — DESIGN NOTE, UNDER DEVELOPMENT (2026-08-15). Not implemented.**
Recorded as a plan we expect to want soon and to de-risk with case studies
before building. The mechanism below is proposed; the numbers cited are from
the reproduced failures above, not from a built implementation.

### The idea

Compile a small set (K ≈ 2–3) of alternative join orders per size-sensitive
rule into the **same cached artifact**, and choose one **at run time** from
actual relation row counts — the same way a name-free kernel already attaches
to different relations at run time (T4's descriptor attach). This is
parametric / "choose-plan" optimization: for a non-recursive rule every valid
order computes the identical relation, so the runtime picks the cheapest with
no correctness risk.

It is the clean answer to the compile-time problem above: the alternatives
all derive from one program text, so the **cache key is unchanged** and there
is **no recompile when the DB changes**; the runtime just reads a row-count
per relation (which the daemon already has at rule entry) and picks. That is
categorically lighter than profiling a representative database.

### Mechanism sketch

- **Planner** — emit a *choice group* of K complete orders instead of a
  single argmax. Minimal version: drive-from-each-relation; the structural
  score already ranks candidates, so keep the top few.
- **Plan format** — a new variant kind: a *pick-one-by-cost* group, alongside
  the existing `all`/`delta` variants (which still all run, for semi-naive
  completeness).
- **Executor, both tiers** — at rule entry, evaluate a cheap size cost per
  candidate from the daemon's relation counts, pick one, run it. Interp:
  cheap (K plan entries + a comparison). Native: K× codegen for affected
  rules only.
- **Selector scope** — keep it to what row counts can decide: driver =
  smallest eligible relation (robust); coarse size-greedy tail. Finer choices
  want per-column distinct/selectivity, which counts alone do not give.

### Soundness and scope

- **Non-recursive rule** — pick the whole order once at rule entry. Fully
  sound (all orders equivalent).
- **Recursive / semi-naive rule** — the delta variants must all still run;
  the choice applies to the **tail order within each**, picked once at
  fixpoint entry from settled input/lower-stratum sizes. Sound, kills the
  tail blowup, but a *heuristic* for a relation that grows during its own
  fixpoint (entry-time sizes ≠ final sizes) — deliberately no per-iteration
  re-selection, to stay clear of dynamic profiling.
- **Determinism** — the artifact stays deterministic (same program → same K
  variants); the runtime pick is a deterministic function of the DB's sizes;
  correctness goldens are unaffected (all orders equal); only plan-*shape*
  goldens grow (re-record), and any per-variant fire-count stat becomes
  data-dependent.
- **Cost control** — emit alternatives only for size-sensitive rules
  (multi-relation, no key-bound / provably non-expanding driver);
  single-join and key-bound rules keep one plan, so the K× native codegen hits
  only the rules that need it. Gate behind an `SLOG_*` flag until proven.

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
   edge expansion) matters and depends on selectivity. Tail chosen once at
   fixpoint entry — a heuristic for the growing relation, still strictly
   better than a blind fixed order, still no profiling. This case study
   should quantify how much the entry-time heuristic leaves on the table
   versus an oracle, to decide whether recursive rules are worth the K×.

### Open design questions (the case studies should answer)

- **Candidate-set policy** — drive-from-each (N candidates) vs top-K
  structural vs FD-pruned. What K is enough? The reproduced examples need only
  *driver* robustness → K = #join relations, usually 2–4.
- **Native codegen budget** — is K× acceptable in general, or gated behind a
  flag until the case studies show the win? (Interp is cheap regardless.)
- **Selector placement / cost** — where the entry-time size lookup lives and
  its per-rule overhead.
- **Interaction with semijoin / WCOJ** — they ride *on top*; selection just
  gives them a better base order (a well-chosen driver, then the existing
  filters/`join3`), so they compose rather than compete.

### Relationship to the options above

This is the concrete, recompile-free realization of options (1) and (2) in
"General improvement options": it delivers size-aware ordering without the
bind-time replan, by moving the size read to run time and pre-paying the
alternatives into the cached artifact. Options (3) (FD/key-aware) and (4)
(tie-break) remain valuable *complements* — they improve the structural
default order each candidate starts from, and reduce how often a choice group
is even needed (a key-bound driver needs no alternatives).

## Files

- Failing examples: `bench/path_driver.slog`, `bench/path_driver_good.slog`,
  `bench/star_driver.slog`, `bench/star_driver_good.slog`; generators in
  `bench/gen.py` (`bench_pathdriver`, `bench_stardriver`).
- Planner: `compiler/join-planning.rkt` (`join-score:991`,
  `best-occurrence:1009`, `schedule-body-actions:1182`); weights
  `compiler/params.rkt:34-36`; toggles `SLOG_NO_WCOJ3`, `SLOG_NO_SEMIJOIN`.
- Cardinality-aware precedent: `compiler/query-plan.rkt` (`estimate-probe`,
  `best-probe-choice`).
