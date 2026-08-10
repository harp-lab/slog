#lang racket

(provide convert-db-folder
         delete-folder
         build-so
         compile-one
         ensure-pch
         pooled-eager
         pool-boost!            ; T3b slice 4: current-SCC O0 jumps the queue
         core-budget            ; T3b slice 4: the one compile-side budget
         core-count
         clang-report           ; T3b slice 4: §5.4's measured clang metric
         o2-build-command
         spawn-detached-o2-batch
         o-cache-path
         link-os
         try-claim-o2!
         clear-o2-marker!
         stratum-tu-paths
         call-with-atomic-output
         fullpath
         ensure-slogd-exists
         ensure-slog-freeze-exists
         run-freezer
         slogd-argv
         daemon-headers-fingerprint
         compiler-sources-fingerprint)

(require "utils.rkt")
(require racket/runtime-path)
(require racket/future)   ; processor-count
(require racket/random)   ; crypto-random-bytes
(require file/gunzip)     ; gzipped importer inputs
(require "sha256.rkt")

(define-runtime-path daemon-dir "../daemon")
(define-runtime-path compiler-dir ".")

;; Cross-process-safe temp file in build/.  Racket's make-temporary-file has a
;; TOCTOU window across SEPARATE `racket compiler/run.rkt` processes (run-tests.sh -jN
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

;; Import a folder of delimited text files as a static binary database under
;; data/<dbname>/, loadable afterwards with `racket compiler/run.rkt -d <dbname>`.
;; One relation per input file (or per subdirectory of shard files):
;;
;;   edge.csv | edge.tsv | edge.txt   arity inferred from the first row
;;   edge.2.csv                       arity stated in the file name
;;   edge/  or  edge.2/               a directory of shards, one .bin each
;;
;; Any input may be gzipped (edge.csv.gz).  Rows are newline-delimited and
;; columns are separated by runs of spaces and tabs, or by a single #:delimiter
;; character if one is given.  A column is
;;
;;   1712              an int  (an interned bignum outside the s32 range)
;;   0.5 | -1.25e2     a float
;;   alice             a str
;;   "bob jones"       a str, and may hold delimiters
;;   (pt 1 2)          a struct value, nestable: (seg (pt 1 2) (pt 3 4))
;;
;; A `#` line is a comment.  A comment whose columns are all type names is a
;; schema line, which forces column types (and settles arity) rather than
;; leaving them to what the first row happens to look like:
;;
;;   # str str int
;;   alice bob 7
;;
;; #:read-values? #t restores the original Racket-`read` tokenizer, where a
;; value may span lines and row boundaries come from the arity alone.
;;
;; The delicate part is interned ids.  value.strings/0.bin and value.mpz/0.bin
;; are re-interned in file order by Database::loadStringsBIN/loadMpzBIN, so the
;; id written into a tuple word has to be exactly the one
;; InternTable::intern_value will hand back: the low 26 bits are the FNV-1a
;; hash (intern_buckets_bits 21 plus 5 inner-position bits) and the bits above
;; are the value's position in that hash's collision chain.  The two tables
;; hash slightly differently -- utf8string xors a SIGNED char, mpz_val an
;; unsigned byte -- and they are separate tables, so their chains are counted
;; separately.  This mirrors daemon/intern.h and must keep mirroring it; a
;; mismatch is not silent corruption but a "Dangling string id" / "Dangling
;; mpz id" fatal at load.  Struct instance ids are safe to number from 0
;; because Relation::seedInternAllocators lifts every bucket's allocator above
;; the largest id in a loaded file, so nothing the daemon mints later collides.
(define (convert-db-folder path dbname
                          #:read-values? [read-values? #f]
                          #:delimiter [delimiter #f]
                          #:skip-rows [skip-rows 0])
  (unless (directory-exists? path)
    (error 'convert-db-folder "cannot convert ~a; it is not a directory" path))
  (unless (directory-exists? "data")
    (error 'convert-db-folder
           "no data/ directory under ~a -- run this from the repository root"
           (current-directory)))

  ;; Build into a staging directory and rename it into place at the very end.
  ;; A failed import must not leave a half-written data/<dbname>/ behind: it
  ;; would load as a real database, silently short a relation or two.
  (define staging (format "data/.import-~a" dbname))
  (delete-folder staging)
  (make-directory (format "~a/" staging))
  (make-directory (format "~a/value.strings/" staging))

  (let ([out-files (make-hash)]
        [strings-file (open-output-file (format "~a/value.strings/0.bin" staging))]
        [mpz-file #f]
        [str-chains (make-hash)]
        [mpz-chains (make-hash)]
        [string-to-value (make-hash)]
        [mpz-to-value (make-hash)]
        [struct-map (make-hash)]
        [alloc-map (make-hash)]
        [row-counts (make-hash)]
        [col-types (make-hash)]     ; relname -> vector of observed type sets
        [struct-fields (make-hash)] ; struct name -> vector of observed type sets
        [rel-shape (make-hash)]     ; relname -> (arity schema-or-#f), rows or not
        [enum-members (mutable-set)]
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

    (define str-type 0) ;; intern type tags are 0..7 inclusive
    (define mpz-type 1)
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

    ;; FNV-1a, as daemon/intern.h's two fasthash specializations spell it.
    ;; fasthash<utf8string> xors a SIGNED char, so a byte >= 0x80 sign-extends
    ;; first; fasthash<mpz_val> xors an unsigned byte and does not.
    (define (fnv32 bs signed?)
      (for/fold ([h 2166136261]) ([b (in-bytes bs)])
        (bitwise-and (* (bitwise-xor h (if (and signed? (>= b 128)) (+ b #xffffff00) b))
                        16777619)
                     #xffffffff)))

    ;; The id InternTable::intern_value returns for the `n`th distinct value
    ;; whose hash shares these low 26 bits.
    (define (intern-id chains hash)
      (define lo26 (bitwise-and hash #x3ffffff))
      (define chain (hash-ref chains lo26 (lambda () 0)))
      (when (>= chain 512)
        (error 'convert-db-folder "intern collision chain overflow (512) at hash ~a" lo26))
      (hash-set! chains lo26 (add1 chain))
      (bitwise-ior (arithmetic-shift chain 26) lo26))

    ;; strings are interned into a separate table, in write order
    (define (intern-string s)
      (unless (hash-has-key? string-to-value s)
        (define bs (string->bytes/utf-8 s))
        ;; > SEQ_BLEAF_MAX bytes is a tag-4 rope in the sequence arena, not a
        ;; monolithic intern, and this writer cannot build one
        (when (> (bytes-length bs) 256)
          (error 'convert-db-folder
                 "string of ~a bytes exceeds the ~a-byte monolithic-intern limit: ~s"
                 (bytes-length bs) 256 s))
        (when (for/or ([b (in-bytes bs)]) (= b 0))
          (error 'convert-db-folder "value.strings records are NUL-terminated: ~s" s))
        (hash-set! string-to-value s
                   (make-intern-value str-type (intern-id str-chains (fnv32 bs #t))))
        (write-bytes (bytes-append bs (bytes 0)) strings-file))
      (hash-ref string-to-value s))

    ;; An int outside [-2^31, 2^31) is an interned GMP bignum, never an s32
    ;; word (docs/primitives.md §14: the int TYPE spans both representations
    ;; and every producer has to normalize the same way).  A value.mpz record
    ;; is a u32 length then the canonical body mpz_val::write_bytes emits: a
    ;; sign byte followed by LSB-first magnitude bytes.
    (define (intern-mpz n)
      (unless (hash-has-key? mpz-to-value n)
        (define mag (abs n))
        (define nbytes (max 1 (quotient (+ (integer-length mag) 7) 8)))
        (define body
          (bytes-append (bytes (if (negative? n) 1 0))
                        (apply bytes
                               (for/list ([i (in-range nbytes)])
                                 (bitwise-and (arithmetic-shift mag (* -8 i)) 255)))))
        (unless mpz-file
          (make-directory (format "~a/value.mpz/" staging))
          (set! mpz-file (open-output-file (format "~a/value.mpz/0.bin" staging))))
        (hash-set! mpz-to-value n
                   (make-intern-value mpz-type (intern-id mpz-chains (fnv32 body #f))))
        (write-bytes (int->bytes (bytes-length body) 4) mpz-file)
        (write-bytes body mpz-file))
      (hash-ref mpz-to-value n))

    ;; A name no `table`/`struct` declaration can carry is a database nothing
    ;; can query, so refuse it here instead of at the first query.  Kept in
    ;; step with modules.rkt's check-not-reserved! by a unit test rather than
    ;; by requiring the middle end from this build utility.
    (define (check-import-name! name what)
      (unless (regexp-match? #px"^[A-Za-z_][A-Za-z0-9_']*$" name)
        (error 'convert-db-folder "~s is not a usable ~a name" name what))
      (when (member name '("list" "cons" "nil"          ; native sequence syntax
                           "cset" "cmap" "coll" "cseq"  ; collection base types
                           "error" "error_spec" "malformed_deduction" "div_by_zero"
                           "modulo_by_zero" "int_overflow" "nan_result" "toint_range"
                           "type_mismatch" "mpz_overflow" "mpz_table_overflow"
                           "smt_bad_formula"))
        (error 'convert-db-folder
               "~a is a reserved name (modules.rkt check-not-reserved!) and cannot be a ~a"
               name what)))

    ;; ---- observed column types, for the declarations to print at the end --

    (define (type-name v)
      (cond [(string? v) "str"]
            [(and (number? v) (inexact? v)) "float"]
            [(exact-integer? v) "int"]
            [(pair? v) (symbol->string (car v))]
            [else "?"]))

    (define (note-types! table name arity vals)
      (define seen (hash-ref! table name (lambda () (build-vector arity (lambda (_) (mutable-set))))))
      (for ([v (in-list vals)] [i (in-naturals)])
        (set-add! (vector-ref seen i) (type-name v))))

    (define mixed-columns '())   ; (name column types) worth warning about
    (define (column-decl name seen)
      (string-join
       (for/list ([s (in-vector seen)] [i (in-naturals)])
         ;; sorted list, not the set itself: `seen` holds mutable sets and
         ;; equal? never says one of those is an immutable set
         (define kinds (sort (set->list s) string<?))
         (cond [(= 1 (length kinds)) (first kinds)]
               ;; an int column with one decimal in it is a float column
               [(equal? kinds '("float" "int")) "float"]
               [else (set! mixed-columns (cons (list name i kinds) mixed-columns))
                     "any"]))
       " "))

    ;; ---- tuple words -----------------------------------------------------

    (define (write-val v)
      (match v
        [(? bytes?) v]
        ;; Strings are interned; a bare word in a data file is one too
        [(? string?) (intern-string v)]
        [(? symbol?) (intern-string (symbol->string v))]
        ;; Floating points are stored as their little-endian binary64 encoding.
        ;; The NaN box reuses the IEEE NaN space, so a non-finite float is not
        ;; a value the daemon can hold: NaN is unrepresentable outright, and
        ;; -inf.0 satisfies is_struct as well as is_float (types.h).
        [(and (? number?) (? inexact?))
         (unless (rational? v)
           (error 'convert-db-folder "~a is not a representable float" v))
         (real->floating-point-bytes v 8 #f)]
        [(? exact-integer?)
         #:when (and (>= v (- (expt 2 31))) (< v (expt 2 31)))
         ;; 0 11111111111 0 1 ... [SIGNED INT] ...
         ;; mask first: bitwise-ior on a negative would sign-extend over the tag
         (make-prim-value s32-type (bitwise-and v #xffffffff))]
        [(? exact-integer?) (intern-mpz v)]
        ;; A NULLARY constructor -- (nil), (on), a union's terminator -- is not
        ;; a zero-field struct.  modules.rkt turns one into an `enum` member,
        ;; and the runtime holds every member of every enum as one shared
        ;; `_enum` struct whose single field is the member name's string.  An
        ;; arity-1 struct directory is not even loadable ("Malformed relation
        ;; directory name"), so this is the only shape that works.
        [`(,membername)
         #:when (symbol? membername)
         (set-add! enum-members (symbol->string membername))
         (unless (hash-has-key? out-files "_enum")
           (define struct-id (alloc-struct-id))
           (define out-folder
             (format "~a/struct._enum.arity.2.id.~a/" staging struct-id))
           (make-directory out-folder)
           (hash-set! out-files "_enum"
                      `(struct 1 ,struct-id
                               ,(open-output-file (string-append out-folder "0.bin")))))
         (match-define `(struct ,_ ,struct-id ,_port) (hash-ref out-files "_enum"))
         (unless (hash-has-key? struct-map v)
           (hash-set! struct-map v (alloc "_enum"))
           (emit-tuple "_enum"
                       (list (make-struct-value struct-id (hash-ref struct-map v))
                             (symbol->string membername))))
         (make-struct-value struct-id (hash-ref struct-map v))]
        [`(,structname ,vals ...)
         #:when (symbol? structname)
         (match (hash-ref out-files (symbol->string structname) (lambda () #f))
           [`(struct ,arity ,struct-id ,port)
            (unless (= arity (length vals))
              (error 'convert-db-folder
                     "struct ~a appears with ~a fields and also with ~a"
                     structname arity (length vals)))
            ;; content-to-id is a function: repeated content is one instance
            ;; with one row, so the same value in ten places is one id
            (unless (hash-has-key? struct-map v)
              (hash-set! struct-map v (alloc structname))
              (emit-tuple (symbol->string structname)
                          `(,(make-struct-value struct-id (hash-ref struct-map v)) ,@vals)))
            (make-struct-value struct-id (hash-ref struct-map v))]
           [`(rel ,arity ,port)
            (error 'convert-db-folder
                   "~a is both a relation file and a struct constructor" structname)]
           [_
            (check-import-name! (symbol->string structname) "struct constructor")
            (unless (<= 1 (add1 (length vals)) 32)
              (error 'convert-db-folder "struct ~a has ~a fields; the limit is 31"
                     structname (length vals)))
            (define struct-id (alloc-struct-id))
            (define out-folder
              (format "~a/struct.~a.arity.~a.id.~a/"
                      staging
                      structname
                      (add1 (length vals))
                      struct-id))
            (make-directory out-folder)
            (hash-set! out-files
                       (symbol->string structname)
                       `(struct ,(length vals) ,struct-id
                                ,(open-output-file (string-append out-folder "0.bin"))))
            (write-val v)])]
        [_ (error 'convert-db-folder "cannot write a column of this type: ~s" v)]))

    (define (emit-tuple relname tuple)
      (hash-update! row-counts relname add1 0)
      (match (hash-ref out-files relname)
        [`(rel ,arity ,port)
         #:when (= arity (length tuple))
         (note-types! col-types relname arity tuple)
         (write-bytes (apply bytes-append (map write-val tuple)) port)]
        [`(struct ,arity ,struct-id ,port)
         #:when (= (add1 arity) (length tuple))
         (note-types! struct-fields relname arity (cdr tuple))
         (write-bytes (apply bytes-append (map write-val tuple)) port)]))

    ;; ---- rows ------------------------------------------------------------

    (define (delimiter? c)
      (if delimiter
          (char=? c delimiter)
          (or (char=? c #\space) (char=? c #\tab) (char=? c #\return))))

    ;; A column is a "quoted string" (backslash escapes; may contain the
    ;; delimiter), a balanced ( s-expression ) -- which may itself contain
    ;; quoted strings and nested parens -- or a run of ordinary characters.
    (define (tokenize-row line* where)
      ;; a UTF-8 BOM would otherwise ride along inside the first column
      (define line (if (and (> (string-length line*) 0) (char=? (string-ref line* 0) #\uFEFF))
                       (substring line* 1)
                       line*))
      (define n (string-length line))
      (define (scan-quoted i)      ; line[i] is #\"; returns the index past it
        (let loop ([j (add1 i)])
          (cond [(>= j n) (error 'convert-db-folder "~a: unterminated string" where)]
                [(char=? (string-ref line j) #\\) (loop (+ j 2))]
                [(char=? (string-ref line j) #\") (add1 j)]
                [else (loop (add1 j))])))
      (define (scan-sexp i)        ; line[i] is #\(; returns the index past it
        (let loop ([j i] [depth 0])
          (if (>= j n)
              (error 'convert-db-folder "~a: unbalanced parentheses" where)
              (let ([c (string-ref line j)])
                (cond [(char=? c #\") (loop (scan-quoted j) depth)]
                      [(char=? c #\() (loop (add1 j) (add1 depth))]
                      [(char=? c #\)) (if (= depth 1) (add1 j) (loop (add1 j) (sub1 depth)))]
                      [else (loop (add1 j) depth)])))))
      (define (scan-token i)
        (define c (string-ref line i))
        (cond [(char=? c #\") (scan-quoted i)]
              [(char=? c #\() (scan-sexp i)]
              [else (let loop ([j i])
                      (cond [(>= j n) j]
                            [(delimiter? (string-ref line j)) j]
                            [else (loop (add1 j))]))]))
      (if delimiter
          ;; one field per delimiter, so an empty field is a real empty column
          (let loop ([i 0] [start 0] [acc '()])
            (cond [(>= i n) (reverse (cons (string-trim (substring line start i)) acc))]
                  [(char=? (string-ref line i) #\") (loop (scan-quoted i) start acc)]
                  [(char=? (string-ref line i) #\() (loop (scan-sexp i) start acc)]
                  [(delimiter? (string-ref line i))
                   (loop (add1 i) (add1 i) (cons (string-trim (substring line start i)) acc))]
                  [else (loop (add1 i) start acc)]))
          ;; runs of whitespace separate columns and cannot make an empty one
          (let loop ([i 0] [acc '()])
            (cond [(>= i n) (reverse acc)]
                  [(delimiter? (string-ref line i)) (loop (add1 i) acc)]
                  [else (define e (scan-token i))
                        (loop e (cons (substring line i e) acc))]))))

    (define int-rx #px"^[+-]?[0-9]+$")
    (define float-rx #px"^[+-]?(?:[0-9]+\\.[0-9]*|\\.[0-9]+|[0-9]+)(?:[eE][+-]?[0-9]+)?$")

    (define (unescape body)
      (regexp-replace* #px"\\\\(.)" body
                       (lambda (_ c) (case c [("n") "\n"] [("t") "\t"] [else c]))))

    (define (token->value t where)
      (cond
        [(and (> (string-length t) 1) (char=? (string-ref t 0) #\"))
         (unescape (substring t 1 (sub1 (string-length t))))]
        [(and (> (string-length t) 0) (char=? (string-ref t 0) #\())
         (define v (with-handlers ([exn:fail? (lambda (e)
                                                (error 'convert-db-folder
                                                       "~a: cannot read the column ~a" where t))])
                     (read (open-input-string t))))
         (unless (and (pair? v) (symbol? (car v)))
           (error 'convert-db-folder "~a: ~a is not a (constructor field ...) column" where t))
         v]
        [(regexp-match? int-rx t) (string->number t 10)]
        [(regexp-match? float-rx t) (exact->inexact (string->number t 10))]
        [else t]))

    ;; A schema line pins what the columns are instead of leaving it to what
    ;; the first row happens to look like -- "01234" is a str, not 1234.
    (define type-names '("int" "float" "str" "any"))
    (define (schema-line? toks)
      (and (pair? toks) (andmap (lambda (t) (member t type-names)) toks)))

    (define (coerce ty t v where)
      (case ty
        [("any") v]
        [("str") (cond [(string? v) v]
                       [(pair? v) (error 'convert-db-folder
                                         "~a: a struct column cannot be a str" where)]
                       [else t])]   ; the raw text, so "007" stays "007"
        [("int") (unless (exact-integer? v)
                   (error 'convert-db-folder "~a: ~a is not an int" where t))
                 v]
        [("float") (cond [(and (number? v) (inexact? v)) v]
                         [(exact-integer? v) (exact->inexact v)]
                         [else (error 'convert-db-folder "~a: ~a is not a float" where t)])]))

    ;; ---- input files -----------------------------------------------------

    ;; Read a possibly-gzipped text file as lines.
    (define (call-with-input-lines file proc)
      (if (regexp-match? #px"\\.gz$" file)
          (let-values ([(pin pout) (make-pipe)])
            (define t (thread (lambda ()
                               (call-with-input-file file (lambda (in) (gunzip-through-ports in pout)))
                               (close-output-port pout))))
            (begin0 (proc pin) (thread-wait t) (close-input-port pin)))
          (call-with-input-file file proc)))

    ;; NAME.ARITY.ext or NAME.ext -> (list relname arity-or-#f); #f when the
    ;; name is not an importable data file at all.  A directory carries the
    ;; same naming, and holds shard files.
    (define (parse-input-name filename dir?)
      (define stripped (regexp-replace #px"\\.gz$" filename ""))
      (define m (if dir?
                    (list #f stripped)
                    (regexp-match #px"^(.+)\\.(?:csv|tsv|txt)$" stripped)))
      (and m
           (let* ([stem (second m)]
                  [a (regexp-match #px"^(.+)\\.([0-9]+)$" stem)])
             (if a
                 (list (second a) (string->number (third a)))
                 (list stem #f)))))

    ;; The first row that is neither blank nor a comment settles the arity; a
    ;; schema comment settles it too, and takes precedence.
    (define (probe-shape file)
      (call-with-input-lines file
        (lambda (in)
          (let loop ([schema #f])
            (define line (read-line in))
            (cond
              [(eof-object? line) (list schema (and schema (length schema)))]
              [(regexp-match? #px"^\\s*#" line)
               (define toks (tokenize-row (regexp-replace #px"^\\s*#" line "") file))
               (if (and (not schema) (schema-line? toks)) (loop toks) (loop schema))]
              [else
               (define toks (tokenize-row line file))
               (cond [(null? toks) (loop schema)]
                     [schema (list schema (length schema))]
                     [else (list #f (length toks))])])))))

    (define (import-tokenized file relname arity schema)
      (call-with-input-lines file
        (lambda (in)
          (let loop ([lineno 1] [dropped 0])
            (define line (read-line in))
            (unless (eof-object? line)
              (define where (format "~a:~a" file lineno))
              (cond
                [(regexp-match? #px"^\\s*#" line) (loop (add1 lineno) dropped)]
                [else
                 (define toks (tokenize-row line where))
                 (cond
                   [(null? toks) (loop (add1 lineno) dropped)]
                   [(< dropped skip-rows) (loop (add1 lineno) (add1 dropped))]
                   [(= (length toks) arity)
                    (emit-tuple relname
                                (for/list ([t (in-list toks)] [i (in-naturals)])
                                  (define v (token->value t where))
                                  (if schema (coerce (list-ref schema i) t v where) v)))
                    (loop (add1 lineno) dropped)]
                   [else
                    (error 'convert-db-folder
                           "~a: ~a columns, expected arity ~a"
                           where (length toks) arity)])]))))))

    ;; Legacy tokenizer: values are Racket data, a value may span lines, and
    ;; tuple boundaries come from the arity alone.
    (define (import-read file relname arity)
      (call-with-input-lines file
        (lambda (in)
          (let loop ()
            (define tup (for/list ([_ (in-range arity)]) (read in)))
            (unless (ormap eof-object? tup)
              (emit-tuple relname tup)
              (loop))))))

    ;; ---- the work list ---------------------------------------------------

    ;; String and mpz ids depend on interning order, so walk the folder in a
    ;; stable order rather than directory-list's unspecified one.
    (define entries (sort (map path->string (directory-list path)) string<?))

    (define work
      (for*/list ([entry (in-list entries)]
                  [full (in-value (build-path path entry))]
                  [dir? (in-value (directory-exists? full))]
                  [parsed (in-value (parse-input-name entry dir?))]
                  #:when (cond
                           [parsed #t]
                           [else (eprintf "skipping ~a (not a .csv/.tsv/.txt file)\n" entry) #f]))
        (define shards
          (if dir?
              (for/list ([f (in-list (sort (map path->string (directory-list full)) string<?))]
                         #:when (regexp-match? #px"\\.(csv|tsv|txt)(\\.gz)?$" f))
                (path->string (build-path full f)))
              (list (path->string full))))
        (list (first parsed) (second parsed) shards)))

    (define (close-all!)
      (for ([entry (in-list (hash-values out-files))])
        (match entry
          [`(rel ,arity ,port) (close-output-port port)]
          [`(struct ,arity ,struct-id ,port) (close-output-port port)]))
      (close-output-port strings-file)
      (when mpz-file (close-output-port mpz-file)))

    (define (import-one-relation job)
      (define relname (first job))
      (define named-arity (second job))
      (define shards (third job))
      (check-import-name! relname "relation")
      (when (hash-has-key? out-files relname)
        (error 'convert-db-folder
               "the name ~a is already taken, by another input or by a struct constructor"
               relname))
      (cond
        [(null? shards) (eprintf "skipping ~a (no shard files)\n" relname)]
        [else
         (define probed (and (not read-values?) (probe-shape (first shards))))
         (define schema (and probed (first probed)))
         (define arity (or named-arity (and probed (second probed))))
         (when (and named-arity schema (not (= named-arity (length schema))))
           (error 'convert-db-folder
                  "~a: the name says arity ~a but the schema line has ~a columns"
                  (first shards) named-arity (length schema)))
         (cond
           [(not arity)
            ;; an empty file has no first row to measure, and `read` mode has
            ;; no row boundaries at all, so both need the arity in the name
            (eprintf "skipping ~a (no rows to infer arity from; name it ~a.ARITY.csv)\n"
                     relname relname)]
           [else
            ;; the daemon can only load arities 1..32 (and arity 0 would loop
            ;; forever below reading zero-length tuples)
            (unless (<= 1 arity 32)
              (error 'convert-db-folder
                     "~a: arity ~a out of the loadable range 1..32" relname arity))
            (define outfolder (format "~a/table.~a.arity.~a/" staging relname arity))
            (make-directory outfolder)
            (hash-set! rel-shape relname (list arity schema))
            (for ([shard (in-list shards)] [i (in-naturals)])
              (define port (open-output-file (format "~a~a.bin" outfolder i)))
              (hash-set! out-files relname `(rel ,arity ,port))
              (if read-values?
                  (import-read shard relname arity)
                  (import-tokenized shard relname arity
                                    (if (= i 0) schema (first (probe-shape shard)))))
              (close-output-port port))])]))

    (with-handlers ([(lambda (_) #t)
                     (lambda (e) (close-all!) (delete-folder staging) (raise e))])
      (for-each import-one-relation work))

    (close-all!)
    (delete-folder (format "data/~a" dbname))
    (rename-file-or-directory staging (format "data/~a" dbname))

    ;; What a query over this database has to declare.  A column type that
    ;; disagrees with the stored rows is rejected at load rather than
    ;; reinterpreted, so print what was actually written.
    (define (pad s w) (string-append s (make-string (max 1 (- w (string-length s))) #\space)))
    ;; a nullary constructor declares as (nil), not (nil )
    (define (decl kind name cols)
      (if (string=? cols "") (format "~a (~a)" kind name) (format "~a (~a ~a)" kind name cols)))
    (printf "data/~a\n" dbname)
    (for ([name (in-list (sort (hash-keys struct-fields) string<?))]
          ;; _enum is the runtime's shared carrier for enum members, never
          ;; something a program declares; report the members instead
          #:unless (string=? name "_enum"))
      (printf "  ~a~a values\n"
              (pad (decl "struct" name (column-decl name (hash-ref struct-fields name))) 44)
              (hash-ref row-counts name 0)))
    (unless (set-empty? enum-members)
      (printf "  ~a~a values\n"
              (pad (format "nullary members: ~a"
                           (string-join (for/list ([m (sort (set->list enum-members) string<?)])
                                          (format "(~a)" m))
                                        " "))
                   44)
              (hash-ref row-counts "_enum" 0)))
    (for ([name (in-list (sort (hash-keys rel-shape) string<?))])
      (define shape (hash-ref rel-shape name))
      ;; what the rows say, else what a schema line said, else nothing to go on
      (define cols
        (cond [(hash-ref col-types name #f) => (lambda (seen) (column-decl name seen))]
              [(second shape) (string-join (second shape) " ")]
              [else (string-join (for/list ([_ (in-range (first shape))]) "any") " ")]))
      (printf "  ~a~a rows\n"
              (pad (decl "table" name cols) 44)
              (hash-ref row-counts name 0)))
    (printf "  ~a interned strings, ~a interned bignums\n"
            (hash-count string-to-value) (hash-count mpz-to-value))
    ;; A column of two primitive kinds is nearly always a delimiter or schema
    ;; mistake.  A column of several CONSTRUCTORS is not a mistake at all --
    ;; that is what a union type is for -- so say so rather than crying `any`.
    (for ([m (in-list (reverse mixed-columns))])
      (define constructors?
        (andmap (lambda (k) (not (member k '("int" "float" "str")))) (third m)))
      (eprintf "warning: ~a column ~a holds ~a; declare it ~a\n"
               (first m) (add1 (second m)) (string-join (third m) " and ")
               (if constructors? "as a union type" "any, or fix the input")))
    (void)))

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

;; The freezer (daemon/freeze.cpp): renders a fact stream to a static .bin
;; database.  Built on demand through make (which no-ops when fresh -- the
;; target depends on freeze.cpp + every daemon header).
(define (ensure-slog-freeze-exists)
  (make-directory* (fullpath "build"))
  (define log-path (fullpath "build/freeze-build.log"))
  (define logport (open-output-file log-path #:exists 'replace))
  (define-values (sp out in err)
    (subprocess logport #f logport (find-executable-path "make")
                "-C" "daemon" "slog-freeze"))
  (close-output-port in)
  (subprocess-wait sp)
  (close-output-port logport)
  (when (> (subprocess-status sp) 0)
    (error (format "Something went wrong compiling slog-freeze!\n~a"
                   (file->string log-path)))))

;; Run the freezer: stream (a string) on stdin, database written to dir
;; (tmp+rename inside, so a crashed freeze never leaves a partial db under
;; a content-addressed name).  The freezer prints one summary line at exit,
;; after consuming all of stdin, so writing the whole stream first cannot
;; deadlock.
(define (run-freezer dir stream)
  (ensure-slog-freeze-exists)
  (define-values (sp out in err)
    (subprocess #f #f #f (fullpath "daemon/slog-freeze") dir))
  (display stream in)
  (close-output-port in)
  (define outs (port->string out))
  (define errs (port->string err))
  (close-input-port out)
  (close-input-port err)
  (subprocess-wait sp)
  (unless (zero? (subprocess-status sp))
    (error (format "slog-freeze failed for ~a:\n~a~a" dir outs errs))))

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
       (list (format "-I~a/include" brew-prefix) (format "-L~a/lib" brew-prefix) "-lz" "-lgmp")]
      [else (list "-lz" "-lgmp")])))

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
;; -fbracket-depth: emitted read phases nest one brace scope per join, so a
;; staged ground tree's biggest stage nests O(level width) deep -- clang's
;; default cap is 256, hit by a few hundred nodes per level.
(define (base-cxx-flags opt)
  (append (list "-std=c++20" "-fPIC" "-Idaemon" "-fopenmp" "-ffp-contract=off"
                "-ferror-limit=1" "-fbracket-depth=4096" opt)
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

;; ---- compiling .cpp TU(s) into one .so, via a content-addressed .o cache ----
;; Each TU .cpp is compiled to a .o cached in build/o/ keyed by its
;; comment-stripped content + opt + daemon-header fingerprint (docs/fast-compile.md
;; P2); the .o's are then linked into the .so.  An unchanged cluster's .o is
;; reused across stratum versions / configs / edits, so an edit recompiles only
;; the clusters that actually changed and relinks (cheap).  emit-cpp names each
;; cluster function by its content hash, so identical clusters produce identical
;; .cpp content -> identical .o key -> a hit even across different strata.
;;
;; Reads a per-build log DEFENSIVELY (docs/build-issues-notes.md §4): a concurrent
;; job can unlink the tempfile, and on failure we still surface the exit status +
;; the exact command so a build failure is never a mystery.
(define (read-build-log log-path ok? status argv)
  (define raw
    (if (file-exists? log-path)
        (with-handlers ([exn:fail? (lambda (e)
                                     (format "<build log ~a unreadable: ~a>"
                                             log-path (exn-message e)))])
          (file->string log-path))
        ""))
  (if ok?
      raw
      (string-append
       (if (string=? (string-trim raw) "")
           (format "<no compiler output captured at ~a -- the log was missing or empty (most likely a build/ tempfile race); the clang command still ran and failed>\n"
                   log-path)
           raw)
       (format "\n[c++ exited with status ~a]\n[command: ~a]\n"
               status (string-join (map ~a argv) " ")))))   ; argv may hold path objects

;; Run one clang invocation `argv` producing `dest` (a temp), redirecting output
;; to a per-run log; atomically rename temp->dest on success.  Returns (values
;; ok? log).  `tmp-template` and `dest` are threaded so both .o and .so builds
;; share this.
(define (run-cxx argv tmp dest)
  (define log-path (string-append tmp ".log"))
  (define logport (open-output-file log-path #:exists 'replace))
  (define-values (sp out in err) (apply subprocess logport #f logport argv))
  (close-output-port in)
  (subprocess-wait sp)
  (close-output-port logport)
  (define status (subprocess-status sp))
  (define ok? (= 0 status))
  (define log (read-build-log log-path ok? status argv))
  (cond
    [ok?  (delete-file* log-path) (rename-file-or-directory tmp dest #t)]
    [else (delete-file* tmp)])   ; keep the log on failure for inspection
  (values ok? log))

;; ---- build/o content-addressed .o cache: GC (docs/fast-compile.md §14) --------
;; Evict on BOTH age and a size cap, once per process (lazy).  Entries are
;; touched on a cache hit, so mtime is last-use; content-addressing makes an
;; evicted .o inert (recompiled only if needed again).  Knobs come from the
;; config system (SLOG_O_CACHE_MAX_AGE_DAYS default 4, SLOG_O_CACHE_MAX_MB 768).
(define (env-num name default)
  (let* ([v (getenv name)] [n (and v (string->number (string-trim v)))])
    (if (and n (real? n) (>= n 0)) n default)))
(define o-cache-gc-done (box #f))
(define (gc-o-cache!)
  (unless (unbox o-cache-gc-done)
    (set-box! o-cache-gc-done #t)
    (define dir (fullpath "build/o"))
    (when (directory-exists? dir)
      (with-handlers ([exn:fail? void])           ; GC is best-effort
        (define max-age (* 86400 (env-num "SLOG_O_CACHE_MAX_AGE_DAYS" 4)))
        (define max-bytes (* 1024 1024 (env-num "SLOG_O_CACHE_MAX_MB" 768)))
        (define now (current-seconds))
        (define entries               ; (path mtime size), only .o files
          (for/list ([f (in-list (directory-list dir))]
                     #:when (regexp-match? #rx"\\.o$" (path->string f)))
            (define p (build-path dir f))
            (list p (file-or-directory-modify-seconds p) (file-size p))))
        ;; 1. age: drop anything unused longer than the window
        (define live
          (for/list ([e (in-list entries)])
            (cond [(> (- now (second e)) max-age) (delete-file* (first e)) #f]
                  [else e])))
        (define kept (filter values live))
        ;; 2. size cap: evict oldest (by mtime) until under the byte cap
        (when (> (for/sum ([e (in-list kept)]) (third e)) max-bytes)
          (let loop ([sorted (sort kept < #:key second)]
                     [t (for/sum ([e (in-list kept)]) (third e))])
            (when (and (> t max-bytes) (pair? sorted))
              (delete-file* (first (car sorted)))
              (loop (cdr sorted) (- t (third (car sorted)))))))))))

;; Content-addressed cache key for one TU's .o: its comment-stripped source (the
;; crule debug comments are non-reproducible but do not affect the object) plus
;; the opt level, daemon-header fingerprint, and -g flag.
(define (o-cache-key cpp opt)
  (define content (file->string cpp))
  (define stripped (regexp-replace* #px"(?m:^[ \t]*//[^\n]*\n)" content ""))
  (substring (bytes->hex-string
              (sha256 (string->bytes/utf-8
                       (format "~a\0~a\0~a\0~a" stripped opt daemon-fp8
                               (if (debug-build?) "g" "")))))
             0 32))

;; The content-addressed .o path for `cpp` at `opt` (whether or not it exists).
;; The granular O0->O2 upgrade (compile.rkt/runslog.rkt) uses this to find which
;; clusters' -O2 objects have landed and relink a best-available mix.
(define (o-cache-path cpp opt)
  (fullpath (format "build/o/~a.o" (o-cache-key cpp opt))))

;; Link a set of .o's into one .so (temp + atomic rename).  Returns (values ok?
;; log).  Used by compile-one and by the granular relink.
(define (link-os o-paths so-path opt)
  (define tmp (build-tempfile "so~a.tmp"))
  (define argv (append (list the-cxx-path)
                       (base-cxx-flags opt)
                       o-paths
                       (list "-shared" (format "-o~a" tmp))
                       extra-cxx-flags))
  (clang-bump! clang-links)
  (run-cxx argv tmp so-path))

;; Ensure build/o/<key>.o exists for `cpp` at `opt`; compile on a cache miss.
;; Returns (list o-path ok? log); o-path is #f on a compile failure.
(define (build-o cpp opt pch)
  (make-directory* (fullpath "build/o"))
  (gc-o-cache!)
  (define o-path (fullpath (format "build/o/~a.o" (o-cache-key cpp opt))))
  (cond
    [(file-exists? o-path)                                 ; cache hit: no clang
     (with-handlers ([exn:fail? void])                     ; touch: mtime = last use
       (file-or-directory-modify-seconds o-path (current-seconds)))
     (list o-path #t "")]
    [else
     (define tmp (build-tempfile "o~a.o.tmp"))
     (define argv (append (list the-cxx-path)
                          (base-cxx-flags opt)
                          (if pch (list "-include-pch" pch) '())
                          (list "-c" cpp (format "-o~a" tmp))))
     (clang-bump! clang-compiles)
     (define-values (ok? log) (run-cxx argv tmp o-path))
     (list (and ok? o-path) ok? log)]))

;; Compile every TU .cpp to a cached .o, then link the .o's into so-path.
;; Returns (values success? log-string).
(define (compile-one cpp-paths so-path opt pch)
  (unless the-cxx-path
    (error "For reasons unknown, no C++ compiler has been found in PATH."))
  (define cpps (if (list? cpp-paths) cpp-paths (list cpp-paths)))
  (define results (map (lambda (cpp) (build-o cpp opt pch)) cpps))
  (define failed (findf (lambda (r) (not (second r))) results))
  (cond
    [failed (values #f (third failed))]   ; a TU failed to compile
    [else
     (link-os (map first results) so-path opt)]))   ; o-paths are strings (fullpath)

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
;; Eager clang builds run concurrently, capped by the core-budget arbiter so
;; a program's strata compile in parallel instead of one-at-a-time.
;; pooled-eager enqueues the work and returns a thunk that blocks until it is
;; done (re-raising any error), so the driver can force stratum k's build in
;; pipeline order while k+1.. build behind it.
;;
;; T3b slice 4 (execution-tiers §5.5): ONE core budget for the compile side,
;; and the pool is a PRIORITY queue.
;;
;;   compiler pool (eager -O0)   max(floor(P/2) - 1, 1)
;;   detached -O2 batch          max(ceil(pool/2), 1), nice -n 10
;;
;; Before this, the pool defaulted to P and the O2 batch to P/2 ON TOP of the
;; daemon's P-1 workers -- ~2.5P of hard demand on a P-core machine.  The
;; daemon's own -t deliberately stays P-1 (slog-thread-count above): it is
;; launch-static, and halving it would tax every warm native fixpoint to
;; relieve contention that only exists while cold builds are in flight; the
;; fully daemon-owned dynamic budget waits for daemon-side resizing
;; (t3b-contract §3 slice 4 residues).  SLOG_CORES overrides the detected
;; count (tests, CI); SLOG_BUILD_JOBS still pins the pool directly and wins,
;; as it always has.  Both resolve lazily on first build so the slog config
;; system (which sets env after module load) is honored.
;;
;; Queue order is §5.5's strict priority: jobs carry a priority -- 1 = the
;; currently executing SCC (promotions and boosts), 2 = future SCCs -- and a
;; label (the stratum hash); `pool-boost!` raises a pending labeled job to
;; priority 1, called by the drivers just before blocking on a stratum's
;; runnable.  Within a priority, submission (pipeline) order holds.  Detached
;; -O2 work never enters this queue: it rides its own nice'd batch sized by
;; the same arbiter, so "every O2 last" is enforced by OS priority and budget
;; share rather than queue position.
(define (core-count)
  (let* ([env (getenv "SLOG_CORES")]
         [n (and env (string->number (string-trim env)))])
    (if (and n (exact-integer? n) (>= n 1)) n (processor-count))))

;; (values compile-pool-jobs o2-batch-jobs), each >= 1.
(define (core-budget [p (core-count)])
  (define pool
    (let* ([env (getenv "SLOG_BUILD_JOBS")]
           [n (and env (string->number (string-trim env)))])
      (if (and n (exact-integer? n) (>= n 1))
          n
          (max 1 (sub1 (quotient p 2))))))
  (values pool (max 1 (quotient (add1 pool) 2))))

(define (build-parallelism)
  (let-values ([(pool _o2) (core-budget)]) pool))

(struct pool-job (prio-box seq label thunk result err done) #:transparent)

(define pool-queue (box '()))             ; pending pool-jobs, unordered
(define pool-lock (make-semaphore 1))
(define pool-pending (make-semaphore 0))  ; counts pending jobs
(define pool-seq (box 0))
(define pool-workers-started (box #f))

;; clang accounting (§5.4's "track this as a measured metric"): compiles,
;; links, and the detached -O2 claims this run caused.  Bumped in build-o /
;; link-os / try-claim-o2!; the batch driver reports the triple at run end.
(define clang-compiles (box 0))
(define clang-links (box 0))
(define clang-o2-claims (box 0))
(define (clang-bump! b)
  (call-with-semaphore pool-lock (lambda () (set-box! b (add1 (unbox b))))))
(define (clang-report)
  (values (unbox clang-compiles) (unbox clang-links) (unbox clang-o2-claims)))

;; Pop the best pending job: lowest priority number, then lowest sequence
;; (pipeline order).  Called after pool-pending was decremented, so at least
;; one job is present.
(define (pool-pop!)
  (call-with-semaphore pool-lock
    (lambda ()
      (define jobs (unbox pool-queue))
      (define best
        (for/fold ([best (car jobs)]) ([j (in-list (cdr jobs))])
          (define bp (unbox (pool-job-prio-box best)))
          (define jp (unbox (pool-job-prio-box j)))
          (if (or (< jp bp)
                  (and (= jp bp) (< (pool-job-seq j) (pool-job-seq best))))
              j best)))
      (set-box! pool-queue (remq best jobs))
      best)))

(define (ensure-pool-workers!)
  (unless (unbox pool-workers-started)
    (call-with-semaphore pool-lock
      (lambda ()
        (unless (unbox pool-workers-started)
          (set-box! pool-workers-started #t)
          (for ([_ (in-range (build-parallelism))])
            (thread
             (lambda ()
               (let loop ()
                 (semaphore-wait pool-pending)
                 (define j (pool-pop!))
                 (with-handlers ([(lambda (_) #t)
                                  (lambda (e) (set-box! (pool-job-err j) e))])
                   (set-box! (pool-job-result j) ((pool-job-thunk j))))
                 (semaphore-post (pool-job-done j))
                 (loop))))))))))

(define (pooled-eager thunk #:label [label #f] #:priority [prio 2])
  (define j (pool-job (box prio)
                      (call-with-semaphore pool-lock
                        (lambda ()
                          (set-box! pool-seq (add1 (unbox pool-seq)))
                          (unbox pool-seq)))
                      label thunk (box #f) (box #f) (make-semaphore 0)))
  (call-with-semaphore pool-lock
    (lambda () (set-box! pool-queue (cons j (unbox pool-queue)))))
  (semaphore-post pool-pending)
  (ensure-pool-workers!)
  (lambda ()
    (semaphore-wait (pool-job-done j))
    (semaphore-post (pool-job-done j))   ; re-postable: force may be called again
    (when (unbox (pool-job-err j)) (raise (unbox (pool-job-err j))))
    (unbox (pool-job-result j))))

;; Raise every PENDING job with this label to priority 1 -- the driver is
;; about to block on (or is currently interpreting) that stratum, so its
;; build is the front of §5.5's queue.  A job already running is untouched:
;; the pool cannot preempt clang, only order what has not started.
(define (pool-boost! label)
  (when label
    (call-with-semaphore pool-lock
      (lambda ()
        (for ([j (in-list (unbox pool-queue))]
              #:when (equal? (pool-job-label j) label))
          (set-box! (pool-job-prio-box j) 1))))))

;; Minimal POSIX single-quoting for one shell word (coercing paths to strings).
(define (sh-q x)
  (define s (if (path? x) (path->string x) (format "~a" x)))
  (string-append "'" (regexp-replace* #rx"'" s "'\\\\''") "'"))

;; Atomically (re)write a file: emit to a unique temp in build/ then rename over
;; the target (same-dir rename is atomic on POSIX).  So a concurrent reader --
;; e.g. another `racket compiler/run.rkt` compiling the SAME content-addressed stratum
;; under run-tests.sh -jN -- never sees a half-written .cpp/.cprog/.meta.
(define (call-with-atomic-output path thunk)
  (define tmp (build-tempfile "w~a.tmp"))
  (with-output-to-file tmp #:exists 'replace thunk)
  (rename-file-or-directory tmp path #t))

;; ---- background -O2 claim marker (docs/fast-compile.md §13) -------------
;; Exactly one background -O2 build per stratum hash should run at a time across
;; ALL concurrent/successive `slog` processes -- otherwise two runs that both
;; miss build/<hash>.so each spawn the (expensive) -O2, wasting Nx clang.  A
;; sidecar marker build/<hash>.so.building records "a build is in flight"; it is
;; DELIBERATELY a separate file from the canonical <hash>.so (an empty file at
;; the canonical name would be dlopen'd by the hot swap and satisfy the "-O2
;; cached" cache branch -- both crashes).
(define (o2-marker-path so-path) (string-append so-path ".building"))

;; Seconds before an in-flight build's marker is presumed abandoned by a dead
;; builder (crash / kill / reboot) and reclaimed -- and the per-build timeout.
;; From the config system (SLOG_O2_RECLAIM_SECS), default 15 min.
(define (o2-reclaim-seconds)
  (let* ([env (getenv "SLOG_O2_RECLAIM_SECS")]
         [n (and env (string->number (string-trim env)))])
    (if (and n (real? n) (> n 0)) (inexact->exact (floor n)) 900)))

;; A marker older than the reclaim window (or unreadable) is presumed stale.
(define (o2-marker-stale? marker)
  (with-handlers ([exn:fail? (λ (_) #t)])
    (> (- (current-seconds) (file-or-directory-modify-seconds marker))
       (o2-reclaim-seconds))))

;; Try to claim the right to build so-path's -O2 in the background.  Returns #t
;; iff THIS process now holds the marker (nobody else is building it); #f if a
;; live builder already owns it.  The atomic O_EXCL create (#:exists 'error) is
;; the cross-process mutex; the mtime window reclaims a dead builder's marker.
;; (A residual race on stale reclaim only ever costs a duplicate build, never
;; correctness -- the build itself is temp+rename safe.)
(define (try-claim-o2! so-path)
  (define marker (o2-marker-path so-path))
  (define (create!)
    (with-handlers ([exn:fail:filesystem? (λ (_) #f)])
      (call-with-output-file marker #:exists 'error
        (λ (p) (fprintf p "~a\n" (current-seconds))))
      #t))
  (cond
    [(create!) (clang-bump! clang-o2-claims) #t]
    [(o2-marker-stale? marker)
     (delete-file* marker)
     (let ([claimed? (create!)])
       (when claimed? (clang-bump! clang-o2-claims))
       claimed?)]
    [else #f]))

;; Best-effort marker cleanup, e.g. once <hash>.so is present (the claim is moot).
(define (clear-o2-marker! so-path) (delete-file* (o2-marker-path so-path)))

;; The generated C++ TUs for a stratum hash, read back from build/: the spine
;; build/<hash>.cpp plus any part TUs build/<hash>.pK.cpp (docs/fast-compile.md
;; §6).  Used when a cached -O0 .so lets us skip re-emitting yet we still need
;; the sources to launch the background -O2.  Sorted so the spine leads; empty
;; if none are present (caller falls back to a fresh emit).
(define (stratum-tu-paths proghash)
  (define builddir (fullpath "build"))
  (define rx (regexp (format "^~a(\\.p[0-9]+)?\\.cpp$" (regexp-quote proghash))))
  (sort (for/list ([f (in-list (directory-list builddir))]
                   #:when (regexp-match? rx (path->string f)))
          (path->string (build-path builddir f)))
        string<?))

;; The shell command for one background -O2 build: compile to a unique temp,
;; then atomically rename it onto so-path (so a daemon that has already dlopen'd
;; the -O0 .so at that path never sees a torn file), cleaning the temp AND the
;; claim marker (docs/fast-compile.md §13) either way.  A `timeout` bounds a
;; wedged clang so it cannot hold the claim slot until the marker goes stale.
(define (o2-build-command cpp-paths so-path)
  (define pchp (ensure-pch "-O2"))
  (define cpps (if (list? cpp-paths) cpp-paths (list cpp-paths)))
  (define marker (o2-marker-path so-path))
  (make-directory* (fullpath "build/o"))
  (gc-o-cache!)
  (define so-tmp (build-tempfile "o2~a.tmp"))
  ;; Mirror the eager path's content-addressed .o cache at -O2 (docs/fast-compile
  ;; §14): compile each cluster's -O2 .o only on a cache miss, then link.  So an
  ;; -O2 rebuild after an edit/sweep recompiles only the changed clusters (the
  ;; rest are cache hits shared with prior -O2 builds), and the eager path's
  ;; granular relink (Stage 2) reads these same .o's as they land.
  (define o-paths
    (for/list ([cpp (in-list cpps)])
      (fullpath (format "build/o/~a.o" (o-cache-key cpp "-O2")))))
  (define compile-lines
    (for/list ([cpp (in-list cpps)] [o (in-list o-paths)])
      (define otmp (build-tempfile "o2o~a.o.tmp"))
      (define cargv (append (list the-cxx-path) (base-cxx-flags "-O2")
                            (if pchp (list "-include-pch" pchp) '())
                            (list "-c" cpp (format "-o~a" otmp))))
      (string-append "if [ -f " (sh-q o) " ]; then touch " (sh-q o) "; else "
                     (string-join (map sh-q cargv) " ")
                     " && mv -f " (sh-q otmp) " " (sh-q o) " || exit 1; fi")))
  (define link-argv (append (list the-cxx-path) (base-cxx-flags "-O2") o-paths
                            (list "-shared" (format "-o~a" so-tmp)) extra-cxx-flags))
  (define link-line
    (string-append (string-join (map sh-q link-argv) " ")
                   " && mv -f " (sh-q so-tmp) " " (sh-q so-path)))
  ;; Emit the compile+link sequence to a script file rather than one giant quoted
  ;; command -- avoids nested-quoting hazards and keeps `nice`/`timeout` wrapping
  ;; the whole build.
  (define script (build-tempfile "o2build~a.sh"))
  (call-with-atomic-output script
    (lambda () (for ([l (in-list compile-lines)]) (displayln l)) (displayln link-line)))
  (define to-prefix
    (if (find-executable-path "timeout") (format "timeout ~a " (o2-reclaim-seconds)) ""))
  (string-append "nice -n 10 " to-prefix "bash " (sh-q script)
                 " ; rm -f " (sh-q so-tmp) " " (sh-q marker) " " (sh-q script)))

;; Run all background -O2 builds as ONE detached, bounded-parallel job
;; (docs/fast-compile.md §2/§7/§13).  A per-stratum detached process would let a
;; many-stratum program spawn unbounded concurrent clang -O2's (memory pressure,
;; no cgroup bound); instead a single detached bash driver runs the commands from
;; a jobfile at most (cores/2) at a time.  Launched under `setsid` (when
;; available) so it leads its OWN session -- a terminal SIGHUP when the user
;; closes the window after `slog` returns can no longer take it down, so the -O2
;; builds durably outlive this driver and land in the cache for next time (each
;; is `timeout`-bounded per o2-build-command).
(define (spawn-detached-o2-batch commands)
  (when (pair? commands)
    (define jobfile (build-tempfile "o2jobs~a.sh"))
    (with-output-to-file jobfile #:exists 'replace
      (lambda () (for ([c (in-list commands)]) (displayln c))))
    ;; T3b slice 4: the batch's width comes from the same core budget as the
    ;; eager pool, not from a second uncoordinated sizing.
    (define k (let-values ([(_pool o2) (core-budget)]) o2))
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
    (define setsid-exe (find-executable-path "setsid"))
    (define-values (sp o i e)
      (if setsid-exe
          (subprocess devnull-out devnull-in devnull-out setsid-exe "/bin/bash" "-c" script)
          (subprocess devnull-out devnull-in devnull-out "/bin/bash" "-c" script)))
    (close-output-port devnull-out)
    (close-input-port devnull-in)
    (void)))
