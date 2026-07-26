#lang racket

;; Independent, deliberately slow support-count oracle for canonical `_count`
;; cprogs.  It interprets the relational subset of the emitted operational IR
;; over immutable Racket sets, first to a from-scratch least fixpoint and then
;; once more to enumerate every final rule instantiation by support kind.  It
;; shares no daemon indices, task scheduler, sidecar arithmetic, or recount
;; code.  Unsupported IR fails loudly instead of blessing a partial result.
;;
;;   racket tests/api/count-ir-oracle.rkt build/A_count.cprog ...

;; Output uses the daemon's `(countrow REL ... input nonrec rec)` shape so the
;; session battery can sort/diff it directly.

(require racket/set
         racket/match
         racket/file
         "../../compiler/ir-stack.rkt")

(define argv (vector->list (current-command-line-arguments)))
(define versioned? (and (pair? argv) (equal? (car argv) "--versioned")))
(define pipeline-path (and versioned? (second argv)))
(define ledger-path (and versioned? (third argv)))
(define paths (if versioned? (drop argv 3) argv))
(when (and (null? paths) (not versioned?))
  (error 'count-ir-oracle "expected at least one _count.cprog path"))
(define (read-cprog path)
  ;; The compiler's diagnostic artifact pretty-prints its dynamic relation set
  ;; as `#<set: ...>`, which is intentionally not reader syntax.  That field is
  ;; irrelevant to this interpreter; make just that display form readable.
  (define text
    (regexp-replace*
     #px"#<set:([^>]*)>" (file->string path)
     (lambda (_all members) (format "(oracle-dynamic ~a)" members))))
  (define p (read (open-input-string text)))
  (match p
    [`(cprog ,_ ,(? hash?) (,_ ...) (,_ ...)) p]
    [_ (error 'count-ir-oracle "malformed cprog ~a: ~s" path p)]))
(struct vprog (program relmap) #:transparent)

(define pipeline-form
  (and versioned? (call-with-input-file pipeline-path read)))
(define ledger-forms
  (if versioned?
      (call-with-input-file ledger-path
        (lambda (in)
          (let loop ([out '()])
            (define x (read in))
            (if (eof-object? x) (reverse out) (loop (cons x out))))))
      '()))

(define-values (stratum-forms version-forms)
  (if versioned?
      (match pipeline-form
        [`(pipeline (pos ,_) (evaluation ,_) (update-epoch ,_)
                    (strata ,ss ...) (version-ids ,vis ...) ,_ ...)
         (values ss vis)]
        ;; Compatibility with M0.4 logs captured before settled-state
        ;; revisions became part of pipeline introspection.
        [`(pipeline (pos ,_) (evaluation ,_) (strata ,ss ...)
                    (version-ids ,vis ...) ,_ ...)
         (values ss vis)]
        [_ (error 'count-ir-oracle "malformed pipeline form: ~s" pipeline-form)])
      (values '() '())))

(define path-by-hash
  (for/hash ([path (in-list paths)])
    (define m (regexp-match #px"/([0-9a-f]{8})_count\\.cprog$" path))
    (unless m
      (error 'count-ir-oracle "cannot recover stratum hash from ~a" path))
    (values (second m) path)))

(define programs
  (if versioned?
      (for/list ([st (in-list stratum-forms)] [instance (in-naturals)]
                 #:when (match st [`(s ,_ ,_ ,_ (kind semantic) ,_ ...) #t] [_ #f]))
        (match-define `(s ,_scc ,_pos ,hash (kind semantic)
                          (reads ,reads ...) (write-map ,writes ...)
                          (writes ,_ ...)) st)
        (define path
          (hash-ref path-by-hash hash
                    (lambda ()
                      (error 'count-ir-oracle "no _count.cprog for semantic stratum ~a" hash))))
        (define p (read-cprog path))
        (define exact
          (for/hash ([b (in-list (append reads writes))])
            (values (first b) (second b))))
        ;; Every declared compiler-local relation is instance-local too.  Exact
        ;; semantic bindings override this synthetic namespace.
        (define relmap
          (for/fold ([m exact]) ([d (in-list (cprog-decls p))])
            (define name (second d))
            (if (hash-has-key? m name) m
                (hash-set m name (cons instance name)))))
        (vprog p relmap))
      (for/list ([p (in-list (map read-cprog paths))])
        (vprog p (hash)))))

(define current-relmap (make-parameter (hash)))
(define (rel-key rel) (hash-ref (current-relmap) rel rel))

;; rel -> immutable set of nominal tuples (lists)
(define db (make-hash))
(define temp-names
  (for*/set ([vp (in-list programs)] [d (in-list (cprog-decls (vprog-program vp)))]
             #:when (eq? (car d) 'temp))
    (hash-ref (vprog-relmap vp) (second d) (second d))))
(define lattice-specs
  (for*/hash ([vp (in-list programs)] [d (in-list (cprog-decls (vprog-program vp)))]
              #:when (eq? (car d) 'lattice))
    (values (hash-ref (vprog-relmap vp) (second d) (second d)) (fourth d))))
(define ignored-names
  (set '_enum 'error 'type_mismatch 'toint_range 'smt_bad_formula
       'nan_result 'mpz_table_overflow 'mpz_overflow 'modulo_by_zero
       'malformed_deduction 'int_overflow 'div_by_zero))

(define (rows rel) (hash-ref db rel (set)))
(define (resolve env x)
  (define (arg y) (resolve env y))
  (cond [(hash-has-key? env x) (hash-ref env x)]
        [(or (number? x) (string? x) (boolean? x)) x]
        [(pair? x)
         (match x
           [`(_0002b ,xs ...) (apply + (map arg xs))] ; +
           [`(_0002d ,a ,b) (- (arg a) (arg b))]      ; -
           [`(_0002a ,xs ...) (apply * (map arg xs))] ; *
           [e (error 'count-ir-oracle "unsupported operational expression: ~s" e)])]
        [else (error 'count-ir-oracle "unbound operational variable ~a" x)]))

(define (insert-tuple! rel tuple)
  (define old (rows rel))
  (define spec (hash-ref lattice-specs rel #f))
  (cond
    [(not spec)
     (if (set-member? old tuple) #f
         (begin (hash-set! db rel (set-add old tuple)) #t))]
    [else
     (define key (drop-right tuple 1))
     (define prior
       (for/first ([row (in-set old)] #:when (equal? (drop-right row 1) key)) row))
     (define kind (first spec))
     (define candidate (last tuple))
     (define improve?
       (or (not prior)
           (case kind
             [(min) (< candidate (last prior))]
             [(max) (> candidate (last prior))]
             [(flat) (not (equal? candidate (last prior)))]
             [else (error 'count-ir-oracle "unsupported lattice spec: ~s" spec)])))
     (if (not improve?) #f
         (begin
           (hash-set! db rel (set-add (if prior (set-remove old prior) old) tuple))
           #t))]))

(define (unify env vars vals)
  (for/fold ([e env]) ([v (in-list vars)] [x (in-list vals)] #:break (not e))
    (cond [(hash-has-key? e v) (and (equal? (hash-ref e v) x) e)]
          [else (hash-set e v x)])))

(define (nominal->ordered tuple ordering)
  (for/list ([col (in-list ordering)]) (list-ref tuple col)))

(define (ordered->nominal vals ordering)
  (define out (make-vector (length ordering)))
  (for ([v (in-list vals)] [col (in-list ordering)])
    (vector-set! out col v))
  (vector->list out))

(define (join-envs env rel ordering vars)
  (filter values
          (for/list ([tuple (in-set (rows rel))])
            (unify env vars (nominal->ordered tuple ordering)))))

(define (apply-op env op)
  (match op
    [`(let ,x ,y) (list (hash-set env x (resolve env y)))]
    [`(,(or 'join 'join-lat) ,rel ,ordering ,_k ,vars ...)
     (join-envs env (rel-key rel) ordering vars)]
    [`(join-old ,rel ,ordering ,_k ,_delta-ordering ,vars ...)
     ;; Count flavor enumerates the settled full relation.  A join-old is not
     ;; expected there today, but its full-side meaning is unambiguous.
     (join-envs env (rel-key rel) ordering vars)]
    [`(exists ,rel ,ordering ,_k ,vars ...)
     (if (pair? (join-envs env (rel-key rel) ordering vars)) (list env) '())]
    [`(,(or 'absent 'absent-lat) ,rel ,ordering ,_k ,vars ...)
     (if (null? (join-envs env (rel-key rel) ordering vars)) (list env) '())]
    [`(eq ,x ,y) (if (equal? (resolve env x) (resolve env y)) (list env) '())]
    [`(neq ,x ,y) (if (equal? (resolve env x) (resolve env y)) '() (list env))]
    [x (error 'count-ir-oracle "unsupported operational body op: ~s" x)]))

(define (apply-ops envs ops)
  (for/fold ([es envs]) ([op (in-list ops)])
    (append-map (lambda (e) (apply-op e op)) es)))

(struct emission (rel tuple) #:transparent)

;; Head ops are sequential because mkstruct binds the nominal struct value for
;; following emits.  Struct identity is represented content-canonically as
;; `(name field ...)`, which is exactly the daemon dump's rendered value.
(define (apply-head env hops)
  (let loop ([e env] [hs hops] [out '()])
    (match hs
      ['() (reverse out)]
      [(cons hop more)
       (match hop
         [`(emit ,rel ,ordering ,vars ...)
          (define tuple
            (ordered->nominal (map (lambda (v) (resolve e v)) vars) ordering))
          (loop e more (cons (emission (rel-key rel) tuple) out))]
         [`(emit-temp ,rel ,vars ...)
          (loop e more
                (cons (emission (rel-key rel)
                                (map (lambda (v) (resolve e v)) vars)) out))]
         [`(emit-lat ,rel ,vars ...)
          (loop e more
                (cons (emission (rel-key rel)
                                (map (lambda (v) (resolve e v)) vars)) out))]
         [`(mkstruct ,rel ,ordering ,id-var ,fields ...)
         (define fvals (map (lambda (v) (resolve e v)) fields))
         (define id (cons rel fvals))
         (define e2 (hash-set e id-var id))
          ;; mkstruct's ordering is the master index: fields first, id last.
          (define tuple (ordered->nominal (append fvals (list id)) ordering))
          (loop e2 more (cons (emission (rel-key rel) tuple) out))]
         [`(let ,x ,y)
          (loop (hash-set e x (resolve e y)) more out)]
         [x (error 'count-ir-oracle "unsupported operational head op: ~s" x)])])))

(define (constant-env p)
  ;; cprog constants are value -> generated variable.
  (for/hash ([(value var) (in-hash (cprog-constants p))])
    (values var value)))

(define (rule-envs p rule)
  (define base (apply-ops (list (constant-env p)) (crule-pre rule)))
  (define driven
    (match (crule-driver rule)
      [`(,(or 'once 'seeded)) base]
      [`(scan ,rel ,vars ...)
       (append-map (lambda (e) (join-envs e (rel-key rel)
                                         (range (length vars)) vars)) base)]
      [`(probe ,rel ,ordering ,_k ,vars ...)
       (append-map (lambda (e) (join-envs e (rel-key rel) ordering vars)) base)]
      [x (error 'count-ir-oracle "unsupported operational driver: ~s" x)]))
  (apply-ops driven (crule-body rule)))

(define (rule-emissions p rule)
  (append-map (lambda (e) (apply-head e (crule-head rule)))
              (rule-envs p rule)))

;; Version metadata and normalized input foundations.  Relation keys are
;; VersionIds in versioned mode, so rename aliases cannot duplicate state.
(define vid-info
  (for/fold ([h (hash)]) ([vi (in-list version-forms)])
    (match vi
      [`(vid ,name ,_ord ,vid ,pred ,_key
             (schema ,arity ,sid ,storage) ,_identity-fields ...)
       (if (hash-has-key? h vid) h
           (hash-set h vid (list name pred sid storage arity)))])))
(define masks (make-hash)) ; VersionId -> immutable tuple set
(for ([row (in-list ledger-forms)])
  (match row
    [`(inputledger direct ,vid ,_name ,vals ...)
     (hash-set! db vid (set-add (rows vid) vals))]
    [`(inputledger mask ,vid ,_name ,vals ...)
     (hash-update! masks vid (lambda (s) (set-add s vals)) (set))]
    [`(inputledger-done ,_) (void)]
    [_ (error 'count-ir-oracle "malformed input-ledger row: ~s" row)]))

(define inheritance
  (for/list ([(vid info) (in-hash vid-info)] #:when (positive? (second info)))
    (list vid (second info))))

(define (propagate-inheritance!)
  (for/fold ([changed? #f]) ([edge (in-list inheritance)])
    (match-define (list child pred) edge)
    (for/fold ([changed? changed?]) ([tuple (in-set (rows pred))])
      (cond
        [(set-member? (hash-ref masks child (set)) tuple) changed?]
        [else (or (insert-tuple! child tuple) changed?)]))))

;; Desugared from-scratch evaluation.  Programs are semantic strata in recipe
;; order; each closes before the next, preserving stratified-negation meaning.
;; Inheritance is an ordinary monotone edge and is refreshed during each
;; stratum fixpoint.
(for ([vp (in-list programs)])
  (parameterize ([current-relmap (vprog-relmap vp)])
    (define p (vprog-program vp))
    (let fixpoint ()
      (define changed? (propagate-inheritance!))
      (for* ([rule (in-list (cprog-rules p))]
             [em (in-list (rule-emissions p rule))])
        (when (insert-tuple! (emission-rel em) (emission-tuple em))
          (set! changed? #t)))
      (when changed? (fixpoint)))))
(let loop () (when (propagate-inheritance!) (loop)))

;; Enumerate support on the settled fixpoint.  Each satisfying assignment and
;; each emitting head contributes once, even if set materialization deduped it.
(define counts (make-hash)) ; (cons rel tuple) -> mutable vector input/nonrec/rec
(define kind-index (hash 'input 0 'nonrec 1 'rec 2))
(define (count-key rel tuple)
  (if (and versioned? (integer? rel)
           (positive? (third (hash-ref vid-info rel '(unknown 0 0)))))
      (list (first tuple))
      tuple))
(define (countable-version? rel)
  (define info (hash-ref vid-info rel '(unknown 0 0 set 1)))
  (and (positive? (fifth info)) (not (eq? (fourth info) 'lattice))))
(define (add-count! rel tuple kind)
  (define key (cons rel (count-key rel tuple)))
  (define cs (hash-ref! counts key (lambda () (vector 0 0 0))))
  (define i (hash-ref kind-index kind))
  (if (zero? i)
      (vector-set! cs i 1)
      (vector-set! cs i (add1 (vector-ref cs i)))))

;; Authoritative foundations are not rule emissions.
(when versioned?
  (for ([row (in-list ledger-forms)])
    (match row
      [`(inputledger direct ,vid ,_name ,vals ...) (add-count! vid vals 'input)]
      [_ (void)]))
  (for ([edge (in-list inheritance)])
    (match-define (list child pred) edge)
    (for ([tuple (in-set (rows pred))]
          #:unless (set-member? (hash-ref masks child (set)) tuple))
      (add-count! child tuple 'nonrec))))

(for ([vp (in-list programs)])
  (parameterize ([current-relmap (vprog-relmap vp)])
    (define p (vprog-program vp))
    (for ([rule (in-list (cprog-rules p))])
      (define kind (crule-kind rule))
      (unless (hash-has-key? kind-index kind)
        (error 'count-ir-oracle "cprog is not a classified count flavor: ~s" kind))
      (for ([em (in-list (rule-emissions p rule))])
        (add-count! (emission-rel em) (emission-tuple em) kind)))))

(define visible
  (sort
   (for/list ([(key cs) (in-hash counts)]
              #:unless
              (or (set-member? temp-names (car key))
                  (and versioned? (integer? (car key))
                       (not (countable-version? (car key))))
                  (and (not versioned?)
                       (or (set-member? ignored-names (car key))
                           (string-prefix? (symbol->string (car key)) "$")))))
     (list (car key) (cdr key) cs))
   string<? #:key ~s))
(for ([row (in-list visible)])
  (match-define (list rel tuple cs) row)
  (write (if versioned?
             `(vcountrow ,rel ,@tuple ,@(vector->list cs))
             `(countrow ,rel ,@tuple ,@(vector->list cs))))
  (newline))
