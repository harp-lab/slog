#lang racket

;; Turn a folder of delimited text files into a static binary database under
;; data/<dbname>/.  One file per relation, rows newline-delimited and columns
;; space/tab-delimited:
;;
;;   $ racket compiler/csv2db.rkt path/to/folder mydb
;;   $ racket compiler/run.rkt --no-banner -d mydb --sizes query.slog
;;
;; The importer is convert-db-folder in tools.rkt; this is just its command
;; line.  Run it from the repository root, since database names are logical
;; names under data/.

(require "tools.rkt")

(module+ main
  (define read-values? #f)
  (command-line
   #:program "csv2db"
   #:once-each
   [("--read-values")
    "Read columns as Racket data instead of delimited tokens (allows (struct ...) columns)"
    (set! read-values? #t)]
   #:args (folder dbname)
   (convert-db-folder folder dbname #:read-values? read-values?)))
