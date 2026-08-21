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
set -u
cd "$(dirname "$0")/.."
PASS=0; FAIL=0
ok()  { echo "PASS $1"; PASS=$((PASS+1)); }
bad() { echo "FAIL $1"; FAIL=$((FAIL+1)); }

OUT=out/multiplan-tests
mkdir -p "$OUT"
raco make compiler/run.rkt >/dev/null 2>&1

run_one() {  # name prog multiplan force_arm
  local name="$1" prog="$2" mp="$3" force="$4"
  rm -rf "$OUT/$name"
  local env=(SLOG_OPT=interp)
  [ -n "$mp" ] && env+=(SLOG_MULTIPLAN=1)
  [ -n "$force" ] && env+=(SLOG_FORCE_ARM="$force")
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

# --- 5. out-of-range force falls back to the selector's pick ----------------
run_one armbig flip_mini 1 7
if diff <(LC_ALL=C sort "$OUT/armbig/walk.csv") \
        <(LC_ALL=C sort "$OUT/arm0/walk.csv") >/dev/null 2>&1 \
   && [ "$(grep -o 'delta:walk#[01]' "$OUT/armbig/\$stat_work.csv" | sort -u)" = "$w0" ]
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

echo
echo "$PASS passed, $FAIL failed"
[ $FAIL -eq 0 ]
