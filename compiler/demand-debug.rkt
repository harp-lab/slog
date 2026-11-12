#lang racket/base
;; Debugging demand relations (docs/demand.md): breakpoint patterns written
;; as Slog terms, and the call tree a run's demand log describes.
;;
;; A demand `(f in ...)` is asked by constructing the struct f and answered
;; by a row of f_ans keyed by it.  The REPL arms one logpoint on those
;; relations (and the transform's `$sup` relations) for a run, and the
;; daemon records each emit into them with its labelled body (the break log,
;; daemon/database.h).  Everything here is the reading of that log:
;;
;;   - an ASK of D is an emit into f; its parent is the call whose rule
;;     asked it.  That rule's gate `(= _d0 (g ...))` is a premise row of g
;;     -- the one demand row in the body with no answer row beside it (a
;;     resumed call is always joined with its answer).  When the ask rule
;;     reads a supplementary relation instead, the gate is the sup row's
;;     own parent, recorded when the sup was emitted.
;;   - an ANSWER of D is an emit into f_ans; its first column is D's id,
;;     which the same gate row names.
;;
;; A call asked by several rules has several parents: the tree shows it
;; under each, and only its first asker owns it.  A call with no answer is
;; where a relation failed -- failure is absence.

(require racket/list
         racket/match
         racket/string
         "catalog.rkt"
         "names.rkt")

(provide catalog-demands
         break-term
         break-guard
         (struct-out calls)
         (struct-out call-node)
         (struct-out call-ask)
         (struct-out call-answer)
         (struct-out logged)
         make-calls
         calls-read!
         calls-node
         calls-lookup
         calls-roots
         calls-frontier
         calls-stack
         call-text
         word-text
         call-answer-text
         call-status)

;; ---- the program's demand relations -------------------------------------

;; name -> (cons input-arity answer-arity) for each struct f with a table
;; f_ans whose first column is f: the pair demand.rkt declares.
(define (catalog-demands declarations)
  (for*/hash ([(name d) (in-hash declarations)]
              #:when (eq? (declaration-descriptor-kind d) 'struct)
              [ans (in-value
                    (hash-ref declarations
                              (symbol->qname
                               (string->symbol
                                (string-append (qname->display name) "_ans")))
                              #f))]
              #:when (and ans
                          (eq? (declaration-descriptor-kind ans) 'table)
                          (pair? (declaration-descriptor-fields ans))
                          (equal? (first (declaration-descriptor-fields ans))
                                  (type-ref 'named name))))
    (values (qname->display name)
            (cons (length (declaration-descriptor-fields d))
                  (sub1 (length (declaration-descriptor-fields ans)))))))

;; ---- patterns -------------------------------------------------------------

;; A Slog term, as read with square brackets tagged, to the daemon's break
;; term (slogd.cpp parse_break_term).  A symbol is a variable, `_` any
;; value, `(c t ...)` a constructor, `[t ... x ...]` a list that starts
;; with the t's.
(define (break-term t)
  (match t
    ['_ '_]
    [(? symbol? x) `(var ,(symbol->string x))]
    [(? exact-integer? n) `(integer ,(number->string n))]
    [(? real? r) `(real ,(number->string (exact->inexact r)))]
    [(? string? s) `(string ,s)]
    [`(#%brackets ,items ...)
     (define-values (prefix open?)
       (match items
         [(list prefix ... (? symbol?) '...) (values prefix #t)]
         [_ (values items #f)]))
     `(,(if open? 'seq-open 'seq) ,@(map break-term prefix))]
    [`(,(? symbol? c) ,args ...) `(ctor ,(symbol->string c) ,@(map break-term args))]
    [_ (error 'break "cannot match on ~s" t)]))

(define guard-ops '(= /= != < <= > >=))

;; `(OP a b)` to the daemon's guard; `!=` is `/=`.
(define (break-guard g)
  (match g
    [`(,(? symbol? op) ,a ,b)
     #:when (memq op guard-ops)
     `(,(if (eq? op '!=) '/= op) ,(break-term a) ,(break-term b))]
    [_ (error 'break "a condition is (OP a b) with OP one of = /= < <= > >=, not ~s" g)]))

;; ---- the call graph -------------------------------------------------------

;; One call: `relation` and its argument words.  Asks and answers are kept
;; newest first; `children` are the calls its rules asked, in first-ask
;; order.
(struct call-node (index relation fields
                   [asks #:mutable] [answers #:mutable]
                   [children #:mutable] [child-set #:mutable])
  #:transparent)
(struct call-ask (parent seq scc iteration source bindings) #:transparent)
(struct call-answer (words seq scc iteration source) #:transparent)
;; A record of the operator's own logpoints.
(struct logged (id seq scc iteration source relation row bindings) #:transparent)

(struct calls (demands answers   ; f -> arities; f_ans -> f
               nodes             ; (cons f fields) -> call-node
               indexed           ; index -> call-node, in first-seen order
               ids               ; demand id word -> key
               sups              ; carrier-key -> the gate it carries, or #f
               values            ; word -> text
               [next #:mutable] [first #:mutable] [dropped #:mutable]
               [last #:mutable]  ; the newest demand event: (cons kind key)
               log-id            ; the logpoint the graph is read from
               [logged #:mutable]) ; other logpoints' records, newest first
  #:transparent)

(define (make-calls demands [log-id "demand-log"])
  (calls demands
         (for/hash ([f (in-hash-keys demands)])
           (values (string-append f "_ans") f))
         (make-hash) (make-hash) (make-hash) (make-hash) (make-hash)
         0 0 0 #f log-id '()))

;; The transform's supplementary relations and the planner's temporaries
;; carry a rule's gate from one of its rules to the next.  Their rows are
;; recognized by content, columns in any order: the row a rule emits and
;; the row a later rule reads it as need not be laid out alike.
(define (carrier? relation)
  (or (string-prefix? relation "$sup") (string-prefix? relation "temp")))
(define (carrier-key row) (cons (car row) (sort (cdr row) <)))

;; Read `lines` -- one (break-log ...) reply -- into the graph.  A reply
;; whose oldest record is past what the graph has read means the daemon's
;; log was cleared by a new event: the graph starts over.  Answers #t when
;; it did.
(define (calls-read! c lines)
  (define data (for/list ([line (in-list lines)])
                 (read (open-input-string line))))
  (define restart?
    (for/or ([d (in-list data)])
      (match d
        [`(break-log-end (records ,_) (next ,_) (first ,first) (dropped ,_))
         (> first (calls-first c))]
        [_ #f])))
  (when restart?
    (hash-clear! (calls-nodes c))
    (hash-clear! (calls-indexed c))
    (hash-clear! (calls-ids c))
    (hash-clear! (calls-sups c))
    (hash-clear! (calls-values c))
    (set-calls-last! c #f)
    (set-calls-logged! c '()))
  (for ([d (in-list data)])
    (match d
      [`(log-value ,w ,text) (hash-set! (calls-values c) w text)]
      [`(break-log-end (records ,_) (next ,next) (first ,first) (dropped ,dropped))
       (set-calls-next! c next)
       (set-calls-first! c first)
       (set-calls-dropped! c dropped)]
      [_ (void)]))
  (for ([d (in-list data)])
    (match d
      [`(log (seq ,seq) (id ,id) (scc ,scc) (iteration ,iteration) (rule ,_)
             (source ,source) (relation ,relation) (row ,row ...)
             (bindings (,names ,words) ...) (driver ,drel ,drow ...)
             (premises (,prels ,prows ...) ...))
       (if (equal? id (calls-log-id c))
           (add-record! c seq scc iteration source relation row
                        (map cons names words)
                        (cons (cons drel drow) (map cons prels prows)))
           (set-calls-logged! c (cons (logged id seq scc iteration source relation row
                                              (map cons names words))
                                      (calls-logged c))))]
      [_ (void)]))
  restart?)

(define (node! c key)
  (or (hash-ref (calls-nodes c) key #f)
      (let ([n (call-node (hash-count (calls-nodes c)) (car key) (cdr key)
                          '() '() '() (make-hash))])
        (hash-set! (calls-nodes c) key n)
        (hash-set! (calls-indexed c) (call-node-index n) n)
        n)))

;; The call whose rule this body belongs to (see the header), or #f.
(define (body-gate c body)
  (define demands (calls-demands c))
  (define answered
    (for/hash ([row (in-list body)]
               #:when (and (hash-ref (calls-answers c) (car row) #f)
                           (pair? (cdr row))))
      (values (cadr row) #t)))
  (or (for/first ([row (in-list body)]
                  #:when (and (hash-ref demands (car row) #f)
                              (pair? (cdr row))
                              (not (hash-ref answered (cadr row) #f))))
        (cons (car row) (cddr row)))
      (for/or ([row (in-list body)] #:when (carrier? (car row)))
        (hash-ref (calls-sups c) (carrier-key row) #f))))

(define (add-record! c seq scc iteration source relation row bindings body)
  ;; every demand row in a body names a call's id beside its arguments
  (for ([b (in-list body)]
        #:when (and (hash-ref (calls-demands c) (car b) #f) (pair? (cdr b))))
    (hash-set! (calls-ids c) (cadr b) (cons (car b) (cddr b))))
  (define gate (body-gate c body))
  (cond
    [(hash-ref (calls-demands c) relation #f)
     (define key (cons relation row))
     (define n (node! c key))
     (set-call-node-asks! n (cons (call-ask gate seq scc iteration source bindings)
                                  (call-node-asks n)))
     (when gate
       (define p (node! c gate))
       (unless (hash-ref (call-node-child-set p) key #f)
         (hash-set! (call-node-child-set p) key #t)
         (set-call-node-children! p (append (call-node-children p) (list key)))))
     (set-calls-last! c (cons 'ask key))]
    [(hash-ref (calls-answers c) relation #f)
     => (lambda (f)
          ;; the answered call is the rule's gate
          (define key (or (hash-ref (calls-ids c) (first row) #f) gate
                          (cons f (list (first row)))))
          (define n (node! c key))
          (set-call-node-answers! n (cons (call-answer (rest row) seq scc iteration source)
                                          (call-node-answers n)))
          (set-calls-last! c (cons 'answer key)))]
    [(carrier? relation) (hash-set! (calls-sups c) (carrier-key (cons relation row)) gate)]))

;; ---- reading it -----------------------------------------------------------

(define (calls-node c index) (hash-ref (calls-indexed c) index #f))

(define (in-calls c)
  (for/list ([i (in-range (hash-count (calls-indexed c)))])
    (hash-ref (calls-indexed c) i)))

(define (calls-lookup c key) (hash-ref (calls-nodes c) key #f))

;; The daemon renders an enum constant as its `_enum` struct; the source
;; spells it `(mt)`.
(define (word-text c w)
  (regexp-replace* #px"\\(_enum \"([^\"\\\\]*)\"\\)"
                   (hash-ref (calls-values c) w (lambda () (format "#<~a>" w)))
                   "(\\1)"))

;; "(infer [] (app (zero) (zero)))"
(define (call-text c n)
  (format "(~a~a)" (call-node-relation n)
          (string-append*
           (for/list ([w (in-list (call-node-fields n))]) (string-append " " (word-text c w))))))

(define (call-answer-text c a)
  (string-join (for/list ([w (in-list (call-answer-words a))]) (word-text c w)) " "))

;; answered | pending (no answer yet, the run goes on) | failed
(define (call-status n running?)
  (cond [(pair? (call-node-answers n)) 'answered]
        [running? 'pending]
        [else 'failed]))

;; Calls no rule asked: the program's own demands.
(define (calls-roots c)
  (for/list ([n (in-list (in-calls c))]
             #:when (for/or ([a (in-list (call-node-asks n))]) (not (call-ask-parent a))))
    n))

;; Where failure starts: calls without an answer whose subcalls all have
;; one.  The rule that asked them could not conclude from those answers.
(define (calls-frontier c)
  (for/list ([n (in-list (in-calls c))]
             #:when (and (null? (call-node-answers n))
                         (for/and ([k (in-list (call-node-children n))])
                           (pair? (call-node-answers (hash-ref (calls-nodes c) k))))))
    n))

;; The chain of calls from `key` up through each first asker, `key` first.
(define (calls-stack c key)
  (let loop ([key key] [seen '()])
    (define n (and key (not (member key seen)) (hash-ref (calls-nodes c) key #f)))
    (if n
        (cons n (loop (let ([asks (call-node-asks n)])
                        (and (pair? asks) (call-ask-parent (last asks))))
                      (cons key seen)))
        '())))
