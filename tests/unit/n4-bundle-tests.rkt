#lang racket

;; N4-A: the durable boundary bundle codec and its validators
;; (docs/n4-contract.md §3, §4 work orders 1-2).
;;
;; The bundle is the ONE canonical description of a saved database's logical
;; schema.  These cases pin the round trip (including through a real `read`
;; of a written META) and every integrity refusal, because a bundle that
;; decodes but lies would install a wrong catalog before any tuple is loaded.

(module+ test
  (require rackunit
           racket/file
           racket/set
           "../../compiler/catalog.rkt"
           "../../compiler/dbmeta.rkt"
           "../../compiler/names.rkt")

  (define (Q name) (symbol->qname name))
  (define I (type-ref 'primitive 'int))
  (define (N name) (type-ref 'named (Q name)))
  (define (D name kind [fields '()] [lattice #f])
    (declaration-descriptor (Q name) kind fields lattice))
  (define (Delta descriptors [memberships (set)])
    (catalog-delta
     (for/hash ([descriptor (in-list descriptors)])
       (values (declaration-descriptor-name descriptor) descriptor))
     memberships))

  ;; A qualified program: tables, a lattice, a struct, nested collection
  ;; declarations, a union membership, and one relation nobody writes.
  (define sample-delta
    (Delta
     (list (D 'g.Node 'struct (list I))
           (D 'g.edge 'table (list (N 'g.Node) (N 'g.Node)))
           (D 'g.cost 'lattice '() (lattice-descriptor 'min (list I) '()))
           (D 'g.dist 'table (list (N 'g.Node) (N 'g.cost)))
           (D 'g.unseen 'table (list I))
           (D 'g.Items 'list (list (N 'g.Node)))
           (D 'g.Index 'map (list I (N 'g.Node)))
           (D 'g.Maybe 'union))
     (set (cons (Q 'g.Node) (Q 'g.Maybe)))))

  (define base-key "b0:test")
  (define sample-plan
    (plan-boundary (empty-boundary base-key) sample-delta '()
                   #:layer-id "test" #:program-event 1 #:boundary-event 1))
  (define sample-head (boundary-plan-output sample-plan))
  (define sample-environment (boundary-environment sample-head))
  (define sample-nominals (catalog-nominals (boundary-catalog sample-head)))

  (define (version-key-of name) (hash-ref sample-environment (Q name)))
  (define node-type-key (hash-ref sample-nominals (Q 'g.Node)))

  (define sample-history
    (list (boundary-record base-key #f 'initial #f)
          (boundary-record (boundary-key sample-head) base-key 'program
                           (boundary-plan->datum sample-plan))))

  (define (version-for name kind materialized?)
    (version-record (version-key-of name) #f kind (Q name) materialized?))

  (define sample-versions
    (list (version-for 'g.Node 'struct #t)
          (version-for 'g.edge 'table #t)
          (version-for 'g.dist 'table #t)
          ;; the empty declaration: described, with no materialization
          (version-for 'g.unseen 'table #f)))

  (define sample-types
    (list (type-record node-type-key 2 7 (list (Q 'g.Node)))))

  (define sample-module
    (module-instance-descriptor->datum
     (module-instance-descriptor
      (module-instance-key (boundary-plan-program-key sample-plan) '())
      '() '() '())))

  (define sample-programs
    (list (program-record (boundary-plan-program-key sample-plan)
                          base-key (boundary-key sample-head)
                          (list sample-module))))

  (define (make-bundle #:format [format slog-boundary-bundle-format]
                       #:head [head sample-head]
                       #:history [history sample-history]
                       #:versions [versions sample-versions]
                       #:types [types sample-types]
                       #:programs [programs sample-programs])
    (boundary-bundle format head history versions types programs))

  (define sample-bundle (make-bundle))

  (define (bundle-failure thunk)
    (with-handlers ([exn:fail:catalog? exn:fail:catalog-kind])
      (thunk)
      #f))

  (define (rejects kind thunk)
    (check-equal? (bundle-failure thunk) kind))

  ;; -- round trip ---------------------------------------------------------

  (test-case "a qualified bundle round-trips through its datum"
    (define datum (boundary-bundle->datum sample-bundle))
    (define decoded (datum->boundary-bundle datum))
    (check-equal? (boundary-bundle-selected-head decoded) sample-head)
    (check-equal? (boundary-bundle-history decoded) sample-history)
    (check-equal? (boundary-bundle-versions decoded) sample-versions)
    (check-equal? (boundary-bundle-types decoded) sample-types)
    (check-equal? (boundary-bundle-programs decoded) sample-programs)
    (check-equal? decoded sample-bundle)
    (check-equal? (boundary-bundle->datum decoded) datum)
    (check-true (boundary-bundle-datum? datum)))

  (test-case "the datum survives a write/read cycle unchanged"
    (define datum (boundary-bundle->datum sample-bundle))
    (define text (with-output-to-string (lambda () (write datum))))
    (define reread (read (open-input-string text)))
    (check-equal? reread datum)
    (check-equal? (datum->boundary-bundle reread) sample-bundle))

  (test-case "an empty declaration is described before any tuple exists"
    ;; The whole point of the bundle: g.unseen is in the head's catalog and
    ;; environment with a real VersionKey and no materialization.
    (define decoded
      (datum->boundary-bundle (boundary-bundle->datum sample-bundle)))
    (define head (boundary-bundle-selected-head decoded))
    (check-true
     (hash-has-key? (catalog-declarations (boundary-catalog head))
                    (Q 'g.unseen)))
    (define record
      (for/first ([r (in-list (boundary-bundle-versions decoded))]
                  #:when (qname=? (version-record-name r) (Q 'g.unseen)))
        r))
    (check-equal? (version-record-key record) (version-key-of 'g.unseen))
    (check-false (version-record-materialized? record)))

  (test-case "the saved-SID projection covers every recorded nominal"
    (check-equal? (boundary-bundle-type-key->sid sample-bundle)
                  (hash node-type-key 7))
    ;; A nominal whose SID was never observed simply has no left-hand entry;
    ;; it must not fabricate one.
    (check-equal?
     (boundary-bundle-type-key->sid
      (make-bundle #:types (list (type-record node-type-key 2 #f
                                              (list (Q 'g.Node))))))
     (hash)))

  (test-case "historical constructor names are retained beside the current one"
    (define bundle
      (make-bundle #:types (list (type-record node-type-key 2 7
                                              (list (Q 'g.Node) (Q 'old.Node))))))
    (check-equal? (validate-boundary-bundle bundle) bundle)
    (check-equal? (boundary-bundle-types
                   (datum->boundary-bundle (boundary-bundle->datum bundle)))
                  (boundary-bundle-types bundle)))

  ;; -- refusals -----------------------------------------------------------

  (test-case "an unsupported bundle format is refused"
    (rejects 'unsupported-bundle-format
             (lambda () (validate-boundary-bundle
                         (make-bundle #:format (add1 slog-boundary-bundle-format)))))
    (rejects 'unsupported-bundle-format
             (lambda ()
               (datum->boundary-bundle
                (boundary-bundle->datum
                 (make-bundle
                  #:format (add1 slog-boundary-bundle-format))))))
    (check-false
     (boundary-bundle-datum?
      (boundary-bundle->datum
       (make-bundle #:format (add1 slog-boundary-bundle-format))))))

  (test-case "a duplicate key in any record family is refused"
    (rejects 'duplicate-key
             (lambda ()
               (validate-boundary-bundle
                (make-bundle
                 #:versions (append sample-versions
                                    (list (version-for 'g.edge 'table #t)))))))
    (rejects 'duplicate-key
             (lambda ()
               (validate-boundary-bundle
                (make-bundle #:types (append sample-types sample-types)))))
    (rejects 'duplicate-key
             (lambda ()
               (validate-boundary-bundle
                (make-bundle #:programs (append sample-programs
                                                sample-programs))))))

  (test-case "two nominals may not claim one saved struct id"
    (rejects 'duplicate-key
             (lambda ()
               (validate-boundary-bundle
                (make-bundle
                 #:types (list (type-record node-type-key 2 7 (list (Q 'g.Node)))
                               (type-record "t1:test:1:9" 2 7
                                            (list (Q 'gone.Node)))))))))

  (test-case "a head binding with no version record is refused"
    (rejects 'missing-version
             (lambda ()
               (validate-boundary-bundle
                (make-bundle
                 #:versions (filter
                             (lambda (r)
                               (not (qname=? (version-record-name r)
                                             (Q 'g.edge))))
                             sample-versions))))))

  (test-case "a version record that renames its binding is refused"
    (rejects 'invalid-bundle
             (lambda ()
               (validate-boundary-bundle
                (make-bundle
                 #:versions
                 (cons (version-record (version-key-of 'g.edge) #f 'table
                                       (Q 'g.dist) #t)
                       (filter (lambda (r)
                                 (not (equal? (version-record-key r)
                                              (version-key-of 'g.edge))))
                               sample-versions)))))))

  (test-case "a version naming an undeclared relation is refused"
    (rejects 'dangling-version
             (lambda ()
               (validate-boundary-bundle
                (make-bundle
                 #:versions (cons (version-record "v1:test:0:9" #f 'table
                                                  (Q 'g.absent) #f)
                                  sample-versions))))))

  (test-case "a version predecessor must name a described version"
    (rejects 'dangling-version
             (lambda ()
               (validate-boundary-bundle
                (make-bundle
                 #:versions
                 (cons (version-record "v1:test:9:0" "v1:nowhere:0:0" 'table
                                       #f #f)
                       sample-versions))))))

  (test-case "a version record kind must match its declaration"
    (rejects 'invalid-bundle
             (lambda ()
               (validate-boundary-bundle
                (make-bundle
                 #:versions
                 (cons (version-record (version-key-of 'g.Node) #f 'table
                                       (Q 'g.Node) #t)
                       (filter (lambda (r)
                                 (not (equal? (version-record-key r)
                                              (version-key-of 'g.Node))))
                               sample-versions)))))))

  (test-case "a nominal with no type record is refused"
    (rejects 'missing-type
             (lambda ()
               (validate-boundary-bundle (make-bundle #:types '())))))

  (test-case "a type record must carry the name the head binds to it"
    (rejects 'invalid-bundle
             (lambda ()
               (validate-boundary-bundle
                (make-bundle
                 #:types (list (type-record node-type-key 2 7
                                            (list (Q 'other.Node)))))))))

  (test-case "a type record arity must match the stored declaration arity"
    (rejects 'invalid-bundle
             (lambda ()
               (validate-boundary-bundle
                (make-bundle
                 #:types (list (type-record node-type-key 5 7
                                            (list (Q 'g.Node)))))))))

  (test-case "boundary history must be a linked chain ending at the head"
    (rejects 'invalid-bundle
             (lambda () (validate-boundary-bundle (make-bundle #:history '()))))
    (rejects 'invalid-bundle
             (lambda ()
               (validate-boundary-bundle
                (make-bundle #:history (list (first sample-history))))))
    (rejects 'invalid-bundle
             (lambda ()
               (validate-boundary-bundle
                (make-bundle
                 #:history
                 (list (first sample-history)
                       (boundary-record (boundary-key sample-head)
                                        "b0:elsewhere" 'program
                                        (boundary-plan->datum sample-plan))))))))

  (test-case "a history record may not carry a plan that mints another key"
    (rejects 'invalid-bundle
             (lambda ()
               (validate-boundary-bundle
                (make-bundle
                 #:history
                 (list (first sample-history)
                       (boundary-record (boundary-key sample-head) base-key
                                        'transform
                                        '(transform-plan (layer "test")
                                                         (event 4)
                                                         (kind rename)
                                                         (from (qname "a"))
                                                         (to (qname "b"))
                                                         (boundary "b1:test:4"))))))))
    ;; ... and the same record with the right key validates
    (define renamed-head
      (boundary "b1:test:4" (boundary-catalog sample-head) sample-environment))
    (check-true
     (boundary-bundle?
      (validate-boundary-bundle
       (make-bundle
        #:head renamed-head
        #:programs
        (list (program-record (boundary-plan-program-key sample-plan)
                              base-key "b1:test:4" (list sample-module)))
        #:history
        (list (first sample-history)
              (boundary-record "b1:test:4" base-key 'transform
                               '(transform-plan (layer "test")
                                                (event 4)
                                                (kind rename)
                                                (from (qname "a"))
                                                (to (qname "b"))
                                                (boundary "b1:test:4")))))))))

  (test-case "a program record may not reference an unknown boundary"
    (rejects 'dangling-boundary
             (lambda ()
               (validate-boundary-bundle
                (make-bundle
                 #:programs (list (program-record "p1:test:1" base-key
                                                  "b1:nowhere:0" '())))))
    )
    (rejects 'dangling-boundary
             (lambda ()
               (validate-boundary-bundle
                (make-bundle
                 #:programs
                 (list (program-record "p1:test:1" "b1:nowhere:0"
                                       (boundary-key sample-head) '())))))))

  (test-case "two module occurrences may not share one ModuleInstanceKey"
    (rejects 'duplicate-key
             (lambda ()
               (validate-boundary-bundle
                (make-bundle
                 #:programs
                 (list (program-record (boundary-plan-program-key sample-plan)
                                       base-key (boundary-key sample-head)
                                       (list sample-module sample-module))))))))

  (test-case "a dangling TypeRef or membership never reaches a reader"
    ;; The head is validated with the same shape checker the planner uses, so
    ;; a bundle cannot smuggle in a reference to an undeclared node.
    (define broken
      (boundary (boundary-key sample-head)
                (catalog (hash (Q 'g.edge)
                               (D 'g.edge 'table (list (N 'g.Node))))
                         (set)
                         (hash))
                (hash (Q 'g.edge) "v1:test:1:0")))
    (rejects 'missing-type
             (lambda ()
               (validate-boundary-bundle (make-bundle #:head broken)))))

  (test-case "malformed datums are refused rather than partly decoded"
    (rejects 'invalid-bundle (lambda () (datum->boundary-bundle '(nonsense))))
    (rejects 'invalid-bundle
             (lambda () (datum->boundary '(boundary (key "b") (declarations)))))
    (rejects 'invalid-bundle
             (lambda ()
               (datum->boundary-bundle
                `(boundary-bundle
                  (bundle-format ,slog-boundary-bundle-format)
                  (selected-head ,(boundary->datum sample-head))
                  (boundary-history (boundary-record (key "b") (predecessor #f)
                                                     (origin (program 17))))
                  (versions) (types) (programs)))))
    (rejects 'duplicate-key
             (lambda ()
               (datum->boundary
                `(boundary
                  (key "b1:test:1")
                  (declarations)
                  (memberships)
                  (nominals)
                  (environment (binding (qname "g" "edge") "v1:a")
                               (binding (qname "g" "edge") "v1:b"))))))
    (check-false (boundary-bundle-datum? '(boundary-bundle)))
    (check-false (boundary-bundle-datum? "not even a datum")))

  ;; -- META placement (work order 2) --------------------------------------

  ;; META is written through tools.rkt's atomic writer, which stages into a
  ;; `build/` directory beside the working directory -- so run these cases
  ;; inside a self-contained scratch tree.
  (define (with-temp-db-dir proc)
    (define dir (make-temporary-file "n4-bundle-~a" 'directory))
    (make-directory* (build-path dir "build"))
    (dynamic-wind void
                  (lambda ()
                    (parameterize ([current-directory dir]) (proc ".")))
                  (lambda () (delete-directory/files dir #:must-exist? #f))))

  (test-case "META carries the bundle atomically and re-reads it exactly"
    (define datum (boundary-bundle->datum sample-bundle))
    (with-temp-db-dir
     (lambda (dir)
       (define m (make-db-meta #:kind 'compressed #:pure-edb? #f
                               #:boundary-bundle datum))
       (check-equal? (db-meta-format-version m) slog-db-format-version)
       (check-true (db-meta-has-boundary-bundle? m))
       (write-db-meta (hash-set m 'stamp (compute-db-stamp m)) dir)
       (define back (read-db-meta dir))
       (check-equal? (db-meta-boundary-bundle back) datum)
       (check-equal? (datum->boundary-bundle (db-meta-boundary-bundle back))
                     sample-bundle))))

  (test-case "a database with no exact declaration metadata carries no bundle"
    (define m (make-db-meta #:kind 'root))
    (check-false (db-meta-has-boundary-bundle? m))
    (check-false (db-meta-boundary-bundle m)))

  (test-case "the writer refuses an invalid bundle before it reaches disk"
    (check-exn db-meta-error?
               (lambda ()
                 (make-db-meta #:boundary-bundle '(boundary-bundle))))
    (check-exn db-meta-error?
               (lambda ()
                 (make-db-meta
                  #:boundary-bundle
                  (boundary-bundle->datum (make-bundle #:types '()))))))

  (test-case "a corrupted bundle on disk fails the whole META read"
    (with-temp-db-dir
     (lambda (dir)
       (define m (make-db-meta
                  #:boundary-bundle (boundary-bundle->datum sample-bundle)))
       (write-db-meta m dir)
       (define path (build-path dir "META"))
       (define text (file->string path))
       ;; drop the type records: the head's nominal is now undescribed
       (define broken
         (regexp-replace #px"\\(type-record[^)]*\\)[^)]*\\)[^)]*\\)[^)]*\\)"
                         text ""))
       (check-not-equal? broken text)
       (display-to-file broken path #:exists 'truncate)
       (check-exn db-meta-error? (lambda () (read-db-meta dir))))))

  (test-case "the stamp covers the bundle"
    (define with-bundle
      (make-db-meta #:boundary-bundle (boundary-bundle->datum sample-bundle)))
    (define without (make-db-meta))
    (define other
      (make-db-meta
       #:boundary-bundle
       (boundary-bundle->datum
        (make-bundle #:types (list (type-record node-type-key 2 9
                                                (list (Q 'g.Node))))))))
    (check-not-equal? (compute-db-stamp with-bundle) (compute-db-stamp without))
    (check-not-equal? (compute-db-stamp with-bundle) (compute-db-stamp other))
    (check-equal? (compute-db-stamp with-bundle)
                  (compute-db-stamp
                   (make-db-meta
                    #:boundary-bundle
                    (boundary-bundle->datum sample-bundle))))))
