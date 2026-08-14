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

;; The generic total-coverage draft construction lives in
;; compiler/change-pcs.rkt (auto-program-draft) -- shared with the REPL.

;; ---------------------------------------------------------------------------
;; Cases.
;; ---------------------------------------------------------------------------

(define (joint-path name) (build-path joint-dir name))

(define (build-case base-name candidate-name source-names)
  (define base (compile-image (joint-path base-name)))
  (define candidate (compile-image (joint-path candidate-name)))
  (define change-set (seal-program-draft (auto-program-draft base candidate)))
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
              '("joint-refusal-candidate.slog"))
        ;; the W5' exit demo's producer leg: ONE rule of the right
        ;; instance edited (recursion narrowed to two-hop paths)
        ;; libs first, entry main LAST: the session's activate step
        ;; compiles the final source as the program entry
        (list "w5-demo"
              "w5-demo-base.slog" "w5-demo-candidate.slog"
              '("w5-demo-lib.slog" "w5-demo-lib-v2.slog"
                "w5-demo-candidate.slog"))
        ;; the rf5 §10 gate cases (tests/rf5-gate.sh)
        (list "gate-split"
              "gate-split-base.slog" "gate-split-candidate.slog"
              '("gate-split-candidate.slog"))
        (list "gate-merge"
              "gate-merge-base.slog" "gate-merge-candidate.slog"
              '("w5-demo-lib.slog" "gate-merge-candidate.slog"))
        (list "gate-identical"
              "gate-identical-base.slog" "gate-identical-candidate.slog"
              '("gate-identical-candidate.slog"))
        (list "gate-duplicate"
              "gate-duplicate-base.slog" "gate-duplicate-candidate.slog"
              '("gate-duplicate-candidate.slog"))))

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
