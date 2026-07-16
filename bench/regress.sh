#!/usr/bin/env bash
#
# Performance-regression gate (docs/stats.md; the pre-DRed^c baseline).
#
#   bench/regress.sh            compare against bench/regress/baselines.tsv
#   bench/regress.sh --update   re-baseline (after INTENTIONAL changes only)
#
# Two assertions per benchmark:
#   - per-stratum ITERATION counts match the baseline EXACTLY: they are
#     deterministic, machine-independent, and the cleanest signal that an
#     engine change altered evaluation structure (extra rounds = lag or
#     refire changes; fewer = something stopped firing);
#   - total fixpoint runtime stays within REGRESS_BUDGET x baseline
#     (default 2.0).  Baselines are MACHINE-LOCAL: regenerate on a new
#     machine before relying on the time gate.
#
# Runs at SLOG_OPT=0: iteration structure is tier-independent and -O0
# keeps the gate fast (first run pays the compile; the content-addressed
# cache makes repeats cheap).  Use SLOG_OPT=2 by hand for absolute
# numbers.  The benchmark set spans the shapes DRed^c will stress: the
# deterministic-split partition idiom (supplementary-keyed answer joins),
# the sequential fold (long delta chains), a demand-style interpreter
# (struct-recursion resumes), and classic struct-heavy CFA.

set -u
cd "$(dirname "$0")/.."

export SLOG_OPT=0
export SLOG_SMT_SOLVERS=mock
BUDGET="${REGRESS_BUDGET:-2.0}"
BASE="bench/regress/baselines.tsv"

BENCHES=(
  bench/regress/split512.slog
  bench/regress/fold512.slog
  examples/r7rs-small/eval.slog
  examples/tinycfa/0cfa.slog
)

UPDATE=0
[ "${1:-}" = "--update" ] && UPDATE=1
[ "$UPDATE" -eq 1 ] && : > "$BASE.tmp"

fail=0
for t in "${BENCHES[@]}"; do
  name="$(basename "$t" .slog)"
  out="out/regress-$name"
  rm -rf "$out"
  log="out/regress-$name.log"
  if ! timeout 900 racket compiler/run.rkt --no-banner --debug-dir "$out" "$t" \
       > "$log" 2>&1; then
    echo "FAIL $name (run error; see $log)"; fail=1; continue
  fi
  # "(fixpoint <scc> <hash> <iters> <ms>)" per stratum
  iters="$(grep -oE '^\(fixpoint [0-9]+ "[^"]*" [0-9]+' "$log" \
           | awk '{print $4}' | paste -sd, -)"
  ms="$(grep -oE '^\(fixpoint .* [0-9.]+\)$' "$log" \
        | awk '{gsub(/\)/,"",$NF); s+=$NF} END {printf "%.1f", s}')"

  if [ "$UPDATE" -eq 1 ]; then
    printf '%s\t%s\t%s\n' "$name" "$iters" "$ms" >> "$BASE.tmp"
    echo "BASELINE $name iters=[$iters] ms=$ms"
    continue
  fi

  line="$(grep -P "^$name\t" "$BASE" || true)"
  if [ -z "$line" ]; then
    echo "FAIL $name (no baseline; run with --update)"; fail=1; continue
  fi
  want_iters="$(printf '%s' "$line" | cut -f2)"
  want_ms="$(printf '%s' "$line" | cut -f3)"

  if [ "$iters" != "$want_iters" ]; then
    echo "FAIL $name (iterations [$iters] != baseline [$want_iters])"
    fail=1; continue
  fi
  over="$(awk -v a="$ms" -v b="$want_ms" -v k="$BUDGET" \
          'BEGIN { print (a > b * k) ? 1 : 0 }')"
  if [ "$over" -eq 1 ]; then
    echo "FAIL $name (${ms}ms > ${BUDGET}x baseline ${want_ms}ms)"
    fail=1
  else
    echo "PASS $name (iters=[$iters] ${ms}ms, baseline ${want_ms}ms)"
  fi
done

[ "$UPDATE" -eq 1 ] && mv "$BASE.tmp" "$BASE"
exit $fail
