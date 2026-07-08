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
         db-manifest-from-name)

(require "tools.rkt")
(require "compile.rkt")
(require "actions.rkt")
(require "dbmeta.rkt")
(require "dbtool.rkt")
(require "parser.rkt")   ; current-source-capture (P1.1)

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
                       #:reoptimise? [reoptimise? #f])
  ;; Working directories used by the compiler and daemon (relative to cwd).
  (make-directory* "build")
  (make-directory* "out")
  ;; The query compiles against the FULL DAG manifest so it sees an opened
  ;; compressed db's EDB root as well as its IDB layer (P1.4); a plain db's full
  ;; manifest is just its own directory.
  (define dbmanifest (if db-name (db-full-manifest db-name) (hash)))
  (define replay-plan (compressed-replay-plan db-name))
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

  ;; Force-kill the daemon if compilation or the run errors out after launch,
  ;; rather than leaving it orphaned (blocked reading stdin or mid-fixpoint).
  (with-handlers
      ([exn:fail? (lambda (e)
                    (with-handlers ([exn:fail? void])
                      (unless (port-closed? in) (close-output-port in)))
                    (subprocess-kill sp #t)
                    (raise e))])

    ;; Issue the database load FIRST, before compiling: loadDatabaseBIN is
    ;; single-threaded, so sending (open ...) now lets the load overlap the
    ;; Racket front end, codegen, AND every clang build below
    ;; (docs/fast-compile.md).
    ;; A plain database is a single (open); a compressed one is a manifest-
    ;; driven open-root + import-layer sequence (dbtool.rkt db-load-actions).
    ;; At per=100% this reconstitutes the exact database with no replay.
    (when db-name
      (for ([act (in-list (db-load-actions db-name))])
        (send-plugin (action-so act))))

    ;; Plan every stratum and kick off its build(s) on the parallel pool: tiered
    ;; mode runs each stratum at -O0 immediately and hot-swaps to a background
    ;; -O2 build when ready.  The daemon is already loading the input DB (if any)
    ;; while this runs.
    ;; For a linked compressed save, capture the program's source closure while
    ;; compiling so it can be stored as prog.sexpr and replayed on load (P1.1).
    (define src-capture (and linked-compressed? (make-hash)))
    (define-values (strata partition edb-boundary)
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
    (define (drive-stratum! sb tag)  ; poll one stratum to fixpoint; #t unless eof
      (define o2 (sbuild-o2-path sb))
      (define upgradeable? (and tiered? (eq? tag 'o0) o2))
      (let poll ([swapped? #f])
        (define line (read-line out))
        (cond
          [(eof-object? line) #f]
          [(regexp-match? #px"^\\(fixpoint " line) (displayln line) #t]
          [(regexp-match? #px"^\\(paused " line)
           (displayln line)
           (cond
             ;; A `memory` pause means the run reached the memory cap; in the
             ;; default continue-to-fixpoint mode we can only climb toward the
             ;; hard cgroup cap by continuing, so abort GRACEFULLY instead of
             ;; OOM-crashing (docs/pausing.md §5).
             [(regexp-match? #px"memory\\)\\s*$" line)
              (error (format (string-append
                              "out of memory: the run reached the memory cap "
                              "(configure with SLOG_MEM_BYTES / SLOG_MEM_MAX).\n  ~a")
                             line))]
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

    ;; PHASE R -- recompute-on-load replay (docs/db-compression.md P1.4).  When
    ;; -d opened a compressed database that stored its deriving program,
    ;; recompile that program from prog.sexpr under the CURRENT compiler (the
    ;; original files may be gone/changed -- the source override supplies them)
    ;; and run its strata atop the opened root + imported IDB sample.  This
    ;; regenerates any facts dropped by sampling; at per=100% the sample is the
    ;; whole IDB, so the fixpoint derives nothing new -- a self-verifying load.
    ;; Runs BEFORE the query strata so the query sees the reconstituted db.
    (when replay-plan
      (match-define (cons r-entry r-sources) replay-plan)
      (define-values (r-strata _rp _rb)
        (parameterize ([current-source-override r-sources])
          (compile-strata r-entry dbmanifest #:split-facts? #f)))
      (for ([sb (in-list r-strata)])
        (match-define (cons so tag) ((sbuild-runnable sb)))
        (send-plugin so)
        (drive-stratum! sb tag))
      ;; Verify the replay reproduced the stored content signature (P1.5): drift
      ;; is a compiler change, nondeterminism, or a compression bug.
      (let* ([ddir (string-append "data/" db-name)]
             [stored-sig (read-signature-file ddir)])
        (when stored-sig
          (define meta (read-db-meta ddir))
          (define idb (db-meta-idb-rels meta))
          (unless (null? idb)
            (send-plugin (action-so `(signature ,@idb)))
            (report-drift db-name stored-sig (read-signature!) meta strict?)))))

    ;; A linked compressed save with no facts stratum (edb-boundary 0) snapshots
    ;; the root right after the open, before any stratum runs (the EDB is then
    ;; just the -d input, or empty for a from-scratch program with no facts).
    (when (and linked-compressed? (= edb-boundary 0))
      (send-plugin (action-so `(write-db ,(string-append compressed ".edb")))))

    (for ([sb (in-list strata)] [i (in-naturals)])
      (match-define (cons so tag) ((sbuild-runnable sb)))  ; blocks until built
      (send-plugin so)
      (drive-stratum! sb tag)
      ;; After the facts stratum fixpoints (its output is the pure iteration-0
      ;; EDB), snapshot the root before any derived tuple exists (P0.5).  A
      ;; silent write-db emits no line, so it cannot desync the next stratum's
      ;; handshake; the daemon processes it in stdin order before that stratum.
      (when (and linked-compressed? (> edb-boundary 0) (= (add1 i) edb-boundary))
        (send-plugin (action-so `(write-db ,(string-append compressed ".edb"))))))

    ;; Capture the full-IDB content signature BEFORE the (possibly sampled)
    ;; layer write, so a load can verify the replay reproduced it (P1.3).
    (define captured-sig #f)
    (when (and linked-compressed? (not (null? (db-partition-idb-rels partition))))
      (send-plugin (action-so `(signature ,@(db-partition-idb-rels partition))))
      (set! captured-sig (read-signature!)))

    ;; At the final fixpoint the terminal actions run (each emits its own lines).
    (cond
      ;; --out-db-compressed --flatten: one self-contained root (§7.3).
      [(and compressed flatten?)
       (send-plugin (action-so `(write-db ,compressed)))]
      ;; --out-db-compressed (linked): the IDB layer; the root was snapshotted
      ;; above.  per<1.0 samples the IDB tuples (dropped ones recomputed by
      ;; replay on load); per=1.0 stores them whole.  An empty IDB writes no
      ;; relation dir (its META-only dir is created below), since these verbs
      ;; require >=1 relation.
      [(and linked-compressed? (not (null? (db-partition-idb-rels partition))))
       (send-plugin
        (action-so (if (< per 1.0)
                       `(save-compressed ,compressed ,per ,compressed-rng-seed
                                         ,@(db-partition-idb-rels partition))
                       `(write-db-subset ,compressed
                                         ,@(db-partition-idb-rels partition)))))]
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
        (loop)))
    (thread-wait err-thread)
    (close-input-port out)
    (close-input-port err)
    (subprocess-wait sp)
    (when (> (subprocess-status sp) 0)
      (error "Something went wrong running the daemon!"))
    ;; The daemon has materialised every data directory; now stamp their META
    ;; headers (P0.5/P0.6).  Done here (post-exit) so the dirs exist and no
    ;; mid-run synchronisation is needed.
    (when compressed
      (write-compressed-metas compressed flatten? partition per slog-path src-capture captured-sig))))

;; Compare a stored content signature to the freshly replayed one and report
;; drift (docs/db-compression.md §11).  compiler-stamp attribution: a newer
;; compiler likely means an intended semantic change; the SAME stamp means
;; nondeterminism or a compression bug -- a louder alarm.  --strict turns any
;; mismatch into an error.
(define (report-drift name stored live meta strict?)
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
     (eprintf "verified ~a: replay matches stored signature (~a relations)\n"
              name (hash-count stored))]
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

;; Write the META header(s) for a compressed/flattened save (docs/db-
;; compression.md P0.5/P0.6).  --flatten yields one self-contained root;
;; a linked compressed save yields a pure-EDB root (data/<name>.edb) plus an
;; IDB layer (data/<name>) whose manifest links the root by (name stamp).  At
;; P0 `per` is always 1.0 (no sampler yet), so the layer holds the full IDB and
;; a load is open-root + import-layer (no replay) -- content-equal to the
;; uncompressed db.
(define (write-compressed-metas name flatten? partition per entry sources sig)
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
     (define root-name (string-append name ".edb"))
     (define root-dir (string-append "data/" root-name))
     (unless (directory-exists? root-dir) (make-directory* root-dir))
     (define rm0 (make-db-meta #:kind 'root #:pure-edb? #t #:manifest '()
                               #:per 1.0 #:compiler-stamp cstamp
                               #:idb-rels '() #:edb-rels edb))
     (define root-stamp (compute-db-stamp rm0 #:db-dir root-dir))
     (write-db-meta (hash-set rm0 'stamp root-stamp) root-dir)
     (define dir (string-append "data/" name))
     (unless (directory-exists? dir) (make-directory* dir))
     ;; Store the program source so a load recompiles+replays it (P1.1/§9).
     (when (and sources (positive? (hash-count sources)))
       (write-prog-sexpr dir entry sources))
     ;; Store the full-IDB content signature for load-time verification (P1.3).
     (when (and sig (positive? (hash-count sig)))
       (write-signature-file dir sig))
     (define lm0 (make-db-meta #:kind 'compressed #:pure-edb? #f
                               #:manifest (list (list root-name root-stamp))
                               #:per per #:rng-seed compressed-rng-seed
                               #:strata range #:compiler-stamp cstamp
                               #:idb-rels idb #:edb-rels edb))
     (write-db-meta (hash-set lm0 'stamp (compute-db-stamp lm0 #:prog-fingerprint cstamp))
                    dir)]))
