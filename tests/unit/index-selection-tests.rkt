#lang racket

;; Unit tests for operationalization's greedy prefix-chain index selection.
;; Run via:
;;   cd /home/tom/slog && TMPDIR=/tmp raco test tests/unit/

(module+ test
  (require rackunit)
  (require "../../compiler/operationalization.rkt")
  (require (submod "../../compiler/operationalization.rkt" test-support))
  (require "../../compiler/ir-stack.rkt")

  (define (covers? ordering selection)
    (equal? (list->set (take ordering (set-count selection))) selection))

  (define (check-covered orderings selections)
    (for ([selection (in-set selections)])
      (check-true
       (for/or ([ordering (in-set orderings)])
         (covers? ordering selection))
       (format "selection ~a is covered by ~a" selection orderings))))

  ;; A reverse-numbered subset chain is the case the old canonical
  ;; one-ordering-per-selection scheme missed completely.
  (test-case "nested selections pack into one deterministic ordering"
    (define selections
      (set (set) (set 3) (set 2 3) (set 1 2 3) (set 0 1 2 3)))
    (define orderings (greedy-index-orderings selections 4))
    (check-equal? orderings (set '(3 2 1 0)))
    (check-covered orderings selections))

  (test-case "incomparable selections remain separate"
    (define selections (set (set 0) (set 1) (set 2)))
    (define orderings (greedy-index-orderings selections 3))
    (check-equal? (set-count orderings) 3)
    (check-covered orderings selections))

  (test-case "equal-size tie breaking is stable"
    (define selections (set (set 0) (set 1) (set 0 1)))
    (define expected (set '(0 1 2) '(1 0 2)))
    (for ([i (in-range 10)])
      (check-equal? (greedy-index-orderings selections 3) expected)))

  (test-case "all subsets through arity six remain covered"
    (for ([arity (in-range 1 7)])
      (define selections
        (for/set ([mask (in-range (arithmetic-shift 1 arity))])
          (for/set ([column (in-range arity)]
                    #:when (bitwise-bit-set? mask column))
            column)))
      (define orderings (greedy-index-orderings selections arity))
      (check-true (<= (set-count orderings) (set-count selections)))
      (for ([ordering (in-set orderings)])
        (check-equal? (sort ordering <) (range arity)))
      (check-covered orderings selections)))

  (define (decl-of cprog name)
    (or (findf (lambda (decl)
                 (and (pair? decl) (>= (length decl) 2)
                      (equal? (second decl) name)))
               (cprog-decls cprog))
        (error 'index-selection-tests "missing declaration for ~a" name)))

  (test-case "struct master and lookup layouts survive packing"
    (define cprog
      (build-cprog (set) (hash 'pair '(struct int int))))
    (match-define `(struct pair 3 ,master ,lookup ,_ ...) (decl-of cprog 'pair))
    (check-equal? (last master) 0)
    (check-equal? (first lookup) 0)
    (check-equal? (list->set master) (set 0 1 2))
    (check-equal? (list->set lookup) (set 0 1 2)))

  (test-case "lattice full indices keep the payload column last"
    (define rel-env
      (hash 'cost '(lattice min int)
            'lat '(table int int cost)
            'seed '(table int)
            'out '(table int)))
    (define rule
      '(syn #f rule
            (syn #f seed A)
            (syn #f lat X A V)
            -->
            (syn #f out V)))
    (define cprog (build-cprog (set rule) rel-env))
    (match-define `(lattice lat 3 ,_spec ,_decomp ,indices ...)
      (decl-of cprog 'lat))
    (define full
      (filter (lambda (index)
                (not (and (pair? index) (eq? 'delta (car index)))))
              indices))
    (check-true (pair? full))
    (for ([index (in-list full)])
      (check-equal? (last index) 2)))

  (test-case "exact joins pin matching packed full and delta orderings"
    (define rel-env
      (hash 'seed '(table int int)
            'r '(table int int int int)
            'out '(table int)))
    ;; The ordinary join asks for {2,3}; the exact join asks for {3}.
    ;; Together with the table's empty selection they pack as
    ;; {} ⊂ {3} ⊂ {2,3}, producing the non-canonical order (3 2 0 1).
    (define ordinary
      '(syn #f rule
            (syn #f seed A B)
            (syn #f r X Y B A)
            -->
            (syn #f out A)))
    (define exact
      '(syn #f rule
            (syn #f seed A B)
            (syn #f $oldjoin (syn #f r X Y Z A))
            -->
            (syn #f out A)))
    (define cprog (build-cprog (set ordinary exact) rel-env))
    (define old-op
      (for*/first ([crule (in-list (cprog-rules cprog))]
                   [op (in-list (crule-body crule))]
                   #:when (eq? 'join-old (car op)))
        op))
    (check-not-false old-op)
    (match-define `(join-old r ,full-ordering 1 ,delta-ordering ,_ ...) old-op)
    (check-equal? full-ordering '(3 2 0 1))
    (check-equal? delta-ordering full-ordering)
    (match-define `(relation r 4 ,indices ...) (decl-of cprog 'r))
    (check-equal?
     (count (lambda (index)
              (not (and (pair? index) (eq? 'delta (car index)))))
            indices)
     1
     "{} ⊂ {3} ⊂ {2,3} shares one full index")
    (check-not-false (member full-ordering indices))
    (check-not-false (member `(delta ,@full-ordering) indices)))

  (void))
