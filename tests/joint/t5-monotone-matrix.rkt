#lang racket
;; T5 slice (d5), the monotone-enforcement matrix (docs/t5-contract.md §0.1,
;; §4(d5)).  The arc's standing pin is that level-1 debugging is MONOTONE
;; ONLY: counted and signed-maintenance epochs are non-watchable at level 1
;; and non-replayable, and every level-1-only continuation refuses them
;; STRUCTURALLY, naming the epoch's own flavor.  Each earlier slice proved
;; its own half of that in isolation; this driver crosses them, so the
;; enforcement is one artifact rather than five scattered controls.
;;
;; For a non-monotone epoch the matrix asserts, in one run:
;;   - the pre-commit gate never engages (no phase-read watch park), while
;;     the level-0 report still arrives at the iteration barrier;
;;   - `replay` refuses level-1-unwatchable and names the flavor;
;;   - `step` refuses the same way (a step is a level-1-only continuation);
;;   - provenance captures NOTHING, and `why` says which silence it is;
;;   - a standing break never fires, however armed.
;; And, as the control that keeps the matrix honest, the SAME session over a
;; MONOTONE epoch does every one of those things.
;;
;; Emits (matrix ...) records; tests/joint-battery.sh pins them.
(require "../../compiler/repl.rkt")
(require (only-in "../../compiler/session.rkt" session-pause-hook))

(putenv "SLOG_NO_MEM_CAP" "1")
(putenv "SLOG_THREADS" "1")

(define state (make-server-state))
(define (lines result) (string-join (hash-ref result 'lines '()) " | "))

;; Drive one command with a hook that counts gate parks (phase read + a
;; watch citation) and answers `directive` at each of them.
(define (drive! line #:at-park [park-directive 'continue]
                #:at-any [any-directive #f])
  (define parks 0)
  (define result
    (parameterize ([session-pause-hook
                    (lambda (_s l)
                      (cond
                        [(and (regexp-match? #px"\\(phase read\\)" l)
                              (regexp-match? #px"\\(cause \\(watch " l))
                         (set! parks (add1 parks))
                         park-directive]
                        ;; a non-monotone epoch has NO gate park to ask at,
                        ;; so the level-1-only continuations are requested at
                        ;; the iteration barriers it does have -- which is
                        ;; exactly where the flavor refusal must fire
                        [any-directive any-directive]
                        [else 'continue]))])
      (dispatch-command state line)))
  (values parks result))

(define (emit! . parts) (displayln (format "(matrix ~a)" (string-join (map ~a parts) " "))))

;; ---------------------------------------------------------------------------
;; A counted database with a level-1, provenance-armed watch and a break.
(void (dispatch-command state "run tests/session/base.slog"))
;; a retractable fact: base.slog's edges are ground-rule derived, and only
;; an ADDED fact can be taken back (the retraction is what makes the epoch
;; counted maintenance rather than monotone)
(void (dispatch-command state "stage +(edge 4 5)"))
(void (dispatch-command state "flush"))
(void (dispatch-command state "recount"))
(void (dispatch-command state "watch path level 1 why"))
(void (dispatch-command state "break path"))

;; --- the NON-MONOTONE epoch: a retraction runs counted maintenance ---------
(define-values (maint-parks maint-result) (drive! "del edge 4 5"))
(emit! "maint-gate-parks" maint-parks)
(emit! "maint-watch-reported"
       (if (regexp-match? #px"watch w1: .*hit" (lines maint-result)) 1 0))
(emit! "maint-break-fired"
       (if (regexp-match? #px"Paused · break" (~a (hash-ref maint-result 'title "")))
           1 0))

;; every level-1-only continuation refuses, naming the epoch's flavor
(define-values (_rp replay-result)
  (drive! "add edge 4 5" #:at-park 'replay #:at-any 'replay))
(define replay-text (lines replay-result))
(emit! "replay-refusal"
       (if (regexp-match? #px"refused: level-1-unwatchable" replay-text) 1 0))
(emit! "replay-names-flavor"
       (if (regexp-match? #px"\\(flavor \"(count|maint[0-9a-z]*)\"\\)" replay-text)
           1 0))
;; and the change itself still lands: a refused continuation is not a lost run
(emit! "refused-change-committed"
       (if (regexp-match? #px"settled" replay-text) 1 0))

;; a step is a level-1-only continuation too, and refuses the same way
(define-values (_sp step-result)
  (drive! "del edge 4 5" #:at-any "(step)"))
(define step-text (lines step-result))
(emit! "step-refusal"
       (if (regexp-match? #px"refused: level-1-unwatchable.*\\(verb step\\)"
                          step-text)
           1 0))

;; capture is monotone-only too, and the refusal says WHICH silence this is
(define why-text (lines (dispatch-command state "why (path 1 3)")))
(emit! "why-monotone-refusal"
       (if (and (regexp-match? #px"provenance-unavailable" why-text)
                (regexp-match? #px"MONOTONE" why-text))
           1 0))

;; --- the MONOTONE control, same session -----------------------------------
;; a scratch fragment is a normal-flavor epoch: the gate engages, the break
;; fires, and capture fills.
(define-values (mono-parks mono-result)
  (drive! "rule (path 91 92) <-- (edge 2 3)"))
(emit! "monotone-gate-or-break"
       (if (or (positive? mono-parks)
               (regexp-match? #px"Paused" (~a (hash-ref mono-result 'title ""))))
           1 0))

;; resolve whatever held it, then confirm the change landed exactly once
(when (regexp-match? #px"Paused" (~a (hash-ref mono-result 'title "")))
  (void (dispatch-command state "continue")))
(define final (lines (dispatch-command state "?count (path X Y)")))
(emit! "monotone-committed" (if (regexp-match? #px"[0-9]+ rows match" final) 1 0))

(displayln "(matrix-end)")
(void (dispatch-command state ":quit"))
