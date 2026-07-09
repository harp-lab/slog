#lang racket

;; Collection and sequence literal desugaring (docs/primitives.md;
;; docs/sequences.md §4-5).
;;
;; BRACKETS denote canonical [T] sequences.  A bracket in a rule -- head or
;; body, atom argument or nested expression -- rewrites to a fresh
;; deterministic variable plus one NEUTRAL seq-pat clause in the rule body:
;;
;;   (foo [a xs ... b])  ==>  (foo $seq0)
;;                            + (seq-pat $seq0 (elem a) (splice xs) (elem b))
;;
;; `...` is a postfix operator marking its element as a SPLICE (it binds or
;; supplies a subsequence).  Splices may appear at any position and, in
;; construction direction, in any number; the pattern-direction restrictions
;; (at most two, non-adjacent, D12 support) are enforced at expansion time
;; (seq-expand.rkt), where bindedness is known -- the desugar cannot know
;; whether a bracket destructures or constructs (§5.1: bindedness is a
;; scheduling fact), so the clause is direction-neutral and the expansion
;; pass (post-simplification, pre-typecheck) lowers it onto prims, builds,
;; or occurrence joins.
;;
;; seq-pat item grammar (raw lists, not syn nodes -- expansion owns them):
;;   (elem x)    -- x a variable (or _ wildcard, gensym'd by simplification)
;;   (elemc v)   -- a constant element (raw scalar)
;;   (splice x)  -- x a variable (or _)
;; Nested element/splice TERMS (struct patterns, prim calls, nested
;; brackets) hoist into ordinary (= $seqeN <term>) clauses, keeping items
;; flat; the hoisted clause is itself neutral (a body destructure or a
;; construction, decided downstream).
;;
;; Fresh variables are DETERMINISTIC (no gensym -- this runs before the .so
;; cache key is computed): a per-rule counter over a reserved prefix in
;; traversal order.
;;
;; A `|` in a bracket's spine still errors loudly HERE (the removed legacy
;; tail syntax); a pipe strictly inside an element subterm keeps the
;; language's uniform nested-| or-split meaning and passes through.
;; PLACEMENT (load-bearing): called from lift-type-envs (modules.rkt)
;; BEFORE the demand transform and both or-split sites.
;;
;; BRACES (collections) are untouched by the sequences work: {a b} / {k:v}
;; lower to the native collection prims (cins/cput over (cmap)) or, when
;; the rules-based Patricia libraries are included (pset/pmap declared), to
;; st_ins/mp_put (docs/primitives.md M2.3).

(require "parser.rkt")

(provide desugar-collections-mods
         collection-builtin?
         bracket-symbol?
         ellipsis-symbol?)

;; Reserved names (docs/sequences.md D2): the builtin cons list is retired,
;; but user declarations of these would silently change older programs'
;; meaning, so they stay rejected (modules.rkt check-not-reserved!).
(define (collection-builtin? name)
  (set-member? (set 'list 'cons 'nil) name))

(define (symbol-named? str)
  (lambda (x) (and (symbol? x) (equal? str (symbol->string x)))))
(define bracket-symbol? (symbol-named? "[]"))
(define brace-symbol? (symbol-named? "{}"))
(define pipe-symbol? (symbol-named? "|"))
(define ellipsis-symbol? (symbol-named? "..."))

;; mods is a list of (list path toks rules) triples (lift-type-envs'
;; working shape); rewrite every rule, leaving everything else alone.
;; `demands` (name -> (in-arity . ans-arity)) routes HEAD brackets: a
;; demand-moded head's INPUT columns are pattern context (they destructure
;; the demanded value), everything else in a head constructs.
(define (desugar-collections-mods mods [lib? #f] [demands (hash)])
  (for/list ([m (in-list mods)])
    (match-define (list path toks rules) m)
    (list path toks (for/set ([r (in-set rules)])
                      (desugar-rule r lib? demands)))))

;; -----------------------------------------------------------------------
;; Per-rule bracket rewriting.
;;
;; Rules arrive normalized as (syn prov rule bodys ... --> heads ...)
;; (extract-rules, modules.rkt; facts are body-less rules).  Two walking
;; modes (docs/sequences.md §4.2):
;;
;;   PATTERN mode -- body clauses, and the INPUT columns of a full-arity
;;   demand-moded head (they match the demanded value).  A bracket becomes
;;   a fresh deterministic variable plus one neutral seq-pat clause in the
;;   rule body; nested element terms hoist to (= $seqeN <term>) BODY
;;   clauses (destructures).
;;
;;   CONSTRUCTION mode -- every other head position.  A bracket lowers IN
;;   PLACE to a nested lempty/lpush/lcat prim chain, so its element terms
;;   stay head-side: simplification flattens them into head constructions,
;;   exactly as nested struct terms always flattened.  (Hoisting them to
;;   the body would turn constructions into empty-relation joins.)

(define (desugar-rule rule lib? demands)
  (match rule
    [`(syn ,prov rule ,clauses ...)
     (define-values (bodys arrow-heads) (splitf-at clauses
                                                   (lambda (c) (not (eq? c '-->)))))
     (define heads (cdr arrow-heads))
     (define counter (box 0))
     (define extra (box '()))   ; collected body clauses, reverse order
     (define (fresh! stem)
       (define n (unbox counter))
       (set-box! counter (add1 n))
       (string->symbol (format "$~a~a" stem n)))
     (define (collect! cl) (set-box! extra (cons cl (unbox extra))))
     (define (pat t) (walk-pattern t lib? fresh! collect!))
     (define (con t) (walk-construction t lib? fresh! collect!))
     (define (walk-head cl)
       (match cl
         ;; a full-arity demand-moded judgment head: input columns match
         ;; the demanded value (pattern), answer columns construct
         [`(syn ,p ,(? symbol? name) ,args ...)
          #:when (match (hash-ref demands name #f)
                   [(cons nd na) (= (length args) (+ nd na))]
                   [_ #f])
          (match-define (cons nd _na) (hash-ref demands name))
          `(syn ,p ,name
                ,@(map pat (take args nd))
                ,@(map con (drop args nd)))]
         [_ (con cl)]))
     (define bodys+ (map pat bodys))
     (define heads+ (map walk-head heads))
     `(syn ,prov rule ,@bodys+ ,@(reverse (unbox extra)) --> ,@heads+)]
    [_ rule]))

;; PATTERN mode: brackets become fresh vars + collected seq-pat clauses;
;; braces lower in place (pure expressions); everything else recurses.
(define (walk-pattern term lib? fresh! collect!)
  (match term
    [`(syn ,prov const ,_) term]
    [`(syn ,prov ,(? bracket-symbol?) ,args ...)
     (desugar-bracket prov (map (lambda (a) (walk-pattern a lib? fresh! collect!))
                                args)
                      fresh! collect!)]
    [`(syn ,prov ,(? brace-symbol?) ,args ...)
     (desugar-brace prov (map (lambda (a) (walk-pattern a lib? fresh! collect!))
                              args)
                    lib?)]
    [`(syn ,prov ,head ,args ...)
     `(syn ,prov
           ,(if (symbol? head) head (walk-pattern head lib? fresh! collect!))
           ,@(map (lambda (a) (walk-pattern a lib? fresh! collect!)) args))]
    [_ term]))

;; CONSTRUCTION mode: brackets lower in place to lempty/lpush/lcat chains
;; (splices concatenate); nested brackets recurse in construction mode.
(define (walk-construction term lib? fresh! collect!)
  (match term
    [`(syn ,prov const ,_) term]
    [`(syn ,prov ,(? bracket-symbol?) ,args ...)
     (for ([a (in-list args)])
       (match a
         [`(syn ,_ ,(? pipe-symbol?) ,_ ...)
          (error (parse-error
                  "The | tail syntax was replaced by a postfix ...: [x y t ...]"
                  (cdr prov)))]
         [_ (void)]))
     (for/fold ([acc `(syn ,prov lempty)]) ([a (in-list args)])
       (match a
         [`(syn ,pprov ,(? ellipsis-symbol?) ,t)
          `(syn ,pprov lcat ,acc ,(walk-construction t lib? fresh! collect!))]
         [`(syn ,pprov ,(? ellipsis-symbol?) ,_ ...)
          (error (parse-error "Malformed splice: postfix ... takes one element"
                              (cdr pprov)))]
         [_ `(syn ,prov lpush ,acc
                   ,(walk-construction a lib? fresh! collect!))]))]
    [`(syn ,prov ,(? brace-symbol?) ,args ...)
     (desugar-brace prov (map (lambda (a)
                                (walk-construction a lib? fresh! collect!))
                              args)
                    lib?)]
    [`(syn ,prov ,head ,args ...)
     `(syn ,prov
           ,(if (symbol? head) head (walk-construction head lib? fresh! collect!))
           ,@(map (lambda (a) (walk-construction a lib? fresh! collect!)) args))]
    [_ term]))

;; One bracket node (arguments already walked): produce the fresh list
;; variable and collect its neutral seq-pat clause.
(define (desugar-bracket prov args fresh! collect!)
  ;; the legacy `| tail` spine syntax stays a loud error (letting it
  ;; through would hand split-or-clauses a silent cartesian split)
  (for ([a (in-list args)])
    (match a
      [`(syn ,_ ,(? pipe-symbol?) ,_ ...)
       (error (parse-error
               "The | tail syntax was replaced by a postfix ...: [x y t ...]"
               (cdr prov)))]
      [_ (void)]))
  (define (item-of a)
    (match a
      ;; splice: postfix ... marks its element as a subsequence
      [`(syn ,pprov ,(? ellipsis-symbol?) ,t)
       (match t
         [(? symbol? x) `(splice ,x)]
         [_ (let ([v (fresh! 'seqe)])
              (collect! `(syn ,pprov = ,v ,t))
              `(splice ,v))])]
      [`(syn ,pprov ,(? ellipsis-symbol?) ,_ ...)
       (error (parse-error "Malformed splice: postfix ... takes one element"
                           (cdr pprov)))]
      ;; element: a variable, a constant, or a hoisted term
      [(? symbol? x) `(elem ,x)]
      [`(syn ,_ const ,v) `(elemc ,v)]
      [`(syn ,pprov ,_ ...)
       (let ([v (fresh! 'seqe)])
         (collect! `(syn ,pprov = ,v ,a))
         `(elem ,v))]
      [_ (error (parse-error "Malformed bracket element" (cdr prov)))]))
  (define items (map item-of args))
  (define lvar (fresh! 'seq))
  (collect! `(syn ,prov seq-pat ,lvar ,@items))
  lvar)

;; One brace node, arguments already desugared (docs/primitives.md
;; Phase 1 / M2.3).  A set literal {a b c} folds an insert over the empty
;; collection; a map literal {a:b c:d} folds a put; {es base ...} threads
;; an existing collection instead of the empty one -- so {a:b m ...} is
;; a functional map update and {x y s ...} inserts x and y into set s.
;; Entries and pairs may not mix; the leftmost entry wins on duplicates
;; (it is applied last).
;;
;; Two lowerings, chosen per program (modules.rkt lift-type-envs): with
;; lib/set.slog / lib/map.slog included (pset/pmap declared), braces
;; target the rules-based judgments (st_ins/mp_put over pempty/mempty);
;; otherwise the native collection prims (cins/cput over (cmap), where
;; a set is a map-to-unit).  Native braces admit the empty {} (one
;; canonical empty collection); the lib keeps its pempty/mempty split.
(define (desugar-brace prov args lib?)
  (define (spine-pipe! a)
    (match a
      [`(syn ,_ ,(? pipe-symbol?) ,_ ...)
       (error (parse-error
               "The | tail syntax was replaced by a postfix ...: {x y s ...}"
               (cdr prov)))]
      [_ (void)]))
  (for ([a (in-list args)]) (spine-pipe! a))
  (define (split-extension args)
    (for ([a (in-list (if (null? args) '() (drop-right args 1)))])
      (match a
        [`(syn ,_ ,(? ellipsis-symbol?) ,_ ...)
         (error (parse-error
                 "A collection extension base t... must come last: {x y s ...}"
                 (cdr prov)))]
        [_ (void)]))
    (match args
      [`(,init ... (syn ,pprov ,(? ellipsis-symbol?) ,t))
       (values init t)]
      [`(,init ... (syn ,pprov ,(? ellipsis-symbol?) ,_ ...))
       (error (parse-error
               "Malformed collection extension base: {x y s ...}"
               (cdr pprov)))]
      [_ (values args #f)]))
  (define (pair-entry a)
    (match a
      [`(syn ,_ ,(? (symbol-named? ":")) ,k ,v) (cons k v)]
      [_ #f]))
  (define-values (entries base) (split-extension args))
  (when (and base (pair-entry base))
    (error (parse-error
            "The base of a collection extension cannot be a k:v entry: {k:v m ...}"
            (cdr prov))))
  (when (and lib? (null? entries) (not base))
    (error (parse-error
            "An empty {} is ambiguous: write (pempty) for the empty set or (mempty) for the empty map"
            (cdr prov))))
  (define pairs (map pair-entry entries))
  (define (fold-map put-name empty-term)
    (foldr (lambda (kv acc)
             `(syn ,prov ,put-name ,acc ,(car kv) ,(cdr kv)))
           (or base empty-term)
           pairs))
  (define (fold-set ins-name empty-term)
    (foldr (lambda (e acc) `(syn ,prov ,ins-name ,acc ,e))
           (or base empty-term)
           entries))
  (cond
    [(and (null? entries) (not base))            ; native {}: the empty map
     `(syn ,prov cmap)]
    [(andmap values pairs)                       ; all k:v -- a map
     (if lib?
         (fold-map 'mp_put `(syn ,prov mempty))
         (fold-map 'cput `(syn ,prov cmap)))]
    [(ormap values pairs)
     (error (parse-error
             "A brace literal cannot mix set elements and k:v map entries"
             (cdr prov)))]
    [else                                        ; all plain -- a set
     (if lib?
         (fold-set 'st_ins `(syn ,prov pempty))
         (fold-set 'cins `(syn ,prov cmap)))]))
