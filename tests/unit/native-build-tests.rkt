#lang racket

;; Concurrent driver startups must share warm native binaries without racing
;; make, truncating a shared log, or rebuilding unchanged products.
(module+ test
  (require rackunit racket/runtime-path "../../compiler/tools.rkt")
  (define-runtime-path root "../..")
  (define-runtime-path tools-module "../../compiler/tools.rkt")
  (parameterize ([current-directory root])
    (ensure-slogd-exists)
    (ensure-slog-freeze-exists)
    (define targets '("daemon/slogd" "daemon/slog-freeze" "daemon/plan-flavored-tasks.o"))
    (define before (map file-or-directory-modify-seconds targets))
    (define expression
      (format "(require (file ~s)) (ensure-slogd-exists) (ensure-slog-freeze-exists)"
              (path->string tools-module)))
    (define children
      (for/list ([_ (in-range 8)])
        (define-values (sp out in err)
          (subprocess #f #f #f (find-executable-path "racket") "-e" expression))
        (close-output-port in)
        (define stderr (box ""))
        (define reader (thread (lambda () (set-box! stderr (port->string err)))))
        (list sp out err reader stderr)))
    (for ([child (in-list children)])
      (define sp (first child))
      (port->string (second child))
      (subprocess-wait sp)
      (thread-wait (fourth child))
      (close-input-port (second child))
      (close-input-port (third child))
      (check-equal? (subprocess-status sp) 0 (unbox (fifth child))))
    (check-equal? (map file-or-directory-modify-seconds targets) before)))
