#lang racket

;; Unit tests for compiler/lattice-check.rkt -- the declaration occurrence
;; restrictions and the monotone-use calculus (docs/lattices.md §5), run via:
;;   cd /home/tom/slog && raco test tests/unit/
;;
;; The calculus' rejections are product surface: each §5.1 violation must
;; fail compilation with an error naming the offense.  Programs are driven
;; through the real front half of the pipeline (parse -> modules ->
;; simplify -> typecheck -> stratify -> lattice checks), so these tests
;; also pin the interplay with simplification's flattening (head transfer
;; expressions become lets) and the planner-feeding typed level.

(module+ test
  (require rackunit)
  (require racket/file)
  (require "../../compiler/modules.rkt")
  (require "../../compiler/simplification.rkt")
  (require "../../compiler/type-system.rkt")
  (require "../../compiler/stratify.rkt")
  (require "../../compiler/lattice-check.rkt")
  (require "../../compiler/ir-shared.rkt")

  (define (run-checks src)
    (define f (make-temporary-file "lattice-test-~a.slog"))
    (dynamic-wind
     void
     (lambda ()
       (with-output-to-file f #:exists 'replace (lambda () (display src)))
       (match-define `((program ,type-env ,mods ,_))
         (load-program-list (path->string f) (hash)))
       (define all-rules (foldl set-union (set) (map last (set->list mods))))
       (check-lattice-declarations type-env)
       (define typed
         (typecheck-rules type-env
                          (foldl simplify-rule (set) (set->list all-rules))))
       (define strata (stratify-rules typed))
       (check-lattice-strata strata type-env))
     (lambda () (delete-file f))))

  (define-syntax-rule (accepts name src)
    (test-case name (check-not-exn (lambda () (run-checks src)))))
  (define-syntax-rule (rejects name rx src)
    (test-case name (check-exn rx (lambda () (run-checks src)))))

  (define sssp-prelude "
lattice (cost (min int))
table (edge int int int)
table (dist int int cost)
rule (edge X Y W) --> (dist X Y W)
")

  ;; ---------------------------------------------------------------------
  ;; Accepted programs

  (accepts "sssp transfer through +"
    (string-append sssp-prelude
     "rule (dist X Y D) (edge Y Z W) --> (dist X Z (+ D W))"))

  (accepts "upward-closed guard (< V c) on min"
    (string-append sssp-prelude
     "rule (dist X Y D) (edge Y Z W) (< D 100) --> (dist X Z (+ D W))"))

  (accepts "mirrored upward-closed guard (> c V) on min"
    (string-append sssp-prelude
     "rule (dist X Y D) (edge Y Z W) (> 100 D) --> (dist X Z (+ D W))"))

  (accepts "discard via wildcard"
    (string-append sssp-prelude
     "table (reach int int)
rule (dist X Y D) (edge Y Z W) --> (dist X Z (+ D W))
rule (dist X Y _) --> (reach X Y)"))

  (accepts "cross-stratum extraction is unrestricted"
    (string-append sssp-prelude
     "table (report int int int)
rule (dist X Y D) (edge Y Z W) --> (dist X Z (+ D W))
rule (dist X Y D) (= D 12) --> (report X Y D)"))

  (accepts "count: (= C (inf)) is upward-closed in-SCC; cplus is the evolution op"
    "lattice (card (count))
table (bind int int)
table (mu int card)
rule (bind S A) --> (mu A (one))
rule (bind S1 A) (bind S2 A) (/= S1 S2) --> (mu A (inf))
rule (mu A C) (= C (inf)) (bind S A) --> (mu S (cplus C (one)))")

  (accepts "flat identity propagation"
    "union (value (vnum int))
lattice (fv (flat value))
table (assignc int int value)
table (flow int int)
table (regval int int fv)
rule (assignc L R K) --> (regval L R K)
rule (flow L L2) (regval L R V) --> (regval L2 R V)")

  (accepts "monotone * by nonnegative literal"
    (string-append sssp-prelude
     "rule (dist X Y D) (edge Y Z W) --> (dist X Z (* D 2))"))

  ;; ---------------------------------------------------------------------
  ;; Rejected programs: each §5.1 violation with its intended error

  (rejects "lattice value into a plain head column"
    #rx"cannot be emitted into"
    (string-append sssp-prelude
     "table (leak int)
rule (dist X Y D) (edge Y Z W) --> (dist X Z (+ D W)) (leak D)"))

  (rejects "lattice value as a join key"
    #rx"join key"
    (string-append sssp-prelude
     "rule (dist X Y D) (edge D Z W) --> (dist X Z W)"))

  (rejects "downward-closed guard (> V c) on min"
    #rx"not an upward-closed guard"
    (string-append sssp-prelude
     "rule (dist X Y D) (edge Y Z W) (> D 3) --> (dist X Z (+ D W))"))

  (rejects "comparison between two live lattice values"
    #rx"comparing two still-ascending"
    (string-append sssp-prelude
     "table (edge2 int int int)
rule (edge X Y W) --> (edge2 X Y W)
rule (dist X Y D) (dist Y Z D2) (< D D2) (edge Y Z W) --> (dist X Z (+ D W))"))

  (rejects "antitone (- x V)"
    #rx"not a whitelisted monotone transfer"
    (string-append sssp-prelude
     "rule (dist X Y D) (edge Y Z W) --> (dist X Z (- W D))"))

  (rejects "* by a variable multiplier"
    #rx"not a whitelisted monotone transfer"
    (string-append sssp-prelude
     "rule (dist X Y D) (edge Y Z W) --> (dist X Z (* D W))"))

  (rejects "(= C (one)) in-SCC: the strong-update bug"
    #rx"not upward-closed"
    "lattice (card (count))
table (bind int int)
table (mu int card)
rule (bind S A) --> (mu A (one))
rule (mu A C) (= C (one)) (bind S A) --> (mu A (inf))")

  (rejects "disequality on a live lattice value"
    #rx"disequality"
    (string-append sssp-prelude
     "rule (dist X Y D) (dist X Z D2) (/= D D2) --> (dist Y Z D)"))

  (rejects "implicit meet: one variable, two live lattice reads"
    #rx"implicit meet"
    (string-append sssp-prelude
     "rule (dist X Y D) (dist Y Z D) --> (dist X Z D)"))

  (rejects "constant in a live value position"
    #rx"plain variable"
    (string-append sssp-prelude
     "table (found int int)
rule (dist X Y 5) (dist X Y D) --> (dist Y X D)"))

  (rejects "(top) contributed to a non-flat lattice"
    #rx"lattice constant"
    (string-append sssp-prelude
     "rule (edge X Y W) --> (dist X Y (top))"))

  (rejects "live lattice value inside a struct construction"
    #rx"struct"
    (string-append sssp-prelude
     "struct (pair int int)
table (out pair)
rule (dist X Y D) (edge Y Z W) --> (dist X Z (+ D W)) (out (pair X D))"))

  ;; dist and dist3 are mutually recursive (one SCC), so the dist read is
  ;; still-ascending -- and its (min int) does not match dist3's clamped
  ;; (min int (floor 0)).  Without the wildcard back-edge the strata would
  ;; separate and the cross-stratum unwrap would make this legal.
  (rejects "cross-lattice contribution"
    #rx"does not match target"
    (string-append sssp-prelude
     "lattice (cost3 (min int #:floor 0))
table (dist3 int int cost3)
rule (dist3 X Y _) (edge X Y W) --> (dist X Y W)
rule (dist X Y D) (edge Y Z W) --> (dist3 X Z (+ D W))"))

  ;; ---------------------------------------------------------------------
  ;; Declaration occurrence restrictions

  (rejects "lattice type as a struct field"
    #rx"struct"
    "lattice (cost (min int))
struct (pair cost int)
table (t pair)")

  (rejects "lattice type in a non-final column"
    #rx"last column"
    "lattice (cost (min int))
table (dist int cost int)")

  (rejects "two lattice columns"
    #rx"at most one"
    "lattice (cost (min int))
table (dist int cost cost)")

  (rejects "keyless map"
    #rx"at least one key"
    "lattice (cost (min int))
table (best cost)")

  (rejects "flat of a lattice type"
    #rx"cannot itself be a lattice"
    "lattice (cost (min int))
lattice (fc (flat cost))
table (t int fc)")

  (rejects "lattice type as a demand input (demands are interned structs)"
    #rx"struct"
    "lattice (cost (min int))
demand (f cost) int
facts (f 3 4)"))
