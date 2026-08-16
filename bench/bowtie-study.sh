#!/usr/bin/env bash
#
# Bowtie decomposition case study (docs/static-join-decomposition.md):
# monolithic vs hand-factored bowtie/bridge queries over the planted
# gadget graphs bench_bowtie{,_small} (bench/gen.py bowtie_graph), across
# tiers and with the wcoj search on/off.  Prints summed per-stratum
# fixpoint ms, wall seconds, and output/intermediate row counts; diffs
# each query's output across its variants.
#
#   bench/bowtie-study.sh            full matrix
#   TIMEOUT=1800 bench/bowtie-study.sh
#
set -u
cd "$(dirname "$0")/.."
TIMEOUT="${TIMEOUT:-900}"
mkdir -p out/bowtie-study
raco make compiler/run.rkt >/dev/null 2>&1

evalms() {
  awk '/^\(fixpoint / { v = $NF; gsub(/\)/, "", v); s += v + 0 }
       END { printf "%.1f", s }' "$1"
}

printf "%-28s %-18s %-6s %-4s | %10s %8s | %9s %9s\n" \
       "program" "db" "tier" "wcoj" "fix-ms" "wall-s" "answers" "tri-rows"
printf '%.0s-' {1..105}; echo

run_one() {  # prog db tier wcoj
  local prog="$1" db="$2" tier="$3" wcoj="$4"
  local name; name="$(basename "$prog" .slog)-$db-$tier-$wcoj"
  local out="out/bowtie-study/$name" log="out/bowtie-study/$name.log"
  rm -rf "$out"
  local t0 t1
  t0=$(date +%s.%N)
  if [ "$wcoj" = off ]; then
    SLOG_OPT="$tier" SLOG_NO_WCOJ3=1 timeout "$TIMEOUT" racket compiler/run.rkt \
      --no-banner -d "$db" --debug-dir "$out" "$prog" > "$log" 2>&1
  else
    SLOG_OPT="$tier" timeout "$TIMEOUT" racket compiler/run.rkt \
      --no-banner -d "$db" --debug-dir "$out" "$prog" > "$log" 2>&1
  fi
  local rc=$?
  t1=$(date +%s.%N)
  local wall; wall=$(awk -v a="$t0" -v b="$t1" 'BEGIN { printf "%.1f", b - a }')
  if [ $rc -ne 0 ]; then
    printf "%-28s %-18s %-6s %-4s | %10s %8s | %9s %9s\n" \
           "$(basename "$prog" .slog)" "$db" "$tier" "$wcoj" \
           "$([ $rc -eq 124 ] && echo TIMEOUT || echo "FAIL($rc)")" "$wall" - -
    return
  fi
  local ans=- tri=-
  for f in bt btw bb; do
    [ -e "$out/$f.csv" ] && ans=$(wc -l < "$out/$f.csv")
  done
  [ -e "$out/tri.csv" ] && tri=$(wc -l < "$out/tri.csv")
  printf "%-28s %-18s %-6s %-4s | %10s %8s | %9s %9s\n" \
         "$(basename "$prog" .slog)" "$db" "$tier" "$wcoj" \
         "$(evalms "$log")" "$wall" "$ans" "$tri"
}

# -- interp tier, small graph: exact-cost stats runs ------------------------
for p in bowtie_mono bowtie_mono_adv bowtie_tri; do
  run_one "bench/$p.slog" bench_bowtie_small interp on
done
for p in bowtie_mono bowtie_tri; do
  run_one "bench/$p.slog" bench_bowtie_small interp off
done
run_one bench/bowtie_mono_compute.slog bench_bowtie_small interp on
run_one bench/bowtie_tri_compute.slog  bench_bowtie_small interp on
run_one bench/bowtie_multi_mono.slog   bench_bowtie_small interp on
run_one bench/bowtie_multi_tri.slog    bench_bowtie_small interp on

# -- O2 native, big graph: wall-clock runs ----------------------------------
for p in bowtie_mono bowtie_tri; do
  run_one "bench/$p.slog" bench_bowtie 2 on
  run_one "bench/$p.slog" bench_bowtie 2 off
done
run_one bench/bowtie_mono_compute.slog bench_bowtie 2 on
run_one bench/bowtie_tri_compute.slog  bench_bowtie 2 on
run_one bench/bowtie_bridge_mono.slog  bench_bowtie 2 on
run_one bench/bowtie_bridge_tri.slog   bench_bowtie 2 on
for p in bowtie_multi_mono bowtie_multi_tri; do
  run_one "bench/$p.slog" bench_bowtie 2 on
  run_one "bench/$p.slog" bench_bowtie 2 off
done

# -- cross-variant output diffs ---------------------------------------------
echo
diffpair() {  # relname dirA dirB label
  local rel="$1" a="out/bowtie-study/$2/$1.csv" b="out/bowtie-study/$3/$1.csv"
  if [ -e "$a" ] && [ -e "$b" ]; then
    if diff -q <(LC_ALL=C sort "$a") <(LC_ALL=C sort "$b") >/dev/null 2>&1
    then echo "  $4: identical"
    else echo "  $4: DIFFER"
    fi
  fi
}
echo "output equivalence:"
diffpair bt  bowtie_mono-bench_bowtie-2-on      bowtie_tri-bench_bowtie-2-on      "bt  mono vs tri (O2 on)"
diffpair bt  bowtie_mono-bench_bowtie-2-off     bowtie_tri-bench_bowtie-2-off     "bt  mono vs tri (O2 off)"
diffpair bt  bowtie_mono-bench_bowtie-2-on      bowtie_mono-bench_bowtie-2-off    "bt  mono on vs off"
diffpair btw bowtie_mono_compute-bench_bowtie-2-on bowtie_tri_compute-bench_bowtie-2-on "btw mono vs tri (O2 on)"
diffpair bb  bowtie_bridge_mono-bench_bowtie-2-on  bowtie_bridge_tri-bench_bowtie-2-on  "bb  mono vs tri (O2 on)"
for rel in bt trip bb; do
  diffpair "$rel" bowtie_multi_mono-bench_bowtie-2-on bowtie_multi_tri-bench_bowtie-2-on "$rel multi mono vs tri (O2 on)"
done
diffpair bt bowtie_multi_mono-bench_bowtie-2-on bowtie_multi_mono-bench_bowtie-2-off "bt  multi mono on vs off"
