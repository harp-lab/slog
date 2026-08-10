#!/usr/bin/env bash
#
# T3b slice 4 gate: o0-max honored, and the clang metric
# (docs/t3b-contract.md §3 slice 4; execution-tiers §5.3's "never queued
# for O2", §5.4's "track this as a measured metric").
#
#   1. O0-CAP -- a stratum whose covered variants are all `o0-max` (an
#      acyclic join) builds its -O0 and NEVER claims an -O2: no .so, no
#      .so.building marker, ever.  A recursive control stratum under the
#      same run of the battery DOES claim.
#   2. CLANG REPORT -- a cold run reports nonzero clang work; the warm
#      rerun reports exactly "0 compiles, 0 links, 0 o2 claims".  This is
#      §5.4's zero-clang-warm-runs metric as an observable count.
#
# The queue-priority and budget-arithmetic halves of the slice are pinned
# deterministically in tests/unit/tier-arbiter-tests.rkt (one-worker pool).
#
#   bash tests/tier-arbiter.sh

set -u
cd "$(dirname "$0")/.."

WORK="$(mktemp -d)"
trap 'rm -rf "$WORK"' EXIT
PASS=0; FAIL=0
pass() { echo "PASS $1"; PASS=$((PASS+1)); }
fail() { echo "FAIL $1"; FAIL=$((FAIL+1)); }

export SLOG_OPT=tiered
export SLOG_SMT_SOLVERS=mock
export SLOG_NO_FREEZE=1
unset SLOG_TIER_PROFILE SLOG_TIER_SKIP_MS SLOG_TIER_PROMOTE_MS 2>/dev/null || true

mkdir -p build out

# one program, two interesting strata: a recursive closure (tiered) and an
# acyclic join over its OUTPUT (o0-max) -- reading `path` stratifies the
# join into its own level, so the cap and its control are separate
# artifacts (two rules at one level would share a stratum, and a MIXED
# stratum rightly keeps its O2)
FIX=out/tarb_fixture.slog
cat > "$FIX" <<'EOF'
table (edge int int)
table (other int int)
table (joined int int)
table (path int int)
rule
(edge 1 2)
(edge 2 3)
(edge 3 4)
(other 2 7)
(other 3 9)
rule (edge X Y) --> (path X Y)
rule (path X Y) (edge Y Z) --> (path X Z)
rule (path X Y) (other Y Z) --> (joined X Z)
EOF

run_fix() { # <label> -- tiered run; log keeps stderr (the clang report)
  rm -rf "out/tarb-$1"
  timeout 900 racket compiler/run.rkt --no-banner --debug-dir "out/tarb-$1" \
    "$FIX" > "$WORK/$1.log" 2>&1
}

# ---- discovery + clean slate ------------------------------------------------
run_fix disc || { fail discovery; echo "$PASS passed, $((FAIL+1)) failed"; exit 1; }
HASHES=$(grep -o '(fixpoint [0-9]* "[0-9a-f]*"' "$WORK/disc.log" \
           | sed 's/.*"\([0-9a-f]*\)"/\1/' | sort -u)
O0MAX=""; TIERED=""
for h in $HASHES; do
  if grep -q 'tiered iterated native' "build/$h.tiers" 2>/dev/null; then
    TIERED="$h"
  elif grep -q 'o0-max acyclic-join native' "build/$h.tiers" 2>/dev/null; then
    O0MAX="$h"
  fi
done
if [ -z "$O0MAX" ] || [ -z "$TIERED" ]; then
  fail "discovery (fixture shape: o0max='$O0MAX' tiered='$TIERED')"
  echo "$PASS passed, $FAIL failed"; exit 1
fi
# profiles could make either stratum skip (shared-kernel gotcha) -- clear them
for h in $O0MAX $TIERED; do
  for k in $(grep -o '(key "[0-9a-f]*")' "build/$h.tiers" | sed 's/(key "\(.*\)")/\1/'); do
    rm -f "build/profile/$k.profile"
  done
  # settle any in-flight O2 (claim marker; see tier-promotion.sh), then clean
  if [ -e "build/$h.so.building" ] && [ ! -e "build/$h.so" ]; then
    for i in $(seq 1 180); do [ -e "build/$h.so" ] && break; sleep 1; done
  fi
  rm -f "build/$h.so" "build/$h.O0.so" "build/$h.so.building"
done

# ---- 1: the cold run -- cap vs control -------------------------------------
run_fix cold || fail cold-run
# both O0s land (pool drains before driver exit); give the detached O2 a
# moment to at least CLAIM
ok=1
for h in $O0MAX $TIERED; do
  for i in $(seq 1 60); do [ -e "build/$h.O0.so" ] && break; sleep 1; done
  [ -e "build/$h.O0.so" ] || { echo "  $h built no O0"; ok=0; }
done
[ $ok -eq 1 ] && pass "cold-builds-o0" || fail "cold-builds-o0"

ok=1
# the recursive control claimed an O2 (marker or the artifact itself)
{ [ -e "build/$TIERED.so" ] || [ -e "build/$TIERED.so.building" ]; } \
  || { echo "  tiered control never claimed an O2"; ok=0; }
[ $ok -eq 1 ] && pass "tiered-claims-o2" || fail "tiered-claims-o2"

# the o0-max stratum must never see an O2 -- not now, not after settling
for i in $(seq 1 120); do [ -e "build/$TIERED.so" ] && break; sleep 1; done
ok=1
{ [ -e "build/$O0MAX.so" ] || [ -e "build/$O0MAX.so.building" ]; } \
  && { echo "  o0-max stratum was queued for O2"; ok=0; }
[ $ok -eq 1 ] && pass "o0max-capped" || fail "o0max-capped"

grep -q '\[clang: 0 compiles, 0 links, 0 o2 claims\]' "$WORK/cold.log" \
  && { echo "  cold run reported zero clang"; fail "cold-reports-work"; } \
  || pass "cold-reports-work"

# ---- 2: the warm rerun -- the metric at zero --------------------------------
run_fix warm || fail warm-run
if grep -q '\[clang: 0 compiles, 0 links, 0 o2 claims\]' "$WORK/warm.log"; then
  pass "warm-reports-zero"
else
  echo "  $(grep -o '\[clang:[^]]*\]' "$WORK/warm.log" | head -1)"
  fail "warm-reports-zero"
fi

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
