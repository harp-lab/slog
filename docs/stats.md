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

## 6. Plan: tiers, new tables, and the naming migration (2026-07-11)

The v1 tables are a floor, not a ceiling.  A lot of the runtime's own
per-iteration bookkeeping is *already computed* and then discarded --
`$stat_fixpoint` keeps only the final `(iterations, µs)` pair, but the
per-iteration delta magnitude (it drives fixpoint detection) and the
per-iteration wall time (`ms_call`, surfaced today only on pauses --
`RunStatus`, database.h) are recomputed every round and thrown away.
The plan below surfaces the cheap ones and puts the expensive ones
behind a tier.

### 6.1 The two-axis doctrine every new stat obeys

1. **Where the counter lives** decides whether it costs a recompile:
   - *daemon-side* stats (timing, sizes, per-iteration delta, reorg
     counts, memory/RSS, interner/index metadata) publish at existing
     barriers with pure runtime gating -- **no codegen, not in the .so
     cache key**;
   - *codegen-side* counters (per-rule net-new/dedup, per-join probe
     counts, phase timing) hook the generated read task like the
     `_fires` counter and therefore **must be in the .so cache hash**
     (precedent: `SLOG_NO_SEMIJOIN` is in the key, `SLOG_OPT` is not).
2. **Determinism** decides testability: *deterministic counts* (fires,
   net-new, probes, per-iteration delta) are auditable -- two identical
   runs must match, `stats-tests.sh`-style -- and *resource metrics*
   (any wall time, RSS) are nondeterministic and join the
   golden-excluded set.  This mirrors the existing fires-vs-timing
   split; it is not a new category.

### 6.2 Tiers: `SLOG_STATS=off|basic|full` (default `basic`)

`SLOG_NO_STATS=1` remains as the hard off (kept for compatibility;
equivalent to `off`).  The counting increments stay live regardless; the
tier gates *publication and codegen*.

- **`off`** -- publish nothing.
- **`basic`** (default; = v1 behavior + the free daemon-side tables) --
  all publication is O(iterations) or O(dump), all counters O(1) per
  task.  Safe for production.  Adds to the v1 three:

  | table | columns | when | class |
  |---|---|---|---|
  | `stats.iter` | scc `int`, iteration `int`, delta-tuples `int`, µs `int` | each iteration | delta count = deterministic; µs = metric |
  | `stats.mem` | scc `int`, peak-rss `int`, total-tuples `int` | each fixpoint | metric (RSS from `/proc/self/status`, one read) |
  | `stats.interner` | strings `int`, struct-instances `int`, arena-nodes `int`, cnodes `int` | each fixpoint | the four id spaces (io-serialization); deterministic sizes |
  | `stats.index` | relation `str`, index-spec `str`, tuples `int` | at dump | deterministic; index/secondary inventory |

  (`stats.iter` and `stats.mem` are cheap enough to argue for
  always-on; leaving them tier-gated only to keep `basic` opt-in-able.)
- **`full`** (debug; participates in the cache hash) -- adds codegen-side
  counters:

  | table | columns | value |
  |---|---|---|
  | `stats.work` | rule-loc `str`, variant `str`, fires `int`, net-new `int` | fires:net-new = work amplification; net-new nearly free (emit sink already knows novelty) |
  | `stats.probes` | rule-loc `str`, variant `str`, probes `int`, matched `int` | quantifies the §4 unkeyed-scan warning |
  | `stats.phase` | scc `int`, iteration `int`, read-µs, write-µs, intern-µs, reorg-µs | where the time went; a few clock reads/iter |

### 6.3 Naming migration

v1 ships `$stat_fires`/`$stat_fixpoint`/`$stat_size`.  When real
namespaces land (docs/weaving.md §3) these become
`stats.fires`/`stats.fixpoint`/`stats.sizes` in the reserved,
non-persistent `stats` namespace, and the `$stat_`-prefix filter in
`writeDatabaseBIN` becomes a *namespace policy* ("`stats.*` is
ephemeral + golden-excluded") rather than a string prefix.  Until then,
new tables keep the `$stat_` prefix so they inherit the save/golden
exclusion for free.  The tables above are written with their eventual
`stats.` names to fix the target.

### 6.4 First slice (zero recompile, highest value)

`stats.iter` + `stats.mem`: both daemon-side, both answer the "how many
rounds, how big each, how much memory" question that recurs in
compression/seed-accelerator tuning (broom's 3009->6 rounds is a
`stats.iter` story) and mem-cap tuning (`SLOG_MEM_MAX`).  No codegen, no
cache-key change, no new test category -- the delta count is auditable
like fires, the µs/RSS ride the existing golden-exclusion.
