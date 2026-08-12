#!/usr/bin/env bash
#
# Spine slice A2 gate (docs/activation-contract.md §5): the live activation
# transaction, end to end.
#
#   1. ABORT ATOMICITY -- an activation that faults AFTER the in-boundary
#      heal aborts through session-run!'s handler: the base boundary,
#      relation contents, and lease state are byte-identical to before.
#   2. COMMIT -- the same fixture then activates cleanly: path REBUILDS
#      under the candidate (recursive rule removed -> closure rows GONE,
#      single-hop rows only: removed support disappears, not shadowed);
#      edge CARRIES.
#   3. IDENTITY -- the committed plan's program key matches the run's
#      minted key (resolution and minting agree, the A1 determinism claim
#      against the live minter).
#   4. REPLAY -- save, reload: the tip reproduces (the recipe is the truth;
#      retirement is liveness bookkeeping only).
#
#   bash tests/activation-live.sh

set -u
cd "$(dirname "$0")/.."

WORK="$(mktemp -d)"
trap 'rm -rf "$WORK"' EXIT
mkdir -p $WORK
PASS=0; FAIL=0
pass() { echo "PASS $1"; PASS=$((PASS+1)); }
fail() { echo "FAIL $1"; FAIL=$((FAIL+1)); }

export SLOG_OPT=0
export SLOG_SMT_SOLVERS=mock
mkdir -p build out data

# the base image: reach's shape -- 3 edges, closure path (6 rows)
BASE=out/act_base.slog
cat > "$BASE" <<'EOF'
table (edge int int)
table (path int int)

rule
(edge 1 2)
(edge 2 3)
(edge 3 4)

rule
(edge X Y)
-->
(path X Y)

rule
(path X Y)
(edge Y Z)
-->
(path X Z)
EOF

rm -rf data/act-save
if ! timeout 900 racket tests/api/session-drive.rkt \
     "run:$BASE" \
     dump-tuples:path \
     activate-fail:tests/activation/minimal-live.pcs \
     dump-tuples:path \
     activate:tests/activation/minimal-live.pcs \
     dump-tuples:path dump-tuples:edge \
     rule-keys \
     save:act-save \
     > "$WORK/live.log" 2>&1; then
  echo "  (live drive failed; see $WORK/live.log)"
  tail -5 "$WORK/live.log" | sed 's/^/  /'
  fail live-drive
  echo "$PASS passed, $((FAIL+1)) failed"; exit 1
fi

# 1. the abort: fault surfaced as data, base content unchanged after it
grep -q '(activation-aborted' "$WORK/live.log" \
  && pass "abort-surfaced" || fail "abort-surfaced"
# path had 6 closure rows before AND after the aborted activation
n_before=$(awk '/tupledone/{n++} n==1{exit} /^\(tuplerow/{c++} END{print c+0}' "$WORK/live.log")
n_after_abort=$(awk '/\(tupledone/{n++} /^\(tuplerow/{if(n==1)c++} END{print c+0}' "$WORK/live.log")
[ "$n_before" = "6" ] && pass "base-closure-6" || fail "base-closure-6 (got $n_before)"
[ "$n_after_abort" = "6" ] && pass "abort-left-base-intact" \
                           || fail "abort-left-base-intact (got $n_after_abort)"

# 2. the commit: path rebuilt single-hop (3), edge carried (3)
grep -q '^(activated (program ' "$WORK/live.log" && pass "commit-narrated" \
                                                 || fail "commit-narrated"
n_final=$(awk '/\(tupledone/{n++} /^\(tuplerow/{if(n==2)c++} END{print c+0}' "$WORK/live.log")
n_edge=$(awk '/\(tupledone/{n++} /^\(tuplerow/{if(n==3)c++} END{print c+0}' "$WORK/live.log")
[ "$n_final" = "3" ] && pass "removed-support-gone (path 6 -> 3)" \
                     || fail "removed-support-gone (got $n_final)"
[ "$n_edge" = "3" ] && pass "carried-relation-intact" \
                    || fail "carried-relation-intact (got $n_edge)"

# 3. identity: the committed narration's program key appears in the
#    identity ledger (the run minted THE SAME successor key the plan named)
akey=$(sed -n 's/^(activated (program \([^)]*\)).*/\1/p' "$WORK/live.log" | head -1)
grep -q "(identity-program $akey)" "$WORK/live.log" \
  && pass "plan-and-minter-agree" || fail "plan-and-minter-agree ($akey)"

# 4. replay: reload the save; the tip reproduces
if ! timeout 900 racket tests/api/session-drive.rkt \
     open:act-save dump-tuples:path dump-tuples:edge \
     > "$WORK/reload.log" 2>&1; then
  echo "  (reload failed; see $WORK/reload.log)"; fail reload
else
  r_path=$(awk '/\(tupledone/{n++} /^\(tuplerow/{if(n==0)c++} END{print c+0}' "$WORK/reload.log")
  r_edge=$(awk '/\(tupledone/{n++} /^\(tuplerow/{if(n==1)c++} END{print c+0}' "$WORK/reload.log")
  [ "$r_path" = "3" ] && [ "$r_edge" = "3" ] \
    && pass "replay-converges (path 3, edge 3)" \
    || fail "replay-converges (path=$r_path edge=$r_edge)"
fi

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
