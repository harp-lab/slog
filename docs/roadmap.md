# Cross-stream roadmap: modules, tiers, reflection, REPL, incremental

2026-07-14. **Working plan, revised same day into a diamond:** a shared trunk
builds the keel and the interpreter, then development forks into two
concurrent threads — thread 0 (full incrementality, deep vetting) and
thread 1 (the REPL on forward incrementality) — and re-joins at an explicit
sync gate before level-1 debugging and the capstone work. Five design
streams are mature enough to collide unless sequenced deliberately; this
document owns ordering and interleaving only. Each stream's own document
remains normative for its content.

| stream | document | slices | status 2026-07-26 (v3.1.0) |
|---|---|---|---|
| incremental maintenance | [incremental.md](incremental.md), [incremental-status.md](incremental-status.md) | Phase 0, M0–M7 | Phase 0, M0, M1, M3, M6L 1–2, M4T, M5, M4S, **M4N ([m4n-contract.md](m4n-contract.md), all 4 slices)** shipped; **counted-interpreter milestone complete** ([counted-interp-contract.md](counted-interp-contract.md)); **M7 slice 1 complete ([m7-contract.md](m7-contract.md), sub-slices (a)–(d), 2026-07-24)** — thread 0's M-milestone spine is done |
| execution tiers | [execution-tiers.md](execution-tiers.md) | T0–T6, Q1 | T1 shipped; T2 core frozen, monotone conformance groups closed, **flavored execution interp-only by default**; T0 slices (a), (b), and (d) landed; canonical Q1 query/page/cancel dispatcher active; **T0(c) sub-slice c1 SHIPPED 2026-08-09 on `w5-runtime` (durable RuleKey/SccInstanceKey live: r1:/scc1: family over real ModuleInstanceKeys, session identity ledger, `identity-keys` tier — replay re-mints byte-identical, two instances of one library mint disjoint keys); **c2+c3 SHIPPED 2026-08-10: daemon rule-meta registry (register-rule-meta/rule-meta verbs, kernel-scoped RuleId↔RuleKey, mode-neutral + lease-admitted) and D9 fire vectors (dense slot table replaces the locked string map; interp native, string shim for native artifacts; stats battery 11/11 goldens unchanged) — T0(c) COMPLETE except the deliberately deferred (RuleId,VariantTag) stat rekey, a sanctioned golden-changing event for when its consumers exist**; T3a cold start shipped (2026-07-28); T5+R4 debugger arc complete (2026-08-02); **T4 COMPLETE (2026-08-08, [t4-contract.md](t4-contract.md) §0.1 ledger: kernel-local requisitions, canonical TU order, name-free clusters, descriptor attach, attachment identity + the accept re-key, per-rule selective emission)** — T6's prerequisite met; **T3b slice 1 (default tier classification) 2026-08-09 on `w5-runtime`: every rule VARIANT carries a §5.3 designation, `interp-only` variants are not emitted, and a stratum designated wholly interp-only builds no artifact at all — measured 247/499 strata over the warm suite cache ([t3b-contract.md](t3b-contract.md) §1); `tier-classification` tier in ALL, plan bytes unmoved; **slice 2 (tier-profile sidecar) same day: per-KernelPlanKey race observations under build/profile/, cold-tiered-arm consult — a warm profile with cold artifacts (the post-re-key 65-min scenario) runs zero clang, `tier-profile` tier in ALL**; **slice 3 (promotion + next-re-entry pickup) same day: make-promotion-upgrade self-rescue on the skip path, sinfo-artifact resolves best-cached at re-entry (also fixes the silent post-swap downgrade), sessions record the race, `tier-promotion` tier in ALL**; **slice 4 (core-budget arbiter + priority queue) same day — T3b IS COMPLETE ([t3b-contract.md](t3b-contract.md) §0.1 ledger: classification, profile sidecar, promotion/pickup, arbiter; o0-max honored, clang metric zero-on-warm, promote budget = 2× recorded O0 cost)**; **T6 IS COMPLETE 2026-08-11 ([t6-contract.md](t6-contract.md) §0.1 ledger; slice (d): the audit found harvested-answer LOSS on abort — consumption now staged per-binding, commit at finalizeAll / restore on abort, invariant in smt.md §9.9; `t6-restart` 11/11)**; next: N5+stats 5–7, the activation spine — **T6 slices (a)+(b) SHIPPED 2026-08-11 ([t6-contract.md](t6-contract.md)): always-on per-ReadAttempt fire staging (armed-only snapshot deleted), abortReadAttempt at MID_READ ∪ READ_COMPLETE with the (abort-read) verb, `t6-restart` tier 5/5 — §12.7 equivalence INCLUDING $stat_fires, admission + §12.13 flavor refusals driven; **slice (c) same day: post-abort pristine state admits the upgrade entry — executor-swap restart proven BOTH directions (plan↔.O0.so) with content equality + executor-blind total fires; per-key mixed-run fires equality is the (RuleId,VariantTag) rekey's second queued consumer** |
| modules/namespaces | [modules.md](modules.md), [n4-contract.md](n4-contract.md) | N0–N5 | N0, **N1**, N2-A/B, and **all of N3** landed (N1 lexical occurrences, qualification, bindings, and persisted module identity; N3-A/B/C daemon boundaries, direct history, durable type registry; **N3-D qualified-path transforms, 2026-07-26**); **all of N4** ([n4-contract.md](n4-contract.md): N4-A durable bundle in META format 2, restore-on-open, replay audit, boundary-backed REPL projection; N4-B mapped namespace attachment) -- **N0-N4 are complete**, N5 unstarted |
| reflection | [slog-reflection.md](slog-reflection.md) | RF0–RF5 | RF0 done; RF1 slices 0/0.1/1/2 shipped AND **THE DEFAULT IS ABI 2** (flipped 2026-08-06; [rf1-contract.md](rf1-contract.md) as-built: plan determinism, tie-group fixes ×3, ProgramModel, ABI-2 emitter + airtightness gate + daemon cohort decoder + Racket cohort adapter for the REPL's readers; `SLOG_PLAN_ABI=1` is the escape hatch; full suite 21/21 tiers + plan-determinism 506/506 cohorts at the new default); slice 3 (attribute vocabulary, absent-when-empty) and slice 4 (plan goldens of record, `plan-goldens` tier in ALL) SHIPPED 2026-08-06 — **RF1 IS COMPLETE, all six exit gates closed**; next in stream: RF1.5 model queries (unscheduled), RF2 image mount (W4′); RF5 semantic/module replacement now has a draft end-to-end contract in [rf5-contract.md](rf5-contract.md) |
| REPL | [repl.md](repl.md), [repl-ux.md](repl-ux.md), [repl-terminal.md](repl-terminal.md) | R0–R5 | native Rust shell, private TCP server, live session/daemon vertical slice, structured change projection, executable `--plain` golden, and R1 budgeted tree, navigation, semantic change cards, command completion, visible-canvas search, live-relation observations, and buffered pagination shipped; canonical Q1 cursor protocol active, with boundary catalog/friendly parser/value/proof adapters next |
| stats migration | [stats.md](stats.md) §7 | steps 1–7 | `$stat_*` shipped; migration unstarted |

## 1. Ordering principles

**P1 — Representation before consumers (the keel).** Identity taxonomy,
qualified names, the ProgramModel, and the Plan ABI split are cheap while
they have no production consumers and expensive after. They land before the
daemon interpreter (T2), the boundary catalog (N2/N3), and native rebinding
(T4) harden against them. slog-reflection.md §18.1 states the same rule from
the reflection side.

**P2 — One identity substrate.** M0.4a already ships Layer/Event/Slot-based
persistent keys (`VersionKey`, program events). `RuleKey`,
`ModuleInstanceKey`, `ProgramInstanceKey`, and `SccInstanceKey` ride the
same substrate (modules.md §6.4), built once in T0 — with a degenerate
module-occurrence component (the root include tree) defined so N1's real
`ModuleInstanceKey`s compose without a rekey.

**P3 — One protocol, not two.** T0's S-expression command protocol and N3's
transactional boundary requests (`prepare-boundary` / `commit-boundary` /
`abort-boundary`) are the same protocol. T0 reserved the verb space; N3-A
joined it without a second dispatcher. After the fork, protocol changes are additive verbs only,
under joint review.

**P4 — Interpreter before new flavors.** Flavored variants (`_count`,
`_maint*`) are interp-only by default (execution-tiers §5.3), and the
interpreter's counted admissibility is gated by the instantiation-multiset
audit (§4.3). Landing T2 **before** M4N and M7 means neither milestone
writes a line of `emit-cpp` — their new variants are planned and
canonicalized by the compiler but executed only by the interpreter, and
validated by the recount/fuzz oracles that already gate every M milestone.
This inversion is also what makes the fork safe (§4.3 below).

**P5 — One M milestone always in flight.** The decided queue M4S → M4N → M7
is preserved: M4S on the trunk, M4N/M7 as thread 0's spine. The incremental
cadence (contract doc → slices → exit audit) continues uninterrupted through
the fork.

**P6 — Every phase ships something user-visible.** Level-0 watches (trunk),
no-clang interpreted runs (trunk), a working REPL shell (thread 1, early),
the debugger (post-sync), live program editing with healing (capstone).

**P7 — Conceptual fork, physical trunk.** The fork is two *workstreams*,
not two long-lived git branches. Both threads land small, green, gated
changes on master under the ownership zones of §7. The "merge" is a sync
milestone — both threads' gates green plus the joint intersection battery
of §5 — not a git merge. Long-lived divergence in `session.rkt` or
`database.h` would make the re-join the riskiest event in the plan; trunk
discipline makes it a checklist.

## 2. The shape

```text
        W0: land the in-flight arc (M5, wcoj, docs)
        W1: keel     N0 · RF0 · RF1 + ABI split · T0   ∥  M4S
        W2: engine   T2 (+ stats rekey) · T3a cold-start · N1
                                |
                        F  — fork gate (§3.1)
                       /                    \
   thread 0: SEMANTICS                        thread 1: INTERACTION
   counted interpreter (§4.3)                 Q1 queries · N2/N3 catalog
   M4N -> M7                                  REPL R0 -> R1 -> R2 -> R3
   deep-vetting campaign                      level-0 watch UX
                       \                    /
                        S  — sync gate (§5)
                                |
        W4': T5 + REPL R4 (the debugger) · T4 · N4-A -> N4-B · RF2 · T3b
        W5': T6 · N5 + stats 5–7 · RF5 program/module replacement
             (rf5-contract.md) · R5 · derived watches
```

The interpreter is what makes the fork clean, because its concerns partition
three ways: the **monotone/forward** interpreter is trunk work and freezes at
F; the **counted/maintenance** interpreter belongs to thread 0; the
**read-only query** interpreter belongs to thread 1. Forward incrementality
(Phase 0 sessions: runs, batches, renames, saves, clear-and-rerun) is shipped
and stable, so thread 1 stands on settled ground while thread 0 extends the
flavored paths beside it.

## 3. The trunk (W0–W2)

### W0 — land the in-flight arc

Commit the current working tree: M5 slice 1, the wcoj cross-layer session
block, the document set. Nothing below starts on a dirty tree.

**Checkpoint 2026-07-14:** landed by this arc. M5 identity separation and the
join3 cross-layer regression are implemented; all 17 orchestrator harnesses
are green. M4S starts with a contract that pins struct-maintenance tasks,
route admission, and tombstone persistence; the direct-input/embedded-id
session fixture remains a small recorded M5 follow-up.

**Checkpoint 2026-07-15 (W0 closed):** the 17-harness orchestrator was
re-verified green on the committed tree, and the recorded M5 follow-up
fixture (`m5-keep-*`) both landed and earned its keep — it exposed a real
input-ledger hole (direct-input imports and flat opens recorded table rows
but not the struct heap, so a clear-and-rerun left restored embedded ids
tombstoned, decoding silently as garbage). Fixed in `importDatabaseBIN` and
`markLatestRelationsDirect`; details in `docs/m5-contract.md` exit
criterion 2. M5 slice 1's exit criteria are now met in full. W1 is open.

### W1 — the keel

**Checkpoint 2026-07-15 (first arc landed; contracts pinned):** N0 landed
(`names.rkt` authority, parser name-path collapse, emit-cpp identifier
hygiene, `dotted_ns` golden + unit battery). Gate note: a wholesale TU
byte-diff is NOT a valid N0 gate — legacy TU text is run-unstable (crule
emission order + gensym'd locals; measured ~12k normalized diff lines on
`deep_fact`'s TU across consecutive same-tree runs) while canonical `.plan`
sidecars are byte-stable run-to-run *for temp-free strata*. The evening
wholesale comparison sharpened this: gensym'd temp relation names were the
contaminant reaching plan bytes, D4 sort order, and KernelPlanKeys
(job-hash filenames were later PROVEN stable by slice 0's audit — the
"moved stems" were asymmetric compile sets, not renames); temp-free
strata were stable at every layer. Deterministic temp naming was promoted
into RF1 as slice 0 and SHIPPED same day (rf1-contract.md as-built:
500/500 plans byte-identical across runs, two further plan-layer
instabilities fixed alongside). N0's
byte-identity rests on the provable inertness of its changes for dot-free
names, 165/165 goldens, and content-level plan equality against the
`build-post2/` corpus modulo that one named defect. Ratified same
day: the progressive fork (§3.1), the minimal-for-T2 RF1 scope, and T2-A
starting immediately after the contract pins; drafted for review:
rf1-contract.md, t0-contract.md, interp-core-contract.md. T2-A0 landed
(`interp` harness in run-all.sh's quick tier, `-fopenmp`). M4S may start
immediately under the progressive fork.

*Compiler:* **N0** qualified-name substrate (`names.rkt` QName authority;
gate: byte-identical emitted C++). **RF1** ProgramModel + Plan ABI 2 split
into KernelExecPlan / DebugMap / binding schema / cohort manifest, per-kernel
plans; coordinate with N0's struct-ification of the program tuples — one
IR-hygiene arc. **RF0** round-trip probe (~1 week) with measurements
recorded in slog-reflection.md.

*Daemon:* **T0** command protocol dual-stacked with the path protocol;
provisional builders + seal validation; explicit entry modes; persistent
RuleKey/SccInstanceKey on the Layer/Event/Slot substrate; catalog verbs;
**level-0 watches**. Verb space reserved for N3.

*Incremental:* **M4S** — struct relations enter the DRed capability set on
the M5 tombstone substrate; tombstone persistence policy decided.

**Checkpoint 2026-07-17 (M4S slice 1):** acyclic struct cones are admitted
to the M1/M3 counted maintenance routes — sign-directed id resolution in a
new struct maintenance fold (intern path with tombstone resurrection when
positive; probe-only against live master then the non-erosive tombstone
peek when negative, a miss invalidating the epoch), `tombstoneStructRow`
membership transitions, id-keyed sidecar folds, and the `'new`-view fix for
staged struct-head follow-ups' content→id resolution joins (temp-driven
versions probe all-FULL, exact for tables but not for structs whose dead
rows leave FULL one iteration before the follow-up fires).  Routing
requires no struct edit target, no lattice in the cone, and all-acyclic
strata; the recursive sweep flavor refuses struct heads loudly until
slice 2.  The `m4s-*` chain/multictor/mixed-sign/import fixtures are
flipped to precise-route assertions; the by-name negative-sign struct
retraction refusal landed alongside.  Slices 2 (sweep) and 3 (persistence)
remain on thread 0's spine.

**Checkpoint 2026-07-17 (M4S slices 2+3 — M4S complete):** the sweep rode
slice 1's fold nearly verbatim (the DRed policy and dead-candidate
absorption were already in `MaintainStructTask`; the unchanged reseed
verbs resurrect struct candidates through verbatim-reinsert
reconciliation), with one genuinely new mechanism the selfjoin fixture
forced: staged struct-head follow-ups' content→id RESOLUTION joins lower
to a tombstone-aware probe (`join-tomb` → live master, then the
dictionary) because a sweep round may tombstone a head arbitrarily many
rounds before the last decrement referencing it — no one-round FULL∪Δ
view spans that gap, and partition occurrences must NOT see the
dictionary (double-decrement).  Slice 3 pins persistence: tombstones
never save; `reconstructStructTombstones` rebuilds each chain's dead half
at load (`dict(v) = (live(pred) ∪ dict(pred)) − live(v)`), replay
re-minting the rest by re-execution.  Diamond/selfjoin/dredhead/persist
batteries pin sweep routes, reseed counts, id resurrection, and the
save/load policy.  The incremental queue is now **M4N → M7**, both behind
the counted-interpreter gate (P4).

### W2 — the engine

**T2** decoded interpreter: cursor erasure including `Join3PrefixCursor`,
the full §4.1 vocabulary including `letp`/`cjoin`, task factories into
`slogd`, short slices, suspension; every task records
`(plan_key, variant_slot, pc)` from day one. **T3a** cold-start slice only:
install/seal plans before clang, interpret immediately, `SLOG_OPT=interp`.
**Stats steps 1+4**: `$stat_fires` rekeys to `(RuleId, VariantTag)`.
**N1** lexical module instances (compiler track, parallel): `instantiate`,
occurrence trees, qualification pass, real `ModuleInstanceKey`s.

**Checkpoint 2026-07-27 (N4 complete: work orders 4-7).** Opening a saved
database now restores its logical catalog before any row is loaded.
`slog db freeze` carries the catalog forward through the recipe-chain loader
hook and cuts its history, so a flat root is the database that has a bundle
and no recipe -- and therefore the one that exercises restore. The daemon
change this looked to need turned out to be unnecessary: instead of adopting a
verbatim-loaded environment (which `prepareBoundary` cannot express), the
restore skips the verbatim load and prepares the persisted head as ordinary
initial creates, imports rows into that boundary's private slots, and commits.
BoundaryKeys, VersionKeys, and TypeKeys survive exactly; a reversed create
order (`SLOG_N4_RESTORE_REVERSE`) forces 40 of 41 runtime SIDs onto different
values and every set, map, sequence, and nested struct still decodes.
A recipe layer takes the other route -- it rebuilds its own chain -- and is
audited against the stored bundle: head, declaration graph, VersionKey
environment, TypeKey registry, and program/module keys, with divergence a load
failure. `live-catalog` is now a projection of the selected boundary (so an
empty declaration appears in `tables`), a new `catalog` command publishes the
structured history/programs/modules/versions/types, and the Rust completion
inventory gained relation and namespace paths. Gated by 19 `n4c-*` session
checks, 12 new REPL projection assertions, and a Rust completion case.

**Checkpoint 2026-07-27 (N4-B complete: mapped namespace attachment).**
`attach DB as DEST` / `attach DB SOURCE as DEST` imports a saved database, or
one dependency-closed subtree of it, under a destination prefix as one
ordinary N3 boundary. `plan-attachment` (catalog.rkt) is pure -- selection,
dependency closure, component-wise prefix substitution, leaf-vs-namespace
shape, and the complete VersionKey/TypeKey maps are decided before the daemon
is contacted -- and it allocates through the *unchanged* `plan-boundary`,
whose established behaviour already is §5's mapping rules. `session-attach!`
prepares one boundary, imports into its private slots (the shipped
`importDatabaseBIN` remap, reached through the prepared overlay), and commits;
any failure aborts. The recipe step carries the self-auditing plan, replay
refuses source/destination/content drift, and the attachment enters the
durable bundle history under a new `attachment` origin. Gated by 15 unit
cases and a 27-check `n4b-*` session block covering root and subtree attach,
double attach with disjoint keys, merge into a compatible partial destination,
an empty member with no tuple directory, sets/maps/sequences/structs remapped
through each other, save+replay, and the escaping/occupied/catalog-less
refusals. Two settlements §5 did not anticipate are recorded in
[n4-contract.md](n4-contract.md) §5.1: builtin membership members do not move,
and internal `$...` relations are staged out of the payload.

**Fix 2026-07-27 (N1 sequence splice regression).** `qualify-rule`'s
`operator-name` tested `qname-symbol?` -- "does this symbol contain a dot" --
before the special-operator check, so the sequence splice token `...` was
routed into name resolution and failed there. Every program using `[x xs ...]`
was broken, including `lib/set.slog`, `lib/map.slog`, and `lib/list.slog`;
five compression cases and fourteen goldens were failing. `...` is dot-free
in no other special operator, so the dotted-name branch now excludes them.

**Checkpoint 2026-07-26 (N4-A work orders 1-3: the durable bundle is
written).** A saved session layer now carries its own logical catalog.
`compiler/catalog.rkt` gained the one canonical bundle codec -- boundary,
committed-boundary-history, version, type, and program/module records, with
a validator that refuses duplicate keys, dangling versions or TypeRefs, an
unlinked history, a head binding no record describes, and a stored-arity
disagreement. `compiler/dbmeta.rkt` cut the format to version 2, placed the
bundle in META, gated it on read and write, and folded it into the database
stamp. `compiler/session.rkt` accumulates the bundle from committed state
only: one head-assignment point, one history record per committed program
boundary or N3-D transform, TypeKeys retaining every qualified spelling they
have carried, and a prepared-boundary lease a save refuses to write over. A
legacy environment event restarts the chain rather than faking continuity,
and a session with no exact head writes no bundle at all. Gated by a 27-case
`tests/unit/n4-bundle-tests.rkt`, an `n4a-*` session block over a fixture
carrying qualified tables, a qualified struct column, a lattice table, and an
unwritten declaration, and the full unit + session suites. Restore-on-open,
the replay audit, the REPL projection, and the catalog-less refusals (work
orders 4-7) are next; [n4-contract.md](n4-contract.md) §4.1 records the exact
residue, including the new daemon boundary action the restore path needs.

**Checkpoint 2026-07-26 (N1 complete):** `instantiate` and the shared
`as`/`with` occurrence grammar now produce ordered lexical occurrence trees
with per-occurrence include deduplication. Qualification lowers complete
declaration/rule graphs and owner-scoped generated helpers through the
central QName authority before the existing middle end. Explicit bindings
perform component-wise prefix substitution, use directional `any` only while
validating the bound interface, and compile against the selected live catalog
rather than reconstructing types from the legacy manifest. Program IR and
compile groups retain occurrence metadata; session recipes persist
`ModuleInstanceKey`s derived from replayed `ProgramInstanceKey`s plus lexical
slots. Focused unit, golden execution, and two-segment live-catalog tests pin
double instantiation, client extension, richer actual namespaces, compatible
completion, atomic incompatibility, provenance separation, and replay data.

**Checkpoint 2026-07-16 (T2-A2/A3 engine admission + T0 sidecar seam):** the normal-set
decoded/sealed/bound path and real scheduler task have landed in
`daemon/plan.h`/`plan.cpp`. The admission fixture differentially compares
per-iteration deltas and disaggregated fires with the fused native operators
under the same scheduler, including boundary pause/resume, and production
factories cover the daemon's full arity range. T0's bounded ABI-1 reader now
parses a byte-identical real compiler sidecar into that same seam; typed
parse/seal refusals and selective binding cover the standard unused
service-struct prelude, and the parsed rule executes through the scheduler.
The reader also parsed the extant 857-sidecar two-corpus audit. This does not
claim T0 slice (b) complete (entry modes remain), much less F: the command
dispatcher/builders, pre-freeze T2-B conformance groups, and full
`SLOG_OPT=interp` compiler-driven suite remain ahead.

**Checkpoint 2026-07-16 (T2-B conformance group (i)):** ABI-1
`join-old`/`join-new` view probes and `exists`/`absent` filters now pass through
parse, seal, bind, and the production VM as cursor registrations. Old/new use
the native full/delta equations, delta orderings are explicit requisitions,
K=0 view scans and absence are supported, and bound rules hand workers cloned
cursor prototypes rather than factory lookups. Focused tests compare the same
read iteration's rows and fire counts with the native helpers and pin typed
rejections for missing/mismatched delta indices and unsupported filter shapes.
The next pre-freeze engine group is (ii), prims/`letp`/`tycheck`; T0 entry
modes/dispatcher remain a separate daemon track.

**Checkpoint 2026-07-16 (T2-B conformance group (ii)):** ABI-1 primitive
calls, copies, equality/comparison guards, `letp`, and `tycheck` now pass
through parse, seal, bind, and the production VM in pre/body/head position.
The complete emitted primitive-call ABI binds to shared daemon functions once
per call site, with typed arity and total/partial validation and declared-primitive
coverage at install. Partial misses abandon without an error; fallible total
primitives retain the native pending-error diversion; and `tycheck` runs after
the instantiation fire, emits four fields through a bound
`malformed_deduction` struct sink, and suppresses ordinary heads. The focused
parsed differential matches native straight-line control flow for fires,
ordinary rows, partial misses, and malformed rows under continuation slicing,
and pins unknown/undeclared primitive, arity, partiality, accept-set,
effect-relation, and accepted-struct refusals. At that checkpoint the next
pre-freeze engine group was (iii), the real `Join3PrefixCursor` erasure; T0
entry modes/dispatcher remained orthogonal.

**Checkpoint 2026-07-16 (T2-B conformance group (iii)):** canonical ABI-1
`join3` now passes through parse, seal, bind, the production VM, and ordinary
set sinks as one tri-state cursor level. Its key-simple arms keep the native
FULL/OLD/NEW seek and normalization semantics behind a private arm interface;
arity erasure is independent per arm, so the factory is linear rather than a
left/right cross-product. `PrefixCursor` does not gain general seek methods;
the only interface addition is a one-premise-default proof view so the
composite can expose both physical premises lazily. The focused suite checks
all nine view pairings against native `join3`, fires, budget-1 pause/clone
continuations, parsed production output, mixed arm arities, and typed
parse/seal/bind refusals. At that checkpoint the final pre-freeze engine group
was (iv), map/lattice probes; T0 entry modes/dispatcher remained orthogonal.

**Checkpoint 2026-07-16 (T2-B conformance group (iv), core freeze):**
canonical ABI-1 `join-lat` and `absent-lat` now pass through parse, seal,
bind, the production VM, and ordinary set sinks. Map storage arity determines
key arity; the full physical ordering must end in its payload column; and a
single arity-erased cursor covers K=0 all-bucket scans, K>0 prefix probes,
and pre/body absence. It retains a physical key-plus-payload proof row only
when observed and rejects missing, shape-mismatched, or wrong-concrete-type
map indices at cold bind. Native differentials cover non-identity key order,
rows, fire multiplicity, absence, and pause/clone continuation, with typed
parse/seal/bind refusals. This closes all four pre-freeze groups without a new
opcode, VM arm, or cursor method.

### 3.1 F — the fork gate

**Amended 2026-07-15 (progressive fork; ratified).** F's five criteria below
are unchanged, but F is the **interpreter-core freeze gate**, not the
begin-parallelism gate. Parallel work begins per-workstream as its own true
dependency lands:

| workstream | starts after |
|---|---|
| M4S (thread 0) | nothing — native-path on shipped M4T/M5 substrates; may start immediately |
| REPL R0–R1 (thread 1) | T0 slices a/b/d (dispatcher+catalog, seal, uniform pause record — t0-contract.md); level-0 watches co-develop post-fork |
| Q1 + R2 (thread 1) | T2-A admission gate + core freeze (interp-core-contract.md) |
| counted interpreter → M4N (thread 0) | T2-A admission gate + core freeze |
| M7 | M4N |

The core freezes early — after T2-A's admission gate plus the pre-freeze
T2-B conformance groups, conservatively including the `Join3PrefixCursor`
erasure and map/lattice probes (ratified 2026-07-15;
interp-core-contract.md pins the trigger and the freeze list) — and the
remaining monotone T2-B groups land as trunk chores under the frozen
interfaces; criterion 1's full-suite `SLOG_OPT=interp` run completes
during the fork rather than gating it. Ownership zones (§7) are
in effect from today. Nothing interpreter-touching forks before the core
freeze, so §4.3's safety argument is preserved exactly.

**Current status (2026-07-16): the interpreter-core freeze trigger is
satisfied and declared.** Q1/R2 and the counted-interpreter-to-M4N workstream
may now start against the frozen seams. The full fork gate F is not yet met:
T0's client-ready command path, the remaining monotone conformance groups and
full `SLOG_OPT=interp` suite, uniform pause transcript battery, and catalog
criteria below remain open.

**Checkpoint 2026-07-18 (T0 slice (a) landed):** the command-protocol
dual-stack is on master — one per-line dispatch for stdin and TCP, typed
refusals (`parse`/`unknown-verb`/`reserved-verb` with the generation
token), all fourteen reserved verbs answering by family, read-only
catalog verbs streaming keyed records (F criterion 4's no-string-parsing
consumer is `tests/api/catalog-check.rkt`), and the protocol-mode seam
slice (d) will scope the uniform pause record by. The dispatcher
consumes the ONE shared bounded reader (`sexp.h`, per the slice-(b)
as-built pin) — the parked branch's second grammar was deleted at
landing. Gates: protocol 41/41, pause, api, quick 9/9, session 528/528.
REPL R0 work is unblocked; R0–R1's full fork start still waits on
slice (b)'s entry modes and slice (d)'s pause record.

**Checkpoint 2026-07-19 (T2-B monotone normal path landed):** normal
`once`/`seeded`, temp, struct, and lattice sinks now execute through the
frozen interpreter seams. The sealed-plan installer reconstructs native
declarations, full/delta/seeded-only indices, write/intern/lattice tasks,
decompositions, oracle bindings, and sequence indices; it preserves native
reverse declaration order for stable constructor tags and collection
rendering. Canonical `cjoin` lowers to the existing primitive opcode, struct
filters reuse BTree cursors, and probe drivers consume the compiler-declared
DELTA order. `SLOG_OPT=interp` sends stratum `.plan` artifacts directly to the
daemon without compiling or loading stratum shared objects; separate action
plugins remain native. The focused differential and 29 lattice/sequence/SMT
goldens pass. The former `dem_lambda` generated-name mismatch was closed
2026-07-20 by hashing a compilation-root-relative source key. Its targeted
native run passes and the full interpreter golden suite is now 165/165 from
this clone.

The fork gate F is met when the daemon API is genuinely ready for a client
and has been exercised, specifically:

1. **Interpreter conformance:** per-iteration content-delta equality and
   instantiation-multiset (fires) equality against O0/O2; `SLOG_OPT=interp`
   full suite green — for the *monotone* vocabulary (normal, seeded,
   `_delta`).
2. **Protocol battery:** every builder/seal/entry-mode/generation-token
   refusal driven by a test; the existing session workflow harness passes
   *through the command protocol* dual-stack, not just the path protocol.
3. **Uniform pause record (amended 2026-07-15):** the command stack's
   single structured pause record — arbitrary pause or pause-for-cause
   citing a watch — as golden transcripts across pause classes, with the
   watch-citation cause variant validated; `watch`/`unwatch` verb space
   reserved. The level-0 watch battery itself is co-developed post-fork
   as thread-1/joint work riding this record.
4. **Catalog verbs** return structured records keyed by
   VersionKey/TypeKey (no string parsing), sufficient for REPL name
   resolution and completion.
5. The interpreter core vocabulary and dispatch are declared **frozen**:
   post-F changes to them require joint review (§7).

## 4. The fork

A "thread" is a development focus (a human plus agents), not necessarily two
people; both threads follow trunk discipline (P7).

### 4.1 Thread 0 — semantics: full incrementality, deeply vetted

The spine is the decided queue, now interpreter-first:

- **Counted interpreter admissibility** (execution-tiers §4.3; contract:
  counted-interp-contract.md, drafted 2026-07-17): the
  interpreter enumerates the exact instantiation multiset for `_count` and
  maintenance flavors, drives the shared `cnt_*` folds, and respects
  counted-plan attributes (no semijoin re-optimization). Gate: fires
  multiset equality plus maintained-sidecar equality with forced recounts,
  across the whole existing incremental battery under interpreter routing.
- **M4N — precise stratified negation:** anti-delta variants and pre/post
  transition scheduling, implemented as interpreter variants (P4); exit
  audit in the established style.
- **M7 — recursive lattice/rank repair**, likewise interpreter-first.
**Checkpoint 2026-07-18 (counted interpreter slice 1):** `(flavor count)`
plans now parse, seal, bind, and execute through the production
interpreter with zero changes to the frozen core.  The counted read
vocabulary landed as decode plus thread-0 factory registrations —
once/seeded one-row drivers over K=0 FULL scans, temp declarations and
nominal emit-temp staging, struct-master resolution probes, and a
mkstruct lowering to a pre-fire resolve cursor (fatal on zero-match,
the emit_struct_count closure stance) that composes chained
constructions with no new opcode.  The thread-0 sinks call the native
counting emitters verbatim, so kind-tagged batches reach the unchanged
CountTask/CountStructTask folds; `install_count_stratum` mirrors the
native flavored plugin (counted-head classification, fire-once
scheduling, read/dynamic manifests, beginStratumDelta entry), and
`SLOG_COUNT_INTERP=1` routes `_count` plugins through it as the
differential's second executor — default routing untouched until
slice 4.  A drafting error was found and fixed at the source: counted
plans were NOT semijoin-stripped as the tiers doc claimed
(`ensure-count-so` never disabled the lookahead); the count flavor now
plans semijoin-free, `incremental-flavor-abi` bumped to `ci1-v1`, and
the seal CHECK refuses stray `exists` ops.  The dual-executor
differential earned its keep on its first full run: the VM's
primitive-fault path still bound the normal flavor's error emitter,
whose kind-less batch tripped the M0.3 invalidation and freed the
count sidecars mid-round (an ASan-confirmed use-after-free); counted
rules now bind `emit_pending_error_count` with the rule's fold kind,
and the regression is a permanent fixture case.  The permanent counted
differential cases live in the quick-tier `interp` harness (sidecar
byte-equality against native tasks and hand-pinned words,
disaggregated fires, chained-construction fatal, typed refusals for
the maint flavors slices 2–3 will lift).  Slices 2–3 (maintenance
flavors) and 4 (routing flip + exit audit) remain on this spine.

**Checkpoint 2026-07-18 (counted interpreter slices 2–3):** the three
maintenance flavors now execute through the VM — again zero frozen-core
changes.  The negative pre-state union view is literally the frozen
`join-new` equation over post-overlay indices, so the only new cursor
is `join-tomb` (live master, then the tombstone dictionary); signed
sinks call `emit_maint`/`emit_lattice_maint`/`emit_struct_maint`
verbatim into the unchanged serial `Maintain*Task` folds, and
`install_maint_stratum` mirrors the native plugin's full registration
(kind-aware write/intern machinery, delta-index writers feeding the
exclusion and union views, dred for maint4neg, native fire-once
scheduling).  The dual-executor differential caught one real
divergence per leg: the prim-fault error arms (slice 1's tail) and
lattice-driven consumer epochs (flavored scan drivers are now
kind-agnostic — a lattice consumer is driven by the staged replacement
rows in the lattice's own delta).  Gates: interp battery 35 cases;
session 528/528 native AND 528/528 with every flavored epoch through
the VM.  Slice 4 (routing flip + exit audit) remains.

**Checkpoint 2026-07-18 (counted interpreter slice 4 — the routing
flip):** flavored variants are interp-only by default.  The compiler's
`ensure-*-so` functions ensure sidecars (.cprog + .plan) without
running clang and the daemon installs the sealed plan for every
flavored plugin path; `SLOG_FLAVORED_NATIVE` restores native flavored
artifacts as the differential's second executor (the flavored emit-cpp
paths exist for that alone — M4N/M7 add interpreter variants
exclusively, P4 discharged).  Corrupted-sidecar probes pin both
directions.  Exit-audit battery counts land in incremental-status.md;
M4N is unblocked on its completion.

**Checkpoint 2026-07-20 (M4N slice 1 — acyclic negated readers):** the
full stack landed per m4n-contract.md pins 2–5 with the slice-1
refinement (upfront finalization of input-edited negated relations,
global phasing retained — recorded in pin 3).  Planner: anti-delta
versions per fully-bound negated occurrence with the ratified pairwise
pre/post sibling split, `absent-old`/`absent-new` view ops carrying the
delta ordering, DRed+`~` as a typed refusal until slice 2 (21-case unit
battery).  Daemon: `AbsentView` decode/seal (maint flavors only,
delta-ordering equality checked), the XOR pre-state cursor
(`AbsentPreCursor`), `cnt_kind_view` with typed fold/drive fatals, and
the non-draining view staging vehicle
(`stageViewTransitions`/`stage-view-transitions`).  Session: the
`negatable?` cone flag, the M4N admission predicate (input-edited,
neg-only-read, fully-bound, acyclic, tables, interp-only), the
finalize-upfront route with per-phase drive `(−S)` + view `(S)` staging
(routes `maintain-negated-{negative,positive}`), and named fallbacks
for `'negw`, derived-negated, mixed reads, structs/lattices, and
`SLOG_FLAVORED_NATIVE` (emit-cpp emits `static_assert(false, ...)` for
the views — no native leg, loudly).  Gates: the four-flush canon
(initial/gained/lost/mixed churn incl. the ~b/~c sibling split) with
healed-equals-forced counts, five fallback fixtures, `m4n-*` block in
the session battery.  Next: slice 2 (recursive readers, ALL `~`
shapes).

**Checkpoint 2026-07-22 (M4N slice 2 — recursive readers):** the sweep
table ratified 2026-07-21 landed end-to-end.  Planner: the DRed+`~`
refusal lifted; under maint4neg corpse-driven versions retag `~` to
`~ever` (the third absence state) and anti-delta versions read positives
at the phase-entry `join-new` reconstruction (`'old` on acyclic routes
is unchanged; maint1 needed nothing — its `join-old` IS the rebuild's
phase-entry view, and reseeded rows sit in the delta so the anti-delta
excludes them while their own gain-driven versions fire).  Daemon:
`AbsentView::ever` decode/seal + `AbsentEverCursor` (∉FULL ∧ ∉Δ — two
plain bound-prefix witnesses, simpler than the XOR).  Session:
`m4n-rec-eligible?` routes recursive negation cones through the M4T
walk (upfront negated-input finalization → negative sweep with
drive/view staging → dred-reseed → rebuild gated on reseeds ∨ positive
edits ∨ LOST blockers, whose −journal is the rebuild's anti-delta
drive); routes `maintain-negated-recursive`/`maintain-negated-positive`.
Gates: m4n-sweep battery 14/14 — the cascade fixture's mixed flush
exercises the double-decrement hazard directly (round-1 anti-delta owns
(r 1 3)×blk(4); the round-3 corpse fire is absent-ever-excluded) and
settles counts-valid with healed-equals-forced; self-join closure w/
blocked-endpoint composition; derived-negated refusal (slice 3).
Planner unit battery 39/39.  Next: slice 3 (admission completion +
intersection-matrix ledger, derived-negated per-stratum phasing).

**Checkpoint 2026-07-22 (M4N slice 3 — admission completion + the
matrix):** inheritance masks precise across negative edges on both
routes; negation x demand split by cone shape; the derived-negated
route (producer-precise, journal-sign-decided reader suffix — the 0.A8
"~ + increments" reserved case is now precise); the mixed
input+derived admission hole closed; the intersection-matrix ledger
seeded in incremental-status.md.  DISCOVERY: maintenance x body
constants hung every flavor since M1 (non-draining probe drivers) —
fixed with lift-driver-consts + a maint-flavor seal refusal + flavor
ABI ci1-v2 (plans abi-keyed).  Next: slice 4 (exit audit) with
`join-pre` and derived x recursive as recorded unlocks.

**Checkpoint 2026-07-23 (M4N slice 4 — exit audit; M4N COMPLETE):**
the negation fuzz harnesses land in the incremental-stress tier — the
combined acyclic+sweep signed-stream oracle and the derived-negated
boundary hammer (route classes cycled so both sides of the journal-sign
decision fire every run, constant-column negated atom included), each
at 1/2/8 workers, ten warm flushes diffed per flush against fresh
recompute + forced recounts; the negation pause-stress attributes
1ms-budget pauses to the anti-delta `_maint3neg` phase; count-IR oracle
legs cover both canon runs.  The audit note is in
incremental-status.md.  **M4N is complete — M7 (recursive lattice/rank
repair) opens**, with `join-pre` and derived x recursive readers as its
recorded companion unlocks.  **v3.1.0 tagged on the milestone**
(2026-07-23; .version, display-only).

**Thread-0 bearings (2026-07-19, v3.0.1).**  How this thread proceeds:

1. **M4N** (contract: m4n-contract.md, drafted 2026-07-19) — the
   negated-body-driven variants as interpreter plans: anti-delta
   versions with inverted polarity, the per-sign drive-vs-view staging
   protocol at negative edges, pre/post absence views as plan ops over
   thread-0 cursors.  Slices: acyclic readers → recursive readers →
   admission + intersections → exit audit.  Its differential is the
   oracle triangle (replay content, count-IR oracle, forced recounts):
   anti-delta variants have no native leg by design.
2. **M7** — recursive lattice/rank repair, opening on M4N's exit,
   interpreter-first on the same seam (M6L's contributor machinery +
   the DRed change-splitting adopted in lattices.md).
3. **The standing vetting campaign runs alongside, not after**: the
   intersection-matrix ledger goes into incremental-status.md during
   M4N slice 3 (its negation rows are the natural first entries), the
   fuzz generators grow negative edges in M4N slice 4, and long-horizon
   soak (hundreds-of-flush streams with save/load round-trips) lands as
   its own arc between M4N and M7.
4. **Banked and reusable**: the flavored install seam, the oracle
   triangle harnesses, and the -O0 registration-ladder TU are the
   substrate every remaining thread-0 milestone extends — new variants
   mean planner emission + seal admission + cursor/sink registrations,
   never new executor machinery.

- **The standing vetting campaign** — the reason this thread exists beyond
  the milestones. Full incrementality is the system's central bet and its
  testing should outweigh its implementation:
  - an **intersection matrix** ledger in incremental-status.md (feature ×
    feature: negation × recursion, lattices × structs, sequences/collections
    × maintenance, demand × edits, compression/accel × maintenance, oracle
    answers × edits, freeze × edits), each cell either tested-by-name or
    consciously excluded;
  - **dual-executor differential** as a permanent fixture: every maintenance
    epoch runs under interpreter and native where both exist, comparing
    content, sidecars, and fires;
  - **long-horizon soak:** hundreds-of-flush streams with periodic forced
    recounts, mid-stream save/load/replay round-trips, and pause/resume
    injection attributed to every phase;
  - **adversarial scheduling:** the existing 1/2/8-worker seeds plus
    randomized slice budgets (`SLOG_MAX_MS=1`-class stress) over the new
    routes;
  - extending the independent Racket count-IR oracle toward maintenance
    flavors where feasible.

### 4.2 Thread 1 — interaction: the REPL on forward incrementality

Everything here runs on shipped Phase-0 semantics plus the frozen monotone
interpreter; nothing waits for thread 0.

- **Q1 — query engine** (thread 1's interpreter extension): `scan-full`
  driver, `yield` sink, `QueryContext`, pagination, probe-only interner
  entry points. Gate: query hygiene — bit-identical database after any
  query, including cancelled and paused-state queries.
- **N2/N3 — catalog and boundary transactions:** `CatalogDelta` /
  `BoundaryPlan` planner subsumes `update-manifest`; daemon
  prepare/commit/abort boundary verbs join the T0 protocol; `TypeDescriptor`
  registry replaces the name-discovered `structs_by_id`; lowest-free SID
  allocation. (Serves completion, empty members, boundary handles — REPL
  substrate, hence this thread.)
- **REPL R0 — the shell:** session ownership, `dbN/@vN/@tN/#N` tables,
  semantic verbs as a skin over `session-*!`, change summaries, budgeted
  printing, level-0 watch/break with paused-mode observation, dbtool verbs
  mounted. Golden transcripts in `--plain`.
- **R1 — the canvas:** navigate mode, gesture echo, cards, completion.
- **R2 — the query register** over Q1: `?`/`?count`/`?exists`, `explain`,
  `uses`/`find`, dump.
- **R3 — the workbench:** the scratch layer with instant interpreted views.
  `clear scratch` rides the *shipped* clear-and-rerun fallback — and
  silently improves as thread 0 lands precise routes. Tier visibility
  (`tiers`, `code`) reads whatever T3a exposes.

**Checkpoint 2026-07-16 (Q1 slice 1 / R2 engine surface):** the thread-1
`query.h`/`query.cpp` extension now runs existing-index `scan-full` plans
through the frozen machine into a non-mutating paged `yield` sink. A separate
`QueryContext` owns continuation, cancellation, and one-query admission and
never enters `RunState`; rows/count/exists provide the client-neutral backing
for `?`/`?count`/`?exists`, with a structured bound-plan explanation.
Probe-only short-string and bignum resolution returns empty on a miss and
never allocates an interned value. The focused hygiene differential preserves
all fixture master rows and exact heap counts across successful, paused,
cancelled, empty, and refused queries. No core opcode or cursor interface
changed.

**Checkpoint 2026-07-16 (Q1 slice 2 / engine forkpoint):** an empty physical
driver order now means an explicit scan-plus-filter fallback. Binding chooses
the lexicographically first catalogued order that is actually materialized,
remaps its physical tuple into nominal query registers, and reports the
degradation in `explain`; it never requisitions an index. The initial audited
compute table admits numeric comparisons, storage-neutral numeric conversion,
and read-only string/sequence inspection through query-specific checked
adapters. Wrong runtime types abandon the row without touching pending-error
scratch, and an exception during paging cancels the context and releases its
lease before propagation. The hygiene differential now also pins reverse-only
fallback, safe total/partial/guard computes, paging failure, and the exact
pending-error record.

**Checkpoint 2026-07-17 (Q1 slice 3 / catalog planner):**
`compiler/query-plan.rkt` now constructs executable query plans as a pure
function of an immutable boundary/materialization snapshot and a typed query
request. It binds every logical relation to an exact VersionKey, uses only
catalogued full orders, chooses a deterministic size-weighted driver and
prefix-probe schedule, closes guards/absence/audited computes at their first
safe frontier, and allocates stable dense registers before lowering to a
`daemon/query.h::Plan`-shaped value. Explain distinguishes driver
scan-plus-filter, suffix probe-plus-filter, and a larger driver forced by
existing-index prefixes. Unsafe negation, incompatible types, non-whitelisted
computes, unsupported relation kinds, and schedules requiring a body K=0 scan
are structured front-end refusals. The memoized scheduler is bounded to 16
positive atoms; its diagnostic datum is deliberately not a new wire grammar.
The focused battery covers reverse-index reuse, missing-index driver changes,
post-probe equality, computes/guards, snapshot absence, determinism, and typed
refusals; all 212 compiler unit tests pass.

**Checkpoint 2026-07-17 (Q1 slice 4 / universal body fallback):** the ordinary
arity-erased full-view probe cursor now admits `K=0` and walks every physical
hash bucket with exact pause/clone continuation. Probe drivers remain `K>=1`,
so outer-driver semantics do not change. This closes the deferred T2-B
ordinary Cartesian scan and lets Q1 lower any no-prefix body atom to a body
full scan plus explicit equality filters, still over an already-materialized
catalog order. The native differential compares non-identity-order rows,
fires, proof premises, and cursor-budget pauses with `join_all`; the query
hygiene fixture covers paged body fallback and marks it degraded. The catalog
planner now costs `K=0`, reports its body scan-plus-filter reason, and reserves
`no-feasible-schedule` for cyclic/un-groundable compute dataflow. The expanded
planner battery has 11 focused cases; all 213 compiler unit tests and the
optimized native interpreter/query battery pass.

**Checkpoint 2026-07-17 (Q1 slice 5 / catalog-to-daemon meeting contract):**
the compiler now adapts separate declaration, boundary-environment, and
VersionKey-keyed materialization maps into the immutable planner catalog. It
checks referential integrity plus kind/arity agreement and retains empty
storage declarations. The resulting plan has a canonical ABI-1 wire datum;
the daemon's bounded reader decodes it to a typed object, the existing query
sealer audits it, and the typed builder binds relation slots only by exact
VersionKey. One checked-in golden payload crosses Racket serialization and
C++ parse/seal/bind/page execution, with parse, ABI, and wrong-VersionKey
refusals pinned.

Q1/R2 are still in progress. N2/N3 must supply the real persistent
`C_k`/`E_k` boundary and materialization overlay, and T0's generic dispatcher
must own generation/phase admission plus `query`/`query-page`/`query-cancel`.
The payload/builder seam is ready for that meeting, but deliberately has no
exact-command branch in `slogd.cpp`. The R2 parser/rendering and transcript
battery follow the dispatcher integration.

**Checkpoint 2026-07-23 (threads reconciled at merge — T0(b)/(d)
converged).** During the fork both threads independently built the
shared-trunk T0 slices (b) entry modes and (d) uniform pause record. At
merge, **thread 1's design is adopted as the trunk**: the
connection-scoped SCC/stratum builder lifecycle
(`scc-begin`/`scc-seal`/`stratum-begin`/`stratum-add-scc`/`stratum-seal`)
over file-scope `EntryMode`/`EntryModeK` admission types, and the keyed
`(paused ...)` command-session pause record — a superset of the frozen
positional path-stack bytes — with its `PauseCause`/`PauseRecord`
`renderPauseRecord` machinery. Thread 0's parallel
`installStratumChecked`/`(install-stratum ...)` verb and the SExp
`validatePauseRecord` validator are superseded (this was the forced
resolution: the already-merged `plan-count.cpp` and
`protocol-record-tests.cpp` bind thread 1's types). M4N's maintenance
surface — `journalSigns`, `stageViewTransitions`, the `AbsentView`
filter, the `cnt_kind_view` staging — is unaffected and rides beside the
adopted lifecycle. **R0–R1's full start is unblocked.**

**Thread-1 checkpoint (2026-07-20; independent interpreter/protocol prep).** The monotone
normal interpreter path is ready for the UX branch to consume: normal and
delta plans install declarations and native write/intern machinery directly,
the compiler can route strata through `.plan`, the frozen interpreter core is
unchanged, and the focused plus 29-program feature batteries are green. The
repository-wide run was interpreter/native-equivalent. Its shared
`dem_lambda` checkout-path baseline is now repaired, and T0(d)'s uniform
command-stack pause record plus slice (b)'s checked runtime entry state machine
are landed without touching `repl/`. Thread 1 deliberately remains decoupled
from the separately developed UX until the command builder lifecycle is a
sensible integration seam.

Thread 1 proceeds in this order:

1. **Independent substrate checkpoint (completed 2026-07-20)** — demand-name
   identity is checkout-independent; T0(d)'s pause record and the T0(b)
   runtime `EntryMode` state machine/generation gate/legacy shims are landed.
   Gates: unit 219/219, interpreter operator, protocol 48/48, pause 18/18,
   session 528/528, targeted native `dem_lambda`, and full
   `SLOG_OPT=interp` golden 165/165.
2. **Finish the independent T0(b) command lifecycle (completed 2026-07-21)**
   — connection-scoped SCC and stratum begin/add/seal objects, generation
   admission, D16/builder/entry refusals, count restart/tier-swap policy, and
   the command-only dual-stack session workflow are landed. The ABI-1 bridge
   takes one canonical sidecar per SCC and one SCC per runtime stratum; no REPL
   code changed.
3. **Synchronize the UX work at that seam (completed 2026-07-22)** — the
   canonical workbench command patch is imported without the UX checkout's
   unrelated M4N work. There were no daemon-builder overlaps; the shared
   command boundary and terminal lifecycle pass their joint gates.
4. **R0 → R1 on the shipped substrate (server contract landed 2026-07-22;
   executable `--plain` client join landed 2026-07-23)**: session ownership,
   semantic verbs over `session-*!`, change summaries, and the golden plain
   transcript are joined through one client result model; canvas behavior is
   next. Nothing here waits on thread 0 —
   forward incrementality and the frozen monotone interpreter are the
   foundation, and `clear scratch` silently improves as thread 0's
   precise routes land (M4N just widened them to negation cones).
5. **The Q1/R2 meeting point (dispatcher half completed 2026-07-23)**:
   T0's dispatcher owns `query`/`query-page`/`query-cancel`, generation/phase
   admission, connection-scoped cursor lifetime, and structured page
   sentinels. N3-B now supplies the live direct boundary/materialization
   overlay; N3-C now supplies direct TypeKey/SID descriptors and
   boundary-aware struct rendering, while N4 persists them. R2's
   `?`/`?count`/`?exists` and `explain` can land over the already-golden
   payload seam once checked REPL value-handle ownership joins.
6. **Toward F**: the monotone T2-B normal path, compiler-driven
   `SLOG_OPT=interp` route, checkout-independent demand names, and uniform
   pause record are landed. The remaining fork-gate work is the slice-(b)/(c)
   builder/identity surface and post-fork watch battery integration.

Deferred on this thread until after S: level-1 anything (provenance watches,
stepping, why/why-not), `whatif`, fork/branching vocabulary beyond reserved
words.

**Thread-1 checkpoint (2026-07-21; T0(b) command lifecycle complete,
pre-UX-sync).** The daemon now owns a connection-scoped ABI-1 SCC/stratum
builder over canonical `.plan` sidecars: `scc-begin`/`scc-seal`, then
`stratum-begin`/`stratum-add-scc`/`stratum-seal`. All five mutations are
generation-gated and acknowledged; parse/I/O/D16, provisional-state,
entry-state, suspension, and capability failures remain typed.
`stratum-seal` read-only-preflights bindings before the checked entry
transition, pushes without auto-continuing, and preserves legacy path-stack
behavior through the existing installer wrappers. Entry/flavor policy pins
normal=fresh/upgrade, delta+maintenance=resident-delta, and
count=resident-count; count restart/tier-swap attempts are capability
refusals. The sidecar bridge deliberately admits one SCC per runtime stratum;
T0(c)'s rule identity/builder work can extend the SCC source without changing
this lifecycle. `repl/` remains untouched. Exit gates: interpreter operator
pass; protocol 67/67; pause 18/18; session 528/528; full cache-cleared
`SLOG_OPT=interp` golden 165/165.

That pre-sync seam is now closed by the 2026-07-22 checkpoint below. Coupled
R0/R1 work may begin over the shipped command lifecycle. Keep T0(c) identity
(`rule-meta`, stable keys, per-attempt fire vectors) separate from UX
rendering, and connect Q1's already-golden query payload only when the N2/N3
catalog overlay supplies real VersionKey-boundary state.

**Thread-1 checkpoint (2026-07-22; canonical UX command sync complete).** The
six-file UX patch is integrated at the T0(b) seam: `:help`, `:status`, `:ping`,
and `:quit` are the canonical workbench commands in server help, terminal
copy, and documentation, while the unprefixed server aliases remain accepted
for compatibility. F1 now emits the same generated `:help` command and durable
transcript entry as typed input. The private co-author lane admits the
read-only colon commands and explicitly rejects `:quit`. No daemon builder,
interpreter, session, or query-engine file changed, and the UX checkout's
unrelated M4N commits and working-tree contract draft were not imported.

The integration gates are green: Rust format and 28/28 frontend/model tests;
16/16 Racket frame/dispatch tests; daemon protocol 67/67, including the full
SCC/stratum lifecycle; and a real interactive PTY run in which `:status`
returned protocol/version/session state, `:quit` returned `Goodbye`/`REPL
closed`, terminal input modes and the alternate screen were restored, and the
process exited zero. This is the clean handoff into coupled R0/R1 work. Next,
add semantic session verbs over `session-*!` and a stable `--plain` golden
transcript harness before canvas-specific behavior. Keep T0(c) identity work
and Q1's N2/N3-dependent catalog meeting on their existing independent seams.

**Thread-1 checkpoint (2026-07-22; semantic server contract prepared before
the client join).** `compiler/repl.rkt` now wraps its existing `session-*!`
calls in one settled semantic-result path. New loads, runs, add/delete,
rename/drop, and saves return a structured `change` object alongside bounded
text: operation/target/status, the daemon's explicitly named
`update-revision`, counts-valid state, requested tuple edits, sorted
before/after relation-size observations, and parsed route records. The
distinctions are deliberate: an update revision is not an N2/N3 BoundaryKey,
and a requested add is not claimed as an actual insert. The golden pins that
truth with an existing-fact add whose request is `+1` while relation sizes are
unchanged.

Post-commit observations are best effort and cannot convert a successful
session mutation into a reported command failure. The deterministic contract
harness drives a real session through open, no-op/effective add, delete,
rename, drop, and shutdown, round-trips every result through the actual
Content-Length JSON framing, and compares the plain projection with a checked-
in golden. It is now a named full-suite `repl` harness. No file under `repl/`
changed: the user-facing Rust `--plain` mode remains the next client-side
consumer, not a second Racket frontend.

This checkpoint intentionally stops before three decisions/dependencies:
`stage`/`flush` and `inject` need their command grammar and anchoring syntax
pinned; honest `dbN` handles wait for N2/N3 BoundaryKeys rather than aliasing
the update counter; and, at this checkpoint, Q1 query verbs still waited for
their dispatcher join. The later canonical dispatcher accepts exact
VersionKey payloads without pretending that it supplies N2/N3's persistent
boundary/materialization overlay. T0(c) identity remains an independent engine
track and does not block this client contract.

**Thread-1 checkpoint (2026-07-23; executable plain client join complete).**
The Rust `slog --plain` path branches before Ratatui, raw input, mouse capture,
and the co-author listener. It reads one command per line, drives the existing
authenticated Content-Length backend, renders through the canonical transcript
projection, and updates the typed semantic-change ledger without scraping
human text. EOF shuts down gracefully, server `close` ends the command stream,
diagnostics stay on stderr, and transport loss fails the process.

The executable now drives the same open, no-op/effective add, delete, rename,
drop, and shutdown sequence as the server harness and byte-compares stdout
with the existing semantic-session golden. `CommandResult` is shared with the
canvas, removing its duplicate title/line/kind/close decoding. Gates: Rust
format; 16/16 presentation-model tests; 31/31 canvas/client tests; 3/3
executable tests; Racket REPL contract 18/18. The named full-suite `repl`
harness owns both Racket and Rust legs.

Next on R0/R1: build canvas behavior over this shared result model without
adding display-only state to the compiler contract. Before staging verbs land,
decide buffer ownership across session switches, failure/discard behavior,
flush atomicity, and BoundaryKey anchoring; relation-size summaries are useful
settled evidence but are neither full tuple diffs nor support/provenance
proofs.

**Thread-1 checkpoint (2026-07-23; R1 presentation/navigation foundation).**
`repl/src/present.rs` is the terminal-independent tree engine: separate depth,
total-node, collection-item, and string budgets render stable expandable
markers, and expansion state is keyed by positional paths rather than handles.
The first semantic adapter preserves the server's bounded result lines and
adds a collapsed `it.change` tree from the structured mutation record; it
never scrapes those lines or changes the plain projection.

The newest successful result is the sole live canvas. Tab enters navigate
mode; arrows/hjkl select and expand/collapse; Esc/q returns to the editor.
Every successful gesture appends a dim generated
`expand POSITION`/`collapse POSITION` command, and typed or co-author commands
take the same reducer path without reaching Racket. Older results keep their
last rendered lines. Gates: Rust format and Clippy; 20/20
presentation-model tests; 34/34 canvas/client tests; 3/3 executable tests
including the unchanged semantic-session golden; Racket REPL contract 19/19.

Next R1 slices: cards/actions over selected semantic nodes, then completion,
search, richer schema/value/proof adapters, and pagination. R2 remains at the
separate N2/N3 catalog/VersionKey meeting point.

**Thread-1 checkpoint (2026-07-23; semantic change cards).** Navigate mode's
`o` gesture and the typed/co-author `card POSITION` command now run through
the same client-owned reducer as expansion. A contextual sidebar describes
the selected structured change node and publishes its canonical actions;
`card close` closes it. Collapsing an ancestor also closes a descendant card,
and narrow terminals retain the state while omitting the sidebar.

The first card adapter keeps the evidence boundary explicit: requested tuple
edits are requests whose settled effect is determined by normalization, while
relation sizes are cardinality observations, not tuple diffs or provenance
proofs. No display-only field was added to the Racket result contract, and
plain mode remains byte-identical. Gates: Rust format and Clippy; 21/21
presentation-model tests; 34/34 canvas/client tests; 3/3 executable tests
including the unchanged semantic-session golden; Racket REPL contract 20/20;
named combined `repl` gate PASS.

Next R1 slices: completion, then search, richer schema/value/proof adapters,
and pagination. R2 remains at the separate N2/N3 catalog/VersionKey meeting
point.

**Thread-1 checkpoint (2026-07-23; command completion foundation).**
`repl/src/completion.rs` is a terminal-independent token/candidate reducer.
Tab applies a unique candidate directly or opens a bounded selection panel;
Tab/Down and Shift-Tab/Up cycle, Enter accepts, Esc dismisses, and mouse-wheel
selection uses the same state. Acceptance only changes the editor, leaving the
eventual canonical typed command as the sole semantic action.

The initial inventory covers shipped command verbs, mode/library grammar,
database names learned from structured resident and library records, and
currently valid expand/collapse/card positions. It intentionally refuses to
infer relation or namespace names from the runtime size ledger or saved
relation directories. The selected boundary catalog and embedded-Slog token
stream remain the authoritative inputs for those future candidates; no Racket
contract field was added in this slice. Gates: Rust format and Clippy; 25/25
presentation-model tests; 38/38 canvas/client tests; 3/3 executable tests
including the unchanged semantic-session golden; Racket REPL contract 20/20;
named combined `repl` gate PASS.

Next R1 slices: the boundary-catalog/embedded-Slog completion adapter when its
identity contract lands, plus client-local canvas search, richer
schema/value/proof adapters, and pagination. Search can proceed independently;
R2 remains at the separate N2/N3 catalog/VersionKey meeting point.

**Thread-1 checkpoint (2026-07-23; visible canvas search).** Search lives in
the terminal-independent presentation reducer and visits only the currently
rendered tree after depth, node, item, and string budgets. Navigate-mode `/`
previews a case-insensitive query incrementally; Enter commits and echoes
`search TEXT`, Esc restores the prior query/selection, and n/N echo
`search-next`/`search-previous`. Typed and co-author commands, including
`search-clear`, take the same client-owned path without reaching Racket.
Visible matches are highlighted with an honest current/total status; collapsed
children remain absent until expanded.

No compiler result field or plain projection changed. Gates: Rust format and
Clippy; 26/26 presentation-model tests; 40/40 canvas/client tests; 3/3
executable tests including the unchanged semantic-session golden; Racket REPL
contract 21/21; named combined `repl` gate PASS.

Next R1 slices: richer schema/value/proof presentation adapters and pagination;
the boundary-catalog/embedded-Slog completion adapter joins when its identity
contract lands. R2 remains at the N2/N3 catalog/VersionKey meeting point.

**Thread-1 checkpoint (2026-07-23; live relation observation adapter).**
`tables` already owned current-session relation name, daemon kind/arity,
schema detail, and row count; it now retains those facts in an additive
JSON-safe `relations` field with filter/scope totals instead of discarding
them after formatting. The presentation reducer maps the field to a budgeted
`it.relations` tree. Each relation card offers canonical `count`, `show`, and
`state` actions and states that the current live name has no published
BoundaryKey or VersionKey.

The existing `lines` projection and plain transcript are unchanged. The
completion engine does not consume this field: only the N2/N3 boundary catalog
can supply empty additive members, historical names, and durable identity.
Tuple values remain unstructured until evaluation/boundary TypeDescriptor and
value-handle ownership are fixed; proof trees remain gated by provenance.
Gates: Rust format and Clippy; 27/27 presentation-model tests; 42/42
canvas/client tests; 3/3 executable tests including the unchanged
semantic-session golden; Racket REPL contract 23/23; named combined `repl`
gate PASS.

Next R1 work is pagination where the existing protocol can support it; richer
tuple-value and proof adapters wait on their named identity/provenance
contracts. The boundary-catalog completion adapter joins at N2/N3.

**Thread-1 checkpoint (2026-07-23; buffered canvas pagination).** Wide
presentation collections now retain one item-budget page at a time. Markers
report exact remaining/prior item counts and current/total pages; Enter emits
the absolute `page POSITION NUMBER` command. Typed and co-author commands use
the same client reducer, while completion derives visible targets and valid
page numbers from structured canvas state. Changing pages reselects the first
item, closes an off-page card, and refreshes search so hidden buffered nodes do
not leak into visible results.

This is explicitly not Q1 cursor pagination. It operates only on nodes already
present in a bounded response, including `show REL all` under the current
200-row cap. The server contract gained only the client-command help line;
result fields and plain projection are unchanged. Default `show REL` continues
to advertise `show REL all`; this checkpoint predates the canonical Q1
dispatcher below, so the Rust `more` command is still not connected to that
cursor surface. Gates: Rust format and Clippy; 28/28
presentation-model tests; 44/44 canvas/client tests; 3/3 executable tests
including the unchanged semantic-session golden; Racket REPL contract 24/24;
named combined `repl` gate PASS.

The remaining rich R1 adapters are dependency-bound: tuple values need
evaluation/boundary TypeDescriptor and value-handle ownership, proof trees
need provenance, and catalog completion needs N2/N3 identity. The next
unblocked Thread-1 join is the Q1/R2 dispatcher/catalog meeting point rather
than a display-only imitation of those contracts.

**Thread-1 checkpoint (2026-07-23; canonical Q1 dispatcher).** The generic
daemon command layer now activates `query`, `query-page`, and `query-cancel`
over the frozen ABI-1 QueryPlan. Query start checks the embedded generation,
seals the payload without reserializing it, binds the dense relation frame
only by exact VersionKey, derives idle/boundary/mid-read admission from the
daemon, and returns a structured row stream ending in exactly one
`query-end`. Page and cursor-work budgets are server-bounded; matched counts
are cumulative across page/paused/complete/cancelled sentinels.

The cursor is connection-scoped and holds the database's one-query lease.
While it is live, all non-query commands and arbitrary plugin paths are
refused, so no index mutation can invalidate a continuation; EOF explicitly
releases the lease before database teardown. Completed/cancelled ids are not
retained. The protocol battery pins page/page/complete continuation,
cancellation, exact-VersionKey rejection, stale generation, payload and page
refusals, active-id serialization, mutation interlocks, EOF cleanup, and an
absent-string probe followed by an unchanged row set. The Q1 native hygiene
battery remains the exact master-row/heap/pending-error audit.

This does not manufacture N2/N3 identity. The BoundaryKey is carried through
the canonical payload, while runtime authority remains its exact VersionKey
frame. Friendly `?`/catalog completion, rich TypeDescriptor/value handles,
and `more` integration remain at the real boundary-catalog adapter.

**Thread-1 checkpoint (2026-07-24; N2-A immutable boundary producer).**
The first real N2 catalog slice now lives in `compiler/catalog.rkt`.
Existing type environments normalize into exact qualified declaration graphs
(`TypeRef`, lattice/collection descriptors, union edges, including empty
tables and structs), and one pure planner reconciles those assertions against
an explicit input catalog/environment. Compatible omissions retain their
VersionKeys; new storage receives one initial VersionKey even when written in
the same program; written existing storage receives one successor; new
structs receive TypeKeys; any incompatible overlap or dangling field graph
rejects before a plan is returned. ProgramInstanceKey, BoundaryKey,
VersionKey, and TypeKey slot tables are content-neutral and deterministic by
sorted QName over caller-supplied LayerId/events.

The old `modules.rkt` manifest threading now consumes the catalog's one-way
legacy ABI projection, so `update-manifest` no longer owns a parallel
public kind/arity/lattice encoder. Compiler-reserved `$...` supplementary
relations stay in an execution-only manifest appendix until N1 replaces that
legacy convention with internal IDs/path components; anonymous lattice clamp
names now escape non-QName signs deterministically. The compiler tuple ABI is
intentionally unchanged in this slice. Gates: eight focused planner cases
and all 266 compiler unit tests pass; an extern-backed standard-library load
also passes. Next is N2-B: carry `CatalogDelta` plus each compiled program
group's actual write set through `compile-strata` into session boundary/recipe
state. The N2-A producer deliberately did not advance session state. N2-B
must preserve an explicit seam for N3's daemon prepare/fixpoint/commit overlay
and must not claim that a logical post-fixpoint head alone provides atomic
publication. This work is wholly Thread 1-owned; N1 can later supply lexical
multi-instance paths to the same QName-native planner without rekeying it.

**Thread-1 checkpoint (2026-07-24; N2-B compile/session boundary bridge).**
`compile-strata` now returns one named `compile-group` per dependency-ordered
program instead of an anonymous `(count . frozen-dirs)` pair. Each group owns
its `CatalogDelta`, stratum/frozen actual write set, and the public catalog
storage subset of that write set. The same write-set computation now serves
the one-shot and session drivers; compiler-only `$...` state remains
execution metadata and cannot acquire public catalog identity accidentally.
Declaration-only programs remain first-class groups and therefore receive a
logical program/boundary event even with zero strata.

`session-run!` pure-plans the complete group chain before daemon mutation,
then records a self-auditing plan and exact daemon VersionKey table per group.
The persisted form contains LayerId and program/boundary/type events, complete
normalized deltas, retain/create actions with exact predecessor keys, and the
version/type slot tables. Replay recompiles the source, reconstructs each
plan from the selected input boundary, and rejects any semantic disagreement
between the reconstructed and persisted plan before executing that group.
Recipe grammar validation admits both this form and the prior
version-events-only form.

The session publishes each logical output catalog/environment only after that
group reaches fixpoint. Open reconstructs the head from recipe plans; rename,
drop, import/link, and input injection invalidate it so the next program
re-adopts the live environment rather than extending stale state. The
transition bridge for an older catalog-less root adopts only live storage
reachable through the next program's declaration graph, preserves the exact
current VersionKeys, and refuses a referenced storage type without a live
key. It does not fabricate omitted nominal graphs.

This is deliberately not N3 atomicity. `begin-segment/keyed` still exposes
the legacy daemon boundary while execution is in flight, a declaration-only
initial slot is logical until daemon declaration support exists, and durable
TypeKey/SID descriptors remain absent. N3 next replaces that bridge with
preflighted `prepare-boundary` / fixpoint / `commit-boundary` (or abort) and
direct VersionKey/BoundaryKey indexing. N4 remains responsible for a
checksummed catalog table and restoring empty declarations independently of
recipe source. Gates: 11 focused catalog/compile-group cases, all 269 compiler
unit tests, fresh and catalog-less save/replay probes, and all 605 session
checks.

**Thread-1 checkpoint (2026-07-25; N3-A transactional daemon boundary).**
The T0 command dispatcher now implements generation-checked
`prepare-boundary`, `commit-boundary`, and `abort-boundary`. Prepare validates
the complete output catalog, memberships, retain/create actions, storage ABI,
TypeKeys, predecessor bindings, and VersionKey uniqueness before allocating
anything. It then opens eager initial/successor slots and a plugin-visible
private environment. Declaration-only groups therefore own real empty
physical relations. Ordinary command/catalog/query access is refused while
the private lease exists.

Native strata and frozen inputs execute against that overlay. Commit requires
terminal fixpoint and atomically publishes catalog, name bindings, VersionKey
index entries, and deferred stats before advancing the generation. Abort
settles a mid-read pause to a clean boundary if necessary, removes the private
pipeline suffix and relations, restores the prior cursor/reload state, and
leaves both public keys and content unchanged. VersionIds and SIDs may burn.
The session now sends the same immutable N2 `BoundaryPlan` it persists,
publishes its logical head only after the daemon commit, and issues abort on
every execution or commit failure.

Legacy rename/drop/import/input-version events remain outside boundary
transactions until N3-D. They invalidate both sides' logical snapshot; the
next program re-adopts the live environment, including durable TypeKeys from
`(catalog types)`, rather than synthesizing a second nominal identity.

Gates: daemon and Racket builds, 269 compiler unit tests, 87 command-protocol
checks, and all 606 session checks. Those gates opened N3-B's durable
boundary/history work.

**Thread-1 checkpoint (2026-07-25; N3-B boundary identity and history).**
Every N3 commit now installs one immutable `BoundarySnapshot` under its
BoundaryKey, records that key on each created `RelBinding`, and appends it to
evaluation-local commit history. The snapshot owns the complete public
storage environment plus catalog and program identity; historical relations
therefore resolve directly without reconstructing a name map from
`pipeline_pos`. Positions remain the fast ordering labels used by maintenance.
Committed keys are unique, aborted keys are reusable, and legacy
rename/drop/import/stratum events clear only the selected current handle while
conservatively retained history stays addressable.

`(catalog boundaries)` streams commit-order handles and
`(catalog boundary "KEY")` streams the exact historical relation
materialization. Current and historical relation records carry BoundaryKey,
and pipeline identity records attach it to committed binding events. Q1 now
rejects an unknown BoundaryKey or a QName/VersionKey pair that does not match
the selected snapshot; it no longer accepts a decorative boundary beside a
globally resolved VersionKey. The REPL tables adapter consumes the structured
catalog and publishes the real BoundaryKey/VersionKey pair to relation cards.

**Thread-1 checkpoint (2026-07-25; N3-C durable type identity).**
Name-discovered `structs_by_id` and the monotone high-water allocator are
gone. Each evaluation now owns pointer-stable `TypeDescriptor`s under direct
SID and TypeKey indices plus a lowest-free occupancy bitmap. Sparse root loads
reserve only their actual SIDs; successors and renames retain one descriptor;
drop removes only the current name projection; redeclaration receives a fresh
TypeKey/SID; and history-only or aborted slots remain conservatively occupied.

Prepared struct storage lives in a private SID overlay. Commit atomically
advances canonical descriptor storage and publishes new TypeKeys; abort
deletes the physical overlay without publishing its TypeKey. `(catalog types)`
enumerates descriptors independently of the latest map and reports `(name
#f)` for an unnamed retained type. Value rendering resolves SID through the
descriptor, uses the selected BoundaryKey's constructor name/storage for
historical queries, and emits an explicit `<type TypeKey>` form when no
current name exists.

Focused gates add 62 struct-identity checks and seven protocol lifecycle
checks (102 command-protocol checks total), including sparse SIDs 10/3 with
fresh allocations 1/2/4 and an aborted SID burn. N3-D is next: teach lookup,
sizes, batch, rename, drop, and version-chain actions structured qualified
paths and make subtree environment operations atomic.

Full exit gates are green: the optimized daemon build, 269 compiler unit
tests, 62 struct-identity checks, 102 command-protocol checks, 24 Racket REPL
contract checks, 28 Rust library tests, 44 Rust client tests, three executable
semantic integrations, the native/interpreter operator gate, and all 608
session checks.

**Checkpoint (2026-07-26; N3-D qualified-path transforms — N3 complete).**
Landed on the reunified trunk in four sub-slices after the thread-1 merge.
`rename-path`/`drop-path` are single-shot atomic environment events in the
T0 dispatcher over ONE structured path syntax: the current environment and
catalog decide leaf vs namespace (never both), the whole selected subtree
rebinds or unbinds at one pipeline position, and the event publishes a
successor BoundarySnapshot under a session-planned BoundaryKey with the
generation advancing while counts stay valid. The session's pure planner
(`plan-path-transform`) rewrites declaration names, nominal TypeRefs into
the subtree — including field types declared outside it — membership edges,
nominal TypeKey keys, and environment VersionKey keys, preserving every
key's value; drop applies §5.3's conservative referential-integrity
rejection (field graph session-side, memberships re-checked by the daemon).
The logical head is TRANSFORMED in lockstep instead of invalidated: the
next program retains exact VersionKeys, recipes carry the self-auditing
`(transform-plan ...)` datum, and replay recomputes it and refuses key
divergence. Anchored batches translate through subtree renames leaf-by-leaf
(per-leaf rename triples derived from the plan's environments by VersionKey
match); catalog streams take a structured subtree filter (`(catalog
relations (qname ...))`); Q1 binds old names at their historical boundaries
under the same VersionKey and refuses them at successors; struct SID/
TypeKey survive renames; keys freed by aborted prepares are reusable.

Two latent thread-1 seams surfaced and were fixed: prepare-boundary's
declaration/action parsers required singleton qname fields (multi-component
qualified declarations could not be spelled at all), and `advancePosition`
cleared the daemon's complete catalog on EVERY non-transactional boundary
event — any flush/walk rebind silently destroyed catalog identity, invisible
until the transforms became the first consumer to compare against it.
Declarations are version-independent: content events now clear only the
current boundary handle, and only genuinely catalog-invalidating legacy
events (imports, links, injected input versions, catalog-less rename/drop)
clear catalog truth, matching the session's head-invalidation policy.

Legacy single-relation env ops remain for catalog-less roots. Deliberately
out of scope, per the docs: §5.3 attach/import-at-path and save/inspect
bundles (N4 persistence), the N1 module system, and privacy/export lists.

Exit gates: daemon -O2 build; 275 compiler unit tests (7 new transform
planner cases); 127/127 command-protocol checks (25 new: transform atomicity
and refusals, subtree filters, Q1 history coherence, TypeKey survival);
struct-identity battery; Racket REPL contract 24/24; Rust 28+44+3 with the
unchanged semantic golden; session battery 703/703 (namespace rename/
consume/drop, anchored-batch translation, chained transforms with a closed
count walk and IR oracle).

**Checkpoint (2026-07-28; R2 slice (a) — the query spine).** The `?`
register is live end to end over the shipped Q1 substrate: `?`/`?count`/
`?exists` with conjunctive bodies, `/=`-and-comparison guards, the audited
compute whitelist, snapshot negation, `->` projection, and `explain ?...`
plan-without-run rendering. The grammar lives in `compiler/query-front.rkt`
as a pure text-to-request translator (symbols are variables exactly as in
rule bodies, `_` is fresh per occurrence, a fully ground rows query answers
existence); `repl.rkt` projects the committed logical head plus the daemon's
materialization facts into the planner's snapshot, keys it by display name,
plans with `query-plan.rkt`, and drives the canonical dispatcher through the
new `session-query-lines!` raw channel. The missing catalog link closed on
the daemon side: `Relation::fullOrders()` (seeded-order policy mirrors
`getAnyIndex`) and an additive `(orders ((0 1) ...))` field on
`catalog-rel` records now report the materialized full-index orders the
planner may schedule over (t0-contract.md updated; field-tagged readers
unaffected).

The one-query lease is respected by construction: v1 fetches at most one
page (200 rows) or drains count/exists through paused work slices under a
budget, then cancels — no cursor survives a command, so `more` integration
remains open. Value handles do not yet splice into queries (`#N` refuses
with a hint); the single-atom sugar substitutes answers back into the fact
template. A bare `(fact ...)` line now errors with the two-way add/query
hint (repl-ux §5.1).

Gates: daemon build; unit 404 (query-front battery + planner suite);
protocol 132/132 (orders pin added); Racket REPL contract 67/67 including a
live scratch-session battery — rows/count/exists/explain, typed refusals,
and a query at the fresh epoch after a flushed tip edit; Rust 29+44+3 with
the semantic golden byte-identical. Remaining for R2: `uses`/`find`, `dump`,
query watches, handle splicing, Q1-cursor pagination (`more`), and client
completion/canvas adapters for query results.

**Checkpoint (2026-07-28; R2 slice (b) — held cursors, cell replies, dump).**
Ratified direction: large query responses yield a REAL cursor the REPL pulls
or throws away, and the daemon's query replies are structured, never bare
strings. Query rows now stream as value-adapter CELL records — the
`dump-cells` shape: word, kind, sid, TypeKey, boundary-aware text — with the
preview cut at an optional `(depth N)` render budget on `query`/`query-page`
(a cut subtree prints `...`; the cell's word lets the client ask deeper).
The budget rides `writeValCSVAtBoundary` as a parameter beside the existing
4096 overflow guard. The REPL pulls pages of 50 at preview depth 4, mints
checked `#N` handles for compound cells exactly as `show` does, substitutes
answers into the single-atom fact template, and HOLDS the connection's one
cursor when rows remain: `more` continues with continuous numbering,
`cancel` discards, and any command that needs the daemon discards the
cursor first (the daemon refuses every other verb while its cursor lives,
so a held cursor never blocks the next thought — new `?` queries included).
`dump ?QUERY to PATH.csv` pulls 1000-row pages to completion and writes
CSV (variable-name header, standard quoting) client-side; the relation
fast-path via the daemon's own CSV facilities remains open. count/exists
still drain to exactness. Fixed in passing: `show #N` parsed its argument
with the Racket reader before checking for a handle label, so the
documented verb could never fire.

Gates: daemon -O2 build; unit 404; protocol 134/134 (cells shape + depth
grammar pins; query-check.rkt reads cells); Racket REPL contract 77/77 —
new live battery over tests/chain12.slog covering page/more/complete
numbering, third-`more` refusal, cancel, auto-discard before `count`, the
depth-4 preview cut with `#1` minted from a query row, `show #1`, and a
66-row CSV dump; Rust 29+44+3, semantic golden byte-identical; session
battery at slice end. Remaining for R2: `#N` splice via preload words,
`uses`/`find` daemon verbs, query watches (after REPL watch integration),
deep re-describe for cut previews, and client completion/canvas adapters.

**Checkpoint (2026-07-28; R2 slice (c) — `#N` splices as preload words).**
A value handle now splices into any query term position and the front end
translates it seamlessly: the REPL's query reader owns `#`+digits as a
dispatch macro (the language grammar is untouched — repl-ux §14.2
resolved), the token resolves through the checked handle table
(database, evaluation, and constructor identity re-verified before
planning), and the planner lowers the new `word` literal kind to a wire
PRELOAD — the register starts holding the exact encoded word, no interner
probe involved, so the splice is read-only by construction and works for
every value kind including the structs and collections no typed wire
literal could spell. Word literals type as `any`; the daemon needed no
changes (preloads were already decoded). Equality on a spliced word is
interned-value identity, exactly the semantics joins use.

Gates: unit 406 (resolver/readtable/preload-wire cases); protocol
134/134; Racket REPL contract 79/79 — the chain12 battery now splices the
minted `#1` back in, both as a ground existence query and through an eq
guard that re-yields its row; Rust suites green; session battery at slice
end. NOTE an intermittent protocol-battery flake (~1-in-4 runs, one
unnamed check, self-heals on rerun) — RESOLVED in slice (d): it was
`run-replay-setup` scraping stratum .so paths from a fixture run log that
T3a's cold start can complete interpreted; the fixture is now pinned
`SLOG_OPT=0`. Any test scraping .so paths from a run log must pin the
regime.

**Checkpoint (2026-07-28; R2 slice (d) — `show #N` iterates deeper).**
Ratified: `show` always gives a deeper view than the handle has, so
iterating it pulls in an arbitrary tree one preview-depth step at a time.
The daemon gains the read-only `(describe-value WORD [(depth N)])` verb —
re-render one evaluation-local word as a bare cell record;
`canDescribeWord` refuses unrecognized encodings, dead SIDs, and absent
struct instances as `value-lookup` instead of tripping the renderer's
fatals (interned ids are trusted exactly as every other reader trusts
them: the handle table only holds words this evaluation emitted). Handles
now record the depth their stored text was rendered at (#f = complete);
minting the same word deeper upgrades the stored cell in place, `show #N`
re-describes at stored+4 and keeps the cut/complete state, a completed
text skips the daemon round trip, and a still-cut preview prints a
dig-further hint.

Same slice, **watches at the prompt** (the R2 query-watch item over the
07-27 level-0 daemon substrate). `watch REL` binds a daemon watch to the
relation's exact current VersionKey and the REPL keeps the INTENT: at
every semantic barrier it rebinds against successor keys (noting rebinds,
suspending on drops — the daemon never follows names). `watch ?QUERY` is
the client-side re-run: the query re-counts at each barrier and the delta
reports. Both speak through the change summary — in-run hits arrive as
watch-cause pause records in the captured event stream (the driver
auto-continues them) and aggregate to ONE heartbeat line per watch
("watch w1: 13 hits, last at ..._maint1 iter 12"), never a ledger of
every round. `watches` lists intents; `unwatch wN` removes one.
Deliberately deferred: interactive pause-on-hit (`break`, the paused
prompt, paused-mode queries) is R4's debugger surface, and registration
against PREPARED keys (so a watch fires inside the run that creates the
successor version) needs a session.rkt prepare-hook — today a relation
watch fires on in-place propagation (flushes, maintenance epochs), which
is exactly the joint battery's item 4.

Same slice, the other ratified daemon verb: **value search**. `(uses
(word W))` / `(uses (string|integer|real "TEXT"))` walks every latest
non-temporary relation's master index once and reports nonzero counts of
rows containing the value in any column — `(uses-rel (name ..)
(version-key ..) (count ..))` records, name-sorted, then `(uses-end
(relations N) (rows TOTAL))`. Typed literals share Q1's probe-only
`resolve_literal` (now declared in query.h), so a value the interner has
never seen honestly appears nowhere; words validate like
`describe-value`. The REPL's `uses #N | uses VALUE` (alias `find`)
renders the dream-session line: relation counts plus a total. Also fixed
here: the protocol battery's intermittent `run-replay-setup` flake —
section 8 scrapes stratum .so paths from a fixture run log that T3a's
tiered cold start can complete interpreted on a cold cache; the fixture
run is now pinned `SLOG_OPT=0`, verified cold 136/136.

**Checkpoint (2026-07-29; R3 slice (a) — the scratch register).** The
third syntactic register is live: a line whose head token is a Slog
definition keyword (`rule table struct union enum lattice demand extern
def let`) is a scratch fragment — one dispatched line/paste is one
program event (immediate-with-coalescing, repl-ux §14.1 resolved), run
through the ordinary boundary machinery with two twists.  It compiles
INTERP-ONLY (`opt-mode-override` beats `SLOG_OPT` for exactly that
compile: the canonical plan is the runnable artifact, no toolchain, live
in one round trip), and it ADOPTS the live schema it reads: modules.rkt's
`current-catalog-adoption` seeds the root type env from the input
catalog's declarations for used-but-undeclared names, dependency-closed
(a 5-deep struct match pulls `l5..l1` along) — the
tests/session/consumer.slog declare-what-you-read convention synthesized
from the N3-C typed catalog instead of typed by hand.  Defined heads
still declare explicitly, exactly as in a file.  Source-composition
directives (`include`/`instantiate`/`import`/`export`) refuse with a
run-a-file hint.  The session ledger (`session-scratch-add!/events/
keep!`) marks which tip events are the retractable layer; `scratch`
lists fragments; `keep scratch as F.slog` exports the program and
promotes its events to ordinary history (re-keep into the same file
allowed, unrelated overwrite refused).  Fragments ride the full
substrate: scratch-over-scratch adoption, edits propagating through
scratch cones in one maintenance epoch (`edge +1 ⇒ hop2 +1 · hop4 +1 ·
route maintain 3`), query/watch visibility at the committed head, and —
after fixing a real replay gap found by the save smoke — save/load, with
adoption on for every replayed recipe compile (a self-describing
program's adoption set is empty, so its plans recompute byte-identically;
the scratch segment path under `build/scratch/<layer>/` is only a
source-override key).  Reloaded scratch arrives as ordinary baked
history (ledger is session-local; the persistence question is slice
(d)'s).  Gates: unit 406, REPL contract 108 (two new live batteries:
reach-cycle scratch spine incl. the undeclared-head hint, chain12
struct-adoption + save/replay), protocol 139/139, Rust golden 29+44+3,
golden 167 (chain12 finally got the expected/ dir R2 forgot to mint),
session battery at slice end.  The plan-determinism gate ran for the
first time since RF1 slice 0 and re-surfaced a PRE-EXISTING tie-group
defect (verify.slog's twin demand rules flip their rid↔temp pairing;
reproduced on a pristine checkout; logged in rf1-contract.md with the
fix direction — not this slice's to fix); filename sets and every other
plan byte-identical.  Remaining R3: `clear scratch` retraction over
clear-and-rerun (slice b), tier visibility `tiers`/`code` + arrival
notes (slice c), save×scratch policy + goldens (slice d).

**Checkpoint (2026-07-30; R3 slice (b) — `clear scratch`).**  The layer
retracts wholesale: its strata leave `strata-info` (the client drives all
propagation, so a forgotten stratum never re-enters; the daemon's
pipeline entries persist, inert), pending edits aimed at its relations
are discarded with it, and the names it INTRODUCED drop through the
ordinary planned transforms — dependents before their dependencies
(reverse-topological over the catalog's named field references, so a
fresh table dies before the fresh struct its column cites).  The recipe
stays replay-honest by construction: the run steps remain, the drops
append, and a reloaded save replays create → fill → drop (pinned in the
battery).  Two typed refusals guard that honesty: a later non-scratch
program event reading a scratch relation (dropping under a compiled
reader), and — the deliberate v1 cut — a layer that EXTENDED a
pre-existing relation via an adopted head: its derived rows have no
recipe spelling for retraction, so replay would re-derive them and the
load-time signature would refuse the divergence; the refusal names the
relation and points at `keep scratch`.  The live-state recompute for
that case was built and works (writers+downstream-cone clear-and-rerun
over the surviving strata — `session-rerun!` cannot serve: its anchor is
the relation's last binding, i.e. the scratch boundary itself, and its
wave misses non-recursive writers) but ships only together with its
recipe event, a design the save/load walkthrough forced.  Also fixed
here, found by the save smoke: scratch segment FILE ordinals were
ledger-relative and reset at keep/clear, aliasing distinct fragments
under one source-override key — the replay plan validation refused
exactly as designed; ordinals are now session-monotonic (directory
count).  Gates: unit 406, REPL contract 117 (clear battery: dependency-
ordered drops, extended refusal, create→fill→drop replay round-trip),
protocol 139/139, Rust 29+44+3, session battery at slice end.

**Checkpoint (2026-07-30; R3 slice (c) — tier visibility).**  `tiers`
renders the session's per-stratum execution rungs — scc id, content
hash, current rung, and which rungs the build cache holds — and `code
sN|HASHPREFIX` opens one stratum's card (rung, cached artifacts, and the
canonical plan's shape: flavor, abi, relation/rule-variant counts,
dynamic set, rule sources).  Both are observations over client state
plus the build cache, no daemon round trip, cursor-preserving.  The
substrate: `sinfo` gained the stratum's content hash and a tier box;
`push-sbuild!` seeds the box from the runnable's tag and wraps the T3a
upgrade closure so every in-place artifact swap advances the box and
echoes one `(tier SCC HASH RUNG)` event — change summaries render those
as §5.4's arrival notes ("tiers: s3 -> -O0 arrived").  The two upgrade
shapes disambiguate by initial tag (a cold start's make-native-upgrade
counts absolute rungs; a warm -O0 start's make-upgrade counts linked
clusters, partial = "-O2 (partial)").  One truth the verb immediately
surfaces: a stratum whose fixpoint beats clang stays on its starting
rung for its maintenance lifetime (mid-run swap is the only shipped
pickup point — the cache rows show the built-but-unused artifacts), so
next-re-entry artifact pickup is explicitly future T3b policy work, now
visible instead of latent.  Live arrival notes are timing-dependent by
nature, so the rendering is pinned at the unit level and the verbs under
forced interp.  Gates: unit 406, REPL contract 123, protocol 139/139,
Rust 29+44+3, session battery at slice end.

**Checkpoint (2026-07-30; R3 slice (d) — save×scratch policy + goldens;
R3 SERVER-SIDE COMPLETE).**  Until the layer is kept, `save NAME`
refuses while scratch is live, naming the three ways out — `keep scratch
as F.slog` promotes, `clear scratch` retracts, `save NAME with scratch`
bakes it as ordinary history (exactly what a reload yields) — the
server-side form of §5.3's "save asks"; an interactive client renders
the refusal as a prompt.  Second policy pinned here, forced by the
golden regeneration: **scratch is catalog-era only** — over a legacy
(pre-N4, catalog-less) input the register refuses with the catalog
verb's own message, because adoption reads the typed catalog and the
fresh/extended split IS a catalog diff: a fragment's first boundary over
such a database would mint every live relation as "introduced" and a
later clear would drop real data.  The byte-exact semantic-session
golden gained the refusal stanza (additive diff only).  Gates: unit 406,
REPL contract 125, protocol 139/139, Rust 29+44+3, session battery at
slice end.  **R3's server side is done** — with R0–R2 banked, thread 1's
gate-S local exits (R0–R3 batteries, Q1 hygiene, catalog round-trip) are
all closed; what remains before S is the JOINT battery (§5), plus the
non-gating leftovers: R2's Rust client adapters / prepare-time watch
registration / relation fast-path dump, R3's extended-layer clear recipe
event, and T3b's next-re-entry artifact pickup.

### 4.3 Why the fork is safe

Three structural facts, not optimism: the interpreter partitions (monotone
frozen at F; counted = thread 0; query = thread 1, in separate files and
registration tables); thread 1's semantic foundation (Phase 0
forward-incrementality) shipped months of hardening ago and thread 0's work
is additive flavored paths beside it; and the protocol freezes at F except
for additive verbs. The known shared hotspots get explicit zones (§7).

## 5. S — the sync gate

Thread-local exits: M4N and M7 audits plus the counted-interpreter gate
(thread 0); R0–R3 golden batteries, Q1 hygiene, catalog round-trip
(thread 1). The gate itself is the **joint intersection battery** — each
item is a capability neither thread can prove alone:

*Status 2026-07-19:* thread 0 has banked the counted-interpreter gate
(all four slices, exit audit in incremental-status.md) — M4N and M7
audits remain.  Thread 1 has banked Q1 slices 1–5 and T0 slice (a);
R0–R3 and the catalog round-trip remain, gated first on T0 (b)/(d).
The post-merge shape (W4′ debugger/T4/N4/RF2, W5′ capstone) is
unchanged; item 2 of the joint battery (scratch over counted state)
got materially easier — counted sidecars are now maintained by the
same executor the scratch layer's views run on.

*Status 2026-07-30 — **GATE S CLOSED**.*  Both threads' local exits were
already banked (thread 0: counted-interpreter + M4N + M7 audits; thread
1: R0–R3 batteries, Q1 hygiene, catalog round-trip).  The joint
intersection battery now exists as `tests/joint-battery.sh` (run-all's
`joint` tier, 21 checks; commits 727e1a1 + 216710f) and each item below
points at its proof:
item 1 → tests/joint/repl-workflow.rkt (staged edits via the new
`stage`/`flush` verbs, visible pending then ONE epoch; delete cone
through the closure; `recount [force]` + `counts REL`
sidecar-vs-forced-rebuild equality; save/load replay — the REPL is a
permanent second driver harness);
item 2 → tests/joint/scratch-counted.rkt (a scratch view over counted
state; the delete routes through the scratch stratum on counted flavors;
sidecar equality WITH scratch resident and again after `clear scratch`);
item 3 → tests/joint/quiescence.rkt (a query issued FROM a parked
barrier of a counted delete epoch via the new `session-pause-hook` —
R4's future stepping seam — is admitted and answers committed masters;
lease/stale-generation/prepared-boundary refusals stay pinned in the
protocol battery; the write/intern refusal class is documented
unreachable from this dispatcher by design, slogd.cpp query_admission);
item 4 → pinned in both drivers (watch heartbeats at `maint4neg`
barriers, truthful counted status in the change summaries);
item 5 → the union sweep under `SLOG_OPT=interp`: golden 167/167,
protocol 139/139, REPL contract 125, session 782/782, joint 21/21.
One operational lesson worth keeping: bare epochs never pause — the
daemon parks FOR CAUSE (a watch) or on budget, so parked-state tests
must register a watch first.  Post-merge bearings unchanged: W4′ = T5
level-1 debugging with REPL R4 as its UX, plus T4 parameterized native
bundles, RF2 mount, and T3b tier policy (now with `tiers` making the
pickup gap visible).  Standing non-gating leftovers: R2's Rust client
adapters / prepare-time watch registration / relation fast-path dump,
R3's extended-layer clear recipe event, and the wandering-recount flake
hunt (three strikes, always near count rounds, always rerun-green).

1. **The REPL drives the incremental battery.** The session workflow
   harness re-expressed as REPL transcripts: edits, flushes, recounts,
   maintenance epochs, save/load — all through the shell. The REPL becomes
   a permanent second driver harness (dogfooding as testing).
2. **Scratch over counted state:** scratch rules atop a counted database
   route correctly; `clear scratch` retraction lands on precise routes
   where admissible and fallback elsewhere; sidecars match forced recounts
   afterward.
3. **Quiescence enforcement:** queries admitted at every legal pause class
   and *refused* against mid-flight maintenance epochs (decisions 6/15),
   each refusal driven by a test.
4. **Level-0 watches during maintenance epochs** fire at coherent barriers
   with truthful counted status in change summaries.
5. `SLOG_OPT=interp` green over the union of both threads' batteries.

## 6. Post-merge

**W4′ — the debugger and the durable substrate.** **T5** level-1 debugging
(interpreted policy, `RUN_READ_COMPLETE`, `WatchSettle` — struct case per
m5-contract, lattice per M6L contributor-reduce; monotone-only enforcement
now testable against real M4N/M7 exclusions) with **REPL R4** (stepping,
frames, why/why-not, commit/replay) as its UX. In parallel: **T4**
parameterized native bundles (the alpha-normalized KernelPlanKey gate goes
live over N1 instantiation), **N4's two slices**
([n4-contract.md](n4-contract.md): N4-A versioned META boundary bundle,
empty-declaration restore, replay audit, and catalog-backed REPL; then N4-B
atomic mapped namespace attachment with explicit TypeKey/SID remapping),
**RF2** image mount via
freeze/import with image-based compiler goldens and a first Slog-written
lint, **T3b** full tier policy (promotion budgets, profile sidecars, core
arbiter).

**Checkpoint (2026-08-02; T5 slices (d4)+(d5) — the non-plain settles and
the exit audit.  THE W4′ DEBUGGER ARC IS COMPLETE).**  (d4) finishes the
gate: the question "does this change genuinely appear?" is the same for
every storage kind, but the identity that answers it is not.  A STRUCT head
stages content with a 0 id placeholder — the id is minted in the intern
phase — so its settle asks M5's intern-identity question of the content,
and the master ordering is content-first precisely so that probe is a
prefix.  A LATTICE contribution settles through M6L's contributor-reduce:
`BTreeMapIndex::wouldChange` is `merge` with a lookup where merge inserts —
same clamp, same join, no mutation — so a contribution the resident payload
already subsumes is not a change however new its row looks.  The lattice
case is also the clearest argument that membership was never the right
question: contributing a worse cost adds a row and changes nothing, while
contributing a better one changes the database without moving its size.
One bug nearly shipped and is worth remembering: `getAnyIndex()` is right
for a plain table and WRONG for the other two, because a struct carries an
id-first ordering beside its content-first master, and probing that one
reads the 0 placeholder — so every construction, new or not, looked like a
change.  `settleOrder()` now picks by kind, and the battery asserts each
settle in BOTH directions, which is what caught it: a settle that only ever
says yes is a park on every write, not a settle.  With every kind settling,
the last silent downgrade goes too — registration reports `(settleable #f)`
when a level-1 binding has no full index to preview against (an empty
declared table still settles, so the field names the safety net rather than
the norm).  (d5) is the exit audit, and its artifact is
`tests/joint/t5-monotone-matrix.rkt`: §0.1's monotone-only pin crossed in
ONE run rather than five scattered per-slice controls — over a counted
maintenance epoch the gate never engages while the level-0 report still
arrives, `replay` and `step` both refuse `level-1-unwatchable` naming the
epoch's flavor, a refused continuation still commits its change, capture
stays empty and `why` says which silence that is, and a standing break
never fires; then the same session over a monotone epoch does all of it.
Gates: protocol 172, REPL 241, joint 32, plus the full suite and the
interp union sweep.  W4′ still holds T4 (parameterized native bundles),
RF2 mount and T3b tier policy; R5 (`whatif`) is W5′.

**Checkpoint (2026-08-02; T5 slices (d3)+(d2) — the pre-run entry and the
failure frontier).**  Two slices, opposite in shape: one closes a hole the
arc had left open, the other answers the debugger's other half without
touching the daemon at all.

**(d3) `break`** is the entry path stepping lacked.  A step needs an
existing park, so before this every port (c3) built required a level-1
watch to trip the gate first -- you had to know which relation would move
before you could watch anything move.  A break is a STANDING arm where a
step is one-shot: it materializes the same `StepStop` (so `frames`, `why`
and `step` at the stop need no new machinery), and instead of disarming it
goes QUIET until the resume clears the stop, which is what lets it fire
again.  Three filters over state the earlier slices already produce: a head
relation matched at the emit port through (d1)'s `ProofSchema` names, a
rule matched at the `fire` port, and a body position matched at the probe
port whose cursor slot is that position.  repl-ux §9.1's `when` lands as a
head PATTERN, not a binding predicate -- conditions over `X` need the
source variable names still blocked inside the KernelPlanKey.  A relation
break pins that relation's writer strata to the interpreter and says so: a
native stratum has no ports to stop at.  A session with a break armed holds
its commands on the (c2) thread exactly as a level-1 watch does.

**(d2) `whynot`** deviates from execution-tiers §7.5 deliberately, and the
contract records why: the frontier is a PLAN-DIRECTED PROBE over committed
state rather than a captured iteration.  §7.5's scope needs the target
known while the read runs -- but "why is this not here?" is asked
afterwards, usually with nothing armed.  The canonical `.plan` the client
already reads for `code` IS the rule set, so the probe unifies the target
with each head that can produce its relation, rebuilds that rule's atoms in
plan order (inverting each ordering exactly as (d1)'s capture does),
and probes prefixes through the ordinary `?count` spine until one is empty.
Over reach.slog, `whynot (path 1 5)` answers: the base rule dies at
`(edge 1 5)`, and the recursive rule gets three ways through `(path 1 V)`
before dying at `(edge V 5)`.  Zero daemon changes.  Honest edges are
printed, not smoothed: the question's premise is checked first (a present
fact is answered as present, pointing at `why`), a head that cannot unify
never probes, a computed position ends that rule's walk, and delta views
probe as full views because the question is about the state that exists
now.  Gates for both: protocol 170, REPL 234, pause 18, joint 21, unit 406,
interp, Rust 29+44+3, session 782/782.  Remaining in the arc: (d4) struct
and lattice settles, (d5) hygiene + exit audit.

**Checkpoint (2026-08-01; T5 slice (d1) — provenance capture and `why`).**
The last slice of the debugger arc opens with its proof surface, and the
mechanism was again already there: the interpreter's `emit` port and
`DebugView::proof()`.  What (d1) adds is a place to put the answer and a
way to ask.  Capture is OPT-IN PER WATCH (`watch REL level 1 why` →
`(watch ... (provenance #t))`, additive and echoed only when true),
because an armed gate alone leaves the event mask at 0 and the fast loop
selected; paying the observed loop on every gate run to answer a question
nobody asked is precisely the cost dishonesty execution-tiers §7.4 warns
about.  The journal is event-scoped and bounded both ways (records per
event, derivations per fact, the omitted count reported), keyed by
(relation, tuple) in NOMINAL order — cursors hand back PHYSICAL index
rows, so a per-rule `ProofSchema` built at bind time labels each level and
inverts its ordering inside the callback, where the plan is still in hand.
Three spellings: bare `why` at a gate park explains the CANDIDATES that
stopped the run (the settle now retains them, bounded — the one thing no
query can name, since they live in the send shards); `why (path 1 4)` goes
through the query front end, so `#N` handles splice as they do in a query
and there is no second grammar for naming a tuple; `depth N` deepens the
tree.  Four things the choreography settled: the driving row is a premise
NODE (a rule whose only body position is its driver would otherwise prove
nothing, and a delta-driven recursive chain would break at every step);
monotone-only is enforced at the PLAN (`counted || maint` ⇒ uncapturable,
since a flavored set head stages a signed contribution and journalling it
would call a deletion's bookkeeping a proof); "one semantic event" needed
BOTH event doors, `prepareBoundary` and `beginUpdateEpoch`, because an
`add` prepares no boundary and would otherwise answer with the previous
event's tree; and the two silences — nothing armed, versus armed over an
epoch capture does not cover — are told apart in the refusal.  A replayed
read discards its own records before rerunning, so slice (c1)'s exactness
holds here too.  Gates: protocol 160, REPL 207, pause 18, joint 21, unit
406, interp, Rust 29+44+3.  Remaining in the arc: (d2) `whynot`, (d3)
`break` (the missing pre-run entry path into the ports), (d4) struct and
lattice settles, (d5) hygiene + exit audit.

**Checkpoint (2026-08-01; T5 slice (c) — replay, the gate as a place,
and stepping).**  Three parts, all over the substrate the earlier slices
built.  **(c1) replay** (commit 7dddec0): `replay` leaves reserved-verb
parking through the T0 dispatcher, and at a gate park discards every
relation's send shards, rolls the iteration's `$stat_fires` tallies back
to a snapshot taken at the iteration barrier (armed sessions only),
re-arms `once_pending[phase_read]` — runPhase's completed-read tail had
already cleared it, so without this the rerun would be a SMALLER read —
and re-enters at `RUN_MID_READ`, which is precisely "the read phase
again, without the iteration barrier or the write phase".  The old delta
and its indices never moved, so the rerun is exact and re-parks with an
indistinguishable record; struct ids are minted in the INTERN phase, so a
discarded read leaks no identity.  `replayObstacle` orders refusals
FLAVOR FIRST, which is where `level-1-unwatchable` finally fires (its
ratified surface: a level-1-only continuation against a counted or
maintenance epoch, naming that epoch's retained flavor).  **(c2) the gate
as a place** (7dddec0): a session with a level-1 watch armed runs its
commands on a held thread, so a gate park comes back as the command's
RESULT, ordinary commands then observe the parked epoch, and
`commit`/`replay`/`abort` resolve it — `commit` returning the held
command's own summary, `abort` raising an `exn:fail` subtype so the
session's existing abort-boundary unwind discards the change with no
second path.  repl-ux §9.2's "the pause is simply a place", literally.
**(c3) stepping**: the interpreter already owned the mechanism (interp.h's
eight D15 ports, `DebugSink` with a per-event mask, post-transition
`DebugAction::pause`, `DebugView`'s cursor stack, `StopReason::
breakpoint`), so this is a translation layer — a `StepSink` mapping the
operator's granularity to a mask, plain step state on Database, a stop
that parks its continuation exactly as a budget pause does and comes out
as an ordinary `RUN_MID_READ` park with a `breakpoint` cause.  Cost stays
honest: a disarmed session's mask is 0, which selects the machine's
separately compiled fast loop.  From the gate a step REPLAYS the
completed read and stops at the first matching port — walking the very
read that produced the candidate — and the lease widens by exactly one
park so queries and `frames` work there.  Two pieces deliberately left:
frames print the join stack structurally, because source VARIABLE names
need the canonical plan's rule-meta to carry a register-to-name map and
every byte of that plan text is the KernelPlanKey; and `up`/`down` are a
cursor over a stack the server already prints whole (the Rust canvas's
job).  Remaining in the arc: slice (d) — why/whynot proof trees,
struct/lattice settles, the exit audit.

**Checkpoint (2026-07-31; T5 slices (a)+(b) — the pre-commit gate
works).**  Slice (a), commit 7edfe7a: level-1 watch registration as an
additive `(level 0|1)` wire field (level-0 replies byte-identical) and
the per-SCC interpreter pin — `watch REL level 1` pins the relation's
writer strata client-side, every re-entry send resolves the canonical
plan, and the native→interp flip is battery-proven with zero daemon
changes.  Slice (b), commit 0e51337: `RUN_READ_COMPLETE` parks a
level-1-watched run at read-complete before the deferred finalize;
`WatchSettle` scans the send shards and probes master absence over ANY
full ordering (plain tables hold no id-last master — the first draft's
gate silently never fired); the uniform pause record carries phase
`read` + the watch citations with zero grammar changes; plain
`(continue)` commits, and committed content is byte-equal to an
unwatched run.  Two contract additions flagged for review in
t5-contract §4(b): prepare-time watch registration (the R2 leftover,
load-bearing — semantic runs write successor instances, so the gate is
unreachable without binding the prepared key through the private
overlay, with watch verbs exempt from the boundary lease) and
gate-park lease reads (`query*`/`catalog` admitted under the lease only
at the park, where everything they touch is committed truth).  The
`level-1-unwatchable` refusal rides to slice (c) with `replay`, its
first reachable surface; the §7.3 downgrade is meanwhile behavioral and
battery-pinned (maintenance epochs never gate; level-1 hits stay at
iteration barriers).  Gates at (b): protocol 145/145, REPL contract
140, unit 406, pause 18/18, joint 21/21, Rust 29+44+3, golden 167/167,
session 782/782.  Remaining: slice (c) replay + the interactive pause
state over `session-pause-hook` + four-port stepping + the refusal;
slice (d) why/whynot + struct/lattice settles + exit audit.

**Checkpoint (2026-07-31; W4′ entry).**  Two arc-entry items done.  (1)
The wandering crash flake open since the N3 merge is root-caused and
fixed (db6b57f): the `sha` package's `_bytes` RETURN conversion scans
past every 32-byte digest for a NUL terminator — ~88% of calls overread
the heap, a page-edge hit was the SIGSEGV; `compiler/sha256.rkt` binds
libcrypto correctly (digest via the sized output argument, returned
pointer dropped), byte-identical digests so no cache churn; 40-iteration
soak of the three strike cases, 0 strikes.  N4 landed pre-gate-S, so
this wave's parallel track is T4/RF2/T3b.  (2)
[t5-contract.md](t5-contract.md) DRAFTED (pending review): monotone-only
pins with structured `level-1-unwatchable` refusals, the one-pause-record
rule, settle/apply factoring (struct settle co-designed with the SHIPPED
M5 split), interpreter-first with the native→interp flip riding T3a's
swap seam in reverse, reserved-verb activation, and four slices —
(a) policy/registration/refusals, (b) the pre-commit gate with
plain-table WatchSettle, (c) replay + stepping over gate S's
session-pause-hook seam, (d) proof surfaces + non-plain settles + exit
audit.

**W5′ — the capstone.** **T6** transactional mid-read restart; **N5 + stats
steps 5–7**; **RF5** draft images and activation wired to writer/cone
healing per [rf5-contract.md](rf5-contract.md) — the point where the two long
arcs merge and a program or instantiated-module replacement becomes a recipe
event healed like a fact edit; **derived watches**
(slog-reflection.md §18.5) as the flagship meta-program; **REPL R5**
(`whatif` cones over the maintenance machinery).

Capstone gate, stated as a demo: at the REPL, edit one rule of a large
loaded analysis; watch the successor image seal, activate, and heal
incrementally with counts valid and struct ids stable; run `whynot` on the
same fact before and after.

### W5′ two-arc implementation plan (ratified 2026-08-08)

W5′ is implemented as two parallel arcs with one deliberate integration
tail.  The split is by authority, not by UI feature:

```text
runtime / transaction arc                 program / reflection arc
-------------------------                 ------------------------
T3b carry-in                              RF1.5 model queries
T0(c) durable rule/SCC identity           RF2 sealed image mount
T6 read restart/publication               RF3/RF4 image-path closure
N5 and stats identity migration           RF5-A drafts/diffs/lineage
private build/recount/persistence          read-only R5/whatif surface
                    \                     /
                     \                   /
                      RF5-B activation join
                   rebuild -> audit -> preview
                        -> commit or abort
                                |
                derived watches + integrated R5
                                |
                           W5′ exit demo
```

The **runtime / transaction arc** owns the mechanics of changing a live
recipe-bearing database safely.  Its pre-join result must be able to accept a
fully specified synthetic program change, build a private successor cone,
recount and audit it, preserve or replace the correct durable identities,
and atomically publish or abort it.  T6 supplies the one read-consistency
mechanism: a reader pinned to an old boundary remains pinned, while a
latest-following read attempt that crosses publication restarts.  T0(c), N5,
and stats steps 5–7 belong here because durable rule/SCC identity, internal
namespaces, keyed fire data, and valid count epochs are properties of the
candidate transaction rather than compiler-diff policy.  T3b is the W4′
carry-in at the head of this arc.  This arc does not infer source or module
correspondence.

The **program / reflection arc** owns deciding and describing what the new
program means.  RF1.5 provides normalized queries and fingerprints over
`ProgramModel`; RF2 mounts sealed images read-only; the remaining RF3/RF4
closure proves that image-described interpreted/native kernels and attachment
observations match execution; and RF5-A produces immutable drafts, the three
compiler diffs, explicit occurrence and relation-slot lineage, affected roots,
and the union old/new dependency cone.  Read-only `preview`/`whatif` and REPL
navigation may be built against these products.  Before the join this arc
does not install tasks, allocate live `VersionKey`s, replay a recipe suffix,
or mutate a database.

The arcs exchange a frozen, serializable **`ProgramChangeSet`** fixture.  The
program arc produces at least:

- the base program/image identity and the sealed candidate image;
- old/new module and rule occurrence lineage, with fresh candidate slots;
- proposed semantic relation-slot correspondence;
- source/occurrence, normalized-semantic, and execution-plan diffs;
- old/new writer sets and SCC condensation graphs, affected writer roots, and
  the union-graph cone; and
- required services, compiler/Plan-ABI identities, and typed refusals already
  knowable without live database state.

The runtime/session side validates that product against the named base
boundary and enriches it into an **`ActivationPlan`**: allocated successor
`VersionKey`s, accepted slot lineage, mapped recipe-suffix events, selected
maintenance routes or the mandatory fresh-cone fallback, invalidated count
epochs, and the publication/restart decision.  Compiler code remains the
authority for semantic/SCC differences; the session remains the authority
for recipe and version lineage; the daemon remains the authority for private
materialization, recount, and publication.  Golden `ProgramChangeSet`s let
the runtime arc proceed before the compiler producer is finished, and a
synthetic consumer lets the program arc prove serialization and diagnostics
without a daemon.  The first joint battery runs the exact golden products
through both sides so the fixture cannot become a parallel informal ABI.

W5′ collision ownership is therefore:

| surface | W5′ owner before RF5-B |
|---|---|
| `ProgramModel` queries, image schema/container, compiler diffs and lineage | program arc |
| RF1.5/RF2/RF5-A goldens and synthetic change-set producer | program arc |
| T0(c) registration, counts/stats, maintenance routes, recount, T6 | runtime arc |
| database candidate construction and atomic publication | runtime arc |
| `ProgramChangeSet` schema and golden corpus | frozen interface; joint review |
| native emission/descriptor attach and final plan-diff baselines | frozen until T4 lands; then joint review |
| recipe/version resolution in `session.rkt` and RF5-B command semantics | join work; runtime authority |
| read-only REPL browsing/preview rendering | program arc; command grammar changes reviewed jointly |

**Start rule.**  Both full arcs may start in parallel from the named, clean
integration commit containing all T4 slices and gates.  The program arc may
start **before that commit lands**, from the latest common RF1/Plan-ABI-2
baseline, because RF1.5, the RF2 container/query layer, and most of RF5-A do
not consume native attachment machinery.  During that early start it should:

1. prefer new compiler/reflection modules plus golden fixtures over edits to
   central lowering or emission files;
2. avoid `emit-cpp.rkt`, native descriptor attachment, `daemon.h`,
   `plan-count.cpp`, and T4's TU/determinism gates while the T4 checkout is
   under validation;
3. delay final execution-plan-diff goldens, RF4 artifact-catalog wiring, and
   daemon mount integration until it has merged or rebased onto the T4 landing
   commit; and
4. use candidate slots and abstract identities so RF5-A does not take a
   compile-time dependency on unfinished T0(c) compact-id registration.

T0(c)'s isolated identity fixtures may also be prepared early, but T6 and any
native task/publication changes wait for the T4 landing point; beginning those
against the checkout being vetted would create high-conflict work in the same
daemon and attachment surfaces for little scheduling gain.

Use two Git branches/worktrees, `w5-runtime` and `w5-program`, rather than two
copies with unrecorded state.  The early program worktree starts at a known
committed common ancestor, never by copying the dirty T4 validation tree.  As
soon as T4 lands, merge or rebase that single landing commit into
`w5-program`, create `w5-runtime` at the landing commit, and freeze the first
`ProgramChangeSet` golden.  Thereafter integrate small vertical slices at the
fixture boundary; changes to the interchange schema, command grammar,
`session.rkt`, or shared daemon/catalog files require joint review.  This
keeps T4 validation reproducible and limits the later merge to intentional
RF5-B wiring rather than overlapping speculative implementations.

The required W5′ join is **RF5-B**, not all of RF5.  After the join, finish
the real R5 commands, derived watches, save/reload and abort coverage, count
and struct-identity audits, and the capstone demo.  RF5-C's capability-by-
capability precise healing is an optimization over RF5-B's permanent fresh-
cone oracle; RF5-D historical descendant-branch replacement is later scope.
Neither is required to declare this W5′ gate closed.

## 7. Ownership zones and collision watchlist

During the fork, shared code has named owners; the other thread touches a
zone only through joint review.

The table below records the earlier pre-S thread-0/thread-1 fork.  It is kept
as historical ownership evidence and does not rename or override the W5′
arc ownership table above.

| zone | owner |
|---|---|
| interpreter core: dispatch, vocabulary, cursor layer | frozen at F; joint review |
| flavored ops, `counts.h` folds, maintenance sinks, route admission, recount | thread 0 |
| `QueryContext`, query drivers/sinks, probe-only interner entries, pagination | thread 1 |
| `session.rkt`: routing/maintenance/recount paths | thread 0 |
| `session.rkt`: catalog/boundary planner, handles, alias tables | thread 1 |
| `database.h`: versions, sidecars, maintained mutation verbs | thread 0 |
| `database.h`: declaration/boundary application, `TypeDescriptor` registry | thread 1 |
| interim evaluation-local VersionKey→VersionId map (T0; subsumed by N3 indexing) | thread 1 |
| command protocol grammar | frozen at F; additive verbs only, joint review |
| `emit-cpp.rkt` | dormant between the W1 ABI split and T4 (P4) |

Cache keys: W1 re-keys plans once (ABI split); T4 re-buckets shards once.
No other re-key events are scheduled; do not add one casually.

## 8. Elasticity and the fallback

If effort turns out to be serialized rather than concurrent, the diamond
degrades gracefully to the original wave sequence (trunk, then thread 0's
content as wave 3, then thread 1's as wave 3½) — the fork is optionality,
not an obligation to staff two fronts. If one thread finishes early:
thread 1 pulls N4 persistence or RF2 introspection forward; thread 0 pulls
T3b policy or T4 forward. The sync gate's joint battery is fixed either
way.

## 9. Parked — do not start

Portable cursor handoff (tiers §8.3); whole-fixpoint why-not;
counted-sidecar preview/apply (post-M7, if ever); direct plan editing; the
automatic outer meta-fixpoint; self-hosted compiler passes; session
branching/fork; module type parameters; privacy/export lists; lifecycle
monitors. Each is recorded in its stream document; none blocks anything
above.
