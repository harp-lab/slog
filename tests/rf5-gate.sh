#!/usr/bin/env bash
#
# RF5-B's remaining §10 gate cases (rf5-contract.md, "Additional required
# cases"), each driven with PRODUCER-SEALED fixtures where the diff is the
# compiler's own (build-joint-fixtures) and hand-templated fixtures where
# the content is session-side (the suffix):
#
#   SPLIT        an SCC splits in two; membership survives, the emitted
#                fixture's sccs section records 1 old row -> 2 new rows.
#   MERGE        two instances' SCCs merging across a new mutual rule
#                pair CHANGES the resident clustering -- the v1
#                correctness-first route refuses TYPED (torn by the cone,
#                rf5 §7.2's fall-back-before-publication) with the base
#                untouched; the consumer-level fixture stays conformant.
#                Widening the sever closure to the resident∪candidate
#                clustering union would admit it -- vetting-era work.
#   IDENTICAL    a metadata-only (reformatted) replacement: rebuild 0 in
#                the verdict, contents identical, a fresh program event.
#   DUPLICATE    a duplicated semantic rule loses one copy: membership
#                unchanged, per-row derivation counts drop 2 -> 1 and
#                equal a forced fresh recount.
#   SUFFIX-LIVE  a mapped data-overlay batch replays through the CANDIDATE
#                rules after the heal ((suffix 1) narrated), and a
#                data-tuning edit afterwards stays on the ordinary batch
#                path (no second activation event).
#   SUFFIX-REFUSED  a batch anchored on a REBUILT relation refuses typed
#                (historical-program-replacement), before any state.
#   REACTIVATION the same sealed candidate activates twice; the second
#                run mints fresh identity (no key reuse).
#
# Deferred, recorded: failure DURING the recount step is not yet
# injectable inside the activation transaction (the fail-after-heal lever
# faults at prepare; a recount-point lever is vetting-era work).
#
#   bash tests/rf5-gate.sh

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

if ! timeout 900 racket tests/api/build-joint-fixtures.rkt "$WORK/fx" \
     > "$WORK/build.log" 2>&1; then
  echo "  (fixture build failed)"; tail -5 "$WORK/build.log" | sed 's/^/  /'
  fail producer-build; echo "$PASS passed, $FAIL failed"; exit 1
fi
pass producer-build

drive() { # name, then session-drive tokens
  local name="$1"; shift
  if timeout 900 racket tests/api/session-drive.rkt "$@" \
       > "$WORK/$name.log" 2>&1; then
    pass "drive-$name"
  else
    fail "drive-$name"; tail -5 "$WORK/$name.log" | sed 's/^/  /'
  fi
}

# tuple count of the Nth dump-tuples section (0-based)
tuples() { awk -v n="$2" '/\(tupledone/{s++} /^\(tuplerow/{if(s==n)c++} END{print c+0}' "$WORK/$1.log"; }

# ---- SPLIT -----------------------------------------------------------------
grep -q '(old ((scc 0 1 (members back path))))' "$WORK/fx/gate-split.pcs" \
  && pass "split-fixture-1-old-scc" || fail "split-fixture-1-old-scc"
n_new=$(grep -o '(scc [0-9]* [0-9]* (members [a-z]*))' "$WORK/fx/gate-split.pcs" | wc -l)
[ "$n_new" = "2" ] && pass "split-fixture-2-new-sccs" \
                   || fail "split-fixture-2-new-sccs (got $n_new)"
drive split "run:tests/reflect/joint/gate-split-base.slog" \
      dump-tuples:path dump-tuples:back \
      "activate:$WORK/fx/gate-split.pcs" \
      dump-tuples:path dump-tuples:back
[ "$(tuples split 0)" = "2" ] && [ "$(tuples split 2)" = "2" ] \
  && [ "$(tuples split 1)" = "2" ] && [ "$(tuples split 3)" = "2" ] \
  && pass "split-membership-survives" \
  || fail "split-membership-survives ($(tuples split 0)/$(tuples split 1) -> $(tuples split 2)/$(tuples split 3))"
grep -q '(activation-committed ' "$WORK/split.log" \
  && pass "split-committed" || fail "split-committed"

# ---- MERGE -----------------------------------------------------------------
grep -Eq '\(scc [0-9]+ [0-9]+ \(members left\.path right\.path\)\)' "$WORK/fx/gate-merge.pcs" \
  && pass "merge-fixture-one-scc-both-members" \
  || fail "merge-fixture-one-scc-both-members"
drive merge "run:tests/reflect/joint/gate-merge-base.slog" \
      dump-tuples:left.path dump-tuples:right.path \
      "activate:$WORK/fx/gate-merge.pcs" \
      dump-tuples:left.path dump-tuples:right.path
[ "$(tuples merge 0)" = "3" ] && [ "$(tuples merge 1)" = "1" ] \
  && pass "merge-base-shape" || fail "merge-base-shape ($(tuples merge 0)/$(tuples merge 1))"
grep -q '(refused activation-unsupported .*torn by the cone' "$WORK/merge.log" \
  && pass "merge-refuses-typed-torn-clustering" \
  || fail "merge-refuses-typed-torn-clustering"
[ "$(tuples merge 2)" = "3" ] && [ "$(tuples merge 3)" = "1" ] \
  && pass "merge-refusal-left-base-untouched" \
  || fail "merge-refusal-left-base-untouched ($(tuples merge 2)/$(tuples merge 3))"

# ---- IDENTICAL ---------------------------------------------------------------
grep -q '(rebuild 0)' <(racket tests/api/pcs-check.rkt "$WORK/fx/gate-identical.pcs") \
  && pass "identical-verdict-rebuild-0" || fail "identical-verdict-rebuild-0"
drive identical "run:tests/reflect/joint/gate-identical-base.slog" \
      dump-tuples:path \
      "activate:$WORK/fx/gate-identical.pcs" \
      dump-tuples:path
[ "$(tuples identical 0)" = "3" ] && [ "$(tuples identical 1)" = "3" ] \
  && pass "identical-contents-identical" \
  || fail "identical-contents-identical ($(tuples identical 0) -> $(tuples identical 1))"
grep -q '(activated (program .*) (rebuilt 0) ' "$WORK/identical.log" \
  && pass "identical-rebuilt-0-narrated" || fail "identical-rebuilt-0-narrated"

# ---- DUPLICATE ---------------------------------------------------------------
drive duplicate "run:tests/reflect/joint/gate-duplicate-base.slog" \
      dump-tuples:path recount dump-counts:path \
      "activate:$WORK/fx/gate-duplicate.pcs" \
      dump-tuples:path recount dump-counts:path \
      recount-force dump-counts:path
[ "$(tuples duplicate 0)" = "2" ] && [ "$(tuples duplicate 1)" = "2" ] \
  && pass "duplicate-membership-unchanged" \
  || fail "duplicate-membership-unchanged ($(tuples duplicate 0) -> $(tuples duplicate 1))"
awk '/^\(countdone/{s++} /^\(countrow/{print s+0, $0}' "$WORK/duplicate.log" > "$WORK/dup-counts.txt"
before_counts=$(awk '$1==0' "$WORK/dup-counts.txt" | grep -c ' 0 2 0)$')
after_counts=$(awk '$1==1' "$WORK/dup-counts.txt" | grep -c ' 0 1 0)$')
[ "$before_counts" = "2" ] && [ "$after_counts" = "2" ] \
  && pass "duplicate-support-recounted-2-to-1" \
  || fail "duplicate-support-recounted-2-to-1 (before2=$before_counts after1=$after_counts)"
recount_counts=$(awk '$1==2' "$WORK/dup-counts.txt" | grep -c ' 0 1 0)$')
[ "$recount_counts" = "2" ] \
  && pass "duplicate-counts-equal-fresh-recount" \
  || fail "duplicate-counts-equal-fresh-recount (got $recount_counts)"

# ---- SUFFIX-LIVE + data-tuning stays on the batch path ----------------------
drive suffix "run:tests/reflect/joint/joint-live-base.slog" \
      "activate:tests/reflect/joint/gate-suffix-live.pcs" \
      dump-tuples:edge dump-tuples:path \
      batch+:edge,9,10 flush \
      dump-tuples:edge dump-tuples:path
grep -q '(suffix 1))' "$WORK/suffix.log" \
  && pass "suffix-narrated" || fail "suffix-narrated"
[ "$(tuples suffix 0)" = "4" ] && [ "$(tuples suffix 1)" = "4" ] \
  && pass "suffix-replayed-through-candidate (edge 4, path 4)" \
  || fail "suffix-replayed-through-candidate ($(tuples suffix 0)/$(tuples suffix 1))"
[ "$(tuples suffix 2)" = "5" ] && [ "$(tuples suffix 3)" = "5" ] \
  && pass "tuning-edit-propagates" \
  || fail "tuning-edit-propagates ($(tuples suffix 2)/$(tuples suffix 3))"
n_act=$(grep -c '(activation-committed ' "$WORK/suffix.log")
[ "$n_act" = "1" ] && pass "tuning-edit-stays-on-batch-path" \
                   || fail "tuning-edit-stays-on-batch-path (activations=$n_act)"

# ---- SUFFIX-REFUSED ----------------------------------------------------------
if racket tests/api/pcs-check.rkt tests/reflect/joint/gate-suffix-rebuilt.pcs \
     > "$WORK/refuse.verdict" 2>&1; then
  fail "suffix-rebuilt-anchor-refuses (accepted!)"
else
  grep -q '^(refused historical-program-replacement' "$WORK/refuse.verdict" \
    && pass "suffix-rebuilt-anchor-refuses" \
    || { fail "suffix-rebuilt-anchor-refuses"; sed 's/^/  /' "$WORK/refuse.verdict"; }
fi

# ---- REACTIVATION without identity reuse ------------------------------------
drive reactivate "run:tests/reflect/joint/joint-live-base.slog" \
      "activate:$WORK/fx/joint-minimal-live.pcs" \
      "activate:$WORK/fx/joint-minimal-live.pcs" \
      dump-tuples:path
keys=$(sed -n 's/^(activation-committed \(.*\))$/\1/p' "$WORK/reactivate.log" | sort -u | wc -l)
[ "$keys" = "2" ] && pass "reactivation-mints-fresh-identity" \
                  || fail "reactivation-mints-fresh-identity (distinct keys=$keys)"
[ "$(tuples reactivate 0)" = "3" ] && pass "reactivation-converges" \
                                   || fail "reactivation-converges (got $(tuples reactivate 0))"

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
