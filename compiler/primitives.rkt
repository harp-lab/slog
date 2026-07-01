#lang racket

(provide prim-fun-env)

;; The environment of built-in *value-producing* primitives (used as
;; `(= r (op args ...))`, i.e. let-bound).  Polymorphic type vars A/B/C are the
;; compiler's "any escape hatch" (type-system.rkt) -- runtime dispatch in
;; daemon/prims.h picks the concrete kernel (int vs float) and issues a fatal on
;; an unsupported combination.
;;
;; Ordering comparisons (< <= > >=) are NOT here: they are body *guards*
;; (filters, like /=), recognized structurally via preds.rkt's primitive-cmp?.
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
           substr (fun str int int -> str))))
