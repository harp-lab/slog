#lang racket
;; Gate S joint battery, items 1 + 4 (docs/roadmap.md §5): the session
;; workflow harness re-expressed as a REPL transcript -- staged edits
;; committing as one boundary, a level-0 watch firing at coherent barriers
;; through a DELETE-driven counted maintenance epoch with truthful counted
;; status, sidecars matching a forced recount, and a save/load round trip.
;; The runner (tests/joint-battery.sh) greps the printed transcript; this
;; driver only produces it.
(require "../../compiler/repl.rkt")

(putenv "SLOG_NO_MEM_CAP" "1")
(when (directory-exists? "data/joint_s1")
  (delete-directory/files "data/joint_s1"))
(display
 (plain-transcript
  (list "run tests/session/base.slog"
        ;; staged batches: the git index for facts (§5.2.1) -- two edits,
        ;; visible as pending, committing as ONE update epoch
        "stage +(edge 4 5) +(edge 5 6)"
        "status"
        "flush"
        ;; a level-0 watch rides the DELETE epoch's barriers (item 4).
        ;; The retracted tuple is one this session batch-added: base.slog's
        ;; own edges are ground-RULE derivations, which input retraction
        ;; honestly refuses ("derived-only").
        "watch path"
        "stage -(edge 4 5)"
        "flush"
        "watches"
        ;; sidecars vs a forced rebuild (item 2's equality instrument):
        ;; the two counts blocks must be identical
        "counts path"
        "recount force"
        "counts path"
        "unwatch w1"
        "save joint_s1"
        "open joint_s1"
        "?count (path X Y)"
        ":quit")))
