#lang racket

;; The W5' exit demo (docs/roadmap.md, "Capstone gate, stated as a demo"):
;; at the REPL's dispatch surface, edit one rule of a loaded two-instance
;; analysis; the successor image seals (the producer leg, done by
;; build-joint-fixtures before this drive), activates, and heals
;; incrementally; `whynot` answers about THE SAME FACT before and after.
;;
;;   racket tests/api/w5-demo-drive.rkt BASE.slog FIXTURE.pcs
;;
;; Emits one `(w5 NAME 0|1)` record per check; the battery pins them to 1.
;; The story, concretely: ONE rule of the right instance's lib is edited
;; -- transitivity out, reversal in (the A3-proven clustering-stable
;; shape; an edit that changes the SCC clustering is the correctness-first
;; route's recorded typed refusal).  (right.path 1 4), present and
;; derivable before, loses its support and gains none; (right.path 2 1)
;; appears through the new rule.  The left instance, seed, right.edge, and
;; the struct-valued marks all carry, which the resolved plan attests.

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

(define (check name ok?) (printf "(w5 ~a ~a)\n" name (if ok? 1 0)))

;; ---- the loaded analysis ---------------------------------------------------
(void (run (format "run ~a" base-path)))
(define s (ensure-session! state))

(check 'base-closure (regexp-match? #px"9 rows" (run "count answer")))
(define marks-before (run "?(marks P)"))
(check 'base-marks (regexp-match? #px"2 row" (run "count marks")))

;; ---- BEFORE: the same fact, both directions --------------------------------
(define whynot-before (run "whynot (right.path 1 4)"))
(check 'whynot-before-is-present
       (regexp-match? #px"is present" whynot-before))

(void (run "watch right.path level 1 why"))
(session-rerun! s 'right.path)
(define why-before (run "why (right.path 1 4)"))
(check 'why-before-derives-via-v1
       (and (regexp-match? #px"w5-demo-lib\\.slog" why-before)
            (regexp-match? #px"\\(right\\.path 1 3\\)" why-before)))

;; ---- THE ACTIVATION: the sealed successor, substituted live ----------------
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
               (lambda () (error 'w5-demo-drive "no version for ~a" rel))))))
(define plan (session-activate! s (read (open-input-string substituted))))
(check 'activation-committed (activation-plan? plan))

;; the plan's OWN dispositions attest the heal's shape: exactly the edited
;; rule's cone rebuilds; the untouched instance, the struct-valued marks,
;; and right.edge inside the edited instance all carry
(define allocs (activation-plan-version-allocs plan))
(define (disposition-of rel)
  (match (hash-ref allocs rel #f) [(list _ _ d) d] [_ #f]))
(check 'rebuild-exactly-the-cone
       (and (eq? (disposition-of 'right.path) 'rebuild)
            (eq? (disposition-of 'answer) 'rebuild)
            (= 2 (for/sum ([(_ a) (in-hash allocs)])
                   (if (eq? (third a) 'rebuild) 1 0)))))
(check 'carried-outside-cone
       (and (eq? (disposition-of 'left.path) 'carry)
            (eq? (disposition-of 'right.edge) 'carry)
            (eq? (disposition-of 'marks) 'carry)
            (eq? (disposition-of 'seed) 'carry)))

;; ---- AFTER: the same fact, the successor image, the carried remainder ------
;; 3 transitive rows lost, 3 reversal rows gained: same cardinality,
;; different membership -- the presence checks below are the real claim
(check 'healed-closure (regexp-match? #px"9 rows" (run "count answer")))

(define whynot-after (run "whynot (right.path 1 4)"))
(check 'whynot-after-v2-frontier
       (and (regexp-match? #px"w5-demo-lib-v2\\.slog" whynot-after)
            (not (regexp-match? #px"is present" whynot-after))))

;; struct ids stable: the carried marks relation answers byte-identically
;; the GAINED fact derives through the successor image's new rule
(void (run "watch right.path level 1 why"))
(session-rerun! s 'right.path)
(define why-gained (run "why (right.path 2 1)"))
(check 'why-gained-after-derives-via-v2
       (and (regexp-match? #px"w5-demo-lib-v2\\.slog" why-gained)
            (regexp-match? #px"\\(right\\.path 1 2\\)" why-gained)))

(check 'struct-marks-carried
       (and (regexp-match? #px"2 row" (run "count marks"))
            (equal? marks-before (run "?(marks P)"))))

;; the untouched instance still holds its closure -- its carried version
;; answers as before, through the original image's rules
(check 'carried-instance-keeps-closure
       (regexp-match? #px"is present" (run "whynot (left.path 1 3)")))
