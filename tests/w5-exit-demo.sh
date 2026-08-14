#!/usr/bin/env bash
#
# The W5' EXIT DEMO (docs/roadmap.md, "Capstone gate, stated as a demo"):
# edit one rule of a loaded two-instance analysis; the successor image
# seals through the ORDINARY producer pipeline (images -> draft -> sealed
# ProgramChangeSet -> frozen .pcs); it activates and heals incrementally
# -- exactly the edited cone rebuilds, the untouched instance, the
# struct-valued relation, and right.edge inside the edited instance all
# carry; `whynot` answers about THE SAME FACT before (present, derivable
# via v1) and after (v2 frontier); the gained fact derives via v2.
#
#   bash tests/w5-exit-demo.sh

set -u
cd "$(dirname "$0")/.."

WORK="$(mktemp -d)"
trap 'rm -rf "$WORK"' EXIT
PASS=0; FAIL=0
pass() { echo "PASS $1"; PASS=$((PASS+1)); }
fail() { echo "FAIL $1"; FAIL=$((FAIL+1)); }

export SLOG_OPT=0
export SLOG_SMT_SOLVERS=mock
mkdir -p build out data

# the producer leg: seal the successor
if ! timeout 900 racket tests/api/build-joint-fixtures.rkt "$WORK/fx" \
     > "$WORK/build.log" 2>&1; then
  echo "  (fixture build failed)"; tail -5 "$WORK/build.log" | sed 's/^/  /'
  fail producer-build; echo "$PASS passed, $FAIL failed"; exit 1
fi
pass producer-build

# its conformance verdict
if racket tests/api/pcs-check.rkt "$WORK/fx/w5-demo.pcs" > "$WORK/verdict" 2>&1; then
  pass demo-fixture-conformant
else
  fail demo-fixture-conformant; sed 's/^/  /' "$WORK/verdict"
fi

# the demo drive: every (w5 NAME 0|1) record must be 1
if ! timeout 900 racket tests/api/w5-demo-drive.rkt \
     tests/reflect/joint/w5-demo-base.slog "$WORK/fx/w5-demo.pcs" \
     > "$WORK/demo.log" 2>&1; then
  echo "  (demo drive failed)"; tail -5 "$WORK/demo.log" | sed 's/^/  /'
  fail demo-drive
else
  pass demo-drive
  while read -r name val; do
    [ "$val" = "1" ] && pass "$name" || fail "$name"
  done < <(sed -n 's/^(w5 \([a-z0-9-]*\) \([01]\))$/\1 \2/p' "$WORK/demo.log")
fi

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
