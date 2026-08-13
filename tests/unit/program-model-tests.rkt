#lang racket

;; RF1 slice 1 (docs/rf1-contract.md "What RF1 pins" item 4, Slices item 1):
;; the ProgramModel that stratify-rules now carries out instead of
;; discarding -- the condensation (SCC of each relation, its level, its
;; members) and source-rule lineage.  Run via:
;;   cd /home/tom/slog && raco test tests/unit/program-model-tests.rkt
;;
;; Slice 2 partitions a stratum's crules by HEAD SCC to emit per-kernel
;; plans, and names each SCC's members in the cohort manifest.  These are
;; the properties that partition will rest on; the compile driver also
;; asserts the level agreement on every build (compile.rkt
;; check-stratum-scc-agreement).

(module+ test
  (require rackunit)
  (require racket/runtime-path)
  (require "../../compiler/ir-shared.rkt")
  (require "../../compiler/program-model.rkt")

  (define-runtime-path repo-root "../..")
  (define stratify-rules/model
    (parameterize ([current-directory repo-root])
      (dynamic-require
       `(file ,(path->string (build-path repo-root "compiler" "stratify.rkt")))
       'stratify-rules/model)))

  ;; ---------------------------------------------------------------------
  ;; Builders.  A located rule carries a lexer-shaped prov so lineage keys
  ;; are real; LOC is 0-based like the lexer's line-pos.

  (define (S . parts) `(syn (prov #f #f) ,@parts))
  (define (at file line col . parts)
    `(syn (prov (token id (pos ,file ,line ,col ,line ,col) "") #f) ,@parts))
  (define (rule-at file line bodys heads)
    (apply at file line 0 (append (list 'rule) bodys (list '-->) heads)))
  (define (rule-nowhere bodys heads)
    (apply S (append (list 'rule) bodys (list '-->) heads)))

  (define (model-of . rules)
    (define-values (_strata m) (stratify-rules/model (list->set rules)))
    m)

  ;; ---------------------------------------------------------------------
  ;; 1. Condensation: a recursive pair shares one SCC; a downstream
  ;;    consumer sits in a higher-level SCC of its own.

  (test-case "mutual recursion condenses into one SCC, consumers stratify above"
    (define m
      (model-of
       ;; p <-> q recursion
       (rule-at "g.slog" 1 (list (S 'q 'x)) (list (S 'p 'x)))
       (rule-at "g.slog" 2 (list (S 'p 'x)) (list (S 'q 'x)))
       ;; r reads p, nothing reads r
       (rule-at "g.slog" 3 (list (S 'p 'x)) (list (S 'r 'x)))))
    (define scc-of (program-model-scc-of m))
    (define lvl (program-model-scc-level m))
    (define members (program-model-scc-members m))
    (check-equal? (hash-ref scc-of 'p) (hash-ref scc-of 'q))
    (check-not-equal? (hash-ref scc-of 'p) (hash-ref scc-of 'r))
    (check-equal? (hash-ref members (hash-ref scc-of 'p)) '(p q))
    (check-equal? (hash-ref members (hash-ref scc-of 'r)) '(r))
    ;; r's SCC is strictly above p/q's
    (check < (hash-ref lvl (hash-ref scc-of 'p))
             (hash-ref lvl (hash-ref scc-of 'r))))

  ;; ---------------------------------------------------------------------
  ;; 2. Members are symbol-sorted, so a manifest built from them is a pure
  ;;    function of the program (not of hash iteration order).

  (test-case "SCC members are sorted"
    (define m
      (model-of
       (rule-at "g.slog" 1 (list (S 'zeta 'x)) (list (S 'alpha 'x)))
       (rule-at "g.slog" 2 (list (S 'alpha 'x)) (list (S 'mid 'x)))
       (rule-at "g.slog" 3 (list (S 'mid 'x)) (list (S 'zeta 'x)))))
    (define scc-of (program-model-scc-of m))
    (check-equal? (hash-ref (program-model-scc-members m)
                            (hash-ref scc-of 'alpha))
                  '(alpha mid zeta)))

  ;; ---------------------------------------------------------------------
  ;; 3. Lineage, the rf1-contract battery.  Provenance already survives
  ;;    every pass, so rules from ONE source rule share a prov -- which is
  ;;    exactly what a `|`-split's derivatives look like after
  ;;    simplification.

  (test-case "a split rule's derivatives map to one source"
    ;; two derived rules, same source location: one source rule
    (define a (rule-at "s.slog" 7 (list (S 'e 'x)) (list (S 'out1 'x))))
    (define b (rule-at "s.slog" 7 (list (S 'e 'x)) (list (S 'out2 'x))))
    (define m (model-of a b))
    (define of (program-model-source-of m))
    (check-equal? (hash-ref of a) (hash-ref of b))
    (check-equal? (length (hash-ref (program-model-sources m) (hash-ref of a)))
                  2))

  (test-case "rules at different locations are different sources"
    (define a (rule-at "s.slog" 7 (list (S 'e 'x)) (list (S 'out1 'x))))
    (define b (rule-at "s.slog" 9 (list (S 'e 'x)) (list (S 'out2 'x))))
    (define m (model-of a b))
    (define of (program-model-source-of m))
    (check-not-equal? (hash-ref of a) (hash-ref of b)))

  (test-case "two rules on one line stay distinct (column is in the key)"
    (define a (at "s.slog" 7 0 'rule (S 'e 'x) '--> (S 'out1 'x)))
    (define b (at "s.slog" 7 40 'rule (S 'e 'x) '--> (S 'out2 'x)))
    (define m (model-of a b))
    (check-not-equal? (hash-ref (program-model-source-of m) a)
                      (hash-ref (program-model-source-of m) b)))

  (test-case "an unlocated rule is its own source"
    (define a (rule-nowhere (list (S 'e 'x)) (list (S 'out1 'x))))
    (define b (rule-nowhere (list (S 'e 'x)) (list (S 'out2 'x))))
    (define m (model-of a b))
    (define of (program-model-source-of m))
    (check-not-equal? (hash-ref of a) (hash-ref of b))
    (for ([r (in-list (list a b))])
      (check-equal? (length (hash-ref (program-model-sources m) (hash-ref of r)))
                    1)))

  ;; ---------------------------------------------------------------------
  ;; 4. The model is a pure function of the rule SET -- ids do not depend on
  ;;    which order the rules were handed over.  (Sets do not preserve
  ;;    insertion order, so this asserts the canonical assignment rather
  ;;    than merely re-running the same iteration.)

  (test-case "lineage ids are canonical, not arrival-ordered"
    (define a (rule-at "z.slog" 3 (list (S 'e 'x)) (list (S 'out1 'x))))
    (define b (rule-at "z.slog" 1 (list (S 'e 'x)) (list (S 'out2 'x))))
    (define m1 (model-of a b))
    (define m2 (model-of b a))
    ;; the earlier LOCATION owns the lower id, whichever order they arrive in
    (check-equal? (hash-ref (program-model-source-of m1) b) 0)
    (check-equal? (hash-ref (program-model-source-of m2) b) 0)
    (check-equal? (hash-ref (program-model-source-of m1) a)
                  (hash-ref (program-model-source-of m2) a)))

  ;; ---------------------------------------------------------------------
  ;; 5. rule-lineage-key itself: located vs not.

  (test-case "rule-lineage-key shape"
    (check-equal? (rule-lineage-key (rule-at "f.slog" 12 (list (S 'e 'x))
                                             (list (S 'o 'x))))
                  '("f.slog" 12 0))
    (check-false (rule-lineage-key (rule-nowhere (list (S 'e 'x))
                                                 (list (S 'o 'x))))))

  ;; ---------------------------------------------------------------------
  ;; RF1.5: normalized, id-free model queries for the W5' program arc.

  (define (neg . parts) (S '~ (apply S parts)))

  (test-case "RF1.5 fingerprints ignore provenance and variable spelling"
    (define m1
      (model-of
       (rule-at "old/path.slog" 3
                (list (S 'edge 'x 'y))
                (list (S 'reach 'x 'y)))))
    (define m2
      (model-of
       (rule-at "new/path.slog" 80
                (list (S 'edge 'from 'to))
                (list (S 'reach 'from 'to)))))
    (check-equal? (program-model-normalized-rules m1)
                  (program-model-normalized-rules m2))
    (check-equal? (program-model-fingerprint m1)
                  (program-model-fingerprint m2))
    (define diff (diff-program-models m1 m2))
    (check-equal? (program-semantic-diff-rule-changes diff) '())
    (check-equal? (program-semantic-diff-affected-roots diff) '())
    (check-equal? (program-semantic-diff-cone diff) '()))

  (test-case "RF1.5 exposes typed dependency kinds, writers, and stable SCCs"
    (define r1
      (rule-at "q.slog" 1 (list (S 'input 'x)) (list (S 'mid 'x))))
    (define r2
      (rule-at "q.slog" 2
               (list (S 'mid 'x) (neg 'blocked '__wild))
               (list (S 'out 'x))))
    (define-values (_ model)
      (stratify-rules/model (set r1 r2) (set (cons 'out 'side))))
    (define kinds
      (for/set ([edge (in-list (program-model-dependency-edges model))])
        (list (program-edge-from edge) (program-edge-to edge)
              (program-edge-kind edge))))
    (check-true (set-member? kinds '(input mid positive)))
    (check-true (set-member? kinds '(mid out positive)))
    (check-true
     (set-member? kinds '(blocked out negative-wildcard)))
    (check-true (set-member? kinds '(out side derived)))
    (check-equal? (sort (hash-keys (program-model-writers model)) symbol<?)
                  '(mid out))
    (check-equal? (program-model-forward-cone model '(mid)) '(mid out side))
    ;; Components use member names rather than exposing Tarjan's local ids.
    (check-not-false (member '((out) (side) (derived))
                             (program-model-condensation-edges model))))

  (test-case "oracle side-channel edges are typed semantics and enter cones"
    (define producer
      (rule-at "oracle.slog" 1
               (list (S 'request 'x)) (list (S 'demand 'x))))
    (define consumer
      (rule-at "oracle.slog" 2
               (list (S 'answer 'x)) (list (S 'result 'x))))
    (define oracle-edge (cons 'demand 'answer))
    (define-values (_ model)
      (stratify-rules/model
       (set producer consumer)
       (set oracle-edge)
       (hash oracle-edge 'oracle)))
    (check-not-false
     (for/or ([edge (in-list (program-model-dependency-edges model))])
       (and (eq? (program-edge-from edge) 'demand)
            (eq? (program-edge-to edge) 'answer)
            (eq? (program-edge-kind edge) 'oracle)
            (not (program-edge-rule-slot edge)))))
    (check-equal? (program-model-forward-cone model '(demand))
                  '(answer demand result)))

  (test-case "RF1.5 semantic diff preserves duplicate multiplicity and uses the union cone"
    (define duplicate-a
      (rule-at "a.slog" 1 (list (S 'input 'x)) (list (S 'mid 'x))))
    (define duplicate-b
      (rule-at "b.slog" 9 (list (S 'input 'renamed))
               (list (S 'mid 'renamed))))
    (define sink
      (rule-at "sink.slog" 1 (list (S 'mid 'x)) (list (S 'answer 'x))))
    (define old (model-of duplicate-a duplicate-b sink))
    (define new (model-of duplicate-a sink))
    (define diff (diff-program-models old new))
    (check-not-equal? (program-semantic-diff-old-fingerprint diff)
                      (program-semantic-diff-new-fingerprint diff))
    (check-equal? (length (program-semantic-diff-rule-changes diff)) 1)
    (define change (first (program-semantic-diff-rule-changes diff)))
    (check-equal? (program-rule-change-old-count change) 2)
    (check-equal? (program-rule-change-new-count change) 1)
    (check-equal? (program-semantic-diff-affected-roots diff) '(mid))
    (check-equal? (program-semantic-diff-cone diff) '(answer mid)))

  (test-case "RF1.5 union cone retains consumers present only in the old graph"
    (define old
      (model-of
       (rule-at "old.slog" 1 (list (S 'root 'x)) (list (S 'gone 'x)))
       (rule-at "old.slog" 2 (list (S 'gone 'x)) (list (S 'old-leaf 'x)))))
    (define new
      (model-of
       (rule-at "new.slog" 1 (list (S 'root 'x)) (list (S 'added 'x)))
       (rule-at "new.slog" 2 (list (S 'added 'x)) (list (S 'new-leaf 'x)))))
    (check-equal?
     (program-model-union-cone old new '(gone added))
     '(added gone new-leaf old-leaf))))
