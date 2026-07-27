#lang racket

;; Unit tests for the M2.4 R_has/R_at decomposition front end
;; (docs/finish-collections.md §C): the need-driven synthesis by name in
;; modules.rkt (interception, user-decl-wins, unused -> absent) and the
;; derived stratification edge.  Run via:
;;   cd /home/tom/slog && raco test tests/unit/
;;
;; modules.rkt requires utils.rkt, which reads daemon headers relative to
;; the current directory at instantiation time -- so load it with
;; dynamic-require under the repo root (the planner-tests.rkt pattern).

(module+ test
  (require rackunit)
  (require racket/runtime-path)
  (require "../../compiler/ir-shared.rkt")
  (require "../../compiler/ir-stack.rkt")   ; stratum-level / stratum-rules
  (require "../../compiler/stratify.rkt")

  (define-runtime-path repo-root "../..")
  (define load-program-list
    (parameterize ([current-directory repo-root])
      (dynamic-require
       `(file ,(path->string (build-path repo-root "compiler" "modules.rkt")))
       'load-program-list)))

  ;; Load one program from source; returns (values rels decomp-env).
  (define (front-end src)
    (define f (make-temporary-file "decomp-test-~a.slog"))
    (dynamic-wind
     void
     (lambda ()
       (with-output-to-file f #:exists 'replace (lambda () (display src)))
       (match-define (list (? program-ir? program))
         (load-program-list (path->string f) (hash)))
       (define type-env (program-ir-type-env program))
       (define decomps (program-ir-decomps program))
       (values (type-env-rels type-env) decomps))
     (lambda () (delete-file f))))

  ;; ---------------------------------------------------------------------
  ;; set kind: using undeclared reach_has over reach : (..., (set int))
  ;; synthesizes a PLAIN table (keys, element) and records the registry entry

  (test-case "R_has synthesis (set kind)"
    (define-values (rels decomps)
      (front-end "lattice (iset (set int))
table (edge int int int)
table (reach int iset)
rule (edge a b g) (= s (cins (cmap) b)) --> (reach a s)
rule (edge a b g) (reach_has a g) (reach b s) --> (reach a s)"))
    (check-equal? (hash-ref decomps 'reach_has #f) '(reach set))
    (check-equal? (hash-ref rels 'reach_has #f) '(table int int)))

  ;; ---------------------------------------------------------------------
  ;; map kind: best_at over best : (int, (map int (min int))) synthesizes a
  ;; LATTICE table -- last column is the deterministically-named child spec

  (test-case "R_at synthesis (map kind)"
    (define-values (rels decomps)
      (front-end "lattice (dm (map int (min int)))
table (edge int int int)
table (best int dm)
table (out int int int)
rule (edge a b w) (= m (cput (cmap) b w)) --> (best a m)
rule (best_at a k v) --> (out a k v)"))
    (check-equal? (hash-ref decomps 'best_at #f) '(best map))
    (check-equal? (hash-ref rels 'best_at #f) '(table int int _lat_min_int))
    (check-equal? (hash-ref rels '_lat_min_int #f) '(lattice min int))
    ;; the synthesized table IS a lattice table under the shared helper
    (check-equal? (rel-lattice-spec rels 'best_at) '(lattice min int)))

  ;; ---------------------------------------------------------------------
  ;; a user's own declaration wins: no interception, no registry entry

  (test-case "user-declared foo_has wins"
    (define-values (rels decomps)
      (front-end "lattice (iset (set int))
table (reach int iset)
table (reach_has str str)
table (seed int)
rule (seed a) (= s (cins (cmap) a)) --> (reach a s)
rule (reach_has x y) --> (reach_has y x)"))
    (check-equal? decomps (hash))
    (check-equal? (hash-ref rels 'reach_has #f) '(table str str)))

  ;; ---------------------------------------------------------------------
  ;; no use -> no declaration, no registry entry (zero cost)

  (test-case "unused decomposition stays absent"
    (define-values (rels decomps)
      (front-end "lattice (iset (set int))
table (reach int iset)
table (seed int)
rule (seed a) (= s (cins (cmap) a)) --> (reach a s)"))
    (check-equal? decomps (hash))
    (check-false (hash-ref rels 'reach_has #f)))

  ;; ---------------------------------------------------------------------
  ;; a non-collection base does not intercept: foo_has over a (min int)
  ;; lattice table stays undeclared (and would be an ordinary type error)

  (test-case "scalar-lattice base does not synthesize"
    (define-values (rels decomps)
      (front-end "lattice (low (min int))
table (d int low)
table (seed int)
rule (seed a) --> (d a 5)"))
    (check-equal? decomps (hash))
    (check-false (hash-ref rels 'd_has #f)))

  ;; ---------------------------------------------------------------------
  ;; the stratify edge R -> R_has: a reader of R_has that writes back into R
  ;; joins R's SCC; a pure downstream reader lands strictly above

  (test-case "decomposition stratification edge"
    (define P '(prov #f #f))
    (define (S . parts) `(syn ,P ,@parts))
    (define feedback   ; reads reach_has, writes reach: cycle via the edge
      (S 'rule (S 'edge 'a 'b) (S 'reach_has 'a 'g) '--> (S 'reach 'a 'b)))
    (define seed
      (S 'rule (S 'edge 'a 'b) '--> (S 'reach 'a 'b)))
    (define downstream ; reads reach_has only: strictly above reach's SCC
      (S 'rule (S 'reach_has 'a 'g) '--> (S 'out 'a)))
    (define edge (set (cons 'reach 'reach_has)))
    (define (level-of strata rule)
      (for/first ([s (in-list strata)]
                  #:when (set-member? (stratum-rules s) rule))
        (stratum-level s)))
    (define strata (stratify-rules (set feedback seed downstream) edge))
    (check-equal? (level-of strata feedback) (level-of strata seed))
    (check-true (> (level-of strata downstream) (level-of strata feedback)))
    ;; without the edge there is nothing forcing downstream above reach
    (define strata0 (stratify-rules (set feedback seed downstream)))
    (check-true (<= (level-of strata0 downstream) (level-of strata0 feedback)))))
