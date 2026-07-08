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

(define (repeat s n)
  (if (= n 0)
      ""
      (string-append s (repeat s (- n 1)))))

;; Render a primitive call: _prim_NAME(db, v_a0, ...) -- nullary primitives
;; (the lattice constants (one)/(inf)/(top)) take only db.
(define (prim-call f args)
  (define al (string-join (map (lambda (a) (format "v_~a" a)) args) ", "))
  (format "_prim_~a(db~a)" f (if (string=? al "") "" (string-append ", " al))))

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
      (define ind (if delta (cdr indx) indx))
      (define A (length ind))  ;; composite-key arity = ordering length
      (define ordering (gensymb 'ord))
      (define isstatic (if (and (equal? indx (car indices)) (not delta)) "true" "false"))
      (append
       (list
        (format "  s->addTask(phase_write, new slog::WriteTask<~a>(db, r, ~a, ~a, b), ~a);"
                A (u16-array-lit ind) (if delta "true" "false") isstatic)
        (format "for (u16 b = 0; b < ~a; ++b)" bucket-count)
        (format "r->addIndex<~a>(~a, ~a);" A ordering (if delta "true" "false"))
        (add-ord-decl ordering ind 2))
       lines)))))

;; The interning task for a relation's master index (its first index, already
;; created by add-write-task): a per-bucket generic slog::InternTask<N> (set
;; semantics) or InternStructTask<N> (content dedup + id assignment).
(define (add-intern-task name intern-ord is-struct)
  (define N (length intern-ord))
  ((emit-lines 2)
   (format "for (u16 b = 0; b < ~a; ++b)" bucket-count)
   (format "  s->addTask(phase_intern, new slog::Intern~aTask<~a>(db, db->getRelation(\"~a\"), ~a, b));"
           (if is-struct "Struct" "") N name (u16-array-lit intern-ord))))

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

(define (add-lattice-decl name arity spec indices)
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
       (define ordering (gensymb 'ord))
       (define isstatic (if (and (equal? indx master) (not delta)) "true" "false"))
       (append
        (if delta
            (list
             (format "  s->addTask(phase_write, new slog::WriteTask<~a>(db, r, ~a, true, b), false);"
                     A (u16-array-lit ind))
             (format "for (u16 b = 0; b < ~a; ++b)" bucket-count)
             (format "r->addIndex<~a>(~a, true);" A ordering)
             (add-ord-decl ordering ind 2))
            (list
             (format "  s->addTask(phase_write, new slog::MapWriteTask<~a>(db, r, ~a, b), ~a);"
                     A (u16-array-lit ind) isstatic)
             (format "for (u16 b = 0; b < ~a; ++b)" bucket-count)
             (format "r->addMapIndex<~a>(~a);" A ordering)
             (add-ord-decl ordering ind 2)))
        lines))))
   "\n"
   ((emit-lines 2)
    (format "for (u16 b = 0; b < ~a; ++b)" bucket-count)
    (format "  s->addTask(phase_intern, new slog::LatticeInternTask<~a>(db, db->getRelation(\"~a\"), ~a, b));"
            arity name (u16-array-lit master)))))

(define (add-rel-decl rel)
  (match rel
    [`(temp ,name ,arity)
     ((emit-lines 2)
      (format "r = db->getRelation(\"~a\");" name)
      (format "if (r == 0) db->addRelation(\"~a\", ~a);" name arity)
      (format "else if (r->getArity() != ~a) slog::fatal(\"Temp rel arity mismatch.\");" arity))]
    [`(struct ,name ,arity ,indices ...)
     (when (or (not (> (length indices) 1))
               (not (equal? (last (first indices)) 0))
               (not (equal? (first (second indices)) 0)))
       (error (format "Struct ~a does not have required indices in ~a" name indices)))
     (string-append (add-write-task name arity indices #t)
                    "\n"
                    (add-intern-task name (first indices) #t))]
    [`(relation ,name ,arity ,indices ...)
     (when (null? indices)
       (error (format "Table ~a does not have any indices." name)))
     (string-append (add-write-task name arity indices #f)
                    "\n"
                    (add-intern-task name (first indices) #f))]
    [`(lattice ,name ,arity ,spec ,indices ...)
     (when (or (null? indices) (eq? 'delta (car (first indices))))
       (error (format "Lattice relation ~a must lead with a non-delta (master) index: ~a"
                      name indices)))
     (add-lattice-decl name arity spec indices)]))

;; -----------------------------------------------------------------------
;; Rules.

;; A member declaration + constructor lookup for one index.
(define (index-member name member ind delta)
  (define ord-name (gensymb 'ord))
  (define rel-name (gensymb 'readrel))
  (string-append "    "
                 (add-ord-decl ord-name ind)
                 (format "    slog::Relation* ~a = db->getRelation(\"~a\");\n" rel-name name)
                 (format "    ~a = ~a->getIndex(~a, ~a);"
                         member rel-name ord-name (if delta "true" "false"))))

;; Emit the ops of a rule body (after the driver), innermost continuation
;; last.  Each join op opens a nested continuation lambda; other ops are
;; straight-line statements.  `index-name-of` maps a join op to its member.
(define (emit-ops ops index-name-of head-fun indent)
  (match ops
    ['() (head-fun indent)]
    [`(,(and op `(join ,name ,ind ,K ,ys ...)) . ,rest)
     (define A (length ys))
     (define free (drop ys K))
     (define m (gensymb 'm))
     (define bind-free
       (string-join (for/list ([k (in-range K A)])
                      (format "u64 v_~a = ~a[~a];" (list-ref ys k) m k))
                    " "))
     (define inner
       (string-append
        (if (string=? bind-free "") "" ((emit-lines (+ indent 2)) bind-free))
        (emit-ops rest index-name-of head-fun (+ indent 2))))
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
      (emit-ops rest index-name-of head-fun indent))]
    [`(,(and op `(join-lat ,name ,ind ,K ,ys ...)) . ,rest)
     (define KA (sub1 (length ys)))          ; key columns; last var is the value
     (define vvar (last ys))
     (define m (gensymb 'm))
     (define vparam (gensymb 'val))
     (define bind-free
       (string-join (append
                     (for/list ([k (in-range K KA)])
                       (format "u64 v_~a = ~a[~a];" (list-ref ys k) m k))
                     (list (format "u64 v_~a = ~a;" vvar vparam)))
                    " "))
     (define inner
       (string-append
        ((emit-lines (+ indent 2)) bind-free)
        (emit-ops rest index-name-of head-fun (+ indent 2))))
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
      (emit-ops rest index-name-of head-fun indent))]))

;; Straight-line (non-join) ops; `return` skips the current tuple.
(define (emit-straight-op op)
  (match op
    [`(let ,x ,(? symbol? y)) (format "u64 v_~a = v_~a;" x y)]
    [`(let ,x (,f ,args ...))
     (format "u64 v_~a = ~a;" x (prim-call f args))]
    [`(eq ,x ,y) (format "if (v_~a != v_~a) return;" x y)]
    [`(neq ,x ,y) (format "if (v_~a == v_~a) return;" x y)]
    [`(cmp ,fn ,x ,y) (format "if (!_prim_~a(db, v_~a, v_~a)) return;" fn x y)]))

;; Pre-ops run at the top of work() (not inside a driver lambda), so a failing
;; constant guard aborts the WHOLE task -- and since work() now returns bool
;; (docs/pausing.md §3), that abort is `return true;` (task finished, produced
;; nothing), not the tuple-skipping `return;` of a body op.
(define (emit-pre-op op)
  (match op
    [`(let ,x ,(? symbol? y)) (format "u64 v_~a = v_~a;" x y)]
    [`(let ,x (,f ,args ...))
     (format "u64 v_~a = ~a;" x (prim-call f args))]
    [`(eq ,x ,y) (format "if (v_~a != v_~a) return true;" x y)]
    [`(neq ,x ,y) (format "if (v_~a == v_~a) return true;" x y)]
    [`(cmp ,fn ,x ,y) (format "if (!_prim_~a(db, v_~a, v_~a)) return true;" fn x y)]))

;; The innermost continuation: emit each head op.  emit/emit_temp sinks do
;; their own dedup + batch flush (operators.h); emit_struct leaves dedup and
;; id assignment to the intern phase.  tycheck hops always precede the
;; emitting hops (operationalization.rkt), so their guards protect every
;; sink of the rule; `sid-members` maps a struct name in an accept set to
;; the task's u32 member holding its runtime struct id.
(define ((emit-heads heads sid-members) indent)
  (apply string-append
         (for/list ([hop (in-list heads)] [i (in-naturals)])
           (match hop
             [`(let ,x (,f ,args ...))
              ((emit-lines indent)
               (format "u64 v_~a = ~a;" x (prim-call f args)))]
             ;; a residual type check: if the value's surface tag matches no
             ;; accepted type, divert -- intern a malformed_deduction struct
             ;; (rule-location, relation, column, bad value) in place of the
             ;; deduction and abandon the tuple (`return` = old `continue`)
             [`(tycheck ,y (accept ,ts ...) ,rid ,rel ,colv ,ind)
              (define prim-tests
                (for/list ([t (in-list ts)] #:when (symbol? t))
                  (format (match t
                            ['int "is_s32(v_~a)"]
                            ['float "is_float(v_~a)"]
                            ['str "is_str(v_~a)"]
                            ['cnode "is_cnode(v_~a)"])
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
               (format "  slog::emit_struct<5>(head_rel[~a], newbatch[~a], ~a, ~a);"
                       i i
                       (u64-array-lit (map (lambda (z) (format "v_~a" z))
                                           (list rid rel colv y)))
                       (u16-array-lit ind))
               "  return;"
               "}")]
             [`(mkstruct ,name ,ind ,x ,fields ...)
              ((emit-lines indent)
               (format "slog::emit_struct<~a>(head_rel[~a], newbatch[~a], ~a, ~a);"
                       (length ind) i i
                       (u64-array-lit (map (lambda (z) (format "v_~a" z)) fields))
                       (u16-array-lit ind)))]
             [`(emit ,name ,ind ,zs ...)
              ((emit-lines indent)
               (format "slog::emit<~a>(head_rel[~a], head_index[~a], newbatch[~a], ~a, ~a);"
                       (length zs) i i i
                       (u64-array-lit (map (lambda (z) (format "v_~a" z)) zs))
                       (u16-array-lit ind)))]
             [`(emit-temp ,name ,zs ...)
              ((emit-lines indent)
               (format "slog::emit_temp<~a>(head_rel[~a], newbatch[~a], ~a);"
                       (length zs) i i
                       (u64-array-lit (map (lambda (z) (format "v_~a" z)) zs))))]
             ;; a lattice contribution: nominal order, no dedup (the merge
             ;; task owns subsumption) -- the emit_temp sink is exactly that
             [`(emit-lat ,name ,zs ...)
              ((emit-lines indent)
               (format "slog::emit_temp<~a>(head_rel[~a], newbatch[~a], ~a);"
                       (length zs) i i
                       (u64-array-lit (map (lambda (z) (format "v_~a" z)) zs))))]))))

(define ((add-rule dynamic-rels) crule)
  (define pre (crule-pre crule))
  (define driver (crule-driver crule))
  (define body (crule-body crule))
  (define heads (crule-head crule))

  ;; name the index member for the driver probe, each body join, and each
  ;; semijoin filter's existence probe
  (define join-members
    (for/list ([op (in-list body)] #:when (memq (car op) '(join join-lat exists)))
      (cons op (gensymb (string->symbol (format "~aindex" (second op)))))))
  (define (index-name-of op)
    (cdr (assq op join-members)))

  (define driver-rel
    (match driver
      [`(once) #f]
      [`(,_ ,name ,_ ...) name]))
  (define static?
    (or (not driver-rel) (not (set-member? dynamic-rels driver-rel))))

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
           (if (hash-has-key? h n) h (hash-set h n (gensymb 'sid)))]
          [_ h]))))
  (define sid-members-sorted
    (sort (hash->list sid-members) symbol<? #:key car))

  (define task-name (gensymb 'ReadTask))

  ;; --- constructor body: look up head relations/indices and join indices
  (define ctor-body
    (string-append
     (apply string-append
            (for/list ([hop (in-list heads)] [i (in-naturals)])
              (match hop
                [`(let ,_ ,_) ""]
                [`(tycheck ,_ ,_ ,_ ,_ ,_ ,_)
                 (format "    head_rel[~a] = db->getRelation(\"malformed_deduction\");\n" i)]
                [`(mkstruct ,name ,_ ,_ ,_ ...)
                 (format "    head_rel[~a] = db->getRelation(\"~a\");\n" i name)]
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
       [`(once) ""])
     (apply string-append
            (for/list ([om (in-list join-members)])
              (match (car om)
                [`(,(or 'join 'join-lat 'exists) ,name ,ind ,_ ...)
                 (string-append (index-member name (cdr om) ind #f) "\n")])))
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
      [`(once) 'none]))
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

  (define pipeline
    (match driver
      [`(once)
       (emit-ops body index-name-of (emit-heads heads sid-members) 4)]
      [`(scan ,name ,xs ...)
       (string-append
        slice-ctx-setup
        ((emit-lines 4)
         "u32 _rt = resume_t, _ri = resume_i;"
         "bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {")
        (apply (emit-lines 6)
               (for/list ([x (in-list xs)] [n (in-naturals)])
                 (format "u64 v_~a = _t[~a];" x n)))
        (emit-ops body index-name-of (emit-heads heads sid-members) 6)
        ((emit-lines 4) "});"))]
      [`(probe ,name ,ind ,K ,ys ...)
       (define A (length ys))
       (define free (drop ys K))
       (define m (gensymb 'm))
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
          (emit-ops body index-name-of (emit-heads heads sid-members) 6)))
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
          (map (lambda (om) (format "  slog::Index** ~a;" (cdr om))) join-members))
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
   (apply (emit-lines 4) (map emit-pre-op pre))
   (format "    slog::InsertBatch* newbatch[~a];" (max 1 (length heads)))
   alloc-batches
   pipeline
   send-batches
   work-tail
   (format "  }")
   (format "  };")
   (format "  for (u16 b = 0; b < ~a; ++b)" nbuckets)
   (format "    s->addTask(phase_read, new ~a(db,b), ~a);"
           task-name
           (if static? "true" "false"))))

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
(define (write-cpp cprog dbmanifest stratum-name)
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
        [`(lat ,_ ,arity ,spec)
         `(lattice ,name ,arity ,(cdr spec) ,(range arity))])))

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
               [(? string?) (format "  v_~a = str_encode(db,\"~a\");\n" g v)]
               [(? exact-integer?) (format "  v_~a = s32_encode(~a);\n" g v)]
               [(? inexact-real?) (format "  v_~a = float_encode(~a);\n" g v)]))))
  (define rel-decls
    (apply string-append (map add-rel-decl (append decls manifest-decls))))
  (define dynrel-meta
    (apply string-append
           (for/list ([rel (in-list (sort (set->list dynamic-rels)
                                          string<? #:key symbol->string))])
             (format "  s->addDynamicRel(\"~a\");\n" rel))))
  (define emit-rule (add-rule dynamic-rels))
  (define (part-fn k) (format "slog_rules_~a_~a" stratum-name k))

  ;; slog_plugin's body, given the block that registers the read tasks (inline
  ;; for one TU; a sequence of part-function calls when split).
  (define (plugin-body register-reads)
    (string-append
     "extern \"C\" void slog_plugin(slog::Daemon* d)\n{\n"
     "  slog::Database* db = d->db();\n"
     ;; beginStratum first: it performs the deferred between-strata reload, so
     ;; the index registrations below happen against the reloaded database
     (format "  slog::Stratum* s = d->beginStratum(\"~a\");\n" stratum-name)
     ;; null (and an emitted error) if a stratum is suspended and this is not a
     ;; hot-swap upgrade; bail before touching s (docs/pausing.md §4 guardrail)
     "  if (s == nullptr) return;\n"
     "  slog::Relation* r;\n"
     const-init
     rel-decls
     register-reads
     dynrel-meta
     "  d->push(s);\n"
     ;; one bounded unit of work (docs/pausing.md §5); the client drives the
     ;; continue loop until this stratum's (fixpoint ...) via (continue ...) actions
     "  d->continueRun();\n"
     "}\n\n"))

  (cond
    ;; Single TU (the common case): read tasks emitted inline in slog_plugin.
    [(<= (length crules) chunk-size)
     (string-append include-block const-defs "\n\n"
                    (plugin-body (apply string-append (map emit-rule crules))))]
    ;; Split: spine + part TUs (docs/fast-compile.md §6).
    [else
     (define chunks (chunk-list crules chunk-size))
     (define nparts (length chunks))
     (define fwd-decls
       (apply string-append
              (for/list ([k (in-range 1 (add1 nparts))])
                (format "void ~a(slog::Database* db, slog::Stratum* s);\n" (part-fn k)))))
     (define calls
       (apply string-append
              (for/list ([k (in-range 1 (add1 nparts))])
                (format "  ~a(db, s);\n" (part-fn k)))))
     (define spine
       (cons ""
             (string-append include-block const-defs "\n" fwd-decls "\n\n"
                            (plugin-body calls))))
     (define parts
       (for/list ([chunk (in-list chunks)] [k (in-naturals 1)])
         (cons (format "p~a" k)
               (string-append include-block const-externs "\n\n"
                              (format "void ~a(slog::Database* db, slog::Stratum* s)\n{\n"
                                      (part-fn k))
                              (apply string-append (map emit-rule chunk))
                              "}\n\n"))))
     (cons spine parts)]))
