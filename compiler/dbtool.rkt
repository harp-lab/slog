#lang racket

;; The data/ database DAG and the `slog db` command (docs/db-compression.md §7).
;;
;; data/ is an immutable object DAG: every database directory links (by an
;; ordered manifest in its META) to the input database(s) it was derived atop.
;; A scan of all data/*/META reconstructs the graph.  This module owns:
;;   - the DAG scan + queries (inputs, dependents, staleness),
;;   - `slog db ls|tree|rm|gc|clear|verify` (invoked as `slog db <sub> ...`),
;;   - the referenced-db immutability guard the save path consults,
;;   - db-load-actions: the manifest-driven open+import sequence that the driver
;;     issues for `-d NAME` on a compressed database (open the EDB root, import
;;     the layer) -- at per=100% this reconstitutes the exact database with no
;;     replay (P1 adds recompute for per<100%).

(provide slog-db-command
         db-load-actions
         db-load-steps
         db-referenced-by
         db-exists?
         db-managed?
         db-chain-has-edits?
         db-encoding-mismatch)

(require "dbmeta.rkt")
(require racket/format)

(define DATA "data")

;; ---------------------------------------------------------------------------
;; DAG scan
;; ---------------------------------------------------------------------------

(define (db-dir name) (build-path DATA name))
(define (db-exists? name) (directory-exists? (db-dir name)))
(define (db-managed? name) (db-meta-file-exists? (db-dir name)))

;; All database directory names under data/ (each immediate subdirectory).
(define (all-db-names)
  (cond
    [(not (directory-exists? DATA)) '()]
    [else
     (sort
      (for/list ([e (in-list (directory-list DATA))]
                 #:when (directory-exists? (build-path DATA e)))
        (path->string e))
      string<?)]))

;; META of a db, or #f if it has none (a plain/legacy --out-db database).
(define (db-meta-of name)
  (and (db-managed? name)
       (with-handlers ([db-meta-error? (lambda (_) #f)])
         (read-db-meta (db-dir name)))))

;; Input db names of `name` (its manifest links).
(define (db-inputs name)
  (define m (db-meta-of name))
  (if m (map first (db-meta-manifest m)) '()))

;; Names of dbs whose manifest lists `name` as an input (its dependents).
(define (db-referenced-by name)
  (for/list ([n (in-list (all-db-names))]
             #:when (member name (db-inputs n)))
    n))

;; Transitive dependents of `name` (everything that would break if it vanished).
(define (db-dependents* name)
  (let loop ([frontier (list name)] [seen (set)])
    (cond
      [(null? frontier) (set-remove seen name)]
      [else
       (define n (first frontier))
       (define deps (db-referenced-by n))
       (loop (append (rest frontier) (filter (lambda (d) (not (set-member? seen d))) deps))
             (for/fold ([s seen]) ([d (in-list deps)]) (set-add s d)))])))

;; Is `name` stale?  -> #f, or a list of reasons (missing/changed inputs).
(define (db-staleness name)
  (define m (db-meta-of name))
  (cond
    [(not m) '()]
    [else
     (for/fold ([reasons '()]) ([link (in-list (db-meta-manifest m))])
       (match-define (list iname istamp) link)
       (define im (db-meta-of iname))
       (cond
         [(not (db-exists? iname)) (cons (format "input ~a missing" iname) reasons)]
         [(and im istamp (not (equal? (db-meta-stamp im) istamp)))
          (cons (format "input ~a changed" iname) reasons)]
         [else reasons]))]))

;; Count relation directories (a cheap size proxy).
(define (db-rel-count name)
  (define d (db-dir name))
  (if (directory-exists? d)
      (for/sum ([e (in-list (directory-list d))]
                #:when (regexp-match? #px"^(table|struct|lat)\\." (path->string e)))
        1)
      0))

(define (dir-bytes d)
  (if (directory-exists? d)
      (for/sum ([f (in-directory d)] #:when (file-exists? f)) (file-size f))
      0))

(define (human-bytes n)
  (cond [(< n 1024) (format "~aB" n)]
        [(< n (* 1024 1024)) (format "~aK" (quotient n 1024))]
        [(< n (* 1024 1024 1024)) (format "~aM" (quotient n (* 1024 1024)))]
        [else (format "~aG" (quotient n (* 1024 1024 1024)))]))

;; ---------------------------------------------------------------------------
;; Cycle detection (enforced logically; save also refuses to link a cycle)
;; ---------------------------------------------------------------------------

(define (dag-has-cycle?)
  (define names (all-db-names))
  (define color (make-hash))          ; name -> 'grey | 'black
  (let/ec return
    (define (visit n)
      (case (hash-ref color n #f)
        [(grey) (return #t)]
        [(black) (void)]
        [else
         (hash-set! color n 'grey)
         (for ([i (in-list (db-inputs n))] #:when (db-exists? i)) (visit i))
         (hash-set! color n 'black)]))
    (for ([n (in-list names)]) (visit n))
    #f))

;; ---------------------------------------------------------------------------
;; Load: the manifest-driven open+import sequence for `-d NAME`
;; ---------------------------------------------------------------------------

;; Returns the ordered action specs the driver issues to reconstitute `name`.
;; A plain db (or one with an empty manifest) is a single (open name).  A
;; compressed layer opens its EDB root, imports any further inputs, then imports
;; its own IDB relations -- content-dedup merges the two id lineages (§4.3).  At
;; P0 per is always 1.0, so this yields the full database with no replay.
(define (db-load-actions name)
  (define m (db-meta-of name))
  (define manifest (if m (db-meta-manifest m) '()))
  ;; a db's edits (add-tuple ...) apply right after it is opened/imported, so
  ;; replay of everything above sees the edited input-leaf relation (§12).
  (define (edits-of n) (read-edits (db-dir n)))
  (cond
    [(null? manifest) (append (list `(open ,name)) (edits-of name))]
    [else
     (define inputs (map first manifest))
     (append
      (list `(open ,(first inputs))) (edits-of (first inputs))
      (append-map (lambda (i) (cons `(import ,i) (edits-of i))) (rest inputs))
      (list `(import ,name)) (edits-of name))]))

;; Recursive load plan for `name` (docs/db-compression.md §10, P2): the whole
;; input DAG materialised bottom-up.  Each element is either an action spec
;; (open/import/add-tuple) streamed as a plugin, or `(replay L)` telling the
;; driver to recompile + run layer L's stored program.  The base (first input)
;; is opened and recursively materialised; further inputs and this layer are
;; imported; each db's edits apply right after it lands; a layer with a stored
;; program is replayed to regenerate dropped facts.  `seen` de-dups diamonds.
(define (db-load-steps name [seen (set)])
  (cond
    [(or (not name) (set-member? seen name)) '()]
    [else
     (define seen+ (set-add seen name))
     (define m (db-meta-of name))
     (define manifest (if m (db-meta-manifest m) '()))
     (define e (read-edits (db-dir name)))
     (define replay (if (prog-sexpr-exists? (db-dir name)) (list `(replay ,name)) '()))
     (cond
       [(null? manifest) (append (list `(open ,name)) e)]
       [else
        (define inputs (map first manifest))
        (append
         (db-load-steps (first inputs) seen+)                          ; base, recursively
         (append-map (lambda (i) (append (db-load-steps i seen+)       ; extra inputs merged in
                                         (list `(import ,i))))
                     (rest inputs))
         (list `(import ,name)) e replay)])]))

;; Walk the load DAG; return (list db stored-version) for the first database
;; whose recorded value-encoding-version differs from what this build reads,
;; else #f (docs/db-compression.md §P2.2).  A derived layer could drop-and-
;; replay under the new encoding, but a root's bins would need real migration,
;; so the driver refuses rather than misread words at the wrong offsets.
(define (db-encoding-mismatch name [seen (set)])
  (cond
    [(or (not name) (set-member? seen name)) #f]
    [else
     (define m (db-meta-of name))
     (cond
       [(and m (not (equal? (db-meta-value-encoding-version m) slog-value-encoding-version)))
        (list name (db-meta-value-encoding-version m))]
       [else (for/or ([i (in-list (db-inputs name))])
               (db-encoding-mismatch i (set-add seen name)))])]))

;; Does `name` or any db in its transitive input DAG carry edits?  A verify
;; against the stored signature is skipped in that case -- an edit intentionally
;; changes the content, so the replay legitimately no longer matches (§12).
(define (db-chain-has-edits? name [seen (set)])
  (cond
    [(or (not name) (set-member? seen name)) #f]
    [(db-has-edits? (db-dir name)) #t]
    [else
     (for/or ([i (in-list (db-inputs name))])
       (db-chain-has-edits? i (set-add seen name)))]))

;; ---------------------------------------------------------------------------
;; `slog db` subcommands
;; ---------------------------------------------------------------------------

(define (die fmt . args)
  (fprintf (current-error-port) "Error: ~a\n" (apply format fmt args))
  (exit 2))

(define (cmd-ls)
  (define names (all-db-names))
  (cond
    [(null? names) (printf "No databases under ~a/\n" DATA)]
    [else
     (printf "~a  ~a  ~a  ~a  ~a\n"
             (~a "NAME" #:min-width 24) (~a "KIND" #:min-width 10)
             (~a "PER" #:min-width 5) (~a "RELS" #:min-width 5) "SIZE")
     (for ([n (in-list names)])
       (define m (db-meta-of n))
       (define stale (db-staleness n))
       (printf "~a  ~a  ~a  ~a  ~a~a\n"
               (~a n #:min-width 24)
               (~a (if m (db-meta-kind m) "plain") #:min-width 10)
               (~a (if m (~r (* 100 (db-meta-per m)) #:precision 0) "-") #:min-width 5)
               (~a (db-rel-count n) #:min-width 5)
               (~a (human-bytes (dir-bytes (db-dir n))) #:min-width 6)
               (if (null? stale) "" (format "  STALE (~a)" (string-join stale "; ")))))]))

(define (cmd-tree names0)
  ;; Roots to print: named args, or every db that nothing else references.
  (define roots
    (cond [(pair? names0) names0]
          [else (filter (lambda (n) (null? (db-referenced-by n))) (all-db-names))]))
  (define (walk n depth seen)
    (define m (db-meta-of n))
    (printf "~a~a~a\n"
            (make-string (* 2 depth) #\space)
            (if (> depth 0) "└─ " "")
            (format "~a~a" n (if m (format " [~a]" (db-meta-kind m)) " [plain]")))
    (cond
      [(set-member? seen n) (printf "~a(cycle)\n" (make-string (* 2 (add1 depth)) #\space))]
      [else
       (for ([i (in-list (db-inputs n))])
         (walk i (add1 depth) (set-add seen n)))]))
  (for ([r (in-list roots)])
    (unless (db-exists? r) (die "no such database: ~a" r))
    (walk r 0 (set))))

(define (rm-one! name)
  (define d (db-dir name))
  (when (directory-exists? d) (delete-directory/files d))
  (printf "removed ~a\n" name))

(define (cmd-rm args)
  (define cascade? (and (member "--cascade" args) #t))
  (define names (filter (lambda (a) (not (string-prefix? a "--"))) args))
  (when (null? names) (die "usage: slog db rm NAME... [--cascade]"))
  (for ([name (in-list names)])
    (unless (db-exists? name) (die "no such database: ~a" name))
    (define deps (set->list (db-dependents* name)))
    (cond
      [(null? deps) (rm-one! name)]
      [cascade?
       (for ([d (in-list deps)]) (rm-one! d))
       (rm-one! name)]
      [else
       (die "~a is an input to: ~a\n  (use --cascade to remove it and all dependents)"
            name (string-join deps ", "))])))

(define (cmd-gc)
  ;; Reclaim EDB roots (data/<x>.edb) that no layer's manifest references any
  ;; more -- the orphan left behind when a compressed layer is removed.
  (define orphans
    (for/list ([n (in-list (all-db-names))]
               #:when (and (string-suffix? n ".edb")
                           (null? (db-referenced-by n))))
      n))
  (cond
    [(null? orphans) (printf "nothing to collect\n")]
    [else (for ([o (in-list orphans)]) (rm-one! o))]))

(define (cmd-clear)
  (cond
    [(not (directory-exists? DATA)) (printf "no data/ directory\n")]
    [else
     (for ([e (in-list (directory-list DATA))]
           #:when (directory-exists? (build-path DATA e)))
       (delete-directory/files (build-path DATA e)))
     (printf "cleared ~a/\n" DATA)]))

(define (cmd-verify names0)
  (define names (if (pair? names0) names0 (all-db-names)))
  (define ok (box #t))
  (when (dag-has-cycle?)
    (set-box! ok #f)
    (printf "FAIL: data/ contains a dependency cycle\n"))
  (for ([n (in-list names)])
    (unless (db-exists? n) (die "no such database: ~a" n))
    (define problems '())
    (define (add! p) (set! problems (cons p problems)))
    (define m (db-meta-of n))
    (cond
      [(not (db-managed? n)) (add! "no META (plain database)")]
      [(not m) (add! "META present but unreadable/foreign")]
      [else
       ;; every input must exist and be managed
       (for ([link (in-list (db-meta-manifest m))])
         (match-define (list iname _) link)
         (unless (db-exists? iname) (add! (format "missing input ~a" iname))))
       (for ([r (in-list (db-staleness n))]) (add! (format "stale: ~a" r)))])
    (cond
      [(null? problems) (printf "ok   ~a\n" n)]
      [else (set-box! ok #f)
            (printf "FAIL ~a\n" n)
            (for ([p (in-list (reverse problems))]) (printf "       - ~a\n" p))]))
  (unless (unbox ok) (exit 2)))

;; slog db edit NAME add-tuple REL v...  -- record a forward-incremental edit
;; to an input-leaf relation (§12).  Applied at load; propagates by re-replay.
(define (cmd-edit args)
  (match args
    [(list-rest name "add-tuple" rel vals)
     (unless (db-exists? name) (die "no such database: ~a" name))
     (when (null? vals) (die "usage: slog db edit NAME add-tuple REL v..."))
     (define parsed (for/list ([v (in-list vals)]) (or (string->number v) (string->symbol v))))
     (append-edit! (db-dir name) `(add-tuple ,(string->symbol rel) ,@parsed))
     (printf "recorded edit on ~a: (add-tuple ~a ~a); reload a dependent to propagate\n"
             name rel (string-join vals " "))]
    [_ (die "usage: slog db edit NAME add-tuple REL v...")]))

(define (slog-db-command args)
  (match args
    [(list) (printf "usage: slog db <ls|tree|rm|gc|clear|verify|edit> [args]\n")]
    [(cons "ls" _) (cmd-ls)]
    [(cons "tree" rest) (cmd-tree rest)]
    [(cons "rm" rest) (cmd-rm rest)]
    [(cons "gc" _) (cmd-gc)]
    [(cons "clear" _) (cmd-clear)]
    [(cons "verify" rest) (cmd-verify rest)]
    [(cons "edit" rest) (cmd-edit rest)]
    [(cons other _) (die "unknown db subcommand: ~a" other)]))
