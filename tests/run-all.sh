#!/usr/bin/env bash
#
# Unified test orchestrator (2026-07-10).  Runs every slog test harness and
# prints one summary.
#
# Motivation: there was no single entry point, and in particular the exact-once
# FIRE AUDIT (tests/stats-tests.sh -- the M0 incremental-prep invariant,
# docs/stats.md; docs/incremental.md §8) and the arena/seq C++ batteries were
# run by NO default flow, so a regression in those load-bearing properties
# could land unnoticed.  This wires them in with the golden suite and the other
# specialised harnesses.
#
# Usage:
#   tests/run-all.sh              # full suite (several minutes -- the arc-end run)
#   tests/run-all.sh --quick      # fast subset: unit diag stats arena seq
#   tests/run-all.sh NAME...      # only the named harnesses (see --list)
#   tests/run-all.sh --list       # print the harness names and exit
#
# Harness names (also = full execution order):
#   unit diag stats arena seq counts wcoj3 interp structid golden api tiered pause protocol session incremental-stress compression smt-pin smt-solver
#
# Gating: `smt-solver` self-skips its z3 leg when z3 is not on PATH.  `golden`
# clears build/ by default (correctness is cache-independent), so it is ordered
# after the C++ batteries and re-warms the cache for the heavier harnesses.
#
# Known-benign failures to tolerate: NONE as of 2026-07-10 -- the
# grandparent/nested compressed-save bug and the dem_lambda/mp_basic/demo stale
# goldens were fixed.  If a benign failure reappears, record it in KNOWN_FAIL
# below (harness/case + reason) so genuine regressions still stand out.
KNOWN_FAIL=()   # e.g. ("compression/foo -- <reason + tracking note>")

set -u
cd "$(dirname "$0")/.."
mkdir -p build out
CXX="${CXX:-clang++}"

run_harness() {
  case "$1" in
    unit)        raco test tests/unit/ ;;
    diag)        bash tests/diag-tests.sh ;;
    stats)       bash tests/stats-tests.sh ;;
    golden)      bash tests/run-tests.sh ;;
    api)         bash tests/api-tests.sh ;;
    tiered)      bash tests/tiered-tests.sh ;;
    pause)       bash tests/pause-tests.sh ;;
    protocol)    bash tests/protocol-tests.sh ;;
    session)     bash tests/session-tests.sh ;;
    incremental-stress) bash tests/incremental-stress.sh ;;
    compression) bash tests/compression/run.sh ;;
    smt-pin)     bash tests/compression/smt-pin-test.sh ;;
    smt-solver)  bash tests/smt-solver-tests.sh ;;
    arena)       "$CXX" -O2 -Wall -std=c++20 -pthread -Idaemon tests/arena-tests.cpp -o build/arena-tests -lgmp && ./build/arena-tests ;;
    seq)         "$CXX" -O2 -Wall -std=c++20 -pthread -Idaemon tests/seq-tests.cpp   -o build/seq-tests   -lgmp && ./build/seq-tests ;;
    counts)      "$CXX" -O2 -Wall -std=c++20 -pthread -Idaemon tests/counts-tests.cpp -o build/counts-tests -lgmp && ./build/counts-tests ;;
    wcoj3)       "$CXX" -O2 -Wall -std=c++20 -pthread -Idaemon tests/wcoj3-operator-tests.cpp -o build/wcoj3-operator-tests -lgmp && ./build/wcoj3-operator-tests ;;
    interp)      "$CXX" -O0 -Wall -std=c++20 -pthread -fopenmp -Idaemon -c daemon/plan-flavored-tasks.cpp -o build/plan-flavored-tasks.O0.o && "$CXX" -O2 -Wall -std=c++20 -pthread -fopenmp -Idaemon tests/interp-operator-tests.cpp daemon/plan.cpp daemon/plan-count.cpp daemon/query.cpp daemon/sexp.cpp daemon/runtime.cpp build/plan-flavored-tasks.O0.o -o build/interp-operator-tests -lgmp && ./build/interp-operator-tests ;;
    structid)    "$CXX" -O2 -Wall -std=c++20 -pthread -Idaemon tests/struct-identity-tests.cpp -o build/struct-identity-tests -lgmp && ./build/struct-identity-tests ;;
    *)           echo "run-all: unknown harness '$1'" >&2; return 2 ;;
  esac
}

ALL=(unit diag stats arena seq counts wcoj3 interp structid golden api tiered pause protocol session incremental-stress compression smt-pin smt-solver)
QUICK=(unit diag stats arena seq counts wcoj3 interp structid)

case "${1:-}" in
  --list)  printf '%s\n' "${ALL[@]}"; exit 0 ;;
  --quick) SEL=("${QUICK[@]}") ;;
  "")      SEL=("${ALL[@]}") ;;
  *)       SEL=("$@") ;;
esac

PASS=(); FAIL=()
for h in "${SEL[@]}"; do
  echo; echo "################  $h  ################"
  if run_harness "$h"; then PASS+=("$h"); else FAIL+=("$h"); fi
done

echo; echo "====================  SUMMARY  ===================="
printf 'PASS (%d): %s\n' "${#PASS[@]}" "${PASS[*]:-(none)}"
printf 'FAIL (%d): %s\n' "${#FAIL[@]}" "${FAIL[*]:-(none)}"
[ ${#KNOWN_FAIL[@]} -gt 0 ] && printf 'known-benign (not counted): %s\n' "${KNOWN_FAIL[*]}"
[ ${#FAIL[@]} -eq 0 ]
