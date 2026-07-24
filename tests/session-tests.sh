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
versioned_count_oracle() { # name session-log
  local name="$1" log="$2" prefix="out/${1}-versioned-oracle"
  grep '^[(]pipeline ' "$log" | tail -1 > "${prefix}.pipeline"
  grep '^[(]inputledger' "$log" > "${prefix}.ledger"
  local oracle_args=()
  while read -r h; do oracle_args+=("build/${h}_count.cprog"); done < <(
    grep -oE '\(s [0-9]+ [0-9]+ "[0-9a-f]{8}" \(kind semantic\)' \
      "${prefix}.pipeline" \
      | sed -E 's/.*"([0-9a-f]{8})".*/\1/' | awk '!seen[$0]++'
  )
  if racket tests/api/count-ir-oracle.rkt --versioned \
       "${prefix}.pipeline" "${prefix}.ledger" "${oracle_args[@]}" \
       > "${prefix}.expected" 2> "${prefix}.err" \
     && grep -E '^\(vcountrow ' "$log" | sort -u > "${prefix}.actual" \
     && sort -u "${prefix}.expected" > "${prefix}.expected.sorted" \
     && diff "${prefix}.actual" "${prefix}.expected.sorted" \
          > "${prefix}.diff"; then
    echo "PASS $name"; PASS=$((PASS+1))
  else
    echo "FAIL $name (see ${prefix}.{diff,err})"; FAIL=$((FAIL+1))
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
timeout 600 racket compiler/run.rkt --no-banner --out-db sess_b0a tests/session/base.slog \
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
timeout 600 racket compiler/run.rkt --no-banner --out-db sess_b0b tests/session/base2.slog \
  > out/sess-b0b-base.log 2>&1
timeout 600 racket tests/api/session-drive.rkt \
  open:sess_b0b run:tests/session/seg2b.slog \
  pipeline sizes-at:0 write-csv:out/sess-b0-session-csv \
  > out/sess-b0b.log 2>&1
expect "b0-pair-chain"  "(rel pair (v 0 0 2) (v 1 1 3))" out/sess-b0b.log
expect "b0-out-chain"   "(rel out (v 0 0 2) (v 1 1 3))" out/sess-b0b.log
expect "b0-dist-chain"  "(rel dist (v 0 0 3) (v 1 1 3))" out/sess-b0b.log
expect "b0-lat-base"    "(dist 3)" out/sess-b0b.log

timeout 600 racket compiler/run.rkt --no-banner --debug-dir out/sess-b0-oracle-csv \
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
  run:tests/session/base_input.slog \
  batch+:edge,1,2 batch+:edge,2,3 batch+:edge,3,4 flush \
  del-tuple:edge,2,3 rerun:edge \
  dump-rel:path \
  > out/sess-b2d.log 2>&1
expect "b2-deleted"    "(overlay-set edge 1)" out/sess-b2d.log
expect "b2-del-cone"   "(rerun edge 1 " out/sess-b2d.log
expect "b2-path-minus" "(dumpdone 2)" out/sess-b2d.log

# Negation cone (the reserved "~ + increments" case, 0.A8): unreached =
# nodes NOT path-reachable from 1.  A monotone ADD shrinks it (3 -> 2), a
# deletion grows it (2 -> 4); both route through clear-and-rerun (the cone
# holds a neg edge), and each re-run recomputes the complement exactly.
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/negsess_input.slog \
  batch+:edge,1,2 batch+:edge,2,3 flush \
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
  run:tests/session/base2_input.slog \
  batch+:in,1,2 batch+:in,3,4 flush \
  del-tuple:in,3,4 rerun:in \
  dump-rel:out dump-rel:pair sizes-at:99 \
  > out/sess-b2s.log 2>&1
expect "b2-struct-cone" "(rerun in 1 " out/sess-b2s.log
expect "b2-out-minus"   "(dumpdone 1)" out/sess-b2s.log
expect "b2-out-content" "(dumprow (pair 1 2))" out/sess-b2s.log
expect "b2-dist-kept"   "(dist 3)" out/sess-b2s.log

# --- B4+B5: the routing rule (compiler/session.rkt flush) -------------------
# Queued signed batches route per §0.5/M1: certified positive plain-table
# cones use support maintenance; a same-point add/delete pair
# collapses to an empty flush ("(flush 0)", content untouched); since M4T a
# deletion into this recursive cone takes the DRed sweep rather than
# clear-and-rerun (docs/m4t-contract.md).
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/base_input.slog \
  batch+:edge,1,2 batch+:edge,2,3 batch+:edge,3,4 flush \
  batch+:edge,4,5 flush dump-rel:path \
  batch+:edge,7,8 batch-:edge,7,8 flush dump-rel:edge \
  batch-:edge,1,2 flush dump-rel:path \
  > out/sess-b4.log 2>&1
expect "b4-route-delta"   "(route maintain 1)" out/sess-b4.log
expect "b4-add-applied"   "(dumpdone 10)" out/sess-b4.log
expect "b4-collapse"      "(flush 0)" out/sess-b4.log
expect "b4-collapse-kept" "(dumpdone 4)" out/sess-b4.log
expect "b4-route-sweep"   "(route maintain-recursive-negative 1)" out/sess-b4.log
expect "b4-del-settled"   "(update-committed 3 counts-valid)" out/sess-b4.log
expect "b4-del-applied"   "(dumpdone 6)" out/sess-b4.log

# The reserved "~ + increments" case (0.A8), precise since M4N slice 3: a
# monotone ADD into the recursive producer finalizes path, then the
# acyclic reader repairs from path's MAINTAINED journal (the gained rows
# drive the reader's negative phase as anti-deltas).
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/negsess.slog \
  batch+:edge,3,4 flush dump-rel:unreached \
  > out/sess-b4n.log 2>&1
expect "b4-neg-producers" "(route maintain-producers-positive 1)" out/sess-b4n.log
expect "b4-neg-readers" "(route maintain-negated-derived-negative 1 1)" out/sess-b4n.log
expect_not "b4-neg-no-rerun" "(route rerun" out/sess-b4n.log
expect "b4-neg-result" "(dumpdone 2)" out/sess-b4n.log

# a MULTI-stratum monotone cone chains update-local presence transitions
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/twohop.slog \
  batch+:edge,3,4 flush dump-rel:endpoint \
  > out/sess-b4m.log 2>&1
expect "b4-multihop-replay" "(route maintain 2)" out/sess-b4m.log
expect "b4-multihop-result" "(dumpdone 3)" out/sess-b4m.log

# --- B5 repeated delta-entry + B6 exact-once staging ------------------------
# Three consecutive maintained flushes extend the chain 1..4 to 1..7; live
# indices and support sidecars survive each update and the closure
# must be exact: C(7,2) = 21 paths.
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/base.slog \
  batch+:edge,4,5 flush \
  batch+:edge,5,6 flush \
  batch+:edge,6,7 flush \
  dump-rel:path write-csv:out/sess-b5-csv \
  dump-counts:path recount-force dump-counts:path \
  > out/sess-b5.log 2>&1
expect "b5-repeat-delta" "(route maintain 1)" out/sess-b5.log
if [ "$(grep -cF '(route maintain 1)' out/sess-b5.log)" = "3" ]; then
  echo "PASS b5-all-three-delta"; PASS=$((PASS+1))
else
  echo "FAIL b5-all-three-delta (expected 3 delta routes)"; FAIL=$((FAIL+1))
fi
expect "b5-closure-exact" "(dumpdone 21)" out/sess-b5.log
if [ "$(grep -cF '(countrow path 1 7 0 0 1)' out/sess-b5.log)" = "2" ]; then
  echo "PASS b5-repeated-support-counts"; PASS=$((PASS+1))
else
  echo "FAIL b5-repeated-support-counts (maintained count differs from recount)"; FAIL=$((FAIL+1))
fi

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
expect    "c-anchored-route" "(route anchored edge 1 4)" out/sess-c-add.log
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
  run:tests/session/base_input.slog \
  batch+:edge,1,2 batch+:edge,2,3 batch+:edge,3,4 flush \
  run:tests/session/seg2.slog \
  abatch-:1,edge,2,3 flush \
  sizes-at:2 dump-rel:path \
  > out/sess-c-del.log 2>&1
expect    "c-adel-applied" "(overlay-set edge 1)" out/sess-c-del.log
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
expect "c-recipe-run"     '(run "tests/session/base.slog" (version-events' out/sess-c-reapply.log
expect "c-recipe-tipb"    "(v 1) ((direct (5 6)))" out/sess-c-reapply.log
expect "c-recipe-anchb"   "(v 0) ((direct (0 1)))" out/sess-c-reapply.log

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
timeout 600 racket compiler/run.rkt --no-banner --out-db sess_cpay tests/session/payload.slog \
  > out/sess-cpay.log 2>&1
timeout 600 racket compiler/run.rkt --no-banner --out-db sess_cpay2 tests/session/payload2.slog \
  > out/sess-cpay2.log 2>&1
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/base.slog \
  import-delta:data/sess_cpay \
  dump-rel:path recount pipeline input-ledger dump-all-counts \
  > out/sess-c-imp.log 2>&1
expect "c-import-cone"   "(import-delta data/sess_cpay 1)" out/sess-c-imp.log
expect "c-import-result" "(dumpdone 9)" out/sess-c-imp.log
versioned_count_oracle "m04-import-ir-oracle" out/sess-c-imp.log
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
  dump-rel:reach dump-rel:endp recount pipeline input-ledger dump-all-counts recipe \
  > out/sess-d-rename.log 2>&1
expect "d-renamed"        "(renamed path reach 1)" out/sess-d-rename.log
expect "d-endp-initial"   "(dumpdone 3)" out/sess-d-rename.log
expect "d-walk-translates" "(route anchored edge 1 3)" out/sess-d-rename.log
expect "d-alias-reapply"  "(overlay-set reach 1)" out/sess-d-rename.log
expect "d-reach-final"    "(dumpdone 11)" out/sess-d-rename.log
expect "d-endp-final"     "(dumpdone 5)" out/sess-d-rename.log
expect "d-recipe-rename"  "(rename-rel path reach)" out/sess-d-rename.log
versioned_count_oracle "m04-rename-ir-oracle" out/sess-d-rename.log

# drop + re-declare: the dropped lineage stays positionally addressable
# (path 6 at position 2); the re-declaration is a severed fresh chain
# (1 row); (schema) reflects the current environment
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/base.slog \
  drop-rel:path \
  run:tests/session/redecl.slog \
  sizes-at:2 dump-rel:path recount pipeline input-ledger dump-all-counts \
  > out/sess-d-drop.log 2>&1
expect    "d-dropped"     "(dropped path 1)" out/sess-d-drop.log
expect_re "d-old-lineage" '\(sizes-at 2 .*\(path 6\)' out/sess-d-drop.log
expect    "d-fresh-chain" "(dumpdone 1)" out/sess-d-drop.log
versioned_count_oracle "m04-drop-redeclare-ir-oracle" out/sess-d-drop.log

# hot-link (D5): same merge machinery as import-delta, recorded as a LINK
# step (payload stays a reference; externalisation leaves it alone)
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/base.slog \
  link:sess_cpay \
  dump-rel:path recount pipeline input-ledger dump-all-counts recipe \
  > out/sess-d-link.log 2>&1
expect "d-link-cone"   "(import-delta data/sess_cpay 1)" out/sess-d-link.log
expect "d-link-result" "(dumpdone 9)" out/sess-d-link.log
expect "d-link-recipe" '(link "sess_cpay" ())' out/sess-d-link.log
versioned_count_oracle "m04-link-ir-oracle" out/sess-d-link.log

# D3: rename as an EDIT on a stored database -- one implementation with
# the batch edits (the op IS the action spec, streamed on load)
rm -rf data/sess_dedit
timeout 600 racket compiler/run.rkt --no-banner --out-db sess_dedit tests/session/base.slog \
  > out/sess-d-edit0.log 2>&1
timeout 300 racket compiler/run.rkt db edit sess_dedit rename-rel path reach \
  > out/sess-d-edit1.log 2>&1
expect "d-edit-recorded" "recorded edit on sess_dedit: (rename-rel path reach)" out/sess-d-edit1.log
timeout 600 racket compiler/run.rkt --no-banner --sizes -d sess_dedit tests/api/noop.slog \
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
timeout 600 racket compiler/run.rkt --no-banner --out-db-compressed sess_w2 --per 100 \
  tests/session/base.slog > out/sess-w2-save.log 2>&1
timeout 600 racket tests/api/session-drive.rkt \
  open:sess_w2 \
  batch+:edge,4,5 flush \
  dump-rel:path \
  save:sess_pb \
  > out/sess-w2.log 2>&1
expect "w2-route-delta" "(route maintain 1)" out/sess-w2.log
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
  recount pipeline input-ledger dump-all-counts \
  > out/sess-ren2.log 2>&1
expect "ren-loaded-reach" "(dumpdone 11)" out/sess-ren2.log
expect "ren-loaded-endp"  "(dumpdone 5)" out/sess-ren2.log
versioned_count_oracle "m04-rename-load-oracle" out/sess-ren2.log

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
timeout 600 racket compiler/run.rkt --no-banner --out-db sess_uns_in tests/session/edges.slog \
  > out/sess-uns-in.log 2>&1
timeout 600 racket compiler/run.rkt --no-banner --out-db-compressed sess_uns --per 100 \
  -d sess_uns_in tests/session/tcrules.slog > out/sess-uns-save.log 2>&1
timeout 300 racket compiler/run.rkt db edit sess_uns_in del-tuple edge 2 3 \
  > out/sess-uns-edit.log 2>&1
expect "uns-recorded" "recorded edit on sess_uns_in: (del-tuple edge 2 3)" out/sess-uns-edit.log
timeout 600 racket compiler/run.rkt --no-banner --sizes -d sess_uns tests/api/noop.slog \
  > out/sess-uns.log 2>&1
expect "uns-edge-edited"    "(relation_size edge 2)" out/sess-uns.log
expect "uns-path-rederived" "(relation_size path 2)" out/sess-uns.log

# --- 0.E3: slog db freeze -- cut a chain to a standalone flat root -----------
# Freezing the edited chain materialises the post-edit fixpoint (path 2)
# with no manifest/recipe/program; the frozen copy loads as a plain root.
rm -rf data/sess_frozen
timeout 600 racket compiler/run.rkt db freeze sess_uns --as sess_frozen \
  > out/sess-freeze.log 2>&1
expect "freeze-cut" "froze sess_uns as sess_frozen" out/sess-freeze.log
timeout 600 racket compiler/run.rkt --no-banner --sizes -d sess_frozen tests/api/noop.slog \
  > out/sess-freeze2.log 2>&1
expect "freeze-content" "(relation_size path 2)" out/sess-freeze2.log
timeout 600 racket tests/api/session-drive.rkt \
  open:sess_frozen recount pipeline input-ledger dump-all-counts \
  > out/sess-freeze-counts.log 2>&1
versioned_count_oracle "m04-freeze-root-oracle" out/sess-freeze-counts.log
if [ -f data/sess_frozen/META ] && grep -q "kind flat" data/sess_frozen/META \
   && [ ! -f data/sess_frozen/prog.sexpr ] && [ ! -f data/sess_frozen/recipe ]; then
  echo "PASS freeze-flat-meta"; PASS=$((PASS+1))
else
  echo "FAIL freeze-flat-meta (expected flat META, no prog/recipe)"; FAIL=$((FAIL+1))
fi

# freezing a SESSION chain cuts its recipe history too
rm -rf data/sess_e4f
timeout 600 racket compiler/run.rkt db freeze sess_e4 --as sess_e4f \
  > out/sess-freeze3.log 2>&1
timeout 600 racket compiler/run.rkt --no-banner --sizes -d sess_e4f tests/api/noop.slog \
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
  open:sess_lnk dump-rel:path recount pipeline input-ledger dump-all-counts \
  > out/sess-lnk2.log 2>&1
expect "lnk-loaded" "(dumpdone 9)" out/sess-lnk2.log
versioned_count_oracle "m04-link-load-oracle" out/sess-lnk2.log

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
timeout 600 racket compiler/run.rkt --no-banner --sizes -d sess_e1 tests/api/noop.slog \
  > out/sess-dhook.log 2>&1
expect "dhook-loaded" "(relation_size path 21)" out/sess-dhook.log

# --- M0.2: the _count flavor / count round (docs/incremental.md 8B.1) --------
# TC over a graph with one redundantly-derivable edge: hand-verified
# per-tuple (input | nonrec | rec) sidecar contents after (recount) -- the
# ground facts are nonrecursive PROGRAM support (not API-editable input), the
# copy rule contributes nonrec, and the recursive rule's single fixpoint instantiation
# contributes rec to exactly (path 1 3).  A second (recount) must
# reproduce, not double (counts are recomputable cache, 8B.2).
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/counts_tc.slog recount recount \
  dump-counts:edge dump-counts:path \
  > out/sess-counts-tc.log 2>&1
expect "cnt-edge-fact"   "(countrow edge 1 2 0 1 0)" out/sess-counts-tc.log
expect "cnt-edge-count"  "(countdone edge 3)" out/sess-counts-tc.log
expect "cnt-path-copy"   "(countrow path 1 2 0 1 0)" out/sess-counts-tc.log
expect "cnt-path-copy2"  "(countrow path 2 3 0 1 0)" out/sess-counts-tc.log
expect "cnt-path-rec"    "(countrow path 1 3 0 1 1)" out/sess-counts-tc.log
expect "cnt-path-count"  "(countdone path 3)" out/sess-counts-tc.log

# M0.4d's independent oracle: interpret the canonical count IR in Racket over
# a from-scratch least fixpoint, then diff every edge/path support word with
# the daemon sidecars.  The interpreter shares no runtime count machinery.
oracle_args=()
while read -r h; do oracle_args+=("build/${h}_count.cprog"); done < <(
  grep -oE '\(s [0-9]+ [0-9]+ "[0-9a-f]{8}"' out/sess-counts-tc.log \
    | sed -E 's/.*"([0-9a-f]{8})"/\1/' | awk '!seen[$0]++'
)
if racket tests/api/count-ir-oracle.rkt "${oracle_args[@]}" \
     > out/sess-counts-oracle.log 2>&1 \
   && grep -E '^\(countrow (edge|path) ' out/sess-counts-tc.log | sort -u \
        > out/sess-counts-runtime.sorted \
   && sort -u out/sess-counts-oracle.log > out/sess-counts-oracle.sorted \
   && diff out/sess-counts-runtime.sorted out/sess-counts-oracle.sorted \
        > out/sess-counts-oracle.diff; then
  echo "PASS m04-count-ir-oracle"; PASS=$((PASS+1))
else
  echo "FAIL m04-count-ir-oracle (see out/sess-counts-oracle.diff/.log)"; FAIL=$((FAIL+1))
fi

# The TEMP-SPLIT headline case (the 6.2 temps decision): two instantiations
# agreeing on the staged construction's only input -- a narrow residue temp
# would collapse them to one row and report (g (h 2)) at nonrec 1; the
# instantiation-injective wide temp must keep both.
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/counts_struct.slog recount \
  dump-counts:e dump-counts:h dump-counts:g \
  > out/sess-counts-st.log 2>&1
expect "cnt-e-fact"      "(countrow e 2 2 0 1 0)" out/sess-counts-st.log
expect "cnt-h-two"       "(countrow h (h 2) 0 2 0)" out/sess-counts-st.log
expect "cnt-g-two"       "(countrow g (h 2) 0 2 0)" out/sess-counts-st.log

# Ground struct trees (staged replay chains + synthesized-const temps) and
# negation (absent probes over closed strata) through the count round; a
# lattice relation stays outside the legacy count walk (countdone -1); M6L
# establishes contributor state only when the leaf-maintenance route asks.
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/deep_fact.slog recount dump-counts:corners dump-counts:t \
  > out/sess-counts-tree.log 2>&1
expect "cnt-tree-corners" "(countrow corners 1 32 0 1 0)" out/sess-counts-tree.log
expect_re "cnt-tree-root" "^\\(countrow t \\(Nd .* 0 1 0\\)$" out/sess-counts-tree.log
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/neg_reach.slog recount dump-counts:reach \
  pipeline input-ledger dump-all-counts \
  > out/sess-counts-neg.log 2>&1
expect "cnt-neg-nonrec"  "(countrow reach 1 2 0 1 0)" out/sess-counts-neg.log
expect "cnt-neg-rec"     "(countrow reach 1 6 0 0 1)" out/sess-counts-neg.log
expect "cnt-neg-count"   "(countdone reach 7)" out/sess-counts-neg.log
versioned_count_oracle "m04-negation-ir-oracle" out/sess-counts-neg.log
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/base2.slog recount dump-counts:out dump-counts:dist \
  count-capabilities pipeline input-ledger dump-all-counts \
  > out/sess-counts-lat.log 2>&1
expect "cnt-lat-out"     "(countrow out (pair 1 2) 0 1 0)" out/sess-counts-lat.log
expect "cnt-lat-skip"    "(countdone dist -1)" out/sess-counts-lat.log
expect_re "m04-cap-lattice" '\(cap dist 0 [0-9]+ \(recount yes\) \(precise-delete conditional\) \(fallback clear-rerun\) \(reason lattice-contributor-recount\)\)' out/sess-counts-lat.log
versioned_count_oracle "m04-lattice-boundary-oracle" out/sess-counts-lat.log

# --- M0.3: counted state, laziness, invalidation, positional/cone walks ------
# (docs/incremental.md 8B.2)  A walk marks `counted` per (relation,
# version); a second recount is fully lazy (runs 0 of 2); a delta-entry
# flush INVALIDATES the touched cone (kind-less batches at finalize), and
# the healed counts see the new edge's derivations -- path (1 4) has TWO
# rec derivations through edge (3 4).
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/counts_tc.slog recount count-state recount \
  batch+:edge,3,4 flush recount dump-counts:path \
  > out/sess-counts-m03a.log 2>&1
expect "m03-counted"   "(cnt edge 0 1)" out/sess-counts-m03a.log
expect "m03-lazy"      "(recount 0 2 2)" out/sess-counts-m03a.log
expect "m03-heal-new"  "(countrow path 1 4 0 0 2)" out/sess-counts-m03a.log
expect "m03-heal-old"  "(countrow path 1 3 0 1 1)" out/sess-counts-m03a.log

# Per-version walks: seg1's strata re-pushed under bind-at 2 count the OLD
# versions (single rule copies -> 1s); the tip walk then counts the new
# versions under BOTH segments' rule copies (2s: duplicate rules each
# contribute a derivation), and the old versions' counted state SURVIVES
# the tip walk's close.
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/base.slog run:tests/session/seg2.slog \
  recount-at:2 dump-counts:path,2 recount dump-counts:path count-state \
  pipeline input-ledger dump-all-counts \
  > out/sess-counts-m03b.log 2>&1
expect "m03-old-copy"  "(countrow path 1 2 0 1 0)" out/sess-counts-m03b.log
expect "m03-old-rec"   "(countrow path 1 4 0 0 1)" out/sess-counts-m03b.log
expect "m03-old-done"  "(countdone path 6)" out/sess-counts-m03b.log
expect "m03-tip-copy"  "(countrow path 1 2 0 2 0)" out/sess-counts-m03b.log
expect "m03-tip-rec"   "(countrow path 1 5 0 0 1)" out/sess-counts-m03b.log
expect "m03-tip-done"  "(countdone path 10)" out/sess-counts-m03b.log
expect "m03-both-vers" "(cnt path 0 1) (cnt path 1 1)" out/sess-counts-m03b.log
versioned_count_oracle "m04-version-barrier-oracle" out/sess-counts-m03b.log

# Correctness-first relation recount currently closes the whole VersionId
# prefix transactionally; partial cones return only after writer closure is
# represented over exact VersionIds.
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/session/counts_struct.slog recount:g dump-counts:g dump-counts:e \
  count-capabilities pipeline input-ledger dump-all-counts \
  > out/sess-counts-m03c.log 2>&1
expect "m03-cone-ran"  "(recount 2 0 2 rel=g)" out/sess-counts-m03c.log
expect "m03-cone-g"    "(countrow g (h 2) 0 2 0)" out/sess-counts-m03c.log
expect "m03-cone-e"    "(countrow e 2 2 0 1 0)" out/sess-counts-m03c.log
expect_re "m04-cap-struct" '\(cap h 0 [0-9]+ \(recount yes\) \(precise-delete conditional\) \(fallback clear-rerun\) \(reason struct-recount\)\)' out/sess-counts-m03c.log
versioned_count_oracle "m04-struct-ir-oracle" out/sess-counts-m03c.log

# --- M0.4: stable instances, input overlays, transactional recount ---------
# Program facts are not editable input. Injection creates a distinct input-
# only successor slot; edits then target that slot. A following explicit
# rules-only program event consumes the new slot and creates its own downstream
# output version--injection never silently retargets the historical writer.
# Deleting inherited data installs a mask, while a fresh assertion is direct
# input support.
rm -rf data/sess_m04
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/counts_tc.slog \
  inject-version:edge,m04-edge \
  batch+:edge,2,3 batch-:edge,1,2 batch+:edge,4,5 flush \
  run:tests/session/tcrules.slog \
  pipeline count-capabilities dump-rel:edge dump-rel:path \
  recount dump-counts:edge dump-counts:path \
  pipeline input-ledger dump-all-counts \
  save:sess_m04 recipe \
  > out/sess-m04.log 2>&1
expect_re "m04-two-versions" '\(rel edge \(v 0 [0-9]+ 3\) \(v 1 [0-9]+ 3\)\)' out/sess-m04.log
expect_re "m04-downstream-version" '\(rel path \(v 0 [0-9]+ 3\) \(v 1 [0-9]+ [0-9]+\)\)' out/sess-m04.log
expect_re "m04-read-map" '\(kind semantic\) \(reads \(edge [0-9]+\) \(path [0-9]+\)\)' out/sess-m04.log
expect "m04-stable-key"  '"m04-edge" (schema 2 0 set)' out/sess-m04.log
expect_re "m04-cap-table" '\(cap edge 1 [0-9]+ \(recount yes\) \(precise-delete conditional\) \(fallback clear-rerun\) \(reason table-recount\)\)' out/sess-m04.log
expect "m04-input-count" "(countrow edge 4 5 1 0 0)" out/sess-m04.log
expect "m04-inherit-count" "(countrow edge 2 3 0 1 0)" out/sess-m04.log
expect_not "m04-mask-absent" "(countrow edge 1 2" out/sess-m04.log
expect "m04-reopened-derivation" "(countrow path 4 5 0 1 0)" out/sess-m04.log
expect "m04-overlay-recipe" '(overlay edge (key "m04-edge") (v 1) ((direct (4 5)) (mask (1 2))))' out/sess-m04.log
versioned_count_oracle "m04-injected-version-oracle" out/sess-m04.log
expect "m04-meta-format" "(version-format 1)" data/sess_m04/META
expect "m04-meta-schema" "(schema (2 0 set))" data/sess_m04/META

# Replay resolves the VersionKey first (the ordinal is diagnostic fallback),
# reproduces direct/mask state, and recounts the same foundations.
timeout 900 racket tests/api/session-drive.rkt \
  open:sess_m04 dump-rel:edge dump-rel:path recount \
  dump-counts:edge dump-counts:path pipeline \
  input-ledger dump-all-counts \
  > out/sess-m04-load.log 2>&1
expect "m04-load-size" "(dumpdone 3)" out/sess-m04-load.log
expect "m04-load-key" '"m04-edge" (schema 2 0 set)' out/sess-m04-load.log
expect "m04-load-input" "(countrow edge 4 5 1 0 0)" out/sess-m04-load.log
expect_not "m04-load-mask" "(countrow edge 1 2" out/sess-m04-load.log
expect "m04-load-derivation" "(countrow path 4 5 0 1 0)" out/sess-m04-load.log
versioned_count_oracle "m04-load-version-oracle" out/sess-m04-load.log

# A failed recount publishes nothing, leaves the semantic pipeline at the same
# position, and a forced retry succeeds from fresh scratch sidecars.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/counts_tc.slog recount dump-counts:path \
  recount-fail:1 dump-counts:path recount-force dump-counts:path pipeline \
  > out/sess-m04-txn.log 2>&1
expect "m04-txn-abort" "(count-epoch-aborted)" out/sess-m04-txn.log
expect "m04-txn-failure" "(recount-failed 1" out/sess-m04-txn.log
expect "m04-txn-retry" "(count-epoch-committed)" out/sess-m04-txn.log
expect "m04-txn-position" "(pipeline (pos 3)" out/sess-m04-txn.log
if [ "$(grep -cF '(countrow path 1 3 0 1 1)' out/sess-m04-txn.log)" -eq 3 ]; then
  echo "PASS m04-txn-preserved"; PASS=$((PASS+1))
else
  echo "FAIL m04-txn-preserved (committed counts changed across abort/retry)"; FAIL=$((FAIL+1))
fi

# Writer coverage is structural, not inferred from tuple presence: omitting a
# semantic writer makes commit fail even when another support keeps every live
# tuple positive, and the last committed map remains readable.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/counts_tc.slog recount recount-omit:1 dump-counts:path \
  > out/sess-m04-writers.log 2>&1
expect "m04-writer-audit" "semantic writer coverage mismatch" out/sess-m04-writers.log
expect "m04-writer-abort" "(count-epoch-aborted)" out/sess-m04-writers.log
expect "m04-writer-preserved" "(countrow path 1 3 0 1 1)" out/sess-m04-writers.log

# A test-width ceiling forces the production overflow invalidation path.  The
# scratch epoch aborts, the last committed nonrec=2 word remains visible, and
# restoring the full-width ceiling permits a clean retry without changing set
# content.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/counts_struct.slog recount dump-counts:h \
  count-test-max:1 recount-try dump-counts:h dump-rel:g \
  count-test-max:4294967295 recount-force dump-counts:h \
  > out/sess-m04-overflow.log 2>&1
expect "m04-overflow-invalid" "count arithmetic overflow/underflow or kind mismatch" out/sess-m04-overflow.log
expect "m04-overflow-abort" "(count-epoch-aborted)" out/sess-m04-overflow.log
if [ "$(grep -cF '(countrow h (h 2) 0 2 0)' out/sess-m04-overflow.log)" -eq 3 ]; then
  echo "PASS m04-overflow-preserved"; PASS=$((PASS+1))
else
  echo "FAIL m04-overflow-preserved (committed count changed across overflow/retry)"; FAIL=$((FAIL+1))
fi
expect "m04-overflow-content" "(dumpdone 1)" out/sess-m04-overflow.log

# --- M1: positive signed maintenance --------------------------------------
# Multiple strata consume an update-local transition journal; maintained
# support counts must equal an independent forced recount at revision 1.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/twohop.slog batch+:edge,3,4 flush \
  dump-counts:path dump-counts:endpoint count-state \
  recount-force dump-counts:path dump-counts:endpoint \
  > out/sess-m1-multistratum.log 2>&1
expect "m1-route" "(route maintain 2)" out/sess-m1-multistratum.log
expect "m1-revision" "(update-committed 1 counts-valid)" out/sess-m1-multistratum.log
expect "m1-count-revision" "(rev path 0 1)" out/sess-m1-multistratum.log
if [ "$(grep -cF '(countrow path 1 4 0 0 1)' out/sess-m1-multistratum.log)" -eq 2 ] \
   && [ "$(grep -cF '(countrow endpoint 4 0 3 0)' out/sess-m1-multistratum.log)" -eq 2 ]; then
  echo "PASS m1-maintained-equals-recount"; PASS=$((PASS+1))
else
  echo "FAIL m1-maintained-equals-recount"; FAIL=$((FAIL+1))
fi

# Simultaneous deltas in two body relations plus two occurrences of the same
# relation: every newly enabled pair appears once and downstream multiplicity
# is preserved (hit(1) and hit(2) each have two supports).
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m1_occurrence.slog \
  batch+:a,2 batch+:b,2 flush \
  dump-rel:selfp dump-rel:cross dump-counts:hit recount-force dump-counts:hit \
  > out/sess-m1-occurrence.log 2>&1
expect "m1-occ-route" "(route maintain 2)" out/sess-m1-occurrence.log
expect "m1-self-count" "(dumpdone 4)" out/sess-m1-occurrence.log
expect "m1-cross-count" "(dumpdone 4)" out/sess-m1-occurrence.log
if [ "$(grep -cF '(countrow hit 1 0 2 0)' out/sess-m1-occurrence.log)" -eq 2 ] \
   && [ "$(grep -cF '(countrow hit 2 0 2 0)' out/sess-m1-occurrence.log)" -eq 2 ]; then
  echo "PASS m1-occurrence-counts"; PASS=$((PASS+1))
else
  echo "FAIL m1-occurrence-counts"; FAIL=$((FAIL+1))
fi

# Adding direct support to a row already live by derivation is support-only:
# set the input bit, but do not manufacture a 0->1 premise transition.  The
# recursive path relation remains three rows and its complete support word
# agrees with recount.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/counts_tc.slog batch+:path,1,3 flush \
  dump-rel:path dump-counts:path recount-force dump-counts:path \
  > out/sess-m1-support-only.log 2>&1
expect "m1-support-only-route" "(route maintain 1)" out/sess-m1-support-only.log
expect "m1-support-only-content" "(dumpdone 3)" out/sess-m1-support-only.log
if [ "$(grep -cF '(countrow path 1 3 1 1 1)' out/sess-m1-support-only.log)" -eq 2 ]; then
  echo "PASS m1-support-only-counts"; PASS=$((PASS+1))
else
  echo "FAIL m1-support-only-counts"; FAIL=$((FAIL+1))
fi

# Count establishment itself is an optimization gate.  If a test-width limit
# makes the private recount epoch fail before mutation, the update remains
# usable, takes the legacy set route, commits one revision, and produces the
# correct closure.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/counts_tc.slog count-test-max:0 \
  batch+:edge,3,4 flush update-epoch dump-rel:path \
  > out/sess-m1-establish-fallback.log 2>&1
expect "m1-establish-refused" "(maintenance-unavailable recount" out/sess-m1-establish-fallback.log
expect "m1-establish-route" "(route delta 1)" out/sess-m1-establish-fallback.log
expect "m1-establish-revision" "(update-epoch 1 settled)" out/sess-m1-establish-fallback.log
expect "m1-establish-content" "(dumpdone 6)" out/sess-m1-establish-fallback.log

# Optimistic revision checks reject stale writers.  Signed underflow takes the
# same recoverable invalidation path as maintenance overflow: set content stays
# intact, counts become unestablished, and a recount heals them.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/counts_tc.slog recount \
  begin-update:0 signed-underflow commit-update begin-update:0 update-epoch \
  dump-rel:path count-state recount-force dump-counts:path \
  > out/sess-m1-revision-failure.log 2>&1
expect "m1-underflow-recovered" "(signed-underflow-recovered)" out/sess-m1-revision-failure.log
expect "m1-underflow-invalidates" "(update-committed 1 counts-invalid)" out/sess-m1-revision-failure.log
expect "m1-stale-refused" "stale expected revision 0; current revision is 1" out/sess-m1-revision-failure.log
expect "m1-failure-content" "(dumpdone 3)" out/sess-m1-revision-failure.log
expect "m1-failure-healed" "(countrow path 1 3 0 1 1)" out/sess-m1-revision-failure.log

timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/counts_tc.slog recount count-test-max:1 \
  batch+:edge,3,4 flush dump-rel:path count-state \
  count-test-max:4294967295 recount-force dump-counts:path \
  > out/sess-m1-overflow.log 2>&1
expect "m1-overflow-fallback" "(update-committed 1 counts-invalid)" out/sess-m1-overflow.log
expect "m1-overflow-content" "(dumpdone 6)" out/sess-m1-overflow.log
expect "m1-overflow-healed" "(countrow path 1 4 0 0 2)" out/sess-m1-overflow.log

# Plain injection remains input-only.  The explicit inject-and-reopen API
# applies that input without retargeting historical writers, then creates
# stable inherited output slots and new semantic writer maps.
rm -rf data/sess_m1_reopen
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/counts_tc.slog \
  inject-reopen:edge,m1-reopen,tests/session/tcrules.slog,4,5 \
  dump-rel:edge dump-rel:path \
  batch+:edge,5,6 flush dump-rel:path dump-counts:path \
  recount-force dump-counts:path pipeline save:sess_m1_reopen \
  > out/sess-m1-reopen.log 2>&1
expect "m1-reopen-input-only" "(route anchored edge 3 0)" out/sess-m1-reopen.log
expect "m1-reopen-revisions" "(update-committed 2 counts-valid)" out/sess-m1-reopen.log
expect "m1-reopen-content" "(dumpdone 4)" out/sess-m1-reopen.log
expect "m1-reopen-maintained" "(route maintain 1)" out/sess-m1-reopen.log
expect "m1-reopen-grown" "(dumpdone 6)" out/sess-m1-reopen.log
if [ "$(grep -cF '(countrow path 4 6 0 0 1)' out/sess-m1-reopen.log)" -eq 2 ]; then
  echo "PASS m1-reopen-counts"; PASS=$((PASS+1))
else
  echo "FAIL m1-reopen-counts"; FAIL=$((FAIL+1))
fi
expect_re "m1-reopen-writer-map" '\(kind semantic\) \(reads \(edge [0-9]+\) \(path [0-9]+\)\) \(write-map \(path [0-9]+\)\)' out/sess-m1-reopen.log
expect "m1-reopen-input-policy" "(kind input-injection-inherit)" data/sess_m1_reopen/META
expect "m1-reopen-output-policy" "(kind program-inherit)" data/sess_m1_reopen/META

# Counts are cache only, so replay the saved explicit topology event in a
# fresh EvaluationId and independently reconstruct every VersionId's support.
timeout 900 racket tests/api/session-drive.rkt \
  open:sess_m1_reopen dump-rel:path recount pipeline input-ledger dump-all-counts \
  > out/sess-m1-reopen-load.log 2>&1
expect "m1-reopen-load-content" "(dumpdone 6)" out/sess-m1-reopen-load.log
expect "m1-reopen-load-key" '"m1-reopen" (schema 2 0 set)' out/sess-m1-reopen-load.log
versioned_count_oracle "m1-reopen-load-oracle" out/sess-m1-reopen-load.log

# --- M3: acyclic signed deletion -------------------------------------------
# Shared support, a repeated body occurrence, and a downstream stratum use the
# negative exact partition.  First -a(1) is support-only for p(1) because b(1)
# remains, but removes the three pair rows involving 1.  The next mixed flush
# removes b(1), adds a(3), and must settle as one revision after - then +.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m3_acyclic.slog \
  batch+:a,1 batch+:a,2 batch+:b,1 flush \
  batch-:a,1 flush \
  dump-rel:p dump-rel:q dump-rel:pair dump-counts:p dump-counts:pair \
  recount-force dump-counts:p dump-counts:pair \
  batch-:b,1 batch+:a,3 flush \
  dump-rel:p dump-rel:q dump-rel:pair dump-counts:p dump-counts:pair \
  recount-force dump-counts:p dump-counts:pair \
  > out/sess-m3-acyclic.log 2>&1
expect "m3-negative-route" "(route maintain-negative 2)" out/sess-m3-acyclic.log
expect "m3-mixed-positive" "(route maintain-positive 2)" out/sess-m3-acyclic.log
expect "m3-counts-valid" "(update-committed 3 counts-valid)" out/sess-m3-acyclic.log
if [ "$(grep -cF '(dumpdone 2)' out/sess-m3-acyclic.log)" -eq 4 ] \
   && [ "$(grep -cF '(dumpdone 1)' out/sess-m3-acyclic.log)" -eq 1 ] \
   && [ "$(grep -cF '(dumpdone 4)' out/sess-m3-acyclic.log)" -eq 1 ]; then
  echo "PASS m3-set-content"; PASS=$((PASS+1))
else
  echo "FAIL m3-set-content"; FAIL=$((FAIL+1))
fi
if [ "$(grep -cF '(countrow pair 2 2 0 1 0)' out/sess-m3-acyclic.log)" -eq 4 ] \
   && [ "$(grep -cF '(countrow pair 2 3 0 1 0)' out/sess-m3-acyclic.log)" -eq 2 ] \
   && [ "$(grep -cF '(countrow pair 3 2 0 1 0)' out/sess-m3-acyclic.log)" -eq 2 ] \
   && [ "$(grep -cF '(countrow pair 3 3 0 1 0)' out/sess-m3-acyclic.log)" -eq 2 ]; then
  echo "PASS m3-maintained-equals-recount"; PASS=$((PASS+1))
else
  echo "FAIL m3-maintained-equals-recount"; FAIL=$((FAIL+1))
fi

# Inherited foundation support takes the same counted path: the successor's
# -a(1) installs a mask and removes its synthetic nonrec support, without
# mutating the predecessor VersionId.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m3_acyclic.slog batch+:a,1 flush \
  inject-reopen:a,m3-inherit,tests/session/m3_acyclic.slog,3 \
  batch-:a,1 flush dump-rel:a input-ledger dump-counts:a \
  recount-force dump-counts:a \
  > out/sess-m3-inherit.log 2>&1
expect "m3-inherit-route" "(route maintain-negative 2)" out/sess-m3-inherit.log
expect "m3-inherit-mask" "(inputledger mask" out/sess-m3-inherit.log
expect "m3-inherit-content" "(dumpdone 1)" out/sess-m3-inherit.log
if [ "$(grep -cF '(countrow a 3 1 0 0)' out/sess-m3-inherit.log)" -eq 2 ]; then
  echo "PASS m3-inherit-counts"; PASS=$((PASS+1))
else
  echo "FAIL m3-inherit-counts"; FAIL=$((FAIL+1))
fi

# A recursive producer is not admitted by M3's acyclicity certificate; since
# M4T it takes the recursive sweep instead of clear-and-rerun.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/base_input.slog \
  batch+:edge,1,2 batch+:edge,2,3 flush \
  batch-:edge,1,2 flush dump-rel:path \
  > out/sess-m3-cycle-fallback.log 2>&1
expect "m3-cycle-recursive-route" "(route maintain-recursive-negative 1)" out/sess-m3-cycle-fallback.log
expect "m3-cycle-content" "(dumpdone 1)" out/sess-m3-cycle-fallback.log

# Random legal signed streams (including mixed batches and delete/re-add
# cycles) are diffed against fresh recomputation; the fuzzer also compares
# every maintained derived counter with a forced recount.
for seed in 3101 3102; do
  if timeout 900 racket tests/api/acyclic-stream-fuzz.rkt $seed \
       > "out/sess-m3-fuzz-$seed.log" 2>&1 \
     && grep -q "m3-fuzz-ok $seed" "out/sess-m3-fuzz-$seed.log"; then
    echo "PASS m3-fuzz-$seed"; PASS=$((PASS+1))
  else
    echo "FAIL m3-fuzz-$seed (see out/sess-m3-fuzz-$seed.log)"; FAIL=$((FAIL+1))
  fi
done

# --- M6L slice 1: acyclic leaf-lattice contributor repair -----------------
# The sidecar keeps non-winning and duplicate contributions independently of
# the visible min payload.  Losing/winning/final removals and a mixed flush
# must stay on signed maintenance, after which a forced contributor recount
# reproduces the warm state exactly.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m6l_leaf.slog \
  batch+:offer,1,9 batch+:alias,1,5 flush \
  dump-rel:best dump-counts:best lattice-contributor-state \
  batch-:offer,1,9 flush dump-rel:best dump-counts:best \
  batch-:alias,1,5 flush dump-rel:best dump-counts:best \
  batch+:offer,1,7 batch+:alias,1,7 flush dump-counts:best \
  batch-:offer,1,7 flush dump-counts:best \
  batch-:alias,1,7 batch+:offer,1,3 batch+:alias,1,8 flush \
  dump-rel:best dump-counts:best \
  batch-:offer,1,3 flush dump-rel:best dump-counts:best \
  recount-lattices-force dump-counts:best lattice-contributor-state \
  > out/sess-m6l-leaf.log 2>&1
expect "m6l-positive-route" "(route maintain 1)" out/sess-m6l-leaf.log
expect "m6l-negative-route" "(route maintain-negative 1)" out/sess-m6l-leaf.log
expect "m6l-mixed-route" "(route maintain-positive 1)" out/sess-m6l-leaf.log
expect_not "m6l-no-rerun" "(route rerun" out/sess-m6l-leaf.log
expect "m6l-certified" "(lcnt best 0 1)" out/sess-m6l-leaf.log
expect "m6l-final-removal" "(countdone best 0)" out/sess-m6l-leaf.log
expect "m6l-duplicate-two" "(countrow best 1 7 0 2 0)" out/sess-m6l-leaf.log
expect "m6l-duplicate-one" "(countrow best 1 7 0 1 0)" out/sess-m6l-leaf.log
if [ "$(grep -cF '(countrow best 1 5 0 1 0)' out/sess-m6l-leaf.log)" -eq 2 ] \
   && [ "$(grep -cF '(countrow best 1 8 0 1 0)' out/sess-m6l-leaf.log)" -eq 3 ]; then
  echo "PASS m6l-maintained-equals-recount"; PASS=$((PASS+1))
else
  echo "FAIL m6l-maintained-equals-recount"; FAIL=$((FAIL+1))
fi

# M6L slice 2 closes the acyclic lattice value before publishing exactly one
# old->new pair into the downstream table consumer.  The losing deletion does
# not move the visible value; the mixed deletion/addition must skip its
# producer-phase intermediate and publish only 5->3; the next deletion
# regresses 3->8.  A forced recount then reproduces both contributor and
# consumer count state.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m6l_stratified.slog \
  batch+:offer,1,9 batch+:alias,1,5 flush \
  dump-tuples:best dump-tuples:reported dump-counts:best dump-counts:reported \
  batch-:offer,1,9 flush \
  dump-tuples:best dump-tuples:reported dump-counts:best dump-counts:reported \
  batch-:alias,1,5 batch+:offer,1,3 batch+:alias,1,8 flush \
  dump-tuples:best dump-tuples:reported dump-counts:best dump-counts:reported \
  batch-:offer,1,3 flush \
  dump-tuples:best dump-tuples:reported dump-counts:best dump-counts:reported \
  recount-lattices-force \
  dump-tuples:best dump-tuples:reported dump-counts:best dump-counts:reported \
  lattice-contributor-state \
  > out/sess-m6l-stratified.log 2>&1
expect "m6l2-negative-producer" "(route maintain-lattice-producers-negative 1)" out/sess-m6l-stratified.log
expect "m6l2-positive-producer" "(route maintain-lattice-producers-positive 1)" out/sess-m6l-stratified.log
expect "m6l2-negative-consumer" "(route maintain-lattice-consumers-negative 1)" out/sess-m6l-stratified.log
expect "m6l2-positive-consumer" "(route maintain-lattice-consumers-positive 1)" out/sess-m6l-stratified.log
expect_not "m6l2-no-rerun" "(route rerun" out/sess-m6l-stratified.log
expect_not "m6l2-no-intermediate" "(tuplerow 1 9)" out/sess-m6l-stratified.log
expect "m6l2-certified" "(lcnt best 0 1)" out/sess-m6l-stratified.log
if [ "$(grep -cF '(tuplerow 1 5)' out/sess-m6l-stratified.log)" -eq 4 ] \
   && [ "$(grep -cF '(tuplerow 1 3)' out/sess-m6l-stratified.log)" -eq 2 ] \
   && [ "$(grep -cF '(tuplerow 1 8)' out/sess-m6l-stratified.log)" -eq 4 ] \
   && [ "$(grep -cF '(countrow best 1 8 0 1 0)' out/sess-m6l-stratified.log)" -eq 3 ] \
   && [ "$(grep -cF '(countrow reported 1 8 0 1 0)' out/sess-m6l-stratified.log)" -eq 2 ]; then
  echo "PASS m6l2-coalesced-recount"; PASS=$((PASS+1))
else
  echo "FAIL m6l2-coalesced-recount"; FAIL=$((FAIL+1))
fi

# FLIPPED(M7 sub-slice (b)): recursive lattice consumers ride the repair
# route -- the acyclic producer keeps its M6L fold, the recursive consumer
# stratum takes the M4T sweep driven by the staged replacement rows.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m6l_recursive_consumer.slog \
  batch+:offer,1,5 flush batch-:offer,1,5 flush \
  dump-tuples:best dump-tuples:reported \
  > out/sess-m6l-recursive-fallback.log 2>&1
expect "m6l2-recursive-repair-neg" "(route maintain-lattice-recursive-negative 2)" out/sess-m6l-recursive-fallback.log
expect "m6l2-recursive-repair-pos" "(route maintain-lattice-recursive-positive 2)" out/sess-m6l-recursive-fallback.log
# exactly one rerun: the POSITIVE flush keeps its legacy route (monotone
# ascents never enter the repair fixpoint); only the deletion repairs
if [ "$(grep -cF '(route rerun' out/sess-m6l-recursive-fallback.log)" -eq 1 ]; then
  echo "PASS m6l2-recursive-one-legacy-rerun"; PASS=$((PASS+1))
else
  echo "FAIL m6l2-recursive-one-legacy-rerun"; FAIL=$((FAIL+1))
fi
expect_not "m6l2-recursive-not-m6l2-verbs" "maintain-lattice-consumers" out/sess-m6l-recursive-fallback.log

# A net contributor change that returns to the epoch-entry payload must emit no
# consumer replacement.  The same fixture also pins absent->present and
# present->absent propagation instead of relying on random streams to hit them.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m6l_stratified.slog \
  batch+:offer,1,5 flush dump-counts:reported \
  batch-:offer,1,5 batch+:alias,1,5 flush dump-counts:best dump-counts:reported \
  batch-:alias,1,5 flush dump-counts:best dump-counts:reported \
  batch+:offer,1,5 flush dump-counts:best dump-counts:reported \
  > out/sess-m6l-transitions.log 2>&1
expect_not "m6l2-transition-no-rerun" "(route rerun" out/sess-m6l-transitions.log
expect "m6l2-transition-absent" "(countdone reported 0)" out/sess-m6l-transitions.log
if [ "$(grep -cF '(countrow reported 1 5 0 1 0)' out/sess-m6l-transitions.log)" -eq 3 ] \
   && [ "$(grep -cF '(update-committed ' out/sess-m6l-transitions.log)" -eq 4 ]; then
  echo "PASS m6l2-net-no-change-and-presence"; PASS=$((PASS+1))
else
  echo "FAIL m6l2-net-no-change-and-presence"; FAIL=$((FAIL+1))
fi

# Scalar lattice kinds share one producer stratum.  This makes the journal
# VersionId-local while exercising max regression and flat top->constant repair.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m6l_shapes.slog \
  batch+:imax,1,5 batch+:imax,1,9 batch+:iflat,1,5 batch+:iflat,1,9 flush \
  dump-tuples:peak dump-tuples:constant lattice-contributor-state \
  batch-:imax,1,9 batch-:iflat,1,9 flush \
  dump-tuples:peak dump-tuples:constant dump-counts:peak dump-counts:constant \
  lattice-contributor-state recount-lattices-force \
  dump-counts:peak dump-counts:constant \
  > out/sess-m6l-shapes.log 2>&1
expect_not "m6l-shapes-no-rerun" "(route rerun" out/sess-m6l-shapes.log
expect "m6l-shapes-max" "(tuplerow 1 9)" out/sess-m6l-shapes.log
expect "m6l-shapes-flat-top" "(tuplerow 1 (top))" out/sess-m6l-shapes.log
expect "m6l-shapes-max-regress" "(countrow peak 1 5 0 1 0)" out/sess-m6l-shapes.log
expect "m6l-shapes-flat-regress" "(countrow constant 1 5 0 1 0)" out/sess-m6l-shapes.log
expect "m6l-shapes-certified-max" "(lcnt peak 0 1)" out/sess-m6l-shapes.log
expect "m6l-shapes-certified-flat" "(lcnt constant 0 1)" out/sess-m6l-shapes.log

# Multi-column keys and reversed consumers force more than one payload-map
# ordering.  Both live maps and both table sidecars must follow 5->9 repair.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m6l_orderings.slog \
  batch+:offer,1,2,9 batch+:offer,1,2,5 batch+:offer,2,1,7 flush \
  batch-:offer,1,2,5 flush \
  dump-tuples:best dump-tuples:forward dump-tuples:reverse \
  dump-counts:best dump-counts:forward dump-counts:reverse \
  recount-lattices-force dump-counts:best dump-counts:forward dump-counts:reverse \
  > out/sess-m6l-orderings.log 2>&1
expect_not "m6l-orderings-no-rerun" "(route rerun" out/sess-m6l-orderings.log
expect "m6l-orderings-best" "(tuplerow 1 2 9)" out/sess-m6l-orderings.log
expect "m6l-orderings-forward" "(countrow forward 1 2 9 0 1 0)" out/sess-m6l-orderings.log
expect "m6l-orderings-reverse" "(countrow reverse 2 1 9 0 1 0)" out/sess-m6l-orderings.log

# More than one producer stratum settles before the closed lattice reaches its
# consumer.  The mixed update's producer intermediate (9) is never published.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m6l_multistratum.slog \
  batch+:source,1,9 batch+:source,1,5 flush \
  dump-tuples:best dump-tuples:reported \
  batch-:source,1,5 batch+:source,1,3 flush \
  dump-tuples:best dump-tuples:reported dump-counts:best dump-counts:reported \
  recount-lattices-force dump-counts:best dump-counts:reported \
  > out/sess-m6l-multistratum.log 2>&1
expect "m6l-multi-negative-producers" "(route maintain-lattice-producers-negative 2)" out/sess-m6l-multistratum.log
expect "m6l-multi-positive-producers" "(route maintain-lattice-producers-positive 2)" out/sess-m6l-multistratum.log
expect "m6l-multi-consumer" "(route maintain-lattice-consumers-positive 1)" out/sess-m6l-multistratum.log
expect_not "m6l-multi-no-intermediate" "(tuplerow 1 9)" out/sess-m6l-multistratum.log
expect "m6l-multi-final" "(countrow reported 1 3 0 1 0)" out/sess-m6l-multistratum.log

# Contributor state is cache, not persistence truth.  A saved root session
# reopens uncounted, establishes its writers, and can then repair precisely.
rm -rf data/sess_m6l_reopen
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m6l_stratified.slog \
  batch+:offer,1,9 batch+:alias,1,5 flush save:sess_m6l_reopen \
  > out/sess-m6l-save.log 2>&1
timeout 900 racket tests/api/session-drive.rkt \
  open:sess_m6l_reopen lattice-contributor-state \
  batch-:alias,1,5 flush dump-tuples:best dump-tuples:reported \
  dump-counts:best dump-counts:reported lattice-contributor-state \
  > out/sess-m6l-open.log 2>&1
expect "m6l-open-starts-uncounted" "(lcnt best 0 0)" out/sess-m6l-open.log
expect "m6l-open-repair-route" "(route maintain-lattice-consumers-negative 1)" out/sess-m6l-open.log
expect "m6l-open-final" "(tuplerow 1 9)" out/sess-m6l-open.log
expect "m6l-open-certified" "(lcnt best 0 1)" out/sess-m6l-open.log

# Pin the remaining named topology refusals before M4T changes route
# classification: recursive producer, negated consumer, and lattice writer.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m6l_recursive_producer.slog \
  batch+:offer,1,9 batch+:offer,1,5 flush batch-:offer,1,5 flush \
  dump-tuples:best > out/sess-m6l-recursive-producer.log 2>&1
# FLIPPED(M7 sub-slice (b)): the recursive producer repairs -- deletion of
# the winning contributor regresses to the retained loser without rerun.
expect "m6l-recursive-producer-repair" "(route maintain-lattice-recursive-negative" out/sess-m6l-recursive-producer.log
expect_not "m6l-recursive-producer-no-rerun" "(route rerun" out/sess-m6l-recursive-producer.log
expect "m6l-recursive-producer-content" "(tuplerow 1 9)" out/sess-m6l-recursive-producer.log
expect_not "m6l-recursive-producer-not-m6l2-verbs" "maintain-lattice-producers" out/sess-m6l-recursive-producer.log

timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m6l_negated_consumer.slog \
  dump-tuples:missing batch+:offer,1,5 flush dump-tuples:missing \
  batch-:offer,1,5 flush dump-tuples:missing \
  > out/sess-m6l-negation.log 2>&1
expect "m6l-negation-fallback" "(route rerun" out/sess-m6l-negation.log
if [ "$(grep -cF '(tuplerow 1)' out/sess-m6l-negation.log)" -eq 2 ]; then
  echo "PASS m6l-negation-content"; PASS=$((PASS+1))
else
  echo "FAIL m6l-negation-content"; FAIL=$((FAIL+1))
fi

timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m6l_lattice_writer.slog \
  batch+:offer,1,9 batch+:offer,1,5 flush batch-:offer,1,5 flush \
  dump-tuples:best dump-tuples:echoed \
  > out/sess-m6l-lattice-writer.log 2>&1
expect "m6l-lattice-writer-fallback" "(route rerun" out/sess-m6l-lattice-writer.log
if [ "$(grep -cF '(tuplerow 1 9)' out/sess-m6l-lattice-writer.log)" -eq 2 ]; then
  echo "PASS m6l-lattice-writer-content"; PASS=$((PASS+1))
else
  echo "FAIL m6l-lattice-writer-content"; FAIL=$((FAIL+1))
fi

# Direct lattice overlays are refused, while an inherited lattice successor
# must fail contributor establishment and retain the correctness fallback.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m6l_leaf.slog batch+:best,1,5 flush \
  > out/sess-m6l-direct.log 2>&1 || true
expect "m6l-direct-refused" "set-overlay: best is a lattice/struct relation" out/sess-m6l-direct.log

timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m6l_stratified.slog batch+:offer,1,5 flush \
  inject-reopen:offer,m6l-inherited,tests/session/m6l_stratified.slog,2,7 \
  batch+:offer,3,4 flush dump-tuples:best dump-tuples:reported \
  lattice-contributor-state \
  > out/sess-m6l-inherited.log 2>&1
expect "m6l-inherited-recount-refused" "(maintenance-unavailable recount" out/sess-m6l-inherited.log
expect "m6l-inherited-fallback" "(route rerun" out/sess-m6l-inherited.log
expect "m6l-inherited-uncounted" "(lcnt best 1 0)" out/sess-m6l-inherited.log

# Source-program facts are derived-only to the input API, and persistent keys
# cannot collide within one evaluation.
if timeout 900 racket tests/api/session-drive.rkt \
     run:tests/session/counts_tc.slog batch-:edge,1,2 flush \
     > out/sess-m04-derived.log 2>&1; then
  echo "FAIL m04-derived-refusal"; FAIL=$((FAIL+1))
else
  expect "m04-derived-refusal" "derived-only" out/sess-m04-derived.log
fi
if timeout 900 racket tests/api/session-drive.rkt \
     run:tests/session/counts_tc.slog \
     inject-version:edge,m04-duplicate inject-version:edge,m04-duplicate \
     > out/sess-m04-duplicate.log 2>&1; then
  echo "FAIL m04-key-collision"; FAIL=$((FAIL+1))
else
  expect "m04-key-collision" "duplicate VersionKey" out/sess-m04-duplicate.log
fi

# Two replay evaluations share persistent VersionKeys but have distinct
# EvaluationIds; numeric VersionIds are scoped by those EvaluationIds.
timeout 900 racket tests/api/session-drive.rkt open:sess_m04 pipeline \
  > out/sess-m04-eval-a.log 2>&1
timeout 900 racket tests/api/session-drive.rkt open:sess_m04 pipeline \
  > out/sess-m04-eval-b.log 2>&1
eval_a=$(sed -n 's/.*(evaluation "\([^"]*\)").*/\1/p' out/sess-m04-eval-a.log | tail -1)
eval_b=$(sed -n 's/.*(evaluation "\([^"]*\)").*/\1/p' out/sess-m04-eval-b.log | tail -1)
if [ -n "$eval_a" ] && [ -n "$eval_b" ] && [ "$eval_a" != "$eval_b" ]; then
  echo "PASS m04-evaluation-isolation"; PASS=$((PASS+1))
else
  echo "FAIL m04-evaluation-isolation"; FAIL=$((FAIL+1))
fi
expect "m04-eval-a-key" '"m04-edge" (schema 2 0 set)' out/sess-m04-eval-a.log
expect "m04-eval-b-key" '"m04-edge" (schema 2 0 set)' out/sess-m04-eval-b.log

# Error arms count (8B.4: instantiation-deterministic) and close with the
# walk that covers their writer stratum.
timeout 600 racket tests/api/session-drive.rkt \
  run:tests/err_div0.slog recount dump-counts:div_by_zero count-state \
  > out/sess-counts-m03d.log 2>&1
expect "m03-arm-row"   " 100) 0 1 0)" out/sess-counts-m03d.log
expect "m03-arm-state" "(cnt div_by_zero 0 1)" out/sess-counts-m03d.log

# --- M4T slice 1: recursive plain-table deletion (docs/m4t-contract.md) -----
# Each fixture settles on the precise sweep/reseed/rebuild route and its
# maintained sidecar must equal a forced fresh recount.

# §5.2 symmetric cycle: proof counting alone would strand both tuples; the
# sweep over-deletes the pair and reseeds neither.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4t_symmetric_cycle.slog \
  batch+:r0,1,2 flush dump-rel:r recount dump-counts:r \
  batch-:r0,1,2 flush dump-rel:r recount-force dump-counts:r \
  > out/sess-m4t-cycle.log 2>&1
expect "m4t-cycle-positive-maintained" "(route maintain 1)" out/sess-m4t-cycle.log
expect "m4t-cycle-copy-counts" "(countrow r 1 2 0 1 1)" out/sess-m4t-cycle.log
expect "m4t-cycle-swap-counts" "(countrow r 2 1 0 0 1)" out/sess-m4t-cycle.log
expect "m4t-cycle-sweep" "(route maintain-recursive-negative 1)" out/sess-m4t-cycle.log
expect "m4t-cycle-discards" "(dred-reseeded 0 2)" out/sess-m4t-cycle.log
expect "m4t-cycle-settled" "(update-committed 2 counts-valid)" out/sess-m4t-cycle.log
expect "m4t-cycle-emptied" "(dumpdone 0)" out/sess-m4t-cycle.log
expect "m4t-cycle-zero-counted" "(countdone r 0)" out/sess-m4t-cycle.log

# §5.3 over-delete and refound: path(1,4) keeps a surviving derivation
# (rec 2 -> 1) and is reseeded; path(1,5) reaches zero and is relearned
# from the reseeded premise during the positive rebuild.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4t_diamond.slog \
  batch+:edge,1,2 batch+:edge,2,4 batch+:edge,1,3 batch+:edge,3,4 \
  batch+:edge,4,5 flush \
  dump-rel:path recount dump-counts:path \
  batch-:edge,1,2 flush dump-rel:path dump-counts:path \
  recount-force dump-counts:path \
  > out/sess-m4t-diamond.log 2>&1
expect "m4t-diamond-before" "(dumpdone 9)" out/sess-m4t-diamond.log
expect "m4t-diamond-two-routes" "(countrow path 1 4 0 0 2)" out/sess-m4t-diamond.log
expect "m4t-diamond-sweep" "(route maintain-recursive-negative 1)" out/sess-m4t-diamond.log
expect "m4t-diamond-reseed" "(dred-reseeded 1 2)" out/sess-m4t-diamond.log
expect "m4t-diamond-rebuild" "(route maintain-positive 1)" out/sess-m4t-diamond.log
expect "m4t-diamond-settled" "(update-committed 2 counts-valid)" out/sess-m4t-diamond.log
expect "m4t-diamond-after" "(dumpdone 8)" out/sess-m4t-diamond.log
if [ "$(grep -cF '(countrow path 1 4 0 0 1)' out/sess-m4t-diamond.log)" -eq 2 ] \
   && [ "$(grep -cF '(countrow path 1 5 0 0 1)' out/sess-m4t-diamond.log)" -ge 2 ]; then
  echo "PASS m4t-diamond-maintained-equals-recount"; PASS=$((PASS+1))
else
  echo "FAIL m4t-diamond-maintained-equals-recount"; FAIL=$((FAIL+1))
fi

# Repeated occurrences: closure by self-join over the swept relation; the
# cut cycle strands three rows, one (r(2,1)) founded purely recursively and
# restored by reseed from surviving recursive support.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4t_selfjoin.slog \
  batch+:r0,1,2 batch+:r0,2,3 batch+:r0,3,1 flush \
  dump-rel:r recount dump-counts:r \
  batch-:r0,1,2 flush dump-rel:r dump-counts:r \
  recount-force dump-counts:r \
  > out/sess-m4t-selfjoin.log 2>&1
expect "m4t-selfjoin-before" "(dumpdone 9)" out/sess-m4t-selfjoin.log
expect "m4t-selfjoin-dense" "(countrow r 2 1 0 0 3)" out/sess-m4t-selfjoin.log
expect "m4t-selfjoin-sweep" "(route maintain-recursive-negative 1)" out/sess-m4t-selfjoin.log
expect "m4t-selfjoin-reseeds" "(dred-reseeded 1 6)" out/sess-m4t-selfjoin.log
expect "m4t-selfjoin-settled" "(update-committed 2 counts-valid)" out/sess-m4t-selfjoin.log
expect "m4t-selfjoin-after" "(dumpdone 3)" out/sess-m4t-selfjoin.log
if [ "$(grep -cF '(countrow r 2 1 0 0 1)' out/sess-m4t-selfjoin.log)" -eq 2 ] \
   && [ "$(grep -cF '(countrow r 2 3 0 1 0)' out/sess-m4t-selfjoin.log)" -eq 2 ] \
   && [ "$(grep -cF '(countrow r 3 1 0 1 0)' out/sess-m4t-selfjoin.log)" -eq 2 ]; then
  echo "PASS m4t-selfjoin-maintained-equals-recount"; PASS=$((PASS+1))
else
  echo "FAIL m4t-selfjoin-maintained-equals-recount"; FAIL=$((FAIL+1))
fi

# Two SCC strata over an acyclic bridge: both sweeps run inside one
# topological negative walk and the cancelling cascade crosses the bridge.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4t_bridge.slog \
  batch+:edge1,1,2 batch+:edge1,2,1 flush \
  dump-rel:path1 dump-rel:path2 recount dump-counts:path2 \
  batch-:edge1,2,1 flush dump-rel:path1 dump-rel:path2 dump-counts:path2 \
  recount-force dump-counts:path2 \
  > out/sess-m4t-bridge.log 2>&1
expect "m4t-bridge-positive-maintained" "(route maintain 3)" out/sess-m4t-bridge.log
expect "m4t-bridge-before" "(countrow path2 1 2 0 1 2)" out/sess-m4t-bridge.log
expect "m4t-bridge-sweep" "(route maintain-recursive-negative 3)" out/sess-m4t-bridge.log
expect "m4t-bridge-discards" "(dred-reseeded 0 6)" out/sess-m4t-bridge.log
expect "m4t-bridge-settled" "(update-committed 2 counts-valid)" out/sess-m4t-bridge.log
if [ "$(grep -cF '(countrow path2 1 2 0 1 0)' out/sess-m4t-bridge.log)" -eq 2 ]; then
  echo "PASS m4t-bridge-maintained-equals-recount"; PASS=$((PASS+1))
else
  echo "FAIL m4t-bridge-maintained-equals-recount"; FAIL=$((FAIL+1))
fi

# Mixed signs in one epoch: the sweep, reseed, and a genuinely new edge all
# settle in one revision; path(2,5) ends with copy AND recursive support.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4t_diamond.slog \
  batch+:edge,1,2 batch+:edge,2,4 batch+:edge,1,3 batch+:edge,3,4 \
  batch+:edge,4,5 flush \
  batch-:edge,1,2 batch+:edge,2,5 flush dump-rel:path dump-counts:path \
  recount-force dump-counts:path \
  > out/sess-m4t-mixed.log 2>&1
expect "m4t-mixed-sweep" "(route maintain-recursive-negative 1)" out/sess-m4t-mixed.log
expect "m4t-mixed-reseed" "(dred-reseeded 1 2)" out/sess-m4t-mixed.log
expect "m4t-mixed-rebuild" "(route maintain-positive 1)" out/sess-m4t-mixed.log
expect "m4t-mixed-settled" "(update-committed 2 counts-valid)" out/sess-m4t-mixed.log
expect "m4t-mixed-content" "(dumpdone 8)" out/sess-m4t-mixed.log
if [ "$(grep -cF '(countrow path 2 5 0 1 1)' out/sess-m4t-mixed.log)" -eq 2 ]; then
  echo "PASS m4t-mixed-maintained-equals-recount"; PASS=$((PASS+1))
else
  echo "FAIL m4t-mixed-maintained-equals-recount"; FAIL=$((FAIL+1))
fi

# --- M4T slice 2: recursive-head edits and inheritance admission -----------
# An edit targeting a recursive head takes the foundation-aware overlay verb
# (docs/m4t-contract.md): a zero-rec direct row degenerates to the ordinary
# presence loss inside the sweep epoch.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4t_diamond.slog \
  batch+:path,7,8 flush dump-rel:path \
  batch-:path,7,8 flush dump-rel:path \
  > out/sess-m4t-headedit.log 2>&1
expect "m4t-headedit-verb" "(overlay-negative-dred path 1 1)" out/sess-m4t-headedit.log
expect "m4t-headedit-route" "(route maintain-recursive-negative 1)" out/sess-m4t-headedit.log
expect "m4t-headedit-discard" "(dred-reseeded 0 1)" out/sess-m4t-headedit.log
expect "m4t-headedit-settled" "(update-committed 2 counts-valid)" out/sess-m4t-headedit.log
expect "m4t-headedit-empty" "(dumpdone 0)" out/sess-m4t-headedit.log

# Deleting a direct assertion on a derived recursive head row: foundation
# loss with rec 2 enters candidacy at apply time; the sweep drags path(1,5)
# to zero, reseed restores path(1,4) from surviving recursive support, and
# the rebuild relearns path(1,5).  Content is unchanged.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4t_diamond.slog \
  batch+:edge,1,2 batch+:edge,2,4 batch+:edge,1,3 batch+:edge,3,4 \
  batch+:edge,4,5 flush \
  batch+:path,1,4 flush \
  batch-:path,1,4 flush dump-rel:path dump-counts:path \
  recount-force dump-counts:path \
  > out/sess-m4t-headreseed.log 2>&1
expect "m4t-headreseed-verb" "(overlay-negative-dred path 1 1)" out/sess-m4t-headreseed.log
expect "m4t-headreseed-sweep" "(route maintain-recursive-negative 1)" out/sess-m4t-headreseed.log
expect "m4t-headreseed-reseed" "(dred-reseeded 1 1)" out/sess-m4t-headreseed.log
expect "m4t-headreseed-rebuild" "(route maintain-positive 1)" out/sess-m4t-headreseed.log
expect "m4t-headreseed-settled" "(update-committed 3 counts-valid)" out/sess-m4t-headreseed.log
expect "m4t-headreseed-content" "(dumpdone 9)" out/sess-m4t-headreseed.log
if [ "$(grep -cF '(countrow path 1 4 0 0 2)' out/sess-m4t-headreseed.log)" -eq 2 ] \
   && [ "$(grep -cF '(countrow path 1 5 0 0 1)' out/sess-m4t-headreseed.log)" -eq 2 ]; then
  echo "PASS m4t-headreseed-maintained-equals-recount"; PASS=$((PASS+1))
else
  echo "FAIL m4t-headreseed-maintained-equals-recount"; FAIL=$((FAIL+1))
fi

# The unfounded pair via a head edit: r(5,6) direct feeds r(6,5), which
# recursively feeds r(5,6) back.  Presence semantics would strand both on
# positive rec; the foundation-aware verb over-deletes r(5,6) and the sweep
# collapses the pair with nothing reseeded.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4t_symmetric_cycle.slog \
  batch+:r,5,6 flush dump-rel:r recount dump-counts:r \
  batch-:r,5,6 flush dump-rel:r dump-counts:r \
  recount-force dump-counts:r \
  > out/sess-m4t-headcycle.log 2>&1
expect "m4t-headcycle-before-direct" "(countrow r 5 6 1 0 1)" out/sess-m4t-headcycle.log
expect "m4t-headcycle-before-swap" "(countrow r 6 5 0 0 1)" out/sess-m4t-headcycle.log
expect "m4t-headcycle-verb" "(overlay-negative-dred r 1 1)" out/sess-m4t-headcycle.log
expect "m4t-headcycle-sweep" "(route maintain-recursive-negative 1)" out/sess-m4t-headcycle.log
expect "m4t-headcycle-discards" "(dred-reseeded 0 2)" out/sess-m4t-headcycle.log
expect "m4t-headcycle-settled" "(update-committed 2 counts-valid)" out/sess-m4t-headcycle.log
expect "m4t-headcycle-emptied" "(dumpdone 0)" out/sess-m4t-headcycle.log
if [ "$(grep -cF '(countdone r 0)' out/sess-m4t-headcycle.log)" -eq 2 ]; then
  echo "PASS m4t-headcycle-zero-counted"; PASS=$((PASS+1))
else
  echo "FAIL m4t-headcycle-zero-counted"; FAIL=$((FAIL+1))
fi

# Inheritance/version edges (foundation contract): masking an actively
# inherited edge tuple at the reopened tip sweeps the successor SCC, but
# every inherited path row keeps its inheritance nonrec as foundation --
# support-only decrements, no candidates, content intact.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4t_diamond.slog \
  batch+:edge,1,2 batch+:edge,2,4 batch+:edge,1,3 batch+:edge,3,4 \
  batch+:edge,4,5 flush \
  inject-reopen:edge,m4t-inherit,tests/session/m4t_diamond.slog,9,10 \
  batch-:edge,1,2 flush dump-rel:path input-ledger dump-counts:path \
  recount-force dump-counts:path \
  > out/sess-m4t-inherit.log 2>&1
expect "m4t-inherit-verb" "(overlay-negative edge 1 1)" out/sess-m4t-inherit.log
expect "m4t-inherit-sweep" "(route maintain-recursive-negative 1)" out/sess-m4t-inherit.log
expect "m4t-inherit-barrier" "(dred-reseeded 0 0)" out/sess-m4t-inherit.log
expect "m4t-inherit-settled" "(update-committed 4 counts-valid)" out/sess-m4t-inherit.log
expect "m4t-inherit-mask" "(inputledger mask" out/sess-m4t-inherit.log
expect "m4t-inherit-content" "(dumpdone 10)" out/sess-m4t-inherit.log
if [ "$(grep -cF '(countrow path 1 2 0 1 0)' out/sess-m4t-inherit.log)" -eq 2 ] \
   && [ "$(grep -cF '(countdone path 10)' out/sess-m4t-inherit.log)" -eq 2 ]; then
  echo "PASS m4t-inherit-maintained-equals-recount"; PASS=$((PASS+1))
else
  echo "FAIL m4t-inherit-maintained-equals-recount"; FAIL=$((FAIL+1))
fi

# Version-copy contract at the head: masking an actively inherited row of
# the recursive head removes exactly the inheritance contribution; the
# candidate reseeds from surviving successor-local recursive support and
# the mask persists while presence returns through derivation.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4t_diamond.slog \
  batch+:edge,1,2 batch+:edge,2,4 batch+:edge,1,3 batch+:edge,3,4 \
  batch+:edge,4,5 flush \
  inject-reopen:edge,m4t-inherit,tests/session/m4t_diamond.slog,9,10 \
  batch-:path,1,4 flush dump-rel:path input-ledger dump-counts:path \
  recount-force dump-counts:path \
  > out/sess-m4t-inherit-head.log 2>&1
expect "m4t-inherit-head-verb" "(overlay-negative-dred path 1 1)" out/sess-m4t-inherit-head.log
expect "m4t-inherit-head-sweep" "(route maintain-recursive-negative 1)" out/sess-m4t-inherit-head.log
expect "m4t-inherit-head-reseed" "(dred-reseeded 1 0)" out/sess-m4t-inherit-head.log
expect "m4t-inherit-head-rebuild" "(route maintain-positive 1)" out/sess-m4t-inherit-head.log
expect "m4t-inherit-head-settled" "(update-committed 4 counts-valid)" out/sess-m4t-inherit-head.log
expect "m4t-inherit-head-mask" "(inputledger mask" out/sess-m4t-inherit-head.log
expect "m4t-inherit-head-content" "(dumpdone 10)" out/sess-m4t-inherit-head.log
if [ "$(grep -cF '(countrow path 1 4 0 0 2)' out/sess-m4t-inherit-head.log)" -eq 2 ] \
   && [ "$(grep -cF '(countrow path 1 5 0 1 1)' out/sess-m4t-inherit-head.log)" -eq 2 ]; then
  echo "PASS m4t-inherit-head-maintained-equals-recount"; PASS=$((PASS+1))
else
  echo "FAIL m4t-inherit-head-maintained-equals-recount"; FAIL=$((FAIL+1))
fi

# Clear-and-rerun preserves the input baseline: a direct assertion on a
# derived relation is input, not a rule consequence, and must survive the
# cone clear (§0.6).  Before the fix, rerun silently dropped path(9,9).
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/base_input.slog \
  batch+:edge,1,2 batch+:path,9,9 flush dump-rel:path \
  rerun:edge dump-rel:path recount dump-counts:path \
  > out/sess-rerun-baseline.log 2>&1
expect "rerun-baseline-before" "(dumpdone 2)" out/sess-rerun-baseline.log
expect "rerun-baseline-direct-kept" "(countrow path 9 9 1 0 0)" out/sess-rerun-baseline.log
expect "rerun-baseline-counted" "(countdone path 2)" out/sess-rerun-baseline.log
if [ "$(grep -cF '(dumpdone 2)' out/sess-rerun-baseline.log)" -eq 2 ]; then
  echo "PASS rerun-baseline-preserved"; PASS=$((PASS+1))
else
  echo "FAIL rerun-baseline-preserved"; FAIL=$((FAIL+1))
fi

# A mid-cone version edge (a cone stratum's relation rebound after it) is
# NOT admitted: the rebound guard diverts the tip batch to the anchored
# walk, which settles the correct successor content.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4t_diamond.slog \
  batch+:edge,1,2 batch+:edge,2,4 batch+:edge,1,3 batch+:edge,3,4 \
  batch+:edge,4,5 flush \
  run:tests/session/m4t_diamond.slog \
  batch-:edge,1,2 flush dump-rel:path \
  > out/sess-m4t-midcone.log 2>&1
expect "m4t-midcone-anchored" "(route anchored edge 1 2)" out/sess-m4t-midcone.log
expect_not "m4t-midcone-no-sweep" "(route maintain-recursive-negative" out/sess-m4t-midcone.log
expect "m4t-midcone-content" "(dumpdone 8)" out/sess-m4t-midcone.log

# --- WCOJ join3 inside the incremental artifacts (docs/wcoj.md §15) ---------
# The triangle body lowers to a single join3 cycle action; every incremental
# artifact flavor must carry it (asserted against the .plan sidecars of the
# artifacts this very run compiled), and the maintained support sidecars must
# equal a forced fresh recount -- set output equality alone is insufficient.
expect_join3_plan() { # name plan-file
  if [ -f "$2" ] && grep -qF "(join3 " "$2"; then
    echo "PASS $1"; PASS=$((PASS+1))
  else
    echo "FAIL $1 (no join3 action in $2)"; FAIL=$((FAIL+1))
  fi
}

# Acyclic: _maint1 (positive OLD arms) twice, then _maint3neg (negative NEW
# arms); deleting the closing edge (1,3) kills wtri(1,2,3) and wtri(1,3,4)
# while wtri(2,3,4) and wtri(1,2,4) survive with exact nonrec support.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/wcoj_tri.slog \
  batch+:edge,1,2 batch+:edge,2,3 batch+:edge,1,3 batch+:edge,2,4 \
  batch+:edge,3,4 flush \
  dump-rel:wtri recount dump-counts:wtri \
  batch+:edge,1,4 flush dump-rel:wtri dump-counts:wtri \
  batch-:edge,1,3 flush dump-rel:wtri dump-counts:wtri \
  recount-force dump-counts:wtri \
  > out/sess-wcoj-tri.log 2>&1
expect "wcoj-tri-neg-route" "(route maintain-negative 1)" out/sess-wcoj-tri.log
expect "wcoj-tri-grown" "(dumpdone 4)" out/sess-wcoj-tri.log
expect "wcoj-tri-settled" "(update-committed 3 counts-valid)" out/sess-wcoj-tri.log
if [ "$(grep -cF '(route maintain 1)' out/sess-wcoj-tri.log)" -eq 2 ] \
   && [ "$(grep -cF '(dumpdone 2)' out/sess-wcoj-tri.log)" -eq 2 ]; then
  echo "PASS wcoj-tri-both-positive-maintained"; PASS=$((PASS+1))
else
  echo "FAIL wcoj-tri-both-positive-maintained"; FAIL=$((FAIL+1))
fi
# survivor counted 4x (recount, two maintained dumps, forced recount); the
# maintained row born in flush 2 counted 3x; rows lost to the deletion stop
# appearing at exactly the right dump
if [ "$(grep -cF '(countrow wtri 2 3 4 0 1 0)' out/sess-wcoj-tri.log)" -eq 4 ] \
   && [ "$(grep -cF '(countrow wtri 1 2 4 0 1 0)' out/sess-wcoj-tri.log)" -eq 3 ] \
   && [ "$(grep -cF '(countrow wtri 1 2 3 0 1 0)' out/sess-wcoj-tri.log)" -eq 2 ] \
   && [ "$(grep -cF '(countrow wtri 1 3 4 0 1 0)' out/sess-wcoj-tri.log)" -eq 1 ]; then
  echo "PASS wcoj-tri-maintained-equals-recount"; PASS=$((PASS+1))
else
  echo "FAIL wcoj-tri-maintained-equals-recount"; FAIL=$((FAIL+1))
fi
wcoj_tri_hash=$(grep -oE '"[0-9a-f]{8}_maint1"' out/sess-wcoj-tri.log \
                  | head -1 | tr -d '"' | sed 's/_maint1//')
expect_join3_plan "wcoj-tri-plan-normal"   "build/${wcoj_tri_hash}.plan"
expect_join3_plan "wcoj-tri-plan-count"    "build/${wcoj_tri_hash}_count.ci1-v2.plan"
expect_join3_plan "wcoj-tri-plan-maint1"   "build/${wcoj_tri_hash}_maint1.ci1-v2.plan"
expect_join3_plan "wcoj-tri-plan-maint3neg" "build/${wcoj_tri_hash}_maint3neg.ci1-v2.plan"

# Recursive: tedge is both the edited input and the recursive head, so the
# deletion applies through the foundation-aware overlay verb and the
# _maint4neg sweep's join3 finds the lost instantiation; tedge(3,1) loses
# its only foundation (no reseed) and is relearned by the join3 _maint1
# rebuild when the edge returns.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/wcoj_tri_rec.slog \
  batch+:tedge,1,2 batch+:tedge,2,3 batch+:tedge,1,3 flush \
  dump-rel:tedge recount dump-counts:tedge \
  batch-:tedge,2,3 flush dump-rel:tedge dump-counts:tedge \
  batch+:tedge,2,3 flush dump-rel:tedge dump-counts:tedge \
  recount-force dump-counts:tedge \
  > out/sess-wcoj-rec.log 2>&1
expect "wcoj-rec-overlay-verb" "(overlay-negative-dred tedge 1 1)" out/sess-wcoj-rec.log
expect "wcoj-rec-sweep" "(route maintain-recursive-negative 1)" out/sess-wcoj-rec.log
expect "wcoj-rec-no-reseed" "(dred-reseeded 0 2)" out/sess-wcoj-rec.log
expect "wcoj-rec-swept" "(dumpdone 2)" out/sess-wcoj-rec.log
expect "wcoj-rec-settled" "(update-committed 3 counts-valid)" out/sess-wcoj-rec.log
if [ "$(grep -cF '(route maintain 1)' out/sess-wcoj-rec.log)" -eq 2 ] \
   && [ "$(grep -cF '(dumpdone 4)' out/sess-wcoj-rec.log)" -eq 2 ]; then
  echo "PASS wcoj-rec-relearned"; PASS=$((PASS+1))
else
  echo "FAIL wcoj-rec-relearned"; FAIL=$((FAIL+1))
fi
# the purely recursively founded row: recount, maintained relearn, forced
# recount -- and never while the closing edge is out
if [ "$(grep -cF '(countrow tedge 3 1 0 0 1)' out/sess-wcoj-rec.log)" -eq 3 ]; then
  echo "PASS wcoj-rec-maintained-equals-recount"; PASS=$((PASS+1))
else
  echo "FAIL wcoj-rec-maintained-equals-recount"; FAIL=$((FAIL+1))
fi
wcoj_rec_hash=$(grep -oE '"[0-9a-f]{8}_maint4neg"' out/sess-wcoj-rec.log \
                  | head -1 | tr -d '"' | sed 's/_maint4neg//')
expect_join3_plan "wcoj-rec-plan-normal"    "build/${wcoj_rec_hash}.plan"
expect_join3_plan "wcoj-rec-plan-count"     "build/${wcoj_rec_hash}_count.ci1-v2.plan"
expect_join3_plan "wcoj-rec-plan-maint1"    "build/${wcoj_rec_hash}_maint1.ci1-v2.plan"
expect_join3_plan "wcoj-rec-plan-maint4neg" "build/${wcoj_rec_hash}_maint4neg.ci1-v2.plan"

# --- M5 slice 1: struct ids are stable across clear-and-rerun ---------------
# (docs/m5-contract.md).  The struct cone routes to clear-and-rerun on a
# deletion; the clear keeps the intern dictionary as tombstones, so the
# rerun's re-derivations RESURRECT the original ids.  dump-ids exposes the
# raw id words (rendered dumps hide them) plus the tombstone count.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/base2_input.slog \
  batch+:in,1,2 batch+:in,3,4 flush dump-ids:pair \
  batch-:in,3,4 flush dump-ids:pair \
  batch+:in,3,4 flush dump-ids:pair \
  > out/sess-m5-ids.log 2>&1
expect "m5-ids-populated" "(idsdone 2 0)" out/sess-m5-ids.log
expect "m5-ids-tombstoned" "(idsdone 1 1)" out/sess-m5-ids.log
# FLIPPED(M7 sub-slice (c)): struct+lattice cones repair in place;
# the id-stability asserts below now hold THROUGH the repair route.
expect "m5-ids-repair-routed" "(route maintain-lattice-recursive-negative" out/sess-m5-ids.log
if [ "$(grep -cF '(idsdone 2 0)' out/sess-m5-ids.log)" -eq 2 ]; then
  echo "PASS m5-ids-all-resurrected"; PASS=$((PASS+1))
else
  echo "FAIL m5-ids-all-resurrected (tombstones left after reappearance)"; FAIL=$((FAIL+1))
fi
m5_ids1=$(grep -F '(idrow ' out/sess-m5-ids.log | head -2 | sort)
m5_ids2=$(grep -F '(idrow ' out/sess-m5-ids.log | sed -n '3p')
m5_ids3=$(grep -F '(idrow ' out/sess-m5-ids.log | tail -2 | sort)
if [ -n "$m5_ids1" ] && [ "$m5_ids1" = "$m5_ids3" ]; then
  echo "PASS m5-ids-stable-across-rerun"; PASS=$((PASS+1))
else
  echo "FAIL m5-ids-stable-across-rerun (ids reminted)"; FAIL=$((FAIL+1))
fi
if [ -n "$m5_ids2" ] && printf '%s\n' "$m5_ids1" | grep -qF "$m5_ids2"; then
  echo "PASS m5-ids-survivor-original"; PASS=$((PASS+1))
else
  echo "FAIL m5-ids-survivor-original (survivor id not from the original set)"; FAIL=$((FAIL+1))
fi

# --- M5 slice 1: imported direct assertion embedding a struct id ------------
# (docs/m5-contract.md exit criterion 2, embedded-id leg.)  A frozen mini
# bin-db asserts (out (pair 7 8)) directly; no rule derives pair(7,8), so
# after the struct cone's clear-and-rerun its liveness must return through
# the input ledger -- importDatabaseBIN records the payload's struct heap
# as direct input exactly like its table rows, and the baseline verbatim
# re-insert reconciles the tombstone.  Before that recording existed, the
# restored out row's embedded id stayed tombstoned and decoded as garbage
# ((pair 0.0 0.0)) with no drift fatal.
rm -rf out/sess-m5-keep-db
{
  echo '(struct pair 2)'
  echo '(table out 1)'
  echo '(out (pair 7 8))'
} > out/sess-m5-keep.facts
timeout 600 racket -e '
(require "compiler/tools.rkt" racket/file)
(run-freezer "out/sess-m5-keep-db" (file->string "out/sess-m5-keep.facts"))
(displayln "frozen-ok")' > out/sess-m5-keep-freeze.log 2>&1
expect "m5-keep-freeze" "frozen-ok" out/sess-m5-keep-freeze.log
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/base2_input.slog \
  batch+:in,1,2 batch+:in,3,4 flush \
  import-delta:out/sess-m5-keep-db \
  dump-ids:pair dump-rel:out \
  batch-:in,3,4 flush dump-ids:pair dump-rel:out \
  batch+:in,3,4 flush dump-ids:pair dump-rel:out \
  > out/sess-m5-keep.log 2>&1
# pair ids: 3 live/0 dead -> 2 live/1 tombstone -> 3 live/0 dead
expect "m5-keep-populated"    "(idsdone 3 0)" out/sess-m5-keep.log
expect "m5-keep-tombstoned"   "(idsdone 2 1)" out/sess-m5-keep.log
# FLIPPED(M7 sub-slice (c)): struct+lattice cones repair in place;
# the id-stability asserts below now hold THROUGH the repair route.
expect "m5-keep-repair-routed" "(route maintain-lattice-recursive-negative" out/sess-m5-keep.log
if [ "$(grep -cF '(idsdone 3 0)' out/sess-m5-keep.log)" -eq 2 ]; then
  echo "PASS m5-keep-all-resurrected"; PASS=$((PASS+1))
else
  echo "FAIL m5-keep-all-resurrected (tombstones left after reappearance)"; FAIL=$((FAIL+1))
fi
# out: 3 rows -> 2 rows -> 3 rows, and the imported row's embedded id
# decodes as (pair 7 8) in every dump (the dangling-id check).
if [ "$(grep -cF '(dumpdone 3)' out/sess-m5-keep.log)" -eq 2 ] \
   && [ "$(grep -cF '(dumpdone 2)' out/sess-m5-keep.log)" -eq 1 ]; then
  echo "PASS m5-keep-out-contents"; PASS=$((PASS+1))
else
  echo "FAIL m5-keep-out-contents"; FAIL=$((FAIL+1))
fi
if [ "$(grep -F '(dumprow ' out/sess-m5-keep.log | grep -cF 'pair 7 8')" -eq 3 ]; then
  echo "PASS m5-keep-imported-row-decodes"; PASS=$((PASS+1))
else
  echo "FAIL m5-keep-imported-row-decodes (embedded struct id dangling)"; FAIL=$((FAIL+1))
fi
# id-word stability: dump1 (3 ids) == dump3 (3 ids); dump2 (2 ids) subset.
m5k_1=$(grep -F '(idrow ' out/sess-m5-keep.log | head -3 | sort)
m5k_2=$(grep -F '(idrow ' out/sess-m5-keep.log | sed -n '4,5p' | sort)
m5k_3=$(grep -F '(idrow ' out/sess-m5-keep.log | tail -3 | sort)
if [ -n "$m5k_1" ] && [ "$m5k_1" = "$m5k_3" ]; then
  echo "PASS m5-keep-ids-stable"; PASS=$((PASS+1))
else
  echo "FAIL m5-keep-ids-stable (ids reminted across rerun)"; FAIL=$((FAIL+1))
fi
m5k_sub=ok
while IFS= read -r l; do
  [ -n "$l" ] && { printf '%s\n' "$m5k_1" | grep -qFx "$l" || m5k_sub=bad; }
done <<< "$m5k_2"
if [ -n "$m5k_2" ] && [ "$m5k_sub" = ok ]; then
  echo "PASS m5-keep-survivors-original"; PASS=$((PASS+1))
else
  echo "FAIL m5-keep-survivors-original"; FAIL=$((FAIL+1))
fi

# --- M5 slice 1: flat-OPENED direct assertion embedding a struct id ----------
# (docs/m5-contract.md exit criterion 2, embedded-id leg -- the second fixed
# site.)  The same recording hole had a flat-open half: markLatestRelationsDirect
# carried the pre-M5 struct exclusion, so an opened root's struct heap was
# not direct input.  Unlike the import leg, a later clear-and-rerun cannot
# expose it here -- the opened version is every tip's predecessor, and
# rematerializeInputBaseline restores through unmasked inheritance -- but the
# COUNT ROUND walks the opened version itself: without the input bit its
# struct instance has no support kind, and the coverage audit fatals the
# daemon with "count epoch: live tuple has no positive semantic support"
# (verified by reverting the exclusion).  The recount below is therefore the
# regression detector; the edit cycle then pins the ledgered row's liveness,
# decode, and id stability through a routed clear-and-rerun, and the forced
# recount re-derives the same support shape from scratch.
rm -rf data/sess_m5_open
timeout 600 racket compiler/run.rkt --no-banner --out-db sess_m5_open \
  tests/session/m5_open_seed.slog > out/sess-m5-open-seed.log 2>&1
timeout 900 racket tests/api/session-drive.rkt \
  open:sess_m5_open \
  run:tests/session/base2_input.slog \
  batch+:in,1,2 batch+:in,3,4 flush \
  recount dump-counts:pair dump-counts:out \
  dump-ids:pair dump-rel:out \
  batch-:in,3,4 flush dump-ids:pair dump-rel:out \
  batch+:in,3,4 flush dump-ids:pair dump-rel:out \
  recount-force dump-counts:out \
  > out/sess-m5-open.log 2>&1
# the opened heap is counted input: the recount commits instead of fataling,
# and the opened row's support at the tip is the inherited (nonrec) kind
expect "m5-open-counts-valid" "(update-committed 1 counts-valid)" out/sess-m5-open.log
expect "m5-open-heap-support" "(countrow pair (pair 7 8) 0 1 0)" out/sess-m5-open.log
# pair ids: 3 live/0 dead -> 2 live/1 tombstone -> 3 live/0 dead
expect "m5-open-populated"    "(idsdone 3 0)" out/sess-m5-open.log
expect "m5-open-tombstoned"   "(idsdone 2 1)" out/sess-m5-open.log
# FLIPPED(M7 sub-slice (c)): struct+lattice cones repair in place;
# the id-stability asserts below now hold THROUGH the repair route.
expect "m5-open-repair-routed" "(route maintain-lattice-recursive-negative" out/sess-m5-open.log
if [ "$(grep -cF '(idsdone 3 0)' out/sess-m5-open.log)" -eq 2 ]; then
  echo "PASS m5-open-all-resurrected"; PASS=$((PASS+1))
else
  echo "FAIL m5-open-all-resurrected (tombstones left after reappearance)"; FAIL=$((FAIL+1))
fi
# out: 3 rows -> 2 rows -> 3 rows, and the opened row's embedded id decodes
# as (pair 7 8) in every dump (the dangling-id check)
if [ "$(grep -cF '(dumpdone 3)' out/sess-m5-open.log)" -eq 2 ] \
   && [ "$(grep -cF '(dumpdone 2)' out/sess-m5-open.log)" -eq 1 ]; then
  echo "PASS m5-open-out-contents"; PASS=$((PASS+1))
else
  echo "FAIL m5-open-out-contents"; FAIL=$((FAIL+1))
fi
if [ "$(grep -F '(dumprow ' out/sess-m5-open.log | grep -cF 'pair 7 8')" -eq 3 ]; then
  echo "PASS m5-open-opened-row-decodes"; PASS=$((PASS+1))
else
  echo "FAIL m5-open-opened-row-decodes (embedded struct id dangling)"; FAIL=$((FAIL+1))
fi
# id-word stability: dump1 (3 ids) == dump3 (3 ids); dump2 (2 ids) subset
m5o_1=$(grep -F '(idrow ' out/sess-m5-open.log | head -3 | sort)
m5o_2=$(grep -F '(idrow ' out/sess-m5-open.log | sed -n '4,5p' | sort)
m5o_3=$(grep -F '(idrow ' out/sess-m5-open.log | tail -3 | sort)
if [ -n "$m5o_1" ] && [ "$m5o_1" = "$m5o_3" ]; then
  echo "PASS m5-open-ids-stable"; PASS=$((PASS+1))
else
  echo "FAIL m5-open-ids-stable (ids reminted across rerun)"; FAIL=$((FAIL+1))
fi
m5o_sub=ok
while IFS= read -r l; do
  [ -n "$l" ] && { printf '%s\n' "$m5o_1" | grep -qFx "$l" || m5o_sub=bad; }
done <<< "$m5o_2"
if [ -n "$m5o_2" ] && [ "$m5o_sub" = ok ]; then
  echo "PASS m5-open-survivors-original"; PASS=$((PASS+1))
else
  echo "FAIL m5-open-survivors-original"; FAIL=$((FAIL+1))
fi
# the forced fresh recount re-derives the same opened-row support
if [ "$(grep -cF '(countrow out (pair 7 8) 0 1 0)' out/sess-m5-open.log)" -eq 2 ]; then
  echo "PASS m5-open-forced-recount-agrees"; PASS=$((PASS+1))
else
  echo "FAIL m5-open-forced-recount-agrees"; FAIL=$((FAIL+1))
fi

# --- M4S fixtures (docs/m4s-contract.md) -------------------------------------
# SLICES 1+2 FLIPPED: struct relations are admitted as interior cone members
# on the counted maintenance routes -- acyclic M1/M3 (chain, multictor,
# mixed-sign, import) and the M4T recursive sweep (diamond, selfjoin,
# dredhead).  Every block asserts precise routes, id stability (dump-ids),
# embedded-id validity (content-rendered dumps), and healed-equals-forced
# support components; the named refusals (struct edit target, lattice+struct,
# negation+struct) are permanent.  Each case compares settled content and
# every support component against a lazy heal plus a forced fresh recount
# (§10's two oracles); the recounts before the first post-edit dump-counts
# are lazy no-ops on the precise routes.
#
# These fixtures exposed (and their substrate fix closed) a real M5 hole:
# the greedy index packer could unify a struct's intern MASTER ordering with
# a permuted probe selection, so two flavors resident on one relation owned
# two disjoint "masters" -- clear-and-rerun walked the stale one, silently
# forgot the dictionary, and reminted every id; a count round after a
# delta-entry flush fataled on the same staleness.  The master assignment is
# now pinned canonical in every flavor (operationalization.rkt
# choose-indices), making the canonical master the one id-last ordering
# every resident flavor maintains.  Without that fix the diamond block below
# cannot even complete: its recount op fatals the daemon mid-drive.

# Struct diamond with tail: the m4t_diamond shape with a constructed pnode
# head.  Deleting edge(1,2) removes exactly spath/pnode (1,2); (1,4)
# survives on its 1-3-4 route (rec 2 -> 1) and (1,5) through it.  Ids must
# be stable across the sweep and the dead content must remain tombstoned.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4s_diamond.slog \
  batch+:edge,1,2 batch+:edge,2,4 batch+:edge,1,3 batch+:edge,3,4 \
  batch+:edge,4,5 flush \
  dump-rel:spath dump-ids:pnode recount dump-counts:spath dump-counts:pnode \
  batch-:edge,1,2 flush dump-rel:spath dump-ids:pnode \
  recount dump-counts:spath dump-counts:pnode \
  recount-force dump-counts:spath dump-counts:pnode \
  > out/sess-m4s-diamond.log 2>&1
expect "m4s-diamond-before" "(dumpdone 9)" out/sess-m4s-diamond.log
expect "m4s-diamond-ids-before" "(idsdone 9 0)" out/sess-m4s-diamond.log
expect "m4s-diamond-two-routes" "(countrow spath (pnode 1 4) 0 0 2)" out/sess-m4s-diamond.log
expect "m4s-diamond-ctor-coupled" "(countrow pnode (pnode 1 4) 0 0 2)" out/sess-m4s-diamond.log
# FLIPPED(M4S slice 2): the deletion runs the sweep -- (1,4) is over-deleted
# on foundation loss and reseeded from its surviving 1-3-4 support for BOTH
# relations (2 reseeds), (1,2)/(1,5) discard (4), and the rebuild relearns
# (1,5) through the reseeded (1,4), resurrecting its id.
expect "m4s-diamond-sweep-route" "(route maintain-recursive-negative 1)" out/sess-m4s-diamond.log
expect "m4s-diamond-reseeded" "(dred-reseeded 2 4)" out/sess-m4s-diamond.log
expect "m4s-diamond-rebuild" "(route maintain-positive 1)" out/sess-m4s-diamond.log
expect_not "m4s-diamond-no-rerun" "(route rerun" out/sess-m4s-diamond.log
expect "m4s-diamond-settled" "(update-committed 2 counts-valid)" out/sess-m4s-diamond.log
expect "m4s-diamond-after" "(dumpdone 8)" out/sess-m4s-diamond.log
expect "m4s-diamond-tombstoned" "(idsdone 8 1)" out/sess-m4s-diamond.log
# healed and forced recounts agree on every support component; (1,5) holds
# rec 1 before AND after, so its row appears in all three dumps
if [ "$(grep -cF '(countrow spath (pnode 1 4) 0 0 1)' out/sess-m4s-diamond.log)" -eq 2 ] \
   && [ "$(grep -cF '(countrow spath (pnode 1 5) 0 0 1)' out/sess-m4s-diamond.log)" -eq 3 ] \
   && [ "$(grep -cF '(countrow pnode (pnode 1 4) 0 0 1)' out/sess-m4s-diamond.log)" -eq 2 ] \
   && [ "$(grep -cF '(countrow spath (pnode 1 2)' out/sess-m4s-diamond.log)" -eq 1 ]; then
  echo "PASS m4s-diamond-maintained-equals-recount"; PASS=$((PASS+1))
else
  echo "FAIL m4s-diamond-maintained-equals-recount"; FAIL=$((FAIL+1))
fi
m4sd_1=$(grep -F '(idrow ' out/sess-m4s-diamond.log | head -9 | sort)
m4sd_2=$(grep -F '(idrow ' out/sess-m4s-diamond.log | tail -8 | sort)
m4sd_sub=ok
while IFS= read -r l; do
  [ -n "$l" ] && { printf '%s\n' "$m4sd_1" | grep -qFx "$l" || m4sd_sub=bad; }
done <<< "$m4sd_2"
if [ -n "$m4sd_2" ] && [ "$m4sd_sub" = ok ]; then
  echo "PASS m4s-diamond-ids-stable"; PASS=$((PASS+1))
else
  echo "FAIL m4s-diamond-ids-stable (ids reminted across fallback)"; FAIL=$((FAIL+1))
fi

# Recursive construction self-join: closure constructing sedge terms over a
# 3-cycle; cutting the cycle strands 6 of 9 contents.  The re-add leg is the
# strongest identity pin: every tombstone must be consumed back to its
# ORIGINAL id ((idsdone 9 0) twice, identical id sets).
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4s_selfjoin.slog \
  batch+:r0,1,2 batch+:r0,2,3 batch+:r0,3,1 flush \
  dump-rel:sr dump-ids:sedge recount dump-counts:sr \
  batch-:r0,1,2 flush dump-rel:sr dump-ids:sedge \
  recount dump-counts:sr dump-counts:sedge \
  recount-force dump-counts:sr dump-counts:sedge \
  batch+:r0,1,2 flush dump-ids:sedge \
  > out/sess-m4s-selfjoin.log 2>&1
expect "m4s-selfjoin-before" "(dumpdone 9)" out/sess-m4s-selfjoin.log
expect "m4s-selfjoin-dense" "(countrow sr (sedge 2 1) 0 0 3)" out/sess-m4s-selfjoin.log
# FLIPPED(M4S slice 2): the cut runs the sweep; the rec-founded survivor
# (2,1) is over-deleted and reseeded for BOTH relations (2 reseeds, 12
# discards), and the re-add leg resurrects every tombstone to its original
# id -- the follow-up decrements of late rounds land on ids only the
# dictionary still knows (join-tomb resolution).
expect "m4s-selfjoin-sweep-route" "(route maintain-recursive-negative 1)" out/sess-m4s-selfjoin.log
expect "m4s-selfjoin-reseeded" "(dred-reseeded 2 12)" out/sess-m4s-selfjoin.log
expect_not "m4s-selfjoin-no-rerun" "(route rerun" out/sess-m4s-selfjoin.log
expect "m4s-selfjoin-after" "(dumpdone 3)" out/sess-m4s-selfjoin.log
expect "m4s-selfjoin-tombstoned" "(idsdone 3 6)" out/sess-m4s-selfjoin.log
if [ "$(grep -cF '(countrow sr (sedge 2 1) 0 0 1)' out/sess-m4s-selfjoin.log)" -eq 2 ] \
   && [ "$(grep -cF '(countrow sr (sedge 2 3) 0 1 0)' out/sess-m4s-selfjoin.log)" -eq 2 ] \
   && [ "$(grep -cF '(countrow sr (sedge 3 1) 0 1 0)' out/sess-m4s-selfjoin.log)" -eq 2 ] \
   && [ "$(grep -cF '(countrow sedge (sedge 2 1) 0 0 1)' out/sess-m4s-selfjoin.log)" -eq 2 ]; then
  echo "PASS m4s-selfjoin-maintained-equals-recount"; PASS=$((PASS+1))
else
  echo "FAIL m4s-selfjoin-maintained-equals-recount"; FAIL=$((FAIL+1))
fi
if [ "$(grep -cF '(idsdone 9 0)' out/sess-m4s-selfjoin.log)" -eq 2 ]; then
  echo "PASS m4s-selfjoin-all-resurrected"; PASS=$((PASS+1))
else
  echo "FAIL m4s-selfjoin-all-resurrected (tombstones left after re-add)"; FAIL=$((FAIL+1))
fi
m4ssj_1=$(grep -F '(idrow ' out/sess-m4s-selfjoin.log | head -9 | sort)
m4ssj_2=$(grep -F '(idrow ' out/sess-m4s-selfjoin.log | sed -n '10,12p' | sort)
m4ssj_3=$(grep -F '(idrow ' out/sess-m4s-selfjoin.log | tail -9 | sort)
m4ssj_sub=ok
while IFS= read -r l; do
  [ -n "$l" ] && { printf '%s\n' "$m4ssj_1" | grep -qFx "$l" || m4ssj_sub=bad; }
done <<< "$m4ssj_2"
if [ -n "$m4ssj_1" ] && [ "$m4ssj_1" = "$m4ssj_3" ] && [ "$m4ssj_sub" = ok ]; then
  echo "PASS m4s-selfjoin-ids-stable"; PASS=$((PASS+1))
else
  echo "FAIL m4s-selfjoin-ids-stable (ids reminted across cut/re-add)"; FAIL=$((FAIL+1))
fi

# Foundation-aware overlay composing with struct heads (M4S slice 2): the
# edit targets hop -- a plain int table dynamic in the recursive stratum --
# via set-overlay-negative-dred, while mk maintains in the acyclic stratum
# downstream.  Completing the 3-cycle by direct assertion explodes the
# closure to 9; the retraction enters candidacy at apply, the sweep
# discards the 6 unfounded rows and reseeds (1,3); mk keeps its ids
# (3 live + 6 tombstones); the re-assertion resurrects all nine originals.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4s_dredhead.slog \
  batch+:r0,1,2 batch+:r0,2,3 flush dump-rel:out dump-ids:mk \
  batch+:hop,3,1 flush dump-rel:out dump-ids:mk \
  batch-:hop,3,1 flush dump-rel:out dump-ids:mk \
  recount dump-counts:out dump-counts:mk \
  recount-force dump-counts:out dump-counts:mk \
  batch+:hop,3,1 flush dump-ids:mk \
  > out/sess-m4s-dredhead.log 2>&1
expect "m4s-dredhead-apply-verb" "(overlay-negative-dred hop 1 1)" out/sess-m4s-dredhead.log
expect "m4s-dredhead-sweep-route" "(route maintain-recursive-negative 2)" out/sess-m4s-dredhead.log
expect "m4s-dredhead-reseeded" "(dred-reseeded 1 6)" out/sess-m4s-dredhead.log
expect_not "m4s-dredhead-no-rerun" "(route rerun" out/sess-m4s-dredhead.log
expect "m4s-dredhead-exploded" "(dumpdone 9)" out/sess-m4s-dredhead.log
expect "m4s-dredhead-collapsed" "(idsdone 3 6)" out/sess-m4s-dredhead.log
if [ "$(grep -cF '(countrow out (mk 1 3) 0 1 0)' out/sess-m4s-dredhead.log)" -eq 2 ] \
   && [ "$(grep -cF '(countrow mk (mk 1 3) 0 1 0)' out/sess-m4s-dredhead.log)" -eq 2 ]; then
  echo "PASS m4s-dredhead-maintained-equals-recount"; PASS=$((PASS+1))
else
  echo "FAIL m4s-dredhead-maintained-equals-recount"; FAIL=$((FAIL+1))
fi
# id stability: the 9-id set after the explosion equals the set after the
# re-add, and the 3 survivors are a subset of it throughout
m4sdh_1=$(grep -F '(idrow ' out/sess-m4s-dredhead.log | sed -n '4,12p' | sort)
m4sdh_2=$(grep -F '(idrow ' out/sess-m4s-dredhead.log | sed -n '13,15p' | sort)
m4sdh_3=$(grep -F '(idrow ' out/sess-m4s-dredhead.log | tail -9 | sort)
m4sdh_sub=ok
while IFS= read -r l; do
  [ -n "$l" ] && { printf '%s\n' "$m4sdh_1" | grep -qFx "$l" || m4sdh_sub=bad; }
done <<< "$m4sdh_2"
if [ -n "$m4sdh_1" ] && [ "$m4sdh_1" = "$m4sdh_3" ] && [ "$m4sdh_sub" = ok ]; then
  echo "PASS m4s-dredhead-ids-stable"; PASS=$((PASS+1))
else
  echo "FAIL m4s-dredhead-ids-stable (ids reminted across sweep/relearn)"; FAIL=$((FAIL+1))
fi

# Pass-through chain (p P) --> (q (bar P)): q rows embed bar ids, bar rows
# embed foo ids.  After each settlement every embedded id must decode to its
# live struct row -- a dangling id renders as garbage (e.g. 0.0 fields),
# never as the constructed content.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4s_chain.slog \
  batch+:in,1 batch+:in,2 batch+:in,3 flush \
  dump-rel:q dump-ids:foo dump-ids:bar \
  batch-:in,2 batch+:in,4 flush dump-rel:p dump-rel:q dump-ids:foo dump-ids:bar \
  batch-:in,3 flush dump-rel:q dump-ids:foo dump-ids:bar \
  recount dump-counts:q recount-force dump-counts:q \
  > out/sess-m4s-chain.log 2>&1
# FLIPPED(M4S slice 1): the mixed and negative flushes take the acyclic
# maintenance routes.
expect "m4s-chain-negative-route" "(route maintain-negative 2)" out/sess-m4s-chain.log
expect "m4s-chain-positive-route" "(route maintain-positive 2)" out/sess-m4s-chain.log
expect_not "m4s-chain-no-rerun" "(route rerun" out/sess-m4s-chain.log
expect "m4s-chain-settled" "(update-committed 3 counts-valid)" out/sess-m4s-chain.log
# embedded-id decode walk: 3 + 3 + 2 nested q renderings, one p dump, and
# never a dangling-id rendering
if [ "$(grep -cF 'dumprow (bar (foo ' out/sess-m4s-chain.log)" -eq 8 ] \
   && [ "$(grep -cF '(dumprow (foo 4))' out/sess-m4s-chain.log)" -eq 1 ] \
   && ! grep -F '(dumprow ' out/sess-m4s-chain.log | grep -qF '0.0'; then
  echo "PASS m4s-chain-embedded-ids-decode"; PASS=$((PASS+1))
else
  echo "FAIL m4s-chain-embedded-ids-decode (dangling embedded id)"; FAIL=$((FAIL+1))
fi
expect "m4s-chain-swap-tombstones" "(idsdone 3 1)" out/sess-m4s-chain.log
expect "m4s-chain-final-tombstones" "(idsdone 2 2)" out/sess-m4s-chain.log
if [ "$(grep -cF '(countrow q (bar (foo 1)) 0 1 0)' out/sess-m4s-chain.log)" -eq 2 ] \
   && [ "$(grep -cF '(countrow q (bar (foo 4)) 0 1 0)' out/sess-m4s-chain.log)" -eq 2 ]; then
  echo "PASS m4s-chain-maintained-equals-recount"; PASS=$((PASS+1))
else
  echo "FAIL m4s-chain-maintained-equals-recount"; FAIL=$((FAIL+1))
fi
# foo id stability: dumps are foo(3), bar(3), foo(3), bar(3), foo(2), bar(2)
m4sc_foo1=$(grep -F '(idrow ' out/sess-m4s-chain.log | sed -n '1,3p' | sort)
m4sc_foo2=$(grep -F '(idrow ' out/sess-m4s-chain.log | sed -n '7,9p' | sort)
m4sc_foo3=$(grep -F '(idrow ' out/sess-m4s-chain.log | sed -n '13,14p' | sort)
m4sc_kept=$(comm -12 <(printf '%s\n' "$m4sc_foo1") <(printf '%s\n' "$m4sc_foo2") | grep -c '(idrow ')
m4sc_sub=ok
while IFS= read -r l; do
  [ -n "$l" ] && { printf '%s\n' "$m4sc_foo2" | grep -qFx "$l" || m4sc_sub=bad; }
done <<< "$m4sc_foo3"
if [ "$m4sc_kept" -eq 2 ] && [ -n "$m4sc_foo3" ] && [ "$m4sc_sub" = ok ]; then
  echo "PASS m4s-chain-ids-stable"; PASS=$((PASS+1))
else
  echo "FAIL m4s-chain-ids-stable (survivor foo ids reminted)"; FAIL=$((FAIL+1))
fi

# Multi-constructor support: identical content (mk 7) constructed by two
# rules.  Deleting one input is a support-only decrement (row stays live,
# SAME id, nonrec 2 -> 1); deleting both tombstones it.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4s_multictor.slog \
  batch+:a,7 batch+:b,7 flush dump-rel:out dump-ids:mk \
  recount dump-counts:out dump-counts:mk \
  batch-:a,7 flush dump-rel:out dump-ids:mk \
  recount dump-counts:out dump-counts:mk \
  recount-force dump-counts:out dump-counts:mk \
  batch-:b,7 flush dump-rel:out dump-ids:mk \
  > out/sess-m4s-multictor.log 2>&1
expect "m4s-multictor-two-ctors" "(countrow out (mk 7) 0 2 0)" out/sess-m4s-multictor.log
expect "m4s-multictor-struct-two" "(countrow mk (mk 7) 0 2 0)" out/sess-m4s-multictor.log
# FLIPPED(M4S slice 1): both deletions take the acyclic negative route; the
# first is a support-only decrement, the second a last-support tombstone.
if [ "$(grep -cF '(route maintain-negative 1)' out/sess-m4s-multictor.log)" -eq 2 ]; then
  echo "PASS m4s-multictor-precise-routes"; PASS=$((PASS+1))
else
  echo "FAIL m4s-multictor-precise-routes"; FAIL=$((FAIL+1))
fi
expect_not "m4s-multictor-no-rerun" "(route rerun" out/sess-m4s-multictor.log
if [ "$(grep -cF '(countrow out (mk 7) 0 1 0)' out/sess-m4s-multictor.log)" -eq 2 ] \
   && [ "$(grep -cF '(countrow mk (mk 7) 0 1 0)' out/sess-m4s-multictor.log)" -eq 2 ]; then
  echo "PASS m4s-multictor-support-only"; PASS=$((PASS+1))
else
  echo "FAIL m4s-multictor-support-only"; FAIL=$((FAIL+1))
fi
if [ "$(grep -cF '(dumpdone 1)' out/sess-m4s-multictor.log)" -eq 2 ] \
   && grep -qF '(dumpdone 0)' out/sess-m4s-multictor.log; then
  echo "PASS m4s-multictor-contents"; PASS=$((PASS+1))
else
  echo "FAIL m4s-multictor-contents"; FAIL=$((FAIL+1))
fi
expect "m4s-multictor-live-kept" "(idsdone 1 0)" out/sess-m4s-multictor.log
expect "m4s-multictor-final-tombstone" "(idsdone 0 1)" out/sess-m4s-multictor.log
if [ "$(grep -F '(idrow ' out/sess-m4s-multictor.log | sort -u | wc -l)" -eq 1 ] \
   && [ "$(grep -cF '(idrow ' out/sess-m4s-multictor.log)" -eq 2 ]; then
  echo "PASS m4s-multictor-id-stable"; PASS=$((PASS+1))
else
  echo "FAIL m4s-multictor-id-stable (id changed on support-only decrement)"; FAIL=$((FAIL+1))
fi

# Mixed-sign epoch: from a = {7}, b = {}, one flush {-a(7), +b(7)} kills and
# revives (mk 7) inside a single update epoch; the id must survive
# (within-epoch resurrection, M5) and the support word swaps constructor
# without changing value.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4s_multictor.slog \
  batch+:a,7 flush dump-ids:mk recount dump-counts:out \
  batch-:a,7 batch+:b,7 flush dump-rel:out dump-ids:mk \
  recount dump-counts:out recount-force dump-counts:out \
  > out/sess-m4s-mixedsign.log 2>&1
# FLIPPED(M4S slice 1): one epoch runs the negative walk (tombstone) then the
# positive walk (within-epoch resurrection, M5).
expect "m4s-mixedsign-negative-route" "(route maintain-negative 1)" out/sess-m4s-mixedsign.log
expect "m4s-mixedsign-positive-route" "(route maintain-positive 1)" out/sess-m4s-mixedsign.log
expect_not "m4s-mixedsign-no-rerun" "(route rerun" out/sess-m4s-mixedsign.log
expect "m4s-mixedsign-settled" "(update-committed 2 counts-valid)" out/sess-m4s-mixedsign.log
expect "m4s-mixedsign-live" "(dumpdone 1)" out/sess-m4s-mixedsign.log
if [ "$(grep -cF '(idsdone 1 0)' out/sess-m4s-mixedsign.log)" -eq 2 ] \
   && [ "$(grep -F '(idrow ' out/sess-m4s-mixedsign.log | sort -u | wc -l)" -eq 1 ]; then
  echo "PASS m4s-mixedsign-id-survives"; PASS=$((PASS+1))
else
  echo "FAIL m4s-mixedsign-id-survives (id lost across in-epoch kill/revive)"; FAIL=$((FAIL+1))
fi
if [ "$(grep -cF '(countrow out (mk 7) 0 1 0)' out/sess-m4s-mixedsign.log)" -eq 3 ]; then
  echo "PASS m4s-mixedsign-ctor-swap-counts"; PASS=$((PASS+1))
else
  echo "FAIL m4s-mixedsign-ctor-swap-counts"; FAIL=$((FAIL+1))
fi

# Import-then-edit over an admissible cone (the m5-keep shape minus the
# lattice): the frozen payload's (out (pair 7 8)) is direct input and so
# is its struct heap -- the pair row's foundation is the input LEDGER, not a
# constructor.  The deletion takes the precise route; the imported row's
# embedded id stays valid throughout.
rm -rf out/sess-m4s-import-db
{
  echo '(struct pair 2)'
  echo '(table out 1)'
  echo '(out (pair 7 8))'
} > out/sess-m4s-import.facts
timeout 600 racket -e '
(require "compiler/tools.rkt" racket/file)
(run-freezer "out/sess-m4s-import-db" (file->string "out/sess-m4s-import.facts"))
(displayln "frozen-ok")' > out/sess-m4s-import-freeze.log 2>&1
expect "m4s-import-freeze" "frozen-ok" out/sess-m4s-import-freeze.log
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4s_import.slog \
  batch+:in,1,2 batch+:in,3,4 flush \
  import-delta:out/sess-m4s-import-db \
  dump-ids:pair dump-rel:out recount dump-counts:pair dump-counts:out \
  input-ledger \
  batch-:in,3,4 flush dump-ids:pair dump-rel:out \
  recount dump-counts:pair dump-counts:out \
  recount-force dump-counts:pair dump-counts:out \
  > out/sess-m4s-import.log 2>&1
expect "m4s-import-populated" "(idsdone 3 0)" out/sess-m4s-import.log
expect "m4s-import-ledger-heap" "pair (pair 7 8) 7 8)" out/sess-m4s-import.log
expect "m4s-import-ledger-row" "out (pair 7 8))" out/sess-m4s-import.log
# FLIPPED(M4S slice 1): maintained deletion, no rerun -- the imported row's
# input-ledger foundation and embedded id survive a precise-route epoch.
expect "m4s-import-precise-route" "(route maintain-negative 1)" out/sess-m4s-import.log
expect_not "m4s-import-no-rerun" "(route rerun" out/sess-m4s-import.log
expect "m4s-import-tombstoned" "(idsdone 2 1)" out/sess-m4s-import.log
# the struct row's input foundation comes from the ledger: input bit set,
# no constructor support, before AND after (healed + forced)
if [ "$(grep -cF '(countrow pair (pair 7 8) 1 0 0)' out/sess-m4s-import.log)" -eq 3 ] \
   && [ "$(grep -cF '(countrow out (pair 7 8) 1 0 0)' out/sess-m4s-import.log)" -eq 3 ] \
   && [ "$(grep -cF '(countrow out (pair 1 2) 0 1 0)' out/sess-m4s-import.log)" -eq 3 ] \
   && [ "$(grep -cF '(countrow pair (pair 3 4) 0 1 0)' out/sess-m4s-import.log)" -eq 1 ]; then
  echo "PASS m4s-import-ledger-foundation"; PASS=$((PASS+1))
else
  echo "FAIL m4s-import-ledger-foundation"; FAIL=$((FAIL+1))
fi
# the imported row's embedded id decodes in the pre- and post-deletion dumps
if [ "$(grep -cF '(dumprow (pair 7 8))' out/sess-m4s-import.log)" -eq 2 ] \
   && [ "$(grep -cF '(dumpdone 2)' out/sess-m4s-import.log)" -eq 1 ]; then
  echo "PASS m4s-import-embedded-id-valid"; PASS=$((PASS+1))
else
  echo "FAIL m4s-import-embedded-id-valid (imported embedded id dangling)"; FAIL=$((FAIL+1))
fi
m4si_1=$(grep -F '(idrow ' out/sess-m4s-import.log | head -3 | sort)
m4si_2=$(grep -F '(idrow ' out/sess-m4s-import.log | tail -2 | sort)
m4si_sub=ok
while IFS= read -r l; do
  [ -n "$l" ] && { printf '%s\n' "$m4si_1" | grep -qFx "$l" || m4si_sub=bad; }
done <<< "$m4si_2"
if [ -n "$m4si_2" ] && [ "$m4si_sub" = ok ]; then
  echo "PASS m4s-import-ids-stable"; PASS=$((PASS+1))
else
  echo "FAIL m4s-import-ids-stable"; FAIL=$((FAIL+1))
fi

# --- M4S slice 3: persistence -- the chain is the sidecar --------------------
# Tombstones never persist: a save carries live content only, and a load
# rebuilds every struct dictionary's dead half -- recipe replay re-executes
# the same routes, and the reconstruct-tombstones chain pass closes the
# invariant independent of them (dict(v) = (live(pred) ∪ dict(pred)) −
# live(v); the formula itself is pinned by the structid unit battery).  A
# maintained session deletes (mk 8), saves, reopens: re-deriving the dead
# content must not leave a stale mapping (a remint against a retained
# tombstone would show (idsdone 2 1)), fresh content mints above the loaded
# allocators, and every embedded id decodes.  Tombstone COUNTS are
# deliberately never compared across the boundary (docs/m4s-contract.md).
rm -rf data/sess_m4s_persist
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4s_multictor.slog \
  batch+:a,7 batch+:a,8 flush dump-rel:out dump-ids:mk \
  batch-:a,8 flush dump-rel:out dump-ids:mk \
  save:sess_m4s_persist \
  > out/sess-m4s-persist-save.log 2>&1
expect "m4s-persist-maintained" "(route maintain-negative 1)" out/sess-m4s-persist-save.log
expect "m4s-persist-presave" "(idsdone 1 1)" out/sess-m4s-persist-save.log
expect "m4s-persist-saved" "(saved sess_m4s_persist" out/sess-m4s-persist-save.log
timeout 900 racket tests/api/session-drive.rkt \
  open:sess_m4s_persist dump-rel:out dump-ids:mk \
  batch+:b,8 flush dump-rel:out dump-ids:mk \
  batch+:a,9 flush dump-rel:out dump-ids:mk \
  > out/sess-m4s-persist-load.log 2>&1
expect "m4s-persist-replayed" "(replayed-recipe sess_m4s_persist" out/sess-m4s-persist-load.log
expect "m4s-persist-reconstructed" "(tombstones-reconstructed" out/sess-m4s-persist-load.log
expect "m4s-persist-loaded" "(dumprow (mk 7))" out/sess-m4s-persist-load.log
expect "m4s-persist-rederived-clean" "(idsdone 2 0)" out/sess-m4s-persist-load.log
expect "m4s-persist-rederived-decodes" "(dumprow (mk 8))" out/sess-m4s-persist-load.log
expect "m4s-persist-fresh" "(idsdone 3 0)" out/sess-m4s-persist-load.log
expect "m4s-persist-fresh-decodes" "(dumprow (mk 9))" out/sess-m4s-persist-load.log
if ! grep -F '(dumprow ' out/sess-m4s-persist-load.log | grep -qF '0.0'; then
  echo "PASS m4s-persist-embedded-ids-decode"; PASS=$((PASS+1))
else
  echo "FAIL m4s-persist-embedded-ids-decode (dangling embedded id)"; FAIL=$((FAIL+1))
fi

# --- M4S named fallbacks (permanent refusals and compositions) --------------
# An edit whose TARGET is a struct relation is refused (docs/m4s-contract.md
# keeps struct edit targets refused permanently, even after admission;
# import-delta is the vehicle for struct-embedding input).  The positive
# sign is refused BY NAME at set-overlay (the m6l lattice precedent):
# nothing applies and the session continues, so content and ids are
# asserted intact in the same drive.  The negative sign is refused BY NAME
# before any epoch or mutation: baseline normalization rejects the whole
# flush, and the misleading generic classification ("tuple is absent") is
# replaced by the struct-relation message on the error path.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4s_import.slog \
  batch+:in,1,2 flush \
  batch+:pair,9,9 flush dump-rel:out dump-ids:pair \
  > out/sess-m4s-editstruct-add.log 2>&1
expect "m4s-editstruct-add-refused-by-name" \
  '(error "set-overlay: pair is a lattice/struct relation")' \
  out/sess-m4s-editstruct-add.log
expect "m4s-editstruct-add-content-intact" "(dumpdone 1)" out/sess-m4s-editstruct-add.log
expect "m4s-editstruct-add-ids-intact" "(idsdone 1 0)" out/sess-m4s-editstruct-add.log
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4s_import.slog \
  batch+:in,1,2 flush \
  batch-:pair,1,2 flush \
  > out/sess-m4s-editstruct-del.log 2>&1
expect "m4s-editstruct-del-refused" \
  "cannot retract (1 2) from pair: pair is a struct relation" \
  out/sess-m4s-editstruct-del.log
expect "m4s-editstruct-del-before-epoch" "(update-committed 1 " out/sess-m4s-editstruct-del.log
expect_not "m4s-editstruct-del-unapplied" "(update-begun 1)" out/sess-m4s-editstruct-del.log

# Lattice INSIDE the struct cone: refused by name under M4S (M6L/M7 own the
# shape); the rerun must regress score's key 1 from 7 back to 5 -- only a
# rerun can lower a lattice payload today.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4s_latstruct.slog \
  batch+:in,1,5 batch+:in,1,7 batch+:in,2,3 flush \
  dump-rel:out dump-tuples:score dump-ids:pair \
  batch-:in,1,7 flush dump-rel:out dump-tuples:score dump-ids:pair \
  > out/sess-m4s-latstruct.log 2>&1
expect "m4s-latstruct-max-before" "(tuplerow 1 7)" out/sess-m4s-latstruct.log
expect "m4s-latstruct-fallback" "(route rerun 1 3)" out/sess-m4s-latstruct.log
expect_not "m4s-latstruct-no-maintain" "(route maintain" out/sess-m4s-latstruct.log
expect "m4s-latstruct-regressed" "(tuplerow 1 5)" out/sess-m4s-latstruct.log
expect "m4s-latstruct-out-shrunk" "(dumpdone 2)" out/sess-m4s-latstruct.log
expect "m4s-latstruct-tombstoned" "(idsdone 2 1)" out/sess-m4s-latstruct.log

# Negation INSIDE the struct cone: refused by name under M4S (M4N owns
# anti-deltas); the complement recomputes exactly (blocked GROWS 2 -> 3).
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4s_negstruct.slog \
  batch+:in,1,1 batch+:in,2,5 flush \
  dump-rel:out dump-rel:blocked dump-ids:pair \
  batch-:in,1,1 flush dump-rel:out dump-rel:blocked dump-ids:pair \
  > out/sess-m4s-negstruct.log 2>&1
if [ "$(grep -cF '(route rerun 1 3)' out/sess-m4s-negstruct.log)" -eq 2 ]; then
  echo "PASS m4s-negstruct-fallback-routes"; PASS=$((PASS+1))
else
  echo "FAIL m4s-negstruct-fallback-routes"; FAIL=$((FAIL+1))
fi
expect_not "m4s-negstruct-no-maintain" "(route maintain" out/sess-m4s-negstruct.log
expect "m4s-negstruct-complement-before" "(dumpdone 2)" out/sess-m4s-negstruct.log
expect "m4s-negstruct-complement-grown" "(dumpdone 3)" out/sess-m4s-negstruct.log
expect "m4s-negstruct-survivor" "(dumprow (pair 2 5))" out/sess-m4s-negstruct.log
expect "m4s-negstruct-tombstoned" "(idsdone 1 1)" out/sess-m4s-negstruct.log

# --- M4N slice 1: acyclic negated reads of edited inputs --------------------
# (docs/m4n-contract.md pins 3-5.)  The changed negated inputs are finalized
# upfront (both overlay signs), each phase then stages their opposite-sign
# journal as anti-delta drives and same-sign as view-only rows.  Four
# flushes exercise every partition-table case: initial build, gained
# blocker, lost blocker, and a mixed flush churning BOTH a positive premise
# and a blocker (including the sibling ~b/~c pre/post split on hs).
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4n_acyclic.slog \
  batch+:a,1 batch+:a,2 batch+:a,3 batch+:b,2 batch+:c,3 flush \
  dump-rel:h dump-rel:hs dump-rel:down \
  batch+:b,1 flush dump-rel:h dump-rel:hs dump-rel:down \
  batch-:b,2 flush dump-rel:h dump-rel:hs dump-rel:down \
  batch-:b,1 batch+:b,3 batch+:a,4 batch-:a,2 flush \
  dump-rel:h dump-rel:hs dump-rel:down \
  dump-counts:h dump-counts:hs recount-force dump-counts:h dump-counts:hs \
  pipeline input-ledger dump-all-counts \
  > out/sess-m4n-acyclic.log 2>&1
if [ "$(grep -cE '\(route maintain-negated-negative [0-9]+ [0-9]+\)' out/sess-m4n-acyclic.log)" -eq 4 ] \
   && [ "$(grep -cE '\(route maintain-negated-positive [0-9]+ [0-9]+\)' out/sess-m4n-acyclic.log)" -eq 4 ] \
   && [ "$(grep -cE '\(route maintain-negated-negative [0-9]+ 2\)' out/sess-m4n-acyclic.log)" -eq 1 ]; then
  echo "PASS m4n-routes"; PASS=$((PASS+1))
else
  echo "FAIL m4n-routes"; FAIL=$((FAIL+1))
fi
expect_not "m4n-no-rerun" "(route rerun" out/sess-m4n-acyclic.log
expect "m4n-settled" "(update-committed 4 counts-valid)" out/sess-m4n-acyclic.log
if [ "$(grep -cF '(dumpdone 2)' out/sess-m4n-acyclic.log)" -eq 7 ] \
   && [ "$(grep -cF '(dumpdone 1)' out/sess-m4n-acyclic.log)" -eq 4 ] \
   && [ "$(grep -cF '(dumpdone 0)' out/sess-m4n-acyclic.log)" -eq 1 ]; then
  echo "PASS m4n-set-content"; PASS=$((PASS+1))
else
  echo "FAIL m4n-set-content"; FAIL=$((FAIL+1))
fi
versioned_count_oracle "m4n-acyclic-ir-oracle" out/sess-m4n-acyclic.log
if [ "$(grep -cF '(countrow h 1 0 1 0)' out/sess-m4n-acyclic.log)" -eq 2 ] \
   && [ "$(grep -cF '(countrow h 4 0 1 0)' out/sess-m4n-acyclic.log)" -eq 2 ] \
   && [ "$(grep -cF '(countrow hs 1 0 1 0)' out/sess-m4n-acyclic.log)" -eq 2 ] \
   && [ "$(grep -cF '(countrow hs 4 0 1 0)' out/sess-m4n-acyclic.log)" -eq 2 ] \
   && [ "$(grep -cF '(countdone h 2)' out/sess-m4n-acyclic.log)" -eq 2 ]; then
  echo "PASS m4n-maintained-equals-recount"; PASS=$((PASS+1))
else
  echo "FAIL m4n-maintained-equals-recount"; FAIL=$((FAIL+1))
fi

# Named fallbacks.  A wildcard'd negated read of the changed relation
# carries 'negw: prefix absence is not maintainable from row transitions.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4n_negw.slog \
  batch+:a,1 batch+:pair,1,2 flush \
  batch-:pair,1,2 flush dump-rel:hw \
  > out/sess-m4n-negw.log 2>&1
if [ "$(grep -cF '(route rerun' out/sess-m4n-negw.log)" -eq 2 ]; then
  echo "PASS m4n-negw-fallback"; PASS=$((PASS+1))
else
  echo "FAIL m4n-negw-fallback"; FAIL=$((FAIL+1))
fi
expect_not "m4n-negw-no-maintain" "(route maintain-negated" out/sess-m4n-negw.log
expect "m4n-negw-content" "(dumpdone 1)" out/sess-m4n-negw.log

# A DERIVED negated relation (M4N slice 3): the producer prefix is
# maintained precisely in both flushes; the first flush GAINS a reader
# positive (+b rows), so the reader suffix reruns; the second flush is
# loss-only and the readers take the precise phases from m's MAINTAINED
# journal.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4n_derived.slog \
  batch+:a,1 batch+:b,1 batch+:b,2 flush \
  batch-:a,1 flush dump-rel:g \
  > out/sess-m4n-derived.log 2>&1
expect "m4n-derived-gains-detected" "(maintenance-unavailable reader-positive-gains)" out/sess-m4n-derived.log
expect "m4n-derived-suffix-rerun" "(route maintain-producers-rerun-readers 1 1 1)" out/sess-m4n-derived.log
expect "m4n-derived-precise-neg" "(route maintain-negated-derived-negative 1 1)" out/sess-m4n-derived.log
expect "m4n-derived-precise-pos" "(route maintain-negated-derived-positive 1 1)" out/sess-m4n-derived.log
expect_not "m4n-derived-no-full-rerun" "(route rerun" out/sess-m4n-derived.log
expect "m4n-derived-content" "(dumpdone 2)" out/sess-m4n-derived.log

# A relation read BOTH positively and negatively in the cone falls back:
# slice 1 requires the changed negated relation's reads to be exactly ~.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4n_mixedread.slog \
  batch+:a,1 batch+:b,2 flush \
  batch-:b,2 flush dump-rel:h dump-rel:m \
  > out/sess-m4n-mixedread.log 2>&1
if [ "$(grep -cF '(route rerun' out/sess-m4n-mixedread.log)" -eq 2 ]; then
  echo "PASS m4n-mixedread-fallback"; PASS=$((PASS+1))
else
  echo "FAIL m4n-mixedread-fallback"; FAIL=$((FAIL+1))
fi
expect_not "m4n-mixedread-no-maintain" "(route maintain-negated" out/sess-m4n-mixedread.log
expect "m4n-mixedread-h" "(dumpdone 1)" out/sess-m4n-mixedread.log
expect "m4n-mixedread-m" "(dumpdone 0)" out/sess-m4n-mixedread.log

# Under SLOG_FLAVORED_NATIVE the anti-delta variants have no native leg,
# so admission itself must decline (before forcing any flavored build).
SLOG_FLAVORED_NATIVE=1 timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4n_acyclic.slog \
  batch+:a,1 batch+:b,2 flush dump-rel:h \
  > out/sess-m4n-native-fallback.log 2>&1
expect "m4n-native-fallback" "(route rerun" out/sess-m4n-native-fallback.log
expect_not "m4n-native-no-maintain" "(route maintain-negated" out/sess-m4n-native-fallback.log
expect "m4n-native-content" "(dumpdone 1)" out/sess-m4n-native-fallback.log

# --- M4N slice 2: recursive readers over edited negated inputs --------------
# (docs/m4n-contract.md slice 2, ratified 2026-07-21.)  The sweep schedule
# with negated staging: +blk kills base rows and cascades across rounds
# (the round-3 corpse fire against blk(4) must be excluded by absent-ever
# or r(1,4) is double-decremented and the epoch goes counts-invalid);
# -blk relearns through the rebuild's anti-delta drive; the mixed flush
# churns a positive premise AND a blocker in one epoch.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4n_sweep.slog \
  batch+:e,1,2 batch+:e,2,3 batch+:e,3,4 flush dump-rel:r \
  batch+:blk,3 flush dump-rel:r dump-counts:r \
  batch-:blk,3 flush dump-rel:r \
  batch-:e,1,2 batch+:blk,4 flush dump-rel:r \
  dump-counts:r recount-force dump-counts:r \
  pipeline input-ledger dump-all-counts \
  > out/sess-m4n-sweep.log 2>&1
expect "m4n-sweep-initial-route" "(route maintain 1)" out/sess-m4n-sweep.log
if [ "$(grep -cF '(route maintain-negated-recursive 1 1)' out/sess-m4n-sweep.log)" -eq 3 ] \
   && [ "$(grep -cF '(route maintain-negated-positive 1 1)' out/sess-m4n-sweep.log)" -eq 3 ]; then
  echo "PASS m4n-sweep-routes"; PASS=$((PASS+1))
else
  echo "FAIL m4n-sweep-routes"; FAIL=$((FAIL+1))
fi
expect_not "m4n-sweep-no-rerun" "(route rerun" out/sess-m4n-sweep.log
expect "m4n-sweep-gained-sweep" "(dred-reseeded 0 4)" out/sess-m4n-sweep.log
expect "m4n-sweep-settled" "(update-committed 4 counts-valid)" out/sess-m4n-sweep.log
if [ "$(grep -cF '(dumpdone 6)' out/sess-m4n-sweep.log)" -eq 2 ] \
   && [ "$(grep -cF '(dumpdone 2)' out/sess-m4n-sweep.log)" -eq 1 ] \
   && [ "$(grep -cF '(dumpdone 1)' out/sess-m4n-sweep.log)" -eq 1 ]; then
  echo "PASS m4n-sweep-content"; PASS=$((PASS+1))
else
  echo "FAIL m4n-sweep-content"; FAIL=$((FAIL+1))
fi
versioned_count_oracle "m4n-sweep-ir-oracle" out/sess-m4n-sweep.log
if [ "$(grep -cF '(countrow r 1 2 0 1 0)' out/sess-m4n-sweep.log)" -eq 1 ] \
   && [ "$(grep -cF '(countrow r 3 4 0 1 0)' out/sess-m4n-sweep.log)" -eq 1 ] \
   && [ "$(grep -cF '(countrow r 2 3 0 1 0)' out/sess-m4n-sweep.log)" -eq 2 ]; then
  echo "PASS m4n-sweep-maintained-equals-recount"; PASS=$((PASS+1))
else
  echo "FAIL m4n-sweep-maintained-equals-recount"; FAIL=$((FAIL+1))
fi

# Slice-4 fuzzer catch (the expired-witness bug): a lost premise AND a
# lost blocker in one sweep flush.  The round-2 corpse probe against the
# LOST blocker must witness it round-stably (the bind-time journal
# snapshot) -- through the staged delta indices the witness expires after
# round 1 and the phantom decrement poisons the epoch.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4n_sweep.slog \
  batch+:blk,3 batch+:e,0,1 batch+:e,1,3 flush dump-rel:r \
  batch-:e,0,1 batch-:blk,3 flush dump-rel:r \
  dump-counts:r recount-force dump-counts:r \
  > out/sess-m4n-lostwitness.log 2>&1
expect "m4n-lostwitness-route" "(route maintain-negated-recursive 1 1)" out/sess-m4n-lostwitness.log
expect "m4n-lostwitness-settled" "(update-committed 2 counts-valid)" out/sess-m4n-lostwitness.log
expect_not "m4n-lostwitness-no-rerun" "(route rerun" out/sess-m4n-lostwitness.log
if [ "$(grep -cF '(dumpdone 1)' out/sess-m4n-lostwitness.log)" -eq 2 ] \
   && [ "$(grep -cF '(countrow r 1 3 0 1 0)' out/sess-m4n-lostwitness.log)" -eq 2 ]; then
  echo "PASS m4n-lostwitness-counts"; PASS=$((PASS+1))
else
  echo "FAIL m4n-lostwitness-counts"; FAIL=$((FAIL+1))
fi

# Repeated swept occurrences beside the negated input: the 3-cycle closure
# (9 rows) loses exactly the rec-derived edges INTO the blocked node and
# their cascades (2 rows), and relearns them on unblock.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4n_sweep_selfjoin.slog \
  batch+:r0,1,2 batch+:r0,2,3 batch+:r0,3,1 flush dump-rel:r \
  batch+:blk,1 flush dump-rel:r dump-counts:r recount-force dump-counts:r \
  batch-:blk,1 flush dump-rel:r \
  > out/sess-m4n-sweep-selfjoin.log 2>&1
if [ "$(grep -cF '(dumpdone 9)' out/sess-m4n-sweep-selfjoin.log)" -eq 2 ] \
   && [ "$(grep -cF '(dumpdone 7)' out/sess-m4n-sweep-selfjoin.log)" -eq 1 ]; then
  echo "PASS m4n-sweep-selfjoin-content"; PASS=$((PASS+1))
else
  echo "FAIL m4n-sweep-selfjoin-content"; FAIL=$((FAIL+1))
fi
expect "m4n-sweep-selfjoin-route" "(route maintain-negated-recursive 1 1)" out/sess-m4n-sweep-selfjoin.log
expect "m4n-sweep-selfjoin-settled" "(update-committed 3 counts-valid)" out/sess-m4n-sweep-selfjoin.log
if [ "$(grep -cF '(countrow r 3 1 0 1 0)' out/sess-m4n-sweep-selfjoin.log)" -eq 2 ]; then
  echo "PASS m4n-sweep-selfjoin-counts"; PASS=$((PASS+1))
else
  echo "FAIL m4n-sweep-selfjoin-counts"; FAIL=$((FAIL+1))
fi

# Derived negated relation over RECURSIVE readers (M4N slice 3): the
# producers maintain precisely; the reader suffix reruns in both flushes
# (gains on the reader positive in the first, recursive readers in the
# second -- the precise recursive-reader composition is future work).
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4n_sweep_derived.slog \
  batch+:e,1,2 batch+:e,2,2 flush \
  batch-:e,2,2 flush dump-rel:r \
  > out/sess-m4n-sweep-derived.log 2>&1
if [ "$(grep -cF '(route maintain-producers-rerun-readers 1 1 1)' out/sess-m4n-sweep-derived.log)" -eq 2 ]; then
  echo "PASS m4n-sweep-derived-suffix-reruns"; PASS=$((PASS+1))
else
  echo "FAIL m4n-sweep-derived-suffix-reruns"; FAIL=$((FAIL+1))
fi
expect_not "m4n-sweep-derived-no-full-rerun" "(route rerun" out/sess-m4n-sweep-derived.log
expect "m4n-sweep-derived-content" "(dumpdone 1)" out/sess-m4n-sweep-derived.log

# --- M4N slice 3 track A: inheritance and masks across negative edges -------
# The M0.4 inherited-overlay path (inject-reopen: a successor version masks
# an inherited input tuple without mutating the predecessor) composed with
# the m4n routes: the masked relation IS the negated input, on both the
# acyclic route and the sweep.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4n_acyclic.slog \
  batch+:a,1 batch+:b,1 flush \
  inject-reopen:b,m4n-inherit,tests/session/m4n_acyclic.slog,9 \
  batch-:b,1 flush dump-rel:b dump-rel:h input-ledger dump-counts:h \
  recount-force dump-counts:h \
  > out/sess-m4n-inherit.log 2>&1
expect "m4n-inherit-route-neg" "(route maintain-negated-negative" out/sess-m4n-inherit.log
expect "m4n-inherit-route-pos" "(route maintain-negated-positive" out/sess-m4n-inherit.log
expect_not "m4n-inherit-no-rerun" "(route rerun" out/sess-m4n-inherit.log
expect "m4n-inherit-mask" "(inputledger mask" out/sess-m4n-inherit.log
if [ "$(grep -cF '(dumpdone 1)' out/sess-m4n-inherit.log)" -eq 2 ]; then
  echo "PASS m4n-inherit-content"; PASS=$((PASS+1))
else
  echo "FAIL m4n-inherit-content"; FAIL=$((FAIL+1))
fi
if [ "$(grep -cF '(countrow h 1 0 1 0)' out/sess-m4n-inherit.log)" -eq 2 ]; then
  echo "PASS m4n-inherit-counts"; PASS=$((PASS+1))
else
  echo "FAIL m4n-inherit-counts"; FAIL=$((FAIL+1))
fi

# The sweep variant: masking the inherited blocker relearns the blocked
# closure through the rebuild's anti-delta drive.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4n_sweep.slog \
  batch+:e,1,2 batch+:e,2,3 batch+:e,3,4 batch+:blk,3 flush dump-rel:r \
  inject-reopen:blk,m4n-sweep-inherit,tests/session/m4n_sweep.slog,9 \
  batch-:blk,3 flush dump-rel:r input-ledger dump-counts:r \
  recount-force dump-counts:r \
  > out/sess-m4n-sweep-inherit.log 2>&1
expect "m4n-sweep-inherit-route" "(route maintain-negated-recursive" out/sess-m4n-sweep-inherit.log
expect "m4n-sweep-inherit-relearn" "(route maintain-negated-positive" out/sess-m4n-sweep-inherit.log
expect_not "m4n-sweep-inherit-no-rerun" "(route rerun" out/sess-m4n-sweep-inherit.log
expect "m4n-sweep-inherit-mask" "(inputledger mask" out/sess-m4n-sweep-inherit.log
expect "m4n-sweep-inherit-before" "(dumpdone 2)" out/sess-m4n-sweep-inherit.log
expect "m4n-sweep-inherit-after" "(dumpdone 6)" out/sess-m4n-sweep-inherit.log
if [ "$(grep -cF '(countrow r 1 4 0 0 1)' out/sess-m4n-sweep-inherit.log)" -eq 2 ] \
   && [ "$(grep -cF '(countrow r 1 3 0 0 1)' out/sess-m4n-sweep-inherit.log)" -eq 2 ]; then
  echo "PASS m4n-sweep-inherit-counts"; PASS=$((PASS+1))
else
  echo "FAIL m4n-sweep-inherit-counts"; FAIL=$((FAIL+1))
fi

# --- M4N slice 3 track B: negation x demand ---------------------------------
# Downstream shape: the blocker's cone is one acyclic plain stratum (the
# demand SCC stays outside it), so the precise route admits.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4n_demand.slog \
  dump-rel:fibres batch+:blk,10 flush dump-rel:fibres dump-counts:fibres \
  recount-force dump-counts:fibres \
  batch-:blk,10 flush dump-rel:fibres \
  > out/sess-m4n-demand.log 2>&1
expect "m4n-demand-route" "(route maintain-negated-negative 1 1)" out/sess-m4n-demand.log
expect "m4n-demand-relearn" "(route maintain-negated-positive 1 1)" out/sess-m4n-demand.log
expect_not "m4n-demand-no-rerun" "(route rerun" out/sess-m4n-demand.log
if [ "$(grep -cF '(dumpdone 2)' out/sess-m4n-demand.log)" -eq 2 ] \
   && [ "$(grep -cF '(dumpdone 1)' out/sess-m4n-demand.log)" -eq 1 ]; then
  echo "PASS m4n-demand-content"; PASS=$((PASS+1))
else
  echo "FAIL m4n-demand-content"; FAIL=$((FAIL+1))
fi
if [ "$(grep -cF '(countrow fibres 7 13 0 1 0)' out/sess-m4n-demand.log)" -eq 2 ]; then
  echo "PASS m4n-demand-counts"; PASS=$((PASS+1))
else
  echo "FAIL m4n-demand-counts"; FAIL=$((FAIL+1))
fi

# Inside shape: the struct-backed demand SCC is in the blocker's cone --
# the pinned negation x structs exclusion refuses by name; rerun
# recomputes the demand fixpoint including retracting unshared demands.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4n_demand_inside.slog \
  batch+:blk,10 flush dump-rel:fibres \
  batch-:blk,10 flush dump-rel:fibres \
  > out/sess-m4n-demand-inside.log 2>&1
if [ "$(grep -cF '(route rerun' out/sess-m4n-demand-inside.log)" -eq 2 ]; then
  echo "PASS m4n-demand-inside-fallback"; PASS=$((PASS+1))
else
  echo "FAIL m4n-demand-inside-fallback"; FAIL=$((FAIL+1))
fi
expect_not "m4n-demand-inside-no-maintain" "(route maintain-negated" out/sess-m4n-demand-inside.log
if [ "$(grep -cF '(dumpdone 1)' out/sess-m4n-demand-inside.log)" -eq 1 ] \
   && [ "$(grep -cF '(dumpdone 2)' out/sess-m4n-demand-inside.log)" -eq 1 ]; then
  echo "PASS m4n-demand-inside-content"; PASS=$((PASS+1))
else
  echo "FAIL m4n-demand-inside-content"; FAIL=$((FAIL+1))
fi

# --- M4N slice 3: the mixed input+derived negation admission hole -----------
# A flush editing BOTH the negated input b and a2 (feeding derived ~m)
# must fall back (neither the edit-staging arms nor the pure-derived arm
# admits a mixed shape); a b-only flush keeps m outside the cone and
# stays precise.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m4n_mixed_negs.slog \
  batch+:a,1 batch+:a,2 batch+:b,1 flush dump-rel:h \
  batch+:b,2 batch+:a2,2 flush dump-rel:h \
  batch+:a,3 batch-:b,2 flush dump-rel:h \
  > out/sess-m4n-mixed-negs.log 2>&1
expect "m4n-mixed-negs-first-precise" "(route maintain-negated-negative" out/sess-m4n-mixed-negs.log
expect "m4n-mixed-negs-hole-closed" "(route rerun" out/sess-m4n-mixed-negs.log
expect_not "m4n-mixed-negs-no-derived" "(route maintain-negated-derived" out/sess-m4n-mixed-negs.log
if [ "$(grep -cF '(dumpdone 1)' out/sess-m4n-mixed-negs.log)" -eq 2 ] \
   && [ "$(grep -cF '(dumpdone 0)' out/sess-m4n-mixed-negs.log)" -eq 1 ]; then
  echo "PASS m4n-mixed-negs-content"; PASS=$((PASS+1))
else
  echo "FAIL m4n-mixed-negs-content"; FAIL=$((FAIL+1))
fi

# --- maintenance x body constants (found by M4N slice 3; latent since M1) ---
# Constant-bearing driver clauses hung every maintenance flavor (keyed
# delta-index probes never drain in a maintenance epoch).  Both signs must
# settle counts-valid on the precise routes.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m1_body_const.slog \
  batch+:p,1,5 batch+:a,5 flush dump-rel:h dump-counts:h \
  batch-:p,1,5 flush dump-rel:h \
  batch+:p,1,7 batch+:a,7 flush dump-rel:h recount-force dump-counts:h \
  > out/sess-m1-body-const.log 2>&1
expect "m1-body-const-add" "(route maintain 1)" out/sess-m1-body-const.log
expect "m1-body-const-del" "(route maintain-negative 1)" out/sess-m1-body-const.log
expect "m1-body-const-settled" "(update-committed 3 counts-valid)" out/sess-m1-body-const.log
if [ "$(grep -cF '(dumpdone 1)' out/sess-m1-body-const.log)" -eq 2 ] \
   && [ "$(grep -cF '(dumpdone 0)' out/sess-m1-body-const.log)" -eq 1 ]; then
  echo "PASS m1-body-const-content"; PASS=$((PASS+1))
else
  echo "FAIL m1-body-const-content"; FAIL=$((FAIL+1))
fi
if [ "$(grep -cF '(countrow h 5 0 1 0)' out/sess-m1-body-const.log)" -eq 1 ] \
   && [ "$(grep -cF '(countrow h 7 0 1 0)' out/sess-m1-body-const.log)" -eq 1 ]; then
  echo "PASS m1-body-const-counts"; PASS=$((PASS+1))
else
  echo "FAIL m1-body-const-counts"; FAIL=$((FAIL+1))
fi

# =========================================================================
# --- M7 sub-slice (a): recursive (same-SCC) lattice substrate -------------
# docs/m7-contract.md.  Retention establishes and CERTIFIES contributor
# state for the recursive min cone before route selection (the recount is
# version-local and transactional); routing still falls back.  Rank
# witnesses stamp first-derivation rounds (temp-staged rules stride two
# physical rounds per logical hop) and the rerun re-certifies them from
# empty.  Loser contributors subsumed before reaching the delta carry no
# forward stamp (lattice merge) -- repair derives those on demand, a
# pinned sub-slice (b) design point.
# FLIPPED(M7 sub-slice (b)): the deletion flush takes the stored-
# contributor repair fixpoint -- the maint4neg sweep runs the contributor
# candidate lifecycle with pessimistic retraction and old-value witnesses,
# dred-reseed re-asserts swept keys (dist regresses to the retained loser
# (1,3)->100), and the repair-mode positive rebuild re-derives downstream.
# No rerun; the contributor cache survives the flush.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m7_rec_min.slog \
  batch+:edge,1,2,10 batch+:edge,2,3,5 batch+:edge,3,1,2 \
  batch+:edge,1,3,100 batch+:edge,3,4,1 batch+:edge,2,4,20 batch+:edge,1,4,17 \
  flush dump-rel:dist rank-witness-state dump-ranks:dist \
  recount-lattices-force dump-counts:dist lattice-contributor-state \
  batch-:edge,2,3,5 flush dump-rel:dist rank-witness-state \
  recount-lattices-force dump-counts:dist lattice-contributor-state \
  > out/sess-m7-recmin.log 2>&1
if [ "$(grep -cF '(m7-retention (dist))' out/sess-m7-recmin.log)" -eq 2 ]; then
  echo "PASS m7-retention-fires"; PASS=$((PASS+1))
else
  echo "FAIL m7-retention-fires"; FAIL=$((FAIL+1))
fi
expect "m7-recmin-admitted" "(m7-admitted (lattices (dist)) (recursive 1) (strata 1))" out/sess-m7-recmin.log
expect "m7-recmin-repair-neg" "(route maintain-lattice-recursive-negative 1)" out/sess-m7-recmin.log
expect "m7-recmin-repair-pos" "(route maintain-lattice-recursive-positive 1)" out/sess-m7-recmin.log
expect_not "m7-recmin-no-rerun" "(route rerun" out/sess-m7-recmin.log
if [ "$(grep -cF '(lcnt dist 0 1)' out/sess-m7-recmin.log)" -ge 4 ]; then
  echo "PASS m7-recmin-certified"; PASS=$((PASS+1))
else
  echo "FAIL m7-recmin-certified"; FAIL=$((FAIL+1))
fi
expect "m7-recmin-contributors-pre" "(countdone dist 28)" out/sess-m7-recmin.log
expect "m7-recmin-contributors-post" "(countdone dist 18)" out/sess-m7-recmin.log
# loser retention: rule-1's (1,3)->100 keeps nonrec support while the
# recursive winner (1,3)->15 holds the visible value -- then the winner
# dies with the deleted edge and the loser IS the post-rerun value
if [ "$(grep -cF '(countrow dist 1 3 100 0 1 0)' out/sess-m7-recmin.log)" -eq 2 ] \
   && [ "$(grep -cF '(countrow dist 1 3 15 0 0 1)' out/sess-m7-recmin.log)" -eq 1 ]; then
  echo "PASS m7-recmin-loser-retained"; PASS=$((PASS+1))
else
  echo "FAIL m7-recmin-loser-retained"; FAIL=$((FAIL+1))
fi
# rank witnesses: valid after the initial from-empty run; the REPAIR epoch
# is a warm maintenance re-entry, so ranks go honestly invalid (as-built,
# m7-contract.md: DRed over-deletes every touched derived-only row, and a
# derivation-grain rank recompute needs the finer per-derivation
# contributor identity 7A.2 reserves -- per-derivation rank folds behind
# the repair seam are the deferred precise mechanism).  Transient count
# rounds no longer flip validity either way; dead rows' stamps erase.
if [ "$(grep -cF '(rnk dist 0 1)' out/sess-m7-recmin.log)" -eq 1 ] \
   && [ "$(grep -cF '(rnk dist 0 2)' out/sess-m7-recmin.log)" -eq 1 ]; then
  echo "PASS m7-recmin-ranks-honest"; PASS=$((PASS+1))
else
  echo "FAIL m7-recmin-ranks-honest"; FAIL=$((FAIL+1))
fi
if [ "$(grep -cF '(rankrow dist 1 3 100 1)' out/sess-m7-recmin.log)" -ge 1 ] \
   && [ "$(grep -cF '(rankrow dist 1 3 15 3)' out/sess-m7-recmin.log)" -eq 1 ] \
   && [ "$(grep -cF '(rankrow dist 1 1 17 5)' out/sess-m7-recmin.log)" -eq 1 ]; then
  echo "PASS m7-recmin-rank-depths"; PASS=$((PASS+1))
else
  echo "FAIL m7-recmin-rank-depths"; FAIL=$((FAIL+1))
fi
# the M7 repair schedule: candidate lifecycle visible in the reseed reply
expect "m7-recmin-reseed" "(dred-reseeded 0 0)" out/sess-m7-recmin.log
# candidate collapse + reseed: a contributor with foundation AND two
# recursive supports loses its foundation, survives as a reseeded
# candidate, and its downstream re-derives through repair staging
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m7_rec_min.slog \
  batch+:edge,1,2,10 batch+:edge,2,3,5 batch+:edge,1,5,7 batch+:edge,5,3,8 \
  batch+:edge,1,3,15 batch+:edge,3,4,1 \
  flush \
  batch-:edge,1,3,15 flush dump-rel:dist recount-lattices-force dump-counts:dist \
  batch-:edge,2,3,5 flush dump-rel:dist recount-lattices-force dump-counts:dist \
  > out/sess-m7-collapse.log 2>&1
if [ "$(grep -cF '(dred-reseeded 1 0)' out/sess-m7-collapse.log)" -eq 2 ] \
   && [ "$(grep -cF '(dumpdone 9)' out/sess-m7-collapse.log)" -eq 1 ] \
   && [ "$(grep -cF '(dumpdone 7)' out/sess-m7-collapse.log)" -eq 1 ] \
   && [ "$(grep -cF '(count-epoch-aborted)' out/sess-m7-collapse.log)" -eq 0 ]; then
  echo "PASS m7-collapse-reseed"; PASS=$((PASS+1))
else
  echo "FAIL m7-collapse-reseed"; FAIL=$((FAIL+1))
fi
expect_not "m7-collapse-no-rerun" "(route rerun" out/sess-m7-collapse.log
# 0-weight cycle: candidate absorbed to death, rec-only contributor
# lifecycle, and the unfounded 10<->11 pair dying with its last external
# feed -- foundedness held by pessimistic retraction + exact counting
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m7_rec_min.slog \
  batch+:edge,9,10,0 batch+:edge,10,11,0 batch+:edge,11,10,0 \
  batch+:edge,9,12,0 batch+:edge,12,10,0 \
  flush \
  batch-:edge,9,10,0 flush dump-rel:dist recount-lattices-force \
  batch-:edge,9,12,0 flush dump-rel:dist recount-lattices-force \
  batch-:edge,12,10,0 flush dump-rel:dist recount-lattices-force \
  > out/sess-m7-cycle0.log 2>&1
if [ "$(grep -cF '(dred-reseeded 1 0)' out/sess-m7-cycle0.log)" -eq 1 ] \
   && [ "$(grep -cF '(dumpdone 9)' out/sess-m7-cycle0.log)" -eq 1 ] \
   && [ "$(grep -cF '(dumpdone 6)' out/sess-m7-cycle0.log)" -eq 1 ] \
   && [ "$(grep -cF '(dumpdone 4)' out/sess-m7-cycle0.log)" -eq 1 ] \
   && [ "$(grep -cF '(count-epoch-aborted)' out/sess-m7-cycle0.log)" -eq 0 ]; then
  echo "PASS m7-cycle0-foundedness"; PASS=$((PASS+1))
else
  echo "FAIL m7-cycle0-foundedness"; FAIL=$((FAIL+1))
fi
expect_not "m7-cycle0-no-rerun" "(route rerun" out/sess-m7-cycle0.log

# --- M7 sub-slice (a): rank witnesses on a plain-table recursive cone -----
# Diamond/refound from incremental.md section 10's foundedness list, plus
# a symmetric cycle.  The initial from-empty run stamps exact ranks
# (path(1,4) = 2 via the diamond; first-seen-wins beats the rank-3 refound
# chain).  Deletion takes M4T's PRECISE sweep -- a maintenance epoch over
# warm content -- so rank witnesses go honestly INVALID (state 2), and
# as-built (m7-contract.md) they STAY so: DRed over-deletes every touched
# derived-only row (path(1,4) reseeds), so exact table ranks through a
# sweep need the deferred per-derivation rank folds.  The value-level
# unchanged skip is the operative re-fire exclusion (ratified 2026-07-24).
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m7_rank_diamond.slog \
  batch+:edge,1,2 batch+:edge,1,3 batch+:edge,2,4 batch+:edge,3,4 \
  batch+:edge,1,5 batch+:edge,5,6 batch+:edge,6,4 \
  batch+:edge,9,10 batch+:edge,10,11 batch+:edge,11,10 \
  flush rank-witness-state dump-ranks:path \
  batch-:edge,2,4 flush rank-witness-state \
  > out/sess-m7-rankdiamond.log 2>&1
expect "m7-diamond-ranks-valid" "(rnk path 0 1)" out/sess-m7-rankdiamond.log
expect "m7-diamond-rank-14" "(rankrow path 1 4 2)" out/sess-m7-rankdiamond.log
expect "m7-diamond-rank-refound" "(rankrow path 5 4 2)" out/sess-m7-rankdiamond.log
expect "m7-diamond-rank-cycle" "(rankrow path 9 11 2)" out/sess-m7-rankdiamond.log
expect "m7-diamond-rankcount" "(rankdone path 16)" out/sess-m7-rankdiamond.log
expect "m7-diamond-m4t-route" "(route maintain-recursive-negative 1)" out/sess-m7-rankdiamond.log
expect "m7-diamond-ranks-honest" "(rnk path 0 2)" out/sess-m7-rankdiamond.log

# --- M7 sub-slice (c): persistence -----------------------------------------
# Save a warm recursive-lattice session, reopen: the load re-establishes
# contributor state from the exact historical writers (certifying it), and
# the FIRST regression repairs precisely -- the contract's persistence
# fixture verbatim.
rm -rf data/sess_m7_reopen
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m7_rec_min.slog \
  batch+:edge,1,2,10 batch+:edge,2,3,5 batch+:edge,3,1,2 \
  batch+:edge,1,3,100 batch+:edge,3,4,1 batch+:edge,2,4,20 batch+:edge,1,4,17 \
  flush save:sess_m7_reopen \
  > out/sess-m7-save.log 2>&1
timeout 900 racket tests/api/session-drive.rkt \
  open:sess_m7_reopen lattice-contributor-state \
  batch-:edge,2,3,5 flush dump-rel:dist \
  recount-lattices-force dump-counts:dist lattice-contributor-state \
  > out/sess-m7-reopen.log 2>&1
expect "m7-reopen-starts-uncounted" "(lcnt dist 0 0)" out/sess-m7-reopen.log
expect "m7-reopen-establishes" "(m7-retention (dist))" out/sess-m7-reopen.log
expect "m7-reopen-repairs" "(route maintain-lattice-recursive-negative 1)" out/sess-m7-reopen.log
expect_not "m7-reopen-no-rerun" "(route rerun" out/sess-m7-reopen.log
expect "m7-reopen-content" "(dumpdone 9)" out/sess-m7-reopen.log
expect "m7-reopen-oracle" "(countdone dist 18)" out/sess-m7-reopen.log
expect "m7-reopen-certified" "(lcnt dist 0 1)" out/sess-m7-reopen.log

# The companion impossible case: an inject-reopen'd lattice successor
# cannot establish contributor state (begin-count-epoch refuses lattice
# versions with predecessors) -- the regression takes the named fallback.
# Content follows the version semantics: inherited rows keep their nonrec
# foundation and SURVIVE the input deletion, while rows derived only at
# the tip through the deleted premise are retracted -- the rebound-aware
# clear-set (rerun clears the tip's OWN overlay; inheritance persists).
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m7_rec_min.slog \
  batch+:edge,1,2,10 batch+:edge,2,3,5 batch+:edge,3,4,1 flush \
  inject-reopen:edge,m7-inh,tests/session/m7_rec_min.slog,9,2,1 \
  batch-:edge,2,3,5 flush dump-tuples:dist \
  > out/sess-m7-inherited.log 2>&1
expect "m7-inherited-refused" "(maintenance-unavailable recount" out/sess-m7-inherited.log
expect "m7-inherited-fallback" "(route rerun " out/sess-m7-inherited.log
expect "m7-inherited-foundation-survives" "(tuplerow 2 3 5)" out/sess-m7-inherited.log
expect "m7-inherited-direct-survives" "(tuplerow 9 2 1)" out/sess-m7-inherited.log
if [ "$(grep -cF '(tuplerow 9 3 6)' out/sess-m7-inherited.log)" -eq 0 ] \
   && [ "$(grep -cF '(tuplerow 9 4 7)' out/sess-m7-inherited.log)" -eq 0 ]; then
  echo "PASS m7-inherited-tip-rows-retract"; PASS=$((PASS+1))
else
  echo "FAIL m7-inherited-tip-rows-retract (tip-only derivations survived)"; FAIL=$((FAIL+1))
fi

# --- M7 sub-slice (c): struct-KEYED recursive lattice -----------------------
# The lattice key is a pnode struct: contributor rows, witnesses, and
# replacement pairs carry interned ids that stay stable across the repair
# (M5 tombstone identity) -- delete tombstones the dead keys' ids, the
# re-add resurrects all of them.
timeout 900 racket tests/api/session-drive.rkt \
  run:tests/session/m7_struct_min.slog \
  batch+:edge,1,2,10 batch+:edge,2,3,5 batch+:edge,3,1,2 \
  batch+:edge,1,3,100 batch+:edge,3,4,1 batch+:edge,2,4,20 batch+:edge,1,4,17 \
  flush dump-ids:pnode \
  batch-:edge,2,3,5 flush dump-rel:dist dump-ids:pnode \
  recount-lattices-force dump-counts:dist \
  batch+:edge,2,3,5 flush dump-ids:pnode \
  > out/sess-m7-struct.log 2>&1
expect "m7-struct-repairs" "(route maintain-lattice-recursive-negative 1)" out/sess-m7-struct.log
expect_not "m7-struct-no-rerun" "(route rerun" out/sess-m7-struct.log
expect "m7-struct-reseed" "(dred-reseeded 1 4)" out/sess-m7-struct.log
expect "m7-struct-content" "(dumpdone 9)" out/sess-m7-struct.log
expect "m7-struct-tombstoned" "(idsdone 9 3)" out/sess-m7-struct.log
expect "m7-struct-oracle" "(countdone dist 18)" out/sess-m7-struct.log
if [ "$(grep -cF '(idsdone 12 0)' out/sess-m7-struct.log)" -eq 2 ]; then
  echo "PASS m7-struct-ids-resurrected"; PASS=$((PASS+1))
else
  echo "FAIL m7-struct-ids-resurrected (tombstones left after re-add)"; FAIL=$((FAIL+1))
fi

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
