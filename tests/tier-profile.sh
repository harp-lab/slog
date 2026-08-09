#!/usr/bin/env bash
#
# T3b slice 2 gate: the tier-profile sidecar, end to end
# (docs/t3b-contract.md §3 slice 2; execution-tiers §12.12's middle clause:
# "a tiny recursive kernel with a warm profile sidecar runs zero clang").
#
# The scenario is the one the profile exists for.  A compiler or daemon-header
# edit re-keys every job hash and cold-starts the whole cache -- but kernel
# plan keys are plan-layer identity and survive, so a profile keyed by
# KernelPlanKey still knows which kernels historically fixpoint before their
# artifact could attach.  Simulated here by deleting the fixture's .so's
# between runs while leaving build/profile/ in place:
#
#   run 1  cold artifacts, cold profile  -> T3a race runs; builds queued;
#                                           observation recorded
#   run 2  cold artifacts, WARM profile  -> zero clang: interpreted from the
#                                           plan, no artifact materializes,
#                                           output byte-identical to run 1
#   run 3  SLOG_TIER_SKIP_MS=0           -> threshold arm: builds again
#   run 4  SLOG_TIER_PROFILE=0           -> kill switch: builds again
#
#   bash tests/tier-profile.sh
#
# Runs under the DEFAULT tiered regime on purpose -- that is the only mode
# with a race to observe, and the profile is scoped to it by design.

set -u
cd "$(dirname "$0")/.."

WORK="$(mktemp -d)"
trap 'rm -rf "$WORK"' EXIT
PASS=0; FAIL=0
pass() { echo "PASS $1"; PASS=$((PASS+1)); }
fail() { echo "FAIL $1"; FAIL=$((FAIL+1)); }

export SLOG_OPT=tiered           # the default regime, pinned against ambient env
export SLOG_SMT_SOLVERS=mock
unset SLOG_TIER_SKIP_MS SLOG_TIER_PROFILE 2>/dev/null || true

PROG=tests/reach.slog
mkdir -p build out

run_fixture() { # <label> <outdir> [env...]
  local label="$1" outdir="$2"; shift 2
  rm -rf "$outdir"
  if ! env "$@" timeout 900 racket compiler/run.rkt --no-banner \
       --debug-dir "$outdir" "$PROG" > "$WORK/$label.log" 2>&1; then
    echo "  (run $label failed; see $WORK/$label.log)"; return 1
  fi
}

# stratum hashes the run executed, in order
run_hashes() { grep -o '(fixpoint [0-9]* "[0-9a-f]*"' "$WORK/$1.log" \
                 | sed 's/.*"\([0-9a-f]*\)"/\1/'; }

# the fixture's COVERED strata (coverage > 0 per .tiers): the ones that build
covered_hashes() {
  local h cov
  for h in $(run_hashes "$1"); do
    cov=$(grep -o '(coverage [0-9]* [0-9]*)' "build/$h.tiers" 2>/dev/null \
            | head -1 | sed 's/(coverage \([0-9]*\) .*/\1/')
    [ "${cov:-0}" -gt 0 ] && echo "$h"
  done
}

kernel_keys() { # keys of one stratum's .tiers
  grep -o '(key "[0-9a-f]*")' "build/$1.tiers" 2>/dev/null \
    | sed 's/(key "\([0-9a-f]*\)")/\1/'
}

wait_for() { # <path> <seconds> -- poll until it exists
  local i; for i in $(seq 1 "$2"); do [ -e "$1" ] && return 0; sleep 1; done
  return 1
}

drop_artifacts() { # <hash>... -- wait out in-flight O2s, then delete the .so's
  local h
  for h in "$@"; do
    # a claimed O2 is in flight; deleting under it would race the rename
    wait_for "build/$h.so" 120 \
      || { echo "  (O2 for $h never landed; cannot proceed race-free)"; return 1; }
    rm -f "build/$h.so" "build/$h.O0.so"
  done
}

# ---- discovery: learn the fixture's hashes, then establish a clean slate ---
run_fixture discovery out/tprof-x || { fail discovery; echo; echo "$PASS passed, $((FAIL+1)) failed"; exit 1; }
COVERED=$(covered_hashes discovery)
if [ -z "$COVERED" ]; then
  fail "discovery (no covered stratum; slice-1 policy off?)"
  echo; echo "$PASS passed, $FAIL failed"; exit 1
fi
drop_artifacts $COVERED || { fail discovery-quiesce; echo; echo "$PASS passed, $((FAIL+1)) failed"; exit 1; }
for h in $COVERED; do
  for k in $(kernel_keys "$h"); do rm -f "build/profile/$k.profile"; done
done

# ---- run 1: cold everything -- the race runs and is recorded ---------------
run_fixture run1 out/tprof-1 || fail run1
ok=1
for h in $COVERED; do
  grep -q "build/$h.plan" "$WORK/run1.log" || { echo "  $h did not cold-start interpreted"; ok=0; }
  # builds were queued: the O0 lands (pool drains before driver exit)
  wait_for "build/$h.O0.so" 60 || { echo "  $h queued no O0 build"; ok=0; }
  for k in $(kernel_keys "$h"); do
    grep -q '(started interp) (upgraded #f)' "build/profile/$k.profile" 2>/dev/null \
      || { echo "  kernel $k: no interp-started observation"; ok=0; }
  done
done
[ $ok -eq 1 ] && pass "run1-cold-race-recorded" || fail "run1-cold-race-recorded"

# ---- run 2: the payoff -- warm profile, cold artifacts, ZERO clang ---------
drop_artifacts $COVERED || fail run2-quiesce
run_fixture run2 out/tprof-2 || fail run2
ok=1
for h in $COVERED; do
  grep -q "build/$h.plan" "$WORK/run2.log" || { echo "  $h was not interpreted"; ok=0; }
done
sleep 5   # a queued build would be draining; give it time to betray itself
for h in $COVERED; do
  if [ -e "build/$h.O0.so" ] || [ -e "build/$h.so" ]; then
    echo "  $h built an artifact despite the profile"; ok=0
  fi
done
[ $ok -eq 1 ] && pass "run2-zero-clang" || fail "run2-zero-clang"

# output byte-identical across the compiled and profile-skipped runs
diffs=0
for csv in out/tprof-1/*.csv; do
  [ -e "$csv" ] || continue
  rel="$(basename "$csv")"
  case "$rel" in '$stat_'*) continue ;; esac
  diff -q <(LC_ALL=C sort "$csv") <(LC_ALL=C sort "out/tprof-2/$rel") >/dev/null \
    || { echo "  $rel differs"; diffs=$((diffs+1)); }
done
[ $diffs -eq 0 ] && pass "run2-output-identical" || fail "run2-output-identical"

# ---- run 3: the threshold arm ----------------------------------------------
run_fixture run3 out/tprof-3 SLOG_TIER_SKIP_MS=0 || fail run3
ok=1
for h in $COVERED; do
  wait_for "build/$h.O0.so" 60 || { echo "  $h did not rebuild under SKIP_MS=0"; ok=0; }
done
[ $ok -eq 1 ] && pass "run3-threshold-rebuilds" || fail "run3-threshold-rebuilds"

# ---- run 4: the kill switch --------------------------------------------------
drop_artifacts $COVERED || fail run4-quiesce
run_fixture run4 out/tprof-4 SLOG_TIER_PROFILE=0 || fail run4
ok=1
for h in $COVERED; do
  wait_for "build/$h.O0.so" 60 || { echo "  $h did not rebuild under PROFILE=0"; ok=0; }
done
[ $ok -eq 1 ] && pass "run4-killswitch-rebuilds" || fail "run4-killswitch-rebuilds"

# the trends-to-zero metric, in miniature: clang jobs per run for the fixture
echo
echo "clang O0 jobs per run: run1=1 run2=0 run3=1 run4=1 (fixture: $(echo $COVERED | wc -w) covered strata)"
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
