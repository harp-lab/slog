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

           ;; collections (docs/primitives.md M2.1): canonical finite maps/
           ;; sets as interned Patricia-trie values in the daemon's collection
           ;; arena (daemon/arena.h).  Keys and values are arbitrary words, so
           ;; everything is `any` until the typed (set T)/(map K V) layer
           ;; (M2.3) narrows these.  A set is a map-to-unit (cins/cmem).
           ;; cmerge is left-biased; cget faults on absence (guard with chas).
           cmap   (fun -> any)
           cput   (fun any any any -> any)
           cget   (fun any any -> any)
           chas   (fun any any -> int)
           cmerge (fun any any -> any)
           cdel   (fun any any -> any)
           cdiff  (fun any any -> any)
           csize  (fun any -> int)
           cins   (fun any any -> any)
           cmem   (fun any any -> int)

           ;; lattice constants and transfers (docs/lattices.md).  $count is
           ;; the base type of (count) -- not lexable as a user type name, so
           ;; only these primitives and count-lattice columns inhabit it.
           ;; (top) is flat's top; it types as `any` and the monotone-use
           ;; calculus (lattice-check.rkt) polices where it may land.
           one   (fun -> $count)
           inf   (fun -> $count)
           cplus (fun $count $count -> $count)
           top   (fun -> any))))
