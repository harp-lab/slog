#lang racket

;; The module system: turns a source path into the ordered list of programs
;; the pipeline compiles.
;;
;;   - `include "file"` merges another file's modules (and type declarations)
;;     into the current program.  Relative paths resolve against the including
;;     file's directory, then fall back to the compiler's lib/ directory
;;     (so `include "list.slog"` works from anywhere).
;;   - `run "file"` names a prerequisite program: it is compiled separately
;;     and runs to fixpoint first, its database feeding this program.
;;
;; Loading a path therefore yields a tree of programs; linearizing it
;; dependencies-first gives the program list.  Alongside, each module's type
;; declarations (table/struct/union/enum/demand) are extracted into a type
;; environment (see ir-shared.rkt) and merged across modules with conflict
;; checking; and a manifest of relations already present in the database is
;; threaded through the list so each program declares what it inherits.
;;
;; M2.4 decomposition synthesis (docs/primitives.md §4.2) also happens here:
;; using an undeclared name `<R>_has` (`<R>_at`) where R is a set-kind
;; (map-kind) collection-lattice table synthesizes its declaration --
;; deterministic, no gensym, pre-cache-key like every decl -- and records R
;; as decomposed in the program's decomp-env, a parallel hash
;;   derived-name -> (base-name set|map)
;; threaded alongside the type env (program tuple, ir-stack.rkt).  Consumers:
;; stratify (the R -> R_has edge), the planner/operationalization/emit
;; (dynamic-rel marking + registering the decomp target on the base
;; relation's merge tasks).  A user declaring their own `foo_has` wins: no
;; interception, no decomposition.  No use -> no decl -> zero cost.
;;
;; A `demand (f in ...) out ...` declaration turns into its two backing
;; relations here -- struct (f in ...) and table (f_ans f out ...) -- and,
;; once each program's modules are merged, the demand transform
;; (demand.rkt) desugars every rule's judgment occurrences of f into plain
;; rules over those relations.  Programs leave this file free of demands.

(provide load-program-list
         type-env->catalog-delta)

(require racket/runtime-path)
(require "parser.rkt")
(require "utils.rkt")
(require "names.rkt")
(require "ir-shared.rkt")
(require "catalog.rkt")
(require "demand.rkt")
(require "collections.rkt")

;; -----------------------------------------------------------------------
;; Entry point: path -> (listof program?), dependencies first, manifests
;; threaded.  `input-manifest` describes the relations of the input DB
;; (name -> (rel name arity) | (struct name arity)).

(define current-input-catalog (make-parameter #f))

(define (load-program-list path input-manifest
                           #:input-catalog [input-catalog #f])
  (parameterize ([current-input-catalog input-catalog])
    (define tree (lift-type-envs (load-program-tree path)))
    (thread-manifests (linearize-programs tree) input-manifest)))

;; -----------------------------------------------------------------------
;; Include/run/instantiate resolution (N1).
;;
;; Includes contribute source units to one lexical occurrence. Instantiation
;; creates a fresh child occurrence with its own include-dedup set. Runs create
;; temporal predecessor programs while retaining the lexical home selected by
;; their occurrence options.

(struct raw-source (path tokens ast) #:transparent)
(struct raw-occurrence
  (entry-path alias home lexical-path bindings interface? sources children)
  #:transparent)
(struct raw-program (requirements root) #:transparent)
(struct qualified-module (ir type-env demands interface?) #:transparent)

(define (load-program-tree path [seen-run (set)])
  (define canonical (fullpath path))
  (resolve-program canonical '() '() '() (set-add seen-run canonical)))

;; An include/run target is available if it is on disk OR provided by the
;; source override (P1.1) -- so a stored program's closure resolves during a
;; recompute-on-load replay even when the original files are gone.
(define (source-available? p)
  (define ov (current-source-override))
  (or (and ov (hash-has-key? ov (source-key p)))
      (file-exists? p)))

;; An include path resolves relative to the including file's directory; a
;; relative path with no source there falls back to the compiler's sibling
;; lib/ directory, so the standard helpers are `include "list.slog"` from
;; anywhere.  The local candidate wins when both exist, and an unavailable
;; path stays local so the caller's availability filter behaves as before.
(define-runtime-path stdlib-dir "../lib")
(define (resolve-include p rel-dir)
  (define local (fullpath (normalize-path p rel-dir)))
  (cond
    [(source-available? local) local]
    [(or (absolute-path? p) (not (directory-exists? stdlib-dir))) local]
    [else
     (define stdlib (fullpath (normalize-path p stdlib-dir)))
     (if (source-available? stdlib) stdlib local)]))

(define (source-string directive)
  (match directive
    [`(syn ,_ const ,(? string? path)) path]
    [_ (error 'modules "module source must be a string literal: ~a"
              (strip-prov directive))]))

;; Return the body with its leading source-composition directives removed and
;; an ordered directive list. Source order matters for sibling run programs.
(define (strip-directives ast)
  (match ast
    [`(syn ,_ include ,source ,body)
     (define-values (body+ directives) (strip-directives body))
     (values body+ (cons `(include ,(source-string source)) directives))]
    [`(syn ,_ run ,source ,body)
     (define-values (body+ directives) (strip-directives body))
     (values body+ (cons `(run ,(source-string source) #f ()) directives))]
    [`(syn ,_ run ,source
            (occurrence-options ,alias (bindings ,bindings ...)) ,body)
     (define-values (body+ directives) (strip-directives body))
     (values body+
             (cons `(run ,(source-string source) ,alias ,bindings) directives))]
    [`(syn ,_ instantiate ,source ,alias (bindings ,bindings ...) ,body)
     (define-values (body+ directives) (strip-directives body))
     (values body+
             (cons `(instantiate ,(source-string source) ,alias ,bindings)
                   directives))]
    [_ (values ast '())]))

(define (symbol-components who name)
  (unless (symbol? name)
    (error who "expected a namespace path; got ~a" name))
  (qname-components (symbol->qname name)))

(define (prefix-components? left right)
  (and (<= (length left) (length right))
       (equal? left (take right (length left)))))

;; Bindings captured by a new occurrence map a FORMAL path relative to that
;; occurrence to an ACTUAL absolute path resolved in its caller.
(define (normalize-bindings who raw caller-home)
  (define normalized
    (for/list ([binding (in-list raw)])
      (match binding
        [(list formal actual)
         (cons (symbol-components who formal)
               (append caller-home (symbol-components who actual)))]
        [_ (error who "malformed namespace binding: ~a" binding)])))
  (define formals (map car normalized))
  (for* ([left (in-list formals)]
         [right (in-list formals)]
         #:when (and (not (equal? left right))
                     (or (prefix-components? left right)
                         (prefix-components? right left))))
    (error who "overlapping formal namespace bindings are not allowed: ~a and ~a"
           (string-join left ".") (string-join right ".")))
  (unless (= (length formals) (length (remove-duplicates formals equal?)))
    (error who "a formal namespace is bound more than once"))
  normalized)

(define (resolve-program path home lexical-path bindings seen-run)
  (define-values (root requirements)
    (resolve-occurrence path #f home lexical-path bindings #f
                        seen-run (set)))
  (raw-program requirements root))

(define (resolve-occurrence path alias home lexical-path bindings interface?
                            seen-run instance-stack)
  (define entry (fullpath path))
  (when (set-member? instance-stack entry)
    (error 'instantiate
           "lexical module cycle reaches ~a through occurrence ~a"
           entry lexical-path))
  (define seen-inc (mutable-set))
  (define sources '())
  (define children '())
  (define requirements '())
  (define aliases (make-hash))
  (define next-slot 0)
  (define stack+ (set-add instance-stack entry))

  (define (visit source-path module-ast)
    (define canonical (fullpath source-path))
    (unless (set-member? seen-inc canonical)
      (set-add! seen-inc canonical)
      (match module-ast
        [`(module ,_ ,tokens ,ast)
         (define-values (rel-dir _name _dir?) (split-path canonical))
         (define-values (body directives) (strip-directives ast))
         (set! sources
               (append sources (list (raw-source canonical tokens body))))
         (for ([directive (in-list directives)])
           (match directive
             [`(include ,raw)
              (define target (resolve-include raw rel-dir))
              (cond
                [(source-available? target)
                 (visit target (parse-file target))]
                [else
                 (eprintf
                  "warning: include ~s not found (searched ~a and the compiler's lib/); ignoring it -- its declarations will be missing\n"
                  raw (path->string (path->complete-path rel-dir)))])]
             [`(instantiate ,raw ,(? symbol? child-alias) ,raw-bindings)
              (when (hash-has-key? aliases child-alias)
                (error 'instantiate
                       "duplicate instance alias ~a in lexical occurrence ~a"
                       child-alias lexical-path))
              (hash-set! aliases child-alias #t)
              (define target (resolve-include raw rel-dir))
              (unless (source-available? target)
                (error 'instantiate "module source ~s was not found" raw))
              (define slot next-slot)
              (set! next-slot (add1 next-slot))
              (define alias-component (symbol->string child-alias))
              (define inherited
                (for/list ([binding (in-list bindings)]
                           #:when (equal? alias-component (first (car binding))))
                  (cons (rest (car binding)) (cdr binding))))
              (define exact-home
                (for/first ([binding (in-list inherited)]
                            #:when (null? (car binding)))
                  (cdr binding)))
              (define child-home
                (or exact-home (append home (list alias-component))))
              (define child-lexical
                (append lexical-path
                        (list (list slot (symbol->string child-alias)))))
              (define child-bindings
                (append
                 (filter (lambda (binding) (pair? (car binding))) inherited)
                 (normalize-bindings 'instantiate raw-bindings home)))
              ;; The two sources of child bindings (an enclosing binding of a
              ;; nested formal and the child's own `with`) share the same
              ;; no-overlap rule.
              (define child-formals (map car child-bindings))
              (unless (= (length child-formals)
                         (length (remove-duplicates child-formals equal?)))
                (error 'instantiate
                       "a child formal namespace is bound more than once under ~a"
                       child-alias))
              (for* ([left (in-list child-formals)]
                     [right (in-list child-formals)]
                     #:when (and (not (equal? left right))
                                 (or (prefix-components? left right)
                                     (prefix-components? right left))))
                (error 'instantiate
                       "overlapping child formal namespace bindings under ~a: ~a and ~a"
                       child-alias (string-join left ".")
                       (string-join right ".")))
              (define-values (child child-reqs)
                (resolve-occurrence target child-alias child-home child-lexical
                                    child-bindings
                                    (or interface? (and exact-home #t))
                                    seen-run stack+))
              (set! children (append children (list child)))
              (set! requirements (append requirements child-reqs))]
             [`(run ,raw ,run-alias ,raw-bindings)
              (define target (fullpath (normalize-path raw rel-dir)))
              (cond
                [(not (source-available? target))
                 (eprintf "warning: run target ~s not found; ignoring it\n" raw)]
                [(set-member? seen-run target)
                 (error 'run "module ~a transitively runs itself" target)]
                [else
                 (define run-home
                   (if run-alias
                       (append home (list (symbol->string run-alias)))
                       home))
                 (define run-bindings
                   (normalize-bindings 'run raw-bindings home))
                 (set! requirements
                       (append requirements
                               (list
                                (resolve-program
                                 target run-home '() run-bindings
                                 (set-add seen-run target)))))])]))])))

  (visit entry (parse-file entry))
  (values
   (raw-occurrence entry alias home lexical-path bindings interface?
                   sources children)
   requirements))

;; -----------------------------------------------------------------------
;; Type environments: construction and merging.
;;
;; Representation and accessors live in ir-shared.rkt.  The `_enum` struct
;; (one string column) backs enum constants; it is seeded into every module
;; so symbol literals (true/false, declared enum members) always have a home.

(define (type-env-rel x t)
  `(,(hash) ,(hash x t) ,(hash)))

(define (type-env-union x st)
  `(,(hash x st) ,(hash) ,(hash)))

;; Transitively close an alias environment (name -> set of names).
(define (transitive-env env)
  (define env+
    (foldl (lambda (x env+)
             (hash-set env+
                       x
                       (apply set-union
                              (cons (hash-ref env+ x)
                                    (map (lambda (y) (hash-ref env+ y set))
                                         (set->list (hash-ref env+ x)))))))
           env
           (hash-keys env)))
  (if (equal? env env+)
      env+
      (transitive-env env+)))

;; Merge two type environments, checking that overlapping declarations agree.
(define (unify-type-envs e0 e1)
  (define alias-env
    (transitive-env ;; simple pointwise join and then transitive closure
     (foldl (lambda (name env)
              (if (hash-has-key? env name)
                  (hash-set env name (set-union (hash-ref env name)
                                                (hash-ref (type-env-aliases e1) name)))
                  (hash-set env name (hash-ref (type-env-aliases e1) name))))
            (type-env-aliases e0)
            (hash-keys (type-env-aliases e1)))))
  (define env+
    (list
     alias-env
     (foldl (lambda (name env) (hash-set env name (hash-ref (type-env-rels e1) name)))
            (type-env-rels e0)
            (filter (lambda (k) (not (hash-has-key? (type-env-rels e0) k)))
                    (hash-keys (type-env-rels e1))))
     (foldl
      (lambda (name env)
        (if (hash-has-key? env name)
            (let ([myval (hash-ref env name)]
                  [oval (hash-ref (type-env-funs e1) name)])
              (if (equal? myval oval)
                  env
                  (error (format "Function declarations must exactly match: ~a : ~a \n  vs\n  ~a : ~a"
                                 name myval name oval))))
            (hash-set env name (hash-ref (type-env-funs e1) name))))
      (type-env-funs e0)
      (hash-keys (type-env-funs e1)))))
  ;; check that redeclared relations have unifiable field types
  (define (types-unify? t0 t1)
    (or (equal? t0 t1)
        (and (set-member? (hash-ref alias-env t0 set) t1)
             (set-member? (hash-ref alias-env t1 set) t0)
             (equal? (hash-ref alias-env t0 set) (hash-ref alias-env t1 set)))))
  (for ([name (in-list (filter (lambda (k) (hash-has-key? (type-env-rels e0) k))
                               (hash-keys (type-env-rels e1))))])
    (define t0 (hash-ref (type-env-rels env+) name))
    (define t1 (hash-ref (type-env-rels e1) name))
    (match (list t0 t1)
      [`((,struct-or-table ,fields0 ...) (,struct-or-table ,fields1 ...))
       #:when (and (= (length fields0) (length fields1))
                   (andmap types-unify? fields0 fields1))
       (void)]
      [_ (error (format "Type declarations for ~a conflict: ~a vs ~a" name t0 t1))]))
  (for ([x (in-set (set-intersect (list->set (hash-keys (type-env-aliases env+)))
                                  (list->set (hash-keys (type-env-rels env+)))))])
    (error (format "The type ~a appears defined as a union and struct!" x)))
  env+)

;; Builtin declarations seeded into every module's environment: the _enum
;; struct backing enum constants, the native collection/sequence base
;; types, and the runtime type-error machinery (type-system.rkt "Residual
;; dynamic type checks"):
;; a failed residualized check interns a malformed_deduction struct
;; (rule-location string, target relation name, 0-based column, the bad
;; value) and a synthesized rule wraps each one as an (error e) fact.
;; The names list/cons/nil/error/malformed_deduction are reserved (checked
;; in extract-type-env): user redeclarations would otherwise hit the
;; generic conflict check with a baffling message.
;; The rels-env key holding an extern relation's oracle binding entry
;; (oracle <oracle-name> <demand-rel> <ans-rel>): a reserved spelling no
;; user identifier can collide with, so the entry rides the ordinary rel
;; environment (and thus the compile cache key) without new plumbing.
(define (oracle-entry-name name)
  (string->symbol (format "$oracle$~a" name)))

(define base-type-env
  (foldl (lambda (e env) (unify-type-envs env e))
         empty-type-env
         (list (type-env-rel '_enum `(struct str))
               ;; native sequence base type (docs/sequences.md §3.3): cseq
               ;; types the arena's canonical chunked-Merkle sequence words;
               ;; (list T) / [T] columns resolve to it transparently
               ;; (ir-shared.rkt lattice-base-type).  The builtin cons/nil/
               ;; list union is RETIRED (D2) -- brackets now denote native
               ;; sequences -- but the three names stay reserved
               ;; (check-not-reserved! below) to avoid silently changing the
               ;; meaning of programs that declared them.
               (type-env-union 'cseq (set 'cseq))
               ;; bare `list` in a column type = (list any): the untyped
               ;; sequence column older programs use; resolves to cseq like
               ;; every (listof T) entry
               (type-env-rel 'list `(listof any))
               ;; native collection base types (docs/primitives.md M2.3):
               ;; cset/cmap type the arena's canonical collection words
               ;; (one runtime representation, two static disciplines --
               ;; cins/cmem on sets, cput/cget/chas on maps); coll is their
               ;; union for the shared ops (cmerge/cdel/cdiff/csize) and
               ;; the (cmap) empty-collection seed
               (type-env-union 'coll (set 'coll 'cset 'cmap))
               ;; Runtime-error facts (docs/type-errors.md): a fallible prim that
               ;; hits bad data (div/mod by 0, INT_MIN overflow, NaN, toint out of
               ;; range, an `any`-typed type mismatch) records one of these
               ;; error_spec arms in place of the deduction; a per-stratum rule
               ;; wraps each as (error e), delta-driven within the same fixpoint.
               ;; malformed_deduction (the head residual-check failure) is the
               ;; seventh arm.  All arm names are reserved.
               (type-env-rel 'malformed_deduction `(struct str str int any))
               (type-env-rel 'div_by_zero         `(struct str any))
               (type-env-rel 'modulo_by_zero      `(struct str any))
               (type-env-rel 'int_overflow        `(struct str any any))
               (type-env-rel 'nan_result          `(struct str str any))
               (type-env-rel 'toint_range         `(struct str any))
               (type-env-rel 'type_mismatch       `(struct str str any any))
               ;; the two bignum caps (docs/primitives.md §14.4): a result
               ;; exceeding SLOG_MPZ_MAX_BITS (loc, op, operands), and the
               ;; whole-table SLOG_MPZ_TABLE_BYTES trip (loc, op) -- near-
               ;; global by design so a storm dedups to a handful of facts
               (type-env-rel 'mpz_overflow        `(struct str str any any))
               (type-env-rel 'mpz_table_overflow  `(struct str str))
               ;; an extern oracle demand whose payload does not serialize
               ;; (docs/smt.md §12): (reason, the offending formula value);
               ;; the oracle answers unknown alongside recording this
               (type-env-rel 'smt_bad_formula     `(struct str any))
               (type-env-union 'error_spec
                               (set 'error_spec 'malformed_deduction 'div_by_zero
                                    'modulo_by_zero 'int_overflow 'nan_result
                                    'toint_range 'type_mismatch 'mpz_overflow
                                    'mpz_table_overflow 'smt_bad_formula))
               (type-env-rel 'error `(table any)))))

;; -----------------------------------------------------------------------
;; Lattice valuespecs (docs/lattices.md §3).
;;
;; A valuespec expression -- (min int #:floor 0), (max float), (count),
;; (flat T) -- normalizes to the canonical rel-env entry
;; (lattice kind base? (param val) ...).  Returns #f when the expression is
;; not headed by a valuespec constructor (so nested-type flattening can fall
;; through to unions/enums/structs); malformed uses of a constructor error.

(define (parse-valuespec-maybe type-e)
  (define (kw->param-key s)
    (match (symbol->string s)
      ["#:floor" 'floor]
      ["#:ceiling" 'ceiling]
      [_ #f]))
  (define (parse-params kind base kvs)
    (let loop ([kvs kvs] [params '()])
      (match kvs
        ['() (reverse params)]
        [`(,(? symbol? kw) (syn ,_ const ,(? number? v)) ,rest ...)
         (define key (kw->param-key kw))
         (unless key
           (error (format "Unknown lattice parameter ~a in (~a ~a ...)" kw kind base)))
         (unless (case key
                   [(floor) (eq? kind 'min)]
                   [(ceiling) (eq? kind 'max)]
                   [else #f])
           (error (format "Lattice parameter ~a does not apply to (~a ...)" kw kind)))
         (unless (or (and (eq? base 'int) (exact-integer? v))
                     (and (eq? base 'float) (inexact-real? v)))
           (error (format "Lattice parameter ~a value ~a must be a~a ~a literal"
                          kw v (if (eq? base 'int) "n" "") base)))
         (loop rest (cons (list key v) params))]
        [_ (error (format "Malformed lattice parameters ~a in (~a ...)"
                          (strip-prov kvs) kind))])))
  ;; nested valuespecs (a map's value spec) may not carry clamps in v1:
  ;; the composed merge joins leaf values only at key collisions, so an
  ;; entry contributed once would bypass its clamp -- reject rather than
  ;; ship subtly different clamp semantics (docs/primitives.md M2.2)
  (define (reject-nested-clamps! spec ctx)
    (match spec
      [`(lattice map ,_ ,inner) (reject-nested-clamps! `(lattice ,@inner) ctx)]
      [`(lattice ,_ ,_ ,(? pair?) ...+)
       (error (format "Lattice parameters (#:floor/#:ceiling) are not supported inside ~a: ~a"
                      ctx spec))]
      [_ (void)]))
  (match type-e
    [`(syn ,_ ,(and kind (or 'min 'max)) ,(and base (or 'int 'float)) ,kvs ...)
     `(lattice ,kind ,base ,@(parse-params kind base kvs))]
    [`(syn ,_ ,(and kind (or 'min 'max)) ,_ ...)
     (error (format "Lattice (~a T) requires T = int or float: ~a"
                    kind (strip-prov type-e)))]
    [`(syn ,_ count) `(lattice count)]
    [`(syn ,_ flat ,(? symbol? t)) `(lattice flat ,t)]
    [`(syn ,_ flat ,_ ...)
     (error (format "Lattice (flat T) requires a single named type: ~a"
                    (strip-prov type-e)))]
    ;; collection lattices (docs/primitives.md §6.1): (set T) is an
    ;; ascending finite set (join = union); (map K <valuespec>) joins
    ;; pointwise, its value spec joined recursively at colliding keys.
    ;; (map K V) with V a PLAIN type is NOT a valuespec -- it falls through
    ;; to the value-role (mapof K V) column handling (§8.4 role routing).
    [`(syn ,_ set ,(? symbol? t)) `(lattice set ,t)]
    [`(syn ,_ set ,_ ...)
     (error (format "Lattice (set T) requires a single named element type: ~a"
                    (strip-prov type-e)))]
    [`(syn ,_ map ,(? symbol? k) ,vspec-e)
     (match (parse-valuespec-maybe vspec-e)
       [(? list? inner)
        (reject-nested-clamps! inner "a map value position")
        `(lattice map ,k ,(cdr inner))]
       [_ #f])]
    ;; a compound key type with a VALUESPEC value must not silently fall
    ;; through to the value-role (mapof ...) reading -- the user asked for
    ;; a lattice map and would get a plain column
    [`(syn ,_ map ,k ,vspec-e)
     #:when (parse-valuespec-maybe vspec-e)
     (error (format "Lattice (map K <valuespec>) requires a named key type, got: ~a"
                    (strip-prov k)))]
    [_ #f]))

;; Deterministic name for an anonymous inline valuespec: the same spec
;; names the same type, and no gensym (declarations enter the .so cache
;; key, which must be stable run to run).
(define (generated-name-fragment value)
  ;; Numeric clamps may be negative or use an exponent sign.  Keep the
  ;; historical alphanumeric/underscore/dot spelling byte-identical, but
  ;; encode characters which cannot occur in a QName component with the same
  ;; fixed-width scalar escape used by names.rkt's C++ codec.  (A dot remains
  ;; the already-established lowered QName separator; decimal components are
  ;; valid lexer components.)
  (apply
   string-append
   (for/list ([char (in-string (format "~a" value))])
     (cond
       [(regexp-match? #rx"^[A-Za-z0-9_'.]$" (string char)) (string char)]
       [else
        (define hex (number->string (char->integer char) 16))
        (string-append
         "_"
         (make-string (max 0 (- 5 (string-length hex))) #\0)
         hex)]))))

(define (lattice-anon-name spec)
  (string->symbol
   (apply string-append "_lat"
          (map (lambda (part)
                 (format "_~a" (generated-name-fragment part)))
               (flatten (cdr spec))))))

;; -----------------------------------------------------------------------
;; Per-module organization: extract the type environment and the rule set
;; from a module's AST, leaving a (module path toks rules) inside a
;; single-module program.

(define (organize-module module-ast)
  ;; A nested type expression in a declaration field is either a name, an
  ;; anonymous union, a nullary constructor (an enum member), or an inline
  ;; struct declaration; flatten it to a name, collecting declarations.
  (define (flatten-nested-type env type-e)
    (match type-e
      [(? symbol? x) (cons x env)]
      [`(syn ,prov union ,args ...)
       ;; Deterministic name, like lattice-anon-name below: the same member
       ;; list names the same type, and no gensym -- the declaration enters
       ;; the .so cache key (compile.rkt progstr), which must be byte-stable
       ;; run to run (RF1 slice 0: the gensym here was the one pre-cache-key
       ;; mint, churning every stratum stem of a program using an anonymous
       ;; inline union).  Members flatten FIRST, so nested anonymous types
       ;; name deterministically bottom-up.
       (match-define (cons xs env+) (flatten-nested-types env args))
       (define g (string->symbol
                  (apply string-append "_union"
                         (map (lambda (x) (format "_~a" x)) xs))))
       (cons g
             (unify-type-envs env+
                              (extract-type-env
                               `(syn ,prov union (,g ,@xs) (syn ,prov top-level)))))]
      ;; an inline anonymous lattice valuespec: (min int), (flat T), ... --
      ;; declares (deterministically named) a lattice type in place, the same
      ;; sugar unions/structs already have
      [(app parse-valuespec-maybe (? list? spec))
       (define g (lattice-anon-name spec))
       (cons g (unify-type-envs env (type-env-rel g spec)))]
      ;; a parametric list column type: (list T) -- deterministically named,
      ;; recorded as (listof T) preserving the element type verbatim
      ;; (docs/primitives.md §8.4); transparent to the checker, resolving to
      ;; the builtin cseq base type (ir-shared.rkt lattice-base-type;
      ;; docs/sequences.md §3.3).  MUST precede the inline-struct fallback,
      ;; which would otherwise silently declare a unary struct named `list`.
      [`(syn ,prov list ,elem-e)
       (match-define (cons elem env+) (flatten-nested-type env elem-e))
       (define g (string->symbol (format "_list_~a" elem)))
       (cons g (unify-type-envs env+ (type-env-rel g `(listof ,elem))))]
      ;; [T] in type position: sugar for (list T) (docs/sequences.md D11)
      [`(syn ,prov ,(? (lambda (s) (and (symbol? s)
                                        (equal? "[]" (symbol->string s)))))
             ,elem-es ...)
       (unless (= 1 (length elem-es))
         (error (format "A [T] column type takes exactly one element type: ~a"
                        (strip-prov type-e))))
       (flatten-nested-type env `(syn ,prov list ,(car elem-es)))]
      ;; a parametric map VALUE column: (map K V) with V a plain type -- an
      ;; immutable canonical collection word (cnode), transparent to the
      ;; builtin cmap base type with K/V preserved verbatim (§8.4).
      ;; Lattice-role maps -- (map K <valuespec>) -- were claimed by the
      ;; valuespec hook above; (set T) is always lattice-role (an ascending
      ;; set), so a value-role set column is declared as plain `cset`.
      [`(syn ,prov map ,key-e ,val-e)
       (match-define (cons key env+) (flatten-nested-type env key-e))
       (match-define (cons val env++) (flatten-nested-type env+ val-e))
       (define g (string->symbol (format "_map_~a_~a" key val)))
       (cons g (unify-type-envs env++ (type-env-rel g `(mapof ,key ,val))))]
      [`(syn ,prov ,name)
       (cons name
             (extract-type-env `(syn ,prov enum (syn ,prov ,name) (syn ,prov top-level))
                               env))]
      [`(syn ,prov ,structname ,args ...)
       (cons structname
             (extract-type-env `(syn ,prov struct ,type-e (syn ,prov top-level)) env))]))

  (define (flatten-nested-types env args)
    (foldr (lambda (arg acc)
             (match-define (cons xs env+) acc)
             (match-define (cons x env++) (flatten-nested-type env+ arg))
             (cons (cons x xs) env++))
           (cons '() env)
           args))

  ;; list/cons/nil stay reserved even though the builtin cons list is
  ;; retired (D2, docs/sequences.md §9): a user declaration would silently
  ;; change the meaning of older programs.  Reject redeclarations here with
  ;; a message that names the feature, before the generic conflict check
  ;; produces a baffling one.
  (define (check-not-reserved! name)
    (when (collection-builtin? name)
      (error (format "The name ~a is reserved (bracket syntax [x y ...] denotes native sequences, docs/sequences.md); remove the declaration" name)))
    (when (memq name '(cset cmap coll cseq))
      (error (format "The name ~a is a builtin collection/sequence base type (docs/primitives.md M2.3, docs/sequences.md); remove the declaration" name)))
    (when (memq name '(error error_spec malformed_deduction div_by_zero
                       modulo_by_zero int_overflow nan_result toint_range
                       type_mismatch mpz_overflow mpz_table_overflow
                       smt_bad_formula))
      (error (format "The name ~a is reserved for the runtime type-error machinery ((error (error_spec ...)) facts); remove the declaration" name))))

  (define (extract-type-env ast [env base-type-env])
    (match ast
      [`(syn ,_ ,(and struct-or-table (or 'table 'struct))
             (syn ,_ ,(? symbol? name) ,args ...) ,body)
       (check-not-reserved! name)
       (when (null? args)
         (error (format "Table or struct ~a must have at least one column" name)))
       (match-define (cons xs env+) (flatten-nested-types env args))
       (extract-type-env body
                         (unify-type-envs env+ (type-env-rel name `(,struct-or-table ,@xs))))]

      [`(syn ,_ union (syn ,_ ,(? symbol? name) ,args ...) ,body)
       (check-not-reserved! name)
       (match-define (cons xs env+) (flatten-nested-types env args))
       (extract-type-env body
                         (unify-type-envs env+ (type-env-union name (list->set (cons name xs)))))]

      ;; lattice (name valuespec): declare a lattice value TYPE; relations
      ;; with a lattice-typed (last) column are maps automatically
      [`(syn ,_ lattice (syn ,_ ,(? symbol? name) ,spec-e) ,body)
       (check-not-reserved! name)
       (define spec (parse-valuespec-maybe spec-e))
       (unless spec
         (error (format "Malformed lattice valuespec for ~a: expected (min int #:floor n), (max T #:ceiling n), (count), (flat T), (set T), or (map K <valuespec>); got ~a"
                        name (strip-prov spec-e))))
       (extract-type-env body (unify-type-envs env (type-env-rel name spec)))]
      [`(syn ,_ lattice ,rest ...)
       (error (format "Malformed lattice declaration: expected lattice (name valuespec), got ~a"
                      (strip-prov `(lattice ,@(drop-right rest 1)))))]

      ;; demand (f in ...) out ...: declare the backing relations -- the
      ;; demand struct itself and its answer table, keyed by the demand
      [`(syn ,_ demand (syn ,_ ,(? symbol? name) ,args ...) ,ans ... ,body)
       (check-not-reserved! name)
       (when (null? args)
         (error (format "Demand relation ~a must have at least one input column" name)))
       (when (null? ans)
         (error (format "Demand relation ~a must declare at least one answer column" name)))
       (match-define (cons xs env+) (flatten-nested-types env args))
       (match-define (cons ys env++) (flatten-nested-types env+ ans))
       (extract-type-env
        body
        (unify-type-envs
         env++
         (unify-type-envs (type-env-rel name `(struct ,@xs))
                          (type-env-rel (demand-ans-name name)
                                        `(table ,name ,@ys)))))]
      [`(syn ,_ demand ,rest ...)
       (error (format "Malformed demand declaration: expected demand (name in-type ...) answer-type ..., got ~a"
                      (strip-prov `(demand ,@(drop-right rest 1)))))]

      ;; extern <oracle> (f in-type) int: an oracle-backed demand relation
      ;; (docs/smt.md).  Declares exactly what `demand` would -- the interned
      ;; demand struct plus its answer table -- and additionally records an
      ;; (oracle <name> <f> <f_ans>) binding entry that codegen turns into
      ;; the daemon-side dispatch/harvest task registration for every stratum
      ;; writing the demand struct.  The oracle owns the answer table: rules
      ;; answering it are rejected (check-extern-rules below).  v1 keeps the
      ;; daemon side trivially generic: one input column, one `int` answer
      ;; (the oracle's code word); lib rules translate codes to enums.
      [`(syn ,_ extern ,(? symbol? oname) (syn ,_ ,(? symbol? name) ,args ...) ,ans ... ,body)
       (check-not-reserved! name)
       (unless (= 1 (length args))
         (error (format "Extern relation ~a must have exactly one input column (v1)" name)))
       (unless (and (= 1 (length ans)) (memq (car ans) '(int cmap cset)))
         (error (format "Extern relation ~a must declare exactly one answer column of type int, cmap, or cset (the oracle's code word or a materialized collection; lib rules translate -- see lib/smt.slog)" name)))
       (match-define (cons xs env+) (flatten-nested-types env args))
       (extract-type-env
        body
        (unify-type-envs
         env+
         (unify-type-envs
          (type-env-rel name `(struct ,@xs))
          (unify-type-envs
           (type-env-rel (demand-ans-name name) `(table ,name ,(car ans)))
           (type-env-rel (oracle-entry-name name)
                         `(oracle ,oname ,name ,(demand-ans-name name)))))))]
      [`(syn ,_ extern ,rest ...)
       (error (format "Malformed extern declaration: expected extern <oracle> (name in-type) int, got ~a"
                      (strip-prov `(extern ,@(drop-right rest 1)))))]

      [`(syn ,_ enum (syn ,_ ,name ,(? symbol? names) ...) ,body)
       ;; A bare nullary constructor (`enum (halt)`, via a union member) is
       ;; itself a constant.  A named enumeration (`enum (color red green
       ;; blue)`) additionally makes the name a type over its member
       ;; constants -- an alias set, exactly like a union of nullary members
       ;; -- so columns can be declared with the enum's name.
       (check-not-reserved! name)
       (for-each check-not-reserved! names)
       (define members (if (null? names) (list name) names))
       (define env+
         (foldl unify-type-envs
                env
                (map (lambda (m) (type-env-rel m `(enum ,m))) members)))
       (extract-type-env body
                         (if (null? names)
                             env+
                             (unify-type-envs
                              env+
                              (type-env-union name (list->set (cons name members))))))]

      [`(syn ,_ top-level) env]

      ;; skip over rules, defs, etc
      [_ (extract-type-env (last ast) env)]))

  (define (extract-rules ast [rules (set)])
    (match ast
      [`(syn ,_ top-level) rules]

      [`(syn ,prov rule ,body0 ... --> ,body1 ... ,topbody)
       (extract-rules topbody (set-add rules `(syn ,prov rule ,@body0 --> ,@body1)))]

      [`(syn ,prov rule ,body0 ... <-- ,body1 ... ,topbody)
       (extract-rules topbody (set-add rules `(syn ,prov rule ,@body1 --> ,@body0)))]

      ;; skip over defs, funs, etc
      [_ (extract-rules (last ast) rules)]))

  ;; demand-moded relations: name -> (cons input-arity answer-arity),
  ;; consumed program-wide by the demand transform after env merging
  (define (extract-demands ast [demands (hash)])
    (match ast
      [`(syn ,_ top-level) demands]
      [`(syn ,_ demand (syn ,_ ,(? symbol? name) ,args ...) ,ans ... ,body)
       (define entry (cons (length args) (length ans)))
       (when (and (hash-has-key? demands name)
                  (not (equal? entry (hash-ref demands name))))
         (error (format "Demand relation ~a is declared twice with different signatures" name)))
       (extract-demands body (hash-set demands name entry))]
      ;; an extern relation is demand-moded exactly like `demand`: callers
      ;; desugar through the same transform, only the answerer differs
      [`(syn ,_ extern ,(? symbol? _) (syn ,_ ,(? symbol? name) ,args ...) ,ans ... ,body)
       (define entry (cons (length args) (length ans)))
       (when (and (hash-has-key? demands name)
                  (not (equal? entry (hash-ref demands name))))
         (error (format "Demand relation ~a is declared twice with different signatures" name)))
       (extract-demands body (hash-set demands name entry))]
      [_ (extract-demands (last ast) demands)]))

  (match module-ast
    [`(module ,path ,toks
        ,ast)
     `(program ()
               ,(set `(module ,path ,toks
                        ,(extract-type-env ast)
                        ,(extract-demands ast)
                        ,(extract-rules ast))))]))

;; -----------------------------------------------------------------------
;; N1 qualification.

(define builtin-type-names
  (set-union (list->set (hash-keys (type-env-aliases base-type-env)))
             (list->set (hash-keys (type-env-rels base-type-env)))))

(define primitive-type-names
  (set 'any 'int 'float 'str 'cset 'cmap '$count))

(define special-operator-names
  (set '= '/= '== '< '<= '> '>= '& (string->symbol "|")
       'let 'const 'rule '--> '<-- '~ 'lambda
       (string->symbol "[]") (string->symbol "{}") '...))

(define (internal-symbol? name)
  (and (symbol? name)
       (string-prefix? (symbol->string name) "$")))

(define (resolve-components home bindings components)
  (define selected
    (for/first ([binding
                 (in-list
                  (sort bindings > #:key (lambda (binding)
                                           (length (car binding)))))]
                #:when (prefix-components? (car binding) components))
      binding))
  (if selected
      (append (cdr selected)
              (drop components (length (car selected))))
      (append home components)))

(define (resolve-public-name home bindings name)
  (qname->symbol
   (qname (resolve-components home bindings
                              (qname-components (symbol->qname name))))))

(define (qualify-type-name home bindings name)
  (cond
    [(or (set-member? primitive-type-names name)
         (set-member? builtin-type-names name))
     name]
    [(internal-symbol? name) (internal-name-at-home home name)]
    [else (resolve-public-name home bindings name)]))

(define (qualify-lattice-datum home bindings value)
  (match value
    [`(lattice ,kind ,arguments ...)
     `(lattice ,kind
               ,@(for/list ([argument (in-list arguments)])
                   (match argument
                     [(? symbol? name)
                      (if (string-prefix? (symbol->string name) "#:")
                          name
                          (qualify-type-name home bindings name))]
                     [`(,parameter ,literal)
                      #:when (memq parameter '(floor ceiling))
                      argument]
                     [(? list?)
                      (qualify-lattice-datum home bindings argument)]
                     [_ argument])))]
    [_ value]))

(define (qualify-rel-declaration home bindings declaration)
  (match declaration
    [`(,(and kind (or 'table 'struct)) ,fields ...)
     `(,kind ,@(map (lambda (name)
                      (qualify-type-name home bindings name))
                    fields))]
    [`(enum ,name)
     `(enum ,(qualify-type-name home bindings name))]
    [`(lattice ,_ ...)
     (qualify-lattice-datum home bindings declaration)]
    [`(listof ,name)
     `(listof ,(qualify-type-name home bindings name))]
    [`(mapof ,key ,value)
     `(mapof ,(qualify-type-name home bindings key)
             ,(qualify-type-name home bindings value))]
    [`(oracle ,oracle ,demand-rel ,answer-rel)
     `(oracle ,oracle
              ,(resolve-public-name home bindings demand-rel)
              ,(resolve-public-name home bindings answer-rel))]
    [other other]))

(define (qualify-type-environment env home bindings)
  (define aliases
    (for/fold ([out (hash)])
              ([(name members) (in-hash (type-env-aliases env))])
      (cond
        [(set-member? builtin-type-names name)
         (hash-set out name members)]
        [else
         (hash-set
          out
          (resolve-public-name home bindings name)
          (for/set ([member (in-set members)])
            (qualify-type-name home bindings member)))])))
  (define rels
    (for/fold ([out (hash)])
              ([(name declaration) (in-hash (type-env-rels env))])
      (cond
        [(and (set-member? builtin-type-names name)
              (equal? declaration
                      (hash-ref (type-env-rels base-type-env) name #f)))
         (hash-set out name declaration)]
        [else
         (define name+
           (if (internal-symbol? name)
               (internal-name-at-home home name)
               (resolve-public-name home bindings name)))
         (hash-set out name+
                   (qualify-rel-declaration home bindings declaration))])))
  (list aliases rels (type-env-funs env)))

(define (occurrence-source-label path lexical-path)
  (cond
    [(null? lexical-path) path]
    [else
     (define-values (dir file _dir?) (split-path path))
     (define occurrence
       (string-join
        (for/list ([step (in-list lexical-path)])
          (format "~a#~a" (second step) (first step)))
        "."))
     (path->string
      (build-path (if (path? dir) dir (current-directory))
                  (format "~a@~a" occurrence file)))]))

(define (rewrite-token-source token label)
  (match token
    [`(token ,tag (pos ,_ ,sl ,sc ,el ,ec) ,text)
     `(token ,tag (pos ,label ,sl ,sc ,el ,ec) ,text)]
    [_ token]))

(define (rewrite-provenance provenance label)
  (match provenance
    [`(prov ,left ,right)
     `(prov ,(rewrite-token-source left label)
            ,(rewrite-token-source right label))]
    [_ provenance]))

(define (qualify-rule rule home bindings local-names source-label)
  (define (operator-name name)
    (cond
      [(internal-symbol? name) (internal-name-at-home home name)]
      [(or (set-member? local-names name)
           ;; `qname-symbol?` only asks whether a symbol contains a dot.  The
           ;; sequence splice token `...` does, but it is syntax, not a
           ;; qualified name -- routing it into name resolution fails there
           ;; because "" is not a valid component.  Every other special
           ;; operator is dot-free, so this exclusion is exactly `...`.
           (and (qname-symbol? name)
                (not (set-member? special-operator-names name))))
       (resolve-public-name home bindings name)]
      [(or (set-member? special-operator-names name)
           (hash-has-key? (type-env-funs base-type-env) name)
           (set-member? builtin-type-names name))
       name]
      [else name]))
  (let walk ([form rule])
    (match form
      [`(syn ,provenance const ,value)
       `(syn ,(rewrite-provenance provenance source-label) const ,value)]
      [`(syn ,provenance ,(? symbol? head) ,arguments ...)
       `(syn ,(rewrite-provenance provenance source-label)
             ,(operator-name head)
             ,@(map walk arguments))]
      [`(syn ,provenance ,items ...)
       `(syn ,(rewrite-provenance provenance source-label)
             ,@(map walk items))]
      [(? list?) (map walk form)]
      [_ form])))

(define (organize-raw-source source)
  (match-define
    `(program ()
              ,(app set->list
                    (list `(module ,path ,tokens ,env ,demands ,rules))))
    (organize-module
     `(module ,(raw-source-path source)
              ,(raw-source-tokens source)
              ,(raw-source-ast source))))
  (list path tokens env demands rules))

(define (qualify-occurrence occurrence)
  (define organized
    (map organize-raw-source (raw-occurrence-sources occurrence)))
  (define local-names
    (for*/set ([source (in-list organized)]
               [name (in-list
                      (append
                       (hash-keys (type-env-aliases (third source)))
                       (hash-keys (type-env-rels (third source)))))]
               #:unless (set-member? builtin-type-names name))
      name))
  (define aliases
    (for/set ([child (in-list (raw-occurrence-children occurrence))])
      (raw-occurrence-alias child)))
  (for ([alias (in-set aliases)])
    (when (set-member? local-names alias)
      (error 'instantiate
             "instance alias ~a collides with a declaration in ~a"
             alias (raw-occurrence-entry-path occurrence))))
  (for ([binding (in-list (raw-occurrence-bindings occurrence))])
    (unless (and (pair? (car binding))
                 (set-member? aliases
                              (string->symbol (first (car binding)))))
      (error 'instantiate
             "formal namespace ~a is not an explicitly instantiated child of ~a"
             (string-join (car binding) ".")
             (raw-occurrence-entry-path occurrence))))
  (define home (raw-occurrence-home occurrence))
  (define bindings (raw-occurrence-bindings occurrence))
  (define modules
    (for/list ([source (in-list organized)])
      (match-define (list path tokens env demands rules) source)
      (define label
        (occurrence-source-label path
                                 (raw-occurrence-lexical-path occurrence)))
      (qualified-module
       (module-ir
        path tokens
        (for/set ([rule (in-set rules)])
          (qualify-rule rule home bindings local-names label))
        home
        (raw-occurrence-lexical-path occurrence))
       (qualify-type-environment env home bindings)
       (for/hash ([(name signature) (in-hash demands)])
         (values (resolve-public-name home bindings name) signature))
       (raw-occurrence-interface? occurrence))))
  (define child-results
    (for/list ([child (in-list (raw-occurrence-children occurrence))])
      (call-with-values (lambda () (qualify-occurrence child)) list)))
  (define child-modules
    (append-map first child-results))
  (define child-trees
    (map second child-results))
  (values
   (append modules child-modules)
   (module-occurrence
    (raw-occurrence-entry-path occurrence)
    home
    (raw-occurrence-lexical-path occurrence)
    (for/list ([binding (in-list bindings)])
      (list (car binding) (cdr binding)))
    (map raw-source-path (raw-occurrence-sources occurrence))
    child-trees)))

;; -----------------------------------------------------------------------
;; Lifting and linearization.

(struct lifted-program
  (requirements type-env modules decomps occurrence-tree)
  #:transparent)

;; The oracle owns an extern relation's answers: reject any rule that would
;; answer it in-language -- a full-arity head occurrence of the demand
;; relation (the demand transform would turn it into an answer rule) or a
;; direct head on its answer table.  Bare input-arity head occurrences (asks)
;; stay legal.  Runs over the merged view, pre-desugar.
(define (check-extern-rules type-env mods)
  (define externs   ; demand-rel -> (cons full-arity ans-rel)
    (for/hash ([(k decl) (in-hash (type-env-rels type-env))]
               #:when (and (pair? decl) (eq? 'oracle (car decl))))
      (match-define `(oracle ,_ ,drel ,arel) decl)
      (define in-arity
        (match (hash-ref (type-env-rels type-env) drel)
          [`(struct ,ts ...) (length ts)]))
      (values drel (cons (add1 in-arity) arel))))
  (unless (hash-empty? externs)
    (for* ([m (in-list mods)]
           [rule (in-set (module-ir-rules m))])
      (match rule
        [`(syn ,_ rule ,bodys ... --> ,heads ...)
         (for ([h (in-list heads)])
           (match h
             [`(syn ,_ ,(? symbol? name) ,args ...)
              (define ext (hash-ref externs name #f))
              (when (and ext (= (length args) (car ext)))
                (error (format "Extern relation ~a is answered by its oracle; remove the answering rule ~a"
                               name (strip-prov rule))))
              (for ([(drel ext) (in-hash externs)])
                (when (eq? name (cdr ext))
                  (error (format "Answer table ~a of extern relation ~a is oracle-owned; remove the rule ~a"
                                 name drel (strip-prov rule)))))]
             [_ (void)]))]
        [_ (void)]))))

;; Merge two demand registries, requiring agreeing signatures.
(define (unify-demands d0 d1)
  (for/fold ([d d0]) ([(name entry) (in-hash d1)])
    (when (and (hash-has-key? d name) (not (equal? entry (hash-ref d name))))
      (error (format "Demand relation ~a is declared twice with different signatures" name)))
    (hash-set d name entry)))

;; Directional compatibility for a namespace interface.  `any` is a wildcard
;; only on the formal side of an explicit binding; it is deliberately not
;; added to ordinary type-env unification, where overlapping declarations
;; continue to require equality.
(define (interface-datum-compatible? formal actual)
  (cond
    [(eq? formal 'any) #t]
    [(equal? formal actual) #t]
    [(and (list? formal)
          (list? actual)
          (= (length formal) (length actual)))
     (andmap interface-datum-compatible? formal actual)]
    [else #f]))

(define (unify-interface-type-env actual formal)
  (define aliases
    (for/fold ([out (type-env-aliases actual)])
              ([(name members) (in-hash (type-env-aliases formal))])
      (hash-update out name
                   (lambda (actual-members)
                     (set-union actual-members members))
                   members)))
  (define rels
    (for/fold ([out (type-env-rels actual)])
              ([(name declaration) (in-hash (type-env-rels formal))])
      (cond
        [(not (hash-has-key? out name))
         (hash-set out name declaration)]
        [else
         (define actual-declaration (hash-ref out name))
         (unless (interface-datum-compatible? declaration
                                               actual-declaration)
           (error 'instantiate
                  (string-append
                   "bound namespace declaration ~a is incompatible:\n"
                   "  required ~a\n  actual   ~a")
                  name declaration actual-declaration))
         out])))
  ;; User-defined primitive functions are not a module feature today, but
  ;; retain the ordinary exact check if that changes.
  (define funs
    (for/fold ([out (type-env-funs actual)])
              ([(name declaration) (in-hash (type-env-funs formal))])
      (when (and (hash-has-key? out name)
                 (not (equal? declaration (hash-ref out name))))
        (error 'instantiate
               "bound function declaration ~a is incompatible" name))
      (hash-set out name declaration)))
  (list (transitive-env aliases) rels funs))

(define (binding-actual-prefixes occurrence)
  (append
   (map cdr (raw-occurrence-bindings occurrence))
   (append-map binding-actual-prefixes
               (raw-occurrence-children occurrence))))

(define (input-binding-type-env occurrence)
  (define input (current-input-catalog))
  (define prefixes
    (remove-duplicates (binding-actual-prefixes occurrence) equal?))
  (cond
    [(or (not input) (null? prefixes)) empty-type-env]
    [else
     (define full (catalog->type-env input))
     (define aliases (type-env-aliases full))
     (define rels (type-env-rels full))
     (define initial
       (for/set ([name (in-list
                        (append (hash-keys aliases) (hash-keys rels)))]
                 #:when
                 (for/or ([prefix (in-list prefixes)])
                   (prefix-components?
                    prefix
                    (qname-components (symbol->qname name)))))
         name))
     ;; Pull in named field/member dependencies even when they live outside
     ;; the selected actual subtree.  This is a schema closure, not a blanket
     ;; import of the input database.
     (define selected
       (let loop ([names initial])
         (define names+
           (for/fold ([out names]) ([name (in-set names)])
             (define values
               (append
                (set->list (hash-ref aliases name (set)))
                (let walk ([value (hash-ref rels name '())])
                  (cond
                    [(symbol? value) (list value)]
                    [(list? value) (append-map walk value)]
                    [else '()]))))
             (for/fold ([out out]) ([dependency (in-list values)]
                                    #:when
                                    (or (hash-has-key? aliases dependency)
                                        (hash-has-key? rels dependency)))
               (set-add out dependency))))
         (if (equal? names names+) names (loop names+))))
     (list
      (for/hash ([(name members) (in-hash aliases)]
                 #:when (set-member? selected name))
        (values name members))
      (for/hash ([(name declaration) (in-hash rels)]
                 #:when (set-member? selected name))
        (values name declaration))
      (type-env-funs full))]))

;; Merge each program's per-module type environments (and demand
;; registries) into one program-level environment, then desugar every
;; module's demand-moded rules against the merged view -- a rule may use a
;; judgment declared in another included module (recursively over the run
;; tree).  The transform can synthesize declarations of its own (closure
;; structs and enum constants from lambdas, the `clo` union, and the
;; applyN backing relations); those merge into the type env here, with
;; the usual conflict checking.
(define (lift-type-envs p)
  (match-define (raw-program reqs root) p)
  (define-values (qualified occurrence-tree)
    (qualify-occurrence root))
  (define ordinary
    (filter (lambda (mod) (not (qualified-module-interface? mod)))
            qualified))
  (define interfaces
    (filter qualified-module-interface? qualified))
  (define seeded-type-env
    (unify-type-envs (input-binding-type-env root) base-type-env))
  (define type-env-ordinary
    (for/fold ([env seeded-type-env]) ([mod (in-list ordinary)])
      (unify-type-envs (qualified-module-type-env mod) env)))
  (define type-env
    (for/fold ([env type-env-ordinary]) ([mod (in-list interfaces)])
      (unify-interface-type-env env (qualified-module-type-env mod))))
  (define demands
    (for/fold ([out (hash)]) ([mod (in-list qualified)])
      (unify-demands out (qualified-module-demands mod))))
  (define mods+
    (map qualified-module-ir qualified))
     ;; Bracket list literals desugar BEFORE the demand transform: the
     ;; transform or-splits rule bodies (demand.rkt), and a not-yet-
     ;; reassociated tail pipe inside ([] ...) would be silently split
     ;; into wrong alternatives (collections.rkt has the full story).
     ;; Brace literals route by target: programs including the rules-based
     ;; Patricia libraries (pset/pmap declared) keep the lib lowering
     ;; (st_ins/mp_put); otherwise braces lower to the native collection
     ;; prims (cmap/cins/cput) -- docs/primitives.md M2.3.
     (define lib-collections?
       (or (hash-has-key? (type-env-aliases type-env) 'pset)
           (hash-has-key? (type-env-aliases type-env) 'pmap)
           (hash-has-key? (type-env-rels type-env) 'pset)
           (hash-has-key? (type-env-rels type-env) 'pmap)))
     (define mods-collections
       (desugar-collections-mods mods+ lib-collections? demands))
     ;; oracle-owned answer relations must not be answered by rules; checked
     ;; pre-desugar so the message names the offending SOURCE rule
     (check-extern-rules type-env mods-collections)
     (define-values (mods-desugared synth-rels clo-members)
       (desugar-demand-program mods-collections demands type-env))
     (define type-env+
       (let* ([env (foldl (lambda (name env)
                            (unify-type-envs
                             env
                             (type-env-rel name (hash-ref synth-rels name))))
                          type-env
                          (sort (hash-keys synth-rels) symbol<?))])
         (for/fold ([env env])
                   ([(clo-name members) (in-hash clo-members)])
           (unify-type-envs
            env
            (type-env-union clo-name (set-add members clo-name))))))
     (define mods++
       (for/set ([m (in-list mods-desugared)])
         m))
     ;; M2.4 need-driven decomposition synthesis (header comment above):
     ;; scan the desugared rules for undeclared `<R>_has`/`<R>_at` names over
     ;; a matching collection-lattice base and synthesize their declarations.
     (define-values (type-env++ decomp-env)
       (synthesize-decompositions mods++ type-env+))
  (lifted-program (map lift-type-envs reqs)
                  type-env++ mods++ decomp-env occurrence-tree))

;; Every operator-position name of every rule (relation atoms, struct
;; patterns, prim calls -- conservative: an undeclared non-relation name is a
;; type error anyway, so over-collection cannot mis-fire the synthesis).
(define (rules-used-names mods)
  (for*/fold ([names (set)])
             ([m (in-set mods)] [rule (in-set (module-ir-rules m))])
    (let walk ([e rule] [names names])
      (match e
        [`(syn ,_ ,(? symbol? h) ,rest ...)
         (foldl walk (set-add names h) rest)]
        [(? list?) (foldl walk names e)]
        [_ names]))))

;; The synthesis itself: for each used-but-undeclared `<R>_has` (`<R>_at`)
;; whose base R is a set-kind (map-kind) collection-lattice table, declare
;;   R_has : (table k̄ elem)            -- a PLAIN monotone relation
;;   R_at  : (table k̄ key <childlat>)  -- itself a lattice table whose value
;;                                        column carries the map's child
;;                                        valuespec (pointwise by construction;
;;                                        nested maps compose)
;; and record derived -> (base kind).  Names are processed sorted for
;; deterministic env construction; the child lattice type reuses the
;; deterministic anon-valuespec naming (lattice-anon-name), unifying with an
;; identical inline declaration if the program already has one.
(define (synthesize-decompositions mods type-env)
  (define used (rules-used-names mods))
  (for/fold ([env type-env] [denv (hash)])
            ([name (in-list (sort (set->list used) symbol<?))])
    (define m
      (and (not (hash-has-key? (type-env-rels type-env) name))
           (regexp-match #px"^(.+)_(has|at)$" (symbol->string name))))
    (define base (and m (string->symbol (second m))))
    (define spec (and base (rel-lattice-spec (type-env-rels type-env) base)))
    (match* ((and m (third m)) spec)
      [("has" `(lattice set ,t))
       (match-define `(table ,ts ...) (hash-ref (type-env-rels type-env) base))
       (values (unify-type-envs env (type-env-rel name `(table ,@(drop-right ts 1) ,t)))
               (hash-set denv name (list base 'set)))]
      [("at" `(lattice map ,k ,inner))
       (match-define `(table ,ts ...) (hash-ref (type-env-rels type-env) base))
       (define g (lattice-anon-name `(lattice ,@inner)))
       (define env+g
         (if (hash-has-key? (type-env-rels env) g)
             env
             (unify-type-envs env (type-env-rel g `(lattice ,@inner)))))
       (values (unify-type-envs env+g (type-env-rel name `(table ,@(drop-right ts 1) ,k ,g)))
               (hash-set denv name (list base 'map)))]
      [(_ _) (values env denv)])))

;; Dependencies-first (post-order) linearization of the run tree.
(define (linearize-programs prog)
  (foldr append
         (list
          (program-ir (lifted-program-type-env prog)
                      (lifted-program-modules prog)
                      (hash)
                      (lifted-program-decomps prog)
                      (lifted-program-occurrence-tree prog)))
         (map linearize-programs (lifted-program-requirements prog))))

;; -----------------------------------------------------------------------
;; Manifests: each program is compiled against the manifest of relations
;; already in the database at that point (input DB plus every earlier
;; program's declarations), and must not contradict it.

(define (update-manifest type-env manifest)
  ;; The flat manifest is now only the current code-generation ABI
  ;; projection.  Rich declaration normalization has one authority in
  ;; catalog.rkt; the session boundary planner consumes the same delta.
  ;; Today's `$...` generated relations remain an explicitly execution-only
  ;; appendix until N1 replaces that legacy spelling with internal IDs.
  (merge-legacy-manifest
   manifest
   (type-env->legacy-manifest type-env)))

(define (thread-manifests prog-lst manifest)
  (match prog-lst
    [(cons (? program-ir? program) more)
     (define type-env (program-ir-type-env program))
     (cons (struct-copy program-ir program [manifest manifest])
           (thread-manifests more (update-manifest type-env manifest)))]
    ['() '()]))
