#!/usr/bin/env bash
#
# The FIRST JOINT BATTERY -- the RF5-B join's opening move
# (docs/activation-contract.md §6, rf5-contract.md §10.1): the program
# arc's producer regenerates the golden corpus's fixtures from its OWN
# sealed diffs (ordinary compiler pipeline -> images -> draft -> sealed
# ProgramChangeSet -> frozen .pcs grammar via compiler/change-pcs.rkt),
# and the runtime arc's consumer resolves them.
#
#   1. CONFORMANCE  -- every emitted fixture is accepted by pcs-check;
#                      the refusal carrier refuses TYPED (fixture-refusal)
#                      before any state could be touched.
#   2. VERDICTS     -- emitted rebuild/retire counts equal the corpus
#                      counterpart's; carries are a superset (the producer
#                      also carries the implicit diagnostic relations).
#   3. NO DRIFT     -- section-level equivalence against the corpus
#                      (tests/api/pcs-compare.rkt): rebuild/retire sets,
#                      roots, cone, writers, occurrences, rule slots, sccs.
#   4. LIVE         -- the emitted minimal-live fixture drives the FULL A2
#                      transaction: path rebuilds 6 -> 3 (removed support
#                      GONE, not shadowed), edge carries, commit narrated.
#   5. CORPUS FROZEN -- the golden corpus manifest is untouched: this
#                      battery consumes the frozen ABI, it does not move it.
#
#   bash tests/rf5-join.sh

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

# ---- the producer leg: regenerate every fixture from real diffs --------
if ! timeout 900 racket tests/api/build-joint-fixtures.rkt "$WORK/fx" \
     > "$WORK/build.log" 2>&1; then
  echo "  (fixture build failed)"; tail -5 "$WORK/build.log" | sed 's/^/  /'
  fail producer-build
  echo "$PASS passed, $((FAIL)) failed"; exit 1
fi
pass producer-build

# ---- 1. conformance ------------------------------------------------------
for f in joint-minimal joint-minimal-live joint-two-instance; do
  if racket tests/api/pcs-check.rkt "$WORK/fx/$f.pcs" > "$WORK/$f.verdict" 2>&1; then
    pass "conformant-$f"
  else
    fail "conformant-$f"; sed 's/^/  /' "$WORK/$f.verdict"
  fi
done
if racket tests/api/pcs-check.rkt "$WORK/fx/joint-refusal.pcs" \
     > "$WORK/joint-refusal.verdict" 2>&1; then
  fail "refusal-refuses (accepted!)"
else
  grep -q '^(refused fixture-refusal' "$WORK/joint-refusal.verdict" \
    && pass "refusal-typed" \
    || { fail "refusal-typed"; sed 's/^/  /' "$WORK/joint-refusal.verdict"; }
fi

# ---- 2. verdict equality (rebuild/retire exact, carry superset) ----------
verdict_field() { sed -n "s/.*(${2} \([0-9]*\)).*/\1/p" "$1"; }
for pair in "joint-minimal minimal" "joint-minimal-live minimal-live" \
            "joint-two-instance two-instance"; do
  set -- $pair
  racket tests/api/pcs-check.rkt "tests/activation/$2.pcs" > "$WORK/$2.verdict" 2>&1
  ok=1
  for fld in rebuild retire; do
    [ "$(verdict_field "$WORK/$1.verdict" $fld)" = \
      "$(verdict_field "$WORK/$2.verdict" $fld)" ] || ok=0
  done
  [ "$(verdict_field "$WORK/$1.verdict" carry)" -ge \
    "$(verdict_field "$WORK/$2.verdict" carry)" ] || ok=0
  [ $ok = 1 ] && pass "verdict-$1" \
              || { fail "verdict-$1"; paste "$WORK/$1.verdict" "$WORK/$2.verdict" | sed 's/^/  /'; }
done

# ---- 3. no drift: section-level equivalence ------------------------------
for pair in "joint-minimal minimal" "joint-minimal-live minimal-live" \
            "joint-two-instance two-instance"; do
  set -- $pair
  if racket tests/api/pcs-compare.rkt "$WORK/fx/$1.pcs" "tests/activation/$2.pcs" \
       > "$WORK/$1.compare" 2>&1; then
    pass "no-drift-$1"
  else
    fail "no-drift-$1"; sed 's/^/  /' "$WORK/$1.compare"
  fi
done

# ---- 4. the live leg: emitted fixture through the full transaction -------
rm -rf data/rf5-join-save
if ! timeout 900 racket tests/api/session-drive.rkt \
     run:tests/reflect/joint/joint-live-base.slog \
     dump-tuples:path \
     activate:"$WORK/fx/joint-minimal-live.pcs" \
     dump-tuples:path dump-tuples:edge \
     > "$WORK/live.log" 2>&1; then
  echo "  (live drive failed)"; tail -5 "$WORK/live.log" | sed 's/^/  /'
  fail live-drive
else
  pass live-drive
  grep -q '^(activated (program ' "$WORK/live.log" \
    && pass "live-commit-narrated" || fail "live-commit-narrated"
  n_before=$(awk '/tupledone/{n++} n==1{exit} /^\(tuplerow/{c++} END{print c+0}' "$WORK/live.log")
  n_path=$(awk '/\(tupledone/{n++} /^\(tuplerow/{if(n==1)c++} END{print c+0}' "$WORK/live.log")
  n_edge=$(awk '/\(tupledone/{n++} /^\(tuplerow/{if(n==2)c++} END{print c+0}' "$WORK/live.log")
  [ "$n_before" = "6" ] && pass "live-base-closure-6" \
                        || fail "live-base-closure-6 (got $n_before)"
  [ "$n_path" = "3" ] && pass "live-removed-support-gone (path 6 -> 3)" \
                      || fail "live-removed-support-gone (got $n_path)"
  [ "$n_edge" = "3" ] && pass "live-carried-relation-intact" \
                      || fail "live-carried-relation-intact (got $n_edge)"
fi

# ---- 5. the corpus did not move ------------------------------------------
if (cd tests/activation && sha256sum --quiet -c CORPUS.sha256 > /dev/null 2>&1); then
  pass corpus-frozen
else
  fail corpus-frozen
fi

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
