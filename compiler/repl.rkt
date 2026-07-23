#lang racket

;; The sole Racket-side REPL entry point.
;;
;; The interactive program is the Rust `slog` client under ../repl.  This
;; process owns compilation, a lazy registry of compiler/session.rkt sessions,
;; and the C++ daemon beneath each resident session.  It exposes none of
;; Racket's terminal UI:
;; one authenticated Rust client connects over a loopback-only TCP listener
;; and exchanges Content-Length-framed JSON messages.

(provide serve-repl
         plain-transcript) ; deterministic server-contract harness

(require json
         racket/cmdline
         racket/match
         racket/port
         racket/string
         racket/tcp
         "dbtool.rkt"
         "params.rkt"
         "session.rkt")

(define protocol-version 1)
(define default-max-frame-bytes (* 16 1024 1024))

(struct repl-session (session database [mode #:mutable] [changed? #:mutable])
  #:transparent)

;; One Racket REPL connection can own several independent compiler sessions.
;; A database name is the key for a database-backed session; the 'scratch key
;; is reserved for the lazy, database-less session used by `run` before an
;; `open`.  Switching only changes `current`, so every session keeps its own
;; daemon, pipeline, mutations, and replayed database in memory.
(struct server-state (sessions
                      [current #:mutable]
                      [event-sink #:mutable]
                      [closing? #:mutable])
  #:transparent)

(struct relation-info (name kind arity detail size) #:transparent)

(define scratch-key 'scratch)
(define max-show-facts 200)

(define (json-bytes value)
  (define out (open-output-bytes))
  (write-json value out)
  (get-output-bytes out))

(define (write-frame out value)
  (define body (json-bytes value))
  (fprintf out "Content-Length: ~a\r\n\r\n" (bytes-length body))
  (write-bytes body out)
  (flush-output out))

(define (read-exactly in amount)
  (define body (make-bytes amount))
  (let loop ([offset 0])
    (cond
      [(= offset amount) body]
      [else
       (define got (read-bytes! body in offset amount))
       (cond
         [(eof-object? got) eof]
         [(zero? got) (loop offset)]
         [else (loop (+ offset got))])])))

(define (read-frame in [max-bytes default-max-frame-bytes])
  (define header (read-line in 'any))
  (cond
    [(eof-object? header) eof]
    [else
     (match (regexp-match #px"(?i:^Content-Length:)[ ]*([0-9]+)$" header)
       [(list _ amount-text)
        (define amount (string->number amount-text))
        (unless (<= 0 amount max-bytes)
          (error 'repl-protocol "frame length ~a exceeds limit ~a"
                 amount max-bytes))
        (define separator (read-line in 'any))
        (unless (and (string? separator) (string=? separator ""))
          (error 'repl-protocol "expected blank line after Content-Length"))
        (define body (read-exactly in amount))
        (if (eof-object? body)
            (error 'repl-protocol "connection ended inside a frame")
            (read-json (open-input-bytes body)))]
       [_ (error 'repl-protocol "invalid frame header: ~a" header)])]))

(define (success id result)
  (hasheq 'id id 'ok #t 'result result))

(define (failure id kind message)
  (hasheq 'id id
          'ok #f
          'error (hasheq 'kind kind 'message message)))

(define (capture-session-events state thunk)
  (define sink (box '()))
  (dynamic-wind
    (lambda () (set-server-state-event-sink! state sink))
    (lambda ()
      (define value (thunk))
      (values value (reverse (unbox sink))))
    (lambda () (set-server-state-event-sink! state #f))))

(define (make-repl-session state database)
  (repl-session
   (make-session
    #:echo
    (lambda (line)
      (define sink (server-state-event-sink state))
      (when sink
        (set-box! sink (cons line (unbox sink))))))
   database
   'mutable
   #f))

(define (current-repl-session state)
  (and (server-state-current state)
       (hash-ref (server-state-sessions state) (server-state-current state) #f)))

(define (ensure-session-record! state)
  (or (current-repl-session state)
      (let ([rs (hash-ref! (server-state-sessions state)
                           scratch-key
                           (lambda () (make-repl-session state #f)))])
        (set-server-state-current! state scratch-key)
        rs)))

(define (ensure-session! state)
  (repl-session-session (ensure-session-record! state)))

(define (ensure-mutable-session-record! state who)
  (define rs (ensure-session-record! state))
  (unless (eq? (repl-session-mode rs) 'mutable)
    (error who
           "current database is read-only; use `mode mutable` before changing it"))
  rs)

(define (session-display-name key rs)
  (or (repl-session-database rs)
      (and (eq? key scratch-key) "scratch")
      (~a key)))

(define (session-summaries state)
  (define current (server-state-current state))
  (for/list ([key (in-list
                   (sort (hash-keys (server-state-sessions state))
                         string<?
                         #:key (lambda (key)
                                 (if (eq? key scratch-key) "" (~a key)))))])
    (define rs (hash-ref (server-state-sessions state) key))
    (hasheq 'name (session-display-name key rs)
            'database (or (repl-session-database rs) 'null)
            'current (equal? key current)
            'mode (symbol->string (repl-session-mode rs))
            'changed (repl-session-changed? rs))))

(define (attach-session-state state result)
  (hash-set
   (hash-set result
             'current
             (let ([rs (current-repl-session state)])
               (if rs (or (repl-session-database rs) "scratch") 'null)))
   'sessions
   (session-summaries state)))

(define (read-one-response out)
  (define line (read-line out))
  (if (eof-object? line) '() (list line)))

(define ((read-until-response end-rx) out)
  (let loop ([lines '()])
    (define line (read-line out))
    (cond
      [(eof-object? line) (reverse lines)]
      [(regexp-match? end-rx line) (reverse (cons line lines))]
      [else (loop (cons line lines))])))

(define help-lines
  (list
   "Open databases"
   "  library             browse saved databases"
   "  library select NAME focus a saved database in the library"
   "  library close       return from the library to the shell"
   "  open NAME           load NAME, or switch to its resident in-memory copy"
   "  current             describe the current database"
   "  resident            list databases currently held in memory"
   "  mode readonly       protect the current database from mutations"
   "  mode mutable        allow the current database to be extended"
   ""
   "Explore the current database"
   "  tables [FILTER]     list live relations, schemas, and row counts"
   "  state [REL]         summarize the pipeline or one relation's versions"
   "  count REL           count the current version of a relation"
   "  show REL [LIMIT]    show rows for a small relation (safety cap: 200)"
   "  query REL V...      test whether any row matches a value prefix"
   "  schema              show the daemon's raw live schema"
   "  pipeline            show the daemon's raw versioned pipeline"
   ""
   "Extend a mutable database"
   "  run PATH            compile and run a .slog program"
   "  add REL V...        add one input tuple and propagate it"
   "  del REL V...        retract one input tuple and propagate it"
   "  rename FROM TO      rename one live relation without moving its data"
   "  drop REL            remove one relation name at the next boundary"
   "  save NAME           save the current database as data/NAME"
   ""
   "Workbench"
   "  :status             show REPL, current database, and daemon state"
   "  :ping               round-trip through the private TCP protocol"
   "  :help               show these commands"
   "  :quit               close every resident database and the REPL"
   "  :clear              clear the visible client transcript"
   "  :share              show the trusted-local co-author endpoint"
   "  ; COMMENT           add a transcript comment without invoking Slog"))

(define (split-command source)
  (define text (string-trim source))
  (cond
    [(string=? text "") (values "" "")]
    [else
     (match (regexp-match #px"^([^[:space:]]+)(?:[[:space:]]+(.*))?$" text)
       [(list _ verb argument)
        (values (string-downcase verb) (or argument ""))])]))

(define (text-result title lines #:kind [kind "text"] #:change [change #f])
  (define result (hasheq 'kind kind 'title title 'lines lines))
  (if change (hash-set result 'change change) result))

(define (read-datum line)
  (with-handlers ([exn:fail? (lambda (_) #f)])
    (read (open-input-string line))))

(define (read-command-data who argument #:minimum [minimum 1])
  (define datum
    (with-handlers ([exn:fail:read?
                     (lambda (e)
                       (error who "cannot read values: ~a" (exn-message e)))])
      (read (open-input-string (string-append "(" argument ")")))))
  (unless (and (list? datum) (>= (length datum) minimum))
    (error who "expected a relation followed by values"))
  datum)

(define (relation-key value) (~a value))

;; `(sizes)` has no terminator, while `(schema)` does.  Queue them in that
;; order and read through schema-end: the daemon's ordered plugin stream makes
;; schema-end a delimiter for both read-only replies without any daemon change.
(define (live-catalog s)
  (session-action! s '(sizes))
  (define lines
    (session-action! s '(schema)
                     (read-until-response #px"^\\(schema-end\\)$")))
  (define sizes (make-hash))
  (define schemas (make-hash))
  (for ([line (in-list lines)])
    (match (read-datum line)
      [`(relation_size ,name ,size)
       (hash-set! sizes (relation-key name) size)]
      [`(schema-rel ,kind ,name ,arity ,detail ...)
       (hash-set! schemas (relation-key name)
                  (list (~a kind) arity detail))]
      [_ (void)]))
  (for/list ([name (in-list (sort (remove-duplicates
                                    (append (hash-keys sizes) (hash-keys schemas)))
                                   string<?))])
    (match (hash-ref schemas name #f)
      [(list kind arity detail)
       (relation-info name kind arity detail (hash-ref sizes name 0))]
      [_ (relation-info name "relation" #f '() (hash-ref sizes name 0))])))

;; A semantic command is observed at two settled points.  These snapshots are
;; presentation evidence only: a failed observation must never turn an already
;; committed session operation into a reported failure.  N2/N3 will eventually
;; replace this name-keyed stopgap with boundary/VersionKey catalog deltas.
(define (catalog-size-snapshot s)
  (with-handlers ([exn:fail? (lambda (_) #f)])
    (for/hash ([relation (in-list (live-catalog s))])
      (values (relation-info-name relation) (relation-info-size relation)))))

(define (signed-count amount)
  (if (positive? amount) (format "+~a" amount) (~a amount)))

(define (catalog-delta-records before after)
  (cond
    [(and before after)
     (define names
       (sort (remove-duplicates (append (hash-keys before) (hash-keys after)))
             string<?))
     (sort
      (for/list ([name (in-list names)]
                 #:when (or (not (hash-has-key? before name))
                            (not (hash-has-key? after name))
                            (not (= (hash-ref before name) (hash-ref after name)))))
        (define before? (hash-has-key? before name))
        (define after? (hash-has-key? after name))
        (define old-size (if before? (hash-ref before name) 0))
        (define new-size (if after? (hash-ref after name) 0))
        (hasheq 'relation name
                'before (if before? old-size 'null)
                'after (if after? new-size 'null)
                'net (- new-size old-size)))
      (lambda (a b)
        (define an (abs (hash-ref a 'net)))
        (define bn (abs (hash-ref b 'net)))
        (if (= an bn)
            (string<? (hash-ref a 'relation) (hash-ref b 'relation))
            (> an bn))))]
    [else '()]))

(define (internal-relation? name)
  (or (string-prefix? name "$")
      (string-prefix? name "temp")
      (string=? name "_enum")))

(define builtin-diagnostic-relations
  '("div_by_zero" "error" "int_overflow" "malformed_deduction"
    "modulo_by_zero" "mpz_overflow" "mpz_table_overflow" "nan_result"
    "smt_bad_formula" "toint_range" "type_mismatch"))

(define (default-hidden-relation? relation)
  (define name (relation-info-name relation))
  (or (internal-relation? name)
      (and (zero? (relation-info-size relation))
           (member name builtin-diagnostic-relations))))

(define (relation-description relation)
  (define arity (or (relation-info-arity relation) "?"))
  (define detail
    (if (null? (relation-info-detail relation))
        ""
        (format " · ~a" (string-join (map ~a (relation-info-detail relation)) " "))))
  (format "~a/~a  ~a~a  ~a row~a"
          (relation-info-name relation)
          arity
          (relation-info-kind relation)
          detail
          (relation-info-size relation)
          (if (= (relation-info-size relation) 1) "" "s")))

(define (tables-result state argument)
  (define catalog (live-catalog (ensure-session! state)))
  (define filter-text (string-trim argument))
  (define visible
    (filter
     (lambda (relation)
       (define name (relation-info-name relation))
       (cond
         [(string=? filter-text "all") #t]
         [(string=? filter-text "") (not (default-hidden-relation? relation))]
         [else (string-contains? name filter-text)]))
     catalog))
  (text-result
   "Live relations"
   (if (null? visible)
       (list (if (string=? filter-text "")
                 "no user relations; use `tables all` to include internals"
                 (format "no relations match ~s" filter-text)))
       (map relation-description visible))
   #:kind "tables"))

(define (relation-from-catalog who catalog name)
  (or (findf (lambda (relation) (string=? (relation-info-name relation) name))
             catalog)
      (error who "no live relation named ~a; use `tables` to inspect the catalog" name)))

(define (count-result state argument)
  (define name (string-trim argument))
  (when (string=? name "") (error 'count "expected: count REL"))
  (define relation
    (relation-from-catalog 'count (live-catalog (ensure-session! state)) name))
  (text-result (format "Count ~a" name)
               (list (format "~a row~a"
                             (relation-info-size relation)
                             (if (= (relation-info-size relation) 1) "" "s")))
               #:kind "query"))

(define (show-result state argument)
  (match-define (list* rel options) (read-command-data 'show argument))
  (define name (relation-key rel))
  (define limit
    (match options
      ['() 20]
      [(list (? exact-positive-integer? n)) n]
      [(list 'all) max-show-facts]
      [_ (error 'show "expected: show REL [positive LIMIT | all]")]))
  (define s (ensure-session! state))
  (define relation (relation-from-catalog 'show (live-catalog s) name))
  (define size (relation-info-size relation))
  (when (> size max-show-facts)
    (error 'show
           (string-append
            "relation ~a has ~a rows; row display is capped at ~a because the current daemon "
            "can only stream a whole relation. Use `count ~a` or `query ~a V...` instead")
           name size max-show-facts name name))
  (define raw
    (session-action! s `(dump-tuples ,(string->symbol name))
                     (read-until-response #px"^\\(tupledone [0-9]+\\)$")))
  (define rows
    (for/list ([line (in-list raw)]
               #:do [(define datum (read-datum line))]
               #:when (match datum [`(tuplerow ,_ ...) #t] [_ #f]))
      (match datum
        [`(tuplerow ,values ...)
         (format "(~a~a)"
                 name
                 (if (null? values)
                     ""
                     (string-append " " (string-join (map ~s values) " "))))])))
  (define shown (take rows (min limit (length rows))))
  (text-result
   (format "Rows · ~a" name)
   (append shown
           (if (> (length rows) (length shown))
               (list (format "… ~a more; use `show ~a all`"
                             (- (length rows) (length shown)) name))
               '())
           (if (null? rows) (list "0 rows") '()))
   #:kind "query"))

(define (query-result state argument)
  (match-define (list* rel values) (read-command-data 'query argument #:minimum 2))
  (define name (relation-key rel))
  (define reply
    (session-action! (ensure-session! state)
                     `(lookup ,(string->symbol name) ,@values)
                     read-one-response))
  (define found?
    (match (and (pair? reply) (read-datum (first reply)))
      [`(found ,_ 1) #t]
      [`(found ,_ 0) #f]
      [other (error 'query "unexpected lookup response: ~a" other)]))
  (text-result
   (format "Query · ~a" name)
   (list (format "~a — ~a row matches prefix ~s"
                 (if found? "yes" "no") name values))
   #:kind "query"))

(define (pipeline-datum s)
  (define lines (session-action! s '(pipeline) read-one-response))
  (and (pair? lines) (read-datum (first lines))))

(define (settled-session-state s)
  (with-handlers ([exn:fail? (lambda (_) (values 'null "unknown"))])
    (define revision
      (match (pipeline-datum s)
        [`(pipeline (pos ,_) (evaluation ,_) (update-epoch ,epoch) ,_ ...) epoch]
        [_ 'null]))
    (define counts
      (match (session-action! s '(update-counts-valid) read-one-response)
        [(list line)
         (match (read-datum line)
           [`(update-counts-valid 1) "valid"]
           [`(update-counts-valid 0) "invalid"]
           [_ "unknown"])]
        [_ "unknown"]))
    (values revision counts)))

(define (route-records events)
  (for/list ([line (in-list events)]
             #:do [(define datum (read-datum line))]
             #:when (match datum [`(route ,_ ,_ ...) #t] [_ #f]))
    (match datum
      [`(route ,kind ,detail ...)
       (hasheq 'kind (~a kind) 'detail (map ~a detail))])))

(define max-change-relations 8)

(define (assemble-change operation target status requested events before after
                         revision counts)
  (define deltas (catalog-delta-records before after))
  (define shown (take deltas (min max-change-relations (length deltas))))
  (hasheq 'operation operation
          'status status
          'target target
          'update-revision revision
          'counts counts
          'requested requested
          'size-deltas shown
          'size-deltas-omitted (- (length deltas) (length shown))
          'sizes-observed (and before after #t)
          'routes (route-records events)))

(define (make-change s operation target status requested events before after)
  (define-values (revision counts) (settled-session-state s))
  (assemble-change operation target status requested events before after
                   revision counts))

(define (capture-semantic-change state rs operation status requested thunk)
  (define s (repl-session-session rs))
  (define before (catalog-size-snapshot s))
  (define-values (value events) (capture-session-events state thunk))
  (define after (catalog-size-snapshot s))
  (values value
          events
          (make-change s operation (or (repl-session-database rs) "scratch")
                       status requested events before after)))

(define (change-relation-line record)
  (define name (hash-ref record 'relation))
  (define before (hash-ref record 'before))
  (define after (hash-ref record 'after))
  (define net (hash-ref record 'net))
  (format "~a ~a (~a -> ~a)"
          name (signed-count net)
          (if (eq? before 'null) "new" before)
          (if (eq? after 'null) "removed" after)))

(define (change-summary-lines change)
  (define revision (hash-ref change 'update-revision))
  (define state-line
    (string-append
     (hash-ref change 'status)
     (if (eq? revision 'null) "" (format " · update revision ~a" revision))
     (format " · counts ~a" (hash-ref change 'counts))))
  (define requested (hash-ref change 'requested))
  (define size-deltas (hash-ref change 'size-deltas))
  (define routes (hash-ref change 'routes))
  (append
   (list state-line)
   (if (null? requested)
       '()
       (list
        (format "requested: ~a"
                (string-join
                 (for/list ([record (in-list requested)])
                   (define added (hash-ref record 'added 0))
                   (define removed (hash-ref record 'removed 0))
                   (string-append
                    (hash-ref record 'relation)
                    (if (zero? added) "" (format " +~a" added))
                    (if (zero? removed) "" (format " -~a" removed))))
                 "; "))))
   (cond
     [(not (hash-ref change 'sizes-observed))
      (list "relation sizes: unavailable")]
     [(null? size-deltas) (list "relation sizes: unchanged")]
     [else
      (list (format "size changes: ~a"
                    (string-join (map change-relation-line size-deltas) "; ")))])
   (if (positive? (hash-ref change 'size-deltas-omitted))
       (list (format "...and ~a more relation-size changes"
                     (hash-ref change 'size-deltas-omitted)))
       '())
   (if (null? routes)
       '()
       (list
        (format "route: ~a"
                (string-join
                 (for/list ([record (in-list routes)])
                   (string-join
                    (cons (hash-ref record 'kind) (hash-ref record 'detail)) " "))
                 "; "))))))

(define (semantic-text-result title lines change #:kind kind)
  (text-result title (append lines (change-summary-lines change))
               #:kind kind #:change change))

(define (state-result state argument)
  (define rs (ensure-session-record! state))
  (define datum (pipeline-datum (repl-session-session rs)))
  (match datum
    [`(pipeline (pos ,position) (evaluation ,_evaluation)
                (update-epoch ,epoch) (strata ,strata ...)
                (version-ids ,versions ...) ,relations ...)
     (define requested (string-trim argument))
     (define base
       (list
        (format "database: ~a" (or (repl-session-database rs) "scratch"))
        (format "access: ~a · ~a"
                (repl-session-mode rs)
                (if (repl-session-changed? rs) "extended" "clean"))
        (format "pipeline: position ~a · ~a strata · update epoch ~a"
                position (length strata) epoch)
        (format "state: ~a relation names · ~a live versions"
                (length relations) (length versions))))
     (cond
       [(string=? requested "")
        (text-result "Database state" base #:kind "state")]
       [else
        (define rel-state
          (findf (lambda (entry)
                   (match entry [`(rel ,name ,_ ...) (string=? (~a name) requested)] [_ #f]))
                 relations))
        (unless rel-state
          (error 'state "no version state for relation ~a" requested))
        (define version-lines
          (match rel-state
            [`(rel ,_ ,entries ...)
             (for/list ([entry (in-list entries)] [index (in-naturals)])
               (match entry
                 [`(v ,ordinal ,binding ,size)
                  (format "@v~a  binding ~a · ~a row~a~a"
                          ordinal binding size (if (= size 1) "" "s")
                          (if (= index (sub1 (length entries))) " · current" ""))]))]))
        (text-result (format "State · ~a" requested)
                     (append base version-lines)
                     #:kind "state")])]
    [other (error 'state "unparseable pipeline response: ~a" other)]))

(define (open-database! state name)
  (unless (db-exists? name) (error 'open "no database named ~a under data/" name))
  (define sessions (server-state-sessions state))
  (cond
    [(hash-ref sessions name #f)
     (set-server-state-current! state name)
     (text-result (format "Switched to ~a" name)
                  (list "resident database selected; in-memory extensions were preserved")
                  #:kind "open")]
    [else
     (define rs (make-repl-session state name))
     (define replay?
       (for/or ([step (in-list (db-load-steps name))])
         (match step [`(replay ,_ ,_) #t] [`(replay-recipe ,_) #t] [_ #f])))
     (define-values (_ events change)
       (with-handlers
           ([exn:fail?
             (lambda (e)
               (with-handlers ([exn:fail? void])
                 (session-close! (repl-session-session rs)))
               (raise e))])
         (capture-semantic-change
          state rs "open" "settled" '()
          (lambda () (session-open! (repl-session-session rs) name)))))
     (hash-set! sessions name rs)
     (set-server-state-current! state name)
     (semantic-text-result
      (format "Opened ~a" name)
      (append
       (list (if replay?
                 "compressed load materialized retained data and recomputed replay layers"
                 "database loaded into a new mutable in-memory workspace"))
       (list "Try `current`, `tables`, `state`, `show REL`, or `query REL V...`."))
      change
      #:kind "open")]))

(define (current-result state)
  (define rs (current-repl-session state))
  (text-result
   "Current database"
   (if rs
       (list (format "database: ~a" (or (repl-session-database rs) "scratch"))
             (format "access: ~a" (repl-session-mode rs))
             (format "memory: ~a"
                     (if (repl-session-changed? rs) "extended in memory" "clean"))
             "Observe with `tables`, `state`, `count`, `show`, and `query`."
             "Extend with `run`, `add`, and `del` while the mode is mutable.")
       (list "no current database; use `library` or `open NAME`"))
   #:kind "current"))

(define (resident-result state)
  (define sessions (session-summaries state))
  (text-result
   "Resident databases"
   (if (null? sessions)
       (list "none; use `library` or `open NAME`")
       (for/list ([summary (in-list sessions)])
         (format "~a  ~a · ~a~a"
                 (hash-ref summary 'name)
                 (hash-ref summary 'mode)
                 (if (hash-ref summary 'changed) "extended" "clean")
                 (if (hash-ref summary 'current) " · current" ""))))
   #:kind "resident"))

(define (mode-result state argument)
  (define rs (ensure-session-record! state))
  (define mode
    (match (string-downcase (string-trim argument))
      ["" (repl-session-mode rs)]
      [(or "readonly" "read-only" "ro") 'readonly]
      [(or "mutable" "read-write" "rw") 'mutable]
      [_ (error 'mode "expected: mode readonly | mutable")]))
  (set-repl-session-mode! rs mode)
  (text-result "Database access"
               (list (format "~a is now ~a"
                             (or (repl-session-database rs) "scratch") mode))
               #:kind "mode"))

(define (dispatch-command state source)
  (define-values (verb argument) (split-command source))
  (define result
    (match verb
    ["" (text-result "Slog" '())]
    [(or ":help" "help" "?") (text-result "Help" help-lines #:kind "help")]
    [(or ":ping" "ping")
     (text-result "Protocol"
                  (list "pong" "Racket server answered over private loopback TCP.")
                  #:kind "status")]
    [(or ":status" "status")
     (define rs (current-repl-session state))
     (text-result
      "REPL status"
      (list (format "protocol: ~a" protocol-version)
            (format "slog: ~a" slog-version)
            (format "racket: ~a" (version))
            (format "current: ~a"
                    (if rs (or (repl-session-database rs) "scratch") "none"))
            (format "resident databases: ~a"
                    (hash-count (server-state-sessions state))))
      #:kind "status")]
    ["library"
     (define selected
       (cond
         [(string=? argument "") 'null]
         [(string-prefix? argument "select ")
          (define name (string-trim (substring argument (string-length "select "))))
          (when (string=? name "")
            (error 'library "expected: library select NAME"))
          (unless (db-exists? name)
            (error 'library "no database named ~a under data/" name))
          name]
         [else (error 'library "expected: library [select NAME | close]")]))
     (hasheq 'kind "library"
             'title "Database library"
             'selected selected
             'databases (db-library-summaries))]
    [(or "open" "use")
     (when (string=? argument "")
       (error 'open "expected: open NAME"))
     (open-database! state argument)]
    [(or "current" "database") (current-result state)]
    [(or "resident" "sessions") (resident-result state)]
    ["mode" (mode-result state argument)]
    [(or "tables" "rels" "relations") (tables-result state argument)]
    [(or "state" "states") (state-result state argument)]
    ["count" (count-result state argument)]
    ["show" (show-result state argument)]
    [(or "query" "has") (query-result state argument)]
    ["run"
     (when (string=? argument "")
       (error 'run "expected: run PATH"))
     (define rs (ensure-mutable-session-record! state 'run))
     (define-values (_ _events change)
       (capture-semantic-change
        state rs "run" "settled" '()
        (lambda () (session-run! (repl-session-session rs) argument))))
     (set-repl-session-changed?! rs #t)
     (semantic-text-result
      (format "Run ~a" argument)
      (list "program completed at a settled daemon boundary")
      change
      #:kind "run")]
    [(or "add" "del")
     (match-define (list* rel values)
       (read-command-data (string->symbol verb) argument #:minimum 2))
     (define rs (ensure-mutable-session-record! state (string->symbol verb)))
     (define requested
       (list (hasheq 'relation (relation-key rel)
                     'added (if (string=? verb "add") 1 0)
                     'removed (if (string=? verb "del") 1 0))))
     (define-values (_ _events change)
       (capture-semantic-change
        state rs verb "settled" requested
        (lambda ()
          (session-batch! (repl-session-session rs)
                          (if (string=? verb "add") '+ '-)
                          (string->symbol (relation-key rel))
                          values)
          (session-flush! (repl-session-session rs)))))
     (set-repl-session-changed?! rs #t)
     (semantic-text-result
      (format "~a · ~a" (string-titlecase verb) (relation-key rel))
      (list (format "(~a ~a)" (relation-key rel)
                    (string-join (map ~s values) " ")))
      change
      #:kind "mutation")]
    ["rename"
     (match (read-command-data 'rename argument #:minimum 2)
       [(list from to)
        (define rs (ensure-mutable-session-record! state 'rename))
        (define-values (_ _events change)
          (capture-semantic-change
           state rs "rename" "settled" '()
           (lambda ()
             (session-rename! (repl-session-session rs)
                              (string->symbol (relation-key from))
                              (string->symbol (relation-key to))))))
        (set-repl-session-changed?! rs #t)
        (semantic-text-result
         (format "Renamed ~a to ~a" (relation-key from) (relation-key to))
         (list "relation identity was rebound without moving tuple data")
         change
         #:kind "mutation")]
       [_ (error 'rename "expected: rename FROM TO")])]
    ["drop"
     (match (read-command-data 'drop argument)
       [(list rel)
        (define rs (ensure-mutable-session-record! state 'drop))
        (define-values (_ _events change)
          (capture-semantic-change
           state rs "drop" "settled" '()
           (lambda ()
             (session-drop! (repl-session-session rs)
                            (string->symbol (relation-key rel))))))
        (set-repl-session-changed?! rs #t)
        (semantic-text-result
         (format "Dropped ~a" (relation-key rel))
         (list "relation name was removed from the live environment")
         change
         #:kind "mutation")]
       [_ (error 'drop "expected: drop REL")])]
    ["schema"
     (define s (ensure-session! state))
     (define lines
       (session-action! s '(schema)
                        (read-until-response #px"^\\(schema-end\\)$")))
     (text-result "Schema" lines #:kind "schema")]
    ["pipeline"
     (define s (ensure-session! state))
     (text-result "Pipeline"
                  (session-action! s '(pipeline) read-one-response)
                  #:kind "pipeline")]
    ["save"
     (when (string=? argument "")
       (error 'save "expected: save NAME"))
     (define rs (ensure-mutable-session-record! state 'save))
     (define-values (_ _events change)
       (capture-semantic-change
        state rs "save" "saved" '()
        (lambda () (session-save! (repl-session-session rs) argument))))
     (semantic-text-result
      (format "Saved ~a" argument)
      (list "database materialization and replay recipe were written")
      change
      #:kind "save")]
    [(or ":quit" "quit" "exit")
     (set-server-state-closing?! state #t)
     (hasheq 'kind "quit" 'title "Goodbye" 'lines (list "REPL closed") 'close #t)]
    [_
     (error 'command
            (format "unknown command ~a; type :help for the current command set" verb))]))
  (attach-session-state state result))

;; Deterministic transcript projection for the server contract.  This is a
;; test harness, not a second interactive frontend: the future Rust --plain
;; mode must render the same structured responses and is golden-compared to
;; this projection before it replaces the harness at the executable boundary.
(define (plain-command-result source result)
  (define title (hash-ref result 'title))
  (define lines (hash-ref result 'lines '()))
  (string-append
   (format "› ~a\n◆ ~a" source title)
   (if (null? lines)
       ""
       (format "\n  ~a" (string-join lines "\n  ")))))

(define (wire-round-trip value)
  (define out (open-output-bytes))
  (write-frame out value)
  (read-frame (open-input-bytes (get-output-bytes out))))

(define (plain-transcript commands)
  (define state (server-state (make-hash) #f #f #f))
  (dynamic-wind
    void
    (lambda ()
      (string-append
       (string-join
        (for/list ([command (in-list commands)]
                   #:break (server-state-closing? state))
          (with-handlers
              ([exn:fail?
                (lambda (e)
                  (format "› ~a\n! Command failed\n  ~a" command
                          (exn-message e)))])
            (plain-command-result
             command
             (wire-round-trip (dispatch-command state command)))))
        "\n")
       "\n"))
    (lambda () (close-server-session! state))))

(define (request-id request)
  (hash-ref request 'id 0))

(define (serve-request state request)
  (define id (request-id request))
  (with-handlers ([exn:fail?
                   (lambda (e)
                     (failure id "command" (exn-message e)))])
    (match (hash-ref request 'method #f)
      ["command"
       (define params (hash-ref request 'params (hasheq)))
       (success id
                (dispatch-command state (hash-ref params 'line "")))]
      ["shutdown"
       (set-server-state-closing?! state #t)
       (success id
                (hasheq 'kind "quit" 'title "Goodbye"
                        'lines (list "session closed") 'close #t))]
      [method
       (failure id "protocol" (format "unknown method: ~a" method))])))

(define (authenticate! in out token)
  (define request (read-frame in))
  (cond
    [(eof-object? request) #f]
    [else
     (define id (request-id request))
     (define params (hash-ref request 'params (hasheq)))
     (define valid?
       (and (equal? (hash-ref request 'method #f) "hello")
            (equal? (hash-ref params 'token #f) token)
            (equal? (hash-ref params 'protocol #f) protocol-version)))
     (if valid?
         (begin
           (write-frame
            out
            (success
             id
             (hasheq 'kind "hello"
                     'protocol protocol-version
                     'server "slog-racket-session"
                     'slog-version slog-version
                     'features
                     (list "compile" "session" "daemon" "schema" "pipeline"))))
           #t)
         (begin
           (write-frame out (failure id "authentication" "REPL handshake rejected"))
           #f))]))

(define (open-loopback-listener requested-port)
  (define (listen port)
    (values (tcp-listen port 1 #t "127.0.0.1") port))
  (cond
    [(positive? requested-port) (listen requested-port)]
    [else
     (let loop ([attempt 0])
       (when (>= attempt 256)
         (error 'serve-repl "could not allocate a private loopback port"))
       (define candidate (+ 20000 (random 40000)))
       (with-handlers ([exn:fail:network? (lambda (_) (loop (add1 attempt)))])
         (listen candidate)))]))

(define (close-server-session! state)
  (for ([rs (in-hash-values (server-state-sessions state))])
    (with-handlers ([exn:fail? (lambda (e)
                                 (eprintf "REPL session cleanup failed: ~a\n"
                                          (exn-message e)))])
      (session-close! (repl-session-session rs))))
  (hash-clear! (server-state-sessions state))
  (set-server-state-current! state #f))

(define (serve-connection in out token)
  (define state (server-state (make-hash) #f #f #f))
  (dynamic-wind
    void
    (lambda ()
      (when (authenticate! in out token)
        (let loop ()
          (unless (server-state-closing? state)
            (define request (read-frame in))
            (unless (eof-object? request)
              (write-frame out (serve-request state request))
              (loop))))))
    (lambda () (close-server-session! state))))

(define (serve-repl #:port [requested-port 0]
                    #:token [token (getenv "SLOG_REPL_TOKEN")])
  (unless (and token (not (string=? token "")))
    (error 'serve-repl "SLOG_REPL_TOKEN is required"))
  (define-values (listener port)
    (open-loopback-listener requested-port))
  (dynamic-wind
    void
    (lambda ()
      ;; This one line is a bootstrap announcement on the inherited private
      ;; pipe.  All subsequent communication is framed on the TCP connection.
      (write-json (hasheq 'host "127.0.0.1"
                          'port port
                          'protocol protocol-version))
      (newline)
      (flush-output)
      (define-values (in out) (tcp-accept listener))
      (tcp-close listener)
      (set! listener #f)
      (dynamic-wind
        void
        (lambda () (serve-connection in out token))
        (lambda ()
          (close-input-port in)
          (close-output-port out))))
    (lambda () (when listener (tcp-close listener)))))

(module+ main
  (define port 0)
  (command-line
   #:program "racket compiler/repl.rkt"
   #:once-each
   [("--port") value "Loopback TCP port (0 chooses a private high port)"
                 (set! port (or (string->number value)
                                (error 'repl "invalid port: ~a" value)))]
   #:args ()
   (void))
  (serve-repl #:port port))

(module+ test
  (require rackunit
           racket/runtime-path)

  (define-runtime-path semantic-session-golden
    "../tests/expected/repl/semantic-session.txt")
  (define-runtime-path repository-root "..")

  (define out (open-output-bytes))
  (write-frame out (hasheq 'id 7 'method "ping"))
  (define framed (get-output-bytes out))
  (check-equal? (read-frame (open-input-bytes framed))
                (hasheq 'id 7 'method "ping"))

  (define state (server-state (make-hash) #f #f #f))
  (check-equal? (hash-ref (dispatch-command state ":help") 'kind) "help")
  (check-equal? (hash-ref (dispatch-command state ":ping") 'kind) "status")
  (define library-result (dispatch-command state "library"))
  (check-equal? (hash-ref library-result 'kind) "library")
  (when (pair? (hash-ref library-result 'databases))
    (define existing-name (hash-ref (first (hash-ref library-result 'databases)) 'name))
    (check-equal?
     (hash-ref (dispatch-command state (format "library select ~a" existing-name)) 'selected)
     existing-name))
  (check-exn #px"no database named"
             (lambda ()
               (dispatch-command state "library select __missing_repl_test_database__")))
  (check-exn #px"expected: library"
             (lambda () (dispatch-command state "library next")))
  (check-equal? (hash-ref (dispatch-command state ":status") 'lines)
                (list (format "protocol: ~a" protocol-version)
                      (format "slog: ~a" slog-version)
                      (format "racket: ~a" (version))
                      "current: none"
                      "resident databases: 0"))
  (check-equal? (hash-ref (dispatch-command state "current") 'lines)
                (list "no current database; use `library` or `open NAME`"))
  (check-equal? (hash-ref (dispatch-command state "sessions") 'sessions) '())
  (check-equal? (hash-ref (dispatch-command state "resident") 'title)
                "Resident databases")

  (check-equal?
   (catalog-delta-records (hash "a" 2 "b" 0) (hash "a" 5 "c" 0))
   (list (hasheq 'relation "a" 'before 2 'after 5 'net 3)
         (hasheq 'relation "b" 'before 0 'after 'null 'net 0)
         (hasheq 'relation "c" 'before 'null 'after 0 'net 0)))

  (define sample-request
    (list (hasheq 'relation "edge" 'added 1 'removed 0)))
  (define sample-change
    (assemble-change "add" "scratch" "settled" sample-request
                     (list "(route maintain 2)")
                     (hash "edge" 3) (hash "edge" 4)
                     7 "valid"))
  (check-equal?
   (wire-round-trip sample-change)
   (hasheq 'operation "add"
           'status "settled"
           'target "scratch"
           'update-revision 7
           'counts "valid"
           'requested sample-request
           'size-deltas
           (list (hasheq 'relation "edge" 'before 3 'after 4 'net 1))
           'size-deltas-omitted 0
           'sizes-observed #t
           'routes (list (hasheq 'kind "maintain" 'detail (list "2")))))

  (define mode-state (server-state (make-hash) #f #f #f))
  (hash-set! (server-state-sessions mode-state)
             "alpha"
             (repl-session #f "alpha" 'readonly #f))
  (set-server-state-current! mode-state "alpha")
  (check-true
   (regexp-match?
    #px"current database is read-only"
    (with-handlers ([exn:fail? exn-message])
      (ensure-mutable-session-record! mode-state 'test)
      "mutation unexpectedly allowed")))
  (define mutable-result (dispatch-command mode-state "mode mutable"))
  (check-equal? (hash-ref mutable-result 'current) "alpha")
  (check-equal? (hash-ref (first (hash-ref mutable-result 'sessions)) 'mode)
                "mutable")
  (check-equal? (hash-ref (dispatch-command mode-state "resident") 'lines)
                (list "alpha  mutable · clean · current"))
  (define quit-state (server-state (make-hash) #f #f #f))
  (check-true (hash-ref (dispatch-command quit-state ":quit") 'close))
  ;; The golden deliberately stops at the server contract.  It proves real
  ;; session calls and deterministic presentation data without making this
  ;; Racket process a competing user-facing frontend.
  (define test-environment
    (environment-variables-copy (current-environment-variables)))
  (environment-variables-set! test-environment #"SLOG_NO_MEM_CAP" #"1")
  (check-equal?
   (parameterize ([current-directory repository-root]
                  [current-environment-variables test-environment])
     (plain-transcript
      (list "open sess_w2.edb"
            "add edge 1 2"
            "add edge 4 5"
            "del edge 4 5"
            "rename edge input_edge"
            "drop path"
            ":quit")))
   (file->string semantic-session-golden)))
