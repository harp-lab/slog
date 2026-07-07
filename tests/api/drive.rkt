#lang racket

;; Raw daemon driver for the pausable-fixpoint tests (docs/pausing.md).
;;
;;   racket tests/api/drive.rkt LINE ...
;;
;; Each command-line argument is one line sent verbatim to a fresh slogd over
;; stdin (a .so path, or a protocol literal such as "(continue)" or "(close)"),
;; in order; all daemon output is then echoed.  Unlike send-actions.rkt this
;; does no compiling and no auto-continue -- it sends exactly what it is given,
;; so a test can leave a stratum suspended and probe it, or drive the continue
;; loop by hand.  The environment (SLOG_MAX_MS / SLOG_MEM_BYTES / ...) is
;; inherited, so the caller sets the budget.
;;
;; Run from the repository root (build/, data/, daemon/ are relative).

(require "../../compiler/tools.rkt")

(module+ main
  (define lines (vector->list (current-command-line-arguments)))
  (ensure-slogd-exists)
  (define-values (sp out in err) (apply subprocess #f #f #f (slogd-argv "daemon/slogd")))
  (for ([l (in-list lines)])
    (display (string-append l "\n") in)
    (flush-output in))
  (close-output-port in)
  (for ([port (in-list (list out err))])
    (let loop ()
      (define s (read-line port))
      (when (not (eof-object? s))
        (displayln s)
        (loop)))
    (close-input-port port))
  (subprocess-wait sp)
  (exit (if (> (subprocess-status sp) 0) 1 0)))
