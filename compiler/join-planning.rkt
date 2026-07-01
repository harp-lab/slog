#lang racket

(require "utils.rkt"
         "parser.rkt"
         "preds.rkt")

(provide plan-rule)

(define (clause-vars cl)
  (match cl
    [`(syn ,_ /= ,x ,y) (set x y)]
    [`(syn ,_ let ,x ,(? symbol? y)) (set x y)]
    [`(syn ,_ let ,x (syn ,_ ,name ,args ...)) (list->set `(,x ,@args))]
    [`(syn ,_ = ,x (syn ,_ const ,_)) (set x)]
    [`(syn ,_ = ,x (syn ,_ ,name ,xs ...)) (list->set `(,x ,@xs))]
    [`(syn ,_ ,name ,xs ...) (list->set xs)]))

(define (clause-req-vars cl)
  (match cl
    [`(syn ,_ /= ,x ,y) (set x y)]
    [`(syn ,_ == ,x ,y) (set x y)]
    [`(syn ,_ let ,x ,(? symbol? y)) (set y)]
    [`(syn ,_ let ,x (syn ,_ ,name ,args ...)) (list->set args)]
    [`(syn ,_ = ,x (syn ,_ const ,_)) (set)]
    [`(syn ,_ = ,x (syn ,_ ,name ,xs ...)) (list->set xs)]
    [`(syn ,_ ,name ,xs ...) (list->set xs)]))

(define (plan-rule rule defs+relenv)
  (match rule
    [`(syn ,prov rule ,bodys ... --> ,heads ...)
     ;; The head can only have x = (struct ...), x == y, and (rel ...) clauses
     ;; the body must first be split into special clauses and join clauses
     (define (special-cl? cl)
       (match cl
         [`(syn ,_ /= ,x ,y) #t]
         [`(syn ,_ ,(? primitive-cmp?) ,x ,y) #t]
         [`(syn ,_ let ,x ,y) #t]
         [_ #f]))
     (define (const-cl? cl)
       (match cl
         [`(syn ,_ = ,x (syn ,_ const ,v)) #t]
         [_ #f]))
     (define const-cls (filter const-cl? (append bodys heads)))
     (define const-vars (foldl set-union (set) (map clause-vars const-cls)))
     (match-define (cons _ heads+)
       (foldl (lambda (hcl acc)
                (match-define (cons env heads+) acc)
                (match hcl
                  [`(syn ,p = ,x ,cl)
                   #:when (set-member? env x)
                   ;; Two head clauses bind the same new id var to different
                   ;; constructions -- a value-unification constraint whose
                   ;; runtime (==) was never implemented.  Reject loudly.
                   (error 'plan-rule
                          "value unification (==) is not supported: head binds ~a twice" x)]
                  ;; when not already seen
                  [`(syn ,p = ,x ,cl) (cons (set-add env x) (cons hcl heads+))]
                  [_ (cons env (cons hcl heads+))]))
              (cons (set) '())
              (filter (not/c const-cl?) heads)))
     (define special-cls (filter special-cl? bodys))
     (define join-cls (filter (and/c (not/c const-cl?) (not/c special-cl?)) bodys))
     (define computed-vars
       (foldl (lambda (cl acc)
                (match cl
                  [`(syn ,_ let ,x ,_) (set-add acc x)]
                  [_ acc]))
              (set)
              special-cls))

     (define (join-ready? cl ground-vars)
       (set-empty? (set-subtract (set-intersect (clause-vars cl) computed-vars) ground-vars)))

     ;; Plan a list of body clauses starting with this
     (define (plan-body-with this rem-bodys rem-special [ground (set)])
       (define ground+ (set-union ground (clause-vars this)))
       (define (ground-special? cl)
         (match cl
           [`(syn ,_ /= ,x ,y) (and (set-member? ground+ x) (set-member? ground+ y))]
           [`(syn ,_ ,(? primitive-cmp?) ,x ,y) (and (set-member? ground+ x) (set-member? ground+ y))]
           [`(syn ,_ let ,x (syn ,_ ,name ,args ...)) (subset? (list->set args) ground+)]
           [_ #f]))
       (define ins-special (filter ground-special? rem-special))
       (define rem-special+ (filter (not/c ground-special?) rem-special))
       (define (score join-cl)
         (define cl-vars (clause-vars join-cl))
         (define grounded (set-intersect ground+ cl-vars))
         (define newlyread (set-subtract cl-vars grounded))
         (define ground++ (set-union ground+ cl-vars))
         ;; we should experiment; currently scores join clauses based on:
         (+ (* 100 (set-count grounded)) ;; new vars that are already ground
            (* -35 (set-count newlyread)) ;; new vars traversed/read, potential blow up
            (* 20
               (foldl (lambda (cl c) ;; special clauses it enables to run
                        (match cl
                          [(or `(syn ,_ /= ,x ,y) `(syn ,_ ,(? primitive-cmp?) ,x ,y))
                           (if (and (not (and (set-member? ground+ x) (set-member? ground+ y)))
                                    (set-member? ground++ x)
                                    (set-member? ground++ y))
                               (add1 c)
                               c)]
                          [_ c]))
                      0
                      special-cls))))
       (define (pick-next rems)
         (define ready (filter (lambda (cl) (join-ready? cl ground+)) rems))
         (cond
           [(null? ready)
            (if (null? rems)
                #f
                (error 'plan-rule
                       "no join clauses are ready after satisfying specials; remaining: ~a"
                       rems))]
           [else (first (sort ready > #:key score))]))
       (if (special-cl? this)
           (if (null? ins-special)
               (if (null? rem-bodys)
                   (list this)
                   (let ([next (pick-next rem-bodys)])
                     (if next
                         (cons this (plan-body-with next rem-bodys rem-special+ ground+))
                         (list this))))
               (cons this
                     (plan-body-with (car ins-special)
                                     rem-bodys
                                     (append (cdr ins-special) rem-special+)
                                     ground+)))
           (let ([rem-bodys+ (filter (lambda (x) (not (eq? x this))) rem-bodys)])
             (if (null? ins-special)
                 (if (null? rem-bodys+)
                     (list this)
                     (let ([next (pick-next rem-bodys+)])
                       (if next
                           (cons this (plan-body-with next rem-bodys+ rem-special+ ground+))
                           (list this))))
                 (cons this
                       (plan-body-with (car ins-special)
                                       rem-bodys+
                                       (append (cdr ins-special) rem-special+)
                                       ground+))))))

     ;; Select only head clauses that do not depend upon other head clauses
     (define ((in-scope? vars) cl)
       (subset? (clause-req-vars cl) vars))
     (define (add-head-ids cl st)
       (match cl
         [`(syn ,_ = ,x ,_) (set-add st x)]
         [_ st]))
     (define head-new-ids (foldl add-head-ids (set) heads+))
     (define immediate
       (filter (lambda (cl)
                 (if (equal? (third cl) '=)
                     (set-empty? (set-intersect head-new-ids
                                                (set-subtract (clause-vars cl) (set (fourth cl)))))
                     (set-empty? (set-intersect head-new-ids (clause-vars cl)))))
               heads+))
     (define residual-heads (filter (lambda (cl) (not (member cl immediate))) heads+))
     (define residual-bodys (filter (lambda (cl) (eq? (third cl) '=)) immediate))
     (define all-res-vars
       (foldl set-union (set) (map clause-vars (append residual-bodys residual-heads))))
     (define all-res-reqs (set-subtract all-res-vars head-new-ids))

     ;; Recur to generate subrules for heads:
     (match-define (cons defs rel-env) defs+relenv)
     (match-define (list defs+ rel-env+ immediate-heads)
       (if (null? residual-heads)
           (list defs rel-env immediate)
           (let* ([tempname (gensymb 'headtemp)]
                  [vars (set-subtract all-res-reqs const-vars)]
                  [ordvars (set->list vars)])
             (match-define (cons defs+ rel-env+)
               (plan-rule `(syn ,prov
                                rule
                                ;; include the needed constants and specials
                                ,@(filter (in-scope? all-res-vars) (append special-cls const-cls))
                                ;; the residual head is triggered by tuples in tempname
                                ;; joined with the ids for new structs in immediate head
                                ,@(if (set-empty? vars)
                                      '()
                                      `((syn ,prov ,tempname ,@ordvars)))
                                ,@residual-bodys
                                -->
                                ,@residual-heads)
                          (cons defs rel-env)))
             (if (set-empty? vars)
                 (list defs+ rel-env+ immediate)
                 (list defs+
                       ;; The temp physically carries one column per ordvar; it
                       ;; MUST record that arity so the daemon strides its delta
                       ;; correctly (arity 0 here = infinite loop in reorgDelta).
                       (hash-set rel-env+ tempname `(temp ,(length ordvars)))
                       (cons `(syn ,prov ,tempname ,@ordvars) immediate))))))

     ;; Generate the immediate rule
     (define (let-cl? cl)
       (match cl
         [`(syn ,_ let ,x ,rhs) #t]
         [_ #f]))
     (define (const->let cl)
       (match cl
         [`(syn ,prov = ,x ,rhs) `(syn ,prov let ,x ,rhs)]))
     (define immediate-vars
       (foldl set-union const-vars (map clause-vars (append join-cls immediate-heads))))
     (define immediate-const-cls (filter (in-scope? immediate-vars) const-cls))
     (define immediate-special-cls (filter (in-scope? immediate-vars) special-cls))
     (define immediate-head-lets (filter let-cl? immediate-heads))
     (define (order-head-lets
              rem
              [ground
               (apply set-union `(,const-vars ,@(map clause-vars (append join-cls special-cls))))])
       (match-define (cons avail unavail)
         (foldl (lambda (cl acc)
                  (match-define (cons avail unavail) acc)
                  (match cl
                    [`(syn ,_ let ,x ,(? symbol? y))
                     #:when (set-member? ground y)
                     (cons (cons cl avail) unavail)]
                    [`(syn ,_ let ,x (syn ,_ ,name ,args ...))
                     #:when (subset? (list->set args) ground)
                     (cons (cons cl avail) unavail)]
                    [_ (cons avail (cons cl unavail))]))
                (cons '() '())
                rem))
       (if (null? rem)
           '() ;; Places head lets into order
           `(,@avail ,@(order-head-lets unavail
                                        (apply set-union `(,ground ,@(map clause-vars avail)))))))
     (define immediate-head-ord-lets (order-head-lets immediate-head-lets))
     (define immediate-heads+ (filter (not/c let-cl?) immediate-heads))
     (define temp-bodys
       (filter (lambda (cl)
                 (match cl
                   [`(syn ,_ ,nm ,_ ...)
                    (let ([nmstr (symbol->string nm)])
                      (and (> (string-length nmstr) 8) (equal? "headtemp" (substring nmstr 0 8))))]
                   [_ #f]))
               join-cls))
     (define temp-body-ready?
       (and (= 1 (length temp-bodys)) (join-ready? (car temp-bodys) const-vars)))
     (if (null? join-cls)
         ;; an empty body is true: add a fact rule
         (cons (set-add defs+
                        `(syn ,prov
                              rule
                              ;; put constants at the top as lets
                              ,@(map const->let immediate-const-cls)
                              ,@
                              (let* ([lst (filter (in-scope? immediate-vars) immediate-special-cls)])
                                (if (null? lst)
                                    '()
                                    (plan-body-with (car lst)
                                                    '()
                                                    (filter (lambda (cl) (not (eq? cl (car lst))))
                                                            special-cls)
                                                    const-vars)))
                              -->
                              ,@immediate-head-ord-lets
                              ,@immediate-heads+))
               rel-env+)
         (if temp-body-ready?
             ;; or, if a temporary initiates the head subrule, generate a single plan starting there
             (cons (set-add defs+
                            `(syn ,prov
                                  rule
                                  ;; put constants at the top as lets
                                  ,@(map const->let immediate-const-cls)
                                  ,@(plan-body-with (car temp-bodys) join-cls special-cls const-vars)
                                  -->
                                  ,@immediate-head-ord-lets
                                  ,@immediate-heads+))
                   rel-env+)
             ;; add one def for each body join cl (static vs dyn is differentiated later)
             (let ([initial-join-cls (filter (lambda (cl) (join-ready? cl const-vars)) join-cls)])
               (cons (foldl (lambda (cl defs)
                              (set-add defs
                                       `(syn ,prov
                                             rule
                                             ;; put constants at the top as lets
                                             ,@(map const->let immediate-const-cls)
                                             ,@(plan-body-with cl join-cls special-cls const-vars)
                                             -->
                                             ,@immediate-head-ord-lets
                                             ,@immediate-heads+)))
                            defs+
                            initial-join-cls)
                     rel-env+))))]))
