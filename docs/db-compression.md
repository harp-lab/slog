# Rule-based database compression (recompute-on-load)

*A `data/` folder of linked, stratum-aligned databases that store their deriving
program as source and are recomputed from origin on load, keeping only a target
percentage of the derived facts. 2026-07-07, rev 6 (finished design).*

**Status: P0+P1+P2 implemented (2026-07-07), forward-incremental only; hardened
2026-07-08** (edited-chain signature re-baseline §11.2, no-seed full-replay
verify `slog db verify --replay` §11.1, loud replay disk-fallback warning, §5.3
error-watch question resolved). The only unbuilt pieces are the §14
content-addressed struct id and DRed^c backward incrementality — both explicitly
optional. Sibling of `db-merge.md`,
`incremental.md`, `pausing.md`. This document is meant to be self-contained: if we
pick the work up months from now, everything we reasoned through should be here —
the model, the theory that constrains it, the on-disk format, the load algorithm,
the drift/attribution story, a decisions log with the alternatives we rejected, a
map of the existing machinery to reuse, and a concrete P0/P1/P2 task breakdown
against real files.

### Reading guide

- **Part I — Motivation & model** (§1–§3): what and why.
- **Part II — Theory that constrains it** (§4–§6): the value heap, id
  determinism, sampling math, stratum boundaries. Read this before touching code —
  it is where correctness lives.
- **Part III — The design** (§7–§14): the DAG, the on-disk format, program
  storage, load, drift reporting, edit-and-propagate, the `per` knob, the id
  north-star.
- **Part IV — Building it** (§15–§21): reused-machinery map, P0/P1/P2 task
  breakdown, testing plan, risks, open questions.
- **Appendix** (§22): value-encoding & id-space reference; decisions log.

### One-paragraph summary

Every database on disk is uniform: it links (by an ordered *manifest*) to one or
more input bin databases, records the *program* that derives it as a single
self-contained s-expr of slog **source**, and keeps its input's facts in full plus
a target **coverage percentage `per`** of the facts *it* derived (its IDB) chosen
by a closure-accumulation sample. Loading **always replays from origin**:
recursively materialise the inputs, merge them, recompile the stored program under
the *current* compiler, run its strata to fixpoint (regenerating the dropped
tuples), and verify the result against a stored content signature. `per = 100 %`
is the exact database (load is an immediate-fixpoint self-check); lower `per`
trades disk for a smaller witness. The whole `data/` DAG is a saved,
re-runnable, editable representation of an entire incremental program with all its
inputs.

---

# Part I — Motivation & model

## 1. Motivation, goals, non-goals

### 1.1 The problem

`--out-db NAME` today writes a database as *materialised tuples only*
(`writeDatabaseBIN`, database.h:1996): every relation, plus the interned-string
and collection-node tables, with **no record of how the tuples were derived**.
`-d NAME` reads them straight back (`loadDatabaseBIN`, database.h:2121). Two costs
grow over time:

- **Disk.** A transitive closure or a big join is tiny to *describe* (a few rules)
  and enormous to *store*. Abstract-interpretation outputs (kcfa/schemecfa) blow
  up similarly.
- **Load time.** Loading a large binary database, and especially compiling a huge
  inline block of ground rules, is slow. The tutorial already warns that inline facts are
  "unwise for hundreds of thousands" of rows.

### 1.2 The goal

Add a **compressed** database format for *derived* data:

> Store the program's **input** (in full, as a linked bin db), a portable copy of
> the **program** that derived the rest, and a **sample** of the derived output.
> On load, re-run the program to fixpoint to regenerate everything, then verify
> the sample survived. The format is **recursive**: an input may itself be a
> compressed derived db, so a whole chain of program stages compresses to one base
> input plus a stack of recipes.

### 1.3 Payoff

- **Disk**: keep the rules, drop most of the answer.
- **Provenance & incrementality**: the stored recipe makes a database a
  *program+dataset* you can re-run, extend (pipeline a new program), or edit
  in place with changes propagating downstream (§12).
- **Latest-semantics tracking**: because we store source and recompile on load, an
  old database automatically benefits from (and is tested against) compiler
  improvements, with drift surfaced as a warning (§11).

### 1.4 Non-goals (for the first cut)

- Not a general-purpose incremental engine — that is DRed^c (`incremental.md`),
  which this composes with but does not require (§12).
- Not byte-identical reproducibility across runs — we compare by *content*, not
  bytes (§4). Byte reproducibility is an optional north-star (§14).
- Not automatic optimal tuning of `per` — a follow-on study; a fixed default plus
  a simple heuristic is enough to ship (§13.1).

---

## 2. The core reframe

Three ideas make the feature tractable; internalise them before the details.

**(a) The deductive rules ARE the compression; the kept sample is an integrity
witness, not data.** Recompute regenerates the entire least fixpoint
deterministically (§5), so the kept fraction is never *needed* to reconstruct the
database. Its job is to catch the cases where recompute would silently produce
something *different*: a compiler semantic change, a nondeterminism escape hatch
(§5.3), or a compression bug. This is why the sample is stored and compared
**content-addressed**, never as raw tuple bytes (§4).

**(b) Loading always replays from origin.** There is one code path for exact and
compressed databases; they differ only in how much each fixpoint must do. This
single decision buys two things almost for free: **sound deletion / edit-and-
propagate** (full replay from an edited origin is the true least fixpoint,
including retraction — §12), and a natural **self-verifying** exact db at
`per = 100 %` (§5).

**(c) Inputs are links, not copies.** A database references its input(s) by name;
`data/` becomes an immutable object DAG (§7). Shared ancestors are stored once, and
the DAG *is* the serialized incremental program.

---

## 3. The model at a glance

```
data/base ──▶ data/mid ──▶ data/top        (each ──▶ is an input-manifest entry)
        \                      ▲
         ▶ data/other ────────/            (data/top's manifest = [mid, other])
```

- **A node** = `(input manifest, program, kept data, signature, META)`.
- **A root** = a pure-EDB bin db (no program; `per = 100 %`): a CSV import
  (`convert-db-folder`) or a from-scratch program's captured input snapshot
  (§7.1). Every replay bottoms out at roots.
- **An edge** = a manifest entry: `data/top` is derived by running its program atop
  the merge of `data/mid` and `data/other`.

Worked example. `reach.slog` computes transitive closure over `edge`:

```
$ racket slog.rkt --out-db-compressed reach --per 60 reach.slog
# writes data/reach.edb/    (root: the edge facts, snapshot before any rule fired)
#        data/reach/META    (manifest=[reach.edb], per=60%, stamp, versions, seed)
#        data/reach/prog.sexpr   (the whole source tree of reach.slog)
#        data/reach/table.path.arity.2/  (~60% of derived path tuples + heap closure)
#        data/reach/signature            (full-coverage checksum of path)

$ racket slog.rkt -d reach --sizes analyze.slog
# load(reach): materialise reach.edb -> replay reach's program to fixpoint
#              (regenerates the other ~40% of path) -> verify signature
#              -> then run analyze.slog atop it
```

---

# Part II — The theory that constrains it

## 4. The value heap, sampling, and id convergence

Recompute reproduces the *logical* least fixpoint deterministically, but **not the
byte/id layout**. This is the single most important fact in the design.

- Struct-instance ids are minted as a per-bucket allocation-order counter
  (`InternStructTask`, operators.h:490); encounter order is nondeterministic even
  at a fixed thread count (dynamic work-stealing dispatch, database.h:1240;
  per-thread shard concatenation, database.h:590).
- String ids are content-addressed (FNV low bits, intern.h:269) *except* on a rare
  hash collision, where the chain index is insertion-order dependent
  (intern.h:95-148).
- Collection-node ids are content-hash + collision position, and node contents
  embed other id words (db-merge.md §2).
- Only `s32`/`float` self-encode and are portable across runs.

The authors already state it: *"struct ids and interned-string ids are only stable
within the database directory that wrote them"* (database.h:2175-2177). See
db-merge.md §2 for the full id-space table, reproduced in §22.

### 4.1 You sample facts, never the heap — and keep complete subtrees

A relation tuple can hold **references into a heap**, not values-in-place:

- **struct instances** — a `struct.NAME` row keyed by an id word whose fields are
  themselves id words, recursively down to scalars/strings/`nil`;
- **collection nodes** — Patricia-trie DAGs in `value.nodes`, whose node contents
  embed further id words;
- **strings** — interned bytes in `value.strings`.

So the database is *relation tuples over a value heap*. Consequences:

- Retention selects top-level **facts** (table/lat tuples), never heap entries
  directly.
- For every kept fact, keep the **complete transitive closure** of the
  structs/strings/nodes it references — the whole subtree, to the leaves — or the
  fact dangles. `importWord` fatals on a dangling child (database.h:2373); a struct
  is atomic (no half a cons cell, no parent without its children).

**So: must every saved struct be a complete subtree? Yes — guaranteed by taking
the referential closure of the sampled facts, not by hoping a random heap sample
is whole.** The walk already exists: `importWord` (database.h:2344) is a
children-first, cycle-guarded dereference over the struct/cnode/string DAG.
Repurpose it as "mark the heap reachable from this fact."

**Practical limit:** a random 25 % of *facts* can pull in far more than 25 % of the
*heap* when structures are large or shared. Closure, not the `per` knob, sets the
real footprint of struct-heavy relations — which is exactly why we count coverage
over the *union* of facts + heap (§4.2).

### 4.2 Choosing the kept set: coverage by percentage (not probability)

Retention is a **target coverage `per` ∈ [0,1]** (e.g. 60 %) over droppable
records, **not** an independent per-fact coin flip. "Records" counts IDB relation
tuples **and** IDB-heap (structs/cnodes/strings this program interned, i.e.
reachable from IDB but **not already present in a linked input**). The save loop:

```
D          = |IDB tuples| + |IDB-heap|                # denominator: everything droppable
input_heap = heap records already in a linked input db   # provided on load, never re-saved
kept       = ∅
pool       = order(all IDB top-level table/lat facts)    # shuffle (default) or legacy §4.4.5 bias
for fact in pool:
    if |kept| / D >= per: break
    kept += fact
    kept += closure(fact) \ input_heap                # full struct-trees; deduped into kept
```

Because each pick pulls in its **whole** struct-tree and the budget spans the
union, **the struct-to-table ratio emerges from the DB's topology** — a fact
hanging off a deep tree spends more budget than a scalar one, self-balancing to
`per` with no manual tuning. Overshoot is at most one fact's closure (the loop
stops the moment coverage crosses `per`). Details:

- **Heap shared with an input is free.** `closure(fact) \ input_heap` skips structs
  the linked input already stores; on replay the input provides them and
  content-dedup reuses their ids (§4.3). This both shrinks the save *and* is what
  lets the linked model resolve those references at all.
- **`per` counts records; disk is close but not identical** (rows vary in width;
  strings are variable-length). Counting *bytes* would target disk directly — a
  one-line change if disk matters more than "fraction of facts." (Open Q, §21.)
- **Per-relation coverage is emergent, not guaranteed.** A rare relation may get
  few or zero sampled facts at a given `per`. That is fine: the full-coverage
  `signature` (§8) checks every relation regardless; kept records are distributed
  spot-checks + seed, not the integrity floor. Add a per-relation minimum only if
  guaranteed witness rows per relation are wanted.
- Record the RNG seed in `META` so an exact kept-set is reproducible for debugging.

### 4.3 Id convergence within one lineage already works

The worry: a kept struct (old id) and its re-derived twin (fresh id) coexist,
breaking slog's constant-time (**by-id**) struct equality — a headline feature
(two structs are equal iff same id word). This does **not** happen for a single
database's seed+recompute, because `InternStructTask` dedups fresh structs **by
content** (`lower_bound` on the content columns, ignoring the id slot,
operators.h:481-495):

```cpp
auto it = root->lower_bound(low);                 // low = content cols, id slot = 0
bool dup = (it != root->end());
if (dup) for (c…) if ((*it)[c] != batch->data[j+ord[c]]) dup = false;
if (dup)  batch->data[j] = slog_null;             // content match -> reuse the loaded id
else    { batch->data[j] = struct_encode(struct_id, (*intern_alloc << bucket_bits)|bucket);
          ++(*intern_alloc); root->insert(key); } // genuinely new -> fresh id
```

A re-derived struct whose content matches a loaded one is nulled (its loaded id is
reused); genuinely new structs draw ids from allocators `seedInternAllocators`
(database.h:650) bumped above every loaded id, so they cannot collide. **This is
the exact mechanism that makes `-d`/`run` chaining preserve struct ids today**
(db-merge.md §7.1 PINNED). Therefore **seed-a-subset-then-recompute is correct on
existing machinery**, provided `seedInternAllocators` is right — a documented
data-loss bug class if it is not (the 400→392 bug), so test it hard rather than
redesign (§19).

The genuinely hard id problem is **cross-database** merge (two independent id
lineages), which `importDatabaseBIN` already solves by content-remap. A manifest
merge (§7.2) routes through that same remap, so even multi-input compression stays
on the correct side of the line. **Consequently content-addressed ids (§14) are an
optional accelerator, not a prerequisite** (this corrects earlier revisions of
this doc).

### 4.4 Accelerator seeds: round-structured selection via the seed sidecar (v2, 2026-07-11)

*(v1 of this section proposed a static fan-out "productivity" score; it shipped
as P2.4 `--bias productivity` and survives as the §4.4.5 footnote. The analysis
below supersedes it — designed 2026-07-11, sprint plan in §18.1.)*

#### 4.4.1 What a seed can and cannot buy

Under always-full-replay, kept tuples are content-deduped, not skipped (§4.3):
every rule instantiation still fires exactly once during replay no matter what
is seeded, so total derivation **work is invariant under seed choice**. The
only thing selection controls is the **critical path** — replay's semi-naïve
round count, i.e. the deepest residual derivation chain among unseeded tuples.
Seeding collapses sequential rounds into parallel round-0 work; it never
removes work. "Best N %" is therefore a **min-max gap problem** (space cuts
evenly along derivation chains), not a "most valuable tuples" problem. Four
consequences, in order of importance:

1. **Round-stepping lemma (linear rules).** In a rule with exactly ONE
   same-SCC body occurrence, a tuple first derived at round `r` has its dynamic
   antecedent at round `r-1` *exactly* (semi-naïve fires when that antecedent
   enters delta). Chains step one round at a time, so a **complete** kept layer
   at round `k` hard-resets replay depth to zero at `k`. With ≥2 same-SCC
   occurrences the guarantee leaks (the older antecedent may sit at any
   `r' < r`, threading past a cut) — but those fronts double and stay shallow.
   Depth lives in linear rules; that is where cuts have teeth.
2. **Deep-bias alone is wrong.** On a chain of depth `D`, keeping the deepest
   20 % leaves an unbroken `0.8·D` prefix → replay ≈ `0.8·D` rounds. Keeping
   every 5th *round* gives ≈ 5 rounds, all segments advancing in parallel.
   **Spacing beats depth.**
3. **Uniform random is a strong baseline — with backwards budgeting.**
   p-sampling yields geometric gaps along chains, mean `1/p` (5 rounds at
   20 %): the default shuffle already captures most of the even-spacing win in
   expectation. Its flaw is allocation: budget lands ∝ layer size — mostly in
   fat early layers whose tuples replay in a round or two anyway — while the
   long thin tail, where the round count actually lives, gets a proportional
   pittance.
4. **Lattices break the work-invariance ceiling.** Lattice exact-once is per
   *value-change*: a seeded FINAL value turns every replayed candidate into a
   no-change merge → no delta → no downstream re-fire. Final lattice values cut
   rounds AND real work; one tuple per key retires an unbounded ascending
   chain. (Prereq: §19A exempts lattice-headed staged rules from seeded
   re-entry tasks — soundness spike in §4.4.5.)

#### 4.4.2 The mechanism: a per-round quota reservoir (the seed sidecar)

One runtime rule realises the whole policy. For each relation of a **selected
SCC** (below), at the end-of-round delta reorg, copy that round's delta into
an in-memory **seed sidecar**, tagged with the round number — **whole if it is
small** (≤ the `q` floor: a complete layer, a hard cut), **else a `rate`
sample of it** (default 10 %, decided 2026-07-11 — fat rounds get proportional
probabilistic cover). The quota is **per relation** (not shared across the
SCC): a size-skewed SCC cannot starve a small member relation's cut points,
at slightly more disk than a shared pool. Recording is always on for selected
SCCs (it is O(kept)/round); whether to *write* the sidecar is decided at save.

- **Thin rounds fall under quota → kept whole → complete layer cuts** (hard
  resets, lemma 1). The long tail is retained nearly complete — the "suffix
  save" *emerges* rather than being a separate mode.
- **Fat rounds get `q` of `s_r`** — sparse probabilistic cover, all they merit.
- Kept volume = `Σ min(q, s_r)` ≈ `q × rounds`: budget scales with the thing
  being bought (round cuts), not with DB size. This inverts uniform sampling's
  allocation and is why 5–10 % budgets are realistic — in long-tail workloads
  the tail is ~1 % of tuples but ~90 % of rounds.

**Cap policy — drop whole rounds, never within rounds.** A complete thin layer
is a hard cut; a half layer is leaky. When the sidecar exceeds its byte cap,
**decimate by halving**: drop every other retained round (spacing doubles,
stays even at every scale, O(1) amortised). Contiguous complete runs of rounds
(the tail) coalesce into one storage group — round identity only matters at
gaps.

**SCC selection is static and mostly a kill list** (stratify.rkt has all the
inputs). Score each SCC:

| Tier | Predicate | Why |
|---|---|---|
| 3 | contains lattice-headed relations | final-value super-seeds (work + rounds) |
| 2 | ∃ recursive rule with exactly one same-SCC body occurrence (**linear**) | hard layer-cut guarantee |
| 1 | recursive, all recursive rules ≥2 same-SCC occurrences | doubling fronts, shallow — skip by default |
| 0 | non-recursive | replays in O(strata) rounds — never seed |

Default: sidecars for tiers ≥ 2 (`SLOG_SEED_TIERS` widens). **Selection** is
at SCC granularity (every IDB relation of a qualifying SCC gets a sidecar — in
a mutual recursion chains alternate relations round by round, so covering only
one member relation would cover only every k-th cut point); the **quota** is
per relation within it (see above).

**Lattice variant — same reservoir, different materialisation.** For lattice
relations the sidecar stores KEY WORDS only (an entry whenever a key's value
changes that round); at save each retained key is materialised at its CURRENT
(final) value by a point lookup, deduped by key keeping the latest round tag.
Intermediate values are never stored; "late finishers" (ends of long
relaxation chains — the valuable keys) land in late round buffers
automatically, and decimation keeps them evenly spaced.

**Sampling cost is two O(|delta|) passes** (count live rows, then a
Bresenham-even pick), run single-threaded at the iteration barrier — the same
order of work as the delta reorg the loop already does each round; measured
~15µs/round on thin deltas, ~180µs on ~3000-emission rounds (§4.4.5). The
sidecar has NO statistical role (the witness keeps that job, §4.4.3), so the
even pick needs no randomness.

Knobs (as built; all daemon-side env): `SLOG_ACCEL=0` (recording kill
switch), `SLOG_ACCEL_RATE` (fat-round sample rate, default 0.10),
`SLOG_ACCEL_QUOTA` (whole-round floor `q`, default 64 rows — the keep rule is
`min(live, max(q, ceil(rate·live)))`, additionally clamped so one round never
eats over a quarter of the cap), `SLOG_ACCEL_MB` (per-stratum byte cap,
default 64), `SLOG_ACCEL_MIN_ROUNDS` (default 16). Every sampled save
(`per < 100 %`) requests the sidecar; it is *written* only for strata whose
recorded fixpoint ran ≥ `SLOG_ACCEL_MIN_ROUNDS` rounds — below that, replay
is round-cheap and the sidecar is dead weight (§13); with rate-sampling a
shallow fat stratum would otherwise write 10 % of everything for nothing.
META records `accel #t/#f` (whether accel/ materialised). Tier widening
(`SLOG_SEED_TIERS` in the v2 draft) is NOT built — tiers ≥ 2 are fixed in
the compiler's scorer (`stratum-accel-rels`, compile.rkt).

#### 4.4.3 Two files, two roles: witness vs. accelerator

The §4.2 content-hash kept set stays exactly as shipped and keeps the
**integrity/drift** role: uniform, order-independent, content-stable across
saves. Round-structured selection churns under program edits (rounds shift),
so it must NOT share the witness's file or its drift comparison. The
accelerator is a separate `accel/` subtree of ordinary relation dirs (same
row format, storage order; heap closure joins the db-level
`value.strings`/`value.nodes`/struct trim via markKeptStructs, §4.1) plus
`accel/manifest.sexpr`. *(As built 2026-07-11: ONE merged dir per relation —
rows from all retained rounds of all gated strata concatenated; a lattice
relation dedups by key keeping the latest recorded post-merge value. The
manifest records, per stratum, `(generation, round, complete?, rows)` for
every retained round — per-ROW round attribution is deferred. Storage
grouping cannot affect replay: the layer-cut property is per-round
completeness at record time, not on-disk adjacency.)* Round metadata costs
nothing to keep and is exactly the provenance-lite timestamping DRed^c will
want on seeds later (consistent with incremental.md §8B — counts regenerate
and are never persisted; round tags are static provenance, not counted
state). Load ingests `witness ∪ accel` identically (any-subset
soundness, §2a); the `--replay` no-seed verify ignores both; drift compares
the witness only. `per` continues to denominate the witness alone — total
disk = witness(`per`) + accel(cap).

#### 4.4.4 Honest limits

- **Deep-and-fat is the one shape this cannot beat**: every layer over quota →
  all cuts probabilistic → gaps stay ~budget-proportional, same as uniform.
  Such a DB is huge and replay is throughput-bound — the data-parallel engine
  is the answer there, not seeding. Benchmarks must say so before someone runs
  dense TC and concludes the feature is broken.
- **Rounds must dominate for any of this to matter** (§13): a 40-round stratum
  gains nothing; a 20,000-round chain or SSSP-style relaxation gains
  ~everything. Hence the `accel_min_rounds` gate.
- Multi-dynamic rules leak cuts (lemma 1) — accepted; mixed SCCs still profit
  through their linear rules.

#### 4.4.5 As-built details (shipped 2026-07-11; see §18.1 for the map)

Pinned (2026-07-11):

- Sidecar lives in the daemon `Database`/run state, NOT the stratum `.so` — it
  must survive tiered O0→O2 hot-swap reloads mid-fixpoint.
- Round tag = per-stratum-fixpoint counter; a re-entered stratum (session
  batches, incremental.md §0) appends under a bumped **generation** prefix,
  same cap, global decimation; `(generation round)` both recorded in
  `accel/manifest.sexpr`.
- Checkpoint-on-pause (P2.3) DROPS the sidecar — accel is an optimisation;
  correctness never depends on it.
- Exclusions: temps (never persisted), `$stat_*` (already excluded from
  saves), side-channel/oracle rels (SMT answers are memo-*inputs* saved whole
  — pinned doctrine), `full-store-rels` (already 100 %).
- Rows are copied as raw u64 words at the iteration barrier
  (`EndIterCompletion` — single-threaded, delta finalized+interned+idle);
  the save-time writer runs normal closure-completion over them (§4.1).
  Note the sampled delta is the round's raw EMISSIONS: rows that a later
  write-phase insert dedups away are still genuine derived tuples of the
  least fixpoint, so sampling them is sound — just mildly redundant.
- **Retraction safety is by invalidation, not filtering**: `del-tuple`,
  `del-batch`, `clear-rel(-at)`, `rename`, and `drop` call
  `accelInvalidate(rel)` — a mutated relation's sidecar buffers are dropped
  wholesale, so a deleted tuple can never resurrect as a seed on replay.
  Fresh single-program runs (the common save) never pay this.

Spike results (all closed 2026-07-11):

1. **Lattice seeding soundness**: accel_lat_chain (150-round min-int chain)
   is content-equal at per ∈ {100,60,20,5} with accel seeds — the §19A
   lattice-headed exemption does not bite (accel rows enter as ordinary
   iteration-0 delta through the same import path as kept rows).
2. **Hook cost**: ~15µs/round on 10-row deltas (broom), ~180µs/round on
   ~3000-emission rounds (braid) — visible only against an O0
   per-round-overhead-dominated fixpoint (≲25 % there, noise elsewhere);
   two O(|delta|) passes, same order as the reorg the loop already does.
3. **Round-shape findings** (bench, 2026-07-11): on wide-ancestor-cone data
   (ER, braided DAGs) the uniform witness ALONE collapses replay (701→10
   rounds at per=10; parity with accel even at per=2 — exponential ancestor
   cones make any seed set a log-depth cut), confirming §4.4.1's
   uniform-baseline claim. Differentiation appears exactly where predicted:
   thin/chain-shaped data (broom: ER core + 10×3000 chains) replays 3009→6
   rounds with accel vs 27 (per=10) and **117 (per=2)** without — ~20× and
   per-independent, since the sidecar is drawn per-round, not per-fraction.
   SSSP braid (tier 3): 1400→123 vs 177. ER honest-negative: 9 rounds, gate
   keeps accel/ absent.

Footnote — the shipped static fan-out bias (P2.4 `--bias productivity`,
`compile.rkt` `productive-rels`): under exact-once it buys only slightly
earlier availability — the weakest lever here. It stays a documented save-time
flag until the sidecar lands; then fold `--bias` into `--accel` and retire it.

---

## 5. Determinism, replay, and the escape hatches

### 5.1 What is and isn't deterministic

- **Deterministic:** the *logical* least fixpoint of monotone rules — the set of
  tuples taken as content (struct type + recursively-decoded fields, string bytes,
  scalar values) — is order- and thread-count-independent.
- **Not deterministic:** the byte image — struct-instance ids, string collision
  chains, tuple/file ordering — for the reasons in §4.
- **Deterministic given the id words:** `writeDatabaseBIN` shards each relation
  into per-bucket files in btree-sorted order (database.h:1647, 1884), so identical
  id words ⇒ identical bytes. The only byte nondeterminism is the ids.

### 5.2 Why replay reconstructs the data (but not the bytes)

Loading a *stored* db round-trips ids exactly because they are in the files
(`readBIN` copies struct-id words verbatim; `loadStringsBIN` re-interns in file
order, database.h:2059-2062). A *recomputed* db re-derives from the EDB and
re-mints ids — landing on the same logical set (§5.1) but different bytes. That is
fine because we compare by content (§4, §8).

### 5.3 Escape hatches (things that can break "logical set is deterministic")

The premise holds for monotone rules; watch:

- **`(error e)` watches that kill the fixpoint.** *Resolved 2026-07-08 — not an
  issue under the shipped semantics.* The `(error (error_spec …))` runtime-error
  facts (2026-07) are ordinary monotone facts: the driver's watch
  (`runslog.rkt` `check-errors!`) dumps the reserved `error` relation at each
  stratum fixpoint and **warns without stopping**, so the fixpoint always
  completes and the logical set stays deterministic (`error` included — it
  compresses like any relation). A daemon-level `(error …)` reply aborts the
  run *before* any save action fires, so a partial (timing-dependent) database
  is never written. `META`'s `full-store-rels` therefore stays **reserved**: it
  becomes live only if a hard-stop error mode (terminate-on-first-error) is
  added, at which point relations reachable from error rules must be forced to
  `per = 100 %` as originally planned.
- **Lattices**: the converged value is order-independent iff the merge is
  commutative/associative — true by kind; confirm the collection-arena
  (`LAT_EXTERN`, `intern4`) path (open Q, §21).
- **Floating-point** non-associative reductions inside a lattice.
- **Any future non-monotone feature.**

The `signature` check (§8, §11) turns each of these from silent corruption into a
loud verify failure, and the compiler stamp (§11) tells them apart from an intended
compiler change.

---

## 6. Stratum boundaries give a clean EDB/IDB split

The recurring blocker — *there is no EDB/IDB marker on disk* (db-merge.md §7.2),
`loadDatabaseBIN` ingests every relation dir identically — dissolves once each
database is a **subsequence of strata**:

- The compiler condenses the rule dependency graph into an SCC DAG and schedules it
  by level (`stratify.rkt`: `level = 1 + max predecessor level`, same-level SCCs
  merged into one stratum). Each relation is **completed within its SCC's
  stratum**, so it is unambiguously derived in exactly one stratum.
- The compiler knows, per stratum, its **head relations** (IDB) and its body-only
  relations (EDB from lower strata) — `rule-head-rels` (stratify.rkt:53).
- **At save**, a layer's **IDB = the union of head relations over its stratum
  range**; its **EDB = the merged input manifest** (§7.2). Coverage `per` applies
  only to IDB; EDB is always whole.
- The awkward mixed case — a relation both grounded by body-less rules and derived by
  other rules in the same layer — resolves by the boundary definition: those ground rows land in
  the base layer's EDB *snapshot* (§7.1, the iteration-0 state before rules fire);
  the derived extension is the deriving stratum's IDB. No post-hoc un-mixing.

A saved database therefore records its stratum range `[s_a..s_b]` in `META`, and a
chain of databases partitions a whole program's strata into contiguous segments.

---

# Part III — The design

## 7. `data/` is an immutable object DAG (with GC)

Linking instead of nesting turns `data/` into a dependency graph managed like an
object store.

- **Immutability by default.** A database that is an input to another is frozen;
  overwriting it would silently change every dependent's provenance. `--out-db X`
  onto a referenced `X` is refused unless forced (and forcing must invalidate
  dependents, §12). The sanctioned way to change a referenced layer is
  **edit-and-propagate** (§12).
- **Dependency-aware deletion.** `slog db rm X` refuses if `X` has dependents;
  `--cascade` removes `X` with every transitive dependent (unloadable without it);
  `gc` removes orphans nothing links to; `clear` wipes `data/`.
- **Discoverable DAG.** Each `META` names its input manifest; a scan of all
  `data/*/META` builds the graph (keep an index for speed). Enforce acyclicity at
  save. Each edge records the input's **expected version stamp**; if an input's
  stamp changes, its dependents are marked **stale** (their materialisation must be
  recomputed) rather than silently wrong.
- **Atomic writes.** Write into `data/<name>.tmp/` then `rename` over
  `data/<name>/`; never `remove_all` a database another layer depends on. Today
  `writeDatabaseBIN` does `remove_all(db_dir)` (database.h:1636) then parallel
  writes — unsafe for an in-place recompress of a referenced layer, and worth
  fixing for plain `--out-db` too.

New tooling: a `slog db` command — `ls`/`tree` (show the DAG, `per`, sizes,
staleness), `rm [--cascade]`, `gc`, `clear`, `verify [--replay]`.

> **Known wart (2026-07-08): `gc` vs. an in-flight save.** META headers are
> stamped by the driver post-exit (P0.5 note), so a freshly written `.edb` root
> is unreferenced for a short window; a concurrent `slog db gc` will collect it
> and break the save's layer. data/ management assumes a single writer — don't
> run `gc` while a save is in flight (observed once as a harness race). The
> clean fix, if it ever matters, is stamping the root's META at snapshot time
> instead of post-exit.

### 7.1 Every input is a bin database first

A compressed database's EDB is always a materialised bin db it links to. Two cases
at save:

- **Chained run (`-d X`)**: the EDB already *is* the bin db `data/X` — link it.
- **From-scratch run (inline ground rules)**: the EDB is the **iteration-0 snapshot**,
  the database state after facts are ingested but before any rule fires (§6).
  Materialise *that* as a pure-EDB root bin db, then link the compressed layer to
  it.

So there is never an inline/ephemeral EDB to reconstruct: roots are pure-EDB bin
dbs (`per = 100 %`), and every derived layer stands on one. Mechanically, the
driver issues a `(write-db <name>.edb)` action *before* sending the first stratum
plugin, reusing the existing writer.

### 7.2 Merging inputs is an ordered manifest, not a special node

Between two strata is the only place the daemon admits a database: `open` before
stratum 1, `import` at any stratum boundary — both set `needs_reload`, consumed by
the next `beginStratum`'s `reloadInsertBatches` (database.h:2525); both are refused
mid-suspend (daemon.h:105-114). So the natural merge is:

> materialise each input (recursively), **`open` the first, `importDatabaseBIN` the
> rest in order**, then run this layer's strata atop the union.

Consequences:

- **Merge is not a special node** — a pure merge (`dbC = dbA + dbB`, no new rules)
  is a 2-entry manifest with an *empty* program. Every node is
  `(manifest, program)` with zero-or-more strata.
- `importDatabaseBIN` reconciles ids by content (strings by content, struct types
  by relation name, instances children-first content-dedup via `internStructTuple`,
  collections rebuilt via the arena kernels), so tables **union**, lattices **join
  per key**, structs **dedup by content**.
- **Order** decides only which db's ids are preserved (the first, opened) vs.
  remapped (the rest, imported) — never the logical (content) result, since union
  and join commute. Record the order in `META` for a canonical id layout.
- **Schema must agree** across same-named relations (arity, table/struct/lattice
  kind, lattice spec) or `importDatabaseBIN` fatals — a real constraint for
  multi-input pipelines.
- **Merge-then-run is a monotone over-approximation** (db-merge.md §7.2): facts
  from any input persist even if their grounding is absent in the union; the
  program atop can only ADD. Retraction across a merge is edit-and-propagate's job
  (§12), not merge's.
- **Diamonds** (a shared ancestor reached two ways) are fine: it materialises once
  (memoised, §10) and content-dedups at merge.

This is the whole "tree with multiple loaded DBs": a node with an N-entry manifest,
each entry its own subtree. The DAG of `(manifest, program, kept-data)` nodes **is
the serialized incremental program with all its inputs**; loading reconstitutes it,
and you extend it by pipelining a new layer or edit it in place (§12).

### 7.3 Flattening to static bins (the unusual mode)

By default a save links atop the incremental program tree. `--flatten` instead
materialises the db and writes it as a standalone bin db with **no program or
manifest** — today's plain `--out-db`, i.e. a root. Use it to cut a chain (share a
dataset without its recipe, freeze a checkpoint), accepting that it can no longer
be recomputed or edited-through. It is the exception; linking is the default.

---

## 8. The on-disk format (per database)

```
data/<name>/
  META                # keyed s-expr, read by the driver (see fields below)
  prog.sexpr          # ONE self-contained s-expr of the whole include/run tree of slog
                      #   SOURCE; recompiled under the CURRENT compiler on load (§9).
                      #   Absent for pure-EDB roots.
  edits               # ordered explicit EDB mutations applied at boundaries (§12); optional
  <relation dirs>     # the KEPT records, today's exact binary layout, CLOSURE-COMPLETE:
                      #   table.NAME.arity.N/ struct.NAME.arity.N.id.SID/ lat.NAME.arity.N.spec.TOK/
                      #   value.strings/ value.nodes/
                      #   (EDB relations absent — they live in the linked input; IDB at coverage
                      #    per; heap = closure of what is kept minus what a linked input has, §4)
  signature           # per IDB relation: (count, commutative-content-checksum) over the FULL
                      #   IDB, computed at SAVE before dropping — full-coverage integrity
  signature.edited    # drift baseline for an EDITED chain (§11.2), keyed by a digest of the
                      #   chain's load recipe incl. edit ops; written by the first post-edit load
  accel/              # OPTIONAL round-structured accelerator seeds (§4.4 v2): one merged
                      #   relation dir per sampled rel (kept-records format, storage order)
                      #   + manifest.sexpr of per-stratum round provenance
                      #   (generation round complete? rows); ingested as extra seeds on
                      #   load (open + import both), EXCLUDED from drift comparison; heap
                      #   closure lives in the db-level value.strings/value.nodes/struct
                      #   dirs like all kept facts
```

**`META` fields** (a keyed s-expr; version everything):

| Field | Purpose |
|---|---|
| `format-version`, `magic`, `endianness` | reject/parse foreign files loudly |
| `manifest` = ordered `[(name stamp) …]` | input links + their expected version stamps (§7) |
| `stamp` | this db's content/version stamp (for dependents' staleness checks) |
| `strata` = `[s_a … s_b]` | the stratum range this db represents (§6), by stable rule-id set |
| `per`, `rng-seed` | retention target + sample seed (§4.2) |
| `value-encoding-version` | daemon NaN-box/interner version — gates bin readability (§9) |
| `compiler-stamp` | `compiler-sources-fingerprint` (tools.rkt:36) that produced `signature` (§11) |
| `env` | result-affecting env (`SLOG_NO_SEMIJOIN`) captured for faithful recompile |
| `fixpoint-wall-ms` | recorded cost, for the load policy / `per` heuristic (§13) |
| `pure-edb?` | true for roots (no `prog.sexpr`) |
| `full-store-rels` | relations forced to `per = 100 %` (nondeterministic, §5.3) |
| `accel` | accelerator-seed summary if `accel/` present: `(quota cap-mb tiers groups rows bytes)` (§4.4) |

Notes:

- **Kept records are an ordinary database written by the canonical writer** — no
  new tuple codec, internally id-consistent, closure-complete by construction. The
  writer just receives the sampled + closure-completed subset instead of the whole
  relation.
- **The kept IDB *is* the sample** — there is no separate witness store. It seeds
  the replay and is checked as a content-subset of it (§10). The one extra artifact
  is `signature`, over the *full* IDB at save (before dropping), so replay is
  checkable for full coverage in O(n) without decoding every tuple.
- **The signature is over *decoded, id-free* content** (a commutative
  combine — e.g. 128-bit XOR+sum of per-tuple SipHash of the recursively-decoded
  term), so it is comparable across runs despite id reassignment. Raw-byte
  checksums would spuriously mismatch on every recompute.

---

## 9. Store the program as one s-expr source tree — recompiled on load

Store the program as a **single self-contained s-expr file**: the entire
include/run closure of `.slog` **source**, by file identity, with the tree edges,
the entry point, and result-affecting env. It is a saved *copy* of the source,
independent of what those files become on disk later (satisfying "the program tied
to a saved DB is a saved copy, even if it changes elsewhere").

On load, feed it to the **current** compiler (parse → simplify → typecheck →
stratify → plan → emit → run). This is a deliberate choice:

> **Compiler improvements — optimisations *and* breaking semantic changes — are
> immediately observed when a database loads**, and the witness (§11) reports when
> a change altered the result. We trade frozen reproducibility for always-latest
> semantics, which is what an evolving compiler wants.

Rationale and consequences:

- **Source, not IR/`.so`.** Storing source insulates the recipe from every compiler
  change downstream of the parser. `.so` and crule IR are **ephemeral build
  caches** (`build/<hash>.so` keyed by the compiler+daemon fingerprints,
  tools.rkt:32-36; `finish-jit`, tools.rkt:311), regenerated on demand, never part
  of a saved db. (Earlier revisions proposed storing crule IR for literal replay;
  we reversed that — see the decisions log, §22.)
- **The one residual coupling is bins ↔ the NaN-box value encoding.** A
  value-encoding change requires migrating the **root** EDB bins
  (decode-old/encode-new — unavoidable for any binary format); every **derived**
  layer's bins are simply dropped and replayed under the new encoding. `META`'s
  `value-encoding-version` lets load detect a mismatch and migrate/refuse rather
  than misreading struct fields at the wrong offsets.
- **Frozen reproducibility** against a specific compiler is a version-pinning
  concern outside this format (pin the compiler, not the db).
- **What to serialise.** Prefer raw source text per file plus the tree structure,
  so the *current* lexer/parser run (maximally robust to compiler changes). The
  include/run resolver (`load-program-list`, modules.rkt:37; `program-merge-include`
  / `program-merge-run`, modules.rkt:59-96) already walks the tree; capturing it
  self-contained is a modest extension. Capture library `.slog` files
  (`lib/list.slog`, etc.) in the closure too, since collection lowering branches on
  which libs are included (`lift-type-envs`, modules.rkt:526).

---

## 10. Load = replay from origin

```
load(name):
  for each layer L in dependency order (roots … name):        # topological over the DAG
      if L is materialised and not stale: continue            # memoised (diamonds share)
      for each input I in L.manifest: load(I)                 # recursion; roots load directly
      open  L.manifest[0]                                     # or a fresh db for a root
      import L.manifest[1..] in order                         # §7.2 content-remap merge
      ingest L.kept (verbatim; ids converge by content-dedup, §4.3)
      ingest L.accel if present (extra seeds, §4.4; never drift-compared)
      apply  L.edits (§12)
      if L.pure-edb?: done                                    # roots: nothing to replay
      compile L.prog.sexpr with the CURRENT compiler          # §9
      replay its strata to fixpoint                           # runslog paused/fixpoint handshake
      verify:  replay signature == L.signature   (full coverage, §11)
               L.kept ⊆ replay by content        (importWord decode)
  # `name`'s strata stay resident → positioned to chain a new program / edit (§12)
```

This is the existing driver (`slog-run-file`, runslog.rkt:110-204: `open` input,
stream stratum plugins, drive each to fixpoint via the `(paused)`/`(fixpoint)`
handshake `drive-stratum!` at runslog.rkt:151, terminal actions) **inverted**:
program and inputs come from the on-disk recipe, and the recursion runs before the
outermost `open`. The pausing substrate (`continueStratum` budgets, `pausing.md`)
runs a long replay in bounded units; for recovery, a `memory` pause should
**checkpoint** rather than abort (today `drive-stratum!` aborts, runslog.rkt:164).

Two behaviours worth restating:

- **`per = 100 %`**: iteration-0 delta is the whole database and the first round
  derives nothing new → an **immediate fixpoint that proves the stored database is
  closed under the rules** (a self-verifying exact db — integrity today's plain
  load does not give). A `--trust` flag may skip even this.
- **`per < 100 %`**: the missing IDB is re-derived; kept tuples content-dedup in as
  seed + witness. See the honest limit on what this costs and saves (§13).

---

## 11. Drift reporting and attribution

Because every load recompiles under the current compiler (§9), the verify step
doubles as a **change detector**.

- **Driven by the content `signature`** (commutative checksum over decoded, id-free
  content — comparable across runs), with per-relation tuple **counts** as the
  human-readable headline. Counts alone can silently match on a set change, so the
  signature decides *whether* something changed and counts report *what*. The check
  is **full-coverage** (signature is over the whole IDB), so the note is precise
  per relation, not a spot-check.
- **Warn-only by default** (proceed with the freshly recomputed, current-semantics
  result); a **strict** mode treats a mismatch as an error for
  reproducibility-critical pipelines. Reuse the frontend's fixpoint-watch machinery
  (the same seam as the `(error e)` roadmap).

**Attribution is the point.** A mismatch has three causes — a compiler semantic
change (the interesting one), nondeterminism (§5.3), or a compression bug (id
reissue / dangling heap). `META`'s `compiler-stamp` distinguishes them:

- **stamp differs** → *"you are on a newer compiler; relation `reach` changed
  (+12 / −0) … — likely an intended semantic change"* (informative; often a
  monotone improvement).
- **stamp matches** → same compiler, different result → nondeterminism or a
  compression bug → a **louder** alarm to investigate, not a benign note.

Report per relation the count delta and direction (more / fewer / changed);
`--diff` decodes and lists example tuples that appeared/disappeared (cheap over the
kept sample, full on request). After confirming a change is correct, **re-save** the
db to re-baseline its `signature` + `compiler-stamp` to the new compiler — so the
warning fires once per real change, not every load.

### 11.1 The seeded-sample blind spot, and the full-replay verify (added 2026-07-08)

The default load **seeds** the kept sample before replaying (§10), and replay is
monotone — so a change that *removes* a kept tuple is invisible: the seeded tuple
survives the union, and the signature (computed over that union) still matches.
Only removals of *dropped* tuples surface as a count deficit. The blind spot
therefore scales with `per`: at `per = 100 %` **every** removal is masked and the
"self-verifying" load only detects *additions*.

The strong check is **`slog db verify NAME --replay`**: it loads the chain with
`db-load-steps #:seed? #f` — no layer's kept sample is imported — so every replay
must re-derive its whole IDB from the EDB, and removals show up as drift
(verified by test: a recipe weakened to derive 3 of 6 `path` tuples passes the
seeded load silently and fails the `--replay` verify loudly). It is strict by
default (drift ⇒ non-zero exit) and composes with the edited-chain baseline of
§11.2. Run it after compiler upgrades or before trusting an old archive; the
seeded verify remains the cheap every-load check.

### 11.2 Edited chains re-baseline instead of skipping verification (added 2026-07-08)

An edit legitimately changes content, so the save-time `signature` no longer
applies — but skipping verification entirely (the original P2.1 behaviour) left
edited chains with **no** integrity check. Now the driver re-baselines: the first
load after a new edit stores the replayed signature in `signature.edited`, keyed
by a digest of the chain's whole load recipe including every edit op
(`db-chain-edits-digest`). Subsequent loads verify against that baseline exactly
like the unedited path; a further edit anywhere in the chain changes the digest
and forces one fresh re-baseline load. Cost: exactly one unverified load per
edit, instead of an unverified chain forever.

---

## 12. Edit-and-propagate through the chain

Goal: *import a dataset and trample it arbitrarily at that stratum (delete /
rename / add), yet stay linked atop an older program, and still be able to add a
tuple to the oldest database and have it propagate all the way through to the one
that was nominally loaded.*

**Edits are first-class replayable recipe steps.** A layer's `edits` file records
ordered EDB mutations at its boundary — `(del R …)`, `(rename R S)`, `(drop R)`,
`(add-tuple R …)` — applied before/between its strata. Because each layer compiles
against its **post-edit** manifest via existing manifest-threading
(`thread-manifests`, modules.rkt:563), trampling is reproducible and the layer's
own program legitimately references the trampled schema.

**Propagation is re-replay.** Adding a tuple to a base marks it and all transitive
dependents **stale** (§7); the next `load` recomputes them from the edited base,
re-applying each layer's edits atop the recomputed lower layers. The change flows
to the nominally-loaded top.

**The big payoff of always-replay: deletion is sound for free.** Full replay from
an edited origin yields the true least fixpoint of the edited input — including
correct *retraction* of facts whose support was removed. The unfounded-cycle
unsoundness that motivates DRed^c (`incremental.md §1`) only bites incremental
maintenance that *avoids* recomputation. So **DRed^c is a pure optimisation here**
(skip replaying unchanged or monotone-only regions on deep chains), not a
correctness requirement. Ship correctness via replay; add DRed^c later for speed.

Two honesty notes:

- **Reproduce vs. mutate are different verbs.** A normal `load` is a frozen replay
  (immutable DAG, §7); edit-and-propagate is a sanctioned mutation that invalidates
  and recomputes the dependent subgraph. They coexist because they are different
  operations.
- **Re-firing an *old resident* stratum needs index re-binding.** A reload clears
  index *contents* while keeping registrations (daemon.h:22-26), so replaying an
  already-run stratum in place needs its tasks' index arrays rebound. Chaining a
  *new* layer forward works today; re-running an *old* one in place is
  DRed^c/rebinding territory.

> **2026-07-11 note (two pins).** (1) The edit-op vocabulary is now the SAME
> grammar as the session recipe steps (incremental.md §0.2, 0.E): an `edits`
> file is a recipe *fragment attached to an ancestor layer*, sharing parser,
> applier, and digest (`recipe-digest` subsumes `db-chain-edits-digest`) —
> never a second mechanism. (2) The composition with counting is settled by
> incremental.md §8B: loads — seeded or not — never establish counts; DRed^c
> state is healed lazily by the count round after replay. Nothing in this
> document's replay model changes under Phase 1, and the kept sample keeps
> its full seeding role.

---

## 13. What `per` actually buys (an honest limit)

`per` is a smooth disk knob; its effect on *load time* is not smooth:

- **`per = 100 %`**: no derivation (immediate fixpoint) → fast load, max disk.
- **`per < 100 %`, recursive relations**: semi-naïve must re-derive the missing IDB
  *and re-confirm closure*, firing all rules over all data regardless of how much
  was kept (kept tuples are content-deduped, not skipped — the join work is
  unchanged, only the insert is saved). So **60 % coverage does not give 40 %-less
  load time**; between 0 and 100 %, `per` mostly trades **disk for witness
  strength**, and only `per = 100 %` yields the fast path.

The knobs that *do* move load time:

- **Coarse — how many DAG layers stay at `per = 100 %`.** Keep expensive-to-derive
  layers (kcfa/schemecfa abstract interpreters, where recompute can cost more than a
  read) at `per = 100 %` → instant; compress cheap-to-derive-but-huge layers
  (closures, joins) to low `per` → big disk win, cheap recompute anyway.
- **Fine — §4.4's round-structured accelerator seeds** (the seed sidecar):
  complete thin-layer cuts + even round spacing collapse round-dominated
  (long-tail / linear-chain / lattice-relaxation) replays — sequential rounds
  become parallel round-0 work. Engage-gated on recorded round count
  (`accel_min_rounds`), so it never spends disk where replay is already
  round-cheap.

Document `per` as "disk-vs-witness within a layer," layer choice as
"disk-vs-load-time across the chain."

### 13.1 A default `per` heuristic (deliberately simple)

Enabling the feature matters more than optimally tuning `per`; treat tuning as a
follow-on study. A reasonable monotone default per layer:

- **rises with recorded fixpoint wall-time** — expensive to recompute ⇒ keep more,
  snapping to `100 %` past a "too costly to recompute" threshold so load is an
  immediate-fixpoint check;
- **falls with layer size** — huge and cheap ⇒ compress hard;
- clamped to `[per_min, 100 %]` (e.g. `per_min = 20 %`); forced to `100 %` for any
  relation in `full-store-rels` (§5.3).

Concrete starting form (all knobs empirical):
`per = clamp(per_min, 1.0, k · fixpoint_wall_ms / size_bytes)`, with `per = 1.0`
once `fixpoint_wall_ms` exceeds a threshold. **First cut: skip the formula** — fix a
default (≈ 60 %), run the `examples/` programs at `per ∈ {20, 60, 90, 100}%`,
measure disk vs. replay time, set the default from that. Wire the heuristic (and the
bias) later.

---

## 14. North-star (optional accelerator): content-address the struct-instance id

Compression is correct without this (§4.3). But making the struct-instance id a
**content hash** of `(type, decoded fields)`, as strings/cnodes almost already are,
buys real simplifications:

- **byte-reproducible** recompute → verification by raw byte equality instead of an
  `importWord` content-decode on both sides;
- an **id-free witness** (no heap-closure blow-up, §4.1) — the maximally-compressed
  kept representation;
- dedup and `seedInternAllocators` stop mattering here, removing the 400→392 bug
  class from this path;
- `importDatabaseBIN`'s children-first remap largely disappears; db-merge and
  cross-db joins simplify.

Cost: replace `(*intern_alloc << bucket_bits) | bucket` at operators.h:490 with a
content hash; handle hash collisions (as strings do, intern.h:95-148); canonicalise
the string/cnode file order so `.strings`/`.nodes` bytes are content-canonical too
(a determinism sub-question, §21). Bigger than the §16–§17 wiring and **not on the
critical path** — do it when byte-level verification, an id-free witness, or db-merge
unification are worth the change, not before shipping compression.

---

# Part IV — Building it

## 15. Map of existing machinery to reuse

| Need | Reuse | Where |
|---|---|---|
| Write a db (subset) to disk | `writeDatabaseBIN`, `writeAllFactsBIN`, `stageStringsWrite`, `stageNodesWrite` | database.h:1996, 1647, 1906 |
| Read a stored db | `loadDatabaseBIN`, `loadStringsBIN`, `loadNodesBIN`, `readRelationFiles` | database.h:2121, 2020, 2063, 2105 |
| Merge an input db (content-remap) | `importDatabaseBIN`, `internStructTuple` | database.h:2230, 2315 |
| Transitive heap closure / decode-to-content | `importWord` (children-first, cycle-guarded) | database.h:2344 |
| Content-dedup fresh structs on recompute | `InternStructTask` + `seedInternAllocators` | operators.h:481, database.h:650 |
| Deferred reload = iteration-0 delta | `reloadInsertBatches`, `needs_reload`/`beginStratum` | database.h:2525, daemon.h:144 |
| Run strata to fixpoint in bounded units | `continueStratum`/`continueRun`, pausing | database.h:1360, daemon.h:214 |
| Client verbs as cached plugins | `action-body`/`action-so` (open/import/write-db/sizes/lookup…) | actions.rkt:28, 112 |
| Drive compile+run, stream plugins | `slog-run-file`, `drive-stratum!` | runslog.rkt:110, 151 |
| Reconstruct a db's relation schema | `db-manifest-from-name`, `parseRelationDirName` | runslog.rkt:65, database.h:1705 |
| Resolve include/run program tree | `load-program-list`, `program-merge-run` | modules.rkt:37, 59 |
| Per-stratum IDB/EDB (head relations) | `rule-head-rels`, `stratify-rules` | stratify.rkt:53 |
| Program content identity | `progstr` / job-hash | compile.rkt:82 |
| CLI surface | flags in `slog.rkt` | slog.rkt:137-148 |

## 16. P0 — foundations (format, DAG, safety)

Goal: the uniform format, the immutable DAG, and crash safety — with **no**
recompute yet (P0 can still produce and load `per = 100 %` dbs, which behave like
today's `--out-db`/`-d` plus a `META` and a signature).

> **IMPLEMENTED 2026-07-07.** All six tasks below shipped and are verified by a
> content-equality harness (uncompressed `--out-db` vs. the compressed
> round-trip) across tables, structs, native collections, lattices, library
> collections with shared substructure, and a mixed relation — all byte-equal.
> New files: `compiler/dbmeta.rkt` (P0.2), `compiler/dbtool.rkt` (P0.3).
> Notes / deviations from the plan as written:
> - **All `daemon/database.h` line numbers in this doc are stale (~+50 drift).**
>   Re-anchor by symbol name (`writeDatabaseBIN` is at ~2047, `importWord` at
>   ~2395, `seedInternAllocators` at ~671, `loadDatabaseBIN` at ~2172, etc.).
> - **P0.5 uses a dedicated facts stratum** (the chosen general approach, not the
>   "write before the first stratum" mechanism §7.1 sketched, which is wrong
>   because inline facts are body-less rules and don't exist
>   pre-stratum). `compile-strata #:split-facts?` pulls every iteration-0 rule
>   (body reads no declared relation) into a level-0 stratum run first; the
>   driver snapshots the pure EDB after it. Level-preserving for the real strata,
>   and correct even for a relation grounded by both facts and rules (verified).
> - **Struct instances are heap:** a filtered (IDB-layer) write always also
>   writes every struct relation (`getStructId() > 0`), like `value.strings`/
>   `value.nodes`, so each kept directory is closure-complete and `import` never
>   dangles (§4.1). `value.strings`/`value.nodes` are likewise written whole in
>   both root and layer at P0 (self-contained; P1's sampler trims the heap).
> - **Load at `per = 100 %` is open-root + import-layer (no replay):**
>   `dbtool.rkt`'s `db-load-actions` drives it; struct id-convergence rides the
>   existing `importDatabaseBIN` content-dedup (no 400→392 regression observed).
>   The recursive replay driver + `prog.sexpr` + `signature` are P1 (§17).
> - **`--per < 100 %` is accepted but clamped to 100 %** with a warning (no
>   sampler yet). `--bias`/`--strict`/`--reoptimise` are parsed but inert at P0.
> - Pre-existing flakiness surfaced: `call-with-atomic-output` (tools.rkt) can
>   hit a `make-temporary-file` name collision under heavy concurrent cold
>   compiles (`run-tests.sh -j6` fresh cache); harmless at `-j4`/warm and
>   unrelated to compression — worth a unique-per-process temp name later.

- **P0.1 — Atomic db writes.** Change `writeDatabaseBIN` (database.h:1996) to write
  into `data/<name>.tmp/` then `std::filesystem::rename` over `data/<name>/`;
  never `remove_all` the live target. *Files:* database.h. *Depends:* none.
  *Risk:* low; also hardens plain `--out-db`. **Do first.**
- **P0.2 — `META` format + reader/writer.** Define the keyed s-expr of §8. Writer
  on the driver side (racket); reader on the driver side (orchestration) and a
  minimal C++ read for `value-encoding-version` gating. *Files:* new
  `compiler/dbmeta.rkt`; small helper in `daemon/` if the daemon must self-check
  encoding. *Depends:* none.
- **P0.3 — `data/` dependency DAG + `slog db` tool.** Scan `data/*/META` →
  manifest graph; implement `ls`/`tree`, `rm [--cascade]`, `gc`, `clear`,
  `verify`; enforce acyclicity and referenced-db immutability (refuse `--out-db X`
  if `X` is referenced). *Files:* new `compiler/dbtool.rkt`; wire subcommands in
  `slog.rkt`. *Depends:* P0.2.
- **P0.4 — Stratum-boundary EDB/IDB partition at save.** From the compiler's
  stratification, compute the set of IDB (head) relations for the layer's stratum
  range and pass it to the save path (which relations to sample; the rest are
  EDB, provided by the input). *Files:* `compile.rkt`/`stratify.rkt` (expose head
  relations for the range), `runslog.rkt` (thread into save). *Depends:* none.
- **P0.5 — iteration-0 EDB snapshot → root.** For a from-scratch run, issue a
  `(write-db <name>.edb)` (or `--flatten`-style write) before the first stratum
  plugin, producing a pure-EDB root; the compressed layer's manifest links it.
  *Files:* `runslog.rkt` (insert the pre-stratum action), `actions.rkt` (reuse
  `write-db`). *Depends:* P0.1, P0.2.
- **P0.6 — `--flatten` + CLI surface.** `--out-db-compressed NAME`, `--per`,
  `--flatten`, `--bias`, `--strict`, `--reoptimise` flags. `--flatten` materialises
  and writes a standalone root. *Files:* `slog.rkt`, `runslog.rkt`. *Depends:*
  P0.1.

**P0 exit criterion:** save/load a `per = 100 %` compressed db (with `META`,
manifest link to an EDB root, and a `signature`) that round-trips content-equal to
today's `--out-db`; `slog db` manages the DAG safely.

## 17. P1 — the recompute engine

Goal: real compression + recompute-on-load + verification, gated by tests.

> **IMPLEMENTED 2026-07-07** (P1.1–P1.5 + P1.7; P1.6 folded into the signature).
> Real compression works: `--per 20` stores ~1/6 of reach's derived tuples on
> disk and a load regenerates all of them; the oracle-diff harness
> (`tests/compression/run.sh`) confirms content-equality against the
> uncompressed run at `per ∈ {100,90,60,20}` across tables, structs, native
> collections, lattices, demand functions, and library collections. Notes /
> deviations:
> - **P1.1 stores raw source, replayed via a source-override parameter**
>   (`parser.rkt` `current-source-override`/`current-source-capture`,
>   `source-key`; `modules.rkt` `source-available?`).  prog.sexpr = entry +
>   canonical-path→source map (dbmeta.rkt).  The full parse→lift→…→emit pipeline
>   re-runs on load, so compiler changes ARE observed (the §9 goal); relative
>   includes resolve because the entry is stored absolute and the resolver only
>   touches the filesystem to normalise paths, which tolerates absent files.
>   Assumes no symlinks in the source tree and the same working directory at
>   save and load.  Since 2026-07-08 a divergence is LOUD rather than silent:
>   if a replay's source lookup misses the stored override and falls through
>   to disk (`parser.rkt` `parse-file`), the driver warns that the result may
>   not correspond to the saved recipe (catches symlink/moved-tree/incomplete-
>   capture cases at their point of impact).
> - **P1.4 replay is a driver phase, not a separate `recompute.rkt`.**  `-d NAME`
>   on a compressed db opens the root, imports the IDB sample, then recompiles
>   prog.sexpr (`#:split-facts? #f`) and runs its strata — atop the FULL DAG
>   manifest (`db-full-manifest`) so the program sees root+layer.  Runs before
>   any query strata.  The manifest DAG resolution is single-level (nested
>   compressed inputs would need recursion — not yet exercised).
> - **P1.2 sampler is per-tuple content-hash keep, not coverage-accumulation.**
>   Each IDB table/lattice tuple survives iff FNV-1a(storage words, seed) falls
>   in the lowest `per` of the hash space (order-independent, seeded, recorded in
>   META `rng-seed`); struct/string/cnode heap is kept WHOLE (closure-complete).
>   Any subset is a valid seed (§2a), so this satisfies correctness.  P2 adds
>   sound struct-heap trimming (see §18); the coverage-budget-over-facts+heap
>   variant (§4.2) is the remaining refinement.
> - **P1.3 signature reuses the CSV value decoder** (`writeValCSV`): per IDB
>   relation, (count, XOR of FNV-1a over each tuple's canonical id-free rendered
>   text) — commutative, comparable across id reassignment.  Stored over the
>   FULL IDB at save (before sampling) in `data/<name>/signature`.
> - **P1.5 verify runs on every compressed load**: recompute the signature after
>   replay, compare, attribute via `compiler-stamp` (same ⇒ nondeterminism/bug,
>   newer ⇒ likely intended), warn-only default / `--strict` errors.  The
>   `kept ⊆ replay` check is subsumed (2026-07-08) by the stronger
>   `slog db verify NAME --replay` no-seed verify (§11.1), which detects
>   removals the seeded load masks; `--diff` example tuples remain unwired.
> - **P1.6** content-equality is the signature comparison; the harness (P1.7)
>   also does a direct per-relation CSV diff via an empty "dump" loader.

- **P1.1 — s-expr program-tree (de)serialiser.** Serialise the transitive
  include/run source closure into one self-contained `prog.sexpr` (entry, per-file
  source, tree edges, env); deserialise into a program-list the compiler consumes
  with the original files absent. *Files:* `modules.rkt` (beside `load-program-list`,
  modules.rkt:37). *Depends:* P0.2.
- **P1.2 — closure-accumulation sampler (daemon).** New `Database::saveCompressed(dir,
  idb_rels, per, seed, bias?)`: order IDB facts (shuffle/bias), accumulate
  `fact + (closure(fact) \ input_heap)` via an `importWord`-style reachability walk
  until `kept/D ≥ per`, and write the kept subset + its heap with the canonical
  writer. *Files:* `daemon/database.h` (new method reusing `importWord`
  reachability + `writeAllFactsBIN`/stage writers), `actions.rkt` (a
  `(save-compressed …)` verb). *Depends:* P0.1, P0.4.
- **P1.3 — signature computation (daemon).** `Database::signature(idb_rels)` →
  per-relation `(count, checksum)` over decoded content-keys (commutative combine),
  written to `signature`. *Files:* `daemon/database.h` (reuse `importWord` decode),
  `actions.rkt` (`(signature …)` verb). *Depends:* none (parallel to P1.2).
- **P1.4 — recursive replay-from-origin driver.** Read `META`, resolve/memoise the
  manifest DAG, `open` + ordered `import`, ingest kept, apply edits, compile
  `prog.sexpr` under the current compiler, replay strata, verify. *Files:* new
  `compiler/recompute.rkt` (or extend `runslog.rkt`); `actions.rkt` for the
  import-chain + kept-ingest verbs. *Depends:* P1.1, P1.2, P1.3.
- **P1.5 — verify + drift report.** After replay, recompute `signature`, compare;
  on mismatch attribute via `compiler-stamp` and emit a warn-only/strict report;
  `kept ⊆ replay` content check; `--diff`. *Files:* `recompute.rkt`, `actions.rkt`
  (`(signature)` on the live db), frontend formatting in `slog.rkt`. *Depends:*
  P1.3, P1.4.
- **P1.6 — content-equality primitive.** Assert two dbs are content-equal (id-free),
  used by verify and the harness — e.g. compare per-relation signatures, or a
  `(content-digest)` action. *Files:* `daemon/database.h`, `actions.rkt`. *Depends:*
  P1.3.
- **P1.7 — oracle-diff test harness (ships with P1, gates it).** See §19. *Files:*
  new `tests/compression/`. *Depends:* P1.4, P1.6.

**P1 exit criterion:** for every `examples/` program, saving at `per ∈ {20,60,90,
100}%` and reloading yields a database **content-equal** to the uncompressed run,
and the harness enforces it in CI.

## 18. P2 and north-star

> **IMPLEMENTED 2026-07-07** (P2.1–P2.4 + heap trimming), forward-incremental
> only.  Deferred: DRed^c backward incrementality and the §14 content-addressed
> struct id (see below).  Notes / deviations:
> - **Heap trimming (sound, struct-only).**  When `per<1.0` the IDB layer keeps
>   only the struct instances reachable from the kept table/lattice facts (plus
>   every struct any collection node references, since cnodes are written
>   whole); dropped-fact-only structs are regenerated by replay.  Sound because
>   struct ids load back **verbatim**.  Strings and cnodes stay whole -- they
>   re-intern by insertion order (id = content-hash + collision-chain position),
>   so trimming would shift a kept value's id and corrupt the facts that
>   reference it; trimming them needs §14.  (`daemon/database.h` `markKeptStructs`
>   + `writeAllFactsBIN` `keep_ids`.)  Verified: ex_eval per=30 drops struct
>   words 40→9, 0cfa per=20 stays content-equal (struct id-convergence holds).
> - **Input-heap struct dedup (`closure \ input_heap`, §4.2).**  A from-scratch
>   layer does not re-store the struct instances its verbatim-opened EDB root
>   already holds: `(capture-edb-heap)` at the boundary records them, the layer
>   write subtracts them, and `importDatabaseBIN(..., passthrough=true)` (used by
>   the `import-layer` action) passes a trimmed same-lineage struct id through to
>   the root instead of fataling.  ONLY for from-scratch saves -- a chained input
>   is REPLAYED with fresh struct ids, so its heap can't be dedup'd by id; chained
>   layers stay closure-complete.  Cuts ex_eval's struct bytes 640→320 at per=100.
>   General db-merge is unaffected (passthrough defaults off; its sources must be
>   closure-complete).
> - **Forward-incremental edit-and-propagate (P2.1).**  `edits` files hold
>   `(add-tuple REL v…)`; `slog db edit NAME add-tuple REL v…` records one; on
>   load a db's edits apply right after it is opened/imported (a daemon
>   `add-tuple` → `insertTupleAllIndices` + `needs_reload`), so replay propagates
>   the change FORWARD through every dependent layer.  Verified through a 2-layer
>   chain: editing the deep root's `edge` grew `path` 6→10 and `twohop` 3→6.
>   Since 2026-07-08 the drift verify is NO LONGER skipped on an edited chain:
>   the first post-edit load re-baselines to `signature.edited` and later loads
>   verify against it (§11.2).  Backward maintenance (DRed^c) is deliberately
>   NOT built.
> - **Recursive manifest DAG.**  `db-load-steps` materialises the whole input
>   DAG bottom-up (open base root → per layer: import sample, apply edits,
>   `(replay L)`).  A compressed save under `-d INPUT` chains atop INPUT (links
>   it in the manifest) rather than snapshotting a fresh root.
> - **P2.2 encoding migration = detection + refuse.**  A load walks the DAG and
>   refuses any db whose `value-encoding-version` differs from this build's
>   (`db-encoding-mismatch`); with only v1 in existence there is nothing to
>   re-encode yet, so the migration transform itself is a stub the check gates.
> - **P2.3 checkpoint-on-pause.**  A memory pause DURING a replay serially
>   checkpoints the partial db to `data/<layer>.checkpoint/` (a new
>   `writeDatabaseSerialBIN` that uses no Stratum/RunState, so it is safe against
>   the parked run -- the parallel writer is not) then aborts with a resume hint,
>   instead of losing the progress.  A pause during the top-level query still
>   aborts as before.
> - **P2.4 = auto-`per` default + productive-seed bias.**  `--per` now defaults
>   to `auto`: the driver sums the run's fixpoint wall-time and picks
>   `per = auto-per(ms)` -- a coarse two-level rule (cheap ⇒ compress to
>   `per_min=0.5`, expensive ≥500ms ⇒ keep whole; the smooth size-aware clamp of
>   §13.1 is left for later), recorded in META's `fixpoint-wall-ms`.  `--bias
>   productivity` weights IDB relations READ by some rule (their facts
>   immediately deduce new facts) at a higher keep fraction (`boost = min(1,
>   2·per)`) than terminal relations; default is uniform.  Both are simple,
>   non-strict static signals (`compile.rkt` `productive-rels`); refine later.
> - **§14 content-addressed struct ids** (would let strings/cnodes trim and make
>   recompute byte-reproducible) and **DRed^c** remain the only unbuilt pieces --
>   both explicitly optional here.

- **P2.1 — edit-and-propagate.** `edits` file format + apply-on-load + stale
  propagation across the DAG; `slog db edit`. *Files:* `dbmeta.rkt`, `dbtool.rkt`,
  `recompute.rkt`, `modules.rkt` (post-edit manifest threading).
- **P2.2 — value-encoding migration.** On `value-encoding-version` mismatch:
  re-encode root EDB bins (decode-old/encode-new), drop-and-replay derived layers.
  *Files:* a migration tool + `daemon/` decoders.
- **P2.3 — checkpoint-on-pause.** For long replays, checkpoint on a `memory` pause
  instead of aborting (runslog.rkt:164). *Files:* `recompute.rkt`, pausing plumbing.
- **P2.4 — `per` heuristic + productive-seed bias.** Wire §13.1 and §4.4 after
  benchmarking on `examples/`. *Files:* `compile.rkt` (bias scores from the rule
  graph), sampler (P1.2), driver. *(Shipped against §4.4 v1; the bias is
  superseded by §4.4 v2 — see §18.1 P3.)*
- **North-star** — content-addressed struct ids (§14; operators.h:490) and DRed^c
  (`incremental.md`). Neither blocks shipping compression.

### 18.1 P3 — round-structured accelerator seeds (SHIPPED 2026-07-11)

> **Shipped 2026-07-11, same-day sprint.** The map of what landed where:
> - **Compiler**: `stratum-accel-rels` (compile.rkt) — per-SCC tier scoring
>   over the stratum-local Tarjan subgraph (`tarjan-scc-ids` +
>   `rule-body-rel-occurrences` now exported from stratify.rkt); emitted as
>   `s->addAccelRel("…")` beside the dynamic-rel manifest (emit-cpp.rkt) and
>   as `(accel-rels …)` in build/<hash>.meta. Tiers ≥ 2 fixed; per-relation
>   quota (decided over the SCC-shared pool: a size-skewed SCC cannot starve
>   a small member's cut points).
> - **Daemon**: `Stratum::accel_rels`; `Database::accel_sidecar` +
>   `accelRecordRound` (hooked in `EndIterCompletion`), decimation-by-halving
>   under `SLOG_ACCEL_MB`, generation bump in `continueStratum(starting)`,
>   `accelInvalidate` on delete/clear/rename/drop; `writeAccelBIN` inside
>   `writeDatabaseBIN(accel_out)` with `markKeptStructs(include_accel)`
>   closure union; `loadAccelBIN` at the end of `loadDatabaseBIN`, so
>   open AND the scratch-db import/remap path both carry accel rows — zero
>   driver load changes, and `--replay` no-seed skips accel with the layer.
> - **Driver**: save-compressed action carries `(accel 1)`; META `accel
>   #t/#f` by directory existence (runslog.rkt `#:extra`).
> - **Tests**: tests/accel_chain.slog + tests/accel_lat_chain.slog in the
>   compression battery (the only battery programs deep enough to clear the
>   gate); measured on bench_accel_{braid,broom,er} (§4.4.5 spike results).

The original sprint plan, for the record:

- **P3.0 — spikes first** (§4.4.5): lattice-seeding soundness under the §19A
  lattice-headed exemption; reorg-hook overhead (< 1 % on fat rounds); round
  histograms on `examples/` to set `q` / cap / `accel_min_rounds` defaults.
- **P3.1 — SCC tiers (compiler).** Per-SCC tier score
  (lattice / linear / nonlinear / non-recursive) computed where stratify already
  has the rule graph; emit selected SCCs + member relations into the stratum
  manifest so the daemon knows what to record. *Files:* stratify.rkt,
  compile.rkt (manifest plumbing).
- **P3.2 — sidecar recording (daemon).** Per-selected-SCC quota reservoir at
  end-of-round delta reorg (O(q) bucket-stride sampling); lattice key-only
  variant; byte cap + decimation-by-halving with whole-round drops and
  contiguous-suffix coalescing; generation bump on stratum re-entry; lives in
  `Database`/run state (survives .so hot-swap); dropped on pause-checkpoint.
  *Files:* database.h, the stratum fixpoint loop, env knobs.
- **P3.3 — save/load plumbing.** `saveCompressed` writes `accel/` groups +
  `manifest.sexpr` (lattice keys materialised at final values via point
  lookups; closure via the normal writer); load ingests witness ∪ accel; META
  `accel` block; drift compares witness only; `--accel on|off|auto` in the db
  tool. *Files:* database.h (writer), dbmeta.rkt, recompute.rkt, dbtool.rkt.
- **P3.4 — tests + bench** (§19 accelerator bullets; bench/regress.sh
  round-count cases: deep chain, SSSP-style lattice, dense-TC honest
  negative). Fold `--bias` into `--accel` and retire it (§4.4.5 footnote).

## 19. Testing plan (this WILL break in subtle ways)

Correctness rests on invariants that fail **silently** — id reissue, dangling
heap, monotone over-approximation, compiler drift. Dedicated harnesses in
`tests/compression/`, not incidental tests:

- **Round-trip content-equality (the core test).** For each `examples/` program:
  run uncompressed → save at `per ∈ {20,60,90,100}%` → load (replay) → assert the
  loaded db is **content-equal** to the uncompressed run (id-free, per relation)
  and `signature`s match.
- **id-convergence stress (the 400→392 class).** Programs deriving many structs
  with shared substructure; assert no logical struct appears under two ids after
  seed+recompute (constant-time equality holds); fuzz thread counts (2/4/6/…).
- **Closure completeness.** Assert every kept fact's heap closure is present (no
  dangling struct/cnode/string); fuzz `per` and topology (deep cons lists, shared
  subtrees, cycle guards).
- **Manifest/merge.** Multi-input manifests in different orders → same content;
  schema conflict → clean fatal; diamond DAGs → shared ancestor deduped once.
- **Edit-and-propagate.** Add/del/rename at a base; assert downstream re-derives to
  the true from-scratch fixpoint (incl. retraction on delete), against a full
  recompute oracle.
- **Compiler-drift observability.** Deliberately change a rule's meaning; assert
  the witness **flags** the changed result on load (the feature working, not a
  silent pass) and attributes it to the stamp difference.
- **Value-encoding migration.** Simulate an encoding bump; assert roots migrate and
  derived layers drop-and-replay correctly.
- **Bias A/B.** `--bias productivity` vs. uniform on deep vs. shallow benchmarks;
  measure rounds + wall-time to decide if §4.4 earns its keep.
- **Accelerator seeds (§4.4 v2 / §18.1).** Status 2026-07-11:
  (a) round-trip content-equality DONE — tests/accel_chain.slog +
  tests/accel_lat_chain.slog in the battery's default set, green at
  `per ∈ {100,60,20,5}%` incl. the long-chain lattice case (the §19A
  exemption did not bite); (b) **witness stability** VERIFIED manually
  (kept dirs byte-identical under `SLOG_ACCEL=0/1`, `accel/` absent under 0)
  — not yet an automated assertion; (c) decimation invariants unit battery —
  OPEN (decimation is exercised only when a run exceeds `SLOG_ACCEL_MB`;
  cover with a tiny-cap env run); (d) round-count measurements DONE on
  bench_accel_{braid,broom,er} (§4.4.5 spike results; bench/accel_*.slog +
  bench/gen.py) — not yet wired as automated regress assertions.

The uncompressed run is always the oracle; wire a fuzzer over
`(program, per, thread-count, seed, bias, accel)` where every
compressed+replayed load must content-match it.

## 19A. The staging-replay bug and its two fixes (2026-07-10)

Replay's soundness premise — "re-running the program over any seed
superset regenerates every dropped derived tuple" — implicitly assumes
full semi-naive variant coverage: a delta variant on every body position
that could be the LAST to arrive.  Head-const staging (2026-07-09,
join-planning `stage-rule`) deliberately prunes that coverage for staged
construction rules: earlier-stage replays become STATICS with no delta
versions, justified by an in-run timing proof ("rows land in FULL before
any driver's delta").  A partially-sampled seed falsifies the proof's
premise — a seeded trigger's only delta fires at iteration 0, before
unsampled prerequisites exist; when a prerequisite is rebuilt later,
no variant fires — so ground facts (and anything downstream) silently
failed to regenerate (dem_stlc at per=20, ~40% of seeds).  Two fixes:

1. **Ground rules are EDB** (`compile.rkt ground-fact-rules`): the
   two-level fixpoint classifies a rule as ground when its only declared
   reads are constant-class relations (those headed exclusively by strict
   facts — in practice `_enum`, which every ground struct tree's enum
   leaves join).  Ground heads land in the facts stratum and the `.edb`
   root, saved WHOLE: ground rows are origin (literally program text),
   and storing them beats replaying them through a staged cascade.
2. **Seeded re-entry tasks** (`seeded-rule` versions, `addTaskSeeded`):
   every staged rule with pruned statics — except temp-driven follow-ups,
   whose trigger is only ever produced in-run co-emitted with what their
   statics need, and lattice-headed rules (no emit-side dedup; a v1 gap)
   — also compiles ONE no-delta version over FULL indices.  The daemon
   registers those tasks (and the WriteTasks of indices only they
   requisition) only when the database was externally seeded
   (open/import/frozen imports), and they rerun each iteration:
   set-semantics re-fires dedup away, with `emit_struct_checked` probing
   the master index so re-emissions of known structs don't hold the
   fixpoint open.  Fresh runs are bit-identical and pay nothing.

The residual exact-once caveat: seeded tasks re-fire instantiations
(sets absorb them); DRed^c counting must replace this with true
partitioned variants at the M0 boundary — the fire audit (docs/stats.md)
is the tool that will prove that property.

(2026-07-11: resolved differently — incremental.md §8B keeps seeded runs
set-semantics FOREVER. Counting lives only in the `_count`/`_delta`
flavors, which contain no seeded tasks, so the exact-once burden never
meets a seeded re-fire; no partitioned-variant rework of the seeded
flavor is needed.)

## 20. Risks & tricky parts, at a glance

1. **Sample facts, keep heap closure** (§4.1); id convergence within a lineage
   already works via content-dedup + seeded allocators (§4.3), so §14 is an
   accelerator, not a gate.
2. **`per` is a coverage target** hit by a closure-accumulation loop (§4.2); the
   struct/table mix emerges from topology; per-relation coverage is emergent (the
   `signature` is the floor).
3. **Inputs are a manifest of bin dbs** (§7.1-7.2); merge = manifest + empty
   program; order sets id layout only; schema must agree.
4. **`data/` is an immutable GC'd DAG** (§7): dependency-aware delete, frozen
   referenced layers, stale-propagation, atomic writes; `--flatten` opts out.
5. **Program stored as one s-expr source tree, recompiled on load** (§9): latest
   semantics always; `.so`/crule are ephemeral caches; only bins couple to the
   value encoding (roots migrate, derived re-derive).
6. **Edits are replayable recipe steps** (§12); deletion is sound for free under
   replay; DRed^c is an optimisation, not a correctness need.
7. **`per` ≠ proportional speedup** for recursive relations (§13); layer choice and
   §4.4's round-structured seed sidecar are the real load-time levers.
8. **`seedInternAllocators` is the fragile spot** (§4.3): wrong seeding silently
   collapses referencing rows — the single most important thing to test (§19).
9. **Drift attribution needs the compiler stamp** (§11); without it a warning
   cannot tell an intended semantic change from a bug.
10. **id budgets** (14-bit type, 35-bit string, 38-bit instance): recompute-then-
    store re-mints per layer, so budgets are per-database, not per-chain — a point
    *for* this model over deep in-place merges.
11. **Testing is load-bearing** (§19): silent-failure invariants demand oracle-diff
    harnesses and fuzzing.

## 21. Open questions

1. **`per` counting unit**: records (fraction of facts) vs. bytes (disk). Records
   is the default; bytes is a one-line swap.
2. **Naming & immutability**: human names + version stamps vs. content-addressed
   names for automatic dedup/immutability.
3. **Edit granularity**: edit-ops on EDB/relation level only, or targeting derived
   relations (only meaningful if a later stratum re-consumes them)?
4. **Lattice/collection determinism** under `LAT_EXTERN` (`intern4`): confirm the
   converged value (and, post-§14, canonical node order) is order-independent.
5. ~~Does the productive-seed bias (§4.4) ever pay enough to justify recording
   per-tuple derivation rounds for the dynamic variant?~~ **Resolved 2026-07-11
   by §4.4 v2**: no per-tuple tags needed — the per-round quota reservoir
   records rounds at O(q)/round; even spacing (not depth preference) is the
   right policy; the `accel_min_rounds` gate confines it to round-dominated
   strata. Remaining empirical: `q` / cap defaults (P3.0 histograms decide).
6. **What exactly goes in `prog.sexpr`** — raw source text (most robust) vs. the
   parsed module AST (skips re-parsing but couples to parser output)? Leaning raw
   text; confirm library capture is complete.
7. **`convert-db-folder` (tools.rkt:45)**: still on any live path? Its id scheme
   differs from the runtime interner, so roots must be produced by the daemon's
   canonical writer to be replay-consistent.

## 22. Appendix

### 22.1 Value encoding & id spaces (reference)

Slog values are NaN-boxed `u64`s (`types.h`). Four id classes, three of them
database-local (db-merge.md §2):

| Class | Encodes | Assigned by | Portable across runs? |
|---|---|---|---|
| `s32` / `float` | the value itself | — | **Yes** (self-encoding) |
| string (`is_str`) | 35-bit intern id | FNV low-26 bits + collision position (intern.h:227-269) | mostly (collisions order-dependent) |
| struct (`is_struct`) | 14-bit type id + 38-bit instance id | type = `addStruct`/`struct_id_max++` (declaration order); instance = `intern_allocators[bucket]` counter (operators.h:490) | **No** (allocation order) |
| collection node (`is_cnode`) | 35-bit arena intern id | content-hash + collision position; contents embed other id words | **No** (order-dependent, recursive) |

On-disk directory layout of a (kept) database:
`table.NAME.arity.N/`, `struct.NAME.arity.N.id.SID/`, `lat.NAME.arity.N.spec.TOK/`,
each holding `0.bin` (or `.bin.gz`) of native-endian `u64` tuple words
(bucket-sharded), plus `value.strings/` and `value.nodes/`. See `convert-db-folder`
(tools.rkt:45) and `writeDatabaseBIN` (database.h:1996).

### 22.2 Decisions log (what we chose and why, incl. rejected alternatives)

- **Linked DAG, not physical nesting** (§7). Rejected `mydb/input/input/…` nesting:
  it duplicates shared ancestors and can't express merges. Links dedup and form the
  incremental-program graph.
- **Coverage percentage `per`, not per-tuple probability `p`** (§4.2). A coverage
  target makes on-disk size predictable and lets the struct/table ratio emerge from
  topology; a Bernoulli rate + closure gave an unpredictable actual size.
- **Store source (one s-expr tree) + recompile on load, not crule IR / `.so`**
  (§9). Rejected storing crule IR (rev 4's plan): we *want* compiler improvements —
  even breaking ones — observed immediately, with the witness catching drift.
  Source is robust to all compiler changes downstream of the parser; `.so`/crule are
  ephemeral caches.
- **Kept set stored as an ordinary closure-complete db, compared by content**
  (§4, §8). Rejected an id-free content-key witness *as the store* (bigger, loses
  sharing); content-keys are the *comparison*, computed at verify time; the
  `signature` gives cheap full coverage.
- **Sample facts, keep heap closure; never sample the heap** (§4.1). A struct is
  atomic and referenced; closure is required, obtained via `importWord`.
- **Content-addressed struct ids are optional, not a prerequisite** (§4.3, §14).
  Corrected an earlier "near-mandatory" claim: within-lineage recompute already
  converges ids via `InternStructTask` content-dedup + `seedInternAllocators`.
- **Always replay from origin ⇒ deletion sound for free; DRed^c is an
  optimisation** (§12). Full replay from an edited base is the true fixpoint;
  DRed^c only matters to *avoid* recomputation.
- **Merge = ordered manifest, not a special node** (§7.2). `open` first + `import`
  rest, reusing `importDatabaseBIN`; a pure merge is a manifest with an empty
  program.
- **Record the compiler stamp for drift attribution** (§11). Cheap; turns "something
  changed" into "the compiler changed" vs. "nondeterminism/bug."
- **Honest limit: `per ∈ (0,100)` trades disk for witness, not proportional load
  time** (§13). The real load-time levers are DAG-layer choice (keep expensive
  layers at 100 %) and, for round-dominated strata, the §4.4 v2 seed sidecar
  (which superseded the marginal productive-seed bias, 2026-07-11).
