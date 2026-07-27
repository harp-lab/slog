#lang racket

;; convert-db-folder (compiler/tools.rkt): delimited text folder -> static
;; binary database under data/<name>/.
;;
;; The importer writes tuple words the daemon never re-encodes, so it is a
;; second implementation of daemon/types.h's NaN boxing and daemon/intern.h's
;; string-id assignment.  Two halves here: a guard that the header constants
;; it mirrors are still what they were, and a byte-level check of what it
;; actually writes.  A drift in either direction surfaces at load as a
;; "Dangling string id" fatal (or, worse, as a tuple of the wrong values),
;; a long way from the cause.

(module+ test
  (require rackunit
           racket/runtime-path
           "../../compiler/tools.rkt")

  (define-runtime-path repo-root "../..")

  ;; ---- the daemon constants convert-db-folder mirrors -----------------

  (define (header-defines path)
    (for/hash ([line (in-list (file->lines (build-path repo-root path)))]
               #:when (regexp-match #px"^#define\\s+(\\w+)\\s+(.+?)\\s*$" line))
      (define m (regexp-match #px"^#define\\s+(\\w+)\\s+(.+?)\\s*$" line))
      (values (second m) (third m))))

  (define intern.h (header-defines "daemon/intern.h"))
  (define types.h (header-defines "daemon/types.h"))
  (define seqparams.h (header-defines "daemon/seqparams.h"))

  ;; 21 bucket bits + 5 inner-position bits = the 26-bit hash prefix of an
  ;; intern id; the collision-chain index sits above it.
  (check-equal? (hash-ref intern.h "intern_buckets_bits" #f) "21"
                "intern id layout changed: convert-db-folder's 26-bit hash prefix is stale")
  (check-equal? (hash-ref types.h "str_intern_tag" #f) "0")
  (check-equal? (hash-ref types.h "s32_prim_tag" #f) "1")
  (check-equal? (hash-ref types.h "internflags" #f) "0x7fffffc000000000")
  (check-equal? (hash-ref types.h "NaNflags" #f) "0x7ff0000000000000")
  ;; longer strings are tag-4 ropes, which the importer refuses rather than builds
  (check-equal? (hash-ref seqparams.h "SEQ_BLEAF_MAX" #f) "((u32)256)")
  ;; fasthash<utf8string> is FNV-1a over the utf8 bytes
  (define intern-src (file->string (build-path repo-root "daemon/intern.h")))
  (check-true (and (regexp-match? #px"2166136261u" intern-src)
                   (regexp-match? #px"16777619u" intern-src))
              "fasthash<utf8string> is no longer FNV-1a with the classic constants")

  ;; ---- reference encoders (types.h / intern.h, independently spelled) --

  (define (fnv-1a bs)
    (for/fold ([h 2166136261]) ([b (in-bytes bs)])
      ;; the C loop xors a SIGNED char, so bytes >= 0x80 sign-extend first
      (bitwise-and (* (bitwise-xor h (if (< b 128) b (+ b #xffffff00))) 16777619)
                   #xffffffff)))

  (define (s32-word v) (bitwise-ior #x7ff0000000000000 (arithmetic-shift 1 35)
                                    (bitwise-and v #xffffffff)))
  (define (str-word id) (bitwise-ior #x7fffffc000000000 id))
  (define (float-word f) (integer-bytes->integer (real->floating-point-bytes f 8 #f) #f #f))

  (define (words-of path)
    (define bs (file->bytes path))
    (for/list ([i (in-range (quotient (bytes-length bs) 8))])
      (integer-bytes->integer bs #f #f (* 8 i) (* 8 (add1 i)))))

  ;; ---- run the importer -----------------------------------------------

  (define src (make-temporary-directory))
  (define dbname "csv_import_unit_test")
  (define db (build-path repo-root "data" dbname))

  (display-to-file "1 2\n-5\t3\n" (build-path src "edge.csv"))
  ;; a quoted column is a string even when it looks like a number, and may
  ;; hold spaces; a bare word is a string too
  (display-to-file "alice \"bob jones\" \"7\"\n" (build-path src "who.csv"))
  (display-to-file "1 0.5\n2 -1.25e2\n" (build-path src "weight.csv"))
  (display-to-file "" (build-path src "empty.csv"))

  (define out (open-output-string))
  (parameterize ([current-directory repo-root]
                 [current-output-port out]
                 [current-error-port out])
    (convert-db-folder (path->string src) dbname))

  (check-true (directory-exists? (build-path db "table.edge.arity.2"))
              "arity inferred from the first row")
  (check-true (directory-exists? (build-path db "table.who.arity.3")))
  (check-true (directory-exists? (build-path db "table.weight.arity.2")))
  (check-false (directory-exists? (build-path db "table.empty.arity.0"))
               "a file with no rows has no inferable arity and is skipped")

  ;; ints, including a negative (masking to 32 bits before the tag matters:
  ;; an unmasked negative would sign-extend over the whole word)
  (check-equal? (words-of (build-path db "table.edge.arity.2" "0.bin"))
                (list (s32-word 1) (s32-word 2) (s32-word -5) (s32-word 3)))

  ;; floats are raw little-endian binary64
  (check-equal? (words-of (build-path db "table.weight.arity.2" "0.bin"))
                (list (s32-word 1) (float-word 0.5) (s32-word 2) (float-word -125.0)))

  ;; strings: the id the daemon's interner will recompute on load
  (define (expected-id s chain)
    (bitwise-ior (arithmetic-shift chain 26)
                 (bitwise-and (fnv-1a (string->bytes/utf-8 s)) #x3ffffff)))
  (check-equal? (words-of (build-path db "table.who.arity.3" "0.bin"))
                (list (str-word (expected-id "alice" 0))
                      (str-word (expected-id "bob jones" 0))
                      (str-word (expected-id "7" 0))))

  ;; value.strings is NUL-terminated records in id-assignment order, because
  ;; loadStringsBIN re-interns them in exactly that order
  (check-equal? (file->bytes (build-path db "value.strings" "0.bin"))
                #"alice\0bob jones\0007\0")

  ;; ---- rejected inputs --------------------------------------------------

  (define (import-failure! filename contents)
    (define bad (make-temporary-directory))
    (display-to-file contents (build-path bad filename))
    (begin0 (with-handlers ([exn:fail? exn-message])
              (parameterize ([current-directory repo-root]
                             [current-output-port (open-output-nowhere)]
                             [current-error-port (open-output-nowhere)])
                (convert-db-folder (path->string bad) dbname))
              #f)
      (delete-directory/files bad)))

  ;; a ragged row is a mistake to report by line, not to resynchronize past
  (check-regexp-match #px"r\\.csv:2: 3 columns, expected arity 2"
                      (or (import-failure! "r.csv" "1 2\n3 4 5\n") ""))
  ;; > SEQ_BLEAF_MAX bytes has to be a rope, which this writer cannot build
  (check-regexp-match #px"exceeds the 256-byte monolithic-intern limit"
                      (or (import-failure! "r.csv" (string-append (make-string 300 #\x) "\n")) ""))
  ;; int columns outside the s32 range would need an interned bignum
  (check-regexp-match #px"outside the s32 range"
                      (or (import-failure! "r.csv" "9999999999\n") ""))

  (delete-directory/files db)
  (delete-directory/files src))
