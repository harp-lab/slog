#lang racket

;; RF5-A: immutable program drafts and the frozen compiler/session handoff.
;;
;; A ProgramChangeSet is deliberately a compiler-side value.  It describes
;; two already sealed ProgramImages, explicit cross-image correspondence, and
;; three independent diffs.  It never allocates a live VersionId, chooses a
;; maintenance route, or names a publication boundary; those are RF5-B
;; session responsibilities.

(provide
 program-change-set-format-version
 (struct-out program-output)
 (struct-out module-handle)
 (struct-out program-replacement)
 (struct-out module-lineage)
 (struct-out rule-lineage)
 (struct-out relation-slot-lineage)
 (struct-out source-occurrence-diff)
 (struct-out semantic-program-diff)
 (struct-out execution-plan-diff)
 (struct-out compiler-refusal)
 (struct-out program-draft)
 (struct-out program-change-set)
 program-image-outputs
 make-module-handle
 make-program-draft
 program-draft-preserve-module
 program-draft-replace-module
 program-draft-remove-module
 program-draft-add-module
 program-draft-preserve-rule
 program-draft-replace-rule
 program-draft-remove-rule
 program-draft-add-rule
 program-draft-preserve-relation
 program-draft-replace-relation
 program-draft-remove-relation
 program-draft-add-relation
 seal-program-draft
 validate-program-change-set!
 program-change-set->datum
 datum->program-change-set
 program-change-set->string
 write-program-change-set
 read-program-change-set)

(require racket/list
         racket/set
         "canonical-plan.rkt"
         "program-image.rkt"
         "sha256.rkt")

(define program-change-set-format-version 1)

;; The handoff may cross a process boundary before RF5-B can apply transport
;; quotas.  Bound the compiler reader too: its content seal is checked only
;; after the textual value has been parsed.
(define max-program-change-bytes (* 64 1024 1024))
(define max-program-change-nodes 2000000)
(define max-program-change-depth 512)

;; Candidate output slots are dense over ProgramImage relation declarations.
;; They are prospective compiler slots, never daemon VersionIds.
(struct program-output (slot declaration-slot relation value) #:transparent)

;; A handle binds a live occurrence identity to the exact immutable image
;; occurrence it came from.  Aliases and source paths are intentionally absent.
(struct module-handle
  (program-instance module-instance image-key module-slot)
  #:transparent)

(struct program-replacement (old-program-instance new-program-slot)
  #:transparent)
(struct module-lineage
  (old-module-instance old-module-slot new-module-slot kind)
  #:transparent)
(struct rule-lineage
  (old-rule-key old-rule-slot new-rule-slot kind)
  #:transparent)
(struct relation-slot-lineage
  (old-version-key old-output-slot old-relation
                   new-output-slot new-relation kind)
  #:transparent)

;; The payload records below use closed, canonical s-expression records.  The
;; public structs keep the three diff authorities visibly distinct while the
;; wire codec remains small and independently consumable by RF5-B.
(struct source-occurrence-diff
  (occurrences sources rules facts options homes bindings)
  #:transparent)
(struct semantic-program-diff
  (old-model-key new-model-key declarations rules facts bindings options
   edges-added edges-removed old-writers new-writers
   old-components new-components old-component-edges new-component-edges
   affected-roots union-cone)
  #:transparent)
(struct execution-plan-diff
  (old-plan-abi new-plan-abi cohort-changes
   old-kernels new-kernels kernel-changes
   old-bindings new-bindings
   services-added services-removed reusable-kernel-keys)
  #:transparent)
(struct compiler-refusal (code details) #:transparent)

;; Draft updates are persistent values.  Every operation returns revision n+1
;; and leaves the old revision usable.  The sealed images are immutable inputs;
;; a later draft edit cannot mutate an already sealed ProgramChangeSet.
(struct program-draft
  (base-program-instance base-image candidate-image revision
                         module-lineage rule-lineage relation-lineage)
  #:transparent)

(struct program-change-set
  (key format
   base-program-instance base-image-key candidate-image-key draft-revision
   base-module-count candidate-module-count
   base-rule-count candidate-rule-count
   base-output-count candidate-output-count
   program-lineage module-lineage rule-lineage relation-lineage
   source-diff semantic-diff execution-diff
   required-compiler-key required-plan-abi required-services refusals)
  #:transparent)

;; -------------------------------------------------------------------------
;; Canonical carriers and common validation.

(define (sexp->string x)
  (with-output-to-string (lambda () (write x))))

(define (datum-key x) (sexp->string x))

(define (digest x)
  (bytes->hex-string
   (sha256 (string->bytes/utf-8 (sexp->string x)))))

(define (string-digest text)
  (bytes->hex-string (sha256 (string->bytes/utf-8 text))))

(define (sorted-records xs)
  (sort xs string<? #:key datum-key))

(define (symbols xs)
  (sort (remove-duplicates xs) symbol<?))

(define (portable-key? x)
  (and (string? x)
       (regexp-match? #px"^[A-Za-z0-9._:-]+$" x)))

(define (non-empty-string? x)
  (and (string? x) (positive? (string-length x))))

(define (content-key? x)
  (and (string? x) (regexp-match? #px"^[0-9a-f]{64}$" x)))

(define (change-fail fmt . args)
  (error 'program-change (apply format fmt args)))

(define (check-portable who value)
  (unless (portable-key? value)
    (raise-argument-error who
                          "non-empty portable identity string"
                          value)))

(define (in-range? n count)
  (and (exact-nonnegative-integer? n) (< n count)))

(define (canonical-record-list? xs)
  (and (list? xs)
       (equal? xs (sorted-records xs))
       (= (length xs) (length (remove-duplicates xs)))))

;; The handoff is intentionally a closed textual value.  In particular, a
;; caller-supplied refusal cannot smuggle a hash with iteration-dependent
;; printing, an opaque object, or a live runtime handle into the content key.
(define (closed-datum? x)
  (cond [(list? x) (andmap closed-datum? x)]
        [(pair? x) #f]
        [else (or (boolean? x) (number? x) (string? x) (symbol? x)
                  (char? x) (bytes? x))]))

(define (read-bounded-datum in byte-limit who)
  (define out (open-output-bytes))
  (let loop ([total 0])
    (define chunk (read-bytes 8192 in))
    (cond
      [(eof-object? chunk) (void)]
      [else
       (define next (+ total (bytes-length chunk)))
       (when (> next byte-limit)
         (change-fail "~a exceeds the ~a-byte decoder limit" who byte-limit))
       (write-bytes chunk out)
       (loop next)]))
  (define bounded-in (open-input-bytes (get-output-bytes out)))
  (define datum
    (parameterize ([read-accept-graph #f]
                   [read-accept-reader #f])
      (read bounded-in)))
  (when (eof-object? datum)
    (change-fail "empty ~a stream" who))
  (unless (eof-object?
           (parameterize ([read-accept-graph #f]
                          [read-accept-reader #f])
             (read bounded-in)))
    (change-fail "trailing data after ~a" who))
  datum)

(define (check-datum-budget! datum who node-limit depth-limit)
  (define nodes 0)
  (define (walk value depth)
    (set! nodes (add1 nodes))
    (when (> nodes node-limit)
      (change-fail "~a exceeds the ~a-node decoder limit" who node-limit))
    (when (> depth depth-limit)
      (change-fail "~a exceeds the ~a-level decoder limit" who depth-limit))
    (cond
      [(list? value)
       (for ([item (in-list value)]) (walk item (add1 depth)))]
      [(pair? value)
       (walk (car value) (add1 depth))
       (walk (cdr value) (add1 depth))]
      [(vector? value)
       (for ([item (in-vector value)]) (walk item (add1 depth)))]
      [else (void)]))
  (walk datum 0))

(define (program-image-outputs image)
  (validate-program-image! image)
  (for/list ([declaration
              (in-list
               (filter (lambda (d)
                         (eq? (image-declaration-namespace d) 'relation))
                       (program-image-declarations image)))]
             [slot (in-naturals)])
    (program-output slot
                    (image-declaration-slot declaration)
                    (image-declaration-name declaration)
                    (image-declaration-value declaration))))

(define (output-at image slot [who 'program-change])
  (define outputs (program-image-outputs image))
  (unless (in-range? slot (length outputs))
    (raise-argument-error who
                          "candidate relation-output slot in range"
                          slot))
  (list-ref outputs slot))

(define (base-output-at image slot [who 'program-change])
  (define outputs (program-image-outputs image))
  (unless (in-range? slot (length outputs))
    (raise-argument-error who "base relation-output slot in range" slot))
  (list-ref outputs slot))

;; -------------------------------------------------------------------------
;; Immutable draft construction and explicit lineage operations.

(define (make-module-handle program-instance module-instance image module-slot)
  (check-portable 'make-module-handle program-instance)
  (check-portable 'make-module-handle module-instance)
  (validate-program-image! image)
  (program-image-module-at image module-slot)
  (module-handle program-instance module-instance
                 (program-image-key image) module-slot))

(define (make-program-draft base-program-instance base-image candidate-image)
  (check-portable 'make-program-draft base-program-instance)
  (validate-program-image! base-image)
  (validate-program-image! candidate-image)
  (program-draft base-program-instance base-image candidate-image 0 '() '() '()))

(define (check-draft who draft)
  (unless (program-draft? draft)
    (raise-argument-error who "program-draft?" draft)))

(define (check-base-handle who draft handle)
  (unless (module-handle? handle)
    (raise-argument-error who "module-handle?" handle))
  (unless (and (equal? (module-handle-program-instance handle)
                       (program-draft-base-program-instance draft))
               (equal? (module-handle-image-key handle)
                       (program-image-key (program-draft-base-image draft))))
    (change-fail "module handle belongs to another program/image"))
  (program-image-module-at (program-draft-base-image draft)
                           (module-handle-module-slot handle)))

(define (slot-used? old-accessor new-accessor entries old-slot new-slot)
  (or (and old-slot
           (for/or ([entry (in-list entries)])
             (equal? (old-accessor entry) old-slot)))
      (and new-slot
           (for/or ([entry (in-list entries)])
             (equal? (new-accessor entry) new-slot)))))

(define (add-module-lineage who draft old-instance old-slot new-slot kind)
  (check-draft who draft)
  (when old-slot
    (program-image-module-at (program-draft-base-image draft) old-slot))
  (when new-slot
    (program-image-module-at (program-draft-candidate-image draft) new-slot))
  (when (slot-used? module-lineage-old-module-slot
                    module-lineage-new-module-slot
                    (program-draft-module-lineage draft) old-slot new-slot)
    (change-fail "module lineage reuses old slot ~s or new slot ~s"
                 old-slot new-slot))
  (struct-copy
   program-draft draft
   [revision (add1 (program-draft-revision draft))]
   [module-lineage
    (cons (module-lineage old-instance old-slot new-slot kind)
          (program-draft-module-lineage draft))]))

(define (program-draft-preserve-module draft handle new-slot)
  (check-draft 'program-draft-preserve-module draft)
  (check-base-handle 'program-draft-preserve-module draft handle)
  (add-module-lineage
   'program-draft-preserve-module draft
   (module-handle-module-instance handle) (module-handle-module-slot handle)
   new-slot 'preserved))

(define (program-draft-replace-module draft handle new-slot)
  (check-draft 'program-draft-replace-module draft)
  (check-base-handle 'program-draft-replace-module draft handle)
  (add-module-lineage
   'program-draft-replace-module draft
   (module-handle-module-instance handle) (module-handle-module-slot handle)
   new-slot 'modified))

(define (program-draft-remove-module draft handle)
  (check-draft 'program-draft-remove-module draft)
  (check-base-handle 'program-draft-remove-module draft handle)
  (add-module-lineage
   'program-draft-remove-module draft
   (module-handle-module-instance handle) (module-handle-module-slot handle)
   #f 'removed))

(define (program-draft-add-module draft new-slot)
  (add-module-lineage 'program-draft-add-module draft #f #f new-slot 'added))

(define (check-old-rule who draft key slot)
  (check-portable who key)
  (program-image-rule-at (program-draft-base-image draft) slot))

(define (add-rule-lineage who draft key old-slot new-slot kind)
  (check-draft who draft)
  (when old-slot (check-old-rule who draft key old-slot))
  (when new-slot
    (program-image-rule-at (program-draft-candidate-image draft) new-slot))
  (when (slot-used? rule-lineage-old-rule-slot rule-lineage-new-rule-slot
                    (program-draft-rule-lineage draft) old-slot new-slot)
    (change-fail "rule lineage reuses old slot ~s or new slot ~s"
                 old-slot new-slot))
  (struct-copy
   program-draft draft
   [revision (add1 (program-draft-revision draft))]
   [rule-lineage
    (cons (rule-lineage key old-slot new-slot kind)
          (program-draft-rule-lineage draft))]))

(define (program-draft-preserve-rule draft old-rule-key old-slot new-slot)
  (add-rule-lineage 'program-draft-preserve-rule draft old-rule-key
                    old-slot new-slot 'preserved))

;; Completes the symmetric draft-verb family (preserve/replace/remove/add).
;; No current producer emits 'modified rule lineage -- auto-program-draft
;; pairs rules by normalized text, so a changed rule is a remove+add -- but
;; datum->rule-lineage reads the 'modified kind off the wire, so the verb
;; and its vocabulary are kept intentionally for a producer that diffs rules
;; positionally.
(define (program-draft-replace-rule draft old-rule-key old-slot new-slot)
  (add-rule-lineage 'program-draft-replace-rule draft old-rule-key
                    old-slot new-slot 'modified))

(define (program-draft-remove-rule draft old-rule-key old-slot)
  (add-rule-lineage 'program-draft-remove-rule draft old-rule-key
                    old-slot #f 'removed))

(define (program-draft-add-rule draft new-slot)
  (add-rule-lineage 'program-draft-add-rule draft #f #f new-slot 'added))

(define (check-old-relation who draft version-key old-slot)
  (check-portable who version-key)
  (base-output-at (program-draft-base-image draft) old-slot who))

(define (add-relation-lineage who draft version-key old-slot new-slot kind)
  (check-draft who draft)
  (define old-output
    (and old-slot (check-old-relation who draft version-key old-slot)))
  (define new-output
    (and new-slot (output-at (program-draft-candidate-image draft) new-slot who)))
  (when (slot-used? relation-slot-lineage-old-output-slot
                    relation-slot-lineage-new-output-slot
                    (program-draft-relation-lineage draft) old-slot new-slot)
    (change-fail "relation lineage reuses old output ~s or new output ~s"
                 old-slot new-slot))
  (struct-copy
   program-draft draft
   [revision (add1 (program-draft-revision draft))]
   [relation-lineage
    (cons
     (relation-slot-lineage
      version-key old-slot (and old-output (program-output-relation old-output))
      new-slot (and new-output (program-output-relation new-output)) kind)
     (program-draft-relation-lineage draft))]))

(define (program-draft-preserve-relation draft old-version-key old-slot new-slot)
  (define old-output (base-output-at (program-draft-base-image draft) old-slot))
  (define new-output (output-at (program-draft-candidate-image draft) new-slot))
  (unless (equal? (program-output-relation old-output)
                  (program-output-relation new-output))
    (change-fail "preserved relation lineage cannot rename ~s to ~s"
                 (program-output-relation old-output)
                 (program-output-relation new-output)))
  (add-relation-lineage 'program-draft-preserve-relation draft old-version-key
                        old-slot new-slot 'preserved))

(define (program-draft-replace-relation draft old-version-key old-slot new-slot)
  (add-relation-lineage 'program-draft-replace-relation draft old-version-key
                        old-slot new-slot 'modified))

(define (program-draft-remove-relation draft old-version-key old-slot)
  (add-relation-lineage 'program-draft-remove-relation draft old-version-key
                        old-slot #f 'removed))

(define (program-draft-add-relation draft new-slot)
  (add-relation-lineage 'program-draft-add-relation draft #f #f new-slot 'added))

;; -------------------------------------------------------------------------
;; Diff construction.

(define (image-module-at/optional image slot)
  (and slot (program-image-module-at image slot)))

(define (image-rule-at/optional image slot)
  (and slot (program-image-rule-at image slot)))

(define (module-source-snapshots image module-slot)
  (if module-slot
      (for/list ([source-slot
                  (in-list
                   (image-module-sources
                    (program-image-module-at image module-slot)))])
        (define source (program-image-source-at image source-slot))
        `(source ,source-slot ,(image-source-path source)
                 ,(image-source-digest source)))
      '()))

(define (group-sources-by-digest snapshots)
  (for/fold ([h (hash)]) ([snapshot (in-list snapshots)])
    (hash-update h (fourth snapshot) (lambda (xs) (cons snapshot xs)) '())))

(define (source-records-for-lineage base candidate lineage)
  (define old-slot (module-lineage-old-module-slot lineage))
  (define new-slot (module-lineage-new-module-slot lineage))
  (define old-groups
    (group-sources-by-digest (module-source-snapshots base old-slot)))
  (define new-groups
    (group-sources-by-digest (module-source-snapshots candidate new-slot)))
  (for/list ([source-digest
              (in-list
               (sort (remove-duplicates
                      (append (hash-keys old-groups) (hash-keys new-groups)))
                     string<?))])
    (define olds (sorted-records (hash-ref old-groups source-digest '())))
    (define news (sorted-records (hash-ref new-groups source-digest '())))
    (define kind
      (cond [(null? olds) 'added]
            [(null? news) 'removed]
            [(equal? (sorted-records
                      (for/list ([snapshot (in-list olds)])
                        (list (third snapshot) (fourth snapshot))))
                     (sorted-records
                      (for/list ([snapshot (in-list news)])
                        (list (third snapshot) (fourth snapshot)))))
             'preserved]
            [else 'modified]))
    `(source-change ,kind
                    (old-module ,old-slot) (new-module ,new-slot)
                    (digest ,source-digest)
                    (old ,@olds) (new ,@news))))

(define (ground-rule-slots image)
  ;; Match compile.rkt's ground-fact-rules classification, including rules
  ;; whose only positive reads are constant-class relations.  Testing merely
  ;; for an empty relation body misclassified the cartesian closure of program
  ;; facts as an ordinary derived rule even though compilation places it in
  ;; the facts stratum.
  (define relation-names
    (list->set
     (for/list ([declaration (in-list (program-image-declarations image))]
                #:when (eq? (image-declaration-namespace declaration)
                            'relation))
       (image-declaration-name declaration))))
  (define rules (program-image-rules image))
  (define (body-reads rule)
    (set-intersect
     (list->set (append (image-rule-positive rule)
                        (image-rule-negative rule)))
     relation-names))
  (define strict
    (for/set ([rule (in-list rules)] #:when (set-empty? (body-reads rule)))
      (image-rule-slot rule)))
  (define strict-heads
    (for/fold ([heads (set)]) ([rule (in-list rules)]
                               #:when (set-member? strict
                                                   (image-rule-slot rule)))
      (set-union heads (list->set (image-rule-heads rule)))))
  (define tainted
    (for/fold ([heads (set)]) ([rule (in-list rules)]
                               #:unless (set-member? strict
                                                     (image-rule-slot rule)))
      (set-union heads (list->set (image-rule-heads rule)))))
  (define constant-relations (set-subtract strict-heads tainted))
  (for/set ([rule (in-list rules)]
            #:when (and (null? (image-rule-negative rule))
                        (subset? (body-reads rule) constant-relations)))
    (image-rule-slot rule)))

(define (rule-lineage-record base candidate lineage)
  (define old-rule
    (image-rule-at/optional base (rule-lineage-old-rule-slot lineage)))
  (define new-rule
    (image-rule-at/optional candidate (rule-lineage-new-rule-slot lineage)))
  `(rule-change ,(rule-lineage-kind lineage)
                (old-key ,(rule-lineage-old-rule-key lineage))
                (old-slot ,(rule-lineage-old-rule-slot lineage))
                (new-slot ,(rule-lineage-new-rule-slot lineage))
                (old-fingerprint ,(and old-rule
                                       (image-rule-fingerprint old-rule)))
                (new-fingerprint ,(and new-rule
                                       (image-rule-fingerprint new-rule)))
                (old-origin ,(and old-rule (image-rule-origin old-rule)))
                (new-origin ,(and new-rule (image-rule-origin new-rule)))))

(define (changed-module-field base candidate lineage accessor tag)
  (define old-module
    (image-module-at/optional base (module-lineage-old-module-slot lineage)))
  (define new-module
    (image-module-at/optional candidate (module-lineage-new-module-slot lineage)))
  (define old-value (and old-module (accessor old-module)))
  (define new-value (and new-module (accessor new-module)))
  (and (not (equal? old-value new-value))
       `(,tag (old-module ,(module-lineage-old-module-slot lineage))
              (new-module ,(module-lineage-new-module-slot lineage))
              (old ,old-value) (new ,new-value))))

(define (module-lineage->datum lineage)
  `(module (old-instance ,(module-lineage-old-module-instance lineage))
           (old-slot ,(module-lineage-old-module-slot lineage))
           (new-slot ,(module-lineage-new-module-slot lineage))
           (kind ,(module-lineage-kind lineage))))

(define (rule-lineage->datum lineage)
  `(rule (old-key ,(rule-lineage-old-rule-key lineage))
         (old-slot ,(rule-lineage-old-rule-slot lineage))
         (new-slot ,(rule-lineage-new-rule-slot lineage))
         (kind ,(rule-lineage-kind lineage))))

(define (relation-lineage->datum lineage)
  `(relation (old-version-key ,(relation-slot-lineage-old-version-key lineage))
             (old-output-slot ,(relation-slot-lineage-old-output-slot lineage))
             (old-relation ,(relation-slot-lineage-old-relation lineage))
             (new-output-slot ,(relation-slot-lineage-new-output-slot lineage))
             (new-relation ,(relation-slot-lineage-new-relation lineage))
             (kind ,(relation-slot-lineage-kind lineage))))

(define (make-source-diff draft modules rules)
  (define base (program-draft-base-image draft))
  (define candidate (program-draft-candidate-image draft))
  (define old-ground (ground-rule-slots base))
  (define new-ground (ground-rule-slots candidate))
  (define sources
    (sorted-records
     (append*
      (for/list ([lineage (in-list modules)])
        (source-records-for-lineage base candidate lineage)))))
  (define-values (rule-records fact-records)
    (for/fold ([rs '()] [fs '()]) ([lineage (in-list rules)])
      (define old-rule
        (image-rule-at/optional base (rule-lineage-old-rule-slot lineage)))
      (define new-rule
        (image-rule-at/optional candidate (rule-lineage-new-rule-slot lineage)))
      (define record (rule-lineage-record base candidate lineage))
      (if (or (and old-rule
                   (set-member? old-ground (image-rule-slot old-rule)))
              (and new-rule
                   (set-member? new-ground (image-rule-slot new-rule))))
          (values rs (cons record fs))
          (values (cons record rs) fs))))
  (define homes
    (filter values
            (for/list ([lineage (in-list modules)])
              (changed-module-field base candidate lineage image-module-home
                                    'home-change))))
  (define bindings
    (filter values
            (for/list ([lineage (in-list modules)])
              (changed-module-field base candidate lineage image-module-bindings
                                    'binding-change))))
  ;; ProgramImage currently has no separate option occurrence carrier.  The
  ;; empty explicit section prevents a consumer from mistaking bindings or
  ;; executor flavor for compile-time options.
  (source-occurrence-diff
   (sorted-records (map module-lineage->datum modules))
   sources (sorted-records rule-records) (sorted-records fact-records)
   '() (sorted-records homes) (sorted-records bindings)))

(define (count-by xs key)
  (for/fold ([h (hash)]) ([x (in-list xs)])
    (hash-update h (key x) add1 0)))

(define (semantic-rule-records olds news)
  (define old-counts (count-by olds image-rule-normalized))
  (define new-counts (count-by news image-rule-normalized))
  (for/list ([normalized
              (in-list
               (sort (remove-duplicates
                      (append (hash-keys old-counts) (hash-keys new-counts)))
                     string<?))]
             #:unless (= (hash-ref old-counts normalized 0)
                         (hash-ref new-counts normalized 0)))
    `(semantic-rule-change
      (fingerprint ,(string-digest normalized))
      (normalized ,normalized)
      (old-count ,(hash-ref old-counts normalized 0))
      (new-count ,(hash-ref new-counts normalized 0)))))

(define (relation-declaration-records base candidate relations)
  (for/list ([lineage (in-list relations)])
    (define old-output
      (and (relation-slot-lineage-old-output-slot lineage)
           (base-output-at base
                           (relation-slot-lineage-old-output-slot lineage))))
    (define new-output
      (and (relation-slot-lineage-new-output-slot lineage)
           (output-at candidate
                      (relation-slot-lineage-new-output-slot lineage))))
    (define compatibility
      (cond [(not old-output) 'added]
            [(not new-output) 'retired]
            [(equal? (program-output-value old-output)
                     (program-output-value new-output))
             'compatible]
            [else 'incompatible]))
    `(declaration-change
      (namespace relation)
      (kind ,(relation-slot-lineage-kind lineage))
      (old-name ,(and old-output (program-output-relation old-output)))
      (new-name ,(and new-output (program-output-relation new-output)))
      (old-slot ,(and old-output (program-output-declaration-slot old-output)))
      (new-slot ,(and new-output (program-output-declaration-slot new-output)))
      (compatibility ,compatibility)
      (old-value ,(and old-output (program-output-value old-output)))
      (new-value ,(and new-output (program-output-value new-output))))))

(define (nonrelation-declaration-map image)
  (for/hash ([declaration (in-list (program-image-declarations image))]
             #:unless (eq? (image-declaration-namespace declaration) 'relation))
    (values (list (image-declaration-namespace declaration)
                  (image-declaration-name declaration))
            declaration)))

(define (nonrelation-declaration-records base candidate)
  (define old-map (nonrelation-declaration-map base))
  (define new-map (nonrelation-declaration-map candidate))
  (for/list ([key
              (in-list
               (sorted-records
                (remove-duplicates
                 (append (hash-keys old-map) (hash-keys new-map)))))])
    (define old (hash-ref old-map key #f))
    (define new (hash-ref new-map key #f))
    (define kind
      (cond [(not old) 'added]
            [(not new) 'retired]
            [(equal? (image-declaration-value old)
                     (image-declaration-value new)) 'preserved]
            [else 'modified]))
    `(declaration-change
      (namespace ,(first key)) (kind ,kind)
      (old-name ,(and old (image-declaration-name old)))
      (new-name ,(and new (image-declaration-name new)))
      (old-slot ,(and old (image-declaration-slot old)))
      (new-slot ,(and new (image-declaration-slot new)))
      (compatibility ,(if (memq kind '(preserved added retired))
                          kind 'incompatible))
      (old-value ,(and old (image-declaration-value old)))
      (new-value ,(and new (image-declaration-value new))))))

(define (edge-counts image)
  (count-by (program-image-dependencies image)
            (lambda (edge)
              (list (image-dependency-from edge)
                    (image-dependency-to edge)
                    (image-dependency-kind edge)))))

(define (dependency-changes base candidate)
  (define olds (edge-counts base))
  (define news (edge-counts candidate))
  (define added '())
  (define removed '())
  (for ([signature
         (in-list
          (sorted-records
           (remove-duplicates (append (hash-keys olds) (hash-keys news)))))])
    (define old-count (hash-ref olds signature 0))
    (define new-count (hash-ref news signature 0))
    (unless (= old-count new-count)
      (define record
        `(dependency-change
          (from ,(first signature)) (to ,(second signature))
          (kind ,(third signature))
          (old-count ,old-count) (new-count ,new-count)))
      (when (> new-count old-count) (set! added (cons record added)))
      (when (< new-count old-count) (set! removed (cons record removed)))))
  (values (sorted-records added) (sorted-records removed)))

(define (writer-records image)
  (define by-relation
    (for*/fold ([h (hash)])
               ([rule (in-list (program-image-rules image))]
                [head (in-list (image-rule-heads rule))])
      (hash-update h head
                   (lambda (fingerprints)
                     (cons (image-rule-fingerprint rule) fingerprints))
                   '())))
  ;; Include explicit empty sets for declared input-only relations.  RF5-B
  ;; must not have to infer whether an absent row means "zero writers" or
  ;; "the compiler forgot this relation".
  (define relations
    (symbols
     (append (map program-output-relation (program-image-outputs image))
             (hash-keys by-relation))))
  (for/list ([relation (in-list relations)])
    (define counts (count-by (hash-ref by-relation relation '()) values))
    `(writer-set
      (relation ,relation)
      (writers
       ,@(for/list ([fingerprint (in-list (sort (hash-keys counts) string<?))])
           `(writer ,fingerprint ,(hash-ref counts fingerprint)))))))

(define (component-records image)
  (for/list ([component (in-list (program-image-components image))])
    `(component (members ,@(image-component-members component))
                (level ,(image-component-level component)))))

(define (component-edge-records image)
  (define components (program-image-components image))
  (for/list ([edge (in-list (program-image-component-edges image))])
    `(component-edge
      (from ,@(image-component-members
               (list-ref components (image-component-edge-from edge))))
      (to ,@(image-component-members
             (list-ref components (image-component-edge-to edge))))
      (kinds ,@(image-component-edge-kinds edge)))))

(define (changed-writer-relations old-writers new-writers)
  (define old-map
    (for/hash ([record (in-list old-writers)])
      (values (second (second record)) record)))
  (define new-map
    (for/hash ([record (in-list new-writers)])
      (values (second (second record)) record)))
  (for/list ([relation
              (in-list
               (symbols (append (hash-keys old-map) (hash-keys new-map))))]
             #:unless (equal? (hash-ref old-map relation #f)
                             (hash-ref new-map relation #f)))
    relation))

(define (changed-binding-relations base candidate source-diff)
  (define changed-module-slots
    (for/list ([record (in-list (source-occurrence-diff-bindings source-diff))])
      (match record
        [`(binding-change (old-module ,old) (new-module ,new) ,_ ...)
         (cons old new)])))
  (define (relations image slots old?)
    (append*
     (for/list ([pair (in-list slots)])
       (define slot (if old? (car pair) (cdr pair)))
       (if slot
           (append*
            (for/list ([rule (in-list (program-image-rules image))]
                       #:when (equal? (image-rule-module rule) slot))
              (append (image-rule-heads rule)
                      (image-rule-positive rule)
                      (image-rule-negative rule))))
           '()))))
  (symbols
   (append (relations base changed-module-slots #t)
           (relations candidate changed-module-slots #f))))

(define (changed-rule-heads base candidate rule-changes fact-changes)
  (define fingerprints
    (for/list ([record (in-list (append rule-changes fact-changes))])
      (match record
        [`(semantic-rule-change (fingerprint ,fingerprint) ,_ ...)
         fingerprint])))
  (symbols
   (append*
    (for/list ([rule (in-list (append (program-image-rules base)
                                     (program-image-rules candidate)))]
               #:when (member (image-rule-fingerprint rule) fingerprints))
      (image-rule-heads rule)))))

(define (service-relations services)
  (symbols
   (append*
    (for/list ([service (in-list services)])
      (match service
        [`(oracle ,_ ,demand ,answer) (list demand answer)]
        [`(seqindex ,base ,_ ...) (list base)]
        [_ '()])))))

(define (changed-service-relations base candidate)
  (define-values (_old-kernels _old-bindings old-services)
    (cohort-snapshots base))
  (define-values (_new-kernels _new-bindings new-services)
    (cohort-snapshots candidate))
  (service-relations
   (set->list
    (set-symmetric-difference (list->set old-services)
                              (list->set new-services)))))

(define (union-forward-cone base candidate roots)
  (define successors
    (for/fold ([h (hash)])
              ([edge (in-list
                      (append (program-image-dependencies base)
                              (program-image-dependencies candidate)))])
      (hash-update h (image-dependency-from edge)
                   (lambda (targets)
                     (set-add targets (image-dependency-to edge)))
                   (set))))
  (let loop ([pending roots] [seen (set)])
    (cond
      [(null? pending) (sort (set->list seen) symbol<?)]
      [(set-member? seen (car pending)) (loop (cdr pending) seen)]
      [else
       (define relation (car pending))
       (loop (append (set->list (hash-ref successors relation (set)))
                     (cdr pending))
             (set-add seen relation))])))

(define (make-semantic-diff draft relations source-diff)
  (define base (program-draft-base-image draft))
  (define candidate (program-draft-candidate-image draft))
  (define declarations
    (sorted-records
     (append (relation-declaration-records base candidate relations)
             (nonrelation-declaration-records base candidate))))
  (define old-rules (program-image-rules base))
  (define new-rules (program-image-rules candidate))
  (define old-ground (ground-rule-slots base))
  (define new-ground (ground-rule-slots candidate))
  (define old-facts
    (filter (lambda (rule)
              (set-member? old-ground (image-rule-slot rule)))
            old-rules))
  (define new-facts
    (filter (lambda (rule)
              (set-member? new-ground (image-rule-slot rule)))
            new-rules))
  (define old-derived
    (filter (lambda (rule)
              (not (set-member? old-ground (image-rule-slot rule))))
            old-rules))
  (define new-derived
    (filter (lambda (rule)
              (not (set-member? new-ground (image-rule-slot rule))))
            new-rules))
  (define rules (semantic-rule-records old-derived new-derived))
  (define facts (semantic-rule-records old-facts new-facts))
  (define-values (edges-added edges-removed)
    (dependency-changes base candidate))
  (define old-writers (writer-records base))
  (define new-writers (writer-records candidate))
  (define declaration-roots
    (symbols
     (append*
      (for/list ([lineage (in-list relations)])
        (if (eq? (relation-slot-lineage-kind lineage) 'preserved)
            '()
            (filter values
                    (list (relation-slot-lineage-old-relation lineage)
                          (relation-slot-lineage-new-relation lineage))))))))
  (define edge-roots
    (symbols
     (for/list ([record (in-list (append edges-added edges-removed))])
       (match record [`(dependency-change ,_ (to ,to) ,_ ...) to]))))
  (define roots
    (symbols
     (append declaration-roots edge-roots
             (changed-writer-relations old-writers new-writers)
             (changed-binding-relations base candidate source-diff)
             (changed-rule-heads base candidate rules facts)
             (changed-service-relations base candidate))))
  (semantic-program-diff
   (program-image-model-key base) (program-image-model-key candidate)
   declarations (sorted-records rules) (sorted-records facts)
   (source-occurrence-diff-bindings source-diff)
   (source-occurrence-diff-options source-diff)
   edges-added edges-removed old-writers new-writers
   (sorted-records (component-records base))
   (sorted-records (component-records candidate))
   (sorted-records (component-edge-records base))
   (sorted-records (component-edge-records candidate))
   roots (union-forward-cone base candidate roots)))

(define (cohort-snapshots image)
  (define kernels '())
  (define bindings '())
  (define services '())
  (for ([cohort (in-list (program-image-cohorts image))])
    (match (image-cohort-plan cohort)
      [`(kernel-cohort (abi ,_abi) (flavor ,flavor)
                       (attachments ,attachments ...)
                       (declarations ,_declarations ...)
                       (dynamic ,_dynamic ...)
                       (manifest ,manifest ...)
                       ,kernel-forms ...)
       (set! services (append attachments services))
       (for ([entry (in-list manifest)])
         (match entry
           [`(kernel (ord ,ord) (key ,key) ,attributes ...)
            (define kernel
              (for/first ([form (in-list kernel-forms)]
                          #:when
                          (match form
                            [`(kernel (ord ,candidate-ord) ,_ ...)
                             (= candidate-ord ord)]
                            [_ #f]))
                form))
            (unless kernel
              (change-fail "cohort ~a manifest kernel ~a is absent"
                           (image-cohort-slot cohort) ord))
            (match-define
              `(kernel (ord ,_) ,exec (binding ,binding-slots ...) ,_ ...)
              kernel)
            (unless (equal? key (kernel-exec-key exec))
              (change-fail "cohort ~a kernel ~a key does not match exec"
                           (image-cohort-slot cohort) ord))
            (define members
              (match (assq 'members attributes)
                [`(members ,names ...) names]
                [_ '()]))
            (define rule-count
              (match (assq 'rules attributes)
                [`(rules ,count) count]
                [_ 0]))
            (define prelude?
              (match (assq 'prelude attributes)
                [`(prelude ,value) value]
                [_ #f]))
            (set! kernels
                  (cons `(kernel (cohort ,(image-cohort-slot cohort))
                                 (ordinal ,ord) (flavor ,flavor)
                                 (key ,key) (members ,@members)
                                 (prelude ,prelude?) (rules ,rule-count))
                        kernels))
            (set! bindings
                  (cons `(binding-frame
                          (kernel-key ,key)
                          (cohort ,(image-cohort-slot cohort))
                          (ordinal ,ord)
                          (slots ,@binding-slots))
                        bindings))]
           [_ (change-fail "malformed kernel manifest entry: ~s" entry)]))]
      [_ (change-fail "malformed Plan-ABI-2 cohort in ProgramImage")]))
  (values (sorted-records kernels)
          (sorted-records bindings)
          (sorted-records (remove-duplicates services))))

(define (multiplicity-changes old-values new-values tag value-tag)
  (define olds (count-by old-values values))
  (define news (count-by new-values values))
  (for/list ([value
              (in-list
               (sorted-records
                (remove-duplicates
                 (append (hash-keys olds) (hash-keys news)))))]
             #:unless (= (hash-ref olds value 0) (hash-ref news value 0)))
    `(,tag (,value-tag ,value)
           (old-count ,(hash-ref olds value 0))
           (new-count ,(hash-ref news value 0)))))

(define (kernel-keys kernels)
  (for/list ([kernel (in-list kernels)])
    (match kernel [`(kernel ,_ ... (key ,key) ,_ ...) key])))

(define (make-execution-diff base candidate)
  (define old-cohorts (map image-cohort-digest (program-image-cohorts base)))
  (define new-cohorts (map image-cohort-digest
                           (program-image-cohorts candidate)))
  (define-values (old-kernels old-bindings old-services)
    (cohort-snapshots base))
  (define-values (new-kernels new-bindings new-services)
    (cohort-snapshots candidate))
  (define old-keys (kernel-keys old-kernels))
  (define new-keys (kernel-keys new-kernels))
  (define old-counts (count-by old-keys values))
  (define new-counts (count-by new-keys values))
  (define reusable
    (for/list ([key
                (in-list
                 (sort (set->list
                        (set-intersect (list->set old-keys)
                                       (list->set new-keys)))
                       string<?))])
      `(kernel-key ,key
                   (reusable-count ,(min (hash-ref old-counts key)
                                        (hash-ref new-counts key))))))
  (execution-plan-diff
   (program-image-plan-abi base) (program-image-plan-abi candidate)
   (multiplicity-changes old-cohorts new-cohorts
                         'cohort-change 'digest)
   old-kernels new-kernels
   (multiplicity-changes old-keys new-keys 'kernel-change 'key)
   old-bindings new-bindings
   (sorted-records (set->list
                    (set-subtract (list->set new-services)
                                  (list->set old-services))))
   (sorted-records (set->list
                    (set-subtract (list->set old-services)
                                  (list->set new-services))))
   reusable))

;; -------------------------------------------------------------------------
;; Draft sealing and compiler-known refusals.

(define (covered-slots entries accessor)
  (sort (filter exact-nonnegative-integer? (map accessor entries)) <))

(define (check-total-lineage who entries old-accessor new-accessor
                             old-count new-count)
  (unless (equal? (covered-slots entries old-accessor) (range old-count))
    (change-fail "~a lineage does not exactly cover base slots 0..~a"
                 who (sub1 old-count)))
  (unless (equal? (covered-slots entries new-accessor) (range new-count))
    (change-fail "~a lineage does not exactly cover candidate slots 0..~a"
                 who (sub1 new-count))))

(define (validate-preserved-lineage! draft modules rules relations)
  (define base (program-draft-base-image draft))
  (define candidate (program-draft-candidate-image draft))
  (for ([lineage (in-list modules)]
        #:when (eq? (module-lineage-kind lineage) 'preserved))
    (define old (program-image-module-at base
                                         (module-lineage-old-module-slot lineage)))
    (define new (program-image-module-at candidate
                                         (module-lineage-new-module-slot lineage)))
    (define old-shape
      (list (image-module-home old) (image-module-lexical-path old)
            (image-module-bindings old)
            (map fourth
                 (module-source-snapshots
                  base (module-lineage-old-module-slot lineage)))))
    (define new-shape
      (list (image-module-home new) (image-module-lexical-path new)
            (image-module-bindings new)
            (map fourth
                 (module-source-snapshots
                  candidate (module-lineage-new-module-slot lineage)))))
    (unless (equal? old-shape new-shape)
      (change-fail "module marked preserved has changed occurrence content: ~s"
                   (module-lineage-old-module-instance lineage))))
  (for ([lineage (in-list rules)]
        #:when (eq? (rule-lineage-kind lineage) 'preserved))
    (define old (program-image-rule-at base (rule-lineage-old-rule-slot lineage)))
    (define new
      (program-image-rule-at candidate (rule-lineage-new-rule-slot lineage)))
    (unless (equal? (image-rule-normalized old) (image-rule-normalized new))
      (change-fail "rule marked preserved changed normalized semantics: ~s"
                   (rule-lineage-old-rule-key lineage))))
  (for ([lineage (in-list relations)]
        #:when (eq? (relation-slot-lineage-kind lineage) 'preserved))
    (define old (base-output-at base
                                (relation-slot-lineage-old-output-slot lineage)))
    (define new (output-at candidate
                           (relation-slot-lineage-new-output-slot lineage)))
    (unless (and (equal? (program-output-relation old)
                         (program-output-relation new))
                 (equal? (program-output-value old)
                         (program-output-value new)))
      (change-fail "relation marked preserved changed name or shape: ~s"
                   (relation-slot-lineage-old-version-key lineage)))))

(define (computed-refusals draft relations)
  (define base (program-draft-base-image draft))
  (define candidate (program-draft-candidate-image draft))
  (sorted-records
   (filter
    values
    (append
     (append*
      (for/list ([lineage (in-list relations)])
        (define old
          (and (relation-slot-lineage-old-output-slot lineage)
               (base-output-at
                base (relation-slot-lineage-old-output-slot lineage))))
        (define new
          (and (relation-slot-lineage-new-output-slot lineage)
               (output-at
                candidate (relation-slot-lineage-new-output-slot lineage))))
        (list
         (and old new
              (not (equal? (program-output-relation old)
                           (program-output-relation new)))
              (compiler-refusal
               'relation-rename-requires-migration
               `(old ,(program-output-relation old)
                     new ,(program-output-relation new))))
         (and old new
              (not (equal? (program-output-value old)
                           (program-output-value new)))
              (compiler-refusal
               'incompatible-declaration
               `(relation ,(program-output-relation old)
                          old ,(program-output-value old)
                          new ,(program-output-value new)))))))
     ;; An unchanged relation spelling can still name an alias whose members
     ;; changed.  RF5-A has no live TypeKeys or migration engine, so make that
     ;; incompatibility explicit rather than asking RF5-B to infer it.
     (for/list ([record (in-list
                         (nonrelation-declaration-records base candidate))]
                #:when
                (match record
                  [`(declaration-change (namespace ,_)
                                        (kind modified) ,_ ...)
                   #t]
                  [_ #f]))
       (match record
         [`(declaration-change (namespace ,namespace) (kind modified)
                               (old-name ,old-name) (new-name ,new-name)
                               ,_ ...)
          (compiler-refusal
           'incompatible-declaration
           `(namespace ,namespace old ,old-name new ,new-name))]))))))

(define (refusal->datum refusal)
  `(refusal (code ,(compiler-refusal-code refusal))
            (details ,(compiler-refusal-details refusal))))

(define (seal-program-draft draft #:refusals [additional-refusals '()])
  (check-draft 'seal-program-draft draft)
  (unless (andmap compiler-refusal? additional-refusals)
    (raise-argument-error 'seal-program-draft
                          "(listof compiler-refusal?)"
                          additional-refusals))
  (define base (program-draft-base-image draft))
  (define candidate (program-draft-candidate-image draft))
  (validate-program-image! base)
  (validate-program-image! candidate)
  (define modules
    (sort (program-draft-module-lineage draft) string<?
          #:key (lambda (x) (datum-key (module-lineage->datum x)))))
  (define rules
    (sort (program-draft-rule-lineage draft) string<?
          #:key (lambda (x) (datum-key (rule-lineage->datum x)))))
  (define relations
    (sort (program-draft-relation-lineage draft) string<?
          #:key (lambda (x) (datum-key (relation-lineage->datum x)))))
  (check-total-lineage 'module modules
                       module-lineage-old-module-slot
                       module-lineage-new-module-slot
                       (length (program-image-modules base))
                       (length (program-image-modules candidate)))
  (check-total-lineage 'rule rules
                       rule-lineage-old-rule-slot rule-lineage-new-rule-slot
                       (length (program-image-rules base))
                       (length (program-image-rules candidate)))
  (check-total-lineage 'relation relations
                       relation-slot-lineage-old-output-slot
                       relation-slot-lineage-new-output-slot
                       (length (program-image-outputs base))
                       (length (program-image-outputs candidate)))
  (validate-preserved-lineage! draft modules rules relations)
  (define source-diff (make-source-diff draft modules rules))
  (define semantic-diff
    (make-semantic-diff draft relations source-diff))
  (define execution-diff (make-execution-diff base candidate))
  (define required-services
    (sorted-records
     (remove-duplicates
      (append (execution-plan-diff-services-added execution-diff)
              (let-values ([(ks bs services) (cohort-snapshots candidate)])
                services)))))
  (define refusals
    (sort (remove-duplicates
           (append (computed-refusals draft relations) additional-refusals))
          string<? #:key (lambda (x) (datum-key (refusal->datum x)))))
  (define provisional
    (program-change-set
     #f program-change-set-format-version
     (program-draft-base-program-instance draft)
     (program-image-key base) (program-image-key candidate)
     (program-draft-revision draft)
     (length (program-image-modules base))
     (length (program-image-modules candidate))
     (length (program-image-rules base))
     (length (program-image-rules candidate))
     (length (program-image-outputs base))
     (length (program-image-outputs candidate))
     (program-replacement (program-draft-base-program-instance draft) 0)
     modules rules relations
     source-diff semantic-diff execution-diff
     (program-image-compiler-key candidate)
     (program-image-plan-abi candidate)
     required-services refusals))
  (define sealed
    (struct-copy program-change-set provisional
                 [key (digest (program-change-set-content-datum provisional))]))
  (validate-program-change-set! sealed))

;; -------------------------------------------------------------------------
;; Frozen ProgramChangeSet wire codec.

(define (source-diff->datum diff)
  `(source-diff
    (occurrences ,@(source-occurrence-diff-occurrences diff))
    (sources ,@(source-occurrence-diff-sources diff))
    (rules ,@(source-occurrence-diff-rules diff))
    (facts ,@(source-occurrence-diff-facts diff))
    (options ,@(source-occurrence-diff-options diff))
    (homes ,@(source-occurrence-diff-homes diff))
    (bindings ,@(source-occurrence-diff-bindings diff))))

(define (semantic-diff->datum diff)
  `(semantic-diff
    (old-model-key ,(semantic-program-diff-old-model-key diff))
    (new-model-key ,(semantic-program-diff-new-model-key diff))
    (declarations ,@(semantic-program-diff-declarations diff))
    (rules ,@(semantic-program-diff-rules diff))
    (facts ,@(semantic-program-diff-facts diff))
    (bindings ,@(semantic-program-diff-bindings diff))
    (options ,@(semantic-program-diff-options diff))
    (edges-added ,@(semantic-program-diff-edges-added diff))
    (edges-removed ,@(semantic-program-diff-edges-removed diff))
    (old-writers ,@(semantic-program-diff-old-writers diff))
    (new-writers ,@(semantic-program-diff-new-writers diff))
    (old-components ,@(semantic-program-diff-old-components diff))
    (new-components ,@(semantic-program-diff-new-components diff))
    (old-component-edges ,@(semantic-program-diff-old-component-edges diff))
    (new-component-edges ,@(semantic-program-diff-new-component-edges diff))
    (affected-roots ,@(semantic-program-diff-affected-roots diff))
    (union-cone ,@(semantic-program-diff-union-cone diff))))

(define (execution-diff->datum diff)
  `(execution-diff
    (old-plan-abi ,(execution-plan-diff-old-plan-abi diff))
    (new-plan-abi ,(execution-plan-diff-new-plan-abi diff))
    (cohort-changes ,@(execution-plan-diff-cohort-changes diff))
    (old-kernels ,@(execution-plan-diff-old-kernels diff))
    (new-kernels ,@(execution-plan-diff-new-kernels diff))
    (kernel-changes ,@(execution-plan-diff-kernel-changes diff))
    (old-bindings ,@(execution-plan-diff-old-bindings diff))
    (new-bindings ,@(execution-plan-diff-new-bindings diff))
    (services-added ,@(execution-plan-diff-services-added diff))
    (services-removed ,@(execution-plan-diff-services-removed diff))
    (reusable-kernel-keys
     ,@(execution-plan-diff-reusable-kernel-keys diff))))

(define (program-change-set-content-datum change-set)
  `(program-change-set-content
    (format ,(program-change-set-format change-set))
    (base
     (program-instance ,(program-change-set-base-program-instance change-set))
     (image-key ,(program-change-set-base-image-key change-set))
     (modules ,(program-change-set-base-module-count change-set))
     (rules ,(program-change-set-base-rule-count change-set))
     (outputs ,(program-change-set-base-output-count change-set)))
    (candidate
     (program-slot 0)
     (image-key ,(program-change-set-candidate-image-key change-set))
     (modules ,(program-change-set-candidate-module-count change-set))
     (rules ,(program-change-set-candidate-rule-count change-set))
     (outputs ,(program-change-set-candidate-output-count change-set)))
    (draft-revision ,(program-change-set-draft-revision change-set))
    (program-lineage
     (replacement
      (old-program-instance
       ,(program-replacement-old-program-instance
         (program-change-set-program-lineage change-set)))
      (new-program-slot
       ,(program-replacement-new-program-slot
         (program-change-set-program-lineage change-set)))))
    (module-lineage
     ,@(map module-lineage->datum
            (program-change-set-module-lineage change-set)))
    (rule-lineage
     ,@(map rule-lineage->datum (program-change-set-rule-lineage change-set)))
    (relation-slot-lineage
     ,@(map relation-lineage->datum
            (program-change-set-relation-lineage change-set)))
    ,(source-diff->datum (program-change-set-source-diff change-set))
    ,(semantic-diff->datum (program-change-set-semantic-diff change-set))
    ,(execution-diff->datum (program-change-set-execution-diff change-set))
    (requirements
     (compiler-key ,(program-change-set-required-compiler-key change-set))
     (plan-abi ,(program-change-set-required-plan-abi change-set))
     (services ,@(program-change-set-required-services change-set)))
    (refusals
     ,@(map refusal->datum (program-change-set-refusals change-set)))))

(define (program-change-set->datum change-set)
  `(program-change-set
    (state sealed)
    (key ,(program-change-set-key change-set))
    ,@(cdr (program-change-set-content-datum change-set))))

(define (datum->module-lineage datum)
  (match datum
    [`(module (old-instance ,old-instance) (old-slot ,old-slot)
              (new-slot ,new-slot) (kind ,kind))
     (module-lineage old-instance old-slot new-slot kind)]
    [_ (change-fail "malformed module lineage: ~s" datum)]))

(define (datum->rule-lineage datum)
  (match datum
    [`(rule (old-key ,old-key) (old-slot ,old-slot)
            (new-slot ,new-slot) (kind ,kind))
     (rule-lineage old-key old-slot new-slot kind)]
    [_ (change-fail "malformed rule lineage: ~s" datum)]))

(define (datum->relation-lineage datum)
  (match datum
    [`(relation (old-version-key ,old-version-key)
                (old-output-slot ,old-output-slot)
                (old-relation ,old-relation)
                (new-output-slot ,new-output-slot)
                (new-relation ,new-relation) (kind ,kind))
     (relation-slot-lineage old-version-key old-output-slot old-relation
                            new-output-slot new-relation kind)]
    [_ (change-fail "malformed relation-slot lineage: ~s" datum)]))

(define (datum->source-diff datum)
  (match datum
    [`(source-diff (occurrences ,occurrences ...)
                   (sources ,sources ...) (rules ,rules ...)
                   (facts ,facts ...) (options ,options ...)
                   (homes ,homes ...) (bindings ,bindings ...))
     (source-occurrence-diff occurrences sources rules facts options homes
                             bindings)]
    [_ (change-fail "malformed source/occurrence diff")]))

(define (datum->semantic-diff datum)
  (match datum
    [`(semantic-diff
       (old-model-key ,old-model-key) (new-model-key ,new-model-key)
       (declarations ,declarations ...) (rules ,rules ...) (facts ,facts ...)
       (bindings ,bindings ...) (options ,options ...)
       (edges-added ,edges-added ...) (edges-removed ,edges-removed ...)
       (old-writers ,old-writers ...) (new-writers ,new-writers ...)
       (old-components ,old-components ...)
       (new-components ,new-components ...)
       (old-component-edges ,old-component-edges ...)
       (new-component-edges ,new-component-edges ...)
       (affected-roots ,affected-roots ...) (union-cone ,union-cone ...))
     (semantic-program-diff
      old-model-key new-model-key declarations rules facts bindings options
      edges-added edges-removed old-writers new-writers
      old-components new-components old-component-edges new-component-edges
      affected-roots union-cone)]
    [_ (change-fail "malformed semantic program diff")]))

(define (datum->execution-diff datum)
  (match datum
    [`(execution-diff
       (old-plan-abi ,old-plan-abi) (new-plan-abi ,new-plan-abi)
       (cohort-changes ,cohort-changes ...)
       (old-kernels ,old-kernels ...) (new-kernels ,new-kernels ...)
       (kernel-changes ,kernel-changes ...)
       (old-bindings ,old-bindings ...) (new-bindings ,new-bindings ...)
       (services-added ,services-added ...)
       (services-removed ,services-removed ...)
       (reusable-kernel-keys ,reusable-kernel-keys ...))
     (execution-plan-diff
      old-plan-abi new-plan-abi cohort-changes old-kernels new-kernels
      kernel-changes old-bindings new-bindings services-added services-removed
      reusable-kernel-keys)]
    [_ (change-fail "malformed execution-plan diff")]))

(define (datum->refusal datum)
  (match datum
    [`(refusal (code ,code) (details ,details))
     (compiler-refusal code details)]
    [_ (change-fail "malformed compiler refusal: ~s" datum)]))

(define (datum->program-change-set datum)
  (define change-set
    (match datum
      [`(program-change-set
         (state sealed) (key ,key) (format ,format-version)
         (base (program-instance ,base-program) (image-key ,base-image-key)
               (modules ,base-modules) (rules ,base-rules)
               (outputs ,base-outputs))
         (candidate (program-slot 0) (image-key ,candidate-image-key)
                    (modules ,candidate-modules) (rules ,candidate-rules)
                    (outputs ,candidate-outputs))
         (draft-revision ,draft-revision)
         (program-lineage
          (replacement (old-program-instance ,old-program)
                       (new-program-slot ,new-program-slot)))
         (module-lineage ,modules ...)
         (rule-lineage ,rules ...)
         (relation-slot-lineage ,relations ...)
         ,source-diff ,semantic-diff ,execution-diff
         (requirements (compiler-key ,compiler-key) (plan-abi ,plan-abi)
                       (services ,services ...))
         (refusals ,refusals ...))
       (program-change-set
        key format-version base-program base-image-key candidate-image-key
        draft-revision
        base-modules candidate-modules base-rules candidate-rules
        base-outputs candidate-outputs
        (program-replacement old-program new-program-slot)
        (map datum->module-lineage modules)
        (map datum->rule-lineage rules)
        (map datum->relation-lineage relations)
        (datum->source-diff source-diff)
        (datum->semantic-diff semantic-diff)
        (datum->execution-diff execution-diff)
        compiler-key plan-abi services (map datum->refusal refusals))]
      [_ (change-fail "not a sealed ProgramChangeSet datum")]))
  (validate-program-change-set! change-set))

(define (validate-lineage-shape! change-set)
  (define modules (program-change-set-module-lineage change-set))
  (define rules (program-change-set-rule-lineage change-set))
  (define relations (program-change-set-relation-lineage change-set))
  (check-total-lineage
   'module modules module-lineage-old-module-slot module-lineage-new-module-slot
   (program-change-set-base-module-count change-set)
   (program-change-set-candidate-module-count change-set))
  (check-total-lineage
   'rule rules rule-lineage-old-rule-slot rule-lineage-new-rule-slot
   (program-change-set-base-rule-count change-set)
   (program-change-set-candidate-rule-count change-set))
  (check-total-lineage
   'relation relations
   relation-slot-lineage-old-output-slot relation-slot-lineage-new-output-slot
   (program-change-set-base-output-count change-set)
   (program-change-set-candidate-output-count change-set))
  (define (unique-old-keys! who keys)
    (define present (filter values keys))
    (unless (= (length present) (length (remove-duplicates present)))
      (change-fail "~a lineage reuses an old identity" who)))
  (unique-old-keys! 'module
                    (map module-lineage-old-module-instance modules))
  (unique-old-keys! 'rule (map rule-lineage-old-rule-key rules))
  (unique-old-keys! 'relation
                    (map relation-slot-lineage-old-version-key relations))
  (for ([lineage (in-list modules)])
    (unless (memq (module-lineage-kind lineage)
                  '(preserved modified removed added))
      (change-fail "unknown module lineage kind"))
    (unless (case (module-lineage-kind lineage)
              [(preserved modified)
               (and (portable-key? (module-lineage-old-module-instance lineage))
                    (exact-nonnegative-integer?
                     (module-lineage-old-module-slot lineage))
                    (exact-nonnegative-integer?
                     (module-lineage-new-module-slot lineage)))]
              [(removed)
               (and (portable-key? (module-lineage-old-module-instance lineage))
                    (exact-nonnegative-integer?
                     (module-lineage-old-module-slot lineage))
                    (not (module-lineage-new-module-slot lineage)))]
              [(added)
               (and (not (module-lineage-old-module-instance lineage))
                    (not (module-lineage-old-module-slot lineage))
                    (exact-nonnegative-integer?
                     (module-lineage-new-module-slot lineage)))])
      (change-fail "module lineage fields disagree with kind")))
  (for ([lineage (in-list rules)])
    (unless (memq (rule-lineage-kind lineage)
                  '(preserved modified removed added))
      (change-fail "unknown rule lineage kind"))
    (unless (case (rule-lineage-kind lineage)
              [(preserved modified)
               (and (portable-key? (rule-lineage-old-rule-key lineage))
                    (exact-nonnegative-integer?
                     (rule-lineage-old-rule-slot lineage))
                    (exact-nonnegative-integer?
                     (rule-lineage-new-rule-slot lineage)))]
              [(removed)
               (and (portable-key? (rule-lineage-old-rule-key lineage))
                    (exact-nonnegative-integer?
                     (rule-lineage-old-rule-slot lineage))
                    (not (rule-lineage-new-rule-slot lineage)))]
              [(added)
               (and (not (rule-lineage-old-rule-key lineage))
                    (not (rule-lineage-old-rule-slot lineage))
                    (exact-nonnegative-integer?
                     (rule-lineage-new-rule-slot lineage)))])
      (change-fail "rule lineage fields disagree with kind")))
  (for ([lineage (in-list relations)])
    (unless (memq (relation-slot-lineage-kind lineage)
                  '(preserved modified removed added))
      (change-fail "unknown relation lineage kind"))
    (unless (case (relation-slot-lineage-kind lineage)
              [(preserved modified)
               (and (portable-key?
                     (relation-slot-lineage-old-version-key lineage))
                    (exact-nonnegative-integer?
                     (relation-slot-lineage-old-output-slot lineage))
                    (symbol? (relation-slot-lineage-old-relation lineage))
                    (exact-nonnegative-integer?
                     (relation-slot-lineage-new-output-slot lineage))
                    (symbol? (relation-slot-lineage-new-relation lineage)))]
              [(removed)
               (and (portable-key?
                     (relation-slot-lineage-old-version-key lineage))
                    (exact-nonnegative-integer?
                     (relation-slot-lineage-old-output-slot lineage))
                    (symbol? (relation-slot-lineage-old-relation lineage))
                    (not (relation-slot-lineage-new-output-slot lineage))
                    (not (relation-slot-lineage-new-relation lineage)))]
              [(added)
               (and (not (relation-slot-lineage-old-version-key lineage))
                    (not (relation-slot-lineage-old-output-slot lineage))
                    (not (relation-slot-lineage-old-relation lineage))
                    (exact-nonnegative-integer?
                     (relation-slot-lineage-new-output-slot lineage))
                    (symbol? (relation-slot-lineage-new-relation lineage)))])
      (change-fail "relation lineage fields disagree with kind"))))

(define (diff-record-lists change-set)
  (define source (program-change-set-source-diff change-set))
  (define semantic (program-change-set-semantic-diff change-set))
  (define execution (program-change-set-execution-diff change-set))
  (list
   (source-occurrence-diff-occurrences source)
   (source-occurrence-diff-sources source)
   (source-occurrence-diff-rules source)
   (source-occurrence-diff-facts source)
   (source-occurrence-diff-options source)
   (source-occurrence-diff-homes source)
   (source-occurrence-diff-bindings source)
   (semantic-program-diff-declarations semantic)
   (semantic-program-diff-rules semantic)
   (semantic-program-diff-facts semantic)
   (semantic-program-diff-bindings semantic)
   (semantic-program-diff-options semantic)
   (semantic-program-diff-edges-added semantic)
   (semantic-program-diff-edges-removed semantic)
   (semantic-program-diff-old-writers semantic)
   (semantic-program-diff-new-writers semantic)
   (semantic-program-diff-old-components semantic)
   (semantic-program-diff-new-components semantic)
   (semantic-program-diff-old-component-edges semantic)
   (semantic-program-diff-new-component-edges semantic)
   (execution-plan-diff-cohort-changes execution)
   (execution-plan-diff-old-kernels execution)
   (execution-plan-diff-new-kernels execution)
   (execution-plan-diff-kernel-changes execution)
   (execution-plan-diff-old-bindings execution)
   (execution-plan-diff-new-bindings execution)
   (execution-plan-diff-services-added execution)
   (execution-plan-diff-services-removed execution)
   (execution-plan-diff-reusable-kernel-keys execution)))

(define (optional predicate value)
  (or (not value) (predicate value)))

(define (edit-kind? value)
  (and (memq value '(preserved modified removed added)) #t))

(define (source-snapshot? value)
  (match value
    [`(source ,(? exact-nonnegative-integer?) ,(? string?)
              ,(? content-key?)) #t]
    [_ #f]))

(define (source-change-record? value)
  (match value
    [`(source-change ,(? edit-kind?)
                     (old-module ,(? (lambda (x)
                                      (optional exact-nonnegative-integer? x))))
                     (new-module ,(? (lambda (x)
                                      (optional exact-nonnegative-integer? x))))
                     (digest ,(? content-key?))
                     (old ,olds ...) (new ,news ...))
     (and (andmap source-snapshot? olds)
          (andmap source-snapshot? news)
          (or (pair? olds) (pair? news)))]
    [_ #f]))

(define (source-rule-change-record? value)
  (match value
    [`(rule-change ,(? edit-kind?)
                   (old-key ,(? (lambda (x) (optional portable-key? x))))
                   (old-slot ,(? (lambda (x)
                                   (optional exact-nonnegative-integer? x))))
                   (new-slot ,(? (lambda (x)
                                   (optional exact-nonnegative-integer? x))))
                   (old-fingerprint ,(? (lambda (x) (optional content-key? x))))
                   (new-fingerprint ,(? (lambda (x) (optional content-key? x))))
                   (old-origin ,old-origin) (new-origin ,new-origin))
     (and (closed-datum? old-origin) (closed-datum? new-origin))]
    [_ #f]))

(define (module-field-change-record? tag value)
  (match value
    [`(,(== tag)
       (old-module ,(? (lambda (x)
                        (optional exact-nonnegative-integer? x))))
       (new-module ,(? (lambda (x)
                        (optional exact-nonnegative-integer? x))))
       (old ,old) (new ,new))
     (and (closed-datum? old) (closed-datum? new))]
    [_ #f]))

(define (declaration-change-record? value)
  (match value
    [`(declaration-change
       (namespace ,namespace) (kind ,kind)
       (old-name ,(? (lambda (x) (optional symbol? x))))
       (new-name ,(? (lambda (x) (optional symbol? x))))
       (old-slot ,(? (lambda (x) (optional exact-nonnegative-integer? x))))
       (new-slot ,(? (lambda (x) (optional exact-nonnegative-integer? x))))
       (compatibility ,compatibility)
       (old-value ,old-value) (new-value ,new-value))
     (and (memq namespace '(alias relation function))
          (edit-kind? kind)
          (memq compatibility
                '(compatible incompatible preserved added retired))
          (closed-datum? old-value) (closed-datum? new-value))]
    [_ #f]))

(define (semantic-rule-change-record? value)
  (match value
    [`(semantic-rule-change
       (fingerprint ,(? content-key?)) (normalized ,(? string?))
       (old-count ,(? exact-nonnegative-integer? old-count))
       (new-count ,(? exact-nonnegative-integer? new-count)))
     (not (= old-count new-count))]
    [_ #f]))

(define (dependency-change-record? value)
  (match value
    [`(dependency-change
       (from ,(? symbol?)) (to ,(? symbol?)) (kind ,kind)
       (old-count ,(? exact-nonnegative-integer? old-count))
       (new-count ,(? exact-nonnegative-integer? new-count)))
     (and (memq kind '(positive negative negative-wildcard co-head
                       derived oracle))
          (not (= old-count new-count)))]
    [_ #f]))

(define (writer-set-record? value)
  (match value
    [`(writer-set (relation ,(? symbol?)) (writers ,writers ...))
     (andmap
      (lambda (writer)
        (match writer
          [`(writer ,(? content-key?) ,(? exact-positive-integer?)) #t]
          [_ #f]))
      writers)]
    [_ #f]))

(define (component-record? value)
  (match value
    [`(component (members ,members ...)
                 (level ,(? exact-nonnegative-integer?)))
     (and (pair? members)
          (andmap symbol? members)
          (equal? members (symbols members)))]
    [_ #f]))

(define (component-edge-record? value)
  (match value
    [`(component-edge (from ,from ...) (to ,to ...) (kinds ,kinds ...))
     (and (pair? from) (pair? to) (pair? kinds)
          (equal? from (symbols from))
          (equal? to (symbols to))
          (equal? kinds (symbols kinds))
          (andmap (lambda (kind)
                    (memq kind '(positive negative negative-wildcard co-head
                                derived oracle)))
                  kinds))]
    [_ #f]))

(define (multiplicity-change-record? tag value-tag value value-predicate)
  (match value
    [`(,(== tag) (,(== value-tag) ,payload)
                 (old-count ,(? exact-nonnegative-integer? old-count))
                 (new-count ,(? exact-nonnegative-integer? new-count)))
     (and (value-predicate payload) (not (= old-count new-count)))]
    [_ #f]))

(define (kernel-record? value)
  (match value
    [`(kernel
       (cohort ,(? exact-nonnegative-integer?))
       (ordinal ,(? exact-nonnegative-integer?)) (flavor ,flavor)
       (key ,(? content-key?)) (members ,members ...)
       (prelude ,prelude?) (rules ,(? exact-nonnegative-integer?)))
     (and (memq flavor '(normal delta count maint1 maint3neg maint4neg))
          (boolean? prelude?)
          (andmap symbol? members)
          (equal? members (symbols members))
          (if prelude? (null? members) (pair? members)))]
    [_ #f]))

(define (binding-frame-record? value)
  (match value
    [`(binding-frame
       (kernel-key ,(? content-key?))
       (cohort ,(? exact-nonnegative-integer?))
       (ordinal ,(? exact-nonnegative-integer?)) (slots ,slots ...))
     (andmap (lambda (slot)
               (match slot
                 [`(slot ,(? exact-nonnegative-integer?) ,(? symbol?)) #t]
                 [_ #f]))
             slots)]
    [_ #f]))

(define (service-record? value)
  (match value
    [`(oracle ,(? symbol?) ,(? symbol?) ,(? symbol?)) #t]
    [`(seqindex ,(? symbol?) ,(? exact-nonnegative-integer?) ...) #t]
    [_ #f]))

(define (reusable-kernel-record? value)
  (match value
    [`(kernel-key ,(? content-key?)
                  (reusable-count ,(? exact-positive-integer?))) #t]
    [_ #f]))

(define (validate-diff-schema! change-set)
  (define source (program-change-set-source-diff change-set))
  (define semantic (program-change-set-semantic-diff change-set))
  (define execution (program-change-set-execution-diff change-set))
  (unless (and
           (equal? (source-occurrence-diff-occurrences source)
                   (map module-lineage->datum
                        (program-change-set-module-lineage change-set)))
           (andmap source-change-record?
                   (source-occurrence-diff-sources source))
           (andmap source-rule-change-record?
                   (source-occurrence-diff-rules source))
           (andmap source-rule-change-record?
                   (source-occurrence-diff-facts source))
           ;; Format 1 reserves this section but defines no semantic option
           ;; vocabulary.  Accepting an arbitrary option-change-shaped list
           ;; would turn a reserved field into an unversioned extension seam.
           (null? (source-occurrence-diff-options source))
           (andmap (lambda (x)
                     (module-field-change-record? 'home-change x))
                   (source-occurrence-diff-homes source))
           (andmap (lambda (x)
                     (module-field-change-record? 'binding-change x))
                   (source-occurrence-diff-bindings source)))
    (change-fail "malformed source/occurrence diff record"))
  (unless (and
           (andmap declaration-change-record?
                   (semantic-program-diff-declarations semantic))
           (andmap semantic-rule-change-record?
                   (semantic-program-diff-rules semantic))
           (andmap semantic-rule-change-record?
                   (semantic-program-diff-facts semantic))
           (equal? (semantic-program-diff-bindings semantic)
                   (source-occurrence-diff-bindings source))
           (equal? (semantic-program-diff-options semantic)
                   (source-occurrence-diff-options source))
           (andmap dependency-change-record?
                   (semantic-program-diff-edges-added semantic))
           (andmap dependency-change-record?
                   (semantic-program-diff-edges-removed semantic))
           (andmap writer-set-record?
                   (semantic-program-diff-old-writers semantic))
           (andmap writer-set-record?
                   (semantic-program-diff-new-writers semantic))
           (andmap component-record?
                   (semantic-program-diff-old-components semantic))
           (andmap component-record?
                   (semantic-program-diff-new-components semantic))
           (andmap component-edge-record?
                   (semantic-program-diff-old-component-edges semantic))
           (andmap component-edge-record?
                   (semantic-program-diff-new-component-edges semantic))
           (subset? (list->set (semantic-program-diff-affected-roots semantic))
                    (list->set (semantic-program-diff-union-cone semantic))))
    (change-fail "malformed semantic program diff record"))
  (unless (and
           (andmap (lambda (x)
                     (multiplicity-change-record?
                      'cohort-change 'digest x content-key?))
                   (execution-plan-diff-cohort-changes execution))
           (andmap kernel-record? (execution-plan-diff-old-kernels execution))
           (andmap kernel-record? (execution-plan-diff-new-kernels execution))
           (andmap (lambda (x)
                     (multiplicity-change-record?
                      'kernel-change 'key x content-key?))
                   (execution-plan-diff-kernel-changes execution))
           (andmap binding-frame-record?
                   (execution-plan-diff-old-bindings execution))
           (andmap binding-frame-record?
                   (execution-plan-diff-new-bindings execution))
           (andmap service-record?
                   (execution-plan-diff-services-added execution))
           (andmap service-record?
                   (execution-plan-diff-services-removed execution))
           (andmap reusable-kernel-record?
                   (execution-plan-diff-reusable-kernel-keys execution))
           (andmap service-record?
                   (program-change-set-required-services change-set)))
    (change-fail "malformed execution plan diff record")))

(define (validate-program-change-set! change-set)
  (unless (program-change-set? change-set)
    (raise-argument-error 'validate-program-change-set!
                          "program-change-set?" change-set))
  (unless (= (program-change-set-format change-set)
             program-change-set-format-version)
    (change-fail "unsupported ProgramChangeSet format ~s"
                 (program-change-set-format change-set)))
  (unless (and (content-key? (program-change-set-base-image-key change-set))
               (content-key? (program-change-set-candidate-image-key change-set))
               (portable-key?
                (program-change-set-base-program-instance change-set))
               (non-empty-string?
                (program-change-set-required-compiler-key change-set)))
    (change-fail "malformed ProgramChangeSet identity"))
  (for ([count (in-list
                (list (program-change-set-base-module-count change-set)
                      (program-change-set-candidate-module-count change-set)
                      (program-change-set-base-rule-count change-set)
                      (program-change-set-candidate-rule-count change-set)
                      (program-change-set-base-output-count change-set)
                      (program-change-set-candidate-output-count change-set)
                      (program-change-set-draft-revision change-set)))])
    (unless (exact-nonnegative-integer? count)
      (change-fail "negative or non-integral ProgramChangeSet count")))
  (unless (and (= (program-replacement-new-program-slot
                   (program-change-set-program-lineage change-set)) 0)
               (equal? (program-replacement-old-program-instance
                        (program-change-set-program-lineage change-set))
                       (program-change-set-base-program-instance change-set)))
    (change-fail "program replacement lineage disagrees with base/candidate"))
  (validate-lineage-shape! change-set)
  (unless (and
           (equal? (map module-lineage->datum
                        (program-change-set-module-lineage change-set))
                   (sorted-records
                    (map module-lineage->datum
                         (program-change-set-module-lineage change-set))))
           (equal? (map rule-lineage->datum
                        (program-change-set-rule-lineage change-set))
                   (sorted-records
                    (map rule-lineage->datum
                         (program-change-set-rule-lineage change-set))))
           (equal? (map relation-lineage->datum
                        (program-change-set-relation-lineage change-set))
                   (sorted-records
                    (map relation-lineage->datum
                         (program-change-set-relation-lineage change-set)))))
    (change-fail "lineage records are not in canonical order"))
  (unless (andmap canonical-record-list? (diff-record-lists change-set))
    (change-fail "diff records are not unique and canonically ordered"))
  (unless (andmap (lambda (records) (andmap closed-datum? records))
                  (diff-record-lists change-set))
    (change-fail "diff contains a non-canonical wire value"))
  (validate-diff-schema! change-set)
  (unless (and (equal? (semantic-program-diff-affected-roots
                        (program-change-set-semantic-diff change-set))
                       (symbols
                        (semantic-program-diff-affected-roots
                         (program-change-set-semantic-diff change-set))))
               (equal? (semantic-program-diff-union-cone
                        (program-change-set-semantic-diff change-set))
                       (symbols
                        (semantic-program-diff-union-cone
                         (program-change-set-semantic-diff change-set)))))
    (change-fail "affected roots or union cone are not canonical"))
  (unless (= (program-change-set-required-plan-abi change-set)
             (execution-plan-diff-new-plan-abi
              (program-change-set-execution-diff change-set)))
    (change-fail "required Plan ABI disagrees with execution diff"))
  (unless (and (= (execution-plan-diff-old-plan-abi
                   (program-change-set-execution-diff change-set)) 2)
               (= (execution-plan-diff-new-plan-abi
                   (program-change-set-execution-diff change-set)) 2)
               (content-key?
                (semantic-program-diff-old-model-key
                 (program-change-set-semantic-diff change-set)))
               (content-key?
                (semantic-program-diff-new-model-key
                 (program-change-set-semantic-diff change-set))))
    (change-fail "unsupported Plan ABI or malformed ProgramModel key"))
  (unless (andmap compiler-refusal? (program-change-set-refusals change-set))
    (change-fail "malformed compiler refusal list"))
  (unless (and (canonical-record-list?
                (program-change-set-required-services change-set))
               (andmap closed-datum?
                       (program-change-set-required-services change-set))
               (equal? (map refusal->datum
                            (program-change-set-refusals change-set))
                       (sorted-records
                        (map refusal->datum
                             (program-change-set-refusals change-set))))
               (= (length (program-change-set-refusals change-set))
                  (length (remove-duplicates
                           (program-change-set-refusals change-set))))
               (andmap (lambda (refusal)
                         (and (symbol? (compiler-refusal-code refusal))
                              (closed-datum?
                               (compiler-refusal-details refusal))))
                       (program-change-set-refusals change-set)))
    (change-fail "requirements or refusals are not canonically ordered"))
  (unless (equal? (program-change-set-key change-set)
                  (digest (program-change-set-content-datum change-set)))
    (change-fail "ProgramChangeSet key does not match sealed content"))
  change-set)

(define (program-change-set->string change-set)
  (with-output-to-string
    (lambda () (pretty-write (program-change-set->datum change-set)))))

(define (write-program-change-set change-set [out (current-output-port)])
  (validate-program-change-set! change-set)
  (pretty-write (program-change-set->datum change-set) out))

(define (read-program-change-set [in (current-input-port)])
  (define datum
    (read-bounded-datum in max-program-change-bytes "ProgramChangeSet"))
  (check-datum-budget! datum "ProgramChangeSet"
                       max-program-change-nodes max-program-change-depth)
  (datum->program-change-set datum))
