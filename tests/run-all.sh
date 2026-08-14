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
#   unit diag stats arena seq counts wcoj3 interp structid golden api tiered pause protocol repl session incremental-stress compression smt-pin smt-solver
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
    repl)        raco test compiler/repl.rkt && cargo test --manifest-path repl/Cargo.toml ;;
    session)     bash tests/session-tests.sh ;;
    joint)       bash tests/joint-battery.sh ;;
    abi2)        bash tests/abi2-airtight.sh && bash tests/abi2-differential.sh ;;
    plan-goldens) bash tests/plan-goldens.sh ;;
    tier-classification) bash tests/tier-classification.sh ;;
    tier-profile) bash tests/tier-profile.sh ;;
    tier-promotion) bash tests/tier-promotion.sh ;;
    tier-arbiter) bash tests/tier-arbiter.sh ;;
    identity-keys) bash tests/identity-keys.sh ;;
    t6-restart) bash tests/t6-restart.sh ;;
    activation-live) bash tests/activation-live.sh ;;
    activation-a3) bash tests/activation-a3.sh ;;
    activation-freeze) bash tests/activation-freeze.sh ;;
    rf5-join)    bash tests/rf5-join.sh ;;
    w5-exit-demo) bash tests/w5-exit-demo.sh ;;
    tu-determinism) bash tests/tu-determinism.sh ;;
    incremental-stress) bash tests/incremental-stress.sh ;;
    compression) bash tests/compression/run.sh ;;
    smt-pin)     bash tests/compression/smt-pin-test.sh ;;
    smt-solver)  bash tests/smt-solver-tests.sh ;;
    arena)       "$CXX" -O2 -Wall -std=c++20 -pthread -Idaemon tests/arena-tests.cpp -o build/arena-tests -lgmp && ./build/arena-tests ;;
    seq)         "$CXX" -O2 -Wall -std=c++20 -pthread -Idaemon tests/seq-tests.cpp   -o build/seq-tests   -lgmp && ./build/seq-tests ;;
    counts)      "$CXX" -O2 -Wall -std=c++20 -pthread -Idaemon tests/counts-tests.cpp -o build/counts-tests -lgmp && ./build/counts-tests ;;
    wcoj3)       "$CXX" -O2 -Wall -std=c++20 -pthread -Idaemon tests/wcoj3-operator-tests.cpp -o build/wcoj3-operator-tests -lgmp && ./build/wcoj3-operator-tests ;;
    interp)      "$CXX" -O0 -Wall -std=c++20 -pthread -fopenmp -Idaemon -c daemon/plan-flavored-tasks.cpp -o build/plan-flavored-tasks.O0.o && "$CXX" -O2 -Wall -std=c++20 -pthread -fopenmp -Idaemon tests/interp-operator-tests.cpp daemon/plan.cpp daemon/plan-count.cpp daemon/query.cpp daemon/sexp.cpp daemon/runtime.cpp build/plan-flavored-tasks.O0.o -o build/interp-operator-tests -lgmp && ./build/interp-operator-tests ;;
    structid)    "$CXX" -O2 -Wall -std=c++20 -pthread -fopenmp -Idaemon tests/struct-identity-tests.cpp -o build/struct-identity-tests -lz -lgmp && ./build/struct-identity-tests ;;
    *)           echo "run-all: unknown harness '$1'" >&2; return 2 ;;
  esac
}

ALL=(unit diag stats arena seq counts wcoj3 interp structid golden plan-goldens tier-classification tier-profile tier-promotion tier-arbiter identity-keys t6-restart activation-live activation-a3 activation-freeze rf5-join w5-exit-demo api tiered pause protocol repl session joint incremental-stress compression smt-pin smt-solver)
# `abi2` (RF1 slice 2's airtightness + the ABI-1/ABI-2 differential) is a
# named tier but NOT in ALL: like plan-determinism it compiles each program
# from cold twice, so it is a slice gate rather than a per-change one.  Run it
# before any change to the plan split, and before the ABI default flips.
# `plan-goldens` (RF1 slice 4: the plan sets of record for four program
# classes, plus per-program recompile-twice stability) IS in ALL: plan-layer
# identity is the golden format of record, and this is its per-change gate
# (~8 cold compiles of small programs).  On a sanctioned plan-byte change,
# re-record with `bash tests/plan-goldens.sh --record` and commit the new
# goldens WITH the change.
# `tier-classification` (T3b slice 1: the default rule-variant tier policy)
# IS in ALL -- it is four small compiles, and it guards two things that fail
# silently otherwise: a stratum designated wholly interp-only must build no
# artifact, and the classified/all policies must produce identical output.
# `tier-profile` (T3b slice 2: the per-KernelPlanKey runtime profile) IS in
# ALL -- four tiered runs of one small fixture, ~2 min.  It guards the
# zero-clang skip against a warm profile with cold artifacts (the post-re-key
# scenario the profile exists for) and both of its escape hatches.
# `tier-promotion` (T3b slice 3: the promotion budget + next-re-entry
# pickup) IS in ALL -- ~2-3 min over one slow chain and one small session.
# It guards the §12.12 self-rescue (stale profile -> interpret past budget
# -> build launches mid-run and attaches), the budget's refusal direction,
# and the session ledger climbing at re-entry instead of interpreting
# forever beside its own built artifact.
# `tier-arbiter` (T3b slice 4: o0-max capped at -O0, the clang metric at
# zero on warm runs) IS in ALL -- one cold + one warm run of a two-strata
# fixture, ~1 min; the queue-priority and budget-arithmetic halves are
# deterministic unit tests (tier-arbiter-tests.rkt).
# `tu-determinism` (T4 slice 2a: comment-stripped generated C++ is
# byte-reproducible across two cold compiles -- the property the .o cache
# and cross-instance sharing key on) is named but OUTSIDE ALL, like abi2:
# ~14 cold compiles including examples/kcfa.  Run it before any emit-cpp
# change and before every T4 slice ships.
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
