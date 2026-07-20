#lang racket

;; Operationalization: lower one stratum's planned rules to the c-program
;; (see ir-stack.rkt) that emit-cpp.rkt renders as C++.
;;
;; Four logical stages:
;;   1. globalize constants -- each distinct literal becomes one global
;;      variable, initialized once at program load;
;;   2. collect select sets -- for every join, the set of columns it probes
;;      with (against the delta index for drivers, the full index otherwise);
;;   3. choose indices -- greedily pack subset-related select sets into
;;      prefix chains, then assemble one deterministic ordering per chain;
;;   4. lower each rule -- resolve every join to a concrete index, reorder
;;      its tuple to match, and split the body into pre-ops / driver / ops.
;;
;; Variables and primitive names are C-escaped here, in one place; relation
;; names stay raw (they only appear inside C string literals downstream).

(provide build-cprog
         semijoin-filters)   ; exported for tests/unit/semijoin-tests.rkt

(require "utils.rkt")
(require "params.rkt")
(require "ir-shared.rkt")
(require "join-actions.rkt")
(require "primitives.rkt")    ; prim-partial? (letp lowering)
(require "type-system.rkt")   ; rule-has-fallible-prims?, prim-error-arms
(require sha)                 ; content-derived constant global names (P2)

;; The rule's "basename:line" (1-based), baked into any runtime-error
;; (error_spec ...) it reports.  Mirrors compile.rkt's rule-location; basename
;; (not absolute path) so error facts don't vary with the checkout location.
(define (rule-loc-string rule)
  (match rule
    [`(syn (prov (token ,_ (pos ,file ,line ,_ ...) ,_) ,_ ...) ,_ ...)
     (define p (file-name-from-path (format "~a" file)))
     (format "~a:~a" (if p (path->string p) file) (add1 line))]
    [_ "<unknown>"]))

;; -----------------------------------------------------------------------
;; Clause views shared by the steps below.

(define (join-cl? cl)
  (and (not (expand3-action? cl))
       (match cl
         [`(syn ,_ ,(or '/= '== 'let 'tycheck) ,_ ...) #f]
         ;; ~ and the M4N view-retagged ~old/~new (neg-symbol?)
         [`(syn ,_ ,(? neg-symbol?) ,_ ...) #f]
         [`(syn ,_ ,(? primitive-cmp?) ,_ ,_) #f]
         [_ #t])))

(define (join-entry? entry)
  (or (join-cl? entry) (expand3-action? entry)))

(define (join-entry-width entry)
  (if (expand3-action? entry) 2 1))

;; A residual type check in head position (type-system.rkt).
(define (tycheck-cl? cl)
  (match cl
    [`(syn ,_ tycheck ,_ ...) #t]
    [_ #f]))

(define (join-rel cl)
  (match cl
    [`(syn ,_ = ,_ (syn ,_ ,name ,_ ...)) name]
    [`(syn ,_ ,name ,_ ...) name]))

;; The join's tuple in storage order (a struct's id is storage column 0).
(define (join-tuple cl)
  (match cl
    [`(syn ,_ = ,x (syn ,_ ,name ,xs ...)) (cons x xs)]
    [`(syn ,_ ,name ,xs ...) xs]))

;; A `seeded-rule` is a staged rule's SEEDED RE-ENTRY version (the
;; staging-replay bug, docs/db-compression.md): identical semantics, but
;; every join probes FULL indices (no delta anywhere) and the generated
;; task registers via addTaskSeeded -- the daemon runs it each iteration
;; only when the stratum starts over externally seeded content (an
;; open/import preceded), restoring semi-naive completeness exactly where
;; staging's pruned delta variants lose it.
(define (seeded-rule? rule)
  (match rule [`(syn ,_ seeded-rule ,_ ...) #t] [_ #f]))

(define (rule-body rule)
  (match rule
    [`(syn ,_ ,(or 'rule 'seeded-rule) ,bodys ... --> ,heads ...) bodys]))

(define (rule-heads rule)
  (match rule
    [`(syn ,_ ,(or 'rule 'seeded-rule) ,bodys ... --> ,heads ...) heads]))

;; The planner marks a dynamic body join ORDERED AFTER the delta driver (in the
;; rule's fixed dynamic-clause order) with $oldjoin: exact semi-naive must probe
;; it against R_old = FULL - current delta, not FULL, or an assignment whose
;; premises are all new this round double-fires (docs/incremental.md §6/§8).
;; Recover those positions (0-based over body JOIN clauses; the driver is 0 and
;; is never marked) and strip the wrappers so the rest of the pass sees plain
;; clauses.  $tombjoin marks the M4S struct RESOLUTION join (probe live
;; master then the tombstone dictionary -- docs/m4s-contract.md).  Returns
;; (values plain-bodys old-positions new-positions tomb-positions).
(define (split-exact-marks bodys)
  (let loop ([cls bodys] [out '()] [jpos 0] [olds (set)] [news (set)]
             [tombs (set)])
    (cond
      [(null? cls) (values (reverse out) olds news tombs)]
      [else
       (match (car cls)
         [`(syn ,_ $oldjoin ,inner)
          (loop (cdr cls) (cons inner out) (add1 jpos)
                (set-add olds jpos) news tombs)]
         [`(syn ,_ $newjoin ,inner)
          (loop (cdr cls) (cons inner out) (add1 jpos)
                olds (set-add news jpos) tombs)]
         [`(syn ,_ $tombjoin ,inner)
          (loop (cdr cls) (cons inner out) (add1 jpos)
                olds news (set-add tombs jpos))]
         [cl
          (loop (cdr cls) (cons cl out)
                (if (join-entry? cl) (+ jpos (join-entry-width cl)) jpos)
                olds news tombs)])])))

;; -----------------------------------------------------------------------
;; The pass driver.
;;
;; planned-rules  set of planned rules (one stratum)
;; rel-env        relation declarations, including this stratum's temps
;; decomp-env     M2.4 decomposition registry: derived -> (base set|map)
;;
;; Returns a cprog.  The dynamic-relation set (heads of this stratum's
;; rules) determines which read tasks re-run every iteration versus once.

(define (build-cprog planned-rules rel-env [decomp-env (hash)])
  (define rules0 (set->list planned-rules))
  (match-define (cons constants rules) (globalize-constants rules0))
  ;; residual checks grow malformed_deduction through their failure path,
  ;; so it counts as a head relation for scheduling purposes
  (define head-dynamic-rels
    (for/fold ([acc (set)]) ([rule (in-list rules)])
      (define heads (rule-heads rule))
      (set-union acc
                 (list->set (map join-rel (filter join-cl? heads)))
                 (if (ormap tycheck-cl? heads)
                     (set 'malformed_deduction)
                     (set))
                 ;; runtime-error arms are grown through a fallible prim's
                 ;; side channel (emit_pending_error), not as rule heads, so
                 ;; -- like malformed_deduction -- they must be marked dynamic
                 ;; for the injected wrap rules (arm -> error) to see the delta.
                 (if (rule-has-fallible-prims? rule)
                     (list->set prim-error-arms)
                     (set)))))
  ;; a decomposed relation's derived facts (R_has/R_at) are grown through the
  ;; base's merge tasks, not as rule heads -- and in EVERY stratum: the master
  ;; (once) MapWriteTask re-derives them from the reloaded content at
  ;; iteration 0, landing them in iteration 1's delta, so rules they drive
  ;; must re-run each iteration even where the base is closed (a static
  ;; reader would miss the freshly-seeded rows; compile.rkt has the story)
  (define dynamic-rels
    (for/fold ([acc head-dynamic-rels]) ([(derived _info) (in-hash decomp-env)])
      (set-add acc derived)))
  (define needs
    (foldl (add-select-sets rel-env) (seed-selection-needs rel-env) rules))
  (define indices (choose-indices rel-env needs))
  ;; (decls are built AFTER rule lowering: which orderings are seeded-only
  ;; is decided from the indices crules actually reference)
  ;; extern oracle bindings (docs/smt.md): a stratum whose rules write the
  ;; demand struct gets the daemon-side dispatch/harvest registration,
  ;; emitted AFTER every relation decl so bindOracle's lookups succeed
  ;; The _count flavor registers NO oracle bindings (§8B.4: answers are
  ;; monotone memo-inputs -- the count round must never re-query a solver;
  ;; the demand structs themselves count as ordinary struct heads) and no
  ;; sequence-occurrence feeding (§8B.4: value-keyed side tables are never
  ;; counted, and their rows are already published in the resident db).
  (define oracle-decls
    (if (count-flavor)
        '()
        (sort (for/list ([(k decl) (in-hash rel-env)]
                         #:when (and (pair? decl) (eq? 'oracle (car decl))
                                     (set-member? head-dynamic-rels (third decl))))
                `(oracle ,(second decl) ,(third decl) ,(fourth decl)))
              symbol<? #:key third)))
  ;; the bound answer tables grow via the oracle's harvest side channel (no
  ;; rule head), so mark them dynamic -- mirrors the pre-planning extension
  ;; in compile.rkt (the planner already staged rules accordingly); this set
  ;; drives the static?-task flags and the stratum's addDynamicRel metadata.
  ;; smt_bad_formula grows via the dispatcher's side channel likewise.
  (define dynamic-rels+
    (for/fold ([acc dynamic-rels]) ([d (in-list oracle-decls)])
      (set-add (set-add acc (fourth d)) 'smt_bad_formula)))
  ;; sequence-occurrence feeding (docs/sequences.md §5.3): when seq-expand
  ;; declared the occurrence relations, every table/struct with a
  ;; cseq-resolving column gets a SeqIndexTask registration (D6: type-based,
  ;; program-wide), emitted after all relation decls so getRelation lookups
  ;; succeed.  The occurrence relations grow via that task's side channel
  ;; (no rule head), so they are dynamic exactly like decomp targets.
  (define seq-occ-present
    (filter (lambda (n) (hash-has-key? rel-env n)) '($seq_at $seq_atr)))
  (define seq-decls
    (if (or (null? seq-occ-present) (count-flavor))
        '()
        (for/fold ([acc '()] #:result (reverse acc))
                  ([name (in-list (sort (hash-keys rel-env) symbol<?))])
          (define (cseq-col? t)
            (and (symbol? t) (eq? 'cseq (lattice-base-type rel-env t))))
          (match (hash-ref rel-env name)
            [`(table ,ts ...)
             #:when (and (not (memq name '($seq_at $seq_atr
                                           $seq_posdem $seq_pos)))
                         (not (rel-lattice-spec rel-env name))
                         (ormap cseq-col? ts))
             (cons `(seqindex ,name
                              ,(for/list ([t (in-list ts)] [i (in-naturals)]
                                          #:when (cseq-col? t))
                                 i))
                   acc)]
            [`(struct ,ts ...)
             #:when (ormap cseq-col? ts)
             ;; storage column 0 is the id; fields are 1..n
             (cons `(seqindex ,name
                              ,(for/list ([t (in-list ts)] [i (in-naturals)]
                                          #:when (cseq-col? t))
                                 (add1 i)))
                   acc)]
            [_ acc]))))
  (define dynamic-rels++
    (for/fold ([acc dynamic-rels+]) ([occ (in-list seq-occ-present)])
      (set-add acc occ)))
  ;; Lower each rule with its source location attached to any failure (an
  ;; unbound variable otherwise dies deep in lowering as a locationless
  ;; `hash-ref: no value found`; docs/build-issues-notes.md §5).
  (define lower-one (lower-rule rel-env indices))
  (define crules
    (for/list ([rule (in-list rules)])
      (with-rule-context rule (lambda () (lower-one rule)))))
  ;; Gate an ordering's WriteTask behind addTaskSeeded only if EVERY
  ;; reference to it comes from a seeded re-entry crule.  Attribution must
  ;; happen POST-lowering: several select sets can share one packed ordering,
  ;; so selection-level attribution could gate an index that a live rule also
  ;; probes (empty in fresh runs: silent under-derivation).  Delta indices are
  ;; never gated.
  (define seeded-used
    (for*/set ([cr (in-list crules)]
               #:when (equal? (third cr) `(seeded))          ; crule-driver
               [ref (in-list (crule-index-refs cr))])
      ref))
  (define live-used
    (for*/set ([cr (in-list crules)]
               #:unless (equal? (third cr) `(seeded))        ; crule-driver
               [ref (in-list (crule-index-refs cr))])
      ref))
  ;; In the _count flavor the seeded PLAN SHAPE is reused for the fire-once
  ;; all-full rules (join-planning), so their orderings are LIVE indices --
  ;; registered normally and backfilled from resident content (database.h
  ;; addIndex); nothing is gated seeded-only.
  (define gate-inds
    (if (count-flavor) (set) (set-subtract seeded-used live-used)))
  (define decls (make-rel-decls rel-env indices decomp-env gate-inds))
  `(cprog ,dynamic-rels++ ,constants ,(append decls oracle-decls seq-decls)
          ,crules))

;; every full-index ordering a crule's ops reference, as (name . ordering)
(define (crule-index-refs cr)
  (define (op-refs op)
    (match op
      [`(join ,name ,ind ,_ ,_ ...) (list (cons name ind))]
      [`(join-tomb ,name ,ind ,_ ,_ ...) (list (cons name ind))]
      ;; join-old's FULL index (the delta index it also references is never
      ;; seeded-gated); record it so a live old-join keeps its full ordering
      [`(,(or 'join-old 'join-new) ,name ,ind ,_ ,_ ,_ ...)
       (list (cons name ind))]
      [`(join3 ,_ ,arms ...)
       (for/list ([arm (in-list arms)])
         (cons (second arm) (third arm)))]
      [`(join-lat ,name ,ind ,_ ,_ ...) (list (cons name ind))]
      [`(exists ,name ,ind ,_ ,_ ...) (list (cons name ind))]
      [`(absent ,name ,ind ,_ ,_ ...) (list (cons name ind))]
      [`(,(or 'absent-old 'absent-new) ,name ,ind ,_ ,_ ,_ ...)
       (list (cons name ind))]
      [`(absent-lat ,name ,ind ,_ ,_ ...) (list (cons name ind))]
      [`(mkstruct ,name ,ind ,_ ,_ ...) (list (cons name ind))]
      [`(emit ,name ,ind ,_ ...) (list (cons name ind))]
      [`(tycheck ,_ ,_ ,_ ,_ ,_ ,ind) (list (cons 'malformed_deduction ind))]
      [_ '()]))
  ;; positional crule accessors (ir-stack.rkt owns the named ones; requiring
  ;; it here would be a cycle): (crule (pre ...) driver (body ...) (head ...) loc)
  (append (append-map op-refs (cdr (second cr)))
          (append-map op-refs (cdr (fourth cr)))
          (append-map op-refs (cdr (fifth cr)))))

;; -----------------------------------------------------------------------
;; 1. Constants.
;;
;; Rewrite every (let x (const v)) to (let x g), collecting v -> g.  The
;; generated code declares each g as a global and initializes it at load
;; time (interning strings, NaN-boxing numbers).

;; Content-derived global name for an interned constant VALUE.  Was
;; (gensymb 'const), which varied run to run and made the file-scope v_<name>
;; symbol -- the cross-TU interface a .o exports/imports -- non-reproducible,
;; blocking per-cluster .o caching (docs/fast-compile.md P2).  A 24-hex sha256 of
;; the value's printed form: same value -> same name (the v->g map still dedups
;; within a program), distinct values -> distinct name w.h.p.  All-alphanumeric
;; after the `const` prefix (escape-id-for-C doubles `_`, so we avoid it).
(define (const-global-name v)
  (string->symbol
   (string-append
    "const"
    (substring (bytes->hex-string (sha256 (string->bytes/utf-8 (format "~s" v)))) 0 24))))

(define (globalize-constants rules)
  (for/fold ([acc (cons (hash) '())]
             #:result (cons (car acc) (reverse (cdr acc))))
            ([rule (in-list rules)])
    (match-define (cons constants rules+) acc)
    (match-define `(syn ,prov ,(and tag (or 'rule 'seeded-rule)) ,cls ...) rule)
    (define-values (constants+ cls+)
      (for/fold ([constants constants] [out '()]
                 #:result (values constants (reverse out)))
                ([cl (in-list cls)])
        (match cl
          [`(syn ,p let ,x (syn ,_ const ,v))
           (define g (hash-ref constants v (lambda () (const-global-name v))))
           (values (hash-set constants v g)
                   (cons `(syn ,p let ,x ,g) out))]
          [_ (values constants (cons cl out))])))
    (cons constants+ (cons `(syn ,prov ,tag ,@cls+) rules+))))

;; -----------------------------------------------------------------------
;; Semijoin filters (Yannakakis-style lookahead pruning).
;;
;; Before an EXPANDING join (one that binds at least one fresh variable),
;; a partial tuple that cannot satisfy some future clause of the schedule
;; is dead weight: every match the join produces from it will be discarded
;; when that clause finally runs.  So, just before each expanding join, we
;; place an existence probe against each future clause's relation on the
;; columns already bound -- pruning BEFORE the fan-out instead of after.
;; This is the pipelined form of a semijoin reducer: it cannot beat a
;; worst-case optimal join on dense cyclic queries (nothing prunes a
;; bipartite triangle query), but it collapses the common pathologies --
;; star joins where a later clause is selective, and recursive rules whose
;; delta drives into a fan-out that a later clause mostly rejects.
;;
;; Sound under semi-naive evaluation: the probe reads the same full-index
;; snapshot the future join itself reads this iteration, so a pruned tuple
;; could never have joined NOW; combinations enabled by later growth of the
;; future relation re-arrive through that relation's own delta-driven rule
;; version, exactly as they would without filters.
;;
;; Conservative by construction:
;;   - only fires before a join that binds fresh variables, so there is
;;     always fan-out between the check and the clause it guards (a rule
;;     with two joins gets no filters at all);
;;   - re-checks a future clause only when its bound-column set has GROWN
;;     since the last check placed for it;
;;   - identical probes at the same point are deduplicated;
;;   - lattice and temp relations are skipped (payload maps and index-free
;;     temps have no set index to probe), as is a struct probed only on its
;;     id column (an interned id is present by construction).
;;
;; Returns a hash from join position (0 = driver, counting join clauses in
;; schedule order) to the filters to run immediately before that join, each
;; a (list name sel tuple): the future clause's relation, bound storage
;; columns, and full tuple (the lowering picks the key vars out of it).
;; Each filter's sel is also a select set (add-select-sets), so the index
;; it probes is requisitioned like any join's.

(define (semijoin-filters bodys rel-env)
  (define (skip-rel? name)
    (match (hash-ref rel-env name #f)
      [#f #t]
      [`(temp ,_) #t]
      [_ (and (rel-lattice-spec rel-env name) #t)]))
  (define (struct-rel? name)
    (match (hash-ref rel-env name #f)
      [`(struct ,_ ...) #t]
      [_ #f]))
  (define joins
    (list->vector
     (append-map
      (lambda (entry)
        (cond
          [(join-cl? entry) (list entry)]
          [(expand3-action? entry)
           (map access-clause (action-accesses entry))]
          [else '()]))
      bodys)))
  (define n (vector-length joins))
  (cond
    [(or (not (semijoin-filters-enabled)) (< n 3)) (hash)]
    [else
     (define last-sel (make-hash))   ; future join index -> sel last checked
     ;; existence checks worth placing just before join `jpos` fires
     (define (filters-at first-future ground)
       (for/fold ([out '()] [seen (set)] #:result (reverse out))
                 ([m (in-range first-future n)])
         (define fut (vector-ref joins m))
         (define name (join-rel fut))
         (define tup (join-tuple fut))
         (define sel
           (for/set ([x (in-list tup)] [i (in-naturals)]
                     #:when (set-member? ground x))
             i))
         (define probe-key           ; identity of the runtime check itself
           (cons name (for/list ([x (in-list tup)] [i (in-naturals)]
                                 #:when (set-member? ground x))
                        (cons i x))))
         (cond
           [(or (skip-rel? name)
                (set-empty? sel)
                (and (struct-rel? name) (equal? sel (set 0)))
                (equal? (hash-ref last-sel m (set)) sel))
            (values out seen)]
           [(set-member? seen probe-key)          ; same check already placed
            (hash-set! last-sel m sel)            ; here for another clause
            (values out seen)]
           [else
            (hash-set! last-sel m sel)
            (values (cons (list name sel tup) out)
                    (set-add seen probe-key))])))
     (for/fold ([ground (set)] [jpos 0] [acc (hash)] #:result acc)
               ([cl (in-list bodys)])
       (cond
         [(join-cl? cl)
          (define expanding? (not (subset? (clause-vars cl) ground)))
          (define acc+
            (if (and (> jpos 0) expanding?)
                (match (filters-at (add1 jpos) ground)
                  ['() acc]
                  [fs (hash-set acc jpos fs)])
                acc))
          (values (set-union ground (clause-vars cl)) (add1 jpos) acc+)]
         [(expand3-action? cl)
          (define acc+
            (match (filters-at (+ jpos 2) ground)
              ['() acc]
              [fs (hash-set acc jpos fs)]))
          (values (set-add ground (expand3-action-cycle cl))
                  (+ jpos 2) acc+)]
         [else
          (values (set-union ground (clause-out-vars cl)) jpos acc)]))]))

;; -----------------------------------------------------------------------
;; 2. Select sets: relation (or (delta relation)) -> set of column sets.

;; same-order maps relation -> select sets constrained by exact semi-naive
;; joins.  Their full and delta probes must use the identical complete tuple
;; ordering so the runtime can test full-index matches directly in delta.
(struct selection-needs (by-key same-order) #:transparent)

;; Every struct needs its interning master index (content columns first, the
;; id column -- storage 0 -- last) and its lookup index (id first); every
;; table needs at least one index to exist in (and be reloadable from).
(define (seed-selection-needs rel-env)
  (selection-needs
   (for/fold ([ss (hash)]) ([(name decl) (in-hash rel-env)])
     (match decl
       [`(struct ,ts ...)
        (hash-set ss name (set (list->set (range 1 (add1 (length ts))))
                               (set 0)))]
       [`(table ,ts ...) (hash-set ss name (set (set)))]
       [_ ss]))                                   ; temps and enums: none
   (hash)))

(define (add-select-set needs key columns)
  (struct-copy selection-needs needs
               [by-key (hash-update (selection-needs-by-key needs) key
                                    (lambda (s) (set-add s columns))
                                    (set))]))

(define (add-same-order-selection needs name columns)
  (struct-copy selection-needs
               (add-select-set (add-select-set needs name columns)
                               `(delta ,name) columns)
               [same-order
                (hash-update (selection-needs-same-order needs) name
                             (lambda (sels) (set-add sels columns))
                             (set))]))

;; Walk one rule's body in schedule order, recording each join's probe
;; columns.  The first join is the driver: a probing driver hits the DELTA
;; index of its relation; a driver with no bound columns scans the raw delta
;; and needs no index at all.  Semijoin filters placed before a join probe
;; the full index of THEIR relation on the filter's bound columns, so each
;; filter contributes a select set of its own -- this is where the extra
;; indices the filters need get requisitioned.
;;
;; A lattice relation's non-driver joins never select on the value column
;; (the payload is bound by the map probe, not by an index prefix): in-SCC
;; the calculus guarantees the value variable is unground, and cross-stratum
;; a ground value becomes an equality check after the probe (lower-join).
;; Delta indices are ordinary full-width sets, so drivers are unrestricted.
(define ((add-select-sets rel-env) rule needs)
  (define-values (bodys old-positions new-positions tomb-positions)
    (split-exact-marks (rule-body rule)))
  (define sj-filters (semijoin-filters bodys rel-env))
  ;; a seeded-rule has NO delta driver: its first join selects on the FULL
  ;; index like any other
  (define seeded? (seeded-rule? rule))
  (for/fold ([ground (set)] [jpos 0] [needs needs] #:result needs)
            ([cl (in-list bodys)])
    (cond
      [(expand3-action? cl)
       (define needs0
         (for/fold ([n needs]) ([f (in-list (hash-ref sj-filters jpos '()))])
           (add-select-set n (first f) (second f))))
       (define needs+
         (for/fold ([n needs0]) ([access (in-list (action-accesses cl))])
           (define tup (access-tuple access))
           (define sel
             (for/set ([x (in-list tup)] [i (in-naturals)]
                       #:when (set-member? ground x))
               i))
           (define cycle (expand3-action-cycle cl))
           (define cycle-pos (index-of tup cycle))
           (unless (and cycle-pos
                        (= (set-count sel) (sub1 (length tup)))
                        (not (set-member? sel cycle-pos)))
             (error 'operationalization
                    "invalid key-simple Expand3 access ~a at ground frontier ~a"
                    access ground))
           (if (memq (join-access-view access) '(old new))
               (add-same-order-selection n (access-rel access) sel)
               (add-select-set n (access-rel access) sel))))
       (values (set-add ground (expand3-action-cycle cl))
               (+ jpos 2) needs+)]
      [(join-cl? cl)
       (define first? (and (= jpos 0) (not seeded?)))
       (define tup (join-tuple cl))
       (define lat-value-pos
         (and (rel-lattice-spec rel-env (join-rel cl)) (sub1 (length tup))))
       (define sel
         (for/set ([x (in-list tup)] [i (in-naturals)]
                   #:when (set-member? ground x))
           i))
       (define needs0
         (for/fold ([needs needs]) ([f (in-list (hash-ref sj-filters jpos '()))])
           (add-select-set needs (first f) (second f))))
       (define selv (if lat-value-pos (set-remove sel lat-value-pos) sel))
       (define needs+
         (cond
           [(and first? (set-empty? sel)) needs0]                ; delta scan
           [first? (add-select-set needs0 `(delta ,(join-rel cl)) sel)]
           [else
            ;; An exact old/new join additionally needs a delta index with the
            ;; SAME complete ordering as its full index.
            (if (or (set-member? old-positions jpos)
                    (set-member? new-positions jpos))
                (add-same-order-selection needs0 (join-rel cl) selv)
                (add-select-set needs0 (join-rel cl) selv))]))
       (values (set-union ground (clause-vars cl)) (add1 jpos) needs+)]
      [else
       ;; a negated atom (§0.8) probes the negated relation's FULL index on
       ;; its bound (non-wildcard) columns -- requisition an index ordering
       ;; them first, exactly like a semijoin filter's.  For a lattice
       ;; relation the atom carries KEY columns only, and the value column
       ;; (highest, never selected) lands last: the payload-map layout.
       (define needs+
         (if (neg-clause? cl)
             ;; A view-marked absence (M4N ~old/~new) additionally needs a
             ;; delta index with the SAME complete ordering as its full
             ;; index, exactly like an exact old/new join.
             ((if (neg-view cl) add-same-order-selection add-select-set)
              needs (neg-rel cl)
              (for/set ([x (in-list (neg-args cl))]
                        [i (in-naturals)]
                        #:unless (neg-wildcard-var? x))
                i))
             needs))
       (values (set-union ground (clause-out-vars cl)) jpos needs+)])))

;; -----------------------------------------------------------------------
;; 3. Indices: greedy prefix-chain packing.
;;
;; A lexicographic index covers every select set equal to the set of its
;; first K columns.  Consequently, one ordering covers a chain
;;   S0 ⊂ S1 ⊂ ... ⊂ Sn
;; by placing S0 first, then each successive set difference, then the
;; unselected columns.  We greedily build those chains largest-to-smallest:
;; put a selection below the tightest chain minimum that contains it, or
;; start a new chain.  This deterministic heuristic favors predictable compile
;; time while eliminating the common one-index-per-selection redundancy.

(struct index-plan (orderings assignments) #:transparent)

(define (lexicographic<? xs ys)
  (cond
    [(null? xs) (pair? ys)]
    [(null? ys) #f]
    [(< (car xs) (car ys)) #t]
    [(> (car xs) (car ys)) #f]
    [else (lexicographic<? (cdr xs) (cdr ys))]))

(define (selection-columns sel)
  (sort (set->list sel) <))

;; Largest selections first; numeric column order breaks equal-size ties.
(define (selection-larger<? a b)
  (cond
    [(> (set-count a) (set-count b)) #t]
    [(< (set-count a) (set-count b)) #f]
    [else (lexicographic<? (selection-columns a) (selection-columns b))]))

;; Prefer the smallest compatible chain minimum (best fit), then its column
;; order.  `chain` is stored largest-to-smallest, so its minimum is last.
(define (chain-tighter<? a b)
  (define amin (last a))
  (define bmin (last b))
  (cond
    [(< (set-count amin) (set-count bmin)) #t]
    [(> (set-count amin) (set-count bmin)) #f]
    [else (lexicographic<? (selection-columns amin)
                           (selection-columns bmin))]))

(define (assemble-index chain arity)
  (define all-columns (list->set (range arity)))
  (define-values (prefix seen)
    (for/fold ([prefix '()] [seen (set)])
              ([sel (in-list (reverse chain))])
      (define fresh (sort (set->list (set-subtract sel seen)) <))
      (values (append prefix fresh) (set-union seen sel))))
  (append prefix (sort (set->list (set-subtract all-columns seen)) <)))

;; Pack selections that are not already served by a fixed ordering.  Returns
;; both the distinct orderings and the exact selection -> ordering assignment.
(define (pack-unfixed-selections selections arity)
  (define chains
    (for/fold ([chains '()])
              ([sel (in-list (sort (set->list selections)
                                   selection-larger<?))])
      (define compatible
        (filter (lambda (chain)
                  (define minimum (last chain))
                  (and (< (set-count sel) (set-count minimum))
                       (subset? sel minimum)))
                chains))
      (if (null? compatible)
          (cons (list sel) chains)
          (let ([best (first (sort compatible chain-tighter<?))])
            (cons (append best (list sel)) (remove best chains))))))
  (for/fold ([orderings (set)] [assignments (hash)])
            ([chain (in-list chains)])
    (define ordering (assemble-index chain arity))
    (values (set-add orderings ordering)
            (for/fold ([assignments assignments])
                      ([sel (in-list chain)])
              (hash-set assignments sel ordering)))))

(define (ordering-covers? ordering sel)
  (equal? (list->set (take ordering (set-count sel))) sel))

;; Fixed assignments are used only for exact semi-naive delta probes: their
;; complete ordering must equal the full index's ordering.  Other selections
;; first reuse any fixed ordering that already covers them, then the remainder
;; is greedily packed as usual.
(define (pack-selections selections arity [fixed (hash)])
  (for ([(sel ordering) (in-hash fixed)])
    (unless (and (set-member? selections sel)
                 (= (length ordering) arity)
                 (ordering-covers? ordering sel))
      (error 'operationalization
             "fixed index ~a does not cover selection ~a" ordering sel)))
  (define fixed-orderings (list->set (hash-values fixed)))
  (define assignments
    (for/fold ([assignments fixed])
              ([sel (in-list (sort (set->list selections)
                                   selection-larger<?))])
      (cond
        [(hash-has-key? assignments sel) assignments]
        [else
         (define candidates
           (sort (filter (lambda (ordering) (ordering-covers? ordering sel))
                         (set->list fixed-orderings))
                 lexicographic<?))
         (if (null? candidates)
             assignments
             (hash-set assignments sel (first candidates)))])))
  (define uncovered
    (for/set ([sel (in-set selections)]
              #:unless (hash-has-key? assignments sel))
      sel))
  (define-values (more-orderings more-assignments)
    (pack-unfixed-selections uncovered arity))
  (values (set-union fixed-orderings more-orderings)
          (for/fold ([assignments assignments])
                    ([(sel ordering) (in-hash more-assignments)])
            (hash-set assignments sel ordering))))

(define (greedy-index-orderings selections arity)
  (define-values (orderings _assignments)
    (pack-selections selections arity))
  orderings)

(module+ test-support
  (provide greedy-index-orderings))

(define (stored-arity-for-decl decl)
  (match decl
    [`(struct ,_ ...) (add1 (rel-decl-arity decl))]
    [_ (rel-decl-arity decl)]))

;; Build full plans first, then delta plans.  Exact old/new select sets pin
;; their delta assignment to the full assignment chosen by the greedy packer.
;;
;; A struct's full-content selection {1..n} is pinned to the CANONICAL master
;; ordering (1 2 ... n 0) in every flavor.  The master is the intern
;; dictionary's authority (dedup, tombstone keys, clear-to-tombstones,
;; count-mode probe-only mkstruct), shared across the flavors resident on one
;; relation; letting the greedy packer unify it with a permuted probe
;; selection (e.g. {2} chaining {1,2} into (2 1 0)) gives two flavors two
;; disjoint "masters", and whichever one a flavor never writes goes silently
;; stale -- discovered by the M4S diamond fixture as reminted ids after
;; clear-and-rerun and count-round "uninterned instance" fatals (the M4T
;; all-orderings lesson, this time between flavors).  Permuted content
;; probes still get their own SECONDARY orderings; only the {1..n}
;; assignment is fixed.
(define (canonical-struct-master rel-env name)
  (match (hash-ref rel-env name)
    [`(struct ,ts ...)
     (define stored (add1 (length ts)))
     (hash (list->set (range 1 stored))
           (append (range 1 stored) (list 0)))]
    [_ (hash)]))

(define (choose-indices rel-env needs)
  (define selections (selection-needs-by-key needs))
  (define orderings (make-hash))
  (define assignments (make-hash))
  (define names (sort (hash-keys rel-env) symbol<?))
  (for ([name (in-list names)])
    (define sels (hash-ref selections name (set)))
    (unless (set-empty? sels)
      (define arity (stored-arity-for-decl (hash-ref rel-env name)))
      (define-values (ords asns)
        (pack-selections sels arity (canonical-struct-master rel-env name)))
      (hash-set! orderings name ords)
      (hash-set! assignments name asns)))
  (for ([name (in-list names)])
    (define key `(delta ,name))
    (define sels (hash-ref selections key (set)))
    (unless (set-empty? sels)
      (define arity (stored-arity-for-decl (hash-ref rel-env name)))
      (define full-assignments (hash-ref assignments name (hash)))
      (define fixed
        (for/hash ([sel (in-set
                         (hash-ref (selection-needs-same-order needs)
                                   name (set)))])
          (values sel
                  (hash-ref full-assignments sel
                            (lambda ()
                              (error 'operationalization
                                     "exact selection ~a missing full index for ~a"
                                     sel name))))))
      (define-values (ords asns) (pack-selections sels arity fixed))
      (hash-set! orderings key ords)
      (hash-set! assignments key asns)))
  (index-plan
   (for/hash ([(key value) (in-hash orderings)]) (values key value))
   (for/hash ([(key value) (in-hash assignments)]) (values key value))))

(define (index-orderings-of plan key)
  (hash-ref (index-plan-orderings plan) key (set)))

;; -----------------------------------------------------------------------
;; 4. Relation declarations.

(define (make-rel-decls rel-env indices [decomp-env (hash)]
                        [gate-inds (set)])
  ;; an ordering referenced ONLY by seeded re-entry crules (build-cprog):
  ;; tag it so its WriteTask is gated like the tasks that read it
  (define (mark-seeded-only name inds)
    (map (lambda (i)
           (if (set-member? gate-inds (cons name i)) `(seeded-only ,@i) i))
         inds))
  (define (seeded-only-index? index)
    (and (pair? index) (eq? 'seeded-only (car index))))
  (define (declaration-index<? a b)
    (define a-seeded? (seeded-only-index? a))
    (define b-seeded? (seeded-only-index? b))
    (cond
      [(and (not a-seeded?) b-seeded?) #t] ; a live master must remain first
      [(and a-seeded? (not b-seeded?)) #f]
      [else (lexicographic<? (if a-seeded? (cdr a) a)
                             (if b-seeded? (cdr b) b))]))
  ;; inverted decomp registry: base -> (decomp derived set|map), the slot a
  ;; decomposed base's lattice decl carries into emission (M2.4)
  (define decomp-of
    (for/hash ([(derived info) (in-hash decomp-env)])
      (values (first info) `(decomp ,derived ,(second info)))))
  (for/fold ([decls '()]) ([name (in-list (sort (hash-keys rel-env) symbol<?))])
    (define decl (hash-ref rel-env name))
    (define arity (rel-decl-arity decl))
    (match decl
      [`(struct ,_ ...)
       (define stored (add1 arity))    ; fields + id column
       (define all (index-orderings-of indices name))
       (define master
         (find-index indices name (list->set (range 1 stored))
                     (format "master declaration for ~a" name)))
       (define lookup
         (find-index indices name (set 0)
                     (format "lookup declaration for ~a" name)))
       ;; seed-selection-needs guarantees both exist:
       ;;   (set 1 ... n) -> (... 0) = master/interning, and
       ;;   (set 0)       -> (0 ...) = lookup
       (define others
         (sort (mark-seeded-only
                name (set->list (set-subtract all (set master lookup))))
               declaration-index<?))
       (define deltas
         (sort (set->list (index-orderings-of indices `(delta ,name)))
               lexicographic<?))
       (cons `(struct ,name ,stored
                ,master ,lookup ,@others
                ,@(map (lambda (i) `(delta ,@i)) deltas))
             decls)]
      [`(table ,_ ...)
       #:when (rel-lattice-spec rel-env name)
       ;; a lattice (map) relation: every non-delta ordering ends in the
       ;; value column automatically (it is the highest storage column and
       ;; never selected), which is the layout the payload-map index wants;
       ;; the empty-selection assignment is the merge task's master
       (define spec (rel-lattice-spec rel-env name))
       (define master
         (find-index indices name (set)
                     (format "master declaration for ~a" name)))
       (define all
         (cons master
               (sort (set->list
                      (set-remove (index-orderings-of indices name) master))
                     lexicographic<?)))
       (define deltas
         (sort (set->list (index-orderings-of indices `(delta ,name)))
               lexicographic<?))
       (cons `(lattice ,name ,arity ,(cdr spec) ,(hash-ref decomp-of name #f)
                       ,@all
                       ,@(map (lambda (i) `(delta ,@i)) deltas))
             decls)]
      [`(table ,_ ...)
       ;; The empty-selection assignment is the intern master
       ;; (add-write-task's isstatic + add-intern-task read it).  It is a
       ;; mandatory live index; only secondary orderings may be seeded-only.
       (define master
         (find-index indices name (set)
                     (format "master declaration for ~a" name)))
       (define all
         (cons master
               (sort (mark-seeded-only
                      name
                      (set->list
                       (set-remove (index-orderings-of indices name) master)))
                     declaration-index<?)))
       (define deltas
         (sort (set->list (index-orderings-of indices `(delta ,name)))
               lexicographic<?))
       (cons `(relation ,name ,arity ,@all
                        ,@(map (lambda (i) `(delta ,@i)) deltas))
             decls)]
      [`(temp ,arity) (cons `(temp ,name ,arity) decls)]
      [`(enum ,_) decls]
      [`(oracle ,_ ...) decls]   ; bindings are emitted by build-cprog per stratum
      [(? lattice-spec?) decls]
      [(? listof-spec?) decls]
      [(? mapof-spec?) decls])))

;; -----------------------------------------------------------------------
;; 5. Rule lowering.

;; Escape a variable for use as a C identifier (v_<name> in the emitter).
(define esc escape-id-for-C)

;; Reorder `tup` by index ordering `ind`.
(define (order-tuple ind tup)
  (map (lambda (p) (list-ref tup p)) ind))

;; The packer records an explicit assignment for every selection.  Keeping
;; lowering on that map makes output deterministic even when several packed
;; orderings could cover the same select set.
(define (find-index indices key sel who)
  (hash-ref (hash-ref (index-plan-assignments indices) key (hash)) sel
            (lambda ()
              (error 'operationalization
                     "no ~a index assigned to selection ~a for ~a"
                     key sel who))))

;; A struct's master selection is every content column (storage 1..n), which
;; seed-selection-needs guarantees is assigned to an id-last ordering.
(define (master-index-of indices name stored who)
  (find-index indices name (list->set (range 1 stored)) who))

(define ((lower-rule rel-env indices) rule0)
  ;; strip the planner's exact-view marks up front and rebuild a plain rule, so
  ;; cjoin-spec-env / semijoin-filters / body-splitting all see ordinary
  ;; clauses; the position sets drive join-old/join-new below.
  (match-define `(syn ,rprov ,rtag ,rbodys0 ... --> ,rheads ...) rule0)
  (define-values (plain-bodys old-positions new-positions tomb-positions)
    (split-exact-marks rbodys0))
  (define rule `(syn ,rprov ,rtag ,@plain-bodys --> ,@rheads))
  ;; deterministic per-rule counter for lowering-introduced names: rule
  ;; content is a pure function of its source, so clause-order counting is
  ;; reproducible where a global gensym is not (the canonical plan and
  ;; byte-reproducible codegen both need this, docs/execution-tiers.md §4)
  (define latchk-count (box 0))
  (define (rel-arity name)
    (rel-decl-arity (hash-ref rel-env name)))
  (define (stored-arity name)                      ; struct tuples carry an id
    (match (hash-ref rel-env name)
      [`(struct ,ts ...) (add1 (length ts))]
      [decl (rel-decl-arity decl)]))
  (define (temp-rel? name)
    (match (hash-ref rel-env name #f)
      [`(temp ,_) #t]
      [_ #f]))
  (define (struct-rel? name)
    (match (hash-ref rel-env name #f)
      [`(struct ,_ ...) #t]
      [_ #f]))

  ;; var -> collection-lattice spec (sans the `lattice` head), for cjoin
  ;; lowering (docs/finish-collections.md §D).  Seeded by every body join
  ;; over a lattice relation (its value variable carries that relation's
  ;; spec) and extended through cjoin lets IN SCHEDULE ORDER -- planned
  ;; bodies are ordered, and head computes run after, so one left-to-right
  ;; pass resolves chains without a fixpoint.  This is lattice-check's seed
  ;; scan without the dynamic-rels filter: lowering needs the spec of any
  ;; lattice-column read, closed or still-ascending.
  (define (cjoin-spec-env rule)
    (define seed
      (for/fold ([env (hash)]) ([cl (in-list (rule-body rule))])
        (define spec (and (join-cl? cl) (rel-lattice-spec rel-env (join-rel cl))))
        (if (memq (and spec (second spec)) '(set map))
            (hash-set env (last (join-tuple cl)) (cdr spec))
            env)))
    (for/fold ([env seed]) ([cl (in-list (append (rule-body rule) (rule-heads rule)))])
      (match cl
        [`(syn ,_ let ,x (syn ,_ cjoin ,a ,b))
         (define sa (hash-ref env a #f))
         (define sb (hash-ref env b #f))
         (unless (or sa sb)
           (error 'operationalization
                  "(cjoin ~a ~a): neither argument's collection-lattice spec is known -- cjoin needs an argument bound from a (set ...)/(map ...) lattice value column\n  in rule: ~a"
                  a b (strip-prov rule)))
         (when (and sa sb (not (equal? sa sb)))
           (error 'operationalization
                  "(cjoin ~a ~a): arguments carry different lattice specs ~a and ~a\n  in rule: ~a"
                  a b sa sb (strip-prov rule)))
         (hash-set env x (or sa sb))]
        [_ env])))

  ;; a non-join body op; spec-env backs the cjoin lowering
  (define (lower-op cl spec-env)
    (match cl
      [`(syn ,_ /= ,x ,y) `(neq ,(esc x) ,(esc y))]
      [`(syn ,_ == ,x ,y) `(eq ,(esc x) ,(esc y))]
      [`(syn ,_ ,(? primitive-cmp? op) ,x ,y)
       `(cmp ,(cmp-prim-name op) ,(esc x) ,(esc y))]
      [`(syn ,_ let ,x ,(? var? y)) `(let ,(esc x) ,(esc y))]
      ;; the spec-aware pointwise join (§D): a dedicated c-op carrying the
      ;; spec resolved above (cjoin-spec-env guarantees it exists)
      [`(syn ,_ let ,x (syn ,_ cjoin ,a ,b))
       `(cjoin ,(esc x) ,(hash-ref spec-env x) ,(esc a) ,(esc b))]
      ;; a PARTIAL prim (prim-partial?, primitives.rkt): lower to letp -- the
      ;; emitted call carries a trailing bool* ok, and !ok abandons the row
      ;; (absence = failed match against a virtual relation)
      [`(syn ,_ let ,x (syn ,_ ,(? prim-partial? f) ,args ...))
       `(letp ,(esc x) (,(esc f) ,@(map esc args)))]
      [`(syn ,_ let ,x (syn ,_ ,f ,args ...))
       `(let ,(esc x) (,(esc f) ,@(map esc args)))]))

  ;; a body join op: pick the index whose prefix carries the bound columns.
  ;; Returns a LIST of ops: a lattice join binding an already-ground value
  ;; variable (legal cross-stratum only) probes into a fresh variable and
  ;; appends an equality check.
  (define (lower-join cl ground)
    (define name (join-rel cl))
    (define tup (join-tuple cl))
    (define lat? (and (rel-lattice-spec rel-env name) #t))
    (define value-pos (and lat? (sub1 (length tup))))
    (define sel
      (for/set ([x (in-list tup)] [i (in-naturals)]
                #:when (and (set-member? ground x)
                            (not (equal? i value-pos))))
        i))
    (cond
      [lat?
       (define vvar (last tup))
       (define value-ground? (set-member? ground vvar))
       ;; a ground value probes into a fresh check variable.  The name is a
       ;; deterministic per-rule counter, NOT a gensym (run-varying names
       ;; would break the canonical plan's byte stability); it is built in
       ;; POST-escape form -- the single "_" is compiler-reserved by
       ;; escape-id-for-C (a user "_" doubles), so no escaped source
       ;; variable can collide -- and must bypass esc below.
       (define vvar-c
         (if value-ground?
             (let ([n (unbox latchk-count)])
               (set-box! latchk-count (add1 n))
               (string->symbol (format "latchk_~a" n)))
             (esc vvar)))
       (define ind (find-index indices name sel (strip-prov cl)))
       ;; the ordering ends in the value column; the op's vars are the key
       ;; columns in index order with the bound value variable last
       (define keytup (order-tuple (take ind (sub1 (length ind))) tup))
       (cons `(join-lat ,name ,ind ,(set-count sel)
                        ,@(map esc keytup) ,vvar-c)
             (if value-ground? (list `(eq ,(esc vvar) ,vvar-c)) '()))]
      [else
       (define ind (find-index indices name sel (strip-prov cl)))
       (list `(join ,name ,ind ,(set-count sel) ,@(map esc (order-tuple ind tup))))]))

  ;; Exact semi-naive old/new probes need identical full and delta orderings.
  (define (exact-index name sel who)
    (define full (find-index indices name sel who))
    (define delta (find-index indices `(delta ,name) sel who))
    (unless (equal? full delta)
      (error 'operationalization
             "exact full/delta indices differ for ~a selection ~a in ~a: ~a vs ~a"
             name sel who full delta))
    full)

  ;; an OLD join (exact semi-naive, docs/incremental.md §6/§8): probe the full
  ;; index like lower-join, but against R_old = full - current delta.  The full
  ;; index `ind` and the delta index `dind` share an ordering (same sel), so at
  ;; runtime a match in `ind` order tests directly against `dind`.  Old joins
  ;; are never lattice (the planner excludes lattice recursion), so no lat path.
  (define (lower-join-old cl ground)
    (define name (join-rel cl))
    (define tup (join-tuple cl))
    (define sel
      (for/set ([x (in-list tup)] [i (in-naturals)]
                #:when (set-member? ground x))
        i))
    (define ord (exact-index name sel (strip-prov cl)))
    (list `(join-old ,name ,ord ,(set-count sel) ,ord
                     ,@(map esc (order-tuple ord tup)))))

  ;; Negative exact partition's pre-state O view.  The live FULL index is the
  ;; post-deletion N view, so FULL union the current delta reconstructs O.
  (define (lower-join-new cl ground)
    (define name (join-rel cl))
    (define tup (join-tuple cl))
    (define sel
      (for/set ([x (in-list tup)] [i (in-naturals)]
                #:when (set-member? ground x))
        i))
    (define ord (exact-index name sel (strip-prov cl)))
    (list `(join-new ,name ,ord ,(set-count sel) ,ord
                     ,@(map esc (order-tuple ord tup)))))

  ;; M4S struct RESOLUTION join (docs/m4s-contract.md "Negative-phase
  ;; mkstruct is probe-only"): resolve a constructed head's content to its
  ;; id against the live MASTER first, then the tombstone dictionary -- an
  ;; earlier sweep round may already have tombstoned the head, and the
  ;; retained delta witness lives only one round, so no view join can span
  ;; the gap.  The temp carries every content column (head vars are
  ;; body-ground), so the selection is exactly the master's content prefix
  ;; and only the id column binds.
  (define (lower-join-tomb cl ground)
    (define name (join-rel cl))
    (define tup (join-tuple cl))
    (define stored (stored-arity name))
    (define sel
      (for/set ([x (in-list tup)] [i (in-naturals)]
                #:when (set-member? ground x))
        i))
    (unless (and (struct-rel? name)
                 (equal? sel (list->set (range 1 stored))))
      (error 'operationalization
             "resolution join on ~a must bind the full content prefix of a struct (got selection ~a) in ~a"
             name (sort (set->list sel) <) (strip-prov cl)))
    (define ord (master-index-of indices name stored (strip-prov cl)))
    (list `(join-tomb ,name ,ord ,(set-count sel)
                      ,@(map esc (order-tuple ord tup)))))

  ;; Lower the planner's explicit two-occurrence action.  Both arms are
  ;; resolved against the SAME pre-action ground frontier; lowering never
  ;; rediscovers candidate adjacency.  Key-simple mode requires the cycle
  ;; column to be the sole suffix immediately after the selected prefix.
  (define (lower-join3 action ground)
    (define cycle (expand3-action-cycle action))
    (define (lower-arm access)
      (define cl (access-clause access))
      (define name (access-rel access))
      (define tup (access-tuple access))
      (define sel
        (for/set ([x (in-list tup)] [i (in-naturals)]
                  #:when (set-member? ground x))
          i))
      (define view (join-access-view access))
      (define ord
        (if (memq view '(old new))
            (exact-index name sel (strip-prov cl))
            (find-index indices name sel (strip-prov cl))))
      (define K (set-count sel))
      (define cycle-pos (index-of tup cycle))
      (unless (and cycle-pos
                   (= K (sub1 (length tup)))
                   (= (list-ref ord K) cycle-pos))
        (error 'operationalization
               "chosen index ~a does not put Expand3 cycle column ~a after bound set ~a for ~a"
               ord cycle-pos sel (strip-prov cl)))
      (define ordered (order-tuple ord tup))
      `(,view ,name ,ord ,K ,(if (memq view '(old new)) ord '())
              ,@(map esc ordered)))
    `(join3 ,(esc cycle)
            ,@(map lower-arm (action-accesses action))))

  ;; the driver: scan the raw delta, or probe the delta index
  (define (lower-driver cl ground)
    (define name (join-rel cl))
    (define tup (join-tuple cl))
    (define sel
      (for/set ([x (in-list tup)] [i (in-naturals)]
                #:when (set-member? ground x))
        i))
    (if (set-empty? sel)
        `(scan ,name ,@(map esc tup))
        (let ([ind (find-index indices `(delta ,name) sel (strip-prov cl))])
          `(probe ,name ,ind ,(set-count sel) ,@(map esc (order-tuple ind tup))))))

  ;; the ground types of a residual check's accept set, lowered to what the
  ;; runtime can test: a primitive tag or an interned struct's id (every
  ;; enum member lowers to _enum -- all enum constants share its struct id,
  ;; so the check is surface-level: "some enum constant", not which one)
  (define (lower-accepts ts who)
    (remove-duplicates
     (for/list ([t (in-list ts)])
       (match t
         [(or 'int 'float 'str) t]
         ;; the two collection base types share one runtime tag (a cnode
         ;; word), so the check is surface-level like enums: "some canonical
         ;; collection", not set-vs-map
         [(or 'cset 'cmap) 'cnode]
         ;; sequences have their own intern tag (docs/sequences.md §1.3)
         ['cseq 'seq]
         [_ (match (hash-ref rel-env t #f)
              [`(struct ,_ ...) `(struct ,t)]
              [`(enum ,_) `(struct _enum)]
              [_ (error 'operationalization
                        "accepted type ~a of a residual check has no runtime tag test in ~a"
                        t who)])]))))

  ;; a head op; spec-env backs the cjoin lowering, exactly as in lower-op
  (define (lower-head cl spec-env)
    (match cl
      [`(syn ,_ let ,x (syn ,_ cjoin ,a ,b))
       `(cjoin ,(esc x) ,(hash-ref spec-env x) ,(esc a) ,(esc b))]
      [`(syn ,_ let ,x (syn ,_ ,(? prim-partial? f) ,args ...))
       `(letp ,(esc x) (,(esc f) ,@(map esc args)))]
      [`(syn ,_ let ,x (syn ,_ ,f ,args ...))
       `(let ,(esc x) (,(esc f) ,@(map esc args)))]
      [`(syn ,_ tycheck ,y (accept ,ts ...) ,rid ,rel ,colv)
       ;; the failure path emits into malformed_deduction (4 fields + id)
       ;; via its master (interning) index, exactly like a mkstruct
       (define master
         (master-index-of indices 'malformed_deduction 5 (strip-prov cl)))
       `(tycheck ,(esc y) (accept ,@(lower-accepts ts (strip-prov cl)))
                 ,(esc rid) ,(esc rel) ,(esc colv) ,master)]
      [`(syn ,_ = ,x (syn ,_ ,name ,fields ...))
       (define stored (stored-arity name))
       (define master (master-index-of indices name stored (strip-prov cl)))
       ;; master orders content first, id (storage 0) last; emit the fields
       ;; in master (content) order, the ordering array scattering them home
       `(mkstruct ,name ,master ,(esc x)
                  ,@(map esc (order-tuple (take master (sub1 stored))
                                          (cons x fields))))]
      [`(syn ,_ ,name ,xs ...)
       #:when (temp-rel? name)
       `(emit-temp ,name ,@(map esc xs))]
      [`(syn ,_ ,name ,xs ...)
       #:when (rel-lattice-spec rel-env name)
       ;; a lattice contribution: batch in storage order with no dedup --
       ;; subsumption is decided by the merge (intern) task
       `(emit-lat ,name ,@(map esc xs))]
      [`(syn ,_ ,name ,xs ...)
       (define ind (find-index indices name (set) (strip-prov cl)))
       `(emit ,name ,ind ,@(map esc (order-tuple ind xs)))]))

  ;; a semijoin filter: existence probe of the future clause's relation on
  ;; its bound columns, which the requisitioned index orders first
  (define (lower-filter f)
    (match-define (list name sel tup) f)
    (define ind (find-index indices name sel
                            (format "semijoin filter on ~a" name)))
    (define K (set-count sel))
    `(exists ,name ,ind ,K ,@(map esc (order-tuple (take ind K) tup))))

  ;; a negated atom (docs/incremental.md §0.8): absence probe of the CLOSED
  ;; negated relation on its bound (non-wildcard) columns, which the
  ;; requisitioned index orders first; wildcard columns are simply not in
  ;; the key (K = 0 tests emptiness).  Scheduling (join-planning) placed the
  ;; clause after its binders, so the key variables are ground here.  A
  ;; lattice atom carries KEY columns only and probes the payload map.
  (define (lower-absent cl)
    (define name (neg-rel cl))
    (define args (neg-args cl))
    (define view (neg-view cl))
    (define sel
      (for/set ([x (in-list args)] [i (in-naturals)]
                #:unless (neg-wildcard-var? x))
        i))
    (define K (set-count sel))
    (cond
      [(rel-lattice-spec rel-env name)
       ;; Lattice negation is a pinned M4N exclusion (m4n-contract.md):
       ;; the maintenance planners never view-mark it, and a view here
       ;; means a mis-tagged plan -- refuse loudly.
       (when view
         (error 'operationalization
                "lattice negation is not maintainable (~a): ~a"
                name (strip-prov cl)))
       (define ind (find-index indices name sel
                               (format "negated atom on ~a" name)))
       `(absent-lat ,name ,ind ,K
                    ,@(map esc (order-tuple (take ind K) args)))]
      [view
       ;; M4N pre/post absence: the full and delta orderings are identical
       ;; (exact-index), and the c-op carries the delta ordering exactly as
       ;; join-old/join-new do.
       (define ind (exact-index name sel (strip-prov cl)))
       `(,(if (eq? view 'pre) 'absent-old 'absent-new)
         ,name ,ind ,K ,ind
         ,@(map esc (order-tuple (take ind K) args)))]
      [else
       (define ind (find-index indices name sel
                               (format "negated atom on ~a" name)))
       `(absent ,name ,ind ,K
                ,@(map esc (order-tuple (take ind K) args)))]))

  ;; split the body: everything before the first join is a pre-op
  (define bodys (rule-body rule))
  (define spec-env (cjoin-spec-env rule))
  (define sj-filters (semijoin-filters bodys rel-env))
  (define-values (pre-cls rest)
    (splitf-at bodys (lambda (cl) (not (join-entry? cl)))))
  (define pre-ground
    (for/fold ([g (set)]) ([cl (in-list pre-cls)])
      (set-union g (clause-out-vars cl))))
  (define-values (driver ops)
    (cond
      [(null? rest)
       (values `(once) '())                      ; fact rule: no joins;
       ;; its ops all land in `pre` (below), which the emitter runs before
       ;; allocating batches -- so a failing constant guard aborts cleanly
       ]
      [(seeded-rule? rule)
       ;; seeded re-entry version: NO delta anywhere -- every join (the
       ;; first included) probes the FULL index, and the task reruns each
       ;; iteration of an externally-seeded stratum (addTaskSeeded)
       (let loop ([ground pre-ground] [ops '()] [jpos 0] [cls rest])
         (cond
           [(null? cls) (values `(seeded) (reverse ops))]
           [(expand3-action? (car cls))
            (define filter-ops
              (map lower-filter (hash-ref sj-filters jpos '())))
            (loop (set-add ground (expand3-action-cycle (car cls)))
                  (cons (lower-join3 (car cls) ground)
                        (append (reverse filter-ops) ops))
                  (+ jpos 2)
                  (cdr cls))]
           [(join-cl? (car cls))
            (define filter-ops
              (map lower-filter (hash-ref sj-filters jpos '())))
            (loop (set-union ground (clause-vars (car cls)))
                  (append (reverse (lower-join (car cls) ground))
                          (reverse filter-ops)
                          ops)
                  (add1 jpos)
                  (cdr cls))]
           [(neg-clause? (car cls))
            (loop ground
                  (cons (lower-absent (car cls)) ops)
                  jpos
                  (cdr cls))]
           [else
            (loop (set-union ground (clause-out-vars (car cls)))
                  (cons (lower-op (car cls) spec-env) ops)
                  jpos
                  (cdr cls))]))]
      [else
       (let loop ([driver (lower-driver (car rest) pre-ground)]
                  [ground (set-union pre-ground (clause-vars (car rest)))]
                  [ops '()]
                  [jpos 1]
                  [cls (cdr rest)])
         (cond
           [(null? cls) (values driver (reverse ops))]
           [(expand3-action? (car cls))
            (define filter-ops
              (map lower-filter (hash-ref sj-filters jpos '())))
            (loop driver
                  (set-add ground (expand3-action-cycle (car cls)))
                  (cons (lower-join3 (car cls) ground)
                        (append (reverse filter-ops) ops))
                  (+ jpos 2)
                  (cdr cls))]
           [(join-cl? (car cls))
            (define filter-ops
              (map lower-filter (hash-ref sj-filters jpos '())))
            (define join-ops
              (cond
                [(set-member? old-positions jpos)
                 (lower-join-old (car cls) ground)]
                [(set-member? new-positions jpos)
                 (lower-join-new (car cls) ground)]
                [(set-member? tomb-positions jpos)
                 (lower-join-tomb (car cls) ground)]
                [else (lower-join (car cls) ground)]))
            (loop driver
                  (set-union ground (clause-vars (car cls)))
                  (append (reverse join-ops)
                          (reverse filter-ops)
                          ops)
                  (add1 jpos)
                  (cdr cls))]
           [(neg-clause? (car cls))
            (loop driver
                  ground
                  (cons (lower-absent (car cls)) ops)
                  jpos
                  (cdr cls))]
           [else
            (loop driver
                  (set-union ground (clause-out-vars (car cls)))
                  (cons (lower-op (car cls) spec-env) ops)
                  jpos
                  (cdr cls))]))]))
  ;; every tycheck hop goes AHEAD of every emitting hop, whatever the head
  ;; order upstream: a failed check must abandon the deduction before any
  ;; sink runs -- in particular before a staging temp emit, whose tuple
  ;; would otherwise revive the deduction in the follow-up rule.  (Checks
  ;; read only body-bound and const-bound variables, so hoisting is safe.)
  (define-values (check-hops emit-hops)
    (partition (lambda (hop) (eq? 'tycheck (car hop)))
               (map (lambda (cl) (lower-head cl spec-env)) (rule-heads rule))))
  ;; The rule's counting classification (docs/incremental.md §6.4), #f
  ;; outside the _count flavor.  Keyed by prov: staged sub-rules and all
  ;; versions of one rule share the original rule's prov, so the whole
  ;; chain inherits one classification (recorded by plan-stratum).
  (define count-kind
    (let ([cm (count-flavor)])
      (and cm (hash-ref (count-mode-kinds cm) (syn-prov rule)
                        (lambda ()
                          (error 'lower-rule
                                 "count flavor: no classification recorded for the rule at ~a"
                                 (rule-loc-string rule)))))))
  `(crule (pre ,@(map (lambda (cl)
                        (if (neg-clause? cl)
                            (lower-absent cl)
                            (lower-op cl spec-env)))
                      pre-cls))
          ,driver
          (body ,@ops)
          (head ,@check-hops ,@emit-hops)
          ,(rule-loc-string rule)
          ,count-kind))
