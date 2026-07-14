#lang racket

;; M6L slice-2 pause/resume stress.  A wide winning-contributor deletion
;; regresses every key and drives both halves of the replacement schedule.

(require "../../compiler/session.rkt")

(define args (current-command-line-arguments))
(define n (if (positive? (vector-length args))
              (string->number (vector-ref args 0))
              240))
(unless (exact-positive-integer? n)
  (error 'lattice-pause-stress "expected a positive key count"))

(define transcript '())
(define (record! line) (set! transcript (cons line transcript)))

(define (count-rows s rel)
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

(define s (make-session #:echo record!))
(dynamic-wind
 void
 (lambda ()
   (session-run! s "tests/session/m6l_stratified.slog")
   (for ([key (in-range n)])
     (session-batch! s '+ 'offer (list key 0))
     (session-batch! s '+ 'alias (list key 1)))
   (session-flush! s)
   (for ([key (in-range n)])
     (session-batch! s '- 'offer (list key 0)))
   (session-flush! s)

   (define maintained-best (count-rows s 'best))
   (define maintained-reported (count-rows s 'reported))
   (unless (and (= (length maintained-best) n)
                (= (length maintained-reported) n)
                (for/and ([key (in-range n)])
                  (member (format "(countrow best ~a 1 0 1 0)" key)
                          maintained-best))
                (for/and ([key (in-range n)])
                  (member (format "(countrow reported ~a 1 0 1 0)" key)
                          maintained-reported)))
     (error 'lattice-pause-stress "wrong maintained replacement rows"))

   (session-recount! s #:force? #t #:lattices? #t)
   (unless (and (equal? maintained-best (count-rows s 'best))
                (equal? maintained-reported (count-rows s 'reported)))
     (error 'lattice-pause-stress "maintained sidecars differ from recount"))
   (unless (for/or ([line (in-list transcript)])
             (regexp-match? #px"^\\(paused " line))
     (error 'lattice-pause-stress
            "time budget did not force a pause; increase N or lower SLOG_MAX_MS"))
   (unless (for/or ([line (in-list transcript)])
             (regexp-match? #px"^\\(route maintain-lattice-consumers-negative " line))
     (error 'lattice-pause-stress "slice-2 route was not selected"))
   (when (for/or ([line (in-list transcript)])
           (regexp-match? #px"^\\(route rerun " line))
     (error 'lattice-pause-stress "unexpected fallback"))
   (printf "m6l-pause-stress-ok ~a pauses=~a\n"
           n
           (count (lambda (line) (regexp-match? #px"^\\(paused " line))
                  transcript)))
 (lambda () (session-close! s)))
