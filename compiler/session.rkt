#lang racket

;; The incremental-session driver (docs/incremental.md §0.2-§0.5, 0.B4/0.C/0.E):
;; a resident daemon driven through program segments and signed batches,
;; with the Phase-0 routing rule deciding how each flush propagates.
;;
;;   session        = daemon + per-stratum manifest info + pending batches
;;                    + the applied-batch log (the recipe's batch steps)
;;   session-open!  = materialise a stored database CHAIN with the live
;;                    machinery (0.E2): plain opens, layer imports, edits
;;                    (logged like batches -- one applier, E1a), prog.sexpr
;;                    replays, and saved-session recipe replays all execute
;;                    exactly as they would live, rebuilding the versioned
;;                    pipeline in memory
;;   session-run!   = one program segment per program of the run tree
;;                    (E0c): begin-segment version boundary, frozen imports,
;;                    strata to fixpoint -- per program, not per file
;;   session-batch! = queue one signed tuple against an anchor (default:
;;                    the tip); same-point add/delete pairs collapse in the
;;                    pending set (§0.2)
;;   session-flush! = apply the pending sets and propagate:
;;     tip anchors, by the §0.5/M1 routing rule -- capability-certified
;;       positive plain-table cones -> counted `_maint1` across every affected
;;       stratum; unsupported single-stratum positives may use legacy
;;       delta-entry, other monotone cones use replay-entry, and every
;;       retraction/non-monotone cone uses clear-and-rerun;
;;     old anchors (a version with later rebindings), by the ANCHORED WALK
;;       (§0.4-§0.6): apply the batch to the anchored version, then replay
;;       the pipeline suffix -- refresh each affected inheritance boundary
;;       (re-copy + re-seed allocators), clear each affected first-binding
;;       version, re-run each affected stratum positionally (bind-at + its
;;       cached .so over the P-environment), re-apply logged batches whose
;;       target versions were rebuilt, and re-apply logged imports at their
;;       positions (0.E0b -- the walk no longer refuses across imports).
;;       Sound by the mode-2 argument: the suffix is a from-scratch run
;;       over the edited history.
;;   session-save!  = one new data/<X> layer: the full materialisation
;;                    (canonical writer, per=100), the recipe (steps +
;;                    collapsed anchored batches, payloads externalised
;;                    into delta.<k>/), the segment sources (prog.sexpr),
;;                    a signature over the touched relations, and a META
;;                    whose manifest links the base chain (0.E1).  Loading
;;                    X replays the recipe -- W2/W3/W4's one code path.
;;
;; Batches queue while a stratum runs and apply only between fixpoints
;; (refuseIfSuspended semantics compose -- every action here is sent at a
;; boundary).  Inline transport refuses > `inline-batch-max` tuples per
;; (anchor, relation) per flush (§0.3): bulk data enters as a bin database
;; via session-import-delta! (or a -d link), not baked literals.
;;
;; Pausing composes: each stratum answers one line per bounded unit; a
;; (paused ...) is answered with a (continue) action (env-configurable
;; budget), exactly as runslog's one-shot loop does.
;;
;; Known holes, guarded loudly: anchors that resolve to no version, and
;; hot-links of CHAINED databases (their on-disk dirs are partial; freeze
;; first).  Deleting an independently re-derivable row sticks only until
;; its deriving stratum re-runs (the replay-deletion caveat,
;; docs/db-compression.md §12); precise deletion is DRed^c (M4+).

(provide make-session
         make-session-over      ; a session facade over an existing daemon
         session-open!
         session-run!
         session-batch!
         session-edit-batch!
         session-inject-version!
         session-inject-batch!
         session-inject-and-reopen!
         session-add-tuple!     ; immediate tip apply, LOGGED (0.E0d)
         session-del-tuple!
         session-import-delta!
         session-link!          ; hot-link a data/ DB (0.D5)
         session-rename!        ; environment operations (0.D1)
         session-drop!
         session-flush!
         session-save!          ; the delta-layer save (0.E1)
         session-log            ; the collapsed applied-batch log (C2/C3)
         session-recipe         ; ordered steps + anchored batches (§0.10)
         session-action!        ; low-level: one action + a reader
         session-recount!       ; the count round over the pipeline (M0)
         session-reenter!       ; direct replay-entry (tests/tools)
         session-rerun!         ; direct clear-and-rerun (tests/tools)
         session-close!
         inline-batch-max)

(require "tools.rkt")
(require "compile.rkt")
(require "actions.rkt")
(require "runslog.rkt")   ; db-full-manifest, segment-write-set, manifest-entry
(require "dbmeta.rkt")
(require "dbtool.rkt")
(require "parser.rkt")    ; current-source-capture / current-source-override

;; §0.3: past a few thousand tuples the inline transport (values baked as
;; literals into an action plugin) stops making sense -- the known ~10k
;; inline-facts ceiling with clang time growing ahead of it.  Per
;; (anchor, relation) per flush.
(define inline-batch-max
  (or (string->number (or (getenv "SLOG_INLINE_MAX") "")) 2048))

;; One stratum's driver-side record: its cached .so, manifest
;; dynamic-rels/reads/heads, and the thunks that lazily build its
;; legacy delta-entry (0.B5), `_count` (§8B.1/M0), and `_maint1` (M1)
;; flavors.
(struct sinfo (so dyn reads heads acyclic? delta count maintenance
                  negative-maintenance recursive-negative-maintenance)
  #:transparent)

;; One live session.
;;   strata-info : list of (cons scc sinfo), oldest first -- scc is the
;;             daemon pipeline id of the stratum's FIRST push (`next-scc`
;;             mirrors the daemon's pipeline length: every stratum .so this
;;             session sends advances it, fresh pushes and re-pushes alike,
;;             so the ids stay aligned however many re-entries happen).
;;   pending : anchor -> rel -> tuple -> chronological +/- command list
;;             (anchor = 'tip | position); normalization happens against
;;             the daemon's authoritative VersionInstance overlay at flush
;;   applied : (cons rel version-binding-pos) -> tuple -> '+/'-  -- the
;;             session's OWN collapsed batch log (§0.2): what a save
;;             serialises, and what the anchored walk re-applies when it
;;             rebuilds a version.
;;   inherited : same shape, populated while REPLAYING ancestor history
;;             (a chain load) -- the walk re-applies these too, but a save
;;             never serialises them (they belong to the ancestors' own
;;             recipes/edits).  An own entry for the same (version, tuple)
;;             overrides the inherited one.
;;   imports : list of (list dir renames pos), newest first -- re-applied
;;             positionally by the suffix walk (0.E0b).
;;   steps   : list of (list pos seq step), newest first -- position-
;;             stamped so a back-anchored import serialises INTO its
;;             pipeline place, not at its wall-clock arrival (§0.2 span
;;             semantics; the recipe replays steps in (pos, seq) order).
;;   touched : rel -> #t, every relation this session wrote (segment
;;             write-sets, batch/import targets, rename targets) -- the
;;             save's signature scope (§0.10: ancestors' signatures are
;;             inherited for the rest).
;;   sources : path -> text, the source closure of every segment compiled
;;             by this session (prog.sexpr capture, P1.1).
;;   replaying? : #t while executing ancestor history (session-open! /
;;             recipe replay): steps are not recorded, logs go to
;;             `inherited`, touched/sources are not accumulated.
(struct session (sp out in err-thread [db #:mutable]
                 [strata-info #:mutable] [next-scc #:mutable]
                 pending applied inherited
                 [imports #:mutable] [steps #:mutable] [renames #:mutable]
                 touched sources [replaying? #:mutable] echo
                 [layer-id #:mutable] evaluation-id [next-event #:mutable]
                 [descriptors #:mutable] compat-keys input-only)
  #:transparent)

(define (fresh-runtime-id prefix)
  (format "~a-~x-~x-~x-~x"
          prefix (inexact->exact (floor (current-inexact-milliseconds)))
          (random 1000000000) (random 1000000000) (random 1000000000)))

(define (make-session #:echo [echo displayln])
  (ensure-slogd-exists)
  (define-values (sp out in err)
    (apply subprocess #f #f #f (slogd-argv "daemon/slogd")))
  (define err-thread
    (thread (lambda ()
              (let loop ()
                (define s (read-line err))
                (unless (eof-object? s) (eprintf "~a\n" s) (loop))))))
  (define s
    (session sp out in err-thread #f '() 0 (make-hash) (make-hash) (make-hash)
             '() '() '() (make-hash) (make-hash) #f echo
             (fresh-runtime-id "layer") (fresh-runtime-id "eval") 0 '()
             (make-hash) (make-hash)))
  (session-action! s `(set-evaluation ,(session-evaluation-id s))
                   read-one-line-quiet!)
  s)

;; A session facade over an existing daemon connection (the one-shot
;; driver's, for recipe-chain loads -- runslog's recipe-chain-loader hook).
;; next-scc initialises from live introspection so cone bookkeeping aligns
;; with whatever the connection already pushed.
(define (make-session-over in-port out-port #:echo [echo displayln])
  (define s (session #f out-port in-port #f #f '() 0 (make-hash) (make-hash)
                     (make-hash) '() '() '() (make-hash) (make-hash) #f echo
                     (fresh-runtime-id "layer") (fresh-runtime-id "eval") 0 '()
                     (make-hash) (make-hash)))
  (session-action! s `(set-evaluation ,(session-evaluation-id s))
                   read-one-line-quiet!)
  (define-values (_cur strata-pos _chains) (introspect! s))
  (set-session-next-scc! s (hash-count strata-pos))
  s)

(define (send-plugin! s path)
  (display (string-append path "\n") (session-in s))
  (flush-output (session-in s)))

(define (echo! s line) ((session-echo s) line))

;; Drive the current stratum to fixpoint: echo every line; answer
;; (paused ...) with (continue); error on (error ...) or EOF.
(define (drive-to-fixpoint! s)
  (define continue-so (action-so `(continue)))
  (let poll ()
    (define line (read-line (session-out s)))
    (cond
      [(eof-object? line) (error 'session "daemon EOF mid-stratum")]
      [(regexp-match? #px"^\\(fixpoint " line) (echo! s line)]
      [(regexp-match? #px"^\\(paused " line)
       (echo! s line)
       (cond
         [(regexp-match? #px"memory\\)\\s*$" line)
          (error 'session (format "out of memory: ~a" line))]
         [else (send-plugin! s continue-so) (poll)])]
      [(regexp-match? #px"^\\(error " line)
       (error 'session (format "daemon error: ~a" line))]
      [else (echo! s line) (poll)])))

;; Send one STRATUM plugin and drive it to fixpoint, advancing the daemon
;; pipeline mirror -- every stratum push (fresh or re-push) lands here so
;; next-scc never drifts from the daemon's scc assignment.
(define (send-stratum! s so)
  (set-session-next-scc! s (add1 (session-next-scc s)))
  (send-plugin! s so)
  (drive-to-fixpoint! s))

;; Maintenance strata use the same bounded execution protocol without
;; becoming pipeline events.  In particular, recount must not make a later
;; JIT injection's identity depend on whether someone inspected counts first.
(define (send-transient-stratum! s so)
  (session-action! s `(transient-stratum))
  (define armed (read-line (session-out s)))
  (unless (equal? armed "(transient-armed)")
    (error 'session (format "could not arm transient stratum: ~a" armed)))
  (send-plugin! s so)
  (drive-to-fixpoint! s))

;; Delta/replay incarnations retain legacy numeric pipeline positions but are
;; explicitly non-semantic: they cannot acquire writer ownership or become a
;; second recount source merely because maintenance re-executed a program.
(define (send-maintenance-stratum! s so)
  (session-action! s `(maintenance-stratum))
  (define armed (read-line (session-out s)))
  (unless (equal? armed "(maintenance-armed)")
    (error 'session (format "could not arm maintenance stratum: ~a" armed)))
  (send-stratum! s so))

;; Send one FRESH stratum (recording its manifest info for cone assembly)
;; and drive it.
(define (push-sbuild! s sb)
  (match-define (cons so _tag) ((sbuild-runnable sb)))
  (define-values (dyn reads heads acyclic?)
    (read-stratum-meta (sbuild-hash sb)))
  (set-session-strata-info!
   s (append (session-strata-info s)
             (list (cons (session-next-scc s)
                         (sinfo so dyn reads heads acyclic?
                                (sbuild-delta sb) (sbuild-count sb)
                                (sbuild-maintenance sb)
                                (sbuild-negative-maintenance sb)
                                (sbuild-recursive-negative-maintenance sb))))))
  (send-stratum! s so))

;; The count round (docs/incremental.md §8B.1-§8B.2, M0.4c): rebuild a
;; VERSION-LOCAL count state in scratch sidecars, audit its coverage, then
;; publish the whole target set atomically.  Each _count flavor fires its
;; rules exactly once over FULL indices and folds contributions into the
;; scratch sidecar selected by the exact VersionId captured when its
;; original stratum instance was pushed.  Nothing is inserted, so the
;; resident content is untouched.
;;
;;   (session-recount! s)              whole pipeline through the tip
;;   (session-recount! s #:rel R)      same correctness-first prefix walk;
;;                                     R is retained as the future cone API
;;   (session-recount! s #:at P)       whole pipeline prefix through P
;;   (session-recount! s #:force? #t)  replace even an already-closed walk
;;
;; A prefix walk deliberately runs each selected stratum at ITS ORIGINAL
;; bind position, rather than resolving every plugin through one common
;; tip environment.  That is the crucial distinction when a relation is
;; renamed, rebound, or reopened by several SCCs: every contribution lands
;; on the VersionId actually written by that stratum instance.
;;
;; Laziness is all-or-nothing for the transaction: if every count-capable
;; version in the prefix is already closed, no plugin runs.  Otherwise all
;; prefix strata run into fresh scratch maps.  A plugin/coverage failure
;; aborts every scratch map and preserves all previously committed maps.
;; The optional relation cone can be restored later once its closure is
;; expressed over VersionIds and complete writer sets; a full prefix is
;; intentionally preferable to publishing a plausible partial count map.
(define (session-recount! s #:rel [rel #f] #:at [at #f] #:force? [force? #f]
                          #:only [only #f]
                          #:lattices? [lattices? #f]
                          #:fail-after [fail-after #f]
                          #:omit-writer [omit-writer #f])
  (define-values (cur sinstances chains vinfo) (introspect-identities! s))
  (define p (or at cur))
  (when (> p cur)
    (error 'session (format "recount position ~a is past pipeline tip ~a" p cur)))
  ;; Original stratum instances in prefix order.  `sinstances` also gives
  ;; their exact write VersionIds, but activating every count-capable
  ;; prefix version covers program inputs and inheritance-only successors
  ;; that have no writer stratum of their own.
  (define entries
    (for/list ([e (in-list (session-strata-info s))]
               #:do [(define si (hash-ref sinstances (car e) #f))]
               #:when (and si (<= (first si) p)))
      (list (car e) (first si) (cdr e) (second si) (third si))))
  (define cstate (query-maintenance-count-state! s lattices?))
  ;; VersionId -> counted?, de-duplicated across rename aliases.  A false
  ;; observation wins (aliases should agree, but this makes disagreement
  ;; conservatively force a rebuild).
  (define target-state (make-hash))
  (for* ([(name states) (in-hash cstate)]
         [oc (in-list states)])
    (define ord (car oc))
    (define binding
      (and (< ord (length (hash-ref chains name '())))
           (list-ref (hash-ref chains name) ord)))
    (define vi (hash-ref vinfo (cons name ord) #f))
    (when (and (or (not only) (member name only))
               binding vi (<= (second binding) p))
      (define vid (first vi))
      (hash-set! target-state vid
                 (and (cdr oc) (hash-ref target-state vid #t)))))
  (define vids (sort (hash-keys target-state) <))
  (define closed?
    (and (pair? vids)
         (for/and ([vid (in-list vids)]) (hash-ref target-state vid))))
  (define run? (and (pair? vids) (or force? (not closed?))))
  (echo! s (format "(recount ~a ~a ~a~a)"
                   (if run? (length entries) 0)
                   (if run? 0 (length entries))
                   (length entries)
                   (if rel (format " rel=~a" rel) "")))
  (when run?
    (define (epoch-action! spec expected)
      (session-action! s spec)
      (define line (read-line (session-out s)))
      (when (eof-object? line) (error 'session "daemon EOF during count epoch"))
      (echo! s line)
      (define reply (read (open-input-string line)))
      (match reply
        [`(error ,why) (error 'session why)]
        [(== expected) (void)]
        [_ (error 'session (format "unexpected count-epoch reply: ~a" reply))]))
    (epoch-action! `(begin-count-epoch ,@vids) '(count-epoch-begun))
    (with-handlers
        ([exn:fail?
          (lambda (e)
            (with-handlers ([exn:fail? void])
              (epoch-action! `(abort-count-epoch ,@vids) '(count-epoch-aborted)))
            (raise e))])
      (for ([e (in-list entries)] [writer-n (in-naturals 1)])
        ;; Resolve this count plugin through its historical environment;
        ;; its CountTasks then select the active scratch sidecars of the
        ;; exact versions registered by that original stratum instance.
        (define exact-bindings
          (remove-duplicates (append (fourth e) (fifth e)) equal?))
        (session-action! s `(bind-instance ,(second e) ,exact-bindings))
        (send-transient-stratum! s ((sinfo-count (third e))))
        (unless (and omit-writer (= omit-writer writer-n))
          (epoch-action! `(cover-count-writer ,(first e))
                         `(count-writer-covered ,(first e))))
        (when (and fail-after (= fail-after writer-n))
          (error 'session (format "injected recount failure after ~a writers"
                                  fail-after))))
      (epoch-action! `(commit-count-epoch ,@vids) '(count-epoch-committed)))))

;; The per-(relation, version) counted state (§8B.2): name -> list of
;; (ord . counted?), from the (count-state) introspection action.
;; Lattices use the separate contributor-state action below.  Index-free
;; versions, severed bindings, and $-diagnostics are absent by construction.
(define (query-count-state! s)
  (session-action! s `(count-state))
  (define line (read-line (session-out s)))
  (when (eof-object? line) (error 'session "daemon EOF at count-state"))
  (echo! s line)
  (match (read (open-input-string line))
    [`(count-state ,es ...)
     (for/fold ([h (hash)]) ([e (in-list es)])
       (match e
         [`(cnt ,name ,ord ,flag)
          (hash-update h name (lambda (l) (cons (cons ord (= flag 1)) l)) '())]
         [`(revisions ,_ ...) h]))]
    [x (error 'session (format "unparseable (count-state) reply: ~a" x))]))

;; M6L contributor state mirrors count-state's name -> (ordinal . closed?)
;; shape, but closing it certifies a full contribution multiset whose reduction
;; equals the visible lattice map.
(define (query-lattice-contributor-state! s)
  (session-action! s `(lattice-contributor-state))
  (define line (read-line (session-out s)))
  (when (eof-object? line)
    (error 'session "daemon EOF at lattice-contributor-state"))
  (echo! s line)
  (match (read (open-input-string line))
    [`(lattice-contributor-state ,es ...)
     (for/fold ([h (hash)]) ([e (in-list es)])
       (match e
         [`(lcnt ,name ,ord ,flag)
          (hash-update h name (lambda (l) (cons (cons ord (= flag 1)) l)) '())]))]
    [x (error 'session
              (format "unparseable lattice-contributor-state reply: ~a" x))]))

(define (query-maintenance-count-state! s include-lattices?)
  (define tables (query-count-state! s))
  (if include-lattices?
      (for/fold ([h tables]) ([(name states)
                               (in-hash (query-lattice-contributor-state! s))])
        (hash-set h name states))
      tables))

(define (query-update-epoch! s)
  (session-action! s `(update-epoch))
  (define line (read-line (session-out s)))
  (when (eof-object? line) (error 'session "daemon EOF at update-epoch"))
  (echo! s line)
  (match (read (open-input-string line))
    [`(update-epoch ,revision settled) revision]
    [`(update-epoch ,revision active) revision]
    [x (error 'session (format "unparseable update-epoch reply: ~a" x))]))

(define (query-update-counts-valid! s)
  (session-action! s `(update-counts-valid))
  (define line (read-line (session-out s)))
  (when (eof-object? line) (error 'session "daemon EOF at update-counts-valid"))
  (echo! s line)
  (match (read (open-input-string line))
    [`(update-counts-valid ,flag) (= flag 1)]
    [x (error 'session (format "unparseable update-counts-valid reply: ~a" x))]))

;; Latest-version maintenance capability.  Values distinguish ordinary table
;; support from M6L's conditional lattice-contributor support and M4S's
;; conditional struct support; the route below proves leaf or stratified
;; topology (and, for structs, acyclic interior membership) before accepting
;; the conditional kinds.
(define (query-positive-capabilities! s chains)
  (session-action! s `(count-capabilities))
  (define line (read-line (session-out s)))
  (when (eof-object? line) (error 'session "daemon EOF at count-capabilities"))
  (echo! s line)
  (match (read (open-input-string line))
    [`(count-capabilities ,caps ...)
     (for/hash ([c (in-list caps)]
                #:when
                (match c
                  [`(cap ,name ,ord ,_vid ,fields ...)
                   (define chain (hash-ref chains name '()))
                   (and (member '(recount yes) fields)
                        (or (member '(reason table-recount) fields)
                            (member '(reason lattice-contributor-recount) fields)
                            (member '(reason struct-recount) fields))
                        (pair? chain) (= ord (first (last chain))))]
                  [_ #f]))
       (match-define `(cap ,name ,_ord ,_vid ,fields ...) c)
       (values name
               (cond
                 [(member '(reason lattice-contributor-recount) fields) 'lattice]
                 [(member '(reason struct-recount) fields) 'struct]
                 [else 'table])))]
    [x (error 'session (format "unparseable count-capabilities reply: ~a" x))]))

;; consume one response line without echoing (internal protocol chatter)
(define (read-one-line-quiet! out)
  (void (read-line out)))

;; Send one action and hand its response stream to `read!` (called with
;; the session's output port; may read as many lines as the action's
;; protocol emits -- nothing for silent actions).
(define (session-action! s spec [read! void])
  (send-plugin! s (action-so spec))
  (read! (session-out s)))

(define (read-one-line! s)
  (define line (read-line (session-out s)))
  (unless (eof-object? line) (echo! s line)))

;; ---- bookkeeping ----------------------------------------------------------

;; Record one recipe step, stamped with its pipeline position (defaulting
;; to the CURRENT position -- the one the step is about to occupy); a
;; back-anchored step passes its anchor so it serialises into its logical
;; pipeline place (0.E0b).  Ancestor history being replayed is never
;; recorded -- it lives in the ancestors' own recipes.
(define (record-step! s step #:at [pos #f])
  (unless (session-replaying? s)
    (define p (or pos (let-values ([(cur _sp _ch) (introspect! s)]) cur)))
    (set-session-steps! s (cons (list p (length (session-steps s)) step)
                                (session-steps s)))))

;; Accumulate the save's signature scope (§0.10: cone/target relations;
;; ancestors' signatures are inherited for the rest).  $-machinery
;; relations never sign: their contents are route-dependent (e.g. a
;; $stat_fires row differs between a delta-entry and a replay-entry of
;; the same batch), so they would read as false drift.
(define (touch! s rels)
  (unless (session-replaying? s)
    (for ([r (in-list rels)])
      (define r* (if (symbol? r) r (string->symbol r)))
      (unless (eq? #\$ (string-ref (symbol->string r*) 0))
        (hash-set! (session-touched s) r* #t)))))

;; The normalized applied-overlay log, serialization-ready: a list of
;; (overlay REL POS ((direct|mask|none (v ...)) ...)), sorted by (pos, rel).
;; `none` is retained as an explicit descendant override of ancestor state.
(define (session-log s)
  (for/list ([key (in-list (sort (hash-keys (session-applied s))
                                 (lambda (a b)
                                   (or (< (cdr a) (cdr b))
                                       (and (= (cdr a) (cdr b))
                                            (symbol<? (car a) (car b)))))))]
             #:when (positive? (hash-count (hash-ref (session-applied s) key))))
    (define per (hash-ref (session-applied s) key))
    (define rows
      (sort (for/list ([(t state) (in-hash per)]) `(,state ,t))
            (lambda (a b) (string<? (~a a) (~a b)))))
    `(overlay ,(car key) ,(cdr key) ,rows)))

;; The session as a recipe (docs/incremental.md §0.10, C2): the recorded
;; steps in (position, arrival) order -- so a back-anchored import sits at
;; its pipeline place -- plus the collapsed batch log, each batch anchored
;; as (relation, version-ordinal): ordinals are recipe-stable across
;; recompiles (§0.4); raw positions are not, so they are resolved against
;; the live chains here and never serialised.
(define (session-recipe s)
  (define-values (_cur _si chains vinfo) (introspect-identities! s))
  (define ordered-steps
    (map third (sort (reverse (session-steps s))
                     (lambda (a b)
                       (or (< (first a) (first b))
                           (and (= (first a) (first b))
                                (< (second a) (second b))))))))
  `(slog-recipe
    ,@ordered-steps
    ,@(for/list ([entry (in-list (session-log s))])
        (match-define `(overlay ,rel ,pos ,rows) entry)
        (define ord
          (or (for/first ([b (in-list (hash-ref chains rel '()))]
                          #:when (and (= (second b) pos) (not (third b))))
                (first b))
              0))
        (define key
          (match (hash-ref vinfo (cons rel ord) #f)
            [(list _vid _pred k _schema)
             (if (regexp-match? #px"^runtime-" k)
                 (hash-ref!
                  (session-compat-keys s) (cons rel ord)
                  (lambda ()
                    (second
                     (first (allocate-version-event! s (list rel)
                                                     'legacy-compatibility)))))
                 k)]
            [_
             (hash-ref!
              (session-compat-keys s) (cons rel ord)
              (lambda ()
                (second
                 (first (allocate-version-event! s (list rel)
                                                 'legacy-compatibility)))))]))
        `(overlay ,rel (key ,key) (v ,ord) ,rows))))

;; ---- opening: chain loads through the live machinery (0.E2) ---------------

(define (session-open! s db)
  (define mm (db-encoding-mismatch db))
  (when mm
    (error 'session
           (format "database ~a was written with value-encoding v~a but this build reads v~a; re-encode its root bins (or drop-and-replay derived layers) to migrate"
                   (first mm) (second mm) slog-value-encoding-version)))
  (set-session-db! s db)
  (record-step! s `(open ,db))
  (session-execute-load-steps! s (db-load-steps db))
  ;; a recipe replay rebinds session-db to the layer's base for its first
  ;; segment's compile manifest; restore the user-level input
  (set-session-db! s db)
  ;; M4S slice 3 (docs/m4s-contract.md): tombstones never persist -- the
  ;; dead half of every struct intern dictionary is reconstructed from the
  ;; loaded chain itself (dict(v) = (live(pred) ∪ dict(pred)) − live(v)).
  ;; Replay re-mints most mappings by re-running the same clears and
  ;; deletions; this closes the invariant independent of each step's route.
  (session-action! s `(reconstruct-tombstones))
  (read-one-line! s))

;; Execute a dbtool load plan with the live machinery: every step lands
;; exactly as it would in a live session.  Everything applied here is
;; ancestor HISTORY: logged as inherited, never re-serialised by a save.
(define (session-execute-load-steps! s steps)
  (define was (session-replaying? s))
  (set-session-replaying?! s #t)
  (for ([st (in-list steps)])
    (match st
      [`(open ,db) (session-action! s `(open ,db))]
      [`(import-layer ,l) (session-action! s `(import-layer ,l))]
      [`(replay ,l ,own) (replay-prog-layer! s l own)]
      [`(replay-recipe ,l) (replay-recipe-layer! s l)]
      [_ (apply-edit-step! s st)]))
  (set-session-replaying?! s was))

;; THE single step applier (E1a): an `edits` file is a recipe fragment --
;; the same spellings execute through the same machinery whether they come
;; from a recipe, an ancestor's edits appendix, or a live tool.
(define (apply-edit-step! s st)
  (match st
    [`(add-tuple ,rel ,vs ...) (apply-tuples! s rel (list vs) '())]
    [`(del-tuple ,rel ,vs ...) (apply-tuples! s rel '() (list vs))]
    [`(rename-rel ,from ,to) (session-rename! s from to)]
    [`(drop-rel ,r) (session-drop! s r)]
    [`(inject-version ,r ,key) (session-inject-version! s r #:key key)]
    [`(import-delta ,dir ,renames) (session-import-delta! s dir renames)]
    [`(link ,db ,renames) (session-link! s db renames)]
    [`(batch ,rel (v ,ord) ,adds ,dels)
     (queue-anchored-batch! s rel ord adds dels)
     (session-flush! s)]
    [`(overlay ,rel (v ,ord) ,rows)
     (apply-anchored-overlay! s rel #f ord rows)]
    [`(overlay ,rel (key ,key) (v ,ord) ,rows)
     (apply-anchored-overlay! s rel key ord rows)]
    [x (error 'session (format "unknown load/edit step: ~a" x))]))

;; Immediate tip apply of signed tuples, LOGGED at the target's current
;; version binding (0.E0d: no input event exists outside the log).  Apply
;; only -- propagation is the caller's (flush routing, or an explicit
;; reenter/rerun as the test harness does).
(define (apply-tuples! s rel adds dels)
  (define rel* (if (symbol? rel) rel (string->symbol rel)))
  (define-values (_cur _sp chains) (introspect! s))
  (define-values (_ord bind-pos _last?) (resolve-anchor chains rel* 'tip))
  (define commands (make-hash))
  (for ([t (in-list adds)]) (hash-update! commands t (lambda (xs) (cons '+ xs)) '()))
  (for ([t (in-list dels)]) (hash-update! commands t (lambda (xs) (cons '- xs)) '()))
  (define normalized (normalize-pending! s rel* bind-pos commands))
  (define rows
    (for/list ([(t change) (in-hash normalized)]) `(,(first change) ,t)))
  (when (pair? rows)
    (session-action! s `(set-overlay ,rel* -1 (,@rows)))
    (read-one-line! s)
    (for ([state '(direct mask none)])
      (log-applied! s rel* bind-pos
                    (for/list ([row (in-list rows)] #:when (eq? (first row) state))
                      (second row))
                    state)))
  (touch! s (list rel*)))

(define (session-add-tuple! s rel tuple) (apply-tuples! s rel (list tuple) '()))
(define (session-del-tuple! s rel tuple) (apply-tuples! s rel '() (list tuple)))

;; Replay one prog.sexpr layer (the db-compression load, ported to the
;; session -- one code path per 0.E2).  E0a order: the layer's version
;; boundary opens FIRST; its own steps (kept-sample import + edits) then
;; land in the layer's own versions; then its strata re-run.
(define (replay-prog-layer! s lname own-steps)
  (define plan (read-prog-sexpr (string-append "data/" lname)))
  (define (apply-own!)
    (for ([st (in-list own-steps)])
      (match st
        [`(import-layer ,l) (session-action! s `(import-layer ,l))]
        [_ (apply-edit-step! s st)])))
  (cond
    [plan
     (match-define (cons r-entry r-sources) plan)
     (define-values (strata _partition _edb _frozen _groups)
       (parameterize ([current-source-override r-sources])
         (compile-strata r-entry (db-full-manifest lname) #:split-facts? #f)))
     (define ws (segment-write-set strata '()))
     (when (pair? ws)
       (session-action! s `(begin-segment ,@ws))
       (read-one-line! s))
     (apply-own!)
     (for ([sb (in-list strata)])
       (push-sbuild! s sb))]
    [else (apply-own!)]))

;; Replay one saved SESSION layer (0.E2): execute its recipe's steps with
;; the machinery above -- run segments recompile from the stored sources,
;; imports resolve their externalised payloads, batches queue against
;; their ordinal anchors and flush through the live routing (tip applies
;; route normally; back-inserted anchors take the walk).  The layer's own
;; stored relation dirs are a WITNESS (signature verification), never a
;; seed: importing the final materialisation first would pollute the
;; rebuilt predecessor versions, so a recipe layer always replays from its
;; base -- and deletion is trivially sound on this path.
(define (replay-recipe-layer! s lname)
  (define dir (string-append "data/" lname))
  (define recipe (read-recipe dir))
  (unless recipe
    (error 'session (format "no recipe in data/~a" lname)))
  (match-define `(slog-recipe ,steps ...) recipe)
  (define plan (read-prog-sexpr dir))
  (define sources (if plan (cdr plan) (hash)))
  ;; the FIRST run segment compiles against the base chain's manifest --
  ;; the base is the recipe's own (open ...) step (a base-less session
  ;; with a hot-link has link edges in the manifest but no base); later
  ;; segments read the live schema (0.D2), which reflects everything
  (define base
    (for/first ([st (in-list steps)]
                #:when (match st [`(open ,_) #t] [_ #f]))
      (second st)))
  (set-session-db! s base)
  (parameterize ([current-source-override sources])
    (for ([st (in-list steps)])
      (match st
        [`(open ,_db) (void)]   ; the manifest link already materialised the base
        [`(run ,prog) (session-run! s prog)]
        [`(run ,prog (version-events ,tables ...))
         (session-run! s prog #:version-events tables)]
        [`(import-delta ,ref ,renames)
         (session-import-delta! s (recipe-payload-dir dir ref) renames)]
        [`(batch ,rel (v ,ord) ,adds ,dels)
         (queue-anchored-batch! s rel ord adds dels)]
        [`(overlay ,rel (v ,ord) ,rows)
         (apply-anchored-overlay! s rel #f ord rows)]
        [`(overlay ,rel (key ,key) (v ,ord) ,rows)
         (apply-anchored-overlay! s rel key ord rows)]
        [_ (apply-edit-step! s st)]))
    (session-flush! s))
  (echo! s (format "(replayed-recipe ~a ~a)" lname (length steps))))

;; Queue a recipe batch entry against its ordinal anchor, resolved through
;; the live (rebuilt) chains -- ordinals are the recipe-stable half of the
;; anchor (§0.4); positions are reconstituted here.
(define (queue-anchored-batch! s rel ord adds dels)
  (define rel* (if (symbol? rel) rel (string->symbol rel)))
  (define-values (_cur _sp chains) (introspect! s))
  (define chain (hash-ref chains rel* '()))
  (define hit
    (for/first ([b (in-list chain)]
                #:when (and (= (first b) ord) (not (third b))))
      b))
  (unless hit
    (error 'session
           (format "recipe batch anchors at ~a (v ~a), which the replay did not rebuild"
                   rel* ord)))
  (define anchor (if (equal? hit (last chain)) 'tip (second hit)))
  (for ([t (in-list adds)]) (session-batch! s '+ rel* t #:at anchor))
  (for ([t (in-list dels)]) (session-batch! s '- rel* t #:at anchor)))

;; New-format normalized overlay replay.  Unlike legacy +/- batches this is
;; absolute VersionInstance state and therefore needs no baseline inference.
(define (apply-anchored-overlay! s rel key ord rows)
  (define rel* (if (symbol? rel) rel (string->symbol rel)))
  (define-values (_cur _si chains vinfo) (introspect-identities! s))
  (define chosen
    (and key
         (or (for/first ([(nk vi) (in-hash vinfo)]
                         #:when (and (equal? (third vi) key) (eq? (car nk) rel*))) nk)
             (for/first ([(nk vi) (in-hash vinfo)]
                         #:when (equal? (third vi) key)) nk))))
  (define anchor-name (if chosen (car chosen) rel*))
  (define anchor-ord (if chosen (cdr chosen) ord))
  (define chain (hash-ref chains anchor-name '()))
  (define hit
    (for/first ([b (in-list chain)]
                #:when (and (= (first b) anchor-ord) (not (third b)))) b))
  (unless hit
    (error 'session
           (format "overlay anchor ~a key ~a (legacy v ~a) was not rebuilt"
                   rel* key ord)))
  (define-values (_cur2 strata-pos _chains2) (introspect! s))
  (session-action! s `(set-overlay ,anchor-name ,(second hit) (,@rows)))
  (read-one-line! s)
  (for ([state '(direct mask none)])
    (log-applied! s anchor-name (second hit)
                  (for/list ([row (in-list rows)] #:when (eq? (first row) state))
                    (second row))
                  state))
  (touch! s (list anchor-name))
  (define safe-tip?
    (and (equal? hit (last chain))
         (with-handlers ([exn:fail? (lambda (_e) #f)])
           (cone-of s anchor-name strata-pos chains)
           #t)))
  (if safe-tip?
      (session-rerun! s anchor-name)
      (walk-suffix! s (second hit) (set anchor-name) strata-pos chains)))

;; The live schema as a compile manifest (0.D2): one (schema) round trip
;; parsed by runslog's db-manifest-from-schema-lines.
(define (session-schema-manifest s)
  (send-plugin! s (action-so `(schema)))
  (define lines
    (let loop ([acc '()])
      (define line (read-line (session-out s)))
      (cond
        [(eof-object? line) (reverse acc)]
        [(regexp-match? #px"^\\(schema-end\\)" line) (reverse acc)]
        [else (loop (cons line acc))])))
  (db-manifest-from-schema-lines lines))

;; Rename / drop between segments (docs/incremental.md §0.7, 0.D1):
;; environment operations, zero data movement.  The rename is recorded
;; with its position so the anchored walk can translate its affected set
;; across the boundary and re-apply a version's batches under aliasing
;; names; drops need no driver record -- the chains' severance markers
;; carry them.  Rename EVENTS record even while replaying (the walk needs
;; ancestor renames too); recipe STEPS only for the session's own.
(define (session-rename! s from to)
  ;; normalize to symbols: the affected-set walk and the recipe both key
  ;; relations symbolically
  (define from* (if (symbol? from) from (string->symbol from)))
  (define to* (if (symbol? to) to (string->symbol to)))
  (define-values (cur _sp _ch) (introspect! s))
  (session-action! s `(rename-rel ,from* ,to*))
  (define line (read-line (session-out s)))
  (unless (and (string? line) (regexp-match? #px" 1\\)\\s*$" line))
    (error 'session (format "rename-rel ~a -> ~a refused: ~a" from* to* line)))
  (echo! s line)
  (record-step! s `(rename-rel ,from* ,to*) #:at cur)
  (touch! s (list to*))
  (set-session-renames! s (cons (list from* to* cur) (session-renames s))))

(define (session-drop! s rel)
  (define rel* (if (symbol? rel) rel (string->symbol rel)))
  (define-values (cur _sp _ch) (introspect! s))
  (session-action! s `(drop-rel ,rel*))
  (define line (read-line (session-out s)))
  (unless (and (string? line) (regexp-match? #px" 1\\)\\s*$" line))
    (error 'session (format "drop-rel ~a refused: ~a" rel* line)))
  (echo! s line)
  (record-step! s `(drop-rel ,rel*) #:at cur))

;; Run one program atop the session (docs/incremental.md §0.4): one
;; version boundary PER PROGRAM of its run tree (E0c) -- announce the
;; segment's write-set, import its frozen ground facts, then drive each
;; stratum to fixpoint, recording its manifest for later cone assembly.
;; Sources are captured for the save's prog.sexpr (unless replaying
;; ancestor history, whose sources belong to the ancestor layers).
(define (allocate-version-event! s writes kind)
  (define event (session-next-event s))
  (set-session-next-event! s (add1 event))
  (define rows
    (for/list ([rel (in-list (sort (remove-duplicates writes) symbol<?))]
               [slot (in-naturals)])
      (define key (format "v1:~a:~a:~a" (session-layer-id s) event slot))
      (list rel key event slot kind)))
  (set-session-descriptors! s (append (session-descriptors s) rows))
  (for/list ([row (in-list rows)]) (take row 2)))

(define (session-run! s prog #:version-events [supplied-events #f])
  ;; Segments compile against the LIVE schema once the session has any
  ;; state (0.D2): renames, drops, imports, and prior segments' relations
  ;; are all reflected, so later-segment resolution errors come free --
  ;; a program reading a dropped name simply finds no declaration.
  (define manifest
    (cond
      [(or (pair? (session-strata-info s)) (pair? (session-imports s))
           (pair? (session-renames s)))
       (session-schema-manifest s)]
      [(session-db s) (db-full-manifest (session-db s))]
      [else (hash)]))
  (define-values (strata _partition _edb-boundary _frozen-dirs groups)
    (parameterize ([current-source-capture
                    (and (not (session-replaying? s)) (session-sources s))])
      (compile-strata prog manifest #:split-facts? #f)))
  (define group-write-sets
    (let loop ([gs groups] [remaining strata] [out '()])
      (match gs
        ['() (reverse out)]
        [(cons (cons n g-frozen) more)
         (define g-strata (take remaining n))
         (loop more (drop remaining n)
               (cons (segment-write-set g-strata g-frozen) out))])))
  (define version-events
    (or supplied-events
        (for/list ([ws (in-list group-write-sets)])
          (allocate-version-event! s ws 'program-inherit))))
  (unless (= (length version-events) (length groups))
    (error 'session "recipe supplied ~a version events for ~a program groups"
           (length version-events) (length groups)))
  (record-step! s `(run ,prog (version-events ,@version-events)))
  (let run-groups ([gs groups] [remaining strata] [ves version-events])
    (match gs
      ['() (void)]
      [(cons (cons n g-frozen) more)
       (define g-strata (take remaining n))
       (define ws (segment-write-set g-strata g-frozen))
       (when (pair? ws)
         (session-action! s `(begin-segment/keyed ,(car ves)))
         (read-one-line! s))   ; (segment P N)
       (touch! s ws)
       (for ([dir (in-list g-frozen)])
         (session-action! s `(import-path ,dir)))
       (for ([sb (in-list g-strata)])
         (push-sbuild! s sb))
       (run-groups more (drop remaining n) (cdr ves))]))
  ;; Running a program is the explicit semantic reopen event for any
  ;; input-only successors accumulated since the prior program event.
  (hash-clear! (session-input-only s)))

;; Queue one signed tuple against an anchor.  Commands remain ordered until
;; flush: `+,-` is a mask on inherited input while `-,+` clears one, so the
;; old syntactic cancellation was not baseline-correct.
(define (session-batch! s sign rel tuple #:at [anchor 'tip])
  (unless (memq sign '(+ -))
    (error 'session "batch sign must be + or -"))
  (define per-anchor (hash-ref! (session-pending s) anchor make-hash))
  (define per-rel (hash-ref! per-anchor rel make-hash))
  (hash-update! per-rel tuple (lambda (commands) (cons sign commands)) '()))

;; Explicit existing-slot edit spelling.  Keep session-batch! as the
;; compatibility alias used by the current harness and recipe reader.
(define session-edit-batch! session-batch!)

;; Create a distinct input-only successor slot at the current JIT tip.  An
;; earlier pipeline point requires a recipe-branch rebuild; refusing it keeps
;; event-time semantics honest.
(define (session-inject-version! s rel #:key [key #f] #:at [anchor 'tip])
  (unless (eq? anchor 'tip)
    (error 'session "inject-version currently requires the JIT tip; rebuild a recipe branch for historical injection"))
  (define rel* (if (symbol? rel) rel (string->symbol rel)))
  (when (and key
             (not (and (string? key)
                       (regexp-match? #px"^[A-Za-z0-9._:-]+$" key))))
    (error 'session
           "VersionKey must be a non-empty portable identifier (letters, digits, '.', '_', ':', '-')"))
  ;; Descriptor allocation precedes the daemon request so the chosen key is
  ;; explicit in both places.  Admission can still fail (notably a stale
  ;; expected revision or duplicate key), so retain a pre-request checkpoint
  ;; and publish the descriptor only with a successfully created VersionId.
  (define old-next-event (session-next-event s))
  (define old-descriptors (session-descriptors s))
  (define (rollback-descriptor!)
    (set-session-next-event! s old-next-event)
    (set-session-descriptors! s old-descriptors))
  (define k
    (cond
      [key
       (unless (session-replaying? s)
         (define event (session-next-event s))
         (set-session-next-event! s (add1 event))
         (set-session-descriptors!
          s (append (session-descriptors s)
                    (list (list rel* key event 0 'input-injection-inherit)))))
       key]
      [else (second (first (allocate-version-event! s (list rel*)
                                                   'input-injection-inherit)))]))
  (define expected (query-update-epoch! s))
  (session-action! s `(begin-update ,expected))
  (define begun (read-line (session-out s)))
  (unless (equal? begun (format "(update-begun ~a)" expected))
    (rollback-descriptor!)
    (error 'session (format "could not begin injection at revision ~a: ~a"
                            expected begun)))
  (echo! s begun)
  (session-action! s `(inject-version ,rel* ,k))
  (define line (read-line (session-out s)))
  (unless (and (string? line) (regexp-match? #px"^\\(injected " line))
    (session-action! s `(abort-update) read-one-line-quiet!)
    (rollback-descriptor!)
    (error 'session (format "inject-version ~a refused: ~a" rel* line)))
  (echo! s line)
  (hash-set! (session-input-only s) rel* k)
  (session-action! s `(commit-update))
  (define committed (read-line (session-out s)))
  (unless (and (string? committed)
               (regexp-match? #px"^\\(update-committed " committed))
    (error 'session (format "could not commit injection: ~a" committed)))
  (echo! s committed)
  (record-step! s `(inject-version ,rel* ,k))
  (touch! s (list rel*))
  (match (read (open-input-string line))
    [`(injected ,_ ,pos ,vid) (values pos vid k)]))

(define (session-inject-batch! s rel adds [dels '()] #:key [key #f])
  (define-values (pos vid k) (session-inject-version! s rel #:key key))
  (for ([t (in-list adds)]) (session-edit-batch! s '+ rel t #:at 'tip))
  (for ([t (in-list dels)]) (session-edit-batch! s '- rel t #:at 'tip))
  (session-flush! s)
  (values pos vid k))

;; Explicit topology event: create an input successor, apply its overlay while
;; it is still input-only, then run a new semantic program event.  session-run!
;; allocates stable VersionKeys for every output and its current boundary
;; policy is explicit inheritance; a future fresh-output policy must be added
;; as a distinct spelling rather than inferred from ordinary injection.
(define (session-inject-and-reopen! s rel prog [adds '()] [dels '()]
                                    #:key [key #f]
                                    #:output-policy [policy 'inherit])
  (unless (eq? policy 'inherit)
    (error 'session
           "inject-and-reopen currently supports only explicit inherited output slots"))
  (define-values (pos vid k) (session-inject-version! s rel #:key key))
  (for ([t (in-list adds)]) (session-edit-batch! s '+ rel t #:at 'tip))
  (for ([t (in-list dels)]) (session-edit-batch! s '- rel t #:at 'tip))
  (when (or (pair? adds) (pair? dels)) (session-flush! s))
  (session-run! s prog)
  (values pos vid k))

;; Import a mini bin-database as a bulk batch payload (§0.3 transport 2)
;; and propagate through its target relations' cones.  `renames` maps
;; source->dest names.  #:at anchors the import at a pipeline position
;; (0.E0b): the payload lands in the versions current there (the daemon's
;; positional import) and the suffix walk propagates it -- the recipe
;; records it at that position, so a replay re-applies it in place.
(define (session-import-delta! s dir [renames '()] #:at [anchor 'tip])
  (import-merge! s dir renames `(import-delta ,dir ,renames) anchor))

;; Hot-link a stored database into the live session (docs/incremental.md
;; §0.9, 0.D5): same import machinery and downstream routing as a bulk
;; payload, but the recipe records a LINK step -- the payload is a
;; reference to data/<db> (and its chain), never copied into the saving
;; layer (externalize-recipe-payloads leaves link steps alone), and the
;; save's manifest records the edge so the DAG (tree/staleness/gc) sees
;; it.  The import reads the target's dirs AS STORED, so a chained/
;; compressed target (whose content lives across its chain) refuses:
;; freeze it first, or -d it as the session's base.
(define (session-link! s db [renames '()] #:at [anchor 'tip])
  (define ddir (string-append "data/" db))
  (when (and (db-meta-file-exists? ddir)
             (pair? (db-meta-manifest (read-db-meta ddir))))
    (error 'session
           (format "link target ~a is a chained database; its on-disk dirs are not its full content -- freeze it first (slog db freeze ~a --as NAME) or load it as the session's base" db db)))
  (import-merge! s ddir renames `(link ,db ,renames) anchor))

(define (import-merge! s dir renames step anchor)
  (define-values (cur strata-pos chains) (introspect! s))
  ;; target rels: the payload's relation dirs (renamed), same scan as
  ;; frozen dirs use
  (define targets
    (for/fold ([acc (set)]) ([p (in-list (if (directory-exists? dir)
                                             (directory-list dir) '()))])
      (define m (regexp-match #px"^(?:table|struct|lat)\\.(.+)\\.arity\\.[0-9]+"
                              (path->string p)))
      (if m
          (let* ([src (cadr m)]
                 [dst (or (for/first ([r (in-list renames)]
                                      #:when (equal? (~a (first r)) src))
                            (~a (second r)))
                          src)])
            (set-add acc (string->symbol dst)))
          acc)))
  (touch! s (set->list targets))
  (cond
    [(eq? anchor 'tip)
     (session-action! s `(import-delta ,dir ,renames))
     ;; the import occupies position `cur` (it advances the counter, like open)
     (set-session-imports! s (cons (list dir renames cur)
                                   (session-imports s)))
     (record-step! s step #:at cur)
     ;; re-introspect (the import advanced the position) and rerun the union
     ;; cone of the targets -- imports are monotone merges, but into full
     ;; indices with no delta staging, so replay-entry (not delta) applies
     (define-values (_cur+ strata-pos+ chains+) (introspect! s))
     (define union-sos (mutable-set))
     (for ([r (in-list (sort (set->list targets) symbol<?))]
           #:when (hash-has-key? chains+ r))
       (define-values (cone _mono?) (cone-of s r strata-pos+ chains+))
       (for ([info (in-list cone)])
         (set-add! union-sos (sinfo-so info))))
     (define union-cone
       (for/list ([p (in-list (session-strata-info s))]
                  #:when (set-member? union-sos (sinfo-so (cdr p))))
         (cdr p)))
     (echo! s (format "(import-delta ~a ~a)" dir (length union-cone)))
     (for ([info (in-list union-cone)])
       (send-maintenance-stratum! s (sinfo-so info)))]
    [else
     ;; anchored import (0.E0b): positional apply, then the suffix walk
     (session-action! s `(import-delta ,dir ,renames ,anchor))
     (set-session-imports! s (cons (list dir renames anchor)
                                   (session-imports s)))
     (record-step! s step #:at anchor)
     (echo! s (format "(import-delta-at ~a ~a)" dir anchor))
     ;; An import anchor is an event position: the import occurs after the
     ;; stratum at `anchor`, so only the strict suffix is replayed.  This is
     ;; deliberately different from an overlay anchored to a VersionInstance
     ;; binding, whose equal-position writer must see the overlay.
     (walk-suffix! s anchor targets strata-pos chains
                   #:include-anchor? #f)]))

;; ---- cone assembly (docs/incremental.md §0.5) ----------------------------

;; Live introspection:
;; (values current-pos scc->pos rel->binding-(ord . pos)-lists).
(define (introspect! s)
  (session-action! s `(pipeline))
  (define pline (read-line (session-out s)))
  (when (eof-object? pline) (error 'session "daemon EOF at introspection"))
  (echo! s pline)
  (match (read (open-input-string pline))
    [`(pipeline (pos ,cur) (evaluation ,_eval) (update-epoch ,_revision)
                (strata ,ss ...)
                (version-ids ,vis ...) ,rels ...)
     (values cur
             (for/hash ([st (in-list ss)])
               (match-define `(s ,scc ,pos ,_name ,_fields ...) st)
               (values scc pos))
             (for/hash ([r (in-list rels)])
               (match-define `(rel ,name ,vs ...) r)
               (values name
                       (for/list ([v (in-list vs)])
                         ;; size -1 = an unbinding marker (drop / rename
                         ;; source): lineage severance for the walk (0.D)
                         (match-define `(v ,ord ,pos ,sz) v)
                         (list ord pos (= sz -1))))))]
    [x (error 'session (format "unparseable (pipeline) reply: ~a" x))]))

;; Identity-rich view used by M0.4 recount.  `vinfo` maps (name . ordinal)
;; to (version-id predecessor-id version-key schema); `sinfo*` maps the original
;; daemon SCC id to (bind-position read-map write-map write-VersionIds).
(define (introspect-identities! s)
  (session-action! s `(pipeline))
  (define pline (read-line (session-out s)))
  (when (eof-object? pline) (error 'session "daemon EOF at introspection"))
  (echo! s pline)
  (match (read (open-input-string pline))
    [`(pipeline (pos ,cur) (evaluation ,_eval) (update-epoch ,_revision)
                (strata ,ss ...)
                (version-ids ,vis ...) ,rels ...)
     (define sinstances
       (for/hash ([st (in-list ss)])
         (match-define `(s ,scc ,pos ,_name
                           (kind ,kind)
                           (reads ,reads ...) (write-map ,writes ...)
                           (writes ,vids ...)) st)
         (values scc (list pos reads writes vids kind))))
     (define vinfo
       (for/hash ([vi (in-list vis)])
         (match-define `(vid ,name ,ord ,vid ,pred ,key (schema ,arity ,sid ,storage)) vi)
         (values (cons name ord) (list vid pred key (list arity sid storage)))))
     (define chains
       (for/hash ([r (in-list rels)])
         (match-define `(rel ,name ,vs ...) r)
         (values name
                 (for/list ([v (in-list vs)])
                   (match-define `(v ,ord ,pos ,sz) v)
                   (list ord pos (= sz -1))))))
     (values cur sinstances chains vinfo)]
    [x (error 'session (format "unparseable identity pipeline reply: ~a" x))]))

(define (chain-positions chains rel)
  (map second (hash-ref chains rel '())))

;; cone(target) closure over candidate entries (cons pos sinfo), in
;; pipeline order; monotone? = #f if any edge INTO the cone is neg/lat.
(define (cone-closure candidates target)
  (let loop ([infos candidates] [wave (set target)] [acc '()] [mono? #t])
    (match infos
      ['() (values (reverse acc) mono?)]
      [(cons (cons _pos info) rest)
       (define hit-kinds
         (for*/list ([entry (in-list (sinfo-reads info))]
                     #:when (set-member? wave (car entry))
                     [k (in-list (cdr entry))])
           k))
       (cond
         [(null? hit-kinds) (loop rest wave acc mono?)]
         [else
          (loop rest
                (for/fold ([w wave]) ([d (in-list (sinfo-dyn info))]) (set-add w d))
                (cons info acc)
                (and mono? (andmap (lambda (k) (eq? k 'pos)) hit-kinds)))])])))

;; cone(rel) for a TIP-anchored batch, given one introspection snapshot:
;; anchor at the target's last binding, candidates = strata bound
;; at-or-after it (earlier strata read a PREDECESSOR version); each
;; strata-info entry carries the daemon scc id of its first push, so the
;; bind-position lookup stays aligned however many re-pushes happened.
;; The rebound guard: a re-pushed stratum binds the LATEST environment,
;; sound only if nothing it touches was rebound after it -- rebound cases
;; go through the ANCHORED walk instead (session-flush! routes them there
;; by anchor).
(define (cone-of s rel strata-pos chains)
  (define anchor
    (let ([c (chain-positions chains rel)])
      (if (null? c) 0 (last c))))
  (define candidates
    (for/list ([p (in-list (session-strata-info s))]
               #:when (>= (hash-ref strata-pos (car p) 0) anchor))
      (cons (hash-ref strata-pos (car p) 0) (cdr p))))
  (define-values (cone mono?) (cone-closure candidates rel))
  (for ([info (in-list cone)])
    (define pos
      (for/first ([c (in-list candidates)] #:when (eq? (cdr c) info)) (car c)))
    (for ([r (in-sequences (in-list (sinfo-dyn info))
                           (in-list (map car (sinfo-reads info))))])
      (when (for/or ([p (in-list (chain-positions chains r))]) (> p pos))
        (error 'session
               (format "~a was rebound after a cone stratum (pos ~a): tip re-entry is unsound here; anchor the batch at the version instead" r pos)))))
  (values cone mono?))

;; ---- the applied input-overlay log (M0.4b) -------------------------------

;; Record the normalized final state for each touched tuple at one physical
;; version: direct, inheritance mask, or neither.  `none` is meaningful when
;; it overrides an ancestor layer's direct/mask state, so it is retained.
(define (log-applied! s rel bind-pos tuples state)
  (define store (if (session-replaying? s) (session-inherited s) (session-applied s)))
  (define per (hash-ref! store (cons rel bind-pos) make-hash))
  (for ([t (in-list tuples)])
    (cond
      [(and (eq? state 'none)
            (or (session-replaying? s)
                (not (hash-has-key?
                      (hash-ref (session-inherited s) (cons rel bind-pos) (hash))
                      t))))
       (hash-remove! per t)]
      [else (hash-set! per t state)])))

;; The normalized overlay at one (rel, version-binding): inherited entries
;; merged under the session's OWN state for the same tuple.
(define (logged-overlays-at s rel bind-pos)
  (define merged (make-hash))
  (for ([store (in-list (list (session-inherited s) (session-applied s)))])
    (define per (hash-ref store (cons rel bind-pos) #f))
    (when per
      (for ([(t state) (in-hash per)]) (hash-set! merged t state))))
  (for/list ([(t state) (in-hash merged)]) `(,state ,t)))

;; Query the authoritative per-VersionInstance overlay for a tuple list.
;; Each result is (direct? masked? predecessor-present? live?).
(define (query-input-states! s rel bind-pos tuples)
  (session-action! s `(input-state ,rel ,bind-pos (,@tuples)))
  (let loop ([states (make-hash)])
    (define line (read-line (session-out s)))
    (when (eof-object? line) (error 'session "daemon EOF at input-state"))
    (match (read (open-input-string line))
      [`(inputstate ,i ,d ,m ,pred ,live)
       (hash-set! states i (map (lambda (x) (= x 1)) (list d m pred live)))
       (loop states)]
      [`(inputstate-done ,n)
       (unless (= n (length tuples))
         (error 'session "short input-state response"))
       (for/list ([i (in-range n)])
         (hash-ref states i
                   (lambda () (error 'session "missing input-state row ~a" i))))]
      [`(error ,why) (error 'session why)]
      [x (error 'session (format "bad input-state response: ~a" x))])))

;; Reduce each tuple's ordered +/- commands against its actual baseline.
;; Result values are (state negative-membership? positive-membership?), where
;; state is the normalized direct/mask/none overlay to persist.
(define (normalize-pending! s rel bind-pos per-rel)
  (define tuples (hash-keys per-rel))
  (define states (query-input-states! s rel bind-pos tuples))
  (for/fold ([out (make-hash)])
            ([t (in-list tuples)] [initial (in-list states)])
    (match-define (list d0 m0 pred? live?) initial)
    (define d d0)
    (define m m0)
    (for ([sign (in-list (reverse (hash-ref per-rel t)))])
      (case sign
        [(+)
         (cond [d (void)]
               [m (set! m #f)]
               [pred? (void)]
               [else (set! d #t)])]
        [(-)
         (cond [d (set! d #f)]
               [(and pred? (not m)) (set! m #t)]
               [else
                ;; M4S: a batch retraction TARGETING a struct relation is
                ;; refused by name (docs/m4s-contract.md) -- content-arity
                ;; tuples classify incoherently against struct storage, so
                ;; the generic derived-only/absent report misleads.  The
                ;; schema round trip runs only on this error path.
                (define kind (hash-ref (session-schema-manifest s) rel #f))
                (error 'session
                       (if (and (pair? kind) (eq? (car kind) 'struct))
                           (format "cannot retract ~a from ~a: ~a is a struct relation (import-delta is the vehicle for struct-embedding input)"
                                   t rel rel)
                           (format "cannot retract ~a from ~a: tuple is ~a"
                                   t rel (if live? "derived-only" "absent"))))])]))
    (unless (and (equal? d d0) (equal? m m0))
      (define before? (or d0 (and pred? (not m0))))
      (define after? (or d (and pred? (not m))))
      (hash-set! out t
                 (list (cond [d 'direct] [m 'mask] [else 'none])
                       (and before? (not after?))
                       (and after? (not before?)))))
    out))

;; ---- flush: route, apply pending batches, propagate ----------------------

;; Resolve one pending anchor for `rel` against the chains: (values
;; ordinal binding-pos last?) of the version current at the anchor.
(define (resolve-anchor chains rel anchor)
  (define chain (hash-ref chains rel '()))
  (when (null? chain)
    (error 'session (format "batch targets unknown relation ~a" rel)))
  (define hit
    (if (eq? anchor 'tip)
        (last chain)
        (for/last ([b (in-list chain)] #:when (<= (second b) anchor)) b)))
  (unless hit
    (error 'session
           (format "batch anchored at ~a precedes every version of ~a (first binding at ~a)"
                   anchor rel (second (first chain)))))
  (when (third hit)
    (error 'session
           (format "~a is unbound ~a (dropped or renamed away); anchor before the severance or use the successor name"
                   rel (if (eq? anchor 'tip) "at the tip" (format "at ~a" anchor)))))
  (match-define (list ord pos _d) hit)
  (values ord pos (equal? hit (last chain))))

(define (session-flush! s)
  (define pending (session-pending s))
  ;; Collect raw command sequences, dropping empties.
  (define raw-groups
    (for*/list ([(anchor per-anchor) (in-hash pending)]
                [(rel per-rel) (in-hash per-anchor)]
                #:when (positive? (hash-count per-rel)))
      (list anchor rel (hash-copy per-rel))))
  (hash-clear! pending)
  (cond
    [(null? raw-groups) (echo! s "(flush 0)")]
    [else
     ;; the inline-transport ceiling (§0.3/C4)
     (for ([g (in-list raw-groups)])
       (when (> (hash-count (third g)) inline-batch-max)
         (error 'session
                (format "inline batch of ~a tuples for ~a exceeds ~a: write a bin database and session-import-delta! it (or link it as a -d input)"
                        (hash-count (third g)) (second g) inline-batch-max))))
     (define-values (_cur strata-pos chains) (introspect! s))
     ;; Resolve and normalize before mutating anything.  Thus a derived-only
     ;; or absent retraction rejects the whole flush with the prior overlay
     ;; intact, and inherited +/- sequences keep their baseline semantics.
     (define groups
       (filter
        values
        (for/list ([g (in-list raw-groups)])
          (match-define (list anchor rel per-rel) g)
          (define-values (ord bind-pos last?) (resolve-anchor chains rel anchor))
          (define normalized (normalize-pending! s rel bind-pos per-rel))
          (and (positive? (hash-count normalized))
               (list anchor rel ord bind-pos last? normalized)))))
     ;; Serialize the complete logical edit (possibly several anchors and
     ;; strata) against one expected settled revision.  The daemon rejects a
     ;; stale writer before any mutation is applied.
     (when (pair? groups)
       (define expected (query-update-epoch! s))
       (session-action! s `(begin-update ,expected))
       (define begun (read-line (session-out s)))
       (unless (equal? begun (format "(update-begun ~a)" expected))
         (error 'session (format "could not begin update at revision ~a: ~a"
                                 expected begun)))
       (echo! s begun))
     ;; split by resolved anchor: groups whose anchor resolves to the
     ;; LATEST version take the tip routing; older versions take the walk.
     ;; A tip group whose cone trips the rebound guard (something a cone
     ;; stratum touches was renamed/rebound after it -- latest-env re-push
     ;; would resolve the old name to nothing) diverts to the walk too:
     ;; positional re-binding is rename-immune (0.D).
     (define-values (tip-groups old-groups)
       (for/fold ([tips '()] [olds '()])
                 ([g (in-list groups)])
         (match-define (list anchor rel ord bind-pos last? per-rel) g)
         (define tip-ok?
           (and last?
                (not (hash-has-key? (session-input-only s) rel))
                (with-handlers ([exn:fail? (lambda (_e) #f)])
                  (cone-of s rel strata-pos chains)
                  #t)))
         (if tip-ok?
             (values (cons (list rel bind-pos per-rel) tips) olds)
             (values tips (cons (list rel ord bind-pos per-rel) olds)))))
     ;; anchored walks first (they may rebuild latest versions), ascending
     (for ([g (in-list (sort old-groups < #:key third))])
       (anchored-walk! s g strata-pos chains))
     (when (pair? tip-groups)
       (tip-flush! s tip-groups strata-pos chains))
     (when (and (null? tip-groups) (null? old-groups))
       (echo! s "(flush 0)"))
     (when (pair? groups)
       (session-action! s `(commit-update))
       (define committed (read-line (session-out s)))
       (unless (and (string? committed)
                    (regexp-match? #px"^\\(update-committed " committed))
         (error 'session (format "could not commit update: ~a" committed)))
       (echo! s committed))]))

;; Tip routing: M1 positive maintenance for certified plain-table cones; M3
;; negative-then-positive maintenance for their acyclic subset; legacy
;; delta/replay for unsupported monotone cones; clear-and-rerun for every
;; unsupported retraction or non-monotone edge.
(define (tip-flush! s tip-groups strata-pos chains)
  (define topology-mono? #t)
  (define union-sos (mutable-set))
  (for ([g (in-list tip-groups)])
    (define-values (cone mono?) (cone-of s (first g) strata-pos chains))
    (unless mono? (set! topology-mono? #f))
    (for ([info (in-list cone)])
      (set-add! union-sos (sinfo-so info))))
  (define union-cone
    (for/list ([p (in-list (session-strata-info s))]
               #:when (set-member? union-sos (sinfo-so (cdr p))))
      (cdr p)))
  (touch! s (for*/list ([info (in-list union-cone)]
                        [h (in-list (sinfo-heads info))])
              h))
  (define (positive-change? change)
    (and (eq? (first change) 'direct) (third change)))
  (define (negative-change? change)
    (or (eq? (first change) 'mask)
        (and (eq? (first change) 'none) (not (third change)))))
  (define has-positive?
    (for*/or ([g (in-list tip-groups)] [(_t change) (in-hash (third g))])
      (positive-change? change)))
  (define has-negative?
    (for*/or ([g (in-list tip-groups)] [(_t change) (in-hash (third g))])
      (negative-change? change)))
  (define edit-shape?
    (for*/and ([g (in-list tip-groups)]
               [(_t change) (in-hash (third g))])
      (or (positive-change? change) (negative-change? change))))
  (define maintenance-names
    (remove-duplicates
     (append (map first tip-groups)
             (append-map sinfo-dyn union-cone)
             (for*/list ([info (in-list union-cone)]
                         [entry (in-list (sinfo-reads info))]
                         #:when (or (member 'pos (cdr entry))
                                    (member 'lat (cdr entry))))
               (car entry)))))
  ;; A lattice edge is intentionally non-monotone in the generic cone test,
  ;; but M6L has its own stricter certificate.  Query local capability once
  ;; the edit form is admissible, then prove the complete topology below.
  (define caps (and edit-shape?
                    (query-positive-capabilities! s chains)))
  (define lattice-names
    (if caps
        (for/list ([r (in-list maintenance-names)]
                   #:when (eq? (hash-ref caps r #f) 'lattice))
          r)
        '()))
  ;; M4S (docs/m4s-contract.md): struct relations are admissible INTERIOR
  ;; cone members; an edit whose TARGET is a struct relation stays refused
  ;; by name (import-delta is the vehicle for struct-embedding input), and
  ;; slice 1 admits struct cones on the acyclic routes only.
  (define struct-names
    (if caps
        (for/list ([r (in-list maintenance-names)]
                   #:when (eq? (hash-ref caps r #f) 'struct))
          r)
        '()))
  (define struct-edit-target?
    (and caps
         (for/or ([g (in-list tip-groups)])
           (eq? (hash-ref caps (first g) #f) 'struct))))
  (define lattice-head-names
    (remove-duplicates
     (for*/list ([info (in-list union-cone)]
                 [h (in-list (sinfo-heads info))]
                 #:when (member h lattice-names))
       h)))
  ;; Starting from a closed lattice head, collect its reader strata and their
  ;; ordinary downstream closure.  Everything before/outside that wave is a
  ;; producer stratum and settles before the replacement pair is published.
  (define lattice-consumer-cone
    (let ([wave (mutable-set)])
      (for ([r (in-list lattice-head-names)]) (set-add! wave r))
      (reverse
       (for/fold ([acc '()]) ([info (in-list union-cone)])
         (if (for/or ([entry (in-list (sinfo-reads info))])
               (set-member? wave (car entry)))
             (begin
               (for ([d (in-list (sinfo-dyn info))]) (set-add! wave d))
               (cons info acc))
             acc)))))
  (define lattice-producer-cone
    (for/list ([info (in-list union-cone)]
               #:unless (memq info lattice-consumer-cone))
      info))
  ;; M6L slices 1+2: root contributor state is produced by an acyclic positive
  ;; cone.  Slice 2 additionally permits a closed lattice read followed only
  ;; by acyclic positive plain-table consumers.  Recursive consumers, lattice
  ;; heads below the boundary, negation, and direct lattice edits fall back.
  (define lattice-shape-certified?
    (or (null? lattice-names)
        (and (pair? lattice-head-names)
             (pair? lattice-producer-cone)
             (for/and ([r (in-list lattice-names)])
               (member r lattice-head-names))
             (for/and ([g (in-list tip-groups)])
               (not (eq? (hash-ref caps (first g) #f) 'lattice)))
             (for/and ([info (in-list union-cone)]) (sinfo-acyclic? info))
             (for*/and ([info (in-list lattice-producer-cone)]
                        [entry (in-list (sinfo-reads info))]
                        [kind (in-list (cdr entry))])
               (eq? kind 'pos))
             (for*/and ([info (in-list lattice-consumer-cone)]
                        [entry (in-list (sinfo-reads info))]
                        [kind (in-list (cdr entry))])
               (and (member kind '(pos lat))
                    (or (not (eq? kind 'lat))
                        (member (car entry) lattice-names))))
             (for*/and ([info (in-list lattice-consumer-cone)]
                        [d (in-list (sinfo-dyn info))])
               (not (member d lattice-names))))))
  (define route-shape-certified?
    (or (and (null? lattice-names) topology-mono?)
        (and (pair? lattice-names) lattice-shape-certified?)))
  (define positive-shape?
    (and edit-shape? route-shape-certified?
         has-positive? (not has-negative?)))
  (define structurally-certified?
    (and caps route-shape-certified?
         (for/and ([r (in-list maintenance-names)])
           (hash-ref caps r #f))))
  ;; Establish counts lazily before touching content.  Recount is itself
  ;; transactional and version-local; a warm sidecar makes this a cheap state
  ;; check on later flushes.  Establishment failure is not an update failure:
  ;; the count epoch has published nothing and no edit has been applied yet,
  ;; so retain set semantics by selecting the legacy delta/re-entry route.
  (define recount-ready?
    (and structurally-certified?
         (with-handlers
             ([exn:fail?
               (lambda (e)
                 (echo! s (format "(maintenance-unavailable recount ~s)"
                                  (exn-message e)))
                 #f)])
           (session-recount! s #:only maintenance-names #:lattices? #t)
           #t)))
  (define cstate
    (and recount-ready? (query-maintenance-count-state! s #t)))
  (define counts-certified?
    (and cstate
         (for/and ([r (in-list maintenance-names)])
           (define chain (hash-ref chains r '()))
           (and (pair? chain)
                (let* ([ord (first (last chain))]
                       [row (assoc ord (hash-ref cstate r '()))])
                  (and row (cdr row)))))))
  ;; M4S: struct interior members ride the counted maintenance routes --
  ;; acyclic M1/M3 (slice 1) and the M4T recursive sweep (slice 2).
  ;; Refused by name: struct edit targets (import-delta is the vehicle for
  ;; struct-embedding input) and lattices anywhere in a struct cone
  ;; (M6L/M7 own those shapes).
  (define struct-cone-admissible?
    (or (null? struct-names)
        (and (not struct-edit-target?)
             (null? lattice-names))))
  (define m1-eligible?
    (and positive-shape? structurally-certified? counts-certified?
         struct-cone-admissible?))
  (define m3-eligible?
    (and structurally-certified? counts-certified? has-negative?
         struct-cone-admissible?
         (for/and ([info (in-list union-cone)]) (sinfo-acyclic? info))))
  ;; M4T (docs/m4t-contract.md): a plain-table cone mixing certified acyclic
  ;; strata with recursive SCC strata takes the DRed sweep.  An edit whose
  ;; target is dynamic in a recursive stratum uses the foundation-aware
  ;; overlay verb (slice 2), and multi-version chains are admissible because
  ;; cone-of's rebound guard already diverts any mid-cone version edge to the
  ;; anchored walk -- on the tip route, inherited support is a stable nonrec
  ;; barrier that can never enter candidacy without an explicit mask edit.
  (define m4t-eligible?
    (and structurally-certified? counts-certified? has-negative?
         (null? lattice-names)
         struct-cone-admissible?       ; M4S slice 2: structs join the sweep
         (for/or ([info (in-list union-cone)])
           (not (sinfo-acyclic? info)))))
  (define m6l2-eligible?
    (and structurally-certified? counts-certified?
         (null? struct-names)          ; lattice+struct cones fall back by name
         (pair? lattice-names) (pair? lattice-consumer-cone)))

  ;; The old set-only delta route remains a fallback for unsupported shapes.
  (define delta-eligible?
    (and positive-shape? (= 1 (length union-cone))))
  (define (apply-edits! #:stage-direct? [stage-direct? #f])
    (for ([g (in-list tip-groups)])
      (match-define (list rel bind-pos per-rel) g)
      (define rows
        (for/list ([(t change) (in-hash per-rel)])
          `(,(first change) ,t)))
      (touch! s (list rel))
      (session-action! s `(set-overlay ,rel -1 (,@rows)))
      (read-one-line! s)
      (when stage-direct?
        (session-action! s
                         `(stage-batch ,rel
                                       (,@(for/list ([row (in-list rows)])
                                            (second row))))))
      (for ([state '(direct mask none)])
        (log-applied! s rel bind-pos
                      (for/list ([row (in-list rows)] #:when (eq? (first row) state))
                        (second row))
                      state))))
  (define positive-apply-ok? #t)
  (define (apply-positive-edits!)
    (for ([g (in-list tip-groups)])
      (match-define (list rel bind-pos per-rel) g)
      (define tuples
        (for/list ([(t change) (in-hash per-rel)] #:when (positive-change? change)) t))
      (when (pair? tuples)
        (touch! s (list rel))
        (session-action! s `(set-overlay-positive ,rel (,@tuples)))
        (define reply (read-line (session-out s)))
        (unless (equal? reply
                        (format "(overlay-positive ~a ~a ~a)"
                                rel (length tuples) (length tuples)))
          (set! positive-apply-ok? #f))
        (echo! s reply)
        (log-applied! s rel bind-pos tuples 'direct))))
  (define negative-apply-ok? #t)
  ;; `dred-names` (M4T, docs/m4t-contract.md): relations dynamic in a
  ;; recursive stratum of the maintained cone take the foundation-aware
  ;; retraction verb -- presence semantics would leave a row live on
  ;; recursive support that the sweep may prove unfounded.
  (define (apply-negative-edits! #:dred-names [dred-names '()])
    (for ([g (in-list tip-groups)])
      (match-define (list rel bind-pos per-rel) g)
      (define rows
        (for/list ([(t change) (in-hash per-rel)] #:when (negative-change? change))
          (list t change)))
      (define tuples (map first rows))
      (when (pair? tuples)
        (touch! s (list rel))
        (define dred? (and (member rel dred-names) #t))
        (session-action! s `(,(if dred?
                                  'set-overlay-negative-dred
                                  'set-overlay-negative)
                             ,rel (,@tuples)))
        (define reply (read-line (session-out s)))
        (unless (equal? reply
                        (format "(~a ~a ~a ~a)"
                                (if dred? "overlay-negative-dred" "overlay-negative")
                                rel (length tuples) (length tuples)))
          (set! negative-apply-ok? #f))
        (echo! s reply)
        (for ([state '(mask none)])
          (log-applied! s rel bind-pos
                        (for/list ([row (in-list rows)]
                                   #:when (eq? (first (second row)) state))
                          (first row))
                        state)))))
  (define (run-maintenance-phase! infos sign get-so
                                  #:lattice-replacements?
                                  [lattice-replacements? #f])
    (for ([info (in-list infos)])
      (define plain-reads
        (remove-duplicates
         (for/list ([entry (in-list (sinfo-reads info))]
                    #:when (member 'pos (cdr entry)))
           (car entry))))
      (when (pair? plain-reads)
        (session-action! s
                         `(stage-update-transitions signed ,sign ,@plain-reads))
        (read-one-line! s))
      (when lattice-replacements?
        (define lattice-reads
          (remove-duplicates
           (for/list ([entry (in-list (sinfo-reads info))]
                      #:when (member 'lat (cdr entry)))
             (car entry))))
        (when (pair? lattice-reads)
          (session-action!
           s `(stage-lattice-replacements signed ,sign ,@lattice-reads))
          (read-one-line! s)))
      (send-maintenance-stratum! s (get-so info))))
  (define (rerun-cone!)
    ;; clear cone-written relations, EXCEPT those also written by non-cone
    ;; strata (shared diagnostic side channels)
    (define cone-dyn
      (for*/set ([info (in-list union-cone)] [d (in-list (sinfo-dyn info))]) d))
    (define noncone-dyn
      (for*/set ([p (in-list (session-strata-info s))]
                 #:unless (set-member? union-sos (sinfo-so (cdr p)))
                 [d (in-list (sinfo-dyn (cdr p)))])
        d))
    (define clear-set
      (sort (set->list (set-subtract cone-dyn noncone-dyn)) symbol<?))
    (for ([r (in-list clear-set)])
      (session-action! s `(clear-rel ,r)))
    (echo! s (format "(route rerun ~a ~a)" (length union-cone) (length clear-set)))
    (for ([info (in-list union-cone)])
      (send-maintenance-stratum! s (sinfo-so info))))
  (cond
    [m6l2-eligible?
     ;; Settle every producer phase first.  LatticeMaintainTask coalesces all
     ;; repairs for a key across those phases; only then do consumers receive
     ;; the epoch-entry row negatively and the final row positively.
     (define settled? #t)
     (when has-negative?
       (apply-negative-edits!)
       (if negative-apply-ok?
           (begin
             (echo! s
                    (format "(route maintain-lattice-producers-negative ~a)"
                            (length lattice-producer-cone)))
             (run-maintenance-phase!
              lattice-producer-cone -1
              (lambda (info) ((sinfo-negative-maintenance info)))))
           (begin
             (set! settled? #f)
             (echo! s "(maintenance-unavailable negative-input)"))))
     (when (and settled? has-negative?
                (not (query-update-counts-valid! s)))
       (set! settled? #f))
     (when (and settled? has-positive?)
       (apply-positive-edits!)
       (if positive-apply-ok?
           (begin
             (echo! s
                    (format "(route maintain-lattice-producers-positive ~a)"
                            (length lattice-producer-cone)))
             (run-maintenance-phase!
              lattice-producer-cone 1
              (lambda (info) ((sinfo-maintenance info)))))
           (begin
             (set! settled? #f)
             (echo! s "(maintenance-unavailable positive-input)"))))
     (when (and settled? has-positive?
                (not (query-update-counts-valid! s)))
       (set! settled? #f))
     (when settled?
       (echo! s
              (format "(route maintain-lattice-consumers-negative ~a)"
                      (length lattice-consumer-cone)))
       (run-maintenance-phase!
        lattice-consumer-cone -1
        (lambda (info) ((sinfo-negative-maintenance info)))
        #:lattice-replacements? #t)
       (unless (query-update-counts-valid! s) (set! settled? #f)))
     (when settled?
       (echo! s
              (format "(route maintain-lattice-consumers-positive ~a)"
                      (length lattice-consumer-cone)))
       (run-maintenance-phase!
        lattice-consumer-cone 1
        (lambda (info) ((sinfo-maintenance info)))
        #:lattice-replacements? #t)
       (unless (query-update-counts-valid! s) (set! settled? #f)))
     (unless settled?
       ;; Counts are cache state.  Once any signed phase has touched content,
       ;; normalize the requested overlay and rebuild the full cone before the
       ;; enclosing update epoch commits.
       (apply-edits!)
       (rerun-cone!))]
    [m3-eligible?
     (apply-negative-edits!)
     (cond
       [negative-apply-ok?
        (echo! s (format "(route maintain-negative ~a)" (length union-cone)))
        (run-maintenance-phase! union-cone -1
                                (lambda (info) ((sinfo-negative-maintenance info))))
        (cond
          [(query-update-counts-valid! s)
           (when has-positive?
             (apply-positive-edits!)
             (if positive-apply-ok?
                 (begin
                   (echo! s (format "(route maintain-positive ~a)"
                                    (length union-cone)))
                   (run-maintenance-phase!
                    union-cone 1 (lambda (info) ((sinfo-maintenance info)))))
                 (begin
                   (echo! s "(maintenance-unavailable positive-input)")
                   (apply-edits!)
                   (rerun-cone!))))]
          [else
           ;; Arithmetic failure leaves the epoch private.  Install the already
           ;; normalized target overlay generically and rebuild before commit.
           (apply-edits!)
           (rerun-cone!)])]
       [else
        (echo! s "(maintenance-unavailable negative-input)")
        (apply-edits!)
        (rerun-cone!)])]
    [m4t-eligible?
     ;; M4T (docs/m4t-contract.md): the ordinary topological negative walk,
     ;; with each recursive stratum swept by the DRed flavor; then reseed the
     ;; rec>0 candidates once the WHOLE walk settles (every journaled row is
     ;; still absent from FULL while downstream stages its DeltaMinus); then
     ;; the existing M1 positive phase rebuilds -- even for a negative-only
     ;; batch, since reseeded rows are absent-to-present transitions.
     (define settled? #t)
     (define reseeded 0)
     ;; Edits targeting a relation dynamic in a recursive stratum take the
     ;; foundation-aware verb: foundation loss with surviving rec enters
     ;; candidacy at apply time and the sweep decides reseed or discard.
     (define head-edited
       (for/list ([g (in-list tip-groups)]
                  #:when (for/or ([info (in-list union-cone)]
                                  #:unless (sinfo-acyclic? info))
                           (member (first g) (sinfo-dyn info))))
         (first g)))
     (apply-negative-edits! #:dred-names head-edited)
     (if negative-apply-ok?
         (begin
           (echo! s (format "(route maintain-recursive-negative ~a)"
                            (length union-cone)))
           (run-maintenance-phase!
            union-cone -1
            (lambda (info)
              (if (sinfo-acyclic? info)
                  ((sinfo-negative-maintenance info))
                  ((sinfo-recursive-negative-maintenance info))))))
         (begin
           (set! settled? #f)
           (echo! s "(maintenance-unavailable negative-input)")))
     (when (and settled? (not (query-update-counts-valid! s)))
       (set! settled? #f))
     (when settled?
       (define swept
         (remove-duplicates
          (for*/list ([info (in-list union-cone)]
                      #:unless (sinfo-acyclic? info)
                      [d (in-list (sinfo-dyn info))])
            d)))
       (session-action! s `(dred-reseed ,@swept))
       (define reply (read-line (session-out s)))
       (echo! s reply)
       (match (regexp-match #px"^\\(dred-reseeded (\\d+) (\\d+)\\)$" reply)
         [(list _ r _) (set! reseeded (string->number r))]
         [_ (set! settled? #f)])
       (when (and settled? (not (query-update-counts-valid! s)))
         (set! settled? #f)))
     (when (and settled? (or (> reseeded 0) has-positive?))
       (when has-positive? (apply-positive-edits!))
       (if positive-apply-ok?
           (begin
             (echo! s (format "(route maintain-positive ~a)"
                              (length union-cone)))
             (run-maintenance-phase!
              union-cone 1 (lambda (info) ((sinfo-maintenance info))))
             (unless (query-update-counts-valid! s) (set! settled? #f)))
           (begin
             (set! settled? #f)
             (echo! s "(maintenance-unavailable positive-input)"))))
     (unless settled?
       (apply-edits!)
       (rerun-cone!))]
    [m1-eligible?
     (apply-positive-edits!)
     (if positive-apply-ok?
         (begin
           (echo! s (format "(route maintain ~a)" (length union-cone)))
           (run-maintenance-phase!
            union-cone 1 (lambda (info) ((sinfo-maintenance info)))))
         (begin
           (echo! s "(maintenance-unavailable positive-input)")
           (apply-edits!)
           (rerun-cone!)))]
    [delta-eligible?
     (define delta-so ((sinfo-delta (first union-cone))))
     (apply-edits! #:stage-direct? #t)
     (echo! s "(route delta 1)")
     (send-maintenance-stratum! s delta-so)]
    [(and topology-mono? (not has-negative?))
     (apply-edits!)
     (echo! s (format "(route reenter ~a)" (length union-cone)))
     (for ([info (in-list union-cone)])
       (send-maintenance-stratum! s (sinfo-so info)))]
    [else
     (apply-edits!)
     (rerun-cone!)]))

;; The ANCHORED walk (0.C, §0.4-§0.6): one old-anchored (rel, version)
;; batch group -- apply to the anchored version in place, then replay the
;; pipeline suffix over the edited history (walk-suffix!).
(define (anchored-walk! s group strata-pos chains)
  (match-define (list rel ord bind-pos per-rel) group)
  (define rows
    (for/list ([(t change) (in-hash per-rel)]) `(,(first change) ,t)))
  ;; 1. apply to the anchored version in place; log at its binding.  If
  ;; the version's writer re-runs below, the rebuild wipes and the log
  ;; re-applies -- the §0.5 mode-2 "copy predecessor ± batch"; if not (a
  ;; fresh binding anchored at its writer's own position), this apply IS
  ;; the version rebuild and writer-derived deletions keep the
  ;; replay-deletion caveat.
  (touch! s (list rel))
  (session-action! s `(set-overlay ,rel ,bind-pos (,@rows)))
  (read-one-line! s)
  (for ([state '(direct mask none)])
    (log-applied! s rel bind-pos
                  (for/list ([row (in-list rows)] #:when (eq? (first row) state))
                    (second row))
                  state))
  (walk-suffix! s bind-pos (set rel) strata-pos chains
                #:announce (lambda (n)
                             (echo! s (format "(route anchored ~a ~a ~a)"
                                              rel bind-pos n)))))

;; Replay the pipeline suffix after an in-place edit at `bind-pos` seeded
;; by `affected0` (the edited relations).
;;
;; Pass 1 (pure): forward over strata AND rename events in position order,
;; growing the affected set through manifest HEADS (side channels
;; deliberately never propagate; renames TRANSLATE the set across the
;; boundary) and collecting the re-run set: a stratum re-runs iff it reads
;; OR heads an affected relation.
;;
;; Pass 2 (events, position-ordered; at equal positions bindings <
;; batch/import re-applies < strata): an affected relation's binding at
;; pos >= anchor rebuilds -- ordinal 0 clears (first registration, no
;; predecessor), ordinal k>0 refreshes (re-copy predecessor + re-seed
;; allocators); logged batches at a rebuilt version re-apply right after
;; its rebuild (under EVERY name that anchors to it, following rename
;; aliases); logged IMPORTS at positions past the anchor re-apply
;; positionally (0.E0b -- monotone merges, so re-application is idempotent
;; where nothing was rebuilt and restorative where something was); re-run
;; strata go bind-at + re-push (positional reload + P-environment
;; registration).  The anchored version itself is exempt (its rebuild is
;; the in-place batch apply).
(define (walk-suffix! s bind-pos affected0 strata-pos chains
                      #:announce [announce void]
                      #:include-anchor? [include-anchor? #t])
  (define strata+pos
    (sort (for/list ([p (in-list (session-strata-info s))])
            (cons (hash-ref strata-pos (car p) 0) (cdr p)))
          < #:key car))
  (define rename-events   ; (list from to pos), ascending, post-anchor only
    (sort (filter (lambda (rn) (> (third rn) bind-pos)) (session-renames s))
          < #:key third))
  (define-values (affected rerun)
    (let loop ([sps strata+pos] [rns rename-events]
               [affected affected0] [rerun '()])
      (cond
        [(and (null? sps) (null? rns)) (values affected (reverse rerun))]
        [(and (pair? rns)
              (or (null? sps) (< (third (car rns)) (car (car sps)))))
         (match-define (list from to _p) (car rns))
         (loop sps (cdr rns)
               (if (set-member? affected from) (set-add affected to) affected)
               rerun)]
        [else
         (match-define (cons pos info) (car sps))
         (cond
           ;; A relation first declared by a reader/writer stratum is bound at
           ;; that stratum's own position.  An input overlay anchored to that
           ;; binding is logically visible before the stratum runs, so the
           ;; equal-position stratum belongs to the replay suffix.
           [(if include-anchor?
                (< pos bind-pos)
                (<= pos bind-pos))
            (loop (cdr sps) rns affected rerun)]
           [(or (for/or ([r (in-list (map car (sinfo-reads info)))])
                  (set-member? affected r))
                (for/or ([h (in-list (sinfo-heads info))])
                  (set-member? affected h)))
            (loop (cdr sps) rns
                  (for/fold ([a affected]) ([h (in-list (sinfo-heads info))])
                    (set-add a h))
                  (cons (car sps) rerun))]
           [else (loop (cdr sps) rns affected rerun)])])))
  ;; pass 2, WRITER-DRIVEN: each re-run stratum's affected heads resolve
  ;; to the versions it writes at its position; each rebuilds exactly
  ;; once, right before the stratum -- an inheritance continuation
  ;; refreshes, a fresh binding clears.  Rename-target bindings are pure
  ;; aliases and never rebuild.
  (define rename-targets   ; (cons to pos) -> #t
    (for/hash ([rn (in-list (session-renames s))])
      (values (cons (second rn) (third rn)) #t)))
  (define (chain-binding-at r p)
    (for/last ([b (in-list (hash-ref chains r '()))] #:when (<= (second b) p)) b))
  ;; every (name . binding-pos) that aliases the version bound as (h, bpos):
  ;; h itself, plus rename successors whose source resolved to this binding
  (define (alias-anchors h bpos)
    (let grow ([name h] [pos bpos] [acc (list (cons h bpos))])
      (for/fold ([acc acc]) ([rn (in-list (session-renames s))])
        (match-define (list from to rpos) rn)
        (define src
          (and (equal? from name)
               (for/last ([b (in-list (hash-ref chains from '()))]
                          #:when (and (< (second b) rpos) (not (third b))))
                 b)))
        (if (and src (= (second src) pos))
            (grow to rpos (cons (cons to rpos) acc))
            acc))))
  (define rebuilt (mutable-set))
  (define events '())   ; (list pos tie thunk)
  (for ([sp (in-list rerun)])
    (match-define (cons pos info) sp)
    (for ([h (in-list (sinfo-heads info))] #:when (set-member? affected h))
      (define b (chain-binding-at h pos))
      (when (and b (not (third b))
                 (not (hash-ref rename-targets (cons h (second b)) #f))
                 (not (set-member? rebuilt (cons h (first b)))))
        (set-add! rebuilt (cons h (first b)))
        (match-define (list bord bpos _d) b)
        (define chain (hash-ref chains h '()))
        (define continuation?
          (and (> bord 0) (not (third (list-ref chain (sub1 bord))))))
        (set! events
              (cons (list pos 0
                          (lambda ()
                            (if continuation?
                                (begin
                                  (session-action! s `(refresh-version ,h ,bord))
                                  (read-one-line! s))
                                (session-action! s `(clear-rel-at ,h ,bpos)))))
                    events))
        (define anchors (alias-anchors h bpos))
        (set! events
              (cons (list pos 1
                          (lambda ()
                            (for ([a (in-list anchors)])
                              (define rows (logged-overlays-at s (car a) (cdr a)))
                              (when (pair? rows)
                                (session-action! s `(set-overlay ,(car a) ,(cdr a) (,@rows)))
                                (read-one-line! s)))))
                    events))))
    (set! events
          (cons (list pos 2
                      (lambda ()
                        (session-action! s `(bind-at ,pos))
                        (send-maintenance-stratum! s (sinfo-so info))))
                events)))
  ;; logged imports past the anchor re-apply at their positions (0.E0b)
  (for ([im (in-list (session-imports s))]
        #:when (> (third im) bind-pos))
    (match-define (list idir irenames ipos) im)
    (set! events
          (cons (list ipos 1
                      (lambda ()
                        (session-action! s `(import-delta ,idir ,irenames ,ipos))))
                events)))
  (define ordered
    (sort events (lambda (a b)
                   (or (< (first a) (first b))
                       (and (= (first a) (first b))
                            (< (second a) (second b)))))))
  (touch! s (set->list affected))
  (announce (length rerun))
  (for ([e (in-list ordered)])
    ((third e))))

;; Direct single-relation re-entry modes (tests/tools; flush is the policy
;; path).  reenter refuses non-monotone cones; rerun accepts everything
;; the rebound guard admits.
(define (session-reenter! s rel)
  (define-values (_cur strata-pos chains) (introspect! s))
  (define-values (cone mono?) (cone-of s rel strata-pos chains))
  (unless mono?
    (error 'session
           (format "non-monotone cone for ~a (neg/lat edge): use rerun (clear-and-rerun, 0.B2)" rel)))
  (echo! s (format "(reenter ~a ~a)" rel (length cone)))
  (for ([info (in-list cone)])
    (send-maintenance-stratum! s (sinfo-so info))))

(define (session-rerun! s rel)
  (define-values (_cur strata-pos chains) (introspect! s))
  (define-values (cone _mono?) (cone-of s rel strata-pos chains))
  (define cone-sos (for/set ([i (in-list cone)]) (sinfo-so i)))
  (define cone-dyn (for*/set ([i (in-list cone)] [d (in-list (sinfo-dyn i))]) d))
  (define noncone-dyn
    (for*/set ([p (in-list (session-strata-info s))]
               #:unless (set-member? cone-sos (sinfo-so (cdr p)))
               [d (in-list (sinfo-dyn (cdr p)))])
      d))
  (define clear-set (sort (set->list (set-subtract cone-dyn noncone-dyn)) symbol<?))
  (for ([r (in-list clear-set)])
    (session-action! s `(clear-rel ,r)))
  (echo! s (format "(rerun ~a ~a ~a)" rel (length cone) (length clear-set)))
  (for ([info (in-list cone)])
    (send-maintenance-stratum! s (sinfo-so info))))

;; ---- save: one new delta layer (0.E1) -------------------------------------

;; Serialise the session as a NEW data/<name> layer: full materialisation
;; (canonical writer, per=100 -- the session-save default, §0.10), the
;; recipe with payloads externalised into delta.<k>/, the segment sources
;; as prog.sexpr, a content signature over the TOUCHED relations (the
;; cone/target scope -- ancestors' signatures cover the rest), and a META
;; whose manifest links the base chain plus any hot-link edges.  Loading
;; the layer replays the recipe (0.E2) -- pending batches are flushed
;; first so the saved log is the applied truth.
(define (session-save! s name)
  (when (for*/or ([(a per-anchor) (in-hash (session-pending s))]
                  [(r per-rel) (in-hash per-anchor)])
          (positive? (hash-count per-rel)))
    (session-flush! s))
  (define deps (db-referenced-by name))
  (unless (null? deps)
    (error 'session
           (format "refusing to overwrite database ~a: it is an input to ~a"
                   name (string-join deps ", "))))
  (define dir (string-append "data/" name))
  (make-directory* dir)
  ;; 1. the materialisation (all latest versions, canonical writer)
  (session-action! s `(write-db ,name))
  ;; 2. signature over the touched relations -- also the sync point: its
  ;;    reply arrives only after the write completed (stdin order)
  (define touched (sort (hash-keys (session-touched s)) symbol<?))
  (define sig
    (cond
      [(null? touched)
       (introspect! s)   ; sync only (pure-batch layer with nothing touched)
       (hash)]
      [else
       (send-plugin! s (action-so `(signature ,@touched)))
       (let loop ([acc (hash)])
         (define line (read-line (session-out s)))
         (cond
           [(eof-object? line) acc]
           [(regexp-match #px"^\\(sig ([^ ]+) ([0-9]+) ([0-9a-f]+)\\)$" line)
            => (lambda (m)
                 (loop (hash-set acc (string->symbol (second m))
                                 (cons (string->number (third m)) (fourth m)))))]
           [(regexp-match? #px"^\\(sig-end\\)$" line) acc]
           [else (echo! s line) (loop acc)]))]))
  (unless (directory-exists? dir)
    (error 'session (format "save failed: data/~a was not written" name)))
  ;; 3. recipe (+ payload placement), sources, signature, META
  (define recipe (externalize-recipe-payloads (session-recipe s) dir))
  (write-recipe dir recipe)
  (define run-entries
    (for/list ([st (in-list (cdr recipe))] #:when (match st [`(run ,_ ,_ ...) #t] [_ #f]))
      (second st)))
  (when (positive? (hash-count (session-sources s)))
    (write-prog-sexpr dir (if (pair? run-entries) (first run-entries) "session")
                      (for/hash ([(k v) (in-hash (session-sources s))])
                        (values k v))))
  (when (positive? (hash-count sig))
    (write-signature-file dir sig))
  (define link-dbs
    (for/list ([st (in-list (cdr recipe))] #:when (match st [`(link ,_ ,_) #t] [_ #f]))
      (second st)))
  (define manifest
    (append (if (session-db s) (list (manifest-entry (session-db s))) '())
            (for/list ([db (in-list link-dbs)]) (manifest-entry db))))
  (define-values (_vcur _vsi _vchains vvinfo) (introspect-identities! s))
  (define id->key
    (for/hash ([(nk vi) (in-hash vvinfo)]) (values (first vi) (third vi))))
  (define descriptor-table
    (for/list ([row (in-list (session-descriptors s))])
      (match-define (list rel key event slot kind) row)
      (define live
        (for/first ([(nk vi) (in-hash vvinfo)] #:when (equal? (third vi) key)) vi))
      `(version-descriptor ,key
                           (event ,event) (slot ,slot) (kind ,kind)
                           (name ,rel)
                           (schema ,(and live (fourth live)))
                           (predecessor ,(and live
                                              (positive? (second live))
                                              (hash-ref id->key (second live) #f))))))
  (define compatibility-map
    (for/list ([(anchor key) (in-hash (session-compat-keys s))])
      `(legacy-anchor ,(car anchor) ,(cdr anchor) ,key)))
  (define m0 (make-db-meta #:kind 'compressed #:pure-edb? #f
                           #:manifest manifest #:per 1.0
                           #:compiler-stamp (current-compiler-stamp)
                           #:idb-rels touched #:edb-rels '()
                           #:extra (list (cons 'recipe? #t)
                                         (cons 'version-format 1)
                                         (cons 'layer-id (session-layer-id s))
                                         (cons 'version-descriptors descriptor-table)
                                         (cons 'legacy-version-map compatibility-map))))
  (write-db-meta (hash-set m0 'stamp
                           (compute-db-stamp m0 #:prog-fingerprint (recipe-digest recipe)))
                 dir)
  (echo! s (format "(saved ~a ~a)" name (length (cdr recipe)))))

;; Close the daemon and drain its remaining output through the echo.
(define (session-close! s)
  (close-output-port (session-in s))
  (let loop ()
    (define line (read-line (session-out s)))
    (unless (eof-object? line) (echo! s line) (loop)))
  (close-input-port (session-out s))
  (when (session-err-thread s) (thread-wait (session-err-thread s)))
  (cond
    [(session-sp s)
     (subprocess-wait (session-sp s))
     (subprocess-status (session-sp s))]
    [else 0]))

;; ---- runslog integration (0.E2) -------------------------------------------

;; Install the recipe-chain loader: the one-shot driver (`slog -d NAME`,
;; verify --replay, freeze) delegates the WHOLE load plan of any chain
;; holding a saved session to this, driving a session facade over its own
;; daemon connection -- one code path for W1 and W2, by construction.
(set-recipe-chain-loader!
 (lambda (in-port out-port steps)
   (define s (make-session-over in-port out-port #:echo displayln))
   (session-execute-load-steps! s steps)))
