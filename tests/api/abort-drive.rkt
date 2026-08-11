#lang racket

;; T6 slice (b): deterministically exercise the transactional ReadAttempt
;; abort (docs/t6-contract.md; execution-tiers §8.1).  Drives a fresh slogd
;; through pre-built stratum plugins; an abort target runs under a
;; pathological budget until a MID-READ pause, aborts the attempt over the
;; command layer, and continues to fixpoint -- §12.7's claim is that the
;; result is indistinguishable from never having aborted.
;;
;;   racket tests/api/abort-drive.rkt <csvdir> <token>...
;;     token = plain:<so>          -- run a stratum plugin to fixpoint
;;           = abort:<so>          -- abort the FIRST mid-read pause, rerun
;;           = abort-refused:<so>  -- arm a TRANSIENT round first; the abort
;;                                    must refuse (read-abort-flavor) and the
;;                                    round then completes normally
;;
;; Launch with SLOG_MAX_MS=1..3 so mid-read pauses actually occur; the
;; harness echoes ABORTED / REFUSED markers for the battery to assert on.

(require "../../compiler/actions.rkt")
(require "../../compiler/tools.rkt")

(define (run csv-dir tokens)
  (define continue-so (action-so '(continue)))
  (define csv-so (action-so `(write-csv ,csv-dir)))
  (define transient-so (action-so '(transient-stratum)))
  (ensure-slogd-exists)
  (define-values (sp out in err) (apply subprocess #f #f #f (slogd-argv "daemon/slogd")))
  (define (send p) (display (string-append p "\n") in) (flush-output in))
  (define (rd) (read-line out))
  (define et (thread (lambda ()
                       (let loop () (define s (read-line err))
                         (unless (eof-object? s) (eprintf "~a\n" s) (loop))))))

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

  ;; abort the first genuine mid-read pause: (paused ... read ...), the
  ;; 8-field path shape.  One abort per stratum -- later pauses continue.
  (define (drive-abort so)
    (send so)
    (let loop ([aborted? #f])
      (define l (rd))
      (cond
        [(eof-object? l) (error "unexpected eof")]
        [(regexp-match? #px"^\\(fixpoint " l) (displayln l) aborted?]
        [(regexp-match? #px"^\\(paused " l)
         (displayln l)
         (cond
           [(and (not aborted?)
                 (regexp-match? #px"^\\(paused [^ ]+ \"[^\"]*\" [0-9]+ read " l))
            (send "(abort-read)")
            (define reply (rd))
            (displayln reply)
            (unless (regexp-match? #px"^\\(read-aborted \\(generation [0-9]+\\)\\)" reply)
              (error (format "abort-read did not abort: ~a" reply)))
            (displayln "ABORTED")
            (send continue-so)
            (loop #t)]
           [else (send continue-so) (loop aborted?)])]
        [(regexp-match? #px"^\\(error " l) (error l)]
        [else (displayln l) (loop aborted?)])))

  ;; a transient (count-flavored) round must REFUSE the abort at its parks
  ;; and then complete normally -- §12.13's restart clause.
  (define (drive-abort-refused so)
    (send transient-so)
    (let arm ()
      (define l (rd))
      (cond [(eof-object? l) (error "unexpected eof arming transient")]
            [(regexp-match? #px"^\\(transient-armed\\)" l) (displayln l)]
            [else (displayln l) (arm)]))
    (send so)
    (let loop ([refused? #f])
      (define l (rd))
      (cond
        [(eof-object? l) (error "unexpected eof")]
        [(regexp-match? #px"^\\(fixpoint " l) (displayln l) refused?]
        [(regexp-match? #px"^\\(paused " l)
         (displayln l)
         (cond
           [(not refused?)
            (send "(abort-read)")
            (define reply (rd))
            (displayln reply)
            (unless (regexp-match? #px"^\\(refused read-abort-flavor " reply)
              (error (format "expected a flavor refusal: ~a" reply)))
            (displayln "REFUSED")
            (send continue-so)
            (loop #t)]
           [else (send continue-so) (loop refused?)])]
        [(regexp-match? #px"^\\(error " l) (error l)]
        [else (displayln l) (loop refused?)])))

  (define outcomes
    (for/list ([tok (in-list tokens)])
      (match (string-split tok ":")
        [(list "plain" so) (drive-plain so) #t]
        [(list "abort" so) (drive-abort so)]
        [(list "abort-refused" so) (drive-abort-refused so)]
        [_ (error 'abort-drive "bad token: ~a" tok)])))
  (unless (andmap values outcomes)
    ;; a target stratum that never paused mid-read aborted/refused nothing:
    ;; say so loudly so the battery can retry with a bigger fixture rather
    ;; than pass vacuously
    (displayln "NO-TARGET-EVENT"))

  (send csv-so)
  (close-output-port in)
  (let loop () (define s (rd)) (unless (eof-object? s) (displayln s) (loop)))
  (thread-wait et)
  (subprocess-wait sp))

(module+ main
  (match (vector->list (current-command-line-arguments))
    [(cons csvdir tokens) #:when (pair? tokens) (run csvdir tokens)]
    [_ (error "usage: abort-drive.rkt <csvdir> <plain:so | abort:so | abort-refused:so>...")]))
