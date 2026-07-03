#!/usr/bin/env bash
#
# Scaling demonstration for the pathological star join (bench/hub_tri.slog):
# without filters the fixpoint is O(n^2) in the spoke count, with filters
# O(n) -- so the speedup itself grows linearly with n.  One run per point
# (the effect dwarfs run-to-run noise).
#
#   bench/scaling.sh [n ...]        default: 10000 20000 40000 80000 160000
#
set -u
cd "$(dirname "$0")/.."

NS=("$@")
[ ${#NS[@]} -eq 0 ] && NS=(10000 20000 40000 80000 160000)

mkdir -p build out
raco make slog.rkt >/dev/null 2>&1

evalms() {
  awk '/^\(fixpoint / { v = $NF; gsub(/\)/, "", v); s += v + 0 }
       END { printf "%.1f", s }' "$1"
}

printf "%10s | %12s %12s | %10s\n" "n (spokes)" "off-ms" "on-ms" "speedup"
printf '%.0s-' {1..55}; echo

for n in "${NS[@]}"; do
  python3 - "$n" <<'EOF'
import os, shutil, struct, sys
n = int(sys.argv[1])
enc = lambda v: 0x7FF0000000000000 | (1 << 35) | (v & 0xFFFFFFFF)
d = "data/bench_hub_scale"
shutil.rmtree(d, ignore_errors=True)
os.makedirs(d + "/value.strings")
def rel(name, arity, tuples):
    rd = "%s/table.%s.arity.%d" % (d, name, arity)
    os.makedirs(rd)
    with open(rd + "/0.bin", "wb") as f:
        for t in tuples:
            f.write(struct.pack("<%dQ" % arity, *map(enc, t)))
rel("redge", 2, ((i, 0) for i in range(1, n + 1)))
rel("sedge", 2, ((0, j) for j in range(n + 1, 2 * n + 1)))
rel("tedge", 3, [(90000001, 90000002, 7)])
EOF

  off_log="out/scale-$n-off.log"; on_log="out/scale-$n-on.log"
  SLOG_NO_SEMIJOIN=1 timeout 1800 racket slog.rkt --no-banner \
    -d bench_hub_scale bench/hub_tri.slog > "$off_log" 2>&1 || \
    { echo "n=$n off FAILED"; continue; }
  timeout 1800 racket slog.rkt --no-banner \
    -d bench_hub_scale bench/hub_tri.slog > "$on_log" 2>&1 || \
    { echo "n=$n on FAILED"; continue; }

  off="$(evalms "$off_log")"; on="$(evalms "$on_log")"
  speedup="$(awk -v a="$off" -v b="$on" 'BEGIN { printf "%.0fx", a / (b > 0 ? b : 1) }')"
  printf "%10s | %12s %12s | %10s\n" "$n" "$off" "$on" "$speedup"
done
