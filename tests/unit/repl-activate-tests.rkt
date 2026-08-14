#lang racket

;; RF5-B at the prompt (rf5-contract §6's initial surface): `replace
;; instance ALIAS with "LIB.slog"` seals a proposal through the ordinary
;; producer pipeline and renders its preview; `preview` re-renders;
;; `activate` runs the proven activation transaction against the live
;; boundary.  The battery pins the workflow on the W5' demo shape: the
;; right instance swaps transitivity for reversal, (right.path 1 4) is
;; present and derivable before and walks the v2 frontier after.

(require rackunit
         racket/file
         racket/runtime-path
         "../../compiler/repl.rkt")

(define-runtime-path repo-root "../..")
(define-runtime-path joint-dir "../reflect/joint")

(module+ test
  (void (putenv "SLOG_NO_MEM_CAP" "1"))
  (void (putenv "SLOG_THREADS" "2"))
  (void (putenv "SLOG_OPT" "0"))

  (define dir (make-temporary-file "repl-activate-~a" 'directory))
  (dynamic-wind
    void
    (lambda ()
      (for ([name '("w5-demo-lib.slog" "w5-demo-lib-v2.slog")])
        (copy-file (build-path joint-dir name) (build-path dir name)))
      (copy-file (build-path joint-dir "w5-demo-base.slog")
                 (build-path dir "analysis.slog"))

      (test-case "replace instance / preview / activate, end to end"
        (define transcript
          (parameterize ([current-directory repo-root])
            (plain-transcript
             (list (format "run ~a" (path->string (build-path dir "analysis.slog")))
                   "whynot (right.path 1 4)"
                   "replace instance right with \"w5-demo-lib-v2.slog\""
                   "preview"
                   "activate"
                   "whynot (right.path 1 4)"))))
        ;; before: present; the proposal seals and previews its cone
        (check-regexp-match #px"is present" transcript)
        (check-regexp-match #px"Proposal d[0-9]+ — replace instance right"
                            transcript)
        (check-regexp-match #px"rebuild: \\(answer right\\.path\\)" transcript)
        (check-regexp-match #px"nothing is live yet" transcript)
        ;; preview re-renders the same sealed key
        (check-regexp-match #px"Proposal — replace instance right" transcript)
        ;; activate commits; the same fact now walks the v2 frontier
        (check-regexp-match #px"Activated — p1:" transcript)
        (check-regexp-match #px"committed atomically after recount" transcript)
        (check-regexp-match #px"w5-demo-lib-v2\\.slog" transcript))

      (test-case "proposal lifecycle refusals instruct"
        (define transcript
          (parameterize ([current-directory repo-root])
            (plain-transcript
             (list "preview"
                   (format "run ~a" (path->string (build-path dir "analysis.slog")))
                   "replace instance nosuch with \"w5-demo-lib-v2.slog\""
                   "activate"))))
        (check-regexp-match #px"no pending proposal" transcript)
        (check-regexp-match #px"no `instantiate \\.\\.\\. as nosuch` occurrence"
                            transcript))

      (test-case "a proposal stale against a moved boundary refuses, is retained"
        (define transcript
          (parameterize ([current-directory repo-root])
            (plain-transcript
             (list (format "run ~a" (path->string (build-path dir "analysis.slog")))
                   "replace instance right with \"w5-demo-lib-v2.slog\""
                   ;; move the tip out from under the sealed proposal
                   (format "run ~a" (path->string (build-path dir "analysis.slog")))
                   "activate"
                   ;; the proposal survives the refusal -- preview still works
                   "preview"))))
        (check-regexp-match #px"the committed boundary moved since this proposal was sealed"
                            transcript)
        (check-regexp-match #px"Proposal — replace instance right" transcript)))
    (lambda () (delete-directory/files dir))))
