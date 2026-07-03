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
;; (lattice flat value).
(define (lat-spec-from-token tok)
  (match (string-split tok "-")
    [`("count") `(lattice count)]
    [`("flat" ,t) `(lattice flat ,(string->symbol t))]
    [`(,kind ,base) `(lattice ,(string->symbol kind) ,(string->symbol base))]
    [`(,kind ,base ,param ,v)
     `(lattice ,(string->symbol kind) ,(string->symbol base)
               (,(string->symbol param) ,(string->number v)))]
    [_ (error 'db-manifest "unrecognized lattice spec token on disk: ~a" tok)]))

;; Scan an input database directory into a manifest of its relations.
(define (db-manifest-from-name db-name)
  (if db-name
      (let ([db-path (string-append "data/" db-name "/")])
        (foldl (lambda (path man)
                 (define path+ (fullpath (normalize-path path (path->complete-path db-path))))
                 (match (regexp-match #px"/table\\.(\\w+)\\.arity\\.(\\d+)" path+)
                   [`(,_ ,name ,arity)
                    (hash-set man
                              (string->symbol name)
                              `(rel ,(string->symbol name) ,(string->number arity)))]
                   [_
                    (match (regexp-match #px"/struct\\.(\\w+)\\.arity\\.(\\d+)\\.id\\.(\\d+)" path+)
                      [`(,_ ,name ,arity ,_)
                       (hash-set man
                                 (string->symbol name)
                                 `(struct ,(string->symbol name) ,(string->number arity)))]
                      [_
                       (match (regexp-match #px"/lat\\.(\\w+)\\.arity\\.(\\d+)\\.spec\\.([-.'\\w]+)" path+)
                         [`(,_ ,name ,arity ,tok)
                          (hash-set man
                                    (string->symbol name)
                                    `(lat ,(string->symbol name) ,(string->number arity)
                                          ,(lat-spec-from-token tok)))]
                         [_ man])])]))
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
