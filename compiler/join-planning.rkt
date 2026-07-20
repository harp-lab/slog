#lang racket

;; Join planning: turn each typed rule into a set of executable rule
;; versions with fully ordered bodies and heads.
;;
;; Planning has three concerns, layered below in this order:
;;
;;  1. HEAD STAGING.  A struct construction in a head is assigned its id by
;;     the intern phase, after the read phase that produced it -- so a head
;;     clause that *uses* another head's fresh id cannot run in the same
;;     pass.  Such residual heads split into a follow-up rule: the parent
;;     emits a temp tuple carrying the variables the residue needs, and the
;;     follow-up rule joins the temp's delta with the (now interned) structs
;;     -- looked up by content -- to finish the job.  Staging recurses, so a
;;     nested construction chain becomes a chain of rules.
;;
;;  2. BODY SCHEDULING.  A rule body is a bag of joins (relation/struct
;;     patterns), computations ((let x (f args)), from primitive calls),
;;     guards (/=, <, ...), and constants.  Scheduling is safety-first:
;;     constants ground their variables up front; guards and computations
;;     fire as soon as their inputs are ground.  Small compute-free join
;;     tails use bounded action search so a certified two-arm cycle can run
;;     as Expand3; other tails retain the tunable greedy score (params.rkt).
;;     A computation whose
;;     output variable is already ground computes into a fresh variable and
;;     becomes an equality check -- so lets are correct in any position a
;;     user writes them.  If computations remain unrunnable at the end (a
;;     circular let dependency), planning fails with the offending rule.
;;
;;  3. SEMI-NAIVE VERSIONS.  For each body join on a relation that can
;;     still grow during this stratum (a "dynamic" relation), we emit one
;;     version of the rule driven by that clause's delta.  A rule whose
;;     joins all read closed (lower-stratum) relations gets a single
;;     version that runs once, at stratum start, over the freshly reloaded
;;     database.  A rule with no joins at all is a fact rule.  Follow-up
;;     rules from staging are driven solely by their temp: the parent emits
;;     the temp tuple and its constructions together, so the temp's delta
;;     subsumes the other clauses' deltas (and temps, being index-free,
;;     cannot be joined against anyway).

(provide plan-stratum)

(require "utils.rkt")
(require "params.rkt")
(require "ir-shared.rkt")
(require "join-actions.rkt")

;; -----------------------------------------------------------------------
;; Clause classification.

(define (const-cl? cl)
  (match cl
    [`(syn ,_ = ,_ (syn ,_ const ,_)) #t]
    [_ #f]))

(define (compute-cl? cl)
  (match cl
    [`(syn ,_ let ,_ ,_) #t]
    [_ #f]))

(define (guard-cl? cl)
  (match cl
    [`(syn ,_ /= ,_ ,_) #t]
    [`(syn ,_ == ,_ ,_) #t]
    [`(syn ,_ ,(? primitive-cmp?) ,_ ,_) #t]
    [_ #f]))

;; Negated atoms (docs/incremental.md §0.8) schedule EXACTLY like guards:
;; they fire once their (non-wildcard) variables are ground, they only
;; prune, and they never drive a version -- the negated relation is closed
;; (strictly lower stratum, stratify.rkt), so there is no delta to ride.
(define (join-cl? cl)
  (and (not (const-cl? cl)) (not (compute-cl? cl)) (not (guard-cl? cl))
       (not (neg-clause? cl))))

;; A head struct construction (= x (name args ...)); returns (values x args)
;; or #f.
(define (construction-cl? cl)
  (match cl
    [`(syn ,_ = ,_ (syn ,_ const ,_)) #f]
    [`(syn ,_ = ,x (syn ,_ ,name ,args ...)) #t]
    [_ #f]))

(define (construction-id cl) (fourth cl))
(define (construction-args cl) (cdddr (fifth cl)))

(define (join-rel cl)
  (match cl
    [`(syn ,_ = ,_ (syn ,_ ,name ,_ ...)) name]
    [`(syn ,_ ,name ,_ ...) name]))

;; The tuple of variables a join clause reads/writes, id first for structs.
(define (join-tuple cl)
  (match cl
    [`(syn ,_ = ,x (syn ,_ ,name ,xs ...)) (cons x xs)]
    [`(syn ,_ ,name ,xs ...) xs]))

;; -----------------------------------------------------------------------
;; Canonical rule order (RF1 slice 0, docs/rf1-contract.md determinism
;; doctrine).  Temp relation names are minted by a per-stratum counter
;; walked in canonical rule order (the shipped latchk_<n>/const<sha24>
;; precedents), so two compiles of the same tree produce byte-identical
;; names.  The order key is the rule's serialization with provenance
;; stripped and every VARIABLE renamed to its first-occurrence ordinal:
;; typed rules carry gensym'd variable spellings (wildcards `__*`, split
;; `_t*`, residual tycheck reporting vars -- all minted post-cache-key and
;; random run to run), and Racket set iteration order varies with symbol
;; spellings, so neither mint order nor raw rule text can drive the walk.
;; Relation/prim/struct names, constants, and accept lists are run-stable
;; and stay verbatim.  Two rules can tie only by being alpha-equivalent,
;; in which case the counter assignment within the tie group is arbitrary
;; -- invisible at the plan layer, which is variable-blind (canonical
;; plans register-rename), so either assignment yields the same plan SET.

(define (rule-sort-key rule)
  (define names (make-hash))
  (define (var! v)
    (if (symbol? v)
        (hash-ref! names v (lambda () (string->symbol (format "?~a" (hash-count names)))))
        v))
  (define (vars! vs) (map var! vs))
  (define (norm-rhs rhs)
    (match rhs
      [`(syn ,_ const ,v) `(const ,v)]
      [`(syn ,_ ,name ,args ...) `(,name ,@(vars! args))]
      [_ (if (symbol? rhs) (var! rhs) rhs)]))
  (define (norm-cl cl)
    (match cl
      [`(syn ,_ = ,x ,rhs) `(= ,(var! x) ,(norm-rhs rhs))]
      [`(syn ,_ let ,x ,rhs) `(let ,(var! x) ,(norm-rhs rhs))]
      [`(syn ,_ ,(? neg-symbol?) ,inner) `(~ ,(norm-cl inner))]
      [`(syn ,_ tycheck ,y ,accept ,rid ,rel ,col)
       `(tycheck ,(var! y) ,accept ,(var! rid) ,(var! rel) ,(var! col))]
      [`(syn ,_ /= ,a ,b) `(/= ,(var! a) ,(var! b))]
      [`(syn ,_ == ,a ,b) `(== ,(var! a) ,(var! b))]
      [`(syn ,_ ,(? primitive-cmp? f) ,a ,b) `(,f ,(var! a) ,(var! b))]
      [`(syn ,_ ,name ,args ...) `(,name ,@(vars! args))]
      [cl (strip-prov cl)]))   ; defensive: unknown shapes verbatim, prov-blind
  (match rule
    [`(syn ,_ rule ,bodys ... --> ,heads ...)
     (format "~s" `(rule ,@(map norm-cl bodys) --> ,@(map norm-cl heads)))]
    [_ (format "~s" (strip-prov rule))]))

;; -----------------------------------------------------------------------
;; plan-stratum: the pass entry point.
;;
;; rules        set of typed rules (one stratum's worth)
;; rel-env      relation declarations (hash), extended here with temps
;; dynamic-rels relations that grow during this stratum (its rules' heads)
;; #:level      the stratum's level, embedded in temp names: temps of two
;;              strata coexist by NAME in one daemon database (emit-cpp
;;              reuses an existing relation of the same name, fatal on
;;              arity mismatch), so names must be unique program-wide
;;
;; Returns (cons planned-rules rel-env+) with planned-rules a set.

(define (plan-stratum rules rel-env dynamic-rels #:level [level 0])
  ;; temps created by staging are dynamic too; track them alongside
  (define temps (mutable-set))
  (define (dynamic? name)
    (or (set-member? dynamic-rels name) (set-member? temps name)))
  (define (temp? name) (set-member? temps name))
  (define (lattice? name) (and (rel-lattice-spec rel-env name) #t))
  (define (struct-rel? name)
    (match (hash-ref rel-env name #f)
      [`(struct ,_ ...) #t]
      [_ #f]))
  (define (ordinary-table? name)
    (match (hash-ref rel-env name #f)
      [`(table ,_ ...) (not (lattice? name))]
      [_ #f]))

  (define rel-env-box (box rel-env))
  (define (add-temp! name arity)
    (set-add! temps name)
    (set-box! rel-env-box (hash-set (unbox rel-env-box) name `(temp ,arity))))

  ;; Deterministic temp naming (RF1 slice 0; see rule-sort-key above).
  ;; Shape: temp[<flavor>]<level>x<n> -- all-alphanumeric ON PURPOSE:
  ;;  - tests/stats-tests.sh normalizes `temp[A-Za-z0-9]+`, so a `_` would
  ;;    break the fires goldens;
  ;;  - not `v_`-prefixed (emit-cpp value-reference namespace) and not
  ;;    `$`-prefixed (docs/n0-seam-map.md Seam 4 conventions).
  ;; The flavor tag keeps the count/maintenance/delta replans of the SAME
  ;; stratum disjoint from the normal flavor's temps: flavored temps can
  ;; differ in arity (a counted temp carries the parent's full enumeration
  ;; signature), and emit-cpp resolves temps BY NAME against the live
  ;; database, fatal on arity mismatch -- under gensym the flavors never
  ;; shared names, and this preserves exactly that.
  (define flavor-tag
    (cond [(dred-maintenance-flavor?)     "r"]   ; _maint4neg
          [(negative-maintenance-flavor?) "n"]   ; _maint3neg
          [(maintenance-flavor)           "m"]   ; _maint1
          [(count-flavor)                 "c"]   ; _count
          [(delta-entry-flavor)           "d"]   ; _delta
          [else                           ""]))
  (define temp-counter (box 0))
  (define (fresh-temp! arity)
    (let loop ()
      (define n (unbox temp-counter))
      (set-box! temp-counter (add1 n))
      (define name (string->symbol (format "temp~a~ax~a" flavor-tag level n)))
      ;; skip names already taken (a user relation could spell temp<L>x<N>;
      ;; rel-env content is run-stable, so the skip is deterministic too)
      (if (hash-has-key? (unbox rel-env-box) name)
          (loop)
          (begin (add-temp! name arity) name))))

  ;; Count-flavor classification (docs/incremental.md §6.4/§8B.5, M0): a
  ;; rule is recursive iff some positive body relation is produced by its
  ;; own stratum (the count-mode carries the TRUE head-based dynamic set --
  ;; the planning `dynamic?` above is empty in this flavor); body-less
  ;; ground rules are non-recursive program support.  Recorded per ORIGINAL
  ;; rule keyed by prov:
  ;; staged sub-rules share the parent's prov, so a whole staged chain
  ;; inherits one classification (a consequence's counter is the logical
  ;; rule's, whichever stage emits it).  Distinct synthesized rules sharing
  ;; a prov that disagree degrade to 'rec -- sound for DRed^c (it only
  ;; weakens the nonrec barrier, never correctness).
  (define (count-classify! rule)
    (define cm (count-flavor))
    (when cm
      (match-define `(syn ,prov rule ,bodys ... --> ,_ ...) rule)
      (define joins (filter join-cl? bodys))
      (define kind
        (cond
          ;; Program ground facts are rule support, not JIT/data input.
          ;; Their removal is a program-version change; semantic direct input
          ;; is seeded from the VersionInstance ledger by the count epoch.
          [(and (null? joins) (not (ormap neg-clause? bodys))) 'nonrec]
          [(for/or ([cl (in-list joins)])
             (set-member? (count-mode-dynamic-rels cm) (join-rel cl)))
           'rec]
          [else 'nonrec]))
      (define kinds (count-mode-kinds cm))
      (define k0 (hash-ref kinds prov #f))
      (when (and k0 (not (eq? k0 kind)))
        (eprintf "warning: rules at one source location classify both ~a and ~a for counting; degrading to rec (docs/incremental.md 6.4)\n"
                 k0 kind))
      (hash-set! kinds prov (if (and k0 (not (eq? k0 kind))) 'rec kind))))

  ;; Count-flavor version selection (§8B.1): a temp-driven follow-up plans
  ;; normally (its temp is the only dynamic clause, so it gets exactly the
  ;; one temp-driven version, registered every iteration -- it fires once,
  ;; on the round its temp delta arrives); any other rule with joins plans
  ;; as the SEEDED all-full shape (the first join selects on the FULL
  ;; index; emit-cpp registers it once in this flavor); fact rules keep the
  ;; driverless once shape.  Exactly one version per staged rule ->
  ;; fire-once by construction.
  (define (plan-versions-counted staged-rule statics)
    (match-define `(syn ,_ rule ,bodys ... --> ,_ ...) staged-rule)
    (define joins (filter join-cl? bodys))
    (define temp-driven?
      (for/or ([cl (in-list joins)]) (temp? (join-rel cl))))
    (if (and (pair? joins) (not temp-driven?))
        (plan-rule-versions staged-rule dynamic? temp? lattice? ordinary-table? statics
                            #:seeded? #t)
        (plan-rule-versions staged-rule dynamic? temp? lattice? ordinary-table? statics)))

  ;; Canonical rule order: temps mint in this walk (rule-sort-key above),
  ;; NOT in set-iteration order, which varies with gensym'd symbol
  ;; spellings run to run.
  (define sorted-rules
    (sort (set->list rules) string<? #:key rule-sort-key #:cache-keys? #t))
  (define planned
    (for/fold ([acc (set)]) ([rule (in-list sorted-rules)])
     (with-rule-context rule (lambda ()
      (count-classify! rule)
      (for/fold ([acc acc]) ([staged (in-list (stage-rule rule fresh-temp!))])
        (match-define (cons staged-rule statics) staged)
        (define versions
          (if (and (count-flavor) (not (maintenance-flavor)))
              (plan-versions-counted staged-rule statics)
              (plan-rule-versions staged-rule dynamic? temp? lattice? ordinary-table? statics
                                  #:struct-rel? struct-rel?)))
        ;; SEEDED RE-ENTRY version (the staging-replay bug, 2026-07-10): a
        ;; staged rule with pruned (static) joins relies on this stratum's
        ;; own construction order -- statics' rows always land in FULL
        ;; before any driver's delta.  A stratum started over EXTERNALLY
        ;; SEEDED content (compression replay, open/import, frozen ground
        ;; DBs) violates that: sampling can make any pruned position the
        ;; last to arrive, and no variant fires.  So each such rule also
        ;; gets one no-delta version over FULL indices, run every
        ;; iteration only in seeded runs (addTaskSeeded; set-semantics
        ;; re-fires dedup away).  Temp-DRIVEN follow-ups are exempt: a
        ;; temp row is only ever produced in-run, co-emitted with (or
        ;; after) everything its statics need, so its timing invariant
        ;; survives seeding.
        (define needs-seeded?
          (and (not (count-flavor))   ; fire-once flavor: no re-entry versions
               (pair? statics)
               (match staged-rule
                 [`(syn ,_ rule ,bodys ... --> ,heads ...)
                  (and
                   ;; temp-driven follow-ups are exempt: a temp row is only
                   ;; ever produced in-run, co-emitted with (or after)
                   ;; everything its statics need
                   (not (for/or ([cl (in-list bodys)])
                          (and (join-cl? cl) (temp? (join-rel cl)))))
                   ;; lattice heads have no emit-side dedup (subsumption
                   ;; belongs to the merge task), so a seeded re-fire would
                   ;; register fresh delta forever -- excluded (v1 gap:
                   ;; sampled staged-lattice ground facts; docs/stats.md)
                   (not (for/or ([cl (in-list heads)])
                          (match cl
                            [`(syn ,_ ,(? symbol? name) ,_ ...)
                             (and (rel-lattice-spec rel-env name) #t)]
                            [_ #f]))))])))
        (set-union acc versions
                    (if needs-seeded?
                        (plan-rule-versions staged-rule dynamic? temp? lattice? ordinary-table? '()
                                            #:seeded? #t)
                        (set))))))))
  (cons planned (unbox rel-env-box)))

;; -----------------------------------------------------------------------
;; 1. Head staging.
;;
;; Returns the list of rules replacing `rule`, each as (cons rule statics):
;; the parent with only its immediate heads (plus a temp head when needed),
;; followed by the staged follow-up rules.  `statics` are body joins whose
;; rows are guaranteed present in FULL by the time any driver's delta
;; arrives -- clauses re-established from an earlier stage, and all but one
;; of a stage's sibling replays (they are co-emitted, so one delta subsumes
;; the others, the same argument temps make) -- and must not spawn
;; delta-driven versions of their own.
;;
;; `fresh-temp!` mints (and registers) a deterministic temp name per
;; plan-stratum's canonical walk; the staging recursion below is list-
;; ordered, so mints within one rule's staged chain are deterministic too.

(define (stage-rule rule fresh-temp! [statics '()])
  (match rule
    [`(syn ,prov rule ,bodys ... --> ,heads ...)
     ;; fresh values produced by this rule's heads: constructed ids AND
     ;; head-compute (prim let) outputs -- a construction consuming a prim
     ;; result (e.g. (lall (cins ...)), a brace literal nested in a head
     ;; field) must stage AFTER the compute, exactly like one consuming a
     ;; fresh id.  Both clause shapes bind (fourth cl).
     (define new-ids
       (for/fold ([ids (set)]) ([cl (in-list heads)]
                                #:when (or (construction-cl? cl)
                                           (compute-cl? cl)))
         (when (set-member? ids (construction-id cl))
           (error 'plan-stratum
                  "value unification (two head constructions/computations binding ~a) is not supported:\n~a"
                  (construction-id cl) (strip-prov rule)))
         (set-add ids (construction-id cl))))

     ;; immediate heads: no input depends on a fresh id
     (define (immediate? cl)
       (set-empty? (set-intersect (head-in-vars cl) new-ids)))
     (define-values (immediate residual) (partition immediate? heads))

     (cond
       [(null? residual) (list (cons rule statics))]
       [else
        ;; No immediate head means EVERY head clause consumes a fresh id, so
        ;; the follow-up rule would keep these exact heads and staging can
        ;; never make progress: a dependency cycle among head constructions/
        ;; computes (the head-side analogue of schedule-body's circular-let
        ;; check below).
        (when (null? immediate)
          (error 'plan-stratum
                 "circular dependencies among head constructions/computations (cannot stage ~a):\n~a"
                 (map strip-prov residual) (strip-prov rule)))
        ;; Constructions the residue needs, replayed as body joins of the
        ;; follow-up rule (content lookup finds the interned id).  A replay's
        ;; arguments become needed in turn.  Residual COMPUTE outputs are
        ;; bound in the follow-up too (the let re-runs there); an IMMEDIATE
        ;; compute's output is not replayable -- it stays `needed` and is
        ;; carried by value through the temp.
        (define residual-bound
          (for/set ([cl (in-list residual)] #:when (or (construction-cl? cl)
                                                       (compute-cl? cl)))
            (construction-id cl)))
        (define immediate-constructions (filter construction-cl? immediate))
        (define-values (replays needed)
          (let loop ([replays '()]
                     [needed (set-subtract
                              (apply set-union (set) (map head-in-vars residual))
                              residual-bound)])
            (define next
              (findf (lambda (cl)
                       (and (set-member? needed (construction-id cl))
                            (not (member cl replays))))
                     immediate-constructions))
            (if next
                (loop (cons next replays)
                      (set-union (set-remove needed (construction-id next))
                                 (list->set (construction-args next))))
                (values replays needed))))

        ;; Clauses that re-establish themselves in the follow-up rule
        ;; instead of riding the temp: constants, and struct content-joins
        ;; whose inputs are all themselves re-establishable -- a replay
        ;; copied from an earlier stage re-finds its interned row by
        ;; content, chaining down to constants.  Without the chaining, an
        ;; id referenced across two or more stages rides every intervening
        ;; temp by value, and a ground tree's temp width grows with its
        ;; node count.  A ground fact's constants are HEAD clauses (always
        ;; immediate -- they consume nothing), so seed from those too.
        (define-values (reest reest-vars)
          (let loop ([kept '()]
                     [vars (set)]
                     [pending (append bodys (filter const-cl? immediate))])
            (define-values (new rest)
              (partition
               (lambda (cl)
                 (match cl
                   [`(syn ,_ = ,(? symbol?) (syn ,_ const ,_)) #t]
                   [`(syn ,_ = ,(? symbol?) (syn ,_ ,(? symbol?) ,args ...))
                    (for/and ([a (in-list args)]) (set-member? vars a))]
                   [_ #f]))
               pending))
            (if (null? new)
                (values kept vars)
                (loop (append kept new)
                      (for/fold ([vars vars]) ([cl (in-list new)])
                        (set-add vars (fourth cl)))
                      rest))))
        ;; Counted plans (docs/incremental.md §6.2, the 2026-07-11 temps
        ;; decision): the temp carries the parent's FULL enumeration
        ;; signature -- every body-join variable (wildcards are already
        ;; gensym'd distinct per occurrence), plus the residue values that
        ;; ride by value today -- so temp rows are in bijection with parent
        ;; instantiations and the write-phase set-collapse can absorb only
        ;; duplicate fires of the SAME instantiation, never multiplicity.
        ;; Re-establishable vars stay OFF the temp even here: they chain
        ;; down to constants, so they hold the same value in every
        ;; instantiation -- excluding them cannot merge two distinct
        ;; instantiations -- and carrying one would hand the follow-up a
        ;; const-pre-bound temp column, which the scheduler would turn
        ;; into a (nonexistent) temp delta-index probe.
        ;; Temp COLUMN order: first-occurrence order over the rule's clause
        ;; list, NOT variable-name order (RF1 slice 0).  Gensym'd variable
        ;; spellings (wildcards `__*`, split `_t*`) vary run to run, so a
        ;; symbol<? sort flips the temp's column order -- and with it the
        ;; follow-up's scan/emit register pairing -- between two compiles
        ;; of the same tree (measured: 35/500 suite plans once temp NAMES
        ;; were deterministic).  The clause list order is run-stable (it
        ;; drives scheduling, whose plans are byte-stable), so the
        ;; occurrence index is too.
        (define var-occ
          (let ([h (make-hash)])
            (let walk ([x (map strip-prov (append bodys heads))])
              (cond [(symbol? x) (unless (hash-has-key? h x)
                                   (hash-set! h x (hash-count h)))]
                    [(pair? x) (walk (car x)) (walk (cdr x))]))
            h))
        (define (occ-of v)
          (hash-ref var-occ v
                    (lambda () (error 'plan-stratum
                                      "carried variable ~a not in rule" v))))
        (define carried
          (sort (set->list
                 (if (count-flavor)
                     (set-subtract
                      (set-union
                       (apply set-union (set)
                              (map (lambda (cl)
                                     (list->set (filter symbol? (join-tuple cl))))
                                   (filter join-cl? bodys)))
                       needed)
                      reest-vars)
                     (set-subtract needed reest-vars)))
                < #:key occ-of))
        ;; the copied subset: re-establishable clauses whose output the
        ;; follow-up uses, pulled in transitively (a copied join's inputs
        ;; need their own binders copied too)
        (define sub-reest
          (let loop ([used (set-union needed
                                      (apply set-union (set)
                                             (map clause-vars (append replays residual))))]
                     [kept '()]
                     [pending reest])
            (define-values (new rest)
              (partition (lambda (cl) (set-member? used (fourth cl))) pending))
            (if (null? new)
                kept
                (loop (for/fold ([used used]) ([cl (in-list new)])
                        (set-union used (clause-vars cl)))
                      (append kept new)
                      rest))))

        ;; Counted plans NEVER take the no-temp shape (§6.2: a follow-up
        ;; driven by a replayed construction's delta relies on the head
        ;; relation's write pipeline, which the _count flavor does not run
        ;; -- head emissions are count contributions, not inserts, so no
        ;; delta would ever drive it).  When nothing needs carrying (a
        ;; ground chain to constants, e.g. [(g (nil))]), carry one
        ;; synthesized constant: the arity-1 temp's single row fires the
        ;; follow-up exactly once, at multiplicity 1.
        (define-values (carried+ extra-consts)
          (if (and (count-flavor) (null? carried))
              (let ([dv (gensymb 'cntone)])
                (values (list dv) `((syn ,prov = ,dv (syn ,prov const 0)))))
              (values carried '())))
        (define-values (parent-heads sub-body-front)
          (if (null? carried+)
              ;; nothing to carry: the follow-up is driven by a replayed
              ;; construction's delta alone
              (values immediate '())
              (let ([temp (fresh-temp! (length carried+))])
                (values (append (cons `(syn ,prov ,temp ,@carried+) immediate)
                                extra-consts)
                        `((syn ,prov ,temp ,@carried+))))))

        (define parent `(syn ,prov rule ,@bodys --> ,@parent-heads))
        (define follow-up
          `(syn ,prov rule ,@sub-reest ,@sub-body-front ,@replays --> ,@residual))
        ;; the copies never drive; of the sibling replays one delta
        ;; subsumes the rest (co-emitted with it) -- but only when nothing
        ;; else drives: with a temp the temp drives and every replay row
        ;; already exists when it fires, without one the first replay's
        ;; delta *is* the arrival signal for its co-emitted siblings
        (define follow-statics
          (append (filter (lambda (cl) (not (const-cl? cl))) sub-reest)
                  (if (pair? replays) (cdr replays) '())))
        (cons (cons parent statics)
              (stage-rule follow-up fresh-temp! follow-statics))])]))

;; -----------------------------------------------------------------------
;; 2 & 3. Scheduling and version generation for one staged rule.

(define (plan-rule-versions rule dynamic? temp? lattice? ordinary-table? [statics '()]
                            #:seeded? [seeded? #f]
                            #:struct-rel? [struct-rel? (lambda (_name) #f)])
  (match rule
    [`(syn ,prov rule ,bodys ... --> ,heads ...)
     ;; constants (from body or head) ground their variables up front
     (define consts (filter const-cl? (append bodys heads)))
     (define const-vars (for/set ([cl (in-list consts)]) (fourth cl)))
     (define const-lets
       (map (match-lambda [`(syn ,p = ,x ,rhs) `(syn ,p let ,x ,rhs)]) consts))

     ;; normalize repeated variables within body joins: (edge x x) becomes
     ;; (edge x x*) plus an equality guard, so downstream never sees a join
     ;; binding the same variable twice
     (define body-joins (filter join-cl? bodys))
     (define-values (join-clauses eq-guards)
       (for/fold ([joins '()] [eqs '()]
                  #:result (values (reverse joins) eqs))
                 ([cl (in-list body-joins)])
         (define-values (cl+ eqs+) (dedup-join-vars cl))
         (values (cons cl+ joins) (append eqs+ eqs))))
     ;; Stable logical occurrence identities are assigned before driver choice,
     ;; version generation, and physical scheduling.  Dynamic ordinals retain
     ;; original staged-rule order, which makes exact FULL/OLD/NEW views immune
     ;; to later action reordering.
     (define dynamic-ordinal 0)
     (define joins
       (for/list ([cl0 (in-list body-joins)]
                  [cl+ (in-list join-clauses)]
                  [source-index (in-naturals)])
         (define static? (and (member cl0 statics) #t))
         (define dynamic-index
           (and (not static?)
                (dynamic? (join-rel cl+))
                (let ([i dynamic-ordinal])
                  (set! dynamic-ordinal (add1 dynamic-ordinal))
                  i)))
         (join-occurrence source-index cl+ source-index dynamic-index static?)))
     ;; joins staging marked static (stage-rule) are guaranteed present in
     ;; FULL before any driver's delta arrives: they join in every version
     ;; but never drive one
     (define driver-joins
       (filter (lambda (occ) (not (join-occurrence-static? occ))) joins))

     (define computes (filter compute-cl? bodys))
     (define neg-clauses (filter neg-clause? bodys))
     ;; M4N (docs/m4n-contract.md): under the maintenance flavors every
     ;; negated atom carries an explicit absence-evaluation state (~old =
     ;; absence at the epoch's PRE state for lost instantiations, ~new =
     ;; final POST state for gained ones -- the ratified partition table),
     ;; and each fully-bound table-negated occurrence contributes an
     ;; ANTI-DELTA version below.  The recursive sweep's interplay is
     ;; slice-2 work: a DRed plan with negation is a typed planner
     ;; refusal, never a mis-planned sweep.
     (when (and (dred-maintenance-flavor?) (pair? neg-clauses))
       (error 'plan-stratum
              "negation under the recursive sweep is not yet maintainable (m4n-contract.md slice 2): ~a"
              (strip-prov rule)))
     (define plain-guards (filter guard-cl? bodys))
     (define default-neg-sym
       (cond [(negative-maintenance-flavor?) '~old]
             [(maintenance-flavor) '~new]
             [else '~]))
     (define default-neg-guards
       (for/list ([nc (in-list neg-clauses)]) (neg-retag nc default-neg-sym)))
     ;; the pre-M4N guard order (guards, negs, eqs) is preserved so
     ;; normal-flavor plan bytes do not churn
     (define guards (append plain-guards default-neg-guards eq-guards))

     ;; Head computations join the body's compute pool: the scheduler runs
     ;; them once their inputs ground, and -- crucially -- if their output
     ;; variable is also bound by the body, the ==-check path makes that a
     ;; unification constraint rather than a silently shadowed C++ local.
     (define computes+ (append computes (filter compute-cl? heads)))
     (define head-rest (filter (lambda (cl) (and (not (compute-cl? cl))
                                                 (not (const-cl? cl))))
                               heads))

     ;; Exact views belong to logical occurrences, not scheduled positions.
     (define (make-version driver exact-old?
                           #:neg-guards [neg-guards default-neg-guards]
                           #:extra-eqs [extra-eqs '()]
                           #:anti? [anti? #f])
       (define driver-dynamic-index
         (and driver (join-occurrence-dynamic-index driver)))
       (define (view-of occ)
         (cond
           [(and driver (eq? occ driver)) (if seeded? 'full 'delta)]
           ;; M4S (docs/m4s-contract.md): a struct occurrence outside the
           ;; exact partition -- no dynamic ordinal, or a sibling of a TEMP
           ;; driver (temp-driven versions otherwise probe all-FULL, which
           ;; is exact for tables precisely because instantiation-injective
           ;; temps carry every bound value; the struct id does not exist at
           ;; stage-1 emit time, so the follow-up re-probes by content) --
           ;; is a content->id RESOLUTION join: functional (at most one id
           ;; per content), multiplicity owned by the temp.  In the negative
           ;; flavors it probes the live master THEN the tombstone
           ;; dictionary ('tomb -> join-tomb): a sweep round may tombstone
           ;; the head ARBITRARILY many rounds before the last follow-up
           ;; decrement referencing it, and the retained delta witness
           ;; lives only one round, so no FULL∪Δ view can span the gap.
           ;; Struct occurrences inside a non-temp partition keep their
           ;; exact N/O/driver views (a dictionary there would re-count
           ;; instantiations already decremented in earlier rounds).
           [(and (negative-maintenance-flavor?)
                 (not seeded?)
                 (struct-rel? (join-rel (join-occurrence-clause occ)))
                 (or (not (join-occurrence-dynamic-index occ))
                     (and driver
                          (temp? (join-rel (join-occurrence-clause driver))))))
            'tomb]
           [(join-occurrence-static? occ) 'full]
           ;; An anti-delta version's positive occurrences read survivors
           ;; only: post - delta = pre intersect post, the join-old
           ;; equation over the staged view rows (m4n-contract.md pin 5).
           [anti? 'old]
           [(and exact-old?
                 (not seeded?)
                 driver
                 (not (temp? (join-rel (join-occurrence-clause driver))))
                 driver-dynamic-index
                 (join-occurrence-dynamic-index occ)
                 (> (join-occurrence-dynamic-index occ) driver-dynamic-index))
            (if (negative-maintenance-flavor?) 'new 'old)]
           [else 'full]))
       (define (access-of occ) (join-access occ (view-of occ)))
       (define-values (body-schedule ground)
         (schedule-body-actions driver joins access-of computes+
                                (append plain-guards neg-guards eq-guards
                                        extra-eqs)
                                const-vars rule ordinary-table?))
       ;; every variable a head emits must be ground by now
       (for ([cl (in-list head-rest)])
         (define missing (set-subtract (head-in-vars cl) ground))
         (unless (set-empty? missing)
           (error 'plan-stratum
                  "head variable~a ~a never bound in body:\n~a"
                  (if (> (set-count missing) 1) "s" "")
                  (string-join (map symbol->string
                                    (sort (set->list missing) symbol<?)) ", ")
                  (strip-prov rule))))
       (define planned-body
         (for/list ([entry (in-list body-schedule)])
           (cond
             [(scalar-join-action? entry)
              (define access (scalar-join-action-access entry))
              (define cl (access-clause access))
              (case (join-access-view access)
                [(old) `(syn ,(cadr cl) $oldjoin ,cl)]
                [(new) `(syn ,(cadr cl) $newjoin ,cl)]
                [(tomb) `(syn ,(cadr cl) $tombjoin ,cl)]
                [else cl])]
             [else entry])))
       `(syn ,prov ,(if seeded? 'seeded-rule 'rule) ,@const-lets ,@planned-body
             --> ,@head-rest))

     (define (occ-rel occ) (join-rel (join-occurrence-clause occ)))
     (define temp-joins (filter (lambda (occ) (temp? (occ-rel occ))) driver-joins))
     (define dynamic-joins
       (filter (lambda (occ) (dynamic? (occ-rel occ))) driver-joins))
     ;; exact semi-naive applies the R_old/full split only when EVERY dynamic
     ;; join is a table relation: lattice-valued recursion has its own
     ;; change-splitting story (M7), so a rule with any dynamic lattice join
     ;; keeps the current all-FULL behavior (no old-clauses marked).
     (define exact-old?
       (not (for/or ([occ (in-list dynamic-joins)]) (lattice? (occ-rel occ)))))
     ;; Dynamic/temp versions have a semantic driver and therefore retain one
     ;; version per required occurrence.  Closed and seeded versions have no
     ;; such constraint: try every legal outer occurrence for small bodies so
     ;; a locally good scalar choice cannot hide the only Expand3 frontier.
     (define choose-one-driver?
       (or seeded?
           (and (null? temp-joins) (null? dynamic-joins) (pair? joins))))
     (define enumerate-drivers?
       (and choose-one-driver?
            (wcoj3-enabled)
            (<= (length joins) (wcoj3-search-cap))))
     (define drivers
       (cond
         ;; the seeded re-entry version (plan-stratum): ONE full-index
         ;; evaluation scheduled around the best-scoring join; no delta
         ;; position at all (operationalization keys off the seeded-rule
         ;; tag and lowers the first join like any other)
         [seeded?
          (if enumerate-drivers?
              joins
              (list (best-occurrence joins const-vars computes guards)))]
         ;; a temp join must drive (temps have no indices to probe), and its
         ;; delta subsumes its siblings' (they were emitted together)
         [(pair? temp-joins) (list (car temp-joins))]
         ;; one delta-driven version per dynamic join.  The joins ordered
         ;; after the driver use the sign-specific exact view: R_old for +,
         ;; R_pre=FULL union delta for -.
         [(pair? dynamic-joins) dynamic-joins]
         ;; all joins read closed relations: one version, run once over the
         ;; reloaded database
         [(pair? joins)
          (if enumerate-drivers?
              joins
              (list (best-occurrence joins const-vars computes guards)))]
         ;; no joins at all: a fact rule
         [else (list #f)]))

     (define candidates
       (for/list ([driver (in-list drivers)])
         (cons driver (make-version driver exact-old?))))
     ;; M4N anti-delta versions: one per fully-bound table-negated
     ;; occurrence, driven by the negated relation's staged opposite-sign
     ;; transitions.  The drive row binds the atom's variables (no probe of
     ;; its own occurrence: for a fully-bound atom, gained implies
     ;; absent-before and lost implies absent-after by construction);
     ;; sibling negated occurrences split by the ownership order -- in the
     ;; negative flavor, earlier siblings at POST (~new), later at PRE
     ;; (~old); mirrored in the positive flavor.  Struct- and
     ;; lattice-negated occurrences are pinned exclusions (admission owns
     ;; their fallback).
     (define anti-versions
       (if (and (maintenance-flavor) (not (dred-maintenance-flavor?)))
           (for/list ([nc (in-list neg-clauses)]
                      [i (in-naturals)]
                      #:when (andmap (lambda (x) (not (neg-wildcard-var? x)))
                                     (neg-args nc))
                      #:unless (or (lattice? (neg-rel nc))
                                   (struct-rel? (neg-rel nc))))
             (define-values (drive-cl drive-eqs)
               (dedup-join-vars (neg-inner nc)))
             (define drive-occ
               (join-occurrence (+ (length joins) i) drive-cl
                                (+ (length joins) i) #f #f))
             (define anti-neg-guards
               (for/list ([mc (in-list neg-clauses)] [j (in-naturals)]
                          #:unless (= j i))
                 (neg-retag mc
                            (if (negative-maintenance-flavor?)
                                (if (< j i) '~new '~old)
                                (if (< j i) '~old '~new)))))
             (make-version drive-occ exact-old?
                           #:neg-guards anti-neg-guards
                           #:extra-eqs drive-eqs
                           #:anti? #t))
           '()))
     (define (expand-count candidate)
       (match (cdr candidate)
         [`(syn ,_ ,_ ,body ... --> ,_ ...)
          (count expand3-action? body)]))
     (define (candidate-better? a b)
       (define ea (expand-count a))
       (define eb (expand-count b))
       (cond
         [(> ea eb) #t]
         [(< ea eb) #f]
         [else
          (define da (car a))
          (define db (car b))
          (define sa (if da (join-score (join-occurrence-clause da)
                                        const-vars computes guards) 0))
          (define sb (if db (join-score (join-occurrence-clause db)
                                        const-vars computes guards) 0))
          (if (= sa sb)
              (< (if da (join-occurrence-id da) -1)
                 (if db (join-occurrence-id db) -1))
              (> sa sb))]))
     (define base-versions
       (if choose-one-driver?
           (set (cdr (first (sort candidates candidate-better?))))
           (for/set ([candidate (in-list candidates)]) (cdr candidate))))
     (set-union base-versions (list->set anti-versions))]))

;; Rewrite a join clause so no variable repeats, returning the clause and
;; the equality guards that restore the constraint.
(define (dedup-join-vars cl)
  (match cl
    [`(syn ,prov = ,x (syn ,p2 ,name ,xs ...))
     (define-values (xs+ eqs) (dedup-vars (cons x xs) prov))
     (values `(syn ,prov = ,(car xs+) (syn ,p2 ,name ,@(cdr xs+))) eqs)]
    [`(syn ,prov ,name ,xs ...)
     (define-values (xs+ eqs) (dedup-vars xs prov))
     (values `(syn ,prov ,name ,@xs+) eqs)]))

(define (dedup-vars xs prov)
  (for/fold ([seen (set)] [out '()] [eqs '()]
             #:result (values (reverse out) eqs))
            ([x (in-list xs)])
    (if (set-member? seen x)
        (let ([x* (gensymb 'dup)])
          (values seen (cons x* out) (cons `(syn ,prov == ,x ,x*) eqs)))
        (values (set-add seen x) (cons x out) eqs))))

;; -----------------------------------------------------------------------
;; The greedy scheduler.

;; Emit guards and computations whose inputs are ground, to a fixpoint.
;; Guards always fire eagerly -- they only prune, which is safe and
;; beneficial at any point.  Computations are gated by `needed`:
;;
;;   'all      -- fire every ground-input compute (the post-join flush,
;;                and the whole schedule for join-free rules);
;;   a var set -- fire only computes whose output is in the set and not
;;                already ground, transitively pulling in computes that
;;                feed them (the on-demand case: the next join consumes
;;                the output).
;;
;; The gating is a soundness fix, not a heuristic: a compute fired before
;; a later FILTERING join runs speculatively on rows that join would
;; reject, and a partial prim can fault on them.  Concretely: a demand
;; answer rule (+ ans elem) scheduled before the demand-gate join faulted
;; on an any-typed cons whose element was a nested-list struct -- the
;; interned (nil) tail is shared between the demanded list and unrelated
;; nested-list facts, so the reverse-tail cons probe yields foreign rows
;; the gate exists to discard.  Deferring computes to consumption point
;; or to the flush means a prim only ever runs on fully-matched rows.
;;
;; A computation whose output is already ground computes into a fresh
;; variable and asserts equality (a pure filter; in needed-mode it defers
;; to the flush).  Returns (values emitted ground computes guards) with
;; the emitted clauses in firing order.
(define (fire-specials ground computes guards [needed 'all])
  (let loop ([emitted '()] [ground ground] [computes computes] [guards guards]
             [needed needed])
    (define g (findf (lambda (cl) (subset? (clause-in-vars cl) ground)) guards))
    (define (fireable? cl)
      (match-define `(syn ,_ let ,x ,_) cl)
      (and (subset? (clause-in-vars cl) ground)
           (or (eq? needed 'all)
               (and (set-member? needed x)
                    (not (set-member? ground x))))))
    ;; In flush mode, among fireable computes prefer one that (transitively)
    ;; feeds a pending guard, so the guard prunes before unrelated computes
    ;; run -- this is what lets `(= h (chas m k)) (> h 0) (= v (cget m k))`
    ;; protect a faultable cget.  Every fireable compute fires in the flush
    ;; regardless, so the preference is pure reordering: it cannot introduce
    ;; speculative execution (unlike eager firing in needed mode, which the
    ;; gating above exists to prevent).
    (define feeders
      (and (not g) (eq? needed 'all) (pair? guards)
           (let close ([vs (for/fold ([s (set)]) ([gd (in-list guards)])
                             (set-union s (clause-in-vars gd)))])
             (define vs+
               (for/fold ([n vs]) ([cl (in-list computes)])
                 (match-define `(syn ,_ let ,x ,_) cl)
                 (if (set-member? n x) (set-union n (clause-in-vars cl)) n)))
             (if (equal? vs+ vs) vs (close vs+)))))
    (define c (and (not g)
                   (or (and feeders
                            (findf (lambda (cl)
                                     (match-define `(syn ,_ let ,x ,_) cl)
                                     (and (set-member? feeders x) (fireable? cl)))
                                   computes))
                       (findf fireable? computes))))
    (cond
      [g (loop (cons g emitted) ground computes (remq g guards) needed)]
      [c
       (match-define `(syn ,prov let ,x ,rhs) c)
       (if (set-member? ground x)
           (let ([x* (gensymb 'chk)])
             (loop (list* `(syn ,prov == ,x ,x*) `(syn ,prov let ,x* ,rhs) emitted)
                   ground (remq c computes) guards needed))
           (loop (cons c emitted) (set-add ground x) (remq c computes) guards
                 needed))]
      [(eq? needed 'all) (values (reverse emitted) ground computes guards)]
      [else
       ;; feeder expansion: a needed compute whose inputs are not ground
       ;; makes its inputs needed too (chains of lets resolve on demand)
       (define needed+
         (for/fold ([n needed]) ([cl (in-list computes)])
           (match-define `(syn ,_ let ,x ,_) cl)
           (if (and (set-member? n x)
                    (not (set-member? ground x))
                    (not (subset? (clause-in-vars cl) ground)))
               (set-union n (clause-in-vars cl))
               n)))
       (if (equal? needed+ needed)
           (values (reverse emitted) ground computes guards)
           (loop emitted ground computes guards needed+))])))

;; Score a candidate join at the current frontier: prefer joins probing many
;; already-ground columns, reading few new ones, and unblocking guards or
;; computations.  Weights are parameters (params.rkt) for later tuning.
(define (join-score cl ground computes guards)
  (define vars (clause-vars cl))
  (define bound (set-intersect vars ground))
  (define free (set-subtract vars ground))
  (define ground+ (set-union ground vars))
  ;; only GUARDS count as enabled: computes fire on demand (fire-specials
  ;; needed-gating), so rewarding a join for making a compute fireable
  ;; would actively optimize for the speculative firing the gating removes
  (define enabled
    (for/sum ([sp (in-list guards)])
      (if (and (not (subset? (clause-in-vars sp) ground))
               (subset? (clause-in-vars sp) ground+))
          1
          0)))
  (+ (* (plan-weight-bound) (set-count bound))
     (* (plan-weight-free) (set-count free))
     (* (plan-weight-enables) enabled)))

(define (best-occurrence occurrences ground computes guards)
  (car
   (sort occurrences
         (lambda (a b)
           (define sa (join-score (join-occurrence-clause a) ground computes guards))
           (define sb (join-score (join-occurrence-clause b) ground computes guards))
           (if (= sa sb)
               (< (join-occurrence-id a) (join-occurrence-id b))
               (> sa sb))))))

;; Does the already-consumed positive-occurrence incidence graph connect two
;; variables?  Constants, guards, and computations intentionally do not add
;; edges: automatic Expand3 selection is initially restricted to a genuine
;; relation-cycle closure.
(define (incidence-connected? x y consumed)
  (let loop ([seen (set x)])
    (define seen+
      (for/fold ([s seen]) ([occ (in-list consumed)])
        (define vs (clause-vars (join-occurrence-clause occ)))
        (if (set-empty? (set-intersect s vs)) s (set-union s vs))))
    (cond
      [(set-member? seen+ y) #t]
      [(equal? seen seen+) #f]
      [else (loop seen+)])))

(struct expand-candidate (action bound-count) #:transparent)

;; Enumerate conservative key-simple ternary cycle closers at one ground
;; frontier.  A group of three or more arms sharing C is left scalar until an
;; explicit IntersectN action exists; a different two-arm cycle in the same
;; rule may still qualify.
(define (expand3-candidates pending ground consumed access-of ordinary-table?)
  (define infos
    (for/hash ([occ (in-list pending)])
      (define access (access-of occ))
      (define vars (access-vars access))
      (define free (set-subtract vars ground))
      (define bound (set-intersect vars ground))
      (define eligible?
        (and (wcoj3-enabled)
             (ordinary-table? (access-rel access))
             (memq (join-access-view access) '(full old new))
             (= (set-count free) 1)
             (not (set-empty? bound))
             ;; With normalized distinct tuple variables, K+1=arity says C
             ;; is the sole unbound stored column: no payload/group product.
             (= (length (access-tuple access)) (add1 (set-count bound)))
             (= (length (access-tuple access)) (set-count vars))))
      (values occ (and eligible? (cons (set-first free) bound)))))
  (define groups
    (for/fold ([h (hash)]) ([occ (in-list pending)])
      (match (hash-ref infos occ)
        [#f h]
        [(cons cycle _)
         (hash-update h cycle (lambda (xs) (cons occ xs)) '())])))
  (define candidates
    (for/list ([cycle (in-list (sort (hash-keys groups) symbol<?))]
               #:do [(define arms (sort (hash-ref groups cycle) <
                                        #:key join-occurrence-id))]
               #:when (= (length arms) 2)
               #:do [(define left (first arms))
                     (define right (second arms))
                     (define lbound (cdr (hash-ref infos left)))
                     (define rbound (cdr (hash-ref infos right)))]
               #:when
               (for*/or ([x (in-set lbound)] [y (in-set rbound)])
                 (and (not (eq? x y))
                      (incidence-connected? x y consumed))))
      (expand-candidate
       (expand3-action cycle (access-of left) (access-of right))
       (+ (set-count lbound) (set-count rbound)))))
  (sort candidates
        (lambda (a b)
          (define ba (expand-candidate-bound-count a))
          (define bb (expand-candidate-bound-count b))
          (if (= ba bb)
              (lexicographic<?
               (action-occurrence-ids (expand-candidate-action a))
               (action-occurrence-ids (expand-candidate-action b)))
              (> ba bb)))))

(define (lexicographic<? xs ys)
  (cond
    [(null? xs) (pair? ys)]
    [(null? ys) #f]
    [(< (car xs) (car ys)) #t]
    [(> (car xs) (car ys)) #f]
    [else (lexicographic<? (cdr xs) (cdr ys))]))

(struct searched-plan (schedule ground expands score) #:transparent)

(define (better-searched-plan a b)
  (cond
    [(not a) b]
    [(not b) a]
    [(> (searched-plan-expands a) (searched-plan-expands b)) a]
    [(< (searched-plan-expands a) (searched-plan-expands b)) b]
    [(> (searched-plan-score a) (searched-plan-score b)) a]
    [else a]))

;; Bounded exhaustive action search for graph-like bodies whose pre-phase has
;; discharged every computation.  Guards remain deterministic/eager.  If the
;; best complete schedule contains no Expand3, the caller deliberately keeps
;; today's scalar greedy plan unchanged.
(define (search-action-tail pending ground consumed guards access-of
                            ordinary-table?)
  (define memo (make-hash))
  (define (go pending ground consumed guards)
    (define key
      (list (sort (map join-occurrence-id pending) <)
            (sort (set->list ground) symbol<?)))
    (hash-ref!
     memo key
     (lambda ()
       (define-values (fired ground+ computes+ guards+)
         (fire-specials ground '() guards (set)))
       (unless (null? computes+)
         (error 'plan-stratum "internal WCOJ search retained a computation"))
       (cond
         [(null? pending)
          (define-values (tail final-ground final-computes final-guards)
            (fire-specials ground+ '() guards+))
          (and (null? final-computes)
               (null? final-guards)
               (searched-plan (append fired tail) final-ground 0 0))]
         [else
          (define expansions
            (expand3-candidates pending ground+ consumed access-of ordinary-table?))
          (define candidates
            (append
             (for/list ([candidate (in-list expansions)])
               (define action (expand-candidate-action candidate))
               (define arms (map join-access-occurrence (action-accesses action)))
               (define suffix
                 (go (filter (lambda (occ) (not (memq occ arms))) pending)
                     (set-add ground+ (expand3-action-cycle action))
                     (append arms consumed)
                     guards+))
               (and suffix
                    (struct-copy
                     searched-plan suffix
                     [schedule (append fired (list action)
                                       (searched-plan-schedule suffix))]
                     [expands (add1 (searched-plan-expands suffix))]
                     [score (+ (expand-candidate-bound-count candidate)
                               (searched-plan-score suffix))])))
             (for/list ([occ (in-list
                              (sort pending < #:key join-occurrence-id))])
               (define clause (join-occurrence-clause occ))
               (define suffix
                 (go (remq occ pending)
                     (set-union ground+ (clause-vars clause))
                     (cons occ consumed)
                     guards+))
               (and suffix
                    (struct-copy
                     searched-plan suffix
                     [schedule
                      (append fired
                              (list (scalar-join-action (access-of occ)))
                              (searched-plan-schedule suffix))]
                     [score (+ (join-score clause ground+ '() guards+)
                               (searched-plan-score suffix))])))))
          (for/fold ([best #f]) ([candidate (in-list candidates)])
            (better-searched-plan best candidate))]))))
  (go pending ground consumed guards))

;; Order the full body: driver first (when there is one), then the greedy
;; interleaving of joins with the guards they unblock; computes fire only
;; when the next join consumes their output, or in the flush after the
;; last join (see fire-specials).  A join-free rule has nothing that can
;; reject a row later, so it keeps the fully-eager order.
;; Returns (values schedule ground).
(define (schedule-body-actions driver joins access-of computes guards ground0 rule
                               ordinary-table?)
  ;; the pre phase stays fully eager: nothing row-bound is ground yet, so
  ;; a fireable compute here has constant inputs only -- it cannot be
  ;; speculative on rows, and fact rules keep their pre-slot ops
  (define-values (pre ground1 computes1 guards1)
    (fire-specials ground0 computes guards))
  (define initial-schedule
    (if driver
        (append pre (list (scalar-join-action (access-of driver))))
        pre))
  (define initial-ground
    (if driver
        (set-union ground1 (clause-vars (join-occurrence-clause driver)))
        ground1))
  (define pending (remq driver joins))
  (define searched
    (and driver
         (wcoj3-enabled)
         (null? computes1)
         (<= (length joins) (wcoj3-search-cap))
         (search-action-tail pending initial-ground (list driver) guards1
                             access-of ordinary-table?)))
  (cond
    [(and searched (> (searched-plan-expands searched) 0))
     (values (append initial-schedule (searched-plan-schedule searched))
             (searched-plan-ground searched))]
    [else
  (let loop ([schedule initial-schedule]
             [ground initial-ground]
             [joins pending]
             [computes computes1]
             [guards guards1])
    (cond
      [(pair? joins)
       ;; drain guards, pick the join, then fire exactly the computes it
       ;; consumes (transitively), then the join itself
       (define-values (fired0 ground0+ computes0+ guards0+)
         (fire-specials ground computes guards (set)))
       (define next (best-occurrence joins ground0+ computes0+ guards0+))
       (define next-clause (join-occurrence-clause next))
       (define-values (fired1 ground1+ computes1+ guards1+)
         (fire-specials ground0+ computes0+ guards0+ (clause-vars next-clause)))
       (loop (append schedule fired0 fired1
                     (list (scalar-join-action (access-of next))))
             (set-union ground1+ (clause-vars next-clause))
             (remq next joins)
             computes1+
             guards1+)]
      [else
       ;; flush: every remaining compute and guard, on fully-matched rows
       (define-values (fired ground+ computes+ guards+)
         (fire-specials ground computes guards))
       (cond
         [(pair? computes+)
          (error 'plan-stratum
                 "circular let dependencies (cannot order ~a):\n~a"
                 (map strip-prov computes+) (strip-prov rule))]
         [(pair? guards+)
          (error 'plan-stratum
                 "guard over variables never bound in body (~a):\n~a"
                 (map strip-prov guards+) (strip-prov rule))]
         [else (values (append schedule fired) ground+)])]))]))
