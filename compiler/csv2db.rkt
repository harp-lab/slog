#lang racket

;; Turn a folder of delimited text files into a static binary database under
;; data/<dbname>/.  One relation per file (or per subdirectory of shards), rows
;; newline-delimited and columns space/tab-delimited:
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
  (define delimiter #f)
  (define skip-rows 0)
  (command-line
   #:program "csv2db"
   #:once-each
   [("-d" "--delim") char
    "Separate columns on this one character (default: runs of spaces and tabs)"
    (unless (= 1 (string-length char))
      (raise-user-error 'csv2db "--delim takes a single character, not ~s" char))
    (set! delimiter (string-ref char 0))]
   [("-s" "--skip") n
    "Drop this many leading rows of every input file (a text header)"
    (define k (string->number n))
    (unless (exact-nonnegative-integer? k)
      (raise-user-error 'csv2db "--skip takes a row count, not ~s" n))
    (set! skip-rows k)]
   [("--read-values")
    "Read columns as Racket data instead of delimited tokens (values may span lines)"
    (set! read-values? #t)]
   #:args (folder dbname)
   (convert-db-folder folder dbname
                      #:read-values? read-values?
                      #:delimiter delimiter
                      #:skip-rows skip-rows)))
