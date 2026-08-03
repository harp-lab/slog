#lang racket

;; Unit tests for compiler/join-planning.rkt (plan-stratum), run via:
;;   cd /home/tom/slog && raco test tests/unit/
;;
;; join-planning.rkt requires utils.rkt, which reads daemon/database.h
;; relative to the current directory at instantiation time -- so we load it
;; with dynamic-require under the repo root instead of a static require.
;;
;; plan-stratum : (set/c typed-rule?) rel-env-hash (set/c symbol?)
;;             -> (cons (set/c planned-rule?) rel-env-hash)

(module+ test
  (require rackunit)
  (require racket/runtime-path)
  (require "../../compiler/ir-shared.rkt")
  (require "../../compiler/ir-stack.rkt")

  (define-runtime-path repo-root "../..")
  (define plan-stratum
    (parameterize ([current-directory repo-root])
      (dynamic-require
       `(file ,(path->string (build-path repo-root "compiler" "join-planning.rkt")))
       'plan-stratum)))

  ;; ---------------------------------------------------------------------
  ;; Builders (typed-rule shapes; see ir-stack.rkt levels 3/5)

  (define P '(prov #f #f))
  (define (S . parts) `(syn ,P ,@parts))
  (define (R body heads) `(syn ,P rule ,@body --> ,@heads))
  (define (CONST x v) (S '= x (S 'const v)))                 ; (= x (const v))
  (define (CTOR x name . args) (S '= x (apply S name args))) ; (= x (name a ...))

  (define (rule-body r)
    (match r [`(syn ,_ rule ,cls ...)
              (let-values ([(b h) (splitf-at cls (lambda (c) (not (eq? c '-->))))])
                b)]))
  (define (rule-head r)
    (match r [`(syn ,_ rule ,cls ...)
              (let-values ([(b h) (splitf-at cls (lambda (c) (not (eq? c '-->))))])
                (cdr h))]))

  ;; The relation of a body join clause, or #f for guards/lets/consts.
  (define (join-rel-of cl)
    (match cl
      [`(syn ,_ = ,_ (syn ,_ const ,_)) #f]
      [`(syn ,_ = ,_ (syn ,_ ,name ,_ ...)) name]
      [`(syn ,_ let ,_ ,_) #f]
      [`(syn ,_ /= ,_ ,_) #f]
      [`(syn ,_ == ,_ ,_) #f]
      [`(syn ,_ ,(? primitive-cmp?) ,_ ,_) #f]
      [`(syn ,_ ,name ,_ ...) name]))

  ;; clause-in-vars / clause-vars treat a const-let's literal as a variable,
  ;; so special-case (let x (const v)) when replaying a schedule.
  ;; An $oldjoin wrapper (the exact-semi-naive R_old marker, join-planning.rkt)
  ;; binds variables exactly like the join it wraps -- it only narrows WHICH
  ;; tuples are scanned (FULL - delta), not the var in/out behaviour -- so the
  ;; ordering replay treats it transparently as its inner clause.
  (define (cl-in-vars cl)
    (match cl
      [`(syn ,_ let ,_ (syn ,_ const ,_)) (set)]
      [`(syn ,_ $oldjoin ,inner) (cl-in-vars inner)]
      [_ (clause-in-vars cl)]))
  (define (cl-vars cl)
    (match cl
      [`(syn ,_ let ,x (syn ,_ const ,_)) (set x)]
      [`(syn ,_ $oldjoin ,inner) (cl-vars inner)]
      [_ (clause-vars cl)]))

  ;; Replay a planned rule: every body clause's inputs must be ground by the
  ;; clauses before it, and every head clause's inputs by the body plus
  ;; earlier head clauses.  This is the planner's core ordering contract.
  (define (check-well-ordered r)
    (check-pred planned-rule? r)
    (define body-ground
      (for/fold ([g (set)]) ([cl (in-list (rule-body r))])
        (check-true (subset? (cl-in-vars cl) g)
                    (format "body clause ~a runs before its inputs are ground in ~a"
                            (strip-prov cl) (strip-prov r)))
        (set-union g (cl-vars cl))))
    (for/fold ([g body-ground]) ([cl (in-list (rule-head r))])
      (check-true (subset? (head-in-vars cl) g)
                  (format "head clause ~a runs before its inputs are ground in ~a"
                          (strip-prov cl) (strip-prov r)))
      (set-union g (cl-vars cl)))
    (void))

  (define (plan1 rule dynamic-rels)   ; plan a single rule, return the set
    (car (plan-stratum (set rule) (hash) dynamic-rels)))

  ;; ---------------------------------------------------------------------
  ;; 1. A let written before the join that grounds its input is scheduled
  ;;    after that join (consts first, driver join, then the let).

  (test-case "lets are scheduled after their inputs are bound"
    (define r (R (list (S 'let 'y (S '+ 'x 'c))
                       (CONST 'c 1)
                       (S 'edge 'x 'z))
                 (list (S 'out 'y 'z))))
    (define planned (plan1 r (set 'out)))
    (check-equal? (set-count planned) 1)
    (for ([p (in-set planned)]) (check-well-ordered p))
    (check-equal? (strip-prov (set-first planned))
                  '(rule (let c (const 1)) (edge x z) (let y (+ x c))
                         --> (out y z))))

  ;; ---------------------------------------------------------------------
  ;; 2. Two joins on dynamic relations yield two semi-naive versions, one
  ;;    driven by each join's delta (the driver is the first body join).

  (test-case "two dynamic joins yield two versions"
    (define r (R (list (S 'e 'x 'y) (S 'f 'y 'z))
                 (list (S 'out2 'x 'z))))
    (define planned (plan1 r (set 'e 'f 'out2)))
    (check-equal? (set-count planned) 2)
    (for ([p (in-set planned)]) (check-well-ordered p))
    ;; Exact semi-naive (join-planning.rkt): the two dynamic joins are ordered
    ;; canonically e,f; the e-driven version reads f as R_old ($oldjoin) so the
    ;; (e-delta, f-delta) instantiation is counted once -- in the f-driven
    ;; version, which reads e at FULL.  (Was the pre-$oldjoin all-FULL shape.)
    (check-equal? (for/set ([p (in-set planned)]) (strip-prov p))
                  (set '(rule (e x y) ($oldjoin (f y z)) --> (out2 x z))
                       '(rule (f y z) (e x y) --> (out2 x z)))))

  ;; ---------------------------------------------------------------------
  ;; 3. The same rule over only closed (non-dynamic) relations yields a
  ;;    single version that runs once.

  (test-case "closed-relation joins yield a single version"
    (define r (R (list (S 'e 'x 'y) (S 'f 'y 'z))
                 (list (S 'out2 'x 'z))))
    (define planned (plan1 r (set 'out2)))
    (check-equal? (set-count planned) 1)
    (for ([p (in-set planned)]) (check-well-ordered p))
    (check-true
     (and (member (strip-prov (set-first planned))
                  '((rule (e x y) (f y z) --> (out2 x z))
                    (rule (f y z) (e x y) --> (out2 x z))))
          #t)))

  ;; ---------------------------------------------------------------------
  ;; 4. A repeated variable within one join is rewritten to a fresh variable
  ;;    plus an == guard restoring the constraint.

  (test-case "repeated join variables become fresh vars plus == guards"
    (define r (R (list (S 'edge 'x 'x)) (list (S 'loop 'x))))
    (define planned (plan1 r (set 'edge 'loop)))
    (check-equal? (set-count planned) 1)
    (for ([p (in-set planned)]) (check-well-ordered p))
    (match (strip-prov (set-first planned))
      [`(rule (edge x ,d) (== x ,d2) --> (loop x))
       (check-equal? d d2)
       (check-not-equal? d 'x)]
      [other (fail (format "unexpected plan: ~a" other))]))

  ;; ---------------------------------------------------------------------
  ;; 5. Head staging: a nested construction chain becomes a chain of rules
  ;;    whose temps carry exactly the variables the residue needs, in
  ;;    first-occurrence order (RF1 slice 0: occurrence order is run-stable
  ;;    where variable-name order is not -- gensym'd spellings vary).
  ;;      (edge x y) --> (= i1 (pair x y)) (= i2 (pair i1 y)) (out5 i2)
  ;;    stages into:
  ;;      (edge x y)                  --> (t1 x y) (= i1 (pair x y))
  ;;      (t1 x y) (= i1 (pair x y))  --> (t2 y i1) (= i2 (pair i1 y))
  ;;      (t2 y i1) (= i2 (pair i1 y)) --> (out5 i2)

  (test-case "nested head constructions stage into a temp-driven chain"
    (define r (R (list (S 'edge 'x 'y))
                 (list (CTOR 'i1 'pair 'x 'y)
                       (CTOR 'i2 'pair 'i1 'y)
                       (S 'out5 'i2))))
    (match-define (cons planned env+) (plan-stratum (set r) (hash) (set 'pair 'out5)))
    (check-equal? (set-count planned) 3)
    (for ([p (in-set planned)]) (check-well-ordered p))
    (define stripped (for/list ([p (in-set planned)]) (strip-prov p)))
    (define temps (for/set ([(k v) (in-hash env+)]
                            #:when (match v [`(temp ,_) #t] [_ #f]))
                    k))
    (check-equal? (set-count temps) 2)
    (for ([t (in-set temps)]) (check-equal? (hash-ref env+ t) '(temp 2)))
    ;; the parent: driven by edge, emits t1 carrying {x y} plus the inner pair
    (define parent
      (findf (match-lambda [`(rule (edge ,_ ...) ,_ ...) #t] [_ #f]) stripped))
    (check-not-false parent)
    (match parent
      [`(rule (edge x y) --> (,t1 x y) (= i1 (pair x y)))
       (check-true (set-member? temps t1))
       ;; the middle rule: driven by t1's delta, re-finds the inner pair by
       ;; content, emits t2 carrying {i1 y} plus the outer pair
       (define mid
         (findf (match-lambda [`(rule (,(== t1) ,_ ...) ,_ ...) #t] [_ #f])
                stripped))
       (check-not-false mid)
       (match mid
         [`(rule (,_ x y) (= i1 (pair x y)) --> (,t2 y i1) (= i2 (pair i1 y)))
          (check-true (set-member? temps t2))
          (check-not-equal? t2 t1)
          ;; the final rule: driven by t2's delta, emits out5
          (define fin
            (findf (match-lambda [`(rule (,(== t2) ,_ ...) ,_ ...) #t] [_ #f])
                   stripped))
          (check-not-false fin)
          (check-equal? fin `(rule (,t2 y i1) (= i2 (pair i1 y)) --> (out5 i2)))]
         [other (fail (format "unexpected middle rule: ~a" other))])]
      [other (fail (format "unexpected parent rule: ~a" other))]))

  ;; ---------------------------------------------------------------------
  ;; 6. Circular let dependencies in the body raise an error mentioning
  ;;    'circular'.

  (test-case "circular body lets raise"
    (define r (R (list (CONST 'one 1)
                       (S 'let 'a (S '+ 'b 'one))
                       (S 'let 'b (S '+ 'a 'one)))
                 (list (S 'out6 'a))))
    (check-exn #rx"circular" (lambda () (plan1 r (set 'out6)))))

  ;; ---------------------------------------------------------------------
  ;; 7. Circular let dependencies among head lets raise too.

  (test-case "circular head lets raise"
    (define r (R (list (S 'e7 'x))
                 (list (S 'let 'a (S '+ 'b 'x))
                       (S 'let 'b (S '+ 'a 'x))
                       (S 'out7 'a 'b))))
    (check-exn #rx"circular" (lambda () (plan1 r (set 'out7)))))

  ;; ---------------------------------------------------------------------
  ;; 8. A computation whose output variable the join already bound computes
  ;;    into a fresh variable and asserts equality (== check).

  (test-case "let with already-ground output becomes fresh var plus =="
    (define r (R (list (S 'e8 'x 'y)
                       (CONST 'one 1)
                       (S 'let 'y (S '+ 'x 'one)))
                 (list (S 'out8 'x))))
    (define planned (plan1 r (set 'out8)))
    (check-equal? (set-count planned) 1)
    (for ([p (in-set planned)]) (check-well-ordered p))
    (match (strip-prov (set-first planned))
      [`(rule (let one (const 1)) (e8 x y) (let ,chk (+ x one)) (== y ,chk2)
              --> (out8 x))
       (check-equal? chk chk2)
       (check-not-equal? chk 'y)]
      [other (fail (format "unexpected plan: ~a" other))]))

  ;; ---------------------------------------------------------------------
  ;; 9. A head variable no body clause can ground is an error.

  (test-case "unbound head variable raises"
    (define r (R (list (S 'e9 'x)) (list (S 'out9 'z))))
    (check-exn #rx"never bound" (lambda () (plan1 r (set 'out9)))))

  ;; ---------------------------------------------------------------------
  ;; 10. Two head constructions binding the same id (value unification) are
  ;;     rejected.

  (test-case "two head constructions binding one id raise"
    (define r (R (list (S 'e10 'x 'y))
                 (list (CTOR 'i 'pair 'x 'x)
                       (CTOR 'i 'pair 'y 'y)
                       (S 'out10 'i))))
    (check-exn #rx"value unification" (lambda () (plan1 r (set 'pair 'out10)))))

  ;; ---------------------------------------------------------------------
  ;; 11. RF1 determinism (rf1-contract.md's 2026-07-29 defect): the
  ;;     canonical walk that mints temp names must be TOTAL.  Two
  ;;     alpha-equivalent rules tie on the provenance-stripped,
  ;;     variable-blind key, and `sort` is stable -- so before the fix the
  ;;     tie group kept whatever order it arrived in, i.e. set-iteration
  ;;     order, which varies with gensym'd symbol spellings run to run.
  ;;     The rid walk (canonical-plan.rkt) orders by canonical text, which
  ;;     contains the minted temp name, so that arbitrary choice decided
  ;;     which rid recorded which SOURCE, and the plan's `meta` block
  ;;     churned.  The property under test is exactly input-order
  ;;     independence; the fix is breaking ties by source location, the
  ;;     same way the rid walk does.

  (define-values (canonical-rule-order rule-sort-key)
    (parameterize ([current-directory repo-root])
      (define planner
        `(file ,(path->string (build-path repo-root "compiler" "join-planning.rkt"))))
      (values (dynamic-require planner 'canonical-rule-order)
              (dynamic-require planner 'rule-sort-key))))

  ;; a rule whose prov carries a real (file, line), like the lexer's
  (define (located file line bodys heads)
    `(syn (prov (token id (pos ,file ,line 0 ,line 0) "") #f)
          rule ,@bodys --> ,@heads))

  (test-case "canonical rule order is input-order independent (tie groups)"
    ;; alpha-equivalent bodies, different source lines: verify.slog:79/83's
    ;; shape (same clause structure, different head relation is enough to
    ;; keep them distinct rules while the KEY still ties on structure only
    ;; if the heads match -- so use identical shape and rely on location)
    ;; lexer line positions are 0-based; rule-location-string renders 1-based
    (define a (located "v.slog" 78 (list (S 'check_err 'i 'e)) (list (S 'seen 'i 'e))))
    (define b (located "v.slog" 82 (list (S 'check_err 'j 'f)) (list (S 'seen 'j 'f))))
    ;; The keys must genuinely TIE, or this test proves nothing: with equal
    ;; keys a stable sort returns input order, which is precisely the bug.
    (check-equal? (rule-sort-key a) (rule-sort-key b))
    (check-equal? (map rule-location-string (canonical-rule-order (list a b)))
                  '("v.slog:79" "v.slog:83"))
    (check-equal? (map rule-location-string (canonical-rule-order (list b a)))
                  '("v.slog:79" "v.slog:83")))

  (test-case "line order is numeric, not lexicographic"
    ;; :9 must precede :79 -- the trap a raw string compare falls into
    (define a (located "v.slog" 8  (list (S 'p 'x)) (list (S 'q 'x))))
    (define b (located "v.slog" 78 (list (S 'p 'y)) (list (S 'q 'y))))
    (check-equal? (rule-sort-key a) (rule-sort-key b))
    (check-equal? (map rule-location-string (canonical-rule-order (list b a)))
                  '("v.slog:9" "v.slog:79"))))
