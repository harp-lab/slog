# Finishing first-class collections: the wrap-up shot

*Plan (2026-07-06, agreed with Tom).  **Status: EXECUTED 2026-07-08 — all
four items landed, §D included (the friction it was gated on collapsed:
schedule-ordered planned bodies make the var→spec scan one pass, and a
function-local static holds the parsed spec, so no emitter threading).
§5 subset + unit/arena/api all green; docs/primitives.md M2.3/M2.4 status
blocks carry the landed details.**  Post-plan finding worth keeping: a
decomp-derived name must be DYNAMIC in EVERY stratum, not only where its
base ascends — the master (once) MapWriteTask re-derives the decomposition
from reloaded/imported content at iteration 0 and those rows land in
iteration 1's delta, so a static reader would miss them (caught by the
foreign-db seeding check; that seeding is also what makes an imported base
without decomp rows self-heal on first use).
SCHEDULING (agreed with Tom 2026-07-08): this doc executes to COMPLETION
**before** sequences Phase S1 (docs/sequences.md §11) — §A's `letp`
mechanism and §C's decomposition-publish plumbing are S1 dependencies
(S1's `SeqIndexTask` reuses the `RowPublisher` shards path in
daemon/operators.h), and building them here first keeps S1 focused on
sequences proper.  Two forward-pointers are marked in §A and §C below.*
This document is written to be executed in ONE clean session: every item
carries its design decisions, exact touch points, and acceptance tests, so
no re-derivation is needed.  Read docs/primitives.md (M2.1–M2.3 status
blocks), docs/lattices.md §0, and docs/db-merge.md P0/P1 status first for
where things stand; memory of record: the M2.1/M2.2/M2.3/merge sessions.*

**Scope: four items — (A) partial prims + in-SCC `cget` restored, (B)
orphan keep-alive hardening + the `(schema)` action, (C) M2.4 `R_has`/`R_at`
decomposition, (D) spec-aware `cjoin` (optional, cut on friction).  With C
landed, the planned lattice feature work is closed out; what remains after
this shot is examples/goldens (M2.5), `(vec T)`, type-system Stages 1–2, and
merge P2 hardening — all tracked in their own docs.**

**Test discipline for this shot (agreed): do NOT run the full golden suite
per change.**  Validate each item with its own targeted tests, then one
curated subset pass (~20 min), listed in §5.  The full suite runs at most
once at the very end — or not at all: report first, offer the full run.

---

## A. Partial prims (the general mechanism), then `cget` in-SCC

**Why.**  A computed prim today has no "no answer" channel — `cget` on an
absent key can only `fatal()`.  Every candidate *value*-level sentinel is
in-band (NaN-boxing makes every u64 a legal value) and user-forgettable.
The right general mechanism: **partiality is a prim attribute; the failure
mode is row-abandon, emitted by the compiler** — the same `return`
semantics cmp guards already have, attached to a value-producing op.  This
restores the function-as-relation symmetry (a body prim call behaves as a
join against a virtual relation; absence = failed match, like `mp_get`),
and mid-fixpoint it composes with the value-carrying delta: absent now →
derive nothing; the rule refires when the map ascends.  Sound, confluent,
demand-style.

**Design decisions (final):**
- Registry: a new exported set `prim-partial?` in `compiler/primitives.rkt`
  (do NOT change the `(fun ...)` signature shape — zero consumer churn).
  Initially `{cget}`; `substr`/parsing prims can join later.  (Sequences
  S1 adds `lref`/`lset`/`lins`/`ldel`/`lidx`, S2 adds `sidx`/`schar`/
  `s2i`/`s2f` — registry entries only, mechanism unchanged;
  docs/sequences.md §3.)
- Typed level unchanged: typecheck still normalizes to `let`; the planner
  (needed-gating, guard-feeders, flush) operates on typed `let`s and needs
  **zero changes** — partiality is consulted only at lowering.
- c-op: `operationalization.rkt` lowers `(let x (f args))` to a new c-op
  `(letp x (f args))` when `(prim-partial? f)`; `ir-stack.rkt` grammar
  (`c-body-op?`/`c-head-op?` beside `let`).
- Emission (`emit-cpp.rkt`, body and head arms beside `let`):
  `bool okN = true; u64 v_x = _prim_f(db, args..., &okN); if (!okN) return;`
  (`okN` indexed by hop position — deterministic, no gensym concerns).
- Runtime convention (`prims.h`): a partial prim's LAST parameter is
  `bool* ok`.  `_prim_cget(db, m, k, bool* ok)`: absent → `*ok = false`,
  return 0.  Type errors (non-cnode m) STAY fatal — partiality is for
  absent *data*, not for bugs.
- Calculus: restore the map-kind `cget` transfer row in
  `lattice-check.rkt` (child-spec descent, taint only at position 0) —
  it was built and removed in the M2.3 review round; it is one `case` arm:
  `[(eq? f 'cget) (and (taint-only-at? 0) (match spec [`(lattice map ,_ ,inner) `(lattice ,@inner)] [_ #f]))]`.
- `chas` stays (explicit boolean logic); a total `cgetor m k d` is NOT
  needed now (partiality covers the use cases; add on demand).

**Tests:** unit (operationalization lowers `letp`; ir-stack accepts it);
golden `cn_getp.slog`: absent-key `cget` with NO chas guard → row silently
dropped, present key → value (no crash — this was a guaranteed fatal
before); golden `lat_nested.slog`: **in-SCC cget** — a `(map int (min
int))` column read mid-ascent via `cget`, result flowing through a `+`
transfer into a `(min int)` lattice table in the same SCC, with the cycle
closed by an upward-closed guard (`(< v k)`) gating new keys (tainted
values may gate, not flow, into the map — the position rule).  Also rerun
`cn_basic`/`lat_set` (their guarded-cget rows must still pass unchanged).

## B. Keep-alive, finished properly + the `(schema)` action

**Where it stands.**  `runStratum` now restores any relation the incoming
stratum didn't re-register (default index + finalize + ingest) — no
relation ever loses data across a reload, regardless of what the program
or its compile-time manifest knows.  That inverts liveness onto the
daemon, where it belongs.  What completes the story is making schema
truth queryable from the LIVE daemon, so the front end can compile
against the session instead of a directory scan — the substrate for the
ad-hoc incremental .so-commit workflow (add databases, programs, SCCs in
any order).

**Design decisions (final):**
- `(schema)` action (actions.rkt + one emit loop, `sizes` as template):
  one s-expr per relation, name-sorted:
  `(schema-rel table <name> <arity>)` /
  `(schema-rel struct <name> <arity> <sid>)` /
  `(schema-rel lat <name> <arity> <spec-token>)` —
  exactly the information directory names carry, but from the live db
  (imports and prior programs included).
- `runslog.rkt`: `db-manifest-from-schema-lines` — parse those s-exprs
  into the SAME manifest hash `db-manifest-from-name` produces (this is
  the hook for a future front end to compile against a session; no
  slog.rkt orchestration in this shot — CLI sugar comes later with merge
  P2's offline verb).
- send-actions: `schema` spec.
- Keep-alive hardening tests (api-tests §9): imported-exclusive relation
  survives TWO chained strata (orphan → restore → dump → restore); a
  post-import-run `write-db` PERSISTS the orphan (writeDatabaseBIN sees
  its restored index) and reopens with correct sizes; `(schema)` output
  after open+import lists the union with correct kinds/specs, and its
  parsed manifest equals `db-manifest-from-name` of a `write-db`'d copy.

## C. M2.4 — `R_has` / `R_at` decomposition (closes the lattice plan)

**What.**  For a collection-lattice table `R(k̄, S)`, a derived,
relation-keyed decomposition (docs/primitives.md §4.2, the cheap
non-blowup animal): sets get `R_has(k̄, elem)` — a PLAIN monotone
relation; maps get `R_at(k̄, key, v)` — **itself a lattice table whose
value column carries the map's child valuespec** (pointwise semantics by
construction; nested maps compose because the child spec may again be
set/map).  This is what makes in-SCC membership/enumeration sound: each
element, once present, stays; Datalog draws only monotone conclusions.

**Design decisions (final):**
- **Need-driven synthesis by name.**  Using an undeclared name `<R>_has`
  (`<R>_at`) where `R` is a set-kind (map-kind) collection-lattice table
  synthesizes the declaration in `modules.rkt` (deterministic, no gensym
  — pre-cache-key like all decls) and marks `R` as decomposed.  A user
  declaring their own `foo_has` wins: no interception, no decomposition.
  No use → no decl → zero cost.
- **Stratification edge**: `stratify.rkt` adds the derived dependency
  `R → R_has` (as if a rule read R and wrote R_has) when the synthesis
  fired.  Marker representation (DECIDED): a parallel hash
  `decomp-env : derived-name → (base-name set|map child-spec?)` threaded
  alongside the type env the way demands are — do NOT extend rel-env
  entry shapes, which every pass pattern-matches.  Consumers: stratify
  (the edge), operationalization/emit-cpp (register the decomp target on
  the base relation's LatticeInternTask), and modules (synthesis +
  user-decl-wins check).
- **Runtime**: extend `LatticeInternTask` (operators.h) with an optional
  decomposition target: `Relation* decomp` + the payload spec.  At the
  merge point it already holds OLD and NEW payload words; emit rows for
  the ascent via a new arena walk `foreach_added(oldw, neww, f)` —
  enumerate entries of `new` not equal in `old`, pruning
  physically-shared subtrees — **O(change) deltas for free** (the §8.5
  tree-diff).  Fresh keys pass old = the empty word.  Rows are pushed
  into `decomp`'s send shards (emit_temp-style, nominal order) and ride
  the NORMAL write/intern pipeline next iteration — the same
  one-iteration lag structs have; semi-naive refire is native.
  **Build the rows-into-shards publish path as a small reusable helper,
  not inline in LatticeInternTask**: sequences S1's `SeqIndexTask`
  (docs/sequences.md §5.3) publishes occurrence rows through the identical
  mechanism, and should reuse this helper rather than re-derive it.
  For `R_at`, emit (k̄, key, value-word); its own LatticeInternTask
  merges per (k̄,key) by the child spec — machinery already exists.
- **Codegen**: `emit-cpp.rkt` `add-lattice-decl` registers the
  LatticeInternTask with the decomp target when the decl carries the
  marker (the decomp relation itself is declared as a normal
  table/lattice in the same stratum — its indices come from the planner's
  actual joins as usual).
- Calculus: nothing new — `R_has` is a plain growing relation (freely
  readable in-SCC); `R_at` is an ordinary lattice table under existing
  rules.
- Persistence/merge: both are ordinary relations — write/open/import all
  generic.  (Import note: a source db's `R_has` merges as a plain table;
  consistent because decomposition is derived from R monotonically.)

**Tests:** golden `lat_rhas.slog` — the in-SCC enumeration flagship:
gated reachability (`reach : (set int)`; an edge `(gedge a b g)` fires
only when `(reach_has a g)` holds mid-fixpoint — exactly what v1 could
not express); golden `lat_rat.slog` — map decomposition with `(map int
(min int))`: `R_at` converges to the pointwise minima, read both in-SCC
and cross-strata; unit tests for the synthesis (name interception,
user-decl wins, unused → absent) and the stratify edge.

## D. `cjoin` — spec-aware pointwise join (OPTIONAL; cut on friction)

**Why last/optional**: per-key `cput` contributions + separate head
contributions cover almost everything (the column's own merge joins
pointwise), and C's `R_at` covers the rest.  `cjoin` only adds
*materializing* the pointwise join of two map VALUES as an intermediate.

**Design (if done):** not a prim-fun-env prim (the runtime call needs the
spec, which no word carries).  A dedicated c-op like tycheck:
`operationalization.rkt` computes a per-rule var→spec map (the same scan
lattice-check's seeds do, without the dynamic-rels filter — every var
bound from a lattice value column) and lowers `(let x (cjoin a b))` to
`(cjoin x <spec-token> a b)`; unknown spec → compile error naming the fix.
`emit-cpp` materializes `const LatSpec* spec_N = parseLatSpecToken("...")`
once per task (sid-members precedent) and emits
`u64 v_x = db->collections()->merge_spec(v_a, v_b, spec_N);`.
`lattice-check`: whitelist `cjoin` as a transfer for set+map kinds, any
position.  Test: a golden joining two map values cross-strata + an in-SCC
variant.  **If the var→spec scan gets hairy, cut D entirely** — record it
as the remaining loose end in primitives.md and move on.

## 5. Validation plan (agreed: no full-suite churn)

Per-item tests as above, run as they land.  Then ONE subset pass
(~15–20 min warm, parallelizable in two shells):

```
# shell 1: goldens touching collections/lattices/prims/planner
tests/run-tests.sh --keep-cache \
  tests/cn_basic.slog tests/cn_getp.slog tests/lat_set.slog \
  tests/lat_nested.slog tests/lat_rhas.slog tests/lat_rat.slog \
  tests/lat_sssp.slog tests/lat_count.slog tests/lat_demand.slog \
  tests/st_basic.slog tests/mp_basic.slog tests/dem_brackets.slog \
  tests/lst_basic.slog tests/structs.slog tests/reach.slog \
  examples/tinycfa/0cfa-counting.slog

# shell 2: unit + arena + api (api includes merge + import-run + schema)
raco test tests/unit/  &&  \
clang++ -O2 -Wall -std=c++20 -pthread -Idaemon tests/arena-tests.cpp \
  -o build/arena-tests && ./build/arena-tests  &&  \
tests/api-tests.sh
```

Full suite: at most once, at the very end — default is to REPORT with the
subset green and offer the full run.

## 6. Execution order

A (mechanism) → A (cget + calculus row + goldens) → B (schema action +
api §9) → C (arena `foreach_added` → LatticeInternTask decomp → synthesis
+ stratify edge → emit → goldens) → D (only if smooth) → §5 subset →
docs/status/memory updates → report.

Known sharp edges to respect while executing (from the shipped sessions):
`daemon/.#*.h` lock files break the header fingerprint (`rm -f` first);
body `(= p (mk ...))` is a join, not a construction; `pset`/`pmap` live in
the ALIASES env; the tycheck accept contract lives in ir-stack
(`c-accept?`) — new markers must be added there too; noop.slog pins
edge/path arity (use `tests/api/empty.slog`); template literals in
Workflow scripts break on backticks.
