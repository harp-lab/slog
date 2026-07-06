#lang racket

;; Lattice checks (docs/lattices.md §5): the occurrence restrictions on
;; lattice-typed columns and the monotone-use calculus.
;;
;; The type system treats lattice types as transparent aliases of their
;; base types (injection in, unwrap out); everything lattice-specific is
;; checked here, after stratification, because the discipline is exactly
;; "reading a still-ascending value is legal only monotonically" and
;; still-ascending-vs-closed is stratum information:
;;
;;   - a body read of lattice relation R inside R's own SCC binds a
;;     lattice-typed variable, which may only be contributed onward
;;     (possibly through a whitelisted monotone transfer), tested by an
;;     upward-closed guard, or discarded;
;;   - once R's stratum is done its values are final and any use is legal.
;;
;; The same-SCC test is one bit the stratifier already gives us: a body
;; relation at the same stratum LEVEL as the rule is necessarily in the
;; same SCC (a body->head edge across SCCs forces a strictly higher level),
;; so "R is a head relation of this stratum" = "R can still ascend here".
;;
;; The checks are purely syntactic over a fixed whitelist -- v1's lattices
;; and transfers are built in and their monotonicity is a theorem proven
;; once (see tests), not per-program.

(provide check-lattice-declarations
         check-lattice-strata)

(require "ir-shared.rkt")
(require "stratify.rkt")
(require "ir-stack.rkt")

;; -----------------------------------------------------------------------
;; Declaration-level occurrence restrictions (§3.1): a lattice type may
;; appear only as the last column of a table (the map's value column).

(define (check-lattice-declarations type-env)
  (define rels (type-env-rels type-env))
  (define aliases (type-env-aliases type-env))
  (define (lattice-type? t)
    (lattice-spec? (hash-ref rels t (lambda () #f))))
  (for ([(name decl) (in-hash rels)])
    (match decl
      [`(struct ,ts ...)
       (for ([t (in-list ts)])
         (when (lattice-type? t)
           (error 'lattice-check
                  "lattice type ~a cannot be a field of struct ~a: interned identity and merged state are incompatible"
                  t name)))]
      [`(table ,ts ...)
       (define lat-positions
         (for/list ([t (in-list ts)] [i (in-naturals)] #:when (lattice-type? t)) i))
       (when (> (length lat-positions) 1)
         (error 'lattice-check
                "table ~a has ~a lattice-typed columns; at most one is supported in v1"
                name (length lat-positions)))
       (when (and (pair? lat-positions)
                  (not (= (car lat-positions) (sub1 (length ts)))))
         (error 'lattice-check
                "lattice-typed column ~a of table ~a must be the last column (the map's value)"
                (list-ref ts (car lat-positions)) name))
       (when (and (pair? lat-positions) (= 1 (length ts)))
         (error 'lattice-check
                "map relation ~a needs at least one key column (a keyless global value is not supported in v1)"
                name))]
      [`(lattice flat ,t)
       (when (lattice-type? t)
         (error 'lattice-check
                "(flat ~a): the payload of a flat lattice cannot itself be a lattice type" t))
       (unless (or (memq t '(int float str any cset cmap coll))
                   (hash-has-key? rels t)
                   (hash-has-key? aliases t))
         (error 'lattice-check "(flat ~a): type ~a is not declared" t t))]
      ;; collection lattices (docs/primitives.md §6.1): element/key types are
      ;; ordinary value types (a still-ascending value has no stable identity,
      ;; so lattice types are excluded exactly as they are from struct fields
      ;; and map keys); a map's value spec validates recursively.
      [`(lattice set ,t)
       (when (lattice-type? t)
         (error 'lattice-check
                "(set ~a): the element type cannot itself be a lattice type" t))
       (unless (or (memq t '(int float str any cset cmap coll))
                   (hash-has-key? rels t)
                   (hash-has-key? aliases t))
         (error 'lattice-check "(set ~a): type ~a is not declared" t t))]
      [`(lattice map ,k ,inner)
       (let check-map ([k k] [inner inner])
         (when (lattice-type? k)
           (error 'lattice-check
                  "(map ~a ...): the key type cannot be a lattice type (an ascending key has no stable identity)" k))
         (unless (or (memq k '(int float str any cset cmap coll))
                     (hash-has-key? rels k)
                     (hash-has-key? aliases k))
           (error 'lattice-check "(map ~a ...): type ~a is not declared" k k))
         (match inner
           [`(map ,k2 ,inner2) (check-map k2 inner2)]
           [`(,(or 'flat 'set) ,t)
            (unless (or (memq t '(int float str any cset cmap coll))
                        (hash-has-key? rels t)
                        (hash-has-key? aliases t))
              (error 'lattice-check "(map ... (~a ~a)): type ~a is not declared"
                     (car inner) t t))]
           [_ (void)]))]
      [_ (void)]))
  ;; unions may not mix lattice types in
  (for ([(name members) (in-hash aliases)])
    (for ([m (in-set members)] #:unless (eq? m name))
      (when (lattice-type? m)
        (error 'lattice-check
               "lattice type ~a cannot be a member of union ~a" m name)))))

;; -----------------------------------------------------------------------
;; The monotone-use calculus (§5.1), per stratum over typed rules.

;; The relation and argument list of a typed join clause; #f for guards,
;; lets, and constants.  Struct patterns (= x (name fs ...)) count -- a
;; lattice variable inside one is a content (key) use.
(define (join-parts cl)
  (match cl
    [`(syn ,_ /= ,_ ,_) #f]
    [`(syn ,_ ,(? primitive-cmp?) ,_ ,_) #f]
    [`(syn ,_ let ,_ ,_) #f]
    [`(syn ,_ tycheck ,_ ...) #f]   ; residual type checks are not joins
    [`(syn ,_ = ,_ (syn ,_ const ,_)) #f]
    [`(syn ,_ = ,x (syn ,_ ,name ,args ...)) (list name (cons x args) #t)]
    [`(syn ,_ ,name ,args ...) (list name args #f)]))

(define (check-lattice-strata strata type-env)
  (define rel-env (type-env-rels type-env))
  (define (spec-of name) (rel-lattice-spec rel-env name))
  (for ([stratum (in-list strata)])
    (define rules (set->list (stratum-rules stratum)))
    (define dynamic-rels
      (for/fold ([acc (set)]) ([rule (in-list rules)])
        (set-union acc (rule-head-rels rule))))
    (for ([rule (in-list rules)])
      (check-rule rule rel-env spec-of dynamic-rels))
    (warn-unbounded-recursion rules rel-env spec-of dynamic-rels)))

;; ---- per-rule check --------------------------------------------------

(define (check-rule rule rel-env spec-of dynamic-rels)
  (match-define `(syn ,_ rule ,bodys ... --> ,heads ...) rule)
  (define (die fmt . args)
    (error 'lattice-check "~a\n  in rule: ~a"
           (apply format fmt args) (strip-prov rule)))

  ;; constants: var -> literal (for the *-by-nonneg-literal transfer and
  ;; classifying ground guard operands)
  (define const-env
    (for/fold ([h (hash)]) ([cl (in-list (append bodys heads))])
      (match cl
        [`(syn ,_ = ,x (syn ,_ const ,v)) (hash-set h x v)]
        [_ h])))

  ;; lattice constants: var -> one | inf | top (nullary lattice prims)
  (define lat-const-env
    (for/fold ([h (hash)]) ([cl (in-list (append bodys heads))])
      (match cl
        [`(syn ,_ let ,x (syn ,_ ,(and f (or 'one 'inf 'top)))) (hash-set h x f)]
        [_ h])))

  ;; ---- seed taints: in-SCC lattice body reads bind lattice values ----
  ;; taint: var -> (list spec how origin) with how = 'seed | 'transfer and
  ;; origin the let clause that produced a transfer taint (#f for seeds) --
  ;; needed to tell a transfer's own output binding from a REbinding of an
  ;; already-lattice-bound variable (the planner's ==-check in disguise)
  (define seeds
    (for/fold ([taint (hash)]) ([cl (in-list bodys)])
      (match (join-parts cl)
        [(list name args #f)
         #:when (and (spec-of name) (set-member? dynamic-rels name))
         (define spec (spec-of name))
         (define v (last args))
         (when (hash-has-key? const-env v)
           (die "the value position of still-ascending lattice relation ~a must be a plain variable, not a constant (an equality test on a live lattice value is not upward-closed)"
                name))
         (when (member v (drop-right args 1))
           (die "variable ~a is both a key and the value of lattice relation ~a (in-SCC): a live lattice value cannot be a join key"
                v name))
         (when (hash-has-key? taint v)
           (die "variable ~a binds the values of two still-ascending lattice reads: the implicit meet is not supported; bind separately"
                v))
         (hash-set taint v (list spec 'seed #f))]
        [_ taint])))

  ;; ---- propagate through lets (whitelisted monotone transfers) -------
  ;; iterate lets to a fixpoint: a let over a tainted input either taints
  ;; its output (whitelisted transfer) or dies
  (define taint
    (let loop ([taint seeds])
      (define taint+
        (for/fold ([taint taint]) ([cl (in-list (append bodys heads))])
          (match cl
            [`(syn ,_ let ,x (syn ,_ ,f ,args ...))
             (define in-taints
               (filter values (map (lambda (a) (hash-ref taint a #f)) args)))
             (cond
               [(null? in-taints) taint]
               [(hash-has-key? taint x) taint]  ; handled below (rebinding check)
               [else
                (define spec (first (first in-taints)))
                (define kind (lattice-spec-kind spec))
                ;; all tainted inputs must share one spec
                (for ([t (in-list in-taints)])
                  (unless (equal? (first t) spec)
                    (die "primitive ~a mixes values of two different lattices ~a and ~a"
                         f spec (first t))))
                ;; the whitelist yields the OUTPUT's spec (#f = not monotone).
                ;; Position matters: an op monotone in its COLLECTION argument
                ;; is not monotone in its element/key/value arguments -- a
                ;; still-ascending value used as an inserted element or key
                ;; would freeze one snapshot of it into interned content.
                (define (taint-only-at? . positions)
                  (for/and ([a (in-list args)] [i (in-naturals)])
                    (or (memv i positions) (not (hash-has-key? taint a)))))
                (define out-spec
                  (case kind
                    [(min max)
                     (and (match* (f args)
                            [('+ _) #t]
                            [('- (list a _)) (hash-has-key? taint a)] ; (- V x) only
                            [('min _) #t]
                            [('max _) #t]
                            [('* (list a b))
                             ;; multiplier must be a nonnegative literal
                             (define other (if (hash-has-key? taint a) b a))
                             (and (not (hash-has-key? taint other))
                                  (let ([v (hash-ref const-env other #f)])
                                    (and (real? v) (>= v 0))))]
                            [(_ _) #f])
                          spec)]
                    [(count) (and (eq? f 'cplus) spec)]
                    [(flat) #f]
                    ;; sets grow by insert (collection position only: a live
                    ;; element would be snapshotted) and by union (either
                    ;; argument -- presence-union is monotone in both, and
                    ;; unit values make the left bias irrelevant).  cdel/
                    ;; cdiff shrink: excluded.
                    [(set)
                     (and (case f
                            [(cins) (taint-only-at? 0)]
                            [(cmerge) #t]
                            [else #f])
                          spec)]
                    ;; maps grow by put, monotone in the MAP position only
                    ;; (colliding values reconcile at the merge point).
                    ;; cmerge is EXCLUDED for maps in v1: the prim is
                    ;; left-biased, so at a colliding key the contribution
                    ;; carries whichever side arrived first through the
                    ;; iteration schedule, not the pointwise join -- the
                    ;; fixpoint would be timing-dependent.  cget is also
                    ;; deferred (it faults on a not-yet-present key, and the
                    ;; chas guard is later-stratum only); in-SCC element
                    ;; access is M2.4's R_has decomposition.
                    [(map)
                     (and (eq? f 'cput) (taint-only-at? 0) spec)]
                    [else #f]))
                (unless out-spec
                  (die "primitive (~a ~a) is not a whitelisted monotone transfer for a still-ascending (~a ...) value"
                       f (string-join (map symbol->string args) " ") kind))
                (hash-set taint x (list out-spec 'transfer cl))])]
            [_ taint])))
      (if (equal? taint+ taint) taint (loop taint+))))

  (define (tainted v) (hash-ref taint v #f))

  ;; ---- rebinding lets: (let V rhs) with V lattice-bound is the
  ;; planner's ==-check in disguise -- an equality guard on a live value.
  ;; Upward-closed cases: (= V (inf)) on count, (= V (top)) on flat.
  (for ([cl (in-list (append bodys heads))])
    (match cl
      [`(syn ,_ let ,x (syn ,_ ,f ,args ...))
       #:when (and (tainted x) (not (eq? (third (tainted x)) cl)))
       (define kind (lattice-spec-kind (first (tainted x))))
       (unless (or (and (eq? kind 'count) (eq? f 'inf) (null? args))
                   (and (eq? kind 'flat) (eq? f 'top) (null? args)))
         (die "equality test on still-ascending lattice value ~a is not upward-closed (only (= V (inf)) on count and (= V (top)) on flat are)"
              x))]
      [`(syn ,_ let ,x ,(? var? y))
       #:when (or (tainted x) (tainted y))
       (die "aliasing a still-ascending lattice value (~a) is not supported"
            (if (tainted x) x y))]
      [_ (void)]))

  ;; ---- guards --------------------------------------------------------
  (for ([cl (in-list bodys)])
    (match cl
      [`(syn ,_ /= ,x ,y)
       (for ([v (in-list (list x y))] #:when (tainted v))
         (die "(/= ... ~a ...): disequality on a still-ascending lattice value is not upward-closed"
              v))]
      [`(syn ,_ ,(? primitive-cmp? op) ,x ,y)
       (define tx (tainted x))
       (define ty (tainted y))
       (when (and tx ty)
         (die "(~a ~a ~a): comparing two still-ascending lattice values is not upward-closed"
              op x y))
       (for ([(v t v-side) (in-parallel (list x y) (list tx ty) (list 'left 'right))]
             #:when t)
         (define kind (lattice-spec-kind (first t)))
         (define ok?
           (case kind
             ;; min: ascent = numeric descent, so V may only be bounded above
             [(min) (if (eq? v-side 'left) (memq op '(< <=)) (memq op '(> >=)))]
             [(max) (if (eq? v-side 'left) (memq op '(> >=)) (memq op '(< <=)))]
             [else #f]))
         (unless ok?
           (die "(~a ~a ~a): not an upward-closed guard for the still-ascending (~a ...) value ~a"
                op x y kind v)))]
      [_ (void)]))

  ;; ---- joins and head emissions --------------------------------------
  ;; every remaining use of a tainted variable must be a contribution to a
  ;; matching lattice head's value position
  (define (check-join cl head?)
    (match (join-parts cl)
      [(list name args struct?)
       (define spec (spec-of name))
       (for ([a (in-list args)] [i (in-naturals)] #:when (tainted a))
         (define t (tainted a))
         (define value-pos? (and spec (not struct?) (= i (sub1 (length args)))))
         (cond
           [struct?
            (die "still-ascending lattice value ~a cannot appear in struct ~a: interned content must be final"
                 a name)]
           [(and head? value-pos?)
            (unless (equal? spec (first t))
              (die "contributing ~a to lattice relation ~a: source lattice ~a does not match target ~a"
                   a name (first t) spec))]
           [(and (not head?) value-pos? (eq? 'seed (second t))
                 (set-member? dynamic-rels name))
            (void)] ; the seeding read itself
           [head?
            (die "still-ascending lattice value ~a cannot be emitted into ~a position ~a: only a lattice value column may receive it"
                 a name i)]
           [else
            (die "still-ascending lattice value ~a cannot be used as a join key (relation ~a): its match set could shrink as the value ascends"
                 a name)]))]
      [_ (void)]))
  (for ([cl (in-list bodys)]) (check-join cl #f))
  (for ([cl (in-list heads)]) (check-join cl #t))

  ;; a tainted variable seeded by one read but read again in another body
  ;; join is caught above; what remains is (top) landing somewhere sensible:
  ;; a flat value column or an equality with a flat variable
  (for ([cl (in-list heads)])
    (match (join-parts cl)
      [(list name args #f)
       (for ([a (in-list args)] [i (in-naturals)])
         (define c (hash-ref lat-const-env a #f))
         (define spec (spec-of name))
         (define value-pos? (and spec (= i (sub1 (length args)))))
         (when (and c (not (and value-pos?
                                (case c
                                  [(top) (eq? 'flat (lattice-spec-kind spec))]
                                  [(one inf) (eq? 'count (lattice-spec-kind spec))]))))
           (die "lattice constant (~a) can only be contributed to a matching lattice value column, not ~a position ~a"
                c name i)))]
      [_ (void)])))

;; ---- termination warning (§5.5) ---------------------------------------
;; A min/max lattice without a floor/ceiling that some in-SCC rule feeds
;; through a genuine transfer can descend forever (the negative-cycle
;; problem); warn once per relation.

(define (warn-unbounded-recursion rules rel-env spec-of dynamic-rels)
  (define warned (mutable-set))
  (for ([rule (in-list rules)])
    (match-define `(syn ,_ rule ,bodys ... --> ,heads ...) rule)
    ;; tainted-by-transfer variables, cheaply recomputed: a let over a
    ;; seeded lattice variable (the full check already validated it)
    (define seeds
      (for/fold ([s (hash)]) ([cl (in-list bodys)])
        (match (join-parts cl)
          [(list name args #f)
           #:when (and (spec-of name) (set-member? dynamic-rels name))
           (hash-set s (last args) (spec-of name))]
          [_ s])))
    (define transferred
      (let loop ([t (hash)])
        (define t+
          (for/fold ([t t]) ([cl (in-list (append bodys heads))])
            (match cl
              [`(syn ,_ let ,x (syn ,_ ,f ,args ...))
               (define spec
                 (for/first ([a (in-list args)]
                             #:when (or (hash-ref seeds a #f) (hash-ref t a #f)))
                   (or (hash-ref seeds a #f) (hash-ref t a #f))))
               (if (and spec (not (hash-has-key? t x))) (hash-set t x spec) t)]
              [_ t])))
        (if (equal? t t+) t (loop t+))))
    (for ([cl (in-list heads)])
      (match (join-parts cl)
        [(list name args #f)
         #:when (spec-of name)
         (define spec (spec-of name))
         (define kind (lattice-spec-kind spec))
         (define v (last args))
         (when (and (memq kind '(min max))
                    (not (lattice-spec-param spec (if (eq? kind 'min) 'floor 'ceiling)))
                    (hash-ref transferred v #f)
                    (not (set-member? warned name)))
           (set-add! warned name)
           (eprintf "lattice-check: warning: relation ~a over ~a is recursive through an arithmetic transfer without #:~a -- termination is the program's obligation (unbounded ~a, the negative-cycle analogue)\n"
                    name spec (if (eq? kind 'min) 'floor 'ceiling)
                    (if (eq? kind 'min) "descent" "ascent")))
         ;; growing collections have no static height bound: a single run
         ;; terminates because the Herbrand universe is finite (§8.1) --
         ;; admit, but say so once
         (when (and (memq kind '(set map))
                    (hash-ref transferred v #f)
                    (not (set-member? warned name)))
           (set-add! warned name)
           (eprintf "lattice-check: warning: relation ~a over ~a grows through in-SCC transfers; it terminates only because the value universe of a run is finite (docs/primitives.md §8.1)\n"
                    name spec))]
        [_ (void)]))))
