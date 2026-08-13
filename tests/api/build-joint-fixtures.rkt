#lang racket

;; The joint battery's producer leg (docs/activation-contract.md §6): build
;; each joint case's base and candidate images with the ORDINARY compiler
;; pipeline, construct the total-coverage draft, seal the ProgramChangeSet,
;; and emit the frozen `.pcs` fixture through compiler/change-pcs.rkt.
;;
;;   racket tests/api/build-joint-fixtures.rkt OUTPUT-DIR
;;
;; Writes OUTPUT-DIR/joint-{minimal,minimal-live,two-instance,refusal}.pcs
;; and prints one `(built CASE (refusals N))` line per case.  The compiler
;; identity is pinned ("compiler-test") so unrelated compiler edits do not
;; churn the emitted fixtures -- the same choice build-rf5a-fixture.rkt
;; made for the RF5-A goldens.

(provide build-joint-fixtures!)

(require racket/file
         racket/list
         racket/runtime-path
         racket/set
         "../../compiler/compile.rkt"
         "../../compiler/modules.rkt"
         "../../compiler/program-change.rkt"
         "../../compiler/program-image.rkt"
         "../../compiler/change-pcs.rkt")

(define-runtime-path repo-root "../..")
(define-runtime-path joint-dir "../reflect/joint")

(define (compile-image source-path)
  (parameterize ([current-directory repo-root])
    (define program
      (first (load-program-list (path->string source-path) (hash))))
    (define jobs (first (program->jobs program)))
    (define output-dir (make-temporary-file "joint-image-~a" 'directory))
    (dynamic-wind
      void
      (lambda ()
        (define-values (image _path)
          (emit-program-image program jobs output-dir
                              #:compiler-key "compiler-test"))
        image)
      (lambda () (delete-directory/files output-dir)))))

;; ---------------------------------------------------------------------------
;; Generic total-coverage draft construction.  Modules pair by lexical path
;; and are preserved exactly when the seal validator's occurrence shape --
;; home, lexical path, bindings, and source digests -- is unchanged; any
;; textual change (including the candidate main naming a v2 library) makes
;; the occurrence an explicit replacement, never an inference.  Rules pair
;; globally by normalized form, relations by qualified name: the same
;; explicit-coverage discipline as the RF5-A golden builder.
;; ---------------------------------------------------------------------------

(define (module-shape image m)
  (list (image-module-home m)
        (image-module-lexical-path m)
        (image-module-bindings m)
        (for/list ([slot (in-list (image-module-sources m))])
          (image-source-digest (program-image-source-at image slot)))))

(define (map-modules draft base candidate)
  (define candidate-by-path
    (for/hash ([m (in-list (program-image-modules candidate))])
      (values (image-module-lexical-path m) m)))
  (for/fold ([current draft])
            ([old (in-list (program-image-modules base))])
    (define new
      (hash-ref candidate-by-path (image-module-lexical-path old)
                (lambda ()
                  (error 'build-joint-fixtures
                         "no candidate occurrence at path ~a"
                         (image-module-lexical-path old)))))
    (define handle
      (make-module-handle "program.old"
                          (format "module.~a" (image-module-slot old))
                          base (image-module-slot old)))
    (if (equal? (module-shape base old) (module-shape candidate new))
        (program-draft-preserve-module current handle (image-module-slot new))
        (program-draft-replace-module current handle (image-module-slot new)))))

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

;; ---------------------------------------------------------------------------
;; Cases.
;; ---------------------------------------------------------------------------

(define (joint-path name) (build-path joint-dir name))

(define (build-case base-name candidate-name source-names)
  (define base (compile-image (joint-path base-name)))
  (define candidate (compile-image (joint-path candidate-name)))
  (define draft
    (map-relations
     (map-rules
      (map-modules (make-program-draft "program.old" base candidate)
                   base candidate)
      base candidate)
     base candidate))
  (define change-set (seal-program-draft draft))
  (define sources
    (for/list ([name (in-list source-names)])
      (cons name (file->string (joint-path name)))))
  (values change-set
          (program-change-set->pcs change-set base candidate
                                   #:sources sources)))

(define cases
  ;; name, base source, candidate source, candidate source closure
  (list (list "joint-minimal"
              "joint-minimal-base.slog" "joint-minimal-candidate.slog"
              '("joint-minimal-candidate.slog"))
        (list "joint-minimal-live"
              "joint-live-base.slog" "joint-live-candidate.slog"
              '("joint-live-candidate.slog"))
        (list "joint-two-instance"
              "joint-two-instance-base.slog"
              "joint-two-instance-candidate.slog"
              '("joint-two-instance-candidate.slog"
                "joint-graph-lib.slog" "joint-graph-lib-v2.slog"))
        (list "joint-refusal"
              "joint-minimal-base.slog" "joint-refusal-candidate.slog"
              '("joint-refusal-candidate.slog"))))

(define (build-joint-fixtures! output-dir)
  (make-directory* output-dir)
  (for ([case-spec (in-list cases)])
    (match-define (list name base-name candidate-name source-names) case-spec)
    (define-values (change-set pcs)
      (build-case base-name candidate-name source-names))
    (call-with-output-file (build-path output-dir (format "~a.pcs" name))
      #:exists 'truncate
      (lambda (out) (display (pcs->string pcs) out)))
    (printf "(built ~a (refusals ~a))\n"
            name (length (program-change-set-refusals change-set)))))

(module+ main
  (match (vector->list (current-command-line-arguments))
    [(list output-dir) (build-joint-fixtures! output-dir)]
    [_ (error 'build-joint-fixtures "usage: build-joint-fixtures.rkt OUTPUT-DIR")]))
