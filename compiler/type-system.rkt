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
;; Type errors raise; the result is a set of typed rules (ir-stack.rkt)
;; including the synthetic enum fact rules.

(provide typecheck-rules)

(require "parser.rkt")
(require "lexer.rkt")
(require "utils.rkt")
(require "ir-shared.rkt")

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
     (define (add-to-local cl env)
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
             ;; -> list) exactly as the relation-atom case below does
             (hash-set (foldl (lambda (x t env)
                                (hash-set env x (lattice-base-type rel-env t)))
                              env args ts)
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
             ;; unwrap out); lattice-check.rkt owns the use discipline
             (foldl (lambda (x t env) (hash-set env x (lattice-base-type rel-env t)))
                    env args ts)]
            [`(enum ,_) env]
            [`(,(or 'table 'struct) ,ts ...)
             (error (format "~a takes ~a columns but is used with ~a in ~a"
                            name (length ts) (length args) (strip-prov cl)))]
            [_
             (error (format "Table ~a in ~a is not defined." name (strip-prov cl)))])]))

     (define local-env-proto (foldl add-to-local (hash) (append heads bodys)))
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
     ;; the constant strings used.  `body?` only affects nothing here --
     ;; the produced clauses always join in the body.
     (define (convert-clauses cls)
       (for/fold ([kept '()] [extra-body '()] [consts (set)]
                  #:result (values (reverse kept) (reverse extra-body) consts))
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
                    (set-add consts (symbol->string s)))]
           [else (values (cons (check-clause cl) kept) extra-body consts)])))

     (define-values (bodys+ body-extra body-consts) (convert-clauses bodys))
     (define-values (heads+ head-extra head-consts) (convert-clauses heads))

     (values `(syn ,prov rule ,@body-extra ,@head-extra ,@bodys+ --> ,@heads+)
             (set-union body-consts head-consts))]))
