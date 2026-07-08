#lang racket

;; Collection literal desugaring (docs/primitives.md; Phase 0: lists).
;;
;; Rewrites bracket list literals/patterns, in every rule of every
;; module, into the builtin cons/nil constructors:
;;
;;   [a b c]     -->  (cons a (cons b (cons c (nil))))
;;   [a b t ...] -->  (cons a (cons b t))    ; postfix ... extends list t
;;   []          -->  (nil)
;;
;; The parser leaves brackets as ([] e ...) application nodes.  A tail
;; extension is written as a postfix ... on the FINAL element, which
;; parses as ([] a b (... t)); split-extension pulls that base out.  The
;; older `| T` tail syntax was REMOVED (triple-overloaded and neighbour-
;; binding); a `|` anywhere in the bracket's spine now errors loudly HERE,
;; deliberately: if it survived to an or-split (simplification, or the
;; demand transform's split before scheduling), split-or-clauses recurses
;; into every subterm and would silently cartesian-split the rule into
;; wrong alternatives.  A pipe strictly inside an element subterm keeps
;; the language's uniform nested-| or-split meaning and passes through.
;;
;; PLACEMENT (load-bearing, not stylistic): called from lift-type-envs
;; (modules.rkt) BEFORE the demand transform, so no (| ...) remains
;; inside a ([] ...) by the time either or-split site runs.  Like the
;; demand transform, this runs before the .so cache key is computed
;; (program->jobs hashes the rewritten module rules), so it must be
;; deterministic run to run: no gensym -- and none is needed, since the
;; rewrite introduces only the fixed builtin names cons/nil (seeded in
;; modules.rkt base-type-env alongside _enum).

(require "parser.rkt")

(provide desugar-collections-mods
         collection-builtin?)

;; The reserved builtin names (docs/primitives.md §12 D5): bracket
;; syntax denotes these, so user declarations of them are rejected
;; (modules.rkt) rather than silently conflicting.
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
;; lib? routes brace literals: #t targets the rules-based Patricia
;; libraries (st_ins/mp_put over pset/pmap structs -- programs that
;; include lib/set.slog or lib/map.slog), #f targets the native
;; collection prims (cmap/cins/cput over arena words).
(define (desugar-collections-mods mods [lib? #f])
  (for/list ([m (in-list mods)])
    (match-define (list path toks rules) m)
    (list path toks (for/set ([r (in-set rules)]) (walk-term r lib?)))))

;; Bottom-up generic walk over syntax nodes.  Provenance lists and
;; constants pass through untouched; bare symbols (variables, -->) fall
;; to the catch-all.
(define (walk-term term lib?)
  (match term
    [`(syn ,prov const ,_) term]
    [`(syn ,prov ,(? bracket-symbol?) ,args ...)
     (desugar-bracket prov (map (lambda (a) (walk-term a lib?)) args))]
    [`(syn ,prov ,(? brace-symbol?) ,args ...)
     (desugar-brace prov (map (lambda (a) (walk-term a lib?)) args) lib?)]
    [`(syn ,prov ,head ,args ...)
     `(syn ,prov
           ,(if (symbol? head) head (walk-term head lib?))
           ,@(map (lambda (a) (walk-term a lib?)) args))]
    [_ term]))

;; Extract the extension base from a bracket/brace node's arguments: a
;; postfix ... on the FINAL element -- [x y t ...] extends list t;
;; {x y s ...} inserts into set s; {k:v m ...} updates map m.  The
;; postfix parses as (... t) wrapping only the last element, has no
;; other meaning in the language, and is inert to the or-splitter --
;; which is why it replaced the earlier | tail syntax (triple-overloaded
;; and neighbor-binding).  A pipe in the spine still errors loudly here:
;; letting it through would hand split-or-clauses a silent cartesian
;; split.  Returns (values elems base-or-#f).
(define (split-extension prov args what example)
  (define (spine-pipe? a)
    (match a [`(syn ,_ ,(? pipe-symbol?) ,_ ...) #t] [_ #f]))
  (define (spine-ellipsis? a)
    (match a [`(syn ,_ ,(? ellipsis-symbol?) ,_ ...) #t] [_ #f]))
  (for ([a (in-list args)])
    (when (spine-pipe? a)
      (error (parse-error
              (format "The | tail syntax was replaced by a postfix ...: ~a" example)
              (cdr prov)))))
  (for ([a (in-list (if (null? args) '() (drop-right args 1)))])
    (when (spine-ellipsis? a)
      (error (parse-error
              (format "A ~a extension base t... must come last: ~a" what example)
              (cdr prov)))))
  (match args
    [`(,init ... (syn ,pprov ,(? ellipsis-symbol?) ,t))
     (values init t)]
    [`(,init ... (syn ,pprov ,(? ellipsis-symbol?) ,_ ...))
     (error (parse-error
             (format "Malformed ~a extension base: ~a" what example)
             (cdr pprov)))]
    [_ (values args #f)]))

;; One bracket node, arguments already desugared: [a b] a literal,
;; [a b t ...] consing onto tail t.
(define (desugar-bracket prov args)
  (define-values (elems tail) (split-extension prov args "list" "[x y t ...]"))
  (foldr (lambda (e acc) `(syn ,prov cons ,e ,acc))
         (or tail `(syn ,prov nil))
         elems))

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
  (define (pair-entry a)
    (match a
      [`(syn ,_ ,(? (symbol-named? ":")) ,k ,v) (cons k v)]
      [_ #f]))
  (define-values (entries base)
    (split-extension prov args "collection" "{x y s ...} / {k:v m ...}"))
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
