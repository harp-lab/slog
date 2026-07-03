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
TESTS=()
for arg in "$@"; do
  case "$arg" in
    --update)     UPDATE=1 ;;
    --keep-cache) KEEP_CACHE=1 ;;
    *)            TESTS+=("$arg") ;;
  esac
done

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
fi

if [ "$KEEP_CACHE" -eq 0 ]; then
  rm -rf build
fi
mkdir -p build out

PASS=0
FAIL=0
FAILED_NAMES=()

for t in "${TESTS[@]}"; do
  name="$(basename "$t" .slog)"
  outdir="out/test-$name"
  logfile="out/test-$name.log"
  expected="tests/expected/$name"
  rm -rf "$outdir"

  if ! timeout 300 racket slog.rkt --no-banner --debug-dir "$outdir" "$t" \
       > "$logfile" 2>&1; then
    echo "FAIL $name (run error; see $logfile)"
    FAIL=$((FAIL+1)); FAILED_NAMES+=("$name")
    continue
  fi

  if [ "$UPDATE" -eq 1 ]; then
    rm -rf "$expected"
    mkdir -p "$expected"
    for csv in "$outdir"/*.csv; do
      [ -e "$csv" ] || continue
      LC_ALL=C sort "$csv" > "$expected/$(basename "$csv")"
    done
    echo "UPDATED $name"
    continue
  fi

  if [ ! -d "$expected" ]; then
    echo "FAIL $name (no golden dir $expected; run with --update)"
    FAIL=$((FAIL+1)); FAILED_NAMES+=("$name")
    continue
  fi

  ok=1
  # every expected file must match, and no unexpected relations may appear
  for want in "$expected"/*.csv; do
    rel="$(basename "$want")"
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
    rel="$(basename "$got")"
    if [ ! -e "$expected/$rel" ]; then
      echo "  $name: unexpected non-empty relation $rel"; ok=0
    fi
  done

  if [ "$ok" -eq 1 ]; then
    echo "PASS $name"
    PASS=$((PASS+1))
  else
    echo "FAIL $name"
    FAIL=$((FAIL+1)); FAILED_NAMES+=("$name")
  fi
done

echo
echo "$PASS passed, $FAIL failed"
if [ "$FAIL" -gt 0 ]; then
  echo "failed: ${FAILED_NAMES[*]}"
  exit 1
fi
