#lang racket

(require "parser.rkt")
(require "utils.rkt")
(require "preds.rkt")

(provide typecheck-rule)

(define ((typecheck-rule type-env) rule defs)
  (define alias-env (first type-env))
  (define rel-env (second type-env))
  (define fun-env (third type-env))
  (match rule
    [`(syn ,prov rule ,bodys ... --> ,heads ...)

     (define (add-to-local cl env)
       (match cl
         [`(syn ,_ /= ,x ,y) env]
         [`(syn ,_ ,(? primitive-cmp?) ,x ,y) env]
         [`(syn ,_ = ,x (syn ,_ const ,(? string?))) (hash-set env x 'str)]
         [`(syn ,_ = ,x (syn ,_ const ,(? exact-integer?))) (hash-set env x 'int)]
         [`(syn ,_ = ,x (syn ,_ const ,(? inexact-real?))) (hash-set env x 'float)]
         [`(syn ,_ = ,x (syn ,_ ,name ,args ...))
          #:when (hash-has-key? fun-env name)
          (match-define `(fun ,argts ... -> ,rett) (hash-ref fun-env name))
          (define env+
            (foldl (lambda (y t env)
                     (if (set-member? (set 'A 'B 'C) t)
                         ;; Link the other args (and, for the result type var,
                         ;; the target x) to this arg's equivalence class.  Skip
                         ;; the self-link (= y)->y: a computed arg has no direct
                         ;; type, so a self-alias would loop resolve-local-type.
                         (foldl (lambda (arg env)
                                  (if (equal? arg y) env (hash-set env `(= ,arg) y)))
                                (if (eq? t rett)
                                    (hash-set env `(= ,x) y)
                                    env)
                                args)
                         (hash-set env y t)))
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
             (hash-set (foldl (lambda (x t env) (hash-set env x t)) env args ts) x name)]
            [_ (error (format "Struct ~a in ~a is not defined." name (strip-prov cl)))])]
         [`(syn ,_ ,name ,(? symbol? args) ...)
          (match (hash-ref rel-env name list)
            [`(table ,ts ...)
             #:when (= (length args) (length ts))
             (foldl (lambda (x t env) (hash-set env x t)) env args ts)]
            [`(struct ,ts ...)
             #:when (= (length args) (length ts))
             (foldl (lambda (x t env) (hash-set env x t)) env args ts)]
            [_
             (error (format "Table ~a in ~a is not defined.\n~a"
                            name
                            (strip-prov cl)
                            (hash-ref rel-env name list)))])]))

     ;; First pass collects immediate variable types
     (define local-env-proto (foldl add-to-local (hash) (append heads bodys)))
     (define (resolve-local-type sym [seen (set)])
       (cond
         [(hash-has-key? local-env-proto sym) (hash-ref local-env-proto sym)]
         [(set-member? seen sym) (error (format "Circular local-env alias involving ~a" sym))]
         [else
          (define alias (hash-ref local-env-proto `(= ,sym) (lambda () #f)))
          (if alias
              (resolve-local-type alias (set-add seen sym))
              (error (format "No local-env for ~a" sym)))]))
     ;; Second pass connects variables via polymorphic instantiations
     (define local-env
       (foldl (lambda (k env)
                (match k
                  [`(= ,x)
                   (let* ([y (hash-ref local-env-proto k)]
                          [yt (resolve-local-type y)]
                          [xt (hash-ref local-env-proto x (lambda () #f))])
                     (if xt
                         (if (equal? xt yt)
                             (hash-set env x xt)
                             (error (format "Arguments ~a : ~a and ~a : ~a do not match" x xt y yt)))
                         (hash-set env x yt)))]
                  [(? symbol? x) (hash-set env x (hash-ref local-env-proto x))]))
              (hash)
              (hash-keys local-env-proto)))

     (define (type-match? t x)
       (define t* (hash-ref alias-env t (lambda () (set t))))
       (define t+
         (hash-ref alias-env (hash-ref local-env x) (lambda () (set (hash-ref local-env x)))))
       (let ([checks (or (set-member? t* 'any) (not (set-empty? (set-intersect t* t+))))])
         (if (or checks (set-member? (set 'A 'B 'C) t))
             checks
             (error (format "~a : ~a does not match type '~a' in\n~a"
                            x
                            t
                            (hash-ref local-env x void)
                            (strip-prov rule))))))

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
                (if (and (= (length ts) (length args)))
                    (map type-match? ts args)
                    (error (format "~a is being used with the wrong arity" name))))]))
       (match cl
         [`(syn ,_ /= ,(? symbol? x) ,(? symbol? y)) cl]
         [`(syn ,_ ,(? primitive-cmp?) ,(? symbol? x) ,(? symbol? y)) cl]
         [`(syn ,_ = ,(? symbol? x) (syn ,_ const ,v)) cl]
         [`(syn ,pr0 = ,(? symbol? x) (syn ,pr1 ,name ,(? symbol? args) ...))
          #:when (hash-has-key? fun-env name)
          (check-rel! x name args (hash-ref fun-env name))
          ;; Specialize function calls as let clauses so they're ordered as specials
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

     (define (enum? cl)
       (match cl
         [(or `(syn ,_ = ,_ (syn ,_ ,name)) `(syn ,_ = ,_ (syn ,_ ,name)))
          (not (hash-has-key? fun-env name))]
         [_ #f]))

     ;; Both checks clauses and extracts enum constants
     (define (extract-enum-consts cl acc)
       (match-define (cons cls const-cls) acc)
       (define cx (gensymb '_tconst))
       (match cl
         [`(syn ,p0 = ,x (syn ,p1 ,name))
          (cons (cons `(syn ,p0 = ,x (syn ,p1 _enum ,cx)) cls)
                (cons `(syn ,p0 = ,cx (syn ,p0 const ,(symbol->string name))) const-cls))]
         [`(syn ,p0 ,name)
          (cons (cons `(syn ,p0 = ,(gensymb '_) (syn ,p0 _enum ,cx)) cls)
                (cons `(syn ,p0 = ,cx (syn ,p0 const ,(symbol->string name))) const-cls))]
         [_ (cons (cons (check-clause cl) cls) const-cls)]))

     ;; Type check this rule:
     (match-define (cons bodys+ const-cls0) (foldr extract-enum-consts (cons '() '()) bodys))
     (match-define (cons heads+ const-cls1) (foldr extract-enum-consts (cons '() '()) heads))

     (set-add defs `(syn ,prov rule ,@const-cls0 ,@const-cls1 ,@bodys+ --> ,@heads+))]))
