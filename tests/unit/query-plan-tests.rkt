#lang racket

;; Pure Q1 catalog planner battery.  These tests deliberately stop at the
;; executable-plan boundary: the daemon binding/execution differential lives
;; in tests/interp-operator-tests.cpp.

(module+ test
  (require rackunit
           racket/file
           racket/match
           racket/runtime-path
           "../../compiler/query-plan.rkt")

  (define-runtime-path wire-fixture "../data/q1-catalog-query.plan")

  (define (relation name types orders count)
    (query-relation name (format "version/~a" name) 'plain
                    types orders count))

  (define (catalog . relations)
    (query-catalog
     'boundary/7 42
     (for/hash ([value (in-list relations)])
       (values (query-relation-name value) value))))

  (define (integer text) (query-literal 'integer text))
  (define (string text) (query-literal 'string text))

  (define (request atoms
                   #:guards [guards '()]
                   #:computes [computes '()]
                   #:project [project '(x)]
                   #:mode [mode 'rows])
    (query-request mode atoms guards computes project))

  (define (degradation-kinds plan)
    (map query-degradation-kind
         (query-explain-degradations (query-plan-explain plan))))

  (define (failure-kind thunk)
    (with-handlers ([exn:fail:query-plan?
                     (lambda (failure)
                       (exn:fail:query-plan-kind failure))])
      (thunk)
      #f))

  (test-case "small literal relation drives reverse-index joins deterministically"
    (define cat
      (catalog
       (relation 'edge '(int int) '((0 1) (1 0)) 1000000)
       (relation 'label '(int str) '((0 1)) 100)))
    (define query
      (request
       (list (query-atom 'label (list 'z (string "hot")) #f)
             (query-atom 'edge '(y z) #f)
             (query-atom 'edge '(x y) #f))
       #:guards (list (query-guard 'neq 'x 'z))
       #:project '(x z)))
    (define plan (plan-query cat query))

    (check-equal? (map query-binding-name (query-plan-bindings plan))
                  '(edge label))
    (check-equal? (query-explain-driver (query-plan-explain plan)) 'label)
    (check-equal? (qp-driver-relation (query-plan-driver plan)) 1)
    (check-equal? (qp-driver-order (query-plan-driver plan)) '())
    (check-equal? (map qp-literal-kind (query-plan-literals plan))
                  '(string))
    (check-match (query-plan-body plan)
                 (list (qp-eq _ _)
                       (qp-probe 0 '(1 0) 1 _)
                       (qp-probe 0 '(1 0) 1 _)
                       (qp-neq _ _)))
    (check-equal? (query-plan-project plan) '(3 0))
    (check-equal? (degradation-kinds plan) '(scan-plus-filter))
    (check-equal? (query-plan->datum plan)
                  (query-plan->datum (plan-query cat query))))

  (test-case "missing reverse index changes driver and explains join order"
    (define cat
      (catalog
       (relation 'edge '(int int) '((0 1)) 1000000)
       (relation 'label '(int str) '((1 0)) 10)))
    (define plan
      (plan-query
       cat
       (request
        (list (query-atom 'label (list 'c (string "hot")) #f)
              (query-atom 'edge '(y z) #f)
              (query-atom 'edge '(x y) #f))
        #:project '(x c))))

    (check-equal? (query-explain-driver (query-plan-explain plan)) 'edge)
    (check-equal? (qp-driver-order (query-plan-driver plan)) '(0 1))
    (check-equal? (first (degradation-kinds plan)) 'join-order)
    (check-match
     (query-degradation-detail
      (first (query-explain-degradations (query-plan-explain plan))))
     (list 'smallest-driver 'label
           'smallest-size 10
           'chosen-size 1000000
           'reason 'existing-index-prefixes)))

  (test-case "Cartesian body atom uses an existing-index full scan"
    (define cat
      (catalog
       (relation 'a '(int int) '((0 1)) 10)
       (relation 'b '(int int) '((0 1)) 10)))
    (define plan
      (plan-query
       cat
       (request
        (list (query-atom 'a '(u x) #f)
              (query-atom 'b '(v x) #f)))))
    (check-equal? (query-explain-driver (query-plan-explain plan)) 'a)
    (check-match (query-plan-body plan)
                 (list (qp-probe 1 '(0 1) 0 (list _ _))
                       (qp-eq _ 1)))
    (check-equal? (degradation-kinds plan) '(scan-plus-filter))
    (check-match
     (query-degradation-detail
      (first (query-explain-degradations (query-plan-explain plan))))
     (list 'position 'body
           'reason 'no-positive-index-prefix
           'post-scan-equalities 1)))

  (test-case "cyclic compute dataflow is a structured refusal"
    (check-equal?
     (failure-kind
      (lambda ()
        (plan-query
         (catalog (relation 'seed '(int) '((0)) 1))
         (request
          (list (query-atom 'seed '(x) #f))
          #:computes
          (list (query-compute 'total 'tofloat 'y '(z))
                (query-compute 'total 'tofloat 'z '(y)))
          #:project '(y)))))
     'no-feasible-schedule))

  (test-case "probe suffix constraints lower to equality filters"
    (define plan
      (plan-query
       (catalog
        (relation 'seed '(int) '((0)) 1)
        (relation 'target '(int int int) '((0 1 2)) 1600))
       (request
        (list (query-atom 'seed '(x) #f)
              (query-atom 'target '(x y x) #f))
        #:project '(x y))))

    (check-match (query-plan-body plan)
                 (list (qp-probe 1 '(0 1 2) 1 (list 0 1 _))
                       (qp-eq _ 0)))
    (check-equal? (degradation-kinds plan) '(probe-plus-filter))
    (check-match
     (query-degradation-detail
      (first (query-explain-degradations (query-plan-explain plan))))
     (list 'index-prefix 1 'post-probe-equalities 1)))

  (test-case "repeated driver variables use scan-plus-filter"
    (define plan
      (plan-query
       (catalog (relation 'same '(int int) '((0 1)) 5))
       (request (list (query-atom 'same '(x x) #f)))))
    (check-equal? (qp-driver-order (query-plan-driver plan)) '())
    (check-match (query-plan-body plan) (list (qp-eq _ 0)))
    (check-equal? (degradation-kinds plan) '(scan-plus-filter)))

  (test-case "guards and audited computes close as soon as inputs are ground"
    (define plan
      (plan-query
       (catalog (relation 'nums '(int) '((0)) 4))
       (request
        (list (query-atom 'nums '(x) #f))
        #:guards (list (query-guard 'lt 'x (integer "10")))
        #:computes (list (query-compute 'total 'tofloat 'y '(x)))
        #:project '(y))))

    (check-match
     (query-plan-body plan)
     (list (qp-prim 'guard "lt" 0 (list 0 _))
           (qp-prim 'total "tofloat" 1 '(0))))
    (check-equal? (query-plan-project plan) '(1)))

  (test-case "literal-only compute is a preop and constrains the driver"
    (define plan
      (plan-query
       (catalog (relation 'pair '(float int) '((0 1)) 4))
       (request
        (list (query-atom 'pair '(y x) #f))
        #:computes
        (list (query-compute 'total 'tofloat 'y (list (integer "2"))))
        #:project '(x))))

    (check-match (query-plan-preops plan)
                 (list (qp-prim 'total "tofloat" 0 (list 2))))
    (check-equal? (qp-driver-order (query-plan-driver plan)) '())
    (check-match (query-plan-body plan) (list (qp-eq _ 0))))

  (test-case "fully bound negative atom lowers to snapshot absence"
    (define plan
      (plan-query
       (catalog
        (relation 'banned '(int) '((0)) 2)
        (relation 'seed '(int) '((0)) 5))
       (request
        (list (query-atom 'seed '(x) #f)
              (query-atom 'banned '(x) #t)))))

    (check-match (query-plan-body plan)
                 (list (qp-filter 'absent 0 '(0) 1 '(0)))))

  (test-case "unsafe dataflow, types, and computes fail before scheduling"
    (define cat
      (catalog
       (relation 'ints '(int) '((0)) 2)
       (relation 'strings '(str) '((0)) 2)))
    (check-equal?
     (failure-kind
      (lambda ()
        (plan-query
         cat
         (request
          (list (query-atom 'ints '(x) #f)
                (query-atom 'strings '(s) #f)
                (query-atom 'strings '(z) #t))))))
     'unsafe-negation)
    (check-equal?
     (failure-kind
      (lambda ()
        (plan-query
         cat
         (request
          (list (query-atom 'ints '(x) #f)
                (query-atom 'strings '(s) #f))
          #:guards (list (query-guard 'eq 'x 's))))))
     'type)
    (check-equal?
     (failure-kind
      (lambda ()
        (plan-query
         cat
         (request
          (list (query-atom 'ints '(x) #f))
          #:computes (list (query-compute 'total '_0002b 'y '(x x)))))))
     'unsafe-compute))

  (test-case "catalog snapshot validation rejects missing physical orders"
    (check-equal?
     (failure-kind
      (lambda ()
        (plan-query
         (catalog (relation 'empty '(int) '() 0))
         (request (list (query-atom 'empty '(x) #f))))))
     'catalog))

  (test-case "boundary adapter retains empty storage declarations"
    (define boundary
      (query-boundary
       "boundary/empty" 9
       (hash 'empty (query-declaration 'empty 'table '(int))
             'UserId (query-declaration 'UserId 'type '()))
       (hash 'empty "version/empty")
       (hash "version/empty"
             (query-materialization
              "version/empty" 'plain 1 '((0)) 0))))
    (define cat (query-catalog-from-boundary boundary))
    (check-equal? (query-catalog-boundary-key cat) "boundary/empty")
    (check-true (hash-has-key? (query-catalog-relations cat) 'empty))
    (check-equal?
     (query-relation-tuple-count
      (hash-ref (query-catalog-relations cat) 'empty))
     0)
    (check-false (hash-has-key? (query-catalog-relations cat) 'UserId)))

  (test-case "boundary adapter rejects declaration/materialization drift"
    (check-equal?
     (failure-kind
      (lambda ()
        (query-catalog-from-boundary
         (query-boundary
          "boundary/bad" 10
          (hash 'edge (query-declaration 'edge 'table '(int int)))
          (hash 'edge "version/edge")
          (hash "version/edge"
                (query-materialization
                 "version/edge" 'plain 1 '((0)) 0))))))
     'catalog))

  (test-case "catalog planner emits the frozen QueryPlan payload"
    (define boundary
      (query-boundary
       "boundary/7" 42
       (hash 'edge (query-declaration 'edge 'table '(int int)))
       (hash 'edge "version/edge")
       (hash "version/edge"
             (query-materialization
              "version/edge" 'plain 2 '((0 1) (1 0)) 6))))
    (define plan
      (plan-query
       (query-catalog-from-boundary boundary)
       (request
        (list (query-atom 'edge (list 'x (integer "2")) #f)))))
    ;; The fixture's trailing LF is part of the checked-in file, not the
    ;; payload returned to the future dispatcher.
    (check-equal? (string-append (query-plan->wire-string plan) "\n")
                  (file->string wire-fixture))))
