#lang racket

;; Canonical KernelPlan pass battery (docs/execution-tiers.md T1;
;; docs/execution-tiers-impl.md D3-D6).  Uses the same front-half harness as
;; wcoj3-tests.rkt, but writes each source to a FIXED temp path so two
;; canonicalizations of one program see identical rule locs (rule-meta
;; embeds "file:line"; a fresh make-temporary-file name per call would make
;; determinism trivially fail on the filename, not the pass).

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
           "../../compiler/canonical-plan.rkt"
           "../../compiler/ir-shared.rkt"
           "../../compiler/ir-stack.rkt")

  (define fixed-src
    (build-path (find-system-path 'temp-dir) "canonical-plan-tests.slog"))

  (define (cprogs-of src)
    (with-output-to-file fixed-src #:exists 'replace (lambda () (display src)))
    (match-define (list (? program-ir? program))
      (load-program-list (path->string fixed-src) (hash)))
    (define type-env (program-ir-type-env program))
    (define mods (program-ir-modules program))
    (define all-rules
      (foldl set-union (set) (map module-ir-rules (set->list mods))))
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

  (define (plan-of src)
    (match (cprogs-of src)
      [(list cp) (canonicalize-cprog cp)]
      [cps (error 'plan-of "expected one stratum, got ~a" (length cps))]))

  (define (plan-section kp key)
    (cdr (assq key (cdr kp))))

  (define (rule-defs kp) (plan-section kp 'rules))
  (define (variant-of rd) (second (third rd)))    ; (variant "tag")
  (define (rid-of rd) (second (second rd)))       ; (rid n)
  (define (nregs-of rd) (second (fourth rd)))     ; (nregs n)

  ;; every (r n) reference in a form
  (define (regs-in form)
    (match form
      [`(r ,n) (list n)]
      [(list xs ...) (append-map regs-in xs)]
      [_ '()]))

  (define recursive-triangle
    "table (edge int int)
     rule (edge A B) (edge B C) (edge A C) --> (edge C A)")

  (define nonrec-join
    "table (edge int int)
     table (out int int int)
     rule (edge A B) (edge B C) (= X (+ A B)) --> (out A B X)")

  (define with-const
    "table (edge int int)
     table (seven int)
     rule (edge A 7) --> (seven A)")

  (define fact-rule
    "table (start int)
     rule --> (start 5)")

  ;; -------------------------------------------------------------------
  (test-case "kernel-plan? accepts real plans across rule shapes"
    (for ([src (in-list (list recursive-triangle nonrec-join
                              with-const fact-rule))])
      (check-pred kernel-plan? (plan-of src))))

  (test-case "canonicalization is deterministic and edit-stable keyed"
    (define p1 (plan-of recursive-triangle))
    (define p2 (plan-of recursive-triangle))
    (check-equal? p1 p2)
    (check-equal? (kernel-plan->string p1) (kernel-plan->string p2))
    (check-equal? (kernel-plan-key p1) (kernel-plan-key p2)))

  (test-case "serialization round-trips through read"
    (define p (plan-of recursive-triangle))
    (check-equal? (read (open-input-string (kernel-plan->string p))) p))

  (test-case "same-source semi-naive variants share a rid, ordinal tags (D3)"
    (define rds (rule-defs (plan-of recursive-triangle)))
    (check-equal? (length rds) 3)
    (check-equal? (remove-duplicates (map rid-of rds)) '(0))
    (define tags (map variant-of rds))
    (check-equal? (length (remove-duplicates tags)) 3)
    (for ([t (in-list tags)])
      (check-regexp-match #rx"^delta:edge#[0-2]$" t)))

  (test-case "a single-variant rule keeps the unsuffixed emit-cpp tag"
    ;; edge is input-only here (not head-written), so it is not
    ;; stratum-dynamic and the scan reads staged full content: "all:", the
    ;; same discrimination emit-cpp's static? makes for the stat label
    (define rds (rule-defs (plan-of nonrec-join)))
    (check-equal? (length rds) 1)
    (check-equal? (variant-of (car rds)) "all:edge"))

  (test-case "fact rules carry the once driver and tag"
    (define rds (rule-defs (plan-of fact-rule)))
    (check-equal? (length rds) 1)
    (check-equal? (variant-of (car rds)) "once")
    (check-match (assq 'driver (cdr (car rds))) `(driver (once))))

  (test-case "body constants take (k n) slots loaded in pre"
    (define kp (plan-of with-const))
    (check-equal? (length (plan-section kp 'constants)) 1)
    (check-match (plan-section kp 'constants) `((k 0 ,_ ,_)))
    (define rd (car (rule-defs kp)))
    (check-match (assq 'pre (cdr rd)) `(pre (let (r 0) (k 0)))))

  (test-case "registers are dense and bounded by nregs"
    (for ([src (in-list (list recursive-triangle nonrec-join with-const))])
      (for ([rd (in-list (rule-defs (plan-of src)))])
        (define rs (regs-in rd))
        (check-true (andmap (lambda (r) (< r (nregs-of rd))) rs))
        (check-equal? (sort (remove-duplicates rs) <)
                      (range (nregs-of rd))))))

  (test-case "join3 arms carry (rel n) slots and (r n) registers"
    (define rds (rule-defs (plan-of recursive-triangle)))
    (define j3s
      (for*/list ([rd (in-list rds)]
                  [op (in-list (cdr (assq 'body (cdr rd))))]
                  #:when (eq? (car op) 'join3))
        op))
    (check-equal? (length j3s) 3)
    (for ([j3 (in-list j3s)])
      (check-match j3
        `(join3 (r ,_)
                (,_ (rel ,_) ,_ ,_ ,_ (r ,_) (r ,_))
                (,_ (rel ,_) ,_ ,_ ,_ (r ,_) (r ,_))))))

  (test-case "prims collect into a sorted opcode table"
    (define kp (plan-of nonrec-join))
    (define prims (plan-section kp 'prims))
    (check-equal? (length prims) 1)        ; the escaped +
    (check-pred symbol? (car prims)))

  (test-case "canonical-rule-tags aligns with cprog rule order"
    (match-define (list cp) (cprogs-of recursive-triangle))
    (define tags (canonical-rule-tags cp))
    (check-equal? (length tags) (length (cprog-rules cp)))
    (define plan-tags
      (sort (map variant-of (rule-defs (canonicalize-cprog cp))) string<?))
    (check-equal? (sort (map cdr tags) string<?) plan-tags)
    (check-true (andmap (lambda (t) (= (car t) 0)) tags)))

  (test-case "the wcoj3 off-switch changes the plan and its key"
    (define on (plan-of recursive-triangle))
    (define off (parameterize ([wcoj3-enabled #f])
                  (plan-of recursive-triangle)))
    (check-not-equal? (kernel-plan-key on) (kernel-plan-key off)))

  ;; ---------------------------------------------------------------------
  ;; ABI 2: cohort bytes are input-order independent even for
  ;; exec-identical rules -- the THIRD instance of the slice-0.1 trap,
  ;; caught by the first SLOG_PLAN_ABI=2 plan-determinism run (2026-08-05,
  ;; 7/506 plans): two alpha-equivalent rules over the SAME relations tie
  ;; on blind AND global text, so the residual tie fell to set-iteration
  ;; order, and the ord <-> (rid, source) pairing in the DebugMap churned
  ;; run to run while the exec bytes stayed identical.  kernel-parts now
  ;; tiebreaks by the rid walk (loc-tiebroken, run-stable); the property
  ;; under test is exactly input-order independence of the WHOLE cohort --
  ;; exec, binding, dynamic AND debug.

  (define (cprogs+model-of src)
    (with-output-to-file fixed-src #:exists 'replace (lambda () (display src)))
    (match-define (list (? program-ir? program))
      (load-program-list (path->string fixed-src) (hash)))
    (define type-env (program-ir-type-env program))
    (define mods (program-ir-modules program))
    (define all-rules
      (foldl set-union (set) (map module-ir-rules (set->list mods))))
    (define typed
      (typecheck-rules type-env
                       (foldl simplify-rule (set) (set->list all-rules))))
    (define-values (strata model) (stratify-rules/model typed))
    (values
     (for/list ([stratum (in-list strata)])
       (define rules (stratum-rules stratum))
       (define dynamic-rels
         (for/fold ([acc (set)]) ([rule (in-set rules)])
           (set-union acc (rule-head-rels rule))))
       (match-define (cons planned rel-env+)
         (plan-stratum rules (type-env-rels type-env) dynamic-rels))
       (build-cprog planned rel-env+))
     model))

  (test-case "ABI-2 cohort bytes are input-order independent (tied rules)"
    (define-values (cps model)
      (cprogs+model-of
       "table (edge int int)
        table (out int int)
        rule (edge X Y) --> (out X Y)

        rule (edge A B) --> (out A B)"))
    ;; the fixture must actually produce a tied pair in some stratum, or
    ;; this test proves nothing
    (define tied 0)
    (for ([cp (in-list cps)])
      (define rev
        (list 'cprog (cprog-dynamic-rels cp) (cprog-constants cp)
              (cprog-decls cp) (reverse (cprog-rules cp))))
      (check-equal?
       (kernel-plan->string (canonicalize-cprog/abi2 rev model))
       (kernel-plan->string (canonicalize-cprog/abi2 cp model)))
      (when (>= (length (cprog-rules cp)) 2) (set! tied (add1 tied))))
    (check >= tied 1))

  ;; ---------------------------------------------------------------------
  ;; RF1 slice 3: the closed plan-attribute vocabulary
  ;; (docs/rf1-contract.md "Flavored-plan attributes").  Absent-when-empty
  ;; is the byte-defining decision under test: a normal-flavor cohort must
  ;; carry NO attribute spellings at all (its exec bytes -- and every
  ;; normal KernelPlanKey -- survive the slice unchanged), while a counted
  ;; cohort emitted under the real planning toggle carries the kernel
  ;; attribute and its kinded rules carry (attrs (fold ...)).

  (test-case "flavored cohorts carry attributes; normal carries none"
    (define-values (cps model)
      (cprogs+model-of
       "table (edge int int)
        table (out int int)
        rule (edge X Y) --> (out X Y)"))
    (define cp
      (or (findf (lambda (c) (pair? (cprog-rules c))) cps)
          (error 'slice3-test "no rule-bearing stratum")))
    ;; normal flavor, default toggles: no attribute spellings anywhere
    (define normal (kernel-plan->string (canonicalize-cprog/abi2 cp model)))
    (check-false (regexp-match? #rx"[(]attributes" normal))
    (check-false (regexp-match? #rx"[(]attrs " normal))
    ;; counted: the flavored planners run with semijoin lookahead OFF and
    ;; kinded crules (crule-kind is the seventh field); reproduce both
    (define kinded
      (list 'cprog (cprog-dynamic-rels cp) (cprog-constants cp)
            (cprog-decls cp)
            (map (lambda (r) (list-set r 6 'nonrec)) (cprog-rules cp))))
    (define counted
      (parameterize ([semijoin-filters-enabled #f])
        (kernel-plan->string
         (canonicalize-cprog/abi2 kinded model #:flavor 'count))))
    (check-true (regexp-match? #rx"[(]attributes no-semijoin-reopt[)]" counted))
    (check-true (regexp-match? #rx"[(]attrs [(]fold nonrec[)][)]" counted))
    ;; the display variant keeps the "/<kind>" rendering of the same fact
    (check-true (regexp-match? #rx"/nonrec" counted)))

  (test-case "attribute validators reject unknowns"
    (check-exn #rx"unknown kernel attribute"
               (lambda () (validate-kernel-attributes! '(semijoin-off))))
    (check-not-exn
     (lambda () (validate-kernel-attributes! '(no-semijoin-reopt))))
    (check-exn #rx"unknown rule attribute"
               (lambda () (validate-rule-attrs! '((fold prov)))))
    (check-not-exn
     (lambda () (validate-rule-attrs! '((fold rec) (fold input)))))))
