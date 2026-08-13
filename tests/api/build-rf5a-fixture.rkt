#lang racket

;; Reproducible RF5-A handoff fixture.  Both images and every ABI-2 cohort are
;; produced by the ordinary compiler pipeline; only the compiler identity is
;; pinned so unrelated source edits do not churn this boundary golden.

(provide make-rf5a-fixture record-rf5a-fixture!)

(require racket/file
         racket/list
         racket/runtime-path
         racket/set
         "../../compiler/compile.rkt"
         "../../compiler/modules.rkt"
         "../../compiler/program-change.rkt"
         "../../compiler/program-image.rkt")

(define-runtime-path repo-root "../..")
(define-runtime-path base-source "../reflect/rf5a-base.slog")
(define-runtime-path candidate-source "../reflect/rf5a-candidate.slog")
(define-runtime-path base-output "../change-expected/rf5a-base.pimg")
(define-runtime-path candidate-output
  "../change-expected/rf5a-candidate.pimg")
(define-runtime-path change-output
  "../change-expected/rf5a-rule-removal.pchange")

(define (compile-image source)
  (parameterize ([current-directory repo-root])
    (define program
      (first (load-program-list (path->string source) (hash))))
    (define jobs (first (program->jobs program)))
    (define output-dir (make-temporary-file "rf5a-image-~a" 'directory))
    (dynamic-wind
      void
      (lambda ()
        (define-values (image _path)
          (emit-program-image program jobs output-dir
                              #:compiler-key "compiler-test"))
        image)
      (lambda () (delete-directory/files output-dir)))))

(define (map-modules draft base candidate)
  (unless (and (= (length (program-image-modules base)) 1)
               (= (length (program-image-modules candidate)) 1))
    (error 'make-rf5a-fixture "fixture sources must each have one module"))
  (program-draft-replace-module
   draft (make-module-handle "program.old" "module.root" base 0) 0))

(define (map-rules draft base candidate)
  (define used-new (mutable-set))
  (define after-old
    (for/fold ([current draft])
              ([old (in-list (program-image-rules base))])
      (define new
        (for/first ([candidate-rule (in-list (program-image-rules candidate))]
                    #:unless (set-member? used-new
                                          (image-rule-slot candidate-rule))
                    #:when (equal? (image-rule-normalized old)
                                   (image-rule-normalized candidate-rule)))
          candidate-rule))
      (define old-key (format "rule.~a" (image-rule-slot old)))
      (cond
        [new
         (set-add! used-new (image-rule-slot new))
         (program-draft-preserve-rule current old-key
                                      (image-rule-slot old)
                                      (image-rule-slot new))]
        [else
         (program-draft-remove-rule current old-key (image-rule-slot old))])))
  (for/fold ([current after-old])
            ([new (in-list (program-image-rules candidate))]
             #:unless (set-member? used-new (image-rule-slot new)))
    (program-draft-add-rule current (image-rule-slot new))))

(define (map-relations draft base candidate)
  (define candidate-by-name
    (for/hash ([output (in-list (program-image-outputs candidate))])
      (values (program-output-relation output) output)))
  (define used-new (mutable-set))
  (define after-old
    (for/fold ([current draft])
              ([old (in-list (program-image-outputs base))])
      (define new
        (hash-ref candidate-by-name (program-output-relation old) #f))
      (define version-key
        (format "version.~a" (program-output-slot old)))
      (cond
        [(not new)
         (program-draft-remove-relation current version-key
                                        (program-output-slot old))]
        [else
         (set-add! used-new (program-output-slot new))
         (if (equal? (program-output-value old) (program-output-value new))
             (program-draft-preserve-relation current version-key
                                              (program-output-slot old)
                                              (program-output-slot new))
             (program-draft-replace-relation current version-key
                                             (program-output-slot old)
                                             (program-output-slot new)))])))
  (for/fold ([current after-old])
            ([new (in-list (program-image-outputs candidate))]
             #:unless (set-member? used-new (program-output-slot new)))
    (program-draft-add-relation current (program-output-slot new))))

(define (make-rf5a-fixture)
  (define base (compile-image base-source))
  (define candidate (compile-image candidate-source))
  (define draft0 (make-program-draft "program.old" base candidate))
  (define draft1 (map-modules draft0 base candidate))
  (define draft2 (map-rules draft1 base candidate))
  (define draft3 (map-relations draft2 base candidate))
  (values base candidate draft0 draft3 (seal-program-draft draft3)))

(define (record-rf5a-fixture!)
  (define-values (base candidate _draft0 _draft change-set)
    (make-rf5a-fixture))
  (call-with-output-file base-output #:exists 'truncate
    (lambda (out) (write-program-image base out)))
  (call-with-output-file candidate-output #:exists 'truncate
    (lambda (out) (write-program-image candidate out)))
  (call-with-output-file change-output #:exists 'truncate
    (lambda (out) (write-program-change-set change-set out))))

(module+ main
  (record-rf5a-fixture!))
