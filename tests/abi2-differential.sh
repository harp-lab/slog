#!/usr/bin/env bash
#
# RF1 slice 2: the ABI-1 vs ABI-2 DIFFERENTIAL.
#
# The airtightness gate (tests/abi2-airtight.sh) checks identity -- keys,
# bindings, partition coverage.  It is blind to the failure mode that actually
# hurt during this slice: splitting one plan into N kernels changes the ARITY
# of every side effect the install performs, and getting that wrong is SILENT.
# Duplicated intern tasks made reach's recursive stratum settle after 2
# iterations instead of 4 and printed a perfectly ordinary
# `(fixpoint 1 "..." 2 0.317)`.  Goldens catch that only where the lost
# derivations happen to reach a checked relation.
#
# So: run each program under BOTH artifact shapes and require agreement on
#   - every stratum's ITERATION COUNT (the fixpoint lines), and
#   - the dumped relation set and contents.
# Iteration counts are the sensitive signal -- they move the moment a delta is
# ingested twice or a read task goes missing, whether or not any output does.
#
#   bash tests/abi2-differential.sh [program.slog ...]

set -u
cd "$(dirname "$0")/.."
WORK="$(mktemp -d)"
trap 'rm -rf "$WORK"' EXIT
PASS=0; FAIL=0

PROGRAMS=("$@")
if [ "${#PROGRAMS[@]}" -eq 0 ]; then
  # a deliberate spread: recursion, structs, lattices, negation, demand,
  # sequences+attachments, WCOJ3, module instances, tycheck/error arms
  PROGRAMS=(tests/reach.slog tests/structs.slog tests/lat_run_base.slog
            tests/neg_wild.slog tests/dem_lambda.slog tests/seq_oracle.slog
            tests/sj_tri.slog tests/n1_instances.slog tests/tycheck_basic.slog)
fi

run_shape() { # <program> <tag> <abi>
  local prog="$1" tag="$2" abi="$3"
  rm -rf build config/cache
  local env_abi=()
  [ "$abi" = "2" ] && env_abi=(SLOG_PLAN_ABI=2)
  env "${env_abi[@]}" SLOG_OPT=interp timeout 900 \
    racket compiler/run.rkt --no-banner --debug-dir "$WORK/out-$tag" "$prog" \
    > "$WORK/log-$tag" 2>&1
  # the fixpoint lines carry (scc name iterations ms): keep scc + iterations,
  # drop the stem (job hashes move when the artifact shape does) and the ms
  grep -o '(fixpoint [0-9]* "[^"]*" [0-9]*' "$WORK/log-$tag" \
    | sed 's/"[^"]*"/STEM/' > "$WORK/iters-$tag"
  (cd "$WORK/out-$tag" 2>/dev/null && ls *.csv 2>/dev/null | LC_ALL=C sort) \
    > "$WORK/rels-$tag"
}

for prog in "${PROGRAMS[@]}"; do
  name="$(basename "$prog" .slog)"
  [ -f "$prog" ] || { echo "SKIP $name (missing)"; continue; }
  run_shape "$prog" "abi1-$name" 1
  run_shape "$prog" "abi2-$name" 2

  if ! diff -q "$WORK/iters-abi1-$name" "$WORK/iters-abi2-$name" >/dev/null; then
    echo "FAIL $name iterations"
    diff "$WORK/iters-abi1-$name" "$WORK/iters-abi2-$name" | head -6 | sed 's/^/    /'
    FAIL=$((FAIL+1)); continue
  fi
  if ! diff -q "$WORK/rels-abi1-$name" "$WORK/rels-abi2-$name" >/dev/null; then
    echo "FAIL $name relation set"
    diff "$WORK/rels-abi1-$name" "$WORK/rels-abi2-$name" | head -6 | sed 's/^/    /'
    FAIL=$((FAIL+1)); continue
  fi
  content_ok=1
  for csv in "$WORK/out-abi1-$name"/*.csv; do
    [ -e "$csv" ] || continue
    rel="$(basename "$csv")"
    case "$rel" in '$stat_'*) continue ;; esac   # per-run diagnostics
    if ! diff -q <(LC_ALL=C sort "$csv") \
                 <(LC_ALL=C sort "$WORK/out-abi2-$name/$rel") >/dev/null 2>&1
    then
      echo "FAIL $name contents ($rel)"; content_ok=0; break
    fi
  done
  if [ "$content_ok" -eq 1 ]; then
    echo "PASS $name ($(wc -l < "$WORK/iters-abi1-$name") strata, $(wc -l < "$WORK/rels-abi1-$name") relations)"
    PASS=$((PASS+1))
  else
    FAIL=$((FAIL+1))
  fi
done

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
