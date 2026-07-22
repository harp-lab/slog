# Cross-stream roadmap: modules, tiers, reflection, REPL, incremental

2026-07-14. **Working plan, revised same day into a diamond:** a shared trunk
builds the keel and the interpreter, then development forks into two
concurrent threads — thread 0 (full incrementality, deep vetting) and
thread 1 (the REPL on forward incrementality) — and re-joins at an explicit
sync gate before level-1 debugging and the capstone work. Five design
streams are mature enough to collide unless sequenced deliberately; this
document owns ordering and interleaving only. Each stream's own document
remains normative for its content.

| stream | document | slices | status 2026-07-19 (v3.0.1) |
|---|---|---|---|
| incremental maintenance | [incremental.md](incremental.md), [incremental-status.md](incremental-status.md) | Phase 0, M0–M7 | Phase 0, M0, M1, M3, M6L 1–2, M4T, M5, M4S shipped; **counted-interpreter milestone complete** ([counted-interp-contract.md](counted-interp-contract.md), all 4 slices); queue **M4N ([m4n-contract.md](m4n-contract.md)) → M7** |
| execution tiers | [execution-tiers.md](execution-tiers.md) | T0–T6, Q1 | T1 shipped; T2 core frozen, monotone conformance groups closed, **flavored execution interp-only by default**; T0 slice (a) landed; T3a/T4+ unstarted |
| modules/namespaces | [modules.md](modules.md) | N0–N5 | N0 landed; N1+ unstarted |
| reflection | [slog-reflection.md](slog-reflection.md) | RF0–RF5 | RF0 done; RF1 slice 0 shipped (plan determinism); ABI-2 split pending |
| REPL | [repl.md](repl.md), [repl-ux.md](repl-ux.md), [repl-terminal.md](repl-terminal.md) | R0–R5 | native Rust shell, private TCP server, and live session/daemon vertical slice working; R0 waits on T0 (b)/(d) |
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
3. **Synchronize the UX work at that seam (next)**, resolve only genuine overlaps,
   and run the joint intersection battery before beginning coupled client
   changes.
4. **R0 → R1 on the shipped substrate**: session ownership, semantic
   verbs over `session-*!`, change summaries, golden `--plain`
   transcripts; then the canvas.  Nothing here waits on thread 0 —
   forward incrementality and the frozen monotone interpreter are the
   foundation, and `clear scratch` silently improves as thread 0's
   precise routes land (M4N just widened them to negation cones).
5. **The Q1/R2 meeting point**: T0's dispatcher takes ownership of
   `query`/`query-page`/`query-cancel` admission, N2/N3 supply the
   boundary/materialization overlay, and the already-golden
   payload/builder seam connects — then R2's `?`/`?count`/`?exists`
   and `explain` land as rendering over it.
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

The next thread-1 move is now the planned UX synchronization: merge at this
command seam, reconcile only the dispatcher/session call sites that genuinely
overlap, and run the joint protocol + plain-transcript intersection before
starting coupled R0 work. After that, keep T0(c) identity (`rule-meta`, stable
keys, per-attempt fire vectors) separate from UX rendering, and connect Q1's
already-golden query payload only when the N2/N3 catalog overlay supplies real
VersionKey-boundary state.

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
