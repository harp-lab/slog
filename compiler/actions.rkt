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

(provide action-so)

(require "tools.rkt")
(require sha)

(define (action-body spec)
  (match spec
    [`(open ,db-name)
     (format "  d->open(\"~a\");\n" db-name)]
    [`(import ,db-name)
     (format "  d->import(\"~a\");\n" db-name)]
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
    ;; instead -- the productive-seed bias.  Values baked as literals.
    [`(save-compressed ,db-name ,per ,seed ,boost (boosted ,boosted ...) (rels ,rels ..1))
     (define (setlit rs) (string-join (for/list ([r (in-list rs)]) (format "\"~a\"" r)) ", "))
     (format "  d->writeDatabaseSampledBIN(\"~a\", {~a}, ~a, ~aull, {~a}, ~a);\n"
             db-name (setlit rels) (exact->inexact per) seed
             (setlit boosted) (exact->inexact boost))]
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
     (define enc
       (for/list ([v (in-list vals)])
         (cond
           [(string? v) (format "str_encode(db, \"~a\")" v)]
           [(exact-integer? v) (format "s32_encode(~a)" v)]
           [(real? v) (format "float_encode(~a)" (exact->inexact v))]
           [(symbol? v) (format "str_encode(db, \"~a\")" v)]
           [else (error 'action-so "unsupported add-tuple value: ~a" v)])))
     (string-append
      "  slog::Database* db = d->db();\n"
      (format "  std::vector<u64> t = { ~a };\n" (string-join enc ", "))
      (format "  d->addTuple(\"~a\", t);\n" rel))]
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
     (define enc
       (for/list ([v (in-list vals)])
         (cond
           [(string? v) (format "str_encode(db, \"~a\")" v)]
           [(exact-integer? v) (format "s32_encode(~a)" v)]
           [(real? v) (format "float_encode(~a)" (exact->inexact v))]
           [(symbol? v) (format "str_encode(db, \"~a\")" v)]
           [else (error 'action-so "unsupported lookup value: ~a" v)])))
     (string-append
      "  slog::Database* db = d->db();\n"
      (format "  slog::Relation* r = db->getRelation(\"~a\");\n" rel)
      (format "  u64 q[] = { ~a };\n" (string-join enc ", "))
      "  const size_t QN = sizeof(q) / sizeof(q[0]);\n"
      "  bool found = false;\n"
      "  if (r) slog::Database::forEachNominal(r, [&](const u64* row) {\n"
      "    bool eq = true;\n"
      "    for (size_t c = 0; c < QN; ++c) if (row[c] != q[c]) { eq = false; break; }\n"
      "    if (eq) found = true;\n"
      "  });\n"
      (format "  d->emit(std::string(\"(found ~a \") + (found ? \"1\" : \"0\") + \")\");\n"
              rel))]
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
      "              + std::to_string(kv.second->tupleCount()) + \")\");\n")]))

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
