#lang racket

;; Operationalization: lower one stratum's planned rules to the c-program
;; (see ir-stack.rkt) that emit-cpp.rkt renders as C++.
;;
;; Four steps, each a fold over the planned rules:
;;   1. globalize constants -- each distinct literal becomes one global
;;      variable, initialized once at program load;
;;   2. collect select sets -- for every join, the set of columns it probes
;;      with (against the delta index for drivers, the full index otherwise);
;;   3. choose indices -- naively, one index per select set: the selected
;;      columns (sorted) first, the rest after, deduplicated per relation
;;      (indices.rkt has the min-chain-cover machinery for doing better);
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
(require "primitives.rkt")    ; prim-partial? (letp lowering)
(require "type-system.rkt")   ; rule-has-fallible-prims?, prim-error-arms

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
  (match cl
    [`(syn ,_ ,(or '/= '== 'let 'tycheck) ,_ ...) #f]
    [`(syn ,_ ,(? primitive-cmp?) ,_ ,_) #f]
    [_ #t]))

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
  (define selections
    (foldl (add-select-sets rel-env) (seed-select-sets rel-env) rules))
  ;; (decls are built AFTER rule lowering: which orderings are seeded-only
  ;; is decided from the indices crules actually reference)
  ;; extern oracle bindings (docs/smt.md): a stratum whose rules write the
  ;; demand struct gets the daemon-side dispatch/harvest registration,
  ;; emitted AFTER every relation decl so bindOracle's lookups succeed
  (define oracle-decls
    (sort (for/list ([(k decl) (in-hash rel-env)]
                     #:when (and (pair? decl) (eq? 'oracle (car decl))
                                 (set-member? head-dynamic-rels (third decl))))
            `(oracle ,(second decl) ,(third decl) ,(fourth decl)))
          symbol<? #:key third))
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
    (if (null? seq-occ-present)
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
  (define crules (map (lower-rule rel-env selections) rules))
  ;; Gate an ordering's WriteTask behind addTaskSeeded only if EVERY
  ;; reference to it comes from a seeded re-entry crule.  Attribution must
  ;; happen POST-lowering: find-index resolves prefix SETS, so a live
  ;; rule's selection {0,1} can land on the ordering (1 0 2) that only a
  ;; seeded rule requisitioned -- selection-level attribution once gated
  ;; an index a live rule probes (empty in fresh runs: silent
  ;; under-derivation).  Delta indices are never gated.
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
  (define gate-inds (set-subtract seeded-used live-used))
  (define decls (make-rel-decls rel-env selections decomp-env gate-inds))
  `(cprog ,dynamic-rels++ ,constants ,(append decls oracle-decls seq-decls)
          ,crules))

;; every full-index ordering a crule's ops reference, as (name . ordering)
(define (crule-index-refs cr)
  (define (op-refs op)
    (match op
      [`(join ,name ,ind ,_ ,_ ...) (list (cons name ind))]
      [`(join-lat ,name ,ind ,_ ,_ ...) (list (cons name ind))]
      [`(exists ,name ,ind ,_ ,_ ...) (list (cons name ind))]
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
           (define g (hash-ref constants v (lambda () (gensymb 'const))))
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
  (define joins (list->vector (filter join-cl? bodys)))
  (define n (vector-length joins))
  (cond
    [(or (not (semijoin-filters-enabled)) (< n 3)) (hash)]
    [else
     (define last-sel (make-hash))   ; future join index -> sel last checked
     ;; existence checks worth placing just before join `jpos` fires
     (define (filters-at jpos ground)
       (for/fold ([out '()] [seen (set)] #:result (reverse out))
                 ([m (in-range (add1 jpos) n)])
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
                (match (filters-at jpos ground)
                  ['() acc]
                  [fs (hash-set acc jpos fs)])
                acc))
          (values (set-union ground (clause-vars cl)) (add1 jpos) acc+)]
         [else
          (values (set-union ground (clause-out-vars cl)) jpos acc)]))]))

;; -----------------------------------------------------------------------
;; 2. Select sets: relation (or (delta relation)) -> set of column sets.

;; Every struct needs its interning master index (content columns first, the
;; id column -- storage 0 -- last) and its lookup index (id first); every
;; table needs at least one index to exist in (and be reloadable from).
(define (seed-select-sets rel-env)
  (for/fold ([ss (hash)]) ([(name decl) (in-hash rel-env)])
    (match decl
      [`(struct ,ts ...)
       (hash-set ss name (set (list->set (range 1 (add1 (length ts))))
                              (set 0)))]
      [`(table ,ts ...) (hash-set ss name (set (set)))]
      [_ ss])))                                   ; temps and enums: none

(define (add-select-set ss key columns)
  (hash-update ss key (lambda (s) (set-add s columns)) (set)))

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
(define ((add-select-sets rel-env) rule ss)
  (define bodys (rule-body rule))
  (define sj-filters (semijoin-filters bodys rel-env))
  ;; a seeded-rule has NO delta driver: its first join selects on the FULL
  ;; index like any other
  (define seeded? (seeded-rule? rule))
  (for/fold ([ground (set)] [jpos 0] [ss ss] #:result ss)
            ([cl (in-list bodys)])
    (cond
      [(join-cl? cl)
       (define first? (and (= jpos 0) (not seeded?)))
       (define tup (join-tuple cl))
       (define lat-value-pos
         (and (rel-lattice-spec rel-env (join-rel cl)) (sub1 (length tup))))
       (define sel
         (for/set ([x (in-list tup)] [i (in-naturals)]
                   #:when (set-member? ground x))
           i))
       (define ss0
         (for/fold ([ss ss]) ([f (in-list (hash-ref sj-filters jpos '()))])
           (add-select-set ss (first f) (second f))))
       (define ss+
         (cond
           [(and first? (set-empty? sel)) ss0]                   ; delta scan
           [first? (add-select-set ss0 `(delta ,(join-rel cl)) sel)]
           [else (add-select-set ss0 (join-rel cl)
                                 (if lat-value-pos
                                     (set-remove sel lat-value-pos)
                                     sel))]))
       (values (set-union ground (clause-vars cl)) (add1 jpos) ss+)]
      [else
       (values (set-union ground (clause-out-vars cl)) jpos ss)])))

;; -----------------------------------------------------------------------
;; 3. Indices: one per select set, selected columns (sorted) first, the
;; rest after.  Orderings are derived on demand from the selections and
;; deduplicated per relation by the set they land in.

(define (index-for-selection sel all-columns)
  (append (sort (set->list sel) <)
          (sort (set->list (set-subtract all-columns sel)) <)))

;; The full index orderings for a relation of the given arity.
(define (indices-of selections key arity)
  (for/set ([sel (in-set (hash-ref selections key (set)))])
    (index-for-selection sel (list->set (range arity)))))

;; -----------------------------------------------------------------------
;; 4. Relation declarations.

(define (make-rel-decls rel-env indices [decomp-env (hash)]
                        [gate-inds (set)])
  ;; an ordering referenced ONLY by seeded re-entry crules (build-cprog):
  ;; tag it so its WriteTask is gated like the tasks that read it
  (define (mark-seeded-only name arity inds)
    (map (lambda (i)
           (if (set-member? gate-inds (cons name i)) `(seeded-only ,@i) i))
         inds))
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
       (define all (indices-of indices name stored))
       (define master (findf (lambda (i) (= 0 (last i))) (set->list all)))
       (define lookup (findf (lambda (i) (= 0 (first i))) (set->list all)))
       ;; seed-select-sets guarantees both exist:
       ;;   (set)  -> (1 ... n 0)  = master/interning, and
       ;;   (set 0)-> (0 1 ... n)  = lookup
       (define others
         (mark-seeded-only name stored
                           (set->list (set-subtract all (set master lookup)))))
       (define deltas (set->list (indices-of indices `(delta ,name) stored)))
       (cons `(struct ,name ,stored
                ,master ,lookup ,@others
                ,@(map (lambda (i) `(delta ,@i)) deltas))
             decls)]
      [`(table ,_ ...)
       #:when (rel-lattice-spec rel-env name)
       ;; a lattice (map) relation: every non-delta ordering ends in the
       ;; value column automatically (it is the highest storage column and
       ;; never selected), which is the layout the payload-map index wants;
       ;; the first index is the merge task's master
       (define spec (rel-lattice-spec rel-env name))
       (define all (sort (set->list (indices-of indices name arity))
                         (lambda (a b) (string<? (~a a) (~a b)))))
       (define deltas (set->list (indices-of indices `(delta ,name) arity)))
       (cons `(lattice ,name ,arity ,(cdr spec) ,(hash-ref decomp-of name #f)
                       ,@all
                       ,@(map (lambda (i) `(delta ,@i)) deltas))
             decls)]
      [`(table ,_ ...)
       ;; the FIRST ordering is the intern master (add-write-task's isstatic
       ;; + add-intern-task read it): keep a live ordering first
       (define all
         (sort (mark-seeded-only name arity
                                 (set->list (indices-of indices name arity)))
               (lambda (a b) (and (not (eq? (car a) 'seeded-only))
                                  (eq? (car b) 'seeded-only)))))
       (define deltas (set->list (indices-of indices `(delta ,name) arity)))
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

;; Find an index of `key` whose leading columns are exactly `sel`.
(define (find-index indices key arity sel who)
  (define candidates
    (filter (lambda (ind)
              (equal? (list->set (take ind (set-count sel))) sel))
            (set->list (indices-of indices key arity))))
  (when (null? candidates)
    (error 'operationalization "no ~a index with prefix ~a for ~a" key sel who))
  (car candidates))

;; A struct's master (interning) index: content columns first, id last.
;; Guaranteed to exist by seed-select-sets.
(define (master-index-of indices name stored who)
  (or (findf (lambda (ind) (= 0 (last ind)))
             (set->list (indices-of indices name stored)))
      (error 'operationalization "no master index for struct ~a in ~a" name who)))

(define ((lower-rule rel-env indices) rule)
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
       (define vvar+ (if value-ground? (gensymb 'latchk) vvar))
       (define ind (find-index indices name (stored-arity name) sel (strip-prov cl)))
       ;; the ordering ends in the value column; the op's vars are the key
       ;; columns in index order with the bound value variable last
       (define keytup (order-tuple (take ind (sub1 (length ind))) tup))
       (cons `(join-lat ,name ,ind ,(set-count sel)
                        ,@(map esc keytup) ,(esc vvar+))
             (if value-ground? (list `(eq ,(esc vvar) ,(esc vvar+))) '()))]
      [else
       (define ind (find-index indices name (stored-arity name) sel (strip-prov cl)))
       (list `(join ,name ,ind ,(set-count sel) ,@(map esc (order-tuple ind tup))))]))

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
        (let ([ind (find-index indices `(delta ,name) (stored-arity name) sel
                               (strip-prov cl))])
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
       (define master (master-index-of indices 'malformed_deduction 5 (strip-prov cl)))
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
       (define ind (find-index indices name (rel-arity name) (set)
                               (strip-prov cl)))
       `(emit ,name ,ind ,@(map esc (order-tuple ind xs)))]))

  ;; a semijoin filter: existence probe of the future clause's relation on
  ;; its bound columns, which the requisitioned index orders first
  (define (lower-filter f)
    (match-define (list name sel tup) f)
    (define ind (find-index indices name (stored-arity name) sel
                            (format "semijoin filter on ~a" name)))
    (define K (set-count sel))
    `(exists ,name ,ind ,K ,@(map esc (order-tuple (take ind K) tup))))

  ;; split the body: everything before the first join is a pre-op
  (define bodys (rule-body rule))
  (define spec-env (cjoin-spec-env rule))
  (define sj-filters (semijoin-filters bodys rel-env))
  (define-values (pre-cls rest) (splitf-at bodys (lambda (cl) (not (join-cl? cl)))))
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
           [(join-cl? (car cls))
            (define filter-ops
              (map lower-filter (hash-ref sj-filters jpos '())))
            (loop (set-union ground (clause-vars (car cls)))
                  (append (reverse (lower-join (car cls) ground))
                          (reverse filter-ops)
                          ops)
                  (add1 jpos)
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
           [(join-cl? (car cls))
            (define filter-ops
              (map lower-filter (hash-ref sj-filters jpos '())))
            (loop driver
                  (set-union ground (clause-vars (car cls)))
                  (append (reverse (lower-join (car cls) ground))
                          (reverse filter-ops)
                          ops)
                  (add1 jpos)
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
  `(crule (pre ,@(map (lambda (cl) (lower-op cl spec-env)) pre-cls))
          ,driver
          (body ,@ops)
          (head ,@check-hops ,@emit-hops)
          ,(rule-loc-string rule)))
