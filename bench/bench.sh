#!/usr/bin/env bash
#
# Semijoin-filter benchmark: run each bench program with filters OFF
# (SLOG_NO_SEMIJOIN=1) and ON, report summed per-stratum fixpoint times
# (the daemon's "(fixpoint <name> <iters> <ms>)" lines -- pure evaluation,
# no compile/parse/CSV time), and diff the two runs' outputs.
#
#   bench/bench.sh                 full suite
#   bench/bench.sh bench/foo.slog  subset
#   REPS=5 bench/bench.sh          more repetitions (default 3, median)
#
set -u
cd "$(dirname "$0")/.."

REPS="${REPS:-3}"
TESTS=("$@")
if [ ${#TESTS[@]} -eq 0 ]; then
  TESTS=(bench/tri_er.slog bench/cyc4_er.slog bench/cyc5_er.slog
         bench/tri_bipartite.slog bench/clique4_cliques.slog
         bench/hub_tri.slog bench/hub_closing_tri.slog
         bench/walk_hub.slog bench/sg_tree.slog bench/reach_er.slog)
fi

mkdir -p build out
raco make slog.rkt >/dev/null 2>&1

# Sum the fixpoint milliseconds in one run's log.
evalms() {
  awk '/^\(fixpoint / { v = $NF; gsub(/\)/, "", v); s += v + 0 }
       END { printf "%.1f", s }' "$1"
}

# Median of a list of floats.
median() {
  printf '%s\n' "$@" | LC_ALL=C sort -g | awk '{ a[NR] = $1 }
    END { print (NR % 2) ? a[(NR+1)/2] : (a[NR/2] + a[NR/2+1]) / 2 }'
}

printf "%-22s %5s | %10s %10s | %8s | %s\n" \
       "test" "reps" "off-ms" "on-ms" "speedup" "outputs"
printf '%.0s-' {1..80}; echo

for t in "${TESTS[@]}"; do
  name="$(basename "$t" .slog)"
  declare -a offs=() ons=()
  ok="identical"

  # each bench program declares its input database in a ";; db: <name>" line
  db="$(sed -n 's/^;; db: //p' "$t" | head -1)"
  dbarg=()
  [ -n "$db" ] && dbarg=(-d "$db")

  for mode in off on; do
    outdir="out/bench-$name-$mode"
    rm -rf "$outdir"
    for rep in $(seq "$REPS"); do
      log="out/bench-$name-$mode.log"
      if [ "$mode" = off ]; then
        SLOG_NO_SEMIJOIN=1 timeout 900 racket slog.rkt --no-banner \
          "${dbarg[@]}" --debug-dir "$outdir" "$t" > "$log" 2>&1
      else
        timeout 900 racket slog.rkt --no-banner \
          "${dbarg[@]}" --debug-dir "$outdir" "$t" > "$log" 2>&1
      fi
      if [ $? -ne 0 ]; then
        echo "  $name/$mode rep $rep FAILED (see $log)"
        continue 2
      fi
      ms="$(evalms "$log")"
      if [ "$mode" = off ]; then offs+=("$ms"); else ons+=("$ms"); fi
    done
  done

  # outputs must be identical relation-by-relation (sorted)
  for f in out/bench-"$name"-off/*.csv; do
    [ -e "$f" ] || continue
    rel="$(basename "$f")"
    if ! diff -q <(LC_ALL=C sort "$f") \
                 <(LC_ALL=C sort "out/bench-$name-on/$rel" 2>/dev/null) \
         > /dev/null 2>&1; then
      ok="DIFFER($rel)"
    fi
  done
  for f in out/bench-"$name"-on/*.csv; do
    [ -e "$f" ] || continue
    rel="$(basename "$f")"
    [ -e "out/bench-$name-off/$rel" ] || ok="DIFFER($rel)"
  done

  off_med="$(median "${offs[@]}")"
  on_med="$(median "${ons[@]}")"
  speedup="$(awk -v a="$off_med" -v b="$on_med" \
             'BEGIN { printf (b > 0) ? "%.2fx" : "inf", a / (b > 0 ? b : 1) }')"
  printf "%-22s %5s | %10s %10s | %8s | %s\n" \
         "$name" "$REPS" "$off_med" "$on_med" "$speedup" "$ok"
done
