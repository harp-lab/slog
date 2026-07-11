#lang racket

;; CLI shell over the incremental-session driver (compiler/session.rkt,
;; docs/incremental.md 0.B): one resident daemon driven through segments,
;; batches, re-entry, and versioned queries; every daemon line echoes to
;; stdout for the test harness (tests/session-tests.sh) to assert on.
;;
;;   racket tests/api/session-drive.rkt open:DB run:PROG.slog \
;;          batch+:edge,3,4 batch-:edge,2,3 flush \
;;          pipeline sizes-at:0 dump-rel:path,1 ...
;;
;; Ops, executed in order against one session:
;;   open:DB            open data/DB (segments then compile against it)
;;   run:PROG           one program segment (begin-segment boundary,
;;                      frozen imports, strata to fixpoint)
;;   batch+:REL,V,..    queue a signed tuple against the current point;
;;   batch-:REL,V,..    same-point opposite pairs collapse (§0.2)
;;   flush              apply pending batches + route by the §0.5 rule:
;;                      all-adds + monotone cone -> replay-entry (delta-
;;                      entry once 0.B5 lands); else clear-and-rerun
;;   add-tuple:REL,V,.. immediate insert (latest version, in place)
;;   del-tuple:REL,V,.. immediate retraction (rebuild minus tuple)
;;   reenter:REL        direct replay-entry (refuses non-monotone cones)
;;   rerun:REL          direct clear-and-rerun
;;   pipeline           version chains + strata positions
;;   sizes-at:P         sizes resolved at position P
;;   dump-rel:REL[,P]   dump REL (optionally at position P)
;;   sizes | schema     the existing unversioned actions
;;   write-db:DB | write-csv:DIR
;;
;; Run from the repository root.  SLOG_OPT=0 recommended (no hot-swap
;; logic here -- strata run whatever tier sbuild-runnable returns first).

(require "../../compiler/session.rkt")

(define (num-or-str v) (or (string->number v) v))

(define (parse-op s)
  (match (string-split s ":")
    [(list "open" db) `(open ,db)]
    [(list "run" prog) `(run ,prog)]
    [(list "pipeline") `(pipeline)]
    [(list "recipe") `(recipe)]
    [(list "sizes") `(sizes)]
    [(list "schema") `(schema)]
    [(list "flush") `(flush)]
    [(list "sizes-at" p) `(sizes-at ,(string->number p))]
    [(list "dump-rel" arg)
     (match (string-split arg ",")
       [(list rel) `(dump-rel ,rel)]
       [(list rel p) `(dump-rel ,rel ,(string->number p))])]
    [(list "write-db" db) `(write-db ,db)]
    [(list "write-csv" dir) `(write-csv ,dir)]
    [(list "add-tuple" arg)
     (match-define (cons rel vals) (string-split arg ","))
     `(add-tuple ,rel ,@(map num-or-str vals))]
    [(list "del-tuple" arg)
     (match-define (cons rel vals) (string-split arg ","))
     `(del-tuple ,rel ,@(map num-or-str vals))]
    [(list "batch+" arg)
     (match-define (cons rel vals) (string-split arg ","))
     `(batch + tip ,(string->symbol rel) ,(map num-or-str vals))]
    [(list "batch-" arg)
     (match-define (cons rel vals) (string-split arg ","))
     `(batch - tip ,(string->symbol rel) ,(map num-or-str vals))]
    ;; anchored batches (0.C): abatch+:P,rel,v,..  -- anchor at position P
    [(list "abatch+" arg)
     (match-define (list* p rel vals) (string-split arg ","))
     `(batch + ,(string->number p) ,(string->symbol rel) ,(map num-or-str vals))]
    [(list "abatch-" arg)
     (match-define (list* p rel vals) (string-split arg ","))
     `(batch - ,(string->number p) ,(string->symbol rel) ,(map num-or-str vals))]
    ;; bulk bin-db payload (0.C1): import-delta:DIR[,SRC=DST...]
    [(list "import-delta" arg)
     (match-define (cons dir renames) (string-split arg ","))
     `(import-delta ,dir ,(for/list ([r (in-list renames)])
                            (match-define (list a b) (string-split r "="))
                            (list (string->symbol a) (string->symbol b))))]
    ;; environment operations (0.D): rename-rel:R,S | drop-rel:R
    [(list "rename-rel" arg)
     (match-define (list from to) (string-split arg ","))
     `(rename-rel ,from ,to)]
    [(list "drop-rel" rel) `(drop-rel ,rel)]
    ;; hot-link a stored database (0.D5): link:DB[,SRC=DST...]
    [(list "link" arg)
     (match-define (cons db renames) (string-split arg ","))
     `(link ,db ,(for/list ([r (in-list renames)])
                   (match-define (list a b) (string-split r "="))
                   (list (string->symbol a) (string->symbol b))))]
    [(list "reenter" rel) `(reenter ,(string->symbol rel))]
    [(list "rerun" rel) `(rerun ,(string->symbol rel))]
    [_ (error 'session-drive "unrecognized op: ~a" s)]))

;; response readers for the query actions
(define (echo-one-line out)
  (define line (read-line out))
  (unless (eof-object? line) (displayln line)))
(define ((echo-until rx) out)
  (let loop ()
    (define line (read-line out))
    (unless (eof-object? line)
      (displayln line)
      (unless (regexp-match? rx line) (loop)))))

(module+ main
  (define ops (map parse-op (vector->list (current-command-line-arguments))))
  (define s (make-session))
  (for ([op (in-list ops)])
    (match op
      [`(open ,db) (session-open! s db)]
      [`(run ,prog) (session-run! s prog)]
      [`(batch ,sign tip ,rel ,tuple) (session-batch! s sign rel tuple)]
      [`(batch ,sign ,anchor ,rel ,tuple)
       (session-batch! s sign rel tuple #:at anchor)]
      [`(import-delta ,dir ,renames) (session-import-delta! s dir renames)]
      [`(link ,db ,renames) (session-link! s db renames)]
      [`(rename-rel ,from ,to) (session-rename! s from to)]
      [`(drop-rel ,rel) (session-drop! s rel)]
      [`(flush) (session-flush! s)]
      [`(add-tuple ,rel ,vals ...)
       (session-action! s `(add-tuple ,rel ,@vals))]
      [`(del-tuple ,rel ,vals ...)
       (session-action! s `(del-tuple ,rel ,@vals) echo-one-line)]
      [`(reenter ,rel) (session-reenter! s rel)]
      [`(rerun ,rel) (session-rerun! s rel)]
      [`(pipeline) (session-action! s `(pipeline) echo-one-line)]
      [`(recipe) (writeln (session-recipe s))]
      [`(sizes-at ,p) (session-action! s `(sizes-at ,p) echo-one-line)]
      [`(dump-rel ,rel) (session-action! s `(dump-rel ,rel)
                                         (echo-until #px"^\\(dumpdone "))]
      [`(dump-rel ,rel ,p) (session-action! s `(dump-rel ,rel ,p)
                                            (echo-until #px"^\\(dumpdone "))]
      [`(sizes)
       ;; no terminator line: rely on ordering -- the lines flush before
       ;; the next op's response and drain at close
       (session-action! s `(sizes))]
      [`(schema) (session-action! s `(schema)
                                  (echo-until #px"^\\(schema-end\\)"))]
      [`(write-db ,db) (session-action! s `(write-db ,db))]
      [`(write-csv ,dir) (session-action! s `(write-csv ,dir))]))
  (exit (if (> (session-close! s) 0) 1 0)))
