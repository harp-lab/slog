#lang racket

;; Unit tests for the IR level predicates in compiler/ir-stack.rkt and the
;; shared clause analysis in compiler/ir-shared.rkt, run via:
;;   cd /home/tom/slog && raco test tests/unit/
;;
;; One representative well-formed value per level, plus targeted malformed
;; variants that each predicate must reject.
;;
;; Known discrepancy, deliberately NOT asserted here: ir-stack.rkt documents
;; the flat head grammar as "all but /= and cmp guards", but join-clause?'s
;; exclusion list ('(= /= == let const)) omits < <= > >=, so flat-rule? and
;; planned-rule? accept e.g. (< x y) as a head clause (treated as a join on a
;; relation named <).  Reported as a compiler bug, not codified as a golden.

(module+ test
  (require rackunit)
  (require "../../compiler/ir-shared.rkt")
  (require "../../compiler/ir-stack.rkt")

  (define P '(prov #f #f))
  (define (S . parts) `(syn ,P ,@parts))

  ;; ---------------------------------------------------------------------
  ;; syn wrappers and strip-prov

  (test-case "syn? / strip-prov"
    (check-true (syn? (S 'edge 'x 'y)))
    (check-false (syn? '(edge x y)))
    (check-false (syn? '(syn edge x y)))         ; no (prov _ _)
    (check-equal? (strip-prov (S 'rule (S 'edge 'x 'y) '--> (S 'out 'x)))
                  '(rule (edge x y) --> (out x))))

  ;; ---------------------------------------------------------------------
  ;; Level 0: module-ast

  (test-case "module-ast?"
    (check-true (module-ast? `(module "f.slog" () ,(S 'topbody))))
    (check-true (module-ast? `(module "f.slog" ((token a 1 2)) ,(S 'topbody))))
    (check-false (module-ast? `(module f.slog () ,(S 'topbody))))   ; path not a string
    (check-false (module-ast? `(module "f.slog" () (topbody))))     ; body not syn-wrapped
    (check-false (module-ast? `(module "f.slog" ())))               ; missing body
    (check-false (module-ast? '())))

  ;; ---------------------------------------------------------------------
  ;; Level 1: program / program-list

  (test-case "program? / program-list?"
    (define prog `(program ,empty-type-env ,(set) ,(hash) ,(hash)))
    (check-true (program? prog))
    (check-true (program-list? (list prog prog)))
    (check-true (program-list? '()))
    (check-false (program? `(program (,(hash) ,(hash)) ,(set) ,(hash) ,(hash)))) ; 2-part type-env
    (check-false (program? `(program ,empty-type-env () ,(hash) ,(hash))))       ; mods not a set
    (check-false (program? `(program ,empty-type-env ,(set) ,(list) ,(hash))))   ; manifest not a hash
    (check-false (program? `(program ,empty-type-env ,(set) ,(hash))))  ; missing decomp-env
    (check-false (program-list? prog))          ; one program is not a program list
    (check-false (program-list? (list prog 'x))))

  ;; ---------------------------------------------------------------------
  ;; Levels 2/3: flat and typed rules
  ;;
  ;;   flat body ::= /=, cmp guards | (= x (const v)) | (= x (name x...)) | (name x...)
  ;;   flat head ::= consts and join clauses
  ;;   typed     ::= flat + (let x ...) clauses on both sides

  (define flat-r
    (S 'rule (S 'edge 'x 'y)                 ; relation pattern
             (S '= 'z (S 'const 1))          ; constant
             (S '= 'w (S 'pair 'x 'y))       ; struct pattern
             (S '/= 'x 'y)                   ; guard
             (S '< 'x 'z)                    ; cmp guard
             '-->
             (S 'out 'x 'w)
             (S '= 'k (S 'const "s"))))

  (define typed-r
    (S 'rule (S 'edge 'x 'y)
             (S 'let 'c (S 'const 5))        ; let-bound constant
             (S 'let 'z (S '+ 'x 'c))        ; primitive computation
             (S 'let 'z2 'z)                 ; variable alias
             (S '/= 'z2 'y)
             '-->
             (S 'let 'w (S '* 'z 'z))
             (S '= 'i (S 'pair 'w 'x))
             (S 'out 'i)))

  (test-case "flat-rule? accepts flat shapes"
    (check-true (flat-rule? flat-r))
    (check-true (flat-rule? (S 'rule '--> (S 'a 'x)))))   ; fact rule: empty body

  (test-case "flat-rule? rejects malformed shapes"
    (check-false (flat-rule? typed-r))                    ; lets are typed-level
    (check-false (flat-rule? (S 'rule (S 'edge 'x 1) '--> (S 'out 'x))))   ; literal arg
    (check-false (flat-rule? (S 'rule (S 'edge 'x (S 'pair 'a 'b)) '--> (S 'out 'x)))) ; nested arg
    (check-false (flat-rule? (S 'rule (S 'edge 'x 'y) '--> (S '/= 'x 'y)))) ; guard in head
    (check-false (flat-rule? (S 'rule '(edge x y) '--> (S 'out 'x))))      ; clause not syn-wrapped
    (check-false (flat-rule? (S 'rule (S 'edge 'x 'y) (S 'out 'x))))       ; missing -->
    (check-false (flat-rule? '(rule)))
    ;; a const clause may only carry a slog literal (number/string/symbol)
    (check-false (flat-rule? (S 'rule (S '= 'x (S 'const '(1 2))) '--> (S 'out 'x)))))

  (test-case "typed-rule? accepts flat plus lets, rejects bad lets"
    (check-true (typed-rule? flat-r))                     ; flat is a subset of typed
    (check-true (typed-rule? typed-r))
    (check-false (typed-rule? (S 'rule (S 'let 'x 5) '--> (S 'out 'x))))   ; literal rhs
    (check-false (typed-rule? (S 'rule (S 'let 'x (S '+ 'y 1)) '--> (S 'out 'x)))) ; literal arg
    (check-false (typed-rule? (S 'rule (S 'edge 'x 'y) '--> (S '/= 'x 'y)))) ; guard in head
    ;; == equality checks are introduced by the planner: planned-level only
    (check-false (typed-rule? (S 'rule (S 'edge 'x 'y) (S '== 'x 'y) '--> (S 'out 'x))))
    (check-true (planned-rule? (S 'rule (S 'edge 'x 'y) (S '== 'x 'y) '--> (S 'out 'x))))
    ;; a comparison guard is not a join, so it cannot appear as a head
    (check-false (typed-rule? (S 'rule (S 'edge 'x 'y) '--> (S '< 'x 'y)))))

  ;; ---------------------------------------------------------------------
  ;; Level 4: strata

  (test-case "stratum? / strata? / accessors"
    (define s0 `(stratum 0 ,(set typed-r)))
    (define s1 `(stratum 1 ,(set)))
    (check-true (stratum? s0))
    (check-true (stratum? s1))
    (check-false (stratum? `(stratum -1 ,(set typed-r))))     ; negative level
    (check-false (stratum? `(stratum 0 ,(list typed-r))))     ; rules must be a set
    (check-false (stratum? `(stratum 0 ,(set '(bogus)))))     ; rules must be typed rules
    (check-false (stratum? `(stratum ,(set typed-r))))        ; missing level
    (check-true (strata? (list s0 s1)))
    (check-true (strata? '()))
    (check-false (strata? s0))                                ; one stratum is not strata
    (check-false (strata? (list s0 'x)))
    (check-equal? (stratum-level s1) 1)
    (check-equal? (stratum-rules s0) (set typed-r)))

  ;; ---------------------------------------------------------------------
  ;; Level 5: planned rules -- ordered bodies of joins/lets/guards; heads of
  ;; lets and joins only (raw const clauses have become lets).

  (test-case "planned-rule?"
    (define planned-r
      (S 'rule (S 'let 'c (S 'const 1))
               (S 'edge 'x 'y)
               (S '/= 'x 'c)
               (S 'let 'z (S '+ 'x 'c))
               (S '== 'z 'y)
               '-->
               (S 'let 'w (S '+ 'z 'c))
               (S '= 'i (S 'pair 'w 'x))
               (S 'out 'i)))
    (check-true (planned-rule? planned-r))
    (check-true (planned-rule? typed-r))       ; typed shapes minus raw consts fit
    ;; raw (= x (const v)) clauses must not survive planning
    (check-false (planned-rule?
                  (S 'rule (S '= 'c (S 'const 1)) (S 'edge 'x 'y) '--> (S 'out 'x))))
    (check-false (planned-rule?
                  (S 'rule (S 'edge 'x 'y) '--> (S '= 'k (S 'const 1)) (S 'out 'x))))
    ;; guards may not appear in heads
    (check-false (planned-rule? (S 'rule (S 'edge 'x 'y) '--> (S '/= 'x 'y))))
    (check-false (planned-rule? (S 'rule (S 'edge 'x 'y) '--> (S '== 'x 'y)))))

  ;; ---------------------------------------------------------------------
  ;; Level 6: c-programs

  (test-case "crule? and accessors"
    (define cr
      `(crule (pre (let cc five))
              (probe edge (1 2) 1 x y)
              (body (join f (2 1) 1 y z)
                    (cmp lt x z)
                    (neq x y)
                    (let s (plus x cc))
                    (eq s z))
              (head (let w (plus s s))
                    (mkstruct pair (1 2 3) i w x)
                    (emit out (1 2) i w)
                    (emit-temp t1 i))
              "t.slog:1"))
    (check-true (crule? cr))
    (check-true (crule? '(crule (pre) (once) (body) (head) #f)))    ; fact rule, no loc
    (check-true (crule? '(crule (pre) (scan edge x y) (body) (head (emit out (1 2) x y)) "t.slog:2")))
    ;; the trailing loc ("file:line" or #f, docs/type-errors.md) is required
    (check-false (crule? '(crule (pre) (once) (body) (head))))
    (check-equal? (crule-pre cr) '((let cc five)))
    (check-equal? (crule-driver cr) '(probe edge (1 2) 1 x y))
    (check-equal? (crule-body cr)
                  '((join f (2 1) 1 y z) (cmp lt x z) (neq x y)
                    (let s (plus x cc)) (eq s z)))
    (check-equal? (crule-head cr)
                  '((let w (plus s s)) (mkstruct pair (1 2 3) i w x)
                    (emit out (1 2) i w) (emit-temp t1 i)))
    ;; rejections
    (check-false (crule? '(crule (pre) (body) (head) #f)))          ; missing driver
    (check-false (crule? '(crule (pre) (join e (1) 1 x) (body) (head) #f))) ; join is not a driver
    (check-false (crule? '(crule (pre) (probe e () 0 x) (body) (head) #f))) ; empty index
    (check-false (crule? '(crule (pre) (scan e x) (body (join f (1) x)) (head) #f))) ; join missing K
    (check-false (crule? '(crule (pre) (scan e x) (body) (head (let x y)) #f)))      ; head alias let
    (check-false (crule? '(crule (pre) (scan e x) (body) (head (join f (1) 1 x)) #f))) ; join in head
    (check-false (crule? '(crule (pre (emit out (1) x)) (scan e x) (body) (head) #f)))) ; emit in pre

  (test-case "cprog? and accessors"
    (define cr '(crule (pre) (scan edge x y) (body) (head (emit out (1 2) x y)) "t.slog:3"))
    (define decls '((relation edge 2 (1 2) (delta 1))
                    (relation out 2 (1 2))
                    (struct pair 3 (1 2 3 0) (0 1 2 3))
                    (temp t1 2)))
    (define cp `(cprog ,(set 'out) ,(hash "5" 'five) ,decls (,cr)))
    (check-true (cprog? cp))
    (check-equal? (cprog-dynamic-rels cp) (set 'out))
    (check-equal? (cprog-constants cp) (hash "5" 'five))
    (check-equal? (cprog-decls cp) decls)
    (check-equal? (cprog-rules cp) (list cr))
    ;; rejections
    (check-false (cprog? `(cprog ,(set) ,(hash)
                                 ((struct pair 3 (1 2 3 0)))       ; structs need >= 2 indices
                                 ())))
    (check-false (cprog? `(cprog ,(set) ,(hash)
                                 ((temp t1))                       ; temp missing arity
                                 ())))
    (check-false (cprog? `(cprog ,(set) ,(hash) ,decls ((crule (pre) (body) (head) #f)))))
    (check-false (cprog? `(cprog () ,(hash) ,decls ())))           ; dyn-rels not a set
    (check-false (cprog? `(cprog ,(set) ,(hash) ,decls ,cr))))     ; rules not a list

  ;; ---------------------------------------------------------------------
  ;; Shared clause analysis (ir-shared.rkt) over the typed/planned grammar.

  (test-case "clause variable analysis"
    ;; join clauses ground everything, require nothing
    (check-equal? (clause-vars (S 'edge 'x 'y)) (set 'x 'y))
    (check-equal? (clause-in-vars (S 'edge 'x 'y)) (set))
    (check-equal? (clause-out-vars (S 'edge 'x 'y)) (set 'x 'y))
    ;; struct patterns include the id
    (check-equal? (clause-vars (S '= 'i (S 'pair 'x 'y))) (set 'i 'x 'y))
    (check-equal? (clause-in-vars (S '= 'i (S 'pair 'x 'y))) (set))
    ;; guards require both sides
    (check-equal? (clause-in-vars (S '< 'x 'y)) (set 'x 'y))
    (check-equal? (clause-in-vars (S '/= 'x 'y)) (set 'x 'y))
    (check-equal? (clause-out-vars (S '== 'x 'y)) (set))
    ;; lets require their arguments and bind their output
    (check-equal? (clause-in-vars (S 'let 'z (S '+ 'x 'y))) (set 'x 'y))
    (check-equal? (clause-out-vars (S 'let 'z (S '+ 'x 'y))) (set 'z))
    (check-equal? (clause-in-vars (S 'let 'z 'y)) (set 'y))
    ;; constants require nothing
    (check-equal? (clause-in-vars (S '= 'x (S 'const 1))) (set))
    (check-equal? (clause-out-vars (S '= 'x (S 'const 1))) (set 'x))
    ;; head reading: an emit consumes its columns; a construction consumes
    ;; its fields and produces only the id
    (check-equal? (head-in-vars (S 'out 'x 'y)) (set 'x 'y))
    (check-equal? (head-in-vars (S '= 'i (S 'pair 'x 'y))) (set 'x 'y))
    (check-equal? (head-in-vars (S '= 'k (S 'const 1))) (set)))

  ;; ---------------------------------------------------------------------
  ;; Type-environment helpers (ir-shared.rkt).

  (test-case "type-env helpers"
    (check-true (type-env? empty-type-env))
    (check-false (type-env? (list (hash) (hash))))
    (check-equal? (rel-decl-arity '(table int int)) 2)
    (check-equal? (rel-decl-arity '(struct int str any)) 3)
    (check-equal? (rel-decl-arity '(temp 4)) 4)
    (check-equal? (rel-decl-arity '(enum bool)) 0)
    (check-equal? (rel-decl-kind '(table int)) 'table)))
