#lang racket

(provide fnv
         unescape-id-from-C
         fullpath
         source-name-key
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

;; Stable source identity for compiler-generated relation/type names.  Parser
;; provenance carries complete paths, but hashing those paths makes otherwise
;; identical plans and result relation names depend on the checkout location.
;; Keep the useful module path component while removing the compilation-root
;; prefix.  `simplify-path` is deliberately filesystem-free: saved-source
;; replay may describe a source file which no longer exists on disk.
(define (source-name-key path [root (current-directory)])
  (define root+ (simplify-path (path->complete-path root) #f))
  (define path+ (simplify-path (path->complete-path path root+) #f))
  (define relative (find-relative-path root+ path+))
  ;; Racket paths use the host separator.  Generated names and plan identity
  ;; must not, so make the key slash-normalized as well as root-relative.
  (regexp-replace* #rx"\\\\" (path->string relative) "/"))

(define nums-pool "0123456789")
(define alpha-pool "abcdefghijklmnopqrstuvwxyz")
(define alphanum-pool (string-append nums-pool alpha-pool (string-upcase alpha-pool)))

;; CONVENTION: every gensymb base is `_`- or `$`-prefixed (`_t`, `_tconst`,
;; `_err…`, `_chk`, `$sq…`).  The random suffix below must never reach plan
;; bytes; canonical-plan.rkt's DebugMap register names rely on the prefix to
;; blank compiler-introduced variables (the lexer admits neither a leading
;; "$" nor -- once escaped -- a single "_" in a user identifier).
;; Monotonic counter so generated names are guaranteed unique within a compile.
;; (The random suffix alone collides via the birthday paradox once a program has
;; a few hundred generated names -- e.g. a large block of ground rules.)
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

;; The inverse, for DISPLAY only (canonical-plan's DebugMap register names):
;; "__" -> "_", "_" + 5 hex digits (6 for a supplementary-plane code point,
;; which escape-one pads to at least 5) -> the character; anything else is
;; kept verbatim.  Never used for identity.
(define (unescape-id-from-C id)
  (define s (if (symbol? id) (symbol->string id) id))
  (define n (string-length s))
  (define (hex-at i len)
    (and (<= (+ i len) n)
         (let ([v (string->number (substring s i (+ i len)) 16)])
           (and v (or (< v #xD800) (> v #xDFFF)) (<= v #x10FFFF) v))))
  (let loop ([i 0] [acc '()])
    (cond
      [(>= i n) (apply string-append (reverse acc))]
      [(char=? (string-ref s i) #\_)
       (cond
         [(and (< (add1 i) n) (char=? (string-ref s (add1 i)) #\_))
          (loop (+ i 2) (cons "_" acc))]
         [(let ([six (hex-at (add1 i) 6)])
            (and six (>= six #x100000) six))
          => (lambda (cp) (loop (+ i 7) (cons (string (integer->char cp)) acc)))]
         [(hex-at (add1 i) 5)
          => (lambda (cp) (loop (+ i 6) (cons (string (integer->char cp)) acc)))]
         [else (loop (add1 i) (cons "_" acc))])]
      [else (loop (add1 i) (cons (string (string-ref s i)) acc))])))

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
