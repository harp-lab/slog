#lang racket

;; M6L transactional/recovery audit.  Contributor recount failures must retain
;; the last committed cache; maintenance overflow must settle through fallback,
;; invalidate cache state, heal on recount, and leave no stale replacement in
;; the following epoch.

(require "../../compiler/session.rkt")

(define transcript '())
(define (record! line) (set! transcript (cons line transcript)))

(define (one-line out)
  (define line (read-line out))
  (when (eof-object? line) (error 'lattice-recovery "daemon EOF"))
  line)

(define (action-line s spec)
  (session-action! s spec one-line))

(define (dump-lines s spec done-rx row-rx)
  (define rows '())
  (session-action!
   s spec
   (lambda (out)
     (let loop ()
       (define line (read-line out))
       (cond
         [(eof-object? line) (error 'lattice-recovery "daemon EOF during dump")]
         [(regexp-match? done-rx line) (void)]
         [(regexp-match? row-rx line) (set! rows (cons line rows)) (loop)]
         [else (loop)]))))
  (sort rows string<?))

(define (counts s rel)
  (dump-lines s `(dump-counts ,rel) #px"^\\(countdone " #px"^\\(countrow "))

(define (tuples s rel)
  (dump-lines s `(dump-tuples ,rel) #px"^\\(tupledone " #px"^\\(tuplerow "))

(define (contributor-state s)
  (action-line s `(lattice-contributor-state)))

(define (expect-failure who thunk pattern)
  (define failed? #f)
  (with-handlers ([exn:fail?
                   (lambda (e)
                     (set! failed? (regexp-match? pattern (exn-message e))))])
    (thunk))
  (unless failed? (error 'lattice-recovery "~a did not fail as expected" who)))

(define s (make-session #:echo record!))
(dynamic-wind
 void
 (lambda ()
   (session-run! s "tests/session/m6l_stratified.slog")
   (session-batch! s '+ 'offer '(1 9))
   (session-batch! s '+ 'alias '(1 5))
   (session-flush! s)
   (define baseline-best (counts s 'best))
   (define baseline-reported (counts s 'reported))
   (define baseline-state (contributor-state s))

   (expect-failure
    'injected-recount
    (lambda ()
      (session-recount! s #:force? #t #:lattices? #t #:fail-after 1))
    #rx"injected recount failure")
   (unless (and (equal? baseline-best (counts s 'best))
                (equal? baseline-reported (counts s 'reported))
                (equal? baseline-state (contributor-state s)))
     (error 'lattice-recovery "failed recount changed committed state"))

   (expect-failure
    'writer-coverage
    (lambda ()
      (session-recount! s #:force? #t #:lattices? #t #:omit-writer 1))
    #rx"semantic writer coverage mismatch")
   (unless (and (equal? baseline-best (counts s 'best))
                (equal? baseline-reported (counts s 'reported))
                (equal? baseline-state (contributor-state s)))
     (error 'lattice-recovery "writer audit changed committed state"))

   (session-recount! s #:force? #t #:lattices? #t)
   (unless (regexp-match? #px"\\(lcnt best 0 1\\)" (contributor-state s))
     (error 'lattice-recovery "successful recount did not certify best"))

   ;; Two distinct rules emit the same contributor.  With a test ceiling of
   ;; one, the second support invalidates maintenance and forces a full rerun.
   (void (action-line s `(count-test-max 1)))
   (set! transcript '())
   (session-batch! s '+ 'offer '(2 7))
   (session-batch! s '+ 'alias '(2 7))
   (session-flush! s)
   (unless (and (member "(tuplerow 2 7)" (tuples s 'best))
                (member "(tuplerow 2 7)" (tuples s 'reported))
                (for/or ([line (in-list transcript)])
                  (regexp-match? #px"^\\(route rerun " line))
                (for/or ([line (in-list transcript)])
                  (regexp-match? #px"^\\(update-committed .* counts-invalid\\)" line))
                (regexp-match? #px"\\(lcnt best 0 0\\)" (contributor-state s)))
     (error 'lattice-recovery "overflow did not settle through invalidating fallback"))

   (void (action-line s `(count-test-max 4294967295)))
   (session-recount! s #:force? #t #:lattices? #t)
   (unless (and (member "(countrow best 2 7 0 2 0)" (counts s 'best))
                (member "(countrow reported 2 7 0 1 0)" (counts s 'reported)))
     (error 'lattice-recovery "healed contributor/consumer counts are wrong"))

   ;; The visible value remains 7 when one duplicate support disappears.  A
   ;; stale replacement left by the failed epoch would perturb reported here.
   (set! transcript '())
   (session-batch! s '- 'offer '(2 7))
   (session-flush! s)
   (unless (and (not (for/or ([line (in-list transcript)])
                       (regexp-match? #px"^\\(route rerun " line)))
                (member "(countrow best 2 7 0 1 0)" (counts s 'best))
                (member "(countrow reported 2 7 0 1 0)" (counts s 'reported))
                (regexp-match? #px"\\(lcnt best 0 1\\)" (contributor-state s)))
     (error 'lattice-recovery "post-recovery epoch saw stale replacement state"))

   (printf "m6l-recovery-ok\n"))
 (lambda () (session-close! s)))
