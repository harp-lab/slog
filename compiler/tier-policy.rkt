#lang racket
;; T3b slice 1 -- the DEFAULT tier classification (docs/execution-tiers.md
;; §5.3, docs/t3b-contract.md §3).
;;
;; T4 slice 4 shipped the per-rule emission MECHANISM: a native artifact
;; covers a set of kernel rule ordinals and the daemon runs the exact
;; complement interpreted (`SLOG_NATIVE_COVERAGE`'s even/odd/none are that
;; mechanism's deterministic test knob).  This module supplies the POLICY the
;; mechanism was waiting for: which rule VARIANTS are worth handing to clang.
;;
;; The unit is deliberately the crule -- one planned rule variant, i.e. §5.3's
;; `RuleVariantId` -- and not the source rule and not the stratum.  A `once`
;; driver and a delta driver over the same source rule are different work with
;; different economics, and after T4 the emitter can act on that difference.
;;
;; NOTHING here reaches the canonical plan.  A tier designation is a
;; compile-time scheduling decision, not part of a kernel's semantics: it
;; rides in the .tiers sidecar and in the descriptor's covered-ordinal list.
;; The plan is a golden of record (rf1-contract slice 4) and T3b must leave
;; its bytes unmoved.

(require "ir-stack.rkt" "params.rkt")

(provide variant-tier tier-native? crule-natively-covered?
         kernel-tier-summary tier-reason
         tier-summary-sink effective-tier-policy)

;; write-cpp fills this box (when the caller supplies one) with the per-kernel
;; designations it just acted on, so compile.rkt can write the .tiers sidecar
;; and decide whether the stratum needs a toolchain invocation AT ALL -- both
;; without re-deriving the classification and without changing write-cpp's
;; return type, which several flavor paths share.
(define tier-summary-sink (make-parameter #f))

;; §5.3 scopes selectivity to the tiered regime: the explicit -O0/-O2 modes
;; mean "compile it all" and stay a full-coverage differential control.  A
;; pinned SLOG_TIER_POLICY overrides that in either direction.
(define (effective-tier-policy mode)
  (cond [tier-policy-pinned? (tier-policy)]
        [(member mode '("0" "2")) 'all]
        [else (tier-policy)]))

;; --------------------------------------------------------------------------
;; The classification
;; --------------------------------------------------------------------------

;; Body/pre ops that MULTIPLY work -- a genuine dynamic join.  Semijoin
;; filters (exists/absent*) are deliberately NOT here: §5.3 lists "filter
;; shapes" among the interp-only defaults, and a filter probes one index once
;; per candidate rather than opening a nested loop.  Keep this list in sync
;; with canonical-plan.rkt's `crule-op-rels` join arm -- that one answers
;; "which relations does this op name", this one "does this op join".
(define (join-op? op)
  (match op
    [`(,(or 'join 'join-old 'join-new 'join-tomb 'join-lat) ,_ ...) #t]
    [`(join3 ,_ ...) #t]
    [_ #f]))

(define (join-count cr)
  (+ (for/sum ([op (in-list (crule-pre cr))]) (if (join-op? op) 1 0))
     (for/sum ([op (in-list (crule-body cr))]) (if (join-op? op) 1 0))))

;; Every relation this variant READS, from every position that can hold one.
;; Mirrors canonical-plan.rkt's crule-body-rels; duplicated rather than
;; imported so a change to the plan's relation-collection cannot silently
;; re-tier every rule in the tree.
(define (read-rels cr)
  (define (op-rels op)
    (match op
      [`(,(or 'join 'join-old 'join-new 'join-tomb 'join-lat
              'exists 'absent 'absent-old 'absent-new 'absent-ever 'absent-lat)
         ,rel ,_ ...)
       (list rel)]
      [`(join3 ,_cycle ,arms ...)
       (for/list ([arm (in-list arms)])
         (match arm [`(,_view ,rel ,_ ...) rel] [_ #f]))]
      [_ '()]))
  (filter values
          (append (list (match (crule-driver cr)
                          [`(scan ,rel ,_ ...) rel]
                          [`(probe ,rel ,_ ...) rel]
                          [_ #f]))
                  (append* (map op-rels (crule-pre cr)))
                  (append* (map op-rels (crule-body cr))))))

;; A variant is ITERATED iff it reads a relation this stratum also produces:
;; that is the same test `stratum-rule-metas` uses for its per-rule `rec` bit
;; (docs/incremental.md §6.4 -- a body relation lies in the head's SCC iff it
;; is produced WITHIN the stratum), so the manifest's recursion bit and this
;; classification cannot drift apart.  It is deliberately conservative: an
;; acyclic stratum whose second rule reads the first rule's head counts as
;; iterated and keeps its artifact.
(define (iterated? cr dynamic-rels)
  (for/or ([r (in-list (read-rels cr))]) (set-member? dynamic-rels r)))

;; §5.3's three classes, as a total function on a planned variant.
;;
;;   interp-only  never compiled; the interpreter is its permanent executor
;;   o0-max       compiled to O0 when warranted; never queued for O2
;;   tiered       full ladder: interpret -> O0 -> O2
;;
;; Order matters and follows §5.3's own wording.  `once`/`seeded` variants run
;; exactly once, so nothing amortizes and the class is unconditional.  Then
;; recursion wins over join-freedom: a join-free rule inside a recursive SCC
;; still fires every iteration, and §5.3 puts "rules in recursive SCCs" in
;; `tiered` without qualification.  Only then does the join-free shape --
;; copy, rename, projection, filter -- fall to the interpreter.
(define (variant-tier cr dynamic-rels)
  (match (crule-driver cr)
    [`(once) 'interp-only]
    [`(seeded) 'interp-only]
    [_ (cond [(iterated? cr dynamic-rels) 'tiered]
             [(zero? (join-count cr)) 'interp-only]
             [else 'o0-max])]))

;; The one-word WHY, recorded in the .tiers sidecar so a surprising
;; designation is diagnosable without re-deriving it by hand.
(define (tier-reason cr dynamic-rels)
  (match (crule-driver cr)
    [`(once) 'runs-once]
    [`(seeded) 'seeded-reentry]
    [_ (cond [(iterated? cr dynamic-rels) 'iterated]
             [(zero? (join-count cr)) 'no-join]
             [else 'acyclic-join])]))

;; --------------------------------------------------------------------------
;; What the emitter asks
;; --------------------------------------------------------------------------

;; Which classes get native code.  `o0-max` and `tiered` differ in how far up
;; the ladder they are allowed to go (slice 4's queue), not in whether they
;; are emitted at all.
(define (tier-native? t) (memq t '(o0-max tiered)))

;; The emitter's question, with every knob folded in.  `flavored?` pins full
;; coverage for the _count/_maint* artifacts: they are the differential's
;; second executor and a partially covered one would compare nothing
;; (t4-contract §3 slice 4).  `ord` is the rule's ordinal WITHIN THE KERNEL,
;; which is what the even/odd test knobs bucket on.
(define (crule-natively-covered? cr ord dynamic-rels #:flavored? [flavored? #f])
  (cond
    [flavored? #t]
    [else
     (case (native-rule-coverage)
       [(none) #f]
       [(even) (even? ord)]
       [(odd)  (odd? ord)]
       ;; 'all is the MECHANISM's "no per-rule restriction" answer; the tier
       ;; policy is what decides underneath it.  SLOG_TIER_POLICY=all is the
       ;; pre-T3b escape hatch and the differential control.
       [else (or (eq? (tier-policy) 'all)
                 (tier-native? (variant-tier cr dynamic-rels)))])]))

;; --------------------------------------------------------------------------
;; The sidecar's per-kernel summary
;; --------------------------------------------------------------------------

;; (values covered-count total-count entries), entries being one
;; `(ord TIER REASON covered?)` per variant in kernel-ordinal order.
(define (kernel-tier-summary krs dynamic-rels #:flavored? [flavored? #f])
  (define entries
    (for/list ([cr (in-list krs)] [ord (in-naturals)])
      (list ord
            (variant-tier cr dynamic-rels)
            (tier-reason cr dynamic-rels)
            (and (crule-natively-covered? cr ord dynamic-rels
                                          #:flavored? flavored?)
                 #t))))
  (values (for/sum ([e (in-list entries)]) (if (fourth e) 1 0))
          (length entries)
          entries))
