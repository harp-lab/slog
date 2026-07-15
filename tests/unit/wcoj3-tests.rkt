#lang racket

(module+ test
  (require rackunit
           racket/file
           racket/list
           "../../compiler/params.rkt"
           "../../compiler/modules.rkt"
           "../../compiler/simplification.rkt"
           "../../compiler/type-system.rkt"
           "../../compiler/stratify.rkt"
           "../../compiler/join-actions.rkt"
           "../../compiler/join-planning.rkt"
           "../../compiler/operationalization.rkt"
           "../../compiler/ir-shared.rkt"
           "../../compiler/ir-stack.rkt")

  (define (compile-source src finish)
    (define f (make-temporary-file "wcoj3-test-~a.slog"))
    (dynamic-wind
     void
     (lambda ()
       (with-output-to-file f #:exists 'replace (lambda () (display src)))
       (match-define `((program ,type-env ,mods ,_ ,_))
         (load-program-list (path->string f) (hash)))
       (define all-rules (foldl set-union (set) (map last (set->list mods))))
       (define typed
         (typecheck-rules type-env
                          (foldl simplify-rule (set) (set->list all-rules))))
       (for/list ([stratum (in-list (stratify-rules typed))])
         (define rules (stratum-rules stratum))
         (define dynamic-rels
           (for/fold ([acc (set)]) ([rule (in-set rules)])
             (set-union acc (rule-head-rels rule))))
         (match-define (cons planned rel-env+)
           (plan-stratum rules (type-env-rels type-env) dynamic-rels))
         (finish planned rel-env+)))
     (lambda () (delete-file f))))

  (define (cprogs-of src)
    (compile-source src build-cprog))

  (define (planned-rules-of src)
    (append* (compile-source src (lambda (planned _) (set->list planned)))))

  (define (all-ops cprogs)
    (for*/list ([cp (in-list cprogs)]
                [cr (in-list (cprog-rules cp))]
                [op (in-list (crule-body cr))])
      op))

  (define (join3s cprogs)
    (filter (lambda (op) (eq? (car op) 'join3)) (all-ops cprogs)))

  (define triangle
    "table (edge int int)
     table (tri int int int)
     rule (edge A B) (edge B C) (edge A C) --> (tri A B C)")

  (test-case "key-simple triangle lowers to one full/full join3"
    (define js (join3s (cprogs-of triangle)))
    (check-equal? (length js) 1)
    (match-define `(join3 ,cycle ,arms ...) (car js))
    (check-equal? (map car arms) '(full full))
    (for ([arm (in-list arms)])
      (match-define `(,_ edge ,ind ,K ,_ ,ys ...) arm)
      (check-equal? K 1)
      (check-equal? (length ys) 2)
      (check-equal? (list-ref ys K) cycle)
      (check-equal? (length ind) 2)))

  (test-case "feature flag preserves the binary plan"
    (parameterize ([wcoj3-enabled #f])
      (define ops (all-ops (cprogs-of triangle)))
      (check-equal? (count (lambda (op) (eq? (car op) 'join3)) ops) 0)
      (check-equal? (count (lambda (op) (eq? (car op) 'join)) ops) 2)))

  (test-case "all triangle source permutations expose one cycle closer"
    (define decls "table (r int int) table (s int int) table (t int int)
                   table (out int int int) rule ")
    (for ([atoms (in-list
                  (permutations '("(r A B)" "(s B C)" "(t A C)")))])
      (define source
        (string-append decls (string-join atoms " ")
                       " --> (out A B C)"))
      (check-equal? (length (join3s (cprogs-of source))) 1
                    (string-join atoms " "))))

  (test-case "closed driver enumeration exposes a two-column-prefix closer"
    (define js
      (join3s
       (cprogs-of
        "table (root int int int int)
         table (left int int int)
         table (right int int int)
         table (out int int int int int)
         rule (left A B C) (right D E C) (root A B D E)
           --> (out A B C D E)")))
    (check-equal? (length js) 1)
    (match-define `(join3 ,cycle ,arms ...) (car js))
    (check-equal? cycle 'C)
    (for ([arm (in-list arms)])
      (match-define `(full ,_ ,ord 2 () ,vars ...) arm)
      (check-equal? (list-ref vars 2) cycle)
      (check-equal? (length ord) 3)))

  (test-case "four-cycle can use a local closer after a scalar prefix"
    (define js
      (join3s
       (cprogs-of
        "table (r int int) table (s int int)
         table (t int int) table (u int int)
         table (out int int int int)
         rule (r A B) (s B C) (t A D) (u D C) --> (out A B C D)")))
    (check-equal? (length js) 1))

  (test-case "one self-joined relation can supply both join3 arms"
    (define js (join3s (cprogs-of triangle)))
    (match-define `(join3 ,_ ,arms ...) (car js))
    (check-equal? (length arms) 2)
    (check-equal? (map second arms) '(edge edge))
    (define planned-actions
      (for*/list ([rule (in-list (planned-rules-of triangle))]
                  [entry (in-list (match rule
                                    [`(syn ,_ ,_ ,body ... --> ,_ ...) body]))]
                  #:when (expand3-action? entry))
        entry))
    (check-equal? (length planned-actions) 1)
    (match-define (list left-id right-id)
      (action-occurrence-ids (car planned-actions)))
    (check-not-equal? left-id right-id))

  (test-case "acyclic shared-anchor lookalike stays scalar"
    (check-equal?
     (join3s
      (cprogs-of
       "table (root int) table (l int int) table (r int int)
        table (out int int)
        rule (root A) (l A C) (r A C) --> (out A C)"))
     '()))

  (test-case "three eligible arms sharing one free key stay scalar"
    (check-equal?
     (join3s
      (cprogs-of
       "table (root int int int)
        table (r int int) table (s int int) table (t int int)
        table (out int int int int)
        rule (root A B D) (r A C) (s B C) (t D C)
          --> (root A B D) (out A B C D)"))
     '()))

  (test-case "body computation uses the conservative scalar fallback"
    (check-equal?
     (join3s
      (cprogs-of
       "table (r int int) table (s int int) table (t int int)
        table (out int int int int)
        rule (r A B) (s B C) (t A C) (= X (+ A B)) --> (out A B C X)"))
     '()))

  (test-case "search cap falls back without changing rule validity"
    (parameterize ([wcoj3-search-cap 2])
      (check-equal? (join3s (cprogs-of triangle)) '())))

  (test-case "payload arm is outside key-simple scope"
    (define js
      (join3s
       (cprogs-of
        "table (r int int int)
         table (s int int int)
         table (t int int int)
         table (out int int int int int int)
         rule (r A B X) (s B C Y) (t A C Z) --> (out A B C X Y Z)")))
    (check-equal? js '()))

  (define recursive-triangle
    "table (edge int int)
     rule (edge A B) (edge B C) (edge A C) --> (edge C A)")

  (define (view-signatures cprogs)
    (sort
     (for/list ([j (in-list (join3s cprogs))])
       (sort (map car (cddr j)) symbol<?))
     string<? #:key (lambda (xs) (string-join (map symbol->string xs) "/"))))

  (test-case "positive exact versions preserve full/old occurrence views"
    (define cprogs (cprogs-of recursive-triangle))
    (check-equal? (view-signatures cprogs)
                  '((full full) (full old) (old old)))
    (for* ([j (in-list (join3s cprogs))]
           [arm (in-list (cddr j))]
           #:when (eq? (car arm) 'old))
      (check-equal? (third arm) (fifth arm)
                    "OLD arm uses one complete FULL/DELTA ordering")))

  (test-case "negative exact versions preserve full/new occurrence views"
    (parameterize ([maintenance-flavor 'negative])
      (define cprogs (cprogs-of recursive-triangle))
      (check-equal? (view-signatures cprogs)
                    '((full full) (full new) (new new)))
      (for* ([j (in-list (join3s cprogs))]
             [arm (in-list (cddr j))]
             #:when (eq? (car arm) 'new))
        (check-equal? (third arm) (fifth arm)
                      "NEW arm uses one complete FULL/DELTA ordering"))))

  (test-case "count flavor retains one all-FULL cycle action"
    (parameterize ([count-flavor (count-mode (set 'tri) (make-hash))])
      (check-equal? (view-signatures (cprogs-of triangle))
                    '((full full))))))
