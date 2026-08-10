#lang racket

;; T3b slice 4 battery: the core-budget arbiter, the priority pool, and the
;; estimate-derived promotion budget (docs/t3b-contract.md §3 slice 4).
;;
;; The pool tests pin SLOG_BUILD_JOBS=1 BEFORE the pool's lazy first use, so
;; one worker drains the queue and execution order IS queue order -- the
;; §5.5 priority claims become deterministic assertions.

(module+ test
  (require rackunit
           "../../compiler/params.rkt"
           "../../compiler/tools.rkt"
           "../../compiler/tier-profile.rkt")

  ;; ---- the arbiter's arithmetic (§5.5, §12.14) ---------------------------

  (test-case "the compile-side budget never oversubscribes its share"
    (for ([p (in-list '(2 3 4 6 8 16 32))])
      (define-values (pool o2) (core-budget p))
      (check-true (>= pool 1) (format "P=~a pool" p))
      (check-true (>= o2 1) (format "P=~a o2" p))
      ;; §5.5's split: pool = max(floor(P/2)-1, 1); the nice'd O2 batch
      ;; stays within roughly half the pool's share
      (check-equal? pool (max 1 (sub1 (quotient p 2))) (format "P=~a" p))
      (check-true (<= o2 (max 1 (quotient (add1 pool) 2))) (format "P=~a" p))
      ;; and on ordinary P >= 3, the compile side stays under half the
      ;; machine, leaving the daemon's workers their share
      (when (>= p 3)
        (check-true (<= (+ pool o2) p) (format "P=~a total" p)))))

  ;; ---- the priority queue -------------------------------------------------

  ;; one worker; jobs record their execution order
  (putenv "SLOG_BUILD_JOBS" "1")

  (define order (box '()))
  (define (record! tag)
    (lambda () (set-box! order (cons tag (unbox order))) tag))

  (test-case "priority beats submission order; boost promotes a label"
    ;; occupy the single worker so the queue can be arranged behind it
    (define gate (make-semaphore 0))
    (define blocker (pooled-eager (lambda () (semaphore-wait gate) 'blocked)))
    (sleep 0.1)                       ; let the worker pick the blocker up
    ;; three pending jobs: two future-priority in pipeline order, one
    ;; explicitly current-priority, submitted LAST
    (define a (pooled-eager (record! 'a) #:label "job-a"))
    (define b (pooled-eager (record! 'b) #:label "job-b"))
    (define c (pooled-eager (record! 'c) #:label "job-c" #:priority 1))
    ;; boost b: it joins priority 1 behind c (c's sequence is earlier at
    ;; equal priority?  no -- c was submitted after b; within priority 1,
    ;; SEQUENCE order holds, so b (seq 2) runs before c (seq 3))
    (pool-boost! "job-b")
    (semaphore-post gate)
    (void (a) (b) (c))                ; force all three
    (check-equal? (reverse (unbox order)) '(b c a)
                  "priority 1 first (b then c by sequence), future job last"))

  (test-case "a boost of a running or absent label is a no-op"
    (check-equal? (void) (pool-boost! "no-such-label"))
    (check-equal? (void) (pool-boost! #f)))

  (test-case "pool errors re-raise on force, repeatedly"
    (define f (pooled-eager (lambda () (error 'boom "nope"))))
    (check-exn exn:fail? f)
    (check-exn exn:fail? f))

  ;; ---- the estimate-derived promotion budget ------------------------------

  ;; scratch store (fullpath is cwd-relative)
  (define scratch (make-temporary-file "tier-arbiter-~a" 'directory))
  (define (write-tiers! hash keys)
    (make-directory* (build-path scratch "build"))
    (call-with-output-file (build-path scratch "build" (format "~a.tiers" hash))
      #:exists 'replace
      (lambda (o)
        (writeln `(stratum-tiers (hash ,hash) (policy classified)
                                 (coverage 1 1)
                                 ,@(for/list ([k keys] [i (in-naturals)])
                                     `(kernel (ord ,i) (key ,k) (coverage 1 1)
                                              (variant 0 tiered iterated native))))
                 o))))

  (parameterize ([current-directory scratch])
    (test-case "no recorded build cost falls back to the default floor"
      (write-tiers! "dddd0001" '("k-nocost"))
      (check-equal? (stratum-promote-budget-ms "dddd0001") (tier-promote-ms)))

    (test-case "a recorded cost sets the budget to mult × estimate, floored"
      (write-tiers! "dddd0002" '("k-cost"))
      (profile-note-build! "dddd0002" 5000.0)
      (check-equal? (profile-build-ms "k-cost") 5000.0)
      (check-equal? (stratum-promote-budget-ms "dddd0002") 10000.0)
      ;; a tiny estimate cannot promote instantly: the floor holds
      ;; (numerically -- max over a float estimate returns an inexact)
      (profile-note-build! "dddd0002" 100.0)
      (check-= (stratum-promote-budget-ms "dddd0002") (tier-promote-ms) 0.001))

    (test-case "build cost and observations round-trip together"
      (write-tiers! "dddd0003" '("k-both"))
      (profile-note-build! "dddd0003" 3000.0)
      (profile-note-fixpoint! "dddd0003" 'interp #f 4 1.5)
      ;; the observation write preserved the build cost, and vice versa
      (check-equal? (profile-build-ms "k-both") 3000.0)
      (check-equal? (length (profile-observations "k-both")) 1)
      (profile-note-build! "dddd0003" 3500.0)
      (check-equal? (length (profile-observations "k-both")) 1)
      (check-true (stratum-profile-skip? "dddd0003"))))

  (delete-directory/files scratch))
