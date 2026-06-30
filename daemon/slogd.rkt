#lang racket

(require racket/runtime-path)

;; Path to the slogd executable, resolved relative to this source file
;; (rather than searched on PATH).
(define-runtime-path slogd-path "slogd")

;; Build the argv for launching slogd, wrapping it in a transient
;; `systemd-run --user --scope` with a memory cap so a runaway program is
;; OOM-killed inside its own cgroup instead of taking down this console (and
;; the surrounding terminal/editor that share its scope).  Mirrors
;; compiler/tools.rkt's slogd-argv; kept inline so the daemon stays free of a
;; dependency on the compiler.  Knobs: SLOG_MEM_MAX (default "4G",
;; "none"/"off"/"" disables), SLOG_NO_MEM_CAP (non-empty = direct launch).
(define (slogd-argv . extra-args)
  (define slogd (path->string (path->complete-path slogd-path)))
  (define cap (or (getenv "SLOG_MEM_MAX") "4G"))
  (define cap-off? (and (member (string-downcase cap) '("" "none" "off")) #t))
  (define no-cap? (let ([v (getenv "SLOG_NO_MEM_CAP")]) (and v (not (string=? v "")) #t)))
  (define systemd-run
    (and (not cap-off?) (not no-cap?) (find-executable-path "systemd-run")))
  (cond
    [systemd-run
     (list* (path->string systemd-run)
            "--user" "--scope" "--quiet"
            "-p" (string-append "MemoryMax=" cap)
            "-p" "MemorySwapMax=0"
            slogd extra-args)]
    [else
     (when (and (not cap-off?) (not no-cap?))
       (eprintf "warning: systemd-run not found on PATH; launching slogd without a ~a memory cap\n" cap))
     (cons slogd extra-args)]))

;; Spawn the slogd subprocess and hand back its private TCP connection.
;; Returns (values subprocess conn-in conn-out).
(define (spawn-daemon)
  (define listener (tcp-listen 0 4 #t "127.0.0.1"))
  (define-values (_ local-port __ ___) (tcp-addresses listener #t))

  (define-values (sub-proc _out _in _err)
    (apply subprocess #f #f (current-error-port)
           (slogd-argv "-p" (number->string local-port))))

  (define-values (conn-in conn-out) (tcp-accept listener))
  (tcp-close listener)

  (values sub-proc conn-in conn-out))

;; Write a datum to the daemon and flush.
(define (send-msg out msg)
  (write msg out)
  (flush-output out))


;; Boot the daemon and give the user a "> " prompt.  Whatever the user
;; types is forwarded verbatim to the daemon; whatever the daemon sends
;; back is printed just above the prompt as it arrives.  Ctrl-D (EOF on
;; stdin) sends a graceful (close) and exits.
(define (run-console)
  (define-values (proc in out) (spawn-daemon))

  (define interactive? (terminal-port? (current-output-port)))
  (define stdout-lock (make-semaphore 1))
  (define closing? #f)
  (define (locked thunk) (call-with-semaphore stdout-lock thunk))
  (define (show-prompt)
    (when interactive? (display "> ") (flush-output)))

  ;; Reader: print incoming daemon messages above the prompt.
  (define reader
    (thread
     (lambda ()
       (let loop ()
         ;; A reset/closed socket can raise rather than return eof;
         ;; treat either the same way.
         (define msg (with-handlers ([exn:fail? (lambda (_) eof)])
                       (read in)))
         (unless (eof-object? msg)
           (locked
            (lambda ()
              (cond
                [interactive?
                 ;; \r + clear-to-end-of-line, the message, then redraw
                 ;; the prompt (unless we are already shutting down).
                 (printf "\r\e[K~a\n" msg)
                 (unless closing? (show-prompt))]
                [else (displayln msg)])))
           (loop))))))

  (locked show-prompt)
  (let loop ()
    (define line (read-line))
    (cond
      [(eof-object? line)
       ;; Ctrl-D: clear the prompt and ask the daemon to close.
       (locked (lambda ()
                 (set! closing? #t)
                 (when interactive? (display "\r\e[K") (flush-output))))
       (with-handlers ([exn:fail? void]) (send-msg out '(close)))]
      [else
       ;; Forward the line (newline-terminated, so the daemon can split
       ;; it as one command); stop if the daemon has gone away.
       (define ok?
         (with-handlers ([exn:fail? (lambda (_) #f)])
           (fprintf out "~a\n" line)
           (flush-output out)
           #t))
       (when ok? (loop))]))

  (thread-wait reader)
  (subprocess-wait proc)
  (displayln "[slogd console] connection closed, exiting."))


(run-console)
