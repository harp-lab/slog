#lang racket

;; The compiler's stack of intermediate languages, top to bottom.
;;
;; Each pass consumes one level and produces the next; compile.rkt wires the
;; passes together and applies these predicates as coarse contracts -- one
;; check per pass over the actual program, not per-node decoration (the
;; checks are O(program) and the pipeline runs each only once per stratum).
;;
;;   module-ast          parser.rkt            (module path toks ast)
;;     |  modules.rkt: include/run resolution, type-env extraction+merge,
;;     |               demand desugar (demand.rkt)
;;   program-list        modules.rkt           (program type-env mods manifest)
;;     |  simplification.rkt: or-split, flatten, wildcards, static unification
;;   flat rules          (set/c flat-rule?)
;;     |  type-system.rkt: check + normalize (prim calls -> let, enums -> consts)
;;   typed rules         (set/c typed-rule?)
;;     |  stratify.rkt: Tarjan SCC condensation -> DAG of strata (topo order)
;;   strata              strata?
;;     |  join-planning.rkt: head staging + body scheduling, per stratum
;;   planned rules       (listof planned-rule?)
;;     |  operationalization.rkt: constants, indices, lowering
;;   c-program           cprog?
;;     |  emit-cpp.rkt
;;   C++ source          string
;;
;; Shared building blocks (syn wrappers, clause analysis, type envs, prim
;; taxonomy) live in ir-shared.rkt; this file is just the level grammars.

(provide module-ast? program-list? program?
         flat-rule? typed-rule?
         strata? stratum? stratum-level stratum-rules
         planned-rule?
         cprog? cprog-dynamic-rels cprog-constants cprog-decls cprog-rules
         crule? crule-pre crule-driver crule-body crule-head)

(require "ir-shared.rkt")

(define natural? exact-nonnegative-integer?)

;; -----------------------------------------------------------------------
;; Level 0: parsed module (parser.rkt).  The body is an arbitrary nest of
;; (syn prov tag e ...) forms; only the frame is checked here.

(define (module-ast? m)
  (match m
    [`(module ,(? string?) ,(? list?) ,(? syn?)) #t]
    [_ #f]))

;; -----------------------------------------------------------------------
;; Level 1: resolved program list (modules.rkt).
;;
;; A source file plus its transitive `include`s becomes one program; its
;; `run` directives contribute predecessor programs, linearized into a list
;; (dependencies first).  Each program carries the merged type environment
;; of its modules and the manifest of relations already present in the
;; database when it starts (from the input DB and all earlier programs).

(define (program? p)
  (match p
    [`(program ,(? type-env?) ,(? set? mods) ,(? hash?)) #t]
    [_ #f]))

(define (program-list? ps)
  (and (list? ps) (andmap program? ps)))

;; -----------------------------------------------------------------------
;; Levels 2 and 3: flat and typed rules.
;;
;; Simplification flattens all nested structure: every clause argument is a
;; variable, nested constructions having been lifted into fresh (= var ...)
;; clauses, `|` alternatives split into separate rules, wildcards gensym'd.
;;
;;   flat body clause ::= (/= x y) | (< x y) | ... cmp guards
;;                      | (= x (const v))
;;                      | (= x (name x ...))     struct pattern / prim call
;;                      | (name x ...)           relation pattern
;;   flat head clause ::= all but /= and cmp guards
;;
;; The type checker keeps the same shape but normalizes: primitive calls
;; become (let x (f args ...)) clauses, enum references become _enum struct
;; patterns plus string constants, and bare struct patterns gain their id
;; binding (= fresh (name ...)).  It also residualizes dynamic type checks
;; as head-position clauses placed before the emissions they guard:
;;
;;   (tycheck y (accept t ...+) rid rel col)
;;
;; -- at runtime, if y's surface tag is none of the accepted ground types,
;; emit (malformed_deduction rid rel col y) instead of the rule's heads
;; (rid/rel/col are const-bound reporting variables).  Invisible to
;; stratification; see type-system.rkt.

(define (const-clause? cl)
  (match cl
    [`(syn ,_ = ,(? var?) (syn ,_ const ,(? slog-literal?))) #t]
    [_ #f]))

(define (join-clause? cl)
  (match cl
    [`(syn ,_ = ,(? var?) (syn ,_ ,(? var?) ,(? var?) ...)) #t]
    [`(syn ,_ ,(? var? name) ,(? var?) ...)
     (and (not (memq name '(= /= == let const)))
          (not (primitive-cmp? name)))]
    [_ #f]))

(define (let-clause? cl)
  (match cl
    [`(syn ,_ let ,(? var?) ,(? var?)) #t]
    [`(syn ,_ let ,(? var?) (syn ,_ ,(? var?) ,(? var?) ...)) #t]
    [`(syn ,_ let ,(? var?) (syn ,_ const ,(? slog-literal?))) #t]
    [_ #f]))

;; /= and comparison guards exist from the flat level on; == equality
;; checks are introduced by the planner and legal only at the planned level.
(define (flat-guard-clause? cl)
  (match cl
    [`(syn ,_ /= ,(? var?) ,(? var?)) #t]
    [`(syn ,_ ,(? primitive-cmp?) ,(? var?) ,(? var?)) #t]
    [_ #f]))

(define (guard-clause? cl)
  (match cl
    [`(syn ,_ == ,(? var?) ,(? var?)) #t]
    [_ (flat-guard-clause? cl)]))

(define (flat-body-clause? cl)
  (or (flat-guard-clause? cl) (const-clause? cl) (join-clause? cl)))

(define (flat-head-clause? cl)
  (or (const-clause? cl) (join-clause? cl)))

(define (tycheck-clause? cl)
  (match cl
    [`(syn ,_ tycheck ,(? var?) (accept ,(? symbol?) ..1)
       ,(? var?) ,(? var?) ,(? var?)) #t]
    [_ #f]))

(define (flat-rule? r)
  (match r
    [`(syn ,_ rule ,body ... --> ,head ...)
     (and (andmap flat-body-clause? body) (andmap flat-head-clause? head))]
    [_ #f]))

(define (typed-rule? r)
  (match r
    [`(syn ,_ rule ,body ... --> ,head ...)
     (and (andmap (lambda (cl) (or (flat-body-clause? cl) (let-clause? cl))) body)
          (andmap (lambda (cl) (or (flat-head-clause? cl) (let-clause? cl)
                                   (tycheck-clause? cl)))
                  head))]
    [_ #f]))

;; -----------------------------------------------------------------------
;; Level 4: strata (stratify.rkt).
;;
;; The DAG of SCCs of the relation dependency graph, condensed to a list of
;; strata in topological order.  Each stratum holds the typed rules whose
;; head relations belong to that level; independent (sibling) SCCs at the
;; same depth are merged into a single stratum, so "run the list in order"
;; is a valid (and maximally merged) schedule of the DAG.

(define (stratum? s)
  (match s
    [`(stratum ,(? natural?) ,(? set? rules))
     (andmap typed-rule? (set->list rules))]
    [_ #f]))

(define (strata? ss)
  (and (list? ss) (andmap stratum? ss)))

(define (stratum-level s) (second s))
(define (stratum-rules s) (third s))

;; -----------------------------------------------------------------------
;; Level 5: planned rules (join-planning.rkt).
;;
;; Same clause forms as the typed level, but the body is now an ordered
;; schedule: constants (as lets) first, then join clauses interleaved with
;; the guards and computations that become runnable as their inputs ground
;; (head computations are scheduled into the body too, so heads are pure
;; emissions).  The first join clause is the rule's driver -- the clause
;; whose delta fires the rule.  Value equality checks (== x y) may appear
;; where the planner reconciled a computed value with an already-ground
;; variable.

(define (planned-rule? r)
  (match r
    [`(syn ,_ rule ,body ... --> ,head ...)
     (and (andmap (lambda (cl) (or (guard-clause? cl) (let-clause? cl) (join-clause? cl)))
                  body)
          (andmap (lambda (cl) (or (let-clause? cl) (join-clause? cl)
                                   (tycheck-clause? cl)))
                  head))]
    [_ #f]))

;; -----------------------------------------------------------------------
;; Level 6: the c-program (operationalization.rkt), consumed by emit-cpp.
;;
;; All variables and primitive names are C-escaped here; relation names stay
;; raw (they only ever appear inside C string literals).
;;
;;   cprog   ::= (cprog dyn-rels constants (decl ...) (crule ...))
;;   decl    ::= (relation name arity idx ...)   idx ::= (col ...+)
;;             | (struct name arity idx ...)           | (delta col ...+)
;;             | (temp name arity)
;;   crule   ::= (crule (pre op ...) driver (body op ...) (head hop ...))
;;   driver  ::= (scan name x ...)          read the relation's delta
;;             | (probe name idx K x ...)   probe the relation's delta index
;;             | (once)                     fact rule: run at startup only
;;   op      ::= (join name idx K x ...)    probe/scan a full index
;;             | (exists name idx K x ...)  semijoin filter: prune the tuple
;;                                          unless some tuple of the full
;;                                          index matches the K bound cols
;;                                          (x ... are exactly the K key
;;                                          vars, in index-prefix order)
;;             | (let x y) | (let x (f y ...))
;;             | (eq x y) | (neq x y) | (cmp fn x y)
;; K counts the join's bound columns; the index orders those first, so the
;; probe key is the tuple's first K variables and the rest bind fresh.
;;   hop     ::= (let x (f y ...))
;;             | (mkstruct name idx x field ...)
;;             | (emit name idx x ...)
;;             | (emit-temp name x ...)
;;             | (tycheck x (accept t ...) rid rel col idx)
;;                 t ::= int | float | str | (struct name)
;;                 residual type check, always ahead of the emitting hops:
;;                 if x's tag matches no accepted t, emit the struct
;;                 (malformed_deduction rid rel col x) -- idx is its master
;;                 (interning) index -- and abandon the deduction

(define (index? i)
  (match i
    [`(delta ,(? natural?) ..1) #t]
    [`(,(? natural?) ..1) #t]
    [_ #f]))

(define (decl? d)
  (match d
    [`(relation ,(? var?) ,(? natural?) ,(? index?) ...) #t]
    [`(struct ,(? var?) ,(? natural?) ,(? index?) ..2) #t]
    ;; a lattice (map) relation: keys -> merged value (last storage column);
    ;; the spec is the valuespec sans its `lattice` head, e.g. (min int (floor 0));
    ;; non-delta indices are payload maps registered under full orderings that
    ;; end in the value column, delta indices are ordinary full-width sets
    [`(lattice ,(? var?) ,(? natural?) (,(? var?) ,_ ...) ,(? index?) ..1) #t]
    [`(temp ,(? var?) ,(? natural?)) #t]
    [_ #f]))

(define (c-op? op)
  (match op
    [`(join ,(? var?) (,(? natural?) ..1) ,(? natural?) ,(? var?) ...) #t]
    ;; a semijoin filter: existence probe of a future clause's relation on
    ;; the K currently-bound columns (which the index orders first)
    [`(exists ,(? var?) (,(? natural?) ..1) ,(? natural?) ,(? var?) ..1) #t]
    ;; a lattice body read: probe the payload map on the key prefix; the vars
    ;; are the key columns in index order plus, last, the bound merged value
    [`(join-lat ,(? var?) (,(? natural?) ..1) ,(? natural?) ,(? var?) ...) #t]
    [`(let ,(? var?) ,(? var?)) #t]
    [`(let ,(? var?) (,(? var?) ,(? var?) ...)) #t]
    [`(eq ,(? var?) ,(? var?)) #t]
    [`(neq ,(? var?) ,(? var?)) #t]
    [`(cmp ,(? var?) ,(? var?) ,(? var?)) #t]
    [_ #f]))

(define (c-driver? d)
  (match d
    [`(scan ,(? var?) ,(? var?) ...) #t]
    [`(probe ,(? var?) (,(? natural?) ..1) ,(? natural?) ,(? var?) ...) #t]
    [`(once) #t]
    [_ #f]))

(define (c-head-op? op)
  (match op
    [`(let ,(? var?) (,(? var?) ,(? var?) ...)) #t]
    [`(mkstruct ,(? var?) (,(? natural?) ..1) ,(? var?) ,(? var?) ...) #t]
    [`(emit ,(? var?) (,(? natural?) ..1) ,(? var?) ...) #t]
    [`(emit-temp ,(? var?) ,(? var?) ...) #t]
    ;; a lattice contribution, in storage order (keys then value): batched
    ;; with no dedup -- subsumption is decided at the merge (intern) phase
    [`(emit-lat ,(? var?) ,(? var?) ...) #t]
    ;; a residual type check guarding every emitting hop after it
    [`(tycheck ,(? var?) (accept ,(? c-accept?) ..1)
       ,(? var?) ,(? var?) ,(? var?) (,(? natural?) ..1)) #t]
    [_ #f]))

;; A runtime-testable type in a lowered accept set: a primitive tag or an
;; interned struct's id (enum members lower to (struct _enum)).
(define (c-accept? t)
  (match t
    [(or 'int 'float 'str) #t]
    [`(struct ,(? var?)) #t]
    [_ #f]))

(define (crule? r)
  (match r
    [`(crule (pre ,pre ...) ,driver (body ,body ...) (head ,head ...))
     (and (andmap c-op? pre)
          (c-driver? driver)
          (andmap c-op? body)
          (andmap c-head-op? head))]
    [_ #f]))

(define (cprog? p)
  (match p
    [`(cprog ,(? set?) ,(? hash?) (,(? decl?) ...) (,(? crule?) ...)) #t]
    [_ #f]))

(define (cprog-dynamic-rels p) (second p))
(define (cprog-constants p) (third p))
(define (cprog-decls p) (fourth p))
(define (cprog-rules p) (fifth p))

(define (crule-pre r) (cdr (second r)))
(define (crule-driver r) (third r))
(define (crule-body r) (cdr (fourth r)))
(define (crule-head r) (cdr (fifth r)))
