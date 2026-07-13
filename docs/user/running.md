# Running Slog

The main entry point is a Racket program:

```console
$ racket slog.rkt [options] program.slog
```

Run it from the repository root. The current build and database drivers use
repository-relative paths for `compiler/`, `daemon/`, `lib/`, `build/`, and
`data/`.

## Requirements

Slog needs:

- Racket and its `sha` package
- GNU Make
- Clang with C++20 support
- OpenMP matching that Clang installation
- Boost headers
- zlib development headers and library
- GMP development headers and library

On Debian and Ubuntu the package names are typically:

```console
$ sudo apt install racket make clang libomp-dev libboost-dev zlib1g-dev libgmp-dev
$ raco pkg install sha
```

Package names differ on other systems. Slog's build scripts invoke `clang++`
and link OpenMP, zlib, and GMP, so a compiler found under another name may
need the repository's build settings adjusted.

`systemd-run --user` is optional. When available, the launcher uses it for a
hard cgroup memory limit. Without it, Slog warns and starts the daemon
directly with only its graceful in-process limit.

Z3 and cvc5 are optional. They are only needed for symbolic SMT solving; the
default mock backend handles supported ground formulas without a subprocess.

## What a run does

For a normal source run, the front end:

1. loads configuration;
2. parses included and prerequisite modules;
3. desugars demand calls, patterns, and collection syntax;
4. type-checks, stratifies, plans, and lowers the rules;
5. emits and compiles one native plugin per stratum;
6. starts the daemon and sends those plugins in dependency order;
7. drives every stratum to a fixpoint;
8. optionally reports sizes, writes CSV, or saves a binary database.

The daemon executable is rebuilt with `make -C daemon` when it is missing or
older than a daemon source/header. Generated rule code is cached under
`build/`. The default `tiered` mode starts with a quick `-O0` plugin and builds
an `-O2` replacement in the background.

## Command-line options

### General output

| Option | Meaning |
|---|---|
| `--no-banner` | suppress the startup banner |
| `--version` | print the Slog version and exit; the current parser still expects the positional command shape |
| `-v`, `--verbose` | print paths and driver progress details |
| `--sizes` | print `(relation_size NAME COUNT)` after the run |
| `--debug-dir DIR` | create `DIR` and write nonempty relations as `.csv` files |

The `.csv` files are space-separated runtime renderings. Strings remain
quoted, structures use constructor syntax, and lists use brackets. Relations
are sets and output order is not stable; sort files before comparing them.

`--debug-dir` also includes daemon-owned `$stat_*.csv` diagnostics unless
statistics publication is disabled.

### Loading and saving databases

| Option | Meaning |
|---|---|
| `-d NAME`, `--db-name NAME` | load `data/NAME/` before running the program |
| `--out-db NAME` | write an exact final database to `data/NAME/` |
| `--out-db-compressed NAME` | write a linked recompute-on-load database |
| `--per N` | retain fraction `0 < N <= 1`, or percentage `N > 1`, for a compressed save |
| `--flatten` | with a compressed save, write a self-contained exact root without replay metadata |
| `--bias uniform` | uniform compressed sampling; this is the default behavior |
| `--bias productivity` | retain more rows from relations read by rules, up to twice the base rate |
| `--strict` | turn a compressed replay signature drift warning into an error |
| `--reoptimise` | force cached strata to be emitted again during compressed load |
| `--force` | overwrite a save target even when another database references it; dependents become stale |

`--per 0.6` and `--per 60` both mean 60 percent. Values above 100 percent are
clamped to full retention. If omitted, Slog chooses a retention fraction from
measured replay cost.

Database behavior is covered in [persistent databases](databases.md).

## Practical output checks

Start with counts:

```console
$ racket slog.rkt --no-banner --sizes analysis.slog
```

For a small test case, write all relations:

```console
$ racket slog.rkt --no-banner --debug-dir out/check analysis.slog
$ find out/check -maxdepth 1 -name '*.csv' -type f -print
$ LC_ALL=C sort out/check/result.csv
```

Empty relations normally have no CSV file, so a missing `bad.csv` can be the
expected success condition for an invariant relation. In scripts, distinguish
“expected empty” from “misspelled or undeclared” by checking compilation and
the `--sizes` output too.

Use small hand-checkable inputs before large ones. Good assertions to encode
as relations include:

- a result that must exist;
- a `bad` relation that must stay empty;
- pairs that should be equal after two different computations;
- expected cardinality for a tiny graph;
- runtime `(error E)` facts, which should usually stay empty.

## Fixpoint status and pauses

The daemon reports stratum progress as s-expressions. The normal driver keeps
issuing continuation actions after time-slice pauses and stops only at
fixpoint or a terminal failure. `SLOG_MAX_MS` and `SLOG_SLICE_MS` control the
budget of each continuation unit; they are responsiveness controls, not a
whole-program deadline.

The daemon has a graceful RSS limit. At that limit it pauses with reason
`memory`; the command-line driver reports an out-of-memory error instead of
continuing. When `systemd-run` is active, the cgroup's hard limit is set higher
so the graceful path has room to fire first.

A program can still run forever in a sequence of successful slices if it keeps
generating new values. Termination comes from the program's finite reachable
fact space or finite-height lattice argument, not from the rule syntax.

## Runtime errors

Slog distinguishes several failure kinds:

- A parse, type, stratification, or lattice-soundness error stops before the
  affected program runs.
- A recoverable primitive failure emits a built-in `(error E)` fact, abandons
  that deduction, and normally lets the fixpoint continue.
- A partial primitive miss abandons a match without an error.
- A memory pause stops the command-line run cleanly.
- An internal invariant failure or corrupt database may stop the daemon.

After each stratum, the normal driver dumps new `error` facts and prints a
warning for each distinct one. Programs may also consume them:

```slog
table (division_problem any)
rule (error (div_by_zero Location Numerator))
  --> (division_problem Numerator)
```

See [built-in errors](builtins.md#errors-and-partial-operations) for every
shape.

The command-line entry point uses exit code 1 for a missing source file and 2
for normal front-end/runtime failures. A process killed by the OS or cgroup can
have a different shell status.

## Configuration

Slog configuration is itself a Slog program.

- `config/default-config.slog` is tracked and supplies shipped defaults.
- `config/config.slog` is an optional local, gitignored replacement.
- `config/system.slog` is generated from detected cores and RAM.
- `config/cache/` stores the computed settings database by content hash.

To override a few settings, create `config/config.slog`:

```slog
include "default-config.slog"

rule
(override_int "threads" 4)
(override_int "build_jobs" 2)
(override_str "opt" "2")
```

Do not edit the tracked default file for local tuning. There is no pre-created
`config/config.slog`; make it only when you need overrides.

Precedence is:

```text
command line or explicit SLOG_* environment variable
    > config/config.slog
    > config/default-config.slog
    > built-in code default
```

An explicitly set environment variable is never overwritten by config. Set
`SLOG_NO_CONFIG=1` to skip the config program and use environment/code
defaults.

### Config-mapped settings

| Setting | Environment variable | Shipped/code default |
|---|---|---|
| `threads` | `SLOG_THREADS` | detected cores minus one, at least one |
| `build_jobs` | `SLOG_BUILD_JOBS` | detected core count |
| `opt` | `SLOG_OPT` | `tiered` |
| `o2_reclaim_secs` | `SLOG_O2_RECLAIM_SECS` | 900 |
| `o_cache_max_age_days` | `SLOG_O_CACHE_MAX_AGE_DAYS` | 4 |
| `o_cache_max_mb` | `SLOG_O_CACHE_MAX_MB` | 768 |
| `max_ms` | `SLOG_MAX_MS` | 8000 in shipped config |
| `slice_ms` | `SLOG_SLICE_MS` | 500 in shipped config |
| `mem_max` | `SLOG_MEM_MAX` | `4G` |
| `mem_bytes` | `SLOG_MEM_BYTES` | about 90% of `mem_max` when parseable |
| `smt_solvers` | `SLOG_SMT_SOLVERS` | `mock` |
| `oracle_procs` | `SLOG_ORACLE_PROCS` | 4 |
| `mpz_max_bits` | `SLOG_MPZ_MAX_BITS` | 65536 bits per value |
| `mpz_table_bytes` | `SLOG_MPZ_TABLE_BYTES` | 1 GiB approximate total |

Setting names and string values cannot contain spaces because the computed
settings are read through space-separated CSV.

### Other useful environment switches

These are runtime/debug controls rather than config-program fields:

| Variable | Effect |
|---|---|
| `SLOG_NO_MEM_CAP=1` | do not wrap the daemon with `systemd-run` |
| `SLOG_NO_STATS=1` | suppress `$stat_*` relation publication |
| `SLOG_INLINE_MAX=N` | session inline batch limit per anchor/relation; default 2048 |
| `SLOG_NO_SEMIJOIN=1` | disable generated semijoin filters for diagnosis |
| `SLOG_DEBUG=1` | compile generated code with extra debug information |
| `SLOG_NO_FREEZE=1` | disable compiler freezing of ground facts |

Compression and performance work has additional experimental `SLOG_ACCEL_*`
and tracing variables. Treat those as implementation controls and consult the
corresponding design record under `docs/` before depending on them.

## Build cache and optimization

`SLOG_OPT` accepts:

- `0`: compile and run `-O0` plugins only;
- `2`: compile `-O2` before running;
- `tiered`: start with `-O0`, build cached `-O2` objects in the background,
  and swap at an iteration boundary.

The cache includes generated C++, daemon header fingerprints, optimization
level where relevant, and debug-code settings. Content-addressed objects live
under `build/o/` and are pruned by age and total size.

Do not normally delete the cache. If diagnosing a suspected stale artifact,
use a cold test run or remove the specific documented cache files rather than
assuming a compiler failure is a program error.

## Statistics

Three daemon-owned relations are currently published:

| Relation | Meaning |
|---|---|
| `$stat_fires` | rule instantiations before output deduplication, grouped by source location and generated variant |
| `$stat_fixpoint` | SCC/stratum iteration count and elapsed microseconds |
| `$stat_size` | relation sizes when CSV is written |

They appear in debug CSV output but are outside the language type environment,
excluded from binary saves, and ignored by golden comparison. Fire counts are
deterministic for a fixed compiled program and input; timing is not.

For ordinary tuning:

1. inspect relation and demand-answer sizes;
2. inspect fixpoint iteration counts;
3. find source rules with large fire counts;
4. check for compiler warnings about unkeyed recursive scans;
5. reduce accidental Cartesian products or overly broad demand inputs.

## Tests

The golden-output runner is:

```console
$ tests/run-tests.sh
```

Run selected programs without clearing the cache:

```console
$ tests/run-tests.sh --keep-cache tests/reach.slog tests/dem_chain.slog
```

`--update` rewrites expected output and should be used only when a behavior
change is intentional and reviewed.

The full test orchestrator is:

```console
$ tests/run-all.sh
```

Useful forms are:

```console
$ tests/run-all.sh --quick
$ tests/run-all.sh --list
$ tests/run-all.sh unit golden api
```

The full sequence includes Racket unit tests, diagnostics, runtime statistics,
C++ arena/sequence/count tests, goldens, API tests, tiered compilation,
pausing, sessions, compression, SMT pinning, and optional real-solver checks.
The real Z3 leg skips itself when Z3 is unavailable.
