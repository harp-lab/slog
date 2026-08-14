#lang racket
;; The activation spine, slice A1 (docs/activation-contract.md §2-§3):
;; parse a frozen ProgramChangeSet fixture and resolve it against a base
;; environment into an ActivationPlan -- successor identities minted, slot
;; lineage accepted, the route chosen -- with every validation refusal
;; TYPED and fired before any live state could be touched.  No daemon
;; contact anywhere in this module: the session supplies a base-env from
;; its catalog (slice A2) and executes the plan; the golden corpus
;; (tests/activation/*.pcs) supplies fixtures until the program arc's
;; compiler producer exists, exactly as roadmap §6 planned the handoff.
;;
;; The three fixture rules, enforced here (rf5-contract §10.1): no live
;; VersionIds, maintenance routes, or publication decisions inside the
;; fixture; no inferred lineage -- every old/new correspondence is
;; explicit or absent; compiler-known refusals ride along typed.

(require racket/match
         "catalog.rkt")   ; the m1:/r1:/scc1:/v1: constructors (T0(c) c1)

(provide (struct-out change-set)
         (struct-out base-env)
         (struct-out activation-plan)
         parse-change-set
         resolve-activation
         activation-refusal?)

;; ---------------------------------------------------------------------------
;; Shapes
;; ---------------------------------------------------------------------------

(struct change-set
  (base-program base-boundary          ; the named base identities
   candidate                           ; (image compiler plan-abi sources)
   occurrences                         ; ((old-mkey new-slot-path home) ...)
   rule-lineage                        ; ((old-rkey|#f unit.rule-slot) ...)
   slot-lineage                        ; ((qname old-vkey disposition) ...)
   diffs writers-old writers-new
   sccs-new                            ; ((slot level (members ...)) ...)
   affected-roots affected-cone
   services suffix refusals)
  #:transparent)

;; What the session derives from its catalog for the selected base boundary.
;;   versions : qname symbol -> committed VersionKey string
;;   services : the symbols this daemon can serve
(struct base-env (program-key boundary-key tip? versions services)
  #:transparent)

(struct activation-plan
  (program-key                         ; the successor ProgramInstanceKey
   module-keys                         ; old-mkey -> new ModuleInstanceKey
   rule-keys                           ; (new RuleKey ...) in lineage order
   scc-keys                            ; ((SccInstanceKey slot level members) ...)
   version-allocs                      ; qname -> (old|#f new|carried disposition)
   suffix                              ; accepted mapped batch events
   route                               ; 'correctness-first (the v1 route)
   publication)                        ; 'hold-at-gate (abort always available)
  #:transparent)

(define (activation-refusal? v)
  (match v [`(refused ,(? symbol?) ,_ ...) #t] [_ #f]))

(define (refuse type . detail) `(refused ,type ,@detail))

;; ---------------------------------------------------------------------------
;; Parse: datum -> change-set | (refused malformed-change-set ...)
;; ---------------------------------------------------------------------------

(define (field parts key)
  (for/or ([p (in-list parts)])
    (match p [(cons (== key) rest) rest] [_ #f])))

;; The closed section vocabulary (rf5 §10.1's fixture rules: nothing else
;; rides along -- in particular no live VersionIds, route, or publication
;; field).  A typo'd or forbidden section is a hard refusal, never a silent
;; empty default: a fixture's whole intent must not vanish because a
;; section name was misspelled.
(define known-sections
  '(base candidate occurrences rule-lineage slot-lineage
    diffs writers sccs affected services suffix refusals))

;; "U.R" -- two non-negative integers.  Validated at parse so a dotless or
;; non-numeric slot refuses typed here rather than crashing resolve with a
;; raw `second:`/`string->number` error outside session-activate!'s handler.
(define (rule-slot-parts who slot)
  (define text (format "~a" slot))
  (define parts (string-split text "."))
  (unless (and (= 2 (length parts))
               (andmap (lambda (p) (regexp-match? #px"^[0-9]+$" p)) parts))
    (error (format "~a: slot must be U.R (two integers), got ~a" who slot)))
  text)

(define (parse-change-set datum)
  (with-handlers ([exn:fail? (lambda (e)
                               (refuse 'malformed-change-set (exn-message e)))])
    (match datum
      [`(program-change-set (abi 1) ,parts ...)
       (for ([p (in-list parts)])
         (define key (and (pair? p) (car p)))
         (unless (memq key known-sections)
           (error (format "unknown section ~a (allowed: ~a)"
                          (if key p key) known-sections))))
       (let ([seen (make-hasheq)])
         (for ([p (in-list parts)])
           (when (hash-ref seen (car p) #f)
             (error (format "duplicate section ~a" (car p))))
           (hash-set! seen (car p) #t)))
       (define (need key)
         (or (field parts key)
             (error (format "missing (~a ...)" key))))
       (match-define `((program ,pkey) (boundary ,bkey)) (need 'base))
       (define occurrences
         (for/list ([o (in-list (or (field parts 'occurrences) '()))])
           (match o
             [`(replace (old ,mkey) (new-slot ,slots) (home ,home))
              (list (format "~a" mkey) slots home)]
             [_ (error (format "malformed occurrence: ~a" o))])))
       (define rule-lineage
         (for/list ([r (in-list (or (field parts 'rule-lineage) '()))])
           (match r
             [`((old ,old) (new-slot ,slot))
              (list (and (not (eq? old '#f)) (format "~a" old))
                    (rule-slot-parts "rule lineage" slot))]
             [_ (error (format "malformed rule lineage: ~a" r))])))
       (define slot-lineage
         (for/list ([sl (in-list (or (field parts 'slot-lineage) '()))])
           (match sl
             [`((relation ,q) (old ,v) (disposition ,d))
              #:when (memq d '(carry rebuild retire))
              (list q (and (not (eq? v '#f)) (format "~a" v)) d)]
             [_ (error (format "malformed slot lineage: ~a" sl))])))
       (define (writer-list side raw)
         (unless (and (list? raw) (andmap symbol? raw))
           (error (format "~a writers must be a list of relation symbols, got ~a"
                          side raw)))
         raw)
       (define-values (writers-old writers-new)
         (match (field parts 'writers)
           [#f (values '() '())]
           [`((old ,o) (new ,n))
            (values (writer-list "old" o) (writer-list "new" n))]
           [other (error (format "malformed writers: ~a" other))]))
       (define-values (affected-roots affected-cone)
         (match (field parts 'affected)
           [#f (values '() '())]
           [`((roots ,r) (cone ,c)) (values r c)]
           [other (error (format "malformed affected: ~a" other))]))
       (change-set
        (format "~a" pkey) (format "~a" bkey)
        (field parts 'candidate)
        occurrences rule-lineage slot-lineage
        (field parts 'diffs)
        writers-old writers-new
        (for/list ([s (in-list (match (field parts 'sccs)
                                 [#f '()]
                                 [`((old ,_) (new ,n)) n]
                                 [other (error (format "malformed sccs: ~a" other))]))])
          (match s [`(scc ,slot ,level (members ,m ...)) (list slot level m)]
                   [_ (error (format "malformed scc: ~a" s))]))
        affected-roots affected-cone
        (or (field parts 'services) '())
        (or (field parts 'suffix) '())
        (or (field parts 'refusals) '()))]
      [_ (refuse 'malformed-change-set "not a (program-change-set (abi 1) ...)")])))

;; ---------------------------------------------------------------------------
;; Resolve: change-set × base-env -> activation-plan | typed refusal
;;
;; Deterministic: the same fixture, environment, and layer/event mint the
;; same plan -- the property the corpus battery pins, and the reason replay
;; can re-derive rather than persist (the c1 doctrine).
;; ---------------------------------------------------------------------------

(define (resolve-activation cs env #:layer layer #:event event)
  (cond
    ;; 0. a fixture that carries compiler refusals never touches state
    [(pair? (change-set-refusals cs))
     (refuse 'fixture-refusal (first (change-set-refusals cs)))]
    ;; 1. the named base must be THIS boundary, and it must be the tip
    [(not (equal? (change-set-base-boundary cs) (base-env-boundary-key env)))
     (refuse 'unknown-base-boundary (change-set-base-boundary cs))]
    [(not (equal? (change-set-base-program cs) (base-env-program-key env)))
     (refuse 'unknown-base-boundary (change-set-base-program cs))]
    [(not (base-env-tip? env))
     (refuse 'stale-base (base-env-boundary-key env))]
    ;; 2. every replaced occurrence must belong to the base program.  The
    ;; trailing ':' matters -- without it p1:layer:1 would accept an
    ;; occurrence of p1:layer:10 (any longer-key sibling).
    [(for/or ([o (in-list (change-set-occurrences cs))])
       (and (not (string-prefix? (first o)
                                 (format "m1:~a:" (base-env-program-key env))))
            (first o)))
     => (lambda (bad) (refuse 'unknown-occurrence bad))]
    ;; 2b. slot-lineage names each relation at most once.  Two rows for one
    ;; relation make disposition order-dependent: suffix admission reads the
    ;; first, version-allocs the last, so a `(carry)` then `(retire)` pair
    ;; would admit a batch against a relation the plan actually retires.
    [(let ([seen (make-hash)])
       (for/or ([sl (in-list (change-set-slot-lineage cs))])
         (define rel (first sl))
         (begin0 (and (hash-ref seen rel #f) rel)
           (hash-set! seen rel #t))))
     => (lambda (bad) (refuse 'slot-lineage-conflict `(duplicate ,bad)))]
    ;; 3. carried/retired slots must exist at the base boundary
    [(for/or ([sl (in-list (change-set-slot-lineage cs))])
       (and (memq (third sl) '(carry retire))
            (not (hash-ref (base-env-versions env) (first sl) #f))
            (first sl)))
     => (lambda (bad) (refuse 'slot-lineage-conflict bad))]
    ;; 3b. a `retire` disposition (a relation the candidate drops entirely)
    ;; needs the correctness-first route to advance the relation to an empty
    ;; successor.  That retirement heal is unimplemented: the live route only
    ;; rebuilds relations the CANDIDATE writes, so a dropped relation would
    ;; silently CARRY its stale materialization into the new boundary.
    ;; Refuse typed rather than leak (rf5 §5's "materialization loses tuples"
    ;; is the intended behavior; delivering it is a later RF5 slice).
    [(for/or ([sl (in-list (change-set-slot-lineage cs))])
       (and (eq? (third sl) 'retire) (first sl)))
     => (lambda (bad) (refuse 'retirement-unsupported bad))]
    ;; 4. required services must be servable
    [(for/or ([svc (in-list (change-set-services cs))])
       (and (not (memq svc (base-env-services env))) svc))
     => (lambda (bad) (refuse 'unsupported-service bad))]
    ;; 5. the v1 suffix admission (rf5 §8): input batches with unique,
    ;;    carried anchors map; any program/attach/rename/drop event refuses
    [(for/or ([ev (in-list (change-set-suffix cs))])
       (match ev
         [`(batch ,rel ,_ ...)
          (and (not (eq? 'carry
                         (for/or ([sl (in-list (change-set-slot-lineage cs))])
                           (and (eq? (first sl) rel) (third sl)))))
               ev)]
         [_ ev]))
     => (lambda (bad) (refuse 'historical-program-replacement bad))]
    [else
     (define pkey (program-key layer event))
     (define module-keys
       (for/hash ([o (in-list (change-set-occurrences cs))])
         (values (first o)
                 (module-instance-key pkey (second o)))))
     ;; v1 rule lineage scopes to a SINGLE replaced occurrence: the new U.R
     ;; slot names a rule within that one module.  With two or more
     ;; occurrences the fixture grammar has no mkey coordinate to
     ;; disambiguate "0.0" across modules, so minting RuleKeys would
     ;; fabricate collisions under one arbitrary module.  Those keys have no
     ;; live consumer yet; rather than mint colliding identities (or refuse
     ;; a legitimate whole-program two-instance diff), leave rule-keys empty
     ;; until the grammar grows a module coordinate.  The diagnostic
     ;; rule-lineage still rides in the fixture.
     (define rule-keys
       (cond
         [(= 1 (hash-count module-keys))
          (define mkey (for/first ([(k v) (in-hash module-keys)]) v))
          (for/list ([r (in-list (change-set-rule-lineage cs))])
            ;; parse already validated the two-integer "U.R" shape
            (define parts (string-split (second r) "."))
            (rule-key mkey
                      (string->number (first parts))
                      (string->number (second parts))))]
         [else '()]))
     (define scc-keys
       (for/list ([s (in-list (change-set-sccs-new cs))])
         (list (scc-instance-key pkey (first s))
               (first s) (second s) (third s))))
     ;; fresh slots for every REBUILt writer, in one deterministic order;
     ;; carries keep the committed VersionKey the env names
     ;; every union writer PLUS every slot-lineage relation: a carried
     ;; non-writer (the untouched instance's slots) gets an explicit reuse
     ;; row, which is how the RF5-B gate's outside-cone claim becomes
     ;; checkable rather than implicit
     (define union-writers
       (sort (remove-duplicates
              (append (change-set-writers-old cs)
                      (change-set-writers-new cs)
                      (map first (change-set-slot-lineage cs))))
             symbol<?))
     (define dispositions
       (for/hash ([sl (in-list (change-set-slot-lineage cs))])
         (values (first sl) (third sl))))
     (define version-allocs
       (for/hash ([w (in-list union-writers)] [slot (in-naturals)])
         (define disp (hash-ref dispositions w 'rebuild))
         (values w
                 (list (hash-ref (base-env-versions env) w #f)
                       (case disp
                         [(carry) (hash-ref (base-env-versions env) w)]
                         [(rebuild) (version-key layer event slot)]
                         [(retire) #f])
                       disp))))
     (activation-plan pkey module-keys rule-keys scc-keys version-allocs
                      (change-set-suffix cs)
                      'correctness-first 'hold-at-gate)]))
