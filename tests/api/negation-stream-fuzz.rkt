#lang racket

;; M4N signed-stream differential oracle (slice 4): one program carrying
;; BOTH negation reader classes -- acyclic (h := a ~b; hs adds the sibling
;; pair ~b ~c) and the recursive sweep (r closure with a negated endpoint
;; blocker) -- under ten mixed-sign flushes over positives AND negated
;; inputs.  Every flush's content and maintained sidecars must equal a
;; fresh run over the normalized EDB plus a forced recount.

(require "../../compiler/session.rkt")

(define args (current-command-line-arguments))
(define seed (string->number (vector-ref args 0)))
(random-seed seed)

(define rules #<<EOF
table (a int)
table (b int)
table (c int)
table (h int)
table (hs int)
table (e int int)
table (blk int)
table (r int int)

rule (a X) ~(b X) --> (h X)
rule (a X) ~(b X) ~(c X) --> (hs X)
rule (e X Y) ~(blk Y) --> (r X Y)
rule (r X Y) (e Y Z) ~(blk Z) --> (r X Z)
EOF
)

(define universe
  (append (for/list ([x (in-range 7)]) (list 'a x))
          (for/list ([x (in-range 7)]) (list 'b x))
          (for/list ([x (in-range 7)]) (list 'c x))
          (for/list ([x (in-range 6)]) (list 'blk x))
          (for*/list ([i (in-range 6)] [d (in-list '(1 2))])
            (list 'e i (modulo (+ i d) 6)))))
(define initial (list->set (take (shuffle universe) 8)))

(define-values (flushes reverse-models _final)
  (for/fold ([fs '()] [models (list initial)] [present initial])
            ([_ (in-range 10)])
    (define touched (take (shuffle universe) (+ 3 (random 5))))
    (define ops
      (for/list ([f (in-list touched)])
        (list (if (set-member? present f) '- '+) f)))
    (define next
      (for/fold ([p present]) ([op (in-list ops)])
        (if (eq? (first op) '+) (set-add p (second op))
            (set-remove p (second op)))))
    (values (cons ops fs) (cons next models) next)))
(define stream (reverse flushes))
(define models (reverse reverse-models))

(define base-prog (format "out/m4n-fuzz-~a-base.slog" seed))
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
  (for/list ([rel '(a b c h hs e blk r)]) (cons rel (dump-rows s rel))))

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
  (for/list ([rel '(h hs r)]) (cons rel (dump-count-rows s rel))))

(define (with-session proc)
  (define s (make-session))
  (define v (proc s))
  (session-close! s)
  v)

(define (send-fact! s op f)
  (session-batch! s op (first f) (rest f)))

(define streamed
  (with-session
   (lambda (s)
     (session-run! s base-prog)
     (define snapshots '())
     (define (capture!)
       (set! snapshots (cons (list (snapshot s) (derived-counts s)) snapshots)))
     (for ([f (in-set initial)]) (send-fact! s '+ f))
     (session-flush! s)
     (capture!)
     (for ([ops (in-list stream)])
       (for ([op (in-list ops)]) (send-fact! s (first op) (second op)))
       (session-flush! s)
       (capture!))
     (reverse snapshots))))

(define (overlay! s rel arity model)
  (define path (format "out/m4n-fuzz-~a-~a.rows" seed rel))
  (call-with-output-file path #:exists 'replace
    (lambda (out)
      (for ([fact (in-set model)] #:when (eq? (first fact) rel))
        (displayln (string-join (map number->string (rest fact)) " ") out))))
  (session-action! s `(set-overlay-int-file ,rel ,path ,arity)
                   (lambda (out) (void (read-line out)))))

(define oracle
  (for/list ([model (in-list models)])
    (with-session
     (lambda (s)
       (session-run! s base-prog)
       (for ([spec '((a 1) (b 1) (c 1) (blk 1) (e 2))])
         (overlay! s (first spec) (second spec) model))
       (session-rerun! s 'a)
       (session-rerun! s 'e)
       (session-recount! s #:force? #t)
       (list (snapshot s) (derived-counts s))))))

(unless (equal? streamed oracle)
  (eprintf "m4n-fuzz-FAIL seed ~a\n" seed)
  (for ([got (in-list streamed)] [want (in-list oracle)] [i (in-naturals)]
        #:unless (equal? got want))
    (eprintf "  flush ~a:\n    streamed: ~s\n    oracle:   ~s\n" i got want))
  (exit 1))

(printf "m4n-fuzz-ok ~a\n" seed)
