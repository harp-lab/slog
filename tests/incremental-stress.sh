#!/usr/bin/env bash
# Focused concurrency, pause/resume, and performance gates for counted
# M1/M3/M6L maintenance.

set -u
cd "$(dirname "$0")/.."
mkdir -p build out
export SLOG_OPT=0
export SLOG_NO_MEM_CAP=1

PASS=0
FAIL=0
ok() { echo "PASS $1"; PASS=$((PASS+1)); }
bad() { echo "FAIL $1"; FAIL=$((FAIL+1)); }

# One independent signed-stream oracle per representative worker count.  The
# ordinary session gate retains its fixed 3101/3102 seeds; these vary both
# scheduling and edit streams.
for spec in 1:4101 2:4102 8:4108; do
  threads="${spec%%:*}"
  seed="${spec##*:}"
  log="out/m3-stress-t${threads}-s${seed}.log"
  if SLOG_THREADS="$threads" timeout 900 \
       racket tests/api/acyclic-stream-fuzz.rkt "$seed" > "$log" 2>&1 \
     && grep -qF "m3-fuzz-ok $seed" "$log"; then
    ok "m3-fuzz-t${threads}-s${seed}"
  else
    bad "m3-fuzz-t${threads}-s${seed} (see $log)"
  fi
done

# Exercise the session driver's automatic continuation while an M3-sized
# update is suspended in read and/or iteration work.
log="out/m3-pause-stress.log"
if SLOG_THREADS=4 SLOG_MAX_MS=1 timeout 900 \
     racket tests/api/acyclic-pause-stress.rkt > "$log" 2>&1 \
   && grep -qF "m3-pause-stress-ok" "$log"; then
  ok "m3-pause-resume"
else
  bad "m3-pause-resume (see $log)"
fi

# M6L slice 2: each worker count gets an independent signed contributor stream
# diffed after every flush against a fresh unseeded one-shot session.
for spec in 1:5101 2:5102 8:5108; do
  threads="${spec%%:*}"
  seed="${spec##*:}"
  log="out/m6l-stress-t${threads}-s${seed}.log"
  if SLOG_THREADS="$threads" timeout 1200 \
       racket tests/api/lattice-stream-fuzz.rkt "$seed" > "$log" 2>&1 \
     && grep -qF "m6l-fuzz-ok $seed" "$log"; then
    ok "m6l-fuzz-t${threads}-s${seed}"
  else
    bad "m6l-fuzz-t${threads}-s${seed} (see $log)"
  fi
done

log="out/m6l-pause-stress.log"
if SLOG_THREADS=4 SLOG_MAX_MS=1 timeout 1200 \
     racket tests/api/lattice-pause-stress.rkt > "$log" 2>&1 \
   && grep -qF "m6l-pause-stress-ok" "$log"; then
  ok "m6l-pause-resume"
else
  bad "m6l-pause-resume (see $log)"
fi

# Timing is reported rather than thresholded so a loaded CI host cannot make
# the correctness gate flaky.  Route selection and settled state are asserted
# inside the benchmark.
log="out/m6l-perf.log"
if SLOG_THREADS=4 timeout 1200 \
     racket tests/api/lattice-perf.rkt > "$log" 2>&1 \
   && grep -qF "m6l-perf-ok" "$log"; then
  ok "m6l-cold-warm-perf"
  grep -F "m6l-perf-ok" "$log"
else
  bad "m6l-cold-warm-perf (see $log)"
fi

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
