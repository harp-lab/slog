#!/usr/bin/env bash
# Compare the scalar join plan with the automatic key-simple join3 plan.
# Evaluation time is the daemon's fixpoint time; compilation and CSV output
# are outside the measurement.  Every result relation is diffed.

set -u
cd "$(dirname "$0")/.."

REPS="${REPS:-3}"
THREADS="${SLOG_THREADS:-8}"
TESTS=("$@")
if [ ${#TESTS[@]} -eq 0 ]; then
  TESTS=(bench/wcoj_hub.slog bench/tri_bipartite.slog bench/tri_er.slog)
fi

mkdir -p build out

evalms() {
  awk '/^\(fixpoint / { v = $NF; gsub(/\)/, "", v); s += v + 0 }
       END { printf "%.3f", s }' "$1"
}

median() {
  printf '%s\n' "$@" | LC_ALL=C sort -g | awk '{ a[NR] = $1 }
    END { print (NR % 2) ? a[(NR+1)/2] : (a[NR/2] + a[NR/2+1]) / 2 }'
}

printf "%-20s | %11s %11s | %9s | %s\n" test binary-ms join3-ms speedup outputs

for t in "${TESTS[@]}"; do
  name="$(basename "$t" .slog)"
  db="$(sed -n 's/^;; db: //p' "$t" | head -1)"
  dbarg=()
  [ -n "$db" ] && dbarg=(-d "$db")
  declare -a binary=() wcoj=()
  ok=identical
  for mode in binary wcoj; do
    outdir="out/wcojbench-$name-$mode"
    rm -rf "$outdir"
    for rep in $(seq "$REPS"); do
      log="out/wcojbench-$name-$mode-$rep.log"
      common=(env TMPDIR=/tmp SLOG_THREADS="$THREADS" SLOG_NO_MEM_CAP=1
              SLOG_OPT=2 timeout 900 racket compiler/run.rkt --no-banner
              "${dbarg[@]}" --debug-dir "$outdir" "$t")
      if [ "$mode" = binary ]; then
        SLOG_NO_WCOJ3=1 "${common[@]}" >"$log" 2>&1
      else
        env -u SLOG_NO_WCOJ3 "${common[@]}" >"$log" 2>&1
      fi
      if [ $? -ne 0 ]; then
        echo "$name/$mode/$rep failed"
        tail -40 "$log"
        exit 1
      fi
      ms="$(evalms "$log")"
      if [ "$mode" = binary ]; then binary+=("$ms"); else wcoj+=("$ms"); fi
    done
  done
  for f in out/wcojbench-"$name"-binary/*.csv; do
    [ -e "$f" ] || continue
    rel="$(basename "$f")"
    case "$rel" in '$stat_'*) continue ;; esac
    if ! diff -q <(LC_ALL=C sort "$f") \
                 <(LC_ALL=C sort "out/wcojbench-$name-wcoj/$rel" 2>/dev/null) \
                 >/dev/null 2>&1; then
      ok="DIFFER($rel)"
    fi
  done
  for f in out/wcojbench-"$name"-wcoj/*.csv; do
    [ -e "$f" ] || continue
    rel="$(basename "$f")"
    case "$rel" in '$stat_'*) continue ;; esac
    [ -e "out/wcojbench-$name-binary/$rel" ] || ok="DIFFER($rel)"
  done
  bm="$(median "${binary[@]}")"
  wm="$(median "${wcoj[@]}")"
  speed="$(awk -v a="$bm" -v b="$wm" 'BEGIN { printf "%.2fx", a / b }')"
  printf "%-20s | %11s %11s | %9s | %s\n" "$name" "$bm" "$wm" "$speed" "$ok"
done
