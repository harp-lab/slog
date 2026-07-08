#lang racket

(require racket/cmdline
         racket/format
         racket/file
         racket/path
         racket/system
         racket/logging
         "./compiler/params.rkt"
         "./compiler/runslog.rkt"
         "./compiler/dbtool.rkt")

(define EXIT-FILE-NOT-FOUND 1)
(define EXIT-RUNTIME-ERROR 2)

(define (bold s)
  (string-append "\033[1m" s "\033[0m"))
(define (cyan s)
  (string-append "\033[36m" s "\033[0m"))
(define (yellow s)
  (string-append "\033[33m" s "\033[0m"))
(define (dim s)
  (string-append "\033[2m" s "\033[0m"))

(define (ascii-art-banner)
  (define art-lines
    (list "       _____ __           "
          "      / ___// /___  ____ _"
          "      \\__ \\/ / __ \\/ __ `/"
          "     ___/ / / /_/ / /_/ / "
          "    /____/_/\\____/\\__, /  "
          (format "                 /____/  v~a.~a.~a"
                  slog-version-major
                  slog-version-minor
                  slog-version-revision)))

  (newline)
  (for-each (λ (l) (printf "~a\n" (cyan l))) art-lines)
  (newline)

  (printf "~a\n" (bold "Slog — symbolic-expression logic programming language"))
  (newline)
  (printf "~a\n"
          (dim (format "Copyright (c) 2018-~a ~a. ~a"
                       (date-year (seconds->date (current-seconds)))
                       slog-copyright-authors
                       slog-copyright-warning)))
  (printf "~a\n" (dim "See ./License.md for license information."))
  (newline)
  (printf "~a\n\n" (make-string 60 #\-)))

(define (ensure-dir! p)
  (define dir (simplify-path (expand-user-path p)))
  (with-handlers
      ([exn:fail:filesystem?
        (λ (e) (die EXIT-RUNTIME-ERROR "Failed to create directory ~a: ~a" dir (exn-message e)))])
    (when (not (directory-exists? dir))
      (make-directory* dir)))
  dir)

(define (expand-tilde p)
  (simplify-path (expand-user-path (string->path p))))

(define (die code fmt . args)
  (fprintf (current-error-port) "Error: ~a\n" (apply format fmt args))
  (exit code))

(define (validate-slog-file slog-path)
  (define slog-file (path->complete-path (expand-tilde slog-path)))
  (cond
    [(not (file-exists? slog-file)) (die EXIT-FILE-NOT-FOUND "Slog file not found: ~a" slog-file)]
    [(not (path-has-extension? slog-file #".slog"))
     (fprintf (current-error-port) "Warning: File ~a does not have .slog extension\n" slog-file)])
  slog-file)

(define (validate-and-prepare-paths out-db debug-dir)
  ;; out-db is a logical DB name: the daemon stores it under data/<name>/
  (when out-db
    (ensure-dir! (string-append "data/" out-db)))
  (values out-db
          (and debug-dir (path->string (ensure-dir! (expand-tilde debug-dir))))))

(define (print-version)
  (printf "slog ~a.~a.~a\n" slog-version-major slog-version-minor slog-version-revision))

;; Parse a --per value: a percentage (e.g. 60) or a fraction (e.g. 0.6),
;; normalised to a fraction in [0,1].  At P0 there is no sampler, so any value
;; below 1.0 is clamped up to 1.0 (store-everything) with a warning.
(define (parse-per s)
  (define n (string->number s))
  (unless (and n (real? n) (> n 0))
    (die EXIT-RUNTIME-ERROR "--per expects a positive number (percent or fraction), got ~a" s))
  (define frac (min 1.0 (if (> n 1) (/ n 100.0) (exact->inexact n))))
  (when (< frac 1.0)
    (fprintf (current-error-port)
             "Warning: --per ~a: fractional retention is not implemented yet (P0); storing the full database (per=100%).\n" s))
  1.0)

(define (run-slog* slog-path
                   #:db-name [db-name #f]
                   #:out-db [out-db #f]
                   #:out-db-compressed [out-db-compressed #f]
                   #:per [per 1.0]
                   #:flatten? [flatten? #f]
                   #:strict? [strict? #f]
                   #:bias [bias #f]
                   #:reoptimise? [reoptimise? #f]
                   #:force? [force? #f]
                   #:debug-dir [debug-dir #f]
                   #:show-banner? [show-banner? #t]
                   #:verbose? [verbose? #f]
                   #:sizes? [sizes? #f])

  (when show-banner?
    (ascii-art-banner))

  (define slog-file (validate-slog-file slog-path))
  (define-values (out-db* debug-dir*) (validate-and-prepare-paths out-db debug-dir))
  (when out-db-compressed
    (ensure-dir! "data"))
  ;; Immutability guard (docs/db-compression.md §7): a referenced database is
  ;; frozen -- overwriting it would silently change every dependent's
  ;; provenance.  Refuse unless --force (which leaves dependents stale).
  (define save-target (or out-db-compressed out-db))
  (when (and save-target (not force?))
    (define deps (db-referenced-by save-target))
    (unless (null? deps)
      (die EXIT-RUNTIME-ERROR
           "refusing to overwrite database ~a: it is an input to ~a.\n  Use --force to override (dependents become stale), or `slog db rm` them first."
           save-target (string-join deps ", "))))

  (when verbose?
    (fprintf (current-error-port) "Processing file: ~a\n" slog-file)
    (when db-name
      (fprintf (current-error-port) "Using DB name: ~a\n" db-name))
    (when out-db*
      (fprintf (current-error-port) "Output directory: ~a\n" out-db*))
    (when debug-dir*
      (fprintf (current-error-port) "Debug directory: ~a\n" debug-dir*)))

  (with-handlers ([exn:fail?
                   (λ (e)
                     (fprintf (current-error-port) "Slog execution failed: ~a\n" (exn-message e))
                     (when verbose?
                       (fprintf (current-error-port)
                                "Additional details: ~a\n"
                                (if (exn:fail:contract? e) "Contract violation" "Runtime error")))
                     (exit EXIT-RUNTIME-ERROR))])

    (slog-run-file (path->string slog-file) db-name out-db* debug-dir* sizes?
                   #:compressed out-db-compressed
                   #:per per
                   #:flatten? flatten?
                   #:strict? strict?
                   #:bias bias
                   #:reoptimise? reoptimise?)

    (when verbose?
      (fprintf (current-error-port) "Execution completed successfully.\n"))))

(module+ main
  (define argv (current-command-line-arguments))
  ;; `slog db <subcommand> ...` -- database DAG management.  Dispatched before
  ;; command-line (which would bind "db" to the .slog-file positional).
  (when (and (positive? (vector-length argv))
             (equal? (vector-ref argv 0) "db"))
    (slog-db-command (cdr (vector->list argv)))
    (exit 0))
  (define show-banner? #t)
  (define db-name #f)
  (define out-db #f)
  (define out-db-compressed #f)
  (define per 1.0)
  (define flatten? #f)
  (define strict? #f)
  (define bias #f)
  (define reoptimise? #f)
  (define force? #f)
  (define debug-dir #f)
  (define print-version? #f)
  (define show-help? #f)
  (define verbose? #f)
  (define sizes? #f)
  (define program-name "slog")

  (define parsed-args
    (command-line
     #:program program-name
     #:once-each [("--no-banner") "Suppress the startup banner" (set! show-banner? #f)]
     [("-d" "--db-name")
      name
      "Logical DB name to use for the run (a directory under /data)"
      (set! db-name name)]
     [("--out-db") name "Write the final database as data/<name>/ (loadable later with -d)" (set! out-db name)]
     [("--out-db-compressed")
      name
      "Write a recompute-on-load compressed database as data/<name>/ (+ EDB root data/<name>.edb/)"
      (set! out-db-compressed name)]
     [("--per")
      pct
      "Target retention % of derived facts for --out-db-compressed (P0: full only)"
      (set! per (parse-per pct))]
     [("--flatten") "With --out-db-compressed: write one self-contained root (no program/manifest)"
      (set! flatten? #t)]
     [("--bias")
      how
      "Sample-order bias for --out-db-compressed: uniform (default) | productivity"
      (set! bias how)]
     [("--strict") "Treat a load-time drift mismatch as an error, not a warning" (set! strict? #t)]
     [("--reoptimise") "Force re-emission of cached strata on a compressed load" (set! reoptimise? #t)]
     [("--force") "Overwrite a referenced database anyway (dependents become stale)" (set! force? #t)]
     [("--debug-dir")
      path
      "Directory to write debug dumps / traces (created if missing)"
      (set! debug-dir path)]
     [("--version") "Print Slog version and exit" (set! print-version? #t)]
     [("--verbose" "-v") "Enable verbose output" (set! verbose? #t)]
     [("--sizes") "Report each relation's tuple count after the run" (set! sizes? #t)]
     #:args (slog-file)
     (cond
       [print-version?
        (printf "slog ~a.~a.~a\n" slog-version-major slog-version-minor slog-version-revision)
        (exit 0)]
       [else
        (run-slog* slog-file
                   #:db-name db-name
                   #:out-db out-db
                   #:out-db-compressed out-db-compressed
                   #:per per
                   #:flatten? flatten?
                   #:strict? strict?
                   #:bias bias
                   #:reoptimise? reoptimise?
                   #:force? force?
                   #:debug-dir debug-dir
                   #:show-banner? show-banner?
                   #:verbose? verbose?
                   #:sizes? sizes?)]))))

