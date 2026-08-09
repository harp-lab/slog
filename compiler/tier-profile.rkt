#lang racket
;; T3b slice 2 -- the tier-profile sidecar (docs/execution-tiers.md §5.3's
;; demotion feedback path, docs/t3b-contract.md §3 slice 2).
;;
;; Slice 1 decides statically which rule variants are worth compiling; this
;; module answers the question statics cannot: does this kernel's fixpoint
;; historically arrive BEFORE its artifact could?  A tiny recursive kernel
;; interprets to fixpoint in single-digit milliseconds while its -O0 build
;; costs seconds -- the T3a race is over before clang has parsed a header --
;; and today the tree pays that clang anyway, every cold run.
;;
;; The store is `build/profile/<KernelPlanKey>.profile`.  Keyed by the KERNEL
;; plan key, not the stratum job hash, deliberately: job hashes fold in the
;; compiler-sources fingerprint and daemon headers, so every compiler or
;; header edit re-keys them and would wipe a hash-keyed profile at exactly
;; the moment it is most valuable (the post-edit cold suite run).  Kernel
;; keys are plan-layer identity -- they survive re-keys, and they transfer
;; across programs that share a kernel (T4's sharing).
;;
;; What a profile is NOT: semantics.  It never reaches the plan, the TU text,
;; or the job hash -- it only decides whether builds are SCHEDULED for text
;; that was emitted identically either way.  Deleting build/profile/ costs
;; rediscovery (one compile), never correctness.
;;
;; RECORD (runslog.rkt, at each stratum fixpoint under the tiered regime):
;; one observation -- started rung, whether a better artifact attached before
;; fixpoint, iterations, fixpoint wall ms -- appended to every kernel key the
;; stratum's .tiers sidecar names.  Only tiered-mode runs record: under the
;; explicit -O0/-O2/interp modes there is no race to observe, and the golden
;; suite (SLOG_OPT=0) stays byte-stable in build/.
;;
;; CONSULT (compile.rkt, cold tiered arm): skip the toolchain iff EVERY
;; kernel's latest interp-started observation says interp sufficed --
;; fixpoint reached with no artifact attached, under the ms ceiling.  The
;; conjunction is the conservative direction: one hot shared kernel keeps
;; the stratum compiling.  Self-correcting at re-entry granularity: a
;; skipped stratum still records, so when its data grows past the ceiling
;; the next run compiles again (mid-run rescue is slice 3's promotion).

(require "params.rkt" "utils.rkt"
         (only-in "tools.rkt" call-with-atomic-output))

(provide profile-note-fixpoint! stratum-profile-skip?
         history-says-interp-sufficed? profile-observations
         tier-profile-window)

;; Observations kept per kernel, newest first.  Large enough that one
;; anomalous run cannot evict all history the rule wants; small enough that
;; the file stays a screenful.
(define tier-profile-window (make-parameter 8))

(define (profile-path key)
  (fullpath (format "build/profile/~a.profile" key)))

;; ---------------------------------------------------------------------------
;; The stratum -> kernel-keys map, read off the slice-1 .tiers sidecar.
;; A stratum with no sidecar (legacy cache, hand-built cprog) yields '() --
;; consult reads that as "no evidence, keep compiling".
;; ---------------------------------------------------------------------------

(define (stratum-kernel-keys proghash)
  (with-handlers ([exn:fail? (lambda (_) '())])
    (match (call-with-input-file
             (fullpath (format "build/~a.tiers" proghash)) read)
      [`(stratum-tiers ,fields ...)
       (for/list ([f (in-list fields)]
                  #:when (match f [`(kernel ,_ ...) #t] [_ #f]))
         (match f
           [`(kernel ,_ord (key ,k) ,_ ...) k]))]
      [_ '()])))

;; ---------------------------------------------------------------------------
;; Observation store.  One s-expression per kernel:
;;   (kernel-profile (key "…")
;;     (obs (started interp|o0|o2) (upgraded #t|#f)
;;          (iterations N) (ms N.N) (stratum "hash") (at SECONDS)) ...)
;; Concurrent test runs share build/ -- writes are temp+atomic-rename like
;; the rest of the cache, so a lost race costs one observation, not a torn
;; file.
;; ---------------------------------------------------------------------------

(define (profile-observations key)
  (with-handlers ([exn:fail? (lambda (_) '())])
    (match (call-with-input-file (profile-path key) read)
      [`(kernel-profile (key ,_) ,obs ...) obs]
      [_ '()])))

(define (write-profile! key obs)
  (make-directory* (fullpath "build/profile"))
  (call-with-atomic-output
   (profile-path key)
   (lambda () (writeln `(kernel-profile (key ,key) ,@obs)))))

;; Record one stratum fixpoint against every kernel the stratum carries.
;; `started` is the rung the stratum LAUNCHED on ('interp/'o0/'o2);
;; `upgraded?` whether the driver attached a better artifact before this
;; fixpoint; `ms` the daemon-reported fixpoint wall time.  Called only under
;; the tiered regime (the caller guards) and off entirely when the profile
;; is disabled.
(define (profile-note-fixpoint! proghash started upgraded? iterations ms)
  (when (tier-profile-enabled)
    (define ob `(obs (started ,started) (upgraded ,(and upgraded? #t))
                     (iterations ,iterations) (ms ,ms)
                     (stratum ,proghash) (at ,(current-seconds))))
    (for ([key (in-list (stratum-kernel-keys proghash))])
      (write-profile! key (cons ob (take-up-to (profile-observations key)
                                               (sub1 (tier-profile-window))))))))

(define (take-up-to lst n) (if (> (length lst) n) (take lst n) lst))

;; ---------------------------------------------------------------------------
;; The consult rule
;; ---------------------------------------------------------------------------

;; Pure, so the battery can pin its arms without a filesystem: given one
;; kernel's observations (newest first), does history say the interpreter
;; suffices?  Only interp-STARTED observations are evidence in either
;; direction -- a warm-native run (started o0/o2) says nothing about whether
;; interp would have been enough, so it neither grants nor revokes a skip.
;; The latest interp-started observation decides:
;;   - upgraded? #t  -> the run outlasted a build; the artifact is wanted
;;   - ms > ceiling  -> interp was slow enough that a compile would pay
;;   - otherwise     -> fixpoint beat clang; skip
(define (history-says-interp-sufficed? obs)
  (define latest-interp
    (for/first ([o (in-list obs)]
                #:when (match o
                         [`(obs (started interp) ,_ ...) #t] [_ #f]))
      o))
  (match latest-interp
    [`(obs (started interp) (upgraded ,up) (iterations ,_) (ms ,ms) ,_ ...)
     (and (not up) (real? ms) (<= ms (tier-skip-max-ms)))]
    [_ #f]))

;; The stratum-level verdict compile-strata consults on the cold tiered arm.
;; Conjunction over the stratum's kernels, and vacuously false: no sidecar or
;; no kernels means no evidence, and no evidence means compile as before.
(define (stratum-profile-skip? proghash)
  (and (tier-profile-enabled)
       (let ([keys (stratum-kernel-keys proghash)])
         (and (pair? keys)
              (for/and ([k (in-list keys)])
                (history-says-interp-sufficed? (profile-observations k)))))))
