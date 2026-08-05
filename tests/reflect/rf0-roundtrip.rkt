#lang racket

;; RF0: reflective round trip (docs/slog-reflection.md §15).
;;
;; Empirical probe: convert real canonical-plan sidecars (build/<hash>.plan,
;; written by compiler/canonical-plan.rkt via compile.rkt) into a FLAT
;; relational fact encoding in the spirit of slog-reflection.md §5.2, decode
;; the facts back to the plan term, and prove
;;   (a) byte-identical re-serialization against the original file, and
;;   (b) identical KernelPlanKey (canonical-plan.rkt's kernel-plan-key).
;; For ABI-2 cohorts (RF1 slice 2) the key check is PER KERNEL: every
;; kernel's KernelPlanKey is recomputed from its decoded exec part and must
;; agree with the original's recomputation AND with the manifest's recorded
;; keys.
;;
;; The encoding is genuinely relational: facts are tagged tuples with only
;; atomic columns; every sequenced position in the plan (index order, op
;; order, operand order, arm order) carries an explicit ordinal/pc column.
;; To prove no implicit order survives, the decoder consumes the facts
;; SHUFFLED, after a serialize-to-text/read-back cycle (one S-expr per line),
;; so the round trip runs over honest serialized relational data rather than
;; in-memory aliasing.
;;
;; Fact schema (27 relations; pid = image-local plan id, always the leading
;; column so a single fact set can hold many plans):
;;
;;   header      (plan pid abi flavor)
;;   relations   (rel-decl pid slot kind name arity)     kind in {relation,
;;                                                       struct,lattice,temp}
;;               (rel-index pid slot ix kind)            index existence; kind
;;                                                       in {plain,delta,
;;                                                       seeded-only}
;;               (rel-index-col pid slot ix pos col)     index columns
;;               (rel-lat pid slot spec-tid decomp)      lattice extras
;;   attachments (attachment pid ord tid)                raw decl as term
;;   constants   (const pid slot name value)             value is atomic
;;   prims       (prim pid ord name)
;;   dynamic     (dynamic pid ord name)
;;   rules       (rule pid rslot rid variant nregs)      rslot = plan order
;;   ops         (op pid rslot region pc opcode)         region in {pre,
;;                                                       driver,body,head}
;;               (op-rel pid rslot region pc relslot)
;;               (op-k pid rslot region pc K)
;;               (op-ord pid rslot region pc pos col)
;;               (op-dord pid rslot region pc pos col)
;;               (op-arg pid rslot region pc pos kind n) kind in {r,k}
;;               (op-prim pid rslot region pc f)
;;               (op-spec pid rslot region pc tid)       cjoin lattice spec
;;               (op-accept pid rslot region pc pos kind name)
;;   join3 arms  (op-arm pid rslot region pc j view relslot K)
;;               (op-arm-ord pid rslot region pc j pos col)
;;               (op-arm-dord pid rslot region pc j pos col)
;;               (op-arm-arg pid rslot region pc j pos kind n)
;;   meta        (rule-meta pid ord rid source)
;;   terms       (term-atom pid tid value)               open sexp fallback
;;               (term-node pid tid len)
;;               (term-child pid tid pos child-tid)
;;
;; ABI 2 (kernel-cohort files; docs/rf1-contract.md slice 2) adds cohort-
;; level facts under the cohort's pid and reuses the schema above PER
;; KERNEL, each kernel under its own pid (pid+1+ord, recorded by the
;; `kernel` linking fact -- which is what lets the whole op/decl codec
;; reuse verbatim):
;;
;;   header      (cohort pid abi flavor)
;;   linking     (kernel pid kord kpid)
;;   manifest    (kmanifest pid kord key nrules prelude?)
;;               (kmember pid kord pos name)
;;   declarations/attachments/dynamic reuse the ABI-1 fact families (the
;;               (rel slot DECL) grammar is shared exactly)
;;   per kernel  (kslot kpid slot kind arity)            name-free exec
;;                                                       slots; orderings
;;                                                       reuse rel-index[-col]
;;                                                       and rel-lat
;;               (krule kpid rslot ord kind nregs)       exec rule-def; ops
;;                                                       reuse the op facts
;;               (krule-rel kpid rslot n)                structured variant
;;               (krule-fold kpid rslot f)               fields -- field
;;               (krule-ord kpid rslot n)                presence = fact
;;                                                       presence
;;               (kbind kpid slot name)                  binding schema
;;               (kdyn kpid slot)                        slot-relative dynamic
;;               (kdebug kpid ord rid variant source)    DebugMap
;;
;; Operand roles are positional per opcode (the op vocabulary is closed, so
;; the decoder knows arg 0 of a cjoin is the bound var and args 1,2 the
;; collection inputs); genuinely open sexps (lattice specs, cjoin collection
;; specs, oracle/seqindex attachment decls) fall back to a rooted term tree.
;;
;; Usage:
;;   racket tests/reflect/rf0-roundtrip.rkt build/<hash>.plan [more ...]
;;   racket tests/reflect/rf0-roundtrip.rkt --all [build-dir]
;;
;; --all round-trips every *.plan (and *.abi2 audit dump) under the build
;; dir (default: <repo>/build), reports pass/fail counts, and prints a
;; measurement table for the 5 largest.  Exit status is non-zero on any
;; failure.

(require racket/runtime-path)

(provide plan->facts facts->plan cohort->facts facts->cohort
         facts->bytes bytes->facts roundtrip)

(define-runtime-path here ".")
(define repo-root (simplify-path (build-path here ".." "..")))
(define canonical-plan-path
  (build-path repo-root "compiler" "canonical-plan.rkt"))

;; kernel-plan-key / kernel-plan->string / kernel-exec-key from the shipped
;; pass (do not copy)
(define-values (kernel-plan-key kernel-plan->string kernel-exec-key)
  (let ([resolved (path->string canonical-plan-path)])
    (values (dynamic-require `(file ,resolved) 'kernel-plan-key)
            (dynamic-require `(file ,resolved) 'kernel-plan->string)
            (dynamic-require `(file ,resolved) 'kernel-exec-key))))

;; -------------------------------------------------------------------------
;; Encode: plan sexp -> list of flat facts.

(define (atom? x)
  (or (symbol? x) (exact-integer? x) (flonum? x) (string? x)
      (boolean? x) (char? x)))

;; Open-sexp fallback: encode an arbitrary proper-list tree as term facts,
;; returning its root tid.  emit! appends a fact; next-tid! allocates ids.
(define (encode-term! x pid emit! next-tid!)
  (define tid (next-tid!))
  (cond
    [(atom? x) (emit! `(term-atom ,pid ,tid ,x))]
    [(list? x)
     (emit! `(term-node ,pid ,tid ,(length x)))
     (for ([c (in-list x)] [i (in-naturals)])
       (emit! `(term-child ,pid ,tid ,i ,(encode-term! c pid emit! next-tid!))))]
    [else (error 'rf0 "unencodable term (improper/opaque): ~s" x)])
  tid)

;; A canonical value ref, (r n) or (k n).
(define (ref->cols x)
  (match x
    [`(r ,n) (list 'r n)]
    [`(k ,n) (list 'k n)]
    [_ (error 'rf0 "not a value ref: ~s" x)]))

;; The op codec is shared between ABI-1 rule bodies and ABI-2 kernel exec
;; rule bodies -- the op grammar inside a rule-def is identical (both are
;; canonicalize-crule's output).  `pid` scopes the facts; ABI 2 hands each
;; kernel its own pid, and the codec reuses verbatim.
(define (make-op-encoder pid emit! term!)
  (define (emit-args! rslot region pc refs [pos0 0])
    (for ([x (in-list refs)] [i (in-naturals pos0)])
      (emit! `(op-arg ,pid ,rslot ,region ,pc ,i ,@(ref->cols x)))))
  (define (emit-ord! tag rslot region pc cols)
    (for ([c (in-list cols)] [i (in-naturals)])
      (emit! `(,tag ,pid ,rslot ,region ,pc ,i ,c))))
  (define (rel-slot-of r)
    (match r [`(rel ,n) n] [_ (error 'rf0 "not a rel ref: ~s" r)]))

  (define (encode-op! rslot region pc op)
    (define (op! code) (emit! `(op ,pid ,rslot ,region ,pc ,code)))
    (define (rel! r) (emit! `(op-rel ,pid ,rslot ,region ,pc ,(rel-slot-of r))))
    (define (k! K) (emit! `(op-k ,pid ,rslot ,region ,pc ,K)))
    (match op
      [`(,(and code (or 'join 'exists 'absent 'absent-lat 'join-lat))
         ,r ,ord ,K ,xs ...)
       (op! code) (rel! r) (k! K)
       (emit-ord! 'op-ord rslot region pc ord)
       (emit-args! rslot region pc xs)]
      [`(,(and code (or 'join-old 'join-new)) ,r ,ord ,K ,dord ,xs ...)
       (op! code) (rel! r) (k! K)
       (emit-ord! 'op-ord rslot region pc ord)
       (emit-ord! 'op-dord rslot region pc dord)
       (emit-args! rslot region pc xs)]
      [`(join3 ,c ,arms ...)
       (op! 'join3)
       (emit-args! rslot region pc (list c))
       (for ([arm (in-list arms)] [j (in-naturals)])
         (match-define `(,view ,r ,ord ,K ,dind ,ys ...) arm)
         (emit! `(op-arm ,pid ,rslot ,region ,pc ,j ,view ,(rel-slot-of r) ,K))
         (for ([c (in-list ord)] [i (in-naturals)])
           (emit! `(op-arm-ord ,pid ,rslot ,region ,pc ,j ,i ,c)))
         (for ([c (in-list dind)] [i (in-naturals)])
           (emit! `(op-arm-dord ,pid ,rslot ,region ,pc ,j ,i ,c)))
         (for ([y (in-list ys)] [i (in-naturals)])
           (emit! `(op-arm-arg ,pid ,rslot ,region ,pc ,j ,i ,@(ref->cols y)))))]
      [`(,(and code (or 'let 'letp)) ,x (prim ,f ,ys ...))
       (op! code)
       (emit! `(op-prim ,pid ,rslot ,region ,pc ,f))
       (emit-args! rslot region pc (cons x ys))]
      [`(let ,x ,y)                          ; ref-copy form: no op-prim fact
       (op! 'let) (emit-args! rslot region pc (list x y))]
      [`(cjoin ,x ,spec ,a ,b)
       (op! 'cjoin)
       (emit! `(op-spec ,pid ,rslot ,region ,pc ,(term! spec)))
       (emit-args! rslot region pc (list x a b))]
      [`(,(and code (or 'eq 'neq)) ,x ,y)
       (op! code) (emit-args! rslot region pc (list x y))]
      [`(cmp ,f ,x ,y)
       (op! 'cmp)
       (emit! `(op-prim ,pid ,rslot ,region ,pc ,f))
       (emit-args! rslot region pc (list x y))]
      [`(scan ,r ,xs ...)
       (op! 'scan) (rel! r) (emit-args! rslot region pc xs)]
      [`(probe ,r ,ord ,K ,xs ...)
       (op! 'probe) (rel! r) (k! K)
       (emit-ord! 'op-ord rslot region pc ord)
       (emit-args! rslot region pc xs)]
      [`(,(and code (or 'once 'seeded))) (op! code)]
      [`(mkstruct ,r ,ord ,x ,fields ...)
       (op! 'mkstruct) (rel! r)
       (emit-ord! 'op-ord rslot region pc ord)
       (emit-args! rslot region pc (cons x fields))]
      [`(emit ,r ,ord ,xs ...)
       (op! 'emit) (rel! r)
       (emit-ord! 'op-ord rslot region pc ord)
       (emit-args! rslot region pc xs)]
      [`(,(and code (or 'emit-temp 'emit-lat)) ,r ,xs ...)
       (op! code) (rel! r) (emit-args! rslot region pc xs)]
      [`(tycheck ,x (accept ,ts ...) ,rid ,rel ,col ,ord)
       (op! 'tycheck)
       (for ([t (in-list ts)] [i (in-naturals)])
         (match t
           [(? symbol?)
            (emit! `(op-accept ,pid ,rslot ,region ,pc ,i sym ,t))]
           [`(struct ,nm)
            (emit! `(op-accept ,pid ,rslot ,region ,pc ,i struct ,nm))]
           [_ (error 'rf0 "unknown accept type: ~s" t)]))
       (emit-ord! 'op-ord rslot region pc ord)
       (emit-args! rslot region pc (list x rid rel col))]
      [_ (error 'rf0 "unknown op: ~s" op)]))
  encode-op!)

;; One rule's regions, through the shared op codec.
(define (encode-regions! encode-op! rslot pre drv body head)
  (for ([op (in-list pre)] [pc (in-naturals)])
    (encode-op! rslot 'pre pc op))
  (encode-op! rslot 'driver 0 drv)
  (for ([op (in-list body)] [pc (in-naturals)])
    (encode-op! rslot 'body pc op))
  (for ([op (in-list head)] [pc (in-naturals)])
    (encode-op! rslot 'head pc op)))

;; A declaration's trailing index list.
;;   idx ::= (col ...+) | (delta col ...+) | (seeded-only col ...+)
;;   (ir-stack.rkt index?)
(define (encode-indices! pid emit! slot indices)
  (for ([idx (in-list indices)] [ix (in-naturals)])
    (define-values (ikind cols)
      (match idx
        [`(,(and m (or 'delta 'seeded-only)) ,cols ...) (values m cols)]
        [`(,(? exact-integer? c) ,cols ...) (values 'plain (cons c cols))]
        [_ (error 'rf0 "unknown index shape: ~s" idx)]))
    (emit! `(rel-index ,pid ,slot ,ix ,ikind))
    (for ([c (in-list cols)] [i (in-naturals)])
      (emit! `(rel-index-col ,pid ,slot ,ix ,i ,c)))))

;; One (rel slot DECL) storage declaration -- ABI 1's relations table and
;; ABI 2's cohort declarations list share this shape exactly.
(define (encode-decl! pid emit! term! slot decl)
  (define-values (kind name arity indices)
    (match decl
      [`(lattice ,name ,arity ,spec ,decomp ,idx ...)
       (emit! `(rel-lat ,pid ,slot ,(term! spec) ,decomp))
       (values 'lattice name arity idx)]
      [`(,(and kind (or 'relation 'struct 'temp)) ,name ,arity ,idx ...)
       (values kind name arity idx)]
      [_ (error 'rf0 "unknown storage decl: ~s" decl)]))
  (emit! `(rel-decl ,pid ,slot ,kind ,name ,arity))
  (encode-indices! pid emit! slot indices))

(define (plan->facts plan [pid 0])
  (define facts '())
  (define (emit! f) (set! facts (cons f facts)))
  (define tid-counter 0)
  (define (next-tid!) (begin0 tid-counter (set! tid-counter (add1 tid-counter))))
  (define (term! x) (encode-term! x pid emit! next-tid!))
  (define encode-op! (make-op-encoder pid emit! term!))

  (match-define `(kernel-plan (abi ,abi) (flavor ,flavor)
                              (relations ,rels ...)
                              (attachments ,atts ...)
                              (constants ,ks ...)
                              (prims ,prims ...)
                              (dynamic ,dyns ...)
                              (rules ,rules ...)
                              (meta ,metas ...))
    plan)
  (emit! `(plan ,pid ,abi ,flavor))
  (for ([r (in-list rels)])
    (match-define `(rel ,slot ,decl) r)
    (encode-decl! pid emit! term! slot decl))
  (for ([a (in-list atts)] [i (in-naturals)])
    (emit! `(attachment ,pid ,i ,(term! a))))
  (for ([k (in-list ks)])
    (match-define `(k ,slot ,name ,v) k)
    (unless (atom? v) (error 'rf0 "non-atomic constant value: ~s" v))
    (emit! `(const ,pid ,slot ,name ,v)))
  (for ([p (in-list prims)] [i (in-naturals)])
    (emit! `(prim ,pid ,i ,p)))
  (for ([d (in-list dyns)] [i (in-naturals)])
    (emit! `(dynamic ,pid ,i ,d)))
  (for ([rd (in-list rules)] [rslot (in-naturals)])
    (match-define `(rule-def (rid ,rid) (variant ,tag)
                             (nregs ,nregs)
                             (pre ,pre ...) (driver ,drv)
                             (body ,body ...) (head ,head ...))
      rd)
    (emit! `(rule ,pid ,rslot ,rid ,tag ,nregs))
    (encode-regions! encode-op! rslot pre drv body head))
  (for ([m (in-list metas)] [i (in-naturals)])
    (match-define `(rule-meta (rid ,rid) (source ,src)) m)
    (emit! `(rule-meta ,pid ,i ,rid ,src)))
  (reverse facts))

;; One ABI-2 kernel's exec/binding/dynamic/debug facts, under its own kpid.
(define (encode-kernel! kpid emit! next-tid! exec binding kdyn debug)
  (define (term! x) (encode-term! x kpid emit! next-tid!))
  (define encode-op! (make-op-encoder kpid emit! term!))
  (match-define `(exec (slots ,slots ...) (constants ,ks ...)
                       (prims ,prims ...) (rules ,rules ...))
    exec)
  (for ([s (in-list slots)])
    (match s
      [`(slot ,slot lattice ,arity ,spec ,decomp ,idx ...)
       (emit! `(rel-lat ,kpid ,slot ,(term! spec) ,decomp))
       (emit! `(kslot ,kpid ,slot lattice ,arity))
       (encode-indices! kpid emit! slot idx)]
      [`(slot ,slot ,(and kind (or 'relation 'struct 'temp)) ,arity ,idx ...)
       (emit! `(kslot ,kpid ,slot ,kind ,arity))
       (encode-indices! kpid emit! slot idx)]
      [_ (error 'rf0 "unknown exec slot: ~s" s)]))
  (for ([k (in-list ks)])
    (match-define `(k ,slot ,name ,v) k)
    (unless (atom? v) (error 'rf0 "non-atomic constant value: ~s" v))
    (emit! `(const ,kpid ,slot ,name ,v)))
  (for ([p (in-list prims)] [i (in-naturals)])
    (emit! `(prim ,kpid ,i ,p)))
  (for ([rd (in-list rules)] [rslot (in-naturals)])
    (match-define `(rule-def (ord ,ord) (variant ,vkind ,vrest ...)
                             (nregs ,nregs)
                             (pre ,pre ...) (driver ,drv)
                             (body ,body ...) (head ,head ...))
      rd)
    (emit! `(krule ,kpid ,rslot ,ord ,vkind ,nregs))
    (for ([v (in-list vrest)])
      (match v
        [`(rel ,n) (emit! `(krule-rel ,kpid ,rslot ,n))]
        [`(fold ,f) (emit! `(krule-fold ,kpid ,rslot ,f))]
        [(? exact-integer? n) (emit! `(krule-ord ,kpid ,rslot ,n))]
        [_ (error 'rf0 "unknown variant field: ~s" v)]))
    (encode-regions! encode-op! rslot pre drv body head))
  (match-define `(binding ,bs ...) binding)
  (for ([b (in-list bs)])
    (match-define `(slot ,slot ,name) b)
    (emit! `(kbind ,kpid ,slot ,name)))
  (match-define `(dynamic ,ds ...) kdyn)
  (for ([d (in-list ds)])
    (match-define `(slot ,slot) d)
    (emit! `(kdyn ,kpid ,slot)))
  (match-define `(debug ,rs ...) debug)
  (for ([r (in-list rs)])
    (match-define `(rule (ord ,ord) (rid ,rid) (variant ,v) (source ,src)) r)
    (emit! `(kdebug ,kpid ,ord ,rid ,v ,src))))

;; ABI 2: a kernel-cohort file.  Cohort-level facts ride `pid`; each
;; kernel's content rides pid+1+ord (the `kernel` linking fact records the
;; assignment, so a decoder never assumes it).
(define (cohort->facts cohort [pid 0])
  (define facts '())
  (define (emit! f) (set! facts (cons f facts)))
  (define tid-counter 0)
  (define (next-tid!) (begin0 tid-counter (set! tid-counter (add1 tid-counter))))
  (define (term! x) (encode-term! x pid emit! next-tid!))
  (match-define `(kernel-cohort (abi ,abi) (flavor ,flavor)
                                (attachments ,atts ...)
                                (declarations ,decls ...)
                                (dynamic ,dyns ...)
                                (manifest ,mans ...)
                                ,kernels ...)
    cohort)
  (emit! `(cohort ,pid ,abi ,flavor))
  (for ([a (in-list atts)] [i (in-naturals)])
    (emit! `(attachment ,pid ,i ,(term! a))))
  (for ([r (in-list decls)])
    (match-define `(rel ,slot ,decl) r)
    (encode-decl! pid emit! term! slot decl))
  (for ([d (in-list dyns)] [i (in-naturals)])
    (emit! `(dynamic ,pid ,i ,d)))
  (for ([m (in-list mans)])
    (match m
      [`(kernel (ord ,kord) (key ,key) (members ,ms ...) ,rest ...)
       (define prelude? (and (assq 'prelude rest) #t))
       (match-define `(rules ,nrules) (assq 'rules rest))
       (emit! `(kmanifest ,pid ,kord ,key ,nrules ,prelude?))
       (for ([mm (in-list ms)] [i (in-naturals)])
         (emit! `(kmember ,pid ,kord ,i ,mm)))]
      [_ (error 'rf0 "unknown manifest entry: ~s" m)]))
  (for ([k (in-list kernels)])
    (match-define `(kernel (ord ,kord) ,exec ,binding ,kdyn ,debug) k)
    (define kpid (+ pid 1 kord))
    (emit! `(kernel ,pid ,kord ,kpid))
    (encode-kernel! kpid emit! next-tid! exec binding kdyn debug))
  (reverse facts))

;; -------------------------------------------------------------------------
;; Decode: facts -> plan sexp.  Consumes facts in ANY order (they arrive
;; shuffled); all sequencing is recovered from explicit ordinal columns.

;; Bucket accessors over ONE pid's facts.  Key length by relation: how many
;; leading payload cols identify the group; the rest is the row.
(define (make-fact-db facts pid)
  (define buckets (make-hasheq))
  (define (bucket tag) (hash-ref! buckets tag make-hash))
  (for ([f (in-list facts)])
    (match-define (cons tag (cons fpid cols)) f)
    (when (equal? fpid pid)
      (define-values (key row)
        (case tag
          [(plan cohort) (values '() cols)]
          [(rel-decl rel-lat kslot) (values (list (car cols)) (cdr cols))]
          [(rel-index) (values (take cols 2) (drop cols 2))]
          [(rel-index-col) (values (take cols 2) (drop cols 2))]
          [(attachment const prim dynamic rule rule-meta term-atom term-node
            kernel kmanifest kbind kdyn kdebug)
           (values '() cols)]
          [(kmember krule krule-rel krule-fold krule-ord)
           (values (list (car cols)) (cdr cols))]
          [(term-child) (values (list (car cols)) (cdr cols))]
          [(op op-rel op-k op-prim op-spec) (values (take cols 3) (drop cols 3))]
          [(op-ord op-dord op-arg op-accept) (values (take cols 3) (drop cols 3))]
          [(op-arm) (values (take cols 3) (drop cols 3))]
          [(op-arm-ord op-arm-dord op-arm-arg) (values (take cols 4) (drop cols 4))]
          [else (error 'rf0 "unknown fact relation: ~s" tag)]))
      (hash-update! (bucket tag) key (lambda (rs) (cons row rs)) '())))
  ;; the (rslot region) -> pcs index, from op facts
  (for ([key (in-list (hash-keys (bucket 'op)))])
    (match-define (list rslot region pc) key)
    (hash-update! (bucket 'op-pcs) (list rslot region)
                  (lambda (rs) (cons (list pc) rs)) '()))
  (define (rows tag key) (hash-ref (bucket tag) key '()))
  (define (one tag key #:default [d #f])
    (match (rows tag key)
      [(list r) r]
      ['() (or d (error 'rf0 "missing ~a fact for ~s" tag key))]
      [rs (error 'rf0 "duplicate ~a facts for ~s: ~s" tag key rs)]))
  ;; positional group: rows are (pos col ...); sort by pos, return payloads
  (define (seq tag key)
    (map cdr (sort (rows tag key) < #:key car)))
  (define (keys tag) (hash-keys (bucket tag)))
  (values rows one seq keys))

;; term decoding, via id-keyed lookup tables
(define (make-term-decoder rows seq)
  (define term-atoms (make-hash))
  (for ([r (in-list (rows 'term-atom '()))])
    (hash-set! term-atoms (car r) (cadr r)))
  (define term-nodes (make-hash))
  (for ([r (in-list (rows 'term-node '()))])
    (hash-set! term-nodes (car r) (cadr r)))
  (define (term-of tid)
    (cond
      [(hash-has-key? term-atoms tid) (hash-ref term-atoms tid)]
      [(hash-has-key? term-nodes tid)
       (define len (hash-ref term-nodes tid))
       (define kids (seq 'term-child (list tid)))
       (unless (= (length kids) len)
         (error 'rf0 "term ~a arity mismatch" tid))
       (map (lambda (k) (term-of (car k))) kids)]
      [else (error 'rf0 "dangling term id ~a" tid)]))
  term-of)

;; The op decoder, shared like its encoder; returns region-ops.
(define (make-op-decoder rows one seq term-of)
  (define (ref-of kind n)
    (case kind [(r) `(r ,n)] [(k) `(k ,n)]
      [else (error 'rf0 "bad ref kind ~s" kind)]))
  (define (args-of key) (map (lambda (a) (apply ref-of a)) (seq 'op-arg key)))
  (define (ord-of key [tag 'op-ord]) (map car (seq tag key)))
  (define (rel-of key) `(rel ,(car (one 'op-rel key))))
  (define (k-of key) (car (one 'op-k key)))

  (define (decode-op rslot region pc)
    (define key (list rslot region pc))
    (define code (car (one 'op key)))
    (case code
      [(join exists absent absent-lat join-lat)
       `(,code ,(rel-of key) ,(ord-of key) ,(k-of key) ,@(args-of key))]
      [(join-old join-new)
       `(,code ,(rel-of key) ,(ord-of key) ,(k-of key) ,(ord-of key 'op-dord)
               ,@(args-of key))]
      [(join3)
       (define arms
         (for/list ([arm (in-list (sort (rows 'op-arm key) < #:key car))])
           (match-define (list j view relslot K) arm)
           (define akey (list rslot region pc j))
           `(,view (rel ,relslot)
                   ,(map car (seq 'op-arm-ord akey))
                   ,K
                   ,(map car (seq 'op-arm-dord akey))
                   ,@(map (lambda (a) (apply ref-of a)) (seq 'op-arm-arg akey)))))
       `(join3 ,@(args-of key) ,@arms)]
      [(let letp)
       (define args (args-of key))
       (match (rows 'op-prim key)
         [(list (list f)) `(,code ,(car args) (prim ,f ,@(cdr args)))]
         ['() `(let ,(first args) ,(second args))])]
      [(cjoin)
       (define args (args-of key))
       `(cjoin ,(first args) ,(term-of (car (one 'op-spec key)))
               ,(second args) ,(third args))]
      [(eq neq) `(,code ,@(args-of key))]
      [(cmp) `(cmp ,(car (one 'op-prim key)) ,@(args-of key))]
      [(scan) `(scan ,(rel-of key) ,@(args-of key))]
      [(probe) `(probe ,(rel-of key) ,(ord-of key) ,(k-of key) ,@(args-of key))]
      [(once seeded) `(,code)]
      [(mkstruct) `(mkstruct ,(rel-of key) ,(ord-of key) ,@(args-of key))]
      [(emit) `(emit ,(rel-of key) ,(ord-of key) ,@(args-of key))]
      [(emit-temp emit-lat) `(,code ,(rel-of key) ,@(args-of key))]
      [(tycheck)
       (define ts (for/list ([t (in-list (seq 'op-accept key))])
                    (match t
                      [(list 'sym s) s]
                      [(list 'struct nm) `(struct ,nm)])))
       (match-define (list x rid rel col) (args-of key))
       `(tycheck ,x (accept ,@ts) ,rid ,rel ,col ,(ord-of key))]
      [else (error 'rf0 "unknown opcode ~s" code)]))

  (define (region-ops rslot region)
    ;; ops of one region, in pc order; pcs are dense from 0
    (define pcs (sort (map car (rows 'op-pcs (list rslot region))) <))
    (for/list ([pc (in-list pcs)]) (decode-op rslot region pc)))
  region-ops)

;; A slot's index sexps, in emitted order.
(define (decode-indices rows one seq keys slot)
  (define my-ixes
    (sort (for/list ([k (in-list (keys 'rel-index))]
                     #:when (equal? (car k) slot))
            (list (second k) (car (one 'rel-index k))))
          < #:key car))
  (for/list ([ix+k (in-list my-ixes)])
    (match-define (list ix ikind) ix+k)
    (define cols (map car (seq 'rel-index-col (list slot ix))))
    (if (eq? ikind 'plain) cols `(,ikind ,@cols))))

;; The (rel slot DECL) list, slot-sorted -- ABI 1's relations table and
;; ABI 2's cohort declarations.
(define (decode-decls rows one seq keys term-of)
  (for/list ([row (in-list (sort (map (lambda (k) (cons (car k) (one 'rel-decl k)))
                                      (keys 'rel-decl))
                                 < #:key car))])
    (match-define (cons slot (list kind name arity)) row)
    (define idx-sexps (decode-indices rows one seq keys slot))
    (define decl
      (case kind
        [(lattice)
         (match-define (list spec-tid decomp) (one 'rel-lat (list slot)))
         `(lattice ,name ,arity ,(term-of spec-tid) ,decomp ,@idx-sexps)]
        [else `(,kind ,name ,arity ,@idx-sexps)]))
    `(rel ,slot ,decl)))

(define (facts->plan facts [pid 0])
  (define-values (rows one seq keys) (make-fact-db facts pid))
  (define term-of (make-term-decoder rows seq))
  (define region-ops (make-op-decoder rows one seq term-of))

  (match-define (list (list abi flavor)) (rows 'plan '()))
  (define rels (decode-decls rows one seq keys term-of))
  (define atts
    (for/list ([row (in-list (sort (rows 'attachment '()) < #:key car))])
      (term-of (second row))))
  (define consts
    (for/list ([row (in-list (sort (rows 'const '()) < #:key car))])
      (match-define (list slot name v) row)
      `(k ,slot ,name ,v)))
  (define prims (map second (sort (rows 'prim '()) < #:key car)))
  (define dyns (map second (sort (rows 'dynamic '()) < #:key car)))
  (define rules
    (for/list ([row (in-list (sort (rows 'rule '()) < #:key car))])
      (match-define (list rslot rid tag nregs) row)
      `(rule-def (rid ,rid) (variant ,tag)
                 (nregs ,nregs)
                 (pre ,@(region-ops rslot 'pre))
                 (driver ,(car (region-ops rslot 'driver)))
                 (body ,@(region-ops rslot 'body))
                 (head ,@(region-ops rslot 'head)))))
  (define metas
    (for/list ([row (in-list (sort (rows 'rule-meta '()) < #:key car))])
      (match-define (list _ord rid src) row)
      `(rule-meta (rid ,rid) (source ,src))))
  `(kernel-plan
    (abi ,abi)
    (flavor ,flavor)
    (relations ,@rels)
    (attachments ,@atts)
    (constants ,@consts)
    (prims ,@prims)
    (dynamic ,@dyns)
    (rules ,@rules)
    (meta ,@metas)))

;; One kernel's four parts, from its kpid-scoped facts.
(define (decode-kernel facts kpid)
  (define-values (rows one seq keys) (make-fact-db facts kpid))
  (define term-of (make-term-decoder rows seq))
  (define region-ops (make-op-decoder rows one seq term-of))
  (define slots
    (for/list ([row (in-list (sort (map (lambda (k) (cons (car k) (one 'kslot k)))
                                        (keys 'kslot))
                                   < #:key car))])
      (match-define (cons slot (list kind arity)) row)
      (define idx-sexps (decode-indices rows one seq keys slot))
      (case kind
        [(lattice)
         (match-define (list spec-tid decomp) (one 'rel-lat (list slot)))
         `(slot ,slot lattice ,arity ,(term-of spec-tid) ,decomp ,@idx-sexps)]
        [else `(slot ,slot ,kind ,arity ,@idx-sexps)])))
  (define consts
    (for/list ([row (in-list (sort (rows 'const '()) < #:key car))])
      (match-define (list slot name v) row)
      `(k ,slot ,name ,v)))
  (define prims (map second (sort (rows 'prim '()) < #:key car)))
  (define rules
    (for/list ([k (in-list (sort (keys 'krule) < #:key car))])
      (match-define (list rslot) k)
      (match-define (list ord vkind nregs) (one 'krule k))
      (define variant
        `(,vkind
          ,@(match (rows 'krule-rel k) [(list (list n)) `((rel ,n))] ['() '()])
          ,@(match (rows 'krule-fold k) [(list (list f)) `((fold ,f))] ['() '()])
          ,@(match (rows 'krule-ord k) [(list (list n)) (list n)] ['() '()])))
      `(rule-def (ord ,ord) (variant ,@variant)
                 (nregs ,nregs)
                 (pre ,@(region-ops rslot 'pre))
                 (driver ,(car (region-ops rslot 'driver)))
                 (body ,@(region-ops rslot 'body))
                 (head ,@(region-ops rslot 'head)))))
  (define binds
    (for/list ([row (in-list (sort (rows 'kbind '()) < #:key car))])
      `(slot ,(first row) ,(second row))))
  (define kds
    (for/list ([row (in-list (sort (rows 'kdyn '()) < #:key car))])
      `(slot ,(first row))))
  (define debugs
    (for/list ([row (in-list (sort (rows 'kdebug '()) < #:key car))])
      (match-define (list ord rid v src) row)
      `(rule (ord ,ord) (rid ,rid) (variant ,v) (source ,src))))
  (list `(exec (slots ,@slots) (constants ,@consts) (prims ,@prims)
               (rules ,@rules))
        `(binding ,@binds)
        `(dynamic ,@kds)
        `(debug ,@debugs)))

(define (facts->cohort facts [pid 0])
  (define-values (rows one seq keys) (make-fact-db facts pid))
  (define term-of (make-term-decoder rows seq))
  (match-define (list (list abi flavor)) (rows 'cohort '()))
  (define atts
    (for/list ([row (in-list (sort (rows 'attachment '()) < #:key car))])
      (term-of (second row))))
  (define decls (decode-decls rows one seq keys term-of))
  (define dyns (map second (sort (rows 'dynamic '()) < #:key car)))
  (define mans
    (for/list ([row (in-list (sort (rows 'kmanifest '()) < #:key car))])
      (match-define (list kord key nrules prelude?) row)
      `(kernel (ord ,kord) (key ,key)
               (members ,@(map car (seq 'kmember (list kord))))
               ,@(if prelude? '((prelude #t)) '())
               (rules ,nrules))))
  (define kernels
    (for/list ([row (in-list (sort (rows 'kernel '()) < #:key car))])
      (match-define (list kord kpid) row)
      `(kernel (ord ,kord) ,@(decode-kernel facts kpid))))
  `(kernel-cohort
    (abi ,abi)
    (flavor ,flavor)
    (attachments ,@atts)
    (declarations ,@decls)
    (dynamic ,@dyns)
    (manifest ,@mans)
    ,@kernels))

;; -------------------------------------------------------------------------
;; Fact serialization: one written S-expr per line, and back.

(define (facts->bytes facts)
  (define o (open-output-bytes))
  (for ([f (in-list facts)]) (write f o) (newline o))
  (get-output-bytes o))

(define (bytes->facts bs)
  (define in (open-input-bytes bs))
  (for/list ([f (in-port read in)]) f))

;; -------------------------------------------------------------------------
;; Round trip one file.  Returns a result hash (for reporting); raises
;; nothing -- failures are recorded.

;; Every kernel's KernelPlanKey, RECOMPUTED from its exec part (never read
;; from the manifest): (ord key) pairs in kernel order.
(define (cohort-keys cohort)
  (for/list ([form (in-list (cdr cohort))]
             #:when (and (pair? form) (eq? (car form) 'kernel)
                         (assq 'exec (cddr form))))
    (list (second (second form))
          (kernel-exec-key (assq 'exec (cddr form))))))

;; The manifest's RECORDED (ord key) pairs, for the recorded-vs-recomputed
;; agreement check.
(define (manifest-keys cohort)
  (define m (or (assq 'manifest (cdr cohort))
                (error 'rf0 "cohort has no manifest")))
  (for/list ([e (in-list (cdr m))])
    (list (second (second e)) (second (third e)))))

(define (cohort-form? x) (and (pair? x) (eq? (car x) 'kernel-cohort)))

(define (roundtrip file)
  (define orig-bytes (file->bytes file))
  (define-values (parse-r parse-cpu parse-real parse-gc)
    (time-apply (lambda ()
                  (with-input-from-bytes orig-bytes read))
                '()))
  (define plan (car parse-r))
  (define cohort? (cohort-form? plan))
  (define orig-key (if cohort? (cohort-keys plan) (kernel-plan-key plan)))
  (define-values (enc-r enc-cpu enc-real enc-gc)
    (time-apply (lambda () ((if cohort? cohort->facts plan->facts) plan)) '()))
  (define facts (car enc-r))
  (define encoded (facts->bytes facts))
  ;; read the facts back from their serialized text and SHUFFLE them: the
  ;; decoder must depend only on explicit ordinal columns, never on fact
  ;; order or in-memory sharing
  (define reread (shuffle (bytes->facts encoded)))
  (define-values (dec-r dec-cpu dec-real dec-gc)
    (time-apply (lambda () ((if cohort? facts->cohort facts->plan) reread)) '()))
  (define plan2 (car dec-r))
  (define out-bytes
    (string->bytes/utf-8 (string-append (kernel-plan->string plan2) "\n")))
  (define byte-ok (bytes=? orig-bytes out-bytes))
  (define key2 (if cohort? (cohort-keys plan2) (kernel-plan-key plan2)))
  ;; cohorts additionally require the manifest's recorded keys to agree with
  ;; the keys recomputed from the decoded exec parts
  (define key-ok
    (and (equal? orig-key key2)
         (or (not cohort?) (equal? (manifest-keys plan2) key2))))
  (hash 'file (path->string (if (path? file) file (string->path file)))
        'orig-bytes (bytes-length orig-bytes)
        'facts (length facts)
        'encoded-bytes (bytes-length encoded)
        'parse-ms parse-real
        'encode-ms enc-real
        'decode-ms dec-real
        'byte-ok byte-ok
        'key-ok key-ok
        'orig-key (format "~a" orig-key)
        'new-key (format "~a" key2)))

(define (first-diff a b)
  (define n (min (bytes-length a) (bytes-length b)))
  (or (for/first ([i (in-range n)]
                  #:unless (= (bytes-ref a i) (bytes-ref b i)))
        i)
      (and (not (= (bytes-length a) (bytes-length b))) n)))

;; -------------------------------------------------------------------------
;; Driver.

(define (report-row r)
  (printf "~a  ~a bytes, ~a facts, ~a fact-bytes, parse ~ams, plan->facts ~ams, facts->plan ~ams  [~a~a]\n"
          (hash-ref r 'file)
          (hash-ref r 'orig-bytes) (hash-ref r 'facts)
          (hash-ref r 'encoded-bytes)
          (hash-ref r 'parse-ms) (hash-ref r 'encode-ms) (hash-ref r 'decode-ms)
          (if (hash-ref r 'byte-ok) "bytes=ok" "BYTES-DIFFER")
          (if (hash-ref r 'key-ok) " key=ok" " KEY-DIFFERS")))

(define (run-files files #:table-top [top 0])
  (define results
    (for/list ([f (in-list files)])
      (with-handlers ([exn:fail?
                       (lambda (e)
                         (hash 'file (path->string
                                      (if (path? f) f (string->path f)))
                               'error (exn-message e)
                               'byte-ok #f 'key-ok #f))])
        (roundtrip f))))
  (define failures
    (filter (lambda (r) (not (and (hash-ref r 'byte-ok)
                                  (hash-ref r 'key-ok))))
            results))
  (for ([r (in-list failures)])
    (cond
      [(hash-ref r 'error #f)
       (printf "FAIL ~a: ~a\n" (hash-ref r 'file) (hash-ref r 'error))]
      [else
       (printf "FAIL ~a: bytes ~a key ~a\n" (hash-ref r 'file)
               (hash-ref r 'byte-ok) (hash-ref r 'key-ok))]))
  (printf "round-trip: ~a/~a byte-identical + key-identical\n"
          (- (length results) (length failures)) (length results))
  (when (> top 0)
    (define ranked
      (sort (filter (lambda (r) (hash-ref r 'orig-bytes #f)) results)
            > #:key (lambda (r) (hash-ref r 'orig-bytes))))
    (printf "\nlargest ~a plans:\n" (min top (length ranked)))
    (for ([r (in-list (take ranked (min top (length ranked))))])
      (report-row r)))
  (exit (if (null? failures) 0 1)))

(module+ main
  (define argv (current-command-line-arguments))
  (cond
    [(and (> (vector-length argv) 0)
          (string=? (vector-ref argv 0) "--all"))
     (define dir (if (> (vector-length argv) 1)
                     (string->path (vector-ref argv 1))
                     (build-path repo-root "build")))
     (define files
       (sort (for/list ([p (in-directory dir)]
                        #:when (regexp-match? #rx"\\.(plan|abi2)$"
                                              (path->string p)))
               p)
             string<? #:key path->string))
     (when (null? files)
       (eprintf "no .plan files under ~a\n" dir)
       (exit 2))
     (run-files files #:table-top 5)]
    [(> (vector-length argv) 0)
     (for ([f (in-vector argv)])
       (define r (roundtrip f))
       (report-row r)
       (unless (and (hash-ref r 'byte-ok) (hash-ref r 'key-ok))
         (define orig (file->bytes f))
         (define form (with-input-from-bytes orig read))
         (define cohort? (cohort-form? form))
         (define plan2
           ((if cohort? facts->cohort facts->plan)
            (shuffle (bytes->facts
                      (facts->bytes
                       ((if cohort? cohort->facts plan->facts) form))))))
         (define out (string->bytes/utf-8
                      (string-append (kernel-plan->string plan2) "\n")))
         (define i (first-diff orig out))
         (printf "  first differing byte at ~a\n" i)
         (exit 1)))]
    [else
     (eprintf "usage: racket rf0-roundtrip.rkt <file.plan|file.abi2> ...\n")
     (eprintf "       racket rf0-roundtrip.rkt --all [build-dir]\n")
     (exit 2)]))
