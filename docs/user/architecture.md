# How Slog runs

Slog is a source-to-native compiler in front of a persistent parallel fixpoint
runtime. The Racket front end does whole-program analysis and generates C++.
The long-lived C++ daemon owns values, relations, indexes, database versions,
and rule execution.

This page gives enough of the design to read compiler output, reason about
performance, and make a safe extension. It is not a line-by-line internals
manual.

## Main components

```text
repl/src/main.rs and repl/src/ui/
  native terminal lifecycle, event loop, fixed layout, and rendering

repl/src/app.rs, editor.rs, backend.rs, protocol.rs
  client state/editor, Racket child lifecycle, and framed loopback TCP

compiler/repl.rkt
  private interactive server and persistent compiler/session/daemon owner

compiler/run.rkt
  one-shot batch command line, configuration, and database commands

compiler/modules.rkt
  include/run loading, declarations, manifests, demand and collection setup

compiler/compile.rkt
  checking, stratification, planning, lowering, C++ jobs, cache metadata

compiler/runslog.rkt
  one-shot daemon lifecycle, compile/run overlap, persistence and replay

compiler/session.rkt
  resident incremental sessions and versioned program segments

compiler/actions.rkt
  small generated plugins for database operations and queries

daemon/slogd.cpp and daemon/daemon.h
  path-per-line plugin host and pipeline control

daemon/database.h
  relation storage, fixpoint phases, versions, persistence, statistics

daemon/operators.h, prims.h, arena.h, seq.h, oracle.h, smt.h
  generated-rule operators, primitives, canonical values, and external work
```

## From source file to program tree

The parser records source provenance on expressions so later errors and rule
statistics can refer to `file:line`.

Module loading follows two edges:

- `include` combines files into one program node;
- `run` creates a prerequisite program node that will reach fixpoint first.

The loader resolves relative includes from the including file, then tries the
repository `lib/` directory. It rejects `run` cycles and linearizes the program
tree in dependency order.

Each program is compiled against a manifest of relations already in the live
database: an input database plus relations declared by earlier `run` stages.
The manifest records relation kind, arity, and lattice specification where
needed. Source declarations still supply full field types.

For compressed replay, the same loader can read source from an in-memory
snapshot rather than disk. Save-time capture records the closure of included
and run files.

## Declarations and desugaring

The module pass builds a type environment for tables, structs, unions, enums,
demands, lattices, built-in primitives, and error relations.

Surface features are reduced to a smaller relational core:

- Head-only rules become empty-body rules.
- Left arrows are normalized to body-to-head direction.
- Body alternatives become separate rule paths.
- Nested constructor patterns become joins and equality constraints.
- Bracket patterns become native sequence checks, indexing, and slicing.
- Brace construction becomes native or compatibility collection calls.
- A demand becomes a request struct, answer table, ask rules, answer rules,
  and caller resume joins.
- A lambda becomes an interned closure and generated apply demand.
- An external demand keeps the same request/answer shape but marks its answer
  table as oracle-owned.
- Set/map lattice declarations produce `R_has` and `R_at` decomposition views.

The important design choice is that these features do not require a separate
runtime evaluator. They end as relations, rules, primitive calls, and a small
number of specialized operators.

## Type checking and residual checks

The type checker unifies variable types across body sources, primitive
signatures, patterns, constructors, and head sinks. Struct and union types are
nominal. Native collection roles carry element/key/value constraints through
the typed program even though the runtime word does not encode them.

`any` and overlapping unions deliberately permit a value whose exact runtime
member is not known statically. When such a value flows into a narrower head
column, the compiler emits a residual tag check just before the head writes.

If the check fails, the entire deduction is abandoned and a
`malformed_deduction` value is emitted into the built-in error family. Safe
head writes have no residual check or cost.

Primitive type dispatch can similarly turn invalid dynamic arithmetic into a
recoverable error fact. Partial absence remains a failed match.

## Dependency graph and strata

The compiler builds a relation dependency graph from rule bodies and heads.
Mutually recursive positive dependencies form strongly connected components.
Those components are ordered into strata.

Positive recursion stays in one stratum and runs to a fixpoint. A negative edge
requires the read relation to be completed earlier. A cycle containing
negation is rejected.

Lattice dependencies add another concern: a relation value can ascend while
its component is running. The lattice checker tracks a taint from lattice
reads through computations and allows only operations proven monotone in the
relevant argument. An unrestricted observation is scheduled after closure
when the dependency graph permits it, or rejected when it participates in an
unsafe cycle.

The compiler may merge compatible SCCs into a linear stratum sequence to
reduce plugin and reload overhead while preserving dependency order.

## Planning and indexes

A rule body is a join plan. The planner chooses a clause order based on which
variables are bound and which relation indexes can be used. Primitive
computations that feed a guard or key are ordered before their consumers.

For each relation read, generated code registers the required index projection.
An index stores rows in a column order suited to its joins. The runtime may
maintain several indexes over one logical relation.

The compiler also creates supplementary relations for some demand resume
shapes, semijoin filters for recursive joins, and dynamic relation metadata
used later by the session cone planner.

A warning about an unkeyed co-recursive scan means a rule rereads a whole
relation in an iteration because no column was bound at that join point. It is
often a real performance problem: bind a key earlier, split the rule, or use a
demand shape with a narrower request.

## Semi-naive fixpoint execution

Naive recursive evaluation reruns every rule over every known row each round.
Slog uses semi-naive variants. For a rule with recursive body relations, a
generated variant chooses one relation's new delta as its driver and reads
settled or stage-appropriate rows from the others.

The runtime partitions work so a satisfying instantiation is attributed to
one delta position rather than firing once for every recursive input that
happened to be new. `$stat_fires` exposes generated variants and supports an
exact-once audit on small tests.

A stratum iteration moves through coordinated phases:

1. read indexes and execute rule continuations;
2. collect candidate output batches per worker;
3. intern newly constructed values and normalize rows;
4. merge, deduplicate, and reorganize relation indexes;
5. publish the next delta and decide whether another iteration is needed.

OpenMP workers run tasks inside those barriers. Rule code avoids a lock per
row; it writes to task-local or worker-local batches and merges at phase
boundaries.

Fixpoint is reached when there is no new relation delta and no external oracle
work outstanding.

## Generated plugins

Each lowered stratum becomes one or more C++ translation units linked into a
shared object. The plugin exports:

```cpp
extern "C" void slog_plugin(slog::Daemon*);
```

Calling it registers relation/index requirements, task objects, oracle
bindings, and stratum metadata with the daemon, then starts or advances that
stratum.

The plugin is specialized to the program: arities, column permutations,
primitive calls, constructor IDs, join continuations, and head writes are
compiled into C++. There is no bytecode interpreter in the hot rule loop.

The daemon protocol itself is one line containing a plugin path. Action
plugins use the same ABI for operations such as open, import, CSV dump, sizes,
lookup, and save.

Generated plugins include daemon headers and depend on their layouts and
symbols. The build fingerprint includes those headers, and the launcher
rebuilds a daemon older than its source. A stale daemon/plugin pair is an ABI
problem, not merely missed optimization.

## Compilation cache and tiering

Stratum jobs are content addressed from normalized program information, type
environment, input manifest, lowering choices, and daemon-header fingerprint.
Generated source, object files, shared objects, and sidecar manifests live
under `build/`.

In `tiered` mode, independent stratum builds enter a bounded Racket worker
pool. An `-O0` plugin can start while other strata and `-O2` objects compile.
At a clean iteration boundary, the daemon can replace a running stratum's
tasks with the optimized plugin. If a small stratum finishes first, its `-O2`
build is simply cached for the next run.

Object writes and plugin publication use temporary files and atomic renames so
parallel Slog processes can share the cache safely. Claim-marker timeouts
recover background builds abandoned by a dead process.

## Runtime values

Most Slog values fit in one 64-bit tagged word. The tag distinguishes small
integers, floats, interned strings, structured references, bignums, native
collections, native sequences, and special lattice/error sentinels.

### Strings and bignums

Small strings are interned directly. Larger strings can use a canonical rope
in the sequence arena. String primitives hide the representation and count
code points.

Small signed integers use an immediate representation. Larger integers are GMP
values interned by numeric content. Arithmetic returns the small encoding again
when a result fits. Bit and total-table caps prevent one rule from allocating
unbounded bignums without a queryable failure.

### Structured values

Each struct constructor has a runtime struct relation. A content row is
interned and assigned an ID; user relations store the compact reference. Equal
constructor and field content returns the same ID within a database.

Nested syntax trees therefore form hash-consed DAGs. Copying a whole subtree
into another relation copies one word. Pattern matching follows registered
struct indexes to its fields.

### Native lists and collections

Lists use canonical chunked Merkle sequences. Concatenation and slicing can
share tree structure instead of copying every element. Point updates return a
new root.

Sets and maps use a canonical Patricia-style collection arena. A set is a map
from elements to a unit value at runtime; static types keep map and set
operations separate. Equal contents have equal canonical roots.

Canonical values make equality cheap, but construction, traversal, and
conversion still cost work proportional to affected structure. Interning is
not magic free memory; shared roots and nodes remain live as long as the
database needs them.

## Relations and lattices

A plain table stores a set of normalized rows. Struct relations additionally
own constructor interning. A lattice relation stores one joined payload per key
and carries its value specification into runtime registration and on-disk
naming.

Lattice joins happen at insertion/finalization. A proposal can be novel even
when its key already exists if it improves the payload. Downstream deltas
receive the new joined state needed by semi-naive propagation.

Collection lattice joins need their recursive value specification at runtime;
the collection word alone does not say whether a collision means min, max,
flat conflict, set union, or nested map join. That is why `cjoin` is lowered as
a spec-aware operator rather than an ordinary dispatcher in `prims.h`.

## Demand implementation

For:

```slog
demand (f A B) C
```

the compiler creates a request struct `f(A,B)` and table `f_ans(f,C)`. A call
constructs/interns the request. Generated ask rules make relevant answer rules
active for that request; resume rules join new answer rows back to suspended
caller context.

This is tabling through ordinary relations. Recursion terminates when request
and answer spaces stop growing. Calls are not a hidden C++ stack, so mutually
recursive and nondeterministic demands compose with the same fixpoint engine.

Lambdas generate closure constructors containing captured free variables and
apply demands that unpack the closure and evaluate its body.

## External oracles

An `extern` declaration creates the same request/answer relations but prevents
Slog rules from writing the answer table. Generated strata bind the request
relation to a named daemon oracle.

Dispatch runs in a safe read phase, decodes the request payload, and serializes
everything a worker will need. `Oracle::solve` runs in a separate thread pool
and must not touch the database. It returns a recipe containing an integer code
or map/set entries. Harvest runs back on a database-safe phase, interns values,
and emits answer rows through the normal relation path.

The registry tracks answered and in-flight demand IDs across strata. Reloaded
or persisted answer rows seed that state so the same request is not solved
again.

SMT registers three instances of one oracle implementation: verdict, model,
and core modes.

## Persistent storage

The daemon writes each relation and intern arena in a canonical binary layout.
Directory names encode enough relation kind, arity, struct ID, and lattice spec
for the compiler and daemon to reconstruct registrations on load.

An exact open materializes relation indexes immediately. Before the next
stratum, the daemon can reload all stored content as iteration-zero input so
new rules see it as existing data.

Managed compressed databases add compiler-side metadata:

- ordered input links and content stamps;
- EDB/IDB relation partitions;
- retained fraction and sampling seed;
- stored source closure or session recipe;
- complete content signatures;
- edits and externalized batch payloads;
- pinned oracle relations.

Replay builds the input DAG bottom-up, imports seeds, and runs stored sources.
The signature is content based rather than internal-ID based, so a valid replay
may assign different struct IDs and still verify.

## Resident sessions and versions

A session retains strata and the daemon instead of exiting after one program.
Before a new program segment writes a relation, the daemon creates a copied
physical version and binds the name to it at a new pipeline position. Older
versions remain addressable.

The compiler writes a sidecar manifest for each stratum with dynamic reads,
heads, and monotonicity-relevant dependencies. Session updates use these
manifests to compute a downstream cone.

Capability-certified positive plain-table changes use counted maintenance,
including across recursive SCCs. Counted acyclic plain-table deletions use the
signed M3 path. Counted plain-table cones containing recursive SCCs use the
M4T path for tip-local deletions: a DRed sweep over-deletes each stratum on
foundation loss, a reseed restores candidates with surviving recursive
support, and the positive phase rebuilds the rest. Edits targeting a
recursive head relation apply through a foundation-aware overlay that enters
candidacy directly, and inherited chains ride the same route (a mid-cone
version edge diverts to the anchored walk). M6L extends that machinery
to an acyclic root lattice by
counting full `(key, payload)` contributors, repairing the joined payload for
affected keys, and propagating one coalesced old/final replacement through
acyclic positive plain-table consumers. Unsupported changes--including
recursive lattice producers or consumers, negation, downstream lattice
writers, structs, and nullary relations--clear affected
derived versions and rerun their suffix. Anchored
changes temporarily bind strata to the environment at an old position and
replay later events in order.

The save format records persistent VersionKeys and a recipe rather than
serializing only today's final name bindings. Legacy ordinal recipes remain
readable. A later loader can reproduce the history through the same session
machinery.

## Errors and observability

Generated rule code increments task-local fire counters before head
deduplication and publishes them at fixpoint. The daemon also records stratum
iterations/time and output relation sizes. These diagnostic relations are
excluded from semantic persistence.

Recoverable errors use a pending per-worker slot. A fallible primitive stores
an error code and operands, returns a sentinel, and generated code turns that
slot into an interned error struct with source location. The deduction stops,
but the error relation grows through the normal fixpoint.

Memory and time slicing happen at clean task/iteration boundaries. Read-only
actions can inspect a suspended database. Actions that would reload or clear
indexes are refused until the stratum reaches fixpoint, protecting parked task
state.

## A performance checklist

When a Slog program is slower or larger than expected, check in this order:

1. Relation sizes: did the program derive the intended state space?
2. Demand request and answer sizes: did a narrow query become a broad one?
3. Stratum iteration counts: is information moving only one edge per round?
4. Fire counts: which source rule and generated variant dominates work?
5. Join keys: is a recursive relation scanned without a bound column?
6. Value growth: are rules building fresh integers, trees, lists, or map keys?
7. Lattice height: how many improvements can one key make?
8. Solver requests: are path conditions canonical, or are equivalent formulas
   being asked under different shapes?
9. Replay policy: is a tiny compressed layer causing a large load-time
   recomputation?

Then look at generated C++ or daemon profiling. Most large wins come first
from changing the relation or demand shape, not from micro-optimizing a
primitive.
