#!/bin/sh
# Fake solver: answers unsat immediately (the racing test's fast winner);
# logs each call when SMT_SOLVER_LOG is set (the pinning test's re-query
# detector).
cat > /dev/null
[ -n "${SMT_SOLVER_LOG:-}" ] && echo "call" >> "$SMT_SOLVER_LOG"
echo unsat
