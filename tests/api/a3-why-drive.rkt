#lang racket
;; Spine A3's debugging leg (docs/activation-contract.md §5): why/whynot
;; before AND after a live two-instance activation, against ONE session --
;; the REPL surface and the activation transaction narrating the same
;; state.  Emits one `(a3 NAME 0|1)` record per check; the battery pins
;; them all to 1.
;;
;;   racket tests/api/a3-why-drive.rkt BASE.slog FIXTURE.pcs
;;
;; The provenance workflow is the documented one (T5): `why` explains
;; derivations CAPTURED while a provenance-armed watch covers the deriving
;; epoch, so each `why` here follows watch-arm + a monotone re-derivation
;; (session-rerun!); `whynot` is the pure frontier over committed state
;; and needs no capture.

(require racket/string
         "../../compiler/repl.rkt"
         "../../compiler/session.rkt"
         "../../compiler/activation.rkt"
         "../../compiler/catalog.rkt"
         "../../compiler/names.rkt")

(match-define (list base-path fixture-path)
  (vector->list (current-command-line-arguments)))

(putenv "SLOG_NO_MEM_CAP" "1")
(define state (make-server-state))

(define (run cmd)
  (string-join (hash-ref (dispatch-command state cmd) 'lines '()) "\n"))

(define (check name ok?) (printf "(a3 ~a ~a)\n" name (if ok? 1 0)))

(void (run (format "run ~a" base-path)))
(define s (ensure-session! state))

;; ---- BEFORE ---------------------------------------------------------------
;; arm provenance, re-derive the base content, then ask
(void (run "watch right.path level 1 why"))
(session-rerun! s 'right.path)

(define why-lost-before (run "why (right.path 8 10)"))
(check 'why-lost-before-derives
       (and (regexp-match? #px"← r[0-9]+#[0-9]+ · right#1@a3_lib\\.slog:5" why-lost-before)
            (regexp-match? #px"\\(right\\.path 8 9\\)" why-lost-before)))

(define whynot-gained-before (run "whynot (right.path 9 8)"))
(check 'whynot-gained-before-frontier
       (and (regexp-match? #px"a3_lib\\.slog" whynot-gained-before)
            (regexp-match? #px"frontier" whynot-gained-before)
            (not (regexp-match? #px"is present" whynot-gained-before))))

;; ---- THE ACTIVATION -------------------------------------------------------
;; substituted exactly as session-drive's activate op does
(define text (file->string fixture-path))
(define head (session-current-boundary s))
(define pkey (boundary-plan-program-key (last (session-boundary-history s))))
(define versions
  (for/hash ([(q v) (in-hash (boundary-environment head))])
    (values (qname->display q) v)))
(define substituted
  (regexp-replace*
   #px"@V:([A-Za-z0-9_.]+)@"
   (string-replace (string-replace text "@BASE-PROGRAM@" pkey)
                   "@BASE-BOUNDARY@" (boundary-key head))
   (lambda (_ rel)
     (hash-ref versions rel
               (lambda () (error 'a3-why-drive "no version for ~a" rel))))))
(define plan (session-activate! s (read (open-input-string substituted))))
(check 'activation-committed (activation-plan? plan))

;; ---- AFTER ----------------------------------------------------------------
(define whynot-lost-after (run "whynot (right.path 8 10)"))
(check 'whynot-lost-after-v2-frontier
       (and (regexp-match? #px"a3_lib_v2\\.slog" whynot-lost-after)
            (regexp-match? #px"frontier" whynot-lost-after)
            (not (regexp-match? #px"is present" whynot-lost-after))))

;; the successor version is a NEW slot: re-arm at the tip, re-derive, ask
(void (run "watch right.path level 1 why"))
(session-rerun! s 'right.path)

(define why-gained-after (run "why (right.path 9 8)"))
(check 'why-gained-after-derives-via-v2
       (and (regexp-match? #px"← r[0-9]+#[0-9]+ · right#1@a3_lib_v2\\.slog:5" why-gained-after)
            (regexp-match? #px"\\(right\\.path 8 9\\)" why-gained-after)))

;; and the carried instance still explains through the ORIGINAL lib: the
;; untouched image's rules survived the activation untouched
(define whynot-left (run "whynot (left.path 9 8)"))
(check 'whynot-carried-instance-v1-rules
       (and (regexp-match? #px"a3_lib\\.slog" whynot-left)
            (not (regexp-match? #px"a3_lib_v2" whynot-left))))
