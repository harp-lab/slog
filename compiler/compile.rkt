#lang racket

;; The compilation pipeline, one pass per line (see ir-stack.rkt for the
;; intermediate languages):
;;
;;   path --modules.rkt--> programs (dependencies first, manifests threaded)
;;   each program:
;;     rules --simplify--> flat --typecheck--> typed --stratify--> strata
;;   each stratum:
;;     rules --plan--> planned --lower--> c-program --emit--> C++ --> .so
;;
;; The unit of execution is the stratum program: the driver (runslog.rkt)
;; loads and runs each one to fixpoint in order, reloading the database
;; between them, which walks the SCC DAG in topological order.
;;
;; Each pass output is checked against its IR predicate once per program or
;; stratum (the define/contract wrappers below) -- coarse contracts, not
;; per-node decoration.
;;
;; Compiled strata are cached in build/ keyed by a hash of the program
;; sources, the type environment, the manifest, the daemon headers (the .so
;; inlines daemon data-structure layouts), and the stratum level.  Compiles
;; run in a chain of futures so the daemon can execute stratum k while
;; stratum k+1 compiles.

(provide compile-path)

(require "params.rkt")
(require "utils.rkt")
(require "modules.rkt")
(require "simplification.rkt")
(require "type-system.rkt")
(require "stratify.rkt")
(require "lattice-check.rkt")
(require "join-planning.rkt")
(require "operationalization.rkt")
(require "emit-cpp.rkt")
(require "ir-shared.rkt")
(require "ir-stack.rkt")
(require "tools.rkt")
(require racket/future)
(require sha)

;; -----------------------------------------------------------------------
;; Pass drivers, contract-checked once per program/stratum.

(define/contract (simplify-all rules)
  (-> set? (set/c flat-rule?))
  (foldl simplify-rule (set) (set->list rules)))

(define/contract (typecheck-all type-env rules)
  (-> type-env? set? (set/c typed-rule?))
  (typecheck-rules type-env rules))

(define/contract (stratify-all rules)
  (-> set? strata?)
  (stratify-rules rules))

(define/contract (plan-all rules rel-env dynamic-rels)
  (-> set? hash? set? (cons/c (set/c planned-rule?) hash?))
  (plan-stratum rules rel-env dynamic-rels))

(define/contract (lower-all planned-rules rel-env)
  (-> set? hash? cprog?)
  (build-cprog planned-rules rel-env))

;; -----------------------------------------------------------------------
;; Front end: a program to its list of stratum jobs.
;;
;; A job is (job hash type-env stratum-rules): everything needed to build
;; one stratum's .so, plus the cache key deciding whether to.  The key is
;; computed from pre-simplification inputs only -- later passes introduce
;; generated names that differ run to run, while the front end's output is
;; a pure function of these inputs.

(define (program->jobs prog)
  (match-define `(program ,type-env ,mods ,dbmanifest) prog)
  (define info0 (sort (hash->list (type-env-aliases type-env)) symbol<? #:key car))
  (define info1 (sort (hash->list (type-env-rels type-env)) symbol<? #:key car))
  (define info2 (sort (set->list mods) string<? #:key second))
  (define info3 (sort (hash->list dbmanifest) symbol<? #:key car))
  (define progstr
    (with-output-to-string
     (lambda () (print (list info0 info1 info2 info3
                             daemon-headers-fingerprint
                             compiler-sources-fingerprint
                             ;; codegen-affecting settings: a toggle must
                             ;; miss the cache rather than reuse a .so
                             ;; compiled under the other setting
                             (semijoin-filters-enabled))))))
  (define (job-hash level)
    (substring (bytes->hex-string
                (sha256 (string->bytes/utf-8 (format "~a:stratum ~a" progstr level))))
               0
               (if debug-mode 8 32)))

  (define all-rules
    (foldl set-union (set) (map last (set->list mods))))
  ;; lattice declaration occurrence restrictions run before typechecking
  ;; (a misplaced lattice type should be its own error, not a type error);
  ;; the monotone-use calculus needs the strata for the same-SCC bit
  (check-lattice-declarations type-env)
  (define typed (typecheck-all type-env (simplify-all all-rules)))
  (define strata (stratify-all typed))
  (check-lattice-strata strata type-env)
  (for/list ([stratum (in-list strata)])
    (list (job-hash (stratum-level stratum)) type-env stratum dbmanifest)))

;; -----------------------------------------------------------------------
;; Back end: build one stratum program (unless its .so is already cached).

(define (compile-job job)
  (match-define (list proghash type-env stratum dbmanifest) job)
  (define so-path (fullpath (format "build/~a.so" proghash)))
  (cond
    [(file-exists? so-path) proghash]
    [else
     ;; a stratum whose rules carry residual type checks also gets the
     ;; error-wrapping rule (malformed_deduction -> error), delta-driven
     ;; within this stratum's fixpoint: malformed_deduction is marked
     ;; dynamic since the checks' failure paths grow it every iteration
     (define base-rules (stratum-rules stratum))
     (define checked?
       (for/or ([rule (in-set base-rules)]) (rule-has-tychecks? rule)))
     (define rules
       (if checked? (set-add base-rules (error-wrap-rule)) base-rules))
     (define dynamic-rels
       (for/fold ([acc (if checked? (set 'malformed_deduction) (set))])
                 ([rule (in-set rules)])
         (set-union acc (rule-head-rels rule))))
     (match-define (cons planned rel-env+)
       (plan-all rules (type-env-rels type-env) dynamic-rels))
     (define cprog (lower-all planned rel-env+))
     (list proghash cprog (write-cpp cprog dbmanifest proghash))]))

;; -----------------------------------------------------------------------
;; Entry point: returns a touched FutureStream
;;    (or '() (cons compiled FutureStream))
;; where compiled is a hash string (cached) or (list hash cprog cpp-string);
;; tools.rkt's finish-jit turns either into a build/<hash>.so path.

(define (compile-path path dbmanifest)
  (define jobs
    (append-map program->jobs (load-program-list path dbmanifest)))
  (define (compile-future lst)
    (if (null? lst)
        (future (lambda () '()))
        (future (lambda ()
                  (let ([rest (compile-future (cdr lst))])
                    (cons (compile-job (car lst)) rest))))))
  (touch (compile-future jobs)))
