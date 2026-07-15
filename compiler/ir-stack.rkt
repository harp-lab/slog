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
         crule? crule-pre crule-driver crule-body crule-head crule-loc
         crule-kind)

(require "ir-shared.rkt")
(require "join-actions.rkt")

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
;; of its modules, the manifest of relations already present in the
;; database when it starts (from the input DB and all earlier programs),
;; and its decomp-env -- the M2.4 decomposition registry
;; (derived-name -> (base-name set|map), modules.rkt synthesis).

(define (program? p)
  (match p
    [`(program ,(? type-env?) ,(? set? mods) ,(? hash?) ,(? hash?)) #t]
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
;;                      | (~ (name x ...))       negated relation atom
;;                                               (stratified negation, §0.8:
;;                                               args all vars -- constants
;;                                               lifted positively, wildcards
;;                                               __-gensym'd; body only)
;;   flat head clause ::= all but /= and cmp guards and negated atoms
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

;; a planner-marked "old" join: $oldjoin wrapping a join clause (exact
;; semi-naive, docs/incremental.md §6/§8).  Legal only at the planned level;
;; operationalization strips the mark and lowers it to join_probe_old.
(define (old-join-clause? cl)
  (match cl
    [`(syn ,_ $oldjoin ,inner) (join-clause? inner)]
    [_ #f]))

;; Planner-marked pre-state join for negative maintenance.  Operationally the
;; live FULL index is the post-deletion N view, so O is FULL union delta.
(define (new-join-clause? cl)
  (match cl
    [`(syn ,_ $newjoin ,inner) (join-clause? inner)]
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

;; A neutral sequence-pattern clause (collections.rkt; docs/sequences.md
;; §5.1): flat-level ONLY -- seq-expand.rkt lowers every one onto ordinary
;; clauses before typechecking, so the typed level never sees them.
(define (seq-pat-item? it)
  (match it
    [`(,(or 'elem 'splice) ,(? var?)) #t]
    [`(elemc ,(? slog-literal?)) #t]
    [_ #f]))

(define (seq-pat-clause? cl)
  (match cl
    [`(syn ,_ seq-pat ,(? var?) ,(? seq-pat-item?) ...) #t]
    [_ #f]))

(define (flat-body-clause? cl)
  (or (flat-guard-clause? cl) (const-clause? cl) (join-clause? cl)
      (seq-pat-clause? cl) (neg-clause? cl)))

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
    ;; seeded-rule: a staged rule's seeded re-entry version (join-planning
    ;; plan-stratum) -- same clause grammar, full-index lowering downstream
    [`(syn ,_ ,(or 'rule 'seeded-rule) ,body ... --> ,head ...)
     (and (andmap (lambda (cl) (or (guard-clause? cl) (let-clause? cl) (join-clause? cl)
                                   (old-join-clause? cl) (new-join-clause? cl)
                                   (neg-clause? cl) (expand3-action? cl)))
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
;;             | (lattice name arity spec decomp idx ...)
;;                 decomp ::= #f | (decomp name set|map)   [M2.4]
;;             | (temp name arity)
;;   crule   ::= (crule (pre op ...) driver (body op ...) (head hop ...) loc kind)
;;                 loc  ::= "file:line" | #f
;;                 kind ::= #f | input | nonrec | rec     [_count flavor, §6.4]
;;   driver  ::= (scan name x ...)          read the relation's delta
;;             | (probe name idx K x ...)   probe the relation's delta index
;;             | (once)                     fact rule: run at startup only
;;   op      ::= (join name idx K x ...)    probe/scan a full index
;;             | (exists name idx K x ...)  semijoin filter: prune the tuple
;;                                          unless some tuple of the full
;;                                          index matches the K bound cols
;;                                          (x ... are exactly the K key
;;                                          vars, in index-prefix order)
;;             | (absent name idx K x ...)  negated atom (§0.8): prune the
;;                                          tuple when some tuple of the
;;                                          (closed) relation's full index
;;                                          matches the K bound cols; K = 0
;;                                          tests relation emptiness
;;             | (absent-lat name idx K x ...)  negation over lattice keys:
;;                                          prune when the payload map holds
;;                                          any entry under the K-bound
;;                                          key prefix
;;             | (let x y) | (let x (f y ...))
;;             | (letp x (f y ...))   partial prim (prim-partial?): the call
;;                                    takes a trailing bool* ok; !ok abandons
;;                                    the current tuple (absence, not error)
;;             | (cjoin x spec a b)   spec-aware pointwise join (§D): the
;;                                    collection-lattice spec (sans `lattice`
;;                                    head) is baked in; emitted as a
;;                                    merge_spec call under its parsed tree
;;             | (eq x y) | (neq x y) | (cmp fn x y)
;; K counts the join's bound columns; the index orders those first, so the
;; probe key is the tuple's first K variables and the rest bind fresh.
;;   hop     ::= (let x (f y ...)) | (letp x (f y ...)) | (cjoin x spec a b)
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
    ;; requisitioned ONLY by seeded re-entry rules: its WriteTask registers
    ;; via addTaskSeeded, so fresh runs skip its maintenance
    [`(seeded-only ,(? natural?) ..1) #t]
    [`(,(? natural?) ..1) #t]
    [_ #f]))

(define (decl? d)
  (match d
    [`(relation ,(? var?) ,(? natural?) ,(? index?) ...) #t]
    [`(struct ,(? var?) ,(? natural?) ,(? index?) ..2) #t]
    ;; a lattice (map) relation: keys -> merged value (last storage column);
    ;; the spec is the valuespec sans its `lattice` head, e.g. (min int (floor 0));
    ;; non-delta indices are payload maps registered under full orderings that
    ;; end in the value column, delta indices are ordinary full-width sets.
    ;; The decomp slot is the M2.4 decomposition target: #f, or
    ;; (decomp <derived-name> set|map) registered on the master merge tasks
    ;; (docs/primitives.md §4.2)
    [`(lattice ,(? var?) ,(? natural?) (,(? var?) ,_ ...) ,decomp ,(? index?) ..1)
     (match decomp
       [#f #t]
       [`(decomp ,(? var?) ,(or 'set 'map)) #t]
       [_ #f])]
    [`(temp ,(? var?) ,(? natural?)) #t]
    ;; an extern relation's oracle binding (docs/smt.md): registers the
    ;; daemon-side dispatch/harvest tasks against the (already-declared)
    ;; demand struct and its answer table
    [`(oracle ,(? var?) ,(? var?) ,(? var?)) #t]
    ;; a sequence-occurrence feeding registration (docs/sequences.md §5.3):
    ;; one SeqIndexTask walking the named base relation's sequence-typed
    ;; storage columns into $seq_at/$seq_atr.  Emitted after all relation
    ;; decls (build-cprog appends it) so the getRelation lookups succeed.
    [`(seqindex ,(? var?) (,(? natural?) ..1)) #t]
    [_ #f]))

(define (join3-arm? arm)
  (match arm
    [`(,(or 'full 'old 'new) ,(? var?) (,(? natural?) ..1)
       ,(? natural?) ,dind ,(? var?) ..1)
     (or (null? dind)
         (and (list? dind) (pair? dind) (andmap natural? dind)))]
    [_ #f]))

(define (c-op? op)
  (match op
    [`(join ,(? var?) (,(? natural?) ..1) ,(? natural?) ,(? var?) ...) #t]
    ;; exact semi-naive R_old join (docs/incremental.md §6/§8): a full index,
    ;; K bound cols, then the SAME-ordering delta index to exclude against
    [`(join-old ,(? var?) (,(? natural?) ..1) ,(? natural?) (,(? natural?) ..1) ,(? var?) ...) #t]
    ;; negative exact partition: FULL union current delta (pre-state O)
    [`(join-new ,(? var?) (,(? natural?) ..1) ,(? natural?) (,(? natural?) ..1) ,(? var?) ...) #t]
    [`(join3 ,(? var?) ,(? join3-arm?) ,(? join3-arm?)) #t]
    ;; a semijoin filter: existence probe of a future clause's relation on
    ;; the K currently-bound columns (which the index orders first)
    [`(exists ,(? var?) (,(? natural?) ..1) ,(? natural?) ,(? var?) ..1) #t]
    ;; a negated atom (docs/incremental.md §0.8): absence probe of a CLOSED
    ;; relation on the K bound columns (the index orders them first);
    ;; K = 0 tests emptiness.  Prunes the tuple when a match EXISTS.
    [`(absent ,(? var?) (,(? natural?) ..1) ,(? natural?) ,(? var?) ...) #t]
    ;; its lattice form: key-prefix absence probe of the payload map
    ;; ("no value at key k"); the vars are the K bound key columns
    [`(absent-lat ,(? var?) (,(? natural?) ..1) ,(? natural?) ,(? var?) ...) #t]
    ;; a lattice body read: probe the payload map on the key prefix; the vars
    ;; are the key columns in index order plus, last, the bound merged value
    [`(join-lat ,(? var?) (,(? natural?) ..1) ,(? natural?) ,(? var?) ...) #t]
    [`(let ,(? var?) ,(? var?)) #t]
    [`(let ,(? var?) (,(? var?) ,(? var?) ...)) #t]
    ;; a partial prim's let: same shape, row-abandoning failure channel
    [`(letp ,(? var?) (,(? var?) ,(? var?) ...)) #t]
    ;; the spec-aware pointwise join (§D)
    [`(cjoin ,(? var?) (,(? var?) ,_ ...) ,(? var?) ,(? var?)) #t]
    [`(eq ,(? var?) ,(? var?)) #t]
    [`(neq ,(? var?) ,(? var?)) #t]
    [`(cmp ,(? var?) ,(? var?) ,(? var?)) #t]
    [_ #f]))

(define (c-driver? d)
  (match d
    [`(scan ,(? var?) ,(? var?) ...) #t]
    [`(probe ,(? var?) (,(? natural?) ..1) ,(? natural?) ,(? var?) ...) #t]
    [`(once) #t]
    ;; a staged rule's seeded re-entry task: no delta anywhere -- every
    ;; join in `body` reads a FULL index; runs each iteration only when
    ;; the stratum began over externally seeded content
    [`(seeded) #t]
    [_ #f]))

(define (c-head-op? op)
  (match op
    [`(let ,(? var?) (,(? var?) ,(? var?) ...)) #t]
    [`(letp ,(? var?) (,(? var?) ,(? var?) ...)) #t]
    [`(cjoin ,(? var?) (,(? var?) ,_ ...) ,(? var?) ,(? var?)) #t]
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

;; A runtime-testable type in a lowered accept set: a primitive tag, the
;; collection-word tag (cset/cmap both lower to the shared cnode test),
;; the sequence-word tag (cseq lowers to seq), or an interned struct's id
;; (enum members lower to (struct _enum)).
(define (c-accept? t)
  (match t
    [(or 'int 'float 'str 'cnode 'seq) #t]
    [`(struct ,(? var?)) #t]
    [_ #f]))

(define (crule? r)
  (match r
    ;; trailing `loc` = the rule's "file:line" (or #f), baked by emit-cpp into
    ;; any runtime-error (error_spec ...) this rule reports (docs/type-errors.md);
    ;; `kind` = the rule's counting classification (docs/incremental.md §6.4),
    ;; #f outside the _count flavor: 'input | 'nonrec | 'rec selects which
    ;; sidecar counter the counting sinks bump
    [`(crule (pre ,pre ...) ,driver (body ,body ...) (head ,head ...) ,loc ,kind)
     (and (andmap c-op? pre)
          (c-driver? driver)
          (andmap c-op? body)
          (andmap c-head-op? head)
          (or (string? loc) (not loc))
          (and (memq kind '(#f input nonrec rec)) #t))]
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
(define (crule-loc r) (sixth r))
(define (crule-kind r) (seventh r))
