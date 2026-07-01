# Fully Incremental Slog: Insertion and Deletion of Input Facts

**Status:** design / pre-implementation
**Goal:** make slog programs incrementally maintainable in *both* directions — a stream
of insertions **and deletions** of EDB (input) facts is applied to a materialised
database and every derived relation/struct is updated to exactly the least-fixpoint it
would have had if the new input had been loaded from scratch, without recomputing from
scratch.

This document captures the full design worked out in discussion: the theory that
constrains it, the algorithm we chose (DRed^c), and — concretely — every change we
expect to make and where it lands in the codebase.

---

## 1. Why this is hard: pure counting is unsound for recursion

The tempting design is: give every tuple a *proof count* (number of derivations),
increment on insert, decrement on delete, and remove a tuple when its count hits 0.
This is finite and terminating in slog (we count *one-step* derivations from
currently-present facts, driven by semi-naïve iteration, **not** derivation trees — so
the count of a tuple in a cycle stays finite). And it is **sound and precise for
non-recursive programs**.

It is **not sound for recursive programs**, because a count tells you *how many* proofs
a tuple has, never *whether any of them is still grounded in surviving input*. Across a
recursive cycle, tuples keep each other's counts positive while collectively having lost
all external support — the **unfounded self-supporting cycle**.

### Canonical counterexample (Motik et al.)

```
R(y,x) :- R(x,y).          % symmetric closure; R is EDB + IDB
EDB: R(a,b)
```

After inserting `R(a,b)`: counts are `R(a,b)=2` (1 from the EDB fact, 1 derived from
`R(b,a)`), `R(b,a)=1`. Now **delete EDB `R(a,b)`**: decrement its EDB proof → `R(a,b)=1`,
still `>0`, so it survives; because it survives, `R(b,a)` keeps its derivation and stays
at 1. Final state `R(a,b)=1, R(b,a)=1` — **both wrongly retained**. They prop each other
up forever ("analogous to why reference counting is not a general GC strategy").

The same shape appears as `reachable(a),reachable(b)` in a two-cycle after the `source`
fact that founded them is deleted: the edge cycle survives and mutually supports the
pair even though nothing grounds it anymore.

### Why the naïve intuition (the TC/`path` case) *seemed* to work

Transitive closure over edges deletes correctly under pure counting **only because the
deleted EDB (`edge`) appears inside every recursive proof step**, so deleting an edge
drives all dependent counts to zero directly. The failure case is deleting a fact *below*
a cycle that stays structurally intact. General soundness therefore requires re-checking
**foundedness**, which counts alone cannot do.

### Theory backing this

- Counting a tuple's derivation trees over a cycle is *infinite*; incremental view
  maintenance by counting diverges for recursive views over cyclic data.
- Datalog over a semiring converges **iff the semiring is stable**; ℕ (bag / counting
  semantics) is **not stable**. A finite per-tuple derivation-tree count is not even
  well-defined for recursive Datalog over cycles.
- This is exactly the gap DRed (Delete and Re-derive) was invented to fill.

See §12 for citations.

---

## 2. The chosen algorithm: DRed^c

We adopt **DRed^c** (counting-augmented Delete/Re-derive): Hu, Motik, Horrocks,
*"Optimised Maintenance of Datalog Materialisations"*, AAAI 2018. It combines the
precision of counting on the easy (non-recursive) part with DRed's foundedness repair on
the recursive part, and — crucially for slog — **it does not require evaluating rules
"backwards"** (matching a head to a fact and running the partial body as a query). That
property is why it fits slog's forward, push-operator engine.

DRed^c gives us:

- **Full precision on non-recursive derivations** — counters decide membership exactly,
  no over-deletion, no re-derivation.
- **Sound recursion** — over-delete the suspect region, then re-derive what is still
  founded, restoring the least fixpoint (kills unfounded cycles).
- **A cheap re-derivation** — counters identify the re-foundable frontier without
  backward search.

### Alternatives considered (and why not, for now)

| Approach | Correctness | Fit to slog | Verdict |
|---|---|---|---|
| Pure counting | Unsound for recursion | Trivial | Rejected (see §1) |
| **DRed^c** | Sound | *Extends* current engine; no backward rules | **Chosen** |
| DBSP nested incremental circuits | Sound, O(change) | Codegen rewrite (integration/differentiation ops, nested recursive circuits) | Future |
| Differential dataflow (timestamp lattice) | Sound, O(change) even deep in recursion | Engine *replacement* (versioned traces, progress tracking); ~2–4× memory | Future |

---

## 3. Core concepts

### 3.1 Two counters per fact

Each fact carries two signed counters in its relation's master index:

- **`nonrec`** — number of derivations via rules whose body is entirely in *earlier
  strata* (including base/EDB rules). These are **foundation** proofs.
- **`rec`** — number of derivations via rules with a body predicate in the **same SCC**
  as the head. These are **circular-capable** proofs.

`present(t) := nonrec + rec > 0`. The classification of each *rule* as recursive vs
non-recursive is static (see §4.5), so each rule bumps exactly one of the two counters.

The two counters are the whole reason DRed^c beats plain DRed:

- `nonrec > 0` ⟹ the fact is grounded in an earlier stratum and is **provably still
  true** after any update within this stratum → it is a hard barrier that stops
  over-deletion.
- After the negative fixpoint, `rec > 0` on an over-deleted fact is an **O(1) certificate
  that a surviving derivation still exists** (support that did not route through the
  deleted region) → it can be re-founded in one step, with its count already correct,
  without re-firing its rules.

### 3.2 Two roles per tuple (the key mental model)

Two different things flow through evaluation; do not conflate them:

1. **Counter updates** happen when a tuple is produced (or loses a derivation) **as a
   consequence** of a join. This is the only place `(nonrec, rec)` mutate.
2. **Delta records** `(tuple, sign)` are **propagation signals** — "this tuple changed
   presence; use it as a **premise** to drive the next round of joins." The `sign`
   (+1 appeared / −1 disappeared) tells the downstream aggregate whether joins *through*
   this premise should add to or subtract from **its consequences'** counters.

A delta record therefore carries **no `(Δnonrec, Δrec)` for the tuple itself** — that
tuple's counters were already finalised when it was produced as a consequence. Every
tuple plays both roles: as a consequence its counters are updated; as a premise it is a
signed signal driving further joins.

### 3.3 Presence ≠ counts during an update

Between phases a fact can be **over-deleted** (removed from the live set) while `rec > 0`.
So membership cannot be read off the counters during an update. We track over-deleted
facts explicitly in a transient **candidate set `C`** (§3.4).

### 3.4 The candidate set `C`

`C` is the per-update set of **over-deleted** (speculatively removed) facts. It is
required because counters alone cannot encode "removed but rec>0". It is **not a new
kind of structure**: it is an instance of the existing delta/index machinery
(`BTreeIndex<A>` / the `deltaindices` handles) given a different *lifecycle* —
"accumulate until reseed" instead of "merge into the main index." One handle per
relation, populated only in the negative phase.

---

## 4. The algorithm

Process the program's strata in **topological order** (lowest first). Within a stratum,
run three phases in sequence. Topological order is what makes it a single sweep with no
mutual iteration: when stratum *k* is processed, every earlier stratum is final, so each
fact's `nonrec` counter (which counts only earlier-stratum support) is **stable**
throughout — that stability is what makes the `nonrec>0` barrier sound.

```
for each stratum S in topological order:
    1. NEGATIVE fixpoint   (apply − input deltas to S; over-delete; accumulate C)
    2. RESEED scan         (adjudicate C: rec>0 → re-found; rec==0 → delete)
    3. POSITIVE fixpoint   (apply + deltas: reseeds + genuine inserts; rebuild)
    // facts that truly died escape S as − input deltas to later strata
    // facts newly true escape S as + input deltas to later strata
```

### 4.1 Negative fixpoint (over-deletion)

Drive `Δ⁻` through the **same** compiled join pipeline as forward evaluation. The
aggregate step decrements consequence counters:

```
over-delete(h):                      # when a consequence h loses presence and nonrec==0
    if h not in C:
        C.insert(h)                  # explicit candidate set
        push (h, -1) onto Δ⁻         # propagation signal → decrement h's consequences
    # h stays physically in the main index for now; its counters remain
```

Propagation rule (in the generic aggregate, selected by polarity):

- Decrement the appropriate counter of every consequence reached.
- If a consequence has `nonrec > 0` → **protected**: record the decrement, **do not
  propagate** (stop).
- If a consequence has `nonrec == 0` and its presence drops → **over-delete** it (add to
  `C`, push `−1`), regardless of remaining `rec`.
- A fact is over-deleted at most once per update (the `not in C` guard); later reaches
  only decrement its counters further.

After this fixpoint settles, for every fact `rec` equals the number of its derivations
through **surviving** (non-over-deleted, non-deleted) facts — because over-deleting a
supporter decremented it. Hence `rec > 0` ⟺ re-foundable from a surviving fact.

### 4.2 Reseed scan (between phases)

Iterate **`C`** (not the relation — `O(|over-deleted|)`):

```
reseed():
    for t in C:
        if t.rec > 0:
            push (t, +1) onto Δ⁺      # presence signal to rebuild t's cone; counters already correct
            C.erase(t)                # t survives
        else:
            delete t from the main index   # (0,0): truly gone for now; may be re-derived below
```

Deleting the `rec==0` candidates here (rather than leaving them "absent but physically
present") keeps the positive phase's full-index joins correct **without a per-tuple
liveness branch on the hot path** — after reseed, the index holds only live tuples.

The `(t, +1)` pushed for a re-founded fact is a **propagation signal only**. `t`'s own
`(nonrec, rec)` are already correct; the increments it triggers land on **`t`'s
consequences** (the downstream cone the negative phase wrongly tore down).

### 4.3 Positive fixpoint (insertion / rebuild)

Drive `Δ⁺` (reseeds **plus** genuinely new inserted facts) through the same join
pipeline. The aggregate step increments consequence counters; a consequence whose
presence rises `0 → +` is pushed onto the output delta and (if it was a `rec==0`
candidate deleted at reseed) re-inserted fresh. This rebuilds the torn-down cone and
relearns any fact that is genuinely re-foundable — including facts that dropped to
`(0,0)` mid-update but come back once their founding route is re-established.

### 4.4 The uniform aggregate

The single place counters mutate; identical in both phases except for the propagation
predicate, which is chosen by a polarity flag:

```
aggregate(c, incoming signed derivations, polarity):
    was = present(c)
    c.nonrec += Σ(nonrec-tagged signs)     # "local contributor count" for this iteration
    c.rec    += Σ(rec-tagged signs)
    now = present(c)
    if was != now:
        if polarity == NEGATIVE and now == false and c.nonrec == 0:
            over-delete(c)                 # add to C, push (c,-1)
        elif polarity == NEGATIVE and now == false and c.nonrec > 0:
            pass                           # protected: decremented but not propagated
        else:  # POSITIVE, presence 0 -> +
            push (c, +1) onto Δ⁺
    # counters mutate here (c as consequence); the pushed record is a premise-signal
```

Note the "was == now" case (count changed, presence didn't): **do not propagate**. This
is the finiteness property — re-derivations of an already-present tuple bump its count
but never re-enter the delta, so counts stay finite and each fixpoint terminates.

---

## 5. Worked examples

### 5.1 Unfounded cycle stays deleted (Motik)

```
R(y,x) :- R(x,y).   EDB: R(a,b)
init:  R(a,b) = (nonrec 1, rec 1)     R(b,a) = (nonrec 0, rec 1)
delete EDB R(a,b):
  negative: R(a,b).nonrec 1→0; presence still true (rec 1) but nonrec==0 →
            over-delete R(a,b), push −1 → decrements R(b,a).rec 1→0 →
            over-delete R(b,a), push −1 → decrements R(a,b).rec 1→0.  C = {R(a,b),R(b,a)}
  reseed:   both have rec==0 → delete from index. No Δ⁺ seeds.
  positive: nothing to propagate.
  result:   both gone.  Correct.
```

### 5.2 Over-delete then one-step re-found, and a (0,0) relearn (diamond + chain)

```
path(x,y) :- edge(x,y).             % nonrecursive → nonrec
path(x,z) :- path(x,y), edge(y,z).  % recursive    → rec
EDB edges: a→b, a→e, e→b, b→c        % a reaches b directly AND via a→e→b

init:  path(a,b)=(1,1)   path(a,c)=(0,1)   path(a,e)=(1,0)  path(e,b)=(1,0)  path(b,c)=(1,0)

delete edge a→b:
  negative: path(a,b).nonrec 1→0; nonrec==0 → over-delete path(a,b), push −1
            → path(a,b),edge(b,c) decrements path(a,c).rec 1→0 → (0,0) →
              over-delete path(a,c).           C = {path(a,b)@(0,1), path(a,c)@(0,0)}
  reseed:   path(a,b).rec = 1 (from path(a,e),edge(e,b), both surviving) → push (path(a,b),+1); keep.
            path(a,c).rec = 0 → delete from index.
  positive: path(a,b) drives path(a,b),edge(b,c) → re-derive path(a,c): rec 0→1, re-inserted.
  result:   path(a,b)=(0,1), path(a,c)=(0,1).  Correct (a→e→b→c keeps both).
```

`path(a,b)` was re-founded cheaply in the **reseed** (its own `rec` survived).
`path(a,c)` genuinely hit `(0,0)` and was **relearned only in the positive fixpoint**,
once `path(a,b)` re-propagated.

---

## 6. Where every change lands

Two layers, and the split is what preserves "compile each rule once":

- **Per-rule compiled code** — the `ReadTask` join pipeline emitted inline by
  `emit-cpp.rkt`. Direction-agnostic: reads a delta, probes indices, hands
  presence-transition records to the aggregate. **The sign is data**, not code — so this
  is compiled **once per rule** and shared across the negative and positive phases.
- **Generic per-arity machinery** — `WriteTask<A>`, `InternTask<N>`, `InternStructTask<N>`
  in `operators.h`, instantiated per relation/bucket. **Every asymmetry between the
  phases lives here or in the driver**, never in per-rule code.

### 6.1 Data structures — `daemon/index.h`, `daemon/database.h`

- Master index value changes from a set element to a mapped value:
  - relations: `btree_map<std::array<u64,A>, Count>` where `struct Count { s64 nonrec; s64 rec; };`
  - structs: value `struct SCount { u64 id; s64 nonrec; s64 rec; };` — **`id` stays in
    the value so it survives over-delete/reseed** (see §7).
  - Counters live in the **value**, never in the key (else the same tuple at two counts
    becomes two keys and dedup/probe ordering breaks). Use **signed** `s64`: negative
    weights must exist *in transit* during propagation.
- Delta/probe indices that don't need counts can stay sets.
- Add, per relation, a handle for the transient candidate set `C` (§3.4) — reuse the
  existing `deltaindices` machinery; populated only in the negative phase.
- Relation gains: stratum id and, per index, the rule-derived rec/nonrec tag needed by
  the aggregate.

### 6.2 Operators — `daemon/operators.h`

- `read_delta` (l.40), `join_probe` (l.59), `join_all` (l.76): **unchanged** — sign-agnostic.
- `emit` (l.94): replace the set-semantics "if head exists, skip; else scatter" with a
  **counting, signed** producer that records `(tuple, sign)` tagged with the rule's
  static rec/nonrec bit into the batch — **no emit-time dedup-skip** (we must count
  re-derivations of existing tuples).
- `emit_struct` (l.133): same, but the id slot stays a placeholder (interning owns id).
- `InternTask` (l.203) → **counting aggregator** implementing §4.4: sum per-tuple signed
  contributions, update `(nonrec, rec)`, apply the polarity-selected propagation
  predicate (over-delete + `C` on negative; push Δ⁺ on positive).
- `InternStructTask` (l.241): same aggregation, preserving `id`; presence 0→+ allocates
  id only for genuinely new content; presence →0 tombstones (does not recycle id).
- **New generic task: `ReseedTask<A>`** — §4.2 scan of `C`.
- `WriteTask` (l.164): learn to *remove* index entries (reseed's `rec==0` deletes and the
  final sweep), not only insert.

### 6.3 Codegen — `compiler/emit-cpp.rkt`

- Emit `emit` → the counting/signed producer, parameterised by the rule's static
  `IS_REC` bit and a phase-supplied sign.
- Instantiate the new generic tasks (`ReseedTask<A>`, counting `InternTask`) per relation/
  bucket alongside the existing `WriteTask`/`InternTask` wiring (l.48-88).
- No per-rule deletion variant is emitted — the negative phase reuses the same
  per-position semi-naïve delta-join variants already generated for insertion.

### 6.4 New compiler pass — `compiler/operationalization.rkt` / `join-planning.rkt`

**Current state (baseline — what exists today).** There is **no SCC / stratification
analysis anywhere in the compiler.** Within a single program, *all* rules compile into one
global fixpoint and the daemon runs them together to quiescence (`compile.rkt:121-138`).
The only decomposition is at **module (`require`/include) granularity**: the include tree
is flattened by `preorder-traversal` (`compile.rkt:51-54`) into a linear list of separate
programs, each compiled to its own `.so` and run to fixpoint in dependency order with
`reload:` between them (`runslog.rkt:145-152`; the manifest is threaded forward by
`add-manifests`, `compile.rkt:77-82`). This is programmer-authored staging, not computed
strata. The only static/dynamic notion is **binary**: `dynamic-rels` = every relation
appearing in any rule head (`add-dynamic-rels`, `compile.rkt:99-107,132`); a read-task is
emitted **static** (run once) iff its first body relation is not a dynamic-rel (pure EDB),
else **dynamic** (iterate) — `emit-cpp.rkt:411`, mirrored by the first-non-delta-index
`isstatic` at `emit-cpp.rkt:67`. This bit is baked into the emitted C++ (`isstatic` arg to
`addTask`/`addIndex`); the daemon has no SCC/stratum concept of its own.

This binary is **too coarse for DRed^c**: it cannot distinguish a body predicate that
shares the head's SCC (→ `rec`) from one in a strictly lower stratum (→ `nonrec`) — both
are just "dynamic" today. M2 must therefore add genuine SCC + topological stratification
from scratch. Reusable: the *plumbing pattern* — `dynamic-rels` shows exactly how a
compile-time relation-set is computed in `compile.rkt` and threaded into `emit-cpp.rkt`'s
`(add-rule dynamic-rels)` closure; the rec/nonrec tag rides the same path. The
module-reload pipeline is also a working precedent for sequencing stages through one
daemon, should we later want strata run as ordered sub-fixpoints.

Net-new work:

- Build the rule dependency graph, compute **SCCs**, assign **strata** in topological
  order.
- Tag each rule **recursive** (a body predicate shares the head's SCC) or
  **non-recursive** (all body predicates in earlier strata). This single bit drives
  `emit`'s counter choice and the aggregate's barrier.
- Emit stratum ids and processing order into the manifest the driver consumes.

### 6.5 Driver — `daemon/database.h` fixpoint loop (l.728-749)

- Generalise the phase loop to carry a **polarity** and run the three-phase, per-stratum
  schedule of §4.
- Between negative-phase iterations, accumulate the delta into `C` instead of merging
  into the main index; between positive-phase iterations, merge as today (`reorgDelta`).
- **Termination keys on presence transitions, not count changes** (`latest_any_rec`,
  l.535) — otherwise a re-derivation that only bumps a count spins the loop. Revisit the
  arity-0 / `reorgDelta` guard from the earlier OOM fix under this new invariant.

### 6.6 Input protocol — `daemon/slogd.cpp` (command loop l.60-116)

- Add signed-fact commands (e.g. `+<tuple>` / `-<tuple>`, or a signed batch) that feed
  the per-thread delta shards with a sign.
- Batch a set of changes and run one three-phase sweep per batch.

---

## 7. Structs: specific concerns

- Structs are derived (via `emit_struct`) and interned (`InternStructTask`), mapping
  content → id. With counting the master index maps content → `(id, nonrec, rec)`.
- **Id stability across over-delete/reseed is mandatory.** Other tuples embed a struct's
  id; if reseed/rederivation hands out a fresh id, every referent dangles. Keep `id` in
  the value, **tombstone at presence 0, never recycle** an id until a foundedness-safe
  reclamation pass proves no live referent remains (initially: never reclaim).
- Per-bucket id allocators (`operators.h` intern allocators) must not treat a tombstoned
  slot as free.

---

## 7A. Aggregation, rank, and lattice-valued recursion (plan-ahead)

Aggregation is deferred past the first incremental milestones (M0–M4 do plain recursion),
but the substrate must **anticipate** it, because the mechanism that makes recursive
aggregation work is the *same* mechanism that makes recursive deletion precise. Get the
value slot, the delta format, and the rel-env right now and aggregation slots in without a
rewrite.

### 7A.1 An aggregate is a semiring fold — so it inherits stability exactly

An aggregate is a `⊕`-fold over a group. Putting one inside recursion therefore converges
**iff its semiring is *stable*** — the same condition from §1 (Abo Khamis et al., PODS
2022). Concretely:

- **tropical `(min,+)` is stable** → recursive `MIN`/`MAX` converges (shortest path,
  min-label connected components). Safe recursively.
- **`ℕ (+,×)` is not stable** → recursive `SUM`/`COUNT` diverges over cycles — the *exact*
  same failure as plain derivation counting in §1. Not safe recursively.

So recursive aggregation is not impossible; it is possible **precisely for the stable
(monotonic) aggregates**. The escape hatch and its practical test have names:
**monotonic aggregation** (Ross & Sagiv, PODS 1992 / JCSS 1997) and **pre-mappability
(PreM)** (Zaniolo, Yang, Das, Shkapsky, Condie, Interlandi, TPLP 2017; DeALS/BigDatalog),
which says exactly when `min`/`max` (and constrained `count`/`sum`) may be pushed inside a
fixpoint while preserving the least-fixpoint answer.

### 7A.2 Two kinds of per-fact state — keep them separate

Do not conflate foundedness with the aggregate value; they are orthogonal and both needed.

1. **Foundedness state** of the aggregate *result* tuple `agg(group,value)` — tracked with
   the same `(nonrec, rec)` / rank machinery as any derived tuple.
2. **Aggregate value state** — function-specific auxiliary state:

   | Aggregate | State per group | Deletion |
   |---|---|---|
   | `COUNT` | contributor count | trivial (−1; retract at 0) |
   | `SUM` / `AVG` | running sum + count | trivial (subtract; count says when empty) |
   | `MIN` / `MAX` | **whole contributor multiset** (sorted `BTreeIndex` by `(group,value)`) | *hard*: deleting the current extreme needs the next one |

   (Mumick/Quass/Mumick, SIGMOD 1997 — COUNT is kept precisely *so deletion works*;
   Palpanas et al., VLDB 2002 — the MIN/MAX auxiliary structure.)

Two rules that make this fit our framework:

- **Aggregate over the *set* of founded contributors, each once — not weighted by
  derivation count.** A contributor's `rec/nonrec` count governs *its* membership; while
  present it contributes once. The aggregate value is driven by contributors' **presence
  transitions** (the `±1` signals from §3.2/§4.4), never by raw counts.
- **A value change is `retract-old + insert-new`.** `agg(g,5) → agg(g,7)` emits
  `−agg(g,5), +agg(g,7)` — ordinary signed deltas, no new downstream mechanism.

### 7A.3 Rank *is* a recursive-min aggregate (the unification)

The `rank` from §"count+rank" (minimum derivation depth) is itself a recursive `MIN`
aggregate over the tropical semiring: `rank(t) = 1 + min over derivations of max(premise
ranks)`. So **foundedness-rank maintenance and recursive `MIN`/`MAX` aggregation are the
same computation**, and their hard case is the same: deleting the input that supplied the
current best = **decremental shortest path** = recompute the value from survivors and
propagate the regression. Build rank repair for foundedness and you have recursive
monotonic aggregation for free (and vice-versa).

### 7A.4 Rank-rebuilding vs. the `rec/nonrec` algorithm — same shape, finer grain

`(nonrec, rec)` is a **coarse, membership-only, 2-bucket approximation of rank**:
`nonrec>0` ≈ "grounded below this stratum" (a low, bounded rank); `rec`-only ≈ "rank
determined inside the SCC." DRed^c resolves the in-SCC part **bluntly** — over-delete the
region, rebuild from the boundary. Rank-rebuilding is the **fine-grained generalization**:

| | DRed^c `(nonrec,rec)` | rank-rebuilding (tropical) |
|---|---|---|
| per fact | 2 integer counters | 1 lattice value (+ how to find next-best) |
| resolves foundedness by | over-delete region + forward rederive | recompute value from survivors, propagate *regressions* only |
| over-work | can tear down + rebuild a whole region | touches only facts whose value actually changes |
| deletion style | invalidate-then-rebuild | Ramalingam–Reps decremental-SSSP |
| also gives you | membership | membership **and** the aggregate value |

Both share the skeleton — *localized recomputation triggered by deletion, bounded by a
well-foundedness/stability property* — and both face the same memory/compute trade: to
find the next-best derivation *without* re-running rules you must store per-derivation
info (heavy); DRed^c and forward-rebuild avoid that by re-deriving from the boundary.
`(nonrec,rec)` is simply the degenerate case of rank; rank is the version that also does
aggregation.

### 7A.5 The dovetail: user-declared stable semiring / semilattice

The crisp payoff — **one mechanism, parameterised by a semiring.** Let a relation declare
the lattice/semiring it aggregates over: a domain, `⊕` (combine — associative,
commutative; idempotent for a semilattice), `⊥`, and the order. The engine maintains the
lattice value incrementally with the shared rank-rebuild machinery. Built-in instances:

- **Boolean present-lattice** → plain membership (the DRed^c default).
- **tropical depth** → foundedness rank (internal, for recursive relations).
- **user lattices** → `min`/`max`/shortest-path/custom monotonic aggregates.

**Stability is the compile-time admissibility check:** a stable/monotone semiring may be
used *recursively* (Tier 2 below); a non-stable one (`SUM`/`COUNT`) is allowed only
*stratified* (Tier 1) or **rejected** with a clear error — the ℕ-not-stable boundary made
into a diagnostic. (Lattice-typed relations echo Bloom^L: Conway, Marczak, Alvaro,
Hellerstein, Maier, SoCC 2012.)

### 7A.6 Implementation tiers

1. **Tier 1 — Stratified aggregation (safe baseline; covers ~all practical use).** Require
   the group relation in a *strictly lower stratum* (M2 gives this; enforce + reject
   same-SCC here). Keep `(count,sum)` per group for `COUNT`/`SUM`/`AVG`; a sorted
   `BTreeIndex` multiset per group for `MIN`/`MAX`. Contributor presence-transitions drive
   it; value changes emit `retract-old + insert-new`. **Deletion is fully precise — no
   over-delete/rederive** (non-recursive w.r.t. its input). Drops straight into the
   three-phase driver as a higher-stratum relation.
2. **Tier 2 — Recursive monotonic aggregation (stable semiring).** Allow same-SCC
   `MIN`/`MAX`/user-lattice when PreM/monotonicity passes. Value = lattice element per
   group; lattice-semi-naïve for insertion (monotone, easy); deletion = the rank-repair
   path, **shared with foundedness**.
3. **Tier 3 — Reject recursive non-stable aggregation** (`SUM`/`COUNT` over cycles) unless
   acyclic grounding / a PreM certificate is proven.

### 7A.7 Forward-compatibility hooks to build during M0–M4

Even though aggregation ships later, these choices in the early milestones avoid a rewrite:

- **Extensible index-value slot.** Do not hardcode `struct Count { s64 nonrec, rec; }` as
  the only shape — make the per-relation value a configurable type so a relation can later
  carry a rank / lattice accumulator (or a `(count,sum)` / multiset handle) instead of
  bare counters.
- **Value-carrying delta records.** Allow a delta record to carry a payload, not only a
  sign, so `retract-old + insert-new` value changes and lattice deltas fit the same
  transport (§3.2 already separates the premise-signal from the counter update — extend
  the signal to optionally carry a value).
- **A semiring/lattice annotation slot in the rel-env / manifest**, default =
  support-counting (membership). This is where a user later declares `min`/`max`/custom.
- **M2 must also expose, per rule, the same-SCC bit per body predicate** — needed to
  classify recursive-vs-stratified aggregation and to run the monotonicity/PreM check.
- **Anticipate an aggregate rule form in the IR** (group-by vars + combine op) even if
  unimplemented, so `operationalization.rkt` doesn't need reshaping later.

## 8. Known caveats to design in now

- **Semi-naïve delta convention.** Negative propagation must respect the standard
  "delta-in-one-position against the pre-deletion state" convention, or two deleted
  supporters of one derivation double-decrement the consequence. slog already generates
  the per-position delta-join variants for insertion; the negative phase reuses them, but
  the **driver must sequence old/new state consistently.**
- **Termination invariant** (§6.5): presence transitions, not count changes.
- **Struct id stability** (§7).
- **`C` lifecycle correctness:** after the positive phase, any candidate still at `(0,0)`
  that was not rebuilt is physically removed; anything rebuilt has a positive count and
  stays. (In the reseed formulation of §4.2, `rec==0` candidates are removed at reseed
  and only re-inserted if the positive phase re-derives them — equivalent.)

---

## 9. Phased implementation plan

Each milestone is independently testable and delivers value before the next.

1. **M0 — Signed-count substrate.** `Count`/`SCount` index values; signed deltas;
   counting `emit`/`InternTask` with presence-transition propagation. Insertion still
   monotone, but now counter-based. Verify identical results to today plus correct counts.
2. **M1 — Bidirectional input protocol.** `+`/`-` commands into delta shards
   (`slogd.cpp`). Deltas can be negative.
3. **M2 — Stratification + rec/nonrec tagging.** New compiler pass; strata/tags in the
   manifest; `emit` targets the right counter. No behaviour change yet for insertion.
4. **M3 — Non-recursive deletion.** For acyclic strata, signed counting is sound and
   complete both directions. Ship full incrementality for non-recursive programs. Big,
   safe milestone.
5. **M4 — Recursive deletion (DRed^c).** Candidate set `C`, negative fixpoint with the
   `nonrec>0` barrier, `ReseedTask`, three-phase driver. This is the hard milestone.
6. **M5 — Struct GC discipline.** Tombstoning, id stability, (optional) safe reclamation.
7. **M6 — Stratified aggregation** (§7A Tier 1). `COUNT`/`SUM`/`AVG` via `(count,sum)`;
   `MIN`/`MAX` via a per-group sorted multiset; value changes as `retract-old+insert-new`.
   Fully precise deletion; no new recursion machinery. Requires only the M2 strata + the
   §7A.7 hooks.
8. **M7 — Recursive monotonic aggregation** (§7A Tier 2). User-declared stable
   semiring/semilattice; lattice-valued relations; rank-precise foundedness sharing the
   same rank-rebuild path. This is where `(nonrec,rec)` optionally generalises to a full
   tropical rank (§7A.4). Tier 3 rejection of non-stable recursive aggregates lands here
   too, as a compile-time diagnostic.

The M0–M4 substrate should already carry the §7A.7 forward-compatibility hooks so M6/M7
are additive, not a rewrite.

---

## 10. Testing strategy

The literature's counterexamples are the test suite. Each must match a from-scratch batch
recompute after a randomised insert/delete sequence:

- `R(y,x):-R(x,y)` symmetric closure — insert then delete the seed (unfounded cycle).
- `reachable` with `source` deletion leaving a live edge-cycle (unfounded cycle archetype).
- TC over cyclic graphs, deleting edges (must *stay* correct — the case pure counting
  handled).
- Diamond + chain (§5.2): over-delete then one-step re-found, plus a `(0,0)` relearn.
- SCC collapse: delete the single edge bridging two strongly-connected blobs.
- **Differential fuzzing:** random `±tuple` streams vs. full recompute, across programs
  with structs and multiple strata.

---

## 11. Future directions (not in scope)

- **DBSP nested incremental circuits** for O(change) recursion without over-deletion
  waste — a codegen project atop `emit-cpp.rkt` (integration/differentiation operators,
  nested recursive circuits).
- **Differential dataflow** (timestamp lattice, versioned traces) for O(change) even deep
  in recursion — an engine replacement with ~2–4× memory and a progress-tracking
  subsystem. Reach for it only if deep-recursion incremental performance demands it.

---

## 12. References

- A. Gupta, I. S. Mumick, V. S. Subrahmanian. *Maintaining Views Incrementally.* SIGMOD
  1993. (Counting algorithm and DRed; counting fails on recursion.)
- P. Hu, B. Motik, I. Horrocks. *Optimised Maintenance of Datalog Materialisations.*
  AAAI 2018. arXiv:1711.03987. (**DRed^c**: nonrec/rec split counters, three phases, no
  backward evaluation.)
- B. Motik, Y. Nenov, R. Piro, I. Horrocks. *Incremental Update of Datalog Materialisation:
  The Backward/Forward Algorithm.* AAAI 2015. (Foundedness via backward proof search.)
- B. Motik, Y. Nenov, R. Piro, I. Horrocks. *Maintenance of Datalog Materialisations
  Revisited.* Artificial Intelligence 269 (2019). (FBF; unifies DRed / B/F / counting.)
- M. Budiu, T. Chajed, F. McSherry, L. Ryzhyk, V. Tannen. *DBSP: Automatic Incremental
  View Maintenance for Rich Query Languages.* VLDB 2023. (Z-sets; recursion via nested
  circuits with `distinct`; least-fixpoint recomputation, not derivation counts.)
- F. McSherry, D. Murray, R. Isaacs, M. Isard. *Differential Dataflow.* CIDR 2013.
  L. Ryzhyk, M. Budiu. *Differential Datalog.* Datalog 2.0, 2019. (Signed multiplicities
  over a timestamp lattice.)
- T. Green, G. Karvounarakis, V. Tannen. *Provenance Semirings.* PODS 2007.
  M. Abo Khamis, H. Ngo, R. Pichler, D. Suciu, Y. Wang. *Convergence of Datalog over
  (Pre-)Semirings.* PODS 2022 / JACM 2024. (ℕ is not stable → counting diverges on
  recursion; stable semirings converge — the aggregation admissibility condition.)

### Aggregation

- K. Ross, Y. Sagiv. *Monotonic Aggregation in Deductive Databases.* PODS 1992 / JCSS
  54(1) 1997. (Aggregation monotone over a lattice composes with recursion.)
- C. Zaniolo, M. Yang, A. Das, A. Shkapsky, T. Condie, M. Interlandi. *Fixpoint Semantics
  and Optimization of Recursive Datalog Programs with Aggregates.* TPLP 2017. (**PreM** —
  when min/max/count/sum are safe inside a fixpoint; DeALS/BigDatalog.)
- I. Mumick, D. Quass, B. Mumick. *Maintenance of Data Cubes and Summary Tables in a
  Warehouse.* SIGMOD 1997. (Self-maintainable aggregates; COUNT retained for deletion.)
- T. Palpanas, R. Sidle, R. Cochrane, H. Pirahesh. *Incremental Maintenance for
  Non-Distributive Aggregate Functions.* VLDB 2002. (MIN/MAX auxiliary structures.)
- N. Conway, W. Marczak, P. Alvaro, J. Hellerstein, D. Maier. *Logic and Lattices for
  Distributed Programming* (Bloom^L). SoCC 2012. (Lattice-typed, monotone-composable
  relations.)
