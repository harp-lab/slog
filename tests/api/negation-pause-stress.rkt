#lang racket

;; M4N scheduling stress (slice 4): force a large anti-delta negative
;; phase through pause/resume boundaries at a small SLOG_MAX_MS, then
;; check settled sizes, pause attribution to the negation stratum's
;; maintenance flavor, and a fresh forced recount.

(require "../../compiler/session.rkt")

(define args (current-command-line-arguments))
(define n (if (positive? (vector-length args))
              (string->number (vector-ref args 0))
              450))
(define blocked (if (> (vector-length args) 1)
                    (string->number (vector-ref args 1))
                    150))
(unless (and (exact-positive-integer? n)
             (exact-nonnegative-integer? blocked)
             (< blocked n))
  (error 'negation-pause-stress "expected N and 0 <= BLOCKED < N"))

(define prog (format "out/m4n-pause-~a-~a.slog" n blocked))
(call-with-output-file prog #:exists 'replace
  (lambda (o)
    (displayln "table (a int)" o)
    (displayln "table (b int)" o)
    (displayln "table (hp int int)" o)
    (displayln "rule (a X) (a Y) ~(b X) --> (hp X Y)" o)))

(define transcript '())
(define (record! line) (set! transcript (cons line transcript)))
(define (one-line out)
  (define line (read-line out))
  (when (eof-object? line) (error 'negation-pause-stress "daemon EOF"))
  line)

(define s (make-session #:echo record!))
(dynamic-wind
 void
 (lambda ()
   (session-run! s prog)
   (for ([x (in-range n)]) (session-batch! s '+ 'a (list x)))
   (session-flush! s)
   ;; Cold-path pauses are not the assertion; the anti-delta negative
   ;; phase below must pause on its own.
   (set! transcript '())
   (for ([x (in-range blocked)]) (session-batch! s '+ 'b (list x)))
   (session-flush! s)

   (define pipeline-line (session-action! s `(pipeline) one-line))
   (define tip-pos
     (match (read (open-input-string pipeline-line))
       [`(pipeline (pos ,p) ,_ ...) p]
       [x (error 'negation-pause-stress "bad pipeline reply: ~s" x)]))
   (define size-line (session-action! s `(sizes-at ,tip-pos) one-line))
   (define sizes
     (match (read (open-input-string size-line))
       [`(sizes-at ,(== tip-pos) ,rows ...)
        (for/hash ([row (in-list rows)])
          (match-define `(,name ,size) row)
          (values name size))]
       [x (error 'negation-pause-stress "bad sizes reply: ~s" x)]))
   (define survivors (- n blocked))
   (unless (and (= (hash-ref sizes 'a -1) n)
                (= (hash-ref sizes 'b -1) blocked)
                (= (hash-ref sizes 'hp -1) (* survivors n)))
     (error 'negation-pause-stress "wrong settled sizes: ~s" sizes))

   (define chronological (reverse transcript))
   (define negated-start
     (for/first ([line (in-list chronological)] [i (in-naturals)]
                 #:when (regexp-match? #px"^\\(route maintain-negated-negative "
                                       line))
       i))
   (unless negated-start
     (error 'negation-pause-stress "gained blocker did not enter M4N"))
   ;; Attribution: pauses AFTER the negated route line, on the negation
   ;; stratum's negative maintenance flavor.
   (define attributed
     (for/sum ([line (in-list chronological)] [i (in-naturals)])
       (if (and (> i negated-start)
                (regexp-match? #px"^\\(paused .*_maint3neg" line))
           1 0)))
   (when (zero? attributed)
     (error 'negation-pause-stress
            "anti-delta negative phase did not pause on _maint3neg; increase N or lower SLOG_MAX_MS"))

   (session-recount! s #:force? #t)
   (define state-line (session-action! s `(count-state) one-line))
   (match (read (open-input-string state-line))
     [`(count-state ,entries ...)
      (for ([name '(a b hp)])
        (unless (for/or ([entry (in-list entries)])
                  (match entry
                    [`(cnt ,m 0 1) (eq? m name)]
                    [_ #f]))
          (error 'negation-pause-stress "uncounted relation ~a: ~s"
                 name entries)))]
     [x (error 'negation-pause-stress "bad count-state reply: ~s" x)])
   (printf "m4n-pause-stress-ok ~a ~a maint3neg-pauses=~a\n"
           n blocked attributed))
 (lambda () (session-close! s)))
