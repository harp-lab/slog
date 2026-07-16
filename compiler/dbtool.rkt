#lang racket

;; The data/ database DAG and the `slog db` command (docs/db-compression.md §7).
;;
;; data/ is an immutable object DAG: every database directory links (by an
;; ordered manifest in its META) to the input database(s) it was derived atop.
;; A scan of all data/*/META reconstructs the graph.  This module owns:
;;   - the DAG scan + queries (inputs, dependents, staleness),
;;   - `slog db ls|tree|rm|gc|clear|verify` (invoked as `slog db <sub> ...`),
;;   - the referenced-db immutability guard the save path consults,
;;   - db-load-actions: the manifest-driven open+import sequence that the driver
;;     issues for `-d NAME` on a compressed database (open the EDB root, import
;;     the layer) -- at per=100% this reconstitutes the exact database with no
;;     replay (P1 adds recompute for per<100%).

(provide slog-db-command
         db-load-actions
         db-load-steps
         db-referenced-by
         db-exists?
         db-managed?
         db-chain-has-edits?
         db-chain-edits-digest
         db-encoding-mismatch)

(require "dbmeta.rkt")
(require racket/format)

(define DATA "data")

;; ---------------------------------------------------------------------------
;; DAG scan
;; ---------------------------------------------------------------------------

(define (db-dir name) (build-path DATA name))
(define (db-exists? name) (directory-exists? (db-dir name)))
(define (db-managed? name) (db-meta-file-exists? (db-dir name)))

;; All database directory names under data/ (each immediate subdirectory).
(define (all-db-names)
  (cond
    [(not (directory-exists? DATA)) '()]
    [else
     (sort
      (for/list ([e (in-list (directory-list DATA))]
                 #:when (directory-exists? (build-path DATA e)))
        (path->string e))
      string<?)]))

;; META of a db, or #f if it has none (a plain/legacy --out-db database).
(define (db-meta-of name)
  (and (db-managed? name)
       (with-handlers ([db-meta-error? (lambda (_) #f)])
         (read-db-meta (db-dir name)))))

;; Input db names of `name` (its manifest links).
(define (db-inputs name)
  (define m (db-meta-of name))
  (if m (map first (db-meta-manifest m)) '()))

;; Names of dbs whose manifest lists `name` as an input (its dependents).
(define (db-referenced-by name)
  (for/list ([n (in-list (all-db-names))]
             #:when (member name (db-inputs n)))
    n))

;; Transitive dependents of `name` (everything that would break if it vanished).
(define (db-dependents* name)
  (let loop ([frontier (list name)] [seen (set)])
    (cond
      [(null? frontier) (set-remove seen name)]
      [else
       (define n (first frontier))
       (define deps (db-referenced-by n))
       (loop (append (rest frontier) (filter (lambda (d) (not (set-member? seen d))) deps))
             (for/fold ([s seen]) ([d (in-list deps)]) (set-add s d)))])))

;; Is `name` stale?  -> #f, or a list of reasons (missing/changed inputs).
(define (db-staleness name)
  (define m (db-meta-of name))
  (cond
    [(not m) '()]
    [else
     (for/fold ([reasons '()]) ([link (in-list (db-meta-manifest m))])
       (match-define (list iname istamp) link)
       (define im (db-meta-of iname))
       (cond
         [(not (db-exists? iname)) (cons (format "input ~a missing" iname) reasons)]
         [(and im istamp (not (equal? (db-meta-stamp im) istamp)))
          (cons (format "input ~a changed" iname) reasons)]
         [else reasons]))]))

;; Count relation directories (a cheap size proxy).
(define (db-rel-count name)
  (define d (db-dir name))
  (if (directory-exists? d)
      (for/sum ([e (in-list (directory-list d))]
                #:when (regexp-match? #px"^(table|struct|lat)\\." (path->string e)))
        1)
      0))

(define (dir-bytes d)
  (if (directory-exists? d)
      (for/sum ([f (in-directory d)] #:when (file-exists? f)) (file-size f))
      0))

(define (human-bytes n)
  (cond [(< n 1024) (format "~aB" n)]
        [(< n (* 1024 1024)) (format "~aK" (quotient n 1024))]
        [(< n (* 1024 1024 1024)) (format "~aM" (quotient n (* 1024 1024)))]
        [else (format "~aG" (quotient n (* 1024 1024 1024)))]))

;; ---------------------------------------------------------------------------
;; Cycle detection (enforced logically; save also refuses to link a cycle)
;; ---------------------------------------------------------------------------

(define (dag-has-cycle?)
  (define names (all-db-names))
  (define color (make-hash))          ; name -> 'grey | 'black
  (let/ec return
    (define (visit n)
      (case (hash-ref color n #f)
        [(grey) (return #t)]
        [(black) (void)]
        [else
         (hash-set! color n 'grey)
         (for ([i (in-list (db-inputs n))] #:when (db-exists? i)) (visit i))
         (hash-set! color n 'black)]))
    (for ([n (in-list names)]) (visit n))
    #f))

;; ---------------------------------------------------------------------------
;; Load: the manifest-driven open+import sequence for `-d NAME`
;; ---------------------------------------------------------------------------

;; Returns the ordered action specs the driver issues to reconstitute `name`.
;; A plain db (or one with an empty manifest) is a single (open name).  A
;; compressed layer opens its EDB root, imports any further inputs, then imports
;; its own IDB relations -- content-dedup merges the two id lineages (§4.3).  At
;; P0 per is always 1.0, so this yields the full database with no replay.
(define (db-load-actions name)
  (define m (db-meta-of name))
  (define manifest (if m (db-meta-manifest m) '()))
  ;; a db's edits (add-tuple ...) apply right after it is opened/imported, so
  ;; replay of everything above sees the edited input-leaf relation (§12).
  (define (edits-of n) (read-edits (db-dir n)))
  (cond
    [(null? manifest) (append (list `(open ,name)) (edits-of name))]
    [else
     (define inputs (map first manifest))
     (append
      (list `(open ,(first inputs))) (edits-of (first inputs))
      (append-map (lambda (i) (cons `(import ,i) (edits-of i))) (rest inputs))
      (list `(import ,name)) (edits-of name))]))

;; Recursive load plan for `name` (docs/db-compression.md §10, P2): the whole
;; input DAG materialised bottom-up.  Each element is either an action spec
;; (open/import/add-tuple) streamed as a plugin, or a replay step telling the
;; driver to recompile + run a layer's stored program:
;;
;;   (replay L (own-step ...))   -- prog.sexpr layer.  The layer's OWN steps
;;     (its sample import + its edits) ride inside the replay step so the
;;     executor can open the layer's version boundary FIRST and apply them
;;     into the layer's own versions (0.E0a) -- pre-E0 they streamed before
;;     the boundary and landed in the predecessor versions.
;;   (replay-recipe L)           -- session-recipe layer (0.E2): the executor
;;     replays the layer's stored recipe with the live session machinery.
;;     Its stored relation dirs are a witness (signature verification), not
;;     a seed: importing the final materialisation first would pollute the
;;     rebuilt predecessor versions, so a recipe layer always replays
;;     unseeded from its base.  Its edits stream AFTER the recipe (they are
;;     later mutations of the saved session).
;;
;; The base (first input) is opened and recursively materialised; further
;; inputs are merged in; `seen` de-dups diamonds.
;;
;; #:seed? #f (a FULL-replay verify, `slog db verify NAME --replay`) skips
;; importing the kept sample of any layer whose program will be replayed, so
;; the replay must re-derive the whole IDB from the EDB.  A seeded load is
;; monotone -- a kept tuple the current compiler no longer derives silently
;; survives (§11 blind spot); an unseeded replay surfaces exactly those
;; removals.  Layers with no stored program (pure merges) still import.
;;
;; The unseeded-downstream rule (0.E2, pinned 2026-07-11): once a NEGATIVE
;; edit step (del-tuple / del-batch / a batch with deletions) has streamed
;; anywhere below, every LATER prog-layer's kept sample was computed for a
;; different EDB -- a seeded (monotone) replay would silently resurrect
;; retracted derivations (§8B.6 drift source (b)) -- so those layers replay
;; UNSEEDED.  Only the mutable `edits` appendix can carry a del under an
;; existing dependent (recipes are immutable parts of their layer, so a
;; recipe's own deletions are already reflected in every later save);
;; positive-only chains keep full seeding.
(define (step-negative? st)
  (match st
    [`(del-tuple ,_ ...) #t]
    [`(del-batch ,_ ...) #t]
    [`(batch ,_ ,_ ,_ ,(? pair?)) #t]
    [_ #f]))

(define (db-load-steps name [seen (set)] #:seed? [seed? #t])
  (define neg-seen (box #f))   ; a negative edit streamed somewhere below
  (let walk ([name name] [seen seen])
    (cond
      [(or (not name) (set-member? seen name)) '()]
      [else
       (define seen+ (set-add seen name))
       (define m (db-meta-of name))
       (define manifest (if m (db-meta-manifest m) '()))
       (define e (read-edits (db-dir name)))
       (define (note-edits!) (when (ormap step-negative? e) (set-box! neg-seen #t)))
       (cond
         [(db-has-recipe? (db-dir name))
          ;; a session layer: materialise its base chain, then replay the
          ;; recipe (which re-runs segments and re-applies batches/imports/
          ;; links itself -- link-edge manifest entries are provenance, not
          ;; load imports), then its edits appendix.  The base is named by
          ;; the recipe's (open ...) step -- NOT the manifest's first entry,
          ;; which for a base-less session with a hot-link would be the
          ;; link edge.
          (define base
            (match (read-recipe (db-dir name))
              [`(slog-recipe ,steps ...)
               (for/first ([st (in-list steps)]
                           #:when (match st [`(open ,_) #t] [_ #f]))
                 (second st))]
              [_ #f]))
          (begin0
            (append (if base (walk base seen+) '())
                    (list `(replay-recipe ,name))
                    e)
            (note-edits!))]
         [(null? manifest)
          (begin0 (append (list `(open ,name)) e) (note-edits!))]
         [else
          (define inputs (map first manifest))
          (define base-steps (walk (first inputs) seen+))       ; base, recursively
          (define rest-steps
            (append-map (lambda (i) (append (walk i seen+)
                                            (list `(import-layer ,i))))
                        (rest inputs)))
          (define replay? (prog-sexpr-exists? (db-dir name)))
          ;; unseeded when asked (#:seed? #f) or forced by a negative edit
          ;; below (noted by the recursive walks above) -- INCLUDING the
          ;; layer's own edits: they apply at its boundary before its
          ;; replay, so its kept sample (computed pre-edit) would resurrect
          ;; the retracted tuple's own derivations
          (define own-neg? (ormap step-negative? e))
          (define import-self
            (if (and replay? (or (not seed?) (unbox neg-seen) own-neg?))
                '()
                (list `(import-layer ,name))))
          (begin0
            (append base-steps rest-steps
                    (if replay?
                        (list `(replay ,name ,(append import-self e)))
                        (append import-self e)))
            (note-edits!))])])))

;; A short digest of `name`'s effective load recipe -- the full load plan with
;; its inline edit ops.  signature.edited (dbmeta.rkt) is keyed by this: an
;; edit added anywhere in the chain changes the digest, invalidating the
;; edited-chain drift baseline until the next load re-baselines it.  Always
;; digests the seeded plan so the key is independent of the verify mode.
;; Same digest core as recipe-digest (dbmeta.rkt steps-digest, E1a); grouped
;; replay steps are FLATTENED back to the legacy stream order (own steps,
;; then a bare (replay L)) so digests -- and hence existing signature.edited
;; baselines -- are byte-identical to the pre-0.E plans, and a recipe layer
;; contributes its recipe's digest (one mechanism: an edit OR a differing
;; recipe anywhere in a chain invalidates downstream baselines).
(define (db-chain-edits-digest name)
  (steps-digest
   (append-map
    (lambda (st)
      (match st
        [`(replay ,l ,own) (append own (list `(replay ,l)))]
        [`(replay-recipe ,l)
         (define r (read-recipe (db-dir l)))
         (list `(replay-recipe ,l ,(if r (recipe-digest r) 'none)))]
        [_ (list st)]))
    (db-load-steps name))))

;; Walk the load DAG; return (list db stored-version) for the first database
;; whose recorded value-encoding-version differs from what this build reads,
;; else #f (docs/db-compression.md §P2.2).  A derived layer could drop-and-
;; replay under the new encoding, but a root's bins would need real migration,
;; so the driver refuses rather than misread words at the wrong offsets.
(define (db-encoding-mismatch name [seen (set)])
  (cond
    [(or (not name) (set-member? seen name)) #f]
    [else
     (define m (db-meta-of name))
     (cond
       [(and m (not (equal? (db-meta-value-encoding-version m) slog-value-encoding-version)))
        (list name (db-meta-value-encoding-version m))]
       [else (for/or ([i (in-list (db-inputs name))])
               (db-encoding-mismatch i (set-add seen name)))])]))

;; Does `name` or any db in its transitive input DAG carry edits?  A verify
;; against the stored signature is skipped in that case -- an edit intentionally
;; changes the content, so the replay legitimately no longer matches (§12).
(define (db-chain-has-edits? name [seen (set)])
  (cond
    [(or (not name) (set-member? seen name)) #f]
    [(db-has-edits? (db-dir name)) #t]
    [else
     (for/or ([i (in-list (db-inputs name))])
       (db-chain-has-edits? i (set-add seen name)))]))

;; ---------------------------------------------------------------------------
;; `slog db` subcommands
;; ---------------------------------------------------------------------------

(define (die fmt . args)
  (fprintf (current-error-port) "Error: ~a\n" (apply format fmt args))
  (exit 2))

(define (cmd-ls)
  (define names (all-db-names))
  (cond
    [(null? names) (printf "No databases under ~a/\n" DATA)]
    [else
     (printf "~a  ~a  ~a  ~a  ~a\n"
             (~a "NAME" #:min-width 24) (~a "KIND" #:min-width 10)
             (~a "PER" #:min-width 5) (~a "RELS" #:min-width 5) "SIZE")
     (for ([n (in-list names)])
       (define m (db-meta-of n))
       (define stale (db-staleness n))
       (printf "~a  ~a  ~a  ~a  ~a~a\n"
               (~a n #:min-width 24)
               (~a (if m (db-meta-kind m) "plain") #:min-width 10)
               (~a (if m (~r (* 100 (db-meta-per m)) #:precision 0) "-") #:min-width 5)
               (~a (db-rel-count n) #:min-width 5)
               (~a (human-bytes (dir-bytes (db-dir n))) #:min-width 6)
               (if (null? stale) "" (format "  STALE (~a)" (string-join stale "; ")))))]))

(define (cmd-tree names0)
  ;; Roots to print: named args, or every db that nothing else references.
  (define roots
    (cond [(pair? names0) names0]
          [else (filter (lambda (n) (null? (db-referenced-by n))) (all-db-names))]))
  (define (walk n depth seen)
    (define m (db-meta-of n))
    (printf "~a~a~a\n"
            (make-string (* 2 depth) #\space)
            (if (> depth 0) "└─ " "")
            (format "~a~a" n (if m (format " [~a]" (db-meta-kind m)) " [plain]")))
    (cond
      [(set-member? seen n) (printf "~a(cycle)\n" (make-string (* 2 (add1 depth)) #\space))]
      [else
       (for ([i (in-list (db-inputs n))])
         (walk i (add1 depth) (set-add seen n)))]))
  (for ([r (in-list roots)])
    (unless (db-exists? r) (die "no such database: ~a" r))
    (walk r 0 (set))))

(define (rm-one! name)
  (define d (db-dir name))
  (when (directory-exists? d) (delete-directory/files d))
  (printf "removed ~a\n" name))

(define (cmd-rm args)
  (define cascade? (and (member "--cascade" args) #t))
  (define names (filter (lambda (a) (not (string-prefix? a "--"))) args))
  (when (null? names) (die "usage: slog db rm NAME... [--cascade]"))
  (for ([name (in-list names)])
    (unless (db-exists? name) (die "no such database: ~a" name))
    (define deps (set->list (db-dependents* name)))
    (cond
      [(null? deps) (rm-one! name)]
      [cascade?
       (for ([d (in-list deps)]) (rm-one! d))
       (rm-one! name)]
      [else
       (die "~a is an input to: ~a\n  (use --cascade to remove it and all dependents)"
            name (string-join deps ", "))])))

(define (cmd-gc)
  ;; Reclaim EDB roots (data/<x>.edb) that no layer's manifest references any
  ;; more -- the orphan left behind when a compressed layer is removed.
  (define orphans
    (for/list ([n (in-list (all-db-names))]
               #:when (and (string-suffix? n ".edb")
                           (null? (db-referenced-by n))))
      n))
  (cond
    [(null? orphans) (printf "nothing to collect\n")]
    [else (for ([o (in-list orphans)]) (rm-one! o))]))

(define (cmd-clear)
  (cond
    [(not (directory-exists? DATA)) (printf "no data/ directory\n")]
    [else
     (for ([e (in-list (directory-list DATA))]
           #:when (directory-exists? (build-path DATA e)))
       (delete-directory/files (build-path DATA e)))
     (printf "cleared ~a/\n" DATA)]))

;; `slog db verify [NAME...] [--replay]`.  The static pass checks the DAG
;; (META readable, inputs present, staleness, acyclicity).  --replay
;; additionally loads each named compressed db WITHOUT seeding its kept sample
;; (db-load-steps #:seed? #f) and replays from the EDB, comparing the result
;; against the stored signature -- the strong check that also surfaces
;; REMOVALS a seeded load masks (§11 blind spot).  Driven by the
;; replay-verify callback compiler/run.rkt supplies (the driver lives in runslog.rkt,
;; which requires this module).
(define (cmd-verify names0 #:replay-verify [replay-verify #f])
  (define replay? (and (member "--replay" names0) #t))
  (define names1 (filter (lambda (a) (not (string-prefix? a "--"))) names0))
  (define names (if (pair? names1) names1 (all-db-names)))
  (define ok (box #t))
  (when (dag-has-cycle?)
    (set-box! ok #f)
    (printf "FAIL: data/ contains a dependency cycle\n"))
  (for ([n (in-list names)])
    (unless (db-exists? n) (die "no such database: ~a" n))
    (define problems '())
    (define (add! p) (set! problems (cons p problems)))
    (define m (db-meta-of n))
    (cond
      [(not (db-managed? n)) (add! "no META (plain database)")]
      [(not m) (add! "META present but unreadable/foreign")]
      [else
       ;; every input must exist and be managed
       (for ([link (in-list (db-meta-manifest m))])
         (match-define (list iname _) link)
         (unless (db-exists? iname) (add! (format "missing input ~a" iname))))
       (for ([r (in-list (db-staleness n))]) (add! (format "stale: ~a" r)))])
    (cond
      [(null? problems) (printf "ok   ~a\n" n)]
      [else (set-box! ok #f)
            (printf "FAIL ~a\n" n)
            (for ([p (in-list (reverse problems))]) (printf "       - ~a\n" p))]))
  (when replay?
    (unless replay-verify
      (die "--replay verify needs the run driver; invoke as `slog db verify ... --replay`"))
    (for ([n (in-list names)])
      (cond
        ;; only compressed layers have a signature to replay against
        [(not (read-signature-file (db-dir n)))
         (printf "skip ~a (--replay: no stored signature)\n" n)]
        [else
         (with-handlers ([exn:fail?
                          (lambda (e)
                            (set-box! ok #f)
                            (printf "FAIL ~a (full replay): ~a\n" n (exn-message e)))])
           (replay-verify n)
           (printf "ok   ~a (full replay verify)\n" n))])))
  (unless (unbox ok) (exit 2)))

;; slog db edit NAME <op> ...  -- record a forward-incremental edit on an
;; existing layer (§12).  Applied at load; propagates by re-replay.  The op
;; vocabulary IS the recipe step grammar's mutation subset (dbmeta.rkt
;; edit-step?, E1a): edits are recipe fragments attached to an ancestor,
;; stored as the action specs themselves so the load-step loop streams
;; them like any step -- one grammar, one applier, one digest.
(define (cmd-edit args)
  (match args
    [(list-rest name "add-tuple" rel vals)
     (unless (db-exists? name) (die "no such database: ~a" name))
     (when (null? vals) (die "usage: slog db edit NAME add-tuple REL v..."))
     (define parsed (for/list ([v (in-list vals)]) (or (string->number v) (string->symbol v))))
     (append-edit! (db-dir name) `(add-tuple ,(string->symbol rel) ,@parsed))
     (printf "recorded edit on ~a: (add-tuple ~a ~a); reload a dependent to propagate\n"
             name rel (string-join vals " "))]
    ;; del-tuple is recordable since 0.E2's unseeded-downstream rule landed:
    ;; db-load-steps drops the kept-sample import of every prog-layer that
    ;; streams AFTER a negative edit, so their replays re-derive from the
    ;; edited EDB and the retraction propagates instead of being masked by
    ;; a monotone seed (the §11.1 blind spot, closed).  The digest change
    ;; also re-baselines signature.edited on the next load, as any edit does.
    [(list-rest name "del-tuple" rel vals)
     (unless (db-exists? name) (die "no such database: ~a" name))
     (when (null? vals) (die "usage: slog db edit NAME del-tuple REL v..."))
     (define parsed (for/list ([v (in-list vals)]) (or (string->number v) (string->symbol v))))
     (append-edit! (db-dir name) `(del-tuple ,(string->symbol rel) ,@parsed))
     (printf "recorded edit on ~a: (del-tuple ~a ~a); dependent layers replay UNSEEDED below this edit; reload a dependent to propagate.\nNote: retraction sticks for DATA-fed inputs; a tuple that is a stored program's own ground fact re-derives on replay (program-supported -- docs/incremental.md §8B.5)\n"
             name rel (string-join vals " "))]
    [(list name "rename-rel" from to)
     (unless (db-exists? name) (die "no such database: ~a" name))
     (append-edit! (db-dir name) `(rename-rel ,(string->symbol from) ,(string->symbol to)))
     (printf "recorded edit on ~a: (rename-rel ~a ~a); reload a dependent to propagate\n"
             name from to)]
    [(list name "drop-rel" rel)
     (unless (db-exists? name) (die "no such database: ~a" name))
     (append-edit! (db-dir name) `(drop-rel ,(string->symbol rel)))
     (printf "recorded edit on ~a: (drop-rel ~a); reload a dependent to propagate\n"
             name rel)]
    [_ (die "usage: slog db edit NAME <add-tuple REL v...|rename-rel R S|drop-rel R>")]))

;; slog db freeze NAME [--as NEW] [--force] (docs/incremental.md §0.10, W7):
;; load/replay NAME's whole chain, write the materialisation as a standalone
;; FLAT root -- no manifest, no recipe, no stored program -- the sanctioned
;; way to cut history.  The frozen copy can no longer be replayed, edited
;; through, or hot-linked *as a chain*.  Without --as the freeze is IN PLACE
;; (via a temp dir + swap): refused while dependents reference NAME unless
;; --force (they become stale -- the freeze changes NAME's stamp).  The
;; heavy lifting (`freeze`: load the chain, write data/<target>) is the run
;; driver's, injected by compiler/run.rkt exactly like verify's --replay.
(define (cmd-freeze args #:freeze freeze)
  (unless freeze
    (die "freeze needs the run driver; invoke as `slog db freeze NAME [--as NEW]`"))
  (define force? (and (member "--force" args) #t))
  (define-values (names as-name)
    (let loop ([as args] [names '()] [as-name #f])
      (match as
        ['() (values (reverse names) as-name)]
        [(list-rest "--as" new rest) (loop rest names new)]
        [(cons "--force" rest) (loop rest names as-name)]
        [(cons a rest) (loop rest (cons a names) as-name)])))
  (match names
    [(list name)
     (unless (db-exists? name) (die "no such database: ~a" name))
     (define in-place? (or (not as-name) (equal? as-name name)))
     (when (and in-place? (not (db-managed? name)))
       (die "~a is already a standalone database (no META/chain to cut); use --as NEW to copy it" name))
     (when in-place?
       (define deps (db-referenced-by name))
       (unless (or force? (null? deps))
         (die "~a is an input to: ~a\n  (freezing changes its stamp; use --force to proceed -- dependents become stale)"
              name (string-join deps ", "))))
     (define target (if in-place? (string-append name ".freeze.tmp") as-name))
     (when (and (not in-place?) (db-exists? target) (not force?))
       (die "database ~a already exists (use --force to overwrite)" target))
     (when (db-exists? target) (rm-one! target))
     (freeze name target)
     (unless (db-exists? target)
       (die "freeze failed: data/~a was not written" target))
     ;; strip chain artifacts the daemon's write never emits but a copied
     ;; in-place dir would retain, then stamp the flat META
     (for ([f (in-list '("recipe" "prog.sexpr" "signature" "signature.edited" "edits"))])
       (define p (build-path (db-dir target) f))
       (when (file-exists? p) (delete-file p)))
     (for ([e (in-list (directory-list (db-dir target)))]
           #:when (regexp-match? #px"^delta\\.[0-9]+$" (path->string e)))
       (delete-directory/files (build-path (db-dir target) e)))
     (define m0 (make-db-meta #:kind 'flat #:pure-edb? #f #:manifest '()
                              #:per 1.0 #:compiler-stamp (current-compiler-stamp)))
     (write-db-meta (hash-set m0 'stamp (compute-db-stamp m0 #:db-dir (db-dir target)))
                    (db-dir target))
     (cond
       [in-place?
        (delete-directory/files (db-dir name))
        (rename-file-or-directory (db-dir target) (db-dir name))
        (printf "froze ~a in place: now a standalone flat root (history cut)\n" name)]
       [else
        (printf "froze ~a as ~a: a standalone flat root (history cut)\n" name target)])]
    [_ (die "usage: slog db freeze NAME [--as NEW] [--force]")]))

(define (slog-db-command args #:replay-verify [replay-verify #f] #:freeze [freeze #f])
  (match args
    [(list) (printf "usage: slog db <ls|tree|rm|gc|clear|verify|edit|freeze> [args]\n")]
    [(cons "ls" _) (cmd-ls)]
    [(cons "tree" rest) (cmd-tree rest)]
    [(cons "rm" rest) (cmd-rm rest)]
    [(cons "gc" _) (cmd-gc)]
    [(cons "clear" _) (cmd-clear)]
    [(cons "verify" rest) (cmd-verify rest #:replay-verify replay-verify)]
    [(cons "edit" rest) (cmd-edit rest)]
    [(cons "freeze" rest) (cmd-freeze rest #:freeze freeze)]
    [(cons other _) (die "unknown db subcommand: ~a" other)]))
