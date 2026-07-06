#lang racket

(provide prim-fun-env)

;; The environment of built-in *value-producing* primitives (used as
;; `(= r (op args ...))`, i.e. let-bound).  Polymorphic type vars A/B/C are the
;; compiler's "any escape hatch" (type-system.rkt) -- runtime dispatch in
;; daemon/prims.h picks the concrete kernel (int vs float) and issues a fatal on
;; an unsupported combination.
;;
;; Ordering comparisons (< <= > >=) are NOT here: they are body *guards*
;; (filters, like /=), recognized structurally via ir-shared.rkt's
;; primitive-cmp?.
(define prim-fun-env
  (apply hash
         `(;; polymorphic arithmetic (int + int, float + float; + also concats str)
           +   (fun A A -> A)
           -   (fun A A -> A)
           *   (fun A A -> A)
           /   (fun A A -> A)
           %   (fun A A -> A)
           neg (fun A -> A)
           abs (fun A -> A)
           min (fun A A -> A)
           max (fun A A -> A)
           pow (fun A A -> A)

           ;; integer bitwise / shifts
           band (fun int int -> int)
           bor  (fun int int -> int)
           bxor (fun int int -> int)
           bnot (fun int -> int)
           shl  (fun int int -> int)
           shr  (fun int int -> int)

           ;; floating-point math (arg may be int; result is float)
           sqrt  (fun A -> float)
           sin   (fun A -> float)
           cos   (fun A -> float)
           tan   (fun A -> float)
           exp   (fun A -> float)
           log   (fun A -> float)
           floor (fun A -> float)
           ceil  (fun A -> float)
           round (fun A -> float)

           ;; conversions
           tofloat (fun A -> float)
           toint   (fun A -> int)

           ;; strings
           size   (fun any -> int)
           substr (fun str int int -> str)

           ;; collections (docs/primitives.md M2.1/M2.3): canonical finite
           ;; maps/sets as interned Patricia-trie values in the daemon's
           ;; collection arena (daemon/arena.h).  One runtime representation
           ;; (a set is a map-to-unit), two static disciplines: cset for
           ;; cins/cmem, cmap for cput/cget/chas, and the builtin union
           ;; coll = {cset, cmap} for the shared ops and the (cmap) empty
           ;; seed.  Keys/values/elements stay `any` until the type-terms
           ;; rewrite (docs/type-system.md Stage 1-2) makes (set T)/(map K V)
           ;; parameters enforceable.  cmerge is left-biased on value-role
           ;; maps; cget faults on absence (guard with chas -- the planner
           ;; fires guard-feeding computes first, so the idiom protects).
           cmap   (fun -> coll)
           cput   (fun cmap any any -> cmap)
           cget   (fun cmap any -> any)
           chas   (fun cmap any -> int)
           cmerge (fun coll coll -> coll)
           cdel   (fun coll any -> coll)
           cdiff  (fun coll coll -> coll)
           csize  (fun coll -> int)
           cins   (fun cset any -> cset)
           cmem   (fun cset any -> int)

           ;; lattice constants and transfers (docs/lattices.md).  $count is
           ;; the base type of (count) -- not lexable as a user type name, so
           ;; only these primitives and count-lattice columns inhabit it.
           ;; (top) is flat's top; it types as `any` and the monotone-use
           ;; calculus (lattice-check.rkt) polices where it may land.
           one   (fun -> $count)
           inf   (fun -> $count)
           cplus (fun $count $count -> $count)
           top   (fun -> any))))
