#lang racket

;; Slog's static and dynamic settings and parameters
;; Copyright (c) Thomas Gilray, et al, see License.md

(provide (all-defined-out))

(require racket/runtime-path
         racket/string)

(define-runtime-path slog-version-path "../.version")

(define slog-version
  (string-trim (file->string slog-version-path)))
(define slog-version-components
  (regexp-match #px"^([0-9]+)\\.([0-9]+)\\.([0-9]+)$" slog-version))
(unless slog-version-components
  (error 'slog-version
         "expected MAJOR.MINOR.PATCH in ~a, got ~s"
         slog-version-path
         slog-version))
(define slog-version-major (string->number (list-ref slog-version-components 1)))
(define slog-version-minor (string->number (list-ref slog-version-components 2)))
(define slog-version-revision (string->number (list-ref slog-version-components 3)))
(define slog-copyright-authors "Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al.")
(define slog-copyright-warning "Some rights reserved. See ./License.md.")

(define debug-mode #t)

;; Join-planning score weights (join-planning.rkt).  A candidate join is
;; scored  wb*|bound vars| + wf*|free vars| + we*|guards/lets it unblocks|;
;; the greedy scheduler picks the max.  Parameters, so a driver (or a future
;; auto-tuner) can adjust them without touching the planner.
(define plan-weight-bound (make-parameter 100))
(define plan-weight-free (make-parameter -35))
(define plan-weight-enables (make-parameter 20))

;; Semijoin existence filters (operationalization.rkt): before an expanding
;; join, probe each future clause's relation on its already-bound columns
;; and prune partial tuples that cannot possibly satisfy it.  The env
;; toggle exists so benchmarks can compare; its value participates in the
;; .so cache key (compile.rkt), so flipping it cannot serve stale plugins.
(define semijoin-filters-enabled
  (make-parameter (not (getenv "SLOG_NO_SEMIJOIN"))))

;; Key-simple ternary cyclic join (docs/wcoj.md).  The planner may replace two
;; ordinary table probes that close a certified local cycle with one Expand3
;; action over their sorted prefix cursors.  The off switch is cache-keyed in
;; compile.rkt and remains the differential-testing/fallback escape hatch.
(define wcoj3-enabled
  (make-parameter (not (getenv "SLOG_NO_WCOJ3"))))

;; T4 slice 4: per-rule selective native emission (t4-contract §3 slice 4).
;; Which kernel rule ordinals the native artifact covers; the daemon runs
;; the complement interpreted, so coverage is native ∪ interp by
;; construction.  The deterministic even/odd/none values are the MECHANISM
;; gate's test knob -- real hotness policy is T3b's.  Cache-keyed in
;; compile.rkt (a partial artifact must never be served where a full one
;; was expected); flavored (_count/_maint*) TUs pin 'all regardless.
(define native-rule-coverage
  (make-parameter
   (let ([v (getenv "SLOG_NATIVE_COVERAGE")])
     (cond [(or (not v) (equal? v "") (equal? v "all")) 'all]
           [(equal? v "even") 'even]
           [(equal? v "odd") 'odd]
           [(equal? v "none") 'none]
           [else (error 'params
                        "SLOG_NATIVE_COVERAGE must be all|even|odd|none: ~a"
                        v)]))))

;; T3b slice 1: the selective-compilation POLICY behind T4's mechanism
;; (docs/execution-tiers.md §5.3, docs/t3b-contract.md).  'classified applies
;; the default rule-variant classification -- interp-only variants are not
;; emitted, and a stratum whose every variant is interp-only skips the
;; toolchain entirely.  'all restores pre-T3b behavior (emit every rule) and
;; is the escape hatch plus the differential control.  Cache-keyed in
;; compile.rkt beside native-rule-coverage: an artifact built under one
;; policy must never stand in for one built under the other.
;;
;; The env var, when set, is a HARD choice that holds in every mode -- it is
;; the gate's lever and the differential control.  Left unset, the policy
;; follows §5.3's own scoping ("the default `tiered` now means selective per
;; this section"): selective under tiered, off under the explicit -O0/-O2
;; modes, which mean "compile it all" (compile-strata resolves that).
(define tier-policy
  (make-parameter
   (let ([v (getenv "SLOG_TIER_POLICY")])
     (cond [(or (not v) (equal? v "") (equal? v "classified")) 'classified]
           [(equal? v "all") 'all]
           [else (error 'params
                        "SLOG_TIER_POLICY must be classified|all: ~a" v)]))))

(define tier-policy-pinned?
  (let ([v (getenv "SLOG_TIER_POLICY")]) (and v (not (equal? v "")) #t)))

;; T3b slice 2: the tier-profile sidecar (docs/t3b-contract.md §3 slice 2,
;; tier-profile.rkt).  Runtime feedback recorded per KernelPlanKey under
;; build/profile/; consulted on the cold tiered arm to skip the toolchain for
;; kernels whose fixpoint historically beats their build.  Deliberately NOT
;; in the .so cache key: profiles decide whether builds are scheduled, never
;; what is emitted.  SLOG_TIER_PROFILE=0|off disables both recording and
;; consulting -- the mechanism batteries' pin and the differential control.
(define tier-profile-enabled
  (make-parameter
   (let ([v (getenv "SLOG_TIER_PROFILE")])
     (not (member v '("0" "off"))))))

;; The consult rule's ceiling: an interp-started run counts as "interp
;; sufficed" only when its daemon-reported fixpoint wall time stayed at or
;; under this.  Above it, interpreting was slow enough that a compile would
;; pay even if the fixpoint won the race this once (a saturated pool must
;; not teach the profile that a hot kernel is cheap).  Well under any
;; observed O0 build (seconds); deliberately conservative.
(define tier-skip-max-ms
  (make-parameter
   (let ([v (getenv "SLOG_TIER_SKIP_MS")])
     (or (and v (string->number v)) 2000))))

;; T3b slice 3: the promotion budget (docs/t3b-contract.md §3 slice 3,
;; execution-tiers §5.3's promotion feedback path).  A profile-skipped
;; stratum that interprets past this wall-clock budget without fixpointing
;; launches its build mid-run and attaches at the next safe boundary --
;; the §12.12 self-rescue.  The contract's eventual form is "a small
;; multiple of estimated O0 compile cost"; until slice 4's arbiter records
;; build costs this is a fixed ceiling, kept ABOVE the skip ceiling so a
;; stratum the profile admitted has real room before the rescue fires.
;; Like the other profile knobs it schedules builds only -- never emitted
;; content -- so it is not cache-keyed.
(define tier-promote-ms
  (make-parameter
   (let ([v (getenv "SLOG_TIER_PROMOTE_MS")])
     (or (and v (string->number v)) 4000))))

;; Exhaustive action search is deliberately bounded.  Larger join bodies use
;; the deterministic action-aware greedy fallback.
(define wcoj3-search-cap (make-parameter 8))

;; Delta-entry flavor (docs/incremental.md §0.5 mode 3, 0.B5): when set, a
;; stratum is re-planned with its positive table/struct INPUTS marked
;; dynamic -- per-position delta-driven versions replace the run-once full
;; scans -- and its plugin registers under beginStratumDelta (no reload:
;; the staged batch IS iteration-0's delta).  Emitted to distinct
;; build/<hash>_delta.* artifacts by ensure-delta-so (compile.rkt); never
;; on for the base artifacts, so it needs no cache-key entry.
(define delta-entry-flavor (make-parameter #f))

;; Signed support maintenance.  This is paired with `count-flavor`'s
;; count-mode value so planning/lowering retain rule support classifications
;; and instantiation-injective staging temps, but unlike the `_count` recount
;; flavor it uses ordinary exact delta variants and maintains live indices.
;; Values are #f, 'positive (M1), 'negative (M3), or 'negative-rec (M4T).
;; Both negative flavors share the dual exact partition and -1 contributions;
;; 'negative-rec additionally puts the maintenance interner in DRed mode
;; (docs/m4t-contract.md): over-delete on foundation loss with the sidecar
;; entry retained, and dead candidates absorb later decrements.
(define maintenance-flavor (make-parameter #f))

(define (negative-maintenance-flavor?)
  (memq (maintenance-flavor) '(negative negative-rec)))

(define (dred-maintenance-flavor?)
  (eq? (maintenance-flavor) 'negative-rec))

;; The `_count` flavor (docs/incremental.md §8B.1/§6.2, M0): the count-round
;; plugin.  Every rule is planned as ONE all-full fire-once version (the
;; seeded-rule plan shape, registered once) with counting sinks in place of
;; the dedup-skipping emits; staging temps are widened to the parent's full
;; enumeration signature (instantiation-injective, the 2026-07-11 temps
;; decision); registers under beginStratumDelta (no reload -- the count
;; round runs OVER the resident settled fixpoint; fresh join orderings are
;; backfilled by addIndex).  Value is #f, or a `count-mode`:
;;   dynamic-rels -- the stratum's true (head-based) dynamic set, used ONLY
;;                   to classify rules rec/nonrec (§6.4); the plan itself
;;                   runs with an empty dynamic set (all-full joins).
;;   kinds        -- mutable hash, rule prov -> 'input|'nonrec|'rec, written
;;                   by plan-stratum and read at lowering (all within one
;;                   emit-stratum-cpp dynamic extent).  Staged sub-rules
;;                   share the original rule's prov, so the whole chain
;;                   inherits its classification.
;; Emitted to distinct build/<hash>_count.* artifacts by ensure-count-so
;; (compile.rkt); never on for the base artifacts -> no cache-key entry.
(struct count-mode (dynamic-rels kinds) #:transparent)
(define count-flavor (make-parameter #f))
