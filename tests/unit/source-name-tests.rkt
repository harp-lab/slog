#lang racket

(require rackunit
         "../../compiler/utils.rkt")

;; The same repository-relative source has one key in independent clones.
;; These paths need not exist; source-name-key is a lexical normalization.
(define rel (build-path "tests" "dem_lambda.slog"))
(define clone-a (build-path "/tmp" "slog-clone-a"))
(define clone-b (build-path "/opt" "worktrees" "slog-clone-b"))

(check-equal? (source-name-key (build-path clone-a rel) clone-a)
              "tests/dem_lambda.slog")
(check-equal? (source-name-key (build-path clone-b rel) clone-b)
              "tests/dem_lambda.slog")
(check-equal? (modulo (fnv (source-name-key (build-path clone-a rel) clone-a))
                      100000)
              26114)
