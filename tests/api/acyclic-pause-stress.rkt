#lang racket

;; M3 scheduling stress: force a large acyclic counted update through several
;; pause/resume boundaries, then check the settled set sizes and a fresh recount.
;; Run with a small SLOG_MAX_MS and an explicit SLOG_THREADS value.

(require "../../compiler/session.rkt")

(define args (current-command-line-arguments))
(define n (if (positive? (vector-length args))
              (string->number (vector-ref args 0))
              450))
(define removed (if (> (vector-length args) 1)
                    (string->number (vector-ref args 1))
                    150))
(unless (and (exact-positive-integer? n)
             (exact-nonnegative-integer? removed)
             (< removed n))
  (error 'acyclic-pause-stress "expected N and 0 <= REMOVED < N"))

(define prog (format "out/m3-pause-~a-~a.slog" n removed))
(call-with-output-file prog #:exists 'replace
  (lambda (o)
    (displayln "table (a int)" o)
    (displayln "table (p int)" o)
    (displayln "table (pair int int)" o)
    (displayln "rule (a X) --> (p X)" o)
    (displayln "rule (a X) (a Y) --> (pair X Y)" o)))

(define transcript '())
(define (record! line) (set! transcript (cons line transcript)))
(define (one-line out)
  (define line (read-line out))
  (when (eof-object? line) (error 'acyclic-pause-stress "daemon EOF"))
  line)

(define s (make-session #:echo record!))
(dynamic-wind
 void
 (lambda ()
   (session-run! s prog)
   (for ([x (in-range n)]) (session-batch! s '+ 'a (list x)))
   (session-flush! s)
   (for ([x (in-range removed)]) (session-batch! s '- 'a (list x)))
   (session-flush! s)

   (define pipeline-line (session-action! s `(pipeline) one-line))
   (define tip-pos
     (match (read (open-input-string pipeline-line))
       [`(pipeline (pos ,p) ,_ ...) p]
       [x (error 'acyclic-pause-stress "bad pipeline reply: ~s" x)]))
   (define size-line (session-action! s `(sizes-at ,tip-pos) one-line))
   (define sizes
     (match (read (open-input-string size-line))
       [`(sizes-at ,(== tip-pos) ,rows ...)
        (for/hash ([row (in-list rows)])
          (match-define `(,name ,size) row)
          (values name size))]
       [x (error 'acyclic-pause-stress "bad sizes reply: ~s" x)]))
   (define remain (- n removed))
   (unless (and (= (hash-ref sizes 'a -1) remain)
                (= (hash-ref sizes 'p -1) remain)
                (= (hash-ref sizes 'pair -1) (* remain remain)))
     (error 'acyclic-pause-stress "wrong settled sizes: ~s" sizes))

   (unless (for/or ([line (in-list transcript)])
             (regexp-match? #px"^\\(paused " line))
     (error 'acyclic-pause-stress
            "time budget did not force a pause; increase N or lower SLOG_MAX_MS"))
   (unless (for/or ([line (in-list transcript)])
             (regexp-match? #px"^\\(route maintain-negative " line))
     (error 'acyclic-pause-stress "negative update did not enter M3"))

   ;; A fresh version-local count round must accept the maintained contents.
   (session-recount! s #:force? #t)
   (define state-line (session-action! s `(count-state) one-line))
   (match (read (open-input-string state-line))
     [`(count-state ,entries ...)
      (for ([name '(a p pair)])
        (unless (for/or ([entry (in-list entries)])
                  (match entry
                    [`(cnt ,n 0 1) (eq? n name)]
                    [_ #f]))
          (error 'acyclic-pause-stress "uncounted relation ~a: ~s" name entries)))]
     [x (error 'acyclic-pause-stress "bad count-state reply: ~s" x)])
   (printf "m3-pause-stress-ok ~a ~a pauses=~a\n"
           n removed
           (count (lambda (line) (regexp-match? #px"^\\(paused " line))
                  transcript)))
 (lambda () (session-close! s)))
