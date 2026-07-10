# First-Class Finite Sets, Maps, and Lists

**Status:** largely IMPLEMENTED as of 2026-07 — finite sets, maps, and lists
ship as first-class values (see `lib/{set,map,list}.slog`, the `cset`/`cmap`/
`cnode` collection machinery in the daemon, and tutorial chapters 5 and 7); the
per-section `STATUS: SHIPPED` markers in the body reflect what has landed. This
doc records the original design and the architectural tension. It
lays out the data structures, the compiler/daemon touch-points, the
index-generation and splice semantics, and — most importantly — the one
architectural tension that decides how ambitious the feature can be. It builds
on `docs/lattices.md` (the lattice-column machinery this reuses), `docs/demand.md`
(the recursive-judgment access layer), and `docs/incremental.md` (deletion,
which the same representation must not preclude).

Companion goal, stated once: we want finite **sets**, **maps**, and **lists** as
*canonicalizing, hash-consed (interned) functional tree values* that (a) are
ordinary column values — buildable, nestable, keyable, comparable — and (b) can
serve as **lattice columns** whose merge (set-union, pointwise map-merge) runs as
a **native routine at the lattice-merge point, within a single fixpoint
iteration**, and that (c) can be **joined on by partially-ground patterns**
(`[a b c d e ...]` with `c,d` ground; `{a:b | rest}`).

---

## 1. The two roles a collection value plays

Everything downstream turns on separating two uses that look the same but have
opposite runtime requirements — the same split we drew for the `ps` bitmask
lattice, now for heap-sized values:

- **Immutable-value role.** A collection you *build, pass, nest, key by, compare
  by identity, and deconstruct*. This is exactly what a **struct** already is:
  an interned, content-addressed, immutable word. It is queryable (joinable)
  because interned structs live in b-tree indices. It is produced and consumed
  *across* fixpoint iterations.

- **Lattice-column role.** A collection that is the value of a *map keyed by
  other columns*, auto-merged by `⊔` (union / pointwise) on every contribution,
  read at its current merged value inside a recursive fixpoint. This is what
  `docs/lattices.md` builds, and its merge runs *within one iteration* at the
  intern phase.

These map onto Slog's **two existing interners**, which sit at opposite ends of a
tradeoff, and the central design problem (§9) is that a first-class collection
wants properties from both:

| interner | where | joinable (b-tree indices)? | re-entrant mid-phase / any-thread? |
|---|---|---|---|
| **struct interner** (per-relation b-tree, per-bucket single-owner, `phase_intern`) — `operators.h:377-426`, `database.h:100,231-234` | structs, lattice payloads | **yes** — that is the whole point of the master/lookup indices | **no** — safe only under single-owner-per-(relation,bucket); mid-phase recursive interning across buckets/relations races |
| **global interner** `InternTable<T>` (lock-free, atomic CAS, content-addressed) — `intern.h:54-395`, `types.h:62` | strings, bigints | **no** — not indexed for content joins | **yes** — interns inline from any thread in any phase, no hazard |

A canonical collection wants **both**: a mergeable canonical id you can build
mid-merge (the global interner's property) *and* structural joinability on its
contents (the struct interner's property). No path gives both today. §9 proposes
how to reconcile them; §10 phases the work so the early wins don't require it.

---

## 2. Representations (the data structures)

Canonicalization is a **gate, not a tradeoff**: for hash-consing to give
value-equality, *equal content must force one identical tree shape regardless of
construction order*. A structure that fails this is disqualified as an interned
value no matter how fast it is, because two equal collections would intern to
different ids and every downstream `==`/join/key would be wrong.

Slog already interns every element/key to a word-sized id, so *elements are dense
64-bit words* — which makes integer-keyed tries the natural fit.

### 2.1 Sets and maps → big-endian Patricia tries (Okasaki–Gill)

**Recommendation: one engine for both — a big-endian Patricia/radix trie keyed on
the interned element/key word** ("Fast Mergeable Integer Maps"; a set is a
map-to-unit). Why it wins on every criterion at once:

- **Canonical by construction.** A Patricia trie's shape is a function of its
  key-set alone — branch points are determined by shared key-bit prefixes, not
  insertion order. No rebalancing choices exist to introduce shape variance.
- **Merge = the semilattice join, and it is incremental-friendly.** `merge`/
  `union`/`mergeWithKey` is a parallel prefix walk that **returns physically-equal
  common subtrees untouched** → near-O(difference), and it *shares structure with
  the delta*. Pointwise map-merge combines colliding leaves by the **value
  column's own lattice join** — nested lattices compose (this is egglog's and
  Flix's model).
- **Interns bottom-up, gives O(1) equality.** Each node is a small struct
  (`branch(prefix, mask, left-id, right-id)` / `leaf(key, val)`); children are
  interned before parents; hash-consing then makes physical-eq = value-eq.

**Node = a struct relation; child pointers = child struct-ids in field slots**
(§9) — so within a single run, content-dedup on the master index *already* gives
canonical hash-consing for free (`operators.h:403-421`). CHAMP (compressed HAMT)
is the upgrade path if memory/iteration throughput dominates (canonical, more
compact, more implementation/verification cost). Plain BST/HAMT are **not**
canonical (shape depends on history / tombstones); a deterministic-priority
treap/zip-tree is the only canonical BST variant. Sorted-vector is canonical but
copies whole arrays (no subtree sharing) — fine only for tiny frozen sets.

> Verification note: the original Okasaki–Gill merge had a bug found in 2017
> (Midtgaard, *QuickChecking Patricia Trees*). Property-test the merge; do not
> transcribe the paper blindly. If keying by *hash* rather than dense id, handle
> collisions with a collision leaf whose contents are themselves canonicalized
> (sorted), or non-canonicity sneaks back in.

### 2.2 Sequences → BOTH: cons `(list T)` and strict radix-balanced `(vec T)`, as siblings

> **SUPERSEDED (2026-07-08, docs/sequences.md — S1 SHIPPED).**  The
> cons/(vec T) compromise below is retired: `[T]` is now ONE type backed by
> a content-defined-chunked Merkle tree ("prolly tree") in its own arena —
> canonical (the same gate) with expected-O(log n) point AND bulk ops,
> which dissolves the mutual-exclusion premise this section reasons from
> (boundaries become a function of CONTENT, so relaxed balance is not
> needed for cheap concat).  The builtin cons/nil union is gone (names
> stay reserved); the cons library survives as the differential oracle
> (tests/oracle/list-cons.slog).  This section stays as the design record
> of why the two canonical position-keyed representations were mirror
> images — the argument that motivated the chunked escape.

First, the disqualification that stands regardless: **canonicity and cheap
concat are mutually exclusive for balanced sequence trees.** RRB-trees get
O(log n) concat/split *precisely by relaxing balance*, admitting multiple shapes
per sequence — out, by the gate.

Among canonical representations there are two, and they are **mirror images**;
the decisive axis is *build direction*:

| | **hash-consed cons** | **strict radix-balanced vector** (Clojure-style, not relaxed) |
|---|---|---|
| canonical? | trivially (one spine per sequence) | yes — shape is a function of length alone (strict left-fill) |
| cheap end | **front**: O(1) cons, O(1) `[x \| rest]` deconstruct | **back**: amortized O(1) push/pop-tail |
| costly end | append/index/update O(n) | prepend O(n) rebuild |
| ref / update | O(n) | **O(log₃₂ n)** |
| sharing | **maximal suffix sharing** across different lists | prefix sharing under append-accumulation |
| head-first recursion (`(map f (cons x xs) (cons y ys))` — the style of every `dem_*` example) | O(1)/step, full sharing across intermediates | O(n)/step, **no sharing** (front-extension rebuilds) |
| accumulator / append-at-end style | O(n)/step, no sharing | O(1)/step, prefix sharing |

Neither dominates; they are the Lisp/Clojure list-vs-vector split, for the same
reasons. And since the node arena (§9) is polymorphic over node kinds *anyway*
(trie branch/leaf, cons, vector node — one interner, many types), the marginal
cost of shipping both is small. So: **`(list T)` = hash-consed cons** (the
default; the natural recursion/pattern type), **`(vec T)` = strict radix-balanced
vector** (random access, back-heavy workloads), both canonical, both interned in
the same arena, both getting decomposition indices (§4.2).

Two sequence-specific notes for the join story (details in §4.2):

- Flat occurrence indices are **representation-agnostic** — `list_at(val, pos,
  list_id)` doesn't navigate the tree, so back-position joins work atop cons
  exactly as well as atop a vector. The representation decides *native-op* cost
  and sharing, not join expressibility.
- Cons gets one elegant back-access bonus from maximal suffix sharing: a
  **fully-ground back pattern** `[x ... y z]` (y, z ground) *is a single
  interned id* — the suffix `[y z]` is one shared node — compiled to one probe
  against a tail-reachability (`tail*`) relation. Vectors answer the same
  pattern natively (`ref` at len−1, len−2, O(log n)) but need the inverted
  occurrence index for the *join* direction just like cons.

If concat-heavy sequence algebra is ever needed, expose it as a *non-interned
transient* canonicalized (rebuilt into cons or strict-radix) at intern time.

---

## 3. Surface syntax

**The lexer and parser already emit the brackets** — this is not new lexing work.
`[ … ]` → `(syn … [] …)`, `{ … }` → `(syn … {} …)` (`parser.rkt:179-190`), with
`|` (`lexer.rkt:52`), `:` and `...` as operator tokens. Today they die downstream
with "Type `[]` was never declared" (`type-system.rkt:220`). The new work is a
**desugaring pass** (§8) that rewrites these into constructor/deconstructor terms.

Intended surface:

```
[a b c]            a 3-element list                     -> (cons a (cons b (cons c (nil))))
[a b | T]          list with head a,b and tail T        -> (cons a (cons b T))
{a b c}            a set                                 -> (set-of a b c)
{a | rest}         set containing a, rest = the others
{a:b c:d}          a map with two entries
{a:b | mp}         map mp functionally updated with a->b -> (map-put mp a b)
```

and the **same forms are patterns in a body** (deconstruction), exactly as
`(cons a b)` is used both ways today.

**Parse gotchas that must be handled by the desugar pass (all grounded):**

- **RESOLVED (2026-07-05): the extension base is a postfix `...` on the final
  element** — `[a b t ...]`, `{x y s ...}`, `{k:v m ...}` — which parses as
  `(... t)` wrapping only the last element, has no other meaning in the
  language, and is inert to the or-splitter. The earlier `|` syntax was
  triple-overloaded (clause-level or-split, nested or-split, tail) and bound
  only its neighbours (`[a b | T]` parsed as `([] a (| b T))`), forcing
  reassociation and hazard defenses; a pipe in a bracket/brace spine now
  errors with a migration hint (letting it through would hand
  `split-or-clauses` a silent cartesian split). `[t ...]`/`{s ...}` are
  identity extensions; a base that is a `k:v` pair errors.
- **`:` binds tighter than `|`** — so `{a:b | rest}` groups the pair correctly as
  `({} (| (: a b) rest))`. Good, but `:` is now claimed globally (watch future
  type-ascription uses; `:=` is a separate token, no clash).
- **`{}` is ambiguous** (empty set vs empty map) — needs a disambiguator
  (`{:}` for the empty map, or type-directed).
- **`[…]` defaults to `(list T)`**; `(vec T)` gets either a distinct literal
  (`#[…]`) or type-directed resolution from the column type. Since both are
  canonical interned values, the choice is per-type, not per-occurrence.
- **At most one rest/splice var** (§4.3); reject `[a... b...]` and `{|r1|r2}`.

---

## 4. Using collections

### 4.1 Construction (heads)

- **Lists**: `[a b | T]` desugars to nested `(cons …)` head constructions.
  These ride the *existing* head-staging + interning path with **zero engine
  change** (`join-planning.rkt:124-192`, `emit_struct`/`InternStructTask`,
  `operators.h:184-198,377-422`).
- **Sets/maps**: `{a:b | mp}` = a functional update `(map-put mp a b)`; a set/map
  literal = a fold of inserts. These produce a **canonical** trie, which naive
  `cons`/`mapnode` construction does **not** — a normalize step must run before
  interning (§2, §9). Whether that normalize is a `demand` stdlib routine
  (cross-iteration, available now) or a native prim (single-iteration) is the
  phase question (§10).

### 4.2 Deconstruction / joining on patterns → a *spectrum* of compilations

A partially-ground collection pattern in a body compiles to relational access —
never to structural unification. But "generate a flat occurrence table" is only
one point on a spectrum, and choosing the right point per pattern is what keeps
costs sane. Ordered from cheapest:

1. **Bound-element membership → a native guard, no table at all.** `member? e S`
   with `e` and `S` bound is an O(W) tree walk — a guard like `<` or the
   semijoin `exists_probe`. Nothing is materialized.
2. **Ground-suffix probe (cons speciality).** A fully-ground trailing pattern
   `[x ... y z]` is one interned id (§2.2); compile to a single probe on a
   `tail*(suffix_id, list_id)` reachability relation.
3. **Enumeration via demand judgments over nodes.** When a pattern *enumerates*
   a bound collection's members (`{k:v | rest}` with `k` free, collection
   bound), a memoized demand judgment walking the tree's nodes enumerates
   entries without materializing any per-value flat table.
4. **Flat occurrence tables — the inverted direction.** The one case that
   genuinely needs a materialized index is the *inverted* join: "which
   collections contain `e` / have `v` at position `p`?" (collection **unbound**).
   These are the generated relations, indexed by the existing machinery
   (`BTreeIndex`, select-sets, `find-index`, `join_probe`, min-chain-cover —
   no new read-side runtime):

   | pattern | decomposition relation | probe |
   |---|---|---|
   | which sets contain ground `e` | `set_has(elem, set_id)` | K=1 on `elem` → bind `set_id` |
   | `{a:b}` join, key ground, map unbound | `map_at(key, val, map_id)` | K=1/2 → bind `val`/`map_id` |
   | list positions `c,d` ground (`[_ _ c d _ ...]`) | `list_at(val, pos, list_id)` | two probes joined on `list_id` (the planner's existing shared-var path) |

   The `(lists c d [...])` intuition is exactly this, generalized: per-`(pos,val)`
   occurrence rows + planner intersection on the shared collection id, with
   min-chain-cover fusing hot multi-position patterns into composite orderings.
   Same scheme for all kinds. Because these tables are the expensive point of
   the spectrum (§5), they are generated **need-driven** — only for the
   kind/pattern shapes actually joined on, like semijoin index requisition.

**The relation-key decomposition (lattice role) — a different, cheaper animal.**
When the collection is a **lattice column** `R(k̄, S)` (S ascending), do not
decompose by collection id at all — decompose by the *relation key*:

```
R_has(k̄, elem)     ;; generated: elem ∈ current S at key k̄
```

`R_has` is an ordinary **monotone growing relation**: as `S` ascends, elements
are only added, never removed. Its deltas are exactly the tree-diff of
`(old, new)` — O(change) via the Patricia physical-equality short-circuit — and
semi-naive drives dependents off them natively. No per-version blowup (§5), no
new runtime concept. And it has a semantic payoff, noted in §7: it makes in-SCC
*enumeration* of an ascending set sound.

**Bucket-skew caveat (design-relevant):** a bucket is `buckethash(key[0])`
(`operators.h:61`), so an ordering **led by `pos`** (a handful of small ints)
skews catastrophically. **Lead structural indices with the high-cardinality value
column** — `set_has(elem, set_id)`, `list_at(val, pos, list_id)` — so the natural
probe stays well distributed.

### 4.3 The AC restriction (why we do *not* build a unifier)

Matching `{a:b | rest}` with an **unground key** is set/associative-commutative
matching. **Set-matching and set-unification are NP-complete** (Kapur–Narendran);
a complete set of AC-unifiers is doubly-exponential. So we do **not** implement
AC-unification. We restrict collection patterns to the cases that compile to
lookup or bounded iteration (the Maude/rewriting practice):

1. **fully-ground key** → point lookup, O(W);
2. **single member + rest** (`{k:v | rest}`, `[x | rest]`, exactly one unground
   member) → enumerate the collection's entries (bounded fan-out = |collection|),
   binding `k,v`/`x` and `rest` = the remainder;
3. **forbid** multiple simultaneous rest/unground patterns against one collection
   (splitting into two unknown halves) — that is where the exponential lives.

So a splice is one rest var. For lists it's the tail (cheap cons deconstruct).
For sets/maps `rest` = *collection minus the entry* = another canonical id — a
native set-difference (or a decomposition relation carrying the residual,
`map_entry(map_id, key, val, rest_id)`), **not** a b-tree prefix probe. This
residual/tree-navigation is the one thing the occurrence-relation model does not
cover for free (§9, tension 3).

---

## 5. Structural indices: the real cost is write-side maintenance

The read side of §4.2 is nearly free. The hard part, per the grounding, is
**maintaining the decomposition relations**: there is *no* automatic
secondary-relation maintenance today — struct interning fans nothing out into
per-element tuples. So we need new **write-side** machinery:

- At collection **construction/intern**, emit one occurrence tuple per
  element/entry/position (a companion generated rule, or an extension of the
  intern task analogous to `emit_struct`), and these must flow through the
  **normal delta pipeline** so semi-naive dependents re-fire
  (`join-planning.rkt:245` drives off deltas).
- For a collection used as a **lattice-merge column**, the merge yields a single
  merged value word (the canonical id), *not* membership tuples — so a follow-on
  task must publish `set_has(new_id, elem)` for the merged members, again through
  the delta pipeline. This is precisely the DRed_L / change-splitting concern in
  `docs/incremental.md`.

**Cost analysis, sharpened.** The blowup afflicts exactly one point of §4.2's
spectrum, and only in one role:

- **Value role, inverted tables: the blowup is real and structural.** A flat
  table keyed by *collection id* is inherently O(|S|) rows per **distinct
  value** — tree sharing does NOT transfer to the flat index, because the rows
  are keyed by the new id. An ascending chain of values S ⊂ S∪{a} ⊂ … (each a
  distinct interned id) materializes O(n²) rows. This is why the spectrum
  routes everything it can to guards, ground-suffix probes, and node-walking
  demand judgments, and generates inverted tables only need-driven.
- **Lattice role: the blowup does not exist.** `R_has(k̄, elem)` is keyed by the
  *relation key*, which is stable across the value's ascent; each element is one
  row, ever, and each ascent contributes only the diff. Total size =
  |final set| per key — the same as the relation's own semantics. This is a
  strong reason to *keep* collections as lattice values rather than desugaring
  to per-version struct ids (§8.4).

---

## 6. The lattice-column merge (the payoff, and the hard part)

The fit at the seams is genuinely good. **A tree-id is one `u64`** (same
`struct_encode` NaN-box family) → it **fits the existing one-word lattice payload
with no widening**; `BTreeMapIndex::merge`'s signature, the value-carrying delta
rewrite, and `join_probe_lat`'s binding are all width-agnostic and unchanged
(`index.h:108,123-136`, `operators.h:112-135,362-366`). **The entire difficulty
concentrates in `lat_join` for a tree-id**: it must build the union/pointwise-merge
tree of two interned trees and return *its* interned id.

This is exactly the **`extern` lattice tier** (`docs/lattices.md §7`): register a
native `join_fn : u64×u64→u64` (and `leq_fn : u64×u64→bool`, needed now for the
debug audit `o ⊑ o⊔v` and later for incremental repair). Add a `LAT_EXTERN` kind
to `lat_join`'s dispatch (`types.h:116`); the merge task, delta plumbing, and
probe binding are otherwise unchanged.

**Why a native kernel is the right tool and a rule-defined merge is not:** the
merge runs inside `phase_intern` and **cannot re-enter rule evaluation** — a
rule-defined `⊔` would need a semi-naive sub-fixpoint inside one `merge()` call.
A native straight-line `u64×u64→u64` union does not re-enter anything, so it
escapes that objection. What it *inherits* is §9.

### 6.1 The combinator algebra: `(map K L)` is the fundamental construction

The deepest reason collections and lattices belong in one design: **the
pointwise-lifted map is the construction every other lattice-collection is an
instance of.** If `L` is a lattice, `(map K L)` is a lattice — ⊥ = the empty
map, `⊑` = pointwise with absent-is-⊥, and **join = `mergeWithKey(join_L)`**:
merge the tries, calling `L`'s join at colliding leaves. One native kernel —
Patricia merge parameterized by a value-join function pointer — implements the
entire family:

| lattice | as a combinator | note |
|---|---|---|
| finite set, `∪` | `(map T presence)` | presence = the one-point lattice; the degenerate pointwise merge |
| `(ps E)` bitmask | `(map E presence)`, \|E\| ≤ 64 | the bitmask is a *representation specialization*, not a separate feature |
| multiset / `lbag` (Bloom^L) | `(map T (max int #:floor 0))` | max-multiplicity — the idempotent stand-in for `sum` |
| abstract store | `(map addr (ps val))`, `(map addr (flat val))` | a whole store as ONE value — per-program-state stores |
| abstract counting μ | `(map addr (count))` | ΓCFA's μ as a value; strong-update discipline per §7 |
| environment of records | `(map var (map field (flat val)))` | nesting: the value-join is called recursively at leaves |
| **products** | fixed-length list of lattice values, pointwise | `interval = [(min int) (max int)]` — the L2 "products" milestone falls out of list syntax |
| constant-prop over lists | `(flat (list T))` | works with **zero new machinery** the moment lists are interned values — `flat` already lifts any interned word |

This answers "can users encode their own lattices via lists/maps": **yes, as a
combinator algebra** — compose `min/max/count/flat/ps/map` and fixed-shape
lattice-lists (products) freely, and every composite's join, ⊑, and calculus
rows derive mechanically from the components'. What composition does *not* give
is a genuinely new order (a custom ⊑ with a hand-written join) — that remains
the `extern` tier. The boundary is crisp: **combinators = zero proof
obligations (laws are parametric in the components); extern = trusted +
audited.**

Implementation shape: the arena merge kernel takes `(kind, value_join_fn)`;
`mergeWithKey` recurses structurally and calls `value_join_fn` at leaves — which
may itself be another `mergeWithKey` (nested maps) or a scalar `lat_join` arm.
The compiler derives the kernel-composition from the declared type, exactly as
it derives calculus rows.

---

## 7. The monotone-use calculus for collections

The calculus is data (`lattice-check.rkt`), one row per kind; collections slot in
by direction:

- **Monotone transfers (legal in-SCC as contributions):** `union`, `insert`,
  `map-merge`, `map-put` (only grow the collection); pointwise merge (dispatches
  to the value lattice's own join). `intersect(V, m)` for **constant/closed** `m`
  is monotone and is how gen/**kill** dataflow expresses `IN ∩ ¬kill`.
- **Upward-closed guards (legal in-SCC):** `member? e V` (once a member, stays),
  `superset? V m` for constant `m`.
- **Forbidden in-SCC (later stratum only):** `subset? V m` (downward-closed),
  exact equality, size-as-guard, use as a **join key** (its match set could
  shrink as the value ascends — `lattice-check.rkt:276`), and any plain-column /
  struct-field placement (interned content must be final). These are all fine
  **after** the collection's SCC closes.

**The rows derive compositionally** (Datafun-style monotonicity typing, done as
a table): an op classifies by how it maps `⊑`. Three instructive cases:

- `lookup : (map K L) → L` is **monotone** (map ascends ⇒ the looked-up value
  ascends in `L`-with-⊥) — so a mid-ascent lookup is a legal *transfer into an
  L-position*, recursively inheriting `L`'s own discipline. This is what makes
  nested-map dataflow (environments, stores) writable inside one SCC.
- `size` is **monotone into `(max int)`** — `(size S)` contributed to a max
  column is legal in-SCC! — while `(< (size S) k)` is downward-closed and
  illegal as a guard. Same operation, two directions, the table tells them
  apart.
- **Enumeration is not forbidden — unsound *snapshots* are.** The relation-key
  decomposition `R_has(k̄, elem)` (§4.2) is a plain monotone growing relation;
  reading it in-SCC is sound because each element, once present, stays, and
  Datalog rules can only draw monotone conclusions from a relation. What the
  calculus forbids on the *payload* (`subset?`, size-as-guard, equality) is
  exactly the class of conclusions `R_has` cannot express — treating a
  snapshot as complete. So the pair *(payload map for whole-value ops,
  derived `R_has` for element-wise use)* gives both faces soundly, and
  dissolves what a payload-only design would have to blanket-forbid.

Note the occurrence restrictions currently forbid a lattice type as a struct
field or map key (`lattice-check.rkt:47-81`), so "a map whose values are
themselves a lattice" is *not* a word-payload today — it *is* the extern-tree
tier: the canonical tree carries the pointwise structure internally and its merge
kernel does the pointwise `⊔` (§6.1).

---

## 8. Termination, persistence, cache-key, incrementality, and the pipeline principle

### 8.1 Termination

Growing collections have no natural floor (unlike `(min int #:floor 0)` =
Trop⁺). A set/map-union lattice terminates only because a single run ranges over
a finite Herbrand universe; the compiler can't hand you a static bound. Admit
with a **warning**, and offer the `docs/lattices.md §6` backstops: a per-key
merge budget, or widening (collapse to ⊤ after k ascents), or a declared finite
element universe.

### 8.2 On-disk / reload

Struct ids embed an insertion-order per-bucket counter (`operators.h:417`), so
the *same* logical set gets a *different* numeric id on a rerun. A tree-id
payload is meaningless without its node relation, and reload must persist the
node relation and **re-canonicalize to stable ids**. A **content-addressed**
node arena (id derived from a content hash) fixes this at the root and is a
strong argument for the arena in §9.

> **M2.1 reality check (2026-07-05):** the shipped arena's ids are content
> hash (26 bits) *plus collision-chain position* -- a pure-content-hash id
> in a 35-bit budget would hit birthday collisions in the hundreds of
> thousands of nodes (the same objection that deferred db-merge's north
> star C).  Reload reproduces ids exactly (in-order re-intern per partition
> file, `value.nodes/`), so *within one database* the promise above holds;
> what it does NOT give is cross-DB stability -- merging arenas shifts
> chain positions, and remapped keys change trie shapes, so db-merge must
> remap node words and re-canonicalize (see docs/db-merge.md).

### 8.3 Cache-key determinism

If the desugar introduces demand-like judgments (for AC ops), it must run
**before** the `.so` cache key and use **no gensym**, like the demand transform
(`demand.rkt:57-60`). Pure list-cons lowering can instead ride simplification
(which runs after the cache key and gensyms freely).

### 8.4 The pipeline principle: collections stay TYPED down to the backend

Collections must **not** fully desugar into cons/node structs in the front end.
The bracket *syntax* desugars early (pre-cache-key, gensym-free) — but into
**typed collection terms** (`(list T)`, `(vec T)`, `(set T)`, `(map K V)` with
ops `put/ref/member/merge/…`) that survive through typecheck → lattice-check →
operationalization and appear in c-IR as collection ops. Lowering to the struct
machinery (value role) or to native arena kernels (lattice role) is a **backend
decision per occurrence**, not a front-end rewrite. Three independent reasons,
each sufficient:

1. **The calculus needs the types.** `(map-put M a b)` must classify as a
   monotone transfer and `(lookup M k)` as a transfer-into-`L` (§7); desugared
   to opaque struct construction, the classification is impossible — worse, the
   occurrence restrictions *forbid* lattice-typed values inside struct
   constructions, so the desugared program would be rejected.
2. **The merge kernel needs the types.** A lattice column's `⊔` is derived from
   the composite type (§6.1's kernel composition); struct rows have no merge.
3. **Incrementality needs the types** (§8.5): a changed map must travel as an
   ⊑-increasing *replacement pair*, not as delete-row + insert-row.

**Concretely** ("backend" = the compiler's lowering passes, never the daemon —
nothing is decided at runtime; the daemon just runs whatever tasks and kernels
were compiled in). The same surface term in two occurrences:

```
lattice (fv (flat val))
table (env label (map var fv))    ;; lattice-composed column → env is a payload map
table (snapshot int envmap)       ;; plain column → rows hold interned map ids

;; A — inside env's own SCC:
rule (flow L L2) (env L M)      --> (env L2 {x:(const v) | M})
;; B — a later stratum:
rule (checkpoint T L) (env L M) --> (snapshot T {x:(const v) | M})
```

emit-cpp statically selects machinery per occurrence from (type, column role,
stratum): **A** emits a *merge-sink* — the head contributes a value that
`LatticeInternTask` merges via the composed `mergeWithKey(flat-join)` kernel
(payload map, value-carrying delta); **B** emits a *value construction* — build
the canonical trie, intern it, write the id into an ordinary row. Same
characters on the page; the triple is the routing information — and
lattice-check needed the same triple one pass earlier (to admit A as a monotone
transfer, and to leave B unrestricted).

This is a routing discipline Slog already follows twice: a `cost`-typed head
column routes to a merge-sink instead of an insert (lattices), and `(fib 10)`
routes to ask/resume codegen (demand). Collections are the third instance,
with one more axis (value role vs lattice role, per column, fixed at
declaration — no use-site annotations).

The choice has real teeth for *construction*: the typed op `(map-put M x v)`
has three possible emissions — a demand-judgment call (pure rules,
cross-iteration; Phase 0/1), staged struct construction (existing machinery,
~one iteration per tree level), or a native arena prim (one inline call in the
read phase, hash-consing nodes lock-free the way *string* interning already
works; Phase 2). Keeping the op typed to the lowering means upgrading is a new
emit-cpp arm, not a front-end rewrite.

Pragmatics per phase: the c-IR extension (typed `cput`/`cref`/`cmerge`/… ops)
lands in the phase that first needs it (native prims / merge sinks); Phases 0
and 1a ride existing machinery (struct construction, demand judgments). What
every phase must honor from day one is *declaration-level* fidelity: a
`(list T)`/`(map K V)` column type is recorded in the rel-env **as itself**,
never erased to its encoding.

### 8.5 Incrementality: the DRed^c / DRed_L dovetail

The collections design must be the one `docs/incremental.md` can extend
*additively* — and it is, with three specific synergies and one design rule:

- **Change-splitting composes, and requires the lattice representation.**
  DRed_L's central move: a value change travels as a replacement pair
  `(k̄, old, new)`; when `old ⊑ new` (checked by `leq_fn`) it routes through the
  **monotone phase** — no over-deletion, no rederivation cone. For collection
  columns this is the common case (the set grew). Had collections been struct
  rows, the same update is `−old_row, +new_row` → the full DRed negative
  fixpoint tears down the consequence cone of every ordinary insertion. This is
  the strongest form of §8.4: *the struct encoding is not just awkward for
  incrementality — it is asymptotically wrong for it.*
- **The tree-diff is the delta.** Patricia merge's physical-equality
  short-circuit computes `diff(old, new)` in O(change) — which is exactly the
  set of `R_has` rows to emit (§4.2) and exactly the signed records DRed^c
  wants. Canonical trees make occurrence maintenance O(change) for free.
- **The payload slot is shared, as designed.** `docs/lattices.md §4.1` reserved
  the index-value slot for `(value, nonrec, rec)`; a tree-id is one word, so a
  collection lattice column's incremental state is `(tree_id, nonrec, rec)` —
  no new layout. Deletion of a contribution that supplied part of the current
  set is the §7A.3 rank-repair problem *per leaf*, and the pair format
  localizes repair to the leaves that actually regressed.
- **Design rule: prefer rules-derived maintenance.** If `R_has` / occurrence
  relations are maintained by *generated rules* (from the value-carrying
  delta), DRed^c handles their deletion/repair like any derived relation —
  for free. A native fast-path task that publishes them directly must emit
  the **same signed records** the rules would have, or incrementality breaks.
  Start rules-derived; make native an optimization with an equivalence
  obligation.

---

## 9. The architectural crux — reconciling the two interners

This is the decision the whole feature pivots on. Restating §1: canonical
collections want a **mergeable canonical id producible mid-merge-phase**
(the global lock-free interner's property) **and structural joinability on
contents** (the struct b-tree interner's property). Concretely, the grounding
found three blockers to hosting a native mid-phase merge in the struct interner:

1. **Bucket ownership.** A fresh child node's bucket = `buckethash(child content)`
   — generally *not* the bucket the current merge task owns — so recursively
   interning it races that bucket's own task. There is no lock in
   `InternStructTask`.
2. **Cross-relation concurrency.** Node rows live in their own Relation whose
   per-bucket intern tasks run concurrently in the same `phase_intern` queue;
   mutating them from another relation's task is an unguarded race.
3. **No post-intern write phase.** Phases run `write→read→intern`
   (`database.h:36-39`); a node minted during intern isn't inserted into its
   lookup/secondary indices until the *next* iteration's write — so a
   within-one-iteration merge cannot make its new nodes joinable this iteration.

**Proposed resolution — decouple *identity* from *joinability*:**

- **Identity (source of truth):** collection **nodes live in a global,
  lock-free, content-addressed hash-cons arena** modeled on `InternTable`
  (`intern.h:54-395`) — re-entrant from any thread in any phase, so a native merge
  kernel can build and canonicalize a union tree mid-`phase_intern` safely, and
  ids are **content-stable** (fixing reload, §8).
- **Joinability (derived view):** the b-tree occurrence/decomposition relations of
  §4.2/§5 are *materialized from the arena through the normal delta pipeline* — a
  merged collection's id flows out as a value-carrying delta, and a generated
  companion rule publishes its `set_has`/`map_at` tuples in the *next* iteration's
  write/read phases. This is the **same one-iteration lag structs already have**
  (id assigned iteration N, queryable N+1) — consistent with the existing model,
  not a new hazard.

So the arena owns canonical identity and hosts the native merge; the b-tree side
is a lazily-published, need-driven index. This is the piece that does not exist
today and is the core new runtime component (a concurrent canonicalizing node
arena distinct from both existing interners). Everything in §10's Phase 0/1 is
deliberately arranged to *not* need it.

---

## 10. Phased plan (sequencing the risk)

Standing constraint on every phase, from §8.4: the front end produces **typed
collection terms**; struct-lowering vs native-kernel lowering is a backend
decision. No phase bakes "collections are structs" into anything above the
lowering.

- **Phase 0 — lists, essentially free.** Bracket syntax → typed `(list T)`
  terms (pre-cache-key, gensym-free); single-trailing-tail `[a b | T]`;
  parametric list typing; **backend lowering to `cons`/`nil` structs** (the
  value-role lowering, which for lists is also the final one). A `demand`
  stdlib (`insert`, `member`, `append`, `ref`, `size`) — one-to-a-few rules
  each, memoized, with real subtree sharing. **No engine work**: rides
  simplification-flattening, head-staging, struct interning, and demand. Bonus
  that falls out immediately: `(flat (list T))` — constant-propagation over
  lists — works with zero additional machinery (§6.1).

- **Phase 1 — sets/maps (and `(vec T)`) as canonical *values*.** The new
  engine work is **canonicalization**: a normalize step producing a canonical
  Patricia tree (strict-radix tree for `vec`) *before* interning, so equal
  collections → one id. Ops via the demand stdlib or native prims. Pattern
  compilation per §4.2's spectrum: native member-guards, ground-suffix `tail*`
  probes, node-walking enumeration judgments, and **need-driven** inverted
  occurrence tables with their write-side maintenance. Delivers collections as
  immutable canonical values with joinable patterns, cross-iteration. (Still
  no lattice-column merge.)

- **Phase 2 — the lattice-column merge (the payoff).** The `extern`-tier
  native **`mergeWithKey` kernel parameterized by the value-join** (§6.1) —
  one kernel implementing sets, maps, multisets, nested maps, and products —
  hosted on the content-addressed arena (§9) so it is re-entrant mid-phase.
  The **relation-key decomposition `R_has`** (§4.2) generated as rules off the
  value-carrying delta. Replacement-pair deltas + `leq_fn` from day one so
  DRed_L change-splitting lands additively (§8.5). This is where `set`/`map`
  become lattice columns that merge in one iteration (reaching-defs with kill,
  points-to, AAM stores with counting, per-state abstract stores as values, …).
  Heaviest, and gated on §9.

Each phase is independently useful and independently shippable.

---

## 11. Open issues / tricky-issue checklist

1. **The two-interner reconciliation (§9)** — *the* architectural decision;
   arena vs. serialize-node-interning vs. stay-cross-iteration.
2. **Canonicalization is a correctness gate** — any shape nondeterminism →
   wrong `==`/keys/joins. Patricia by construction; strict-radix for lists;
   collision-leaf ordering must itself be canonical.
3. **Mid-phase recursive hash-consing** needs the re-entrant arena; cannot reuse
   the per-bucket struct interner (races, no post-intern write).
4. **Write-side occurrence maintenance + delta propagation** for semi-naive
   refire; O(membership) blowup vs. sharing; need-driven generation.
5. **REST/splice = set-difference / tree navigation**, outside the b-tree-prefix
   model — needs native tree ops or residual-carrying decomposition relations.
6. **AC-matching is NP-complete** → restrict to ground-key / single-member+rest /
   no multi-split.
7. **Parser overloads:** `|` mis-associates and triple-overloads (prefer a
   dedicated splice token); `{}` set-vs-map ambiguity; single-rest restriction;
   `_`-tail semantics.
8. **Typing:** parametric `(set T)` / `(map K V)` / `(list T)`; rest-var typing;
   nesting; the value-role vs lattice-role distinction; the transparent-typing
   precedent (`lattice-base-type`).
9. **Termination** has no static floor → warn / budget / widening / finite universe.
10. **On-disk reload** needs the node relation persisted + content-stable ids
    (the arena fixes this).
11. **Cache-key determinism** — desugar before the cache key, no gensym, if it
    emits demand-like judgments.
12. **Map-lattice merge composes** with the value lattice's own join (nested
    lattices) — the native kernel must dispatch to it.
13. **Bucket skew** — lead structural indices with the high-cardinality value
    column, never `pos`.
14. **Index proliferation** — one ordering per partial-groundness shape; lean on
    min-chain-cover (`indices.rkt`).
15. **Value-unification restriction** (`join-planning.rkt:131-134`) blocks two
    head constructions binding one id — design merges as single constructions.
16. **Merge verification** — Okasaki–Gill had a 2017 bug; property-test the union.
17. **Build-direction mismatch** — cons is head-cheap, vec is tail-cheap; the
    desugar should not silently compile a head-recursive idiom onto `vec` (or an
    accumulator idiom onto `list`) without at least a lint.
18. **Value-role vs lattice-role decomposition are different mechanisms** —
    collection-id-keyed (blowup-prone, need-driven) vs relation-key-keyed
    (monotone, cheap, in-SCC-enumerable). Don't conflate them in the planner.
19. **Rules-derived vs native occurrence maintenance** — native fast paths must
    emit the same signed records the generated rules would, or DRed^c breaks
    (§8.5). Start rules-derived.
20. **Combinator boundary** — composed lattices (`map`/products/`flat`/…) carry
    zero proof obligations; only genuinely new orders need `extern`. Keep the
    boundary crisp in the surface syntax so users know which side they're on.

---

## 12. Implementation plan

Gate for every milestone: the full golden suite (93) + unit tests stay green;
each milestone adds its own goldens. Decision points are marked **D#** with
defaults.

### Phase 0 — lists (target: no engine work)

**STATUS: SHIPPED 2026-07-03** — all milestones below landed; full suite green
(98 golden + 95 unit). Files: `compiler/collections.rkt` (desugar),
`modules.rkt` (builtin seeding, reserved names, `(list T)` interception),
`ir-shared.rkt` (`listof-spec?`, transparent resolution), `lib/list.slog`
(stdlib), goldens `lst_basic`/`lst_ops`/`lst_flat`/`lst_typed`/`dem_brackets`,
`tests/unit/collections-tests.rkt`. D1 resolved: `any`-fielded builtin. D5
resolved: `list`/`cons`/`nil` reserved (the two declaring tests migrated).
Bonus finds fixed along the way: the `parse-error` single-token latent bug;
the type-system struct-construction path not resolving transparent types; and
— the significant one — the **speculative-compute planner bug**: computes
fired eagerly before filtering joins, so a faultable prim could run on rows a
later join would reject (exposed by a demand judgment coexisting with
nested-list facts; pre-existing, reachable via any-fielded unions).
Fix: guards stay eager, computes fire on-demand (when the next join consumes
their output, with transitive feeder expansion) or in the post-join flush —
prims now only run on fully-matched rows (`join-planning.rkt` `fire-specials`
needed-gating; `join-score` enabled-bonus now counts guards only).

All M0 placement/feasibility claims below were verified against the compiler
(2026-07-03, empirical probes; artifacts in the session scratchpad).

- **M0.1 — desugar pass.** New `compiler/collections.rkt` (auto-covered by the
  compiler-sources cache fingerprint), modeled on `desugar-demand-program`:
  takes mods + type-env, returns rewritten mods + synthesized decls, all names
  deterministic, **no gensym**. Invocation site: inside `lift-type-envs`
  (`modules.rkt:~420`), **immediately before the demand transform** — this is
  load-bearing, not stylistic: `split-or-clauses` recurses into *every*
  subterm and is invoked from BOTH `simplification.rkt:184` and
  `demand.rkt:504`, and a body `[a b | T]` is verified to silently cartesian-
  split into `[a b]` / `[a T]` alternatives if any or-split sees it first
  (heads instead get a phantom `(| …)` struct). Rewrites: `([] …)` →
  `cons`/`nil`; **only a 2-ary `(| h t)` in the bracket's last argument** is a
  tail — a pipe in a non-last argument (`[a b | c d]`) and n-ary chained tails
  (`[a b | c | d]` — the parser flattens chained pipes) are provenance-carrying
  errors; pipes strictly inside element subterms keep the language's uniform
  nested-`|` or-split semantics.
  **D1 (default: `any`):** one builtin untyped `list` union — `(nil)`,
  `(cons any list)` — seeded into `base-type-env` exactly like `_enum`
  (`modules.rkt:177-178`; the demand transform's `clo` union is precedent for
  programmatic synthesis). Verified: `any`-fielded unions compile and run
  correctly today. Caveat carried: `any` is bidirectionally permissive, so a
  `(list T)` annotation buys no content checking until the typed phase.
  **D2 — RESOLVED: reassociate `|`; no splice token**, under the M0.1
  error conditions above.
  **D5 (new, needs a call): the builtin names collide with user decls.**
  `types-unify?` has no `any` escape, so builtin `(cons any list)` conflicts
  with a user's `union (list (nil) (cons int list))` — which
  `tests/dem_map.slog` and `tests/dem_lambda.slog` declare today. Options:
  reserve `list`/`cons`/`nil` as builtins (migrate the two tests, clear
  redeclaration error) — the default; or teach `types-unify?` an `any`-escape
  so user redeclarations refine the builtin.
- **M0.2 — typing.** Intercept `(list T)` in `flatten-nested-type`
  (`modules.rkt:259-261`, beside the lattice-valuespec clause and **before**
  the inline-struct fallback — verified footgun: today `table (input (list
  int))` silently declares a unary struct named `list`). Deterministic anon
  name (`_list_int`), rels entry `(listof T)` preserving the parametric type
  verbatim (§8.4), transparent resolution to `list` via a `column-base-type`
  sibling of `lattice-base-type` at its two call sites
  (`type-system.rkt:125,169`), plus the small case additions
  (`rel-decl-arity`, `update-manifest` skip).
- **M0.3 — stdlib.** `lib/list.slog`: `lst_append`, `lst_ref`, `lst_member`,
  `lst_len`, `lst_rev` as demand judgments. **D3 (default: explicit
  `include`)** — no auto-injection magic in Phase 0.
- **M0.4 — tests.** Unit tests for the desugar; goldens: literal facts, head
  construction, body `[x | xs]` deconstruct, stdlib ops, a bracket-syntax
  variant of `dem_map`, and the free §6.1 bonus: constant propagation over
  lists via `(flat list)`.

### Phase 1 — canonical sets/maps + `(vec T)` as values

**STATUS: sets/maps SHIPPED 2026-07-05** (`(vec T)` is the remaining item).
`lib/set.slog` + `lib/map.slog`: Okasaki-Gill big-endian Patricia tries as
demand judgments over non-negative int keys (bit helpers via the arithmetic
prims; element generality arrives with the native kernels). Ops: ins/put,
partial mem/get, **total mem0/has0** (a trie is a decision structure, so
absence is structurally decidable — no negation needed), del with branch
collapse, union (left-biased for maps via put_soft), difference, size,
fromlist. Brace literals/updates (`{5 2 8}`, `{k:v | m}`) desugar in
`collections.rkt` (21 unit tests). **Canonicity verified**: brace literal,
two insertion orders, and union-of-parts all intern to ONE id (goldens
`st_basic`/`mp_basic`, each hand-derived; plus a seeded differential oracle
vs a Python reference — 3 random rounds, all relations exact). Deviations
from the M1 plan: rules-based ops only (M1.4 arena accel not needed yet);
inverted occurrence tables still deferred (need-driven).

Building this exposed and fixed TWO more pre-existing engine bugs (the
Patricia lib is the largest demand program yet compiled):
- the **type-system alias cycle** in its full generality (head-side nested
  calls process before grounding lets; first-write-wins was order-dependent)
  — fixed properly with symmetric accumulated links + BFS-to-ground;
- the **task-queue drop bug**: `boost::lockfree::queue<Task*, 8192>` with
  unchecked `push()` silently dropped every task past capacity — the set-lib
  stratum registers 9,888 read tasks, so late-registered rules never ran and
  fixpoints converged wrong with no error. Replaced with an atomic cursor
  over the stratum's task vectors (strictly less synchronization). Debugging
  trick worth keeping: the daemon loads plugins by path, so a scratch-
  compiled instrumented copy of a generated stratum .cpp can be substituted
  into the stdin plugin list.

- **M1.1 — node types + rules-based ops.** Builtin Patricia node unions
  (`pleaf`, `pbranch`) and strict-radix vec nodes. `lib/set.slog` /
  `lib/map.slog`: Patricia `insert`/`lookup`/`member`/`union`/`difference` as
  demand judgments — canonical **by construction**, so rule-based ops already
  intern equal collections to one id. Branching-bit helpers over the existing
  `band/bor/bxor/shl/shr` prims, property-tested against a Racket oracle
  (§11.16).
- **M1.2 — surface.** `{…}` literals, `{a:b | m}` update, ground-key body
  patterns → lookup judgments; single-member+rest → enumeration judgment.
  `{}`/`{:}` disambiguation (D2 family). Inverted occurrence tables stay
  **deferred until a concrete pattern demands one** (need-driven applies to us
  too).
- **M1.3 — canonicity tests.** Same set built in N insertion orders → one
  interned id (assert via CSV); random-op differential tests vs the oracle.
- **M1.4 (optional accel) — arena spike, pulled forward.** See M2.1; if
  rules-based op cost bites early, the spike moves here unchanged.

### Phase 2 — the arena + the lattice role

- **M2.1 — arena spike (de-risk first, standalone).** Content-addressed,
  lock-free node store modeled on `InternTable` (`intern.h`); native
  `put/lookup/union` prims callable inline in the read phase; id stability
  across reload; bench vs the rules-based ops. **D4:** which NaN-box tag
  space collection-node ids live in (the 35-bit intern family vs a reserved
  struct-id family).

  **STATUS: SHIPPED 2026-07-05.** `daemon/arena.h`: `cnode` (4-word Patricia
  node -- branch `{prefix, mask, left, right}`, leaf `{key, 0, val, 1}`,
  empty `{0,0,0,0}`) hash-consed in an `InternTable<cnode>`; kernels
  `put/put_soft/find/merge/del/diff/size/foreach` over **full 64-bit
  NaN-boxed key words** (string ids, struct ids, floats, nested collection
  words -- all legal keys/values), with physical-equality short-circuits
  justified by canonical interning.  **D4 resolved: intern tag 2** (the
  free 3-bit intern family; `is_cnode`, `types.h`).  A set is a map-to-unit.
  Ten `any`-typed prims (`cmap cput cget chas cmerge cdel cdiff csize cins
  cmem`, `prims.h` + `primitives.rkt` -- two-edit registration, every prim
  already receives `Database*`); `cmerge` is left-biased; `cget` faults on
  absence and the planner now fires **guard-feeding computes first in the
  post-join flush** (`join-planning.rkt` `fire-specials`) so
  `(= h (chas m k)) (> h 0) (= v (cget m k))` genuinely protects it.
  Rendering: `writeValCSV` prints `{k:v ...}` in canonical (ascending
  unsigned key-word) order, depth-capped.  Persistence: `value.nodes/`
  partition files mirroring `value.strings` (32-byte records in iterator
  order; ids reproduce on in-order reload because an id = 26 content-hash
  bits + collision-chain position and a chain lives wholly in one partition
  file -- child words hash without dereferencing, so the argument extends
  to trees inductively).  Tests: `tests/arena-tests.cpp` (5.8k-check
  differential vs a reference model, canonicity/shuffle/partition-merge,
  algebraic identities, 8-thread concurrency, reload-id-reproduction;
  ASan/TSan clean), `cn_basic` golden, `api-tests.sh` §6 round-trip.
  **Bench: ~700x** over the rules-based lib (2x1000 inserts + union:
  36.9ms native vs 26,402ms `lib/set.slog`).

  Findings worth keeping (adversarially reviewed):
  - **`intern.h` dup-hit id bug (fixed):** the duplicate-hit path computed
    `i << 26` with `u16 i` promoted to *int* -- sign-extension at chain
    index >= 32, full wraparound (silent id conflation!) at >= 64.  Fixed
    with a `u64` widen + a hard 512-entries-per-slot fatal (the 35-bit id
    budget), which now also protects *string* interning.
  - **Id semantics, honestly stated:** ids are content-hash *plus
    collision-order* -- reload-in-order reproduces them exactly, but they
    are NOT pure content addresses: loading into a non-empty arena or
    merging DBs shifts collision indices, so cross-DB import must remap
    node ids and **re-canonicalize tries whose keys are themselves
    remapped interned words** (db-merge P1 work; §8.2's "content-addressed
    fixes reload" holds, its cross-DB implications do not).
  - Accepted spike limits: `csize` truncates to s32; a `writeRelationBIN`
    into a *foreign* db dir rewrites `value.nodes` from the current arena
    (same "only stable within the db this instance opened or wrote"
    contract strings have, `database.h`); collection words can still reach
    numeric lattice columns via `any` typing -- now a loud fatal in
    `lat_num_min/max` instead of silent NaN garbage; the ten prim names
    are not reserved against user relations (same as all prims).
  - The rules-based libs (`lib/set.slog`, `lib/map.slog`) remain as the
    semantics reference and differential oracle; M1.4's "arena accel"
    escape hatch is now real.
- **M2.2 — merge kernel.** `LAT_EXTERN` + the composed `mergeWithKey`
  kernel parameterized by the value-join (one kernel: sets, maps, multisets,
  nested maps, products), `leq_fn` from day one (audit + DRed_L), clamp
  no-op arm.

  **STATUS: SHIPPED 2026-07-06.** `daemon/arena.h`: `LatSpec` trees parsed
  from spec tokens (`parseLatSpecToken`, recursive descent — the runslog
  manifest inverse mirrors it) + `CollectionArena::merge_spec`/`leq_spec`
  (`merge_with` pointwise union with `join_leaf` dispatching the child spec
  at collisions; a set joins as map-to-unit).  `LAT_EXTERN` (`types.h`,
  whose scalar `lat_join` default is now a fatal, not silently-flat);
  `BTreeMapIndex` carries the spec tree + arena, copied at all three
  registration points; `Relation::setLattice` parses the token and owns the
  tree.  Valuespec surface: `(set T)` and `(map K <valuespec>)`, nesting
  freely (`map-int-map-str-flat-val` tokens round-trip both re-parsers);
  **v1 restriction: no `#:floor/#:ceiling` inside nested positions** (a
  collision-only clamp would be subtly different semantics — rejected at
  parse).  `leq_spec(a,b) = merge_spec(a,b)==b` (canonical interning makes
  the one-liner exact).  Demand answers compose free (`(demand (f int)
  (set int))` needs zero demand.rkt changes).  Golden `lat_set` (in-SCC
  set union, pointwise-min map, guarded extraction) + on-disk round trip +
  1.8k merge_spec differential checks in `tests/arena-tests.cpp`.

- **M2.3 — compiler.** Collection-lattice typing (§6.1 composition legality),
  calculus rows (compositional table, §7), merge-sink emission for collection
  columns; c-IR gains the typed `cput`/`cref`/`cmember`/`cmerge` ops (the
  §8.4 contract surface, landing in the phase that needs it).

  **STATUS: SHIPPED 2026-07-06** (the name-set-era version; the full
  type-terms rewrite is docs/type-system.md Stages 1–2).  Base types
  `cset`/`cmap` + builtin union `coll` type the arena's words (one runtime
  representation, two static disciplines); the ten prims got real
  signatures (`cput : cmap any any -> cmap`, `cins : cset any -> cset`,
  shared ops over `coll`), so set/map misuse is a static rejection while
  element types await Stage 2.  `(map K V)` with V a plain type is a
  VALUE-role column (`(mapof K V)` rels entry, transparent to `cmap`, K/V
  verbatim per §8.4); `(map K <valuespec>)` and `(set T)` are LATTICE-role
  (docs/type-system.md §8.5's role-from-type rule; a value-role set column
  is declared plain `cset`).  The residual head-typecheck machinery gained
  the `is_cnode` tag (a collection column is runtime-guarded like any
  other).  Calculus (v1, position-aware — a still-ascending value is only accepted
  in an op's COLLECTION position, never as an inserted element/key/value):
  `(lattice set/map ...)` occurrence validation; sets grow in-SCC by
  `cins` (collection position) and `cmerge` (either side — presence-union
  is monotone in both and unit values erase the left bias); maps grow by
  `cput` (map position only).  **Excluded in v1, by adversarial review**:
  in-SCC `cmerge` on MAPS (the prim is left-biased, so a colliding key's
  contribution would carry whichever side the iteration schedule delivered
  first — a timing-dependent fixpoint; a pointwise-joining `cjoin` prim
  or per-key contributions are the sound spellings) and in-SCC `cget`
  (§7's monotone-lookup rule is real, but the prim faults on a
  not-yet-present key and the `chas` guard is later-stratum only — child-
  spec descent returns when a total lookup exists); `cdel`/`cdiff`
  excluded (shrinking); membership/size guards stay later-stratum (in-SCC
  membership is M2.4's `R_has`); finite-universe termination warning.
  **Both exclusions LIFTED 2026-07-08 (`docs/finish-collections.md` §A/§D,
  executed): `cget` is a PARTIAL prim** — `prim-partial?`
  (compiler/primitives.rkt) marks it, lowering emits a `letp` c-op whose
  call takes a trailing `bool* ok` and whose failure abandons the row
  (absence = failed match against a virtual relation; type errors stay
  fatal), and the calculus regained the map-kind child-spec-descent row
  (goldens `cn_getp`, `lat_nested`) — **and `cjoin` is the spec-aware
  pointwise join**: typed like `cmerge` but lowered to a dedicated
  `(cjoin x spec a b)` c-op from a per-rule var→spec scan (planned bodies
  are schedule-ordered, so one pass resolves chains), emitted as a
  `merge_spec` call under a once-per-site parsed spec tree; whitelisted
  in-SCC for set (union) and map (pointwise, both positions) kinds
  (golden `lat_cjoin`).  Brace literals
  route per program: the rules libs (pset/pmap declared) keep `st_ins`/
  `mp_put`; otherwise braces lower to native `cins`/`cput`/`(cmap)` — and
  the native empty `{}` is legal (one canonical empty collection).
  Merge-sink emission needed NO new codegen: a collection-lattice head
  rides the existing width-agnostic `emit-lat`/`LatticeInternTask` path.
  NOT yet: `(ps E)` bitmask specialization; the reaching-defs/
  abstract-store flagship goldens (M2.5) beyond `lat_set`.
- **M2.4 — `R_has`.** Relation-key decomposition generated off the
  value-carrying delta (§4.2); an in-SCC enumeration golden.

  **STATUS: SHIPPED 2026-07-08** (`docs/finish-collections.md` §C,
  executed).  Need-driven synthesis by name (modules.rkt): using an
  undeclared `<R>_has` (`<R>_at`) over a set-kind (map-kind)
  collection-lattice table R synthesizes `R_has(k̄, elem)` — a PLAIN
  monotone relation — or `R_at(k̄, key, v)` — itself a lattice table whose
  value column carries the map's child valuespec (pointwise by
  construction; nested maps compose) — and records `derived → (base kind)`
  in the program's decomp-env (threaded through the program tuple; a user
  decl wins, no use = zero cost).  Stratify gains the derived edge
  R → R_has; the derived name is DYNAMIC in every stratum (its rows ride
  the publish path one iteration late, so readers get delta-driven
  versions even where the base is closed).  Runtime: the base's
  `LatticeInternTask` walks each ascent's (old, new) payload pair with the
  arena's `foreach_added` tree-diff — O(change) via shared-subtree pruning
  — and publishes rows through the reusable `RowPublisher` shards path
  (which sequences S1's `SeqIndexTask` will reuse); the master (once)
  `MapWriteTask` carries the same target, so iteration 0 re-derives the
  decomposition from reloaded/imported content — a dedup'd no-op when
  up to date, and exactly what makes a foreign or stale base self-heal on
  first use.  Persistence/merge generic (both are ordinary relations).
  Goldens `lat_rhas` (gated reachability — in-SCC membership, chained
  gates), `lat_rat` (pointwise minima in-SCC + cross-strata, nested
  (map int (set int)) composition); unit tests for synthesis/interception/
  edges in tests/unit/decomp-tests.rkt; `foreach_added` differential
  checks in tests/arena-tests.cpp.
- **M2.5 — flagship goldens.** Reaching definitions **with kill**
  (`intersect` against the static ¬kill mask); an abstract store
  `(map addr (ps val))` variant of the tinycfa analysis; `(ps E)` as the
  bitmask specialization — which also makes `examples/sudoku/sudoku-ps.slog`
  runnable.
- **M2.6 — persistence.** Spec tokens for collection lattices; arena BIN
  round-trip (content-addressed ids make this stable by construction).

## 13. Prior art

- **egglog** (PLDI'23) — the closest analog: a column carries a lattice via a
  `:merge` expression, join order is irrelevant, e-graph rebuilding restores the
  invariant after merges; exposes hash-consed container sorts (set/map/vec) usable
  in merges. This is essentially the Phase-2 target.
- **Flix** (PLDI'16) — lattice columns merge by a user `⊔` supplied through
  `JoinLattice`/`MeetLattice` type classes; collections are ordinary ADT values in
  a lattice column.
- **Datafun** (ICFP'16) — the purest "set as a lattice value": finite sets ordered
  by inclusion are the core semilattice, `∪` the join, with a monotonicity type
  system — the semantic model for §7.
- **Soufflé** — records/ADTs interned into a record table (hash-consing by another
  name) with auto-indexing; `eqrel` (parallel union-find), subsumption, and choice
  domains *emulate* lattice behavior; no general user lattice merge. The
  decomposition-relation + auto-index approach here mirrors Soufflé's auto-index
  requisition.
- **ACL2 `hons`** (Boyer–Hunt) / **Filliâtre–Conchon type-safe modular
  hash-consing** — the interning discipline: canonical structure + bottom-up
  interning ⇒ pointer-equality = value-equality + memoization.
- **Okasaki–Gill**, *Fast Mergeable Integer Maps* (big-endian Patricia; Haskell
  `Data.IntMap`); **Steindorfer–Vinju**, CHAMP (OOPSLA'15); **Bagwell–Rompf**,
  RRB-Trees (the non-canonicity that disqualifies them here).
- **Kapur–Narendran**, NP-completeness of set unification/matching; **Maude/Eker**
  AC bipartite matching (why we restrict rather than unify).


## 14. Exact integers — auto-promoting s32 ⇄ interned mpz

**STATUS: SHIPPED 2026-07-09** — all milestones landed same-day. Files:
`daemon/mpz.h` (new: `mpz_val`, `fasthash`, `cmp_int_words`, the relocated
scalar lattice joins), `daemon/int_prims.h` (full rewrite: s64 fast paths +
GMP kernels), `daemon/types.h` (sentinel relocation, `is_s32` mask,
`is_mpz`/`is_int`), `daemon/database.h` (table + keystone encoders + caps +
`value.mpz/` stage/load/serial + import leaf arm + CSV), `daemon/prims.h`
(dispatch over `is_int`), `daemon/seq_prims.h` (index-guard sign-saturation,
`s2i`/`i2s` bignum), `daemon/operators.h` + `compiler/modules.rkt` +
`type-system.rkt` (the two new error arms), `emit-cpp.rkt` (tycheck arm,
literal split + cap-fatal), `actions.rkt`, `config.rkt` (cap settings),
`dbmeta.rkt` (v2), `tools.rkt`/`daemon/Makefile` (`-lgmp`).  Tests:
`int_promote`/`int_bignum`/`int_caps`/`int_lat` goldens (all rows
hand-verified), api-tests §11 bignum round-trip + §12 table cap, smt-tests
bignum parse case + `bigmodel-z3.slog` (solver 10^20 round-trips exactly).
Notes vs the plan: `i2s` takes the value through `is_int` directly (the
index-guard saturation would corrupt it); the SMT mock deliberately answers
unknown on bignum formulas (s64 evaluator, documented in smt.h); a
cap-tripped LITERAL fatals at plugin load (a stored `slog_error` word would
otherwise corrupt facts); the serial checkpoint's string writer had a latent
codepoints-vs-bytes truncation bug (multibyte content), fixed in passing;
`ERR_INT_OVF`/`int_overflow` remain declared but no kernel emits them now
(INT_MIN edge cases promote instead).

### Original plan (2026-07-09), decisions resolved inline

**Goal.** `int` becomes *exact, unbounded* integers with ONE canonical word per
value: a value in `[-2^31, 2^31)` is ALWAYS the s32 prim word; anything outside
is ALWAYS an interned GMP bignum under `mpz_intern_tag` (types.h:42, reserved
since day one). Arithmetic never wraps: s32 kernels promote on overflow, mpz
kernels contract when the result fits. The small/big split is a pure function
of the value — the same **two representations, one type** keystone as
mono/rope strings (types.h:75-91) — so raw-word equality/joins/dedup remain
value semantics, and the small-int common path pays nothing new.

### 14.1 Prerequisite encoding refactor (no semantics): sentinel relocation

The s32 prim payload uses 32 of its 35 bits (`s32_encode` masks, types.h:106).
The upper-3-bit region — tag-1 payloads in `[2^32, 2^35)`, ~30G words — becomes
**reserved internal space**, and the three sentinels move to its top:

```
slog_null     0x7ff0003fffffffff  →  0x7ff0000fffffffff   (tag-1 payload 2^35-1)
slog_lat_top  0x7ff0003ffffffffe  →  0x7ff0000ffffffffe
slog_error    0x7ff0003ffffffffd  →  0x7ff0000ffffffffd
```

- `is_s32` gains one mask test:
  `is_prim(x) && decode_type(x)==s32_prim_tag && !((x) & 0x0000000700000000)`.
  Every consumer inherits it through the macro; the both-s32 fast paths in
  prims.h are otherwise unchanged.
- Freed by this + deleting the dead `enum_prim_tag` define (types.h:38, zero
  uses — enums lower to the `_enum` struct): **prim tags 2–7 fully free**
  (35-bit payloads each); intern tags 5–7 already free.
- **Disk impact.** `slog_lat_top` is a real stored value (FLAT join result,
  types.h:202 → `BTreeMapIndex` payload, index.h:146 → raw u64 in
  `writeAllFactsBIN`, database.h:1931-1944). `slog_null`/`slog_error` are
  confirmed transient (dedup markers / abandoned deductions; never reach the
  stored btree). **RESOLVED (D-int.3): hard break** — bump
  `slog-value-encoding-version` 1→2 (dbmeta.rkt:83, enforced
  runslog.rkt:263-265, dbtool.rkt:203-217); no legacy translate arm. v1 DBs
  are invalidated: clear `data/` and regenerate what matters. IO upgrades
  fully with the encoding, every time.
- The import `self_encoding` allowlist (database.h:3057) references the
  macros — it moves automatically. Generated `.so`s compare `slog_error` by
  name (emit-cpp.rkt:53) and daemon headers are in the cache fingerprint, so
  stale plugins recompile automatically.

### 14.2 The keystone: `encodeInt` / `encodeMpz` normalization

`daemon/mpz.h` (new): an immutable `mpz_val` wrapper (holds `mpz_t`;
`operator==` via `mpz_cmp`; canonical byte serialization = sign byte + u32
limb-byte count + little-endian `mpz_export` bytes, used by BOTH the disk
format and `fasthash<mpz_val>` — intern.h:38-51 pattern, which the table
REQUIRES). `InternTable<mpz_val>` is instantiated as-is: lock-free CAS,
content-hash ids, the dup-path id-wrap fix (intern.h:105-108) inherited;
interned values are immutable so parallel prim calls are safe. **No allocator
seeding** — like strings, ids are content-derived, not counters.

Database (mirroring database.h:1108-1163, 1183-1205):

- `intern_mpz` (with the duplicate-delete guard) / `lookup_mpz`;
- `u64 encodeInt(s64 v)` — fits s32 → `s32_encode`, else intern;
- `u64 encodeMpz(mpz_srcptr z)` — fits s32 → `s32_encode(mpz_get_si)`, else
  cap check (§14.4) then intern. **Invariant: no interned mpz ever lies in
  `[-2^31, 2^31)`** — this is what makes word equality = value equality;
- `u64 encodeIntLiteral(const char* dec)` — `mpz_set_str` → `encodeMpz`
  (literals, `s2i`, SMT numerals).
- `is_mpz(x)` / `is_int(x) = is_s32(x) || is_mpz(x)` in types.h.
- `cmp_int(db,a,b)` exact tri-compare: both-s32 → s64 compare; one mpz → its
  **sign decides** (by the invariant its magnitude exceeds every s32); both →
  `mpz_cmp`. mpz-vs-float uses `mpz_cmp_d` (exact, no 2^53 loss).

### 14.3 Prim semantics (prims.h dispatch + kernels)

- `+ - *` both-s32: compute in **s64** (can't overflow), `encodeInt` — silent
  wrap is gone. Any-mpz int arm: GMP kernel → `encodeMpz` contraction.
- `/ %`: div0/mod0 errors unchanged; the `INT_MIN/-1` `ERR_INT_OVF` arms
  (int_prims.h:35-51) are **retired** — the result promotes to mpz `2^31`.
  mpz uses `mpz_tdiv_q/r` (matches C truncated division).
- `pow`: negative exponent → 0 (unchanged); size precheck
  `bits(base)·exp` vs cap, then `mpz_pow_ui`.
- Bitwise `band bor bxor bnot`: extend to mpz via GMP's two's-complement
  semantics (`mpz_and/ior/xor/com`). `shl` becomes true `×2^k` (the `&31`
  mask drops; cap prechecks `bits+k`); `shr` = arithmetic shift
  (`mpz_fdiv_q_2exp`). Ints are integers, not 32-bit bitvectors (D-int.2).
- Comparisons `SLOG_CMP` (prims.h:97-101): int-exact arms via `cmp_int`
  before the double fallback; guards, `min/max`, all inherit.
- Mixed int/float arithmetic: promote to double as today (`to_double` gains an
  mpz arm via `mpz_get_d`; lossy ≥2^53, same as any int→float, documented).
- `toint`: out-of-s32-range integral doubles now promote (`mpz_set_d`) —
  `ERR_TOINT` retires for magnitude, stays for NaN/±inf.
- `s2i` parses arbitrary decimals via `encodeIntLiteral`; `i2s` via
  `mpz_get_str` (seq_prims.h:460-509).
- Length/count producers (`size llen csize chas cmem sidx …`) stay s32
  producers (bounded by construction). Seq/str **index-consuming** kernels
  (`SLOG_SEQ_INT`, seq_prims.h:35, 249): an mpz index is definitionally
  out-of-bounds — take the kernel's existing OOB result, not a fatal.
- `$count` chain (`one/inf/cplus`) untouched (tagged s32 words 1/2).
- Error-arm registration: every mpz-producing prim (`+ - * pow shl s2i toint
  …`) becomes faultable via the caps (§14.4); each needs the new
  `mpz_overflow`/`mpz_table_overflow` arm relations registered the same way
  `/ %` get `div_by_zero` (operators.h:296 `rel()` fatals if unregistered),
  plus the two new `ErrorKind`s appended at database.h:1077 and their arms in
  `emit_pending_error` (operators.h:290-314).

### 14.4 The growth caps (RESOLVED D-int.1: two caps, both config-tunable)

Unbounded growth in a fixpoint is a real divergence vector (`(* x x)` doubles
bits per iteration). Two independent caps, enforced centrally in `encodeMpz`,
both wired through the dogfooded config system (config/*.slog → `setting->env`
in config.rkt → `envU64` in the Daemon ctor, daemon.h:76-89):

- **Per-value cap** — `SLOG_MPZ_MAX_BITS`, default **65536** (~19.7k decimal
  digits). Prechecks in `pow`/`shl` (`bits(base)·exp`, `bits+k`) so we never
  allocate a huge result just to reject it. Exceeding →
  `setPendingError(ERR_MPZ_OVF, …)` → `slog_error` → the deduction is
  abandoned and an `(error (mpz_overflow …))` fact is recorded instead of any
  other fact — exactly the div-by-zero mechanism (emit-cpp.rkt:53 check,
  operators.h:290-314 arm dispatch).
- **Whole-table cap** — `SLOG_MPZ_TABLE_BYTES`, default **~1GB**. The
  Database keeps an atomic approximate byte counter (limb bytes + entry
  overhead), bumped only on interning a NEW value (dup hits are free; the
  atomic check may overshoot by one in-flight value per thread — it is an
  approximation by design). Once exceeded, NO new mpz is ever learned: every
  interning attempt fails with `ERR_MPZ_TABLE` → `(error
  (mpz_table_overflow …))`. Set semantics dedup the emissions — the fixpoint
  converges with one such fact per rule location that tripped it, and all
  already-interned bignums keep working.

Two new `ErrorKind`s (append-only, database.h:1077) + two new arm relations
(`mpz_overflow`, `mpz_table_overflow`) registered compiler-side like
`div_by_zero`/`int_overflow`. Two new config settings (`mpz_max_bits`,
`mpz_table_bytes`) added to config.rkt's `setting->env` map and the default
config.

### 14.5 Lattices

`lat_num_min/max` (types.h:161-188) gain int-exact compare via `cmp_int` —
which needs the table, so `BTreeMapIndex` carries a `Database*` (set where
`lat_kind`/clamps are wired, index.h:113-115, database.h:425); `lat_join`/
`lat_clamp` thread it. LAT_COUNT and LAT_FLAT unchanged (FLAT's top is just
the relocated constant). `#:floor/#:ceiling` spec tokens stay s32-range
(database.h:389 `latClampOfSpec`); revisit only if a use case appears.

### 14.6 Persistence, import, compression — the leaf pattern

mpz is a **leaf** (no child words): strings' lifecycle, never cnode/seq
rebuild.

- **Save**: `value.mpz/` (8 partitions), records **length-prefixed** per
  §14.2's serialization — NUL framing is unusable, limb bytes contain 0x00;
  mirror `stageSeqWrite` (database.h:2401-2438) not `stageStringsWrite`.
  Call sites: `writeRelationBIN` :2453-2455, `writeDatabaseBIN` :2553-2555,
  plus an inline block in the serial checkpoint path `writeDatabaseSerialBIN`
  :2605-2611 (checkpoint-on-pause).
- **Load**: `loadMpzBIN` (gz + plain arms, re-intern in file order ⇒ ids
  reproduce) from `loadDatabaseBIN` :2821-2823 and `loadRelationBIN`
  :2894-2896.
- **Import/merge** (`importDatabaseBIN`): one leaf arm mirroring
  `is_mono_str` (database.h:3073-3084) — `scratch.lookup_mpz` →
  `remap[w] = encodeMpz(...)`. NOT self-encoding (content-hash ids are
  per-DB); do not touch the :3057 allowlist; removes the :3207 catch-all
  fatal. docs/db-merge.md: mpz joins strings as a content-addressed leaf
  space (contrast cnodes/seqs = rebuild spaces).
- **Compression**: zero new code — leaf heaps ride whole, never trimmed
  (database.h:2494 rationale); replay re-interns via `encodeMpz` and
  converges by content like strings (db-compression.md §4.3). SMT pinning
  unaffected (pinned answers are facts; their words remap like any fact).

### 14.7 SMT bridge (fixes a live truncation gap)

- Word→numeral: `render`/`intLit` (smt.h:128-162, 182-189) get an mpz arm via
  `mpz_get_str` decimal.
- Numeral→word: `smtParseModel`/`smtParseCore` (smt.h:801-876) currently
  `strtoll` → and `materialize` (oracle.h:417-429) **truncates to s32**.
  Keep the digit string, materialize via `encodeIntLiteral` — solver-returned
  bignums round-trip exactly now.
- `SmtGroundEval` (smt.h:430-449) evaluates in s64; extend to mpz or bail to
  the solver on overflow (either is sound; bail is smaller).

### 14.8 Compiler surface

- **Literals**: parser already yields exact bignums, unchecked (parser.rkt:
  139-141) — today 2^31..2^63 literals silently wrap and ≥2^64 breaks the C++
  build. The const-init arm (emit-cpp.rkt:812; also :181, actions.rkt:88,125)
  splits: in-range → `s32_encode(v)`; big → `db->encodeMpz("<decimal>")`,
  mirroring the string arm at :811 and for the same reason (must dedup with
  computed values). Negative literals already lex (lexer.rkt:71-78).
- **tycheck**: the `'int` accept arm (emit-cpp.rkt:447) becomes
  `(is_s32(v) || is_mpz(v))`. Surface type stays `int`
  (type-system.rkt:91 unchanged).
- **dbtool** (bulk binary-DB writer): tools.rkt:137-141 is the
  "BigInt prims not supported yet" gate. Supporting it means mirroring the
  intern-id function over §14.2's serialization in Racket (as tools.rkt:125
  does for strings) + writing `value.mpz/`. D-int.4: defer (keep a clean
  error) — bulk bigint ingestion can land separately; the id-function
  round-trip test is the acceptance gate when it does.
- **Version**: `slog-value-encoding-version` → 2 (§14.1, one bump covers
  both changes).
- **Build**: `-lgmp` in daemon Makefile `LDLIBS` and in the plugin flag list
  (tools.rkt:325-331 `extra-cxx-flags`). gmp dev confirmed installed
  (multiarch include path; `libgmp.so` present).

### 14.9 Decision points — ALL RESOLVED 2026-07-09

- **D-int.1 — caps**: per-value 65536 bits + whole-table ~1GB approximate
  byte counter, both config-tunable; distinct `mpz_overflow` /
  `mpz_table_overflow` error facts (§14.4).
- **D-int.2 — bitwise on bignums**: true-math view (GMP two's-complement;
  `shl` promotes exactly).
- **D-int.3 — legacy DBs**: hard break; version 1→2, clear `data/`,
  regenerate. IO upgrades fully with every encoding change.
- **D-int.4 — dbtool bigint ingestion**: deferred (clean error stays at
  tools.rkt:141; follow-up gated on a Racket/C++ id round-trip test).

### 14.10 Milestones (one day) + tests

- **M-int.0** sentinel move + `is_s32` mask + version bump (hard break, no
  translate) + delete `enum_prim_tag`; lockstep tools.rkt/dbmeta; clear
  `data/`. Pure refactor — curated suite subset must stay green with zero
  golden drift.
- **M-int.1** `mpz.h` (`mpz_val`, fasthash, kernels) + table + Database
  encode/decode + table byte counter + `-lgmp` both builds.
- **M-int.2** prims: s64 fast paths + GMP kernels + contraction; `cmp_int`
  arms in `SLOG_CMP`/`min`/`max`; `toint`/`s2i`/`i2s`; both caps + the two
  new ErrorKinds/arm relations + config settings + error-arm registration
  for newly-faultable prims.
- **M-int.3** lattice `cmp_int` (thread `Database*` into `BTreeMapIndex`);
  tycheck arm; literal emission split.
- **M-int.4** persistence: `value.mpz/` stage/load/serial-checkpoint +
  import leaf arm.
- **M-int.5** SMT numerals both directions.
- **M-int.6** goldens + unit battery.

Goldens (`int_*`): promote at every boundary op (`+ - * pow shl` at
±(2^31-1)); contract back down (`/ - abs`) and prove re-canonicalization;
canonicity via two derivation routes of the same bignum deduping to one row;
factorial/fib exactness through `i2s`; guards straddling the boundary;
min/max lattice over bignums; big literals (pos/neg); `s2i`/`i2s` round-trip;
per-value cap → `mpz_overflow` fact; table cap (tiny `SLOG_MPZ_TABLE_BYTES`)
→ one deduped `mpz_table_overflow` fact + fixpoint still converges; save/load
round-trip; import differential (api-tests §8 pattern); compression replay
verify; SMT model with a >2^32 numeral. Unit battery beside the
lat/collection ones in tests/unit.
