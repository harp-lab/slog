#!/usr/bin/env bash
#
# T6 slices (a)+(b) gate: the transactional ReadAttempt abort
# (docs/t6-contract.md; execution-tiers §8.1, §12 gate 7).
#
#   1. EQUIVALENCE (§12.7) -- park a real join mid-read under a pathological
#      budget, (abort-read), continue to fixpoint: every relation INCLUDING
#      $stat_fires is byte-equal to an undisturbed drive of the same
#      plugins.  Fires equality is the sharp edge: a restart that
#      double-counted would show here (the exact-once audit's observable).
#   2. ADMISSION refusal -- (abort-read) with nothing parked refuses
#      structurally, naming the position.
#   3. FLAVOR refusal (§12.13's restart clause) -- a transient
#      (count-flavored) round refuses the abort at its parks and completes
#      normally.
#
#   bash tests/t6-restart.sh

set -u
cd "$(dirname "$0")/.."

WORK="$(mktemp -d)"
trap 'rm -rf "$WORK"' EXIT
PASS=0; FAIL=0
pass() { echo "PASS $1"; PASS=$((PASS+1)); }
fail() { echo "FAIL $1"; FAIL=$((FAIL+1)); }

export SLOG_SMT_SOLVERS=mock
export SLOG_NO_FREEZE=1
mkdir -p build out

# The fixture: pause-tests' 250-edge chain -- ~63000 transitive paths whose
# recursive scan driver iterates far past the slice check, so a small budget
# forces many MID-READ suspends (a one-shot fan-out join completes its whole
# read inside one unit and parks only at iter -- measured, not guessed).
FIX=out/t6_fixture.slog
{
  echo "table (edge int int)"
  echo "table (path int int)"
  echo "rule"
  for i in $(seq 1 250); do echo "(edge $i $((i+1)))"; done
  echo "rule (edge X Y) --> (path X Y)"
  echo "rule (path X Y) (edge Y Z) --> (path X Z)"
} > "$FIX"

# pre-build the stratum plugins (SLOG_OPT=0 pinned: scraping .so paths from
# a run log requires it -- the api-tests lesson)
if ! timeout 900 env SLOG_OPT=0 racket compiler/run.rkt --no-banner \
     --debug-dir out/t6-prebuild "$FIX" > "$WORK/prebuild.log" 2>&1; then
  echo "  (fixture prebuild failed; see $WORK/prebuild.log)"
  fail prebuild; echo "$PASS passed, $((FAIL+1)) failed"; exit 1
fi
# stratum plugins only -- the action-*.so lines never match the bare-hex stem
SOS=$(grep -oE '/[^ ]*/build/[a-f0-9]+(\.O0)?\.so' "$WORK/prebuild.log" | awk '!seen[$0]++')
N_SO=$(echo "$SOS" | grep -c . || true)
if [ "$N_SO" -lt 1 ]; then
  fail "prebuild (no stratum plugin scraped)"
  echo "$PASS passed, $FAIL failed"; exit 1
fi
# the LAST stratum is the join-bearing one; everything before it drives plain
JOIN_SO=$(echo "$SOS" | tail -1)
PLAIN_TOKENS=""
while read -r so; do
  [ "$so" = "$JOIN_SO" ] && continue
  PLAIN_TOKENS="$PLAIN_TOKENS plain:$so"
done <<< "$SOS" 

# ---- 1: the §12.7 equivalence -----------------------------------------------
# reference: the same plugins, same budget, no abort
rm -rf out/t6-ref out/t6-abort
if ! SLOG_MAX_MS=2 timeout 600 racket tests/api/abort-drive.rkt out/t6-ref \
     $PLAIN_TOKENS "plain:$JOIN_SO" > "$WORK/ref.log" 2>&1; then
  echo "  (reference drive failed; see $WORK/ref.log)"; fail reference
fi
# the abort drive: retry a few times if the budget happens to never park
# mid-read (timing-dependent by nature; the fixture makes it ~certain)
got_abort=0
for attempt in 1 2 3; do
  rm -rf out/t6-abort
  if ! SLOG_MAX_MS=2 timeout 600 racket tests/api/abort-drive.rkt out/t6-abort \
       $PLAIN_TOKENS "abort:$JOIN_SO" > "$WORK/abort.log" 2>&1; then
    echo "  (abort drive failed; see $WORK/abort.log)"; break
  fi
  if grep -q '^ABORTED$' "$WORK/abort.log"; then got_abort=1; break; fi
done
[ "$got_abort" -eq 1 ] && pass "abort-fired" \
                       || fail "abort-fired (no mid-read park in 3 attempts)"

if [ "$got_abort" -eq 1 ]; then
  ok=1
  for csv in out/t6-ref/*.csv; do
    rel="$(basename "$csv")"
    case "$rel" in '$stat_fixpoint'*) continue ;; esac   # wall-clock rows
    if ! diff -q <(LC_ALL=C sort "$csv") \
                 <(LC_ALL=C sort "out/t6-abort/$rel") > /dev/null 2>&1; then
      echo "  $rel differs after abort+rerun:"
      diff <(LC_ALL=C sort "$csv") <(LC_ALL=C sort "out/t6-abort/$rel") \
        | head -5 | sed 's/^/    /'
      ok=0
    fi
  done
  [ $ok -eq 1 ] && pass "equivalence-including-fires" \
                || fail "equivalence-including-fires"
fi

# ---- 2: the admission refusal -------------------------------------------------
timeout 300 racket tests/api/drive.rkt '(abort-read)' '(abort-read now)' \
  > "$WORK/refusal.log" 2>&1 || true
grep -qE '\(refused read-abort-admission [0-9]+ \(verb abort-read\) \(detail not-parked\)' \
  "$WORK/refusal.log" && pass "admission-refusal" || fail "admission-refusal"
grep -qE '\(refused parse [0-9]+ \(verb abort-read\)' "$WORK/refusal.log" \
  && pass "bare-form-only" || fail "bare-form-only"

# ---- 3: the flavor refusal (§12.13's restart clause) --------------------------
got_refusal=0
for attempt in 1 2 3; do
  if ! SLOG_MAX_MS=2 timeout 600 racket tests/api/abort-drive.rkt out/t6-flavor \
       $PLAIN_TOKENS "abort-refused:$JOIN_SO" > "$WORK/flavor.log" 2>&1; then
    echo "  (flavor drive failed; see $WORK/flavor.log)"; break
  fi
  if grep -q '^REFUSED$' "$WORK/flavor.log"; then got_refusal=1; break; fi
done
[ "$got_refusal" -eq 1 ] && pass "flavor-refusal" \
                         || fail "flavor-refusal (no park in 3 attempts)"

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
