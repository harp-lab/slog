#!/usr/bin/env bash
#
# Cardinality-based plan-selection study (companion to
# docs/join-planning-assessment.md).  Ten self-generating programs -- no
# external DBs; stratum 0 builds the pathological data with (+ x 1)-style
# rules -- that reproduce the four blowup classes runtime plan selection
# must fix, each paired with an oracle twin computing the identical answer:
#
#   card_bait / card_bait_good      driver join-score baited by a constant
#                                   column (the literal foo/bar/baz/boo);
#                                   spelling-independent; linear class
#   card_skew_a / _a_good / _b     congruent drivers, tie broken by source
#                                   order; opposite-skew twin datasets share
#                                   one plan (the impossibility case; J2)
#   card_corr / card_corr_good     ALL per-relation stats tie; composition
#                                   alone decides (gates entry measurement)
#   card_flip_ac / _ca / _oracle   recursive; profitable tail order flips
#                                   mid-fixpoint; sizes constant (gates
#                                   per-iteration measurement / tripwire)
#   card_monster_ac / _ca          one driver tuple's subtree = ~1e9 probes
#                                   in ONE iteration (gates mid-subtree
#                                   rescue; R1 support matrix)
#
# NOT part of any default battery: run manually, or from a future opt-in
# cardsel tier.  CARD_ASSERT=1 enforces the ratio gates (exit 1 on miss).
#
#   bench/card-study.sh              report only
#   CARD_ASSERT=1 bench/card-study.sh   assert ratio gates
#
set -u
cd "$(dirname "$0")/.."
TIMEOUT="${TIMEOUT:-600}"
TIER="${TIER:-interp}"
OUT=out/card-study
mkdir -p "$OUT"
raco make compiler/run.rkt >/dev/null 2>&1

declare -A QMS WALL ROWS
run_one() {  # prog [key] [extra env...]
  local p="$1" key="${2:-$1}"; shift; shift 2>/dev/null || true
  local log="$OUT/$key.log" dbg="$OUT/$key"
  rm -rf "$dbg"
  local t0 t1
  t0=$(date +%s.%N)
  env SLOG_OPT="$TIER" "$@" timeout "$TIMEOUT" racket compiler/run.rkt \
    --no-banner --debug-dir "$dbg" "bench/$p.slog" > "$log" 2>&1
  local rc=$?
  t1=$(date +%s.%N)
  WALL[$key]=$(awk -v a="$t0" -v b="$t1" 'BEGIN{printf "%.1f", b-a}')
  if [ $rc -ne 0 ]; then
    QMS[$key]=$([ $rc -eq 124 ] && echo TIMEOUT || echo "FAIL($rc)")
    ROWS[$key]=-
  else
    QMS[$key]=$(grep '^(fixpoint' "$log" | tail -1 | awk '{v=$NF; gsub(/\)/,"",v); printf "%.1f", v}')
    local f
    for f in ans walk walkg; do
      [ -e "$dbg/$f.csv" ] && ROWS[$key]=$(wc -l < "$dbg/$f.csv")
    done
  fi
  printf "%-26s %-7s | query-stratum %10s ms | wall %6ss | rows %8s\n" \
         "$key" "$TIER" "${QMS[$key]}" "${WALL[$key]}" "${ROWS[$key]:--}"
}

PROGS="card_bait card_bait_good card_skew_a card_skew_a_good card_skew_b
       card_corr card_corr_good card_flip_ac card_flip_ca card_flip_oracle
       card_monster_ac card_monster_ca"
for p in $PROGS; do run_one "$p"; done

echo
echo "output equivalence (twins must agree):"
fail=0
diffpair() {  # rel a b label
  local a="$OUT/$2/$1.csv" b="$OUT/$3/$1.csv"
  if [ -e "$a" ] && [ -e "$b" ] && \
     diff -q <(LC_ALL=C sort "$a") <(LC_ALL=C sort "$b") >/dev/null 2>&1
  then echo "  $4: identical"
  else echo "  $4: DIFFER"; fail=1
  fi
}
diffpair ans  card_bait       card_bait_good     "bait    vs bait_good"
diffpair ans  card_skew_a     card_skew_a_good   "skew_a  vs a_good"
diffpair ans  card_corr       card_corr_good     "corr    vs corr_good"
diffpair walk card_flip_ac    card_flip_ca       "flip_ac vs flip_ca"
diffpair walk card_flip_ac    card_flip_oracle   "flip_ac vs oracle"
diffpair walk card_monster_ac card_monster_ca    "monster ac vs ca"

echo
echo "-- runtime selection (SLOG_MULTIPLAN=1, unforced; one artifact each) --"
run_one card_bait        bait-mp    SLOG_MULTIPLAN=1 SLOG_MEM_MAX=16G
# the index-policy headline: free mode fits bait's arms into the
# primary-only orderings -- no OOM at the DEFAULT 4G cap, no union build
# free-mode's measured peak RSS is 3.55-3.70G (VmHWM, both 2026-08-24
# daemons) -- ON the default cap's 3.75G soft ceiling, so pass/pause
# flipped with allocator noise.  6G steps off the knife edge while
# keeping the leg's point: free mode fits in modest memory where the
# eager arm-union needs the 16G-class cap above.
run_one card_bait        bait-fr    SLOG_MULTIPLAN=1 SLOG_MULTIPLAN_INDEX=free SLOG_MEM_MAX=6G
run_one card_skew_a      skew_a-mp  SLOG_MULTIPLAN=1
run_one card_skew_b      skew_b-mp  SLOG_MULTIPLAN=1
run_one card_corr        corr-mp    SLOG_MULTIPLAN=1
run_one card_flip_ac     flip_ac-mp SLOG_MULTIPLAN=1
run_one card_flip_ca     flip_ca-mp SLOG_MULTIPLAN=1
run_one card_monster_ac  monster-mp SLOG_MULTIPLAN=1
echo "-- the V4 tripwire + rescue (mid-iteration blowups) --"
run_one card_probe_blind pblind-mp     SLOG_MULTIPLAN=1
run_one card_probe_blind pblind-oracle SLOG_MULTIPLAN=1 SLOG_FORCE_ARM=1
run_one card_probe_late  plate-mp      SLOG_MULTIPLAN=1
run_one card_probe_late  plate-oracle  SLOG_MULTIPLAN=1 SLOG_FORCE_ARM=1
run_one card_probe_rate  prate-mp      SLOG_MULTIPLAN=1
run_one card_probe_rate  prate-oracle  SLOG_MULTIPLAN=1 SLOG_FORCE_ARM=1

echo "-- J3 native dominant-arm promotion (SLOG_OPT=0) --"
run_one card_native nat-off SLOG_MULTIPLAN=1 SLOG_OPT=0
run_one card_native nat-on  SLOG_MULTIPLAN=1 SLOG_OPT=0 SLOG_NATIVE_ARM=0
sumfix() { grep '^(fixpoint' "$OUT/$1.log" | awk '{v=$NF; gsub(/\)/,"",v); s+=v} END{printf "%.1f", s}'; }
NOFF=$(sumfix nat-off); NON=$(sumfix nat-on)
nr=$(awk -v a="$NOFF" -v b="$NON" 'BEGIN{ if (b==0) print "n/a"; else printf "%.2f", a/b }')
echo "  native promotion: interp-arms ${NOFF}ms / native-pinned ${NON}ms = ${nr}x"
nok=$(awk -v r="$nr" 'BEGIN{print (r>=1.2) ? "PASS" : "MISS"}')
printf "  %-32s %8sx (gate >= 1.2x)  %s\n" "nat-off / nat-on (summed fixpoint)" "$nr" "$nok"
[ "$nok" = MISS ] && fail=1

echo
echo "-- J3 phase 2: the pinned tripwire at the default floor (SLOG_OPT=0) --"
# card_betray pins its a-first arm natively; the arm betrays at step 10
# (~18M meter ticks/epoch vs the 1e6+rate default ceiling).  The tripped
# leg pays ONE exploded epoch then hands off to the interp sibling; the
# held-pin control (SLOG_NO_RESCUE) pays all ten.  SLOG_NO_NATIVE_RESCUE
# isolates the phase-2 epoch-close tripwire (phase 3 would otherwise
# trip MID-epoch -- the bmon gate below owns that).
run_one card_betray bet-pin  SLOG_MULTIPLAN=1 SLOG_OPT=0 SLOG_NATIVE_ARM=0 \
                             SLOG_ARM_DEBUG=1 SLOG_NO_ARM_ADVISORIES=1 \
                             SLOG_NO_NATIVE_RESCUE=1
run_one card_betray bet-held SLOG_MULTIPLAN=1 SLOG_OPT=0 SLOG_NATIVE_ARM=0 \
                             SLOG_NO_RESCUE=1 SLOG_NO_ARM_ADVISORIES=1
BP=$(sumfix bet-pin); BH=$(sumfix bet-held)
btr=$(awk -v a="$BH" -v b="$BP" 'BEGIN{ if (b==0) print "n/a"; else printf "%.2f", a/b }')
btu=$(grep -c 'UNPIN' "$OUT/bet-pin.log")
echo "  betrayal: held-pin ${BH}ms / tripped ${BP}ms = ${btr}x (UNPINs: $btu)"
btok=$(awk -v r="$btr" -v u="$btu" 'BEGIN{print (r>=2 && u==1) ? "PASS" : "MISS"}')
printf "  %-32s %8sx (gate >= 2x, 1 unpin)  %s\n" "bet-held / bet-pin (summed fixpoint)" "$btr" "$btok"
[ "$btok" = MISS ] && fail=1

echo
echo "-- J3 phase 3: mid-epoch native rescue at the default floor (SLOG_OPT=0) --"
# card_betray_monster's poison is ONE ~200M-tick epoch: phase 3 trips
# mid-epoch at ~1e6 ticks and rescues the bucket onto the interp
# sibling; the phase-2 control (SLOG_NO_NATIVE_RESCUE) pays the whole
# epoch natively before its epoch-close unpin.
run_one card_betray_monster bmon-p3 SLOG_MULTIPLAN=1 SLOG_OPT=0 SLOG_NATIVE_ARM=0 \
                                    SLOG_ARM_DEBUG=1 SLOG_NO_ARM_ADVISORIES=1
run_one card_betray_monster bmon-p2 SLOG_MULTIPLAN=1 SLOG_OPT=0 SLOG_NATIVE_ARM=0 \
                                    SLOG_ARM_DEBUG=1 SLOG_NO_ARM_ADVISORIES=1 \
                                    SLOG_NO_NATIVE_RESCUE=1
BM3=$(sumfix bmon-p3); BM2=$(sumfix bmon-p2)
bmr=$(awk -v a="$BM2" -v b="$BM3" 'BEGIN{ if (b==0) print "n/a"; else printf "%.2f", a/b }')
bmu=$(grep -c 'NATIVE-RESCUE' "$OUT/bmon-p3.log")
echo "  mid-epoch rescue: phase-2 ${BM2}ms / phase-3 ${BM3}ms = ${bmr}x (rescues: $bmu)"
bmok=$(awk -v r="$bmr" -v u="$bmu" 'BEGIN{print (r>=2 && u>=1) ? "PASS" : "MISS"}')
printf "  %-32s %8sx (gate >= 2x, >=1 rescue)  %s\n" "bmon-p2 / bmon-p3 (summed fixpoint)" "$bmr" "$bmok"
[ "$bmok" = MISS ] && fail=1

echo
echo "ratio gates (bad-plan / oracle query-stratum ms):"
gate() {  # bad good min label
  local r
  r=$(awk -v a="${QMS[$1]}" -v b="${QMS[$2]}" \
        'BEGIN{ if (a+0!=a || b+0!=b || b==0) print "n/a"; else printf "%.1f", a/b }')
  # n/a means a leg TIMEOUT/FAILed -- an unmeasurable gate is a failed
  # gate under CARD_ASSERT, never a silent skip
  local ok="MISS"
  if [ "$r" != "n/a" ]; then
    ok=$(awk -v r="$r" -v m="$3" 'BEGIN{print (r>=m) ? "PASS" : "MISS"}')
  fi
  printf "  %-28s %8sx (gate >= %sx)  %s\n" "$4" "$r" "$3" "$ok"
  [ "$ok" = MISS ] && fail=1
}
gate card_bait        card_bait_good    2  "bait / bait_good"
gate card_skew_a      card_skew_a_good  50 "skew_a / a_good (spelling)"
gate card_skew_a      card_skew_b       50 "skew_a / skew_b (same plan)"
gate card_corr        card_corr_good    5  "corr / corr_good"
gate card_flip_ac     card_flip_oracle  10 "flip_ac / oracle"
gate card_flip_ca     card_flip_oracle  10 "flip_ca / oracle"
gate card_monster_ac  card_monster_ca   50 "monster ac / ca"

echo
echo "selection gates (SLOG_MULTIPLAN unforced / oracle; small = selector works):"
sgate() {  # mp-key oracle-key max label
  local r
  r=$(awk -v a="${QMS[$1]}" -v b="${QMS[$2]}" \
        'BEGIN{ if (a+0!=a || b+0!=b || b==0) print "n/a"; else printf "%.1f", a/b }')
  # n/a = a leg TIMEOUT/FAILed: fail the gate, never skip it silently
  local ok="MISS"
  if [ "$r" != "n/a" ]; then
    ok=$(awk -v r="$r" -v m="$3" 'BEGIN{print (r<=m) ? "PASS" : "MISS"}')
  fi
  printf "  %-32s %8sx (gate <= %sx)  %s\n" "$4" "$r" "$3" "$ok"
  [ "$ok" = MISS ] && fail=1
}
# bait-mp is dominated by the one-time eager index-union build over its
# 18M-row relations (load-sensitive; measured 3.5-7.3x) -- the linear
# class; bait-free below is the shipped fix.  The eager leg also needs
# real RAM headroom: under heavy desktop memory pressure (<~6G
# available) the union build thrashes into TIMEOUT -- verified
# environmental (2026-08-24: pre-change daemon times out identically).
sgate bait-mp    card_bait_good   10 "bait-mp / bait_good"
# bait-free shares bait-mp's load-sensitive floor (18M-row relations;
# measured 4.7-6.6x across runs) -- the gate asserts sanity, not optimum
sgate bait-fr    card_bait_good    8 "bait-free / bait_good (6G cap)"
sgate skew_a-mp  card_skew_a_good  3 "skew_a-mp / a_good"
sgate skew_b-mp  card_skew_b       3 "skew_b-mp / skew_b"
sgate corr-mp    card_corr_good    4 "corr-mp / corr_good"
sgate flip_ac-mp card_flip_oracle  2 "flip_ac-mp / flip_oracle"
sgate flip_ca-mp card_flip_oracle  2 "flip_ca-mp / flip_oracle"
sgate monster-mp card_monster_ca   4 "monster-mp / monster_ca"

echo
echo "rescue gates (mid-iteration blowups; small = tripwire+rescue works):"
sgate pblind-mp  pblind-oracle  3 "probe_blind-mp / oracle"
sgate plate-mp   plate-oracle   3 "probe_late-mp / oracle"
sgate prate-mp   prate-oracle   3 "probe_rate-mp / oracle"

if [ "${CARD_ASSERT:-0}" = 1 ] && [ $fail -ne 0 ]; then
  echo "CARD_ASSERT: gate or equivalence failure"; exit 1
fi
exit 0
