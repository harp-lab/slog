#lang racket

(provide slog-init
         slog-load-path
         slog-run
         slog-run-wait
         slog-write
         slog-write-csv
         slog-compile-run-all
         slog-simple-run-all)

(require "tools.rkt")
(require "compile.rkt")

;; None of this seems to work except slog-simple-run-all
;; due to some kind of blocking until I close the in port to the daemon
(define (slog-init [db #f])
  (if db
      (slog-init-open db)
      (slog-init-new)))

(define (slog-init-start)
  (ensure-slogd-exists)
  (define-values (sp out in err) (apply subprocess #f #f #f (slogd-argv "daemon/slogd")))
  `(slogd start ,(hash) ,sp ,out ,in ,err))

(define (db-manifest-from-name db-name)
  (if db-name
      (let ([db-path (string-append "data/" db-name "/")])
        (foldl (lambda (path man)
                 (define path+ (fullpath (normalize-path path (path->complete-path db-path))))
                 (match (regexp-match #px"/table\\.(\\w+)\\.arity\\.(\\d+)" path+)
                   [`(,_ ,name ,arity)
                    (hash-set man
                              (string->symbol name)
                              `(rel ,(string->symbol name) ,(string->number arity)))]
                   [_
                    (match (regexp-match #px"/struct\\.(\\w+)\\.arity\\.(\\d+)\\.id\\.(\\d+)" path+)
                      [`(,_ ,name ,arity ,_)
                       (hash-set man
                                 (string->symbol name)
                                 `(struct ,(string->symbol name) ,(string->number arity)))]
                      [_ man])]))
               (hash)
               (directory-list db-path)))
      (hash)))

(define (slog-init-open db-name)
  (match-define `(slogd start ,dbmanifest ,sp ,out ,in ,err) (slog-init-start))
  (display (string-append "open:" db-name "\n") in)
  (define db-path (string-append "data/" db-name "/"))
  (define dbmanifest+ (db-manifest-from-name db-name))
  `(slogd loading ,dbmanifest+ ,sp ,out ,in ,err))

(define (slog-init-new)
  (match-define `(slogd start ,dbmanifest ,sp ,out ,in ,err) (slog-init-start))
  (display (string-append "new:\n") in)
  `(slogd loading ,dbmanifest ,sp ,out ,in ,err))

(define (slog-load-path slogd path)
  (match-define `(slogd loading ,dbmanifest ,sp ,out ,in ,err) slogd)
  (display (string-append "load:" path "\n") in)
  slogd)

(define (slog-run slogd)
  (match-define `(slogd loading ,dbmanifest ,sp ,out ,in ,err) slogd)
  (display "run:\n" in)
  (display "writeCSV:out/\n" in)
  (close-output-port in)
  `(slogd running ,dbmanifest ,sp ,out ,in ,err))

(define (slog-run-wait slogd)
  (match-define `(slogd running ,dbmanifest ,sp ,out ,in ,err) slogd)
  (define str (read-line out))
  ; Skip iteration printing
  (if (regexp-match #px"$Fixpoint reached" str)
      (let ()
        (display (format "~a\n" str))
        (slog-run-wait slogd))
      ; Stop when we see 'Fixpoint reached...'
      `(slogd stable ,dbmanifest ,sp ,out ,in ,err)))

(define (slog-write slogd db-name)
  (match-define `(slogd stable ,dbmanifest ,sp ,out ,in ,err) slogd)
  (display (string-append "write:" db-name "\n") in)
  slogd)

(define (slog-write-csv slogd out-path)
  (match-define `(slogd stable ,dbmanifest ,sp ,out ,in ,err) slogd)
  (display (string-append "writeCSV:" out-path "\n") in)
  slogd)

(define (slog-close slogd)
  (match-define `(slogd _ ,dbmanifest ,sp ,out ,in ,err) slogd)
  (close-output-port in)
  (close-input-port out)
  (close-input-port err)
  (subprocess-wait sp)
  (when (> (subprocess-status sp) 0)
    (error "Something went wrong running the daemon!"))
  (void))

(define (slog-reload slogd)
  (match-define `(slogd stable ,dbmanifest ,sp ,out ,in ,err) slogd)
  (display (string-append "reload:\n") in)
  `(slogd loading ,dbmanifest ,sp ,out ,in ,err))

; Takes a slogd in loading mode and a path to a .slog program
; iterates the program through each fixpoint and yields a slogd
; in stable mode that you can optionally write an output DB from.
(define (slog-compile-run-all slogd path)
  (match-define `(slogd loading ,dbmanifest ,sp ,out ,in ,err) slogd)
  (match-define (cons so-path prog-fut) (compile-path path dbmanifest))
  (let loop ([slogd slogd]
             [so-path so-path]
             [prog-fut prog-fut])
    (define slogd1 (slog-load-path slogd so-path))
    (define slogd2 (slog-run slogd1))
    (define slogd3 (slog-run-wait slogd2))
    (define more (touch prog-fut))
    (if (null? more)
        slogd3 ; update the manifest upon returning?
        (loop (slog-reload slogd3) (car more) (cdr more)))))

;; Avoids the above interface which isn't working right now
(define (slog-simple-run-all slog-path [db-name #f] [out-db #f] [debug-out-path #f])
  ;; Working directories used by the compiler and daemon (relative to cwd).
  (make-directory* "build")
  (make-directory* "out")
  (define dbmanifest (db-manifest-from-name db-name))
  (match-define (cons so-path prog-fut) (finish-jit (compile-path slog-path dbmanifest)))
  (ensure-slogd-exists)
  (define-values (sp out in err) (apply subprocess #f #f #f (slogd-argv "daemon/slogd")))
  (define (command cmd . args)
    (define cmd+ (apply format (cons cmd args)))
    (display (string-append cmd+ "\n"))
    (display (string-append cmd+ "\n") in))

  ;; Open or new
  (if db-name
      (command "open:~a" db-name)
      (command "new:"))

  ;; Loop of loading, running, and possibly reloading if there are more programs
  (let loop ([so-path so-path]
             [prog-fut prog-fut])
    (command "load:~a" so-path)
    (command "run:")
    (define more (finish-jit (touch prog-fut)))
    (when (not (null? more))
      (command "reload:")
      (loop (car more) (cdr more))))

  ;; When at the final fixpoint:
  (when out-db
    (command "write:~a" out-db))
  (when debug-out-path
    (command "writeCSV:~a" debug-out-path))
  (close-output-port in)
  (let loop () ;; echo output from daemon
    (define s (read-line out))
    (when (not (eof-object? s))
      (display s)
      (newline)
      (loop)))
  (let loop () ;; echo error output from daemon
    (define s (read-line err))
    (when (not (eof-object? s))
      (display s)
      (newline)
      (loop)))
  (close-input-port out)
  (close-input-port err)
  (subprocess-wait sp)
  (when (> (subprocess-status sp) 0)
    (error "Something went wrong running the daemon!")))
