#!/usr/bin/env bash
#
# Sanity tests for the plugin-based daemon API: the daemon is only ever sent
# .so paths; opening/writing/querying the database happens through generated
# action plugins (compiler/actions.rkt).
#
#   tests/api-tests.sh              (expects a warm build/ cache; run after
#                                    tests/run-tests.sh, or budget compile time)

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
expect_not() { # name unexpected-substring file
  if grep -qF "$2" "$3"; then
    echo "FAIL $1 (unexpected '$2' in $3)"; FAIL=$((FAIL+1))
  else
    echo "PASS $1"; PASS=$((PASS+1))
  fi
}

# --- 1. relation sizes reported back over the connection after a run
timeout 300 racket slog.rkt --no-banner --sizes tests/reach.slog \
  > out/api-reach.log 2>&1
expect "sizes-edge"  "(relation_size edge 3)" out/api-reach.log
expect "sizes-path"  "(relation_size path 6)" out/api-reach.log

# struct interning counts distinct contents (structs.slog inserts (pair 1 2) twice)
timeout 300 racket slog.rkt --no-banner --sizes tests/structs.slog \
  > out/api-structs.log 2>&1
expect "sizes-struct" "(relation_size pair 2)" out/api-structs.log
expect "sizes-out"    "(relation_size out 2)"  out/api-structs.log

# --- 2. write the database, reopen it in a fresh daemon, sizes persist
rm -rf data/apidb
timeout 300 racket slog.rkt --no-banner --out-db apidb tests/reach.slog \
  > out/api-write.log 2>&1
timeout 300 racket slog.rkt --no-banner --sizes -d apidb tests/api/noop.slog \
  > out/api-reopen.log 2>&1
expect "reopen-edge" "(relation_size edge 3)" out/api-reopen.log
expect "reopen-path" "(relation_size path 6)" out/api-reopen.log

# --- 3. per-relation refresh from another database on disk:
#        open reach's db, replace edge from line's db (11 edges), path keeps
rm -rf data/apilinedb
timeout 300 racket slog.rkt --no-banner --out-db apilinedb tests/line.slog \
  > out/api-line.log 2>&1
timeout 300 racket tests/api/send-actions.rkt \
  open:apidb load-rel:apilinedb,edge sizes \
  > out/api-loadrel.log 2>&1
expect "loadrel-edge" "(relation_size edge 11)" out/api-loadrel.log
expect "loadrel-path" "(relation_size path 6)"  out/api-loadrel.log

# --- 4. per-relation write: extract just `path` into its own database
rm -rf data/apipartial
timeout 300 racket tests/api/send-actions.rkt \
  open:apidb write-rel:apipartial,path \
  > out/api-partialw.log 2>&1
timeout 300 racket tests/api/send-actions.rkt \
  open:apipartial sizes \
  > out/api-partial.log 2>&1
expect     "partial-path"    "(relation_size path 6)" out/api-partial.log
expect_not "partial-no-edge" "(relation_size edge"    out/api-partial.log

# --- 5. mtime-based refresh: unchanged reports 0; after the on-disk file
#        changes MID-SESSION, reports 1 (and reloads)
timeout 300 racket tests/api/send-actions.rkt \
  open:apidb refresh-rel:apidb,edge \
  > out/api-fresh0.log 2>&1
expect "refresh-unchanged" "(refreshed edge 0)" out/api-fresh0.log

# build the plugins up front, then drive one daemon session through a fifo
# so the touch lands between the open and the refresh
mapfile -t SOS < <(timeout 300 racket tests/api/send-actions.rkt --paths \
                     open:apidb refresh-rel:apidb,edge sizes)
rm -f out/api-fifo; mkfifo out/api-fifo
SLOG_NO_MEM_CAP=1 ./daemon/slogd < out/api-fifo > out/api-fresh1.log 2>&1 &
DPID=$!
exec 9> out/api-fifo
echo "${SOS[0]}" >&9          # open
sleep 2
touch data/apidb/table.edge.arity.2/*
echo "${SOS[1]}" >&9          # refresh-rel
echo "${SOS[2]}" >&9          # sizes
exec 9>&-
wait $DPID
rm -f out/api-fifo
expect "refresh-changed" "(refreshed edge 1)" out/api-fresh1.log
expect "refresh-size"    "(relation_size edge 3)" out/api-fresh1.log

# --- 6. collection-arena round trip: rows holding collection words survive
#        write-db + reopen because value.nodes re-interns in iterator order,
#        reproducing every node id (daemon/arena.h).  The structural print is
#        the assertion: it only renders if every id resolves after reload.
rm -rf data/apicndb
timeout 300 racket slog.rkt --no-banner --out-db apicndb tests/cn_basic.slog \
  > out/api-cn-write.log 2>&1
if [ -d data/apicndb/value.nodes ]; then
  echo "PASS cn-nodes-dir"; PASS=$((PASS+1))
else
  echo "FAIL cn-nodes-dir (no value.nodes written)"; FAIL=$((FAIL+1))
fi
timeout 300 racket slog.rkt --no-banner --sizes -d apicndb \
  --debug-dir out/api-cn-reopen tests/api/noop.slog \
  > out/api-cn-reopen.log 2>&1
expect "cn-reopen-size"  "(relation_size canon 1)"  out/api-cn-reopen.log
expect "cn-reopen-print" "{1:1 2:1 5:1 8:1}"        out/api-cn-reopen/canon.csv
expect "cn-reopen-nest"  "{(mk 3 4):{1:2}}"         out/api-cn-reopen/nest.csv
expect "cn-reopen-env"   "{\"y\":2 \"x\":3}"        out/api-cn-reopen/env.csv

# --- 7. struct-id stability across open + stratum (db-merge §7.1): opened
#        instances keep their ids (the master index's static WriteTask
#        ingests the reloaded delta verbatim; InternStructTask dedups
#        against those rows), and NEWLY interned structs allocate above
#        every loaded id.  The per-file allocator-seeding bug re-issued
#        owned ids: 8 of 200 new structs collided, silently collapsing
#        keep to 392 rows and pointing rows at the wrong struct.
rm -rf data/apistructdb
timeout 300 racket slog.rkt --no-banner --out-db apistructdb tests/api/structdb.slog \
  > out/api-structdb.log 2>&1
timeout 300 racket slog.rkt --no-banner --sizes -d apistructdb \
  --debug-dir out/api-structuse tests/api/structuse.slog \
  > out/api-structuse.log 2>&1
expect "structs-mk"      "(relation_size mk 400)"     out/api-structuse.log
expect "structs-keep"    "(relation_size keep 400)"   out/api-structuse.log
expect "structs-oldf"    "(relation_size oldf 400)"   out/api-structuse.log
expect "structs-probe5"  "(relation_size probe5 1)"   out/api-structuse.log
expect "structs-probe5-val" "10" out/api-structuse/probe5.csv

# --- 8. database merge (docs/db-merge.md P1): open A, import B ==
#        from-scratch fixpoint over the unioned facts, compared by CSV
#        rendering (ids are database-local; renderings are content).
#        Fixtures cover all four remapped id spaces: strings, struct
#        instances (dedup: mk 3+3 with one shared content = 5), collection
#        words (string-keyed maps, REBUILT on import), a (min int) lattice
#        (key 3 joins min(30,5)=5) and a (set int) lattice (per-key union).
rm -rf data/apimrga data/apimrgb data/apimrgexp
timeout 300 racket slog.rkt --no-banner --out-db apimrga tests/api/mergea.slog \
  > out/api-mergea.log 2>&1
timeout 300 racket slog.rkt --no-banner --out-db apimrgb tests/api/mergeb.slog \
  > out/api-mergeb.log 2>&1
timeout 300 racket slog.rkt --no-banner --out-db apimrgexp \
  --debug-dir out/api-mergedexp tests/api/mergeexp.slog \
  > out/api-mergeexp.log 2>&1
rm -rf out/api-merged
timeout 300 racket tests/api/send-actions.rkt \
  open:apimrga import:apimrgb sizes write-csv:out/api-merged \
  > out/api-merge.log 2>&1
expect "merge-mk"   "(relation_size mk 5)" out/api-merge.log
expect "merge-t"    "(relation_size t 5)"  out/api-merge.log
expect "merge-d"    "(relation_size d 4)"  out/api-merge.log
MERGE_DIFF=0
for f in out/api-mergedexp/*.csv; do
  b="$(basename "$f")"
  diff <(LC_ALL=C sort "$f") <(LC_ALL=C sort "out/api-merged/$b") \
    > /dev/null 2>&1 || MERGE_DIFF=1
done
diff <(ls out/api-merged) <(ls out/api-mergedexp) > /dev/null 2>&1 || MERGE_DIFF=1
if [ "$MERGE_DIFF" -eq 0 ]; then
  echo "PASS merge-differential"; PASS=$((PASS+1))
else
  echo "FAIL merge-differential (merged CSVs differ from from-scratch union)"; FAIL=$((FAIL+1))
fi

# self-merge is a no-op (everything dedups/joins)
rm -rf out/api-selfm out/api-adump
timeout 300 racket tests/api/send-actions.rkt \
  open:apimrga write-csv:out/api-adump > /dev/null 2>&1
timeout 300 racket tests/api/send-actions.rkt \
  open:apimrga import:apimrga write-csv:out/api-selfm > /dev/null 2>&1
SELF_DIFF=0
for f in out/api-adump/*.csv; do
  b="$(basename "$f")"
  diff <(LC_ALL=C sort "$f") <(LC_ALL=C sort "out/api-selfm/$b") \
    > /dev/null 2>&1 || SELF_DIFF=1
done
if [ "$SELF_DIFF" -eq 0 ]; then
  echo "PASS merge-self-noop"; PASS=$((PASS+1))
else
  echo "FAIL merge-self-noop (self-import changed content)"; FAIL=$((FAIL+1))
fi

# same-session import-then-run: a relation exclusive to the imported db is
# unknown to the program AND its compile-time manifest, so it survives the
# stratum's reload only via runStratum's orphan-relation restore
rm -rf data/apimrgc
timeout 300 racket slog.rkt --no-banner --out-db apimrgc tests/api/mergec.slog \
  > out/api-mergec.log 2>&1
timeout 300 racket slog.rkt --no-banner -d apimrga tests/api/mergerun.slog \
  > out/api-mergerun-compile.log 2>&1
# The stratum plugin the driver sent: tiered mode logs the -O0 artifact
# (build/<hash>.O0.so), a cached run the plain build/<hash>.so; either replays.
RUNSO="$(grep -oE '/[^ ]*/build/[a-f0-9]+(\.O0)?\.so' out/api-mergerun-compile.log | head -1)"
timeout 300 racket tests/api/send-actions.rkt \
  "open:apimrga" "import:apimrgc" "so:$RUNSO" sizes \
  > out/api-importrun.log 2>&1
expect "importrun-onlyc" "(relation_size onlyc 2)" out/api-importrun.log
expect "importrun-twice" "(relation_size twice 3)" out/api-importrun.log

# --- 9. keep-alive hardening + (schema) (docs/finish-collections.md §B)
# 9a. an imported-exclusive relation survives TWO chained strata: each
#     beginStratum reloads (dump + clear all indices), so onlyc must ride
#     orphan-restore -> dump -> orphan-restore across both runs
timeout 300 racket tests/api/send-actions.rkt \
  "open:apimrga" "import:apimrgc" "so:$RUNSO" "so:$RUNSO" sizes \
  > out/api-chain2.log 2>&1
expect "chain2-onlyc" "(relation_size onlyc 2)" out/api-chain2.log
expect "chain2-twice" "(relation_size twice 3)" out/api-chain2.log

# 9b. a post-import-run write-db PERSISTS the orphan (writeDatabaseBIN sees
#     its restored index), and a fresh daemon reopens it with correct sizes
rm -rf data/apichain
timeout 300 racket tests/api/send-actions.rkt \
  "open:apimrga" "import:apimrgc" "so:$RUNSO" "write-db:apichain" \
  > out/api-chainw.log 2>&1
timeout 300 racket tests/api/send-actions.rkt \
  open:apichain sizes > out/api-chainr.log 2>&1
expect "chainw-onlyc" "(relation_size onlyc 2)" out/api-chainr.log
expect "chainw-twice" "(relation_size twice 3)" out/api-chainr.log

# 9c. (schema) after open+import lists the UNION with correct kinds/specs
#     (struct ids are session-local, so mk's sid is not pinned)
timeout 300 racket tests/api/send-actions.rkt \
  open:apimrga import:apimrgc schema > out/api-schema.log 2>&1
expect "schema-table"  "(schema-rel table t 3)"      out/api-schema.log
expect "schema-seed"   "(schema-rel table seed 2)"   out/api-schema.log
expect "schema-onlyc"  "(schema-rel table onlyc 2)"  out/api-schema.log
expect "schema-minlat" "(schema-rel lat d 2 min-int)" out/api-schema.log
expect "schema-setlat" "(schema-rel lat r 2 set-int)" out/api-schema.log
expect "schema-struct" "(schema-rel struct mk 3"      out/api-schema.log
expect "schema-end"    "(schema-end)"                 out/api-schema.log

# 9d. the parsed schema manifest of the live session equals what a directory
#     scan reads back from a write-db'd copy (schema-manifest.rkt)
rm -rf data/apischemadb
if timeout 300 racket tests/api/schema-manifest.rkt apimrga apimrgc apischemadb \
     > out/api-schemaman.log 2>&1; then
  echo "PASS schema-manifest"; PASS=$((PASS+1))
else
  echo "FAIL schema-manifest (see out/api-schemaman.log)"; FAIL=$((FAIL+1))
fi

# --- 10. sequence-arena round trip (docs/sequences.md §8): rows holding
#         sequence words survive write-db + reopen because value.seq
#         re-interns records in iterator order, reproducing every node id
#         (daemon/seq.h).  The structural print is the assertion: it only
#         renders if every id resolves after reload.  PARAMS carries the
#         chunker format version (§8.2).
rm -rf data/apiseqdb
timeout 300 racket slog.rkt --no-banner --out-db apiseqdb tests/seq_io.slog \
  > out/api-seq-write.log 2>&1
if [ -f data/apiseqdb/value.seq/PARAMS ]; then
  echo "PASS seq-params"; PASS=$((PASS+1))
else
  echo "FAIL seq-params (no value.seq/PARAMS written)"; FAIL=$((FAIL+1))
fi
timeout 300 racket slog.rkt --no-banner --sizes -d apiseqdb \
  --debug-dir out/api-seq-reopen tests/api/noop.slog \
  > out/api-seq-reopen.log 2>&1
expect "seq-reopen-size"  "(relation_size canon 1)"        out/api-seq-reopen.log
expect "seq-reopen-print" "[1 2 3 5 8]"                    out/api-seq-reopen/canon.csv
expect "seq-reopen-nest"  "[[1 2] [\"x\" 3.5] []]"         out/api-seq-reopen/nest.csv
expect "seq-reopen-bsz"   "80"                             out/api-seq-reopen/bsz.csv
# a tag-4 rope column survives the round trip (byte-leaf/byte-branch
# records re-intern in order; the root id resolves and renders whole)
expect "seq-reopen-rope"  "0123456789abcdefghij0123456789abcdefghij" \
                                                           out/api-seq-reopen/doc.csv
expect "seq-reopen-dsz"   "320"                            out/api-seq-reopen/dsz.csv

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
