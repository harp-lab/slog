#lang racket

;; (schema) manifest round trip (docs/finish-collections.md §B): drive one
;; daemon session through open + import + (schema) + write-db, then check
;; that the schema lines parse (db-manifest-from-schema-lines) into EXACTLY
;; the manifest a directory scan (db-manifest-from-name) reads back from the
;; write-db'd copy -- live-session schema truth == on-disk schema truth.
;;
;;   racket tests/api/schema-manifest.rkt OPENDB IMPORTDB OUTDB
;;
;; Run from the repository root.  Prints PASS/FAIL and exits accordingly.

(require "../../compiler/actions.rkt")
(require "../../compiler/tools.rkt")
(require "../../compiler/runslog.rkt")

(module+ main
  (match-define (vector opendb importdb outdb) (current-command-line-arguments))
  (define paths
    (map action-so `((open ,opendb) (import ,importdb) (schema) (write-db ,outdb))))
  (ensure-slogd-exists)
  (define-values (sp out in err) (apply subprocess #f #f #f (slogd-argv "daemon/slogd")))
  (for ([p (in-list paths)])
    (display (string-append p "\n") in))
  (close-output-port in)
  (define lines
    (let loop ([acc '()])
      (define s (read-line out))
      (if (eof-object? s) (reverse acc) (loop (cons s acc)))))
  (close-input-port out)
  (close-input-port err)
  (subprocess-wait sp)
  (define live-man (db-manifest-from-schema-lines lines))
  (define disk-man (db-manifest-from-name outdb))
  (cond
    [(equal? live-man disk-man)
     (printf "PASS schema-manifest (~a relations)\n" (hash-count live-man))
     (exit 0)]
    [else
     (printf "FAIL schema-manifest\n  live: ~a\n  disk: ~a\n" live-man disk-man)
     (exit 1)]))
