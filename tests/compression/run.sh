#!/usr/bin/env bash
#
# db-compression oracle-diff harness (docs/db-compression.md §19, P1.7).
#
# For each program and each coverage `per`, save a compressed database, reload
# it (which recompiles prog.sexpr and REPLAYS to regenerate any sampled-out
# derived tuples), and assert the reloaded database is CONTENT-EQUAL, relation
# by relation, to an uncompressed --out-db of the same program (the oracle).
#
#   tests/compression/run.sh                 # default program set, per {100,90,60,20}
#   tests/compression/run.sh PROG...         # explicit programs
#   PERS="100 50" tests/compression/run.sh   # override coverage points
#
# Correctness must hold at EVERY per: the kept sample is only a witness/seed,
# so replay from origin must reproduce the full least fixpoint regardless of
# how many derived tuples were dropped.
set -u
cd "$(dirname "$0")/../.."
export SLOG_OPT="${SLOG_OPT:-0}"          # -O0: correctness is optimisation-independent
EMPTY="$(mktemp -d)/empty.slog"; printf ';; dump loader\n' > "$EMPTY"
PERS="${PERS:-100 90 60 20}"

PROGS=("$@")
if [ ${#PROGS[@]} -eq 0 ]; then
  PROGS=(tests/reach.slog tests/grandparent.slog tests/ex_eval.slog tests/ex_peano.slog
         tests/cn_basic.slog tests/mp_basic.slog tests/lst_basic.slog tests/st_basic.slog
         tests/nested.slog tests/lat_sssp.slog tests/lat_count.slog tests/lat_constprop.slog
         tests/dem_fib.slog tests/dem_stlc.slog tests/enum_basic.slog
         tests/stage_derived.slog
         # 2026-07-10: close the sequence / collection-lattice / freeze x
         # compression gaps -- the delta-layer save (docs/incremental.md 0.E)
         # reuses this exact struct-heap-trim + sample + prog.sexpr-replay DAG.
         # (frozen_fact deliberately omitted: its 1023-node cold build is slow
         # and widens the concurrent-build tempfile-race window; deep_fact
         # covers freeze x compression.)
         tests/seq_join.slog tests/seq_split_mixed.slog tests/str_rope.slog
         tests/lat_set.slog tests/lat_cjoin.slog tests/deep_fact.slog
         # 2026-07-11: stratified negation x compression (0.A, docs/
         # incremental.md 0.8).  neg_wild is load-bearing: its ~(h _)
         # emptiness rule caught ground-fact-rules classifying a negation-
         # bearing rule into the level-0 facts stratum (a non-monotone read
         # racing the facts' own iteration-0 writes on replay).
         tests/neg_reach.slog tests/neg_wild.slog
         # 2026-07-11: accelerator-seed sidecar (docs/db-compression.md §4.4
         # v2).  These are the only battery programs whose fixpoints run deep
         # enough (>= SLOG_ACCEL_MIN_ROUNDS) for compressed saves to write
         # accel/ -- they exercise sidecar recording, the struct-closure
         # union, verbatim accel ingest through the layer import, and (lat
         # variant) lattice dedup-by-key + merge-ingest, at every per.
         tests/accel_chain.slog tests/accel_lat_chain.slog)
fi

pass=0; fail=0; failed=()
dump() { # dump db $1 to dir $2 via the empty loader (replays a compressed db)
  rm -rf "$2"
  if ! racket slog.rkt --no-banner -d "$1" --debug-dir "$2" "$EMPTY" \
       > "out/dump-$(basename "$2").log" 2>&1; then
    echo "  DUMP-ERROR $1 (see out/dump-$(basename "$2").log):"
    tail -3 "out/dump-$(basename "$2").log" | sed 's/^/    /'
  fi
}
for prog in "${PROGS[@]}"; do
  name="$(basename "$prog" .slog)"
  [ -f "$prog" ] || { echo "SKIP $name (no such file)"; continue; }
  # oracle: uncompressed, dumped once
  rm -rf "data/${name}_o" "data/${name}_o.edb"
  racket slog.rkt --no-banner --out-db "${name}_o" "$prog" \
    > "out/save-${name}_o.log" 2>&1
  st=$?
  [ $st -ne 0 ] && echo "  SAVE-ERROR ${name}_o exit=$st (out/save-${name}_o.log)"
  dump "${name}_o" "out/cmp_o_$name"
  ocount=$(ls "out/cmp_o_$name"/*.csv 2>/dev/null | wc -l)
  if [ "$ocount" -eq 0 ]; then
    echo "FAIL $name (oracle produced no relations -- cannot verify)"
    # preserve the evidence: the save tree, both logs, the dump output
    fdir="out/forensics-$name-$$-$RANDOM"
    mkdir -p "$fdir"
    cp -r "data/${name}_o" "$fdir/db" 2>/dev/null
    cp -r "data/${name}_o.tmp" "$fdir/db.tmp" 2>/dev/null
    cp "out/save-${name}_o.log" "$fdir/save.log" 2>/dev/null
    cp "out/dump-cmp_o_$name.log" "$fdir/dump.log" 2>/dev/null
    echo "  forensics preserved: $fdir"
    fail=$((fail+1)); failed+=("$name/oracle")
    rm -rf "data/${name}_o" "data/${name}_o.edb" "out/cmp_o_$name"; continue
  fi
  for per in $PERS; do
    rm -rf "data/${name}_c" "data/${name}_c.edb"
    racket slog.rkt --no-banner --out-db-compressed "${name}_c" --per "$per" "$prog" \
      > "out/save-${name}_c.log" 2>&1
    st=$?
    [ $st -ne 0 ] && echo "  SAVE-ERROR ${name}_c per=$per exit=$st (out/save-${name}_c.log)"
    dump "${name}_c" "out/cmp_c_$name"
    ok=1
    if [ ! -d "out/cmp_c_$name" ]; then ok=0; echo "  FAIL $name per=$per (replay produced no dump)";
    else
      for f in "out/cmp_o_$name"/*.csv; do
        r="$(basename "$f" .csv)"
        # $stat_* are per-run daemon diagnostics (docs/stats.md), deliberately
        # outside the persistence contract: $stat_fixpoint carries timing
        # (nondeterministic) and $stat_fires counts instantiations, which a
        # replay legitimately re-fires over the whole reloaded DB -- both differ
        # oracle-vs-replay by design, so comparing them here is a false failure.
        # Content correctness is the real oracle; matches run-tests.sh policy.
        case "$r" in '$stat_'*) continue ;; esac
        if ! diff <(sort "out/cmp_o_$name/$r.csv") <(sort "out/cmp_c_$name/$r.csv" 2>/dev/null) >/dev/null 2>&1; then
          ok=0; echo "  FAIL $name per=$per: relation $r differs (oracle=$(wc -l <"out/cmp_o_$name/$r.csv") replay=$(wc -l <"out/cmp_c_$name/$r.csv" 2>/dev/null))"
        fi
      done
    fi
    if [ $ok -eq 1 ]; then pass=$((pass+1)); echo "  ok   $name per=$per ($(ls "out/cmp_o_$name"/*.csv|wc -l) relations)"; else fail=$((fail+1)); failed+=("$name/$per"); fi
    rm -rf "data/${name}_c" "data/${name}_c.edb" "out/cmp_c_$name"
  done
  rm -rf "data/${name}_o" "data/${name}_o.edb" "out/cmp_o_$name"
done
echo
echo "$pass passed, $fail failed"
[ $fail -gt 0 ] && { echo "failed: ${failed[*]}"; exit 1; }
exit 0
