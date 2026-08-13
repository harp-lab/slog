#lang racket

;; Structured-record consumer for the T0 catalog verbs (docs/t0-contract.md
;; slice (a)).  Reads a daemon transcript on stdin and consumes every catalog
;; stream the way a client must be able to: datum `read` plus keyed field
;; access -- NO string splitting of payload fields (F criterion 4).  Checks:
;;
;;   - every (catalog-rel ...) record carries the full pinned field set
;;     [name kind arity version-id version-key boundary evaluation predecessor
;;      struct-id type-key lat-spec size temp] with well-typed values
;;     (strings for names/keys, naturals for ids/sizes, #f for absent);
;;   - every (catalog-planned ...) record carries [name version-key];
;;   - every (catalog-type ...) record carries [sid name|#f arity type-key];
;;   - every (catalog-boundary ...) history record carries durable boundary
;;     and program keys plus position/generation/relation-count naturals;
;;   - RF2-B program/source/rule/kernel/plan rows carry the sealed image key,
;;     dense slots, typed references, digests, and structured plan/source maps;
;;   - RF4 artifact/materialization/attachment observations carry content and
;;     plan keys plus explicit native/interpreted variant-slot partitions;
;;   - each stream's (catalog-end <n>) sentinel count equals the number of
;;     records that preceded it.
;;
;; Command-line assertions (any number, checked over ALL streams):
;;   rel=NAME,KIND,ARITY   a catalog-rel with that name has that kind/arity;
;;                         struct kind additionally requires a positive
;;                         integer struct-id and a version-id >= 1
;;   type=NAME             a catalog-type record with that name exists
;;   rels>=N / types>=N    at least N records of that class seen
;;   images>=N              at least N catalog-program records seen
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
  (check-typed rec 'boundary string-or-f? "a BoundaryKey string or #f")
  (check-typed rec 'evaluation string-or-f? "a string or #f")
  (check-typed rec 'predecessor nat-or-f? "a natural or #f")
  (define sid (check-typed rec 'struct-id nat-or-f? "a natural or #f"))
  (check-typed rec 'type-key string-or-f? "a durable TypeKey string or #f")
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
  (check-typed rec 'name string-or-f? "a current name string or #f")
  (check-typed rec 'arity exact-nonnegative-integer? "a natural")
  (check-typed rec 'type-key string-or-f? "a durable TypeKey string or #f"))

(define (check-boundary rec)
  (check-typed rec 'boundary string? "a BoundaryKey string")
  (check-typed rec 'program string? "a ProgramInstanceKey string")
  (check-typed rec 'evaluation string? "an EvaluationId string")
  (check-typed rec 'position exact-nonnegative-integer? "a natural")
  (check-typed rec 'generation exact-nonnegative-integer? "a natural")
  (check-typed rec 'relations exact-nonnegative-integer? "a natural"))

(define (digest? value)
  (and (string? value) (regexp-match? #px"^[0-9a-f]{64}$" value)))

(define (check-program rec)
  (check-typed rec 'image-key digest? "a SHA-256 image key")
  (check-typed rec 'format exact-positive-integer? "a positive format")
  (check-typed rec 'compiler-key string? "a compiler key string")
  (check-typed rec 'plan-abi exact-positive-integer? "a positive Plan ABI")
  (check-typed rec 'model-key digest? "a SHA-256 model key")
  (for ([key '(root-module declarations modules sources rules kernels plans)])
    (check-typed rec key exact-nonnegative-integer? "a natural")))

(define (check-program-source rec)
  (check-typed rec 'image-key digest? "a SHA-256 image key")
  (check-typed rec 'slot exact-nonnegative-integer? "a source slot")
  (check-typed rec 'module exact-nonnegative-integer? "a module slot")
  (check-typed rec 'path string? "a root-relative path")
  (check-typed rec 'digest digest? "a SHA-256 source digest")
  (check-typed rec 'tokens exact-nonnegative-integer? "a token count"))

(define (check-program-rule rec)
  (check-typed rec 'image-key digest? "a SHA-256 image key")
  (check-typed rec 'slot exact-nonnegative-integer? "a rule slot")
  (check-typed rec 'source-id exact-nonnegative-integer? "a source rule id")
  (check-typed rec 'module nat-or-f? "a module slot or #f")
  (check-typed rec 'source nat-or-f? "a source slot or #f")
  (check-typed rec 'fingerprint digest? "a SHA-256 rule fingerprint")
  (check-typed rec 'normalized string? "a normalized rule string")
  (for ([key '(heads positive negative negative-wildcard)])
    (check-typed rec key
                 (lambda (value) (and (list? value) (andmap string? value)))
                 "a string list")))

(define (check-program-kernel rec)
  (check-typed rec 'image-key digest? "a SHA-256 image key")
  (check-typed rec 'slot exact-nonnegative-integer? "a kernel slot")
  (check-typed rec 'level exact-nonnegative-integer? "a dependency level")
  (check-typed rec 'members
               (lambda (value) (and (pair? value) (andmap string? value)))
               "a nonempty relation-name list"))

(define (check-program-plan rec)
  (check-typed rec 'image-key digest? "a SHA-256 image key")
  (check-typed rec 'slot exact-nonnegative-integer? "a plan slot")
  (check-typed rec 'digest digest? "a SHA-256 plan digest")
  (check-typed rec 'plan
               (lambda (value) (and (pair? value) (eq? (car value) 'kernel-cohort)))
               "a kernel-cohort datum"))

(define (natural-list? value)
  (and (list? value) (andmap exact-nonnegative-integer? value)))

(define (check-native-artifact rec)
  (check-typed rec 'artifact-key digest? "a SHA-256 artifact key")
  (check-typed rec 'interface exact-positive-integer? "a descriptor ABI")
  (check-typed rec 'state (lambda (value) (memq value '(ready miss)))
               "ready|miss")
  (check-typed rec 'paths
               (lambda (value) (and (pair? value) (andmap string? value)))
               "a nonempty path-hint list")
  (check-typed rec 'bytes nat-or-f? "a byte count or #f")
  (for ([key '(kernels variants native attachments)])
    (check-typed rec key exact-nonnegative-integer? "a natural")))

(define (check-native-artifact-kernel rec)
  (check-typed rec 'artifact-key digest? "a SHA-256 artifact key")
  (check-typed rec 'native-slot exact-nonnegative-integer? "a native slot")
  (check-typed rec 'plan-key digest? "a KernelExecPlan key")
  (for ([key '(frame-width variants attachments)])
    (check-typed rec key exact-nonnegative-integer? "a natural"))
  (for ([key '(native interpreted)])
    (check-typed rec key natural-list? "a variant-slot list")))

(define (check-executor-attachment rec)
  (for ([key '(scc attachment-slot variants)])
    (check-typed rec key exact-nonnegative-integer? "a natural"))
  (check-typed rec 'stratum string? "a stratum name")
  (check-typed rec 'plan-key digest? "a KernelExecPlan key")
  (check-typed rec 'artifact-key
               (lambda (value) (or (eq? value #f) (digest? value)))
               "an ArtifactKey or #f")
  (check-typed rec 'native-slot nat-or-f? "a native slot or #f")
  (check-typed rec 'tier (lambda (value) (memq value '(interpreted native mixed)))
               "interpreted|native|mixed")
  (for ([key '(native interpreted)])
    (check-typed rec key natural-list? "a variant-slot list"))
  (check-typed rec 'writes
               (lambda (value)
                 (and (list? value)
                      (andmap (lambda (write)
                                (and (list? write) (= (length write) 2)
                                     (string? (first write))
                                     (exact-nonnegative-integer? (second write))))
                              value)))
               "a (name VersionId) list")
  (check-typed rec 'reads
               (lambda (value) (and (list? value) (andmap string? value)))
               "a relation-name list"))

(define (check-program-materialization rec)
  (check-typed rec 'image-key digest? "a SHA-256 image key")
  (for ([key '(plan-slot kernel-ordinal variants artifact-attachments
                         interpreted-attachments)])
    (check-typed rec key exact-nonnegative-integer? "a natural"))
  (check-typed rec 'plan-key digest? "a KernelExecPlan key")
  (check-typed rec 'artifact-key
               (lambda (value) (or (eq? value #f) (digest? value)))
               "an ArtifactKey or #f")
  (check-typed rec 'cache-state (lambda (value) (memq value '(ready miss)))
               "ready|miss")
  (for ([key '(native interpreted)])
    (check-typed rec key natural-list? "a variant-slot list")))

(module+ main
  (define assertions (vector->list (current-command-line-arguments)))
  (define rels '())      ; every catalog-rel record seen
  (define types '())     ; every catalog-type record seen
  (define images '())    ; every sealed ProgramImage summary seen
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
        [(catalog-boundary)(check-boundary rec)
                           (set! in-stream (add1 in-stream))]
        [(catalog-program) (check-program rec)
                           (set! images (cons rec images))
                           (set! in-stream (add1 in-stream))]
        [(catalog-program-source) (check-program-source rec)
                                  (set! in-stream (add1 in-stream))]
        [(catalog-program-rule) (check-program-rule rec)
                                (set! in-stream (add1 in-stream))]
        [(catalog-program-kernel) (check-program-kernel rec)
                                  (set! in-stream (add1 in-stream))]
        [(catalog-program-plan) (check-program-plan rec)
                                (set! in-stream (add1 in-stream))]
        [(catalog-native-artifact) (check-native-artifact rec)
                                   (set! in-stream (add1 in-stream))]
        [(catalog-native-artifact-kernel) (check-native-artifact-kernel rec)
                                          (set! in-stream (add1 in-stream))]
        [(catalog-executor-attachment) (check-executor-attachment rec)
                                       (set! in-stream (add1 in-stream))]
        [(catalog-program-materialization) (check-program-materialization rec)
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
      [(regexp-match #px"^images>=([0-9]+)$" a)
       => (lambda (m)
            (unless (>= (length images) (string->number (second m)))
              (fail! "only ~a catalog-program records, wanted >= ~a"
                     (length images) (second m))))]
      [else (fail! "unknown assertion ~a" a)]))
  (printf "catalog-check: ok (~a rel, ~a type, ~a image records, ~a streams)\n"
          (length rels) (length types) (length images) streams))
