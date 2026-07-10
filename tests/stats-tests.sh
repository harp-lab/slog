#!/usr/bin/env bash
#
# Exact-once fire audit (docs/stats.md; docs/incremental.md §8, M0 prep).
#
#   tests/stats-tests.sh             assert every tests/stat_*.slog
#   tests/stats-tests.sh --update    re-snapshot the expectations
#
# Each program runs TWICE; the audit asserts
#   1. the two runs' $stat_fires agree exactly (thread-schedule
#      determinism of instantiation counts), and
#   2. the counts match tests/stats-expected/<name>.fires -- HAND-VERIFIED
#      instantiation counts (see each program's header comment): under
#      correct per-position delta partitioning, semi-naive fires each
#      satisfying body assignment exactly once, so these goldens are the
#      observable form of the exact-once property that DRed^c counting
#      will depend on.
#
# Timing rows ($stat_fixpoint) are deliberately not asserted.

set -u
cd "$(dirname "$0")/.."

export SLOG_OPT="${SLOG_OPT:-0}"
export SLOG_SMT_SOLVERS=mock

UPDATE=0
[ "${1:-}" = "--update" ] && UPDATE=1

# planner temp relations are gensym-named per compile; normalize them so
# unrelated compiler changes don't churn the hand-verified expectations
norm() { LC_ALL=C sed -E 's/temp[A-Za-z0-9]+/temp<N>/g' "$1" | LC_ALL=C sort; }

fail=0
for t in tests/stat_*.slog; do
  name="$(basename "$t" .slog)"
  exp="tests/stats-expected/$name.fires"
  out1="out/stats-$name-1"; out2="out/stats-$name-2"
  ok=1
  for o in "$out1" "$out2"; do
    rm -rf "$o"
    if ! timeout 900 racket slog.rkt --no-banner --debug-dir "$o" "$t" \
         > "out/stats-$name.log" 2>&1; then
      echo "FAIL $name (run error; see out/stats-$name.log)"; fail=1; ok=0; break
    fi
  done
  [ "$ok" -eq 1 ] || continue

  if ! diff <(norm "$out1/\$stat_fires.csv") \
            <(norm "$out2/\$stat_fires.csv") > /dev/null; then
    echo "FAIL $name (fire counts differ across identical runs -- nondeterminism)"
    fail=1; continue
  fi

  if [ "$UPDATE" -eq 1 ]; then
    mkdir -p tests/stats-expected
    norm "$out1/\$stat_fires.csv" > "$exp"
    echo "UPDATED $name"
    continue
  fi

  if [ ! -e "$exp" ]; then
    echo "FAIL $name (no expectation $exp; run with --update and hand-verify)"
    fail=1; continue
  fi
  if diff <(norm "$out1/\$stat_fires.csv") "$exp" > /dev/null; then
    echo "PASS $name"
  else
    echo "FAIL $name (fire counts drifted from hand-verified expectation):"
    diff <(norm "$out1/\$stat_fires.csv") "$exp" | sed 's/^/  /'
    fail=1
  fi
done
exit $fail
