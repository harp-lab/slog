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
;;     guards (/=, <, ...), and constants.  The schedule is greedy and
;;     safety-first: constants ground their variables up front; guards and
;;     computations fire as soon as their inputs are ground; joins are
;;     picked by a tunable score (see params.rkt).  A computation whose
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

(define (join-cl? cl)
  (and (not (const-cl? cl)) (not (compute-cl? cl)) (not (guard-cl? cl))))

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
;; plan-stratum: the pass entry point.
;;
;; rules        set of typed rules (one stratum's worth)
;; rel-env      relation declarations (hash), extended here with temps
;; dynamic-rels relations that grow during this stratum (its rules' heads)
;;
;; Returns (cons planned-rules rel-env+) with planned-rules a set.

(define (plan-stratum rules rel-env dynamic-rels)
  ;; temps created by staging are dynamic too; track them alongside
  (define temps (mutable-set))
  (define (dynamic? name)
    (or (set-member? dynamic-rels name) (set-member? temps name)))
  (define (temp? name) (set-member? temps name))

  (define rel-env-box (box rel-env))
  (define (add-temp! name arity)
    (set-add! temps name)
    (set-box! rel-env-box (hash-set (unbox rel-env-box) name `(temp ,arity))))

  (define planned
    (for/fold ([acc (set)]) ([rule (in-set rules)])
      (for/fold ([acc acc]) ([staged (in-list (stage-rule rule add-temp!))])
        (set-union acc (plan-rule-versions staged dynamic? temp?)))))
  (cons planned (unbox rel-env-box)))

;; -----------------------------------------------------------------------
;; 1. Head staging.
;;
;; Returns the list of rules replacing `rule`: the parent with only its
;; immediate heads (plus a temp head when needed), followed by the staged
;; follow-up rules.

(define (stage-rule rule add-temp!)
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
       [(null? residual) (list rule)]
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

        ;; constants in scope re-establish themselves in the follow-up rule
        (define consts (filter const-cl? bodys))
        (define const-vars (for/set ([cl (in-list consts)]) (fourth cl)))
        (define carried (sort (set->list (set-subtract needed const-vars))
                              symbol<?))
        (define sub-consts
          (let ([used (set-union needed
                                 (apply set-union (set)
                                        (map clause-vars (append replays residual))))])
            (filter (lambda (cl) (set-member? used (fourth cl))) consts)))

        (define-values (parent-heads sub-body-front)
          (if (null? carried)
              ;; nothing to carry: the follow-up is driven by a replayed
              ;; construction's delta alone
              (values immediate '())
              (let ([temp (gensymb 'temp)])
                (add-temp! temp (length carried))
                (values (cons `(syn ,prov ,temp ,@carried) immediate)
                        `((syn ,prov ,temp ,@carried))))))

        (define parent `(syn ,prov rule ,@bodys --> ,@parent-heads))
        (define follow-up
          `(syn ,prov rule ,@sub-consts ,@sub-body-front ,@replays --> ,@residual))
        (cons parent (stage-rule follow-up add-temp!))])]))

;; -----------------------------------------------------------------------
;; 2 & 3. Scheduling and version generation for one staged rule.

(define (plan-rule-versions rule dynamic? temp?)
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
     (define-values (joins eq-guards)
       (for/fold ([joins '()] [eqs '()]
                  #:result (values (reverse joins) eqs))
                 ([cl (in-list (filter join-cl? bodys))])
         (define-values (cl+ eqs+) (dedup-join-vars cl))
         (values (cons cl+ joins) (append eqs+ eqs))))

     (define computes (filter compute-cl? bodys))
     (define guards (append (filter guard-cl? bodys) eq-guards))

     ;; Head computations join the body's compute pool: the scheduler runs
     ;; them once their inputs ground, and -- crucially -- if their output
     ;; variable is also bound by the body, the ==-check path makes that a
     ;; unification constraint rather than a silently shadowed C++ local.
     (define computes+ (append computes (filter compute-cl? heads)))
     (define head-rest (filter (lambda (cl) (and (not (compute-cl? cl))
                                                 (not (const-cl? cl))))
                               heads))

     (define (make-version driver)
       (define-values (body-schedule ground)
         (schedule-body driver joins computes+ guards const-vars rule))
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
       `(syn ,prov rule ,@const-lets ,@body-schedule
             --> ,@head-rest))

     (define temp-joins (filter (lambda (cl) (temp? (join-rel cl))) joins))
     (define dynamic-joins (filter (lambda (cl) (dynamic? (join-rel cl))) joins))
     (define drivers
       (cond
         ;; a temp join must drive (temps have no indices to probe), and its
         ;; delta subsumes its siblings' (they were emitted together)
         [(pair? temp-joins) (list (car temp-joins))]
         [(pair? dynamic-joins) dynamic-joins]
         ;; all joins read closed relations: one version, run once over the
         ;; reloaded database (pick the best-scoring driver)
         [(pair? joins)
          (list (best-join joins const-vars computes guards))]
         ;; no joins at all: a fact rule
         [else (list #f)]))

     (for/set ([d (in-list drivers)]) (make-version d))]))

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

(define (best-join joins ground computes guards)
  (car (sort joins > #:key (lambda (j) (join-score j ground computes guards)))))

;; Order the full body: driver first (when there is one), then the greedy
;; interleaving of joins with the guards they unblock; computes fire only
;; when the next join consumes their output, or in the flush after the
;; last join (see fire-specials).  A join-free rule has nothing that can
;; reject a row later, so it keeps the fully-eager order.
;; Returns (values schedule ground).
(define (schedule-body driver joins computes guards ground0 rule)
  ;; the pre phase stays fully eager: nothing row-bound is ground yet, so
  ;; a fireable compute here has constant inputs only -- it cannot be
  ;; speculative on rows, and fact rules keep their pre-slot ops
  (define-values (pre ground1 computes1 guards1)
    (fire-specials ground0 computes guards))
  (let loop ([schedule (if driver
                           (append pre (list driver))
                           pre)]
             [ground (if driver
                         (set-union ground1 (clause-vars driver))
                         ground1)]
             [joins (remq driver joins)]
             [computes computes1]
             [guards guards1])
    (cond
      [(pair? joins)
       ;; drain guards, pick the join, then fire exactly the computes it
       ;; consumes (transitively), then the join itself
       (define-values (fired0 ground0+ computes0+ guards0+)
         (fire-specials ground computes guards (set)))
       (define next (best-join joins ground0+ computes0+ guards0+))
       (define-values (fired1 ground1+ computes1+ guards1+)
         (fire-specials ground0+ computes0+ guards0+ (clause-vars next)))
       (loop (append schedule fired0 fired1 (list next))
             (set-union ground1+ (clause-vars next))
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
         [else (values (append schedule fired) ground+)])])))
