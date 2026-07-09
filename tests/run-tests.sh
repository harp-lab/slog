#!/usr/bin/env bash
#
# Golden-output test runner for slog.
#
#   tests/run-tests.sh                  run every test against its golden outputs
#   tests/run-tests.sh --update         re-snapshot goldens from current behavior
#   tests/run-tests.sh --keep-cache     don't clear build/ first (faster, but stale
#                                       .so's can mask compiler changes: the cache
#                                       key covers program + daemon headers only)
#   tests/run-tests.sh tests/reach.slog examples/tinycfa/0cfa.slog   run a subset
#
# A test is a .slog program; its golden is tests/expected/<name>/ holding one
# sorted .csv per non-empty relation.  Row order out of the daemon depends on
# which index writeDatabaseCSV picks and on struct-id assignment order, so both
# sides are compared sorted (LC_ALL=C).

set -u
cd "$(dirname "$0")/.."

UPDATE=0
KEEP_CACHE=0
# Run tests concurrently (docs/fast-compile.md §7): each test has its own out
# dir, log, and daemon, and shares only the content-addressed build/ cache
# (writes are temp+atomic-rename, so concurrent builds of the same hash are
# safe).  Default a few in flight; override with -jN / --jobs N.
JOBS="${SLOG_TEST_JOBS:-4}"
TESTS=()
for arg in "$@"; do
  case "$arg" in
    --update)     UPDATE=1 ;;
    --keep-cache) KEEP_CACHE=1 ;;
    -j*)          JOBS="${arg#-j}" ;;
    --jobs)       ;;                 # value handled below
    [0-9]*)       JOBS="$arg" ;;     # bare number after --jobs
    *)            TESTS+=("$arg") ;;
  esac
done
[ -z "$JOBS" ] && JOBS=4

# Tests compile at -O0 (fast, no background -O2): correctness is
# optimization-independent, and -O0 runtime is fine at test scale.  A caller
# can still export SLOG_OPT=2 to exercise the optimized path.
export SLOG_OPT="${SLOG_OPT:-0}"

# Pin the SMT oracle to its deterministic mock backend (docs/smt.md) so the
# smt_* goldens never depend on an installed solver or the user's configured
# chain (config/config.slog could set smt_solvers).  The solver-path tests
# live in tests/smt-solver-tests.sh instead.
export SLOG_SMT_SOLVERS=mock

# Build the daemon ONCE up front so the concurrent tests below don't race
# `make` (each test's ensure-slogd-exists then finds it fresh and skips).
make -C daemon >/dev/null 2>&1 || { echo "daemon build failed"; exit 1; }

if [ ${#TESTS[@]} -eq 0 ]; then
  for t in tests/*.slog; do
    case "$t" in
      *_lib.slog|*_base.slog) ;;  # helper modules of multi-file tests
      *) TESTS+=("$t") ;;
    esac
  done
  TESTS+=("examples/tinycfa/0cfa.slog")
  TESTS+=("examples/tinycfa/0cfa-demand.slog")
  TESTS+=("examples/tinycfa/0cfa-counting.slog")
  TESTS+=("examples/tinycfa/mcfa-counting.slog")
  TESTS+=("examples/schemecfa/schemecfa.slog")
  TESTS+=("examples/schemecfa/analysis-demo.slog")
  TESTS+=("examples/kcfa/kcfa.slog")
  TESTS+=("examples/verify/demo.slog")
fi

if [ "$KEEP_CACHE" -eq 0 ]; then
  rm -rf build
fi
mkdir -p build out
RESULTS="$(mktemp -d)"
trap 'rm -rf "$RESULTS"' EXIT

# Run one test: compile+run, then compare to (or update) its golden.  Writes a
# single result line to $RESULTS/<name> ("PASS"/"UPDATED"/"FAIL <reason>") and
# prints its own diagnostics; the parent aggregates.  Safe to run concurrently.
run_one_test() {
  local t="$1"
  local name outdir logfile expected
  name="$(basename "$t" .slog)"
  outdir="out/test-$name"
  logfile="out/test-$name.log"
  expected="tests/expected/$name"
  rm -rf "$outdir"

  # 900s, not 300s: cold clang builds of the map-heavy examples (kcfa's
  # rules-based Patricia environments generate a large .cpp) run several
  # minutes; the fixpoints themselves are sub-second.  --keep-cache skips
  # the rebuild.  The ceiling is a hang backstop, not a perf gate.
  if ! timeout 900 racket slog.rkt --no-banner --debug-dir "$outdir" "$t" \
       > "$logfile" 2>&1; then
    echo "FAIL $name (run error; see $logfile)"
    echo "FAIL run-error" > "$RESULTS/$name"; return
  fi

  if [ "$UPDATE" -eq 1 ]; then
    rm -rf "$expected"; mkdir -p "$expected"
    for csv in "$outdir"/*.csv; do
      [ -e "$csv" ] || continue
      LC_ALL=C sort "$csv" > "$expected/$(basename "$csv")"
    done
    echo "UPDATED $name"; echo "UPDATED" > "$RESULTS/$name"; return
  fi

  if [ ! -d "$expected" ]; then
    echo "FAIL $name (no golden dir $expected; run with --update)"
    echo "FAIL no-golden" > "$RESULTS/$name"; return
  fi

  local ok=1
  # every expected file must match, and no unexpected relations may appear
  for want in "$expected"/*.csv; do
    local rel; rel="$(basename "$want")"
    if [ ! -e "$outdir/$rel" ]; then
      echo "  $name: missing relation $rel"; ok=0; continue
    fi
    if ! diff -q <(LC_ALL=C sort "$outdir/$rel") "$want" > /dev/null; then
      echo "  $name: relation $rel differs:"
      diff <(LC_ALL=C sort "$outdir/$rel") "$want" | head -10 | sed 's/^/    /'
      ok=0
    fi
  done
  for got in "$outdir"/*.csv; do
    [ -e "$got" ] || continue
    local rel; rel="$(basename "$got")"
    if [ ! -e "$expected/$rel" ]; then
      echo "  $name: unexpected non-empty relation $rel"; ok=0
    fi
  done

  if [ "$ok" -eq 1 ]; then echo "PASS $name"; echo "PASS" > "$RESULTS/$name"
  else echo "FAIL $name"; echo "FAIL mismatch" > "$RESULTS/$name"; fi
}

# Dispatch up to $JOBS tests concurrently.
running=0
for t in "${TESTS[@]}"; do
  run_one_test "$t" &
  running=$((running+1))
  if [ "$running" -ge "$JOBS" ]; then wait -n 2>/dev/null || wait; running=$((running-1)); fi
done
wait

PASS=0; FAIL=0; FAILED_NAMES=()
for t in "${TESTS[@]}"; do
  name="$(basename "$t" .slog)"
  read -r status _ < "$RESULTS/$name" 2>/dev/null || status="FAIL"
  case "$status" in
    PASS|UPDATED) PASS=$((PASS+1)) ;;
    *)            FAIL=$((FAIL+1)); FAILED_NAMES+=("$name") ;;
  esac
done

echo
echo "$PASS passed, $FAIL failed"
if [ "$FAIL" -gt 0 ]; then
  echo "failed: ${FAILED_NAMES[*]}"
  exit 1
fi
