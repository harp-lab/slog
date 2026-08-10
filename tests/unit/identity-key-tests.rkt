#lang racket

;; T0(c) slice c1 battery: RuleKey/SccInstanceKey construction
;; (docs/t0-contract.md "Persistent identity and rule-meta").
;;
;; The GOLDEN KEY CORPUS resolves the contract's open question 1: the wire
;; spelling is the m1:/v1:/b1: compact colon-string family, and these exact
;; strings are pinned -- a change to any of them is a re-key event and must
;; say so in its commit.

(module+ test
  (require rackunit
           "../../compiler/catalog.rkt")

  ;; ---- the corpus ---------------------------------------------------------

  (define PKEY "p1:layer-test:0")

  (test-case "golden key corpus: the exact wire spellings"
    (check-equal? (module-instance-key PKEY '()) "m1:p1:layer-test:0:root")
    (check-equal? (module-instance-key PKEY '((0 "left")))
                  "m1:p1:layer-test:0:0")
    (check-equal? (module-instance-key PKEY '((1 "right") (0 "inner")))
                  "m1:p1:layer-test:0:1.0")
    (check-equal? (rule-key "m1:p1:layer-test:0:root" 0 3)
                  "r1:m1:p1:layer-test:0:root:0.3")
    (check-equal? (rule-key "m1:p1:layer-test:0:1.0" 2 0)
                  "r1:m1:p1:layer-test:0:1.0:2.0")
    (check-equal? (scc-instance-key PKEY 4) "scc1:p1:layer-test:0:4"))

  (test-case "malformed components refuse loudly"
    (check-exn exn:fail? (lambda () (rule-key 'not-a-string 0 0)))
    (check-exn exn:fail? (lambda () (rule-key "m1:x" -1 0)))
    (check-exn exn:fail? (lambda () (scc-instance-key PKEY 'x))))

  ;; ---- minting from a payload --------------------------------------------

  (define payload
    '(program-identity
      (sccs (scc 0 0 (members edge seed))
            (scc 1 1 (members path)))
      (occurrences
       (occurrence (lexical-path ())
                   (units (unit 0 (rules (rule 0 (loc "main.slog:3") (scc 0))
                                         (rule 1 (loc "main.slog:5") (scc 1))))))
       (occurrence (lexical-path ((0 "lib")))
                   (units (unit 0 (rules (rule 0 (loc "lib.slog:2") (scc 1)))))))))

  (test-case "mint-program-identity composes the family correctly"
    (define-values (sccs rules) (mint-program-identity PKEY payload))
    (check-equal?
     sccs
     '((scc-record "scc1:p1:layer-test:0:0" 0 0 (members edge seed))
       (scc-record "scc1:p1:layer-test:0:1" 1 1 (members path))))
    (check-equal?
     rules
     '((rule-record "r1:m1:p1:layer-test:0:root:0.0" "m1:p1:layer-test:0:root"
                    (scc "scc1:p1:layer-test:0:0") (loc "main.slog:3"))
       (rule-record "r1:m1:p1:layer-test:0:root:0.1" "m1:p1:layer-test:0:root"
                    (scc "scc1:p1:layer-test:0:1") (loc "main.slog:5"))
       (rule-record "r1:m1:p1:layer-test:0:0:0.0" "m1:p1:layer-test:0:0"
                    (scc "scc1:p1:layer-test:0:1") (loc "lib.slog:2")))))

  (test-case "a rule outside every SCC carries (scc #f), never a guess"
    (define-values (_sccs rules)
      (mint-program-identity
       PKEY
       '(program-identity
         (sccs)
         (occurrences
          (occurrence (lexical-path ())
                      (units (unit 0 (rules (rule 0 (loc #f) (scc #f))))))))))
    (check-match rules
                 (list `(rule-record ,_ ,_ (scc #f) (loc #f)))))

  (test-case "minting is a pure function of (key, payload)"
    (define-values (a1 b1) (mint-program-identity PKEY payload))
    (define-values (a2 b2) (mint-program-identity PKEY payload))
    (check-equal? a1 a2)
    (check-equal? b1 b2)
    ;; and a different program key changes EVERY key -- immutable-image
    ;; semantics: keys are never reused for different content (RF5 §2)
    (define-values (a3 b3) (mint-program-identity "p1:layer-test:1" payload))
    (check-true (for/and ([r1 (in-list b1)] [r3 (in-list b3)])
                  (not (equal? (second r1) (second r3)))))))
