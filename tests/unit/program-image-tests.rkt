#lang racket

;; RF2-A sealed ProgramImage container tests.  The fixture stays deliberately
;; small: this battery pins the wire/container contract; real ABI-2 cohorts
;; retain their own exhaustive RF0/T4 round-trip gates.

(module+ test
  (require rackunit
           racket/file
           racket/runtime-path
           "../../compiler/compile.rkt"
           "../../compiler/ir-shared.rkt"
           "../../compiler/modules.rkt"
           "../../compiler/program-image.rkt"
           "../../compiler/program-model.rkt"
           "../../compiler/stratify.rkt")

  (define-runtime-path repo-root "../..")
  (define-runtime-path golden "../image-expected/rf2-basic.pimg")

  (define source-path
    (path->string (build-path repo-root "tests" "reflect" "rf2-basic.slog")))
  (define P `(prov (token id (pos ,source-path 0 0 0 1) "") #f))
  (define (S . parts) `(syn ,P ,@parts))
  (define (rule line body heads)
    `(syn (prov (token id (pos ,source-path ,line 0 ,line 1) "") #f)
          rule ,@body --> ,@heads))

  (define edge->reach
    (rule 4 (list (S 'edge 'x 'y)) (list (S 'reach 'x 'y))))
  (define reach-step
    (rule 5 (list (S 'reach 'x 'y) (S 'edge 'y 'z))
          (list (S 'reach 'x 'z))))
  (define rules (set edge->reach reach-step))
  (define tokens
    `((token id (pos ,source-path 0 0 0 5) "table")
      (token newline (pos ,source-path 0 5 0 6) "\n")
      (token eof (pos ,source-path 6 0 6 0) "")))
  (define type-env
    (list (hash 'scalar (set 'int 'str))
          (hash 'edge '(table int int)
                'reach '(table int int))
          (hash 'plus '(int int int))))
  (define module
    (module-ir source-path tokens rules '() '()))
  (define occurrence
    (module-occurrence source-path '() '() '() (list source-path) '()))
  (define program
    (program-ir type-env (set module) (hash) (hash) occurrence))
  (define-values (_strata model) (stratify-rules/model rules))
  (define empty-cohort
    '(kernel-cohort
      (abi 2) (flavor normal) (attachments) (declarations) (dynamic)
      (manifest)))

  (define (make-image)
    (seal-program-image
     program type-env model
     #:compiler-key "compiler-test"
     #:cohorts (list empty-cohort)
     #:source-root repo-root))

  (test-case "sealed image is deterministic, queryable, and path-normalized"
    (define image (make-image))
    (check-equal? (string-length (program-image-key image)) 64)
    (check-equal? (program-image-key image)
                  (program-image-key (make-image)))
    (check-equal? (map image-rule-slot
                       (program-image-rules-writing image 'reach))
                  '(0 1))
    (check-equal?
     (image-component-members
      (program-image-component-for-relation image 'reach))
     '(reach))
    (check-equal? (image-source-path (program-image-source-at image 0))
                  "tests/reflect/rf2-basic.slog")
    (check-false (string-contains? (program-image->string image) "/tmp/slog")))

  (test-case "wire round trip returns the same sealed value"
    (define image (make-image))
    (define encoded (program-image->string image))
    (define decoded (read-program-image (open-input-string encoded)))
    (check-equal? decoded image)
    (check-equal? (program-image->string decoded) encoded))

  (test-case "sealed key and version checks reject tampering"
    (define image (make-image))
    (check-exn #rx"image key does not match"
               (lambda ()
                 (validate-program-image!
                  (struct-copy program-image image
                               [key (make-string 64 #\0)]))))
    (check-exn #rx"unsupported format version"
               (lambda ()
                 (validate-program-image!
                  (struct-copy program-image image [format 99])))))

  (test-case "wire reader rejects trailing data"
    (define encoded (string-append (program-image->string (make-image)) "junk\n"))
    (check-exn #rx"trailing data" (lambda ()
                                     (read-program-image
                                      (open-input-string encoded)))))

  (test-case "wire reader rejects excessive structural depth before decoding"
    (define nested
      (string-append (make-string 514 #\() "x" (make-string 514 #\))))
    (check-exn #rx"level decoder limit"
               (lambda ()
                 (read-program-image (open-input-string nested)))))

  (test-case "complete textual image matches the RF2 golden"
    (check-equal? (program-image->string (make-image))
                  (file->string golden)))

  (test-case "compiler producer writes one content-addressed package per program"
    (parameterize ([current-directory repo-root])
      (define loaded (load-program-list source-path (hash)))
      (check-equal? (length loaded) 1)
      (define compiled-program (first loaded))
      (define pp (program->jobs compiled-program))
      (define jobs (first pp))
      (define out-dir (make-temporary-file "rf2-image-~a" 'directory))
      (dynamic-wind
        void
        (lambda ()
          (define-values (image path)
            (emit-program-image compiled-program jobs out-dir))
          (check-true (file-exists? path))
          (check-equal? (path->string (file-name-from-path path))
                        (format "~a.pimg" (program-image-key image)))
          (check-equal? (length (program-image-cohorts image)) (length jobs))
          (check-equal? (call-with-input-file path read-program-image) image)
          ;; Re-emission is a content-addressed cache hit, not a second package.
          (define-values (image2 path2)
            (emit-program-image compiled-program jobs out-dir))
          (check-equal? image2 image)
          (check-equal? path2 path)
          (check-equal? (length (directory-list out-dir)) 1))
        (lambda () (delete-directory/files out-dir)))))

  (test-case "double-digit SCC and dependency slots retain numeric wire order"
    (parameterize ([current-directory repo-root])
      (define program
        (first (load-program-list
                (build-path repo-root "tests" "dem_lambda.slog") (hash))))
      (define pp (program->jobs program))
      (define image
        (seal-program-image program (fourth pp) (fifth pp)
                            #:compiler-key "compiler-test"
                            #:source-root repo-root))
      (check > (length (program-image-components image)) 10)
      (check-equal?
       (read-program-image
        (open-input-string (program-image->string image)))
       image)))

  (test-case "compiler-derived oracle dependencies survive the image boundary"
    (parameterize ([current-directory repo-root])
      (define program
        (first (load-program-list
                (build-path repo-root "tests" "smt_basic.slog") (hash))))
      (define pp (program->jobs program))
      (define model (fifth pp))
      (define image
        (seal-program-image program (fourth pp) model
                            #:compiler-key "compiler-test"
                            #:source-root repo-root))
      (check-not-false
       (for/or ([edge (in-list (program-image-dependencies image))])
         (and (eq? (image-dependency-from edge) 'smt_qsat)
              (eq? (image-dependency-to edge) 'smt_qsat_ans)
              (eq? (image-dependency-kind edge) 'oracle)
              (not (image-dependency-rule-slot edge)))))
      (check-not-false
       (member 'smt_qsat_ans
               (program-model-forward-cone model '(smt_qsat))))))

  (test-case "two instances of one source retain distinct image occurrences"
    (parameterize ([current-directory repo-root])
      (define instance-path (build-path repo-root "tests" "n1_instances.slog"))
      (define instance-program
        (first (load-program-list instance-path (hash))))
      (define jobs (first (program->jobs instance-program)))
      (match-define (list _ type-env+ _ _ _ instance-model) (first jobs))
      (define image
        (seal-program-image instance-program type-env+ instance-model
                            #:compiler-key "compiler-test"
                            #:source-root repo-root))
      (check-equal? (length (program-image-modules image)) 3)
      (define left-rule
        (first (program-image-rules-writing image 'left.path)))
      (define right-rule
        (first (program-image-rules-writing image 'right.path)))
      (check-not-equal? (image-rule-module left-rule)
                        (image-rule-module right-rule))
      (check-not-equal? (image-rule-source left-rule)
                        (image-rule-source right-rule))
      ;; The captured source bytes are reusable even though the lexical
      ;; occurrences and qualified rules are deliberately distinct.
      (check-equal?
       (image-source-digest
        (program-image-source-at image (image-rule-source left-rule)))
       (image-source-digest
        (program-image-source-at image (image-rule-source right-rule))))))

  (test-case "declaration-only programs seal without inventing a kernel"
    (parameterize ([current-directory repo-root])
      (define declaration-path
        (build-path repo-root "tests" "reflect" "rf2-decls.slog"))
      (define declaration-program
        (first (load-program-list declaration-path (hash))))
      (define pp (program->jobs declaration-program))
      (check-equal? (first pp) '())
      (define out-dir (make-temporary-file "rf2-decls-~a" 'directory))
      (dynamic-wind
        void
        (lambda ()
          (define-values (image path)
            (emit-program-image declaration-program (first pp) out-dir
                                #:type-env (fourth pp)
                                #:model (fifth pp)))
          (check-true (file-exists? path))
          (check-equal? (program-image-rules image) '())
          (check-equal? (program-image-components image) '())
          (check-equal? (program-image-cohorts image) '()))
        (lambda () (delete-directory/files out-dir)))))

  (test-case "compile-strata opt-in hook emits a sealed image without changing its API"
    (define out-dir (make-temporary-file "rf2-hook-~a" 'directory))
    (define env
      (environment-variables-copy (current-environment-variables)))
    (environment-variables-set! env #"SLOG_OPT" #"interp")
    (environment-variables-set!
     env #"SLOG_EMIT_PROGRAM_IMAGES"
     (path->bytes out-dir))
    (dynamic-wind
      void
      (lambda ()
        (parameterize ([current-directory repo-root]
                       [current-environment-variables env])
          ;; The runtime-facing result remains exactly five values.
          (define results
            (call-with-values
             (lambda () (compile-strata source-path (hash))) list))
          (check-equal? (length results) 5))
        (define image-paths
          (filter (lambda (path) (regexp-match? #rx"[.]pimg$"
                                                (path->string path)))
                  (directory-list out-dir #:build? #t)))
        (check-equal? (length image-paths) 1)
        (define mounted-value
          (call-with-input-file (first image-paths) read-program-image))
        (check-equal? (length (program-image-cohorts mounted-value)) 1))
      (lambda () (delete-directory/files out-dir)))))
