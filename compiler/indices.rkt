;; Minimum-index-set selection, after
;;   [1] "Automatic Index Selection for Large-Scale Datalog Computation"
;;       (Subotic, Jordan, Scholz et al., VLDB 2018)
;;
;; Currently unused: operationalization.rkt builds one index per distinct
;; select set, which is simple and correct but can materialize more indices
;; than necessary.  The minimum chain cover below computes, for one
;; relation's set of selections, a minimal set of index orderings such that
;; every selection is a prefix of some ordering -- swap it in behind
;; operationalization's indices-of when index count starts to matter.
#lang racket

(require graph)
(provide (contract-out
          [min-chain-cover (-> (set/c selection?) (listof (listof selection?)))]
          [indices-from-selections (-> (set/c selection?) columns? indices?)]))

(define index? (listof natural-number/c))
(define indices? (set/c index?))
(define columns? (set/c natural-number/c))
(define selection? columns?)

(struct vtx (tag contents) #:transparent)

(define (sort-sets s)
  (sort s proper-subset?))

;; Calculate the minimum chain cover of a set of selections (Algorithm 1 in
;; [1]): chains of subset-ordered selections, via maximum bipartite matching.
(define (min-chain-cover selections)
  (define selections-l (set->list selections))

  ;; Form edges u -> v between two copies of the selections whenever u is a
  ;; proper subset of v (u's columns can prefix an index that also serves v).
  (define edges
    (map (match-lambda
           [`(,x . ,y) (list (vtx 0 x) (vtx 1 y))])
         (set->list (for*/set ([s (in-list selections-l)]
                               [t (in-list selections-l)]
                               #:when (proper-subset? s t))
                      (cons s t)))))

  (define matching (maximum-bipartite-matching (undirected-graph edges)))

  ;; Chains are the connected components of the matched pairs.
  (define chain-input-edges
    (for/list ([matching-edge (in-list matching)])
      (sort-sets (list (vtx-contents (first matching-edge))
                       (vtx-contents (second matching-edge))))))
  (map sort-sets (cc (undirected-graph chain-input-edges))))

;; Assemble an index ordering out of a given chain of selections.
(define ((assemble-index all-columns) chain)
  (let loop ([chain chain] [columns-left (list->set all-columns)] [seen (set)] [index '()])
    (match chain
      ['() (append index (set->list columns-left))]
      [`(,hd . ,tl)
       (let* ([curr (set-subtract (list->set hd) seen)]
              [columns-left+ (set-subtract columns-left curr)]
              [seen+ (set-union seen curr)])
         (loop tl columns-left+ seen+ (append index (set->list curr))))])))

;; A minimal set of indices covering a set of selections.
(define (indices-from-selections selections all-columns)
  (list->set (map (assemble-index (set->list all-columns))
                  (min-chain-cover selections))))

(module+ test
  (require rackunit)
  (define example (set (set 0) (set 1) (set 0 1) (set 0 1 2)))
  ;; {0},{0,1},{0,1,2} chain into one index; {1} needs its own
  (check-equal? (set-count (indices-from-selections example (set 0 1 2))) 2))
