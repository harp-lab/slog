#lang racket

;; Pure catalog-driven construction of Q1 executable query plans.
;;
;; This module deliberately owns no daemon/session transport.  Its input is an
;; immutable snapshot of one selected boundary: logical names and field types
;; together with the exact VersionKey, existing full-index orders, and tuple
;; count of each materialized relation.  Its output mirrors daemon/query.h but
;; retains VersionKey bindings and explain annotations for the future T0 wire
;; adapter.

(provide (struct-out query-catalog)
         (struct-out query-relation)
         (struct-out query-boundary)
         (struct-out query-declaration)
         (struct-out query-materialization)
         (struct-out query-request)
         (struct-out query-atom)
         (struct-out query-guard)
         (struct-out query-compute)
         (struct-out query-literal)
         (struct-out query-binding)
         (struct-out query-plan)
         (struct-out query-explain)
         (struct-out qp-literal)
         (struct-out qp-driver)
         (struct-out qp-probe)
         (struct-out qp-filter)
         (struct-out qp-eq)
         (struct-out qp-neq)
         (struct-out qp-prim)
         (struct-out query-degradation)
         (struct-out exn:fail:query-plan)
         query-catalog-from-boundary
         plan-query
         query-plan->datum
         query-plan->wire-datum
         query-plan->wire-string
         query-primitive-spec)

(require racket/list
         racket/match
         racket/set)

;; -------------------------------------------------------------------------
;; Public planning boundary.

;; relations : immutable hash QName -> query-relation.  plan-query defensively
;; copies it so callers cannot mutate the snapshot during construction.
(struct query-catalog (boundary-key generation relations) #:transparent)

;; field-types are source-level types used for query checking. Runtime-only
;; orderings/counts remain beside, not inside, declaration compatibility.
(struct query-relation
  (name version-key kind field-types full-orders tuple-count)
  #:transparent)

;; N2/N3 adapter input.  The three maps intentionally preserve the
;; architecture's separation:
;;   declarations    : QName -> logical declaration (C_k)
;;   environment     : QName -> exact VersionKey (E_k)
;;   materializations: VersionKey -> runtime index/count facts
;; Empty declarations therefore remain present even when tuple-count is zero;
;; daemon schema/directory discovery is not a substitute for this input.
(struct query-boundary
  (key generation declarations environment materializations)
  #:transparent)
(struct query-declaration (name kind field-types) #:transparent)
(struct query-materialization
  (version-key kind arity full-orders tuple-count)
  #:transparent)

;; Terms are symbols (variables) or query-literal values.  Positive and
;; negative atoms share one representation; a negative atom is a snapshot
;; absence filter and never introduces variables.
(struct query-request (mode atoms guards computes project) #:transparent)
(struct query-atom (relation terms negated?) #:transparent)
(struct query-guard (kind left right) #:transparent)
(struct query-compute (kind name output args) #:transparent)
(struct query-literal (kind text) #:transparent)

;; -------------------------------------------------------------------------
;; Executable output, intentionally isomorphic to daemon/query.h::Plan.

(struct query-binding
  (slot name version-key kind arity field-types full-orders tuple-count)
  #:transparent)
(struct qp-literal (reg kind text) #:transparent)
(struct qp-driver (relation order regs) #:transparent)
(struct qp-probe (relation order bound regs) #:transparent)
(struct qp-filter (kind relation order bound regs) #:transparent)
(struct qp-eq (left right) #:transparent)
(struct qp-neq (left right) #:transparent)
(struct qp-prim (kind name output args) #:transparent)
(struct query-degradation (kind relation detail) #:transparent)
(struct query-explain
  (estimated-cost driver schedule degradations)
  #:transparent)
(struct query-plan
  (boundary-key generation bindings nregs preloads literals preops driver body
                project mode explain)
  #:transparent)

(struct exn:fail:query-plan exn:fail (kind detail) #:transparent)

;; daemon/index.h's frozen cursor ladder bound. Keep the pure front-end
;; refusal aligned with seal-time capability instead of emitting a doomed
;; plan.
(define max-query-arity 64)

(define (query-fail kind fmt . args)
  (define message (apply format fmt args))
  (raise (exn:fail:query-plan
          (format "query plan [~a]: ~a" kind message)
          (current-continuation-marks) kind message)))

(define (storage-kind kind)
  (case kind
    [(table plain) 'plain]
    [(struct) 'struct]
    [(lattice) 'lattice]
    [else #f]))

(define (query-catalog-from-boundary boundary)
  (unless (query-boundary? boundary)
    (query-fail 'catalog "expected a query-boundary"))
  (unless (exact-nonnegative-integer? (query-boundary-generation boundary))
    (query-fail 'catalog "boundary generation must be nonnegative"))
  (for ([field (in-list (list (query-boundary-declarations boundary)
                              (query-boundary-environment boundary)
                              (query-boundary-materializations boundary)))])
    (unless (hash? field)
      (query-fail 'catalog "boundary maps must be hashes")))
  (define declarations (query-boundary-declarations boundary))
  (define environment (query-boundary-environment boundary))
  (define materializations (query-boundary-materializations boundary))

  ;; Every environment binding names one declared storage member, and every
  ;; storage declaration has a slot even when empty. Non-storage type/member
  ;; descriptors may coexist in C_k and are not projected into QueryPlan.
  (for ([(name version-key) (in-hash environment)])
    (unless (hash-has-key? declarations name)
      (query-fail 'catalog "environment binds undeclared relation ~s" name))
    (unless (hash-has-key? materializations version-key)
      (query-fail 'catalog
                  "relation ~s VersionKey ~s has no materialization facts"
                  name version-key)))
  (for ([(name declaration) (in-hash declarations)])
    (unless (query-declaration? declaration)
      (query-fail 'catalog "declaration ~s is malformed" name))
    (unless (equal? name (query-declaration-name declaration))
      (query-fail 'catalog "declaration key/name mismatch for ~s" name))
    (when (storage-kind (query-declaration-kind declaration))
      (unless (hash-has-key? environment name)
        (query-fail 'catalog
                    "storage declaration ~s has no boundary VersionKey" name))))

  (query-catalog
   (query-boundary-key boundary)
   (query-boundary-generation boundary)
   (for/hash ([(name version-key) (in-hash environment)])
     (define declaration (hash-ref declarations name))
     (define materialization (hash-ref materializations version-key))
     (unless (query-materialization? materialization)
       (query-fail 'catalog "VersionKey ~s materialization is malformed"
                   version-key))
     (unless (equal? version-key
                     (query-materialization-version-key materialization))
       (query-fail 'catalog "materialization key/VersionKey mismatch for ~s"
                   name))
     (define logical-kind (storage-kind (query-declaration-kind declaration)))
     (define runtime-kind (storage-kind
                           (query-materialization-kind materialization)))
     (unless (and logical-kind (eq? logical-kind runtime-kind))
       (query-fail 'catalog
                   "relation ~s logical/runtime kinds disagree: ~s versus ~s"
                   name (query-declaration-kind declaration)
                   (query-materialization-kind materialization)))
     (unless (list? (query-declaration-field-types declaration))
       (query-fail 'catalog "relation ~s field types must be a list" name))
     (unless (= (length (query-declaration-field-types declaration))
                (query-materialization-arity materialization))
       (query-fail 'catalog
                   "relation ~s logical/runtime arities disagree" name))
     (values
      name
      (query-relation
       name version-key logical-kind
       (query-declaration-field-types declaration)
       (query-materialization-full-orders materialization)
       (query-materialization-tuple-count materialization))))))

;; -------------------------------------------------------------------------
;; Validation and type constraints.

(define (name-key value) (format "~s" value))

(define (lexicographic<? xs ys)
  (cond
    [(null? xs) (pair? ys)]
    [(null? ys) #f]
    [(< (car xs) (car ys)) #t]
    [(> (car xs) (car ys)) #f]
    [else (lexicographic<? (cdr xs) (cdr ys))]))

(define (valid-order? order arity)
  (and (list? order)
       (= (length order) arity)
       (andmap exact-nonnegative-integer? order)
       (equal? (sort order <) (range arity))))

(define (literal-type literal)
  (unless (string? (query-literal-text literal))
    (query-fail 'literal "literal payload must be text, received ~s"
                (query-literal-text literal)))
  (match (query-literal-kind literal)
    ['integer 'int]
    ['real 'float]
    ['string 'str]
    [kind (query-fail 'literal "unsupported literal kind ~s" kind)]))

(define (term? term) (or (symbol? term) (query-literal? term)))

(define (term-vars terms)
  (for/set ([term (in-list terms)] #:when (symbol? term)) term))

(define (type-meet left right)
  (cond
    [(equal? left right) left]
    [(eq? left 'any) right]
    [(eq? right 'any) left]
    [(and (eq? left 'numeric) (memq right '(int float))) right]
    [(and (eq? right 'numeric) (memq left '(int float))) left]
    [else #f]))

(define primitive-specs
  ;; name -> (kind input-types output-type).  This is the frontend projection
  ;; of query.cpp's audited registry; comparisons are represented as guards.
  (hash
   'tofloat '(total (numeric) float)
   'size    '(total (any) int)
   'sidx    '(partial (str str) int)
   'shas    '(total (str str) int)
   'aslst   '(partial (any) seq)
   'llen    '(total (seq) int)
   'lref    '(partial (seq int) any)
   'lidx    '(partial (seq any) int)
   'lmem    '(total (seq any) int)))

(define comparison-kinds '(lt le gt ge))
(define equality-kinds '(eq neq))

;; The R2 front end asks which audited primitive a surface (= X (op ...))
;; names; #f means "not in the query whitelist" (the surface language's
;; primitive set is much larger).
(define (query-primitive-spec name)
  (hash-ref primitive-specs (normalize-primitive-name name) #f))

(define (normalize-primitive-name name)
  (cond [(symbol? name) name]
        [(string? name) (string->symbol name)]
        [else (query-fail 'unsafe-compute "invalid primitive name ~s" name)]))

(define (validate-catalog catalog)
  (unless (query-catalog? catalog)
    (query-fail 'catalog "expected a query-catalog"))
  (unless (exact-nonnegative-integer? (query-catalog-generation catalog))
    (query-fail 'catalog "generation must be an exact nonnegative integer"))
  (unless (hash? (query-catalog-relations catalog))
    (query-fail 'catalog "relations must be a hash"))
  (for/hash ([(name relation) (in-hash (query-catalog-relations catalog))])
    (unless (query-relation? relation)
      (query-fail 'catalog "~s is not a query-relation" name))
    (unless (equal? name (query-relation-name relation))
      (query-fail 'catalog "relation key/name mismatch for ~s" name))
    (unless (query-relation-version-key relation)
      (query-fail 'catalog "relation ~s has no VersionKey" name))
    (unless (list? (query-relation-field-types relation))
      (query-fail 'catalog "relation ~s field types must be a list" name))
    (define arity (length (query-relation-field-types relation)))
    (unless (and (positive? arity) (<= arity max-query-arity))
      (query-fail 'catalog
                  "relation ~s arity ~a is outside the daemon range 1..~a"
                  name arity max-query-arity))
    (unless (and (list? (query-relation-full-orders relation))
                 (exact-nonnegative-integer?
                  (query-relation-tuple-count relation))
                 (pair? (query-relation-full-orders relation)))
      (query-fail 'catalog
                  "relation ~s needs a tuple count and at least one full index"
                  name))
    (for ([order (in-list (query-relation-full-orders relation))])
      (unless (valid-order? order arity)
        (query-fail 'catalog "relation ~s has invalid full order ~s"
                    name order)))
    (values name
            (struct-copy query-relation relation
              [full-orders
               (sort (remove-duplicates
                      (query-relation-full-orders relation))
                     lexicographic<?)]))))

(define (resolve-request request relations)
  (unless (query-request? request)
    (query-fail 'request "expected a query-request"))
  (unless (memq (query-request-mode request) '(rows count exists))
    (query-fail 'request "unsupported result mode ~s"
                (query-request-mode request)))
  (unless (and (list? (query-request-atoms request))
               (list? (query-request-guards request))
               (list? (query-request-computes request))
               (list? (query-request-project request)))
    (query-fail 'request "atoms, guards, computes, and projection must be lists"))
  (unless (andmap symbol? (query-request-project request))
    (query-fail 'request "projection must contain variables"))
  (when (and (eq? (query-request-mode request) 'rows)
             (null? (query-request-project request)))
    (query-fail 'request "row mode requires a nonempty projection"))
  (when (> (length (query-request-project request)) max-query-arity)
    (query-fail 'limit "projection is wider than the daemon ABI (~a)"
                max-query-arity))

  (for/list ([atom (in-list (query-request-atoms request))]
             [id (in-naturals)])
    (unless (query-atom? atom)
      (query-fail 'request "body item ~a is not an atom" id))
    (define relation
      (hash-ref relations (query-atom-relation atom)
                (lambda ()
                  (query-fail 'unknown-relation "unknown relation ~s"
                              (query-atom-relation atom)))))
    (unless (eq? (query-relation-kind relation) 'plain)
      (query-fail 'relation-kind
                  "Q1 v1 planner supports ordinary tables, not ~s relation ~s"
                  (query-relation-kind relation)
                  (query-relation-name relation)))
    (unless (list? (query-atom-terms atom))
      (query-fail 'request "relation ~s terms must be a list"
                  (query-relation-name relation)))
    (unless (= (length (query-atom-terms atom))
               (length (query-relation-field-types relation)))
      (query-fail 'arity "relation ~s expects ~a terms, received ~a"
                  (query-relation-name relation)
                  (length (query-relation-field-types relation))
                  (length (query-atom-terms atom))))
    (unless (andmap term? (query-atom-terms atom))
      (query-fail 'request "relation ~s contains an invalid term"
                  (query-relation-name relation)))
    (ratom id atom relation)))

(define (check-types! request resolved-atoms)
  (define variable-types (make-hash))
  (define (constrain-variable! variable expected where)
    (define old (hash-ref variable-types variable 'any))
    (define next (type-meet old expected))
    (unless next
      (query-fail 'type "variable ~s has incompatible types ~s and ~s at ~a"
                  variable old expected where))
    (hash-set! variable-types variable next))
  (define (constrain-term! term expected where)
    (cond
      [(symbol? term) (constrain-variable! term expected where)]
      [(query-literal? term)
       (unless (type-meet (literal-type term) expected)
         (query-fail 'type "literal ~s is incompatible with ~s at ~a"
                     term expected where))]))

  (for ([resolved (in-list resolved-atoms)])
    (for ([term (in-list (query-atom-terms (ratom-atom resolved)))]
          [type (in-list (query-relation-field-types
                          (ratom-relation resolved)))]
          [column (in-naturals)])
      (constrain-term!
       term type
       (format "~a column ~a" (query-relation-name (ratom-relation resolved))
               column))))

  (for ([compute (in-list (query-request-computes request))]
        [id (in-naturals)])
    (unless (query-compute? compute)
      (query-fail 'request "compute ~a is malformed" id))
    (unless (symbol? (query-compute-output compute))
      (query-fail 'request "compute ~a output must be a variable" id))
    (unless (list? (query-compute-args compute))
      (query-fail 'request "compute ~a arguments must be a list" id))
    (unless (andmap term? (query-compute-args compute))
      (query-fail 'request "compute ~a contains an invalid argument" id))
    (define name (normalize-primitive-name (query-compute-name compute)))
    (define spec
      (hash-ref primitive-specs name
                (lambda ()
                  (query-fail 'unsafe-compute
                              "primitive ~a is outside the Q1 whitelist"
                              name))))
    (match-define (list kind inputs output) spec)
    (unless (eq? kind (query-compute-kind compute))
      (query-fail 'unsafe-compute
                  "primitive ~a requires ~a form, received ~a"
                  name kind (query-compute-kind compute)))
    (unless (= (length inputs) (length (query-compute-args compute)))
      (query-fail 'unsafe-compute "primitive ~a expects ~a arguments"
                  name (length inputs)))
    (for ([term (in-list (query-compute-args compute))]
          [type (in-list inputs)])
      (constrain-term! term type (format "compute ~a" name)))
    (constrain-variable! (query-compute-output compute) output
                         (format "compute ~a output" name)))

  (for ([guard (in-list (query-request-guards request))]
        [id (in-naturals)])
    (unless (and (query-guard? guard)
                 (term? (query-guard-left guard))
                 (term? (query-guard-right guard)))
      (query-fail 'request "guard ~a is malformed" id))
    (define kind (query-guard-kind guard))
    (unless (or (memq kind equality-kinds)
                (memq kind comparison-kinds))
      (query-fail 'unsafe-compute "unsupported query guard ~s" kind))
    (cond
      [(memq kind comparison-kinds)
      (constrain-term! (query-guard-left guard) 'numeric
                       (format "guard ~a" kind))
      (constrain-term! (query-guard-right guard) 'numeric
                       (format "guard ~a" kind))]
      [else
       (define left-type
         (if (symbol? (query-guard-left guard))
             (hash-ref variable-types (query-guard-left guard) 'any)
             (literal-type (query-guard-left guard))))
       (define right-type
         (if (symbol? (query-guard-right guard))
             (hash-ref variable-types (query-guard-right guard) 'any)
             (literal-type (query-guard-right guard))))
       (define common (type-meet left-type right-type))
       (unless common
         (query-fail 'type "guard ~a compares incompatible types ~s and ~s"
                     kind left-type right-type))
       (constrain-term! (query-guard-left guard) common
                        (format "guard ~a" kind))
       (constrain-term! (query-guard-right guard) common
                        (format "guard ~a" kind))]))
  variable-types)

;; -------------------------------------------------------------------------
;; Scheduling over existing physical orders only.

(struct ratom (id atom relation) #:transparent)
(struct indexed-compute (id value) #:transparent)
(struct indexed-guard (id value) #:transparent)
(struct sched-special (kind value ground-before output-ground?) #:transparent)
(struct probe-choice
  (atom order bound ground-before filtered-bound cost)
  #:transparent)
(struct tail-result
  (body cost degradations final-ground schedule-key)
  #:transparent)
(struct candidate
  (driver driver-order driver-ground pre body cost degradations final-ground key)
  #:transparent)

(define (term-ground? term ground)
  (or (query-literal? term)
      (and (symbol? term) (set-member? ground term))))

(define (terms-ground? terms ground)
  (andmap (lambda (term) (term-ground? term ground)) terms))

(define (compute-ready? indexed ground)
  (terms-ground? (query-compute-args (indexed-compute-value indexed)) ground))

(define (guard-ready? indexed ground)
  (define guard (indexed-guard-value indexed))
  (and (term-ground? (query-guard-left guard) ground)
       (term-ground? (query-guard-right guard) ground)))

(define (negative-ready? atom ground)
  (terms-ground? (query-atom-terms (ratom-atom atom)) ground))

;; Eagerly close every safe special enabled by the current ground set.
;; Guards/absence filters run before computes at one frontier; one compute is
;; then fired and closure repeats, allowing compute chains to enable joins.
(define (close-specials ground computes guards negatives)
  (let loop ([ground ground] [computes computes] [guards guards]
             [negatives negatives] [emitted '()])
    (define ready-guards (filter (lambda (g) (guard-ready? g ground)) guards))
    (define ready-negatives
      (filter (lambda (n) (negative-ready? n ground)) negatives))
    (cond
      [(or (pair? ready-guards) (pair? ready-negatives))
       (define emitted+
         (append emitted
                 (for/list ([g (in-list ready-guards)])
                   (sched-special 'guard (indexed-guard-value g) ground #f))
                 (for/list ([n (in-list ready-negatives)])
                   (sched-special 'negative n ground #f))))
       (loop ground computes
             (filter (lambda (g) (not (member g ready-guards))) guards)
             (filter (lambda (n) (not (member n ready-negatives))) negatives)
             emitted+)]
      [else
       (define ready-compute (findf (lambda (c) (compute-ready? c ground))
                                    computes))
       (if ready-compute
           (let* ([compute (indexed-compute-value ready-compute)]
                  [output (query-compute-output compute)]
                  [already? (set-member? ground output)])
             (loop (set-add ground output)
                   (remove ready-compute computes) guards negatives
                   (append emitted
                           (list (sched-special 'compute compute ground
                                                already?)))))
           (values ground emitted computes guards negatives))])))

(define (atom-ground-columns atom ground)
  (for/set ([term (in-list (query-atom-terms (ratom-atom atom)))]
            [column (in-naturals)]
            #:when (term-ground? term ground))
    column))

(define (atom-filter-count atom ground)
  ;; Equality work left after a tuple is read: literals/pre-bound variables,
  ;; plus repeated variables introduced by the same tuple.
  (define seen (mutable-set))
  (for/sum ([term (in-list (query-atom-terms (ratom-atom atom)))])
    (cond
      [(term-ground? term ground) 1]
      [(set-member? seen term) 1]
      [else (set-add! seen term) 0])))

(define (probe-filter-count atom order bound ground)
  (define seen (mutable-set))
  (for/sum ([column (in-list order)] [physical (in-naturals)])
    (define term (list-ref (query-atom-terms (ratom-atom atom)) column))
    (cond
      [(< physical bound) 0]
      [(term-ground? term ground) 1]
      [(set-member? seen term) 1]
      [else (set-add! seen term) 0])))

(define (bound-prefix order terms ground)
  (let loop ([columns order] [count 0])
    (cond
      [(null? columns) count]
      [(term-ground? (list-ref terms (car columns)) ground)
       (loop (cdr columns) (add1 count))]
      [else count])))

(define (estimate-probe tuple-count bound)
  ;; Until prefix-distinct statistics exist, every bound column gets the same
  ;; conservative factor. Exact arithmetic and a floor of one keep plan
  ;; choice deterministic across Racket/platform versions.
  (define divisor (expt 16 bound))
  (if (zero? tuple-count)
      0
      (max 1 (quotient (+ tuple-count divisor -1) divisor))))

(define (best-probe-choice atom ground)
  (define terms (query-atom-terms (ratom-atom atom)))
  (define relation (ratom-relation atom))
  (define choices
    (for/list ([order (in-list (query-relation-full-orders relation))]
               #:do [(define bound (bound-prefix order terms ground))])
      (probe-choice atom order bound ground
                    (probe-filter-count atom order bound ground)
                    (estimate-probe (query-relation-tuple-count relation)
                                    bound))))
  (and (pair? choices)
       (first
        (sort choices
              (lambda (left right)
                (cond
                  [(< (probe-choice-cost left) (probe-choice-cost right)) #t]
                  [(> (probe-choice-cost left) (probe-choice-cost right)) #f]
                  [(> (probe-choice-bound left) (probe-choice-bound right)) #t]
                  [(< (probe-choice-bound left) (probe-choice-bound right)) #f]
                  [else (lexicographic<? (probe-choice-order left)
                                         (probe-choice-order right))]))))))

(define (tail-better? left right)
  (cond
    [(not right) #t]
    [(< (tail-result-cost left) (tail-result-cost right)) #t]
    [(> (tail-result-cost left) (tail-result-cost right)) #f]
    [else (string<? (tail-result-schedule-key left)
                    (tail-result-schedule-key right))]))

(define (search-tail remaining ground computes guards negatives memo)
  (define memo-key
    (list (sort (map ratom-id remaining) <)
          (sort (set->list ground) symbol<?)
          (map indexed-compute-id computes)
          (map indexed-guard-id guards)
          (sort (map ratom-id negatives) <)))
  (cond
    [(hash-has-key? memo memo-key) (hash-ref memo memo-key)]
    [else
     (define-values (ground+ specials computes+ guards+ negatives+)
       (close-specials ground computes guards negatives))
     (define result
       (cond
         [(null? remaining)
          (and (null? computes+) (null? guards+) (null? negatives+)
               (tail-result specials 0 '() ground+
                            (format "~s"
                                    (map sched-special-kind specials))))]
         [else
          (for/fold ([best #f]) ([atom (in-list remaining)])
            (define choice (best-probe-choice atom ground+))
            (cond
              [(not choice) best]
              [else
               (define ground++
                 (set-union
                  ground+
                  (term-vars (query-atom-terms (ratom-atom atom)))))
               (define tail
                 (search-tail (remove atom remaining) ground++
                              computes+ guards+ negatives+ memo))
               (cond
                 [(not tail) best]
                 [else
                  (define degradation
                    (cond
                      [(zero? (probe-choice-bound choice))
                       (list
                        (query-degradation
                         'scan-plus-filter
                         (query-relation-name (ratom-relation atom))
                         (list
                          'position 'body
                          'reason 'no-positive-index-prefix
                          'post-scan-equalities
                          (probe-choice-filtered-bound choice))))]
                      [(positive? (probe-choice-filtered-bound choice))
                       (list
                        (query-degradation
                         'probe-plus-filter
                         (query-relation-name (ratom-relation atom))
                         (list
                          'index-prefix (probe-choice-bound choice)
                          'post-probe-equalities
                          (probe-choice-filtered-bound choice))))]
                      [else '()]))
                  (define proposed
                    (tail-result
                     (append specials (list choice) (tail-result-body tail))
                     (+ (probe-choice-cost choice) (tail-result-cost tail))
                     (append degradation (tail-result-degradations tail))
                     (tail-result-final-ground tail)
                     (format "~s/~a"
                             (list (ratom-id atom)
                                   (probe-choice-order choice))
                             (tail-result-schedule-key tail))))
                  (if (tail-better? proposed best) proposed best)])]))]))
     (hash-set! memo memo-key result)
     result]))

(define (driver-order atom ground)
  ;; Any already-ground driver column requires equality after scan-full. Mark
  ;; that fact explicitly by requesting the engine's empty-order fallback;
  ;; binding then chooses a deterministic existing physical order.
  (if (zero? (atom-filter-count atom ground))
      (first (query-relation-full-orders (ratom-relation atom)))
      '()))

(define (candidate-better? left right)
  (cond
    [(not right) #t]
    [(< (candidate-cost left) (candidate-cost right)) #t]
    [(> (candidate-cost left) (candidate-cost right)) #f]
    [else (string<? (candidate-key left) (candidate-key right))]))

(define (choose-schedule positives computes guards negatives)
  (define indexed-computes
    (for/list ([compute (in-list computes)] [id (in-naturals)])
      (indexed-compute id compute)))
  (define indexed-guards
    (for/list ([guard (in-list guards)] [id (in-naturals)])
      (indexed-guard id guard)))
  (define-values (pre-ground pre computes+ guards+ negatives+)
    (close-specials (set) indexed-computes indexed-guards negatives))
  (define memo (make-hash))
  (define best
    (for/fold ([best #f]) ([driver (in-list positives)])
    (define after-driver
      (set-union pre-ground
                 (term-vars (query-atom-terms (ratom-atom driver)))))
    (define tail
      (search-tail (remove driver positives) after-driver
                   computes+ guards+ negatives+ memo))
    (cond
      [(not tail) best]
      [else
       (define order (driver-order driver pre-ground))
       (define fallback? (null? order))
       (define degradations
         (append
          (if fallback?
              (list
                (query-degradation
                'scan-plus-filter
                (query-relation-name (ratom-relation driver))
                (list 'equalities (atom-filter-count driver pre-ground)
                      'ground-columns
                      (sort (set->list
                             (atom-ground-columns driver pre-ground)) <))))
              '())
          (tail-result-degradations tail)))
       (define key
         (format "~s/~a"
                 (list (ratom-id driver) order fallback?)
                 (tail-result-schedule-key tail)))
       (define proposed
         (candidate driver order pre-ground pre (tail-result-body tail)
                    (+ (query-relation-tuple-count (ratom-relation driver))
                       (tail-result-cost tail))
                    degradations (tail-result-final-ground tail) key))
       (if (candidate-better? proposed best) proposed best)])))
  (cond
    [(not best) #f]
    [else
     (define cheapest
       (first
        (sort positives
              (lambda (left right)
                (define left-size
                  (query-relation-tuple-count (ratom-relation left)))
                (define right-size
                  (query-relation-tuple-count (ratom-relation right)))
                (or (< left-size right-size)
                    (and (= left-size right-size)
                         (< (ratom-id left) (ratom-id right))))))))
     (define cheapest-size
       (query-relation-tuple-count (ratom-relation cheapest)))
     (define chosen-size
       (query-relation-tuple-count
        (ratom-relation (candidate-driver best))))
     (if (<= chosen-size cheapest-size)
         best
         (struct-copy candidate best
           [degradations
            (cons
             (query-degradation
              'join-order
              (query-relation-name
               (ratom-relation (candidate-driver best)))
              (list 'smallest-driver
                    (query-relation-name (ratom-relation cheapest))
                    'smallest-size cheapest-size
                    'chosen-size chosen-size
                    'reason 'existing-index-prefixes))
             (candidate-degradations best))]))]))

;; -------------------------------------------------------------------------
;; Dense register allocation and lowering.

(define (lower-plan catalog request bindings resolved-atoms chosen)
  (define variable-registers (make-hash))
  (define literal-registers (make-hash))
  (define literal-order '())
  (define next-register 0)
  (define (fresh-register!)
    (define result next-register)
    (set! next-register (add1 next-register))
    result)
  (define (variable-register! variable)
    (hash-ref! variable-registers variable fresh-register!))
  (define (literal-register! literal)
    (hash-ref! literal-registers literal
               (lambda ()
                 (define register (fresh-register!))
                 (set! literal-order (append literal-order (list literal)))
                 register)))
  (define (term-register! term)
    (cond [(symbol? term) (variable-register! term)]
          [else (literal-register! term)]))
  (define (visit-term! term) (void (term-register! term)))

  ;; Allocate user-visible registers in source order before schedule-local
  ;; temporaries, so cost-driven reordering never renumbers the debug map.
  (for ([resolved (in-list resolved-atoms)])
    (for-each visit-term! (query-atom-terms (ratom-atom resolved))))
  (for ([compute (in-list (query-request-computes request))])
    (for-each visit-term! (query-compute-args compute))
    (void (variable-register! (query-compute-output compute))))
  (for ([guard (in-list (query-request-guards request))])
    (visit-term! (query-guard-left guard))
    (visit-term! (query-guard-right guard)))
  (for-each variable-register! (query-request-project request))

  (define binding-slot
    (for/hash ([binding (in-list bindings)])
      (values (query-binding-name binding) (query-binding-slot binding))))

  (define (lower-special special)
    (match (sched-special-kind special)
      ['guard
       (define guard (sched-special-value special))
       (define left (term-register! (query-guard-left guard)))
       (define right (term-register! (query-guard-right guard)))
       (match (query-guard-kind guard)
         ['eq (list (qp-eq left right))]
         ['neq (list (qp-neq left right))]
         [kind
          (list (qp-prim 'guard (symbol->string kind) 0
                         (list left right)))])]
      ['compute
       (define compute (sched-special-value special))
       (define output (variable-register! (query-compute-output compute)))
       (define actual-output
         (if (sched-special-output-ground? special)
             (fresh-register!) output))
       (define primitive
         (qp-prim (query-compute-kind compute)
                  (symbol->string
                   (normalize-primitive-name (query-compute-name compute)))
                  actual-output
                  (map term-register! (query-compute-args compute))))
       (if (= output actual-output)
           (list primitive)
           (list primitive (qp-eq output actual-output)))]
      ['negative
       (define resolved (sched-special-value special))
       (define relation (ratom-relation resolved))
       (define order (first (query-relation-full-orders relation)))
       (define nominal (query-atom-terms (ratom-atom resolved)))
       (list
        (qp-filter
         'absent
         (hash-ref binding-slot (query-relation-name relation))
         order (length order)
         (for/list ([column (in-list order)])
           (term-register! (list-ref nominal column)))))]))

  (define (lower-driver driver ground-before order)
    (define terms (query-atom-terms (ratom-atom driver)))
    (define seen (mutable-set))
    (define equalities '())
    (define regs
      (for/list ([term (in-list terms)])
        (cond
          [(or (query-literal? term)
               (and (symbol? term) (set-member? ground-before term))
               (and (symbol? term) (set-member? seen term)))
           (define temporary (fresh-register!))
           (set! equalities
                 (append equalities
                         (list (qp-eq temporary (term-register! term)))))
           temporary]
          [else
           (set-add! seen term)
           (term-register! term)])))
    (values
     (qp-driver
      (hash-ref binding-slot
                (query-relation-name (ratom-relation driver)))
      order regs)
     equalities))

  (define (lower-probe choice)
    (define resolved (probe-choice-atom choice))
    (define terms (query-atom-terms (ratom-atom resolved)))
    (define ground-before (probe-choice-ground-before choice))
    (define seen-new (mutable-set))
    (define equalities '())
    (define regs
      (for/list ([column (in-list (probe-choice-order choice))]
                 [physical (in-naturals)])
        (define term (list-ref terms column))
        (cond
          [(< physical (probe-choice-bound choice))
           (term-register! term)]
          [(and (symbol? term)
                (not (set-member? ground-before term))
                (not (set-member? seen-new term)))
           (set-add! seen-new term)
           (term-register! term)]
          [else
           (define temporary (fresh-register!))
           (set! equalities
                 (append equalities
                         (list (qp-eq temporary (term-register! term)))))
           temporary])))
    (cons
     (qp-probe
      (hash-ref binding-slot
                (query-relation-name (ratom-relation resolved)))
      (probe-choice-order choice) (probe-choice-bound choice) regs)
     equalities))

  (define preops
    (append-map lower-special (candidate-pre chosen)))
  (define-values (driver driver-equalities)
    (lower-driver (candidate-driver chosen)
                  (candidate-driver-ground chosen)
                  (candidate-driver-order chosen)))
  (define body
    (append
     driver-equalities
     (append-map
      (lambda (item)
        (cond [(probe-choice? item) (lower-probe item)]
              [else (lower-special item)]))
      (candidate-body chosen))))

  (define literals
    (for/list ([literal (in-list literal-order)])
      (qp-literal (literal-register! literal)
                  (query-literal-kind literal)
                  (query-literal-text literal))))
  (define schedule
    (cons
     (list 'scan (query-relation-name
                  (ratom-relation (candidate-driver chosen)))
           (candidate-driver-order chosen))
     (for/list ([item (in-list (candidate-body chosen))])
       (cond
         [(probe-choice? item)
          (list 'probe
                (query-relation-name
                 (ratom-relation (probe-choice-atom item)))
                (probe-choice-order item) (probe-choice-bound item))]
         [else
          (list (sched-special-kind item)
                (match (sched-special-kind item)
                  ['negative
                   (query-relation-name
                    (ratom-relation (sched-special-value item)))]
                  [_ #f]))]))))
  (define explain
    (query-explain
     (candidate-cost chosen)
     (query-relation-name (ratom-relation (candidate-driver chosen)))
     schedule (candidate-degradations chosen)))
  (query-plan
   (query-catalog-boundary-key catalog)
   (query-catalog-generation catalog)
   bindings next-register '() literals preops driver body
   (map variable-register! (query-request-project request))
   (query-request-mode request) explain))

;; -------------------------------------------------------------------------
;; Public constructor.

(define (plan-query catalog request)
  (define relations (validate-catalog catalog))
  (define resolved-atoms (resolve-request request relations))
  (void (check-types! request resolved-atoms))

  (define positive
    (filter (lambda (resolved)
              (not (query-atom-negated? (ratom-atom resolved))))
            resolved-atoms))
  (define negative
    (filter (lambda (resolved)
              (query-atom-negated? (ratom-atom resolved)))
            resolved-atoms))
  (when (null? positive)
    (query-fail 'driver "a query requires at least one positive relation atom"))
  (when (> (length positive) 16)
    (query-fail 'limit
                "Q1 v1 plans at most 16 positive atoms, received ~a"
                (length positive)))

  (define producible
    (for/fold ([vars (set)]) ([atom (in-list positive)])
      (set-union vars (term-vars (query-atom-terms (ratom-atom atom))))))
  (define producible+
    (for/fold ([vars producible])
              ([compute (in-list (query-request-computes request))])
      (set-add vars (query-compute-output compute))))
  (for ([atom (in-list negative)])
    (define missing
      (set-subtract (term-vars (query-atom-terms (ratom-atom atom)))
                    producible+))
    (unless (set-empty? missing)
      (query-fail 'unsafe-negation
                  "negative relation ~s has unbound variables ~s"
                  (query-relation-name (ratom-relation atom))
                  (sort (set->list missing) symbol<?))))
  (define missing-project
    (set-subtract (list->set (query-request-project request)) producible+))
  (unless (set-empty? missing-project)
    (query-fail 'dataflow "projection has unbound variables ~s"
                (sort (set->list missing-project) symbol<?)))

  (define used-names
    (sort (remove-duplicates
           (map (lambda (resolved)
                  (query-relation-name (ratom-relation resolved)))
                resolved-atoms))
          string<? #:key name-key))
  (define bindings
    (for/list ([name (in-list used-names)] [slot (in-naturals)])
      (define relation (hash-ref relations name))
      (query-binding
       slot name (query-relation-version-key relation)
       (query-relation-kind relation)
       (length (query-relation-field-types relation))
       (query-relation-field-types relation)
       (query-relation-full-orders relation)
       (query-relation-tuple-count relation))))

  (define chosen
    (choose-schedule positive
                     (query-request-computes request)
                     (query-request-guards request)
                     negative))
  (unless chosen
    (query-fail 'no-feasible-schedule
                "no schedule can ground every guard, compute, and absence dependency"))
  (define missing-final
    (set-subtract (list->set (query-request-project request))
                  (candidate-final-ground chosen)))
  (unless (set-empty? missing-final)
    (query-fail 'dataflow "chosen plan leaves projection variables unbound ~s"
                (sort (set->list missing-final) symbol<?)))
  (lower-plan catalog request bindings resolved-atoms chosen))

;; A deterministic diagnostic representation for unit tests and explain.
;; This is not the frozen T0 wire grammar; query-plan->wire-datum below is.
(define (query-plan->datum plan)
  (define (op->datum op)
    (match op
      [(qp-probe relation order bound regs)
       `(probe (rel ,relation) (order ,@order) (bound ,bound) (regs ,@regs))]
      [(qp-filter kind relation order bound regs)
       `(filter ,kind (rel ,relation) (order ,@order)
                (bound ,bound) (regs ,@regs))]
      [(qp-eq left right) `(eq (r ,left) (r ,right))]
      [(qp-neq left right) `(neq (r ,left) (r ,right))]
      [(qp-prim kind name output args)
       `(primitive ,kind ,name (output ,output) (args ,@args))]))
  `(query-plan
    (at ,(query-plan-boundary-key plan) ,(query-plan-generation plan))
    (bindings
     ,@(for/list ([binding (in-list (query-plan-bindings plan))])
         `(rel ,(query-binding-slot binding)
               (name ,(query-binding-name binding))
               (version ,(query-binding-version-key binding))
               (kind ,(query-binding-kind binding))
               (arity ,(query-binding-arity binding))
               (orders ,@(query-binding-full-orders binding))
               (size ,(query-binding-tuple-count binding)))))
    (registers ,(query-plan-nregs plan))
    (literals
     ,@(for/list ([literal (in-list (query-plan-literals plan))])
         `(literal (r ,(qp-literal-reg literal))
                   ,(qp-literal-kind literal) ,(qp-literal-text literal))))
    (pre ,@(map op->datum (query-plan-preops plan)))
    (driver
     (scan-full (rel ,(qp-driver-relation (query-plan-driver plan)))
                (order ,@(qp-driver-order (query-plan-driver plan)))
                (regs ,@(qp-driver-regs (query-plan-driver plan)))))
    (body ,@(map op->datum (query-plan-body plan)))
    (project ,@(query-plan-project plan))
    (mode ,(query-plan-mode plan))))

;; Frozen QueryPlan payload ABI consumed by daemon/query.cpp. The T0
;; `(query ID <payload> (page N))` command embeds this datum unchanged; command
;; framing, IDs, generation admission, and pagination are dispatcher concerns.
(define (query-plan->wire-datum plan)
  (unless (query-plan? plan)
    (query-fail 'wire "expected a query-plan"))
  (define boundary-key (query-plan-boundary-key plan))
  (unless (string? boundary-key)
    (query-fail 'wire "BoundaryKey must be a string, received ~s"
                boundary-key))
  (define (ref register) `(r ,register))
  (define (wire-name name)
    (cond [(string? name) name]
          [(symbol? name) (symbol->string name)]
          [else (query-fail 'wire "QName is not serializable: ~s" name)]))
  (define (op->wire op)
    (match op
      [(qp-probe relation order bound regs)
       `(probe (rel ,relation) ,order ,bound ,@(map ref regs))]
      [(qp-filter kind relation order bound regs)
       `(filter ,kind (rel ,relation) ,order ,bound ,@(map ref regs))]
      [(qp-eq left right) `(eq ,(ref left) ,(ref right))]
      [(qp-neq left right) `(neq ,(ref left) ,(ref right))]
      [(qp-prim kind name output args)
       `(primitive ,kind ,name (output ,(ref output))
                   (args ,@(map ref args)))]
      [_ (query-fail 'wire "unsupported query operation ~s" op)]))
  `(query-plan
    (abi 1)
    (at (boundary ,boundary-key)
        (generation ,(query-plan-generation plan)))
    (relations
     ,@(for/list ([binding (in-list (query-plan-bindings plan))])
         (unless (eq? (query-binding-kind binding) 'plain)
           (query-fail 'wire "Q1 cannot serialize relation kind ~s"
                       (query-binding-kind binding)))
         (unless (string? (query-binding-version-key binding))
           (query-fail 'wire "VersionKey for ~s must be a string"
                       (query-binding-name binding)))
         `(rel ,(query-binding-slot binding)
               (binding ,(wire-name (query-binding-name binding))
                        ,(query-binding-version-key binding)
                        ,(query-binding-tuple-count binding))
               (relation ,(query-binding-arity binding)
                         ,@(query-binding-full-orders binding)))))
    (registers ,(query-plan-nregs plan))
    (preloads
     ,@(for/list ([preload (in-list (query-plan-preloads plan))])
         (match preload
           [(list register value) `(set ,(ref register) ,value)]
           [(cons register value) `(set ,(ref register) ,value)]
           [_ (query-fail 'wire "malformed preload ~s" preload)])))
    (literals
     ,@(for/list ([literal (in-list (query-plan-literals plan))])
         `(literal ,(ref (qp-literal-reg literal))
                   ,(qp-literal-kind literal) ,(qp-literal-text literal))))
    (pre ,@(map op->wire (query-plan-preops plan)))
    (driver
     (scan-full (rel ,(qp-driver-relation (query-plan-driver plan)))
                ,(qp-driver-order (query-plan-driver plan))
                ,@(map ref (qp-driver-regs (query-plan-driver plan)))))
    (body ,@(map op->wire (query-plan-body plan)))
    (project ,@(map ref (query-plan-project plan)))
    (mode ,(query-plan-mode plan))))

(define (query-plan->wire-string plan)
  (with-output-to-string
    (lambda () (write (query-plan->wire-datum plan)))))
