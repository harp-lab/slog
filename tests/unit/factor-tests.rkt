#lang racket

;; Unit battery for the S3 fragment-factoring pass
;; (compiler/fragment-factor.rkt; docs/static-join-decomposition.md).
;; End-to-end coverage (auto-factored bowtie_multi_mono matches the
;; hand-factored twin) lives in bench/bowtie-study.sh; this file pins the
;; pass's own contract: trigger, canonicalization, exclusions, determinism.

(module+ test
  (require rackunit
           racket/file
           racket/list
           racket/set
           racket/string
           "../../compiler/params.rkt"
           "../../compiler/modules.rkt"
           "../../compiler/simplification.rkt"
           "../../compiler/ir-shared.rkt"
           "../../compiler/fragment-factor.rkt")

  (define (factored-of src)
    (define f (make-temporary-file "factor-test-~a.slog"))
    (dynamic-wind
     void
     (lambda ()
       (with-output-to-file f #:exists 'replace (lambda () (display src)))
       (match-define (list (? program-ir? program))
         (load-program-list (path->string f) (hash)))
       (define type-env (program-ir-type-env program))
       (define mods (program-ir-modules program))
       (define all-rules
         (foldl set-union (set) (map module-ir-rules (set->list mods))))
       (define simplified (foldl simplify-rule (set) (set->list all-rules)))
       (define-values (rules+ env+)
         (factor-shared-fragments simplified type-env))
       (list rules+ env+))
     (lambda () (delete-file f))))

  (define (frag-rels env)
    (sort (filter (lambda (n)
                    (string-prefix? (symbol->string n) "$frag"))
                  (hash-keys (type-env-rels env)))
          symbol<?))

  (define (body-rels rule)
    (match rule
      [`(syn ,_ rule ,bodys ... --> ,_ ...)
       (for/list ([cl (in-list bodys)])
         (match cl
           [`(syn ,_ ,rel ,_ ...) rel]
           [_ #f]))]
      [_ '()]))

  (define two-rule-shared
    "table (r int int) table (s int int) table (t int int)
     table (out1 int int int) table (out2 int int int)
     rule (r A B) (s B C) (t A C) --> (out1 A B C)
     rule (t X Z) (r X Y) (s Y Z) --> (out2 X Y Z)")

  (test-case "a triangle shared by two rules factors to one $frag relation"
    (match-define (list rules+ env+) (factored-of two-rule-shared))
    (define frags (frag-rels env+))
    (check-equal? (length frags) 1)
    (define frag (first frags))
    ;; both consumer rules now join the fragment and none of them keeps a
    ;; base atom; exactly one synthesized rule derives it from r/s/t
    (define consumers
      (for/list ([rule (in-set rules+)]
                 #:when (memq frag (body-rels rule)))
        rule))
    (check-equal? (length consumers) 2)
    (for ([rule (in-list consumers)])
      (check-false (ormap (lambda (rel) (memq rel '(r s t)))
                          (body-rels rule))))
    ;; the synthesized definition: body = the three base atoms
    (define synths
      (for/list ([rule (in-set rules+)]
                 #:when (match rule
                          [`(syn ,_ rule ,_ ... --> (syn ,_ ,h ,_ ...))
                           (eq? h frag)]
                          [_ #f]))
        rule))
    (check-equal? (length synths) 1)
    (check-equal? (sort (body-rels (first synths)) symbol<?) '(r s t))
    ;; inferred column types survive (all int here, never any)
    (check-equal? (hash-ref (type-env-rels env+) frag)
                  '(table int int int)))

  (test-case "factoring is deterministic (same source, same name)"
    (match-define (list _ env1) (factored-of two-rule-shared))
    (match-define (list _ env2) (factored-of two-rule-shared))
    (check-equal? (frag-rels env1) (frag-rels env2)))

  (test-case "a single-rule repeat (the bowtie itself) does not trigger"
    (match-define (list rules+ env+)
      (factored-of
       "table (e int int) table (bt int int int int int)
        rule (e X Y) (e Y M) (e X M) (e M U) (e U V) (e M V)
          --> (bt X Y M U V)"))
    (check-equal? (frag-rels env+) '()))

  (test-case "a const-bound triangle variable excludes the embedding"
    (match-define (list _ env+)
      (factored-of
       "table (r int int) table (s int int) table (t int int)
        table (out1 int int int) table (out2 int int)
        rule (r A B) (s B C) (t A C) --> (out1 A B C)
        rule (r 5 Y) (s Y Z) (t 5 Z) --> (out2 Y Z)"))
    (check-equal? (frag-rels env+) '()))

  (test-case "two same-shape but differently-labeled patterns stay distinct"
    (match-define (list _ env+)
      (factored-of
       "table (r int int) table (s int int) table (t int int)
        table (u int int)
        table (out1 int int int) table (out2 int int int)
        table (out3 int int int) table (out4 int int int)
        rule (r A B) (s B C) (t A C) --> (out1 A B C)
        rule (r X Y) (s Y Z) (t X Z) --> (out2 X Y Z)
        rule (r A B) (s B C) (u A C) --> (out3 A B C)
        rule (r X Y) (s Y Z) (u X Z) --> (out4 X Y Z)"))
    (check-equal? (length (frag-rels env+)) 2))

  (test-case "the kill switch disables the pass"
    (parameterize ([fragment-factor-enabled #f])
      (match-define (list rules+ env+) (factored-of two-rule-shared))
      (check-equal? (frag-rels env+) '()))))
