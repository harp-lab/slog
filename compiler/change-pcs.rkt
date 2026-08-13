#lang racket

;; The RF5-B join's producer bridge (docs/activation-contract.md §2, §6):
;; render a SEALED ProgramChangeSet (compiler/program-change.rkt, the rich
;; RF5-A artifact) as one fixture datum in the FROZEN `.pcs` grammar the
;; activation consumer resolves (compiler/activation.rkt).  This is the
;; module that makes the producer and consumer executable together -- the
;; first joint battery (tests/joint-battery.sh) runs its output through
;; tests/api/pcs-check.rkt next to the golden corpus.
;;
;; Identity spelling: the compiler does not know live layer keys, so the
;; emitter always uses the corpus's TEMPLATED placeholder convention --
;; `@BASE-PROGRAM@`, `@BASE-BOUNDARY@`, and `@V:rel@` per carried/retired
;; relation (activation-contract §6/§7: "how a fixture written before a
;; layer exists names that layer's keys").  pcs-check substitutes the
;; synthetic base; session-drive's activate verb substitutes the live one.
;;
;; The three fixture rules hold BY CONSTRUCTION: no live VersionIds (only
;; placeholders), no maintenance routes or publication decisions (no such
;; field is emitted), no inferred lineage (every row below comes from the
;; sealed set's explicit lineage; nothing is matched up here).
;;
;; Disposition doctrine (rf5-contract §4.2/§7): a slot's disposition is
;; derived from the sealed lineage kind and the sealed union cone --
;;   removed lineage            -> retire
;;   added lineage              -> rebuild (a fresh slot; carry would name
;;                                          a version that cannot exist)
;;   member of the union cone   -> rebuild
;;   otherwise                  -> carry
;; The emitter never inspects rule text to decide this: the cone is the
;; compiler's sealed claim, and the consumer re-checks carried slots
;; against the catalog.

(require racket/match
         racket/list
         "program-image.rkt"
         "program-change.rkt")

(provide program-change-set->pcs
         pcs->string)

;; ---------------------------------------------------------------------------
;; Identity spellings (the m1:/r1: renderings of catalog.rkt, §T0(c), over
;; the templated base-program placeholder).
;; ---------------------------------------------------------------------------

(define base-program-placeholder "@BASE-PROGRAM@")
(define base-boundary-placeholder "@BASE-BOUNDARY@")

(define (path->suffix lexical-path)
  (if (null? lexical-path)
      "root"
      (string-join
       (for/list ([step (in-list lexical-path)])
         (match step
           [(list (? exact-nonnegative-integer? slot) (? string? _alias))
            (number->string slot)]
           [_ (error 'program-change-set->pcs
                     "malformed lexical step in image module: ~a" step)]))
       ".")))

(define (module-mkey image module-slot)
  (define m (list-ref (program-image-modules image) module-slot))
  (format "m1:~a:~a" base-program-placeholder
          (path->suffix (image-module-lexical-path m))))

;; A rule's fixture slot is "U.R": U the ordinal of its source unit within
;; its module occurrence's source list, R its ordinal among that unit's
;; rules in image slot order (t0-contract's construction).  Rules the image
;; carries without a module/source binding (peeled or synthesized) sit in
;; unit 0 of the root occurrence, which is where the compiler places them.
(define (rule-ur image rule)
  (define mslot (or (image-rule-module rule) 0))
  (define m (list-ref (program-image-modules image) mslot))
  (define unit
    (or (and (image-rule-source rule)
             (index-of (image-module-sources m) (image-rule-source rule)))
        0))
  (define ordinal
    (for/sum ([other (in-list (program-image-rules image))]
              #:when (and (< (image-rule-slot other) (image-rule-slot rule))
                          (equal? (or (image-rule-module other) 0) mslot)
                          (equal? (image-rule-source other)
                                  (image-rule-source rule))))
      1))
  (values (module-mkey image mslot) (format "~a.~a" unit ordinal)))

(define (rule-r1key image rule)
  (define-values (mkey ur) (rule-ur image rule))
  (format "r1:~a:~a" mkey ur))

;; ---------------------------------------------------------------------------
;; Section renderers.
;; ---------------------------------------------------------------------------

(define (rule-at image slot)
  (findf (lambda (r) (= (image-rule-slot r) slot))
         (program-image-rules image)))

(define (occurrence-rows cs base candidate)
  (for/list ([row (in-list (program-change-set-module-lineage cs))]
             #:when (eq? (module-lineage-kind row) 'modified))
    (define new-module
      (list-ref (program-image-modules candidate)
                (module-lineage-new-module-slot row)))
    `(replace (old ,(module-mkey base (module-lineage-old-module-slot row)))
              (new-slot ,(image-module-lexical-path new-module))
              (home ,(image-module-home new-module)))))

(define (rule-rows cs base candidate)
  (define rows
    (for/list ([row (in-list (program-change-set-rule-lineage cs))]
               #:when (rule-lineage-new-rule-slot row))
      (define new-rule (rule-at candidate (rule-lineage-new-rule-slot row)))
      (define-values (_mkey new-ur) (rule-ur candidate new-rule))
      (define old
        (and (rule-lineage-old-rule-slot row)
             (memq (rule-lineage-kind row) '(preserved))
             (rule-r1key base (rule-at base (rule-lineage-old-rule-slot row)))))
      (list new-ur `((old ,(or old '#f)) (new-slot ,new-ur)))))
  (map second (sort rows string<? #:key first)))

(define (slot-disposition row cone)
  (define relation (or (relation-slot-lineage-new-relation row)
                       (relation-slot-lineage-old-relation row)))
  (case (relation-slot-lineage-kind row)
    [(removed) 'retire]
    [(added) 'rebuild]
    [else (if (memq relation cone) 'rebuild 'carry)]))

;; Only declarations that materialize a VERSIONED relation at a boundary
;; may claim a slot row: a `(listof ...)`-style collection type declaration
;; has no VersionKey to carry, and a `@V:rel@` placeholder for it could
;; never substitute against a live catalog.
(define (versioned-value? value)
  (and (pair? value) (memq (car value) '(table struct lattice oracle))))

(define (output-value image slot)
  (for/first ([output (in-list (program-image-outputs image))]
              #:when (= (program-output-slot output) slot))
    (program-output-value output)))

(define (slot-rows cs base candidate cone)
  ;; base outputs in old-slot order, then genuinely new outputs.
  (define ordered
    (sort (program-change-set-relation-lineage cs) <
          #:key (lambda (row)
                  (or (relation-slot-lineage-old-output-slot row)
                      (+ 1000000 (relation-slot-lineage-new-output-slot row))))))
  (for/list ([row (in-list ordered)]
             #:when (versioned-value?
                     (if (relation-slot-lineage-old-output-slot row)
                         (output-value base
                                       (relation-slot-lineage-old-output-slot row))
                         (output-value candidate
                                       (relation-slot-lineage-new-output-slot row)))))
    (define relation (or (relation-slot-lineage-new-relation row)
                         (relation-slot-lineage-old-relation row)))
    (define old-vkey
      (and (relation-slot-lineage-old-version-key row)
           (format "@V:~a@" relation)))
    `((relation ,relation)
      (old ,(or old-vkey '#f))
      (disposition ,(slot-disposition row cone)))))

(define (written-relations writer-sets)
  (sort (for/list ([record (in-list writer-sets)]
                   #:when (match record
                            [`(writer-set (relation ,_) (writers ,w ...))
                             (pair? w)]
                            [_ #f]))
          (match record [`(writer-set (relation ,r) ,_) r]))
        symbol<?))

(define (scc-rows components cone)
  (define in-cone
    (for/list ([record (in-list components)]
               #:when (match record
                        [`(component (members ,m ...) (level ,_))
                         (for/or ([member (in-list m)]) (memq member cone))]
                        [_ #f]))
      (match record
        [`(component (members ,m ...) (level ,level)) (list level m)])))
  (for/list ([entry (in-list (sort in-cone
                                   (lambda (a b)
                                     (or (< (first a) (first b))
                                         (and (= (first a) (first b))
                                              (symbol<? (first (second a))
                                                        (first (second b))))))))]
             [slot (in-naturals)])
    `(scc ,slot ,(first entry) (members ,@(second entry)))))

(define (rule-change-counts records)
  (for/fold ([added 0] [removed 0]) ([record (in-list records)])
    (match record
      [`(semantic-rule-change ,_ ,_ (old-count ,o) (new-count ,n))
       (values (+ added (max 0 (- n o)))
               (+ removed (max 0 (- o n))))]
      [_ (values added removed)])))

;; ---------------------------------------------------------------------------
;; The emitter.
;; ---------------------------------------------------------------------------

;; sources: ((path-string . text-string) ...) -- the candidate sources the
;; activation writes out and compiles; the sealed set does not retain raw
;; text, so the caller (which compiled the candidate) supplies it.
(define (program-change-set->pcs cs base candidate #:sources [sources '()])
  (validate-program-change-set! cs)
  (define diff (program-change-set-semantic-diff cs))
  (define source-diff (program-change-set-source-diff cs))
  (define exec-diff (program-change-set-execution-diff cs))
  (define cone (semantic-program-diff-union-cone diff))
  (define-values (rules-added rules-removed)
    (let-values ([(ra rr) (rule-change-counts
                           (semantic-program-diff-rules diff))]
                 [(fa fr) (rule-change-counts
                           (semantic-program-diff-facts diff))])
      (values (+ ra fa) (+ rr fr))))
  `(program-change-set (abi 1)
    (base (program ,base-program-placeholder)
          (boundary ,base-boundary-placeholder))
    (candidate (image ,(program-change-set-candidate-image-key cs))
               (compiler ,(program-change-set-required-compiler-key cs))
               (plan-abi ,(program-change-set-required-plan-abi cs))
               (sources ,@(for/list ([s (in-list sources)])
                            `((path ,(car s)) (text ,(cdr s))))))
    (occurrences ,@(occurrence-rows cs base candidate))
    (rule-lineage ,@(rule-rows cs base candidate))
    (slot-lineage ,@(slot-rows cs base candidate cone))
    (diffs (source ,(length (source-occurrence-diff-sources source-diff)))
           (semantic (added ,rules-added) (removed ,rules-removed) (moved 0))
           (plan (kernels-changed
                  ,(length (execution-plan-diff-kernel-changes exec-diff)))))
    (writers (old ,(written-relations
                    (semantic-program-diff-old-writers diff)))
             (new ,(written-relations
                    (semantic-program-diff-new-writers diff))))
    (sccs (old ,(scc-rows (semantic-program-diff-old-components diff) cone))
          (new ,(scc-rows (semantic-program-diff-new-components diff) cone)))
    (affected (roots ,(semantic-program-diff-affected-roots diff))
              (cone ,cone))
    (services ,@(program-change-set-required-services cs))
    (suffix)
    (refusals ,@(for/list ([r (in-list (program-change-set-refusals cs))])
                  (cons (compiler-refusal-code r)
                        (let ([d (compiler-refusal-details r)])
                          (if (list? d) d (list d))))))))

(define (pcs->string datum)
  (with-output-to-string (lambda () (pretty-write datum))))
