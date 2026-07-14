#lang racket

;; M6L slice-2 differential stream.  Every maintained flush is compared with
;; a fresh, unseeded clear-and-rerun session over the same normalized
;; offer/alias set.  Maintained contributor/table sidecars are also compared
;; with a forced recount after every step.

(require "../../compiler/session.rkt")

(define args (current-command-line-arguments))
(define seed (string->number (vector-ref args 0)))
(random-seed seed)

(define universe
  (for*/list ([rel '(offer alias)] [key (in-range 4)] [value (in-range 1 8)])
    (list rel key value)))
(define initial (list->set (take (shuffle universe) 9)))

;; Distinct toggles within a flush, but delete/re-add cycles and mixed batches
;; across flushes.  Multiple keys and duplicate contributors are both common.
(define-values (reverse-flushes reverse-models _final-model)
  (for/fold ([fs '()] [models (list initial)] [present initial])
            ([_ (in-range 4)])
    (define touched (take (shuffle universe) (+ 4 (random 5))))
    (define ops
      (for/list ([fact (in-list touched)])
        (list (if (set-member? present fact) '- '+) fact)))
    (define next
      (for/fold ([p present]) ([op (in-list ops)])
        (if (eq? (first op) '+)
            (set-add p (second op))
            (set-remove p (second op)))))
    (values (cons ops fs) (cons next models) next)))
(define stream (reverse reverse-flushes))
(define models (reverse reverse-models))

(define base-program "tests/session/m6l_stratified.slog")

(define (dump-tuples s rel)
  (define rows '())
  (session-action! s `(dump-tuples ,rel)
    (lambda (out)
      (let loop ()
        (define line (read-line out))
        (cond
          [(eof-object? line) (void)]
          [(regexp-match? #px"^\\(tupledone " line) (void)]
          [(regexp-match? #px"^\\(tuplerow " line)
           (set! rows (cons line rows))
           (loop)]
          [else (loop)]))))
  (sort rows string<?))

(define (snapshot s)
  (for/list ([rel '(best reported)])
    (cons rel (dump-tuples s rel))))

(define (dump-count-rows s rel)
  (define rows '())
  (session-action! s `(dump-counts ,rel)
    (lambda (out)
      (let loop ()
        (define line (read-line out))
        (cond
          [(eof-object? line) (void)]
          [(regexp-match? #px"^\\(countdone " line) (void)]
          [(regexp-match? #px"^\\(countrow " line)
           (set! rows (cons line rows))
           (loop)]
          [else (loop)]))))
  (sort rows string<?))

(define (count-snapshot s)
  (for/list ([rel '(best reported)])
    (cons rel (dump-count-rows s rel))))

(define (with-session echo proc)
  (define s (make-session #:echo echo))
  (dynamic-wind void (lambda () (proc s)) (lambda () (session-close! s))))

(define transcript '())
(define streamed
  (with-session
   (lambda (line) (set! transcript (cons line transcript)))
   (lambda (s)
     (session-run! s base-program)
     (define snapshots '())
     (define (capture! step)
       (define result (snapshot s))
       (define maintained (count-snapshot s))
       (session-recount! s #:force? #t #:lattices? #t)
       (define recounted (count-snapshot s))
       (unless (equal? maintained recounted)
         (eprintf "m6l-count-fuzz-FAIL seed ~a step ~a\n  maintained: ~s\n  recounted:  ~s\n"
                  seed step maintained recounted)
         (exit 1))
       (set! snapshots (cons result snapshots)))
     (for ([fact (in-set initial)])
       (match-define (list rel key value) fact)
       (session-batch! s '+ rel (list key value)))
     (session-flush! s)
     (capture! 0)
     (for ([ops (in-list stream)] [step (in-naturals 1)])
       (for ([op (in-list ops)])
         (match-define (list sign (list rel key value)) op)
         (session-batch! s sign rel (list key value)))
       (session-flush! s)
       (capture! step))
     (reverse snapshots))))

(when (for/or ([line (in-list transcript)])
        (regexp-match? #px"^\\(route rerun " line))
  (eprintf "m6l-fuzz-FAIL seed ~a unexpectedly rebuilt the cone\n" seed)
  (exit 1))
(unless (for/or ([line (in-list transcript)])
          (regexp-match? #px"^\\(route maintain-lattice-consumers-negative " line))
  (eprintf "m6l-fuzz-FAIL seed ~a never used the slice-2 route\n" seed)
  (exit 1))

(define oracle
  (for/list ([model (in-list models)])
    (with-session void
      (lambda (s)
        ;; A genuinely fresh database, but reuse the fixed semantic program:
        ;; install the normalized EDB in two batch actions and invoke the
        ;; ordinary clear-and-rerun oracle.  This avoids compiling a distinct
        ;; rule plugin for every randomized fact set while remaining wholly
        ;; independent of contributor state and signed maintenance.
        (session-run! s base-program)
        (for ([rel '(offer alias)])
          (define path (format "out/m6l-oracle-~a-~a.rows" seed rel))
          (call-with-output-file path #:exists 'replace
            (lambda (out)
              (for ([fact (in-set model)] #:when (eq? (first fact) rel))
                (fprintf out "~a ~a\n" (second fact) (third fact)))))
          (session-action! s `(set-overlay-int-file ,rel ,path 2)
                           (lambda (out) (void (read-line out)))))
        (session-rerun! s 'offer)
        (snapshot s)))))

(unless (equal? streamed oracle)
  (eprintf "m6l-fuzz-FAIL seed ~a\n  streamed: ~s\n  oracle:   ~s\n"
           seed streamed oracle)
  (exit 1))

(printf "m6l-fuzz-ok ~a\n" seed)
