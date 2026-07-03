#lang racket

;; Shared IR components used across the whole compiler pipeline.
;;
;; Every intermediate language in the stack (see ir-stack.rkt) is built from
;; the same handful of pieces defined here:
;;   - `syn` provenance wrappers produced by the parser,
;;   - variables and literal constants,
;;   - the primitive-operator taxonomy (value-producing vs guard),
;;   - the three-part type environment threaded from the module system,
;;   - clause variable analysis (all / required / bound vars) over the
;;     clause grammar shared by the middle-end passes.
;;
;; ir-stack.rkt layers the per-level rule/program predicates on top of these;
;; a pass that needs to look inside a clause should get its building blocks
;; from here rather than re-deriving them.

(provide
 ;; provenance
 syn? syn-prov strip-prov
 ;; atoms
 var? slog-literal?
 ;; primitive operators
 primitive-unarop? primitive-binop? primitive-triarop?
 primitive-cmp? cmp-prim-name
 ;; type environments
 empty-type-env type-env? type-env-aliases type-env-rels type-env-funs
 rel-decl-kind rel-decl-arity
 ;; lattice value types
 lattice-spec? lattice-spec-kind lattice-spec-base lattice-spec-param
 lattice-base-type rel-lattice-spec rel-lattice-key-arity
 ;; clause analysis (typed/planned clause grammar)
 clause-vars clause-in-vars clause-out-vars head-in-vars)

(require "primitives.rkt")

;; -----------------------------------------------------------------------
;; Provenance
;;
;; The parser wraps every expression as (syn (prov tok0 tok1) e ...), where
;; the two tokens delimit the source range.  Passes match through the
;; wrapper and rebuild it, so provenance survives to error messages.

(define (syn? e)
  (match e
    [`(syn (prov ,_ ,_) ,_ ...) #t]
    [_ #f]))

(define (syn-prov e)
  (match e
    [`(syn ,prov ,_ ...) prov]
    [_ (error 'syn-prov "not a syn form: ~a" e)]))

;; Strip provenance wrappers from any (possibly nested) value, for display,
;; hashing, and structural checks.
(define (strip-prov e)
  (match e
    [`(syn ,prov . ,e0) (strip-prov e0)]
    [`((token ,_ ...) ...) '(toks)]
    [(? list? e) (map strip-prov e)]
    [(? set? s) (list->set (map strip-prov (set->list s)))]
    [(? hash? h)
     (foldl (lambda (k h+) (hash-set h+ (strip-prov k) (strip-prov (hash-ref h k))))
            (hash)
            (hash-keys h))]
    [_ e]))

;; -----------------------------------------------------------------------
;; Atoms

;; Variables (and relation names) are plain symbols.
(define (var? x)
  (symbol? x))

;; Literals a (const v) form may carry.  Symbols cover the parser's
;; `true`/`false`, which the type checker rewrites into enum constants.
(define (slog-literal? v)
  (or (number? v) (string? v) (symbol? v)))

;; -----------------------------------------------------------------------
;; Primitive operators
;;
;; Value-producing primitives ((= r (op args ...)), let-bound by the type
;; checker) are enumerated by arity; their type signatures live in
;; primitives.rkt.  Ordering comparisons are NOT value-producing: they are
;; body guards (filters, like /=) recognized structurally.

(define (primitive-unarop? x)
  (match x
    [(or 'size 'neg 'abs 'bnot
         'sqrt 'sin 'cos 'tan 'exp 'log 'floor 'ceil 'round
         'tofloat 'toint) #t]
    [_ #f]))

(define (primitive-binop? x)
  (match x
    [(or '- '+ '* '/ '% 'min 'max 'pow
         'band 'bor 'bxor 'shl 'shr) #t]
    [_ #f]))

(define (primitive-triarop? x)
  (match x
    ['substr #t]
    [_ #f]))

(define (primitive-cmp? x)
  (match x
    [(or '< '<= '> '>=) #t]
    [_ #f]))

;; The runtime prim function base name (daemon/prims.h) for a comparison op.
;; Chosen alnum so escape-id-for-C leaves it untouched.
(define (cmp-prim-name op)
  (match op
    ['<  'lt]
    ['<= 'le]
    ['>  'gt]
    ['>= 'ge]))

;; -----------------------------------------------------------------------
;; Type environments
;;
;; A type environment is a list of three hashes:
;;   aliases : union-type name -> set of member type names (transitively closed)
;;   rels    : relation name   -> (table t ...) | (struct t ...) | (enum name)
;;                                | (temp arity)          [added by the planner]
;;   funs    : primitive name  -> (fun argt ... -> rett)
;; Built and merged by modules.rkt; consumed by the type checker and planner.

(define empty-type-env `(,(hash) ,(hash) ,prim-fun-env))

(define (type-env? e)
  (match e
    [`(,(? hash?) ,(? hash?) ,(? hash?)) #t]
    [_ #f]))

(define (type-env-aliases e) (first e))
(define (type-env-rels e) (second e))
(define (type-env-funs e) (third e))

;; The kind tag and column count of a rel-env declaration.
(define (rel-decl-kind decl) (first decl))
(define (rel-decl-arity decl)
  (match decl
    [`(table ,ts ...) (length ts)]
    [`(struct ,ts ...) (length ts)]
    [`(temp ,arity) arity]
    [`(enum ,_) 0]
    [`(lattice ,_ ...) 0]))

;; -----------------------------------------------------------------------
;; Lattice value types (docs/lattices.md).
;;
;; A `lattice` declaration binds a name to a valuespec in the rels env:
;;   (lattice min int)               (lattice min int (floor 0))
;;   (lattice max float)             (lattice max int (ceiling 100))
;;   (lattice count)                 (lattice flat T)
;; A table whose LAST column has a lattice type is a map from its other
;; (key) columns to the merged value; the value column's storage type is
;; the lattice's base type.  For typing purposes lattice types are
;; transparent (they resolve to their base); the monotone-use discipline
;; is enforced by lattice-check.rkt.

(define (lattice-spec? d)
  (match d
    [`(lattice ,_ ...) #t]
    [_ #f]))

(define (lattice-spec-kind spec) (second spec))

(define (lattice-spec-base spec)
  (match spec
    [`(lattice ,(or 'min 'max) ,base ,_ ...) base]
    [`(lattice count) '$count]
    [`(lattice flat ,t) t]))

;; A keyword parameter of the spec: (lattice-spec-param spec 'floor) -> 0 | #f
(define (lattice-spec-param spec key)
  (for/first ([p (in-list (cdr spec))]
              #:when (and (pair? p) (eq? (car p) key)))
    (second p)))

;; Resolve a column type through the rels env: the lattice's base type if
;; it names a lattice, the type itself otherwise.
(define (lattice-base-type rel-env t)
  (match (hash-ref rel-env t #f)
    [(? lattice-spec? spec) (lattice-spec-base spec)]
    [_ t]))

;; The valuespec of a map relation: #f unless `name` is a table whose last
;; column is lattice-typed (declaration validation guarantees a lattice
;; type appears only there).
(define (rel-lattice-spec rel-env name)
  (match (hash-ref rel-env name #f)
    [`(table ,ts ..1)
     (match (hash-ref rel-env (last ts) #f)
       [(? lattice-spec? spec) spec]
       [_ #f])]
    [_ #f]))

(define (rel-lattice-key-arity rel-env name)
  (match (hash-ref rel-env name #f)
    [`(table ,ts ..1) (sub1 (length ts))]
    [_ #f]))

;; -----------------------------------------------------------------------
;; Clause variable analysis
;;
;; Over the clause grammar shared by the typed and planned levels (see
;; ir-stack.rkt).  Three views of a clause:
;;   clause-vars     every variable the clause mentions
;;   clause-in-vars  variables that must already be bound for it to run
;;   clause-out-vars variables it can bind (ground) when it runs

(define (clause-vars cl)
  (match cl
    [`(syn ,_ /= ,x ,y) (set x y)]
    [`(syn ,_ == ,x ,y) (set x y)]
    [`(syn ,_ ,(? primitive-cmp?) ,x ,y) (set x y)]
    [`(syn ,_ let ,x ,(? var? y)) (set x y)]
    [`(syn ,_ let ,x (syn ,_ const ,_)) (set x)]
    [`(syn ,_ let ,x (syn ,_ ,f ,args ...)) (list->set (cons x args))]
    [`(syn ,_ = ,x (syn ,_ const ,_)) (set x)]
    [`(syn ,_ = ,x (syn ,_ ,name ,xs ...)) (list->set (cons x xs))]
    [`(syn ,_ ,name ,xs ...) (list->set xs)]))

(define (clause-in-vars cl)
  (match cl
    [`(syn ,_ /= ,x ,y) (set x y)]
    [`(syn ,_ == ,x ,y) (set x y)]
    [`(syn ,_ ,(? primitive-cmp?) ,x ,y) (set x y)]
    [`(syn ,_ let ,x ,(? var? y)) (set y)]
    [`(syn ,_ let ,x (syn ,_ const ,_)) (set)]
    [`(syn ,_ let ,x (syn ,_ ,f ,args ...)) (list->set args)]
    [`(syn ,_ = ,x (syn ,_ const ,_)) (set)]
    ;; Join clauses require nothing: an index scan/probe can ground all
    ;; of their columns.
    [`(syn ,_ = ,x (syn ,_ ,name ,xs ...)) (set)]
    [`(syn ,_ ,name ,xs ...) (set)]))

(define (clause-out-vars cl)
  (set-subtract (clause-vars cl) (clause-in-vars cl)))

;; Head clauses invert the join reading: an emit consumes all its columns,
;; and a construction consumes its fields (producing only the fresh id).
(define (head-in-vars cl)
  (match cl
    [`(syn ,_ let ,x ,(? var? y)) (set y)]
    [`(syn ,_ let ,x (syn ,_ ,f ,args ...)) (list->set args)]
    [`(syn ,_ = ,x (syn ,_ const ,_)) (set)]
    [`(syn ,_ = ,x (syn ,_ ,name ,xs ...)) (list->set xs)]
    [`(syn ,_ ,name ,xs ...) (list->set xs)]))
