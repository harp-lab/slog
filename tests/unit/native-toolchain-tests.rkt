#lang racket

;; Exercise the actual plugin linker and object cache with two toolchain
;; configurations. The second build must not reuse the first build's object.
(module+ test
  (require rackunit racket/runtime-path)
  (define-runtime-path root "../..")
  (define-runtime-path tools-module "../../compiler/tools.rkt")
  (parameterize ([current-directory root])
    (make-directory* "build")
    (define dir (make-temporary-file "native-flags~a" 'directory (build-path root "build")))
    (define cpp (build-path dir "probe.cpp"))
    (define so (build-path dir "probe.so"))
    (define recorder (build-path dir "record-argv"))
    (define recorded (build-path dir "argv"))
    (dynamic-wind
      void
      (lambda ()
        (display-to-file
         "extern \"C\" const char* native_probe() { return SLOG_NATIVE_TEST; }\n" cpp)
        (display-to-file "#!/bin/sh\nprintf '%s\\n' \"$@\" > \"$SLOG_NATIVE_ARGV\"\n" recorder)
        (file-or-directory-permissions recorder #o755)
        (for ([value (in-list '("one" "two's"))])
          (define env (environment-variables-copy (current-environment-variables)))
          (define flag (format "-DSLOG_NATIVE_TEST=\"~a\"" value))
          (environment-variables-set!
           env #"CPPFLAGS"
           (string->bytes/utf-8
            (format "~a ~a" (or (getenv "CPPFLAGS") "") flag)))
          (environment-variables-set! env #"SLOG_NATIVE_ARGV" (path->bytes recorded))
          ;; Inspect the actual Makefile recipe's arguments without rebuilding
          ;; shared binaries. Quotes must survive identically in both paths.
          (parameterize ([current-environment-variables env]
                         [current-output-port (open-output-nowhere)])
            (check-true
             (system* (find-executable-path "make") "-s" "-C" "daemon" "interp-check"
                      (format "CXX=~a" recorder))))
          (check-not-false (member flag (file->lines recorded)))
          (define expression
            (format
             "(begin (require ffi/unsafe (file ~s)) (build-so ~s ~s #:opt \"-O0\" #:pch #f) (displayln ((get-ffi-obj \"native_probe\" (ffi-lib ~s) (_fun -> _string/utf-8)))))"
             (path->string tools-module) (path->string cpp) (path->string so) (path->string so)))
          (define-values (sp out in err)
            (parameterize ([current-environment-variables env])
              (subprocess #f #f #f (find-executable-path "racket") "-e" expression)))
          (close-output-port in)
          (define errors (box ""))
          (define reader (thread (lambda () (set-box! errors (port->string err)))))
          (define result (port->string out))
          (subprocess-wait sp)
          (thread-wait reader)
          (close-input-port out)
          (close-input-port err)
          (check-equal? (subprocess-status sp) 0 (unbox errors))
          (check-equal? (string-trim result) value)))
      (lambda () (delete-directory/files dir)))))
