#lang racket

;; Unit tests for compiler/collections.rkt (bracket list desugaring),
;; run via:  cd /home/tom/slog && raco test tests/unit/
;;
;; The desugar operates on the lift-type-envs module shape
;; (list path toks rules) where rules is a set of syn-wrapped rule
;; nodes; brackets arrive from the parser as ([] e ...) application
;; nodes with an extension base as a postfix ... on the LAST element:
;; [a b t ...] parses as ([] a b (... t)).

(module+ test
  (require rackunit)
  (require "../../compiler/collections.rkt")

  ;; ---------------------------------------------------------------------
  ;; Builders.  parse-error needs real-shaped tokens in the prov.
  (define T '(token ref (pos "t" 1 0 1 1) "x"))
  (define P `(prov ,T ,T))
  (define (S . parts) `(syn ,P ,@parts))

  ;; Run one rule through the desugar and hand back the rewritten rule.
  ;; Braces route by lowering mode (modules.rkt lift-type-envs): lib? = #t
  ;; targets the rules-based Patricia libraries (st_ins/mp_put), the
  ;; default #f targets the native collection prims (cins/cput).
  (define (desugar-rule r [lib? #f])
    (match-let ([(list (list _ _ rules))
                 (desugar-collections-mods (list (list "t" '() (set r))) lib?)])
      (set-first rules)))
  (define (desugar-rule/lib r) (desugar-rule r #t))

  (define (strip e)
    (match e
      [`(syn ,_ ,items ...) (map strip items)]
      [_ e]))

  ;; ---------------------------------------------------------------------
  ;; 1. Literal: [a b] --> (cons a (cons b (nil)))
  (check-equal?
   (strip (desugar-rule (S 'rule (S 'in (S '|[]| 'a 'b)) '--> (S 'out 'a))))
   '(rule (in (cons a (cons b (nil)))) --> (out a)))

  ;; 2. Empty: [] --> (nil)
  (check-equal?
   (strip (desugar-rule (S 'rule (S 'in (S '|[]|)) '--> (S 'out 'a))))
   '(rule (in (nil)) --> (out a)))

  ;; 3. Tail: [a b t ...] arrives as ([] a b (... t)) --> (cons a (cons b t))
  (check-equal?
   (strip (desugar-rule
           (S 'rule (S 'in (S '|[]| 'a 'b (S '... 't))) '--> (S 'out 'a))))
   '(rule (in (cons a (cons b t))) --> (out a)))

  ;; 4. Single-element tail: [x t ...] --> (cons x t); [t ...] is t itself
  (check-equal?
   (strip (desugar-rule
           (S 'rule (S 'in (S '|[]| 'x (S '... 't))) '--> (S 'out 'x))))
   '(rule (in (cons x t)) --> (out x)))
  (check-equal?
   (strip (desugar-rule
           (S 'rule (S 'in (S '|[]| (S '... 't))) '--> (S 'out 'x))))
   '(rule (in t) --> (out x)))

  ;; 5. Nested brackets desugar bottom-up
  (check-equal?
   (strip (desugar-rule
           (S 'rule (S 'in (S '|[]| (S '|[]| 'a))) '--> (S 'out 'a))))
   '(rule (in (cons (cons a (nil)) (nil))) --> (out a)))

  ;; 6. A top-level | (or-split alternative) is untouched -- only pipes
  ;;    in a bracket's last position reassociate
  (check-equal?
   (strip (desugar-rule
           (S 'rule (S '\| (S 'e 'a 'b) (S 'e 'b 'a)) '--> (S 'out 'a))))
   '(rule (\| (e a b) (e b a)) --> (out a)))

  ;; 7. A pipe inside an element subterm is untouched (uniform nested-|
  ;;    or-split semantics)
  (check-equal?
   (strip (desugar-rule
           (S 'rule (S 'in (S '|[]| (S 'f (S '\| 'x 'g)))) '--> (S 'out 'x))))
   '(rule (in (cons (f (\| x g)) (nil))) --> (out x)))

  ;; 8. Errors: pipe in non-last position; chained/n-ary tail; postfix
  ;;    ...; brace literals.  parse-error prints and (exit 1) rather than
  ;;    raising, so trap the exit (and swallow the display).
  (define (check-dies thunk)
    (check-exn exn:fail?
     (lambda ()
       (parameterize ([exit-handler (lambda (_) (error "exited"))]
                      [current-output-port (open-output-nowhere)])
         (thunk)))))
  (check-dies   ;; any pipe in a bracket spine (replaced syntax) dies loudly
   (lambda () (desugar-rule
               (S 'rule (S 'in (S '|[]| (S '\| 'a 'b) 'c)) '--> (S 'out 'a)))))
  (check-dies
   (lambda () (desugar-rule
               (S 'rule (S 'in (S '|[]| 'a (S '\| 'b 'c))) '--> (S 'out 'a)))))
  (check-dies   ;; ... anywhere but last dies
   (lambda () (desugar-rule
               (S 'rule (S 'in (S '|[]| (S '... 'a) 'c)) '--> (S 'out 'a)))))

  ;; 9. collection-builtin? gates exactly the three reserved names
  (check-true (collection-builtin? 'list))
  (check-true (collection-builtin? 'cons))
  (check-true (collection-builtin? 'nil))
  (check-false (collection-builtin? 'edge))

  ;; ---------------------------------------------------------------------
  ;; Brace literals (Phase 1)

  ;; 10. Set literal, lib mode: {a b} --> (st_ins (st_ins (pempty) b) a)
  ;;     (like maps, the leftmost entry is applied last -- for sets the
  ;;     order is semantically irrelevant, the trie is canonical)
  (check-equal?
   (strip (desugar-rule/lib (S 'rule (S 'in (S '|{}| 'a 'b)) '--> (S 'out 'a))))
   '(rule (in (st_ins (st_ins (pempty) b) a)) --> (out a)))

  ;; 10n. ...and native mode (the default): cins over (cmap)
  (check-equal?
   (strip (desugar-rule (S 'rule (S 'in (S '|{}| 'a 'b)) '--> (S 'out 'a))))
   '(rule (in (cins (cins (cmap) b) a)) --> (out a)))

  ;; 11. Set update: {x s ...} arrives as ({} x (... s)) --> (st_ins s x)
  (check-equal?
   (strip (desugar-rule/lib
           (S 'rule (S 'in (S '|{}| 'x (S '... 's))) '--> (S 'out 'x))))
   '(rule (in (st_ins s x)) --> (out x)))
  (check-equal?
   (strip (desugar-rule
           (S 'rule (S 'in (S '|{}| 'x (S '... 's))) '--> (S 'out 'x))))
   '(rule (in (cins s x)) --> (out x)))

  ;; 12. Map literal: {a:b c:d} --> (mp_put (mp_put (mempty) c d) a b)
  ;;     (leftmost entry applied last = wins on duplicate keys)
  (check-equal?
   (strip (desugar-rule/lib
           (S 'rule (S 'in (S '|{}| (S ': 'a 'b) (S ': 'c 'd)))
              '--> (S 'out 'a))))
   '(rule (in (mp_put (mp_put (mempty) c d) a b)) --> (out a)))
  (check-equal?
   (strip (desugar-rule
           (S 'rule (S 'in (S '|{}| (S ': 'a 'b) (S ': 'c 'd)))
              '--> (S 'out 'a))))
   '(rule (in (cput (cput (cmap) c d) a b)) --> (out a)))

  ;; 13. Map update: {a:b m ...} arrives as ({} (: a b) (... m))
  (check-equal?
   (strip (desugar-rule/lib
           (S 'rule (S 'in (S '|{}| (S ': 'a 'b) (S '... 'm)))
              '--> (S 'out 'a))))
   '(rule (in (mp_put m a b)) --> (out a)))
  (check-equal?
   (strip (desugar-rule
           (S 'rule (S 'in (S '|{}| (S ': 'a 'b) (S '... 'm)))
              '--> (S 'out 'a))))
   '(rule (in (cput m a b)) --> (out a)))

  ;; 14. Errors: empty {} (lib mode only -- native {} is the one canonical
  ;; empty collection), mixed entries, multiple bases
  (check-dies
   (lambda () (desugar-rule/lib (S 'rule (S 'in (S '|{}|)) '--> (S 'out 'a)))))
  (check-equal?
   (strip (desugar-rule (S 'rule (S 'in (S '|{}|)) '--> (S 'out 'a))))
   '(rule (in (cmap)) --> (out a)))
  (check-dies
   (lambda () (desugar-rule
               (S 'rule (S 'in (S '|{}| 'a (S ': 'b 'c))) '--> (S 'out 'a)))))
  (check-dies   ;; base cannot be a k:v pair
   (lambda () (desugar-rule
               (S 'rule (S 'in (S '|{}| (S ': 'a 'b) (S '... (S ': 'c 'd))))
                  '--> (S 'out 'a))))))
