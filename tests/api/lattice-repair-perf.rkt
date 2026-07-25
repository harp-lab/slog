#lang racket

;; Non-flaky M7 performance + sidecar-memory gate (docs/m7-contract.md
;; sub-slice (d)).  Cold = initial derivation flush + contributor
;; establishment over a weighted chain with shortcut losers; warm = a
;; one-edge deletion repaired from stored contributors.  Correct
;; route/state are hard gates; timings and the contributor/rank storage
;; lower bounds are trend data for CI.

(require "../../compiler/session.rkt")

(define args (current-command-line-arguments))
(define n (if (positive? (vector-length args))
              (string->number (vector-ref args 0))
              48))
(unless (and (exact-positive-integer? n) (>= n 6))
  (error 'lattice-repair-perf "expected a chain length of at least 6"))

(define transcript '())
(define (dump-lines s action done-rx row-rx)
  (define rows '())
  (session-action! s action
    (lambda (out)
      (let loop ()
        (define line (read-line out))
        (cond
          [(eof-object? line) (void)]
          [(regexp-match? done-rx line) (void)]
          [(regexp-match? row-rx line)
           (set! rows (cons line rows))
           (loop)]
          [else (loop)]))))
  rows)
(define (count-rows s rel)
  (dump-lines s `(dump-counts ,rel) #px"^\\(countdone " #px"^\\(countrow "))
(define (rank-rows s rel)
  (dump-lines s `(dump-ranks ,rel) #px"^\\(rankdone " #px"^\\(rankrow "))

(define s (make-session
           #:echo (lambda (line) (set! transcript (cons line transcript)))))
(dynamic-wind
 void
 (lambda ()
   (session-run! s "tests/session/m7_rec_min.slog")
   ;; chain i -> i+1 weight 1, with shortcut losers i -> i+2 weight 3
   (for ([i (in-range 1 n)])
     (session-batch! s '+ 'edge (list i (add1 i) 1)))
   (for ([i (in-range 1 (sub1 n))])
     (session-batch! s '+ 'edge (list i (+ i 2) 3)))
   (define cold-start (current-inexact-monotonic-milliseconds))
   (session-flush! s)
   (define cold-ms (- (current-inexact-monotonic-milliseconds) cold-start))

   ;; deleting the chain head regresses every (1, j) key to shortcut routes
   (session-batch! s '- 'edge (list 1 2 1))
   (define warm-start (current-inexact-monotonic-milliseconds))
   (session-flush! s)
   (define warm-ms (- (current-inexact-monotonic-milliseconds) warm-start))

   (when (for/or ([line (in-list transcript)])
           (regexp-match? #px"^\\(route rerun " line))
     (error 'lattice-repair-perf "unexpected fallback"))
   (unless (for/or ([line (in-list transcript)])
             (regexp-match?
              #px"^\\(route maintain-lattice-recursive-negative " line))
     (error 'lattice-repair-perf "the repair route was not selected"))

   (define contributors (count-rows s 'dist))
   (define ranks (rank-rows s 'dist))
   (when (null? contributors)
     (error 'lattice-repair-perf "post-repair contributor cache is absent"))
   ;; storage lower bound: key columns + payload/word, 8 bytes each
   (define row-words 4)   ; dist arity 3 + sidecar word
   (printf "m7-perf-ok n=~a cold-ms=~a warm-ms=~a ratio=~a contributors=~a contributor-bytes-lb=~a ranks=~a rank-bytes-lb=~a\n"
           n
           (real->decimal-string cold-ms 3)
           (real->decimal-string warm-ms 3)
           (real->decimal-string (/ warm-ms (max cold-ms 1e-9)) 4)
           (length contributors)
           (* 8 row-words (length contributors))
           (length ranks)
           (* 8 row-words (length ranks))))
 (lambda () (session-close! s)))
