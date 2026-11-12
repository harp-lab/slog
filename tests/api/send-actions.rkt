#lang racket

;; Send a sequence of actions to a fresh slogd and echo its output:
;;
;;   racket tests/api/send-actions.rkt open:mydb load-rel:otherdb,edge sizes
;;
;; Specs: open:DB | import:DB | write-db:DB | write-csv:DIR
;;      | write-rel:DB,REL | write-rel-csv:DIR,REL | load-rel:DB,REL
;;      | refresh-rel:DB,REL | sizes | schema
;;      | so:PATH (send a stratum plugin path verbatim)
;;
;; Run from the repository root (build/, data/, daemon/ are relative).

(require "../../compiler/actions.rkt")
(require "../../compiler/tools.rkt")

(define (parse-spec s)
  (match (string-split s ":")
    [(list "sizes") `(sizes)]
    [(list "schema") `(schema)]
    [(list "open" db) `(open ,db)]
    [(list "import" db) `(import ,db)]
    [(list "import-layer" db) `(import-layer ,db)]
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

(define (spec->line spec)
  (match spec
    [`(so ,path) path]
    [_ (action-line spec)]))

(module+ main
  (define args (vector->list (current-command-line-arguments)))
  ;; --lines: only print the protocol lines (for test scripts that drive a
  ;; daemon session themselves, e.g. via a fifo)
  (define lines-only? (and (pair? args) (equal? (car args) "--lines")))
  (define specs (if lines-only? (cdr args) args))
  (define lines (map (compose spec->line parse-spec) specs))
  (when lines-only?
    (for ([p (in-list lines)]) (displayln p))
    (exit 0))
  (ensure-slogd-exists)
  (define-values (sp out in err) (apply subprocess #f #f #f (slogd-argv "daemon/slogd")))
  (for ([p (in-list lines)])
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
