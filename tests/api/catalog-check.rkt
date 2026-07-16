#lang racket

;; Structured-record consumer for the T0 catalog verbs (docs/t0-contract.md
;; slice (a)).  Reads a daemon transcript on stdin and consumes every catalog
;; stream the way a client must be able to: datum `read` plus keyed field
;; access -- NO string splitting of payload fields (F criterion 4).  Checks:
;;
;;   - every (catalog-rel ...) record carries the full pinned field set
;;     [name kind arity version-id version-key evaluation predecessor
;;      struct-id type-key lat-spec size temp] with well-typed values
;;     (strings for names/keys, naturals for ids/sizes, #f for absent);
;;   - every (catalog-planned ...) record carries [name version-key];
;;   - every (catalog-type ...) record carries [sid name arity type-key];
;;   - each stream's (catalog-end <n>) sentinel count equals the number of
;;     records that preceded it.
;;
;; Command-line assertions (any number, checked over ALL streams):
;;   rel=NAME,KIND,ARITY   a catalog-rel with that name has that kind/arity;
;;                         struct kind additionally requires a positive
;;                         integer struct-id and a version-id >= 1
;;   type=NAME             a catalog-type record with that name exists
;;   rels>=N / types>=N    at least N records of that class seen
;;
;;   racket tests/api/catalog-check.rkt rel=edge,table,2 < transcript

(define (fail! fmt . args)
  (eprintf "catalog-check: ~a\n" (apply format fmt args))
  (exit 1))

(define (field rec key)          ; rec = (catalog-* (k v) ...) -> v or 'missing
  (define hit (assq key (cdr rec)))
  (if (and hit (= (length hit) 2)) (cadr hit) 'missing))

(define (check-typed rec key pred what)
  (define v (field rec key))
  (when (eq? v 'missing) (fail! "~s: missing field ~a" rec key))
  (unless (pred v) (fail! "~s: field ~a is not ~a" rec key what))
  v)

(define (nat-or-f? v) (or (eq? v #f) (exact-nonnegative-integer? v)))
(define (string-or-f? v) (or (eq? v #f) (string? v)))

(define (check-rel rec)
  (check-typed rec 'name string? "a string")
  (define kind (check-typed rec 'kind (lambda (v) (memq v '(table struct lat)))
                            "table|struct|lat"))
  (check-typed rec 'arity exact-nonnegative-integer? "a natural")
  (check-typed rec 'version-id exact-nonnegative-integer? "a natural")
  (check-typed rec 'version-key string-or-f? "a string or #f")
  (check-typed rec 'evaluation string-or-f? "a string or #f")
  (check-typed rec 'predecessor nat-or-f? "a natural or #f")
  (define sid (check-typed rec 'struct-id nat-or-f? "a natural or #f"))
  (check-typed rec 'type-key not "#f (N3 fills it)")
  (check-typed rec 'lat-spec string-or-f? "a string or #f")
  (check-typed rec 'size nat-or-f? "a natural or #f")
  (check-typed rec 'temp boolean? "a boolean")
  (when (and (eq? kind 'struct) (not (exact-positive-integer? sid)))
    (fail! "~s: struct kind without a positive struct-id" rec)))

(define (check-planned rec)
  (check-typed rec 'name string? "a string")
  (check-typed rec 'version-key string? "a string"))

(define (check-type rec)
  (check-typed rec 'sid exact-positive-integer? "a positive integer")
  (check-typed rec 'name string? "a string")
  (check-typed rec 'arity exact-nonnegative-integer? "a natural")
  (check-typed rec 'type-key not "#f (N3 fills it)"))

(module+ main
  (define assertions (vector->list (current-command-line-arguments)))
  (define rels '())      ; every catalog-rel record seen
  (define types '())     ; every catalog-type record seen
  (define in-stream 0)   ; records since the last sentinel
  (define streams 0)
  (for ([line (in-lines)])
    (define rec (with-handlers ([exn:fail? (lambda (_) #f)])
                  (read (open-input-string line))))
    (when (pair? rec)
      (case (car rec)
        [(catalog-rel)     (check-rel rec)
                           (set! rels (cons rec rels))
                           (set! in-stream (add1 in-stream))]
        [(catalog-planned) (check-planned rec)
                           (set! in-stream (add1 in-stream))]
        [(catalog-type)    (check-type rec)
                           (set! types (cons rec types))
                           (set! in-stream (add1 in-stream))]
        [(catalog-end)
         (unless (and (= (length rec) 2) (equal? (cadr rec) in-stream))
           (fail! "sentinel ~s after ~a records" rec in-stream))
         (set! in-stream 0)
         (set! streams (add1 streams))]
        [else (void)])))
  (when (> in-stream 0) (fail! "record stream not closed by (catalog-end n)"))
  (when (zero? streams) (fail! "no catalog stream in the transcript"))

  (define (find-rel name)
    (findf (lambda (r) (equal? (field r 'name) name)) rels))
  (for ([a (in-list assertions)])
    (cond
      [(regexp-match #px"^rel=([^,]+),([^,]+),([0-9]+)$" a)
       => (lambda (m)
            (define rec (find-rel (second m)))
            (unless rec (fail! "no catalog-rel named ~a" (second m)))
            (unless (eq? (field rec 'kind) (string->symbol (third m)))
              (fail! "~a: kind ~a, wanted ~a"
                     (second m) (field rec 'kind) (third m)))
            (unless (equal? (field rec 'arity) (string->number (fourth m)))
              (fail! "~a: arity ~a, wanted ~a"
                     (second m) (field rec 'arity) (fourth m)))
            (when (eq? (field rec 'kind) 'struct)
              (unless (>= (field rec 'version-id) 1)
                (fail! "~a: struct record without a version-id" (second m)))))]
      [(regexp-match #px"^type=(.+)$" a)
       => (lambda (m)
            (unless (findf (lambda (r) (equal? (field r 'name) (second m)))
                           types)
              (fail! "no catalog-type named ~a" (second m))))]
      [(regexp-match #px"^rels>=([0-9]+)$" a)
       => (lambda (m)
            (unless (>= (length rels) (string->number (second m)))
              (fail! "only ~a catalog-rel records, wanted >= ~a"
                     (length rels) (second m))))]
      [(regexp-match #px"^types>=([0-9]+)$" a)
       => (lambda (m)
            (unless (>= (length types) (string->number (second m)))
              (fail! "only ~a catalog-type records, wanted >= ~a"
                     (length types) (second m))))]
      [else (fail! "unknown assertion ~a" a)]))
  (printf "catalog-check: ok (~a rel, ~a type records, ~a streams)\n"
          (length rels) (length types) streams))
