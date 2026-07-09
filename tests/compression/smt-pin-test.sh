#!/usr/bin/env bash
#
# Oracle-answer pinning (docs/smt.md §15): a compressed save preserves the
# extern answer tables + smt_bad_formula VERBATIM (unsampled, and their rows
# root the struct-heap trim), and a reload re-ingests them so the solver is
# NEVER re-queried -- answers are inputs discovered during evaluation.
#
# The save runs under the scripted slow-sat solver (symbolic probes: sat).
# The reload runs under fast-unsat WITH a call log: if replay re-queried,
# the probes would flip to unsat (content diff) AND the log would be
# non-empty.  Checked at per=100 (subset write) and per=60 (sampled write +
# struct-heap trimming -- the pinned rows must keep their demand structs and
# formula DAGs alive through the trim).
set -u
cd "$(dirname "$0")/../.."
export SLOG_OPT="${SLOG_OPT:-0}"
EMPTY="$(mktemp -d)/empty.slog"; printf ';; dump loader\n' > "$EMPTY"
PROG=tests/smt/pin.slog
SAT="$PWD/tests/smt/slow-sat.sh"
UNSAT="$PWD/tests/smt/fast-unsat.sh"

make -C daemon >/dev/null 2>&1 || { echo "daemon build failed"; exit 1; }

fail=0
for per in 100 60; do
  rm -rf data/smtpin_c data/smtpin_c.edb out/smtpin_save out/smtpin_load
  SLOG_SMT_SOLVERS="$SAT:5000" \
    racket slog.rkt --no-banner --out-db-compressed smtpin_c --per "$per" \
    --debug-dir out/smtpin_save "$PROG" >/dev/null 2>&1
  LOG="$(mktemp)"
  SLOG_SMT_SOLVERS="$UNSAT" SMT_SOLVER_LOG="$LOG" \
    racket slog.rkt --no-banner -d smtpin_c --debug-dir out/smtpin_load "$EMPTY" \
    >/dev/null 2>&1
  ok=1
  for f in out/smtpin_save/*.csv; do
    r="$(basename "$f")"
    if ! diff <(LC_ALL=C sort "$f") <(LC_ALL=C sort "out/smtpin_load/$r" 2>/dev/null) >/dev/null 2>&1; then
      ok=0; echo "  FAIL per=$per: relation $r differs after reload"
    fi
  done
  calls=$(wc -l < "$LOG" 2>/dev/null || echo 0)
  if [ "$calls" -ne 0 ]; then
    ok=0; echo "  FAIL per=$per: solver re-queried $calls time(s) on replay"
  fi
  grep -q '"sat"' out/smtpin_load/probe.csv 2>/dev/null \
    || { ok=0; echo "  FAIL per=$per: sat probes missing after reload"; }
  grep -q 'non-boolean' out/smtpin_load/caught.csv 2>/dev/null \
    || { ok=0; echo "  FAIL per=$per: pinned smt_bad_formula fact lost"; }
  if [ $ok -eq 1 ]; then echo "  ok   per=$per (answers pinned; zero re-queries)"; else fail=$((fail+1)); fi
  rm -f "$LOG"
  rm -rf data/smtpin_c data/smtpin_c.edb out/smtpin_save out/smtpin_load
done
if [ $fail -eq 0 ]; then echo "smt-pin-test: ALL PASS"; else echo "smt-pin-test: FAILURES"; exit 1; fi
