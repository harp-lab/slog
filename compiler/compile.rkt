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
;; inlines daemon data-structure layouts), and the stratum level -- but NOT the
;; optimization level, so an -O0 build and its -O2 hot-swap replacement share
;; one cache slot (docs/fast-compile.md).  Builds run on a bounded parallel pool
;; (tools.rkt) so a program's strata compile concurrently and overlap the run.

(provide compile-strata (struct-out sbuild) (struct-out db-partition)
         stratum-meta-dynamic-rels   ; segment write-sets (incremental B0)
         read-stratum-meta           ; cone/polarity input (incremental B4)
         program->jobs)   ; tooling/debug: inspect a program's stratum jobs

(require "params.rkt")
(require "utils.rkt")
(require "modules.rkt")
(require "simplification.rkt")
(require "seq-expand.rkt")
(require "type-system.rkt")
(require "stratify.rkt")
(require "lattice-check.rkt")
(require "join-planning.rkt")
(require "operationalization.rkt")
(require "emit-cpp.rkt")
(require "ir-shared.rkt")
(require "ir-stack.rkt")
(require "tools.rkt")
(require "freeze.rkt")
(require sha)

;; -----------------------------------------------------------------------
;; Pass drivers, contract-checked once per program/stratum.

(define/contract (simplify-all rules)
  (-> set? (set/c flat-rule?))
  (foldl simplify-rule (set) (set->list rules)))

(define/contract (typecheck-all type-env rules [decomps (hash)])
  (->* (type-env? set?) (hash?) (set/c typed-rule?))
  (typecheck-rules type-env rules decomps))

(define/contract (stratify-all rules [extra-edges (set)])
  (->* (set?) (set?) strata?)
  (stratify-rules rules extra-edges))

(define/contract (plan-all rules rel-env dynamic-rels)
  (-> set? hash? set? (cons/c (set/c planned-rule?) hash?))
  (plan-stratum rules rel-env dynamic-rels))

(define/contract (lower-all planned-rules rel-env decomps)
  (-> set? hash? hash? cprog?)
  (build-cprog planned-rules rel-env decomps))

;; -----------------------------------------------------------------------
;; Front end: a program to its list of stratum jobs.
;;
;; A job is (job hash type-env stratum-rules): everything needed to build
;; one stratum's .so, plus the cache key deciding whether to.  The key is
;; computed from pre-simplification inputs only -- later passes introduce
;; generated names that differ run to run, while the front end's output is
;; a pure function of these inputs.

;; program->jobs returns (list jobs facts-stratum? frozen).  When
;; #:split-facts? is set (a compressed save, docs/db-compression.md P0.5), the
;; program's iteration-0 rules -- those whose body reads no declared relation,
;; i.e. facts and constant/primitive-computed ground tuples -- are pulled into
;; a dedicated level-0 "facts stratum" run strictly first, with every real
;; stratum bumped up one level.  This is level-preserving for the real strata
;; (an iter0 rule contributes no dependency edge, so removing it changes no
;; SCC) and lets the driver snapshot the pure iteration-0 EDB after that one
;; stratum, before any derived tuple exists -- correct even for a relation
;; grounded by BOTH facts and rules.  facts-stratum? is #t iff a non-empty
;; facts stratum was prepended.  frozen is #f, or (cons hash stream): the
;; program's big ground rules peeled into a fact stream (freeze.rkt) for
;; compile-strata to render as a static database the driver links in.
(define (program->jobs prog #:split-facts? [split-facts? #f])
  (match-define `(program ,type-env ,mods0 ,dbmanifest ,decomps) prog)
  ;; Robustness lint (docs/bug-daemon-crash-shape-car.md): the compiler mints
  ;; value-reference C++ locals as `v_<var>` and shares that textual namespace
  ;; with any relation/struct/lattice/enum whose name begins with `v_`.  Such
  ;; names are supported now (emit-cpp's canonicalize-vrefs keeps declared names
  ;; verbatim), but the overlap is a latent trap -- it SILENTLY mis-compiled in
  ;; split strata before that fix (a per-TU rename desynchronised the daemon
  ;; relation names -> null Relation* -> segfault).  Warn once per declared name.
  (for ([name (in-list (sort (hash-keys (type-env-rels type-env)) symbol<?))]
        #:when (regexp-match? #rx"^v_" (symbol->string name)))
    (eprintf (string-append
              "warning: name `~a` begins with `v_`, the prefix the compiler uses"
              " for value references -- supported, but the shared namespace is"
              " fragile; prefer another prefix (docs/bug-daemon-crash-shape-car.md)\n")
             name))
  ;; peel BEFORE the cache key: a peeled program's rule set (and so its
  ;; stratum hashes) differs from the unpeeled one's, and the frozen
  ;; database is content-addressed separately (freeze.rkt)
  (define-values (mods frozen)
    (peel-ground-facts mods0 type-env #:enabled? (not split-facts?)))
  (define info0 (sort (hash->list (type-env-aliases type-env)) symbol<? #:key car))
  (define info1 (sort (hash->list (type-env-rels type-env)) symbol<? #:key car))
  (define info2 (sort (set->list mods) string<? #:key second))
  (define info3 (sort (hash->list dbmanifest) symbol<? #:key car))
  ;; the M2.4 decomposition registry changes codegen (merge-task decomp
  ;; targets) without necessarily changing the rels env (a user decl toggling
  ;; the synthesis off), so it keys the cache too
  (define info4 (sort (hash->list decomps) symbol<? #:key car))
  (define progstr
    (with-output-to-string
     (lambda () (print (list info0 info1 info2 info3 info4
                             daemon-headers-fingerprint
                             compiler-sources-fingerprint
                             ;; codegen-affecting settings: a toggle must
                             ;; miss the cache rather than reuse a .so
                             ;; compiled under the other setting
                             (semijoin-filters-enabled)
                             ;; the facts split changes stratum rule sets, so
                             ;; it must key the cache (else a split and a
                             ;; non-split build would share a .so slot)
                             split-facts?)))))
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
  ;; sequence-pattern expansion (docs/sequences.md §5, seq-expand.rkt):
  ;; lower the desugar's neutral seq-pat clauses onto prim computes/guards/
  ;; occurrence joins.  Post-simplification (wildcards are __-gensym'd, D13),
  ;; pre-typecheck (the emitted clauses are ordinary surface forms).  May
  ;; declare the $seq_at/$seq_atr occurrence relations and return their
  ;; stratification edges (base -> occurrence, decomp-edges style).
  (define-values (expanded type-env+ seq-edges)
    (expand-seq-patterns (simplify-all all-rules) type-env))
  (define typed (typecheck-all type-env+ expanded decomps))
  ;; the M2.4 decomposition's derived dependency edges: R -> R_has as if a
  ;; rule read R and wrote R_has (the base's merge tasks do exactly that), so
  ;; a derived relation closes no earlier than its base -- and shares its SCC
  ;; when some rule feeds R_has back into R (in-SCC enumeration)
  (define decomp-edges
    (set-union (for/set ([(derived info) (in-hash decomps)])
                 (cons (first info) derived))
               seq-edges))
  (define full-strata (stratify-all typed decomp-edges))
  ;; check the ORIGINAL stratification (a superset that keeps iter0 rules in
  ;; place); the split only moves body-less rules, which can never violate the
  ;; monotone-use calculus, so passing here implies the split is safe too.
  (check-lattice-strata full-strata type-env+ decomps)
  ;; the §5.3 blowup warning (docs/sequences.md, defense (b)): a fed list
  ;; column on a relation that grows RECURSIVELY materializes O(n) list ids
  ;; x O(len) occurrence rows while indexing is active.  Warn, don't error:
  ;; sometimes the quadratic index is exactly what the user wants.
  (when (hash-has-key? (type-env-rels type-env+) '$seq_at)
    (define fed (list->set (seq-fed-relations (type-env-rels type-env+))))
    (for ([s (in-list full-strata)])
      ;; recursive in this stratum = written AND read here (SCC-merged
      ;; strata make this the head∩body of the whole level, catching
      ;; mutual recursion too)
      (define-values (hs bs)
        (for/fold ([hs (set)] [bs (set)]) ([rule (in-set (stratum-rules s))])
          (values (set-union hs (rule-head-rels rule))
                  (set-union bs (rule-body-rels rule)))))
      (for ([r (in-list (sort (set->list (set-intersect hs bs fed))
                              symbol<?))])
        (eprintf "warning: relation ~a carries a sequence column and grows recursively (stratum ~a) while occurrence indexing is active -- its occurrence rows can reach O(lists x elements); prefer the bound direction or restructure (docs/sequences.md §5.3)\n"
                 r (stratum-level s)))))
  (define rel-names (list->set (hash-keys (type-env-rels type-env+))))
  (define fact-rules
    (if split-facts? (ground-fact-rules typed rel-names) (set)))
  (define facts? (not (set-empty? fact-rules)))
  (define strata
    (cond
      [(not facts?) full-strata]
      [else
       (define rest-strata (stratify-all (set-subtract typed fact-rules) decomp-edges))
       (cons `(stratum 0 ,fact-rules)
             (for/list ([s (in-list rest-strata)])
               `(stratum ,(add1 (stratum-level s)) ,(stratum-rules s))))]))
  (list (for/list ([stratum (in-list strata)])
          (list (job-hash (stratum-level stratum)) type-env+ stratum dbmanifest decomps))
        facts?
        frozen))

;; -----------------------------------------------------------------------
;; Rule/SCC ids + sidecar manifest (docs/pausing.md §6).
;;
;; A rule id is a 31-bit hash of the rule's SOURCE TEXT (not its location --
;; line shifts must not churn ids), disambiguated by an occurrence counter
;; among identical duplicate rules.  Computed from the pre-lowering typed rule,
;; so every split/staged descendant of one source rule shares its id.  Ids are
;; deliberately NOT baked into the .so (that would couple the .so cache to the
;; whole program's rule list); the manifest is a plain sidecar next to the
;; build artifacts that the front end reads to correlate the daemon's SCC id
;; (= pipeline position, assigned at push) with a stratum's hash-name and its
;; rules' source -- and, in a later step, to diagnose malformed_deduction rows.

(define (rule-text rule) (format "~s" (strip-prov rule)))

(define (rule-location rule)
  (match (syn-prov rule)
    [`(prov (token ,_ (pos ,file ,line ,_ ...) ,_) ,_)
     (define p (file-name-from-path (format "~a" file)))
     (format "~a:~a" (if p (path->string p) file) (add1 line))]
    [_ "<unknown>"]))

(define (rule-id-of text occurrence)
  (bitwise-and
   (integer-bytes->integer
    (subbytes (sha256 (string->bytes/utf-8 (format "~a#~a" text occurrence))) 0 4)
    #f #t)
   #x7fffffff))

;; (id location text rec? same-scc neg-body lat-body) per rule of a stratum,
;; occurrence-disambiguated in a deterministic (text-sorted) order so ids are
;; stable across runs.
(define (stratum-rule-metas stratum dynamic-rels rel-env)
  (define rules (sort (set->list (stratum-rules stratum)) string<? #:key rule-text))
  (define seen (make-hash))
  (for/list ([rule (in-list rules)])
    (define text (rule-text rule))
    (define occ (hash-ref seen text 0))
    (hash-set! seen text (add1 occ))
    ;; docs/incremental.md §6.4/§7A.7: a body relation lies in the head's SCC
    ;; iff it is produced WITHIN this stratum (i.e. is dynamic), so a rule is
    ;; recursive -- would bump `rec` rather than `nonrec` under DRed^c counting
    ;; -- iff any of its body relations is dynamic.  The bit exists only
    ;; implicitly today (via dynamic-rels membership at emit time); exposing it
    ;; per rule now lets the incremental driver's routing/cone logic and M2's
    ;; counter tagging read it straight off the manifest ("tag the IR once").
    (define same-scc-body
      (sort (set->list (set-intersect (rule-body-rels rule) dynamic-rels))
            symbol<?))
    ;; per-edge polarity (§0.8 A7 / §0.5): the rule's negated reads, and its
    ;; lattice-valued reads (reading a merged value is conservatively a
    ;; non-monotone edge -- a positive batch below can retract the value a
    ;; derivation consumed)
    (define neg-body (sort (set->list (rule-body-neg-rels rule)) symbol<?))
    (define lat-body
      (sort (for/list ([r (in-set (rule-body-pos-rels rule))]
                       #:when (rel-lattice-spec rel-env r))
              r)
            symbol<?))
    (list (rule-id-of text occ) (rule-location rule) text
          (pair? same-scc-body) same-scc-body neg-body lat-body)))

;; A stratum's augmented rule set (base rules + the error/oracle arm rules its
;; residual checks require) and its dynamic-rels -- the relations produced
;; WITHIN this stratum (head rels plus the decomp/oracle/seq side channels that
;; re-derive from reloaded content at iteration 0).  Shared by the back end
;; (emit-stratum-cpp) and the sidecar manifest (write-stratum-manifest) so a
;; rule's recursive/non-recursive classification (docs/incremental.md §6.4) is
;; computed one way.  Returns (values rules dynamic-rels).
(define (stratum-rules+dynamic stratum type-env decomps)
  (define base-rules (stratum-rules stratum))
  ;; a stratum whose rules carry residual type checks also gets the
  ;; error-wrapping rule (malformed_deduction -> error), delta-driven within
  ;; this stratum's fixpoint: malformed_deduction is marked dynamic since the
  ;; checks' failure paths grow it every iteration
  (define checked?
    (for/or ([rule (in-set base-rules)]) (rule-has-tychecks? rule)))
  ;; strata using a fallible prim also wire the runtime-error arms (docs/type-
  ;; errors.md): a prim that hits bad data records an error_spec, wrapped to
  ;; (error e) by the injected per-arm rules below, delta-driven in this fixpoint.
  (define has-prims?
    (for/or ([rule (in-set base-rules)]) (rule-has-fallible-prims? rule)))
  ;; strata that write an extern demand struct dispatch to its oracle, whose
  ;; serialize failures record (smt_bad_formula reason formula) facts
  ;; (docs/smt.md §12) -- wire that arm + wrap rule exactly like the others
  (define base-heads
    (for/fold ([acc (set)]) ([rule (in-set base-rules)])
      (set-union acc (rule-head-rels rule))))
  (define has-oracle?
    (for/or ([(k decl) (in-hash (type-env-rels type-env))])
      (and (pair? decl) (eq? 'oracle (car decl))
           (set-member? base-heads (third decl)))))
  (define active-arms
    (append (if checked?    '(malformed_deduction) '())
            (if has-prims?  prim-error-arms        '())
            (if has-oracle? '(smt_bad_formula)     '())))
  (define rules
    (for/fold ([rs base-rules]) ([arm (in-list active-arms)])
      (set-add rs (error-wrap-rule-for-arm arm))))
  (define head-dynamic-rels
    (for/fold ([acc (list->set active-arms)])
              ([rule (in-set rules)])
      (set-union acc (rule-head-rels rule))))
  ;; a decomposed base's derived relation (R_has/R_at) is dynamic in EVERY
  ;; stratum, not just where the base ascends: the base's master (once)
  ;; MapWriteTask re-derives the decomposition from the reloaded/imported
  ;; content at iteration 0, and those rows ride the publish path into
  ;; iteration 1's delta -- a static reader would run at iteration 0 and
  ;; miss them (the foreign-db seeding case).  The PLANNER must treat the
  ;; derived name as dynamic so readers get a delta-driven version.
  (define decomp-dynamic-rels
    (for/fold ([acc head-dynamic-rels]) ([(derived _info) (in-hash decomps)])
      (set-add acc derived)))
  ;; an extern relation's answer table grows through the oracle's harvest
  ;; task -- a side channel, not a rule head -- so, exactly like the
  ;; malformed_deduction/error arms above, it must be marked dynamic in any
  ;; stratum that writes the demand struct, or the planner would treat it as
  ;; closed and rules joining it would never see answers arriving
  ;; mid-fixpoint (docs/smt.md)
  (define oracle-dynamic-rels
    (for/fold ([acc decomp-dynamic-rels])
              ([(k decl) (in-hash (type-env-rels type-env))])
      (if (and (pair? decl) (eq? 'oracle (car decl))
               (set-member? head-dynamic-rels (third decl)))
          (set-add acc (fourth decl))
          acc)))
  ;; the sequence-occurrence relations grow via SeqIndexTask's side channel
  ;; in EVERY stratum (iteration-0 re-derivation from the reloaded content,
  ;; docs/sequences.md §5.3) -- dynamic exactly like decomp targets
  (define dynamic-rels
    (for/fold ([acc oracle-dynamic-rels])
              ([occ (in-list '($seq_at $seq_atr))])
      (if (hash-has-key? (type-env-rels type-env) occ) (set-add acc occ) acc)))
  (values rules dynamic-rels))

;; Write build/<hash>.meta: this stratum's compile hash, DAG level (one stratum
;; per level, in pipeline order), the relations it produces (dynamic-rels), its
;; reads with per-edge polarity, and its rules (id -> location + source text +
;; recursive bit + same-SCC body rels + negated/lattice reads).  Refreshed on
;; every compile-job so a cached .so still gets a current manifest.
;;
;; The `reads` field is the incremental driver's cone/polarity input
;; (docs/incremental.md §0.5, §0.8 A7): one entry per body-read relation with
;; its edge kinds -- `pos` (some rule reads it positively), `neg` (some rule
;; negates it), `lat` (some rule reads its merged lattice value; conservatively
;; non-monotone).  cone(R) falls out by chaining manifests: stratum S is in
;; R's cone iff R is read here or produced by a cone stratum below; the cone
;; is MONOTONE iff every edge along the way is a plain `pos` -- any `neg`/`lat`
;; edge routes that cone to clear-and-rerun rather than delta re-entry.
;; Consumers so far: the driver unions `dynamic-rels` into each segment's
;; write-set for the daemon's begin-segment version boundary (B0, below);
;; the reads/cone half still awaits the re-entry driver (0.B1).
(define (write-stratum-manifest proghash stratum type-env decomps)
  (define-values (_rules dynamic-rels)
    (stratum-rules+dynamic stratum type-env decomps))
  (define rel-env (type-env-rels type-env))
  (define rule-metas (stratum-rule-metas stratum dynamic-rels rel-env))
  ;; per-relation edge kinds, aggregated over the stratum's rules
  (define reads
    (let ([kinds (make-hash)])   ; rel -> set of 'pos/'neg/'lat
      (for ([rule (in-set (stratum-rules stratum))])
        (for ([r (in-set (rule-body-pos-rels rule))])
          (hash-update! kinds r (lambda (s) (set-add s (if (rel-lattice-spec rel-env r) 'lat 'pos))) (set)))
        (for ([r (in-set (rule-body-neg-rels rule))])
          (hash-update! kinds r (lambda (s) (set-add s 'neg)) (set))))
      (for/list ([r (in-list (sort (hash-keys kinds) symbol<?))])
        `(,r ,@(sort (set->list (hash-ref kinds r)) symbol<?)))))
  ;; pure rule heads, WITHOUT the diagnostic side channels dynamic-rels
  ;; carries (error arms, $seq_*, malformed_deduction, oracle tables): the
  ;; anchored-replay walk (0.C, compiler/session.rkt) propagates its
  ;; affected set through these -- side channels would make every stratum
  ;; look affected by every other
  (define heads
    (for/fold ([acc (set)]) ([rule (in-set (stratum-rules stratum))])
      (set-union acc (rule-head-rels rule))))
  (define meta
    `(stratum-meta
      (hash ,proghash)
      (level ,(stratum-level stratum))
      (dynamic-rels ,@(sort (set->list dynamic-rels) symbol<?))
      (heads ,@(sort (set->list heads) symbol<?))
      (reads ,@reads)
      (rules
       ,@(for/list ([m (in-list rule-metas)])
           (match-define (list id loc text rec? same-scc neg-body lat-body) m)
           `(rule ,id ,loc ,text (rec ,rec?) (same-scc-body ,@same-scc)
                  (neg-body ,@neg-body) (lat-body ,@lat-body))))))
  (call-with-atomic-output (fullpath (format "build/~a.meta" proghash))
                           (lambda () (writeln meta))))

;; Read back one stratum's build/<hash>.meta and return its `dynamic-rels`
;; (the relations the stratum produces) as a list of symbols -- the driver
;; unions these into a segment write-set for the daemon's begin-segment
;; version boundary (docs/incremental.md §0.4-§0.5, B0).  A missing or
;; malformed manifest yields '() -- conservative for content (an unannounced
;; write lands in the predecessor version in place; final fixpoints are
;; unchanged, only versioned addressing loses precision for that name).
(define (stratum-meta-dynamic-rels proghash)
  (define-values (dyn _reads _heads) (read-stratum-meta proghash))
  dyn)

;; The manifest fields the session driver consumes: (values dynamic-rels
;; reads heads) -- reads is the ((REL KIND ...) ...) polarity entries
;; (cone input), heads the pure rule heads (the anchored walk's affected
;; propagation; side-channel-free).  Metas regenerate on every compile
;; job, so a missing `heads` (a stale pre-0.C meta) degrades to '() only
;; transiently.
(define (read-stratum-meta proghash)
  (define p (fullpath (format "build/~a.meta" proghash)))
  (with-handlers ([exn:fail? (lambda (_) (values '() '() '()))])
    (match (call-with-input-file p read)
      [`(stratum-meta ,fields ...)
       (values (match (assq 'dynamic-rels fields)
                 [`(dynamic-rels ,rels ...) rels]
                 [_ '()])
               (match (assq 'reads fields)
                 [`(reads ,entries ...) entries]
                 [_ '()])
               (match (assq 'heads fields)
                 [`(heads ,rels ...) rels]
                 [_ '()]))]
      [_ (values '() '() '())])))

;; -----------------------------------------------------------------------
;; Back end: emit one stratum's C++ translation unit(s).
;;
;; Runs the per-stratum Racket passes (plan -> lower -> emit) and writes the
;; generated source to build/.  Returns the list of .cpp paths making up the
;; stratum (one for a small stratum; a spine + several parts for a large one,
;; docs/fast-compile.md §6).  The .so is NOT built here -- compile-strata below
;; schedules that on the parallel pool at the appropriate optimization level(s).

(define (emit-stratum-cpp job)
  (match-define (list proghash type-env stratum dbmanifest decomps) job)
  ;; the delta-entry flavor (docs/incremental.md 0.B5) writes its own
  ;; artifact family; "_delta" (not ".delta") because the name also becomes
  ;; the daemon stratum name and rides into generated identifiers
  (define hash-name
    (if (delta-entry-flavor) (string-append proghash "_delta") proghash))
  ;; the augmented rule set (+ error/oracle arms) and the relations produced
  ;; within this stratum, both from stratum-rules+dynamic -- shared with the
  ;; sidecar manifest so recursive/non-recursive classification is derived once.
  (define-values (rules dynamic-rels)
    (stratum-rules+dynamic stratum type-env decomps))
  ;; Delta-entry flavor (§0.5 mode 3): plan with the stratum's positive
  ;; table/struct INPUTS marked dynamic too -- the planner then emits
  ;; per-position delta-driven versions for them (the compiled entry point
  ;; that accepts "just the new tuples"), replacing the run-once full
  ;; scans; their delta indices/write-tasks follow from the same generic
  ;; requisition flow.  build-cprog's dynamic set stays head-based, so the
  ;; input-driven read tasks register ONCE -- exact, since an input's
  ;; delta is nonempty only at iteration 0.  Lattice-valued reads stay
  ;; static (the routing rule never delta-enters a lat cone), and negated
  ;; reads never drive (guards, not drivers).
  (define plan-dynamic
    (if (not (delta-entry-flavor))
        dynamic-rels
        (for*/fold ([acc dynamic-rels])
                   ([rule (in-set rules)]
                    [r (in-set (rule-body-pos-rels rule))]
                    #:unless (set-member? dynamic-rels r))
          (match (hash-ref (type-env-rels type-env) r #f)
            [`(struct ,_ ...) (set-add acc r)]
            [`(table ,_ ...)
             (if (rel-lattice-spec (type-env-rels type-env) r) acc (set-add acc r))]
            [_ acc]))))
  (match-define (cons planned rel-env+)
    (plan-all rules (type-env-rels type-env) plan-dynamic))
  (define cprog (lower-all planned rel-env+ decomps))
  ;; atomic writes: run-tests.sh -jN can compile the SAME content-addressed
  ;; stratum in two processes at once, and a torn .cpp/.cprog read would break a
  ;; concurrent clang (docs/fast-compile.md §8)
  (call-with-atomic-output (fullpath (format "build/~a.cprog" hash-name))
                           (lambda () (pretty-write cprog)))
  (define emitted (write-cpp cprog dbmanifest hash-name))
  ;; write-cpp returns either one string (a single TU) or a list of
  ;; (suffix . contents) pairs -- the spine (suffix "") plus part TUs.
  (define tus (if (string? emitted) (list (cons "" emitted)) emitted))
  (for/list ([tu (in-list tus)])
    (match-define (cons suffix contents) tu)
    (define path
      (fullpath (format "build/~a~a.cpp" hash-name
                        (if (string=? suffix "") "" (string-append "." suffix)))))
    (call-with-atomic-output path (lambda () (display contents)))
    path))

;; Build (or reuse) the delta-entry flavor of one stratum job
;; (docs/incremental.md §0.5 mode 3, 0.B5), returning its .so path.
;; Compiled LAZILY -- the session driver calls this on the first increment
;; that targets the stratum's inputs ("delta-entry when compiled,
;; replay-entry until then") -- and cached as build/<hash>_delta.O0.so.
;; -O0 only for now: an increment's latency is dominated by the fixpoint,
;; and the artifact caches; the tiered/-O2 plumbing can adopt the flavor
;; later if profiles ask.
(define (ensure-delta-so job)
  (match-define (list proghash _te _st _dm _dc) job)
  (define so (fullpath (format "build/~a_delta.O0.so" proghash)))
  (unless (file-exists? so)
    (define cpps (parameterize ([delta-entry-flavor #t])
                   (emit-stratum-cpp job)))
    (build-so cpps so #:opt "-O0"))
  so)

;; -----------------------------------------------------------------------
;; Tiered compilation entry point (docs/fast-compile.md).
;;
;; Returns the program's strata in pipeline order as `sbuild` records the driver
;; (runslog.rkt) consumes.  Building is scheduled here so it overlaps the run:
;;
;;   runnable -- a thunk that BLOCKS until a runnable .so exists and returns
;;               (cons so-path tag), tag in {o0, o2}.  Eager builds are already
;;               in flight on the pool when this returns, so forcing stratum k
;;               in order still lets k+1.. build behind it.
;;   o2-path  -- build/<hash>.so, the hot-swap upgrade target the driver polls
;;               for (via file-exists?), or #f when no upgrade will appear.
;;
;; SLOG_OPT selects the regime:
;;   tiered (default) -- run the eager -O0 build now; a detached -O2 build fills
;;                       build/<hash>.so in the background and the driver
;;                       hot-swaps to it mid-run when ready (and it is cached for
;;                       next time regardless).
;;   0                -- -O0 only (fast compiles, no upgrade); the test suite.
;;   2                -- block for -O2 and run only that; benchmarks / today's
;;                       behavior.  A previously-built build/<hash>.so is always
;;                       preferred in every mode (a re-run is pure -O2).

(struct sbuild (hash o2-path runnable upgrade delta))
;; `delta` -- a thunk returning the delta-entry flavor's .so path, building
;; it on first call (ensure-delta-so; docs/incremental.md 0.B5).  The
;; session driver forces it only when the routing rule picks delta-entry.

;; Granular O0->O2 upgrade (docs/fast-compile.md §14): given this stratum's TU
;; .cpp paths, return a closure the driver calls at each fixpoint boundary.  It
;; relinks the best-available mix -- each cluster's -O2 .o if the background has
;; produced it, else its -O0 .o -- into a fresh .so, but ONLY when more clusters
;; are now -O2 than the one currently loaded.  Any mix is correct (the .o's are
;; semantically identical); when all are -O2 the mix is the full -O2 build.  The
;; per-TU .o paths are content-addressed and fixed, so they are computed once;
;; each boundary is then just file-exists? checks + (on progress) one cheap link.
;; Returns (list mix-so-or-#f n-o2 total).
(define (make-upgrade proghash cpps)
  (define pairs
    (for/list ([cpp (in-list cpps)])
      (cons (o-cache-path cpp "-O0") (o-cache-path cpp "-O2"))))
  (define total (length pairs))
  (lambda (loaded-o2)
    (define bests
      (for/list ([p (in-list pairs)])
        (if (file-exists? (cdr p)) (cons (cdr p) #t) (cons (car p) #f))))
    (define n-o2 (for/sum ([b (in-list bests)] #:when (cdr b)) 1))
    (cond
      [(> n-o2 loaded-o2)
       ;; a distinct path per relink: dlopen will not reload an already-loaded
       ;; path, and n-o2 strictly increases across relinks
       (define mix (fullpath (format "build/~a.mix~a.so" proghash n-o2)))
       (define-values (ok? _log) (link-os (map car bests) mix "-O0"))
       (list (and ok? mix) n-o2 total)]
      [else (list #f loaded-o2 total)])))

;; -----------------------------------------------------------------------
;; Whole-program IDB/EDB partition (docs/db-compression.md §6, P0.4).
;;
;; Computed from the typed strata: a rule whose body reads at least one
;; DECLARED relation derives its head relations (IDB); a rule that reads none
;; produces iteration-0 / ground content -- literal facts, or values computed
;; from constants and primitives -- so its heads are EDB/base.  Relations of
;; the linked input manifest are EDB too (provided on load, never re-derived).
;; A relation grounded by facts AND extended by a real rule is `mixed`: it
;; lands in BOTH sets (its facts live in the iteration-0 EDB root, its derived
;; extension in the IDB layer; §6).  `strata-range` is (lo . hi) over the
;; actual stratum levels present.
;;
;; `derives?` intersects a rule's body relations with the set of declared
;; relations, so struct constructors and collection/arithmetic primitives in a
;; fact body (e.g. `(r (cons 1 nil))`, `(canon {1 2 3})`) -- which clause-rel
;; reports by operator name but which are NOT relations -- do not spuriously
;; make a ground fact look derived.
;; `productive-rels` (docs/db-compression.md §4.4, simplified): IDB relations
;; that are READ by some rule -- i.e. a fact of theirs immediately participates
;; in deducing new facts.  The sampler weights these more highly for retention
;; (a better replay seed) than terminal relations that nothing reads.  A simple
;; static signal, not a strict firing order.
;; `pinned-rels` (docs/smt.md §15): oracle-fed relations -- the extern answer
;; tables plus the smt_bad_formula error structs -- written by NO rule (a
;; daemon-side oracle produces their rows mid-run), so a compressed save must
;; store them VERBATIM and unsampled: replay cannot re-derive them, and
;; re-ingesting them is what keeps the oracle from being re-queried (the
;; dispatch task treats loaded answers as already-answered demands).
(struct db-partition (idb-rels edb-rels mixed-rels strata-range productive-rels
                      pinned-rels)
  #:transparent)

;; Ground (EDB) rules, TWO levels (docs/db-compression.md P0.5; the
;; staging-replay bug, 2026-07-10).  Strict facts read no declared
;; relation; a ground struct tree's rule ALSO reads the enum-constant
;; table (its (tint)/(mt) leaves desugar to _enum joins), which used to
;; misclassify it as derived -- so its rows were sampled, and re-deriving
;; them through head-const staging's pruned delta variants is unsound
;; under partial seeds.  Ground = strict facts plus rules whose only
;; declared-relation reads are CONSTANT-CLASS relations: those headed
;; exclusively by strict facts (in practice _enum).  Two levels suffice:
;; a source-bodiless rule can only acquire constant-class reads.  Ground
;; rows are origin data (they are literally program text) -- storing them
;; whole is both sound and smaller than replaying them.
(define (ground-fact-rules rules rel-names)
  (define (body-reads rule) (set-intersect (rule-body-rels rule) rel-names))
  ;; a rule with a NEGATED read is never ground (§0.8): pulling it into the
  ;; level-0 facts stratum would race its absent probe (a once task at
  ;; iteration 0) against the facts' own iteration-0 writes -- positive
  ;; constant-class reads are safe there (monotone: delta-driven versions
  ;; catch rows landing later in the fixpoint), a negative read is not.
  ;; Its heads are genuinely derived content: IDB, regenerated by replay.
  (define (negation-free? rule) (set-empty? (rule-body-neg-rels rule)))
  (define strict
    (for/set ([r (in-set rules)] #:when (set-empty? (body-reads r))) r))
  (define strict-heads
    (for/fold ([acc (set)]) ([r (in-set strict)])
      (set-union acc (rule-head-rels r))))
  (define tainted    ; anything a non-strict rule heads is not constant-class
    (for/fold ([acc (set)]) ([r (in-set rules)]
                             #:when (not (set-member? strict r)))
      (set-union acc (rule-head-rels r))))
  (define constant-rels (set-subtract strict-heads tainted))
  (for/set ([r (in-set rules)]
            #:when (and (negation-free? r)
                        (subset? (body-reads r) constant-rels)))
    r))

(define (jobs->db-partition jobs)
  (define rel-names
    (for/fold ([acc (set)]) ([job (in-list jobs)])
      (set-union acc (list->set (hash-keys (type-env-rels (second job)))))))
  (define input-rels
    (for/fold ([acc (set)]) ([job (in-list jobs)])
      (set-union acc (list->set (hash-keys (fourth job))))))
  (define all-rules
    (for/fold ([acc (set)]) ([job (in-list jobs)])
      (set-union acc (stratum-rules (third job)))))
  (define ground (ground-fact-rules all-rules rel-names))
  (define (derives? rule) (not (set-member? ground rule)))
  ;; relations read by some rule (appear in a body) -- productive-seed candidates
  (define read-rels
    (for/fold ([acc (set)]) ([job (in-list jobs)])
      (for/fold ([acc acc]) ([rule (in-set (stratum-rules (third job)))])
        (set-union acc (rule-body-rels rule)))))
  (define-values (idb0 edb-fact levels)
    (for/fold ([idb (set)] [edb (set)] [lvls (set)]) ([job (in-list jobs)])
      (define st (third job))
      (for/fold ([idb idb] [edb edb] [lvls (set-add lvls (stratum-level st))])
                ([rule (in-set (stratum-rules st))])
        (if (derives? rule)
            (values (set-union idb (rule-head-rels rule)) edb lvls)
            (values idb (set-union edb (rule-head-rels rule)) lvls)))))
  ;; a decomposition target (R_has/R_at) heads no rule but is derived data by
  ;; construction (grown from its base by the merge tasks): IDB.  The
  ;; sequence-occurrence relations are the same class (grown from their fed
  ;; bases by SeqIndexTask, re-derivable from any state).
  (define idb
    (for*/fold ([acc (for/fold ([acc idb0]) ([occ (in-list '($seq_at $seq_atr))])
                       (if (set-member? rel-names occ) (set-add acc occ) acc))])
                ([job (in-list jobs)]
                 [(derived info) (in-hash (fifth job))])
      (set-add acc derived)))
  (define edb (set-union edb-fact input-rels))
  (define lvl-list (sort (set->list levels) <))
  (when (getenv "SLOG_DEBUG_PARTITION")
    (eprintf "  [partition] declared-rels: ~a\n" (sort (set->list rel-names) symbol<?))
    (for ([job (in-list jobs)])
      (for ([rule (in-set (stratum-rules (third job)))])
        (eprintf "    L~a ~a  head=~a body=~a bodyrels=~a\n"
                 (stratum-level (third job))
                 (if (derives? rule) 'IDB 'EDB)
                 (sort (set->list (rule-head-rels rule)) symbol<?)
                 (sort (set->list (rule-body-rels rule)) symbol<?)
                 (sort (set->list (set-intersect (rule-body-rels rule) rel-names)) symbol<?)))))
  ;; oracle-fed relations (see the struct comment): the extern answer tables
  ;; from the (oracle ...) rel-env entries, plus the smt_bad_formula arm when
  ;; any oracle exists (its rows come from the dispatcher's side channel)
  (define oracle-pinned
    (for*/fold ([acc (set)])
               ([job (in-list jobs)]
                [(k decl) (in-hash (type-env-rels (second job)))])
      (if (and (pair? decl) (eq? 'oracle (car decl)))
          (set-add acc (fourth decl))
          acc)))
  (define pinned
    (if (set-empty? oracle-pinned)
        '()
        (sort (set->list (set-add oracle-pinned 'smt_bad_formula)) symbol<?)))
  (db-partition (sort (set->list idb) symbol<?)
                (sort (set->list edb) symbol<?)
                (sort (set->list (set-intersect idb edb)) symbol<?)
                (if (null? lvl-list) '(0 . 0) (cons (first lvl-list) (last lvl-list)))
                (sort (set->list (set-intersect idb read-rels)) symbol<?)
                pinned))

(define (opt-mode) (or (getenv "SLOG_OPT") "tiered"))

;; Returns (values strata partition edb-boundary).  edb-boundary is the number
;; of leading strata whose combined output is the iteration-0 EDB root (P0.5):
;; 1 when the first program contributed a facts stratum, else 0.  The driver
;; drives that many strata, snapshots the root, then drives the rest.
(define (compile-strata path dbmanifest #:split-facts? [split-facts? #f])
  (define mode (opt-mode))
  ;; tiered = the default regime (anything but the explicit -O0-only / -O2-only
  ;; knobs); mirrors runslog.rkt's driver-side test.
  (define tiered? (not (member mode '("0" "2"))))
  (define per-program
    (for/list ([prog (in-list (load-program-list path dbmanifest))])
      (program->jobs prog #:split-facts? split-facts?)))
  (define jobs (append-map first per-program))
  (define edb-boundary
    (if (and split-facts? (pair? per-program) (second (first per-program))) 1 0))
  ;; Render each program's peeled ground rules (freeze.rkt) as a static
  ;; database under build/frozen/<hash>/ -- content-addressed, so a repeat
  ;; compile reuses it; the stream itself sits alongside for debugging.
  ;; The driver imports these before stratum 0.
  (define frozen-dirs
    (for/list ([fz (in-list (filter-map third per-program))])
      (match-define (cons h stream) fz)
      (define dir (format "build/frozen/~a" h))
      (unless (directory-exists? (fullpath dir))
        (make-directory* (fullpath "build/frozen"))
        (call-with-output-file (fullpath (string-append dir ".facts"))
          #:exists 'replace
          (lambda (o) (display stream o)))
        (run-freezer (fullpath dir) stream)
        (printf "(frozen ~a)\n" dir))
      dir))
  (define partition (jobs->db-partition jobs))
  ;; background -O2 build commands (tiered mode), launched as ONE bounded batch
  ;; after all strata are planned so concurrency is capped (docs/fast-compile.md §7)
  (define o2-cmds '())
  (define strata
    (for/list ([job (in-list jobs)])
      (match-define (list proghash _te stratum _dm _dc) job)
      (write-stratum-manifest proghash stratum _te _dc)  ; sidecar, even for a cached .so
      (define o2so (fullpath (format "build/~a.so" proghash)))
      (define o0so (fullpath (format "build/~a.O0.so" proghash)))
      (cond
        ;; Optimized artifact already cached: always the best thing to run.
        [(file-exists? o2so)
         (clear-o2-marker! o2so)   ; any leftover in-flight marker is moot now
         (sbuild proghash o2so (lambda () (cons o2so 'o2)) #f
                 (lambda () (ensure-delta-so job)))]
        ;; -O0-only mode with a warm -O0 artifact: reuse it, no upgrade.
        [(and (equal? mode "0") (file-exists? o0so))
         (sbuild proghash #f (lambda () (cons o0so 'o0)) #f
                 (lambda () (ensure-delta-so job)))]
        ;; TIERED with a warm -O0 artifact but no -O2 yet (e.g. a prior run
        ;; exited before the background -O2 landed): run the cached -O0 NOW --
        ;; no re-emit, no -O0 rebuild -- and queue the background -O2 only if we
        ;; can claim it (docs/fast-compile.md §13).  The .cpp TUs persist in
        ;; build/, so the O2 command reads them back; fall back to a fresh emit
        ;; only if they were removed.
        [(and tiered? (file-exists? o0so))
         (define cpps0 (stratum-tu-paths proghash))
         (define cpps (if (null? cpps0) (emit-stratum-cpp job) cpps0))
         (when (try-claim-o2! o2so)
           (set! o2-cmds (cons (o2-build-command cpps o2so) o2-cmds)))
         (sbuild proghash o2so (lambda () (cons o0so 'o0)) (make-upgrade proghash cpps)
                 (lambda () (ensure-delta-so job)))]
        [else
         (define cpps (emit-stratum-cpp job))   ; write .cpp(s) now (fast, main thread)
         (case mode
           [("2")
            (sbuild proghash o2so
                    (pooled-eager (lambda () (build-so cpps o2so #:opt "-O2") (cons o2so 'o2)))
                    #f (lambda () (ensure-delta-so job)))]
           [("0")
            (sbuild proghash #f
                    (pooled-eager (lambda () (build-so cpps o0so #:opt "-O0") (cons o0so 'o0)))
                    #f (lambda () (ensure-delta-so job)))]
           [else ; tiered: eager -O0 to run now, then upgrade cluster-by-cluster to
                 ;; -O2 as the background fills the .o cache (docs/fast-compile.md §14)
            ;; claim-gate the -O2 so concurrent/successive runs that all miss the
            ;; -O2 don't each spawn one (docs/fast-compile.md §13)
            (when (try-claim-o2! o2so)
              (set! o2-cmds (cons (o2-build-command cpps o2so) o2-cmds)))
            (sbuild proghash o2so
                    (pooled-eager (lambda () (build-so cpps o0so #:opt "-O0") (cons o0so 'o0)))
                    (make-upgrade proghash cpps)
                    (lambda () (ensure-delta-so job)))])])))
  (spawn-detached-o2-batch (reverse o2-cmds))
  (values strata partition edb-boundary frozen-dirs))
