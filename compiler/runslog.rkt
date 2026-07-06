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
  (define compiled (finish-jit (compile-path slog-path dbmanifest)))
  (ensure-slogd-exists)
  (define-values (sp out in err) (apply subprocess #f #f #f (slogd-argv "daemon/slogd")))
  (define (send-plugin path)
    (display (string-append path "\n"))
    (display (string-append path "\n") in))

  (when db-name
    (send-plugin (action-so `(open ,db-name))))

  ;; Stream the stratum plugins in pipeline order (a declaration-only
  ;; program compiles to no strata at all).
  (let loop ([compiled compiled])
    (unless (null? compiled)
      (send-plugin (car compiled))
      (loop (finish-jit (touch (cdr compiled))))))

  ;; At the final fixpoint:
  (when out-db
    (send-plugin (action-so `(write-db ,out-db))))
  (when debug-out-path
    (send-plugin (action-so `(write-csv ,debug-out-path))))
  (when report-sizes?
    (send-plugin (action-so `(sizes))))
  (close-output-port in)
  (let loop () ;; echo output from daemon
    (define s (read-line out))
    (when (not (eof-object? s))
      (display s)
      (newline)
      (loop)))
  (let loop () ;; echo error output from daemon
    (define s (read-line err))
    (when (not (eof-object? s))
      (display s)
      (newline)
      (loop)))
  (close-input-port out)
  (close-input-port err)
  (subprocess-wait sp)
  (when (> (subprocess-status sp) 0)
    (error "Something went wrong running the daemon!")))
