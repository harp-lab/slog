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
run_one() {  # prog
  local p="$1" log="$OUT/$1.log" dbg="$OUT/$1"
  rm -rf "$dbg"
  local t0 t1
  t0=$(date +%s.%N)
  SLOG_OPT="$TIER" timeout "$TIMEOUT" racket compiler/run.rkt \
    --no-banner --debug-dir "$dbg" "bench/$p.slog" > "$log" 2>&1
  local rc=$?
  t1=$(date +%s.%N)
  WALL[$p]=$(awk -v a="$t0" -v b="$t1" 'BEGIN{printf "%.1f", b-a}')
  if [ $rc -ne 0 ]; then
    QMS[$p]=$([ $rc -eq 124 ] && echo TIMEOUT || echo "FAIL($rc)")
    ROWS[$p]=-
  else
    QMS[$p]=$(grep '^(fixpoint' "$log" | tail -1 | awk '{v=$NF; gsub(/\)/,"",v); printf "%.1f", v}')
    local f
    for f in ans walk; do
      [ -e "$dbg/$f.csv" ] && ROWS[$p]=$(wc -l < "$dbg/$f.csv")
    done
  fi
  printf "%-22s %-7s | query-stratum %10s ms | wall %6ss | rows %8s\n" \
         "$p" "$TIER" "${QMS[$p]}" "${WALL[$p]}" "${ROWS[$p]:--}"
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
echo "ratio gates (bad-plan / oracle query-stratum ms):"
gate() {  # bad good min label
  local r
  r=$(awk -v a="${QMS[$1]}" -v b="${QMS[$2]}" \
        'BEGIN{ if (a+0!=a || b+0!=b || b==0) print "n/a"; else printf "%.1f", a/b }')
  local ok="?"
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

if [ "${CARD_ASSERT:-0}" = 1 ] && [ $fail -ne 0 ]; then
  echo "CARD_ASSERT: gate or equivalence failure"; exit 1
fi
exit 0
