#lang racket

(provide convert-db-folder
         delete-folder
         build-so
         compile-one
         ensure-pch
         pooled-eager
         o2-build-command
         spawn-detached-o2-batch
         call-with-atomic-output
         fullpath
         ensure-slogd-exists
         slogd-argv
         daemon-headers-fingerprint
         compiler-sources-fingerprint)

(require "utils.rkt")
(require racket/runtime-path)
(require racket/future)   ; processor-count
(require racket/random)   ; crypto-random-bytes
(require sha)

(define-runtime-path daemon-dir "../daemon")
(define-runtime-path compiler-dir ".")

;; Cross-process-safe temp file in build/.  Racket's make-temporary-file has a
;; TOCTOU window across SEPARATE `racket slog.rkt` processes (run-tests.sh -jN
;; compiling the same content-addressed stratum concurrently), which surfaces as
;; "open-output-file: file exists".  We give every process a unique OS-entropy
;; salt so its temp names live in a disjoint namespace (no cross-process
;; collision is possible), and retry on the residual filesystem-exists race.
;; `template` must contain one ~a (e.g. "w~a.tmp").
(define build-temp-salt (bytes->hex-string (crypto-random-bytes 6)))
(define (build-tempfile template)
  (let retry ([n 0])
    (with-handlers ([exn:fail:filesystem?
                     (lambda (e) (if (< n 32) (retry (add1 n)) (raise e)))])
      (path->string
       (make-temporary-file (string-append build-temp-salt "-" template)
                            #f (fullpath "build"))))))

(define (fingerprint-dir dir rx)
  (apply string-append
         (for/list ([f (in-list (sort (map path->string (directory-list dir))
                                      string<?))]
                    #:when (and (regexp-match? rx f)
                                ;; skip dangling editor lock symlinks (.#foo.h)
                                (file-exists? (build-path dir f))))
           (file->string (build-path dir f)))))

;; Fingerprint of the daemon headers.  Generated .so's #include daemon
;; headers and inline Database's layout and methods, so any header change
;; must invalidate cached .so's (otherwise a stale .so reads members at the
;; wrong offsets).  Folded into every .so cache key.
(define daemon-headers-fingerprint (fingerprint-dir daemon-dir #rx"\\.h$"))

;; Fingerprint of the compiler itself, so editing a pass invalidates cached
;; .so's (previously a stale .so could silently mask a codegen change).
(define compiler-sources-fingerprint (fingerprint-dir compiler-dir #rx"\\.rkt$"))

(define (delete-folder path)
  (define-values (sp out in err) (subprocess #f #f #f "/bin/rm" "-rf" path))
  (close-input-port out)
  (close-output-port in)
  (close-input-port err)
  (subprocess-wait sp))

(define (convert-db-folder path dbname)
  (let () ;; setup folder
    (delete-folder (format "data/~a" dbname))
    (make-directory (format "data/~a/" dbname))
    (make-directory (format "data/~a/value.strings/" dbname)))

  (if (directory-exists? path)
      (let ([out-files (make-hash)]
            [strings-file (open-output-file (format "data/~a/value.strings/0.bin" dbname))]
            [fnv-to-count (make-hash)]
            [string-to-value (make-hash)]
            [struct-map (make-hash)]
            [alloc-map (make-hash)]
            [in-files (directory-list path)]
            [struct-id-max 1])

        (define (alloc-struct-id)
          (let ([n struct-id-max])
            (set! struct-id-max (add1 struct-id-max))
            n))

        (define (int->bytes n len)
          (if (= len 0)
              (bytes)
              (bytes-append (bytes (bitwise-and n 255))
                            (int->bytes (arithmetic-shift n -8) (- len 1)))))

        (define (alloc structname)
          (define n (hash-ref alloc-map structname (lambda () 0)))
          (hash-set! alloc-map structname (add1 n))
          n)

        (define (emit-string s)
          (write-bytes (bytes-append (string->bytes/utf-8 s) (bytes 0)) strings-file))

        (define str-type 0) ;; intern type tags are 0..7 inclusive
        (define s32-type 1) ;; prim type tags are 1..7 inclusive
        (define NaNcode (arithmetic-shift (sub1 (expt 2 11)) 52))
        (define interncode (bitwise-ior NaNcode (arithmetic-shift (sub1 (expt 2 14)) 38)))
        ;; Uses a NaN-based IEEE-754 Binary64 encoding of non-float values
        ;; 0 11111111111 1111111 XXXXX YYYY....[35bit intern-id]....YYYYYY
        (define (make-intern-value type-code lower-bits) ; 3 bit type code
          (int->bytes (bitwise-ior lower-bits (arithmetic-shift type-code 35) interncode) 8))
        ;; 0 11111111111 0000000 XXXXX YYYY....[prim-value]...YYYYYY
        (define (make-prim-value type-code lower-bits) ; 3 bit non-zero type code
          (int->bytes (bitwise-ior lower-bits (arithmetic-shift type-code 35) NaNcode) 8))
        ;; 1 11111111111 [14bit struct-id]  [38bit interned struct id with buckets at bottom]
        (define (make-struct-value struct-id id)
          (int->bytes (bitwise-ior id (arithmetic-shift struct-id 38) NaNcode (arithmetic-shift 1 63))
                      8))
        ;; strings are interned intro a separate table
        (define (intern-string s)
          (when (not (hash-has-key? string-to-value s))
            (let* ([fnvhash (fnv s)]
                   [coll-n (hash-ref fnv-to-count fnvhash (lambda () 0))])
              (hash-set! fnv-to-count fnvhash (add1 coll-n))
              (define str-id (bitwise-ior (arithmetic-shift coll-n 32) fnvhash))
              (hash-set! string-to-value s (make-intern-value str-type str-id))
              (emit-string s)))
          (hash-ref string-to-value s))

        (define (write-val v)
          (match v
            [(? bytes?) v]
            ;; Strings are interned
            [(? string?) (intern-string v)]
            ;; Floating points are stored as their little-endian binary64 encoding
            [(and (? number?) (? inexact?)) (real->floating-point-bytes v 8 #f)]
            [(? integer?)
             #:when (and (> v (- (expt 2 31))) (< v (expt 2 31)))
             ;; 0 11111111111 0 1 ... [SIGNED INT] ...
             (make-prim-value s32-type v)]
            [(? integer? x) (error "BigInt prims not supported yet.")]
            [`(,structname ,vals ...)
             (match (hash-ref out-files (symbol->string structname) (lambda () #f))
               [`(struct ,arity ,struct-id ,port)
                (when (not (= arity (length vals)))
                  (error "Struct arity mismatch"))
                (when (not (hash-has-key? struct-map v))
                  (hash-set! struct-map v (alloc structname)))
                (define id (hash-ref struct-map v))
                (define id-bytes (make-struct-value struct-id id))
                (emit-tuple (symbol->string structname) `(,id-bytes ,@vals))
                id-bytes]

               [_
                (define struct-id (alloc-struct-id))
                (define out-folder
                  (format "data/~a/struct.~a.arity.~a.id.~a/"
                          dbname
                          structname
                          (add1 (length vals))
                          struct-id))
                (make-directory out-folder)
                (define out-file (string-append out-folder "0.bin"))
                (display (format "Writing ~a\n" out-file))
                (hash-set! out-files
                           (symbol->string structname)
                           `(struct ,(length vals) ,struct-id ,(open-output-file out-file)))
                (write-val v)])]
            [_ (error "Unmable to write other types just now.")]))

        (define (emit-tuple relname tuple)
          (match (hash-ref out-files relname)
            [`(rel ,arity ,port)
             #:when (= arity (length tuple))
             (write-bytes (apply bytes-append (map write-val tuple)) port)]
            [`(struct ,arity ,struct-id ,port)
             #:when (= (add1 arity) (length tuple))
             (write-bytes (apply bytes-append (map write-val tuple)) port)]))

        (map (lambda (file)
               (define infile (normalize-path file (path->complete-path path)))
               (match (regexp-match #px"/(\\w+)\\.(\\d+)\\.csv$" (fullpath infile))
                 [`(,_ ,relname ,aritystr)
                  (define arity (string->number aritystr))
                  ;; the daemon can only load arities 1..32 (and arity 0
                  ;; would loop forever below reading zero-length tuples)
                  (unless (and arity (<= 1 arity 32))
                    (error 'convert-db-folder
                           "~a: arity ~a out of the loadable range 1..32"
                           file arity))
                  (define outfolder (format "data/~a/table.~a.arity.~a/" dbname relname arity))
                  (make-directory outfolder)
                  (define outfile (string-append outfolder "0.bin"))
                  (display (format "Writing ~a\n" outfile))
                  (hash-set! out-files relname `(rel ,arity ,(open-output-file outfile)))
                  (with-input-from-file infile
                                        (lambda ()
                                          (let loop ()
                                            (define tup (map (lambda (x) (read)) (range arity)))
                                            (if (ormap eof-object? tup)
                                                (void)
                                                (let ()
                                                  (emit-tuple relname tup)
                                                  (loop))))))]
                 [_ (void)]))
             in-files)

        (map (lambda (file)
               (match file
                 [`(rel ,arity ,port) (close-output-port port)]
                 [`(struct ,arity ,struct-id ,port) (close-output-port port)]))
             (hash-values out-files))
        (close-output-port strings-file)
        (void))

      (error "Cannot convert DB directory; it does not exist.")))

;; Parse a memory size ("4G" / "512M" / "1048576") into bytes; #f if unparseable.
(define (parse-mem-size s)
  (define m (regexp-match #px"^\\s*([0-9]+)\\s*([KkMmGgTt]?)\\s*$" s))
  (and m
       (* (string->number (second m))
          (case (string-downcase (third m))
            [("k") 1024] [("m") 1048576] [("g") 1073741824]
            [("t") 1099511627776] [else 1]))))

;; Build the argv list for launching the slogd daemon.  By default the daemon
;; is wrapped in a transient `systemd-run --user --scope` with a memory cap, so
;; a runaway program (e.g. a non-terminating fixpoint) is OOM-killed inside its
;; own cgroup instead of taking down the whole login session -- terminal,
;; editor, and this process all share the konsole scope otherwise.  Knobs:
;;   SLOG_MEM_MAX     hard cgroup cap for systemd-run's MemoryMax= (default
;;                    "4G"); "none"/"off"/"" disables it.
;;   SLOG_MEM_BYTES   daemon GRACEFUL soft cap in bytes (docs/pausing.md §5): at
;;                    this much RSS the run pauses with reason `memory` and the
;;                    front end aborts cleanly.  Defaults here to ~90% of the
;;                    hard cap so it fires before the cgroup OOM-kills.
;;   SLOG_NO_MEM_CAP  if set non-empty, launch slogd directly (no systemd-run).
;; Falls back to a direct launch (with a warning on stderr) when systemd-run is
;; not on PATH.  `slogd-exe` is the daemon binary; `extra-args` are appended
;; after it (e.g. "-p" PORT for the interactive TCP console).
;; Worker-thread count the driver asks the daemon for.  SLOG_THREADS overrides
;; (the slog config system sets it); otherwise default to one fewer than the
;; detected processor count, leaving headroom for the OS and this driver's own
;; parallel build pool (build-parallelism below).  An explicit -t already in
;; extra-args still wins (we don't add a second one).
(define (slog-thread-count)
  (define env (getenv "SLOG_THREADS"))
  (define n (and env (string->number (string-trim env))))
  (if (and n (exact-integer? n) (>= n 1))
      n
      (max 1 (sub1 (processor-count)))))

(define (slogd-argv slogd-exe . extra-args)
  (define slogd (path->string (path->complete-path slogd-exe)))
  ;; Inject the dynamic thread default as an explicit -t unless the caller
  ;; already specified one.
  (define extra-args*
    (if (member "-t" extra-args)
        extra-args
        (list* "-t" (number->string (slog-thread-count)) extra-args)))
  (define cap (or (getenv "SLOG_MEM_MAX") "4G"))
  (define cap-off? (and (member (string-downcase cap) '("" "none" "off")) #t))
  (define no-cap? (let ([v (getenv "SLOG_NO_MEM_CAP")]) (and v (not (string=? v "")) #t)))
  ;; Track the daemon soft cap to ~90% of the hard cap unless set explicitly,
  ;; so the graceful pause always precedes the cgroup kill.
  (unless (or cap-off? (getenv "SLOG_MEM_BYTES"))
    (let ([bytes (parse-mem-size cap)])
      (when bytes
        (putenv "SLOG_MEM_BYTES" (number->string (quotient (* bytes 9) 10))))))
  (define systemd-run
    (and (not cap-off?) (not no-cap?) (find-executable-path "systemd-run")))
  (cond
    [systemd-run
     (list* (path->string systemd-run)
            "--user" "--scope" "--quiet"
            "-p" (string-append "MemoryMax=" cap)
            "-p" "MemorySwapMax=0"
            slogd extra-args*)]
    [else
     (when (and (not cap-off?) (not no-cap?))
       (eprintf "warning: systemd-run not found on PATH; launching slogd without a ~a memory cap\n" cap))
     (cons slogd extra-args*)]))

;; The daemon binary is STALE if missing or older than any daemon source (.h or
;; .cpp).  A stale slogd is not merely a perf issue: generated .so's inline the
;; daemon's data-structure layouts (wrong offsets if headers changed) and, since
;; makeIndex/makeMapIndex moved out-of-line, resolve those symbols from slogd's
;; exported dynamic table -- an old slogd built before that change lacks them, so
;; a plugin's orphan-restore path would fail at runtime.  Rebuild rather than
;; only-when-absent (the Makefile's own slogd: slogd.cpp $(HEADERS) rule agrees).
(define (slogd-stale?)
  (define exe "daemon/slogd")
  (or (not (file-exists? exe))
      (let ([m (file-or-directory-modify-seconds exe)])
        (for/or ([f (in-list (directory-list daemon-dir))]
                 #:when (and (regexp-match? #rx"\\.(h|cpp)$" (path->string f))
                             (file-exists? (build-path daemon-dir f))))
          (> (file-or-directory-modify-seconds (build-path daemon-dir f)) m)))))

(define (ensure-slogd-exists)
  (when (slogd-stale?)
    ;; Redirect make's stdout+stderr to a log file (NOT closed pipes -- closing
    ;; the read end mid-build SIGPIPEs the compiler and fails the build); surface
    ;; the log on failure.
    (make-directory* (fullpath "build"))
    (define log-path (fullpath "build/slogd-build.log"))
    (define logport (open-output-file log-path #:exists 'replace))
    (define-values (sp out in err)
      (subprocess logport #f logport (find-executable-path "make") "-C" "daemon"))
    (close-output-port in)
    (subprocess-wait sp)
    (close-output-port logport)
    (when (> (subprocess-status sp) 0)
      (error (format "Something went wrong compiling the daemon!\n~a"
                     (file->string log-path))))))

;; The C++ compiler used for every generated .so.  Must match the daemon's
;; (daemon/Makefile uses clang++) so the .so and daemon share one OpenMP
;; runtime -- the .so calls omp_get_thread_num().
(define the-cxx-path
  (or (find-executable-path "clang++") (find-executable-path "c++")))

;; System-specific link/include flags, computed once (each shells out).
(define extra-cxx-flags
  (let ([uname-s (string-trim (with-output-to-string (lambda () (system "uname -s"))))])
    (cond
      [(string=? uname-s "Darwin")
       (define brew-prefix (string-trim (with-output-to-string (lambda () (system "brew --prefix")))))
       (list (format "-I~a/include" brew-prefix) (format "-L~a/lib" brew-prefix) "-lz")]
      [else (list "-lz")])))

;; Debug info is off by default (measured ~30% of a stratum's clang time,
;; docs/fast-compile.md §7.3); set SLOG_DEBUG=1 to emit -g.
(define (debug-build?)
  (let ([v (getenv "SLOG_DEBUG")]) (and v (not (string=? v "")) #t)))

;; The compile flags shared by strata, actions, and the precompiled header.
;; `opt` is a string like "-O0"/"-O2".  -ffp-contract=off (matched by the
;; daemon Makefile) keeps float primitives bit-identical across the daemon and
;; every plugin -- and across an -O0 plugin and its -O2 hot-swap replacement
;; (docs/fast-compile.md §7.5).  -Idaemon lets the vendored tlx headers'
;; internal <tlx/...> includes resolve.
(define (base-cxx-flags opt)
  (append (list "-std=c++20" "-fPIC" "-Idaemon" "-fopenmp" "-ffp-contract=off"
                "-ferror-limit=1" opt)
          (if (debug-build?) (list "-g") '())))

;; ---- precompiled header (docs/fast-compile.md §7.2) --------------------
;; The daemon headers parse in ~2.4s per TU; a PCH cuts that to ~0.5s.  One PCH
;; per (daemon-headers-fingerprint x opt x debug), built lazily into build/ and
;; reused.  Best-effort: any failure returns #f and builds fall back to plain
;; header inclusion.  clang PCHs are opt/flag-sensitive, so the key encodes opt
;; and -g, and the fingerprint invalidates it when a daemon header changes.

(define pch-build-lock (make-semaphore 1))
(define daemon-fp8
  (substring (bytes->hex-string
              (sha256 (string->bytes/utf-8 daemon-headers-fingerprint)))
             0 8))
(define (pch-path opt)
  (fullpath (format "build/slog-~a-~a~a.pch"
                    daemon-fp8 (substring opt 1) (if (debug-build?) "g" ""))))

;; Newest mtime among the daemon headers (computed once; headers do not change
;; mid-run).  clang validates a consumed PCH by its inputs' mtimes, so a PCH
;; older than any header is rejected -- even when the header's CONTENT is
;; unchanged (a git checkout / touch bumps mtime only).  Since our PCH cache key
;; is content-based (daemon_fp8), such a mtime-only bump would otherwise reuse a
;; now-rejected PCH and wedge every compile; we rebuild it instead.
(define daemon-headers-newest-mtime
  (apply max 0
         (for/list ([f (in-list (directory-list daemon-dir))]
                    #:when (and (regexp-match? #rx"\\.h$" (path->string f))
                                (file-exists? (build-path daemon-dir f))))
           (file-or-directory-modify-seconds (build-path daemon-dir f)))))
(define (pch-fresh? p)
  (and (file-exists? p)
       (>= (file-or-directory-modify-seconds p) daemon-headers-newest-mtime)))

;; Compile umbrella (daemon.h + operators.h) to a PCH for `opt`; return the path
;; or #f if the PCH could not be built.  Idempotent and concurrency-safe.
(define (ensure-pch opt)
  (define p (pch-path opt))
  (cond
    [(pch-fresh? p) p]
    [else
     (call-with-semaphore pch-build-lock
       (lambda ()
         (cond
           [(pch-fresh? p) p]        ; another thread just (re)built it
           [else
            (with-handlers ([exn:fail? (lambda (_) #f)])
              (define umbrella (fullpath "build/slog-pch-umbrella.hpp"))
              ;; Write ONCE and never rewrite: clang invalidates a PCH when its
              ;; source header's mtime changes, so if the -O0 and -O2 ensure-pch
              ;; calls both rewrote this the first-built PCH would go stale.
              ;; (Serialized by pch-build-lock, so the file-exists? test is safe.)
              (unless (file-exists? umbrella)
                (with-output-to-file umbrella #:exists 'replace
                  (lambda ()
                    (display "#include \"../daemon/daemon.h\"\n")
                    (display "#include \"../daemon/operators.h\"\n"))))
              (define tmp (build-tempfile "pch~a.tmp"))
              (define logport (open-output-file (string-append tmp ".log") #:exists 'replace))
              (define-values (sp out in err)
                (apply subprocess logport #f logport the-cxx-path
                       "-x" "c++-header" umbrella
                       (append (base-cxx-flags opt) (list (format "-o~a" tmp)))))
              (close-output-port in)
              (subprocess-wait sp)
              (close-output-port logport)
              (delete-file* (string-append tmp ".log"))
              (cond
                [(= 0 (subprocess-status sp))
                 (rename-file-or-directory tmp p #t)
                 p]
                [else (delete-file* tmp) #f]))])))]))

(define (delete-file* p) (when (file-exists? p) (with-handlers ([exn:fail? void]) (delete-file p))))

;; ---- compiling one .cpp into one .so ----------------------------------
;; A single clang++ invocation, redirecting stdout+stderr to a per-build log
;; file so many can run concurrently without a shared pipe filling and
;; deadlocking (docs/fast-compile.md §5).  Compiles to a unique temp then
;; atomically renames onto so-path, so a concurrent daemon that has already
;; dlopen'd an older so-path (the -O0->-O2 upgrade case) never sees a torn file.
;; Returns (values success? log-string).
(define (compile-one cpp-paths so-path opt pch)
  (unless the-cxx-path
    (error "For reasons unknown, no C++ compiler has been found in PATH."))
  (define tmp (build-tempfile "so~a.tmp"))
  (define log-path (string-append tmp ".log"))
  (define logport (open-output-file log-path #:exists 'replace))
  (define argv
    (append (list the-cxx-path)
            (if (list? cpp-paths) cpp-paths (list cpp-paths))
            (base-cxx-flags opt)
            (if pch (list "-include-pch" pch) '())
            (list "-shared" (format "-o~a" tmp))
            extra-cxx-flags))
  (define-values (sp out in err)
    (apply subprocess logport #f logport argv))
  (close-output-port in)
  (subprocess-wait sp)
  (close-output-port logport)
  (define log (file->string log-path))
  (delete-file* log-path)
  (define ok? (= 0 (subprocess-status sp)))
  (if ok?
      (rename-file-or-directory tmp so-path #t)
      (delete-file* tmp))
  (values ok? log))

;; Synchronous build of one .cpp (or list of .cpp TUs linked into one .so).
;; `opt` defaults to -O2 (the historical behavior); the tiered driver passes an
;; explicit level.  `pch` is 'auto (build/reuse a PCH), #f (none), or a path.
(define (build-so cpp-path
                  [so-path (fullpath "build/temp.so")]
                  #:opt [opt "-O2"]
                  #:pch [pch 'auto])
  (define pchp (cond [(eq? pch 'auto) (ensure-pch opt)] [else pch]))
  (define-values (ok? log) (compile-one cpp-path so-path opt pchp))
  ;; Only surface the clang log on failure -- on success it is at most warnings,
  ;; and echoing it from a parallel build pool would interleave noisily on the
  ;; console (and never touches the daemon protocol pipe regardless).
  (unless ok? (error (format "Something went wrong running c++!\n~a" log)))
  so-path)

;; ---- bounded parallel build pool (docs/fast-compile.md §5) --------------
;; Eager clang builds run concurrently, capped at the core count so a program's
;; strata compile in parallel instead of one-at-a-time.  pooled-eager starts the
;; work immediately in a pool thread and returns a thunk that blocks until it is
;; done (re-raising any error), so the driver can force stratum k's build in
;; pipeline order while k+1.. build behind it.
;; Parallel clang build pool size.  SLOG_BUILD_JOBS overrides (useful on shared
;; / CI machines); otherwise use the full processor count.  Resolved lazily on
;; first build so the slog config system (which sets SLOG_BUILD_JOBS after module
;; load) is honored.
(define (build-parallelism)
  (let* ([env (getenv "SLOG_BUILD_JOBS")]
         [n (and env (string->number (string-trim env)))])
    (max 1 (if (and n (exact-integer? n) (>= n 1)) n (processor-count)))))
(define build-sem-box (box #f))
(define build-sem-init-lock (make-semaphore 1))
(define (build-sem)
  (or (unbox build-sem-box)
      (call-with-semaphore build-sem-init-lock
        (lambda ()
          (or (unbox build-sem-box)
              (let ([s (make-semaphore (build-parallelism))])
                (set-box! build-sem-box s)
                s))))))
(define (pooled-eager thunk)
  (define result (box #f))
  (define err (box #f))
  (define done (make-semaphore 0))
  (thread
   (lambda ()
     (with-handlers ([(lambda (_) #t) (lambda (e) (set-box! err e))])
       (call-with-semaphore (build-sem) (lambda () (set-box! result (thunk)))))
     (semaphore-post done)))
  (lambda ()
    (semaphore-wait done)
    (semaphore-post done)            ; re-postable: force may be called again
    (when (unbox err) (raise (unbox err)))
    (unbox result)))

;; Minimal POSIX single-quoting for one shell word (coercing paths to strings).
(define (sh-q x)
  (define s (if (path? x) (path->string x) (format "~a" x)))
  (string-append "'" (regexp-replace* #rx"'" s "'\\\\''") "'"))

;; Atomically (re)write a file: emit to a unique temp in build/ then rename over
;; the target (same-dir rename is atomic on POSIX).  So a concurrent reader --
;; e.g. another `racket slog.rkt` compiling the SAME content-addressed stratum
;; under run-tests.sh -jN -- never sees a half-written .cpp/.cprog/.meta.
(define (call-with-atomic-output path thunk)
  (define tmp (build-tempfile "w~a.tmp"))
  (with-output-to-file tmp #:exists 'replace thunk)
  (rename-file-or-directory tmp path #t))

;; The shell command for one background -O2 build: compile to a unique temp,
;; then atomically rename it onto so-path (so a daemon that has already dlopen'd
;; the -O0 .so at that path never sees a torn file), cleaning the temp either way.
(define (o2-build-command cpp-paths so-path)
  (define pchp (ensure-pch "-O2"))
  (define tmp (build-tempfile "o2~a.tmp"))
  (define argv (append (list the-cxx-path)
                       (if (list? cpp-paths) cpp-paths (list cpp-paths))
                       (base-cxx-flags "-O2")
                       (if pchp (list "-include-pch" pchp) '())
                       (list "-shared" (format "-o~a" tmp))
                       extra-cxx-flags))
  (string-append "nice -n 10 " (string-join (map sh-q argv) " ")
                 " && mv -f " (sh-q tmp) " " (sh-q so-path)
                 " ; rm -f " (sh-q tmp)))

;; Run all background -O2 builds as ONE detached, bounded-parallel job
;; (docs/fast-compile.md §2/§7).  A per-stratum detached process would let a
;; many-stratum program spawn unbounded concurrent clang -O2's (memory pressure,
;; no cgroup bound); instead a single detached bash driver runs the commands from
;; a jobfile at most (cores/2) at a time.  Detached, so it outlives this driver
;; (a Racket subprocess is not killed when its parent exits) and the .so's still
;; land in the cache for next time.
(define (spawn-detached-o2-batch commands)
  (when (pair? commands)
    (define jobfile (build-tempfile "o2jobs~a.sh"))
    (with-output-to-file jobfile #:exists 'replace
      (lambda () (for ([c (in-list commands)]) (displayln c))))
    (define k (max 1 (quotient (build-parallelism) 2)))
    ;; read -r (no quote processing) each line; eval it; cap concurrency with
    ;; bash's wait -n.  Passed verbatim as bash's -c arg (no outer shell), so the
    ;; jobfile lines' own single-quoting is the only quoting that matters.
    (define script
      (string-append
       "K=" (number->string k) "\n"
       "while IFS= read -r c; do\n"
       "  eval \"$c\" &\n"
       "  while [ \"$(jobs -rp | wc -l)\" -ge \"$K\" ]; do wait -n 2>/dev/null || wait; done\n"
       "done < " (sh-q jobfile) "\n"
       "wait\n"
       "rm -f " (sh-q jobfile) "\n"))
    (define devnull-out (open-output-file "/dev/null" #:exists 'append))
    (define devnull-in (open-input-file "/dev/null"))
    (define-values (sp o i e)
      (subprocess devnull-out devnull-in devnull-out "/bin/bash" "-c" script))
    (close-output-port devnull-out)
    (close-input-port devnull-in)
    (void)))
