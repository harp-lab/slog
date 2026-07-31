#lang racket/base

;; A correctly-sized SHA-256 over libcrypto, replacing the `sha` package.
;;
;; The package's binding declared SHA256's RETURN as `_bytes`, whose
;; pointer->bytes conversion scans forward for a NUL terminator to decide
;; the length -- but a 32-byte digest has no interior zero byte about 88%
;; of the time, so nearly every call read past the output buffer before a
;; sized copy rescued the value.  An overread that crosses into an
;; unmapped page is a segfault: in a driver that hashes on every action
;; cache-check, that was the wandering "invalid memory reference" /
;; silent-death flake striking about once per full session battery
;; (probe: a `_bytes`-returned 32-byte NUL-free buffer measured as 33-36
;; bytes, varying with heap noise).
;;
;; Here the digest comes back in the `(_bytes o 32)` OUTPUT argument -- a
;; real 32-byte Racket byte string the C side fills -- and the returned
;; pointer is deliberately dropped untranslated.  No scan, no copy, no
;; length guess; byte-identical digests, so every content-addressed cache
;; key is unchanged.
(require ffi/unsafe
         openssl/libcrypto
         (only-in file/sha1 bytes->hex-string))

(provide sha256 bytes->hex-string)

(define sha256
  (if libcrypto
      (get-ffi-obj
       'SHA256 libcrypto
       (_fun [data : _bytes]
             [len : _int = (bytes-length data)]
             [md : (_bytes o 32)]
             -> [r : _pointer]
             -> md))
      (lambda (data) (error 'sha256 "libcrypto could not load"))))

(module+ test
  (require rackunit)
  ;; FIPS 180-2 vectors
  (check-equal?
   (bytes->hex-string (sha256 #"abc"))
   "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad")
  (check-equal?
   (bytes->hex-string (sha256 #""))
   "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855")
  (check-equal?
   (bytes->hex-string
    (sha256 #"abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq"))
   "248d6a61d20638b8e5c026930c3e6039a33ce45964ff2167f6ecedd419db06c1")
  ;; a large input exercises the length argument
  (check-equal?
   (bytes->hex-string (sha256 (make-bytes 1000000 (char->integer #\a))))
   "cdc76e5c9914fb9281a1c7e284d73e67f1809a48a497200e046d39ccc7112cd0"))
