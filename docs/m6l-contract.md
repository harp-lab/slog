# M6L stratified lattice-deletion contract

**Status:** implemented and hardened contract for the first two M6L vertical
slices.
`incremental.md` remains normative; this file pins the narrower admission and
state lifecycle needed to implement §7A without weakening fallback.
This slice is closed for now; the implementation queue resumes at M4T as
recorded in `incremental-status.md`.

## Semantic state

For each lattice VersionId `L`, maintain a conceptual hidden set relation

```text
Contrib(L) = { (key..., payload) }
```

Each contributor row has the ordinary packed `input | nonrec | rec` support
word. Multiple rule instantiations may support the same contributor row; the
row remains live until its last support disappears. The visible lattice entry
for a key is the semilattice join of all live contributor payloads for that
key. Foundedness of contributor rows and reduction of their payloads are
separate state.

The physical implementation may use a hidden relation or a typed sidecar, but
it must preserve the same VersionId, writer, count-epoch, and coverage
invariants as an ordinary hidden relation. Contributor state is a recomputable
cache and is not serialized as semantic truth. A load must establish it from
the exact historical writers before precise admission, or fall back.

## Replacement transition

After one signed contributor phase, repair each affected key exactly once:

- unchanged join: publish no visible transition;
- absent to present: publish `DeltaPlus(key, new)`;
- present to absent: publish `DeltaMinus(key, old)`;
- changed payload: atomically publish the replacement pair
  `DeltaMinus(key, old)` then `DeltaPlus(key, new)` in the same update epoch.

The visible payload map, contributor state, replacement journal, and settled
revision must agree at commit. Arithmetic, coverage, writer, or repair failure
invalidates the cache and completes through clear-and-rerun.

## Admission ladder

M6L grows through two explicit slices.

1. **Leaf repair.** Admit a root lattice version whose producers form an
   acyclic, positive, positive-arity plain-table cone and whose visible lattice
   has no downstream reader in the affected cone. Maintain contributors and
   repair only the visible payload map.
2. **Stratified propagation.** Admit acyclic positive plain-table consumers of
   the closed lattice value. Stage the replacement pair through the existing
   negative-then-positive schedule.

Until a later expansion is separately certified, fall back for:

- a same-SCC or otherwise recursive lattice producer;
- a recursive downstream consumer (requires M4T for its negative half);
- negation over the changing lattice key;
- struct, nullary, diagnostic/fallible, or unsupported side-channel cones;
- a predecessor/inheritance edge whose contributor state cannot be exactly
  established; and
- historical/back-anchored edits.

Direct lattice assertions and contributor inheritance are not part of these
two slices. The session overlay API continues to refuse direct lattice edits;
inheritance and historical shapes use fallback until their foundation and
version-copy contracts have dedicated tests.

## Required fixtures

The leaf executable fixture is `tests/session/m6l_leaf.slog`:

```text
offer(key, value) -> best(key, min value)
```

It must exercise:

- removing a losing contributor without changing `best`;
- removing the winning contributor and regressing to the next value;
- removing the final contributor and deleting the visible key;
- two derivations supporting the same `(key, payload)` contributor;
- a mixed remove/add that publishes one settled replacement; and
- maintained contributor state equal to a fresh contributor recount.

`tests/session/m6l_stratified.slog` adds the `reported` consumer. Slice 2
settles every producer phase before staging the coalesced epoch-entry row
negatively and final row positively. `tests/api/lattice-stream-fuzz.rkt`
retains a warm maintained session for ten epochs and compares every flush's
content and sidecars with an independent fresh recount session.

The permanent hardening matrix additionally covers:

- max and flat payloads, multi-column keys, reversed consumer orderings, and
  multiple producer strata;
- net-no-change and absent/present transitions;
- save/reopen from an uncertified contributor cache followed by exact repair;
- recount abort, semantic-writer omission, overflow fallback, healing, and
  next-epoch replacement-journal hygiene; and
- named fallback for recursive producers and consumers, negated consumers,
  downstream lattice writers, inherited successors, and direct overlay
  refusal.

## Concurrency and observability

Affected-key interning and replacement journals are shared scheduling state
and must be synchronized, just like M1/M3 transition journals. Runtime
capability reports distinguish `lattice-contributor-recount`; session route
messages distinguish stratified producer/consumer repair from named fallback.
Storage-class inspection is not sufficient admission.

The runtime reports `(reason lattice-contributor-recount)` only as a
conditional local capability. The session route additionally proves the
complete leaf or stratified cone shape and reports distinct producer/consumer
phases for slice 2.
`(lattice-contributor-state ...)` reports version-local cache certification;
legacy `(count-state ...)` remains table/struct-only.

Deterministic leaf, stratified, shape, ordering, persistence, recovery, and
fallback cases are executable gates. Randomized replacements run ten warm
epochs under one, two, and eight workers against independent fresh recount
oracles. Forced pause/resume is attributed to the replacement consumer phase
and crosses the runtime split-batch boundary; cold-versus-warm performance and
contributor-storage reporting remain separate gates. The focused hardening
suite is `tests/incremental-stress.sh`; recursive consumers remain a named
fallback boundary for M4T/M7.
