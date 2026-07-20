#lang racket

;; Stratification: organize a program's rules into a DAG of SCCs.
;;
;; The relation dependency graph has an edge B -> H for every rule with B in
;; its body and H in its head, plus edges making all head relations of one
;; rule mutually dependent (a rule fires as a unit, so its heads must close
;; in the same stratum).  Tarjan's algorithm condenses this graph into
;; strongly connected components; each rule belongs to the (single, by the
;; head-merge edges) SCC of its head relations.
;;
;; The condensation is a DAG.  We schedule it by depth: an SCC's level is one
;; more than the deepest of its predecessors, and all SCCs at the same level
;; -- which are necessarily independent -- merge into one stratum.  The
;; resulting list of strata, in level order, is a valid topological walk of
;; the DAG: when a stratum runs, every relation it reads from below is
;; already closed, so the driver can run each stratum program to fixpoint in
;; sequence, reloading the database between them.
;;
;; Stratification is LOAD-BEARING (docs/incremental.md §0.8): edges carry
;; polarity, and a negative edge (a rule reading ~B and writing H) whose
;; endpoints share an SCC is a compile error -- negation through recursion
;; is not stratifiable.  A cross-SCC negative edge needs nothing extra: like
;; any edge it forces level(H) >= level(B)+1, and same-level merged SCCs are
;; mutually unreachable, so a negated relation is always CLOSED (strictly
;; lower stratum) at read time -- exactly the property the runtime's absent
;; probe leans on.  Beyond semantics, stratification still buys smaller
;; fixpoints (only a stratum's own rules iterate) and lets rules over closed
;; relations run once as static tasks.

(provide stratify-rules
         rule-head-rels
         rule-body-rels
         rule-body-neg-rels
         rule-body-negw-rels
         rule-body-pos-rels
         rule-body-rel-occurrences
         tarjan-scc-ids)

(require "ir-shared.rkt")

;; -----------------------------------------------------------------------
;; Relation references of a typed rule.

(define (clause-rel cl)
  (match cl
    [`(syn ,_ /= ,_ ,_) #f]
    [`(syn ,_ == ,_ ,_) #f]
    [`(syn ,_ ,(? primitive-cmp?) ,_ ,_) #f]
    [`(syn ,_ let ,_ ,_) #f]
    ;; residual type checks are deliberately INVISIBLE here: their failure
    ;; path writes malformed_deduction, but counting that as a head would
    ;; put every checked rule's heads in one SCC (heads of a rule close
    ;; together), collapsing the program into a single stratum.  Sound
    ;; because nothing feeds back: malformed_deduction flows only into
    ;; `error` via the per-stratum wrap rule compile.rkt injects.
    [`(syn ,_ tycheck ,_ ...) #f]
    [`(syn ,_ = ,_ (syn ,_ const ,_)) #f]
    [`(syn ,_ = ,_ (syn ,_ ,name ,_ ...)) name]
    ;; a negated atom reads its relation like any body atom (the edge it
    ;; contributes is NEGATIVE; see rule-body-neg-rels)
    [(? neg-clause?) (neg-rel cl)]
    [`(syn ,_ ,name ,_ ...) name]))

(define (clauses-rels cls)
  (list->set (filter-map clause-rel cls)))

(define (rule-head-rels rule)
  (match rule
    [`(syn ,_ rule ,bodys ... --> ,heads ...) (clauses-rels heads)]))

(define (rule-body-rels rule)
  (match rule
    [`(syn ,_ rule ,bodys ... --> ,heads ...) (clauses-rels bodys)]))

;; The NEGATED subset of a rule's body reads (polarity; §0.8), and its
;; complement over positive clauses only -- a relation can appear in both
;; (read positively in one clause, negated in another).
(define (rule-body-neg-rels rule)
  (match rule
    [`(syn ,_ rule ,bodys ... --> ,heads ...)
     (list->set (map neg-rel (filter neg-clause? bodys)))]))

;; Wildcard'd negated reads (M4N, docs/m4n-contract.md pin 5): a negated
;; atom with a wildcard column is a PREFIX test whose anti-delta
;; multiplicity is per-prefix-transition, not per-row -- so route admission
;; needs to know which negative edges are prefix-shaped.  Manifested as the
;; 'negw read kind beside 'neg.
(define (rule-body-negw-rels rule)
  (match rule
    [`(syn ,_ rule ,bodys ... --> ,heads ...)
     (for/set ([cl (in-list bodys)]
               #:when (and (neg-clause? cl)
                           (ormap neg-wildcard-var? (neg-args cl))))
       (neg-rel cl))]))

(define (rule-body-pos-rels rule)
  (match rule
    [`(syn ,_ rule ,bodys ... --> ,heads ...)
     (clauses-rels (filter (lambda (cl) (not (neg-clause? cl))) bodys))]))

;; Body relation reads WITH occurrence multiplicity (rule-body-rels dedups):
;; the linear-vs-nonlinear recursion test (db-compression.md §4.4 v2) needs to
;; distinguish path(x,y),path(y,z) (two same-SCC occurrences) from
;; path(x,y),edge(y,z) (one), which sets can't.
(define (rule-body-rel-occurrences rule)
  (match rule
    [`(syn ,_ rule ,bodys ... --> ,heads ...) (filter-map clause-rel bodys)]))

;; -----------------------------------------------------------------------
;; Tarjan's strongly-connected-components algorithm.
;;
;; nodes: sorted list of symbols; succs: symbol -> (listof symbol).
;; Returns a hash from node to SCC id (a small integer).  Ids carry no
;; ordering significance here; levels are computed over the condensation.

(define (tarjan-scc-ids nodes succs)
  (define index (make-hash))     ; node -> visitation index
  (define lowlink (make-hash))   ; node -> smallest index reachable
  (define on-stack (make-hash))  ; node -> #t while on the stack
  (define stack '())
  (define next-index 0)
  (define scc-of (make-hash))    ; node -> scc id
  (define next-scc 0)

  (define (strong-connect v)
    (hash-set! index v next-index)
    (hash-set! lowlink v next-index)
    (set! next-index (add1 next-index))
    (set! stack (cons v stack))
    (hash-set! on-stack v #t)
    (for ([w (in-list (succs v))])
      (cond
        [(not (hash-has-key? index w))
         (strong-connect w)
         (hash-set! lowlink v (min (hash-ref lowlink v) (hash-ref lowlink w)))]
        [(hash-ref on-stack w #f)
         (hash-set! lowlink v (min (hash-ref lowlink v) (hash-ref index w)))]))
    ;; v is the root of an SCC: pop the stack down to v
    (when (= (hash-ref lowlink v) (hash-ref index v))
      (let pop ()
        (define w (car stack))
        (set! stack (cdr stack))
        (hash-set! on-stack w #f)
        (hash-set! scc-of w next-scc)
        (unless (eq? w v) (pop)))
      (set! next-scc (add1 next-scc))))

  (for ([v (in-list nodes)])
    (unless (hash-has-key? index v)
      (strong-connect v)))
  scc-of)

;; -----------------------------------------------------------------------
;; Stratification driver: typed rules -> (listof (stratum level rules)).
;;
;; `extra-edges` are derived dependencies with no rule of their own -- today
;; the M2.4 decomposition edge R -> R_has (as if a rule read R and wrote
;; R_has; compile.rkt passes them from the program's decomp-env).  They keep
;; a decomposed relation's derived facts from closing before their base, and
;; complete the cycle when a rule reads R_has and writes back into R (the
;; in-SCC enumeration case: R and R_has share an SCC).

(define (stratify-rules rules [extra-edges (set)])
  (define rule-list (set->list rules))

  ;; the dependency graph over relation names
  (define edges ; set of (from . to), from body to head and among heads
    (for*/fold ([es extra-edges]) ([rule (in-list rule-list)])
      (define heads (set->list (rule-head-rels rule)))
      (define bodys (set->list (rule-body-rels rule)))
      (for*/fold ([es (set-union
                       es
                       (for*/set ([h0 (in-list heads)] [h1 (in-list heads)]
                                  #:unless (eq? h0 h1))
                         (cons h0 h1)))])
                 ([b (in-list bodys)] [h (in-list heads)])
        (set-add es (cons b h)))))
  ;; NEGATIVE edges (§0.8): (list from to rule) per negated body read, kept
  ;; separately (with provenance) for the post-condensation rejection below.
  ;; Every negative edge is also in `edges` (rule-body-rels includes negated
  ;; reads), so leveling needs nothing extra.
  (define neg-edges
    (for*/list ([rule (in-list rule-list)]
                [b (in-set (rule-body-neg-rels rule))]
                [h (in-set (rule-head-rels rule))])
      (list b h rule)))
  (define nodes
    (sort (set->list
           (for/fold ([ns (for/fold ([ns (set)]) ([e (in-set extra-edges)])
                            (set-add (set-add ns (car e)) (cdr e)))])
                     ([rule (in-list rule-list)])
             (set-union ns (rule-head-rels rule) (rule-body-rels rule))))
          symbol<?))
  (define succ-map
    (for/fold ([h (hash)]) ([e (in-set edges)])
      (hash-update h (car e) (lambda (l) (cons (cdr e) l)) '())))
  (define (succs v)
    (sort (hash-ref succ-map v '()) symbol<?))

  (define scc-of (tarjan-scc-ids nodes succs))

  ;; semantic stratification (§0.8): a negative edge inside one SCC means
  ;; some rule's negated read can still grow while its head derives --
  ;; negation through recursion, not stratifiable.  Name the rule and the
  ;; cycle's relations (the members of the offending SCC).
  (for ([e (in-list neg-edges)])
    (match-define (list b h rule) e)
    (when (= (hash-ref scc-of b) (hash-ref scc-of h))
      (define cycle-rels
        (sort (for/list ([n (in-list nodes)]
                         #:when (= (hash-ref scc-of n) (hash-ref scc-of b)))
                n)
              symbol<?))
      (error 'stratify
             "negation through recursion -- not stratified: the rule at ~a negates ~a, but ~a and ~a are mutually recursive (cycle: ~a)\n  in rule: ~a"
             (rule-location-string rule) b b h
             (string-join (map symbol->string cycle-rels) " ")
             (strip-prov rule))))

  ;; condensation edges and levels: level(scc) = 1 + max level of preds
  (define preds-of ; scc id -> set of predecessor scc ids
    (for/fold ([h (hash)]) ([e (in-set edges)])
      (define su (hash-ref scc-of (car e)))
      (define sv (hash-ref scc-of (cdr e)))
      (if (= su sv)
          h
          (hash-update h sv (lambda (s) (set-add s su)) (set)))))
  (define level-memo (make-hash))
  (define (scc-level s)
    (hash-ref! level-memo s
               (lambda ()
                 (add1 (for/fold ([mx -1]) ([p (in-set (hash-ref preds-of s (set)))])
                         (max mx (scc-level p)))))))

  ;; each rule joins the stratum of its heads' (shared) SCC
  (define (rule-level rule)
    (define heads (rule-head-rels rule))
    (when (set-empty? heads)
      (error 'stratify-rules "rule derives nothing (no head relations):\n~a"
             (strip-prov rule)))
    (scc-level (hash-ref scc-of (set-first heads))))

  (define by-level
    (for/fold ([h (hash)]) ([rule (in-list rule-list)])
      (hash-update h (rule-level rule) (lambda (s) (set-add s rule)) (set))))

  (for/list ([lvl (in-list (sort (hash-keys by-level) <))])
    `(stratum ,lvl ,(hash-ref by-level lvl))))
