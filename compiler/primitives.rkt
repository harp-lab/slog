#lang racket

(provide prim-fun-env
         prim-partial?)

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

           ;; strings (docs/sequences.md §6: one type, two representations
           ;; -- monolithic under the byte threshold, tag-4 ropes above it;
           ;; every op dispatches and normalizes).  Indexing is CODEPOINTS;
           ;; substr clamps (D5); sidx/schar/s2i/s2f are PARTIAL (absence/
           ;; unparsable is data).  ssplit/sjoin bridge to [str] lists.
           size   (fun any -> int)
           substr (fun str int int -> str)
           sidx   (fun str str -> int)
           shas   (fun str str -> int)
           schar  (fun str int -> str)
           ssplit (fun str str -> cseq)
           sjoin  (fun cseq str -> str)
           s2i    (fun str -> int)
           s2f    (fun str -> float)
           i2s    (fun int -> str)
           f2s    (fun float -> str)

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
           ;; spec-aware pointwise join (docs/finish-collections.md §D):
           ;; typed here like cmerge, but NOT dispatched through prims.h --
           ;; the runtime call needs the collection-lattice spec, which no
           ;; word carries, so operationalization lowers it to a dedicated
           ;; (cjoin x spec a b) c-op from a per-rule var->spec scan and
           ;; emit-cpp calls merge_spec under the parsed spec tree
           cjoin  (fun coll coll -> coll)
           cdel   (fun coll any -> coll)
           cdiff  (fun coll coll -> coll)
           csize  (fun coll -> int)
           cins   (fun cset any -> cset)
           cmem   (fun cset any -> int)

           ;; sequences (docs/sequences.md §3.1): canonical chunked-Merkle
           ;; [T] lists as interned values in the daemon's sequence arena
           ;; (daemon/seq.h); cseq is the base type (list T) resolves to
           ;; (modules.rkt), exactly as (mapof K V) resolves to cmap.
           ;; Element types stay `any` until type-system Stage 2, same as
           ;; sets/maps.  Point ops (lref/lset/lins/ldel) and lidx are
           ;; PARTIAL (prim-partial-set below): an absent position is data.
           ;; lslice CLAMPS (the substr precedent; D5).  lsort/set2lst/
           ;; ckeys/cvals order by ascending unsigned word -- canonical,
           ;; deterministic, but NOT a semantic ordering of the values.
           lempty  (fun -> cseq)
           lpush   (fun cseq any -> cseq)
           ;; the pattern-matching entry point: v as a sequence, PARTIAL --
           ;; a non-sequence word abandons the row (bracket patterns MATCH-
           ;; FAIL on non-lists: an `any` column's int, a flat lattice's
           ;; (top)); every §5.2 chain threads through its output so the
           ;; planner orders it first by data dependency
           aslst   (fun any -> cseq)
           llen    (fun cseq -> int)
           lref    (fun cseq int -> any)
           lset    (fun cseq int any -> cseq)
           lins    (fun cseq int any -> cseq)
           ldel    (fun cseq int -> cseq)
           lcat    (fun cseq cseq -> cseq)
           lslice  (fun cseq int int -> cseq)
           lrev    (fun cseq -> cseq)
           lidx    (fun cseq any -> int)
           lmem    (fun cseq any -> int)
           lsort   (fun cseq -> cseq)
           lst2set (fun cseq -> cset)
           set2lst (fun cset -> cseq)
           ckeys   (fun cmap -> cseq)
           cvals   (fun cmap -> cseq)

           ;; lattice constants and transfers (docs/lattices.md).  $count is
           ;; the base type of (count) -- not lexable as a user type name, so
           ;; only these primitives and count-lattice columns inhabit it.
           ;; (top) is flat's top; it types as `any` and the monotone-use
           ;; calculus (lattice-check.rkt) polices where it may land.
           one   (fun -> $count)
           inf   (fun -> $count)
           cplus (fun $count $count -> $count)
           top   (fun -> any))))

;; PARTIAL prims: prims with a "no answer for this input" case that is absent
;; *data*, not a bug -- `cget` on a missing key.  Partiality is an attribute
;; consulted only at lowering (operationalization.rkt): a partial prim's let
;; becomes a `letp` c-op whose emitted call takes a trailing `bool* ok`
;; (daemon/prims.h) and whose failure abandons the row, exactly like a failed
;; join against a virtual relation -- absence = failed match.  Type errors
;; (e.g. a non-cnode map argument) STAY fatal in the runtime dispatcher.
;; Typed level and planner are untouched: partiality changes only the c-op.
(define prim-partial-set (set 'cget 'aslst 'lref 'lset 'lins 'ldel 'lidx
                              'sidx 'schar 's2i 's2f))

(define (prim-partial? f)
  (set-member? prim-partial-set f))
