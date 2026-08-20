#lang racket

;; S3 (docs/static-join-decomposition.md): factor a body subpattern that is
;; SHARED ACROSS RULES into a synthesized relation, so the fragment (and
;; whatever scan tax it carries) is computed once instead of once per rule.
;;
;; Runs at program level between sequence expansion and typechecking
;; (compile.rkt), the same slot and contract as expand-seq-patterns: bodies
;; are flat simplified surface forms, and everything downstream --
;; typecheck, stratification, planning, every counted/maintenance flavor --
;; sees the rewritten rules uniformly (docs/incremental.md §8B.3: semantic
;; source transforms live above the multiplicity line; physical planning
;; below it must be instantiation-bijective).
;;
;; v1 fragment shape: three positive binary TABLE atoms forming a variable
;; triangle (three distinct variables, each atom covering a distinct pair)
;; -- exactly the cycle cores the wcoj machinery certifies, and the shape
;; the bowtie case study measured.  The synthesized relation projects ALL
;; THREE variables, so fragment rows are in bijection with fragment
;; instantiations and the rewritten rule's instantiations are in bijection
;; with the original's: tuple output AND derivation counts are preserved
;; exactly (stronger than §8B.3 requires).  The synthesized rule is an
;; ordinary rule, so stratification derives its base->fragment edges from
;; the rule itself (unlike $seq_at, which has no defining rule and needs
;; manual edges); if a base is recursive, the fragment joins that SCC --
;; intended, not incidental.
;;
;; TRIGGER: a canonical fragment class is factored iff it embeds in >= 2
;; DISTINCT rules.  The case study's verdict is encoded here: single-rule
;; repetition (the bowtie itself) measurably LOSES to the chained-join3
;; monolithic plan (materialization + a stratum for nothing, and the
;; fragment rule forfeits the residue's semijoin filter context), so it
;; does not trigger.  Exclusions, each load-bearing:
;;   - lattice relations (an extern/float merge is the one place join
;;     order changes the LOGICAL result, docs/db-compression.md);
;;   - structs, non-binary tables, `$`-internal relations, repeated-var
;;     atoms (v1 scope);
;;   - embeddings touching a const-bound variable (the fragment would
;;     compute the unconstrained pattern and filter afterwards -- strictly
;;     worse than the const-pushed inline plan);
;;   - negated atoms never match (different clause shape).
;;
;; Naming is content-derived and gensym-free ($frag + sha256 of the
;; canonical pattern text): the pass runs before the plan cache key is
;; computed, and identical programs must factor identically.  The
;; SLOG_NO_FRAGMENT_FACTOR toggle is folded into the job-hash settings
;; block (compile.rkt) so flipping it can never reuse a stale artifact.
;;
;; KNOWN LIMITATION (benign, documented rather than engineered around): a
;; synthesized rule inherits its prov from the format-least first atom of
;; the class's embeddings.  A prov is a token SPAN, so it can never equal a
;; user RULE's prov (different span) -- but two distinct fragment classes
;; whose format-least embedding starts at the SAME atom would share one
;; prov.  `count-classify!` (join-planning.rkt) keys by prov, so if those
;; two synthesized rules then classified differently for counting, the
;; documented conservative behavior applies: degrade to 'rec with a warning
;; (docs/incremental.md 6.4).  No silent divergence, and fabricating a
;; distinct prov would mean fabricating tokens.

(provide factor-shared-fragments)

(require "ir-shared.rkt"
         "params.rkt"
         "sha256.rkt")

;; how many eligible atoms a body may have before we skip enumeration
;; (C(n,3) subsets; peeled ground-fact rules and generated bodies can be
;; huge, and a 20-atom cyclic query is already far outside v1's remit)
(define fragment-atom-cap 20)

(define (factor-shared-fragments rules type-env)
  (cond
    [(not (fragment-factor-enabled)) (values rules type-env)]
    [else
     (define rels (type-env-rels type-env))
     (define (eligible-rel? name)
       (and (symbol? name)
            (not (string-prefix? (symbol->string name) "$"))
            (match (hash-ref rels name #f)
              [`(table ,_ ,_) (not (rel-lattice-spec rels name))]
              [_ #f])))
     (define (eligible-atom? cl)
       (match cl
         [`(syn ,_ ,(? eligible-rel?) ,(? symbol? a) ,(? symbol? b))
          (not (eq? a b))]
         [_ #f]))
     (define (atom-rel cl) (third cl))
     (define (atom-vars cl) (list (fourth cl) (fifth cl)))

     ;; ---- embedding enumeration -----------------------------------------
     ;; An embedding is a list of three body POSITIONS (into bodys) whose
     ;; atoms cover three distinct variables with pairwise-distinct pairs
     ;; (i.e., exactly the three edges of a variable triangle).
     (define (rule-embeddings bodys)
       (define const-bound
         (for/set ([cl (in-list bodys)]
                   #:when (match cl
                            [`(syn ,_ = ,_ (syn ,_ const ,_)) #t]
                            [_ #f]))
           (fourth cl)))
       (define idx+atoms
         (for/list ([cl (in-list bodys)] [i (in-naturals)]
                    #:when (eligible-atom? cl))
           (cons i cl)))
       (cond
         [(> (length idx+atoms) fragment-atom-cap) '()]
         [else
          (for*/list ([x (in-list idx+atoms)]
                      [y (in-list idx+atoms)]
                      #:when (< (car x) (car y))
                      [z (in-list idx+atoms)]
                      #:when (< (car y) (car z))
                      #:do [(define atoms (list (cdr x) (cdr y) (cdr z)))
                            (define pairs
                              (map (lambda (a) (list->set (atom-vars a)))
                                   atoms))
                            (define vars (apply set-union pairs))]
                      #:when (and (= (set-count vars) 3)
                                  (not (equal? (first pairs) (second pairs)))
                                  (not (equal? (first pairs) (third pairs)))
                                  (not (equal? (second pairs) (third pairs)))
                                  (for/and ([v (in-set vars)])
                                    (not (set-member? const-bound v)))))
            (list (car x) (car y) (car z)))]))

     ;; ---- canonicalization ----------------------------------------------
     ;; For each of the six atom orderings, number variables by first
     ;; occurrence and render the pattern; the lexicographically least
     ;; rendering is the class key, and the var order that produced it is
     ;; the projection order.  Fixed enumeration order makes automorphic
     ;; patterns resolve deterministically.
     (define (canonicalize atoms)
       (define best #f)   ; (key . var-list)
       (for ([perm (in-list (permutations atoms))])
         (define numbering (make-hash))
         (define order '())
         (for* ([a (in-list perm)] [v (in-list (atom-vars a))])
           (unless (hash-has-key? numbering v)
             (hash-set! numbering v (hash-count numbering))
             (set! order (cons v order))))
         ;; WRITE mode, not display: the key must be INJECTIVE over relation
         ;; symbols, and `~a` would render a (hypothetical) symbol containing
         ;; spaces or parens indistinguishably from a different triple list --
         ;; fusing two unrelated patterns into one $frag.  Today's lexer
         ;; cannot produce such a name, so this is insurance against a future
         ;; pass minting one; `~s` quotes it and costs nothing.
         (define key
           (format "~s"
                   (for/list ([a (in-list perm)])
                     (list (atom-rel a)
                           (hash-ref numbering (first (atom-vars a)))
                           (hash-ref numbering (second (atom-vars a)))))))
         (when (or (not best) (string<? key (car best)))
           (set! best (cons key (reverse order)))))
       best)

     ;; ---- pass 1: count distinct rules per class -------------------------
     ;; per class key: rendered canonical atoms (for the synth rule), the
     ;; set of rules embedding it, and a deterministic prov candidate pool.
     (define classes (make-hash))  ; key -> (list canon-atoms rule-set provs)
     (define (note-class! key atoms-in-canon-order rule prov)
       (match (hash-ref classes key #f)
         [#f (hash-set! classes key
                        (list atoms-in-canon-order (set rule) (list prov)))]
         [(list canon rs provs)
          (hash-set! classes key
                     (list canon (set-add rs rule) (cons prov provs)))]))

     (for ([rule (in-set rules)])
       (match rule
         [`(syn ,_ rule ,bodys ... --> ,_ ...)
          (for ([emb (in-list (rule-embeddings bodys))])
            (define atoms (map (lambda (i) (list-ref bodys i)) emb))
            (match-define (cons key var-order) (canonicalize atoms))
            (note-class! key
                         (canonical-atoms atoms var-order)
                         rule
                         (second (first atoms))))]
         [_ (void)]))

     (define triggered
       (for/hash ([(key info) (in-hash classes)]
                  #:when (>= (set-count (second info)) 2))
         (values key info)))

     (cond
       [(zero? (hash-count triggered)) (values rules type-env)]
       [else
        ;; ---- synthesized relations + rules -------------------------------
        (define (frag-name key)
          (string->symbol
           (string-append
            "$frag"
            (substring (bytes->hex-string
                        (sha256 (string->bytes/utf-8 key))) 0 10))))
        (define sorted-keys (sort (hash-keys triggered) string<?))
        (define synth-rules
          (for/list ([key (in-list sorted-keys)])
            (match-define (list canon _rs provs) (hash-ref triggered key))
            ;; deterministic prov: the formatted-least of the class's
            ;; embedding provs (the seq-expand precedent)
            (define prov
              (car (sort provs string<? #:key (lambda (p) (format "~a" p)))))
            (define name (frag-name key))
            `(syn ,prov rule
                  ,@(for/list ([a (in-list canon)])
                      `(syn ,prov ,(first a) ,(second a) ,(third a)))
                  --> (syn ,prov ,name v0 v1 v2))))
        (define env+
          (for/fold ([env type-env]) ([key (in-list sorted-keys)])
            (match-define (list canon _rs _provs) (hash-ref triggered key))
            (define name (frag-name key))
            ;; The only way this can fire is a 40-bit prefix collision
            ;; between two DISTINCT class keys: users cannot write `$` in an
            ;; identifier, and every other machinery relation is named by a
            ;; different pass.  Aborting is correct (it precedes any
            ;; rewrite), but say what actually happened -- a name-conflict
            ;; message would send the reader hunting for a declaration that
            ;; does not exist.
            (when (hash-has-key? (type-env-rels env) name)
              (error 'fragment-factor
                     (string-append
                      "fragment name hash collision on ~a\n"
                      "  key: ~a\n"
                      "this is a sha256-prefix collision between two distinct"
                      " fragment patterns; widen the prefix in frag-name")
                     name key))
            (define col-types
              (for/list ([v (in-list '(v0 v1 v2))])
                (define ts
                  (for*/list ([a (in-list canon)]
                              [pos (in-list '(0 1))]
                              #:when (eq? (list-ref a (add1 pos)) v))
                    (list-ref (hash-ref rels (first a)) (add1 pos))))
                (if (and (pair? ts)
                         (for/and ([t (in-list (cdr ts))])
                           (equal? t (car ts))))
                    (car ts)
                    'any)))
            (list (type-env-aliases env)
                  (hash-set (type-env-rels env) name `(table ,@col-types))
                  (type-env-funs env))))

        ;; ---- pass 2: rewrite the embedding rules --------------------------
        (define (rewrite-rule rule)
          (match rule
            [`(syn ,prov rule ,bodys ... --> ,heads ...)
             ;; embeddings of triggered classes, deterministically ordered,
             ;; greedily selected atom-disjoint
             (define chosen
               (let loop ([embs (sort
                                 (for/list ([emb (in-list
                                                  (rule-embeddings bodys))]
                                            #:do [(define atoms
                                                    (map (lambda (i)
                                                           (list-ref bodys i))
                                                         emb))
                                                  (match-define
                                                    (cons key var-order)
                                                    (canonicalize atoms))]
                                            #:when (hash-has-key? triggered
                                                                  key))
                                   (list key emb var-order))
                                 (lambda (a b)
                                   (if (string=? (first a) (first b))
                                       (< (car (second a)) (car (second b)))
                                       (string<? (first a) (first b)))))]
                          [used (set)] [acc '()])
                 (match embs
                   ['() (reverse acc)]
                   [(cons e rest)
                    (if (for/or ([i (in-list (second e))])
                          (set-member? used i))
                        (loop rest used acc)
                        (loop rest
                              (set-union used (list->set (second e)))
                              (cons e acc)))])))
             (cond
               [(null? chosen) rule]
               [else
                (define replaced   ; body position -> replacement or 'drop
                  (for/fold ([h (hash)]) ([e (in-list chosen)])
                    (match-define (list key emb var-order) e)
                    (define first-atom (list-ref bodys (first emb)))
                    (define aprov (second first-atom))
                    (define h+
                      (hash-set h (first emb)
                                `(syn ,aprov ,(frag-name key) ,@var-order)))
                    (for/fold ([h h+]) ([i (in-list (rest emb))])
                      (hash-set h i 'drop))))
                `(syn ,prov rule
                      ,@(for/list ([cl (in-list bodys)] [i (in-naturals)]
                                   #:unless (eq? (hash-ref replaced i #f)
                                                 'drop))
                          (or (hash-ref replaced i #f) cl))
                      --> ,@heads)])]
            [_ rule]))

        (define rules+
          (for/fold ([acc (set)]) ([rule (in-set rules)])
            (set-add acc (rewrite-rule rule))))
        (values (for/fold ([acc rules+]) ([r (in-list synth-rules)])
                  (set-add acc r))
                env+)])]))

;; the canonical pattern's atoms with variables renamed to v0/v1/v2 --
;; `(rel v_i v_j)` triples in canonical atom order, used both to build the
;; synthesized rule and to infer column types
(define (canonical-atoms atoms var-order)
  (define name-of
    (for/hash ([v (in-list var-order)] [i (in-naturals)])
      (values v (list-ref '(v0 v1 v2) i))))
  ;; atoms arrive in embedding order; re-derive the canonical atom order by
  ;; rendering each and sorting -- the canonical key sorted the same triples
  (sort (for/list ([a (in-list atoms)])
          (list (third a)
                (hash-ref name-of (fourth a))
                (hash-ref name-of (fifth a))))
        (lambda (x y) (string<? (format "~a" x) (format "~a" y)))))
