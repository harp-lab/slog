#lang racket

;; RF1.5: deterministic, identity-free queries over RF1's ProgramModel.
;;
;; The raw model deliberately retains compiler-internal SCC ids and typed
;; rules.  RF5 must not serialize either accident as cross-image identity, so
;; this module is the adapter: image-local rule slots, member-named SCCs,
;; alpha-normalized rule fingerprints, writer/dependency queries, and the
;; union-graph cone used by semantic program replacement.

(provide
 (struct-out program-rule)
 (struct-out program-edge)
 (struct-out program-rule-change)
 (struct-out program-semantic-diff)
 semantic-rule-normal-form
 semantic-rule-fingerprint
 program-model-content-fingerprint
 program-model-rules
 program-model-normalized-rules
 program-model-fingerprint
 program-model-relations
 program-model-writers
 program-model-dependency-edges
 program-model-components
 program-model-condensation-edges
 program-model-successors
 program-model-forward-cone
 program-model-union-cone
 diff-program-models)

(require racket/list
         racket/set
         (only-in "join-planning.rkt" rule-sort-key)
         "ir-shared.rkt"
         "sha256.rkt"
         "stratify.rkt")

;; A candidate-image-local semantic rule occurrence.  `slot` has no meaning
;; outside this one model.  Duplicate normalized rules deliberately occupy
;; distinct slots: support multiplicity matters even when membership does not.
(struct program-rule
  (slot source-id source-key fingerprint normalized heads positive negative
        negative-wildcard)
  #:transparent)

;; A relation dependency.  `rule-slot` is #f for a compiler-derived edge.
;; Kinds are positive, negative, negative-wildcard, co-head, and derived.
(struct program-edge (from to kind rule-slot) #:transparent)

;; One normalized rule whose occurrence count differs across two models.
(struct program-rule-change
  (fingerprint normalized old-count new-count)
  #:transparent)

;; This is the normalized-rule/graph portion of RF5's semantic program diff.
;; Declarations, bindings, services, and execution plans live in later image
;; layers and are intentionally not guessed here.
(struct program-semantic-diff
  (old-fingerprint new-fingerprint
   rule-changes
   edges-added edges-removed
   writer-relations
   components-added components-removed
   affected-roots cone)
  #:transparent)

(define (sha256-string s)
  (bytes->hex-string (sha256 (string->bytes/utf-8 s))))

;; The planner's canonical rule key is already the compiler's provenance-free,
;; alpha-normalized typed-rule representation.  Reuse it rather than allowing
;; reflection and emission to acquire subtly different normalization rules.
(define (semantic-rule-normal-form rule)
  (rule-sort-key rule))

(define (semantic-rule-fingerprint rule)
  (sha256-string (semantic-rule-normal-form rule)))

(define (symbols xs)
  (sort (remove-duplicates xs) symbol<?))

(define (program-model-rules model)
  (define source-of (program-model-source-of model))
  (define keyed
    (for/list ([rule (in-list (hash-keys source-of))])
      (define normalized (semantic-rule-normal-form rule))
      (vector normalized (hash-ref source-of rule) rule)))
  ;; Source ids are only a deterministic tiebreak among alpha-equivalent
  ;; occurrences.  They never enter a semantic fingerprint.
  (define ordered
    (sort keyed
          (lambda (a b)
            (define na (vector-ref a 0))
            (define nb (vector-ref b 0))
            (or (string<? na nb)
                (and (string=? na nb)
                     (< (vector-ref a 1) (vector-ref b 1)))))))
  (for/list ([entry (in-list ordered)] [slot (in-naturals)])
    (define normalized (vector-ref entry 0))
    (define source-id (vector-ref entry 1))
    (define rule (vector-ref entry 2))
    (program-rule
     slot source-id (rule-lineage-key rule) (sha256-string normalized) normalized
     (symbols (set->list (rule-head-rels rule)))
     (symbols (set->list (rule-body-pos-rels rule)))
     (symbols (set->list (rule-body-neg-rels rule)))
     (symbols (set->list (rule-body-negw-rels rule))))))

(define (program-model-normalized-rules model)
  (map program-rule-normalized (program-model-rules model)))

;; A normalized ProgramModel fingerprint, not yet a complete ProgramImage
;; digest.  Rule occurrences remain repeated, so removing one duplicate
;; changes the digest.  Compiler-derived edges are included because they can
;; change the SCC graph without introducing a source rule.
(define (program-model-content-fingerprint normalized-rules derived-edges)
  (define derived
    (sort (for/list ([edge (in-list derived-edges)])
            (match edge
              [(list from to) (list from to)]
              [(list from to kind) (list from to kind)]
              [(cons from to) (list from to)]
              [_ (error 'program-model-content-fingerprint
                        "malformed derived edge: ~s" edge)]))
          string<? #:key (lambda (x) (format "~s" x))))
  (sha256-string
   (format "~s"
           `(program-model-v1
             (rules ,@normalized-rules)
             (derived-edges ,@derived)))))

(define (program-model-fingerprint model)
  (program-model-content-fingerprint
   (program-model-normalized-rules model)
   (for/list ([edge (in-set (program-model-extra-edges model))])
     (if (eq? (hash-ref (program-model-extra-edge-kinds model)
                        edge 'derived)
              'derived)
         edge
         (list (car edge) (cdr edge)
               (hash-ref (program-model-extra-edge-kinds model) edge))))))

(define (optional-slot<? left right)
  (cond [(not left) (and right #t)]
        [(not right) #f]
        [else (< left right)]))

(define (program-edge<? left right)
  (define lf (program-edge-from left))
  (define rf (program-edge-from right))
  (define lt (program-edge-to left))
  (define rt (program-edge-to right))
  (define lk (program-edge-kind left))
  (define rk (program-edge-kind right))
  (cond [(not (eq? lf rf)) (symbol<? lf rf)]
        [(not (eq? lt rt)) (symbol<? lt rt)]
        [(not (eq? lk rk)) (symbol<? lk rk)]
        [else
         (optional-slot<? (program-edge-rule-slot left)
                          (program-edge-rule-slot right))]))

(define (program-model-dependency-edges model)
  (define rule-edges
    (append*
     (for/list ([rule (in-list (program-model-rules model))])
       (define heads (program-rule-heads rule))
       (define negw (list->set (program-rule-negative-wildcard rule)))
       (append
        (for*/list ([from (in-list (program-rule-positive rule))]
                    [to (in-list heads)])
          (program-edge from to 'positive (program-rule-slot rule)))
        (for*/list ([from (in-list (program-rule-negative rule))]
                    [to (in-list heads)])
          (program-edge from to
                        (if (set-member? negw from)
                            'negative-wildcard
                            'negative)
                        (program-rule-slot rule)))
        (for*/list ([from (in-list heads)] [to (in-list heads)]
                    #:unless (eq? from to))
          (program-edge from to 'co-head (program-rule-slot rule)))))))
  (define derived
    (for/list ([edge (in-set (program-model-extra-edges model))])
      (program-edge
       (car edge) (cdr edge)
       (hash-ref (program-model-extra-edge-kinds model) edge 'derived) #f)))
  (sort (append rule-edges derived) program-edge<?))

(define (program-model-relations model)
  (symbols
   (append*
    (for/list ([members (in-hash-values (program-model-scc-members model))])
      members))))

;; relation -> sorted image-local rule slots (duplicates retained)
(define (program-model-writers model)
  (define writers
    (for*/fold ([h (hash)])
               ([rule (in-list (program-model-rules model))]
                [head (in-list (program-rule-heads rule))])
      (hash-update h head (lambda (slots) (cons (program-rule-slot rule) slots))
                   '())))
  (for/hash ([(rel slots) (in-hash writers)])
    (values rel (sort slots <))))

;; Stable SCC query: each component is (MEMBERS LEVEL).  Raw Tarjan ids never
;; escape this adapter and therefore cannot be mistaken for cross-image keys.
(define (program-model-components model)
  (sort
   (for/list ([(scc members) (in-hash (program-model-scc-members model))])
     (list members (hash-ref (program-model-scc-level model) scc)))
   string<? #:key (lambda (x) (format "~s" (first x)))))

(define (component-members model relation)
  (define scc (hash-ref (program-model-scc-of model) relation))
  (hash-ref (program-model-scc-members model) scc))

;; Each result is (FROM-MEMBERS TO-MEMBERS KINDS).  Multiple relation/rule
;; edges between the same SCC pair collapse, retaining their edge-kind set.
(define (program-model-condensation-edges model)
  (define grouped
    (for/fold ([h (hash)])
              ([edge (in-list (program-model-dependency-edges model))]
               #:unless (equal? (component-members model (program-edge-from edge))
                                (component-members model (program-edge-to edge))))
      (define key
        (list (component-members model (program-edge-from edge))
              (component-members model (program-edge-to edge))))
      (hash-update h key
                   (lambda (kinds) (set-add kinds (program-edge-kind edge)))
                   (set))))
  (sort
   (for/list ([(component-pair kinds) (in-hash grouped)])
     (list (first component-pair) (second component-pair)
           (sort (set->list kinds) symbol<?)))
   string<? #:key (lambda (x) (format "~s" x))))

(define (successor-hash edges)
  (for/fold ([h (hash)]) ([edge (in-list edges)])
    (hash-update h (program-edge-from edge)
                 (lambda (targets) (set-add targets (program-edge-to edge)))
                 (set))))

(define (program-model-successors model relation)
  (sort
   (set->list
    (hash-ref (successor-hash (program-model-dependency-edges model))
              relation (set)))
   symbol<?))

(define (normalize-roots roots)
  (cond [(set? roots) (set->list roots)]
        [(list? roots) roots]
        [else (list roots)]))

(define (forward-cone edges roots)
  (define succs (successor-hash edges))
  (let loop ([pending (normalize-roots roots)] [seen (set)])
    (cond
      [(null? pending) (sort (set->list seen) symbol<?)]
      [(set-member? seen (car pending)) (loop (cdr pending) seen)]
      [else
       (define rel (car pending))
       (loop (append (set->list (hash-ref succs rel (set))) (cdr pending))
             (set-add seen rel))])))

(define (program-model-forward-cone model roots)
  (forward-cone (program-model-dependency-edges model) roots))

(define (program-model-union-cone old-model new-model roots)
  (forward-cone
   (append (program-model-dependency-edges old-model)
           (program-model-dependency-edges new-model))
   roots))

(define (count-by xs key)
  (for/fold ([h (hash)]) ([x (in-list xs)])
    (hash-update h (key x) add1 0)))

(define (edge-signatures model)
  (for/set ([edge (in-list (program-model-dependency-edges model))])
    (list (program-edge-from edge) (program-edge-to edge)
          (program-edge-kind edge))))

(define (writer-signatures model)
  (for*/fold ([h (hash)])
             ([rule (in-list (program-model-rules model))]
              [head (in-list (program-rule-heads rule))])
    (hash-update h head
                 (lambda (rules) (cons (program-rule-normalized rule) rules))
                 '())))

(define (component-signatures model)
  (for/set ([component (in-list (program-model-components model))])
    (first component)))

(define (sorted-set-difference left right)
  (sort (set->list (set-subtract left right))
        string<? #:key (lambda (x) (format "~s" x))))

(define (diff-program-models old-model new-model)
  (define old-rules (program-model-rules old-model))
  (define new-rules (program-model-rules new-model))
  (define old-counts (count-by old-rules program-rule-normalized))
  (define new-counts (count-by new-rules program-rule-normalized))
  (define rule-forms
    (sort (remove-duplicates
           (append (hash-keys old-counts) (hash-keys new-counts)))
          string<?))
  (define changes
    (for/list ([normalized (in-list rule-forms)]
               #:unless (= (hash-ref old-counts normalized 0)
                           (hash-ref new-counts normalized 0)))
      (program-rule-change
       (sha256-string normalized) normalized
       (hash-ref old-counts normalized 0)
       (hash-ref new-counts normalized 0))))

  (define old-edges (edge-signatures old-model))
  (define new-edges (edge-signatures new-model))
  (define edges-added (sorted-set-difference new-edges old-edges))
  (define edges-removed (sorted-set-difference old-edges new-edges))

  (define old-writers (writer-signatures old-model))
  (define new-writers (writer-signatures new-model))
  (define writer-relations
    (sort
     (for/list ([rel (in-list
                      (remove-duplicates
                       (append (hash-keys old-writers) (hash-keys new-writers))))]
                #:unless (equal? (sort (hash-ref old-writers rel '()) string<?)
                                 (sort (hash-ref new-writers rel '()) string<?)))
       rel)
     symbol<?))

  (define old-components (component-signatures old-model))
  (define new-components (component-signatures new-model))
  (define components-added
    (sorted-set-difference new-components old-components))
  (define components-removed
    (sorted-set-difference old-components new-components))

  ;; Changed writers are the normal rule-edit roots.  A compiler-derived
  ;; dependency can change with no writer change, so its target is a root too.
  (define affected-roots
    (symbols
     (append writer-relations
             (map second edges-added)
             (map second edges-removed))))
  (define cone
    (program-model-union-cone old-model new-model affected-roots))
  (program-semantic-diff
   (program-model-fingerprint old-model)
   (program-model-fingerprint new-model)
   changes edges-added edges-removed writer-relations
   components-added components-removed affected-roots cone))
