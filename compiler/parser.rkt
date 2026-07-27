#lang racket

(provide parse-port
         parse-file
         parse-source
         source-key
         current-source-override
         current-source-capture
         parse-error
         syn->filename)

(require "lexer.rkt")
(require "ir-shared.rkt")
(require "names.rkt")

;; Recompute-on-load source plumbing (docs/db-compression.md P1.1).
;;
;; A saved database stores the *source* of its deriving program so a load can
;; recompile+replay it under the CURRENT compiler even if the original files
;; have changed or vanished.  Two parameters give parse-file that hook without
;; threading through the whole module resolver:
;;   current-source-override : #f, or a hash (source-key -> source-string).  When
;;     set, parse-file reads a module's text from the hash instead of the disk.
;;   current-source-capture  : #f, or a mutable hash.  When set, parse-file
;;     records every (source-key -> text) it reads, snapshotting a closure.
;; Keys are a pure (no-filesystem) canonicalisation of the path so save-time and
;; load-time lookups agree without touching absent files (symlink-free tree).
(define current-source-override (make-parameter #f))
(define current-source-capture (make-parameter #f))

(define (source-key filename)
  (path->string (simplify-path (path->complete-path filename) #f)))

;; Parse a module from an in-memory source string (filename is used only for
;; token source positions / error context).
(define (parse-source filename source)
  (parse-port filename (open-input-string source)))

(define (syn->filename ast)
  (match ast
    [`(syn (prov ,t ,_) ,_ ...) (pos->file (token->pos t))]
    [_ (error "Cannot lookup filename for syntax.")]))

(define (whitespace n)
  (if (= n 0)
      ""
      (string-append " " (whitespace (- n 1)))))

(define module-toks (hash))
(define (parse-error msg toks [after-toks '()])
  (newline)
  ; Pretty-prints an error message
  (define (line-prefix line)
    (let ([pre (format "~a: " line)]) (string-append (whitespace (- 5 (string-length pre))) pre)))
  ; whitespace up to first column
  (define col (pos->startcol (token->pos (first toks))))
  (define origin-line (pos->startline (token->pos (first toks))))
  (display (line-prefix origin-line))
  (display (whitespace col))
  ; prints toks
  (let loop ([toks toks]
             [line origin-line]
             [col col])
    (if (null? toks)
        (newline)
        (let* ([ctok (first toks)]
               [cpos (token->pos ctok)])
          (if (> (pos->startline cpos) (+ 3 origin-line))
              (newline)
              (if (> (pos->startline cpos) line)
                  (begin
                    (newline)
                    (display (line-prefix (add1 line)))
                    (loop toks (add1 line) 0))
                  (if (> (pos->startcol cpos) col)
                      (let ([dist (- (pos->startcol cpos) col)])
                        (display (whitespace dist))
                        (loop toks line (+ col dist)))
                      (begin
                        (display (token->str ctok))
                        (loop (cdr toks) (pos->endline cpos) (pos->endcol cpos))))))))
    ; print error

    (newline))
  (display (format "Error: ~a" msg))
  (newline)
  (newline)
  (exit 1))

(define (peek toks [i 0])
  ; peeks at the ith token -- O(i), NOT O(|toks|): computing (length toks)
  ; here made every peek walk the whole remaining token list, turning the
  ; parser quadratic (minutes for a few thousand facts)
  (cond
    [(null? toks) `(token eof (position "" 0 0 0 0) "")]
    [(zero? i) (first toks)]
    [else (peek (rest toks) (sub1 i))]))

(define (advance toks [i 1])
  ; removes the first i number of tokens
  (if (or (null? toks) (= i 0))
      toks
      (advance (cdr toks) (- i 1))))

(define (expect toks str)
  ; expects a token and advances toks
  (if (and (not (null? toks)) (equal? str (token->str (first toks))))
      (advance toks)
      (parse-error (format "expected '~a'" str) toks)))


(define (emit-expr expr before-toks after-toks)
  ; emits a provenance-tagged expression
  (when (not (list? expr))
    (error "Parser: emit-expr must be given a proper list"))
  (define left-tok (peek before-toks))
  (define right-tok
    (let loop ([t before-toks])
      (if (or (equal? (peek after-toks) (peek t)) (equal? (peek after-toks) (peek t 1)))
          (peek t)
          (loop (advance t)))))
  `(syn (prov ,left-tok ,right-tok) . ,expr))

(define (parse-bracketed-then toks parser close-str k)
  (if (equal? close-str (token->str (peek toks)))
      (k '() (advance toks))
      (let ()
        (match-define (cons e0 toks+) (parser toks))
        (parse-bracketed-then toks+ parser close-str (lambda (es toks++) (k (cons e0 es) toks++))))))

(define (parse-atom toks)
  ; parses an atom expression from toks
  (define tok (peek toks))
  (match (token->tag tok)
    [(or 'id 'ref)
     (define symb (string->symbol (token->str tok)))
     (if (member symb '(true false))
         (cons (emit-expr `(const ,symb) toks (advance toks)) (advance toks))
         (cons symb (advance toks)))]
    ['num
     (cons (emit-expr `(const ,(string->number (token->str tok))) toks (advance toks))
           (advance toks))]
    ['str
     (define tokstr (token->str tok))
     (cons (emit-expr `(const ,(substring tokstr 1 (- (string-length tokstr) 1))) toks (advance toks))
           (advance toks))]
    ;; `~atom` -- stratified negation of a body atom (docs/incremental.md
    ;; §0.8): the 'not token prefixes an ordinary clause, producing
    ;; (syn prov ~ <atom>).  Form/position restrictions (body only, no
    ;; nesting, ...) are enforced downstream (simplification.rkt), where
    ;; body/head context exists.
    ['not
     (match-define (cons e0 toks+) (parse-atom (advance toks)))
     (cons (emit-expr `(~ ,e0) toks toks+) toks+)]
    #;['op
       #:when (equal? "|" (token->str tok))
       (parse-bracketed-then
        (advance toks)
        parse
        "|"
        (lambda (es toks+)
          (cons (emit-expr `(,(emit-expr `(ref ,(string->symbol "||")) toks toks+) . ,es) toks toks+)
                toks+)))]
    ['popen
     #:when (hash-has-key? keywords (token->str (peek toks 1)))
     (match-define (cons e0 toks+) (parse (advance toks)))
     (cons e0 (expect toks+ ")"))]
    ['popen
     #:when (equal? "ref" (token->str (peek toks 1)))
     (parse-bracketed-then (advance toks 2)
                           parse
                           ")"
                           (lambda (es toks+)
                             (cons (emit-expr `(,(string->symbol "ref") ,@es) toks toks+) toks+)))]
    ['popen
     #:when (eq? 'op (token->tag (peek toks 1)))
     (parse-bracketed-then
      (advance toks 2)
      parse
      ")"
      (lambda (es toks+)
        (cons (emit-expr `(,(string->symbol (token->str (peek toks 1))) ,@es) toks toks+) toks+)))]
    ['popen
     (parse-bracketed-then (advance toks)
                           parse
                           ")"
                           (lambda (es toks+) (cons (emit-expr es toks toks+) toks+)))]
    ['copen
     (parse-bracketed-then (advance toks)
                           parse
                           "}"
                           (lambda (es toks+)
                             (cons (emit-expr `(,(string->symbol "{}") . ,es) toks toks+) toks+)))]
    ['sopen
     (parse-bracketed-then (advance toks)
                           parse
                           "]"
                           (lambda (es toks+)
                             (cons (emit-expr `(,(string->symbol "[]") . ,es) toks toks+) toks+)))]
    [_ (parse-error "Expected an atom---literal, variable, s-expr, etc." toks)]))

(define (parse-w-rem-operators-pre toks prefixes ops)
  (define tokstr (token->str (peek toks)))
  (if (set-member? prefixes tokstr)
      (let* ([toks+ (advance toks)])
        (match-define (cons e0 toks++) (parse-w-rem-operators toks+ ops))
        (cons (emit-expr `(,(string->symbol tokstr) ,e0) toks toks++) toks++))
      (parse-w-rem-operators toks (cdr ops))))

(define (parse-w-rem-operators-post toks postfixes ops)
  (match-define (cons e0 toks+) (parse-w-rem-operators toks (cdr ops)))
  (let loop ([ops '()]
             [after-tokss '()]
             [toks+ toks+])
    (define tokstr (token->str (peek toks+)))
    (define toks++ (advance toks+))
    (if (set-member? postfixes tokstr)
        ; found another postfix operator:
        (loop (cons (string->symbol tokstr) ops) (cons toks++ after-tokss) toks++)
        ; done finding postfix operators:
        (if (null? ops)
            ; there were none:
            (cons e0 toks+)
            ; there were some:
            (let loop ([ops (reverse ops)]
                       [after-tokss (reverse after-tokss)]
                       [e0 e0])
              (if (null? ops)
                  (cons e0 toks+)
                  (loop (cdr ops)
                        (cdr after-tokss)
                        (emit-expr `(,(car ops) ,e0) toks (car after-tokss)))))))))

(define (parse-w-rem-operators toks ops)
  ; parses operators in order (from ops, a suffix of operators) from toks
  (if (null? ops)
      (parse-atom toks)
      (match (car (first ops))
        ['bin (parse-w-rem-operators-bin toks (list->set (cdr (first ops))) ops)]
        ['pre (parse-w-rem-operators-pre toks (list->set (cdr (first ops))) ops)]
        ['post (parse-w-rem-operators-post toks (list->set (cdr (first ops))) ops)])))

(define (parse-w-rem-operators-bin toks group ops)
  ; parses an operator group from toks, with remaining ops (right assoc)
  (match-define (cons e0 toks+) (parse-w-rem-operators toks (rest ops)))
  (define tokstr (token->str (peek toks+)))
  (define tokstrsym (string->symbol tokstr))
  (if (and (not (eq? 'ref (token->tag (peek toks+)))) (set-member? group tokstr))
      (let ([toks++ (advance toks+)])
        (match-define (cons e1 toks+++) (parse-w-rem-operators toks++ ops))
        (match e1
          ;; Qualified name-path (docs/modules.md §8.1, N0): id.id chains
          ;; collapse to ONE lowered symbol at the site the dot would
          ;; otherwise build its (dormant) binary-operator tree.  Bare ids
          ;; parse to bare symbols (parse-atom) and right-assoc recursion
          ;; has already collapsed e1, so both operands being symbols IS
          ;; the id(.id)+ shape; anything else (literals, parens) keeps
          ;; the operator tree.  compiler/names.rkt owns the encoding.
          [(? symbol?)
           #:when (and (equal? tokstr ".") (symbol? e0))
           (cons (qname-join e0 e1) toks+++)]
          [`(syn ,_ ,(? (lambda (x) (equal? x tokstrsym))) ,e+s ...)
           (cons (emit-expr `(,tokstrsym ,e0 ,@e+s) toks toks+++) toks+++)]
          [_ (cons (emit-expr `(,tokstrsym ,e0 ,e1) toks toks+++) toks+++)]))
      (cons e0 toks+)))

(define (parse toks)
  ; parses a single expression from toks, checking keywords, then operators, postfixes, prefixes, atoms
  (define tok (peek toks))
  (define tokstr (token->str tok))
  (if (hash-has-key? keywords tokstr)
      ((hash-ref keywords tokstr) toks)
      (parse-w-rem-operators toks operators)))

(define (parse-N toks parser n)
  ; parses N expressions from toks and returns a list of ASTs
  (match n
    [0 (cons '() toks)]
    [_
     (match-define (cons e toks+) (parser toks))
     (match-define (cons es toks++) (parse-N toks+ parser (- n 1)))
     (cons `(,e . ,es) toks++)]))

(define (make-parse-id-then-N-emit parser N)
  ; idiom used for keywords, prefixes, generates a parser for id e...^N
  (lambda (toks)
    (match-define (cons expr toks+) (parse-id-then-N toks parser N))
    (cons (emit-expr expr toks toks+) toks+)))

(define (parse-id-then-N toks parser N)
  ; parses id e...^N from toks
  (define tag (string->symbol (token->str (peek toks))))
  (define toks+ (advance toks))
  (match-define (cons es toks++) (parse-N toks+ parser N))
  (cons `(,tag ,@es) toks++))

(define (parse-def toks is-toplevel)
  (define toks+1 (advance toks)) ; always 'def'
  (match-define (cons pattern-e toks+2) (parse toks+1))
  (match-define (cons w-or-b toks+3) (parse toks+2))
  (if (and (pair? w-or-b) (equal? (last w-or-b) 'when))
      (let ()
        (match-define (cons guard-e toks+4) (parse toks+3))
        (match-define (cons body-e toks+5) (parse toks+4))
        (match-define (cons rest-e toks+6)
          (if is-toplevel
              (parse-top-level toks+5)
              (parse toks+5)))
        (cons (emit-expr `(def ,pattern-e ,guard-e ,body-e ,rest-e) toks toks+6) toks+6))
      (let ()
        (match-define (cons rest-e toks+4)
          (if is-toplevel
              (parse-top-level toks+3)
              (parse toks+3)))
        (cons (emit-expr `(def ,pattern-e ,w-or-b ,rest-e) toks toks+4) toks+4))))

;; Top-level forms delimit variable-length declarations/rules and the optional
;; namespace-binding tail of run/instantiate.  Keep this list in one place:
;; historically the local list omitted include/run/union/... and therefore
;; only happened to work when those directives preceded every declaration.
(define top-level-keywords
  (set "def" "rule" "enum" "table" "struct" "union" "demand" "extern"
       "lattice" "include" "instantiate" "run" "let" "import" "export" ""))

;; Parse one id(.id)* path without admitting the ordinary expression `=`
;; operator.  Binding grammar needs the left path to stop exactly before `=`
;; and the right path to stop before `,` or the next top-level form.
(define (parse-name-path toks what)
  (define first-token (peek toks))
  (unless (memq (token->tag first-token) '(id ref))
    (parse-error (format "Expected ~a name path" what) toks))
  (let loop ([name (string->symbol (token->str first-token))]
             [rest (advance toks)])
    (cond
      [(equal? "." (token->str (peek rest)))
       (define component-token (peek rest 1))
       (unless (memq (token->tag component-token) '(id ref))
         (parse-error (format "Expected a name component after '.' in ~a" what)
                      rest))
       (loop (qname-join name
                         (string->symbol (token->str component-token)))
             (advance rest 2))]
      [else (cons name rest)])))

;; [with formal = actual, ...] -> (values binding-pairs remaining-tokens).
;; Paths retain the N0 lowered-symbol representation; modules.rkt immediately
;; recovers components through names.rkt before applying any substitution.
(define (parse-optional-bindings toks)
  (cond
    [(not (equal? "with" (token->str (peek toks)))) (values '() toks)]
    [else
     (let loop ([rest (advance toks)] [out '()])
       (match-define (cons formal after-formal)
         (parse-name-path rest "formal namespace"))
       (unless (equal? "=" (token->str (peek after-formal)))
         (parse-error "Expected '=' after a formal namespace path"
                      after-formal))
       (match-define (cons actual after-actual)
         (parse-name-path (advance after-formal) "actual namespace"))
       (define out+ (cons (list formal actual) out))
       (cond
         [(equal? "," (token->str (peek after-actual)))
          (loop (advance after-actual) out+)]
         [(set-member? top-level-keywords (token->str (peek after-actual)))
          (values (reverse out+) after-actual)]
         [else
          (parse-error
           "Expected ',' or the next top-level form after a namespace binding"
           after-actual)]))]))

;; Parse the two occurrence forms. Plain `run "x"` deliberately retains its
;; historical AST shape, preserving the root-only parser/compile identity
;; gate. Extended run carries one options record; instantiate always names a
;; fresh lexical child.
(define (parse-occurrence toks kind)
  (define after-kind (advance toks))
  (match-define (cons source after-source) (parse after-kind))
  (define alias #f)
  (define after-alias
    (cond
      [(equal? "as" (token->str (peek after-source)))
       (define alias-token (peek after-source 1))
       (unless (eq? 'id (token->tag alias-token))
         (parse-error "Expected one identifier after 'as'" after-source))
       (set! alias (string->symbol (token->str alias-token)))
       (advance after-source 2)]
      [(eq? kind 'instantiate)
       (parse-error "Expected 'as <identifier>' after instantiate source"
                    after-source)]
      [else after-source]))
  (define-values (bindings after-bindings)
    (parse-optional-bindings after-alias))
  (match-define (cons body after-body) (parse-top-level after-bindings))
  (define expr
    (cond
      [(eq? kind 'instantiate)
       `(instantiate ,source ,alias (bindings ,@bindings) ,body)]
      [(and (not alias) (null? bindings))
       `(run ,source ,body)]
      [else
       `(run ,source (occurrence-options ,alias (bindings ,@bindings)) ,body)]))
  (cons (emit-expr expr toks after-body) after-body))

(define (parse-top-level toks)
  ;; parses top level expression from toks
  (match (token->str (peek toks))
    ["def" (parse-def toks #t)]
    [(or "import" "export")
     (define import/export (string->symbol (token->str (peek toks))))
     (define toks+ (advance toks))
     (match-define (cons e0 toks+2) (parse toks+))
     (when (not (equal? "as" (token->str (peek toks+2))))
       (parse-error (format "Expected 'as' next in ~a statement" import/export) toks))
     (match-define (cons e1 toks+3) (parse (advance toks+2)))
     (match-define (cons body toks+4) (parse-top-level toks+3))
     (cons (emit-expr `(,import/export ,e0 ,e1 ,body) toks toks+3) toks+4)]
    ["demand"
     ;; demand (name in-type ...) answer-type ... -- the input signature
     ;; then answer types, gathered to the next top-level form
     (let loop ([toks+ (advance toks)]
                [sig-lst '()])
       (if (set-member? top-level-keywords (token->str (peek toks+)))
           (let ()
             (match-define (cons topbody toks++) (parse-top-level toks+))
             (cons (emit-expr `(demand ,@sig-lst ,topbody) toks toks++) toks++))
           (let ()
             (match-define (cons e toks++) (parse toks+))
             (loop toks++ `(,@sig-lst ,e)))))]
    ["extern"
     ;; extern <oracle> (name in-type) answer-type -- an oracle-backed demand
     ;; relation (docs/smt.md): declared like demand, answered by the named
     ;; daemon-side oracle instead of rules; gathered like demand
     (let loop ([toks+ (advance toks)]
                [sig-lst '()])
       (if (set-member? top-level-keywords (token->str (peek toks+)))
           (let ()
             (match-define (cons topbody toks++) (parse-top-level toks+))
             (cons (emit-expr `(extern ,@sig-lst ,topbody) toks toks++) toks++))
           (let ()
             (match-define (cons e toks++) (parse toks+))
             (loop toks++ `(,@sig-lst ,e)))))]
    ["rule"
     (let loop ([toks+ (advance toks)]
                [body0 '()])
       (define next (token->str (peek toks+)))
       (define arrow (string->symbol next))
       (cond
         [(or (eq? arrow '-->) (eq? arrow '<--))
          (let loop ([toks+ (advance toks+)]
                     [body1 '()])
            (if (set-member? top-level-keywords (token->str (peek toks+)))
                (let () ; parse the rest of the top level and emit rule
                  (match-define (cons topbody toks++) (parse-top-level toks+))
                  (cons (emit-expr `(rule ,@(reverse body0) ,arrow ,@(reverse body1) ,topbody)
                                   toks toks+)
                        toks++))
                (let () ; gather each clause in the second half
                  (match-define (cons e toks++) (parse toks+))
                  (loop toks++ (cons e body1)))))]
         ;; the next top-level form arrives before any arrow: a head-only
         ;; rule -- the empty body is implicit, every clause a head (one
         ;; ground fact, or several heads gated/grouped together)
         [(set-member? top-level-keywords next)
          (when (null? body0)
            (parse-error "Expected at least one clause in rule" toks))
          (match-define (cons topbody toks++) (parse-top-level toks+))
          (cons (emit-expr `(rule --> ,@(reverse body0) ,topbody) toks toks+)
                toks++)]
         [else ; gather each clause in the first half
          (match-define (cons e toks++) (parse toks+))
          (loop toks++ (cons e body0))]))]
    ["let"
     (match-define (cons tag-pat-rhs toks+) (parse-id-then-N toks parse 2))
     (match-define (cons body toks++) (parse-top-level toks+))
     (cons (emit-expr `(,@tag-pat-rhs ,body) toks toks++) toks++)]
    ["instantiate" (parse-occurrence toks 'instantiate)]
    ["run" (parse-occurrence toks 'run)]
    [(or "include" "union" "struct" "table" "enum" "lattice")
     (match-define (cons tag-str toks+) (parse-id-then-N toks parse 1))
     (match-define (cons body toks++) (parse-top-level toks+))
     (cons (emit-expr `(,@tag-str ,body) toks toks++) toks++)]
    ["" (cons (emit-expr '(top-level) toks toks) toks)]
    [_ (parse toks)]))

; Defines infix operators, precedence, grouping, associativity
(define operators
  `((bin ";") (bin "<-")
              (pre "->")
              (bin "&" "|")
              (bin "=" "/=")
              (bin ":=")
              (bin "+" "-")
              (bin "*" "/" "%")
              (bin "^")
              (post "...")
              (bin ":")
              (bin "?")
              (pre "`" ",")
              (bin ".")))

; Defines keyword parsers
(define keywords
  (hash) ; turn off for slog?
  #;(hash "def"
          (lambda (toks) (parse-def toks #f))
          "let"
          (make-parse-id-then-N-emit parse 3)
          "use"
          (make-parse-id-then-N-emit parse 2)
          "if"
          (make-parse-id-then-N-emit parse 3)
          "lambda"
          (make-parse-id-then-N-emit parse 2)
          "#"
          (make-parse-id-then-N-emit parse 2)))

; Parses a module from an input port
(define (parse-port filename input-port)
  (define lex (make-tinkr-lexer filename input-port))
  (define raw-toks
    (let loop ()
      (let ([tok (lex input-port)])
        (match tok
          [`(token eof ,_ ...) `(,tok)]
          [_ `(,tok . ,(loop))]))))
  (define real-toks
    (filter (lambda (x)
              (and (not (eq? (first x) eof))
                   (> (length x) 1)
                   (not (eq? (second x) 'space))
                   (not (eq? (second x) 'comment))
                   (not (eq? (second x) 'newline))))
            raw-toks))
  (set! module-toks (hash-set module-toks filename raw-toks))
  (match-define (cons file-ast residual-toks) (parse-top-level real-toks))
  (if (eq? 'eof (token->tag (peek residual-toks)))
      `(module ,filename ,raw-toks
         ,file-ast)
      (parse-error "End of file expected." real-toks residual-toks)))

; Parses a module from a filename, honouring the source override/capture
; parameters (P1.1): read the text from the override hash if present, otherwise
; from disk (recording it in the capture hash when capturing).
(define (parse-file filename)
  (define key (source-key filename))
  (define ov (current-source-override))
  (cond
    [(and ov (hash-has-key? ov key))
     (parse-source filename (hash-ref ov key))]
    [else
     ;; During a replay (override set) every source should come from the
     ;; stored program; falling through to DISK means the stored closure is
     ;; incomplete or path resolution diverged (symlink / moved tree / cwd),
     ;; so the replay may silently compile sources that differ from the
     ;; recipe -- say so loudly rather than let drift pass unattributed.
     (when ov
       (eprintf "Warning: replay is reading ~a from disk -- it is not in the stored program (prog.sexpr); the result may not correspond to the saved recipe\n"
                key))
     (define src (file->string filename))
     (define cap (current-source-capture))
     (when cap (hash-set! cap key src))
     (parse-source filename src)]))
