# Cross-stream roadmap: modules, tiers, reflection, REPL, incremental

2026-07-14. **Working plan, revised same day into a diamond:** a shared trunk
builds the keel and the interpreter, then development forks into two
concurrent threads — thread 0 (full incrementality, deep vetting) and
thread 1 (the REPL on forward incrementality) — and re-joins at an explicit
sync gate before level-1 debugging and the capstone work. Five design
streams are mature enough to collide unless sequenced deliberately; this
document owns ordering and interleaving only. Each stream's own document
remains normative for its content.

| stream | document | slices | status 2026-07-14 |
|---|---|---|---|
| incremental maintenance | [incremental.md](incremental.md), [incremental-status.md](incremental-status.md) | Phase 0, M0–M7 | Phase 0, M0, M1, M3, M6L 1–2, M4T, M5 slice 1 shipped; queue **M4S → M4N → M7** |
| execution tiers | [execution-tiers.md](execution-tiers.md) | T0–T6, Q1 | T1 shipped; T0/T2+ unstarted |
| modules/namespaces | [modules.md](modules.md) | N0–N5 | design complete, unstarted |
| reflection | [slog-reflection.md](slog-reflection.md) | RF0–RF5 | brainstorm + §18 staging verdict |
| REPL | [repl.md](repl.md), [repl-ux.md](repl-ux.md), [repl-terminal.md](repl-terminal.md) | R0–R5 | native Rust shell, private TCP server, and live session/daemon vertical slice working; semantic catalogs/handles remain |
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
`abort-boundary`) are the same protocol. T0 reserves the verb space; N3
joins it later. After the fork, protocol changes are additive verbs only,
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
        W4': T5 + REPL R4 (the debugger) · T4 · N4 · RF2 · T3b
        W5': T6 · N5 + stats 5–7 · RF5 program edits · R5 · derived watches
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

### W2 — the engine

**T2** decoded interpreter: cursor erasure including `Join3PrefixCursor`,
the full §4.1 vocabulary including `letp`/`cjoin`, task factories into
`slogd`, short slices, suspension; every task records
`(plan_key, variant_slot, pc)` from day one. **T3a** cold-start slice only:
install/seal plans before clang, interpret immediately, `SLOG_OPT=interp`.
**Stats steps 1+4**: `$stat_fires` rekeys to `(RuleId, VariantTag)`.
**N1** lexical module instances (compiler track, parallel): `instantiate`,
occurrence trees, qualification pass, real `ModuleInstanceKey`s.

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

- **Counted interpreter admissibility** (execution-tiers §4.3): the
  interpreter enumerates the exact instantiation multiset for `_count` and
  maintenance flavors, drives the shared `cnt_*` folds, and respects
  counted-plan attributes (no semijoin re-optimization). Gate: fires
  multiset equality plus maintained-sidecar equality with forced recounts,
  across the whole existing incremental battery under `SLOG_OPT=interp`.
- **M4N — precise stratified negation:** anti-delta variants and pre/post
  transition scheduling, implemented as interpreter variants (P4); exit
  audit in the established style.
- **M7 — recursive lattice/rank repair**, likewise interpreter-first.
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

Deferred on this thread until after S: level-1 anything (provenance watches,
stepping, why/why-not), `whatif`, fork/branching vocabulary beyond reserved
words.

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
live over N1 instantiation), **N4** persistence (catalogs in META, namespace
import maps, empty-declaration restore), **RF2** image mount via
freeze/import with image-based compiler goldens and a first Slog-written
lint, **T3b** full tier policy (promotion budgets, profile sidecars, core
arbiter).

**W5′ — the capstone.** **T6** transactional mid-read restart; **N5 + stats
steps 5–7**; **RF5** draft images and activation wired to writer/cone
healing — the point where the two long arcs merge and a program edit becomes
a recipe event healed like a fact edit; **derived watches**
(slog-reflection.md §18.5) as the flagship meta-program; **REPL R5**
(`whatif` cones over the maintenance machinery).

Capstone gate, stated as a demo: at the REPL, edit one rule of a large
loaded analysis; watch the successor image seal, activate, and heal
incrementally with counts valid and struct ids stable; run `whynot` on the
same fact before and after.

## 7. Ownership zones and collision watchlist

During the fork, shared code has named owners; the other thread touches a
zone only through joint review.

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
