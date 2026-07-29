#lang racket

;; The R2 `?` register grammar: typed line -> query-plan.rkt request.
;; Pure translation tests; planning/transport are covered by
;; query-plan-tests.rkt and the REPL contract battery.

(module+ test
  (require rackunit
           "../../compiler/query-front.rkt"
           "../../compiler/query-plan.rkt")

  (define (parse text) (parse-query-line text))
  (define (request text) (query-line-request (parse text)))

  (define (failure-kind thunk)
    (with-handlers ([exn:fail:query-plan? exn:fail:query-plan-kind])
      (thunk)
      'no-failure))

  (define (failure-detail thunk)
    (with-handlers ([exn:fail:query-plan? exn:fail:query-plan-detail])
      (thunk)
      'no-failure))

  (test-case "single-atom sugar keeps the fact template"
    (define line (parse "?(edge \"a\" X)"))
    (define req (query-line-request line))
    (check-equal? (query-request-mode req) 'rows)
    (check-equal? (query-request-project req) '(X))
    (check-equal? (query-line-pattern line) '(edge "a" X))
    (match-define (list atom) (query-request-atoms req))
    (check-equal? (query-atom-relation atom) "edge")
    (check-false (query-atom-negated? atom))
    (match-define (list lit var) (query-atom-terms atom))
    (check-equal? (query-literal-kind lit) 'string)
    (check-equal? (query-literal-text lit) "a")
    (check-equal? var 'X))

  (test-case "conjunctive form with guard and explicit projection"
    (define req
      (request "? (path X Y) (label Y L) (/= L \"skip\") -> (X L)"))
    (check-equal? (query-request-mode req) 'rows)
    (check-equal? (query-request-project req) '(X L))
    (check-equal? (map query-atom-relation (query-request-atoms req))
                  '("path" "label"))
    (match-define (list guard) (query-request-guards req))
    (check-equal? (query-guard-kind guard) 'neq)
    (check-equal? (query-guard-left guard) 'L))

  (test-case "count and exists modes carry no projection"
    (check-equal? (query-request-mode (request "?count (path X _)")) 'count)
    (check-equal? (query-request-project (request "?count (path X _)")) '())
    (check-equal? (query-request-mode (request "?exists (edge 1 2)")) 'exists))

  (test-case "a fully ground rows query answers existence"
    (define req (request "?(edge 1 2)"))
    (check-equal? (query-request-mode req) 'exists)
    (check-equal? (query-request-project req) '()))

  (test-case "wildcards are fresh per occurrence and never project"
    (define req (request "?(edge _ _)"))
    (check-equal? (query-request-mode req) 'exists)
    (match-define (list atom) (query-request-atoms req))
    (match-define (list left right) (query-atom-terms atom))
    (check-pred symbol? left)
    (check-pred symbol? right)
    (check-false (eq? left right))
    ;; and the sugar template is withheld when `_` hides a column
    (check-false (query-line-pattern (parse "?(edge X _)"))))

  (test-case "negation in both spellings"
    (define spaced (request "? (path X Y) ~ (blocked X)"))
    (define glued (request "? (path X Y) ~(blocked X)"))
    (for ([req (in-list (list spaced glued))])
      (match-define (list _ negated) (query-request-atoms req))
      (check-true (query-atom-negated? negated))
      (check-equal? (query-atom-relation negated) "blocked")))

  (test-case "audited computes pass; the wider surface set is refused"
    (define req (request "? (num X) (= Y (tofloat X)) -> (Y)"))
    (match-define (list compute) (query-request-computes req))
    (check-equal? (query-compute-kind compute) 'total)
    (check-equal? (query-compute-name compute) 'tofloat)
    (check-equal? (query-compute-output compute) 'Y)
    (check-regexp-match
     #px"scratch rule"
     (~a (failure-detail (lambda () (request "? (num X) (= Y (range X))")))))
    (match-define (list eq-guard)
      (query-request-guards (request "? (num X) (= X 3)")))
    (check-equal? (query-guard-kind eq-guard) 'eq))

  (test-case "handle splices resolve through the caller's table"
    ;; without a resolver a #N token is a typed refusal...
    (check-equal? (failure-kind (lambda () (request "?(edge #3 X)"))) 'parse)
    (check-regexp-match
     #px"needs a live session"
     (~a (failure-detail (lambda () (request "?(edge #3 X)")))))
    ;; ...with one, it becomes a spliced word literal (and `#` digits do
    ;; not leak into adjacent tokens)
    (define resolved
      (parse-query-line
       "?(edge #37 X)"
       #:resolve-handle
       (lambda (label)
         (check-equal? label "#37")
         (query-literal 'word "12345"))))
    (match-define (list atom)
      (query-request-atoms (query-line-request resolved)))
    (match-define (list word var) (query-atom-terms atom))
    (check-equal? (query-literal-kind word) 'word)
    (check-equal? (query-literal-text word) "12345")
    (check-equal? var 'X)
    ;; the single-atom template keeps the token's label for rendering
    (check-true (handle-token? (second (query-line-pattern resolved)))))

  (test-case "a spliced word lowers to a preload, not a wire literal"
    (define catalog
      (query-catalog-from-boundary
       (query-boundary
        "boundary/word" 3
        (hash "edge" (query-declaration "edge" 'table '(int int)))
        (hash "edge" "version/edge")
        (hash "version/edge"
              (query-materialization
               "version/edge" 'plain 2 '((0 1)) 4)))))
    (define line
      (parse-query-line
       "?(edge #1 X)"
       #:resolve-handle (lambda (_) (query-literal 'word "9218868471587143682"))))
    (define wire
      (query-plan->wire-string (plan-query catalog (query-line-request line))))
    (check-regexp-match #px"\\(preloads \\(set \\(r [0-9]+\\) 9218868471587143682\\)\\)"
                        wire)
    (check-regexp-match #px"\\(literals\\)" wire)
    ;; an out-of-range word refuses as a literal error
    (check-equal?
     (failure-kind
      (lambda ()
        (plan-query
         catalog
         (query-line-request
          (parse-query-line
           "?(edge #1 X)"
           #:resolve-handle (lambda (_) (query-literal 'word "not-a-word")))))))
     'literal))

  (test-case "typed refusals"
    (check-equal? (failure-kind (lambda () (request "? -> (X)"))) 'parse)
    (check-equal? (failure-kind (lambda () (request "?"))) 'parse)
    (check-equal? (failure-kind (lambda () (request "? (< 1 2 3)"))) 'parse)
    (check-equal? (failure-kind
                   (lambda () (request "? (edge X Y) -> (Z)")))
                  'parse)
    (check-equal? (failure-kind
                   (lambda () (request "? (edge X Y) -> (X) (path X Z)")))
                  'parse)
    (check-equal? (failure-kind (lambda () (request "?(edge 1/2 X)")))
                  'parse)
    (check-equal? (failure-kind (lambda () (request "?(edge #t X)")))
                  'parse))

  (test-case "literal kinds"
    (match-define (list atom)
      (query-request-atoms (request "?(cost \"x\" 3 2.5 X)")))
    (match-define (list s i r _) (query-atom-terms atom))
    (check-equal? (query-literal-kind s) 'string)
    (check-equal? (query-literal-kind i) 'integer)
    (check-equal? (query-literal-text i) "3")
    (check-equal? (query-literal-kind r) 'real))

  (test-case "a parsed request plans and serializes end to end"
    (define catalog
      (query-catalog-from-boundary
       (query-boundary
        "boundary/front" 7
        (hash "edge" (query-declaration "edge" 'table '(int int)))
        (hash "edge" "version/edge")
        (hash "version/edge"
              (query-materialization
               "version/edge" 'plain 2 '((0 1)) 4)))))
    (define line (parse "?(edge 2 X)"))
    (define plan (plan-query catalog (query-line-request line)))
    (define wire (query-plan->wire-string plan))
    (check-regexp-match #px"^\\(query-plan \\(abi 1\\)" wire)
    (check-regexp-match #px"\\(mode rows\\)" wire)
    (check-regexp-match #px"boundary/front" wire)))
