#lang racket

;; Canonical KernelPlan pass (docs/execution-tiers.md §4/§11 T1; decisions
;; D3-D6 in docs/execution-tiers-impl.md §2).
;;
;; Consumes one stratum's cprog (build-cprog output) and produces the
;; deterministic, edit-stable lowered plan: dense registers, relation and
;; constant slots, RuleId/VariantTag identities, and a canonical
;; serialization whose sha256 is the KernelPlanKey.  T1 scope: the plan is a
;; parallel artifact (build/<hash>.plan, written by emit-stratum-cpp beside
;; the .cprog) -- emit-cpp's generated C++ is unchanged, and in particular
;; bumpFires keeps its aggregated (loc, base-tag) key, which is the
;; exact-once audit's documented unit (emit-cpp.rkt "Same-driver variants of
;; one rule share a key").  Disaggregated identity lives here.
;;
;; Identity model (docs/execution-tiers.md §2.1):
;;   rid          dense per source rule, grouped by crule loc ("file:line");
;;                every #f-loc crule is its own rid.  Two source rules on one
;;                line would merge -- deterministic but muddled; the durable
;;                RuleKey (T0) subsumes this.
;;   VariantTag   emit-cpp's base tag (once | seeded | all:<rel> |
;;                delta:<rel>, by dynamic-rels membership), "#<ordinal>"
;;                suffixed IFF the (rid, base) group has several variants
;;                (D3: a recursive rule's exact-semi-naive versions share a
;;                driver tag), "/<kind>" suffixed in count flavors.
;;
;; Determinism is by construction (D4): every unordered container is sorted
;; here -- decls and crules by canonical serialization, constants by global
;; name, dynamic rels and prims by symbol -- so the printed plan is
;; byte-stable across processes AND stable under unrelated program edits
;; (unlike set/hash iteration order, which is content-chaotic).

(provide canonicalize-cprog       ; cprog [#:flavor sym] -> kernel-plan
         canonicalize-cprog/tags  ; ... -> (values kernel-plan crule->rid.tag)
         canonical-rule-tags      ; cprog -> (listof (cons rid tag)),
                                  ;   aligned with (cprog-rules cprog)
         kernel-plan->string      ; single-line deterministic serialization
         kernel-plan-key)         ; sha256 hex of that serialization

(require racket/set
         sha
         "ir-stack.rkt")

;; ------------------------------------------------------------------------
;; Deterministic total order on s-expressions.

(define (sexp->string x)
  (with-output-to-string (lambda () (write x))))

(define (sexp<? a b)
  (string<? (sexp->string a) (sexp->string b)))

;; "file:line" -> (list file line-number) for rid ordering; #f locs sort
;; after every located rule (each as its own rid, in canonical rule order).
(define (loc-key loc)
  (match (and loc (regexp-match #rx"^(.*):([0-9]+)$" loc))
    [(list _ file line) (list file (string->number line))]
    [_ (list (or loc "") 0)]))

(define (loc-key<? a b)
  (match-define (list fa la) a)
  (match-define (list fb lb) b)
  (or (string<? fa fb) (and (string=? fa fb) (< la lb))))

;; ------------------------------------------------------------------------
;; Per-crule canonicalization: rewrite every value-ref symbol to (r n) or
;; (k n), every relation name to (rel n), and collect prim names.  Value-ref
;; positions hold BOTH variables and globalized constants (globalize-
;; constants keys its hash value->name, so the name set distinguishes them).
;; Registers are dense in first-use order: pre ops, driver, body, head --
;; note pre runs BEFORE the driver (probe drivers key on constants loaded
;; there), so register 0 is not necessarily a driver column.

(define (canonicalize-crule cr const-slot rel-slot prim!)
  (define regs (make-hash))
  (define (ref! v)
    (cond [(const-slot v) => (lambda (k) `(k ,k))]
          [else `(r ,(hash-ref! regs v (lambda () (hash-count regs))))]))
  (define (refs* vs) (map ref! vs))
  (define (rel! name) `(rel ,(rel-slot name)))
  (define (op->canon op)
    (match op
      [`(join ,rel ,ord ,K ,xs ...)
       `(join ,(rel! rel) ,ord ,K ,@(refs* xs))]
      [`(join-old ,rel ,ord ,K ,dord ,xs ...)
       `(join-old ,(rel! rel) ,ord ,K ,dord ,@(refs* xs))]
      [`(join-new ,rel ,ord ,K ,dord ,xs ...)
       `(join-new ,(rel! rel) ,ord ,K ,dord ,@(refs* xs))]
      [`(join3 ,cycle ,arms ...)
       `(join3 ,(ref! cycle)
               ,@(for/list ([arm (in-list arms)])
                   (match-define `(,view ,rel ,ord ,K ,dind ,ys ...) arm)
                   `(,view ,(rel! rel) ,ord ,K ,dind ,@(refs* ys))))]
      [`(exists ,rel ,ord ,K ,xs ...)
       `(exists ,(rel! rel) ,ord ,K ,@(refs* xs))]
      [`(absent ,rel ,ord ,K ,xs ...)
       `(absent ,(rel! rel) ,ord ,K ,@(refs* xs))]
      [`(absent-lat ,rel ,ord ,K ,xs ...)
       `(absent-lat ,(rel! rel) ,ord ,K ,@(refs* xs))]
      [`(join-lat ,rel ,ord ,K ,xs ...)
       `(join-lat ,(rel! rel) ,ord ,K ,@(refs* xs))]
      [`(let ,x (,f ,ys ...))
       (prim! f)
       `(let ,(ref! x) (prim ,f ,@(refs* ys)))]
      [`(let ,x ,y) `(let ,(ref! x) ,(ref! y))]
      [`(letp ,x (,f ,ys ...))
       (prim! f)
       `(letp ,(ref! x) (prim ,f ,@(refs* ys)))]
      [`(cjoin ,x ,spec ,a ,b)
       `(cjoin ,(ref! x) ,spec ,(ref! a) ,(ref! b))]
      [`(eq ,x ,y) `(eq ,(ref! x) ,(ref! y))]
      [`(neq ,x ,y) `(neq ,(ref! x) ,(ref! y))]
      [`(cmp ,f ,x ,y)
       (prim! f)
       `(cmp ,f ,(ref! x) ,(ref! y))]))
  (define (hop->canon op)
    (match op
      [`(mkstruct ,rel ,ord ,x ,fields ...)
       `(mkstruct ,(rel! rel) ,ord ,(ref! x) ,@(refs* fields))]
      [`(emit ,rel ,ord ,xs ...) `(emit ,(rel! rel) ,ord ,@(refs* xs))]
      [`(emit-temp ,rel ,xs ...) `(emit-temp ,(rel! rel) ,@(refs* xs))]
      [`(emit-lat ,rel ,xs ...) `(emit-lat ,(rel! rel) ,@(refs* xs))]
      [`(tycheck ,x (accept ,ts ...) ,rid ,rel ,col ,ord)
       `(tycheck ,(ref! x) (accept ,@ts)
                 ,(ref! rid) ,(ref! rel) ,(ref! col) ,ord)]
      [_ (op->canon op)]))
  (define (driver->canon d)
    (match d
      [`(scan ,rel ,xs ...) `(scan ,(rel! rel) ,@(refs* xs))]
      [`(probe ,rel ,ord ,K ,xs ...)
       `(probe ,(rel! rel) ,ord ,K ,@(refs* xs))]
      [d d]))
  (define pre (map op->canon (crule-pre cr)))
  (define driver (driver->canon (crule-driver cr)))
  (define body (map op->canon (crule-body cr)))
  (define head (map hop->canon (crule-head cr)))
  `((nregs ,(hash-count regs))
    (pre ,@pre)
    (driver ,driver)
    (body ,@body)
    (head ,@head)))

;; The stat base tag, reproducing emit-cpp's convention exactly: scan/probe
;; drivers are "delta:<rel>" when the relation is stratum-dynamic and
;; "all:<rel>" otherwise (emit-cpp's static?); count-flavor kinds suffix.
(define (base-tag driver kind dynamic-rels)
  (define base
    (match driver
      [`(once) "once"]
      [`(seeded) "seeded"]
      [`(,_ ,name ,_ ...)
       (format "~a:~a"
               (if (set-member? dynamic-rels name) "delta" "all")
               name)]))
  (if kind (format "~a/~a" base kind) base))

;; ------------------------------------------------------------------------
;; The pass.

(define (canonicalize-cprog cp #:flavor [flavor 'normal])
  (define-values (kp _tags) (canonicalize-cprog/tags cp #:flavor flavor))
  kp)

(define (canonicalize-cprog/tags cp #:flavor [flavor 'normal])
  (define constants (cprog-constants cp))
  ;; globalize-constants keys value -> generated name; tolerate either
  ;; orientation (the generated name is always the symbol side)
  (define const-pairs                       ; (name . value), sorted by name
    (sort (for/list ([(k v) (in-hash constants)])
            (if (symbol? v) (cons v k) (cons k v)))
          symbol<? #:key car))
  (define const-ix
    (for/hash ([p (in-list const-pairs)] [i (in-naturals)])
      (values (car p) i)))
  (define (const-slot v) (hash-ref const-ix v #f))
  ;; storage decls take slots; oracle/seqindex decls reference existing
  ;; names and ride as raw attachments (T2's installer resolves them)
  (define all-decls (sort (cprog-decls cp) sexp<?))
  (define-values (storage attachments)
    (partition (lambda (d) (memq (car d) '(relation struct lattice temp)))
               all-decls))
  (define rel-ix
    (for/hash ([d (in-list storage)] [i (in-naturals)])
      (values (second d) i)))
  (define (rel-slot name)
    (or (hash-ref rel-ix name #f)
        (error 'canonicalize-cprog "unslotted relation ~a" name)))
  (define dynamic-rels (cprog-dynamic-rels cp))
  (define prim-names (mutable-set))
  (define (prim! f) (set-add! prim-names f))
  ;; canonicalize every crule, then sort by canonical text (edit-stable, D4)
  (define entries                    ; (vector crule canon tagbase loc canonstr)
    (for/list ([cr (in-list (cprog-rules cp))])
      (define canon (canonicalize-crule cr const-slot rel-slot prim!))
      (vector cr canon
              (base-tag (crule-driver cr) (crule-kind cr) dynamic-rels)
              (crule-loc cr)
              (sexp->string canon))))
  (define sorted
    (sort entries string<? #:key (lambda (e) (vector-ref e 4))))
  ;; rid assignment: located source rules in (file, line) order, then each
  ;; #f-loc crule as its own rid in canonical rule order
  (define located-locs
    (sort (remove-duplicates
           (filter values (map (lambda (e) (vector-ref e 3)) sorted)))
          loc-key<? #:key loc-key))
  (define loc->rid
    (for/hash ([loc (in-list located-locs)] [i (in-naturals)])
      (values loc i)))
  (define next-rid (box (length located-locs)))
  (define (rid-of e)
    (cond [(vector-ref e 3) => (lambda (loc) (hash-ref loc->rid loc))]
          [else (let ([r (unbox next-rid)])
                  (set-box! next-rid (add1 r))
                  r)]))
  (define with-rids                          ; (vector crule canon tag rid loc)
    (for/list ([e (in-list sorted)])
      (vector (vector-ref e 0) (vector-ref e 1) (vector-ref e 2)
              (rid-of e) (vector-ref e 3))))
  ;; ordinal suffix IFF a (rid, base-tag) group holds several variants (D3);
  ;; ordinals follow canonical rule order
  (define group-sizes (make-hash))
  (for ([e (in-list with-rids)])
    (define key (cons (vector-ref e 3) (vector-ref e 2)))
    (hash-update! group-sizes key add1 0))
  (define group-seen (make-hash))
  (define tagged                             ; (vector crule canon tag rid loc)
    (for/list ([e (in-list with-rids)])
      (define key (cons (vector-ref e 3) (vector-ref e 2)))
      (define tag
        (if (> (hash-ref group-sizes key) 1)
            (let ([n (hash-ref group-seen key 0)])
              (hash-set! group-seen key (add1 n))
              (format "~a#~a" (vector-ref e 2) n))
            (vector-ref e 2)))
      (vector (vector-ref e 0) (vector-ref e 1) tag
              (vector-ref e 3) (vector-ref e 4))))
  (define rule-defs
    (for/list ([e (in-list tagged)])
      `(rule-def (rid ,(vector-ref e 3)) (variant ,(vector-ref e 2))
                 ,@(vector-ref e 1))))
  (define metas
    (sort (remove-duplicates
           (for/list ([e (in-list tagged)])
             `(rule-meta (rid ,(vector-ref e 3))
                         (source ,(vector-ref e 4)))))
          < #:key (lambda (m) (second (second m)))))
  (values
   `(kernel-plan
     (abi 1)
     (flavor ,flavor)
     (relations
      ,@(for/list ([d (in-list storage)] [i (in-naturals)]) `(rel ,i ,d)))
     (attachments ,@attachments)
     (constants
      ,@(for/list ([p (in-list const-pairs)] [i (in-naturals)])
          `(k ,i ,(car p) ,(cdr p))))
     (prims ,@(sort (set->list prim-names) symbol<?))
     (dynamic ,@(sort (set->list dynamic-rels) symbol<?))
     (rules ,@rule-defs)
     (meta ,@metas))
   ;; crule -> (rid . tag), for callers aligning with cprog-rules order
   (for/hash ([e (in-list tagged)])
     (values (vector-ref e 0)
             (cons (vector-ref e 3) (vector-ref e 2))))))

;; (rid . tag) per crule, aligned with (cprog-rules cp).  Identical crules
;; (impossible from one planned-rule set, but harmless) share one entry.
(define (canonical-rule-tags cp #:flavor [flavor 'normal])
  (define-values (_plan tag-map) (canonicalize-cprog/tags cp #:flavor flavor))
  (for/list ([cr (in-list (cprog-rules cp))])
    (hash-ref tag-map cr)))

;; ------------------------------------------------------------------------
;; Serialization and KernelPlanKey.  One `write` line (D6): the daemon's
;; line-framed dispatcher reads it whole; pretty-printing is for humans.

(define (kernel-plan->string kp)
  (sexp->string kp))

(define (kernel-plan-key kp)
  (bytes->hex-string (sha256 (string->bytes/utf-8 (kernel-plan->string kp)))))
