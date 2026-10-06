#lang racket

;; The static check: everything that can reject a program before it runs --
;; parse, includes, demand, types, negation safety, stratification, lattices
;; -- and nothing after: no planning, codegen, cache key, daemon or session.
;; It is the compiler's own front end (compile.rkt's check-program), so a
;; program passes exactly when compiling it would get past the front end.
;;
;;   racket compiler/check.rkt [--json] FILE ...   (also run.rkt --check FILE)
;;   racket compiler/check.rkt --serve             one JSON request a line:
;;     {"id": 1, "path": "/abs/main.slog", "sources": {"/abs/main.slog": "..."}}
;;
;; `sources` are unsaved texts, read in place of the files they name (the
;; parser's source override), so an editor's buffers check where they sit
;; and their includes resolve.  A diagnostic is
;;   {"severity": "error"|"warning", "file", "line", "col", "message", "located"}
;; with 1-based lines and columns (docs/REPL-exploration-kris/notes/
;; static-check-design.md).

(require json
         (only-in racket/hash hash-union)
         "parser.rkt"
         (only-in "modules.rkt" load-program-list)
         (only-in "compile.rkt" check-program)
         (only-in "type-system.rkt" current-rule-errors current-rule-types)
         (only-in "lexer.rkt" token->tag token->pos token->str pos->file
                  pos->startline pos->startcol pos->endline pos->endcol)
         (only-in "ir-shared.rkt" module-ir-path module-ir-tokens
                  program-ir-modules program-ir-type-env type-env-rels))

(provide check-file
         check-file/info
         check-report
         diagnostic-line)

;; path [sources: path-string -> text] -> (listof diagnostic), errors first,
;; each kind in source order
(define (check-file path #:sources [sources (hash)])
  (define-values (diagnostics _info) (check-file/info path #:sources sources))
  diagnostics)

;; The diagnostics, and what the check learned of the program for an editor
;; (see program-info), or #f when it did not get past parsing.
(define (check-file/info path #:sources [sources (hash)])
  (define main (path->string (path->complete-path path)))
  (define override
    (and (positive? (hash-count sources))
         ;; an include resolves through normalize-path, which follows
         ;; symlinks (/tmp -> /private/tmp): key each text both ways
         (for*/hash ([(file text) (in-hash sources)]
                     [key (in-list (list file (resolved file)))])
           (values (source-key key) text))))
  (define errors (box '()))
  (define warnings (open-output-string))
  (define programs '())
  (define rule-types '())
  (define failure
    (parameterize ([parse-errors-raise? #t]
                   [current-source-override override]
                   [current-rule-errors errors]
                   [current-rule-types (lambda (rule env)
                                         (set! rule-types (cons (cons rule env) rule-types)))]
                   [current-error-port warnings])
      (with-handlers ([exn:fail? values])
        (set! programs (load-program-list main (hash)))
        (for-each check-program programs)
        #f)))
  (define known (cons main (hash-keys sources)))
  (define (error-diagnostic e)
    (if (exn:fail:slog-parse? e)
        (diagnostic "error" (as-known (~a (exn:fail:slog-parse-file e)) known)
                    (exn:fail:slog-parse-line e) (exn:fail:slog-parse-col e)
                    (exn-message e) main)
        (located "error" (exn-message e) main known)))
  (define failures
    (cond
      [(pair? (unbox errors)) (unbox errors)]
      [failure (list failure)]
      [else '()]))
  (values
   (append
    (sort (map error-diagnostic failures) diagnostic<?)
    (for/list ([w (in-list (warning-messages (get-output-string warnings)))])
      (located "warning" w main known)))
   (and (pair? programs)
        (let ([names (make-hash)])
          (program-info programs rule-types
                        (lambda (file) (hash-ref! names file (lambda () (as-known file known)))))))))

;; "warning: ..." blocks of the front end's stderr, continuation lines kept
(define (warning-messages text)
  (reverse
   (for/fold ([out '()]) ([line (in-list (string-split text "\n"))])
     (cond
       [(string-prefix? line "warning: ")
        (cons (substring line (string-length "warning: ")) out)]
       [(and (pair? out) (regexp-match? #rx"^[ \t]" line))
        (cons (string-append (car out) "\n" line) (cdr out))]
       [else out]))))

;; A message's own location: the first NAME.slog:LINE[:COL] naming one of
;; the program's files (the passes spell locations with rule-location-
;; string); else line 1 of the main file, marked unlocated.
(define (located severity message main known)
  (define found
    (for/or ([m (in-list (regexp-match* #px"([^\\s:\"'`(]+\\.slog):([0-9]+)(?::([0-9]+))?"
                                        message #:match-select values))])
      (define file (resolve-name (second m) main known))
      (and file (list file (string->number (third m))
                      (if (fourth m) (string->number (fourth m)) 1)))))
  (match found
    [(list file line col) (diagnostic severity file line col message main)]
    [#f (hash-set (diagnostic severity main 1 1 message main) 'located #f)]))

(define (resolved file)
  (with-handlers ([exn:fail? (lambda (_) file)]) (normalize-path file)))

;; a file as the caller named it, though the loader may have followed links
(define (as-known file known)
  (or (for/first ([k (in-list known)]
                  #:when (equal? (resolved k) (resolved file)))
        k)
      file))

(define (resolve-name name main known)
  (define base (file-name-from-path name))
  (or (for/first ([file (in-list known)]
                  #:when (equal? (file-name-from-path file) base))
        file)
      (let ([beside (build-path (path-only main) name)])
        (and (file-exists? beside) (path->string (simplify-path beside))))))

(define (diagnostic severity file line col message main)
  (hasheq 'severity severity
          'file file
          'line line
          'col col
          ;; the location is in the record; drop its spelling from the text
          'message (regexp-replace #px"^[^\\s:]+\\.slog:[0-9]+(:[0-9]+)?: " message "")
          'located #t))

(define (diagnostic<? a b)
  (define (key d) (list (hash-ref d 'file) (hash-ref d 'line) (hash-ref d 'col)))
  (match* ((key a) (key b))
    [((list fa la ca) (list fb lb cb))
     (or (string<? fa fb)
         (and (string=? fa fb) (or (< la lb) (and (= la lb) (< ca cb)))))]))

;; The check of `path` as one JSON-ready answer.
(define (check-report path #:sources [sources (hash)])
  (define start (current-inexact-milliseconds))
  (define-values (diagnostics info)
    (with-handlers ([exn:fail? (lambda (e)
                                 (values (list (located "error" (exn-message e) path '())) #f))])
      (check-file/info path #:sources sources)))
  (hasheq 'ok (not (for/or ([d (in-list diagnostics)])
                     (equal? (hash-ref d 'severity) "error")))
          'ms (inexact->exact (round (- (current-inexact-milliseconds) start)))
          'diagnostics diagnostics
          'info (or info 'null)))

(define (diagnostic-line d)
  (format "~a:~a:~a: ~a: ~a" (hash-ref d 'file) (hash-ref d 'line) (hash-ref d 'col)
          (hash-ref d 'severity) (hash-ref d 'message)))

;; ---- what the check learned, for an editor's hovers and navigation ------
;;
;; {"rules":   [{"file", "line", "col", "end_line", "end_col",
;;               "vars": [{"name", "type", "line", "col"}]}],
;;  "symbols": [{"name", "kind", "signature", "decl", "doc",
;;               "def": {"file", "line", "col"} | null,
;;               "refs": [{"file", "line", "col", "role"}]}]}
;;
;; A rule's vars are the ones the typechecker inferred, each at its first
;; occurrence.  A symbol is a declared relation, struct, constructor or
;; type: its declaration as written, the comment beside or above it, and
;; every place its name is written -- "def", "write" (a head atom), "read"
;; (a body atom) or "use" (anything else: a nested constructor, a column
;; type).  Positions are 1-based; end_col is exclusive.

(define declaring-words '("table" "struct" "union" "enum" "lattice" "demand" "extern"))
(define top-level-words
  (append declaring-words '("def" "rule" "include" "instantiate" "run" "let" "import" "export")))

(define (program-info programs rule-types name-of)
  (define rels
    (for*/fold ([h (hash)]) ([p (in-list programs)]
                             [(k v) (in-hash (type-env-rels (program-ir-type-env p)))])
      (hash-set h k v)))
  (define mods
    (remove-duplicates (append-map (lambda (p) (set->list (program-ir-modules p))) programs)
                       #:key module-ir-path))
  (define (place tok)
    (define pos (token->pos tok))
    (hasheq 'file (name-of (~a (pos->file pos)))
            'line (add1 (pos->startline pos))
            'col (add1 (pos->startcol pos))))
  (define symbols (make-hash))   ; name -> mutable record
  (define (symbol-entry name)
    (hash-ref! symbols name
               (lambda ()
                 (define decl (hash-ref rels name))
                 (make-hasheq (list (cons 'name (symbol->string name))
                                    (cons 'kind (~a (if (pair? decl) (car decl) decl)))
                                    (cons 'signature (~a decl))
                                    (cons 'decl 'null) (cons 'doc 'null) (cons 'def 'null)
                                    (cons 'refs '()))))))
  ;; (cons file line) -> that line's identifier tokens, to place a rule's
  ;; variables
  (define ids (make-hash))
  (for ([m (in-list mods)])
    (define all
      (filter (lambda (t) (not (memq (token->tag t) '(space newline eof))))
              (module-ir-tokens m)))
    (define code (filter (lambda (t) (not (eq? (token->tag t) 'comment))) all))
    (for ([t (in-list (reverse code))] #:when (eq? (token->tag t) 'id))
      (hash-update! ids (cons (module-ir-path m) (pos->startline (token->pos t)))
                    (lambda (ts) (cons t ts)) '()))
    (define code-lines (for/set ([t (in-list code)]) (pos->startline (token->pos t))))
    (define comments
      (for/hash ([t (in-list all)] #:when (eq? (token->tag t) 'comment))
        (values (pos->startline (token->pos t))
                (string-trim (string-trim (token->str t) #rx";+")))))
    ;; the comment beside a line, else the comment lines just above it
    (define (doc-of line)
      (or (and (set-member? code-lines line) (hash-ref comments line #f))
          (let loop ([l (sub1 line)] [above '()])
            (if (and (hash-has-key? comments l) (not (set-member? code-lines l)))
                (loop (sub1 l) (cons (hash-ref comments l) above))
                (and (pair? above) (string-join above "\n"))))))
    (for ([form (in-list (top-level-forms code))])
      (note-form! (car form) (cdr form) rels symbol-entry place doc-of)))
  (define rules
    (for/fold ([by-span (hash)]) ([rt (in-list rule-types)])
      (match (car rt)
        [`(syn (prov ,(? pair? left) ,(? pair? right)) ,_ ...)
         (define lp (token->pos left))
         (define rp (token->pos right))
         (define span (list (~a (pos->file lp)) (pos->startline lp) (pos->startcol lp)
                            (pos->endline rp) (pos->endcol rp)))
         (hash-update by-span span (lambda (vars) (hash-union vars (cdr rt) #:combine (lambda (a _) a)))
                      (cdr rt))]
        [_ by-span])))
  (hasheq
   'rules
   (for/list ([(span types) (in-hash rules)])
     (match-define (list file line col end-line end-col) span)
     (define (inside? t)
       (define p (token->pos t))
       (define here (list (pos->startline p) (pos->startcol p)))
       (and (not (before? here (list line col))) (before? here (list end-line end-col))))
     ;; the first occurrence of each named variable the typechecker typed
     (define vars
       (for*/fold ([seen (hash)] #:result (hash-values seen))
                 ([l (in-range line (add1 end-line))]
                  [t (in-list (hash-ref ids (cons file l) '()))]
                  #:when (inside? t))
         (define x (string->symbol (token->str t)))
         (define ty (hash-ref types x #f))
         (if (or (not ty) (hash-has-key? seen x))
             seen
             (hash-set seen x (hash-set* (place t) 'name (symbol->string x) 'type (~a ty))))))
     (hasheq 'file (name-of file) 'line (add1 line) 'col (add1 col)
             'end_line (add1 end-line) 'end_col (add1 end-col)
             'vars (sort vars before? #:key (lambda (v) (list (hash-ref v 'line) (hash-ref v 'col))))))
   'symbols
   (for/list ([entry (in-hash-values symbols)])
     (hash-update (for/hasheq ([(k v) (in-hash entry)]) (values k v)) 'refs reverse))))

;; code tokens -> (listof (cons keyword tokens)): one per top-level form,
;; which starts with its keyword in the first column
(define (top-level-forms code)
  (let loop ([toks code] [form #f] [out '()])
    (define (done) (if form (cons (cons (car form) (reverse (cdr form))) out) out))
    (match toks
      ['() (reverse (done))]
      [(cons t rest)
       (if (and (eq? (token->tag t) 'id) (zero? (pos->startcol (token->pos t)))
                (member (token->str t) top-level-words))
           (loop rest (list (token->str t)) (done))
           (loop rest (and form (list* (car form) t (cdr form))) out))])))

;; Record the declared names one form writes, with their roles.
(define (note-form! word toks rels symbol-entry place doc-of)
  (define arrow
    (for/first ([t (in-list toks)] #:when (member (token->str t) '("-->" "<--")))
      (token->str t)))
  (define (text toks)
    (for/fold ([out ""] [end #f] [line #f] #:result out) ([t (in-list toks)])
      (define pos (token->pos t))
      (values (string-append out
                             (if (and end (or (not (= line (pos->startline pos)))
                                              (> (pos->startcol pos) end)))
                                 " " "")
                             (token->str t))
              (pos->endcol pos)
              (pos->startline pos))))
  (for/fold ([depth 0] [opened? #f] [after-arrow? #f] #:result (void))
            ([t (in-list toks)])
    (define str (token->str t))
    (define name (string->symbol str))
    (when (and (eq? (token->tag t) 'id) (hash-has-key? rels name))
      (define entry (symbol-entry name))
      (define role
        (cond
          [(and (member word declaring-words) opened?
                (or (= depth 1) (and (equal? word "union") (= depth 2))))
           "def"]
          [(and (equal? word "rule") opened? (= depth 1))
           (if (match arrow
                 [#f #t]
                 ["-->" after-arrow?]
                 ["<--" (not after-arrow?)])
               "write"
               "read")]
          [else "use"]))
      (when (equal? role "def")
        (hash-set! entry 'def (place t))
        (hash-set! entry 'decl (format "~a ~a" word (text toks)))
        (hash-set! entry 'doc (or (doc-of (pos->startline (token->pos t))) 'null)))
      (hash-update! entry 'refs (lambda (refs) (cons (hash-set (place t) 'role role) refs))))
    (values (cond [(member str '("(" "[" "{")) (add1 depth)]
                  [(member str '(")" "]" "}")) (sub1 depth)]
                  [else depth])
            (equal? str "(")
            (or after-arrow? (and (= depth 0) (member str '("-->" "<--")) #t)))))

(define (before? a b)
  (or (< (first a) (first b)) (and (= (first a) (first b)) (< (second a) (second b)))))

(define (serve)
  (let loop ()
    (define line (read-line))
    (unless (eof-object? line)
      (define answer
        (with-handlers ([exn:fail? (lambda (e) (hasheq 'error (exn-message e)))])
          (define request (string->jsexpr line))
          (define sources
            (for/hash ([(file text) (in-hash (hash-ref request 'sources (hasheq)))])
              (values (symbol->string file) text)))
          (hash-set (check-report (hash-ref request 'path) #:sources sources)
                    'id (hash-ref request 'id 0))))
      (write-json answer)
      (newline)
      (flush-output)
      (loop))))

(module+ main
  (define json? #f)
  (define serve? #f)
  (command-line
   #:program "check"
   #:once-each
   [("--json") "Print one JSON report per file" (set! json? #t)]
   [("--serve") "Answer JSON requests, one a line, on stdin" (set! serve? #t)]
   #:args files
   (cond
     [serve? (serve)]
     [else
      (define reports (for/list ([file (in-list files)]) (check-report file)))
      (for ([report (in-list reports)])
        (if json?
            (begin (write-json report) (newline))
            (for ([d (in-list (hash-ref report 'diagnostics))])
              (displayln (diagnostic-line d)))))
      (exit (if (andmap (lambda (r) (hash-ref r 'ok)) reports) 0 1))])))

(module+ test
  (require rackunit)
  ;; programs checked from text, as an editor's unsaved buffers are
  (define dir (path->string (find-system-path 'temp-dir)))
  (define (check text #:file [file "main.slog"] #:more [more (hash)])
    (define main (path->string (build-path dir file)))
    (for/list ([d (in-list (check-file main #:sources (hash-set more main text)))])
      (list (hash-ref d 'severity)
            (path->string (file-name-from-path (hash-ref d 'file)))
            (hash-ref d 'line) (hash-ref d 'col)
            (hash-ref d 'message))))
  (define (where ds) (map (lambda (d) (take d 4)) ds))

  (check-equal? (check "table (edge int int)\ntable (path int int)\nrule (edge 1 2)\nrule (edge X Y) --> (path X Y)\n")
                '())

  ;; an unclosed ( is blamed on its opener, not on the end of the file
  (define unclosed
    (check "table (lib str int)\nrule (lib \"plus\"\n  (+ 1\n     2)\n"))
  (check-equal? (where unclosed) '(("error" "main.slog" 2 6)))
  (check-regexp-match #rx"the \\( at 2:6 opening `\\(lib \"plus\" ...` is never closed \\(1 open at end of file\\)"
                      (fifth (first unclosed)))
  ;; ... and before the next top-level form, when one starts while it is open
  (check-equal? (where (check "table (a int)\nrule (a 1\nrule (a 2)\n"))
                '(("error" "main.slog" 2 6)))
  ;; an extra or mismatched closer is reported where it is
  (check-equal? (check "table (a int)\nrule (a 1))\n")
                '(("error" "main.slog" 2 11 "the ) at 2:11 has nothing to close")))
  (check-equal? (check "table (a int)\nrule (a 1]\n")
                '(("error" "main.slog" 2 10 "the ] at 2:10 does not close the ( at 2:6")))
  ;; brackets inside strings and comments do not count
  (check-equal? (check "table (s str)\nrule (s \"(((\") ;; )))\n") '())

  ;; every rule's type error, in source order
  (check-equal? (where (check "table (a int)\nrule (a \"s\")\nrule (a x) --> (c x)\n"))
                '(("error" "main.slog" 2 1) ("error" "main.slog" 3 16)))
  ;; an error quotes the text as given, not the file on disk
  (check-regexp-match #rx"in\n  rule \\(a \"s\"\\)$"
                      (fifth (first (check "table (a int)\nrule (a \"s\")\n"))))
  ;; constructors under negation, and negation through recursion
  (check-equal? (where (check (string-append "union (n (zero) (pos))\ntable (a int)\ntable (h int n)\n"
                                             "rule (a 1)\nrule (a x) ~(h x (pos)) --> (h x (zero))\n")))
                '(("error" "main.slog" 5 12)))
  (check-regexp-match #rx"negation through recursion"
                      (fifth (first (check "table (a int)\ntable (b int)\nrule (a x) ~(b x) --> (b x)\n"))))
  ;; an error in an included file is located there
  (check-equal? (where (check "include \"lib.slog\"\ntable (a int)\nrule (a 1)\n"
                              #:more (hash (path->string (build-path dir "lib.slog"))
                                           "table (b int)\nrule (b \"x\")\n")))
                '(("error" "lib.slog" 2 1)))
  ;; a syntax error in an included file names it as the caller did
  (define lib (path->string (build-path dir "lib.slog")))
  (check-equal? (map (lambda (d) (hash-ref d 'file))
                     (check-file (path->string (build-path dir "main.slog"))
                                 #:sources (hash (path->string (build-path dir "main.slog"))
                                                 "include \"lib.slog\"\n"
                                                 lib "table (b int\n")))
                (list lib))
  ;; a missing include is a warning, not an error
  (check-equal? (map first (check "include \"no-such-file-xyz.slog\"\ntable (a int)\nrule (a 1)\n"))
                '("warning")))

(module+ test
  ;; what an editor's hovers read: each variable's type at its first
  ;; occurrence, and a relation's declaration, comment and uses
  (let ()
    (define main (path->string (build-path (find-system-path 'temp-dir) "info.slog")))
    (define-values (diagnostics info)
      (check-file/info main #:sources
                       (hash main (string-append "table (edge int int)\n"
                                                 "table (name int str) ;; a node's label\n"
                                                 "rule (edge 1 2) (name 1 \"a\")\n"
                                                 "rule (edge x y) (name x s) --> (name y s)\n"))))
    (check-equal? diagnostics '())
    (define rule4
      (for/first ([r (in-list (hash-ref info 'rules))] #:when (= 4 (hash-ref r 'line))) r))
    (check-equal? (for/list ([v (in-list (hash-ref rule4 'vars))])
                    (list (hash-ref v 'name) (hash-ref v 'type) (hash-ref v 'col)))
                  '(("x" "int" 12) ("y" "int" 14) ("s" "str" 25)))
    (define name
      (for/first ([s (in-list (hash-ref info 'symbols))] #:when (equal? (hash-ref s 'name) "name")) s))
    (check-equal? (list (hash-ref name 'decl) (hash-ref name 'doc))
                  '("table (name int str)" "a node's label"))
    (check-equal? (for/list ([r (in-list (hash-ref name 'refs))])
                    (list (hash-ref r 'line) (hash-ref r 'role)))
                  '((2 "def") (3 "write") (4 "read") (4 "write")))))
