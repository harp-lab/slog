#lang racket

;; T3b slice 2 battery: the tier-profile sidecar's consult rule and store
;; (docs/t3b-contract.md §3 slice 2, compiler/tier-profile.rkt).
;;
;; The consult rule is pure over an observation list, so its arms pin
;; directly; the store tests run the real read/modify/write path against a
;; scratch build/ (fullpath is cwd-relative), including the .tiers-driven
;; stratum conjunction and the window bound.

(module+ test
  (require rackunit
           "../../compiler/params.rkt"
           "../../compiler/tier-profile.rkt")

  (define (ob #:started [started 'interp] #:upgraded [up #f] #:ms [ms 1.5])
    `(obs (started ,started) (upgraded ,up) (iterations 4) (ms ,ms)
          (stratum "cafe0000") (at 0)))

  ;; ---- the rule's arms ---------------------------------------------------

  (test-case "no history is no evidence"
    (check-false (history-says-interp-sufficed? '())))

  (test-case "a fast unraced interp fixpoint says skip"
    (check-true (history-says-interp-sufficed? (list (ob)))))

  (test-case "an upgraded run means the artifact was wanted"
    (check-false (history-says-interp-sufficed? (list (ob #:upgraded #t)))))

  (test-case "a slow interp fixpoint disqualifies, even unraced"
    (check-false (history-says-interp-sufficed?
                  (list (ob #:ms (add1 (tier-skip-max-ms)))))))

  (test-case "the ceiling is a parameter"
    (parameterize ([tier-skip-max-ms 0])
      (check-false (history-says-interp-sufficed? (list (ob #:ms 1.5))))))

  (test-case "warm-native observations are not evidence either way"
    ;; a newer o0-started run does not revoke the interp verdict...
    (check-true (history-says-interp-sufficed?
                 (list (ob #:started 'o0) (ob))))
    ;; ...and a history of ONLY warm-native runs grants nothing
    (check-false (history-says-interp-sufficed?
                  (list (ob #:started 'o0) (ob #:started 'o2)))))

  (test-case "the LATEST interp observation decides, not the best"
    ;; newest first: a slow interp run in front of an old fast one -> no skip
    (check-false (history-says-interp-sufficed?
                  (list (ob #:ms 60000.0) (ob))))
    ;; and the recovery direction: fast again in front of slow -> skip
    (check-true (history-says-interp-sufficed?
                 (list (ob) (ob #:ms 60000.0)))))

  ;; ---- the store, in a scratch build/ -------------------------------------

  (define scratch (make-temporary-file "tier-profile-~a" 'directory))

  (define-syntax-rule (in-scratch body ...)
    (parameterize ([current-directory scratch]) body ...))

  (define (write-tiers! hash keys)
    (make-directory* (build-path scratch "build"))
    (call-with-output-file (build-path scratch "build" (format "~a.tiers" hash))
      #:exists 'replace
      (lambda (o)
        (writeln `(stratum-tiers (hash ,hash) (policy classified)
                                 (coverage 1 2)
                                 ,@(for/list ([k keys] [i (in-naturals)])
                                     `(kernel (ord ,i) (key ,k) (coverage 1 1)
                                              (variant 0 tiered iterated native))))
                 o))))

  (test-case "note-fixpoint fans out to every kernel of the stratum"
    (write-tiers! "aaaa0001" '("k-one" "k-two"))
    (in-scratch
     (profile-note-fixpoint! "aaaa0001" 'interp #f 4 1.2)
     (check-equal? (length (profile-observations "k-one")) 1)
     (check-equal? (length (profile-observations "k-two")) 1)
     (check-true (stratum-profile-skip? "aaaa0001"))))

  (test-case "the conjunction: one hot kernel keeps the stratum compiling"
    (write-tiers! "aaaa0002" '("k-two" "k-hot"))
    (in-scratch
     ;; k-hot's only interp run outlasted its build
     (profile-note-fixpoint! "aaaa0002" 'interp #t 40 9000.0)
     ;; k-two now carries a hot observation too (same stratum), so BOTH
     ;; strata sharing it stop skipping -- conservative by design
     (check-false (stratum-profile-skip? "aaaa0002"))
     (check-false (stratum-profile-skip? "aaaa0001"))))

  (test-case "no sidecar or no kernels means no evidence, not a skip"
    (in-scratch
     (check-false (stratum-profile-skip? "bbbb0000"))   ; no .tiers at all
     (write-tiers! "bbbb0001" '())
     (check-false (stratum-profile-skip? "bbbb0001"))))

  (test-case "the window is bounded, newest first"
    (write-tiers! "aaaa0003" '("k-win"))
    (in-scratch
     (for ([i (in-range (+ (tier-profile-window) 5))])
       (profile-note-fixpoint! "aaaa0003" 'interp #f i (* 1.0 i)))
     (define obs (profile-observations "k-win"))
     (check-equal? (length obs) (tier-profile-window))
     ;; newest first: the last write's iteration count leads
     (check-match (first obs)
                  `(obs ,_ ,_ (iterations ,n) ,_ ...)
                  (= n (+ (tier-profile-window) 4)))))

  (test-case "disabling the profile disables both record and consult"
    (write-tiers! "aaaa0004" '("k-off"))
    (in-scratch
     (parameterize ([tier-profile-enabled #f])
       (profile-note-fixpoint! "aaaa0004" 'interp #f 4 1.0)
       (check-equal? (profile-observations "k-off") '())
       (check-false (stratum-profile-skip? "aaaa0004")))
     ;; and with it back on, the same stratum records and skips
     (profile-note-fixpoint! "aaaa0004" 'interp #f 4 1.0)
     (check-true (stratum-profile-skip? "aaaa0004"))))

  (delete-directory/files scratch))
