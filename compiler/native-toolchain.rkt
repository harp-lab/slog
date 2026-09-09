#lang racket

;; Keep build configuration in one place: daemon/native.mk. No shell eval;
;; each line is one field, and flag fields contain whitespace-separated argv.
(provide native-cxx native-include-flags native-openmp-flags native-link-flags
         native-plugin-flags native-libraries native-toolchain-fingerprint)
(require racket/runtime-path)
(define-runtime-path daemon-dir "../daemon")

(define (capture exe . args)
  (define-values (sp out in err) (apply subprocess #f #f #f exe args))
  (close-output-port in)
  (define errors "")
  (define reader (thread (lambda () (set! errors (port->string err)))))
  (define result (port->string out))
  (subprocess-wait sp)
  (thread-wait reader)
  (close-input-port out)
  (close-input-port err)
  (unless (zero? (subprocess-status sp))
    (error 'native-toolchain "~a failed; check the native dependencies in Readme.md\n~a" exe errors))
  result)

(define fields
  (string-split (capture (find-executable-path "make") "--no-print-directory"
                         "-s" "-C" (path->string daemon-dir) "print-toolchain")
                "\n" #:trim? #f))
(define native-cxx
  (or (find-executable-path (first fields))
      (error 'native-toolchain "C++ compiler ~a not found; see Readme.md" (first fields))))
(define native-include-flags (string-split (second fields)))
(define native-openmp-flags (string-split (third fields)))
(define native-link-flags (string-split (fourth fields)))
(define native-plugin-flags (string-split (fifth fields)))
(define native-libraries (string-split (sixth fields)))

;; All native artifacts (including actions and PCHs) share this identity.
;; A compiler, target, SDK override, or flag change must not reuse an old ABI.
(define native-toolchain-fingerprint
  (format "~s\n~a" fields (capture native-cxx "--version")))
