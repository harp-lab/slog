# Runtime statistics: the `$stat_*` tables, the fire audit, and the perf gate

2026-07-10.  Always-on runtime observability, designed as M0 preparation
for the incremental arc (docs/incremental.md §8) and as the standing
perf baseline ahead of DRed^c's hot-path changes.

## 1. The tables

Every run populates three daemon-owned relations (disable with
`SLOG_NO_STATS=1`; the counting itself is a task-local increment and
stays on):

| relation | columns | when |
|---|---|---|
| `$stat_fires` | rule-loc `str`, variant `str`, count `int` | each stratum fixpoint |
| `$stat_fixpoint` | scc `int`, stratum `str`, iterations `int`, microseconds `int` | each stratum fixpoint |
| `$stat_size` | relation `str`, tuples `int` | at CSV dump (sizes as-of dump; `$stat_*` themselves skipped, `$seq_*`/`$sup*` machinery included) |

They appear in `--debug-dir` CSV dumps like any non-empty relation and
are readable by api actions (`lookup`).  They are **daemon-owned
diagnostics**, deliberately outside the language and the persistence
formats:

- **not declared** in any program's type environment — no rules can read
  them (in-language joins would raise stratification questions; a
  follow-up if wanted);
- **excluded from BIN saves** (`writeDatabaseBIN`'s keep filter): timing
  rows are nondeterministic and would break compression replay/verify
  drift checks and db-merge determinism;
- **excluded from golden comparison** (`run-tests.sh` and api-tests skip
  `$stat_*.csv`).

## 2. Fire counts and the exact-once audit (M0 prep)

`$stat_fires` counts rule **instantiations**: one per satisfying body
assignment, pre-dedup; a multi-head rule counts once.  The generated
read task increments a local `u64 _fires` in its innermost continuation
and flushes via `Database::bumpFires(loc, variant, n)` before both exits
(completion and slice-pause), so paused/resumed invocations accumulate
correctly.  The variant tag is the task's driver reading —
`delta:<rel>` / `all:<rel>` / `once` — and every generated rule carries
its host's source location, so ask rules, supplementary rules, and the
main rule of one source rule share a `rule-loc` and are distinguished by
variant.  Same-(loc, variant) tasks merge; per-loc totals are the unit
of the audit.

**Why this is the M0 observable** (docs/incremental.md §8): under
correct per-position delta partitioning, semi-naive evaluation fires
each instantiation *exactly once* — so per-rule totals equal the
instantiation count, a number that can be computed by hand for small
programs.  Under set semantics a double-fire is absorbed by dedup and
invisible; under DRed^c counting it permanently corrupts counters.
These counters make the property visible *before* counting semantics
exist.

`tests/stats-tests.sh` asserts it two ways for each `tests/stat_*.slog`:

1. **hand-verified goldens** (`tests/stats-expected/<name>.fires`): each
   program's header derives its expected counts combinatorially
   (`stat_chain`: 4 copy fires + 6 transitive fires on a 4-edge chain;
   `stat_dem`: a demand chain where the step rule fires exactly once per
   demanded n>0 across all its variants — the partition property visible
   per-variant: the gate-delta variant fires 0, the answer-delta variant
   fires 3);
2. **determinism**: two identical runs must produce identical counts
   (per-iteration delta contents are deterministic under set semantics;
   a mismatch means a thread-schedule-dependent fire).

Planner temp relation names are gensym-per-compile and normalized
(`temp<N>`) in the comparison.  What v1 does **not** yet cover: the
reload-boundary refire case (iteration 0 with delta = a whole reloaded
database re-firing rules whose outputs already exist) — that needs
Phase 0's session/stratum-re-entry machinery and becomes the headline M0
test when it lands; the counters and harness here are built for it.

## 3. The perf-regression gate

`bench/regress.sh` runs a fixed benchmark set spanning the shapes DRed^c
will stress — the deterministic-split partition idiom
(supplementary-keyed answer joins), the sequential fold (long delta
chains), the r7rs demand interpreter (struct-recursion resumes), and
0cfa — and asserts against `bench/regress/baselines.tsv`:

- per-stratum **iteration counts match exactly** (deterministic,
  machine-independent; extra rounds = new lag or refires, fewer =
  something stopped firing);
- **total runtime** within `REGRESS_BUDGET`× baseline (default 2.0;
  baselines are machine-local — re-run `--update` on a new machine).

Re-baseline only after intentional changes, and say why in the commit.

## 4. The unkeyed-scan warning

Compile-time companion (emit-cpp): a delta variant of a recursive rule
that joins a co-recursive relation with **no bound column** re-scans it
every iteration — the computed-key shape whose demand-rule instances the
supplementary transform fixes (docs/demand.md §5).  The warning names
the rule and the scanned relation, once per site.  Demand-machinery
drivers (`*_ans`, `$`-synthesized) are exempt: their residual scans are
the semantically-required broadcasts (a constant-key judgment's answer
joins every caller by design).

## 5. Implementation map

- `daemon/database.h` — `bumpFires`, `ensureStatsRelation`, `statsRows`
  (materialize-immediately: the `loadDatabaseBIN` discipline, so output
  actions after the final stratum see rows without a reload),
  `publishStratumStats`, `publishSizeStats` (called by
  `writeDatabaseCSV`), and the `$stat_` exclusion in
  `writeDatabaseBIN`'s keep filter.
- `daemon/daemon.h` — `continueRun` publishes at each stratum fixpoint.
- `compiler/emit-cpp.rkt` — `_fires` counter + flush in every read task;
  the unkeyed-scan warning.
- `tests/stats-tests.sh`, `tests/stat_*.slog`,
  `tests/stats-expected/` — the audit.
- `bench/regress.sh`, `bench/regress/` — the gate.
