#lang racket

;; M3 signed-stream differential oracle.  Every editable a/b fact enters via
;; the JIT overlay, flushes freely mix legal additions and retractions, and the
;; acyclic closure after every flush must equal a fresh run over that
;; normalized EDB.  Maintained sidecars are also checked against forced recount.

(require "../../compiler/session.rkt")

(define args (current-command-line-arguments))
(define seed (string->number (vector-ref args 0)))
(random-seed seed)

(define rules #<<EOF
table (a int)
table (b int)
table (p int)
table (q int)
table (pair int int)

rule (a X) --> (p X)
rule (b X) --> (p X)
rule (a X) (a Y) --> (pair X Y)
rule (p X) --> (q X)
EOF
)

(define universe
  (append (for/list ([x (in-range 7)]) (cons 'a x))
          (for/list ([x (in-range 7)]) (cons 'b x))))
(define initial (list->set (take (shuffle universe) 5)))

;; Five batches of distinct toggles.  Sampling from the whole universe allows
;; delete/re-add cycles across batches while each batch still has one final op
;; per tuple after normalization.
(define-values (flushes reverse-models _final-model)
  (for/fold ([fs '()] [models (list initial)] [present initial])
            ([_ (in-range 5)])
    (define touched (take (shuffle universe) (+ 2 (random 4))))
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

(define base-prog (format "out/m3-fuzz-~a-base.slog" seed))
(define (write-prog path facts)
  (call-with-output-file path #:exists 'replace
    (lambda (o)
      (displayln rules o)
      (unless (set-empty? facts)
        (newline o)
        (displayln "rule" o)
        (for ([f (in-list (sort (set->list facts)
                                (lambda (x y)
                                  (or (symbol<? (car x) (car y))
                                      (and (eq? (car x) (car y))
                                           (< (cdr x) (cdr y)))))))])
          (fprintf o "(~a ~a)\n" (car f) (cdr f)))))))
(write-prog base-prog (set))

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
  (for/list ([r '(a b p q pair)]) (cons r (dump-rows s r))))

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
  (for/list ([r '(p q pair)]) (cons r (dump-count-rows s r))))

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
     (define (capture! step)
       (define result (snapshot s))
       (define maintained (derived-counts s))
       (session-recount! s #:force? #t)
       (define recounted (derived-counts s))
       (unless (equal? maintained recounted)
         (eprintf "m3-count-fuzz-FAIL seed ~a step ~a\n  maintained: ~s\n  recounted:  ~s\n"
                  seed step maintained recounted)
         (exit 1))
       (set! snapshots (cons result snapshots)))
     (for ([f (in-set initial)])
       (session-batch! s '+ (car f) (list (cdr f))))
     (session-flush! s)
     (capture! 0)
     (for ([ops (in-list stream)] [step (in-naturals 1)])
       (for ([op (in-list ops)])
         (define f (second op))
         (session-batch! s (first op) (car f) (list (cdr f))))
       (session-flush! s)
       (capture! step))
     (reverse snapshots))))

(define oracle
  (for/list ([model (in-list models)] [step (in-naturals)])
    (define oracle-prog (format "out/m3-fuzz-~a-oracle-~a.slog" seed step))
    (write-prog oracle-prog model)
    (with-session
     (lambda (s) (session-run! s oracle-prog) (snapshot s)))))

(unless (equal? streamed oracle)
  (eprintf "m3-fuzz-FAIL seed ~a\n  streamed: ~s\n  oracle:   ~s\n"
           seed streamed oracle)
  (exit 1))

(printf "m3-fuzz-ok ~a\n" seed)
