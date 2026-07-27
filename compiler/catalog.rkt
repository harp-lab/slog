#lang racket

;; Logical declaration catalogs and pure boundary planning
;; (docs/modules.md §3.1, §6.4, §8.5.1; N2).
;;
;; This module deliberately has no daemon or session dependency.  A caller
;; supplies immutable recipe identity inputs (LayerId and event numbers), and
;; receives one immutable BoundaryPlan.  Validation happens before any key is
;; exposed, so an incompatible program cannot partly allocate a boundary.
;;
;; The current compiler still lowers QNames to symbols in its middle end.
;; Catalogs immediately recover the structured QName through names.rkt and
;; never split or join components themselves.

(provide
 (struct-out type-ref)
 (struct-out lattice-descriptor)
 (struct-out declaration-descriptor)
 (struct-out catalog-delta)
 (struct-out catalog)
 (struct-out boundary)
 (struct-out boundary-action)
 (struct-out boundary-plan)
 (struct-out module-instance-descriptor)
 (struct-out exn:fail:catalog)
 empty-catalog
 empty-boundary
 storage-declaration?
 declaration-references
 type-env->catalog-delta
 plan-boundary
 replay-boundary-plan
 module-instance-key
 module-occurrence-instances
 module-instance-descriptor->datum
 module-instance-descriptor-datum?
 (struct-out transform-plan)
 plan-path-transform
 replay-path-transform
 transform-plan->datum
 transform-plan-datum?
 qname-inside?
 boundary-plan->datum
 boundary-plan-datum?
 declaration-descriptor->datum
 datum->declaration-descriptor
 catalog-delta->datum
 datum->catalog-delta
 boundary->datum
 datum->boundary
 ;; N4-A durable boundary bundle
 slog-boundary-bundle-format
 (struct-out boundary-record)
 (struct-out version-record)
 (struct-out type-record)
 (struct-out program-record)
 (struct-out boundary-bundle)
 boundary-bundle->datum
 datum->boundary-bundle
 boundary-bundle-datum?
 validate-boundary-bundle
 boundary-bundle-cut-history
 plan-bundle-restore
 boundary-bundle-type-key->sid
 plan-clause              ; read one clause of a persisted plan datum
 ;; N4-B mapped namespace attachment
 (struct-out attachment-plan)
 attachment-plan-boundary-key
 attachment-plan-output
 plan-attachment
 attachment-plan->datum
 attachment-plan-datum?
 replay-attachment
 catalog->manifest
 catalog->type-env
 catalog-delta->manifest
 type-env->legacy-manifest
 merge-legacy-manifest)

(require racket/list
         racket/set
         "ir-shared.rkt"
         "names.rkt")

;; A field type is either a primitive runtime type or a reference to one
;; declaration node.  Collection/lattice expressions live on their own
;; declaration descriptors, so references remain simple and recursive graphs
;; compare by exact qualified node name.
(struct type-ref (kind value) #:transparent)

;; Canonical lattice expression.  `arguments` contains TypeRefs and, for map,
;; one nested lattice-descriptor.  `parameters` is an ordered list of
;; (parameter . literal) pairs.
(struct lattice-descriptor (kind arguments parameters) #:transparent)

;; Kinds:
;;   table, struct  -- fields are exact TypeRefs
;;   enum, union    -- node declarations; union edges are catalog memberships
;;   lattice       -- lattice-spec contains its normalized expression
;;   list, map      -- fields carry their element or key/value TypeRefs
;;
;; A lattice table also carries its normalized lattice expression directly.
;; This makes its storage ABI projection local while the referenced lattice
;; declaration remains part of the complete field graph.
(struct declaration-descriptor (name kind fields lattice-spec) #:transparent)

;; A CatalogDelta is a set of declaration assertions and additive membership
;; assertions.  modules.rkt emits the complete program assertion set; a
;; BoundaryPlan contains only the assertions absent from its input catalog.
(struct catalog-delta (declarations memberships) #:transparent)

;; `nominals` maps struct QNames to stable TypeKeys.
(struct catalog (declarations memberships nominals) #:transparent)

;; A boundary is the public catalog plus its materialized name environment.
;; `environment` maps every table/struct QName to a stable VersionKey.
(struct boundary (key catalog environment) #:transparent)

;; kind = retain | create.  A fresh declaration has no predecessor; a written
;; existing declaration names its input VersionKey as predecessor.
(struct boundary-action (kind name version-key predecessor type-key)
  #:transparent)

;; Slot hashes are persisted allocation tables, not recipes to recompute after
;; publication.  They contain only keys minted by this boundary.
(struct boundary-plan
  (layer-id program-event boundary-event type-event
   program-key boundary-key input output delta actions version-slots type-slots)
  #:transparent)

;; A lexical module occurrence receives its stable key only after the
;; enclosing boundary planner has minted (or replayed) the ProgramInstanceKey.
;; Source paths and aliases remain metadata; the key uses only the persisted
;; program key and deterministic occurrence slots.
(struct module-instance-descriptor
  (key home lexical-path bindings)
  #:transparent)

(define (module-instance-key program-key lexical-path)
  (unless (string? program-key)
    (catalog-fail 'invalid-key
                  "module instance needs a ProgramInstanceKey string"))
  (define slots
    (for/list ([step (in-list lexical-path)])
      (match step
        [(list (? exact-nonnegative-integer? slot) (? string? _alias))
         slot]
        [_ (catalog-fail 'invalid-key
                         "malformed lexical occurrence step: ~a" step)])))
  (format "m1:~a:~a"
          program-key
          (if (null? slots) "root"
              (string-join (map number->string slots) "."))))

(define (module-occurrence-instances program-key occurrence)
  (unless (module-occurrence? occurrence)
    (catalog-fail 'invalid-module-tree
                  "expected a module occurrence tree; got ~a" occurrence))
  (define lexical-path (module-occurrence-lexical-path occurrence))
  (cons
   (module-instance-descriptor
    (module-instance-key program-key lexical-path)
    (module-occurrence-home occurrence)
    lexical-path
    (module-occurrence-bindings occurrence))
   (append-map
    (lambda (child)
      (module-occurrence-instances program-key child))
    (module-occurrence-children occurrence))))

(define (module-instance-descriptor->datum descriptor)
  `(module-instance
    (key ,(module-instance-descriptor-key descriptor))
    (home ,@(module-instance-descriptor-home descriptor))
    (lexical-path
     ,@(for/list ([step
                   (in-list
                    (module-instance-descriptor-lexical-path descriptor))])
         `(occurrence ,(first step) ,(second step))))
    (bindings
     ,@(for/list ([binding
                   (in-list
                    (module-instance-descriptor-bindings descriptor))])
         `(bind (formal ,@(first binding))
                (actual ,@(second binding)))))))

(define (module-instance-descriptor-datum? datum)
  (match datum
    [`(module-instance
       (key ,(? string?))
       (home ,(? valid-component?) ...)
       (lexical-path
        (occurrence ,(? exact-nonnegative-integer?)
                    ,(? valid-component?)) ...)
       (bindings
        (bind (formal ,(? valid-component?) ...)
              (actual ,(? valid-component?) ...)) ...))
     #t]
    [_ #f]))

(struct exn:fail:catalog exn:fail (kind detail) #:transparent)

(define (catalog-fail kind fmt . args)
  (define message (apply format fmt args))
  (raise
   (exn:fail:catalog
    message
    (current-continuation-marks)
    kind
    message)))

(define (empty-catalog)
  (catalog (hash) (set) (hash)))

(define (empty-boundary [key "boundary:empty"])
  (boundary key (empty-catalog) (hash)))

(define (storage-declaration? descriptor)
  (and (memq (declaration-descriptor-kind descriptor) '(table struct)) #t))

(define primitive-types
  ;; cset/cmap are builtin concrete collection disciplines rather than
  ;; user-declared nominal constructors.  cseq/coll are represented by the
  ;; builtin alias nodes already present in the type environment.
  (set 'any 'int 'float 'str 'cset 'cmap '$count))

(define (internal-symbol? name)
  (and (symbol? name)
       (string-prefix? (symbol->string name) "$")))

(define (name->qname who name)
  (cond
    [(qname? name) name]
    [(symbol? name) (symbol->qname name)]
    [(string? name) (wire->qname name)]
    [else (catalog-fail 'invalid-name "~a: expected QName, symbol, or wire name; got ~a"
                        who name)]))

(define (normalize-type-ref type-name)
  (unless (symbol? type-name)
    (catalog-fail 'invalid-type "field type is not a name: ~a" type-name))
  (if (set-member? primitive-types type-name)
      (type-ref 'primitive type-name)
      (type-ref 'named (symbol->qname type-name))))

(define (normalize-lattice-spec spec)
  (define (parameters ps)
    (define pairs
      (for/list ([p (in-list ps)])
        (match p
          [`(,(? symbol? key) ,value) (cons key value)]
          [_ (catalog-fail 'invalid-lattice "malformed lattice parameter: ~a" p)])))
    (define keys (map car pairs))
    (unless (= (length keys) (length (remove-duplicates keys)))
      (catalog-fail 'invalid-lattice "duplicate lattice parameter in ~a" spec))
    (sort pairs symbol<? #:key car))
  (match spec
    [`(lattice ,(and kind (or 'min 'max)) ,base ,ps ...)
     (lattice-descriptor kind
                         (list (normalize-type-ref base))
                         (parameters ps))]
    [`(lattice count)
     (lattice-descriptor 'count '() '())]
    [`(lattice ,(and kind (or 'flat 'set)) ,type-name)
     (lattice-descriptor kind
                         (list (normalize-type-ref type-name))
                         '())]
    [`(lattice map ,key-type ,inner)
     (unless (and (list? inner) (pair? inner))
       (catalog-fail 'invalid-lattice "malformed map lattice child: ~a" inner))
     (lattice-descriptor
      'map
      (list (normalize-type-ref key-type)
            (normalize-lattice-spec `(lattice ,@inner)))
      '())]
    [_ (catalog-fail 'invalid-lattice "malformed normalized lattice spec: ~a" spec)]))

(define (type-env->catalog-delta type-env)
  (unless (type-env? type-env)
    (catalog-fail 'invalid-type-environment "not a type environment: ~a" type-env))
  (define rels (type-env-rels type-env))
  (define aliases (type-env-aliases type-env))
  (define declarations
    (for/fold ([out (hash)])
              ([name (in-list (sort (hash-keys rels) symbol<?))])
      (define entry (hash-ref rels name))
      ;; Planner temps and extern-oracle dispatch bindings are execution
      ;; metadata, not logical public schema declarations.  In particular an
      ;; oracle binding uses a compiler-reserved `$...` key which is not a
      ;; QName, so recognize it before decoding public names.
      (cond
        [(or (internal-symbol? name)
             (match entry
               [`(temp ,_ ...) #t]
               [`(oracle ,_ ...) #t]
               [_ #f]))
         out]
        [else
         (define qn (symbol->qname name))
         (define descriptor
           (match entry
          [`(table ,fields ...)
           (declaration-descriptor
            qn 'table (map normalize-type-ref fields)
            (and (rel-lattice-spec rels name)
                 (normalize-lattice-spec (rel-lattice-spec rels name))))]
          [`(struct ,fields ...)
           (declaration-descriptor
            qn 'struct (map normalize-type-ref fields) #f)]
          [`(enum ,_)
           (declaration-descriptor qn 'enum '() #f)]
          [(and spec (? lattice-spec?))
           (declaration-descriptor
            qn 'lattice '() (normalize-lattice-spec spec))]
          [`(listof ,element)
           (declaration-descriptor
            qn 'list (list (normalize-type-ref element)) #f)]
          [`(mapof ,key ,value)
           (declaration-descriptor
            qn 'map
            (list (normalize-type-ref key) (normalize-type-ref value))
            #f)]
          [other
           (catalog-fail 'invalid-declaration
                         "unrecognized declaration for ~a: ~a" name other)]))
         (hash-set out qn descriptor)])))
  (define declarations+
    (for/fold ([out declarations])
              ([name (in-list (sort (hash-keys aliases) symbol<?))])
      (define qn (symbol->qname name))
      (cond
        [(hash-has-key? out qn)
         (catalog-fail 'conflicting-declaration
                       "~a is both a declaration and a union" name)]
        [else
         (hash-set out qn (declaration-descriptor qn 'union '() #f))])))
  ;; The current type environment stores transitive alias closure.  Emitting
  ;; every non-reflexive edge preserves its exact accepted-member contract;
  ;; N1's occurrence IR can later retain direct-edge provenance as well.
  (define memberships
    (for*/fold ([out (set)])
               ([union-name (in-list (sort (hash-keys aliases) symbol<?))]
                [member-name
                 (in-list
                  (sort (set->list (hash-ref aliases union-name)) symbol<?))]
                #:unless (eq? union-name member-name))
      (set-add out
               (cons (symbol->qname member-name)
                     (symbol->qname union-name)))))
  (catalog-delta declarations+ memberships))

(define (descriptor-compatible? left right)
  (equal? left right))

(define (type-ref-names ref)
  (match ref
    [(type-ref 'primitive _) (set)]
    [(type-ref 'named (? qname? name)) (set name)]
    [_ (catalog-fail 'invalid-type "invalid normalized TypeRef: ~a" ref)]))

(define (lattice-names spec)
  (for/fold ([out (set)]) ([argument (in-list (lattice-descriptor-arguments spec))])
    (cond
      [(type-ref? argument) (set-union out (type-ref-names argument))]
      [(lattice-descriptor? argument) (set-union out (lattice-names argument))]
      [else (catalog-fail 'invalid-lattice
                          "invalid normalized lattice argument: ~a" argument)])))

(define (declaration-references descriptor)
  (define field-names
    (for/fold ([out (set)])
              ([field (in-list (declaration-descriptor-fields descriptor))])
      (set-union out (type-ref-names field))))
  (define spec (declaration-descriptor-lattice-spec descriptor))
  (if spec (set-union field-names (lattice-names spec)) field-names))

(define known-kinds '(table struct enum union lattice list map))

(define (validate-catalog-shape declarations memberships)
  (unless (hash? declarations)
    (catalog-fail 'invalid-catalog
                  "catalog declarations must be a hash: ~a" declarations))
  (unless (set? memberships)
    (catalog-fail 'invalid-catalog
                  "catalog memberships must be a set: ~a" memberships))
  (for ([(name descriptor) (in-hash declarations)])
    (unless (and (qname? name)
                 (declaration-descriptor? descriptor)
                 (qname=? name (declaration-descriptor-name descriptor)))
      (catalog-fail 'invalid-catalog
                    "declaration key and descriptor name disagree: ~a -> ~a"
                    name descriptor))
    (unless (memq (declaration-descriptor-kind descriptor) known-kinds)
      (catalog-fail 'invalid-catalog "unknown declaration kind: ~a"
                    (declaration-descriptor-kind descriptor)))
    (define kind (declaration-descriptor-kind descriptor))
    (define fields (declaration-descriptor-fields descriptor))
    (define spec (declaration-descriptor-lattice-spec descriptor))
    (unless (and (list? fields) (andmap type-ref? fields))
      (catalog-fail 'invalid-catalog
                    "declaration ~a has invalid normalized fields: ~a"
                    (qname->display name) fields))
    (case kind
      [(table)
       (unless (and (pair? fields)
                    (or (not spec) (lattice-descriptor? spec)))
         (catalog-fail 'invalid-catalog
                       "table ~a has invalid fields/lattice descriptor"
                       (qname->display name)))]
      [(struct)
       (unless (and (pair? fields) (not spec))
         (catalog-fail 'invalid-catalog
                       "struct ~a has invalid fields/lattice descriptor"
                       (qname->display name)))]
      [(enum union)
       (unless (and (null? fields) (not spec))
         (catalog-fail 'invalid-catalog
                       "~a declaration ~a must not carry fields or a lattice"
                       kind (qname->display name)))]
      [(lattice)
       (unless (and (null? fields) (lattice-descriptor? spec))
         (catalog-fail 'invalid-catalog
                       "lattice declaration ~a has no normalized lattice spec"
                       (qname->display name)))]
      [(list)
       (unless (and (= 1 (length fields)) (not spec))
         (catalog-fail 'invalid-catalog
                       "list declaration ~a must have one element type"
                       (qname->display name)))]
      [(map)
       (unless (and (= 2 (length fields)) (not spec))
         (catalog-fail 'invalid-catalog
                       "map declaration ~a must have key and value types"
                       (qname->display name)))])
    (for ([reference (in-set (declaration-references descriptor))])
      (unless (hash-has-key? declarations reference)
        (catalog-fail
         'missing-type
         "declaration ~a references missing type ~a"
         (qname->display name) (qname->display reference)))))
  (for ([edge (in-set memberships)])
    (unless (and (pair? edge) (qname? (car edge)) (qname? (cdr edge)))
      (catalog-fail 'invalid-membership "invalid membership edge: ~a" edge))
    (define union (hash-ref declarations (cdr edge) #f))
    (unless (and union (eq? 'union (declaration-descriptor-kind union)))
      (catalog-fail 'invalid-membership
                    "membership target ~a is not a declared union"
                    (qname->display (cdr edge))))))

(define (validate-boundary input)
  (unless (boundary? input)
    (catalog-fail 'invalid-boundary "expected an input boundary; got ~a" input))
  (define cat (boundary-catalog input))
  (unless (catalog? cat)
    (catalog-fail 'invalid-boundary "boundary has no catalog: ~a" input))
  (define declarations (catalog-declarations cat))
  (validate-catalog-shape declarations (catalog-memberships cat))
  (unless (and (hash? (catalog-nominals cat))
               (hash? (boundary-environment input)))
    (catalog-fail 'invalid-boundary
                  "boundary TypeKey and VersionKey environments must be hashes"))
  (unless (and (string? (boundary-key input))
               (for/and ([key (in-hash-values (catalog-nominals cat))])
                 (and (string? key) (non-empty-string? key)))
               (for/and ([key (in-hash-values (boundary-environment input))])
                 (and (string? key) (non-empty-string? key))))
    (catalog-fail 'invalid-boundary
                  "boundary and relation/type keys must be nonempty strings"))
  (define expected-storage
    (for/set ([descriptor (in-hash-values declarations)]
              #:when (storage-declaration? descriptor))
      (declaration-descriptor-name descriptor)))
  (define actual-storage (list->set (hash-keys (boundary-environment input))))
  (unless (set=? expected-storage actual-storage)
    (catalog-fail
     'invalid-boundary
     "boundary VersionKey environment does not exactly cover its storage declarations"))
  (define expected-nominals
    (for/set ([descriptor (in-hash-values declarations)]
              #:when (eq? 'struct (declaration-descriptor-kind descriptor)))
      (declaration-descriptor-name descriptor)))
  (define actual-nominals (list->set (hash-keys (catalog-nominals cat))))
  (unless (set=? expected-nominals actual-nominals)
    (catalog-fail
     'invalid-boundary
     "boundary TypeKey map does not exactly cover its struct declarations")))

(define (check-key-input who layer event)
  (unless (and (string? layer) (non-empty-string? layer))
    (catalog-fail 'invalid-key-input "~a LayerId must be a nonempty string: ~a"
                  who layer))
  (unless (exact-nonnegative-integer? event)
    (catalog-fail 'invalid-key-input "~a event must be a natural number: ~a"
                  who event)))

(define (program-key layer event) (format "p1:~a:~a" layer event))
(define (make-boundary-key layer event) (format "b1:~a:~a" layer event))
(define (version-key layer event slot) (format "v1:~a:~a:~a" layer event slot))
(define (type-key layer event slot) (format "t1:~a:~a:~a" layer event slot))

(define (sorted-qnames names)
  (sort (remove-duplicates names equal?) qname<?))

(define (plan-boundary input proposed writes
                       #:layer-id layer-id
                       #:program-event program-event
                       #:boundary-event boundary-event
                       #:type-event [type-event boundary-event])
  (validate-boundary input)
  (unless (catalog-delta? proposed)
    (catalog-fail 'invalid-delta "expected CatalogDelta; got ~a" proposed))
  (check-key-input 'program layer-id program-event)
  (check-key-input 'boundary layer-id boundary-event)
  (check-key-input 'type layer-id type-event)

  (define input-catalog (boundary-catalog input))
  (define input-declarations (catalog-declarations input-catalog))
  (define proposed-declarations (catalog-delta-declarations proposed))
  (unless (and (hash? proposed-declarations)
               (set? (catalog-delta-memberships proposed)))
    (catalog-fail 'invalid-delta
                  "CatalogDelta must contain a declaration hash and membership set"))

  ;; Reconcile into local immutable values.  No keys or caller state change
  ;; before every overlap has passed.
  (for ([(name descriptor) (in-hash proposed-declarations)])
    (unless (and (qname? name)
                 (declaration-descriptor? descriptor)
                 (qname=? name (declaration-descriptor-name descriptor)))
      (catalog-fail 'invalid-delta
                    "declaration key and descriptor name disagree: ~a -> ~a"
                    name descriptor))
    (define established (hash-ref input-declarations name #f))
    (when (and established
               (not (descriptor-compatible? established descriptor)))
      (catalog-fail
       'incompatible-declaration
       "declaration for ~a is incompatible with the input catalog: ~a vs ~a"
       (qname->display name) established descriptor)))

  (define added-declarations
    (for/hash ([(name descriptor) (in-hash proposed-declarations)]
               #:unless (hash-has-key? input-declarations name))
      (values name descriptor)))
  (define output-declarations
    (for/fold ([out input-declarations])
              ([(name descriptor) (in-hash added-declarations)])
      (hash-set out name descriptor)))
  (define added-memberships
    (set-subtract (catalog-delta-memberships proposed)
                  (catalog-memberships input-catalog)))
  (define output-memberships
    (set-union (catalog-memberships input-catalog)
               (catalog-delta-memberships proposed)))
  (validate-catalog-shape output-declarations output-memberships)

  (define write-names
    (sorted-qnames
     (for/list ([name (in-list writes)]) (name->qname 'plan-boundary name))))
  (for ([name (in-list write-names)])
    (define descriptor (hash-ref output-declarations name #f))
    (unless descriptor
      (catalog-fail 'unknown-write "write set names undeclared relation ~a"
                    (qname->display name)))
    (unless (storage-declaration? descriptor)
      (catalog-fail 'invalid-write "write set names non-storage declaration ~a"
                    (qname->display name))))

  (define new-structs
    (sorted-qnames
     (for/list ([(name descriptor) (in-hash added-declarations)]
                #:when (eq? 'struct (declaration-descriptor-kind descriptor)))
       name)))
  (define type-slots
    (for/hash ([name (in-list new-structs)] [slot (in-naturals)])
      (values name slot)))
  (define output-nominals
    (for/fold ([out (catalog-nominals input-catalog)])
              ([name (in-list new-structs)])
      (hash-set out name
                (type-key layer-id type-event (hash-ref type-slots name)))))

  (define input-environment (boundary-environment input))
  (define create-names
    (sorted-qnames
     (for/list ([(name descriptor) (in-hash output-declarations)]
                #:when
                (and (storage-declaration? descriptor)
                     (or (hash-has-key? added-declarations name)
                         (member name write-names equal?))))
       name)))
  (define version-slots
    (for/hash ([name (in-list create-names)] [slot (in-naturals)])
      (values name slot)))
  (define output-environment
    (for/fold ([out input-environment])
              ([name (in-list create-names)])
      (hash-set out name
                (version-key layer-id boundary-event
                             (hash-ref version-slots name)))))

  (define output-catalog
    (catalog output-declarations output-memberships output-nominals))
  (define output
    (boundary (make-boundary-key layer-id boundary-event)
              output-catalog
              output-environment))
  (define actions
    (for/list ([name
                (in-list
                 (sorted-qnames
                  (for/list ([descriptor (in-hash-values output-declarations)]
                             #:when (storage-declaration? descriptor))
                    (declaration-descriptor-name descriptor))))])
      (define descriptor (hash-ref output-declarations name))
      (define nominal
        (and (eq? 'struct (declaration-descriptor-kind descriptor))
             (hash-ref output-nominals name)))
      (cond
        [(hash-has-key? version-slots name)
         (boundary-action
          'create name (hash-ref output-environment name)
          (and (hash-has-key? input-environment name)
               (hash-ref input-environment name))
          nominal)]
        [else
         (boundary-action
          'retain name (hash-ref input-environment name) #f nominal)])))

  (boundary-plan
   layer-id
   program-event
   boundary-event
   type-event
   (program-key layer-id program-event)
   (make-boundary-key layer-id boundary-event)
   input
   output
   (catalog-delta added-declarations added-memberships)
   actions
   version-slots
   type-slots))

;; -----------------------------------------------------------------------
;; N3-D path transforms (modules.md §5.3)
;;
;; A rename or drop is a pure transform of one input boundary: the selected
;; subtree's declarations, memberships, nominal TypeKeys, and environment
;; VersionKeys move (or leave) together under a successor BoundaryKey minted
;; from the same LayerId/event identity as program boundaries.  A rename also
;; rewrites every nominal reference INTO the subtree -- including field types
;; declared outside it -- without changing any TypeKey or VersionKey.  A drop
;; is rejected while a surviving declaration still references the subtree
;; (field type or membership edge): the conservative §5.3 integrity rule.

(struct transform-plan
  (layer-id event kind from to boundary-key input output)
  #:transparent)

(define (qname-inside? name path)
  (define nc (qname-components name))
  (define pc (qname-components path))
  (and (> (length nc) (length pc))
       (equal? (take nc (length pc)) pc)))

(define (qname-at-or-inside? name path)
  (or (qname=? name path) (qname-inside? name path)))

(define (qname-rebase name from to)
  (if (qname=? name from)
      to
      (qname (append (qname-components to)
                     (drop (qname-components name)
                           (length (qname-components from)))))))

(define (rewrite-type-ref ref rename)
  (match ref
    [(type-ref 'primitive _) ref]
    [(type-ref 'named (? qname? name)) (type-ref 'named (rename name))]
    [_ (catalog-fail 'invalid-type "invalid normalized TypeRef: ~a" ref)]))

(define (rewrite-lattice-spec spec rename)
  (lattice-descriptor
   (lattice-descriptor-kind spec)
   (for/list ([argument (in-list (lattice-descriptor-arguments spec))])
     (cond
       [(type-ref? argument) (rewrite-type-ref argument rename)]
       [(lattice-descriptor? argument) (rewrite-lattice-spec argument rename)]
       [else (catalog-fail 'invalid-lattice
                           "invalid normalized lattice argument: ~a"
                           argument)]))
   (lattice-descriptor-parameters spec)))

(define (rewrite-declaration descriptor rename)
  (declaration-descriptor
   (rename (declaration-descriptor-name descriptor))
   (declaration-descriptor-kind descriptor)
   (for/list ([field (in-list (declaration-descriptor-fields descriptor))])
     (rewrite-type-ref field rename))
   (let ([spec (declaration-descriptor-lattice-spec descriptor)])
     (and spec (rewrite-lattice-spec spec rename)))))

(define (plan-path-transform input kind path target
                             #:layer-id layer-id #:event event)
  (unless (memq kind '(rename drop))
    (catalog-fail 'invalid-transform "unknown transform kind: ~a" kind))
  (check-key-input 'transform layer-id event)
  (define from (name->qname 'transform path))
  (define to (and (eq? kind 'rename) (name->qname 'transform target)))
  (define cat (boundary-catalog input))
  (define declarations (catalog-declarations cat))
  (define memberships (catalog-memberships cat))
  (define nominals (catalog-nominals cat))
  (define environment (boundary-environment input))
  (define (known-names)
    (set-union (list->set (hash-keys declarations))
               (list->set (hash-keys environment))))
  (define names (known-names))
  (define selected
    (for/set ([name (in-set names)]
              #:when (qname-at-or-inside? name from))
      name))
  (when (set-empty? selected)
    (catalog-fail 'unknown-path "transform path is unbound: ~a"
                  (qname->display from)))
  (when (and (set-member? selected from) (> (set-count selected) 1))
    (catalog-fail 'invalid-catalog
                  "path names both a declaration and a namespace: ~a"
                  (qname->display from)))
  (when to
    (when (qname-at-or-inside? to from)
      (catalog-fail 'invalid-transform
                    "rename target lies inside the renamed subtree: ~a"
                    (qname->display to)))
    (for ([name (in-set names)])
      (when (qname-at-or-inside? name to)
        (catalog-fail 'occupied-target
                      "rename target is already bound: ~a covers ~a"
                      (qname->display to) (qname->display name)))
      ;; one path is never both a declaration and a namespace: the target
      ;; may not nest inside an existing leaf either
      (when (qname-inside? to name)
        (catalog-fail 'occupied-target
                      "rename target nests inside declaration ~a"
                      (qname->display name)))))
  (define (rename-name name)
    (if (and to (qname-at-or-inside? name from))
        (qname-rebase name from to)
        name))
  (define output-catalog
    (cond
      [to
       (catalog
        (for/hash ([(name descriptor) (in-hash declarations)])
          (values (rename-name name)
                  (rewrite-declaration descriptor rename-name)))
        (for/set ([edge (in-set memberships)])
          (cons (rename-name (car edge)) (rename-name (cdr edge))))
        (for/hash ([(name key) (in-hash nominals)])
          (values (rename-name name) key)))]
      [else
       (define surviving
         (for/hash ([(name descriptor) (in-hash declarations)]
                    #:unless (qname-at-or-inside? name from))
           (values name descriptor)))
       (for ([(name descriptor) (in-hash surviving)])
         (for ([reference (in-set (declaration-references descriptor))])
           (when (and (qname-at-or-inside? reference from)
                      ;; a reference to a name that was never declared is the
                      ;; planner's concern elsewhere; integrity gates only on
                      ;; real subtree members
                      (or (hash-has-key? declarations reference)
                          (hash-has-key? environment reference)))
             (catalog-fail 'dangling-reference
                           "declaration ~a references ~a inside the dropped subtree"
                           (qname->display name)
                           (qname->display reference)))))
       (catalog
        surviving
        (for/set ([edge (in-set memberships)]
                  #:unless (or (qname-at-or-inside? (car edge) from)
                               (qname-at-or-inside? (cdr edge) from)))
          edge)
        (for/hash ([(name key) (in-hash nominals)]
                   #:unless (qname-at-or-inside? name from))
          (values name key)))]))
  ;; membership integrity runs over EVERY edge: a surviving parent may not
  ;; keep an edge whose member the drop removes (§5.3)
  (unless to
    (for ([edge (in-set memberships)])
      (when (and (qname-at-or-inside? (car edge) from)
                 (not (qname-at-or-inside? (cdr edge) from)))
        (catalog-fail 'dangling-membership
                      "declaration ~a retains a membership into the dropped subtree"
                      (qname->display (cdr edge))))))
  (define output-environment
    (if to
        (for/hash ([(name key) (in-hash environment)])
          (values (rename-name name) key))
        (for/hash ([(name key) (in-hash environment)]
                   #:unless (qname-at-or-inside? name from))
          (values name key))))
  (define output
    (boundary (make-boundary-key layer-id event)
              output-catalog
              output-environment))
  (transform-plan layer-id event kind from to
                  (make-boundary-key layer-id event)
                  input output))

(define (transform-plan->datum plan)
  `(transform-plan
    (layer ,(transform-plan-layer-id plan))
    (event ,(transform-plan-event plan))
    (kind ,(transform-plan-kind plan))
    (from ,(qname->datum (transform-plan-from plan)))
    (to ,(and (transform-plan-to plan)
              (qname->datum (transform-plan-to plan))))
    (boundary ,(transform-plan-boundary-key plan))))

(define (transform-plan-datum? datum)
  (match datum
    [`(transform-plan (layer ,(? string?)) (event ,(? exact-nonnegative-integer?))
                      (kind ,(or 'rename 'drop)) (from ,_) (to ,_)
                      (boundary ,(? string?)))
     #t]
    [_ #f]))

;; Replay recomputes the transform from the reconstructed input boundary
;; under the persisted identity and refuses any disagreement -- transforms
;; carry no allocation tables, so key equality plus successful recomputation
;; is the complete audit.
(define (replay-path-transform input datum)
  (match datum
    [`(transform-plan (layer ,(? string? layer)) (event ,(? exact-nonnegative-integer? event))
                      (kind ,(and kind (or 'rename 'drop)))
                      (from ,from) (to ,to)
                      (boundary ,(? string? key)))
     (define plan
       (plan-path-transform input kind (datum->qname from)
                            (and (eq? kind 'rename) (datum->qname to))
                            #:layer-id layer #:event event))
     (unless (equal? (transform-plan-boundary-key plan) key)
       (catalog-fail 'replay-divergence
                     "replayed transform minted ~a but the recipe recorded ~a"
                     (transform-plan-boundary-key plan) key))
     plan]
    [_ (catalog-fail 'invalid-recipe
                     "malformed persisted transform plan: ~a" datum)]))

;; -----------------------------------------------------------------------
;; Recipe codec
;;
;; Recipe QNames retain their component vector explicitly.  Dotted text is a
;; display/wire projection and must not become the persisted identity parser.

(define (qname->datum name)
  `(qname ,@(qname-components name)))

(define (datum->qname datum)
  (match datum
    [`(qname ,(? string? components) ..1) (qname components)]
    [_ (catalog-fail 'invalid-recipe-qname
                     "malformed recipe QName: ~a" datum)]))

(define (type-ref->datum ref)
  (match ref
    [(type-ref 'primitive (? symbol? name)) `(type primitive ,name)]
    [(type-ref 'named (? qname? name)) `(type named ,(qname->datum name))]
    [_ (catalog-fail 'invalid-type "invalid normalized TypeRef: ~a" ref)]))

(define (datum->type-ref datum)
  (match datum
    [`(type primitive ,(? symbol? name)) (type-ref 'primitive name)]
    [`(type named ,name) (type-ref 'named (datum->qname name))]
    [_ (catalog-fail 'invalid-recipe-type
                     "malformed recipe TypeRef: ~a" datum)]))

(define (lattice-descriptor->recipe-datum spec)
  `(lattice-descriptor
    ,(lattice-descriptor-kind spec)
    (arguments
     ,@(for/list ([argument
                   (in-list (lattice-descriptor-arguments spec))])
         (cond
           [(type-ref? argument) (type-ref->datum argument)]
           [(lattice-descriptor? argument)
            (lattice-descriptor->recipe-datum argument)]
           [else
            (catalog-fail 'invalid-lattice
                          "invalid normalized lattice argument: ~a"
                          argument)])))
    (parameters
     ,@(for/list ([parameter
                   (in-list (lattice-descriptor-parameters spec))])
         `(,(car parameter) ,(cdr parameter))))))

(define (datum->lattice-descriptor datum)
  (match datum
    [`(lattice-descriptor ,(? symbol? kind)
                          (arguments ,arguments ...)
                          (parameters ,parameters ...))
     (lattice-descriptor
      kind
      (for/list ([argument (in-list arguments)])
        (match argument
          [`(type ,_ ...) (datum->type-ref argument)]
          [`(lattice-descriptor ,_ ...) (datum->lattice-descriptor argument)]
          [_ (catalog-fail 'invalid-recipe-lattice
                           "malformed recipe lattice argument: ~a"
                           argument)]))
      (for/list ([parameter (in-list parameters)])
        (match parameter
          [`(,(? symbol? key) ,value) (cons key value)]
          [_ (catalog-fail 'invalid-recipe-lattice
                           "malformed recipe lattice parameter: ~a"
                           parameter)])))]
    [_ (catalog-fail 'invalid-recipe-lattice
                     "malformed recipe lattice descriptor: ~a" datum)]))

(define (declaration-descriptor->datum descriptor)
  `(declaration
    ,(qname->datum (declaration-descriptor-name descriptor))
    ,(declaration-descriptor-kind descriptor)
    (fields
     ,@(map type-ref->datum
            (declaration-descriptor-fields descriptor)))
    (lattice
     ,(and (declaration-descriptor-lattice-spec descriptor)
           (lattice-descriptor->recipe-datum
            (declaration-descriptor-lattice-spec descriptor))))))

(define (datum->declaration-descriptor datum)
  (match datum
    [`(declaration ,name ,(? symbol? kind)
                   (fields ,fields ...)
                   (lattice ,spec))
     (declaration-descriptor
      (datum->qname name)
      kind
      (map datum->type-ref fields)
      (and spec (datum->lattice-descriptor spec)))]
    [_ (catalog-fail 'invalid-recipe-declaration
                     "malformed recipe declaration: ~a" datum)]))

(define (catalog-delta->datum delta)
  (unless (catalog-delta? delta)
    (catalog-fail 'invalid-delta "expected CatalogDelta; got ~a" delta))
  `(catalog-delta
    (declarations
     ,@(for/list ([name
                   (in-list
                    (sort (hash-keys (catalog-delta-declarations delta))
                          qname<?))])
         (declaration-descriptor->datum
          (hash-ref (catalog-delta-declarations delta) name))))
    (memberships
     ,@(for/list ([edge
                   (in-list
                    (sort-membership-edges
                     (catalog-delta-memberships delta)))])
         `(member ,(qname->datum (car edge))
                  ,(qname->datum (cdr edge)))))))

(define (datum->catalog-delta datum)
  (match datum
    [`(catalog-delta
       (declarations ,declarations ...)
       (memberships ,memberships ...))
     (define descriptor-list
       (map datum->declaration-descriptor declarations))
     (define names (map declaration-descriptor-name descriptor-list))
     (unless (= (length names) (length (remove-duplicates names equal?)))
       (catalog-fail 'invalid-recipe-delta
                     "recipe CatalogDelta repeats a declaration"))
     (catalog-delta
      (for/hash ([descriptor (in-list descriptor-list)])
        (values (declaration-descriptor-name descriptor) descriptor))
      (for/set ([membership (in-list memberships)])
        (match membership
          [`(member ,member ,union)
           (cons (datum->qname member) (datum->qname union))]
          [_ (catalog-fail 'invalid-recipe-delta
                           "malformed recipe membership: ~a"
                           membership)])))]
    [_ (catalog-fail 'invalid-recipe-delta
                     "malformed recipe CatalogDelta: ~a" datum)]))

(define (slot-table->datum label slots)
  `(,label
    ,@(for/list ([name (in-list (sort (hash-keys slots) qname<?))])
        `(,(qname->datum name) ,(hash-ref slots name)))))

(define (valid-slot-table-datum? datum label)
  (match datum
    [`(,(== label) ,entries ...)
     (define names
       (for/list ([entry (in-list entries)])
         (match entry
           [`(,name ,(? exact-nonnegative-integer?)) (datum->qname name)]
           [_ (catalog-fail 'invalid-recipe-plan
                            "malformed ~a entry: ~a" label entry)])))
     (unless (= (length names) (length (remove-duplicates names equal?)))
       (catalog-fail 'invalid-recipe-plan
                     "~a repeats a QName" label))
     #t]
    [_ (catalog-fail 'invalid-recipe-plan
                     "malformed ~a table: ~a" label datum)]))

(define (boundary-plan->datum plan)
  (unless (boundary-plan? plan)
    (catalog-fail 'invalid-boundary-plan
                  "expected BoundaryPlan; got ~a" plan))
  `(boundary-plan
    (layer-id ,(boundary-plan-layer-id plan))
    (program-event ,(boundary-plan-program-event plan))
    (boundary-event ,(boundary-plan-boundary-event plan))
    (type-event ,(boundary-plan-type-event plan))
    (program-key ,(boundary-plan-program-key plan))
    (boundary-key ,(boundary-plan-boundary-key plan))
    ,(catalog-delta->datum (boundary-plan-delta plan))
    (actions
     ,@(for/list ([action (in-list (boundary-plan-actions plan))])
         `(,(boundary-action-kind action)
           ,(qname->datum (boundary-action-name action))
           ,(boundary-action-version-key action)
           ,(boundary-action-predecessor action)
           ,(boundary-action-type-key action))))
    ,(slot-table->datum 'version-slots (boundary-plan-version-slots plan))
    ,(slot-table->datum 'type-slots (boundary-plan-type-slots plan))))

(define (boundary-plan-datum? datum)
  (with-handlers ([exn:fail? (lambda (_error) #f)])
    (match datum
      [`(boundary-plan
         (layer-id ,(? non-empty-string?))
         (program-event ,(? exact-nonnegative-integer?))
         (boundary-event ,(? exact-nonnegative-integer?))
         (type-event ,(? exact-nonnegative-integer?))
         (program-key ,(? non-empty-string?))
         (boundary-key ,(? non-empty-string?))
         ,delta
         (actions ,actions ...)
         ,version-slots
         ,type-slots)
       (datum->catalog-delta delta)
       (for ([action (in-list actions)])
         (match action
           [`(,(or 'retain 'create)
              ,name
              ,(? non-empty-string?)
              ,(or #f (? non-empty-string?))
              ,(or #f (? non-empty-string?)))
            (datum->qname name)]
           [_ (catalog-fail 'invalid-recipe-plan
                            "malformed boundary action: ~a" action)]))
       (valid-slot-table-datum? version-slots 'version-slots)
       (valid-slot-table-datum? type-slots 'type-slots)
       #t]
      [_ #f])))

(define (replay-boundary-plan input proposed writes datum)
  (unless (boundary-plan-datum? datum)
    (catalog-fail 'invalid-recipe-plan
                  "malformed persisted BoundaryPlan: ~a" datum))
  (match-define
    `(boundary-plan
      (layer-id ,layer-id)
      (program-event ,program-event)
      (boundary-event ,boundary-event)
      (type-event ,type-event)
      ,_ ...)
    datum)
  (define plan
    (plan-boundary input proposed writes
                   #:layer-id layer-id
                   #:program-event program-event
                   #:boundary-event boundary-event
                   #:type-event type-event))
  (unless (equal? datum (boundary-plan->datum plan))
    (catalog-fail
     'recipe-plan-mismatch
     "recompiled boundary plan differs from its persisted recipe plan:\n  stored ~a\n  rebuilt ~a"
     datum (boundary-plan->datum plan)))
  plan)

;; -----------------------------------------------------------------------
;; N4-A durable boundary bundle (docs/n4-contract.md §3)
;;
;; One canonical value describes a saved database's logical schema without
;; rediscovering it from tuple directories or source text.  The head is a
;; COMPLETE snapshot; history is a chain of validated transition records that
;; reuse the BoundaryPlan and transform-plan codecs above rather than
;; repeating full catalog snapshots.  Every record family is validated for
;; internal consistency before a reader may expose a single key, so a
;; malformed bundle fails ahead of any daemon mutation.

(define slog-boundary-bundle-format 1)

;; One committed boundary in order.  `origin` is 'program (its BoundaryPlan
;; datum), 'transform (its transform-plan datum), 'attachment (its N4-B
;; attachment-plan datum), or 'initial (an adopted or empty base with no
;; producing plan).
(struct boundary-record (key predecessor origin-kind origin) #:transparent)

;; A relation version.  `name` is its qualified name AT THE SELECTED HEAD, or
;; #f for a historical version whose name no longer resolves there.
;; `materialized?` records whether this save carries its rows.
(struct version-record (key predecessor kind name materialized?) #:transparent)

;; A nominal constructor.  `arity` is the STORED arity (fields + the intern
;; id column), `sid` the saved runtime struct id, and `names` every qualified
;; spelling this TypeKey has carried -- current or historical, so an unnamed
;; historical constructor still renders through its TypeKey.
(struct type-record (key arity sid names) #:transparent)

;; One compiled program occurrence and its lexical module instances.
(struct program-record (key input output modules) #:transparent)

(struct boundary-bundle
  (format selected-head history versions types programs)
  #:transparent)

(define (boundary->datum input)
  (unless (boundary? input)
    (catalog-fail 'invalid-boundary "expected a boundary; got ~a" input))
  (define cat (boundary-catalog input))
  (unless (catalog? cat)
    (catalog-fail 'invalid-boundary "boundary has no catalog: ~a" input))
  (define declarations (catalog-declarations cat))
  (define nominals (catalog-nominals cat))
  (define environment (boundary-environment input))
  `(boundary
    (key ,(boundary-key input))
    (declarations
     ,@(for/list ([name (in-list (sort (hash-keys declarations) qname<?))])
         (declaration-descriptor->datum (hash-ref declarations name))))
    (memberships
     ,@(for/list ([edge (in-list (sort-membership-edges
                                  (catalog-memberships cat)))])
         `(member ,(qname->datum (car edge)) ,(qname->datum (cdr edge)))))
    (nominals
     ,@(for/list ([name (in-list (sort (hash-keys nominals) qname<?))])
         `(nominal ,(qname->datum name) ,(hash-ref nominals name))))
    (environment
     ,@(for/list ([name (in-list (sort (hash-keys environment) qname<?))])
         `(binding ,(qname->datum name) ,(hash-ref environment name))))))

(define (sort-membership-edges memberships)
  (sort (set->list memberships)
        (lambda (left right)
          (or (qname<? (cdr left) (cdr right))
              (and (qname=? (cdr left) (cdr right))
                   (qname<? (car left) (car right)))))))

(define (datum->boundary datum)
  (match datum
    [`(boundary
       (key ,(? non-empty-string? key))
       (declarations ,declarations ...)
       (memberships ,memberships ...)
       (nominals ,nominals ...)
       (environment ,bindings ...))
     (define descriptors (map datum->declaration-descriptor declarations))
     (define names (map declaration-descriptor-name descriptors))
     (unless (= (length names) (length (remove-duplicates names equal?)))
       (catalog-fail 'invalid-bundle "boundary repeats a declaration"))
     (boundary
      key
      (catalog
       (for/hash ([descriptor (in-list descriptors)])
         (values (declaration-descriptor-name descriptor) descriptor))
       (for/set ([edge (in-list memberships)])
         (match edge
           [`(member ,member ,union)
            (cons (datum->qname member) (datum->qname union))]
           [_ (catalog-fail 'invalid-bundle
                            "malformed boundary membership: ~a" edge)]))
       (keyed-name-table nominals 'nominal "nominal TypeKey"))
      (keyed-name-table bindings 'binding "VersionKey binding"))]
    [_ (catalog-fail 'invalid-bundle "malformed persisted boundary: ~a"
                     datum)]))

;; A sorted QName -> nonempty-string table under one tag.  Duplicate names are
;; a hard error: an allocation table is never silently last-wins.
(define (keyed-name-table entries tag what)
  (for/fold ([out (hash)]) ([entry (in-list entries)])
    (match entry
      [`(,(== tag) ,name ,(? non-empty-string? key))
       (define decoded (datum->qname name))
       (when (hash-has-key? out decoded)
         (catalog-fail 'duplicate-key "~a repeats ~a" what
                       (qname->display decoded)))
       (hash-set out decoded key)]
      [_ (catalog-fail 'invalid-bundle "malformed ~a entry: ~a" what entry)])))

(define (boundary-record->datum record)
  (define origin (boundary-record-origin record))
  `(boundary-record
    (key ,(boundary-record-key record))
    (predecessor ,(boundary-record-predecessor record))
    (origin
     ,(case (boundary-record-origin-kind record)
        [(program) `(program ,origin)]
        [(transform) `(transform ,origin)]
        [(attachment) `(attachment ,origin)]
        [(initial) `(initial)]
        [else
         (catalog-fail 'invalid-bundle "unknown boundary origin kind: ~a"
                       (boundary-record-origin-kind record))]))))

(define (datum->boundary-record datum)
  (match datum
    [`(boundary-record
       (key ,(? non-empty-string? key))
       (predecessor ,(and predecessor (or #f (? non-empty-string?))))
       (origin ,origin))
     (match origin
       [`(program ,plan)
        (unless (boundary-plan-datum? plan)
          (catalog-fail 'invalid-bundle
                        "boundary record ~a carries a malformed BoundaryPlan"
                        key))
        (boundary-record key predecessor 'program plan)]
       [`(transform ,plan)
        (unless (transform-plan-datum? plan)
          (catalog-fail 'invalid-bundle
                        "boundary record ~a carries a malformed transform plan"
                        key))
        (boundary-record key predecessor 'transform plan)]
       [`(attachment ,plan)
        (unless (attachment-plan-datum? plan)
          (catalog-fail 'invalid-bundle
                        "boundary record ~a carries a malformed attachment plan"
                        key))
        (boundary-record key predecessor 'attachment plan)]
       [`(initial) (boundary-record key predecessor 'initial #f)]
       [_ (catalog-fail 'invalid-bundle
                        "malformed boundary origin: ~a" origin)])]
    [_ (catalog-fail 'invalid-bundle
                     "malformed persisted boundary record: ~a" datum)]))

(define (version-record->datum record)
  `(version-record
    (key ,(version-record-key record))
    (predecessor ,(version-record-predecessor record))
    (kind ,(version-record-kind record))
    (name ,(let ([name (version-record-name record)])
             (and name (qname->datum name))))
    (materialized ,(and (version-record-materialized? record) #t))))

(define (datum->version-record datum)
  (match datum
    [`(version-record
       (key ,(? non-empty-string? key))
       (predecessor ,(and predecessor (or #f (? non-empty-string?))))
       (kind ,(and kind (or 'table 'struct)))
       (name ,name)
       (materialized ,(? boolean? materialized?)))
     (version-record key predecessor kind
                     (and name (datum->qname name))
                     materialized?)]
    [_ (catalog-fail 'invalid-bundle
                     "malformed persisted version record: ~a" datum)]))

(define (type-record->datum record)
  `(type-record
    (key ,(type-record-key record))
    (arity ,(type-record-arity record))
    (sid ,(type-record-sid record))
    (names ,@(for/list ([name (in-list (sort (type-record-names record)
                                             qname<?))])
               (qname->datum name)))))

(define (datum->type-record datum)
  (match datum
    [`(type-record
       (key ,(? non-empty-string? key))
       (arity ,(? exact-positive-integer? arity))
       (sid ,(and sid (or #f (? exact-nonnegative-integer?))))
       (names ,names ...))
     (define decoded (map datum->qname names))
     (unless (= (length decoded) (length (remove-duplicates decoded equal?)))
       (catalog-fail 'invalid-bundle
                     "type record ~a repeats a constructor name" key))
     (type-record key arity sid decoded)]
    [_ (catalog-fail 'invalid-bundle
                     "malformed persisted type record: ~a" datum)]))

(define (program-record->datum record)
  `(program-record
    (key ,(program-record-key record))
    (input ,(program-record-input record))
    (output ,(program-record-output record))
    (modules ,@(program-record-modules record))))

(define (datum->program-record datum)
  (match datum
    [`(program-record
       (key ,(? non-empty-string? key))
       (input ,(and input (or #f (? non-empty-string?))))
       (output ,(? non-empty-string? output))
       (modules ,modules ...))
     (for ([module-datum (in-list modules)])
       (unless (module-instance-descriptor-datum? module-datum)
         (catalog-fail 'invalid-bundle
                       "program record ~a carries a malformed module instance"
                       key)))
     (program-record key input output modules)]
    [_ (catalog-fail 'invalid-bundle
                     "malformed persisted program record: ~a" datum)]))

(define (boundary-bundle->datum bundle)
  (unless (boundary-bundle? bundle)
    (catalog-fail 'invalid-bundle "expected a BoundaryBundle; got ~a" bundle))
  `(boundary-bundle
    (bundle-format ,(boundary-bundle-format bundle))
    (selected-head ,(boundary->datum (boundary-bundle-selected-head bundle)))
    (boundary-history
     ,@(map boundary-record->datum (boundary-bundle-history bundle)))
    (versions ,@(map version-record->datum (boundary-bundle-versions bundle)))
    (types ,@(map type-record->datum (boundary-bundle-types bundle)))
    (programs
     ,@(map program-record->datum (boundary-bundle-programs bundle)))))

;; Decode WITHOUT cross-record validation -- callers that mutate public state
;; must run `validate-boundary-bundle` (which decoding here already implies
;; for shape).  Kept separate so a diagnostic reader can inspect a bundle that
;; fails integrity.
(define (datum->boundary-bundle datum)
  (match datum
    [`(boundary-bundle
       (bundle-format ,(? exact-nonnegative-integer? format))
       (selected-head ,head)
       (boundary-history ,history ...)
       (versions ,versions ...)
       (types ,types ...)
       (programs ,programs ...))
     (unless (= format slog-boundary-bundle-format)
       (catalog-fail
        'unsupported-bundle-format
        "boundary bundle format ~a is not supported by this build (~a)"
        format slog-boundary-bundle-format))
     (boundary-bundle
      format
      (datum->boundary head)
      (map datum->boundary-record history)
      (map datum->version-record versions)
      (map datum->type-record types)
      (map datum->program-record programs))]
    [_ (catalog-fail 'invalid-bundle
                     "malformed persisted boundary bundle: ~a" datum)]))

;; A cheap total predicate for META gating: shape-and-integrity, never raising.
(define (boundary-bundle-datum? datum)
  (with-handlers ([exn:fail? (lambda (_error) #f)])
    (validate-boundary-bundle (datum->boundary-bundle datum))
    #t))

;; The items of a persisted plan datum's `tag` clause, or #f when it has none.
;; Both plan codecs above are flat keyed forms, so every reader of a stored
;; plan goes through this rather than growing a second positional grammar.
(define (plan-clause datum tag)
  (and (pair? datum)
       (for/or ([clause (in-list (cdr datum))])
         (and (pair? clause) (eq? (car clause) tag) (cdr clause)))))

;; The same, for a clause known to carry exactly one value.
(define (tagged-clause datum tag)
  (match (plan-clause datum tag)
    [(list value) value]
    [_ #f]))

(define (unique-keys! keys what)
  (unless (= (length keys) (length (remove-duplicates keys equal?)))
    (catalog-fail 'duplicate-key "boundary bundle repeats a ~a" what)))

(define (validate-boundary-bundle bundle)
  (unless (boundary-bundle? bundle)
    (catalog-fail 'invalid-bundle "expected a BoundaryBundle; got ~a" bundle))
  (unless (= (boundary-bundle-format bundle) slog-boundary-bundle-format)
    (catalog-fail 'unsupported-bundle-format
                  "boundary bundle format ~a is not supported by this build (~a)"
                  (boundary-bundle-format bundle) slog-boundary-bundle-format))
  (define head (boundary-bundle-selected-head bundle))
  (validate-boundary head)
  (define declarations (catalog-declarations (boundary-catalog head)))
  (define nominals (catalog-nominals (boundary-catalog head)))
  (define environment (boundary-environment head))

  ;; --- history: an ordered, linked chain ending at the selected head ---
  (define history (boundary-bundle-history bundle))
  (when (null? history)
    (catalog-fail 'invalid-bundle "boundary bundle has no boundary history"))
  (unique-keys! (map boundary-record-key history) "BoundaryKey")
  (for ([record (in-list history)]
        [previous (in-list (cons #f (map boundary-record-key history)))])
    (unless (equal? (boundary-record-predecessor record) previous)
      (catalog-fail
       'invalid-bundle
       "boundary record ~a names predecessor ~a but follows ~a"
       (boundary-record-key record)
       (boundary-record-predecessor record) previous))
    (define recorded-key
      (case (boundary-record-origin-kind record)
        [(program) (tagged-clause (boundary-record-origin record) 'boundary-key)]
        [(transform) (tagged-clause (boundary-record-origin record) 'boundary)]
        ;; an attachment mints its key through the BoundaryPlan it embeds
        [(attachment)
         (for/or ([clause (in-list (cdr (boundary-record-origin record)))])
           (and (pair? clause) (eq? (car clause) 'boundary-plan)
                (tagged-clause clause 'boundary-key)))]
        [else (boundary-record-key record)]))
    (unless (equal? recorded-key (boundary-record-key record))
      (catalog-fail
       'invalid-bundle
       "boundary record ~a carries a plan that mints ~a"
       (boundary-record-key record) recorded-key)))
  (unless (equal? (boundary-record-key (last history)) (boundary-key head))
    (catalog-fail
     'invalid-bundle
     "boundary history ends at ~a but the selected head is ~a"
     (boundary-record-key (last history)) (boundary-key head)))

  ;; --- versions: every bound VersionKey is described, exactly once ---
  (define versions (boundary-bundle-versions bundle))
  (unique-keys! (map version-record-key versions) "VersionKey")
  (define version-index
    (for/hash ([record (in-list versions)])
      (values (version-record-key record) record)))
  (for ([record (in-list versions)])
    (define predecessor (version-record-predecessor record))
    (when (and predecessor (not (hash-has-key? version-index predecessor)))
      (catalog-fail 'dangling-version
                    "version ~a names unknown predecessor ~a"
                    (version-record-key record) predecessor))
    (define name (version-record-name record))
    (when name
      (define descriptor (hash-ref declarations name #f))
      (unless (and descriptor (storage-declaration? descriptor))
        (catalog-fail 'dangling-version
                      "version ~a names ~a, which the selected head does not declare"
                      (version-record-key record) (qname->display name)))
      (unless (eq? (version-record-kind record)
                   (declaration-descriptor-kind descriptor))
        (catalog-fail 'invalid-bundle
                      "version ~a is a ~a but ~a is declared ~a"
                      (version-record-key record)
                      (version-record-kind record)
                      (qname->display name)
                      (declaration-descriptor-kind descriptor)))))
  (for ([(name key) (in-hash environment)])
    (define record (hash-ref version-index key #f))
    (unless record
      (catalog-fail 'missing-version
                    "selected head binds ~a to undescribed VersionKey ~a"
                    (qname->display name) key))
    (unless (and (version-record-name record)
                 (qname=? (version-record-name record) name))
      (catalog-fail
       'invalid-bundle
       "VersionKey ~a is bound to ~a but its record names ~a"
       key (qname->display name)
       (let ([recorded (version-record-name record)])
         (if recorded (qname->display recorded) "no relation")))))

  ;; --- types: every nominal TypeKey is described, with a distinct SID ---
  (define types (boundary-bundle-types bundle))
  (unique-keys! (map type-record-key types) "TypeKey")
  (define saved-sids (filter values (map type-record-sid types)))
  (unique-keys! saved-sids "saved struct id")
  (define type-index
    (for/hash ([record (in-list types)]) (values (type-record-key record) record)))
  (for ([(name key) (in-hash nominals)])
    (define record (hash-ref type-index key #f))
    (unless record
      (catalog-fail 'missing-type
                    "selected head binds nominal ~a to undescribed TypeKey ~a"
                    (qname->display name) key))
    (unless (for/or ([recorded (in-list (type-record-names record))])
              (qname=? recorded name))
      (catalog-fail 'invalid-bundle
                    "TypeKey ~a is bound to ~a but records names ~a"
                    key (qname->display name)
                    (map qname->display (type-record-names record))))
    (define descriptor (hash-ref declarations name))
    (define stored-arity
      (add1 (length (declaration-descriptor-fields descriptor))))
    (unless (= (type-record-arity record) stored-arity)
      (catalog-fail 'invalid-bundle
                    "TypeKey ~a stores arity ~a but ~a declares ~a fields"
                    key (type-record-arity record) (qname->display name)
                    (length (declaration-descriptor-fields descriptor)))))

  ;; --- programs: keys unique, outputs land on committed boundaries ---
  (define programs (boundary-bundle-programs bundle))
  (unique-keys! (map program-record-key programs) "ProgramInstanceKey")
  (define boundary-keys
    (list->set (map boundary-record-key history)))
  (define module-keys
    (append*
     (for/list ([record (in-list programs)])
       (for/list ([module-datum (in-list (program-record-modules record))])
         (match module-datum
           [`(module-instance (key ,key) ,_ ...) key])))))
  (unique-keys! module-keys "ModuleInstanceKey")
  (for ([record (in-list programs)])
    (unless (set-member? boundary-keys (program-record-output record))
      (catalog-fail 'dangling-boundary
                    "program ~a outputs unknown boundary ~a"
                    (program-record-key record)
                    (program-record-output record)))
    (define input (program-record-input record))
    (when (and input (not (set-member? boundary-keys input)))
      (catalog-fail 'dangling-boundary
                    "program ~a reads unknown boundary ~a"
                    (program-record-key record) input)))
  bundle)

;; Restate a bundle as its own base: the selected head becomes a single
;; `initial` history record, superseded/dropped versions drop away, and no
;; program lineage is claimed.  This is what a FROZEN root carries -- its
;; history was deliberately cut, so keeping transition records that name
;; boundaries the database no longer contains would be a lie.
;;
;; Type records are kept WHOLE, including those no name binds: live rows still
;; embed those SIDs, so their descriptors remain part of what the database
;; needs to decode itself.
(define (boundary-bundle-cut-history bundle)
  (validate-boundary-bundle bundle)
  (define head (boundary-bundle-selected-head bundle))
  (define environment (boundary-environment head))
  (define bound (list->set (hash-values environment)))
  (define cut
    (boundary-bundle
     (boundary-bundle-format bundle)
     head
     (list (boundary-record (boundary-key head) #f 'initial #f))
     (for/list ([record (in-list (boundary-bundle-versions bundle))]
                #:when (set-member? bound (version-record-key record)))
       (version-record (version-record-key record) #f
                       (version-record-kind record)
                       (version-record-name record)
                       #t))
     (boundary-bundle-types bundle)
     '()))
  (validate-boundary-bundle cut)
  cut)

;; N4-A work order 4: the boundary that RESTORES a saved head verbatim.
;;
;; Unlike every other producer here this mints nothing.  The output boundary
;; IS the persisted head -- same BoundaryKey, same VersionKeys, same TypeKeys
;; -- so opening a saved database preserves its stable identity instead of
;; re-deriving it.  Every storage declaration is an initial `create`, which is
;; what the daemon's admission rules already accept for names it does not yet
;; hold; runtime SIDs are assigned fresh at that point and the caller maps
;; saved-SID to live-SID explicitly.
;; `storage-order` reorders the create actions.  Runtime SIDs are assigned in
;; action order, so reversing it forces every nominal onto a DIFFERENT live
;; SID than it was saved with -- the fixture the "forced SID reassignment
;; still decodes" gate needs.  Ordering carries no identity: VersionKeys and
;; TypeKeys do, and both are persisted.
(define (plan-bundle-restore bundle #:storage-order [storage-order values])
  (validate-boundary-bundle bundle)
  (define head (boundary-bundle-selected-head bundle))
  (define cat (boundary-catalog head))
  (define declarations (catalog-declarations cat))
  (define nominals (catalog-nominals cat))
  (define environment (boundary-environment head))
  (define storage
    (storage-order
     (sorted-qnames
      (for/list ([(name descriptor) (in-hash declarations)]
                 #:when (storage-declaration? descriptor))
        name))))
  (define actions
    (for/list ([name (in-list storage)])
      (boundary-action 'create name (hash-ref environment name) #f
                       (hash-ref nominals name #f))))
  (define version-slots
    (for/hash ([name (in-list storage)] [slot (in-naturals)])
      (values name slot)))
  (define type-slots
    (for/hash ([name (in-list (sorted-qnames (hash-keys nominals)))]
               [slot (in-naturals)])
      (values name slot)))
  ;; The producing program, when the bundle still records it; a cut-history
  ;; root records none, and the daemon only needs a nonempty handle.
  (define program
    (or (for/or ([record (in-list (boundary-bundle-programs bundle))]
                 #:when (equal? (program-record-output record)
                                (boundary-key head)))
          (program-record-key record))
        (format "restore:~a" (boundary-key head))))
  (boundary-plan
   "restore" 0 0 0
   program
   (boundary-key head)
   (empty-boundary "b0:restore")
   head
   (catalog-delta declarations (catalog-memberships cat))
   actions version-slots type-slots))

;; The loader's saved-SID-to-live-SID substrate: TypeKey -> saved SID for
;; every nominal that recorded one.  Runtime SIDs may be reassigned on open,
;; so this is the left-hand side of the explicit map, never an assertion that
;; the live daemon uses the same id.
(define (boundary-bundle-type-key->sid bundle)
  (for/hash ([record (in-list (boundary-bundle-types bundle))]
             #:when (type-record-sid record))
    (values (type-record-key record) (type-record-sid record))))

;; -----------------------------------------------------------------------
;; N4-B mapped namespace attachment (docs/n4-contract.md §5)
;;
;; Attachment is a PURE plan over two catalogs: a saved bundle's selected head
;; and the destination boundary.  Nothing here contacts the daemon or the
;; filesystem -- the caller supplies which source relations actually carry
;; materialization -- so the complete schema, key, and type decision is made
;; and checkable before any content moves.
;;
;; The allocator is `plan-boundary`, unchanged.  Its established behaviour is
;; exactly §5's mapping rules: an added declaration mints a fresh VersionKey,
;; an existing one advances only when it is in the write set, an added struct
;; mints a fresh TypeKey while an existing one keeps the destination's, and an
;; overlapping declaration must be EXACTLY compatible or the plan refuses.
;; N4-B therefore adds no second compatibility checker or key allocator.

(struct attachment-plan
  (layer-id event source-stamp source-boundary-key source-path
   destination-path boundary-plan version-map type-map imports)
  #:transparent)

(define (attachment-plan-boundary-key plan)
  (boundary-plan-boundary-key (attachment-plan-boundary-plan plan)))

(define (attachment-plan-output plan)
  (boundary-plan-output (attachment-plan-boundary-plan plan)))

;; One path may not be both a declaration and a namespace.  Attachment checks
;; only the names it INTRODUCES -- against the whole output -- so a
;; pre-existing catalog is never retroactively rejected.
(define (check-attachment-shape added existing)
  (define all (set-union added existing))
  (for* ([name (in-set added)] [other (in-set all)])
    (when (qname-inside? other name)
      (catalog-fail 'occupied-target
                    "attachment target ~a is also a namespace containing ~a"
                    (qname->display name) (qname->display other)))
    (when (qname-inside? name other)
      (catalog-fail 'occupied-target
                    "attachment target ~a nests inside declaration ~a"
                    (qname->display name) (qname->display other)))))

(define (plan-attachment source-bundle destination
                         #:source-path [source-path #f]
                         #:destination-path destination-path
                         #:content [content (set)]
                         #:source-stamp [source-stamp #f]
                         #:layer-id layer-id
                         #:event event)
  (validate-boundary-bundle source-bundle)
  (validate-boundary destination)
  (check-key-input 'attachment layer-id event)
  (define destination-root (name->qname 'attachment destination-path))
  (define source-root (and source-path (name->qname 'attachment source-path)))
  (define source-head (boundary-bundle-selected-head source-bundle))
  (define source-catalog (boundary-catalog source-head))
  (define source-declarations (catalog-declarations source-catalog))
  (define source-memberships (catalog-memberships source-catalog))
  (define source-environment (boundary-environment source-head))
  (define source-nominals (catalog-nominals source-catalog))

  ;; --- selection: the saved root, or the subtree at SOURCE ---------------
  (define (selected? name)
    (or (not source-root) (qname-at-or-inside? name source-root)))
  (define selected
    (for/set ([name (in-hash-keys source-declarations)] #:when (selected? name))
      name))
  (when (set-empty? selected)
    (catalog-fail 'unknown-path
                  "attachment source path selects nothing: ~a"
                  (if source-root (qname->display source-root) "<root>")))

  ;; --- dependency closure: nothing may escape the selection --------------
  ;; Primitives are not names and never escape; a reference or membership
  ;; edge leaving the subtree would arrive at the destination pointing into a
  ;; namespace this attachment does not carry.
  (for ([name (in-set selected)])
    (for ([reference (in-set (declaration-references
                              (hash-ref source-declarations name)))])
      (unless (set-member? selected reference)
        (catalog-fail
         'escaping-dependency
         "~a references ~a, which lies outside the attached subtree"
         (qname->display name) (qname->display reference)))))
  ;; A membership endpoint that is not a declaration at all is a builtin
  ;; member (`cmap` in `coll`, say) -- an opaque leaf with nothing outside the
  ;; subtree to point at, so it neither escapes nor moves.
  (define (declared? name) (hash-has-key? source-declarations name))
  (define (escapes? name) (and (declared? name) (not (set-member? selected name))))
  (for ([edge (in-set source-memberships)])
    (define touched?
      (or (set-member? selected (car edge)) (set-member? selected (cdr edge))))
    (when (and touched? (or (escapes? (car edge)) (escapes? (cdr edge))))
      (catalog-fail
       'escaping-dependency
       "membership ~a in ~a crosses the attached subtree boundary"
       (qname->display (car edge)) (qname->display (cdr edge)))))

  ;; --- component-wise prefix substitution --------------------------------
  ;; Only SELECTED declarations move.  A builtin membership member keeps its
  ;; own spelling: prefixing `cmap` would invent a declaration that does not
  ;; exist on either side.
  (define (attach-name name)
    (cond
      [(not (set-member? selected name)) name]
      [source-root (qname-rebase name source-root destination-root)]
      [else (qname-prepend (qname-components destination-root) name)]))
  (define rewritten
    (for/hash ([name (in-set selected)])
      (values (attach-name name)
              (rewrite-declaration (hash-ref source-declarations name)
                                   attach-name))))
  (unless (= (hash-count rewritten) (set-count selected))
    (catalog-fail 'duplicate-key
                  "prefix substitution collapsed two source declarations"))
  (define rewritten-memberships
    (for/set ([edge (in-set source-memberships)]
              #:when (set-member? selected (cdr edge)))
      (cons (attach-name (car edge)) (attach-name (cdr edge)))))

  (define destination-declarations
    (catalog-declarations (boundary-catalog destination)))
  (check-attachment-shape
   (for/set ([name (in-hash-keys rewritten)]
             #:unless (hash-has-key? destination-declarations name))
     name)
   (list->set (hash-keys destination-declarations)))

  ;; --- the write set: destinations that actually receive source rows -----
  ;; A fresh declaration gets its VersionKey from `plan-boundary` whether or
  ;; not content follows; an EXISTING compatible member advances only when
  ;; source content lands in it (§5), so an empty source member leaves the
  ;; destination version exactly where it was.
  (define imports
    (sort
     (for/list ([name (in-set selected)]
                #:when (and (storage-declaration? (hash-ref source-declarations name))
                            (set-member? content name)))
       (cons name (attach-name name)))
     qname<? #:key car))
  (define writes (map cdr imports))

  (define plan
    (plan-boundary destination
                   (catalog-delta rewritten rewritten-memberships)
                   writes
                   #:layer-id layer-id
                   #:program-event event
                   #:boundary-event event
                   #:type-event event))
  (define output (boundary-plan-output plan))
  (define output-environment (boundary-environment output))
  (define output-nominals (catalog-nominals (boundary-catalog output)))

  ;; --- the explicit maps -------------------------------------------------
  ;; Source identity is never reused: every entry maps a source key to the
  ;; key the DESTINATION boundary holds, so attaching one source twice yields
  ;; two disjoint right-hand sides.
  (define version-map
    (for/list ([name (in-list (sorted-qnames
                               (for/list ([name (in-set selected)]
                                          #:when (hash-has-key? source-environment name))
                                 name)))])
      (cons (hash-ref source-environment name)
            (hash-ref output-environment (attach-name name)))))
  (define type-map
    (for/list ([name (in-list (sorted-qnames
                               (for/list ([name (in-set selected)]
                                          #:when (hash-has-key? source-nominals name))
                                 name)))])
      (cons (hash-ref source-nominals name)
            (hash-ref output-nominals (attach-name name)))))

  (attachment-plan layer-id event source-stamp
                   (boundary-key source-head)
                   source-root destination-root
                   plan version-map type-map imports))

(define (attachment-plan->datum plan)
  (unless (attachment-plan? plan)
    (catalog-fail 'invalid-attachment "expected an attachment plan; got ~a" plan))
  `(attachment-plan
    (layer-id ,(attachment-plan-layer-id plan))
    (event ,(attachment-plan-event plan))
    (source
     (stamp ,(attachment-plan-source-stamp plan))
     (boundary ,(attachment-plan-source-boundary-key plan))
     (path ,(let ([path (attachment-plan-source-path plan)])
              (and path (qname->datum path)))))
    (destination
     (path ,(qname->datum (attachment-plan-destination-path plan))))
    (version-map
     ,@(for/list ([entry (in-list (attachment-plan-version-map plan))])
         `(v ,(car entry) ,(cdr entry))))
    (type-map
     ,@(for/list ([entry (in-list (attachment-plan-type-map plan))])
         `(t ,(car entry) ,(cdr entry))))
    (imports
     ,@(for/list ([entry (in-list (attachment-plan-imports plan))])
         `(import ,(qname->datum (car entry)) ,(qname->datum (cdr entry)))))
    ,(boundary-plan->datum (attachment-plan-boundary-plan plan))))

(define (attachment-plan-datum? datum)
  (with-handlers ([exn:fail? (lambda (_error) #f)])
    (match datum
      [`(attachment-plan
         (layer-id ,(? non-empty-string?))
         (event ,(? exact-nonnegative-integer?))
         (source (stamp ,_) (boundary ,(? non-empty-string?)) (path ,path))
         (destination (path ,destination))
         (version-map ,versions ...)
         (type-map ,types ...)
         (imports ,imports ...)
         ,boundary)
       (when path (datum->qname path))
       (datum->qname destination)
       (for ([entry (in-list versions)])
         (match entry
           [`(v ,(? non-empty-string?) ,(? non-empty-string?)) #t]
           [_ (catalog-fail 'invalid-attachment
                            "malformed VersionKey map entry: ~a" entry)]))
       (for ([entry (in-list types)])
         (match entry
           [`(t ,(? non-empty-string?) ,(? non-empty-string?)) #t]
           [_ (catalog-fail 'invalid-attachment
                            "malformed TypeKey map entry: ~a" entry)]))
       (for ([entry (in-list imports)])
         (match entry
           [`(import ,from ,to) (datum->qname from) (datum->qname to)]
           [_ (catalog-fail 'invalid-attachment
                            "malformed import entry: ~a" entry)]))
       (boundary-plan-datum? boundary)]
      [_ #f])))

;; Replay recomputes the attachment from the same source bundle and the
;; reconstructed destination boundary under the persisted identity, then
;; refuses any disagreement -- the recorded plan is self-auditing, so a source
;; whose catalog, keys, or content coverage drifted cannot replay silently.
(define (replay-attachment source-bundle destination content datum)
  (unless (attachment-plan-datum? datum)
    (catalog-fail 'invalid-attachment
                  "malformed persisted attachment plan: ~a" datum))
  (match-define
    `(attachment-plan
      (layer-id ,layer-id)
      (event ,event)
      (source (stamp ,stamp) (boundary ,source-boundary) (path ,path))
      (destination (path ,destination-path))
      ,_ ...)
    datum)
  (define plan
    (plan-attachment source-bundle destination
                     #:source-path (and path (datum->qname path))
                     #:destination-path (datum->qname destination-path)
                     #:content content
                     #:source-stamp stamp
                     #:layer-id layer-id
                     #:event event))
  (unless (equal? (attachment-plan-source-boundary-key plan) source-boundary)
    (catalog-fail 'replay-divergence
                  "attachment source boundary was ~a but the recipe recorded ~a"
                  (attachment-plan-source-boundary-key plan) source-boundary))
  (unless (equal? datum (attachment-plan->datum plan))
    (catalog-fail
     'replay-divergence
     "replayed attachment differs from its persisted plan:\n  stored ~a\n  rebuilt ~a"
     datum (attachment-plan->datum plan)))
  plan)

(define (type-ref->symbol ref)
  (match ref
    [(type-ref 'primitive (? symbol? name)) name]
    [(type-ref 'named (? qname? name)) (qname->symbol name)]
    [_ (catalog-fail 'invalid-type "invalid normalized TypeRef: ~a" ref)]))

(define (lattice-descriptor->datum spec)
  (define kind (lattice-descriptor-kind spec))
  (define args
    (for/list ([argument (in-list (lattice-descriptor-arguments spec))])
      (cond
        [(type-ref? argument) (type-ref->symbol argument)]
        [(lattice-descriptor? argument)
         (cdr (lattice-descriptor->datum argument))]
        [else (catalog-fail 'invalid-lattice
                            "invalid normalized lattice argument: ~a" argument)])))
  `(lattice ,kind ,@args
            ,@(for/list ([parameter
                         (in-list (lattice-descriptor-parameters spec))])
                (list (car parameter) (cdr parameter)))))

(define (declarations->manifest declarations)
  (for/fold ([manifest (hash)])
            ([name (in-list (sort (hash-keys declarations) qname<?))])
    (define descriptor (hash-ref declarations name))
    (define symbol-name (qname->symbol name))
    (match (declaration-descriptor-kind descriptor)
      ['table
       (define arity (length (declaration-descriptor-fields descriptor)))
       (define spec (declaration-descriptor-lattice-spec descriptor))
       (hash-set manifest symbol-name
                 (if spec
                     `(lat ,symbol-name ,arity
                           ,(lattice-descriptor->datum spec))
                     `(rel ,symbol-name ,arity)))]
      ['struct
       ;; Struct storage includes the runtime intern ID column.
       (hash-set manifest symbol-name
                 `(struct ,symbol-name
                          ,(add1
                            (length
                             (declaration-descriptor-fields descriptor)))))]
      [_ manifest])))

(define (catalog->manifest cat)
  (unless (catalog? cat)
    (catalog-fail 'invalid-catalog "expected catalog; got ~a" cat))
  (declarations->manifest (catalog-declarations cat)))

;; Recover the typed compiler view of a logical catalog.  Unlike the legacy
;; manifest projection this preserves field types, nominal references,
;; memberships, and lattice structure, so N1 namespace bindings can validate
;; against an inherited boundary without guessing schema from arities.
(define (catalog->type-env cat)
  (unless (catalog? cat)
    (catalog-fail 'invalid-catalog "expected catalog; got ~a" cat))
  (define (ref->name ref)
    (match ref
      [(type-ref 'primitive name) name]
      [(type-ref 'named (? qname? name)) (qname->symbol name)]
      [_ (catalog-fail 'invalid-type "invalid normalized TypeRef: ~a" ref)]))
  (define (lattice->datum spec)
    `(lattice
      ,(lattice-descriptor-kind spec)
      ,@(for/list ([argument
                    (in-list (lattice-descriptor-arguments spec))])
          (cond
            [(type-ref? argument) (ref->name argument)]
            [(lattice-descriptor? argument)
             (cdr (lattice->datum argument))]
            [else
             (catalog-fail 'invalid-lattice
                           "invalid normalized lattice argument: ~a"
                           argument)]))
      ,@(for/list ([parameter
                    (in-list (lattice-descriptor-parameters spec))])
          (list (car parameter) (cdr parameter)))))
  (define declarations (catalog-declarations cat))
  (define rels
    (for/fold ([out (hash)])
              ([(name descriptor) (in-hash declarations)]
               #:unless (eq? 'union
                             (declaration-descriptor-kind descriptor)))
      (define lowered (qname->symbol name))
      (define fields (map ref->name
                          (declaration-descriptor-fields descriptor)))
      (define declaration
        (match (declaration-descriptor-kind descriptor)
          ['table `(table ,@fields)]
          ['struct `(struct ,@fields)]
          ['enum `(enum ,lowered)]
          ['lattice
           (lattice->datum
            (declaration-descriptor-lattice-spec descriptor))]
          ['list `(listof ,@fields)]
          ['map `(mapof ,@fields)]
          [kind
           (catalog-fail 'invalid-declaration
                         "cannot recover compiler declaration kind ~a" kind)]))
      (hash-set out lowered declaration)))
  (define aliases
    (for/fold ([out (hash)])
              ([(name descriptor) (in-hash declarations)]
               #:when (eq? 'union
                           (declaration-descriptor-kind descriptor)))
      (define members
        (for/set ([edge (in-set (catalog-memberships cat))]
                  #:when (qname=? name (cdr edge)))
          (qname->symbol (car edge))))
      (define lowered (qname->symbol name))
      (hash-set out lowered (set-add members lowered))))
  (list aliases rels (type-env-funs empty-type-env)))

(define (catalog-delta->manifest delta)
  (unless (catalog-delta? delta)
    (catalog-fail 'invalid-delta "expected CatalogDelta; got ~a" delta))
  (declarations->manifest (catalog-delta-declarations delta)))

;; The `$...` relations synthesized by today's demand/sequence machinery are
;; execution-local compiler artifacts, not QName declarations in C_k
;; (docs/modules.md §8.3 explicitly retires this convention in favor of
;; internal IDs/path components).  Keep them in the old code-generation
;; manifest until N1 performs that lowering, without admitting an invalid
;; public QName into the logical catalog.
(define (internal-type-env-manifest type-env)
  (define rels (type-env-rels type-env))
  (for/fold ([manifest (hash)])
            ([name (in-list (sort (filter internal-symbol? (hash-keys rels))
                                  symbol<?))])
    (match (hash-ref rels name)
      [`(table ,fields ...)
       (define spec (rel-lattice-spec rels name))
       (hash-set manifest name
                 (if spec
                     `(lat ,name ,(length fields) ,spec)
                     `(rel ,name ,(length fields))))]
      [`(struct ,fields ...)
       (hash-set manifest name `(struct ,name ,(add1 (length fields))))]
      [`(temp ,_ ...) manifest]
      [`(oracle ,_ ...) manifest]
      [(? lattice-spec?) manifest]
      [(? listof-spec?) manifest]
      [(? mapof-spec?) manifest]
      [other
       (catalog-fail 'invalid-declaration
                     "unrecognized internal declaration for ~a: ~a"
                     name other)])))

(define (type-env->legacy-manifest type-env)
  (merge-legacy-manifest
   (catalog-delta->manifest (type-env->catalog-delta type-env))
   (internal-type-env-manifest type-env)))

;; Compatibility bridge for the current code-generation ABI.  This does not
;; reconstruct a logical catalog from BIN/schema output: the projection is
;; intentionally one-way.
(define (merge-legacy-manifest input projected)
  (unless (and (hash? input) (hash? projected))
    (catalog-fail 'invalid-manifest "legacy manifests must be hashes"))
  (define immutable-input
    (for/hash ([(name entry) (in-hash input)]) (values name entry)))
  (for/fold ([manifest immutable-input])
            ([name (in-list (sort (hash-keys projected) symbol<?))])
    (define entry (hash-ref projected name))
    (cond
      [(not (hash-has-key? manifest name))
       (hash-set manifest name entry)]
      [(equal? (hash-ref manifest name) entry) manifest]
      [else
       (define label
         (match entry
           [`(lat ,_ ,_ ,_) "Lattice relation"]
           [`(rel ,_ ,_) "Table"]
           [`(struct ,_ ,_) "Struct"]
           [_ "Relation"]))
       (catalog-fail
        'legacy-manifest-mismatch
        "~a declaration does not match input database: ~a"
        label name)])))
