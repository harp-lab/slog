#lang racket

;; M4T signed-stream differential oracle (docs/m4t-contract.md).  Random edge
;; toggles over a small vertex universe drive a recursive transitive closure
;; plus an acyclic downstream consumer that reads the swept relation twice.
;; Each flush also toggles one direct assertion on the recursive head itself
;; (foundation-aware overlay, M4T slice 2): only rows this stream directly
;; asserted are ever retracted, so every retraction is overlay-legal.  The
;; warm maintained session's content and support sidecars after every flush
;; must equal a fresh run over that normalized EDB with a forced recount.
;; Cycles, unfounded regions, reseeds, relearns, head-edit candidacy, and
;; the cancelling downstream cascade all arise from the random stream.

(require "../../compiler/session.rkt")

(define args (current-command-line-arguments))
(define seed (string->number (vector-ref args 0)))
(random-seed seed)

(define rules #<<EOF
table (edge int int)
table (path int int)
table (two int int)

rule (edge X Y) --> (path X Y)
rule (path X Y) (edge Y Z) --> (path X Z)
rule (path X Y) (path Y Z) --> (two X Z)
EOF
)

;; Every directed pair over 5 vertices, self-loops included: dense enough
;; that random streams routinely create and cut cycles.
(define universe
  (for*/list ([x (in-range 5)] [y (in-range 5)]) (cons x y)))
(define initial (list->set (take (shuffle universe) 6)))

(define-values (flushes reverse-models _final-model)
  (for/fold ([fs '()]
             [models (list (cons initial (set)))]
             [present (cons initial (set))])
            ([_ (in-range 10)])
    (match-define (cons edges heads) present)
    (define touched (take (shuffle universe) (+ 2 (random 4))))
    (define edge-ops
      (for/list ([f (in-list touched)])
        (list (if (set-member? edges f) '- '+) 'edge f)))
    ;; One direct toggle on the recursive head per flush: retract only rows
    ;; this stream asserted, so the overlay op is always legal regardless of
    ;; what the rules currently derive.
    (define h (car (shuffle universe)))
    (define head-ops
      (list (list (if (set-member? heads h) '- '+) 'path h)))
    (define ops (append edge-ops head-ops))
    (define next
      (for/fold ([p present]) ([op (in-list ops)])
        (match-define (list sign rel f) op)
        (match-define (cons e ph) p)
        (if (eq? rel 'edge)
            (cons (if (eq? sign '+) (set-add e f) (set-remove e f)) ph)
            (cons e (if (eq? sign '+) (set-add ph f) (set-remove ph f))))))
    (values (cons ops fs) (cons next models) next)))
(define stream (reverse flushes))
(define models (reverse reverse-models))

(define base-prog (format "out/m4t-fuzz-~a-base.slog" seed))
(call-with-output-file base-prog #:exists 'replace
  (lambda (o) (displayln rules o)))

(define (dump-rows s rel)
  (define rows '())
  (session-action! s `(dump-rel ,rel)
    (lambda (out)
      (let loop ()
        (define line (read-line out))
        (cond
          [(eof-object? line) (void)]
          [(regexp-match? #px"^\\(dumpdone " line) (void)]
          [(regexp-match #px"^\\(dumprow (.*)\\)\\s*$" line)
           => (lambda (m) (set! rows (cons (cadr m) rows)) (loop))]
          [else (loop)]))))
  (sort rows string<?))

(define (snapshot s)
  (for/list ([r '(edge path two)]) (cons r (dump-rows s r))))

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
           (set! rows (cons line rows)) (loop)]
          [else (loop)]))))
  (sort rows string<?))

(define (derived-counts s)
  (for/list ([r '(path two)]) (cons r (dump-count-rows s r))))

(define (with-session proc)
  (define s (make-session))
  (define v (proc s))
  (session-close! s)
  v)

(define streamed
  (with-session
   (lambda (s)
     (session-run! s base-prog)
     (define snapshots '())
     (define (capture!)
       ;; The warm session is never force-recounted: maintained sidecars must
       ;; stand on their own against the fresh oracle below.
       (set! snapshots (cons (list (snapshot s) (derived-counts s))
                             snapshots)))
     (for ([f (in-set initial)])
       (session-batch! s '+ 'edge (list (car f) (cdr f))))
     (session-flush! s)
     (capture!)
     (for ([ops (in-list stream)])
       (for ([op (in-list ops)])
         (match-define (list sign rel f) op)
         (session-batch! s sign rel (list (car f) (cdr f))))
       (session-flush! s)
       (capture!))
     (reverse snapshots))))

(define oracle
  (for/list ([model (in-list models)])
    (match-define (cons edge-model head-model) model)
    (with-session
     (lambda (s)
       (session-run! s base-prog)
       (define (seed-overlay! rel facts suffix)
         (define path (format "out/m4t-oracle-~a-~a.rows" seed suffix))
         (call-with-output-file path #:exists 'replace
           (lambda (out)
             (for ([fact (in-set facts)])
               (fprintf out "~a ~a\n" (car fact) (cdr fact)))))
         (session-action! s `(set-overlay-int-file ,rel ,path 2)
                          (lambda (out) (void (read-line out)))))
       (seed-overlay! 'edge edge-model "edge")
       (seed-overlay! 'path head-model "path")
       (session-rerun! s 'edge)
       (session-recount! s #:force? #t)
       (list (snapshot s) (derived-counts s))))))

(unless (equal? streamed oracle)
  (for ([w (in-list streamed)] [o (in-list oracle)] [i (in-naturals)])
    (unless (equal? w o)
      (eprintf "m4t-fuzz-FAIL seed ~a flush ~a\n  streamed: ~s\n  oracle:   ~s\n"
               seed i w o)))
  (exit 1))

(printf "m4t-fuzz-ok ~a\n" seed)
