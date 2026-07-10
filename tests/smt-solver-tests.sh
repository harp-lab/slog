#!/usr/bin/env bash
#
# SMT oracle solver-path tests (docs/smt.md) -- the pieces the golden suite's
# deterministic mock backend cannot exercise:
#
#   tests/smt-solver-tests.sh
#
#   1. Async plumbing: tests/smt/async.slog under the scripted slow-sat
#      solver (tests/smt/slow-sat.sh) -- answers flow through the worker
#      pool, the fixpoint's in-flight wait, and the harvest task; asserts
#      every verdict is sat AND the solver ran exactly once per DISTINCT
#      formula (interning dedups re-asks, even across strata).
#   2. Real z3 end-to-end: tests/smt/z3.slog, skipped unless z3 is on PATH
#      or SMT_TEST_Z3 names a binary.
#
# Also runs the C++ unit battery (tests/smt-tests.cpp) first.

set -u
cd "$(dirname "$0")/.."

FAILED=0

note() { echo "== $*"; }
fail() { echo "FAIL: $*"; FAILED=1; }

make -C daemon >/dev/null 2>&1 || { echo "daemon build failed"; exit 1; }

# ---- 0. unit battery ------------------------------------------------------
note "unit battery (tests/smt-tests.cpp)"
mkdir -p build
CXX="${CXX:-clang++}"
if "$CXX" -O1 -Wall -std=c++20 -pthread -fopenmp -Idaemon \
      tests/smt-tests.cpp -o build/smt-tests -lz -lgmp 2>&1 | head -5; then
  Z3BIN="${SMT_TEST_Z3:-$(command -v z3 || true)}"
  if [ -n "$Z3BIN" ]; then
    SMT_TEST_Z3="$Z3BIN" ./build/smt-tests || fail "unit battery"
  else
    ./build/smt-tests || fail "unit battery"
  fi
else
  fail "unit battery build"
fi

# ---- 1. async plumbing + per-formula single-solve -------------------------
note "async plumbing (scripted slow-sat solver)"
LOG="$(mktemp)"
OUT=out/test-smt-async
rm -rf "$OUT"
if SLOG_SMT_SOLVERS="$PWD/tests/smt/slow-sat.sh:5000" SMT_SOLVER_LOG="$LOG" \
     timeout 300 racket slog.rkt --no-banner --debug-dir "$OUT" \
     tests/smt/async.slog > "$OUT.log" 2>&1; then
  sat_rows=$(grep -c 'sat' "$OUT/probe.csv" 2>/dev/null || echo 0)
  later_rows=$(grep -c 'sat' "$OUT/later.csv" 2>/dev/null || echo 0)
  calls=$(wc -l < "$LOG")
  [ "$sat_rows" -eq 3 ]  || fail "async: expected 3 sat probes, got $sat_rows"
  [ "$later_rows" -eq 2 ] || fail "async: expected 2 sat later rows, got $later_rows"
  [ "$calls" -eq 4 ]     || fail "async: expected 4 solver calls (5 asks, 4 distinct formulas), got $calls"
  [ "$FAILED" -eq 0 ] && echo "   ok: 5 asks, $calls solver calls, all sat"
else
  tail -5 "$OUT.log"; fail "async: run error (see $OUT.log)"
fi
rm -f "$LOG"

# ---- 1b. racing: the first definitive verdict wins --------------------------
note "racing (slow-sat vs fast-unsat scripts)"
OUT=out/test-smt-race
rm -rf "$OUT"
if SLOG_SMT_SOLVERS="$PWD/tests/smt/slow-sat.sh|$PWD/tests/smt/fast-unsat.sh:5000" \
     timeout 300 racket slog.rkt --no-banner --debug-dir "$OUT" \
     tests/smt/async.slog > "$OUT.log" 2>&1; then
  unsat_rows=$(grep -c 'unsat' "$OUT/probe.csv" 2>/dev/null || echo 0)
  [ "$unsat_rows" -eq 3 ] \
    || fail "race: expected fast-unsat to win all 3 probes, got $unsat_rows"
  [ "$FAILED" -eq 0 ] && echo "   ok: fast unsat beat the 500ms sat solver on every query"
else
  tail -5 "$OUT.log"; fail "race: run error (see $OUT.log)"
fi

# ---- 2. real z3 (gated) ----------------------------------------------------
Z3BIN="${SMT_TEST_Z3:-$(command -v z3 || true)}"
if [ -z "$Z3BIN" ]; then
  note "z3 end-to-end: SKIPPED (no z3 on PATH; set SMT_TEST_Z3=/path/to/z3)"
else
  note "z3 end-to-end ($Z3BIN)"
  OUT=out/test-smt-z3
  rm -rf "$OUT"
  if SLOG_SMT_SOLVERS="$Z3BIN:8000" \
       timeout 300 racket slog.rkt --no-banner --debug-dir "$OUT" \
       tests/smt/z3.slog > "$OUT.log" 2>&1; then
    check() {  # name expected-verdict
      if ! grep -q "\"$1\" *(_enum \"$2\")" "$OUT/probe.csv" 2>/dev/null; then
        fail "z3: $1 should be $2 (got: $(grep "$1" "$OUT/probe.csv" 2>/dev/null))"
      fi
    }
    check contradiction unsat
    check satisfiable sat
    check tautology sat
    check negated-tautology unsat
    check abs-negative unsat
    check set-contradiction unsat
    check sqrt2 unsat
    [ "$FAILED" -eq 0 ] && echo "   ok: all z3 verdicts correct (incl. ite, set-conjunction, QF_NIA)"
  else
    tail -5 "$OUT.log"; fail "z3: run error (see $OUT.log)"
  fi

  # ---- 2b. model extraction under z3 ---------------------------------------
  note "model extraction under z3 (tests/smt/model-z3.slog)"
  OUT=out/test-smt-model-z3
  rm -rf "$OUT"
  if SLOG_SMT_SOLVERS="$Z3BIN:8000" \
       timeout 300 racket slog.rkt --no-banner --debug-dir "$OUT" \
       tests/smt/model-z3.slog > "$OUT.log" 2>&1; then
    grep -q '"forced" *(_enum "sat")' "$OUT/probe.csv" 2>/dev/null \
      || fail "model: forced probe should be sat"
    grep -q '^5' "$OUT/xval.csv" 2>/dev/null \
      || fail "model: x should be 5 (got: $(cat "$OUT/xval.csv" 2>/dev/null))"
    grep -q '^1' "$OUT/pval.csv" 2>/dev/null \
      || fail "model: p should be 1 (got: $(cat "$OUT/pval.csv" 2>/dev/null))"
    [ "$FAILED" -eq 0 ] && echo "   ok: model values {x:5, p:1} flowed back through cget"
  else
    tail -5 "$OUT.log"; fail "model: run error (see $OUT.log)"
  fi

  # ---- 2b'. bignum model round-trip under z3 (primitives.md §14.7) ---------
  note "bignum model under z3 (tests/smt/bigmodel-z3.slog)"
  OUT=out/test-smt-bigmodel-z3
  rm -rf "$OUT"
  if SLOG_SMT_SOLVERS="$Z3BIN:8000" \
       timeout 300 racket slog.rkt --no-banner --debug-dir "$OUT" \
       tests/smt/bigmodel-z3.slog > "$OUT.log" 2>&1; then
    grep -q '"bigforced" *(_enum "sat")' "$OUT/probe.csv" 2>/dev/null \
      || fail "bigmodel: forced probe should be sat"
    grep -q '^100000000000000000000' "$OUT/xval.csv" 2>/dev/null \
      || fail "bigmodel: x should be 10^20 (got: $(cat "$OUT/xval.csv" 2>/dev/null))"
    grep -q '^1' "$OUT/xok.csv" 2>/dev/null \
      || fail "bigmodel: x should equal (pow 10 20) exactly"
    [ "$FAILED" -eq 0 ] && echo "   ok: solver bignum 10^20 round-tripped exactly through the model map"
  else
    tail -5 "$OUT.log"; fail "bigmodel: run error (see $OUT.log)"
  fi

  # ---- 2c. unsat-core extraction under z3 -----------------------------------
  note "unsat core under z3 (tests/smt/core-z3.slog)"
  OUT=out/test-smt-core-z3
  rm -rf "$OUT"
  if SLOG_SMT_SOLVERS="$Z3BIN:8000" \
       timeout 300 racket slog.rkt --no-banner --debug-dir "$OUT" \
       tests/smt/core-z3.slog > "$OUT.log" 2>&1; then
    grep -q '"contra" *(_enum "unsat")' "$OUT/probe.csv" 2>/dev/null \
      || fail "core: contra probe should be unsat"
    grep -q '^2' "$OUT/blamed.csv" 2>/dev/null \
      || fail "core: expected 2 blamed conjuncts (got: $(cat "$OUT/blamed.csv" 2>/dev/null))"
    [ "$FAILED" -eq 0 ] && echo "   ok: core blamed the 2-conjunct contradiction, not the boolean"
  else
    tail -5 "$OUT.log"; fail "core: run error (see $OUT.log)"
  fi

  # ---- 3. the check-lifting demo under a real solver ----------------------
  note "verify demo under z3 (examples/verify)"
  OUT=out/test-verify-z3
  rm -rf "$OUT"
  if SLOG_SMT_SOLVERS="$Z3BIN:8000" \
       timeout 300 racket slog.rkt --no-banner --debug-dir "$OUT" \
       examples/verify/demo.slog > "$OUT.log" 2>&1; then
    want_elidable() {
      grep -q "\"$1\"" "$OUT/elidable.csv" 2>/dev/null \
        || fail "verify: $1 should be elidable under z3"
    }
    want_kept() {
      grep -q "\"$1\"" "$OUT/kept.csv" 2>/dev/null \
        || fail "verify: $1 should be kept under z3"
    }
    want_elidable const-ok
    want_elidable abs-nonneg     # unknown under mock; PROVEN by the solver
    want_kept const-bad
    want_kept div-nonzero
    grep -q "\"abs-nonneg\"" "$OUT/elidable.csv" 2>/dev/null \
      && ! grep -q "\"abs-nonneg\"" "$OUT/kept.csv" 2>/dev/null \
      && echo "   ok: abs-nonneg lifted to a static fact; div-nonzero stays dynamic"
  else
    tail -5 "$OUT.log"; fail "verify demo: run error (see $OUT.log)"
  fi
fi

if [ "$FAILED" -eq 0 ]; then echo "smt-solver-tests: ALL PASS"; else echo "smt-solver-tests: FAILURES"; exit 1; fi
