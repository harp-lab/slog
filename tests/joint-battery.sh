#!/usr/bin/env bash
#
# Gate S -- the joint intersection battery (docs/roadmap.md §5).  Each
# item is a capability neither thread proves alone: thread 1's REPL
# surface driving thread 0's counted/maintenance substrate.
#
#   item 1: the REPL as the incremental harness's second driver
#   item 2: scratch over counted state (routes + sidecar equality)
#   item 4: level-0 watches through counted maintenance epochs
#
# (item 3, quiescence admission over counted epochs, lives in the
# protocol battery's driving style and joins here as it lands; item 5 is
# the SLOG_OPT=interp union sweep, run at gate closure.)
#
#   tests/joint-battery.sh          (expects a warm build/ cache)

set -u
cd "$(dirname "$0")/.."
mkdir -p build out data

PASS=0
FAIL=0
expect() { # name expected-substring file
  if grep -qF "$2" "$3"; then
    echo "PASS $1"; PASS=$((PASS+1))
  else
    echo "FAIL $1 (missing '$2' in $3)"; FAIL=$((FAIL+1))
  fi
}
expect_re() { # name expected-regex file
  if grep -qE "$2" "$3"; then
    echo "PASS $1"; PASS=$((PASS+1))
  else
    echo "FAIL $1 (no match for '$2' in $3)"; FAIL=$((FAIL+1))
  fi
}

# --- items 1 + 4: the REPL drives edits/flushes/watches/recount/save ---------
timeout 900 racket tests/joint/repl-workflow.rkt > out/joint-s1.log 2>&1

# staged edits are visible, then commit as ONE update epoch
expect "s1-pending-visible" "pending: edge +2" out/joint-s1.log
expect "s1-one-epoch" "path +9 (6 -> 15)" out/joint-s1.log
expect_re "s1-delta-route" "route: maintain" out/joint-s1.log
# the delete epoch retracts through the closure with counts still valid:
# cutting (4 5) splits the 1..6 chain into 1..4 and 5..6, C(4,2)+1 = 7
expect "s1-delete-cone" "path -8 (15 -> 7)" out/joint-s1.log
expect_re "s1-counted-status" \
  "settled · update revision [0-9]+ · counts valid" out/joint-s1.log
# the watch fired at the delete epoch's barriers and aggregated (item 4)
expect_re "s1-watch-heartbeat" "watch w1: .*hit" out/joint-s1.log
# sidecars match the forced recount: the two counts blocks are identical
awk '/◆ Counts · path/{n+=1; b=1; next} b && /^  \(countrow /{print n": "$0; next} {b=0}' \
  out/joint-s1.log > out/joint-s1-counts.txt
if [ -s out/joint-s1-counts.txt ] \
   && diff <(grep '^1: ' out/joint-s1-counts.txt | sed 's/^1: //') \
           <(grep '^2: ' out/joint-s1-counts.txt | sed 's/^2: //') \
        > /dev/null; then
  echo "PASS s1-sidecars-match-recount"; PASS=$((PASS+1))
else
  echo "FAIL s1-sidecars-match-recount (counts blocks differ or empty)"
  FAIL=$((FAIL+1))
fi
# the saved recipe replays to the same content
expect "s1-reload" "Opened joint_s1" out/joint-s1.log
expect "s1-reload-count" "7 rows match" out/joint-s1.log

rm -rf data/joint_s1

# --- item 2: scratch over counted state --------------------------------------
timeout 900 racket tests/joint/scratch-counted.rkt > out/joint-s2.log 2>&1

# the scratch view compiles over counted state and answers
expect "s2-scratch-view" "fragment 1 joined the scratch layer — writes hop2" \
  out/joint-s2.log
expect "s2-view-rows" "3 rows match" out/joint-s2.log
# the delete's cone covers the scratch stratum on the counted flavors,
# with the watch firing at the epoch's barriers
expect "s2-scratch-in-cone" "hop2 -1 (3 -> 2)" out/joint-s2.log
expect_re "s2-counted-route" "route: maintain" out/joint-s2.log
expect_re "s2-scratch-watch" "watch w1: .*hit" out/joint-s2.log
# sidecars match the forced recount while scratch strata are resident
awk '/◆ Counts · hop2/{n+=1; b=1; next} b && /^  \(countrow /{print n": "$0; next} {b=0}' \
  out/joint-s2.log > out/joint-s2-hop2.txt
if [ -s out/joint-s2-hop2.txt ] \
   && diff <(grep '^1: ' out/joint-s2-hop2.txt | sed 's/^1: //') \
           <(grep '^2: ' out/joint-s2-hop2.txt | sed 's/^2: //') \
        > /dev/null; then
  echo "PASS s2-sidecars-with-scratch"; PASS=$((PASS+1))
else
  echo "FAIL s2-sidecars-with-scratch (hop2 counts blocks differ or empty)"
  FAIL=$((FAIL+1))
fi
# retraction drops the layer; the equality holds over the survivors
expect "s2-clear" "dropped: hop2" out/joint-s2.log
awk '/◆ Counts · path/{n+=1; b=1; next} b && /^  \(countrow /{print n": "$0; next} {b=0}' \
  out/joint-s2.log > out/joint-s2-path.txt
if [ -s out/joint-s2-path.txt ] \
   && diff <(grep '^1: ' out/joint-s2-path.txt | sed 's/^1: //') \
           <(grep '^2: ' out/joint-s2-path.txt | sed 's/^2: //') \
        > /dev/null; then
  echo "PASS s2-sidecars-after-clear"; PASS=$((PASS+1))
else
  echo "FAIL s2-sidecars-after-clear (path counts blocks differ or empty)"
  FAIL=$((FAIL+1))
fi
expect "s2-survivor-count" "6 rows match" out/joint-s2.log

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
