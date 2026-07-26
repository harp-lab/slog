#lang racket

;; Structured consumer for the Q1 command transcript.  It reads each record as
;; a datum (rather than splitting lines), checks every page sentinel, and pins
;; pagination/cancellation plus the row set that survives an empty literal
;; probe.  The fixture uses integers so this checker does not pre-empt R2's
;; still-pending TypeDescriptor/value-handle renderer.

(define (fail! fmt . args)
  (eprintf "query-check: ~a\n" (apply format fmt args))
  (exit 1))

(define rows (make-hash))
(define ends (make-hash))

(for ([record (in-port read)])
  (match record
    [`(query-row ,(? symbol? id) (values ,(? string? renderings) ...))
     (hash-update! rows id
                   (lambda (old) (append old (list renderings))) '())]
    [`(query-end ,(? symbol? id) ,status
                 (rows ,(? exact-nonnegative-integer? count))
                 (matched ,(? exact-nonnegative-integer? matched)))
     (unless (memq status '(page paused complete cancelled))
       (fail! "unknown query status in ~s" record))
     (hash-update! ends id
                   (lambda (old)
                     (append old (list (list status count matched))))
                   '())]
    [_ (void)]))

(define (check id actual expected)
  (unless (equal? actual expected)
    (fail! "~a: got ~s, expected ~s" id actual expected)))

(define expected-rows '(("1") ("2") ("4") ("6")))
(check 'q1-rows
       (sort (hash-ref rows 'q1 '()) < #:key (compose1 string->number car))
       expected-rows)
(check 'q1-ends (hash-ref ends 'q1 '())
       '((page 2 2) (page 2 4) (complete 0 4)))

(check 'q2-row-count (length (hash-ref rows 'q2 '())) 1)
(check 'q2-ends (hash-ref ends 'q2 '())
       '((page 1 1) (cancelled 0 1)))

;; A missing string literal closes unsatisfiable without interning it.
(check 'q3-rows (hash-ref rows 'q3 '()) '())
(check 'q3-ends (hash-ref ends 'q3 '()) '((complete 0 0)))

;; A fresh query after cancellation and the literal miss observes the original
;; exact row set, providing the command-level non-mutation check.
(check 'q4-rows
       (sort (hash-ref rows 'q4 '()) < #:key (compose1 string->number car))
       expected-rows)
(check 'q4-ends (hash-ref ends 'q4 '()) '((complete 4 4)))

(check 'qcount-rows (hash-ref rows 'qcount '()) '())
(check 'qcount-ends (hash-ref ends 'qcount '()) '((complete 0 4)))
(check 'qexists-rows (hash-ref rows 'qexists '()) '())
(check 'qexists-ends (hash-ref ends 'qexists '()) '((complete 0 1)))

(printf "query-check: ok\n")
