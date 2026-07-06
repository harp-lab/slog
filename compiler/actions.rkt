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
    [`(write-db ,db-name)
     (format "  d->db()->writeDatabaseBIN(\"~a\");\n" db-name)]
    [`(write-csv ,dir)
     (format "  d->db()->writeDatabaseCSV(\"~a\");\n" dir)]
    [`(write-rel ,db-name ,rel)
     (format "  d->db()->writeRelationBIN(\"~a\", \"~a\");\n" db-name rel)]
    [`(write-rel-csv ,dir ,rel)
     (format "  d->db()->writeRelationCSV(\"~a\", \"~a\");\n" dir rel)]
    [`(load-rel ,db-name ,rel)
     (format "  d->db()->loadRelationBIN(\"~a\", \"~a\");\n" db-name rel)]
    [`(refresh-rel ,db-name ,rel)
     (format (string-append
              "  bool changed = d->db()->refreshRelationBIN(\"~a\", \"~a\");\n"
              "  d->emit(std::string(\"(refreshed ~a \") + (changed ? \"1\" : \"0\") + \")\");\n")
             db-name rel rel)]
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
    (build-so cpp-path so-path))
  so-path)
