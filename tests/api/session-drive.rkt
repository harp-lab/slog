#lang racket

;; Minimal incremental-session driver (docs/incremental.md §0.4-§0.5, B0):
;; open a stored database, run one or more program segments atop it in ONE
;; resident daemon -- each preceded by a begin-segment version boundary --
;; then echo versioned queries ((pipeline), (sizes-at P), (dump-rel R P))
;; for the test harness to assert on.  This is the embryo of the Phase-0
;; routing driver (0.B4); runslog.rkt's batch flow stays the product path.
;;
;;   racket tests/api/session-drive.rkt open:DB run:PROG.slog \
;;          pipeline sizes-at:0 dump-rel:path,1 ...
;;
;; Ops, executed in order against one daemon:
;;   open:DB            open data/DB (also sets the manifest segments compile
;;                      against -- schema truth of the live session)
;;   run:PROG           compile PROG against the session manifest, send a
;;                      begin-segment boundary for its write-set, then drive
;;                      every stratum to fixpoint
;;   pipeline           emit the version chains
;;   sizes-at:P         emit sizes resolved at position P
;;   dump-rel:REL[,P]   dump REL (optionally at position P)
;;   sizes | schema     the existing unversioned actions
;;   add-tuple:REL,V,.. insert one tuple (latest version, in place)
;;   reenter:REL        cone-limited replay-entry (0.B1): re-push the cached
;;                      .so of every stratum in cone(REL) -- computed from
;;                      the last run's .meta reads/dynamic-rels -- in
;;                      pipeline order; each re-stages the whole database as
;;                      its iteration-0 delta and re-fires (set-dedup
;;                      absorbs, the batch propagates).  Errors on a
;;                      non-monotone cone (a neg/lat edge -- clear-and-rerun
;;                      is 0.B2).
;;
;; Run from the repository root.  SLOG_OPT=0 recommended (no hot-swap logic
;; here -- strata run whatever tier sbuild-runnable returns first).

(require "../../compiler/actions.rkt")
(require "../../compiler/compile.rkt")
(require "../../compiler/runslog.rkt")
(require "../../compiler/tools.rkt")

(define (parse-op s)
  (match (string-split s ":")
    [(list "open" db) `(open ,db)]
    [(list "run" prog) `(run ,prog)]
    [(list "pipeline") `(pipeline)]
    [(list "sizes") `(sizes)]
    [(list "schema") `(schema)]
    [(list "sizes-at" p) `(sizes-at ,(string->number p))]
    [(list "dump-rel" arg)
     (match (string-split arg ",")
       [(list rel) `(dump-rel ,rel)]
       [(list rel p) `(dump-rel ,rel ,(string->number p))])]
    [(list "write-db" db) `(write-db ,db)]
    [(list "write-csv" dir) `(write-csv ,dir)]
    [(list "add-tuple" arg)
     (match-define (cons rel vals) (string-split arg ","))
     `(add-tuple ,rel ,@(for/list ([v (in-list vals)])
                          (or (string->number v) v)))]
    [(list "del-tuple" arg)
     (match-define (cons rel vals) (string-split arg ","))
     `(del-tuple ,rel ,@(for/list ([v (in-list vals)])
                          (or (string->number v) v)))]
    [(list "reenter" rel) `(reenter ,(string->symbol rel))]
    [(list "rerun" rel) `(rerun ,(string->symbol rel))]
    [_ (error 'session-drive "unrecognized op: ~a" s)]))

;; Read one stratum's build/<hash>.meta: (values dynamic-rels reads) where
;; reads is the manifest's ((REL KIND ...) ...) polarity entries.  (The
;; dynamic-rels half duplicates compile.rkt's stratum-meta-dynamic-rels;
;; the reads half is harness-local until the 0.B4 routing driver promotes
;; cone assembly into the compiler proper.)
(define (read-stratum-meta h)
  (define p (format "build/~a.meta" h))
  (with-handlers ([exn:fail? (lambda (_) (values '() '()))])
    (match (call-with-input-file p read)
      [`(stratum-meta ,fields ...)
       (values (match (assq 'dynamic-rels fields)
                 [`(dynamic-rels ,r ...) r] [_ '()])
               (match (assq 'reads fields)
                 [`(reads ,entries ...) entries] [_ '()]))]
      [_ (values '() '())])))

;; cone(target) over candidate strata, in pipeline order (docs/
;; incremental.md §0.5): stratum S is in the cone iff it reads the target
;; or a relation a cone stratum below produced; the wavefront grows by each
;; cone stratum's dynamic-rels.  Entries are (list so dyn reads pos ...).
;; Returns (values cone-entries monotone?); monotone? is #f if any edge
;; INTO the cone is neg/lat.
(define (cone-strata infos target)
  (let loop ([infos infos] [wave (set target)] [acc '()] [mono? #t])
    (match infos
      ['() (values (reverse acc) mono?)]
      [(cons (and info (list-rest _so dyn reads _)) rest)
       (define hit-kinds
         (for*/list ([entry (in-list reads)]
                     #:when (set-member? wave (car entry))
                     [k (in-list (cdr entry))])
           k))
       (cond
         [(null? hit-kinds) (loop rest wave acc mono?)]
         [else
          (loop rest
                (for/fold ([w wave]) ([d (in-list dyn)]) (set-add w d))
                (cons info acc)
                (and mono? (andmap (lambda (k) (eq? k 'pos)) hit-kinds)))])])))

(module+ main
  (define ops (map parse-op (vector->list (current-command-line-arguments))))
  (ensure-slogd-exists)
  (define-values (sp out in err) (apply subprocess #f #f #f (slogd-argv "daemon/slogd")))
  (define (send-plugin path)
    (display (string-append path "\n") in)
    (flush-output in))
  (define err-thread
    (thread (lambda ()
              (let loop ()
                (define s (read-line err))
                (unless (eof-object? s) (eprintf "~a\n" s) (loop))))))
  (define continue-so (delay (action-so `(continue))))
  ;; Drive one stratum to fixpoint: echo every line; answer (paused ...) with
  ;; (continue); abort on (error ...) or EOF.
  (define (drive-to-fixpoint!)
    (let poll ()
      (define line (read-line out))
      (cond
        [(eof-object? line) (error 'session-drive "daemon EOF mid-stratum")]
        [(regexp-match? #px"^\\(fixpoint " line) (displayln line)]
        [(regexp-match? #px"^\\(paused " line)
         (displayln line)
         (send-plugin (force continue-so))
         (poll)]
        [(regexp-match? #px"^\\(error " line)
         (error 'session-drive "daemon error: ~a" line)]
        [else (displayln line) (poll)])))
  ;; Read one query action's response: single-line for pipeline/sizes-at,
  ;; sentinel-terminated for dump-rel, count-terminated for sizes/schema.
  (define (read-one-line!)
    (define line (read-line out))
    (unless (eof-object? line) (displayln line)))
  (define (read-until! rx)
    (let loop ()
      (define line (read-line out))
      (unless (eof-object? line)
        (displayln line)
        (unless (regexp-match? rx line) (loop)))))

  (define the-db #f)
  ;; per-stratum (list so-path dynamic-rels reads) of every run: segment so
  ;; far, in pipeline order -- the reenter op's cone input
  (define strata-info '())
  ;; Live introspection: (values scc->pos rel->binding-positions) from one
  ;; (pipeline) round trip.
  (define (introspect!)
    (send-plugin (action-so `(pipeline)))
    (define pline (read-line out))
    (when (eof-object? pline) (error 'session-drive "daemon EOF at introspection"))
    (displayln pline)
    (match (read (open-input-string pline))
      [`(pipeline ,_ (strata ,ss ...) ,rels ...)
       (values (for/hash ([s (in-list ss)])
                 (match-define `(s ,scc ,pos ,_name) s)
                 (values scc pos))
               (for/hash ([r (in-list rels)])
                 (match-define `(rel ,name ,vs ...) r)
                 (values name
                         (for/list ([v (in-list vs)])
                           (match-define `(v ,_ ,pos ,_sz) v)
                           pos))))]
      [x (error 'session-drive "unparseable (pipeline) reply: ~a" x)]))
  ;; cone(rel) for a latest-anchored batch: anchor at the target's last
  ;; binding, candidates = strata bound at-or-after it (earlier strata read
  ;; a PREDECESSOR version and must not re-fire; strata-info index = scc --
  ;; both count fresh pushes in order, and re-entry pushes land at higher
  ;; sccs, deliberately absent from strata-info), then the read-closure.
  ;; The rebound guard applies to BOTH re-entry modes: a re-pushed stratum
  ;; binds the LATEST environment, which equals its own position's
  ;; environment only if nothing it touches (reads or writes) was rebound
  ;; after it -- positional re-binding + boundary re-materialisation
  ;; arrives with anchored batches (0.C).
  (define (cone-of! rel)
    (define-values (strata-pos chains) (introspect!))
    (define anchor
      (let ([c (hash-ref chains rel '())])
        (if (null? c) 0 (last c))))
    (define candidates
      (for/list ([info (in-list strata-info)] [scc (in-naturals)]
                 #:when (>= (hash-ref strata-pos scc 0) anchor))
        (append info (list (hash-ref strata-pos scc 0)))))
    (define-values (cone mono?) (cone-strata candidates rel))
    (for ([info (in-list cone)])
      (match-define (list _so dyn reads pos) info)
      (for ([r (in-sequences (in-list dyn) (in-list (map car reads)))])
        (define rebound
          (for/or ([p (in-list (hash-ref chains r '()))]) (> p pos)))
        (when rebound
          (error 'session-drive
                 "~a was rebound after a cone stratum (pos ~a): latest-env re-entry is unsound here; anchored replay is 0.C"
                 r pos))))
    (values cone mono?))
  (for ([op (in-list ops)])
    (match op
      [`(open ,db)
       (set! the-db db)
       (send-plugin (action-so `(open ,db)))]
      [`(run ,prog)
       (define manifest (if the-db (db-full-manifest the-db) (hash)))
       (define-values (strata partition edb-boundary frozen-dirs)
         (compile-strata prog manifest #:split-facts? #f))
       (define ws (segment-write-set strata frozen-dirs))
       (when (pair? ws)
         (send-plugin (action-so `(begin-segment ,@ws)))
         (read-one-line!))   ; (segment P N)
       (for ([dir (in-list frozen-dirs)])
         (send-plugin (action-so `(import-path ,dir))))
       (for ([sb (in-list strata)])
         (match-define (cons so tag) ((sbuild-runnable sb)))
         (define-values (dyn reads) (read-stratum-meta (sbuild-hash sb)))
         (set! strata-info (append strata-info (list (list so dyn reads))))
         (send-plugin so)
         (drive-to-fixpoint!))]
      [`(add-tuple ,rel ,vals ...)
       (send-plugin (action-so `(add-tuple ,rel ,@vals)))]
      [`(del-tuple ,rel ,vals ...)
       (send-plugin (action-so `(del-tuple ,rel ,@vals)))
       (read-one-line!)]   ; (deleted REL 0|1)
      [`(reenter ,rel)
       ;; Replay-entry (0.B1): sound only for an all-monotone cone.
       (define-values (cone mono?) (cone-of! rel))
       (unless mono?
         (error 'session-drive
                "non-monotone cone for ~a (neg/lat edge): use rerun (clear-and-rerun, 0.B2)"
                rel))
       (printf "(reenter ~a ~a)\n" rel (length cone))
       (for ([info (in-list cone)])
         (send-plugin (first info))
         (drive-to-fixpoint!))]
      [`(rerun ,rel)
       ;; Clear-and-rerun (0.B2): sound for everything the rebound guard
       ;; admits -- deletions and non-monotone cones included.  Clear each
       ;; cone-written relation (latest version, contents only), then
       ;; re-push the cone; the re-run's iteration-0 reload stages
       ;; base + batch without the stale derivations, so the suffix runs
       ;; from scratch.  Relations also written by NON-cone strata (the
       ;; shared diagnostic side channels: error, $seq_*, ...) are exempt
       ;; from clearing -- their out-of-cone content cannot re-derive;
       ;; stale in-cone diagnostic rows are accepted for Phase 0.
       (define-values (cone _mono?) (cone-of! rel))
       (define cone-sos (for/set ([i (in-list cone)]) (first i)))
       (define cone-dyn
         (for*/set ([i (in-list cone)] [d (in-list (second i))]) d))
       (define noncone-dyn
         (for*/set ([i (in-list strata-info)]
                    #:unless (set-member? cone-sos (first i))
                    [d (in-list (second i))])
           d))
       (define clear-set
         (sort (set->list (set-subtract cone-dyn noncone-dyn)) symbol<?))
       (for ([r (in-list clear-set)])
         (send-plugin (action-so `(clear-rel ,r))))
       (printf "(rerun ~a ~a ~a)\n" rel (length cone) (length clear-set))
       (for ([info (in-list cone)])
         (send-plugin (first info))
         (drive-to-fixpoint!))]
      [`(pipeline)
       (send-plugin (action-so `(pipeline)))
       (read-one-line!)]
      [`(sizes-at ,p)
       (send-plugin (action-so `(sizes-at ,p)))
       (read-one-line!)]
      [`(dump-rel ,rel)
       (send-plugin (action-so `(dump-rel ,rel)))
       (read-until! #px"^\\(dumpdone ")]
      [`(dump-rel ,rel ,p)
       (send-plugin (action-so `(dump-rel ,rel ,p)))
       (read-until! #px"^\\(dumpdone ")]
      [`(sizes)
       ;; no terminator: rely on ordering -- sizes lines flush before the
       ;; next op's response; drain at close instead
       (send-plugin (action-so `(sizes)))]
      [`(schema)
       (send-plugin (action-so `(schema)))
       (read-until! #px"^\\(schema-end\\)")]
      ;; silent writes: processed in stdin order before any later op
      [`(write-db ,db) (send-plugin (action-so `(write-db ,db)))]
      [`(write-csv ,dir) (send-plugin (action-so `(write-csv ,dir)))]))

  (close-output-port in)
  (let loop ()
    (define s (read-line out))
    (unless (eof-object? s) (displayln s) (loop)))
  (close-input-port out)
  (thread-wait err-thread)
  (close-input-port err)
  (subprocess-wait sp)
  (exit (if (> (subprocess-status sp) 0) 1 0)))
