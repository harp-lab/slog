#lang racket

;; Exercise configuration without requiring either compiler installation.
;; In particular, explicit dependency flags must work without Homebrew.
(module+ test
  (require rackunit racket/runtime-path)
  (define-runtime-path daemon "../../daemon")
  (define dir (make-temporary-file "native-config~a" 'directory))
  (define apple (build-path dir "apple-clang++"))
  (define llvm (build-path dir "bin" "clang++"))
  (define brew-called (build-path dir "brew-called"))
  (define env (environment-variables-copy (current-environment-variables)))
  (for ([key '(#"CXX" #"CPPFLAGS" #"OMPFLAGS" #"LDFLAGS" #"LDLIBS"
               #"LLVM_PREFIX" #"BREW_PREFIX" #"OMP_PREFIX" #"OPENSSL_PREFIX")])
    (environment-variables-set! env key #f))
  (define (script path body)
    (display-to-file (string-append "#!/bin/sh\n" body "\n") path)
    (file-or-directory-permissions path #o755))
  (define (config . args)
    (define ok? #f)
    (define output
      (parameterize ([current-environment-variables env])
        (with-output-to-string
          (lambda ()
            (set! ok? (apply system* (find-executable-path "make")
                            "--no-print-directory" "-s" "-C" daemon
                            "print-toolchain" args))))))
    (check-true ok?)
    (map string-split (take (string-split output "\n" #:trim? #f) 6)))
  (dynamic-wind
    void
    (lambda ()
      (make-directory (build-path dir "bin"))
      (script apple "echo 'Apple clang version 15.0.0'")
      (script llvm "echo 'clang version 21.1.4'")
      (script (build-path dir "bin" "brew") "touch \"$SLOG_BREW_CALLED\"; exit 1")
      (environment-variables-set! env #"SLOG_BREW_CALLED" (path->bytes brew-called))
      (environment-variables-set!
       env #"PATH" (string->bytes/utf-8
                    (format "~a:~a" (build-path dir "bin") (getenv "PATH"))))
      (define a (config "NATIVE_OS=Darwin" "BREW_PREFIX=" (format "CXX=~a" apple)
                        "CPPFLAGS=-I/custom/include" "LDFLAGS=-L/custom/lib"
                        "LDLIBS=-lcustom"))
      (check-equal? (second a) '("-I/custom/include"))
      (check-equal? (third a) '("-Xclang" "-fopenmp"))
      (check-equal? (fourth a) '("-L/custom/lib"))
      (check-equal? (sixth a) '("-lcustom"))
      (define l (config "NATIVE_OS=Darwin" "BREW_PREFIX=" (format "LLVM_PREFIX=~a" dir)))
      (check-equal? (first l) (list (path->string llvm)))
      (check-equal? (third l) '("-fopenmp"))
      (check-not-false (member (format "-L~a/lib/c++" dir) (fourth l)))
      (check-not-false (member "-lunwind" (sixth l)))
      (define linux (config "NATIVE_OS=Linux" (format "CXX=~a" llvm)))
      (check-equal? (fifth linux) '("-shared"))
      (check-not-false (member "-ldl" (sixth linux)))
      (check-false (file-exists? brew-called)))
    (lambda () (delete-directory/files dir))))
