#lang racket

(provide write-cpp)

(require "utils.rkt")
(require "params.rkt")
(require "primitives.rkt")

(define (repeat s n)
  (if (= n 0)
      ""
      (string-append s (repeat s (- n 1)))))

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

;; Initializes and adds write, receieve, and intern tasks for a relation
(define (add-write-task name arity indices is-struct)
  ((emit-lines 2)
   (format "r = db->getRelation(\"~a\");" name)
   (format "if (r == 0) db->add~a(\"~a\", ~a);" (if is-struct 'Struct 'Relation) name arity)
   (format "else if (r->getArity() != ~a)" arity)
   "  slog::fatal(\"Relation already exists at incorrect arity.\");"
   (apply
    (emit-lines 2)
    (foldr
     (lambda (indx acc)
       (define writetask (gensymb 'WriteTask))
       (define delta (eq? 'delta (car indx)))
       (define deltacstr (if delta "true" "false"))
       (define ind
         (if delta
             (cdr indx)
             indx))
       (define A (length ind))  ;; composite-key arity = ordering length
       (define key-init
         (string-append
          "{"
          (apply string-append
                 (add-between (map (lambda (p) (format "batch->data[j+~a]" p)) ind) ", "))
          "}"))
       (define ordering (gensymb 'ord))
       (define ordering-decl (add-ord-decl ordering ind 2))
       (append
        acc
        (list
         ordering-decl
         (format "db->getRelation(\"~a\")->addIndex<~a>(~a, ~a);" name A ordering deltacstr)
         (format "class ~a : public slog::Task" writetask)
         (format "{")
         (format "  slog::Database* db;")
         (format "  u16 bucket;")
         (format "  slog::Relation* rel;")
         (format "  slog::BTreeIndex<~a>* root;" A)
         (format "public:")
         (format "  ~a(slog::Database* _db, u16 _b) : db(_db), bucket(_b)" writetask)
         (format "  {")
         (format "  ~a" ordering-decl)
         (format "    rel = db->getRelation(\"~a\");" name)
         (format "    root = static_cast<slog::BTreeIndex<~a>*>(rel->getIndex(~a, ~a)[bucket]);"
                 A ordering deltacstr)
         (format "  }")
         (format "  virtual void work()")
         (format "  {")
         ;; Stage B: iterate only this index's hash bucket (refs into delta),
         ;; instead of scanning the whole delta and filtering by buckethash.
         ;; The reorg is per-thread, so read each thread's bucket in turn.
         ;; Refs already exclude null (deduped) tuples.
         (format "    for (u32 t = 0; t < db->getThreadCount(); ++t)")
         (format "    {")
         (format "    auto& refs = rel->getWriteBucket(t, ~a, bucket);" (first ind))
         (format "    for (u32 r = 0; r < refs.size(); ++r)")
         (format "    {")
         (format "      slog::InsertBatch* batch = refs[r].batch;")
         (format "      u32 j = refs[r].offset;")
         (format "      root->insert(~a);" key-init)
         (format "    }")
         (format "    }")
         (format "  }")
         (format "};")
         (format "for (u16 b = 0; b < ~a; ++b)" bucket-count)
         (format "  db->addTask(phase_write, new ~a(db, b), ~a);"
                 writetask
                 (if (and (equal? ind (car indices)) (not delta)) "true" "false")))))
     '()
     indices))))

(define (add-intern-task name intern-ord is-struct)
  ;; A master index is always populated by an interning task
  (define interntask (gensymb 'InternTask))
  (define ord-name (gensymb 'ord))
  (define ordering-decl (add-ord-decl ord-name intern-ord))
  (define N (length intern-ord))   ;; master-index composite-key arity
  ;; full key (tuple in master-index order); for structs ord[N-1]==0 = the id slot
  (define key-init
    (string-append "{"
      (apply string-append
             (add-between (map (lambda (p) (format "batch->data[j+~a]" p)) intern-ord) ", "))
      "}"))
  ;; struct dedup: range-scan the content prefix (cols 0..N-2), id slot = 0 (min)
  (define content-low
    (string-append "{"
      (apply string-append
             (add-between
              (append (map (lambda (p) (format "batch->data[j+~a]" p)) (take intern-ord (sub1 N)))
                      (list "0"))
              ", "))
      "}"))
  (define struct-prefix-check
    (apply string-append
           (for/list ([k (in-range (sub1 N))])
             (format "          if ((*it)[~a] != batch->data[j+~a]) dup = false;\n"
                     k (list-ref intern-ord k)))))
  ((emit-lines 2)
   (format "class ~a : public slog::Task" interntask)
   (format "{")
   (format "  slog::Database* db;")
   (format "  u16 bucket;")
   (format "  slog::Relation* rel;")
   (format "  slog::BTreeIndex<~a>* root;" N)
   (format "  u64* intern_alloc;")
   (format "  u32 struct_id;")
   (format "public:")
   (format "  ~a(slog::Database* _db, u16 _b) : db(_db), bucket(_b)    {" interntask)
   (format "    ~a" ordering-decl)
   (format "    rel = db->getRelation(\"~a\");" name)
   (format "    root = static_cast<slog::BTreeIndex<~a>*>(rel->getIndex(~a, false)[bucket]);" N ord-name)
   (format "    intern_alloc = rel->getInternAlloc(bucket);")
   (format "    struct_id = rel->getStructId();")
   (format "  }")
   (format "  virtual void work()")
   (format "  {")
   (format "    for (u32 i = 0; i < rel->getDelta().size(); ++i)")
   (format "    {")
   (format "      slog::InsertBatch* batch = rel->getDelta()[i];")
   (format "      for (u32 j = 0; j < batch->usage; j += ~a)" N)
   (format "      {  // The check for null must come second below!")
   (format
    "        if (buckethash(batch->data[j+~a]) != bucket || batch->data[j] == slog_null) continue;"
    (first intern-ord))
   (if is-struct
       ;; struct: dedup by content; assign a fresh id (stored at col 0) when new
       (string-append
        (format "        auto it = root->lower_bound(~a);\n" content-low)
        (format "        bool dup = (it != root->end());\n")
        (format "        if (dup) {\n")
        struct-prefix-check
        (format "        }\n")
        (format "        if (dup) batch->data[j] = slog_null;\n")
        (format "        else {\n")
        (format "          batch->data[j] = struct_encode(struct_id, (*intern_alloc << bucket_bits) | bucket);\n")
        (format "          ++(*intern_alloc);\n")
        (format "          root->insert(~a);\n" key-init)
        (format "        }\n"))
       ;; relation: set-semantics dedup -- drop if already present, else insert
       (string-append
        (format "        if (root->contains(~a)) batch->data[j] = slog_null;\n" key-init)
        (format "        else root->insert(~a);\n" key-init)))
   (format "      }")
   (format "    }")
   (format "  }")
   (format "  };")
   (format "  for (u16 b = 0; b < ~a; ++b)" bucket-count)
   (format "    db->addTask(phase_intern, new ~a(db, b));" interntask)))

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

     (define (add-rule-body bodys env head-fun parallelize [indent-len 0])
       (define indent (repeat " " indent-len))
       (match bodys
         ['() (head-fun indent-len)]
         [`((let ,x ,(? symbol? y)) . ,bodys-rem)
          ((emit-lines indent-len) (format "v_~a = v_~a;" x y)
                                   (add-rule-body bodys-rem (set-add env x) head-fun parallelize))]
         [`((let ,x (,name ,args ...)) . ,bodys-rem)
          ((emit-lines indent-len) (format "u64 v_~a = _prim_~a(db, ~a);"
                                           x
                                           name
                                           (foldl (lambda (a acc) (format "~a, v_~a" acc a))
                                                  (if (null? args)
                                                      ""
                                                      (format "v_~a" (car args)))
                                                  (if (null? args)
                                                      '()
                                                      (cdr args))))
                                   (add-rule-body bodys-rem (set-add env x) head-fun parallelize))]
         [`((/= ,x ,y) ,bodys-rem ...)
          ((emit-lines indent-len) (format "//  (/= ~a ~a)" x y)
                                   (format "if (v_~a == v_~a) continue;" x y)
                                   (add-rule-body bodys-rem env head-fun parallelize))]
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
          (define it (gensymb 'it))
          ;; Bind every free (newly-grounded) column from the matched tuple.
          (define bind-free
            (apply string-append
                   (for/list ([k (in-range K A)])
                     (format "u64 v_~a = (*~a)[~a]; " (list-ref ys k) it k))))
          ;; Parallel tasks partition by the first free column's bucket so each
          ;; produced tuple is emitted by exactly one task.
          (define par-filter
            (if (and parallelize (pair? free))
                (format "if (buckethash(v_~a) != bucket) continue;" (car free))
                ""))
          ;; The env after this join: all of this literal's columns are bound
          ;; (the bound prefix already was; the free suffix is now).
          (define body-env (set-union env (list->set ys)))
          (if (= K 0)
              ;; No bound prefix: this literal shares no variable with the
              ;; grounded set, so it's a full cartesian scan.  Tuples are
              ;; hash-partitioned by their lead column across all buckets, so we
              ;; must iterate every bucket and every tuple -- there is no prefix
              ;; to lower_bound on or to break the range scan against.
              ((emit-lines indent-len)
               "{"
               (format "for (u16 ~a_b = 0; ~a_b < ~a; ++~a_b)" it it bucket-count it)
               "{"
               (format "auto* ~a_idx = static_cast<slog::BTreeIndex<~a>*>(~a[~a_b]);"
                       it A index it)
               (format "for (auto ~a = ~a_idx->begin(); ~a != ~a_idx->end(); ++~a)"
                       it it it it it)
               "{"
               bind-free
               par-filter
               (add-rule-body bodys-rem body-env head-fun #f (+ indent-len 2))
               "}"
               "}"
               "}")
              ;; Bound prefix: probe the single bucket holding that lead-column
              ;; value and range-scan the prefix, breaking once it no longer
              ;; matches.
              (let ([klow
                     (string-append (format "std::array<u64,~a>{" A)
                       (apply string-append
                              (add-between (append (map (lambda (y) (format "v_~a" y)) (take ys K))
                                                   (make-list (- A K) "0"))
                                           ", "))
                       "}")]
                    [prefix-break
                     (apply string-append
                            (add-between (for/list ([k (in-range K)])
                                           (format "(*~a)[~a] != v_~a" it k (list-ref ys k)))
                                         " || "))])
                ((emit-lines indent-len)
                 "{"
                 (format "auto* ~a_idx = static_cast<slog::BTreeIndex<~a>*>(~a[buckethash(v_~a)]);"
                         it A index x0)
                 (format "for (auto ~a = ~a_idx->lower_bound(~a); ~a != ~a_idx->end(); ++~a)"
                         it it klow it it it)
                 "{"
                 (format "if (~a) break;" prefix-break)
                 bind-free
                 par-filter
                 (add-rule-body bodys-rem body-env head-fun #f (+ indent-len 2))
                 "}"
                 "}")))]))

     (define (add-rule-head indent-len)
       (define indent (repeat " " indent-len))
       (car ;; ..throws away head-env
        (foldl
         (lambda (i head-cl head-acc)
           (match-define (cons head-acc-str head-env) head-acc)
           (define (emit-head-for head-name head-ord z0 zs)
             (define head-index (format "head_index[~a]" i))
             (define hxs (filter (lambda (z) (set-member? head-env z)) zs))
             (string-append
              head-acc-str
              indent
              (format "do {  // head clause ~a\n" `(,head-name ,head-ord ,@zs))
              ;; Skip emitting if this exact tuple already exists in the head
              ;; relation (full composite-key lookup in its bucket).
              (if (null? head-ord)
                  ""
                  ((emit-lines indent-len)
                   (format "// Check the head relation before emitting ~a" zs)
                   (format "if (static_cast<slog::BTreeIndex<~a>*>(~a[buckethash(v_~a)])->contains(std::array<u64,~a>{~a})) continue;"
                           (length zs)
                           head-index
                           (car zs)
                           (length zs)
                           (apply string-append
                                  (add-between (map (lambda (z) (format "v_~a" z)) zs) ", ")))))
              ;; save values in appropriate newbatch fields
              ((emit-lines indent-len)
               (format "newbatch[~a]->data[newbatch[~a]->usage] = 0;" i i)
               (let ([head-ord (if (null? head-ord)
                                   (range (length zs))
                                   head-ord)])
                 (foldl (lambda (z j acc)
                          ((emit-lines 0) acc
                                          (format "newbatch[~a]->data[newbatch[~a]->usage+~a] = v_~a;"
                                                  i
                                                  i
                                                  (list-ref head-ord j)
                                                  z)))
                        ""
                        zs
                        (range (length zs))))
               (format "newbatch[~a]->usage += ~a;"
                       i
                       (if (null? head-ord)
                           (length zs)
                           (length head-ord)))
               (format "if (newbatch[~a]->usage + ~a >= batch_size_max)"
                       i
                       (if (null? head-ord)
                           (length zs)
                           (length head-ord)))
               "{"
               (format "  head_rel[~a]->sendBatch(newbatch[~a]);" i i)
               (format "  newbatch[~a] = new slog::InsertBatch();" i)
               "}"
               "} while (false);")))
           (match head-cl
             [`(let ,x (,name ,args ...))
              (cons (string-append head-acc-str
                                   indent
                                   (format "u64 v_~a = _prim_~a(db, ~a);"
                                           x
                                           name
                                           (foldl (lambda (a acc) (format "~a, v_~a" acc a))
                                                  (if (null? args)
                                                      ""
                                                      (format "v_~a" (car args)))
                                                  (if (null? args)
                                                      '()
                                                      (cdr args)))))
                    (set-add head-env x))]
             [`(== ,x ,y)
              (cons (string-append head-acc-str
                                   ((emit-lines indent-len)
                                    (format "unifybatch->data[unifybatch->usage] = v_~a;" x)
                                    (format "unifybatch->data[unifybatch->usage+1] = v_~a;" y)
                                    "unifybatch->usage += 2;"
                                    "if (unifybatch->usage + 2 >= batch_size_max)"
                                    "{"
                                    "  db->sendEqBatch(unifybatch);"
                                    "  unifybatch = new slog::InsertBatch();"
                                    "}"))
                    head-env)]
             [`(= ,z0 (,head-name ,head-ord ,zs ...))
              (cons (emit-head-for head-name head-ord z0 zs) (set-add head-env z0))]
             [`(,head-name ,head-ord ,zs ...)
              (cons (emit-head-for head-name head-ord #f zs) head-env)]))
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
           [`(== ,x ,y) acc]
           [`(= ,_ (,head-name ,head-ord ,_ ...))
            (string-append acc
                           (format "    head_rel[~a] = db->getRelation(\"~a\");\n" i head-name)
                           (add-index-def head-name (format "head_index[~a]" i) head-ord))]
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
      (format "    slog::InsertBatch* unifybatch = new slog::InsertBatch();")
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
         ;; Stage B: iterate this read task's pre-bucketed work partition (refs
         ;; into delta), instead of scanning the whole delta round-robin.  The
         ;; reorg is per-thread, so read each thread's partition in turn.  Refs
         ;; already exclude null (deduped) tuples, so no null/round-robin filter.
         ((emit-lines 4) (format "for (u32 t = 0; t < db->getThreadCount(); ++t)")
                         (format "{")
                         (format "auto& refs = outer_rel->getReadBucket(t, bucket);")
                         (format "for (u32 i = 0; i < refs.size(); ++i)")
                         (format "{")
                         (format "  slog::InsertBatch* batch = refs[i].batch;")
                         (format "  u32 j = refs[i].offset;")
                         (format "  {")
                         (foldr string-append
                                ""
                                (map (lambda (x n) (format "    u64 v_~a = batch->data[j+~a];\n" x n))
                                     xs+
                                     (range 0 (length xs))))
                         (foldr string-append
                                ""
                                (map (lambda (kv)
                                       (format "    if (v_~a != v_~a) continue;" (car kv) (cdr kv)))
                                     (hash->list implicit-eq)))
                         (format "    // Rule body and head")
                         (add-rule-body bodys (list->set (append xs letxs)) add-rule-head #f 4)
                         (format "  }")
                         (format "}")
                         (format "}"))]
        ['() (add-rule-body bodys (list->set letxs) add-rule-head #f 4)])
      (foldl (lambda (i acc)
               (string-append acc "      " (format "head_rel[~a]->sendBatch(newbatch[~a]);\n" i i)))
             ""
             real-head-is)
      (format "      db->sendEqBatch(unifybatch);\n")
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
               [(? integer?) (format "  v_~a = s32_encode(~a);\n" (hash-ref constants cv) cv)]
               [(and (? number?) (? inexact?))
                (format "  v_~a = float_encode(~a);\n" (hash-ref constants cv) cv)])))
          ""
          (hash-keys constants))
   ;; Setup Write and Intern task classes for relation/struct decls
   (foldr string-append "" (map add-rel-decl rel-list+))
   ;; Setup Read task classes for program rules
   (foldr string-append "" (map (add-rule dynamic-rels) rules-list))
   "}\n\n"))
