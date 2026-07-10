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

(provide load-program-list)

(require racket/runtime-path)
(require "parser.rkt")
(require "utils.rkt")
(require "ir-shared.rkt")
(require "demand.rkt")
(require "collections.rkt")

;; -----------------------------------------------------------------------
;; Entry point: path -> (listof program?), dependencies first, manifests
;; threaded.  `input-manifest` describes the relations of the input DB
;; (name -> (rel name arity) | (struct name arity)).

(define (load-program-list path input-manifest)
  (define tree (lift-type-envs (load-program-tree path)))
  (thread-manifests (linearize-programs tree) input-manifest))

;; -----------------------------------------------------------------------
;; Include/run resolution.
;;
;; A program tree is (program (subtree ...) mods): its `run` prerequisites
;; and its own set of modules (this file plus everything included).

(define (load-program-tree path [seen-run (set)] [seen-inc (set)])
  (include-module path (parse-file path) seen-run seen-inc))

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

(define (program-merge-run p0 p1)
  (match p0
    [`(program ,reqs ,mods) `(program (,@reqs ,p1) ,mods)]))

(define (program-merge-include p0 p1)
  (match (list p0 p1)
    [`((program ,reqs0 ,mods0) (program ,reqs1 ,mods1))
     `(program (,@reqs0 ,@reqs1) ,(set-union mods0 mods1))]))

(define (include-module path module-ast [seen-run (set)] [seen-inc (set)])
  (let* ([path (fullpath path)]
         [seen-run (set-add seen-run path)]
         [seen-inc (set-add seen-inc path)])
    (match module-ast
      [`(module ,path+ ,toks
          ,ast)
       (define-values (rel-dir _0 _1) (split-path path))
       ;; Peel the leading include/run directives off the module body.
       (define (strip-directives ast)
         (match ast
           [`(syn ,_ include (syn ,_ const ,inc-path) ,body)
            (match-define (list ast+ run-paths inc-paths) (strip-directives body))
            (list ast+ run-paths (set-add inc-paths inc-path))]
           [`(syn ,_ run (syn ,_ const ,run-path) ,body)
            (match-define (list ast+ run-paths inc-paths) (strip-directives body))
            (list ast+ (cons run-path run-paths) inc-paths)]
           [_ (list ast '() (set))]))
       (match-define (list ast-sans-directives run-paths inc-paths)
         (strip-directives ast))
       ;; Resolve each include to its on-disk (or source-override, or lib/)
       ;; path.  A target that resolves to nothing is dropped -- but WARN first
       ;; (docs/build-issues-notes.md §1): a silently-dropped include makes its
       ;; declarations vanish and surfaces later as a baffling cascade of
       ;; "relation/struct X is not defined" for things you clearly included.
       (define resolved-incs
         (for/list ([raw (in-list (set->list inc-paths))])
           (cons raw (resolve-include raw rel-dir))))
       (for ([ri (in-list resolved-incs)])
         (unless (source-available? (cdr ri))
           (eprintf "warning: include ~s not found (searched ~a and the compiler's lib/); ignoring it -- its declarations will be missing\n"
                    (car ri) (path->string (path->complete-path rel-dir)))))
       (define this-prog
         (foldl
          (lambda (inc-path prog)
            (program-merge-include prog (load-program-tree inc-path seen-run seen-inc)))
          (organize-module `(module ,path ,toks
                              ,ast-sans-directives))
          (filter (lambda (p) (and (source-available? p) (not (set-member? seen-inc p))))
                  (map cdr resolved-incs))))
       ;; Same for `run` targets (no lib/ fallback): warn on a dropped one.
       (define resolved-runs
         (for/list ([raw (in-list run-paths)])
           (cons raw (normalize-path raw rel-dir))))
       (for ([rr (in-list resolved-runs)])
         (unless (source-available? (cdr rr))
           (eprintf "warning: run target ~s not found; ignoring it\n" (car rr))))
       (foldl (lambda (run-path prog)
                (define rp (fullpath run-path))
                (when (set-member? seen-run rp)
                  (error (format "Module ~a transitively runs itself" rp)))
                ;; a fresh include-set: each program's includes are its own
                (program-merge-run prog (load-program-tree rp seen-run (set))))
              this-prog
              (filter source-available? (map cdr resolved-runs)))])))

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
(define (lattice-anon-name spec)
  (string->symbol
   (apply string-append "_lat"
          (map (lambda (part) (format "_~a" part))
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
       (define g (gensymb 'union))
       (match-define (cons xs env+) (flatten-nested-types env args))
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
;; Lifting and linearization.

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
           [rule (in-set (third m))])
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

;; Merge each program's per-module type environments (and demand
;; registries) into one program-level environment, then desugar every
;; module's demand-moded rules against the merged view -- a rule may use a
;; judgment declared in another included module (recursively over the run
;; tree).  The transform can synthesize declarations of its own (closure
;; structs and enum constants from lambdas, the `clo` union, and the
;; applyN backing relations); those merge into the type env here, with
;; the usual conflict checking.
(define (lift-type-envs p)
  (match p
    [`(program ,reqs ,mods)
     (match-define (list type-env demands mods+)
       (foldl (lambda (mod acc)
                (match-define (list type-env+ demands+ mods+) acc)
                (match mod
                  [`(module ,path ,toks
                      ,type-env
                      ,demands
                      ,rules)
                   (list (unify-type-envs type-env type-env+)
                         (unify-demands demands+ demands)
                         (cons (list path toks rules) mods+))]))
              (list base-type-env (hash) '())
              (set->list mods)))
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
         (if (set-empty? clo-members)
             env
             (unify-type-envs
              env
              (type-env-union 'clo (set-add clo-members 'clo))))))
     (define mods++
       (for/set ([m (in-list mods-desugared)])
         (match-define (list path toks rules) m)
         `(module ,path ,toks ,rules)))
     ;; M2.4 need-driven decomposition synthesis (header comment above):
     ;; scan the desugared rules for undeclared `<R>_has`/`<R>_at` names over
     ;; a matching collection-lattice base and synthesize their declarations.
     (define-values (type-env++ decomp-env)
       (synthesize-decompositions mods++ type-env+))
     `(program ,(map lift-type-envs reqs) ,type-env++ ,mods++ ,decomp-env)]))

;; Every operator-position name of every rule (relation atoms, struct
;; patterns, prim calls -- conservative: an undeclared non-relation name is a
;; type error anyway, so over-collection cannot mis-fire the synthesis).
(define (rules-used-names mods)
  (for*/fold ([names (set)])
             ([m (in-set mods)] [rule (in-set (last m))])
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
  (match prog
    [`(program ,reqs ,type-env ,mods ,decomps)
     (foldr append `((program ,type-env ,mods ,decomps))
            (map linearize-programs reqs))]))

;; -----------------------------------------------------------------------
;; Manifests: each program is compiled against the manifest of relations
;; already in the database at that point (input DB plus every earlier
;; program's declarations), and must not contradict it.

(define (update-manifest type-env manifest)
  (define rels (type-env-rels type-env))
  (foldl (lambda (x man)
           (match (hash-ref rels x)
             ;; a map relation (table with a lattice-typed last column)
             ;; carries its valuespec so open/reload can re-register it
             [`(table ,xs ...)
              #:when (rel-lattice-spec rels x)
              (define entry `(lat ,x ,(length xs) ,(rel-lattice-spec rels x)))
              (cond
                [(hash-has-key? man x)
                 (when (not (equal? (hash-ref man x) entry))
                   (error (format "Lattice relation declaration does not match input database: ~a" x)))
                 man]
                [else (hash-set man x entry)])]
             [`(table ,xs ...)
              #:when (hash-has-key? man x)
              (when (not (equal? (hash-ref man x) `(rel ,x ,(length xs))))
                (error (format "Table declaration does not match input database: ~a" x)))
              man]
             [`(struct ,xs ...)
              #:when (hash-has-key? man x)
              (when (not (equal? (hash-ref man x) `(struct ,x ,(add1 (length xs)))))
                (error (format "Struct declaration does not match input database: ~a" x)))
              man]
             [`(table ,xs ...) (hash-set man x `(rel ,x ,(length xs)))]
             [`(struct ,xs ...) (hash-set man x `(struct ,x ,(add1 (length xs))))]
             [`(temp ,_ ...) man]
             [`(enum ,name) man]
             [`(oracle ,_ ...) man]   ; extern binding entry: not a relation
             [(? lattice-spec?) man]
             [(? listof-spec?) man]
             [(? mapof-spec?) man]))
         manifest
         (hash-keys rels)))

(define (thread-manifests prog-lst manifest)
  (match prog-lst
    [`((program ,type-env ,mods ,decomps) ,more ...)
     `((program ,type-env ,mods ,manifest ,decomps)
       ,@(thread-manifests more (update-manifest type-env manifest)))]
    ['() '()]))
