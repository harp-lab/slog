#lang racket

;; Unit tests for the partial-prim (letp) mechanism (docs/finish-collections.md
;; §A), run via:
;;   cd /home/tom/slog && raco test tests/unit/
;;
;; A partial prim (prim-partial?, compiler/primitives.rkt) has a "no answer"
;; channel that is absent data, not a bug: operationalization lowers its let
;; to a `letp` c-op, whose emitted call takes a trailing bool* ok and whose
;; failure abandons the row.  These tests pin the registry, the lowering, and
;; the ir-stack acceptance of the new op.
;;
;; operationalization.rkt requires utils.rkt, which reads daemon headers
;; relative to the current directory at instantiation time -- so load it with
;; dynamic-require under the repo root (the planner-tests.rkt pattern).

(module+ test
  (require rackunit)
  (require racket/runtime-path)
  (require "../../compiler/primitives.rkt")
  (require "../../compiler/ir-stack.rkt")

  (define-runtime-path repo-root "../..")
  (define build-cprog
    (parameterize ([current-directory repo-root])
      (dynamic-require
       `(file ,(path->string (build-path repo-root "compiler" "operationalization.rkt")))
       'build-cprog)))

  (define P '(prov #f #f))
  (define (S . parts) `(syn ,P ,@parts))

  ;; ---------------------------------------------------------------------
  ;; The registry

  (test-case "prim-partial? registry"
    (check-true (prim-partial? 'cget))
    (check-false (prim-partial? 'chas))
    (check-false (prim-partial? '+))
    (check-false (prim-partial? 'cput)))

  ;; ---------------------------------------------------------------------
  ;; Lowering: (let x (cget m k)) -> (letp x (cget m k)); total prims stay let

  (define rel-env (hash 'env '(table any) 'got '(table any any)))

  (define rule
    `(syn ,P rule
          (syn ,P let k (syn ,P const "x"))
          (syn ,P env e)
          (syn ,P let v (syn ,P cget e k))
          (syn ,P let w (syn ,P + v v))
          -->
          (syn ,P got v w)))

  (define cprog (build-cprog (set rule) rel-env))

  (define (ops-with tag crule)
    (filter (lambda (op) (eq? tag (car op)))
            (append (crule-pre crule) (crule-body crule) (crule-head crule))))

  (test-case "operationalization lowers a partial prim to letp"
    (check-true (cprog? cprog))
    (match-define (list cr) (cprog-rules cprog))
    (define letps (ops-with 'letp cr))
    (check-equal? (length letps) 1)
    (check-match (first letps) `(letp ,_ (cget ,_ ,_)))
    ;; the total prim (+) stays a plain let (constants also lower to lets)
    (define lets (ops-with 'let cr))
    (check-true (ormap (lambda (op)
                         (match op [`(let ,_ (,f ,_ ...)) (eq? f '_0002b)] [_ #f]))
                       lets)))

  ;; ---------------------------------------------------------------------
  ;; ir-stack accepts letp in body and head position (crule? / cprog?)

  (test-case "ir-stack accepts letp"
    (define body-crule
      `(crule (pre) (scan env e)
              (body (letp v (cget e k)))
              (head (emit got (0 1) v v))
              "t.slog:1" #f))
    (define head-crule
      `(crule (pre) (scan env e)
              (body)
              (head (letp v (cget e k)) (emit got (0 1) v v))
              "t.slog:1" #f))
    (check-true (crule? body-crule))
    (check-true (crule? head-crule))
    ;; a count-flavor classification in the kind slot is accepted too
    (check-true (crule? `(crule (pre) (seeded)
                                (body (join edge (0 1) 0 x y))
                                (head (emit got (0 1) x y))
                                "t.slog:1" nonrec)))
    ;; malformed: letp of a bare variable is not a c-op
    (check-false (crule? `(crule (pre) (scan env e)
                                 (body (letp v k))
                                 (head)
                                 "t.slog:1" #f)))
    ;; malformed: an unknown kind tag
    (check-false (crule? `(crule (pre) (scan env e)
                                 (body)
                                 (head (emit got (0 1) v v))
                                 "t.slog:1" sometimes)))))
