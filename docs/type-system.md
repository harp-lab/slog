# The type system: deepening precision without a runtime

> **Groundwork shipped 2026-07-06 with M2.3** (docs/primitives.md): builtin
> base types `cset`/`cmap` + union `coll` type the arena's collection words
> within the name-set model; the collection prims carry real (flat)
> signatures; `(map K V)` in type position records `(mapof K V)` verbatim
> and resolves transparently to `cmap` (the `(list T)` pattern); `(set T)` /
> `(map K <valuespec>)` are lattice-role per §4's role-from-type rule; and
> the §6 residual-check machinery gained the `is_cnode` tag.  Stages 0–2
> below (type/alias forms, terms + unification, real ∀ schemes enforcing
> K/V/T parameters) remain the plan on top of this.

**Status:** design (2026-07-05). Motivated by two live pressures — the native
collection arena (`daemon/arena.h`, `cput`/`cget`/… in `compiler/primitives.rkt`)
now landing needs a *typed* `(map K V)` / `(set T)` layer to narrow its `any`
signatures (M2.3 of `docs/primitives.md`), and the recurring question of whether
`any` can be removed in favour of fully-specified types. This doc studies the
as-built type system, decomposes what `any` is actually standing in for, and
lays out a staged plan to make Slog **precise-by-default** while keeping the
front end honest about the parts that are genuinely dynamic.

The one-line thesis: **don't remove `any` — decompose it into the four features
it impersonates, and demote it from a silent default to a loud, opt-in top.**
Everything here is a front-end (compiler) discipline; §2.2 shows the runtime
neither sees nor pays for it.

---

## 1. The type system as built

### 1.1 A type is a flat set of ground names

The type environment (`type-env`, `compiler/modules.rkt`) is three hashes:

- **aliases** — `name → set-of-names`, transitively closed
  (`modules.rkt:111-127`). A `union` is exactly this: `union (val …)` registers
  `val → {val, closure, prim, numval, …}`.
- **rels** — each `table`/`struct`/`enum`/lattice relation to its column spec,
  e.g. `(table int list val)`, `(struct any list)`, `(enum nil)`, `(lattice count)`.
- **funs** — value-producing primitives, e.g. `+ : (fun A A -> A)`
  (`compiler/primitives.rkt`).

Type-checking a rule (`compiler/type-system.rkt`) is: infer each variable's
type (a single name), then for every relation use, check that the declared
column type and the variable's inferred type **intersect** once both are
expanded through the alias env (`type-match?`, `type-system.rkt:186-204`):

```racket
(let ([checks (or (set-member? t* 'any)          ; column is any
                  (set-member? t+ 'any)          ; variable is any
                  (not (set-empty? (set-intersect t* t+))))]) …)
```

There is **no structure, no parameters, no unification, no variance.** A type
is an unordered set of atoms; matching is non-empty set intersection with `any`
as a universal short-circuit in either direction.

### 1.2 The three escape/polymorphism mechanisms already present

1. **`any` — the top.** Short-circuits `type-match?` both ways. This is the
   feature under discussion.
2. **`A`/`B`/`C` — per-rule type variables**, but *only* in `fun` signatures
   (`type-system.rkt:73-108`). They are resolved by building a symmetric
   equivalence class over the argument (and result) variables of a primitive
   call and unifying whatever ground type any class member carries. This is a
   real "these positions share one type" — the beachhead for parametric
   polymorphism — but it lives only in primitive signatures and is re-derived
   per rule, not a first-class scheme.
3. **Transparent types** — a column may be declared with a *decorated* type
   that the checker sees through to a base type via `lattice-base-type`
   (`compiler/ir-shared.rkt:200-203`): a lattice column `(min int)` types as
   `int` for content uses (`lattice-check.rkt` owns the use discipline), and a
   `(list T)` column is recorded as `(listof T)` but resolves to the builtin
   `list` for matching. **`(list T)` already parses and is accepted today**
   (`modules.rkt:280-283`) — the element type `T` is preserved verbatim in the
   rel-env but *not enforced*. This is the precedent the whole plan generalizes.

### 1.3 `list` is a union; maps and sets are user code

There is no primitive `list` type. `base-type-env` seeds it as an ordinary
union (`modules.rkt:184-190`):

```
union (list (nil) (cons any list))     ;; cons : (struct any list)
```

So **`list` *is* `(list any)`** structurally, and always has been. Bracket
literals `[a b | t]` desugar (pre-cache-key, gensym-free) to `cons`/`nil`
(`compiler/collections.rkt`).

Maps and sets are *entirely* user-level: `lib/map.slog:14` is
`union (pmap (mempty) (mleaf int any) (mbranch int int pmap pmap))`, with
`mp_put`/`mp_get`/… as ordinary Datalog rules; `{k:v …}` / `{a b …}` value
syntax desugars to `mp_put`/`st_ins` calls against those libraries
(`collections.rkt:124-153`). At runtime they are just interned struct
instances. There is **no `(map K V)` or `(set T)` type**, and no `{…}` syntax in
*type* position (verified: `flatten-nested-type` handles symbol / inline union /
lattice valuespec / `(list T)` / nullary enum / struct — nothing else).

### 1.4 There is no alias or newtype declaration

The keyword set is fixed (`parser.rkt:301`): `def rule enum facts table struct
union demand lattice`. A one-member `union (ctx list)` gives a *transparent*
synonym today via the alias-set closure, but there is no dedicated `type`/`alias`
form and no *nominal* (distinct) alias.

---

## 2. What `any` actually is, and why the runtime makes precision free

### 2.1 `any` is four distinct features wearing one coat

Every load-bearing `any` in the codebase is one of four things the type system
cannot otherwise say:

| # | Role | True type | Sites |
|---|---|---|---|
| ① | **Top ⊤** — genuinely dynamic | `⊤` | user columns `env any`, `tag str any` (`tests/enum_struct_field*.slog`), `(flat any)` (`lattice-check.rkt:71`), debug/serialization columns |
| ② | **Parametric polymorphism** | `∀T. …` | `mp_get … -> any` (`lib/map.slog:50`), native `cput/cget/cmerge/cins/cmem/…` (`primitives.rkt:61-70`), `cons : (struct any list)` |
| ③ | **Existential (closure opacity)** | `∃ᾱ. clo(ᾱ)` | the demand transform's defunctionalized closures — `clo` structs whose fields are captured free vars, all `any`, dispatched via a shared `applyN` (`demand.rkt:145,380`) |
| ④ | **Numeric class** | `int ∣ float` | `+ - * / : (fun A A -> A)` (`primitives.rkt:17`) + mixed-numeric columns `table (v any)` resolved by `prims.h` runtime dispatch (`tests/prim2_mixed.slog`) |

"Require a concrete `T` everywhere, remove `any`" therefore is not one change;
it is *four*: add parametric polymorphism (②), existential/closure typing (③), a
numeric class (④), and retain a genuine top (①). Remove `any` without ②③④ and
you force users either to lie (wrap everything in a giant union) or to write
programs the checker rejects — and you make the compiler's **own generated
code** (③) untypeable.

### 2.2 The runtime is dynamically typed — precision costs nothing

A column cell is a single **NaN-boxed `u64`** with a 3-bit tag in the mantissa
(`daemon/types.h:53-61`); decoding dispatches purely on the word's own tag
(`Database::writeValCSV`, `database.h:1072-1101`), and even a struct's *type* is
recovered from `decode_struct_id(v)`, never from the column. `Relation` carries
no per-column type table (`database.h:86-121`). The runtime is fully
value-self-describing and homogeneous-by-tag.

Two consequences, both central to this plan:

- **More static precision has zero runtime cost and zero runtime risk.** No
  representation change, no perf hit, no reload/serialization impact. The entire
  risk budget of tightening the type system is front-end: expressiveness,
  migration, and inference effort.
- **`any` has an ongoing *cost*, paid as runtime `fatal`s that should be compile
  errors.** Because `any` columns can't be trusted statically, the daemon guards
  at runtime and aborts on mismatch: `types.h:114-129` `fatal`s when an
  `any`-typed prim feeds a non-numeric word into a min/max lattice column; the
  arithmetic/comparison paths tag-check and `fatal` (`prims.h:31-93`). Each is a
  static rejection deferred to a crash. So the real trade is not "precision vs.
  free `any`" but **"static rejection vs. runtime `fatal`."**

### 2.3 The collection substrate that the type layer must describe

The native arena (`daemon/arena.h`, new) hash-conses big-endian Patricia nodes
(`cnode`, tag `cnode_intern_tag`) in a lock-free CAS interner, exposed via
`cmap/cput/cget/chas/cmerge/cdel/cdiff/csize/cins/cmem` (`prims.h:184-256`). The
decisive fact for `(map K V)`:

- **The arena keys the trie on the full 64-bit tagged word**, compared as an
  unsigned integer (`arena.h:85-89,168-219`). Because strings, structs, and
  cnodes are all content-deduped, the value's own word *is* a canonical,
  content-addressed key with value semantics. "Intern any value → a 64-bit key"
  is not a separate step — the word is the key. So `cput`/`cget` already accept
  **arbitrary** slog words as keys, strictly more general than `pmap`'s `int`
  keys.

Constraints the type layer should encode (not the runtime — it is permissive):

1. **Float keys** compare by bit pattern (`-0.0 ≠ 0.0`, `NaN` never matches) —
   legal, lint-worthy, not banned.
2. **Lattice-role values cannot be keys** (an ascending value has no stable
   identity; `slog_lat_top` is a live word, `types.h:102`) — exclude, as
   `lattice-check.rkt` already excludes lattice union members.
3. **Ids are per-database and position-dependent** across *three disjoint*
   interners (35-bit strings chain-capped at 512 `intern.h:113`; 33-bit
   per-bucket struct-instance counter; 14-bit struct-type; 35-bit cnode). There
   is **no single unified id space** — the "id" is `(tag ∥ subspace-id)`
   multiplexed into the word. A map keyed on interned ids needs the remap pass
   on merge/reload (`docs/db-merge.md:37-49`). Irrelevant within a run; a real
   constraint for cross-database identity.

---

## 3. Design principles

1. **Gradual, never big-bang.** `⊤` stays legal and explicit so the existing
   suite (93 goldens) keeps compiling; code opts into precision incrementally.
   This is the `unknown`/`dyn Any` story, apt for a checker written in Racket.
2. **Demote `any` from default to opt-in, and make it loud.** A column is
   precise unless it *says* it is dynamic. Prefer spelling it `dyn` (or `top`)
   so it reads as "dynamic here," not "unspecified." Add a `--strict` mode that
   forbids `dyn` in *user* code while still permitting it in *generated* code
   (role ③) — teams get the guarantee without the language forbidding
   heterogeneity.
3. **Precision is a static discipline; the runtime never changes** (§2.2).
4. **Types drive lowering, not just checking.** Per `docs/primitives.md §8.4`,
   the same surface term routes to different codegen by its declared type
   (merge-sink vs. value-construction; int-key bit-ops vs. whole-word compare).
   The type parameter is representation-level information, which is the strongest
   reason to make it precise rather than `any`.

---

## 4. The target type language

Move the checker's representation from *name-sets* to *type terms*:

```
τ  ::=  int | float | str | dyn                 -- base + top
     |  Name                                     -- struct / enum / union
     |  Name τ̄                                   -- applied parametric ctor
     |  (list τ) | (set τ) | (map τ τ)           -- builtin parametric collections
     |  α                                         -- type variable (in schemes)
```

- **Unions** stay sums, but over type *terms*, so `union (opt (none) (some τ))`
  can be parametric.
- **Parametric constructors** get **schemes**: `cons : ∀T. T × (list T) → (list
  T)`, instantiated with fresh variables at each use site and unified against
  argument types (generalizing today's `A`/`B`/`C`).
- **Matching becomes structural unification** with `dyn` as top and an
  occurs-check for the recursive `list`/`pmap` definitions.
- **Bounds** on variables encode §2.3's carve-outs: `K : Key` (word-equality,
  not a lattice), separate from a value `V` and a lattice `L`.
- **Value role vs. lattice role** is a *type distinction*: `(map K V)` is a
  value column (interned id in a row); `(map K L)` with `L` a lattice is a
  lattice column (merge-sink). `lattice-check.rkt` and `emit-cpp.rkt` already
  branch on this triple — the type just needs to carry it.

`dyn` (today's `any`) remains a first-class member of `τ`: the sanctioned top,
required for role ① and as the fallback interface for role ③.

---

## 5. Staged plan

Each stage is independently shippable and gated on the full suite staying green.
Nothing below touches the daemon except where noted; the runtime is already
type-agnostic (§2.2).

### Stage 0 — surface syntax + aliases (cheap, low-risk, do now)

- A `type`/`alias` declaration registering a **transparent** synonym (e.g.
  `alias ctx list`) in the alias env; fully erased before codegen. Recommend
  transparent first; *nominal* newtypes (distinct identity, reject a raw `list`
  where a `ctx` is expected) are a later, larger want that fights the
  set-intersection model and should wait for Stage 1's term representation.
- Accept `[τ]`, `{τ}`, `{κ:τ}` in **type position**, desugaring to `(list τ)` /
  `(set τ)` / `(map κ τ)`, recorded verbatim and (initially) transparent to the
  encoding — exactly as `(list T)` already behaves (`modules.rkt:280`). Mirrors
  the value-level desugaring in `collections.rkt`. Buys documentation-grade
  precision immediately at zero risk, and is the forcing function for later
  stages.
- **D0.1:** brace disambiguation in type position — `{τ}` set vs. `{κ:τ}` map
  keys on the presence of `:`, matching the value-syntax rule
  (`collections.rkt:124-153`). Empty `{}` stays an error (write `(set …)` /
  `(map …)`), as at the value level.

*Files:* `parser.rkt` (keyword + type-position brace/bracket), `modules.rkt`
(`flatten-nested-type`, beside the `(list T)` clause), `ir-shared.rkt`
(transparent resolution siblings for `setof`/`mapof`).

### Stage 1 — types-as-terms + unification (the enabling rewrite)

Replace name-sets/`set-intersect` with type terms and structural unification;
`any` becomes an explicit `dyn = ⊤` absorbed *only* where a column is declared
`dyn`; unions become sums over terms; parametric constructors gain schemes with
per-use instantiation. **Inference stays local:** declaration column types are
the annotations, propagated within a rule; `dyn` is the boundary. No global
Hindley–Milner over the recursive rule graph (`eval`/`lookup`/`eval_args` would
otherwise force a unification fixpoint) — annotations at relation boundaries
bound the problem.

*Files:* `type-system.rkt` (representation, `resolve-local-type`, `type-match?`),
`modules.rkt` (alias env → term env). Self-contained; runtime untouched.

### Stage 2 — parametric polymorphism for builtins + stdlib **(= M2.3, do *with* the arena)**

Generalize `A`/`B`/`C` into real prenex `∀` schemes, and give the native c-ops
their true signatures so `(map K V)` / `(set T)` are *enforced*:

```
cput   : ∀K:Key, V.  (map K V) × K × V → (map K V)
cget   : ∀K:Key, V.  (map K V) × K → V              -- faults on absence; guard with chas
chas   : ∀K:Key, V.  (map K V) × K → int
cmerge : ∀K:Key, V.  (map K V) × (map K V) → (map K V)   -- left-biased; V join in lattice role
cins   : ∀T:Key.     (set T) × T → (set T)
cmem   : ∀T:Key.     (set T) × T → int
```

`lib/list.slog` / `lib/map.slog` get parametric signatures too. **Do not
over-restrict `K`:** the bound is word-equality (`Key`), not "interned" — ints
and floats self-encode, str/struct/cnode are content-addressed. `K`'s type
selects the canonicalization kernel (`int` → existing bit-op Patricia; general
word → the arena's whole-word compare, `arena.h:168-219`); an `any`-keyed map is
just `(map dyn dyn)`, a special case, not the default. This stage is the reason
to land Stages 1–2 alongside the arena rather than after.

*Files:* `primitives.rkt` (schemes), `type-system.rkt` (instantiation),
`lib/*.slog` (signatures). Daemon: none — the c-ops already exist.

### Stage 3 — numeric class

Introduce `num = int ∣ float` (or a small `Num` class) and type arithmetic
`+ - * / : ∀N:Num. N × N → N` (with `+`'s str-concat as an explicit overload).
Runtime dispatch (`prims.h`) is unchanged. Removes role ④ and lets
`prim2_mixed`'s `any` columns become `num`.

### Stage 4 — closures (last; keep the escape longest)

Type the defunctionalized `clo` **existentially**: at arity *n* its interface is
the `applyN` arrow `τ₁ × … × τₙ → σ` with the captured environment hidden
(`∃ᾱ`). Where a relation's closures share a statically-known interface,
**monomorphize**; fall back to a `dyn`-arrow only for genuinely first-class /
variadic dispatch. The demand transform already produces the correct *runtime*
shape (struct + `applyN`, `demand.rkt:369-388`); this stage only gives it a
*type*. This is the research-adjacent part and the last place to force
precision — the sanctioned home of the surviving `dyn`.

---

## 6. Gradual soundness: residual boundary checks

The type system need not be *statically* sound to be *sound*. Where the checker
cannot prove a type — §2.1's escape branch, a value flowing from `dyn` or a
polymorphic position into a more precise column — it **residualizes a runtime
check** at exactly that point (a gradual-typing cast). Slog's runtime makes the
check unusually cheap and unusually complete.

- **A shallow check is a tag test.** A value is a NaN-boxed `u64` with a 3-bit
  tag (§2.2); verifying a declared base type is one mask-and-compare
  (`is_s32`/`is_str`/`is_float`/`is_struct`+`decode_struct_id`/`is_cnode`,
  `daemon/types.h`, `prims.h:31-35`). O(1), negligible against interning.
- **Shallow is complete for flat types, outermost-only for structured.** For
  `int`/`float`/`str`/enum/a named struct the tag test *fully* verifies the
  declared type; for `(list T)`/`(map K V)`/a union it verifies only the top
  constructor, not the elements.
- **Deep well-typedness is free by induction — if constructors are checked.**
  With `cons : ∀T. T × (list T) → (list T)`, if every head that builds a cons
  cell is shallow-checked ("head is `int`, tail is `list`"), any `(list int)` is
  deeply well-typed *by construction* — no list is ever walked. Interning unrolls
  the recursion across insertions and memoizes it. Policy: shallow tag check at
  **every head column the checker couldn't prove**; deep guarantees compose from
  the checked constructors.
- **Where a deep walk is unavoidable, memoize by interned id.** A value from an
  untrusted, unchecked source into a precise column — a `dyn` column, or **facts
  loaded from a saved DB** (`docs/db-merge.md`, constructors never checked here)
  — needs a deep check. Since the check is a pure function of interned content,
  verify each distinct id at most once: amortized O(distinct values), not
  O(inserts).
- **The compiler already knows the residual sites.** They are exactly where
  `type-match?` succeeded *only* via the `any`-escape branch
  (`type-system.rkt:195-196`), never where the real intersection succeeded. So
  checks are emitted precisely for what cannot be proved, and fully-static rules
  pay nothing.

**Effect: `dyn` becomes sound-with-a-cast** — the difference between `any` (lies)
and `unknown` (checked at the boundary). The escape hatch stays available but
safe: crossing out of `dyn` costs one tag test, and this *replaces* the runtime
`fatal`s of §2.2 with a boundary check that has a defined disposition (§6.1).

### 6.1 Disposition of a failed check — drop, don't crash; record, don't corrupt

A failed boundary check neither crashes nor silently pollutes the target
relation. The offending tuple is **dropped from its target** and **appended to a
global, queryable `error` relation** as a structured error value. Two properties
follow: the analysis degrades to *partial-but-sound* (downstream joins never see
the bad tuple, so what remains is well-typed), and the failure becomes *data the
program can query and react to* rather than an abort. The daemon-side mechanism
— read-phase checks at the emit sink, per-kind error structs, a global funnel,
and the drop-to-error disposition — is the subject of a companion plan (in
design); the key invariant it must preserve is that `error` is a non-feedback
sink writable from any stratum.

---

## 7. Answering the original question directly

**Can we remove `any` and require a concrete `T` for every collection?**

- **Outright removal, no top:** no. It makes the compiler's own closures (③)
  untypeable, forces `num` onto every arithmetic column before Stage 3 exists,
  and strips a Datalog substrate of legitimate dynamism (①). A naive pass would
  either reject working programs or push users into meaningless unions.
- **Precise-by-default with `dyn` as an explicit, opt-in top:** yes, and it is
  the right target. It is free at runtime (§2.2), it *removes* runtime `fatal`s
  (§2.2), and it is reachable in the stages above without a big-bang break.

**Does it stress the type system?** Yes, at four named points, in increasing
order of difficulty: parametric containers (needs Stage 1), numeric (Stage 3),
genuinely-dynamic data (keep `dyn`), and closures (Stage 4, the wall). None of
the stress is in the runtime.

---

## 8. Open issues / checklist

1. **Nominal vs. transparent aliases** — Stage 0 ships transparent; nominal
   needs term-level identity (Stage 1) and a policy for where coercions are
   implicit.
2. **Inference scope** — local propagation + boundary annotations vs. a
   whole-program fixpoint. Default: local; revisit only if annotation burden
   bites recursive demand code.
3. **`dyn` boundary semantics** — precisely when a `dyn` value flowing into a
   typed position is accepted (implicit down-cast, as today) vs. requires an
   explicit guard. Interacts with the `--strict` mode.
4. **Key bound `Key`** — exact membership: exclude lattice types; decide float
   keys (allow + lint vs. forbid); document the cross-database non-portability
   (§2.3.3).
5. **Value role vs. lattice role in the type** — `(map K V)` vs. `(map K L)`
   must be recoverable by `lattice-check`/`emit-cpp` from the declared type
   (`docs/primitives.md §8.4`); ensure the term carries the role, not just the
   parameters.
6. **Rest/splice typing** — `[x xs …]`, `{k:v m …}` tails: the tail variable's
   type is the collection type, the head bindings are the element/entry types;
   confirm this composes with unification.
7. **Migration** — the goldens using `any` (`env any`, `tag str any`,
   `prim2_mixed`, `cn_basic`) either stay `dyn` verbatim or migrate to `num` /
   parametric forms; each is a golden diff, not a semantic change.
8. **Cache-key determinism** — any synthesized names (as `(list T)` already does
   with `_list_T`) must be gensym-free and stable, since declarations enter the
   `.so` cache key.

---

## 9. Non-goals

- Changing the runtime value representation or interners (§2.2 — unnecessary).
- Global type inference / full Hindley–Milner (§5 Stage 1 — bounded to local).
- Removing `dyn` entirely (§6 — it is the sanctioned home of roles ① and ③).
- Subtyping beyond `dyn`-as-top and union membership in v1 (variance is a later
  question if parametric lattices need it).
