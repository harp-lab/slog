#!/usr/bin/env bash
#
# Spine slice A4 gate (docs/activation-contract.md §7): the frozen
# ProgramChangeSet interface.  Two claims:
#
#   1. THE CORPUS IS OF RECORD -- every tests/activation/*.pcs matches
#      the recorded manifest (tests/activation/CORPUS.sha256).  A diff
#      here is a schema/corpus change, which is JOINT-REVIEW by the
#      roadmap's ownership table; re-record with
#        bash tests/activation-freeze.sh --record
#      only as part of a sanctioned joint change.
#   2. THE CONSUMER'S VERDICTS ARE PINNED -- tests/api/pcs-check.rkt
#      (the program arc's conformance gate) accepts/refuses each corpus
#      file with the frozen outcome, and resolution is deterministic.
#
#   bash tests/activation-freeze.sh [--record]

set -u
cd "$(dirname "$0")/.."

PASS=0; FAIL=0
pass() { echo "PASS $1"; PASS=$((PASS+1)); }
fail() { echo "FAIL $1"; FAIL=$((FAIL+1)); }

MANIFEST=tests/activation/CORPUS.sha256

if [ "${1:-}" = "--record" ]; then
  (cd tests/activation && sha256sum $(ls *.pcs | LC_ALL=C sort)) > "$MANIFEST"
  echo "recorded $(grep -c . "$MANIFEST") corpus files into $MANIFEST"
  exit 0
fi

# 1. the corpus manifest
if [ ! -f "$MANIFEST" ]; then
  fail "corpus-manifest (missing $MANIFEST; run --record once, jointly)"
else
  if (cd tests/activation && sha256sum -c "$(basename "$MANIFEST")" --quiet 2>/dev/null) \
     && [ "$(ls tests/activation/*.pcs | wc -l)" = "$(grep -c . "$MANIFEST")" ]; then
    pass "corpus-manifest ($(grep -c . "$MANIFEST") files, all recorded)"
  else
    fail "corpus-manifest (corpus diverges from record -- joint review + --record)"
  fi
fi

# 2. pinned verdicts
check() { # file expected-first-token expected-detail-regex
  local out
  out=$(racket tests/api/pcs-check.rkt "tests/activation/$1" 2>&1 | head -1)
  if echo "$out" | grep -qE "$2"; then
    pass "$1"
  else
    fail "$1 (got: $out)"
  fi
}
check minimal.pcs           '^\(accepted .* \(rebuild 1\) \(carry 1\)'
check minimal-live.pcs      '^\(accepted .* \(rebuild 1\) \(carry 1\)'
check two-instance.pcs      '^\(accepted .* \(rebuild 3\) \(carry 2\)'
check two-instance-live.pcs '^\(accepted .* \(rebuild 2\) \(carry 4\)'
check suffix-batch.pcs      '^\(accepted .* \(suffix 1\)\)'
check carries-refusal.pcs   '^\(refused fixture-refusal'
check suffix-program.pcs    '^\(refused historical-program-replacement'

# 3. determinism: same fixture, same synthetic base -> byte-identical verdict
a=$(racket tests/api/pcs-check.rkt tests/activation/two-instance-live.pcs 2>&1)
b=$(racket tests/api/pcs-check.rkt tests/activation/two-instance-live.pcs 2>&1)
[ -n "$a" ] && [ "$a" = "$b" ] && pass "verdict-deterministic" \
                               || fail "verdict-deterministic"

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
