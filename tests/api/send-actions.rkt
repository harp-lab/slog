#lang racket

;; Send a sequence of action plugins to a fresh slogd and echo its output:
;;
;;   racket tests/api/send-actions.rkt open:mydb load-rel:otherdb,edge sizes
;;
;; Specs: open:DB | write-db:DB | write-csv:DIR | write-rel:DB,REL
;;      | write-rel-csv:DIR,REL | load-rel:DB,REL | refresh-rel:DB,REL
;;      | sizes | so:PATH (send an arbitrary plugin path verbatim)
;;
;; Run from the repository root (build/, data/, daemon/ are relative).

(require "../../compiler/actions.rkt")
(require "../../compiler/tools.rkt")

(define (parse-spec s)
  (match (string-split s ":")
    [(list "sizes") `(sizes)]
    [(list "open" db) `(open ,db)]
    [(list "write-db" db) `(write-db ,db)]
    [(list "write-csv" dir) `(write-csv ,dir)]
    [(list "write-rel" arg)
     (match-define (list db rel) (string-split arg ","))
     `(write-rel ,db ,rel)]
    [(list "write-rel-csv" arg)
     (match-define (list dir rel) (string-split arg ","))
     `(write-rel-csv ,dir ,rel)]
    [(list "load-rel" arg)
     (match-define (list db rel) (string-split arg ","))
     `(load-rel ,db ,rel)]
    [(list "refresh-rel" arg)
     (match-define (list db rel) (string-split arg ","))
     `(refresh-rel ,db ,rel)]
    [(list "so" path) `(so ,path)]
    [_ (error 'send-actions "unrecognized action spec: ~a" s)]))

(define (spec->path spec)
  (match spec
    [`(so ,path) path]
    [_ (action-so spec)]))

(module+ main
  (define args (vector->list (current-command-line-arguments)))
  ;; --paths: only build the plugins and print their paths (for test
  ;; scripts that drive a daemon session themselves, e.g. via a fifo)
  (define paths-only? (and (pair? args) (equal? (car args) "--paths")))
  (define specs (if paths-only? (cdr args) args))
  (define paths (map (compose spec->path parse-spec) specs))
  (when paths-only?
    (for ([p (in-list paths)]) (displayln p))
    (exit 0))
  (ensure-slogd-exists)
  (define-values (sp out in err) (apply subprocess #f #f #f (slogd-argv "daemon/slogd")))
  (for ([p (in-list paths)])
    (display (string-append p "\n") in))
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
