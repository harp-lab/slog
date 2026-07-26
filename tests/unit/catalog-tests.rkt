#lang racket

(module+ test
  (require rackunit
           racket/file
           racket/set
           "../../compiler/catalog.rkt"
           "../../compiler/ir-shared.rkt"
           "../../compiler/names.rkt"
           (only-in "../../compiler/modules.rkt" load-program-list))

  (define (Q name) (symbol->qname name))
  (define I (type-ref 'primitive 'int))
  (define F (type-ref 'primitive 'float))
  (define (N name) (type-ref 'named (Q name)))
  (define (D name kind [fields '()] [lattice #f])
    (declaration-descriptor (Q name) kind fields lattice))
  (define (Delta descriptors [memberships (set)])
    (catalog-delta
     (for/hash ([descriptor (in-list descriptors)])
       (values (declaration-descriptor-name descriptor) descriptor))
     memberships))
  (define (action-for plan name)
    (for/first ([action (in-list (boundary-plan-actions plan))]
                #:when
                (qname=? (Q name) (boundary-action-name action)))
      action))

  (test-case "type environments normalize one exact catalog graph"
    (define type-env
      (list
       (hash 'Maybe (set 'Maybe 'Node))
       (hash 'Node '(struct int)
             'edge '(table Node Node)
             'cost '(lattice min int (floor 0))
             'dist '(table Node cost))
       (hash)))
    (define delta (type-env->catalog-delta type-env))
    (define declarations (catalog-delta-declarations delta))
    (check-equal?
     (hash-ref declarations (Q 'Node))
     (D 'Node 'struct (list I)))
    (check-equal?
     (declaration-descriptor-fields (hash-ref declarations (Q 'edge)))
     (list (N 'Node) (N 'Node)))
    (check-equal?
     (declaration-descriptor-lattice-spec
      (hash-ref declarations (Q 'dist)))
     (lattice-descriptor
      'min (list I) (list (cons 'floor 0))))
    (check-true
     (set-member? (catalog-delta-memberships delta)
                  (cons (Q 'Node) (Q 'Maybe))))
    (check-equal?
     (catalog-delta->manifest delta)
     (hash 'Node '(struct Node 2)
           'edge '(rel edge 2)
           'dist '(lat dist 2 (lattice min int (floor 0))))))

  (test-case "an initial plan allocates empty members and sorted stable slots"
    (define proposed
      (Delta
       (list (D 'z 'table (list I))
             (D 'a 'table (list I))
             (D 'm.S 'struct (list I)))))
    (define plan
      (plan-boundary
       (empty-boundary "b0")
       proposed
       '()
       #:layer-id "L"
       #:program-event 3
       #:boundary-event 7))
    (check-equal? (boundary-plan-program-key plan) "p1:L:3")
    (check-equal? (boundary-plan-boundary-key plan) "b1:L:7")
    (check-equal?
     (boundary-plan-version-slots plan)
     (hash (Q 'a) 0 (Q 'm.S) 1 (Q 'z) 2))
    (check-equal?
     (boundary-plan-type-slots plan)
     (hash (Q 'm.S) 0))
    (define out (boundary-plan-output plan))
    (check-equal?
     (boundary-environment out)
     (hash (Q 'a) "v1:L:7:0"
           (Q 'm.S) "v1:L:7:1"
           (Q 'z) "v1:L:7:2"))
    (check-equal?
     (catalog-nominals (boundary-catalog out))
     (hash (Q 'm.S) "t1:L:7:0"))
    (check-equal?
     (map boundary-action-kind (boundary-plan-actions plan))
     '(create create create))
    (for ([action (in-list (boundary-plan-actions plan))])
      (check-false (boundary-action-predecessor action))))

  (test-case "compatible overlap retains, writes succeed, and additions start once"
    (define initial-delta
      (Delta
       (list (D 'z 'table (list I))
             (D 'a 'table (list I))
             (D 'm.S 'struct (list I)))))
    (define first-plan
      (plan-boundary
       (empty-boundary)
       initial-delta
       '()
       #:layer-id "L"
       #:program-event 0
       #:boundary-event 0))
    ;; The program deliberately omits a and m.S.  Omission is not a drop.
    (define second-plan
      (plan-boundary
       (boundary-plan-output first-plan)
       (Delta (list (D 'z 'table (list I))
                    (D 'c 'table (list I))))
       '(z c)
       #:layer-id "L"
       #:program-event 1
       #:boundary-event 1))
    (check-equal?
     (boundary-plan-version-slots second-plan)
     (hash (Q 'c) 0 (Q 'z) 1))
    (check-equal? (hash-count (boundary-plan-type-slots second-plan)) 0)
    (check-equal?
     (hash-keys (catalog-delta-declarations
                 (boundary-plan-delta second-plan)))
     (list (Q 'c)))
    (define c-action (action-for second-plan 'c))
    (check-equal? (boundary-action-kind c-action) 'create)
    (check-false (boundary-action-predecessor c-action))
    (check-equal? (boundary-action-version-key c-action) "v1:L:1:0")
    (define z-action (action-for second-plan 'z))
    (check-equal? (boundary-action-kind z-action) 'create)
    (check-equal? (boundary-action-predecessor z-action) "v1:L:0:2")
    (check-equal? (boundary-action-version-key z-action) "v1:L:1:1")
    (for ([name '(a m.S)])
      (define action (action-for second-plan name))
      (check-equal? (boundary-action-kind action) 'retain))
    (check-equal?
     (hash-ref (boundary-environment (boundary-plan-output second-plan))
               (Q 'a))
     "v1:L:0:0")
    (check-equal?
     (hash-ref (catalog-nominals
                (boundary-catalog (boundary-plan-output second-plan)))
               (Q 'm.S))
     "t1:L:0:0"))

  (test-case "incompatible overlap rejects the whole pure transition"
    (define first-plan
      (plan-boundary
       (empty-boundary)
       (Delta (list (D 'edge 'table (list I I))))
       '()
       #:layer-id "L"
       #:program-event 0
       #:boundary-event 0))
    (define input (boundary-plan-output first-plan))
    (define before-environment (boundary-environment input))
    (define caught
      (with-handlers ([exn:fail:catalog? values])
        (plan-boundary
         input
         (Delta (list (D 'edge 'table (list I F))))
         '(edge)
         #:layer-id "L"
         #:program-event 1
         #:boundary-event 1)
        #f))
    (check-pred exn:fail:catalog? caught)
    (check-equal? (exn:fail:catalog-kind caught)
                  'incompatible-declaration)
    (check-equal? (boundary-environment input) before-environment)
    (check-equal? (boundary-key input) "b1:L:0"))

  (test-case "union membership grows additively"
    (define U (D 'U 'union))
    (define A (D 'A 'enum))
    (define first-plan
      (plan-boundary
       (empty-boundary)
       (Delta (list U A) (set (cons (Q 'A) (Q 'U))))
       '()
       #:layer-id "L"
       #:program-event 0
       #:boundary-event 0))
    (define second-plan
      (plan-boundary
       (boundary-plan-output first-plan)
       (Delta (list U (D 'B 'enum))
              (set (cons (Q 'B) (Q 'U))))
       '()
       #:layer-id "L"
       #:program-event 1
       #:boundary-event 1))
    (define members
      (catalog-memberships
       (boundary-catalog (boundary-plan-output second-plan))))
    (check-true (set-member? members (cons (Q 'A) (Q 'U))))
    (check-true (set-member? members (cons (Q 'B) (Q 'U))))
    (check-equal?
     (catalog-delta-memberships (boundary-plan-delta second-plan))
     (set (cons (Q 'B) (Q 'U)))))

  (test-case "legacy manifest is a one-way catalog projection"
    (define projected
      (catalog-delta->manifest
       (Delta (list (D 'edge 'table (list I I))
                    (D 'Node 'struct (list I))))))
    (check-equal?
     (merge-legacy-manifest (hash 'old '(rel old 1)) projected)
     (hash 'old '(rel old 1)
           'edge '(rel edge 2)
           'Node '(struct Node 2)))
    (check-exn
     (lambda (e)
       (and (exn:fail:catalog? e)
            (eq? 'legacy-manifest-mismatch
                 (exn:fail:catalog-kind e))))
     (lambda ()
       (merge-legacy-manifest
        (hash 'edge '(rel edge 3))
        projected))))

  (test-case "legacy dollar relations stay outside the public QName catalog"
    (define type-env
      (list (hash)
            (hash '$sup1 '(table any int)
                  'edge '(table int int))
            (hash)))
    (define delta (type-env->catalog-delta type-env))
    (check-equal?
     (hash-keys (catalog-delta-declarations delta))
     (list (Q 'edge)))
    (check-equal?
     (type-env->legacy-manifest type-env)
     (hash '$sup1 '(rel $sup1 2)
           'edge '(rel edge 2))))

  (test-case "negative anonymous lattice clamps lower to valid QNames"
    (define source
      "table (floor_value int (min int #:floor -10))")
    (define path (make-temporary-file "catalog-negative-lattice-~a.slog"))
    (dynamic-wind
     void
     (lambda ()
       (call-with-output-file path
         #:exists 'replace
         (lambda (out) (display source out)))
       (match-define `((program ,type-env ,_ ,_ ,_))
         (load-program-list path (hash)))
       (define generated
         (for/first ([name (in-list (hash-keys (type-env-rels type-env)))]
                     #:when
                     (string-prefix? (symbol->string name)
                                     "_lat_min_int_floor_"))
           name))
       (check-equal? generated '_lat_min_int_floor__0002d10)
       (check-not-exn (lambda () (symbol->qname generated)))
       (check-not-exn (lambda () (type-env->catalog-delta type-env))))
     (lambda () (delete-file path))))

  (test-case "boundary recipe codec preserves and audits the exact plan"
    (define delta
      (Delta
       (list (D 'm.edge 'table (list I I))
             (D 'm.Node 'struct (list I)))))
    (check-equal? (datum->catalog-delta (catalog-delta->datum delta))
                  delta)
    (define plan
      (plan-boundary
       (empty-boundary)
       delta
       '(m.edge)
       #:layer-id "recipe-layer"
       #:program-event 4
       #:boundary-event 5
       #:type-event 6))
    (define datum (boundary-plan->datum plan))
    (check-true (boundary-plan-datum? datum))
    (check-equal?
     (boundary-plan->datum
      (replay-boundary-plan (empty-boundary) delta '(m.edge) datum))
     datum)
    (define tampered
      (match datum
        [`(boundary-plan ,layer ,program-event ,boundary-event ,type-event
                         (program-key ,_)
                         ,rest ...)
         `(boundary-plan ,layer ,program-event ,boundary-event ,type-event
                         (program-key "p1:wrong:0")
                         ,@rest)]))
    (check-true (boundary-plan-datum? tampered))
    (check-exn
     (lambda (error)
       (and (exn:fail:catalog? error)
            (eq? 'recipe-plan-mismatch
                 (exn:fail:catalog-kind error))))
     (lambda ()
       (replay-boundary-plan
        (empty-boundary) delta '(m.edge) tampered)))))
