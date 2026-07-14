# Fully Incremental Slog

## Status and reading contract

**Status, 2026-07-13:** this is the normative semantics, architecture, and
active implementation plan for incremental Slog.

Phase 0 is shipped: stratified negation, resident forward-incremental
sessions, relation versions, anchored batches, rename/drop, recipe
save/load, and bounded clear-and-rerun deletion. M0.1 through M0.4 are also
implemented: version identities, semantic input overlays, exact historical
bindings, transactional recount, the new persistence format, arithmetic
abort/retry, and an independent versioned operational-IR count oracle.

M0.4's exit audit is complete for the capability-certified recount surface.
M1 is also shipped for positive edits through capability-certified plain-table
cones, including recursive SCCs, multiple downstream strata, and explicit
inject-and-reopen version edges. M3 is shipped for direct and inherited
retractions through capability-certified acyclic plain-table cones, including
mixed negative/positive flushes and multiple downstream strata. Recursive
SCCs, negation, structs, nullary relations, and every unsupported version
topology still take the permanent clear-and-rerun path. M6L's first two slices
are implemented: contributor state for acyclic root lattice producers is
recounted transactionally, signed edits repair affected visible keys, and a
closed old-to-new replacement propagates through acyclic positive plain-table
consumers. Recursive producers or consumers, negation, downstream lattice
writers, inheritance, and historical edits still fall back.

Shipped details, known deviations, and test evidence live in
[incremental-status.md](incremental-status.md). Git history preserves the
older discussion document that mixed the original design, implementation
diary, and roadmap.

This document uses three kinds of statement:

- **Semantics** define the answer Slog must produce.
- **Invariants** are correctness obligations on every implementation.
- **Milestones** sequence implementation work. A milestone may optimize an
  operation only after the fallback already implements its semantics.

The semantic oracle is always:

> Desugar the pipeline into immutable relation versions and ordinary rules,
> apply the requested input overrides at their anchored versions, and compute
> the least fixpoint from scratch.

Every live update, saved recipe, replay, count round, and DRed sweep must agree
with that oracle.

---

## 0. Session and pipeline semantics

### 0.1 Workflows and scope

The feature serves these workflows:

- **W1 — run and stream:** run a program, then feed input additions and
  retractions without restarting the session.
- **W2 — load and stream:** load a saved chain and continue through the same
  session API used by W1.
- **W3 — save a fed session:** append an immutable layer containing its
  recipe and input overrides; never mutate ancestors.
- **W4 — move and continue:** load, update, save, and repeat across processes
  or machines.
- **W5 — rename and drop:** rebind relation names between program segments
  without a copy rule.
- **W6 — link a database:** import selected relations from another database
  at an anchor. Flat targets are shipped. Direct linking of a chained target
  remains deferred; freeze it first.
- **W7 — freeze:** materialize a chain as a history-free flat root.
- **W8 — front-end editing:** accept mixed additions and retractions of
  data-fed facts. Program-source edits are recipe/program changes, not data
  retractions.
- **W9 — repeat and inspect:** instantiate cached programs at multiple
  pipeline positions and query earlier relation versions. This is currently
  a semantic guarantee, not yet a claim of bounded copy amplification.

Phase 0 implements all answers through delta entry where monotone and bounded
clear-and-rerun otherwise. Later milestones replace some reruns with precise
maintenance. The fallback remains available permanently.

### 0.2 A session is an anchored recipe

A session consists of:

1. an optional immutable base database chain;
2. an ordered recipe of program, import, rename, drop, and link events;
3. input overrides anchored to physical relation versions; and
4. a resident materialization of every version needed for time travel.

The recipe is semantic state. Materialized tuples, indices, compiled shared
objects, and derivation counts are caches.

The driver owns the recipe. The daemon owns the resident versions and their
indices. Saving appends one new layer containing the new recipe fragment,
payloads, and final materialization. Loading replays the recipe through the
same session machinery used live.

#### Stable version handles

Names and pipeline positions are user-facing lookup conveniences; neither is
a sufficient physical identity.

Separate persistent slot description from evaluation-local mutable state.

Each logical slot has an immutable **VersionDescriptor**:

- a persistent **VersionKey**, identifying the slot in the pipeline recipe;
- its creation event and output-slot ID;
- an optional predecessor VersionKey;
- a creation kind; and
- its schema and struct type identity.

Each materialization of that slot has a **VersionInstance**:

- a runtime **VersionId**, unique within one recipe evaluation in one daemon;
- a reference to the VersionDescriptor;
- the exact runtime stratum instances that write it;
- its effective direct-input assertions and inheritance masks;
- its live relation/index state; and
- any committed count epoch.

Writer instances and overlays are not persistent descriptor identity. Writers
can change when the compiler legitimately regroups SCCs; overlays can differ
between descendant recipe evaluations. They are reconstructed and audited on
load.

A new layer assigns stable event identifiers. A persistent VersionKey is the
layer identity plus the creation event and output slot. A runtime load maps a
VersionKey in the current recipe evaluation to a fresh VersionId.

The layer identity is an immutable, content-neutral identifier allocated
before recipe hashing (for example, a random 128-bit LayerId). It is stored in
META and covered by the recipe digest, but is not derived from that digest;
otherwise VersionKey construction would be circular. Copying an immutable
layer preserves its LayerId. Creating a new layer, including a modified clone,
allocates a new one. Event identifiers are local to the LayerId and never
renumber after publication.

On load, repeated LayerIds are allowed only for the same immutable layer
identity reached through two DAG paths. Conflicting descriptors or stamps
under one LayerId are corruption/collision and are refused.

A version-creating event stores an explicit output-slot table. Slot IDs are
assigned once and serialized; they are not recomputed from SCC number, stratum
position, relation display name, or hash-table order. A program event can
therefore have several SCC writer instances for one output slot without
changing its VersionKey.

New saves should anchor batches by VersionKey. For diagnostics they may also
record the visible name and ordinal. Legacy recipes using a relation name and
version ordinal remain readable and are resolved to a VersionKey during
replay.

A VersionKey is a stable **slot identity**, not a content hash. A descendant
recipe may attach an override to an ancestor slot, so the same VersionKey can
materialize different contents in two descendant branches. The current
single-branch session needs only VersionId, but registries and protocols must
not assume a process-global `VersionKey -> Relation*` map. If simultaneous
branch evaluation or chained hot-link replay is added, its lookup key is
`(EvaluationId, VersionKey)` and each pair receives a distinct VersionId.
Counts and live indices belong to that VersionId only.

This makes anchors stable under:

- rename aliases;
- drops and later redeclarations of the same name;
- compiler SCC regrouping;
- multiple strata writing one relation within a segment;
- repeated instances of the same cached program; and
- anchors reaching into ancestor layers.

### 0.3 Input overrides and batch transports

An input operation changes input support at one VersionId. It does not delete
or manufacture a rule derivation.

For each tuple at a version, the semantic input overlay contains:

- **direct assertion:** the tuple was asserted at this version;
- **inheritance mask:** predecessor presence is suppressed at this version.

The effective foundation also includes non-recursive rule support, described
in §3.

Set-operation semantics are:

- Add an already-direct input: no-op.
- Add an actively inherited input: no-op.
- Add an inheritance-masked tuple: remove the mask.
- Add an absent or derived-only tuple: create a direct assertion.
- Delete a direct assertion: remove it; active inheritance or rule support
  may keep the tuple present.
- Delete an actively inherited tuple: create an inheritance mask.
- Delete a derived-only tuple: refuse.
- Delete an absent tuple: refuse.

Therefore opposite commands do **not** blindly annihilate. They normalize
against the anchored version's baseline:

- inherited T; add T; delete T => an inheritance mask remains;
- inherited T; delete T; add T => no override remains;
- absent T; add T; delete T => no override remains.

The saved form stores the normalized direct-assertion and inheritance-mask
sets. A logical set may be backed by an inline/bin payload or an immutable
link reference; it need not duplicate a large source relation on disk. Live
content and replay content must agree after every command sequence.

Imports and links set direct assertion for every imported tuple, including a
tuple already present only by derivation. Overlapping imports are idempotent.

Program ground facts are **program support**, not data input. Their count
round contribution is non-recursive. Removing a source fact requires a new
program/recipe version. A data retraction of the same tuple may remove direct
input support, but the program fact still derives it.

Batches have three transports:

1. inline action plugins for small batches;
2. self-contained bin-database payloads for bulk data;
3. linked database references for provenance-bearing inputs.

All transports reduce to the same normalized input-overlay operation.

The JIT API exposes two intentionally different operations:

- **edit a slot:** change the overlay of an existing VersionInstance; its
  VersionId and VersionKey do not change;
- **inject a slot:** allocate a new input-only successor VersionInstance with
  a fresh VersionId and persistent VersionKey, inherit the current tip as its
  predecessor, then apply input edits to the successor.

Injection is not syntactic sugar for editing the tip. It creates a distinct
time-travel/query target and a distinct count owner. Live injection currently
targets the JIT tip; injecting into history means constructing a descendant
recipe branch, so the old evaluation is never retroactively renumbered.

Plain injection is deliberately **input-only**. It does not silently retarget
an already-recorded semantic stratum or mutate its historical read map. To
derive downstream facts from the new slot, append an explicit program/reopen
event. `session-inject-and-reopen!` packages those two semantic operations: it
first settles the injected input-only successor, then appends the requested
program event. Its recipe serializes the reopened semantic instances and
stable output VersionKeys; it is not a maintenance re-push. The shipped policy
makes every reopened output a successor that inherits predecessor presence.
A history-free recomputation is a different branch/fresh-output policy and is
not yet exposed by this helper.

### 0.4 Relation versions and environments

A relation name denotes a binding chain, not an object identity.

The following events affect a relation:

- **root open or declaration:** create an initial slot with no predecessor;
- **segment write:** create a new version inheriting from the current one;
- **batch/import/link into an existing span:** update that slot's effective
  input overlay in the current recipe evaluation; it does not create a new
  pipeline-write slot;
- **import/link to an unbound target:** create a fresh slot from the source
  schema, with no predecessor, then add direct input;
- **rename R S:** bind S to R's current VersionId and unbind R;
- **drop R:** unbind R without destroying its old versions;
- **fresh declaration after a drop:** create a new version with no
  predecessor.

A batch to an unbound target is refused because it carries no declaration.
Every import/link schema must match an existing target exactly or define the
fresh target slot explicitly.

Untouched names alias their existing VersionId. A segment creates at most one
new VersionId per relation it writes, even when several SCC strata in the
segment write the relation. Every such stratum instance is recorded as a
writer of that version.

Thus an anchor edits the relation slot selected by last-write-at-or-before the
user's pipeline point. All consumers bound to that slot observe the edited
value, including a consumer textually between the slot's creation and the
anchor point. To express a value that begins only after such a consumer, the
recipe must create a new relation slot (normally by a writing segment). This
slot-editing rule is part of the API semantics and must be visible in
introspection; it is not wall-clock event-time versioning.

The denotational meaning is an alpha-renamed program:

~~~text
R@k+1(x) :- R@k(x).          inheritance
R@k+1(...) :- segment-k+1 rules
~~~

The runtime need not compile those names. Generated plugins resolve ordinary
names through the environment of their original bind position and then retain
direct pointers.

#### Version-local count invariant

Counts belong to one physical VersionId.

- Every actively inherited tuple contributes exactly one non-recursive
  support to the successor.
- Only stratum instances recorded as writers of that VersionId contribute
  rule counts to it.
- A historical stratum is always recounted at its original environment. It
  must never be rebound to a later environment merely because the later
  version is being counted.
- Rename aliases never duplicate counts because they name one VersionId.

This is the hard boundary that prevents a DRed sweep in a later segment from
tunnelling into an earlier version.

#### Materialization policy

The shipped implementation eagerly copies a predecessor's live master index
when a segment writes a relation. That remains the initial implementation.
Copy-on-write or persistent indices are a compatible optimization, but W9
needs a copy-amplification benchmark and an explicit memory limit before it
can be called scalable.

Drop does not reclaim time-travel-visible versions. Reclamation is a separate
prune/freeze/GC operation.

### 0.5 Dependency graph and re-entry modes

The driver maintains a graph over VersionIds:

- positive rule-read edges;
- negative rule-read edges;
- lattice-value read edges;
- inheritance edges;
- import/link/input events; and
- rename aliases, which preserve identity rather than add a derivation edge.

For an update to version V, its cone is the reachable suffix of this graph.
Every edge carries a maintenance capability:

- positive set edge;
- negative edge;
- lattice-value edge;
- value-keyed side-table edge;
- external-oracle edge.

Routing is capability based:

1. **delta entry:** precise O(change) maintenance when every cone edge and
   target version supports the required signed flavor;
2. **replay entry:** set-semantic monotone re-entry for an uncounted cone;
3. **clear and rerun:** rebuild the bounded cone for every unsupported or
   non-monotone case.

Correctness never depends on choosing the faster route.

After M1, replay entry must not fire counted rules over the whole database:
that would duplicate counts. A counted cone uses signed delta entry or is
invalidated and rerun/recounted.

### 0.6 Retraction and mixed batches

A retraction is legal only against direct or inherited input support. It may
leave the tuple present because program rules still derive it.

The API may accept additions and retractions together. The driver first
normalizes all operations to the final input overlay. Maintenance then uses:

1. a negative phase for lost support;
2. a positive phase for new support;
3. one final settled response.

Until the relevant precise milestone is complete, the same normalized update
uses clear-and-rerun. Front ends never need to split a mixed update for
correctness.

The three phases form one update epoch. Without an MVCC snapshot, ordinary
queries, normal saves, and a second update are refused until it settles;
candidate/live state is intentionally inconsistent with the stable answer in
the middle. Pausing may expose progress or create an explicitly partial
checkpoint, but it must not label that state settled. If counted maintenance
fails, rebuild from the already-normalized target overlay before making the
epoch visible.

### 0.7 Rename, drop, and aliases

Rename and drop are environment operations:

- rename preserves the VersionId;
- rename requires a bound source and an unbound target;
- drop preserves old addressability;
- drop requires a bound source;
- a redeclaration after drop starts a fresh lineage;
- already-bound strata remain bound to their original VersionIds.

Runtime protocols and counted state identify versions by VersionId, not by
Relation::getName. Names are presentation and binding keys only.

Manifest threading applies the same rename/drop events at compile time so a
later segment resolves the live schema. Intra-program surface syntax for
rename/drop remains separate work; session recipe operations are shipped.

### 0.8 Stratified negation

Shipped negation has the form ~(R ...), is range restricted, and is rejected
through recursion. A negated atom compiles to an absence probe over a closed
lower-stratum relation.

Phase 0 treats every update crossing a negative edge as non-monotone and
clear-and-reruns its cone.

Precise negation is not obtained merely by flipping the sign at an
absence probe. For:

~~~text
H(x) :- A(x), not B(x)
~~~

- a presence transition +B must enumerate matching A rows and emit -H;
- a presence transition -B must, after B is final, enumerate matching A rows
  and emit +H.

M4N must therefore emit negated-body-driven variants with explicit pre/post
state. Until M4N, negative edges remain on clear-and-rerun even when the rest
of the cone is counted.

Negation of demand-grown, intern-only, oracle, and unanchored value-side-table
relations remains rejected as documented by the shipped type checks.

### 0.9 Links

A link imports selected source relations under a name map as direct input at
an anchored VersionId. The manifest records the dependency edge.

Flat links are shipped. A chained target is not equivalent to its leaf
directories, so direct chained links remain refused. The eventual
implementation must replay/materialize the target chain first, then import
its final selected relations.

M0 treats a link/import as an immutable snapshot source whose selected tuples
join the target's direct-input set. Replacing or removing one of several
overlapping sources is a recipe change and uses clear-and-rerun from the union
of all surviving sources. It must not send a blind `-tuple`, which could erase
support still supplied by another source. O(change) source replacement is a
separate extension: key direct support by stable source event, diff that
source, and emit a premise transition only when the source-union changes
membership.

### 0.10 Persistence, replay, and freeze

A session layer contains:

~~~text
META
recipe
prog.sexpr
delta.k/ payloads
final relation directories
signature
~~~

The recipe is authoritative. Final relation directories are replay witnesses
and optional seeds, never the source of version identity or counts.

New recipe events carry stable event IDs and VersionKeys. The loader accepts
legacy name/ordinal anchors and translates them while replaying their binding
chains.

Intermediate versions are rebuilt by replay and remain addressable in memory.
Counts never touch disk. A load starts uncounted and establishes count cache
only when requested.

Freeze writes one flat root with no recipe history. It allocates fresh root
VersionDescriptors; every emitted tuple is a direct root assertion, with no
predecessor or historical writer provenance. It may remint struct IDs after
rewriting all referents. Freeze intentionally discards time travel and
anchored editability.

### 0.11 Granularity ladder

| Stage | Correct maintenance | Granularity |
|---|---|---|
| Phase 0 | delta entry or bounded clear-and-rerun | stratum/version cone |
| M0.4–M3 | counted positive maintenance and acyclic deletion | tuple |
| M6L | precise deletion of stratified lattice contributions | key/contributor |
| M4T/M4S/M4N | DRed for recursive tables, structs, and negation | tuple/SCC |
| M7 | recursive lattice/rank repair | key/value |

The stages refine cost, not meaning.

---

## 1. Why recursion needs more than proof counting

Counting one-step rule instantiations is finite and exact for acyclic rules.
It is not enough for recursive foundedness.

For:

~~~text
R(y,x) :- R(x,y).
input R(a,b)
~~~

the materialization contains R(a,b) supported by input and recursion, and
R(b,a) supported recursively. Clearing the input can leave both recursive
counts positive even though the pair is now an unfounded cycle.

Pure counting cannot distinguish a founded recursive proof from circular
self-support. DRed repairs foundedness by over-deleting the suspect recursive
region and rederiving only what surviving support can found.

---

## 2. Chosen maintenance family

The initial recursive algorithm is DRed with counting, following the
non-recursive/recursive support split of DRed^c.

It fits Slog because:

- rule evaluation remains forward;
- existing semi-naive join variants can be extended;
- non-recursive support is a hard barrier;
- recursive suspects are repaired without backward rule evaluation; and
- Phase 0 already supplies bounded version-cone orchestration.

The first scope is positive plain Datalog over table relations. Structs,
negation, and lattice values each require the explicit extensions in §7,
§0.8, and §7A.

---

## 3. Core state and invariants

### 3.1 Semantic support and count cache

For tuple t in version V:

~~~text
direct(V,t)       boolean direct input assertion
inherited(V,t)    predecessor presence and no inheritance mask
nonrec(V,t)       non-recursive rule support + inheritance support
rec(V,t)          recursive rule support
~~~

Inheritance contributes one to nonrec. The direct bit is reconstructed from
the semantic input overlay. Program ground facts contribute nonrec.

At a stable fixpoint:

~~~text
present(V,t) = direct(V,t) or nonrec(V,t) + rec(V,t) > 0
foundation(V,t) = direct(V,t) or nonrec(V,t) > 0
~~~

The packed sidecar may continue to store direct, nonrec, and rec compactly.
The recipe/version ledger, not the packed word, is authoritative for direct
and inheritance provenance.

### 3.2 Consequence updates versus premise signals

A rule instantiation changes the support of its head. A presence transition
of that head emits a signed premise signal for downstream rules.

These are distinct:

- support contribution: tuple, rec/nonrec kind, sign;
- premise signal: tuple, presence sign.

A count change with no relevant membership transition does not normally
propagate. Recursive negative maintenance is the exception: losing the last
foundation can over-delete a tuple even while rec remains positive.

Transition interning is shared runtime state. Distinct head-maintenance tasks
may publish transitions concurrently, so insertion into the sign-separated,
VersionId-keyed journals must be linearizable. A downstream stratum stages an
immutable view only after the producing stratum's task barrier. The update's
validity bit is likewise atomic: arithmetic or coverage failure from any head
invalidates the whole counted result.

### 3.3 Count epochs

Count establishment is transactional.

- A recount begins an epoch for exact VersionIds.
- Uncounted target sidecars are cleared or replaced with scratch sidecars.
- Foundation seeding and all writer strata contribute to the epoch.
- A coverage audit validates the result.
- Commit atomically marks the versions counted.
- An interrupted or failed epoch is discarded; retry cannot fold onto a
  partial sidecar.
- Counter overflow aborts the epoch and marks the version not count-capable
  under the current representation. Counters never saturate.

A boolean counted flag is a presentation of committed epoch state, not the
transaction mechanism.

### 3.4 Candidate set and live membership

During a negative recursive sweep, C is keyed by `(UpdateEpoch, VersionId,
tuple)` and contains over-deleted tuples together with their stable identity
and count entry.

The live master indices, not the count sum, define membership during the
sweep. A tuple can be outside the live indices while rec is positive.

Each tuple enters C at most once per update.

---

## 4. Algorithms

### 4.1 Exact-once signed join partitions

Fix a deterministic order over body **occurrences**, not merely relation
names. Let O be the pre-update relation and N the post-update relation.

For a positive batch, every newly enabled rule instantiation is assigned to
its rightmost newly present body occurrence i:

~~~text
N before i  ×  DeltaPlus at i  ×  O after i
~~~

For a negative batch, every lost rule instantiation is assigned to its
leftmost deleted body occurrence i:

~~~text
N before i  ×  DeltaMinus at i  ×  O after i
~~~

This partition applies to repeated relation occurrences and self-joins.
The opposite positive ownership convention (`O / DeltaPlus / N`, leftmost
new) would also be exact, but mixing conventions inside one flavor would not
be. The formulas above are the normative meaning of the current
old/full/delta variants. Tests must exercise simultaneous changes in multiple
occurrences. The partition defines logical views, not a required physical
layout. M3 materializes `N` in FULL immediately, retains each true-to-false
row in the negative delta index, and implements `O` after the driver as the
duplicate-free union `FULL union DeltaMinus`. Thus a deleted row remains
readable only where the partition requires old-state membership. M4T may use
a candidate layout during over-deletion, but must expose the same logical `N`
and `O` views.

### 4.2 Version-local count establishment

To recount a VersionId V:

1. Begin a count epoch.
2. Seed direct input from V's normalized input overlay.
3. If V has a predecessor, add one nonrec inheritance contribution for each
   predecessor tuple not masked at V.
4. Run every stratum instance recorded as a writer of V, exactly once over
   full indices, at that stratum's original environment.
5. Do not run historical writers of predecessor versions against V.
6. Verify every sidecar key is live and every live countable tuple has a
   sidecar entry.
7. Report zero-support table rows as drift; apply the struct tombstone rule
   from §7.
8. Commit the epoch.

Cone recount repeats this operation in version-graph topological order.

### 4.3 Positive counted maintenance

Given counted versions and a normalized direct-input addition:

1. update the direct bit;
2. if live membership changes false to true, insert the tuple and stage
   DeltaPlus exactly once;
3. run counted delta variants using §4.1;
4. apply each head contribution to nonrec or rec;
5. emit a downstream DeltaPlus only on false-to-true presence;
6. cross version boundaries by maintaining the successor's inheritance
   contribution, never by rebinding the predecessor's writers.

Temps in counted flavors must be instantiation-injective and must preserve the
premise sign through every staged follow-up. During DRed rebuild, a candidate
can be count-positive while absent from live indices; its explicit reseed is
the membership transition that emits DeltaPlus. A zero-count candidate that
is newly rederived is inserted, removed from C, and staged in the same way.

### 4.4 Acyclic deletion

For an acyclic counted cone:

1. remove direct input or mask inheritance;
2. decrement the corresponding foundation support;
3. if stable presence becomes false, stage DeltaMinus;
4. use §4.1 to decrement consequences exactly once;
5. propagate only true-to-false presence transitions.

Rows whose support remains positive are support-only decrements: they do not
enter DeltaMinus and do not wake downstream rules. A zero count is represented
by absence of a sidecar entry, and the corresponding row must be absent from
every live index before the phase can report counts valid. No candidate set is
needed because rec is zero in an acyclic SCC.

### 4.5 Recursive negative fixpoint

For one recursive stratum, process lost support as follows:

~~~text
on_lost_derivation(t):
    decrement the tagged support counter
    if not foundation(t) and t not in C:
        add t to C
        stage (t, -)
~~~

The candidate condition is deliberately independent of rec and independent
of a count-derived presence transition.

For each negative round:

1. newly staged candidates remain in FULL while their DeltaMinus drives the
   exact partition;
2. previously processed candidates are absent from FULL;
3. after the round's read and support updates, remove the current DeltaMinus
   candidates from live indices but retain their rows in C and their counters
   in the sidecar.

This prevents later rounds from joining through cumulative dead candidates
and double-decrementing derivations.

At negative fixpoint, rec counts only derivations through surviving live
premises.

### 4.6 Reseed and positive rebuild

Scan C:

- rec greater than zero: reinsert the tuple into live indices and stage
  DeltaPlus; its own count is already correct;
- rec equal to zero: leave it absent; retain only identity tombstone state
  required by §7.

Then run the positive fixpoint of §4.3. A tuple that reached zero may be
relearned from a newly re-founded premise.

### 4.7 Stratified schedule and mixed updates

Process versions and strata in topological order:

~~~text
for each affected stratum:
    negative fixpoint
    reseed
    positive fixpoint
~~~

Earlier strata are final before later strata begin. Inheritance and
non-recursive support therefore remain stable barriers within a recursive
stratum.

Negation and lattice edges use their dedicated algorithms when implemented;
otherwise routing selects clear-and-rerun.

---

## 5. Required examples

### 5.1 Version barrier

Segment 1 derives R@1. Segment 2 writes R and creates R@2.

- tuples copied from R@1 receive one nonrec inheritance support in R@2;
- segment 1 rules count only against R@1;
- segment 2 writers count against R@2;
- a new segment-2 fact cannot retroactively create a segment-1 derivation.

This example must replace the M0.3 test that currently expects both segments'
rules to be rebound to the tip. In the existing `base.slog` + `seg2.slog`
fixture, `path@2(1,5)` has one recursive support from the segment-2 writer,
not two; the segment-1 writer belongs to `path@1` and could not see edge
`(4,5)`. Inherited rows may also have a segment-2 rule support, so tests must
check support kind and writer attribution rather than assume every count of
two is duplication.

### 5.2 Unfounded symmetric cycle

After direct input R(a,b) is removed:

- foundation of R(a,b) becomes zero, so it enters C despite rec greater than
  zero;
- its negative signal removes the recursive support of R(b,a);
- both leave the live index;
- neither has rec support through a survivor;
- reseed restores neither.

### 5.3 Over-delete and refound

In a reachability diamond, deleting one foundation route may over-delete a
tuple that still has a recursive derivation through surviving premises.
The negative fixpoint leaves rec positive, reseed restores the tuple, and its
DeltaPlus rebuilds consequences that reached zero.

### 5.4 Baseline-aware input normalization

For inherited T:

- add then delete produces a mask and T is absent unless rule-derived;
- delete then add removes the mask and returns to baseline;
- save/load preserves the same result.

---

## 6. Implementation map

### 6.1 Data structures

Add or refine:

- VersionDescriptor with persistent VersionKey, predecessor, creation event,
  output slot, creation kind, and schema;
- VersionInstance with EvaluationId/VersionId, runtime writers, input overlay,
  live storage, and committed count epoch;
- BindingEvent mapping a name and position to VersionId or unbound;
- StratumInstance with runtime instance ID, originating program event,
  diagnostic bind position, and exact read/write VersionId maps;
- transactional count sidecars keyed by VersionId;
- candidate sets C;
- separate struct intern identity from live membership (§7).

The count sidecar remains separate from ordinary relation indices and never
persists to disk. Table counts key by full tuple. Struct counts key by stable
struct ID.

The sidecar coverage invariant is:

> A committed counted version has an audited support entry for every live
> countable tuple, and no live support entry for an absent table tuple.

### 6.2 Operators

The target signed read path is not wholly sign-agnostic.

- Delta records expose their premise sign to generated pipelines.
- Counting head records carry contribution kind and sign.
- Temp staging preserves sign.
- Positive and negative exact partitions use the body-occurrence order.
- The negative merge point can put a tuple into C even if rec keeps its count
  sum positive.
- Negative-round completion removes processed candidates from live indices.
- M4N adds negated-body-driven operators.

Normal and seeded set-semantic flavors keep their existing dedup behavior.
M1 exercises the positive sign through `_maint1`; M3 preserves the negative
sign through `_maint3neg` temps and false-transition scheduling. Candidate
over-deletion and reseed scheduling remain M4 obligations.

### 6.3 Code generation

Retain six flavor families:

- normal set semantics;
- seeded replay set semantics;
- legacy positive set-only delta entry;
- counted positive maintenance (`_maint1` for the M1 contract);
- counted acyclic negative maintenance (`_maint3neg` for M3); and
- full count establishment.

The counted flavors must share logical rule classification and instantiation
multiplicity. They may use different driver versions, but temp decomposition,
guards, errors, or-splits, and projection must not collapse a derivation in
only one flavor.

### 6.4 Recursive/non-recursive classification

A logical rule contribution is recursive iff a positive body relation is in
the same SCC as its head. Otherwise it is non-recursive.

- staged subrules inherit the logical source rule's classification;
- program ground facts are non-recursive;
- direct data input uses the direct bit, not a rule kind;
- inheritance is one synthetic non-recursive contribution;
- negated reads are stratified and do not make a rule recursive;
- multiple SCC strata writing one version are all recorded as its writers.

The analysis and IR attributes already exist. The old M2 milestone is retired
into M1 cleanup.

### 6.5 Driver and lifecycle

The session driver owns:

- normalized overlays;
- VersionKey resolution;
- version-graph cones;
- capability routing;
- count epochs;
- negative/reseed/positive scheduling;
- fallback selection;
- recipe serialization.

Pausing may stop exact read cursors. It must never cause a support
contribution to be replayed. A count epoch is committed only at a fixpoint
boundary. An update epoch retains its normalized target overlay and phase
cursor across a pause; normal query/save actions remain gated until settlement.

### 6.6 Actions and protocol

Actions should target VersionId internally and return per-tuple outcomes.
Useful responses distinguish:

- asserted;
- already direct;
- inherited/no-op;
- mask cleared;
- direct removed but still inherited;
- direct removed but still derived;
- inheritance masked;
- derived-only refusal;
- absent refusal.

User-facing helpers may continue to accept latest name, point, or persistent
VersionKey.

---

## 7. Struct identity and deletion

Current struct master indices combine two roles:

1. content-to-ID interning;
2. live relation membership.

Precise deletion must separate them:

- an intern dictionary retains content-to-ID tombstones;
- live master and secondary indices contain only present struct rows;
- over-delete removes live membership after its driving round;
- reseed or relearn consults the dictionary and reuses the original ID;
- IDs are never recycled online;
- freeze/compaction may densely remint IDs after rebuilding every referent.

M5 is therefore a prerequisite for struct-capable recursive deletion. M4T may
ship for plain tables first.

---

## 7A. Lattices and aggregates

This section retains the detailed numbering used by `docs/lattices.md` and
compiler comments. Two features must remain distinct: the existing Slog
lattice relations, and a possible future SQL-style aggregate construct.

### 7A.1 Existing Slog lattice relations and stability

Existing min, max, flat, count-lattice, set, and map values are keyed
semilattice joins. Their payload map and value-carrying delta are the right
insertion substrate. An ascending join is monotone; deletion can make the
value regress and therefore needs repair from surviving contributors.

Recursive use is admissible only under the language's monotone-use checks.
For any future user-defined recursive lattice, an assertion of stability is
not enough: accept a built-in trusted instance or a separately specified,
checkable certificate. Non-stable recursive SUM/COUNT-style folds remain
rejected.

### 7A.2 Foundedness state and contributor state are separate

Do not conflate whether an output tuple is founded with the state needed to
compute its value.

1. **Foundedness state** determines whether the result tuple is live.
2. **Contributor state** determines the current joined or aggregate value.

An input tuple contributes once while present, regardless of how many rule
derivations support it. Contributor collections are therefore driven by
premise presence transitions, not raw derivation-count changes.

For an existing lattice head, model a hidden set relation of emitted
`(key, payload)` contributor tuples. Its rows have ordinary foundedness
support, so two rule instantiations emitting the same contributor collapse
without making one retraction erase the other. The visible lattice payload is
the join of the currently live contributor rows. This is smaller and more
stable than storing every proof, while still retaining losing payloads needed
after regression. SQL-style non-idempotent aggregates may require a finer
source-tuple contributor identity and are deliberately separate.

For stratified lattice input, retain enough per-key contributors to recompute
after deletion, or deliberately rerun the producing cone. A value change is a
replacement pair: retract the old `(key, value)` and insert the new one in one
logical update. An ascending replacement may use the monotone path; a
regression uses repair or fallback.

### 7A.3 Rank and recursive lattice repair

Foundedness rank can be viewed as a recursive minimum over derivation depths,
which explains why rank regression and recursive min/max repair have similar
shapes. It does **not** make either feature free: finding the next surviving
value requires stored contributors, localized rule re-evaluation, or a
hybrid.

M7 must choose that tradeoff using workload measurements. Until then,
recursive lattice regressions route to clear-and-rerun.

### 7A.4 DRed repair versus rank repair

DRed^c tracks coarse membership support and may over-delete a region before
reseed. Rank repair retains a finer value and should touch only facts whose
best surviving rank changes, at the cost of more provenance or
re-evaluation. They can share scheduling, candidate, and replacement-delta
infrastructure, but neither representation should be forced into the other.

### 7A.5 Custom stable semilattices

A future custom declaration needs a domain, bottom, join, order, serialization,
and an admissibility story. The implementation may begin with a closed set of
trusted built-ins. Arbitrary user code does not become recursively safe merely
because it claims associativity, monotonicity, or stability.

### 7A.6 Implementation tiers

1. **M6L — existing lattices, stratified deletion.** Maintain contributor
   state for lower-stratum inputs and emit replacement pairs. Recursive
   regressions still fall back.
2. **M7 — recursive stable lattice/rank repair.** Add the chosen repair
   strategy and retire fallback only for supported monotone forms.
3. **M6A — optional SQL-style aggregates.** COUNT, SUM, AVG, and multiset
   MIN/MAX are a separate language and IR feature, not aliases for Slog's
   existing count semilattice. Specify syntax, grouping, empty groups,
   contributor identity, set/duplicate semantics, stratification, state, and
   replacement deltas before implementation. Non-stable recursion is
   rejected.

### 7A.7 Forward-compatibility hooks

The earlier milestones must preserve these seams:

- count sidecars are separate from relation payload maps, so contributor or
  rank state can use a distinct typed sidecar;
- deltas can represent a signed membership transition or an atomic value
  replacement without overloading derivation counts;
- relation metadata has a lattice/aggregate kind and serialization identity;
- IR metadata exposes same-SCC body edges and polarity;
- count flavors exclude lattice writes until a matching, exact contributor
  contract exists; and
- fallback routing is explicit per relation capability, not inferred from a
  relation's storage class alone.

---

## 8. Global correctness invariants

1. **Version locality:** a stratum reads and writes the VersionIds of its
   original environment.
2. **One inheritance support:** every active predecessor tuple contributes
   exactly one nonrec support to its successor.
3. **Exact-once derivations:** counted positive and negative variants partition
   instantiations by body occurrence.
4. **Transactional counts:** partial recount state is never reused.
5. **Coverage:** committed counts cover every live countable tuple.
6. **Live-index truth:** over-deleted tuples do not remain join-visible after
   their driving negative round.
7. **Stable struct identity:** dead content may retain identity but not live
   relational membership.
8. **Baseline-aware input:** command normalization is relative to direct and
   inherited support.
9. **Counts never persist:** replay establishes semantic state; recount heals
   cache.
10. **Fallback completeness:** unsupported cones clear-and-rerun.
11. **Nullary relations:** counted arity-zero relations use a singleton key or
    remain explicitly routed to fallback; they are never silently omitted.
12. **Side-table anchoring:** residue-only value tables may be excluded from
    counting only when every read is anchored by a live value ID.
13. **Arithmetic failure:** count underflow/overflow is loud and recoverable;
    it never commits saturated or partial support.

### 8A. Compression and replay

Compression stores recipe and enough tuple witnesses to accelerate replay.
It does not store counts.

- Positive seeds are safe only when they are subsets of the true fixpoint.
- A negative mutable edit invalidates downstream samples, so dependent layers
  replay unseeded.
- A count round over a replayed fixpoint counts that materialization; it
  cannot prove that mutually supporting stale seeds were originally founded.
- Full unseeded replay remains the strong drift check.
- Count coverage reports isolated zero-support table seeds.
- Recipe-internal deletions are already part of an immutable layer's
  semantics and do not by themselves invalidate a later layer sampled from
  that semantics.

### 8B. Count-round architecture

Counts are recomputable, plan-relative cache over one settled version graph.

#### 8B.1 The count round and compiled flavors

At a settled fixpoint, the count round enumerates each counted rule
instantiation once over full indices, without propagation. It then combines
those rule contributions with semantic foundation from VersionRecords.

| flavor | purpose | changes counts? |
|---|---|---:|
| normal | set-semantics construction | no |
| seeded/replay | set-semantics reconstruction | no |
| `_delta` | legacy positive set-only delta entry | no |
| `_maint1` | signed-support positive maintenance | yes |
| `_count` | full one-step enumeration | yes |

`_count` and `_maint1` must agree on operationalized instantiation
multiplicity. `_count` uses an all-full plan; `_maint1` uses the exact
positive occurrence partitions of §4.1. Neither optimization may replace
enumeration with an existence shortcut in counted code. `_delta` remains a
set-semantics compatibility flavor and is not a count oracle.

#### 8B.2 Lazy counting, epochs, and coverage

`settled` and `counted` are independent per VersionId. The first maintained
positive edit into an eligible uncounted cone establishes counts or routes to
clear-and-rerun. A future precise deletion has the same precondition before
its negative phase begins.

A correct count-establishment walk:

1. starts a fresh private epoch;
2. seeds direct assertions, active inheritance, and other semantic foundation
   from VersionRecords;
3. enumerates exactly the writer strata recorded for each version;
4. binds every stratum at its original pipeline environment;
5. audits closure and every live countable tuple for coverage; and
6. atomically commits the epoch and marks the covered VersionIds counted.

Failure, cancellation, mutation, overflow, or an uncovered writer discards
the entire epoch. It must not leave partially reusable sidecars. A mutation
invalidates the affected counted cone; it does not try to patch a count round
that was in flight.

During signed maintenance, underflow indicates stale/corrupt support and
overflow exceeds the version's count capability. In M1's positive-only path,
the set insertion result remains authoritative: invalidate count caches and
leave the graph uncounted until recount. Once negative maintenance is enabled,
the affected cone must instead rebuild its set materialization from the
authoritative final overlay before it can be called settled. Saturation is
forbidden because a later decrement could not recover the true zero
transition.

The current sidecar and count compiler flavor are useful substrate. M0.4
changes version attribution, adds complete foundation seeding, and makes the
walk transactional.

#### 8B.3 Counts are plan-relative and never persisted

The canonical unit of counting is a rule instantiation in the operational IR
after semantic source transforms (or-splits, demand rules, construction
staging) and recursive classification, but before physical join planning.
Physical temp decomposition and join order must be instantiation-bijective to
that IR; they do not get to redefine multiplicity. Counts can still change
when a compiler version legitimately changes the operational IR, so they are
not portable across compiler changes. No save, compression sample, checkpoint,
or link stores them. Replay reconstructs semantic materialization; the next
epoch reconstructs counts.

The cross-flavor contract is tested, not assumed:

~~~text
recount(base); maintain(delta stream) == recount(base plus stream)
~~~

Compare both tuple presence and every support component. Include or-splits,
temp splits, self-joins, wildcard projections, multiple occurrences of one
relation, and multiple writer strata.

For small fixtures, a deliberately slow reference enumerator joins the
canonical operational IR over the settled versioned materialization and
classifies each head contribution. That is the independent count oracle.
Comparing `_maint1` with a fresh `_count` round is a broader consistency test,
not a substitute for validating `_count` itself.

#### 8B.4 Side-channel-grown relations

There are explicit capability classes, not one heuristic bucket.

- Instantiation-deterministic diagnostics such as rule errors count through a
  signed sink when their row identity is a deterministic function of the rule
  instantiation.
- Value-keyed residue tables such as sequence/collection decompositions are
  excluded only when every read is anchored by a live value ID. Unanchored
  scans require eager liveness or rejection.
- External oracle answers are durable memo inputs, not rule derivations.
  Demand for an answer may retract; the memoized answer does not. Reclamation
  is an explicit GC/compaction policy, never a DRed side effect.
- `$stat_*` tables remain diagnostic and outside semantic maintenance.

Each relation kind declares its counting, deletion, replay, and GC capability.
Unknown kinds route to fallback.

#### 8B.5 Semantic foundation and the input ledger

The old single `input` bit is insufficient across inheritance, masks, imports,
links, roots, and program facts. The VersionRecord ledger is authoritative:

- direct input assertions are set-valued and idempotent;
- active inherited tuples seed exactly one nonrec support;
- inheritance masks suppress only that predecessor support;
- non-recursive program rules, including ground facts, are enumerated as rule
  support rather than relabeled as input;
- imports and links create direct assertions even when the tuple was already
  present by rule derivation; and
- a derived-only or absent tuple cannot be retracted as input.

The packed count word may retain a fast input-presence bit, but it is a cache
projection of this ledger, not the semantic source of truth. Presence is the
union of active direct/inherited foundation and positive rule support. The
implementation must report the distinction when an input retraction leaves a
tuple derivable.

#### 8B.6 Seeded replay and drift

Positive replay seeds are safe only when they are known subsets of the new
fixpoint. A negative mutable edit invalidates downstream samples, so dependent
layers replay unseeded. Recipe-internal deletions are already reflected in an
immutable descendant's sample.

An isolated stale table seed has no foundation or rule support and is caught
by the coverage audit. Mutually supporting stale seeds can still look counted:
a count round measures the supplied materialization, not its least-founded
history. Therefore full unseeded replay remains the strong drift oracle.
Counts must never be advertised as proving that arbitrary seeds are founded.

Cost policy is secondary. The first correct implementation always recounts an
uncounted eligible cone before precise deletion. A later cost model may choose
clear-and-rerun instead.

---

## 9. Active implementation plan

Milestone names M0 through M7 are retained for external references.

### Phase 0 — shipped semantic baseline

Shipped:

- **0.A:** stratified negation and polarity metadata;
- **0.B:** version registry, environments, re-entry, delta entry, routing;
- **0.C:** anchored batches, bulk payloads, recipe;
- **0.D:** rename, drop, flat link;
- **0.E:** save/load/freeze and workflow harness.

Explicit remaining limitations:

- direct link of a chained target is refused;
- eager version copies may be expensive;
- historical slot injection requires a descendant recipe rebuild; and
- precise negative maintenance is limited to M3's acyclic plain-table cones.

### M0 — count establishment

Shipped implementation substrate:

- **M0.1:** packed direct/nonrec/rec word and sidecar;
- **M0.2:** full count flavor and counting tasks;
- **M0.3:** count-state introspection, lazy walks, invalidation;
- **M0.4a:** evaluation-local VersionIds, persistent VersionKeys and
  descriptors, exact stratum read/write bindings, and JIT successor
  injection;
- **M0.4b:** baseline-aware direct/mask overlays, normalized recipes, and
  ground program facts classified as non-recursive support;
- **M0.4c:** explicit-VersionId scratch epochs, historical exact binding,
  authoritative semantic-writer coverage, explicit capability reporting,
  all-target audit/commit/abort, arithmetic invalidation, and failure retry;
- **M0.4d:** the default versioned META/recipe format, legacy ordinal fallback,
  save/load overlay round trips, EvaluationId isolation, and an independent
  alpha-renamed canonical-IR support-count oracle over the version and
  persistence matrix.

**M0.4 — complete (2026-07-12)**

The exit audit covers every currently recount-capable VersionId in the
relational, recursive, repeated-version, struct-diagnostic, negation, and
lattice-boundary fixtures, including injection, inheritance, masks,
rename/drop/redeclare, import/link, freeze, and save/load. The oracle fails
loudly on canonical IR outside its implemented surface, so a future relation
kind or operation cannot acquire count capability merely by falling through.

Writer-set equality is structural, not inferred from tuple presence. Count
epochs commit all targets or none; injected writer failure and test-width
overflow preserve the last committed counts and set content, and a clean
retry starts from empty scratch state. Underflow is not reachable in a
positive recount. M1 exercises its recoverable cache-invalidation path
directly; M3 exercises real user-driven decrements.

**Exit evidence:** the session workflow, versioned oracle, persistence,
writer-omission, failure/retry, and overflow tests pass together. This
certifies recount establishment; M3 separately certifies its precise-deletion
surface.

### M1 — positive signed maintenance

**M1 — complete (2026-07-13)**

Shipped:

- an evaluation-local `UpdateEpochId`, distinct from VersionId and VersionKey,
  with optimistic expected-revision admission and revision-stamped count
  state;
- signed contribution metadata (`support kind`, `sign`) and a dedicated
  `_maint1` flavor, while preserving `_delta` as the legacy set-only flavor;
- instantiation-injective counted temps and exact positive occurrence
  partitions, including simultaneous changes, self-joins, and repeated
  occurrences of one relation;
- an update-local VersionId-keyed transition journal that carries only
  absent-to-present tuples between SCC/stratum executions, while every rule
  contribution and direct-input assertion still updates support when its row
  is already live, without manufacturing a presence transition;
- positive maintenance across recursive SCCs, multiple strata, repeated
  flushes, and explicit inherited version edges for capability-certified
  positive-arity plain tables;
- an input-only `inject-version` operation and a separate
  `inject-and-reopen` semantic event whose new program outputs record explicit
  inheritance policy and semantic writer maps; and
- recoverable arithmetic/coverage failure: correct set content is retained,
  count caches are invalidated, and a later recount heals them. Stale expected
  revisions are refused before mutation.

The public routing boundary is deliberately narrower than the internal signed
representation. User retractions do not enter `_maint1`; certified acyclic
ones enter `_maint3neg`, while recursive negative propagation belongs to M4.
Structs, nullary relations, lattices, negation, and fallible diagnostic-head
cones also remain on fallback.

**Exit evidence:** for positive existing-slot edits and explicit inherited
reopen edges in the certified surface, maintained set content, support
components, and settled revisions equal a forced fresh version-local recount.
Forced overflow and signed underflow preserve set content, invalidate counts,
and recover after recount. Every retraction and unsupported topology still
routes to clear-and-rerun.

### M2 — retired as a separate milestone

SCC stratification, polarity metadata, and rule classification already exist.
Any remaining threading belongs to M1. The name remains as a compatibility
note only.

### M3 — acyclic deletion

**M3 — complete (2026-07-13)**

Shipped:

- baseline-aware removal of direct support and inherited support masks, with
  positive and negative transition journals separated by exact VersionId and
  synchronized across parallel head-maintenance tasks;
- a dedicated `_maint3neg` flavor implementing the negative occurrence
  partition `N before / DeltaMinus driver / O after`, including self-joins and
  repeated relation occurrences;
- checked negative non-recursive support maintenance, immediate point removal
  from every live index at zero support, and zero-sidecar-key removal;
- topological negative propagation across multiple acyclic strata, followed
  by the existing M1 positive phase for mixed flushes, all in one update
  epoch;
- manifest-level acyclicity certificates and routing restricted to counted,
  positive-body, positive-arity plain-table cones; and
- recovery through the normalized-overlay clear-and-rerun path if admission,
  arithmetic, or coverage validation fails. Recursive SCCs, negation,
  lattices, structs, nullary relations, and unsupported version topology never
  enter `_maint3neg`.

The user-visible capability is deliberately reported as conditional: table
storage supports point deletion, but the whole version cone must also satisfy
the topology and rule-kind certificate.

**Exit evidence:** deterministic cases cover support-only deletion, last-
support deletion, repeated occurrences, downstream propagation, mixed
negative/positive batches, inherited masks after inject-and-reopen, and
recursive fallback. Seeded differential signed-stream fuzzing compares every
materialized relation with a fresh unseeded recomputation and compares
maintained support rows with a forced recount after every flush.

### M6L — existing lattice relations, stratified deletion

Implement per-key contributor repair for existing Slog lattice values in
strictly lower-stratum use, backed by the hidden contributor-set relation of
§7A.2. Do not introduce SQL-style aggregate syntax here. At this point only
an acyclic/plain-table contributor cone is precise; a recursive producer
continues through fallback until M4T/M4S supplies its foundedness maintenance.

The initial admission ladder, contributor-cache lifecycle, replacement
transport, and executable fixture are pinned in
[m6l-contract.md](m6l-contract.md). Leaf repair and downstream stratified
propagation are shipped; every unlisted shape retains clear-and-rerun.

**Current slice:** root, acyclic, positive plain-table producers and their
acyclic positive plain-table consumers are implemented. The contributor
sidecar is established in a private count epoch, audited by reduction against
the visible payload map, and maintained by affected-key repair. Repairs are
coalesced per `(VersionId, key)` across the complete update epoch, then the
entry value is staged through the negative consumer pass and the final value
through the positive pass. `lattice-contributor-state` exposes certification
separately from legacy `count-state`.

**Exit:** precise deletion through stratified lattice cones; recursive lattice
cones still fall back.

**Exit evidence:** deterministic coverage includes min/max/flat payloads,
multi-column keys and map orderings, multiple producer strata, coalesced
no-change and absent/present transitions, save/reopen cache establishment,
transaction abort, writer audit, overflow recovery, and named fallback shapes.
Ten-epoch warm randomized streams under one, two, and eight workers compare
content and both sidecars with independent fresh recount sessions. A forced
pause test enters the replacement consumer phase and crosses the runtime
split-batch boundary before settling to the recount oracle.

### M4T — recursive deletion for positive plain tables

Implement §4.5–§4.7:

- candidate sets;
- negative-round live-index removal;
- foundation barrier;
- reseed;
- positive rebuild;
- version-local scheduling.

**Next implementation milestone.** Start with a deliberately narrow vertical
slice: a counted, positive-arity, positive-only recursive plain-table SCC
reached by a tip-local direct edit. Pin the symmetric unfounded cycle and the
over-delete/refound diamond before adding the candidate lifecycle. The first
slice retains clear-and-rerun for structs, lattices, negation, inheritance,
historical edits, and every uncertified downstream shape. Reuse M3's exact
negative occurrence partition and M1's counted positive rebuild; add only the
candidate-removal, foundation-barrier, and reseed semantics that recursion
requires.

**Exit:** the literature's recursive counterexamples and randomized cyclic
graphs match full recompute.

### M5, then M4S — struct identity and recursive struct deletion

M5 separates intern identity from live membership. M4S then admits struct
relations into the DRed capability set.

**Exit:** every deletion/reseed/relearn preserves struct IDs for all surviving
and reappearing content, with no dead row join-visible.

### M4N — precise stratified negation

Emit and maintain negated-body-driven variants from §0.8. Until this exits,
every negative edge uses clear-and-rerun.

### M6A — optional non-idempotent aggregates

Design and implement the separate stratified aggregate language from §7A.6.
This is not a prerequisite for M4T.

### M7 — recursive lattice/rank repair

Implement change splitting and regression repair for admitted recursive
lattices. Keep non-stable recursive aggregates rejected.

---

## 10. Testing strategy and gates

The current native count and session batteries remain regression gates.
New correctness tests use two independent oracles plus one cross-flavor
consistency check:

1. content equality with from-scratch replay of the equivalent versioned
   recipe;
2. count equality with slow enumeration of canonical operational-IR rule
   instantiations; and
3. maintained `_maint1` counts equal a forced fresh, version-local `_count`
   round.

Required suites:

- **Version locality:** later facts never create earlier-stratum
  instantiations; inheritance appears as nonrec.
- **Evaluation isolation:** two descendant recipe branches may materialize
  one ancestor VersionKey differently without sharing a runtime VersionId or
  sidecar.
- **Alias identity:** rename aliases share one VersionId and count state;
  drop/redeclare creates a fresh lineage.
- **Input overlay matrix:** add/delete sequences from absent, direct,
  inherited, masked, and derived-only states; save/load after every prefix.
- **Foundation sources:** flat roots, program facts, batches, imports, links,
  and inheritance.
- **Count transaction:** interrupt or fail a recount after one writer, retry,
  and compare with a fresh daemon.
- **Count arithmetic:** force recount overflow with test-width counters; once
  signed decrements exist, force underflow too. Assert no invalid epoch commits
  and fallback content matches the oracle.
- **JIT mutation modes:** an edit preserves VersionId/VersionKey and advances
  only the settled revision; injection allocates a new input VersionId/key;
  inject-and-reopen records explicit downstream output slots, inheritance
  policy, and semantic writers.
- **Exact partitions:** simultaneous changes to two relations, two
  occurrences of one relation, self-joins, cartesian joins, or-splits,
  wildcards, and staged temps.
- **Candidate lifecycle:** multi-round recursive over-deletion where a later
  delta would double-decrement if an earlier candidate remained visible.
- **Foundedness:** symmetric cycle, source plus edge cycle, SCC bridge,
  diamond/refound, and cyclic transitive closure.
- **Struct identity:** delete, reseed, reach zero, relearn, save/freeze.
- **Negation:** +B retracts a negated consequence and -B adds it.
- **Lattices:** contributor deletion changes or removes the joined value.
- **Compression:** every coverage percentage, positive seeds, negative
  mutable edits, and strong unseeded verification.
- **Nullary:** facts and recursive/negated consumers of arity-zero relations.
- **Threads and pauses:** each signed case under multiple thread counts and
  forced suspension boundaries.

Performance gates begin only after correctness:

- work proportionality for delta entry;
- count-round instantiation volume;
- candidate-set size versus cleared cone size;
- version copy amplification;
- sidecar and contributor-state memory.

---

## 11. Future directions

- persistent or copy-on-write master indices for long W9 pipelines;
- disk spill for cold historical versions;
- content-addressed struct identity;
- DBSP-style nested incremental recursion;
- differential-dataflow-style timestamped traces;
- provenance-rich explanations and proof witnesses;
- selected persisted count checkpoints as an optional, compiler-stamped
  accelerator only if measurements justify them.

---

## 12. References

- Gupta, Mumick, Subrahmanian. Maintaining Views Incrementally. SIGMOD 1993.
- Hu, Motik, Horrocks. Optimised Maintenance of Datalog Materialisations.
  AAAI 2018.
- Motik, Nenov, Piro, Horrocks. Incremental Update of Datalog
  Materialisation: The Backward/Forward Algorithm. AAAI 2015.
- Motik, Nenov, Piro, Horrocks. Maintenance of Datalog Materialisations
  Revisited. Artificial Intelligence 269, 2019.
- Green, Karvounarakis, Tannen. Provenance Semirings. PODS 2007.
- Abo Khamis, Ngo, Pichler, Suciu, Wang. Convergence of Datalog over
  (Pre-)Semirings. PODS 2022 / JACM 2024.
- Ross, Sagiv. Monotonic Aggregation in Deductive Databases. PODS 1992 /
  JCSS 1997.
- Zaniolo et al. Fixpoint Semantics and Optimization of Recursive Datalog
  Programs with Aggregates. TPLP 2017.
- Budiu et al. DBSP: Automatic Incremental View Maintenance for Rich Query
  Languages. VLDB 2023.
- McSherry et al. Differential Dataflow. CIDR 2013.
