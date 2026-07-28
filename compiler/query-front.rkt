#lang racket

;; The R2 `?` register front end (repl-ux.md §5.1, execution-tiers.md §6.1):
;; one typed REPL query line becomes a typed query-plan.rkt request.  This
;; module is pure text-to-struct translation -- name resolution against a
;; boundary catalog, planning, and transport stay with the caller -- so the
;; grammar is unit-testable without a daemon.
;;
;; Grammar (one line, after the prompt):
;;   ?(edge "a" X)                          single-atom sugar
;;   ? (path X Y) (label Y L) (/= L "skip") -> (X L)
;;   ?count (path X _)                      count matches, no rows
;;   ?exists (edge 1 2)                     first hit wins
;;   ~ (rel ...)                            snapshot absence (may also be
;;                                          spelled glued: ~(rel ...))
;;   (< X 10) (<= ...) (> ...) (>= ...)     order guards
;;   (/= X Y)  (= X Y)                      disequality / equality guards
;;   (= X (op A ...))                       audited compute (query whitelist)
;;
;; Symbols are variables (exactly the rule-body convention; capitalization
;; is style, not semantics), `_` is a fresh wildcard per occurrence, and a
;; query with no variables at all is answered as an existence test.  A bare
;; `->` names the projection; without one, every user variable projects in
;; order of first appearance.

(provide (struct-out query-line)
         parse-query-line)

(require racket/match
         "query-plan.rkt")

;; request        : the query-plan.rkt query-request
;; project-vars   : projected variable symbols, request order (rows mode)
;; pattern        : the single positive atom's surface datum when the query
;;                  is the one-atom sugar with a defaulted projection -- the
;;                  renderer substitutes answers back into it -- else #f
(struct query-line (request project-vars pattern) #:transparent)

(define (front-fail fmt . args)
  (raise (exn:fail:query-plan
          (format "query plan [parse]: ~a" (apply format fmt args))
          (current-continuation-marks)
          'parse (apply format fmt args))))

;; ---- lexical layer ---------------------------------------------------------

(define (read-query-datums text)
  (define in (open-input-string text))
  (with-handlers
      ([exn:fail:read?
        (lambda (e)
          (if (regexp-match? #px"#[0-9]" text)
              (front-fail
               (string-append
                "value handles cannot splice into queries yet; "
                "spell the value out"))
              (front-fail "unreadable query text: ~a" (exn-message e))))])
    (let loop ([datums '()])
      (define datum (read in))
      (if (eof-object? datum)
          (reverse datums)
          (loop (cons datum datums))))))

(define (strip-mode text)
  (define trimmed (string-trim text))
  (cond
    [(regexp-match #px"^\\?count(?![[:alnum:]])(.*)$" trimmed)
     => (lambda (m) (values 'count (second m)))]
    [(regexp-match #px"^\\?exists(?![[:alnum:]])(.*)$" trimmed)
     => (lambda (m) (values 'exists (second m)))]
    [(regexp-match #px"^\\?(.*)$" trimmed)
     => (lambda (m) (values 'rows (second m)))]
    [else (front-fail "a query starts with `?`, `?count`, or `?exists`")]))

;; ---- term layer ------------------------------------------------------------

(define guard-ops (hash '< 'lt '<= 'le '> 'gt '>= 'ge '/= 'neq))

(define (make-wildcard counter)
  (string->uninterned-symbol (format "_~a" counter)))

;; symbols are variables; `_` is fresh per occurrence; numbers and strings
;; become wire literals.  seen-vars preserves first-appearance order.
(define (parse-term datum wildcards seen-vars)
  (match datum
    ['_ (define fresh (make-wildcard (unbox wildcards)))
        (set-box! wildcards (add1 (unbox wildcards)))
        fresh]
    [(? symbol? v)
     (unless (memq v (unbox seen-vars))
       (set-box! seen-vars (append (unbox seen-vars) (list v))))
     v]
    [(? exact-integer? n) (query-literal 'integer (number->string n))]
    [(? real? n)
     (if (exact? n)
         (front-fail "exact non-integer ~s has no query literal form" n)
         (query-literal 'real (number->string n)))]
    [(? string? s) (query-literal 'string s)]
    [(? boolean? b)
     (front-fail "booleans are not yet supported in query literals")]
    [other (front-fail "unsupported query term ~s" other)]))

;; ---- clause layer ----------------------------------------------------------

(define (parse-atom datum negated? wildcards seen-vars)
  (match datum
    [(list (? symbol? rel) terms ...)
     (when (hash-has-key? guard-ops rel)
       (front-fail "guard ~s takes exactly two operands" rel))
     (query-atom (~a rel)
                 (for/list ([term (in-list terms)])
                   (parse-term term wildcards seen-vars))
                 negated?)]
    [other (front-fail "expected an atom (relation term ...), got ~s" other)]))

(define (parse-clauses datums wildcards seen-vars)
  (let loop ([datums datums] [atoms '()] [guards '()] [computes '()]
             [project #f])
    (match datums
      ['()
       (values (reverse atoms) (reverse guards) (reverse computes) project)]
      [(list '-> (list (? symbol? vars) ...))
       (when (null? atoms)
         (front-fail "a projection needs at least one atom before `->`"))
       (values (reverse atoms) (reverse guards) (reverse computes) vars)]
      [(cons '-> _)
       (front-fail "`->` must be last, followed by one (X Y ...) list")]
      [(cons '~ (cons (? list? atom) rest))
       (loop rest
             (cons (parse-atom atom #t wildcards seen-vars) atoms)
             guards computes project)]
      [(cons '~ _)
       (front-fail "`~~` must be followed by one (relation term ...) atom")]
      [(cons (list (? symbol? (? (curry hash-has-key? guard-ops) op))
                   left right)
             rest)
       (loop rest atoms
             (cons (query-guard (hash-ref guard-ops op)
                                (parse-term left wildcards seen-vars)
                                (parse-term right wildcards seen-vars))
                   guards)
             computes project)]
      [(cons (list '= (? symbol? out) (list (? symbol? op) args ...)) rest)
       #:when (query-primitive-spec op)
       (match-define (list kind _in _out) (query-primitive-spec op))
       (loop rest atoms guards
             (cons (query-compute
                    kind op
                    (parse-term out wildcards seen-vars)
                    (for/list ([arg (in-list args)])
                      (parse-term arg wildcards seen-vars)))
                   computes)
             project)]
      [(cons (list '= _ (list (? symbol? op) _ ...)) _)
       (front-fail
        (string-append
         "~s is not in the audited query-compute whitelist; "
         "make it a scratch rule")
        op)]
      [(cons (list '= left right) rest)
       (loop rest atoms
             (cons (query-guard 'eq
                                (parse-term left wildcards seen-vars)
                                (parse-term right wildcards seen-vars))
                   guards)
             computes project)]
      [(cons (? list? atom) rest)
       (loop rest
             (cons (parse-atom atom #f wildcards seen-vars) atoms)
             guards computes project)]
      [(cons other _)
       (front-fail "expected an atom, guard, compute, or `->`, got ~s"
                   other)])))

;; ---- entry -----------------------------------------------------------------

;; text -> query-line.  `text` is the complete typed line including the
;; sigil.  Wildcard variables never project; a fully ground rows query
;; downgrades to an existence test rather than refusing (repl-ux §5.1's
;; two-way add/query hint covers the bare-fact case before we get here).
(define (parse-query-line text)
  (define-values (mode body) (strip-mode text))
  (define datums (read-query-datums body))
  (when (null? datums)
    (front-fail "empty query; try ?(relation term ...)"))
  (define wildcards (box 1))
  (define seen-vars (box '()))
  (define-values (atoms guards computes explicit-project)
    (parse-clauses datums wildcards seen-vars))
  (when (null? atoms)
    (front-fail "a query needs at least one relation atom"))
  (when explicit-project
    (for ([var (in-list explicit-project)])
      (unless (memq var (unbox seen-vars))
        (front-fail "projected variable ~s is not bound by the query" var))))
  (define default-project (unbox seen-vars))
  (define project (or explicit-project default-project))
  (define ground? (null? project))
  (define effective-mode (if (and (eq? mode 'rows) ground?) 'exists mode))
  (define request
    (query-request effective-mode atoms guards computes
                   (if (eq? effective-mode 'rows) project '())))
  (query-line
   request
   (if (eq? effective-mode 'rows) project '())
   (and (eq? mode 'rows)
        (not explicit-project)
        (= (length datums) 1)
        (null? guards) (null? computes)
        (not (query-atom-negated? (first atoms)))
        ;; `_` columns are not projected, so the fact template cannot be
        ;; reassembled from an answer row; fall back to tuple rendering.
        (not (memq '_ (rest (first datums))))
        (first datums))))
