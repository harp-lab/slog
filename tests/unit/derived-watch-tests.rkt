#lang racket

;; §18.5 derived watches -- the first meta-program (docs/slog-reflection.md).
;; `watch cone REL [image KEY]` derives REL's dependency-ancestor cone from
;; a MOUNTED image's rule records and installs each member through the
;; ordinary level-0 watch protocol.  The battery pins the three claims:
;;
;;   1. derivation + installation: the cone of `answer` over v1 is exactly
;;      {answer, path, edge}, and every member gets an ordinary watch id;
;;   2. the set is SEMANTIC: the same command against the refactored v2
;;      image (answer rewired through `short`) derives {answer, short,
;;      edge} -- path is out, short is in -- with already-installed
;;      members reported, not duplicated;
;;   3. honesty at the boundary: a derived member with no live VersionKey
;;      is reported as derived-not-installed, never guessed at.

(require rackunit
         racket/file
         racket/list
         racket/runtime-path
         "../../compiler/compile.rkt"
         "../../compiler/modules.rkt"
         "../../compiler/program-image.rkt"
         "../../compiler/repl.rkt")

(define-runtime-path repo-root "../..")

(define v1-text
  (string-append
   "table (edge int int)\n"
   "table (path int int)\n"
   "table (answer int int)\n"
   "rule (edge 1 2) (edge 2 3)\n"
   "rule (edge X Y) --> (path X Y)\n"
   "rule (path X Y) (edge Y Z) --> (path X Z)\n"
   "rule (path X Y) --> (answer X Y)\n"))

;; the refactor: answer now fed through `short`; path keeps existing but
;; no longer contributes to answer.
(define v2-text
  (string-append
   "table (edge int int)\n"
   "table (short int int)\n"
   "table (path int int)\n"
   "table (answer int int)\n"
   "rule (edge 1 2) (edge 2 3)\n"
   "rule (edge X Y) --> (short X Y)\n"
   "rule (edge X Y) --> (path X Y)\n"
   "rule (path X Y) (edge Y Z) --> (path X Z)\n"
   "rule (short X Y) --> (answer X Y)\n"))

(define (emit-image-for dir name text)
  (define source (build-path dir name))
  (call-with-output-file source #:exists 'truncate
    (lambda (out) (display text out)))
  (parameterize ([current-directory repo-root])
    (define program
      (first (load-program-list (path->string source) (hash))))
    (define pp (program->jobs program))
    (define-values (image path)
      (emit-program-image program (first pp) dir
                          #:type-env (fourth pp)
                          #:model (fifth pp)))
    (values (program-image-key image) path source)))

(module+ test
  (void (putenv "SLOG_NO_MEM_CAP" "1"))
  (void (putenv "SLOG_THREADS" "2"))

  (define dir (make-temporary-file "derived-watch-~a" 'directory))
  (dynamic-wind
    void
    (lambda ()
      (define-values (k1 p1 s1) (emit-image-for dir "dw_v1.slog" v1-text))
      (define-values (k2 p2 _s2) (emit-image-for dir "dw_v2.slog" v2-text))

      (test-case "derive, install, re-derive semantically, report honestly"
        (define transcript
          (parameterize ([current-directory repo-root])
            (plain-transcript
             (list (format "run ~a" (path->string s1))
                   (format "image mount ~s" (path->string p1))
                   (format "image mount ~s" (path->string p2))
                   (format "watch cone answer image ~a" k1)
                   (format "watch cone answer image ~a" k2)
                   "watches"))))
        ;; 1. the v1 cone: exactly answer/path/edge, each installed
        (check-regexp-match #px"Derived watch cone for answer .* 3 relations"
                            transcript)
        (check-regexp-match #px"answer — w[0-9]+ installed \\(level 0\\)"
                            transcript)
        (check-regexp-match #px"path — w[0-9]+ installed \\(level 0\\)"
                            transcript)
        (check-regexp-match #px"edge — w[0-9]+ installed \\(level 0\\)"
                            transcript)
        ;; 2. the v2 derivation: short is IN (but has no live version in
        ;;    the v1 session), path is OUT, the overlap is deduplicated
        (check-regexp-match #px"short — no live VersionKey; derived, not installed"
                            transcript)
        (check-false (regexp-match? #px"short — w[0-9]+ installed" transcript))
        (check-regexp-match #px"answer — already watched" transcript)
        (check-regexp-match #px"edge — already watched" transcript))

      (test-case "no mounted image refuses with instructions"
        (define transcript
          (parameterize ([current-directory repo-root])
            (plain-transcript (list "watch cone answer"))))
        (check-regexp-match #px"no mounted image to derive from" transcript)))
    (lambda () (delete-directory/files dir))))
