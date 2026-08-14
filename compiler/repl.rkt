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
         ;; plain-transcript and the Rust client.  ensure-session! joins
         ;; the same surface (spine A3): the activation battery drives
         ;; session-level verbs (session-activate!, session-rerun!) and
         ;; REPL-level why/whynot against ONE session, which is the only
         ;; way to prove they narrate the same transaction.
         make-server-state
         dispatch-command
         ensure-session!)

(require json
         racket/cmdline
         racket/match
         racket/port
         racket/string
         racket/tcp
         (only-in "canonical-plan.rkt" plan-artifact->kernel-plans)
         "catalog.rkt"   ; N4-B attachment plan projection
         "dbtool.rkt"
         "names.rkt"
         "params.rkt"
         "query-front.rkt" ; the R2 `?` register grammar
         "query-plan.rkt"  ; Q1 catalog planner + ABI-1 wire emission
         "session.rkt"
         (only-in "tools.rkt" convert-db-folder)
         ;; RF5-B at the prompt: the producer pipeline + the consumer's
         ;; synthetic preview resolution
         (only-in "modules.rkt" load-program-list)
         (only-in "compile.rkt" program->jobs emit-program-image)
         (only-in "program-change.rkt" seal-program-draft
                  program-change-set-key)
         "change-pcs.rkt"
         (only-in "activation.rkt" parse-change-set resolve-activation
                  activation-refusal? base-env
                  change-set-diffs change-set-slot-lineage
                  activation-plan? activation-plan-version-allocs
                  activation-plan-program-key))

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
                              kept
                              ;; T5 (d3): id -> break-intent, the standing
                              ;; breakpoints armed against this session's
                              ;; daemon (their own id space, `bN`)
                              breaks)
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
                      handles
                      ;; T5 slice (c): the held-run record while a command is
                      ;; parked at the pre-commit gate, or #f
                      [held #:mutable])
  #:transparent)

;; T5 slice (c) / R4: a run HELD at the pre-commit gate (repl-ux §9.2 -- the
;; pause is a place, not an interruption).  The command that started it is
;; still in flight on `thread`, blocked inside the session driver's pause
;; hook with its whole continuation intact -- prepared boundary, remaining
;; strata, commit, change summary.  The REPL answered the operator with the
;; pause record instead; `commit`, `replay` and `abort` resume that thread,
;; and every other command runs meanwhile against the parked epoch, which
;; the daemon admits precisely because it is parked (slice (b)'s lease).
(struct held-run (thread to-run from-run source [record #:mutable]
                         [parks #:mutable] [replays #:mutable]
                         ;; T5 slice (c3): `finish` runs to the next clean
                         ;; iteration boundary, which is an ordinary pause
                         ;; with no debugger cause -- this one-shot box is
                         ;; what tells the held thread's hook to hold it
                         ;; anyway instead of driving past.
                         hold-next))

;; Raised INTO the held thread by `abort`.  An exn:fail subtype on purpose:
;; the session's boundary driver already unwinds a failed run through
;; abort-boundary (session.rkt), and the daemon's abort forces a parked
;; gate epoch to settle first -- so abort needs no second unwind path, only
;; a marker the REPL can tell apart from a real fault.
(struct exn:fail:gate-abort exn:fail ())

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
   (make-hash)
   (make-hash)))

;; a fresh, connection-less server state -- the stateful harness entry
(define (make-server-state)
  (server-state (make-hash) #f #f #f (make-hash) #f))

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
   "  csv-import FOLDER [as NAME]"
   "                      infer comma/whitespace rows into a binary database and open it"
   "  open NAME           load NAME, or switch to its resident in-memory copy"
   "  current             describe the current database"
   "  resident            list databases currently held in memory"
   "  discard session     close the current in-memory session without saving"
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
   "  watch REL level 1 why  also capture this event's derivations, so"
   "                      `why` can answer afterwards (observed loop)"
   "  why [(REL t ...)]   the proof tree for a fact, or -- bare, at a gate"
   "                      park -- for the candidates that stopped the run"
   "  whynot (REL t ...)  why a fact is NOT there: per rule, the first body"
   "                      position with nothing to match (the frontier)"
   "  break REL | rN[@k]  stop the run AT a port: when a rule writes REL,"
   "   [when (REL t|_ ...)]  when rule N fires, or at its body position k"
   "  breaks | unbreak bN list the standing breaks, or remove one"
   "  commit|replay|abort resolve a run held at the pre-commit gate: take"
   "                      the change, rerun the same read, or discard it"
   "  step [match|fire|   walk the held read one interpreter port at a time"
   "   emit|tuple|rule rN] (from the gate it replays the read to get there)"
   "  finish              leave the ports; run to the next iteration boundary"
   "  frames              the join stack at the current step stop"
   "  watch cone REL [image KEY]  derive level-0 watches over REL's whole"
   "                      dependency-ancestor cone in the mounted image; the"
   "                      SET re-derives semantically (rerun after an edit)"
   "  unwatch wN          remove one watch;  `watches` lists them"
   "  explain ?QUERY      show the query plan and degradations, do not run"
   "  tiers               show each stratum's execution rung (interp/-O0/-O2)"
   "  code sN | HASH      show one stratum's rung, artifacts, and plan shape"
   "  images              list sealed ProgramImages mounted read-only"
   "  image mount PATH    validate and mount one compiler .pimg package"
   "  image KEY [rules|sources|kernels|plans|activation|materializations]"
   "                      inspect semantic image data or executor caches"
   "  image KEY activate  seal, bind, and run its interpreted cohorts"
   "  image unmount KEY   release the decoded mount (the file is unchanged)"
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
   "  whatif add|del REL V...  preview the edit's cone: affected relations,"
   "                      sizes, and the repair route -- nothing is mutated"
   "  replace instance ALIAS with \"LIB.slog\"  seal a program-replacement"
   "                      proposal from the last-run program (RF5-B)"
   "  preview             re-render the pending proposal's diffs/dispositions"
   "  activate            run the pending proposal's activation transaction"
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

;; RF2-B/RF3/RF4 sealed ProgramImage register.  The daemon owns the independent
;; decoder/seal check, immutable mount, generation-gated interpreted
;; activation, and native-materialization overlay; this layer turns its
;; structured control-catalog rows into the same presentation-neutral JSON
;; used by every other REPL observation.
(define (program-image-catalog s command)
  (define lines
    (session-command-stream!
     s command
     (lambda (line) (regexp-match? #px"^\\(catalog-end [0-9]+\\)$" line))))
  (filter values (map read-datum (drop-right lines 1))))

(define (record-field record key [default #f])
  (match (assq key (cdr record))
    [(list _ value) value]
    [_ default]))

(define (image-record-line record)
  (match record
    [`(catalog-program ,_ ...)
     (format "~a · ~a rule~a · ~a kernel~a · ~a plan~a · ~a source~a~a"
             (record-field record 'image-key)
             (record-field record 'rules 0)
             (if (= (record-field record 'rules 0) 1) "" "s")
             (record-field record 'kernels 0)
             (if (= (record-field record 'kernels 0) 1) "" "s")
             (record-field record 'plans 0)
             (if (= (record-field record 'plans 0) 1) "" "s")
             (record-field record 'sources 0)
             (if (= (record-field record 'sources 0) 1) "" "s")
             (if (record-field record 'activated #f) " · active" ""))]
    [`(catalog-program-source ,_ ...)
     (format "s~a · module m~a · ~a · ~a token~a"
             (record-field record 'slot)
             (record-field record 'module)
             (record-field record 'path)
             (record-field record 'tokens 0)
             (if (= (record-field record 'tokens 0) 1) "" "s"))]
    [`(catalog-program-rule ,_ ...)
     (format "r~a · heads ~a · source ~a · ~a"
             (record-field record 'slot)
             (string-join (record-field record 'heads '()) ", ")
             (match (record-field record 'source)
               [#f "external"] [slot (format "s~a" slot)])
             (record-field record 'normalized))]
    [`(catalog-program-kernel ,_ ...)
     (format "k~a · level ~a · ~a"
             (record-field record 'slot)
             (record-field record 'level)
             (string-join (record-field record 'members '()) ", "))]
    [`(catalog-program-plan ,_ ...)
     (format "p~a · ~a · ~a"
             (record-field record 'slot)
             (record-field record 'digest)
             (record-field record 'plan))]
    [`(catalog-program-activation ,_ ...)
     (format "~a · ~a · SCC ~a · ~a cohort~a · ~a kernel~a"
             (record-field record 'image-key)
             (record-field record 'state)
             (record-field record 'first-scc)
             (record-field record 'cohorts 0)
             (if (= (record-field record 'cohorts 0) 1) "" "s")
             (record-field record 'kernels 0)
             (if (= (record-field record 'kernels 0) 1) "" "s"))]
    [`(catalog-program-materialization ,_ ...)
     (define variants (record-field record 'variants 0))
     (define native (record-field record 'native '()))
     (define artifact (record-field record 'artifact-key #f))
     (format "p~a/k~a · cache ~a~a · ~a/~a native · ~a artifact + ~a interpreted attachment~a"
             (record-field record 'plan-slot)
             (record-field record 'kernel-ordinal)
             (record-field record 'cache-state)
             (if artifact (format " · ~a" artifact) "")
             (length native) variants
             (record-field record 'artifact-attachments 0)
             (record-field record 'interpreted-attachments 0)
             (if (= (+ (record-field record 'artifact-attachments 0)
                       (record-field record 'interpreted-attachments 0))
                    1)
                 "" "s"))]
    [_ (~s record)]))

(define (program-image-record->json record)
  (for/hasheq ([field (in-list (cdr record))]
               #:when (and (list? field) (= (length field) 2)))
    (values (car field)
            (let ([value (cadr field)])
              (cond [(symbol? value) (symbol->string value)]
                    [(list? value) (map ~a value)]
                    [else value])))))

(define (program-image-view-result title kind records)
  (hash-set
   (text-result title
                (if (null? records)
                    (list "no mounted image records")
                    (map image-record-line records))
                #:kind kind)
   'records (map program-image-record->json records)))

(define (program-images-result state)
  (define records
    (program-image-catalog (ensure-session! state) '(catalog programs)))
  (program-image-view-result "Mounted program images" "program-images" records))

(define (program-image-result state argument)
  (define parts (read-command-data 'image argument))
  (define s (ensure-session! state))
  (match parts
    [(list 'mount path)
     (define lines
       (session-command-stream! s `(mount-program-image ,(relation-key path))
                                (lambda (_line) #t)))
     (define reply (read-datum (first lines)))
     (match reply
       [`(program-image-mounted ,fields ...)
        (define key (match (assq 'image-key fields) [(list _ v) v]))
        (define hit? (match (assq 'cache-hit fields) [(list _ v) v]))
        (hash-set
         (text-result
          "Program image mounted"
          (list (format "~a · ~a"
                        key (if hit? "validated cache hit" "validated and mounted")))
          #:kind "program-image-mount")
         'image-key key)]
       [_ (error 'image "unexpected daemon mount reply: ~a" reply)])]
    [(list 'unmount key)
     (define lines
       (session-command-stream! s `(unmount-program-image ,(relation-key key))
                                (lambda (_line) #t)))
     (define reply (read-datum (first lines)))
     (match reply
       [`(program-image-unmounted (image-key ,image-key) (mounted ,remaining))
        (text-result "Program image unmounted"
                     (list (format "~a · ~a mount~a remain"
                                   image-key remaining
                                   (if (= remaining 1) "" "s")))
                     #:kind "program-image-unmount")]
       [_ (error 'image "unexpected daemon unmount reply: ~a" reply)])]
    [(list key 'activate)
     (define rs (ensure-mutable-session-record! state 'image))
     (define image-key (relation-key key))
     (match-define (list _ generation hit? first-scc cohorts kernels)
       (session-activate-program-image! (repl-session-session rs) image-key))
     (set-repl-session-changed?! rs #t)
     (text-result
      "Program image activated"
      (list
       (format "~a · ~a" image-key
               (if hit? "already active" "sealed, bound, and settled"))
       (format "generation ~a · SCC ~a · ~a cohort~a · ~a kernel~a"
               generation first-scc cohorts (if (= cohorts 1) "" "s")
               kernels (if (= kernels 1) "" "s")))
      #:kind "program-image-activation")]
    [(list key)
     (define image-key (relation-key key))
     (program-image-view-result
      (format "Program image · ~a" image-key) "program-image"
      (program-image-catalog s `(catalog program ,image-key)))]
    [(list key (and view (or 'sources 'rules 'kernels 'plans 'activation
                             'materializations)))
     (define image-key (relation-key key))
     (program-image-view-result
      (format "Program image ~a · ~a" image-key view)
      (format "program-image-~a" view)
      (program-image-catalog s `(catalog program ,image-key ,view)))]
    [_ (error 'image
              "expected: image mount PATH | image unmount KEY | image KEY activate | image KEY [sources|rules|kernels|plans|activation|materializations]")]))

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
  (id kind target [bound-key #:mutable] [last-count #:mutable] level
      provenance)
  #:transparent)

(define (next-watch-id registry)
  (let loop ([n (add1 (hash-count registry))])
    (define id (format "w~a" n))
    (if (hash-has-key? registry id) (loop (add1 n)) id)))

;; T5 slice (d1): `provenance` rides every registration and every rebind --
;; the arming the capture sink reads is the DAEMON's, so a watch that
;; forgets it at a successor key stops capturing exactly when the run that
;; matters begins (the same lesson as the level field in slice (b)).
;; Returns #t when the daemon reported the binding as settleable at level 1
;; -- T5 (d4)'s registration honesty: every storage kind settles now, so a
;; #f means the relation simply has no full index yet and the gate would
;; never engage.  Level-0 registrations answer #t (nothing to settle).
(define (register-daemon-watch! s id key #:level [level 0]
                                #:provenance [provenance #f])
  (define settleable? (box #t))
  (session-command-stream!
   s
   (cond
     [(and (= level 1) provenance)
      `(watch (id ,id) (version-key ,key) (level 1) (provenance #t))]
     [(= level 1) `(watch (id ,id) (version-key ,key) (level 1))]
     [else `(watch (id ,id) (version-key ,key))])
   (lambda (line)
     (when (and (string? line) (regexp-match? #px"\\(settleable #f\\)" line))
       (set-box! settleable? #f))
     #t))
  (unbox settleable?))

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

;; ---- §18.5 derived watches: the first meta-program -----------------------
;;
;; `watch cone REL [image KEY]` runs a meta-query over the mounted image's
;; dependency records -- "which relations could transitively contribute to
;; a derivation of REL" is ancestor reachability over heads x bodies --
;; and derives one WatchRequest per cone member.  Each request installs
;; through the ORDINARY level-0 watch protocol below: rules derive
;; requests, the client installs them (repl.md §6's invariant intact).
;; The derived SET is semantic: re-running the command against a successor
;; image re-derives it after a refactor or an RF5 activation, while each
;; installed watch remains a version-pinned capability that dies with its
;; version -- exactly the §18.5 split.
(define (watch-cone-result state target-text image-key0)
  (define rs (ensure-session-record! state))
  (define s (repl-session-session rs))
  (define image-key
    (or image-key0
        (match (program-image-catalog s '(catalog programs))
          [(list one) (record-field one 'image-key)]
          ['() (error 'watch
                      "no mounted image to derive from; `image mount PATH` first")]
          [several (error 'watch
                          "~a images mounted; name one: watch cone REL image KEY"
                          (length several))])))
  (define rules
    (program-image-catalog s `(catalog program ,image-key rules)))
  (when (null? rules)
    (error 'watch "image ~a exposes no rule records" image-key))
  (define target (string->symbol target-text))
  ;; ancestors of `target` through the union of positive and negative
  ;; dependencies, by head unification: seed the target, then add every
  ;; body relation of a rule whose head is already in the cone.
  (define wildcard-rules 0)
  ;; the daemon renders relation lists as quoted strings; the meta-query
  ;; unifies by qname symbol
  (define (as-symbols values)
    (for/list ([v (in-list (or values '()))])
      (if (string? v) (string->symbol v) v)))
  (define (rule-heads record) (as-symbols (record-field record 'heads)))
  (define (rule-bodies record)
    (append (as-symbols (record-field record 'positive))
            (as-symbols (record-field record 'negative))))
  (define cone
    (let loop ([members (set target)])
      (define grown
        (for/fold ([acc members]) ([record (in-list rules)])
          (if (for/or ([head (in-list (rule-heads record))])
                (set-member? acc head))
              (for/fold ([acc acc]) ([body (in-list (rule-bodies record))])
                (set-add acc body))
              acc)))
      (if (= (set-count grown) (set-count members)) grown (loop grown))))
  ;; the daemon always emits the (negative-wildcard ...) field, empty as `()`
  ;; -- and an empty list is TRUTHY in Racket, so this must test for a
  ;; non-empty list or the note fires on every wildcard-free cone rule.
  (for ([record (in-list rules)])
    (when (and (pair? (record-field record 'negative-wildcard))
               (for/or ([head (in-list (rule-heads record))])
                 (set-member? cone head)))
      (set! wildcard-rules (add1 wildcard-rules))))
  ;; install one ordinary level-0 watch per LIVE cone member; image-only
  ;; or not-yet-versioned relations are reported, never guessed at.
  (define registry (repl-session-watches rs))
  (define (already-watched? name)
    (for/or ([(_ intent) (in-hash registry)])
      (and (eq? (watch-intent-kind intent) 'relation)
           (equal? (watch-intent-target intent) name))))
  (define catalog (live-catalog s))
  (define outcomes
    (for/list ([member (in-list (sort (set->list cone) symbol<?))])
      (define name (symbol->string member))
      (cond
        [(already-watched? name) (list member 'already #f)]
        [else
         (define relation
           (with-handlers ([exn:fail? (lambda (_e) #f)])
             (relation-from-catalog 'watch catalog name)))
         (define key (and relation (relation-info-version-key relation)))
         (cond
           [(not (string? key)) (list member 'inactive #f)]
           [else
            (define id (next-watch-id registry))
            (register-daemon-watch! s id key)
            (hash-set! registry id
                       (watch-intent id 'relation name key #f 0 #f))
            (list member 'watched id)])])))
  (define (of kind) (filter (lambda (o) (eq? (second o) kind)) outcomes))
  (define lines
    (append
     (for/list ([o (in-list (of 'watched))])
       (format "~a — ~a installed (level 0)" (first o) (third o)))
     (for/list ([o (in-list (of 'already))])
       (format "~a — already watched" (first o)))
     (for/list ([o (in-list (of 'inactive))])
       (format "~a — no live VersionKey; derived, not installed" (first o)))
     (if (> wildcard-rules 0)
         (list (format "note: ~a cone rule~a with wildcard negation read beyond these relations"
                       wildcard-rules (if (= wildcard-rules 1) "" "s")))
         '())))
  (hash-set*
   (text-result
    (format "Derived watch cone for ~a (image ~a…): ~a relation~a"
            target-text (substring image-key 0 (min 12 (string-length image-key)))
            (set-count cone) (if (= (set-count cone) 1) "" "s"))
    lines
    #:kind "watch-cone")
   'target target-text
   'image-key image-key
   'members (map (lambda (o) (hasheq 'relation (format "~a" (first o))
                                     'outcome (format "~a" (second o))
                                     'watch (and (third o) (format "~a" (third o)))))
                 outcomes)))

;; ---- RF5-B at the prompt: replace instance / preview / activate -----------
;;
;; rf5-contract §6's initial surface, the slice §10.1 assigns to RF5-B.
;; `replace instance ALIAS with "LIB.slog"` edits the LAST-RUN program by
;; retargeting that one instantiate line, then runs the ORDINARY producer
;; pipeline -- both images compiled, the total-coverage draft
;; (auto-program-draft: nothing inferred), the sealed ProgramChangeSet,
;; the frozen templated fixture (change-pcs.rkt) -- and renders the
;; PREVIEW from a synthetic resolution: dispositions, diff counts, typed
;; refusals.  Nothing touches the live session until `activate`, which
;; substitutes the placeholders against the committed boundary
;; (session-activate-pcs!) and runs the proven A2 transaction.  `preview`
;; re-renders the pending proposal.  drafts persist under out/drafts/.

(define repl-last-run (make-weak-hasheq))
(define repl-proposals (make-weak-hasheq))
(define repl-draft-counter (box 0))

(define (proposal-compile-image source-path)
  (define program
    (first (load-program-list (path->string source-path) (hash))))
  (define pp (program->jobs program))
  (define out-dir (make-temporary-file "repl-draft-image-~a" 'directory))
  (dynamic-wind
    void
    (lambda ()
      (define-values (image _path)
        (emit-program-image program (first pp) out-dir
                            #:type-env (fourth pp) #:model (fifth pp)))
      image)
    (lambda () (delete-directory/files out-dir))))

;; synthetic preview: the pcs-check convention -- placeholders substitute
;; against the synthetic base, the consumer resolves at layer-new/1
(define (proposal-preview pcs-text)
  (define vslots (make-hash))
  (define substituted
    (regexp-replace*
     #px"@V:([A-Za-z0-9_.]+)@"
     (string-replace (string-replace pcs-text "@BASE-PROGRAM@" "p1:layer-base:0")
                     "@BASE-BOUNDARY@" "b1:layer-base:0")
     (lambda (_ rel)
       (format "v1:layer-base:0:~a"
               (hash-ref! vslots rel (lambda () (hash-count vslots)))))))
  (define cs (parse-change-set (read (open-input-string substituted))))
  (cond
    [(activation-refusal? cs) (list (format "~a" cs))]
    [else
     (define diffs (change-set-diffs cs))
     (define result
       (resolve-activation
        cs
        (base-env "p1:layer-base:0" "b1:layer-base:0" #t
                  (for/hash ([sl (in-list (change-set-slot-lineage cs))]
                             #:when (second sl))
                    (values (first sl) (second sl)))
                  '(smt seq))
        #:layer "layer-new" #:event 1))
     (cond
       [(activation-refusal? result) (list (format "~a" result))]
       [else
        (define allocs (activation-plan-version-allocs result))
        (define (of disp)
          (sort (for/list ([(q a) (in-hash allocs)]
                           #:when (eq? (third a) disp))
                  q)
                symbol<?))
        (append
         (list (format "diffs: ~a" diffs))
         (list (format "rebuild: ~a" (of 'rebuild))
               (format "carry: ~a relation~a" (length (of 'carry))
                       (if (= 1 (length (of 'carry))) "" "s"))
               (if (null? (of 'retire))
                   "retire: none"
                   (format "retire: ~a" (of 'retire))))
         (list "route: correctness-first · publication: commit after audits"
               "nothing is live yet — `activate` runs the transaction"))])]))

(define (replace-instance-result state argument)
  (define m
    (regexp-match
     #px"^instance[[:space:]]+([^[:space:]]+)[[:space:]]+with[[:space:]]+\"([^\"]+)\"[[:space:]]*$"
     (string-trim argument)))
  (unless m
    (error 'replace "expected: replace instance ALIAS with \"LIB.slog\""))
  (match-define (list _ alias lib) m)
  (define rs (ensure-session-record! state))
  (define base-path
    (or (hash-ref repl-last-run rs #f)
        (error 'replace "no program has been run in this session; `run PATH` first")))
  (define base-dir (or (path-only (string->path base-path)) (build-path ".")))
  (define base-text (file->string base-path))
  ;; retarget exactly ONE instantiate line -- explicit, or refuse
  (define pattern
    (pregexp (format "instantiate[[:space:]]+\"([^\"]+)\"[[:space:]]+as[[:space:]]+~a\\b"
                     (regexp-quote alias))))
  (define hits (regexp-match* pattern base-text))
  (unless (= 1 (length hits))
    (error 'replace
           (if (null? hits)
               (format "no `instantiate ... as ~a` occurrence in ~a" alias base-path)
               (format "~a occurrences of instance ~a; replacement must select exactly one"
                       (length hits) alias))))
  (define candidate-text
    ;; regexp-replace-quote: a lib or alias containing `&` or `\N` must
    ;; insert literally, not be interpreted as a backreference splice
    (regexp-replace pattern base-text
                    (regexp-replace-quote
                     (format "instantiate \"~a\" as ~a" lib alias))))
  ;; the draft directory: candidate main + every lib it references
  (define n (begin (set-box! repl-draft-counter (add1 (unbox repl-draft-counter)))
                   (unbox repl-draft-counter)))
  (define draft-dir (build-path "out" "drafts" (format "d~a" n)))
  (make-directory* draft-dir)
  (define lib-names
    (remove-duplicates
     (for/list ([hit (in-list (regexp-match* #px"instantiate[[:space:]]+\"([^\"]+)\""
                                             candidate-text
                                             #:match-select cadr))])
       hit)))
  (for ([name (in-list lib-names)])
    (define src (build-path base-dir name))
    (unless (file-exists? src)
      (error 'replace "library ~a not found beside ~a" name base-path))
    (copy-file src (build-path draft-dir name) #t))
  (define main-name
    (format "~a-draft~a.slog"
            (path->string
             (path-replace-extension (file-name-from-path base-path) ""))
            n))
  (define candidate-path (build-path draft-dir main-name))
  (call-with-output-file candidate-path #:exists 'replace
    (lambda (o) (display candidate-text o)))
  ;; the producer pipeline
  (define base-image (proposal-compile-image (string->path base-path)))
  (define candidate-image (proposal-compile-image candidate-path))
  (define change-set
    (seal-program-draft (auto-program-draft base-image candidate-image)))
  (define sources
    (append (for/list ([name (in-list lib-names)])
              (cons name (file->string (build-path draft-dir name))))
            (list (cons main-name candidate-text))))
  (define pcs-text
    (pcs->string
     (program-change-set->pcs change-set base-image candidate-image
                              #:sources sources)))
  (define preview-lines (proposal-preview pcs-text))
  ;; stamp the boundary this proposal was sealed against: the diffs,
  ;; dispositions, and cone are all computed relative to THIS program, so
  ;; `activate` must refuse if the tip has since moved (a `run` in between)
  ;; rather than silently applying A's plan to program B.
  (hash-set! repl-proposals rs
             (hasheq 'alias alias 'lib lib 'base base-path
                     'key (program-change-set-key change-set)
                     'boundary (boundary-key
                                (session-current-boundary
                                 (repl-session-session rs)))
                     'pcs pcs-text 'preview preview-lines))
  (text-result
   (format "Proposal d~a — replace instance ~a with ~a (sealed ~a…)"
           n alias lib
           (substring (program-change-set-key change-set) 0 12))
   preview-lines
   #:kind "replace-instance"))

(define (preview-result state)
  (define rs (ensure-session-record! state))
  (define proposal
    (or (hash-ref repl-proposals rs #f)
        (error 'preview "no pending proposal; `replace instance ALIAS with \"LIB.slog\"` first")))
  (text-result
   (format "Proposal — replace instance ~a with ~a (sealed ~a…)"
           (hash-ref proposal 'alias) (hash-ref proposal 'lib)
           (substring (hash-ref proposal 'key) 0 12))
   (hash-ref proposal 'preview)
   #:kind "preview"))

(define (activate-result state argument)
  (unless (string=? (string-trim argument) "")
    (error 'activate
           "bare `activate` commits after audits; a pre-commit hold rides an armed level-1 watch (`watch REL level 1`)"))
  (define rs (ensure-session-record! state))
  (define proposal
    (or (hash-ref repl-proposals rs #f)
        (error 'activate "no pending proposal; `replace instance ...` first")))
  (define s (repl-session-session rs))
  ;; the proposal is only valid against the boundary it was sealed on: if
  ;; the tip moved (a `run` since `replace`), the diffs and cone describe a
  ;; program that is no longer live -- refuse rather than misapply them
  (define now-boundary (boundary-key (session-current-boundary s)))
  (unless (equal? now-boundary (hash-ref proposal 'boundary #f))
    (error 'activate
           "the committed boundary moved since this proposal was sealed (~a → ~a); re-issue `replace instance ...` against the current program"
           (hash-ref proposal 'boundary #f) now-boundary))
  (define result (session-activate-pcs! s (hash-ref proposal 'pcs)))
  (cond
    [(activation-plan? result)
     (hash-remove! repl-proposals rs)
     (set-repl-session-changed?! rs #t)
     (text-result
      (format "Activated — ~a" (activation-plan-program-key result))
      (list (format "instance ~a now runs ~a; the old boundary remains addressable"
                    (hash-ref proposal 'alias) (hash-ref proposal 'lib))
            "committed atomically after recount and audits")
      #:kind "activate")]
    [else
     (text-result "Activation refused or aborted"
                  (list (format "~a" result)
                        "the proposal is retained; the base boundary is unchanged")
                  #:kind "activate")]))

;; ---- R5 whatif: the operator's edge (repl-ux §8) --------------------------
;;
;; `whatif del edge 1 2` (or `whatif del (edge 1 2)`) answers "what would
;; this edit break?" from the maintenance machinery's own cone and route
;; classification, READ-ONLY: affected relations with their committed
;; sizes, the repair route the flush would choose, and whether the edited
;; tuple is present now.  Nothing is staged, nothing runs, nothing
;; commits -- the summary says so explicitly.
(define (whatif-result state argument)
  (define raw (string-trim argument))
  (define parsed
    (match (regexp-match #px"^(add|del)[[:space:]]+(.*)$" raw)
      [(list _ verb rest)
       (match (read-command-data 'whatif rest #:minimum 1)
         ;; both spellings: `whatif del (edge 1 2)` and `whatif del edge 1 2`
         [(list (list* rel values)) (list verb rel values)]
         [(list* rel values) (list verb rel values)])]
      [_ (error 'whatif "expected: whatif add|del REL VALUE... (or whatif del (REL VALUE...))")]))
  (match-define (list verb rel values) parsed)
  (define rs (ensure-session-record! state))
  (define s (repl-session-session rs))
  (define sign (if (string=? verb "add") '+ '-))
  (define rel-name (relation-key rel))
  ;; cone-of raises when the target was rebound after a cone stratum (the
  ;; flush would divert to an anchored walk).  A preview must report that,
  ;; not crash at the prompt.
  (match-define (list affected route cone-strata mono? negatable?)
    (with-handlers
        ([exn:fail?
          (lambda (e)
            (error 'whatif
                   "~a cannot be previewed at the tip: ~a; the flush would take an anchored walk"
                   rel-name (exn-message e)))])
      (session-whatif s sign rel-name)))
  (define catalog (live-catalog s))
  (define (size-of name)
    (with-handlers ([exn:fail? (lambda (_e) #f)])
      (relation-info-size
       (relation-from-catalog 'whatif catalog (format "~a" name)))))
  (define tuple-text
    (format "(~a ~a)" rel-name (string-join (map ~s values) " ")))
  (define matches
    (with-handlers ([exn:fail? (lambda (_e) #f)])
      (run-watch-query state rs (string-append "?" tuple-text))))
  ;; This is the COARSE cone classification from cone-of's monotone/negatable
  ;; test -- not the precise route.  The flush certifies a finer route at run
  ;; time (M1/M3/M4N/M4T/M6L/M7) or falls back to clear-and-rerun; a lattice
  ;; or struct cone in particular may maintain where this says clear-rerun.
  (define route-line
    (case route
      [(input-only)
       "likely route: input-only edit — no derived relation reads this one"]
      [(maintain-positive)
       (format "likely route: positive maintenance across ~a ~a (monotone cone; flush certifies the precise route)"
               cone-strata (if (= cone-strata 1) "stratum" "strata"))]
      [(maintain-negative)
       (format "likely route: negative-then-positive maintenance across ~a ~a (negatable cone; flush certifies the precise route)"
               cone-strata (if (= cone-strata 1) "stratum" "strata"))]
      [else
       (format "likely route: clear-and-rerun across ~a ~a (~a; a certified maintenance route may still apply)"
               cone-strata (if (= cone-strata 1) "stratum" "strata")
               (if (eq? sign '+) "non-monotone cone" "cone not negatable"))]))
  (hash-set*
   (text-result
    (format "Whatif ~a ~a" verb tuple-text)
    (append
     (list
      (cond
        [(not matches) (format "~a — presence not checkable here" tuple-text)]
        [(eq? sign '-)
         (format "~a — ~a row~a match~a now~a"
                 tuple-text matches (if (= matches 1) "" "s")
                 (if (= matches 1) "es" "")
                 (if (zero? matches) " (retraction would be a no-op)" ""))]
        [else
         (format "~a — ~a now (~a)"
                 tuple-text
                 (if (zero? matches) "absent" "already present")
                 (if (zero? matches) "a genuine addition" "addition would be a no-op"))]))
     (if (null? affected)
         (list (format "no derived relations read ~a" rel-name))
         (for/list ([name (in-list affected)])
           (define n (size-of name))
           (format "~a — ~a affected"
                   name (if n (format "~a row~a now;" n (if (= n 1) "" "s")) ""))))
     (list route-line
           "nothing staged, nothing mutated — preview only"))
    #:kind "whatif")
   'relation rel-name
   'sign (format "~a" sign)
   'affected (map (lambda (n) (format "~a" n)) affected)
   'route (format "~a" route)))

(define (watch-result state argument)
  (define raw (string-trim argument))
  (when (string=? raw "")
    (error 'watch "expected: watch REL [level 1 [why]] | watch ?QUERY | watch cone REL [image KEY]"))
  ;; §18.5: the derived-cone form dispatches before the single-target forms.
  (define cone-match
    (regexp-match
     #px"^cone[[:space:]]+([^[:space:]]+)([[:space:]]+image[[:space:]]+([^[:space:]]+))?[[:space:]]*$"
     raw))
  (if cone-match
      (watch-cone-result state (second cone-match) (fourth cone-match))
      (watch-result/single state raw)))

(define (watch-result/single state raw)
  ;; T5 slice (a): `watch REL level 1` records the pre-commit-gate intent
  ;; (docs/t5-contract.md) and forces the relation's writer SCCs onto the
  ;; interpreter at their next re-entry (client-side policy, ratified).
  ;; T5 slice (d1): a trailing `why` additionally captures the event's
  ;; derivations, which is what makes `why` answerable afterwards -- opt-in
  ;; because it is what puts the interpreter on its observed loop.
  (define-values (text level provenance)
    (match (regexp-match
            #px"^(.*[^[:space:]])[[:space:]]+level[[:space:]]+([01])([[:space:]]+why)?$"
            raw)
      [(list _ target n why) (values target (string->number n) (and why #t))]
      [_ (values raw 0 #f)]))
  (when (and provenance (not (= level 1)))
    (error 'watch "provenance capture (`why`) is a level-1 watch's observation"))
  (define rs (ensure-session-record! state))
  (define registry (repl-session-watches rs))
  (define id (next-watch-id registry))
  (cond
    [(string-prefix? text "?")
     (when (= level 1)
       (error 'watch
              "query watches are client-side re-counts; level 1 applies to relation watches"))
     (define count (run-watch-query state rs text))
     (hash-set! registry id (watch-intent id 'query text #f count 0 #f))
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
     (define settleable?
       (register-daemon-watch! s id key #:level level #:provenance provenance))
     (define flipped
       (if (= level 1)
           (session-set-scc-policy! s (string->symbol text) 'interpreted)
           '()))
     (hash-set! registry id
                (watch-intent id 'relation text key #f level provenance))
     (text-result
      (format "Watch ~a" id)
      (append
       (list (format "~a @ ~a — hits report at coherent barriers~a~a"
                     text key (if (= level 1) " · level 1" "")
                     (if provenance " · why" "")))
       (if settleable?
           '()
           (list (string-append
                  "note: the pre-commit gate cannot settle this relation "
                  "yet — it has no full index, so level-1 hits report at "
                  "barriers like level 0 until one exists")))
       (if (null? flipped)
           '()
           (list (format "writer strat~a ~a pinned to the interpreter for future re-entries"
                         (if (= (length flipped) 1) "um" "a")
                         (string-join (map (lambda (n) (format "s~a" n)) flipped)
                                      ", ")))))
      #:kind "watch")]))

;; ---- T5 slice (d2): `whynot` -- the failure frontier (repl-ux §9.4) ------
;;
;; The frontier is a PLAN-DIRECTED PROBE over committed state, not a replay
;; of a captured iteration (contract §4(d2) records the deviation and why).
;; For each rule that can write the target's relation, unify the target with
;; the head, walk the rule's atoms in plan order, and probe prefixes through
;; the ordinary `?count` spine until one is empty: that atom is the frontier,
;; and the count before it is how many bindings reached it.
;;
;; Honest edges, all reported rather than smoothed over: a head that cannot
;; unify never probes; a computed position ends the walk (a prefix past it is
;; not expressible as a query); delta views probe as full views, because the
;; question is about the state that exists now.

;; A register's query spelling: its bound value, or a variable named for the
;; register (plan registers are already dense and unique per rule).
(define (frontier-term env reg)
  (define bound (hash-ref env reg #f))
  (cond
    [(not bound) (format "V~a" reg)]
    [(string? bound) (~s bound)]
    [(number? bound) (~a bound)]
    [else #f]))                          ; a value no query text can spell

;; (r N) -> N, (k N) -> the constant's value; #f for anything else.
(define (frontier-ref r ref)
  (match ref
    [`(r ,n) n]
    [`(k ,n) (plan-constant-value (plan-rule-constants r) n)]
    [_ #f]))

;; One plan atom -> (relation . terms-in-nominal-order), or #f when the op is
;; not a relation probe at all.  `order` maps physical position to nominal
;; column, exactly as it does for the daemon's proof rows; a K-prefix filter
;; names only its bound columns and the rest are wildcards.
(define (frontier-atom r op)
  (define (relation slot) (plan-relation-name (plan-rule-relations r) slot))
  (define (arity slot)
    (match (findf (lambda (e) (match e [`(rel ,n ,_) (equal? n slot)] [_ #f]))
                  (plan-rule-relations r))
      [`(rel ,_ (,_kind ,_name ,a ,_ ...)) a]
      [_ 0]))
  ;; place `refs` (index order) into nominal columns through `order`
  (define (nominal slot order refs)
    (define columns (make-vector (arity slot) '_))
    (for ([col (in-list order)] [ref (in-list refs)])
      (when (< col (vector-length columns)) (vector-set! columns col ref)))
    (vector->list columns))
  (match op
    [`(scan (rel ,slot) ,refs ...)        ; drivers scan in NOMINAL order
     (cons (relation slot) refs)]
    [`(probe (rel ,slot) ,order ,_K ,refs ...)
     (cons (relation slot) (nominal slot order refs))]
    [`(,(or 'join 'join-old 'join-new 'join-tomb) (rel ,slot) ,order ,_K
       ,refs ...)
     (cons (relation slot) (nominal slot order refs))]
    [`(,(or 'exists 'absent) (rel ,slot) ,order ,_K ,refs ...)
     (cons (relation slot) (nominal slot order refs))]
    [_ #f]))

(define (frontier-negated? op)
  (match op [`(absent ,_ ...) #t] [_ #f]))

;; The atoms of one rule, in plan order, plus how far they can be spelled.
;; Returns (values atoms stopped-at) where `stopped-at` is the op that ended
;; the walk (#f when the whole body is expressible).
(define (frontier-atoms r)
  (let loop ([ops (cons (plan-rule-driver r) (plan-rule-body r))]
             [atoms '()] [guards '()])
    (cond
      [(null? ops) (values (reverse atoms) (reverse guards) #f)]
      [else
       (define op (car ops))
       (define atom (frontier-atom r op))
       (cond
         [atom (loop (cdr ops)
                     (cons (list atom (frontier-negated? op) op) atoms)
                     guards)]
         ;; guards ride along with the prefix that binds their operands
         [(match op [`(neq ,_ ,_) #t] [`(cmp ,_ ,_ ,_) #t] [_ #f])
          (loop (cdr ops) atoms (cons op guards))]
         ;; `eq` is an aliasing constraint the probe expresses by equality
         [(match op [`(eq ,_ ,_) #t] [_ #f])
          (loop (cdr ops) atoms (cons op guards))]
         [else (values (reverse atoms) (reverse guards) op)])])))

(define frontier-guard-ops (hash '< "<" '<= "<=" '> ">" '>= ">=" 'lt "<"
                                 'le "<=" 'gt ">" 'ge ">="))

;; Unify the target with this rule's head.  Returns the register environment,
;; or #f when the head shape cannot produce the target at all.
(define (frontier-unify r target-args)
  (define env (make-hash))
  ;; constants loaded before the driver bind their registers
  (for ([op (in-list (plan-rule-pre r))])
    (match op
      [`(let (r ,reg) (k ,slot))
       (hash-set! env reg (plan-constant-value (plan-rule-constants r) slot))]
      [_ (void)]))
  (define head
    (for/or ([h (in-list (plan-rule-head r))])
      (match h [`(emit (rel ,_slot) ,_order ,refs ...) refs] [_ #f])))
  (and head
       (= (length head) (length target-args))
       (for/and ([ref (in-list head)] [value (in-list target-args)])
         (match ref
           [`(r ,reg)
            (define bound (hash-ref env reg #f))
            (cond [(not bound) (hash-set! env reg value) #t]
                  [else (equal? bound value)])]
           [`(k ,slot)
            (equal? (plan-constant-value (plan-rule-constants r) slot) value)]
           [_ #f]))
       env))

(define (frontier-atom-text r env atom)
  (match-define (cons relation refs) atom)
  (define terms
    (for/list ([ref (in-list refs)])
      (cond
        [(eq? ref '_) "_"]
        [else
         (define resolved (frontier-ref r ref))
         (cond
           [(match ref [`(k ,_) #t] [_ #f])
            (cond [(string? resolved) (~s resolved)]
                  [(number? resolved) (~a resolved)]
                  [else #f])]
           [(exact-nonnegative-integer? resolved) (frontier-term env resolved)]
           [else #f])])))
  (and (andmap values terms)
       (format "(~a~a)" relation
               (if (null? terms) "" (string-append " "
                                                   (string-join terms " "))))))

(define (frontier-guard-text r env op)
  (match op
    [`(neq ,x ,y)
     (define a (frontier-term env (frontier-ref r x)))
     (define b (frontier-term env (frontier-ref r y)))
     (and a b (format "(/= ~a ~a)" a b))]
    [`(cmp ,f ,x ,y)
     (define op-text (hash-ref frontier-guard-ops f #f))
     (define a (frontier-term env (frontier-ref r x)))
     (define b (frontier-term env (frontier-ref r y)))
     (and op-text a b (format "(~a ~a ~a)" op-text a b))]
    ;; `eq` is realized by ALIASING the two registers before any text is
    ;; built, so by the time guards render there is nothing left to say.
    [`(eq ,_ ,_) ""]
    [_ #f]))

;; (eq (r a) (r b)) makes the two registers one variable; resolve through the
;; alias chain wherever a register is spelled.
(define (frontier-aliases r guards)
  (define aliases (make-hash))
  (for ([op (in-list guards)])
    (match op
      [`(eq (r ,a) (r ,b)) (unless (equal? a b) (hash-set! aliases b a))]
      [_ (void)]))
  aliases)

(define (frontier-resolve aliases reg)
  (let loop ([reg reg] [fuel 16])
    (define next (hash-ref aliases reg #f))
    (if (and next (positive? fuel)) (loop next (sub1 fuel)) reg)))

;; Fold the alias map into everything BEFORE any text is built: two
;; registers the rule equates must become one query variable, or the probe
;; would join them independently and answer optimistically.
(define (frontier-alias-ref aliases ref)
  (match ref
    [`(r ,n) `(r ,(frontier-resolve aliases n))]
    [other other]))

(define (frontier-alias-atoms aliases atoms)
  (for/list ([entry (in-list atoms)])
    (match-define (list (cons relation refs) negated? op) entry)
    (list (cons relation
                (for/list ([ref (in-list refs)])
                  (frontier-alias-ref aliases ref)))
          negated? op)))

(define (frontier-alias-env aliases env)
  (define folded (make-hash))
  (for ([(reg value) (in-hash env)])
    (hash-set! folded (frontier-resolve aliases reg) value))
  folded)

;; One rule's frontier: walk its prefixes until one is empty.  Returns a list
;; of report lines for that rule.
(define (frontier-for-rule state rs r target-args)
  (define env0 (frontier-unify r target-args))
  (define env env0)
  (define label
    (format "  r~a · ~a · ~a" (plan-rule-rid r)
            (or (plan-rule-source r) "?") (plan-rule-variant r)))
  (cond
    [(not env0)
     (list label "    head cannot produce this fact (shape or constants)")]
    [else
     (define-values (raw-atoms guards stopped) (frontier-atoms r))
     (define aliases (frontier-aliases r guards))
     (define atoms (frontier-alias-atoms aliases raw-atoms))
     (set! env (frontier-alias-env aliases env))
     (define texts
       (for/list ([entry (in-list atoms)])
         (match-define (list atom negated? _op) entry)
         (define text (frontier-atom-text r env atom))
         (and text (if negated? (string-append "~" text) text))))
     (define guard-texts
       (for/list ([g (in-list guards)])
         (frontier-guard-text
          r env
          (match g
            [`(,op ,x ,y) (list op (frontier-alias-ref aliases x)
                                (frontier-alias-ref aliases y))]
            [`(cmp ,f ,x ,y) (list 'cmp f (frontier-alias-ref aliases x)
                                   (frontier-alias-ref aliases y))]
            [other other]))))
     (cond
       [(not (andmap values texts))
        (list label "    an atom holds a value no query can spell; stopping")]
       [(null? texts)
        (list label "    this rule has no probeable body (a ground fact rule)")]
       [else
        ;; prefixes, shortest first: the first empty one is the frontier
        (define frontier
          (let loop ([k 1] [previous #f])
            (cond
              [(> k (length texts)) (cons 'satisfiable previous)]
              [else
               (define prefix (take texts k))
               (define text
                 (string-append "?count "
                                (string-join prefix " ")
                                (if (= k (length texts))
                                    (string-append
                                     (if (null? (filter values guard-texts))
                                         ""
                                         " ")
                                     (string-join
                                      (filter (lambda (g)
                                                (and g (not (equal? g ""))))
                                              guard-texts)
                                      " "))
                                    "")))
               (define count
                 (with-handlers ([exn:fail? (lambda (_) #f)])
                   (run-watch-query state rs text)))
               (cond
                 [(not count) (cons 'unprobeable k)]
                 [(zero? count) (cons 'frontier (cons k previous))]
                 [else (loop (add1 k) count)])])))
        (append
         (list label)
         (match frontier
           [(cons 'satisfiable previous)
            (append
             (for/list ([t (in-list texts)]) (format "    ~a" t))
             (list (format "    every position is satisfiable~a — the fact should be derivable here"
                           (if previous (format " (~a binding~a)" previous
                                                (if (= previous 1) "" "s"))
                               ""))))]
           [(cons 'unprobeable k)
            (append
             (for/list ([t (in-list (take texts k))]) (format "    ~a" t))
             (list "    this prefix is not answerable as a query; stopping"))]
           [(cons 'frontier (cons k previous))
            (append
             (for/list ([t (in-list (take texts (sub1 k)))]
                        [i (in-naturals 1)])
               (format "    ~a~a" t
                       (if (and (= i (sub1 k)) previous)
                           (format "   ~a way~a" previous
                                   (if (= previous 1) "" "s"))
                           "")))
             (list (format "    ~a   ✗ nothing matches — the frontier"
                           (list-ref texts (sub1 k)))))])
         (if stopped
             (list (format "    (analysis stops before a computed position: ~a)"
                           (car stopped)))
             '()))])]))

(define (whynot-result state argument)
  (define raw (string-trim argument))
  (when (string=? raw "")
    (error 'whynot "expected: whynot (relation term ...)"))
  (define shape (read-datum raw))
  (unless (and (pair? shape) (symbol? (first shape)))
    (error 'whynot "whynot names ONE ground fact: whynot (relation term ...)"))
  (for ([term (in-list (rest shape))])
    (when (symbol? term)
      (error 'whynot "~a is a variable; whynot names one GROUND fact" term)))
  (define relation (symbol->string (first shape)))
  (define rs (ensure-session-record! state))
  (define s (repl-session-session rs))
  ;; one representative variant per rule: the atom set is the same, only the
  ;; driver and the delta views differ, and the frontier asks about state
  (define seen (make-hash))
  (define rules
    (for/list ([r (in-list (session-plan-rules s))]
               #:when (and (equal? (~a (plan-rule-head-relation r)) relation)
                           (not (hash-ref seen
                                          (cons (plan-rule-hash r)
                                                (plan-rule-rid r)) #f)))
               #:do [(hash-set! seen (cons (plan-rule-hash r)
                                           (plan-rule-rid r)) #t)])
      r))
  ;; The first thing to check is whether the premise of the question holds:
  ;; a fact that IS there needs `why`, not a frontier.  Distinguish a
  ;; failing probe from a confirmed absence: a swallowed query error must
  ;; not masquerade as "absent" and send the frontier over a premise it
  ;; never established.
  (define present?
    (with-handlers ([exn:fail? (lambda (e) (cons 'unprobeable (exn-message e)))])
      (positive? (run-watch-query state rs (format "?count ~a" raw)))))
  (define unprobeable-note
    (and (pair? present?)
         (format "(could not probe presence: ~a) — showing the frontier anyway"
                 (cdr present?))))
  (define body
    (cond
      [(eq? present? #t)
       (list (format "~a is present — `why ~a` explains how it got here" raw raw))]
      [(null? rules)
       (list (format "no resident rule writes ~a (see `tiers` and `code`)"
                     relation))]
      [else
       (append
        (append*
         (for/list ([r (in-list rules)])
           (frontier-for-rule state rs r (rest shape))))
        (list (format "~a rule~a can write ~a · frontier over COMMITTED state at this boundary"
                      (length rules) (if (= (length rules) 1) "" "s")
                      relation)))]))
  (attach-session-state state
                        (text-result (format "Why not ~a" raw)
                                     (if unprobeable-note
                                         (cons unprobeable-note body)
                                         body)
                                     #:kind "proof")))

;; ---- T5 slice (d3): standing breakpoints (repl-ux §9.1) ------------------
;;
;;   break REL                     stop when a rule writes REL
;;   break REL when (REL 99 _)     ... and the fact it writes matches
;;   break rN                      stop when rule N fires (an instantiation)
;;   break rN@k                    stop at body position k of rule N
;;   breaks | unbreak bN
;;
;; This is the entry path stepping lacked: a step needs an existing park, so
;; before (d3) every port needed a level-1 watch to trip the gate first.  A
;; relation break pins that relation's writer strata to the interpreter the
;; same way a level-1 watch does -- without the flip there are no ports to
;; stop at, and saying so is part of the UX (repl-ux §9.1's cost note).
(struct break-intent (id kind target position pattern) #:transparent)

(define (next-break-id registry)
  (let loop ([n (add1 (hash-count registry))])
    (define id (format "b~a" n))
    (if (hash-has-key? registry id) (loop (add1 n)) id)))

;; `break rN` still needs a relation to pin: the rule's own head, read out of
;; the canonical plan.
(define (break-rule-relation s rid)
  (for/or ([r (in-list (session-plan-rules s))]
           #:when (equal? (plan-rule-rid r) rid))
    (plan-rule-head-relation r)))

(define (break-result state argument)
  (define raw (string-trim argument))
  (when (string=? raw "")
    (error 'break "expected: break REL [when (REL t ...)] | break rN[@k]"))
  (define-values (head when-text)
    (match (regexp-match #px"^(.*?)[[:space:]]+when[[:space:]]+(.*)$" raw)
      [(list _ target pattern) (values (string-trim target) pattern)]
      [_ (values raw #f)]))
  (define-values (target position)
    (match (regexp-match #px"^(.*[^[:space:]])@([0-9]+)$" head)
      [(list _ t k) (values t (string->number k))]
      [_ (values head #f)]))
  (define rid
    (match (regexp-match #px"^r([0-9]+)$" target)
      [(list _ n) (string->number n)]
      [_ #f]))
  (when (and position (not rid))
    (error 'break "a body position belongs to a rule: break rN@~a" position))
  (define rs (ensure-session-record! state))
  (define s (repl-session-session rs))
  (define registry (repl-session-breaks rs))
  (define id (next-break-id registry))
  ;; the relation whose writers must run interpreted for the ports to exist
  (define relation
    (~a
     (cond
      [rid (or (break-rule-relation s rid)
               (error 'break
                      "no rule r~a in a resident normal-flavor plan (see `code`)"
                      rid))]
      [else (relation-info-name
             (relation-from-catalog 'break (live-catalog s) target))])))
  ;; The pattern is read directly rather than through the query front end:
  ;; a query drops `_` columns from its fact template (they cannot be
  ;; projected), and a break pattern is exactly where wildcards belong.
  (define pattern
    (and when-text
         (let ([shape (read-datum when-text)])
           (unless (and (pair? shape) (symbol? (first shape)))
             (error 'break
                    "when takes one fact pattern of constants and _: when (~a 99 _)"
                    relation))
           (for/list ([term (in-list (rest shape))])
             (if (eq? term '_) '_ (why-term state term))))))
  (define flipped (session-set-scc-policy! s (string->symbol relation)
                                           'interpreted))
  (session-command-stream!
   s
   `(break (id ,id)
           ,@(if rid `((rule ,rid)) `((relation ,relation)))
           ,@(if position `((position ,position)) '())
           ,@(if pattern `((pattern ,@pattern)) '()))
   (lambda (_line) #t))
  (hash-set! registry id
             (break-intent id (if rid 'rule 'relation)
                           (if rid (format "r~a" rid) relation)
                           position when-text))
  (text-result
   (format "Break ~a" id)
   (append
    (list (format "~a~a~a — stops the run at the port, where step/frames/why work"
                  (if rid (format "rule r~a" rid) relation)
                  (if position (format " body position ~a" position) "")
                  (if when-text (format " when ~a" when-text) "")))
    (if (null? flipped)
        '()
        (list (format "writer strat~a ~a pinned to the interpreter (a native stratum has no ports)"
                      (if (= (length flipped) 1) "um" "a")
                      (string-join (map (lambda (n) (format "s~a" n)) flipped)
                                   ", ")))))
   #:kind "break"))

(define (unbreak-result state argument)
  (define id (string-trim argument))
  (define rs (ensure-session-record! state))
  (define registry (repl-session-breaks rs))
  (unless (hash-has-key? registry id)
    (error 'unbreak "no break named ~a; `breaks` lists them" id))
  (with-handlers ([exn:fail? void])
    (session-command-stream! (repl-session-session rs) `(unbreak (id ,id))
                             (lambda (_line) #t)))
  (hash-remove! registry id)
  (text-result (format "Break ~a removed" id)
               (list (format "~a break~a armed" (hash-count registry)
                             (if (= (hash-count registry) 1) "" "s")))
               #:kind "break"))

;; The daemon owns the hit counts, so the listing is its answer, not the
;; client's memory of what it asked for.
(define (breaks-result state)
  (define rs (ensure-session-record! state))
  (define lines
    (session-debug-lines! (repl-session-session rs) '(breaks)
                          (lambda (l) (regexp-match? #px"^\\(breaks-end " l))))
  (define rows
    (for*/list ([line (in-list lines)]
                #:do [(define datum (read-datum line))]
                #:when (match datum [`(break ,_ ...) #t] [_ #f]))
      (match datum
        [`(break (id ,id) (relation ,relation) (rule ,rule)
                 (position ,position) (pattern ,pattern) (hits ,hits))
         (format "~a  ~a~a~a · ~a hit~a" id
                 (if (equal? rule '#f) relation (format "r~a" rule))
                 (if (equal? position '#f) ""
                     (format "@~a" position))
                 (if (equal? (~a pattern) "") ""
                     (format " when (~a~a)"
                             (if (equal? relation "") "" (format "~a " relation))
                             pattern))
                 hits (if (equal? hits 1) "" "s"))])))
  (text-result "Breaks"
               (if (null? rows)
                   (list "none; `break REL` or `break rN` arms one")
                   rows)
               #:kind "break"))

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
            (format "~a  ~a @ ~a~a~a" (watch-intent-id intent)
                    (watch-intent-target intent)
                    (or (watch-intent-bound-key intent) "suspended")
                    (if (= (watch-intent-level intent) 1) " · level 1" "")
                    (if (watch-intent-provenance intent) " · why" ""))]
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
                                    #:level (watch-intent-level intent)
                                    #:provenance
                                    (watch-intent-provenance intent))
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

;; T5 slice (c): a structured refusal the DRIVER met mid-run -- today a
;; `replay` the daemon would not honour (a non-monotone epoch answers
;; `level-1-unwatchable`, any non-gate park answers `replay-unavailable`).
;; The run commits past it, so without this the refusal would vanish; a
;; debugger continuation that was declined is exactly what the operator
;; needs told.
(define (refusal-records events)
  (for/list ([line (in-list events)]
             #:do [(define datum (read-datum line))]
             #:when (match datum [`(refused ,_ ,_ ,_ ...) #t] [_ #f]))
    (match datum
      [`(refused ,class ,_generation ,detail ...)
       (hasheq 'class (~a class)
               'detail (for/list ([d (in-list detail)]) (format "~s" d)))])))

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
          'tiers (tier-records events)
          'refusals (refusal-records events)))

(define (make-change s operation target status requested events before after)
  (define-values (revision counts) (settled-session-state s))
  (assemble-change operation target status requested events before after
                   revision counts))

;; T5 slice (b): before a prepared run's strata execute, rebind each
;; level-1 RELATION intent whose target the plan CREATES to the successor
;; VersionKey -- that is what lets the pre-commit gate observe the run
;; (a semantic run always writes successor instances).  Retained
;; relations keep their bindings; failures degrade to the post-event
;; rebind (the gate misses that run, honestly).
(define (prepare-rebind-level1! rs plan)
  (define registry (repl-session-watches rs))
  (when (positive? (hash-count registry))
    (define s (repl-session-session rs))
    (define actions
      (match (assq 'actions (cdr (boundary-plan->datum plan)))
        [(cons _ acts) acts]
        [_ '()]))
    (for ([act (in-list actions)])
      (match act
        [`(create (qname ,name) ,key ,_ ,_)
         (for ([intent (in-hash-values registry)]
               #:when (and (eq? (watch-intent-kind intent) 'relation)
                           (= (watch-intent-level intent) 1)
                           (equal? (watch-intent-target intent) (~a name))))
           (with-handlers ([exn:fail? void])
             (silent-unwatch! s (watch-intent-id intent))
             (register-daemon-watch! s (watch-intent-id intent) (~a key)
                                     #:level 1
                                     #:provenance
                                     (watch-intent-provenance intent))
             (set-watch-intent-bound-key! intent (~a key))))]
        [_ (void)]))))

(define (capture-semantic-change state rs operation status requested thunk)
  (define s (repl-session-session rs))
  (define before (catalog-size-snapshot s))
  (define-values (value events)
    (parameterize ([session-prepare-hook
                    (lambda (_s plan) (prepare-rebind-level1! rs plan))])
      (capture-session-events state thunk)))
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
   ;; T5 slice (c): debugger continuations the daemon declined mid-run
   (let ([refusals (hash-ref change 'refusals '())])
     (if (null? refusals)
         '()
         (list
          (format "refused: ~a"
                  (string-join
                   (for/list ([record (in-list refusals)])
                     (string-join (cons (hash-ref record 'class)
                                        (hash-ref record 'detail)) " "))
                   "; ")))))
   ;; the operator's heartbeat: watch hits, rebinds, and query deltas
   (hash-ref change 'watches '())))

(define (brief-change-summary-lines change)
  ;; The structured change record remains authoritative and the Rust client
  ;; exposes it as the collapsed `Change details` tree. Keep the ordinary
  ;; transcript to the one fact every operator needs, plus alerts that would
  ;; be unsafe to hide. Diagnostic clients may still consume `lines`.
  (define status (hash-ref change 'status))
  (define refusal-lines
    (let ([refusals (hash-ref change 'refusals '())])
      (if (null? refusals)
          '()
          (list
           (format "refused: ~a"
                   (string-join
                    (for/list ([record (in-list refusals)])
                      (string-join (cons (hash-ref record 'class)
                                         (hash-ref record 'detail)) " "))
                    "; "))))))
  (append
   (list (if (string=? status "settled") "committed" status))
   refusal-lines
   (hash-ref change 'watches '())))

(define (semantic-text-result title lines change #:kind kind)
  (hash-set
   (text-result title (append lines (change-summary-lines change))
                #:kind kind #:change change)
   'brief-lines
   (append lines (brief-change-summary-lines change))))

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
     (define inferred-schema
       (and (not (db-managed? name))
            (let ([path (format "data/~a/import.slog" name)])
              (and (file-exists? path) path))))
     (define-values (_ events change)
       (with-handlers
           ([exn:fail?
             (lambda (e)
               (with-handlers ([exn:fail? void])
                 (session-close! (repl-session-session rs)))
               (raise e))])
         (capture-semantic-change
          state rs "open" "settled" '()
          (lambda ()
            (session-open! (repl-session-session rs) name)
            (when inferred-schema
              (session-run! (repl-session-session rs) inferred-schema))))))
     (hash-set! sessions name rs)
     (set-server-state-current! state name)
     (semantic-text-result
      (format "Opened ~a" name)
      (append
       (list (if replay?
                 "compressed load materialized retained data and recomputed replay layers"
                 "database loaded into a new mutable in-memory workspace"))
       (if inferred-schema
           (list "the inferred import schema established its logical input boundary")
           '())
       (list "Try `current`, `tables`, `state`, `show REL`, or `query REL V...`."))
      change
      #:kind "open")]))

;; A narrow interactive adapter over tools.rkt's transactional folder
;; importer.  This is deliberately a real REPL operation rather than a
;; tutorial-only shell escape: tutorials and people exercise the same path.
;; The implicit name is collision-free, making a tutorial safe to repeat
;; without replacing an unrelated saved database.
(define csv-import-db-name-rx #px"^[A-Za-z0-9][A-Za-z0-9_.-]*$")

(define (csv-import-parts argument)
  (define text (string-trim argument))
  (when (string=? text "")
    (error 'csv-import "expected: csv-import FOLDER [as NAME]"))
  (match (regexp-match #px"^(.*)[[:space:]]+as[[:space:]]+([^[:space:]]+)$" text)
    [(list _ folder name) (values (string-trim folder) name #t)]
    [_ (values text #f #f)]))

(define (csv-import-derived-name folder)
  (unless (directory-exists? folder)
    (error 'csv-import "~a is not a folder" folder))
  (define-values (_base name _dir?)
    (split-path (simplify-path (path->complete-path folder))))
  (define candidate (and (path? name) (path->string name)))
  (unless (and candidate (regexp-match? csv-import-db-name-rx candidate))
    (error 'csv-import
           "cannot derive a database name from ~a; use `csv-import ~a as NAME`"
           folder folder))
  candidate)

(define (csv-import-name-taken? state name)
  (or (db-exists? name)
      (hash-has-key? (server-state-sessions state) name)))

(define (csv-import-available-name state base)
  (let loop ([suffix 1])
    (define candidate
      (if (= suffix 1) base (format "~a-~a" base suffix)))
    (if (csv-import-name-taken? state candidate)
        (loop (add1 suffix))
        candidate)))

(define (csv-import-result state argument)
  (define-values (folder requested-name explicit?) (csv-import-parts argument))
  (define base (or requested-name (csv-import-derived-name folder)))
  (unless (regexp-match? csv-import-db-name-rx base)
    (error 'csv-import
           "database NAME must use letters, digits, dot, underscore, or hyphen"))
  (when (and explicit? (csv-import-name-taken? state base))
    (error 'csv-import
           "database ~a already exists on disk or in this REPL; choose another name"
           base))
  (define name (if explicit? base (csv-import-available-name state base)))
  (define report-port (open-output-string))
  (parameterize ([current-output-port report-port]
                 [current-error-port report-port])
    (convert-db-folder folder name))
  (define report
    (filter (lambda (line) (not (string=? line "")))
            (string-split (get-output-string report-port) "\n")))
  (define opened (open-database! state name))
  (hash-set
   (hash-set
    (hash-set opened 'title (format "Imported and opened ~a" name))
    'lines
    (append
     (list (format "~a → data/~a/ · binary relations are ready" folder name))
     report
     (hash-ref opened 'lines '())))
   'brief-lines
   (append
    (list (format "~a → database ~a" folder name))
    (hash-ref opened 'brief-lines (hash-ref opened 'lines '())))))

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

(define (discard-session-result state argument)
  (unless (string=? (string-downcase (string-trim argument)) "session")
    (error 'discard "expected: discard session"))
  (when (server-state-held state)
    (error 'discard
           "a run is held at the debugger gate; resolve it with commit, replay, or abort first"))
  (define key (server-state-current state))
  (unless key
    (error 'discard "there is no current in-memory session"))
  (define sessions (server-state-sessions state))
  (define rs (hash-ref sessions key #f))
  (unless rs
    (error 'discard "the current in-memory session is no longer resident"))
  (discard-query-cursor! rs)
  (session-close! (repl-session-session rs))
  (hash-remove! sessions key)
  (set-server-state-current! state #f)
  (text-result
   (format "Discarded ~a" (session-display-name key rs))
   (list "the in-memory session and its unsaved extensions were closed"
         "saved database files were not changed")
   #:kind "discard"))

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
    (error 'clear
           (string-append
            "expected: `clear scratch` to retract scratch definitions; "
            "use `discard session` to close the current in-memory session, "
            "or `:clear` to clear only the transcript")))
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

;; ---- the canonical plan as the client's rule table (T5 (d2)/(d3)) --------
;;
;; `code` already reads build/<hash>.plan for its shape line; the debugger
;; reads the same artifact as the RULE SET.  It is post-planning truth --
;; what actually runs -- with (r N) registers where the source had variables,
;; (k N) slots into the constants table, and (rel N) slots into the relation
;; table.  Only NORMAL-flavor plans are read: contract §0.1 is monotone-only,
;; and a counted or maintenance variant answers a different question.

(struct plan-rule
  (stratum hash rid variant source relations constants nregs pre driver body head)
  #:transparent)

(define (plan-field parts key)
  (match (assq key parts) [(cons _ values) values] [_ #f]))

(define (read-stratum-plan hash)
  (define path (format "build/~a.plan" hash))
  (and (file-exists? path)
       (with-handlers ([exn:fail? (lambda (_) #f)])
         (call-with-input-file path read))))

;; The stratum's ABI-1-equivalent kernel-plan views, whatever the artifact
;; shape: one for a monolith, one per kernel (plus the rule-free services
;; plan) for an ABI-2 cohort.  Post-flip, cohorts are the normal case.
(define (read-stratum-plan-views hash)
  (define form (read-stratum-plan hash))
  (if form (plan-artifact->kernel-plans form) '()))

;; (rel 2) -> 'path, given the plan's relation table
(define (plan-relation-name relations slot)
  (match (findf (lambda (r) (match r [`(rel ,n ,_) (equal? n slot)] [_ #f]))
                relations)
    [`(rel ,_ (,_kind ,name ,_arity ,_orders ...)) name]
    [_ #f]))

;; (k 0) -> 9, given the plan's constants table
(define (plan-constant-value constants slot)
  (match (findf (lambda (k) (match k [`(k ,n ,_ ,_) (equal? n slot)] [_ #f]))
                constants)
    [`(k ,_ ,_name ,value) value]
    [_ #f]))

(define (session-plan-rules s)
  (filter
   values
   (for*/list ([row (in-list (session-tiers s))]
              [plan (in-list (read-stratum-plan-views (second row)))]
              #:do [(define parts (match plan [`(kernel-plan ,ps ...) ps] [_ #f]))]
              #:when (and parts
                          (equal? (car (or (plan-field parts 'flavor) '(#f)))
                                  'normal))
              #:do [(define relations (or (plan-field parts 'relations) '()))
                    (define constants (or (plan-field parts 'constants) '()))
                    (define meta (or (plan-field parts 'meta) '()))]
              [rule (in-list (or (plan-field parts 'rules) '()))])
    (match rule
      [`(rule-def (rid ,rid) (variant ,variant) (nregs ,nregs)
                  (pre ,pre ...) (driver ,driver) (body ,body ...)
                  (head ,head ...))
       (plan-rule (first row) (second row) rid variant
                  (for/or ([m (in-list meta)])
                    (match m
                      [`(rule-meta (rid ,(== rid)) (source ,src)) src]
                      [_ #f]))
                  relations constants nregs pre driver body head)]
      [_ #f]))))

;; The relation a rule writes -- its first ordinary head emit.  Struct and
;; lattice heads answer #f: they are (d4)'s settles, not this slice's.
(define (plan-rule-head-relation r)
  (for/or ([h (in-list (plan-rule-head r))])
    (match h
      [`(emit (rel ,slot) ,_order ,_regs ...)
       (plan-relation-name (plan-rule-relations r) slot)]
      [_ #f])))

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
      ;; ABI 2 (the default since the RF1 flip): the stratum is a cohort of
      ;; per-SCC kernels.  Report the cohort's own shape -- kernels and their
      ;; content-addressed keys are the load-bearing facts here -- and derive
      ;; sources through the DebugMap views, the same adaptation the daemon
      ;; performs at its decoder boundary.
      [`(kernel-cohort ,parts ...)
       (define (field key)
         (match (assq key parts) [(cons _ values) values] [_ #f]))
       (define manifest (or (field 'manifest) '()))
       (define rule-count
         (for/sum ([m (in-list manifest)])
           (match m [`(kernel ,_ ... (rules ,n)) n] [_ 0])))
       (define sources
         (remove-duplicates
          (filter values
                  (for*/list ([view (in-list (plan-artifact->kernel-plans plan))]
                              [m (in-list (match view
                                            [`(kernel-plan ,ps ...)
                                             (match (assq 'meta ps)
                                               [(cons _ ms) ms] [_ '()])]))])
                    (match m
                      [`(rule-meta (rid ,_) (source ,src))
                       (and (string? src) src)]
                      [_ #f])))))
       (append
        (list (format "flavor: ~a · abi ~a · ~a kernels · ~a declarations · ~a rule variants"
                      (car (or (field 'flavor) '(unknown)))
                      (car (or (field 'abi) '(0)))
                      (length manifest)
                      (length (or (field 'declarations) '()))
                      rule-count)
              (format "dynamic: ~a"
                      (string-join (map ~a (or (field 'dynamic) '())) ", ")))
        (for/list ([m (in-list manifest)])
          (match m
            [`(kernel (ord ,i) (key ,key) (members ,ms ...) ,rest ...)
             (format "kernel ~a: ~a · ~a"
                     i (substring key 0 (min 16 (string-length key)))
                     (if (assq 'prelude rest)
                         "prelude"
                         (string-join (map ~a ms) ", ")))]
            [_ ""]))
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

;; ---- T5 slice (c) / R4: the pre-commit gate as a place ---------------------
;; A level-1 watch is an explicit request to stop the run before it commits,
;; so a session that has armed one runs its semantic commands on a HELD
;; thread: the driver's pause hook hands the gate record out and blocks, the
;; command answers with that record, and the operator's next commands work
;; the parked epoch until one of them resolves it.  Sessions without a
;; level-1 watch -- and any embedding that installs its own
;; `session-pause-hook`, which then owns the pause -- keep the shipped
;; straight-through path byte for byte.

;; Which pauses the server HOLDS: the pre-commit gate (a level-1 watch
;; citation at phase read) and, once stepping is armed, the step stop the
;; interpreter reports as a breakpoint.  Budget and boundary pauses stay
;; auto-continued -- they are progress, not places.
(define (gate-pause-line? line)
  (and (regexp-match? #px"^\\(paused " line)
       (or (regexp-match? #px"\\(cause \\(breakpoint " line)
           (and (regexp-match? #px"\\(phase read\\)" line)
                (regexp-match? #px"\\(cause \\(watch " line)))))

(define (step-stop-line? line)
  (and (string? line) (regexp-match? #px"\\(cause \\(breakpoint " line)))

(define (pause-breakpoint-detail line)
  (match (read-datum line)
    [`(paused ,fields ...)
     (match (assq 'cause fields)
       [(list _ `(breakpoint ,detail)) (~a detail)]
       [_ #f])]
    [_ #f]))

;; `step`, `step match|fire|emit|tuple`, `step rule rN|N` -> the wire line
;; the daemon's dispatcher takes, or #f when the spelling is not one.
(define (step-command-line argument)
  (define parts (string-split (string-trim argument)))
  (match parts
    ['() "(step)"]
    [(list (and grain (or "match" "fire" "emit" "tuple"))) (format "(step ~a)" grain)]
    [(list "rule" target)
     (define n (string->number (regexp-replace #px"^r" target "")))
     (and (exact-nonnegative-integer? n) (format "(step rule ~a)" n))]
    [_ #f]))

(define (session-level1-armed? state)
  (define rs (current-repl-session state))
  (and rs
       (or
        ;; T5 (d3): a standing break makes the prompt a place for the same
        ;; reason a level-1 watch does -- without the hold, the pause hook
        ;; drives past the stop and nobody is sitting at it.
        (positive? (hash-count (repl-session-breaks rs)))
        (for/or ([intent (in-hash-values (repl-session-watches rs))])
          (and (eq? (watch-intent-kind intent) 'relation)
               (= (watch-intent-level intent) 1))))))

;; Verbs that run on THIS thread even with a level-1 watch armed: they either
;; resolve a pause or observe one, and neither wants a held run of its own.
(define pause-resolution-verbs
  '("commit" "continue" "replay" "abort" "step" "frames" "finish" "why"
    "breaks" "unbreak" "whynot"))

;; Fields of the uniform pause record, for rendering (t0-contract).
(define (pause-record-field line key)
  (match (read-datum line)
    [`(paused ,fields ...)
     (match (assq key fields)
       [(list _ value) value]
       [_ #f])]
    [_ #f]))

(define (pause-watch-citations line)
  (match (read-datum line)
    [`(paused ,fields ...)
     (match (assq 'cause fields)
       [(list _ `(watch ,cites ...))
        (for/list ([cite (in-list cites)]
                   #:when (match cite [`(watch-id ,_) #t] [_ #f]))
          (match cite [`(watch-id ,id) (~a id)]))]
       [_ '()])]
    [_ '()]))

(define (held-pause-result state held)
  (define line (held-run-record held))
  (define cites (pause-watch-citations line))
  (define rs (current-repl-session state))
  (define registry (and rs (repl-session-watches rs)))
  (define stepped? (step-stop-line? line))
  ;; T5 (d3): a break stop is a step stop the operator armed in advance, so
  ;; the daemon reports the same breakpoint cause -- with the break's id in
  ;; front of the port, which is the only thing that distinguishes them.
  (define broke
    (match (and stepped? (pause-breakpoint-detail line))
      [(? string? detail)
       (match (regexp-match #px"^(b[0-9]+):" detail)
         [(list _ id) id]
         [_ #f])]
      [_ #f]))
  (define watch-lines
    (for/list ([id (in-list cites)])
      (define intent (and registry (hash-ref registry id #f)))
      (format "watch ~a~a — the change is settled but NOT committed"
              id
              (if intent
                  (format " · ~a" (watch-intent-target intent))
                  ""))))
  (attach-session-state
   state
   (text-result
    ;; Name the place honestly: a step stop, the pre-commit gate, or the
    ;; clean iteration boundary `finish` asked to be held at.
    (cond [broke (format "Paused · break ~a" broke)]
          [stepped? "Paused · step"]
          [(pair? cites) "Paused · pre-commit gate"]
          [else "Paused · iteration boundary"])
    (append
     (list (format "~a · iteration ~a · phase ~a"
                   (or (pause-record-field line 'stratum) "?")
                   (or (pause-record-field line 'iteration) "?")
                   (or (pause-record-field line 'phase) "?")))
     (if stepped?
         (list (format "port ~a" (or (pause-breakpoint-detail line) "?"))
               "frames shows the join stack at this port")
         '())
     watch-lines
     (list
      "queries here answer COMMITTED masters; the candidate rows are not in them"
      (format "held: ~a" (held-run-source held)))
     (if (positive? (held-run-replays held))
         (list (format "replayed ~a time~a"
                       (held-run-replays held)
                       (if (= (held-run-replays held) 1) "" "s")))
         '())
     (list (string-append
            "step [match|fire|emit|tuple] · frames · why · finish · "
            (if broke "continue · " "commit · replay · ")
            "abort")))
    #:kind "paused")))

;; The daemon reports the join stack STRUCTURALLY -- port, rule position and
;; rows.  Source variable names are the remaining half of contract §3: the
;; canonical plan's rule-meta carries only (rid source) today, and widening
;; it moves every KernelPlanKey, so that is its own change.
(define (frames-result state)
  (define rs (ensure-session-record! state))
  (define s (repl-session-session rs))
  (define lines
    (session-debug-lines! s '(frames)
                          (lambda (l) (regexp-match? #px"^\\(frames-end " l))))
  (define rendered
    (for/list ([line (in-list lines)])
      (match (read-datum line)
        [`(step-at (port ,port) (rule ,rid) (variant ,variant) (op ,op)
                   (source ,source) (tag ,tag) (tuple ,tuple))
         (format "~a at r~a~a · ~a · op ~a~a"
                 port rid
                 (if (equal? (~a tag) "") "" (format " (~a)" tag))
                 (if (equal? (~a source) "") "?" source)
                 op
                 (if (equal? (~a tuple) "") "" (format " · (~a)" tuple)))]
        [`(frame (level ,level) (kind ,kind) (row ,row))
         (format "  ~a ~a  (~a)" level kind row)]
        [`(frames-end ,n) (format "~a frame~a" n (if (= n 1) "" "s"))]
        [`(refused ,class ,_generation ,detail ...)
         (format "refused: ~a ~a" class
                 (string-join (for/list ([d (in-list detail)])
                                (format "~s" d)) " "))]
        [_ line])))
  (attach-session-state
   state
   (text-result "Frames" rendered #:kind "frames")))

;; ---- T5 slice (d1): `why` at the prompt (repl-ux §9.4) --------------------
;;
;;   why                       the candidates that tripped the pre-commit gate
;;   why (path 1 4)            one ground fact, spelled as it would be queried
;;   why (path 1 4) depth 6    the same tree, deeper
;;
;; The fact spelling goes through the QUERY front end, so `#N` handles splice
;; here exactly as they do in a query and there is no second grammar for
;; naming a tuple.  The bare form is the one that can name a candidate the
;; gate has not committed: no query can return a row that is still in the
;; send shards.
(define (why-term state term)
  (cond
    [(handle-token? term)
     (define cell (value-handle-cell
                   (resolve-value-handle state (handle-token-label term))))
     `(word ,(value-cell-word cell))]
    [(exact-integer? term) `(integer ,(number->string term))]
    [(and (real? term) (inexact? term)) `(real ,(number->string term))]
    [(string? term) `(string ,term)]
    [(symbol? term)
     (error 'why "~a is a variable; why names one GROUND fact" term)]
    [else (error 'why "unsupported term ~s" term)]))

(define (why-request state body depth)
  (define depth-field (if depth (list `(depth ,depth)) '()))
  (cond
    [(string=? body "") `(why ,@depth-field)]
    [else
     (define line
       (with-handlers
           ([exn:fail?
             (lambda (e)
               (error 'why
                      "expected: why | why (relation term ...) [depth N]"))])
         (parse-query-line (string-append "?" body)
                           #:resolve-handle (query-handle-resolver state))))
     (define pattern (query-line-pattern line))
     (unless (and (pair? pattern) (symbol? (first pattern)))
       (error 'why "why names ONE ground fact: why (relation term ...)"))
     `(why (relation ,(symbol->string (first pattern)))
           (row ,@(for/list ([term (in-list (rest pattern))])
                    (why-term state term)))
           ,@depth-field)]))

;; The daemon streams one record per node, parented by id and depth-first, so
;; indentation is a walk of the ids already in hand.
(define (render-proof-lines datums)
  (define depths (make-hash))
  (for/list ([datum (in-list datums)])
    (match datum
      [`(proof-node (id ,id) (parent ,parent) (kind ,kind)
                    (relation ,relation) (row ,row) (derivations ,n))
       (define depth (if (negative? parent) 0
                         (add1 (hash-ref depths parent 0))))
       (hash-set! depths id depth)
       (format "~a(~a~a)~a"
               (make-string (* 2 depth) #\space)
               (if (equal? relation "") "?" relation)
               (if (equal? (~a row) "") "" (format " ~a" row))
               (cond
                 [(equal? (~a kind) "cycle") "  · cycle"]
                 [(and (zero? n) (not (negative? parent))) "  · base"]
                 [(and (zero? n) (negative? parent)) "  · no captured derivation"]
                 [else ""]))]
      [`(proof-node (id ,id) (parent ,parent) (kind derivation) (rule ,rule)
                    (variant ,variant) (source ,source) (tag ,tag))
       (define depth (add1 (hash-ref depths parent 0)))
       (hash-set! depths id depth)
       (format "~a← r~a#~a · ~a~a"
               (make-string (* 2 depth) #\space)
               rule variant
               (if (equal? (~a source) "") "?" source)
               (if (equal? (~a tag) "") "" (format " · ~a" tag)))]
      [`(proof-end ,nodes (records ,records) (dropped ,dropped)
                   (depth ,depth) (truncated ,truncated))
       (format "~a node~a · ~a captured this event · depth ~a~a~a"
               nodes (if (equal? nodes 1) "" "s") records depth
               (if (equal? (~a truncated) "#t") " · truncated" "")
               (if (and (number? dropped) (positive? dropped))
                   (format " · ~a derivation~a over budget" dropped
                           (if (= dropped 1) "" "s"))
                   ""))]
      [`(refused ,class ,_generation ,detail ...)
       (format "refused: ~a ~a" class
               (string-join (for/list ([d (in-list detail)])
                              (format "~s" d)) " "))]
      [other (format "~a" other)])))

(define (why-result state argument)
  (define raw (string-trim argument))
  (define-values (body depth)
    (match (regexp-match
            #px"^(.*?)[[:space:]]*depth[[:space:]]+([0-9]+)$" raw)
      [(list _ rest n) (values (string-trim rest) (string->number n))]
      [_ (values raw #f)]))
  (define request (why-request state body depth))
  (define rs (ensure-session-record! state))
  (define lines
    (session-debug-lines! (repl-session-session rs) request
                          (lambda (l)
                            (regexp-match? #px"^\\(proof-end " l))))
  (attach-session-state
   state
   (text-result (if (string=? body "") "Why · gate candidates" "Why")
                (render-proof-lines
                 (for/list ([line (in-list lines)]) (read-datum line)))
                #:kind "proof")))

;; Wait for the held thread's next event: it either finishes the command
;; (result or fault) or parks again.
(define (await-held-run state held)
  (match (channel-get (held-run-from-run held))
    [(list 'paused line)
     (set-held-run-record! held line)
     (set-held-run-parks! held (add1 (held-run-parks held)))
     (set-server-state-held! state held)
     (held-pause-result state held)]
    [(list 'result value)
     (set-server-state-held! state #f)
     value]
    [(list 'raise exception)
     (set-server-state-held! state #f)
     (if (exn:fail:gate-abort? exception)
         (attach-session-state
          state
          (text-result
           "Aborted · pre-commit gate"
           (list "the run was discarded at the gate; nothing was committed"
                 (format "discarded: ~a" (held-run-source held)))
           #:kind "mutation"))
         (raise exception))]))

;; Start a semantic command on its own thread with the gate hook installed.
(define (dispatch-held-command state source)
  (define to-run (make-channel))
  (define from-run (make-channel))
  (define hold-next (box #f))
  (define runner
    (thread
     (lambda ()
       (parameterize
           ([session-pause-hook
             (lambda (_s line)
               (cond
                 [(or (gate-pause-line? line) (unbox hold-next))
                  (set-box! hold-next #f)
                  (channel-put from-run (list 'paused line))
                  (match (channel-get to-run)
                    ['abort
                     (raise (exn:fail:gate-abort
                             "aborted at the pre-commit gate"
                             (current-continuation-marks)))]
                    [directive directive])]
                 [else 'continue]))])
         (with-handlers ([(lambda (_) #t)
                          (lambda (e) (channel-put from-run (list 'raise e)))])
           (channel-put from-run
                        (list 'result (dispatch-command* state source))))))))
  (await-held-run state
                  (held-run runner to-run from-run source #f 0 0 hold-next)))

;; A command typed while a run is held.  The three resolutions resume the
;; held thread; everything else is an ordinary observation of the parked
;; epoch, dispatched on this thread while the run stays put.
(define (dispatch-at-gate state held source)
  (define-values (verb argument) (split-command source))
  (cond
    [(member verb '("commit" "continue"))
     (channel-put (held-run-to-run held) 'continue)
     (await-held-run state held)]
    [(equal? verb "replay")
     (set-held-run-replays! held (add1 (held-run-replays held)))
     (channel-put (held-run-to-run held) 'replay)
     (await-held-run state held)]
    ;; T5 slice (c3): a step is a resume with a granularity.  From the gate
    ;; it replays the completed read and stops at the first matching port
    ;; (walking the very read that produced the candidate); from a step stop
    ;; it carries on to the next one.
    [(and (equal? verb "step")
          (equal? (string-trim argument) "iter"))
     ;; repl-ux §9.3's coarsest step is `finish` by another name.
     (dispatch-at-gate state held "finish")]
    [(equal? verb "step")
     (define line (step-command-line argument))
     (unless line
       (error 'step (string-append
                     "expected: step [match | fire | emit | tuple | iter] "
                     "| step rule rN")))
     (channel-put (held-run-to-run held) line)
     (await-held-run state held)]
    ;; `finish` leaves the ports behind and runs to the next clean
    ;; iteration boundary -- an ordinary pause, so the hook is told to hold
    ;; that one too rather than drive past it (repl-ux §9.3's coarsest
    ;; granularity).
    [(equal? verb "finish")
     (set-box! (held-run-hold-next held) #t)
     (channel-put (held-run-to-run held) "(continue-boundary)")
     (await-held-run state held)]
    ;; frames observes the stop without resuming: the run stays put.
    [(equal? verb "frames") (frames-result state)]
    [(equal? verb "abort")
     (channel-put (held-run-to-run held) 'abort)
     (await-held-run state held)]
    [(member verb '(":quit" "quit" "exit"))
     ;; never strand a held run: commit it, then quit
     (channel-put (held-run-to-run held) 'continue)
     (void (await-held-run state held))
     (dispatch-command* state source)]
    [else (dispatch-command* state source)]))

(define (dispatch-command state source)
  (define held (server-state-held state))
  (cond
    [held (dispatch-at-gate state held source)]
    [(and (session-level1-armed? state)
          (not (session-pause-hook))
          (not (member (let-values ([(verb _a) (split-command source)]) verb)
                       pause-resolution-verbs)))
     (dispatch-held-command state source)]
    [else (dispatch-command* state source)]))

(define (dispatch-command* state source)
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
    ["csv-import" (csv-import-result state argument)]
    [(or "current" "database") (current-result state)]
    [(or "resident" "sessions") (resident-result state)]
    ["discard" (discard-session-result state argument)]
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
    ["why" (why-result state argument)]
    ["whynot" (whynot-result state argument)]
    ["break" (break-result state argument)]
    ["unbreak" (unbreak-result state argument)]
    ["breaks" (breaks-result state)]
    ["watch" (watch-result state argument)]
    ["unwatch" (unwatch-result state argument)]
    ["watches" (watches-result state)]
    ["scratch" (scratch-show-result state)]
    ["keep" (keep-scratch-result state argument)]
    ["clear" (clear-scratch-result state argument)]
    ["tiers" (tiers-result state)]
    ["code" (code-result state argument)]
    ["images" (program-images-result state)]
    ["image" (program-image-result state argument)]
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
     (hash-set! repl-last-run rs argument)
     (set-repl-session-changed?! rs #t)
     (semantic-text-result
      (format "Run ~a" argument)
      (list "program completed at a settled daemon boundary")
      change
      #:kind "run")]
    ["whatif" (whatif-result state argument)]
    ["replace" (replace-instance-result state argument)]
    ["preview" (preview-result state)]
    ["activate" (activate-result state argument)]
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
    ;; T5 slice (c): the pre-commit gate's three resolutions.  They reach
    ;; here only when NOTHING is held (dispatch-command routes them to the
    ;; held thread otherwise), so the honest answer is that there is no
    ;; pause to resolve -- never a bare "unknown command".
    [(or "commit" "continue" "abort")
     (error 'debugger
            (format (string-append
                     "~a resolves a pause at the pre-commit gate; no run is "
                     "held (arm one with `watch REL level 1`)")
                    verb))]
    [(or "step" "frames" "finish")
     (error 'debugger
            (format (string-append
                     "~a works a run held at the pre-commit gate; no run is "
                     "held (arm one with `watch REL level 1`)")
                    verb))]
    ["replay"
     (error 'debugger
            (string-append
             "replay reruns a read held at the pre-commit gate; no run is "
             "held (arm one with `watch REL level 1`)"))]
    [(or ":quit" "quit" "exit")
     (set-server-state-closing?! state #t)
     (hasheq 'kind "quit" 'title "Goodbye" 'lines (list "REPL closed") 'close #t)]
    [_
     (error 'command
            (format "unknown command ~a; type :help for the current command set" verb))])]))
  (attach-session-state state result))

;; Deterministic transcript projection for the server contract.  This is a
;; test harness, not a second interactive frontend. It deliberately retains
;; the server's diagnostic `lines`; the Rust clients prefer `brief-lines` and
;; keep the same details in their expandable structured change record.
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
  (define state (server-state (make-hash) #f #f #f (make-hash) #f))
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
  ;; T5 slice (c): a connection that drops while a run is held at the gate
  ;; must not strand it -- resolve to the ordinary commit (the t0-ratified
  ;; continue) before any session closes underneath the held thread.
  (let ([held (server-state-held state)])
    (when held
      (with-handlers ([exn:fail? (lambda (e)
                                   (eprintf "held run cleanup failed: ~a\n"
                                            (exn-message e)))])
        (channel-put (held-run-to-run held) 'continue)
        (void (await-held-run state held)))
      (set-server-state-held! state #f)))
  (for ([rs (in-hash-values (server-state-sessions state))])
    (with-handlers ([exn:fail? (lambda (e)
                                 (eprintf "REPL session cleanup failed: ~a\n"
                                          (exn-message e)))])
      (session-close! (repl-session-session rs))))
  (hash-clear! (server-state-sessions state))
  (set-server-state-current! state #f))

(define (serve-connection in out token)
  (define state (server-state (make-hash) #f #f #f (make-hash) #f))
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

  (define state (server-state (make-hash) #f #f #f (make-hash) #f))
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

    (define state (server-state (make-hash) "alpha" #f #f (make-hash) #f))
    (define rs (repl-session #f "alpha" 'mutable #f "eval-1" #f (make-hash) (make-hash)
                                (make-hash)))
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
    (define other (repl-session #f "beta" 'mutable #f "eval-1" #f (make-hash) (make-hash)
                                   (make-hash)))
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
           'tiers (list (hasheq 'scc 3 'hash "4f0b9c11" 'rung "o0"))
           ;; T5 slice (c): no debugger continuation was declined here
           'refusals '()))
  ;; the arrival note renders from the captured tier event (live arrivals
  ;; depend on clang wall-clock vs fixpoint length, so the rendering is
  ;; pinned here and the verbs in the interp battery below)
  (check-not-false
   (member "tiers: s3 -> -O0 arrived" (change-summary-lines sample-change)))
  (check-equal? (brief-change-summary-lines sample-change)
                (list "committed"))

  (define mode-state (server-state (make-hash) #f #f #f (make-hash) #f))
  (hash-set! (server-state-sessions mode-state)
             "alpha"
             (repl-session #f "alpha" 'readonly #f #f #f (make-hash)
                           (make-hash) (make-hash)))
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
  (define quit-state (server-state (make-hash) #f #f #f (make-hash) #f))
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
  (let ([bare-state (server-state (make-hash) #f #f #f (make-hash) #f)])
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
    ;; (unchanged by the policy column).  Since the RF1 flip the artifact
    ;; is a cohort, so the shape line reports kernels and the card carries
    ;; each kernel's content-addressed key and members.
    (check-regexp-match
     #px"◆ Code · s2\n  stratum [0-9a-f]+ · running interp\n  cache: plan\n  flavor: normal · abi 2 · 1 kernels · [0-9]+ declarations · 1 rule variants\n  dynamic: hop2\n  kernel 0: [0-9a-f]{16} · hop2"
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
      (close-server-session! state)))

  ;; T5 slice (b): the pre-commit gate end to end.  A level-1 watch binds
  ;; the prepared successor key at prepare time (the session-prepare-hook
  ;; rebind), the run's read completes with an accepted candidate and
  ;; parks BEFORE finalize (phase read + watch cause), a query issued from
  ;; the park answers from COMMITTED masters only, and the auto-continue
  ;; commits exactly once.  Controls: a level-0 watch never gates a run,
  ;; and a maintenance epoch never gates a level-1 watch (the ratified
  ;; §7.3 downgrade -- its hits stay at iteration barriers).
  (let ([interp-environment (environment-variables-copy test-environment)])
    (environment-variables-set! interp-environment #"SLOG_OPT" #"interp")
    (parameterize ([current-directory repository-root]
                   [current-environment-variables interp-environment])
      ;; watched run: gate park, paused query, commit
      (define state (make-server-state))
      (define (run! line) (dispatch-command state line))
      (void (run! "run tests/reach.slog"))
      (void (run! "watch path level 1"))
      (define gate-lines '())
      (define paused-answer #f)
      (parameterize ([session-pause-hook
                      (lambda (_s line)
                        (when (and (regexp-match? #px"\\(phase read\\)" line)
                                   (regexp-match? #px"\\(cause \\(watch" line))
                          (set! gate-lines (cons line gate-lines))
                          (unless paused-answer
                            (set! paused-answer
                                  (string-join
                                   (hash-ref (run! "?count (path X Y)")
                                             'lines)
                                   " | ")))))])
        (void (run! "rule (path 99 99) <-- (edge 1 2)")))
      (check-equal? (length gate-lines) 1)
      (check-regexp-match
       #px"\\(paused \\(generation [0-9]+\\) \\(scc [0-9]+\\) \\(stratum \"[0-9a-f]+\"\\) \\(iteration 0\\) \\(phase read\\) \\(settled #f\\)[^\n]*\\(cause \\(watch \\(watch-id \"w1\"\\)\\)\\)\\)"
       (first gate-lines))
      ;; committed masters only: the candidate is invisible at the park
      (check-regexp-match #px"6 rows match" paused-answer)
      (check-regexp-match
       #px"7 rows match"
       (string-join (hash-ref (run! "?count (path X Y)") 'lines) " | "))
      (void (run! "dump ?(path X Y) to out/t5b-watched.csv"))
      (void (run! ":quit"))
      ;; unwatched run: byte-equal committed content
      (define state2 (make-server-state))
      (define (run2! line) (dispatch-command state2 line))
      (void (run2! "run tests/reach.slog"))
      (void (run2! "rule (path 99 99) <-- (edge 1 2)"))
      (void (run2! "dump ?(path X Y) to out/t5b-plain.csv"))
      (void (run2! ":quit"))
      (check-equal? (file->string "out/t5b-watched.csv")
                    (file->string "out/t5b-plain.csv"))
      (delete-file "out/t5b-watched.csv")
      (delete-file "out/t5b-plain.csv")
      ;; control 1: a level-0 watch never gates a run (rebinds after it)
      (define state3 (make-server-state))
      (define (run3! line) (dispatch-command state3 line))
      (void (run3! "run tests/reach.slog"))
      (void (run3! "watch path"))
      (define l0-gates 0)
      (parameterize ([session-pause-hook
                      (lambda (_s line)
                        (when (regexp-match? #px"\\(phase read\\)" line)
                          (set! l0-gates (add1 l0-gates))))])
        (void (run3! "rule (path 99 99) <-- (edge 1 2)")))
      (check-equal? l0-gates 0)
      ;; control 2: a maintenance epoch never gates a level-1 watch; its
      ;; hits report at iteration barriers with counts truthful
      (define maint-gates 0)
      (define maint-result #f)
      (void (run3! "watch path level 1"))
      (parameterize ([session-pause-hook
                      (lambda (_s line)
                        (when (and (regexp-match? #px"\\(phase read\\)" line)
                                   (regexp-match? #px"\\(cause \\(watch" line))
                          (set! maint-gates (add1 maint-gates))))])
        (set! maint-result (run3! "add edge 4 1")))
      (check-equal? maint-gates 0)
      (define maint-text
        (string-join (hash-ref maint-result 'lines) "\n"))
      (check-regexp-match #px"watch w2: .*hit" maint-text)
      (check-regexp-match #px"counts valid" maint-text)
      (void (run3! ":quit"))))

  ;; T5 slice (c): `replay` at the pre-commit gate.  The parked read's send
  ;; shards are discarded and the SAME read runs again from its origin, so
  ;; the rerun parks with the same record (an exact rerun is meant to be
  ;; indistinguishable from what it repeats), a query at the replayed park
  ;; still answers committed masters only, and the commit that follows writes
  ;; content byte-equal to a run that was never replayed.  Control: a
  ;; maintenance epoch refuses the level-1-only continuation by name and
  ;; flavor, and the run commits past the refusal.
  (let ([interp-environment (environment-variables-copy test-environment)])
    (environment-variables-set! interp-environment #"SLOG_OPT" #"interp")
    (parameterize ([current-directory repository-root]
                   [current-environment-variables interp-environment])
      (define state (make-server-state))
      (define (run! line) (dispatch-command state line))
      (void (run! "run tests/reach.slog"))
      (void (run! "watch path level 1"))
      (define parks '())
      (define replayed-answer #f)
      (parameterize ([session-pause-hook
                      (lambda (_s line)
                        (cond
                          [(and (regexp-match? #px"\\(phase read\\)" line)
                                (regexp-match? #px"\\(cause \\(watch" line))
                           (set! parks (cons line parks))
                           (cond
                             [(= (length parks) 1) 'replay]
                             [else
                              (set! replayed-answer
                                    (string-join
                                     (hash-ref (run! "?count (path X Y)")
                                               'lines)
                                     " | "))
                              'continue])]
                          [else 'continue]))])
        (void (run! "rule (path 99 99) <-- (edge 1 2)")))
      ;; one replay: two parks, both the same iteration-0 read-phase gate
      (check-equal? (length parks) 2)
      (for ([park (in-list parks)])
        (check-regexp-match
         #px"\\(iteration 0\\) \\(phase read\\) \\(settled #f\\)[^\n]*\\(cause \\(watch \\(watch-id \"w1\"\\)\\)\\)\\)"
         park))
      ;; a replayed read has still committed nothing
      (check-regexp-match #px"6 rows match" replayed-answer)
      (check-regexp-match
       #px"7 rows match"
       (string-join (hash-ref (run! "?count (path X Y)") 'lines) " | "))
      (void (run! "dump ?(path X Y) to out/t5c-replayed.csv"))
      (void (run! ":quit"))
      ;; the same change, never replayed
      (define state2 (make-server-state))
      (define (run2! line) (dispatch-command state2 line))
      (void (run2! "run tests/reach.slog"))
      (void (run2! "rule (path 99 99) <-- (edge 1 2)"))
      (void (run2! "dump ?(path X Y) to out/t5c-plain.csv"))
      (void (run2! ":quit"))
      (check-equal? (file->string "out/t5c-replayed.csv")
                    (file->string "out/t5c-plain.csv"))
      (delete-file "out/t5c-replayed.csv")
      (delete-file "out/t5c-plain.csv")
      ;; control: a maintenance epoch is not replayable, and says why
      (define state3 (make-server-state))
      (define (run3! line) (dispatch-command state3 line))
      (void (run3! "run tests/reach.slog"))
      (void (run3! "watch path level 1"))
      (define maint-result #f)
      (parameterize ([session-pause-hook (lambda (_s _line) 'replay)])
        (set! maint-result (run3! "add edge 4 1")))
      (define maint-text (string-join (hash-ref maint-result 'lines) "\n"))
      ;; every park of the change's epochs refuses, naming that epoch's own
      ;; flavor -- the count round and the maintenance incarnation alike
      (check-regexp-match
       #px"refused: level-1-unwatchable \\(verb replay\\) \\(flavor \"(count|maint[0-9a-z]*)\"\\) \\(position iter\\)"
       maint-text)
      (check-regexp-match #px"\\(flavor \"maint1\"\\) \\(position iter\\)"
                          maint-text)
      ;; and a refused replay leaves the change itself untouched
      (check-regexp-match #px"settled" maint-text)
      (check-regexp-match #px"path \\+10" maint-text)
      (void (run3! ":quit"))))

  ;; T5 slice (c) / R4: the gate as a PLACE at the prompt (repl-ux §9.2).
  ;; With a level-1 watch armed and no embedding hook, the command that
  ;; trips the gate answers with the pause record instead of a change
  ;; summary; the operator then works the parked epoch by ordinary commands
  ;; and resolves it with commit / replay / abort.  The held command's own
  ;; summary is what `commit` finally returns.
  (let ([interp-environment (environment-variables-copy test-environment)])
    (environment-variables-set! interp-environment #"SLOG_OPT" #"interp")
    (parameterize ([current-directory repository-root]
                   [current-environment-variables interp-environment])
      ;; the resolutions are honest with nothing held
      (let ([bare (make-server-state)])
        (check-exn #px"no run is held"
                   (lambda () (dispatch-command bare "commit")))
        (check-exn #px"no run is held"
                   (lambda () (dispatch-command bare "replay"))))
      (define state (make-server-state))
      (define (run! line) (dispatch-command state line))
      (define (count-line) (string-join (hash-ref (run! "?count (path X Y)")
                                                  'lines) " | "))
      (void (run! "run tests/reach.slog"))
      (void (run! "watch path level 1"))
      (define paused (run! "rule (path 99 99) <-- (edge 1 2)"))
      (check-equal? (hash-ref paused 'kind) "paused")
      (define paused-text (string-join (hash-ref paused 'lines) "\n"))
      (check-regexp-match #px"iteration 0 · phase read" paused-text)
      (check-regexp-match #px"watch w1 · path — the change is settled but NOT committed"
                          paused-text)
      (check-regexp-match #px"commit · replay · abort" paused-text)
      (check-regexp-match #px"step \\[match\\|fire\\|emit\\|tuple\\]" paused-text)
      ;; the parked epoch is a place: queries answer committed masters
      (check-regexp-match #px"6 rows match" (count-line))
      ;; replay reruns the same read and lands in the same place
      (define replayed (run! "replay"))
      (check-equal? (hash-ref replayed 'kind) "paused")
      (define replay-text (string-join (hash-ref replayed 'lines) "\n"))
      (check-regexp-match #px"iteration 0 · phase read" replay-text)
      (check-regexp-match #px"replayed 1 time" replay-text)
      (check-regexp-match #px"6 rows match" (count-line))
      ;; commit finishes the HELD command -- its own summary returns now
      (define committed (run! "commit"))
      (check-not-equal? (hash-ref committed 'kind) "paused")
      (check-regexp-match #px"path \\+1"
                          (string-join (hash-ref committed 'lines) "\n"))
      (check-regexp-match #px"7 rows match" (count-line))
      (void (run! ":quit"))
      ;; abort discards the whole change at the gate; the session survives
      (define state2 (make-server-state))
      (define (run2! line) (dispatch-command state2 line))
      (void (run2! "run tests/reach.slog"))
      (void (run2! "watch path level 1"))
      (check-equal? (hash-ref (run2! "rule (path 98 98) <-- (edge 1 2)") 'kind)
                    "paused")
      (define aborted (run2! "abort"))
      (check-regexp-match #px"nothing was committed"
                          (string-join (hash-ref aborted 'lines) "\n"))
      (check-regexp-match
       #px"6 rows match"
       (string-join (hash-ref (run2! "?count (path X Y)") 'lines) " | "))
      (void (run2! ":quit"))))

  ;; T5 slice (c3): stepping the held read (contract §3, repl-ux §9.3).
  ;; From the gate a step REPLAYS the completed read and stops at the first
  ;; matching interpreter port -- walking the very read that produced the
  ;; candidate -- and `frames` prints the join stack there without moving.
  ;; Resuming from a step stop finishes the read, which re-engages the gate:
  ;; two distinct stops, resolved separately.  Pinned single-threaded, which
  ;; is what makes "the first matching port" a determinate place.
  (let ([step-environment (environment-variables-copy test-environment)])
    (environment-variables-set! step-environment #"SLOG_OPT" #"interp")
    (environment-variables-set! step-environment #"SLOG_THREADS" #"1")
    (parameterize ([current-directory repository-root]
                   [current-environment-variables step-environment])
      (define state (make-server-state))
      (define (run! line) (dispatch-command state line))
      (define (text result) (string-join (hash-ref result 'lines) "\n"))
      (void (run! "run tests/reach.slog"))
      (void (run! "watch path level 1"))
      (check-equal? (hash-ref (run! "rule (path 99 99) <-- (edge 1 2)") 'kind)
                    "paused")
      ;; step to the first driver tuple: a different KIND of stop at the
      ;; same run.  Drive before emit is the rule's own order, and this
      ;; fragment's single body position IS its driver (no probe level, so
      ;; no `match` port exists to stop at -- the granularity has to fit
      ;; the rule, which is exactly what the ports make visible).
      (define stepped (run! "step tuple"))
      (check-equal? (hash-ref stepped 'kind) "paused")
      (check-equal? (hash-ref stepped 'title) "Paused · step")
      (check-regexp-match #px"port drive@" (text stepped))
      (check-regexp-match #px"\\(phase read\\)|phase read" (text stepped))
      ;; frames reads the stop without resuming it
      (define frames (run! "frames"))
      (check-equal? (hash-ref frames 'kind) "frames")
      (define frame-text (text frames))
      (check-regexp-match #px"drive at r[0-9]+" frame-text)
      (check-regexp-match #px"0 drive  \\(" frame-text)
      (check-regexp-match #px"[0-9]+ frames?" frame-text)
      ;; still parked: nothing committed, and frames again is stable
      (check-regexp-match
       #px"6 rows match"
       (string-join (hash-ref (run! "?count (path X Y)") 'lines) " | "))
      (check-equal? frame-text (text (run! "frames")))
      ;; a SECOND step re-arms at a different granularity: the stop moves
      ;; to the emit port this attempt is heading for (a parked
      ;; continuation must pick up the NEW arming, not the one that
      ;; stopped it)
      (define stepped2 (run! "step emit"))
      (check-equal? (hash-ref stepped2 'kind) "paused")
      (check-equal? (hash-ref stepped2 'title) "Paused · step")
      (check-regexp-match #px"port emit@" (text stepped2))
      ;; `finish` leaves the ports behind; the next place the stepped read
      ;; reaches is the gate it was stepped out of
      (define regated (run! "finish"))
      (check-equal? (hash-ref regated 'kind) "paused")
      (check-equal? (hash-ref regated 'title) "Paused · pre-commit gate")
      ;; and committing there lands the change exactly once
      (define committed (run! "commit"))
      (check-not-equal? (hash-ref committed 'kind) "paused")
      (check-regexp-match #px"path \\+1" (text committed))
      (check-regexp-match
       #px"7 rows match"
       (string-join (hash-ref (run! "?count (path X Y)") 'lines) " | "))
      (void (run! ":quit"))))

  ;; T5 slice (d1): provenance capture and `why` (contract §4(d1), repl-ux
  ;; §9.4).  Capture is opt-in per watch, so the first thing pinned is that
  ;; the arming rides the spelling and the rebinds.  At the gate, bare `why`
  ;; explains the CANDIDATE -- the one fact no query could name, since it
  ;; lives in the send shards -- and the driving row is a premise like any
  ;; other.  A monotone re-derivation then gives a real recursive tree, cut
  ;; honestly at the depth budget.  Controls: an unarmed session and a
  ;; maintenance epoch each refuse, and say which silence it is.
  (let ([why-environment (environment-variables-copy test-environment)])
    (environment-variables-set! why-environment #"SLOG_OPT" #"interp")
    (environment-variables-set! why-environment #"SLOG_THREADS" #"1")
    (parameterize ([current-directory repository-root]
                   [current-environment-variables why-environment])
      (define state (make-server-state))
      (define (run! line) (dispatch-command state line))
      (define (text result) (string-join (hash-ref result 'lines) "\n"))
      (void (run! "run tests/reach.slog"))
      (check-regexp-match #px"· level 1 · why"
                          (text (run! "watch path level 1 why")))
      (check-regexp-match #px"· level 1 · why" (text (run! "watches")))
      ;; the gate park: `why` with no argument is the candidate's proof
      (define gate-why #f)
      (parameterize ([session-pause-hook
                      (lambda (_s line)
                        (when (and (regexp-match? #px"\\(phase read\\)" line)
                                   (regexp-match? #px"\\(cause \\(watch" line)
                                   (not gate-why))
                          (set! gate-why (run! "why")))
                        'continue)])
        (void (run! "rule (path 99 1) <-- (edge 1 2)")))
      (check-not-false gate-why)
      (define gate-text (text gate-why))
      (check-equal? (hash-ref gate-why 'kind) "proof")
      (check-regexp-match #px"\\(path 99 1\\)" gate-text)
      (check-regexp-match #px"← r[0-9]+#[0-9]+ ·" gate-text)
      ;; the DRIVER is a premise, and one the journal cannot expand: an edge
      ;; fact of the original run, so it prints as a leaf rather than a
      ;; promise
      (check-regexp-match #px"\\(edge 1 2\\)  · base" gate-text)
      (check-regexp-match #px"[0-9]+ nodes · [0-9]+ captured this event"
                          gate-text)
      ;; a monotone re-derivation of the whole program: recursion, so the
      ;; tree has real depth, and every leaf is a ground-fact rule.  The
      ;; hook drives past any gate this rerun trips -- with a level-1 watch
      ;; armed and no hook, the command would be HELD at it.
      (define (run-through! line)
        (parameterize ([session-pause-hook (lambda (_s _l) 'continue)])
          (run! line)))
      (void (run-through! "run tests/reach.slog"))
      (define deep (text (run! "why (path 1 4) depth 8")))
      (check-regexp-match #px"^\\(path 1 4\\)" deep)
      (check-regexp-match #px"  \\(path 1 3\\)" deep)
      (check-regexp-match #px"  \\(path 1 2\\)" deep)
      (check-regexp-match #px"\\(edge 3 4\\)" deep)
      (check-regexp-match #px"reach\\.slog:[0-9]+" deep)
      (check-false (regexp-match? #px"truncated" deep))
      ;; the budget is a cut, and it says so
      (define shallow (text (run! "why (path 1 4) depth 1")))
      (check-regexp-match #px"· truncated" shallow)
      (check-false (regexp-match? #px"\\(path 1 2\\)" shallow))
      ;; a fact the journal never saw is a leaf, not a lie (no path runs
      ;; backwards down the chain, so this one was never derived at all)
      (check-regexp-match #px"· no captured derivation"
                          (text (run! "why (path 4 1) depth 2")))
      ;; a variable is not a fact
      (check-exn #px"GROUND fact" (lambda () (run! "why (path X 4)")))
      ;; control: a maintenance epoch captures nothing (contract §0.1 is
      ;; monotone-only) and the refusal names that, not a missing arming
      (void (run-through! "add edge 4 5"))
      (check-regexp-match
       #px"refused: provenance-unavailable.*MONOTONE"
       (text (run! "why (path 1 5)")))
      (void (run! ":quit"))
      ;; control: nothing armed at all is the other silence
      (define plain (make-server-state))
      (void (dispatch-command plain "run tests/reach.slog"))
      (check-regexp-match
       #px"refused: provenance-unavailable.*arm a level-1 watch"
       (string-join (hash-ref (dispatch-command plain "why (path 1 4)")
                              'lines) "\n"))
      (void (dispatch-command plain ":quit"))))

  ;; T5 slice (d3): a standing break is the PRE-RUN entry into the ports.
  ;; Nothing is parked and no watch is armed: arming alone makes the run stop
  ;; at the port, where the whole stepping surface already works.  The break
  ;; then survives its own hit (a step would have disarmed), and `unbreak`
  ;; at the stop is admitted because breaks are session debugging state.
  (let ([break-environment (environment-variables-copy test-environment)])
    (environment-variables-set! break-environment #"SLOG_OPT" #"interp")
    (environment-variables-set! break-environment #"SLOG_THREADS" #"1")
    (parameterize ([current-directory repository-root]
                   [current-environment-variables break-environment])
      (define state (make-server-state))
      (define (run! line) (dispatch-command state line))
      (define (text result) (string-join (hash-ref result 'lines) "\n"))
      (void (run! "run tests/reach.slog"))
      ;; a relation break pins the writer strata: without the flip there are
      ;; no ports to stop at, and the note says so
      (define armed (run! "break path"))
      (check-equal? (hash-ref armed 'kind) "break")
      (check-regexp-match #px"pinned to the interpreter" (text armed))
      (check-regexp-match #px"b1  path · 0 hits" (text (run! "breaks")))
      ;; the very next semantic command stops AT the emit port
      (define stopped (run! "rule (path 77 7) <-- (edge 1 2)"))
      (check-equal? (hash-ref stopped 'kind) "paused")
      (check-equal? (hash-ref stopped 'title) "Paused · break b1")
      (check-regexp-match #px"port b1:emit@" (text stopped))
      ;; the stepping surface is unchanged at a break stop
      (define frames (text (run! "frames")))
      (check-regexp-match #px"emit at r[0-9]+" frames)
      (check-regexp-match #px"77 7" frames)
      (check-regexp-match #px"6 rows match"
                          (text (run! "?count (path X Y)")))
      ;; the hit is counted, and the break is still armed
      (check-regexp-match #px"b1  path · 1 hit" (text (run! "breaks")))
      (define resumed (run! "continue"))
      (check-not-equal? (hash-ref resumed 'kind) "paused")
      (check-regexp-match #px"path \\+1" (text resumed))
      ;; a rule break at a BODY POSITION, and a head pattern: both narrow
      (void (run! "unbreak b1"))
      (void (run! "break path when (path 1 _)"))
      (define narrowed (run! "run tests/reach.slog"))
      ;; ids are recycled from the registry's own count, exactly as watch
      ;; ids are: the removed b1's number is free again
      (check-equal? (hash-ref narrowed 'title) "Paused · break b1")
      (define narrow-frames (text (run! "frames")))
      (check-regexp-match #px"\\(1 " narrow-frames)
      (void (run! "unbreak b1"))
      (check-not-equal? (hash-ref (run! "continue") 'kind) "paused")
      (check-regexp-match #px"none; `break REL`" (text (run! "breaks")))
      (void (run! ":quit"))))

  ;; T5 slice (d2): `whynot` -- the failure frontier over committed state.
  ;; Per rule that can write the relation, the first body position with
  ;; nothing to match, and the count of bindings that reached it.  A fact
  ;; that IS there is answered as such (the question's premise is false),
  ;; a head that cannot unify never probes, and a relation nobody writes
  ;; says so rather than printing an empty frontier.
  (let ([why-environment (environment-variables-copy test-environment)])
    (environment-variables-set! why-environment #"SLOG_OPT" #"interp")
    (parameterize ([current-directory repository-root]
                   [current-environment-variables why-environment])
      (define state (make-server-state))
      (define (run! line) (dispatch-command state line))
      (define (text result) (string-join (hash-ref result 'lines) "\n"))
      (void (run! "run tests/reach.slog"))
      ;; 1 reaches 2,3,4 but there is no node 5: the recursive rule gets
      ;; three ways through its driver and dies on the edge
      (define missing (run! "whynot (path 1 5)"))
      (check-equal? (hash-ref missing 'kind) "proof")
      (define missing-text (text missing))
      (check-regexp-match #px"reach\\.slog:9" missing-text)
      (check-regexp-match #px"\\(edge 1 5\\)   ✗ nothing matches"
                          missing-text)
      (check-regexp-match #px"\\(path 1 V[0-9]+\\)   3 ways" missing-text)
      (check-regexp-match #px"\\(edge V[0-9]+ 5\\)   ✗ nothing matches"
                          missing-text)
      (check-regexp-match #px"2 rules can write path" missing-text)
      ;; nothing reaches 4 backwards: both rules die at their first position
      (define backwards (text (run! "whynot (path 4 1)")))
      (check-regexp-match #px"\\(edge 4 1\\)   ✗" backwards)
      (check-regexp-match #px"\\(path 4 V[0-9]+\\)   ✗" backwards)
      ;; the premise of the question can simply be false
      (check-regexp-match #px"is present — `why "
                          (text (run! "whynot (path 1 4)")))
      ;; and a relation no resident rule writes is not a frontier at all
      (check-regexp-match #px"no resident rule writes"
                          (text (run! "whynot (nosuch 1 2)")))
      (check-exn #px"GROUND fact" (lambda () (run! "whynot (path 1 X)")))
      (void (run! ":quit"))))

  ;; T5 slice (d4): the non-plain settles.  The gate's question is "does this
  ;; change genuinely appear?", and each storage kind answers it by its OWN
  ;; identity: a struct head by CONTENT (its id is not minted until intern),
  ;; a lattice key by whether the merge would move the payload.  Both cases
  ;; are pinned in BOTH directions, because a settle that only ever says yes
  ;; is not a settle -- it is a park on every write.
  (let ([settle-environment (environment-variables-copy test-environment)])
    (environment-variables-set! settle-environment #"SLOG_OPT" #"interp")
    (environment-variables-set! settle-environment #"SLOG_THREADS" #"1")
    (parameterize ([current-directory repository-root]
                   [current-environment-variables settle-environment])
      ;; --- struct: content identity, not row novelty ---------------------
      (define state (make-server-state))
      (define (run! line) (dispatch-command state line))
      (define (text result) (string-join (hash-ref result 'lines) "\n"))
      (define parks 0)
      (define (drive! line)
        (parameterize ([session-pause-hook
                        (lambda (_s l)
                          (when (and (regexp-match? #px"\\(phase read\\)" l)
                                     (regexp-match? #px"\\(cause \\(watch " l))
                            (set! parks (add1 parks)))
                          'continue)])
          (run! line)))
      (void (run! "run tests/structs.slog"))
      (void (run! "watch pair level 1"))
      ;; re-constructing content the heap already holds resolves to the
      ;; existing instance: nothing appears, so the gate must NOT engage
      (define same (drive! "rule (out (pair 1 2)) <-- (in 1 2)"))
      (check-equal? parks 0)
      (check-regexp-match #px"relation sizes: unchanged" (text same))
      ;; new content mints a new id: that IS the change
      (define fresh (drive! "rule (out (pair 7 8)) <-- (in 1 2)"))
      (check-equal? parks 1)
      (check-regexp-match #px"pair \\+1" (text fresh))
      (void (run! ":quit"))
      ;; --- lattice: the payload moves, or it does not --------------------
      (define lat (make-server-state))
      (define lat-parks 0)
      (define (lat-drive! line)
        (parameterize ([session-pause-hook
                        (lambda (_s l)
                          (when (and (regexp-match? #px"\\(phase read\\)" l)
                                     (regexp-match? #px"\\(cause \\(watch " l))
                            (set! lat-parks (add1 lat-parks)))
                          'continue)])
          (dispatch-command lat line)))
      (void (dispatch-command lat "run tests/lat_run_base.slog"))
      (void (dispatch-command lat "watch dist level 1"))
      ;; a WORSE cost for a key that already has a better one is subsumed by
      ;; the min-lattice merge: a new contribution row, but no change
      (void (lat-drive! "rule (dist 1 2 99) <-- (edge 1 2 3)"))
      (check-equal? lat-parks 0)
      ;; a better one ascends the payload -- and note the relation's SIZE
      ;; does not move, which is exactly why a lattice cannot settle by
      ;; membership the way a plain table does
      (define better (lat-drive! "rule (dist 1 2 1) <-- (edge 1 2 3)"))
      (check-equal? lat-parks 1)
      (check-regexp-match #px"relation sizes: unchanged" (text better))
      (void (dispatch-command lat ":quit")))))
