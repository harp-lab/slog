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

# ---- 1b: T6 slice (c) -- restart under a DIFFERENT executor -------------------
# The prebuild left both artifacts of the join stratum: the canonical plan
# (the interpreter's runnable) and the .O0.so.  Abort at a mid-read park and
# re-register the OTHER one through the upgrade entry; §12.7 must hold in
# both directions.
JOIN_HASH=$(basename "$JOIN_SO" | sed 's/\.O0\.so//; s/\.so//')
JOIN_PLAN="$(dirname "$JOIN_SO")/$JOIN_HASH.plan"
if [ ! -f "$JOIN_PLAN" ]; then
  fail "swap-prebuild (no plan sidecar beside $JOIN_SO)"
else
  for dir in "interp-to-native:$JOIN_PLAN,$JOIN_SO" \
             "native-to-interp:$JOIN_SO,$JOIN_PLAN"; do
    label="${dir%%:*}"; pair="${dir#*:}"; from="${pair%%,*}"
    got_swap=0
    for attempt in 1 2 3; do
      rm -rf "out/t6-swap-$label"
      if ! SLOG_MAX_MS=2 timeout 600 racket tests/api/abort-drive.rkt \
           "out/t6-swap-$label" $PLAIN_TOKENS "swap:$pair" \
           > "$WORK/swap-$label.log" 2>&1; then
        echo "  (swap drive $label failed; see $WORK/swap-$label.log)"; break
      fi
      if grep -q '^SWAPPED$' "$WORK/swap-$label.log"; then got_swap=1; break; fi
    done
    if [ "$got_swap" -ne 1 ]; then
      fail "swap-$label (no mid-read park in 3 attempts)"
      continue
    fi
    ok=1
    for csv in out/t6-ref/*.csv; do
      rel="$(basename "$csv")"
      # N5/stats-4 (2026-08-11) unified the executors' fire identity
      # (source loc + base tag on both sides), so the mixed-run PER-KEY
      # comparison that T6 (c) originally had to exclude now HOLDS -- and
      # this assertion is its guard.  ($stat_fixpoint stays excluded:
      # wall-clock rows.)
      case "$rel" in '$stat_fixpoint'*) continue ;; esac
      if ! diff -q <(LC_ALL=C sort "$csv") \
                   <(LC_ALL=C sort "out/t6-swap-$label/$rel") > /dev/null 2>&1; then
        echo "  $rel differs after $label swap:"
        diff <(LC_ALL=C sort "$csv") <(LC_ALL=C sort "out/t6-swap-$label/$rel") \
          | head -5 | sed 's/^/    /'
        ok=0
      fi
    done
    [ $ok -eq 1 ] && pass "swap-$label-content" || fail "swap-$label-content"
    # exact-once makes TOTAL instantiations executor-independent: the sum
    # over all $stat_fires rows must equal the reference's sum exactly
    ref_total=$(awk '{n+=$NF} END{print n+0}' out/t6-ref/'$stat_fires.csv')
    swap_total=$(awk '{n+=$NF} END{print n+0}' "out/t6-swap-$label/\$stat_fires.csv")
    if [ "$ref_total" = "$swap_total" ] && [ "$ref_total" != "0" ]; then
      pass "swap-$label-total-fires ($swap_total)"
    else
      fail "swap-$label-total-fires (ref=$ref_total swap=$swap_total)"
    fi
  done
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

# ---- 4: T6 slice (d) -- the oracle-dispatch audit ---------------------------
# Recursion THROUGH the oracle (smt_rec's shape, scaled): each answer gates
# the next formula, so one stratum runs many dispatch/harvest rounds and a
# park can land AFTER a harvest -- the state where, without the staged
# consumption, the drained answers die with the discarded shards and the
# answered set suppresses the re-ask: silently lost answers.  Abort at every
# read park; the final `count` relation must still reach the full chain.
SMTFIX=out/t6_smt_fixture.slog
{
  echo 'include "../lib/smt.slog"'
  echo "table (count int)"
  echo "rule (count 0)"
  echo "rule (count N) (= (sat) (smt_check (llt (ic N) (ic 150)))) (= M (+ N 1))"
  echo "  --> (count M)"
} > "$SMTFIX"
if ! timeout 900 env SLOG_OPT=0 racket compiler/run.rkt --no-banner \
     --debug-dir out/t6-smt-prebuild "$SMTFIX" > "$WORK/smt-prebuild.log" 2>&1; then
  echo "  (smt fixture prebuild failed; see $WORK/smt-prebuild.log)"
  fail smt-prebuild
else
  SMT_SOS=$(grep -oE '/[^ ]*/build/[a-f0-9]+(\.O0)?\.so' "$WORK/smt-prebuild.log" | awk '!seen[$0]++')
  # Target the ORACLE stratum by construction: the evaluation with the
  # largest iteration count in the prebuild log.  (This check originally
  # targeted the LAST .so, which is a trailing 2-iteration stratum -- its
  # early greens were sub-ms-park timing luck, and the abort never actually
  # landed in the oracle recursion this slice exists to test.)  Tokens stay
  # in strata order -- the target is a MIDDLE stratum, and driving strata
  # out of order would compute garbage.
  SMT_TARGET=$(awk 'match($0, /\/[^ ]*\/build\/[a-f0-9]+(\.O0)?\.so/) \
                      { so=substr($0, RSTART, RLENGTH) } \
                    /^\(fixpoint / { it=$4+0; if (it > best) { best=it; bestso=so } } \
                    END { print bestso }' "$WORK/smt-prebuild.log")
  SMT_REF_TOKENS=""; SMT_ABORT_TOKENS=""
  while read -r so; do
    SMT_REF_TOKENS="$SMT_REF_TOKENS plain:$so"
    if [ "$so" = "$SMT_TARGET" ]; then
      SMT_ABORT_TOKENS="$SMT_ABORT_TOKENS abort-many:$so"
    else
      SMT_ABORT_TOKENS="$SMT_ABORT_TOKENS plain:$so"
    fi
  done <<< "$SMT_SOS"
  rm -rf out/t6-smt-ref
  if ! SLOG_MAX_MS=1 timeout 600 racket tests/api/abort-drive.rkt out/t6-smt-ref \
       $SMT_REF_TOKENS > "$WORK/smt-ref.log" 2>&1; then
    echo "  (smt reference failed; see $WORK/smt-ref.log)"; fail smt-reference
  fi
  got=0
  for attempt in 1 2 3 4 5; do
    rm -rf out/t6-smt-abort
    if ! SLOG_MAX_MS=1 timeout 600 racket tests/api/abort-drive.rkt out/t6-smt-abort \
         $SMT_ABORT_TOKENS > "$WORK/smt-abort.log" 2>&1; then
      echo "  (smt abort drive failed; see $WORK/smt-abort.log)"; break
    fi
    n=$(sed -n 's/^ABORTS \([0-9]*\)$/\1/p' "$WORK/smt-abort.log" | tail -1)
    if [ "${n:-0}" -ge 1 ]; then got=1; break; fi
  done
  [ "$got" -eq 1 ] && pass "oracle-aborts-fired ($n)" \
                   || fail "oracle-aborts-fired (no abort landed in 5 attempts)"
  if [ "$got" -eq 1 ]; then
    ok=1
    for csv in out/t6-smt-ref/*.csv; do
      rel="$(basename "$csv")"
      case "$rel" in '$stat_'*) continue ;; esac
      if ! diff -q <(LC_ALL=C sort "$csv") \
                   <(LC_ALL=C sort "out/t6-smt-abort/$rel") > /dev/null 2>&1; then
        echo "  $rel differs after oracle aborts:"
        diff <(LC_ALL=C sort "$csv") <(LC_ALL=C sort "out/t6-smt-abort/$rel") \
          | head -5 | sed 's/^/    /'
        ok=0
      fi
    done
    [ $ok -eq 1 ] && pass "oracle-abort-equivalence" || fail "oracle-abort-equivalence"
  fi
fi

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
