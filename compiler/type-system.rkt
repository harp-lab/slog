#lang racket

;; Type checking and normalization.
;;
;; Checks each flat rule against the program's type environment (arities,
;; field types modulo union aliasing, table-vs-struct usage) and normalizes
;; clause forms for the middle end:
;;
;;   - primitive calls (= x (f args ...)) become (let x (f args ...));
;;   - bare struct patterns gain their id binding (= fresh (name ...));
;;   - enum references -- declared members like (red), and symbol literals
;;     like true/false -- become *body* joins against the _enum struct plus
;;     a string constant: (= x (_enum cx)) (= cx (const "red")).  Enum
;;     constants are thereby ordinary interned structs; a per-program fact
;;     rule interning each used constant is synthesized here, so readers
;;     (stratified after the _enum writers) always find the row.
;;
;; Residual dynamic type checks: type-match? deliberately passes two cases
;; it cannot prove -- an `any`-typed variable flowing into a concretely
;; typed column, and a union-typed variable whose member set merely
;; OVERLAPS the column's (e.g. an expr-typed variable into a val column
;; when val = lambda but expr = lambda|app|ref).  Each such head column
;; gets a (tycheck y (accept t ...) rid rel col) head clause: a surface-
;; level tag test compiled just before the rule's emissions.  On failure
;; the deduction is abandoned and a (malformed_deduction rid rel col y)
;; struct is emitted instead (the codegen's divert path); a synthesized
;; per-stratum rule (error-wrap-rule, injected by compile.rkt) wraps each
;; such struct as an (error e) fact within the same fixpoint.  The checks
;; are invisible to stratification (stratify.rkt ignores tycheck clauses):
;; making malformed_deduction a real head of every checked rule would
;; merge all their heads into one SCC (rule heads close together), i.e.
;; collapse the program into a single stratum.
;;
;; Type errors raise; the result is a set of typed rules (ir-stack.rkt)
;; including the synthetic enum fact rules.

(provide typecheck-rules
         error-wrap-rule
         error-wrap-rule-for-arm
         prim-error-arms
         rule-has-tychecks?
         rule-has-fallible-prims?)

(require "parser.rkt")
(require "lexer.rkt")
(require "utils.rkt")
(require "ir-shared.rkt")
(require "primitives.rkt")   ; prim-fun-env (which heads are value prims)

;; -----------------------------------------------------------------------
;; Pass driver: check every rule, then intern every enum constant the
;; program mentions via one synthetic fact rule each.

(define (typecheck-rules type-env rules)
  (define-values (checked enum-consts)
    (for/fold ([acc (set)] [consts (set)])
              ([rule (in-set rules)])
      (define-values (rule+ consts+) ((typecheck-rule type-env) rule))
      (values (set-add acc rule+) (set-union consts consts+))))
  (define synth-prov `(prov ,synth-token ,synth-token))
  (for/fold ([acc checked]) ([s (in-set enum-consts)])
    (define cx (gensymb '_tconst))
    (set-add acc
             `(syn ,synth-prov rule
                   -->
                   (syn ,synth-prov = ,(gensymb '_) (syn ,synth-prov _enum ,cx))
                   (syn ,synth-prov = ,cx (syn ,synth-prov const ,s))))))

;; -----------------------------------------------------------------------
;; Per-rule checking.  Returns (values rule+ enum-constant-strings).

(define ((typecheck-rule type-env) rule)
  (define alias-env (type-env-aliases type-env))
  (define rel-env (type-env-rels type-env))
  (define fun-env (type-env-funs type-env))
  (match rule
    [`(syn ,prov rule ,bodys ... --> ,heads ...)

     ;; ---- first pass: immediate variable types --------------------------
     ;; `head?` marks a HEAD clause: a variable emitted into a relation column
     ;; or struct field there is a SINK, not a source of its own type -- seeding
     ;; from the sink column would hide a needed residual check (an any/union
     ;; value silently entering a concrete column).  So for heads we still record
     ;; genuine sources (a constructed id's name, a prim-computed var) but NOT the
     ;; column/field type of an emitted variable.
     (define (add-to-local head? cl env)
       (match cl
         [`(syn ,_ /= ,x ,y) env]
         [`(syn ,_ ,(? primitive-cmp?) ,x ,y) env]
         [`(syn ,_ = ,x (syn ,_ const ,(? string?))) (hash-set env x 'str)]
         [`(syn ,_ = ,x (syn ,_ const ,(? exact-integer?))) (hash-set env x 'int)]
         [`(syn ,_ = ,x (syn ,_ const ,(? inexact-real?))) (hash-set env x 'float)]
         ;; symbol literals (true/false) are enum members named after themselves
         [`(syn ,_ = ,x (syn ,_ const ,(? symbol? s))) (hash-set env x s)]
         [`(syn ,_ = ,x (syn ,_ ,name ,args ...))
          #:when (hash-has-key? fun-env name)
          (match-define `(fun ,argts ... -> ,rett) (hash-ref fun-env name))
          (define env+
            (foldl (lambda (y t env)
                     (cond
                       [(set-member? (set 'A 'B 'C) t)
                        ;; Link the other args (and, for the result type var,
                        ;; the target x) into this arg's equivalence class.
                        ;; Alias entries ACCUMULATE symmetrically -- (= v) maps
                        ;; to the list of every var v was ever linked to, in
                        ;; both directions -- so resolution is a graph search
                        ;; that finds a grounded class member regardless of
                        ;; clause processing order.  (A single-valued hash was
                        ;; order-dependent: a prim over two computed vars
                        ;; processed before their grounding lets -- e.g. a
                        ;; head-side nested call, heads fold first -- formed a
                        ;; two-cycle that shadowed the groundings.)
                        (let ([link (lambda (env a b)
                                      (if (equal? a b)
                                          env
                                          (hash-update
                                           (hash-update env `(= ,a)
                                                        (lambda (l) (cons b l)) '())
                                           `(= ,b)
                                           (lambda (l) (cons a l)) '())))])
                          (foldl (lambda (arg env) (link env arg y))
                                 (if (eq? t rett)
                                     (link env x y)
                                     env)
                                 args))]
                       ;; an `any` argument imposes no constraint -- recording
                       ;; it would clobber (and conflict with) the type the
                       ;; variable gets from its relation column
                       [(eq? t 'any) env]
                       [else (hash-set env y t)]))
                   env
                   args
                   argts))
          (if (set-member? (set 'A 'B 'C) rett)
              env+
              (hash-set env+ x rett))]
         [`(syn ,_ = ,x (syn ,_ ,name)) (hash-set env x name)]
         [`(syn ,_ = ,x (syn ,_ ,name ,(? symbol? args) ...))
          (match (hash-ref rel-env name list)
            [`(struct ,ts ...)
             #:when (= (length args) (length ts))
             ;; resolve transparent column types (lattice base, (listof T)
             ;; -> list) exactly as the relation-atom case below does.  In a HEAD
             ;; construction the fields are sinks (skip seeding); the constructed
             ;; id `x` is a genuine source (its type is the struct name), always.
             (hash-set (if head?
                           env
                           (foldl (lambda (x t env)
                                    (hash-set env x (lattice-base-type rel-env t)))
                                  env args ts))
                       x
                       name)]
            [`(struct ,ts ...)
             (error (format "Struct ~a takes ~a fields but is used with ~a in ~a"
                            name (length ts) (length args) (strip-prov cl)))]
            [_ (error (format "Struct ~a in ~a is not defined." name (strip-prov cl)))])]
         [`(syn ,_ ,name ,(? symbol? args) ...)
          (match (hash-ref rel-env name list)
            [`(,(or 'table 'struct) ,ts ...)
             #:when (= (length args) (length ts))
             ;; lattice-typed columns are transparent to the type system:
             ;; the variable carries the base type (implicit injection in,
             ;; unwrap out); lattice-check.rkt owns the use discipline.
             ;; In a HEAD atom the columns are sinks -- do NOT source a type from
             ;; them, so an any/union value emitted here gets its residual check.
             (if head?
                 env
                 (foldl (lambda (x t env) (hash-set env x (lattice-base-type rel-env t)))
                        env args ts))]
            [`(enum ,_) env]
            [`(,(or 'table 'struct) ,ts ...)
             (error (format "~a takes ~a columns but is used with ~a in ~a"
                            name (length ts) (length args) (strip-prov cl)))]
            [_
             (error (format "Table ~a in ~a is not defined." name (strip-prov cl)))])]))

     ;; Seed body clauses first (full type sources), THEN head clauses with the
     ;; sink rule above -- so a variable computed in the body and emitted into a
     ;; concrete head column resolves to its computed type, not the sink column's.
     (define local-env-proto
       (foldl (lambda (cl env) (add-to-local #t cl env))
              (foldl (lambda (cl env) (add-to-local #f cl env)) (hash) bodys)
              heads))
     ;; Resolve a variable to a ground type by breadth-first search over
     ;; its (symmetric) polymorphic-link class: the first class member
     ;; with a direct type wins.  A class with no grounded member at all
     ;; is a genuinely circular computed definition.
     (define (resolve-local-type sym)
       (let loop ([frontier (list sym)] [seen (set)])
         (match frontier
           ['()
            (error (format "Cannot infer a type for ~a (circular computed definitions with no ground use)" sym))]
           [(cons s rest)
            (cond
              [(set-member? seen s) (loop rest seen)]
              [(hash-has-key? local-env-proto s) (hash-ref local-env-proto s)]
              [else
               (loop (append rest (hash-ref local-env-proto `(= ,s) '()))
                     (set-add seen s))])])))
     ;; ---- second pass: connect variables via polymorphic instantiations
     (define local-env
       (foldl (lambda (k env)
                (match k
                  [`(= ,x)
                   ;; unify x's own direct type (if any) with the resolved
                   ;; type of every var it was polymorphically linked to.
                   ;; `any` is the universal escape hatch (as in
                   ;; type-match?): a polymorphic link between any and a
                   ;; concrete type resolves to the concrete side -- e.g.
                   ;; (+ n 1) where n comes from an any-typed column (the
                   ;; demand transform's applyN judgments).
                   (define t*
                     (for/fold ([acc (hash-ref local-env-proto x (lambda () #f))])
                               ([y (in-list (hash-ref local-env-proto k))])
                       (define yt (resolve-local-type y))
                       (cond
                         [(not acc) yt]
                         [(equal? acc yt) acc]
                         [(eq? acc 'any) yt]
                         [(eq? yt 'any) acc]
                         [else
                          (error (format "Arguments ~a : ~a and ~a : ~a do not match" x acc y yt))])))
                   (hash-set env x t*)]
                  [(? symbol? x) (hash-set env x (hash-ref local-env-proto x))]))
              (hash)
              (hash-keys local-env-proto)))

     (define (type-match? t0 x)
       (define t (lattice-base-type rel-env t0))
       (define t* (hash-ref alias-env t (lambda () (set t))))
       (define t+
         (hash-ref alias-env (hash-ref local-env x) (lambda () (set (hash-ref local-env x)))))
       ;; `any` is the escape hatch in either direction: a column declared
       ;; any accepts every value, and a variable whose inferred type is any
       ;; (e.g. an argument of (size x), typed (fun any -> int)) satisfies
       ;; every column.
       (let ([checks (or (set-member? t* 'any)
                         (set-member? t+ 'any)
                         (not (set-empty? (set-intersect t* t+))))])
         (if (or checks (set-member? (set 'A 'B 'C) t))
             checks
             (error (format "~a : ~a does not match type '~a' in\n~a"
                            x
                            t
                            (hash-ref local-env x void)
                            (strip-prov rule))))))

     ;; ---- residual dynamic type checks -----------------------------------
     ;; The ground member types of a column/variable type: alias-expand and
     ;; keep only what a runtime tag test can name -- primitives, structs,
     ;; and enum members (union names are covered by their members; lattice
     ;; and listof names resolve through lattice-base-type first).
     (define (ground-member-types t)
       (define ts (hash-ref alias-env t (lambda () (set t))))
       (for/set ([m (in-set ts)]
                 #:when (or (memq m '(int float str any cset cmap))
                            (match (hash-ref rel-env m #f)
                              [`(struct ,_ ...) #t]
                              [`(enum ,_) #t]
                              [_ #f])))
         m))

     ;; #f when the emission of y into a t0-typed column is statically safe
     ;; (or inexpressible as a surface tag test); otherwise the sorted list
     ;; of ground types the column accepts, to residualize as a tycheck.
     (define (residual-accepts t0 y)
       (define col-set (ground-member-types (lattice-base-type rel-env t0)))
       (define var-set (ground-member-types
                        (lattice-base-type rel-env (hash-ref local-env y))))
       (if (or (set-member? col-set 'any)
               (set-empty? col-set)
               (and (not (set-member? var-set 'any))
                    (subset? var-set col-set)))
           #f
           (sort (set->list col-set) symbol<?)))

     ;; Per head emission clause: (relname col-index var accepts) for each
     ;; column whose static pass was only by any/overlap.  Constructed ids
     ;; never need one (their type is the exact struct name), so checks
     ;; only ever guard body-bound (or computed) variables.
     (define (head-residual-checks cl)
       (define (checks-for name ts args)
         (for/fold ([cs '()] #:result (reverse cs))
                   ([t (in-list ts)] [y (in-list args)] [i (in-naturals)])
           (define accepts (residual-accepts t y))
           (if accepts (cons (list name i y accepts) cs) cs)))
       (match cl
         [`(syn ,_ = ,x (syn ,_ ,name ,(? symbol? args) ...))
          #:when (not (hash-has-key? fun-env name))
          (match (hash-ref rel-env name #f)
            [`(struct ,ts ...)
             #:when (= (length ts) (length args))
             (checks-for name ts args)]
            [_ '()])]
         [`(syn ,_ ,name ,(? symbol? args) ...)
          (match (hash-ref rel-env name #f)
            [`(,(or 'table 'struct) ,ts ...)
             #:when (= (length ts) (length args))
             (checks-for name ts args)]
            [_ '()])]
         [_ '()]))

     ;; ---- clause checking + normalization -------------------------------
     (define (check-clause cl)
       (define (check-rel! x name args decl)
         (match decl
           [`(enum ,_)
            (when (not (null? args))
              (error (format "Enumeration ~a cannot be parameterized" name)))]
           [`(struct ,ts ...)
            (when (not (= (length ts) (length args)))
              (error (format "Struct ~a used with wrong arity: ~a" name (cddr cl))))
            (map type-match? ts args)]
           [`(fun ,argts ... -> ,rett) (map type-match? argts args)]
           [`(table ,ts ...)
            (if x
                (error (format "~a is a table, it cannot be used as a struct" name))
                (if (= (length ts) (length args))
                    (map type-match? ts args)
                    (error (format "~a is being used with the wrong arity" name))))]))
       (match cl
         [`(syn ,_ /= ,(? symbol? x) ,(? symbol? y)) cl]
         [`(syn ,_ ,(? primitive-cmp?) ,(? symbol? x) ,(? symbol? y)) cl]
         [`(syn ,_ = ,(? symbol? x) (syn ,_ const ,v)) cl]
         [`(syn ,pr0 = ,(? symbol? x) (syn ,pr1 ,name ,(? symbol? args) ...))
          #:when (hash-has-key? fun-env name)
          (check-rel! x name args (hash-ref fun-env name))
          ;; primitive calls become lets, scheduled by the planner
          `(syn ,pr0 let ,x (syn ,pr1 ,name ,@args))]
         [`(syn ,_ = ,(? symbol? x) (syn ,_ ,name ,(? symbol? args) ...))
          (check-rel!
           x
           name
           args
           (hash-ref rel-env name (lambda () (error (format "Type ~a was never declared" name)))))
          cl]
         [`(syn ,prov ,name ,(? symbol? args) ...)
          (check-rel!
           #f
           name
           args
           (hash-ref rel-env name (lambda () (error (format "Type ~a was never declared" name)))))
          (if (eq? 'struct (first (hash-ref rel-env name (lambda () '(rel)))))
              `(syn ,prov = ,(gensymb '_) ,cl)
              cl)]
         [_ (error (format "Unrecognized clause ~a" cl))]))

     ;; An enum reference: (= x (red)) with red a declared enum member, or a
     ;; symbol literal (= x (const true)).  Returns the member name or #f.
     (define (enum-ref cl)
       (match cl
         [`(syn ,_ = ,_ (syn ,_ const ,(? symbol? s))) s]
         [`(syn ,_ = ,_ (syn ,_ ,name))
          #:when (and (not (hash-has-key? fun-env name))
                      (match (hash-ref rel-env name #f)
                        [`(enum ,_) #t]
                        [_ #f]))
          name]
         [`(syn ,_ ,name)
          #:when (match (hash-ref rel-env name #f)
                   [`(enum ,_) #t]
                   [_ #f])
          name]
         [_ #f]))

     ;; Rewrite enum references into body joins against _enum, collecting
     ;; the constant strings used (the produced clauses always join in the
     ;; body); for head clauses additionally collect the residual checks.
     (define (convert-clauses cls [head? #f])
       (for/fold ([kept '()] [extra-body '()] [consts (set)] [checks '()]
                  #:result (values (reverse kept) (reverse extra-body) consts
                                   (reverse checks)))
                 ([cl (in-list cls)])
         (define s (enum-ref cl))
         (cond
           [s
            (define cx (gensymb '_tconst))
            (define x (match cl
                        [`(syn ,_ = ,x ,_) x]
                        [_ (gensymb '_)]))
            (define p (syn-prov cl))
            (values kept
                    (list* `(syn ,p = ,cx (syn ,p const ,(symbol->string s)))
                           `(syn ,p = ,x (syn ,p _enum ,cx))
                           extra-body)
                    (set-add consts (symbol->string s))
                    checks)]
           [else (values (cons (check-clause cl) kept)
                         extra-body
                         consts
                         (if head?
                             (append (reverse (head-residual-checks cl)) checks)
                             checks))])))

     (define-values (bodys+ body-extra body-consts _bchecks)
       (convert-clauses bodys))
     (define-values (heads+ head-extra head-consts hchecks)
       (convert-clauses heads #t))

     ;; Materialize the residual checks as head-position tycheck clauses,
     ;; BEFORE the emissions: a failing check must abandon the deduction
     ;; with no head fired.  The rule-location string and target names ride
     ;; the ordinary constants machinery (globalized + interned at load).
     ;; The location keeps only the file's basename (1-based line): absolute
     ;; paths would make error facts -- and any golden output containing
     ;; them -- vary with the checkout location.  Same-named files in
     ;; different directories collide; rel/col disambiguate in practice.
     (define (basename f)
       (define p (file-name-from-path (format "~a" f)))
       (if p (path->string p) (format "~a" f)))
     (define check-clauses
       (if (null? hchecks)
           '()
           (let ([rid (gensymb '_trid)]
                 [loc (match prov
                        [`(prov (token ,_ (pos ,file ,line ,_ ...) ,_) ,_)
                         (format "~a:~a" (basename file) (add1 line))]
                        [_ "<unknown>"])])
             (cons
              `(syn ,prov = ,rid (syn ,prov const ,loc))
              (append-map
               (match-lambda
                 [(list name col y accepts)
                  (define relv (gensymb '_trel))
                  (define colv (gensymb '_tcol))
                  (list `(syn ,prov = ,relv (syn ,prov const ,(symbol->string name)))
                        `(syn ,prov = ,colv (syn ,prov const ,col))
                        `(syn ,prov tycheck ,y (accept ,@accepts) ,rid ,relv ,colv))])
               hchecks)))))

     (values `(syn ,prov rule ,@body-extra ,@head-extra ,@bodys+
                   --> ,@check-clauses ,@heads+)
             (set-union body-consts head-consts))]))

;; -----------------------------------------------------------------------
;; The error-wrapping machinery around the residual checks above.

;; Does any head of this typed rule carry a residualized check?
(define (rule-has-tychecks? rule)
  (match rule
    [`(syn ,_ rule ,bodys ... --> ,heads ...)
     (for/or ([cl (in-list heads)])
       (match cl
         [`(syn ,_ tycheck ,_ ...) #t]
         [_ #f]))]))

;; The wrap rule compile.rkt injects into every stratum that carries
;; residual checks: (= e (malformed_deduction r s c v)) --> (error e).
;; Driven by malformed_deduction's delta (the stratum marks it dynamic),
;; it wraps each error struct as an (error e) fact within the same
;; fixpoint, one iteration after the failing deduction -- so a client
;; watching `error` can react (warn, or kill the run) while the fixpoint
;; is still going.  Fresh variables per call keep injected copies from
;; colliding across strata.
(define (error-wrap-rule)
  (error-wrap-rule-for-arm 'malformed_deduction))

;; Field arity of each error_spec arm (matches modules.rkt base-type-env).
(define error-arm-arity
  (hash 'malformed_deduction 4 'div_by_zero 2 'modulo_by_zero 2
        'int_overflow 3 'nan_result 3 'toint_range 2 'type_mismatch 4))

;; The runtime-prim error arms (all except malformed_deduction, which is the
;; head residual-check arm gated separately by rule-has-tychecks?).
(define prim-error-arms
  '(div_by_zero modulo_by_zero int_overflow nan_result toint_range type_mismatch))

;; Generalized wrap rule for one error_spec arm:
;;   (= e (<arm> f0 f1 ...)) --> (error e)
;; injected per-stratum (compile.rkt) so a produced error_spec surfaces as an
;; (error e) fact, delta-driven within the same fixpoint.  Fresh vars per call.
(define (error-wrap-rule-for-arm arm)
  (define p `(prov ,synth-token ,synth-token))
  (define e (gensymb '_erre))
  (define vs (for/list ([_ (in-range (hash-ref error-arm-arity arm))]) (gensymb '_errf)))
  `(syn ,p rule
        (syn ,p = ,e (syn ,p ,arm ,@vs))
        -->
        (syn ,p error ,e)))

;; Does this typed rule use any fallible prim -- a value-producing primitive
;; (prim-fun-env) let-bound, or an ordering-comparison guard -- so its stratum
;; must wire the runtime-error arms + wrap rules?
(define (rule-has-fallible-prims? rule)
  (let walk ([e rule])
    (match e
      ;; a value prim, let-bound (post-simplification form) or =-bound
      [`(syn ,_ ,(or 'let '=) ,_ (syn ,_ ,(? symbol? f) ,_ ...))
       #:when (hash-has-key? prim-fun-env f)
       #t]
      ;; an ordering-comparison guard
      [`(syn ,_ ,(? symbol? h) ,_ ,_)
       #:when (primitive-cmp? h)
       #t]
      [`(syn ,_ ,_ ,es ...) (ormap walk es)]
      [_ #f])))
