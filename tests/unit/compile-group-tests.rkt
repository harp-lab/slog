#lang racket

(module+ test
  (require rackunit
           racket/file
           racket/runtime-path
           "../../compiler/catalog.rkt"
           "../../compiler/compile.rkt"
           "../../compiler/names.rkt")

  (define-runtime-path repo-root "../..")

  (define (with-source text proc)
    (define dir (make-temporary-file "slog-n2b-~a" 'directory))
    (define source (build-path dir "program.slog"))
    (dynamic-wind
      (lambda ()
        (call-with-output-file source #:exists 'truncate
          (lambda (out) (display text out))))
      (lambda () (proc source))
      (lambda () (delete-directory/files dir))))

  (define (compile-groups text)
    (define old-opt (getenv "SLOG_OPT"))
    (dynamic-wind
      (lambda () (putenv "SLOG_OPT" "interp"))
      (lambda ()
        (parameterize ([current-directory repo-root])
          (with-source
           text
           (lambda (source)
             (define-values (_strata _partition _edb _frozen groups)
               (compile-strata source (hash) #:split-facts? #f))
             groups))))
      (lambda () (putenv "SLOG_OPT" (or old-opt "")))))

  (test-case "declaration-only programs retain a first-class empty boundary group"
    (define groups
      (compile-groups
       #<<SLOG
table (empty int)
SLOG
       ))
    (check-equal? (length groups) 1)
    (define group (first groups))
    (check-true (compile-group? group))
    (check-equal? (compile-group-stratum-count group) 0)
    (check-equal? (compile-group-frozen-dirs group) '())
    (check-equal? (compile-group-write-set group) '())
    (check-equal? (compile-group-boundary-write-set group) '())
    (check-true
     (storage-declaration?
      (hash-ref
       (catalog-delta-declarations (compile-group-catalog-delta group))
       (symbol->qname 'empty)))))

  (test-case "compile groups distinguish actual writes from the full catalog"
    (define groups
      (compile-groups
       #<<SLOG
table (edge int int)
table (path int int)

rule
(edge X Y)
-->
(path X Y)
SLOG
       ))
    (check-equal? (length groups) 1)
    (define group (first groups))
    (check-equal? (compile-group-stratum-count group) 1)
    (define declarations
      (catalog-delta-declarations (compile-group-catalog-delta group)))
    (check-true (hash-has-key? declarations (symbol->qname 'edge)))
    (check-true (hash-has-key? declarations (symbol->qname 'path)))
    (check-equal? (compile-group-boundary-write-set group) '(path))
    (check-not-false (member 'path (compile-group-write-set group)))))
