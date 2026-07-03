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
