#!/bin/sh
# Fake SMT solver for the async-plumbing test (tests/smt-solver-tests.sh):
# consumes the query, waits long enough (0.5s) that the fixpoint must actually WAIT
# on in-flight oracle work (database.h EndIterCompletion), logs the call when
# SMT_SOLVER_LOG is set (the dedup/single-solve assertion), answers sat.
cat > /dev/null
sleep 0.5
[ -n "$SMT_SOLVER_LOG" ] && echo "call" >> "$SMT_SOLVER_LOG"
echo sat
