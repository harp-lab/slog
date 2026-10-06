#!/usr/bin/env bash
#
# Interpreter allocation stress (macOS): the multi-threaded interpreter,
# sliced as finely as the daemon allows, over a long demand-driven fixture.
# Every read task builds and frees an execution (a Machine and its cloned
# cursors) and every 1 ms slice parks and resumes one, from all workers at
# once.  With libmalloc's nano zone on, this aborted the daemon in about one
# run in five ("pointer being freed was not allocated" in a cursor
# destructor, or a parked execution found freed), so slogd now re-execs
# itself with MallocNanoZone=0 (slogd.cpp).
#
# Part 1 checks that the daemon runs without the nano zone.  Part 2 runs the
# fixture RUNS times (default 12; ~0.95 chance of catching a regression at
# the old rate) and fails on any daemon death.  Slow -- minutes -- so it is
# a named harness outside ALL.
#
#   bash tests/interp-alloc-stress.sh [RUNS]

set -u
cd "$(dirname "$0")/.."
RUNS="${1:-12}"
PASS=0; FAIL=0
pass() { echo "PASS $1"; PASS=$((PASS+1)); }
fail() { echo "FAIL $1"; FAIL=$((FAIL+1)); }
mkdir -p build out
make -C daemon slogd >/dev/null || { echo "FAIL build"; exit 1; }

if [ "$(uname -s)" = Darwin ]; then
  # The re-exec keeps the pid, so the running daemon's environment shows it.
  sleep 30 | env -u MallocNanoZone -u SLOG_NANO_ZONE daemon/slogd -t 2 \
    >/dev/null 2>&1 &
  pid=$!
  sleep 1
  if ps -E -o command= -p "$pid" | grep -q "MallocNanoZone=0"; then
    pass nano-zone-off
  else
    fail nano-zone-off
  fi
  kill "$pid" 2>/dev/null; wait "$pid" 2>/dev/null
fi

export SLOG_OPT=interp SLOG_SLICE_MS=1 SLOG_MAX_MS=600000 SLOG_NO_MEM_CAP=1
for i in $(seq 1 "$RUNS"); do
  log="out/interp-alloc-stress.$$.$i.log"
  if racket compiler/run.rkt --no-banner tests/interp_alloc_stress.slog \
       >"$log" 2>&1; then
    pass "run-$i"
  else
    fail "run-$i (see $log)"
  fi
done

echo "interp-alloc-stress: $PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
