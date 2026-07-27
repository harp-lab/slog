#lang racket

;; N4-B: the pure attachment planner (docs/n4-contract.md §5, work orders 1-2).
;;
;; Every schema, VersionKey, TypeKey, and import decision is made here, before
;; the daemon is contacted at all -- so these cases are the real gate on the
;; mapping rules.  The allocator underneath is `plan-boundary`, unchanged:
;; what is tested is that attachment feeds it the right selection, rewrite,
;; and write set, and refuses everything §5 says it must.

(module+ test
  (require rackunit
           racket/set
           "../../compiler/catalog.rkt"
           "../../compiler/names.rkt")

  (define (Q name) (symbol->qname name))
  (define I (type-ref 'primitive 'int))
  (define S (type-ref 'primitive 'str))
  (define (N name) (type-ref 'named (Q name)))
  (define (D name kind [fields '()] [lattice #f])
    (declaration-descriptor (Q name) kind fields lattice))
  (define (Delta descriptors [memberships (set)])
    (catalog-delta
     (for/hash ([descriptor (in-list descriptors)])
       (values (declaration-descriptor-name descriptor) descriptor))
     memberships))

  ;; A source database with two independent, dependency-closed namespaces and
  ;; one namespace that reaches into another.
  (define source-delta
    (Delta
     (list (D 'app.Node 'struct (list I))
           (D 'app.edge 'table (list (N 'app.Node) (N 'app.Node)))
           (D 'app.empty 'table (list I))
           (D 'app.cost 'lattice '() (lattice-descriptor 'min (list I) '()))
           (D 'app.dist 'table (list (N 'app.Node) (N 'app.cost)))
           (D 'lib.Item 'struct (list S))
           (D 'lib.items 'table (list (N 'lib.Item)))
           (D 'bad.ref 'table (list (N 'app.Node))))))

  (define source-plan
    (plan-boundary (empty-boundary "b0:src") source-delta '()
                   #:layer-id "src" #:program-event 1 #:boundary-event 1))
  (define source-head (boundary-plan-output source-plan))
  (define source-environment (boundary-environment source-head))
  (define source-nominals (catalog-nominals (boundary-catalog source-head)))

  (define source-bundle
    (boundary-bundle
     slog-boundary-bundle-format
     source-head
     (list (boundary-record "b0:src" #f 'initial #f)
           (boundary-record (boundary-key source-head) "b0:src" 'program
                            (boundary-plan->datum source-plan)))
     (for/list ([(name key) (in-hash source-environment)])
       (version-record
        key #f
        (declaration-descriptor-kind
         (hash-ref (catalog-declarations (boundary-catalog source-head)) name))
        name #t))
     (for/list ([(name key) (in-hash source-nominals)]
                [sid (in-naturals 1)])
       (type-record key 2 sid (list name)))
     '()))

  ;; Everything except app.empty carries rows in the source database.
  (define full-content
    (for/set ([name (in-hash-keys source-environment)]
              #:unless (qname=? name (Q 'app.empty)))
      name))

  (define (attach #:source [source #f]
                  #:to destination-path
                  #:into [destination (empty-boundary "b0:dst")]
                  #:content [content full-content]
                  #:event [event 5])
    (plan-attachment source-bundle destination
                     #:source-path source
                     #:destination-path destination-path
                     #:content content
                     #:source-stamp "stamp-src"
                     #:layer-id "dst" #:event event))

  (define (refusal thunk)
    (with-handlers ([exn:fail:catalog? exn:fail:catalog-kind])
      (thunk)
      #f))
  (define (rejects kind thunk) (check-equal? (refusal thunk) kind))

  (define (declared plan)
    (sort (map qname->display
               (hash-keys (catalog-declarations
                           (boundary-catalog (attachment-plan-output plan)))))
          string<?))
  (define (version-of plan name)
    (hash-ref (boundary-environment (attachment-plan-output plan)) (Q name) #f))
  (define (nominal-of plan name)
    (hash-ref (catalog-nominals (boundary-catalog (attachment-plan-output plan)))
              (Q name) #f))
  (define (action-of plan name)
    (for/first ([action (in-list (boundary-plan-actions
                                  (attachment-plan-boundary-plan plan)))]
                #:when (qname=? (Q name) (boundary-action-name action)))
      action))

  ;; -- attaching the saved root -------------------------------------------

  (test-case "the saved root maps under one dotted destination"
    (define plan (attach #:to (Q 'site.a)))
    (check-equal? (declared plan)
                  '("site.a.app.Node" "site.a.app.cost" "site.a.app.dist"
                    "site.a.app.edge" "site.a.app.empty" "site.a.bad.ref"
                    "site.a.lib.Item" "site.a.lib.items"))
    ;; the field graph moved with it, component-wise
    (check-equal?
     (declaration-descriptor-fields
      (hash-ref (catalog-declarations
                 (boundary-catalog (attachment-plan-output plan)))
                (Q 'site.a.app.edge)))
     (list (N 'site.a.app.Node) (N 'site.a.app.Node)))
    ;; attaching the root is always dependency-closed, so bad.ref rides along
    (check-true (and (version-of plan 'site.a.bad.ref) #t)))

  (test-case "a nested dependency-closed subtree maps to a different name"
    (define plan (attach #:source (Q 'app) #:to (Q 'graph)))
    (check-equal? (declared plan)
                  '("graph.Node" "graph.cost" "graph.dist" "graph.edge"
                    "graph.empty"))
    (check-equal?
     (declaration-descriptor-lattice-spec
      (hash-ref (catalog-declarations
                 (boundary-catalog (attachment-plan-output plan)))
                (Q 'graph.cost)))
     (lattice-descriptor 'min (list I) '())))

  (test-case "an escaping dependency is refused"
    (rejects 'escaping-dependency (lambda () (attach #:source (Q 'bad)
                                                     #:to (Q 'here)))))

  (test-case "an escaping membership edge is refused"
    (define delta
      (Delta (list (D 'in.Leaf 'struct (list I))
                   (D 'out.Union 'union))
             (set (cons (Q 'in.Leaf) (Q 'out.Union)))))
    (define plan
      (plan-boundary (empty-boundary "b0:m") delta '()
                     #:layer-id "m" #:program-event 1 #:boundary-event 1))
    (define head (boundary-plan-output plan))
    (define bundle
      (boundary-bundle
       slog-boundary-bundle-format head
       (list (boundary-record (boundary-key head) #f 'initial #f))
       (for/list ([(name key) (in-hash (boundary-environment head))])
         (version-record key #f 'struct name #t))
       (for/list ([(name key) (in-hash (catalog-nominals (boundary-catalog head)))])
         (type-record key 2 1 (list name)))
       '()))
    (rejects 'escaping-dependency
             (lambda ()
               (plan-attachment bundle (empty-boundary "b0:d")
                                #:source-path (Q 'in)
                                #:destination-path (Q 'here)
                                #:layer-id "d" #:event 1))))

  ;; -- versions, types, and the maps ---------------------------------------

  (test-case "an empty member is declared and versioned but never imported"
    (define plan (attach #:source (Q 'app) #:to (Q 'graph)))
    ;; a FRESH destination relation always gets a VersionKey, content or not
    (check-true (and (version-of plan 'graph.empty) #t))
    (check-equal? (boundary-action-kind (action-of plan 'graph.empty)) 'create)
    (check-false
     (for/or ([entry (in-list (attachment-plan-imports plan))])
       (qname=? (cdr entry) (Q 'graph.empty))))
    ;; ... and it still appears in the VersionKey map
    (check-true
     (for/or ([entry (in-list (attachment-plan-version-map plan))])
       (equal? (car entry) (hash-ref source-environment (Q 'app.empty))))))

  (test-case "the maps carry every selected key and reuse no source identity"
    (define plan (attach #:source (Q 'app) #:to (Q 'graph)))
    (check-equal? (map car (attachment-plan-version-map plan))
                  (for/list ([name (in-list '(app.Node app.dist app.edge
                                              app.empty))])
                    (hash-ref source-environment (Q name))))
    (check-equal? (map cdr (attachment-plan-version-map plan))
                  (for/list ([name (in-list '(graph.Node graph.dist graph.edge
                                              graph.empty))])
                    (version-of plan name)))
    (check-equal? (attachment-plan-type-map plan)
                  (list (cons (hash-ref source-nominals (Q 'app.Node))
                              (nominal-of plan 'graph.Node))))
    (for ([entry (in-list (append (attachment-plan-version-map plan)
                                  (attachment-plan-type-map plan)))])
      (check-not-equal? (car entry) (cdr entry))))

  (test-case "the same source at two destinations stays wholly disjoint"
    (define first-plan (attach #:source (Q 'app) #:to (Q 'one) #:event 5))
    (define second-plan (attach #:source (Q 'app) #:to (Q 'two) #:event 6))
    (check-not-equal? (version-of first-plan 'one.edge)
                      (version-of second-plan 'two.edge))
    (check-not-equal? (nominal-of first-plan 'one.Node)
                      (nominal-of second-plan 'two.Node))
    ;; and neither borrows the source's identity
    (check-false (member (nominal-of first-plan 'one.Node)
                         (hash-values source-nominals)))
    (check-false (member (version-of second-plan 'two.edge)
                         (hash-values source-environment))))

  ;; -- attaching into an established destination ---------------------------

  ;; A destination that already holds a compatible `graph.*` plus a member of
  ;; its own that the attachment must not disturb.
  (define destination-plan
    (plan-boundary
     (empty-boundary "b0:dst")
     (Delta (list (D 'graph.Node 'struct (list I))
                  (D 'graph.edge 'table (list (N 'graph.Node) (N 'graph.Node)))
                  (D 'graph.empty 'table (list I))
                  (D 'graph.local 'table (list I))))
     '()
     #:layer-id "dst" #:program-event 1 #:boundary-event 1))
  (define established (boundary-plan-output destination-plan))

  (test-case "a compatible partial destination keeps its keys and gains the rest"
    (define plan (attach #:source (Q 'app) #:to (Q 'graph) #:into established))
    ;; the destination's own member survives untouched
    (check-equal? (boundary-action-kind (action-of plan 'graph.local)) 'retain)
    (check-equal? (version-of plan 'graph.local)
                  (hash-ref (boundary-environment established) (Q 'graph.local)))
    ;; the established nominal keeps its TypeKey -- shape equality never
    ;; makes source and destination identity the same thing
    (check-equal? (nominal-of plan 'graph.Node)
                  (hash-ref (catalog-nominals (boundary-catalog established))
                            (Q 'graph.Node)))
    (check-not-equal? (nominal-of plan 'graph.Node)
                      (hash-ref source-nominals (Q 'app.Node)))
    ;; an existing member RECEIVING content advances to a successor
    (check-equal? (boundary-action-kind (action-of plan 'graph.edge)) 'create)
    (check-equal? (boundary-action-predecessor (action-of plan 'graph.edge))
                  (hash-ref (boundary-environment established) (Q 'graph.edge)))
    ;; an existing EMPTY member is not advanced merely by appearing in the bundle
    (check-equal? (boundary-action-kind (action-of plan 'graph.empty)) 'retain)
    (check-equal? (version-of plan 'graph.empty)
                  (hash-ref (boundary-environment established) (Q 'graph.empty)))
    ;; the declarations the destination lacked are added atomically
    (check-equal? (declared plan)
                  '("graph.Node" "graph.cost" "graph.dist" "graph.edge"
                    "graph.empty" "graph.local")))

  (test-case "an incompatible declaration is refused before anything is allocated"
    (define clashing
      (plan-boundary
       (empty-boundary "b0:clash")
       (Delta (list (D 'graph.edge 'table (list I I I))))
       '()
       #:layer-id "clash" #:program-event 1 #:boundary-event 1))
    (rejects 'incompatible-declaration
             (lambda () (attach #:source (Q 'app) #:to (Q 'graph)
                                #:into (boundary-plan-output clashing)))))

  (test-case "an occupied leaf and a namespace may not collide"
    ;; the destination already declares `graph` itself as a relation
    (define leaf
      (plan-boundary (empty-boundary "b0:leaf")
                     (Delta (list (D 'graph 'table (list I))))
                     '()
                     #:layer-id "leaf" #:program-event 1 #:boundary-event 1))
    (rejects 'occupied-target
             (lambda () (attach #:source (Q 'app) #:to (Q 'graph)
                                #:into (boundary-plan-output leaf))))
    ;; ... and the mirror: attaching a self-contained leaf onto a name the
    ;; destination already uses as a namespace
    (rejects 'occupied-target
             (lambda () (attach #:source (Q 'app.empty) #:to (Q 'graph)
                                #:into established))))

  (test-case "an unbound source path selects nothing and says so"
    (rejects 'unknown-path
             (lambda () (attach #:source (Q 'nowhere) #:to (Q 'here)))))

  ;; -- the persisted plan --------------------------------------------------

  (test-case "the attachment plan round-trips and re-plans identically"
    (define plan (attach #:source (Q 'app) #:to (Q 'graph) #:into established))
    (define datum (attachment-plan->datum plan))
    (check-true (attachment-plan-datum? datum))
    (check-equal? (read (open-input-string
                         (with-output-to-string (lambda () (write datum)))))
                  datum)
    (check-equal?
     (attachment-plan->datum
      (replay-attachment source-bundle established full-content datum))
     datum))

  (test-case "replay refuses a source whose content coverage drifted"
    (define plan (attach #:source (Q 'app) #:to (Q 'graph) #:into established))
    (define datum (attachment-plan->datum plan))
    ;; app.edge no longer carries rows: the write set, and therefore the whole
    ;; VersionKey allocation, would differ
    (rejects 'replay-divergence
             (lambda ()
               (replay-attachment source-bundle established
                                  (set-remove full-content (Q 'app.edge))
                                  datum))))

  (test-case "replay refuses a drifted destination"
    (define plan (attach #:source (Q 'app) #:to (Q 'graph) #:into established))
    (rejects 'replay-divergence
             (lambda ()
               (replay-attachment source-bundle (empty-boundary "b0:dst")
                                  full-content
                                  (attachment-plan->datum plan)))))

  (test-case "a malformed persisted plan is refused rather than partly read"
    (check-false (attachment-plan-datum? '(attachment-plan)))
    (rejects 'invalid-attachment
             (lambda ()
               (replay-attachment source-bundle established full-content
                                  '(attachment-plan (layer-id "x")))))))
