#lang racket
;; The ProgramChangeSet conformance checker -- spine A4's handoff tool
;; (docs/activation-contract.md §7).  The program arc's producer gates on
;; THIS, with no session or daemon dependency: a fixture that parses and
;; resolves here will be accepted by the live transaction against an
;; equivalent base, and a refusal here is the same typed refusal the
;; session would surface.
;;
;;   racket tests/api/pcs-check.rkt FIXTURE.pcs
;;
;; Prints one datum: `(accepted (program KEY) (rebuild N) (carry N)
;; (retire N) (suffix N))` or the typed `(refused TYPE DETAIL ...)`.
;; Exit 0 on accept, 1 on refusal.
;;
;; Templated fixtures check too: the placeholders substitute against the
;; SYNTHETIC base identity (`p1:layer-base:0` / `b1:layer-base:0`,
;; versions `v1:layer-base:0:N` per distinct @V:rel@), which is also the
;; base activation-tests.rkt pins -- so `same fixture -> same plan` is
;; checkable across both harnesses.

(require racket/string
         "../../compiler/activation.rkt")

(match-define (list fixture-path)
  (vector->list (current-command-line-arguments)))

(define raw (file->string fixture-path))
(define vslots (make-hash))
(define substituted
  (regexp-replace*
   #px"@V:([A-Za-z0-9_.]+)@"
   (string-replace (string-replace raw "@BASE-PROGRAM@" "p1:layer-base:0")
                   "@BASE-BOUNDARY@" "b1:layer-base:0")
   (lambda (_ rel)
     (format "v1:layer-base:0:~a"
             (hash-ref! vslots rel (lambda () (hash-count vslots)))))))

(define cs (parse-change-set (read (open-input-string substituted))))

(define result
  (cond
    [(activation-refusal? cs) cs]
    [else
     ;; the synthetic base-env: every slot-lineage relation holds its
     ;; declared old VersionKey, exactly what a live catalog would answer
     (define versions
       (for/hash ([sl (in-list (change-set-slot-lineage cs))]
                  #:when (second sl))
         (values (first sl) (second sl))))
     (resolve-activation
      cs
      (base-env "p1:layer-base:0" "b1:layer-base:0" #t versions '(smt seq))
      #:layer "layer-new" #:event 1)]))

(cond
  [(activation-refusal? result)
   (writeln result)
   (exit 1)]
  [else
   (define allocs (activation-plan-version-allocs result))
   (define (n-of disp)
     (for/sum ([(_ a) (in-hash allocs)]) (if (eq? (third a) disp) 1 0)))
   (writeln `(accepted (program ,(activation-plan-program-key result))
                       (rebuild ,(n-of 'rebuild))
                       (carry ,(n-of 'carry))
                       (retire ,(n-of 'retire))
                       (suffix ,(length (activation-plan-suffix result)))))
   (exit 0)])
