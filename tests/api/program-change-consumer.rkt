#lang racket

;; Independent RF5-B-side boundary consumer.  This module deliberately does
;; not import ProgramChangeSet or ProgramImage structs/codecs: it reads their
;; frozen wire values, verifies both content seals, checks the inventories at
;; the join, and projects only the runtime planning summary.

(provide consume-program-change-set read-consumer-datum)

(require racket/list
         racket/match
         "../../compiler/sha256.rkt")

(define byte-limit (* 64 1024 1024))
(define node-limit 2000000)
(define depth-limit 512)
(define content-key-rx #px"^[0-9a-f]{64}$")

(define (fail fmt . args)
  (error 'program-change-consumer (apply format fmt args)))

(define (digest datum)
  (bytes->hex-string
   (sha256
    (string->bytes/utf-8
     (with-output-to-string (lambda () (write datum)))))))

(define (content-key? value)
  (and (string? value) (regexp-match? content-key-rx value)))

(define (check-budget! datum)
  (define nodes 0)
  (define (walk value depth)
    (set! nodes (add1 nodes))
    (when (> nodes node-limit)
      (fail "artifact exceeds the ~a-node decoder limit" node-limit))
    (when (> depth depth-limit)
      (fail "artifact exceeds the ~a-level decoder limit" depth-limit))
    (cond
      [(list? value)
       (for ([item (in-list value)]) (walk item (add1 depth)))]
      [(pair? value)
       (walk (car value) (add1 depth))
       (walk (cdr value) (add1 depth))]
      [(vector? value)
       (for ([item (in-vector value)]) (walk item (add1 depth)))]
      [else (void)]))
  (walk datum 0))

(define (read-consumer-datum [in (current-input-port)])
  (define out (open-output-bytes))
  (let loop ([total 0])
    (define chunk (read-bytes 8192 in))
    (cond
      [(eof-object? chunk) (void)]
      [else
       (define next (+ total (bytes-length chunk)))
       (when (> next byte-limit)
         (fail "artifact exceeds the ~a-byte decoder limit" byte-limit))
       (write-bytes chunk out)
       (loop next)]))
  (define source (open-input-bytes (get-output-bytes out)))
  (define datum
    (parameterize ([read-accept-graph #f] [read-accept-reader #f])
      (read source)))
  (when (eof-object? datum) (fail "empty artifact"))
  (unless (eof-object?
           (parameterize ([read-accept-graph #f] [read-accept-reader #f])
             (read source)))
    (fail "trailing artifact data"))
  (check-budget! datum)
  datum)

(define (section fields expected)
  (unless (equal? (map car fields) expected)
    (fail "section shape mismatch: expected ~s, got ~s"
          expected (map car fields)))
  (for/hash ([field (in-list fields)])
    (values (car field) (cdr field))))

(define (canonical? records)
  (equal? records
          (sort (remove-duplicates records) string<?
                #:key (lambda (x)
                        (with-output-to-string (lambda () (write x)))))))

(define (check-lineage-coverage! records old-count new-count tag)
  (define old-slots '())
  (define new-slots '())
  (for ([record (in-list records)])
    (match record
      [`(,record-tag ,fields ...)
       (unless (eq? record-tag tag)
         (fail "unexpected ~a lineage record: ~s" tag record))
       (define table
         (for/hash ([field (in-list fields)])
           (match field
             [`(,name ,value) (values name value)]
             [_ (fail "malformed ~a lineage field: ~s" tag field)])))
       (define old
         (hash-ref table
                   (case tag
                     [(module) 'old-slot]
                     [(rule) 'old-slot]
                     [(relation) 'old-output-slot])))
       (define new
         (hash-ref table
                   (case tag
                     [(module) 'new-slot]
                     [(rule) 'new-slot]
                     [(relation) 'new-output-slot])))
       (when old (set! old-slots (cons old old-slots)))
       (when new (set! new-slots (cons new new-slots)))]
      [_ (fail "malformed ~a lineage record: ~s" tag record)]))
  (unless (and (equal? (sort old-slots <) (range old-count))
               (equal? (sort new-slots <) (range new-count)))
    (fail "~a lineage does not cover both image inventories" tag)))

(struct image-header
  (key compiler-key plan-abi model-key modules rules outputs)
  #:transparent)

(define (consume-image datum)
  (match datum
    [`(program-image (state sealed) (key ,key) ,fields ...)
     (unless (and (content-key? key)
                  (equal? key
                          (digest `(program-image-content ,@fields))))
       (fail "ProgramImage content seal mismatch"))
     (define table
       (section fields
                '(format compiler-key plan-abi model-key root-module
                         declarations modules sources rules dependencies
                         components component-edges cohorts)))
     (define (one tag)
       (match (hash-ref table tag)
         [(list value) value]
         [other (fail "malformed ProgramImage ~a field: ~s" tag other)]))
     (unless (= (one 'format) 1) (fail "unsupported ProgramImage format"))
     (define declarations (hash-ref table 'declarations))
     (define modules (hash-ref table 'modules))
     (define rules (hash-ref table 'rules))
     (define output-count
       (count (lambda (record)
                (match record
                  [`(declaration ,_ relation ,_ ,_) #t]
                  [_ #f]))
              declarations))
     (image-header key (one 'compiler-key) (one 'plan-abi) (one 'model-key)
                   (length modules) (length rules) output-count)]
    [_ (fail "not a sealed ProgramImage wire value")]))

(define (consume-program-change-set datum
                                    [base-image-datum #f]
                                    [candidate-image-datum #f])
  (match datum
    [`(program-change-set (state sealed) (key ,key)
       (format ,format)
       (base (program-instance ,base-program) (image-key ,base-key)
             (modules ,base-modules) (rules ,base-rules)
             (outputs ,base-outputs))
       (candidate (program-slot 0) (image-key ,candidate-key)
                  (modules ,candidate-modules) (rules ,candidate-rules)
                  (outputs ,candidate-outputs))
       (draft-revision ,draft-revision)
       (program-lineage ,program-lineage ...)
       (module-lineage ,module-lineage ...)
       (rule-lineage ,rule-lineage ...)
       (relation-slot-lineage ,relation-lineage ...)
       (source-diff ,source-fields ...)
       (semantic-diff ,semantic-fields ...)
       (execution-diff ,execution-fields ...)
       (requirements (compiler-key ,compiler-key) (plan-abi ,plan-abi)
                     (services ,required-services ...))
       (refusals ,refusals ...))
     (unless (and (= format 1)
                  (content-key? key) (content-key? base-key)
                  (content-key? candidate-key)
                  (exact-nonnegative-integer? draft-revision)
                  (andmap exact-nonnegative-integer?
                          (list base-modules base-rules base-outputs
                                candidate-modules candidate-rules
                                candidate-outputs)))
       (fail "malformed ProgramChangeSet header"))
     (unless (equal? program-lineage
                     `((replacement (old-program-instance ,base-program)
                                    (new-program-slot 0))))
       (fail "program replacement lineage disagrees with the header"))
     (unless (equal? key
                     (digest `(program-change-set-content ,@(cdddr datum))))
       (fail "ProgramChangeSet content seal mismatch"))
     (unless (and (canonical? module-lineage)
                  (canonical? rule-lineage)
                  (canonical? relation-lineage))
       (fail "non-canonical lineage"))
     (check-lineage-coverage! module-lineage
                              base-modules candidate-modules 'module)
     (check-lineage-coverage! rule-lineage base-rules candidate-rules 'rule)
     (check-lineage-coverage! relation-lineage
                              base-outputs candidate-outputs 'relation)
     (define source
       (section source-fields
                '(occurrences sources rules facts options homes bindings)))
     (define semantic
       (section semantic-fields
                '(old-model-key new-model-key declarations rules facts
                  bindings options edges-added edges-removed old-writers
                  new-writers old-components new-components
                  old-component-edges new-component-edges affected-roots
                  union-cone)))
     (unless (and (null? (hash-ref source 'options))
                  (null? (hash-ref semantic 'options)))
       (fail "ProgramChangeSet format 1 has no semantic option vocabulary"))
     (for ([record (in-list
                    (append (hash-ref semantic 'edges-added)
                            (hash-ref semantic 'edges-removed)))])
       (match record
         [`(dependency-change (from ,(? symbol?)) (to ,(? symbol?))
                              (kind ,kind) (old-count ,(? exact-nonnegative-integer?))
                              (new-count ,(? exact-nonnegative-integer?)))
          (unless (memq kind '(positive negative negative-wildcard co-head
                               derived oracle))
            (fail "unknown dependency kind: ~s" kind))]
         [_ (fail "malformed dependency change record: ~s" record)]))
     (define execution
       (section execution-fields
                '(old-plan-abi new-plan-abi cohort-changes old-kernels
                  new-kernels kernel-changes old-bindings new-bindings
                  services-added services-removed reusable-kernel-keys)))
     (for ([records (in-list
                     (append (hash-values source)
                             (hash-values semantic)
                             (hash-values execution)
                             (list required-services refusals)))])
       (unless (canonical? records)
         (fail "non-canonical diff or requirement records")))
     (unless (and (equal? (hash-ref execution 'old-plan-abi)
                          (list plan-abi))
                  (equal? (hash-ref execution 'new-plan-abi)
                          (list plan-abi)))
       (fail "Plan ABI requirement disagrees with execution diff"))
     (when (or (not base-image-datum) (not candidate-image-datum))
       (fail "both sealed ProgramImages are required at the RF5-B join"))
     (define base-image (consume-image base-image-datum))
     (define candidate-image (consume-image candidate-image-datum))
     (unless
         (and (equal? base-key (image-header-key base-image))
              (equal? candidate-key (image-header-key candidate-image))
              (= base-modules (image-header-modules base-image))
              (= candidate-modules (image-header-modules candidate-image))
              (= base-rules (image-header-rules base-image))
              (= candidate-rules (image-header-rules candidate-image))
              (= base-outputs (image-header-outputs base-image))
              (= candidate-outputs (image-header-outputs candidate-image))
              (equal? compiler-key
                      (image-header-compiler-key candidate-image))
              (= plan-abi (image-header-plan-abi base-image)
                          (image-header-plan-abi candidate-image))
              (equal? (hash-ref semantic 'old-model-key)
                      (list (image-header-model-key base-image)))
              (equal? (hash-ref semantic 'new-model-key)
                      (list (image-header-model-key candidate-image))))
       (fail "ProgramChangeSet inventory does not match its sealed images"))
     (define refusal-codes
       (for/list ([refusal (in-list refusals)])
         (match refusal
           [`(refusal (code ,code) (details ,_)) code]
           [_ (fail "malformed compiler refusal: ~s" refusal)])))
     (define reusable
       (for/list ([record (in-list
                           (hash-ref execution 'reusable-kernel-keys))])
         (match record
           [`(kernel-key ,kernel-key (reusable-count ,count))
            (list kernel-key count)]
           [_ (fail "malformed reusable kernel record: ~s" record)])))
     `(program-change-consumer
       (status ,(if (null? refusal-codes) 'ready 'refused))
       (change-key ,key)
       (base-image ,base-key)
       (candidate-image ,candidate-key)
       (base-program ,base-program)
       (module-lineage ,(length module-lineage))
       (rule-lineage ,(length rule-lineage))
       (relation-lineage ,(length relation-lineage))
       (affected-roots ,@(hash-ref semantic 'affected-roots))
       (union-cone ,@(hash-ref semantic 'union-cone))
       (reusable-kernel-keys ,@reusable)
       (required-services ,@required-services)
       (refusals ,@refusal-codes))]
    [_ (fail "not a sealed ProgramChangeSet wire value")]))

(module+ main
  (define argv (vector->list (current-command-line-arguments)))
  (unless (= (length argv) 2)
    (fail "usage: program-change-consumer.rkt BASE.pimg CANDIDATE.pimg"))
  (define change (read-consumer-datum))
  (define base
    (call-with-input-file (first argv) read-consumer-datum))
  (define candidate
    (call-with-input-file (second argv) read-consumer-datum))
  (pretty-write (consume-program-change-set change base candidate)))
