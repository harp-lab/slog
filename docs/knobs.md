# SLOG_* environment knobs — the index

One line per knob + where it's read and which doc owns it.  Rule of thumb:
knobs that change GENERATED artifacts are in the compile job hash (see
compile.rkt's key construction); everything else is runtime-only.
(2026-09-07, from the consistency audit's full inventory.)

## Plan/codegen-shaping (ALL in the job hash)

| knob | effect | doc |
|---|---|---|
| `SLOG_NO_SEMIJOIN` | disable Yannakakis exists-probes | semijoin-filters.md |
| `SLOG_NO_WCOJ3` | disable join3 planning | wcoj.md |
| `SLOG_NO_FRAGMENT_FACTOR` | disable cross-rule triangle factoring | static-join-decomposition.md |
| `SLOG_MULTIPLAN` | runtime-selected join arms | join-planning-assessment.md |
| `SLOG_MULTIPLAN_INDEX=eager\|free\|budget:N` | arm index-cost policy | join-planning-assessment.md |
| `SLOG_NATIVE_ARM` / `SLOG_NO_ARM_ADVISORIES` | native arm pin / PGO advisories (store content is fingerprinted into the hash) | join-planning-assessment.md |
| `SLOG_NATIVE_COVERAGE` | per-rule selective native emission | t4-contract.md |
| `SLOG_TIER_POLICY` | variant tier designation | t3b-contract.md |
| `SLOG_NO_FREEZE` / `SLOG_FREEZE_MIN` | ground-rule peel (keyed by content) | freeze.md |
| `SLOG_PLAN_ABI` | deliberately NOT keyed — TU text is ABI-invariant by construction; warm-cache flips don't regenerate old-ABI plans | rf1-contract.md |

## Toolchain / tiering (artifact-path or .o-key differentiated)

`SLOG_OPT` (0|2|interp; tiered default), `SLOG_DEBUG` (-g; in the .o key,
not the .so path — flipping over a warm build serves symbol-less
artifacts), `SLOG_FLAVORED_NATIVE` (the differential's native leg),
`SLOG_TIER_PROFILE`, `SLOG_TIER_SKIP_MS`/`PROMOTE_MS`/`PROMOTE_MULT`,
`SLOG_BUILD_JOBS`, `SLOG_CORES`, `SLOG_O2_RECLAIM_SECS`,
`SLOG_O_CACHE_MAX_AGE_DAYS`/`_MAX_MB` — fast-compile.md, t3b-contract.md.

## Daemon runtime

`SLOG_MAX_MS`, `SLOG_SLICE_MS`, `SLOG_MEM_BYTES` (RSS soft cap, default
3.75G), `SLOG_MEM_MAX` (systemd-run hard cap, default 4G),
**`SLOG_NO_MEM_CAP`** (skip the systemd-run wrap entirely — set by ~19
test harnesses; previously documented nowhere), `SLOG_THREADS`,
`SLOG_NO_STATS` (stats.md; `SLOG_STATS=off|basic|full` is future),
`SLOG_MPZ_MAX_BITS`/`_TABLE_BYTES`, `SLOG_ACCEL`(+`_RATE`/`_QUOTA`/`_MB`/
`_MIN_ROUNDS`) (db-compression.md §4.4), `SLOG_SMT_SOLVERS` /
`SLOG_ORACLE_PROCS` (smt.md §8), `SLOG_NO_INDEX_REUSE` /
`SLOG_BOUNDARY_DEBUG` (index-reuse.md), `SLOG_NO_RESCUE` /
`SLOG_NO_NATIVE_RESCUE` / `SLOG_TRIP_FLOOR` / `SLOG_TRIP_K` /
`SLOG_MEASURE_BUDGET` / `SLOG_ARM_DEBUG` / `SLOG_FORCE_ARM`
(join-planning-assessment.md — NOTE `SLOG_FORCE_ARM` set-but-EMPTY forces
arm 0: `atoi("")`).

## Session / REPL / debug

**`SLOG_INLINE_MAX`** (inline-fact transport threshold, default 2048 —
session.rkt), **`SLOG_ROOT`** (repl backend override for the checkout
root), `SLOG_REPL_TOKEN` (set by the client, not for users),
`SLOG_N4_RESTORE_REVERSE`, `SLOG_EMIT_PROGRAM_IMAGES` (rf5-contract.md),
`SLOG_DUMP_PROGSTR` / **`SLOG_DUMP_ABI2`** / **`SLOG_DEBUG_PARTITION`**
(compiler debug dumps — rf1-contract.md territory), `SLOG_TEST_JOBS`
(test-driver concurrency, run-tests.sh's own knob).
