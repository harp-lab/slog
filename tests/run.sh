#!/usr/bin/env bash
# Slog compiler + daemon end-to-end test runner.
#
#   tests/run.sh            run all tests, diff against golden outputs
#   tests/run.sh --update   regenerate the golden outputs from current behavior
#
# Each test is run RUNS times; outputs must be identical across runs (so a
# concurrency race shows up as a nondeterminism failure) and match the golden.
set -u
cd "$(dirname "$0")/.."

RUNS=4
TESTS="reach grandparent line hub labels structs nested cartesian"
update=0
[ "${1:-}" = "--update" ] && update=1

echo "Building daemon ..."
if ! make -C daemon >/tmp/slog-daemon-build.log 2>&1; then
  echo "daemon build FAILED:"; cat /tmp/slog-daemon-build.log; exit 1
fi

# Canonical form of a run's output: each csv sorted, prefixed by its name.
canon() { for f in $(ls out/*.csv 2>/dev/null | sort); do echo "## $(basename "$f")"; sort "$f"; done; }

fail=0
for t in $TESTS; do
  expdir="tests/expected/$t"
  prev=""; broke=0
  for run in $(seq 1 $RUNS); do
    rm -rf out; mkdir -p out
    if ! timeout 150 racket slog.rkt --no-banner --debug-dir out "tests/$t.slog" >/dev/null 2>&1; then
      echo "FAIL $t: run $run errored"; fail=1; broke=1; break
    fi
    cur=$(canon)
    if [ -n "$prev" ] && [ "$cur" != "$prev" ]; then
      echo "FAIL $t: nondeterministic output across runs (possible race)"; fail=1; broke=1; break
    fi
    prev="$cur"
  done
  [ $broke -eq 1 ] && continue

  if [ $update -eq 1 ]; then
    rm -rf "$expdir"; mkdir -p "$expdir"
    for f in out/*.csv; do sort "$f" > "$expdir/$(basename "$f")"; done
    echo "updated golden: $t"
    continue
  fi

  ok=1
  for f in out/*.csv; do
    b=$(basename "$f")
    if ! diff -q <(sort "$f") "$expdir/$b" >/dev/null 2>&1; then
      echo "FAIL $t: $b differs from golden"; ok=0; fail=1
    fi
  done
  # also catch relations present in golden but missing from output
  for g in "$expdir"/*.csv; do
    b=$(basename "$g")
    [ -f "out/$b" ] || { echo "FAIL $t: $b missing from output"; ok=0; fail=1; }
  done
  [ $ok -eq 1 ] && echo "PASS $t (${RUNS}x, deterministic)"
done

rm -rf out
[ $fail -eq 0 ] && echo "ALL TESTS PASSED" || echo "SOME TESTS FAILED"
exit $fail
