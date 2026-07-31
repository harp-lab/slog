#lang racket
;; Gate S joint battery, item 2 (docs/roadmap.md §5): scratch rules atop a
;; counted database.  A scratch view compiles over counted state, a delete
;; routes through the scratch stratum on the precise counted flavors, a
;; watch on the scratch relation fires at the epoch's barriers, sidecars
;; match a forced recount with the scratch strata resident, and after
;; `clear scratch` the recount equality holds again over the survivors.
(require "../../compiler/repl.rkt")

(putenv "SLOG_NO_MEM_CAP" "1")
(display
 (plain-transcript
  (list "run tests/session/base.slog"
        ;; a retractable input (base.slog's own edges are rule-derived)
        "stage +(edge 4 5)"
        "flush"
        ;; the scratch view over counted state
        "table (hop2 int int) rule (hop2 X Z) <-- (edge X Y) (edge Y Z)"
        "?count (hop2 X Y)"
        "watch hop2"
        ;; the delete's cone covers the scratch stratum on counted routes
        "stage -(edge 4 5)"
        "flush"
        ;; sidecar equality with scratch strata resident
        "counts hop2"
        "recount force"
        "counts hop2"
        "unwatch w1"
        ;; retraction, then the equality holds over the survivors
        "clear scratch"
        "counts path"
        "recount force"
        "counts path"
        "?count (path X Y)"
        ":quit")))
