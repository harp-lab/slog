#lang racket

;; Simplification: source rules to flat rules (ir-stack.rkt).
;;
;; Four steps, applied per rule:
;;   1. split `|` alternatives in the body into separate rules;
;;   2. flatten all nested structure -- every nested construction, constant,
;;      and & conjunction lifts into a fresh (= var ...) clause, so clause
;;      arguments are all plain variables afterwards;
;;   3. replace each _ wildcard with a fresh variable;
;;   4. statically unify to a fixpoint: identical right-hand sides share one
;;      binding, variable-variable equalities collapse via union-find, and
;;      trivial (= x x) clauses drop.

(require "utils.rkt")
(require "parser.rkt")

(provide simplify-rule split-or-clauses)

;; Split `|` alternatives: the cartesian product of each clause's
;; alternatives, over a clause or a whole body (a list of clauses).
;; Exported for the demand transform (demand.rkt), which must split
;; alternatives before scheduling ask rules -- each alternative grounds
;; its own variables.
(define (or-symbol? x)
  (and (symbol? x) (equal? "|" (symbol->string x))))

(define (split-or-clauses cl)
  (match cl
    [`(syn ,_ ,(? or-symbol?) ,cls ...)
     (foldl set-union (set) (map split-or-clauses cls))]
    ;; a fully parenthesized alternative like ((a X) | (b X)) parses as a
    ;; one-element application whose head is the or expression: unwrap it
    [`(syn ,_ (syn ,prov ,(? or-symbol? pipe) ,cls ...))
     (split-or-clauses `(syn ,prov ,pipe ,@cls))]
    [`(,cl0 ,cls ...)
     (foldl
      (lambda (cl0v acc)
        (foldl (lambda (clsv acc) (set-add acc `(,cl0v ,@clsv)))
               acc
               (set->list (split-or-clauses cls))))
      (set)
      (set->list (split-or-clauses cl0)))]
    [_ (set cl)]))

(define (simplify-rule rule rules)
  (define (rhs-unify-clauses cls [rhs-env (hash)])
    (foldl (lambda (cl acc)
             (match-define (cons rhs-env bodys) acc)
             (match cl
               [`(syn ,_ /= ,_ ...) (cons rhs-env (cons cl bodys))]
               [`(syn ,prov = ,(? symbol? x) (syn ,_ ,rhs ...))
                (if (hash-has-key? rhs-env rhs)
                    (cons rhs-env (cons `(syn ,prov = ,x ,(hash-ref rhs-env rhs)) bodys))
                    (cons (hash-set rhs-env rhs x) (cons cl bodys)))]
               [`(syn ,_ ,rhs ...)
                #:when (hash-has-key? rhs-env rhs)
                acc]
               [_ (cons rhs-env (cons cl bodys))]))
           (cons rhs-env '())
           ;; put = first so we can catch an implicit (= _ (foo ...))
           ;; that matches some prior rhs with a name
           (sort cls < #:key (lambda (cl) (if (member '= cl) 0 1)))))
  (define (lhs-unify-clauses cls [lhs-env (hash)])
    (define (find-root uf x)
      (let ([y (hash-ref uf x (lambda () x))])
        (if (equal? x y)
            x
            (find-root uf y))))
    (define uf ;; Build union-find
      (foldl (lambda (cl uf)
               (match cl
                 [`(syn ,_ = ,(? symbol? x) ,(? symbol? y))
                  (if (hash-has-key? uf x)
                      (if (hash-has-key? uf y)
                          (let* ([s (symbol->string (find-root uf x))]
                                 [best (if (equal? (substring s 0 1) "_")
                                           (find-root uf y)
                                           (find-root uf x))])
                            (hash-set (hash-set uf (find-root uf y) best) (find-root uf x) best))
                          (hash-set uf y (find-root uf x)))
                      (hash-set uf x (find-root uf y)))]
                 [_ uf]))
             lhs-env
             (set->list cls)))
    (define uf+ (foldl (lambda (x uf) (hash-set uf x (find-root uf x))) uf (hash-keys uf)))
    (define (rewrite-all-vars v)
      (match v
        [(? symbol?) (find-root uf+ v)]
        [(? list?) (map rewrite-all-vars v)]
        [_ v]))
    (cons uf (rewrite-all-vars cls)))
  (define (simplify-subclause scl clauses)
    (match scl
      [`(syn ,prov const ,v)
       (define cx (gensymb '_tconst))
       (cons cx (cons `(syn ,prov = ,cx (syn ,prov const ,v)) clauses))]
      [`(syn ,prov /= ,_ ...)
       (error (parse-error "Inequality is not permitted as a subclause" (second prov)))]
      [`(syn ,prov & ,scls ...)
       #:when (> (length scls) 0)
       (match-define (cons xs clauses+)
         (foldl (lambda (scl acc)
                  (match-define (cons xs clauses) acc)
                  (match-define (cons x clauses+) (simplify-subclause scl clauses))
                  (cons (cons x xs) clauses+))
                (cons '() clauses)
                scls))
       (cons (car xs)
             (foldl (lambda (x y clauses) (cons `(syn ,prov = ,x ,y) clauses))
                    clauses+
                    (take xs (- (length xs) 1))
                    (cdr xs)))]
      [`(syn ,prov = ,scl0 ,scl1)
       (match-define (cons x clauses+) (simplify-subclause scl0 clauses))
       (match-define (cons y clauses++) (simplify-subclause scl1 clauses+))
       (cons x (cons `(syn ,prov = ,x ,y) clauses++))]
      [`(syn ,prov = ,scl0 ,scl1 ,scls ...)
       (simplify-subclause `(syn ,prov = ,scl0 (syn ,prov = ,scl1 ,@scls)) clauses)]

      [`(syn ,prov ,name ,scls ...)
       (match-define (cons xs clauses+)
         (foldr (lambda (scl acc)
                  (match-define (cons xs clauses) acc)
                  (match-define (cons x clauses+) (simplify-subclause scl clauses))
                  (cons (cons x xs) clauses+))
                (cons '() clauses)
                scls))
       (define id (gensymb '_t))
       (cons id (cons `(syn ,prov = ,id (syn ,prov ,name ,@xs)) clauses+))]
      [(? symbol? x) (cons x clauses)]
      [_ (error (format "Unrecognized clause ~a" scl))]))
  (define (simplify-clause cl clauses)
    (match cl
      [`(syn ,prov /= ,scl0 ,scl1)
       (match-define (cons x clauses+) (simplify-subclause scl0 clauses))
       (match-define (cons y clauses++) (simplify-subclause scl1 clauses+))
       (cons `(syn ,prov /= ,x ,y) clauses++)]
      [`(syn ,prov ,name ,scls ...)
       #:when (not (set-member? (set '= '&) name))
       (match-define (cons xs clauses+)
         (foldr (lambda (scl acc)
                  (match-define (cons xs clauses) acc)
                  (match-define (cons x clauses+) (simplify-subclause scl clauses))
                  (cons (cons x xs) clauses+))
                (cons '() clauses)
                scls))
       (cons `(syn ,prov ,name ,@xs) clauses+)]
      [_ (cdr (simplify-subclause cl clauses))]))
  (define (handle-wild-card v)
    (match v
      ['_ (gensymb '__)]
      [(? list?) (map handle-wild-card v)]
      [_ v]))
  (define (static-unify-rule rule)
    (match rule
      [`(syn ,prov rule ,bodys ... --> ,heads ...)
       (match-define (cons rhs-env bodys+) (rhs-unify-clauses bodys))
       (match-define (cons _ heads+) (rhs-unify-clauses heads rhs-env))
       ;; variable-variable equalities substitute over the WHOLE rule: a
       ;; head-side (= Y t) must rewrite Y in the body too, or the head
       ;; silently disconnects from the body's Y (unifying instead turns it
       ;; into the natural constraint -- e.g. a body self-join or, for a
       ;; computed t, the planner's ==-check)
       (match-define (cons lhs-env all++)
         (lhs-unify-clauses (append bodys+ heads+)))
       (define bodys++ (take all++ (length bodys+)))
       (define heads++ (drop all++ (length bodys+)))
       (define rule+
         (filter (lambda (cl)
                   (match cl
                     [`(syn ,_ = ,x ,y) (not (equal? x y))]
                     [_ #t]))
                 `(syn ,prov rule ,@bodys++ --> ,@heads++)))
       (if (and (equal? (list->set bodys) (list->set bodys++))
                (equal? (list->set heads) (list->set heads++)))
           rule
           (static-unify-rule rule+))]))
  ;; Simplify the rule
  (match rule
    ;; 1. split rule bodies by or clauses
    [`(syn ,prov rule ,bodys ... --> ,heads ...)
     (define all-bodies (split-or-clauses bodys))
     ;; 2. simplify all heads and bodys (flatten all nested structure)
     (define heads+ (handle-wild-card (foldl simplify-clause '() heads)))
     (foldl (lambda (bodys rules)
              ;; 3. handle-wild-card: replace _ with a unique (gensymb '__)
              (define bodys+ (handle-wild-card (foldl simplify-clause '() bodys)))
              (set-add rules ;; 4. static unification (to a fixpoint)
                       (static-unify-rule `(syn ,prov rule ,@bodys+ --> ,@heads+))))
            rules
            (set->list all-bodies))]))
