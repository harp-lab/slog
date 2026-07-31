#lang racket
;; Gate S joint battery, item 3 (docs/roadmap.md §5): quiescence over a
;; counted maintenance epoch.  The daemon parks at iteration barriers
;; while the client drives an epoch; a query issued AT the parked barrier
;; is admitted against immutable committed masters (execution-tiers
;; §6.3's quiescent-master classes) and answers from the mid-epoch
;; committed state.  The write/intern refusal class is deliberately
;; unreachable from this dispatcher (slogd.cpp query_admission: commands
;; dispatch synchronously between continues, so only idle/boundary/
;; mid-read are observable) -- documented, never fabricated.  Lease and
;; stale-generation refusals are the protocol battery's pins; this
;; driver's claim is the JOINT one: admission holds inside a counted
;; delete epoch, driven from the REPL surface.
(require "../../compiler/repl.rkt")
(require (only-in "../../compiler/session.rkt" session-pause-hook))

(putenv "SLOG_NO_MEM_CAP" "1")

(define state (make-server-state))
(define (run! line) (dispatch-command state line))

(void (run! "run tests/session/base.slog"))
(void (run! "stage +(edge 4 5)"))
(void (run! "flush"))
;; counted state established through the tip
(void (run! "recount"))
;; a level-0 watch makes the epoch PARK at its barriers (the daemon
;; pauses for cause; a bare epoch runs to fixpoint inside one continue)
(void (run! "watch path"))

(define pauses 0)
(define barrier-result #f)
(parameterize ([session-pause-hook
                (lambda (s line)
                  (set! pauses (add1 pauses))
                  ;; one query at the FIRST parked barrier of the epoch
                  (when (= pauses 1)
                    (set! barrier-result
                          (with-handlers ([exn:fail? exn-message])
                            (run! "?count (path X Y)")))))])
  (void (run! "stage -(edge 4 5)"))
  (void (run! "flush")))

(define settled (run! "?count (path X Y)"))

(define (result-count r)
  (cond
    [(string? r) (format "refused: ~a" r)]
    [(hash? r) (string-join (hash-ref r 'lines '()) " | ")]
    [else (~a r)]))

(printf "(quiescence (pauses ~a))\n" pauses)
(printf "(barrier-query ~s)\n" (result-count barrier-result))
(printf "(settled-query ~s)\n" (result-count settled))
