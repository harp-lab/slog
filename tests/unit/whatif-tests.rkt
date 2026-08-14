#lang racket

;; R5 whatif -- the operator's edge (docs/repl-ux.md §8, roadmap W5').
;; `whatif add|del REL V...` previews an edit's blast radius from the
;; maintenance machinery's own cone/route classification, read-only.
;; The battery pins:
;;   1. the deletion cone: affected relations, their sizes, the negative
;;      route, and the matched-tuple count;
;;   2. the addition preview: growth cone + no-op detection;
;;   3. NOTHING MUTATES: counts before and after every whatif agree;
;;   4. an input-only edit reports itself as such.

(require rackunit
         racket/file
         racket/runtime-path
         "../../compiler/repl.rkt")

(define-runtime-path repo-root "../..")

(define program-text
  (string-append
   "table (edge int int)\n"
   "table (island int)\n"
   "table (path int int)\n"
   "table (answer int int)\n"
   "rule (edge 1 2) (edge 2 3) (edge 3 4)\n"
   "rule (edge X Y) --> (path X Y)\n"
   "rule (path X Y) (edge Y Z) --> (path X Z)\n"
   "rule (path X Y) --> (answer X Y)\n"))

(module+ test
  (void (putenv "SLOG_NO_MEM_CAP" "1"))
  (void (putenv "SLOG_THREADS" "2"))

  (define dir (make-temporary-file "whatif-~a" 'directory))
  (dynamic-wind
    void
    (lambda ()
      (define source (build-path dir "whatif.slog"))
      (call-with-output-file source #:exists 'truncate
        (lambda (out) (display program-text out)))

      (test-case "deletion and addition cones preview without mutating"
        (define transcript
          (parameterize ([current-directory repo-root])
            (plain-transcript
             (list (format "run ~a" (path->string source))
                   "count path"
                   "whatif del edge 1 2"
                   "whatif del (edge 7 9)"
                   "whatif add edge 4 5"
                   "whatif add island 3"
                   "count path"))))
        ;; 1. the deletion cone: edge feeds path feeds answer
        (check-regexp-match #px"Whatif del \\(edge 1 2\\)" transcript)
        (check-regexp-match #px"\\(edge 1 2\\) — 1 row matches now" transcript)
        (check-regexp-match #px"path — [0-9]+ rows now; affected" transcript)
        (check-regexp-match #px"answer — [0-9]+ rows now; affected" transcript)
        (check-regexp-match
         #px"route: (negative-then-positive maintenance|clear-and-rerun) across [0-9]+ strat"
         transcript)
        ;; a retraction of an absent tuple is called out as a no-op
        (check-regexp-match #px"\\(edge 7 9\\) — 0 rows match now \\(retraction would be a no-op\\)"
                            transcript)
        ;; 2. the addition preview: a genuine addition on the growth cone
        (check-regexp-match #px"Whatif add \\(edge 4 5\\)" transcript)
        (check-regexp-match #px"absent now \\(a genuine addition\\)" transcript)
        (check-regexp-match
         #px"likely route: positive maintenance across [0-9]+ strat"
         transcript)
        ;; 4. island has no readers: input-only edit
        (check-regexp-match #px"no derived relations read island" transcript)
        (check-regexp-match #px"route: input-only edit" transcript)
        ;; every whatif line promises no mutation...
        (check-regexp-match #px"nothing staged, nothing mutated — preview only"
                            transcript)
        ;; 3. ...and path's count is bytewise identical before and after
        (define path-counts
          (regexp-match* #px"Count path\n  [0-9]+ rows" transcript))
        (check-equal? (length path-counts) 2)
        (check-equal? (length (remove-duplicates path-counts))
                      1
                      (format "count path drifted: ~a" path-counts))))
    (lambda () (delete-directory/files dir))))
