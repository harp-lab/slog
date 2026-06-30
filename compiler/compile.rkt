#lang racket

(provide compile-path)

(require "parser.rkt")
(require "params.rkt")
(require "utils.rkt")
(require "tools.rkt")
(require "indices.rkt")
(require "primitives.rkt")
(require "simplification.rkt")
(require "join-planning.rkt")
(require "operationalization.rkt")
(require "type-system.rkt")
(require "emit-cpp.rkt")
(require "preds.rkt")
(require racket/future)
(require sha)

;; Fingerprint of the daemon headers.  The generated .so #includes
;; daemon/slogd.h and inlines Database's layout and methods, so any header
;; change must invalidate cached .so's (otherwise a stale .so reads members
;; at the wrong offsets).  Folded into the .so cache key below.
(define daemon-headers-fingerprint
  (apply string-append
         (for/list ([f (in-list (sort (map path->string (directory-list "daemon"))
                                       string<?))]
                    #:when (regexp-match? #rx"\\.h$" f))
           (file->string (build-path "daemon" f)))))

(define (compile-path path dbmanifest)
  ;; lifts and merges type environments for programs (sets of included modules)
  (define (lift-type-envs p)
    (match p
      [`(program ,reqs ,mods)
       (match-define (cons type-env mods+)
         (foldl (lambda (mod acc)
                  (match-define (cons type-env+ mods+) acc)
                  (match mod
                    [`(module ,path ,toks
                        ,type-env
                        ,defs-st)
                     (cons (unify-type-envs type-env type-env+)
                           (set-add mods+
                                    `(module ,path ,toks
                                       ,defs-st)))]))
                (cons empty-type-env (set))
                (set->list mods)))
       `(program ,(map lift-type-envs reqs) ,type-env ,mods)]))

  (define (preorder-traversal prog)
    (match prog
      [`(program ,reqs ,type-env ,mods)
       (foldr append `((program ,type-env ,mods)) (map preorder-traversal reqs))]))

  (define (update-manifest type-env dbmanifest)
    (define env (second type-env))
    (foldl (lambda (x man)
             (match (hash-ref env x)
               [`(table ,xs ...)
                #:when (hash-has-key? man x)
                (when (not (equal? (hash-ref man x) `(rel ,x ,(length xs))))
                  (error (format "Table declaration does not match input database: ~a" x)))
                man]
               [`(struct ,xs ...)
                #:when (hash-has-key? man x)
                (when (not (equal? (hash-ref man x) `(struct ,x ,(add1 (length xs)))))
                  (error (format "Table declaration does not match input database: ~a" x)))
                man]
               [`(table ,xs ...) (hash-set man x `(rel ,x ,(length xs)))]
               [`(struct ,xs ...) (hash-set man x `(struct ,x ,(add1 (length xs))))]
               [`(temp ,_ ...) man]
               [`(enum ,name) (hash-set man x `(struct _enum str))]))
           dbmanifest
           (hash-keys env)))

  (define (add-manifests prog-lst dbmanifest)
    (match prog-lst
      [`((program ,type-env ,mods) ,more ...)
       (define dbmanifest+ (update-manifest type-env dbmanifest))
       `((program ,type-env ,mods ,dbmanifest) ,@(add-manifests more dbmanifest+))]
      ['() '()]))

  (define prog-lst (preorder-traversal (lift-type-envs (include-module-path path))))

  (define (compile-future lst)
    (if (null? lst)
        (future (lambda () '()))
        (future (lambda ()
                  (let ([future-v (compile-future (cdr lst))])
                    (cons (compile-one-program (car lst)) future-v))))))

  ; returns a touched FutureStream = (future (or '() (cons string? FutureStream)))
  ; each compiled program is a string of its hash; compiled to build/hash.so
  (touch (compile-future (add-manifests prog-lst dbmanifest))))

(define (compile-one-program prog)

  (define (add-dynamic-rels rule drels)
    (match rule
      [`(syn ,prov rule ,bodys ... --> ,heads ...)
       (foldl (lambda (hcl drels)
                (match hcl
                  [`(syn ,_ = ,x (syn ,_ ,name ,xs ...)) (set-add drels name)]
                  [`(syn ,_ ,name ,xs ...) (set-add drels name)]))
              drels
              heads)]))

  (define (compile-all type-env mods)
    ;; Todo: first extract non-rule defs and desugar these before simplifying all rules
    ;;       this step must also extract a fun-env that extends prim-fun-env....
    (define all-defs (set->list (foldl set-union (set) (map last (set->list mods)))))
    ;; simplify and flatten all nested structure across rules
    (define all-simple-rules (foldl simplify-rule (set) all-defs))
    (when (not (andmap (compose rule? strip-prov) (set->list all-simple-rules)))
      (error "bad absyn"))
    ;; type check these rules and issue warnings:
    (define all-typed-rules (foldl (typecheck-rule type-env) (set) (set->list all-simple-rules)))
    ;; incrementalize, and generate join plans
    (define rel-env (second type-env))
    (match-define (cons all-planned-rules rel-env+)
      (foldl plan-rule (cons (set) rel-env) (set->list all-typed-rules)))
    (match-define (cons constants all-planned-rules+)
      (globalize-constants (set->list all-planned-rules)))
    ;; compute select sets and optimal indices
    (define select-sets
      (foldl add-select-sets (type-select-sets rel-env+) (set->list all-planned-rules+)))
    (define indices
      (foldl (lambda (name ind) (hash-set ind name (naive-indices-bin (hash-ref select-sets name))))
             (hash)
             (hash-keys select-sets)))
    (define dynamic-rels (foldl add-dynamic-rels (set) (set->list all-planned-rules+)))
    ;; setup struct/table declarations based on the rel-env
    (define c-rels (make-rel-decls rel-env+ indices))
    ;; turn each planned rule into a c-rule, picking an index for each join
    (define c-rules (foldl (add-c-rule rel-env+ indices) '() (set->list all-planned-rules+)))
    ;; return a low-level program emit-cpp.rkt can run with
    (escape-all-ids-for-C `(,dynamic-rels ,constants ,@c-rels ,@c-rules)))

  ;; setup a .so path for caching based on a hash of the code
  ;; compile-all modules under the type environment
  ;; build the so from this compiled program using dbmanifest
  (match prog
    [`(program ,type-env ,mods ,dbmanifest)
     ;; dump info in some fixed order and hash to yield a unique hashcode
     (define info0 (sort (hash->list (first type-env)) symbol<? #:key car))
     (define info1 (sort (hash->list (second type-env)) symbol<? #:key car))
     (define info2 (sort (set->list mods) string<? #:key second))
     (define info3 (sort (hash->list dbmanifest) symbol<? #:key car))
     (define progstr (with-output-to-string (lambda () (print (append info0 info1 info2 info3 (list daemon-headers-fingerprint))))))
     (define proghash
       (substring (bytes->hex-string (sha256 (string->bytes/utf-8 progstr))) 0 (if debug-mode 8 32)))
     (define so-path (fullpath (format "build/~a.so" proghash)))
     (if (file-exists? so-path)
         proghash
         (let ([cprog (compile-all type-env mods)])
           (list proghash cprog (write-cpp cprog dbmanifest))))]))

(define (include-module-path path [seenr (set)] [seeni (set)])
  (define module-ast (parse-file path))
  (include-module path module-ast seenr seeni))

; A program has a set of run'd (sub)programs
;    and a set of its own local (included) modules
(define (program-merge-run p0 p1)
  (match p0
    [`(program ,reqs ,mods) `(program (,@reqs ,p1) ,mods)]))

(define (program-merge-include p0 p1)
  (match (list p0 p1)
    [`((program ,reqs0 ,mods0) (program ,reqs1 ,mods1))
     `(program (,@reqs0 ,@reqs1) ,(set-union mods0 mods1))]))

(define (include-module path module-ast [seenr (set)] [seeni (set)])
  (let* ([path (fullpath path)]
         [seenr (set-add seenr path)]
         [seeni (set-add seeni path)])
    (match module-ast
      [`(module ,path+ ,toks
          ,ast)
       (define-values (rel-dir _0 _1) (split-path path))
       (define (strip-inc ast)
         (match ast
           [`(syn ,_ include (syn ,_ const ,path+) ,body)
            (match-define (list ast+ req-paths inc-paths) (strip-inc body))
            (list ast+ req-paths (set-add inc-paths path+))]
           [`(syn ,_ run (syn ,_ const ,path+) ,body)
            (match-define (list ast+ req-paths inc-paths) (strip-inc body))
            (list ast+ (cons path+ req-paths) inc-paths)]
           [_ (list ast '() (set))]))
       (match-define (list ast-sans-inc req-paths inc-paths) (strip-inc ast))
       (define this-prog
         (foldl
          (lambda (path+ prog) (program-merge-include prog (include-module-path path+ seenr seeni)))
          (organize-module `(module ,path ,toks
                              ,ast-sans-inc))
          (filter (lambda (p) (and (file-exists? p) (not (set-member? seeni p))))
                  (map (lambda (p) (fullpath (normalize-path p rel-dir))) (set->list inc-paths)))))
       (foldl (lambda (path+ prog)
                (when (set-member? seenr path+)
                  (error (format "Module ~a transitively runs itself" path+)))
                (program-merge-run
                 prog
                 (include-module-path path+ (set-union seenr (list->set (second prog))) (set))))
              this-prog
              (filter file-exists? (map (lambda (p) (normalize-path p rel-dir)) req-paths)))])))

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

(define empty-type-env `(,(hash) ,(hash) ,prim-fun-env))
(define (type-env-rel x t)
  `(,(hash) ,(hash x t) ,(hash)))
(define (type-env-union x st)
  `(,(hash x st) ,(hash) ,(hash)))

(define (unify-type-envs e0 e1)
  (define alias-env
    (transitive-env ;; simple pointwise join and then TC
     (foldl (lambda (name env)
              (if (hash-has-key? env name)
                  (hash-set env name (set-union (hash-ref env name) (hash-ref (first e1) name)))
                  (hash-set env name (hash-ref (first e1) name))))
            (first e0)
            (hash-keys (first e1)))))
  (define env+
    (list
     alias-env
     (foldl (lambda (name env) (hash-set env name (hash-ref (second e1) name)))
            (second e0)
            (filter (lambda (k) (not (hash-has-key? (second e0) k))) (hash-keys (second e1))))
     (foldl
      (lambda (name env)
        (if (hash-has-key? env name)
            (let ([myval (hash-ref env name)]
                  [oval (hash-ref (third e1) name)])
              (if (equal? myval oval)
                  env
                  (error (format "Function declarations must exactly match: ~a : ~a \n  vs\n  ~a : ~a"
                                 name
                                 myval
                                 name
                                 oval))))
            (hash-set env name (hash-ref (third e1) name))))
      (third e0)
      (hash-keys (third e1)))))
  ;; check for conflicts
  (define (types-unify? t0 t1)
    (or (equal? t0 t1)
        (and (set-member? (hash-ref alias-env t0 set) t1)
             (set-member? (hash-ref alias-env t1 set) t0)
             (equal? (hash-ref alias-env t0 set) (hash-ref alias-env t1 set)))))
  (map (lambda (name)
         (define t0 (hash-ref (second env+) name))
         (define t1 (hash-ref (second e1) name))
         (match (list t0 t1)
           [`((,struct-or-table ,fields0 ...) (,struct-or-table ,fields1 ...))
            #:when (and (= (length fields0) (length fields1)) (andmap types-unify? fields0 fields1))
            #t]
           [_ (error (format "Type declarations ~a and ~a conflict" t0 t1))]))
       (filter (lambda (k) (hash-has-key? (second e0) k)) (hash-keys (second e1))))
  (map (lambda (x) (error (format "The type ~a appears defined as a union and struct!" x)))
       (set->list (set-intersect (list->set (hash-keys (first env+)))
                                 (list->set (hash-keys (second env+))))))
  env+)

(define (organize-module module-ast)
  (define (flatten-nested-type env type-e)
    (match type-e
      [(? symbol? x) (cons x env)]
      [`(syn ,prov union ,args ...)
       (define g (gensymb 'union))
       (match-define (cons xs env+) (flatten-nested-types env args))
       (cons g
             (unify-type-envs env+
                              (extract-type-env `(syn ,prov union (,g ,@xs) (syn ,prov top-level)))))]
      [`(syn ,prov ,name)
       (cons name (extract-type-env `(syn ,prov enum (syn ,prov ,name) (syn ,prov top-level)) env))]
      ;; otherwise, nested struct declaration
      [`(syn ,prov ,structname ,args ...)
       (cons structname (extract-type-env `(syn ,prov struct ,type-e (syn ,prov top-level)) env))]))

  (define (flatten-nested-types env args)
    (foldr (lambda (arg acc)
             (match-define (cons xs env+) acc)
             (match-define (cons x env++) (flatten-nested-type env+ arg))
             (cons (cons x xs) env++))
           (cons '() env)
           args))

  (define (extract-type-env ast [env empty-type-env])
    (match ast
      [`(syn ,_ ,(and struct-or-table (or 'table 'struct)) (syn ,_ ,(? symbol? name) ,args ...) ,body)
       (when (null? args)
         (error "Empty table"))
       (match-define (cons xs env+) (flatten-nested-types env args))
       (extract-type-env body (unify-type-envs env+ (type-env-rel name `(,struct-or-table ,@xs))))]

      [`(syn ,_ union (syn ,_ ,(? symbol? name) ,args ...) ,body)
       (match-define (cons xs env+) (flatten-nested-types env args))
       (extract-type-env body
                         (unify-type-envs env+ (type-env-union name (list->set (cons name xs)))))]

      [`(syn ,_ enum (syn ,_ ,name ,(? symbol? names) ...) ,body)
       (extract-type-env body
                         (foldl unify-type-envs
                                env
                                (map (lambda (name)
                                       (unify-type-envs (type-env-rel name `(enum ,name))
                                                        (type-env-rel '_enum `(struct str))))
                                     (cons name names))))]

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

  (define (extract-import/export ast (import (set)) (export (set)))
    (match ast
      [`(syn ,_ top-level) (cons import export)]

      [`(syn ,_ import (syn ,_ const ,(? string? nm0)) (syn ,_ const ,(? string? nm1)) ,topbody)
       (extract-import/export topbody (set-add import (cons nm0 nm1)) export)]

      [`(syn ,_ export (syn ,_ const ,(? string? nm0)) (syn ,_ const ,(? string? nm1)) ,topbody)
       (extract-import/export topbody import (set-add export (cons nm0 nm1)))]

      ;; skip over defs, funs, etc
      [_ (extract-import/export (last ast) import export)]))

  (match module-ast
    [`(module ,path ,toks
        ,ast)
     (define type-env (extract-type-env ast))
     (define defs-st (extract-rules ast))
     `(program ()
               ,(set `(module ,path ,toks
                        ,type-env
                        ,defs-st)))]))
