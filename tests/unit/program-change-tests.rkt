#lang racket

;; RF5-A immutable draft, three-diff, explicit-lineage, and frozen handoff
;; battery.  The primary fixture is compiled from two real source programs:
;; one recursive rule is removed while an independent kernel remains reusable.

(module+ test
  (require rackunit
           racket/file
           racket/list
           racket/runtime-path
           racket/set
           "../../compiler/compile.rkt"
           "../../compiler/modules.rkt"
           "../../compiler/program-change.rkt"
           "../../compiler/program-image.rkt"
           "../../compiler/sha256.rkt"
           (rename-in "../api/build-rf5a-fixture.rkt"
                      [make-rf5a-fixture build-fixture])
           "../api/program-change-consumer.rkt")

  (define-runtime-path base-golden
    "../change-expected/rf5a-base.pimg")
  (define-runtime-path repo-root "../..")
  (define-runtime-path candidate-golden
    "../change-expected/rf5a-candidate.pimg")
  (define-runtime-path change-golden
    "../change-expected/rf5a-rule-removal.pchange")

  (define fixture (call-with-values build-fixture list))
  (define (make-fixture) (apply values fixture))

  (define (datum-digest datum)
    (bytes->hex-string
     (sha256 (string->bytes/utf-8
              (with-output-to-string (lambda () (write datum)))))))

  ;; Declaration-refusal tests alter only the sealed semantic inventory.  The
  ;; executable/model cross-seal remains intact, and validate-program-image!
  ;; is still the authority over the resulting test image.
  (define (reseal-image image)
    (define provisional (struct-copy program-image image [key #f]))
    (define wire (program-image->datum provisional))
    (define content `(program-image-content ,@(cdddr wire)))
    (validate-program-image!
     (struct-copy program-image provisional [key (datum-digest content)])))

  (define (output-named image name)
    (for/first ([output (in-list (program-image-outputs image))]
                #:when (eq? (program-output-relation output) name))
      output))

  (define (complete-same-lineage base candidate
                                 #:replace-relation [replacement #f])
    (define handle
      (make-module-handle "program.old" "module.root" base 0))
    (define draft
      (program-draft-preserve-module
       (make-program-draft "program.old" base candidate) handle 0))
    (define with-rules
      (for/fold ([current draft])
                ([old (in-list (program-image-rules base))])
        (program-draft-preserve-rule current
                                     (format "rule.~a" (image-rule-slot old))
                                     (image-rule-slot old)
                                     (image-rule-slot old))))
    (for/fold ([current with-rules])
              ([old (in-list (program-image-outputs base))])
      (define new (output-named candidate (program-output-relation old)))
      (define key (format "version.~a" (program-output-slot old)))
      (if (eq? (program-output-relation old) replacement)
          (program-draft-replace-relation current key
                                          (program-output-slot old)
                                          (program-output-slot new))
          (program-draft-preserve-relation current key
                                           (program-output-slot old)
                                           (program-output-slot new)))))

  (define (consume change-set base candidate)
    (consume-program-change-set (program-change-set->datum change-set)
                                (program-image->datum base)
                                (program-image->datum candidate)))

  (test-case "draft operations are persistent revisions and reject inferred reuse"
    (define-values (_base _candidate draft0 draft change-set) (make-fixture))
    (check-equal? (program-draft-revision draft0) 0)
    (check-equal? (program-draft-module-lineage draft0) '())
    (check-equal? (program-draft-revision draft) 21)
    (check-equal? (program-change-set-draft-revision change-set) 21)
    (check-exn #rx"reuses old slot"
               (lambda () (program-draft-add-rule draft 0))))

  (test-case "sealed preview carries independent source, semantic, and execution diffs"
    (define-values (base candidate _draft0 _draft change-set) (make-fixture))
    (check-not-equal? (program-image-key base) (program-image-key candidate))
    (define source (program-change-set-source-diff change-set))
    (define semantic (program-change-set-semantic-diff change-set))
    (define execution (program-change-set-execution-diff change-set))
    (check-equal? (length (source-occurrence-diff-occurrences source)) 1)
    (check-equal? (length (source-occurrence-diff-sources source)) 2)
    (check-equal? (length (source-occurrence-diff-rules source)) 3)
    (check-equal? (length (semantic-program-diff-rules semantic)) 1)
    (check-equal? (semantic-program-diff-facts semantic) '())
    (check-equal? (semantic-program-diff-affected-roots semantic) '(reach))
    (check-equal? (semantic-program-diff-union-cone semantic) '(reach))
    (check-equal? (length (execution-plan-diff-kernel-changes execution)) 2)
    (check-equal? (length
                   (execution-plan-diff-reusable-kernel-keys execution)) 1)
    (check-equal? (program-change-set-required-services change-set) '())
    (check-equal? (program-change-set-refusals change-set) '()))

  (test-case "remove/add operations preserve explicit non-correspondence"
    (define-values (base _candidate _draft0 _draft _change-set) (make-fixture))
    (define handle
      (make-module-handle "program.old" "module.root" base 0))
    (define d0 (make-program-draft "program.old" base base))
    (define d1 (program-draft-remove-module d0 handle))
    (define d2 (program-draft-add-module d1 0))
    (define d3
      (for/fold ([current d2])
                ([rule (in-list (program-image-rules base))])
        (program-draft-remove-rule current
                                   (format "rule.~a" (image-rule-slot rule))
                                   (image-rule-slot rule))))
    (define d4
      (for/fold ([current d3])
                ([rule (in-list (program-image-rules base))])
        (program-draft-add-rule current (image-rule-slot rule))))
    (define d5
      (for/fold ([current d4])
                ([output (in-list (program-image-outputs base))])
        (program-draft-remove-relation
         current (format "version.~a" (program-output-slot output))
         (program-output-slot output))))
    (define d6
      (for/fold ([current d5])
                ([output (in-list (program-image-outputs base))])
        (program-draft-add-relation current (program-output-slot output))))
    (define sealed (seal-program-draft d6))
    (check-equal? (program-draft-revision d6) 42)
    (check-equal?
     (sort (map module-lineage-kind
                (program-change-set-module-lineage sealed)) symbol<?)
     '(added removed))
    ;; Identical semantics do not become changed merely because the caller
    ;; declined occurrence continuity.
    (check-equal?
     (semantic-program-diff-rules
      (program-change-set-semantic-diff sealed))
     '()))

  (test-case "incompatible relation shape is a sealed compiler refusal"
    (define-values (base _candidate _draft0 _draft _change-set) (make-fixture))
    (define declarations
      (for/list ([declaration (in-list (program-image-declarations base))])
        (if (and (eq? (image-declaration-namespace declaration) 'relation)
                 (eq? (image-declaration-name declaration) 'reach))
            (struct-copy image-declaration declaration
                         [value '(table int int int)])
            declaration)))
    (define candidate
      (reseal-image
       (struct-copy program-image base [declarations declarations])))
    (define draft
      (complete-same-lineage base candidate #:replace-relation 'reach))
    (define sealed (seal-program-draft draft))
    (check-equal? (map compiler-refusal-code
                       (program-change-set-refusals sealed))
                  '(incompatible-declaration))
    (check-equal? (second (assoc 'status (cdr (consume sealed base candidate))))
                  'refused))

  (test-case "alias changes cannot bypass relation-shape compatibility"
    (define-values (base _candidate _draft0 _draft _change-set) (make-fixture))
    (define declarations
      (for/list ([declaration (in-list (program-image-declarations base))])
        (if (and (eq? (image-declaration-namespace declaration) 'alias)
                 (eq? (image-declaration-name declaration) 'coll))
            (struct-copy image-declaration declaration [value '(set cmap coll)])
            declaration)))
    (define candidate
      (reseal-image
       (struct-copy program-image base [declarations declarations])))
    (define sealed
      (seal-program-draft (complete-same-lineage base candidate)))
    (check-equal? (map compiler-refusal-code
                       (program-change-set-refusals sealed))
                  '(incompatible-declaration)))

  (test-case "source fact diff matches the compiler's constant-class closure"
    (parameterize ([current-directory repo-root])
      (define program
        (first (load-program-list "tests/deep_fact.slog" (hash))))
      (define pp (program->jobs program #:split-facts? #t))
      (define jobs (first pp))
      (define first-stratum (third (first jobs)))
      (define compiler-ground-count
        (match first-stratum
          [`(stratum 0 ,rules) (set-count rules)]))
      (define image
        (seal-program-image program (fourth pp) (fifth pp)
                            #:compiler-key "compiler-test"))
      (define sealed
        (seal-program-draft (complete-same-lineage image image)))
      (define source (program-change-set-source-diff sealed))
      ;; The nested ground tree is lowered through positive reads of
      ;; constant-class constructor relations; it must remain a fact.
      (check > compiler-ground-count 1)
      (check-equal? (length (source-occurrence-diff-facts source))
                    compiler-ground-count)
      (check-equal? (length (source-occurrence-diff-rules source))
                    (- (length (program-image-rules image))
                       compiler-ground-count))))

  (test-case "service attachment changes are semantic cone roots"
    (define-values (base _candidate _draft0 _draft _change-set) (make-fixture))
    (define service-plan
      '(kernel-cohort
        (abi 2) (flavor normal)
        (attachments (seqindex edge 0))
        (declarations) (dynamic) (manifest)))
    (define service-cohort
      (image-cohort (length (program-image-cohorts base))
                    (datum-digest service-plan) service-plan))
    (define candidate
      (reseal-image
       (struct-copy program-image base
                    [cohorts (append (program-image-cohorts base)
                                     (list service-cohort))])))
    (define sealed
      (seal-program-draft (complete-same-lineage base candidate)))
    (define semantic (program-change-set-semantic-diff sealed))
    (check-equal? (semantic-program-diff-affected-roots semantic) '(edge))
    (check-equal? (semantic-program-diff-union-cone semantic) '(edge reach))
    (check-equal? (program-change-set-required-services sealed)
                  '((seqindex edge 0))))

  (test-case "explicit lineage is total and never manufactured from names"
    (define-values (base _candidate _draft0 _draft _change-set) (make-fixture))
    (define incomplete (make-program-draft "program.old" base base))
    (check-exn #rx"module lineage does not exactly cover"
               (lambda () (seal-program-draft incomplete)))
    (define wrong-program-handle
      (make-module-handle "another.program" "module.root" base 0))
    (check-exn #rx"another program/image"
               (lambda ()
                 (program-draft-preserve-module
                  incomplete wrong-program-handle 0))))

  (test-case "wire round trip, bounded decoding, tamper rejection, and no RF5-B decisions"
    (define-values (_base _candidate _draft0 _draft change-set) (make-fixture))
    (define text (program-change-set->string change-set))
    (define decoded (read-program-change-set (open-input-string text)))
    (check-equal? decoded change-set)
    (check-equal? (program-change-set->string decoded) text)
    (check-false (regexp-match? #rx"VersionId|maintenance-route|publication"
                                text))
    (check-exn #rx"key does not match"
               (lambda ()
                 (validate-program-change-set!
                  (struct-copy program-change-set change-set
                               [key (make-string 64 #\0)]))))
    (define malformed-semantic
      (struct-copy semantic-program-diff
                   (program-change-set-semantic-diff change-set)
                   [declarations '((bogus-record))]))
    (check-exn #rx"malformed semantic program diff"
               (lambda ()
                 (validate-program-change-set!
                  (struct-copy program-change-set change-set
                               [semantic-diff malformed-semantic]))))
    (define source-with-option
      (struct-copy source-occurrence-diff
                   (program-change-set-source-diff change-set)
                   [options '((option-change future #t))]))
    (define semantic-with-option
      (struct-copy semantic-program-diff
                   (program-change-set-semantic-diff change-set)
                   [options '((option-change future #t))]))
    (check-exn #rx"no semantic option vocabulary|malformed source"
               (lambda ()
                 (validate-program-change-set!
                  (struct-copy program-change-set change-set
                               [source-diff source-with-option]
                               [semantic-diff semantic-with-option]))))
    (check-exn #rx"trailing data"
               (lambda ()
                 (read-program-change-set
                  (open-input-string (string-append text "junk\n")))))
    (define nested
      (string-append (make-string 514 #\() "x" (make-string 514 #\))))
    (check-exn #rx"level decoder limit"
               (lambda ()
                 (read-program-change-set (open-input-string nested))))
    (check-exn #rx"level decoder limit"
               (lambda ()
                 (read-consumer-datum (open-input-string nested)))))

  (test-case "independent RF5-B consumer accepts the frozen compiler handoff"
    (define change-datum
      (call-with-input-file change-golden read-consumer-datum))
    (define base-datum
      (call-with-input-file base-golden read-consumer-datum))
    (define candidate-datum
      (call-with-input-file candidate-golden read-consumer-datum))
    (define summary
      (consume-program-change-set change-datum base-datum candidate-datum))
    (check-equal? (second (assoc 'status (cdr summary))) 'ready)
    (check-equal? (cdr (assoc 'affected-roots (cdr summary))) '(reach))
    (check-equal? (cdr (assoc 'union-cone (cdr summary))) '(reach))
    (check-exn #rx"both sealed ProgramImages"
               (lambda () (consume-program-change-set change-datum))))

  (test-case "compiler-produced images and complete change set match goldens"
    (define-values (base candidate _draft0 _draft change-set) (make-fixture))
    (check-equal? (program-image->string base) (file->string base-golden))
    (check-equal? (program-image->string candidate)
                  (file->string candidate-golden))
    (check-equal? (program-change-set->string change-set)
                  (file->string change-golden))))
