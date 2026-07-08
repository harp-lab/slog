#lang racket

;; Deterministically exercise the -O0 -> -O2 hot swap (docs/fast-compile.md §4).
;; Drives a fresh slogd through a sequence of pre-built stratum plugins in
;; pipeline order; one (or more) of them is a swap target, driven -O0 -> clean
;; iteration boundary (via continue-boundary) -> -O2 plugin (SAME stratum name,
;; hot-swapped in place) -> fixpoint.  The two plugins of a swap target are
;; pre-built at the two optimization levels, so the swap fires regardless of
;; build timing (launch with SLOG_MAX_MS=1 to force a pause on the first unit).
;;
;;   racket tests/api/swap-drive.rkt <csvdir> <token>...
;;     token = plain:<so>            -- run a stratum plugin to fixpoint
;;           = swap:<o0.so>,<o2.so>  -- run -O0, then hot-swap to -O2

(require "../../compiler/actions.rkt")
(require "../../compiler/tools.rkt")

(define (run csv-dir tokens)
  (define continue-so (action-so '(continue)))
  (define boundary-so (action-so '(continue-boundary)))
  (define csv-so (action-so `(write-csv ,csv-dir)))
  (ensure-slogd-exists)
  (define-values (sp out in err) (apply subprocess #f #f #f (slogd-argv "daemon/slogd")))
  (define (send p) (display (string-append p "\n") in) (flush-output in))
  (define (rd) (read-line out))
  (define et (thread (lambda ()
                       (let loop () (define s (read-line err))
                         (unless (eof-object? s) (eprintf "~a\n" s) (loop))))))

  ;; a plain stratum: poll to fixpoint, answering pauses with (continue)
  (define (drive-plain so)
    (send so)
    (let loop ()
      (define l (rd))
      (cond
        [(eof-object? l) (error "unexpected eof")]
        [(regexp-match? #px"^\\(fixpoint " l) (displayln l)]
        [(regexp-match? #px"^\\(paused " l) (displayln l) (send continue-so) (loop)]
        [(regexp-match? #px"^\\(error " l) (error l)]
        [else (displayln l) (loop)])))

  ;; a swap target: run -O0, drive to a clean boundary, swap in -O2, finish
  (define (drive-swap o0 o2)
    (send o0)
    (let loop ([swapped? #f])
      (define l (rd))
      (cond
        [(eof-object? l) (error "unexpected eof")]
        [(regexp-match? #px"^\\(fixpoint " l) (displayln l)]
        [(regexp-match? #px"^\\(paused " l)
         (displayln l)
         (cond
           [swapped? (send continue-so) (loop #t)]
           [(regexp-match? #px"^\\(paused [^ ]+ \"[^\"]*\" [0-9]+ iter " l)
            (send o2) (displayln "SWAPPED") (loop #t)]
           [else (send boundary-so) (loop #f)])]
        [(regexp-match? #px"^\\(error " l) (error l)]
        [else (displayln l) (loop swapped?)])))

  (for ([tok (in-list tokens)])
    (match (string-split tok ":")
      [(list "plain" so) (drive-plain so)]
      [(list "swap" pair)
       (match-define (list o0 o2) (string-split pair ","))
       (drive-swap o0 o2)]
      [_ (error 'swap-drive "bad token: ~a" tok)]))

  (send csv-so)
  (close-output-port in)
  (let loop () (define s (rd)) (unless (eof-object? s) (displayln s) (loop)))
  (thread-wait et)
  (subprocess-wait sp))

(module+ main
  (match (vector->list (current-command-line-arguments))
    [(cons csvdir tokens) #:when (pair? tokens) (run csvdir tokens)]
    [_ (error "usage: swap-drive.rkt <csvdir> <plain:so | swap:o0,o2>...")]))
