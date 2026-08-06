#!/usr/bin/env bash
#
# RF1 slice 4: plan goldens of record (docs/rf1-contract.md Slices item 4)
# -- the first installment of slog-reflection §18.7's image-based goldens,
# in textual form.  Plan-layer identity is the run-stable identity (the
# determinism doctrine), so the canonical `.plan` artifacts of four
# representative program classes are pinned as goldens:
#
#   deep_fact      deep_fact-class ground-rule/recursion chains
#   lat_run_base   lattices
#   dem_lambda     demand ($sup supplementary relations; historically the
#                  checkout-path offender, pinned here on purpose)
#   sj_tri         join3/wcoj
#
# A golden is the LC_ALL=C-sorted concatenation of every build/*.plan the
# program's clean compile emits -- each sidecar is one `write` line (D6),
# so the sorted line set IS the plan set, keyed by CONTENT.  Deliberately
# not keyed by filename: the stems are job hashes over pre-simplification
# inputs INCLUDING compiler sources (fast-compile §14), so they churn with
# every compiler edit while the plan bytes -- the identity this gate pins
# -- do not.
#
# Each program compiles TWICE from a clean build/; the two runs must agree
# (the determinism doctrine's recompile-twice stability, per program) and
# match the recorded golden.
#
#   bash tests/plan-goldens.sh             # check against the goldens
#   bash tests/plan-goldens.sh --record    # re-record (after a sanctioned
#                                          # plan-byte change; say so in the
#                                          # commit that carries it)
#
# On a mismatch: if the plan-byte change is intended (a new attribute, a
# re-key), re-record and commit the new goldens WITH the change; if not,
# you have a determinism or emitter regression -- see the .diff under the
# work dir printed in the failure line.

set -u
cd "$(dirname "$0")/.."

PROGRAMS=(deep_fact lat_run_base dem_lambda sj_tri)
GOLD=tests/plan-expected
WORK="$(mktemp -d)"
trap 'rm -rf "$WORK"' EXIT
PASS=0; FAIL=0
mode=check
[ "${1:-}" = "--record" ] && mode=record

compile_plans() { # <program> <outfile>
  rm -rf build config/cache
  # SLOG_OPT=interp, pinned: the plan set is tier-independent (verified
  # against a tiered-default recording), and interp launches no background
  # -O2 compiles -- whose stragglers otherwise race the NEXT iteration's
  # `rm -rf build` (observed: "cannot remove 'build': Directory not empty").
  if ! SLOG_OPT=interp timeout 900 racket compiler/run.rkt --no-banner \
       "tests/$1.slog" > "$WORK/$1.compile.log" 2>&1; then
    echo "FAIL $1 (compile/run failed; see $WORK/$1.compile.log)"
    return 1
  fi
  cat build/*.plan | LC_ALL=C sort > "$2"
}

mkdir -p "$GOLD"
for p in "${PROGRAMS[@]}"; do
  if ! compile_plans "$p" "$WORK/$p.run1"; then FAIL=$((FAIL+1)); continue; fi
  if ! compile_plans "$p" "$WORK/$p.run2"; then FAIL=$((FAIL+1)); continue; fi
  if ! diff "$WORK/$p.run1" "$WORK/$p.run2" > "$WORK/$p.stability.diff"; then
    echo "FAIL $p-stability (two clean compiles disagree; $WORK/$p.stability.diff)"
    FAIL=$((FAIL+1)); continue
  fi
  echo "PASS $p-stability ($(wc -l < "$WORK/$p.run1") plans)"
  PASS=$((PASS+1))
  if [ "$mode" = "record" ]; then
    cp "$WORK/$p.run1" "$GOLD/$p.plans"
    echo "RECORDED $GOLD/$p.plans"
  elif [ ! -f "$GOLD/$p.plans" ]; then
    echo "FAIL $p-golden (no recorded golden; run with --record)"
    FAIL=$((FAIL+1))
  elif diff "$GOLD/$p.plans" "$WORK/$p.run1" > "$WORK/$p.golden.diff"; then
    echo "PASS $p-golden"
    PASS=$((PASS+1))
  else
    cp "$WORK/$p.golden.diff" "out/plan-golden-$p.diff" 2>/dev/null
    echo "FAIL $p-golden (plan bytes moved; out/plan-golden-$p.diff; re-record IF sanctioned)"
    FAIL=$((FAIL+1))
  fi
done

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
