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

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
