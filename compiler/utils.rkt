#lang racket

(provide fnv
         fullpath
         escape-id-for-C
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
        (let ([pad "00000"]
              [hex (number->string (char->integer (string-ref s 0)) 16)])
          (string-append "_" (substring pad 0 (- 5 (string-length hex))) hex))))
  (string->symbol (apply string-append (map escape-one lst))))
