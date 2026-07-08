#lang racket

(provide fnv
         fullpath
         escape-id-for-C
         escape-c-string-literal
         bucket-count
         gensymb)

(require "params.rkt")
(require racket/runtime-path)

;; Resolved relative to this source file, not the current directory, so the
;; compiler's modules can be loaded (e.g. by unit tests) from anywhere.
(define-runtime-path daemon-dir "../daemon")

;; This parameter must be set to the same value as in daemon/database.h
(define bucket-count
  (arithmetic-shift
   1
   (string->number
    (first (regexp-match #rx"[0123456789]+"
                         (first (let ([s (with-input-from-file (build-path daemon-dir "database.h")
                                                               (lambda () (read-string 9999)))])
                                  (regexp-match #rx"define bucket_bits [0123456789]+" s))))))))

(define (fnv str)
  ;; Applies fnv1a to a sample of str
  ;; Must match the c++ implementation in slogd.h !
  (define fnv-prime 16777619)
  (define fnv-base 2166136261)
  (define bitmask (- (expt 2 32) 1))
  (define (step h)
    (bitwise-and (* h fnv-prime) bitmask))
  (define (add h x)
    (step (bitwise-xor h x)))
  (define (cp i)
    (char->integer (string-ref str i)))
  (foldl (lambda (n h) (add h (cp n))) fnv-base (range (string-length str))))

(define (fullpath path)
  (path->string (path->complete-path path)))

(define nums-pool "0123456789")
(define alpha-pool "abcdefghijklmnopqrstuvwxyz")
(define alphanum-pool (string-append nums-pool alpha-pool (string-upcase alpha-pool)))

;; Monotonic counter so generated names are guaranteed unique within a compile.
;; (The random suffix alone collides via the birthday paradox once a program has
;; a few hundred generated names -- e.g. a large `facts` block.)
(define gensymb-counter 0)

(define (gensymb s)
  (define (add s n pool)
    (define randlst (shuffle (string->list (string-append pool pool pool))))
    (string-append s (list->string (take randlst n))))
  (set! gensymb-counter (add1 gensymb-counter))
  ;; Append the counter as bare digits (no separator): names must stay
  ;; alphanumeric because escape-id-for-C doubles any '_', which would make a
  ;; gensym'd constant's reference (escaped) differ from its declaration.
  (string->symbol
   (string-append (add (add (symbol->string s) 1 nums-pool) (if debug-mode 3 12) alphanum-pool)
                  (number->string gensymb-counter))))

(define (escape-id-for-C id)
  (define lst
    (foldr (lambda (t lst)
             (if (equal? t "_")
                 `(,t ,t ,@lst)
                 `(,t ,@lst)))
           '() ;; this makes a single underscore reserved by the compiler
           (map string (string->list (symbol->string id)))))
  (define (escape-one s)
    (if (or (equal? s "_") (string-contains? alphanum-pool s))
        s
        (let ([hex (number->string (char->integer (string-ref s 0)) 16)])
          ;; Pad to at least 5 hex digits, but never negative: a supplementary-
          ;; plane code point (>= U+100000) has 6 hex digits and must not
          ;; underflow the substring width.
          (string-append "_" (make-string (max 0 (- 5 (string-length hex))) #\0) hex))))
  (string->symbol (apply string-append (map escape-one lst))))

;; Escape a Racket string so it can be safely interpolated into a C++ narrow
;; string literal ("..."):  \\ and " must be escaped; newline/CR/tab and other
;; ASCII control bytes become octal escapes (fixed 3 digits -> unambiguous).
;; Non-ASCII code points (>= U+0080) are left as-is: the source is written UTF-8
;; and raw high bytes are valid literal content (the daemon interns them
;; byte-for-byte).  Without this, an embedded " / newline breaks the clang build
;; and a backslash silently interns the WRONG value (e.g. "\\t" -> a tab).
(define (escape-c-string-literal s)
  (apply string-append
    (for/list ([c (in-string s)])
      (case c
        [(#\\) "\\\\"]
        [(#\") "\\\""]
        [(#\newline) "\\n"]
        [(#\return) "\\r"]
        [(#\tab) "\\t"]
        [else
         (define n (char->integer c))
         (if (or (< n #x20) (= n #x7f))
             (let ([o (number->string n 8)])
               (string-append "\\" (make-string (- 3 (string-length o)) #\0) o))
             (string c))]))))
