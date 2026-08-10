#!/usr/bin/env bash
#
# T3b slice 3 gate: the promotion budget and next-re-entry pickup
# (docs/t3b-contract.md §3 slice 3; execution-tiers §12.12's first clause:
# "a pathological interpreted acyclic join triggers promotion and
# self-rescues", plus the contract's re-entry clause: "a second re-entry
# runs on the artifact built during the first").
#
# Part 1 -- batch promotion.  The profile admits a stratum on STALE evidence
# (its data grew since the fast observation), the run interprets past the
# budget, the promotion closure launches the build mid-run, and the T3a swap
# seam attaches it before fixpoint.  Driven under SLOG_MAX_MS=500 -- the
# daemon's own pathological-budget knob -- so boundary polls come every
# ~0.5s instead of every 8s and the test completes in seconds.
#
# Part 2 -- session re-entry pickup.  A session stratum whose fixpoint beat
# clang registered with its PLAN; once the detached builds land, the next
# re-entry send resolves to the cached artifact (sinfo-artifact) and the
# tier ledger records the climb.  Also asserts sessions now RECORD the race
# (slice 2 covered the batch driver only).
#
#   bash tests/tier-promotion.sh

set -u
cd "$(dirname "$0")/.."

WORK="$(mktemp -d)"
trap 'rm -rf "$WORK"' EXIT
PASS=0; FAIL=0
pass() { echo "PASS $1"; PASS=$((PASS+1)); }
fail() { echo "FAIL $1"; FAIL=$((FAIL+1)); }

export SLOG_OPT=tiered
export SLOG_SMT_SOLVERS=mock
export SLOG_NO_FREEZE=1     # keep the ground facts inline: stable stratum shape
export SLOG_MAX_MS=500      # boundary polls every ~0.5s (daemon RunBudget)
unset SLOG_TIER_PROFILE SLOG_TIER_SKIP_MS SLOG_TIER_PROMOTE_MS 2>/dev/null || true

mkdir -p build out

# The pathological-for-interp fixture: full transitive closure of a 2500-chain
# (~3.1M path tuples, ~6s interpreted) against a ~4s -O0 build of two rules.
CHAIN=out/tprom_fixture.slog
{
  echo "table (edge int int)"; echo "table (path int int)"; echo "rule"
  for i in $(seq 1 2500); do echo "(edge $i $((i+1)))"; done
  echo "rule (edge X Y) --> (path X Y)"
  echo "rule (path X Y) (edge Y Z) --> (path X Z)"
} > "$CHAIN"

run_fixture() { # <label> <outdir> [env...]
  local label="$1" outdir="$2"; shift 2
  rm -rf "$outdir"
  if ! env "$@" timeout 900 racket compiler/run.rkt --no-banner \
       --debug-dir "$outdir" "$CHAIN" > "$WORK/$label.log" 2>&1; then
    echo "  (run $label failed; see $WORK/$label.log)"; return 1
  fi
}

covered_hashes() { # hashes this run executed whose strata build artifacts
  local h cov
  for h in $(grep -o '(fixpoint [0-9]* "[0-9a-f]*"' "$WORK/$1.log" \
               | sed 's/.*"\([0-9a-f]*\)"/\1/'); do
    cov=$(grep -o '(coverage [0-9]* [0-9]*)' "build/$h.tiers" 2>/dev/null \
            | head -1 | sed 's/(coverage \([0-9]*\) .*/\1/')
    [ "${cov:-0}" -gt 0 ] && echo "$h"
  done
}

kernel_keys() {
  grep -o '(key "[0-9a-f]*")' "build/$1.tiers" 2>/dev/null \
    | sed 's/(key "\([0-9a-f]*\)")/\1/'
}

wait_for() { local i; for i in $(seq 1 "$2"); do [ -e "$1" ] && return 0; sleep 1; done; return 1; }

drop_artifacts() { # settle any in-flight O2, then delete the covered .so's
  local h
  for h in "$@"; do
    # in flight only under a claim marker (fast-compile §13); a skipped run
    # queued nothing, and waiting on it would block forever
    if [ -e "build/$h.so.building" ] && [ ! -e "build/$h.so" ]; then
      wait_for "build/$h.so" 180 \
        || { echo "  (claimed O2 for $h never landed)"; return 1; }
    fi
    rm -f "build/$h.so" "build/$h.O0.so"
  done
}

seed_stale_profiles() { # <hash>... -- a fast, unraced, PLAUSIBLE-but-stale obs
  mkdir -p build/profile
  local h k
  for h in "$@"; do
    for k in $(kernel_keys "$h"); do
      echo "(kernel-profile (key \"$k\") (obs (started interp) (upgraded #f) (iterations 4) (ms 1.0) (stratum \"stale-seed\") (at 0)))" \
        > "build/profile/$k.profile"
    done
  done
}

csvs_equal() { # <refdir> <gotdir>
  local csv rel
  for csv in "$1"/*.csv; do
    [ -e "$csv" ] || continue
    rel="$(basename "$csv")"
    case "$rel" in '$stat_'*) continue ;; esac
    diff -q <(LC_ALL=C sort "$csv") <(LC_ALL=C sort "$2/$rel") >/dev/null \
      || { echo "  $rel differs"; return 1; }
  done
  return 0
}

# ---- part 1: batch promotion ------------------------------------------------

# discovery (profile state unknown; only for hashes), then a clean-profile
# reference run whose CSVs are the goldens of this battery
run_fixture discovery out/tprom-x || { fail discovery; echo "$PASS passed, $((FAIL+1)) failed"; exit 1; }
COVERED=$(covered_hashes discovery)
[ -n "$COVERED" ] || { fail "discovery (no covered stratum)"; echo "$PASS passed, $((FAIL+1)) failed"; exit 1; }
for h in $COVERED; do for k in $(kernel_keys "$h"); do rm -f "build/profile/$k.profile"; done; done
rm -f $(for h in $COVERED; do echo "build/$h.so build/$h.O0.so"; done)

run_fixture ref out/tprom-ref || fail ref
drop_artifacts $COVERED || fail ref-quiesce

# P1: stale profile admits the stratum; PROMOTE_MS=0 promotes at the first
# boundary poll; the build lands and attaches before the ~6s fixpoint
seed_stale_profiles $COVERED
run_fixture p1 out/tprom-p1 SLOG_TIER_PROMOTE_MS=0 || fail p1
ok=1
grep -q "\[promoting" "$WORK/p1.log" || { echo "  no promotion fired"; ok=0; }
grep -q "\[upgraded" "$WORK/p1.log" || { echo "  promoted artifact never attached"; ok=0; }
csvs_equal out/tprom-ref out/tprom-p1 || ok=0
[ $ok -eq 1 ] && pass "p1-promotes-and-self-rescues" || fail "p1-promotes-and-self-rescues"

# the recorded outcome un-skips the stratum: latest obs upgraded #t
ok=1
for h in $COVERED; do
  for k in $(kernel_keys "$h"); do
    head -c 400 "build/profile/$k.profile" | grep -q '(upgraded #t)' \
      || { echo "  kernel $k latest obs not (upgraded #t)"; ok=0; }
  done
done
[ $ok -eq 1 ] && pass "p1-outcome-recorded" || fail "p1-outcome-recorded"

# P2: same stale admission, but a huge budget -- no promotion, no clang,
# the run completes interpreted and byte-identical
drop_artifacts $COVERED || fail p2-quiesce
seed_stale_profiles $COVERED
run_fixture p2 out/tprom-p2 SLOG_TIER_PROMOTE_MS=600000 || fail p2
ok=1
grep -q "\[promoting" "$WORK/p2.log" && { echo "  promotion fired under a huge budget"; ok=0; }
sleep 5
for h in $COVERED; do
  { [ -e "build/$h.so" ] || [ -e "build/$h.O0.so" ]; } \
    && { echo "  $h built an artifact without promotion"; ok=0; }
done
csvs_equal out/tprom-ref out/tprom-p2 || ok=0
[ $ok -eq 1 ] && pass "p2-budget-respected-zero-clang" || fail "p2-budget-respected-zero-clang"

# ---- part 2: session next-re-entry pickup + session recording ---------------

# a small fixture: fixpoint beats clang, so the session registers the PLAN
SMALL=out/tprom_small.slog
{
  echo "table (edge int int)"; echo "table (path int int)"; echo "rule"
  for i in $(seq 1 400); do echo "(edge $i $((i+1)))"; done
  echo "rule (edge X Y) --> (path X Y)"
  echo "rule (path X Y) (edge Y Z) --> (path X Z)"
} > "$SMALL"
# Its closure kernel is shape-identical to part 1's (T4 sharing), whose
# latest observation is now honest-and-slow -- so no skip: builds queue.
# Its JOB hashes, however, may be warm from other batteries (an identical
# 400-chain exists elsewhere), so discover them with a throwaway session,
# wait out any in-flight builds, and delete the artifacts: the real run
# must COLD-start interpreted for the pickup scenario to exist.
if ! timeout 300 racket tests/api/session-drive.rkt "run:$SMALL" tiers \
     > "$WORK/sdisc.log" 2>&1; then
  echo "  (session discovery failed; see $WORK/sdisc.log)"; fail "session-discovery"
fi
SHASHES=$(grep -o '(tiers-record [0-9]* [0-9a-f]*' "$WORK/sdisc.log" | awk '{print $3}' | sort -u)
SCOVERED=""
for h in $SHASHES; do
  cov=$(grep -o '(coverage [0-9]* [0-9]*)' "build/$h.tiers" 2>/dev/null \
          | head -1 | sed 's/(coverage \([0-9]*\) .*/\1/')
  [ "${cov:-0}" -gt 0 ] && SCOVERED="$SCOVERED $h"
done
drop_artifacts $SCOVERED || fail "session-quiesce"

if ! timeout 900 racket tests/api/session-drive.rkt \
     "run:$SMALL" await-build:180 tiers \
     add-tuple:edge,401,402 reenter:edge tiers \
     dump-tuples:path > "$WORK/session.log" 2>&1; then
  echo "  (session drive failed; see $WORK/session.log)"
  fail "session-drive"
else
  ok=1
  grep -q '(builds-arrived)' "$WORK/session.log" \
    || { echo "  builds never arrived"; ok=0; }
  # the two `tiers` prints: before re-entry the closure stratum sits on its
  # cold-start interp rung with the artifact already in cache; after
  # re-entry it runs the artifact
  first=$(grep -m1 -n '(tiers-record' "$WORK/session.log" | cut -d: -f1)
  interp_with_cache=$(sed -n "${first},\$p" "$WORK/session.log" \
    | awk '/\(tiers-record/ && /interp/ && /o[02]/ {print; exit}')
  if [ -z "$interp_with_cache" ]; then
    echo "  no stratum was interp-registered with a cached artifact"; ok=0
  else
    hash=$(echo "$interp_with_cache" | sed 's/.*tiers-record [0-9]* \([0-9a-f]*\) .*/\1/')
    tail -n +"$first" "$WORK/session.log" | grep '(tiers-record' | tail -n +3 \
      | grep "$hash" | grep -qE '\(tiers-record [0-9]+ [0-9a-f]+ (o0|o2) ' \
      || { echo "  stratum $hash did not climb at re-entry"; ok=0; }
  fi
  # content correct across the native re-entry: the new edge's closure landed
  grep -q '(tuplerow 401 402)' "$WORK/session.log" \
    || { echo "  re-entered cone missing the new tuple's closure"; ok=0; }
  # sessions record the race now (slice 2 residue closed)
  if [ -n "${hash:-}" ]; then
    rec=0
    for k in $(kernel_keys "$hash"); do
      grep -q "(stratum \"$hash\")" "build/profile/$k.profile" 2>/dev/null && rec=1
    done
    [ $rec -eq 1 ] || { echo "  session push recorded no observation"; ok=0; }
  fi
  [ $ok -eq 1 ] && pass "session-reentry-pickup" || fail "session-reentry-pickup"
fi

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
