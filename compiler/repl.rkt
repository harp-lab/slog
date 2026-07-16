#lang racket

;; The sole Racket-side REPL entry point.
;;
;; The interactive program is the Rust `slog` client under ../repl.  This
;; process owns compilation, one lazy compiler/session.rkt session, and the
;; C++ daemon beneath that session.  It exposes none of Racket's terminal UI:
;; one authenticated Rust client connects over a loopback-only TCP listener
;; and exchanges Content-Length-framed JSON messages.

(provide serve-repl)

(require json
         racket/cmdline
         racket/match
         racket/port
         racket/string
         racket/tcp
         "params.rkt"
         "session.rkt")

(define protocol-version 1)
(define default-max-frame-bytes (* 16 1024 1024))

(struct server-state ([session #:mutable]
                      [event-sink #:mutable]
                      [closing? #:mutable])
  #:transparent)

(define (json-bytes value)
  (define out (open-output-bytes))
  (write-json value out)
  (get-output-bytes out))

(define (write-frame out value)
  (define body (json-bytes value))
  (fprintf out "Content-Length: ~a\r\n\r\n" (bytes-length body))
  (write-bytes body out)
  (flush-output out))

(define (read-exactly in amount)
  (define body (make-bytes amount))
  (let loop ([offset 0])
    (cond
      [(= offset amount) body]
      [else
       (define got (read-bytes! body in offset amount))
       (cond
         [(eof-object? got) eof]
         [(zero? got) (loop offset)]
         [else (loop (+ offset got))])])))

(define (read-frame in [max-bytes default-max-frame-bytes])
  (define header (read-line in 'any))
  (cond
    [(eof-object? header) eof]
    [else
     (match (regexp-match #px"(?i:^Content-Length:)[ ]*([0-9]+)$" header)
       [(list _ amount-text)
        (define amount (string->number amount-text))
        (unless (<= 0 amount max-bytes)
          (error 'repl-protocol "frame length ~a exceeds limit ~a"
                 amount max-bytes))
        (define separator (read-line in 'any))
        (unless (and (string? separator) (string=? separator ""))
          (error 'repl-protocol "expected blank line after Content-Length"))
        (define body (read-exactly in amount))
        (if (eof-object? body)
            (error 'repl-protocol "connection ended inside a frame")
            (read-json (open-input-bytes body)))]
       [_ (error 'repl-protocol "invalid frame header: ~a" header)])]))

(define (success id result)
  (hasheq 'id id 'ok #t 'result result))

(define (failure id kind message)
  (hasheq 'id id
          'ok #f
          'error (hasheq 'kind kind 'message message)))

(define (capture-session-events state thunk)
  (define sink (box '()))
  (dynamic-wind
    (lambda () (set-server-state-event-sink! state sink))
    (lambda ()
      (define value (thunk))
      (values value (reverse (unbox sink))))
    (lambda () (set-server-state-event-sink! state #f))))

(define (ensure-session! state)
  (or (server-state-session state)
      (let ([s
             (make-session
              #:echo
              (lambda (line)
                (define sink (server-state-event-sink state))
                (when sink
                  (set-box! sink (cons line (unbox sink))))))])
        (set-server-state-session! state s)
        s)))

(define (read-one-response out)
  (define line (read-line out))
  (if (eof-object? line) '() (list line)))

(define ((read-until-response end-rx) out)
  (let loop ([lines '()])
    (define line (read-line out))
    (cond
      [(eof-object? line) (reverse lines)]
      [(regexp-match? end-rx line) (reverse (cons line lines))]
      [else (loop (cons line lines))])))

(define help-lines
  (list
   "Racket session commands"
   "  status              show server and daemon state"
   "  ping                round-trip through the private TCP protocol"
   "  run PATH            compile and run a .slog program in this session"
   "  open NAME           open data/NAME in this session"
   "  schema              read the live daemon schema"
   "  pipeline            show the daemon's versioned pipeline"
   "  save NAME           save the current session as data/NAME"
   "  help                show these commands"
   "  quit                close the session and REPL"
   ""
   "Rust UI commands"
   "  :demo colors        true-color and styling gallery"
   "  :demo layout        layout, gauge, and table gallery"
   "  :demo unicode       grapheme and wide-character gallery"
   "  :demo off           return to the welcome view"
   "  :clear              clear the visible client transcript"))

(define (split-command source)
  (define text (string-trim source))
  (cond
    [(string=? text "") (values "" "")]
    [else
     (match (regexp-match #px"^([^[:space:]]+)(?:[[:space:]]+(.*))?$" text)
       [(list _ verb argument)
        (values (string-downcase verb) (or argument ""))])]))

(define (text-result title lines #:kind [kind "text"])
  (hasheq 'kind kind 'title title 'lines lines))

(define (dispatch-command state source)
  (define-values (verb argument) (split-command source))
  (match verb
    ["" (text-result "Slog" '())]
    [(or "help" "?") (text-result "Help" help-lines #:kind "help")]
    ["ping"
     (text-result "Protocol"
                  (list "pong" "Racket server answered over private loopback TCP.")
                  #:kind "status")]
    ["status"
     (text-result
      "Session status"
      (list (format "protocol: ~a" protocol-version)
            (format "racket: ~a" (version))
            (format "daemon: ~a"
                    (if (server-state-session state) "ready" "cold (starts on first semantic command)")))
      #:kind "status")]
    ["run"
     (when (string=? argument "")
       (error 'run "expected: run PATH"))
     (define s (ensure-session! state))
     (define-values (_ events)
       (capture-session-events state (lambda () (session-run! s argument))))
     (text-result (format "Run ~a" argument)
                  (if (null? events) (list "run completed") events)
                  #:kind "run")]
    ["open"
     (when (string=? argument "")
       (error 'open "expected: open NAME"))
     (define s (ensure-session! state))
     (define-values (_ events)
       (capture-session-events state (lambda () (session-open! s argument))))
     (text-result (format "Opened ~a" argument)
                  (if (null? events) (list "database opened") events)
                  #:kind "open")]
    ["schema"
     (define s (ensure-session! state))
     (define lines
       (session-action! s '(schema)
                        (read-until-response #px"^\\(schema-end\\)$")))
     (text-result "Schema" lines #:kind "schema")]
    ["pipeline"
     (define s (ensure-session! state))
     (text-result "Pipeline"
                  (session-action! s '(pipeline) read-one-response)
                  #:kind "pipeline")]
    ["save"
     (when (string=? argument "")
       (error 'save "expected: save NAME"))
     (define s (ensure-session! state))
     (define-values (_ events)
       (capture-session-events state (lambda () (session-save! s argument))))
     (text-result (format "Saved ~a" argument)
                  (if (null? events) (list "session saved") events)
                  #:kind "save")]
    [(or "quit" "exit")
     (set-server-state-closing?! state #t)
     (hasheq 'kind "quit" 'title "Goodbye" 'lines (list "session closed") 'close #t)]
    [_
     (error 'command
            (format "unknown command ~a; type help for the current command set" verb))]))

(define (request-id request)
  (hash-ref request 'id 0))

(define (serve-request state request)
  (define id (request-id request))
  (with-handlers ([exn:fail?
                   (lambda (e)
                     (failure id "command" (exn-message e)))])
    (match (hash-ref request 'method #f)
      ["command"
       (define params (hash-ref request 'params (hasheq)))
       (success id
                (dispatch-command state (hash-ref params 'line "")))]
      ["shutdown"
       (set-server-state-closing?! state #t)
       (success id
                (hasheq 'kind "quit" 'title "Goodbye"
                        'lines (list "session closed") 'close #t))]
      [method
       (failure id "protocol" (format "unknown method: ~a" method))])))

(define (authenticate! in out token)
  (define request (read-frame in))
  (cond
    [(eof-object? request) #f]
    [else
     (define id (request-id request))
     (define params (hash-ref request 'params (hasheq)))
     (define valid?
       (and (equal? (hash-ref request 'method #f) "hello")
            (equal? (hash-ref params 'token #f) token)
            (equal? (hash-ref params 'protocol #f) protocol-version)))
     (if valid?
         (begin
           (write-frame
            out
            (success
             id
             (hasheq 'kind "hello"
                     'protocol protocol-version
                     'server "slog-racket-session"
                     'slog-version
                     (format "~a.~a.~a"
                             slog-version-major
                             slog-version-minor
                             slog-version-revision)
                     'features
                     (list "compile" "session" "daemon" "schema" "pipeline"))))
           #t)
         (begin
           (write-frame out (failure id "authentication" "REPL handshake rejected"))
           #f))]))

(define (open-loopback-listener requested-port)
  (define (listen port)
    (values (tcp-listen port 1 #t "127.0.0.1") port))
  (cond
    [(positive? requested-port) (listen requested-port)]
    [else
     (let loop ([attempt 0])
       (when (>= attempt 256)
         (error 'serve-repl "could not allocate a private loopback port"))
       (define candidate (+ 20000 (random 40000)))
       (with-handlers ([exn:fail:network? (lambda (_) (loop (add1 attempt)))])
         (listen candidate)))]))

(define (close-server-session! state)
  (define s (server-state-session state))
  (when s
    (with-handlers ([exn:fail? (lambda (e)
                                 (eprintf "REPL session cleanup failed: ~a\n"
                                          (exn-message e)))])
      (session-close! s))
    (set-server-state-session! state #f)))

(define (serve-connection in out token)
  (define state (server-state #f #f #f))
  (dynamic-wind
    void
    (lambda ()
      (when (authenticate! in out token)
        (let loop ()
          (unless (server-state-closing? state)
            (define request (read-frame in))
            (unless (eof-object? request)
              (write-frame out (serve-request state request))
              (loop))))))
    (lambda () (close-server-session! state))))

(define (serve-repl #:port [requested-port 0]
                    #:token [token (getenv "SLOG_REPL_TOKEN")])
  (unless (and token (not (string=? token "")))
    (error 'serve-repl "SLOG_REPL_TOKEN is required"))
  (define-values (listener port)
    (open-loopback-listener requested-port))
  (dynamic-wind
    void
    (lambda ()
      ;; This one line is a bootstrap announcement on the inherited private
      ;; pipe.  All subsequent communication is framed on the TCP connection.
      (write-json (hasheq 'host "127.0.0.1"
                          'port port
                          'protocol protocol-version))
      (newline)
      (flush-output)
      (define-values (in out) (tcp-accept listener))
      (tcp-close listener)
      (set! listener #f)
      (dynamic-wind
        void
        (lambda () (serve-connection in out token))
        (lambda ()
          (close-input-port in)
          (close-output-port out))))
    (lambda () (when listener (tcp-close listener)))))

(module+ main
  (define port 0)
  (command-line
   #:program "racket compiler/repl.rkt"
   #:once-each
   [("--port") value "Loopback TCP port (0 chooses a private high port)"
                 (set! port (or (string->number value)
                                (error 'repl "invalid port: ~a" value)))]
   #:args ()
   (void))
  (serve-repl #:port port))

(module+ test
  (require rackunit)

  (define out (open-output-bytes))
  (write-frame out (hasheq 'id 7 'method "ping"))
  (define framed (get-output-bytes out))
  (check-equal? (read-frame (open-input-bytes framed))
                (hasheq 'id 7 'method "ping"))

  (define state (server-state #f #f #f))
  (check-equal? (hash-ref (dispatch-command state "ping") 'kind) "status")
  (check-equal? (hash-ref (dispatch-command state "status") 'lines)
                (list (format "protocol: ~a" protocol-version)
                      (format "racket: ~a" (version))
                      "daemon: cold (starts on first semantic command)")))
