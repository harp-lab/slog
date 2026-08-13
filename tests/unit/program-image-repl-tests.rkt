#lang racket

;; RF2-B friendly REPL projection over the daemon's independently validated,
;; read-only ProgramImage control catalog.

(require rackunit
         racket/file
         racket/runtime-path
         "../../compiler/compile.rkt"
         "../../compiler/modules.rkt"
         "../../compiler/program-image.rkt"
         "../../compiler/repl.rkt"
         "../../compiler/sha256.rkt")

(define-runtime-path repo-root "../..")

(define image-key
  "98db03c33027946f1fa293f105845043bf23643b43ced43926747b7396871bd8")

(define (datum-digest datum)
  (bytes->hex-string
   (sha256
    (string->bytes/utf-8
     (with-output-to-string (lambda () (write datum)))))))

(define (transcript-at-root commands)
  (parameterize ([current-directory repo-root])
    (plain-transcript commands)))

(define (transcript-at-root/opt commands mode)
  (define env
    (environment-variables-copy (current-environment-variables)))
  (environment-variables-set! env #"SLOG_OPT" (string->bytes/utf-8 mode))
  (parameterize ([current-directory repo-root]
                 [current-environment-variables env])
    (plain-transcript commands)))

(module+ test
  ;; Avoid host desktop memory-cap discovery in hermetic unit runners.
  (void (putenv "SLOG_NO_MEM_CAP" "1"))
  (void (putenv "SLOG_THREADS" "2"))

  (test-case "mount, inspect every image view, cache-hit, and unmount"
    (define transcript
      (transcript-at-root
       (list
        "image mount tests/image-expected/rf2-basic.pimg"
        "image mount tests/image-expected/rf2-basic.pimg"
        "images"
        (format "image ~a rules" image-key)
        (format "image ~a sources" image-key)
        (format "image ~a kernels" image-key)
        (format "image ~a plans" image-key)
        (format "image ~a materializations" image-key)
        (format "image unmount ~a" image-key)
        "images")))
    (check-regexp-match #px"validated and mounted" transcript)
    (check-regexp-match #px"validated cache hit" transcript)
    (check-regexp-match #px"2 rules · 2 kernels · 1 plan · 1 source" transcript)
    (check-regexp-match
     #px"r0 · heads reach · source s0 · \\(rule \\(edge \\?0 \\?1\\)"
     transcript)
    (check-regexp-match
     #px"s0 · module m0 · tests/reflect/rf2-basic.slog · 3 tokens"
     transcript)
    (check-regexp-match #px"k0 · level 0 · edge" transcript)
    (check-regexp-match #px"kernel-cohort \\(abi 2\\)" transcript)
    (check-regexp-match #px"0 mounts remain" transcript)
    (check-regexp-match #px"no mounted image records" transcript))

  (test-case "missing and tampered image files are typed refusals"
    (define missing
      (transcript-at-root
       (list "image mount tests/image-expected/no-such-image.pimg")))
    (check-regexp-match #px"refused command stream.*image-io" missing)

    (define bad-path (make-temporary-file "rf2-bad-key-~a.pimg"))
    (dynamic-wind
      void
      (lambda ()
        (define good
          (file->string (build-path repo-root
                                    "tests/image-expected/rf2-basic.pimg")))
        (define bad
          (regexp-replace
           #px"\\(key \"[0-9a-f]+\"\\)" good
           "(key \"0000000000000000000000000000000000000000000000000000000000000000\")"))
        (call-with-output-file bad-path
          (lambda (out) (display bad out))
          #:exists 'truncate)
        (define tampered
          (transcript-at-root
           (list (format "image mount ~s" (path->string bad-path)))))
        (check-regexp-match #px"refused command stream.*image-seal" tampered))
      (lambda () (when (file-exists? bad-path) (delete-file bad-path)))))

  (test-case "independent decoder recomputes the ProgramModel fingerprint"
    (define forged-path (make-temporary-file "rf2-bad-model-~a.pimg"))
    (dynamic-wind
      void
      (lambda ()
        (define datum
          (call-with-input-file
              (build-path repo-root "tests/image-expected/rf2-basic.pimg")
            read))
        (define fields
          (for/list ([field (in-list (cdddr datum))])
            (match field
              [`(model-key ,_) `(model-key ,(make-string 64 #\0))]
              [_ field])))
        (define forged
          `(program-image (state sealed)
                          (key ,(datum-digest
                                 `(program-image-content ,@fields)))
                          ,@fields))
        (call-with-output-file forged-path #:exists 'truncate
          (lambda (out) (pretty-write forged out)))
        (define transcript
          (transcript-at-root
           (list (format "image mount ~s" (path->string forged-path)))))
        (check-regexp-match #px"refused command stream.*image-seal" transcript)
        (check-regexp-match #px"ProgramModel fingerprint mismatch" transcript))
      (lambda ()
        (when (file-exists? forged-path) (delete-file forged-path)))))

  (test-case "RF3 mounted image execution matches the ordinary program path"
    (parameterize ([current-directory repo-root])
      (define source "tests/cartesian.slog")
      (define program (first (load-program-list source (hash))))
      (define pp (program->jobs program))
      (define out-dir (make-temporary-file "rf3-image-~a" 'directory))
      (dynamic-wind
        void
        (lambda ()
          (define-values (image path)
            (emit-program-image program (first pp) out-dir
                                #:type-env (fourth pp)
                                #:model (fifth pp)))
          ;; Two dependency levels are intentional: this pins the deferred
          ;; full->delta reload between image cohorts, not merely decoding a
          ;; one-stratum plan.  `cartesian.slog` also contains a multi-head
          ;; fact rule, covering the canonical `co-head` dependency spelling.
          (check-equal? (length (program-image-cohorts image)) 2)
          (define key (program-image-key image))
          (define native
            (transcript-at-root/opt
             (list (format "run ~a" source) "count c") "0"))
          (define interpreted
            (transcript-at-root
             (list (format "image mount ~s" (path->string path))
                   (format "image ~a activate" key)
                   (format "image ~a activation" key)
                   (format "image ~a materializations" key)
                   (format "image ~a activate" key)
                   "count c"
                   (format "image unmount ~a" key))))
          (check-regexp-match #px"4 rows" native)
          (check-regexp-match #px"4 rows" interpreted)
          (check-regexp-match #px"sealed, bound, and settled" interpreted)
          (check-regexp-match #px"settled · SCC 0 · 2 cohorts · 2 kernels"
                              interpreted)
          (check-regexp-match
           #px"cache miss · 0/[1-9][0-9]* native · 0 artifact \\+ 1 interpreted attachment"
           interpreted)
          (check-regexp-match #px"already active" interpreted)
          (check-regexp-match #px"image-active" interpreted))
        (lambda () (delete-directory/files out-dir)))))

  (test-case "RF3 accepts and executes a compiler-produced prelude kernel"
    (parameterize ([current-directory repo-root])
      (define source "tests/lat_run_base.slog")
      (define program (first (load-program-list source (hash))))
      (define pp (program->jobs program))
      (define out-dir (make-temporary-file "rf3-prelude-~a" 'directory))
      (dynamic-wind
        void
        (lambda ()
          (define-values (image path)
            (emit-program-image program (first pp) out-dir
                                #:type-env (fourth pp)
                                #:model (fifth pp)))
          (check-regexp-match #px"\\(prelude #t\\)"
                              (program-image->string image))
          (define key (program-image-key image))
          (define transcript
            (transcript-at-root
             (list (format "image mount ~s" (path->string path))
                   (format "image ~a activate" key)
                   (format "image ~a activation" key)
                   "count dist"
                   (format "image unmount ~a" key))))
          (check-regexp-match #px"validated and mounted" transcript)
          (check-regexp-match #px"sealed, bound, and settled" transcript)
          (check-regexp-match #px"3 rows" transcript))
        (lambda () (delete-directory/files out-dir)))))

  (test-case "RF3 refuses an introspection-only image whose manifests omit its model"
    (define transcript
      (transcript-at-root
       (list "image mount tests/image-expected/rf2-basic.pimg"
             (format "image ~a activate" image-key))))
    (check-regexp-match #px"activation refused \\(binding\\)" transcript)
    (check-regexp-match #px"manifests do not match the ProgramModel"
                        transcript)))
