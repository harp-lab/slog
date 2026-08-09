#!/usr/bin/env bash
#
# T3b slice 1 gate: the default tier classification, end to end
# (docs/t3b-contract.md §3 slice 1, docs/execution-tiers.md §5.3).
#
# Three claims, all over real compiles of real programs:
#
#   1. DESIGNATION -- each stratum's build/<hash>.tiers sidecar records the
#      per-variant tier and reason the emitter actually acted on.
#   2. ZERO CLANG -- a stratum whose every variant is interp-only produces
#      NO .so at all.  This is the slice's payoff (measured at 247 of 499
#      strata over the golden suite) and the thing that silently regresses
#      if someone re-routes the emit path.
#   3. NO SEMANTIC EFFECT -- the same programs under SLOG_TIER_POLICY=all
#      (the pre-slice behavior: every variant emitted) produce byte-identical
#      output.  Selective compilation is a scheduling decision or it is a bug.
#
#   bash tests/tier-classification.sh
#
# Runs at SLOG_OPT=0 with the policy PINNED, so neither the mode-based
# default nor a background -O2 straggler can decide anything here.

set -u
cd "$(dirname "$0")/.."

WORK="$(mktemp -d)"
trap 'rm -rf "$WORK"' EXIT
PASS=0; FAIL=0

pass() { echo "PASS $1"; PASS=$((PASS+1)); }
fail() { echo "FAIL $1"; FAIL=$((FAIL+1)); }

# reach       -- a mixed stratum (interp-only base rule + tiered recursion)
#                plus a pure ground-fact stratum
# shape_facts -- ground facts and projections; several wholly interp-only
#                strata, and the shape the policy is most aggressive about
PROGRAMS=(reach shape_facts)

mkdir -p build out

# run <program> <policy> <outdir> -- compile+run, and echo the .tiers file of
# every stratum the run EXECUTED.  Keyed on the driver's own
# `(fixpoint N "<hash>" ...)` lines rather than on file mtimes: a warm cache
# re-emits nothing, and an mtime-keyed gate would then quietly check a subset
# of the strata (or none) and still report PASS.
run_one() {
  local prog="$1" policy="$2" outdir="$3"
  rm -rf "$outdir"
  if ! SLOG_TIER_POLICY="$policy" SLOG_OPT=0 SLOG_SMT_SOLVERS=mock \
       timeout 900 racket compiler/run.rkt --no-banner --debug-dir "$outdir" \
       "tests/$prog.slog" > "$WORK/$prog.$policy.log" 2>&1; then
    echo "  ($prog under $policy failed to run; see $WORK/$prog.$policy.log)"
    return 1
  fi
  grep -o '(fixpoint [0-9]* "[0-9a-f]*"' "$WORK/$prog.$policy.log" \
    | sed 's/.*"\([0-9a-f]*\)"/build\/\1.tiers/' | sort -u
}

# coverage <tiers-file> -> "<covered> <total>" for the STRATUM.  grep -o, not
# sed: the sidecar is one line carrying a stratum `(coverage c t)` followed by
# a per-kernel one each, and a greedy sed capture silently reports the LAST
# kernel's numbers as the stratum's.
coverage() {
  grep -o '(coverage [0-9]* [0-9]*)' "$1" | head -1 \
    | sed 's/(coverage \([0-9]*\) \([0-9]*\))/\1 \2/'
}

for prog in "${PROGRAMS[@]}"; do
  # ---- 1+2: the classified policy -------------------------------------
  if ! run_one "$prog" classified "out/tier-$prog-classified" \
       > "$WORK/$prog.classified.tiers"; then
    fail "$prog-classified-run"; continue
  fi
  n_tiers=$(wc -l < "$WORK/$prog.classified.tiers")
  if [ "$n_tiers" -eq 0 ]; then
    fail "$prog-sidecar (no .tiers written)"; continue
  fi
  pass "$prog-sidecar ($n_tiers strata recorded)"

  zero=0; violations=0
  while read -r t; do
    [ -n "$t" ] || continue
    # an absent sidecar must be loud: `coverage` would return empty, the
    # defaults below would read that as "fully covered", and the gate would
    # pass while checking nothing
    if [ ! -e "$t" ]; then
      echo "  no sidecar for an executed stratum: $t"
      violations=$((violations+1)); continue
    fi
    read -r cov total <<< "$(coverage "$t")"
    hash=$(basename "$t" .tiers)
    if [ "${cov:-1}" -eq 0 ] && [ "${total:-0}" -gt 0 ]; then
      zero=$((zero+1))
      # the payoff: nothing for the toolchain to build
      if [ -e "build/$hash.so" ] || [ -e "build/$hash.O0.so" ]; then
        echo "  $hash: 0-of-$total covered but an artifact was built"
        violations=$((violations+1))
      fi
    fi
  done < "$WORK/$prog.classified.tiers"

  if [ "$zero" -eq 0 ]; then
    fail "$prog-zero-clang (fixture produced no wholly interp-only stratum)"
  elif [ "$violations" -ne 0 ]; then
    fail "$prog-zero-clang ($violations strata built an artifact anyway)"
  else
    pass "$prog-zero-clang ($zero strata skipped the toolchain entirely)"
  fi

  # every recorded variant must carry a known (tier, reason) pair
  if grep -qE '\(variant [0-9]+ (interp-only|o0-max|tiered) (runs-once|seeded-reentry|iterated|no-join|acyclic-join) (native|interp)\)' \
       "$(head -1 "$WORK/$prog.classified.tiers")"; then
    pass "$prog-designations"
  else
    fail "$prog-designations (no well-formed variant entry in the sidecar)"
  fi

  # ---- 3: the differential --------------------------------------------
  if ! run_one "$prog" all "out/tier-$prog-all" > "$WORK/$prog.all.tiers"; then
    fail "$prog-all-run"; continue
  fi
  # under `all`, coverage is total everywhere -- the pre-slice behavior
  partial=0
  while read -r t; do
    [ -n "$t" ] || continue
    read -r cov total <<< "$(coverage "$t")"
    [ "${cov:-0}" -eq "${total:-0}" ] || partial=$((partial+1))
  done < "$WORK/$prog.all.tiers"
  if [ "$partial" -eq 0 ]; then
    pass "$prog-all-covers-everything"
  else
    fail "$prog-all-covers-everything ($partial strata partially covered)"
  fi

  # identical output under both policies
  diffs=0
  for csv in "out/tier-$prog-classified"/*.csv; do
    [ -e "$csv" ] || continue
    rel="$(basename "$csv")"
    case "$rel" in '$stat_'*) continue ;; esac  # per-run diagnostics
    other="out/tier-$prog-all/$rel"
    if [ ! -e "$other" ]; then
      echo "  $rel missing under policy=all"; diffs=$((diffs+1)); continue
    fi
    if ! diff -q <(LC_ALL=C sort "$csv") <(LC_ALL=C sort "$other") >/dev/null; then
      echo "  $rel differs between policies:"
      diff <(LC_ALL=C sort "$csv") <(LC_ALL=C sort "$other") | head -5 | sed 's/^/    /'
      diffs=$((diffs+1))
    fi
  done
  if [ "$diffs" -eq 0 ]; then
    pass "$prog-policy-differential"
  else
    fail "$prog-policy-differential ($diffs relations differ)"
  fi
done

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
