#lang racket

;; M4N derived-negated boundary hammer (slice 4): reachability with a
;; negated DERIVED complement reader whose positive premise (mark) is
;; itself edited.  The flush generator deliberately cycles route classes
;; -- edge-only gains (producer-precise, reader-precise), mark gains
;; beside edge churn (the journal-sign fallback: reader-suffix rerun),
;; edge losses (loss-only precise), mark losses (precise) -- with random
;; content inside each class, so both sides of the journal-sign decision
;; are exercised every run and diffed against the fresh oracle plus a
;; forced recount.  The negated atom carries a CONSTANT first column
;; (the body-constant fix stays in the loop).

(require "../../compiler/session.rkt")

(define args (current-command-line-arguments))
(define seed (string->number (vector-ref args 0)))
(random-seed seed)

(define rules #<<EOF
table (edge int int)
table (node int)
table (mark int)
table (path int int)
table (unreached int)

rule (node 1) (node 2) (node 3) (node 4) (node 5)

rule (edge X Y) --> (path X Y)
rule (path X Y) (edge Y Z) --> (path X Z)

rule (node X) (mark X) ~(path 1 X) --> (unreached X)
EOF
)

(define edge-universe
  (for*/list ([i (in-range 1 6)] [j (in-range 1 6)] #:unless (= i j))
    (list 'edge i j)))
(define mark-universe (for/list ([x (in-range 1 6)]) (list 'mark x)))

(define initial
  (set-union (list->set (take (shuffle edge-universe) 4))
             (list->set (take (shuffle mark-universe) 3))))

(define (sample pool present want-present? k)
  (define avail
    (shuffle (for/list ([f (in-list pool)]
                        #:when (eq? (set-member? present f) want-present?))
               f)))
  (take avail (min k (length avail))))

;; Ten flushes cycling the four route classes.
(define-values (flushes reverse-models _final)
  (for/fold ([fs '()] [models (list initial)] [present initial])
            ([step (in-range 10)])
    (define ops
      (case (modulo step 4)
        [(0) ; edge gains only: derived route, precise readers
         (for/list ([f (in-list (sample edge-universe present #f 2))])
           (list '+ f))]
        [(1) ; mark gain + edge churn: the suffix-rerun boundary
         (append
          (for/list ([f (in-list (sample mark-universe present #f 1))])
            (list '+ f))
          (for/list ([f (in-list (sample edge-universe present #f 1))])
            (list '+ f)))]
        [(2) ; edge losses only: loss-only precise
         (for/list ([f (in-list (sample edge-universe present #t 2))])
           (list '- f))]
        [(3) ; mark loss + edge loss: precise
         (append
          (for/list ([f (in-list (sample mark-universe present #t 1))])
            (list '- f))
          (for/list ([f (in-list (sample edge-universe present #t 1))])
            (list '- f)))]))
    (define next
      (for/fold ([p present]) ([op (in-list ops)])
        (if (eq? (first op) '+) (set-add p (second op))
            (set-remove p (second op)))))
    (values (cons ops fs) (cons next models) next)))
(define stream (reverse flushes))
(define models (reverse reverse-models))

(define base-prog (format "out/m4n-dfuzz-~a-base.slog" seed))
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
  (for/list ([rel '(edge mark path unreached)]) (cons rel (dump-rows s rel))))

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
  (for/list ([rel '(path unreached)]) (cons rel (dump-count-rows s rel))))

(define (with-session proc #:echo [echo void])
  (define s (make-session #:echo echo))
  (define v (proc s))
  (session-close! s)
  v)

(define route-log '())
(define streamed
  (with-session
   #:echo (lambda (line) (set! route-log (cons line route-log)))
   (lambda (s)
     (session-run! s base-prog)
     (define snapshots '())
     (define (capture!)
       ;; NON-forced: a no-op state check while the maintained sidecar is
       ;; valid (drift stays visible), a legitimate fresh establishment
       ;; after a suffix-rerun flush cleared the cache (counts are
       ;; recomputable cache, never persistent truth).
       (session-recount! s)
       (set! snapshots (cons (list (snapshot s) (derived-counts s)) snapshots)))
     (for ([f (in-set initial)])
       (session-batch! s '+ (first f) (rest f)))
     (session-flush! s)
     (capture!)
     (for ([ops (in-list stream)])
       (for ([op (in-list ops)])
         (session-batch! s (first op) (first (second op)) (rest (second op))))
       (session-flush! s)
       (capture!))
     (reverse snapshots))))

;; Both sides of the journal-sign boundary must have fired.
(define (saw? rx)
  (for/or ([line (in-list route-log)]) (regexp-match? rx line)))
(unless (saw? #px"route maintain-negated-derived-negative")
  (eprintf "m4n-derived-fuzz-FAIL seed ~a: precise derived route never fired\n" seed)
  (exit 1))
(unless (saw? #px"route maintain-producers-rerun-readers")
  (eprintf "m4n-derived-fuzz-FAIL seed ~a: suffix-rerun fallback never fired\n" seed)
  (exit 1))

(define (overlay! s rel arity model)
  (define path (format "out/m4n-dfuzz-~a-~a.rows" seed rel))
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
       (overlay! s 'edge 2 model)
       (overlay! s 'mark 1 model)
       (session-rerun! s 'edge)
       (session-rerun! s 'mark)
       (session-recount! s #:force? #t)
       (list (snapshot s) (derived-counts s))))))

(unless (equal? streamed oracle)
  (eprintf "m4n-derived-fuzz-FAIL seed ~a\n" seed)
  (for ([got (in-list streamed)] [want (in-list oracle)] [i (in-naturals)]
        #:unless (equal? got want))
    (eprintf "  flush ~a:\n    streamed: ~s\n    oracle:   ~s\n" i got want))
  (exit 1))

(printf "m4n-derived-fuzz-ok ~a\n" seed)
