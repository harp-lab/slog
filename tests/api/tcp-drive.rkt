#lang racket

;; TCP twin of drive.rkt (T0 slice (a), docs/t0-contract.md): listen on a
;; local port, spawn `slogd -p PORT` connecting back to it, send each
;; command-line argument verbatim as one line, then send (close).  Every
;; reply datum is echoed one per line via `write` -- TCP replies carry no
;; newline framing (send_msg in slogd.cpp), so datum `read` is the framing,
;; exactly as daemon/slogd.rkt's console reads them.  Replies the command
;; layer emits are canonical write-printed forms, so the echoed lines are
;; byte-comparable with a stdin drive.rkt transcript; the (pending)
;; heartbeat and the (bye ...) handshake are transport chatter that a parity
;; check filters out (they ARE printed, so a test can also assert them).
;;
;; Run from the repository root (build/, data/, daemon/ are relative).

(require "../../compiler/tools.rkt")

(module+ main
  (define lines (vector->list (current-command-line-arguments)))
  (ensure-slogd-exists)
  (define listener (tcp-listen 0 4 #t "127.0.0.1"))
  (define-values (_ port __ ___) (tcp-addresses listener #t))
  (define-values (sp sout sin serr)
    (apply subprocess #f #f #f
           (slogd-argv "daemon/slogd" "-p" (number->string port))))
  (define-values (in out) (tcp-accept listener))
  (tcp-close listener)
  (for ([l (in-list (append lines (list "(close)")))])
    (display (string-append l "\n") out)
    (flush-output out))
  (let loop ()
    (define msg (with-handlers ([exn:fail? (lambda (_) eof)]) (read in)))
    (unless (eof-object? msg)
      (writeln msg)
      (unless (and (pair? msg) (eq? (car msg) 'bye))
        (loop))))
  (close-input-port in)
  (with-handlers ([exn:fail? void]) (close-output-port out))
  (subprocess-wait sp)
  (exit (if (> (subprocess-status sp) 0) 1 0)))
