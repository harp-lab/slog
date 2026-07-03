# Lattice-Valued Relations and Recursive Aggregation

**Status:** L0 + L1 IMPLEMENTED (2026-07-02); L2 (ps/interval/products/lift2)
and L3 (extern) remain design.
**Companions:** `docs/incremental.md` §7A (the incrementality dovetail this design
tees up), `docs/demand.md` (demand-moded judgments, which lattice answers compose
with).

## 0. Implementation status and deviations (2026-07-02)

Shipped, end to end: the `lattice` type declaration and inline anonymous
valuespecs (§3.1) for `(min|max int|float [#:floor/#:ceiling])`, `(count)`,
and `(flat T)`; the monotone-use calculus and occurrence restrictions
(`compiler/lattice-check.rkt`, post-stratify, per §5.1/§5.3 -- 27 unit tests
in `tests/unit/lattice-tests.rkt` pin the acceptance/rejection battery); the
payload-map runtime (`BTreeMapIndex` in `daemon/index.h`, `LatticeInternTask`
+ `MapWriteTask` + payload-binding `join_probe_lat`/`join_all_lat` in
`daemon/operators.h`, kernels in `daemon/types.h`); value-carrying deltas
with subsume-as-null and in-place rewrite; floor/ceiling clamps; the
unbounded-descent warning; CSV output one-row-per-key; reload and
cross-program (`run`) persistence via `(lat ...)` manifest entries; and the
§3.4 demand composition (a lattice-typed answer column makes `f_ans` a map
with zero demand-specific machinery -- `tests/lat_demand.slog`).  Golden
tests: `tests/lat_*.slog` (sssp on a cyclic graph, cross-stratum extraction
+ secondary map orderings, flat constprop over a diamond CFG, abstract
counting with `cplus`, max-float with ceiling, negative cycle clamped by
`#:floor`).

Deviations and v1 choices, relative to the design below:

- **Guard spellings**: the upward-closed tests are written with existing
  forms -- `(= V (inf))` on count and `(= V (top))` on flat -- rather than
  new `cinf?`/`top?` guards (the planner's `==`-check machinery makes them
  free; the calculus classifies them by direction).  `(= V (one))` and
  `(= V (const ...))` in-SCC are rejected, as designed.
- **`(bool)` is deferred**: it is the degenerate presence lattice, and
  slog's true/false are interned `_enum` constants, so its payload word has
  no clean representation; `(max int #:ceiling 1)` covers the need.
- The type system treats lattice types as **transparent aliases of their
  base types** (implicit injection in, unwrap out); all lattice discipline
  lives in the post-stratify check pass.  The same-SCC bit uses the fact
  that a body relation at the same stratum LEVEL is necessarily in the same
  SCC (a cross-SCC body->head edge forces a strictly higher level).
- **Secondary indices are payload maps too** (not key-only sets with an
  extra master probe as §4.3 sketched): every non-delta index of a lattice
  relation is a `BTreeMapIndex` registered under a full-length ordering
  ending in the value column, kept exact by join-merging write tasks each
  iteration -- so probes on any ordering bind the payload directly.  Delta
  indices stay full-width sets (delta rows are immutable post-intern).
- **Representations**: count is tagged-s32 1/2 (printed `(one)`/`(inf)`);
  flat's top is the reserved word `slog_lat_top` (printed `(top)`), distinct
  from `slog_null`.
- **Restrictions**: one lattice column per relation, in the last position,
  with at least one key column (all checked; products are L2).
- The head sink is `emit_temp` (batch, no dedup) -- no emit-time subsume
  probe yet; the merge task owns subsumption, and the termination flag
  keeps its existing one-iteration lag (subsumed records are nulled and
  reorged away, so the next delta is empty).
- **On-disk BIN round-trip works** (`write-db` / `open`): a lattice
  relation's directory is `lat.<name>.arity.<N>.spec.<token>`, where the
  token is the canonical valuespec ("min-int-floor-0", "count",
  "flat-value") -- carried opaquely from the compiler through
  `setLattice`, emitted by `relationDirBIN`, parsed back by the daemon's
  open path (kind + clamps + a payload-map default index, so out-of-band
  ingestion merges) and by runslog's manifest scan (a `(lat name arity
  spec)` entry, checked against redeclarations).
- **Abstract counting is dogfooded**: `examples/tinycfa/0cfa-counting.slog`
  adds the mu measure to the demand-driven 0CFA -- one variable certified
  a singleton (must-alias), one genuinely polyvariant, one polyvariant by
  monovariant imprecision, dead parameters absent -- with the
  singleton/polyvariant reports forced into later strata by the calculus.
- **Deferred**: the `sizes`-style top-k/top-fraction report; the emit-time
  subsume pre-check; L2/L3 items (`ps`, `interval`+widening, products,
  `lift2` flat transfers, merge budgets, `registerLattice`).

Slog's relations are already lattices — *powerset* lattices: a relation's extent
grows monotonically under ∪, rules are monotone maps, and evaluation is a least
fixpoint. This document is about admitting the **other** lattices: keyed relations
whose value column carries an element of a declared join-semilattice, merged by ⊔
instead of accumulated as a set. That single change is what turns

- transitive closure into **shortest paths** (tropical min),
- "all values a register may hold" into **constant propagation** (flat lattice),
- "all bindings an abstract address may hold" into **abstract counting** for
  abstract abstract machines (the {0,1,∞} chain, enabling strong updates),
- set-of-facts program analyses into **interval/range analyses** (with widening).

Scope discipline: this document designs lattices and recursive aggregation **as if
batch-only** — semantics, declarations, the type system's obligations versus the
user's, and the runtime — while making every representation choice the one that
incrementality (DRed^c, `incremental.md`) can later extend *additively*. Deletion
of lattice contributions is explicitly out of scope here and sketched only in §10.

---

## 1. Semantics

### 1.1 What a lattice relation is

A declaration (syntax in §3) fixes, for relation `R`:

- **key columns** `k̄` — ordinary slog types (int, float, str, structs, unions);
- **value column(s)** `v̄` — each drawn from a declared join-semilattice
  `(L, ⊔, ⊥)`; multiple value columns are the product lattice, pointwise.

The database interprets `R` as a **finite partial map** `k̄ ⟼ L \ {⊥}`:

- at most one row per key tuple (a functional dependency `k̄ → v̄`, maintained by
  the engine, not asserted by the user);
- **absence is ⊥** — a key not in the map has value ⊥, and ⊥ is never stored.
  (This matches slog's set semantics exactly when `L` is the two-point lattice:
  presence is the value. Plain relations are the degenerate case.)

Deriving `R(k̄, v)` does not insert a row; it **contributes** `v`:
`DB'[k̄] = DB[k̄] ⊔ v`. Multiple rules, multiple firings, and re-derivations all
merge. There is no way to write a lattice value down; the extent of `R` only
ascends.

### 1.2 Reading: body atoms bind the current value

A body atom `(R k̄ V)` matches the (single) current row per key and binds `V` to
the current value — the Flix reading, not the "enumerate all contributions"
reading. Contributions are not observable; only their join is. `V` is then a
**lattice-typed variable**, and what may be done with it is governed by the
monotonicity calculus of §5.

### 1.3 The fixpoint

Order databases pointwise: `DB ⊑ DB'` iff every plain relation of `DB` is a
subset and every lattice key's value is ⊑ in its lattice. If every rule is a
monotone map on this order (§5 makes that a checked property inside recursion),
the immediate-consequence operator is monotone and Knaster–Tarski gives a least
fixpoint — the program's meaning. This is the classic monotonic-aggregation
semantics (Ross–Sagiv) and the Flix/Bloom^L model; we are not "pushing an
aggregate into recursion" (the PreM framing) but giving the program lattice
semantics natively, so no pre-mappability side condition is needed.

Termination is separate from existence: evaluation reaches the fixpoint in
finite time iff every key's value ascends only finitely often. §6 classifies
lattices by whether the engine can guarantee that (finite height), bound it
(declared floor/ceiling, widening), or must pass the obligation to the user
(unbounded tropical descent = the negative-cycle problem).

### 1.4 Evaluation: lattice semi-naive

Semi-naive evaluation generalizes cleanly, and it is the same shape our engine
already has:

- the **delta** for a lattice relation is the set of keys whose value *changed*
  this iteration, each record carrying the key and the **new (post-merge)
  value** — a value-carrying delta (`incremental.md` §7A.7 hook, realized);
- rules re-fire on changed keys exactly as they re-fire on new tuples today;
- conclusions derived from a stale value are *not retracted* — monotonicity
  makes them subsumed: a downstream lattice head re-merges (`old ⊔ new = new`
  when the transfer is monotone), and a downstream monotone gate that was true
  stays true. This is why the monotone-use discipline is not a style preference
  but the soundness condition for not doing retraction;
- **fixpoint termination keys on value changes**, the generalization of today's
  presence transitions (a contribution `v ⊑ current` produces no delta — it is
  *subsumed*, the lattice analogue of the dedup-skip).

---

## 2. Motivating examples (worked)

### 2.1 Shortest path (tropical min)

```
table   (edge int int int)          ;; src dst weight
lattice (cost (min int))            ;; a value type: int merged by min
table   (dist int int cost)         ;; hence a map: (src, dst) ⟼ cost

rule (edge X Y W) --> (dist X Y W)
rule (dist X Y D) (edge Y Z W) --> (dist X Z (+ D W))
```

`(min int)`: join = numeric min, so the lattice order is *reversed* numeric —
a value "ascends" by getting numerically smaller; ⊥ is absence (+∞). The head
expression `(+ D W)` is monotone in `D` (translation preserves order, any sign
of `W`), so the recursion is admitted. Termination is the user's obligation here
(negative cycles descend forever); `(min int #:floor 0)` restores a finite-height
guarantee by clamping (§6).

Compare today's workaround: compute all `path` costs as a plain relation
(diverges on cyclic graphs — infinitely many path lengths), or bound depth by
hand. The lattice version terminates on any nonneg-weight graph because only
*improvements* propagate.

### 2.2 Constant propagation (flat lattice)

```
lattice (fv (flat value))                 ;; flat lift of any slog type incl. structs
table   (regval label reg fv)             ;; map: (label, reg) ⟼ fv

rule (assign L R (constk K))                  --> (regval L R K)
rule (assign L R (copyk R2)) (regval L R2 V)  --> (regval L R V)
rule (flow L L2) (regval L R V)               --> (regval L2 R V)
```

`(flat T)`: ⊥ < v < ⊤ for every `v : T`; `v ⊔ v = v`, `v ⊔ w = ⊤` for `v ≠ w`.
Join needs only equality of the underlying (word-sized, possibly interned)
value, so `flat` lifts *any* slog type, including structs — flat-of-terms is
constant propagation over syntax. Height 2 ⇒ always terminates. Reading "is it
a constant here?" (`V ≠ ⊤`) is a *downward-closed* test and therefore only legal
once `regval` is closed — a later stratum (§5.3); asking "is it ⊤" is
upward-closed and legal anywhere.

### 2.3 Abstract counting for AAM ({0,1,∞})

The abstract-abstract-machine store `σ : addr → P(value)` is a powerset lattice
— plain slog relations already are that (`(store a v)`), which is exactly the
AAM store-as-map-to-powerset framing (Van Horn–Might). What plain relations
cannot express is the **counting** measure μ (Might–Shivers ΓCFA):
`μ̂ : addr → {0, 1, ∞}`, "an upper bound on how many concrete bindings this
abstract address stands for," the enabler of strong updates, super-β inlining,
and abstract-GC precision. (Verified against the JFP version: N̂ = {0,1,∞},
⊑ = ≤, ⊔ = max; the *pinching theorems* — μ̂(â)=1 forces must-alias — are the
strong-update licenses.) Two counting idioms, both expressible:

**Global (flow-insensitive) cardinality** — one count per address:

```
lattice (card (count))        ;; chain 0 < 1 < inf; 0 = absence; join = max
table   (mu addr card)

;; every binding event contributes 1
rule (bind St A V) --> (mu A (one))
;; two observably-distinct binding events to one address force inf
rule (bind St1 A V1) (bind St2 A V2) (/= V1 V2)   --> (mu A (inf))
rule (bind St1 A V)  (bind St2 A V)  (/= St1 St2) --> (mu A (inf))
```

Note what this is *not*: it is not `COUNT(bind)` — that aggregate is
non-idempotent and unsound in recursion (`incremental.md` §1/§7A). This
rendering is idempotent by construction (`one ⊔ one = one`); only *evidence of
distinctness* raises it to `inf`. μ(a)=1 then certifies a globally unique
binding — flow-insensitive must-alias.

**Per-state (ΓCFA-faithful) counting** — μ threaded through the machine. ΓCFA's
actual update is not a join: along a transition it applies the **abstract
increment** ⊕ (1⊕1 = ∞, the "natural abstraction of addition over N̂"), and
only *across* converging paths does it merge with ⊔ = max. Both fit: ⊕ is
non-idempotent but **monotone in each argument**, so it is a legal transfer
(`cplus`), while the per-key merge stays the idempotent max:

```
table (mucnt state addr card)

rule (step S S2) (mucnt S A C) (not-bound S2 A)  --> (mucnt S2 A C)
rule (step S S2) (mucnt S A C) (binds S2 A)      --> (mucnt S2 A (cplus C (one)))
```

The division of labor — non-idempotent evolution as a monotone *transfer*,
idempotent ⊔ as the *merge* — is precisely what keeps this sound where a
count-the-derivations aggregate would diverge.

The strong-update idiom is then **two-stratum by force of the type system**:
`μ = one` is a downward-closed test (more merging can raise it to `inf`), so
reading it inside the SCC that computes `mu` is rejected; a *later* stratum —
a must-alias pass, an abstract-GC pass, a re-analysis with strong updates over
the frozen μ — may branch on it freely. The classic soundness trap
(strong-updating against a count that later grows) is a **compile error** here.
For the record, the nearest published relative is Ascent's flat-lattice CESK
store (Gilray–Micinski–Sahebolamri, CC 2022) — abstract numbers through
`(flat T)` to bound divergence; counting appears in no published Datalog-based
analysis we found (LADDDER, PLDI 2021, on Soufflé/Doop: "Soufflé only provides
four built-in aggregators, so Doop can only encode powerset-based analyses").

### 2.4 Min-cost parsing (lattices × demand)

`docs/demand.md`'s grammar-is-a-parser example, with one changed declaration:

```
demand (parse str int) (min int)    ;; inline spec, or a named type: ... cost
```

or more usefully cost-per-span:

```
demand (parsecost str int int) (min int)   ;; (sym, i, j) ⟼ min cost
```

Demand answers are stored in the generated `_ans` table; when an answer column
carries a lattice spec, `_ans` becomes a lattice relation keyed by the demand id
(§3.3). The Earley-style evaluation is unchanged; answers now merge tropically —
semiring parsing (min-cost derivation) as a one-declaration delta from
recognition. The same move gives memoized recursive functions over any lattice:
`demand (analyze fn) (ps effects)`, `demand (eval e env) (flat value)`, …

---

## 3. Surface language

### 3.1 The declaration (recommended): `lattice` declares a TYPE

```
lattice (cost (min int #:floor 0))
lattice (reg  (flat value))
lattice (card (count))
```

`lattice` declares a **value type** equipped with a merge — not a relation.
It joins `union`/`struct`/`enum` in the type vocabulary, and lattice-ness then
flows through the *existing* declaration forms by occurrence:

```
table  (dist int int cost)        ;; a map (int,int) ⟼ cost: merged, one row/key
demand (parsecost str int int) cost   ;; answers merge tropically per demand
```

**Any relation with a lattice-typed column is automatically a map** from its
non-lattice columns to its lattice columns (product, pointwise, if several).
No `lat`-vs-`rel` keyword split, no parallel `demand`-vs-`demand-lattice`
forms: one orthogonal axis, carried by the type. This is how slog already
works — enums intern because of their *type*, structs nest because of their
*type* — and it makes the demand composition (§3.3) literally zero
special-casing: the generated `f_ans` table has a lattice-typed column, so it
is a map, by the same rule as every other table.

Anonymous inline specs are the same sugar the language already has for nested
unions/structs: `table (dist int int (min int))` declares an anonymous lattice
type in place (as `union (stack (halt) ...)` declares `halt` in place).

Each constructor bundles join kernel + metadata (§3.2):

```
valuespec ::= (min T)                 T ∈ {int, float}; join = min
            | (max T)                 join = max
            | (count)                 0 < 1 < ∞ (abstract counting)
            | (flat T)                ⊥ < v < ⊤, any column type T
            | (bool)                  two-point (≡ presence; the degenerate case)
            | (ps E)                  powerset of enum E (≤ 64 members), bitmask
            | (interval)              int intervals; requires widening (§6)     [v2]
            | (extern name)           plugin-defined join/leq (§7)              [v2]
```

Optional parameters live on the type, declared once: `(min int #:floor 0)`,
`(max int #:ceiling 100)` (clamp = finite-effective-height, §6);
`(interval #:widen-after 3)`.

Rules use full arity; the head **contributes** (merged), the body **binds the
current value**. Base-typed expressions inject implicitly (an `int` contributes
itself to a `cost` position); `count` and `flat` have lattice constants
(`(one)`, `(inf)`, `(top)`) checked by the type system.

**Occurrence restrictions** (the price of inference, all machine-checked):
a lattice type may appear only as a top-level column of a `table` or an answer
column of a `demand`. Not as a struct/union field (interned identity and
merged state are incompatible — the merge would change the content a stored id
points to), not as a demand *input* (demands are interned structs), not as a
key column of another map. Cross-stratum, a lattice value read out of a closed
relation *unwraps* to its base type (a final `cost` is just an `int`), so
downstream code stores snapshots in plain columns naturally.

**The one footgun to document**: giving a column a lattice type changes the
relation's semantics from set to map, silently at the use site. A weighted-EDB
relation `(edge int int cost)` would collapse parallel edges to their min —
almost certainly wrong; edge weights are plain `int`s, `cost` is for the
*derived* map. The type name is the signal (that is why the declaration
carries an honest name), and the same collapse is one keyword away in every
alternative design; but reviews of lattice programs should check column types
first. We considered requiring a per-relation opt-in marker as a guard
(Flix marks every atom with `;`; Soufflé 2.5 marks the attribute with `<>`) —
inference-plus-naming was judged lighter and more slog-like; revisit if
practice disagrees.

### 3.2 What a constructor is (and what `min` is)

`min` today is a value primitive, `(fun A A -> A)`, usable as
`(= x (min a b))`. The lattice constructor `(min int)` *reuses that kernel* as
its join — same u64 function the merge task calls — but a lattice is more than
its join. A constructor bundles:

- the **join kernel** (an existing prim kernel where one exists: min, max,
  bitwise-or for `ps`; equality-plus-⊤ for `flat`; a two-line kernel for
  `count`);
- the **⊥ convention** (absence — never stored);
- the **induced order** `x ⊑ y iff x ⊔ y = y` (derivable from the join; used
  by guards, debug audits, and later by incremental change-splitting);
- **constants** (`(one)`, `(inf)`, `(top)`);
- the **monotonicity table**: which prims are order-preserving transfers for
  this order, which predicates are upward-closed guards (§5.1) — the metadata
  a bare binary function cannot carry, and the reason "point at any prim and
  call it a join" is not the v1 design.

So: the prim and the constructor are two roles sharing one kernel. They also
compose — `(min D x)` applied to a `cost`-typed `D` is a whitelisted monotone
transfer whose runtime call is the very function that implements `cost`'s
merge. Nothing is special-cased twice.

Alternatives considered for the declaration site, for the record:

- **Relation-level keyword** (this document's first draft):
  `lattice (dist int int) (min int)` — the merge declared per relation.
  Subsumed by the type-level form: it repeats the algebra at every relation,
  and composing with `demand` (and any future relation-former) needs a
  parallel declaration form each time, where the type threads through all of
  them for free. Kept only as a possible reading of the inline-anonymous
  sugar.
- **Explicit per-relation opt-in over lattice types** (Flix's `lat`/`;`,
  Soufflé's `<>` attribute suffix): the type carries the algebra, the relation
  additionally marks the merge. Guards the §3.1 footgun at the cost of a
  second annotation that is redundant given the occurrence restrictions (a
  lattice-typed column has no non-merged reading that is ever sound in-SCC,
  and unwraps cross-stratum anyway).
- **Option C — semiring-valued relations (Datalogo).** A genuinely different
  design, not the type-level variant of this one: the value is not a column
  but an annotation on *every tuple*; all columns are keys; and — the crucial
  part — rule *syntax* becomes sum-of-products, with body conjunction
  combining annotations by ⊗ **implicitly** (`T(x,y) ⊕= T(x,z) ⊗ E(z,y)` —
  no `(+ D W)` anywhere; ⊗ = + does it). Pro: sum-product programs get
  shorter, and monotonicity of the combination is a semiring axiom rather
  than a whitelist. Con, and it is decisive for our uses: **one ⊗ per
  program point is not enough.** Abstract counting needs an evolution
  operator (⊕-increment along transitions) *distinct from* the merge
  (max across paths) — §2.3's whole point — and flat-lattice transfer
  functions (`lift2 +`) are not any semiring's ⊗. Column lattices with
  explicit transfers express these directly; Datalogo would need its
  multi-semiring extensions immediately. Add the whole-language shift
  (every relation becomes B-annotated by default, mixing annotated and
  plain relations needs "keys-to-values" bridging) and the non-stable
  semirings reintroducing exactly the divergence we fence off — and the
  verdict is: the runtime built here (key→payload, value-carrying deltas)
  is the substrate Datalogo evaluation would need, so nothing is lost by
  deferring it; the surface is not worth its semantic budget for the
  motivating workloads.

### 3.3 Reserved behavior worth stating

- `facts (dist 3 7 10)` — contributions, like any head.
- A map relation in a body at full arity is the only read form. There is no
  bare-arity "key exists" form in v1 (write `(R k̄ _)`; the wildcard binds the
  value and discards it — the calculus treats a discarded value as unused, so
  this is always legal).
- Lattice-typed columns cannot appear in `struct` declarations (identity is
  content; merged state has none). Maps compose with structs by *containing*
  struct-typed keys or flat-of-struct values.
- CSV output prints one row per key with the final value; `(relation_size R)`
  counts keys.

### 3.4 Composition with `demand` (now automatic)

`demand (f in ...) cost` — an answer column with a lattice type makes the
generated `table (f_ans f cost)` a map keyed by the demand id, **by §3.1's
general rule, with no demand-specific machinery at all**. Ask/resume is
untouched: a resume join binds the current merged answer and re-fires as it
improves. Plain and lattice answer columns may mix (a mix forfeits
one-row-per-demand unless all are lattice). This is the
memoization-of-recursive-functions-over-lattices story — and the automatic
composition is the argument that decided §3.1: declaration forms multiply,
types thread.

---

## 4. Runtime design

The guiding constraint: every choice here must be the one `incremental.md`
§6.1/§7A.7 already reserved space for, so counters and lattice values later
share one representation.

### 4.1 Index payload: key → value

A lattice relation's **master index** becomes a map: B-tree keyed on the key
columns (in master ordering), with a fixed-width **payload** holding the value
word(s) — `tlx::btree_map<std::array<u64,K>, Payload>` beside today's
`btree_set` (`daemon/index.h` grows a payload-carrying sibling of
`BTreeIndex<A>`; the `Index` virtual interface gains nothing — payloads are a
typed-hot-path concern). Values are **word-sized in v1**: min/max int/float are
NaN-boxed words; `count` is a two-state word; `flat T` is the underlying value
word plus a reserved ⊤ pattern; `ps E` is a bitmask; int `interval` packs
2×s32. (Wider payloads — real intervals over floats, product lattices beyond
two words — make the payload width a per-relation constant; the plumbing is the
same. Interned-struct payloads are possible but pay an interning round-trip per
merge; deferred.)

This is precisely the "extensible index-value slot": DRed^c later stores
`(nonrec, rec)` counters in the same payload, and a lattice relation's payload
becomes `(value, counters...)`.

### 4.2 The merge point: a lattice intern task

Merging is interning with a twist, and it lands in the same phase:
`LatticeInternTask<K>` (a sibling of `InternStructTask<N>`, `operators.h`):

```
for each contribution (k̄, v) in the fresh delta:
    look up k̄ in the master map
    absent:            insert (k̄, v);            keep delta record (k̄, v)
    present, old o:    n = o ⊔ v
                       n == o → null the record   (subsumed: no propagation)
                       n != o → payload = n;      rewrite record to (k̄, n)
```

Exactly the struct-intern shape (content-keyed lookup, payload management,
dedup-as-null), with `⊔` where structs have id-allocation. The **rewrite** step
is why deltas are value-carrying: downstream rules must join against the merged
value, not the raw contribution. Debug mode asserts `o ⊑ n` at every merge
(one `leq` call) — for built-in lattices a tautology, for extern lattices (§7)
a cheap continuous audit that the supplied `⊔` really is a join.

### 4.3 Reading and secondary indices

Because the value is functionally determined by the keys, **all indices of a
lattice relation are key-only** (orderings over key columns; the planner's
select sets simply never include value positions in-SCC — the calculus already
forbids value-position join keys there). A body read binds the value by payload
lookup on the matched key — for the master ordering it is the probed leaf
itself; for secondary orderings v1 does one extra master probe per match
(measurable but simple), with payload-mirroring in secondary leaves as the
known optimization when it shows up in a profile.

Emission (`emit`-sink analogue) does no dedup-check against the head index —
subsumption is decided at the merge (the intern phase owns the payload), so the
sink just batches contributions. The write phase inserts *keys* into secondary
indices idempotently, as today.

### 4.4 Deltas, scan/probe drivers, staticness

Unchanged in shape: the delta is the set of changed keys with new values;
`scan` drivers stream them; `probe` drivers hit key-only delta indices;
rules whose driver relation is closed remain once-run static tasks. The
fixpoint's `latest_any_rec` generalizes from "any tuple appeared" to "any tuple
appeared or any payload ascended" — same flag, set by the lattice intern task
on actual change.

### 4.5 Reload, disk, sizes

Reload dumps key+payload rows and re-ingests them as contributions — a merge
against an empty map reproduces the value exactly, so the stratum-boundary
machinery (`Daemon::beginStratum`) is unchanged. BIN format: payload words
appended per row; the manifest records the valuespec so `open` can re-register
it. `tupleCount()` counts keys (btree size, as today). The plugin/action API
needs nothing new; a `sizes`-style action can additionally report e.g.
top-k/⊤-fraction per lattice relation later.

---

## 5. What the type system proves vs. what the user proves

This is the heart of the design. The split falls out of one observation: **all
danger is concentrated in *reading* a lattice value before its relation is
closed.** Writing (contributing) is always safe; reading a final value is
always safe; reading a still-ascending value is safe exactly when every use is
monotone. And "still-ascending vs. closed" is precisely what our Tarjan
stratification already computes, per relation, per rule.

### 5.1 The monotone-use calculus (checked, in-SCC)

For a rule whose body reads lattice relation `R` **in the same SCC** (i.e., `R`
can still ascend while this rule runs), each lattice-typed variable `V` may be
used only as:

1. **a contribution** to a lattice head position of the *same* lattice type,
   possibly through a whitelisted **monotone transfer**:
   - `min`/`max`: `(+ V x)`, `(- V x)` [note: `(- x V)` is antitone — rejected],
     `(min V x)`, `(max V x)`, `(* V c)` for *nonnegative literal* `c`
     (variable multipliers: rejected in v1 — sign unknowable);
   - `count`: `(cplus V V')` (abstract ⊕: 1⊕1=∞; non-idempotent but monotone
     in both arguments — evolution op, distinct from the ⊔ merge);
   - `flat`: identity, and lifted operators (§5.4);
   - `ps`: `(union V x)`, `(intersect V m)` for *constant* mask `m`;
   - any lattice: `V` itself into a matching position; `(glb V V')` (meets are
     monotone in both arguments) — note this is a deliberate *explicit* form:
     in Flix, binding one variable in two lattice body atoms implicitly takes
     their ⊓; in slog the planner normalizes repeated variables to an `==`
     check, which the calculus rejects in-SCC, so the meet must be asked for
     by name. Explicit beats implicit for a merge the reader must reason
     about;
2. **an upward-closed guard** — a test that, once true, stays true as `V`
   ascends:
   - `min`: `(< V c)`, `(<= V c)` with `c` non-lattice ground (improvement only
     strengthens); `(> V c)`, comparisons *between* two live lattice values:
     rejected;
   - `max`: mirrored;
   - `count`: `(cinf? V)`; [`(cone? V)` is downward-closed — rejected in-SCC];
   - `flat`: `(top? V)`; [`(const? V)`, `(= V k)`: rejected in-SCC];
   - `ps`: `(member? e V)`, `(superset? V m)` for constant `m`;
3. **discarded** (`_`).

Everything else is a compile error naming the variable, the lattice, and the
stratum: lattice values may not (in-SCC) appear in plain head columns, in any
key position, in `/=` or `==`, as demand arguments, or under non-whitelisted
primitives. The check is purely syntactic over a fixed table — no SMT, no
analysis — because v1's lattices and transfers are all built-in and their
monotonicity is a *theorem we prove once* (in comments/tests), not per-program.

### 5.2 Why this calculus is the soundness condition, not a style rule

Evaluation never retracts. A non-monotone use — say emitting `(foo X V)` into
a plain relation mid-ascent — would leave one `foo` row per intermediate value:
the result would depend on iteration order and batch boundaries, i.e. it would
not denote the least fixpoint (or anything). A downward-closed guard —
`(cone? V)` mid-ascent — is the ΓCFA strong-update bug: a conclusion fired
under `μ=1` persists after `μ` grows to ∞. The calculus is exactly "every rule
is a monotone map" (§1.3), decomposed syntactically.

### 5.3 Closed relations: everything is allowed (checked, cross-stratum)

Once `R`'s SCC completes, its values are final. A rule in a **later stratum**
may do anything with them: extract into plain columns, use as keys, compare,
negate-by-absence when negation arrives, group, report. The stratification pass
already knows, for every body atom, whether its relation's SCC is the rule's
own or strictly lower — the check is one bit we already compute. This is Tier-1
"stratified aggregation" (`incremental.md` §7A.6) falling out for free, and it
is the type system's answer to the strong-update idiom (§2.3): *the program
that reads μ=1 is forced to be the program where reading μ=1 is sound.*

### 5.4 The `flat` transfer question (open, options)

Constant propagation wants arithmetic *through* the flat lattice:
`⊤ op x = ⊤`, `k op x = (k op x)`. Options:

- **(a) lifted-prim family**: `(flat+ V1 V2)`, `(flat* V1 V2)`, … — explicit,
  trivially checkable, verbose; v1 ships a small set;
- **(b) generic lift**: `(lift2 + V1 V2)` — one form, second-order-ish surface;
  checkable because the lifted op is drawn from the (pure, total) prim table;
- **(c) implicit lifting** — any prim applied to flat values lifts silently;
  concise but hides ⊤-strictness and makes the calculus table implicit.

Recommendation: (b), with (a)'s spelling as sugar if it reads better in
practice.

### 5.5 The user's obligations (the honest list)

| Obligation | When | Mitigation |
|---|---|---|
| **Termination of unbounded ascent** (tropical min/max without floor/ceiling; the negative-cycle problem) | any in-SCC use of `(min T)`/`(max T)` without `#:floor/#:ceiling` | compile-time *warning* naming the relation; `#:floor/#:ceiling` upgrade to a guarantee; a per-key merge-count budget with a runtime fatal is a cheap belt-and-suspenders option |
| **Lattice laws** of an `extern` lattice (⊔ assoc/comm/idem; `leq` agrees with ⊔) | §7 only | debug-mode continuous audit: assert `o ⊑ o⊔v` and `v ⊑ o⊔v` at every merge; sampled assoc/comm checks on observed triples |
| **Monotonicity of `extern` transfers** | §7 only | debug-mode spot checks on observed argument pairs |
| **Abstraction soundness** (the lattice means what the analysis needs it to mean — e.g. `(inf)` really covers "≥2 concrete bindings") | always | not the compiler's to prove; worked idioms in examples/tests are the guardrail |

Everything *not* in this table — functional dependency, merge correctness for
built-ins, monotone use in recursion, extraction discipline, stratification —
is machine-checked.

### 5.6 Where this sits among existing systems (verified)

The checked-vs-trusted spectrum, most-verified first:

| System | Laws (⊔/⊑) | Monotone use | Termination |
|---|---|---|---|
| **Datafun** (ICFP 2016) | by type construction | **type system** (monotonicity modality) | finite semilattice types |
| **slog (this design)** | proven once for built-ins | **whitelist calculus** (syntactic, per-op table) + stratum boundary | height classes + floors/widening/warnings (§6) |
| **Flix + ISSTA'18 verifier** | SMT over `law`-annotated defs (reflexive/antisym/…/least-upper) | `#monotone` annotations, SMT-discharged; head-only transfer positions checked syntactically | user supplies a height function ◇, verifier proves it non-negative + strictly decreasing |
| **Flix PLDI'16 / modern Flix** | trusted ("otherwise … undefined") | transfer-in-head-last-term + monotone filters: positional checks only | finite-height obligation |
| **IncA** (OOPSLA'18) | trusted (Java `leq/lub/glb`) | "IncA does not verify … responsibility of the analysis developer"; SCC checks for usage consistency | finite ascending chains, widening baked into lattice ops |
| **Ascent** (CC 2022) | Rust `Lattice` trait — signatures only | trusted | finite-height obligation (flat-lattice idiom) |
| **Bloom^L**, **egglog**, **Soufflé 2.5 lattices** | trusted (egglog's formal semantics covers only the join-shaped subset of `:merge`) | trusted / n.a. | trusted |
| **Soufflé subsumption** | n.a. (user asserts a dominance order) | trusted | trusted |

The bet this design makes: v1 ships only built-in lattices and transfers whose
laws and monotonicity are theorems proven once, so the *whole* verification
burden collapses into a fixed syntactic table — stronger in practice than
SMT-over-user-code, at the cost of expressiveness that §7's `extern` tier (and
possibly an ISSTA'18-style verifier much later) buys back. Zaniolo's PreM
compiler is precedent for the posture: check a syntactic sufficient condition,
and back the unprovable residue with a runtime "trust-but-verify" mode — our
debug-mode merge audits are exactly that.

A note from Bloom^L worth keeping for the optimizer: it distinguishes
**morphisms** (`g(a ⊔ b) = g(a) ⊔ g(b)`) from merely monotone functions.
A morphism transfer may be applied to each delta contribution independently
(it distributes over the merge); a merely-monotone transfer must read the
merged value — which is why our body atoms bind post-merge values (§1.2/§4.2).
Tagging whitelist entries with morphism-ness later enables a cheaper delta
path without changing semantics.

---

## 6. Termination classes

Checked per declaration; determines what the compiler admits in-SCC:

The theory behind the classes is now crisp (Abo Khamis et al., PODS'22/JACM'24):
Datalog over a partially ordered pre-semiring converges for *every* program iff
the core semiring is **stable**, and converges in ≤ N steps (N = ground IDB
atoms) when it is **0-stable** — which every distributive lattice is, and which
for tropical min-plus holds exactly for **non-negative** weights (Trop⁺). Our
`(min int #:floor 0)` is literally "declare yourself into Trop⁺": the clamp is
not a hack, it is the published convergence condition surfaced as syntax.

| Class | Lattices | In-SCC use |
|---|---|---|
| **Finite height** | `bool` (1), `flat` (2), `count` (2), `ps E` (|E|), products of these; `min/max int` with floor/ceiling (clamped, finite range; float clamps still admit infinite ascent — floats get the *budget* treatment below) | admitted, terminates unconditionally |
| **Bounded-descent obligation** | `(min int)`, `(max int)` bare, float variants | admitted with a warning; user owns termination (documented idiom: floors = Trop⁺, or structurally bounded weights) |
| **Widening** | `interval`, future infinite-height lattices | admitted only with `#:widen-after k`: after `k` genuine ascents on a key, the merge applies the declared widen (interval → ±∞ bounds; generic fallback → ⊤ if the lattice has one) — the abstract-interpretation discipline, per key, mechanically |
| **Budget backstop** (orthogonal, any class) | — | optional per-relation merge budget; exceeding it is a runtime fatal naming the key — turns silent divergence into a diagnosis |

---

## 7. Programmability: what is built in, what the user can build

The gradient, from zero obligations to full trust, is the design's second
load-bearing wall (after the calculus). Each tier is strictly more expressive
and strictly more trusted than the last:

**Tier 0 — built-in constructors over built-in scalars** (`(min int)`,
`(max float)`, `(count)`, `(bool)`): laws and monotonicity tables are theorems
proven once, in the compiler's whitelist and its test suite. Zero user
obligations beyond §5.5's termination row.

**Tier 1 — built-in constructors over USER types** — already genuinely
programmable, and easy to underestimate: `(flat T)` lifts *any* slog type
including user structs and unions (constant propagation over your own IR's
terms — the join only needs equality of interned words); `(ps E)` is the
powerset of *your* enum (reaching-definitions, effect sets); products via
multiple lattice-typed columns; and v2 composition candidates like
`(lex (min int) (flat T))` — lexicographic pairing whose join keeps the
witness at strictly-better cost and flat-merges at ties, i.e. shortest-path
*with evidence*, the packed-forest trick from `dem_sppf` transported to
optimization. All of Tier 1 keeps zero proof obligations: the constructors'
laws are parametric in the payload type, and the monotonicity tables compose
mechanically.

**Tier 2 — new transfers/guards over existing lattices**: the whitelist is
*data* (a table in the compiler keyed by lattice constructor), and the
intended early contribution path is adding a row plus a prim kernel plus a
one-off monotonicity argument in the test suite — a pull-request-sized unit,
not a language change.

**Tier 3 — `extern`: user-defined algebras via the plugin route** (v2, below):
new joins as native code, laws trusted + audited.

**Tier 4 — verified user algebras** (research tail): an ISSTA'18-style SMT
verifier over a restricted kernel language for extern joins/transfers
(`law`-style annotations, height-function termination proofs), or
Datafun-style monotonicity typing if slog ever grows a function sublanguage.
Rule-*defined* joins (a `demand (join L L) L` judgment as the merge) are noted
and rejected for the merge path — the merge runs inside the intern phase and
cannot re-enter rule evaluation; revisit only if a two-phase propose/normalize
evaluation ever exists.

### 7.1 The `extern` tier concretely

The daemon's plugin architecture (everything is a `.so` calling the Daemon API)
gives `extern` lattices a natural shape with no interpreter in the merge path:

```
lattice (simord (extern simord))
table   (sim node node simord)
```

compiles against a lattice *registered by name*: a small hand-written plugin
`.so` calls `d->db()->registerLattice("simord", join_fn, leq_fn)` (function
pointers over `u64` payload words) before the strata that use it; the compiler
emits merge tasks that call through the registration. The driver just sends the
plugin's path first — the protocol already does this. User obligations and the
debug-mode audits are §5.5's. Whitelisted extern *transfers* register the same
way, each tagged with the per-argument monotonicity the calculus should assume
(trusted, spot-checked).

Precedent (verified): Soufflé 2.5 (March 2025) shipped exactly this shape —
`.lattice Interval<> { Bottom -> ..., Top -> ..., Lub -> @lub(_,_), ... }`
with `Lub` an opaque user-defined C++ functor, relation attributes marked
lattice-valued by an auxiliary-arity type suffix, per-key lub folded into
semi-naïve rounds, laws entirely trusted, and lattice attributes and
subsumptive rules mutually exclusive on one relation. Our plugin registration
is the same trust model with the audits of §5.5 added; our built-in tier is
what Soufflé doesn't have.

The tempting third tier — lattices whose ⊔ is *defined by slog rules* (a
`demand (join L L) L` judgment) — is noted and rejected for the merge path:
the merge runs inside the intern phase and cannot re-enter rule evaluation.
(A desugaring into plain relations + subsumption cannot express "keep only the
join" without negation or choice.) Revisit if a two-phase "propose then
normalize" evaluation ever exists.

---

## 8. Compiler pipeline: where each piece lands

Small, additive, and follows the `demand` precedent at every step:

- **parser.rkt** — `lattice` top-level form (signature clause + valuespec list,
  like `demand`).
- **modules.rkt** — declaration extraction into the rel-env as
  `(lattice (keytypes ...) (valuespecs ...))`; manifest entries carry the
  valuespec (open/reload need it); demand integration: answer valuespecs
  redirect the generated `_ans` table to a lattice declaration.
- **type-system.rkt** — key/value typing; injection typing for value
  expressions; lattice constants (`one`/`inf`/`top`); **the monotone-use
  calculus** (§5.1) — runs after stratification in pipeline order today, so
  either the calculus becomes a small post-stratify check pass (cleanest:
  `lattice-check.rkt`, one pass over strata, reusing `rule-body-rels`/SCC
  info), or typecheck records candidate uses and the check resolves them
  against strata. Prefer the dedicated pass.
- **stratify.rkt** — unchanged (lattice rels are nodes like any other); it
  already produces exactly the same-SCC bit the calculus consumes.
- **join-planning.rkt** — value columns never become join keys in-SCC
  (calculus guarantees the shape; planner asserts); a lattice body atom's value
  var is bound-by-payload, not by index column — a new tuple-shape detail in
  `join-tuple`/select-set construction (key columns only).
- **operationalization.rkt** — decl lowering `(lattice name K payload-spec
  idx...)`; key-only select sets; c-IR: `(merge R idx k̄ v)` head op (replacing
  `emit` for lattice heads), body `(join ...)` op gains a bind-payload slot.
- **emit-cpp.rkt** — `LatticeInternTask<K>` instantiation per relation/bucket;
  payload-map master index registration; merge-sink emission; payload binding
  in probe continuations.
- **daemon** — `index.h`: payload B-tree sibling + `Index` size/clear/forEach
  already generic; `operators.h`: `LatticeInternTask<K>`, `merge` sink,
  payload-binding probe variant; `database.h`: BIN read/write payload columns;
  `registerLattice` (v2).

Nothing in the demand transform, stratifier, or driver changes.

---

## 9. Testing plan

- **Goldens with hand-derived answers**: shortest path on a worked graph
  (incl. a cycle with nonneg weights, and a `#:floor` negative-cycle case);
  constant-prop on a straight-line + branchy mini-IR (exact ⊤/constant rows);
  abstract counting on a bind-event log (`one`/`inf` per address); min-cost
  parse (demand composition) on the demand.md grammar with weighted tokens.
- **Differential tests**: random graphs, `dist` vs. a Racket Dijkstra oracle
  in the test harness; random flat-lattice dataflow vs. a reference
  interpreter.
- **Calculus tests**: a battery of *rejected* programs (each §5.1 violation,
  each with the intended error message) — the type system's behavior is
  product surface here, test it like one.
- **Unit tests**: merge-task semantics (subsume/ascend/insert), value-carrying
  delta plumbing, reload/BIN round-trip of payloads, widening triggers.
- **Idempotence audits**: run every lattice test twice through reload cycles
  (multi-strata programs already do) and assert identical final CSVs.

---

## 10. Incrementality tee-up (explicitly out of scope, explicitly anticipated)

What this design leaves in place for `incremental.md` M6/M7:

- **Shared payload slot** (§4.1): `(value)` today, `(value, nonrec, rec)`
  under DRed^c — one map, one leaf layout discipline.
- **Value-carrying deltas** (§1.4): the signed delta records DRed^c needs are
  these records plus a sign; a lattice value *change* under deletion becomes
  `retract-old + insert-new` in the same transport (§7A.2 of incremental.md).
  **Sharpened by IncA's DRed_L (verified):** the transport should carry the
  *replacement pair* `(key, old, new)`, not two independent signed records —
  DRed_L's central move ("change splitting") recognizes `old ⊑ new`
  replacements and routes them through the **monotone** phase (no over-delete,
  no rederivation cone); only genuinely ⊑-decreasing changes enter the
  DRed-style negative fixpoint. Feeding `−(key,old)` into DRed^c's negative
  phase as if it were a plain deletion would tear down and rebuild the cone of
  every ordinary improvement — the pair format is what prevents that, and it
  costs nothing to adopt now.
- **The repair problem is named and isolated**: deleting a contribution that
  supplied the current min = decremental-SSSP = the foundedness-rank repair
  (§7A.3/§7A.4) — the merge task is the single place a "recompute this key
  from surviving contributions" hook attaches (IncA's DRed_L and
  Palpanas-style per-group multisets are the two known price points; LADDDER
  (PLDI 2021) is the differential-dataflow-side alternative, with two ideas
  worth remembering: *eventual/per-relation* monotonicity — required only at
  one "cut" of each recursive component rather than per rule — and an
  inflationary aggregation semantics that never retracts along the iteration
  axis. Choosing among these is M7's decision, not this design's).
- **A condition to watch**: IncA imposes *aggregation exclusivity* (alternative
  rule bodies for an aggregated relation must derive disjoint results) to
  prevent "cyclic reinforcement" during incremental maintenance. Batch lattice
  semantics needs no such condition (⊔ is idempotent; contributions are not
  counted) — but M7 should revisit whether slog's per-key repair needs it or
  whether the DRed^c candidate-set machinery subsumes it.
- **The calculus is reusable**: DRed^c's over-delete/rederive inside an SCC is
  sound for lattice relations exactly when in-SCC uses are monotone — the same
  check, already enforced.

What this design deliberately does *not* do for incrementality: track
per-contribution support, keep contributor multisets, or store per-key
provenance. Those are M7 costs to pay when deletion arrives, behind the same
payload abstraction.

---

## 11. Milestones

1. **L0 — Core lattices, end to end.** `lattice` decl (parser/modules/rel-env);
   typing + monotone-use calculus + stratum checks (`lattice-check.rkt`);
   payload index + `LatticeInternTask` + merge sink + payload-binding probes;
   value-carrying deltas; `(min|max int|float)`, `(count)`, `(flat T)`,
   `(bool)`; BIN/CSV/reload/sizes support. Tests: sssp, constprop, counting,
   rejection battery. (Recursive and stratified use both — same machinery.)
2. **L1 — Demand composition.** Lattice-valued answer columns; min-cost
   parsing example; memoized-function idiom docs.
3. **L2 — More lattices.** `(ps E)` bitmask; `(interval #:widen-after k)` +
   widening machinery; floors/ceilings; product (multi-valuespec) polish;
   `lift2` flat transfers.
4. **L3 — Extern lattices.** `registerLattice` plugin route; debug-mode law
   audits; extern transfer registration with monotonicity tags.
5. **L4 — Incrementality** (= incremental.md M6/M7; not this document).

---

## 12. Decision summary (the options, with recommendations)

| Decision | Options | Recommendation |
|---|---|---|
| Surface form | (A′) `lattice` declares a value **type**; relations/demands with lattice-typed columns are maps automatically (inline anonymous specs as sugar); (A) relation-level `lattice` keyword; (B′) lattice types + per-relation opt-in marker (Flix/Soufflé); (C) semiring-valued relations | **A′** — one orthogonal axis, threads through `table`/`demand`/future forms with zero special-casing; occurrence restrictions make the inference unambiguous; C is a future reading whose runtime this design already builds |
| Body-read semantics | current-value binding (Flix) vs. contribution enumeration | **current-value** — contributions are not observable; anything else breaks the FD |
| Monotonicity enforcement | syntactic whitelist calculus; SMT verification (Flix PLDI'16); trust-the-user (Souffle subsumption) | **whitelist calculus** for v1 (zero proof burden, built-ins only); SMT worth revisiting only for `extern` |
| Non-monotone reads | reject vs. allow-with-annotation | **reject in-SCC, free cross-stratum** — the stratifier already gives the boundary; add an `unsafe` escape only if practice demands |
| Value storage | payload map (key→value) vs. value-in-key + subsumption deletion (Souffle-style) | **payload map** — no in-index deletion on the hot path, aligns with DRed^c counters |
| Merge point | intern phase task | **yes** — same phase and shape as struct interning |
| Custom lattices | built-ins only → plugin `extern` → rule-defined joins | **built-ins v1, plugin v2**; rule-defined rejected for the merge path |
| Termination | finite-height only vs. obligations + floors/widening | **admit tropical with warning + optional floor/budget; widening for interval** |
| Non-idempotent aggregates (SUM/COUNT) | in this feature vs. separate | **separate** (stratified-only, incremental.md Tier 1/M6) — mixing them into `lattice` would smuggle unsoundness into the keyword whose whole point is soundness |

---

## 13. References

All web-verified during this design pass unless noted.

**Lattice-typed Datalog:**

- M. Madsen, M.-H. Yee, O. Lhoták. *From Datalog to Flix: A Declarative
  Language for Fixed Points on Lattices.* PLDI 2016. (`lat` decls, last column
  = lattice, cells/compact interpretations, glb-within-a-rule vs
  lub-across-rules, transfer-only-in-head-last-term, monotone filters, the
  lattice semi-naive delta = strictly-increased cells carrying *merged*
  values. Laws trusted in 2016: "otherwise … undefined".)
- M. Madsen, O. Lhoták. *Safe and Sound Program Analysis with Flix.* ISSTA
  2018. (`law`-annotated lattice components verified by SMT; termination via a
  user-supplied height function ◇ proven non-negative + strictly decreasing —
  the model for a future `extern`-lattice verifier.)
- M. Madsen, O. Lhoták. *Flix: A Design for Language-Integrated Datalog.*
  OOPSLA 2025. (First-class Datalog values; modern semicolon lattice syntax
  `Dist(y; v)`; nominal `lat` decls retired for structural row types.)
- A. Sahebolamri, T. Gilray, K. Micinski. *Seamless Deductive Inference via
  Macros.* CC 2022. (Ascent: `lattice` keyword, partial-map semantics, last
  column implements a `Lattice` trait, `Dual<T>` for min-as-max, in-place
  `join_mut` with change-flag-driven semi-naive; the flat-lattice CESK-store
  idiom for bounding abstract-machine divergence — the house lineage.)
- N. Conway, W. Marczak, P. Alvaro, J. Hellerstein, D. Maier. *Logic and
  Lattices for Distributed Programming.* SoCC 2012. (Bloom^L: built-in lattice
  library; `morph` vs `monotone` declarations — the delta-optimization
  distinction; lbag's max-multiplicity merge as the idempotent stand-in for
  sum.)
- Soufflé 2.5 (2025-03): `.lattice T<> { Bottom/Top/Lub/Glb/Leq -> functors }`
  + auxiliary-arity lattice attributes; laws trusted; exclusive with
  subsumption. Soufflé ≥2.2 subsumption: `R(x1) <= R(x2) :- body` — dominated
  newcomers filtered from the delta, dominated incumbents physically erased at
  iteration boundaries, consequences never retracted.
- Y. Zhang, Y. R. Wang, O. Flatt, D. Cao, P. Zucker, E. Rosenthal, Z. Tatlock,
  M. Willsey. *Better Together: Unifying Datalog and Equality Saturation.*
  PLDI 2023. (egglog `:merge`; formal guarantees cover only the
  lattice-join-shaped subset; the inflationary-semantics framing of
  non-monotone merges.)
- M. Arntzenius, N. Krishnaswami. *Datafun: A Functional Datalog.* ICFP 2016.
  (Monotonicity in the type system — the most-checked pole of §5.6.)
  [recall-only]

**Semantics and convergence:**

- K. Ross, Y. Sagiv. *Monotonic Aggregation in Deductive Databases.* PODS 1992
  / JCSS 54(1) 1997. (Cost-consistency = the per-key functional dependency;
  minimal models over the specialized lattice order — the semantics §1 adopts.
  Van Gelder's DOOD 1993 critique — the right lattices can't be inferred — is
  the argument for built-in constructors.)
- C. Zaniolo, M. Yang, M. Interlandi, A. Das, A. Shkapsky, T. Condie.
  *Fixpoint Semantics and Optimization of Recursive Datalog Programs with
  Aggregates.* TPLP 17(5-6), 2017. (PreM: γ(T(I)) = γ(T(γ(I))); compiler
  checks the syntactic inflation/deflation-preservation sufficient condition;
  "trust-but-verify" runtime reporting — precedent for §5.5's audits.)
- M. Abo Khamis, H. Q. Ngo, R. Pichler, D. Suciu, Y. R. Wang. *Convergence of
  Datalog over (Pre-)Semirings.* PODS 2022 / JACM 71(2) 2024. (Stability;
  0-stability ⇔ ≤N-step convergence, satisfied by every distributive lattice
  and by Trop⁺ — nonnegative min-plus — which is exactly `#:floor`;
  the semi-naive-with-⊖ correctness frame over distributive dioids.)
- T. J. Green, G. Karvounarakis, V. Tannen. *Provenance Semirings.* PODS 2007.
  (The contrast case: ℕ-like semirings track how-many/which derivations —
  ω-continuity, convergence only in the limit; lattices track a best value —
  finite convergence. Same boundary as incremental.md §1.)

**Incrementality (the M7 shelf):**

- T. Szabó, G. Bergmann, S. Erdweg, M. Voelter. *Incrementalizing Lattice-Based
  Program Analyses in Datalog.* OOPSLA 2018. (IncA/DRed_L: lattice decls with
  trusted Java ops; SCC-checked usage; aggregation exclusivity against cyclic
  reinforcement; **change splitting** — ⊑-increasing replacements bypass the
  deletion machinery.)
- T. Szabó, S. Erdweg, G. Bergmann. *Incremental Whole-Program Analysis in
  Datalog with Lattices.* PLDI 2021. (LADDDER: differential-dataflow substrate;
  eventual/per-relation monotonicity via "cuts"; inflationary aggregation
  along the iteration axis.)

**Abstract interpretation / AAM:**

- M. Might, O. Shivers. *Improving Flow Analyses via ΓCFA.* ICFP 2006; JFP
  18(5-6) 2008. (N̂ = {0,1,∞}, ⊑=≤, ⊔=max, evolution by abstract increment ⊕;
  pinching theorems: μ̂=1 ⇒ must-alias ⇒ strong update licensed; abstract GC
  resets counts.)
- D. Van Horn, M. Might. *Abstracting Abstract Machines.* ICFP 2010.
  (Store-as-map-to-powerset = plain slog relations; counting is the
  instrumentation that does not come for free.)
