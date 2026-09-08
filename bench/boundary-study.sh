#!/usr/bin/env bash
#
# Stratum-boundary index-reuse study (docs/index-reuse.md).  Measures the
# cost of the between-strata boundary on a large resident DB, A/B against
# the pre-reuse behavior (SLOG_NO_INDEX_REUSE=1 forces every relation onto
# the dump + contents-clear + iteration-0-rebuild path).
#
# Two shapes, K strata each, over an n-row edge relation:
#   chain -- stratum i copies r_{i-1} into r_i: the resident DB grows by n
#            rows per stratum, and the OLD boundary re-dumped and rebuilt
#            EVERY relation at EVERY boundary (quadratic-ish waste; the new
#            boundary dumps only the one relation each stratum reads).
#   probe -- stratum i joins r_{i-1} against the SAME probed edge relation
#            (a permutation graph, so sizes stay flat): every stratum
#            re-requisitions edge's probe ordering -- the "two sequenced
#            strata share the same indices" case; the old boundary rebuilt
#            edge's trees K times.
#
#   bench/boundary-study.sh [n [K]]     default n=2000000, K=6
#
# SLOG_OPT is pinned to interp (no clang in the loop; boundary machinery
# and iteration-0 write tasks are tier-independent).  Override by export.
set -u
cd "$(dirname "$0")/.."
mkdir -p build out

N="${1:-2000000}"
K="${2:-6}"
export SLOG_OPT="${SLOG_OPT:-interp}"
export SLOG_BOUNDARY_DEBUG=1

raco make compiler/run.rkt >/dev/null 2>&1

python3 - "$N" <<'EOF'
import os, shutil, struct, sys
n = int(sys.argv[1])
enc = lambda v: 0x7FF0000000000000 | (1 << 35) | (v & 0xFFFFFFFF)
d = "data/bench_boundary"
shutil.rmtree(d, ignore_errors=True)
os.makedirs(d + "/value.strings")
rd = "%s/table.%s.arity.%d" % (d, "edge", 2)
os.makedirs(rd)
with open(rd + "/0.bin", "wb") as f:
    # a permutation with a large stride: functional graph, out-degree 1
    for i in range(n):
        f.write(struct.pack("<2Q", enc(i), enc((i + 7919) % n)))
EOF

gen_prog() { # shape file
  local shape="$1" file="$2"
  {
    echo "table (edge int int)"
    for i in $(seq 1 "$K"); do echo "table (r$i int int)"; done
    if [ "$shape" = chain ]; then
      echo "rule (edge X Y) --> (r1 X Y)"
      for i in $(seq 2 "$K"); do
        echo "rule (r$((i-1)) X Y) --> (r$i X Y)"
      done
    else
      echo "rule (edge X Y) --> (r1 X Y)"
      for i in $(seq 2 "$K"); do
        echo "rule (r$((i-1)) X Y) (edge Y Z) --> (r$i X Z)"
      done
    fi
  } > "$file"
}

sum_ms() { # regex log -> summed trailing-ms of matching lines
  grep -oE "$1" "$2" | awk '{ v=$NF; gsub(/\)/,"",v); s+=v } END { printf "%.0f", s }'
}

printf "%6s | %10s %10s | %10s %10s | %8s\n" \
       "shape" "off-wall-s" "on-wall-s" "off-fix-ms" "on-fix-ms" "speedup"
printf '%.0s-' {1..70}; echo

for shape in chain probe; do
  prog="out/boundary_${shape}.slog"
  gen_prog "$shape" "$prog"
  off_log="out/boundary-$shape-off.log"; on_log="out/boundary-$shape-on.log"

  t0=$(date +%s.%N)
  SLOG_NO_INDEX_REUSE=1 timeout 3600 racket compiler/run.rkt --no-banner \
    -d bench_boundary "$prog" > "$off_log" 2>&1 \
    || { echo "$shape off FAILED"; continue; }
  t1=$(date +%s.%N)
  timeout 3600 racket compiler/run.rkt --no-banner \
    -d bench_boundary "$prog" > "$on_log" 2>&1 \
    || { echo "$shape on FAILED"; continue; }
  t2=$(date +%s.%N)

  offw=$(awk -v a="$t0" -v b="$t1" 'BEGIN{printf "%.1f", b-a}')
  onw=$(awk -v a="$t1" -v b="$t2" 'BEGIN{printf "%.1f", b-a}')
  offf=$(sum_ms '\(fixpoint [^)]*\)' "$off_log")
  onf=$(sum_ms '\(fixpoint [^)]*\)' "$on_log")
  sp=$(awk -v a="$offw" -v b="$onw" 'BEGIN{printf "%.2fx", a/(b>0?b:1)}')
  printf "%6s | %10s %10s | %10s %10s | %8s\n" \
         "$shape" "$offw" "$onw" "$offf" "$onf" "$sp"
  # the sweep's own ms is the LAST (ms X)) on each line; the backfill
  # sub-form carries its own (ms X)) earlier on the line
  echo "  on-mode sweeps: $(grep -c 'boundary-sweep' "$on_log") lines," \
       "summed sweep ms: $(grep -oE '\(ms [0-9.]*\)\)$' "$on_log" | awk '{ v=$2; gsub(/\)/,"",v); s+=v } END { printf "%.0f", s }')," \
       "summed backfill ms: $(grep -oE '\(backfill \(ords [0-9]+\) \(rows [0-9]+\) \(ms [0-9.]*\)' "$on_log" | awk '{ v=$NF; gsub(/\)/,"",v); s+=v } END { printf "%.0f", s }')," \
       "backfilled ords: $(grep -oE '\(backfill \(ords [0-9]+' "$on_log" | awk '{ s+=$NF } END { print s+0 }')"
done
