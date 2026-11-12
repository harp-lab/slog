# SLOG_* environment knobs — the index

One line per knob + where it's read and which doc owns it.  Rule of thumb:
knobs that change GENERATED artifacts are in the compile job hash (see
compile.rkt's key construction); everything else is runtime-only.
(2026-09-07, from the consistency audit's full inventory.)

## Plan/codegen-shaping (ALL in the job hash)

Every knob in this table is also recorded, with its value, in a saved
database's META `env` alist (dbmeta.rkt `result-affecting-env`, 2026-09-08)
beside the `plan-stamp` — the human-readable half of the faithful-rebuild
identity.

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
`SLOG_AWAIT_BUILDS=1` makes `run.rkt` wait for the builds its run queued
before exiting (the tier harnesses set it; by default a run exits at once).

## Daemon runtime

`SLOG_MAX_MS`, `SLOG_SLICE_MS`, `SLOG_MEM_BYTES` (RSS soft cap, default
3.75G), `SLOG_MEM_MAX` (systemd-run hard cap, default 4G),
**`SLOG_NO_MEM_CAP`** (skip the systemd-run wrap entirely — set by ~19
test harnesses; previously documented nowhere), `SLOG_THREADS`,
`SLOG_NO_STATS` (stats.md; `SLOG_STATS=off|basic|full` is future),
**`SLOG_PHASE_TIMES`** (emit one `(phases <scc> "<name>" iters N write W join J
finalize F intern I reorg R end E endcomp C partition P freeze Z)` line after
each `(fixpoint ...)`: the
sentinel thread's wall milliseconds per iteration phase, summed over the
stratum -- write = previous delta inserted into the full indices, join =
read tasks minus finalize, finalize = shard merge into the new delta, intern
= delta dedup against the masters, reorg = delta bucketising, end = the
end-of-iteration barrier and its completion, endcomp = the completion body
alone, partition = the parallel pre-intern bucket partition and its barrier,
freeze = iteration 0's freeze of the read-only relations' indices into their
static form; also `(load "<rel>" read R ingest I)` per relation at database open and
`(mark "<what>" <ms since start>)` timeline marks -- open-done, reload-done,
push -- on stderr; 2026-09-10/11), **`SLOG_ITER_TRACE`**=1 (one `(iter <scc>
"<stratum>" <round> "<rel>" cand C new N master M)` line per relation per
round on stderr: candidates produced, survivors after dedup, master size;
2026-09-14), **`SLOG_DUMP_DELTA`**=`<dir>` (append every plain set relation's
un-deduplicated candidate rows per round to `<dir>/<rel>.bin` as blocks of
`u64 iteration, arity, rows` + rows*arity words -- the input of
`bench/master-sim/`, docs/run-master.md; 2026-09-14),
**`SLOG_EMIT_PROBE`** = `adaptive` (default) | `always` | `never`
(2026-09-10: emit-time dedup policy for set-semantics heads, both tiers.
`always` probes the head master for every candidate (the pre-09-10
behaviour); `never` sends every candidate to the delta and lets intern
dedup; `adaptive` samples 256 candidates per (task, head) and skips the
next 16384 probes unless at least 99 % were duplicates (intern's
bucket-local probe is cheaper than emit's, so the emit probe only pays for
itself by bounding transient delta memory at extreme duplicate rates).  Results are
identical under all three -- intern is the dedup of record; only the delta's
size and the probe count change.  stats.md §1.5), **`SLOG_SORTED_WRITE`** = `0` to disable (2026-09-11: write tasks gather
their bucket's rows, sort them, and bulk-load an empty index or insert in key
order; content is identical, only btree access order changes.  A sorted
INTERN was measured and rejected -- the sort cost three times what sorted
probing saved, since a bucket's master tree fits in cache -- so intern probes
in delta order, one descent per candidate, reading its bucket from the
parallel pre-intern partition; stats.md §1.5), **`SLOG_STATIC_INDEX`** = `0`
to disable (2026-09-12: after iteration 0's write phase every full ordering
of a relation the stratum reads but never writes is FROZEN into its static
form -- a directory of the bucket's distinct lead values plus one sorted
contiguous array, so a probe is a small directory search and a search inside
one lead group, range walks are pointer bumps, and the index is ~30 %
smaller -- and thaws back into a btree on the first mutation, so no caller
sees the difference.  Only buckets whose directory and groups stay
cache-resident freeze -- at most **`SLOG_STATIC_MAX_LEADS`** distinct lead
values per bucket (default 8192) and **`SLOG_STATIC_MAX_GROUP`** keys per
lead (default 256); a 5M-edge input over 2.5M nodes has 80K leads per bucket
and probed 0.75x as fast frozen, so it stays a tree.  Semantic to-fixpoint
runs only; measurement knobs, stats.md §1.5),
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
