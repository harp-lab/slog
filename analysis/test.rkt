#lang racket

;; The tests of slog-lint, run from the repository root:
;;
;;   racket analysis/test.rkt            the finding tests, analysis/tests/*.slog
;;   racket analysis/test.rkt --corpus   ... and every program in tests/ and examples/
;;
;; A finding test marks each finding its program must produce with a
;; comment on that line, `;; expect CODE TEXT, CODE:SEVERITY TEXT`: the
;; finding's code (and, when it says, its severity) and the text at its
;; column.  A line without one must have none, so
;; each file is both the programs that trigger a finding and the ones that
;; must not.
;;
;; The corpus run reifies each program, checks that the facts read back as
;; a Slog program, analyzes it, and holds the analysis's negation cycles to
;; the compiler's stratifier: a program has one exactly when the compiler
;; refuses it for negation through recursion.

(require "../compiler/reify.rkt"
         (only-in "../compiler/repl.rkt" make-server-state dispatch-command)
         (only-in "../compiler/parser.rkt" parse-source parse-errors-raise?)
         (only-in "../compiler/modules.rkt" load-program-list)
         (only-in "../compiler/compile.rkt" program->jobs))

;; the interpreter, as Studio runs the analysis: no C++ toolchain in the loop
(void (putenv "SLOG_OPT" "interp"))

(define analysis (path->string (path->complete-path "analysis/lint-deep.slog")))
(define database "slog-lint-test")
(define state (make-server-state))
(define out (path->string (make-temporary-file "slog-lint-~a.csv")))

(define (command line)
  (define result (dispatch-command state line))
  (when (hash-ref result 'error #f)
    (error 'test "~a: ~a" line (hash-ref result 'error)))
  result)

;; path -> (listof (list severity file line col code message))
(define (analyze path)
  (facts->database (reify-file path) database)
  (with-handlers ([exn:fail? void]) (dispatch-command state "discard session"))
  (command (format "open ~a" database))
  (command (format "run ~a" analysis))
  (command (format "dump ?(finding S F L C K M) to ~a" out))
  (for/list ([row (in-list (cdr (file->lines out)))])
    (match-define (list severity file line col code message) (csv-fields row))
    (list severity file (string->number line) (string->number col) code message)))

(define (csv-fields row)
  (let loop ([chars (string->list row)] [field '()] [fields '()] [quoted? #f])
    (match* (chars quoted?)
      [('() _) (reverse (cons (list->string (reverse field)) fields))]
      [((list* #\" #\" more) #t) (loop more (cons #\" field) fields #t)]
      [((cons #\" more) q) (loop more field fields (not q))]
      [((cons #\, more) #f) (loop more '() (cons (list->string (reverse field)) fields) #f)]
      [((cons c more) q) (loop more (cons c field) fields q)])))

;; ---- the finding tests ----

;; line -> (listof (list code severity-or-#f text))
(define (expectations lines)
  (for/fold ([expected (hash)]) ([text (in-list lines)] [line (in-naturals 1)]
                                 #:when (regexp-match? #px";; expect " text))
    (define m (regexp-match #px";; expect (.*)$" text))
    (hash-set expected line
              (for/list ([one (in-list (string-split (second m) ","))])
                (match-define (list kind mark) (string-split (string-trim one) " "))
                (match (string-split kind ":")
                  [(list code severity) (list code severity mark)]
                  [(list code) (list code #f mark)])))))

(define (check-case path)
  (define lines (file->lines path))
  (define main (path->string (path->complete-path path)))
  (define found (filter (lambda (f) (equal? (second f) main)) (analyze path)))
  (define-values (left problems)
    (for/fold ([left (expectations lines)] [problems '()])
              ([f (in-list found)])
      (match-define (list severity _ line col code message) f)
      (define at (let ([text (list-ref lines (sub1 line))])
                   (substring text (min (sub1 col) (string-length text)))))
      (define wanted (hash-ref left line '()))
      (define hit (findf (lambda (e)
                           (match-define (list c s mark) e)
                           (and (equal? c code) (member s (list #f severity)) (string-prefix? at mark)))
                         wanted))
      (if hit
          (values (hash-set left line (remove hit wanted)) problems)
          (values left (cons (format "~a:~a:~a: unexpected ~a ~a: ~a" path line col severity code message)
                             problems)))))
  (append (reverse problems)
          (for*/list ([(line wanted) (in-hash left)] [e (in-list wanted)])
            (match-define (list code severity mark) e)
            (format "~a:~a: missing ~a~a at ~a" path line code
                    (if severity (format ":~a" severity) "") mark))))

;; ---- the corpus ----

;; Whether the compiler refuses `path` for negation through recursion.
(define (compiler-negation-cycle? path)
  (with-handlers ([exn:fail? (lambda (e) (regexp-match? #rx"negation through recursion" (exn-message e)))])
    (parameterize ([current-error-port (open-output-nowhere)]
                   [parse-errors-raise? #t])
      (for-each program->jobs (load-program-list (path->complete-path path) (hash))))
    #f))

(define (check-corpus-program path)
  (with-handlers ([exn:fail? (lambda (e) (list (format "~a: ~a" path (exn-message e))))])
    (define facts (reify-file path))
    ;; the facts as a program must read back
    (parameterize ([parse-errors-raise? #t])
      (parse-source "facts.slog" (facts->program facts)))
    (define found (analyze path))
    (define cycle? (for/or ([f (in-list found)]) (equal? (fifth f) "negation-cycle")))
    (if (equal? cycle? (compiler-negation-cycle? path))
        '()
        (list (format "~a: the analysis ~a a negation cycle, the compiler ~a"
                      path (if cycle? "finds" "finds no") (if cycle? "does not" "does"))))))

(module+ main
  (define corpus? (member "--corpus" (vector->list (current-command-line-arguments))))
  (define cases (sort (map path->string (directory-list "analysis/tests" #:build? #t)) string<?))
  (define programs
    (if corpus?
        (sort (map path->string
                   (append (find-files (lambda (p) (regexp-match? #rx"[.]slog$" p)) "tests")
                           (find-files (lambda (p) (regexp-match? #rx"[.]slog$" p)) "examples")))
              string<?)
        '()))
  ;; the analysis is a Slog program like any other, and has nothing to say
  ;; about itself
  (define (check-self)
    (for/list ([f (in-list (analyze analysis))])
      (format "~a:~a:~a: the analysis of itself: ~a: ~a"
              (second f) (third f) (fourth f) (fifth f) (sixth f))))
  (define problems
    (append (append-map check-case (filter (lambda (p) (string-suffix? p ".slog")) cases))
            (check-self)
            (append-map check-corpus-program programs)))
  (void (dispatch-command state "quit"))
  (for-each displayln problems)
  (printf "~a finding tests~a: ~a\n" (length cases)
          (if corpus? (format ", ~a corpus programs" (length programs)) "")
          (if (null? problems) "ok" (format "~a problems" (length problems))))
  (exit (if (null? problems) 0 1)))
