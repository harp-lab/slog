#!/usr/bin/env bash
#
# J1/J2 SLOG_MULTIPLAN choice-group battery (docs/join-planning-assessment.md).
#
# Dynamic tail arms, over tests/multiplan/flip_mini.slog (1/100-scale
# card_flip):
#   1. flag OFF emits no arm marks;
#   2. flag ON emits exactly one (arm 0 g)/(arm 1 g) sibling pair for the
#      recursive walk rule, sharing rid, gid, and the delta:walk base tag;
#   3. the arms are EQUIVALENT: identical walk rows and identical
#      $stat_fires for default / SLOG_FORCE_ARM=0 / SLOG_FORCE_ARM=1
#      (tail arms share the driver, so entry counts tie -> arm 0 default);
#   4. $stat_work attributes per arm (#N-suffixed tags, different per run);
#   5. an out-of-range SLOG_FORCE_ARM falls back to the selector's pick.
#
# Closed-rule WHOLE-ORDER arms + the J2 counts selector, over
# tests/multiplan/skew_mini_{a,b}.slog (1/500-scale card_skew: identical
# query rule text, mirrored skew):
#   6. the ans rule carries an all:fa/all:fb arm pair sharing one gid;
#   7. UNFORCED, the counts argmin drives from fa on A-skew and fb on
#      B-skew -- opposite arms of one rule text, picked by data;
#   8. per dataset, unforced/forced-0/forced-1 answers are identical, and
#      the ans rule's per-LOC fires total is arm-invariant (per-KEY tags
#      legitimately differ across whole-order arms: driver-named).
#
# V3 measurement layer:
#   9. flip_mini unforced runs BOTH arms across its phases (per-iteration
#      reselection: delta:walk#0 AND #1 work rows in one run), with walk
#      rows identical to flag-off;
#  10. corr_mini's counts TIE exactly (|fa|=|fb|, mirrored shapes); the
#      bounded emission-free probe resolves the tie to all:fa and the
#      answer matches the flag-off run.
#
set -u
cd "$(dirname "$0")/.."
PASS=0; FAIL=0
ok()  { echo "PASS $1"; PASS=$((PASS+1)); }
bad() { echo "FAIL $1"; FAIL=$((FAIL+1)); }

OUT=out/multiplan-tests
mkdir -p "$OUT"
raco make compiler/run.rkt >/dev/null 2>&1

run_one() {  # name prog multiplan force_arm [extra env...]
  local name="$1" prog="$2" mp="$3" force="$4"
  rm -rf "$OUT/$name"
  local env=(SLOG_OPT=interp)
  [ -n "$mp" ] && env+=(SLOG_MULTIPLAN=1)
  [ -n "$force" ] && env+=(SLOG_FORCE_ARM="$force")
  [ $# -gt 4 ] && env+=("${@:5}")
  env "${env[@]}" timeout 300 racket compiler/run.rkt --no-banner \
    --debug-dir "$OUT/$name" "tests/multiplan/$prog.slog" \
    > "$OUT/$name.log" 2>&1
}

last_plan() {  # name -> the last-stratum plan file of that run
  local h
  h=$(grep '^(fixpoint' "$OUT/$1.log" | tail -1 | awk '{gsub(/"/,"",$3); print $3}')
  echo "build/$h.plan"
}

# --- 1. flag off: no arms, program runs -------------------------------------
run_one off flip_mini "" ""
if [ -e "$OUT/off/walk.csv" ] && [ "$(wc -l < "$OUT/off/walk.csv")" = 20 ]
then ok "off-baseline (20 walk rows)"
else bad "off-baseline"; fi
if grep -q '(attrs (arm ' "$(last_plan off)" 2>/dev/null
then bad "off-no-arm-marks"
else ok "off-no-arm-marks"; fi

# --- 2. flag on: the arm pair exists, one gid --------------------------------
run_one on flip_mini 1 ""
gids=$(grep -o '(attrs (arm [01] [0-9]*))' "$(last_plan on)" \
       | sed 's/.*arm [01] \([0-9]*\).*/\1/' | sort -u | wc -l)
narms=$(grep -o '(attrs (arm [01] [0-9]*))' "$(last_plan on)" | wc -l)
if [ "$narms" = 2 ] && [ "$gids" = 1 ]
then ok "on-arm-pair-emitted (2 arms, 1 gid)"
else bad "on-arm-pair-emitted (arms x$narms, gids x$gids)"; fi
if [ "$(grep -o '(variant "delta:walk#[01]")' "$(last_plan on)" | sort -u | wc -l)" = 2 ]
then ok "on-shared-base-tag (#0/#1 pair)"
else bad "on-shared-base-tag"; fi

# --- 3. arm equivalence across default / force 0 / force 1 ------------------
run_one arm0 flip_mini 1 0
run_one arm1 flip_mini 1 1
equiv=1
for pair in "on arm0" "arm0 arm1" "off arm1"; do
  set -- $pair
  diff <(LC_ALL=C sort "$OUT/$1/walk.csv") \
       <(LC_ALL=C sort "$OUT/$2/walk.csv") >/dev/null 2>&1 || equiv=0
done
[ "$equiv" = 1 ] && ok "arm-equivalence (walk rows)" || bad "arm-equivalence"
f0=$(grep 'delta:walk"' "$OUT/arm0/\$stat_fires.csv" | awk '{print $NF}')
f1=$(grep 'delta:walk"' "$OUT/arm1/\$stat_fires.csv" | awk '{print $NF}')
if [ -n "$f0" ] && [ "$f0" = "$f1" ]
then ok "fires-identity (delta:walk $f0 both arms)"
else bad "fires-identity ($f0 vs $f1)"; fi

# --- 4. per-arm work attribution --------------------------------------------
w0=$(grep -o 'delta:walk#[01]' "$OUT/arm0/\$stat_work.csv" | sort -u)
w1=$(grep -o 'delta:walk#[01]' "$OUT/arm1/\$stat_work.csv" | sort -u)
if [ -n "$w0" ] && [ -n "$w1" ] && [ "$w0" != "$w1" ]
then ok "per-arm-work-tags ($w0 vs $w1)"
else bad "per-arm-work-tags ($w0 vs $w1)"; fi

# --- 5. out-of-range force falls back to the SELECTOR's pick -----------------
# (V3: the selector re-measures per iteration, so the fallback run matches
# the unforced run -- including running both arms across the flip's phases)
run_one armbig flip_mini 1 7
if diff <(LC_ALL=C sort "$OUT/armbig/walk.csv") \
        <(LC_ALL=C sort "$OUT/on/walk.csv") >/dev/null 2>&1 \
   && [ "$(grep -o 'delta:walk#[01]' "$OUT/armbig/\$stat_work.csv" | sort -u)" \
        = "$(grep -o 'delta:walk#[01]' "$OUT/on/\$stat_work.csv" | sort -u)" ]
then ok "force-out-of-range-falls-back"
else bad "force-out-of-range-falls-back"; fi

# --- 6. closed-rule whole-order arm pair -------------------------------------
run_one skew_a skew_mini_a 1 ""
run_one skew_b skew_mini_b 1 ""
sp=$(last_plan skew_a)
sarms=$(grep -o '(attrs (arm [0-9] [0-9]*))' "$sp" | wc -l)
sgids=$(grep -o '(attrs (arm [0-9] [0-9]*))' "$sp" \
        | sed 's/.*arm [0-9] \([0-9]*\).*/\1/' | sort -u | wc -l)
if [ "$sarms" = 4 ] && [ "$sgids" = 1 ] \
   && grep -q '(variant "all:fa")' "$sp" && grep -q '(variant "all:fb")' "$sp"
then ok "closed-arm-set (4 drivers, 1 gid, fa+fb present)"
else bad "closed-arm-set (arms x$sarms gids x$sgids)"; fi

# --- 7. the counts selector picks opposite drivers on mirrored data ----------
picked() {  # run -> the ans rule's chosen driver tag from $stat_work
  grep 'skew_mini' "$OUT/$1/\$stat_work.csv" | grep -o 'all:f[ab]' | sort -u
}
pa=$(picked skew_a); pb=$(picked skew_b)
[ "$pa" = "all:fa" ] && ok "counts-pick-A (drives fa)" || bad "counts-pick-A (got: $pa)"
[ "$pb" = "all:fb" ] && ok "counts-pick-B (drives fb)" || bad "counts-pick-B (got: $pb)"

# --- 8. closed-arm equivalence + loc-total fires invariance -------------------
for ds in a b; do
  run_one "skew_${ds}0" "skew_mini_$ds" 1 0
  run_one "skew_${ds}1" "skew_mini_$ds" 1 1
  if diff <(LC_ALL=C sort "$OUT/skew_$ds/ans.csv") \
          <(LC_ALL=C sort "$OUT/skew_${ds}0/ans.csv") >/dev/null 2>&1 \
     && diff <(LC_ALL=C sort "$OUT/skew_${ds}0/ans.csv") \
             <(LC_ALL=C sort "$OUT/skew_${ds}1/ans.csv") >/dev/null 2>&1
  then ok "closed-arm-equivalence ($ds)"
  else bad "closed-arm-equivalence ($ds)"; fi
  # whole-order arms fire under DRIVER-NAMED tags: sum the ans rule's LOC
  ansloc=$(grep -o 'skew_mini_[ab].slog:[0-9]*' "$OUT/skew_${ds}0/\$stat_fires.csv" | sort | tail -1)
  t0=$(grep "$ansloc" "$OUT/skew_${ds}0/\$stat_fires.csv" | awk '{s+=$NF} END{print s+0}')
  t1=$(grep "$ansloc" "$OUT/skew_${ds}1/\$stat_fires.csv" | awk '{s+=$NF} END{print s+0}')
  if [ "$t0" != 0 ] && [ "$t0" = "$t1" ]
  then ok "fires-loc-total ($ds: $t0 both arms)"
  else bad "fires-loc-total ($ds: $t0 vs $t1)"; fi
done

# --- 9. per-iteration reselection: both arms run in ONE unforced run --------
won=$(grep -o 'delta:walk#[01]' "$OUT/on/\$stat_work.csv" | sort -u | wc -l)
if [ "$won" = 2 ]
then ok "per-iteration-reselection (both arms ran)"
else bad "per-iteration-reselection (arms seen: $won)"; fi

# --- 10. measurement resolves tied counts (corr_mini) ------------------------
run_one corr_off corr_mini "" ""
run_one corr_on  corr_mini 1 ""
cpick=$(grep 'corr_mini' "$OUT/corr_on/\$stat_work.csv" | grep -o 'all:f[ab]' | sort -u)
[ "$cpick" = "all:fa" ] && ok "probe-resolves-tie (picked all:fa)" \
                        || bad "probe-resolves-tie (got: $cpick)"
if diff <(LC_ALL=C sort "$OUT/corr_on/ans.csv") \
        <(LC_ALL=C sort "$OUT/corr_off/ans.csv") >/dev/null 2>&1
then ok "probe-equivalence (corr_mini ans)"
else bad "probe-equivalence"; fi

# --- 11. the V4 rescue: mid-iteration trip + transplant (pblind_mini) --------
# SLOG_MEASURE_BUDGET=64 makes both arms' probes cap blind on clean rows;
# SLOG_TRIP_FLOOR=2000 lets the 1e5-meter wing trip at mini scale.  The
# deterministic footprint of a rescue: BOTH arm work tags on the walkg
# rule in ONE run, with content and per-loc fires identical to the
# forced-oracle and flag-off runs.
PBENV=(SLOG_MEASURE_BUDGET=64 SLOG_TRIP_FLOOR=2000)
run_one pb_off pblind_mini "" "" "${PBENV[@]}"
run_one pb_on  pblind_mini 1  "" "${PBENV[@]}"
run_one pb_f1  pblind_mini 1  1  "${PBENV[@]}"
if diff <(LC_ALL=C sort "$OUT/pb_on/walkg.csv") \
        <(LC_ALL=C sort "$OUT/pb_off/walkg.csv") >/dev/null 2>&1
then ok "rescue-content (pblind_mini == flag-off)"
else bad "rescue-content"; fi
pbtags=$(grep -o 'delta:walkg#[01]' "$OUT/pb_on/\$stat_work.csv" | sort -u | wc -l)
[ "$pbtags" = 2 ] && ok "rescue-footprint (both arm tags in one run)" \
                  || bad "rescue-footprint (tags: $pbtags)"
pbloc=$(grep -o 'pblind_mini.slog:[0-9]*' "$OUT/pb_on/\$stat_fires.csv" | sort | tail -1)
pt0=$(grep "$pbloc" "$OUT/pb_on/\$stat_fires.csv" | awk '{s+=$NF} END{print s+0}')
pt1=$(grep "$pbloc" "$OUT/pb_f1/\$stat_fires.csv" | awk '{s+=$NF} END{print s+0}')
if [ "$pt0" != 0 ] && [ "$pt0" = "$pt1" ]
then ok "rescue-fires-loc-total ($pt0 rescued == forced)"
else bad "rescue-fires-loc-total ($pt0 vs $pt1)"; fi

# --- 12. the index-policy knobs (SLOG_MULTIPLAN_INDEX) -----------------------
# free == budget:0 (delta needs ride free; zero new FULL orderings):
# flip_mini's alternate tail needs a new b-reverse ordering, so free must
# DROP it (group unmarked: no attrs at all) while budget:1 keeps it;
# skew_mini_a keeps at least one zero-cost whole-order alternative under
# free, with answers identical to eager in every mode.
run_one flip_free flip_mini 1 "" SLOG_MULTIPLAN_INDEX=free
fp=$(last_plan flip_free)
if [ "$(grep -o '(attrs (arm [0-9] [0-9]*))' "$fp" | wc -l)" = 0 ] \
   && diff <(LC_ALL=C sort "$OUT/flip_free/walk.csv") \
           <(LC_ALL=C sort "$OUT/off/walk.csv") >/dev/null 2>&1
then ok "index-free-drops-unrealizable (0 arms, == flag-off)"
else bad "index-free-drops-unrealizable"; fi
run_one flip_b1 flip_mini 1 "" SLOG_MULTIPLAN_INDEX=budget:1
bp=$(last_plan flip_b1)
if [ "$(grep -o '(attrs (arm [0-9] [0-9]*))' "$bp" | wc -l)" = 2 ] \
   && diff <(LC_ALL=C sort "$OUT/flip_b1/walk.csv") \
           <(LC_ALL=C sort "$OUT/off/walk.csv") >/dev/null 2>&1
then ok "index-budget-keeps (2 arms, == flag-off)"
else bad "index-budget-keeps"; fi
run_one skew_free skew_mini_a 1 "" SLOG_MULTIPLAN_INDEX=free
sfp=$(last_plan skew_free)
sfarms=$(grep -o '(attrs (arm [0-9] [0-9]*))' "$sfp" | wc -l)
if [ "$sfarms" -ge 2 ] \
   && diff <(LC_ALL=C sort "$OUT/skew_free/ans.csv") \
           <(LC_ALL=C sort "$OUT/skew_a/ans.csv") >/dev/null 2>&1
then ok "index-free-keeps-zero-cost-arms ($sfarms marked, ans == eager)"
else bad "index-free-keeps-zero-cost-arms ($sfarms)"; fi

# --- 13. J3 native dominant-arm promotion (native_mini) ----------------------
# Under SLOG_OPT=0: without SLOG_NATIVE_ARM the choice rule stays interp
# (no pin marker); with SLOG_NATIVE_ARM=0 arm 0 compiles natively and its
# group PINS (the attach trace's deterministic footprint), with content
# and per-loc fires identical to the pure-interp run.
# (advisories disabled here: a repeat battery run must not find its own
# prior recording and pin the "unpromoted" leg -- section 14 owns the loop)
run_one nat_i  native_mini 1 "" SLOG_ARM_DEBUG=1 SLOG_NO_ARM_ADVISORIES=1
run_one nat_o0 native_mini 1 "" SLOG_ARM_DEBUG=1 SLOG_NO_ARM_ADVISORIES=1 SLOG_OPT=0
run_one nat_on native_mini 1 "" SLOG_ARM_DEBUG=1 SLOG_NO_ARM_ADVISORIES=1 SLOG_OPT=0 SLOG_NATIVE_ARM=0
if [ "$(grep -c 'native, pinned' "$OUT/nat_on.log")" -ge 1 ] \
   && [ "$(grep -c 'native, pinned' "$OUT/nat_o0.log")" = 0 ]
then ok "native-arm-pins (marker on, absent off)"
else bad "native-arm-pins"; fi
natok=1
for pair in "nat_i nat_on" "nat_o0 nat_on"; do
  set -- $pair
  diff <(LC_ALL=C sort "$OUT/$1/walk.csv") \
       <(LC_ALL=C sort "$OUT/$2/walk.csv") >/dev/null 2>&1 || natok=0
done
[ "$natok" = 1 ] && ok "native-arm-content (identical across tiers)" \
                 || bad "native-arm-content"
natloc=$(grep -o 'native_mini.slog:[0-9]*' "$OUT/nat_i/\$stat_fires.csv" | sort | tail -1)
nf0=$(grep "$natloc" "$OUT/nat_i/\$stat_fires.csv" | awk '{s+=$NF} END{print s+0}')
nf1=$(grep "$natloc" "$OUT/nat_on/\$stat_fires.csv" | awk '{s+=$NF} END{print s+0}')
if [ "$nf0" != 0 ] && [ "$nf0" = "$nf1" ]
then ok "native-arm-fires ($nf0 both executors)"
else bad "native-arm-fires ($nf0 vs $nf1)"; fi

# --- 14. J3 phase 1b: the profile loop -----------------------------------
# Run 1 (no overrides) converges, reports (arms ...), and records the
# advisory; run 2 recompiles with it applied and pins NATIVELY with no
# env override.  flip_mini's picks change across its phases, so it must
# never record.  The store is cleaned before and after: battery runs
# leave no cross-suite advisory state.
rm -f build/profile/arms.rktd
run_one loop1 native_mini 1 "" SLOG_ARM_DEBUG=1 SLOG_OPT=0
run_one loop2 native_mini 1 "" SLOG_ARM_DEBUG=1 SLOG_OPT=0
if [ "$(grep -c 'native, pinned' "$OUT/loop1.log")" = 0 ] \
   && [ "$(grep -c 'native, pinned' "$OUT/loop2.log")" -ge 1 ] \
   && grep -q 'native_mini.slog' build/profile/arms.rktd 2>/dev/null
then ok "profile-loop-promotes (run2 pinned via advisory)"
else bad "profile-loop-promotes"; fi
if diff <(LC_ALL=C sort "$OUT/loop1/walk.csv") \
        <(LC_ALL=C sort "$OUT/loop2/walk.csv") >/dev/null 2>&1
then ok "profile-loop-content (identical across the loop)"
else bad "profile-loop-content"; fi
run_one floop flip_mini 1 "" SLOG_ARM_DEBUG=1
if ! grep -q 'flip_mini.slog' build/profile/arms.rktd 2>/dev/null \
   && [ "$(grep -c 'native, pinned' "$OUT/floop.log")" = 0 ]
then ok "profile-loop-negative (flip never converges or records)"
else bad "profile-loop-negative"; fi
rm -f build/profile/arms.rktd

# --- 15. J3 phase 2: the pinned tripwire (betray_mini) -----------------------
# betray_mini is cheap for ten epochs (100 baseline driver rows, arming
# the rate ceiling past the 64-row floor) then explodes for the a-first
# arm.  Pinning that arm natively makes the pin BETRAY: the native work
# meter's epoch close trips (ticks > floor + k*chat*rows at the lowered
# floor), the group unpins (rescues++ = never-advise this run), and the
# interp sibling finishes the walk.  Deterministic: the meter is counts,
# not clocks, so the trip epoch and both work totals are data-exact.
# SLOG_NO_NATIVE_RESCUE isolates the phase-2 backstop: with phase 3 on,
# the betrayed epoch would trip MID-epoch instead (section 17 owns that).
run_one bt_off betray_mini "" ""
run_one bt_pin betray_mini 1 "" SLOG_ARM_DEBUG=1 SLOG_NO_ARM_ADVISORIES=1 \
        SLOG_OPT=0 SLOG_NATIVE_ARM=0 SLOG_TRIP_FLOOR=2000 SLOG_NO_NATIVE_RESCUE=1
run_one bt_nr  betray_mini 1 "" SLOG_ARM_DEBUG=1 SLOG_NO_ARM_ADVISORIES=1 \
        SLOG_OPT=0 SLOG_NATIVE_ARM=0 SLOG_TRIP_FLOOR=2000 SLOG_NO_RESCUE=1
if [ "$(grep -c 'native, pinned' "$OUT/bt_pin.log")" -ge 1 ] \
   && [ "$(grep -c 'UNPIN' "$OUT/bt_pin.log")" = 1 ] \
   && [ "$(grep -c 'UNPIN' "$OUT/bt_nr.log")" = 0 ]
then ok "betray-unpins (one trip; SLOG_NO_RESCUE holds the pin)"
else bad "betray-unpins"; fi
btok=1
for leg in bt_pin bt_nr; do
  diff <(LC_ALL=C sort "$OUT/bt_off/walk.csv") \
       <(LC_ALL=C sort "$OUT/$leg/walk.csv") >/dev/null 2>&1 || btok=0
done
[ "$btok" = 1 ] && ok "betray-content (identical off/tripped/held)" \
                || bad "betray-content"
# the handoff: the tripped leg carries BOTH the native meter's work row
# (unsuffixed tag) and the interp sibling's post-unpin rows, and the trip
# bounds the native ticks well under the held-pin leg's full price
nw=$(grep '"delta:walk"' "$OUT/bt_pin/\$stat_work.csv" | awk '{print $3+0}')
iw=$(grep -c 'delta:walk#' "$OUT/bt_pin/\$stat_work.csv")
hw=$(grep '"delta:walk"' "$OUT/bt_nr/\$stat_work.csv" | awk '{print $3+0}')
bloc=$(grep '"delta:walk"' "$OUT/bt_pin/\$stat_work.csv" | awk '{print $1}' | tr -d '"')
bf0=$(grep "$bloc" "$OUT/bt_off/\$stat_fires.csv" | awk '{s+=$NF} END{print s+0}')
bf1=$(grep "$bloc" "$OUT/bt_pin/\$stat_fires.csv" | awk '{s+=$NF} END{print s+0}')
if [ -n "$nw" ] && [ "$iw" -ge 1 ] && [ -n "$hw" ] \
   && [ "$hw" -ge $((nw * 4)) ] \
   && [ "$bf0" != 0 ] && [ "$bf0" = "$bf1" ]
then ok "betray-handoff (native $nw ticks + interp; held $hw >= 4x; fires $bf0)"
else bad "betray-handoff (nw=$nw iw=$iw hw=$hw fires $bf0/$bf1)"; fi

# --- 16. J3 phase 2: the advisory heal ----------------------------------
# A STALE advisory (cross-dataset skew, simulated by seeding the store
# with the betrayer; the gid is the kernel's deterministic mint, 0 for a
# one-group program) pins with no env override; the run trips, unpins,
# reports the group unconverged at fixpoint, and runslog REMOVES the
# advisory -- the next run compiles unpinned.  Cleaned before and after.
rm -f build/profile/arms.rktd; mkdir -p build/profile
printf '#hash(((%s . 0) . 0))\n' "\"$bloc\"" > build/profile/arms.rktd
run_one bt_heal  betray_mini 1 "" SLOG_ARM_DEBUG=1 SLOG_OPT=0 SLOG_TRIP_FLOOR=2000 \
        SLOG_NO_NATIVE_RESCUE=1
run_one bt_after betray_mini 1 "" SLOG_ARM_DEBUG=1 SLOG_OPT=0 SLOG_TRIP_FLOOR=2000 \
        SLOG_NO_NATIVE_RESCUE=1
if [ "$(grep -c 'native, pinned' "$OUT/bt_heal.log")" -ge 1 ] \
   && [ "$(grep -c 'UNPIN' "$OUT/bt_heal.log")" = 1 ] \
   && ! grep -q 'betray_mini' build/profile/arms.rktd 2>/dev/null \
   && [ "$(grep -c 'native, pinned' "$OUT/bt_after.log")" = 0 ] \
   && diff <(LC_ALL=C sort "$OUT/bt_off/walk.csv") \
           <(LC_ALL=C sort "$OUT/bt_heal/walk.csv") >/dev/null 2>&1
then ok "advisory-heal (stale pin trips, unpins, and unrecords)"
else bad "advisory-heal"; fi
rm -f build/profile/arms.rktd

# --- 17. J3 phase 3: mid-epoch native rescue (betray_monster_mini) -----------
# One poisoned step (I=10, ~40k matches per driver row) inside a 20-step
# walk.  Pinned natively, the poisoned bucket's task trips MID-epoch at
# the first masked check past the ceiling (~2048 ticks at the lowered
# floor), aborts WITHOUT committing anything, and the daemon rescues the
# bucket onto the interp sibling (redo-from-zero -- exactly-once fires by
# construction).  No epoch-close UNPIN fires (the rescue already
# unpinned).  The bm_p2 control disables phase 3: the same run pays the
# full ~400k-tick epoch natively and unpins at epoch close -- the
# phase-2 backstop.  Ticks are counts: both totals are data-exact.
run_one bm_off betray_monster_mini "" ""
run_one bm_pin betray_monster_mini 1 "" SLOG_ARM_DEBUG=1 SLOG_NO_ARM_ADVISORIES=1 \
        SLOG_OPT=0 SLOG_NATIVE_ARM=0 SLOG_TRIP_FLOOR=2000
run_one bm_p2  betray_monster_mini 1 "" SLOG_ARM_DEBUG=1 SLOG_NO_ARM_ADVISORIES=1 \
        SLOG_OPT=0 SLOG_NATIVE_ARM=0 SLOG_TRIP_FLOOR=2000 SLOG_NO_NATIVE_RESCUE=1
if [ "$(grep -c 'NATIVE-RESCUE' "$OUT/bm_pin.log")" -ge 1 ] \
   && [ "$(grep -c 'UNPIN' "$OUT/bm_pin.log")" = 0 ] \
   && [ "$(grep -c 'NATIVE-RESCUE' "$OUT/bm_p2.log")" = 0 ] \
   && [ "$(grep -c 'UNPIN' "$OUT/bm_p2.log")" = 1 ]
then ok "monster-rescue (mid-epoch trip; backstop only when disabled)"
else bad "monster-rescue"; fi
bmok=1
for leg in bm_pin bm_p2; do
  diff <(LC_ALL=C sort "$OUT/bm_off/walk.csv") \
       <(LC_ALL=C sort "$OUT/$leg/walk.csv") >/dev/null 2>&1 || bmok=0
done
[ "$bmok" = 1 ] && ok "monster-rescue-content (identical off/rescued/backstop)" \
                || bad "monster-rescue-content"
# the work bound: a tripped invocation never commits its meter, so the
# rescued leg's native ticks are the SPINE ONLY, orders of magnitude
# under the backstop leg's full monster epoch; the interp handoff rows
# appear under the sibling's tag; per-loc fires stay exact
mn=$(grep '"delta:walk"' "$OUT/bm_pin/\$stat_work.csv" | awk '{print $3+0}')
m2=$(grep '"delta:walk"' "$OUT/bm_p2/\$stat_work.csv" | awk '{print $3+0}')
mi=$(grep -c 'delta:walk#' "$OUT/bm_pin/\$stat_work.csv")
mloc=$(grep '"delta:walk"' "$OUT/bm_pin/\$stat_work.csv" | awk '{print $1}' | tr -d '"')
mf0=$(grep "$mloc" "$OUT/bm_off/\$stat_fires.csv" | awk '{s+=$NF} END{print s+0}')
mf1=$(grep "$mloc" "$OUT/bm_pin/\$stat_fires.csv" | awk '{s+=$NF} END{print s+0}')
if [ -n "$mn" ] && [ -n "$m2" ] && [ "$mi" -ge 1 ] \
   && [ "$m2" -ge $((mn * 50)) ] \
   && [ "$mf0" != 0 ] && [ "$mf0" = "$mf1" ]
then ok "monster-rescue-bound (native $mn vs backstop $m2 ticks; fires $mf0)"
else bad "monster-rescue-bound (mn=$mn m2=$m2 mi=$mi fires $mf0/$mf1)"; fi

echo
echo "$PASS passed, $FAIL failed"
[ $FAIL -eq 0 ]
