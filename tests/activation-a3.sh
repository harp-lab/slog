#!/usr/bin/env bash
#
# Spine slice A3 gate (docs/activation-contract.md §5): the RF5-B shape.
# A two-instance program replaces ONE instance's image; the battery proves
# the four capstone claims on the live transaction:
#
#   1. OUTSIDE-CONE REUSE -- every relation outside the cone keeps its
#      VersionKey byte-identical (seed, right.edge, left.path); the cone
#      is STRATUM-granular: left.edge cohabits right.path's level-1
#      stratum, so it rebinds (an inherited clone) alongside the severed
#      right.path/answer.  The battery pins both sides of that line.
#   2. REMOVED SUPPORT DISAPPEARS -- right.path loses its transitive row
#      (8 10) and gains the v2 reversal rows; answer follows; left.path is
#      row-identical.
#   3. COUNTS EQUAL A FRESH RECOUNT -- the post-activation count sidecar is
#      byte-identical before and after recount-force (drop ALL count state,
#      recompute from scratch).
#   4. WHY/WHYNOT BEFORE AND AFTER -- one lost fact and one gained fact,
#      each explained on both sides of the activation, against ONE session
#      (tests/api/a3-why-drive.rkt; the T5 capture workflow).
#
#   bash tests/activation-a3.sh

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

cat > out/a3_lib.slog <<'EOF'
table (edge int int)
table (path int int)

rule (edge X Y) --> (path X Y)
rule (path X Y) (edge Y Z) --> (path X Z)
EOF

cat > out/a3_base.slog <<'EOF'
instantiate "a3_lib.slog" as left
instantiate "a3_lib.slog" as right

table (seed int int)
table (answer int int int)

rule
(seed 1 2)
(seed 2 3)
(right.edge 8 9)
(right.edge 9 10)

rule (seed X Y) --> (left.edge X Y)
rule (left.path X Y) --> (answer 0 X Y)
rule (right.path X Y) --> (answer 1 X Y)
EOF

FIX=tests/activation/two-instance-live.pcs

# ---- part 1: the transaction, versions, contents, counts --------------------
rm -rf data/a3-save
if ! timeout 900 racket tests/api/session-drive.rkt \
     "run:out/a3_base.slog" \
     versions \
     dump-tuples:right.path dump-tuples:left.path dump-tuples:answer \
     "activate:$FIX" \
     versions \
     dump-tuples:right.path dump-tuples:left.path dump-tuples:answer \
     dump-tuples:right.edge \
     rule-keys \
     recount dump-counts:right.path dump-counts:answer \
     recount-force dump-counts:right.path dump-counts:answer \
     save:a3-save \
     > "$WORK/a3.log" 2>&1; then
  echo "  (a3 drive failed; see $WORK/a3.log)"
  tail -5 "$WORK/a3.log" | sed 's/^/  /'
  fail a3-drive
  echo "$PASS passed, $((FAIL+1)) failed"; exit 1
fi

# split the two `versions` sections
awk '/^\(version /{if (seen) print > "'"$WORK"'/v1.txt"; else print > "'"$WORK"'/v0.txt"} /^\(versions-end/{seen=1}' "$WORK/a3.log"

# 1a. carried VersionKeys byte-identical across the activation
ok=1
for rel in seed left.path right.edge; do
  b=$(grep -F "(version $rel " "$WORK/v0.txt")
  a=$(grep -F "(version $rel " "$WORK/v1.txt")
  if [ -z "$b" ] || [ "$b" != "$a" ]; then
    echo "  $rel: before='$b' after='$a'"; ok=0
  fi
done
[ $ok -eq 1 ] && pass "outside-cone-versionkeys-reused" \
              || fail "outside-cone-versionkeys-reused"

# 1b. the rebuilt cone got FRESH slots
ok=1
for rel in right.path answer left.edge; do
  b=$(grep -F "(version $rel " "$WORK/v0.txt")
  a=$(grep -F "(version $rel " "$WORK/v1.txt")
  if [ -z "$b" ] || [ -z "$a" ] || [ "$b" = "$a" ]; then
    echo "  $rel: before='$b' after='$a'"; ok=0
  fi
done
[ $ok -eq 1 ] && pass "rebuilt-cone-fresh-slots" || fail "rebuilt-cone-fresh-slots"

# 1c. the narration pinned: 2 rebuilt, 3 carried-aliased, 1 rebound
grep -q '^(activated (program .*) (rebuilt 2) (carried 3) (carried-rebound 1) (retired 2))' "$WORK/a3.log" \
  && pass "narration-2-rebuilt-3-carried-1-rebound" || fail "narration-2-rebuilt-3-carried-1-rebound"

# 2. contents: sections in drive order (right.path L.path answer | right.path
#    L.path answer right.edge); rows counted per section
section() { awk -v n="$1" '/\(tupledone/{s++} /^\(tuplerow/{if(s==n) print}' "$WORK/a3.log"; }
rp_before=$(section 0 | wc -l); lp_before=$(section 1 | wc -l); an_before=$(section 2 | wc -l)
rp_after=$(section 3 | wc -l);  lp_after=$(section 4 | wc -l);  an_after=$(section 5 | wc -l)
re_after=$(section 6 | wc -l)
[ "$rp_before" = 3 ] && [ "$lp_before" = 3 ] && [ "$an_before" = 6 ] \
  && pass "base-contents (right.path 3, left.path 3, answer 6)" \
  || fail "base-contents (got $rp_before/$lp_before/$an_before)"
if section 3 | grep -q '^(tuplerow 8 10)'; then
  fail "removed-support-gone (right.path still holds 8 10)"
else
  [ "$rp_after" = 4 ] && pass "removed-support-gone (right.path 3 -> 4 rows, no 8 10)" \
                      || fail "removed-support-gone (got $rp_after rows)"
fi
section 3 | grep -q '^(tuplerow 9 8)' && pass "gained-support-present (9 8)" \
                                      || fail "gained-support-present (9 8)"
{ [ "$lp_after" = 3 ] && diff <(section 1 | sort) <(section 4 | sort) > /dev/null; } \
  && pass "carried-instance-row-identical" || fail "carried-instance-row-identical"
[ "$an_after" = 7 ] && [ "$re_after" = 2 ] \
  && pass "downstream-follows (answer 7, right.edge 2)" \
  || fail "downstream-follows (answer=$an_after right.edge=$re_after)"

# 3. counts equal a fresh recount: the sidecar dumps (terminated by
#    (countdone ...)) byte-identical around recount-force
COUNT_SECTIONS=$(grep -c '^(countdone' "$WORK/a3.log" || true)
if [ "${COUNT_SECTIONS:-0}" -ge 4 ]; then
  awk '/^\(countrow /{print s, $0} /^\(countdone/{s++}' "$WORK/a3.log" > "$WORK/crows.txt"
  awk '$1<2' "$WORK/crows.txt" | cut -d" " -f2- | sort > "$WORK/ca.txt"
  awk '$1>=2' "$WORK/crows.txt" | cut -d" " -f2- | sort > "$WORK/cb.txt"
  if [ -s "$WORK/ca.txt" ] && diff "$WORK/ca.txt" "$WORK/cb.txt" > /dev/null; then
    pass "counts-equal-fresh-recount"
  else
    echo "  count sidecars differ (or empty):"
    diff "$WORK/ca.txt" "$WORK/cb.txt" | head -5 | sed 's/^/    /'
    fail "counts-equal-fresh-recount"
  fi
else
  fail "counts-equal-fresh-recount (expected 4 countdone sections; got ${COUNT_SECTIONS:-0})"
fi

# identity: the committed key is in the ledger
akey=$(sed -n 's/^(activated (program \([^)]*\)).*/\1/p' "$WORK/a3.log" | head -1)
grep -q "(identity-program $akey)" "$WORK/a3.log" \
  && pass "plan-and-minter-agree" || fail "plan-and-minter-agree ($akey)"

# replay: reload the save; the two-instance tip reproduces
if ! timeout 900 racket tests/api/session-drive.rkt \
     open:a3-save dump-tuples:right.path dump-tuples:left.path dump-tuples:answer \
     > "$WORK/reload.log" 2>&1; then
  echo "  (reload failed; see $WORK/reload.log)"; fail reload
else
  r_rp=$(awk '/\(tupledone/{s++} /^\(tuplerow/{if(s==0)c++} END{print c+0}' "$WORK/reload.log")
  r_lp=$(awk '/\(tupledone/{s++} /^\(tuplerow/{if(s==1)c++} END{print c+0}' "$WORK/reload.log")
  r_an=$(awk '/\(tupledone/{s++} /^\(tuplerow/{if(s==2)c++} END{print c+0}' "$WORK/reload.log")
  [ "$r_rp" = 4 ] && [ "$r_lp" = 3 ] && [ "$r_an" = 7 ] \
    && pass "replay-converges (right.path 4, left.path 3, answer 7)" \
    || fail "replay-converges (rp=$r_rp lp=$r_lp an=$r_an)"
fi

# ---- part 2: why/whynot before and after (one lost, one gained fact) --------
if ! timeout 900 racket tests/api/a3-why-drive.rkt out/a3_base.slog "$FIX" \
     > "$WORK/why.log" 2>&1; then
  echo "  (why drive failed; see $WORK/why.log)"
  tail -5 "$WORK/why.log" | sed 's/^/  /'
  fail why-drive
else
  for name in why-lost-before-derives whynot-gained-before-frontier \
              activation-committed whynot-lost-after-v2-frontier \
              why-gained-after-derives-via-v2 whynot-carried-instance-v1-rules; do
    grep -q "^(a3 $name 1)" "$WORK/why.log" \
      && pass "$name" || fail "$name"
  done
fi

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
