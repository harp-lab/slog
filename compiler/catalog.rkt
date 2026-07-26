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
 (struct-out exn:fail:catalog)
 empty-catalog
 empty-boundary
 storage-declaration?
 declaration-references
 type-env->catalog-delta
 plan-boundary
 replay-boundary-plan
 boundary-plan->datum
 boundary-plan-datum?
 declaration-descriptor->datum
 catalog-delta->datum
 datum->catalog-delta
 catalog->manifest
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
                    (sort
                     (set->list (catalog-delta-memberships delta))
                     (lambda (left right)
                       (or (qname<? (cdr left) (cdr right))
                           (and (qname=? (cdr left) (cdr right))
                                (qname<? (car left) (car right)))))))])
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
