#lang racket

;; Sequence-pattern expansion (docs/sequences.md §5): lower every neutral
;; seq-pat clause (collections.rkt) onto ordinary clauses -- prim computes,
;; guards, and joins -- so the planner, select-set requisition, and emission
;; machinery all apply unchanged.
;;
;; Runs at program level between simplification and typechecking
;; (compile.rkt): after simplification so `_` wildcards are already gensym'd
;; `__` variables (D13: __-prefixed items are DEAD -- no lref/lslice is
;; materialized for them); before typechecking so the emitted clauses are
;; plain surface forms the checker types like user-written code.  This pass
;; is deterministic given its input; it runs after the .so cache key is
;; computed, so gensym is legal for local variables (synthesized RELATION
;; names stay fixed).
;;
;; DIRECTION.  Bindedness is a scheduling fact (§5.1), approximated here at
;; rule level: variables of every non-seq-pat body clause count as bound
;; (the same over-approximation the demand transform uses -- a genuinely
;; unsafe rule still errors in planning).  A fixpoint then classifies each
;; seq-pat:
;;
;;   pattern       the list var is bound: llen guard + lref anchors +
;;                 lslice splices (§5.2).  Equality checks ride the
;;                 planner's ground-output compute pattern (computing into
;;                 an already-bound variable becomes a ==-check).
;;   construction  every live item var is bound and the list is not: build
;;                 the list -- lempty/lpush element runs, lcat splices --
;;                 binding the list var (heads' [a xs ... b] and ground
;;                 literals land here; any number of splices is legal).
;;   neither       a STATIC ERROR (D12): nothing constrains the list.
;;
;; INVERTED JOINS (§5.3/§5.4).  A pattern-direction seq-pat whose list is
;; bound by a persisted atom column gets redundant occurrence joins --
;; ($seq_at val pos L) / ($seq_atr val rpos L) -- that the planner is free
;; to schedule FIRST, binding L from content when that is more selective
;; than scanning the atom.  Anchors: EVERY fixed-position element that is a
;; constant or a variable bound by another body clause (multi-anchor =
;; multiple probes joined on L); floating-run elements probe $seq_at with
;; `(= pos (- pk k))` tying the probe position to the enumerator's run
;; start; the membership nicety adds a free-position probe.  All probes
;; join on the RAW list variable (the atom's word), not the aslst output.
;; Soundness: every list reaching a fed column has its occurrence rows
;; published by the daemon's SeqIndexTask (emit-cpp) with a one-iteration
;; lag, and the join's delta-driven version refires the rule when rows
;; arrive -- the same lag discipline structs and the M2.4 decomposition
;; ride.  The occurrence relations are declared (and fed) ONLY when some
;; eligible pattern exists; stratification edges base -> $seq_at mirror
;; decomp-edges; compile.rkt warns when a fed relation grows recursively
;; (§5.3 defense (b)).
;;
;; PATTERN SHAPES (D16).  A pattern's items segment as
;;   pre  B1 r1 B2 ... r_{m-1} Bm  post
;; -- maximal blocks Bi of adjacent splices separated by non-empty fixed
;; runs ri, with fixed prefix/suffix outside.  Runs FLOAT: each needed run
;; joins the position enumerator ($seq_posdem/$seq_pos, per-host ask
;; rules), placements ordered left-to-right by <=-guards; fan-out = every
;; placement (>=2 floating runs warn: O(n^r) placements per list).
;; Blocks split DETERMINISTICALLY: k adjacent splices over an extent of m
;; elements bind slices sized floor(m/k)+1 (the first m mod k) then
;; floor(m/k) -- longer first, a pure function of the list; [xs ... ys ...]
;; halves favoring the left.  The membership nicety [_ ... e _ ...] (dead
;; splices, single bound/ground run element) collapses to an lmem guard
;; instead.

(require "utils.rkt")
(require "ir-shared.rkt")

(provide expand-seq-patterns
         seq-occurrence-rels
         seq-fed-relations)

(define seq-occurrence-rels (set '$seq_at '$seq_atr))

;; Synthesized sequence-machinery relations that must never THEMSELVES be
;; occurrence-fed: the occurrence tables (their `list` column would feed
;; itself) and the position enumerator (its demanded lists are already fed
;; by whatever relation supplied them; re-feeding just duplicates rows and
;; trips the recursive-growth warning on machinery the user never wrote).
(define seq-internal-rels (set '$seq_at '$seq_atr '$seq_posdem '$seq_pos))

;; -----------------------------------------------------------------------
;; Small helpers over post-simplification clause forms.

(define (seq-pat-cl? cl)
  (match cl
    [`(syn ,_ seq-pat ,_ ...) #t]
    [_ #f]))

(define (dead-var? x)
  (and (symbol? x) (string-prefix? (symbol->string x) "__")))

(define (item-var it)
  (match it [`(,(or 'elem 'splice) ,x) x] [_ #f]))

(define (term-vars e)
  (match e
    [`(syn ,_ const ,_) (set)]
    [`(syn ,_ ,_ ,args ...) (apply set-union (set) (map term-vars args))]
    [`(,(or 'elem 'splice) ,(? symbol? x)) (set x)]
    [`(elemc ,_) (set)]
    [(? symbol? x) (set x)]
    [_ (set)]))

(define (clause-arg-vars cl)
  (match cl
    [`(syn ,_ ,_ ,args ...) (apply set-union (set) (map term-vars args))]
    [_ (set)]))

;; Does a declared column type name resolve to the sequence base type?
(define (cseq-type? rels t)
  (and (symbol? t) (eq? 'cseq (lattice-base-type rels t))))

;; Variables sitting in cseq-resolving columns of a body atom.
(define (atom-cseq-vars cl rels)
  (define (cols name args)
    (match (hash-ref rels name #f)
      [`(,(or 'table 'struct) ,ts ...)
       #:when (= (length ts) (length args))
       (for/set ([t (in-list ts)] [a (in-list args)]
                 #:when (and (symbol? a) (cseq-type? rels t)))
         a)]
      [_ (set)]))
  (match cl
    [`(syn ,_ = ,(? symbol?) (syn ,_ ,(? symbol? name) ,args ...))
     (cols name args)]
    [`(syn ,_ ,(? symbol? name) ,(? symbol? args) ...)
     (cols name args)]
    [_ (set)]))

;; The relations whose rows the SeqIndexTask must walk: every declared
;; table/struct with a cseq-resolving column (D6: type-based, program-wide),
;; excluding the occurrence relations themselves.  Shared with emit-cpp.
(define (seq-fed-relations rels)
  (sort
   (for/list ([(name decl) (in-hash rels)]
              #:when (and (not (set-member? seq-internal-rels name))
                          (match decl
                            [`(,(or 'table 'struct) ,ts ...)
                             (ormap (lambda (t) (cseq-type? rels t)) ts)]
                            [_ #f])))
     name)
   symbol<?))

;; -----------------------------------------------------------------------
;; The pass.

;; rules: set of simplified surface rules; type-env: the program env.
;; Returns (values rules+ type-env+ seq-edges) where seq-edges are
;; stratification edges (base . occurrence-rel), decomp-edges style.
(define (expand-seq-patterns rules type-env)
  (define rels (type-env-rels type-env))
  (define used-occ (mutable-set))   ; occurrence rels some rule now joins
  (define pos-provs (mutable-set))  ; floating-run sites (their provs)

  (define rules0
    (for/fold ([acc (set)]) ([rule (in-set rules)])
      (for/fold ([acc acc]) ([r (in-list (expand-rule rule rels used-occ
                                                      pos-provs))])
        (set-add acc r))))

  ;; the position enumerator (docs/sequences.md §5.2, floating runs): all
  ;; valid run-start positions of a demanded (list, run-length) pair --
  ;; ($seq_posdem l j) -> ($seq_pos l j pos) for pos in [0, llen-j].
  ;; Memoized demand-style recursion as ordinary rules; asks are emitted by
  ;; the per-host ask rules expand-rule builds.  Synthesized ONCE, with a
  ;; deterministic prov (the lexically-least floating-run site).
  (define pos-needed? (not (set-empty? pos-provs)))
  (define rules+
    (if (not pos-needed?)
        rules0
        (let* ([prov (car (sort (set->list pos-provs)
                                string<? #:key (lambda (p) (format "~a" p))))]
               [enum-rules
                (list
                 `(syn ,prov rule
                       (syn ,prov $seq_posdem l j)
                       (syn ,prov = n (syn ,prov llen l))
                       (syn ,prov >= n j)
                       (syn ,prov = z (syn ,prov const 0))
                       --> (syn ,prov $seq_pos l j z))
                 `(syn ,prov rule
                       (syn ,prov $seq_pos l j p)
                       (syn ,prov = n (syn ,prov llen l))
                       (syn ,prov = lim (syn ,prov - n j))
                       (syn ,prov < p lim)
                       (syn ,prov = one (syn ,prov const 1))
                       (syn ,prov = p1 (syn ,prov + p one))
                       --> (syn ,prov $seq_pos l j p1)))])
          (for/fold ([acc rules0]) ([r (in-list enum-rules)])
            (set-add acc r)))))

  (define new-rels
    (append (sort (set->list used-occ) symbol<?)
            (if pos-needed?
                (list (cons '$seq_posdem '(table cseq int))
                      (cons '$seq_pos '(table cseq int int)))
                '())))
  (cond
    [(null? new-rels) (values rules+ type-env (set))]
    [else
     (define env+
       (for/fold ([env type-env]) ([entry (in-list new-rels)])
         (define-values (name decl)
           (if (pair? entry)
               (values (car entry) (cdr entry))
               (values entry `(table any int cseq))))
         (when (hash-has-key? (type-env-rels env) name)
           (error 'seq-expand "~a is a reserved sequence-index relation" name))
         (list (type-env-aliases env)
               (hash-set (type-env-rels env) name decl)
               (type-env-funs env))))
     ;; NO stratification edges (unlike decomp-edges).  Occurrence probes
     ;; are ADDITIVE: the reader rule always also joins the fed atom, which
     ;; already orders the reader's stratum after every base it reads; and
     ;; occurrence COMPLETENESS within a stratum comes from SeqIndexTask's
     ;; iteration-0 re-derivation of the reloaded content plus per-delta
     ;; walks (the $seq_at-delta-driven version refires on the publish
     ;; lag).  Base->$seq_at edges would instead MERGE the occurrence
     ;; relation into every recursive list-producing SCC whose rules probe
     ;; it -- restructuring stratification (and breaking lattice
     ;; cross-strata reads) for a dependency the design does not have.
     ;; This argument holds ONLY while probes are additive; a future
     ;; lowering that DROPS the source atom must reintroduce the edges.
     (values rules+ env+ (set))]))

(define (expand-rule rule rels used-occ pos-provs)
  (match rule
    [`(syn ,prov rule ,bodys ... --> ,heads ...)
     #:when (ormap seq-pat-cl? bodys)
     (define sps (filter seq-pat-cl? bodys))
     (define others (filter (lambda (c) (not (seq-pat-cl? c))) bodys))

     ;; rule-level bindedness: everything a non-seq-pat body clause mentions
     (define bound0
       (apply set-union (set) (map clause-arg-vars others)))
     ;; occurrence counts across the whole rule, for dead-splice elision
     ;; (a NAMED splice read by nothing still skips its lslice)
     (define uses (make-hash))
     (for ([cl (in-list (append bodys heads))])
       (let count ([e cl])
         (match e
           [`(syn ,_ const ,_) (void)]
           [`(syn ,_ ,_ ,args ...) (for-each count args)]
           [`(,(or 'elem 'splice) ,(? symbol? x))
            (hash-update! uses x add1 0)]
           [`(elemc ,_) (void)]
           [(? symbol? x) (hash-update! uses x add1 0)]
           [_ (void)])))
     (define (used-outside-pattern? x)
       ;; bound elsewhere or mentioned more than its one pattern occurrence
       (or (> (hash-ref uses x 0) 1) (set-member? bound0 x)))

     ;; the vars an atom binds into cseq columns (occurrence-join eligibility)
     (define atom-cseq-bound
       (apply set-union (set) (map (lambda (c) (atom-cseq-vars c rels)) others)))

     ;; ---- direction fixpoint -------------------------------------------
     (define (sp-parts sp)
       (match sp [`(syn ,p seq-pat ,l ,items ...) (values p l items)]))
     (define (live-item-vars items)
       (for/set ([it (in-list items)]
                 #:when (and (item-var it) (not (dead-var? (item-var it)))))
         (item-var it)))

     (define directions (make-hash))   ; sp -> 'pattern | 'construction | 'drop
     (define final-bound
       (let fixpoint ([bound bound0])
         (define progressed
           (for/or ([sp (in-list sps)] #:when (not (hash-has-key? directions sp)))
             (define-values (p l items) (sp-parts sp))
             (cond
               [(set-member? bound l)
                (hash-set! directions sp 'pattern)
                sp]
               [(and (subset? (live-item-vars items) bound)
                     (not (ormap (lambda (it) (and (item-var it)
                                                   (dead-var? (item-var it))))
                                 items)))
                (hash-set! directions sp 'construction)
                sp]
               [else #f])))
         (if progressed
             (let-values ([(p l items) (sp-parts progressed)])
               (fixpoint (set-union bound (set-add (live-item-vars items) l))))
             bound)))
     (for ([sp (in-list sps)])
       (unless (hash-has-key? directions sp)
         (define-values (p l items) (sp-parts sp))
         ;; An unresolvable seq-pat whose list AND unbound live items are
         ;; read by nothing else is a dangling existential -- "some list of
         ;; this shape exists" -- which value semantics makes vacuously true
         ;; (lists are values, not a finite store): DROP it.  The demand
         ;; transform manufactures exactly these when it copies a rule's
         ;; clauses into an ask rule that only needs a subset of them.
         (define (used-elsewhere? v) (> (hash-ref uses v 0) 1))
         (if (and (not (used-elsewhere? l))
                  (for/and ([v (in-set (live-item-vars items))])
                    (or (set-member? final-bound v) (not (used-elsewhere? v)))))
             (hash-set! directions sp 'drop)
             (error 'seq-expand
                    (string-append
                     "a bracket pattern constrains list ~a with nothing ground or"
                     " bound (D12: matching would enumerate every list, and its"
                     " elements are not all bound for construction) in\n~a")
                    l (strip-prov rule)))))

     ;; ---- emission ------------------------------------------------------
     ;; Per seq-pat: main clauses (the host rule's full lowering) and base
     ;; clauses (the ask-safe subset: length guard + anchors, no enumerator
     ;; join) plus, for each floating run, its run length j.  Ask rules
     ;; demand the position enumerator from everything EXCEPT the enumerator
     ;; joins themselves (no demand cycles between floating runs in a rule).
     (define parts
       (for/list ([sp (in-list sps)])
         (define-values (p l items) (sp-parts sp))
         (match (hash-ref directions sp)
           ['pattern
            (define-values (main base run-js)
              (emit-pattern p l items rule rels atom-cseq-bound
                            used-occ used-outside-pattern? bound0))
            (list main base (and (pair? run-js) (list p l run-js)))]
           ['construction
            (define cls (emit-construction p l items))
            (list cls cls #f)]
           ['drop (list '() '() #f)])))
     (define host
       `(syn ,prov rule ,@others ,@(append* (map first parts)) --> ,@heads))
     (define common (append* (map second parts)))
     (define asks
       (append*
        (for/list ([part (in-list parts)] #:when (third part))
          (match-define (list p l js) (third part))
          (for/list ([j (in-list (remove-duplicates js))])
            (define cj (gensymb '$sqc))
            `(syn ,p rule ,@others ,@common
                  (syn ,p = ,cj (syn ,p const ,j))
                  --> (syn ,p $seq_posdem ,l ,cj))))))
     (when (pair? asks)
       (set-add! pos-provs prov))
     (cons host asks)]
    [_ (list rule)]))

;; -----------------------------------------------------------------------
;; Construction direction: [a xs ... b] with every live var bound builds
;; the list -- lempty/lpush per element, lcat per splice; the LAST step
;; binds the pattern's list var (already-bound list vars become the
;; planner's ==-check, giving [1 2 3] literal equality for free).

(define (emit-construction p l items)
  (cond
    [(null? items) (list `(syn ,p = ,l (syn ,p lempty)))]
    [else
     (define n (length items))
     (define seed (gensymb '$sqb))
     (let loop ([items items] [i 0] [acc seed]
                [cls (list `(syn ,p = ,seed (syn ,p lempty)))])
       (match items
         ['() (reverse cls)]
         [(cons it rest)
          (define target (if (= i (sub1 n)) l (gensymb '$sqb)))
          (match it
            [`(elem ,x)
             (loop rest (add1 i) target
                   (cons `(syn ,p = ,target (syn ,p lpush ,acc ,x)) cls))]
            [`(elemc ,v)
             (define cv (gensymb '$sqc))
             (loop rest (add1 i) target
                   (list* `(syn ,p = ,target (syn ,p lpush ,acc ,cv))
                          `(syn ,p = ,cv (syn ,p const ,v))
                          cls))]
            [`(splice ,x)
             (loop rest (add1 i) target
                   (cons `(syn ,p = ,target (syn ,p lcat ,acc ,x)) cls))])]))]))

;; -----------------------------------------------------------------------
;; Pattern direction (§5.2): the list var is bound.  Items segment as
;;
;;     pre  B1 r1 B2 r2 ... r_{m-1} Bm  post
;;
;; where the Bi are MAXIMAL blocks of adjacent splices, the ri are the
;; (necessarily non-empty) fixed-element runs between them, and pre/post
;; are the fixed elements outside the blocks.  Two orthogonal mechanisms
;; (D16):
;;
;;   * runs FLOAT: each needed run joins the position enumerator
;;     ($seq_pos), placements ordered left-to-right by <=-guards -- the
;;     fan-out over placements IS the semantics.  A run is SKIPPED (no
;;     enumerator join) when its elements are all dead and neither
;;     adjacent block has a live splice; its length then matters only
;;     through the arity guard and its neighbors' slack constants.  Two
;;     or more floating runs warn: O(n^r) placements per list.
;;   * blocks split DETERMINISTICALLY: a block of k splices over an
;;     extent of mid elements binds k slices sized floor(mid/k)+1 (the
;;     first mid mod k of them) then floor(mid/k) -- longer slices first,
;;     a pure function of the list.  Boundary c (1..k-1) sits at
;;     lo + ceil(c*mid/k) = lo + (c*mid + k-1)/k (truncated non-negative
;;     division).  k=1 degenerates to the classic single lslice, and
;;     [xs ... ys ...] halves favoring the left ([0] gives xs=[0] ys=[]).
;;
;; Construction direction is untouched (splices concatenate, any shape),
;; so cat-of-split is the identity but split-of-cat is not on unbalanced
;; inputs -- the direction asymmetry documented at §4.2.
;;
;; Returns three values: the full clause list, the ask-safe base subset
;; (length guard + fixed pre/post anchors), and the list of run lengths j
;; that joined the enumerator (each needs a $seq_posdem ask rule).

(define (emit-pattern p l0 items rule rels atom-cseq-bound used-occ
                      used-outside-pattern? bound0)
  ;; The chain's entry point: l0 as a sequence, PARTIAL (aslst) -- a
  ;; non-sequence word (an `any` column's int, a flat lattice's top)
  ;; MATCH-FAILS instead of faulting a fatal-on-type kernel.  Every
  ;; downstream op consumes `l` (aslst's output), so the planner orders the
  ;; test first by data dependency.
  (define l (gensymb '$sql))
  (define entry (list `(syn ,p = ,l (syn ,p aslst ,l0))))

  (define (splice-item? it) (match it [`(splice ,_) #t] [_ #f]))
  (define (splice-live? it)
    ;; dead or never-read splices materialize no slice (D13)
    (match it
      [`(splice ,x) (and (not (dead-var? x)) (used-outside-pattern? x))]
      [_ #f]))
  (define (elem-live? it)
    (match it
      [`(elem ,x) (not (dead-var? x))]
      [`(elemc ,_) #t]
      [_ #f]))

  ;; (= target (lref l <posvar>)) with elemc/rebound handling: computing
  ;; into a bound variable is the planner's ==-check
  (define (lref-clause target-item posvar)
    (match target-item
      [`(elem ,x)
       (list `(syn ,p = ,x (syn ,p lref ,l ,posvar)))]
      [`(elemc ,v)
       (define cv (gensymb '$sqc))
       (list `(syn ,p = ,cv (syn ,p const ,v))
             `(syn ,p = ,cv (syn ,p lref ,l ,posvar)))]))
  (define (constv i)
    (define c (gensymb '$sqc))
    (values c `(syn ,p = ,c (syn ,p const ,i))))

  ;; ---- segmentation ----------------------------------------------------
  (define-values (pre rest0)
    (splitf-at items (lambda (it) (not (splice-item? it)))))
  (define-values (rblocks rruns post)
    (let loop ([rest rest0] [blocks '()] [runs '()])
      (if (null? rest)
          (values blocks runs '())
          (let*-values ([(blk after-blk) (splitf-at rest splice-item?)]
                        [(fixed after-fixed)
                         (splitf-at after-blk
                                    (lambda (it) (not (splice-item? it))))])
            (if (null? after-fixed)
                (values (cons blk blocks) runs fixed)
                (loop after-fixed (cons blk blocks) (cons fixed runs)))))))
  (define blocks (reverse rblocks))
  (define runs (reverse rruns))          ; m-1 of them, each non-empty
  (define m (length blocks))
  (define run-js (map length runs))
  (define n-fixed (+ (length pre) (apply + run-js) (length post)))

  ;; ---- base: entry + length guard + fixed pre/post anchors -------------
  (define nv (gensymb '$sqn))
  (define-values (kv kcl) (constv n-fixed))
  (define len-cls
    (if (zero? m)
        ;; exact arity: llen computed into the const-bound var (==-check)
        (list kcl `(syn ,p = ,kv (syn ,p llen ,l)))
        (list `(syn ,p = ,nv (syn ,p llen ,l))
              kcl
              `(syn ,p >= ,nv ,kv))))
  (define pre-cls
    (for/fold ([acc '()]) ([it (in-list pre)] [i (in-naturals)]
                           #:when (elem-live? it))
      (define-values (cv ccl) (constv i))
      (append acc (cons ccl (lref-clause it cv)))))
  (define post-cls
    (for/fold ([acc '()]) ([it (in-list post)] [j (in-naturals)]
                           #:when (elem-live? it))
      ;; element j of post sits (|post| - j) from the end
      (define-values (cv ccl) (constv (- (length post) j)))
      (define pv (gensymb '$sqp))
      (append acc
              (list ccl `(syn ,p = ,pv (syn ,p - ,nv ,cv)))
              (lref-clause it pv))))
  (define base (append entry len-cls pre-cls post-cls))
  (define (assist)
    (occurrence-assist p l0 items rule rels atom-cseq-bound used-occ bound0))

  (cond
    ;; ---- no splice: exact arity ----------------------------------------
    [(zero? m)
     (values (append base (assist)) base '())]

    ;; ---- membership nicety [_ ... e _ ...]: all splices dead, no
    ;; pre/post, single-element run that is ground or bound -> lmem guard
    [(and (= m 2) (null? pre) (null? post)
          (not (ormap splice-live? (append* blocks)))
          (= 1 (length (first runs)))
          (match (first (first runs))
            [`(elemc ,_) #t]
            [`(elem ,x) (and (not (dead-var? x)) (set-member? bound0 x))]
            [_ #f]))
     (define-values (ev ecl)
       (match (first (first runs))
         [`(elemc ,v) (let ([c (gensymb '$sqc)])
                        (values c (list `(syn ,p = ,c (syn ,p const ,v)))))]
         [`(elem ,x) (values x '())]))
     (define-values (onev onecl) (constv 1))
     ;; the inverted membership probe (§5.4): $seq_at on the element with
     ;; a FREE position -- "which lists contain e" -- binding L from
     ;; content when the planner prefers that over scanning the atom
     (define mem-probe
       (if (set-member? atom-cseq-bound l0)
           (let ([pv (gensymb '$sqo)])
             (set-add! used-occ '$seq_at)
             (list `(syn ,p $seq_at ,ev ,pv ,l0)))
           '()))
     (values (append base ecl
                     (list onecl `(syn ,p = ,onev (syn ,p lmem ,l ,ev)))
                     mem-probe)
             base '())]

    ;; ---- general: floating runs between deterministic block splits ------
    [else
     (define block-live?*
       (for/list ([b (in-list blocks)]) (ormap splice-live? b)))
     ;; a run joins the enumerator when its content is checkable or a
     ;; neighboring block needs its position for a live slice
     (define needed?*
       (for/list ([r (in-list runs)] [i (in-naturals)])
         (or (ormap elem-live? r)
             (list-ref block-live?* i)
             (list-ref block-live?* (add1 i)))))
     (define n-needed (for/sum ([x (in-list needed?*)]) (if x 1 0)))
     (when (>= n-needed 2)
       (eprintf "warning: a bracket pattern floats ~a runs -- O(n^~a) enumerated placements per list; anchor or restructure if the relation is large (docs/sequences.md §4.2) in\n~a\n"
                n-needed n-needed (strip-prov rule)))

     ;; enumerator joins + run-element checks, one per needed run
     (define run-pos (make-vector (sub1 m) #f))   ; i -> (posv . endv)
     (define needed-js '())
     (define run-cls
       (for/fold ([acc '()]) ([r (in-list runs)] [i (in-naturals)]
                              #:when (list-ref needed?* i))
         (define j (list-ref run-js i))
         (set! needed-js (cons j needed-js))
         (define-values (cjv cjcl) (constv j))
         (define posv (gensymb '$sqp))
         (define endv (gensymb '$sqp))              ; pos + j
         (vector-set! run-pos i (cons posv endv))
         (define elem-cls
           (for/fold ([acc2 '()]) ([it (in-list r)] [k (in-naturals)]
                                   #:when (elem-live? it))
             (define-values (ckv ckcl) (constv k))
             (define pkv (gensymb '$sqp))
             (append acc2
                     (list ckcl `(syn ,p = ,pkv (syn ,p + ,posv ,ckv)))
                     (lref-clause it pkv))))
         (append acc
                 (list cjcl
                       `(syn ,p $seq_pos ,l ,cjv ,posv)
                       `(syn ,p = ,endv (syn ,p + ,posv ,cjv)))
                 elem-cls
                 (run-occurrence-assist p l0 r posv rule rels
                                        atom-cseq-bound used-occ bound0))))

     ;; left-to-right placement order: chain <=-guards between consecutive
     ;; needed runs; skipped runs and the fixed prefix/suffix ride as
     ;; constant slack
     (define order-cls
       (let loop ([i 0] [prev #f] [slack (length pre)] [cls '()])
         (cond
           [(> i (- m 2))
            ;; close: the last enumerated run leaves room for the suffix
            (append cls
                    (if prev
                        (let-values ([(cv ccl)
                                      (constv (+ slack (length post)))])
                          (define limv (gensymb '$sqp))
                          (list ccl
                                `(syn ,p = ,limv (syn ,p - ,nv ,cv))
                                `(syn ,p <= ,prev ,limv)))
                        '()))]
           [(not (list-ref needed?* i))
            (loop (add1 i) prev (+ slack (list-ref run-js i)) cls)]
           [else
            (match-define (cons posv endv) (vector-ref run-pos i))
            (define lb-cls
              (cond
                [prev
                 (if (zero? slack)
                     (list `(syn ,p <= ,prev ,posv))
                     (let-values ([(cv ccl) (constv slack)])
                       (define lbv (gensymb '$sqp))
                       (list ccl
                             `(syn ,p = ,lbv (syn ,p + ,prev ,cv))
                             `(syn ,p <= ,lbv ,posv))))]
                [(zero? slack) '()]   ; $seq_pos already gives pos >= 0
                [else (let-values ([(cv ccl) (constv slack)])
                        (list ccl `(syn ,p >= ,posv ,cv)))]))
            (loop (add1 i) endv 0 (append cls lb-cls))])))

     ;; deterministic block splits (live blocks only; a live block's
     ;; neighboring runs are needed by construction, so their position
     ;; vars exist)
     (define split-cls
       (for/fold ([acc '()]) ([blk (in-list blocks)] [i (in-naturals)]
                              #:when (list-ref block-live?* i))
         (define k (length blk))
         (define-values (lov lo-cls)
           (if (zero? i)
               (let-values ([(cv ccl) (constv (length pre))])
                 (values cv (list ccl)))
               (values (cdr (vector-ref run-pos (sub1 i))) '())))
         (define-values (hiv hi-cls)
           (if (= i (sub1 m))
               (let-values ([(cv ccl) (constv (length post))])
                 (define hv (gensymb '$sqp))
                 (values hv (list ccl `(syn ,p = ,hv (syn ,p - ,nv ,cv)))))
               (values (car (vector-ref run-pos i)) '())))
         (define live?s (map splice-live? blk))
         ;; boundary c (1..k-1) is materialized only when an adjacent
         ;; slice is live
         (define boundary?*
           (for/list ([c (in-range 1 k)])
             (or (list-ref live?s (sub1 c)) (list-ref live?s c))))
         (define bvars (make-vector (add1 k) #f))
         (vector-set! bvars 0 lov)
         (vector-set! bvars k hiv)
         (define midv (gensymb '$sqm))
         (define-values (ckv ckcl) (constv k))
         (define-values (km1v km1cl) (constv (sub1 k)))
         (define mid-cls
           (if (ormap values boundary?*)
               (list `(syn ,p = ,midv (syn ,p - ,hiv ,lov)) ckcl km1cl)
               '()))
         (define b-cls
           (for/fold ([acc2 '()]) ([c (in-range 1 k)]
                                   #:when (list-ref boundary?* (sub1 c)))
             (define-values (ccv cccl) (constv c))
             (define t1 (gensymb '$sqm))
             (define t2 (gensymb '$sqm))
             (define t3 (gensymb '$sqm))
             (define bv (gensymb '$sqp))
             (vector-set! bvars c bv)
             (append acc2
                     (list cccl
                           `(syn ,p = ,t1 (syn ,p * ,ccv ,midv))
                           `(syn ,p = ,t2 (syn ,p + ,t1 ,km1v))
                           `(syn ,p = ,t3 (syn ,p / ,t2 ,ckv))
                           `(syn ,p = ,bv (syn ,p + ,lov ,t3))))))
         (define slice-cls
           (for/fold ([acc2 '()]) ([it (in-list blk)] [c (in-naturals)]
                                   #:when (splice-live? it))
             (append acc2
                     (list `(syn ,p = ,(item-var it)
                                 (syn ,p lslice ,l ,(vector-ref bvars c)
                                      ,(vector-ref bvars (add1 c))))))))
         (append acc lo-cls hi-cls mid-cls b-cls slice-cls)))

     (values (append base run-cls order-cls split-cls (assist))
             base
             (reverse needed-js))]))

;; -----------------------------------------------------------------------
;; The inverted-join assist (§5.3): a redundant occurrence join on a GROUND
;; anchor, giving the planner the choice to bind the list from its content.
;; Emitted only when the list is bound by a persisted cseq atom column
;; (occurrence completeness holds for exactly those lists).

(define (occurrence-assist p l items rule rels atom-cseq-bound used-occ
                            bound0)
  (define splice-idxs
    (for/list ([it (in-list items)] [i (in-naturals)]
               #:when (match it [`(splice ,_) #t] [_ #f]))
      i))
  (define first-splice (if (null? splice-idxs) (length items)
                           (first splice-idxs)))
  (define last-splice (if (null? splice-idxs) -1 (last splice-idxs)))
  ;; an item qualifies as an anchor VALUE when it is a constant or a
  ;; variable some other body clause binds (the probe is then selective
  ;; regardless of which side the planner schedules first)
  (define (anchor-val it)
    (match it
      [`(elemc ,v) (cons 'const v)]
      [`(elem ,x)
       (and (not (dead-var? x)) (set-member? bound0 x) (cons 'var x))]
      [_ #f]))
  ;; ALL fixed-position anchors, prefix + suffix side (§5.4: multi-element
  ;; anchors = multiple probes joined on the list)
  (define anchors
    (append
     (for/list ([it (in-list items)] [i (in-naturals)]
                #:when (and (< i first-splice) (anchor-val it)))
       (list '$seq_at (anchor-val it) i))
     (for/list ([it (in-list items)] [i (in-naturals)]
                #:when (and (> i last-splice) (anchor-val it)))
       ;; 0-based position from the END
       (list '$seq_atr (anchor-val it) (- (length items) 1 i)))))
  (cond
    [(not (set-member? atom-cseq-bound l)) '()]
    [else
     (for/fold ([acc '()]) ([a (in-list anchors)])
       (match-define (list occ val pos) a)
       (set-add! used-occ occ)
       (define pv (gensymb '$sqo))
       (define val-cls+var
         (match val
           [(cons 'const v)
            (define vv (gensymb '$sqo))
            (cons (list `(syn ,p = ,vv (syn ,p const ,v))) vv)]
           [(cons 'var x) (cons '() x)]))
       (append acc
               (car val-cls+var)
               (list `(syn ,p = ,pv (syn ,p const ,pos))
                     `(syn ,p ,occ ,(cdr val-cls+var) ,pv ,l))))]))

;; Floating-run occurrence probes (§5.4 row 4): a ground/bound element at
;; run offset k probes $seq_at, and `(= pos (- pk k))` ties the probe's
;; position back to the enumerator's run start -- schedulable either way:
;; probe-first derives pos (the $seq_pos join then validates it), or
;; enumerator-first makes the compute a ==-check against the probe.
(define (run-occurrence-assist p l run posv rule rels atom-cseq-bound
                               used-occ bound0)
  (define (anchor-val it)
    (match it
      [`(elemc ,v) (cons 'const v)]
      [`(elem ,x)
       (and (not (dead-var? x)) (set-member? bound0 x) (cons 'var x))]
      [_ #f]))
  (cond
    [(not (set-member? atom-cseq-bound l)) '()]
    [else
     (for/fold ([acc '()]) ([it (in-list run)] [k (in-naturals)]
                            #:when (anchor-val it))
       (define val (anchor-val it))
       (set-add! used-occ '$seq_at)
       (define pkv (gensymb '$sqo))
       (define ckv (gensymb '$sqc))
       (define val-cls+var
         (match val
           [(cons 'const v)
            (define vv (gensymb '$sqo))
            (cons (list `(syn ,p = ,vv (syn ,p const ,v))) vv)]
           [(cons 'var x) (cons '() x)]))
       (append acc
               (car val-cls+var)
               (list `(syn ,p ,'$seq_at ,(cdr val-cls+var) ,pkv ,l)
                     `(syn ,p = ,ckv (syn ,p const ,k))
                     `(syn ,p = ,posv (syn ,p - ,pkv ,ckv)))))]))
