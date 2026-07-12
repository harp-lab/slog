#lang racket

;; Stream-equivalence fuzzer (docs/incremental.md §10 / 0.E4, the core
;; Phase 0 test): split a random EDB into base + signed batches, stream
;; the batches into a live session flush by flush, and assert the final
;; content equals a from-scratch run on the equivalent edited program.
;; With a save name, additionally saves the fed session and replays it in
;; a fresh daemon (W3/W4), asserting the load reproduces the same content.
;;
;;   racket tests/api/stream-fuzz.rkt SEED [SAVE-NAME]
;;
;; Generation discipline: adds draw from a fresh pool (an edge is never
;; re-added once retired), and deletions target currently-present input
;; edges at the tip.  Re-adding a previously-deleted BASE fact is
;; deliberately not generated: under Phase 0 set semantics a same-version
;; add/delete pair collapses out of the log while the base fact remains
;; independently re-derivable -- the documented replay-deletion caveat,
;; resolved precisely by Phase 1's per-version input bit (§8B.5).
;;
;; Prints "fuzz-ok SEED" on success; exits 1 with a diff on divergence.

(require "../../compiler/session.rkt")

(define args (current-command-line-arguments))
(define seed (string->number (vector-ref args 0)))
(define save-name (and (> (vector-length args) 1) (vector-ref args 1)))
(random-seed seed)

(define rules #<<EOF
table (edge int int)
table (path int int)

rule
(edge X Y)
-->
(path X Y)

rule
(path X Y)
(edge Y Z)
-->
(path X Z)
EOF
)

(define (write-prog path es)
  (call-with-output-file path #:exists 'replace
    (lambda (o)
      (displayln rules o)
      (newline o)
      (displayln "rule" o)
      (for ([e (in-list (sort es (lambda (a b)
                                   (or (< (car a) (car b))
                                       (and (= (car a) (car b))
                                            (< (cdr a) (cdr b)))))))])
        (fprintf o "(edge ~a ~a)\n" (car e) (cdr e))))))

;; a random edge set over 8 nodes: 6 base edges + a fresh-add pool
(define nodes 8)
(define all-edges
  (for*/list ([i (in-range nodes)] [j (in-range nodes)] #:unless (= i j))
    (cons i j)))
(define chosen (take (shuffle all-edges) 14))
(define-values (base-edges pool0) (split-at chosen 6))

;; stream plan: 3 flushes, each adding 1-3 fresh edges and (sometimes)
;; deleting a present one; `model` tracks the expected final input EDB
(define-values (flushes model)
  (let loop ([k 3] [pool pool0] [present (list->set base-edges)]
             [deleted (set)] [acc '()])
    (cond
      [(zero? k) (values (reverse acc) present)]
      [else
       (define n-adds (add1 (random 3)))
       (define adds (take pool (min n-adds (length pool))))
       (define delables
         (for/list ([e (in-set present)] #:unless (set-member? deleted e)) e))
       (define dels
         (if (and (pair? delables) (zero? (random 2)))
             (list (list-ref delables (random (length delables))))
             '()))
       (loop (sub1 k) (drop pool (length adds))
             (set-subtract (set-union present (list->set adds))
                           (list->set dels))
             (set-union deleted (list->set dels))
             (cons (list adds dels) acc))])))

(define base-prog (format "out/fuzz-~a-base.slog" seed))
(define oracle-prog (format "out/fuzz-~a-oracle.slog" seed))
(write-prog base-prog base-edges)
(write-prog oracle-prog (set->list model))

;; dump one relation's rendered rows, sorted
(define (dump-rows s rel)
  (define rows '())
  (session-action! s `(dump-rel ,rel)
    (lambda (out)
      (let loop ()
        (define l (read-line out))
        (cond
          [(eof-object? l) (void)]
          [(regexp-match? #px"^\\(dumpdone " l) (void)]
          [(regexp-match #px"^\\(dumprow (.*)\\)\\s*$" l)
           => (lambda (m) (set! rows (cons (cadr m) rows)) (loop))]
          [else (loop)]))))
  (sort rows string<?))

(define (run-session! thunk)
  (define s (make-session))
  (define result (call-with-values (lambda () (thunk s)) list))
  (session-close! s)
  (apply values result))

;; 1. the streamed session
(define-values (edge-live path-live)
  (run-session!
   (lambda (s)
     (session-run! s base-prog)
     (for ([f (in-list flushes)])
       (match-define (list adds dels) f)
       (for ([e (in-list adds)]) (session-batch! s '+ 'edge (list (car e) (cdr e))))
       (for ([e (in-list dels)]) (session-batch! s '- 'edge (list (car e) (cdr e))))
       (session-flush! s))
     (when save-name (session-save! s save-name))
     (values (dump-rows s 'edge) (dump-rows s 'path)))))

;; 2. the from-scratch oracle on the equivalent edited EDB
(define-values (edge-oracle path-oracle)
  (run-session!
   (lambda (s)
     (session-run! s oracle-prog)
     (values (dump-rows s 'edge) (dump-rows s 'path)))))

(define (check! label got want)
  (unless (equal? got want)
    (eprintf "fuzz-FAIL seed ~a (~a):\n  streamed: ~s\n  oracle:   ~s\n"
             seed label got want)
    (exit 1)))

(check! "edge" edge-live edge-oracle)
(check! "path" path-live path-oracle)

;; 3. W3/W4: the saved session replays to the same content
(when save-name
  (define-values (edge-loaded path-loaded)
    (run-session!
     (lambda (s)
       (session-open! s save-name)
       (values (dump-rows s 'edge) (dump-rows s 'path)))))
  (check! "edge after load" edge-loaded edge-oracle)
  (check! "path after load" path-loaded path-oracle))

(printf "fuzz-ok ~a\n" seed)
