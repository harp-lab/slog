#lang racket

;; T3b slice 1 battery: the DEFAULT tier classification
;; (docs/execution-tiers.md §5.3, docs/t3b-contract.md §3 slice 1).
;;
;; The classifier is a pure function of a PLANNED VARIANT, so these cases
;; compile real sources down to cprogs (the same front-half harness
;; canonical-plan-tests.rkt uses) and assert the designation of every crule
;; that comes out.  Two drivers -- `once` and `seeded` -- are asserted over
;; synthesized crule forms instead, because a `seeded` re-entry variant only
;; arises inside a staged replay and the classifier does not care how the
;; form was produced.
;;
;; The pre-fix demonstration is the `all` policy: under it EVERY variant is
;; covered, which is exactly what the tree did before this slice.

(module+ test
  (require rackunit
           racket/set
           "../../compiler/params.rkt"
           "../../compiler/modules.rkt"
           "../../compiler/simplification.rkt"
           "../../compiler/type-system.rkt"
           "../../compiler/stratify.rkt"
           "../../compiler/join-planning.rkt"
           "../../compiler/operationalization.rkt"
           "../../compiler/ir-shared.rkt"
           "../../compiler/ir-stack.rkt"
           "../../compiler/tier-policy.rkt")

  (define fixed-src
    (build-path (find-system-path 'temp-dir) "tier-policy-tests.slog"))

  ;; source -> (list (cons cprog dynamic-rels) ...), one per stratum
  (define (strata-of src)
    (with-output-to-file fixed-src #:exists 'replace (lambda () (display src)))
    (match-define (list (? program-ir? program))
      (load-program-list (path->string fixed-src) (hash)))
    (define type-env (program-ir-type-env program))
    (define all-rules
      (foldl set-union (set)
             (map module-ir-rules (set->list (program-ir-modules program)))))
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
      (cons (build-cprog planned rel-env+) dynamic-rels)))

  ;; every (tier . reason) pair a source produces, as a set -- the strata and
  ;; their order are stratifier business, not this battery's
  (define (designations src)
    (for*/set ([s (in-list (strata-of src))]
               [cr (in-list (cprog-rules (car s)))])
      (cons (variant-tier cr (cprog-dynamic-rels (car s)))
            (tier-reason cr (cprog-dynamic-rels (car s))))))

  ;; ---- the shapes ------------------------------------------------------

  ;; §5.3 "ground-fact/`once` rules" and "seeded/replay variants": both run
  ;; exactly once, so nothing amortizes and the class is unconditional --
  ;; asserted over the driver forms directly.
  (define (synth driver body)
    `(crule (pre) ,driver (body ,@body) (head (emit out (0) x)) #f #f))

  (test-case "once and seeded drivers are interp-only, unconditionally"
    (check-equal? (variant-tier (synth '(once) '()) (set)) 'interp-only)
    (check-equal? (tier-reason (synth '(once) '()) (set)) 'runs-once)
    (check-equal? (variant-tier (synth '(seeded) '()) (set)) 'interp-only)
    (check-equal? (tier-reason (synth '(seeded) '()) (set)) 'seeded-reentry)
    ;; even with joins over dynamic relations: a variant that fires once
    ;; cannot amortize a compile no matter what its body does
    (check-equal? (variant-tier (synth '(seeded) '((join p (0) 1 x y)))
                                (set 'p))
                  'interp-only))

  ;; a copy/projection over a closed relation: driver, no join
  (test-case "copy/projection shapes are interp-only (no-join)"
    (define ds (designations
                "table (edge int int)
                 table (copy int int)
                 rule (edge X Y) --> (copy X Y)"))
    (check-true (set-member? ds '(interp-only . no-join))
                (format "expected a no-join interp-only variant, got ~s" ds))
    (check-false (for/or ([d (in-set ds)]) (eq? (car d) 'o0-max))))

  ;; a join-bearing rule in an acyclic stratum
  (test-case "acyclic join shapes are o0-max"
    (define ds (designations
                "table (edge int int)
                 table (other int int)
                 table (out int int)
                 rule (edge X Y) (other Y Z) --> (out X Z)"))
    (check-true (set-member? ds '(o0-max . acyclic-join))
                (format "expected an acyclic-join o0-max variant, got ~s" ds)))

  ;; the recursive SCC: its recursive variant is tiered, and recursion beats
  ;; join-freedom -- the base rule of the same SCC stays interp-only because
  ;; it does not read the SCC's own relation
  (test-case "recursive variants are tiered; the base rule is not"
    (define ds (designations
                "table (edge int int)
                 table (path int int)
                 rule (edge X Y) --> (path X Y)
                 rule (path X Y) (edge Y Z) --> (path X Z)"))
    (check-true (set-member? ds '(tiered . iterated))
                (format "expected a tiered iterated variant, got ~s" ds))
    (check-true (set-member? ds '(interp-only . no-join))
                (format "expected the base rule interp-only, got ~s" ds)))

  ;; The `iterated` test is "reads a relation this STRATUM produces", which
  ;; is deliberately conservative in principle.  In practice stratification
  ;; has already split an acyclic dependency chain into separate strata, so
  ;; the conservative arm does not fire on layered acyclic code -- `iterated`
  ;; means real recursion.  Pinned because the classification's whole
  ;; economics rest on it: if acyclic layers read as iterated, everything
  ;; becomes `tiered` and the policy buys nothing.
  (test-case "an acyclic chain is split by stratification, not called iterated"
    (define ds (designations
                "table (a int int)
                 table (b int int)
                 table (c int int)
                 rule (a X Y) --> (b X Y)
                 rule (b X Y) (a Y Z) --> (c X Z)"))
    (check-false (for/or ([d (in-set ds)]) (eq? (cdr d) 'iterated))
                 (format "expected no iterated variant, got ~s" ds)))

  ;; mutual recursion across two relations is one SCC, hence one stratum,
  ;; hence genuinely iterated
  (test-case "mutual recursion is iterated"
    (define ds (designations
                "table (edge int int)
                 table (even int int)
                 table (odd int int)
                 rule (edge X Y) --> (even X Y)
                 rule (even X Y) (edge Y Z) --> (odd X Z)
                 rule (odd X Y) (edge Y Z) --> (even X Z)"))
    (check-true (set-member? ds '(tiered . iterated))
                (format "expected a tiered iterated variant, got ~s" ds)))

  ;; ---- what the emitter asks -------------------------------------------

  (define recursive-src
    "table (edge int int)
     table (path int int)
     rule (edge X Y) --> (path X Y)
     rule (path X Y) (edge Y Z) --> (path X Z)")

  (define (coverage src #:policy [policy 'classified]
                    #:knob [knob 'all] #:flavored? [flavored? #f])
    (parameterize ([tier-policy policy] [native-rule-coverage knob])
      (for/list ([s (in-list (strata-of src))])
        (define crs (cprog-rules (car s)))
        (define-values (ncov total _entries)
          (kernel-tier-summary crs (cprog-dynamic-rels (car s))
                               #:flavored? flavored?))
        (cons ncov total))))

  (test-case "the classified policy leaves the base rule to the interpreter"
    ;; the recursive stratum: 2 variants, 1 covered
    (check-not-false (member '(1 . 2) (coverage recursive-src))
                     (format "expected a 1-of-2 covered stratum, got ~s"
                             (coverage recursive-src))))

  (test-case "SLOG_TIER_POLICY=all is the pre-fix behavior: cover everything"
    (for ([c (in-list (coverage recursive-src #:policy 'all))])
      (check-equal? (car c) (cdr c)
                    "under `all` every variant must be covered")))

  (test-case "flavored artifacts pin full coverage under either policy"
    (for ([c (in-list (coverage recursive-src #:flavored? #t))])
      (check-equal? (car c) (cdr c)
                    "a _count/_maint* artifact must cover every variant"))
    (for ([c (in-list (coverage recursive-src #:knob 'none #:flavored? #t))])
      (check-equal? (car c) (cdr c)
                    "the coverage knob must not partial a flavored artifact")))

  (test-case "the T4 mechanism knobs still win over the policy"
    (for ([c (in-list (coverage recursive-src #:knob 'none))])
      (check-equal? (car c) 0 "SLOG_NATIVE_COVERAGE=none covers nothing"))
    ;; even/odd bucket on the kernel ordinal, independent of designation
    (for ([c (in-list (coverage recursive-src #:knob 'even))])
      (check-equal? (car c) (ceiling (/ (cdr c) 2))
                    "SLOG_NATIVE_COVERAGE=even covers the even ordinals")))

  ;; ---- the zero-clang verdict ------------------------------------------

  (test-case "a wholly non-joining program covers nothing at all"
    ;; every stratum here is ground facts or a projection, so the whole
    ;; program's native coverage is empty and compile-strata skips clang
    (define cov (coverage
                 "table (edge int int)
                  table (copy int int)
                  table (twice int int)
                  rule (edge 1 2) (edge 2 3)
                  rule (edge X Y) --> (copy X Y)
                  rule (copy X Y) --> (twice X Y)"))
    (check-true (for/and ([c (in-list cov)]) (zero? (car c)))
                (format "expected zero coverage everywhere, got ~s" cov))
    (check-true (for/or ([c (in-list cov)]) (> (cdr c) 0))
                "the fixture must actually have variants")))
