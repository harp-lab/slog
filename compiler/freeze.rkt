#lang racket

;; Ground-fact peeling (the freeze path).  A head-only rule whose heads are
;; entirely ground asserts pure DATA; a large one (an AST literal, a dumped
;; program IR) costs staged codegen and clang time proportional to its size
;; for nothing.  When a program's ground rules total at least
;; SLOG_FREEZE_MIN term nodes (default 512; SLOG_NO_FREEZE disables), peel
;; them out of the program, print them as a fact STREAM, and render the
;; stream to a static .bin database (daemon/slog-freeze) under
;; build/frozen/<hash>/ -- content-addressed by the stream text plus the
;; daemon-headers fingerprint (the value-encoding version).  The driver
;; imports it before stratum 0 (importDatabaseBIN's content remap), so the
;; facts arrive as EDB exactly as a -d input's would; a saved database
;; materializes the rows like any others.  The build/ copy remains, so
;; wiping data/ and rerunning re-links (or re-freezes) from source.
;;
;; Peeling is DISABLED under a source-override (a compression replay: the
;; recipe re-derives its facts through the rule path -- equivalent rows by
;; the freezer's bit-compatible encodings, just slower) and for
;; --out-db-compressed runs (the EDB-boundary split owns iteration-0 facts
;; there).  Both paths stay correct because the two routes intern
;; identically; freezing is purely a compile-time optimization.
;;
;; The stream grammar (see daemon/freeze.cpp):
;;   (struct <name> <field-count>) (table <name> <arity>) (enum <name>)
;;   (<name> <ground-term> ...)
;; with string escapes limited to \\ \" \n \t \r -- the emitter below
;; produces only those, everything else as raw UTF-8.

(provide peel-ground-facts)

(require "parser.rkt")   ; current-source-override
(require "tools.rkt")    ; daemon-headers-fingerprint
(require "ir-shared.rkt")
(require "sha256.rkt")

(define (bracket-sym? h)
  (and (symbol? h) (equal? (symbol->string h) "[]")))

;; A construction-position bracket `[e ...]` is lowered, BEFORE the peel pass
;; runs, to a nested lempty/lpush/lcat prim chain (collections.rkt
;; walk-construction: lpush appends an element, lcat splices a subsequence,
;; lempty is the base).  In a head-only GROUND rule such a chain is just a
;; ground sequence literal, so recognize it here -- otherwise any ground fact
;; carrying a list (e.g. an extracted program AST full of [Clause]/[Ref]/[Exp])
;; is deemed non-peelable and falls to the rule path, whose per-join brace
;; nesting overflows codegen at scale (docs/freeze-list-peel-gap.md).
(define (seq-ctor? h) (and (symbol? h) (and (memq h '(lempty lpush lcat)) #t)))

;; Flatten a ground lempty/lpush/lcat chain to its element renderings, in order,
;; so the emitter can write it back as the `[e ...]` stream form the freezer
;; already ingests (docs/freeze.md §3).  Mutually recursive with term->string
;; (an element may itself be a nested sequence or struct).
(define (seq->elem-strings e rel-env decls)
  (match e
    [`(syn ,_ lempty) '()]
    [`(syn ,_ lpush ,acc ,elem)
     (append (seq->elem-strings acc rel-env decls)
             (list (term->string elem rel-env decls)))]
    [`(syn ,_ lcat ,acc ,sub)
     (append (seq->elem-strings acc rel-env decls)
             (seq->elem-strings sub rel-env decls))]))

;; -----------------------------------------------------------------------
;; Classification: (peelable-heads rule rel-env) -> (cons node-count heads)
;; when the rule is head-only and every head is a ground assertion into a
;; plain table or struct (a ground ask); #f otherwise.

(define (peelable-heads rule rel-env)
  (let/ec bail
    (match rule
      [`(syn ,_ rule --> ,heads ...)
       #:when (pair? heads)
       (define nodes 0)
       (define (term! e)
         (set! nodes (add1 nodes))
         (match e
           [`(syn ,_ const ,_) (void)]
           [`(syn ,_ ,(? symbol? h) ,args ...)
            (cond
              [(bracket-sym? h) (for-each term! args)]
              ;; a desugared bracket: a ground sequence literal (see seq-ctor?)
              [(seq-ctor? h) (for-each term! args)]
              [else
               (match (hash-ref rel-env h #f)
                 [`(struct ,ts ...)
                  (unless (= (length args) (length ts)) (bail #f))
                  (for-each term! args)]
                 [`(enum ,_)
                  (unless (null? args) (bail #f))]
                 [_ (bail #f)])])]
           [_ (bail #f)]))  ; a bare symbol is a variable
       (for ([cl (in-list heads)])
         (match cl
           [`(syn ,_ ,(? symbol? name) ,args ...)
            #:when (and (not (bracket-sym? name)) (pair? args))
            (match (hash-ref rel-env name #f)
              [`(table ,ts ...)
               (unless (= (length args) (length ts)) (bail #f))
               ;; v1 exclusion: lattice-valued columns merge on ingestion --
               ;; leave those rules on the rule path
               (when (for/or ([t (in-list ts)])
                       (match (hash-ref rel-env t #f)
                         [(cons 'lattice _) #t]
                         [_ #f]))
                 (bail #f))
               (for-each term! args)]
              [`(struct ,ts ...)  ; a ground ask: intern the instance
               (unless (= (length args) (length ts)) (bail #f))
               (for-each term! args)]
              [_ (bail #f)])]
           [_ (bail #f)]))
       (cons nodes heads)]
      [_ #f])))

;; -----------------------------------------------------------------------
;; Emission.

(define (escape s)
  (apply string-append
         (for/list ([c (in-string s)])
           (case c
             [(#\\) "\\\\"]
             [(#\") "\\\""]
             [(#\newline) "\\n"]
             [(#\tab) "\\t"]
             [(#\return) "\\r"]
             [else (string c)]))))

;; decls : name -> (list 'struct n) | (list 'table n) | (list 'enum)
(define (term->string e rel-env decls)
  (match e
    [`(syn ,_ const ,(? string? s)) (format "\"~a\"" (escape s))]
    [`(syn ,_ const ,(? number? n)) (number->string n)]
    [`(syn ,_ ,(? bracket-sym?) ,args ...)
     (format "[~a]" (string-join
                     (for/list ([a (in-list args)])
                       (term->string a rel-env decls))))]
    ;; a desugared bracket (lempty/lpush/lcat chain): render as the `[e ...]`
    ;; stream form -- bit-identical to a bracket, since both intern through the
    ;; same sequence kernels (docs/freeze.md §3)
    [`(syn ,_ ,(? seq-ctor?) ,_ ...)
     (format "[~a]" (string-join (seq->elem-strings e rel-env decls)))]
    [`(syn ,_ ,(? symbol? h) ,args ...)
     (match (hash-ref rel-env h)
       [`(enum ,_) (hash-set! decls h '(enum))]
       [`(struct ,ts ...) (hash-set! decls h (list 'struct (length ts)))])
     (format "(~a~a)" h
             (apply string-append
                    (for/list ([a (in-list args)])
                      (string-append " " (term->string a rel-env decls)))))]))

(define (head->string cl rel-env decls)
  (match cl
    [`(syn ,_ ,(? symbol? name) ,args ...)
     (match (hash-ref rel-env name)
       [`(table ,ts ...) (hash-set! decls name (list 'table (length ts)))]
       [`(struct ,ts ...) (hash-set! decls name (list 'struct (length ts)))])
     (format "(~a~a)" name
             (apply string-append
                    (for/list ([a (in-list args)])
                      (string-append " " (term->string a rel-env decls)))))]))

;; -----------------------------------------------------------------------
;; The pass: (values mods+ frozen) with frozen #f or (cons hash stream).

(define (freeze-min-nodes)
  (cond
    [(getenv "SLOG_NO_FREEZE") +inf.0]
    [(getenv "SLOG_FREEZE_MIN") => string->number]
    [else 512]))

(define (peel-ground-facts mods type-env #:enabled? [enabled? #t])
  (define rel-env (type-env-rels type-env))
  (define minimum (freeze-min-nodes))
  (cond
    [(or (not enabled?) (current-source-override) (= minimum +inf.0))
     (values mods #f)]
    [else
     (define mod-list (set->list mods))
     ;; Modules retain lexical occurrence metadata through this pass; frozen
     ;; fact selection itself only needs their path and rule set.
     (define picked   ; list of (list mod-path rule (cons nodes heads))
       (for*/list ([m (in-list mod-list)]
                   [rule (in-set (module-ir-rules m))]
                   [ph (in-value (peelable-heads rule rel-env))]
                   #:when ph)
         (list (module-ir-path m) rule ph)))
     (define total (for/sum ([p (in-list picked)]) (car (third p))))
     (cond
       [(< total minimum) (values mods #f)]
       [else
        (define peeled-rules
          (for/fold ([h (hash)]) ([p (in-list picked)])
            (hash-update h (first p)
                         (lambda (s) (set-add s (second p)))
                         (set))))
        (define mods+
          (for/set ([m (in-list mod-list)])
            (struct-copy
             module-ir m
             [rules
              (set-subtract
               (module-ir-rules m)
               (hash-ref peeled-rules (module-ir-path m) (set)))])))
        (define decls (make-hash))
        (define lines
          (sort (for*/list ([p (in-list picked)]
                            [cl (in-list (cdr (third p)))])
                  (head->string cl rel-env decls))
                string<?))
        (define decl-lines
          (sort (for/list ([(name d) (in-hash decls)])
                  (match d
                    [`(enum) (format "(enum ~a)" name)]
                    [`(,kind ,n) (format "(~a ~a ~a)" kind name n)]))
                string<?))
        (define stream
          (string-append (string-join decl-lines "\n") "\n"
                         (string-join lines "\n") "\n"))
        (define h
          (substring
           (bytes->hex-string
            (sha256 (string->bytes/utf-8
                     (string-append stream daemon-headers-fingerprint))))
           0 12))
        (values mods+ (cons h stream))])]))
