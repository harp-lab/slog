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
         "../../compiler/program-image.rkt"
         ;; map-rules / map-relations are shared with the joint producer
         (only-in "../../compiler/change-pcs.rkt" map-rules map-relations))

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

;; the rf5a fixture keeps its OWN map-modules: it maps module 0 by SLOT with
;; an explicit replace and the instance name "module.root", whose spelling is
;; in the frozen golden bytes -- auto-program-draft's path-paired "module.0"
;; would churn the content-sealed key.  map-rules / map-relations are the
;; shared ones (compiler/change-pcs.rkt), byte-identical logic.
(define (map-modules draft base candidate)
  (unless (and (= (length (program-image-modules base)) 1)
               (= (length (program-image-modules candidate)) 1))
    (error 'make-rf5a-fixture "fixture sources must each have one module"))
  (program-draft-replace-module
   draft (make-module-handle "program.old" "module.root" base 0) 0))

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
