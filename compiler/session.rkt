#lang racket

;; The incremental-session driver (docs/incremental.md §0.2-§0.5, 0.B4/0.C):
;; a resident daemon driven through program segments and signed batches,
;; with the Phase-0 routing rule deciding how each flush propagates.
;;
;;   session        = daemon + per-stratum manifest info + pending batches
;;                    + the applied-batch log (the recipe's batch steps)
;;   session-run!   = one program segment: begin-segment version boundary,
;;                    frozen imports, strata to fixpoint
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
;;       cached .so over the P-environment), and re-apply logged batches
;;       whose target versions were rebuilt.  Sound by the mode-2 argument:
;;       the suffix is a from-scratch run over the edited history.
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
;; Known holes, guarded loudly: anchored replay across an import-delta
;; step (the walk cannot re-order an import; 0.E's recipe rebuild) and
;; anchors that resolve to no version.  Deleting an independently
;; re-derivable row sticks only until its deriving stratum re-runs (the
;; replay-deletion caveat, docs/db-compression.md §12); precise deletion
;; is DRed^c (M4+).

(provide make-session
         session-open!
         session-run!
         session-batch!
         session-import-delta!
         session-link!          ; hot-link a data/ DB (0.D5)
         session-rename!        ; environment operations (0.D1)
         session-drop!
         session-flush!
         session-log            ; the collapsed applied-batch log (C2/C3)
         session-recipe         ; ordered steps + anchored batches (§0.10)
         session-action!        ; low-level: one action + a reader
         session-reenter!       ; direct replay-entry (tests/tools)
         session-rerun!         ; direct clear-and-rerun (tests/tools)
         session-close!
         inline-batch-max)

(require "tools.rkt")
(require "compile.rkt")
(require "actions.rkt")
(require "runslog.rkt")   ; db-full-manifest, segment-write-set

;; §0.3: past a few thousand tuples the inline transport (values baked as
;; literals into an action plugin) stops making sense -- the known ~10k
;; inline-facts ceiling with clang time growing ahead of it.  Per
;; (anchor, relation) per flush.
(define inline-batch-max
  (or (string->number (or (getenv "SLOG_INLINE_MAX") "")) 2048))

;; One stratum's driver-side record, in pipeline order (index = daemon scc
;; id): its cached .so, manifest dynamic-rels/reads/heads, and the thunk
;; that lazily builds its delta-entry flavor (0.B5).
(struct sinfo (so dyn reads heads delta) #:transparent)

;; One live session.
;;   pending : anchor -> rel -> tuple -> '+/'-   (anchor = 'tip | position)
;;   applied : (cons rel version-binding-pos) -> tuple -> '+/'-  -- the
;;             collapsed batch log (§0.2): what a save serialises, and what
;;             the anchored walk re-applies when it rebuilds a version.
;;   imports : list of (list dir renames pos), newest first -- the walk's
;;             guard (anchored replay across an import is 0.E).
(struct session (sp out in err-thread [db #:mutable]
                 [strata-info #:mutable] pending applied [imports #:mutable]
                 [steps #:mutable] [renames #:mutable] echo)
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
  (session sp out in err-thread #f '() (make-hash) (make-hash) '() '() '() echo))

;; The collapsed applied-batch log, serialisation-ready (C2): a list of
;; (batch REL POS ((+ v ...) ...) ((- v ...) ...)) sorted by (pos, rel).
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

;; The session as a recipe (docs/incremental.md §0.10, C2): the ordered
;; open/run/import-delta steps plus the collapsed batch log, each batch
;; anchored as (relation, version-ordinal) -- ordinals are recipe-stable
;; across recompiles (§0.4); raw positions are not, so they are resolved
;; against the live chains here and never serialised.
(define (session-recipe s)
  (define-values (_cur _sp chains) (introspect! s))
  `(slog-recipe
    ,@(reverse (session-steps s))
    ,@(for/list ([entry (in-list (session-log s))])
        (match-define `(batch ,rel ,pos ,adds ,dels) entry)
        (define ord
          (or (for/first ([b (in-list (hash-ref chains rel '()))]
                          #:when (and (= (second b) pos) (not (third b))))
                (first b))
              0))
        `(batch ,rel (v ,ord) ,adds ,dels))))

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

;; Send one action and hand its response stream to `read!` (called with
;; the session's output port; may read as many lines as the action's
;; protocol emits -- nothing for silent actions).
(define (session-action! s spec [read! void])
  (send-plugin! s (action-so spec))
  (read! (session-out s)))

(define (read-one-line! s)
  (define line (read-line (session-out s)))
  (unless (eof-object? line) (echo! s line)))

(define (session-open! s db)
  (set-session-db! s db)
  (set-session-steps! s (cons `(open ,db) (session-steps s)))
  (session-action! s `(open ,db)))

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
;; carry them.
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
  (set-session-steps! s (cons `(rename-rel ,from* ,to*) (session-steps s)))
  (set-session-renames! s (cons (list from* to* cur) (session-renames s))))

(define (session-drop! s rel)
  (define rel* (if (symbol? rel) rel (string->symbol rel)))
  (session-action! s `(drop-rel ,rel*))
  (define line (read-line (session-out s)))
  (unless (and (string? line) (regexp-match? #px" 1\\)\\s*$" line))
    (error 'session (format "drop-rel ~a refused: ~a" rel* line)))
  (echo! s line)
  (set-session-steps! s (cons `(drop-rel ,rel*) (session-steps s))))

;; Run one program segment atop the session (docs/incremental.md §0.4):
;; open a version boundary for its write-set, import its frozen ground
;; facts, then drive each stratum to fixpoint, recording its manifest for
;; later cone assembly.
(define (session-run! s prog)
  (set-session-steps! s (cons `(run ,prog) (session-steps s)))
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
  (define-values (strata partition edb-boundary frozen-dirs)
    (compile-strata prog manifest #:split-facts? #f))
  (define ws (segment-write-set strata frozen-dirs))
  (when (pair? ws)
    (session-action! s `(begin-segment ,@ws))
    (read-one-line! s))   ; (segment P N)
  (for ([dir (in-list frozen-dirs)])
    (session-action! s `(import-path ,dir)))
  (for ([sb (in-list strata)])
    (match-define (cons so _tag) ((sbuild-runnable sb)))
    (define-values (dyn reads heads) (read-stratum-meta (sbuild-hash sb)))
    (set-session-strata-info! s (append (session-strata-info s)
                                        (list (sinfo so dyn reads heads
                                                     (sbuild-delta sb)))))
    (send-plugin! s so)
    (drive-to-fixpoint! s)))

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

;; Import a mini bin-database as a bulk batch payload (§0.3 transport 2),
;; tip-anchored, and propagate through its target relations' cones by the
;; tip routing (replay-entry / clear-and-rerun; the import merged in place,
;; so delta-entry does not apply).  `renames` maps source->dest names.
(define (session-import-delta! s dir [renames '()])
  (import-merge! s dir renames `(import-delta ,dir ,renames)))

;; Hot-link a stored database into the live session (docs/incremental.md
;; §0.9, 0.D5): same import machinery and downstream routing as a bulk
;; payload, but the recipe records a LINK step -- the payload is a
;; reference to data/<db> (and its chain), never copied into the saving
;; layer (externalize-recipe-payloads leaves link steps alone); 0.E2's
;; load re-materialises it recursively.
(define (session-link! s db [renames '()])
  (import-merge! s (string-append "data/" db) renames `(link ,db ,renames)))

(define (import-merge! s dir renames step)
  (define-values (cur _sp0 _ch0) (introspect! s))
  (session-action! s `(import-delta ,dir ,renames))
  ;; the import occupies position `cur` (it advances the counter, like open)
  (set-session-imports! s (cons (list dir renames cur)
                                (session-imports s)))
  (set-session-steps! s (cons step (session-steps s)))
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
    (for/list ([info (in-list (session-strata-info s))]
               #:when (set-member? union-sos (sinfo-so info)))
      info))
  (echo! s (format "(import-delta ~a ~a)" dir (length union-cone)))
  (for ([info (in-list union-cone)])
    (send-plugin! s (sinfo-so info))
    (drive-to-fixpoint! s)))

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
;; at-or-after it (earlier strata read a PREDECESSOR version; strata-info
;; index = scc -- both count fresh pushes; re-entry pushes land at higher
;; sccs, absent from strata-info); then the read-closure.  The rebound
;; guard: a re-pushed stratum binds the LATEST environment, sound only if
;; nothing it touches was rebound after it -- rebound cases go through the
;; ANCHORED walk instead (session-flush! routes them there by anchor).
(define (cone-of s rel strata-pos chains)
  (define anchor
    (let ([c (chain-positions chains rel)])
      (if (null? c) 0 (last c))))
  (define candidates
    (for/list ([info (in-list (session-strata-info s))] [scc (in-naturals)]
               #:when (>= (hash-ref strata-pos scc 0) anchor))
      (cons (hash-ref strata-pos scc 0) info)))
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
;; version annihilate in the log -- absent from saves and replays.
(define (log-applied! s rel bind-pos tuples sign)
  (define per (hash-ref! (session-applied s) (cons rel bind-pos) make-hash))
  (for ([t (in-list tuples)])
    (match (hash-ref per t #f)
      [#f (hash-set! per t sign)]
      [(== sign) (void)]
      [_ (hash-remove! per t)])))

(define (logged-batches-at s rel bind-pos)
  (define per (hash-ref (session-applied s) (cons rel bind-pos) #f))
  (if per
      (values (for/list ([(t sg) (in-hash per)] #:when (eq? sg '+)) t)
              (for/list ([(t sg) (in-hash per)] #:when (eq? sg '-)) t))
      (values '() '())))

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
    (for/list ([info (in-list (session-strata-info s))]
               #:when (set-member? union-sos (sinfo-so info)))
      info))
  (define delta-eligible? (and union-mono? (= 1 (length union-cone))))
  ;; apply the collapsed edits (multi-tuple actions), logging each set at
  ;; its target's version binding
  (define (apply-edits! #:stage-adds? [stage-adds? #f])
    (for ([g (in-list tip-groups)])
      (match-define (list rel bind-pos per-rel) g)
      (define adds (for/list ([(t sg) (in-hash per-rel)] #:when (eq? sg '+)) t))
      (define dels (for/list ([(t sg) (in-hash per-rel)] #:when (eq? sg '-)) t))
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
     (send-plugin! s delta-so)
     (drive-to-fixpoint! s)]
    [union-mono?
     (apply-edits!)
     (echo! s (format "(route reenter ~a)" (length union-cone)))
     (for ([info (in-list union-cone)])
       (send-plugin! s (sinfo-so info))
       (drive-to-fixpoint! s))]
    [else
     (apply-edits!)
     ;; clear cone-written relations, EXCEPT those also written by
     ;; non-cone strata (shared diagnostic side channels)
     (define cone-dyn
       (for*/set ([info (in-list union-cone)] [d (in-list (sinfo-dyn info))]) d))
     (define noncone-dyn
       (for*/set ([info (in-list (session-strata-info s))]
                  #:unless (set-member? union-sos (sinfo-so info))
                  [d (in-list (sinfo-dyn info))])
         d))
     (define clear-set
       (sort (set->list (set-subtract cone-dyn noncone-dyn)) symbol<?))
     (for ([r (in-list clear-set)])
       (session-action! s `(clear-rel ,r)))
     (echo! s (format "(route rerun ~a ~a)" (length union-cone) (length clear-set)))
     (for ([info (in-list union-cone)])
       (send-plugin! s (sinfo-so info))
       (drive-to-fixpoint! s))]))

;; The ANCHORED walk (0.C, §0.4-§0.6): one old-anchored (rel, version)
;; batch group -- apply to the anchored version in place, then replay the
;; pipeline suffix over the edited history.
;;
;; Pass 1 (pure): forward over strata in position order, growing the
;; affected set through manifest HEADS (side channels deliberately never
;; propagate) and collecting the re-run set: a stratum re-runs iff it
;; reads OR heads an affected relation.
;;
;; Pass 2 (events, position-ordered; at equal positions bindings <
;; batch re-applies < strata): an affected relation's binding at pos >=
;; anchor rebuilds -- ordinal 0 clears (first registration, no
;; predecessor), ordinal k>0 refreshes (re-copy predecessor + re-seed
;; allocators); logged batches at a rebuilt version re-apply right after
;; its rebuild; re-run strata go bind-at + re-push (positional reload +
;; P-environment registration).  The anchored version itself is exempt
;; (its rebuild is the in-place batch apply).
(define (anchored-walk! s group strata-pos chains)
  (match-define (list rel ord bind-pos per-rel) group)
  ;; guard: the walk cannot re-order an import/link event (0.E's rebuild)
  (for ([im (in-list (session-imports s))])
    (when (> (third im) bind-pos)
      (error 'session
             (format "batch anchored at ~a precedes an import/link of ~a: anchored replay across imports is 0.E's recipe rebuild"
                     bind-pos (first im)))))
  (define adds (for/list ([(t sg) (in-hash per-rel)] #:when (eq? sg '+)) t))
  (define dels (for/list ([(t sg) (in-hash per-rel)] #:when (eq? sg '-)) t))
  ;; 1. apply to the anchored version in place; log at its binding.  If
  ;; the version's writer re-runs below, the rebuild wipes and the log
  ;; re-applies -- the §0.5 mode-2 "copy predecessor ± batch"; if not (a
  ;; fresh binding anchored at its writer's own position), this apply IS
  ;; the version rebuild and writer-derived deletions keep the
  ;; replay-deletion caveat.
  (when (pair? adds)
    (session-action! s `(add-batch ,rel ,bind-pos (,@adds)))
    (read-one-line! s)
    (log-applied! s rel bind-pos adds '+))
  (when (pair? dels)
    (session-action! s `(del-batch ,rel ,bind-pos (,@dels)))
    (read-one-line! s)
    (log-applied! s rel bind-pos dels '-))
  ;; 2. pass 1: affected + re-run sets -- forward over strata AND rename
  ;; events in position order; renames translate the affected set across
  ;; the boundary (post-rename strata read the successor name).  Side
  ;; channels never propagate (heads are pure rule heads).
  (define strata+pos
    (sort (for/list ([info (in-list (session-strata-info s))] [scc (in-naturals)])
            (cons (hash-ref strata-pos scc 0) info))
          < #:key car))
  (define rename-events   ; (list from to pos), ascending, post-anchor only
    (sort (filter (lambda (rn) (> (third rn) bind-pos)) (session-renames s))
          < #:key third))
  (define-values (affected rerun)
    (let loop ([sps strata+pos] [rns rename-events]
               [affected (set rel)] [rerun '()])
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
  ;; 3. pass 2, WRITER-DRIVEN: each re-run stratum's affected heads
  ;; resolve to the versions it writes at its position; each rebuilds
  ;; exactly once, right before the stratum -- an inheritance continuation
  ;; refreshes (re-copy predecessor + re-seed allocators), a fresh binding
  ;; (first registration, or first after a drop) clears.  Rename-target
  ;; bindings are pure aliases and never rebuild.  A rebuilt version's
  ;; logged batches re-apply under EVERY name that anchors to it
  ;; (following rename aliases) before the writer runs.
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
                        (send-plugin! s (sinfo-so info))
                        (drive-to-fixpoint! s)))
                events)))
  (define ordered
    (sort events (lambda (a b)
                   (or (< (first a) (first b))
                       (and (= (first a) (first b))
                            (< (second a) (second b)))))))
  (echo! s (format "(route anchored ~a ~a ~a)"
                   rel bind-pos (length rerun)))
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
    (send-plugin! s (sinfo-so info))
    (drive-to-fixpoint! s)))

(define (session-rerun! s rel)
  (define-values (_cur strata-pos chains) (introspect! s))
  (define-values (cone _mono?) (cone-of s rel strata-pos chains))
  (define cone-sos (for/set ([i (in-list cone)]) (sinfo-so i)))
  (define cone-dyn (for*/set ([i (in-list cone)] [d (in-list (sinfo-dyn i))]) d))
  (define noncone-dyn
    (for*/set ([i (in-list (session-strata-info s))]
               #:unless (set-member? cone-sos (sinfo-so i))
               [d (in-list (sinfo-dyn i))])
      d))
  (define clear-set (sort (set->list (set-subtract cone-dyn noncone-dyn)) symbol<?))
  (for ([r (in-list clear-set)])
    (session-action! s `(clear-rel ,r)))
  (echo! s (format "(rerun ~a ~a ~a)" rel (length cone) (length clear-set)))
  (for ([info (in-list cone)])
    (send-plugin! s (sinfo-so info))
    (drive-to-fixpoint! s)))

;; Close the daemon and drain its remaining output through the echo.
(define (session-close! s)
  (close-output-port (session-in s))
  (let loop ()
    (define line (read-line (session-out s)))
    (unless (eof-object? line) (echo! s line) (loop)))
  (close-input-port (session-out s))
  (thread-wait (session-err-thread s))
  (subprocess-wait (session-sp s))
  (subprocess-status (session-sp s)))
