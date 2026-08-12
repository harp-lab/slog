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

(define (field parts key [default #f])
  (for/or ([p (in-list parts)])
    (match p [(cons (== key) rest) rest] [_ #f]))
  )

(define (parse-change-set datum)
  (with-handlers ([exn:fail? (lambda (e)
                               (refuse 'malformed-change-set (exn-message e)))])
    (match datum
      [`(program-change-set (abi 1) ,parts ...)
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
                    (format "~a" slot))]
             [_ (error (format "malformed rule lineage: ~a" r))])))
       (define slot-lineage
         (for/list ([sl (in-list (or (field parts 'slot-lineage) '()))])
           (match sl
             [`((relation ,q) (old ,v) (disposition ,d))
              #:when (memq d '(carry rebuild retire))
              (list q (and (not (eq? v '#f)) (format "~a" v)) d)]
             [_ (error (format "malformed slot lineage: ~a" sl))])))
       (define writers (or (field parts 'writers) '()))
       (change-set
        (format "~a" pkey) (format "~a" bkey)
        (field parts 'candidate)
        occurrences rule-lineage slot-lineage
        (field parts 'diffs)
        (match writers [`((old ,o) (new ,_)) o] [_ '()])
        (match writers [`((old ,_) (new ,n)) n] [_ '()])
        (for/list ([s (in-list (match (field parts 'sccs)
                                 [`((old ,_) (new ,n)) n]
                                 [#f '()] [other other]))])
          (match s [`(scc ,slot ,level (members ,m ...)) (list slot level m)]
                   [_ (error (format "malformed scc: ~a" s))]))
        (match (field parts 'affected) [`((roots ,r) (cone ,_)) r] [_ '()])
        (match (field parts 'affected) [`((roots ,_) (cone ,c)) c] [_ '()])
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
    ;; 2. every replaced occurrence must belong to the base program
    [(for/or ([o (in-list (change-set-occurrences cs))])
       (and (not (string-prefix? (first o)
                                 (format "m1:~a" (base-env-program-key env))))
            (first o)))
     => (lambda (bad) (refuse 'unknown-occurrence bad))]
    ;; 3. carried/retired slots must exist at the base boundary
    [(for/or ([sl (in-list (change-set-slot-lineage cs))])
       (and (memq (third sl) '(carry retire))
            (not (hash-ref (base-env-versions env) (first sl) #f))
            (first sl)))
     => (lambda (bad) (refuse 'slot-lineage-conflict bad))]
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
     (define rule-keys
       (for/list ([r (in-list (change-set-rule-lineage cs))])
         ;; the new slot is "U.R" within its occurrence; v1 fixtures scope
         ;; lineage to the single replaced occurrence -- multi-occurrence
         ;; lineage rides the same slot spelling with an explicit mkey
         (match-define (list u-dot-r) (list (second r)))
         (define parts (string-split u-dot-r "."))
         (rule-key (if (= 1 (hash-count module-keys))
                       (for/first ([(k v) (in-hash module-keys)]) v)
                       (module-instance-key pkey '()))
                   (string->number (first parts))
                   (string->number (second parts)))))
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
