#lang racket

;; Client actions: everything a driver asks of the daemon's database besides
;; running strata -- opening and writing databases, edits and staging,
;; counting, introspection.  Each is one command line on the daemon's
;; command layer, shaped exactly like its spec:
;;
;;   (action-line `(open ,db-name))          load data/<db-name>/
;;   (action-line `(add-batch edge -1 ((1 2) (2 3))))
;;   (action-line `(dump-counts path))       ...
;;
;; daemon/actions.cpp owns the vocabulary, each verb's arguments, and its
;; reply.  The spec's data travels on the line: there is nothing to compile,
;; so a new tuple, name or position costs nothing.  (These were once
;; generated plugins, one clang build per distinct spec.)

(provide action-line)

;; The command line for `spec`.  The verb is written as an atom; every other
;; symbol -- a relation name, a tag, a symbol value -- as a string, so names
;; never depend on reader-safe spelling and a symbol value interns as the
;; string it names.  The compatibility spelling of stage-update-transitions
;; (no sign) means sign 1.
(define (action-line spec)
  (define normalized
    (match spec
      [`(stage-update-transitions signed ,_ ...) spec]
      [`(stage-update-transitions ,rels ...)
       `(stage-update-transitions signed 1 ,@rels)]
      [_ spec]))
  (with-output-to-string
    (lambda ()
      (write-string "(")
      (write-string (symbol->string (car normalized)))
      (for ([arg (in-list (cdr normalized))])
        (write-string " ")
        (write-arg arg))
      (write-string ")"))))

;; One argument in the daemon reader's syntax: lists, decimal numbers, and
;; strings with only the escapes it accepts (Racket's `write` may emit \e or
;; \uXXXX, which it refuses).
(define (write-arg v)
  (cond
    [(list? v)
     (write-string "(")
     (for ([x (in-list v)] [i (in-naturals)])
       (unless (zero? i) (write-string " "))
       (write-arg x))
     (write-string ")")]
    [(symbol? v) (write-arg (symbol->string v))]
    [(string? v)
     (write-string "\"")
     (for ([c (in-string v)])
       (write-string (case c
                       [(#\\) "\\\\"] [(#\") "\\\""] [(#\newline) "\\n"]
                       [(#\tab) "\\t"] [(#\return) "\\r"] [else (string c)])))
     (write-string "\"")]
    [(exact-integer? v) (write-string (number->string v))]
    [(and (real? v) (rational? v)) (write-string (number->string (exact->inexact v)))]
    [else (error 'action-line "unsupported action argument: ~s" v)]))
