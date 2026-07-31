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
         plain-transcript  ; deterministic server-contract harness
         ;; stateful harness surface (gate S / R4 batteries): a server
         ;; state plus the single command entry point, for tests that
         ;; must interleave commands with session-level hooks (e.g.
         ;; querying a parked epoch from session-pause-hook).  This is a
         ;; test surface, not a second frontend: rendering stays with
         ;; plain-transcript and the Rust client.
         make-server-state
         dispatch-command)

(require json
         racket/cmdline
         racket/match
         racket/port
         racket/string
         racket/tcp
         "catalog.rkt"   ; N4-B attachment plan projection
         "dbtool.rkt"
         "names.rkt"
         "params.rkt"
         "query-front.rkt" ; the R2 `?` register grammar
         "query-plan.rkt"  ; Q1 catalog planner + ABI-1 wire emission
         "session.rkt")

(define protocol-version 1)
(define default-max-frame-bytes (* 16 1024 1024))

(struct repl-session (session database [mode #:mutable] [changed? #:mutable]
                              ;; the EvaluationId this session's daemon is in;
                              ;; a value handle is only valid within it
                              [evaluation #:mutable]
                              ;; the held Q1 cursor (query-cursor) or #f;
                              ;; `more` pulls it, `cancel` or any command
                              ;; that needs the daemon discards it
                              [cursor #:mutable]
                              ;; id -> watch-intent: what the user asked to
                              ;; observe, settled at every semantic barrier
                              watches
                              ;; path -> #t: files this session already wrote
                              ;; via `keep scratch as F` -- re-keeping into
                              ;; the same file is a workflow, so those paths
                              ;; may be overwritten; unrelated files may not
                              kept)
  #:transparent)

;; One Racket REPL connection can own several independent compiler sessions.
;; A database name is the key for a database-backed session; the 'scratch key
;; is reserved for the lazy, database-less session used by `run` before an
;; `open`.  Switching only changes `current`, so every session keeps its own
;; daemon, pipeline, mutations, and replayed database in memory.
(struct server-state (sessions
                      [current #:mutable]
                      [event-sink #:mutable]
                      [closing? #:mutable]
                      ;; label -> value-handle, the checked `#N` table
                      handles)
  #:transparent)

(struct relation-info
  (name kind arity detail size version-key boundary-key)
  #:transparent)

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
   #f
   #f
   #f
   (make-hash)
   (make-hash)))

;; a fresh, connection-less server state -- the stateful harness entry
(define (make-server-state)
  (server-state (make-hash) #f #f #f (make-hash)))

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
   "  ?(REL V...)         query the committed boundary; also"
   "                      ? (a X Y) (b Y Z) (< Z 9) -> (X Z)  and  ~ absence"
   "  ?count ?exists      the same query without materializing rows"
   "  more | cancel       pull or discard the held query cursor"
   "  dump ?QUERY to F    stream every answer row into a CSV file"
   "  uses #N | VALUE     which relations contain a value (`find` = alias)"
   "  watch REL | ?QUERY  observe a relation (daemon barrier hits) or a"
   "                      query count; reports ride each change summary"
   "  watch REL level 1   arm the pre-commit gate intent; the relation's"
   "                      writer strata pin to the interpreter (debug)"
   "  unwatch wN          remove one watch;  `watches` lists them"
   "  explain ?QUERY      show the query plan and degradations, do not run"
   "  tiers               show each stratum's execution rung (interp/-O0/-O2)"
   "  code sN | HASH      show one stratum's rung, artifacts, and plan shape"
   "  catalog             show the selected boundary, history, and types"
   "  schema              show the daemon's raw live schema"
   "  pipeline            show the daemon's raw versioned pipeline"
   ""
   "Extend a mutable database"
   "  run PATH            compile and run a .slog program"
   "  rule ...| table ... a Slog definition is a scratch fragment; it"
   "                      compiles against the live schema and runs now"
   "  scratch             show the scratch layer's accumulated program"
   "  keep scratch as F   export the scratch layer to F and promote it"
   "  clear scratch       retract the whole scratch layer"
   "  add REL V...        add one input tuple and propagate it"
   "  del REL V...        retract one input tuple and propagate it"
   "  stage +(R V..) -(..) queue signed edits; `status` shows them pending"
   "  flush               commit everything staged as one update epoch"
   "  recount [force]     re-establish (or force-rebuild) the count cache"
   "  counts REL          dump one relation's count sidecar rows"
   "  rename FROM TO      rename one live relation without moving its data"
   "  drop REL            remove one relation name at the next boundary"
   "  attach DB as DEST   import a saved database under one namespace"
   "  attach DB SRC as DEST   import one subtree of a saved database"
   "  save NAME           save the current database as data/NAME; a live"
   "                      scratch layer must be kept, cleared, or baked"
   "                      explicitly (`save NAME with scratch`)"
   ""
   "Workbench"
   "  :status             show REPL, current database, and daemon state"
   "  :ping               round-trip through the private TCP protocol"
   "  :help               show these commands"
   "  :quit               close every resident database and the REPL"
   "  :clear              clear the visible client transcript"
   "  :share              show the trusted-local co-author endpoint"
   "  expand POSITION     expand a node in the newest live result canvas"
   "  collapse POSITION   collapse a node in the newest live result canvas"
   "  card POSITION       show the contextual card for a live canvas node"
   "  search TEXT         search visible lines in the newest live result canvas"
   "  search-next         select the next visible canvas search match"
   "  search-previous     select the previous visible canvas search match"
   "  search-clear        clear the current canvas search"
   "  page POSITION N     select an absolute page in a buffered canvas collection"
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

;; ---- the value-handle table (repl.md §1) ----------------------------------
;;
;; `#N` denotes ONE concrete runtime value.  The daemon states a value's
;; encoded word, kind, struct id, and TypeKey; the word is identity only
;; inside one evaluation's interner state, so the handle records the
;; evaluation it was minted in and resolving it anywhere else refuses.  That
;; check is the whole point of the table: a stale word would otherwise decode
;; as some unrelated live value rather than as an error.

(struct value-cell (word kind sid type-key text) #:transparent)
;; depth = the preview depth the stored cell's text was rendered at, or #f
;; when the text is complete; `show #N` deepens it in place.
(struct value-handle (label evaluation database cell depth) #:transparent)

(define (datum->value-cell datum)
  (match datum
    [`(cell (word ,(? exact-nonnegative-integer? word))
            (kind ,(? symbol? kind))
            (sid ,sid)
            (type-key ,type-key)
            (text ,(? string? text)))
     (value-cell word kind (and sid sid) (and type-key type-key) text)]
    [_ (error 'value-adapter "malformed value cell: ~s" datum)]))

;; Scalars render as themselves and re-type trivially; a handle earns its
;; keep for values a user cannot retype -- structs and collections.
(define (handle-worthy? cell)
  (and (memq (value-cell-kind cell) '(struct collection sequence)) #t))

(define (session-evaluation s)
  (match (session-action! s '(pipeline) read-one-response)
    [(list line)
     (match (read-datum line)
       [`(pipeline ,fields ...)
        (match (assq 'evaluation fields)
          [(list _ (? string? id)) id]
          [_ #f])]
       [_ #f])]
    [_ #f]))

;; The EvaluationId is minted once per session's daemon, so read it once and
;; cache it; every handle this session mints is stamped with it.
(define (ensure-evaluation! state s)
  (define rs (current-repl-session state))
  (when (and rs (not (repl-session-evaluation rs)))
    (set-repl-session-evaluation! rs (session-evaluation s)))
  rs)

;; depth: the preview depth `cell` was rendered at (#f = complete text).
;; One word mints once; re-sighting the same word with a DEEPER rendering
;; upgrades the stored cell in place, so a handle never regresses to a
;; shallower preview than the user has already been shown.
(define (mint-value-handle! state cell #:depth [depth #f])
  (define rs (current-repl-session state))
  (and rs
       (let* ([handles (server-state-handles state)]
              [existing
               (for/first ([(label handle) (in-hash handles)]
                           #:when (and (equal? (value-handle-database handle)
                                               (repl-session-database rs))
                                       (= (value-cell-word
                                           (value-handle-cell handle))
                                          (value-cell-word cell))))
                 handle)])
         (cond
           [existing
            (define stored (value-handle-depth existing))
            (when (and stored (or (not depth) (> depth stored)))
              (hash-set! handles (value-handle-label existing)
                         (struct-copy value-handle existing
                           [cell cell] [depth depth])))
            (value-handle-label existing)]
           [else
            (define label (format "#~a" (add1 (hash-count handles))))
            (hash-set! handles label
                       (value-handle label
                                     (repl-session-evaluation rs)
                                     (repl-session-database rs)
                                     cell depth))
            label]))))

;; The live sid -> TypeKey binding, from N3-C's independent registry.  A
;; struct handle records the DURABLE TypeKey beside the runtime sid, so a sid
;; that has since been freed and reissued to a different constructor is
;; detectable: the word still decodes, but it decodes as the wrong type.
(define (live-sid-type-keys s)
  (for/fold ([out (hash)])
            ([line (in-list
                    (session-command-stream!
                     s '(catalog types)
                     (lambda (line)
                       (regexp-match? #px"^\\(catalog-end " line))))])
    (match (read-datum line)
      [`(catalog-type (sid ,sid) (name ,_) (arity ,_) (type-key ,key))
       (if key (hash-set out sid key) out)]
      [_ out])))

;; Resolve `#N` against the session that minted it.  A handle from another
;; database, from an evaluation this session no longer is, or whose struct id
;; has been reissued to a different constructor is refused -- never silently
;; re-decoded.
;;
;; What this does NOT check is liveness: a value retracted within the same
;; evaluation still resolves and still renders, because M5 keeps the struct id
;; alive as a tombstone.  Holding a handle to a value you deleted is arguably
;; the point of a handle; a presence probe would be a separate daemon verb.
(define (resolve-value-handle state label)
  (define rs (current-repl-session state))
  (define handle (hash-ref (server-state-handles state) label #f))
  (cond
    [(not handle) (error 'handle "no such value handle: ~a" label)]
    [(not rs) (error 'handle "~a needs a live session" label)]
    [(not (equal? (value-handle-database handle) (repl-session-database rs)))
     (error 'handle
            "~a was minted in ~a and cannot be resolved in ~a"
            label
            (or (value-handle-database handle) "scratch")
            (or (repl-session-database rs) "scratch"))]
    [(not (equal? (value-handle-evaluation handle)
                  (repl-session-evaluation rs)))
     (error 'handle
            "~a is stale: it was minted in a previous evaluation of ~a"
            label (or (value-handle-database handle) "scratch"))]
    [else
     (define drift
       (and (repl-session-session rs)
            (value-handle-type-drift
             (value-handle-cell handle)
             (live-sid-type-keys (repl-session-session rs)))))
     (when drift (error 'handle "~a is no longer valid: ~a" label drift))
     handle]))

;; #f when the handle's constructor identity still holds; otherwise why not.
;; A non-struct cell carries no sid and cannot drift this way.
(define (value-handle-type-drift cell live-keys)
  (define sid (value-cell-sid cell))
  (define recorded (value-cell-type-key cell))
  (and sid recorded
       (let ([live (hash-ref live-keys sid #f)])
         (and (not (equal? live recorded))
              (format
               "struct id ~a now belongs to ~a, not the constructor this value was minted from (~a)"
               sid (or live "no live type") recorded)))))

;; N3-B's command catalog is relation identity authority: every current record
;; carries its exact VersionKey and selected committed BoundaryKey (or #f after
;; a legacy environment mutation).  The legacy schema stream still contributes
;; human field detail; N3-C's TypeDescriptor stream now owns nominal TypeKey/SID
;; identity, while richer declaration-field projection remains with N3-D/N4.
;; N4-A work order 6: the SELECTED LOGICAL BOUNDARY is the schema authority.
;; The session's committed head owns every declaration, its qualified field
;; graph, its VersionKey, and its nominal TypeKey; the daemon contributes only
;; what it alone knows -- how many rows are actually there.  A declaration the
;; head holds but no tuple ever reached still appears, which the daemon-side
;; join could never show.
(define (type-detail ref)
  (match ref
    [(type-ref 'primitive name) (~a name)]
    [(type-ref 'named name) (qname->display name)]
    [_ "?"]))

(define (declaration-detail descriptor)
  (define fields (map type-detail (declaration-descriptor-fields descriptor)))
  (define spec (declaration-descriptor-lattice-spec descriptor))
  (if spec
      (append fields (list (format "lattice:~a" (lattice-descriptor-kind spec))))
      fields))

(define (boundary-catalog-projection head sizes)
  (define cat (boundary-catalog head))
  (define declarations (catalog-declarations cat))
  (define environment (boundary-environment head))
  (for/list ([name (in-list (sort (hash-keys environment) qname<?))])
    (define descriptor (hash-ref declarations name))
    (define display-name (qname->display name))
    (define kind (declaration-descriptor-kind descriptor))
    (relation-info
     display-name
     (~a kind)
     (+ (length (declaration-descriptor-fields descriptor))
        (if (eq? kind 'struct) 1 0))
     (declaration-detail descriptor)
     (hash-ref sizes display-name 0)
     (hash-ref environment name)
     (boundary-key head))))

;; Sizes only: the one observation the logical boundary cannot supply.
(define (daemon-relation-sizes s)
  (define lines
    (session-command-stream!
     s '(catalog)
     (lambda (line)
       (regexp-match? #px"^\\(catalog-end [0-9]+\\)$" line))))
  (for/fold ([out (hash)]) ([line (in-list lines)])
    (match (read-datum line)
      [`(catalog-rel ,fields ...)
       (define (field key)
         (match (assq key fields) [(list _ value) value] [_ #f]))
       (define name (field 'name))
       (if (string? name) (hash-set out name (or (field 'size) 0)) out)]
      [_ out])))

(define (live-catalog s)
  (define head (session-current-boundary s))
  (if head
      (boundary-catalog-projection head (daemon-relation-sizes s))
      (legacy-live-catalog s)))

;; The pre-N4 name/size approximation, kept for a catalog-less input: an old
;; database no program has re-declared has no logical boundary to project.
;; Work order 7 retires this once such inputs must be regenerated.
(define (legacy-live-catalog s)
  (define catalog-lines
    (session-command-stream!
     s '(catalog)
     (lambda (line)
       (regexp-match? #px"^\\(catalog-end [0-9]+\\)$" line))))
  (define schema-lines
    (session-action! s '(schema)
                     (read-until-response #px"^\\(schema-end\\)$")))
  (define identities (make-hash))
  (define schemas (make-hash))
  (define (record-field fields key [default #f])
    (match (assq key fields)
      [(list _ value) value]
      [_ default]))
  (for ([line (in-list catalog-lines)])
    (match (read-datum line)
      [`(catalog-rel ,fields ...)
       (define name (record-field fields 'name))
       (when (string? name)
         (hash-set!
          identities name
          (list (~a (record-field fields 'kind "relation"))
                (record-field fields 'arity)
                (or (record-field fields 'size) 0)
                (record-field fields 'version-key)
                (record-field fields 'boundary))))]
      [_ (void)]))
  (for ([line (in-list schema-lines)])
    (match (read-datum line)
      [`(schema-rel ,kind ,name ,arity ,detail ...)
       (hash-set! schemas (relation-key name)
                  (list (~a kind) arity detail))]
      [_ (void)]))
  (for/list ([name (in-list (sort (hash-keys identities) string<?))])
    (match-define (list catalog-kind catalog-arity size version-key boundary-key)
      (hash-ref identities name))
    (match (hash-ref schemas name #f)
      [(list schema-kind schema-arity detail)
       (relation-info name schema-kind schema-arity detail size
                      version-key boundary-key)]
      [_
       (relation-info name catalog-kind catalog-arity '() size
                      version-key boundary-key)])))

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

(define (relation-observation relation)
  (hasheq 'name (relation-info-name relation)
          'kind (relation-info-kind relation)
          'arity (or (relation-info-arity relation) 'null)
          'detail (map ~a (relation-info-detail relation))
          'rows (relation-info-size relation)
          'version-key (or (relation-info-version-key relation) 'null)
          'boundary-key (or (relation-info-boundary-key relation) 'null)))

;; The structured boundary projection (work order 6).  Every record is
;; identity the bundle actually holds -- nothing is inferred from a relation
;; directory or a flat manifest.
(define (module-observation instance)
  (match instance
    [`(module-instance (key ,key) (home ,home ...)
                       (lexical-path (occurrence ,slots ,aliases) ...)
                       (bindings (bind (formal ,formals ...)
                                       (actual ,actuals ...)) ...))
     (hasheq 'key key
             'home (string-join home ".")
             'path (string-join
                    (for/list ([slot (in-list slots)] [alias (in-list aliases)])
                      (format "~a#~a" alias slot))
                    ".")
             'bindings
             (for/list ([formal (in-list formals)] [actual (in-list actuals)])
               (hasheq 'formal (string-join formal ".")
                       'actual (string-join actual "."))))]
    [_ (hasheq 'key "?" 'home "" 'path "" 'bindings '())]))

(define (catalog-result bundle sizes)
  (define head (boundary-bundle-selected-head bundle))
  (define declarations (catalog-declarations (boundary-catalog head)))
  (define environment (boundary-environment head))
  (define nominals (catalog-nominals (boundary-catalog head)))
  (define namespaces
    (sort (remove-duplicates
           (for*/list ([name (in-hash-keys declarations)]
                       [depth (in-range 1 (length (qname-components name)))])
             (string-join (take (qname-components name) depth) ".")))
          string<?))
  (define lines
    (append
     (list (format "boundary ~a  (~a declaration~a, ~a namespace~a)"
                   (boundary-key head) (hash-count declarations)
                   (if (= 1 (hash-count declarations)) "" "s")
                   (length namespaces)
                   (if (= 1 (length namespaces)) "" "s")))
     (for/list ([record (in-list (boundary-bundle-history bundle))])
       (format "  ~a ~a" (boundary-record-origin-kind record)
               (boundary-record-key record)))
     (if (null? (boundary-bundle-programs bundle))
         '()
         (cons "programs"
               (for/list ([record (in-list (boundary-bundle-programs bundle))])
                 (format "  ~a -> ~a  (~a module~a)"
                         (program-record-key record)
                         (program-record-output record)
                         (length (program-record-modules record))
                         (if (= 1 (length (program-record-modules record)))
                             "" "s")))))))
  (hash-set*
   (text-result "Logical catalog" lines #:kind "catalog")
   'boundary-key (boundary-key head)
   'namespaces namespaces
   'history
   (for/list ([record (in-list (boundary-bundle-history bundle))])
     (hasheq 'key (boundary-record-key record)
             'predecessor (or (boundary-record-predecessor record) 'null)
             'origin (~a (boundary-record-origin-kind record))))
   'versions
   (for/list ([record (in-list (boundary-bundle-versions bundle))])
     (hasheq 'key (version-record-key record)
             'predecessor (or (version-record-predecessor record) 'null)
             'kind (~a (version-record-kind record))
             'name (let ([name (version-record-name record)])
                     (if name (qname->display name) 'null))
             'materialized (and (version-record-materialized? record) #t)
             'rows (let ([name (version-record-name record)])
                     (if name (hash-ref sizes (qname->display name) 0) 0))))
   'types
   (for/list ([record (in-list (boundary-bundle-types bundle))])
     (hasheq 'key (type-record-key record)
             'arity (type-record-arity record)
             'sid (or (type-record-sid record) 'null)
             'names (map qname->display (type-record-names record))
             'bound (for/or ([(name key) (in-hash nominals)])
                      (equal? key (type-record-key record)))))
   'programs
   (for/list ([record (in-list (boundary-bundle-programs bundle))])
     (hasheq 'key (program-record-key record)
             'input (or (program-record-input record) 'null)
             'output (program-record-output record)
             'modules (map module-observation
                           (program-record-modules record))))
   'relations
   (for/list ([name (in-list (sort (hash-keys environment) qname<?))])
     (hasheq 'name (qname->display name)
             'version-key (hash-ref environment name)))))

(define (tables-result-from-catalog catalog argument)
  (define filter-text (string-trim argument))
  (define boundary-keys
    (remove-duplicates
     (filter values (map relation-info-boundary-key catalog))))
  (define selected-boundary
    (and (= (length boundary-keys) 1) (car boundary-keys)))
  (define visible
    (filter
     (lambda (relation)
       (define name (relation-info-name relation))
       (cond
         [(string=? filter-text "all") #t]
         [(string=? filter-text "") (not (default-hidden-relation? relation))]
         [else (string-contains? name filter-text)]))
     catalog))
  (hash-set*
   (text-result
    "Live relations"
    (if (null? visible)
        (list (if (string=? filter-text "")
                  "no user relations; use `tables all` to include internals"
                  (format "no relations match ~s" filter-text)))
        (map relation-description visible))
    #:kind "tables")
   'relations (map relation-observation visible)
   'relations-total (length catalog)
   'relations-filter filter-text
   'relations-scope
   (if selected-boundary
       (format "committed boundary ~a" selected-boundary)
       "current live session")
   'boundary-key (or selected-boundary 'null)))

(define (tables-result state argument)
  (tables-result-from-catalog (live-catalog (ensure-session! state)) argument))

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
  ;; `#N` is a REPL token, not readable Slog/Racket data, so the handle
  ;; check must come before the reader touches the argument.
  (cond
    [(regexp-match? #px"^#[0-9]+$" (string-trim argument))
     (show-value-handle state (string-trim argument))]
    [else
     (match-define (list* rel options) (read-command-data 'show argument))
     (show-relation-rows state (relation-key rel) options)]))

(define (preview-cut? text) (regexp-match? #px"\\.\\.\\." text))

;; `show #N` always gives a DEEPER view than the handle has (ratified
;; 2026-07-28): each call re-describes the word another preview-depth's
;; worth of levels down, so iterating `show` pulls in an arbitrary tree.
;; A handle whose text is already complete skips the daemon round trip.
(define (show-value-handle state label)
  (define rs (ensure-session-record! state))
  (define handle (resolve-value-handle state label))
  (define stored-depth (value-handle-depth handle))
  (define cell
    (cond
      [(or (not stored-depth) (not (repl-session-session rs)))
       (value-handle-cell handle)]
      [else
       (define next-depth (+ stored-depth query-preview-depth))
       (define reply
         (session-command-stream!
          (repl-session-session rs)
          `(describe-value ,(value-cell-word (value-handle-cell handle))
                           (depth ,next-depth))
          (lambda (line) #t)))
       (define deeper (datum->value-cell (read-datum (first reply))))
       (hash-set! (server-state-handles state) label
                  (struct-copy value-handle handle
                    [cell deeper]
                    [depth (and (preview-cut? (value-cell-text deeper))
                                next-depth)]))
       deeper]))
  (define cut? (and (value-handle-depth
                     (hash-ref (server-state-handles state) label))
                    (preview-cut? (value-cell-text cell))))
  (hash-set*
   (text-result
    (format "Value · ~a" label)
    (append
     (list (value-cell-text cell)
           (format "kind: ~a" (value-cell-kind cell)))
     (if (value-cell-type-key cell)
         (list (format "type: ~a" (value-cell-type-key cell)))
         '())
     (if cut?
         (list (format "… deeper levels remain — `show ~a` digs further"
                       label))
         '()))
    #:kind "value")
   'handle label
   'value-kind (~a (value-cell-kind cell))
   'type-key (or (value-cell-type-key cell) 'null)
   'text (value-cell-text cell)))

(define (show-relation-rows state name options)
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
  ;; The value adapter: rows arrive as structured cells, so a struct or
  ;; collection value becomes a CHECKED `#N` handle instead of display text
  ;; the client would have to parse back (repl.md §1).
  (ensure-evaluation! state s)
  (define raw
    (session-action! s `(dump-cells ,(string->symbol name))
                     (read-until-response #px"^\\(cellsdone [0-9]+\\)$")))
  (define cell-rows
    (for/list ([line (in-list raw)]
               #:do [(define datum (read-datum line))]
               #:when (match datum [`(cellrow ,_ ...) #t] [_ #f]))
      (match datum [`(cellrow ,cells ...) (map datum->value-cell cells)])))
  (define rows
    (for/list ([cells (in-list cell-rows)])
      (format "(~a~a)" name
              (if (null? cells)
                  ""
                  (string-append
                   " "
                   (string-join
                    (for/list ([cell (in-list cells)])
                      (define handle (and (handle-worthy? cell)
                                          (mint-value-handle! state cell)))
                      (if handle
                          (format "~a ~a" (value-cell-text cell) handle)
                          (value-cell-text cell)))
                    " "))))))
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

;; ---- the `?` register (R2 over Q1) -----------------------------------------
;;
;; parse (query-front.rkt) -> plan against the committed head + the daemon's
;; materialization facts (query-plan.rkt) -> drive the canonical dispatcher
;; (query/query-page/query-cancel) -> render.  Queries never mutate: literals
;; resolve probe-only in the daemon and the plan uses existing indices only.

;; Runtime facts only the daemon knows, keyed by exact VersionKey: kind,
;; arity, materialized full-index orders, tuple count.  An index-free
;; relation reports no orders and is dropped -- it has no scannable storage,
;; so it is not queryable until something materializes it.
(define (daemon-materialization-facts s)
  (define lines
    (session-command-stream!
     s '(catalog)
     (lambda (line) (regexp-match? #px"^\\(catalog-end [0-9]+\\)$" line))))
  (for/fold ([out (hash)]) ([line (in-list lines)])
    (match (read-datum line)
      [`(catalog-rel ,fields ...)
       (define (field key)
         (match (assq key fields) [(list _ value) value] [_ #f]))
       (define version-key (field 'version-key))
       (define arity (field 'arity))
       (define orders (field 'orders))
       (define size (field 'size))
       (define kind
         (match (field 'kind) ['struct 'struct] ['lat 'lattice] [_ 'plain]))
       (if (and (string? version-key)
                (exact-nonnegative-integer? arity)
                (list? orders) (pair? orders)
                (exact-nonnegative-integer? size))
           (hash-set out version-key
                     (query-materialization version-key kind arity orders size))
           out)]
      [_ out])))

(define (field-type-symbol ref)
  (match ref
    [(type-ref 'primitive name)
     (if (symbol? name) name (string->symbol (~a name)))]
    [(type-ref 'named name) (string->symbol (qname->display name))]
    [_ 'any]))

;; Project the committed logical head and the daemon's materialization facts
;; into the planner's immutable snapshot.  Display names are the query keys:
;; the `?` register speaks the dotted names the canvas shows.  Only pairs
;; whose logical and runtime kinds agree join the snapshot -- anything else
;; (non-storage declarations, drifted kinds, index-free storage) stays out
;; and queries against it refuse as unknown rather than poisoning the rest.
(define (query-boundary-snapshot s)
  (define head (session-current-boundary s))
  (unless head
    (error '? (string-append
               "queries need a committed boundary catalog; "
               "run a program against this database first")))
  (define generation
    (match (pipeline-datum s)
      [`(pipeline (pos ,_) (evaluation ,_) (update-epoch ,epoch) ,_ ...)
       epoch]
      [_ (error '? "cannot read the daemon update epoch")]))
  (define materializations (daemon-materialization-facts s))
  (define declarations (catalog-declarations (boundary-catalog head)))
  (define-values (decl-map env-map)
    (for/fold ([decls (hash)] [env (hash)])
              ([(name version-key) (in-hash (boundary-environment head))])
      (define descriptor (hash-ref declarations name #f))
      (define materialization (hash-ref materializations version-key #f))
      (define kind (and descriptor (declaration-descriptor-kind descriptor)))
      (define runtime-kind
        (and materialization (query-materialization-kind materialization)))
      (cond
        [(or (not descriptor) (not materialization)
             (not (case kind
                    [(table) (eq? runtime-kind 'plain)]
                    [(struct lattice) (eq? runtime-kind kind)]
                    [else #f])))
         (values decls env)]
        [else
         (define runtime-arity (query-materialization-arity materialization))
         (define fields
           (map field-type-symbol (declaration-descriptor-fields descriptor)))
         ;; the struct id column (and a lattice's spec-only width) types as
         ;; `any`; only plain tables plan, so table typing never weakens
         (define types
           (cond
             [(= (length fields) runtime-arity) fields]
             [(< (length fields) runtime-arity)
              (append fields
                      (make-list (- runtime-arity (length fields)) 'any))]
             [else (take fields runtime-arity)]))
         (define key (qname->display name))
         (values (hash-set decls key (query-declaration key kind types))
                 (hash-set env key version-key))])))
  (query-boundary (boundary-key head) generation decl-map env-map
                  materializations))

;; The page model: `?` pulls one page of 50 rows with cell previews cut at
;; depth 4 and, when more rows remain, HOLDS the connection's one query
;; cursor: `more` continues it, `cancel` discards it, and any command that
;; needs the daemon discards it first (the daemon refuses everything else
;; while a cursor is live, so a held cursor never blocks the next thought).
(define query-page-size 50)
(define query-preview-depth 4)
(define query-slice-budget 64)
(define query-dump-page-size 1000)
(define query-dump-slice-budget 100000)

(define query-id-counter (box 0))
(define (next-query-id)
  (set-box! query-id-counter (add1 (unbox query-id-counter)))
  (format "q~a" (unbox query-id-counter)))

;; id lives on the daemon connection; line keeps the vars/template for
;; rendering later pages; shown numbers rows continuously across pages.
(struct query-cursor (id line shown) #:transparent)

(define (query-refused! who lines)
  (for ([line (in-list lines)])
    (match (read-datum line)
      [`(refused ,class ,_ ,fields ...)
       (define detail
         (match (assq 'detail fields) [(list _ text) text] [_ #f]))
       (error who "daemon refused the query (~a)~a" class
              (if detail (format ": ~a" detail) ""))]
      [_ (void)])))

(define (query-row-cells datum)
  (match datum
    [`(query-row ,_ (cells ,cells ...)) (map datum->value-cell cells)]
    [_ #f]))

;; Silently release a held cursor.  Best-effort by design: the daemon may
;; already have dropped it, and discarding must never turn the user's next
;; command into a failure.
(define (discard-query-cursor! rs)
  (define cursor (repl-session-cursor rs))
  (when cursor
    (set-repl-session-cursor! rs #f)
    (with-handlers ([exn:fail? void])
      (session-query-lines!
       (repl-session-session rs)
       (format "(query-cancel ~a)" (query-cursor-id cursor))))))

;; Pull rows until this request's page quota is met, the query completes,
;; or the slice budget trips (then the cursor is cancelled).  Returns
;; (values status rows matched): 'complete, 'open (cursor still live on the
;; daemon), or 'budget.  `start` is the opening (query ...) line; omitted
;; means continue an existing cursor with (query-page ...) remainders.
(define (query-pull-page! s id #:start [start #f]
                          #:page-size [page-size query-page-size]
                          #:slice-budget [slice-budget query-slice-budget])
  (let loop ([command start] [rows '()] [slices 0])
    (define line-out
      (or command
          (format "(query-page ~a (page ~a))" id
                  (max 1 (- page-size (length rows))))))
    (define lines (session-query-lines! s line-out))
    (query-refused! '? lines)
    (define all
      (append rows (filter-map query-row-cells (map read-datum lines))))
    (match (read-datum (last lines))
      [`(query-end ,_ ,status (rows ,_) (matched ,matched))
       (cond
         [(memq status '(complete cancelled)) (values 'complete all matched)]
         [(>= (length all) page-size) (values 'open all matched)]
         [(>= slices slice-budget)
          (session-query-lines! s (format "(query-cancel ~a)" id))
          (values 'budget all matched)]
         [else (loop #f all (add1 slices))])]
      [other (error '? "unexpected query reply: ~a" other)])))

;; count/exists never materialize rows: keep advancing work slices until the
;; daemon says complete, so `matched` is exact whenever exact? is #t.
(define (query-run-aggregate! s wire-plan)
  (define id (next-query-id))
  (let loop ([command (format "(query ~a ~a (page 1))" id wire-plan)]
             [slices 0])
    (define lines (session-query-lines! s command))
    (query-refused! '? lines)
    (match (read-datum (last lines))
      [`(query-end ,_ ,status (rows ,_) (matched ,matched))
       (cond
         [(memq status '(complete cancelled)) (values #t matched)]
         [(>= slices query-slice-budget)
          (session-query-lines! s (format "(query-cancel ~a)" id))
          (values #f matched)]
         [else (loop (format "(query-page ~a (page 1))" id) (add1 slices))])]
      [other (error '? "unexpected query reply: ~a" other)])))

;; `#N` splices into a query as the handle's raw encoded word -- identity
;; inside this evaluation, lowered to a preloaded register (never an
;; interner write), so it is read-only by construction and works for every
;; value kind including structs and collections no wire literal could
;; spell.  resolve-value-handle re-checks database, evaluation, and
;; constructor identity, so a stale handle refuses before planning.
(define (query-handle-resolver state)
  (lambda (label)
    (define cell (value-handle-cell (resolve-value-handle state label)))
    (query-literal 'word (number->string (value-cell-word cell)))))

;; Mirror the show adapter: a compound value's preview is followed by its
;; checked #N handle -- the daemon cut the preview at the requested depth,
;; and the handle is how the user asks for more; scalars render bare.
(define (query-cell-display state cell)
  (define handle (and (handle-worthy? cell)
                      (mint-value-handle! state cell
                                          #:depth query-preview-depth)))
  (if handle
      (format "~a ~a" (value-cell-text cell) handle)
      (value-cell-text cell)))

;; Substitute an answer row back into the single-atom sugar's fact template.
;; Every symbol in a qualifying template is a projected variable, so the
;; lookup cannot miss.
(define (render-query-fact pattern vars displays)
  (define bindings (map cons vars displays))
  (define parts
    (for/list ([term (in-list (rest pattern))])
      (cond
        [(symbol? term) (cdr (assq term bindings))]
        [(handle-token? term) (handle-token-label term)]
        [(string? term) (~s term)]
        [else (~a term)])))
  (format "(~a~a)" (first pattern)
          (if (null? parts) "" (string-append " " (string-join parts " ")))))

(define (render-query-page state rs line rows-cells status matched
                           start-index)
  (ensure-evaluation! state (repl-session-session rs))
  (define vars (query-line-project-vars line))
  (define pattern (query-line-pattern line))
  (define displays
    (for/list ([cells (in-list rows-cells)])
      (for/list ([cell (in-list cells)])
        (query-cell-display state cell))))
  (define numbered
    (for/list ([row (in-list displays)] [i (in-naturals (add1 start-index))])
      (format "~a  ~a" i
              (if pattern
                  (render-query-fact pattern vars row)
                  (format "(~a)" (string-join row " "))))))
  (define shown (+ start-index (length rows-cells)))
  (define header
    (match status
      ['complete
       (cond
         [(zero? start-index)
          (format "~a row~a" shown (if (= shown 1) "" "s"))]
         [(null? rows-cells) (format "no more rows (~a total)" matched)]
         [else (format "rows ~a–~a · complete (~a total)"
                       (add1 start-index) shown matched)])]
      ['open
       (format "rows ~a–~a — `more` continues, `cancel` discards"
               (add1 start-index) shown)]
      ['budget
       (format "~a row~a before the work budget; narrow the query or use ?count"
               shown (if (= shown 1) "" "s"))]))
  (hash-set*
   (text-result
    (if pattern
        "Query"
        (format "Query · (~a)" (string-join (map ~a vars) " ")))
    (cons header numbered)
    #:kind "query")
   'query-mode "rows"
   'query-status (~a status)
   'query-matched matched
   'query-shown shown))

(define (query-register-result state text)
  ;; grammar refusals need no session, so parse before touching the daemon
  ;; (the handle resolver only fires when a #N actually appears)
  (define line
    (parse-query-line text #:resolve-handle (query-handle-resolver state)))
  (define rs (ensure-session-record! state))
  (discard-query-cursor! rs)
  (define s (repl-session-session rs))
  (define catalog (query-catalog-from-boundary (query-boundary-snapshot s)))
  (define plan (plan-query catalog (query-line-request line)))
  (define wire (query-plan->wire-string plan))
  (match (query-request-mode (query-line-request line))
    ['rows
     (define id (next-query-id))
     (define-values (status rows matched)
       (query-pull-page!
        s id
        #:start (format "(query ~a ~a (page ~a) (depth ~a))"
                        id wire query-page-size query-preview-depth)))
     (when (eq? status 'open)
       (set-repl-session-cursor! rs (query-cursor id line (length rows))))
     (render-query-page state rs line rows status matched 0)]
    ['count
     (define-values (exact? matched) (query-run-aggregate! s wire))
     (hash-set*
      (text-result
       "Query count"
       (list (format "~a~a row~a match"
                     matched (if exact? "" "+")
                     (if (= matched 1) "" "s")))
       #:kind "query")
      'query-mode "count"
      'query-matched matched)]
    ['exists
     (define-values (exact? matched) (query-run-aggregate! s wire))
     (define yes? (positive? matched))
     (hash-set*
      (text-result
       "Query exists"
       (list (cond [yes? "yes — at least one row matches"]
                   [exact? "no rows match"]
                   [else "none found before the work budget"]))
       #:kind "query")
      'query-mode "exists"
      'query-matched matched)]))

;; `more` continues the held cursor; `cancel` discards it.  The handle is
;; cleared before pulling so an error mid-pull cannot strand a stale id.
(define (more-result state)
  (define rs (ensure-session-record! state))
  (define cursor (repl-session-cursor rs))
  (unless cursor
    (error 'more "no open query cursor; a ? query holds one when rows remain"))
  (set-repl-session-cursor! rs #f)
  (define-values (status rows matched)
    (query-pull-page! (repl-session-session rs) (query-cursor-id cursor)))
  (define start (query-cursor-shown cursor))
  (when (eq? status 'open)
    (set-repl-session-cursor!
     rs (query-cursor (query-cursor-id cursor) (query-cursor-line cursor)
                      (+ start (length rows)))))
  (render-query-page state rs (query-cursor-line cursor) rows status matched
                     start))

(define (cancel-result state)
  (define rs (ensure-session-record! state))
  (define cursor (repl-session-cursor rs))
  (unless cursor (error 'cancel "no open query cursor"))
  (discard-query-cursor! rs)
  (text-result "Query cursor"
               (list (format "discarded after ~a row~a"
                             (query-cursor-shown cursor)
                             (if (= (query-cursor-shown cursor) 1) "" "s")))
               #:kind "query"))

(define (csv-field text)
  (if (regexp-match? #px"[,\"\n]" text)
      (string-append "\"" (regexp-replace* #px"\"" text "\"\"") "\"")
      text))

;; `dump ?QUERY to PATH` -- pull the cursor to completion page by page and
;; write one CSV row per answer under a variable-name header.  Full-depth
;; text (no preview budget): dumps are for machines, previews are for eyes.
(define (dump-result state argument)
  (match (regexp-match #px"^(\\?.*?)\\s+to\\s+(\\S+)$" (string-trim argument))
    [(list _ query-text path)
     (define line
       (parse-query-line query-text
                         #:resolve-handle (query-handle-resolver state)))
     (unless (eq? (query-request-mode (query-line-request line)) 'rows)
       (error 'dump "dump takes a rows query; ?count/?exists print directly"))
     (define rs (ensure-session-record! state))
     (define s (repl-session-session rs))
     (define catalog (query-catalog-from-boundary (query-boundary-snapshot s)))
     (define plan (plan-query catalog (query-line-request line)))
     (define wire (query-plan->wire-string plan))
     (define id (next-query-id))
     (define vars (query-line-project-vars line))
     (define total
       (call-with-output-file path #:exists 'truncate
         (lambda (out)
           (displayln (string-join (map ~a vars) ",") out)
           (let loop ([start (format "(query ~a ~a (page ~a))"
                                     id wire query-dump-page-size)]
                      [written 0])
             (define-values (status rows matched)
               (query-pull-page! s id #:start start
                                 #:page-size query-dump-page-size
                                 #:slice-budget query-dump-slice-budget))
             (for ([cells (in-list rows)])
               (displayln
                (string-join
                 (for/list ([cell (in-list cells)])
                   (csv-field (value-cell-text cell)))
                 ",")
                out))
             (define now (+ written (length rows)))
             (cond
               [(eq? status 'open) (loop #f now)]
               [(eq? status 'budget)
                (error 'dump "work budget exceeded after ~a rows (partial file kept)"
                       now)]
               [else now])))))
     (text-result "Dump"
                  (list (format "wrote ~a row~a to ~a"
                                total (if (= total 1) "" "s") path))
                  #:kind "dump")]
    [_ (error 'dump "expected: dump ?QUERY to PATH.csv")]))

;; `uses #N` / `uses VALUE` / `find VALUE`: which relations contain one
;; concrete value?  A handle names its word directly; a typed literal is
;; probe-resolved by the daemon, so a value absent from the interner
;; honestly appears nowhere.  The daemon walks every latest user relation's
;; master index once and reports the nonzero counts.
(define (uses-result state argument)
  (define text (string-trim argument))
  (when (string=? text "")
    (error 'uses "expected: uses #N | uses VALUE (int, float, or string)"))
  (define spec
    (cond
      [(regexp-match? #px"^#[0-9]+$" text)
       (define cell (value-handle-cell (resolve-value-handle state text)))
       `(word ,(value-cell-word cell))]
      [else
       (match (read-datum text)
         [(? string? s) `(string ,s)]
         [(? exact-integer? n) `(integer ,(number->string n))]
         [(and (? real?) (? inexact? n)) `(real ,(number->string n))]
         [_ (error 'uses
                   "expected: uses #N | uses VALUE (int, float, or string)")])]))
  (define s (ensure-session! state))
  (define lines
    (session-command-stream!
     s `(uses ,spec)
     (lambda (line) (regexp-match? #px"^\\(uses-end " line))))
  (define rels
    (for/list ([line (in-list lines)]
               #:do [(define datum (read-datum line))]
               #:when (match datum [`(uses-rel ,_ ...) #t] [_ #f]))
      (match datum
        [`(uses-rel (name ,name) (version-key ,key) (count ,count))
         (list name key count)])))
  (define-values (total-rels total-rows)
    (match (read-datum (last lines))
      [`(uses-end (relations ,n) (rows ,rows)) (values n rows)]
      [other (error 'uses "unexpected reply: ~a" other)]))
  (hash-set*
   (text-result
    (format "Uses · ~a" text)
    (if (null? rels)
        (list "no relation contains this value")
        (append
         (for/list ([rel (in-list rels)])
           (format "~a — ~a row~a" (first rel) (third rel)
                   (if (= (third rel) 1) "" "s")))
         (list (format "~a row~a across ~a relation~a"
                       total-rows (if (= total-rows 1) "" "s")
                       total-rels (if (= total-rels 1) "" "s")))))
    #:kind "query")
   'uses-value text
   'uses-relations
   (for/list ([rel (in-list rels)])
     (hasheq 'name (~a (first rel))
             'version-key (~a (second rel))
             'rows (third rel)))
   'uses-rows total-rows))

;; ---- watches at the prompt (R2 over the level-0 daemon substrate) ---------
;;
;; A RELATION intent holds a daemon watch against the relation's exact
;; current VersionKey and re-registers against each successor (the daemon
;; never follows names — repl.md §6); hits arrive as watch-cause pause
;; records inside the run's own event stream.  A QUERY intent is
;; client-side: re-count at every semantic barrier and report the delta
;; (repl-ux §9.1).  Both report through the change summary, never by
;; interrupting the command.

(struct watch-intent
  (id kind target [bound-key #:mutable] [last-count #:mutable] level)
  #:transparent)

(define (next-watch-id registry)
  (let loop ([n (add1 (hash-count registry))])
    (define id (format "w~a" n))
    (if (hash-has-key? registry id) (loop (add1 n)) id)))

(define (register-daemon-watch! s id key #:level [level 0])
  (session-command-stream!
   s
   (if (= level 1)
       `(watch (id ,id) (version-key ,key) (level 1))
       `(watch (id ,id) (version-key ,key)))
   (lambda (_line) #t)))

(define (silent-unwatch! s id)
  (with-handlers ([exn:fail? void])
    (session-command-stream! s `(unwatch (id ,id)) (lambda (_line) #t))))

;; Coerce any query spelling to a count: a watch observes cardinality.
(define (run-watch-query state rs text)
  (define line
    (parse-query-line text #:resolve-handle (query-handle-resolver state)))
  (define request
    (struct-copy query-request (query-line-request line)
      [mode 'count] [project '()]))
  (define s (repl-session-session rs))
  (define catalog (query-catalog-from-boundary (query-boundary-snapshot s)))
  (define plan (plan-query catalog request))
  (define-values (_exact? matched)
    (query-run-aggregate! s (query-plan->wire-string plan)))
  matched)

(define (watch-result state argument)
  (define raw (string-trim argument))
  (when (string=? raw "")
    (error 'watch "expected: watch REL [level 1] | watch ?QUERY"))
  ;; T5 slice (a): `watch REL level 1` records the pre-commit-gate intent
  ;; (docs/t5-contract.md) and forces the relation's writer SCCs onto the
  ;; interpreter at their next re-entry (client-side policy, ratified).
  (define-values (text level)
    (match (regexp-match #px"^(.*[^[:space:]])[[:space:]]+level[[:space:]]+([01])$" raw)
      [(list _ target n) (values target (string->number n))]
      [_ (values raw 0)]))
  (define rs (ensure-session-record! state))
  (define registry (repl-session-watches rs))
  (define id (next-watch-id registry))
  (cond
    [(string-prefix? text "?")
     (when (= level 1)
       (error 'watch
              "query watches are client-side re-counts; level 1 applies to relation watches"))
     (define count (run-watch-query state rs text))
     (hash-set! registry id (watch-intent id 'query text #f count 0))
     (text-result
      (format "Watch ~a" id)
      (list (format "~a — ~a row~a now; changes report at each boundary"
                    text count (if (= count 1) "" "s")))
      #:kind "watch")]
    [else
     (define s (repl-session-session rs))
     (define relation (relation-from-catalog 'watch (live-catalog s) text))
     (define key (relation-info-version-key relation))
     (unless (string? key)
       (error 'watch "~a has no VersionKey yet; run a program first" text))
     (register-daemon-watch! s id key #:level level)
     (define flipped
       (if (= level 1)
           (session-set-scc-policy! s (string->symbol text) 'interpreted)
           '()))
     (hash-set! registry id (watch-intent id 'relation text key #f level))
     (text-result
      (format "Watch ~a" id)
      (append
       (list (format "~a @ ~a — hits report at coherent barriers~a"
                     text key (if (= level 1) " · level 1" "")))
       (if (null? flipped)
           '()
           (list (format "writer strat~a ~a pinned to the interpreter for future re-entries"
                         (if (= (length flipped) 1) "um" "a")
                         (string-join (map (lambda (n) (format "s~a" n)) flipped)
                                      ", ")))))
      #:kind "watch")]))

(define (unwatch-result state argument)
  (define id (string-trim argument))
  (define rs (ensure-session-record! state))
  (define registry (repl-session-watches rs))
  (define intent (hash-ref registry id #f))
  (unless intent
    (error 'unwatch "no watch named ~a; `watches` lists them" id))
  (when (and (eq? (watch-intent-kind intent) 'relation)
             (watch-intent-bound-key intent))
    (silent-unwatch! (repl-session-session rs) id))
  (hash-remove! registry id)
  (text-result (format "Watch ~a" id)
               (list (format "removed (~a)" (watch-intent-target intent)))
               #:kind "watch"))

(define (watches-result state)
  (define rs (ensure-session-record! state))
  (define registry (repl-session-watches rs))
  (define intents
    (sort (hash-values registry) string<? #:key watch-intent-id))
  (text-result
   "Watches"
   (if (null? intents)
       (list "none; `watch REL` or `watch ?QUERY` adds one")
       (for/list ([intent (in-list intents)])
         (match (watch-intent-kind intent)
           ['relation
            (format "~a  ~a @ ~a~a" (watch-intent-id intent)
                    (watch-intent-target intent)
                    (or (watch-intent-bound-key intent) "suspended")
                    (if (= (watch-intent-level intent) 1) " · level 1" ""))]
           ['query
            (format "~a  ~a — ~a row~a at the last boundary"
                    (watch-intent-id intent) (watch-intent-target intent)
                    (watch-intent-last-count intent)
                    (if (equal? (watch-intent-last-count intent) 1) "" "s"))])))
   #:kind "watch"))

;; In-run hits: the driver auto-continues watch-cause pauses, so the
;; records are already in the captured event stream.  A propagating edit
;; hits at EVERY iteration barrier it advances, so aggregate to one line
;; per watch — the heartbeat states the count and the last barrier, not a
;; ledger of every round.
(define (watch-hit-notes events)
  (define hits (make-hash))
  (for ([line (in-list events)])
    (match (read-datum line)
      [`(paused ,fields ...)
       (match (assq 'cause fields)
         [(list _ `(watch ,cites ...))
          (define site
            (format "~a iter ~a"
                    (match (assq 'stratum fields)
                      [(list _ name) name] [_ "?"])
                    (match (assq 'iteration fields)
                      [(list _ n) n] [_ "?"])))
          (for ([cite (in-list cites)])
            (match cite
              [`(watch-id ,id)
               (hash-update! hits id
                             (lambda (entry) (cons (add1 (car entry)) site))
                             (cons 0 site))]))]
         [_ (void)])]
      [_ (void)]))
  (for/list ([id (in-list (sort (hash-keys hits) string<?))])
    (match-define (cons n site) (hash-ref hits id))
    (if (= n 1)
        (format "watch ~a: hit at ~a" id site)
        (format "watch ~a: ~a hits, last at ~a" id n site))))

(define (settle-relation-watches! rs)
  (define s (repl-session-session rs))
  (define intents
    (for/list ([intent (in-hash-values (repl-session-watches rs))]
               #:when (eq? (watch-intent-kind intent) 'relation))
      intent))
  (cond
    [(null? intents) '()]
    [else
     (define catalog (live-catalog s))
     (for/fold ([notes '()]) ([intent (in-list intents)])
       (define info
         (findf (lambda (r) (string=? (relation-info-name r)
                                      (watch-intent-target intent)))
                catalog))
       (define new-key (and info (relation-info-version-key info)))
       (define old-key (watch-intent-bound-key intent))
       (cond
         [(equal? new-key old-key) notes]
         [(not (string? new-key))
          (set-watch-intent-bound-key! intent #f)
          (cons (format "watch ~a: ~a has no live binding; suspended"
                        (watch-intent-id intent) (watch-intent-target intent))
                notes)]
         [else
          ;; successor VersionKey: the old registration died with its
          ;; version (or evaluation) — re-register, tolerating a stale id
          (silent-unwatch! s (watch-intent-id intent))
          (with-handlers
              ([exn:fail?
                (lambda (e)
                  (set-watch-intent-bound-key! intent #f)
                  (cons (format "watch ~a: could not rebind ~a"
                                (watch-intent-id intent)
                                (watch-intent-target intent))
                        notes))])
            (register-daemon-watch! s (watch-intent-id intent) new-key
                                    #:level (watch-intent-level intent))
            (set-watch-intent-bound-key! intent new-key)
            (cons (format "watch ~a: rebound to ~a @ ~a"
                          (watch-intent-id intent)
                          (watch-intent-target intent) new-key)
                  notes))]))]))

(define (settle-query-watches! state rs)
  (for/fold ([notes '()])
            ([intent (in-hash-values (repl-session-watches rs))]
             #:when (eq? (watch-intent-kind intent) 'query))
    (with-handlers
        ([exn:fail?
          (lambda (e)
            (cons (format "watch ~a: query no longer plans (~a)"
                          (watch-intent-id intent)
                          (exn-message e))
                  notes))])
      (define count (run-watch-query state rs (watch-intent-target intent)))
      (define before (watch-intent-last-count intent))
      (set-watch-intent-last-count! intent count)
      (if (equal? before count)
          notes
          (cons (format "watch ~a: ~a — ~a -> ~a (~a)"
                        (watch-intent-id intent) (watch-intent-target intent)
                        before count (signed-count (- count before)))
                notes)))))

;; The barrier hook: report, rebind, re-count.  Returns summary note lines.
(define (settle-watches! state rs events)
  (if (zero? (hash-count (repl-session-watches rs)))
      '()
      (append (watch-hit-notes events)
              (reverse (settle-relation-watches! rs))
              (reverse (settle-query-watches! state rs)))))

;; `explain ?...` plans without executing: the chosen driver, the join
;; schedule, and every degradation the planner had to accept.
(define (explain-result state argument)
  (define text (string-trim argument))
  (unless (string-prefix? text "?")
    (error 'explain "expected: explain ?QUERY (rule explain arrives with R4)"))
  (define s (ensure-session! state))
  (define line
    (parse-query-line text #:resolve-handle (query-handle-resolver state)))
  (define catalog (query-catalog-from-boundary (query-boundary-snapshot s)))
  (define plan (plan-query catalog (query-line-request line)))
  (define explain (query-plan-explain plan))
  (define degradations
    (match (query-explain-degradations explain)
      ['() (list "degradations: none — existing indices cover the query")]
      [items
       (for/list ([d (in-list items)])
         (format "degraded ~a: ~a~a"
                 (query-degradation-kind d)
                 (query-degradation-relation d)
                 (let ([detail (query-degradation-detail d)])
                   (if detail (format " — ~a" detail) ""))))]))
  (text-result
   "Explain query"
   (append
    (list (format "mode: ~a" (query-request-mode (query-line-request line)))
          (format "boundary: ~a · generation ~a"
                  (query-plan-boundary-key plan)
                  (query-plan-generation plan))
          (format "driver: ~s" (query-explain-driver explain))
          (format "schedule: ~s" (query-explain-schedule explain))
          (format "estimated cost: ~a" (query-explain-estimated-cost explain)))
    degradations)
   #:kind "explain"))

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

;; R3 slice (c): T3a arrival notes.  push-sbuild!'s upgrade wrapper echoes
;; one `(tier SCC HASH RUNG)` event per in-place artifact swap; the change
;; summary carries them as "s3 upgraded to -O0 mid-run" lines (§5.4).
(define (tier-label tier)
  (match tier
    ['interp "interp"]
    ['o0 "-O0"]
    ['o2 "-O2"]
    ['o2-mix "-O2 (partial)"]
    [other (~a other)]))

(define (tier-records events)
  (for/list ([line (in-list events)]
             #:do [(define datum (read-datum line))]
             #:when (match datum [`(tier ,_ ,_ ,_) #t] [_ #f]))
    (match datum
      [`(tier ,scc ,hash ,rung)
       (hasheq 'scc scc 'hash (~a hash) 'rung (~a rung))])))

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
          'routes (route-records events)
          'tiers (tier-records events)))

(define (make-change s operation target status requested events before after)
  (define-values (revision counts) (settled-session-state s))
  (assemble-change operation target status requested events before after
                   revision counts))

(define (capture-semantic-change state rs operation status requested thunk)
  (define s (repl-session-session rs))
  (define before (catalog-size-snapshot s))
  (define-values (value events) (capture-session-events state thunk))
  (define after (catalog-size-snapshot s))
  (define change
    (make-change s operation (or (repl-session-database rs) "scratch")
                 status requested events before after))
  ;; watches settle after the event: in-run hits from the captured stream,
  ;; relation intents rebound to successor keys, query intents re-counted
  (define watch-notes (settle-watches! state rs events))
  (values value
          events
          (if (null? watch-notes)
              change
              (hash-set change 'watches watch-notes))))

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
                 "; "))))
   ;; T3a arrival notes: which strata upgraded rungs mid-run (§5.4)
   (let ([tiers (hash-ref change 'tiers '())])
     (if (null? tiers)
         '()
         (list
          (format "tiers: ~a"
                  (string-join
                   (for/list ([record (in-list tiers)])
                     (format "s~a -> ~a arrived"
                             (hash-ref record 'scc)
                             (tier-label
                              (string->symbol (hash-ref record 'rung)))))
                   "; ")))))
   ;; the operator's heartbeat: watch hits, rebinds, and query deltas
   (hash-ref change 'watches '())))

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

;; Commands that never touch the current session's daemon may run over a
;; held query cursor; anything else discards it first, because the daemon
;; ---- R3: the scratch register (repl-ux.md §5.3) ----------------------------
;;
;; The third syntactic register: a line whose head token is a Slog
;; definition keyword is a scratch definition.  One dispatched line is one
;; program event (immediate-with-coalescing, §14.1: a multi-form paste that
;; arrives as one command commits as one boundary), compiled against the
;; live schema and interpreted immediately.
(define scratch-definition-heads
  '("rule" "table" "struct" "union" "enum" "lattice" "demand" "extern"
    "def" "let"))
;; Source-composition directives stay in files: scratch is a tip layer over
;; this session, not a module system.
(define scratch-directive-heads
  '("include" "instantiate" "import" "export"))

(define (line-head-token trimmed)
  (match (regexp-match #px"^([a-zA-Z_][a-zA-Z0-9_-]*)" trimmed)
    [(list _ head) head]
    [_ #f]))

(define (scratch-single-line text)
  (string-join (filter (lambda (s) (not (string=? s "")))
                       (map string-trim (string-split text "\n")))
               " "))

(define (scratch-register-result state source head)
  (define rs (ensure-mutable-session-record! state 'scratch))
  (define event (box #f))
  (define-values (_ _events change)
    (with-handlers
        ;; the language rule is unchanged (a defined head takes an explicit
        ;; declaration); the prompt just says how to satisfy it here
        ([(lambda (e)
            (and (exn:fail? e)
                 (regexp-match? #px"Table ([^ ]+) in .+ is not defined"
                                (exn-message e))))
          (lambda (e)
            (define name
              (second (regexp-match #px"Table ([^ ]+) in .+ is not defined"
                                    (exn-message e))))
            (error 'scratch
                   (format
                    (string-append
                     "~a — a relation the fragment defines needs its "
                     "declaration in the same layer: `table (~a ...)` "
                     "first (adoption only covers relations the database "
                     "already holds)")
                    (exn-message e) name)))])
      (capture-semantic-change
       state rs "scratch" "settled" '()
       (lambda ()
         (set-box! event
                   (session-scratch-add! (repl-session-session rs) source))))))
  (set-repl-session-changed?! rs #t)
  (define n (scratch-event-n (unbox event)))
  (define writes (scratch-event-writes (unbox event)))
  (semantic-text-result
   (format "Scratch ~a · ~a" n head)
   (list (scratch-single-line source)
         (format "fragment ~a joined the scratch layer~a"
                 n
                 (if (null? writes)
                     ""
                     (format " — writes ~a"
                             (string-join (map ~a writes) ", ")))))
   change
   #:kind "scratch"))

(define (scratch-show-result state)
  (define s (ensure-session! state))
  (define events (session-scratch-events s))
  (text-result
   "Scratch"
   (if (null? events)
       (list "the scratch layer is empty"
             "type a Slog definition (`rule ...`, `table ...`) to start one")
       (append
        (for/list ([ev (in-list events)])
          (format "~a  ~a" (scratch-event-n ev)
                  (scratch-single-line (scratch-event-text ev))))
        (list (format
               "~a fragment~a · `keep scratch as FILE.slog` exports and promotes · `clear scratch` retracts the layer"
               (length events)
               (if (= (length events) 1) "" "s")))))
   #:kind "scratch"))

(define (clear-scratch-result state argument)
  (unless (string=? (string-downcase (string-trim argument)) "scratch")
    (error 'clear "expected: clear scratch"))
  (define rs (ensure-mutable-session-record! state 'clear))
  (define outcome (box #f))
  (define-values (_ _events change)
    (capture-semantic-change
     state rs "clear-scratch" "settled" '()
     (lambda ()
       (call-with-values
        (lambda () (session-scratch-clear! (repl-session-session rs)))
        (lambda (count dropped rerun)
          (set-box! outcome (list count dropped rerun)))))))
  (set-repl-session-changed?! rs #t)
  (match-define (list count dropped rerun) (unbox outcome))
  (semantic-text-result
   "Cleared scratch"
   (append
    (list (format "~a fragment~a retracted"
                  count (if (= count 1) "" "s")))
    (if (null? dropped)
        '()
        (list (format "dropped: ~a" (string-join (map ~a dropped) ", "))))
    (if (null? rerun)
        '()
        (list (format "recomputed without the layer: ~a"
                      (string-join (map ~a rerun) ", ")))))
   change
   #:kind "scratch"))

(define (keep-scratch-result state argument)
  (match (regexp-match #px"^scratch[[:space:]]+as[[:space:]]+(.+)$"
                       (string-trim argument))
    [(list _ dest0)
     (define dest (string-trim dest0))
     (define rs (ensure-mutable-session-record! state 'keep))
     ;; re-keeping into a file this session already wrote is the iterate
     ;; loop; clobbering an unrelated file is an accident the session layer
     ;; refuses
     (define count
       (session-scratch-keep! (repl-session-session rs) dest
                              #:overwrite?
                              (and (hash-ref (repl-session-kept rs) dest #f)
                                   #t)))
     (hash-set! (repl-session-kept rs) dest #t)
     (text-result
      (format "Kept scratch as ~a" dest)
      (list (format "~a fragment~a written and promoted to ordinary history"
                    count (if (= count 1) "" "s"))
            "the scratch layer is empty again; its events stay in the recipe")
      #:kind "scratch")]
    [_ (error 'keep "expected: keep scratch as FILE.slog")]))

;; ---- R3 slice (c): tier visibility (execution-tiers T3a) -------------------
;;
;; `tiers` renders the session's per-stratum execution rungs -- what the
;; cold-start ladder is doing right now -- and `code` opens one stratum's
;; card: rung, cached artifacts, and the canonical plan's shape.  Both are
;; observations over client state and the build cache; no daemon round
;; trip, so a held query cursor survives them.

(define (tiers-result state)
  (define s (ensure-session! state))
  (define rows (session-tiers s))
  (text-result
   "Tiers"
   (if (null? rows)
       (list "no resident strata; run a program first")
       (append
        (for/list ([r (in-list rows)])
          (match-define (list scc hash tier cached policy) r)
          (format "s~a  ~a  ~a~a~a"
                  scc hash (tier-label tier)
                  (if (eq? policy 'interpreted) "  · debug" "")
                  (if (null? cached)
                      ""
                      (format "  · cache: ~a"
                              (string-join (map ~a cached) " ")))))
        (let ([groups (for/fold ([acc (hash)]) ([r (in-list rows)])
                        (hash-update acc (third r) add1 0))])
          (list
           (format "~a strat~a · ~a"
                   (length rows) (if (= (length rows) 1) "um" "a")
                   (string-join
                    (for/list ([tier (in-list '(interp o0 o2 o2-mix))]
                               #:when (hash-ref groups tier #f))
                      (format "~a ~a" (hash-ref groups tier)
                              (tier-label tier)))
                    " · "))))))
   #:kind "tiers"))

(define (code-result state argument)
  (define s (ensure-session! state))
  (define requested (string-trim argument))
  (when (string=? requested "")
    (error 'code "expected: code sN | code HASHPREFIX"))
  (define rows (session-tiers s))
  (define row
    (or (findf (lambda (r)
                 (or (equal? (format "s~a" (first r)) requested)
                     (equal? (~a (first r)) requested)
                     (string-prefix? (second r) requested)))
               rows)
        (error 'code "no resident stratum matches ~a (see `tiers`)"
               requested)))
  (match-define (list scc hash tier cached policy) row)
  (define plan-path (format "build/~a.plan" hash))
  (define plan
    (and (file-exists? plan-path)
         (with-handlers ([exn:fail? (lambda (_) #f)])
           (call-with-input-file plan-path read))))
  (define plan-lines
    (match plan
      [`(kernel-plan ,parts ...)
       (define (field key)
         (match (assq key parts) [(cons _ values) values] [_ #f]))
       (define sources
         (remove-duplicates
          (filter values
                  (for/list ([m (in-list (or (field 'meta) '()))])
                    (match m
                      [`(rule-meta (rid ,_) (source ,src)) src]
                      [_ #f])))))
       (append
        (list (format "flavor: ~a · abi ~a · ~a relations · ~a rule variants"
                      (car (or (field 'flavor) '(unknown)))
                      (car (or (field 'abi) '(0)))
                      (length (or (field 'relations) '()))
                      (length (or (field 'rules) '())))
              (format "dynamic: ~a"
                      (string-join (map ~a (or (field 'dynamic) '())) ", ")))
        (if (null? sources)
            '()
            (list (format "sources: ~a" (string-join sources ", ")))))]
      [_ (list "no canonical plan in the build cache for this stratum")]))
  (text-result
   (format "Code · s~a" scc)
   (append
    (list (format "stratum ~a · running ~a~a" hash (tier-label tier)
                  (if (eq? policy 'interpreted)
                      " · pinned interpreted (debug)"
                      ""))
          (format "cache: ~a"
                  (if (null? cached)
                      "empty"
                      (string-join (map ~a cached) " "))))
    plan-lines)
   #:kind "code"))

;; refuses every non-query verb while its one cursor is live.  A new `?`
;; query discards inside the register itself.  `scratch`, `keep`, `tiers`,
;; and `code` never touch the daemon, so a held cursor survives them.
(define keep-cursor-verbs
  '(":help" "help" "?" ":ping" ":status" "library" "current" "resident"
    "sessions" "mode" ":share" ":clear" "more" "cancel" "scratch" "keep"
    "tiers" "code" "stage"))

(define (dispatch-command state source)
  (define trimmed (string-trim source))
  (define-values (verb argument) (split-command source))
  (let ([rs (current-repl-session state)])
    (when (and rs (repl-session-cursor rs)
               (not (member verb keep-cursor-verbs)))
      (discard-query-cursor! rs)))
  (define result
    (cond
    ;; the `?` sigil binds to its atom, so the query register routes on the
    ;; raw line before verb splitting; bare `?` stays the help alias.
    [(and (string-prefix? trimmed "?") (not (string=? trimmed "?")))
     (query-register-result state trimmed)]
    ;; R3: the scratch register -- a Slog definition keyword in line-head
    ;; position routes the raw line (case-sensitive, like the language) to
    ;; the scratch layer before verb dispatch sees it.
    [(member (line-head-token trimmed) scratch-definition-heads)
     (scratch-register-result state trimmed (line-head-token trimmed))]
    [(member (line-head-token trimmed) scratch-directive-heads)
     (error 'scratch
            (format
             (string-append
              "~a is a source-composition directive; scratch takes "
              "definitions (rule, table, struct, ...) -- put directives "
              "in a file and `run` it")
             (line-head-token trimmed)))]
    [(string-prefix? trimmed "(")
     (error 'command
            (format (string-append
                     "a bare fact is ambiguous: `add ~a` asserts it, "
                     "`?~a` queries it")
                    trimmed trimmed))]
    [else
     (match verb
    ["" (text-result "Slog" '())]
    [(or ":help" "help" "?") (text-result "Help" help-lines #:kind "help")]
    [(or ":ping" "ping")
     (text-result "Protocol"
                  (list "pong" "Racket server answered over private loopback TCP.")
                  #:kind "status")]
    [(or ":status" "status")
     (define rs (current-repl-session state))
     ;; gate S1: the git-shaped pending view (§5.2.1) -- staged changes by
     ;; anchor and relation, awaiting one flush
     (define pending
       (if rs (session-pending-summary (repl-session-session rs)) '()))
     (text-result
      "REPL status"
      (append
       (list (format "protocol: ~a" protocol-version)
             (format "slog: ~a" slog-version)
             (format "racket: ~a" (version))
             (format "current: ~a"
                     (if rs (or (repl-session-database rs) "scratch") "none"))
             (format "resident databases: ~a"
                     (hash-count (server-state-sessions state))))
       (for/list ([p (in-list pending)])
         (match-define (list anchor rel adds dels) p)
         (format "pending~a: ~a~a~a"
                 (if (eq? anchor 'tip) "" (format " @~a" anchor))
                 rel
                 (if (positive? adds) (format " +~a" adds) "")
                 (if (positive? dels) (format " -~a" dels) ""))))
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
    ["explain" (explain-result state argument)]
    ["more" (more-result state)]
    ["cancel" (cancel-result state)]
    ["dump" (dump-result state argument)]
    [(or "uses" "find") (uses-result state argument)]
    ["watch" (watch-result state argument)]
    ["unwatch" (unwatch-result state argument)]
    ["watches" (watches-result state)]
    ["scratch" (scratch-show-result state)]
    ["keep" (keep-scratch-result state argument)]
    ["clear" (clear-scratch-result state argument)]
    ["tiers" (tiers-result state)]
    ["code" (code-result state argument)]
    ;; Gate S1 (roadmap §5 item 1): the staged-batch surface -- the git
    ;; index for facts (§5.2.1).  `stage` queues client-side (no daemon
    ;; touch, no epoch); `flush` commits everything queued as ONE update
    ;; epoch with one change summary.
    ["stage"
     (define rs (ensure-mutable-session-record! state 'stage))
     (define datums
       (with-handlers
           ([exn:fail?
             (lambda (e)
               (error 'stage "unreadable staged change: ~a" (exn-message e)))])
         (port->list read (open-input-string argument))))
     (when (null? datums)
       (error 'stage "expected: stage +(REL V...) -(REL V...) ..."))
     (define staged
       (let loop ([ds datums] [acc '()])
         (match ds
           ['() (reverse acc)]
           [(list-rest '+ (and fact (list _ _ ...)) rest)
            (loop rest (cons (cons '+ fact) acc))]
           [(list-rest '- (and fact (list _ _ ...)) rest)
            (loop rest (cons (cons '- fact) acc))]
           ;; a bare fact stages as an add
           [(list-rest (and fact (list _ _ ...)) rest)
            (loop rest (cons (cons '+ fact) acc))]
           [_ (error 'stage
                     "malformed staged change; expected signed facts like +(edge 1 2)")])))
     (for ([sf (in-list staged)])
       (match-define (cons sign (cons rel vals)) sf)
       (session-batch! (repl-session-session rs) sign rel vals))
     (define summary (session-pending-summary (repl-session-session rs)))
     (text-result
      (format "Staged ~a change~a"
              (length staged) (if (= (length staged) 1) "" "s"))
      (append
       (for/list ([sf (in-list staged)])
         (format "~a~a" (car sf) (cdr sf)))
       (list (format "pending: ~a — `flush` commits one update epoch"
                     (string-join
                      (for/list ([p (in-list summary)])
                        (match-define (list _anchor rel adds dels) p)
                        (format "~a~a~a" rel
                                (if (positive? adds) (format " +~a" adds) "")
                                (if (positive? dels) (format " -~a" dels) "")))
                      "; "))))
      #:kind "stage")]
    ["flush"
     (define rs (ensure-mutable-session-record! state 'flush))
     (define-values (_ _events change)
       (capture-semantic-change
        state rs "flush" "settled" '()
        (lambda () (session-flush! (repl-session-session rs)))))
     (set-repl-session-changed?! rs #t)
     (semantic-text-result
      "Flush"
      (list "staged changes committed as one update epoch")
      change
      #:kind "mutation")]
    ;; Gate S1: the count round at the prompt.  Counts are a recomputable
    ;; cache; `recount` re-establishes them through the pipeline tip, and
    ;; `recount force` replaces even already-closed walks -- the joint
    ;; battery's sidecar-vs-forced-rebuild equality instrument.
    ["recount"
     (define force?
       (match (string-downcase (string-trim argument))
         ["" #f]
         ["force" #t]
         [_ (error 'recount "expected: recount [force]")]))
     (define rs (ensure-mutable-session-record! state 'recount))
     (define-values (_ _events change)
       (capture-semantic-change
        state rs "recount" "settled" '()
        (lambda ()
          (session-recount! (repl-session-session rs) #:force? force?))))
     (semantic-text-result
      (if force? "Recount · force" "Recount")
      (list (if force?
                "count state rebuilt from scratch sidecars and republished"
                "count state re-established through the pipeline tip"))
      change
      #:kind "recount")]
    ["counts"
     (match (read-command-data 'counts argument)
       [(list rel)
        (define s (ensure-session! state))
        (define lines
          (session-action!
           s `(dump-counts ,(string->symbol (relation-key rel)))
           (read-until-response #px"^\\(countdone ")))
        (text-result (format "Counts · ~a" (relation-key rel))
                     lines
                     #:kind "counts")]
       [_ (error 'counts "expected: counts REL")])]
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
    ;; N4-B (docs/n4-contract.md §5): `attach DB as DEST` maps a saved root
    ;; under one destination prefix; `attach DB SOURCE as DEST` maps one
    ;; dependency-closed subtree.  Both publish as one ordinary N3 boundary.
    ["attach"
     ;; read-command-data returns datums; the attach grammar is positional
     ;; words, so normalize before matching on the `as` keyword.
     (define words
       (map relation-key (read-command-data 'attach argument #:minimum 3)))
     (define-values (db source destination)
       (match words
         [(list db "as" destination) (values db #f destination)]
         [(list db source "as" destination) (values db source destination)]
         [_ (error 'attach
                   "expected: attach DB as DEST | attach DB SOURCE as DEST")]))
     (define rs (ensure-mutable-session-record! state 'attach))
     (define plan (box #f))
     (define-values (_ _events change)
       (capture-semantic-change
        state rs "attach" "settled" '()
        (lambda ()
          (set-box!
           plan
           (session-attach!
            (repl-session-session rs) db
            #:source (and source (symbol->qname (string->symbol source)))
            #:as (symbol->qname (string->symbol destination)))))))
     (set-repl-session-changed?! rs #t)
     (semantic-text-result
      (format "Attached ~a~a as ~a" db
              (if source (format " ~a" source) "") destination)
      (list (format "~a relation versions and ~a nominal types were mapped"
                    (length (attachment-plan-version-map (unbox plan)))
                    (length (attachment-plan-type-map (unbox plan))))
            (format "published as boundary ~a"
                    (attachment-plan-boundary-key (unbox plan))))
      change
      #:kind "mutation")]
    ;; N4-A work order 6: one structured projection of the session's selected
    ;; logical boundary -- committed history, program/module records with
    ;; their bindings, version chains, and type records.  Work order 7: this
    ;; is an IDENTITY operation, so a catalog-less input is refused loudly
    ;; rather than answered from a name/size approximation.
    ["catalog"
     (define s (ensure-session! state))
     (define bundle (session-boundary-bundle s))
     (unless bundle
       (error 'catalog
              (string-append
               "this database has no logical catalog (a pre-N4 input, or one "
               "invalidated by an import/link/inject); replay and re-save it, "
               "or regenerate it")))
     (catalog-result bundle (daemon-relation-sizes s))]
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
       (error 'save "expected: save NAME [with scratch]"))
     ;; R3 slice (d), repl-ux §5.3: until the layer is kept, a save must
     ;; decide what happens to scratch.  The server-side form of "save
     ;; asks" is a typed refusal naming the three ways out; `with scratch`
     ;; is the explicit override (the layer bakes into the saved recipe as
     ;; ordinary history -- exactly what a reload yields).
     (define-values (name with-scratch?)
       (match (regexp-match #px"^(.*?)[[:space:]]+with[[:space:]]+scratch$"
                            (string-trim argument))
         [(list _ name) (values (string-trim name) #t)]
         [_ (values (string-trim argument) #f)]))
     (when (string=? name "")
       (error 'save "expected: save NAME [with scratch]"))
     (define rs (ensure-mutable-session-record! state 'save))
     (define pending-scratch
       (session-scratch-events (repl-session-session rs)))
     (when (and (pair? pending-scratch) (not with-scratch?))
       (error 'save
              (format
               (string-append
                "the scratch layer holds ~a fragment~a; decide first: "
                "`keep scratch as F.slog` promotes it, `clear scratch` "
                "retracts it, `save ~a with scratch` bakes it as ordinary "
                "history")
               (length pending-scratch)
               (if (= (length pending-scratch) 1) "" "s")
               name)))
     (define-values (_ _events change)
       (capture-semantic-change
        state rs "save" "saved" '()
        (lambda () (session-save! (repl-session-session rs) name))))
     (semantic-text-result
      (format "Saved ~a" name)
      (append
       (list "database materialization and replay recipe were written")
       (if (and with-scratch? (pair? pending-scratch))
           (list (format
                  "~a scratch fragment~a saved as ordinary history (a reload holds them baked)"
                  (length pending-scratch)
                  (if (= (length pending-scratch) 1) "" "s")))
           '()))
      change
      #:kind "save")]
    [(or ":quit" "quit" "exit")
     (set-server-state-closing?! state #t)
     (hasheq 'kind "quit" 'title "Goodbye" 'lines (list "REPL closed") 'close #t)]
    [_
     (error 'command
            (format "unknown command ~a; type :help for the current command set" verb))])]))
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
  (define state (server-state (make-hash) #f #f #f (make-hash)))
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
  (define state (server-state (make-hash) #f #f #f (make-hash)))
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

  (define state (server-state (make-hash) #f #f #f (make-hash)))
  (define help-result (dispatch-command state ":help"))
  (check-equal? (hash-ref help-result 'kind) "help")
  (check-not-false
   (member "  expand POSITION     expand a node in the newest live result canvas"
           (hash-ref help-result 'lines)))
  (check-not-false
   (member "  card POSITION       show the contextual card for a live canvas node"
           (hash-ref help-result 'lines)))
  (check-not-false
   (member "  search TEXT         search visible lines in the newest live result canvas"
           (hash-ref help-result 'lines)))
  (check-not-false
   (member "  page POSITION N     select an absolute page in a buffered canvas collection"
           (hash-ref help-result 'lines)))
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

  (check-equal?
   (wire-round-trip
    (relation-observation
     (relation-info "edge" "table" 2 (list "Int" "Int") 3
                    "v1:edge" "b1:root:1")))
   (hasheq 'name "edge"
           'kind "table"
           'arity 2
           'detail (list "Int" "Int")
           'rows 3
           'version-key "v1:edge"
           'boundary-key "b1:root:1"))

  (define sample-tables
    (tables-result-from-catalog
     (list (relation-info "$internal" "relation" 1 '() 4 #f #f)
           (relation-info "edge" "table" 2 (list "Int" "Int") 3
                          "v1:edge" "b1:root:1"))
     ""))
  (check-equal?
   (list (hash-ref sample-tables 'lines)
         (hash-ref sample-tables 'relations)
         (hash-ref sample-tables 'relations-total)
         (hash-ref sample-tables 'relations-filter)
         (hash-ref sample-tables 'relations-scope))
   (list (list "edge/2  table · Int Int  3 rows")
         (list (relation-observation
                (relation-info "edge" "table" 2 (list "Int" "Int") 3
                               "v1:edge" "b1:root:1")))
         2
         ""
         "committed boundary b1:root:1"))

  ;; N4-A work order 6: the projection comes from the selected logical
  ;; boundary, so a declaration with no rows is a first-class entry and its
  ;; field graph is real type information rather than a schema-stream echo.
  (let* ([Q (lambda (name) (symbol->qname name))]
         [decl (lambda (name kind fields [lat #f])
                 (declaration-descriptor (Q name) kind fields lat))]
         [head
          (boundary
           "b1:proj:0"
           (catalog
            (hash (Q 'g.Node) (decl 'g.Node 'struct (list (type-ref 'primitive 'int)))
                  (Q 'g.edge) (decl 'g.edge 'table
                                    (list (type-ref 'named (Q 'g.Node))
                                          (type-ref 'named (Q 'g.Node))))
                  (Q 'g.unseen) (decl 'g.unseen 'table
                                      (list (type-ref 'primitive 'int))))
            (set)
            (hash (Q 'g.Node) "t1:proj:0:0"))
           (hash (Q 'g.Node) "v1:proj:0:0"
                 (Q 'g.edge) "v1:proj:0:1"
                 (Q 'g.unseen) "v1:proj:0:2"))]
         [projected (boundary-catalog-projection head (hash "g.edge" 3))])
    (check-equal? (map relation-info-name projected)
                  '("g.Node" "g.edge" "g.unseen"))
    ;; the empty declaration is present, with its VersionKey, at zero rows
    (define unseen (third projected))
    (check-equal? (relation-info-version-key unseen) "v1:proj:0:2")
    (check-equal? (relation-info-size unseen) 0)
    ;; field types come from the declaration graph, qualified
    (check-equal? (relation-info-detail (second projected))
                  (list "g.Node" "g.Node"))
    ;; a struct's stored arity includes its intern id column
    (check-equal? (relation-info-arity (first projected)) 2)
    (check-equal? (relation-info-boundary-key unseen) "b1:proj:0")
    ;; ... and the structured catalog projection reports the same identity
    (define bundle
      (boundary-bundle
       slog-boundary-bundle-format head
       (list (boundary-record "b1:proj:0" #f 'initial #f))
       (list (version-record "v1:proj:0:0" #f 'struct (Q 'g.Node) #t)
             (version-record "v1:proj:0:1" #f 'table (Q 'g.edge) #t)
             (version-record "v1:proj:0:2" #f 'table (Q 'g.unseen) #t))
       (list (type-record "t1:proj:0:0" 2 4 (list (Q 'g.Node) (Q 'old.Node))))
       '()))
    (define result (catalog-result bundle (hash "g.edge" 3)))
    (check-equal? (hash-ref result 'boundary-key) "b1:proj:0")
    (check-equal? (hash-ref result 'namespaces) '("g"))
    (check-equal? (length (hash-ref result 'versions)) 3)
    ;; a TypeKey renders through every spelling it has carried
    (check-equal? (hash-ref (first (hash-ref result 'types)) 'names)
                  '("g.Node" "old.Node"))
    (check-true (hash-ref (first (hash-ref result 'types)) 'bound))
    (check-equal? (map (lambda (r) (hash-ref r 'name))
                       (hash-ref result 'relations))
                  '("g.Node" "g.edge" "g.unseen")))

  ;; The value adapter and the checked `#N` table (repl.md §1).  A handle is
  ;; provenance-checked: the word it carries is identity only inside the
  ;; evaluation that minted it, so resolving one anywhere else must refuse
  ;; rather than decode some unrelated live value.
  (let ()
    (define cell
      (datum->value-cell
       '(cell (word 18442241573593808924) (kind struct) (sid 4)
              (type-key "t1:demo:0:3") (text "(m.Pair 1 2)"))))
    (check-equal? (value-cell-word cell) 18442241573593808924)
    (check-equal? (value-cell-kind cell) 'struct)
    (check-equal? (value-cell-sid cell) 4)
    (check-equal? (value-cell-type-key cell) "t1:demo:0:3")
    (check-equal? (value-cell-text cell) "(m.Pair 1 2)")
    ;; scalars re-type trivially, so they earn no handle; structs do
    (check-true (handle-worthy? cell))
    (check-false
     (handle-worthy?
      (datum->value-cell
       '(cell (word 7) (kind int) (sid #f) (type-key #f) (text "3")))))
    (check-exn exn:fail? (lambda () (datum->value-cell '(cell (word 1)))))

    (define state (server-state (make-hash) "alpha" #f #f (make-hash)))
    (define rs (repl-session #f "alpha" 'mutable #f "eval-1" #f (make-hash) (make-hash)))
    (hash-set! (server-state-sessions state) "alpha" rs)
    (define label (mint-value-handle! state cell))
    (check-equal? label "#1")
    ;; the same word mints once, not once per sighting
    (check-equal? (mint-value-handle! state cell) "#1")
    (check-equal? (value-cell-text
                   (value-handle-cell (resolve-value-handle state label)))
                  "(m.Pair 1 2)")
    (check-exn #px"no such value handle"
               (lambda () (resolve-value-handle state "#99")))
    ;; a handle from a previous evaluation of the same database is stale
    (set-repl-session-evaluation! rs "eval-2")
    (check-exn #px"stale"
               (lambda () (resolve-value-handle state label)))
    ;; ... and one from another database is refused outright
    (set-repl-session-evaluation! rs "eval-1")
    (define other (repl-session #f "beta" 'mutable #f "eval-1" #f (make-hash) (make-hash)))
    (hash-set! (server-state-sessions state) "beta" other)
    (set-server-state-current! state "beta")
    (check-exn #px"cannot be resolved in beta"
               (lambda () (resolve-value-handle state label)))

    ;; Constructor identity, the gap the EvaluationId check cannot see: SIDs
    ;; are allocated lowest-free, so dropping a struct type and declaring
    ;; another can reissue sid 4.  The word still decodes -- as the WRONG
    ;; constructor -- and only the durable TypeKey catches it.
    (check-false (value-handle-type-drift cell (hash 4 "t1:demo:0:3")))
    (check-regexp-match
     #px"struct id 4 now belongs to t1:other:0:0"
     (value-handle-type-drift cell (hash 4 "t1:other:0:0")))
    (check-regexp-match
     #px"no live type"
     (value-handle-type-drift cell (hash)))
    ;; a scalar has no constructor identity to drift
    (check-false
     (value-handle-type-drift
      (datum->value-cell
       '(cell (word 7) (kind int) (sid #f) (type-key #f) (text "3")))
      (hash))))

  (define sample-request
    (list (hasheq 'relation "edge" 'added 1 'removed 0)))
  (define sample-change
    (assemble-change "add" "scratch" "settled" sample-request
                     (list "(route maintain 2)"
                           "(tier 3 4f0b9c11 o0)")
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
           'routes (list (hasheq 'kind "maintain" 'detail (list "2")))
           'tiers (list (hasheq 'scc 3 'hash "4f0b9c11" 'rung "o0"))))
  ;; the arrival note renders from the captured tier event (live arrivals
  ;; depend on clang wall-clock vs fixpoint length, so the rendering is
  ;; pinned here and the verbs in the interp battery below)
  (check-not-false
   (member "tiers: s3 -> -O0 arrived" (change-summary-lines sample-change)))

  (define mode-state (server-state (make-hash) #f #f #f (make-hash)))
  (hash-set! (server-state-sessions mode-state)
             "alpha"
             (repl-session #f "alpha" 'readonly #f #f #f (make-hash) (make-hash)))
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
  (define quit-state (server-state (make-hash) #f #f #f (make-hash)))
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
            ;; R3: scratch is a catalog-era feature -- over this legacy
            ;; (pre-N4, catalog-less) fixture the register refuses, and
            ;; the byte-exact golden pins that refusal; the full scratch
            ;; round trip lives in the cataloged batteries below
            "table (deg2 int int) rule (deg2 X Z) <-- (edge X Y) (edge Y Z)"
            "scratch"
            "rename edge input_edge"
            "drop path"
            ":quit")))
   (file->string semantic-session-golden))

  ;; The `?` register (R2): grammar refusals need no daemon; the live rows/
  ;; count/exists/explain checks drive a real scratch session over
  ;; tests/reach.slog (edge = the 1-2-3-4 chain, path = its closure).  Row
  ;; ORDER is index order, so assertions pin content the planner/daemon
  ;; must produce, never incidental orderings.
  (let ([bare-state (server-state (make-hash) #f #f #f (make-hash))])
    (check-regexp-match
     #px"ambiguous"
     (with-handlers ([exn:fail? exn-message])
       (dispatch-command bare-state "(edge 1 2)")
       "bare fact unexpectedly accepted"))
    (check-regexp-match
     #px"query plan \\[parse\\]"
     (with-handlers ([exn:fail? exn-message])
       (dispatch-command bare-state "? ->")
       "empty projection unexpectedly accepted"))
    ;; bare `?` stays the help alias
    (check-equal? (hash-ref (dispatch-command bare-state "?") 'kind) "help"))

  (let ([transcript
         (parameterize ([current-directory repository-root]
                        [current-environment-variables test-environment])
           (plain-transcript
            (list "run tests/reach.slog"
                  "?count (path X Y)"
                  "?exists (edge 1 2)"
                  "?(edge 4 1)"
                  "?(edge 1 X)"
                  "?count (path 1 Y) (< Y 4)"
                  "explain ?(edge 1 X)"
                  "explain ? (path X Y) (edge Y Z) -> (X Z)"
                  "?(nope X)"
                  "?(edge #1 X)"
                  ;; queries ride forward incrementality: the head's
                  ;; VersionKeys survive a flushed tip edit, and the fresh
                  ;; update epoch is read per query
                  "add edge 4 1"
                  "?count (path X Y)"
                  ":quit")))])
    ;; count is exact at completion
    (check-regexp-match #px"◆ Query count\n  6 rows match" transcript)
    ;; existence, spelled and ground-sugared
    (check-regexp-match #px"◆ Query exists\n  yes" transcript)
    (check-regexp-match #px"◆ Query exists\n  no rows match" transcript)
    ;; the single-atom sugar substitutes answers into the fact template
    (check-regexp-match #px"1 row\n  1  \\(edge 1 2\\)" transcript)
    ;; guards ride the audited whitelist
    (check-regexp-match #px"◆ Query count\n  2 rows match" transcript)
    ;; explain plans without running and reports the boundary identity
    (check-regexp-match #px"◆ Explain query\n  mode: rows\n  boundary: "
                        transcript)
    (check-regexp-match #px"driver: " transcript)
    ;; typed refusals surface as command failures with the planner's kind
    (check-regexp-match #px"query plan \\[unknown-relation\\]" transcript)
    (check-regexp-match #px"no such value handle: #1" transcript)
    ;; closing the 4-cycle makes path the complete relation on 4 nodes,
    ;; and the query observes it at the post-edit epoch
    (check-regexp-match #px"◆ Query count\n  16 rows match" transcript))

  ;; The held cursor, cell previews, and dump (R2 slice b) over a 12-node
  ;; chain whose closure (66 pairs) overflows one 50-row page, and a 5-deep
  ;; struct whose preview the daemon cuts at depth 4.
  (let* ([dump-path "out/repl-qdump.csv"]
         [transcript
          (parameterize ([current-directory repository-root]
                         [current-environment-variables test-environment])
            (when (file-exists? dump-path) (delete-file dump-path))
            (plain-transcript
             (list "run tests/chain12.slog"
                   "?(path X Y)"
                   "more"
                   "more"
                   "?(path X Y)"
                   "cancel"
                   "?(path X Y)"
                   "count path"
                   "more"
                   "?(deep D)"
                   "show #1"
                   "?(deep #1)"
                   "? (deep D) (= D #1) -> (D)"
                   "uses 12"
                   "uses #1"
                   "find \"nope\""
                   "dump ?(path X Y) to out/repl-qdump.csv"
                   "watch path"
                   "watch ?count (path X Y)"
                   "add edge 12 1"
                   "watches"
                   "unwatch w1"
                   "watches"
                   ":quit")))])
    ;; page one holds the cursor; `more` finishes it; a third `more` refuses
    (check-regexp-match
     #px"rows 1–50 — `more` continues, `cancel` discards" transcript)
    (check-regexp-match #px"rows 51–66 · complete \\(66 total\\)" transcript)
    (check-regexp-match #px"no open query cursor" transcript)
    ;; `cancel` reports what was shown
    (check-regexp-match #px"◆ Query cursor\n  discarded after 50 rows"
                        transcript)
    ;; a session command auto-discards the held cursor and still succeeds
    (check-regexp-match #px"◆ Count path\n  66 rows" transcript)
    ;; the daemon cut the 5-deep struct preview at depth 4 and the REPL
    ;; minted a checked handle for the compound cell
    (check-regexp-match
     #px"1  \\(deep \\(l5 \\(l4 \\(l3 \\(l2 \\.\\.\\.\\)\\)\\)\\) #1\\)"
     transcript)
    ;; `show #1` deepens past the query's cut: one more preview-depth step
    ;; reaches the leaf, and the completed text drops the dig-further hint
    (check-regexp-match
     #px"◆ Value · #1\n  \\(l5 \\(l4 \\(l3 \\(l2 \\(l1 7\\)\\)\\)\\)\\)"
     transcript)
    (check-false (regexp-match? #px"digs further" transcript))
    ;; #1 splices back into queries as a preloaded word: ground existence
    ;; through the struct value, and an eq guard that re-yields its row
    (check-regexp-match #px"◆ Query exists\n  yes" transcript)
    (check-regexp-match #px"◆ Query · \\(D\\)\n  1 row" transcript)
    ;; uses/find walk every user relation's master index for one value:
    ;; a scalar by typed literal, a struct by its handle's word, and a
    ;; probe-miss honestly appears nowhere
    (check-regexp-match
     #px"◆ Uses · 12\n  edge — 1 row\n  path — 11 rows\n  12 rows across 2 relations"
     transcript)
    (check-regexp-match
     #px"◆ Uses · #1\n  deep — 1 row\n  l5 — 1 row\n  2 rows across 2 relations"
     transcript)
    (check-regexp-match
     #px"◆ Uses · \"nope\"\n  no relation contains this value" transcript)
    ;; dump pulled every page and wrote header + 66 rows
    (check-regexp-match #px"wrote 66 rows to out/repl-qdump\\.csv" transcript)
    (define dump-file
      (build-path repository-root dump-path))
    (check-true (file-exists? dump-file))
    (check-equal? (length (file->lines dump-file)) 67)
    (delete-file dump-file)
    ;; watches: registration echoes the exact bound VersionKey; closing the
    ;; 12-cycle fires the relation watch at every propagation barrier
    ;; (aggregated to one heartbeat line) and moves the query count 66->144
    (check-regexp-match #px"◆ Watch w1\n  path @ v1:" transcript)
    (check-regexp-match
     #px"◆ Watch w2\n  \\?count \\(path X Y\\) — 66 rows now" transcript)
    (check-regexp-match
     #px"watch w1: [0-9]+ hits, last at [0-9a-f]+_maint1 iter 12" transcript)
    (check-regexp-match
     #px"watch w2: \\?count \\(path X Y\\) — 66 -> 144 \\(\\+78\\)" transcript)
    (check-regexp-match
     #px"◆ Watches\n  w1  path @ v1:[^\n]*\n  w2  \\?count \\(path X Y\\) — 144 rows"
     transcript)
    ;; unwatch removes the daemon registration and the intent
    (check-regexp-match #px"◆ Watch w1\n  removed \\(path\\)" transcript)
    (check-regexp-match #px"◆ Watches\n  w2  \\?count" transcript))

  ;; The scratch register (R3 slice a): Slog definitions typed at the prompt
  ;; are immediate interp-only program events; a fragment ADOPTS the live
  ;; schema it reads (the documented consumer convention, synthesized from
  ;; the typed catalog) instead of re-declaring it; the layer accumulates,
  ;; lists, keeps, and rides ordinary maintenance epochs.
  (let* ([kept-path "out/repl-kept-views.slog"]
         [transcript
          (parameterize ([current-directory repository-root]
                         [current-environment-variables test-environment])
            (when (file-exists? kept-path) (delete-file kept-path))
            (plain-transcript
             (list "run tests/reach.slog"
                   "scratch"
                   "table (hop2 int int) rule (hop2 X Z) <-- (edge X Y) (edge Y Z)"
                   "?(hop2 X Y)"
                   ;; the second fragment adopts a SCRATCH relation
                   "table (hop4 int int) rule (hop4 X Z) <-- (hop2 X Y) (hop2 Y Z)"
                   ;; closing the 4-cycle propagates through the whole
                   ;; scratch cone in one maintenance epoch
                   "add edge 4 1"
                   "?count (hop2 X Y)"
                   "scratch"
                   ;; an undeclared head refuses with the declare-it hint
                   ;; and leaves the ledger untouched
                   "rule (hop9 X Z) <-- (hop2 X Z)"
                   ;; directives are refused with the file hint
                   "include \"list.slog\""
                   "keep scratch as out/repl-kept-views.slog"
                   "scratch"
                   "keep scratch as out/repl-kept-views.slog"
                   ":quit")))])
    ;; the empty layer explains itself
    (check-regexp-match
     #px"◆ Scratch\n  the scratch layer is empty" transcript)
    ;; a fragment compiles against the live schema (edge adopted, never
    ;; re-declared), runs interpreted now, and prints an ordinary summary
    (check-regexp-match
     #px"◆ Scratch 1 · table\n  table \\(hop2 int int\\) rule \\(hop2 X Z\\) <-- \\(edge X Y\\) \\(edge Y Z\\)\n  fragment 1 joined the scratch layer — writes hop2"
     transcript)
    (check-regexp-match #px"hop2 \\+2 \\(new -> 2\\)" transcript)
    ;; queries observe scratch relations at the committed head, index order
    (check-regexp-match #px"1  \\(hop2 2 4\\)\n  2  \\(hop2 1 3\\)" transcript)
    ;; scratch-over-scratch adoption
    (check-regexp-match
     #px"fragment 2 joined the scratch layer — writes hop4" transcript)
    ;; the edit's cone covers both scratch strata: hop2 2->4, hop4 0->4
    (check-regexp-match #px"hop2 \\+2 \\(2 -> 4\\)" transcript)
    (check-regexp-match #px"hop4 \\+4 \\(new -> 4|hop4 \\+4 \\(0 -> 4"
                        transcript)
    (check-regexp-match #px"◆ Query count\n  4 rows match" transcript)
    ;; the layer lists its fragments in order
    (check-regexp-match
     #px"◆ Scratch\n  1  table \\(hop2 int int\\)[^\n]*\n  2  table \\(hop4 int int\\)[^\n]*\n  2 fragments"
     transcript)
    ;; an undeclared head names the fix at the prompt; the failed fragment
    ;; never joined the layer (the later keep still writes 2 fragments)
    (check-regexp-match
     #px"declaration in the same layer: `table \\(hop9 \\.\\.\\.\\)`"
     transcript)
    ;; source-composition directives stay in files
    (check-regexp-match
     #px"include is a source-composition directive" transcript)
    ;; keep exports the accumulated program and empties the layer;
    ;; a second keep honestly refuses
    (check-regexp-match
     #px"◆ Kept scratch as out/repl-kept-views\\.slog\n  2 fragments written and promoted"
     transcript)
    (check-regexp-match #px"scratch is empty; nothing to keep" transcript)
    (define kept-file (build-path repository-root kept-path))
    (check-true (file-exists? kept-file))
    (check-regexp-match
     #px";; kept from a REPL scratch layer \\(2 fragments\\)\ntable \\(hop2 int int\\) rule \\(hop2 X Z\\) <-- \\(edge X Y\\) \\(edge Y Z\\)\ntable \\(hop4 int int\\) rule \\(hop4 X Z\\) <-- \\(hop2 X Y\\) \\(hop2 Y Z\\)"
     (file->string kept-file))
    (delete-file kept-file))

  ;; Scratch adoption closes over named type dependencies: matching the
  ;; 5-deep struct pulls l5..l1 along with `deep`; and a saved recipe whose
  ;; tip holds scratch run steps REPLAYS (the segment path is a source-
  ;; override key; adoption is on for replayed compiles).
  (let ([transcript
         (parameterize ([current-directory repository-root]
                        [current-environment-variables test-environment])
           (when (directory-exists? "data/r3_scratch_replay")
             (delete-directory/files "data/r3_scratch_replay"))
           (plain-transcript
            (list "run tests/chain12.slog"
                  "table (leaf int) rule (leaf N) <-- (deep (l5 (l4 (l3 (l2 (l1 N))))))"
                  "?(leaf N)"
                  ;; a plain save must first decide the layer's fate
                  "save r3_scratch_replay"
                  "save r3_scratch_replay with scratch"
                  "open r3_scratch_replay"
                  "?(leaf N)"
                  "add edge 12 1"
                  "?count (path X Y)"
                  ":quit")))])
    (check-regexp-match
     #px"fragment 1 joined the scratch layer — writes leaf" transcript)
    ;; the save×scratch decision point (slice d): a plain save refuses
    ;; while the layer is live; the explicit spelling bakes it
    (check-regexp-match
     #px"the scratch layer holds 1 fragment; decide first" transcript)
    (check-regexp-match
     #px"1 scratch fragment saved as ordinary history" transcript)
    ;; both the live and the replayed boundary yield the struct-matched leaf
    (check-regexp-match
     #px"◆ Query\n  1 row\n  1  \\(leaf 7\\)\n(?s:.*)Opened r3_scratch_replay(?s:.*)◆ Query\n  1 row\n  1  \\(leaf 7\\)"
     transcript)
    ;; the replayed database stays a live workbench: the edit propagates
    (check-regexp-match #px"◆ Query count\n  144 rows match" transcript)
    (parameterize ([current-directory repository-root])
      (when (directory-exists? "data/r3_scratch_replay")
        (delete-directory/files "data/r3_scratch_replay"))))

  ;; clear scratch (R3 slice b): a fresh-only layer retracts wholesale --
  ;; strata forgotten, introduced names dropped dependents-first -- and the
  ;; recipe stays replay-honest (create, fill, drop).  A layer that
  ;; extended a pre-existing relation refuses with the keep hint, because
  ;; its retraction has no recipe spelling yet.
  (let* ([kept-path "out/repl-clear-kept.slog"]
         [transcript
          (parameterize ([current-directory repository-root]
                         [current-environment-variables test-environment])
            (when (file-exists? kept-path) (delete-file kept-path))
            (when (directory-exists? "data/r3_clear_replay")
              (delete-directory/files "data/r3_clear_replay"))
            (plain-transcript
             (list "run tests/reach.slog"
                   ;; dependency-ordered drops: the table dies before the
                   ;; struct its column references
                   "struct (pt int) table (loc pt) rule (loc (pt 5)) <-- (edge 1 2)"
                   "clear scratch"
                   "?(loc X)"
                   ;; an extended layer refuses; keep promotes it instead
                   "rule (path 99 99) <-- (edge 1 2)"
                   "clear scratch"
                   "keep scratch as out/repl-clear-kept.slog"
                   ;; a fresh layer cleared before a save: the replayed
                   ;; recipe creates, fills, and drops it
                   "table (hop9 int int) rule (hop9 X Z) <-- (edge X Y) (edge Y Z)"
                   "clear scratch"
                   "save r3_clear_replay"
                   "open r3_clear_replay"
                   "?count (path X Y)"
                   "?(hop9 X Y)"
                   "clear scratch"
                   ":quit")))])
    (check-regexp-match
     #px"◆ Cleared scratch\n  1 fragment retracted\n  dropped: loc, pt"
     transcript)
    (check-regexp-match
     #px"loc -1 \\(1 -> removed\\); pt -1 \\(1 -> removed\\)" transcript)
    (check-regexp-match #px"unknown relation \"loc\"" transcript)
    ;; the typed extended-layer refusal names the relation and the way out
    (check-regexp-match
     #px"extended pre-existing relation path; retraction there has no recipe spelling yet"
     transcript)
    (check-regexp-match #px"1 fragment written and promoted" transcript)
    (check-regexp-match #px"dropped: hop9" transcript)
    ;; the reloaded database re-derives kept history, not the cleared layer
    (check-regexp-match
     #px"Opened r3_clear_replay(?s:.*)◆ Query count\n  7 rows match"
     transcript)
    (check-regexp-match #px"unknown relation \"hop9\"" transcript)
    ;; a freshly loaded database holds no live scratch ledger
    (check-regexp-match #px"scratch is empty; nothing to clear" transcript)
    (parameterize ([current-directory repository-root])
      (when (file-exists? kept-path) (delete-file kept-path))
      (when (directory-exists? "data/r3_clear_replay")
        (delete-directory/files "data/r3_clear_replay"))))

  ;; tier visibility (R3 slice c): under forced interp every stratum sits
  ;; on the interpreter rung with its plan cached, deterministically;
  ;; `code` opens one stratum's card from the canonical plan sidecar.
  (let* ([interp-environment
          (environment-variables-copy test-environment)]
         [transcript
          (parameterize ([current-directory repository-root]
                         [current-environment-variables
                          (begin
                            (environment-variables-set!
                             interp-environment #"SLOG_OPT" #"interp")
                            interp-environment)])
            (plain-transcript
             (list "tiers"
                   "run tests/reach.slog"
                   "table (hop2 int int) rule (hop2 X Z) <-- (edge X Y) (edge Y Z)"
                   "tiers"
                   ;; T5 slice (a): the level-1 intent pins path's writer
                   "watch path level 1"
                   "watch ?count (path X Y) level 1"
                   "tiers"
                   "code s2"
                   "code nope"
                   ":quit")))])
    (check-regexp-match #px"◆ Tiers\n  no resident strata" transcript)
    (check-regexp-match #px"s0  [0-9a-f]+  interp  · cache: plan" transcript)
    (check-regexp-match #px"3 strata · 3 interp" transcript)
    ;; T5 slice (a): the level-1 registration surface under interp
    (check-regexp-match
     #px"◆ Watch w1\n  path @ v1:[^\n]* — hits report at coherent barriers · level 1\n  writer stratum s1 pinned to the interpreter"
     transcript)
    (check-regexp-match #px"s1  [0-9a-f]+  interp  · debug  · cache: plan"
                        transcript)
    (check-regexp-match
     #px"query watches are client-side re-counts; level 1 applies to relation watches"
     transcript)
    ;; the scratch stratum's card: rung, cached artifacts, plan shape
    ;; (unchanged by the policy column)
    (check-regexp-match
     #px"◆ Code · s2\n  stratum [0-9a-f]+ · running interp\n  cache: plan\n  flavor: normal · abi 1 · [0-9]+ relations · 1 rule variants\n  dynamic: hop2"
     transcript)
    (check-regexp-match #px"no resident stratum matches nope" transcript))

  ;; T5 slice (a), the flip end to end: under SLOG_OPT=0 the strata
  ;; register NATIVE; a level-1 watch pins path's writer to the
  ;; interpreter; a direct clear-and-rerun re-entry then carries the
  ;; canonical plan through the executor-blind entry path (a bogus
  ;; artifact would refuse loudly), and the closure recomputes exactly.
  (let ([o0-environment (environment-variables-copy test-environment)])
    (environment-variables-set! o0-environment #"SLOG_OPT" #"0")
    (parameterize ([current-directory repository-root]
                   [current-environment-variables o0-environment])
      (define state (make-server-state))
      (define (run! line) (dispatch-command state line))
      (void (run! "run tests/reach.slog"))
      (void (run! "watch path level 1"))
      (define rs (current-repl-session state))
      (define s (repl-session-session rs))
      (define pinned
        (for/list ([row (in-list (session-tiers s))]
                   #:when (eq? (fifth row) 'interpreted))
          row))
      (check-equal? (length pinned) 1)
      ;; native rung, interpreted policy: exactly the flip case
      (check-not-false (memq (third (first pinned)) '(o0 o2)))
      (session-rerun! s 'edge)
      (check-regexp-match
       #px"6 rows match"
       (string-join (hash-ref (run! "?count (path X Y)") 'lines '()) "\n"))
      (close-server-session! state))))
