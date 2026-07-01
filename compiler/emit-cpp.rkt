#lang racket

(provide write-cpp)

(require "utils.rkt")
(require "params.rkt")
(require "primitives.rkt")

(define (repeat s n)
  (if (= n 0)
      ""
      (string-append s (repeat s (- n 1)))))

;; Build the comma-separated "v_a0, v_a1, ..." argument list for a primitive
;; call (prefixed by db at the call site: _prim_NAME(db, <this>)).  "" for none.
(define (prim-arglist args)
  (foldl (lambda (a acc) (format "~a, v_~a" acc a))
         (if (null? args) "" (format "v_~a" (car args)))
         (if (null? args) '() (cdr args))))

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

(define (add-ord-decl ordname ind [indent 0])
  (string-append (repeat " " indent)
                 (format "std::vector<u16> ~a({~a});\n"
                         ordname
                         (foldr (lambda (pos acc) (string-append (~a pos) ", " acc))
                                (~a (last ind))
                                (take ind (sub1 (length ind)))))))

;; Index creation + write-phase tasks for a relation.  Each index becomes an
;; addIndex<A> call and a per-bucket slog::WriteTask<A> (generic, in operators.h)
;; -- no per-relation class is emitted any more.  The first non-delta index's
;; write tasks are kicked off statically (run once); the rest run every iter.
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
    (foldr
     (lambda (indx acc)
       (define delta (eq? 'delta (car indx)))
       (define deltacstr (if delta "true" "false"))
       (define ind (if delta (cdr indx) indx))
       (define A (length ind))  ;; composite-key arity = ordering length
       (define ordering (gensymb 'ord))
       (define ordering-decl (add-ord-decl ordering ind 2))
       (define ord-arr (format "std::array<u16,~a>{~a}" A (string-join (map ~a ind) ", ")))
       (define isstatic (if (and (equal? ind (car indices)) (not delta)) "true" "false"))
       (append
        acc
        (list
         ordering-decl
         (format "r->addIndex<~a>(~a, ~a);" A ordering deltacstr)
         (format "for (u16 b = 0; b < ~a; ++b)" bucket-count)
         (format "  db->addTask(phase_write, new slog::WriteTask<~a>(db, r, ~a, ~a, b), ~a);"
                 A ord-arr deltacstr isstatic))))
     '()
     indices))))

;; The interning task for a relation's master index (its first index, already
;; created by add-write-task): a per-bucket generic slog::InternTask<N> (set
;; semantics) or InternStructTask<N> (content dedup + id assignment).
(define (add-intern-task name intern-ord is-struct)
  (define N (length intern-ord))   ;; master-index composite-key arity
  (define ord-arr (format "std::array<u16,~a>{~a}" N (string-join (map ~a intern-ord) ", ")))
  ((emit-lines 2)
   (format "for (u16 b = 0; b < ~a; ++b)" bucket-count)
   (format "  db->addTask(phase_intern, new slog::Intern~aTask<~a>(db, db->getRelation(\"~a\"), ~a, b));"
           (if is-struct "Struct" "") N name ord-arr)))

;; Adds the relation and its Write and Intern Tasks
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
                    (add-intern-task name (first indices) #f))]))

;; Adds tasks for a rule
(define ((add-rule dynamic-rels) rule)
  (match rule
    [`(crule (let ,(? symbol? letxs) ,(? symbol? letys)) ... ,body* ... --> ,head* ...)

     ;; Emit the rule body as a chain of nested push operators (operators.h),
     ;; each taking the rest of the pipeline as a continuation lambda.  Bound
     ;; vars flow as nested-scope locals; the whole chain fuses at -O2.  This is
     ;; the same loop nest the old string emitter inlined by hand -- loops are
     ;; now operator calls and `continue` (skip-this-tuple) becomes `return`
     ;; from the innermost continuation.
     (define (add-rule-body bodys env head-fun parallelize [indent-len 0])
       (match bodys
         ['() (head-fun indent-len)]
         [`((let ,x ,(? symbol? y)) . ,bodys-rem)
          (string-append
           ((emit-lines indent-len) (format "v_~a = v_~a;" x y))
           (add-rule-body bodys-rem (set-add env x) head-fun parallelize indent-len))]
         [`((let ,x (,name ,args ...)) . ,bodys-rem)
          (string-append
           ((emit-lines indent-len)
            (format "u64 v_~a = _prim_~a(db, ~a);" x name (prim-arglist args)))
           (add-rule-body bodys-rem (set-add env x) head-fun parallelize indent-len))]
         [`((/= ,x ,y) ,bodys-rem ...)
          (string-append
           ((emit-lines indent-len) (format "if (v_~a == v_~a) return;" x y))
           (add-rule-body bodys-rem env head-fun parallelize indent-len))]
         [`((cmp ,fn ,x ,y) ,bodys-rem ...)
          ;; Ordering guard: keep this tuple only if the comparison holds.
          (string-append
           ((emit-lines indent-len) (format "if (!_prim_~a(db, v_~a, v_~a)) return;" fn x y))
           (add-rule-body bodys-rem env head-fun parallelize indent-len))]
         [`((join_with ,_ ,index ,x0 ,xs ...) . ,bodys-rem)
          ;; The chosen index orders the bound (join-key) columns first, so this
          ;; literal's already-bound vars are a prefix of (x0 . xs).  K of them
          ;; are bound; the free (suffix) columns are read off each tuple.
          (define ys (cons x0 xs))
          (define A (length ys))
          (define K (let loop ([l ys] [k 0])
                      (if (and (pair? l) (set-member? env (car l)))
                          (loop (cdr l) (add1 k)) k)))
          (define free (drop ys K))
          (define m (gensymb 'm))
          ;; Bind every free (newly-grounded) column from the matched tuple.
          (define bind-free
            (apply string-append
                   (for/list ([k (in-range K A)])
                     (format "u64 v_~a = ~a[~a]; " (list-ref ys k) m k))))
          ;; Parallel tasks partition by the first free column's bucket so each
          ;; produced tuple is emitted by exactly one task.
          (define par-filter
            (if (and parallelize (pair? free))
                (format "if (buckethash(v_~a) != bucket) return;" (car free))
                ""))
          ;; The env after this join: all of this literal's columns are bound
          ;; (the bound prefix already was; the free suffix is now).
          (define body-env (set-union env (list->set ys)))
          ;; The continuation lambda body: bind free cols, parallel-partition,
          ;; then the rest of the pipeline.
          (define inner
            (string-append
             (if (string=? bind-free "") "" ((emit-lines (+ indent-len 2)) bind-free))
             (if (string=? par-filter "") "" ((emit-lines (+ indent-len 2)) par-filter))
             (add-rule-body bodys-rem body-env head-fun #f (+ indent-len 2))))
          (if (= K 0)
              ;; No bound prefix: cartesian scan over all buckets.
              (string-append
               ((emit-lines indent-len)
                (format "slog::join_all<~a>(~a, [&](const std::array<u64,~a>& ~a) {"
                        A index A m))
               inner
               ((emit-lines indent-len) "});"))
              ;; Bound prefix: probe the bucket holding that lead value and
              ;; range-scan the prefix.
              (let ([key (string-append
                          (format "std::array<u64,~a>{" A)
                          (apply string-append
                                 (add-between
                                  (append (map (lambda (y) (format "v_~a" y)) (take ys K))
                                          (make-list (- A K) "0"))
                                  ", "))
                          "}")])
                (string-append
                 ((emit-lines indent-len)
                  (format "slog::join_probe<~a,~a>(~a, ~a, [&](const std::array<u64,~a>& ~a) {"
                          A K index key A m))
                 inner
                 ((emit-lines indent-len) "});"))))]))

     ;; The innermost continuation: emit each head clause.  Relation/temp heads
     ;; go through the operators.h sink (emit / emit_temp, which do their own
     ;; dedup + batch flush and early-return on a duplicate -- independently per
     ;; head, matching the old per-clause do/while-continue).
     (define (add-rule-head indent-len)
       (car ;; ..throws away head-env
        (foldl
         (lambda (i head-cl head-acc)
           (match-define (cons head-acc-str head-env) head-acc)
           (match head-cl
             [`(let ,x (,name ,args ...))
              (cons (string-append head-acc-str
                                   ((emit-lines indent-len)
                                    (format "u64 v_~a = _prim_~a(db, ~a);"
                                            x name (prim-arglist args))))
                    (set-add head-env x))]
             [`(== ,x ,y)
              (error "value unification (==) heads are not implemented")]
             [`(= ,z0 (,head-name ,head-ord ,zs ...))
              ;; Struct head: A = stored arity (fields + id column).  The sink
              ;; writes the id placeholder and scatters fields via head-ord;
              ;; InternStructTask assigns the real id and dedups (operators.h).
              (define A (add1 (length zs)))
              (cons (string-append
                     head-acc-str
                     ((emit-lines indent-len)
                      (format "slog::emit_struct<~a>(head_rel[~a], newbatch[~a], std::array<u64,~a>{~a}, std::array<u16,~a>{~a});"
                              A i i (length zs)
                              (apply string-append
                                     (add-between (map (lambda (z) (format "v_~a" z)) zs) ", "))
                              A
                              (apply string-append (add-between (map ~a head-ord) ", ")))))
                    (set-add head-env z0))]
             [`(,head-name ,head-ord ,zs ...)
              (define A (length zs))
              (define zs-arr
                (format "std::array<u64,~a>{~a}" A
                        (apply string-append
                               (add-between (map (lambda (z) (format "v_~a" z)) zs) ", "))))
              (cons (string-append
                     head-acc-str
                     (if (null? head-ord)
                         ((emit-lines indent-len)
                          (format "slog::emit_temp<~a>(head_rel[~a], newbatch[~a], ~a);" A i i zs-arr))
                         ((emit-lines indent-len)
                          (format "slog::emit<~a>(head_rel[~a], head_index[~a], newbatch[~a], ~a, std::array<u16,~a>{~a});"
                                  A i i i zs-arr A
                                  (apply string-append
                                         (add-between (map ~a head-ord) ", "))))))
                    head-env)]))
         (cons "" (set))
         (range (length head*))
         head*)))

     (define (add-index-def rel index-name ind [delta #f])
       (define ord-name (gensymb 'ord))
       (define rel-name (gensymb 'readrel))
       (string-append "      "
                      (add-ord-decl ord-name ind)
                      (format "      slog::Relation* ~a = db->getRelation(\"~a\");" rel-name rel)
                      (format "      ~a = ~a->getIndex(~a, ~a);"
                              index-name
                              rel-name
                              ord-name
                              (if delta "true" "false"))))
     (match-define (list body** index-defs index-names)
       (foldr (lambda (body-clause acc)
                (match-define (list bodys defs names) acc)
                (match body-clause
                  [`(/= ,x ,y) (list (cons body-clause bodys) defs names)]
                  [`(cmp ,fn ,x ,y) (list (cons body-clause bodys) defs names)]
                  [`(let ,x ,y) (list (cons body-clause bodys) defs names)]
                  [`(read_delta ,name ,ys ...) (list (cons body-clause bodys) defs names)]
                  [`(join_with ,(and 'delta d) ... ,name ,ind ,ys ...)
                   (define delta (if (null? d) #f #t))
                   (define index-name
                     (gensymb (string->symbol (string-append (symbol->string name) "index"))))
                   (list (cons `(join_with ,name ,index-name ,@ys) bodys)
                         (string-append (add-index-def name index-name ind delta) defs)
                         (cons index-name names))]))
              (list '() "" '())
              body*))

     (define body0
       (match body**
         [`((,(or 'read_delta 'join_with) . ,_) . ,_) (take body** 1)]
         [_ '()]))
     (define bodys
       (if (null? body0)
           body**
           (cdr body**)))

     (define readtask (gensymb 'ReadTask))
     (define real-head-is
       (foldr (lambda (cl i is)
                (match cl
                  [`(let ,_ ...) is]
                  [_ (cons i is)]))
              '()
              head*
              (range (length head*))))

     ((emit-lines 2)
      (format "// ~a" rule)
      (format "class ~a : public slog::Task" readtask)
      (format "{")
      (format "  slog::Database* db;")
      (format "  u16 bucket;")
      (format "  slog::Relation* head_rel[~a];" (length head*))
      (format "  slog::Index** head_index[~a];" (length head*))
      (format "  slog::Relation* outer_rel;")
      (foldl (lambda (index-name acc) (string-append acc (format "  slog::Index** ~a;" index-name)))
             ""
             index-names)
      (format "public:")
      (format "  ~a(slog::Database* _db, u16 _b) : db(_db), bucket(_b)" readtask)
      (format "  {")
      (foldl
       (lambda (head-cl i acc)
         (match head-cl
           [`(let ,x ,y) acc]
           [`(= ,_ (,head-name ,head-ord ,_ ...))
            ;; Struct head: emit_struct needs only head_rel (dedup/id lives in
            ;; the intern phase), so no head_index lookup is set up here.
            (string-append acc
                           (format "    head_rel[~a] = db->getRelation(\"~a\");\n" i head-name))]
           [`(,head-name () ,_ ...)
            (string-append acc (format "    head_rel[~a] = db->getRelation(\"~a\");\n" i head-name))]
           [`(,head-name ,head-ord ,_ ...)
            (string-append acc
                           (format "    head_rel[~a] = db->getRelation(\"~a\");\n" i head-name)
                           (add-index-def head-name (format "head_index[~a]" i) head-ord))]))
       ""
       head*
       (range (length head*)))
      (if (and (not (null? body0)) (eq? (caar body0) 'read_delta))
          (format "      outer_rel = db->getRelation(\"~a\");" (second (car body0)))
          "")
      index-defs
      (format "  }")
      (format "  virtual void work()")
      (format "  {")
      (if (null? body0) ;; todo change this to static task?
          (format "    if (db->getIterationCount() > ~a) return;" (length head*))
          "")
      (format "    slog::InsertBatch* newbatch[~a];" (length head*))
      (foldl (lambda (i acc)
               (string-append acc (format "    newbatch[~a] = new slog::InsertBatch();" i)))
             ""
             real-head-is)
      (foldl (lambda (x y acc) (string-append acc (format "    u64 v_~a = v_~a;" x y)))
             ""
             letxs
             letys)
      (match body0
        [`((join_with ,name ,body0ind ,xs ...))
         (add-rule-body (append body0 bodys) (list->set letxs) add-rule-head #t 6)]
        [`((read_delta ,name ,xs ...))
         (match-define (cons xs+ implicit-eq) ;; when you have e.g. (read_delta name x y y z)
           (foldr (lambda (x acc)
                    (match-define (cons xs+ h) acc)
                    (define gx (gensymb 'eq))
                    (if (member x xs+)
                        (cons (cons gx xs+) (hash-set h gx x))
                        (cons (cons x xs+) h)))
                  (cons '() (hash))
                  xs))
         ;; SOURCE operator: drive the pipeline from this task's pre-bucketized
         ;; delta partition (refs into delta, all worker threads' buffers).  Bind
         ;; each column to a local; for repeated vars (e.g. read_delta n x y y z)
         ;; bind a fresh local and add an equality filter (skip => return).
         (string-append
          ((emit-lines 4)
           "slog::read_delta(outer_rel, bucket, db->getThreadCount(), [&](const u64* _t) {")
          (apply (emit-lines 6)
                 (map (lambda (x n) (format "u64 v_~a = _t[~a];" x n))
                      xs+ (range (length xs))))
          (apply (emit-lines 6)
                 (map (lambda (kv) (format "if (v_~a != v_~a) return;" (car kv) (cdr kv)))
                      (hash->list implicit-eq)))
          (add-rule-body bodys (list->set (append xs letxs)) add-rule-head #f 6)
          ((emit-lines 4) "});"))]
        ['() (add-rule-body bodys (list->set letxs) add-rule-head #f 4)])
      (foldl (lambda (i acc)
               (string-append acc "      " (format "head_rel[~a]->sendBatch(newbatch[~a]);\n" i i)))
             ""
             real-head-is)
      (format "    }")
      (format "  };")
      (format "  for (u16 b = 0; b < ~a; ++b)" (if (null? body0) 1 bucket-count))
      (format
       "    db->addTask(phase_read, new ~a(db,b), ~a);"
       readtask
       ;; is a static task if its kicked off by a static rel
       (if (or (null? body0) (set-member? dynamic-rels (second (car body0)))) "false" "true")))]))

;; Takes a compiled program and writes the cpp file to a string
(define (write-cpp program dbmanifest)
  (define dynamic-rels (first program))
  (define constants (second program))
  (define rel-list
    (filter (lambda (x)
              (match x
                [`(,(or 'struct 'relation 'temp) ,_ ...) #t]
                [_ #f]))
            program))
  (define rel-map
    (foldl (lambda (r h)
             (match r
               [`(,(or 'struct 'relation 'temp) ,name ,_ ...)
                (if (hash-has-key? h name)
                    (error "Duplicate Relation.")
                    (hash-set h name r))]
               [_ (error "Bad relation.")]))
           (hash)
           rel-list))
  (define rel-list+
    (foldl
     (lambda (name rel-list+)
       (if (hash-has-key? rel-map name)
           rel-list+
           (cons (match (hash-ref dbmanifest name)
                   [`(rel ,_ ,arity) `(relation ,name ,arity ,(range arity))]
                   [`(struct ,_ ,arity) `(struct ,name ,arity (,@(range 1 arity) 0) ,(range arity))])
                 rel-list+)))
     rel-list
     (hash-keys dbmanifest)))
  (define rules-list
    (filter (lambda (x)
              (match x
                [`(crule ,_ ...) #t]
                [_ #f]))
            program))
  (string-append
   "\n"
   "#include \"../daemon/slogd.h\"\n"
   "#include \"../daemon/operators.h\"\n"
   "\n\n"
   ;; Declare constants as global variables
   (foldl (lambda (cv s) (format "~a u64 v_~a;\n" s (hash-ref constants cv)))
          ""
          (hash-keys constants))
   "\n\n"
   "extern \"C\" void loadProgram(slog::Database* db)\n{\n"
   "  slog::Relation* r;\n"
   ;; Initialize global constants
   (foldl (lambda (cv s)
            (string-append
             s
             (match cv
               [(? string?) (format "  v_~a = str_encode(db,\"~a\");\n" (hash-ref constants cv) cv)]
               [(? exact-integer?) (format "  v_~a = s32_encode(~a);\n" (hash-ref constants cv) cv)]
               [(? inexact-real?)
                (format "  v_~a = float_encode(~a);\n" (hash-ref constants cv) cv)])))
          ""
          (hash-keys constants))
   ;; Setup Write and Intern task classes for relation/struct decls
   (foldr string-append "" (map add-rel-decl rel-list+))
   ;; Setup Read task classes for program rules
   (foldr string-append "" (map (add-rule dynamic-rels) rules-list))
   "}\n\n"))
