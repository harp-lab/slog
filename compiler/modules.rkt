#lang racket

;; The module system: turns a source path into the ordered list of programs
;; the pipeline compiles.
;;
;;   - `include "file"` merges another file's modules (and type declarations)
;;     into the current program.
;;   - `run "file"` names a prerequisite program: it is compiled separately
;;     and runs to fixpoint first, its database feeding this program.
;;
;; Loading a path therefore yields a tree of programs; linearizing it
;; dependencies-first gives the program list.  Alongside, each module's type
;; declarations (table/struct/union/enum) are extracted into a type
;; environment (see ir-shared.rkt) and merged across modules with conflict
;; checking; and a manifest of relations already present in the database is
;; threaded through the list so each program declares what it inherits.

(provide load-program-list)

(require "parser.rkt")
(require "utils.rkt")
(require "ir-shared.rkt")

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
       (define this-prog
         (foldl
          (lambda (inc-path prog)
            (program-merge-include prog (load-program-tree inc-path seen-run seen-inc)))
          (organize-module `(module ,path ,toks
                              ,ast-sans-directives))
          (filter (lambda (p) (and (file-exists? p) (not (set-member? seen-inc p))))
                  (map (lambda (p) (fullpath (normalize-path p rel-dir)))
                       (set->list inc-paths)))))
       (foldl (lambda (run-path prog)
                (define rp (fullpath run-path))
                (when (set-member? seen-run rp)
                  (error (format "Module ~a transitively runs itself" rp)))
                ;; a fresh include-set: each program's includes are its own
                (program-merge-run prog (load-program-tree rp seen-run (set))))
              this-prog
              (filter file-exists?
                      (map (lambda (p) (normalize-path p rel-dir)) run-paths)))])))

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
      [_ (error (format "Type declarations ~a and ~a conflict" t0 t1))]))
  (for ([x (in-set (set-intersect (list->set (hash-keys (type-env-aliases env+)))
                                  (list->set (hash-keys (type-env-rels env+)))))])
    (error (format "The type ~a appears defined as a union and struct!" x)))
  env+)

(define base-type-env
  (unify-type-envs empty-type-env (type-env-rel '_enum `(struct str))))

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

  (define (extract-type-env ast [env base-type-env])
    (match ast
      [`(syn ,_ ,(and struct-or-table (or 'table 'struct))
             (syn ,_ ,(? symbol? name) ,args ...) ,body)
       (when (null? args)
         (error (format "Table or struct ~a must have at least one column" name)))
       (match-define (cons xs env+) (flatten-nested-types env args))
       (extract-type-env body
                         (unify-type-envs env+ (type-env-rel name `(,struct-or-table ,@xs))))]

      [`(syn ,_ union (syn ,_ ,(? symbol? name) ,args ...) ,body)
       (match-define (cons xs env+) (flatten-nested-types env args))
       (extract-type-env body
                         (unify-type-envs env+ (type-env-union name (list->set (cons name xs)))))]

      [`(syn ,_ enum (syn ,_ ,name ,(? symbol? names) ...) ,body)
       ;; A bare nullary constructor (`enum (halt)`, via a union member) is
       ;; itself a constant.  A named enumeration (`enum (color red green
       ;; blue)`) additionally makes the name a type over its member
       ;; constants -- an alias set, exactly like a union of nullary members
       ;; -- so columns can be declared with the enum's name.
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

      [`(syn ,prov facts ,facts ... ,topbody)
       (extract-rules topbody (set-add rules `(syn ,prov rule --> ,@facts)))]

      ;; skip over defs, funs, etc
      [_ (extract-rules (last ast) rules)]))

  (match module-ast
    [`(module ,path ,toks
        ,ast)
     `(program ()
               ,(set `(module ,path ,toks
                        ,(extract-type-env ast)
                        ,(extract-rules ast))))]))

;; -----------------------------------------------------------------------
;; Lifting and linearization.

;; Merge each program's per-module type environments into one program-level
;; environment (recursively over the run tree).
(define (lift-type-envs p)
  (match p
    [`(program ,reqs ,mods)
     (match-define (cons type-env mods+)
       (foldl (lambda (mod acc)
                (match-define (cons type-env+ mods+) acc)
                (match mod
                  [`(module ,path ,toks
                      ,type-env
                      ,rules)
                   (cons (unify-type-envs type-env type-env+)
                         (set-add mods+
                                  `(module ,path ,toks
                                     ,rules)))]))
              (cons base-type-env (set))
              (set->list mods)))
     `(program ,(map lift-type-envs reqs) ,type-env ,mods)]))

;; Dependencies-first (post-order) linearization of the run tree.
(define (linearize-programs prog)
  (match prog
    [`(program ,reqs ,type-env ,mods)
     (foldr append `((program ,type-env ,mods)) (map linearize-programs reqs))]))

;; -----------------------------------------------------------------------
;; Manifests: each program is compiled against the manifest of relations
;; already in the database at that point (input DB plus every earlier
;; program's declarations), and must not contradict it.

(define (update-manifest type-env manifest)
  (define rels (type-env-rels type-env))
  (foldl (lambda (x man)
           (match (hash-ref rels x)
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
             [`(enum ,name) man]))
         manifest
         (hash-keys rels)))

(define (thread-manifests prog-lst manifest)
  (match prog-lst
    [`((program ,type-env ,mods) ,more ...)
     `((program ,type-env ,mods ,manifest)
       ,@(thread-manifests more (update-manifest type-env manifest)))]
    ['() '()]))
