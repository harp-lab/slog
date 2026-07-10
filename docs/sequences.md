# Canonical sequences: `[T]` lists and rope strings

*Design (2026-07-08, drafted for review with Tom; open questions RESOLVED
with Tom same day — see §12).  **Status: S1 AND S2 EXECUTED 2026-07-08 —
the engine, prims, typing, splice-anywhere patterns (both directions incl.
floating runs), occurrence indices (COMPLETED for lists same day: bound-
variable and multi-position anchors, floating-run probes, the membership
probe, the §5.3 recursive-feed warning), persistence/merge, the migration,
AND the S2 rope strings (byte trees, tag-4 plumbing, the §6 op set,
normalization keystone, persistence/merge, goldens).  See §14 (status
appendix) for the shipped shape and the deliberate deviations
(construction via lempty/lpush/lcat prim chains instead of an lbuild c-op;
one untyped `$seq_at`/`$seq_atr` pair instead of per-τ tables; floating
runs via a synthesized POSITION enumerator `$seq_posdem`/`$seq_pos`
instead of match-driven `$seq_occ<j>`; the partial `aslst` chain entry so
patterns MATCH-FAIL on non-sequence words; NO base→occurrence stratify
edges — sound because probes are additive), and §15 for the SMARTER STRING
INDEXING notes (n-gram/ordered/regex — deliberately INCOMPLETE, needs
design).**  This document supersedes the `(vec T)` roadmap item (the one
remaining Phase-1 deliverable in docs/primitives.md §12) and the
cons-backed `[T]` as the blessed sequence type.  It builds on docs/primitives.md (the
canonicity gate, §2/§4.2/§9), docs/finish-collections.md (§A partial prims —
a hard dependency, see §3.2), docs/db-compression.md (the IO dovetail, §8),
and docs/incremental.md (the signed-record obligation, §5.6).  All compiler
touch points below were verified against the tree on 2026-07-08; note that
`indices.rkt`/min-chain-cover referenced by older docs DO NOT EXIST — index
requisition lives in `operationalization.rkt` (one index per select set).*

**One-paragraph summary.**  One sequence type `[T]` (surface type `(list T)`),
backed by a content-defined-chunked, hash-consed Merkle tree ("prolly-tree" /
hash-splitting rope) in a new arena alongside the cnode arena.  Canonical by
construction — equal content interns to one id regardless of build path — so
equality, joins, and keys stay id comparisons.  All point and bulk ops
(`ref/set/ins/del/cat/slice`) are expected O(log n); `len` is O(1).  The
builtin cons/nil encoding is retired.  Body patterns support any single
splice at any position plus the two-splice floating-run form
(`[xs ... a b ys ...]`), compiled onto existing machinery: partial-prim
compute chains when the list is bound, synthesized demand enumerators for
floating runs, and need-driven inverted occurrence relations when the planner
wants to bind the list FROM an element.  Strings move onto the same engine in
a second phase (byte leaves, small-string fast path, two intern tags), which
also fixes today's O(n)-copy-per-op string prims and de-duplicates string
content on disk at chunk granularity.  Regex/ordered/n-gram indexing is
explicitly OUT of scope but the extension seams are reserved (§7).

---

## 1. Representation: content-defined chunked Merkle sequences

### 1.1 Why not radix vectors, RRB, finger trees, or cons

The canonicity gate (docs/primitives.md §2) stands: hash-consing requires
that equal content force one identical tree shape, or two equal sequences
intern to different ids and every downstream `==`/join/key is silently wrong.
That gate kills every classic O(log n) sequence — RRB trees, finger trees,
position-keyed balanced BSTs all encode edit history in their shape.  The two
canonical structures considered before (cons; strict radix-balanced vector)
are mirror images split by build direction, and *neither* gives O(log n)
insert/concat: the radix vector's shape is a function of length, so an
insertion at position i shifts every leaf after it (O(n)); cons is O(n) at
everything except the front.  Shipping both (`(list T)` + `(vec T)`) was the
old compromise; it doubles surface area without fixing either gap.

The escape: make chunk boundaries a function of **content**, not position.
This is the prolly-tree / hash-splitting construction (Dolt/Noms, bup,
casync; Merkle Search Trees are the set-side cousin).  Boundaries are decided
by a rolling hash over a bounded window of the element stream, so (a) the
chunking of a sequence is a deterministic function of its content alone —
canonical, the same gate Patricia passes — and (b) an edit only perturbs
boundaries within a bounded window, so boundaries *resynchronize* and edits
touch O(log n) expected nodes.  `[1 2 3] ++ [4]`, `(lins [1 2 4] 2 3)`, and
the literal `[1 2 3 4]` all intern to ONE id.

### 1.2 The chunking spec

- **Boundary predicate.**  Gear-style rolling hash over element words:
  `h = (h << 1) + gear(w)` where `gear(w) = splitmix64(w)` with a fixed,
  compiled-in constant (no per-run seed — the hash is part of the canonical
  form).  A boundary falls after element i when `(h & LEAF_MASK) == 0`,
  subject to min/max bounds.  A word's influence shifts out of `h` after 64
  steps, so the boundary decision is a function of a bounded window — this
  is what guarantees resynchronization after an edit.
- **Levels.**  Leaves hold runs of element words (lists) or bytes (strings).
  The stream of leaf ids is chunked again by the same predicate (over the id
  words) into branch nodes, recursively, until one node remains — the root.
  Expected height O(log_B n).
- **Parameters (D3 — defaults; bench inside S1, then FROZEN as format
  constants, §8.2):** word leaves target 16 elements (4-bit mask), min 4,
  max 64; branches target fanout 16, min 4, max 64; byte leaves (S2) target
  64 bytes, min 16, max 256, with boundaries snapped forward to the next
  UTF-8 codepoint start (a deterministic function of content — canonicity
  preserved; keeps leaves self-contained for decoding).
- **Min/max bounds.**  min suppresses boundary tests for the first `min`
  items after the previous boundary; max forces a split.  Both keep chunking
  a deterministic scan of the content (still canonical); they slightly
  weaken edit locality (a forced-max run rechunks downstream of an edit
  until the next natural boundary) — see §1.5.
- **Empty and tiny sequences.**  `[]` is one distinguished interned empty
  node (like the cmap empty).  A sequence that fits one leaf IS that leaf
  (root = leaf; no branch chain above it).

**Canonical-form argument (the proof obligation):** chunking is a
deterministic scan of the element stream using only compiled-in constants ⇒
the node DAG is a function of content alone ⇒ hash-consing gives equal
content ⟺ equal root id.  The implementation must not let ANY ambient state
(thread, arena occupancy, phase) influence a boundary or node record.  This
is checked by the canonicity property tests (§10): N random build paths to
the same content must yield one id.

### 1.3 Node formats, the arena, and tag space

New `seqnode` class interned in an `InternTable<seqnode>` — the table already
supports variable-size T (it stores `T*` compared by `operator==` and hashed
by a `fasthash<T>` specialization; utf8string is the precedent,
`intern.h:38-51,62`).  Three kinds:

- `leaf-words`: n ≤ 64 element words (full NaN-boxed u64s — struct ids,
  string ids, floats, nested collection/sequence words are all legal
  elements, exactly as cnode keys are).
- `leaf-bytes` (S2): n ≤ 256 bytes + codepoint count.  Defined in S1's
  record format, unused until S2.
- `branch`: k ≤ 64 child ids, each with its subtree element count (and, for
  byte trees, byte + codepoint counts) so descend-by-index is O(log n).
  Store per-child counts (not cumulative) — simpler records, the partial
  sums are computed in-register during descent.

`fasthash<seqnode>` = FNV-1a over the record bytes (cnode precedent,
`arena.h:63-75`).  Child references are full tagged intern words, so records
hash without dereferencing — the same property that makes cnode reload ids
reproduce in-order (`arena.h:8-12`), extended inductively to trees.

**Tag space (D4):** 3-bit intern tags currently str=0, mpz=1, cnode=2
(`types.h:41-43`).  Sequence roots (and interior nodes) take **tag 3**
(`seq_intern_tag`); **tag 4 is RESERVED now for S2 rope strings**
(`strrope_intern_tag`) so `is_str` can stay a pure bit test:
`is_str(x) := is_intern(x) && (tag == 0 || tag == 4)`.  A rope string's
*interior* nodes are ordinary tag-3 seq words; only the root of a string
value is tagged 4 (the tag is the type; the arena is shared).  `is_seq(x)`
:= tag 3.  The 35-bit id budget, 21+5+9 hash/slot/chain id layout, and the
512-per-slot overflow fatal are inherited unchanged (`intern.h:24-26,111-114`).

### 1.4 Costs and sharing

| op | cost (expected) | notes |
|---|---|---|
| `len` | O(1) | root count |
| `ref i` / `set i v` | O(log n) | descend by counts / rebuild path |
| `ins i v` / `del i` | O(log n) | rechunk ≤ window past the edit, per level |
| `cat a b` | O(log n) | only the seam region rechunks per level |
| `slice i j` | O(log n) new nodes | interior chunks shared with the source |
| equality | O(1) | id compare (canonicity) |
| lexicographic cmp | O(shared-prefix leaves), physical-eq skip | |
| full walk / materialize | O(n/B) leaves | cache-friendly runs |

Sharing is strictly broader than cons: any common contiguous run shares
leaves — two lists differing at one middle element share essentially
everything (cons shares only suffixes; the radix vector only prefixes).

### 1.5 Honest caveats (the tradeoffs to keep in view)

1. **Bounds are expected-case, not worst-case.**  Degenerate content — e.g.
   a million identical elements — either makes every position a boundary
   (min bound floors chunk size) or none (max bound forces splits).  Forced
   runs lose edit locality: an insert ahead of the run rechunks it.  But the
   rechunked chunks have identical content and re-intern to the SAME ids, so
   hash-consing turns the pathology into probe work, not memory.  Property
   tests cover both degeneracies (§10).
2. **Head-recursion regresses vs cons.**  `[x xs ...]` costs O(log n) per
   step instead of O(1), and a full element-at-a-time walk is O(n log n)
   with rope constants.  Mitigation: that idiom is the exception, not the
   target — bulk ops are native O(log n) prims, and enumeration compiles to
   memoized demand enumerators / occurrence joins (§5), which is the
   natural Datalog shape anyway.  Existing dem_*-style programs still run
   correctly, just with different constants.
3. **The chunker constants are format.**  Changing the gear constant, masks,
   or bounds changes every canonical id on disk.  They are versioned (§8.2)
   and frozen after the S1 bench.
4. **Cross-DB merge re-canonicalization now includes re-chunking.**  db-merge
   remaps intern ids; remapped *element* words change leaf content, which
   can move chunk boundaries — a merged-in list is rebuilt from its element
   stream, O(n) per list.  Same class as the already-accepted trie
   re-canonicalization under key remap (docs/db-merge.md).

---

## 2. The kernels (`daemon/seq.h`, sibling of `arena.h`)

A `SequenceArena` owning the `InternTable<seqnode>`, with pure re-entrant
kernels (all interning via lock-free CAS, callable from any thread in any
phase — the same property as cnodes, and the reason mid-rule construction is
safe):

- `build(const u64* xs, u32 n) -> u64` — chunk once, O(n).  Used by literal
  lowering and by re-canonicalization.
- `len(t)`, `ref(t,i)`, `set(t,i,v)`, `ins(t,i,v)`, `del(t,i)`,
  `cat(a,b)`, `slice(t,i,j)`, `rev(t)` (O(n) by necessity),
  `cmp(a,b)` (lexicographic, physical-eq short-circuit),
  `foreach_leaf(t,f)` / `foreach(t,f)` (in-order),
  `find(t, const u64* run, u32 j, u32 from) -> pos|absent` (first match at
  or after `from` — the kernel under `lidx` and the demand enumerators).
- Internals: a `Chunker` struct (gear state + emit buffer) shared by build,
  edit-rechunk, and seam-merge paths; `seqparams.h` holds the frozen
  constants + a format version byte.
- S2 adds the byte-leaf arms (`bref` by codepoint, `bslice`, `bcat`,
  `bfind`, materialize-to-utf8string) behind the same node kinds.

Rendering: `writeValCSV` gains an `is_seq` arm rendering `[a b c]` (elements
recurse at `cdepth+1`, existing 4096 depth guard applies) beside the
`is_cnode` arm (`database.h:1631-1632`); `signatureOf` inherits it (content
signatures stay id-free and canonical).  S2: tag-4 strings render as quoted
strings by leaf-walking (no materialization).

---

## 3. Prims and typing

### 3.1 The op set (D7: `l`-prefix; D5: clamp vs partial)

Registered in `prim-fun-env` (`compiler/primitives.rkt`) — every prim
already receives `Database*`; kernels live in `daemon/seq_prims.h`:

| prim | signature | partial? | notes |
|---|---|---|---|
| `llen` | `cseq -> int` | total | O(1) |
| `lref` | `cseq int -> any` | **partial** | out-of-range → row-abandon |
| `lset` | `cseq int any -> cseq` | **partial** | |
| `lins` | `cseq int any -> cseq` | **partial** | valid positions 0..len |
| `ldel` | `cseq int -> cseq` | **partial** | |
| `lcat` | `cseq cseq -> cseq` | total | |
| `lslice` | `cseq int int -> cseq` | total, **clamped** | substr precedent |
| `lrev` | `cseq -> cseq` | total | O(n) |
| `lidx` | `cseq any -> int` | **partial** | first index; absent → abandon |
| `lmem` | `cseq any -> int` | total | 1/0, guard-friendly |
| `lsort` | `cseq -> cseq` | total | O(n log n); canonical output |
| `lst2set` | `cseq -> cset` | total | elements into a set |
| `set2lst` | `cset -> cseq` | total | ascending word order (canonical) |
| `ckeys` | `cmap -> cseq` | total | keys, ascending word order |
| `cvals` | `cmap -> cseq` | total | values, in ascending-key order |

**D5 rationale:** slices clamp (matching `substr`, and clamping composes
nicely with computed bounds); point ops are partial — absence of a position
is *data*, exactly the function-as-relation semantics finish-collections §A
gives `cget`.  Type errors (non-seq first arg, non-int index) stay fatal.

(`lsort`/`set2lst`/`lst2set`/`ckeys`/`cvals` confirmed IN for S1 by Tom,
2026-07-08.)  Deliberately cut from v1 (add on demand): `lpre` (prefix
test).  `size : any -> int` gains an `is_seq` dispatch arm (= `llen`),
matching its existing str arm (`prims.h:172-175`).

### 3.2 The partial-prim dependency (HARD)

`lref`/`lset`/`lins`/`ldel`/`lidx` need the row-abandon channel.  That is
exactly finish-collections §A (`prim-partial?` registry, `letp` c-op,
`bool ok` emission) — designed but not yet landed (verified 2026-07-08).
**RESOLVED (D15): finish-collections executes to COMPLETION before S1**, so
S1 consumes §A as landed machinery; S1's first item reduces to verifying
the mechanism and adding the sequence prims to the registry (entries only —
the §A design needs zero changes; `substr`-family additions defer to S2).

### 3.3 Typing

- `(list T)` stays the surface type name; the `flatten-nested-type` arm at
  `modules.rkt:352-355` keeps producing `(listof T)` rels entries (element
  type verbatim, per the §8.4 pipeline principle) — but the transparent
  resolution retargets from the cons `list` union to a new base type
  **`cseq`**, exactly as `(mapof K V)` resolves to `cmap` (M2.3 precedent).
  Optional sugar (D11): accept `[T]` in type position — intercept
  `(syn _ [] T)` in the same function, one clause.
- `cseq` joins the base-type seeding beside `cset`/`cmap`
  (`modules.rkt:210`); v1 prim signatures are `cseq`-level (element types
  await type-system Stage 2, same as sets/maps).
- Residual head-typecheck: `is_seq` joins the runtime tag guards the way
  `is_cnode` did (M2.3).
- `lattice-check.rkt`: `(listof T)` remains unrestricted as a value type; add
  `listof`/`cseq` to the collection element/key whitelist
  (`lattice-check.rkt:71,83,92,99`) so `(set [int])` and map keys of lists
  are legal — a sequence id is a canonical interned word, exactly what the
  whitelist expresses.  Lists have NO lattice role in v1 (no calculus rows;
  `(flat (list T))` keeps working since flat lifts any interned word;
  fixed-length product lattices stay deferred).

---

## 4. Surface syntax: splices anywhere

### 4.1 Grammar (D1)

`...` is a **postfix operator** (`parser.rkt:377`); `x ...` marks element
`x` as a **splice** — it binds/supplies a subsequence, not an element.  The
current restriction (splice allowed only on the final element,
`collections.rkt split-extension`) is lifted.  `_ ...` is an anonymous
splice: `_` (as element or splice) rides the EXISTING wildcard machinery —
simplification replaces each `_` with a fresh `(gensymb '__)` variable
(`simplification.rkt:154,189`, post-cache-key where gensym is legal), and
the seq-pat expansion treats any `__`-prefixed element/splice as dead: no
`lslice` materialized for a dead splice, no `lref` for a dead element (its
position contributes only to the length guard and to anchor arithmetic).
Bare `...` (a gap with no name) does not parse and stays that way.

```
[a b c]              exact 3-element list
[x xs ...]           head + tail            (today's form, unchanged meaning)
[xs ... y]           init + last element
[a xs ... b c]       first elem a, last two b c, xs = the middle
[a b ... c d]        elems a,c,d with splice b: a first, c d last, b = middle
[a ... b c ...]      splices a,c around element b: b occurs somewhere;
                     a = everything before, c = everything after
[xs ... a b ys ...]  floating run: contiguous a,b occur somewhere
[_ _ c _ ...]        positional: third element is c, length ≥ 4
[xs ... ys ...]      deterministic halves (D16): xs gets ceil(n/2)
[as ... bs ... cs ...]  deterministic thirds, longer slices first
[a bs ... cs ... d]  peel first/last, halve the middle
[as ... x bs ... cs ...]  x floats (fan-out); the right extent halves
```

**D1 RESOLVED (Tom, 2026-07-08): postfix confirmed.**  `[a b ... c]`
denotes a list that starts with element `a`, ends with element `c`, has two
or more elements, and whose (possibly empty) run of elements strictly
between `a` and `c` is the list `b`.  The identical syntax constructs in
heads: head-side `[a b ... c]` = `lcat(lbuild[a], lcat(b, lbuild[c]))` —
splice-anywhere is symmetric between patterns and construction.

### 4.2 Head vs body rules

- **Heads** (construction; every variable bound): **any number of splices,
  any positions** — it is just concatenation.  `[a xs ... b ys ... c]`
  lowers to `lcat` chains over `lbuild` segments.  Adjacent splices are fine
  in heads (`[xs ... ys ...]` = `lcat xs ys`).
- **Bodies** (patterns): **any number of splices, any positions** (D16,
  Tom 2026-07-09; the v1 at-most-two/non-adjacent restriction is lifted).
  Every body pattern normalizes to
  `pre  B₁ r₁ B₂ r₂ ... r_{m-1} Bₘ  post`
  — maximal blocks `Bᵢ` of adjacent splices separated by non-empty fixed
  runs `rᵢ`, fixed elements outside.  Two orthogonal mechanisms:
  - **Runs float** (the established two-splice semantics, now per run):
    each needed run joins the position enumerator, placements ordered
    left-to-right; fan-out = every placement.  Two or more floating runs
    in one pattern are legal but **warn at compile time** — O(n^r)
    placements per list.
  - **Blocks split deterministically**: a block of k adjacent splices
    over an extent of m elements binds k slices sized ⌊m/k⌋+1 (the first
    m mod k of them) then ⌊m/k⌋ — longer slices first, a pure function of
    the list value (boundary c at `lo + ⌈c·m/k⌉`).  `[xs ... ys ...]`
    halves favoring the left: `[0]` gives `xs=[0]`, `ys=[]`.  No
    enumerator, no fan-out — the split composes freely with demand and
    incremental maintenance, and is the intended workload-partitioning
    idiom (`(work l), (= l [a ... b ...]) --> (work a) (work b)` builds a
    canonical partition tree that terminates by dedup).

    **Demand recursion over splits is automatically keyed** (2026-07-10):
    a slice is a computed key with no inverse index, so the child-answer
    delta direction of a recursive answer rule would rescan demands
    re-slicing per pair (~O(n²) lslice kernel calls; 512-wide: 299s,
    measured 2026-07-09).  The demand transform now detects exactly this
    (and any prim-computed or pattern-field demand key) and emits a
    supplementary relation — the by-hand fix's `(halves l a b) <--
    (work l) (= l [a ... b ...])` table, generated as `$sup...` — keying
    every answer-return join (512-wide: 22ms, identical results;
    docs/demand.md §5, "supplementaries").  Writing the halves table by
    hand is no longer needed.

  **Direction asymmetry (D16, documented not fixed):** head-side
  `[xs ... ys ...]` concatenates, body-side splits — so cat-of-split is
  the identity but split-of-cat is not on unbalanced inputs.  A
  fully-bound body occurrence checks "xs, ys *are* the halves", not
  "l = lcat(xs, ys)".  Bindedness already picks the direction (§5.1);
  this is the same stance, stated for splits.

The desugar (`collections.rkt`) validates these rules pre-cache-key,
gensym-free, and emits the typed pattern clause of §5.1.  The or-split
hazard discipline is unchanged (desugar runs before both or-split sites).

---

## 5. Pattern compilation and access-pattern indices (the centerpiece)

The design principle: **compile patterns INTO existing clause classes** —
computes (`let`/`letp`), guards, and joins — so the planner, select-set
requisition, and emission machinery all apply unchanged.  Exactly one new
daemon mechanism exists (the occurrence-publish task, §5.4); everything else
is desugar + planning.

### 5.1 The neutral pattern clause

Bindedness (is the list bound before or by this pattern?) is a *scheduling*
fact the desugar cannot know.  So `collections.rkt` rewrites a bracket
pattern in an atom argument to a fresh deterministic variable (derived from
rule position, no gensym) plus one neutral clause:

```
(foo [a xs ... b])   ==>   (foo $L)  +  (syn _ seq-pat $L (elem a) (splice xs) (elem b))
```

`seq-pat` survives typecheck (elements type T, splices `(list T)`, list
`(list T)`) and reaches join planning as a new clause class
(`seq-pat-cl?` beside `join-planning.rkt:48-66`).  `ir-stack.rkt`'s accept
contract learns the pre-c-IR form (`c-accept?` — the known sharp edge).

### 5.2 Expansion when the list is BOUND (the default direction)

`schedule-body` expands a `seq-pat` whose list var is bound into ordinary
clauses, which then ride `fire-specials` (guards eager, computes
need-gated/flushed, `join-planning.rkt:309-366`) untouched:

- **Length guard first**: `(= $n (llen $L))` + `(cmp = $n k)` (no splice) or
  `(cmp >= $n k-|S|)` — cheap pruning before any probe.
- **Exact, all elements ground** (`[1 2 3]`): build the pattern id once
  (`lbuild` on constants — hoistable to `pre`) and emit `(eq $L $id)`.
  O(1); the canonicity payoff.
- **Anchored elements**: prefix elems `(letp x (lref $L i))`, suffix elems
  `(letp y (lref $L (- $n j)))` — the arithmetic rides existing computes.
  Ground anchored elements become `letp` + `eq` checks (the ground-output
  compute pattern, `join-planning.rkt:346-350`).
- **Splices**: `(let xs (lslice $L i (- $n j)))` — emitted ONLY if the
  splice variable is used elsewhere in the rule (`_ ...` — a `__`-gensym'd
  wildcard by planning time, §4.1 — and dead named splices skip the slice;
  a dead NAMED splice warns).
- **Floating run** (two-splice form): a **synthesized demand enumerator**
  binds the run position: for run arity j and element type τ, the desugar
  requisitions (once per (τ, j), deterministic name, demand-transform
  precedent `modules.rkt:559-572`):

  ```
  demand ($seq_occ<j> (list τ) int) int          ;; (L from) -> pos
  ;; generated rules: try pos = from via j letp lref probes;
  ;; recurse ($seq_occ<j> L (+ from 1)) — memoized, answers accumulate
  ```

  plus the free-element variant `($seq_elems (list τ) int) -> pos val` when
  the run contains free variables.  The pattern's run then compiles to a
  join against the answer table (fan-out = matching positions, which is the
  semantics), followed by anchored-element checks relative to `pos` and the
  two boundary slices.  Demand memoization gives each distinct (L, from)
  one evaluation ever.  **Why not the occurrence table here:** a bound `$L`
  may be a *computed* list (an `lslice`/`lcat` result) that never landed in
  any fed column — the occurrence table would silently miss it.  The
  enumerator works for any bound list; the table is reserved for the
  direction where it is sound by construction (§5.3).  A native fan-out
  enumerator kernel can later replace the rules-based one — that slot is
  the same one regex matching will need (§7), which is why v1 does not
  improvise a one-off mechanism for it.

### 5.3 Expansion when the list is UNBOUND: inverted occurrence indices

This is the join direction — "which lists have `e` (at position p / at
r-position q / anywhere)?" — and the piece Tom asked to make robust.  In
Datalog safety terms the list var is always *eventually* bound by its atom;
"unbound" here means the planner CHOOSES to bind it from an element first
because that is more selective than scanning the atom.  So occurrence
indices are a planner opportunity with real teeth, not a semantic need —
which is what makes need-driven generation sound.

- **The generated relations.**  Per element type τ actually used by an
  eligible pattern (deterministic synthesis in `modules.rkt` lift-type-envs,
  clo-union precedent; internal reserved names):

  ```
  $seq_at_<τ>  (val pos list)    ;; absolute position
  $seq_atr_<τ> (val rpos list)   ;; position from the END (suffix anchors)
  ```

  Membership needs no third relation: a probe on `$seq_at` with select
  `{val}` (ordering led by val, list next — the bucket-skew rule: lead with
  the high-cardinality column, never pos) answers "which lists contain e";
  `operationalization.rkt`'s one-index-per-select-set requisition
  (`:234-301`) derives that ordering from the join's select set with zero
  new machinery.  `$seq_atr` is co-populated in the same walk; it is only
  declared/fed when some suffix-anchored inverted pattern exists.

- **Planner integration.**  A `seq-pat` whose list var is not yet bound at
  its schedule point — or where `join-score` prefers the inverted order —
  expands to: join `$seq_at_<τ>` on the ground/bound element(s) (multi-
  element anchors = multiple probes joined on `list` with pos-arithmetic
  guards, e.g. `rpos` adjacency `(= p2 (+ p1 1))`), binding `$L`; the
  source atom then joins on `$L`; residual elements check via §5.2 chains.
  The score function treats the occurrence join like any join (it IS one).

- **The maintenance task (the one new daemon mechanism).**  A
  `SeqIndexTask` registered per fed relation (emit-cpp registers it ONLY
  when some crule actually joins the occurrence relation — an unused
  synthesized decl is an empty relation and costs nothing): at delta time,
  for each new row, for each fed column of type `(listof τ)`, if the seq id
  is not in the task's published set (a lock-free hash set keyed by id),
  walk its leaves once emitting `(val, pos, id)` (+ `(val, rpos, id)`) rows
  into the occurrence relation's send shards — riding the NORMAL
  write/intern pipeline next iteration, the same one-iteration lag structs
  and the §C decomposition have; semi-naive dependents refire natively and
  the fixpoint quiesces only when occurrence deltas do too.
- **Feeding set (D6).**  v1: all persisted relation columns whose rels
  entry is `(listof τ)`, program-wide.  This is a type-based
  over-approximation; a dataflow-restricted refinement (only columns that
  can actually reach the pattern's atom positions) is a straightforward
  later tightening.  Known hole, documented: seq words hiding in `any`
  columns are not fed (same class as every existing `any` caveat).
- **The blowup, stated honestly (the §5 concern from primitives.md).**
  Occurrence rows are keyed by seq id; an *accumulator relation* that grows
  a list one element per iteration inside an SCC materializes O(n) ids ×
  O(n) rows = **O(n²) occurrence rows** if that column feeds a needed
  table.  Two defenses: (a) need-driven everything (no eligible pattern →
  no table, no task); (b) a compile-time WARNING when a fed column's
  relation lives in a recursive SCC — naming the column and suggesting the
  bound-direction pattern or restructuring.  Not an error: sometimes the
  quadratic index is exactly what the user wants and n is small.
- **Staleness/deletion.**  Occurrence rows never retract (ids are immutable;
  value-role).  A stale row for an id no longer present in any live atom is
  harmless: every compiled use joins `list` back to a live atom.  When
  DRed^c lands, the publish task must emit signed records equivalent to a
  rules-derived maintenance (docs/incremental.md §8.5 obligation) — the
  append-only discipline makes the interim sound.

### 5.4 The full classification table

| pattern shape | list bound (deconstruction) | list unbound (inverted join) |
|---|---|---|
| all ground, no splice | `lbuild` id + `eq` — O(1) | id constant in the source join — O(1) |
| exact, some free | llen guard + `lref` chain | `$seq_at` probe on any ground elem → bind L, rest via lref |
| single splice, any position | llen guard + lref anchors + lslice | `$seq_at`/`$seq_atr` probes on ground anchors → bind L |
| two splices (floating run) | demand enumerator join + anchors + slices | `$seq_at` probe(s) on run elems + pos-adjacency guards → bind L |
| membership `[xs ... e ys ...]`, e ground | enumerator (all positions) or `lmem` guard if position unused | `$seq_at` select `{val}` → bind L |
| adjacent splices `[xs ... ys ...]` (block of k) | deterministic k-way split of the extent — llen arithmetic + k lslices, longer first (D16); O(1) placements | `$seq_at`/`$seq_atr` probes on fixed pre/post anchors → bind L, then split |
| ≥2 floating runs (`[_ ... x _ ... y _ ...]`) | one enumerator join per run + left-to-right `<=` chain; O(n^r) placements — **compile warning** | run-element `$seq_at` probes per run → bind L |
| nothing ground/bound constrains the list | — | **STATIC ERROR** (D12, Tom 2026-07-08): matching would enumerate every list in the database.  Any ground or already-bound element anywhere in the pattern restores support (probe `$seq_at` on it); a length-only pattern (`[_ _]`, list unbound) is likewise unconstrained and errors. |

One asymmetric nicety worth implementing: when a membership pattern's
position and splices are all dead (`[_ ... e _ ...]` style), the bound
direction collapses to a single `lmem` guard — no enumerator, no fan-out.

### 5.5 What this refactors away

The cons-era pattern path — brackets → `cons`/`nil` struct terms → struct
joins — is deleted from `collections.rkt` (the brace path is untouched).
`lib/list.slog`'s recursive demand judgments are replaced by thin demand
wrappers over the native prims (one body-less `rule` line each, e.g.
`rule (lst_append a b (lcat a b))`) so every existing call site — they are
relational atoms, not computes — keeps working verbatim, now memoized-native
instead of O(n) rules.  The cons-based library moves to
`tests/oracle/list-cons.slog` (renamed constructors, user-declared union) as
the differential oracle, the same discipline as the set/map rules libs.

---

## 6. Strings on the same engine (Phase S2)

### 6.1 Today's problem

Strings are monolithic `utf8string`s in the global InternTable; `substr` and
`+` copy the whole string and re-intern (`str_prims.h:25-44`) — O(n) per op,
quadratic build loops, and every intermediate lives in the table forever
(interns are permanent).  On disk, every distinct string is written whole
(`value.strings`, NUL-terminated records, `database.h:2400-2406`): two large
strings sharing 99% of their content store both copies entirely.

### 6.2 The design

- **Two representations, one type, deterministic split.**  Strings with
  byte length ≤ C (the byte-leaf max, default 256 — frozen with the other
  format constants) stay monolithic tag-0 interns, byte-for-byte today's
  representation: identifiers, symbols, and the vast majority of strings
  never change format, and the hot small-string paths keep their constants.
  Strings > C become **tag-4 ropes**: byte leaves + branch nodes in the seq
  arena.  The split is a pure function of content length, so canonicity
  holds across the boundary — and EVERY kernel must normalize on output
  (a concat result ≤ C returns a monolithic id; a rope is never built for a
  small result).  This normalization rule is the S2 correctness keystone.
- **is_str stays a bit test** (tag 0 or tag 4, §1.3); every `str_decode`
  call site is audited for rope-awareness — kernels iterate leaves; full
  materialization happens only at output boundaries (CSV, network, FFI).
  (The utf8 SEGV from the review pass is the standing reminder that these
  call sites are sensitive.)
- **utf8 discipline:** surface indexing stays in codepoints (current
  `substr` semantics); byte leaves snap boundaries to codepoint starts
  (§1.2); branches carry (bytes, codepoints) so both indexings descend
  O(log n); `size` stays O(1) from root counts.
- **Ops:** `substr` → O(log n + output), now also **partial** on
  genuinely-absent ranges? NO — keep clamped (behavior-compatible; D5).
  `+` → O(log n).  New: `sidx : str str -> int` (partial; find),
  `shas : str str -> int` (total guard), `ssplit : str str -> [str]`,
  `sjoin : [str] str -> str` (these two tie the libraries together),
  `schar : str int -> str` (partial), and the long-missing number
  conversions `s2i`/`s2f` (partial — unparsable is absent data, the §A
  channel again) and `i2s`/`f2s` (total).
- **String patterns are NOT in S2** — but the seq-pat machinery is
  deliberately kind-generic (§7), and `ssplit`/`sidx` cover the common
  cases relationally in the meantime.

### 6.3 The IO win (and the redesign Tom flagged)

Chunking de-duplicates string content on disk at chunk granularity: a rope's
bytes exist ONLY as leaf records, each stored once no matter how many
strings share it; a large string is never written whole.  Saving a database
with a thousand near-identical documents stores the shared chunks once.
Two further steps, designed-for but not committed here (§8.3): migrating
value.strings itself behind the same threshold (it already is, by the ≤C
rule — value.strings simply *becomes* the small-string store), and making
the arena partitions participate in db-compression's manifest DAG so
re-saving shares unchanged partition files instead of rewriting them.

---

## 7. The frontier boundary: what we tee up but do NOT design now

Stated once so S1/S2 leave the right seams and no more:

1. **Fan-out enumerator c-op.**  The one genuinely new mechanism regex
   needs — a body op producing multiple rows from a kernel (DFA match
   positions over a rope; natively-enumerated floating runs).  v1
   deliberately routes floating runs through demand enumerators so that
   when this op is designed, it replaces a *lowering*, not a semantics.
   Reserve: the `seq-pat` expansion point in `schedule-body` is the single
   place that decides enumerator-vs-native; keep it a dispatch table.
2. **Index-kind registry.**  Occurrence tables are one index kind.  Regex
   wants trigram/n-gram tables; string ordering wants a content-ordered
   secondary structure (intern ids are NOT order-preserving, so range JOINS
   need a new index kind; range GUARDS `(slt a b)` need only a cmp prim and
   can ship any time).  Reserve: the synthesis in modules.rkt and the
   emit-cpp task registration both key on an IndexSpec tag — write them as
   small dispatch tables over `{at, atr}` rather than if-chains, so
   `{ngram k, ordered cmp, regex-trigram}` are additive arms later.
3. **String patterns.**  Bracket patterns over strings (`"pre" s ... "suf"`
   or similar) reuse seq-pat classification wholesale once a surface syntax
   is chosen; the classification table (§5.4) is already
   representation-agnostic.  No surface commitment now.
4. **≥3 splices** (subsequence matching): **LIFTED 2026-07-09 (D16)** —
   the seq-expand emitter now segments any splice shape into floating
   runs (one enumerator join each, O(n^r) placements, warned at r≥2) and
   deterministic adjacent-splice block splits (§4.2).  What remains teed
   up is only the native fan-out enumerator c-op of item 1 replacing the
   rules-based `$seq_pos` lowering.
5. **Ordered indices for other prims** (ints/floats already order correctly
   as words within a type; the gap is only content-ordering for interned
   values) — same IndexSpec seam.

---

## 8. Persistence, IO, and the compression dovetail

### 8.1 Format

`value.seq/` partition directory beside `value.strings/`/`value.nodes/`
(`database.h:2396-2420` orchestration reused): 8 partition files, records in
iterator order, **length-prefixed variable records** (byte-leaf payloads may
contain NULs, so the value.strings NUL-termination trick does not transfer):
`u8 kind, u8/u16 count, payload…`.  Reload re-interns records in order;
ids reproduce because an id is content-hash + chain position and a chain
lives wholly in one partition (`intern.h` layout; the cnode argument at
`database.h:2205-2212` and `arena.h:8-12`, extended inductively — child
words hash without dereference).  `loadSeqBIN` mirrors `loadNodesBIN`
(`database.h:2466-2499`) with the variable-record framing; truncated record
→ fatal.

### 8.2 Format constants

`daemon/seqparams.h`: gear constant, masks, min/max bounds, small-string
threshold C, plus a format version byte written as the first record of
partition 0 (or a `value.seq/PARAMS` sidecar — executor's choice; loud
fatal on mismatch either way).  Frozen after the S1 bench; a future change
is a format version bump handled by rebuild-on-load (db-compression's
replay-from-origin makes this survivable for compressed DBs).

### 8.3 Sharing on save (Tom's requirement, 2026-07-08)

Requirements S1/S2 must satisfy, plus the opening we design toward:

- **No duplication within a save**: every node/chunk record written once
  per database regardless of reference count (interning gives this).
- **No whole-value duplication**: a rope string's bytes appear only as its
  leaf records; a chunked list's elements only in its leaves (S2: a >C
  string is never ALSO in value.strings).
- **Cross-save sharing (the redesign opening, not committed):** today a
  save rewrites partition directories whole.  The db-compression DAG model
  (input = ordered manifest of bin dbs) extends naturally: make
  `value.seq/`/`value.strings/`/`value.nodes/` partitions **append-only
  segments referenced by manifest** — a derived save appends only fresh
  records and references parent segments, so shared content is stored once
  ACROSS database versions too.  The in-order-re-intern invariant is
  preserved by construction (segments concatenate in manifest order; a
  collision chain still lives in one partition's segment sequence).  This
  belongs to db-compression's P-track, not S1/S2; S1/S2 must merely avoid
  foreclosing it — which the iterator-order/partition discipline already
  does.  (The existing caveat stands meanwhile: `writeRelationBIN` into a
  foreign db dir rewrites value.* from the current arena — same contract
  strings have today, `database.h`.)

### 8.4 db-merge

Seq node ids remap like cnode ids; remapped element words change leaf
content → re-canonicalize by rebuilding each imported sequence from its
(remapped) element stream via `build` — O(n) per value, same class as trie
re-canonicalization (docs/db-merge.md).  `$seq_at` occurrence relations are
ordinary relations and merge as plain tables; consistency follows from
publish-on-appearance (the merged DB's task re-publishes unseen ids).

---

## 9. Migration and compatibility

- **The builtin cons/nil/list union is retired** (D2): the `base-type-env`
  seeds at `modules.rkt:200-203` are removed; `(list T)` retargets to
  `cseq` (§3.3); `list`/`cons`/`nil` STAY reserved v1 (cheap; avoids
  silent-meaning-change if a user declares `cons`; revisit later).
- **Bracket desugar** retargets from cons-folds to seq-pat/native builds
  (§4/§5); the brace path is untouched.
- **`lib/list.slog`** becomes thin demand wrappers over prims (§5.5) — all
  existing `lst_*` call sites keep working; the cons library moves to
  `tests/oracle/list-cons.slog` with renamed constructors.
- **Goldens:** every golden whose CSV contains a list changes rendering from
  `(cons 1 (cons 2 (nil)))` to `[1 2]` — expected-output updates are
  mechanical but MUST be eyeballed (rendering, not semantics, may change).
  dem_*/lst_* tests are the acceptance bar: identical fact sets modulo
  rendering.
- `(flat (list T))` keeps working (flat lifts any interned word).
- The `st_ins`/`mp_put` routing rule for braces (pset/pmap declared → rules
  libs) is unaffected.

---

## 10. Testing plan

- **`tests/seq-tests.cpp`** (arena-tests sibling; ASan/TSan):
  differential vs `std::vector` reference over randomized op sequences
  (build/ref/set/ins/del/cat/slice/rev/find); **canonicity properties** —
  N random build paths to equal content → ONE id; cat associativity → same
  id; slice∘cat identities; **edit locality** — node-delta per edit bounded
  (assert fresh-intern count ≤ c·log n away from forced-run degeneracies);
  **degenerate content** — all-equal elements, adversarial
  boundary-dense/boundary-free streams (graceful, correct, dedup'd);
  8-thread concurrent interning; reload-id-reproduction round trip.
- **Unit (racket):** desugar classification — every §5.4 row maps a source
  pattern to its expected lowering; splice restriction errors (adjacent,
  ≥3, unbound+unground); dead-splice elision; enumerator synthesis
  determinism (same names across runs); reserved names.
- **Goldens:** `seq_basic` (literals, all single-splice shapes, both
  directions); `seq_run` (floating runs incl. `[a ... b c ...]`);
  `seq_join` (inverted probes: membership, positional, suffix via `_atr`);
  `seq_demand` (a dem_map-style program ported — the recursion-idiom
  regression canary); migration reruns of dem_*/lst_*; S2: `str_rope`
  (large-string build is linear — assert via node counts, not wall clock),
  `str_utf8` (multibyte substr/schar across chunk boundaries), `str_split`.
- **Oracle:** seeded differential runs vs `tests/oracle/list-cons.slog`
  (set/map-lib precedent — 3 random rounds, exact relation equality).
- **api-tests:** value.seq round trip; write-db → open → sizes; a foreign-dir
  writeRelationBIN sanity check.
- Validation discipline per finish-collections §5: targeted tests per item,
  ONE curated subset pass, full suite at most once at the end.

---

## 11. Phases and execution order

Two phases; S1 is the big one and is self-contained.

### Phase S1 — the engine + `[T]` complete

1. **Partial-prim precondition** — finish-collections has executed (D15);
   verify §A's `letp` mechanism and add `lref/lset/lins/ldel/lidx` to the
   `prim-partial?` registry (entries only).
2. **Engine**: `seqparams.h`, `seqnode`, `SequenceArena` kernels + Chunker;
   `seq-tests.cpp` green including canonicity/locality/degeneracy.
3. **Prims**: `seq_prims.h`, prim-fun-env rows, `cseq` base type, size
   dispatch, tag plumbing (`types.h`), `writeValCSV`/`signatureOf` arms.
4. **Typing**: `(list T)` retarget, whitelist additions, `[T]` type sugar
   (if D11 accepted), retire cons seeds, reserved-name adjustments.
5. **Desugar**: splice-anywhere validation + seq-pat emission + head
   lowering (`lbuild`/`lcat` chains); enumerator + occurrence-relation
   synthesis (deterministic names).
6. **Planner**: `seq-pat-cl?` class; schedule-body expansion (both
   directions, §5.2/§5.3); join-score integration; SCC-feeding warning.
7. **Emission**: `lbuild` c-op; SeqIndexTask registration (need-driven);
   occurrence publish path (shards → normal pipeline).
8. **Persistence**: value.seq write/load; params versioning; api-tests.
9. **Migration**: lib/list.slog wrappers, oracle move, golden updates.
10. **Bench + freeze** chunker constants; docs/status/memory updates.

### Phase S2 — strings on the engine

1. Byte-leaf kernel arms (+ codepoint counts, boundary snapping).
2. Tag-4 plumbing; `is_str` widening; representation-normalization rule;
   the `str_decode` call-site audit (every site rope-aware or
   materialize-at-boundary).
3. Reimplement `substr`/`+`/`size`; new prims (`sidx shas ssplit sjoin
   schar s2i s2f i2s f2s`); `substr`-family partial-registry entries where
   applicable (s2i/s2f/sidx/schar).
4. value.strings threshold rule (>C strings live only as ropes); IO
   sharing checks; str goldens + utf8 tests.
5. NOT here: string patterns, regex, ordered/n-gram indices (§7).

**The settled workflow (Tom, 2026-07-08): finish-collections to completion
→ S1 → check-in with Tom → S2.**  Rationale: finish-collections was
verified unexecuted (none of §A–§D in the tree; what DID ship earlier is
M2.1–M2.3 — arena, merge kernel, compiler typing — per docs/primitives.md);
executing it first (a) lands §A's `letp` mechanism and §C's
decomposition-publish plumbing as proven machinery S1 consumes rather than
absorbs, (b) closes the lattice plan cleanly, and (c) keeps S1 — already
the big session — focused on sequences proper.  finish-collections §C
carries a forward-pointer: the rows-into-shards publish path is built as a
reusable helper that `SeqIndexTask` (§5.3) reuses.  §D (`cjoin`) stays
cut-on-friction inside that shot.  Type-system Stage 2 later refines prim
element types orthogonally; incremental.md's DRed work consumes the
signed-record note in §5.3.

---

## 12. Decisions log and open questions

Decided (defaults, revisable before execution):
- **D1** (Tom, 2026-07-08) postfix splices at any position, patterns AND
  construction; `[a b ... c]` = starts a, ends c, ≥2 elements, b = the
  (possibly empty) middle run.
- **D2** retire builtin cons; names stay reserved; oracle preserved.
- **D3** chunker defaults §1.2; bench-then-freeze inside S1.
- **D4** tags: seq=3, strrope=4 (reserved in S1, used in S2).
- **D5** point ops partial; slices/substr clamped.
- **D6** occurrence feeding: type-based, program-wide, SCC warning;
  dataflow refinement later.
- **D7** `l`-prefix prims; `lst_*` demand wrappers preserve the old surface.
- **D8** floating runs: demand enumerators (bound dir) / occurrence joins
  (inverted dir); native fan-out enumerator deferred to the regex slot.
- **D9** two phases, strings second; S1 defines byte-leaf format unused.
- **D10** value.seq length-prefixed records; sharing requirements §8.3;
  manifest-DAG segments deferred to db-compression track.
- **D11** `[T]` accepted in type position as sugar for `(list T)`.
- **D12** (Tom, 2026-07-08) a body pattern that constrains the list with
  nothing ground/bound is a STATIC ERROR (would enumerate all lists); any
  ground constraint restores support (§5.4).
- **D13** (Tom, 2026-07-08) `_` rides the existing wildcard machinery
  (gensym'd `__` vars, simplification.rkt:154,189); `__`-prefixed
  elements/splices are dead — no lref/lslice materialized (§4.1).
- **D14** (Tom, 2026-07-08) `lsort`/`set2lst`/`lst2set`/`ckeys`/`cvals` are
  IN for S1.
- **D15** (Tom, 2026-07-08, superseding the same-day draft) the workflow is
  **finish-collections to COMPLETION → S1 → check-in → S2**.
  finish-collections was verified unexecuted; §C builds the shard-publish
  helper SeqIndexTask reuses (§11); §D stays cut-on-friction within that
  shot.

*(All open questions from the 2026-07-08 draft are resolved above; none
remain blocking.)*

---

## 13. Prior art

- **Prolly trees** (Noms, Dolt) — canonical content-defined-chunked B-trees;
  the direct model for §1, including the min/max-bound engineering.
- **bup / casync / restic** — content-defined chunking of byte streams
  (strings); FastCDC (Xia et al., ATC'16) for gear hashing + normalized
  chunking.
- **Merkle Search Trees** (Auvolat–Taïani 2019) — the set-side cousin
  (we keep Patricia for sets; MST solves ordering we don't need there).
- **Okasaki–Gill / CHAMP / RRB** — see docs/primitives.md §13; RRB remains
  the canonical example of why relaxed balance is disqualified.
- **Hyphenated ropes / jumprope** — non-canonical ropes; useful for kernel
  engineering (seam merging), disqualified as interned values.

---

## 14. S1 status appendix (EXECUTED 2026-07-08)

**Shipped, by §11 item:**

1. §A verified (3 unit tests) + `aslst/lref/lset/lins/ldel/lidx` in
   `prim-partial-set`.
2. `daemon/seqparams.h` (constants FROZEN post-bench — numbers in that
   header's comment; target-16 kept over target-32 for sharing/dedup
   granularity), `daemon/seq.h` (`seqnode`, `SequenceArena`, gear Chunker,
   the `rebuild` splice core with left-path reuse + right-side boundary
   resynchronization; `slice = take∘drop`, both O(log n)).
   `tests/seq-tests.cpp`: 2491 checks — differential vs `std::vector` with
   the EXACT-ID oracle (`build(model)` must equal every incremental
   result), N build paths → one id, cat associativity, slice/cat
   identities, edit locality (avg ~5, worst 9 fresh nodes per edit at
   n=200k, bound 256), all-equal degeneracy, 8-thread agreement, reload id
   reproduction.  ASan/TSan clean.
3. `daemon/seq_prims.h`: the §3.1 op set + `lempty`/`lpush` (construction
   kernels) + `aslst` (see below); `size` is_seq arm; `writeValCSV` `[a b
   c]` arm (signatureOf inherits); tags seq=3 / strrope=4 reserved
   (types.h); per-Database `SequenceArena` (`db->sequences()`).
4. `(list T)`→`cseq` retarget (`ir-shared.rkt` lattice-base-type, now
   RECURSIVE so `(flat list)` resolves through), `[T]` type sugar, bare
   `list` seeded as `(listof any)`, cons/nil/list seeds RETIRED (names
   reserved), lattice-check whitelist, `is_seq` residual tycheck arm
   (`'seq` accept tag through operationalization/ir-stack/emit-cpp).
5. `collections.rkt` rewritten: TWO walking modes — PATTERN (bodies +
   demand-head INPUT columns, routed by the demand registry): bracket →
   deterministic `$seqN` var + neutral `seq-pat` clause, nested terms
   hoisted to body `(= $seqeN t)`; CONSTRUCTION (all other head
   positions): bracket → in-place `lempty`/`lpush`/`lcat` chain (nested
   terms stay head-side — hoisting them made constructions into
   empty-relation joins, the kcfa bug).  Braces untouched.
6. `seq-expand.rkt` (NEW pass, compile.rkt between simplify and
   typecheck): rule-level direction fixpoint (pattern / construction /
   DROP for the demand transform's dangling copies — vacuous existentials
   under value semantics); §5.2 chains as plain surface prims scheduled by
   the planner's needs-gating (equality checks ride the ground-output
   compute ==-pattern); D12 static error; ≤2 non-adjacent splice
   enforcement at direction time; the `lmem` membership nicety; dead-item
   elision (D13, incl. never-read named splices).  NO join-planner changes
   were needed at all.
7. Inverted direction (§5.3) as an ADDITIVE occurrence join: eligible
   patterns (list bound by a persisted cseq atom column + a GROUND
   prefix/suffix anchor) get a redundant `$seq_at`/`$seq_atr` probe the
   planner schedules by score; soundness under the one-iteration publish
   lag = the delta-driven version refires (struct/decomp lag argument).
   `SeqIndexTask` (operators.h, RowPublisher reuse): one per fed relation
   per stratum, delta walk + per-task published set, iteration-0 full
   re-derivation on reload; registration via `(seqindex base (cols))`
   cprog decls (build-cprog, need-driven on `$seq_at` presence); dynamic
   marking + IDB classification mirror decomps; stratify edges base→occ
   ride the decomp-edges mechanism.
8. Floating runs via a synthesized POSITION enumerator: `$seq_posdem (cseq
   int)` / `$seq_pos (cseq int int)` (demand-style recursion, plain
   rules, ONE pair program-wide) + per-host ask rules over the ask-safe
   base clauses; run-element checks at pos+k, pos-bounds guards, boundary
   slices.  Same asymptotics as §5.2's match-driven enumerator for free
   runs; ground-run stepping (`find`-driven) is a later native-kernel
   upgrade (§7's reserved slot, unchanged).
9. `value.seq/` partitions (u8 kind, u16 count, payload record framing;
   PARAMS sidecar with the format version, loud fatal on mismatch) wired
   into staged writes, checkpoint, `loadDatabaseBIN`/`loadRelationBIN`;
   import remap: sequences are the FIFTH id space, rebuilt from remapped
   element streams (children-first worklist arm mirroring cnodes); api
   §10 round trip + §8 merge differential extended with nested/mixed
   list rows.
10. `lib/list.slog` → native wrappers (every `lst_*` judgment keeps its
    surface); the cons library → `tests/oracle/list-cons.slog` (renamed
    `clist`/`ccons`/`cnil`) + `tests/seq_oracle.slog` differential
    (equality-join agreement counts, exact); dem_map/dem_lambda/lst_flat
    migrated; goldens updated and EYEBALLED (kcfa/schemecfa results are
    1:1 rendering translations; demand tables shrank — fewer spurious
    demands).  New goldens: seq_join, seq_run, seq_oracle, seq_io.

**Additions this design did not spell out:**

- **`aslst` (partial, `any -> cseq`)**: every pattern chain's entry point.
  A bracket pattern matched against a non-sequence word (an `any` column's
  int, a flat lattice's `(top)`) MATCH-FAILS through the letp channel
  instead of faulting a fatal-on-type kernel — the cons-join behavior,
  restored.  Chains thread through its OUTPUT, so the planner orders it
  first by data dependency, not by heuristic.
- Bare `list` = `(listof any)` seed, keeping untyped `table (input list)`
  columns working.

**Occurrence indices COMPLETED for lists (same day, follow-up session):**

- Anchors widened from ground-only to **any constant or bound variable**
  at a fixed position, on BOTH sides (`$seq_at` prefix / `$seq_atr`
  suffix), **multi-anchor**: every qualifying position emits its own probe,
  all joined on the list.
- **Floating-run element probes**: a ground/bound run element at offset k
  probes `$seq_at` with `(= pos (- pk k))` tying the probe position to the
  enumerator's run start — schedulable either way (probe-first derives pos
  and `$seq_pos` validates it; enumerator-first turns the compute into a
  ==-check).  The membership nicety additionally probes with a FREE
  position ("which lists contain e").
- Probes join on the RAW list variable (the atom's word), not the `aslst`
  output (an early refactor silently disabled the assists — the indices
  went dead while results stayed correct via scan fallback; watch for
  this class of bug when touching the chain entry).
- **NO base→occurrence stratification edges** (unlike decomp-edges):
  probes are ADDITIVE, so the reader always also joins the fed atom
  (ordering the stratum after every base it reads), and completeness
  within the stratum comes from SeqIndexTask's iteration-0 re-derivation
  plus delta refires.  Edges would have merged `$seq_at` into every
  recursive list-producing SCC that probes it (breaking lattice
  cross-strata reads — kcfa exposed this).  The argument holds ONLY while
  probes are additive; a lowering that DROPS the source atom must
  reintroduce the edges.
- The **§5.3 recursive-feed warning** is emitted (compile.rkt, post-
  stratification: a fed relation written and read in the same stratum);
  the synthesized `$seq_posdem`/`$seq_pos`/`$seq_at`/`$seq_atr` are
  excluded from feeding themselves.
- `Database::getRelation` was a latent footgun this exposed: it used
  `operator[]`, PLANTING a null map entry for missing names (the generated
  registration probes "$seq_atr" in strata that never declare it), which
  `restoreOrphanRelations` then dereferenced.  Now find-based.

**S2 rope strings SHIPPED (same day):**

1. Byte trees in the same arena: `SEQ_LEAF_BYTES` (packed bytes + cp
   count) and `SEQ_BRANCH_BYTES` ((child, bytes, cps) triples); `Entry`
   carries a secondary codepoint weight; ONE generalized rebuild core
   drives both tree families (cuts in primary units — bytes for byte
   trees, always on codepoint starts).  The UTF-8 snap is a DEFERRED cut:
   a fired boundary waits for the next codepoint-start byte (≤3-byte
   slack, invalid UTF-8 cuts anyway), and seam resynchronization peeks one
   byte across node seams so boundary placement stays a pure function of
   the byte stream.  seq-tests.cpp byte section: 36k+ checks total —
   split-cat canonicity, slice_cp exact-id oracle, ref_cp/find_bytes with
   codepoint indices, leaf snap invariants, cat locality, mono-run
   degeneracy; ASan/TSan clean.
2. Tag-4 plumbing: `is_str` = tags {0,4} (`is_mono_str`/`is_rope` split
   it); **`Database::encodeString`/`decodeString` are the normalization
   keystone** — every producer of a string word from raw bytes routes
   through encodeString (≤ SEQ_BLEAF_MAX ⇒ monolithic, else rope; string
   LITERALS in generated code included), every consumer dispatches.  The
   `str_decode`/`str_encode` macros remain for guarded mono-paths and
   short internal constants only (documented at their definition).
   Audited sites: writeValCSV (rope-aware, signatureOf inherits), smt.h
   formula decoding, prims.
3. Ops: `+` (seam-cost rope concat, mixed-representation),
   `size`/`substr`/`schar` in CODEPOINTS over both representations
   (substr clamps; small results re-normalize to monoliths), `sidx`
   (partial, codepoint index), `shas`, `ssplit`/`sjoin` (bridging to
   `[str]` lists; empty separator = per-codepoint), `s2i`/`s2f` (partial:
   unparsable is data; NaN literals abandon — unrepresentable in the
   NaN-box), `i2s`/`f2s` (f2s matches the CSV float form).  Partial
   registry: `sidx schar s2i s2f`.
4. Persistence: byte-kind records ride value.seq unchanged (loader
   validates kind ≤ 3 and the snap slack); rope roots in relation rows
   reload by id reproduction.  Import: mono strings re-encode through
   encodeString (**a legacy over-threshold monolith re-canonicalizes to a
   rope on import — import IS the migration path for pre-rope
   databases**); ropes materialize + rebuild in the dest (bytes are
   content; nothing to remap).  Goldens str_rope (association canonicity
   at rope scale, cross-boundary substr, mixed concat), str_utf8
   (multibyte schar/substr/sidx across leaves, out-of-range partiality),
   str_split (split/join round trip, per-codepoint split, parse
   partiality); api §10 rope round trip + §8 merge differential with rope
   columns.

**Known caveat (documented, accepted):** a PRE-ROPE database opened
verbatim keeps its legacy over-threshold monolithic strings (reload id
reproduction pins them); equal content computed fresh in that session
interns as a rope — a different word, so joins between legacy and fresh
copies of the same >threshold string MISS until the database is migrated
through import/merge.  Self-contained legacy data is unaffected.

**Remaining open:**

- Per-τ occurrence tables (D6's later dataflow refinement) — one untyped
  pair serves v1.
- Native find-driven run enumeration (§7's fan-out enumerator slot; the
  position enumerator covers semantics today).
- The lbuild c-op (constructions cost one lpush rebuild per element —
  source-bounded, fine at test scale).
- DRed^c signed-record emission for SeqIndexTask (§5.3 note, when
  docs/incremental.md M-phases land).
- String/content indexing beyond `sidx`-style search: §15.

---

## 15. Smarter string indexing — NOTES ONLY (incomplete, needs design)

*Status: deliberately NOT designed.  These notes park the thinking so the
seams stay reserved (§7) and nothing lands half-baked; every item below
needs a real design pass (cost model, feeding discipline, DRed^c story)
before implementation.  Occurrence indexing is COMPLETE for lists; none
of it applies to string CONTENT yet — `sidx`/`shas`/`ssplit` are scans.*

1. **n-gram / trigram tables** (`$str_ngram k`): the string-side analogue
   of `$seq_at` — publish (gram, pos, str) for fed string columns; a
   substring/regex pre-filter joins grams of the needle and intersects.
   Open: gram width choice (fixed 3 vs configurable per D6-style
   declaration), byte-grams vs codepoint-grams (byte-grams are
   representation-natural given leaves; codepoint-grams match surface
   semantics), the feeding-volume blowup (|str| rows per string per k —
   worse than list occurrence rows; likely needs opt-in declaration
   rather than need-driven synthesis), and whether grams should be
   leaf-granular (dedup with the chunk store — an attractive interaction
   with the §8.3 sharing story: a shared chunk's grams are shared too).
2. **Ordered/content-comparison indices**: intern ids do NOT order by
   content, so range JOINS over strings (or lists) need a content-ordered
   secondary structure.  A `cmp`-prim-only version (range GUARDS like
   `(slt a b)`) can ship any time without new indices — that is the cheap
   80%.  The index form (order-maintenance keyed by content) interacts
   with reload-id reproduction and needs its own persistence design.
3. **Regex**: rides the §7 fan-out enumerator c-op (DFA over rope leaves,
   emitting match positions) + optionally the n-gram pre-filter.  The
   enumerator op is ALSO what native floating-run enumeration wants, so
   design them together; the seq-pat expansion's dispatch point is the
   single lowering seam.
4. **String patterns** (bracket-like surface syntax over strings): the
   seq-pat classification table (§5.4) is representation-agnostic and
   would reuse wholesale; blocked only on a surface-syntax decision.
5. **SeqIndexTask generalization**: today it walks list columns; a string
   variant (feeding n-grams) should share the RowPublisher discipline and
   the iteration-0 re-derivation contract, and both must emit signed
   records under DRed^c (§5.3's obligation) — design the incremental
   story ONCE for both.*
