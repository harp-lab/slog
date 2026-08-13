#lang racket

;; RF2-A: a deterministic, sealed compiler-side ProgramImage package.
;;
;; This is the logical/container half of RF2.  It binds source closures,
;; lexical module occurrences, declarations, RF1.5 semantic graph queries,
;; and zero or more ABI-2 cohort plans into one content-addressed value.  It
;; deliberately contains only image-local slots: live ProgramInstanceKey,
;; ModuleInstanceKey, RuleKey, VersionKey, and compact daemon ids are allocated
;; by the activation/runtime side and never guessed here.

(provide
 program-image-format-version
 (struct-out image-declaration)
 (struct-out image-module)
 (struct-out image-source)
 (struct-out image-rule)
 (struct-out image-dependency)
 (struct-out image-component)
 (struct-out image-component-edge)
 (struct-out image-cohort)
 (struct-out program-image)
 seal-program-image
 validate-program-image!
 program-image->datum
 datum->program-image
 program-image->string
 write-program-image
 read-program-image
 program-image-rule-at
 program-image-module-at
 program-image-source-at
 program-image-rules-writing
 program-image-component-for-relation)

(require racket/list
         racket/set
         "ir-shared.rkt"
         "program-model.rkt"
         "sha256.rkt"
         "stratify.rkt"
         "utils.rkt")

(define program-image-format-version 1)
(define max-program-image-bytes (* 64 1024 1024))
(define max-program-image-nodes 2000000)
(define max-program-image-depth 512)

(struct image-declaration (slot namespace name value) #:transparent)
(struct image-module
  (slot parent ordinal entry-source home lexical-path bindings sources)
  #:transparent)
(struct image-source (slot module path digest tokens) #:transparent)
(struct image-rule
  (slot source-id module source origin fingerprint normalized
        heads positive negative negative-wildcard)
  #:transparent)
(struct image-dependency (from to kind rule-slot) #:transparent)
(struct image-component (slot members level) #:transparent)
(struct image-component-edge (from to kinds) #:transparent)
(struct image-cohort (slot digest plan) #:transparent)
(struct program-image
  (key format compiler-key plan-abi model-key root-module
       declarations modules sources rules dependencies
       components component-edges cohorts)
  #:transparent)

(define (sexp->string x)
  (with-output-to-string (lambda () (write x))))

(define (digest x)
  (bytes->hex-string (sha256 (string->bytes/utf-8 (sexp->string x)))))

(define (string-digest text)
  (bytes->hex-string (sha256 (string->bytes/utf-8 text))))

(define (datum-key x) (sexp->string x))

(define (content-key? x)
  (and (string? x) (regexp-match? #px"^[0-9a-f]{64}$" x)))

;; Keep the Racket reader on the same closed carrier as the independent C++
;; decoder.  Vectors, hashes, boxes, reader graphs, and opaque compiler values
;; are not ProgramImage wire data even when Racket itself can print them.
(define (closed-image-datum? x)
  (cond [(list? x) (andmap closed-image-datum? x)]
        [(pair? x) #f]
        [else (or (boolean? x) (number? x) (string? x) (symbol? x))]))

;; Hashes and sets are convenient compiler values but cannot cross the image
;; boundary with an implicit iteration order.  This closed canonical carrier
;; is also what declaration values use on disk.
(define (canonical-datum x)
  (cond
    [(set? x)
     `(set ,@(sort (map canonical-datum (set->list x)) string<? #:key datum-key))]
    [(hash? x)
     `(hash
       ,@(sort
          (for/list ([(k v) (in-hash x)])
            (list (canonical-datum k) (canonical-datum v)))
          string<? #:key (lambda (pair) (datum-key (first pair)))))]
    [(list? x) (map canonical-datum x)]
    [(pair? x)
     (error 'program-image "improper list is not image data: ~s" x)]
    [(path? x) (path->string x)]
    [else x]))

(define (canonical-token token)
  (match token
    [`(token ,tag (pos ,_path ,sl ,sc ,el ,ec) ,text)
     `(token ,tag (span ,sl ,sc ,el ,ec) ,text)]
    [_ (error 'program-image "malformed source token: ~s" token)]))

(define (occurrence-source-label path lexical-path)
  (cond
    [(null? lexical-path) path]
    [else
     (define-values (dir file _dir?) (split-path path))
     (define occurrence
       (string-join
        (for/list ([step (in-list lexical-path)])
          (format "~a#~a" (second step) (first step)))
        "."))
     (path->string
      (build-path (if (path? dir) dir (current-directory))
                  (format "~a@~a" occurrence file)))]))

(define (declaration-records type-env)
  (define sections
    (list (cons 'alias (type-env-aliases type-env))
          (cons 'relation (type-env-rels type-env))
          (cons 'function (type-env-funs type-env))))
  (for/list ([entry
              (in-list
               (sort
                (for*/list ([section (in-list sections)]
                            [(name value) (in-hash (cdr section))])
                  (list (car section) name (canonical-datum value)))
                string<? #:key datum-key))]
             [slot (in-naturals)])
    (image-declaration slot (first entry) (second entry) (third entry))))

(define (module-source-records program source-root)
  (define modules-by-occurrence
    (for/hash ([module (in-set (program-ir-modules program))])
      (values (list (module-ir-home module)
                    (module-ir-lexical-path module)
                    (module-ir-path module))
              module)))
  (define next-module 0)
  (define next-source 0)
  (define modules '())
  (define sources '())
  (define label->source (make-hash))

  (define (walk occurrence parent ordinal)
    (define module-slot next-module)
    (set! next-module (add1 next-module))
    (define source-slots
      (for/list ([path (in-list (module-occurrence-source-paths occurrence))])
        (define key
          (list (module-occurrence-home occurrence)
                (module-occurrence-lexical-path occurrence)
                path))
        (define module
          (hash-ref modules-by-occurrence key
                    (lambda ()
                      (error 'program-image
                             "occurrence source has no qualified module: ~s"
                             key))))
        (define source-slot next-source)
        (set! next-source (add1 next-source))
        (define tokens (map canonical-token (module-ir-tokens module)))
        (define record
          (image-source
           source-slot module-slot (source-name-key path source-root)
           (digest `(source-tokens ,@tokens)) tokens))
        (set! sources (cons record sources))
        (hash-set! label->source
                   (occurrence-source-label
                    path (module-occurrence-lexical-path occurrence))
                   source-slot)
        source-slot))
    (define entry-index
      (index-of (module-occurrence-source-paths occurrence)
                (module-occurrence-entry-path occurrence)))
    (unless entry-index
      (error 'program-image "module entry source is absent from its closure: ~s"
             (module-occurrence-entry-path occurrence)))
    (define bindings
      (sort (for/list ([binding (in-list (module-occurrence-bindings occurrence))])
              (canonical-datum binding))
            string<? #:key datum-key))
    (set! modules
          (cons
           (image-module
            module-slot parent ordinal (list-ref source-slots entry-index)
            (canonical-datum (module-occurrence-home occurrence))
            (canonical-datum (module-occurrence-lexical-path occurrence))
            bindings source-slots)
           modules))
    (for ([child (in-list (module-occurrence-children occurrence))]
          [child-ordinal (in-naturals)])
      (walk child module-slot child-ordinal)))

  (walk (program-ir-occurrence-tree program) #f 0)
  (values (sort modules < #:key image-module-slot)
          (sort sources < #:key image-source-slot)
          label->source))

(define (image-rule-records model sources label->source source-root)
  (define module-of-source
    (for/hash ([source (in-list sources)])
      (values (image-source-slot source) (image-source-module source))))
  (for/list ([rule (in-list (program-model-rules model))])
    (define source-key (program-rule-source-key rule))
    (define source-slot
      (and source-key (hash-ref label->source (first source-key) #f)))
    (define origin
      (match source-key
        [#f #f]
        [(list label line column)
         (if source-slot
             `(source ,source-slot ,line ,column)
             `(external ,(source-name-key label source-root) ,line ,column))]))
    (image-rule
     (program-rule-slot rule) (program-rule-source-id rule)
     (and source-slot (hash-ref module-of-source source-slot))
     source-slot origin
     (program-rule-fingerprint rule) (program-rule-normalized rule)
     (program-rule-heads rule) (program-rule-positive rule)
     (program-rule-negative rule) (program-rule-negative-wildcard rule))))

(define (image-dependency-records model)
  (for/list ([edge (in-list (program-model-dependency-edges model))])
    (image-dependency
     (program-edge-from edge) (program-edge-to edge)
     (program-edge-kind edge) (program-edge-rule-slot edge))))

(define (image-component-records model)
  (define components
    (for/list ([component (in-list (program-model-components model))]
               [slot (in-naturals)])
      (image-component slot (first component) (second component))))
  (define slot-of
    (for/hash ([component (in-list components)])
      (values (image-component-members component)
              (image-component-slot component))))
  ;; Component member names determine component slots, but once projected to
  ;; those dense slots the wire order is numeric.  Textual datum ordering puts
  ;; slot 10 before slot 2 and therefore rejected otherwise valid programs as
  ;; soon as their condensation reached eleven components.
  (define edges
    (sort
     (for/list ([edge (in-list (program-model-condensation-edges model))])
       (image-component-edge
        (hash-ref slot-of (first edge))
        (hash-ref slot-of (second edge))
        (third edge)))
     component-edge<?))
  (values components edges))

(define (component-edge<? left right)
  (define lf (image-component-edge-from left))
  (define rf (image-component-edge-from right))
  (define lt (image-component-edge-to left))
  (define rt (image-component-edge-to right))
  (or (< lf rf)
      (and (= lf rf)
           (or (< lt rt)
               (and (= lt rt)
                    (string<? (datum-key (image-component-edge-kinds left))
                              (datum-key
                               (image-component-edge-kinds right))))))))

(define (image-dependency<? left right)
  (define lf (image-dependency-from left))
  (define rf (image-dependency-from right))
  (define lt (image-dependency-to left))
  (define rt (image-dependency-to right))
  (define lk (image-dependency-kind left))
  (define rk (image-dependency-kind right))
  (define ls (image-dependency-rule-slot left))
  (define rs (image-dependency-rule-slot right))
  (cond [(not (eq? lf rf)) (symbol<? lf rf)]
        [(not (eq? lt rt)) (symbol<? lt rt)]
        [(not (eq? lk rk)) (symbol<? lk rk)]
        [(not ls) (and rs #t)]
        [(not rs) #f]
        [else (< ls rs)]))

(define (image-cohort-records plans plan-abi)
  (for/list ([plan (in-list plans)] [slot (in-naturals)])
    (match plan
      [`(kernel-cohort (abi ,abi) ,_ ...)
       (unless (= abi plan-abi)
         (error 'program-image
                "cohort ~a has Plan ABI ~a; image requires ~a"
                slot abi plan-abi))]
      [_ (error 'program-image "cohort ~a is not a Plan ABI 2 cohort: ~s"
                slot plan)])
    (image-cohort slot (digest plan) plan)))

(define (program-image-content-datum image)
  `(program-image-content
    (format ,(program-image-format image))
    (compiler-key ,(program-image-compiler-key image))
    (plan-abi ,(program-image-plan-abi image))
    (model-key ,(program-image-model-key image))
    (root-module ,(program-image-root-module image))
    (declarations
     ,@(for/list ([d (in-list (program-image-declarations image))])
         `(declaration ,(image-declaration-slot d)
                       ,(image-declaration-namespace d)
                       ,(image-declaration-name d)
                       ,(image-declaration-value d))))
    (modules
     ,@(for/list ([m (in-list (program-image-modules image))])
         `(module ,(image-module-slot m)
                  (parent ,(image-module-parent m))
                  (ordinal ,(image-module-ordinal m))
                  (entry-source ,(image-module-entry-source m))
                  (home ,(image-module-home m))
                  (lexical-path ,(image-module-lexical-path m))
                  (bindings ,@(image-module-bindings m))
                  (sources ,@(image-module-sources m)))))
    (sources
     ,@(for/list ([s (in-list (program-image-sources image))])
         `(source ,(image-source-slot s)
                  (module ,(image-source-module s))
                  (path ,(image-source-path s))
                  (digest ,(image-source-digest s))
                  (tokens ,@(image-source-tokens s)))))
    (rules
     ,@(for/list ([r (in-list (program-image-rules image))])
         `(rule ,(image-rule-slot r)
                (source-id ,(image-rule-source-id r))
                (module ,(image-rule-module r))
                (source ,(image-rule-source r))
                (origin ,(image-rule-origin r))
                (fingerprint ,(image-rule-fingerprint r))
                (normalized ,(image-rule-normalized r))
                (heads ,@(image-rule-heads r))
                (positive ,@(image-rule-positive r))
                (negative ,@(image-rule-negative r))
                (negative-wildcard ,@(image-rule-negative-wildcard r)))))
    (dependencies
     ,@(for/list ([d (in-list (program-image-dependencies image))])
         `(dependency ,(image-dependency-from d) ,(image-dependency-to d)
                      ,(image-dependency-kind d)
                      ,(image-dependency-rule-slot d))))
    (components
     ,@(for/list ([c (in-list (program-image-components image))])
         `(component ,(image-component-slot c)
                     (level ,(image-component-level c))
                     (members ,@(image-component-members c)))))
    (component-edges
     ,@(for/list ([e (in-list (program-image-component-edges image))])
         `(component-edge ,(image-component-edge-from e)
                          ,(image-component-edge-to e)
                          ,@(image-component-edge-kinds e))))
    (cohorts
     ,@(for/list ([c (in-list (program-image-cohorts image))])
         `(cohort ,(image-cohort-slot c)
                  (digest ,(image-cohort-digest c))
                  (plan ,(image-cohort-plan c)))))))

(define (program-image->datum image)
  (define content (program-image-content-datum image))
  `(program-image (state sealed) (key ,(program-image-key image))
                  ,@(cdr content)))

(define (seal-program-image program type-env model
                            #:compiler-key compiler-key
                            #:plan-abi [plan-abi 2]
                            #:cohorts [plans '()]
                            #:source-root [source-root (current-directory)])
  (unless (and (string? compiler-key) (positive? (string-length compiler-key)))
    (raise-argument-error 'seal-program-image "non-empty string?" compiler-key))
  (define declarations (declaration-records type-env))
  (define-values (modules sources label->source)
    (module-source-records program source-root))
  (define rules
    (image-rule-records model sources label->source source-root))
  (define dependencies (image-dependency-records model))
  (define-values (components component-edges)
    (image-component-records model))
  (define cohorts (image-cohort-records plans plan-abi))
  (define provisional
    (program-image
     #f program-image-format-version compiler-key plan-abi
     (program-model-fingerprint model) 0
     declarations modules sources rules dependencies
     components component-edges cohorts))
  (define sealed
    (struct-copy program-image provisional
                 [key (digest (program-image-content-datum provisional))]))
  (validate-program-image! sealed)
  sealed)

(define (image-fail fmt . args)
  (error 'program-image (apply format fmt args)))

(define (read-bounded-image-datum in)
  (define out (open-output-bytes))
  (let loop ([total 0])
    (define chunk (read-bytes 8192 in))
    (cond
      [(eof-object? chunk) (void)]
      [else
       (define next (+ total (bytes-length chunk)))
       (when (> next max-program-image-bytes)
         (image-fail "ProgramImage exceeds the ~a-byte decoder limit"
                     max-program-image-bytes))
       (write-bytes chunk out)
       (loop next)]))
  (define bounded-in (open-input-bytes (get-output-bytes out)))
  (define datum
    (parameterize ([read-accept-graph #f]
                   [read-accept-reader #f])
      (read bounded-in)))
  (when (eof-object? datum) (image-fail "empty ProgramImage stream"))
  (unless (eof-object?
           (parameterize ([read-accept-graph #f]
                          [read-accept-reader #f])
             (read bounded-in)))
    (image-fail "trailing data after ProgramImage"))
  datum)

(define (check-image-datum-budget! datum)
  (define nodes 0)
  (define (walk value depth)
    (set! nodes (add1 nodes))
    (when (> nodes max-program-image-nodes)
      (image-fail "ProgramImage exceeds the ~a-node decoder limit"
                  max-program-image-nodes))
    (when (> depth max-program-image-depth)
      (image-fail "ProgramImage exceeds the ~a-level decoder limit"
                  max-program-image-depth))
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

(define (check-dense who records slot-of)
  (for ([record (in-list records)] [expected (in-naturals)])
    (unless (= (slot-of record) expected)
      (image-fail "~a slots are not dense: expected ~a, got ~a"
                  who expected (slot-of record)))))

(define (in-range? n count)
  (and (exact-nonnegative-integer? n) (< n count)))

(define (validate-program-image! image)
  (unless (program-image? image)
    (raise-argument-error 'validate-program-image! "program-image?" image))
  (unless (= (program-image-format image) program-image-format-version)
    (image-fail "unsupported format version ~s (reader supports ~s)"
                (program-image-format image) program-image-format-version))
  (unless (= (program-image-plan-abi image) 2)
    (image-fail "unsupported Plan ABI ~s" (program-image-plan-abi image)))
  (unless (and (content-key? (program-image-key image))
               (content-key? (program-image-model-key image))
               (string? (program-image-compiler-key image))
               (positive? (string-length
                           (program-image-compiler-key image))))
    (image-fail "malformed ProgramImage identity"))
  (unless (equal? (program-image-key image)
                  (digest (program-image-content-datum image)))
    (image-fail "image key does not match the sealed content"))

  (define declarations (program-image-declarations image))
  (define modules (program-image-modules image))
  (define sources (program-image-sources image))
  (define rules (program-image-rules image))
  (define dependencies (program-image-dependencies image))
  (define components (program-image-components image))
  (define component-edges (program-image-component-edges image))
  (define cohorts (program-image-cohorts image))
  (check-dense 'declaration declarations image-declaration-slot)
  (check-dense 'module modules image-module-slot)
  (check-dense 'source sources image-source-slot)
  (check-dense 'rule rules image-rule-slot)
  (check-dense 'component components image-component-slot)
  (check-dense 'cohort cohorts image-cohort-slot)

  (unless (in-range? (program-image-root-module image) (length modules))
    (image-fail "root module slot is out of range: ~s"
                (program-image-root-module image)))
  (define declaration-keys
    (for/list ([d (in-list declarations)])
      (unless (and (memq (image-declaration-namespace d)
                         '(alias relation function))
                   (symbol? (image-declaration-name d))
                   (closed-image-datum? (image-declaration-value d))
                   (equal? (image-declaration-value d)
                           (canonical-datum (image-declaration-value d))))
        (image-fail "declaration ~a is not canonically encoded"
                    (image-declaration-slot d)))
      (list (image-declaration-namespace d) (image-declaration-name d))))
  (unless
      (equal?
       declarations
       (sort declarations string<?
             #:key (lambda (d)
                     (datum-key
                      (list (image-declaration-namespace d)
                            (image-declaration-name d)
                            (image-declaration-value d))))))
    (image-fail "declarations are not in canonical order"))
  (unless (= (length declaration-keys)
             (length (remove-duplicates declaration-keys)))
    (image-fail "duplicate declaration key"))

  (for ([source (in-list sources)])
    (unless (and (in-range? (image-source-module source) (length modules))
                 (string? (image-source-path source))
                 (content-key? (image-source-digest source)))
      (image-fail "source ~a has an out-of-range module slot"
                  (image-source-slot source)))
    (unless (equal? (image-source-digest source)
                    (digest `(source-tokens ,@(image-source-tokens source))))
      (image-fail "source ~a digest mismatch" (image-source-slot source)))
    (for ([token (in-list (image-source-tokens source))])
      (match token
        [`(token ,(? symbol?) (span ,(? exact-nonnegative-integer?)
                          ,(? exact-nonnegative-integer?)
                          ,(? exact-nonnegative-integer?)
                          ,(? exact-nonnegative-integer?))
                 ,(? string?))
         (void)]
        [_ (image-fail "source ~a has a malformed canonical token: ~s"
                       (image-source-slot source) token)])))
  (define child-ordinals (make-hash))
  (define children (make-hash))
  (for ([module (in-list modules)])
    (define slot (image-module-slot module))
    (define parent (image-module-parent module))
    (unless (if (= slot (program-image-root-module image))
                (not parent)
                (and (in-range? parent (length modules)) (< parent slot)))
      (image-fail "module ~a has an invalid parent ~s" slot parent))
    (if parent
        (begin
          (hash-update! child-ordinals parent
                        (lambda (ordinals)
                          (cons (image-module-ordinal module) ordinals))
                        '())
          (hash-update! children parent
                        (lambda (child-slots) (cons slot child-slots)) '()))
        (unless (= (image-module-ordinal module) 0)
          (image-fail "root module ordinal must be zero")))
    (unless (and (exact-nonnegative-integer?
                  (image-module-ordinal module))
                 (closed-image-datum? (image-module-home module))
                 (closed-image-datum? (image-module-lexical-path module))
                 (andmap closed-image-datum?
                         (image-module-bindings module))
                 (equal? (image-module-bindings module)
                         (sort (image-module-bindings module)
                               string<? #:key datum-key)))
      (image-fail "module ~a bindings are not in canonical order" slot))
    (unless (and (member (image-module-entry-source module)
                         (image-module-sources module))
                 (andmap (lambda (source-slot)
                           (and (in-range? source-slot (length sources))
                                (= (image-source-module
                                    (list-ref sources source-slot))
                                   slot)))
                         (image-module-sources module)))
      (image-fail "module ~a has an invalid source closure" slot)))
  (for ([(parent ordinals) (in-hash child-ordinals)])
    (unless (equal? (sort ordinals <) (range (length ordinals)))
      (image-fail "module ~a child ordinals are not dense" parent)))
  (define (preorder slot)
    (cons
     slot
     (append*
      (for/list ([child
                  (in-list
                   (sort (hash-ref children slot '()) <
                         #:key (lambda (child-slot)
                                 (image-module-ordinal
                                  (list-ref modules child-slot)))))])
        (preorder child)))))
  (unless (equal? (preorder (program-image-root-module image))
                  (range (length modules)))
    (image-fail "module slots are not in canonical preorder"))
  (unless (equal? (append* (map image-module-sources modules))
                  (range (length sources)))
    (image-fail "source slots do not follow canonical module/source order"))

  (for ([rule (in-list rules)])
    (unless (and (exact-nonnegative-integer? (image-rule-source-id rule))
                 (content-key? (image-rule-fingerprint rule))
                 (string? (image-rule-normalized rule))
                 (pair? (image-rule-heads rule))
                 (closed-image-datum? (image-rule-origin rule))
                 (equal? (image-rule-fingerprint rule)
                         (string-digest (image-rule-normalized rule))))
      (image-fail "rule ~a fingerprint mismatch" (image-rule-slot rule)))
    (for ([relations (in-list
                      (list (image-rule-heads rule)
                            (image-rule-positive rule)
                            (image-rule-negative rule)
                            (image-rule-negative-wildcard rule)))])
      (unless (and (andmap symbol? relations)
                   (equal? relations
                           (sort (remove-duplicates relations) symbol<?)))
        (image-fail "rule ~a relation sets are not canonical"
                    (image-rule-slot rule))))
    (match* ((image-rule-module rule) (image-rule-source rule))
      [(#f #f) (void)]
      [((? exact-nonnegative-integer? module-slot)
        (? exact-nonnegative-integer? source-slot))
       (unless (and (in-range? source-slot (length sources))
                    (= module-slot
                       (image-source-module (list-ref sources source-slot))))
         (image-fail "rule ~a source/module mismatch" (image-rule-slot rule)))
       (match (image-rule-origin rule)
         [`(source ,origin-slot ,(? exact-nonnegative-integer?)
                   ,(? exact-nonnegative-integer?))
          (unless (= origin-slot source-slot)
            (image-fail "rule ~a origin/source mismatch"
                        (image-rule-slot rule)))]
         [_ (image-fail "rule ~a has a malformed source origin"
                        (image-rule-slot rule))])]
      [(_ _) (image-fail "rule ~a has a partial source binding"
                         (image-rule-slot rule))]))
  (unless
      (equal?
       rules
       (sort rules
             (lambda (a b)
               (define na (image-rule-normalized a))
               (define nb (image-rule-normalized b))
               (or (string<? na nb)
                   (and (string=? na nb)
                        (< (image-rule-source-id a)
                           (image-rule-source-id b)))))))
    (image-fail "rules are not in canonical semantic order"))

  (define relation-members
    (append* (map image-component-members components)))
  (for ([component (in-list components)])
    (unless (and (pair? (image-component-members component))
                 (equal? (image-component-members component)
                         (sort (remove-duplicates
                                (image-component-members component))
                               symbol<?))
                 (exact-nonnegative-integer? (image-component-level component)))
      (image-fail "component ~a is not canonical"
                  (image-component-slot component))))
  (unless (= (length relation-members)
             (length (remove-duplicates relation-members)))
    (image-fail "a relation belongs to more than one component"))
  (unless
      (equal? components
              (sort components string<?
                    #:key (lambda (component)
                            (datum-key (image-component-members component)))))
    (image-fail "components are not in canonical member order"))
  (define relation-set (list->set relation-members))
  (define (rule-at slot) (list-ref rules slot))
  (unless
      (equal?
       dependencies
       (sort dependencies image-dependency<?))
    (image-fail "dependencies are not in canonical order"))
  (unless (= (length dependencies) (length (remove-duplicates dependencies)))
    (image-fail "duplicate dependency record"))
  (for ([edge (in-list dependencies)])
    (unless (and (set-member? relation-set (image-dependency-from edge))
                 (set-member? relation-set (image-dependency-to edge)))
      (image-fail "dependency endpoint is absent from the component partition: ~s"
                  edge))
    (define rule-slot (image-dependency-rule-slot edge))
    (case (image-dependency-kind edge)
      [(derived oracle)
       (when rule-slot
         (image-fail "side-channel dependency names a rule slot"))]
      [(positive negative negative-wildcard co-head)
       (unless (in-range? rule-slot (length rules))
         (image-fail "dependency has an invalid rule slot: ~s" edge))
       (define rule (rule-at rule-slot))
       (unless
           (case (image-dependency-kind edge)
             [(positive)
              (and (member (image-dependency-from edge)
                           (image-rule-positive rule))
                   (member (image-dependency-to edge) (image-rule-heads rule)))]
             [(negative)
              (and (member (image-dependency-from edge)
                           (image-rule-negative rule))
                   (not (member (image-dependency-from edge)
                                (image-rule-negative-wildcard rule)))
                   (member (image-dependency-to edge) (image-rule-heads rule)))]
             [(negative-wildcard)
              (and (member (image-dependency-from edge)
                           (image-rule-negative-wildcard rule))
                   (member (image-dependency-to edge) (image-rule-heads rule)))]
             [(co-head)
              (and (not (eq? (image-dependency-from edge)
                             (image-dependency-to edge)))
                   (member (image-dependency-from edge) (image-rule-heads rule))
                   (member (image-dependency-to edge) (image-rule-heads rule)))])
         (image-fail "dependency does not agree with rule ~a: ~s" rule-slot edge))]
      [else (image-fail "unknown dependency kind: ~s"
                        (image-dependency-kind edge))]))

  ;; Recompute SCCs from the serialized graph.  Component slots are local and
  ;; may differ from Tarjan ids; member sets are the semantic comparison.
  (define succ-map
    (for/fold ([h (hash)]) ([edge (in-list dependencies)])
      (hash-update h (image-dependency-from edge)
                   (lambda (xs) (cons (image-dependency-to edge) xs)) '())))
  (define sorted-relations (sort relation-members symbol<?))
  (define computed-scc
    (tarjan-scc-ids sorted-relations
                    (lambda (rel)
                      (sort (remove-duplicates (hash-ref succ-map rel '()))
                            symbol<?))))
  (define computed-members
    (for/fold ([h (hash)]) ([rel (in-list sorted-relations)])
      (hash-update h (hash-ref computed-scc rel)
                   (lambda (members) (cons rel members)) '())))
  (define expected-components
    (sort (map image-component-members components) string<? #:key datum-key))
  (define actual-components
    (sort (for/list ([members (in-hash-values computed-members)])
            (sort members symbol<?))
          string<? #:key datum-key))
  (unless (equal? expected-components actual-components)
    (image-fail "component partition does not match the dependency graph"))

  (define component-of
    (for*/hash ([component (in-list components)]
                [rel (in-list (image-component-members component))])
      (values rel (image-component-slot component))))
  (define computed-component-edges
    (for/fold ([h (hash)]) ([edge (in-list dependencies)]
                            #:unless (= (hash-ref component-of
                                                  (image-dependency-from edge))
                                        (hash-ref component-of
                                                  (image-dependency-to edge))))
      (define key
        (list (hash-ref component-of (image-dependency-from edge))
              (hash-ref component-of (image-dependency-to edge))))
      (hash-update h key
                   (lambda (kinds) (set-add kinds (image-dependency-kind edge)))
                   (set))))
  (define expected-component-edges
    (sort
     (for/list ([edge (in-list component-edges)])
       (list (image-component-edge-from edge)
             (image-component-edge-to edge)
             (sort (image-component-edge-kinds edge) symbol<?)))
     string<? #:key datum-key))
  (unless
      (equal?
       component-edges
       (sort component-edges component-edge<?))
    (image-fail "component edges are not in canonical order"))
  (define actual-component-edges
    (sort
     (for/list ([(pair kinds) (in-hash computed-component-edges)])
       (list (first pair) (second pair) (sort (set->list kinds) symbol<?)))
     string<? #:key datum-key))
  (unless (equal? expected-component-edges actual-component-edges)
    (image-fail "component edges do not match the dependency graph"))
  (define predecessors
    (for/fold ([h (hash)]) ([edge (in-list component-edges)])
      (unless (and (in-range? (image-component-edge-from edge)
                              (length components))
                   (in-range? (image-component-edge-to edge)
                              (length components))
                   (not (= (image-component-edge-from edge)
                           (image-component-edge-to edge))))
        (image-fail "invalid component edge slots: ~s" edge))
      (hash-update h (image-component-edge-to edge)
                   (lambda (preds)
                     (set-add preds (image-component-edge-from edge)))
                   (set))))
  (define level-memo (make-hash))
  (define (computed-level slot)
    (hash-ref! level-memo slot
               (lambda ()
                 (add1
                  (for/fold ([highest -1])
                            ([pred (in-set (hash-ref predecessors slot (set)))])
                    (max highest (computed-level pred)))))))
  (for ([component (in-list components)])
    (unless (= (image-component-level component)
               (computed-level (image-component-slot component)))
      (image-fail "component ~a level mismatch"
                  (image-component-slot component))))

  (define derived-edges
    (for/list ([edge (in-list dependencies)]
               #:when (memq (image-dependency-kind edge) '(derived oracle)))
      (if (eq? (image-dependency-kind edge) 'derived)
          (cons (image-dependency-from edge) (image-dependency-to edge))
          (list (image-dependency-from edge) (image-dependency-to edge)
                'oracle))))
  (unless
      (equal? (program-image-model-key image)
              (program-model-content-fingerprint
               (map image-rule-normalized rules) derived-edges))
    (image-fail "ProgramModel fingerprint mismatch"))
  (define executable-components '())
  (define executable-manifest? #f)
  (for ([cohort (in-list cohorts)])
    (unless (closed-image-datum? (image-cohort-plan cohort))
      (image-fail "cohort ~a contains a non-wire value"
                  (image-cohort-slot cohort)))
    (unless (equal? (image-cohort-digest cohort)
                    (digest (image-cohort-plan cohort)))
      (image-fail "cohort ~a digest mismatch" (image-cohort-slot cohort)))
    (match (image-cohort-plan cohort)
      [`(kernel-cohort (abi ,abi) (flavor ,(? symbol?))
                       (attachments ,_attachments ...)
                       (declarations ,_declarations ...)
                       (dynamic ,_dynamic ...)
                       (manifest ,manifest ...)
                       ,kernel-forms ...)
       (unless (= abi (program-image-plan-abi image))
         (image-fail "cohort ~a Plan ABI mismatch" (image-cohort-slot cohort)))
       (unless (= (length manifest) (length kernel-forms))
         (image-fail "cohort ~a manifest/kernel coverage mismatch"
                     (image-cohort-slot cohort)))
       (when (pair? manifest) (set! executable-manifest? #t))
       (define exec-by-ordinal
         (for/hash ([form (in-list kernel-forms)])
           (match form
             [`(kernel (ord ,(? exact-nonnegative-integer? ord))
                       ,_exec (binding ,_ ...) (dynamic ,_ ...) (debug ,_ ...))
              (values ord form)]
             [_ (image-fail "cohort ~a has a malformed executable kernel"
                            (image-cohort-slot cohort))])))
       (unless (= (hash-count exec-by-ordinal) (length kernel-forms))
         (image-fail "cohort ~a has duplicate executable kernel ordinals"
                     (image-cohort-slot cohort)))
       (for ([entry (in-list manifest)] [expected (in-naturals)])
         (define-values (ord key members prelude? rule-count)
           (match entry
             [`(kernel (ord ,(? exact-nonnegative-integer? ord))
                       (key ,(? string? key)) (members ,members ...)
                       (rules ,(? exact-nonnegative-integer? count)))
              (values ord key members #f count)]
             [`(kernel (ord ,(? exact-nonnegative-integer? ord))
                       (key ,(? string? key)) (members ,members ...)
                       (prelude #t)
                       (rules ,(? exact-nonnegative-integer? count)))
              (values ord key members #t count)]
             [_ (image-fail "cohort ~a has a malformed manifest kernel: ~s"
                            (image-cohort-slot cohort) entry)]))
         (unless (= ord expected)
           (image-fail "cohort ~a manifest kernel slots are not dense"
                       (image-cohort-slot cohort)))
         (unless (and (andmap symbol? members)
                      (equal? members
                              (sort (remove-duplicates members) symbol<?))
                      (if prelude? (null? members) (pair? members)))
           (image-fail "cohort ~a kernel ~a member/prelude shape is invalid"
                       (image-cohort-slot cohort) ord))
         (define form
           (hash-ref exec-by-ordinal ord
                     (lambda ()
                       (image-fail "cohort ~a manifest kernel ~a is absent"
                                   (image-cohort-slot cohort) ord))))
         (match-define
           `(kernel (ord ,_) ,exec (binding ,_ ...) (dynamic ,_ ...)
                    (debug ,_ ...))
           form)
         (unless (equal? key (digest exec))
           (image-fail "cohort ~a kernel ~a execution key mismatch"
                       (image-cohort-slot cohort) ord))
         (define rules-field
           (and (list? exec) (assq 'rules (cdr exec))))
         (unless (and rules-field (= (sub1 (length rules-field)) rule-count))
           (image-fail "cohort ~a kernel ~a rule count mismatch"
                       (image-cohort-slot cohort) ord))
         (unless prelude?
           (set! executable-components (cons members executable-components))))]
      [_ (image-fail "cohort ~a is not a kernel cohort"
                     (image-cohort-slot cohort))]))
  ;; Plan-free and deliberately empty-manifest images remain valid for RF2
  ;; introspection.  Once an image carries executable kernels, however, its
  ;; non-prelude manifests must cover exactly the sealed semantic SCC view.
  (when executable-manifest?
    (define written-relations
      (list->set (append* (map image-rule-heads rules))))
    (define executable-model-components
      (for/list ([component (in-list components)]
                 #:when (for/or ([member
                                  (in-list
                                   (image-component-members component))])
                          (set-member? written-relations member)))
        (image-component-members component)))
    (unless
        (equal? (sort executable-components string<? #:key datum-key)
                (sort executable-model-components
                      string<? #:key datum-key))
      (image-fail "executable manifests do not match ProgramModel components")))
  image)

;; ----------------------------------------------------------------------
;; Explicit wire codec.  The reader accepts only this versioned shape and
;; validates the whole object before returning it; a parsed draft is never a
;; partially trusted image.

(define (datum->program-image datum)
  (define image
    (match datum
      [`(program-image (state sealed) (key ,key)
                       (format ,format-version)
                       (compiler-key ,compiler-key)
                       (plan-abi ,plan-abi)
                       (model-key ,model-key)
                       (root-module ,root-module)
                       (declarations ,declarations ...)
                       (modules ,modules ...)
                       (sources ,sources ...)
                       (rules ,rules ...)
                       (dependencies ,dependencies ...)
                       (components ,components ...)
                       (component-edges ,component-edges ...)
                       (cohorts ,cohorts ...))
       (program-image
        key format-version compiler-key plan-abi model-key root-module
        (for/list ([d (in-list declarations)])
          (match d
            [`(declaration ,slot ,namespace ,name ,value)
             (image-declaration slot namespace name value)]
            [_ (image-fail "malformed declaration record: ~s" d)]))
        (for/list ([m (in-list modules)])
          (match m
            [`(module ,slot (parent ,parent) (ordinal ,ordinal)
                      (entry-source ,entry-source) (home ,home)
                      (lexical-path ,lexical-path) (bindings ,bindings ...)
                      (sources ,source-slots ...))
             (image-module slot parent ordinal entry-source home lexical-path
                           bindings source-slots)]
            [_ (image-fail "malformed module record: ~s" m)]))
        (for/list ([s (in-list sources)])
          (match s
            [`(source ,slot (module ,module) (path ,path) (digest ,digest)
                      (tokens ,tokens ...))
             (image-source slot module path digest tokens)]
            [_ (image-fail "malformed source record: ~s" s)]))
        (for/list ([r (in-list rules)])
          (match r
            [`(rule ,slot (source-id ,source-id) (module ,module)
                    (source ,source) (origin ,origin)
                    (fingerprint ,fingerprint) (normalized ,normalized)
                    (heads ,heads ...) (positive ,positive ...)
                    (negative ,negative ...)
                    (negative-wildcard ,negative-wildcard ...))
             (image-rule slot source-id module source origin fingerprint normalized
                         heads positive negative negative-wildcard)]
            [_ (image-fail "malformed rule record: ~s" r)]))
        (for/list ([d (in-list dependencies)])
          (match d
            [`(dependency ,from ,to ,kind ,rule-slot)
             (image-dependency from to kind rule-slot)]
            [_ (image-fail "malformed dependency record: ~s" d)]))
        (for/list ([c (in-list components)])
          (match c
            [`(component ,slot (level ,level) (members ,members ...))
             (image-component slot members level)]
            [_ (image-fail "malformed component record: ~s" c)]))
        (for/list ([e (in-list component-edges)])
          (match e
            [`(component-edge ,from ,to ,kinds ...)
             (image-component-edge from to kinds)]
            [_ (image-fail "malformed component edge: ~s" e)]))
        (for/list ([c (in-list cohorts)])
          (match c
            [`(cohort ,slot (digest ,digest) (plan ,plan))
             (image-cohort slot digest plan)]
            [_ (image-fail "malformed cohort record: ~s" c)])))]
      [_ (image-fail "not a sealed ProgramImage datum")]))
  (validate-program-image! image))

(define (program-image->string image)
  (with-output-to-string
    (lambda () (pretty-write (program-image->datum image)))))

(define (write-program-image image [out (current-output-port)])
  (validate-program-image! image)
  (pretty-write (program-image->datum image) out))

(define (read-program-image [in (current-input-port)])
  (define datum (read-bounded-image-datum in))
  (check-image-datum-budget! datum)
  (datum->program-image datum))

;; Read-only introspection queries.  They return immutable image records and
;; never expose a mutation path into an active task graph.
(define (program-image-rule-at image slot)
  (unless (in-range? slot (length (program-image-rules image)))
    (image-fail "rule slot is out of range: ~s" slot))
  (list-ref (program-image-rules image) slot))

(define (program-image-module-at image slot)
  (unless (in-range? slot (length (program-image-modules image)))
    (image-fail "module slot is out of range: ~s" slot))
  (list-ref (program-image-modules image) slot))

(define (program-image-source-at image slot)
  (unless (in-range? slot (length (program-image-sources image)))
    (image-fail "source slot is out of range: ~s" slot))
  (list-ref (program-image-sources image) slot))

(define (program-image-rules-writing image relation)
  (filter (lambda (rule) (member relation (image-rule-heads rule)))
          (program-image-rules image)))

(define (program-image-component-for-relation image relation)
  (for/first ([component (in-list (program-image-components image))]
              #:when (member relation (image-component-members component)))
    component))
