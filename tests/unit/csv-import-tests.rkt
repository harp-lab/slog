#lang racket

;; convert-db-folder (compiler/tools.rkt): delimited text folder -> static
;; binary database under data/<name>/.
;;
;; The importer writes tuple words the daemon never re-encodes, so it is a
;; second implementation of daemon/types.h's NaN boxing and daemon/intern.h's
;; string and bignum id assignment, and it has to know two middle-end facts as
;; well (which names are reserved, and that a nullary constructor is an enum
;; member).  Three parts, then: a guard that everything it mirrors is still
;; what it was, a byte-level check of what it writes, and the rejections.
;; Drift in any of these surfaces at load as a "Dangling string id" fatal or a
;; malformed directory name, a long way from the cause.

(module+ test
  (require rackunit
           racket/runtime-path
           file/gzip
           "../../compiler/tools.rkt")

  (define-runtime-path repo-root "../..")
  (define dbname "csv_import_unit_test")
  (define db (build-path repo-root "data" dbname))

  ;; Import a folder; nothing this test does should print.
  (define (import! dir #:delimiter [delimiter #f] #:skip-rows [skip-rows 0])
    (parameterize ([current-directory repo-root]
                   [current-output-port (open-output-nowhere)]
                   [current-error-port (open-output-nowhere)])
      (convert-db-folder (if (path? dir) (path->string dir) dir) dbname
                         #:delimiter delimiter #:skip-rows skip-rows)))

  ;; Import one bad file and return the error message it raised.  A failed
  ;; import writes only to staging, so there is no database to clean up.
  (define (import-failure! filename contents)
    (define bad (make-temporary-directory))
    (display-to-file contents (build-path bad filename))
    (begin0
      (with-handlers ([exn:fail? exn-message])
        (import! bad)
        "the import unexpectedly succeeded")
      (delete-directory/files bad)))

  ;; ---- the daemon constants convert-db-folder mirrors -----------------

  (define (header-defines path)
    (for*/hash ([line (in-list (file->lines (build-path repo-root path)))]
                [m (in-value (regexp-match #px"^#define\\s+(\\w+)\\s+(.+?)\\s*$" line))]
                #:when m)
      (values (second m) (third m))))

  (define intern.h (header-defines "daemon/intern.h"))
  (define types.h (header-defines "daemon/types.h"))
  (define seqparams.h (header-defines "daemon/seqparams.h"))

  ;; 21 bucket bits + 5 inner-position bits = the 26-bit hash prefix of an
  ;; intern id; the collision-chain index sits above it.
  (check-equal? (hash-ref intern.h "intern_buckets_bits" #f) "21"
                "intern id layout changed: convert-db-folder's 26-bit hash prefix is stale")
  (check-equal? (hash-ref types.h "str_intern_tag" #f) "0")
  (check-equal? (hash-ref types.h "mpz_intern_tag" #f) "1")
  (check-equal? (hash-ref types.h "s32_prim_tag" #f) "1")
  (check-equal? (hash-ref types.h "internflags" #f) "0x7fffffc000000000")
  (check-equal? (hash-ref types.h "NaNflags" #f) "0x7ff0000000000000")
  (check-equal? (hash-ref types.h "structflags" #f) "0xfff0000000000000")
  ;; longer strings are tag-4 ropes, which the importer refuses rather than builds
  (check-equal? (hash-ref seqparams.h "SEQ_BLEAF_MAX" #f) "((u32)256)")

  (define intern-src (file->string (build-path repo-root "daemon/intern.h")))
  (define mpz-src (file->string (build-path repo-root "daemon/mpz.h")))
  ;; both fasthash specializations are FNV-1a with the classic constants ...
  (for ([src (in-list (list intern-src mpz-src))])
    (check-true (and (regexp-match? #px"2166136261u" src)
                     (regexp-match? #px"16777619u" src))
                "a fasthash is no longer FNV-1a with the classic constants"))
  ;; ... but over different bytes: utf8string casts to a SIGNED char, mpz_val
  ;; walks unsigned bytes.  The importer sign-extends for one and not the other.
  (check-true (regexp-match? #px"hash \\^= \\(char\\)cstr\\[i\\]" intern-src)
              "fasthash<utf8string> no longer xors a signed char")
  (check-true (regexp-match? #px"hash \\^= v\\.byte_at\\(i\\)" mpz-src)
              "fasthash<mpz_val> no longer xors an unsigned byte")
  ;; struct instance ids may start at 0 only because a loaded file lifts every
  ;; bucket allocator above the largest id it saw
  (check-true (regexp-match? #px"intern_allocators\\[b\\] = std::max\\(intern_allocators\\[b\\], max_id_seen\\+1\\)"
                             (file->string (build-path repo-root "daemon/database.h")))
              "seedInternAllocators no longer lifts allocators past loaded struct ids")

  ;; ---- the reserved names the importer refuses ------------------------
  ;; modules.rkt check-not-reserved! is the authority; the importer carries its
  ;; own copy so that a build utility need not require the middle end.
  (define check-not-reserved-src
    (let* ([src (file->string (build-path repo-root "compiler/modules.rkt"))]
           [start (regexp-match-positions #px"\\(define \\(check-not-reserved! name\\)" src)])
      (check-true (and start #t) "check-not-reserved! moved or was renamed")
      (substring src (caar start) (+ (caar start) 1200))))
  (define reserved-by-compiler
    (append
     ;; collection-builtin? -- the retired cons list's names
     (let ([m (regexp-match #px"set-member\\? \\(set ((?:'[a-z]+ ?)+)\\)"
                            (file->string (build-path repo-root "compiler/collections.rkt")))])
       (if m (regexp-match* #px"[a-z_][a-z_0-9]*" (second m)) '()))
     ;; the two memq lists inside check-not-reserved! itself
     (append*
      (for/list ([m (in-list (regexp-match* #px"\\(memq name '\\(([^)]*)\\)\\)"
                                            check-not-reserved-src
                                            #:match-select values))])
        (regexp-match* #px"[a-z_][a-z_0-9]*" (second m))))))
  (check-true (>= (length reserved-by-compiler) 15)
              (format "reserved-name scrape found only ~a names" (length reserved-by-compiler)))
  (for ([name (in-list reserved-by-compiler)])
    (check-regexp-match #px"reserved name"
                        (import-failure! (format "~a.csv" name) "1\n")))

  ;; ---- reference encoders (types.h / intern.h, independently spelled) --

  (define (fnv-1a bs #:signed? [signed? #t])
    (for/fold ([h 2166136261]) ([b (in-bytes bs)])
      (bitwise-and (* (bitwise-xor h (if (and signed? (>= b 128)) (+ b #xffffff00) b)) 16777619)
                   #xffffffff)))

  (define (s32-word v) (bitwise-ior #x7ff0000000000000 (arithmetic-shift 1 35)
                                    (bitwise-and v #xffffffff)))
  (define (intern-word tag id)
    (bitwise-ior #x7fffffc000000000 (arithmetic-shift tag 35) id))
  (define (struct-word sid id)
    (bitwise-ior #xfff0000000000000 (arithmetic-shift sid 38) id))
  (define (float-word f) (integer-bytes->integer (real->floating-point-bytes f 8 #f) #f #f))

  (define (words-of . parts)
    (define bs (file->bytes (apply build-path db parts)))
    (for/list ([i (in-range (quotient (bytes-length bs) 8))])
      (integer-bytes->integer bs #f #f (* 8 i) (* 8 (add1 i)))))

  ;; ---- one import of everything ---------------------------------------

  (define src (make-temporary-directory))

  (display-to-file "1 2\n-5\t3\n" (build-path src "edge.csv"))
  ;; a quoted column is a string even when it looks like a number, and may
  ;; hold spaces; a bare word is a string too
  (display-to-file "alice \"bob jones\" \"7\"\n" (build-path src "who.csv"))
  (display-to-file "1 0.5\n2 -1.25e2\n" (build-path src "weight.csv"))
  ;; ints outside [-2^31, 2^31) are interned bignums, not s32 words
  (display-to-file "2147483648\n" (build-path src "huge.csv"))
  ;; s-expression columns, nested, including a nullary constructor
  (display-to-file "(pt 1 2) (seg (pt 1 2) (nil))\n" (build-path src "geom.csv"))
  ;; a schema line settles the types, and settles arity with no rows at all
  (display-to-file "# str int\n01234 7\n" (build-path src "zip.csv"))
  (display-to-file "# str str\n" (build-path src "empty.csv"))
  ;; a subdirectory is one relation's shards, and any input may be gzipped
  (make-directory (build-path src "shard"))
  (display-to-file "1\n2\n" (build-path src "shard" "a.csv"))
  (display-to-file "3\n" (build-path src "shard" "b.csv"))
  (call-with-output-file (build-path src "zipped.csv.gz")
    (lambda (out) (gzip-through-ports (open-input-string "8 9\n") out #f 0)))

  (import! src)

  (check-true (directory-exists? (build-path db "table.edge.arity.2"))
              "arity inferred from the first row")
  (check-true (directory-exists? (build-path db "table.who.arity.3")))
  (check-true (directory-exists? (build-path db "table.empty.arity.2"))
              "a schema line settles arity with no rows to measure")
  (check-true (directory-exists? (build-path db "table.zipped.arity.2"))
              "a .gz input is read like any other")

  ;; ints, including a negative (masking to 32 bits before the tag matters:
  ;; an unmasked negative would sign-extend over the whole word)
  (check-equal? (words-of "table.edge.arity.2" "0.bin")
                (list (s32-word 1) (s32-word 2) (s32-word -5) (s32-word 3)))

  ;; floats are raw little-endian binary64
  (check-equal? (words-of "table.weight.arity.2" "0.bin")
                (list (s32-word 1) (float-word 0.5) (s32-word 2) (float-word -125.0)))

  ;; strings: the id the daemon's interner will recompute on load
  (define (expected-str s [chain 0])
    (intern-word 0 (bitwise-ior (arithmetic-shift chain 26)
                                (bitwise-and (fnv-1a (string->bytes/utf-8 s)) #x3ffffff))))
  (check-equal? (words-of "table.who.arity.3" "0.bin")
                (list (expected-str "alice") (expected-str "bob jones") (expected-str "7")))
  ;; value.strings is NUL-terminated records in id-assignment order, because
  ;; loadStringsBIN re-interns them in exactly that order.  Folders are walked
  ;; sorted, so "nil" (from geom.csv) is interned before who.csv's strings.
  (check-equal? (file->bytes (build-path db "value.strings" "0.bin"))
                (apply bytes-append
                       (for/list ([s (in-list '("nil" "alice" "bob jones" "7" "01234"))])
                         (bytes-append (string->bytes/utf-8 s) (bytes 0)))))

  ;; a schema line beats what the row looks like: "01234" stays a string
  (check-equal? (words-of "table.zip.arity.2" "0.bin")
                (list (expected-str "01234") (s32-word 7)))

  ;; bignums: a u32-length-prefixed record of a sign byte then LSB-first
  ;; magnitude bytes, hashed WITHOUT sign extension
  (define mpz-body (bytes 0 0 0 0 #x80))   ; +2^31
  (check-equal? (file->bytes (build-path db "value.mpz" "0.bin"))
                (bytes-append (integer->integer-bytes 5 4 #f #f) mpz-body))
  (check-equal? (words-of "table.huge.arity.1" "0.bin")
                (list (intern-word 1 (bitwise-and (fnv-1a mpz-body #:signed? #f) #x3ffffff))))

  ;; structs: one directory per constructor, the value word carries the type's
  ;; SID and an instance id numbered from 0, and equal content is one instance
  (check-equal? (words-of "struct.pt.arity.3.id.1" "0.bin")
                (list (struct-word 1 0) (s32-word 1) (s32-word 2))
                "(pt 1 2) appears twice and is one instance with one row")
  (check-equal? (words-of "struct.seg.arity.3.id.2" "0.bin")
                (list (struct-word 2 0) (struct-word 1 0) (struct-word 3 0))
                "a nested struct column holds the inner value's own word")
  (check-equal? (words-of "table.geom.arity.2" "0.bin")
                (list (struct-word 1 0) (struct-word 2 0)))
  ;; a NULLARY constructor is an enum member: one shared _enum struct whose
  ;; single field is the member name.  An arity-1 struct dir cannot be loaded.
  (check-false (directory-exists? (build-path db "struct.nil.arity.1.id.3")))
  (check-equal? (words-of "struct._enum.arity.2.id.3" "0.bin")
                (list (struct-word 3 0) (expected-str "nil")))

  ;; shards: one .bin per input file, all of them read by the loader
  (check-equal? (words-of "table.shard.arity.1" "0.bin")
                (list (s32-word 1) (s32-word 2)))
  (check-equal? (words-of "table.shard.arity.1" "1.bin") (list (s32-word 3)))

  ;; ---- a single delimiter, where an empty column is a real column ------

  (define csv (make-temporary-directory))
  (display-to-file "name,count\nx,1\n\"c,d\",2\n,3\n" (build-path csv "hdr.csv"))
  (import! csv #:delimiter #\, #:skip-rows 1)
  (check-equal? (words-of "table.hdr.arity.2" "0.bin")
                (list (expected-str "x") (s32-word 1)
                      (expected-str "c,d") (s32-word 2)
                      (expected-str "") (s32-word 3)))
  (delete-directory/files csv)

  ;; ---- rejected inputs --------------------------------------------------

  (check-regexp-match #px"r\\.csv:2: 3 columns, expected arity 2"
                      (import-failure! "r.csv" "1 2\n3 4 5\n"))
  (check-regexp-match #px"unbalanced parentheses"
                      (import-failure! "r.csv" "(pt 1 2\n"))
  (check-regexp-match #px"unterminated string"
                      (import-failure! "r.csv" "a \"b\n"))
  (check-regexp-match #px"struct pt appears with 2 fields and also with 1"
                      (import-failure! "r.csv" "(pt 1 2) x\n(pt 1) y\n"))
  ;; > SEQ_BLEAF_MAX bytes has to be a rope, which this writer cannot build
  (check-regexp-match #px"exceeds the 256-byte monolithic-intern limit"
                      (import-failure! "r.csv" (string-append (make-string 300 #\x) "\n")))
  ;; NaN is unrepresentable and -inf.0 reads as a struct word (types.h)
  (check-regexp-match #px"not a representable float"
                      (import-failure! "r.csv" "1e400\n"))
  ;; a schema type the row does not satisfy
  (check-regexp-match #px"not an int" (import-failure! "r.csv" "# int\nxyz\n"))
  ;; ... and none of those left a loadable database behind
  (check-true (directory-exists? db) "a failed import deleted the previous database")
  (check-equal? (filter (lambda (p) (regexp-match? #px"^\\.import-" (path->string p)))
                        (directory-list (build-path repo-root "data")))
                '()
                "a failed import left its staging directory behind")

  (delete-directory/files db)
  (delete-directory/files src))
