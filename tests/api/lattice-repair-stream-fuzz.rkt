#lang racket

;; M7 sub-slice (d) differential stream (docs/m7-contract.md, warm fuzz).
;; One session keeps its contributor/rank sidecars warm across ten mixed
;; signed epochs over a cyclic weighted graph (0-weight edges included, so
;; unfounded-cycle repair is exercised).  Every maintained flush is
;; compared -- content AND contributor sidecars -- with a fresh, unseeded
;; clear-and-rerun session over the same normalized edge set, which also
;; recounts its sidecars from scratch.  Regressing flushes must take the
;; m7 repair route; the cone must never rebuild.

(require "../../compiler/session.rkt")

(define args (current-command-line-arguments))
(define seed (string->number (vector-ref args 0)))
(define epochs (if (> (vector-length args) 1)
                   (string->number (vector-ref args 1))
                   10))
(random-seed seed)

(define universe
  (for*/list ([x (in-range 1 5)] [y (in-range 1 5)] [w '(0 1 3)]
              #:unless (= x y))
    (list x y w)))
(define initial (list->set (take (shuffle universe) 9)))

(define-values (reverse-flushes reverse-models _final-model)
  (for/fold ([fs '()] [models (list initial)] [present initial])
            ([_ (in-range epochs)])
    (define touched (take (shuffle universe) (+ 4 (random 5))))
    (define ops
      (for/list ([fact (in-list touched)])
        (list (if (set-member? present fact) '- '+) fact)))
    (define next
      (for/fold ([p present]) ([op (in-list ops)])
        (if (eq? (first op) '+)
            (set-add p (second op))
            (set-remove p (second op)))))
    (values (cons ops fs) (cons next models) next)))
(define stream (reverse reverse-flushes))
(define models (reverse reverse-models))

(define base-program "tests/session/m7_rec_min.slog")

(define (dump-tuples s rel)
  (define rows '())
  (session-action! s `(dump-tuples ,rel)
    (lambda (out)
      (let loop ()
        (define line (read-line out))
        (cond
          [(eof-object? line) (void)]
          [(regexp-match? #px"^\\(tupledone " line) (void)]
          [(regexp-match? #px"^\\(tuplerow " line)
           (set! rows (cons line rows))
           (loop)]
          [else (loop)]))))
  (sort rows string<?))

(define (dump-count-rows s rel)
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
  (sort rows string<?))

(define (snapshot s) (list (cons 'dist (dump-tuples s 'dist))))
(define (count-snapshot s) (list (cons 'dist (dump-count-rows s 'dist))))

(define (with-session echo proc)
  (define s (make-session #:echo echo))
  (dynamic-wind void (lambda () (proc s)) (lambda () (session-close! s))))

(define transcript '())
(define streamed
  (with-session
   (lambda (line) (set! transcript (cons line transcript)))
   (lambda (s)
     (session-run! s base-program)
     (define snapshots '())
     (define seen 0)
     (define (repaired-since-last-capture!)
       (define new (- (length transcript) seen))
       (set! seen (length transcript))
       (for/or ([line (in-list (take transcript new))])
         (regexp-match? #px"^\\(route maintain-lattice-recursive-negative "
                        line)))
     (define (capture! step)
       ;; The maintained session is never recounted here: the point is to
       ;; carry the exact repaired cache across every epoch.  The fresh
       ;; oracle below owns the independent recount comparison.  A REPAIR
       ;; flush ends with the post-repair refresh, so its cache must be
       ;; present-and-exact; a reenter flush drops the cache (§8B.2's lazy
       ;; protocol), so absent is legal there -- exact or absent, never
       ;; wrong.
       (set! snapshots (cons (list (snapshot s) (count-snapshot s)
                                   (repaired-since-last-capture!))
                             snapshots)))
     (for ([fact (in-set initial)])
       (match-define (list x y w) fact)
       (session-batch! s '+ 'edge (list x y w)))
     (session-flush! s)
     (capture! 0)
     (for ([ops (in-list stream)] [step (in-naturals 1)])
       (for ([op (in-list ops)])
         (match-define (list sign (list x y w)) op)
         (session-batch! s sign 'edge (list x y w)))
       (session-flush! s)
       (capture! step))
     (reverse snapshots))))

(when (for/or ([line (in-list transcript)])
        (regexp-match? #px"^\\(route rerun " line))
  (eprintf "m7-fuzz-FAIL seed ~a unexpectedly rebuilt the cone\n" seed)
  (exit 1))
(unless (for/or ([line (in-list transcript)])
          (regexp-match? #px"^\\(route maintain-lattice-recursive-negative "
                         line))
  (eprintf "m7-fuzz-FAIL seed ~a never used the repair route\n" seed)
  (exit 1))

(define oracle
  (for/list ([model (in-list models)])
    (with-session void
      (lambda (s)
        (session-run! s base-program)
        (define path (format "out/m7-oracle-~a-edge.rows" seed))
        (call-with-output-file path #:exists 'replace
          (lambda (out)
            (for ([fact (in-set model)])
              (fprintf out "~a ~a ~a\n"
                       (first fact) (second fact) (third fact)))))
        (session-action! s `(set-overlay-int-file edge ,path 3)
                         (lambda (out) (void (read-line out))))
        (session-rerun! s 'edge)
        (session-recount! s #:force? #t #:lattices? #t)
        (list (snapshot s) (count-snapshot s))))))

(define failed #f)
(for ([got (in-list streamed)] [want (in-list oracle)] [step (in-naturals)])
  (match-define (list content counts repaired?) got)
  (match-define (list want-content want-counts) want)
  (define counts-empty?
    (for/and ([kv (in-list counts)]) (null? (cdr kv))))
  (unless (and (equal? content want-content)
               (cond
                 [repaired? (equal? counts want-counts)]  ; refresh: exact
                 [counts-empty? #t]                       ; lazily dropped
                 [else (equal? counts want-counts)]))     ; present => exact
    (set! failed #t)
    (eprintf "m7-fuzz-FAIL seed ~a step ~a repaired=~a\n  streamed: ~s\n  oracle:   ~s\n"
             seed step repaired? got want)))
(when failed (exit 1))

(printf "m7-fuzz-ok ~a\n" seed)
