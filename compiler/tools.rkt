#lang racket

(provide convert-db-folder
         delete-folder
         build-so
         finish-jit
         fullpath
         ensure-slogd-exists
         slogd-argv)

(require "utils.rkt")

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

;; Build the argv list for launching the slogd daemon.  By default the daemon
;; is wrapped in a transient `systemd-run --user --scope` with a memory cap, so
;; a runaway program (e.g. a non-terminating fixpoint) is OOM-killed inside its
;; own cgroup instead of taking down the whole login session -- terminal,
;; editor, and this process all share the konsole scope otherwise.  Knobs:
;;   SLOG_MEM_MAX     cap passed to systemd-run's MemoryMax= (default "4G");
;;                    "none"/"off"/"" disables the cap.
;;   SLOG_NO_MEM_CAP  if set non-empty, launch slogd directly (no systemd-run).
;; Falls back to a direct launch (with a warning on stderr) when systemd-run is
;; not on PATH.  `slogd-exe` is the daemon binary; `extra-args` are appended
;; after it (e.g. "-p" PORT for the interactive TCP console).
(define (slogd-argv slogd-exe . extra-args)
  (define slogd (path->string (path->complete-path slogd-exe)))
  (define cap (or (getenv "SLOG_MEM_MAX") "4G"))
  (define cap-off? (and (member (string-downcase cap) '("" "none" "off")) #t))
  (define no-cap? (let ([v (getenv "SLOG_NO_MEM_CAP")]) (and v (not (string=? v "")) #t)))
  (define systemd-run
    (and (not cap-off?) (not no-cap?) (find-executable-path "systemd-run")))
  (cond
    [systemd-run
     (list* (path->string systemd-run)
            "--user" "--scope" "--quiet"
            "-p" (string-append "MemoryMax=" cap)
            "-p" "MemorySwapMax=0"
            slogd extra-args)]
    [else
     (when (and (not cap-off?) (not no-cap?))
       (eprintf "warning: systemd-run not found on PATH; launching slogd without a ~a memory cap\n" cap))
     (cons slogd extra-args)]))

(define (ensure-slogd-exists)
  (when (not (file-exists? "daemon/slogd"))
    (define-values (sp out in err)
      (subprocess #f #f #f (find-executable-path "make") "-C" "daemon"))
    (close-input-port out)
    (close-output-port in)
    (close-input-port err)
    (subprocess-wait sp)
    (when (> (subprocess-status sp) 0)
      (error "Something went wrong compiling the daemon!"))))

(define (build-so cpp-path
                  [so-path (fullpath "build/temp.so")]
                  ;; Must match the daemon's compiler (daemon/Makefile uses
                  ;; clang++) so the .so and daemon share one OpenMP runtime --
                  ;; the .so calls omp_get_thread_num().
                  [cxx-path (or (find-executable-path "clang++")
                                (find-executable-path "c++"))])
  (unless cxx-path
    (error "For reasons unknown, no C++ compiler has been found in PATH."))

  ;; Get system-specific flags like the Makefile does
  (define uname-s (string-trim (with-output-to-string (lambda () (system "uname -s")))))
  (define extra-flags
    (cond
      [(string=? uname-s "Darwin")
       (define brew-prefix (string-trim (with-output-to-string (lambda () (system "brew --prefix")))))
       (list (format "-I~a/include" brew-prefix) (format "-L~a/lib" brew-prefix) "-lz")]
      [(string=? uname-s "Linux") (list "-lz")]
      [else (list "-lz")]))

  (define-values (sp out in err)
    (apply subprocess
           #f
           #f
           #f
           cxx-path
           cpp-path
           "-std=c++20"
           "-fPIC"
           ;; daemon dir on the include path so the vendored tlx headers'
           ;; internal <tlx/...> includes resolve (database.h -> index.h -> tlx).
           "-Idaemon"
           ;; The .so calls Relation::sendBatch, which uses omp_get_thread_num(),
           ;; so it must link the same OpenMP runtime as the daemon.
           "-fopenmp"
           "-fmax-errors=1"
           "-shared"
           "-g"
           ;"-O3"
           (format "-o~a" so-path)
           extra-flags))
  (let loop () ; echo (debug) output from daemon
    (define s (read-line err))
    (when (not (eof-object? s))
      (display s)
      (newline)
      (loop)))
  (close-input-port out)
  (close-output-port in)
  (close-input-port err)
  (subprocess-wait sp)
  (when (> (subprocess-status sp) 0)
    (error "Something went wrong running c++!"))
  so-path)

(define (finish-jit lazy-pair)
  (match lazy-pair
    ['() '()]
    [(cons (? string? phash) fut) (cons (fullpath (format "build/~a.so" phash)) fut)]
    [(cons (list phash cprog cpp) fut)
     (define cpp-path (fullpath (format "build/~a.cpp" phash)))
     (with-output-to-file cpp-path #:exists 'replace (lambda () (display cpp)))
     (with-output-to-file (fullpath (format "build/~a.cprog" phash))
                          #:exists 'replace
                          (lambda () (pretty-write cprog)))
     (define so-path (build-so cpp-path (fullpath (format "build/~a.so" phash))))
     (cons so-path fut)]))
