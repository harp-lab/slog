#lang racket

;; Unit tests for compiler/stratify.rkt (Tarjan SCC condensation and
;; stratum levels), run via:  cd /home/tom/slog && raco test tests/unit/
;;
;; Typed rules are (syn (prov t t) rule <body clause> ... --> <head clause> ...)
;; with every clause syn-wrapped; see compiler/ir-shared.rkt / ir-stack.rkt.

(module+ test
  (require rackunit)
  (require "../../compiler/stratify.rkt")
  (require "../../compiler/ir-stack.rkt")

  ;; ---------------------------------------------------------------------
  ;; Builders

  (define P '(prov #f #f))
  (define (S . parts) `(syn ,P ,@parts))          ; a syn-wrapped clause
  (define (R body heads) `(syn ,P rule ,@body --> ,@heads))

  ;; The stratum level a rule was assigned, or #f if it never landed.
  (define (level-of strata r)
    (for/first ([s (in-list strata)]
                #:when (set-member? (stratum-rules s) r))
      (stratum-level s)))

  (define (levels strata) (map stratum-level strata))

  ;; ---------------------------------------------------------------------
  ;; 1. A linear chain a -> b -> c gives strictly increasing levels
  ;;    (a, underived, sits at level 0; so the rules land at 1 and 2).

  (test-case "linear chain: increasing levels, one rule per stratum"
    (define r-ab (R (list (S 'a 'x)) (list (S 'b 'x))))
    (define r-bc (R (list (S 'b 'x)) (list (S 'c 'x))))
    (define strata (stratify-rules (set r-ab r-bc)))
    (check-pred strata? strata)
    (check-equal? (levels strata) '(1 2))
    (check-equal? (level-of strata r-ab) 1)
    (check-equal? (level-of strata r-bc) 2)
    (check-equal? (stratum-rules (first strata)) (set r-ab))
    (check-equal? (stratum-rules (second strata)) (set r-bc)))

  ;; ---------------------------------------------------------------------
  ;; 2. A cycle (a -> b, b -> a) collapses to a single stratum.

  (test-case "cycle collapses to one stratum"
    (define r1 (R (list (S 'a 'x)) (list (S 'b 'x))))
    (define r2 (R (list (S 'b 'x)) (list (S 'a 'x))))
    (define strata (stratify-rules (set r1 r2)))
    (check-equal? (length strata) 1)
    (check-equal? (levels strata) '(0))
    (check-equal? (stratum-rules (first strata)) (set r1 r2)))

  ;; ---------------------------------------------------------------------
  ;; 3. Two independent sibling SCCs (s -> p and t -> q) share a level and
  ;;    merge into a single stratum.

  (test-case "independent siblings merge into one stratum"
    (define r1 (R (list (S 's 'x)) (list (S 'p 'x))))
    (define r2 (R (list (S 't 'x)) (list (S 'q 'x))))
    (define strata (stratify-rules (set r1 r2)))
    (check-equal? (length strata) 1)
    (check-equal? (levels strata) '(1))
    (check-equal? (stratum-rules (first strata)) (set r1 r2)))

  ;; ---------------------------------------------------------------------
  ;; 4. Multi-head rules make their head relations mutually dependent, so a
  ;;    cycle through only one head (q -> a) still pulls the other head (p)
  ;;    into the same SCC; downstream of the merged SCC sits one level up.
  ;;      rm: (a x) --> (p x) (q x)
  ;;      rc: (q x) --> (a x)         [closes a cycle a -> q -> a]
  ;;      rd: (p x) --> (z x)         [reads p, which the merge put in the SCC]

  (test-case "multi-head rule merges its head relations' SCCs"
    (define rm (R (list (S 'a 'x)) (list (S 'p 'x) (S 'q 'x))))
    (define rc (R (list (S 'q 'x)) (list (S 'a 'x))))
    (define rd (R (list (S 'p 'x)) (list (S 'z 'x))))
    (define strata (stratify-rules (set rm rc rd)))
    (check-equal? (levels strata) '(0 1))
    (check-equal? (level-of strata rm) 0)
    (check-equal? (level-of strata rc) 0)   ; same stratum as rm: {a,p,q} is one SCC
    (check-equal? (level-of strata rd) 1)
    (check-equal? (stratum-rules (first strata)) (set rm rc)))

  ;; ---------------------------------------------------------------------
  ;; 5. Fact rules (empty body; head holds const clauses plus the relation
  ;;    atom) land at their head relation's level, not automatically at 0.

  (test-case "facts land at their head relation's level"
    (define fa (R '() (list (S '= 'xa (S 'const 1)) (S 'a 'xa))))
    (define fb (R '() (list (S '= 'xb (S 'const 2)) (S 'b 'xb))))
    (define r-ab (R (list (S 'a 'x)) (list (S 'b 'x))))
    (define strata (stratify-rules (set fa fb r-ab)))
    (check-equal? (levels strata) '(0 1))
    (check-equal? (level-of strata fa) 0)
    (check-equal? (level-of strata fb) 1)   ; b is derived from a, so b's facts sit with b
    (check-equal? (level-of strata r-ab) 1)
    (check-equal? (stratum-rules (second strata)) (set fb r-ab)))

  ;; ---------------------------------------------------------------------
  ;; 6. A rule whose head derives no relation (only constants) is an error.

  (test-case "rule with no head relations is rejected"
    (define bad (R (list (S 'a 'x)) (list (S '= 'y (S 'const 1)))))
    (check-exn #rx"derives nothing"
               (lambda () (stratify-rules (set bad)))))

  ;; ---------------------------------------------------------------------
  ;; 7. Polarity (docs/incremental.md 0.8, A3).  A negated body atom
  ;;    (syn P ~ (syn P q x)) contributes a NEGATIVE edge: cross-SCC it
  ;;    stratifies like any edge (level(head) >= level(body)+1); inside an
  ;;    SCC it is a compile error naming the rule and cycle.

  (define (N . parts) (S '~ (apply S parts)))    ; a negated atom clause

  (test-case "negated read is a body dependency; rule-body-rels sees through ~"
    (define r (R (list (S 'a 'x) (N 'b 'x)) (list (S 'c 'x))))
    (check-equal? (rule-body-rels r) (set 'a 'b))
    (check-equal? (rule-body-neg-rels r) (set 'b))
    (check-equal? (rule-body-pos-rels r) (set 'a)))

  (test-case "a relation read both ways is in both pos and neg sets"
    (define r (R (list (S 'b 'x) (N 'b 'y)) (list (S 'c 'x))))
    (check-equal? (rule-body-pos-rels r) (set 'b))
    (check-equal? (rule-body-neg-rels r) (set 'b)))

  (test-case "cross-SCC negation stratifies below its reader"
    ;; a -> b (positive), then c derives from a while negating b:
    ;; the negative edge b -> c forces level(c) > level(b), like any edge
    (define r-ab (R (list (S 'a 'x)) (list (S 'b 'x))))
    (define r-neg (R (list (S 'a 'x) (N 'b 'x)) (list (S 'c 'x))))
    (define strata (stratify-rules (set r-ab r-neg)))
    (check-equal? (level-of strata r-ab) 1)
    (check-equal? (level-of strata r-neg) 2))

  (test-case "self-negation through recursion is rejected"
    (define bad (R (list (S 'p 'x) (N 'q 'x)) (list (S 'q 'x))))
    (check-exn #rx"negation through recursion -- not stratified"
               (lambda () (stratify-rules (set bad)))))

  (test-case "mutual-cycle negation is rejected, naming the cycle"
    (define r1 (R (list (S 'p 'x) (N 'q 'x)) (list (S 'r 'x))))
    (define r2 (R (list (S 'r 'x)) (list (S 'q 'x))))
    (check-exn #rx"cycle: q r"
               (lambda () (stratify-rules (set r1 r2)))))

  (test-case "negation against an extra-edges cycle is rejected"
    ;; extra-edges (decomp/seq style) close the cycle: rule reads ~d and
    ;; writes e; the extra edge e -> d makes {d,e} one SCC
    (define r (R (list (S 'a 'x) (N 'd 'x)) (list (S 'e 'x))))
    (check-exn #rx"negation through recursion"
               (lambda () (stratify-rules (set r) (set (cons 'e 'd)))))))
