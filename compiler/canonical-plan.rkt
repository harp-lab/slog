#lang racket

;; Canonical KernelPlan pass (docs/execution-tiers.md §4/§11 T1; decisions
;; D3-D6 in docs/execution-tiers-impl.md §2).
;;
;; Consumes one stratum's cprog (build-cprog output) and produces the
;; deterministic, edit-stable lowered plan: dense registers, relation and
;; constant slots, RuleId/VariantTag identities, and a canonical
;; serialization whose sha256 is the KernelPlanKey.  T1 scope: the plan is a
;; parallel artifact (build/<hash>.plan, written by emit-stratum-cpp beside
;; the .cprog) -- emit-cpp's generated C++ is unchanged, and in particular
;; bumpFires keeps its aggregated (loc, base-tag) key, which is the
;; exact-once audit's documented unit (emit-cpp.rkt "Same-driver variants of
;; one rule share a key").  Disaggregated identity lives here.
;;
;; Identity model (docs/execution-tiers.md §2.1):
;;   rid          dense per source rule, grouped by crule loc ("file:line");
;;                every #f-loc crule is its own rid.  Two source rules on one
;;                line would merge -- deterministic but muddled; the durable
;;                RuleKey (T0) subsumes this.
;;   VariantTag   emit-cpp's base tag (once | seeded | all:<rel> |
;;                delta:<rel>, by dynamic-rels membership), "#<ordinal>"
;;                suffixed IFF the (rid, base) group has several variants
;;                (D3: a recursive rule's exact-semi-naive versions share a
;;                driver tag), "/<kind>" suffixed in count flavors.
;;
;; Determinism is by construction (D4): every unordered container is sorted
;; here -- decls and crules by canonical serialization, constants by global
;; name, dynamic rels and prims by symbol -- so the printed plan is
;; byte-stable across processes AND stable under unrelated program edits
;; (unlike set/hash iteration order, which is content-chaotic).

(provide crule-head-rels crule-body-rels resolve-temp-sccs crule-kernel
         kernel-exec-key canonicalize-cprog/abi2
         cohort->kernel-plans     ; ABI-2 cohort -> ABI-1-equivalent views
         plan-artifact->kernel-plans ; either shape -> list of kernel-plans
         validate-kernel-attributes! validate-rule-attrs!  ; RF1 slice 3
         canonicalize-cprog       ; cprog [#:flavor sym] -> kernel-plan
         canonicalize-cprog/tags  ; ... -> (values kernel-plan crule->rid.tag)
         canonical-rule-tags      ; cprog -> (listof (cons rid tag)),
                                  ;   aligned with (cprog-rules cprog)
         kernel-plan->string      ; single-line deterministic serialization
         kernel-plan-key)         ; sha256 hex of that serialization

(require racket/set
         sha
         "ir-stack.rkt"
         (only-in "params.rkt" semijoin-filters-enabled)  ; RF1 slice 3
         (only-in "ir-shared.rkt"          ; RF1 slice 1's ProgramModel
                  program-model-scc-of program-model-scc-members))

;; ------------------------------------------------------------------------
;; Deterministic total order on s-expressions.

(define (sexp->string x)
  (with-output-to-string (lambda () (write x))))

(define (sexp<? a b)
  (string<? (sexp->string a) (sexp->string b)))

;; "file:line" -> (list file line-number) for rid ordering; #f locs sort
;; after every located rule (each as its own rid, in canonical rule order).
(define (loc-key loc)
  (match (and loc (regexp-match #rx"^(.*):([0-9]+)$" loc))
    [(list _ file line) (list file (string->number line))]
    [_ (list (or loc "") 0)]))

(define (loc-key<? a b)
  (match-define (list fa la) a)
  (match-define (list fb lb) b)
  (or (string<? fa fb) (and (string=? fa fb) (< la lb))))

;; ------------------------------------------------------------------------
;; Per-crule canonicalization: rewrite every value-ref symbol to (r n) or
;; (k n), every relation name to (rel n), and collect prim names.  Value-ref
;; positions hold BOTH variables and globalized constants (globalize-
;; constants keys its hash value->name, so the name set distinguishes them).
;; Registers are dense in first-use order: pre ops, driver, body, head --
;; note pre runs BEFORE the driver (probe drivers key on constants loaded
;; there), so register 0 is not necessarily a driver column.

(define (canonicalize-crule cr const-slot rel-slot prim!)
  (define regs (make-hash))
  (define (ref! v)
    (cond [(const-slot v) => (lambda (k) `(k ,k))]
          [else `(r ,(hash-ref! regs v (lambda () (hash-count regs))))]))
  (define (refs* vs) (map ref! vs))
  (define (rel! name) `(rel ,(rel-slot name)))
  (define (op->canon op)
    (match op
      [`(join ,rel ,ord ,K ,xs ...)
       `(join ,(rel! rel) ,ord ,K ,@(refs* xs))]
      [`(join-old ,rel ,ord ,K ,dord ,xs ...)
       `(join-old ,(rel! rel) ,ord ,K ,dord ,@(refs* xs))]
      [`(join-new ,rel ,ord ,K ,dord ,xs ...)
       `(join-new ,(rel! rel) ,ord ,K ,dord ,@(refs* xs))]
      ;; M4S struct resolution probe (live master, then tombstones)
      [`(join-tomb ,rel ,ord ,K ,xs ...)
       `(join-tomb ,(rel! rel) ,ord ,K ,@(refs* xs))]
      [`(join3 ,cycle ,arms ...)
       `(join3 ,(ref! cycle)
               ,@(for/list ([arm (in-list arms)])
                   (match-define `(,view ,rel ,ord ,K ,dind ,ys ...) arm)
                   `(,view ,(rel! rel) ,ord ,K ,dind ,@(refs* ys))))]
      [`(exists ,rel ,ord ,K ,xs ...)
       `(exists ,(rel! rel) ,ord ,K ,@(refs* xs))]
      [`(absent ,rel ,ord ,K ,xs ...)
       `(absent ,(rel! rel) ,ord ,K ,@(refs* xs))]
      [`(,(and op (or 'absent-old 'absent-new 'absent-ever)) ,rel ,ord ,K ,dord ,xs ...)
       `(,op ,(rel! rel) ,ord ,K ,dord ,@(refs* xs))]
      [`(absent-lat ,rel ,ord ,K ,xs ...)
       `(absent-lat ,(rel! rel) ,ord ,K ,@(refs* xs))]
      [`(join-lat ,rel ,ord ,K ,xs ...)
       `(join-lat ,(rel! rel) ,ord ,K ,@(refs* xs))]
      [`(let ,x (,f ,ys ...))
       (prim! f)
       `(let ,(ref! x) (prim ,f ,@(refs* ys)))]
      [`(let ,x ,y) `(let ,(ref! x) ,(ref! y))]
      [`(letp ,x (,f ,ys ...))
       (prim! f)
       `(letp ,(ref! x) (prim ,f ,@(refs* ys)))]
      [`(cjoin ,x ,spec ,a ,b)
       `(cjoin ,(ref! x) ,spec ,(ref! a) ,(ref! b))]
      [`(eq ,x ,y) `(eq ,(ref! x) ,(ref! y))]
      [`(neq ,x ,y) `(neq ,(ref! x) ,(ref! y))]
      [`(cmp ,f ,x ,y)
       (prim! f)
       `(cmp ,f ,(ref! x) ,(ref! y))]))
  (define (hop->canon op)
    (match op
      [`(mkstruct ,rel ,ord ,x ,fields ...)
       `(mkstruct ,(rel! rel) ,ord ,(ref! x) ,@(refs* fields))]
      [`(emit ,rel ,ord ,xs ...) `(emit ,(rel! rel) ,ord ,@(refs* xs))]
      [`(emit-temp ,rel ,xs ...) `(emit-temp ,(rel! rel) ,@(refs* xs))]
      [`(emit-lat ,rel ,xs ...) `(emit-lat ,(rel! rel) ,@(refs* xs))]
      [`(tycheck ,x (accept ,ts ...) ,rid ,rel ,col ,ord)
       `(tycheck ,(ref! x) (accept ,@ts)
                 ,(ref! rid) ,(ref! rel) ,(ref! col) ,ord)]
      [_ (op->canon op)]))
  (define (driver->canon d)
    (match d
      [`(scan ,rel ,xs ...) `(scan ,(rel! rel) ,@(refs* xs))]
      [`(probe ,rel ,ord ,K ,xs ...)
       `(probe ,(rel! rel) ,ord ,K ,@(refs* xs))]
      [d d]))
  (define pre (map op->canon (crule-pre cr)))
  (define driver (driver->canon (crule-driver cr)))
  (define body (map op->canon (crule-body cr)))
  (define head (map hop->canon (crule-head cr)))
  `((nregs ,(hash-count regs))
    (pre ,@pre)
    (driver ,driver)
    (body ,@body)
    (head ,@head)))

;; ------------------------------------------------------------------------
;; RF1 slice 2: the kernel partition (docs/rf1-contract.md Slices item 2).
;;
;; A kernel is a MODULE-SCC, not a runtime stratum: the stratum is a
;; scheduling container that may group independent same-level SCCs, so a
;; stratum-shaped code unit's content depends on what else shares its level
;; (t4-contract B2).  Each crule joins the kernel of its head's SCC, which
;; is what the ProgramModel carries out of stratification.
;;
;; STAGING TEMPS are the wrinkle.  A multi-level planned rule lowers to a
;; chain -- one crule emits into `temp<f><l>x<n>`, a follow-up scans that
;; temp and emits the real head -- and temps do not exist in the model,
;; which was built over the typed rules before planning.  Resolving a temp
;; by LOCATION would work but would tie the partition to DebugMap data, so
;; instead a temp inherits the SCC of whatever consumes it, to a fixpoint
;; (temp -> temp chains occur at three-way joins).  That is structural: the
;; same answer under any renaming.
(define (crule-head-rels cr)
  (filter values
          (for/list ([h (in-list (crule-head cr))])
            (match h
              [`(emit ,rel ,_ ...) rel]
              [`(emit-temp ,rel ,_ ...) rel]
              [`(emit-lat ,rel ,_ ...) rel]
              [`(mkstruct ,rel ,_ ...) rel]
              [_ #f]))))

;; Every relation a crule references, from EVERY position that can hold one.
;; Getting this wrong is a loud failure -- `rel-slot` raises "unslotted
;; relation X in kernel" -- and two positions were missing at first:
;;
;;  - `pre` ops.  Prefilters (`exists`/`absent` hoisted before the driver)
;;    reference relations exactly as body filters do; walking only driver and
;;    body missed them (neg_wild, seq_oracle).
;;  - `join3` ARMS.  A WCOJ3 intersection carries its two arms as
;;    `(view REL ord K dind regs ...)` nested inside the op, so the relation
;;    is not in position 1 of the form itself (sj_tri).
(define (crule-op-rels op)
  (match op
    [`(,(or 'join 'join-old 'join-new 'join-tomb 'join-lat
            'exists 'absent 'absent-old 'absent-new 'absent-ever 'absent-lat)
       ,rel ,_ ...)
     (list rel)]
    [`(join3 ,_cycle ,arms ...)
     (for/list ([arm (in-list arms)])
       (match arm [`(,_view ,rel ,_ ...) rel] [_ #f]))]
    [_ '()]))

(define (crule-body-rels cr)
  (filter values
          (append
           (list (match (crule-driver cr)
                   [`(scan ,rel ,_ ...) rel]
                   [`(probe ,rel ,_ ...) rel]
                   [_ #f]))
           (append* (map crule-op-rels (crule-pre cr)))
           (append* (map crule-op-rels (crule-body cr))))))

;; temp name -> scc id, by inheriting from consumers until nothing moves.
;; The loop needs no fuel: the map only ever GROWS (a temp is assigned once,
;; never reassigned) and is bounded by the temp count, so the fixpoint
;; arrives in at most one pass per link of the longest temp -> temp chain.
;; An early draft capped it at 32 passes and returned the partial map
;; SILENTLY on exhaustion -- and a temp missing from this map sends its
;; crules to the prelude kernel with no error, which is a mis-partition
;; (wrong sharing, and the prelude key stops being the universal one).
;; crule-kernel now guards that exit loudly instead.
(define (resolve-temp-sccs crules scc-of temp?)
  (let loop ([acc (hash)])
    (define next
      (for/fold ([a acc]) ([cr (in-list crules)])
        (define heads (crule-head-rels cr))
        ;; the SCC this crule belongs to, if already known
        (define known
          (for/or ([h (in-list heads)])
            (if (temp? h) (hash-ref a h #f) (hash-ref scc-of h #f))))
        (cond
          [(not known) a]
          ;; every temp this crule READS belongs to the same kernel
          [else
           (for/fold ([a a]) ([b (in-list (crule-body-rels cr))])
             (if (and (temp? b) (not (hash-ref a b #f)))
                 (hash-set a b known)
                 a))])))
    (if (equal? next acc) next (loop next))))

;; crule -> kernel id, or #f when its head SCC cannot be resolved (the
;; error-arm/internal prelude; rf1-contract puts the error-struct prelude in
;; the cohort manifest rather than in a kernel).
;; WELL-DEFINED because of a deliberate property of stratify's graph: `edges`
;; links every PAIR of a rule's heads (stratify.rkt, "from body to head and
;; among heads"), since a rule writing several relations cannot be stratified
;; between them.  So all heads of a rule share one SCC, and "the first
;; resolvable head" is not an arbitrary choice among candidates -- there is
;; only ever one answer.  (Observed as `(members right.edge seed)` for a
;; ground rule writing both, which is correct rather than a merge bug.)
(define (crule-kernel cr scc-of temp-scc temp?)
  (or (for/or ([h (in-list (crule-head-rels cr))])
        (if (temp? h) (hash-ref temp-scc h #f) (hash-ref scc-of h #f)))
      ;; #f is a LEGITIMATE answer only for the synthesized error arms,
      ;; whose (non-temp) heads are minted after stratification and so are
      ;; in no SCC.  A TEMP head that failed to resolve means no consumer
      ;; chain reaches a real head -- a mis-partition that would otherwise
      ;; ride the prelude silently, so it fails here instead.
      (begin
        (for ([h (in-list (crule-head-rels cr))])
          (when (temp? h)
            (error 'canonicalize-cprog
                   "staging temp ~a resolves to no kernel (no consumer chain reaches a real head)"
                   h)))
        #f)))

;; The stat base tag, reproducing emit-cpp's convention exactly: scan/probe
;; drivers are "delta:<rel>" when the relation is stratum-dynamic and
;; "all:<rel>" otherwise (emit-cpp's static?); count-flavor kinds suffix.
(define (base-tag driver kind dynamic-rels)
  (define base
    (match driver
      [`(once) "once"]
      [`(seeded) "seeded"]
      [`(,_ ,name ,_ ...)
       (format "~a:~a"
               (if (set-member? dynamic-rels name) "delta" "all")
               name)]))
  (if kind (format "~a/~a" base kind) base))

;; ------------------------------------------------------------------------
;; The pass.

(define (canonicalize-cprog cp #:flavor [flavor 'normal])
  (define-values (kp _tags) (canonicalize-cprog/tags cp #:flavor flavor))
  kp)

(define (canonicalize-cprog/tags cp #:flavor [flavor 'normal])
  (define constants (cprog-constants cp))
  ;; globalize-constants keys value -> generated name; tolerate either
  ;; orientation (the generated name is always the symbol side)
  (define const-pairs                       ; (name . value), sorted by name
    (sort (for/list ([(k v) (in-hash constants)])
            (if (symbol? v) (cons v k) (cons k v)))
          symbol<? #:key car))
  (define const-ix
    (for/hash ([p (in-list const-pairs)] [i (in-naturals)])
      (values (car p) i)))
  (define (const-slot v) (hash-ref const-ix v #f))
  ;; storage decls take slots; oracle/seqindex decls reference existing
  ;; names and ride as raw attachments (T2's installer resolves them)
  (define all-decls (sort (cprog-decls cp) sexp<?))
  (define-values (storage attachments)
    (partition (lambda (d) (memq (car d) '(relation struct lattice temp)))
               all-decls))
  (define rel-ix
    (for/hash ([d (in-list storage)] [i (in-naturals)])
      (values (second d) i)))
  (define (rel-slot name)
    (or (hash-ref rel-ix name #f)
        (error 'canonicalize-cprog "unslotted relation ~a" name)))
  (define dynamic-rels (cprog-dynamic-rels cp))
  (define prim-names (mutable-set))
  (define (prim! f) (set-add! prim-names f))
  ;; canonicalize every crule, then sort by canonical text (edit-stable, D4)
  (define entries                    ; (vector crule canon tagbase loc canonstr)
    (for/list ([cr (in-list (cprog-rules cp))])
      (define canon (canonicalize-crule cr const-slot rel-slot prim!))
      (vector cr canon
              (base-tag (crule-driver cr) (crule-kind cr) dynamic-rels)
              (crule-loc cr)
              (sexp->string canon))))
  ;; The D4 order must be TOTAL over run-stable data (RF1 slice 0):
  ;; canonical text alone ties for alpha-equivalent crules from DIFFERENT
  ;; source rules, and a stable sort then preserves upstream set-iteration
  ;; order -- which varies run to run with gensym'd symbol spellings,
  ;; flipping the (rid, position) pairing between the tied entries
  ;; (measured: 7/500 suite plans churned this way).  Ties break by
  ;; location, then variant tag; entries equal in all three are
  ;; interchangeable (same text, same rid, ordinals cover the rest).
  (define (entry<? a b)
    (define sa (vector-ref a 4))
    (define sb (vector-ref b 4))
    (cond [(string<? sa sb) #t]
          [(string<? sb sa) #f]
          [else
           (define la (loc-key (vector-ref a 3)))
           (define lb (loc-key (vector-ref b 3)))
           (cond [(loc-key<? la lb) #t]
                 [(loc-key<? lb la) #f]
                 [else (string<? (vector-ref a 2) (vector-ref b 2))])]))
  (define sorted (sort entries entry<?))
  ;; rid assignment: located source rules in (file, line) order, then each
  ;; #f-loc crule as its own rid in canonical rule order
  (define located-locs
    (sort (remove-duplicates
           (filter values (map (lambda (e) (vector-ref e 3)) sorted)))
          loc-key<? #:key loc-key))
  (define loc->rid
    (for/hash ([loc (in-list located-locs)] [i (in-naturals)])
      (values loc i)))
  (define next-rid (box (length located-locs)))
  (define (rid-of e)
    (cond [(vector-ref e 3) => (lambda (loc) (hash-ref loc->rid loc))]
          [else (let ([r (unbox next-rid)])
                  (set-box! next-rid (add1 r))
                  r)]))
  (define with-rids                          ; (vector crule canon tag rid loc)
    (for/list ([e (in-list sorted)])
      (vector (vector-ref e 0) (vector-ref e 1) (vector-ref e 2)
              (rid-of e) (vector-ref e 3))))
  ;; ordinal suffix IFF a (rid, base-tag) group holds several variants (D3);
  ;; ordinals follow canonical rule order
  (define group-sizes (make-hash))
  (for ([e (in-list with-rids)])
    (define key (cons (vector-ref e 3) (vector-ref e 2)))
    (hash-update! group-sizes key add1 0))
  (define group-seen (make-hash))
  (define tagged                             ; (vector crule canon tag rid loc)
    (for/list ([e (in-list with-rids)])
      (define key (cons (vector-ref e 3) (vector-ref e 2)))
      (define tag
        (if (> (hash-ref group-sizes key) 1)
            (let ([n (hash-ref group-seen key 0)])
              (hash-set! group-seen key (add1 n))
              (format "~a#~a" (vector-ref e 2) n))
            (vector-ref e 2)))
      (vector (vector-ref e 0) (vector-ref e 1) tag
              (vector-ref e 3) (vector-ref e 4))))
  (define rule-defs
    (for/list ([e (in-list tagged)])
      `(rule-def (rid ,(vector-ref e 3)) (variant ,(vector-ref e 2))
                 ,@(vector-ref e 1))))
  (define metas
    (sort (remove-duplicates
           (for/list ([e (in-list tagged)])
             `(rule-meta (rid ,(vector-ref e 3))
                         (source ,(vector-ref e 4)))))
          < #:key (lambda (m) (second (second m)))))
  (values
   `(kernel-plan
     (abi 1)
     (flavor ,flavor)
     (relations
      ,@(for/list ([d (in-list storage)] [i (in-naturals)]) `(rel ,i ,d)))
     (attachments ,@attachments)
     (constants
      ,@(for/list ([p (in-list const-pairs)] [i (in-naturals)])
          `(k ,i ,(car p) ,(cdr p))))
     (prims ,@(sort (set->list prim-names) symbol<?))
     (dynamic ,@(sort (set->list dynamic-rels) symbol<?))
     (rules ,@rule-defs)
     (meta ,@metas))
   ;; crule -> (rid . tag), for callers aligning with cprog-rules order
   (for/hash ([e (in-list tagged)])
     (values (vector-ref e 0)
             (cons (vector-ref e 3) (vector-ref e 2))))))

;; (rid . tag) per crule, aligned with (cprog-rules cp).  Identical crules
;; (impossible from one planned-rule set, but harmless) share one entry.
(define (canonical-rule-tags cp #:flavor [flavor 'normal])
  (define-values (_plan tag-map) (canonicalize-cprog/tags cp #:flavor flavor))
  (for/list ([cr (in-list (cprog-rules cp))])
    (hash-ref tag-map cr)))

;; ------------------------------------------------------------------------
;; RF1 slice 2: ABI 2 emission -- the four-way split, per kernel.
;;
;; The artifact shape is selected at the ONE write site (compile.rkt's
;; plan-writing lambda; ABI 2 is the default since the flip, SLOG_PLAN_ABI=1
;; the escape hatch).  An earlier staging parameter, current-plan-abi, is
;; gone: it was never consulted -- the env var was always the switch.

;; Everything the executor binds and nothing else.  KEY = hash of this part
;; ALONE, so it is the identity of a computation rather than of a program at
;; a moment: kernel-local slots/constants/prims (no sibling dependence),
;; dense rule ordinals (no location dependence), slot-relative variants (no
;; name dependence).
(define (kernel-exec-key exec) (bytes->hex-string (sha256 (string->bytes/utf-8 (sexp->string exec)))))

;; ------------------------------------------------------------------------
;; RF1 slice 3: the closed plan-attribute vocabulary (rf1-contract.md,
;; "Flavored-plan attributes" -- the M4S resolution).  Attributes live in
;; the EXEC part and are hashed: they change executor behavior, so they are
;; identity.  The vocabulary is closed HERE at the writer -- the emitter
;; validates its own output, so drift is a compile error -- and the daemon's
;; cohort decoder rejects unknowns independently.
;;
;; ABSENT-WHEN-EMPTY, pinned: a kernel with no attributes emits no
;; (attributes ...) section and an unkinded rule no (attrs ...) field.
;; Consequence, deliberate: normal-flavor exec bytes -- and every normal
;; KernelPlanKey -- survive this slice unchanged; only flavored artifacts
;; churn, and those are recomputable caches (counts recount).  The
;; contract's own test language agrees: "normal-flavor plans carry none".
;;
;;  - no-semijoin-reopt: derived from the ACTUAL planning toggle
;;    (semijoin-filters-enabled), not from a flavor list -- so it can never
;;    drift from what planning did.  Count/maint3neg/maint4neg disable the
;;    toggle (compile.rkt); maint1 deliberately keeps lookahead, and the
;;    daemon's structural no-exists seal check is gated the same way.
;;  - (fold input|nonrec|rec): the per-rule prov-keyed count kind
;;    (ir-stack.rkt crule-kind), promoted out of the variant spelling so
;;    exec carries it first-class; the display tag's "/<kind>" suffix
;;    remains the DebugMap rendering of the same fact.
;;  - probe-only mkstruct is RESERVED, not emitted: it is an attribute on
;;    the mkstruct OP (m4s-contract.md owns the semantics); the spelling is
;;    pinned as `probe-only` so M4S cannot mint a second one.
(define kernel-attribute-vocabulary '(no-semijoin-reopt))
(define fold-kind-vocabulary '(input nonrec rec))
(define mkstruct-attribute-vocabulary '(probe-only))   ; reserved for M4S

(define (validate-kernel-attributes! attrs)
  (for ([a (in-list attrs)])
    (unless (memq a kernel-attribute-vocabulary)
      (error 'canonicalize-cprog
             "unknown kernel attribute ~a (closed vocabulary: ~a)"
             a kernel-attribute-vocabulary))))

(define (validate-rule-attrs! attrs)
  (for ([a (in-list attrs)])
    (match a
      [`(fold ,(? (lambda (k) (memq k fold-kind-vocabulary)))) (void)]
      [_ (error 'canonicalize-cprog
                "unknown rule attribute ~s (closed vocabulary: (fold ~a))"
                a fold-kind-vocabulary)])))

;; Name-blind AND variable-blind structural text of a crule, for the order
;; that drives slot assignment.  Both halves are load-bearing:
;;
;;  - VARIABLE-blind, because a cprog's crules carry gensym'd variable
;;    spellings (`__t*`) that churn run to run -- feeding raw crule forms to
;;    the order made the ORDER churn, and with it every slot assignment and
;;    kernel key (measured: two identical compiles disagreeing).  So the text
;;    comes from `canonicalize-crule`, which renumbers variables to (r n).
;;  - NAME-blind, because slot numbering must not depend on relation names:
;;    relations resolve to their name-STRIPPED declaration's index among the
;;    program's distinct SHAPES, not to a name-derived slot.
;;
;; Two rules over different relations of the SAME shape therefore tie, which
;; is intended: that tie is genuinely interchangeable for the exec bytes and
;; is broken (deterministically) by the caller's global-text.
(define (blind-crule-text cr decl-of decl-ix const-ix)
  (define (shape-slot name)
    (define d (hash-ref decl-of name #f))
    (if d (hash-ref decl-ix (cons (car d) (cddr d)) -1) -1))
  (sexp->string
   (canonicalize-crule cr
                       (lambda (v) (hash-ref const-ix v #f))
                       shape-slot
                       void)))

;; One kernel's exec/binding/debug triple.
(define (kernel-parts crules decl-of rid-of tag-of constants
                      global-text blind-text service-slots)
  ;; ORDER: name-blind structural text first, so slot assignment cannot
  ;; depend on names.  It must then be TOTAL, or the residual tie falls to
  ;; input order -- which is set-iteration order, varying run to run: the
  ;; exact trap slice 0.1 closed for the temp-mint walk (measured here as
  ;; two identical compiles disagreeing on a kernel key).  The first
  ;; tiebreak is `global-text`: the crule's canonical text under the
  ;; PROGRAM-GLOBAL slot map -- variable-blind (registers are already
  ;; renumbered) and run-stable, and it discriminates by relation identity.
  ;; Using names here is safe for the KEY because a tie on blind text means
  ;; the crules are structurally identical, so either order yields the SAME
  ;; exec text with the slot permutation landing in the binding schema,
  ;; which is exactly where names belong.
  ;;
  ;; Ties on BOTH texts still occur -- two alpha-equivalent rules over the
  ;; SAME relations (verify.slog's demand pair; also `|`-split derivatives)
  ;; -- and leaving them to the stable sort is the slice-0.1 defect met a
  ;; THIRD time: either order yields identical exec bytes (the ordinals are
  ;; positional over identical texts), but DebugMap pairs each ord with a
  ;; rid and a source, so the pairing followed set-iteration order and the
  ;; debug part churned run to run (measured: 7/506 ABI-2 plans, first
  ;; SLOG_PLAN_ABI=2 plan-determinism run, 2026-08-05).  The final tiebreak
  ;; is the RID WALK -- canonical-rule-tags is loc-tiebroken and run-stable,
  ;; and (rid, tag) is unique per crule (the daemon seal-checks exactly
  ;; that) -- which pins the ord <-> (rid, source, variant-ordinal) pairing
  ;; without putting location dependence into the exec bytes: it only ever
  ;; orders exec-identical rules.
  (define ordered
    (sort crules
          (lambda (a b)
            (define ta (blind-text a))
            (define tb (blind-text b))
            (cond [(string<? ta tb) #t]
                  [(string<? tb ta) #f]
                  [else
                   (define ga (global-text a))
                   (define gb (global-text b))
                   (cond [(string<? ga gb) #t]
                         [(string<? gb ga) #f]
                         [(< (rid-of a) (rid-of b)) #t]
                         [(< (rid-of b) (rid-of a)) #f]
                         [else (string<? (tag-of a) (tag-of b))])]))))
  ;; kernel-local slots, first-use over that order
  (define rel-order
    (append service-slots
            (for*/list ([cr (in-list ordered)]
                        [r (in-list (append (crule-body-rels cr)
                                            (crule-head-rels cr)))])
              r)))
  (define rel-ix
    (for/fold ([h (hash)]) ([r (in-list rel-order)])
      (if (hash-has-key? h r) h (hash-set h r (hash-count h)))))
  (define (rel-slot name)
    (or (hash-ref rel-ix name #f)
        (error 'canonicalize-cprog "unslotted relation ~a in kernel" name)))
  ;; kernel-local constants, first-use over the same order.
  ;;
  ;; `const-slot` is handed a value-ref SYMBOL that is either a variable or a
  ;; globalized constant NAME -- that ambiguity is the ir's own convention
  ;; (canonicalize-crule's ref!: the name set is what distinguishes them), so
  ;; the lookup must be by NAME.  Keying it by value instead returns #f for
  ;; every constant, and ref! then falls through to its register branch: the
  ;; constant silently degrades into `(let (r 0) (r 1))`, losing the value
  ;; and emitting nonsense.  (Caught by inspecting a plan that should have
  ;; had constants and did not; the key/binding gate cannot see semantics.)
  (define const-value                    ; globalized NAME -> value
    (for/fold ([h (hash)]) ([(k v) (in-hash constants)])
      (if (symbol? v) (hash-set h v k) (hash-set h k v))))
  (define const-uses (box '()))
  (define const-ix (box (hash)))
  (define (const-slot name)
    (and (hash-has-key? const-value name)
         (let ([h (unbox const-ix)])
           (cond [(hash-ref h name #f) => values]
                 [else (define i (hash-count h))
                       (set-box! const-ix (hash-set h name i))
                       (set-box! const-uses
                                 (cons (list i name (hash-ref const-value name))
                                       (unbox const-uses)))
                       i]))))
  (define prim-names (mutable-set))
  (define (prim! f) (set-add! prim-names f))
  (define canon (for/list ([cr (in-list ordered)])
                  (canonicalize-crule cr const-slot rel-slot prim!)))
  (define slots
    (for/list ([(name i) (in-hash rel-ix)])
      (define d (hash-ref decl-of name))
      (cons i `(slot ,i ,(car d) ,@(cddr d)))))
  ;; RF1 slice 3: kernel attributes from the ACTUAL planning toggle, and
  ;; per-rule fold kinds from crule-kind -- both validated against the
  ;; closed vocabulary before they can reach hashed bytes.
  (define kernel-attrs
    (if (semijoin-filters-enabled) '() '(no-semijoin-reopt)))
  (validate-kernel-attributes! kernel-attrs)
  (define (rule-attrs cr)
    (define as (if (crule-kind cr) `((fold ,(crule-kind cr))) '()))
    (validate-rule-attrs! as)
    as)
  (define exec
    `(exec
      (slots ,@(map cdr (sort slots < #:key car)))
      ;; the constant's global NAME rides along: it is `const<sha24>` OF THE
      ;; VALUE (operationalization.rkt), so it is content-derived and carries
      ;; no program or name dependence -- and the daemon's decode_constant
      ;; reads it, so dropping it would have been a silently lossy split.
      (constants ,@(for/list ([e (in-list (sort (unbox const-uses) < #:key car))])
                     `(k ,(first e) ,(second e) ,(third e))))
      (prims ,@(sort (set->list prim-names) symbol<?))
      ,@(if (null? kernel-attrs) '() `((attributes ,@kernel-attrs)))
      (rules
       ,@(for/list ([cr (in-list ordered)] [c (in-list canon)] [i (in-naturals)])
           `(rule-def (ord ,i) (variant ,@(slot-relative-variant
                                           (tag-of cr) cr rel-slot))
                      ,@(let ([as (rule-attrs cr)])
                          (if (null? as) '() `((attrs ,@as))))
                      ,@c)))))
  (define binding
    `(binding ,@(for/list ([e (in-list (sort (for/list ([(n i) (in-hash rel-ix)])
                                               (cons i n))
                                             < #:key car))])
                  `(slot ,(car e) ,(cdr e)))))
  (define debug
    `(debug ,@(for/list ([cr (in-list ordered)] [i (in-naturals)])
                `(rule (ord ,i) (rid ,(rid-of cr)) (variant ,(tag-of cr))
                       (source ,(or (crule-loc cr) #f))))))
  (values exec binding debug rel-ix))

;; "delta:left.path#1" -> (delta (rel 3) 1): the KIND and ordinal stay, the
;; relation becomes this kernel's slot, and the display spelling lives in
;; DebugMap.  The relation comes from the DRIVER, never re-parsed out of
;; the display string -- the tag's middle is a rendering that may carry a
;; "/<kind>" suffix (base-tag), and an early regex that captured it as part
;; of the relation silently degraded every flavored variant to `(rel -1)`.
;; The fold kind itself rides the rule-def's (attrs ...) field since slice
;; 3 (it is executor identity, not variant identity); the display tag's
;; "/<kind>" remains the DebugMap rendering of the same fact, and the
;; daemon seal-checks their agreement.  A driver that fails to resolve is
;; a partition bug that must be LOUD -- these bytes are hashed into the
;; kernel key, so any silent fallback would bake the failure into plan
;; identity.
(define (slot-relative-variant tag cr rel-slot)
  (define kind (car (regexp-match #px"^[a-z0-9]+" tag)))
  (define ord (regexp-match #px"#([0-9]+)$" tag))
  (define driver-rel
    (match (crule-driver cr)
      [`(,(or 'scan 'probe) ,rel ,_ ...) rel]
      [_ #f]))
  (append (list (string->symbol kind))
          (if driver-rel (list `(rel ,(rel-slot driver-rel))) '())
          (if ord (list (string->number (second ord))) '())))

;; The cohort: one file per (stratum, flavor), carrying the manifest and the
;; kernels with their labeled parts (open question 1, settled -- the atomic
;; write stays single and the daemon's <stem>.<abi>.plan derivation keeps
;; working; 1176 kernels against 506 strata is the other half of the reason).
;;
;; `model` is slice 1's ProgramModel; the partition is by head SCC, with
;; staging temps inheriting their consumer's kernel.  A crule whose head SCC
;; does not resolve rides the PRELUDE (rf1-contract puts the error-struct
;; prelude in the manifest rather than in a kernel).
(define (canonicalize-cprog/abi2 cp model #:flavor [flavor 'normal])
  (define constants (cprog-constants cp))
  (define all-decls (sort (cprog-decls cp) sexp<?))
  (define-values (storage attachments)
    (partition (lambda (d) (memq (car d) '(relation struct lattice temp)))
               all-decls))
  (define decl-of (for/hash ([d (in-list storage)]) (values (second d) d)))
  (define (temp? r) (eq? (car (hash-ref decl-of r '(#f))) 'temp))
  ;; distinct name-stripped shapes, canonically ordered: the blind order's
  ;; discrimination without names
  (define decl-ix
    (for/hash ([sh (in-list (sort (remove-duplicates
                                   (for/list ([d (in-list storage)])
                                     (cons (car d) (cddr d))))
                                  sexp<?))]
               [i (in-naturals)])
      (values sh i)))
  ;; SERVICE PRELUDE.  Some relations are resolved by NAME at seal time
  ;; rather than through an op's relation slot -- the sealer looks
  ;; `malformed_deduction` up among the plan's bindings for every tycheck, and
  ;; the prim error arms are the diversion targets -- so a kernel-local slot
  ;; table that carries only what the ops reference makes the sealer fail
  ;; ("tycheck: malformed_deduction relation is absent", 45 of 167 golden
  ;; programs).  rf1-contract's binding schema already names this case:
  ;; "service-relation references into the cohort prelude".  They ride EVERY
  ;; kernel, in a fixed order over language-level names -- identical in every
  ;; program, so slot numbering stays program-independent and sharing holds.
  ;;
  ;; KEEP IN SYNC with the daemon's by-name resolvers: the eight prim error
  ;; arms are daemon/plan-count.cpp `prim_error_arm_names`, and
  ;; `malformed_deduction` is the tycheck sealer's lookup (daemon/plan.h).
  ;; Two maintenance facts, both load-bearing: (1) a service the daemon
  ;; resolves by name but this list omits fails LOUDLY at seal time under
  ;; ABI 2 (the 45-of-167 failure above), so drift is caught -- but only on
  ;; an ABI-2 run; (2) the `#:when` filter below means the "identical in
  ;; every program" claim holds only while the compiler synthesizes every
  ;; declared service in every program -- a program missing one shifts every
  ;; later slot and silently forfeits cross-program kernel sharing (never
  ;; correctness).  tests/abi2-airtight.sh pins the shared-prefix property
  ;; across two unrelated programs.  Adding a name here is a GLOBAL RE-KEY
  ;; (every kernel's slot table moves) -- schedule it as one.
  (define service-names
    '(malformed_deduction _enum error div_by_zero modulo_by_zero int_overflow
      nan_result toint_range type_mismatch mpz_overflow mpz_table_overflow))
  (define service-slots
    (for/list ([n (in-list service-names)] #:when (hash-has-key? decl-of n)) n))
  (define crules (cprog-rules cp))
  (define scc-of (program-model-scc-of model))
  (define temp-scc (resolve-temp-sccs crules scc-of temp?))
  ;; rid/tag identities stay ABI 1's (they are DebugMap data now, but the
  ;; same function of the cprog, so goldens and stats keep their spelling)
  (define tags (canonical-rule-tags cp #:flavor flavor))
  (define tag-map (for/hash ([cr (in-list crules)] [t (in-list tags)])
                    (values cr t)))
  (define (rid-of cr) (car (hash-ref tag-map cr)))
  (define (tag-of cr) (cdr (hash-ref tag-map cr)))
  ;; The program-global canonical text per crule: the total-order tiebreak
  ;; above.  Same construction ABI 1 uses, so it is variable-blind and
  ;; run-stable.
  (define global-rel-ix
    (for/hash ([d (in-list storage)] [i (in-naturals)]) (values (second d) i)))
  (define const-pairs
    (sort (for/list ([(k v) (in-hash constants)])
            (if (symbol? v) (cons v k) (cons k v)))
          symbol<? #:key car))
  (define global-const-ix
    (for/hash ([p (in-list const-pairs)] [i (in-naturals)]) (values (car p) i)))
  (define global-text-cache (make-hash))
  (define (global-text cr)
    (hash-ref! global-text-cache cr
               (lambda ()
                 (sexp->string
                  (canonicalize-crule cr
                                      (lambda (v) (hash-ref global-const-ix v #f))
                                      (lambda (n) (hash-ref global-rel-ix n 0))
                                      void)))))
  (define blind-cache (make-hash))
  (define (blind-text cr)
    (hash-ref! blind-cache cr
               (lambda () (blind-crule-text cr decl-of decl-ix global-const-ix))))
  (define grouped
    (for/fold ([h (hash)]) ([cr (in-list crules)])
      (hash-update h (crule-kernel cr scc-of temp-scc temp?)
                   (lambda (l) (cons cr l)) '())))
  ;; The unresolved crules (the synthesized error arms) become a KERNEL under
  ;; a sentinel id rather than a metadata block.  Two reasons: a metadata-only
  ;; prelude would carry rid/variant/source but NOT the ops, so the cohort
  ;; would silently lose those rules and a database installed from it would
  ;; stop producing error facts; and as a kernel it is keyed like any other,
  ;; so the arms -- identical in every program -- SHARE one key.
  ;; kernels ordered by their own exec key: a cohort's kernel order is then
  ;; a function of its kernels, not of hash iteration
  (define built
    (sort
     (for/list ([(scc krules) (in-hash grouped)])
       (define-values (exec binding debug rel-ix)
         (kernel-parts (reverse krules) decl-of rid-of tag-of constants
                       global-text blind-text service-slots))
       (list (kernel-exec-key exec) scc exec binding debug rel-ix))
     string<? #:key first))
  (define dyn (cprog-dynamic-rels cp))
  (define (kernel-dynamic rel-ix)
    ;; RESTRICTED to this kernel's bound names: the cohort's whole list would
    ;; hand the installer dynrels the kernel does not bind.  Slot-relative,
    ;; so it names nothing.
    `(dynamic ,@(sort (for/list ([(name slot) (in-hash rel-ix)]
                                 #:when (set-member? dyn name))
                        `(slot ,slot))
                      < #:key second)))
  (define members
    (program-model-scc-members model))
  ;; Cohort-level SERVICES: the relations an attachment names -- an oracle's
  ;; demand and answer, a seqindex's base.  The installer resolves those by
  ;; name, so they must be declared somewhere; they cannot ride a real
  ;; kernel's slot table, because a program-specific name there would make
  ;; that kernel's bytes program-dependent and break its key.  So they are
  ;; declared at cohort level and the daemon installs them with the
  ;; attachments, in a services plan of its own that perturbs no kernel.
  (define attachment-rel-names
    (remove-duplicates
     (append*
      (for/list ([a (in-list attachments)])
        (match a
          [`(oracle ,_name ,demand ,answer) (list demand answer)]
          [`(seqindex ,base ,_cols ...) (list base)]
          [_ '()])))))
  ;; ALL storage declarations ride the cohort, not just the ones an
  ;; attachment names.  The ABI-1 relation table was doing double duty:
  ;; identity AND the declaration list that makes every declared relation
  ;; EXIST in the daemon.  Kernel-local slots keep the first role and drop the
  ;; second, so a relation no kernel binds -- `error`, `malformed_deduction`,
  ;; `$seq_at` -- was never registered and its output CSV simply vanished (34
  ;; golden programs, all reporting "missing relation ...csv").  Declarations
  ;; are a stratum fact and live outside `exec`, so carrying them here costs
  ;; no kernel its key.
  (define service-decls storage)
  `(kernel-cohort
    (abi 2)
    (flavor ,flavor)
    (attachments ,@attachments)
    (declarations ,@(for/list ([d (in-list service-decls)] [i (in-naturals)])
                       `(rel ,i ,d)))
    ;; The cohort-level dynamic set (by NAME -- names live at cohort level)
    ;; is the manifest's stratum-scheduling fact (rf1-contract: "the dynamic
    ;; set belongs to the COHORT MANIFEST").  Today's decoder reads only the
    ;; per-kernel slot-relative form below; this one is for the T2 installer
    ;; and T4 coordinator manifests.  Both are derived from the same
    ;; cprog-dynamic-rels, so they cannot diverge.
    (dynamic ,@(sort (set->list (cprog-dynamic-rels cp)) symbol<?))
    (manifest
     ,@(for/list ([k (in-list built)] [i (in-naturals)])
         `(kernel (ord ,i) (key ,(first k))
                  (members ,@(if (second k)
                                 (hash-ref members (second k) '())
                                 '()))
                  ,@(if (second k) '() '((prelude #t)))
                  (rules ,(length (cdr (assq 'rules (cdr (third k)))))))))
    ,@(for/list ([k (in-list built)] [i (in-naturals)])
        `(kernel (ord ,i) ,(third k) ,(fourth k)
                 ,(kernel-dynamic (sixth k)) ,(fifth k)))))

;; ------------------------------------------------------------------------
;; The Racket twin of the daemon's decoder-boundary adaptation
;; (daemon/plan.cpp parse_kernel_cohort), for Racket-side plan readers --
;; the REPL's whynot/code and any fixture that walks rule-defs by name.
;; Each kernel of a cohort renders as the ABI-1 kernel-plan it is
;; equivalent to: exec structure joined with the binding schema's names,
;; the dense ordinal replaced by the DebugMap's RuleId, the slot-relative
;; variant replaced by its display spelling, sources into a meta block.
;; The rule-free declarations/services plan comes first, exactly as the
;; daemon synthesizes it.  Kernels stay separate units -- this is per-kernel
;; FIELD adaptation, not the reaggregation rf1-contract forbids.
(define (cohort->kernel-plans cohort)
  (match-define `(kernel-cohort (abi 2) (flavor ,flavor)
                                (attachments ,atts ...)
                                (declarations ,decls ...)
                                (dynamic ,_dyns ...)
                                (manifest ,_mans ...)
                                ,kernels ...)
    cohort)
  (define services
    (and (or (pair? decls) (pair? atts))
         `(kernel-plan (abi 1) (flavor ,flavor)
                       (relations ,@decls)
                       (attachments ,@atts)
                       (constants) (prims) (dynamic) (rules) (meta))))
  (append
   (if services (list services) '())
   (for/list ([k (in-list kernels)])
     (match-define `(kernel (ord ,_ord) (exec ,exec-parts ...)
                            (binding ,binds ...)
                            (dynamic ,kdyns ...)
                            (debug ,debugs ...))
       k)
     ;; assq, not positional: (attributes ...) is absent-when-empty (slice
     ;; 3), so exec's section list varies by one
     (define (exec-field key)
       (match (assq key exec-parts) [(cons _ vs) vs] [_ '()]))
     (define slots (exec-field 'slots))
     (define ks (exec-field 'constants))
     (define prims (exec-field 'prims))
     (define rules (exec-field 'rules))
     (define name-of
       (for/hash ([b (in-list binds)])
         (match-define `(slot ,n ,name) b)
         (values n name)))
     (define debug-of
       (for/hash ([d (in-list debugs)])
         (match-define `(rule (ord ,o) (rid ,rid) (variant ,v) (source ,src))
           d)
         (values o (list rid v src))))
     `(kernel-plan
       (abi 1)
       (flavor ,flavor)
       (relations ,@(for/list ([s (in-list slots)])
                      (match-define `(slot ,n ,kind ,rest ...) s)
                      `(rel ,n (,kind ,(hash-ref name-of n) ,@rest))))
       (attachments)                    ; cohort services carry them, above
       (constants ,@ks)
       (prims ,@prims)
       (dynamic ,@(for/list ([d (in-list kdyns)])
                    (match-define `(slot ,n) d)
                    (hash-ref name-of n)))
       (rules ,@(for/list ([rd (in-list rules)])
                  (match-define `(rule-def (ord ,o) (variant ,_v ...) ,rest ...)
                    rd)
                  ;; the (attrs ...) field is exec identity, not ABI-1
                  ;; grammar; the display variant already renders the fold
                  ;; kind as its "/<kind>" suffix, so nothing is lost
                  (define body
                    (match rest
                      [`((attrs ,_ ...) ,more ...) more]
                      [_ rest]))
                  `(rule-def (rid ,(first (hash-ref debug-of o)))
                             (variant ,(second (hash-ref debug-of o)))
                             ,@body)))
       (meta ,@(let ([by-rid (for/fold ([h (hash)])
                                       ([info (in-hash-values debug-of)])
                               (hash-set h (first info) (third info)))])
                 (for/list ([rid (in-list (sort (hash-keys by-rid) <))])
                   `(rule-meta (rid ,rid) (source ,(hash-ref by-rid rid))))))))))

;; Either artifact shape, decided by the form's own tag -- the Racket
;; mirror of the daemon's parse_plan_artifact_file.
(define (plan-artifact->kernel-plans form)
  (match form
    [`(kernel-cohort ,_ ...) (cohort->kernel-plans form)]
    [`(kernel-plan ,_ ...) (list form)]
    [_ '()]))

;; ------------------------------------------------------------------------
;; Serialization and KernelPlanKey.  One `write` line (D6): the daemon's
;; line-framed dispatcher reads it whole; pretty-printing is for humans.

(define (kernel-plan->string kp)
  (sexp->string kp))

(define (kernel-plan-key kp)
  (bytes->hex-string (sha256 (string->bytes/utf-8 (kernel-plan->string kp)))))
