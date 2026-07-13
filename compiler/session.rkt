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
;;     tip anchors, by the §0.5 routing rule -- all-adds + single-stratum
;;       monotone cone -> delta-entry (lazily compiled flavor); all-adds +
;;       monotone -> replay-entry; else clear-and-rerun;
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
;; delta-entry (0.B5) and _count (§8B.1, M0) flavors.
(struct sinfo (so dyn reads heads delta count) #:transparent)

;; One live session.
;;   strata-info : list of (cons scc sinfo), oldest first -- scc is the
;;             daemon pipeline id of the stratum's FIRST push (`next-scc`
;;             mirrors the daemon's pipeline length: every stratum .so this
;;             session sends advances it, fresh pushes and re-pushes alike,
;;             so the ids stay aligned however many re-entries happen).
;;   pending : anchor -> rel -> tuple -> '+/'-   (anchor = 'tip | position)
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
                 touched sources [replaying? #:mutable] echo)
  #:transparent)

(define (make-session #:echo [echo displayln])
  (ensure-slogd-exists)
  (define-values (sp out in err)
    (apply subprocess #f #f #f (slogd-argv "daemon/slogd")))
  (define err-thread
    (thread (lambda ()
              (let loop ()
                (define s (read-line err))
                (unless (eof-object? s) (eprintf "~a\n" s) (loop))))))
  (session sp out in err-thread #f '() 0 (make-hash) (make-hash) (make-hash)
           '() '() '() (make-hash) (make-hash) #f echo))

;; A session facade over an existing daemon connection (the one-shot
;; driver's, for recipe-chain loads -- runslog's recipe-chain-loader hook).
;; next-scc initialises from live introspection so cone bookkeeping aligns
;; with whatever the connection already pushed.
(define (make-session-over in-port out-port #:echo [echo displayln])
  (define s (session #f out-port in-port #f #f '() 0 (make-hash) (make-hash)
                     (make-hash) '() '() '() (make-hash) (make-hash) #f echo))
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

;; Send one FRESH stratum (recording its manifest info for cone assembly)
;; and drive it.
(define (push-sbuild! s sb)
  (match-define (cons so _tag) ((sbuild-runnable sb)))
  (define-values (dyn reads heads) (read-stratum-meta (sbuild-hash sb)))
  (set-session-strata-info!
   s (append (session-strata-info s)
             (list (cons (session-next-scc s)
                         (sinfo so dyn reads heads
                                (sbuild-delta sb) (sbuild-count sb))))))
  (send-stratum! s so))

;; The count round (docs/incremental.md §8B.1-§8B.2, M0.2+M0.3): run the
;; _count flavor of a selection of strata over the resident settled
;; fixpoint, in pipeline order.  Each flavor fires its rules exactly once
;; over FULL indices (staged chains stage-ordered through their wide
;; temps) and folds per-tuple (input | nonrec | rec) contributions into
;; the relations' count sidecars; nothing is inserted, so the resident
;; content is untouched.
;;
;;   (session-recount! s)              whole pipeline, tip environment
;;   (session-recount! s #:rel R)      R's counting cone: R's downstream
;;                                     closure plus every stratum WRITING
;;                                     into it (a retraction sweep needs
;;                                     counts on everything it may delete
;;                                     from, and a relation's own counts
;;                                     come from its writers)
;;   (session-recount! s #:at P)       per-version counts: the pipeline
;;                                     prefix (strata bound at-or-before
;;                                     P), each re-pushed under bind-at P
;;                                     (registrations resolve through P's
;;                                     environment; no reload)
;;   (session-recount! s #:force? #t)  drop ALL count state first
;;
;; Laziness (§8B.2): a stratum is SKIPPED when every relation it writes is
;; already `counted` at the walk's position -- its contributions are in
;; the sidecars.  The daemon's CountTask carries the same check per
;; relation (a closed walk never gets folded onto), so driver-side
;; skipping is an optimization, never load-bearing.  The walk closes with
;; (mark-counted N...): exactly the relations ALL of whose writer strata
;; ran or were skipped become `counted`; a sidecar-bearing relation not
;; named (a cross-stratum error arm whose other writer sat outside a cone
;; walk, say) holds partial contributions and its state is dropped.
;;
;; v1 limits (documented in the M0 STATUS block): a walk crossing a
;; severance (a selected stratum referencing a name dropped/renamed at
;; the bind position) is refused -- recount before the severance, or at
;; the successor name; re-entered strata count where their first push
;; bound.
(define (session-recount! s #:rel [rel #f] #:at [at #f] #:force? [force? #f])
  (when force?
    (session-action! s `(clear-counts) read-one-line-quiet!))
  (define-values (_cur strata-pos chains) (introspect! s))
  (define p (or at +inf.0))
  (define entries                       ; (list pos sinfo), pipeline order
    (for/list ([e (in-list (session-strata-info s))]
               #:when (<= (hash-ref strata-pos (car e) 0) p))
      (list (hash-ref strata-pos (car e) 0) (cdr e))))
  ;; the counting cone: downstream closure of rel, then pull in every
  ;; prefix stratum that WRITES a wave relation
  (define wave
    (and rel
         (let-values ([(cone _mono)
                       (cone-closure (for/list ([e (in-list entries)])
                                       (cons (first e) (second e)))
                                     rel)])
           (for*/fold ([w (set rel)])
                      ([info (in-list cone)] [d (in-list (sinfo-dyn info))])
             (set-add w d)))))
  (define selected
    (for/list ([e (in-list entries)]
               #:when (or (not wave)
                          (for/or ([d (in-list (sinfo-dyn (second e)))])
                            (set-member? wave d))))
      e))
  ;; severance guard: every name a selected stratum touches must resolve
  ;; live at the bind position
  (for* ([e (in-list selected)]
         [n (in-sequences (in-list (sinfo-dyn (second e)))
                          (in-list (map car (sinfo-reads (second e)))))])
    (define chain (hash-ref chains n '()))
    (define hit (for/last ([b (in-list chain)] #:when (<= (second b) p)) b))
    (when (and hit (third hit))
      (error 'session
             (format "recount: ~a is severed (dropped or renamed) at ~a; recount before the severance or under the successor name"
                     n (if at at "the tip")))))
  ;; laziness: skip strata whose written relations are all counted at the
  ;; walk position ('none = uncountable/unknown there -- nothing to fold)
  (define cstate (query-count-state! s))
  (define (counted-at n)
    (define chain (hash-ref chains n '()))
    (define hit (for/last ([b (in-list chain)] #:when (<= (second b) p)) b))
    (cond
      [(or (not hit) (third hit)) 'none]
      [else (match (assv (first hit) (hash-ref cstate n '()))
              [#f 'none]
              [(cons _ c) c])]))
  (define-values (to-run skipped)
    (partition (lambda (e)
                 (or force?
                     (for/or ([d (in-list (sinfo-dyn (second e)))])
                       (eq? #f (counted-at d)))))
               selected))
  (echo! s (format "(recount ~a ~a ~a)"
                   (length to-run) (length skipped) (length entries)))
  (for ([e (in-list to-run)])
    (when at (session-action! s `(bind-at ,at)))
    (send-stratum! s ((sinfo-count (second e)))))
  ;; close the walk: markable = written by NO stratum outside
  ;; selected-or-skipped (within the prefix)
  (when (pair? to-run)
    (define covered (list->seteq (map second (append to-run skipped))))
    (define markable
      (sort
       (set->list
        (for*/fold ([acc (set)])
                   ([e (in-list selected)] [d (in-list (sinfo-dyn (second e)))])
          (if (for/or ([e2 (in-list entries)]
                       #:unless (set-member? covered (second e2)))
                (memq d (sinfo-dyn (second e2))))
              acc
              (set-add acc d))))
       symbol<?))
    (session-action! s `(mark-counted ,@markable) read-one-line-quiet!)))

;; The per-(relation, version) counted state (§8B.2): name -> list of
;; (ord . counted?), from the (count-state) introspection action.
;; Lattices, index-free versions, severed bindings, and $-diagnostics are
;; absent by construction.
(define (query-count-state! s)
  (session-action! s `(count-state))
  (define line (read-line (session-out s)))
  (when (eof-object? line) (error 'session "daemon EOF at count-state"))
  (echo! s line)
  (match (read (open-input-string line))
    [`(count-state ,es ...)
     (for/fold ([h (hash)]) ([e (in-list es)])
       (match-define `(cnt ,name ,ord ,flag) e)
       (hash-update h name (lambda (l) (cons (cons ord (= flag 1)) l)) '()))]
    [x (error 'session (format "unparseable (count-state) reply: ~a" x))]))

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

;; The collapsed applied-batch log, serialisation-ready (C2): a list of
;; (batch REL POS ((+ v ...) ...) ((- v ...) ...)) sorted by (pos, rel).
;; The session's OWN batches only -- inherited (replayed-ancestor) entries
;; belong to the ancestors' recipes.
(define (session-log s)
  (for/list ([key (in-list (sort (hash-keys (session-applied s))
                                 (lambda (a b)
                                   (or (< (cdr a) (cdr b))
                                       (and (= (cdr a) (cdr b))
                                            (symbol<? (car a) (car b)))))))])
    (define per (hash-ref (session-applied s) key))
    (define (side sign)
      (sort (for/list ([(t sg) (in-hash per)] #:when (eq? sg sign)) t)
            (lambda (a b) (string<? (~a a) (~a b)))))
    `(batch ,(car key) ,(cdr key) ,(side '+) ,(side '-))))

;; The session as a recipe (docs/incremental.md §0.10, C2): the recorded
;; steps in (position, arrival) order -- so a back-anchored import sits at
;; its pipeline place -- plus the collapsed batch log, each batch anchored
;; as (relation, version-ordinal): ordinals are recipe-stable across
;; recompiles (§0.4); raw positions are not, so they are resolved against
;; the live chains here and never serialised.
(define (session-recipe s)
  (define-values (_cur _sp chains) (introspect! s))
  (define ordered-steps
    (map third (sort (reverse (session-steps s))
                     (lambda (a b)
                       (or (< (first a) (first b))
                           (and (= (first a) (first b))
                                (< (second a) (second b))))))))
  `(slog-recipe
    ,@ordered-steps
    ,@(for/list ([entry (in-list (session-log s))])
        (match-define `(batch ,rel ,pos ,adds ,dels) entry)
        (define ord
          (or (for/first ([b (in-list (hash-ref chains rel '()))]
                          #:when (and (= (second b) pos) (not (third b))))
                (first b))
              0))
        `(batch ,rel (v ,ord) ,adds ,dels))))

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
  (set-session-db! s db))

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
    [`(import-delta ,dir ,renames) (session-import-delta! s dir renames)]
    [`(link ,db ,renames) (session-link! s db renames)]
    [`(batch ,rel (v ,ord) ,adds ,dels)
     (queue-anchored-batch! s rel ord adds dels)
     (session-flush! s)]
    [x (error 'session (format "unknown load/edit step: ~a" x))]))

;; Immediate tip apply of signed tuples, LOGGED at the target's current
;; version binding (0.E0d: no input event exists outside the log).  Apply
;; only -- propagation is the caller's (flush routing, or an explicit
;; reenter/rerun as the test harness does).
(define (apply-tuples! s rel adds dels)
  (define rel* (if (symbol? rel) rel (string->symbol rel)))
  (define-values (_cur _sp chains) (introspect! s))
  (define-values (_ord bind-pos _last?) (resolve-anchor chains rel* 'tip))
  (when (pair? adds)
    (session-action! s `(add-batch ,rel* -1 (,@adds)))
    (read-one-line! s)
    (log-applied! s rel* bind-pos adds '+))
  (when (pair? dels)
    (session-action! s `(del-batch ,rel* -1 (,@dels)))
    (read-one-line! s)
    (log-applied! s rel* bind-pos dels '-))
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
        [`(import-delta ,ref ,renames)
         (session-import-delta! s (recipe-payload-dir dir ref) renames)]
        [`(batch ,rel (v ,ord) ,adds ,dels)
         (queue-anchored-batch! s rel ord adds dels)]
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
(define (session-run! s prog)
  (record-step! s `(run ,prog))
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
  (let run-groups ([gs groups] [remaining strata])
    (match gs
      ['() (void)]
      [(cons (cons n g-frozen) more)
       (define g-strata (take remaining n))
       (define ws (segment-write-set g-strata g-frozen))
       (when (pair? ws)
         (session-action! s `(begin-segment ,@ws))
         (read-one-line! s))   ; (segment P N)
       (touch! s ws)
       (for ([dir (in-list g-frozen)])
         (session-action! s `(import-path ,dir)))
       (for ([sb (in-list g-strata)])
         (push-sbuild! s sb))
       (run-groups more (drop remaining n))])))

;; Queue one signed tuple against an anchor: 'tip (default, the current
;; pipeline point) or a pipeline position.  A pending opposite-signed entry
;; for the same tuple at the same anchor collapses to nothing (§0.2);
;; re-queuing the same sign is idempotent.
(define (session-batch! s sign rel tuple #:at [anchor 'tip])
  (define per-anchor (hash-ref! (session-pending s) anchor make-hash))
  (define per-rel (hash-ref! per-anchor rel make-hash))
  (match (hash-ref per-rel tuple #f)
    [#f (hash-set! per-rel tuple sign)]
    [(== sign) (void)]
    [_ (hash-remove! per-rel tuple)]))

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
       (send-stratum! s (sinfo-so info)))]
    [else
     ;; anchored import (0.E0b): positional apply, then the suffix walk
     (session-action! s `(import-delta ,dir ,renames ,anchor))
     (set-session-imports! s (cons (list dir renames anchor)
                                   (session-imports s)))
     (record-step! s step #:at anchor)
     (echo! s (format "(import-delta-at ~a ~a)" dir anchor))
     (walk-suffix! s anchor targets strata-pos chains)]))

;; ---- cone assembly (docs/incremental.md §0.5) ----------------------------

;; Live introspection:
;; (values current-pos scc->pos rel->binding-(ord . pos)-lists).
(define (introspect! s)
  (session-action! s `(pipeline))
  (define pline (read-line (session-out s)))
  (when (eof-object? pline) (error 'session "daemon EOF at introspection"))
  (echo! s pline)
  (match (read (open-input-string pline))
    [`(pipeline (pos ,cur) (strata ,ss ...) ,rels ...)
     (values cur
             (for/hash ([st (in-list ss)])
               (match-define `(s ,scc ,pos ,_name) st)
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

;; ---- the applied-batch log (C3) ------------------------------------------

;; Record applied signed tuples against (rel, version-binding-pos), with
;; live same-point collapse (§0.2): an add and delete of one tuple at one
;; version annihilate in the log -- absent from saves and replays.  While
;; replaying ancestor history the entries land in the INHERITED log
;; (re-applied by walks, never re-serialised).
(define (log-applied! s rel bind-pos tuples sign)
  (define store (if (session-replaying? s) (session-inherited s) (session-applied s)))
  (define per (hash-ref! store (cons rel bind-pos) make-hash))
  (for ([t (in-list tuples)])
    (match (hash-ref per t #f)
      [#f (hash-set! per t sign)]
      [(== sign) (void)]
      [_ (hash-remove! per t)])))

;; The signed set at one (rel, version-binding): inherited entries merged
;; under the session's OWN (an own entry for the same tuple overrides --
;; it happened later).
(define (logged-batches-at s rel bind-pos)
  (define merged (make-hash))
  (for ([store (in-list (list (session-inherited s) (session-applied s)))])
    (define per (hash-ref store (cons rel bind-pos) #f))
    (when per
      (for ([(t sg) (in-hash per)]) (hash-set! merged t sg))))
  (values (for/list ([(t sg) (in-hash merged)] #:when (eq? sg '+)) t)
          (for/list ([(t sg) (in-hash merged)] #:when (eq? sg '-)) t)))

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
  ;; collect (anchor rel tuples-hash), dropping empties
  (define groups
    (for*/list ([(anchor per-anchor) (in-hash pending)]
                [(rel per-rel) (in-hash per-anchor)]
                #:when (positive? (hash-count per-rel)))
      (list anchor rel (hash-copy per-rel))))
  (hash-clear! pending)
  (cond
    [(null? groups) (echo! s "(flush 0)")]
    [else
     ;; the inline-transport ceiling (§0.3/C4)
     (for ([g (in-list groups)])
       (when (> (hash-count (third g)) inline-batch-max)
         (error 'session
                (format "inline batch of ~a tuples for ~a exceeds ~a: write a bin database and session-import-delta! it (or link it as a -d input)"
                        (hash-count (third g)) (second g) inline-batch-max))))
     (define-values (_cur strata-pos chains) (introspect! s))
     ;; split by resolved anchor: groups whose anchor resolves to the
     ;; LATEST version take the tip routing; older versions take the walk.
     ;; A tip group whose cone trips the rebound guard (something a cone
     ;; stratum touches was renamed/rebound after it -- latest-env re-push
     ;; would resolve the old name to nothing) diverts to the walk too:
     ;; positional re-binding is rename-immune (0.D).
     (define-values (tip-groups old-groups)
       (for/fold ([tips '()] [olds '()])
                 ([g (in-list groups)])
         (match-define (list anchor rel per-rel) g)
         (define-values (ord bind-pos last?) (resolve-anchor chains rel anchor))
         (define tip-ok?
           (and last?
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
       (echo! s "(flush 0)"))]))

;; Tip routing (0.B4/0.B5): delta-entry for a single-stratum all-monotone
;; all-adds union cone; replay-entry for monotone adds; clear-and-rerun
;; otherwise.
(define (tip-flush! s tip-groups strata-pos chains)
  (define any-del?
    (for*/or ([g (in-list tip-groups)] [(t sg) (in-hash (third g))])
      (eq? sg '-)))
  (define union-mono? (not any-del?))
  (define union-sos (mutable-set))
  (for ([g (in-list tip-groups)])
    (define-values (cone mono?) (cone-of s (first g) strata-pos chains))
    (unless mono? (set! union-mono? #f))
    (for ([info (in-list cone)])
      (set-add! union-sos (sinfo-so info))))
  (define union-cone
    (for/list ([p (in-list (session-strata-info s))]
               #:when (set-member? union-sos (sinfo-so (cdr p))))
      (cdr p)))
  (touch! s (for*/list ([info (in-list union-cone)]
                        [h (in-list (sinfo-heads info))])
              h))
  (define delta-eligible? (and union-mono? (= 1 (length union-cone))))
  ;; apply the collapsed edits (multi-tuple actions), logging each set at
  ;; its target's version binding
  (define (apply-edits! #:stage-adds? [stage-adds? #f])
    (for ([g (in-list tip-groups)])
      (match-define (list rel bind-pos per-rel) g)
      (define adds (for/list ([(t sg) (in-hash per-rel)] #:when (eq? sg '+)) t))
      (define dels (for/list ([(t sg) (in-hash per-rel)] #:when (eq? sg '-)) t))
      (touch! s (list rel))
      (when (pair? adds)
        (if stage-adds?
            (session-action! s `(stage-batch ,rel (,@adds)))
            (begin (session-action! s `(add-batch ,rel -1 (,@adds)))
                   (read-one-line! s)))
        (log-applied! s rel bind-pos adds '+))
      (when (pair? dels)
        (session-action! s `(del-batch ,rel -1 (,@dels)))
        (read-one-line! s)
        (log-applied! s rel bind-pos dels '-))))
  (cond
    [delta-eligible?
     (define delta-so ((sinfo-delta (first union-cone))))
     (apply-edits! #:stage-adds? #t)
     (echo! s "(route delta 1)")
     (send-stratum! s delta-so)]
    [union-mono?
     (apply-edits!)
     (echo! s (format "(route reenter ~a)" (length union-cone)))
     (for ([info (in-list union-cone)])
       (send-stratum! s (sinfo-so info)))]
    [else
     (apply-edits!)
     ;; clear cone-written relations, EXCEPT those also written by
     ;; non-cone strata (shared diagnostic side channels)
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
       (send-stratum! s (sinfo-so info)))]))

;; The ANCHORED walk (0.C, §0.4-§0.6): one old-anchored (rel, version)
;; batch group -- apply to the anchored version in place, then replay the
;; pipeline suffix over the edited history (walk-suffix!).
(define (anchored-walk! s group strata-pos chains)
  (match-define (list rel ord bind-pos per-rel) group)
  (define adds (for/list ([(t sg) (in-hash per-rel)] #:when (eq? sg '+)) t))
  (define dels (for/list ([(t sg) (in-hash per-rel)] #:when (eq? sg '-)) t))
  ;; 1. apply to the anchored version in place; log at its binding.  If
  ;; the version's writer re-runs below, the rebuild wipes and the log
  ;; re-applies -- the §0.5 mode-2 "copy predecessor ± batch"; if not (a
  ;; fresh binding anchored at its writer's own position), this apply IS
  ;; the version rebuild and writer-derived deletions keep the
  ;; replay-deletion caveat.
  (touch! s (list rel))
  (when (pair? adds)
    (session-action! s `(add-batch ,rel ,bind-pos (,@adds)))
    (read-one-line! s)
    (log-applied! s rel bind-pos adds '+))
  (when (pair? dels)
    (session-action! s `(del-batch ,rel ,bind-pos (,@dels)))
    (read-one-line! s)
    (log-applied! s rel bind-pos dels '-))
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
                      #:announce [announce void])
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
           [(<= pos bind-pos) (loop (cdr sps) rns affected rerun)]
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
                              (define-values (ladds ldels)
                                (logged-batches-at s (car a) (cdr a)))
                              (when (pair? ladds)
                                (session-action! s `(add-batch ,(car a) ,(cdr a) (,@ladds)))
                                (read-one-line! s))
                              (when (pair? ldels)
                                (session-action! s `(del-batch ,(car a) ,(cdr a) (,@ldels)))
                                (read-one-line! s)))))
                    events))))
    (set! events
          (cons (list pos 2
                      (lambda ()
                        (session-action! s `(bind-at ,pos))
                        (send-stratum! s (sinfo-so info))))
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
    (send-stratum! s (sinfo-so info))))

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
    (send-stratum! s (sinfo-so info))))

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
    (for/list ([st (in-list (cdr recipe))] #:when (match st [`(run ,_) #t] [_ #f]))
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
  (define m0 (make-db-meta #:kind 'compressed #:pure-edb? #f
                           #:manifest manifest #:per 1.0
                           #:compiler-stamp (current-compiler-stamp)
                           #:idb-rels touched #:edb-rels '()
                           #:extra (list (cons 'recipe? #t))))
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
