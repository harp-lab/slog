#lang racket

;; QName authority battery (docs/modules.md §8.1 N0; docs/n0-seam-map.md).
;; Two halves: the compiler/names.rkt API itself, and the parser's
;; name-path collapse -- id.id chains become one lowered dotted symbol in
;; every position an id can appear, while non-id operands keep the dormant
;; binary dot operator tree and the float/ellipsis lexemes are untouched.

(module+ test
  (require rackunit
           "../../compiler/names.rkt"
           "../../compiler/parser.rkt")

  ;; ---- components and construction ----------------------------------
  (check-true (valid-component? "model"))
  (check-true (valid-component? "value_2'"))
  (check-true (valid-component? "_lat"))
  (check-false (valid-component? ""))
  (check-false (valid-component? "a.b"))       ; no dots inside components
  (check-false (valid-component? "a b"))
  (check-false (valid-component? "a$b"))       ; $ stays compiler-reserved
  (check-exn exn:fail? (lambda () (qname '())))
  (check-exn exn:fail? (lambda () (qname '("a" "b.c"))))

  ;; ---- lowering: the byte-identity invariant -------------------------
  ;; single-component names lower to LITERALLY the same symbol
  (check-eq? (qname->symbol (qname '("edge"))) 'edge)
  (check-true (qname-root? (qname '("edge"))))
  ;; multi-component: dotted printed form, reversible
  (define mv (qname '("model" "value")))
  (check-eq? (qname->symbol mv) 'model.value)
  (check-equal? (qname-components (symbol->qname 'model.value))
                '("model" "value"))
  (check-equal? (qname-components (symbol->qname 'a.bc.r)) '("a" "bc" "r"))
  (check-equal? (qname-components (symbol->qname 'ab.c.r)) '("ab" "c" "r"))
  ;; the §2.2 collision pair stays distinct end to end
  (check-not-eq? (qname->symbol (symbol->qname 'a.bc.r))
                 (qname->symbol (symbol->qname 'ab.c.r)))
  ;; malformed lowered symbols are rejected, never mis-split
  (check-exn exn:fail? (lambda () (symbol->qname '|a..b|)))
  (check-exn exn:fail? (lambda () (symbol->qname '|.a|)))
  (check-exn exn:fail? (lambda () (symbol->qname '|a.|)))

  ;; ---- predicates, ordering, join, derive ----------------------------
  (check-true (qname-symbol? 'model.value))
  (check-false (qname-symbol? 'edge))
  (check-true (qname<? (qname '("a" "b")) (qname '("ab"))))  ; string order of display
  (check-true (qname=? (symbol->qname 'x.y) (qname '("x" "y"))))
  (check-eq? (qname-join 'model 'value) 'model.value)
  (check-eq? (qname-join 'a.b 'c) 'a.b.c)
  ;; derive keeps today's root spellings byte-identical and composes
  (check-eq? (qname-derive 'reach 'has) 'reach_has)
  (check-eq? (qname-derive 'm.reach 'ans) 'm.reach_ans)
  ;; Prefix operations are component-wise, never textual.
  (check-true
   (qname-prefix? (symbol->qname 'a.bc) (symbol->qname 'a.bc.edge)))
  (check-false
   (qname-prefix? (symbol->qname 'a.bc) (symbol->qname 'ab.c.edge)))
  (check-equal?
   (qname-components
    (qname-rebase (symbol->qname 'formal.graph.edge)
                  (symbol->qname 'formal.graph)
                  (symbol->qname 'actual)))
   '("actual" "edge"))
  (check-eq? (name-at-home '() 'edge) 'edge)
  (check-eq? (name-at-home '("left") 'edge) 'left.edge)
  (check-eq? (internal-name-at-home '() '$sup0) '$sup0)
  (check-not-eq? (internal-name-at-home '("left") '$sup0)
                 (internal-name-at-home '("right") '$sup0))

  ;; ---- codecs ---------------------------------------------------------
  (check-equal? (qname->display mv) "model.value")
  (check-equal? (qname->wire mv) "model.value")
  (check-true (qname=? (wire->qname "model.value") mv))
  (check-equal? (qname->fs-name mv) "model.value")
  (check-true (qname=? (fs-name->qname "model.value") mv))
  ;; C++ identifier form pins the escape-id-for-C scheme: dot is _0002e
  (check-eq? (qname->cxx-ident mv) 'model_0002evalue)

  ;; ---- parser collapse ------------------------------------------------
  (define (ast s) (last (parse-source "names-tests.slog" s)))
  (define (strip e)
    (match e
      [`(syn ,_ . ,rest) (map strip rest)]
      [(? list?) (map strip e)]
      [_ e]))

  ;; dotted names in decl-name, field-type, clause-head, and argument
  ;; positions all collapse to one lowered symbol
  (check-equal?
   (strip (ast "table (model.value int syn.Exp)\nrule (model.value x y) --> (out x)"))
   '(table (model.value int syn.Exp)
           (rule (model.value x y) --> (out x) (top-level))))
  ;; chains collapse whole; struct decl and constructor positions too
  (check-equal?
   (strip (ast "struct (a.b.Pair int int)\nrule (in x y) --> (out (a.b.Pair x y))"))
   '(struct (a.b.Pair int int)
            (rule (in x y) --> (out (a.b.Pair x y)) (top-level))))
  ;; floats and the sequence ellipsis are untouched (single lexemes)
  (check-equal?
   (strip (ast "rule (edge 1.5 x) --> (out x)"))
   '(rule (edge (const 1.5) x) --> (out x) (top-level)))
  (check-equal?
   (strip (ast "rule (edge x xs ...) --> (out [x xs ...])"))
   '(rule (edge x (... xs)) --> (out (|[]| x (... xs))) (top-level)))
  ;; non-symbol operands keep the dormant binary dot operator tree
  (check-equal?
   (strip (ast "rule (edge true.false) --> (out 1)"))
   '(rule (edge (|.| (const true) (const false))) --> (out (const 1))
          (top-level)))
  ;; lattice declaration with a dotted name
  (check-equal?
   (strip (ast "lattice (m.cost (min int #:floor 0))"))
   '(lattice (m.cost (min int |#:floor| (const 0))) (top-level))))
