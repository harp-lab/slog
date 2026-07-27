#lang racket

;; The META file of a saved database (docs/db-compression.md §8).
;;
;; Every database directory data/<name>/ carries one META file: a single,
;; human-readable, `read`-able keyed s-expr recording how the database was
;; produced and how to reconstitute it -- its input links (the manifest), the
;; stratum range it represents, its retention target `per`, the compiler and
;; value-encoding versions that produced it, and the IDB/EDB relation
;; partition.  Loading always replays from origin (§10), so META is the recipe
;; header; the kept relation dirs are the witness/seed.
;;
;; This module is the format's single source of truth: the field set, the
;; on-disk serialisation, a loud-on-foreign reader, and the stamp helper the
;; DAG (dbtool.rkt) uses for staleness.  It is deliberately forward-compatible
;; -- META is carried as an immutable hash (symbol -> value), so a newer writer
;; may add keys an older reader simply ignores, while magic + format-version
;; still gate genuinely foreign or too-new files.

(provide slog-db-magic
         slog-db-format-version
         slog-value-encoding-version
         (struct-out db-meta-error)
         make-db-meta
         db-meta?
         db-meta-ref
         db-meta-magic
         db-meta-format-version
         db-meta-kind
         db-meta-pure-edb?
         db-meta-manifest
         db-meta-stamp
         db-meta-strata
         db-meta-per
         db-meta-rng-seed
         db-meta-value-encoding-version
         db-meta-compiler-stamp
         db-meta-env
         db-meta-fixpoint-wall-ms
         db-meta-full-store-rels
         db-meta-idb-rels
         db-meta-edb-rels
         db-meta-pinned-rels
         db-meta-boundary-bundle
         db-meta-has-boundary-bundle?
         db-meta->sexpr
         sexpr->db-meta
         write-db-meta
         read-db-meta
         db-meta-file-exists?
         current-compiler-stamp
         result-affecting-env
         compute-db-stamp
         write-prog-sexpr
         read-prog-sexpr
         prog-sexpr-exists?
         write-signature-file
         read-signature-file
         write-edited-signature-file
         read-edited-signature-file
         read-edits
         append-edit!
         db-has-edits?
         write-recipe          ; the session recipe (incremental 0.C2)
         read-recipe
         db-has-recipe?
         recipe-step?          ; ONE step grammar for recipe + edits (E1a)
         edit-step?
         recipe-digest
         steps-digest          ; the shared digest core (E1a)
         externalize-recipe-payloads   ; payload placement (0.C5)
         recipe-payload-dir)

(require "tools.rkt")            ; compiler-sources-fingerprint, call-with-atomic-output
(require "params.rkt")           ; semijoin-filters-enabled (result-affecting)
(require "catalog.rkt")          ; persisted N2 BoundaryPlan validation
(require sha)
(require racket/hash)

;; ---------------------------------------------------------------------------
;; Format constants
;; ---------------------------------------------------------------------------

;; Bump format-version on any incompatible META schema change; a reader
;; refuses a file whose format-version exceeds what it understands (§8: "reject
;; foreign files loudly").
;; v2 (2026-07-26, N4-A): the `boundary-bundle` field -- one canonical,
;; self-describing logical catalog (docs/n4-contract.md §3) carried directly
;; in META rather than a second CATALOG file, so schema restore stays a single
;; atomic metadata read.  The field is OPTIONAL at the format level (a legacy
;; root re-stamped by this build still has no exact declaration metadata to
;; offer), but when present it must validate completely, and N4 catalog /
;; attach / REPL identity operations refuse an input that lacks it.
(define slog-db-magic "SLOGDB")
(define slog-db-format-version 2)

;; The daemon's NaN-box/interner encoding version (docs/db-compression.md §9):
;; the ONE residual coupling between a stored bin db and the runtime.  A bump
;; means root EDB bins must be migrated (decode-old/encode-new) and derived
;; layers dropped-and-replayed.  Kept here on the compiler side; must move in
;; lockstep with any daemon/types.h value-encoding change.
;; v2 (2026-07-09): sentinels relocated from prim tag 7 into the s32 spare
;; payload bits (tag-1 payloads >= 2^32); interned mpz bigints (intern tag 1).
;; Hard break from v1 by design -- clear data/, regenerate (primitives.md §14.1).
(define slog-value-encoding-version 2)

;; ---------------------------------------------------------------------------
;; The META value: an immutable hash symbol -> value, with typed accessors.
;; ---------------------------------------------------------------------------

;; A db-meta is just an immutable hash; db-meta? is a structural predicate.
(define (db-meta? m)
  (and (hash? m) (immutable? m) (equal? (hash-ref m 'magic #f) slog-db-magic)))

(struct db-meta-error (message) #:transparent)
(define (meta-fail fmt . args)
  (raise (db-meta-error (apply format fmt args))))

;; Default-filled constructor.  Every field the schema defines gets a value so
;; downstream code never has to special-case a missing key; the sampling-only
;; fields (per/rng-seed/fixpoint-wall-ms) default to their per=100% meaning.
;;
;;   kind             : 'root | 'compressed | 'flat
;;   pure-edb?        : #t for a root with no deriving program (§3)
;;   manifest         : ordered list of (name stamp) input links (§7.2)
;;   stamp            : this db's content/version stamp (staleness, §7)
;;   strata           : (lo . hi) inclusive stratum-level range, or #f
;;   per              : retention target in [0,1] (1.0 = exact)
;;   rng-seed         : sample RNG seed (§4.2), 0 when per=100%
;;   value-encoding-version, compiler-stamp : replay-compatibility gates (§9,§11)
;;   env              : result-affecting env alist ((NAME . value-or-#f) ...)
;;   fixpoint-wall-ms : recorded replay cost (§13 heuristic), 0 if unknown
;;   full-store-rels  : relations forced to per=100% (nondeterministic, §5.3)
;;   idb-rels/edb-rels: the stratum-boundary partition (§6, P0.4)
;;   pinned-rels      : oracle-fed relations preserved VERBATIM (docs/smt.md
;;                      §15): written by no rule, so replay cannot re-derive
;;                      them -- stored unsampled, used as heap-trim roots,
;;                      and re-ingested (never re-queried) on load
;;   boundary-bundle  : the N4-A durable logical catalog (catalog.rkt), or #f
;;                      for a creator with no exact declaration metadata
(define (make-db-meta
         #:kind [kind 'root]
         #:pure-edb? [pure-edb? #t]
         #:manifest [manifest '()]
         #:stamp [stamp #f]
         #:strata [strata #f]
         #:per [per 1.0]
         #:rng-seed [rng-seed 0]
         #:value-encoding-version [vev slog-value-encoding-version]
         #:compiler-stamp [compiler-stamp #f]
         #:env [env (result-affecting-env)]
         #:fixpoint-wall-ms [fixpoint-wall-ms 0]
         #:full-store-rels [full-store-rels '()]
         #:idb-rels [idb-rels '()]
         #:edb-rels [edb-rels '()]
         #:pinned-rels [pinned-rels '()]
         #:boundary-bundle [boundary-bundle #f]
         #:extra [extra '()])          ; extra ((key . value) ...) for forward-compat
  (when boundary-bundle
    (unless (boundary-bundle-datum? boundary-bundle)
      (meta-fail "refusing to write an invalid boundary bundle into META")))
  (define base
    (hash 'magic slog-db-magic
          'format-version slog-db-format-version
          'endianness 'little
          'kind kind
          'pure-edb? pure-edb?
          'manifest manifest
          'stamp stamp
          'strata strata
          'per per
          'rng-seed rng-seed
          'value-encoding-version vev
          'compiler-stamp compiler-stamp
          'env env
          'fixpoint-wall-ms fixpoint-wall-ms
          'full-store-rels full-store-rels
          'idb-rels idb-rels
          'edb-rels edb-rels
          'pinned-rels pinned-rels))
  (define with-bundle
    (if boundary-bundle (hash-set base 'boundary-bundle boundary-bundle) base))
  (for/fold ([m with-bundle]) ([kv (in-list extra)])
    (hash-set m (car kv) (cdr kv))))

(define (db-meta-ref m key [default #f]) (hash-ref m key default))

(define (db-meta-magic m) (db-meta-ref m 'magic))
(define (db-meta-format-version m) (db-meta-ref m 'format-version))
(define (db-meta-kind m) (db-meta-ref m 'kind))
(define (db-meta-pure-edb? m) (db-meta-ref m 'pure-edb?))
(define (db-meta-manifest m) (db-meta-ref m 'manifest '()))
(define (db-meta-stamp m) (db-meta-ref m 'stamp))
(define (db-meta-strata m) (db-meta-ref m 'strata))
(define (db-meta-per m) (db-meta-ref m 'per 1.0))
(define (db-meta-rng-seed m) (db-meta-ref m 'rng-seed 0))
(define (db-meta-value-encoding-version m) (db-meta-ref m 'value-encoding-version))
(define (db-meta-compiler-stamp m) (db-meta-ref m 'compiler-stamp))
(define (db-meta-env m) (db-meta-ref m 'env '()))
(define (db-meta-fixpoint-wall-ms m) (db-meta-ref m 'fixpoint-wall-ms 0))
(define (db-meta-full-store-rels m) (db-meta-ref m 'full-store-rels '()))
(define (db-meta-idb-rels m) (db-meta-ref m 'idb-rels '()))
(define (db-meta-edb-rels m) (db-meta-ref m 'edb-rels '()))
(define (db-meta-pinned-rels m) (db-meta-ref m 'pinned-rels '()))
(define (db-meta-boundary-bundle m) (db-meta-ref m 'boundary-bundle #f))
(define (db-meta-has-boundary-bundle? m)
  (and (db-meta-boundary-bundle m) #t))

;; ---------------------------------------------------------------------------
;; Serialisation.  A META file is a single top-level form:
;;   (slog-db-meta (key value) (key value) ...)
;; keys are sorted for a stable, diffable on-disk order.
;; ---------------------------------------------------------------------------

(define (db-meta->sexpr m)
  `(slog-db-meta
    ,@(for/list ([key (in-list (sort (hash-keys m) symbol<?))])
        (list key (hash-ref m key)))))

(define (sexpr->db-meta s)
  (match s
    [`(slog-db-meta ,pairs ...)
     (define m
       (for/fold ([h (hash)]) ([p (in-list pairs)])
         (match p
           [(list (? symbol? key) value) (hash-set h key value)]
           [_ (meta-fail "malformed META entry: ~s" p)])))
     ;; Gate foreign / too-new files loudly (§8).
     (define magic (hash-ref m 'magic #f))
     (unless (equal? magic slog-db-magic)
       (meta-fail "not a slog database META (magic ~s, expected ~s)"
                  magic slog-db-magic))
     (define fv (hash-ref m 'format-version 0))
     (unless (and (exact-nonnegative-integer? fv) (<= fv slog-db-format-version))
       (meta-fail "META format-version ~s is newer than this build understands (~s)"
                  fv slog-db-format-version))
     ;; N4-A: the bundle is optional, but a PRESENT one is authoritative --
     ;; a malformed, internally inconsistent, or unsupported bundle fails the
     ;; whole read, before any caller can touch daemon state with it.
     (define bundle (hash-ref m 'boundary-bundle #f))
     (when (and bundle (not (boundary-bundle-datum? bundle)))
       (meta-fail "META carries a malformed or inconsistent boundary bundle"))
     m]
    [_ (meta-fail "not a slog-db-meta s-expr: ~s" s)]))

;; The path of a directory's META file.  db-dir may be a "data/<name>" name,
;; a "data/<name>/" path, or any directory path.
(define (meta-path db-dir)
  (build-path db-dir "META"))

(define (db-meta-file-exists? db-dir)
  (file-exists? (meta-path db-dir)))

;; Write META atomically into db-dir (which must already exist).  Uses
;; call-with-atomic-output (tools.rkt) so a crashed write never leaves a
;; truncated META that would fail the reader.
(define (write-db-meta m db-dir)
  (define path (meta-path db-dir))
  (call-with-atomic-output
   (path->string path)
   (lambda ()
     (parameterize ([print-graph #f])
       (pretty-write (db-meta->sexpr m))))))

;; Read + validate META from db-dir.  Raises db-meta-error on a missing,
;; unreadable, foreign, or too-new file.
(define (read-db-meta db-dir)
  (define path (meta-path db-dir))
  (unless (file-exists? path)
    (meta-fail "no META in ~a" db-dir))
  (define s
    (with-handlers ([exn:fail? (lambda (e) (meta-fail "cannot read META in ~a: ~a"
                                                       db-dir (exn-message e)))])
      (call-with-input-file path read)))
  (sexpr->db-meta s))

;; ---------------------------------------------------------------------------
;; Stamps
;; ---------------------------------------------------------------------------

;; A short, stable hash of the whole-compiler source fingerprint -- the
;; compiler-stamp recorded in META for drift attribution (§11).  We hash the
;; (large) concatenated-source fingerprint down to 16 hex chars; two builds
;; agree iff every compiler .rkt is byte-identical.
(define (current-compiler-stamp)
  (substring (bytes->hex-string
              (sha256 (string->bytes/utf-8 compiler-sources-fingerprint)))
             0 16))

;; The result-affecting environment captured into META so a replay recompiles
;; faithfully (§8 `env`).  Only vars that can change the logical result belong
;; here (SLOG_NO_SEMIJOIN flips the plan but not the result today, yet it is in
;; the .so cache key, so we record it for a faithful rebuild); perf-only vars
;; (SLOG_OPT, SLOG_MEM_*) are deliberately excluded.
(define (result-affecting-env)
  (list (cons 'SLOG_NO_SEMIJOIN (getenv "SLOG_NO_SEMIJOIN"))))

;; Cheap per-relation directory digest: sorted (entry-name . total-bytes) over
;; a db directory's relation/interner subdirs, excluding META itself.  Used to
;; fold actual on-disk content into a root's stamp (a root has no program, so
;; its identity IS its data).  This is a P0 proxy -- change-sensitive to any
;; size change; P1's content signature (§8) supersedes it for exact identity.
(define (dir-content-digest db-dir)
  (define d (if (directory-exists? db-dir) db-dir #f))
  (cond
    [(not d) '()]
    [else
     (for/list ([entry (in-list (sort (map path->string (directory-list d)) string<?))]
                #:unless (equal? entry "META"))
       (define p (build-path d entry))
       (cons entry (dir-or-file-bytes p)))]))

(define (dir-or-file-bytes p)
  (cond
    [(directory-exists? p)
     (for/sum ([f (in-directory p)] #:when (file-exists? f)) (file-size f))]
    [(file-exists? p) (file-size p)]
    [else 0]))

;; ---------------------------------------------------------------------------
;; prog.sexpr -- the stored program source (docs/db-compression.md §9, P1.1)
;; ---------------------------------------------------------------------------
;;
;; One self-contained s-expr capturing the entry path plus the raw source of
;; every file in the transitive include/run closure, keyed by canonical path
;; (parser.rkt source-key).  Recompiled under the CURRENT compiler on load, so
;; compiler changes are observed and drift is caught -- see §9.

(define (prog-path db-dir) (build-path db-dir "prog.sexpr"))
(define (prog-sexpr-exists? db-dir) (file-exists? (prog-path db-dir)))

;; sources : hash (canonical-path-string -> source-text).  Written sorted for a
;; stable, diffable file.
(define (write-prog-sexpr db-dir entry sources)
  (define sexpr
    `(slog-prog
      (entry ,entry)
      (sources
       ,@(for/list ([k (in-list (sort (hash-keys sources) string<?))])
           (list k (hash-ref sources k))))))
  (call-with-atomic-output
   (path->string (prog-path db-dir))
   (lambda () (parameterize ([print-graph #f]) (write sexpr)))))

;; Returns (cons entry sources-hash), or #f when the db has no stored program.
(define (read-prog-sexpr db-dir)
  (define path (prog-path db-dir))
  (cond
    [(not (file-exists? path)) #f]
    [else
     (match (call-with-input-file path read)
       [`(slog-prog (entry ,entry) (sources ,pairs ...))
        (cons entry
              (for/fold ([h (hash)]) ([p (in-list pairs)])
                (match p
                  [(list (? string? k) (? string? v)) (hash-set h k v)]
                  [_ (meta-fail "malformed prog.sexpr source entry: ~s" p)])))]
       [other (meta-fail "malformed prog.sexpr in ~a: ~s" db-dir other)])]))

;; ---------------------------------------------------------------------------
;; recipe -- the session's pipeline steps + anchored batches
;; (docs/incremental.md §0.10, 0.C2; step grammar unified with `edits`
;; per E1a, 2026-07-11).
;; ---------------------------------------------------------------------------
;;
;; A session = an ordered list of steps plus signed batches anchored at
;; (relation, version-ordinal) -- ordinals, never raw pipeline positions,
;; so the anchors survive recompiles (§0.4).  ONE step grammar serves both
;; the recipe and the `edits` file (an edits file is a recipe FRAGMENT
;; attached to an existing layer -- same spellings, same applier, same
;; digest core):
;;   (slog-recipe
;;     (open DB)
;;     (run PROG)
;;     (run PROG (version-events TABLE ...)
;;               (boundary-plans PLAN ...)
;;               (module-instances GROUP ...)) ; N1/N2 self-auditing form
;;     (import-delta DIR ((X Z) ...))        ; DIR may be (delta k) post-
;;                                           ;   externalisation (0.C5)
;;     (link DB ((X Z) ...))                 ; reference, never copied (0.D5)
;;     (rename-rel R S) | (drop-rel R)       ; legacy environment ops (0.D1)
;;     (rename-path R S (transform-plan ...))  ; N3-D planned transforms --
;;     (drop-path R (transform-plan ...))       ;   subtree-atomic, replayed
;;                                              ;   against the catalog head
;;     (add-tuple REL v ...) | (del-tuple REL v ...)   ; inline single-tuple
;;                                           ;   steps, anchored at entry --
;;                                           ;   the degenerate batch (§0.2)
;;     (batch REL (v ORD) ((v ...) ...) ((v ...) ...)) ; adds, dels
;;     ...)
;; The batch entries are the COLLAPSED log (§0.2): same-point add/delete
;; pairs are already absent.  Consumed by 0.E's delta-layer save/load;
;; produced live by compiler/session.rkt's session-recipe.

;; The shared step grammar.  `recipe-step?` admits every session event;
;; `edit-step?` is the mutation subset an `edits` fragment may contain
;; (opening a db or running a segment inside an ancestor's edit appendix
;; makes no sense -- those are layer-level recipe steps).
(define (recipe-step? st)
  (define (version-table? table)
    (and (list? table)
         (for/and ([entry (in-list table)])
           (match entry
             [`(,(? symbol?) ,(? string?)) #t]
             [_ #f]))))
  (define (module-group? group)
    (match group
      [`(program-modules
         (program ,(? string?))
         ,(? module-instance-descriptor-datum?) ...)
       #t]
      [_ #f]))
  (match st
    [`(open ,(? string?)) #t]
    [`(run ,_) #t]
    [`(run ,_
           (version-events ,tables ...)
           (boundary-plans ,plans ...)
           (module-instances ,module-groups ...))
     (and (= (length tables) (length plans) (length module-groups))
          (andmap version-table? tables)
          (andmap boundary-plan-datum? plans)
          (andmap module-group? module-groups))]
    [`(run ,_
           (version-events ,tables ...)
           (boundary-plans ,plans ...))
     (and (= (length tables) (length plans))
          (andmap version-table? tables)
          (andmap boundary-plan-datum? plans))]
    [`(run ,_ (version-events ,tables ...))
     (andmap version-table? tables)]
    [_ (edit-step? st)]))

(define (edit-step? st)
  (define (rename-map? rs)
    (and (list? rs)
         (for/and ([r (in-list rs)])
           (match r [(list _ _) #t] [_ #f]))))
  (match st
    [`(import-delta ,(or (? string?) `(delta ,(? exact-nonnegative-integer?)))
                    ,(? rename-map?)) #t]
    [`(link ,(? string?) ,(? rename-map?)) #t]
    [`(rename-rel ,(? symbol?) ,(? symbol?)) #t]
    [`(drop-rel ,(? symbol?)) #t]
    ;; N3-D planned transforms: the step retains its self-auditing plan so
    ;; replay revalidates the exact minted BoundaryKey (catalog.rkt).
    [`(rename-path ,(? symbol?) ,(? symbol?) ,(? transform-plan-datum?)) #t]
    [`(drop-path ,(? symbol?) ,(? transform-plan-datum?)) #t]
    ;; N4-B attachment: the step carries its self-auditing plan, so replay
    ;; recomputes the whole mapping and refuses any source or destination
    ;; drift rather than re-deriving a fresh one (n4-contract.md §5).
    [`(attach ,(? string?) ,(? attachment-plan-datum?)) #t]
    [`(inject-version ,(? symbol?) ,(? string?)) #t]
    [`(add-tuple ,(? symbol?) ,_ ...) #t]
    [`(del-tuple ,(? symbol?) ,_ ...) #t]
    [`(batch ,(? symbol?) (v ,(? exact-nonnegative-integer?)) ,(? list?) ,(? list?)) #t]
    [`(overlay ,(? symbol?) (v ,(? exact-nonnegative-integer?)) ,rows)
     (and (list? rows)
          (for/and ([row (in-list rows)])
            (match row
              [`(,(or 'direct 'mask 'none) ,(? list?)) #t]
              [_ #f])))]
    [`(overlay ,(? symbol?) (key ,(? string?))
               (v ,(? exact-nonnegative-integer?)) ,rows)
     (and (list? rows)
          (for/and ([row (in-list rows)])
            (match row
              [`(,(or 'direct 'mask 'none) ,(? list?)) #t]
              [_ #f])))]
    [_ #f]))

(define (recipe-path db-dir) (build-path db-dir "recipe"))
(define (db-has-recipe? db-dir) (file-exists? (recipe-path db-dir)))

(define (write-recipe db-dir recipe)
  (match recipe
    [`(slog-recipe ,steps ...)
     (for ([st (in-list steps)])
       (unless (recipe-step? st)
         (meta-fail "unknown recipe step (grammar in dbmeta.rkt): ~s" st)))]
    [other (meta-fail "not a recipe: ~s" other)])
  (call-with-atomic-output
   (path->string (recipe-path db-dir))
   (lambda () (parameterize ([print-graph #f]) (write recipe)))))

(define (read-recipe db-dir)
  (define path (recipe-path db-dir))
  (cond
    [(not (file-exists? path)) #f]
    [else
     (match (call-with-input-file path read)
       [(and r `(slog-recipe ,_ ...)) r]
       [other (meta-fail "malformed recipe in ~a: ~s" db-dir other)])]))

;; THE digest core, shared by every step-list digest (E1a: one digest
;; mechanism): covers step order, anchors, and inline payloads verbatim; a
;; bin payload (import-delta) contributes its directory's content digest
;; (names + bytes, the root-stamp machinery) so editing a payload in place
;; surfaces as a digest change, with the bare path as the fallback for an
;; unreadable/absent directory.  Used by recipe-digest here and by
;; dbtool.rkt's db-chain-edits-digest (which digests a whole chain's load
;; plan, inline edit steps included).
(define (steps-digest steps)
  (define resolved
    (for/list ([st (in-list steps)])
      (match st
        [`(import-delta ,dir ,renames)
         `(import-delta ,(with-handlers ([exn:fail? (lambda (_) dir)])
                           (dir-content-digest dir))
                        ,renames)]
        [_ st])))
  (substring (bytes->hex-string
              (sha256 (string->bytes/utf-8 (format "~s" resolved))))
             0 16))

;; Digest of a recipe's semantic content (the db-chain-edits-digest of the
;; session world).
(define (recipe-digest recipe)
  (match-define `(slog-recipe ,steps ...) recipe)
  (steps-digest steps))

;; Payload placement (0.C5): copy each import-delta payload database into
;; the saving layer's delta.<k>/ and rewrite its step to the RELATIVE
;; reference (import-delta (delta k) renames) -- the layer owns its
;; payloads (ancestors immutable, the chain self-contained); the load side
;; (0.E2) joins the layer dir back on when replaying.  Returns the
;; rewritten recipe; k assignment is step-ordered, so re-externalising a
;; regenerated session is deterministic.
(define (externalize-recipe-payloads recipe layer-dir)
  (match-define `(slog-recipe ,steps ...) recipe)
  (define k (box 0))
  `(slog-recipe
    ,@(for/list ([st (in-list steps)])
        (match st
          [`(import-delta ,(? string? dir) ,renames)
           (define i (unbox k))
           (set-box! k (add1 i))
           (define dst (build-path layer-dir (format "delta.~a" i)))
           (when (directory-exists? dst) (delete-directory/files dst))
           (copy-directory/files dir dst)
           `(import-delta (delta ,i) ,renames)]
          [_ st]))))

;; The load-side inverse: resolve a step's (delta k) payload reference
;; against its layer directory.
(define (recipe-payload-dir layer-dir ref)
  (match ref
    [`(delta ,k) (path->string (build-path layer-dir (format "delta.~a" k)))]
    [(? string? dir) dir]))

;; ---------------------------------------------------------------------------
;; edits -- ordered EDB mutations applied at a layer's boundary on load (§12).
;; ---------------------------------------------------------------------------
;;
;; The forward-incremental hook: an input-leaf relation can be edited (e.g.
;; `(add-tuple edge 4 5)`) and the change propagates downstream by re-replay,
;; because loading always recomputes from origin.  Stored as
;;   (slog-edits (add-tuple REL v ...) ...)

(define (edits-path db-dir) (build-path db-dir "edits"))
(define (db-has-edits? db-dir) (file-exists? (edits-path db-dir)))

(define (read-edits db-dir)
  (define path (edits-path db-dir))
  (cond
    [(not (file-exists? path)) '()]
    [else
     (match (call-with-input-file path read)
       [`(slog-edits ,ops ...) ops]
       [other (meta-fail "malformed edits in ~a: ~s" db-dir other)])]))

(define (append-edit! db-dir op)
  ;; One grammar with the recipe (E1a): an edits file is a recipe fragment,
  ;; restricted to the mutation subset -- reject anything else here rather
  ;; than let a second vocabulary grow.
  (unless (edit-step? op)
    (meta-fail "not an edit step (grammar in dbmeta.rkt): ~s" op))
  (define ops (append (read-edits db-dir) (list op)))
  (call-with-atomic-output
   (path->string (edits-path db-dir))
   (lambda () (parameterize ([print-graph #f]) (write `(slog-edits ,@ops))))))

;; ---------------------------------------------------------------------------
;; signature -- the full-coverage content witness (docs/db-compression.md §8/§11)
;; ---------------------------------------------------------------------------
;;
;; A hash (relation-name-symbol -> (count . checksum-hex-string)) over the FULL
;; IDB at save (before sampling).  On load, the replayed IDB's signature must
;; match; a mismatch is drift (compiler change, nondeterminism, or a bug).

(define (sig-path db-dir) (build-path db-dir "signature"))

(define (write-signature-file db-dir sig)
  (define sexpr
    `(slog-signature
      ,@(for/list ([k (in-list (sort (hash-keys sig) symbol<?))])
          (match-define (cons count checksum) (hash-ref sig k))
          (list k count checksum))))
  (call-with-atomic-output
   (path->string (sig-path db-dir))
   (lambda () (parameterize ([print-graph #f]) (write sexpr)))))

;; Returns the signature hash, or #f if the db has none.
(define (read-signature-file db-dir)
  (define path (sig-path db-dir))
  (cond
    [(not (file-exists? path)) #f]
    [else
     (match (call-with-input-file path read)
       [`(slog-signature ,rows ...)
        (for/fold ([h (hash)]) ([r (in-list rows)])
          (match r
            [(list (? symbol? k) (? exact-nonnegative-integer? count) (? string? checksum))
             (hash-set h k (cons count checksum))]
            [_ (meta-fail "malformed signature row: ~s" r)]))]
       [other (meta-fail "malformed signature in ~a: ~s" db-dir other)])]))

;; signature.edited -- the drift baseline for an EDITED chain (§11/§12).  An
;; edit legitimately changes content, so the save-time `signature` no longer
;; applies.  Instead of skipping verification entirely (the pre-P2.1 behaviour
;; -- an observability hole), the first load after a new edit RE-BASELINES:
;; it stores the freshly replayed signature keyed by a digest of the chain's
;; whole edit recipe (dbtool.rkt db-chain-edits-digest).  Later loads verify
;; against it as usual; a further edit anywhere in the chain changes the
;; digest and forces a fresh re-baseline (one unverified load per edit).

(define (edited-sig-path db-dir) (build-path db-dir "signature.edited"))

(define (write-edited-signature-file db-dir digest sig)
  (define sexpr
    `(slog-signature-edited
      (edits-digest ,digest)
      ,@(for/list ([k (in-list (sort (hash-keys sig) symbol<?))])
          (match-define (cons count checksum) (hash-ref sig k))
          (list k count checksum))))
  (call-with-atomic-output
   (path->string (edited-sig-path db-dir))
   (lambda () (parameterize ([print-graph #f]) (write sexpr)))))

;; Returns (cons edits-digest sig-hash), or #f when no baseline is stored.
(define (read-edited-signature-file db-dir)
  (define path (edited-sig-path db-dir))
  (cond
    [(not (file-exists? path)) #f]
    [else
     (match (call-with-input-file path read)
       [`(slog-signature-edited (edits-digest ,(? string? digest)) ,rows ...)
        (cons digest
              (for/fold ([h (hash)]) ([r (in-list rows)])
                (match r
                  [(list (? symbol? k) (? exact-nonnegative-integer? count) (? string? checksum))
                   (hash-set h k (cons count checksum))]
                  [_ (meta-fail "malformed signature.edited row: ~s" r)])))]
       [other (meta-fail "malformed signature.edited in ~a: ~s" db-dir other)])]))

;; Compute a database's content/version stamp (§7): a short hash over its
;; identity -- input links, retention, stratum range, compiler + encoding
;; versions, a program fingerprint (or 'none for a root), and (for roots) a
;; directory content digest so a root's stamp tracks its actual EDB.  Derived
;; layers are determined by (program + inputs + compiler), so hashing those is
;; sufficient without re-reading their data.
(define (compute-db-stamp m
                          #:prog-fingerprint [prog-fp 'none]
                          #:db-dir [db-dir #f])
  (define identity
    (list 'slog-db-stamp
          (db-meta-magic m)
          (db-meta-format-version m)
          (db-meta-manifest m)
          (db-meta-per m)
          (db-meta-strata m)
          (db-meta-compiler-stamp m)
          (db-meta-value-encoding-version m)
          (db-meta-env m)
          prog-fp
          ;; N4-A: the logical catalog is part of a database's identity, so a
          ;; tampered or swapped bundle changes the stamp like any other
          ;; identity field.
          (db-meta-boundary-bundle m)
          (if (and db-dir (db-meta-pure-edb? m)) (dir-content-digest db-dir) 'derived)))
  (substring (bytes->hex-string
              (sha256 (string->bytes/utf-8 (format "~s" identity))))
             0 16))
