# T0 command protocol and identity substrate contract

**Status:** design contract (2026-07-15); sidecar parse/seal half of slice (b)
implemented 2026-07-16; Q1's canonical payload decoder and typed builder
boundary implemented 2026-07-17; slice (a)'s dual-stack dispatcher and
catalog verbs implemented 2026-07-18; slice (d)'s uniform pause record and
slice (b)'s checked `EntryMode` state machine/legacy forwarding shims
implemented 2026-07-20. Generic command builders, resident-count tier-policy
admission, and identity remain.
`execution-tiers.md` §9/§9.1/§11-T0/§12 and `execution-tiers-impl.md`
(decisions D6, D9, D10, D16, D17; findings 6 and 8; the §5 daemon
change map) remain normative; this file pins the dual-stack dispatcher,
the byte-compatibility guarantee, the verb inventory and reservations,
explicit entry modes, the parse/seal surface T2 meets, persistent
RuleKey/SccInstanceKey construction, and level-0 watches. The
convention follows `m4s-contract.md` and `m5-contract.md`: everything
not explicitly changed keeps its current behavior, and no shipped
parser breaks. All decisions below were ratified 2026-07-15 alongside
the progressive fork (roadmap.md §3.1) — do not reopen them. T0 is W1
daemon work (roadmap §3); its slices gate REPL R0–R1 and unblock
T2-A2's sidecar parsing.

## One protocol, two stacks

Line-framed S-expressions per D6: one `write`-printed form per line
over the existing line framing, no length prefixes until a measured
need exists. The dispatcher rule is a one-character route: **a line
beginning `(` goes to the command parser; anything else stays a plugin
path.** This lands in the stdin loop (`slogd.cpp:144-157`) and,
byte-identically, in its TCP twin (`slogd.cpp:225-246`) — the two
transports share one dispatch function after this change, not two
copies. The literal special cases `(continue)` / `(continue-boundary)`
(`slogd.cpp:152-155`, `slogd.cpp:241-244`) are already `(`-prefixed
lines; they become the command layer's first two verbs with identical
replies, so the dual-stack formalizes what those literals started.

This is the **same protocol** N3's transactional boundary requests
join later (roadmap P3): T0 reserves the verb space, N3 adds its verbs
into it, and there is never a second command channel. After the fork
gate F the grammar is frozen except for additive verbs under joint
review (roadmap §7, zone "command protocol grammar").

Two protocol-wide rules from execution-tiers §9, restated as contract:
connection loss before a `*-seal` discards the provisional object; and
pause/continue/epoch verbs carry the unified generation token
(execution-tiers §2.2 — PauseToken and UpdateEpochId are one
mechanism), so a stale client is refused before any mutation. The
token field is in the wire shapes from day one even while the backing
store is a single daemon generation counter.

## Reply and refusal doctrine

Every command answers with exactly one structured reply, or a record
stream ending in a sentinel (the existing `(schema-rel ...)*` +
`(schema-end)` convention). Replies are s-expression records keyed by
**VersionKey / TypeKey / RuleKey**; friendly names and ordinals may
ride along as display metadata but no payload requires string parsing
(F criterion 4; repl.md §7's "the REPL must not split mangled
strings"). The daemon resolves `(EvaluationId, VersionKey) ->
VersionId/Relation*` for the current evaluation; durable direct
VersionKey indexing remains N3's item (modules.md §10 N3.2) and T0's
map must be additive under it.

Refusals are typed: `(refused <class> <generation> <detail>...)`, one
class per failure family — `parse`, `unknown-verb`, `reserved-verb`
(distinct from unknown, so clients can distinguish "not yet" from
"never"), `builder-state`, `plan-io` / `parse-limit`, each D16 seal class
(below), `entry-mode`, `stale-generation`, `suspended`, and the capability
refusals (tier swap/restart against `resident-count`). **Every refusal class
is driven by a test** — F
criterion 2 verbatim; a refusal without a test does not exist.

**Byte-compat guarantee (finding 8).** Every reply currently parsed by
`runslog.rkt`'s driver loop, `session.rkt`, and `tests/pause-tests.sh`
— most critically the 8-field `(paused ...)` and the `(fixpoint ...)`
shapes (`daemon.h:1121-1139`) — remains **byte-compatible** until the
driver migrates verb-by-verb (execution-tiers §9.2: each compiled
action retires only together with its driver-loop counterpart, in the
same change). Appendix A enumerates the frozen shapes with their
consumers. New structured replies are new verbs' replies; they never
restyle an existing one in place.

## Verb inventory and reservations

Initial families (spellings follow the execution-tiers §9 sketch; the
sketch is the working set, this contract is where a rename must land):

- **plan/builder:** `rule-meta`, `rule-def`, `scc-begin` /
  `scc-add-rule` / `scc-seal`, `stratum-begin (entry ...)` /
  `stratum-add-scc` / `stratum-seal`, `load` (tier/attachment).
  Provisional until sealed; acknowledged or refused structurally.
- **entry/run:** `installStratum` entry modes (next section),
  `continue`, `continue-boundary`, generation-checked pause/resume.
- **catalog introspection** (repl.md §7): version/type/pipeline/catalog
  records keyed by VersionKey/TypeKey, sufficient for REPL name
  resolution and completion. The existing `(schema)` action describes
  nonempty materialization and is explicitly not the catalog API.
- **watch management (reserved for now):** `subscribe`, `watch`,
  `unwatch` — repl.md §6's spellings, ratified 2026-07-15 (the
  execution-tiers §9 sketch's `watch-add`/`watch-remove` are
  superseded). Watches are NOT implemented in T0 (ratified same day):
  the verbs answer `reserved-verb`, and slice (d) tees up the pause
  machinery they will ride post-fork.
- **stats access:** fires/fixpoint/size reads, keyed by
  `(RuleId, VariantTag)` once rule-meta registration exists.
- **one-at-a-time equivalents of existing compiled action verbs**
  (lookup, sizes, dumps, saves, ...), retired per §9.2.

**Active post-T0 families:** N3-A owns `prepare-boundary`,
`commit-boundary`, and `abort-boundary`; Q1 owns `query`, `query-page`, and
`query-cancel`. They extend this dispatcher and generation/refusal doctrine;
neither is a second protocol path.

**Reserved verb families** — the parser recognizes these remaining verbs and
answers `(refused reserved-verb ...)`:

- **watch:** `subscribe` (`watch`/`unwatch` are live as of T5 slice (a)).
- **T5:** the debugger verbs still parked (`resume`, `why-not-add`,
  `debug-on`/`debug-off` per the §9 sketch).  `replay` LEFT this parking in
  T5 slice (c): at a pre-commit gate park it reruns the read from its
  origin, and everywhere else it refuses structurally
  (`level-1-unwatchable` naming the epoch flavor, or `replay-unavailable`
  naming the park position) -- through this dispatcher, no second grammar.

The active Q1 and N3 families followed the recorded 2026-07-16 dependency:
their wire verbs activate only through slice (a)'s generic dispatcher and
dispatcher-owned phase observation, never another exact-string branch in the
legacy plugin-path switch.

Post-F rule: additive verbs only, joint review (roadmap §7).

## Entry modes

Per D10, one `installStratum(entry_mode)` unifies today's pair and the
hot-swap side effect:

- **`fresh`** — the deferred `reloadInsertBatches` ordering exactly as
  `beginStratum` (`daemon.h:200-244`); the reload-before-re-registration
  invariant moves into one checked installation path instead of being a
  property of generated code.
- **`resident-delta` / `resident-count`** — the positional bind with
  **no reload** exactly as `beginStratumDelta` (`daemon.h:293-315`);
  `resident-count` carries `(at <pipeline-pos>)` and binds against the
  recorded historical environment (incremental.md §4.2: a historical
  stratum is always recounted at its original environment).
- **`upgrade`** — an explicit attachment replacing the name-match
  hot-swap side effect inside `beginStratum` (`daemon.h:204-224`);
  swappability (suspended, same stratum, `RUN_AT_BOUNDARY`) becomes
  validation, not string luck.

Seal/install-time validation enforces the combinations
(execution-tiers §9.1): `resident-*` never reloads; tier swaps and
restarts against `resident-count` are refused (gate 12.13); `upgrade`
against a non-suspended or mid-read state is refused. The legacy C++
entries remain as forwarding shims for the path-protocol stack
(compiled plugins call them today) with replies unchanged; the
accidental name-match firewall they relied on is retired by the
explicit attribute.

**As built 2026-07-21.** `daemon.h` has one read-only entry admission path and
one transition path behind the public `installStratum` overloads. The explicit
path validates entry attributes before reload/bind mutation, checks the
generation token, requires an in-range `resident-count (at P)`, and admits
`upgrade` only for the named live stratum at `RUN_AT_BOUNDARY`.
`beginStratum`/`beginStratumDelta` forward through it while retaining their
exact legacy refusal bytes and former name-matched hot-swap behavior.

The command half is now active as a connection-scoped builder store. ABI 1's
bridge consumes one already-canonical sidecar per SCC:

```text
(scc-begin S (generation G) (kernel-plan (sidecar "PATH.plan")))
(scc-seal S (generation G))
(stratum-begin ST (generation G) (entry fresh))
(stratum-add-scc ST S (generation G))
(stratum-seal ST (generation G))
```

Fields on the two begin forms are keyed (order-independent); ids are protocol
symbols. Every mutation answers `(accepted <verb> <generation> ...)` or one
typed refusal. `scc-seal` runs the production bounded parse/D16 seal and maps
its exact error class. `stratum-seal` revalidates generation and live entry
state, preflights every database-dependent binding without mutation, installs
and pushes exactly one sealed SCC, then acknowledges without continuing; the
client owns the subsequent `(continue)`. A connection drop destroys all
unsealed SCCs and strata. Sealed SCCs are reusable within that connection.
ABI 1 refuses a multi-SCC stratum as `capability`; T0(c)'s future
`rule-meta`/`rule-def` assembly becomes another SCC plan source without changing
the stratum lifecycle. Entry/flavor admission is explicit: normal =
fresh/upgrade, delta and maintenance = resident-delta, count = resident-count.
Any count plan requested as fresh/upgrade, or any non-count plan requested as
resident-count, is the pinned count restart/tier-swap `capability` refusal.

`tests/interp-operator-tests.cpp` drives runtime entry states plus command
entry/flavor policy and no-auto-continue. `tests/protocol-tests.sh` drives the
whole begin/seal/begin/add/seal/continue/catalog workflow over stdin and TCP,
all five stale-generation gates, connection-loss discard, builder state,
plan-I/O/D16 mapping, and count-tier refusal. This completes T0(b) without
touching `repl/`. Exit gates: interpreter operator pass, protocol 67/67,
pause 18/18, session 528/528, and cache-cleared `SLOG_OPT=interp` golden
165/165.

## Builders and seal: the T2 meeting point

`daemon/plan.h` (new) owns parse and seal. Plans — T1's `.plan`
sidecars, re-emitted on a cache miss since stale caches predate them —
parse into **immutable decoded objects**, then seal against the daemon
capability table per D16: register bounds and dataflow, relation
slot/arity/ordering ABI and index requisition, bound-prefix
availability, head coverage, RuleVariant uniqueness (the D3 ordinal —
a seal error, not an assumption), and **per-`(operator, A, K, view)`
factory coverage** — a syntactically valid plan must never discover a
factory-ladder miss on a worker thread. Factory ladders are
instantiated once in the daemon-owned `plan.cpp` TU beside the shared
out-of-line `runtime.cpp` index ladders (D12); driver
partition classes stay distinct per D17 (delta-scan round-robin
buckets, partial-probe first-free-column hash, fully-bound single
task) and the seal records which applies. Every seal failure is a
structured refusal in its own class.

**This is where T0 and T2 meet, explicitly:** T0 owns the parse/seal
surface; T2 binds and executes through the **same** decoded/sealed
in-memory interface (execution-tiers §11 T2.4; impl §7 T2-A2 already
lays those interfaces in `plan.h` from the C++ side and asks to "parse
at least one real T1 `.plan` sidecar into this path as soon as the T0
S-expression reader exists"). Neither stream waits on the other's
schedule: T2-A constructs decoded objects in C++ until slice (b) lands,
then parses.

**As built 2026-07-16 (slice (b), sidecar half only):**
`daemon/sexp.h`/`sexp.cpp` provide the reusable bounded reader (16 MiB input,
1M S-expression nodes, depth 256 for sidecars), and `plan.cpp` owns the ABI-1
decoder. The future command dispatcher consumes this same reader with its own
limits rather than growing a second grammar. Relation schemas, constants, rule/source
metadata, and unsupported canonical forms are decoded before seal;
constants stay storage-neutral until materialization. Parse errors carry
syntax/limit/I/O subtype and byte offset. Seal errors carry the D16 family
needed by the command refusal layer: ABI/flavor, capability, register
bounds/dataflow, relation slot/kind/arity, constant slot,
ordering/requisition, bound prefix, head coverage, RuleVariant identity,
factory, and binding. The standard service-struct prelude remains in the
binding schema, but only operator-referenced set slots must resolve, so an
unused service relation cannot make a normal-set kernel unbindable.

`tests/data/t0-normal-set.plan` is byte-identical compiler output and now runs
through parse → seal → selective bind → `InterpReadTask`; the parsed refusal
battery is in `tests/interp-operator-tests.cpp`. A separate audit parsed all
857 sidecars then present across `build/` and `build-post2/`. Entry modes are
not included in this checkpoint, so slice (b) as a whole is not yet complete.

**Q1 meeting seam as built 2026-07-17 and activated 2026-07-23:**
`compiler/query-plan.rkt` emits a
canonical ABI-1 `query-plan` datum carrying its BoundaryKey/generation and
exact VersionKey catalog frame. `daemon/query.cpp` parses it with the shared
bounded reader, seals it into `SealedRequest`, and builds the runtime relation
frame by VersionKey rather than QName. The checked-in cross-language fixture
executes through this path. The dispatcher now embeds that datum unchanged in
`(query ID QUERY_PLAN (page N) [(depth N)])`, checks generation/phase, and owns
`query-page`/`query-cancel` plus the connection-scoped cursor lifetime; rows
stream as value-adapter cell records with previews cut at the optional render
depth, and `(describe-value WORD [(depth N)])` re-renders one
evaluation-local word deeper on demand (execution-tiers.md §6.4). A live
cursor refuses all non-query commands and plugin paths, preventing mutation
between pages. This is exact-VersionKey admission for canonical clients, not
authority to resolve friendly names: persistent BoundaryKey/catalog
production remains N2/N3's responsibility.

**ABI coordination (RF1):** the sidecar format is ABI 1 today;
rf1-contract.md's re-key splits it into ABI 2's four parts. Slice (b)
parses whichever ABI is current when it lands — the `abi` field and
re-emit-on-miss make the switch mechanical — but the *decoded object*
shape targets ABI 2 from day one (exec content, binding schema, and
cohort facts held separately), so the RF1 re-key changes the parser's
front matter, not the sealed interface T2 binds against.

## Persistent identity and rule-meta

`RuleKey` and `SccInstanceKey` are constructed on the **shipped M0.4a
Layer/Event/Slot substrate** (incremental.md §0.4: content-neutral
LayerId, event ids local to the layer, slot tables assigned once and
stored in the recipe — never name hashes, source text, or pipeline
position), the same construction modules.md §6.4 gives VersionKey and
BoundaryKey. RuleKey composes a ProgramInstanceKey with a **degenerate
module-occurrence component — the root include tree as the single
lexical occurrence —** plus the lexical rule occurrence slot, defined
so N1's real `ModuleInstanceKey`s later fill that component **without a
rekey** (roadmap P2). This resolves execution-tiers §13.1's open
RuleKey construction. Semantic SCC identity separates from the
pipeline ordinal (execution-tiers §2.2); compact RuleId / RelationId /
SccId stay evaluation-local and never appear inside compiled artifacts.

**Daemon-side rule-meta registration** — the piece T1 explicitly
deferred (impl §0: "the daemon cannot resolve RuleIds until T0's
rule-meta registration") — lands here: RuleId↔RuleKey, display names,
and **module-relative source locations** (finding 6: repo-relative
paths only; an absolute path in a RuleKey or golden plan is a bug by
definition). This registration is what enables the W2 `$stat_fires`
rekey to `(RuleId, VariantTag)` (roadmap W2, stats steps 1+4; emit-cpp
phase A per impl §5).

**Per-attempt fire vectors (D9) land in slice (c) of this contract,
not T2** — D9 says "T1/T2, a prerequisite made cheap", T1 shipped
without it, so it lands here: dense RuleVariant ordinals turn
`bumpFires`' locked string-keyed map (`database.h:3942-3960`) into a
plain per-attempt `std::vector<u64>` merged into the durable table at
read commit. The string-keyed entry point remains as a shim resolving
through rule-meta until the W2 call-site rekey; T2's interpreter tasks
use the vectors natively from day one, and the vector discard is
T6's `ReadAttempt` semantics arriving early for free.

## Level-0 watches

repl.md §6's design, adopted verbatim (execution-tiers §7.1 adopts it
unchanged): relation size and per-iteration added/removed counts,
exact-tuple appearance/disappearance, and iteration/stratum/program
events, evaluated only at coherent barriers where the finalized delta
already exists — under **any** executor including O2. **Explicitly no
interpreter dependency.** Verbs: `subscribe`, `watch`, `unwatch`, plus
the existing continue family. **Implementation status (ratified
2026-07-15): deferred past T0** — T0 ships the reserved verbs and the
uniform pause record below; the watch machinery itself is co-developed
post-fork alongside the REPL, riding this contract's seams.

Contract points, all from repl.md §6:

- watches address an exact VersionKey/VersionId; the daemon never
  follows latest names (the client re-resolves QName intents);
- all hits at one barrier aggregate into **one** pause reply carrying a
  structured watch-reason payload with truthful status (which barrier,
  which watches, sizes/deltas); watches are edge-triggered per barrier,
  so `continue` cannot re-return the identical pause;
- a hit at the terminal program barrier pauses **before** the boundary
  commits; `continue` commits, `abort` discards — a breaking watch
  leaves a prepared boundary, never a half-committed one;
- notification versus breakpoint is entirely client policy; the daemon
  has one mechanism and no unsolicited messages;
- watches are session state: never in the compile hash, catalog,
  recipe, or replay.

**The uniform pause record (ratified 2026-07-15).** The command stack
gets ONE structured pause record for every pause, present and future:
a pause may be *arbitrary* (budget expiry, boundary, suspension) or
*for cause*, citing its cause in a structured payload — a watch hit, a
breakpoint, an error-watch — with truthful status either way (which
barrier, what settled, sizes/deltas). There are not two pause shapes
on the command stack, ever; watches later add a cause variant, not a
message kind. Byte-compat holds because the record is scoped by
*protocol stack*: sessions speaking the command protocol receive the
uniform record from day one; path-protocol sessions keep the 8-field
`(paused ...)` bytes until the driver migrates (Appendix A). Golden
transcripts in `--plain` (repl-ux.md §11 R0) are the exit format.
Level-0 watch UX expectations (repl-ux.md §9.1: notify lines, `break`
into paused mode, honest cost lines) will consume this record
post-fork without extending its shape — that forward-compatibility is
exactly what slice (d) must demonstrate with a cause-variant
validator, since the REPL and interpreter co-develop against it after
the fork.

## Slices

- **(a) dispatcher dual-stack + structured replies + read-only catalog
  verbs.** One dispatch function for stdin and TCP; parse/unknown/
  reserved refusals; catalog records keyed by VersionKey/TypeKey.
  Tests: new `tests/protocol-tests.sh` (routing, refusal classes, TCP
  twin parity, catalog round-trip) plus the existing session workflow
  harness driven **through the command protocol** dual-stack; all
  Appendix A consumers untouched and green.

  *As built (2026-07-15; reader unified 2026-07-17):*
  `daemon/protocol.h` is the command layer's adapter over the ONE
  shared bounded reader (`daemon/sexp.h`/`sexp.cpp`, the same grammar
  the plan and query-plan decoders consume — the slice-(b) as-built
  pin): `parseLine` wraps `sexp::read_one` with command-layer limits
  sized to the plan sidecar's, so a future builder or Q1 line embedding
  a plan payload unchanged is never refused by framing; `quoteString`
  is the wire-emission inverse.  The verb dispatch and catalog
  emission live beside the transport loops in `slogd.cpp`
  (`dispatch_line` -> `dispatch_command`).  Refusal shapes:
  `(refused parse <gen> [(verb V)] (detail "..."))`,
  `(refused unknown-verb <gen> (verb V))`,
  `(refused reserved-verb <gen> (verb V) (family
  boundary|query|watch|debugger))`; `<gen>` reads
  `Daemon::commandGeneration()` (backing store today: the update-epoch
  counter).  Catalog: `(catalog [relations|types|boundaries])` streams
  `(catalog-rel (name "N") (kind table|struct|lat) (arity A)
  (version-id I) (version-key K|#f) (boundary B|#f)
  (evaluation E|#f) (predecessor P|#f)
  (struct-id S|#f) (type-key T|#f) (lat-spec L|#f) (size Z|#f)
  (orders ((0 1) ...)) (temp #t|#f))` records — declaration truth,
  empties included, unlike `(schema)` — `orders` lists the materialized
  full-index orderings (sorted; `()` when index-free), the runtime
  materialization fact the Q1 planner schedules over — plus `(catalog-planned (name "N") (version-key K))` for
  announced-but-unregistered keys and `(catalog-type (sid S) (name "N"|#f)
  (arity A) (type-key T|#f))`. N3-C sources these records from the independent
  TypeDescriptor registry, so a dropped/history-only type remains present
  with `(name #f)`. N3-B adds ordered
  `(catalog-boundary (boundary B) (program P) (evaluation E) (position N)
  (generation G) (relations N))` history and `(catalog boundary "B")` direct historical
  relation lookup; an unknown key is a `boundary-lookup` refusal. Each stream
  is closed by `(catalog-end <n>)`.
  Protocol-mode seam: `Daemon::commandProtocolSpoken()`, set by any
  command verb EXCEPT the legacy `(continue)`/`(continue-boundary)`
  literals (every pre-T0 driver sends those; slice (d) scopes the
  uniform pause record by this flag), observable without marking via
  `(protocol-mode)` -> `(protocol-mode path|command)`.  The
  session-workflow-through-the-dual-stack leg remains with slice (b),
  whose entry-mode verbs are what the workflow needs beyond `.so`
  paths.
- **(b) `plan.h` parse/seal + entry modes (completed 2026-07-21).** Parse a real T1 `.plan`
  sidecar; the D16 seal battery; `installStratum` with validated entry
  modes and forwarding shims. Tests: seal-rejection battery extending
  `tests/interp-operator-tests.cpp`'s seal/bind rejections with parsed
  input, one test per refusal class; entry-mode refusals
  (resident-count × swap/restart, resident × reload, upgrade × state);
  provisional SCC/stratum lifecycle and dual-stack command session;
  `tests/pause-tests.sh` and `tests/session-tests.sh` green through the shims.
- **(c) identity keys + rule-meta registration + per-attempt fire
  vectors.** Tests: key-stability unit battery (same layer replay
  preserves keys; modified clone gets a fresh LayerId and fresh keys;
  degenerate module component round-trips; repo-relative source paths
  asserted per finding 6); `tests/stats-tests.sh` goldens unchanged
  with vectors underneath (merged totals ≡ legacy map).

  *As built, sub-slice c1 (2026-08-09, the W5′ runtime arc): the KEY
  CONSTRUCTION is live.*  Open question 1 is resolved: keys join the
  `m1:`/`v1:`/`b1:` compact colon-string family, pinned by the golden
  corpus in `tests/unit/identity-key-tests.rkt` —
  `r1:<ModuleInstanceKey>:<unit-slot>.<rule-slot>` and
  `scc1:<ProgramInstanceKey>:<scc-slot>`.  The degenerate module
  component the contract designed for is no longer needed: N1/N4 shipped
  in the interim, so RuleKey composes the REAL ModuleInstanceKey (the
  root occurrence serving non-module rules as `…:root`).  Slots are the
  contract's construction exactly — a rule is its lexical ordinal within
  its source unit (rule-lineage-key order over captured sources), a unit
  its ordinal within its occurrence's source list, a semantic SCC its
  canonical condensation ordinal (level-major, member-list tie-break),
  SEPARATE from the runtime stratum ordinal.  The compiler derives a
  program-key-free payload (`program-identity-payload`, carried on the
  compile-group beside the occurrence tree); the session mints at the
  boundary planner exactly as ModuleInstanceKeys mint, into a derived
  (never persisted) identity ledger exposed via `session-identity-records`
  and the session-drive `rule-keys` op.  One bug the smoke caught before
  the battery did: a source-path-keyed occurrence join MERGED two
  instantiations of one library file; the join is by lexical path
  (`module-ir-lexical-path` = its occurrence's), and the battery pins the
  distinction — two instances of `n1_graph_lib.slog` mint disjoint
  RuleKey sets, which is RF5 §2's per-occurrence lineage demand.
  Gates: `identity-keys` 7/7, new tier in ALL (ledger populated,
  instances distinct, root round-trip, no absolute locs,
  save→load re-mints BYTE-IDENTICAL, fresh session shares zero keys with
  identical shape); `identity-key-tests.rkt` 5/5 (corpus, refusals,
  minting, purity, fresh-key totality); unit 454; goldens subset over the
  compile-group field addition.  Remaining in (c): sub-slice c2 (daemon
  rule-meta registration, RuleId↔RuleKey) and c3 (fire vectors + the
  `(RuleId, VariantTag)` stat rekey T4 parked here).
- **(d) uniform pause record + watch tee-up (landed 2026-07-20).** The command-stack
  structured pause record for all pause classes (protocol-mode
  scoping; legacy stack byte-identical); the cause-payload grammar —
  including the watch-citation variant — designed, validated, and
  golden'd even though no watch fires yet; `watch`/`unwatch`/
  `subscribe` stay reserved. Tests: `--plain` golden transcripts for
  budget/boundary/terminal pauses through the command stack; a
  cause-variant validator proving a watch citation parses and renders
  without a message-shape change; path-stack byte-compat asserted.
  The level-0 watch battery itself (barrier evaluation, edge
  triggering, terminal-barrier prepared-not-committed) is implemented
  post-fork as thread-1/joint work per roadmap §3.1.

Order: (a) first; (b), (c), (d) each depend only on (a). Under the
progressive fork ratified today (roadmap §3.1): **slice (a) unblocks
REPL R0 work and slice (b) unblocks T2-A2's sidecar parsing**; R0–R1's
full fork start waits for (a)+(b)+(d) per the roadmap table. M4S runs
beside all of this with no shared files.

## Exit gates

Tied to the fork-gate criteria (roadmap §3.1):

1. **Protocol battery (F criterion 2):** every builder / seal /
   entry-mode / generation-token refusal driven by a test; the existing
   session workflow harness passes through the command protocol
   dual-stack, not just the path protocol.
2. **Uniform pause record (F criterion 3, as amended 2026-07-15):**
   golden transcripts for the structured pause record across pause
   classes on the command stack, plus the cause-variant validator;
   the watch battery itself is post-fork joint work.
3. **Catalog verbs (F criterion 4):** structured records keyed by
   VersionKey/TypeKey, no string parsing, sufficient for REPL name
   resolution and completion.
4. **Byte-compat:** Appendix A shapes byte-identical; pause, session,
   api, and stats harnesses green with zero parser edits.
5. **Identity:** key-stability battery green; stats goldens unchanged
   over the fire-vector substrate.

## Open questions (pinned, not blocking)

1. **Key serialization spelling:** opaque token versus readable
   s-expression for RuleKey/SccInstanceKey on the wire — modules.md
   §6.4 permits opaque (the REPL aliases either way); decide at slice
   (c) with a golden key corpus either way.
2. **Generation-token granularity:** one daemon-global counter
   suffices now; the M1 expected-revision unification
   (execution-tiers §2.2) decides per-run/per-epoch structure when M1
   lands. The wire field shape is pinned; the backing store is not.
3. **Record-stream pagination:** catalog verbs may outgrow
   line-at-a-time before Q1's `query-page` exists; whether they gain a
   `(page N)` argument early is deferred until a real catalog exceeds
   a sane line budget.
4. **TCP `(pending)` heartbeat interleaving** (`slogd.cpp:203`): whether
   record streams suppress the 2-second heartbeat or clients tolerate
   interleave; today's single-outstanding-line discipline makes this
   invisible, verb streaming may not.
5. **Retirement order** of compiled-action verbs (§9.2): verb-by-verb
   with the driver counterpart in the same change is contract; the
   order itself is chosen opportunistically as REPL R0 consumes
   equivalents.

## Appendix A: frozen reply shapes (byte-compat until verb-by-verb migration)

| shape | producer | load-bearing consumers |
|---|---|---|
| `(fixpoint <scc_id> "<name>" <iter> <ms>)` | `daemon.h:1121-1124` | `runslog.rkt:380` (wall-ms capture), `session.rkt:204`, `pause-tests.sh:62` |
| `(paused <scc_id> "<name>" <iter> read\|iter <new_tuples> <ms_call> <ms_total> <reason>)` — 8 fields | `daemon.h:1133-1139` | `runslog.rkt:386-433` (`memory)` suffix aborts; `iter ` gates hot-swap), `session.rkt:205-210`, `pause-tests.sh:61-65,101,113,145,168` |
| `(error ...)` | throughout | `runslog.rkt:434-436` aborts the run; `session.rkt:211` |
| `(pending)` | `slogd.cpp:203` (TCP poll timeout) | driver liveness |
| `(bye <unix-seconds>)` | `slogd.cpp:102-107` | close handshake |
| `(transient-armed)` / `(maintenance-armed)` | `daemon.h:277,284` | `session.rkt:228,239` |
| `(schema-rel table\|struct\|lat <name> <arity> [extra])` + `(schema-end)` | `actions.rkt` `(schema)` | `runslog.rkt:157` (name = `[^ ]+` — the Seam 6 tolerance), `session.rkt:768-771` |
| `(relation_size <name> <n>)` | `actions.rkt` `(sizes)` | api tests, session sizing |
| `(dumprow ...)` / `(dumpdone <n>)` | dump actions | `runslog.rkt:360-362` error-fact watch |
| `(countrow ...)` / `(countdone <rel> <n>)` | count dumps | count/session harnesses |
| `(inputledger direct\|mask ...)` / `(inputledger-done <n>)` | `actions.rkt` | ledger fixtures |
| `(sig <name> <count> <checksum>)` / `(sig-end)` | `actions.rkt` | `runslog.rkt:441-` signature reader |
| `(checkpointed ...)` | checkpoint action | `runslog.rkt:403` OOM-replay path |
| `(found ...)`, `(injected ...)`, `(update-committed ...)` | lookup/inject/update actions | `session.rkt:931-941` and friends |

The full name-in-reply census is `n0-seam-map.md` Seam 6. A shape
leaves this table only when its consuming parser migrates to a
structured verb equivalent — retirement and driver counterpart in the
same change (execution-tiers §9.2).
