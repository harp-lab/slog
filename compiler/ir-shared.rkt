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
 syn? syn-prov strip-prov rule-location-string with-rule-context
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
 ;; parametric collection column types (docs/primitives.md)
 listof-spec? mapof-spec?
 ;; negated body atoms (docs/incremental.md §0.8)
 neg-symbol? neg-clause? neg-inner neg-rel neg-args neg-wildcard-var?
 neg-view neg-retag
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

;; "basename:line" (1-based) for a rule/clause syn form, else "<unknown>".
;; The source position lives in the first delimiting token of the prov.
(define (rule-location-string form)
  (match form
    [`(syn (prov (token ,_ (pos ,file ,line ,_ ...) ,_ ...) ,_ ...) ,_ ...)
     (define p (file-name-from-path (format "~a" file)))
     (format "~a:~a" (if p (path->string p) file) (add1 line))]
    [_ "<unknown>"]))

;; Run `thunk`; if it raises a CONTRACT failure, re-raise with the rule's source
;; location prefixed.  A per-rule internal failure -- classically an unbound
;; variable surfacing deep in typecheck/planning/lowering as a locationless
;; `hash-ref: no value found '<var>`, or a pass output breaking its own IR
;; contract -- then names the offending rule instead of forcing a bisection
;; (docs/build-issues-notes.md §5).  We catch only exn:fail:contract, NOT plain
;; exn:fail: intentional user-facing errors (undeclared relation, arity mismatch,
;; type clash, ...) are raised via `error` as exn:fail and must keep their own
;; clear messages, not be relabelled "internal error".
(define (with-rule-context rule thunk)
  (with-handlers
      ([exn:fail:contract?
        (lambda (e)
          (error (format
                  (string-append
                   "internal error while compiling the rule at ~a -- this is often "
                   "an unbound variable (one used in a head or computation that no "
                   "body clause binds):\n  ~a")
                  (rule-location-string rule) (exn-message e))))])
    (thunk)))

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
    [`(lattice ,_ ...) 0]
    [`(listof ,_) 0]
    [`(mapof ,_ ,_) 0]
    [`(oracle ,_ ...) 0]))    ; an extern relation's binding entry (docs/smt.md)

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
    [`(lattice flat ,t) t]
    ;; collection lattices (docs/primitives.md §6.1): the payload word is a
    ;; canonical collection (cnode) -- typed by the builtin collection base
    ;; types so the native prims' signatures check contributions
    [`(lattice set ,_) 'cset]
    [`(lattice map ,_ ,_) 'cmap]))

;; A keyword parameter of the spec: (lattice-spec-param spec 'floor) -> 0 | #f
(define (lattice-spec-param spec key)
  (for/first ([p (in-list (cdr spec))]
              #:when (and (pair? p) (eq? (car p) key)))
    (second p)))

;; A parametric list column type: a deterministically-named rels entry
;; (listof T) that a `(list T)` (or `[T]`) column declaration produces
;; (modules.rkt).  Like lattice types it is transparent to the type
;; system, resolving to the builtin `cseq` base type -- a canonical
;; chunked-Merkle sequence word (docs/sequences.md §3.3; the cons-union
;; resolution retired with the builtin cons list) -- with the element
;; type preserved verbatim for the future typed phase (§8.4:
;; declaration-level fidelity).
(define (listof-spec? d)
  (match d
    [`(listof ,_) #t]
    [_ #f]))

;; A parametric map VALUE column type (docs/primitives.md M2.3): (map K V)
;; with V a plain type declares a (mapof K V) rels entry -- an immutable
;; canonical collection word.  Transparent like (listof T), resolving to
;; the builtin cmap base type; K/V preserved verbatim for the typed phase.
;; (Lattice-role maps -- (map K <valuespec>) -- are (lattice map ...) specs
;; instead; (set T) is always lattice-role.)
(define (mapof-spec? d)
  (match d
    [`(mapof ,_ ,_) #t]
    [_ #f]))

;; Resolve a column type through the rels env: the lattice's base type if
;; it names a lattice, the builtin cseq base type if it names a (listof T),
;; the builtin cmap base type if it names a (mapof K V), the type itself
;; otherwise.
(define (lattice-base-type rel-env t)
  (match (hash-ref rel-env t #f)
    [(? lattice-spec? spec)
     ;; a flat lattice's payload may itself need resolution -- e.g.
     ;; (flat list) resolves list -> cseq (the (listof any) seed) -- so
     ;; recurse; termination: payloads cannot be lattice types
     ;; (lattice-check) and every other arm is a fixed point
     (define b (lattice-spec-base spec))
     (if (eq? b t) b (lattice-base-type rel-env b))]
    [(? listof-spec?) 'cseq]
    [(? mapof-spec?) 'cmap]
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
;; Negated body atoms (docs/incremental.md §0.8, sub-phase 0.A).
;;
;; A body clause (syn prov ~ (syn prov2 name x ...)) is the stratified
;; negation of a relation atom: "no tuple of `name` matches".  From the
;; flat level on, every argument is a plain variable -- constants were
;; lifted into positive const clauses and `_` wildcards gensym'd to
;; `__`-prefixed variables (the established dead-var convention,
;; seq-expand.rkt).  A wildcard-derived variable appears nowhere else, so
;; it is an unconstrained (projected-away) column of the probe; every
;; other variable must be positively bound (safety, type-system.rkt).
;; Negated atoms bind nothing: they schedule like guards (fire once their
;; inputs are ground, only prune) and lower to an absent probe against a
;; CLOSED relation (stratification guarantees strictly-lower stratum).

;; `~` is the source spelling.  The maintenance planners (M4N,
;; docs/m4n-contract.md) retag negated atoms per version with an explicit
;; absence-evaluation state: `~old` (absence at the epoch's PRE state) and
;; `~new` (absence at the final POST state).  The retagged symbols exist
;; only from planning onward -- every pass before join-planning sees `~`.
(define (neg-symbol? s) (and (memq s '(~ ~old ~new)) #t))

;; The absence view a (possibly retagged) negated atom carries: 'pre, 'post,
;; or #f for the plain settled-state probe.
(define (neg-view cl)
  (case (third cl)
    [(~old) 'pre]
    [(~new) 'post]
    [else #f]))

;; Retag a negated clause with an absence-view symbol.
(define (neg-retag cl sym)
  `(syn ,(second cl) ,sym ,(neg-inner cl)))

;; The flat-level-and-later shape: inner args all plain variables.  Passes
;; that run BEFORE simplification (demand, collections) match the raw
;; (syn _ ~ inner) frame themselves -- there the inner atom may still
;; carry constants and `_` wildcards.
(define (neg-clause? cl)
  (match cl
    [`(syn ,_ ,(? neg-symbol?) (syn ,_ ,(? var?) ,(? var?) ...)) #t]
    [_ #f]))

(define (neg-inner cl) (fourth cl))

(define (neg-rel cl)
  (match (neg-inner cl)
    [`(syn ,_ ,name ,_ ...) name]))

(define (neg-args cl)
  (match (neg-inner cl)
    [`(syn ,_ ,_ ,args ...) args]))

;; A wildcard-derived (dead) variable: `_` gensyms to a `__`-prefixed name
;; in simplification; inside a negated atom these are the unconstrained
;; columns (not inputs, not outputs -- dead by construction).
(define (neg-wildcard-var? x)
  (and (symbol? x) (string-prefix? (symbol->string x) "__")))

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
    ;; a residual type check (type-system.rkt): the checked variable plus
    ;; the rule-location/relation/column constant variables it reports with
    [`(syn ,_ tycheck ,y (accept ,_ ...) ,rid ,rel ,col) (set y rid rel col)]
    [`(syn ,_ ,(? primitive-cmp?) ,x ,y) (set x y)]
    [`(syn ,_ let ,x ,(? var? y)) (set x y)]
    [`(syn ,_ let ,x (syn ,_ const ,_)) (set x)]
    [`(syn ,_ let ,x (syn ,_ ,f ,args ...)) (list->set (cons x args))]
    [`(syn ,_ = ,x (syn ,_ const ,_)) (set x)]
    [`(syn ,_ = ,x (syn ,_ ,name ,xs ...)) (list->set (cons x xs))]
    [(? neg-clause?) (list->set (neg-args cl))]
    [`(syn ,_ ,name ,xs ...) (list->set xs)]))

(define (clause-in-vars cl)
  (match cl
    [`(syn ,_ /= ,x ,y) (set x y)]
    [`(syn ,_ == ,x ,y) (set x y)]
    [`(syn ,_ tycheck ,y (accept ,_ ...) ,rid ,rel ,col) (set y rid rel col)]
    [`(syn ,_ ,(? primitive-cmp?) ,x ,y) (set x y)]
    [`(syn ,_ let ,x ,(? var? y)) (set y)]
    [`(syn ,_ let ,x (syn ,_ const ,_)) (set)]
    [`(syn ,_ let ,x (syn ,_ ,f ,args ...)) (list->set args)]
    [`(syn ,_ = ,x (syn ,_ const ,_)) (set)]
    ;; A negated atom is a pure filter: every non-wildcard variable is an
    ;; input (must be positively bound before the absent probe can run);
    ;; wildcard-derived variables are unconstrained columns, not inputs.
    [(? neg-clause?)
     (for/set ([x (in-list (neg-args cl))]
               #:unless (neg-wildcard-var? x))
       x)]
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
    [`(syn ,_ tycheck ,y (accept ,_ ...) ,rid ,rel ,col) (set y rid rel col)]
    [`(syn ,_ = ,x (syn ,_ const ,_)) (set)]
    [`(syn ,_ = ,x (syn ,_ ,name ,xs ...)) (list->set xs)]
    [`(syn ,_ ,name ,xs ...) (list->set xs)]))
