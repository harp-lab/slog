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
         db-has-edits?)

(require "tools.rkt")            ; compiler-sources-fingerprint, call-with-atomic-output
(require "params.rkt")           ; semijoin-filters-enabled (result-affecting)
(require sha)
(require racket/hash)

;; ---------------------------------------------------------------------------
;; Format constants
;; ---------------------------------------------------------------------------

;; Bump format-version on any incompatible META schema change; a reader
;; refuses a file whose format-version exceeds what it understands (§8: "reject
;; foreign files loudly").
(define slog-db-magic "SLOGDB")
(define slog-db-format-version 1)

;; The daemon's NaN-box/interner encoding version (docs/db-compression.md §9):
;; the ONE residual coupling between a stored bin db and the runtime.  A bump
;; means root EDB bins must be migrated (decode-old/encode-new) and derived
;; layers dropped-and-replayed.  Kept here on the compiler side; must move in
;; lockstep with any daemon/types.h value-encoding change.
(define slog-value-encoding-version 1)

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
         #:extra [extra '()])          ; extra ((key . value) ...) for forward-compat
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
          'edb-rels edb-rels))
  (for/fold ([m base]) ([kv (in-list extra)])
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
          (if (and db-dir (db-meta-pure-edb? m)) (dir-content-digest db-dir) 'derived)))
  (substring (bytes->hex-string
              (sha256 (string->bytes/utf-8 (format "~s" identity))))
             0 16))
