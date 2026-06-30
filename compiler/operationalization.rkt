#lang racket

(require "utils.rkt")

(provide globalize-constants
         type-select-sets
         add-select-sets
         add-c-rule
         make-rel-decls
         escape-all-ids-for-C)

(define (clause-vars cl)
  (match cl
    [`(syn ,_ /= ,x ,y) (set x y)]
    [`(syn ,_ let ,x ,(? symbol? y)) (set x y)]
    [`(syn ,_ let ,x (syn ,_ ,name ,args ...)) (list->set `(,x ,@args))]
    [`(syn ,_ = ,x (syn ,_ const ,_)) (set x)]
    [`(syn ,_ = ,x (syn ,_ ,name ,xs ...)) (list->set `(,x ,@xs))]
    [`(syn ,_ ,name ,xs ...) (list->set xs)]))

(define (globalize-constants rules)
  (define (gen v constants)
    (hash-ref constants v (lambda () (gensymb 'const))))
  (foldl (lambda (rule acc)
           (match-define (cons constants rules-st) acc)
           (match-define (cons constants+ rule+)
             (foldr (lambda (cl acc)
                      (match-define (cons constants rule+) acc)
                      (match cl
                        [`(syn ,prov let ,x (syn ,_ const ,v))
                         (define constants+ (hash-set constants v (gen v constants)))
                         (cons constants+ (cons `(syn ,prov let ,x ,(gen v constants+)) rule+))]
                        [_ (cons constants (cons cl rule+))]))
                    (cons constants '())
                    rule))
           (cons constants+ (set-add rules-st rule+)))
         (cons (hash) (set))
         rules))

(define (type-select-sets rel-env)
  (foldl (lambda (name ss)
           (match (hash-ref rel-env name)
             [`(struct ,xs ...)
              (hash-set ss
                        name
                        ;; structs must have an interning index and a lookup index (resp.)
                        (set `(,(list->set (range 1 (add1 (length xs)))) ,(set 0))
                             `(,(set 0) ,(list->set (range 1 (add1 (length xs)))))))]
             ;; tables must have *some* index
             [`(table ,xs ...) (hash-set ss name (set `(,(set) ,(list->set (range (length xs))))))]
             [`(temp ,_) ss]
             [`(enum ,_) ss])) ;; temp rels do not have an index
         (hash)
         (hash-keys rel-env)))

(define (add-select-sets rule ss)
  (match rule
    [`(syn ,_ rule ,bodys ... --> ,heads ...)
     (last
      (foldl
       (lambda (cl acc)
         (match-define (list ground not-first? ss) acc)
         (define (select-set tup)
           (define sel
             (list->set (filter (lambda (i) (set-member? ground (list-ref tup i)))
                                (range (length tup)))))
           (define nsel
             (list->set (filter (lambda (i) (not (set-member? sel i))) (range (length tup)))))
           `(,sel ,nsel))
         (match cl
           [`(syn ,_ /= ,x ,y) (list (set-union ground (clause-vars cl)) not-first? ss)]
           [`(syn ,_ let ,x ,(? symbol? y)) (list (set-add ground x) not-first? ss)]
           [`(syn ,_ = ,x (syn ,_ ,name ,xs ...))
            (if (or not-first? (set-empty? (set-intersect (list->set xs) ground)))
                (list (set-union ground (clause-vars cl))
                      #t
                      (hash-set ss name (set-add (hash-ref ss name set) (select-set (cons x xs)))))
                ;; or, if first, and has variables grounded, delta index:
                (list (set-union ground (clause-vars cl))
                      #t
                      (hash-set ss
                                `(delta ,name)
                                (set-add (hash-ref ss `(delta name) set) (select-set (cons x xs))))))]
           [`(syn ,_ ,name ,xs ...)
            (if (or not-first? (set-empty? (set-intersect (list->set xs) ground)))
                (list (set-union ground (clause-vars cl))
                      #t
                      (hash-set ss name (set-add (hash-ref ss name set) (select-set xs))))
                ;; or, if first, and has variables grounded, delta index:
                (list (set-union ground (clause-vars cl))
                      #t
                      (hash-set ss
                                `(delta ,name)
                                (set-add (hash-ref ss `(delta name) set) (select-set xs)))))]))
       (list (set) #f ss)
       bodys))]))

(define (make-rel-decls rel-env indices)
  (map (lambda (name)
         (define typ (hash-ref rel-env name))
         (define myindices (hash-ref indices name set))
         (define mydeltaindices (hash-ref indices `(delta ,name) set))
         (match typ
           [`(struct ,_ ...)
            (let* ([master (filter (lambda (i) (= 0 (last i))) (set->list myindices))]
                   [lookup (filter (lambda (i) (= 0 (first i))) (set->list myindices))])
              (when (null? master)
                (error (format "~a has no interning index!" name)))
              (when (null? lookup)
                (error (format "~a has no lookup index!" name)))
              (define otherind (set-subtract myindices (set (car master) (car lookup))))
              `(struct ,name ,(length typ)
                 ,(car master)
                 ,(car lookup)
                 ,@(set->list otherind)
                 ,@(map (lambda (ind) `(delta ,@ind)) (set->list mydeltaindices))))]
           [`(table ,_ ...)
            `(relation ,name
                       ,(- (length typ) 1)
                       ,@(set->list myindices)
                       ,@(map (lambda (ind) `(delta ,@ind)) (set->list mydeltaindices)))]
           [`(temp ,arity) `(temp ,name ,arity)]))
       (filter (lambda (k) (not (eq? 'enum (first (hash-ref rel-env k))))) (hash-keys rel-env))))

(define ((add-c-rule rel-env indices) rule rules)
  (define (ordered-clause name ind tup)
    (define ord-tup (map (lambda (p) (list-ref tup p)) ind))
    `(,name ,ind ,@ord-tup))
  (define (add-head head heads)
    (match head
      [`(syn ,_ let ,x (syn ,_ ,name ,args ...)) (cons `(let ,x (,name ,@args)) heads)]
      [`(syn ,_ == ,x ,y) (cons `(== ,x ,y) heads)]
      [`(syn ,_ = ,x (syn ,_ ,name ,xs ...))
       (define ind-lst (filter (lambda (i) (= 0 (last i))) (set->list (hash-ref indices name set))))
       (when (null? ind-lst)
         (error "No struct index found"))
       (define ord-cl (ordered-clause name (car ind-lst) (cons x xs)))
       (cons `(= ,x ,(take ord-cl (sub1 (length ord-cl)))) heads)]
      [`(syn ,_ ,name ,xs ...)
       #:when (match (hash-ref rel-env name (lambda () #f))
                [`(temp ,_) #t]
                [_ #f])
       (cons `(,name () ,@xs) heads)]
      [`(syn ,_ ,name ,xs ...)
       (when (set-empty? (hash-ref indices name set))
         (error "No rel index found"))
       (define ind (set-first (hash-ref indices name)))
       (cons (ordered-clause name ind xs) heads)]))
  (define (add-body body acc)
    (match-define (list bodys ground hit-first-read?) acc)
    (define (emit-join-with name tup)
      (define join-vars (set-intersect ground (list->set tup)))
      (if (and (not hit-first-read?) (set-empty? join-vars))
          (list (cons `(read_delta ,name ,@tup) bodys) (set-union ground (list->set tup)) #t)
          (let ([ind-lst (filter (lambda (i)
                                   (let* ([ordvars (map (lambda (n) (list-ref tup n)) i)])
                                     (equal? (list->set (take ordvars (set-count join-vars)))
                                             join-vars)))
                                 (set->list (hash-ref indices
                                                      (if hit-first-read?
                                                          name
                                                          `(delta ,name))
                                                      set)))])
            (when (null? ind-lst)
              (error "No index found!"))
            (define ind (car ind-lst))
            (list (cons `(join_with ,@(if hit-first-read?
                                          '()
                                          '(delta))
                                    ,@(ordered-clause name ind tup))
                        bodys)
                  (set-union ground (list->set tup))
                  #t))))
    (match body
      [`(syn ,_ /= ,x ,y) (list (cons `(/= ,x ,y) bodys) ground hit-first-read?)]
      [`(syn ,_ let ,x ,(? symbol? y))
       (list (cons `(let ,x ,y) bodys) (set-add ground x) hit-first-read?)]
      [`(syn ,_ let ,x (syn ,_ ,name ,args ...))
       (list (cons `(let ,x (,name ,@args)) bodys) (set-add ground x) hit-first-read?)]
      [`(syn ,_ = ,x (syn ,_ ,name ,xs ...)) (emit-join-with name (cons x xs))]
      [`(syn ,_ ,name ,xs ...) (emit-join-with name xs)]
      [_ (cons (cons body bodys) ground)]))
  (match rule
    [`(syn ,_ rule ,bodys ... --> ,heads ...)
     (match-define (list bodys+ ground _) (foldl add-body (list '() (set) #f) bodys))
     (match-define heads+ (foldr add-head '() heads))
     (cons `(crule ,@(reverse bodys+) --> ,@heads+) rules)]))

(define (escape-all-ids-for-C e)
  (match e
    [(? symbol?)
     #:when (regexp-match #px"^_t" (symbol->string e))
     e]
    [(or '--> '= '/= '== 'join_with 'read_delta) e]
    [(? list? lst) (map escape-all-ids-for-C lst)]
    [(? symbol? x) (escape-id-for-C x)]
    [_ e]))
