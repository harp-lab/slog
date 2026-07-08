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

;; Compile slog-path and run every stratum plugin through a fresh slogd,
;; optionally against input database db-name, optionally writing the final
;; database (binary) to out-db and/or (CSV) to debug-out-path, optionally
;; reporting every relation's tuple count.
(define (slog-run-file slog-path
                       [db-name #f]
                       [out-db #f]
                       [debug-out-path #f]
                       [report-sizes? #f])
  ;; Working directories used by the compiler and daemon (relative to cwd).
  (make-directory* "build")
  (make-directory* "out")
  (define dbmanifest (db-manifest-from-name db-name))
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
    (when db-name
      (send-plugin (action-so `(open ,db-name))))

    ;; Plan every stratum and kick off its build(s) on the parallel pool: tiered
    ;; mode runs each stratum at -O0 immediately and hot-swaps to a background
    ;; -O2 build when ready.  The daemon is already loading the input DB (if any)
    ;; while this runs.
    (define strata (compile-strata slog-path dbmanifest))

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

    (for ([sb (in-list strata)])
      (match-define (cons so tag) ((sbuild-runnable sb)))  ; blocks until built
      (send-plugin so)
      (drive-stratum! sb tag))

    ;; At the final fixpoint the terminal actions run (each emits its own lines).
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
      (error "Something went wrong running the daemon!"))))
