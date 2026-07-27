#lang racket

;; Unit tests for M4N slice-1 planner emission (docs/m4n-contract.md pins
;; 2/4/5): anti-delta versions per fully-bound negated occurrence, the
;; pre/post absence views per the ratified partition table, the wildcard
;; and DRed scope pins, and canonical serialization.  Run via:
;;   cd /home/tom/slog && raco test tests/unit/

(module+ test
  (require rackunit)
  (require racket/file)
  (require "../../compiler/params.rkt")
  (require "../../compiler/modules.rkt")
  (require "../../compiler/simplification.rkt")
  (require "../../compiler/type-system.rkt")
  (require "../../compiler/stratify.rkt")
  (require "../../compiler/join-planning.rkt")
  (require "../../compiler/operationalization.rkt")
  (require "../../compiler/canonical-plan.rkt")
  (require "../../compiler/ir-shared.rkt")
  (require "../../compiler/ir-stack.rkt")

  ;; Compile source through the front half under a flavor, mirroring
  ;; compile.rkt's emit-stratum-cpp parameterization (plan-dynamic broadened
  ;; with positive table reads under maintenance; count-mode swap).
  (define (cprogs-of src #:flavor [flavor #f])
    (parameterize ([wcoj3-enabled #f])
      (define f (make-temporary-file "m4n-test-~a.slog"))
      (dynamic-wind
       void
       (lambda ()
         (with-output-to-file f #:exists 'replace (lambda () (display src)))
         (match-define (list (? program-ir? program))
           (load-program-list (path->string f) (hash)))
         (define type-env (program-ir-type-env program))
         (define mods (program-ir-modules program))
         (define all-rules
           (foldl set-union (set) (map module-ir-rules (set->list mods))))
         (define typed
           (typecheck-rules type-env
                            (foldl simplify-rule (set) (set->list all-rules))))
         (define rel-env (type-env-rels type-env))
         (for/list ([stratum (in-list (stratify-rules typed))])
           (define rules (stratum-rules stratum))
           (define heads
             (for/fold ([acc (set)]) ([rule (in-set rules)])
               (set-union acc (rule-head-rels rule))))
           (define plan-dynamic
             (if (memq flavor '(maint1 maint3neg maint4neg))
                 (for*/fold ([acc heads])
                            ([rule (in-set rules)]
                             [r (in-set (rule-body-pos-rels rule))]
                             #:unless (set-member? heads r))
                   (match (hash-ref rel-env r #f)
                     [`(struct ,_ ...) (set-add acc r)]
                     [`(table ,_ ...)
                      (if (rel-lattice-spec rel-env r) acc (set-add acc r))]
                     [_ acc]))
                 heads))
           (parameterize
               ([maintenance-flavor (case flavor
                                      [(maint1) 'positive]
                                      [(maint3neg) 'negative]
                                      [(maint4neg) 'negative-rec]
                                      [else #f])]
                [semijoin-filters-enabled
                 (not (memq flavor '(count maint3neg maint4neg)))]
                [count-flavor
                 (and (memq flavor '(count maint1 maint3neg maint4neg))
                      (count-mode heads (make-hash)))])
             (match-define (cons planned rel-env+)
               (plan-stratum rules rel-env plan-dynamic))
             (build-cprog planned rel-env+))))
       (lambda () (delete-file f)))))

  ;; The crules of the stratum producing `head`, keyed by driver relation.
  (define (rules-for cprogs head)
    (for*/list ([cprog (in-list cprogs)]
                [crule (in-list (cprog-rules cprog))]
                #:when (for/or ([hop (in-list (crule-head crule))])
                         (member head (cdr hop))))
      crule))
  (define (driver-rel crule)
    (match (crule-driver crule)
      [`(,(or 'scan 'probe) ,name ,_ ...) name]
      [d (car d)]))
  (define (body-ops crule tag)
    (filter (lambda (op) (eq? (car op) tag)) (crule-body crule)))

  (define canon "table (a int)
                 table (b int)
                 table (h int)
                 rule (a 1) (a 2) (b 2)
                 rule (a X) ~(b X) --> (h X)")

  ;; -- 1. maint3neg: lost-A version tests ~b at PRE; the anti-delta version
  ;;       drives b and reads a as survivors (join-old) ------------------
  (let* ([hs (rules-for (cprogs-of canon #:flavor 'maint3neg) 'h)]
         [by-driver (for/hash ([r (in-list hs)]) (values (driver-rel r) r))])
    (check-equal? (sort (hash-keys by-driver) symbol<?) '(a b))
    (check-equal? (length (body-ops (hash-ref by-driver 'a) 'absent-old)) 1)
    (check-equal? (length (body-ops (hash-ref by-driver 'a) 'absent)) 0)
    (check-equal? (length (body-ops (hash-ref by-driver 'b) 'join-old)) 1)
    (check-equal? (length (body-ops (hash-ref by-driver 'b) 'absent-old)) 0))

  ;; -- 2. maint1: gained-A version tests ~b at POST; anti-delta mirrors --
  (let* ([hs (rules-for (cprogs-of canon #:flavor 'maint1) 'h)]
         [by-driver (for/hash ([r (in-list hs)]) (values (driver-rel r) r))])
    (check-equal? (sort (hash-keys by-driver) symbol<?) '(a b))
    (check-equal? (length (body-ops (hash-ref by-driver 'a) 'absent-new)) 1)
    (check-equal? (length (body-ops (hash-ref by-driver 'b) 'join-old)) 1))

  ;; -- 3. count flavor: plain absent, no anti-delta version --------------
  (let ([hs (rules-for (cprogs-of canon #:flavor 'count) 'h)])
    (check-equal? (length hs) 1)
    (check-equal? (length (body-ops (car hs) 'absent)) 1)
    (check-equal? (length (body-ops (car hs) 'absent-old)) 0))

  ;; -- 4. the ratified sibling split: anti-delta for Ni reads earlier
  ;;       negated occurrences at POST, later at PRE (negative flavor) ----
  (let* ([src "table (a int)
               table (b int)
               table (c int)
               table (h int)
               rule (a 1) (b 2) (c 3)
               rule (a X) ~(b X) ~(c X) --> (h X)"]
         [hs (rules-for (cprogs-of src #:flavor 'maint3neg) 'h)]
         [by-driver (for/hash ([r (in-list hs)]) (values (driver-rel r) r))])
    (check-equal? (sort (hash-keys by-driver) symbol<?) '(a b c))
    ;; positive-driven: both at PRE
    (check-equal? (length (body-ops (hash-ref by-driver 'a) 'absent-old)) 2)
    ;; The ownership order is the planner's stable clause order (post-
    ;; simplification), not source order; exactness requires only that the
    ;; two anti-delta versions split PAIRWISE -- exactly one evaluates its
    ;; sibling at PRE and the other at POST, and each carries exactly one
    ;; sibling probe.
    (let ([b-old (length (body-ops (hash-ref by-driver 'b) 'absent-old))]
          [b-new (length (body-ops (hash-ref by-driver 'b) 'absent-new))]
          [c-old (length (body-ops (hash-ref by-driver 'c) 'absent-old))]
          [c-new (length (body-ops (hash-ref by-driver 'c) 'absent-new))])
      (check-equal? (+ b-old b-new) 1)
      (check-equal? (+ c-old c-new) 1)
      (check-equal? (+ b-old c-old) 1)
      (check-equal? (+ b-new c-new) 1)))

  ;; -- 5. wildcard'd negation: viewed absence, but NO anti-delta version -
  (let* ([src "table (a int)
               table (c int int)
               table (h int)
               rule (a 1) (c 2 9)
               rule (a X) ~(c X _) --> (h X)"]
         [hs (rules-for (cprogs-of src #:flavor 'maint3neg) 'h)]
         [drivers (map driver-rel hs)])
    (check-equal? (sort drivers symbol<?) '(a))
    (check-equal? (length (body-ops (car hs) 'absent-old)) 1))

  ;; -- 6. the sweep table (slice 2, ratified 2026-07-21): corpse-driven
  ;;       versions probe ~blk at ABSENT-EVER (not pre); anti-delta
  ;;       versions read positives at the phase-entry join-new view ------
  (let* ([sweep "table (e int int)
                 table (blk int)
                 table (r int int)
                 rule (e 1 2) (e 2 3) (blk 9)
                 rule (e X Y) ~(blk Y) --> (r X Y)
                 rule (r X Y) (e Y Z) ~(blk Z) --> (r X Z)"]
         [hs (rules-for (cprogs-of sweep #:flavor 'maint4neg) 'r)]
         [of-driver (lambda (d) (filter (lambda (c) (eq? (driver-rel c) d)) hs))])
    ;; two anti-delta versions (one per rule's ~blk occurrence)
    (check-equal? (length (of-driver 'blk)) 2)
    (for ([c (in-list (append (of-driver 'e) (of-driver 'r)))])
      (check-equal? (length (body-ops c 'absent-ever)) 1)
      (check-equal? (length (body-ops c 'absent-old)) 0)
      (check-equal? (length (body-ops c 'absent)) 0))
    ;; base-rule anti reads e at phase entry; rec-rule anti reads r AND e
    (check-equal? (sort (for/list ([c (in-list (of-driver 'blk))])
                          (length (body-ops c 'join-new))) <)
                  '(1 2))
    (for ([c (in-list (of-driver 'blk))])
      (check-equal? (length (body-ops c 'join-old)) 0)))

  ;; -- 6b. sweep sibling split: anti versions keep the pairwise pre/post
  ;;        rule; corpse-driven versions carry BOTH probes at absent-ever -
  (let* ([sweep2 "table (e int int)
                  table (blk int)
                  table (c int)
                  table (r int int)
                  rule (e 1 2) (blk 9) (c 8)
                  rule (r X Y) (e Y Z) ~(blk Z) ~(c Z) --> (r X Z)
                  rule (e X Y) --> (r X Y)"]
         [hs (rules-for (cprogs-of sweep2 #:flavor 'maint4neg) 'r)]
         [of-driver (lambda (d) (filter (lambda (c) (eq? (driver-rel c) d)) hs))]
         [antis (append (of-driver 'blk) (of-driver 'c))])
    (check-equal? (length antis) 2)
    (let ([olds (for/sum ([a (in-list antis)]) (length (body-ops a 'absent-old)))]
          [news (for/sum ([a (in-list antis)]) (length (body-ops a 'absent-new)))]
          [evers (for/sum ([a (in-list antis)]) (length (body-ops a 'absent-ever)))])
      (check-equal? olds 1)   ; pairwise: one sibling probe at PRE ...
      (check-equal? news 1)   ; ... and the other at POST
      (check-equal? evers 0))
    (for ([c (in-list (of-driver 'r))]
          #:when (pair? (body-ops c 'absent-ever)))
      (check-equal? (length (body-ops c 'absent-ever)) 2)))

  ;; -- 7. canonical serialization carries the delta ordering (and the
  ;;       sweep spelling serializes) --------------------------------------
  (let* ([sweep "table (e int int)
                 table (blk int)
                 table (r int int)
                 rule (e 1 2) (blk 9)
                 rule (e X Y) ~(blk Y) --> (r X Y)
                 rule (r X Y) (e Y Z) ~(blk Z) --> (r X Z)"]
         [texts (for/list ([cprog (in-list (cprogs-of sweep #:flavor 'maint4neg))])
                  (kernel-plan->string
                   (canonicalize-cprog cprog #:flavor 'maint4neg)))])
    (check-true (regexp-match?
                 #rx"\\(absent-ever \\(rel [0-9]+\\) \\([0-9 ]+\\) [0-9]+ \\([0-9 ]+\\)"
                 (string-join texts))))

  ;; -- 7b. canonical serialization carries the delta ordering ------------
  (let* ([cprogs (cprogs-of canon #:flavor 'maint3neg)]
         [texts (for/list ([cprog (in-list cprogs)])
                  (kernel-plan->string
                   (canonicalize-cprog cprog #:flavor 'maint3neg)))]
         [joined (string-join texts)])
    (check-true (regexp-match?
                 #rx"\\(absent-old \\(rel [0-9]+\\) \\([0-9 ]+\\) [0-9]+ \\([0-9 ]+\\)"
                 joined)))

  (void))
