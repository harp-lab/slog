#lang racket

;; M4T scheduling stress: force a large recursive counted deletion through
;; pause/resume boundaries.  K disjoint diamonds-with-tails each lose one
;; support in a single flush: odd diamonds lose their upper edge route, and
;; even diamonds lose a direct assertion on the recursive head itself (the
;; foundation-aware overlay verb, M4T slice 2).  Either way the sweep
;; over-deletes a rec-positive candidate, reseed restores it, and the
;; rebuild relearns the tail -- all while SLOG_MAX_MS forces suspensions.
;; Run with small SLOG_MAX_MS and explicit SLOG_THREADS.

(require "../../compiler/session.rkt")

(define args (current-command-line-arguments))
(define k (if (positive? (vector-length args))
              (string->number (vector-ref args 0))
              800))
(unless (exact-positive-integer? k)
  (error 'recursive-pause-stress "expected diamond count K"))

(define prog (format "out/m4t-pause-~a.slog" k))
(call-with-output-file prog #:exists 'replace
  (lambda (o)
    (displayln "table (edge int int)" o)
    (displayln "table (path int int)" o)
    (displayln "rule (edge X Y) --> (path X Y)" o)
    (displayln "rule (path X Y) (edge Y Z) --> (path X Z)" o)))

(define transcript '())
(define (record! line) (set! transcript (cons line transcript)))
(define (one-line out)
  (define line (read-line out))
  (when (eof-object? line) (error 'recursive-pause-stress "daemon EOF"))
  line)

;; Diamond i (vertices 5i..5i+4): a->b->d, a->c->d, tail d->e.  An odd
;; diamond deletes a->b: path(a,b) reaches zero, path(a,d) is over-deleted
;; (rec 2 -> 1, no foundation) and reseeded, path(a,e) is relearned.  An
;; even diamond instead deletes a direct assertion on path(a,d) itself:
;; the head edit over-deletes it (rec 2 survives), reseed restores it, and
;; path(a,e) is relearned; its edges and content are unchanged.
(define (v i off) (+ (* 5 i) off))
(define all-edges
  (append*
   (for/list ([i (in-range k)])
     (list (list (v i 0) (v i 1)) (list (v i 1) (v i 3))
           (list (v i 0) (v i 2)) (list (v i 2) (v i 3))
           (list (v i 3) (v i 4))))))
(define even-count (quotient (+ k 1) 2))
(define odd-count (- k even-count))

(define s (make-session #:echo record!))
(dynamic-wind
 void
 (lambda ()
   (session-run! s prog)
   ;; Stay under the inline-batch ceiling per flush.
   (for ([chunk (in-slice 2000 (in-list all-edges))])
     (for ([e (in-list chunk)])
       (session-batch! s '+ 'edge e))
     (session-flush! s))
   ;; Direct assertions on already-derived head rows for the even diamonds:
   ;; no content change, but the later retraction must take the
   ;; foundation-aware verb.
   (for ([chunk (in-slice 2000 (for/list ([i (in-range k)] #:when (even? i))
                                 (list (v i 0) (v i 3))))])
     (for ([t (in-list chunk)])
       (session-batch! s '+ 'path t))
     (session-flush! s))
   (set! transcript '())
   (for ([i (in-range k)])
     (if (even? i)
         (session-batch! s '- 'path (list (v i 0) (v i 3)))
         (session-batch! s '- 'edge (list (v i 0) (v i 1)))))
   (session-flush! s)

   (define chronological (reverse transcript))
   (define sweep-start
     (for/first ([line (in-list chronological)] [i (in-naturals)]
                 #:when (regexp-match? #px"^\\(route maintain-recursive-negative "
                                       line))
       i))
   (unless sweep-start
     (error 'recursive-pause-stress "deletion did not enter the M4T sweep"))
   (unless (for/or ([line (in-list chronological)] [i (in-naturals)])
             (and (> i sweep-start) (regexp-match? #px"^\\(paused " line)))
     (error 'recursive-pause-stress
            "recursive maintenance did not pause; increase K or lower SLOG_MAX_MS"))
   (define reseed-line
     (for/first ([line (in-list chronological)]
                 #:when (regexp-match? #px"^\\(dred-reseeded " line))
       line))
   ;; Every diamond reseeds its path(a,d); an odd diamond also discards
   ;; path(a,b) and path(a,e), an even one discards only path(a,e).
   (unless (equal? reseed-line
                   (format "(dred-reseeded ~a ~a)"
                           k (+ (* 2 odd-count) even-count)))
     (error 'recursive-pause-stress "unexpected reseed report: ~s" reseed-line))
   (unless (for/or ([line (in-list chronological)])
             (regexp-match? #px"^\\(route maintain-positive " line))
     (error 'recursive-pause-stress "reseed did not trigger the rebuild"))
   (unless (for/or ([line (in-list chronological)])
             (regexp-match? #px"^\\(update-committed [0-9]+ counts-valid\\)"
                            line))
     (error 'recursive-pause-stress "epoch did not settle counts-valid"))

   (define pipeline-line (session-action! s `(pipeline) one-line))
   (define tip-pos
     (match (read (open-input-string pipeline-line))
       [`(pipeline (pos ,p) ,_ ...) p]
       [x (error 'recursive-pause-stress "bad pipeline reply: ~s" x)]))
   (define size-line (session-action! s `(sizes-at ,tip-pos) one-line))
   (define sizes
     (match (read (open-input-string size-line))
       [`(sizes-at ,(== tip-pos) ,rows ...)
        (for/hash ([row (in-list rows)])
          (match-define `(,name ,size) row)
          (values name size))]
       [x (error 'recursive-pause-stress "bad sizes reply: ~s" x)]))
   (unless (and (= (hash-ref sizes 'edge -1) (- (* 5 k) odd-count))
                (= (hash-ref sizes 'path -1) (- (* 9 k) odd-count)))
     (error 'recursive-pause-stress "wrong settled sizes: ~s" sizes))

   ;; A fresh version-local count round must accept the maintained contents.
   (session-recount! s #:force? #t)
   (define state-line (session-action! s `(count-state) one-line))
   (match (read (open-input-string state-line))
     [`(count-state ,entries ...)
      (for ([name '(edge path)])
        (unless (for/or ([entry (in-list entries)])
                  (match entry
                    [`(cnt ,n 0 1) (eq? n name)]
                    [_ #f]))
          (error 'recursive-pause-stress "uncounted relation ~a: ~s"
                 name entries)))]
     [x (error 'recursive-pause-stress "bad count-state reply: ~s" x)])
   (printf "m4t-pause-stress-ok ~a pauses=~a\n" k
           (count (lambda (line) (regexp-match? #px"^\\(paused " line))
                  transcript)))
 (lambda () (session-close! s)))
