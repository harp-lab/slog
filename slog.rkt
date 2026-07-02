#lang racket

(require racket/cmdline
         racket/format
         racket/file
         racket/path
         racket/system
         racket/logging
         "./compiler/params.rkt"
         "./compiler/runslog.rkt")

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
  (values (and out-db (path->string (ensure-dir! (expand-tilde out-db))))
          (and debug-dir (path->string (ensure-dir! (expand-tilde debug-dir))))))

(define (print-version)
  (printf "slog ~a.~a.~a\n" slog-version-major slog-version-minor slog-version-revision))

(define (run-slog* slog-path
                   #:db-name [db-name #f]
                   #:out-db [out-db #f]
                   #:debug-dir [debug-dir #f]
                   #:show-banner? [show-banner? #t]
                   #:verbose? [verbose? #f]
                   #:sizes? [sizes? #f])

  (when show-banner?
    (ascii-art-banner))

  (define slog-file (validate-slog-file slog-path))
  (define-values (out-db* debug-dir*) (validate-and-prepare-paths out-db debug-dir))

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

    (slog-run-file (path->string slog-file) db-name out-db* debug-dir* sizes?)

    (when verbose?
      (fprintf (current-error-port) "Execution completed successfully.\n"))))

(module+ main
  (define show-banner? #t)
  (define db-name #f)
  (define out-db #f)
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
     [("--out-db") path "Directory to write DB artifacts (created if missing)" (set! out-db path)]
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
                   #:debug-dir debug-dir
                   #:show-banner? show-banner?
                   #:verbose? verbose?
                   #:sizes? sizes?)]))))

