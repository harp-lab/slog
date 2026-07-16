#!/usr/bin/env bash
#
# Exact-once fire audit (docs/stats.md; docs/incremental.md §8, §10, M0 prep).
#
#   tests/stats-tests.sh                 assert every tests/stat_*.slog
#   tests/stats-tests.sh PROG...         assert only the named programs
#   tests/stats-tests.sh --update        re-snapshot the FRESH expectations
#
# Two audits per program, both against tests/stats-expected/<name>.fires --
# HAND-VERIFIED instantiation counts (see each program's header comment).
# Under correct per-position delta partitioning, semi-naive fires each
# satisfying body assignment EXACTLY once, so these goldens are the observable
# form of the exact-once property that DRed^c counting will depend on.
#
#   1. FRESH: run the program twice from scratch; assert the two runs'
#      $stat_fires agree (thread-schedule determinism of instantiation counts)
#      and match the golden.
#   2. RELOAD (docs/incremental.md §8/§10, 0.B6): save a compressed database
#      and reload it -- the replay re-fires every rule over the WHOLE reloaded
#      database (delta = whole DB at iteration 0: the reload-staging boundary).
#      Its $stat_fires must equal the golden too, or a tuple's instantiation was
#      double-staged at the reload boundary -- harmless under today's set
#      semantics (dedup absorbs it) but a permanent counter corruption once
#      DRed^c counting lands.  Checked at each RELOAD_PERS coverage (default
#      100 = whole DB staged as delta, and 60 = drop+regenerate, so replayed
#      tuples must also fire exactly once).
#
#      Known divergence: a program with a tests/stats-expected/<name>.reload.fires
#      file is asserted against THAT on the reload path instead of the fresh
#      golden -- reserved for rule shapes the current engine does not yet fire
#      exact-once on reload (e.g. self-joins reading one relation in two body
#      positions; see stat_selfjoin).  Tracking the numbers keeps the M0 gap
#      visible and alerts if it shifts.
#
# Timing rows ($stat_fixpoint) are deliberately not asserted.

set -u
cd "$(dirname "$0")/.."

export SLOG_OPT="${SLOG_OPT:-0}"
export SLOG_SMT_SOLVERS=mock

UPDATE=0
PROGS=()
for a in "$@"; do
  if [ "$a" = "--update" ]; then UPDATE=1; else PROGS+=("$a"); fi
done
[ ${#PROGS[@]} -eq 0 ] && PROGS=(tests/stat_*.slog)

RELOAD_PERS="${RELOAD_PERS:-100 60}"
EMPTY="$(mktemp -d)/empty.slog"; printf ';; dump loader\n' > "$EMPTY"

# planner temp relations are gensym-named per compile; normalize them so
# unrelated compiler changes don't churn the hand-verified expectations
norm() { LC_ALL=C sed -E 's/temp[A-Za-z0-9]+/temp<N>/g' "$1" | LC_ALL=C sort; }

fail=0
for t in "${PROGS[@]}"; do
  name="$(basename "$t" .slog)"
  exp="tests/stats-expected/$name.fires"
  out1="out/stats-$name-1"; out2="out/stats-$name-2"
  ok=1
  for o in "$out1" "$out2"; do
    rm -rf "$o"
    if ! timeout 900 racket compiler/run.rkt --no-banner --debug-dir "$o" "$t" \
         > "out/stats-$name.log" 2>&1; then
      echo "FAIL $name (run error; see out/stats-$name.log)"; fail=1; ok=0; break
    fi
  done
  [ "$ok" -eq 1 ] || continue

  if ! diff <(norm "$out1/\$stat_fires.csv") \
            <(norm "$out2/\$stat_fires.csv") > /dev/null; then
    echo "FAIL $name (fire counts differ across identical runs -- nondeterminism)"
    fail=1; continue
  fi

  if [ "$UPDATE" -eq 1 ]; then
    mkdir -p tests/stats-expected
    norm "$out1/\$stat_fires.csv" > "$exp"
    echo "UPDATED $name"
    continue
  fi

  if [ ! -e "$exp" ]; then
    echo "FAIL $name (no expectation $exp; run with --update and hand-verify)"
    fail=1; continue
  fi
  if ! diff <(norm "$out1/\$stat_fires.csv") "$exp" > /dev/null; then
    echo "FAIL $name (fresh fire counts drifted from hand-verified expectation):"
    diff <(norm "$out1/\$stat_fires.csv") "$exp" | sed 's/^/  /'
    fail=1; continue
  fi

  # ---- reload-path exact-once audit (delta = whole DB at reload) ----
  # A program with a .reload.fires override is asserted against it (documented
  # divergence); otherwise the reload must reproduce the fresh golden exactly.
  rexp="tests/stats-expected/$name.reload.fires"
  [ -e "$rexp" ] || rexp="$exp"
  reload_ok=1
  for per in $RELOAD_PERS; do
    db="stats_${name}_c"; rout="out/stats-$name-reload$per"
    rm -rf "data/$db" "data/$db.edb" "$rout"
    if ! timeout 900 racket compiler/run.rkt --no-banner --out-db-compressed "$db" --per "$per" "$t" \
         > "out/stats-$name-save$per.log" 2>&1; then
      echo "FAIL $name (reload per=$per: save error; see out/stats-$name-save$per.log)"
      reload_ok=0; rm -rf "data/$db" "data/$db.edb"; break
    fi
    if ! timeout 900 racket compiler/run.rkt --no-banner -d "$db" --debug-dir "$rout" "$EMPTY" \
         > "out/stats-$name-reload$per.log" 2>&1; then
      echo "FAIL $name (reload per=$per: replay error; see out/stats-$name-reload$per.log)"
      reload_ok=0; rm -rf "data/$db" "data/$db.edb"; break
    fi
    rm -rf "data/$db" "data/$db.edb"
    if [ ! -e "$rout/\$stat_fires.csv" ]; then
      echo "FAIL $name (reload per=$per: replay published no \$stat_fires -- did the strata re-fire?)"
      reload_ok=0; break
    fi
    if ! diff <(norm "$rout/\$stat_fires.csv") "$rexp" > /dev/null; then
      echo "FAIL $name (reload per=$per: fire counts differ from $(basename "$rexp") -- double-staged at the reload boundary?):"
      diff <(norm "$rout/\$stat_fires.csv") "$rexp" | sed 's/^/  /'
      reload_ok=0
    fi
  done
  if [ "$reload_ok" -eq 1 ]; then
    [ "$rexp" = "$exp" ] \
      && echo "PASS $name (fresh + reload @ $RELOAD_PERS)" \
      || echo "PASS $name (fresh; reload @ $RELOAD_PERS matches documented divergence)"
  else
    fail=1
  fi
done
exit $fail
