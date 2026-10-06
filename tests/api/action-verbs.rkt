#lang racket

;; Every client action, as compiler/actions.rkt writes it, against one fresh
;; slogd holding a small frozen database (DIR, relation `e` of arity 2):
;;
;;   racket tests/api/action-verbs.rkt DIR
;;
;; Sends each spec's line, in order, then echoes the daemon's output, so
;; protocol-tests.sh can check that every verb parses the spec shape the
;; driver writes (no parse or unknown-verb refusal) and answers as its
;; plugin did.  Run from the repository root.

(require "../../compiler/actions.rkt"
         "../../compiler/tools.rkt")

(define (specs dir)
  `((import-path ,dir)
    ;; introspection
    (sizes) (schema) (pipeline) (sizes-at 1)
    (lookup e 1 2) (lookup e "a b" 3000000000) (lookup-at e 1 1 2)
    (dump-rel e) (dump-rel e 1) (dump-tuples e) (dump-cells e) (dump-ids e)
    (signature e)
    ;; databases on disk (under data/proto_av*, out/proto-av*)
    (write-db "proto_av") (write-db-subset "proto_av_sub" e)
    (write-rel "proto_av_rel" e) (write-csv "out/proto-av-csv")
    (write-rel-csv "out/proto-av-csv" e)
    (save-compressed "proto_av_c" 0.5 7 1.0 (boosted) (pinned) (rels e) (accel 0))
    (checkpoint "proto_av_ck") (capture-edb-heap)
    (import "proto_av") (load-rel "proto_av" e) (refresh-rel "proto_av" e)
    (import-delta "data/proto_av" ((e e))) (reconstruct-tombstones)
    (set-overlay-int-file e "out/proto-av.ints" 2)
    ;; edits and staging
    (add-tuple e 5 6) (del-tuple e 5 6)
    (add-batch e -1 ((7 8) (x 2.5))) (del-batch e -1 ((7 8)))
    (input-state e -1 ((1 2) (9 9)))
    (set-overlay e -1 ((direct (11 12)) (mask (1 2)) (none (13 14))))
    (set-overlay-positive e ((15 16))) (set-overlay-negative e ((15 16)))
    (set-overlay-negative-dred e ((11 12)))
    (stage-update-transitions e) (stage-update-transitions signed -1 e)
    (stage-view-transitions signed 1 e)
    (stage-lattice-replacements signed 1 e)
    (stage-lattice-replacements-repair signed -1 e)
    (journal-signs e) (dred-reseed e)
    (stage-tuple e 20 21) (stage-batch e ((22 23)))
    ;; update epochs and counts
    (update-epoch) (update-counts-valid)
    (begin-update 0) (commit-update) (begin-update 1) (abort-update)
    (clear-counts) (count-state) (lattice-contributor-state)
    (rank-witness-state) (count-capabilities) (count-test-max 3)
    (input-ledger) (dump-all-counts) (dump-counts e) (dump-counts e 1)
    (dump-ranks e) (dump-ranks e 1) (mark-counted e)
    (begin-count-epoch) (commit-count-epoch) (abort-count-epoch)
    ;; versions and positions
    (begin-segment e) (begin-segment/keyed ((e "k.e.1")))
    (inject-version e "k.e.2") (sizes-at 2)
    (clear-rel-at e 1) (refresh-version e 0) (clear-rel e)
    (rename-rel e e2) (drop-rel e2)
    ;; budgeted continues with nothing to run
    (continue 5) (continue 5 1000000000)
    ;; arming the next stratum push (nothing follows)
    (cover-count-writer 0) (bind-at 0) (bind-instance 0 ((e 1)))
    (transient-stratum) (maintenance-stratum)))

(module+ main
  (match-define (vector dir) (current-command-line-arguments))
  (ensure-slogd-exists)
  (define-values (sp out in err)
    (apply subprocess #f #f #f (slogd-argv "daemon/slogd")))
  (for ([spec (in-list (specs dir))])
    (display (string-append (action-line spec) "\n") in))
  (close-output-port in)
  (for ([port (in-list (list out err))])
    (for ([line (in-lines port)]) (displayln line))
    (close-input-port port))
  (subprocess-wait sp)
  (exit (subprocess-status sp)))
