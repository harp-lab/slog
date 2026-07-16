#!/usr/bin/env bash
#
# RF1 slice-0 determinism gate (docs/rf1-contract.md, "Slices" item 0):
# run the full golden suite TWICE from a clean build/ and assert
#
#   (a) the two runs produce IDENTICAL build/ filename sets (job-hash
#       stems, action plugins, sidecars -- no gensym may reach a cache
#       key), and
#   (b) byte-identical .plan file sets (the canonical KernelPlan layer is
#       run-stable: decl lists, dynamic lists, VariantTags, D4 sort order).
#
# This is the repeatable form of the 2026-07-15 wholesale plan comparison
# (docs/rf1-contract.md determinism doctrine).  It is a manual/slice gate:
# NOT wired into run-all.sh -- two full golden tiers take ~10 minutes.
#
#   bash tests/plan-determinism.sh
#
# config/cache is cleared before each run so the config program
# (config/default-config.slog) compiles in BOTH runs: a warm settings cache
# skips that compile entirely, which would make the build/ sets differ for
# reasons that have nothing to do with determinism.

set -u
cd "$(dirname "$0")/.."

WORK="$(mktemp -d)"
trap 'rm -rf "$WORK"' EXIT

# Golden pass/fail is run-tests.sh's own gate, not this one's: a golden
# mismatch (e.g. dem_lambda's path-derived _lam names when running from a
# worktree checkout) still produces the build artifacts this gate compares.
# Suite failures are surfaced as warnings; the determinism assertions stay
# hard.
suite_warned=0
run_once() {
  local tag="$1"
  rm -rf build config/cache
  if ! bash tests/run-tests.sh > "$WORK/suite-$tag.log" 2>&1; then
    echo "warning: golden suite run $tag did not fully pass (not this gate's assertion):"
    tail -3 "$WORK/suite-$tag.log" | sed 's/^/  /'
    suite_warned=1
  else
    tail -1 "$WORK/suite-$tag.log"
  fi
  # action-* plugins are excluded from the filename-set assertion: they are
  # runtime-DEMAND-compiled client artifacts (actions.rkt), and whether one
  # exists can depend on wall-clock -- e.g. the `(continue)` action compiles
  # lazily the first time any fixpoint hits a pause budget (runslog.rkt:266),
  # so a slow run mints it and a fast run never does.  Their names stay
  # content-addressed; the compiler-determinism surface this gate asserts is
  # the job-hash stems and their .plan/.cprog/.cpp/.meta sidecars.
  (cd build && ls -1 | grep -v '^action-' | LC_ALL=C sort) > "$WORK/files-$tag.txt"
  mkdir -p "$WORK/plans-$tag"
  cp build/*.plan "$WORK/plans-$tag"/ 2>/dev/null || true
}

echo "plan-determinism: run 1 (full golden tier, clean build/) ..."
run_once run1
echo "plan-determinism: run 2 (full golden tier, clean build/) ..."
run_once run2

fail=0

# (a) identical build/ filename sets
if ! diff "$WORK/files-run1.txt" "$WORK/files-run2.txt" > "$WORK/files.diff"; then
  echo "FAIL: build/ filename sets differ between runs:"
  sed 's/^/  /' "$WORK/files.diff" | head -40
  fail=1
else
  echo "OK: build/ filename sets identical ($(wc -l < "$WORK/files-run1.txt") entries)"
fi

# (b) byte-identical .plan sets
nplans=0
for p in "$WORK/plans-run1"/*.plan; do
  [ -e "$p" ] || continue
  nplans=$((nplans + 1))
  b="$(basename "$p")"
  if [ ! -e "$WORK/plans-run2/$b" ]; then
    echo "FAIL: $b produced by run 1 only"
    fail=1
  elif ! cmp -s "$p" "$WORK/plans-run2/$b"; then
    echo "FAIL: $b differs between runs:"
    diff "$WORK/plans-run1/$b" "$WORK/plans-run2/$b" | head -8 | sed 's/^/  /'
    fail=1
  fi
done
for p in "$WORK/plans-run2"/*.plan; do
  [ -e "$p" ] || continue
  b="$(basename "$p")"
  [ -e "$WORK/plans-run1/$b" ] || { echo "FAIL: $b produced by run 2 only"; fail=1; }
done
if [ "$nplans" -eq 0 ]; then
  echo "FAIL: no .plan files produced (harness broken?)"
  fail=1
fi

if [ "$fail" -eq 0 ]; then
  echo "OK: $nplans .plan files byte-identical across runs"
  [ "$suite_warned" -ne 0 ] && echo "note: a suite run had golden failures (see warnings above)"
  echo "plan-determinism: PASS"
else
  echo "plan-determinism: FAIL"
  exit 1
fi
