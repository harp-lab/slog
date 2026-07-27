#lang racket

;; CLI shell over the incremental-session driver (compiler/session.rkt,
;; docs/incremental.md 0.B): one resident daemon driven through segments,
;; batches, re-entry, and versioned queries; every daemon line echoes to
;; stdout for the test harness (tests/session-tests.sh) to assert on.
;;
;;   racket tests/api/session-drive.rkt open:DB run:PROG.slog \
;;          batch+:edge,3,4 batch-:edge,2,3 flush \
;;          pipeline sizes-at:0 dump-rel:path,1 ...
;;
;; Ops, executed in order against one session:
;;   open:DB            open data/DB (segments then compile against it)
;;   run:PROG           one program segment (begin-segment boundary,
;;                      frozen imports, strata to fixpoint)
;;   batch+:REL,V,..    queue a signed tuple against the current point;
;;   batch-:REL,V,..    same-point opposite pairs collapse (§0.2)
;;   flush              apply pending batches + route by the §0.5 rule:
;;                      all-adds + monotone cone -> replay-entry (delta-
;;                      entry once 0.B5 lands); else clear-and-rerun
;;   add-tuple:REL,V,.. immediate insert (latest version, in place; logged
;;                      at the tip binding -- 0.E0d)
;;   del-tuple:REL,V,.. immediate retraction (rebuild minus tuple; logged)
;;   save:NAME          serialise the session as a new data/NAME layer
;;                      (materialisation + recipe + sources + META, 0.E1)
;;   aimport-delta:P,DIR[,SRC=DST..]  import anchored at position P (0.E0b)
;;   reenter:REL        direct replay-entry (refuses non-monotone cones)
;;   rerun:REL          direct clear-and-rerun
;;   pipeline           version chains + strata positions
;;   boundary           logical N2 catalog/environment + plan count
;;   bundle             the N4-A durable boundary bundle this session saves
;;   daemon-boundaries  committed N3 daemon boundary history
;;   daemon-current-boundary exact current N3 materialization snapshot
;;   sizes-at:P         sizes resolved at position P
;;   dump-rel:REL[,P]   dump REL (optionally at position P)
;;   dump-cells:REL     rows as structured value cells (word/kind/sid/type)
;;   sizes | schema     the existing unversioned actions
;;   write-db:DB | write-csv:DIR
;;
;; Run from the repository root.  SLOG_OPT=0 recommended (no hot-swap
;; logic here -- strata run whatever tier sbuild-runnable returns first).

(require "../../compiler/catalog.rkt"
         "../../compiler/names.rkt"
         "../../compiler/session.rkt")

(define (num-or-str v) (or (string->number v) v))

(define (parse-op s)
  (match (string-split s ":")
    [(list "open" db) `(open ,db)]
    [(list "run" prog) `(run ,prog)]
    [(list "pipeline") `(pipeline)]
    [(list "boundary") `(boundary)]
    [(list "bundle") `(bundle)]
    [(list "daemon-boundaries") `(daemon-boundaries)]
    [(list "daemon-current-boundary") `(daemon-current-boundary)]
    [(list "recipe") `(recipe)]
    [(list "sizes") `(sizes)]
    [(list "schema") `(schema)]
    [(list "flush") `(flush)]
    [(list "sizes-at" p) `(sizes-at ,(string->number p))]
    [(list "dump-rel" arg)
     (match (string-split arg ",")
       [(list rel) `(dump-rel ,rel)]
       [(list rel p) `(dump-rel ,rel ,(string->number p))])]
    [(list "dump-tuples" rel) `(dump-tuples ,rel)]
    [(list "dump-cells" rel) `(dump-cells ,rel)]
    [(list "dump-ids" rel) `(dump-ids ,rel)]
    [(list "write-db" db) `(write-db ,db)]
    [(list "write-csv" dir) `(write-csv ,dir)]
    [(list "add-tuple" arg)
     (match-define (cons rel vals) (string-split arg ","))
     `(add-tuple ,rel ,@(map num-or-str vals))]
    [(list "del-tuple" arg)
     (match-define (cons rel vals) (string-split arg ","))
     `(del-tuple ,rel ,@(map num-or-str vals))]
    [(list "inject-version" arg)
     (match (string-split arg ",")
       [(list rel) `(inject-version ,(string->symbol rel) #f)]
       [(list rel key) `(inject-version ,(string->symbol rel) ,key)])]
    [(list "inject+" arg)
     (match-define (cons rel vals) (string-split arg ","))
     `(inject+ ,(string->symbol rel) ,(map num-or-str vals))]
    [(list "inject-reopen" arg)
     (match-define (list* rel key prog vals) (string-split arg ","))
     `(inject-reopen ,(string->symbol rel) ,key ,prog ,(map num-or-str vals))]
    [(list "batch+" arg)
     (match-define (cons rel vals) (string-split arg ","))
     `(batch + tip ,(string->symbol rel) ,(map num-or-str vals))]
    [(list "batch-" arg)
     (match-define (cons rel vals) (string-split arg ","))
     `(batch - tip ,(string->symbol rel) ,(map num-or-str vals))]
    ;; anchored batches (0.C): abatch+:P,rel,v,..  -- anchor at position P
    [(list "abatch+" arg)
     (match-define (list* p rel vals) (string-split arg ","))
     `(batch + ,(string->number p) ,(string->symbol rel) ,(map num-or-str vals))]
    [(list "abatch-" arg)
     (match-define (list* p rel vals) (string-split arg ","))
     `(batch - ,(string->number p) ,(string->symbol rel) ,(map num-or-str vals))]
    ;; bulk bin-db payload (0.C1): import-delta:DIR[,SRC=DST...]
    [(list "import-delta" arg)
     (match-define (cons dir renames) (string-split arg ","))
     `(import-delta ,dir ,(for/list ([r (in-list renames)])
                            (match-define (list a b) (string-split r "="))
                            (list (string->symbol a) (string->symbol b))))]
    ;; anchored bulk payload (0.E0b): aimport-delta:P,DIR[,SRC=DST...]
    [(list "aimport-delta" arg)
     (match-define (list* p dir renames) (string-split arg ","))
     `(import-delta-at ,(string->number p) ,dir
                       ,(for/list ([r (in-list renames)])
                          (match-define (list a b) (string-split r "="))
                          (list (string->symbol a) (string->symbol b))))]
    [(list "save" name) `(save ,name)]
    ;; environment operations (0.D): rename-rel:R,S | drop-rel:R
    [(list "rename-rel" arg)
     (match-define (list from to) (string-split arg ","))
     `(rename-rel ,from ,to)]
    [(list "drop-rel" rel) `(drop-rel ,rel)]
    ;; N4-B attachment: attach:DB,DEST maps the saved root; attach:DB,SRC,DEST
    ;; maps one dependency-closed subtree.
    [(list "attach" arg)
     (match (string-split arg ",")
       [(list db dest) `(attach ,db #f ,dest)]
       [(list db source dest) `(attach ,db ,source ,dest)])]
    ;; hot-link a stored database (0.D5): link:DB[,SRC=DST...]
    [(list "link" arg)
     (match-define (cons db renames) (string-split arg ","))
     `(link ,db ,(for/list ([r (in-list renames)])
                   (match-define (list a b) (string-split r "="))
                   (list (string->symbol a) (string->symbol b))))]
    [(list "reenter" rel) `(reenter ,(string->symbol rel))]
    [(list "rerun" rel) `(rerun ,(string->symbol rel))]
    ;; the count round + sidecar introspection (docs/incremental.md §8B, M0)
    ;;   recount            whole pipeline (tip), lazy
    ;;   recount:REL        REL's counting cone (tip), lazy
    ;;   recount-at:P[,REL] per-version counts bound at position P
    ;;   recount-force      drop all count state, then whole pipeline
    ;;   count-state        the per-(relation, version) counted flags
    ;;   dump-counts:REL[,P]  sidecar contents (optionally at position P)
    [(list "recount") `(recount #f #f #f)]
    [(list "recount" rel) `(recount ,(string->symbol rel) #f #f)]
    [(list "recount-at" arg)
     (match (string-split arg ",")
       [(list pp) `(recount #f ,(string->number pp) #f)]
       [(list pp rel) `(recount ,(string->symbol rel) ,(string->number pp) #f)])]
    [(list "recount-force") `(recount #f #f #t)]
    [(list "recount-lattices-force") `(recount-lattices-force)]
    [(list "recount-try") `(recount-try)]
    [(list "recount-fail" n) `(recount-fail ,(string->number n))]
    [(list "recount-omit" n) `(recount-omit ,(string->number n))]
    [(list "count-state") `(count-state)]
    [(list "lattice-contributor-state") `(lattice-contributor-state)]
    [(list "count-capabilities") `(count-capabilities)]
    [(list "count-test-max" n) `(count-test-max ,(string->number n))]
    [(list "update-epoch") `(update-epoch)]
    [(list "begin-update" n) `(begin-update ,(string->number n))]
    [(list "commit-update") `(commit-update)]
    [(list "abort-update") `(abort-update)]
    [(list "signed-underflow") `(exercise-signed-underflow)]
    [(list "input-ledger") `(input-ledger)]
    [(list "dump-all-counts") `(dump-all-counts)]
    [(list "dump-counts" arg)
     (match (string-split arg ",")
       [(list rel) `(dump-counts ,rel)]
       [(list rel pp) `(dump-counts ,rel ,(string->number pp))])]
    [(list "rank-witness-state") `(rank-witness-state)]
    [(list "dump-ranks" arg)
     (match (string-split arg ",")
       [(list rel) `(dump-ranks ,rel)]
       [(list rel pp) `(dump-ranks ,rel ,(string->number pp))])]
    [_ (error 'session-drive "unrecognized op: ~a" s)]))

;; response readers for the query actions
(define (echo-one-line out)
  (define line (read-line out))
  (unless (eof-object? line) (displayln line)))
(define ((echo-until rx) out)
  (let loop ()
    (define line (read-line out))
    (unless (eof-object? line)
      (displayln line)
      (unless (regexp-match? rx line) (loop)))))

(module+ main
  (define ops (map parse-op (vector->list (current-command-line-arguments))))
  (define s (make-session))
  (for ([op (in-list ops)])
    (match op
      [`(open ,db) (session-open! s db)]
      [`(run ,prog) (session-run! s prog)]
      [`(batch ,sign tip ,rel ,tuple) (session-batch! s sign rel tuple)]
      [`(batch ,sign ,anchor ,rel ,tuple)
       (session-batch! s sign rel tuple #:at anchor)]
      [`(import-delta ,dir ,renames) (session-import-delta! s dir renames)]
      [`(import-delta-at ,p ,dir ,renames)
       (session-import-delta! s dir renames #:at p)]
      [`(link ,db ,renames) (session-link! s db renames)]
      [`(rename-rel ,from ,to) (session-rename! s from to)]
      [`(drop-rel ,rel) (session-drop! s rel)]
      [`(attach ,db ,source ,dest)
       (define plan
         (session-attach! s db
                          #:source (and source (symbol->qname
                                                (string->symbol source)))
                          #:as (symbol->qname (string->symbol dest))))
       (writeln
        `(attached ,db
                   (source ,(let ([path (attachment-plan-source-path plan)])
                              (if path (qname->symbol path) '||)))
                   (destination
                    ,(qname->symbol (attachment-plan-destination-path plan)))
                   (boundary ,(attachment-plan-boundary-key plan))
                   (versions
                    ,@(for/list ([entry (in-list
                                         (attachment-plan-version-map plan))])
                        `(,(car entry) ,(cdr entry))))
                   (types
                    ,@(for/list ([entry (in-list
                                         (attachment-plan-type-map plan))])
                        `(,(car entry) ,(cdr entry))))
                   (imports
                    ,@(for/list ([entry (in-list
                                         (attachment-plan-imports plan))])
                        `(,(qname->symbol (car entry))
                          ,(qname->symbol (cdr entry)))))))]
      [`(flush) (session-flush! s)]
      [`(save ,name) (session-save! s name)]
      [`(add-tuple ,rel ,vals ...)
       (session-add-tuple! s (string->symbol rel) vals)]
      [`(del-tuple ,rel ,vals ...)
       (session-del-tuple! s (string->symbol rel) vals)]
      [`(inject-version ,rel ,key)
       (session-inject-version! s rel #:key key)]
      [`(inject+ ,rel ,tuple)
       (session-inject-batch! s rel (list tuple))]
      [`(inject-reopen ,rel ,key ,prog ,tuple)
       (session-inject-and-reopen! s rel prog (list tuple) #:key key)]
      [`(reenter ,rel) (session-reenter! s rel)]
      [`(rerun ,rel) (session-rerun! s rel)]
      [`(recount ,rel ,at ,force?)
       (session-recount! s #:rel rel #:at at #:force? force?)]
      [`(recount-lattices-force)
       (session-recount! s #:force? #t #:lattices? #t)]
      [`(recount-try)
       (with-handlers ([exn:fail?
                        (lambda (e)
                          (displayln `(recount-rejected ,(exn-message e))))])
         (session-recount! s #:force? #t))]
      [`(recount-fail ,n)
       (with-handlers ([exn:fail?
                        (lambda (e)
                          (displayln `(recount-failed ,n ,(exn-message e))))])
         (session-recount! s #:force? #t #:fail-after n))]
      [`(recount-omit ,n)
       (with-handlers ([exn:fail?
                        (lambda (e)
                          (displayln `(recount-omitted ,n ,(exn-message e))))])
         (session-recount! s #:force? #t #:omit-writer n))]
      [`(count-state) (session-action! s `(count-state) echo-one-line)]
      [`(lattice-contributor-state)
       (session-action! s `(lattice-contributor-state) echo-one-line)]
      [`(rank-witness-state)
       (session-action! s `(rank-witness-state) echo-one-line)]
      [`(dump-ranks ,rel) (session-action! s `(dump-ranks ,rel)
                                           (echo-until #px"^\\(rankdone "))]
      [`(dump-ranks ,rel ,pp) (session-action! s `(dump-ranks ,rel ,pp)
                                               (echo-until #px"^\\(rankdone "))]
      [`(count-capabilities)
       (session-action! s `(count-capabilities) echo-one-line)]
      [`(count-test-max ,n)
       (session-action! s `(count-test-max ,n) echo-one-line)]
      [`(update-epoch) (session-action! s `(update-epoch) echo-one-line)]
      [`(begin-update ,n) (session-action! s `(begin-update ,n) echo-one-line)]
      [`(commit-update) (session-action! s `(commit-update) echo-one-line)]
      [`(abort-update) (session-action! s `(abort-update) echo-one-line)]
      [`(exercise-signed-underflow)
       (session-action! s `(exercise-signed-underflow) echo-one-line)]
      [`(input-ledger)
       (session-action! s `(input-ledger)
                        (echo-until #px"^\\(inputledger-done "))]
      [`(dump-all-counts)
       (session-action! s `(dump-all-counts)
                        (echo-until #px"^\\(vcountdone "))]
      [`(dump-counts ,rel) (session-action! s `(dump-counts ,rel)
                                            (echo-until #px"^\\(countdone "))]
      [`(dump-counts ,rel ,pp) (session-action! s `(dump-counts ,rel ,pp)
                                                (echo-until #px"^\\(countdone "))]
      [`(pipeline) (session-action! s `(pipeline) echo-one-line)]
      [`(boundary)
       (define current (session-current-boundary s))
       (writeln
        (if current
            `(catalog-boundary
              (key ,(boundary-key current))
              (plans ,(length (session-boundary-history s)))
              (declarations
               ,@(sort
                  (map qname->symbol
                       (hash-keys
                        (catalog-declarations
                         (boundary-catalog current))))
                  symbol<?))
              (versions
               ,@(sort
                  (map qname->symbol
                       (hash-keys (boundary-environment current)))
                  symbol<?)))
            `(catalog-boundary #f
                               (plans ,(length
                                        (session-boundary-history s))))))]
      ;; N4-A: the durable bundle this session would save (n4-contract.md §3),
      ;; projected to the identity facts a transcript can assert on.
      [`(bundle)
       (define bundle (session-boundary-bundle s))
       (writeln
        (cond
          [(not bundle) `(boundary-bundle #f (leased ,(session-prepared-boundary s)))]
          [else
           `(boundary-bundle
             (head ,(boundary-key (boundary-bundle-selected-head bundle)))
             (history
              ,@(for/list ([record (in-list (boundary-bundle-history bundle))])
                  `(,(boundary-record-origin-kind record)
                    ,(boundary-record-key record))))
             (versions
              ,@(for/list ([record (in-list (boundary-bundle-versions bundle))])
                  `(,(if (version-record-name record)
                         (qname->symbol (version-record-name record))
                         '||)
                    ,(version-record-kind record)
                    ,(version-record-key record)
                    ,(if (version-record-materialized? record)
                         'materialized 'metadata-only))))
             (types
              ,@(for/list ([record
                            (in-list (sort (boundary-bundle-types bundle)
                                           string<? #:key type-record-key))])
                  `(,(type-record-key record)
                    (arity ,(type-record-arity record))
                    (sid ,(type-record-sid record))
                    (names ,@(map qname->symbol
                                  (type-record-names record))))))
             (programs
              ,@(for/list ([record (in-list (boundary-bundle-programs bundle))])
                  `(,(program-record-key record)
                    (input ,(program-record-input record))
                    (output ,(program-record-output record))
                    (modules ,(length (program-record-modules record)))))))]))]
      [`(daemon-boundaries)
       (for ([line (in-list
                    (session-command-stream!
                     s '(catalog boundaries)
                     (lambda (line)
                       (regexp-match? #px"^\\(catalog-end [0-9]+\\)$"
                                      line))))])
         (displayln line))]
      [`(daemon-current-boundary)
       (define current (session-current-boundary s))
       (unless current
         (error 'session-drive "no current committed boundary"))
       (for ([line (in-list
                    (session-command-stream!
                     s `(catalog boundary ,(boundary-key current))
                     (lambda (line)
                       (regexp-match? #px"^\\(catalog-end [0-9]+\\)$"
                                      line))))])
         (displayln line))]
      [`(recipe) (writeln (session-recipe s))]
      [`(sizes-at ,p) (session-action! s `(sizes-at ,p) echo-one-line)]
      [`(dump-rel ,rel) (session-action! s `(dump-rel ,rel)
                                         (echo-until #px"^\\(dumpdone "))]
      [`(dump-rel ,rel ,p) (session-action! s `(dump-rel ,rel ,p)
                                            (echo-until #px"^\\(dumpdone "))]
      [`(dump-tuples ,rel) (session-action! s `(dump-tuples ,rel)
                                             (echo-until #px"^\\(tupledone "))]
      ;; the value adapter: structured cells rather than a rendered line
      [`(dump-cells ,rel) (session-action! s `(dump-cells ,rel)
                                           (echo-until #px"^\\(cellsdone "))]
      [`(dump-ids ,rel) (session-action! s `(dump-ids ,rel)
                                         (echo-until #px"^\\(idsdone "))]
      [`(sizes)
       ;; no terminator line: rely on ordering -- the lines flush before
       ;; the next op's response and drain at close
       (session-action! s `(sizes))]
      [`(schema) (session-action! s `(schema)
                                  (echo-until #px"^\\(schema-end\\)"))]
      [`(write-db ,db) (session-action! s `(write-db ,db))]
      [`(write-csv ,dir) (session-action! s `(write-csv ,dir))]))
  (exit (if (> (session-close! s) 0) 1 0)))
