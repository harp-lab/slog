#!/usr/bin/env bash
#
# J1 / SLOG_MULTIPLAN choice-group battery (docs/join-planning-assessment.md).
# Over tests/multiplan/flip_mini.slog (a 1/100-scale card_flip):
#
#   1. flag OFF emits no arm marks (byte-level absence);
#   2. flag ON emits exactly one (arm 0)/(arm 1) sibling pair for the
#      recursive walk rule, sharing rid and the delta:walk base tag;
#   3. the arms are EQUIVALENT: identical walk rows and identical
#      $stat_fires under the shared stripped tag, for the default run,
#      SLOG_FORCE_ARM=0, and SLOG_FORCE_ARM=1;
#   4. $stat_work attributes per arm (a #N-suffixed tag per run, and the
#      two forced runs land on DIFFERENT suffixed tags);
#   5. an out-of-range SLOG_FORCE_ARM falls back to arm 0.
#
set -u
cd "$(dirname "$0")/.."
PASS=0; FAIL=0
ok()  { echo "PASS $1"; PASS=$((PASS+1)); }
bad() { echo "FAIL $1"; FAIL=$((FAIL+1)); }

OUT=out/multiplan-tests
mkdir -p "$OUT"
raco make compiler/run.rkt >/dev/null 2>&1

run_one() {  # name multiplan force_arm
  local name="$1" mp="$2" force="$3"
  rm -rf "$OUT/$name"
  local env=(SLOG_OPT=interp)
  [ -n "$mp" ] && env+=(SLOG_MULTIPLAN=1)
  [ -n "$force" ] && env+=(SLOG_FORCE_ARM="$force")
  env "${env[@]}" timeout 300 racket compiler/run.rkt --no-banner \
    --debug-dir "$OUT/$name" tests/multiplan/flip_mini.slog \
    > "$OUT/$name.log" 2>&1
}

walk_plan() {  # name -> the walk-stratum plan file of that run
  local h
  h=$(grep '^(fixpoint' "$OUT/$1.log" | tail -1 | awk '{gsub(/"/,"",$3); print $3}')
  echo "build/$h.plan"
}

# --- 1. flag off: no arms, program runs -------------------------------------
run_one off "" ""
if [ -e "$OUT/off/walk.csv" ] && [ "$(wc -l < "$OUT/off/walk.csv")" = 20 ]
then ok "off-baseline (20 walk rows)"
else bad "off-baseline"; fi
if grep -q '(attrs (arm ' "$(walk_plan off)" 2>/dev/null
then bad "off-no-arm-marks"
else ok "off-no-arm-marks"; fi

# --- 2. flag on: the arm pair exists ----------------------------------------
run_one on 1 ""
n0=$(grep -o '(attrs (arm 0))' "$(walk_plan on)" | wc -l)
n1=$(grep -o '(attrs (arm 1))' "$(walk_plan on)" | wc -l)
if [ "$n0" = 1 ] && [ "$n1" = 1 ]
then ok "on-arm-pair-emitted"
else bad "on-arm-pair-emitted (arm0 x$n0, arm1 x$n1)"; fi
if [ "$(grep -o '(variant "delta:walk#[01]")' "$(walk_plan on)" | sort -u | wc -l)" = 2 ]
then ok "on-shared-base-tag (#0/#1 pair)"
else bad "on-shared-base-tag"; fi

# --- 3. arm equivalence across default / force 0 / force 1 ------------------
run_one arm0 1 0
run_one arm1 1 1
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

# --- 5. out-of-range force falls back to arm 0 ------------------------------
run_one armbig 1 7
if diff <(LC_ALL=C sort "$OUT/armbig/walk.csv") \
        <(LC_ALL=C sort "$OUT/arm0/walk.csv") >/dev/null 2>&1 \
   && [ "$(grep -o 'delta:walk#[01]' "$OUT/armbig/\$stat_work.csv" | sort -u)" = "$w0" ]
then ok "force-out-of-range-falls-back"
else bad "force-out-of-range-falls-back"; fi

echo
echo "$PASS passed, $FAIL failed"
[ $FAIL -eq 0 ]
