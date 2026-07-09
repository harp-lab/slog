#lang racket

;; Unit tests for the semijoin existence filters (operationalization.rkt
;; "Semijoin filters"), run via:
;;   cd /home/tom/slog && raco test tests/unit/
;;
;; Programs are driven through the real front half of the pipeline (parse
;; -> modules -> simplify -> typecheck -> stratify -> plan -> build-cprog)
;; and the tests assert on the resulting crules and decls: where (exists
;; ...) ops appear, which relations/columns they probe, that the indices
;; they need were requisitioned, and that non-candidates (two-join rules,
;; lattice targets, disabled flag) get no filters at all.

(module+ test
  (require rackunit)
  (require racket/file)
  (require "../../compiler/params.rkt")
  (require "../../compiler/modules.rkt")
  (require "../../compiler/simplification.rkt")
  (require "../../compiler/type-system.rkt")
  (require "../../compiler/stratify.rkt")
  (require "../../compiler/join-planning.rkt")
  (require "../../compiler/operationalization.rkt")
  (require "../../compiler/ir-shared.rkt")
  (require "../../compiler/ir-stack.rkt")

  ;; Compile source to the list of cprogs (one per stratum).
  (define (cprogs-of src)
    (define f (make-temporary-file "semijoin-test-~a.slog"))
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
         (build-cprog planned rel-env+)))
     (lambda () (delete-file f))))

  ;; All (exists ...) ops across a cprog list, tagged with their crule.
  (define (exists-ops cprogs)
    (for*/list ([cprog (in-list cprogs)]
                [crule (in-list (cprog-rules cprog))]
                [op (in-list (crule-body crule))]
                #:when (eq? 'exists (car op)))
      (cons crule op)))

  ;; The declared index orderings for a relation, across all strata.
  (define (indices-declared cprogs name)
    (for*/fold ([acc (set)])
               ([cprog (in-list cprogs)]
                [d (in-list (cprog-decls cprog))]
                #:when (equal? (second d) name))
      (set-union acc
                 (for/set ([i (in-list (cdddr d))]
                           #:unless (and (pair? i) (eq? 'delta (car i))))
                   i))))

  ;; -- 1. a two-join rule gets no filters ---------------------------------
  (check-equal?
   (exists-ops (cprogs-of "table (edge int int)
                           table (path int int)
                           rule (edge X Y) (edge Y Z) --> (path X Z)"))
   '()
   "two-join rule must get no filters")

  ;; -- 2. three-relation triangle: exactly one filter, before join #2 ------
  (let* ([cprogs (cprogs-of "table (redge int int)
                             table (sedge int int)
                             table (tedge int int int)
                             table (tri int int int)
                             rule (redge A B) (sedge B C) (tedge C A W) --> (tri A B C)")]
         [ops (exists-ops cprogs)])
    (check-equal? (length ops) 1 "triangle rule gets exactly one filter")
    (match-define (cons crule `(exists ,name ,ind ,K ,vars ...)) (car ops))
    (check-equal? K 1 "one bound column at the driver")
    (check-equal? (length vars) 1 "exists carries exactly the K key vars")
    (check-true (set-member? (indices-declared cprogs name) ind)
                "the probed index ordering was requisitioned")
    ;; the filter must precede the first (expanding) body join
    (define body (crule-body crule))
    (check-pred (lambda (i) (and i (for/and ([op (in-list (take body i))])
                                     (not (eq? 'join (car op))))))
                (index-of body (cdr (car ops))))
    ;; and it must not target the very relation the driver read
    (match-define `(,_ ,driver-name ,_ ...) (crule-driver crule))
    (check-not-equal? name driver-name "filter targets a future clause"))

  ;; -- 3. the flag disables everything -------------------------------------
  (parameterize ([semijoin-filters-enabled #f])
    (check-equal?
     (exists-ops (cprogs-of "table (redge int int)
                             table (sedge int int)
                             table (tedge int int int)
                             table (tri int int int)
                             rule (redge A B) (sedge B C) (tedge C A W) --> (tri A B C)"))
     '()
     "SLOG_NO_SEMIJOIN path yields no filters"))

  ;; -- 4. recursion: the delta-driven version gets the filter --------------
  (let* ([cprogs (cprogs-of "table (edge int int)
                             table (sg int int)
                             rule (edge P X) (edge P Y) --> (sg X Y)
                             rule (edge PX X) (sg PX PY) (edge PY Y) --> (sg X Y)")]
         [ops (exists-ops cprogs)])
    ;; exactly the recursive rule's sg-driven version filters (edge PY ...)
    (check-equal? (length ops) 1 "one filter in the sg-driven version")
    (match-define (cons crule `(exists edge ,ind 1 ,v)) (car ops))
    (match-define `(,dtag sg ,_ ...) (crule-driver crule))
    (check-true (and (memq dtag '(scan probe)) #t)
                "filter lives in the delta-sg version"))

  ;; -- 5. filter-driven index requisition (destination-keyed index) --------
  ;; alternating 4-cycle over two relations; the guards pin the schedule:
  ;; (< A B) makes (e A B) the only driver unblocking a guard, and (< B C)
  ;; then favors (f B C W1) over (f D A W2) -- so the future clause
  ;; (f D A W2) is filtered on its column 1, an index no join requests
  (let* ([cprogs (cprogs-of "table (e int int)
                             table (f int int int)
                             table (cyc4 int int int int)
                             rule (e A B) (f B C W1) (e C D) (f D A W2)
                                  (< A B) (< B C)
                               --> (cyc4 A B C D)")]
         [ops (exists-ops cprogs)])
    (check-true (pair? ops) "4-cycle rule gets at least one filter")
    (for ([co (in-list ops)])
      (match-define (cons _ `(exists ,name ,ind ,K ,vars ...)) co)
      (check-true (set-member? (indices-declared cprogs name) ind)
                  (format "requisitioned index ~a for ~a" ind name))
      (check-equal? (length vars) K)
      (check-true (<= 1 K (length ind))))
    ;; the (f D A W2) future clause binds A first: column 1 leads its index
    (check-true (for/or ([co (in-list ops)])
                  (match-define (cons _ `(exists ,name ,ind ,_ ...)) co)
                  (and (eq? name 'f) (= 1 (first ind))))
                "some filter probes f keyed on its destination column"))

  ;; -- 6. lattice relations are never filter targets -----------------------
  (let* ([cprogs (cprogs-of "lattice (cost (min int #:floor 0))
                             table (edge int int int)
                             table (mark int)
                             table (dist int int cost)
                             table (out int int int)
                             rule (mark X) (edge X Y W) (dist X Y D) --> (out X Y D)
                             rule (edge X Y W) --> (dist X Y W)
                             rule (dist X Y D) (edge Y Z W) --> (dist X Z (+ D W))")]
         [ops (exists-ops cprogs)])
    (for ([co (in-list ops)])
      (match-define (cons _ `(exists ,name ,_ ...)) co)
      (check-not-equal? name 'dist "lattice relations are not probed")))

  ;; -- 7. every exists op in every benchmark shape is well-formed ----------
  ;; (local well-formedness mirror of ir-stack's c-op? for the exists case)
  (define (c-op-well-formed? op)
    (match op
      [`(exists ,(? symbol?)
                (,(? exact-nonnegative-integer?) ..1)
                ,(? exact-nonnegative-integer? k)
                ,(? symbol? vs) ..1)
       (= k (length vs))]
      [_ #f]))

  (let* ([cprogs (cprogs-of "table (edge int int)
                             table (clique4 int int int int)
                             rule (edge A B) (edge A C) (edge A D)
                                  (edge B C) (edge B D) (edge C D)
                               --> (clique4 A B C D)")])
    (for ([co (in-list (exists-ops cprogs))])
      (match-define (cons crule (and op `(exists ,name ,ind ,K ,vars ...))) co)
      (check-true (c-op-well-formed? op))
      ;; never in pre or head
      (check-false (member op (crule-pre crule)))
      (check-true (set-member? (indices-declared cprogs name) ind))))

  (void))
