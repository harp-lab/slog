#lang racket
;; J3 phase 1b -- the arm-advisory sidecar (docs/join-planning-assessment.md
;; "J3").  Records, per (rule loc, choice-group gid), the arm a run's
;; selection CONVERGED on -- the daemon's per-fixpoint `(arms ...)` report,
;; of which runslog records only the converged entries -- and advises the
;; next compile to promote that arm to native coverage (tier-policy.rkt),
;; where attach pins its group.
;;
;; Unlike the tier profile (tier-profile.rkt's "never reaches the TU text
;; or the job hash" doctrine), an APPLIED advisory deliberately changes TU
;; contents -- that is what profile-guided promotion is -- so the advisory
;; set relevant to a program folds into its job hash (compile.rkt,
;; arm-advisories-fingerprint): a new or changed advisory recompiles
;; exactly the programs whose source files it names, once, and the key is
;; stable thereafter (converged picks stop changing by definition).
;;
;; Correctness is never at stake, by construction: an advisory can only
;; select a VALID SIBLING ARM of a choice group (unknown loc/gid/arm
;; advisories simply never match a crule and are ignored), and every arm
;; computes the identical instantiation set.  The risk is PERFORMANCE
;; only: a pinned arm is exempt from runtime selection, so datasets with
;; opposite skew should not share a profile (the tier profile's
;; cross-program-sharing gotcha, same shape).  Escapes: delete
;; build/profile/arms.rktd; SLOG_NO_ARM_ADVISORIES=1 (reports still
;; recorded, never consulted); or SLOG_NATIVE_ARM, the explicit override,
;; which wins outright when set.
;;
;; Store: build/profile/arms.rktd -- one hash of (cons "file.slog:LINE"
;; gid) -> arm, written atomically, merged last-wins.  Keyed by rule LOC
;; (survives job-hash re-keys, anchors across unrelated edits) plus the
;; deterministic per-kernel gid (disambiguates a rule's versions; a gid
;; shift after a program edit at worst mis-aims onto another valid group,
;; a performance-only event per the above).

(provide arm-advisory arm-advisories-fingerprint record-arm-advisories!)

(define store-path (build-path "build" "profile" "arms.rktd"))
(define table-box (box #f))

(define (load-table)
  (or (unbox table-box)
      (let ([t (with-handlers ([exn:fail? (lambda (_e) (hash))])
                 (define v (call-with-input-file store-path read))
                 (if (hash? v) v (hash)))])
        (set-box! table-box t)
        t)))

;; The advisory for one (loc, gid), or #f.  Consulted by tier-policy for
;; arm-kind crules only, so flag-off compiles never read the store's
;; content (the fingerprint below still keys the hash, deterministically).
(define (arm-advisory loc gid)
  (and loc
       (not (getenv "SLOG_NO_ARM_ADVISORIES"))
       (hash-ref (load-table) (cons loc gid) #f)))

;; The job-hash contribution: every advisory naming one of the program's
;; source-file basenames, sorted.  Filtering by basename keeps unrelated
;; programs' advisories from re-keying this one.
(define (arm-advisories-fingerprint basenames)
  (define bset (list->set basenames))
  ;; the basename is everything before the FIRST ':' -- a loc is
  ;; "file.slog:LINE:COL" (the column since 2026-09-08; module-instance
  ;; labels use '#'/'@', never ':'), so the last ':' would keep the line
  (define (loc-file loc)
    (let ([i (for/first ([j (in-naturals)]
                         [c (in-string loc)]
                         #:when (char=? c #\:))
               j)])
      (if i (substring loc 0 i) loc)))
  (sort (for/list ([(k arm) (in-hash (load-table))]
                   #:when (and (string? (car k))
                               (set-member? bset (loc-file (car k)))))
          (list (car k) (cdr k) arm))
        (lambda (a b)
          (or (string<? (first a) (first b))
              (and (string=? (first a) (first b))
                   (< (second a) (second b)))))))

;; Merge converged picks into the store, and REMOVE stale advisories for
;; groups the run reported UNCONVERGED (J3 phase 2 heal: a pinned arm that
;; betrayed mid-run unpins and reports rescues > 0 = never-converged, so
;; its advisory must not re-pin the betrayer on the next profiled run).
;; Last run wins, in both directions -- the same policy as the merge.
;; entries: (list (list loc gid arm) ...); removals: (list (cons loc gid))
(define (record-arm-advisories! entries [removals '()])
  (define t0 (load-table))
  (define t1 (for/fold ([t t0]) ([k (in-list removals)]) (hash-remove t k)))
  (define t (for/fold ([t t1]) ([e (in-list entries)])
              (hash-set t (cons (first e) (second e)) (third e))))
  (unless (equal? t t0)
    (set-box! table-box t)
    (make-parent-directory* store-path)
    (define tmp (path-add-extension store-path #".tmp"))
    (call-with-output-file tmp (lambda (o) (write t o)) #:exists 'replace)
    (rename-file-or-directory tmp store-path #t)))
