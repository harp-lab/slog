#lang racket

;; Spine slice A1 battery (docs/activation-contract.md §5): the
;; ProgramChangeSet consumer over the golden corpus.  Accept/refuse pinned
;; per fixture, plan contents pinned for the accepting cases, and the
;; determinism claim (same fixture, environment, layer/event -> the same
;; plan) asserted directly -- the property that lets replay re-derive
;; rather than persist.

(module+ test
  (require rackunit
           racket/runtime-path
           "../../compiler/activation.rkt")

  (define-runtime-path corpus-dir "../activation")

  (define (load-cs name)
    (parse-change-set
     (call-with-input-file (build-path corpus-dir name) read)))

  (define base
    (base-env "p1:layer-base:0" "b1:layer-base:0" #t
              (hash 'edge "v1:layer-base:0:0"
                    'path "v1:layer-base:0:1"
                    'left.edge "v1:layer-base:0:0"
                    'left.path "v1:layer-base:0:1"
                    'right.edge "v1:layer-base:0:2"
                    'right.path "v1:layer-base:0:3"
                    'answer "v1:layer-base:0:4")
              '(smt seq)))

  (define (resolve name #:env [env base])
    (define cs (load-cs name))
    (check-pred change-set? cs (format "~a parses" name))
    (resolve-activation cs env #:layer "layer-new" #:event 1))

  ;; ---- the accepting cases -------------------------------------------------

  (test-case "minimal: one occurrence, carry + rebuild, fresh identities"
    (define plan (resolve "minimal.pcs"))
    (check-pred activation-plan? plan)
    (check-equal? (activation-plan-program-key plan) "p1:layer-new:1")
    (check-equal? (hash-ref (activation-plan-module-keys plan)
                            "m1:p1:layer-base:0:root")
                  "m1:p1:layer-new:1:root")
    ;; three lineage rows -> three successor RuleKeys under the new occurrence
    (check-equal? (activation-plan-rule-keys plan)
                  '("r1:m1:p1:layer-new:1:root:0.0"
                    "r1:m1:p1:layer-new:1:root:0.1"
                    "r1:m1:p1:layer-new:1:root:0.2"))
    ;; edge carries its committed VersionKey; path gets a fresh slot
    (check-equal? (hash-ref (activation-plan-version-allocs plan) 'edge)
                  '("v1:layer-base:0:0" "v1:layer-base:0:0" carry))
    (check-match (hash-ref (activation-plan-version-allocs plan) 'path)
                 (list "v1:layer-base:0:1"
                       (regexp #rx"^v1:layer-new:1:") 'rebuild))
    (check-equal? (activation-plan-route plan) 'correctness-first)
    (check-equal? (activation-plan-publication plan) 'hold-at-gate))

  (test-case "two-instance: only the replaced instance's writers rebuild"
    (define plan (resolve "two-instance.pcs"))
    (check-pred activation-plan? plan)
    ;; left's slots CARRY -- the RF5-B gate's outside-cone reuse claim
    (for ([q '(left.edge left.path)])
      (check-equal? (third (hash-ref (activation-plan-version-allocs plan) q
                                     '(#f #f rebuild)))
                    'carry (format "~a carries" q))
      (check-equal? (second (hash-ref (activation-plan-version-allocs plan) q))
                    (hash-ref (base-env-versions base) q)))
    ;; right's + answer's rebuild fresh
    (for ([q '(right.edge right.path answer)])
      (check-equal? (third (hash-ref (activation-plan-version-allocs plan) q))
                    'rebuild))
    ;; the successor occurrence sits at the SAME lexical slot under the
    ;; new program key -- occurrence identity moved with the image, slots
    ;; did not (rf5 §2)
    (check-equal? (hash-ref (activation-plan-module-keys plan)
                            "m1:p1:layer-base:0:1")
                  "m1:p1:layer-new:1:1")
    (check-equal? (length (activation-plan-scc-keys plan)) 3))

  (test-case "suffix-batch: a batch against a carried anchor maps"
    (define plan (resolve "suffix-batch.pcs"))
    (check-pred activation-plan? plan)
    (check-equal? (length (activation-plan-suffix plan)) 1))

  ;; ---- determinism ----------------------------------------------------------

  (test-case "resolution is a pure function of (fixture, env, layer/event)"
    (check-equal? (resolve "minimal.pcs") (resolve "minimal.pcs"))
    ;; and a different event mints wholly different identities
    (define other (resolve-activation (load-cs "minimal.pcs") base
                                      #:layer "layer-new" #:event 2))
    (check-not-equal? (activation-plan-program-key (resolve "minimal.pcs"))
                      (activation-plan-program-key other)))

  ;; ---- the refusals, each typed and state-free -------------------------------

  (define (refusal-of name #:env [env base])
    (define r (resolve name #:env env))
    (check-pred activation-refusal? r (format "~a refuses" name))
    (second r))

  (test-case "a fixture-carried compiler refusal surfaces first"
    (check-equal? (refusal-of "carries-refusal.pcs") 'fixture-refusal))

  (test-case "a later program event in the suffix is the rf5 §8 refusal"
    (check-equal? (refusal-of "suffix-program.pcs")
                  'historical-program-replacement))

  (test-case "the wrong boundary refuses by name"
    (check-equal? (refusal-of "minimal.pcs"
                              #:env (struct-copy base-env base
                                                 [boundary-key "b1:other:0"]))
                  'unknown-base-boundary))

  (test-case "a non-tip base refuses as stale"
    (check-equal? (refusal-of "minimal.pcs"
                              #:env (struct-copy base-env base [tip? #f]))
                  'stale-base))

  (test-case "a carried slot the boundary does not hold is a conflict"
    (check-equal? (refusal-of "minimal.pcs"
                              #:env (struct-copy base-env base
                                                 [versions (hash 'path "v1:layer-base:0:1")]))
                  'slot-lineage-conflict))

  (test-case "an occurrence outside the base program refuses"
    (define cs (load-cs "two-instance.pcs"))
    (define hacked
      (struct-copy change-set cs
                   [occurrences (list (list "m1:p1:other:0:1" '((1 "right")) '((1 "right"))))]))
    (check-equal? (second (resolve-activation hacked base
                                              #:layer "layer-new" #:event 1))
                  'unknown-occurrence))

  (test-case "an unservable requirement refuses"
    (define cs (load-cs "minimal.pcs"))
    (define hacked (struct-copy change-set cs [services '(z3-hardware)]))
    (check-equal? (second (resolve-activation hacked base
                                              #:layer "layer-new" #:event 1))
                  'unsupported-service))

  (test-case "malformed datums refuse at parse, not at resolve"
    (check-pred activation-refusal? (parse-change-set '(not-a-change-set)))
    (check-pred activation-refusal?
                (parse-change-set '(program-change-set (abi 1) (base broken))))))
