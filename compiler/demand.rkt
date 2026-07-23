#lang racket

;; The demand transform: desugars demand-moded relations into plain rules
;; over two backing relations (design notes: docs/demand.md).
;;
;;   demand (f in ...) out ...        declares
;;     struct (f in ...)              the demand: asking IS constructing
;;     table  (f_ans f out ...)       answers, keyed by the demand's id
;;
;; Four phases run per program, in order:
;;
;;   V. VAR CALLS.  A form whose head is a bound variable rather than a
;;      declared name is a first-class value being invoked.  Nested,
;;      (f x ...) denotes the answer and becomes an applyN call; as a
;;      whole clause, (f x ... r) reads judgment-style (last argument the
;;      answer) and becomes an applyN occurrence.  The applyN judgments
;;      and the `clo` closure union are synthesized on first use, with
;;      any-typed argument/answer columns (untyped defunctionalization;
;;      users extend `clo` and add applyN rules for hand-rolled closures).
;;
;;   L. LAMBDAS.  (lambda (x ...) body) -- when `lambda` is not itself a
;;      declared relation -- lifts to a closure constructor capturing the
;;      body's free variables (a struct, or an enum constant when nothing
;;      is captured), joins the `clo` union, and generates one answering
;;      rule  (applyN (lamK captured...) x ... body).  Closure names come
;;      from the source position, so they are deterministic.
;;
;;   C. CALLS.  A demand-arity occurrence of a judgment nested in an
;;      argument position is a call denoting the answer (single-answer
;;      judgments only): it extracts to a fresh variable plus a full-arity
;;      body occurrence.  (= x (f a ...)) binds an answer, exactly like a
;;      primitive computation (= x (+ a b)).  The demand struct itself is
;;      still reachable by content in f_ans's key column -- (f_ans (f a)
;;      r) -- which is the escape hatch's join form; a clause-level
;;      (f a ...) is still an ask (head) or enumeration (body).
;;
;;   MAIN.  Judgment occurrences -- (f in... out...) at full arity as
;;      whole clauses -- desugar:
;;      in a head, a gate clause (= d (f in...)) joins the demand in the
;;      body (the rule fires only for demands that exist, binding the
;;      pattern) and the head becomes (f_ans d out...);
;;      in a body, an *ask rule* derives the demand as soon as the
;;      clauses grounding its inputs can fire, and the occurrence becomes
;;      the join (= d (f in...)) (f_ans d out...), resuming when answers
;;      arrive.  Because demands are content-interned, resumes find them
;;      by reconstruction; no continuation relation is needed.
;;
;; Ask rules are scheduled by groundness, in stages: every non-judgment
;; clause runs as soon as its inputs are ground; every body judgment
;; whose demand arguments are ground asks, with all clauses included so
;; far as its rule body (the most restrictive prefix available); its
;; answers extend the ground set for the next stage.  Judgments ready in
;; the same stage ask in parallel.  A demand argument that can never
;; ground is a mode error.
;;
;; The output is plain pre-simplification slog; no pass below this one
;; knows demands, calls, or lambdas exist.  Generated names are
;; deterministic (no gensym): this pass runs before the .so cache key is
;; computed over the module rules (see program->jobs in compile.rkt), so
;; unstable names here would bust the cache on every run.

(provide desugar-demand-program desugar-demand-rules demand-ans-name)

(require "ir-shared.rkt")
(require "simplification.rkt")
(require "lexer.rkt")
(require "utils.rkt")

;; The generated answer table's name.  User-visible: naming it directly is
;; the escape hatch for enumeration and direct answer access.
(define (demand-ans-name name)
  (string->symbol (format "~a_ans" name)))

;; -----------------------------------------------------------------------
;; Program entry point (called by modules.rkt after env merging).
;;
;; mods     : list of (list path toks rules)
;; demands  : hash, relation name -> (cons input-arity answer-arity)
;; type-env : the program's merged type environment
;;
;; Returns (values mods+ rel-decls union-members) where rel-decls is a
;; hash of synthesized declarations (closure structs/enums, applyN
;; backing relations) for modules.rkt to merge into the type env, and
;; union-members the synthesized `clo` union's member set (empty when no
;; lambdas or var calls appeared).

(define (desugar-demand-program mods demands type-env)
  (define ctx (make-ctx demands type-env))
  (define mods+
    (for/list ([m (in-list mods)])
      (match-define (list path toks rules) m)
      (list path toks (transform-rules rules ctx))))
  ;; generated apply rules go through the transform themselves (their
  ;; judgment heads need gates); synthesis is closed after one round
  ;; because generated rules contain no lambdas or var calls
  (define gen (transform-rules (unbox (ctx-gen-rules ctx)) ctx))
  (define mods++
    (if (set-empty? gen)
        mods+
        (match mods+
          [(cons (list path toks rules) rest)
           (cons (list path toks (set-union rules gen)) rest)])))
  (values mods++ (unbox (ctx-rels ctx)) (unbox (ctx-clo-members ctx))))

;; Rules-only wrapper (unit tests; also usable when no synthesis matters).
(define (desugar-demand-rules rules demands type-env)
  (define-values (mods+ rels clo)
    (desugar-demand-program (list (list "m" '() rules)) demands type-env))
  (third (first mods+)))

(define (transform-rules rules ctx)
  (for*/set ([rule (in-set rules)]
             [r (in-list (rewrite-rule rule ctx))])
    r))

;; -----------------------------------------------------------------------
;; The synthesis context: declarations and rules generated by the lambda
;; and var-call phases, plus the demand registry (extended with applyN).

(struct ctx (demands rels clo-members gen-rules type-env) #:transparent)

(define (make-ctx demands type-env)
  (ctx (box demands) (box (hash)) (box (set)) (box (set)) type-env))

(define (ctx-demand ctx name) (hash-ref (unbox (ctx-demands ctx)) name #f))

(define (declared? ctx name)
  (or (hash-has-key? (type-env-rels (ctx-type-env ctx)) name)
      (hash-has-key? (type-env-funs (ctx-type-env ctx)) name)
      (hash-has-key? (unbox (ctx-demands ctx)) name)))

(define special-heads '(= /= == & let const rule -->))

(define (special-head? s)
  (or (memq s special-heads) (equal? "|" (symbol->string s))))

;; Ensure the applyN judgment for call arity n exists; returns its name.
(define (ensure-apply! ctx n)
  (define name (string->symbol (format "apply~a" n)))
  (unless (ctx-demand ctx name)
    (set-box! (ctx-demands ctx)
              (hash-set (unbox (ctx-demands ctx)) name (cons (add1 n) 1)))
    (set-box! (ctx-rels ctx)
              (hash-set* (unbox (ctx-rels ctx))
                         name `(struct clo ,@(make-list n 'any))
                         (demand-ans-name name) `(table ,name any))))
  name)

;; -----------------------------------------------------------------------
;; Occurrence recognition.

;; A judgment occurrence: (f args ...) at full arity at the top of a
;; clause.  Returns (list prov name demand-args answer-args) or #f.
(define (judgment-parts cl ctx)
  (match cl
    [`(syn ,p ,(? symbol? name) ,args ...)
     (match (ctx-demand ctx name)
       [(cons nd na)
        #:when (= (length args) (+ nd na))
        (list p name (take args nd) (drop args nd))]
       [_ #f])]
    [_ #f]))

;; -----------------------------------------------------------------------
;; Validation.  Full-arity judgment occurrences are legal only as whole
;; clauses; other arities of a demand-moded name must be the demand
;; (struct) arity.  Raises on misuse; errors carry the source rule.

(define (demand-arity-error name nd na args rule)
  (error 'demand
         (string-append
          "~a is demand-moded and takes ~a input column~a and ~a answer"
          " column~a; it cannot be used with ~a argument~a in\n~a")
         name nd (if (= nd 1) "" "s") na (if (= na 1) "" "s")
         (length args) (if (= (length args) 1) "" "s") (strip-prov rule)))

(define (validate-term! e ctx rule [top #f])
  (match e
    [`(syn ,_ const ,_) (void)]
    [`(syn ,_ ,(? symbol? name) ,args ...)
     (match (ctx-demand ctx name)
       [(cons nd na)
        (cond
          [(= (length args) nd) (void)]
          [(and top (= (length args) (+ nd na))) (void)]
          [(= (length args) (+ nd na))
           (error 'demand
                  (string-append
                   "value-position use of demand-moded relation ~a at full"
                   " arity: a judgment occurrence must be a clause of its own"
                   " (a nested call takes only the ~a input~a), in\n~a")
                  name nd (if (= nd 1) "" "s") (strip-prov rule))]
          [else (demand-arity-error name nd na args rule)])]
       [#f (void)])
     (for ([a (in-list args)]) (validate-term! a ctx rule))]
    [`(syn ,_ ,es ...)
     (for ([a (in-list es)]) (validate-term! a ctx rule))]
    [_ (void)]))

(define (validate-clause! cl ctx rule)
  (match cl
    [`(syn ,_ = ,(? symbol?) (syn ,_ ,(? symbol? name) ,args ...))
     (match (ctx-demand ctx name)
       [(cons nd na)
        #:when (= (length args) (+ nd na))
        (error 'demand
               "a judgment occurrence of ~a cannot be bound to an id, in\n~a"
               name (strip-prov rule))]
       [_ (void)])
     (validate-term! (fourth cl) ctx rule)]
    ;; a negated demand-moded judgment has no meaning: answers are grown
    ;; lazily on demand, so "no answer" is an evaluation artifact, not a
    ;; fact about the relation (docs/incremental.md §0.8)
    [`(syn ,_ ~ ,inner ,_ ...)
     (match inner
       [`(syn ,_ ,(? symbol? name) ,_ ...)
        #:when (ctx-demand ctx name)
        (error 'demand
               "demand-moded relation ~a cannot be negated: absence of a lazily-grown answer is not observable, in\n~a"
               name (strip-prov rule))]
       [_ (void)])
     (validate-term! inner ctx rule)]
    [_ (validate-term! cl ctx rule #t)]))

;; Judgment arguments exclude clause-level connectives, except the alias
;; form x=(pattern ...): it names the matched sub-term in place, and
;; simplification's nested-= flattening lifts it out of the gate or
;; answer join it lands in, binding x alongside the pattern's variables.
(define (validate-judgment-args! args name rule)
  (define (bad-connective e)
    (match e
      [`(syn ,_ ,(? symbol? s) ,_ ...)
       (and (or (memq s '(& = /= == ~)) (equal? "|" (symbol->string s))) s)]
      [_ #f]))
  (let walk ([es args])
    (for ([e (in-list es)])
      (match e
        [`(syn ,_ = ,(? symbol? x) ,(and pat `(syn ,_ ,(? symbol?) ,_ ...)))
         #:when (not (eq? x '_))
         (walk (list pat))]
        [_
         (define s (bad-connective e))
         (when s
           (error 'demand
                  "~a is not allowed inside the judgment occurrence of ~a, in\n~a"
                  s name (strip-prov rule)))
         (match e
           [`(syn ,_ ,(? symbol?) ,sub ...) (walk sub)]
           [_ (void)])]))))

;; -----------------------------------------------------------------------
;; Variable analysis over pre-simplification terms.  Bare symbols in
;; argument positions are variables (enum constants are written
;; parenthesized); the wildcard _ is not a variable.  A match binds its
;; pattern variables but not the inputs of nested primitive calls.

(define (term-match-vars e fun-env)
  ;; (values bound needed)
  (match e
    ['_ (values (set) (set))]
    [(? symbol? x) (values (set x) (set))]
    [`(syn ,_ const ,_) (values (set) (set))]
    ;; seq-pat items (collections.rkt): raw (elem x)/(splice x)/(elemc v)
    ;; lists inside a neutral sequence-pattern clause.  Like a relation
    ;; match, the clause over-approximates as binding all its variables
    ;; (whichever direction the expansion picks, the vars ground together).
    [`(,(or 'elem 'splice) ,(? symbol? x))
     (if (eq? x '_) (values (set) (set)) (values (set x) (set)))]
    [`(elemc ,_) (values (set) (set))]
    [`(syn ,_ ,(? symbol? f) ,args ...)
     (if (hash-has-key? fun-env f)
         (values (set) (terms-all-vars args))
         (terms-match-vars args fun-env))]
    [`(syn ,_ ,es ...) (terms-match-vars es fun-env)]
    [_ (values (set) (set))]))

(define (terms-match-vars es fun-env)
  (for/fold ([bound (set)] [needed (set)]) ([e (in-list es)])
    (define-values (b n) (term-match-vars e fun-env))
    (values (set-union bound b) (set-union needed n))))

(define (terms-all-vars es)
  (let walk ([e es] [acc (set)])
    (match e
      ['_ acc]
      [(? symbol? x) (set-add acc x)]
      [`(syn ,_ const ,_) acc]
      [`(syn ,_ ,(? symbol?) ,args ...) (foldl walk acc args)]
      [`(syn ,_ ,es ...) (foldl walk acc es)]
      [(? list? l) (foldl walk acc l)]
      [_ acc])))

(define (term-has-wildcard? e)
  (match e
    ['_ #t]
    [`(syn ,_ const ,_) #f]
    [`(syn ,_ ,(? symbol?) ,args ...) (ormap term-has-wildcard? args)]
    [`(syn ,_ ,es ...) (ormap term-has-wildcard? es)]
    [_ #f]))

;; (cons needs grounds) of a non-judgment body clause, for ask scheduling.
(define (clause-mode cl fun-env)
  (match cl
    [`(syn ,_ /= ,args ...) (cons (terms-all-vars args) (set))]
    [`(syn ,_ == ,args ...) (cons (terms-all-vars args) (set))]
    [`(syn ,_ ,(? primitive-cmp?) ,args ...) (cons (terms-all-vars args) (set))]
    ;; a negated atom is a pure check, like a guard: it needs its (non-
    ;; wildcard) variables ground and binds nothing (docs/incremental.md §0.8)
    [`(syn ,_ ~ ,args ...) (cons (terms-all-vars args) (set))]
    [`(syn ,_ = ,(? symbol? x) (syn ,_ const ,_))
     (cons (set) (if (eq? x '_) (set) (set x)))]
    [`(syn ,_ = ,(? symbol? x) ,(? symbol? y))
     (cons (set) (list->set (remq* '(_) (list x y))))]
    [`(syn ,_ = ,(? symbol? x) (syn ,_ ,(? symbol? f) ,args ...))
     (if (hash-has-key? fun-env f)
         (cons (terms-all-vars args) (if (eq? x '_) (set) (set x)))
         (let-values ([(bound needed) (terms-match-vars args fun-env)])
           (cons needed (if (eq? x '_) bound (set-add bound x)))))]
    [`(syn ,_ = ,args ...) (cons (terms-all-vars args) (set))]
    [`(syn ,_ ,(? symbol? _) ,args ...)
     (let-values ([(bound needed) (terms-match-vars args fun-env)])
       (cons needed bound))]
    [_ (cons (set) (set))]))

;; -----------------------------------------------------------------------
;; Deterministic fresh names: a prefix no symbol in the rule shares.

(define (fresh-var-base clauses stem)
  (define all (terms-all-vars clauses))
  (let loop ([base stem])
    (if (for/or ([s (in-set all)]) (string-prefix? (symbol->string s) base))
        (loop (string-append base (substring stem 1)))
        base)))

;; -----------------------------------------------------------------------
;; Phases V and L: var calls and lambda lifting, one bottom-up rewrite.

;; Bound symbols of a rule: everything in argument position plus lambda
;; parameters (over-approximate across sibling lambdas; a var-call on a
;; symbol that is not actually in scope fails downstream as unbound).
(define (rule-bound-symbols clauses ctx)
  (let walk ([e clauses] [acc (terms-all-vars clauses)])
    (match e
      [`(syn ,_ lambda ,params ,body)
       #:when (not (declared? ctx 'lambda))
       (walk body (set-union acc (list->set (lambda-params params))))]
      [`(syn ,_ ,(? symbol?) ,args ...) (foldl walk acc args)]
      [`(syn ,_ ,es ...) (foldl walk acc es)]
      [(? list? l) (foldl walk acc l)]
      [_ acc])))

(define (lambda-params params-form)
  (define (param! x)
    (unless (and (symbol? x) (not (eq? x '_)))
      (error 'demand "malformed lambda parameter list: ~a"
             (strip-prov params-form)))
    x)
  (match params-form
    [(? symbol? x) (list (param! x))]
    [`(syn ,_ ,xs ...) (map param! xs)]
    [_ (error 'demand "malformed lambda parameter list: ~a"
              (strip-prov params-form))]))

;; Closure names come from the lambda's source position: deterministic,
;; and unique within a program (root-relative file hash x line x column).
(define (lambda-name prov)
  (match-define `(prov ,ltok ,_) prov)
  (define pos (token->pos ltok))
  (string->symbol (format "_lam~ax~ax~a"
                          (modulo (fnv (source-name-key (pos->file pos))) 100000)
                          (pos->startline pos)
                          (pos->startcol pos))))

(define (var-callable? ctx h bound)
  (and (symbol? h)
       (not (special-head? h))
       (not (declared? ctx h))
       (set-member? bound h)))

;; Rewrite a term bottom-up: inner lambdas lift first (their replacement
;; constructions become ordinary arguments of the enclosing term), then
;; var-called heads dispatch to applyN.
(define (vl-term e ctx bound)
  (match e
    [`(syn ,p lambda ,params-form ,body)
     #:when (not (declared? ctx 'lambda))
     (define params (lambda-params params-form))
     (define body+ (vl-term body ctx bound))
     (lift-lambda! ctx p params body+)]
    [`(syn ,p ,(? symbol? h) ,args ...)
     (define args+ (for/list ([a (in-list args)]) (vl-term a ctx bound)))
     (if (var-callable? ctx h bound)
         `(syn ,p ,(ensure-apply! ctx (length args+)) ,h ,@args+)
         `(syn ,p ,h ,@args+))]
    [`(syn ,p ,es ...)
     `(syn ,p ,@(for/list ([a (in-list es)]) (vl-term a ctx bound)))]
    [_ e]))

(define (lift-lambda! ctx p params body)
  (define name (lambda-name p))
  (define captured
    (sort (set->list (set-subtract (terms-all-vars (list body))
                                   (list->set params)))
          symbol<?))
  (set-box! (ctx-rels ctx)
            (hash-set (unbox (ctx-rels ctx))
                      name
                      (if (null? captured)
                          `(enum ,name)
                          `(struct ,@(make-list (length captured) 'any)))))
  (set-box! (ctx-clo-members ctx) (set-add (unbox (ctx-clo-members ctx)) name))
  (define ap (ensure-apply! ctx (length params)))
  (set-box! (ctx-gen-rules ctx)
            (set-add (unbox (ctx-gen-rules ctx))
                     `(syn ,p rule -->
                           (syn ,p ,ap (syn ,p ,name ,@captured)
                                ,@params ,body))))
  `(syn ,p ,name ,@captured))

;; Clause-level V/L: a whole clause whose head is a bound variable reads
;; judgment-style -- (f x ... r), last argument the answer.
(define (vl-clause cl ctx bound)
  (match cl
    [`(syn ,p ,(? symbol? h) ,args ...)
     #:when (var-callable? ctx h bound)
     (when (null? args)
       (error 'demand
              "a closure call in clause position needs an answer argument: ~a"
              (strip-prov cl)))
     (define args+ (for/list ([a (in-list args)]) (vl-term a ctx bound)))
     `(syn ,p ,(ensure-apply! ctx (sub1 (length args+))) ,h ,@args+)]
    [_ (vl-term cl ctx bound)]))

;; -----------------------------------------------------------------------
;; Phase C: call extraction.  Nested demand-arity occurrences (and
;; (= x (f a ...)) bindings) become fresh variables plus full-arity body
;; occurrences.  Only single-answer judgments may be called.

(define (call-parts ctx e)
  ;; a bare demand-arity form: (values name args na) or #f
  (match e
    [`(syn ,_ ,(? symbol? f) ,args ...)
     (match (ctx-demand ctx f)
       [(cons nd na) #:when (= (length args) nd) (list f args na)]
       [_ #f])]
    [_ #f]))

(define (extract-calls bodys heads ctx rule)
  (define base (fresh-var-base (append bodys heads) "_v"))
  (define counter 0)
  (define extracted '())
  (define (fresh!)
    (begin0 (string->symbol (format "~a~a" base counter))
      (set! counter (add1 counter))))
  (define (extract! p f args na)
    (when (not (= na 1))
      (error 'demand
             (string-append
              "~a has ~a answer columns and cannot be called in value"
              " position; use an explicit (~a in... out...) clause, in\n~a")
             f na f (strip-prov rule)))
    (define v (fresh!))
    (set! extracted (append extracted (list `(syn ,p ,f ,@args ,v))))
    v)
  (define (walk-term e)
    (match e
      [`(syn ,p ,(? symbol? f) ,args ...)
       (define args+ (map walk-term args))
       (match (call-parts ctx `(syn ,p ,f ,@args+))
         [(list f as na) (extract! p f as na)]
         [#f `(syn ,p ,f ,@args+)])]
      [`(syn ,p ,es ...) `(syn ,p ,@(map walk-term es))]
      [_ e]))
  (define (walk-clause cl)
    (match cl
      ;; a negated atom: no demand machinery may operate under ~ -- a
      ;; nested demand-arity call would extract into a positive body
      ;; occurrence, silently weakening the negation (and a negated
      ;; judgment itself is meaningless: absence of a lazily-grown answer
      ;; is not observable).  Reject with the real story rather than let
      ;; extraction mangle the clause into a downstream parse error.
      [`(syn ,p ~ ,args ...)
       (let check ([es args])
         (for ([e (in-list es)])
           (match e
             [`(syn ,_ ,(? symbol? f) ,iargs ...)
              (when (ctx-demand ctx f)
                (error 'demand
                       "demand-moded relation ~a cannot appear under ~~ (negation): absence of a lazily-grown answer is not observable, in\n~a"
                       f (strip-prov rule)))
              (check iargs)]
             [_ (void)])))
       cl]
      ;; (= x (f a ...)) binds the answer, like a primitive computation
      [`(syn ,p = ,(? symbol? x) ,(app (lambda (e) (call-parts ctx e))
                                       (list f args na)))
       #:when (not (eq? x '_))
       (when (not (= na 1))
         (error 'demand
                "~a has ~a answer columns; (= ~a (~a ...)) cannot bind them all, in\n~a"
                f na x f (strip-prov rule)))
       ;; walk the arguments first: inner calls must extract before this
       ;; occurrence appends itself
       (define args+ (map walk-term args))
       (set! extracted (append extracted (list `(syn ,p ,f ,@args+ ,x))))
       #f]
      ;; f_ans keyed by the demand written in place: the key column IS the
      ;; demand struct, so that position is a content join, not a call
      [`(syn ,p ,(? symbol? fa) (syn ,p2 ,(? symbol? f) ,kargs ...) ,rest ...)
       #:when (and (eq? fa (demand-ans-name f))
                   (match (ctx-demand ctx f)
                     [(cons nd _) (= (length kargs) nd)]
                     [_ #f]))
       `(syn ,p ,fa (syn ,p2 ,f ,@(map walk-term kargs))
             ,@(map walk-term rest))]
      ;; whole-clause forms (asks, enumerations, judgment occurrences,
      ;; guards, computations): heads stay, arguments are walked
      [`(syn ,p ,(? symbol? h) ,args ...) `(syn ,p ,h ,@(map walk-term args))]
      [_ cl]))
  (define bodys+ (filter values (map walk-clause bodys)))
  ;; extractions from the HEADS: their fresh answer variable flows only into
  ;; the head (an "output" occurrence).  Such an occurrence must be demanded
  ;; EXACTLY when the rule fires -- gated by every body guard -- not
  ;; over-approximated like a body query, or a demanded relation with a
  ;; side-effecting co-head (interp `construct`: (vstore v v)) fires spuriously
  ;; whenever the guard-independent prefix holds
  ;; (docs/bug-guard-dropped-step-scc.md).  Snapshot the extraction list before
  ;; walking heads; the tail is head-derived, each ending in its answer var.
  (define n-body-extracted (length extracted))
  (define heads+ (filter values (map walk-clause heads)))
  (define head-out-vars
    (for/set ([cl (in-list (drop extracted n-body-extracted))]
              #:when (symbol? (last cl)))
      (last cl)))
  (values (append bodys+ extracted) heads+ head-out-vars))

;; -----------------------------------------------------------------------
;; Per-rule rewriting.

;; Fast path: a rule mentioning no demand-moded name, no lambda form, and
;; no var-called head passes through untouched (byte-identical, so
;; demand-free programs keep their exact rules and cache keys).
(define (rule-needs-transform? clauses ctx bound)
  (let scan ([e clauses])
    (match e
      [`(syn ,_ lambda ,_ ,_) #:when (not (declared? ctx 'lambda)) #t]
      [`(syn ,_ ,(? symbol? h) ,args ...)
       (or (and (ctx-demand ctx h) #t)
           (var-callable? ctx h bound)
           (ormap scan args))]
      [`(syn ,_ ,es ...) (ormap scan es)]
      [(? list? l) (ormap scan l)]
      [_ #f])))

(define (rewrite-rule rule ctx)
  (match-define `(syn ,prov rule ,bodys ... --> ,heads ...) rule)
  (define bound (rule-bound-symbols (append bodys heads) ctx))
  (cond
    [(not (rule-needs-transform? (append bodys heads) ctx bound))
     (list rule)]
    [else
     ;; alternatives split first: each grounds its own variables, and a
     ;; call inside one alternative must not constrain the others
     (append*
      (for/list ([alt (in-list (set->list (split-or-clauses bodys)))]
                 [alt-idx (in-naturals)])
        (rewrite-alternative prov alt heads ctx rule bound alt-idx)))]))

(define (rewrite-alternative prov bodys0 heads0 ctx rule bound alt-idx)
  ;; phases V/L then C on this alternative
  (define bodys1 (for/list ([cl (in-list bodys0)]) (vl-clause cl ctx bound)))
  (define heads1 (for/list ([cl (in-list heads0)]) (vl-clause cl ctx bound)))
  (define-values (bodys heads head-out-vars) (extract-calls bodys1 heads1 ctx rule))

  (define fun-env (type-env-funs (ctx-type-env ctx)))

  ;; classify and validate clauses
  (define head-occs
    (for/list ([cl (in-list heads)]) (list cl (judgment-parts cl ctx))))
  (define body-occs
    (for/list ([cl (in-list bodys)]) (list cl (judgment-parts cl ctx))))
  (for ([occ (in-list (append body-occs head-occs))])
    (match-define (list cl parts) occ)
    (if parts
        (let ()
          (match-define (list _ name dargs aargs) parts)
          (validate-judgment-args! (append dargs aargs) name rule))
        (validate-clause! cl ctx rule)))

  (cond
    [(and (not (ormap second head-occs)) (not (ormap second body-occs)))
     ;; V/L/C may have rewritten the rule without leaving judgment
     ;; occurrences (e.g. only asks or enumerations); emit as-is
     (list `(syn ,prov rule ,@bodys --> ,@heads))]
    [else

     ;; deterministic demand-id variables, one per judgment occurrence
     (define dvar-base (fresh-var-base (append bodys heads) "_d"))
     (define judgment-count
       (+ (count second head-occs) (count second body-occs)))
     (define dvars
       (for/list ([k (in-range judgment-count)])
         (string->symbol (format "~a~a" dvar-base k))))

     (define-values (head-js remaining-dvars)
       (for/fold ([js '()] [ds dvars] #:result (values (reverse js) ds))
                 ([occ (in-list head-occs)] #:when (second occ))
         (values (cons (cons (car ds) (second occ)) js) (cdr ds))))
     (define body-js
       (for/fold ([js '()] [ds remaining-dvars] #:result (reverse js))
                 ([occ (in-list body-occs)] #:when (second occ))
         (match-define (list p name dargs aargs) (second occ))
         (when (ormap term-has-wildcard? dargs)
           (error 'demand
                  (string-append
                   "wildcard in the demand arguments of a body occurrence of ~a:"
                   " a demand cannot be constructed from _, in\n~a")
                  name (strip-prov rule)))
         (values (cons (cons (car ds) (second occ)) js) (cdr ds))))

     ;; gates: (= d (f p...)) joined in the body for each judgment head
     (define (gate-clause dvar parts)
       (match-define (list p name dargs _) parts)
       `(syn ,p = ,dvar (syn ,p ,name ,@dargs)))
     (define gates
       (for/list ([j (in-list head-js)]) (gate-clause (car j) (cdr j))))

     ;; resume pairs: (= d (f q...)) (f_ans d a...) per body judgment
     (define (resume-clauses dvar parts)
       (match-define (list p name dargs aargs) parts)
       (list `(syn ,p = ,dvar (syn ,p ,name ,@dargs))
             `(syn ,p ,(demand-ans-name name) ,dvar ,@aargs)))

     (define main-body
       (append
        gates
        (append*
         (for/list ([occ (in-list body-occs)])
           (match-define (list cl parts) occ)
           (if parts
               (let ([j (findf (lambda (j) (eq? (cdr j) parts)) body-js)])
                 (resume-clauses (car j) (cdr j)))
               (list cl))))))
     (define main-heads
       (let loop ([occs head-occs] [js head-js])
         (match occs
           ['() '()]
           [(cons (list cl #f) rest) (cons cl (loop rest js))]
           [(cons (list _ parts) rest)
            (match-define (cons dvar _) (car js))
            (match-define (list p name _ aargs) parts)
            (cons `(syn ,p ,(demand-ans-name name) ,dvar ,@aargs)
                  (loop rest (cdr js)))])))
     ;; ask rules, scheduled by groundness in parallel stages; stages whose
     ;; answer-return join cannot be keyed also emit a supplementary
     ;; relation, whose atom joins the main rule additively (see
     ;; schedule-asks)
     (define gate-keys
       (for/set ([j (in-list head-js)])
         (match-define (list _ name dargs _) (cdr j))
         (cons name (strip-prov dargs))))
     (define non-judgment-clauses
       (append gates
               (filter-map (lambda (occ) (and (not (second occ)) (car occ)))
                           body-occs)))
     ;; OUTPUT judgments: those whose answer flows only into the head (a call
     ;; extracted out of a head term).  Their ask must be gated by every body
     ;; guard, so schedule-asks defers them until all guards are scheduled
     ;; (docs/bug-guard-dropped-step-scc.md).
     (define output-dvars
       (for/set ([j (in-list body-js)]
                 #:when (let ([aargs (fourth (cdr j))])
                          (and (pair? aargs)
                               (for/and ([a (in-list aargs)])
                                 (and (symbol? a)
                                      (set-member? head-out-vars a))))))
         (car j)))
     (define-values (asks sup-atoms)
       (schedule-asks prov non-judgment-clauses body-js gate-keys fun-env rule
                      ctx alt-idx output-dvars))
     (define main-rule
       `(syn ,prov rule ,@main-body ,@sup-atoms --> ,@main-heads))

     (cons main-rule asks)]))

;; -----------------------------------------------------------------------
;; Ask scheduling.  Returns (values ask+sup-rules sup-atoms).
;;
;; SUPPLEMENTARY RELATIONS (docs/demand.md).  The main rule resumes a body
;; judgment by RECONSTRUCTION: a delta on f_ans binds the demand id, the
;; match clause decomposes it, and the rest of the host body re-derives
;; the caller's context.  Reconstruction is keyed exactly when every step
;; runs backwards through relation columns (atoms, struct patterns, other
;; answer tables); it degrades to an ask-table SCAN when the caller's
;; context is reachable only through a primitive (a slice, arithmetic --
;; functions have no inverse index) or through the fields of the demanded
;; pattern itself.  For each ask stage containing such a judgment we emit
;; the classic supplementary (Beeri-Ramakrishnan):
;;
;;   rule <stage prefix> --> ($sup<pos>x<alt>x<stage> carried ...)
;;
;; -- the same body as the stage's ask rules -- and join the sup atom
;; ADDITIVELY in the main rule.  It is implied by the clauses beside it,
;; so the least model is unchanged (the occurrence-probe lag discipline:
;; the sup lands an iteration later and its delta refires the rule), and
;; every delta-f_ans variant can now probe the sup on demand-argument
;; columns instead of scanning.  `carried` = the stage's ground variables
;; still needed downstream, sorted for determinism; cardinality is one
;; row per caller binding -- tuples the downward pass enumerates anyway.
;; Judgments whose demand args have no variables are exempt (their answer
;; return is semantically a broadcast; a sup adds no key).  Column types
;; are `any` (the applyN precedent): sup columns are join keys, never
;; patterns, so they also stay out of sequence-occurrence feeding.

(define (sup-rel-name prov alt-idx stage-idx)
  (match-define `(prov ,ltok ,_) prov)
  (define pos (token->pos ltok))
  (string->symbol (format "$sup~ax~ax~ax~ax~a"
                          (modulo (fnv (source-name-key (pos->file pos))) 100000)
                          (pos->startline pos)
                          (pos->startcol pos)
                          alt-idx stage-idx)))

(define (seq-item-var it)
  (match it
    [`(,(or 'elem 'splice) ,(? symbol? x)) #:when (not (eq? x '_)) x]
    [_ #f]))

;; Simulate the delta-f_ans return join for body judgment j: saturate the
;; clauses a planner could fire KEYED starting from what the answer row
;; binds (the demand id, its decomposed inputs, the answer columns).  #t
;; iff a relational clause is left unfireable -- the plan would scan.
(define (return-join-scans? j body-js clauses fun-env)
  (match-define (cons dvar (list _ _name dargs aargs)) j)
  (define other-cls
    (append clauses
            (append*
             (for/list ([j2 (in-list body-js)] #:unless (eq? j2 j))
               (match-define (cons dv (list p n da aa)) j2)
               (list `(syn ,p = ,dv (syn ,p ,n ,@da))
                     `(syn ,p ,(demand-ans-name n) ,dv ,@aa))))))
  ;; -> new bindings if cl can fire keyed under B, else #f
  (define (fire cl B)
    (match cl
      [`(syn ,_ = ,(? symbol? x) (syn ,_ const ,_))
       (if (eq? x '_) (set) (set x))]
      [`(syn ,_ = ,(? symbol? x) ,(? symbol? y))
       (and (or (set-member? B x) (set-member? B y))
            (list->set (remq* '(_) (list x y))))]
      [`(syn ,_ = ,(? symbol? x) (syn ,_ ,(? symbol? f) ,args ...))
       (cond
         [(hash-has-key? fun-env f)              ; a prim: forward only
          (and (subset? (terms-all-vars args) B)
               (if (eq? x '_) (set) (set x)))]
         [else                                   ; struct/judgment term
          (define-values (bound needed) (terms-match-vars args fun-env))
          (cond
            [(and (not (eq? x '_)) (set-member? B x)) bound]  ; decompose
            [(subset? (set-union bound needed) B)             ; construct
             (if (eq? x '_) (set) (set x))]
            [else #f])])]
      [`(syn ,_ seq-pat ,(? symbol? l) ,items ...)
       (define ivars (list->set (filter-map seq-item-var items)))
       (cond
         [(set-member? B l) ivars]
         [(subset? ivars B) (set l)]
         [else #f])]
      [`(syn ,_ ,(? (lambda (s) (and (symbol? s)
                                     (or (special-head? s)
                                         (primitive-cmp? s)))))
             ,_ ...)
       (set)]                                    ; checks bind nothing
      ;; a negated atom: fires (as a pure check) once its variables are
      ;; ground; binds nothing
      [`(syn ,_ ~ ,args ...)
       (and (subset? (terms-all-vars args) B) (set))]
      [`(syn ,_ ,(? symbol?) ,args ...)          ; a relational atom
       ;; a COLUMN keys a probe only whole: a constant, a bound top-level
       ;; variable, or a fully-constructible term.  A bound variable
       ;; buried in a partial struct pattern does not (no field-inverse
       ;; index exists; the planner scans and decomposes).
       (define keyed?
         (for/or ([a (in-list args)])
           (match a
             [`(syn ,_ const ,_) #t]
             [(? symbol? x) (set-member? B x)]
             [`(syn ,_ ,_ ...) (subset? (terms-all-vars a) B)]
             [_ #f])))
       (and keyed? (terms-all-vars args))]
      [_ (set)]))
  (define B0
    (set-remove
     (set-add (set-union (terms-all-vars dargs) (terms-all-vars aargs)) dvar)
     '_))
  (define (scan-shaped? cl)
    (match cl
      [`(syn ,_ = ,_ (syn ,_ ,(? symbol? f) ,_ ...))
       (not (hash-has-key? fun-env f))]          ; stuck gate/decomposition
      [`(syn ,_ seq-pat ,_ ...) #t]
      [`(syn ,_ = ,_ ...) #f]                    ; a stuck prim compute
      [`(syn ,_ ,(? (lambda (s) (and (symbol? s)
                                     (or (special-head? s)
                                         (primitive-cmp? s)))))
             ,_ ...) #f]
      [`(syn ,_ ~ ,_ ...) #f]                    ; a stuck check, not a scan
      [`(syn ,_ ,(? symbol?) ,_ ...) #t]         ; stuck atom
      [_ #f]))
  (let loop ([B B0] [cls other-cls])
    (define-values (B+ rest fired?)
      (for/fold ([B2 B] [rest '()] [fired? #f]) ([cl (in-list cls)])
        (match (fire cl B)
          [#f (values B2 (cons cl rest) fired?)]
          [new (values (set-union B2 (set-remove new '_)) rest #t)])))
    (cond
      [fired? (loop B+ (reverse rest))]
      [else (ormap scan-shaped? cls)])))

(define (schedule-asks prov clauses body-js gate-keys fun-env rule
                       ctx alt-idx [output-dvars (set)])
  ;; an OUTPUT judgment's answer flows only into the head; its demand (and
  ;; any side-effecting co-head it triggers) must fire EXACTLY when the rule
  ;; fires, so it is deferred until every guard judgment is scheduled and its
  ;; ask rides a prefix carrying the guards' resumes (bug-guard-dropped-...).
  (define (output-j? j) (set-member? output-dvars (car j)))
  (define pending0
    (for/list ([cl (in-list clauses)])
      (match-define (cons needs grounds) (clause-mode cl fun-env))
      (list cl needs grounds)))
  (let stage ([pending pending0] [included '()] [G (set)]
              [waiting body-js] [asks '()] [sup-atoms '()] [stage-idx 0]
              [prev-sup #f] [since '()])
    (define-values (pending+ included+ G+)
      (let fix ([pending pending] [included included] [G G])
        (define-values (ready blocked)
          (partition (lambda (p) (subset? (second p) G)) pending))
        (if (null? ready)
            (values blocked included G)
            (fix blocked
                 (append included (map first ready))
                 (for/fold ([G G]) ([p (in-list ready)])
                   (set-union G (third p)))))))
    (define-values (ready-js0 blocked-js0)
      (partition (lambda (j)
                   (match-define (list _ _ dargs _) (cdr j))
                   (subset? (terms-all-vars dargs) G+))
                 waiting))
    ;; defer OUTPUT judgments while any guard judgment is still waiting: an
    ;; output must be gated by every guard, so it may only be asked from a
    ;; prefix that already carries all guard resumes.  Deadlock-free: guards
    ;; never depend on an output's answer (it flows only to the head), so a
    ;; held-back output never blocks a guard.
    (define guards-waiting?
      (for/or ([j (in-list waiting)]) (not (output-j? j))))
    (define-values (ready-js blocked-js)
      (if guards-waiting?
          (values (filter (lambda (j) (not (output-j? j))) ready-js0)
                  (append blocked-js0 (filter output-j? ready-js0)))
          (values ready-js0 blocked-js0)))
    ;; the CHAINED prefix: once a supplementary exists, later ask and sup
    ;; rules ride it -- its atom plus the clauses included since --
    ;; instead of re-carrying (and re-scanning, in their answer-delta
    ;; variants) the whole raw prefix
    (define since+ (append since (drop included+ (length included))))
    (define effective-prefix
      (if prev-sup (cons prev-sup since+) included+))
    (cond
      [(null? ready-js)
       (unless (null? blocked-js)
         ;; report a genuinely-ungroundable judgment, preferring a guard over
         ;; a merely-deferred output (whose args are already ground)
         (define culprit
           (or (findf (lambda (j) (not (output-j? j))) blocked-js)
               (first blocked-js)))
         (match-define (list _ name dargs _) (cdr culprit))
         (error 'demand
                (string-append
                 "cannot ground the demand arguments of ~a (unbound: ~a) in\n~a\n"
                 "(to enumerate demands or answers instead, use ~a or ~a directly)")
                name
                (sort (set->list (set-subtract (terms-all-vars dargs) G+))
                      symbol<?)
                (strip-prov rule) name (demand-ans-name name)))
       (values (reverse asks) (reverse sup-atoms))]
      [else
       ;; this stage's supplementary, when some ready judgment's return
       ;; join would scan (variable-free demand args exempt: broadcast)
       (define triggers?
         (for/or ([j (in-list ready-js)])
           (match-define (list _ _ dargs _) (cdr j))
           (and (not (set-empty? (set-remove (terms-all-vars dargs) '_)))
                (return-join-scans? j body-js clauses fun-env))))
       (define-values (sup-rules sup-atom)
         (cond
           [(not triggers?) (values '() #f)]
           [else
            (define sname (sup-rel-name prov alt-idx stage-idx))
            ;; carry the whole ground set: the return variant must re-key
            ;; not only the downstream clauses but the prefix's own atoms
            ;; (a prim-computed key cannot re-derive its inputs backwards).
            ;; STRICT groundness only: the scheduler's seq-pat
            ;; over-approximation ("pattern vars ground together") must not
            ;; leak into carried columns -- a dangling pattern's vars are
            ;; not values (seq-expand DROPS the copy; carrying them would
            ;; make it live and force its D12 error).  Everything else
            ;; grounds as scheduled (atoms and struct patterns enumerate;
            ;; lists are values, not a finite store).
            (define strict
              (let loop ([G (set)])
                (define G2
                  (for/fold ([G G]) ([cl (in-list included+)])
                    (match cl
                      [`(syn ,_ seq-pat ,(? symbol? l) ,items ...)
                       (define ivars
                         (list->set (filter-map seq-item-var items)))
                       (define constructible?
                         (andmap (lambda (it)
                                   (match it
                                     [`(elemc ,_) #t]
                                     [`(,(or 'elem 'splice) ,(? symbol? x))
                                      (not (eq? x '_))]
                                     [_ #f]))
                                 items))
                       (cond
                         [(set-member? G l) (set-union G ivars)]
                         [(and constructible? (subset? ivars G))
                          (set-add G l)]
                         [else G])]
                      [_ (match-define (cons needs grounds)
                           (clause-mode cl fun-env))
                         (if (subset? needs G) (set-union G grounds) G)])))
                (if (equal? G2 G) G (loop G2))))
            (define carried
              (sort (set->list (set-remove (set-intersect G+ strict) '_))
                    symbol<?))
            (cond
              [(null? carried) (values '() #f)]
              [else
               (set-box! (ctx-rels ctx)
                         (hash-set (unbox (ctx-rels ctx))
                                   sname
                                   `(table ,@(make-list (length carried) 'any))))
               (values (list `(syn ,prov rule ,@effective-prefix
                                   --> (syn ,prov ,sname ,@carried)))
                       `(syn ,prov ,sname ,@carried))])]))
       ;; after a sup, the chain keeps only clauses NOT subsumed by the
       ;; carried columns: a clause whose variables all ride in the sup is
       ;; re-established by the probe, but one still holding unresolved
       ;; variables (a pattern awaiting a later answer -- the scheduler's
       ;; over-approximation admits these early) must stay to bind them
       (define chained-since
         (cond
           [(not sup-atom) since+]
           [else
            (define carried-set
              (list->set (match sup-atom [`(syn ,_ ,_ ,vs ...) vs])))
            (filter (lambda (cl)
                      (not (subset? (terms-all-vars cl) carried-set)))
                    since+)]))
       ;; ask rules ride this stage's supplementary when it exists (their
       ;; bodies otherwise duplicate the prefix -- and its answer-delta
       ;; scan variants -- once per judgment)
       (define ask-body (if sup-atom (list sup-atom) effective-prefix))
       (define new-asks
         (for/list ([j (in-list ready-js)]
                    #:unless (set-member?
                              gate-keys
                              (match-let ([(list _ name dargs _) (cdr j)])
                                (cons name (strip-prov dargs)))))
           (match-define (list p name dargs _) (cdr j))
           `(syn ,prov rule ,@ask-body --> (syn ,p ,name ,@dargs))))
       (define resume-pairs
         (append*
          (for/list ([j (in-list ready-js)])
            (match-define (cons dvar (list p name dargs aargs)) j)
            (list `(syn ,p = ,dvar (syn ,p ,name ,@dargs))
                  `(syn ,p ,(demand-ans-name name) ,dvar ,@aargs)))))
       (define included++ (append included+ resume-pairs))
       (define G++
         (for/fold ([G G+]) ([j (in-list ready-js)])
           (match-define (cons dvar (list _ _n _da aargs)) j)
           (define-values (bound _needed) (terms-match-vars aargs fun-env))
           (set-union G (set-add bound dvar))))
       (stage pending+ included++ G++ blocked-js
              (append (reverse new-asks) sup-rules asks)
              (if sup-atom (cons sup-atom sup-atoms) sup-atoms)
              (add1 stage-idx)
              (or sup-atom prev-sup)
              (append chained-since resume-pairs))])))

;; -----------------------------------------------------------------------
;; Unit tests: the transform is pure syntax -> syntax; shapes are checked
;; with provenance stripped.

(module+ test
  (require rackunit)

  (define P '(prov (token id (pos "t.slog" 1 1 1 2) "t")
                   (token id (pos "t.slog" 1 1 1 2) "t")))
  (define (P@ line col)
    `(prov (token id (pos "t.slog" ,line ,col ,line ,(add1 col)) "t")
           (token id (pos "t.slog" ,line ,col ,line ,(add1 col)) "t")))
  (define (S . parts) `(syn ,P ,@parts))
  (define (rule* bodys heads) `(syn ,P rule ,@bodys --> ,@heads))
  (define (run rules demands)
    (strip-prov
     (desugar-demand-rules (list->set rules) demands empty-type-env)))
  (define (run1 r demands) (run (list r) demands))
  (define demands1 (hash 'f (cons 1 1)))

  ;; a rule without judgment occurrences passes through untouched
  (check-equal?
   (run1 (rule* (list (S 'edge 'x 'y)) (list (S 'path 'x 'y))) demands1)
   (set '(rule (edge x y) --> (path x y))))

  ;; bare-arity occurrences (asks/enumeration) pass through untouched
  (check-equal?
   (run1 (rule* (list (S 'f 'x)) (list (S 'seen 'x))) demands1)
   (set '(rule (f x) --> (seen x))))

  ;; head occurrence: gate in the body, answer emission in the head
  (check-equal?
   (run1 (rule* (list (S '= 'y (S '+ 'x (S 'const 1)))) (list (S 'f 'x 'y)))
         demands1)
   (set '(rule (= _d0 (f x)) (= y (+ x (const 1))) --> (f_ans _d0 y))))

  ;; body occurrence: one ask rule plus the resumed main rule
  (check-equal?
   (run1 (rule* (list (S 'start 'x) (S 'f 'x 'y)) (list (S 'out 'x 'y)))
         demands1)
   (set '(rule (start x) --> (f x))
        '(rule (start x) (= _d0 (f x)) (f_ans _d0 y) --> (out x y))))

  ;; recursion: the self-ask identical to the gate is elided; the
  ;; dependent ask waits for the first answer (its prefix carries the
  ;; resume pair; static unification later collapses _d1 into _d0)
  (check-equal?
   (run1 (rule* (list (S 'f 'x 'y) (S 'f 'y 'z)) (list (S 'f 'x 'z)))
         demands1)
   (set '(rule (= _d0 (f x)) (= _d1 (f x)) (f_ans _d1 y) --> (f y))
        '(rule (= _d0 (f x))
               (= _d1 (f x)) (f_ans _d1 y)
               (= _d2 (f y)) (f_ans _d2 z)
               -->
               (f_ans _d0 z))))

  ;; parallel asks: two judgments ready in the same stage share a prefix
  (let ([out (run1 (rule* (list (S 'n 'x) (S 'f 'x 'a) (S 'f 'x 'b))
                          (list (S 'both 'a 'b)))
                   demands1)])
    (check-true (set-member? out '(rule (n x) --> (f x))))
    (check-equal? (set-count out) 2))

  ;; guards ground nothing but gate the ask when their inputs are ready
  (check-equal?
   (run1 (rule* (list (S 'n 'x) (S '< 'x (S 'const 9)) (S 'f 'x 'y))
                (list (S 'out 'y)))
         demands1)
   (set '(rule (n x) (< x (const 9)) --> (f x))
        '(rule (n x) (< x (const 9)) (= _d0 (f x)) (f_ans _d0 y) --> (out y))))

  ;; a computation feeding a demand argument schedules before the ask --
  ;; and, being prim-computed, the key cannot be reconstructed from a
  ;; returning answer: the stage emits its supplementary, joined
  ;; additively in the main rule (the recursion case above pins the
  ;; converse: answer-column-chained keys emit NO supplementary)
  (check-equal?
   (run1 (rule* (list (S 'n 'x) (S '= 'x1 (S '+ 'x (S 'const 1))) (S 'f 'x1 'y))
                (list (S 'out 'y)))
         demands1)
   (set '(rule ($sup94702x1x1x0x0 x x1) --> (f x1))
        '(rule (n x) (= x1 (+ x (const 1))) --> ($sup94702x1x1x0x0 x x1))
        '(rule (n x) (= x1 (+ x (const 1)))
               (= _d0 (f x1)) (f_ans _d0 y) ($sup94702x1x1x0x0 x x1)
               --> (out y))))

  ;; chained prim-computed keys: each stage carries its own supplementary
  ;; (stage 1's prefix includes stage 0's resume pair)
  (let ([out (run1 (rule* (list (S 'n 'x)
                                (S '= 'x1 (S '+ 'x (S 'const 1)))
                                (S 'f 'x1 'y)
                                (S '= 'y1 (S '+ 'y (S 'const 1)))
                                (S 'f 'y1 'z))
                          (list (S 'out 'z)))
                   demands1)])
    (define sups
      (for/set ([r (in-set out)]
                #:when (match r
                         [`(rule ,_ ... --> (,(? symbol? h) ,_ ...))
                          (string-prefix? (symbol->string h) "$sup")]
                         [_ #f]))
        r))
    (check-equal? (set-count sups) 2))

  ;; multi-answer judgments
  (check-equal?
   (run1 (rule* (list (S 'n 'x) (S 'g 'x 'a 'b)) (list (S 'out 'a 'b)))
         (hash 'g (cons 1 2)))
   (set '(rule (n x) --> (g x))
        '(rule (n x) (= _d0 (g x)) (g_ans _d0 a b) --> (out a b))))

  ;; all-constant demand arguments ask from a fact rule (the seed pattern)
  (check-equal?
   (run1 (rule* (list (S 'f (S 'const 0) 'y)) (list (S 'out 'y))) demands1)
   (set '(rule --> (f (const 0)))
        '(rule (= _d0 (f (const 0))) (f_ans _d0 y) --> (out y))))

  ;; deterministic name collision avoidance
  (check-equal?
   (run1 (rule* (list (S 'start '_d0) (S 'f '_d0 'y)) (list (S 'out 'y)))
         demands1)
   (set '(rule (start _d0) --> (f _d0))
        '(rule (start _d0) (= _dd0 (f _d0)) (f_ans _dd0 y) --> (out y))))

  ;; joint gating: a judgment head and a plain head share the gated body
  (check-equal?
   (run1 (rule* (list (S '= 'y (S '* 'x 'x))) (list (S 'f 'x 'y) (S 'seen 'x)))
         demands1)
   (set '(rule (= _d0 (f x)) (= y (* x x)) --> (f_ans _d0 y) (seen x))))

  ;; | alternatives split before scheduling
  (check-equal?
   (run1 (rule* (list (S (string->symbol "|") (S 'a 'x) (S 'b 'x))
                      (S 'f 'x 'y))
                (list (S 'out 'y)))
         demands1)
   (set '(rule (a x) --> (f x))
        '(rule (b x) --> (f x))
        '(rule (a x) (= _d0 (f x)) (f_ans _d0 y) --> (out y))
        '(rule (b x) (= _d0 (f x)) (f_ans _d0 y) --> (out y))))

  ;; ---- value-position calls (phase C) ----

  ;; nested call in an ordinary head argument
  (check-equal?
   (run1 (rule* (list (S 'n 'x)) (list (S 'out 'x (S 'f 'x)))) demands1)
   (set '(rule (n x) --> (f x))
        '(rule (n x) (= _d0 (f x)) (f_ans _d0 _v0) --> (out x _v0))))

  ;; (= r (f x)) binds the answer, like a primitive computation
  (check-equal?
   (run1 (rule* (list (S 'n 'x) (S '= 'r (S 'f 'x))) (list (S 'out 'r)))
         demands1)
   (set '(rule (n x) --> (f x))
        '(rule (n x) (= _d0 (f x)) (f_ans _d0 r) --> (out r))))

  ;; call in a guard argument (the resume pair replaces the extracted
  ;; occurrence at the end of the body; the guard keeps its place)
  (check-equal?
   (run1 (rule* (list (S 'n 'x) (S '< (S 'f 'x) (S 'const 9)))
                (list (S 'small 'x)))
         demands1)
   (set '(rule (n x) --> (f x))
        '(rule (n x) (< _v0 (const 9)) (= _d0 (f x)) (f_ans _d0 _v0)
               --> (small x))))

  ;; nested call inside another call's demand argument (chained asks)
  (check-equal?
   (run1 (rule* (list (S 'n 'x) (S '= 'r (S 'f (S 'f 'x)))) (list (S 'out 'r)))
         demands1)
   (set '(rule (n x) --> (f x))
        '(rule (n x) (= _d0 (f x)) (f_ans _d0 _v0) --> (f _v0))
        '(rule (n x)
               (= _d0 (f x)) (f_ans _d0 _v0)
               (= _d1 (f _v0)) (f_ans _d1 r)
               --> (out r))))

  ;; a call in a judgment head's answer position: one-rule recursion
  (check-equal?
   (run1 (rule* (list (S 'pos 'x)) (list (S 'f 'x (S 'f 'x)))) demands1)
   ;; the self-call's ask is elided against the gate
   (set '(rule (= _d0 (f x)) (pos x)
               (= _d1 (f x)) (f_ans _d1 _v0)
               --> (f_ans _d0 _v0))))

  ;; f_ans keyed by the demand in place is a content join, not a call
  (check-equal?
   (run1 (rule* (list (S 'f_ans (S 'f 'x) 'r)) (list (S 'out 'x 'r)))
         demands1)
   (set '(rule (f_ans (f x) r) --> (out x r))))

  ;; multi-answer judgments cannot be called
  (check-exn
   (lambda (e) (regexp-match? #rx"cannot be called in value position"
                              (exn-message e)))
   (lambda () (run1 (rule* (list (S 'n 'x)) (list (S 'out (S 'g 'x))))
                    (hash 'g (cons 1 2)))))

  ;; ---- var calls and lambdas (phases V and L) ----

  (define (run-prog rules demands)
    (define-values (mods+ rels clo)
      (desugar-demand-program (list (list "m" '() (list->set rules)))
                              demands
                              empty-type-env))
    (values (strip-prov (third (first mods+))) rels clo))

  ;; clause-position var call: judgment reading, last argument the answer
  (let-values ([(out rels clo)
                (run-prog (list (rule* (list (S 'reg 'g) (S 'g (S 'const 3) 'r))
                                       (list (S 'out 'r))))
                          (hash))])
    (check-true (set-member? out '(rule (reg g) --> (apply1 g (const 3)))))
    (check-true
     (set-member? out
                  '(rule (reg g)
                         (= _d0 (apply1 g (const 3))) (apply1_ans _d0 r)
                         --> (out r))))
    (check-equal? (hash-ref rels 'apply1) '(struct clo any))
    (check-equal? (hash-ref rels 'apply1_ans) '(table apply1 any)))

  ;; nested var call denotes the answer
  (let-values ([(out rels clo)
                (run-prog (list (rule* (list (S 'reg 'g))
                                       (list (S 'out (S 'g (S 'const 3))))))
                          (hash))])
    (check-true (set-member? out '(rule (reg g) --> (apply1 g (const 3))))))

  ;; lambda: closure struct, clo member, generated apply rule
  (let-values ([(out rels clo)
                (run-prog
                 (list (rule* (list (S 'kv 'k))
                              (list (S 'mk `(syn ,(P@ 7 4) lambda
                                                 (syn ,(P@ 7 12) n)
                                                 (syn ,(P@ 7 15) + n k))))))
                 (hash))])
    (define lam (lambda-name (P@ 7 4)))
    (check-equal? (hash-ref rels lam) '(struct any))     ; captures k
    (check-true (set-member? clo lam))
    (check-true (set-member? out `(rule (kv k) --> (mk (,lam k)))))
    ;; the generated apply rule is itself demand-transformed (gated)
    (check-true
     (set-member? out
                  `(rule (= _d0 (apply1 (,lam k) n))
                         --> (apply1_ans _d0 (+ n k))))))

  ;; zero-capture lambda becomes an enum constant
  (let-values ([(out rels clo)
                (run-prog
                 (list (rule* (list (S 'go 'x))
                              (list (S 'mk `(syn ,(P@ 9 2) lambda
                                                 (syn ,(P@ 9 10) n)
                                                 n)))))
                 (hash))])
    (define lam (lambda-name (P@ 9 2)))
    (check-equal? (hash-ref rels lam) `(enum ,lam)))

  ;; ---- errors ----

  (define (check-demand-error rx thunk)
    (check-exn (lambda (e) (and (exn:fail? e) (regexp-match? rx (exn-message e))))
               thunk))
  ;; wrong arity (neither the demand arity 1 nor the full arity 3)
  (check-demand-error
   #rx"cannot be used with 2 arguments"
   (lambda () (run1 (rule* (list (S 'n 'x) (S 'f 'x 'y)) (list (S 'out 'x)))
                    (hash 'f (cons 1 2)))))
  ;; full-arity value position
  (check-demand-error
   #rx"value-position"
   (lambda () (run1 (rule* (list (S 'foo (S 'f 'x 'y))) (list (S 'out 'x)))
                    demands1)))
  ;; id-bound judgment
  (check-demand-error
   #rx"cannot be bound to an id"
   (lambda () (run1 (rule* (list (S '= 'v (S 'f 'x 'y))) (list (S 'out 'v)))
                    demands1)))
  ;; unmoded use: demand argument never grounds
  (check-demand-error
   #rx"cannot ground the demand arguments"
   (lambda () (run1 (rule* (list (S 'f 'x 'y)) (list (S 'out 'y))) demands1)))
  ;; wildcard in a body occurrence's demand argument
  (check-demand-error
   #rx"wildcard in the demand arguments"
   (lambda () (run1 (rule* (list (S 'n 'x) (S 'f '_ 'y)) (list (S 'out 'y)))
                    demands1)))
  ;; connectives inside judgment occurrences
  (check-demand-error
   #rx"not allowed inside the judgment occurrence"
   (lambda () (run1 (rule* (list (S 'n 'x))
                           (list (S 'f (S '& (S 'a 'x) (S 'b 'x)) 'y)))
                    demands1)))
  ;; nullary closure call in clause position
  (check-demand-error
   #rx"needs an answer argument"
   (lambda ()
     (let-values ([(out rels clo)
                   (run-prog (list (rule* (list (S 'reg 'g) (S 'g))
                                          (list (S 'out 'g))))
                             (hash))])
       out))))
