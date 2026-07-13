#lang racket

;; C++ emission: render a c-program (ir-stack.rkt) as the source of one
;; stratum plugin -- a shared object whose slog_plugin(slog::Daemon*) builds
;; the stratum's object representation, pushes it onto the daemon's
;; pipeline, and runs the pipeline forward (daemon/daemon.h).
;;
;; Each relation declaration becomes addRelation/addStruct plus, per index,
;; an addIndex call and per-bucket generic write tasks, and per relation a
;; per-bucket intern task (daemon/operators.h) -- no per-relation classes.
;;
;; Each crule becomes one Task class whose work() is a chain of nested push
;; operators (operators.h), each taking the rest of the pipeline as a
;; continuation lambda.  Bound variables flow as nested-scope locals; the
;; whole chain fuses into one loop at -O2.  A `return` inside a continuation
;; abandons the current tuple (the old codegen's `continue`).
;;
;; Task scheduling: a rule whose driver reads a relation that grows during
;; this stratum re-runs every iteration; a rule over closed relations (and
;; every fact rule) runs once, at program start, over the freshly (re)loaded
;; database whose entire contents form iteration zero's delta.

(provide write-cpp)

(require "utils.rkt")
(require "params.rkt")
(require "ir-shared.rkt")
(require "ir-stack.rkt")
(require (only-in "type-system.rkt" prim-error-arms))  ; counted-head arms (_count)
(require sha)   ; content-hashed cluster names + stable bucketing (P2)

(define (repeat s n)
  (if (= n 0)
      ""
      (string-append s (repeat s (- n 1)))))

;; ---- deterministic emit-local names + value-ref canonicalization (P2) -------
;; For the per-.o cache (docs/fast-compile.md P2) a translation unit's generated
;; text must be a pure function of its rules -- byte-reproducible across runs --
;; so its .o can be content-addressed and reused.  Two sources of run-to-run
;; noise are removed:
;;  (1) emit-local names.  The C++ locals emit mints (index orderings, ReadTask
;;      classes, temp vars) were (gensymb ...), whose random suffix + global
;;      counter varied every run.  `elocal` replaces them with a per-TU
;;      monotonic counter (reset per translation unit in write-cpp): same rules
;;      -> same names.  Monotonic within a TU (never per-rule) so two rules'
;;      locals cannot collide in a shared C++ scope.
;;  (2) value-var references.  Every value flows as `v_<name>`, and the <name>s
;;      carried in from earlier passes are gensym'd (run-varying).  Nothing else
;;      in the emitted code begins with `v_`, and the interned-constant globals
;;      (the ONLY cross-TU value symbols) have content-derived names, so
;;      `canonicalize-vrefs` renames every OTHER `v_<name>` to `v_c<k>` in
;;      first-occurrence order, leaving the constant globals (given) untouched.
(define emit-local-counter (make-parameter (box 0)))
(define (elocal prefix-sym)
  (define b (emit-local-counter))
  (define n (unbox b))
  (set-box! b (add1 n))
  (string->symbol (string-append (symbol->string prefix-sym) (number->string n))))

;; `keep-names` are daemon-registered NAMES (relations/structs/lattices/temps)
;; that occur as STRING LITERALS in getRelation/addRelation/addStruct/... .  A
;; name beginning with `v_` (e.g. a user table `v_maybelist`) matches the
;; value-ref regex, so without protection it would be renumbered to a per-TU
;; `v_cN` -- and since numbering restarts per TU, a split stratum's spine would
;; addRelation one name while a cluster getRelation's a different one, yielding a
;; null Relation* and a segfault binding the read task's index at stratum load.
;; Kept verbatim, these names stay identical across TUs (they are already
;; deterministic, so this does not reintroduce run-variance).
(define (canonicalize-vrefs text const-names keep-names)
  (define keep (list->set (append (map (lambda (g) (format "v_~a" g)) const-names)
                                  keep-names)))
  (define seen (make-hash))
  (define counter (box 0))
  (regexp-replace* #px"\\bv_[A-Za-z0-9_]+" text
    (lambda (tok)
      (cond
        [(set-member? keep tok) tok]
        [(hash-ref seen tok #f) => values]
        [else
         (define c (format "v_c~a" (unbox counter)))
         (set-box! counter (add1 (unbox counter)))
         (hash-set! seen tok c)
         c]))))

;; ---- content-hashed clusters + stable bucketing (P2 Phase 3) ----------------
;; A large stratum's rules are partitioned into clusters compiled to
;; content-addressed .o's (tools.rkt) and linked into one .so.  Two requirements:
;;  * a cluster's emitted text is a pure function of ITS rules (naming it by that
;;    text's hash lets an unchanged cluster's .o be reused across stratum
;;    versions / configs / edits); and
;;  * the rule->cluster assignment is STABLE under unrelated edits, so a one-rule
;;    change re-hashes only its own cluster(s), not all of them.
;; Full-line `//` debug comments carry gensym'd crule renderings that vary run to
;; run but do not affect the compiled .o, so they are stripped before hashing.
(define (strip-line-comments text)
  (regexp-replace* #px"(?m:^[ \t]*//[^\n]*\n)" text ""))
(define (content-hash text)
  (substring (bytes->hex-string (sha256 (string->bytes/utf-8 (strip-line-comments text)))) 0 16))
(define (next-pow2 n) (let loop ([p 1]) (if (>= p n) p (loop (* p 2)))))

;; Render a primitive call: _prim_NAME(db, v_a0, ...) -- nullary primitives
;; (the lattice constants (one)/(inf)/(top)) take only db.
(define (prim-call f args)
  (define al (string-join (map (lambda (a) (format "v_~a" a)) args) ", "))
  (format "_prim_~a(db~a)" f (if (string=? al "") "" (string-append ", " al))))

;; The reporting location ("file:line") of the crule currently being emitted,
;; baked into any runtime-error (error_spec ...) it reports.  Bound per crule in
;; add-rule.
(define current-rule-loc (make-parameter "<unknown>"))

;; The counting classification of the crule currently being emitted (the
;; _count flavor, docs/incremental.md §8B.1): #f outside the flavor, else
;; 'input | 'nonrec | 'rec.  Bound per crule in add-rule; selects the
;; counting sinks and which sidecar counter their batches bump.
(define current-rule-kind (make-parameter #f))

(define (cnt-kind-cpp kind) (format "slog::cnt_kind_~a" kind))

;; unkeyed-scan warnings already issued this compile, keyed (loc . relation)
;; -- one per site, not one per delta variant
(define warned-scans (mutable-set))

;; A fallible prim returns slog_error on bad data (div/mod by 0, INT_MIN, NaN,
;; toint out of range, an any-typed type mismatch).  This is the check emitted
;; right after such a call: record the pending (error_spec ...) for this rule and
;; abandon the deduction.  `ret` is the abandon statement for the context
;; ("return;" for a body/head op, "return true;" for a pre-op that aborts the
;; whole task).  Emitted as one line (valid C++; whitespace is insignificant).
(define (prim-error-check var ret)
  (define k (current-rule-kind))
  (format "if (v_~a == slog_error) { slog::emit_pending_error~a(db, \"~a\"~a); ~a }"
          var (if k "_count" "")
          (escape-c-string-literal (current-rule-loc))
          (if k (string-append ", " (cnt-kind-cpp k)) "")
          ret))

;; A PARTIAL prim call (a letp c-op): the runtime convention (prims.h) is a
;; trailing `bool* ok` parameter -- absent data sets *ok = false and the row is
;; abandoned with `ret`, the same return-semantics cmp guards have.  Absence is
;; not an error: no error fact, just a failed match against a virtual relation.
(define (partial-prim-call x f args ret)
  (define ok (elocal 'ok))
  (define al (string-join (map (lambda (a) (format "v_~a" a)) args) ", "))
  (string-append
   (format "bool ~a = true;\n" ok)
   (format "u64 v_~a = _prim_~a(db~a, &~a);\n"
           x f (if (string=? al "") "" (string-append ", " al)) ok)
   (format "if (!~a) ~a" ok ret)))

;; The spec-aware pointwise join (a cjoin c-op, docs/finish-collections.md
;; §D): parse the baked spec token ONCE per call site into a function-local
;; static (magic-statics init is thread-safe, and the per-bucket instances
;; of one rule share the site), then join the two payload words under it.
;; merge_spec tag-checks its collection operands and fatals on a mistyped
;; word -- the cplus contract, not the row-abandon channel.
(define (cjoin-call x spec a b)
  (define sv (elocal 'spec))
  (string-append
   (format "static const slog::LatSpec* ~a = slog::parseLatSpecToken(\"~a\");\n"
           sv (lat-spec-token spec))
   (format "if (~a == nullptr) slog::fatal(\"cjoin: malformed spec token\");\n" sv)
   (format "u64 v_~a = db->collections()->merge_spec(v_~a, v_~a, ~a);" x a b sv)))

(define ((emit-lines ind) . lines)
  (define ind-str
    (if debug-mode
        (repeat " " ind)
        ""))
  (foldl (lambda (ln acc)
           (string-append acc
                          ind-str
                          (if debug-mode
                              (string-replace ln "\n" (string-append "\n" ind-str))
                              ln)
                          "\n"))
         ""
         lines))

(define (u64-array-lit vals)
  (format "std::array<u64,~a>{~a}" (length vals) (string-join (map ~a vals) ", ")))

(define (u16-array-lit vals)
  (format "std::array<u16,~a>{~a}" (length vals) (string-join (map ~a vals) ", ")))

(define (add-ord-decl ordname ind [indent 0])
  (string-append (repeat " " indent)
                 (format "std::vector<u16> ~a({~a});\n"
                         ordname
                         (string-join (map ~a ind) ", "))))

;; -----------------------------------------------------------------------
;; Relation declarations: index creation + write-phase tasks.  The first
;; non-delta index's write tasks run once (they ingest the initial delta;
;; from then on the intern phase maintains that index); the rest run every
;; iteration.

(define (add-write-task name arity indices is-struct)
  ((emit-lines 2)
   (format "r = db->getRelation(\"~a\");" name)
   (format "if (r == 0) db->add~a(\"~a\", ~a);" (if is-struct 'Struct 'Relation) name arity)
   (format "else if (r->getArity() != ~a)" arity)
   "  slog::fatal(\"Relation already exists at incorrect arity.\");"
   ;; Re-fetch: if it was just created above, the local r still holds 0.
   (format "r = db->getRelation(\"~a\");" name)
   (apply
    (emit-lines 2)
    (for/fold ([lines '()] #:result (reverse lines))
              ([indx (in-list indices)])
      (define delta (eq? 'delta (car indx)))
      ;; seeded-only ordering: requisitioned exclusively by seeded re-entry
      ;; rules, so its WriteTask is gated the same way -- fresh runs never
      ;; pay its per-iteration maintenance (the reload re-stages the whole
      ;; database, so a seeded run's iteration 0 ingests the full content)
      (define seeded-only (eq? 'seeded-only (car indx)))
      (define ind (if (or delta seeded-only) (cdr indx) indx))
      (define A (length ind))  ;; composite-key arity = ordering length
      (define ordering (elocal 'ord))
      (define isstatic (if (and (equal? indx (car indices)) (not delta)) "true" "false"))
      (append
       (cond
         ;; count flavor (§8B.1): full orderings register (idempotent; a
         ;; fresh one is backfilled from resident content, database.h
         ;; addIndex) but get NO WriteTask -- head emissions are count
         ;; contributions folded by CountTask, never index inserts.  Delta/
         ;; seeded-only orderings should not be requisitioned by counted
         ;; plans at all; skip defensively.
         [(and (count-flavor) (not (maintenance-flavor)))
          (if (or delta seeded-only)
              '()
              (list
               (format "r->addIndex<~a>(~a, false);" A ordering)
               (add-ord-decl ordering ind 2)))]
         [else
          (list
           (if seeded-only
               (format "  s->addTaskSeeded(phase_write, new slog::WriteTask<~a>(db, r, ~a, false, b));"
                       A (u16-array-lit ind))
               (format "  s->addTask(phase_write, new slog::WriteTask<~a>(db, r, ~a, ~a, b), ~a);"
                       A (u16-array-lit ind) (if delta "true" "false") isstatic))
           (format "for (u16 b = 0; b < ~a; ++b)" bucket-count)
           (format "r->addIndex<~a>(~a, ~a~a);" A ordering (if delta "true" "false")
                   (if seeded-only ", true" ""))
           (add-ord-decl ordering ind 2))])
       lines)))))

;; The interning task for a relation's master index (its first index, already
;; created by add-write-task): a per-bucket generic slog::InternTask<N> (set
;; semantics) or InternStructTask<N> (content dedup + id assignment).
;;
;; The _count flavor (docs/incremental.md §8B.1) registers a counting task
;; INSTEAD when the relation is a counted head -- kind-tagged contribution
;; rows fold into the count sidecar; nothing is deduped, nulled, or
;; inserted -- and nothing at all for read-only relations (their deltas
;; stay empty in a no-reload count round).
(define (add-intern-task name intern-ord is-struct #:counted? [counted? #f]
                         #:arity [arity #f])
  (define N (length intern-ord))
  (cond
    [(and (count-flavor) (not (maintenance-flavor)))
     (cond
       [(not counted?) ""]
       [(and (not is-struct) (zero? arity))
        (error 'emit-cpp
               "count flavor: arity-0 (propositional) counted head ~a is not yet supported (docs/incremental.md M0)"
               name)]
       [else
        ((emit-lines 2)
         (format "for (u16 b = 0; b < ~a; ++b)" bucket-count)
         (format "  s->addTask(phase_intern, new slog::Count~aTask<~a>(db, db->getRelation(\"~a\"), b), false);"
                 (if is-struct "Struct" "") arity name))])]
    [(and (maintenance-flavor) counted?)
     (when (or is-struct (zero? arity))
       (error 'emit-cpp
              "M1 maintenance supports positive-arity plain-table heads only: ~a"
              name))
     ((emit-lines 2)
      (format "s->addTask(phase_intern, new slog::MaintainTask<~a>(db, db->getRelation(\"~a\"), ~a, 0));"
              N name (u16-array-lit intern-ord)))]
    [else
     ((emit-lines 2)
      (format "for (u16 b = 0; b < ~a; ++b)" bucket-count)
      (format "  s->addTask(phase_intern, new slog::Intern~aTask<~a>(db, db->getRelation(\"~a\"), ~a, b));"
              (if is-struct "Struct" "") N name (u16-array-lit intern-ord)))]))

;; A lattice (map) relation (docs/lattices.md §4): payload-map indices under
;; full orderings ending in the value column.  The master (first) ordering's
;; map is seeded once from iteration-0's delta (the reload/initial facts) and
;; thereafter maintained by the per-bucket LatticeInternTask -- the merge
;; point, which also nulls subsumed delta records and rewrites ascending ones
;; to the post-merge value; secondary maps merge every iteration's (already
;; merged) delta; delta indices are ordinary full-width sets.
(define (lat-kind-cpp kind)
  (match kind
    ['min "LAT_MIN"] ['max "LAT_MAX"] ['count "LAT_COUNT"] ['flat "LAT_FLAT"]
    ;; collection lattices (set/map specs): the runtime parses the spec
    ;; token into a LatSpec tree and joins via the collection arena
    ['set "LAT_EXTERN"] ['map "LAT_EXTERN"]))

;; The canonical spec token carried into the runtime and the on-disk
;; directory name ("min-int-floor-0", "count", "flat-value"); runslog.rkt's
;; manifest scan and the daemon's open path parse it back.
(define (lat-spec-token spec)
  (string-join (map ~a (flatten spec)) "-"))

(define (add-lattice-decl name arity spec decomp indices)
  (match-define `(,kind ,rest ...) spec)
  (define base (and (memq kind '(min max flat)) (car rest)))
  (define (param key)
    (for/first ([p (in-list rest)] #:when (and (pair? p) (eq? (car p) key)))
      (second p)))
  (define (clamp-word v)
    (if (eq? base 'float)
        (format "float_encode(~a)" (exact->inexact v))
        (format "s32_encode(~a)" v)))
  (define floorv (param 'floor))
  (define ceilv (param 'ceiling))
  (define master (first indices))
  ;; M2.4 decomposition target (docs/primitives.md §4.2): extra constructor
  ;; args for the MASTER merge tasks -- the once MapWriteTask (iteration-0
  ;; re-derivation from the reloaded/imported base) and the LatticeInternTask
  ;; (per-ascent O(change) deltas).  The target relation is registered before
  ;; this decl runs: decls emit in descending name order and "<R>_has"/
  ;; "<R>_at" extends (sorts after) "<R>".
  (define decomp-args
    (match decomp
      [`(decomp ,target ,dkind)
       (format ", db->getRelation(\"~a\"), ~a" target (if (eq? dkind 'map) "true" "false"))]
      [#f ""]))
  (string-append
   ((emit-lines 2)
    (format "r = db->getRelation(\"~a\");" name)
    (format "if (r == 0) db->addRelation(\"~a\", ~a);" name arity)
    (format "else if (r->getArity() != ~a)" arity)
    "  slog::fatal(\"Relation already exists at incorrect arity.\");"
    (format "r = db->getRelation(\"~a\");" name)
    (format "r->setLattice(~a, ~a, ~a, ~a, ~a, \"~a\", db->collections());"
            (lat-kind-cpp kind)
            (if floorv "true" "false") (if floorv (clamp-word floorv) "0")
            (if ceilv "true" "false") (if ceilv (clamp-word ceilv) "0")
            (lat-spec-token spec))
    (apply
     (emit-lines 2)
     (for/fold ([lines '()] #:result (reverse lines))
               ([indx (in-list indices)])
       (define delta (eq? 'delta (car indx)))
       (define ind (if delta (cdr indx) indx))
       (define A (length ind))
       (define ordering (elocal 'ord))
       (define isstatic (if (and (equal? indx master) (not delta)) "true" "false"))
       (append
        (cond
          ;; count flavor: payload maps register (idempotent -- live merged
          ;; maps survive) for the flavor's join-lat reads; NO merge/write
          ;; tasks and no delta indices (lattice heads are uncounted until
          ;; M6 and emit nothing in this flavor).
          [(and (count-flavor) (not (maintenance-flavor)))
           (if delta
               '()
               (list
                (format "r->addMapIndex<~a>(~a);" A ordering)
                (add-ord-decl ordering ind 2)))]
          [delta
           (list
            (format "  s->addTask(phase_write, new slog::WriteTask<~a>(db, r, ~a, true, b), false);"
                    A (u16-array-lit ind))
            (format "for (u16 b = 0; b < ~a; ++b)" bucket-count)
            (format "r->addIndex<~a>(~a, true);" A ordering)
            (add-ord-decl ordering ind 2))]
          [else
           (list
            (format "  s->addTask(phase_write, new slog::MapWriteTask<~a>(db, r, ~a, b~a), ~a);"
                    A (u16-array-lit ind)
                    (if (equal? isstatic "true") decomp-args "")
                    isstatic)
            (format "for (u16 b = 0; b < ~a; ++b)" bucket-count)
            (format "r->addMapIndex<~a>(~a);" A ordering)
            (add-ord-decl ordering ind 2))])
        lines))))
   "\n"
   (if (and (count-flavor) (not (maintenance-flavor)))
       ""
       ((emit-lines 2)
        (format "for (u16 b = 0; b < ~a; ++b)" bucket-count)
        (format "  s->addTask(phase_intern, new slog::LatticeInternTask<~a>(db, db->getRelation(\"~a\"), ~a, b~a));"
                arity name (u16-array-lit master) decomp-args)))))

;; `counted-heads` (the _count flavor): relations whose emissions are count
;; contributions -- rule heads plus the runtime-error arms; empty otherwise.
(define ((add-rel-decl [counted-heads (set)]) rel)
  (match rel
    ;; an extern relation's oracle binding (docs/smt.md): registers the
    ;; dispatch/harvest tasks against the (already-declared) demand struct
    ;; and its answer table.  Emitted after all relation decls (build-cprog
    ;; appends it) so the getRelation lookups inside bindOracle succeed.
    [`(oracle ,oname ,drel ,arel)
     ((emit-lines 2)
      (format "d->bindOracle(s, \"~a\", \"~a\", \"~a\");" oname drel arel))]
    ;; sequence-occurrence feeding (docs/sequences.md §5.3): one SeqIndexTask
    ;; per fed base, publishing (val,pos,list)/(val,rpos,list) rows for every
    ;; unseen sequence id in the base's delta.  Registered not-once: iteration
    ;; 0's delta is the reloaded base (full re-derivation), later iterations
    ;; are growth.  getRelation on an occurrence relation this stratum never
    ;; declared yields null; the task publishes to whichever exist.
    [`(seqindex ,base (,cols ...))
     ((emit-lines 2)
      "{"
      (format "  std::vector<u16> seqcols({~a});"
              (string-join (map ~a cols) ", "))
      (format "  s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation(\"~a\"), seqcols, db->getRelation(\"$seq_at\"), db->getRelation(\"$seq_atr\")), false);"
              base)
      "}")]
    [`(temp ,name ,arity)
     ((emit-lines 2)
      (format "r = db->getRelation(\"~a\");" name)
      (format "if (r == 0) db->addTempRelation(\"~a\", ~a);" name arity)
      (format "else if (r->getArity() != ~a) slog::fatal(\"Temp rel arity mismatch.\");" arity))]
    [`(struct ,name ,arity ,indices ...)
     (when (or (not (> (length indices) 1))
               (not (equal? (last (first indices)) 0))
               (not (equal? (first (second indices)) 0)))
       (error (format "Struct ~a does not have required indices in ~a" name indices)))
     (string-append (add-write-task name arity indices #t)
                    "\n"
                    (add-intern-task name (first indices) #t
                                     #:counted? (set-member? counted-heads name)
                                     #:arity arity))]
    [`(relation ,name ,arity ,indices ...)
     (when (null? indices)
       (error (format "Table ~a does not have any indices." name)))
     (string-append (add-write-task name arity indices #f)
                    "\n"
                    (add-intern-task name (first indices) #f
                                     #:counted? (set-member? counted-heads name)
                                     #:arity arity))]
    [`(lattice ,name ,arity ,spec ,decomp ,indices ...)
     (when (or (null? indices) (eq? 'delta (car (first indices))))
       (error (format "Lattice relation ~a must lead with a non-delta (master) index: ~a"
                      name indices)))
     (add-lattice-decl name arity spec decomp indices)]))

;; -----------------------------------------------------------------------
;; Rules.

;; A member declaration + constructor lookup for one index.
(define (index-member name member ind delta)
  (define ord-name (elocal 'ord))
  (define rel-name (elocal 'readrel))
  (string-append "    "
                 (add-ord-decl ord-name ind)
                 (format "    slog::Relation* ~a = db->getRelation(\"~a\");\n" rel-name name)
                 (format "    ~a = ~a->getIndex(~a, ~a);"
                         member rel-name ord-name (if delta "true" "false"))))

;; Emit the ops of a rule body (after the driver), innermost continuation
;; last.  Each join op opens a nested continuation lambda; other ops are
;; straight-line statements.  `index-name-of` maps a join op to its member.
(define (emit-ops ops index-name-of delta-name-of head-fun indent)
  (match ops
    ['() (head-fun indent)]
    [`(,(and op `(join ,name ,ind ,K ,ys ...)) . ,rest)
     (define A (length ys))
     (define free (drop ys K))
     (define m (elocal 'm))
     (define bind-free
       (string-join (for/list ([k (in-range K A)])
                      (format "u64 v_~a = ~a[~a];" (list-ref ys k) m k))
                    " "))
     (define inner
       (string-append
        (if (string=? bind-free "") "" ((emit-lines (+ indent 2)) bind-free))
        (emit-ops rest index-name-of delta-name-of head-fun (+ indent 2))))
     (if (= K 0)
         ;; no bound prefix: cartesian scan over every bucket of the index
         (string-append
          ((emit-lines indent)
           (format "slog::join_all<~a>(~a, [&](const std::array<u64,~a>& ~a) {"
                   A (index-name-of op) A m))
          inner
          ((emit-lines indent) "});"))
         ;; bound prefix: probe the bucket of the lead value, range-scan
         (let ([key (u64-array-lit (append (map (lambda (y) (format "v_~a" y)) (take ys K))
                                           (make-list (- A K) "0")))])
           (string-append
            ((emit-lines indent)
             (format "slog::join_probe<~a,~a>(~a, ~a, [&](const std::array<u64,~a>& ~a) {"
                     A K (index-name-of op) key A m))
            inner
            ((emit-lines indent) "});"))))]
    ;; JOIN against R_old = full - current delta (exact semi-naive, §6/§8): like
    ;; `join`, but excludes matches present in the same-ordering delta index
    [`(,(and op `(,(and join-kind (or 'join-old 'join-new))
                   ,name ,ind ,K ,dind ,ys ...)) . ,rest)
     (define A (length ys))
     (define m (elocal 'm))
     (define bind-free
       (string-join (for/list ([k (in-range K A)])
                      (format "u64 v_~a = ~a[~a];" (list-ref ys k) m k))
                    " "))
     (define inner
       (string-append
        (if (string=? bind-free "") "" ((emit-lines (+ indent 2)) bind-free))
        (emit-ops rest index-name-of delta-name-of head-fun (+ indent 2))))
     (define suffix (if (eq? join-kind 'join-new) "new" "old"))
     (if (= K 0)
         (string-append
          ((emit-lines indent)
           (format "slog::join_all_~a<~a>(~a, ~a, [&](const std::array<u64,~a>& ~a) {"
                   suffix A (index-name-of op) (delta-name-of op) A m))
          inner
          ((emit-lines indent) "});"))
         (let ([key (u64-array-lit (append (map (lambda (y) (format "v_~a" y)) (take ys K))
                                           (make-list (- A K) "0")))])
           (string-append
            ((emit-lines indent)
             (format "slog::join_probe_~a<~a,~a>(~a, ~a, ~a, [&](const std::array<u64,~a>& ~a) {"
                     suffix A K (index-name-of op) (delta-name-of op) key A m))
            inner
            ((emit-lines indent) "});"))))]
    ;; a lattice body read: probe the payload map over the key columns; the
    ;; continuation binds the free keys plus the current merged value (last var)
    ;; a semijoin filter: one existence probe on the K bound columns; a
    ;; miss abandons the current tuple (no future clause could accept it)
    [`(,(and op `(exists ,name ,ind ,K ,ys ...)) . ,rest)
     (define A (length ind))
     (define key (u64-array-lit (append (map (lambda (y) (format "v_~a" y)) ys)
                                        (make-list (- A K) "0"))))
     (string-append
      ((emit-lines indent)
       (format "if (!slog::exists_probe<~a,~a>(~a, ~a)) return;"
               A K (index-name-of op) key))
      (emit-ops rest index-name-of delta-name-of head-fun indent))]
    ;; a negated atom (docs/incremental.md §0.8): one absence probe on the
    ;; K bound columns of the CLOSED relation's full index; a match
    ;; abandons the current tuple.  K = 0 is the emptiness test.
    [`(,(and op `(absent ,name ,ind ,K ,ys ...)) . ,rest)
     (define A (length ind))
     (define key (u64-array-lit (append (map (lambda (y) (format "v_~a" y)) ys)
                                        (make-list (- A K) "0"))))
     (string-append
      ((emit-lines indent)
       (format "if (!slog::absent_probe<~a,~a>(~a, ~a)) return;"
               A K (index-name-of op) key))
      (emit-ops rest index-name-of delta-name-of head-fun indent))]
    ;; negation over lattice keys: absence probe of the payload map under
    ;; the K-bound key prefix ("no value at key k"); the ordering's last
    ;; column is the merged value, so the map's key width is A-1
    [`(,(and op `(absent-lat ,name ,ind ,K ,ys ...)) . ,rest)
     (define KA (sub1 (length ind)))
     (define key (u64-array-lit (append (map (lambda (y) (format "v_~a" y)) ys)
                                        (make-list (- KA K) "0"))))
     (string-append
      ((emit-lines indent)
       (format "if (!slog::absent_probe_lat<~a,~a>(~a, ~a)) return;"
               KA K (index-name-of op) key))
      (emit-ops rest index-name-of delta-name-of head-fun indent))]
    [`(,(and op `(join-lat ,name ,ind ,K ,ys ...)) . ,rest)
     (define KA (sub1 (length ys)))          ; key columns; last var is the value
     (define vvar (last ys))
     (define m (elocal 'm))
     (define vparam (elocal 'val))
     (define bind-free
       (string-join (append
                     (for/list ([k (in-range K KA)])
                       (format "u64 v_~a = ~a[~a];" (list-ref ys k) m k))
                     (list (format "u64 v_~a = ~a;" vvar vparam)))
                    " "))
     (define inner
       (string-append
        ((emit-lines (+ indent 2)) bind-free)
        (emit-ops rest index-name-of delta-name-of head-fun (+ indent 2))))
     (if (= K 0)
         (string-append
          ((emit-lines indent)
           (format "slog::join_all_lat<~a>(~a, [&](const std::array<u64,~a>& ~a, u64 ~a) {"
                   KA (index-name-of op) KA m vparam))
          inner
          ((emit-lines indent) "});"))
         (let ([key (u64-array-lit (append (map (lambda (y) (format "v_~a" y)) (take ys K))
                                           (make-list (- KA K) "0")))])
           (string-append
            ((emit-lines indent)
             (format "slog::join_probe_lat<~a,~a>(~a, ~a, [&](const std::array<u64,~a>& ~a, u64 ~a) {"
                     KA K (index-name-of op) key KA m vparam))
            inner
            ((emit-lines indent) "});"))))]
    [`(,op . ,rest)
     (string-append
      ((emit-lines indent) (emit-straight-op op))
      (emit-ops rest index-name-of delta-name-of head-fun indent))]))

;; Straight-line (non-join) ops; `return` skips the current tuple.
(define (emit-straight-op op)
  (match op
    [`(let ,x ,(? symbol? y)) (format "u64 v_~a = v_~a;" x y)]
    [`(let ,x (,f ,args ...))
     (string-append (format "u64 v_~a = ~a;\n" x (prim-call f args))
                    (prim-error-check x "return;"))]
    [`(letp ,x (,f ,args ...)) (partial-prim-call x f args "return;")]
    [`(cjoin ,x ,spec ,a ,b) (cjoin-call x spec a b)]
    [`(eq ,x ,y) (format "if (v_~a != v_~a) return;" x y)]
    [`(neq ,x ,y) (format "if (v_~a == v_~a) return;" x y)]
    [`(cmp ,fn ,x ,y)
     (define t (elocal 'cmpr))
     (string-append (format "u64 v_~a = _prim_~a(db, v_~a, v_~a);\n" t fn x y)
                    (prim-error-check t "return;") "\n"
                    (format "if (!v_~a) return;" t))]))

;; Pre-ops run at the top of work() (not inside a driver lambda), so a failing
;; constant guard aborts the WHOLE task -- and since work() now returns bool
;; (docs/pausing.md §3), that abort is `return true;` (task finished, produced
;; nothing), not the tuple-skipping `return;` of a body op.  `index-name-of`
;; resolves the index member of a pre-position absent probe (a negation whose
;; key is all-constant or all-wildcard fires before the driver).
(define (emit-pre-op op [index-name-of #f])
  (match op
    [`(absent ,name ,ind ,K ,ys ...)
     (define A (length ind))
     (define key (u64-array-lit (append (map (lambda (y) (format "v_~a" y)) ys)
                                        (make-list (- A K) "0"))))
     (format "if (!slog::absent_probe<~a,~a>(~a, ~a)) return true;"
             A K (index-name-of op) key)]
    [`(absent-lat ,name ,ind ,K ,ys ...)
     (define KA (sub1 (length ind)))
     (define key (u64-array-lit (append (map (lambda (y) (format "v_~a" y)) ys)
                                        (make-list (- KA K) "0"))))
     (format "if (!slog::absent_probe_lat<~a,~a>(~a, ~a)) return true;"
             KA K (index-name-of op) key)]
    [`(let ,x ,(? symbol? y)) (format "u64 v_~a = v_~a;" x y)]
    [`(let ,x (,f ,args ...))
     (string-append (format "u64 v_~a = ~a;\n" x (prim-call f args))
                    (prim-error-check x "return true;"))]
    [`(letp ,x (,f ,args ...)) (partial-prim-call x f args "return true;")]
    [`(cjoin ,x ,spec ,a ,b) (cjoin-call x spec a b)]
    [`(eq ,x ,y) (format "if (v_~a != v_~a) return true;" x y)]
    [`(neq ,x ,y) (format "if (v_~a == v_~a) return true;" x y)]
    [`(cmp ,fn ,x ,y)
     (define t (elocal 'cmpr))
     (string-append (format "u64 v_~a = _prim_~a(db, v_~a, v_~a);\n" t fn x y)
                    (prim-error-check t "return true;") "\n"
                    (format "if (!v_~a) return true;" t))]))

;; The innermost continuation: emit each head op.  emit/emit_temp sinks do
;; their own dedup + batch flush (operators.h); emit_struct leaves dedup and
;; id assignment to the intern phase.  tycheck hops always precede the
;; emitting hops (operationalization.rkt), so their guards protect every
;; sink of the rule; `sid-members` maps a struct name in an accept set to
;; the task's u32 member holding its runtime struct id.
(define ((emit-heads heads sid-members [seeded? #f]) indent)
  (apply string-append
         (for/list ([hop (in-list heads)] [i (in-naturals)])
           (match hop
             [`(let ,x (,f ,args ...))
              ((emit-lines indent)
               (format "u64 v_~a = ~a;" x (prim-call f args))
               (prim-error-check x "return;"))]
             [`(letp ,x (,f ,args ...))
              ((emit-lines indent) (partial-prim-call x f args "return;"))]
             [`(cjoin ,x ,spec ,a ,b)
              ((emit-lines indent) (cjoin-call x spec a b))]
             ;; a residual type check: if the value's surface tag matches no
             ;; accepted type, divert -- intern a malformed_deduction struct
             ;; (rule-location, relation, column, bad value) in place of the
             ;; deduction and abandon the tuple (`return` = old `continue`)
             [`(tycheck ,y (accept ,ts ...) ,rid ,rel ,colv ,ind)
              (define prim-tests
                (for/list ([t (in-list ts)] #:when (symbol? t))
                  (format (match t
                            ;; int spans both representations (s32 prim or
                            ;; interned mpz bignum, docs/primitives.md §14)
                            ['int "is_int(v_~a)"]
                            ['float "is_float(v_~a)"]
                            ['str "is_str(v_~a)"]
                            ['cnode "is_cnode(v_~a)"]
                            ['seq "is_seq(v_~a)"])
                          y)))
              (define sid-tests
                (for/list ([t (in-list ts)] #:unless (symbol? t))
                  (format "decode_struct_id(v_~a) == ~a"
                          y (hash-ref sid-members (second t)))))
              (define struct-test
                (if (null? sid-tests)
                    '()
                    (list (format "(is_struct(v_~a) && (~a))"
                                  y (string-join sid-tests " || ")))))
              ((emit-lines indent)
               (format "if (!(~a))"
                       (string-join (append prim-tests struct-test) " || "))
               "{"
               ;; a failed check is instantiation-deterministic (§8B.4), so
               ;; the count flavor counts the malformed_deduction row too
               (if (current-rule-kind)
                   (format "  slog::emit_struct_count<5>(head_rel[~a], head_index[~a], ~a, newbatch[~a], ~a, ~a);"
                           i i (cnt-kind-cpp (current-rule-kind)) i
                           (u64-array-lit (map (lambda (z) (format "v_~a" z))
                                               (list rid rel colv y)))
                           (u16-array-lit ind))
                   (format "  slog::emit_struct<5>(head_rel[~a], newbatch[~a], ~a, ~a);"
                           i i
                           (u64-array-lit (map (lambda (z) (format "v_~a" z))
                                               (list rid rel colv y)))
                           (u16-array-lit ind)))
               "  return;"
               "}")]
             [`(mkstruct ,name ,ind ,x ,fields ...)
              (cond
                [(maintenance-flavor)
                 (error 'emit-cpp
                        "M1 maintenance does not support struct heads: ~a" name)]
                ;; count flavor (§8B.1): resolve the interned id by content
                ;; and count the contribution; never inserts
                [(current-rule-kind)
                 ((emit-lines indent)
                  (format "slog::emit_struct_count<~a>(head_rel[~a], head_index[~a], ~a, newbatch[~a], ~a, ~a);"
                          (length ind) i i (cnt-kind-cpp (current-rule-kind)) i
                          (u64-array-lit (map (lambda (z) (format "v_~a" z)) fields))
                          (u16-array-lit ind)))]
                ;; a seeded re-entry task re-fires every iteration: skip
                ;; instances the master index already holds, or the
                ;; re-emissions would read as fresh delta forever
                [seeded?
                 ((emit-lines indent)
                  (format "slog::emit_struct_checked<~a>(head_rel[~a], head_index[~a], newbatch[~a], ~a, ~a);"
                          (length ind) i i i
                          (u64-array-lit (map (lambda (z) (format "v_~a" z)) fields))
                          (u16-array-lit ind)))]
                [else
                 ((emit-lines indent)
                  (format "slog::emit_struct<~a>(head_rel[~a], newbatch[~a], ~a, ~a);"
                          (length ind) i i
                          (u64-array-lit (map (lambda (z) (format "v_~a" z)) fields))
                          (u16-array-lit ind)))])]
             [`(emit ,name ,ind ,zs ...)
              (if (current-rule-kind)
                  (if (maintenance-flavor)
                      ;; Every newly-enabled instantiation is a contribution;
                      ;; MaintainTask later turns only 0->1 support changes
                      ;; into membership delta.
                      ((emit-lines indent)
                       (format "slog::emit_maint<~a>(head_rel[~a], ~a, ~a, newbatch[~a], ~a, ~a);"
                               (length zs) i (cnt-kind-cpp (current-rule-kind))
                               (if (negative-maintenance-flavor?) -1 1) i
                               (u64-array-lit (map (lambda (z) (format "v_~a" z)) zs))
                               (u16-array-lit ind)))
                      ;; recount flavor: closure-check instead of dedup-skip
                      ((emit-lines indent)
                       (format "slog::emit_count<~a>(head_rel[~a], head_index[~a], ~a, newbatch[~a], ~a, ~a);"
                               (length zs) i i (cnt-kind-cpp (current-rule-kind)) i
                               (u64-array-lit (map (lambda (z) (format "v_~a" z)) zs))
                               (u16-array-lit ind))))
                  ((emit-lines indent)
                   (format "slog::emit<~a>(head_rel[~a], head_index[~a], newbatch[~a], ~a, ~a);"
                           (length zs) i i i
                           (u64-array-lit (map (lambda (z) (format "v_~a" z)) zs))
                           (u16-array-lit ind))))]
             [`(emit-temp ,name ,zs ...)
              ((emit-lines indent)
               (format "slog::emit_temp<~a>(head_rel[~a], newbatch[~a], ~a);"
                       (length zs) i i
                       (u64-array-lit (map (lambda (z) (format "v_~a" z)) zs))))]
             ;; a lattice contribution: nominal order, no dedup (the merge
             ;; task owns subsumption) -- the emit_temp sink is exactly that.
             ;; The count flavor emits NOTHING here: lattice-valued heads are
             ;; uncounted until M6 (docs/incremental.md §7A/§8B), and firing
             ;; the merge machinery off count-round re-derivations would be
             ;; pure waste against an already-merged resident map.
             [`(emit-lat ,name ,zs ...)
              (if (current-rule-kind)
                  ((emit-lines indent)
                   "// lattice head: uncounted in the _count flavor (M6)")
                  ((emit-lines indent)
                   (format "slog::emit_temp<~a>(head_rel[~a], newbatch[~a], ~a);"
                           (length zs) i i
                           (u64-array-lit (map (lambda (z) (format "v_~a" z)) zs)))))]))))

(define ((add-rule dynamic-rels) crule)
 (parameterize ([current-rule-loc (or (crule-loc crule) "<unknown>")]
                [current-rule-kind (crule-kind crule)])
  (define pre (crule-pre crule))
  (define driver (crule-driver crule))
  (define body (crule-body crule))
  (define heads (crule-head crule))

  ;; name the index member for the driver probe, each body join, each
  ;; semijoin filter's existence probe, and each negated atom's absence
  ;; probe -- absent ops can also sit in the PRE slot (a negation whose key
  ;; is all-constant or all-wildcard runs before the driver), so scan both
  (define join-members
    (for/list ([op (in-list (append pre body))]
               #:when (memq (car op) '(join join-lat exists join-old join-new
                                       absent absent-lat)))
      (cons op (elocal (string->symbol (format "~aindex" (second op)))))))
  ;; a join-old op needs a SECOND member for the delta index it excludes against
  (define join-old-delta-members
    (for/list ([op (in-list body)]
               #:when (memq (car op) '(join-old join-new)))
      (cons op (elocal (string->symbol (format "~adelta" (second op)))))))
  (define (index-name-of op)
    (cdr (assq op join-members)))
  (define (delta-name-of op)
    (cdr (assq op join-old-delta-members)))

  (define driver-rel
    (match driver
      [`(once) #f]
      [`(seeded) #f]
      [`(,_ ,name ,_ ...) name]))
  (define seeded? (eq? (car driver) 'seeded))
  (define static?
    (or (not driver-rel) (not (set-member? dynamic-rels driver-rel))))

  ;; an unkeyed join over a co-recursive relation inside a delta variant
  ;; re-scans it every iteration -- the computed-key smell whose demand-rule
  ;; instances the supplementary transform fixes (docs/demand.md §5).
  ;; Demand-machinery drivers (f_ans / $-synthesized) are exempt: their
  ;; residual scans are the semantically-required broadcasts.
  (unless (or static?
              (not driver-rel)
              (regexp-match? #rx"_ans$" (symbol->string driver-rel))
              (string-prefix? (symbol->string driver-rel) "$"))
    (for ([op (in-list body)])
      (match op
        [`(,(or 'join 'join-lat 'join-old 'join-new) ,jname ,_ 0 ,_ ...)
         #:when (and (set-member? dynamic-rels jname)
                     (not (set-member? warned-scans
                                       (cons (current-rule-loc) jname))))
         (set-add! warned-scans (cons (current-rule-loc) jname))
         (eprintf "warning: a delta variant of the rule at ~a joins ~a with no bound column -- an unkeyed scan EVERY iteration; key it through a column, a demand judgment, or a materialized edge table (docs/demand.md 5)\n"
                  (current-rule-loc) jname)]
        [_ (void)])))

  ;; runtime statistics (docs/stats.md): _fires counts this task's
  ;; INSTANTIATIONS (satisfying body assignments; multi-head rules count
  ;; once) and flushes before both exits, so sliced/paused invocations
  ;; accumulate.  Same-driver variants of one rule share a key: totals per
  ;; rule are the exact-once audit's unit (docs/incremental.md §8).
  (define variant-tag
    (match driver
      [`(once) "once"]
      [`(seeded) "seeded"]
      [`(,_ ,name ,_ ...)
       (format "~a:~a" (if static? "all" "delta") name)]))
  (define fires-flush
    ((emit-lines 4)
     (format "if (_fires) db->bumpFires(\"~a\", \"~a\", _fires);"
             (escape-c-string-literal (current-rule-loc))
             (escape-c-string-literal variant-tag))))

  ;; heads that emit tuples need an insert batch (let heads do not); a
  ;; tycheck's slot batches its failure-path malformed_deduction structs
  (define emitting-head-is
    (for/list ([hop (in-list heads)] [i (in-naturals)]
               #:when (memq (car hop) '(mkstruct emit emit-temp emit-lat tycheck)))
      i))

  ;; runtime struct ids the tycheck accept sets compare against: one u32
  ;; member per distinct struct name, looked up once at task construction
  (define sid-members
    (for/fold ([h (hash)])
              ([hop (in-list heads)] #:when (eq? 'tycheck (car hop)))
      (for/fold ([h h]) ([t (in-list (cdr (third hop)))])
        (match t
          [`(struct ,n)
           (if (hash-has-key? h n) h (hash-set h n (elocal 'sid)))]
          [_ h]))))
  (define sid-members-sorted
    (sort (hash->list sid-members) symbol<? #:key car))

  (define task-name (elocal 'ReadTask))

  ;; --- constructor body: look up head relations/indices and join indices
  (define ctor-body
    (string-append
     (apply string-append
            (for/list ([hop (in-list heads)] [i (in-naturals)])
              (match hop
                [`(let ,_ ,_) ""]
                [`(letp ,_ ,_) ""]
                [`(cjoin ,_ ,_ ,_ ,_) ""]
                [`(tycheck ,_ ,_ ,_ ,_ ,_ ,ind)
                 ;; the counting sink resolves the malformed_deduction id by
                 ;; content, so it needs the master index bound too
                 (if (current-rule-kind)
                     (string-append
                      (format "    head_rel[~a] = db->getRelation(\"malformed_deduction\");\n" i)
                      (index-member 'malformed_deduction (format "head_index[~a]" i) ind #f)
                      "\n")
                     (format "    head_rel[~a] = db->getRelation(\"malformed_deduction\");\n" i))]
                [`(mkstruct ,name ,ind ,_ ,_ ...)
                 (if (or seeded? (current-rule-kind))
                     ;; the checked/counting sinks probe the master index
                     (string-append
                      (format "    head_rel[~a] = db->getRelation(\"~a\");\n" i name)
                      (index-member name (format "head_index[~a]" i) ind #f)
                      "\n")
                     (format "    head_rel[~a] = db->getRelation(\"~a\");\n" i name))]
                [`(emit-temp ,name ,_ ...)
                 (format "    head_rel[~a] = db->getRelation(\"~a\");\n" i name)]
                [`(emit-lat ,name ,_ ...)
                 (format "    head_rel[~a] = db->getRelation(\"~a\");\n" i name)]
                [`(emit ,name ,ind ,_ ...)
                 (string-append
                  (format "    head_rel[~a] = db->getRelation(\"~a\");\n" i name)
                  (index-member name (format "head_index[~a]" i) ind #f)
                  "\n")])))
     (match driver
       [`(scan ,name ,_ ...)
        (format "    outer_rel = db->getRelation(\"~a\");\n" name)]
       [`(probe ,name ,ind ,_ ...)
        (string-append (index-member name "driver_index" ind #t) "\n")]
       [`(once) ""]
       [`(seeded) ""])
     (apply string-append
            (for/list ([om (in-list join-members)])
              (match (car om)
                [`(,(or 'join 'join-lat 'exists 'absent 'absent-lat) ,name ,ind ,_ ...)
                 (string-append (index-member name (cdr om) ind #f) "\n")]
                [`(,(or 'join-old 'join-new) ,name ,ind ,_ ,dind ,_ ...)
                 (string-append
                  (index-member name (cdr om) ind #f) "\n"
                  (index-member name (delta-name-of (car om)) dind #t) "\n")])))
     (apply string-append
            (for/list ([p (in-list sid-members-sorted)])
              (format "    ~a = db->getRelation(\"~a\")->getStructId();\n"
                      (cdr p) (car p))))))

  ;; --- work() body
  (define alloc-batches
    (apply string-append
           (map (lambda (i) (format "    newbatch[~a] = new slog::InsertBatch();\n" i))
                emitting-head-is)))
  (define send-batches
    (apply string-append
           (map (lambda (i) (format "      head_rel[~a]->sendBatch(newbatch[~a]);\n" i i))
                emitting-head-is)))

  ;; SLICING (docs/pausing.md §3, Regime 1): every read-phase rule pauses at its
  ;; OUTER loop and parks a continuation, so pausing is uniform and EXACT (zero
  ;; redo).  A scan driver (read_delta -- recursive rules, and static rules over
  ;; a closed relation) resumes at (thread t, ref i); a probe DRIVER with free
  ;; columns (K<A) resumes from its last match key.  A fully-bound probe (K==A,
  ;; at most one match) and a fact `once` rule (no joins, fixed output) are
  ;; bounded, so they run atomically -- there is nothing to slice.
  (define slice-kind
    (match driver
      [`(scan ,_ ...) 'scan]
      [`(probe ,_ ,_ ,K ,ys ...) (if (< K (length ys)) 'probe 'none)]
      [`(once) 'none]
      [`(seeded) 'none]))
  (define sliceable? (not (eq? slice-kind 'none)))
  (define probe-A
    (match driver [`(probe ,_ ,_ ,_ ,ys ...) (length ys)] [_ 0]))

  ;; Per-invocation slice context (steady-clock deadline = min(slice, global)
  ;; and the stop flag), shared by the sliceable drivers.
  (define slice-ctx-setup
    ((emit-lines 4)
     "auto _slice_deadline = std::min(db->runDeadline(),"
     "  std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));"
     "slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};"))

  (define count+heads
    (let ([hf (emit-heads heads sid-members seeded?)])
      (lambda (indent)
        (string-append ((emit-lines indent) "++_fires;") (hf indent)))))

  (define pipeline
    (match driver
      [`(,(or 'once 'seeded))
       (emit-ops body index-name-of delta-name-of count+heads 4)]
      [`(scan ,name ,xs ...)
       (string-append
        slice-ctx-setup
        ((emit-lines 4)
         "u32 _rt = resume_t, _ri = resume_i;"
         "bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {")
        (apply (emit-lines 6)
               (for/list ([x (in-list xs)] [n (in-naturals)])
                 (format "u64 v_~a = _t[~a];" x n)))
        (emit-ops body index-name-of delta-name-of count+heads 6)
        ((emit-lines 4) "});"))]
      [`(probe ,name ,ind ,K ,ys ...)
       (define A (length ys))
       (define free (drop ys K))
       (define m (elocal 'm))
       (define key (u64-array-lit (append (map (lambda (y) (format "v_~a" y)) (take ys K))
                                          (make-list (- A K) "0"))))
       ;; the probe key is shared by all bucket tasks, so partition the
       ;; results by the first freshly-bound column's bucket
       (define par-filter
         (if (pair? free)
             (format "if (buckethash(v_~a) != bucket) return;" (car free))
             ""))
       (define bind+body
         (string-append
          (apply (emit-lines 6)
                 (for/list ([k (in-range K A)])
                   (format "u64 v_~a = ~a[~a];" (list-ref ys k) m k)))
          (if (string=? par-filter "") "" ((emit-lines 6) par-filter))
          (emit-ops body index-name-of delta-name-of count+heads 6)))
       (if (eq? slice-kind 'probe)
           (string-append
            slice-ctx-setup
            ((emit-lines 4)
             (format "std::array<u64,~a> _rkey = resume_key; bool _hr = has_resume;" A)
             (format "bool _done = slog::join_probe_sliced<~a,~a>(driver_index, ~a, _sc, _rkey, _hr, [&](const std::array<u64,~a>& ~a) {"
                     A K key A m))
            bind+body
            ((emit-lines 4) "});"))
           ;; fully bound (K==A): at most one match, nothing to slice
           (string-append
            ((emit-lines 4)
             (format "slog::join_probe<~a,~a>(driver_index, ~a, [&](const std::array<u64,~a>& ~a) {"
                     A K key A m))
            bind+body
            ((emit-lines 4) "});")))]))

  ;; a fully-bound probe cannot partition; run it as a single task
  (define nbuckets
    (match driver
      [`(once) 1]
      [`(seeded) 1]
      [`(probe ,_ ,_ ,K ,ys ...) (if (= (length ys) K) 1 bucket-count)]
      [_ bucket-count]))

  ;; work()'s tail: a sliceable driver that paused (its _done is false) has
  ;; already flushed its partial batches (send-batches, above) and now parks a
  ;; continuation copy carrying its resume position -- the canonical task in
  ;; once[]/every[] is never mutated (§9.3).  Everything else just finishes.
  (define work-tail
    (cond
      [(eq? slice-kind 'scan)
       ((emit-lines 4)
        "if (!_done)" "{"
        (format "  ~a* _cont = new ~a(db, bucket);" task-name task-name)
        "  _cont->resume_t = _rt; _cont->resume_i = _ri;"
        "  db->pushPaused(phase_read, _cont);"
        "  return false;" "}"
        "return true;")]
      [(eq? slice-kind 'probe)
       ((emit-lines 4)
        "if (!_done)" "{"
        (format "  ~a* _cont = new ~a(db, bucket);" task-name task-name)
        "  _cont->resume_key = _rkey; _cont->has_resume = true;"
        "  db->pushPaused(phase_read, _cont);"
        "  return false;" "}"
        "return true;")]
      [else ((emit-lines 4) "return true;")]))

  ((emit-lines 2)
   (format "// ~a" crule)
   (format "class ~a : public slog::Task" task-name)
   (format "{")
   (format "  slog::Database* db;")
   (format "  u16 bucket;")
   (format "  slog::Relation* head_rel[~a];" (max 1 (length heads)))
   (format "  slog::Index** head_index[~a];" (max 1 (length heads)))
   (if (eq? (car driver) 'scan) "  slog::Relation* outer_rel;" "")
   (if (eq? (car driver) 'probe) "  slog::Index** driver_index;" "")
   ;; outer-loop resume position; private, but the pause path sets it on a
   ;; freshly-allocated sibling (same-class access), so no accessor is needed.
   ;; scan: (thread t, ref i); probe driver: the last match key + a resume flag.
   (if (eq? slice-kind 'scan) "  u32 resume_t = 0;" "")
   (if (eq? slice-kind 'scan) "  u32 resume_i = 0;" "")
   (if (eq? slice-kind 'probe) (format "  std::array<u64,~a> resume_key{};" probe-A) "")
   (if (eq? slice-kind 'probe) "  bool has_resume = false;" "")
   (apply string-append
          (map (lambda (om) (format "  slog::Index** ~a;" (cdr om)))
               (append join-members join-old-delta-members)))
   (apply string-append
          (map (lambda (p) (format "  u32 ~a;" (cdr p))) sid-members-sorted))
   (format "public:")
   ;; index/relation lookups live in bind(db) -- the constructor calls it, and
   ;; it is the re-binding seam a resident stratum will need to re-run after a
   ;; reload (docs/pausing.md §8b); a paused continuation re-binds here too.
   (format "  void bind(slog::Database* db)")
   (format "  {")
   ctor-body
   (format "  }")
   (format "  ~a(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }" task-name)
   (format "  virtual bool work()")
   (format "  {")
   ;; pre-ops run before any allocation, so a failing constant guard can
   ;; abort the whole task early (return true = finished, produced nothing)
   (apply (emit-lines 4) (map (lambda (op) (emit-pre-op op index-name-of)) pre))
   (format "    u64 _fires = 0;")
   (format "    slog::InsertBatch* newbatch[~a];" (max 1 (length heads)))
   alloc-batches
   pipeline
   send-batches
   fires-flush
   work-tail
   (format "  }")
   (format "  };")
   (format "  for (u16 b = 0; b < ~a; ++b)" nbuckets)
   (cond
     ;; count flavor (§8B.1): the seeded PLAN SHAPE (all-full joins) is the
     ;; fire-once count round -- registered ONCE, not gated on seeding
     [(and (eq? (car driver) 'seeded) (current-rule-kind))
      (format "    s->addTask(phase_read, new ~a(db,b), true);" task-name)]
     ;; seeded re-entry task: reruns every iteration, but ONLY when the
     ;; stratum begins over externally seeded content (daemon gate)
     [(eq? (car driver) 'seeded)
      (format "    s->addTaskSeeded(phase_read, new ~a(db,b));" task-name)]
     [else
      (format "    s->addTask(phase_read, new ~a(db,b), ~a);"
              task-name
              (if static? "true" "false"))]))))

;; -----------------------------------------------------------------------
;; Whole-program emission.

;; A large stratum's read-phase rules are split across this many translation
;; units so clang builds them in parallel (docs/fast-compile.md §6): the -O2
;; optimizer costs ~0.4s/rule and does not parallelize within one TU.  Strata at
;; or below this many rules stay a single TU (no splitting overhead) -- the vast
;; majority.  Both optimization tiers read the same .cpp files, so the O0 and O2
;; task registration order is identical (required for the hot swap).
(define chunk-size 48)

(define (chunk-list lst n)
  (if (<= (length lst) n) (list lst) (cons (take lst n) (chunk-list (drop lst n) n))))

;; Render one stratum's plugin.  Returns EITHER a single C++ string (one TU, the
;; common case) or, for a large stratum, a list of (suffix . contents) pairs:
;; the spine (suffix "") plus part TUs "p1".."pN", all linked into one .so.
;;
;; The spine's slog_plugin() builds the Stratum object (relations/indices on the
;; database; write/intern tasks + dynamic-rel metadata on the stratum), then
;; calls each part's slog_rules_<hash>_K(db, s) to register that chunk's
;; read-phase tasks, then pushes and runs.  A rule's emitted code references only
;; `s`, `db`, and the interned-constant globals `v_<g>` (everything else arrives
;; through the header include), so a part TU needs only the includes plus
;; `extern u64 v_<g>;` -- the single definition of each lives in the spine.
(define (write-cpp cprog dbmanifest stratum-name #:accel-rels [accel-rels '()])
  (define dynamic-rels (cprog-dynamic-rels cprog))
  (define constants (cprog-constants cprog))
  (define decls (cprog-decls cprog))
  (define crules (cprog-rules cprog))

  ;; declarations for relations that exist in the database (input DB or an
  ;; earlier program) but are not declared by this program: they must keep
  ;; an index so their facts survive this program's reload cycle
  (define declared
    (for/set ([d (in-list decls)]) (second d)))
  (define manifest-decls
    (for/list ([name (in-list (sort (hash-keys dbmanifest) symbol<?))]
               #:unless (set-member? declared name))
      (match (hash-ref dbmanifest name)
        [`(rel ,_ ,arity) `(relation ,name ,arity ,(range arity))]
        [`(struct ,_ ,arity)
         `(struct ,name ,arity (,@(range 1 arity) 0) ,(range arity))]
        ;; a manifest lattice keeps no decomp target: a decomposed base is
        ;; always program-declared (the synthesis requires its declaration),
        ;; so it never reaches this keep-alive path
        [`(lat ,_ ,arity ,spec)
         `(lattice ,name ,arity ,(cdr spec) #f ,(range arity))])))

  (define include-block
    (string-append "\n"
                   "#include \"../daemon/daemon.h\"\n"
                   "#include \"../daemon/operators.h\"\n"
                   "\n\n"))
  ;; the single definitions (spine) and the matching extern declarations (parts)
  (define const-defs
    (apply string-append
           (for/list ([(v g) (in-hash constants)]) (format "u64 v_~a;\n" g))))
  (define const-externs
    (apply string-append
           (for/list ([(v g) (in-hash constants)]) (format "extern u64 v_~a;\n" g))))
  (define const-init
    (apply string-append
           (for/list ([(v g) (in-hash constants)])
             (match v
               ;; encodeString, not str_encode: a >threshold literal must
               ;; intern as a rope, or it forks from computed equal content
               ;; (the docs/sequences.md §6 normalization keystone)
               [(? string?) (format "  v_~a = db->encodeString(\"~a\");\n" g (escape-c-string-literal v))]
               ;; out-of-s32-range literals intern as bignums at plugin load,
               ;; mirroring the string arm above for the same reason: they
               ;; must dedup with computed equal values (primitives.md §14.2)
               [(? exact-integer?)
                (if (and (>= v (- (expt 2 31))) (< v (expt 2 31)))
                    (format "  v_~a = s32_encode(~a);\n" g v)
                    ;; a literal the caps reject would otherwise smuggle
                    ;; slog_error into facts as a stored word -- fail loudly
                    (format (string-append
                             "  v_~a = db->encodeIntLiteral(\"~a\");\n"
                             "  if (v_~a == slog_error) slog::fatal(\"bignum literal"
                             " exceeds the mpz caps (SLOG_MPZ_MAX_BITS /"
                             " SLOG_MPZ_TABLE_BYTES)\");\n")
                            g v g))]
               [(? inexact-real?) (format "  v_~a = float_encode(~a);\n" g v)]))))
  ;; the interned-constant global names -- the only value symbols shared across
  ;; TUs, so canonicalize-vrefs must leave them alone (P2)
  (define const-names (for/list ([(v g) (in-hash constants)]) g))
  ;; Every daemon-registered name this stratum emits (relations, structs,
  ;; lattices, temps, oracle/seqindex bases).  canonicalize-vrefs must leave
  ;; these string literals untouched so a `v_`-prefixed name (a user table like
  ;; v_maybelist) resolves to the SAME name in the declaring spine TU and in the
  ;; cluster TUs that read/write it -- otherwise getRelation returns null and the
  ;; daemon segfaults at stratum load (canonicalize-vrefs comment).
  (define rel-name-tokens
    (for/list ([d (in-list (append decls manifest-decls))]) (symbol->string (second d))))
  ;; A cluster externs only the constants IT references (found in its body text),
  ;; not all of them -- otherwise editing any one constant would change every
  ;; cluster's extern block and defeat the per-.o cache (P2).
  (define (used-const-externs body)
    (define present (list->set (regexp-match* #px"\\bv_[A-Za-z0-9_]+" body)))
    (apply string-append
           (for/list ([g (in-list (sort const-names symbol<?))]
                      #:when (set-member? present (format "v_~a" g)))
             (format "extern u64 v_~a;\n" g))))
  (define dynrel-meta
    (apply string-append
           (for/list ([rel (in-list (sort (set->list dynamic-rels)
                                          string<? #:key symbol->string))])
             (format "  s->addDynamicRel(\"~a\");\n" rel))))
  ;; Canonical operational-IR reads, recorded on the runtime stratum instance
  ;; so historical recount can rebind by exact VersionId rather than by a
  ;; reconstructed name/position environment.
  (define read-rels
    (for/fold ([acc (set)]) ([cr (in-list crules)])
      (define with-driver
        (match (crule-driver cr)
          [`(,(or 'scan 'probe) ,name ,_ ...) (set-add acc name)]
          [_ acc]))
      (for/fold ([a with-driver]) ([op (in-list (append (crule-pre cr)
                                                        (crule-body cr)))])
        (if (memq (car op) '(join join-old join-new join-lat exists absent absent-lat))
            (set-add a (second op))
            a))))
  (define readrel-meta
    (apply string-append
           (for/list ([rel (in-list (sort (set->list read-rels)
                                          string<? #:key symbol->string))])
             (format "  s->addReadRel(\"~a\");\n" rel))))
  ;; accelerator-seed relations (db-compression.md §4.4 v2): the daemon
  ;; samples these rels' per-round deltas into the seed sidecar; declared
  ;; per-stratum exactly like the dynamic-rel manifest above.  NEVER in the
  ;; _count flavor: its per-round deltas are count contributions, and
  ;; sampling those as replay seeds would corrupt the accel sidecar.
  (define accelrel-meta
    (if (count-flavor)
        ""
        (apply string-append
               (for/list ([rel (in-list accel-rels)])
                 (format "  s->addAccelRel(\"~a\");\n" rel)))))
  ;; _count flavor: the counted heads -- every crule sink target (emit/
  ;; mkstruct heads, tycheck's malformed_deduction) plus the declared
  ;; runtime-error arms (a fallible prim's side channel, §8B.4) -- get a
  ;; CountTask/CountStructTask in place of their intern task.
  (define counted-heads
    (if (not (count-flavor))
        (set)
        (let ([declared (for/set ([d (in-list decls)]) (second d))])
          (for*/fold ([acc (if (maintenance-flavor)
                               (set)
                               (for/set ([a (in-list prim-error-arms)]
                                         #:when (set-member? declared a))
                                 a))])
                     ([cr (in-list crules)]
                      [hop (in-list (crule-head cr))])
            (match hop
              [`(mkstruct ,name ,_ ,_ ,_ ...) (set-add acc name)]
              [`(emit ,name ,_ ,_ ...) (set-add acc name)]
              [`(tycheck ,_ ,_ ,_ ,_ ,_ ,_) (set-add acc 'malformed_deduction)]
              [_ acc])))))
  (define emit-rule (add-rule dynamic-rels))

  ;; slog_plugin's body, given the block that registers the read tasks (inline
  ;; for one TU; a sequence of part-function calls when split).
  (define (plugin-body register-reads)
    ;; computed here (not eagerly) so its index-ordering elocals fall under the
    ;; caller's per-TU emit-local-counter (P2 determinism)
    (define rel-decls
      (apply string-append
             (map (add-rel-decl counted-heads) (append decls manifest-decls))))
    (string-append
     "extern \"C\" void slog_plugin(slog::Daemon* d)\n{\n"
     "  slog::Database* db = d->db();\n"
     ;; beginStratum first: it performs the deferred between-strata reload, so
     ;; the index registrations below happen against the reloaded database.
     ;; The delta-entry flavor (docs/incremental.md 0.B5) registers under
     ;; beginStratumDelta instead: NO reload -- the staged batch is the
     ;; coming run's whole iteration-0 delta, and every live index survives.
     ;; The _count flavor (§8B.1) shares beginStratumDelta: the count round
     ;; runs OVER the resident settled fixpoint (a reload would both count
     ;; the restaged rows and leave the full indices empty at iteration 0's
     ;; read); fresh orderings are backfilled at registration.
     (format "  slog::Stratum* s = d->beginStratum~a(\"~a\");\n"
             (if (or (delta-entry-flavor) (count-flavor)
                     (maintenance-flavor)) "Delta" "")
             stratum-name)
     ;; null (and an emitted error) if a stratum is suspended and this is not a
     ;; hot-swap upgrade; bail before touching s (docs/pausing.md §4 guardrail)
     "  if (s == nullptr) return;\n"
     "  slog::Relation* r;\n"
     const-init
     rel-decls
     register-reads
     readrel-meta
     dynrel-meta
     accelrel-meta
     "  d->push(s);\n"
     ;; one bounded unit of work (docs/pausing.md §5); the client drives the
     ;; continue loop until this stratum's (fixpoint ...) via (continue ...) actions
     "  d->continueRun();\n"
     "}\n\n"))

  ;; Each translation unit is emitted under a FRESH per-TU emit-local-counter
  ;; (deterministic names) and then value-ref-canonicalized, so its text is a
  ;; pure function of its rules -- byte-reproducible, hence content-addressable
  ;; for the per-.o cache (P2).  `tu` wraps both.
  (define (tu thunk) (canonicalize-vrefs (parameterize ([emit-local-counter (box 0)]) (thunk))
                                         const-names rel-name-tokens))
  (cond
    ;; Single TU (the common case): read tasks emitted inline in slog_plugin.
    [(<= (length crules) chunk-size)
     (tu (lambda ()
           (string-append include-block const-defs "\n\n"
                          (plugin-body (apply string-append (map emit-rule crules))))))]
    ;; Split: spine + content-addressed cluster TUs (docs/fast-compile.md P2).
    [else
     ;; per-crule identity: the crule emitted ALONE (fresh counter, canonicalized,
     ;; comments stripped) -- position-independent, so bucketing is stable.
     (define (crule-id cr)
       (content-hash (canonicalize-vrefs
                      (parameterize ([emit-local-counter (box 0)]) (emit-rule cr))
                      const-names rel-name-tokens)))
     (define id+crs (for/list ([cr (in-list crules)]) (cons (crule-id cr) cr)))
     ;; bucket by hash mod a power-of-2 N ~= crules/chunk-size: a changed rule
     ;; touches only its own bucket; N shifts only at power-of-2 boundaries.
     (define nbuckets (max 1 (next-pow2 (ceiling (/ (length crules) chunk-size)))))
     (define buckets
       (for/fold ([bs (hash)]) ([ic (in-list id+crs)])
         (hash-update bs (modulo (string->number (car ic) 16) nbuckets)
                      (lambda (l) (cons ic l)) '())))
     ;; each non-empty bucket -> one cluster: its rules ordered by id (stable),
     ;; named by the hash of its emitted body so an unchanged cluster reuses its
     ;; content-addressed .o across stratum versions (tools.rkt does the caching).
     (define clusters
       (for/list ([b (in-list (sort (hash-keys buckets) <))])
         (define ics (sort (hash-ref buckets b) string<? #:key car))
         (define body (tu (lambda () (apply string-append
                                            (map (lambda (ic) (emit-rule (cdr ic))) ics)))))
         (define fn (format "slog_rules_c~a" (content-hash body)))
         (cons fn
               (string-append include-block (used-const-externs body) "\n\n"
                              (format "void ~a(slog::Database* db, slog::Stratum* s)\n{\n" fn)
                              body "}\n\n"))))
     (define fwd-decls
       (apply string-append
              (for/list ([c (in-list clusters)])
                (format "void ~a(slog::Database* db, slog::Stratum* s);\n" (car c)))))
     (define calls
       (apply string-append
              (for/list ([c (in-list clusters)]) (format "  ~a(db, s);\n" (car c)))))
     (define spine
       (cons ""
             (tu (lambda ()
                   (string-append include-block const-defs "\n" fwd-decls "\n\n"
                                  (plugin-body calls))))))
     (cons spine
           (for/list ([c (in-list clusters)] [k (in-naturals 1)])
             (cons (format "p~a" k) (cdr c))))]))
