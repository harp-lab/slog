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
# sess_lnk (the W6 round-trip below) records a manifest link edge to
# sess_cpay, so a stale copy from a prior run would trip the overwrite
# guard here -- clear the dependent first
rm -rf data/sess_cpay data/sess_cpay2 data/sess_lnk
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

# --- 0.D: renames, drops, hot-links ------------------------------------------
# W5, the rename pipeline: base produces path; (rename-rel path reach)
# rebinds it (zero data movement); a consumer segment reads reach.  A tip
# batch into reach logs at the rename binding; a batch anchored into
# segment 1's edge then walks the suffix -- the pre-rename path stratum
# re-runs positionally, the rename TRANSLATES the affected set (the
# consumer re-runs), and the alias re-apply restores the reach batch after
# path@v0's clear: reach = 10+1, endp = {2,3,4,5,91}.
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/base.slog \
  rename-rel:path,reach \
  run:tests/session/consumer.slog \
  dump-rel:endp \
  batch+:reach,90,91 flush \
  abatch+:1,edge,4,5 flush \
  dump-rel:reach dump-rel:endp recipe \
  > out/sess-d-rename.log 2>&1
expect "d-renamed"        "(renamed path reach 1)" out/sess-d-rename.log
expect "d-endp-initial"   "(dumpdone 3)" out/sess-d-rename.log
expect "d-walk-translates" "(route anchored edge 1 2)" out/sess-d-rename.log
expect "d-alias-reapply"  "(added reach 1)" out/sess-d-rename.log
expect "d-reach-final"    "(dumpdone 11)" out/sess-d-rename.log
expect "d-endp-final"     "(dumpdone 5)" out/sess-d-rename.log
expect "d-recipe-rename"  "(rename-rel path reach)" out/sess-d-rename.log

# drop + re-declare: the dropped lineage stays positionally addressable
# (path 6 at position 2); the re-declaration is a severed fresh chain
# (1 row); (schema) reflects the current environment
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/base.slog \
  drop-rel:path \
  run:tests/session/redecl.slog \
  sizes-at:2 dump-rel:path \
  > out/sess-d-drop.log 2>&1
expect    "d-dropped"     "(dropped path 1)" out/sess-d-drop.log
expect_re "d-old-lineage" '\(sizes-at 2 .*\(path 6\)' out/sess-d-drop.log
expect    "d-fresh-chain" "(dumpdone 1)" out/sess-d-drop.log

# hot-link (D5): same merge machinery as import-delta, recorded as a LINK
# step (payload stays a reference; externalisation leaves it alone)
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/base.slog \
  link:sess_cpay \
  dump-rel:path recipe \
  > out/sess-d-link.log 2>&1
expect "d-link-cone"   "(import-delta data/sess_cpay 1)" out/sess-d-link.log
expect "d-link-result" "(dumpdone 9)" out/sess-d-link.log
expect "d-link-recipe" '(link "sess_cpay" ())' out/sess-d-link.log

# D3: rename as an EDIT on a stored database -- one implementation with
# the batch edits (the op IS the action spec, streamed on load)
rm -rf data/sess_dedit
timeout 600 racket slog.rkt --no-banner --out-db sess_dedit tests/session/base.slog \
  > out/sess-d-edit0.log 2>&1
timeout 300 racket slog.rkt db edit sess_dedit rename-rel path reach \
  > out/sess-d-edit1.log 2>&1
expect "d-edit-recorded" "recorded edit on sess_dedit: (rename-rel path reach)" out/sess-d-edit1.log
timeout 600 racket slog.rkt --no-banner --sizes -d sess_dedit tests/api/noop.slog \
  > out/sess-d-edit2.log 2>&1
expect     "d-edit-applied" "(relation_size reach 6)" out/sess-d-edit2.log
expect_not "d-edit-no-old"  "(relation_size path" out/sess-d-edit2.log

# --- 0.E0c: per-program version boundaries in a multi-`run` program ---------
# strat_run2_main chains two `run` prerequisites; each program of the run
# tree gets its OWN begin-segment, so the pipeline versions their writes
# separately (three segments: p-facts, q, r+main).
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/strat_run2_main.slog \
  pipeline dump-rel:r \
  > out/sess-e0c.log 2>&1
expect "e0c-result" "(dumpdone 2)" out/sess-e0c.log
if [ "$(grep -oE '\(segment [0-9]+ [0-9]+\)' out/sess-e0c.log | wc -l)" -ge "2" ]; then
  echo "PASS e0c-per-program-segments"; PASS=$((PASS+1))
else
  echo "FAIL e0c-per-program-segments (expected >=2 segment boundaries)"; FAIL=$((FAIL+1))
fi

# --- 0.E1 + 0.E2: save a fed session; load = replay the recipe (W3) ---------
# A session (two segments + a tip batch + an anchored back-insertion) saves
# as data/sess_e1; loading it replays the recipe -- the tip content AND the
# versioned pipeline (point-addressed queries) both reconstruct.
rm -rf data/sess_e1 data/sess_e4 data/sess_e4f data/sess_bi \
       out/sess-e1-csv out/sess-e2-csv
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/base.slog run:tests/session/seg2.slog \
  batch+:edge,5,6 flush \
  abatch+:1,edge,0,1 flush \
  save:sess_e1 \
  dump-rel:path write-csv:out/sess-e1-csv \
  > out/sess-e1.log 2>&1
expect "e1-saved"    "(saved sess_e1 4)" out/sess-e1.log
expect "e1-live-tip" "(dumpdone 21)" out/sess-e1.log
timeout 600 racket tests/api/session-drive.rkt \
  open:sess_e1 \
  dump-rel:path sizes-at:2 write-csv:out/sess-e2-csv \
  > out/sess-e2.log 2>&1
expect    "e2-replayed" "(replayed-recipe sess_e1 4)" out/sess-e2.log
expect    "e2-tip"      "(dumpdone 21)" out/sess-e2.log
expect_re "e2-old-env"  '\(sizes-at 2 .*\(edge 4\).*\(path 10\)' out/sess-e2.log
for rel in edge path; do
  if diff <(sort "out/sess-e1-csv/$rel.csv" 2>/dev/null) \
          <(sort "out/sess-e2-csv/$rel.csv" 2>/dev/null) >/dev/null 2>&1; then
    echo "PASS e2-load-oracle-$rel"; PASS=$((PASS+1))
  else
    echo "FAIL e2-load-oracle-$rel (loaded session != saved session)"; FAIL=$((FAIL+1))
  fi
done

# --- W4: move & continue -- load, stream more, save again --------------------
# sess_e1 (0..6 chain, 21 paths) + edge (7 8)... wait, 6->7 extends the
# chain: closure over 0..7 = C(8,2) = 28.  The second save chains atop the
# first (its manifest links sess_e1); loading THAT replays both recipes.
rm -rf data/sess_e4
timeout 600 racket tests/api/session-drive.rkt \
  open:sess_e1 \
  batch+:edge,6,7 flush \
  save:sess_e4 \
  dump-rel:path \
  > out/sess-e4a.log 2>&1
expect "e4-continued" "(dumpdone 28)" out/sess-e4a.log
timeout 600 racket tests/api/session-drive.rkt \
  open:sess_e4 \
  dump-rel:path recipe \
  > out/sess-e4b.log 2>&1
expect "e4-chain-replayed" "(replayed-recipe sess_e4 " out/sess-e4b.log
expect "e4-chain-tip"      "(dumpdone 28)" out/sess-e4b.log

# --- W2 + pure-batch layer: open a COMPRESSED chain and stream into it ------
# The session's open materialises the whole chain with the live machinery
# (root + boundary + seeded replay), so a batch right after the load
# delta-routes through the replayed strata; the save is a PURE-BATCH layer
# (no new program -- recipe = one open + one batch).
rm -rf data/sess_w2 data/sess_w2.edb data/sess_pb
timeout 600 racket slog.rkt --no-banner --out-db-compressed sess_w2 --per 100 \
  tests/session/base.slog > out/sess-w2-save.log 2>&1
timeout 600 racket tests/api/session-drive.rkt \
  open:sess_w2 \
  batch+:edge,4,5 flush \
  dump-rel:path \
  save:sess_pb \
  > out/sess-w2.log 2>&1
expect "w2-route-delta" "(route delta 1)" out/sess-w2.log
expect "w2-grown"       "(dumpdone 10)" out/sess-w2.log
expect "pb-saved"       "(saved sess_pb 2)" out/sess-w2.log
timeout 600 racket tests/api/session-drive.rkt \
  open:sess_pb dump-rel:path \
  > out/sess-pb.log 2>&1
expect "pb-loaded" "(dumpdone 10)" out/sess-pb.log

# --- back-insertion into an ANCESTOR layer's pipeline (the exit criterion) --
# A batch anchored INSIDE sess_e1's replayed pipeline (position 1, edge@v0)
# DELETES the ancestor's own back-inserted (0 1): the walk re-applies the
# inherited add and the session's del at the same version -- del wins (it
# came later) -- and the suffix rebuilds to the 1..6 closure (15 paths).
# Saving and reloading preserves the layered semantics.
rm -rf data/sess_bi
timeout 600 racket tests/api/session-drive.rkt \
  open:sess_e1 \
  abatch-:1,edge,0,1 flush \
  dump-rel:path save:sess_bi \
  > out/sess-bi.log 2>&1
expect "bi-walked" "(route anchored edge 1 " out/sess-bi.log
expect "bi-tip"    "(dumpdone 15)" out/sess-bi.log
timeout 600 racket tests/api/session-drive.rkt \
  open:sess_bi dump-rel:path \
  > out/sess-bi2.log 2>&1
expect "bi-loaded" "(dumpdone 15)" out/sess-bi2.log

# --- recipe round-trip through a rename (E4) ---------------------------------
# A batch anchored pre-rename must re-anchor to the same version on load
# (ordinals resolve through severance markers and alias bindings) and
# re-apply under the alias: reach = 10+1 batch row, endp = {2..5, 91}.
rm -rf data/sess_ren
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/base.slog \
  rename-rel:path,reach \
  run:tests/session/consumer.slog \
  batch+:reach,90,91 flush \
  abatch+:1,edge,4,5 flush \
  save:sess_ren \
  dump-rel:reach dump-rel:endp \
  > out/sess-ren.log 2>&1
expect "ren-live-reach" "(dumpdone 11)" out/sess-ren.log
expect "ren-live-endp"  "(dumpdone 5)" out/sess-ren.log
timeout 600 racket tests/api/session-drive.rkt \
  open:sess_ren dump-rel:reach dump-rel:endp \
  > out/sess-ren2.log 2>&1
expect "ren-loaded-reach" "(dumpdone 11)" out/sess-ren2.log
expect "ren-loaded-endp"  "(dumpdone 5)" out/sess-ren2.log

# --- 0.E0b: anchored imports -- the walk no longer refuses across them -------
# A payload (edges 5-6, 6-7) anchored INSIDE segment 1 (position 1): the
# positional import lands in edge@v0 and the suffix walk re-runs both
# segments -- the old environment shows the payload (edge 5, path 9) and
# the tip closes over the 1..7 chain (21 paths).
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/base.slog run:tests/session/seg2.slog \
  aimport-delta:1,data/sess_cpay \
  sizes-at:2 dump-rel:path \
  > out/sess-e0b.log 2>&1
expect    "e0b-anchored"  "(import-delta-at data/sess_cpay 1)" out/sess-e0b.log
expect_re "e0b-old-env"   '\(sizes-at 2 .*\(edge 5\).*\(path 9\)' out/sess-e0b.log
expect    "e0b-tip"       "(dumpdone 21)" out/sess-e0b.log

# --- 0.E2: the unseeded-downstream rule (del edits propagate on load) --------
# The edges enter as DATA (a plain root; tests/session/edges.slog), the
# closure as a rules-only compressed layer atop it.  A del-tuple edit on
# the root: the layer's kept sample was computed for the pre-edit EDB, so
# it replays UNSEEDED -- path re-derives from the edited edge set
# ({1-2, 3-4}: 2 paths) instead of the monotone seed resurrecting the
# retracted rows.  (A del of a PROGRAM ground fact is different: replay
# re-derives it -- program-supported, the §8B.5 "retracted as input;
# remains derivable" answer -- so del edits target data-fed inputs.)
rm -rf data/sess_uns data/sess_uns_in
timeout 600 racket slog.rkt --no-banner --out-db sess_uns_in tests/session/edges.slog \
  > out/sess-uns-in.log 2>&1
timeout 600 racket slog.rkt --no-banner --out-db-compressed sess_uns --per 100 \
  -d sess_uns_in tests/session/tcrules.slog > out/sess-uns-save.log 2>&1
timeout 300 racket slog.rkt db edit sess_uns_in del-tuple edge 2 3 \
  > out/sess-uns-edit.log 2>&1
expect "uns-recorded" "recorded edit on sess_uns_in: (del-tuple edge 2 3)" out/sess-uns-edit.log
timeout 600 racket slog.rkt --no-banner --sizes -d sess_uns tests/api/noop.slog \
  > out/sess-uns.log 2>&1
expect "uns-edge-edited"    "(relation_size edge 2)" out/sess-uns.log
expect "uns-path-rederived" "(relation_size path 2)" out/sess-uns.log

# --- 0.E3: slog db freeze -- cut a chain to a standalone flat root -----------
# Freezing the edited chain materialises the post-edit fixpoint (path 2)
# with no manifest/recipe/program; the frozen copy loads as a plain root.
rm -rf data/sess_frozen
timeout 600 racket slog.rkt db freeze sess_uns --as sess_frozen \
  > out/sess-freeze.log 2>&1
expect "freeze-cut" "froze sess_uns as sess_frozen" out/sess-freeze.log
timeout 600 racket slog.rkt --no-banner --sizes -d sess_frozen tests/api/noop.slog \
  > out/sess-freeze2.log 2>&1
expect "freeze-content" "(relation_size path 2)" out/sess-freeze2.log
if [ -f data/sess_frozen/META ] && grep -q "kind flat" data/sess_frozen/META \
   && [ ! -f data/sess_frozen/prog.sexpr ] && [ ! -f data/sess_frozen/recipe ]; then
  echo "PASS freeze-flat-meta"; PASS=$((PASS+1))
else
  echo "FAIL freeze-flat-meta (expected flat META, no prog/recipe)"; FAIL=$((FAIL+1))
fi

# freezing a SESSION chain cuts its recipe history too
rm -rf data/sess_e4f
timeout 600 racket slog.rkt db freeze sess_e4 --as sess_e4f \
  > out/sess-freeze3.log 2>&1
timeout 600 racket slog.rkt --no-banner --sizes -d sess_e4f tests/api/noop.slog \
  > out/sess-freeze4.log 2>&1
expect "freeze-session-content" "(relation_size path 28)" out/sess-freeze4.log

# --- W6 round-trip: a hot-link step saved and replayed -----------------------
# A base-less session with a link: the manifest carries the link edge (for
# tree/staleness/gc) but the load must NOT open it as a base chain -- the
# recipe's own (open ...) step (absent here) names the base; the link step
# re-imports at its position during replay.
rm -rf data/sess_lnk
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/base.slog \
  link:sess_cpay \
  save:sess_lnk dump-rel:path \
  > out/sess-lnk.log 2>&1
expect "lnk-live" "(dumpdone 9)" out/sess-lnk.log
timeout 600 racket tests/api/session-drive.rkt \
  open:sess_lnk dump-rel:path \
  > out/sess-lnk2.log 2>&1
expect "lnk-loaded" "(dumpdone 9)" out/sess-lnk2.log

# --- 0.E4: the stream-equivalence fuzzer -------------------------------------
# Random base/batch splits with interleaved deletions, streamed flush by
# flush, oracle-diffed against a from-scratch run on the equivalent edited
# EDB (docs/incremental.md §10's core Phase 0 test); seed 2 also saves the
# fed session and replays it in a fresh daemon (W3/W4).
rm -rf data/sess_fuzz2
for seed in 1 2; do
  save=""
  [ "$seed" = "2" ] && save="sess_fuzz2"
  if timeout 900 racket tests/api/stream-fuzz.rkt $seed $save \
       > "out/sess-fuzz-$seed.log" 2>&1 \
     && grep -q "fuzz-ok $seed" "out/sess-fuzz-$seed.log"; then
    echo "PASS e4-fuzz-$seed"; PASS=$((PASS+1))
  else
    echo "FAIL e4-fuzz-$seed (see out/sess-fuzz-$seed.log)"; FAIL=$((FAIL+1))
  fi
done

# --- one-shot -d atop a saved session (the runslog hook) ---------------------
# `slog -d sess_e1 seg3` runs a NEW one-shot program over the replayed
# session -- the recipe chain loads through the session hook, then the
# program runs as an ordinary segment atop it.
timeout 600 racket slog.rkt --no-banner --sizes -d sess_e1 tests/api/noop.slog \
  > out/sess-dhook.log 2>&1
expect "dhook-loaded" "(relation_size path 21)" out/sess-dhook.log

# --- M0.2: the _count flavor / count round (docs/incremental.md 8B.1) --------
# TC over a graph with one redundantly-derivable edge: hand-verified
# per-tuple (input | nonrec | rec) sidecar contents after (recount) -- the
# ground facts carry the EDB input bit (8B.5), the copy rule contributes
# nonrec, and the recursive rule's single fixpoint instantiation
# contributes rec to exactly (path 1 3).  A second (recount) must
# reproduce, not double (counts are recomputable cache, 8B.2).
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/counts_tc.slog recount recount \
  dump-counts:edge dump-counts:path \
  > out/sess-counts-tc.log 2>&1
expect "cnt-edge-input"  "(countrow edge 1 2 1 0 0)" out/sess-counts-tc.log
expect "cnt-edge-count"  "(countdone edge 3)" out/sess-counts-tc.log
expect "cnt-path-copy"   "(countrow path 1 2 0 1 0)" out/sess-counts-tc.log
expect "cnt-path-copy2"  "(countrow path 2 3 0 1 0)" out/sess-counts-tc.log
expect "cnt-path-rec"    "(countrow path 1 3 0 1 1)" out/sess-counts-tc.log
expect "cnt-path-count"  "(countdone path 3)" out/sess-counts-tc.log

# The TEMP-SPLIT headline case (the 6.2 temps decision): two instantiations
# agreeing on the staged construction's only input -- a narrow residue temp
# would collapse them to one row and report (g (h 2)) at nonrec 1; the
# instantiation-injective wide temp must keep both.
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/counts_struct.slog recount \
  dump-counts:e dump-counts:h dump-counts:g \
  > out/sess-counts-st.log 2>&1
expect "cnt-e-input"     "(countrow e 2 2 1 0 0)" out/sess-counts-st.log
expect "cnt-h-two"       "(countrow h (h 2) 0 2 0)" out/sess-counts-st.log
expect "cnt-g-two"       "(countrow g (h 2) 0 2 0)" out/sess-counts-st.log

# Ground struct trees (staged replay chains + synthesized-const temps) and
# negation (absent probes over closed strata) through the count round; a
# lattice relation stays uncounted (countdone -1) until M6.
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/deep_fact.slog recount dump-counts:corners dump-counts:t \
  > out/sess-counts-tree.log 2>&1
expect "cnt-tree-corners" "(countrow corners 1 32 0 1 0)" out/sess-counts-tree.log
expect_re "cnt-tree-root" "^\\(countrow t \\(Nd .* 1 0 0\\)$" out/sess-counts-tree.log
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/neg_reach.slog recount dump-counts:reach \
  > out/sess-counts-neg.log 2>&1
expect "cnt-neg-nonrec"  "(countrow reach 1 2 0 1 0)" out/sess-counts-neg.log
expect "cnt-neg-rec"     "(countrow reach 1 6 0 0 1)" out/sess-counts-neg.log
expect "cnt-neg-count"   "(countdone reach 7)" out/sess-counts-neg.log
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/base2.slog recount dump-counts:out dump-counts:dist \
  > out/sess-counts-lat.log 2>&1
expect "cnt-lat-out"     "(countrow out (pair 1 2) 0 1 0)" out/sess-counts-lat.log
expect "cnt-lat-skip"    "(countdone dist -1)" out/sess-counts-lat.log

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
