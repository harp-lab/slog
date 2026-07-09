#lang racket

;; Unit tests for compiler/collections.rkt (bracket/brace desugaring),
;; run via:  cd /home/tom/slog && raco test tests/unit/
;;
;; The desugar operates on the lift-type-envs module shape
;; (list path toks rules) where rules is a set of syn-wrapped rule
;; nodes; brackets arrive from the parser as ([] e ...) application
;; nodes with splices as postfix ... terms: [a b t ...] parses as
;; ([] a b (... t)).
;;
;; Brackets denote native sequences (docs/sequences.md §4-5): in PATTERN
;; context (bodies; demand-head input columns) a bracket becomes a fresh
;; deterministic $seqN variable plus one neutral seq-pat clause appended
;; to the rule body; in CONSTRUCTION context (other head positions) it
;; lowers in place to lempty/lpush/lcat prim chains.

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
  ;; `demands` routes demand-head input columns to pattern context.
  (define (desugar-rule r [lib? #f] [demands (hash)])
    (match-let ([(list (list _ _ rules))
                 (desugar-collections-mods (list (list "t" '() (set r)))
                                           lib? demands)])
      (set-first rules)))
  (define (desugar-rule/lib r) (desugar-rule r #t))

  (define (strip e)
    (match e
      [`(syn ,_ ,items ...) (map strip items)]
      [_ e]))

  ;; ---------------------------------------------------------------------
  ;; 1. Body pattern: [a b] --> fresh var + neutral seq-pat clause
  (check-equal?
   (strip (desugar-rule (S 'rule (S 'in (S '|[]| 'a 'b)) '--> (S 'out 'a))))
   '(rule (in $seq0) (seq-pat $seq0 (elem a) (elem b)) --> (out a)))

  ;; 2. Empty body pattern: [] --> a zero-item seq-pat
  (check-equal?
   (strip (desugar-rule (S 'rule (S 'in (S '|[]|)) '--> (S 'out 'a))))
   '(rule (in $seq0) (seq-pat $seq0) --> (out a)))

  ;; 3. Splice: [a b t ...] arrives as ([] a b (... t))
  (check-equal?
   (strip (desugar-rule
           (S 'rule (S 'in (S '|[]| 'a 'b (S '... 't))) '--> (S 'out 'a))))
   '(rule (in $seq0) (seq-pat $seq0 (elem a) (elem b) (splice t)) --> (out a)))

  ;; 4. Head/tail and splice-only patterns; constants become (elemc v)
  (check-equal?
   (strip (desugar-rule
           (S 'rule (S 'in (S '|[]| 'x (S '... 't))) '--> (S 'out 'x))))
   '(rule (in $seq0) (seq-pat $seq0 (elem x) (splice t)) --> (out x)))
  (check-equal?
   (strip (desugar-rule
           (S 'rule (S 'in (S '|[]| (S '... 't))) '--> (S 'out 'x))))
   '(rule (in $seq0) (seq-pat $seq0 (splice t)) --> (out x)))
  (check-equal?
   (strip (desugar-rule
           (S 'rule (S 'in (S '|[]| (S 'const 7) 'x)) '--> (S 'out 'x))))
   '(rule (in $seq0) (seq-pat $seq0 (elemc 7) (elem x)) --> (out x)))

  ;; 4s. Splices at ANY position (docs/sequences.md D1)
  (check-equal?
   (strip (desugar-rule
           (S 'rule (S 'in (S '|[]| (S '... 'xs) 'y)) '--> (S 'out 'y))))
   '(rule (in $seq0) (seq-pat $seq0 (splice xs) (elem y)) --> (out y)))

  ;; 5. Nested bracket patterns compose: the inner bracket's fresh var is
  ;;    already a symbol, so it rides the outer seq-pat as a plain element
  (check-equal?
   (strip (desugar-rule
           (S 'rule (S 'in (S '|[]| (S '|[]| 'a))) '--> (S 'out 'a))))
   '(rule (in $seq1)
          (seq-pat $seq0 (elem a))
          (seq-pat $seq1 (elem $seq0))
          --> (out a)))

  ;; 5h. Hoisted non-var elements: a struct term becomes (= $seqeN term)
  (check-equal?
   (strip (desugar-rule
           (S 'rule (S 'in (S '|[]| (S 'f 'x))) '--> (S 'out 'x))))
   '(rule (in $seq1) (= $seqe0 (f x)) (seq-pat $seq1 (elem $seqe0))
          --> (out x)))

  ;; 6. HEAD position constructs in place: lempty/lpush/lcat chains
  (check-equal?
   (strip (desugar-rule (S 'rule (S 'in 'l) '--> (S 'out (S '|[]| 'a 'b)))))
   '(rule (in l) --> (out (lpush (lpush (lempty) a) b))))
  (check-equal?
   (strip (desugar-rule
           (S 'rule (S 'in 'l) '--> (S 'out (S '|[]| 'a (S '... 'l) 'b)))))
   '(rule (in l) --> (out (lpush (lcat (lpush (lempty) a) l) b))))
  ;; ...including nested terms staying head-side, and empty []
  (check-equal?
   (strip (desugar-rule (S 'rule (S 'in 'x) '--> (S 'out (S '|[]| (S 'f 'x))))))
   '(rule (in x) --> (out (lpush (lempty) (f x)))))
  (check-equal?
   (strip (desugar-rule (S 'rule (S 'in 'x) '--> (S 'out (S '|[]|)))))
   '(rule (in x) --> (out (lempty))))

  ;; 6d. Demand-moded heads: INPUT columns are pattern context, ANSWER
  ;;     columns construct (docs/sequences.md §4.2)
  (check-equal?
   (strip (desugar-rule
           (S 'rule '--> (S 'f (S '|[]| 'x (S '... 'xs)) (S '|[]| 'y)))
           #f (hash 'f (cons 1 1))))
   '(rule (seq-pat $seq0 (elem x) (splice xs))
          --> (f $seq0 (lpush (lempty) y))))

  ;; 7. A top-level | (or-split alternative) is untouched; a pipe inside
  ;;    an element subterm keeps its nested-| or-split meaning
  (check-equal?
   (strip (desugar-rule
           (S 'rule (S '\| (S 'e 'a 'b) (S 'e 'b 'a)) '--> (S 'out 'a))))
   '(rule (\| (e a b) (e b a)) --> (out a)))
  (check-equal?
   (strip (desugar-rule
           (S 'rule (S 'in (S '|[]| (S 'f (S '\| 'x 'g)))) '--> (S 'out 'x))))
   '(rule (in $seq1) (= $seqe0 (f (\| x g))) (seq-pat $seq1 (elem $seqe0))
          --> (out x)))

  ;; 8. Errors: pipe in a bracket spine (replaced syntax) dies loudly, in
  ;;    both pattern and construction context; malformed splices die.
  ;;    parse-error prints and (exit 1) rather than raising, so trap the
  ;;    exit (and swallow the display).
  (define (check-dies thunk)
    (check-exn exn:fail?
     (lambda ()
       (parameterize ([exit-handler (lambda (_) (error "exited"))]
                      [current-output-port (open-output-nowhere)])
         (thunk)))))
  (check-dies
   (lambda () (desugar-rule
               (S 'rule (S 'in (S '|[]| (S '\| 'a 'b) 'c)) '--> (S 'out 'a)))))
  (check-dies
   (lambda () (desugar-rule
               (S 'rule (S 'in (S '|[]| 'a (S '\| 'b 'c))) '--> (S 'out 'a)))))
  (check-dies
   (lambda () (desugar-rule
               (S 'rule (S 'in 'l) '--> (S 'out (S '|[]| (S '\| 'a 'b)))))))

  ;; 9. collection-builtin? gates exactly the three reserved names
  (check-true (collection-builtin? 'list))
  (check-true (collection-builtin? 'cons))
  (check-true (collection-builtin? 'nil))
  (check-false (collection-builtin? 'edge))

  ;; ---------------------------------------------------------------------
  ;; Brace literals (Phase 1) -- untouched by the sequences work

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
  ;; empty collection), mixed entries, k:v base
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
