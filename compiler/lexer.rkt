#lang racket

(provide make-tinkr-lexer
         make-token
         synth-token
         token->tag
         token->pos
         token->str
         pos->file
         pos->startline
         pos->startcol
         pos->endline
         pos->endcol)

(require parser-tools/yacc
         parser-tools/lex
         (prefix-in : parser-tools/lex-sre))

(define token->tag second)
(define token->pos third)
(define token->str fourth)
(define pos->file second)
(define pos->startline third)
(define pos->startcol fourth)
(define pos->endline fifth)
(define pos->endcol sixth)

(define (make-token tag filename line-pos col-pos lexeme)
  `(token ,tag
          (pos ,filename ,line-pos ,col-pos ,line-pos ,(+ col-pos (string-length lexeme)))
          ,lexeme))

(define synth-token (make-token 'synthetic "<internal>" 0 0 ""))

(define make-tinkr-lexer
  (lambda (filename input-port)
    (define line-pos 0)
    (define col-pos 0)
    (define (advance-line!)
      (set! col-pos 0)
      (set! line-pos (+ 1 line-pos)))
    (define (advance-col! [x 1])
      (set! col-pos (+ x col-pos)))
    (define (emit-token tag lexeme)
      (begin0 (make-token tag filename line-pos col-pos lexeme)
        (advance-col! (string-length lexeme))))
    ;; "basename:line:col" (1-based) of the lexeme being matched, spelled
    ;; like ir-shared.rkt's rule-location-string
    (define (location)
      (define p (file-name-from-path (format "~a" filename)))
      (format "~a:~a:~a" (if p (path->string p) filename) (add1 line-pos) (add1 col-pos)))
    (define lex
      (lexer [(eof) (emit-token 'eof "")]
             [(:: ";;" (:* (:& (:~ "\n") any-char))) (emit-token 'comment lexeme)]
             [(:: "'" (:* (:or "\\'" (:& (:~ (:or "\n" "'")) any-char))) "'")
              (emit-token 'ref (substring lexeme 1 (- (string-length lexeme) 1)))]
             ["|" (emit-token 'op lexeme)]
             ["(" (emit-token 'popen lexeme)]
             [")" (emit-token 'pclose lexeme)]
             ["[" (emit-token 'sopen lexeme)]
             ["]" (emit-token 'sclose lexeme)]
             ["{" (emit-token 'copen lexeme)]
             ["}" (emit-token 'cclose lexeme)]
             ["`" (emit-token 'quote lexeme)]
             ["~" (emit-token 'not lexeme)]
             ["," (emit-token 'unquote lexeme)]
             ["λ" (emit-token 'id "lambda")]
             ["\r" (emit-token 'space lexeme)]
             [#\newline
              (begin0 (emit-token 'newline lexeme)
                (advance-line!))]
             [(:+ (:or #\tab #\space)) (emit-token 'space lexeme)]
             [(:: "\"" (:* (:or (:: "\\" any-char) (char-complement (:or "\"")))) "\"")
              ; not sure of the right way to process escape sequences but this works for now
              (emit-token 'str (string-append "\"" (with-input-from-string lexeme read) "\""))]
             ; numbers -- an optional leading '-' is part of the literal ONLY
             ; when digits (or .digits) follow immediately, so `-5`/`-1.0` are
             ; negative literals while a bare `-` (before a space/paren, as in
             ; `(- a b)`) still lexes as the operator below.  Longest-match makes
             ; `-5` beat the `-` operator lexeme.  (No space-less infix like
             ; `1-2` exists in the language -- arithmetic is s-expr `(- 1 2)`.)
             [(:: (:? "-") (:or (:: (:* (:/ "0" "9")) "." (:+ (:/ "0" "9"))) (:+ (:/ "0" "9"))))
              (emit-token 'num lexeme)]
             ; identifiers
             [(:: (:or (:/ "A" "Z") (:/ "a" "z") (:/ "0" "9") "_")
                  (:* (:or (:/ "A" "Z") (:/ "a" "z") (:/ "0" "9") "_" "'")))
              (emit-token 'id lexeme)]
             ; a hyphenated word (on-cycle) is an error, not an identifier.
             ; Without this rule it splits at the `-` operator lexeme below
             ; into the subtraction `on - cycle`, which surfaced much later
             ; as an opaque simplify-all contract failure.  Longest-match
             ; makes this beat the identifier rule; it starts with a letter
             ; or `_`, so numeric `1-2` lexes as before.
             [(:: (:or (:/ "A" "Z") (:/ "a" "z") "_")
                  (:* (:or (:/ "A" "Z") (:/ "a" "z") (:/ "0" "9") "_" "'"))
                  (:+ (:: "-" (:+ (:or (:/ "A" "Z") (:/ "a" "z") (:/ "0" "9") "_" "'")))))
              (error (format "~a: ~a is not a valid name: names may contain letters, digits, `_` and `'`, but not `-` (write ~a; subtraction is (- a b))"
                             (location) lexeme (string-replace lexeme "-" "_")))]
             ; keyword parameters (#:floor, #:ceiling, ...): one id token
             ; (longest-match beats the generic "#:" operator lexeme below)
             [(:: "#:" (:+ (:or (:/ "A" "Z") (:/ "a" "z") (:/ "0" "9") "_")))
              (emit-token 'id lexeme)]
             ; operators; sequences of eveything else between ! and ~
             ["\\" (emit-token 'op lexeme)]
             [(:+ (:& (:/ "!" "~")
                      (:~ (:or (:/ "A" "Z")
                               (:/ "a" "z")
                               (:/ "0" "9")
                               "_"
                               "\""
                               "~"
                               ","
                               "`"
                               "'"
                               "\\"
                               "("
                               ")"
                               "["
                               "]"
                               "{"
                               "}"
                               "|"))))
              (emit-token 'op lexeme)]))
    lex))
