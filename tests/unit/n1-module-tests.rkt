#lang racket

(module+ test
  (require rackunit
           racket/file
           racket/set
           "../../compiler/catalog.rkt"
           "../../compiler/ir-shared.rkt"
           "../../compiler/modules.rkt"
           "../../compiler/names.rkt"
           "../../compiler/parser.rkt")

  (define (write-source dir name text)
    (define path (build-path dir name))
    (with-output-to-file path #:exists 'replace
      (lambda () (display text)))
    path)

  (define (with-sources sources thunk)
    (define dir (make-temporary-file "slog-n1-~a" 'directory))
    (dynamic-wind
      void
      (lambda ()
        (for ([(name text) (in-hash sources)])
          (write-source dir name text))
        (thunk dir))
      (lambda () (delete-directory/files dir))))

  (define (load-one dir name)
    (match (load-program-list (build-path dir name) (hash))
      [(list (? program-ir? program)) program]
      [other (error 'n1-test "expected one program, got ~a" other)]))

  (define (program-rules program)
    (for*/set ([module (in-set (program-ir-modules program))]
               [rule (in-set (module-ir-rules module))])
      (strip-prov rule)))

  (test-case "plain instantiation retains two isolated occurrences"
    (with-sources
     (hash
      "graph.slog"
      (string-append
       "table (edge int int)\n"
       "table (path int int)\n"
       "rule (edge X Y) --> (path X Y)\n"
       "rule (path X Y) (edge Y Z) --> (path X Z)\n")
      "main.slog"
      (string-append
       "instantiate \"graph.slog\" as left\n"
       "instantiate \"graph.slog\" as right\n"
       "table (seed int int)\n"
       "table (answer int int)\n"
       "rule (seed X Y) --> (left.edge X Y)\n"
       "rule (left.path X Y) --> (answer X Y)\n"))
     (lambda (dir)
       (define program (load-one dir "main.slog"))
       (define rels (type-env-rels (program-ir-type-env program)))
       (for ([name '(left.edge left.path right.edge right.path seed answer)])
         (check-true (hash-has-key? rels name) (format "missing ~a" name)))
       (define rules (program-rules program))
       (check-true
        (set-member? rules '(rule (left.edge X Y) --> (left.path X Y))))
       (check-true
        (set-member? rules '(rule (right.edge X Y) --> (right.path X Y))))
       (check-true
        (set-member? rules '(rule (seed X Y) --> (left.edge X Y))))
       (check-false
        (set-member? rules '(rule (left.edge X Y) --> (right.path X Y))))
       (define children
         (module-occurrence-children (program-ir-occurrence-tree program)))
       (check-equal? (map module-occurrence-home children)
                     '(("left") ("right")))
       (check-equal? (map module-occurrence-lexical-path children)
                     '(((0 "left")) ((1 "right"))))
       ;; The two source copies keep their real line but receive distinct
       ;; occurrence labels, so rule identity and diagnostics cannot merge.
       (define child-labels
         (for/list ([module (in-set (program-ir-modules program))]
                    #:when (pair? (module-ir-home module)))
           (rule-location-string (set-first (module-ir-rules module)))))
       (check-equal? (length (remove-duplicates child-labels)) 2))))

  (test-case "include deduplication is local to each occurrence"
    (with-sources
     (hash
      "common.slog" "struct (Node int)\n"
      "graph.slog"
      (string-append
       "include \"common.slog\"\n"
       "include \"common.slog\"\n"
       "table (edge Node Node)\n")
      "main.slog"
      (string-append
       "instantiate \"graph.slog\" as a\n"
       "instantiate \"graph.slog\" as b\n"))
     (lambda (dir)
       (define program (load-one dir "main.slog"))
       ;; root + (graph, common) for each explicit occurrence
       (check-equal? (set-count (program-ir-modules program)) 5)
       (define rels (type-env-rels (program-ir-type-env program)))
       (check-equal? (hash-ref rels 'a.edge) '(table a.Node a.Node))
       (check-equal? (hash-ref rels 'b.edge) '(table b.Node b.Node)))))

  (test-case "binding rewrites a formal namespace and treats any directionally"
    (with-sources
     (hash
      "interface.slog"
      (string-append
       "table (edge any any)\n"
       "table (created any)\n")
      "adapter.slog"
      (string-append
       "instantiate \"interface.slog\" as model\n"
       "table (seen int)\n"
       "rule (model.edge X Y) --> (seen X)\n")
      "main.slog"
      (string-append
       "instantiate \"adapter.slog\" as use with model = real\n"
       "table (real.edge int int)\n"
       "table (real.extra str)\n"))
     (lambda (dir)
       (define program (load-one dir "main.slog"))
       (define rels (type-env-rels (program-ir-type-env program)))
       ;; The actual declaration wins over the formal wildcard; missing
       ;; compatible members are completed atomically into the actual home.
       (check-equal? (hash-ref rels 'real.edge) '(table int int))
       (check-true (hash-has-key? rels 'real.created)
                   (format "declarations: ~a" (sort (hash-keys rels) symbol<?)))
       (check-equal? (hash-ref rels 'real.created) '(table any))
       (check-equal? (hash-ref rels 'real.extra) '(table str))
       (check-equal? (hash-ref rels 'use.seen) '(table int))
       (check-true
        (set-member?
         (program-rules program)
         '(rule (real.edge X Y) --> (use.seen X)))))))

  (test-case "an incompatible bound declaration fails before compilation"
    (with-sources
     (hash
      "interface.slog" "table (edge any any)\n"
      "adapter.slog" "instantiate \"interface.slog\" as model\n"
      "main.slog"
      (string-append
       "instantiate \"adapter.slog\" as use with model = real\n"
       "table (real.edge int)\n"))
     (lambda (dir)
       (check-exn
        #rx"bound namespace declaration real.edge is incompatible"
        (lambda () (load-one dir "main.slog"))))))

  (test-case "binding validates against the selected input catalog"
    (with-sources
     (hash
      "interface.slog" "table (edge any any)\n"
      "adapter.slog"
      (string-append
       "instantiate \"interface.slog\" as model\n"
       "table (seen int)\n"
       "rule (model.edge X Y) --> (seen X)\n")
      "main.slog"
      "instantiate \"adapter.slog\" as use with model = real\n")
     (lambda (dir)
       (define real-edge (symbol->qname 'real.edge))
       (define input
         (catalog
          (hash
           real-edge
           (declaration-descriptor
            real-edge 'table
            (list (type-ref 'primitive 'int)
                  (type-ref 'primitive 'int))
            #f))
          (set)
          (hash)))
       (match-define
         (list (? program-ir? program))
         (load-program-list
          (build-path dir "main.slog")
          (catalog->manifest input)
          #:input-catalog input))
       (define rels (type-env-rels (program-ir-type-env program)))
       (check-equal? (hash-ref rels 'real.edge) '(table int int))
       (check-true
        (set-member?
         (program-rules program)
         '(rule (real.edge X Y) --> (use.seen X)))))))

  (test-case "aliases cannot collide with declarations or siblings"
    (with-sources
     (hash
      "empty.slog" "table (x int)\n"
      "collision.slog"
      (string-append
       "instantiate \"empty.slog\" as m\n"
       "table (m int)\n")
      "duplicate.slog"
      (string-append
       "instantiate \"empty.slog\" as m\n"
       "instantiate \"empty.slog\" as m\n"))
     (lambda (dir)
       (check-exn #rx"collides with a declaration"
                  (lambda () (load-one dir "collision.slog")))
       (check-exn #rx"duplicate instance alias"
                  (lambda () (load-one dir "duplicate.slog"))))))

  (test-case "run and instantiate share as/with occurrence syntax"
    (define parsed
      (parse-source
       "occurrences.slog"
       (string-append
        "run \"stage.slog\" as stage with model = actual\n"
        "instantiate \"lib.slog\" as lib with graph = actual.graph\n")))
    (match parsed
      [`(module ,_ ,_
          (syn ,_ run (syn ,_ const "stage.slog")
               (occurrence-options stage (bindings (model actual)))
               (syn ,_ instantiate (syn ,_ const "lib.slog") lib
                    (bindings (graph actual.graph)) ,_)))
       (void)]
      [_ (fail-check (format "unexpected occurrence parse: ~a" parsed))]))

  (test-case "module keys derive from the persisted program key and slots"
    (define tree
      (module-occurrence
       "main.slog" '() '() '() '("main.slog")
       (list
        (module-occurrence
         "graph.slog" '("left") '((0 "left")) '() '("graph.slog") '())
        (module-occurrence
         "graph.slog" '("right") '((1 "right")) '() '("graph.slog") '()))))
    (define instances (module-occurrence-instances "p1:layer:7" tree))
    (check-equal?
     (map module-instance-descriptor-key instances)
     '("m1:p1:layer:7:root"
       "m1:p1:layer:7:0"
       "m1:p1:layer:7:1"))
    ;; Alias text is metadata, not key material.
    (check-equal? (module-instance-key "p1:layer:7" '((0 "renamed")))
                  "m1:p1:layer:7:0")
    (for ([instance (in-list instances)])
      (check-true
       (module-instance-descriptor-datum?
        (module-instance-descriptor->datum instance))))))
