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

# Transaction abort, writer audit, maintenance overflow fallback, recount
# healing, and next-epoch journal hygiene are lattice-specific lifecycle gates.
log="out/m6l-recovery.log"
if timeout 1200 racket tests/api/lattice-recovery.rkt > "$log" 2>&1 \
   && grep -qF "m6l-recovery-ok" "$log"; then
  ok "m6l-recovery"
else
  bad "m6l-recovery (see $log)"
fi

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

# M4T slice 1: independent recursive signed-stream oracles per worker count.
# Random edge toggles over a dense cyclic universe drive sweeps, reseeds,
# relearns, and the cancelling downstream cascade; every flush is diffed
# (content and sidecars) against a fresh rerun plus forced recount.
for spec in 1:6101 2:6102 8:6108; do
  threads="${spec%%:*}"
  seed="${spec##*:}"
  log="out/m4t-stress-t${threads}-s${seed}.log"
  if SLOG_THREADS="$threads" timeout 1200 \
       racket tests/api/recursive-stream-fuzz.rkt "$seed" > "$log" 2>&1 \
     && grep -qF "m4t-fuzz-ok $seed" "$log"; then
    ok "m4t-fuzz-t${threads}-s${seed}"
  else
    bad "m4t-fuzz-t${threads}-s${seed} (see $log)"
  fi
done

# Force one sweep/reseed/rebuild epoch across pause/resume boundaries.
log="out/m4t-pause-stress.log"
if SLOG_THREADS=4 SLOG_MAX_MS=1 timeout 1200 \
     racket tests/api/recursive-pause-stress.rkt > "$log" 2>&1 \
   && grep -qF "m4t-pause-stress-ok" "$log"; then
  ok "m4t-pause-resume"
  grep -F "m4t-pause-stress-ok" "$log"
else
  bad "m4t-pause-resume (see $log)"
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

# M4N slice 4: one combined negation signed-stream oracle per worker count
# (acyclic h/hs readers AND the recursive sweep reader in one program;
# mixed-sign flushes over positives and negated inputs, ten flushes warm,
# every flush diffed against a fresh run plus forced recount).
for spec in 1:7101 2:7102 8:7108; do
  threads="${spec%%:*}"
  seed="${spec##*:}"
  log="out/m4n-stress-t${threads}-s${seed}.log"
  if SLOG_THREADS="$threads" timeout 1200 \
       racket tests/api/negation-stream-fuzz.rkt "$seed" > "$log" 2>&1 \
     && grep -qF "m4n-fuzz-ok $seed" "$log"; then
    ok "m4n-fuzz-t${threads}-s${seed}"
  else
    bad "m4n-fuzz-t${threads}-s${seed} (see $log)"
  fi
done

# M4N derived-negated boundary: the flush generator cycles route classes so
# BOTH sides of the journal-sign decision fire every run (asserted in the
# harness), with the constant-column negated atom keeping the body-constant
# fix in the loop.
for spec in 1:8101 2:8102 8:8108; do
  threads="${spec%%:*}"
  seed="${spec##*:}"
  log="out/m4n-derived-stress-t${threads}-s${seed}.log"
  if SLOG_THREADS="$threads" timeout 1200 \
       racket tests/api/derived-neg-stream-fuzz.rkt "$seed" > "$log" 2>&1 \
     && grep -qF "m4n-derived-fuzz-ok $seed" "$log"; then
    ok "m4n-derived-fuzz-t${threads}-s${seed}"
  else
    bad "m4n-derived-fuzz-t${threads}-s${seed} (see $log)"
  fi
done

# Force a large anti-delta negative phase across pause/resume boundaries,
# with pauses attributed to the negation stratum's maint3neg flavor.
# WALL: this leg is the harness's slowest by a wide margin -- SLOG_MAX_MS=1
# pauses the anti-delta phase on essentially every budget check.  Measured
# 1146s standalone on 2026-07-25 against the harness-wide 1200s wall, i.e.
# 95% of it, so it timed out inside the full suite (where it also competes
# for cache) while passing standalone with identical output.  Given its own
# 2400s so a genuine hang is still caught but scheduling noise is not
# reported as a failure.  If this leg gets faster, put it back on 1200.
log="out/m4n-pause-stress.log"
if SLOG_THREADS=4 SLOG_MAX_MS=1 timeout 2400 \
     racket tests/api/negation-pause-stress.rkt > "$log" 2>&1 \
   && grep -qF "m4n-pause-stress-ok" "$log"; then
  ok "m4n-pause-resume"
  grep -F "m4n-pause-stress-ok" "$log"
else
  bad "m4n-pause-resume (see $log)"
fi

# --- M7 recursive lattice repair (docs/m7-contract.md sub-slice (d)): ten
# mixed signed epochs over a cyclic weighted graph (0-weight edges
# included), every flush's content AND contributor sidecars diffed against
# a fresh rerun + forced recount.  Regressions must take the repair route
# (any rerun = failure).  Cache model: exact or absent, never wrong; a
# repair flush must be exact (the post-repair refresh).
for spec in 1:9101 2:9102 8:9108; do
  threads="${spec%%:*}"
  seed="${spec##*:}"
  log="out/m7-stress-t${threads}-s${seed}.log"
  if SLOG_THREADS="$threads" timeout 1200 \
       racket tests/api/lattice-repair-stream-fuzz.rkt "$seed" > "$log" 2>&1 \
     && grep -qF "m7-fuzz-ok $seed" "$log"; then
    ok "m7-fuzz-t${threads}-s${seed}"
  else
    bad "m7-fuzz-t${threads}-s${seed} (see $log)"
  fi
done

log="out/m7-pause-stress.log"
if SLOG_THREADS=4 SLOG_MAX_MS=1 timeout 1200 \
     racket tests/api/lattice-repair-stream-fuzz.rkt 9104 > "$log" 2>&1 \
   && grep -qF "m7-fuzz-ok 9104" "$log"; then
  ok "m7-pause-stress"
else
  bad "m7-pause-stress (see $log)"
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

# M7 repair perf + sidecar memory (docs/m7-contract.md sub-slice (d)):
# cold derivation vs warm one-edge repair, contributor/rank storage lower
# bounds -- reported, not thresholded; route selection is the hard gate.
log="out/m7-perf.log"
if SLOG_THREADS=4 timeout 1200 \
     racket tests/api/lattice-repair-perf.rkt > "$log" 2>&1 \
   && grep -qF "m7-perf-ok" "$log"; then
  ok "m7-cold-warm-perf"
  grep -F "m7-perf-ok" "$log"
else
  bad "m7-cold-warm-perf (see $log)"
fi

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
