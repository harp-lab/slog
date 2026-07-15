#lang racket

;; Slog's static and dynamic settings and parameters
;; Copyright (c) Thomas Gilray, et al, see License.md

(provide (all-defined-out))

(define slog-version-major 2)
(define slog-version-minor 0)
(define slog-version-revision 0)
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
