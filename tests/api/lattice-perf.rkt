#lang racket

;; Non-flaky M6L performance gate: report cold contributor establishment and a
;; warm one-key replacement separately.  Correct route/state are hard gates;
;; timings and the contributor-storage lower bound are trend data for CI.

(require "../../compiler/session.rkt")

(define args (current-command-line-arguments))
(define n (if (positive? (vector-length args))
              (string->number (vector-ref args 0))
              240))
(unless (exact-positive-integer? n)
  (error 'lattice-perf "expected a positive key count"))

(define transcript '())
(define (count-rows s rel)
  (define rows '())
  (session-action! s `(dump-counts ,rel)
    (lambda (out)
      (let loop ()
        (define line (read-line out))
        (cond
          [(eof-object? line) (void)]
          [(regexp-match? #px"^\\(countdone " line) (void)]
          [(regexp-match? #px"^\\(countrow " line)
           (set! rows (cons line rows))
           (loop)]
          [else (loop)]))))
  rows)

(define s (make-session #:echo (lambda (line) (set! transcript (cons line transcript)))))
(dynamic-wind
 void
 (lambda ()
   (session-run! s "tests/session/m6l_stratified.slog")
   (for ([key (in-range n)])
     (session-batch! s '+ 'offer (list key 0))
     (session-batch! s '+ 'alias (list key 1)))
   (define cold-start (current-inexact-monotonic-milliseconds))
   (session-flush! s)
   (define cold-ms (- (current-inexact-monotonic-milliseconds) cold-start))

   (session-batch! s '- 'offer (list 0 0))
   (define warm-start (current-inexact-monotonic-milliseconds))
   (session-flush! s)
   (define warm-ms (- (current-inexact-monotonic-milliseconds) warm-start))

   (when (for/or ([line (in-list transcript)])
           (regexp-match? #px"^\\(route rerun " line))
     (error 'lattice-perf "unexpected fallback"))
   (unless (for/or ([line (in-list transcript)])
             (regexp-match? #px"^\\(route maintain-lattice-consumers-negative " line))
     (error 'lattice-perf "slice-2 route was not selected"))
   (define best-rows (count-rows s 'best))
   (define reported-rows (count-rows s 'reported))
   (unless (and (= (length best-rows) (sub1 (* 2 n)))
                (= (length reported-rows) n)
                (member "(countrow best 0 1 0 1 0)" best-rows)
                (member "(countrow reported 0 1 0 1 0)" reported-rows))
     (error 'lattice-perf "wrong settled contributor/consumer state"))
   ;; Two live contributors per key initially; the warm deletion removes one.
   ;; Each sidecar entry stores at least arity payload words plus one support
   ;; word.  Tree/index overhead is deliberately excluded from this lower bound.
   (define contributor-rows (length best-rows))
   (define contributor-bytes-lower-bound (* contributor-rows 3 8))
   (printf "m6l-perf-ok n=~a cold-ms=~a warm-ms=~a ratio=~a contributors=~a contributor-bytes-lb=~a\n"
           n
           (real->decimal-string cold-ms 3)
           (real->decimal-string warm-ms 3)
           (real->decimal-string (/ warm-ms (max cold-ms 0.001)) 4)
           contributor-rows contributor-bytes-lower-bound))
 (lambda () (session-close! s)))
