#lang racket

;; The incremental-session driver (docs/incremental.md §0.2, §0.5, 0.B4):
;; a resident daemon driven through program segments and signed batches,
;; with the Phase-0 routing rule deciding how each flush propagates.
;;
;;   session       = daemon + per-stratum manifest info + pending batches
;;   session-run!  = one program segment: begin-segment version boundary,
;;                   frozen imports, strata to fixpoint
;;   session-batch!= queue one signed tuple; same-point add/delete pairs
;;                   collapse in the pending set (§0.2 -- absent from any
;;                   later flush or save)
;;   session-flush!= apply the pending sets and propagate by the routing
;;                   rule (§0.5): all-adds + all-monotone cone ->
;;                   delta-entry when that flavor exists (0.B5; none yet)
;;                   else replay-entry (re-push the cone's cached .so's);
;;                   any deletion or neg/lat cone edge -> clear-and-rerun
;;                   (clear cone-written relations, re-push).  Cones of a
;;                   multi-relation flush are unioned; one rerun-needing
;;                   relation routes the whole union through rerun (sound:
;;                   clear-and-rerun is sound for everything).
;;
;; Batches are tip-anchored (the current pipeline point): the driver
;; queues them while a stratum runs and applies them only between
;; fixpoints (refuseIfSuspended semantics compose -- every action here is
;; sent at a boundary).  Anchors at older points arrive with the recipe
;; protocol (0.C); the guards below refuse the cases that need them.
;;
;; Pausing composes: each stratum answers one line per bounded unit; a
;; (paused ...) is answered with a (continue) action (env-configurable
;; budget), exactly as runslog's one-shot loop does.

(provide make-session
         session-open!
         session-run!
         session-batch!
         session-flush!
         session-action!          ; low-level: one action + a reader
         session-reenter!         ; direct replay-entry (tests/tools)
         session-rerun!           ; direct clear-and-rerun (tests/tools)
         session-close!)

(require "tools.rkt")
(require "compile.rkt")
(require "actions.rkt")
(require "runslog.rkt")   ; db-full-manifest, segment-write-set

;; One live session.  strata-info: per fresh-pushed stratum, in pipeline
;; order (index = daemon scc id), (list so-path dynamic-rels reads).
;; pending: rel-symbol -> (hash tuple-list -> '+ / '-).
(struct session (sp out in err-thread [db #:mutable]
                 [strata-info #:mutable] pending echo)
  #:transparent)

(define (make-session #:echo [echo displayln])
  (ensure-slogd-exists)
  (define-values (sp out in err)
    (apply subprocess #f #f #f (slogd-argv "daemon/slogd")))
  (define err-thread
    (thread (lambda ()
              (let loop ()
                (define s (read-line err))
                (unless (eof-object? s) (eprintf "~a\n" s) (loop))))))
  (session sp out in err-thread #f '() (make-hash) echo))

(define (send-plugin! s path)
  (display (string-append path "\n") (session-in s))
  (flush-output (session-in s)))

(define (echo! s line) ((session-echo s) line))

;; Drive the current stratum to fixpoint: echo every line; answer
;; (paused ...) with (continue); error on (error ...) or EOF.
(define (drive-to-fixpoint! s)
  (define continue-so (action-so `(continue)))
  (let poll ()
    (define line (read-line (session-out s)))
    (cond
      [(eof-object? line) (error 'session "daemon EOF mid-stratum")]
      [(regexp-match? #px"^\\(fixpoint " line) (echo! s line)]
      [(regexp-match? #px"^\\(paused " line)
       (echo! s line)
       (cond
         [(regexp-match? #px"memory\\)\\s*$" line)
          (error 'session (format "out of memory: ~a" line))]
         [else (send-plugin! s continue-so) (poll)])]
      [(regexp-match? #px"^\\(error " line)
       (error 'session (format "daemon error: ~a" line))]
      [else (echo! s line) (poll)])))

;; Send one action and hand its response stream to `read!` (called with
;; the session's output port; may read as many lines as the action's
;; protocol emits -- nothing for silent actions).
(define (session-action! s spec [read! void])
  (send-plugin! s (action-so spec))
  (read! (session-out s)))

(define (read-one-line! s)
  (define line (read-line (session-out s)))
  (unless (eof-object? line) (echo! s line)))

(define (session-open! s db)
  (set-session-db! s db)
  (session-action! s `(open ,db)))

;; Run one program segment atop the session (docs/incremental.md §0.4):
;; open a version boundary for its write-set, import its frozen ground
;; facts, then drive each stratum to fixpoint, recording its manifest for
;; later cone assembly.
(define (session-run! s prog)
  (define manifest (if (session-db s) (db-full-manifest (session-db s)) (hash)))
  (define-values (strata partition edb-boundary frozen-dirs)
    (compile-strata prog manifest #:split-facts? #f))
  (define ws (segment-write-set strata frozen-dirs))
  (when (pair? ws)
    (session-action! s `(begin-segment ,@ws))
    (read-one-line! s))   ; (segment P N)
  (for ([dir (in-list frozen-dirs)])
    (session-action! s `(import-path ,dir)))
  (for ([sb (in-list strata)])
    (match-define (cons so _tag) ((sbuild-runnable sb)))
    (define-values (dyn reads) (read-stratum-meta (sbuild-hash sb)))
    ;; entry = (list so dynamic-rels reads delta-thunk); the thunk builds
    ;; the stratum's delta-entry flavor lazily (0.B5)
    (set-session-strata-info! s (append (session-strata-info s)
                                        (list (list so dyn reads (sbuild-delta sb)))))
    (send-plugin! s so)
    (drive-to-fixpoint! s)))

;; Queue one signed tuple against the current pipeline point.  A pending
;; opposite-signed entry for the same tuple collapses to nothing (§0.2);
;; re-queuing the same sign is idempotent.
(define (session-batch! s sign rel tuple)
  (define per-rel (hash-ref! (session-pending s) rel make-hash))
  (match (hash-ref per-rel tuple #f)
    [#f (hash-set! per-rel tuple sign)]
    [(== sign) (void)]
    [_ (hash-remove! per-rel tuple)]))

;; ---- cone assembly (docs/incremental.md §0.5) ----------------------------

;; Live introspection: (values scc->pos rel->binding-positions).
(define (introspect! s)
  (session-action! s `(pipeline))
  (define pline (read-line (session-out s)))
  (when (eof-object? pline) (error 'session "daemon EOF at introspection"))
  (echo! s pline)
  (match (read (open-input-string pline))
    [`(pipeline ,_ (strata ,ss ...) ,rels ...)
     (values (for/hash ([st (in-list ss)])
               (match-define `(s ,scc ,pos ,_name) st)
               (values scc pos))
             (for/hash ([r (in-list rels)])
               (match-define `(rel ,name ,vs ...) r)
               (values name
                       (for/list ([v (in-list vs)])
                         (match-define `(v ,_ ,pos ,_sz) v)
                         pos))))]
    [x (error 'session (format "unparseable (pipeline) reply: ~a" x))]))

;; cone(target) closure over candidate entries (list so dyn reads delta
;; pos), in pipeline order; monotone? = #f if any edge INTO the cone is
;; neg/lat.
(define (cone-closure candidates target)
  (let loop ([infos candidates] [wave (set target)] [acc '()] [mono? #t])
    (match infos
      ['() (values (reverse acc) mono?)]
      [(cons (and info (list _so dyn reads _delta _pos)) rest)
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

;; cone(rel) for a tip-anchored batch, given one introspection snapshot:
;; anchor at the target's last binding; candidates = strata bound
;; at-or-after it (earlier strata read a PREDECESSOR version); rebound
;; guard: a re-pushed stratum binds the LATEST environment, sound only if
;; nothing it touches was rebound after it -- positional re-binding +
;; boundary re-materialisation arrive with anchored batches (0.C).
(define (cone-of s rel strata-pos chains)
  (define anchor
    (let ([c (hash-ref chains rel '())])
      (if (null? c) 0 (last c))))
  (define candidates
    (for/list ([info (in-list (session-strata-info s))] [scc (in-naturals)]
               #:when (>= (hash-ref strata-pos scc 0) anchor))
      (append info (list (hash-ref strata-pos scc 0)))))
  (define-values (cone mono?) (cone-closure candidates rel))
  (for ([info (in-list cone)])
    (match-define (list _so dyn reads _delta pos) info)
    (for ([r (in-sequences (in-list dyn) (in-list (map car reads)))])
      (when (for/or ([p (in-list (hash-ref chains r '()))]) (> p pos))
        (error 'session
               (format "~a was rebound after a cone stratum (pos ~a): latest-env re-entry is unsound here; anchored replay is 0.C" r pos)))))
  (values cone mono?))

;; ---- flush: route, apply pending batches, propagate (the 0.B4 policy) ----

(define (session-flush! s)
  (define pending (session-pending s))
  (define rels (sort (hash-keys pending) symbol<?))
  (define nonempty
    (for/list ([r (in-list rels)] #:when (positive? (hash-count (hash-ref pending r))))
      r))
  (cond
    [(null? nonempty)
     (hash-clear! pending)
     (echo! s "(flush 0)")]
    [else
     ;; 1. ROUTE FIRST (cones depend on targets, not edit contents; the
     ;;    rebound guard fires before anything mutates): one introspection
     ;;    snapshot, union the per-relation cones in pipeline order
     (define-values (strata-pos chains) (introspect! s))
     (define any-del?
       (for*/or ([r (in-list nonempty)]
                 [(tuple sign) (in-hash (hash-ref pending r))])
         (eq? sign '-)))
     (define union-mono? (not any-del?))
     (define union-sos (mutable-set))
     (for ([r (in-list nonempty)])
       (define-values (cone mono?) (cone-of s r strata-pos chains))
       (unless mono? (set! union-mono? #f))
       (for ([info (in-list cone)])
         (set-add! union-sos (first info))))
     (define union-cone
       (for/list ([info (in-list (session-strata-info s))]
                  #:when (set-member? union-sos (first info)))
         info))
     ;; delta-entry eligibility (§0.5 mode 3): monotone adds whose union
     ;; cone is a SINGLE stratum -- the batch stages as that stratum's
     ;; iteration-0 delta and semi-naïve runs O(change).  Multi-stratum
     ;; cones stay on replay-entry until boundary-delta capture exists
     ;; (novel derivations of one cone stratum are not observable as the
     ;; next one's delta pre-M0; presence transitions make them so).
     (define delta-eligible? (and union-mono? (= 1 (length union-cone))))
     ;; 2+3. apply the collapsed edits and propagate, per route
     (define (apply-edits! #:stage-adds? [stage-adds? #f])
       (for ([r (in-list nonempty)])
         (for ([(tuple sign) (in-hash (hash-ref pending r))])
           (cond
             [(eq? sign '+)
              (session-action! s (if stage-adds?
                                     `(stage-tuple ,r ,@tuple)
                                     `(add-tuple ,r ,@tuple)))]
             [else
              (session-action! s `(del-tuple ,r ,@tuple))
              (read-one-line! s)])))   ; (deleted REL 0|1)
       (hash-clear! pending))
     (cond
       [delta-eligible?
        ;; the flavor builds lazily on this first increment ("delta-entry
        ;; when compiled" -- here compilation IS the first increment's
        ;; cost, cached for every later flush)
        (define delta-so ((fourth (first union-cone))))
        (apply-edits! #:stage-adds? #t)
        (echo! s "(route delta 1)")
        (send-plugin! s delta-so)
        (drive-to-fixpoint! s)]
       [union-mono?
        (apply-edits!)
        (echo! s (format "(route reenter ~a)" (length union-cone)))
        (for ([info (in-list union-cone)])
          (send-plugin! s (first info))
          (drive-to-fixpoint! s))]
       [else
        (apply-edits!)
        ;; clear cone-written relations, EXCEPT those also written by
        ;; non-cone strata (shared diagnostic side channels: their
        ;; out-of-cone content cannot re-derive; stale in-cone diagnostic
        ;; rows accepted for Phase 0)
        (define cone-dyn
          (for*/set ([info (in-list union-cone)] [d (in-list (second info))]) d))
        (define noncone-dyn
          (for*/set ([info (in-list (session-strata-info s))]
                     #:unless (set-member? union-sos (first info))
                     [d (in-list (second info))])
            d))
        (define clear-set
          (sort (set->list (set-subtract cone-dyn noncone-dyn)) symbol<?))
        (for ([r (in-list clear-set)])
          (session-action! s `(clear-rel ,r)))
        (echo! s (format "(route rerun ~a ~a)" (length union-cone) (length clear-set)))
        (for ([info (in-list union-cone)])
          (send-plugin! s (first info))
          (drive-to-fixpoint! s))])]))

;; Direct single-relation re-entry modes (tests/tools; flush is the policy
;; path).  reenter refuses non-monotone cones; rerun accepts everything
;; the rebound guard admits.
(define (session-reenter! s rel)
  (define-values (strata-pos chains) (introspect! s))
  (define-values (cone mono?) (cone-of s rel strata-pos chains))
  (unless mono?
    (error 'session
           (format "non-monotone cone for ~a (neg/lat edge): use rerun (clear-and-rerun, 0.B2)" rel)))
  (echo! s (format "(reenter ~a ~a)" rel (length cone)))
  (for ([info (in-list cone)])
    (send-plugin! s (first info))
    (drive-to-fixpoint! s)))

(define (session-rerun! s rel)
  (define-values (strata-pos chains) (introspect! s))
  (define-values (cone _mono?) (cone-of s rel strata-pos chains))
  (define cone-sos (for/set ([i (in-list cone)]) (first i)))
  (define cone-dyn (for*/set ([i (in-list cone)] [d (in-list (second i))]) d))
  (define noncone-dyn
    (for*/set ([i (in-list (session-strata-info s))]
               #:unless (set-member? cone-sos (first i))
               [d (in-list (second i))])
      d))
  (define clear-set (sort (set->list (set-subtract cone-dyn noncone-dyn)) symbol<?))
  (for ([r (in-list clear-set)])
    (session-action! s `(clear-rel ,r)))
  (echo! s (format "(rerun ~a ~a ~a)" rel (length cone) (length clear-set)))
  (for ([info (in-list cone)])
    (send-plugin! s (first info))
    (drive-to-fixpoint! s)))

;; Close the daemon and drain its remaining output through the echo.
(define (session-close! s)
  (close-output-port (session-in s))
  (let loop ()
    (define line (read-line (session-out s)))
    (unless (eof-object? line) (echo! s line) (loop)))
  (close-input-port (session-out s))
  (thread-wait (session-err-thread s))
  (subprocess-wait (session-sp s))
  (subprocess-status (session-sp s)))
