#lang racket

;; Action plugins: tiny generated daemon plugins for everything a client
;; wants of the database besides running rules.  The daemon's protocol is
;; nothing but .so paths (daemon/slogd.cpp), so opening a stored database,
;; writing results, or asking for statistics each becomes a one-function
;; plugin: generate its C++, build it (cached in build/ by a hash of the
;; source and the daemon headers), and send the path.
;;
;;   (action-so `(open ,db-name))            load data/<db-name>/
;;   (action-so `(import ,db-name))          merge data/<db-name>/ into the
;;                                           live db (docs/db-merge.md)
;;   (action-so `(write-db ,db-name))        write the database (binary)
;;   (action-so `(write-csv ,dir))           write every relation as CSV
;;   (action-so `(write-rel ,db-name ,rel))  write one relation (binary)
;;   (action-so `(write-rel-csv ,dir ,rel))  write one relation as CSV
;;   (action-so `(load-rel ,db-name ,rel))   replace one relation from disk
;;   (action-so `(refresh-rel ,db-name ,rel)) reload iff changed on disk;
;;                                           reports (refreshed <rel> 0|1)
;;   (action-so `(sizes))                    report (relation_size <rel> <n>)
;;                                           for every indexed relation
;;   (action-so `(schema))                   report (schema-rel <kind> ...)
;;                                           for every non-empty relation of
;;                                           the LIVE db, then (schema-end)

(provide action-so)

(require "tools.rkt")
(require "utils.rkt")
(require sha)

;; Shared value encoder for tuple-carrying actions (add/del/stage/lookup):
;; strings/symbols intern, small ints NaN-box, bignums normalize through the
;; daemon's keystone, floats encode.  Values are baked as literals -- the
;; path-only protocol has no argument channel.
(define (encode-val who v)
  (cond
    [(string? v) (format "str_encode(db, \"~a\")" (escape-c-string-literal v))]
    [(exact-integer? v)
     (if (and (>= v (- (expt 2 31))) (< v (expt 2 31)))
         (format "s32_encode(~a)" v)
         (format "db->encodeIntLiteral(\"~a\")" v))]
    [(real? v) (format "float_encode(~a)" (exact->inexact v))]
    [(symbol? v) (format "str_encode(db, \"~a\")" (escape-c-string-literal (symbol->string v)))]
    [else (error 'action-so "unsupported ~a value: ~a" who v)]))

;; A C++ initializer list of encoded tuples: {{...}, {...}, ...}
(define (encode-tuples who tuples)
  (string-join
   (for/list ([t (in-list tuples)])
     (format "{ ~a }" (string-join (for/list ([v (in-list t)]) (encode-val who v)) ", ")))
   ", "))

(define (action-body spec)
  (match spec
    [`(open ,db-name)
     (format "  d->open(\"~a\");\n" db-name)]
    [`(import ,db-name)
     (format "  d->import(\"~a\");\n" db-name)]
    ;; Merge a database by PATH (no data/ prefix): the compiler's frozen
    ;; ground-fact databases under build/frozen/ (freeze.rkt).
    [`(import-path ,dir)
     (format "  d->importPath(\"~a\");\n" dir)]
    ;; Merge a compressed layer, passing trimmed same-lineage struct refs
    ;; through to the verbatim-loaded root/input (docs/db-compression.md §4.2).
    [`(import-layer ,db-name)
     (format "  d->importLayer(\"~a\");\n" db-name)]
    ;; DB/relation writes and reloads go through the Daemon (not straight to
    ;; the Database) so the suspended guardrail applies (docs/pausing.md §4):
    ;; they run internal strata / mutate indices that would clobber a parked
    ;; run.  CSV writes take no such lock and call the Database directly.
    [`(write-db ,db-name)
     (format "  d->writeDatabaseBIN(\"~a\");\n" db-name)]
    ;; Write only the named relations (docs/db-compression.md P0.5): an EDB-root
    ;; snapshot or an IDB-layer save.  Callers must pass a NON-EMPTY list -- an
    ;; empty relation set means "write all" to the daemon (the single-arg
    ;; write-db delegates via an empty filter), so the driver never emits this
    ;; verb with zero relations.
    [`(write-db-subset ,db-name ,rels ..1)
     (format "  d->writeDatabaseSubsetBIN(\"~a\", {~a});\n"
             db-name
             (string-join (for/list ([r (in-list rels)]) (format "\"~a\"" r)) ", "))]
    ;; Sampled IDB-layer write (docs/db-compression.md P1.2/P2.4).  `rels` is
    ;; the full IDB set (kept at `per`); `boosted` (a sublist) keeps at `boost`
    ;; instead -- the productive-seed bias; `pinned` (a sublist, docs/smt.md
    ;; §15) keeps at 1.0 and seeds the heap-trimming roots -- oracle-fed rows
    ;; replay cannot re-derive.  Values baked as literals.
    [`(save-compressed ,db-name ,per ,seed ,boost (boosted ,boosted ...)
                       (pinned ,pinned ...) (rels ,rels ..1) (accel ,accel))
     (define (setlit rs) (string-join (for/list ([r (in-list rs)]) (format "\"~a\"" r)) ", "))
     (format "  d->writeDatabaseSampledBIN(\"~a\", {~a}, ~a, ~aull, {~a}, ~a, {~a}, ~a);\n"
             db-name (setlit rels) (exact->inexact per) seed
             (setlit boosted) (exact->inexact boost) (setlit pinned)
             (if (zero? accel) "false" "true"))]
    [`(write-csv ,dir)
     (format "  d->db()->writeDatabaseCSV(\"~a\");\n" dir)]
    ;; Serial checkpoint of the current (possibly paused) db (§P2.3).
    [`(checkpoint ,db-name)
     (format "  d->checkpointBIN(\"~a\");\n" db-name)]
    ;; Snapshot the EDB struct heap so the next layer write dedups against it (§4.2).
    [`(capture-edb-heap) "  d->captureEDBHeap();\n"]
    [`(write-rel ,db-name ,rel)
     (format "  d->writeRelationBIN(\"~a\", \"~a\");\n" db-name rel)]
    [`(write-rel-csv ,dir ,rel)
     (format "  d->db()->writeRelationCSV(\"~a\", \"~a\");\n" dir rel)]
    ;; Insert one tuple into a relation (docs/db-compression.md §12,
    ;; edit-and-propagate): storage-order values baked into the plugin like
    ;; lookup.  Used to apply a saved db's `edits` on load so replay propagates
    ;; the change forward.
    [`(add-tuple ,rel ,vals ...)
     (string-append
      "  slog::Database* db = d->db();\n"
      (format "  std::vector<u64> t = { ~a };\n"
              (string-join (for/list ([v (in-list vals)]) (encode-val 'add-tuple v)) ", "))
      (format "  d->addTuple(\"~a\", t);\n" rel))]
    ;; Retract one tuple (docs/incremental.md §0.6, B2): the version-rebuild
    ;; half of clear-and-rerun; the driver clears + re-runs the cone after.
    ;; Same value encoding as add-tuple.  Replies (deleted REL 0|1).
    [`(del-tuple ,rel ,vals ...)
     (string-append
      "  slog::Database* db = d->db();\n"
      (format "  std::vector<u64> t = { ~a };\n"
              (string-join (for/list ([v (in-list vals)]) (encode-val 'del-tuple v)) ", "))
      (format "  d->delTuple(\"~a\", t);\n" rel))]
    ;; Empty one relation's latest version, registrations kept (§0.5 mode 2/
    ;; B2): sent for each cone-written relation before the cone re-push.
    [`(clear-rel ,rel)
     (format "  d->clearRelation(\"~a\");\n" rel)]
    ;; Stage one tuple as pending delta only (docs/incremental.md §0.3,
    ;; 0.B5/B6 exact-once): the delta-entry re-push's iteration-0 delta.
    ;; Same value encoding as add-tuple.
    [`(stage-tuple ,rel ,vals ...)
     (string-append
      "  slog::Database* db = d->db();\n"
      (format "  std::vector<u64> t = { ~a };\n"
              (string-join (for/list ([v (in-list vals)]) (encode-val 'stage-tuple v)) ", "))
      (format "  d->stageTuple(\"~a\", t);\n" rel))]
    ;; ---- the 0.C1 batch actions (docs/incremental.md §0.3 transport 1) ----
    ;; Multi-tuple inline batches, values baked as literals.  `pos` is the
    ;; anchor: -1 = the latest version (tip), else the version current at
    ;; that pipeline position (apply-only -- the session driver owns
    ;; propagation).  Reply (added REL n) / (deleted REL nfound).
    [`(add-batch ,rel ,pos (,tuples ...))
     (string-append
      "  slog::Database* db = d->db();\n"
      (format "  std::vector<std::vector<u64>> ts = { ~a };\n"
              (encode-tuples 'add-batch tuples))
      (format "  d->addBatchAt(\"~a\", ~a, ts);\n" rel pos))]
    [`(del-batch ,rel ,pos (,tuples ...))
     (string-append
      "  slog::Database* db = d->db();\n"
      (format "  std::vector<std::vector<u64>> ts = { ~a };\n"
              (encode-tuples 'del-batch tuples))
      (format "  d->delBatchAt(\"~a\", ~a, ts);\n" rel pos))]
    ;; Multi-tuple staging (0.B5's exact-once path, one plugin per flush).
    [`(stage-batch ,rel (,tuples ...))
     (string-append
      "  slog::Database* db = d->db();\n"
      (format "  std::vector<std::vector<u64>> ts = { ~a };\n"
              (encode-tuples 'stage-batch tuples))
      (format "  d->stageBatch(\"~a\", ts);\n" rel))]
    ;; Positional re-entry arm (0.C): the NEXT stratum push binds and
    ;; restages the P-environment instead of the latest.
    [`(bind-at ,pos)
     (format "  d->bindAt(~a);\n" pos)]
    ;; Positional clear + inheritance-boundary refresh (0.C, the anchored
    ;; clear-and-rerun's primitives).
    [`(clear-rel-at ,rel ,pos)
     (format "  d->clearRelationAt(\"~a\", ~a);\n" rel pos)]
    [`(refresh-version ,rel ,ord)
     (format "  d->refreshVersion(\"~a\", ~a);\n" rel ord)]
    ;; Import a mini bin-database as a bulk batch payload (§0.3 transport 2),
    ;; with an optional source->dest name-map.  Tip-anchored; the 3-argument
    ;; form (0.E0b) anchors the payload at a pipeline position (apply-only,
    ;; like add-batch -- the driver owns propagation).
    [`(import-delta ,dir (,renames ...))
     (format "  d->importDelta(\"~a\", {~a});\n" dir
             (string-join (for/list ([r (in-list renames)])
                            (format "{\"~a\", \"~a\"}" (first r) (second r)))
                          ", "))]
    [`(import-delta ,dir (,renames ...) ,pos)
     (format "  d->importDelta(\"~a\", {~a}, ~a);\n" dir
             (string-join (for/list ([r (in-list renames)])
                            (format "{\"~a\", \"~a\"}" (first r) (second r)))
                          ", ")
             pos)]
    ;; Rename / drop between segments (docs/incremental.md §0.7, 0.D1):
    ;; environment operations on the version chains, zero data movement.
    ;; Replies (renamed R S 0|1) / (dropped R 0|1).
    [`(rename-rel ,from ,to)
     (format "  d->renameRel(\"~a\", \"~a\");\n" from to)]
    [`(drop-rel ,rel)
     (format "  d->dropRel(\"~a\");\n" rel)]
    ;; Segment boundary (docs/incremental.md §0.4-§0.5, B0): announce the
    ;; relation names the upcoming program segment writes, so the daemon
    ;; rebinds each already-bound one to a NEW physical version (full copy of
    ;; its predecessor) before the segment's strata bind.  Names never bound
    ;; are no-ops (they register normally at push).  Replies (segment P N).
    [`(begin-segment ,rels ...)
     (format "  d->beginSegment({~a});\n"
             (string-join (for/list ([r (in-list rels)]) (format "\"~a\"" r)) ", "))]
    ;; Version-chain introspection (§0.4): one
    ;;   (pipeline (pos P) (rel NAME (v ORD POS SIZE) ...) ...)
    ;; line, so a front end can (re)derive the point->(name->version) map
    ;; from a live daemon.  Read-only; safe when suspended.
    [`(pipeline) "  d->emitPipeline();\n"]
    ;; Versioned sizes (§0.4 addressing): one (sizes-at P (NAME SIZE) ...)
    ;; line with every name resolved at position P.  Read-only.
    [`(sizes-at ,pos)
     (format "  d->emitSizesAt(~a);\n" pos)]
    [`(load-rel ,db-name ,rel)
     (format "  d->loadRelation(\"~a\", \"~a\");\n" db-name rel)]
    [`(refresh-rel ,db-name ,rel)
     (format "  d->refreshRelation(\"~a\", \"~a\");\n" db-name rel)]
    ;; One bounded unit of work (docs/pausing.md §5): start or resume the
    ;; frontmost not-yet-fixpointed stratum.  Bare (continue) uses the daemon's
    ;; (env-configurable) default budget; the ms / mem forms override it.  The
    ;; one .so is cached and reused for every poll of a run.
    [`(continue) "  d->continueRun();\n"]
    ;; Continue only to the next clean iteration boundary (docs/fast-compile.md
    ;; §4): the tiered-compilation driver polls this to bring a stratum to
    ;; RUN_AT_BOUNDARY before hot-swapping its .so to the -O2 build.  A distinct
    ;; head (not `(continue boundary)`) so it can't be shadowed by (continue ,ms).
    [`(continue-boundary) "  d->continueToBoundary();\n"]
    [`(continue ,ms)
     (format "  d->continueRun(slog::RunBudget{~a});\n" ms)]
    [`(continue ,ms ,mem)
     (format "  d->continueRun(slog::RunBudget{~a, 500, ~a});\n" ms mem)]
    ;; A point-query against the (possibly suspended) database (§8a): does any
    ;; tuple of `rel` match the given storage-order prefix?  Values are baked
    ;; into the plugin source (the path-only protocol has no arg channel), so a
    ;; new query value costs one clang -- but the motivating "poll whether tuple
    ;; X appeared yet between pauses" repeats the SAME query, compiled once.
    ;; Read-only, so it is safe against a suspended snapshot.
    [`(lookup ,rel ,vals ...)
     (string-append
      "  slog::Database* db = d->db();\n"
      (format "  slog::Relation* r = db->getRelation(\"~a\");\n" rel)
      (format "  u64 q[] = { ~a };\n"
              (string-join (for/list ([v (in-list vals)]) (encode-val 'lookup v)) ", "))
      "  const size_t QN = sizeof(q) / sizeof(q[0]);\n"
      "  bool found = false;\n"
      "  if (r) slog::Database::forEachNominal(r, [&](const u64* row) {\n"
      "    bool eq = true;\n"
      "    for (size_t c = 0; c < QN; ++c) if (row[c] != q[c]) { eq = false; break; }\n"
      "    if (eq) found = true;\n"
      "  });\n"
      (format "  d->emit(std::string(\"(found ~a \") + (found ? \"1\" : \"0\") + \")\");\n"
              rel))]
    ;; Versioned point-query (docs/incremental.md §0.4, 0.C1): the same
    ;; prefix probe against the version of `rel` current at position P.
    [`(lookup-at ,rel ,pos ,vals ...)
     (string-append
      "  slog::Database* db = d->db();\n"
      (format "  slog::Relation* r = db->getRelationAt(\"~a\", ~a);\n" rel pos)
      (format "  u64 q[] = { ~a };\n"
              (string-join (for/list ([v (in-list vals)]) (encode-val 'lookup-at v)) ", "))
      "  const size_t QN = sizeof(q) / sizeof(q[0]);\n"
      "  bool found = false;\n"
      "  if (r) slog::Database::forEachNominal(r, [&](const u64* row) {\n"
      "    bool eq = true;\n"
      "    for (size_t c = 0; c < QN; ++c) if (row[c] != q[c]) { eq = false; break; }\n"
      "    if (eq) found = true;\n"
      "  });\n"
      (format "  d->emit(std::string(\"(found-at ~a ~a \") + (found ? \"1\" : \"0\") + \")\");\n"
              rel pos))]
    ;; Dump every tuple of `rel` (rendered like a CSV value) as one
    ;; (dumprow <value>) line, terminated by (dumpdone <n>).  Read-only, so it
    ;; is safe against a suspended snapshot; used by the driver's error-fact
    ;; watch (compiler/runslog.rkt) to warn on newly-surfaced (error ...) facts.
    [`(dump-rel ,rel)
     (string-append
      "  slog::Database* db = d->db();\n"
      (format "  slog::Relation* r = db->getRelation(\"~a\");\n" rel)
      "  size_t n = 0;\n"
      "  if (r) slog::Database::forEachNominal(r, [&](const u64* row) {\n"
      "    d->emit(std::string(\"(dumprow \") + db->writeValCSV(row[0]) + \")\");\n"
      "    ++n;\n"
      "  });\n"
      "  d->emit(std::string(\"(dumpdone \") + std::to_string(n) + \")\");\n")]
    ;; Versioned dump (docs/incremental.md §0.4): the relation's version
    ;; current at pipeline position `pos` -- same (dumprow ...)/(dumpdone N)
    ;; protocol as the unversioned form.  Read-only.
    [`(dump-rel ,rel ,pos)
     (string-append
      "  slog::Database* db = d->db();\n"
      (format "  slog::Relation* r = db->getRelationAt(\"~a\", ~a);\n" rel pos)
      "  size_t n = 0;\n"
      "  if (r) slog::Database::forEachNominal(r, [&](const u64* row) {\n"
      "    d->emit(std::string(\"(dumprow \") + db->writeValCSV(row[0]) + \")\");\n"
      "    ++n;\n"
      "  });\n"
      "  d->emit(std::string(\"(dumpdone \") + std::to_string(n) + \")\");\n")]
    ;; Drop ALL count state (docs/incremental.md §8B.2): counts are
    ;; session-ephemeral recomputable cache, so the cheap "uncounted"
    ;; transition is deletion -- the recount driver clears before a round
    ;; so re-establishment is idempotent-by-rebuild.  Registry-wide: old
    ;; versions' sidecars are stale the same way the latest's are.
    [`(clear-counts)
     (string-append
      "  for (slog::Relation* r : d->db()->allVersions())\n"
      "    if (r) r->clearCounts();\n"
      "  d->emit(\"(counts-cleared)\");\n")]
    ;; Dump one relation's count sidecar (docs/incremental.md §8B, M0): one
    ;; (countrow REL v.. IN NR RC) line per counted key -- the sidecar key
    ;; rendered like CSV values (tables: the full tuple in storage order;
    ;; structs: the id, which renders as content), then the decoded input
    ;; bit and (nonrec, rec) counters -- terminated by (countdone REL n).
    ;; An uncounted relation reports (countdone REL -1).  Read-only; the
    ;; count oracle and the M0 test batteries key on these lines.
    [`(dump-counts ,rel)
     (string-append
      "  slog::Database* db = d->db();\n"
      (format "  slog::Relation* r = db->getRelation(\"~a\");\n" rel)
      "  if (!r || !r->getCountSidecar())\n"
      (format "  { d->emit(\"(countdone ~a -1)\"); return; }\n" rel)
      "  slog::Index** side = r->getCountSidecar();\n"
      "  const u16 ka = r->countKeyArity();\n"
      "  size_t n = 0;\n"
      "  for (u16 b = 0; b < bucket_count; ++b)\n"
      "    side[b]->forEach([&](const u64* row) {\n"
      (format "      std::string line = \"(countrow ~a\";\n" rel)
      "      for (u16 c = 0; c < ka; ++c) line += \" \" + db->writeValCSV(row[c]);\n"
      "      const u64 w = row[ka];\n"
      "      line += std::string(\" \") + (slog::cnt_input(w) ? \"1\" : \"0\")\n"
      "            + \" \" + std::to_string(slog::cnt_nonrec(w))\n"
      "            + \" \" + std::to_string(slog::cnt_rec(w)) + \")\";\n"
      "      d->emit(line);\n"
      "      ++n;\n"
      "    });\n"
      (format "  d->emit(std::string(\"(countdone ~a \") + std::to_string(n) + \")\");\n" rel))]
    ;; Per-relation id-free content signature (docs/db-compression.md P1.3):
    ;; emit one `(sig NAME count checksum)` per named relation, then `(sig-end)`.
    ;; Read-only, so it is safe against a suspended snapshot.
    [`(signature ,rels ..1)
     (string-append
      "  slog::Database* db = d->db();\n"
      (format "  const char* sigrels[] = { ~a };\n"
              (string-join (for/list ([r (in-list rels)]) (format "\"~a\"" r)) ", "))
      "  for (auto nm : sigrels) {\n"
      "    slog::Relation* r = db->getRelation(nm);\n"
      "    if (!r) continue;\n"
      "    auto sg = db->signatureOf(r);\n"
      "    d->emit(\"(sig \" + std::string(nm) + \" \" + std::to_string(sg.first)\n"
      "            + \" \" + std::format(\"{:016x}\", sg.second) + \")\");\n"
      "  }\n"
      "  d->emit(\"(sig-end)\");\n")]
    [`(sizes)
     (string-append
      "  std::vector<std::pair<std::string, slog::Relation*>> rels(\n"
      "      d->db()->getRelations().begin(), d->db()->getRelations().end());\n"
      "  std::sort(rels.begin(), rels.end());\n"
      "  for (auto& kv : rels)\n"
      "    if (kv.second->getAnyIndex())\n"
      "      d->emit(\"(relation_size \" + kv.first + \" \"\n"
      "              + std::to_string(kv.second->tupleCount()) + \")\");\n")]
    ;; Schema truth from the LIVE db (docs/finish-collections.md §B): one
    ;; s-expr per relation, name-sorted, then (schema-end) -- exactly the
    ;; information relation directory names carry (kind, arity, struct id,
    ;; lattice spec token), but including imports and prior programs.  Skips
    ;; index-free (temp/mid-reload) and EMPTY relations, mirroring what
    ;; writeDatabaseBIN persists, so the parsed manifest of a session equals
    ;; db-manifest-from-name of a write-db'd copy (the front-end hook is
    ;; runslog.rkt's db-manifest-from-schema-lines: compile against the
    ;; session instead of a directory scan).  Read-only; safe when suspended.
    [`(schema)
     (string-append
      "  std::vector<std::pair<std::string, slog::Relation*>> rels(\n"
      "      d->db()->getRelations().begin(), d->db()->getRelations().end());\n"
      "  std::sort(rels.begin(), rels.end());\n"
      "  for (auto& kv : rels)\n"
      "  {\n"
      "    slog::Relation* r = kv.second;\n"
      "    if (!r->getAnyIndex() || r->isEmpty()) continue;\n"
      "    if (r->getStructId() > 0)\n"
      "      d->emit(\"(schema-rel struct \" + kv.first + \" \" + std::to_string(r->getArity())\n"
      "              + \" \" + std::to_string(r->getStructId()) + \")\");\n"
      "    else if (r->isLattice())\n"
      "      d->emit(\"(schema-rel lat \" + kv.first + \" \" + std::to_string(r->getArity())\n"
      "              + \" \" + r->latticeSpec() + \")\");\n"
      "    else\n"
      "      d->emit(\"(schema-rel table \" + kv.first + \" \" + std::to_string(r->getArity()) + \")\");\n"
      "  }\n"
      "  d->emit(\"(schema-end)\");\n")]))

(define (action-source spec)
  (string-append
   "\n"
   "#include \"../daemon/daemon.h\"\n"
   "#include <algorithm>\n"
   "#include <string>\n"
   "#include <utility>\n"
   "#include <vector>\n"
   "\n"
   (format "// action: ~s\n" spec)
   "extern \"C\" void slog_plugin(slog::Daemon* d)\n{\n"
   (action-body spec)
   "}\n"))

;; Generate, build (or reuse from cache), and return the plugin's .so path.
(define (action-so spec)
  (define src (action-source spec))
  (define h
    (substring (bytes->hex-string
                (sha256 (string->bytes/utf-8
                         (string-append src daemon-headers-fingerprint))))
               0 12))
  (define so-path (fullpath (format "build/action-~a.so" h)))
  (unless (file-exists? so-path)
    (define cpp-path (fullpath (format "build/action-~a.cpp" h)))
    (with-output-to-file cpp-path #:exists 'replace (lambda () (display src)))
    ;; Actions are tiny and include a different header set (daemon.h + STL, no
    ;; operators.h), so the strata PCH would not match; build without one.  They
    ;; compile at -O0 -- an action does no hot inner loop worth optimizing.
    (build-so cpp-path so-path #:opt "-O0" #:pch #f))
  so-path)
