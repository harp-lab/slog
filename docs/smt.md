# SMT formulas and external oracles

Status: **Phase 2c implemented** (2026-07-08): formula sets, logic inference,
persistent solver processes, racing, models, error facts, unsat cores, and
compressed-database pinning all shipped after the initial oracle integration.
Sections 1–11 preserve the original design. Sections 12–15 record the shipped
stages and their deviations.

## 1. Motivation

Static analyses in Slog (tinycfa, schemecfa, kcfa) compute reachability; the
next step is computing *path conditions* — first-class formulas that
over-approximate the constraints along paths to a program point — and asking a
solver whether the error paths are satisfiable. An `unsat` answer proves the
dynamic check on that path can never fire, so it can be lifted to a static
guarantee. This requires:

1. building formulas as ordinary first-class Slog values,
2. a relation-shaped query interface returning `sat`/`unsat`/`unknown`,
3. daemon-side solver plumbing over SMT-LIB 2 so we can target z3, cvc5, etc.,
   with timeout-driven fallback between solvers,
4. a shape general enough to host *other* external oracles later (ILP, string
   solvers, MaxSAT, CAS) without redesign.

## 2. Design thesis: three existing substrates already fit

Almost everything needed exists; the genuinely new mechanism is small.

**Formulas are declared struct unions.** Interned structs are hash-consed
DAGs of s-expressions, and SMT-LIB *is* s-expressions — serialization is close
to an identity walk plus a rename map and sort declarations. The vocabulary is
ordinary `struct`/`union` declarations in a `lib/smt.slog`; no parser or
type-system changes are needed to *represent* formulas. Interning gives
canonical formula identity for free, which is the memoization key.

**The query interface is a demand relation whose answer rules are external.**
`demand (f in...) out...` already desugars to a demand `struct` ("asking is
constructing") plus a `f_ans` table (compiler/demand.rkt), with body-position,
value-position, and head-position call forms. An oracle is exactly a demand
relation where no Slog rules derive `f_ans` — a daemon component writes those
rows instead. At runtime there is nothing special about `f_ans` (ordinary
table written through `emit`/`InternTask`), so the oracle injects answers
through the same `sendBatch → finalize → intern` path any rule uses.

**Scheduling rides the iteration/pausing machinery.** Solver calls are slow
(ms–seconds) and must never run inside a join. Dispatch and harvest are
ordinary per-stratum tasks; the only fixpoint change is "delta empty AND no
oracle queries in flight." The shipped pausing substrate (RunBudget, boundary
suspend, checkpoint-on-pause) composes: because demands and answers are plain
facts and the solver cache persists, pausing or killing mid-flight loses
nothing — unanswered demands simply re-dispatch on resume against the memo.

## 3. Surface language

### 3.1 Vocabulary (`lib/smt.slog`)

Typed unions per sort, ordinary declarations:

```
;; integer terms
union (iexpr (iv str)          ; integer variable, named by string
             (ic int)          ; integer constant
             (l+ iexpr iexpr) (l- iexpr iexpr) (l* iexpr iexpr)
             (lite formula iexpr iexpr))

;; formulas (booleans)
union (formula (bv str)                       ; boolean variable
               (ltrue) (lfalse)
               (l< iexpr iexpr) (l<= iexpr iexpr) (l= iexpr iexpr)
               (land formula formula) (lor formula formula)
               (lnot formula) (limplies formula formula))

enum (verdict sat unsat unknown)

extern (smt_check formula) verdict "smt"      ; see 3.2
```

Notes:
- Union arms must be constructors, so literals get wrappers (`(ic 5)`).
  (Alternative considered: allow base types as union arms — a bigger
  type-system change, not worth coupling to this feature.)
- Explicit sorts via distinct variable constructors (`iv`/`bv`, later `rv`,
  `bvv w`); no sort inference in v1. The printer mangles names per sort so
  `(iv "x")` and `(bv "x")` can't collide.
- Homogeneous arithmetic only, mirroring the prims discipline (no Int/Real
  mixing in v1; reals arrive as a parallel `rexpr` union).
- Negative integer literals don't parse in Slog; computed negatives are fine
  and the printer emits SMT-LIB `(- 5)` form.
- Real/BV/array theories are later additions: new unions + printer table
  entries, nothing structural.

### 3.2 Declaring an oracle-backed relation: `extern`

New top-level form, deliberately parallel to `demand`:

```
extern (smt_check formula) verdict "smt"
```

Desugars exactly like `demand (smt_check formula) verdict` — the
`smt_check` demand struct plus `table (smt_check_ans smt_check verdict)` —
except (a) the compiler requires that *no* rule heads target `smt_check_ans`
(the oracle owns it), and (b) codegen registers the binding in each stratum
that writes the demand relation:

```c++
s->addOracle("smt", rel_smt_check, rel_smt_check_ans);
```

All existing demand ergonomics come along for free: body calls, value-position
calls `(= v (smt_check f))`, `_ans` as the enumeration escape hatch, in-SCC
use. `extern` joins `top-level-keywords` (compiler/parser.rkt:300) with an
`extract-type-env` arm alongside the `demand` arm (compiler/modules.rkt:427).

(Alternative considered: `demand (smt_check formula) verdict #:extern "smt"`.
Rejected — an oracle relation has a materially different contract (no user
answer rules, external effects, persistence classification) and deserves a
searchable keyword.)

### 3.3 Idioms

The motivating pattern, using value-position call syntax:

```
;; error path at site S has over-approximate path condition F
rule (error-path S F) (= (unsat) (smt_check F)) --> (check-elidable S)
```

The soundness discipline is structural: you *match* on `sat` or `unsat`;
`unknown` (or an unanswered demand) simply fails to match, so absence of proof
defaults to keeping the dynamic check. No rule should need to match `unknown`.

**Path conditions as csets (recommended idiom + printer support).** Building
conjunctions as nested `land` spines makes semantically-equal path conditions
syntactically distinct (accumulation order), defeating memoization and
inflating the formula heap. Instead accumulate path conditions as csets of
atomic formulas — canonical, order-insensitive, deduped, and extension is
`cins` — and let the printer accept a cset in formula position as an n-ary
conjunction:

```
extern (smt_check_all cset) verdict "smt"   ; cset of formula ⇒ conjunction
rule (edge P Q G) (pathc P S) (= S2 (cins S G)) --> (pathc Q S2)
rule (fails-at Q S) (= (unsat) (smt_check_all S)) --> (safe Q)
```

One canonical query per semantic path condition, regardless of how the
analysis reached it. (Typing: `cset` element type is untyped today; the
printer validates members are formulas and reports bad ones as error facts,
§4.3. A `(set formula)` refinement can ride the parametric-types plan.)

## 4. Semantics

### 4.1 Verdicts and monotonicity

`verdict = sat | unsat | unknown`. `unknown` covers solver timeout, solver
"unknown", and crash-after-retries. Within a run, the oracle is a memoized
function: each demand gets exactly one answer row, ever, and the answer set
grows monotonically — the same contract as a demand relation's answers, so
in-SCC (recursive) calls are sound and permitted (enabling CEGAR-style loops
where answers spawn new formulas). Whatever verdict is first recorded is the
verdict for that run; there is no in-run upgrading of `unknown`.

(Future option, not v1: verdicts as a lattice with `unknown ⊑ sat`,
`unknown ⊑ unsat`. The monotone-use calculus would then *permit* matching
`sat`/`unsat` (upward-closed) and *reject* matching `unknown` — mechanically
enforcing the soundness discipline — and background solver escalation could
refine `unknown` via the lattice-change machinery. Elegant, but v1 keeps
plain enum verdicts.)

### 4.2 Determinism

Solvers are nondeterministic across runs (timeouts, versions, seeds). The
determinism guarantee is *recording*, not reproducibility of the solver:

- **Within a run**: memoization by interned demand id; one query per formula.
- **Verbatim save/load**: `_ans` rows persist like all facts; no re-query.
- **Compression/replay**: oracle answers are classified as **inputs discovered
  during evaluation** — see §7. Replay reuses recorded answers and never
  re-queries (except under an explicit `--refresh-oracle`).
- **Cross-DB/cross-run cache** (optional layer): keyed by canonical SMT-LIB
  text hash (content-addressed — struct ids are not stable across DBs).
  `sat`/`unsat` cache forever (theory truths); `unknown` caches with a policy
  fingerprint (solver chain + timeouts) and is re-solvable when the policy
  strengthens.

### 4.3 Errors

A formula that fails to serialize (non-formula cset member, ill-sorted term
that slipped past typing via `any`, unsupported construct for the configured
logic) is not `unknown` — it is a program error, surfaced through the existing
error-facts machinery as a new reserved `error_spec` arm:

```
(error (smt_bad_formula "reason" f))
```

so users can react in-language (`rule (error (smt_bad_formula R F)) --> ...`),
matching the fallible-prims pattern.

## 5. Runtime architecture (daemon)

New components: `daemon/oracle.h` (registry + queues + worker threads,
oracle-agnostic), `daemon/smtlib.h` (value → SMT-LIB printer),
`daemon/smt-oracle.h` (solver chain over subprocesses). The daemon currently
has no subprocess or thread machinery — this is all new, and stays contained
in the oracle component (the OpenMP stratum team is untouched).

### 5.1 Oracle interface (the generalization)

```c++
struct OracleRequest { u64 demand_id; /* interned struct root */ };
struct OracleAnswer  { u64 demand_id; value answer; };

class Oracle {
public:
  // Called from oracle worker threads; must be thread-safe.
  // Reads the formula DAG via a read-only Database view.
  virtual OracleAnswer solve(const Database&, OracleRequest) = 0;
  virtual ~Oracle() = default;
};

class OracleRegistry {  // owned by Daemon
  void registerOracle(std::string name, std::unique_ptr<Oracle>);
  OracleBinding* bind(std::string name, Relation* demand, Relation* ans);
  // dispatch queue, completion queue, in-flight count, memo, worker pool
};
```

An oracle is any pure(ish), memoizable function from interned value to value.
SMT is the first instance; the registry/dispatch/harvest/fixpoint plumbing is
shared by all future ones. Built-in oracles register in the Daemon ctor;
`.so`-provided oracles can register through the existing plugin protocol
later (`slog_plugin` receives the Daemon, which exposes `registerOracle`).

Thread-safety note: worker threads read the struct arena / relation indices
while the stratum team runs. Reads target only *interned, reorged* data
(demand ids are assigned in phase_intern before dispatch, §5.2), which is
append-only from the reader's perspective; the printer additionally snapshots
the formula into an owned buffer at dispatch time to be safe against
reorg/compaction, making the worker fully decoupled.

### 5.2 Dispatch and harvest tasks

For each stratum writing an extern relation, codegen registers two tasks:

- **`OracleDispatchTask`** in `every[phase_write]`: scans the demand
  relation's delta (already deduped and id-assigned by its `InternStructTask`
  in the *previous* iteration's intern phase, then reorged — so ids are
  final). For each new demand: memo hit → push the recorded answer straight to
  the completion queue; miss → snapshot the formula, enqueue to the worker
  pool, bump `in_flight`.
- **`OracleHarvestTask`** in `every[phase_read]`: drains the completion queue
  and `emit()`s `(f_ans d v)` rows into `send_shards` — exactly like a rule
  emitting — which dedup through the ordinary `InternTask` and become next
  iteration's delta, waking any joins waiting on answers.

Both are cheap, non-blocking, slice-friendly tasks; solving overlaps with rule
evaluation on subsequent iterations.

On stratum reload (`beginStratum` re-dumps master indices into delta), every
demand reappears in delta; the memo (seeded from existing `_ans` rows at
bind time) turns these into immediate completions, so reload does not re-solve.

### 5.3 Fixpoint condition and waiting

`EndIterCompletion` (database.h:3037) gains one clause:

- `!latest_any_rec && in_flight == 0` → `ACT_FIXPOINT` (unchanged otherwise).
- `!latest_any_rec && in_flight > 0` → **oracle wait**: one designated thread
  blocks on the completion queue with a timeout (condition variable), then
  `ACT_CONTINUE` — the next iteration's harvest emits whatever completed.
  Empty-delta iterations are cheap (barriers only), and we only spin when
  something actually completed or the wait timed out against the budget.
- Budget interaction: waiting counts against `RunBudget` wall-clock. If the
  budget expires mid-wait, boundary-suspend as usual and report in-flight
  count in the status: `(paused <name> <iters> <ms> (oracle-inflight N))`.
  In-flight queries keep running (or are killed and become re-dispatchable —
  see open question Q4); correctness is unaffected either way because
  unanswered demands re-dispatch and the memo absorbs duplicates.

### 5.4 The SMT oracle: solver chain

Configured chain, e.g. `z3:500,cvc5:2000` (name:timeout_ms). Per solver, a
pool of persistent subprocess workers (`z3 -in`, `cvc5 --incremental
--lang smt2`) speaking SMT-LIB 2 over pipes; per query: `(reset)`,
`(set-logic ...)` if configured, print declarations + definitions + assert,
`(check-sat)`, read verdict. Wall-clock timeout enforced by poll + kill +
respawn (solvers' own `:timeout` set as a hint where supported). Chain
semantics: first solver's `sat`/`unsat` wins; timeout/unknown/crash falls
through to the next; chain exhausted → `unknown`. Deterministic seeds set
where supported (`smt.random_seed` etc.) — a mitigation, not a guarantee
(§4.2 is the guarantee).

Solver subprocesses live inside the slogd systemd scope, so `SLOG_MEM_MAX`
covers them; per-solver memory limits (`z3 -memory:`) also configurable.

A built-in `mock` solver (in-process, no subprocess) decides ground/linear
integer conjunction fragments deterministically — enough for golden tests
without z3 installed, and for CI.

## 6. The printer (`daemon/smtlib.h`)

- **DAG-aware, linear-size output.** Interned formulas are DAGs; naive tree
  printing is exponential on shared subterms (`(land x x)` towers). Emit each
  distinct non-leaf subterm once as `(define-fun t<id> () <Sort> ...)` in
  dependency order, then assert the root's name. Named by struct id; output is
  machine-consumed, readability is secondary.
- **Name table**: struct tag → SMT-LIB symbol (`land`→`and`, `l<`→`<`,
  `lite`→`ite`, ...), populated for the lib vocabulary. Unknown struct tags
  are an error (→ `smt_bad_formula`), *not* pass-through, in v1 — pass-through
  is a one-line policy flip later if we want user-extensible theories without
  daemon edits.
- **Variables**: collect free `iv`/`bv`/... leaves → `declare-const`, names
  mangled per sort (`x` → `i_x`, `b_x`) to prevent cross-sort collisions.
  Slog string ids resolve through the string interner.
- **Csets in formula position** flatten to `(and ...)` of members (§3.3);
  cset walking reuses the arena iteration kernels.
- **Constants**: `(ic n)` prints negatives as `(- n)`; string escaping per
  SMT-LIB when the string theory arrives.

## 7. Persistence, replay, and compression contract

This is the subtlest cross-cutting piece, given db-compression just shipped.

**Principle: oracle answers are inputs discovered during evaluation.** They
are facts the rules cannot re-derive (the deriving agent is an external,
nondeterministic solver), so for every persistence mechanism they must be
treated like EDB, not IDB:

- **Verbatim save/load** (`writeDatabaseBIN`): already persists everything;
  nothing to do. Reload seeds the memo from `_ans` rows.
- **Compressed DBs / replay**: the compression writer must include extern
  `_ans` rows (and, transitively, the demand structs they reference — the
  struct-heap trimmer's reachability already handles referenced structs) in
  the preserved input set: pinned into the EDB root at compress time, or
  appended to the edits chain for answers acquired after the root was cut,
  whichever the forward-incremental machinery finds natural. Replay then
  ingests them as given facts; the dispatch memo sees every demand already
  answered and issues zero solver calls. Signature/drift checking stays sound
  because replay is now deterministic again.
  `--refresh-oracle` (dbtool flag) deliberately drops recorded answers to
  re-solve — accepting drift, e.g. after a solver upgrade.
- **DRed^c / incrementality**: answer rows count as base facts (like EDB) —
  deleting an input fact can delete *demands* transitively, and a deleted
  demand's answer row is removed with it (its count derivation is exactly the
  demand's); the memo/side cache may retain the verdict for re-use if the
  demand reappears.
- **Checkpoint-on-pause**: answers checkpoint like everything else; in-flight
  queries are represented by unanswered demand facts and re-dispatch on
  resume (§5.2–5.3). Nothing about oracle state needs serializing.

## 8. Configuration

Via the dogfooded config program → env vars, per the established pattern
(compiler/config.rkt `setting->env`):

```
rule (setting_str "smt_solvers" "z3:500,cvc5:2000")   → SLOG_SMT_SOLVERS
rule (setting_int "smt_procs" 4)                      → SLOG_SMT_PROCS
rule (setting_str "smt_logic" "QF_LIA")               → SLOG_SMT_LOGIC (opt)
```

Daemon ctor reads them like the budget fields. `SLOG_SMT_SOLVERS=mock` for
tests. The policy fingerprint (§4.2) is the hash of these settings.

## 9. Testing

- **Unit battery**: printer (DAG sharing, sorts, mangling, negatives, csets,
  bad-formula errors), memo behavior, chain fallback with a scripted flaky
  solver, in-flight fixpoint condition.
- **Golden tests** `smt_*` under `SLOG_SMT_SOLVERS=mock`: value-position and
  body-position calls, in-SCC calls, cset conjunction, unknown-defaults-safe,
  error facts, pause/resume mid-flight, reload, replay-uses-recorded-answers
  (compression round-trip with the mock solver *disabled* on replay to prove
  no re-query happens).
- **Gated real-solver tests** (skip if no z3 on PATH): a handful of
  end-to-end checks incl. a genuine timeout→fallback→unknown path.
- **Demo example** `examples/verify/`: small imperative language with bounds
  checks; path conditions as csets; report elidable checks. This is the
  motivating artifact and the documentation centerpiece.

## 10. Milestones

- **M0 — printer + pool, standalone.** `smtlib.h`, `oracle.h` skeleton,
  `smt-oracle.h` with mock + z3 backends; unit tests only. No compiler work.
- **M1 — end-to-end, one oracle.** `extern` parse/desugar (reusing demand
  machinery), codegen registration, dispatch/harvest tasks, fixpoint
  in-flight clause, in-memory memo seeded from `_ans`. Golden `smt_*` tests
  with mock. In-SCC calls included (falls out of demand machinery).
- **M2 — persistence contract.** `_ans`-as-EDB in the compression writer,
  replay-without-requery test, `--refresh-oracle`, DRed^c base-fact
  classification noted in docs/incremental.md.
- **M3 — production solving.** Config chain, timeouts/fallback/respawn,
  `smt_bad_formula` error arm, cset conjunctions, gated z3/cvc5 tests.
- **M4 — demo + docs.** `examples/verify/`, user-facing docs section.
- **Later**: models as cmaps (`extern (smt_model formula) cmap` — var→value
  maps flowing back as first-class collections), unsat cores as csets,
  lattice-refined verdicts with background escalation, incremental push/pop
  exploiting path-condition prefix sharing, quantifiers/strings/BV/arrays,
  `.so`-pluggable third-party oracles.

## 11. Open questions

- **Q1 surface**: `extern` keyword (proposed) vs `demand ... #:extern "smt"`.
- **Q2 waiting**: in-daemon blocking wait at empty-delta (proposed) vs
  park-at-boundary with a `(waiting smt N)` status and driver-side polling.
  Blocking keeps the protocol unchanged; parking is more honest about
  long waits. Proposed: block, but boundary-suspend when the budget expires.
- **Q3 unknown-cache policy**: exact fingerprint contents, and whether
  `unknown` answers persisted in a DB can ever be upgraded in a *later* run
  (proposal: only via `--refresh-oracle`, never silently).
- **Q4 in-flight on suspend**: keep solver workers running while parked
  (answers land in the completion queue for the next continue) vs kill and
  re-dispatch on resume. Keep-running is better utilization; kill is simpler
  lifecycle. Proposed: keep running, kill on daemon shutdown.
- **Q5 pass-through vocabulary**: v1 closed name table (proposed) vs generic
  `l`-prefix-strip pass-through allowing user theories without daemon edits.
- **Q6 model/values return shape**: reserve now? Proposal: no — `extern`
  relations are ordinary demand relations, so `smt_model` is just a second
  extern later; nothing to reserve.
- **Q7 where answers pin in compressed DBs**: EDB root vs edits chain for
  post-root answers — needs a look at the forward-incremental writer's
  natural seam.

## 12. Implementation status (Phase 1, shipped 2026-07-08)

**Surface.** `extern <oracle> (f in-type) int` (parser.rkt, modules.rkt) is a
demand declaration whose answers come from the named daemon-side oracle as
int code words (0 unknown | 1 sat | 2 unsat); v1 fixes one input column and
the int answer so the daemon side stays trivially generic.  All user-facing
polish is plain Slog in `lib/smt.slog`: the vocabulary unions, the verdict
enum, the `demand (smt_check formula) verdict` wrapper translating codes via
`smt_vcode` facts, and the post-hoc views `smt_sat`/`smt_unsat`/`smt_unknown`
(content-join escape hatch).  Oracle-owned relations are guarded: a rule
answering `smt_qsat` (full-arity head) or writing `smt_qsat_ans` is a
compile error naming the offending rule (`check-extern-rules`).

Constructor spellings: the tokenizer treats `+ - * < <= = ;` as operators, so
formula constructors are word-only -- `llt lle leq ladd lsub lmul` (following
cmp-prim-name's lt/le convention), plus `land lor lnot limplies ltrue lfalse
iv ic bv`.  Single `;` is NOT a comment (it is the infix sequence operator);
use `;;`.

**Binding plumbing.** The extern decl rides the rel env as a
`$oracle$<name> -> (oracle <oracle> <f> <f_ans>)` entry (so it lands in the
compile cache key for free); build-cprog appends an `(oracle ...)` decl to
any stratum whose rules write the demand struct, and emit-cpp renders it as
`d->bindOracle(s, ...)` after all relation registrations.  Critical detail:
the answer table grows through the harvest task's side channel, not a rule
head, so it is marked **dynamic** in those strata (compile.rkt +
operationalization.rkt), exactly like the malformed_deduction/error arms --
without this the planner stages rules reading it as closed and answers
arriving mid-fixpoint never join.

**Runtime.** `daemon/oracle.h` (generic: Oracle iface, OracleRegistry +
worker pool + per-binding answered set/completion queue,
OracleDispatchTask/OracleHarvestTask) and `daemon/smt.h` (the SMT oracle:
DAG-aware SMT-LIB 2 printer with one define-fun per shared compound node,
sort-mangled declare-consts, ground-evaluating mock backend, per-query
subprocess chain with wall-clock kill + fallthrough).  Both dispatch and
harvest run in **phase_read** (not write as originally sketched): read-phase
indices are immutable, so decoding the formula DAG through lookup indices is
race-free; requests are serialized to self-contained strings at dispatch, so
pool threads never touch the Database.  Fixpoint integration (database.h):
ExternalWork + a snapshot flag in RunState; EndIterCompletion refuses
ACT_FIXPOINT while answers are outstanding and blocks (budget-bounded) for
the next completion; an empty-delta iteration with work in flight still
reorgs (clearing bucket views) so the continued iteration reads no dangling
refs.  Budget expiry mid-wait boundary-suspends as usual -- demands are
facts and re-dispatch is idempotent, so resume is always safe.

**Config.** `SLOG_SMT_SOLVERS` ("z3:500,cvc5:2000" | "mock", default mock)
and `SLOG_ORACLE_PROCS` (pool size, default 4), mapped from the config
program via `smt_solvers`/`oracle_procs` settings.  The golden runner pins
`SLOG_SMT_SOLVERS=mock`.

**Tests.** `tests/smt-tests.cpp` (26-check unit battery: printer, DAG
sharing, sorts/mangling, failures, mock evaluation, optional real-z3 solve +
chain fallthrough; standalone binary like arena-tests).  Goldens
`smt_basic`/`smt_rec` (in-SCC recursion through the oracle -- answers gate
the next formula, one demand per iteration)/`smt_multi` (cross-stratum
re-ask joins the persisted answer).  `tests/smt-solver-tests.sh`: the async
path under a scripted slow solver (asserts 5 asks -> exactly 4 solver calls:
per-formula single-solve) plus z3-gated end-to-end verdicts.

**Incidental fixes.** Relation's memoized master/lookup orderings survived
`clearAllIndices`, so a 0-leading join index requisitioned by an earlier
stratum could crash CSV/BIN export after a reload dropped it (latent
pre-oracle bug); the memos now clear with the registrations.  `getIndex` /
type-conflict errors now name the relation.

**v1 deviations / deferred** (the Phase-2 list): persistent solver
process pools (per-query spawn today); unserializable formulas answer
unknown + a once-per-reason stderr warning instead of an `(error
(smt_bad_formula ...))` arm; no cset-as-conjunction printing yet; verdicts
are plain enums (no lattice refinement); compression/replay EDB
classification of answer rows (M2) not yet wired -- verbatim save/load and
in-lineage reuse work today because answers are ordinary persisted facts;
Q3/Q4/Q7 remain open.

## 13. Phase 2a: extended vocabulary, cset conjunctions, the demo (2026-07-08)

**Vocabulary.** Added `lgt lge lne` (>, >=, distinct), `(lite c a b)` (ITE
on terms, per-position sorts), and the path-condition idiom `(lall S)` /
`(lany S)`: a formula arm holding a canonical cset of formulas, rendered as
an n-ary and/or with one define-fun per distinct node.  Empty sets are
vacuous (`(lall (cmap))` = true, `(lany (cmap))` = false); singletons inline;
maps and non-boolean members are render errors.  The mock backend evaluates
sets with sound short-circuiting: one ground-FALSE conjunct refutes the
conjunction (one ground-TRUE disjunct satisfies the disjunction) even beside
symbolic members.  Brace literals compose: `(lall {(llt ...) (lge ...)})`.
Canonicalization means two accumulation orders are ONE interned formula and
at most one solver query (tests/smt_sets.slog demonstrates it).

**Logic inference.** The printer tracks constness per node and emits
`QF_NIA` when two non-constant terms are multiplied, `QF_LIA` otherwise --
before this, a nonlinear query under the hardcoded QF_LIA logic was a
solver-side error read as unknown.

**Staging bugfix (pre-existing, planner).** join-planning.rkt's head
staging accounted for head CONSTRUCTIONS but not head COMPUTES (prim lets):
a construction consuming a prim result -- e.g. any brace literal nested in
a head field, `(out (lall {..}))` -- was staged before the cins chain that
computes its input, dropping the computes and failing planning ("head
variables never bound").  Fixed by treating compute outputs as fresh values
in `new-ids`/`residual-bound`; immediate compute outputs are carried by
value through the stage temp.

**The demo (examples/verify/).** The motivating analysis end to end: a
passive-form branching IR whose conditions ARE the formula vocabulary, a
forward path-condition analysis (csets extended by cins), per-check
error-path accumulation in a `(set any)` lattice column (all paths union
into ONE disjunction), and -- because the deciding rules read that column
from a later stratum -- a single `(smt_check (lany ES))` per check over the
final merged set: stratification does "wait for all paths", no negation
construct needed.  Checks: `elidable` on unsat, `kept` on sat/unknown.
Golden (mock): the ground `const-ok` check is proven and elided, `const-bad`
is sat/kept, the symbolic ones default to kept.  Under z3
(tests/smt-solver-tests.sh): `abs-nonneg` is PROVEN across both branches and
lifts to a static fact; `div-nonzero` stays dynamic.  Two idioms the demo
documents: derived formulas (negations, equations) must be materialized in a
HEAD before body rules can reference them (body-position constructions are
content lookups), and loops would havoc via fresh variable versions (out of
scope here).

## 14. Phase 2b: persistent pools, racing, models, error facts (2026-07-08)

**Persistent solver pools.** Each oracle pool thread owns one persistent
process per solver (thread_local in SmtOracle::solve, reaped at thread
exit): z3/cvc5 run incrementally with `(reset)` between queries and an
`(echo "@@slogdone@@")` marker bounding each response, so the spawn cost is
paid once per (thread, solver).  Anything else -- script solvers included --
stays one-shot (spawn per query, EOF-bounded), so scripted test backends
keep working unchanged.  A dead or timed-out process is killed and respawns
on next use; the wall clock remains the enforcement (solver-native timeout
flags dropped).

**Racing.** A chain entry may race members: `"z3|cvc5:500,z3:5000"` runs
both at 500ms, first COMPLETED definitive verdict wins (completion includes
the model values, which follow the verdict), losers still mid-solve are
killed for respawn; indefinite rounds fall through.  One poll loop serves
persistent and one-shot members uniformly.

**Models as cmaps.** Oracle answers generalized from int codes to
`OracleResult` = code | string->int map -- a RECIPE materialized by the
harvest task (read phase: string interning and arena puts are thread-safe
there), never by pool threads.  `extern` answer types now admit
`int | cmap | cset`.  The second registered instance `smtmodel` answers
maps: the request carries `(set-option :produce-models true)`, a
`(get-value ...)` after the check (harmless on unsat), and `; slogvar
<mangled> <original>` comment lines so the response parses back to ORIGINAL
variable names with no database access.  The raw map holds the verdict code
under "@status" plus one value per variable (booleans as 0/1);
lib/smt.slog's `smt_model` wrapper splits it:
`demand (smt_model formula) verdict cmap` -- full-arity idiom, e.g.
`(smt_model F V M) (= X (cget M "x"))`.  Caveat: model VALUES are
solver-chosen, so unlike verdicts they are only canonical per lineage
(force-determined models are stable; underconstrained ones are not).

**Error facts.** `smt_bad_formula` joined the reserved error_spec arms
(`(struct str any)`: reason + the offending formula value).  The dispatcher
now serializes FIRST under every backend (validation even in mock mode);
a failure records `(error (smt_bad_formula reason F))` through the standard
per-stratum wrap rule (wired for oracle strata like the fallible-prim arms)
and still answers the oracle's unknown shape.  Reaction rules should also
read something the producing stratum computes -- wrap rules are invisible
to stratification (a pre-existing property of the error machinery), so a
bare `(error ...)` reader can schedule too early (tests/smt_err.slog shows
the anchored pattern).

**Tests.** Unit battery at 69 checks (model parsing/rendering, persistent
multi-query reuse, racing, real z3 models).  Goldens smt_model (ground
models under mock) + smt_err (error facts + unknown).  Solver suite adds
the script-racing round (fast unsat beats slow sat) and z3 model extraction
flowing values back through cget.

**Still deferred**: compression/replay EDB pinning of answer rows (Q7; now
doubly relevant for models), unsat cores as csets (the OracleResult set
variant is ready for it; needs per-conjunct named assertions in the
printer), reals/BV/arrays/UF, lattice verdicts, quantifiers.

## 15. Phase 2c: unsat cores + compression pinning (2026-07-08)

**Unsat cores as csets.** The third registered oracle instance `smtcore`:
for a conjunction-set root `(lall S)` each member is asserted separately
under a name (`(assert (! m :named scK))`, `; slogcore scK <word>` comments
carrying the member's raw struct word), and on unsat `(get-unsat-core)`'s
blamed names map back to member WORDS -- OracleResult grew a
`word_entries` payload the harvest inserts verbatim as map keys.  Lib:
`demand (smt_core formula) verdict cset` -- on (unsat) the blamed SUBSET of
S as a first-class cset (empty otherwise; a non-lall root cores as
{root}).  The mock blames every ground-false conjunct (each alone refutes);
solver cores are sound, not guaranteed minimal, and solver-chosen like
models.  z3-gated test: {x<3, x>5, p} blames the arithmetic pair and
exonerates p.

**Compression/replay pinning (Q7 RESOLVED).** Principle implemented:
oracle rows are inputs discovered during evaluation.  `jobs->db-partition`
now computes `pinned-rels` (the extern answer tables from the (oracle ...)
entries + smt_bad_formula); the layer write includes them UNSAMPLED
(fracOf/fracFor 1.0 via a `pinned` set threaded through save-compressed /
writeDatabaseSampledBIN / markKeptStructs); their rows are heap-trim seed
ROOTS -- answer rows keep their demand structs and transitive formula DAGs
alive, and pinned STRUCT relations (smt_bad_formula) seed their own
instances (the error-wrap rule is injected per stratum, invisible to the
partition, so nothing else roots them).  On load, import-layer re-ingests
pinned rows (content interning re-converges demand ids), the dispatch task
seeds `answered` from the reloaded delta, and the solver is NEVER
re-queried; `(error e)` wrappers re-derive from the reloaded arm delta.
Pinned relations are also SIGNED (save + drift-check both extend the
signature set), and recorded in META under `pinned-rels` (old METAs read as
empty; forward-compatible).  Test: tests/compression/smt-pin-test.sh saves
under the sat-answering script solver and reloads under an unsat-answering
one with a call log -- content-equal dumps + zero solver calls at per=100
and per=60.

**Incidental fix.** smtSpawn's pipes are now O_CLOEXEC: pool threads spawn
racing children concurrently, and a sibling child forked between another
thread's pipe() and close() inherited the fast winner's stdout write-end --
holding its EOF hostage until the slow loser exited, which inverted race
outcomes under concurrency.  dup2 clears the flag on the two ends each
child actually uses.

**Remaining known limits**: `slog db verify --replay` (no-seed) skips
import-self, so it cannot reproduce oracle answers -- pinned rows need a
pinned-only import in that mode (deferred; the standard load path is
covered).  Model/core VALUES are solver-chosen: pinning makes them stable
per lineage, which is the guarantee.  Theories (reals/BV/arrays/UF),
lattice verdicts, and quantifiers remain future vocabulary work.
