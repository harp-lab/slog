#!/usr/bin/env bash
#
# Incremental-session tests (docs/incremental.md Phase 0.B).
#
# B0 -- the version registry + environment: running a second program segment
# atop a loaded database in ONE resident daemon opens a version boundary
# (begin-segment): each relation the segment writes is rebound to a new
# physical version (a full copy of its predecessor), the predecessor stays
# positionally addressable ((pipeline), (sizes-at P), (dump-rel R P)), and
# the session's final content equals the from-scratch run of the union
# program (the stream-equivalence precursor; the full harness is 0.E4).
#
#   tests/session-tests.sh              (expects a warm build/ cache; run after
#                                        tests/run-tests.sh, or budget compile time)

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
expect_not() { # name unexpected-substring file
  if grep -qF "$2" "$3"; then
    echo "FAIL $1 (unexpected '$2' in $3)"; FAIL=$((FAIL+1))
  else
    echo "PASS $1"; PASS=$((PASS+1))
  fi
}

# Tests compile at -O0 (fast, no background -O2/hot-swap; session-drive.rkt
# has no upgrade logic).  Correctness is optimization-independent.
export SLOG_OPT=0

make -C daemon >/dev/null 2>&1 || { echo "daemon build failed"; exit 1; }

# --- B0.1: two-segment version chain over plain tables --------------------
# base: edge{3} -> path{6}; seg2 adds edge (4 5): edge{4} -> path{10}.
# The chains, positional sizes, and a positional dump must all show the
# base state at position 0 and the grown state after the boundary (pos 1).
rm -rf data/sess_b0a
timeout 600 racket slog.rkt --no-banner --out-db sess_b0a tests/session/base.slog \
  > out/sess-b0-base.log 2>&1
timeout 600 racket tests/api/session-drive.rkt \
  open:sess_b0a run:tests/session/seg2.slog \
  pipeline sizes-at:0 sizes-at:1 dump-rel:path,0 \
  > out/sess-b0.log 2>&1
expect "b0-boundary"    "(segment 1 2)" out/sess-b0.log
expect "b0-edge-chain"  "(rel edge (v 0 0 3) (v 1 1 4))" out/sess-b0.log
expect "b0-path-chain"  "(rel path (v 0 0 6) (v 1 1 10))" out/sess-b0.log
expect "b0-sizes-base"  "(sizes-at 0 (edge 3) (path 6))" out/sess-b0.log
expect "b0-sizes-new"   "(sizes-at 1 (edge 4) (path 10))" out/sess-b0.log
expect "b0-dump-old"    "(dumpdone 6)" out/sess-b0.log

# --- B0.2: structs + lattices across the boundary, vs the union oracle ----
# base2: pair{2}, out{2}, dist 3 keys; seg2b re-derives (pair 1 2) (must
# dedup to the base-minted id through the copied allocators -- a fresh id
# would surface as pair{4}/out{4}), adds (pair 5 6), and improves edge 1->2
# so dist's values ascend in the new version.  The session's saved CSVs
# must equal a from-scratch run of the union program (content oracle:
# struct rendering is content-based, so ids may differ freely).
rm -rf data/sess_b0b out/sess-b0-session-csv
timeout 600 racket slog.rkt --no-banner --out-db sess_b0b tests/session/base2.slog \
  > out/sess-b0b-base.log 2>&1
timeout 600 racket tests/api/session-drive.rkt \
  open:sess_b0b run:tests/session/seg2b.slog \
  pipeline sizes-at:0 write-csv:out/sess-b0-session-csv \
  > out/sess-b0b.log 2>&1
expect "b0-pair-chain"  "(rel pair (v 0 0 2) (v 1 1 3))" out/sess-b0b.log
expect "b0-out-chain"   "(rel out (v 0 0 2) (v 1 1 3))" out/sess-b0b.log
expect "b0-dist-chain"  "(rel dist (v 0 0 3) (v 1 1 3))" out/sess-b0b.log
expect "b0-lat-base"    "(dist 3)" out/sess-b0b.log

timeout 600 racket slog.rkt --no-banner --debug-dir out/sess-b0-oracle-csv \
  tests/session/combined2.slog > out/sess-b0-oracle.log 2>&1
for rel in in out pair edge dist; do
  if ! diff <(sort "out/sess-b0-session-csv/$rel.csv" 2>/dev/null) \
            <(sort "out/sess-b0-oracle-csv/$rel.csv" 2>/dev/null) >/dev/null 2>&1; then
    echo "FAIL b0-oracle-$rel (session CSV != from-scratch union CSV)"
    FAIL=$((FAIL+1))
  else
    echo "PASS b0-oracle-$rel"; PASS=$((PASS+1))
  fi
done

# --- B1: cone-limited replay-entry ----------------------------------------
# cone.slog holds two independent components (edge/path, color/bright).  A
# batch into edge re-enters ONLY path's stratum -- the driver's cone over
# the .meta reads/dynamic-rels has exactly one stratum ("(reenter edge 1)"),
# path absorbs the batch (3 -> 6 tuples), and bright survives the re-entry
# reload untouched (restored from its own dumped shards, the keep-alive
# discipline).
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/cone.slog \
  add-tuple:edge,3,4 reenter:edge \
  dump-rel:path dump-rel:bright \
  > out/sess-b1.log 2>&1
expect "b1-cone-limited" "(reenter edge 1)" out/sess-b1.log
expect "b1-path-grown"   "(dumpdone 6)" out/sess-b1.log
expect "b1-bright-kept"  "(dumpdone 1)" out/sess-b1.log

# --- B1 across segments: anchor filter + rebound guard ---------------------
# Two segments (base, seg2 -- both write edge/path), then a batch into
# edge.  The anchored version is seg2's (the latest binding), so the cone
# holds ONLY seg2's path stratum -- segment 1's read the predecessor
# version and must not re-fire.  Path absorbs the batch: 10 -> 15 tuples
# (nodes 1..6 chain).
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/base.slog run:tests/session/seg2.slog \
  add-tuple:edge,5,6 reenter:edge \
  dump-rel:path \
  > out/sess-b1m.log 2>&1
expect "b1m-cone-anchored" "(reenter edge 1)" out/sess-b1m.log
expect "b1m-path-grown"    "(dumpdone 15)" out/sess-b1m.log

# A batch into color puts cone.slog's bright stratum in the cone, but a
# later segment REWROTE bright -- latest-env re-entry is unsound there and
# must refuse (positional/anchored replay arrives with 0.C).
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/cone.slog run:tests/session/seg-bright.slog \
  add-tuple:color,8 reenter:color \
  > out/sess-b1g.log 2>&1
expect "b1-rebound-guard" "tip re-entry is unsound here" out/sess-b1g.log

# --- B2: deletions + clear-and-rerun ---------------------------------------
# Plain deletion: retract edge (2 3), clear-and-rerun cone(edge) -- path
# rebuilds from scratch over the suffix: {(1,2),(3,4)} only.
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/base.slog \
  del-tuple:edge,2,3 rerun:edge \
  dump-rel:path \
  > out/sess-b2d.log 2>&1
expect "b2-deleted"    "(deleted edge 1)" out/sess-b2d.log
expect "b2-del-cone"   "(rerun edge 1 " out/sess-b2d.log
expect "b2-path-minus" "(dumpdone 2)" out/sess-b2d.log

# Negation cone (the reserved "~ + increments" case, 0.A8): unreached =
# nodes NOT path-reachable from 1.  A monotone ADD shrinks it (3 -> 2), a
# deletion grows it (2 -> 4); both route through clear-and-rerun (the cone
# holds a neg edge), and each re-run recomputes the complement exactly.
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/negsess.slog \
  dump-rel:unreached \
  add-tuple:edge,3,4 rerun:edge dump-rel:unreached \
  del-tuple:edge,2,3 rerun:edge dump-rel:unreached \
  > out/sess-b2n.log 2>&1
expect "b2-neg-initial" "(dumpdone 3)" out/sess-b2n.log
expect "b2-neg-cone"    "(rerun edge 2 " out/sess-b2n.log
expect "b2-neg-shrunk"  "(dumpdone 2)" out/sess-b2n.log
expect "b2-neg-grown"   "(dumpdone 4)" out/sess-b2n.log

# replay-entry must refuse the negation cone and point at rerun
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/negsess.slog \
  add-tuple:edge,4,5 reenter:edge \
  > out/sess-b2r.log 2>&1
expect "b2-neg-refusal" "use rerun (clear-and-rerun, 0.B2)" out/sess-b2r.log

# Structs in the cone (§0.5 mode 2's id note): retract (in 3 4) -- the
# out/pair stratum clears and re-derives; pair re-mints ids (allocators
# monotone, registrations kept) and out's rows still resolve their struct
# ids (content rendering proves no dangling references).  dist is outside
# cone(in) and must survive untouched.
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/base2.slog \
  del-tuple:in,3,4 rerun:in \
  dump-rel:out dump-rel:pair sizes-at:99 \
  > out/sess-b2s.log 2>&1
expect "b2-struct-cone" "(rerun in 1 " out/sess-b2s.log
expect "b2-out-minus"   "(dumpdone 1)" out/sess-b2s.log
expect "b2-out-content" "(dumprow (pair 1 2))" out/sess-b2s.log
expect "b2-dist-kept"   "(dist 3)" out/sess-b2s.log

# --- B4+B5: the routing rule (compiler/session.rkt flush) -------------------
# Queued signed batches route per §0.5: all-adds + a SINGLE-stratum
# monotone cone -> delta-entry ("(route delta 1)", the lazily-compiled
# build/<hash>_delta.O0.so, O(change)); a same-point add/delete pair
# collapses to an empty flush ("(flush 0)", content untouched); a deletion
# routes the union cone through clear-and-rerun ("(route rerun N M)").
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/base.slog \
  batch+:edge,4,5 flush dump-rel:path \
  batch+:edge,7,8 batch-:edge,7,8 flush dump-rel:edge \
  batch-:edge,1,2 flush dump-rel:path \
  > out/sess-b4.log 2>&1
expect "b4-route-delta"   "(route delta 1)" out/sess-b4.log
expect "b4-add-applied"   "(dumpdone 10)" out/sess-b4.log
expect "b4-collapse"      "(flush 0)" out/sess-b4.log
expect "b4-collapse-kept" "(dumpdone 4)" out/sess-b4.log
expect "b4-route-rerun"   "(route rerun 1 " out/sess-b4.log
expect "b4-del-applied"   "(dumpdone 6)" out/sess-b4.log

# a monotone ADD whose cone crosses a negation still routes to rerun
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/negsess.slog \
  batch+:edge,3,4 flush dump-rel:unreached \
  > out/sess-b4n.log 2>&1
expect "b4-neg-route"  "(route rerun 2 " out/sess-b4n.log
expect "b4-neg-result" "(dumpdone 2)" out/sess-b4n.log

# a MULTI-stratum monotone cone stays on replay-entry (boundary-delta
# capture between cone strata is M0's presence-transition machinery)
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/twohop.slog \
  batch+:edge,3,4 flush dump-rel:endpoint \
  > out/sess-b4m.log 2>&1
expect "b4-multihop-replay" "(route reenter 2)" out/sess-b4m.log
expect "b4-multihop-result" "(dumpdone 3)" out/sess-b4m.log

# --- B5 repeated delta-entry + B6 exact-once staging ------------------------
# Three consecutive delta flushes extend the chain 1..4 to 1..7; each must
# route delta (live indices survive beginStratumDelta across flushes; B3's
# husk-clearing frees each superseded delta incarnation) and the closure
# must be exact: C(7,2) = 21 paths.
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/base.slog \
  batch+:edge,4,5 flush \
  batch+:edge,5,6 flush \
  batch+:edge,6,7 flush \
  dump-rel:path write-csv:out/sess-b5-csv \
  > out/sess-b5.log 2>&1
expect "b5-repeat-delta" "(route delta 1)" out/sess-b5.log
if [ "$(grep -cF '(route delta 1)' out/sess-b5.log)" = "3" ]; then
  echo "PASS b5-all-three-delta"; PASS=$((PASS+1))
else
  echo "FAIL b5-all-three-delta (expected 3 delta routes)"; FAIL=$((FAIL+1))
fi
expect "b5-closure-exact" "(dumpdone 21)" out/sess-b5.log

# B6 -- exact-once staging discipline (§0.3, §8; the M0 prerequisite): the
# FIRST delta flush's fire audit must show the batch fired each rule
# exactly the O(change) number of times -- edge->path once (the one new
# edge), the recursive rule 3 times (the three paths reaching node 4).  A
# double-staged batch (insert + restage, or two shard entries) would fire
# the once-variants twice per tuple and these exact counts would not
# appear.
expect_re "b6-exact-once-base" '"base.slog:9"[[:space:]]+"all:edge"[[:space:]]+1\b' "out/sess-b5-csv/\$stat_fires.csv"
expect_re "b6-exact-once-rec"  '"base.slog:14"[[:space:]]+"all:edge"[[:space:]]+3\b' "out/sess-b5-csv/\$stat_fires.csv"

# --- 0.C: anchored batches (back-insertion) --------------------------------
# An add anchored INSIDE segment 1's version (position 1, edge@v0): the
# anchored walk applies it to v0, re-runs segment 1's path stratum
# positionally, refreshes both inheritance boundaries, and re-runs
# segment 2 -- the OLD environment shows the back-inserted state
# (edge 4 / path 10 at position 2) and the tip closes to C(6,2) = 15,
# content-equal to the from-scratch run with the edge in segment 1.
rm -rf out/sess-c-anchored-csv out/sess-c-oracle-csv
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/base.slog run:tests/session/seg2.slog \
  abatch+:1,edge,0,1 flush \
  sizes-at:2 dump-rel:path write-csv:out/sess-c-anchored-csv \
  > out/sess-c-add.log 2>&1
expect    "c-anchored-route" "(route anchored edge 1 3)" out/sess-c-add.log
expect_re "c-anchored-old"   '\(sizes-at 2 .*\(edge 4\).*\(path 10\)' out/sess-c-add.log
expect    "c-anchored-tip"   "(dumpdone 15)" out/sess-c-add.log
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/base01.slog run:tests/session/seg2.slog \
  write-csv:out/sess-c-oracle-csv \
  > out/sess-c-oracle.log 2>&1
for rel in edge path; do
  if diff <(sort "out/sess-c-anchored-csv/$rel.csv" 2>/dev/null) \
          <(sort "out/sess-c-oracle-csv/$rel.csv" 2>/dev/null) >/dev/null 2>&1; then
    echo "PASS c-anchored-oracle-$rel"; PASS=$((PASS+1))
  else
    echo "FAIL c-anchored-oracle-$rel (back-inserted session != from-scratch)"; FAIL=$((FAIL+1))
  fi
done

# anchored DELETION: edge (2 3) removed from segment 1's version -- the
# old environment shrinks (edge 2 / path 2) and the tip rebuilds to the
# 4-path closure over {1-2, 3-4, 4-5}
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/base.slog run:tests/session/seg2.slog \
  abatch-:1,edge,2,3 flush \
  sizes-at:2 dump-rel:path \
  > out/sess-c-del.log 2>&1
expect    "c-adel-applied" "(deleted edge 1)" out/sess-c-del.log
expect_re "c-adel-old"     '\(sizes-at 2 .*\(edge 2\).*\(path 2\)' out/sess-c-del.log
expect    "c-adel-tip"     "(dumpdone 4)" out/sess-c-del.log

# a rebuilt boundary RE-APPLIES the logged tip batch: tip flush adds
# edge (5 6) (delta route), then the anchored walk refreshes edge@v1
# (wiping it) and the log restores it -- the 21-path closure over the
# 0..6 chain holds ONLY if the re-application happened
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/base.slog run:tests/session/seg2.slog \
  batch+:edge,5,6 flush \
  abatch+:1,edge,0,1 flush \
  dump-rel:path recipe \
  > out/sess-c-reapply.log 2>&1
expect "c-reapply-tip"    "(dumpdone 21)" out/sess-c-reapply.log
# the recipe carries both batches at ordinal anchors (§0.4: never raw
# positions) alongside the run steps
expect "c-recipe-run"     '(run "tests/session/base.slog")' out/sess-c-reapply.log
expect "c-recipe-tipb"    "(batch edge (v 1) ((5 6)) ())" out/sess-c-reapply.log
expect "c-recipe-anchb"   "(batch edge (v 0) ((0 1)) ())" out/sess-c-reapply.log

# log collapse (§0.2): an add flushed and then deleted at the same
# version leaves NO trace in the recipe
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/base.slog \
  batch+:edge,9,9 flush \
  batch-:edge,9,9 flush \
  recipe dump-rel:path \
  > out/sess-c-collapse.log 2>&1
expect     "c-collapse-content" "(dumpdone 6)" out/sess-c-collapse.log
expect_not "c-collapse-recipe"  "(9 9)" out/sess-c-collapse.log

# --- 0.C1: import-delta (bulk bin payload, transport 2) ---------------------
# a mini bin-db payload merges at the tip and its targets' cones re-run;
# the name-map (edge2 -> edge) is the D4 rename parameter's first caller
rm -rf data/sess_cpay data/sess_cpay2
timeout 600 racket slog.rkt --no-banner --out-db sess_cpay tests/session/payload.slog \
  > out/sess-cpay.log 2>&1
timeout 600 racket slog.rkt --no-banner --out-db sess_cpay2 tests/session/payload2.slog \
  > out/sess-cpay2.log 2>&1
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/base.slog \
  import-delta:data/sess_cpay \
  dump-rel:path \
  > out/sess-c-imp.log 2>&1
expect "c-import-cone"   "(import-delta data/sess_cpay 1)" out/sess-c-imp.log
expect "c-import-result" "(dumpdone 9)" out/sess-c-imp.log
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/base.slog \
  import-delta:data/sess_cpay2,edge2=edge \
  dump-rel:path \
  > out/sess-c-impmap.log 2>&1
expect "c-import-mapped" "(dumpdone 9)" out/sess-c-impmap.log

# --- 0.C4: the inline-transport ceiling --------------------------------------
# past the threshold the driver refuses inline batches, pointing at the
# bin-payload path (threshold shrunk via env for the test)
SLOG_INLINE_MAX=2 timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/base.slog \
  batch+:edge,50,51 batch+:edge,51,52 batch+:edge,52,53 flush \
  > out/sess-c-limit.log 2>&1
expect "c-inline-limit" "exceeds 2: write a bin database" out/sess-c-limit.log

# --- 0.C4: the bulk path (fact stream -> freezer -> import-delta) -----------
# 3000 edges -- far past the inline ceiling -- enter as a frozen mini
# bin-db (the documented external-producer stream, docs/freeze.md §3) and
# merge in one import; the linear downstream cone re-runs once.
rm -rf out/sess-c-bulk-db
{
  echo '(table edge 2)'
  for i in $(seq 100 3099); do echo "(edge $i $((i+1)))"; done
} > out/sess-c-bulk.facts
timeout 600 racket -e '
(require "compiler/tools.rkt" racket/file)
(run-freezer "out/sess-c-bulk-db" (file->string "out/sess-c-bulk.facts"))
(displayln "frozen-ok")' > out/sess-c-bulk.log 2>&1
expect "c4-freeze" "frozen-ok" out/sess-c-bulk.log
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/bulk.slog \
  import-delta:out/sess-c-bulk-db \
  dump-rel:node \
  > out/sess-c-bulkimp.log 2>&1
expect "c4-bulk-cone"   "(import-delta out/sess-c-bulk-db 1)" out/sess-c-bulkimp.log
expect "c4-bulk-result" "(dumpdone 3000)" out/sess-c-bulkimp.log

# --- 0.C2: recipe (de)serialisers + digest -----------------------------------
timeout 300 racket -e '
(require "compiler/dbmeta.rkt" racket/file)
(define r1 `(slog-recipe (run "a.slog") (batch edge (v 0) ((1 2)) ())))
(define r2 `(slog-recipe (run "a.slog") (batch edge (v 1) ((1 2)) ())))
(write-recipe "out" r1)
(unless (equal? (read-recipe "out") r1) (error (quote roundtrip)))
(when (equal? (recipe-digest r1) (recipe-digest r2)) (error (quote digest)))
(displayln "recipe-roundtrip-ok")
;; C5: payload externalisation into delta.<k>/ + relative reference
(make-directory* "out/c5-payload") (make-directory* "out/c5-layer")
(call-with-output-file "out/c5-payload/x.bin" #:exists (quote replace)
  (lambda (o) (write-bytes #"abc" o)))
(define r3 (externalize-recipe-payloads
            `(slog-recipe (run "a.slog") (import-delta "out/c5-payload" ()))
            "out/c5-layer"))
(unless (equal? r3 `(slog-recipe (run "a.slog") (import-delta (delta 0) ())))
  (error (quote externalize) "~s" r3))
(unless (file-exists? "out/c5-layer/delta.0/x.bin") (error (quote payload-copy)))
(unless (equal? (recipe-payload-dir "out/c5-layer" `(delta 0)) "out/c5-layer/delta.0")
  (error (quote payload-resolve)))
(displayln "recipe-placement-ok")' > out/sess-c-recipe.log 2>&1
expect "c2-roundtrip" "recipe-roundtrip-ok" out/sess-c-recipe.log
expect "c5-placement" "recipe-placement-ok" out/sess-c-recipe.log

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
