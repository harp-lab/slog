#lang racket

;; The driver: compile a .slog path and feed the resulting plugins to the
;; slogd daemon.
;;
;; The daemon's whole protocol is one plugin .so path per line (see
;; daemon/slogd.cpp), so driving a run is streaming paths: an `open` action
;; when starting from a stored database, then each stratum plugin in
;; topological order of the SCC DAG (each pushes its stratum onto the
;; daemon's resident pipeline and runs it to fixpoint, the daemon reloading
;; the database between strata), then actions for whatever the client wants
;; back -- writing the database or CSVs, relation-size statistics, etc.
;; Compilation runs ahead in a future while the daemon executes.

(provide slog-run-file
         slog-verify-replay
         db-manifest-from-name
         db-manifest-from-schema-lines)

(require "tools.rkt")
(require "compile.rkt")
(require "actions.rkt")
(require "dbmeta.rkt")
(require "dbtool.rkt")
(require "parser.rkt")   ; current-source-capture (P1.1)

;; When set (during a replay layer), a memory pause checkpoints the partial db
;; to this name instead of a bare abort (docs/db-compression.md §P2.3).
(define current-checkpoint (make-parameter #f))

;; Simple auto-per (docs/db-compression.md §13.1, deliberately coarse): pick a
;; retention `per` from how expensive the database was to compute from origin
;; (total replay fixpoint wall-time).  A cheap db compresses hard -- keep a
;; fraction, replay is cheap; an expensive one is kept whole so its load is an
;; immediate fixpoint.  The smooth size-aware clamp of §13.1 is left for later.
(define auto-per-expensive-ms 500.0)
(define auto-per-min 0.5)
(define (auto-per wall-ms)
  (if (>= wall-ms auto-per-expensive-ms) 1.0 auto-per-min))

;; Seed for the IDB sampler's content-hash keep (P1.2); recorded in the layer
;; META so a kept-set is reproducible.  Fixed for now (any subset is a valid
;; seed -- the sample is a witness, not needed for reconstruction, §2a).
(define compressed-rng-seed 0)

;; Reconstruct a canonical lattice valuespec from its on-disk spec token
;; (the inverse of emit-cpp.rkt's lat-spec-token): "min-int-floor-0" ->
;; (lattice min int (floor 0)), "count" -> (lattice count), "flat-value" ->
;; (lattice flat value), "set-int" -> (lattice set int), "map-str-min-int"
;; -> (lattice map str (min int)).  Recursive descent over the dash-split
;; words, mirroring the daemon's parseLatSpecWords (daemon/arena.h) so the
;; two re-parsers stay in lockstep; composite (map) tokens nest, so the
;; old arity-of-split match would misparse them.
(define (lat-spec-from-token tok)
  (define (parse ws)
    (match ws
      [`("count" ,rest ...) (cons `(count) rest)]
      [`("flat" ,t ,rest ...) (cons `(flat ,(string->symbol t)) rest)]
      [`("set" ,t ,rest ...) (cons `(set ,(string->symbol t)) rest)]
      [`("map" ,k ,rest ...)
       (match-define (cons inner rest+) (parse rest))
       (cons `(map ,(string->symbol k) ,inner) rest+)]
      [`(,(and kind (or "min" "max")) ,base
         ,(and param (or "floor" "ceiling")) ,v ,rest ...)
       (cons `(,(string->symbol kind) ,(string->symbol base)
               (,(string->symbol param) ,(string->number v)))
             rest)]
      [`(,(and kind (or "min" "max")) ,base ,rest ...)
       (cons `(,(string->symbol kind) ,(string->symbol base)) rest)]
      [_ (error 'db-manifest "unrecognized lattice spec token on disk: ~a" tok)]))
  (match-define (cons spec rest) (parse (string-split tok "-")))
  (unless (null? rest)
    (error 'db-manifest "unrecognized lattice spec token on disk: ~a" tok))
  `(lattice ,@spec))

;; Scan an input database directory into a manifest of its relations.
;;
;; Parses each entry's BASENAME with anchored patterns, mirroring the
;; daemon's parseRelationDirName (database.h): matching anywhere in the
;; absolute path let an ancestor directory (or the db name itself) shaped
;; like table.X.arity.N shadow real relations, `\w+` names silently dropped
;; relations whose (legal) names carry apostrophes -- and a dropped
;; manifest entry destroys that relation's facts on the first reload
;; (emit-cpp keeps an index alive for exactly the on-disk relations the
;; program doesn't declare).  The greedy (.+) with an anchored tail splits
;; on the LAST .arity., like the daemon.  A dir that CLAIMS a relation
;; prefix but fails validation errors loudly (daemon parity), as does a
;; duplicate name or an arity the daemon cannot load.
(define (db-manifest-from-name db-name)
  (define (arity-ok? n) (and n (<= 1 n 32)))
  (define (add man name entry fname)
    (define sym (string->symbol name))
    (when (hash-has-key? man sym)
      (error 'db-manifest "two directories claim relation ~a (~a)" name fname))
    (hash-set man sym entry))
  (if db-name
      (let ([db-path (string-append "data/" db-name "/")])
        (foldl (lambda (path man)
                 (define fname (path->string path))
                 (match (regexp-match #px"^table\\.(.+)\\.arity\\.([0-9]+)$" fname)
                   [`(,_ ,name ,arity)
                    #:when (arity-ok? (string->number arity))
                    (add man name
                         `(rel ,(string->symbol name) ,(string->number arity))
                         fname)]
                   [_
                    (match (regexp-match #px"^struct\\.(.+)\\.arity\\.([0-9]+)\\.id\\.([0-9]+)$" fname)
                      [`(,_ ,name ,arity ,_)
                       #:when (arity-ok? (string->number arity))
                       (add man name
                            `(struct ,(string->symbol name) ,(string->number arity))
                            fname)]
                      [_
                       (match (regexp-match #px"^lat\\.(.+)\\.arity\\.([0-9]+)\\.spec\\.([-.'\\w]+)$" fname)
                         [`(,_ ,name ,arity ,tok)
                          #:when (arity-ok? (string->number arity))
                          (add man name
                               `(lat ,(string->symbol name) ,(string->number arity)
                                     ,(lat-spec-from-token tok))
                               fname)]
                         [_
                          (when (regexp-match #px"^(table|struct|lat)\\." fname)
                            (error 'db-manifest
                                   "malformed relation directory name: ~a" fname))
                          man])])]))
               (hash)
               (directory-list db-path)))
      (hash)))

;; Parse the lines a `(schema)` action emits (compiler/actions.rkt) into the
;; SAME manifest hash db-manifest-from-name produces -- schema truth from the
;; LIVE daemon (imports and prior programs included), so a front end can
;; compile against the session instead of a directory scan
;; (docs/finish-collections.md §B; CLI orchestration comes later with merge
;; P2's offline verb).  Non-schema lines (and the (schema-end) sentinel) are
;; skipped, so the caller can hand over a whole session transcript.  A
;; struct's id is session-local and manifests never carry it; the arity is
;; the STORED arity (fields + id), exactly like the directory name's.
(define (db-manifest-from-schema-lines lines)
  (for/fold ([man (hash)]) ([l (in-list lines)])
    (match (regexp-match #px"^\\(schema-rel (table|struct|lat) ([^ ]+) ([0-9]+)(?: ([^ )]+))?\\)\\s*$" l)
      [`(,_ "table" ,name ,arity ,_)
       (define sym (string->symbol name))
       (hash-set man sym `(rel ,sym ,(string->number arity)))]
      [`(,_ "struct" ,name ,arity ,_)
       (define sym (string->symbol name))
       (hash-set man sym `(struct ,sym ,(string->number arity)))]
      [`(,_ "lat" ,name ,arity ,tok)
       (define sym (string->symbol name))
       (hash-set man sym `(lat ,sym ,(string->number arity)
                               ,(lat-spec-from-token tok)))]
      [#f man])))

;; Union the on-disk relation manifests across a database's whole input DAG
;; (docs/db-compression.md P1.4): a program loaded atop a compressed database
;; must see every relation the reconstituted db holds -- its own IDB layer AND
;; the EDB root / inputs it links -- so emit-cpp keeps them all alive across
;; reloads.  Falls back to the single-dir manifest for a plain (unlinked) db.
(define (db-full-manifest name [seen (set)])
  (cond
    [(or (not name) (set-member? seen name)) (hash)]
    [else
     (define dir (string-append "data/" name))
     (define inputs
       (if (db-meta-file-exists? dir)
           (map first (db-meta-manifest (read-db-meta dir)))
           '()))
     (for/fold ([m (db-manifest-from-name name)]) ([i (in-list inputs)])
       (for/fold ([m m]) ([(k v) (in-hash (db-full-manifest i (set-add seen name)))])
         (hash-set m k v)))]))

;; If `name` is a compressed database that stored its deriving program, return
;; (cons entry sources-hash) so a load recompiles+replays it (P1.4); else #f.
(define (compressed-replay-plan name)
  (and name (read-prog-sexpr (string-append "data/" name))))

;; Compile slog-path and run every stratum plugin through a fresh slogd,
;; optionally against input database db-name, optionally writing the final
;; database (binary) to out-db and/or (CSV) to debug-out-path, optionally
;; reporting every relation's tuple count.
(define (slog-run-file slog-path
                       [db-name #f]
                       [out-db #f]
                       [debug-out-path #f]
                       [report-sizes? #f]
                       #:compressed [compressed #f]  ; --out-db-compressed NAME
                       #:per [per 1.0]
                       #:flatten? [flatten? #f]
                       #:strict? [strict? #f]
                       #:bias [bias #f]
                       #:reoptimise? [reoptimise? #f]
                       #:no-seed? [no-seed? #f])     ; full-replay verify (§11)
  ;; Working directories used by the compiler and daemon (relative to cwd).
  (make-directory* "build")
  (make-directory* "out")
  ;; The query compiles against the FULL DAG manifest so it sees an opened
  ;; compressed db's EDB root as well as its IDB layer (P1.4); a plain db's full
  ;; manifest is just its own directory.
  (define dbmanifest (if db-name (db-full-manifest db-name) (hash)))
  ;; A compressed save while -d loaded an input chains atop it: the loaded db
  ;; becomes this layer's base input (materialised recursively on load), rather
  ;; than snapshotting a fresh EDB root of it (docs/db-compression.md §7.1).
  (define chained-input (and (or compressed) db-name))
  ;; A LINKED compressed save (docs/db-compression.md P0.5/P0.6) splits the
  ;; iteration-0 facts into their own first stratum so the EDB root can be
  ;; snapshotted before any rule derives.  --flatten writes a single
  ;; self-contained root instead (today's --out-db + META), needing no split.
  (define linked-compressed? (and compressed (not flatten?)))
  (define tiered? (not (member (or (getenv "SLOG_OPT") "tiered") '("0" "2"))))
  (ensure-slogd-exists)
  (define-values (sp out in err) (apply subprocess #f #f #f (slogd-argv "daemon/slogd")))
  (define (send-plugin path)
    (display (string-append path "\n"))
    (display (string-append path "\n") in)
    (flush-output in))
  ;; Drain the daemon's stderr continuously in the background, so a chatty
  ;; stderr can never fill its pipe and wedge the stdout handshake below.
  (define err-thread
    (thread (lambda ()
              (let loop ()
                (define s (read-line err))
                (unless (eof-object? s) (displayln s) (loop))))))
  ;; Action .so's for polling (docs/pausing.md §5), built lazily and memoized:
  ;; (continue) uses the default budget; (continue-boundary) drives to the next
  ;; clean iteration boundary (the only hot-swap-safe stop point).  A program
  ;; whose strata each fixpoint within one budget never pauses, so these stay
  ;; off the critical path entirely.
  (define continue-so (delay (action-so `(continue))))
  (define continue-boundary-so (delay (action-so `(continue-boundary))))
  ;; Error-fact watch (docs/type-errors.md): the default run policy is to drive
  ;; every stratum to fixpoint (hard-stopping only on the memory cap, below), but
  ;; to WARN on stdout as runtime-error facts surface.  We dump the reserved
  ;; `error` relation at each stratum fixpoint and warn on any fact not seen
  ;; before -- `error` is cumulative and reloaded across strata, so dedup by
  ;; content avoids re-warning.  The dump action is a read-only, single-round
  ;; query (safe against even a suspended snapshot).
  (define dump-errors-so (delay (action-so `(dump-rel error))))
  (define warned-errors (make-hash))
  ;; Total fixpoint wall-time of this run, summed from the daemon's (fixpoint
  ;; ... ms) replies -- the recompute cost that feeds auto-per (§13.1).
  (define wall-ms-box (box 0.0))

  ;; Force-kill the daemon if compilation or the run errors out after launch,
  ;; rather than leaving it orphaned (blocked reading stdin or mid-fixpoint).
  (with-handlers
      ([exn:fail? (lambda (e)
                    (with-handlers ([exn:fail? void])
                      (unless (port-closed? in) (close-output-port in)))
                    (subprocess-kill sp #t)
                    (raise e))])

    ;; The load plan (dbtool.rkt db-load-steps) materialises the whole input DAG
    ;; bottom-up: open the base root, then for each layer import its sample,
    ;; apply its edits, and `(replay NAME)` its program (regenerating dropped
    ;; facts).  A plain db is a single (open); a compressed chain is the full
    ;; recursive sequence (docs/db-compression.md §10, P2 recursive DAG).
    ;; Refuse a database written under an incompatible value encoding (§P2.2):
    ;; its bin words would be read at the wrong offsets.
    (when db-name
      (define mm (db-encoding-mismatch db-name))
      (when mm
        (error (format (string-append
                        "database ~a was written with value-encoding v~a but this build reads v~a.\n"
                        "  Re-encode its root bins (or drop-and-replay derived layers) to migrate.")
                       (first mm) (second mm) slog-value-encoding-version))))
    (define load-steps
      (if db-name (db-load-steps db-name #:seed? (not no-seed?)) '()))
    ;; Send the leading open BEFORE compiling: loadDatabaseBIN is single-
    ;; threaded, so the load overlaps the Racket front end + codegen below
    ;; (docs/fast-compile.md).  The rest run after the drive loop is defined.
    (define leading-open?
      (and (pair? load-steps) (eq? (car (first load-steps)) 'open)))
    (when leading-open? (send-plugin (action-so (first load-steps))))
    (define rest-load-steps (if leading-open? (rest load-steps) load-steps))

    ;; Plan every stratum and kick off its build(s) on the parallel pool: tiered
    ;; mode runs each stratum at -O0 immediately and hot-swaps to a background
    ;; -O2 build when ready.  The daemon is already loading the input DB (if any)
    ;; while this runs.
    ;; For a linked compressed save, capture the program's source closure while
    ;; compiling so it can be stored as prog.sexpr and replayed on load (P1.1).
    (define src-capture (and linked-compressed? (make-hash)))
    (define-values (strata partition edb-boundary frozen-dirs)
      (parameterize ([current-source-capture src-capture])
        (compile-strata slog-path dbmanifest #:split-facts? linked-compressed?)))

    ;; Response-driven pipeline walk (docs/pausing.md §7, docs/fast-compile.md §5).
    ;; Each stratum plugin performs ONE bounded unit of work and answers with
    ;; exactly one line, so the loop is a tight synchronous handshake -- send,
    ;; then read: a (paused ...) is answered with a (continue) action, a
    ;; (fixpoint ...) advances to the next stratum, an (error ...) aborts.  A
    ;; single outstanding line means the daemon's stdout can never build up.
    ;;
    ;; Tiered hot swap: when a stratum was launched from its -O0 build and the
    ;; background -O2 build has since materialized (build/<hash>.so, written
    ;; atomically), reach a clean iteration boundary via (continue-boundary) and
    ;; then send the -O2 .so -- the daemon replaces the running stratum's tasks
    ;; in place (daemon.h beginStratum upgrade) and resumes with the optimized
    ;; code.  A stratum that fixpoints before -O2 is ready just runs at -O0 (and
    ;; the -O2 .so is cached for next time).
    ;;
    ;; Builds are already in flight on the pool; forcing stratum k's runnable
    ;; blocks only on k, while k+1.. build behind it.  A declaration-only program
    ;; has no strata.
    ;; Dump `error` and warn (stdout) on any fact not warned about yet.  One
    ;; send + read-until-sentinel; the dump action never calls continueRun, so it
    ;; emits no (paused|fixpoint) and its lines arrive before anything else.
    (define (check-errors! where)
      (send-plugin (force dump-errors-so))
      (let drain ()
        (define l (read-line out))
        (cond
          [(eof-object? l) (void)]
          [(regexp-match? #px"^\\(dumpdone " l) (void)]   ; sentinel: stop reading
          [else
           (define m (regexp-match #px"^\\(dumprow (.*)\\)\\s*$" l))
           (cond
             [m
              (define fact (cadr m))
              (unless (hash-has-key? warned-errors fact)
                (hash-set! warned-errors fact #t)
                (printf "WARNING: runtime error surfaced (~a): ~a\n" where fact)
                (flush-output))]
             [else (displayln l)])              ; defensive: unexpected line
           (drain)])))

    (define (drive-stratum! sb tag)  ; poll one stratum to fixpoint; #t unless eof
      (define o2 (sbuild-o2-path sb))
      (define upgradeable? (and tiered? (eq? tag 'o0) o2))
      (let poll ([swapped? #f])
        (define line (read-line out))
        (cond
          [(eof-object? line) #f]
          [(regexp-match #px"^\\(fixpoint [0-9]+ \"[^\"]*\" [0-9]+ ([0-9.]+)\\)" line)
           => (lambda (m)
                (set-box! wall-ms-box (+ (unbox wall-ms-box) (string->number (cadr m))))
                (displayln line)
                (check-errors! "at fixpoint")   ; per-stratum; daemon idle -> query safe
                #t)]
          [(regexp-match? #px"^\\(paused " line)
           (displayln line)
           (cond
             ;; A `memory` pause means the run reached the memory cap; in the
             ;; default continue-to-fixpoint mode we can only climb toward the
             ;; hard cgroup cap by continuing, so abort GRACEFULLY instead of
             ;; OOM-crashing (docs/pausing.md §5).
             [(regexp-match? #px"memory\\)\\s*$" line)
              (cond
                ;; During a replay, checkpoint the partial db before aborting so
                ;; the (possibly huge) progress is not lost (§P2.3); wait for the
                ;; serial write to finish before we tear the daemon down.
                [(current-checkpoint)
                 => (lambda (ckpt)
                      (send-plugin (action-so `(checkpoint ,ckpt)))
                      (let wait ()
                        (define l (read-line out))
                        (unless (or (eof-object? l) (regexp-match? #px"^\\(checkpointed " l))
                          (displayln l) (wait)))
                      (error (format (string-append
                                      "out of memory during replay: checkpointed the partial "
                                      "database to data/~a/.\n  Resume/inspect with `-d ~a`, or "
                                      "raise SLOG_MEM_MAX and reload.\n  ~a")
                                     ckpt ckpt line)))]
                [else
                 (error (format (string-append
                                 "out of memory: the run reached the memory cap "
                                 "(configure with SLOG_MEM_BYTES / SLOG_MEM_MAX).\n  ~a")
                                line))])]
             ;; -O2 is ready and we haven't swapped yet: get to a clean boundary,
             ;; then hand the daemon the -O2 .so to hot-swap in.
             [(and upgradeable? (not swapped?) (file-exists? o2))
              (cond
                [(regexp-match? #px"^\\(paused [^ ]+ \"[^\"]*\" [0-9]+ iter " line)
                 (send-plugin o2)
                 (eprintf "  [upgraded ~a to -O2]\n" (sbuild-hash sb))
                 (poll #t)]
                [else (send-plugin (force continue-boundary-so)) (poll #f)])]
             [else (send-plugin (force continue-so)) (poll swapped?)])]
          [(regexp-match? #px"^\\(error " line)
           (displayln line)
           (error (format "Daemon reported an error: ~a" line))]
          [else (displayln line) (poll swapped?)])))

    ;; Consume the daemon's (sig NAME count checksum) lines up to (sig-end),
    ;; returning a hash NAME -> (count . checksum) (P1.3/P1.5).
    (define (read-signature!)
      (let loop ([acc (hash)])
        (define line (read-line out))
        (cond
          [(eof-object? line) acc]
          [(regexp-match #px"^\\(sig ([^ ]+) ([0-9]+) ([0-9a-f]+)\\)$" line)
           => (lambda (m)
                (loop (hash-set acc (string->symbol (second m))
                                (cons (string->number (third m)) (fourth m)))))]
          [(regexp-match? #px"^\\(sig-end\\)$" line) acc]
          [else (displayln line) (loop acc)])))

    ;; Replay one compressed layer (docs/db-compression.md §10, P1.4): recompile
    ;; its stored program from prog.sexpr under the CURRENT compiler (the
    ;; original files may be gone/changed -- the source override supplies them)
    ;; and run its strata atop the already-materialised inputs + imported sample,
    ;; regenerating any facts dropped by sampling.  At per=100% the sample is the
    ;; whole IDB, so the fixpoint derives nothing new -- a self-verifying load.
    (define (replay-layer! lname)
      (define plan (read-prog-sexpr (string-append "data/" lname)))
      (when plan
        (match-define (cons r-entry r-sources) plan)
        (define-values (r-strata _rp _rb _rfrozen)
          (parameterize ([current-source-override r-sources])
            (compile-strata r-entry (db-full-manifest lname) #:split-facts? #f)))
        ;; a memory pause during this layer's replay checkpoints to
        ;; data/<lname>.checkpoint/ rather than aborting outright (§P2.3)
        (parameterize ([current-checkpoint (string-append lname ".checkpoint")])
          (for ([sb (in-list r-strata)])
            (match-define (cons so tag) ((sbuild-runnable sb)))
            (send-plugin so)
            (unless (drive-stratum! sb tag)
              (error "daemon output ended (EOF) mid-stratum during replay -- the daemon died or went silent"))))))

    ;; PHASE R -- materialise the loaded input DAG bottom-up: process the load
    ;; steps (imports + edits + per-layer replays).  Runs BEFORE the query
    ;; strata so the query sees the fully reconstituted database.
    (for ([step (in-list rest-load-steps)])
      (match step
        [`(replay ,lname) (replay-layer! lname)]
        [_ (send-plugin (action-so step))]))

    ;; Link the program's frozen ground facts (freeze.rkt): import each
    ;; content-addressed build/frozen/<hash> database before stratum 0 --
    ;; the deferred reload hands the first stratum their rows as its
    ;; iteration-zero delta, exactly as a -d input's facts arrive.
    (for ([dir (in-list frozen-dirs)])
      (send-plugin (action-so `(import-path ,dir))))

    ;; Verify the loaded db reproduced its stored content signature (P1.5): drift
    ;; is a compiler change, nondeterminism, or a compression bug.  An EDITED
    ;; chain verifies against its re-baselined signature.edited (keyed by a
    ;; digest of the chain's whole edit recipe): the first load after a new edit
    ;; establishes the baseline, later loads verify against it (§11/§12).
    ;;
    ;; Seeded-sample blind spot (§11): kept tuples are imported BEFORE replay,
    ;; so a change that would REMOVE a kept tuple is masked by the monotone
    ;; seed (at per=100% every removal is).  A no-seed? load (`slog db verify
    ;; NAME --replay`) skips the seeding so replay re-derives everything from
    ;; the EDB and removals surface in the comparison.
    (when db-name
      (let* ([ddir (string-append "data/" db-name)]
             [meta (and (db-meta-file-exists? ddir) (read-db-meta ddir))]
             ;; pinned oracle relations are part of the stored signature
             ;; (loaded verbatim; a missing pin must surface as drift)
             [idb (if meta (append (db-meta-idb-rels meta)
                                   (db-meta-pinned-rels meta))
                      '())]
             [label (if no-seed? "full replay" "replay")])
        (when (and meta (pair? idb))
          (cond
            [(not (db-chain-has-edits? db-name))
             (define stored-sig (read-signature-file ddir))
             (when stored-sig
               (send-plugin (action-so `(signature ,@idb)))
               (report-drift db-name stored-sig (read-signature!) meta strict?
                             #:label label))]
            [else
             (define digest (db-chain-edits-digest db-name))
             (define baseline (read-edited-signature-file ddir))
             (send-plugin (action-so `(signature ,@idb)))
             (define live (read-signature!))
             (cond
               [(and baseline (equal? (car baseline) digest))
                (report-drift db-name (cdr baseline) live meta strict?
                              #:label (string-append label " (edited-chain baseline)"))]
               [else
                (write-edited-signature-file ddir digest live)
                (eprintf "re-baselined ~a: stored the edited-chain signature (~a relations); drift detection resumes next load\n"
                         db-name (hash-count live))])]))))

    ;; Whether this save writes its own fresh EDB root (data/<name>.edb): yes for
    ;; a from-scratch program's iteration-0 facts (edb-boundary >= 1), or a
    ;; from-scratch program with no facts and no chained input; no when chaining
    ;; atop a -d input (that input IS the base -- linked in the manifest).
    (define root-snapshot?
      (and linked-compressed?
           (or (> edb-boundary 0) (not chained-input))))
    ;; With no facts stratum (edb-boundary 0) and no chained input, snapshot the
    ;; (possibly empty) root right after the open, before any stratum runs.
    (when (and linked-compressed? (= edb-boundary 0) (not chained-input))
      (send-plugin (action-so `(write-db ,(string-append compressed ".edb")))))
    ;; Capture the EDB struct heap at the boundary so the layer write dedups
    ;; against the root's structs (§4.2 `closure \ input_heap`).  Only when the
    ;; root is a fresh pure-EDB snapshot loaded VERBATIM on replay -- a chained
    ;; input is REPLAYED (fresh struct ids), so its heap can't be dedup'd
    ;; against by id; those layers stay closure-complete.
    (when (and linked-compressed? (= edb-boundary 0) (not chained-input))
      (send-plugin (action-so `(capture-edb-heap))))

    (for ([sb (in-list strata)] [i (in-naturals)])
      (match-define (cons so tag) ((sbuild-runnable sb)))  ; blocks until built
      (send-plugin so)
      ;; EOF here means the daemon died or went silent BEFORE this stratum's
      ;; fixpoint: erroring (rather than sailing on to the terminal actions)
      ;; is what keeps a half-run from masquerading as a successful one
      (unless (drive-stratum! sb tag)
        (error "daemon output ended (EOF) mid-stratum -- the daemon died or went silent"))
      ;; After the facts stratum fixpoints (its output is the pure iteration-0
      ;; EDB), snapshot the root before any derived tuple exists (P0.5).  A
      ;; silent write-db emits no line, so it cannot desync the next stratum's
      ;; handshake; the daemon processes it in stdin order before that stratum.
      (when (and linked-compressed? (> edb-boundary 0) (= (add1 i) edb-boundary))
        (send-plugin (action-so `(write-db ,(string-append compressed ".edb"))))
        ;; dedup only against a verbatim from-scratch root, not a replayed input
        (when (not chained-input)
          (send-plugin (action-so `(capture-edb-heap))))))

    ;; Capture the full-IDB content signature BEFORE the (possibly sampled)
    ;; layer write, so a load can verify the replay reproduced it (P1.3).
    ;; Pinned oracle relations (docs/smt.md §15) are signed too: they are
    ;; loaded verbatim, so a corrupted or missing pin surfaces as drift.
    (define signed-rels
      (append (db-partition-idb-rels partition)
              (db-partition-pinned-rels partition)))
    (define captured-sig #f)
    (when (and linked-compressed? (not (null? signed-rels)))
      (send-plugin (action-so `(signature ,@signed-rels)))
      (set! captured-sig (read-signature!)))

    ;; Resolve the retention target now that the run's total recompute cost is
    ;; known: an explicit --per wins; otherwise auto-pick from wall-time (§13.1).
    (define per* (if (eq? per 'auto) (auto-per (unbox wall-ms-box)) per))
    (when (and linked-compressed? (eq? per 'auto))
      (eprintf "  [auto-per ~a: recompute ~ams -> per=~a%]\n"
               compressed (~r (unbox wall-ms-box) #:precision 0) (~r (* 100 per*) #:precision 0)))

    ;; At the final fixpoint the terminal actions run (each emits its own lines).
    (cond
      ;; --out-db-compressed --flatten: one self-contained root (§7.3).
      [(and compressed flatten?)
       (send-plugin (action-so `(write-db ,compressed)))]
      ;; --out-db-compressed (linked): the IDB layer; the root was snapshotted
      ;; above.  per*<1.0 samples the IDB tuples (dropped ones recomputed by
      ;; replay on load); per*=1.0 stores them whole.  An empty IDB writes no
      ;; relation dir (its META-only dir is created below), since these verbs
      ;; require >=1 relation.
      [(and linked-compressed? (not (null? signed-rels)))
       ;; --bias productivity keeps relations read by some rule (productive
       ;; seeds) at a higher fraction than the rest (§4.4); default is uniform.
       (define bias-productivity?
         (and bias (member bias '("productivity" "productive")) #t))
       (define boosted (if bias-productivity? (db-partition-productive-rels partition) '()))
       (define boost (if bias-productivity? (min 1.0 (* 2.0 per*)) per*))
       ;; Pinned oracle relations ride the layer UNSAMPLED (docs/smt.md §15):
       ;; they are in the written set AND named pinned, which forces their
       ;; keep-fraction to 1.0 and makes their rows heap-trimming seed roots
       ;; (so the demand structs + formula DAGs they reference survive).
       (define pinned (db-partition-pinned-rels partition))
       (send-plugin
        (action-so (if (< per* 1.0)
                       `(save-compressed ,compressed ,per* ,compressed-rng-seed ,boost
                                         (boosted ,@boosted)
                                         (pinned ,@pinned)
                                         (rels ,@signed-rels))
                       `(write-db-subset ,compressed ,@signed-rels))))]
      [else (void)])
    (when out-db
      (send-plugin (action-so `(write-db ,out-db))))
    (when debug-out-path
      (send-plugin (action-so `(write-csv ,debug-out-path))))
    (when report-sizes?
      (send-plugin (action-so `(sizes))))
    (close-output-port in)
    (let loop () ;; echo any remaining output from daemon (terminal actions)
      (define s (read-line out))
      (when (not (eof-object? s))
        (display s)
        (newline)
        ;; a terminal action's failure (e.g. a save plugin that would not
        ;; load) must not be swallowed into an exit-0 run
        (when (regexp-match? #px"^\\(error " s)
          (error (format "Daemon reported an error during terminal actions: ~a" s)))
        (loop)))
    (thread-wait err-thread)
    (close-input-port out)
    (close-input-port err)
    (subprocess-wait sp)
    (when (> (subprocess-status sp) 0)
      (error "Something went wrong running the daemon!"))
    ;; A requested save must EXIST and be non-empty after a clean exit: the
    ;; write-db action has no confirmation handshake, so this is the seam
    ;; where a silently-skipped or empty save would otherwise become a
    ;; successful-looking run (the empty-save flake, 2026-07-10).
    (for ([dbn (in-list (filter values (list out-db compressed)))])
      (define d (fullpath (format "data/~a" dbn)))
      (unless (and (directory-exists? d)
                   (pair? (directory-list d)))
        (error (format "save verification failed: data/~a is missing or empty after a clean daemon exit" dbn))))
    ;; The daemon has materialised every data directory; now stamp their META
    ;; headers (P0.5/P0.6).  Done here (post-exit) so the dirs exist and no
    ;; mid-run synchronisation is needed.
    (when compressed
      (write-compressed-metas compressed flatten? partition per* slog-path src-capture captured-sig
                              chained-input root-snapshot? (unbox wall-ms-box)))))

;; Compare a stored content signature to the freshly replayed one and report
;; drift (docs/db-compression.md §11).  compiler-stamp attribution: a newer
;; compiler likely means an intended semantic change; the SAME stamp means
;; nondeterminism or a compression bug -- a louder alarm.  --strict turns any
;; mismatch into an error.
(define (report-drift name stored live meta strict? #:label [label "replay"])
  (define rels (sort (set->list (set-union (list->set (hash-keys stored))
                                           (list->set (hash-keys live))))
                     symbol<?))
  (define diffs
    (for/list ([r (in-list rels)]
               #:unless (equal? (hash-ref stored r #f) (hash-ref live r #f)))
      (match-define (cons sc _) (hash-ref stored r (cons 0 "")))
      (match-define (cons lc _) (hash-ref live r (cons 0 "")))
      (format "    ~a: stored ~a tuple(s) -> replay ~a~a"
              r sc lc (if (= sc lc) " (same count, content changed)" ""))))
  (cond
    [(null? diffs)
     (eprintf "verified ~a: ~a matches stored signature (~a relations)\n"
              name label (hash-count stored))]
    [else
     (define same? (equal? (db-meta-compiler-stamp meta) (current-compiler-stamp)))
     (define msg
       (string-append
        (if same?
            (format "signature drift in ~a under the SAME compiler -- nondeterminism or a compression bug:" name)
            (format "signature drift in ~a on a newer compiler (~a -> ~a) -- likely an intended semantic change:"
                    name (db-meta-compiler-stamp meta) (current-compiler-stamp)))
        "\n" (string-join diffs "\n")))
     (if strict? (error msg) (eprintf "Warning: ~a\n" msg))]))

;; Full-replay verification of a stored compressed database (`slog db verify
;; NAME --replay`).  Loads NAME with #:no-seed? -- the kept IDB samples along
;; the chain are NOT imported, so every replay must re-derive its whole IDB
;; from the EDB -- and compares the result against the stored signature (or
;; the edited-chain baseline).  This is the STRONG integrity check: a seeded
;; load is monotone and masks removals (§11); this one surfaces them.  The
;; query program is an empty loader; strict? makes any drift an error.
(define (slog-verify-replay name #:strict? [strict? #t])
  (define ddir (string-append "data/" name))
  (unless (read-signature-file ddir)
    (error (format "database ~a has no stored signature to verify against (not a compressed layer?)"
                   name)))
  (define tmp (make-temporary-file "slog-verify-~a.slog"))
  (dynamic-wind
   void
   (lambda ()
     (call-with-output-file tmp #:exists 'truncate
       (lambda (p) (fprintf p ";; verify loader\n")))
     (slog-run-file (path->string tmp) name #f #f #f
                    #:no-seed? #t #:strict? strict?))
   (lambda () (when (file-exists? tmp) (delete-file tmp)))))

;; Write the META header(s) for a compressed/flattened save (docs/db-
;; compression.md P0.5/P0.6).  --flatten yields one self-contained root;
;; a linked compressed save yields a pure-EDB root (data/<name>.edb) plus an
;; IDB layer (data/<name>) whose manifest links the root by (name stamp).  At
;; P0 `per` is always 1.0 (no sampler yet), so the layer holds the full IDB and
;; a load is open-root + import-layer (no replay) -- content-equal to the
;; uncompressed db.
;; A manifest entry (name stamp): the current stamp is read from the input's
;; own META (or #f for a plain/legacy db without one).
(define (manifest-entry name)
  (define dir (string-append "data/" name))
  (list name (and (db-meta-file-exists? dir)
                  (db-meta-stamp (read-db-meta dir)))))

(define (write-compressed-metas name flatten? partition per entry sources sig
                                chained-input root-snapshot? wall-ms)
  (define cstamp (current-compiler-stamp))
  (define idb (db-partition-idb-rels partition))
  (define edb (db-partition-edb-rels partition))
  (define range (db-partition-strata-range partition))
  (cond
    [flatten?
     (define dir (string-append "data/" name))
     (unless (directory-exists? dir) (make-directory* dir))
     (define m0 (make-db-meta #:kind 'flat #:pure-edb? #f #:manifest '()
                              #:per 1.0 #:strata range #:compiler-stamp cstamp
                              #:idb-rels idb #:edb-rels edb))
     (write-db-meta (hash-set m0 'stamp (compute-db-stamp m0 #:db-dir dir)) dir)]
    [else
     ;; The layer's manifest links, in load order: the chained -d input (if any,
     ;; materialised recursively) then this save's own fresh EDB root (if it
     ;; snapshotted one).  A from-scratch save links just its root.
     (define root-name (string-append name ".edb"))
     (define root-entry
       (and root-snapshot?
            (let* ([root-dir (string-append "data/" root-name)]
                   [_ (unless (directory-exists? root-dir) (make-directory* root-dir))]
                   [rm0 (make-db-meta #:kind 'root #:pure-edb? #t #:manifest '()
                                      #:per 1.0 #:compiler-stamp cstamp
                                      #:idb-rels '() #:edb-rels edb)]
                   [root-stamp (compute-db-stamp rm0 #:db-dir root-dir)])
              (write-db-meta (hash-set rm0 'stamp root-stamp) root-dir)
              (list root-name root-stamp))))
     (define manifest
       (append (if chained-input (list (manifest-entry chained-input)) '())
               (if root-entry (list root-entry) '())))
     (define dir (string-append "data/" name))
     (unless (directory-exists? dir) (make-directory* dir))
     ;; Store the program source so a load recompiles+replays it (P1.1/§9).
     (when (and sources (positive? (hash-count sources)))
       (write-prog-sexpr dir entry sources))
     ;; Store the full-IDB content signature for load-time verification (P1.3).
     (when (and sig (positive? (hash-count sig)))
       (write-signature-file dir sig))
     (define lm0 (make-db-meta #:kind 'compressed #:pure-edb? #f
                               #:manifest manifest
                               #:per per #:rng-seed compressed-rng-seed
                               #:strata range #:compiler-stamp cstamp
                               #:fixpoint-wall-ms (inexact->exact (round wall-ms))
                               #:idb-rels idb #:edb-rels edb
                               #:pinned-rels (db-partition-pinned-rels partition)))
     (write-db-meta (hash-set lm0 'stamp (compute-db-stamp lm0 #:prog-fingerprint cstamp))
                    dir)]))
