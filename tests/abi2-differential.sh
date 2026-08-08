#!/usr/bin/env bash
#
# RF1 slice 2: the ABI-1 vs ABI-2 DIFFERENTIAL.
#
# The airtightness gate (tests/abi2-airtight.sh) checks identity -- keys,
# bindings, partition coverage.  It is blind to the failure mode that actually
# hurt during this slice: splitting one plan into N kernels changes the ARITY
# of every side effect the install performs, and getting that wrong is SILENT.
# Duplicated intern tasks made reach's recursive stratum settle after 2
# iterations instead of 4 and printed a perfectly ordinary
# `(fixpoint 1 "..." 2 0.317)`.  Goldens catch that only where the lost
# derivations happen to reach a checked relation.
#
# So: run each program under BOTH artifact shapes and require agreement on
#   - every stratum's ITERATION COUNT (the fixpoint lines), and
#   - the dumped relation set and contents.
# Iteration counts are the sensitive signal -- they move the moment a delta is
# ingested twice or a read task goes missing, whether or not any output does.
#
#   bash tests/abi2-differential.sh [program.slog ...]

set -u
cd "$(dirname "$0")/.."
WORK="$(mktemp -d)"
trap 'rm -rf "$WORK"' EXIT
PASS=0; FAIL=0

PROGRAMS=("$@")
if [ "${#PROGRAMS[@]}" -eq 0 ]; then
  # a deliberate spread: recursion, structs, lattices, negation, demand,
  # sequences+attachments, WCOJ3, module instances, tycheck/error arms
  PROGRAMS=(tests/reach.slog tests/structs.slog tests/lat_run_base.slog
            tests/neg_wild.slog tests/dem_lambda.slog tests/seq_oracle.slog
            tests/sj_tri.slog tests/n1_instances.slog tests/tycheck_basic.slog)
fi

run_shape() { # <program> <tag> <abi>
  local prog="$1" tag="$2" abi="$3"
  rm -rf build config/cache
  # explicit BOTH ways: since the flip, the default is ABI 2, so the ABI-1
  # leg must pin itself or this differential compares a shape to itself
  local env_abi=(SLOG_PLAN_ABI="$abi")
  env "${env_abi[@]}" SLOG_OPT=interp timeout 900 \
    racket compiler/run.rkt --no-banner --debug-dir "$WORK/out-$tag" "$prog" \
    > "$WORK/log-$tag" 2>&1
  # the fixpoint lines carry (scc name iterations ms): keep scc + iterations,
  # drop the stem (job hashes move when the artifact shape does) and the ms
  grep -o '(fixpoint [0-9]* "[^"]*" [0-9]*' "$WORK/log-$tag" \
    | sed 's/"[^"]*"/STEM/' > "$WORK/iters-$tag"
  (cd "$WORK/out-$tag" 2>/dev/null && ls *.csv 2>/dev/null | LC_ALL=C sort) \
    > "$WORK/rels-$tag"
}

for prog in "${PROGRAMS[@]}"; do
  name="$(basename "$prog" .slog)"
  [ -f "$prog" ] || { echo "SKIP $name (missing)"; continue; }
  run_shape "$prog" "abi1-$name" 1
  run_shape "$prog" "abi2-$name" 2

  if ! diff -q "$WORK/iters-abi1-$name" "$WORK/iters-abi2-$name" >/dev/null; then
    echo "FAIL $name iterations"
    diff "$WORK/iters-abi1-$name" "$WORK/iters-abi2-$name" | head -6 | sed 's/^/    /'
    FAIL=$((FAIL+1)); continue
  fi
  if ! diff -q "$WORK/rels-abi1-$name" "$WORK/rels-abi2-$name" >/dev/null; then
    echo "FAIL $name relation set"
    diff "$WORK/rels-abi1-$name" "$WORK/rels-abi2-$name" | head -6 | sed 's/^/    /'
    FAIL=$((FAIL+1)); continue
  fi
  content_ok=1
  for csv in "$WORK/out-abi1-$name"/*.csv; do
    [ -e "$csv" ] || continue
    rel="$(basename "$csv")"
    case "$rel" in '$stat_'*) continue ;; esac   # per-run diagnostics
    if ! diff -q <(LC_ALL=C sort "$csv") \
                 <(LC_ALL=C sort "$WORK/out-abi2-$name/$rel") >/dev/null 2>&1
    then
      echo "FAIL $name contents ($rel)"; content_ok=0; break
    fi
  done
  if [ "$content_ok" -eq 1 ]; then
    echo "PASS $name ($(wc -l < "$WORK/iters-abi1-$name") strata, $(wc -l < "$WORK/rels-abi1-$name") relations)"
    PASS=$((PASS+1))
  else
    FAIL=$((FAIL+1))
  fi
done

# --- the flavored leg: counted + maintenance cohorts -----------------------
# The program loop above exercises NORMAL cohorts only.  Count/maint plans
# install through maybe_interp_count_plugin at update/recount time, and the
# cohort split changed the ARITY of their install side effects too --
# duplicated CountTasks double every counter, silently (the fold is
# additive; operators.h says so in as many words).  So drive one maintained
# session under both shapes: a positive flush (maint1), a negative flush on
# the recursive closure (the recursive-deletion sweep), then a forced
# whole-pipeline recount (count), and require identical count rows, routes,
# dump counts and relation contents.  Mirrors session-tests.sh's b5 shape.
run_counted() { # <abi> [native]
  local abi="$1" tag="counted-abi$1${2:+-$2}"
  rm -rf build config/cache "$WORK/csv-$tag"
  mkdir -p build   # session-drive writes action plugins here before any compile
  local env_abi=(SLOG_PLAN_ABI="$abi")   # explicit both ways, as above
  # T4 (2c): normal strata run INTERP in the two ABI legs -- this gate
  # compares plan-install shapes, and SLOG_PLAN_ABI=1 + native is now an
  # explicit refusal (a descriptor .so requires its ABI-2 sibling; the
  # escape hatch is interp-only).  The third leg compiles and EXECUTES the
  # flavored native artifacts (the 2b frame-mode slog_plugin spines) under
  # ABI 2 -- the only harness that runs them at all.
  local opt=interp
  if [ "${2:-}" = native ]; then env_abi+=(SLOG_FLAVORED_NATIVE=1); opt=0; fi
  # batch- can only retract INPUT-ledger tuples (base.slog's own edges are
  # ground-rule derived), so retract the tuple this scenario inserts: the
  # positive flush extends the closure (maint1), the negative flush tears
  # it back down through the recursive sweep.
  env "${env_abi[@]}" SLOG_OPT="$opt" timeout 900 \
    racket tests/api/session-drive.rkt \
      run:tests/session/base.slog \
      batch+:edge,4,5 flush \
      batch-:edge,4,5 flush \
      dump-rel:path write-csv:"$WORK/csv-$tag" \
      dump-counts:path recount-force dump-counts:path \
    > "$WORK/log-$tag" 2>&1
  # sorted: countrow emission follows bucket enumeration, whose order is
  # content-deterministic but not worth pinning; multiset equality is the
  # signal (a doubled counter differs row-wise either way)
  grep -E '^\((countrow|route|dumpdone) ' "$WORK/log-$tag" \
    | LC_ALL=C sort > "$WORK/sig-$tag"
}
run_counted 1
run_counted 2
if [ ! -s "$WORK/sig-counted-abi1" ]; then
  echo "FAIL counted-session (no countrow/route lines; see $WORK/log-counted-abi1)"
  FAIL=$((FAIL+1))
elif ! diff -q "$WORK/sig-counted-abi1" "$WORK/sig-counted-abi2" >/dev/null; then
  echo "FAIL counted-session signature"
  diff "$WORK/sig-counted-abi1" "$WORK/sig-counted-abi2" | head -8 | sed 's/^/    /'
  FAIL=$((FAIL+1))
else
  counted_ok=1
  for csv in "$WORK/csv-counted-abi1"/*.csv; do
    [ -e "$csv" ] || continue
    rel="$(basename "$csv")"
    case "$rel" in '$stat_'*) continue ;; esac
    if ! diff -q <(LC_ALL=C sort "$csv") \
                 <(LC_ALL=C sort "$WORK/csv-counted-abi2/$rel") >/dev/null 2>&1
    then
      echo "FAIL counted-session contents ($rel)"; counted_ok=0; break
    fi
  done
  if [ "$counted_ok" -eq 1 ]; then
    echo "PASS counted-session ($(wc -l < "$WORK/sig-counted-abi1") signature lines)"
    PASS=$((PASS+1))
  else
    FAIL=$((FAIL+1))
  fi
fi

# the flavored-NATIVE leg (T4 2c; closes 2b's untested-flavored-native gap)
run_counted 2 native
if ! diff -q "$WORK/sig-counted-abi2" "$WORK/sig-counted-abi2-native" >/dev/null 2>&1; then
  echo "FAIL counted-session-flavored-native signature"
  diff "$WORK/sig-counted-abi2" "$WORK/sig-counted-abi2-native" | head -8 | sed 's/^/    /'
  FAIL=$((FAIL+1))
else
  fnative_ok=1
  for csv in "$WORK/csv-counted-abi2"/*.csv; do
    [ -e "$csv" ] || continue
    rel="$(basename "$csv")"
    case "$rel" in '$stat_'*) continue ;; esac
    if ! diff -q <(LC_ALL=C sort "$csv") \
                 <(LC_ALL=C sort "$WORK/csv-counted-abi2-native/$rel") >/dev/null 2>&1
    then
      echo "FAIL counted-session-flavored-native contents ($rel)"; fnative_ok=0; break
    fi
  done
  if [ "$fnative_ok" -eq 1 ]; then
    echo "PASS counted-session-flavored-native"
    PASS=$((PASS+1))
  else
    FAIL=$((FAIL+1))
  fi
fi

# RF1 slice 3: the ABI-2 leg's flavored artifacts (still in build/ from
# run_counted 2) double as attribute goldens-in-miniature.  Count and the
# negative maintenance flavors carry the kernel attribute -- maint1 keeps
# semijoin lookahead at planning and must NOT -- every flavored rule
# carries its fold attr, and no normal/delta plan carries any attribute
# spelling at all (absent-when-empty is what keeps their keys stable).
attr_ok=1
for f in build/*_count.*.plan build/*_maint3neg.*.plan build/*_maint4neg.*.plan; do
  [ -e "$f" ] || continue
  grep -qF '(attributes no-semijoin-reopt)' "$f" \
    || { echo "FAIL slice3-attributes ($(basename "$f") lacks no-semijoin-reopt)"; attr_ok=0; }
  grep -qF '(attrs (fold ' "$f" \
    || { echo "FAIL slice3-fold ($(basename "$f") lacks fold attrs)"; attr_ok=0; }
done
for f in build/*_maint1.*.plan; do
  [ -e "$f" ] || continue
  grep -qF '(attributes no-semijoin-reopt)' "$f" \
    && { echo "FAIL slice3-maint1 ($(basename "$f") carries no-semijoin-reopt)"; attr_ok=0; }
  grep -qF '(attrs (fold ' "$f" \
    || { echo "FAIL slice3-fold ($(basename "$f") lacks fold attrs)"; attr_ok=0; }
done
for f in build/*.plan; do
  case "$f" in *_count.*|*_maint*) continue ;; esac
  grep -qE '[(]attributes |[(]attrs ' "$f" \
    && { echo "FAIL slice3-normal ($(basename "$f") carries attribute spellings)"; attr_ok=0; }
done
if [ "$attr_ok" -eq 1 ]; then
  echo "PASS slice3-attributes"
  PASS=$((PASS+1))
else
  FAIL=$((FAIL+1))
fi

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
