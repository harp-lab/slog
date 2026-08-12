# Runtime statistics: current tables and the target observation model

2026-07-13. This document has two deliberately separate parts:

- **Shipped today:** the daemon-owned `$stat_*` relations, exact-once fire
  audit, and performance gate.
- **Target design:** a reserved `stats` namespace whose rows have stable
  evaluation, program-instance, stratum-execution, rule, and relation-version
  identities.

The target is a design, not current syntax. Namespaced module instances are
described in [modules.md](modules.md). Statistics motivate namespaces, but
they are not ordinary instantiated Slog modules.

## 1. What ships today

Every run publishes three daemon-owned relations unless
`SLOG_NO_STATS=1` is set:

| relation | columns | publication point |
|---|---|---|
| `$stat_fires` | rule-location `str`, variant `str`, count `int` | each stratum fixpoint |
| `$stat_fixpoint` | SCC/push position `int`, stratum hash-name `str`, iterations `int`, microseconds `int` | each stratum fixpoint |
| `$stat_size` | relation name `str`, tuples `int` | CSV dump |

The names in this table describe the implementation exactly. In particular,
the first column of `$stat_fixpoint` is called `scc` in the code, but is the
daemon-assigned push position of the emitted runtime stratum. A runtime
stratum is currently a dependency level and may contain several independent
relation-graph SCCs.

These relations appear in `--debug-dir` CSV output and are readable through
API `lookup`. They are intentionally outside ordinary program semantics:

- no program declares them, and Slog rules cannot read them;
- BIN saves exclude them, because timing and execution history are not
  settled database contents;
- golden comparisons exclude them;
- `$stat_size` excludes the `$stat_*` relations themselves but includes
  internal `$seq_*` and `$sup*` machinery.

The task-local fire increment remains enabled when publication is disabled.
This keeps the hot path and audit behavior consistent.

### 1.1 Fire counts and the exact-once audit

`$stat_fires` counts rule **instantiations**: one count for each satisfying
body assignment, before head deduplication. A multi-head rule counts once.
Generated read tasks accumulate into a local `u64` and flush on completion or
slice-pause, so pause/resume does not lose work.

The variant says how the generated task was driven:
`delta:<relation>`, `all:<relation>`, or `once`. Supplementary, demand, and
other generated rules retain the source rule's location and differ by
variant.

This is an important correctness observable for exact semi-naive evaluation.
Set semantics hide a duplicate firing because the duplicate head tuple is
discarded. Counting maintenance would instead turn that firing into excess
support. The small `tests/stat_*.slog` programs therefore compare counts with
hand-derived goldens and run twice to detect schedule-dependent totals.

The current identity is intentionally weak: a basename-and-line location plus
a variant is adequate for these isolated tests, but not for a module
instantiated twice or a source rule emitted into more than one execution. The
target model below fixes that rather than stretching `rule-loc` into an
accidental global key.

### 1.2 Performance regression gate

`bench/regress.sh` covers the shapes most sensitive to maintenance and
semi-naive changes: supplementary-keyed demand joins, long sequential folds,
the R7RS demand interpreter, and 0CFA. It checks:

- exact per-stratum iteration counts, which are deterministic and catch new
  lag or refiring; and
- total runtime against machine-local baselines, with a configurable budget.

Re-baselining should accompany an intentional performance change and record
the reason.

### 1.3 Unkeyed recursive-scan warning

The compiler warns when a recursive delta variant joins a co-recursive
relation with no bound column. Such a join scans the whole relation on every
round. Demand machinery is exempt where the scan is the required broadcast
semantics. This warning is a static companion to the dynamic work counters.

### 1.4 Current implementation map

- `daemon/database.h`: fire aggregation, stats relation creation,
  fixpoint/size publication, and BIN-save exclusion.
- `daemon/daemon.h`: publication at fixpoint.
- `compiler/emit-cpp.rkt`: task-local fire counters and the recursive-scan
  warning.
- `tests/stats-tests.sh`, `tests/stat_*.slog`, and
  `tests/stats-expected/`: exact-once audit.
- `bench/regress.sh` and `bench/regress/`: performance gate.

## 2. Statistics are observations, not program facts

A statistic is produced at an evaluation boundary and describes an execution
that has just happened. That makes it different from an ordinary relation
derived inside the active stratification DAG.

The useful rule is:

> A boundary observer is semantics-preserving when it reads only committed
> state at that boundary and writes only diagnostic state that the active
> program does not read back.

There are two safe forms:

- A **monitor** samples each boundary and writes a sink. Runtime statistics
  are a stratum monitor.
- A **scan** carries private accumulator state from one boundary to the next,
  but that state remains private to the scan. The accelerator quota reservoir
  is an internal example at round scope.

If the main program reads the result back, it is no longer observation. It is
a real dependency: positive feedback may merge SCCs, and negative or other
non-monotone feedback may require a later stratum or be rejected. A namespace
does not change this law.

The runtime has several nested observation scopes:

| scope | sequence |
|---|---|
| iteration | semi-naive rounds inside one fixpoint |
| stratum execution | dependency levels in one program instance |
| compression/replay round | outer accelerator and replay work |
| session evaluation | edits, re-entry, and maintenance executions |

A future lifecycle API could let users attach monitors or scans to these
events. It should be designed independently from `instantiate`: module
instantiation is lexical composition, whereas a monitor is temporal
attachment to runtime events.

No lifecycle-monitor syntax is part of the module proposal. Ordinary
post-analysis reporting is already expressed by a later `run` that reads a
committed database. A new attachment surface is needed only if users must run
custom logic after each internal iteration or stratum, where no ordinary Slog
pipeline boundary exists. Built-in daemon statistics can cover the initial
need; syntax should wait for a concrete user monitor. The first user-facing
step is instead the small event/watch/breakpoint socket protocol described in
[repl.md](repl.md): it observes finalized barriers and remains outside program
semantics.

A module run may execute against a prepared boundary overlay and later commit
or abort it. Execution statistics are still truthful for an aborted run, but
they must record the input BoundaryKey, proposed output BoundaryKey, and final
status. Only a committed output receives a normal database handle or a
settled `stats.size` snapshot. This keeps observability from accidentally
publishing a half-computed database.

### 2.1 What users can express with ordinary sub-databases

A user can create an ordinary `profile.*`, `audit.*`, or `history.*`
sub-database, carry it through a session pipeline, and run programs that add
rules or facts to it. Namespace bindings let a generic stage call that bundle
`out` internally while the live database calls it `X`. Each temporal program
segment that writes it creates the ordinary successor relation versions.

This naturally expresses stage-level summaries and accumulators over settled
inputs. For example, after an analysis reaches fixpoint, a later program can
read `model.*` and write `audit.*`; another later program can extend those
audit relations. It can also read a frozen/exported `stats.*` snapshot and
derive reports from it.

It cannot, as an ordinary rule in the observed program, discover facts the
runtime has not exposed: rule fires, elapsed time, iteration deltas, or the
exact moment each internal stratum commits. Putting such a rule textually
between includes does not create a boundary; all included rules are
stratified together. Reading a live monitor output back into the observed DAG
would also change the dependency graph.

Thus the *output* of a user monitor can be an ordinary namespaced sub-database,
and ordinary later pipeline programs can process it. Supplying the monitor's
per-iteration or per-stratum event source requires a small lifecycle feature
with committed-snapshot semantics. Built-in stats is privileged precisely at
that event-source seam, not because its result needs a special kind of table.

### 2.2 Sink peeling and merge diagnostics

This distinction can also improve ordinary programs. A relation used only as
an output sink can accidentally tie otherwise independent SCCs together when
it appears as an additional head of rules in each component. Under set
semantics, the compiler can often split those sink deductions from the other
heads and publish them at the corresponding committed boundaries without
changing the result.

The dependency analysis already has most of the evidence needed:

- if the cross-cutting relation is never read by the active DAG, it is a
  candidate monitor/sink and automatic peeling can be semantics-preserving;
- if any rule reads it back, the cycle is real and must remain. The compiler
  should report the read-back edge and source location that caused the merge;
- under negation or another non-monotone use, ordinary stratification rules
  still apply. Calling the relation a monitor cannot waive them.

This optimization is not necessary for namespaced modules, but the diagnostic
would be valuable before it: it explains whether a large emitted stratum is a
true recursive component, same-level batching, or avoidable sink coupling.

## 3. Why there should not be a `stratum7.fires` database

It is tempting to imagine a stats module embedded into every SCC, producing
names such as `stratum7.fires`. That combines two unlike identities:

- a namespace names a lexical/schema owner such as `cfg_scc` or `syn`;
- `7` is one evaluation's scheduling position.

Positions shift when a program is prepended, strata are regrouped, a facts
stratum is inserted, or a historical stratum is re-entered. One runtime
stratum can also contain rules from several module namespaces, and independent
SCCs at the same dependency level can be compiled together. There is no
single lexical module whose namespace it should own.

Dynamic namespaces would also duplicate the same stats schema many times and
make global questions awkward. The better representation is one reserved
schema with execution identity in columns:

```text
stats.fixpoint(..., execution, position, ...)
stats.fires(execution, rule, ...)
stats.iter(execution, iteration, ...)
```

An instance-oriented report can be a query or API view over those rows. It
need not be a separately materialized `cfg_scc.stats.*` database.

## 4. Identity model for the target `stats` namespace

Ordinals and display names are useful labels but bad keys. The target should
make the following identities explicit.

### 4.1 EvaluationId

One evaluation of a session recipe. It distinguishes two runs of the same
program and prevents set semantics from collapsing identical observations
from separate runs. Test harnesses may normalize it.

### 4.2 ProgramInstanceKey

A stable logical node in the pipeline recipe: a root program, a `run`
prerequisite, or a session-run segment. It is minted and stored with the
recipe, not reconstructed from the node's current numeric position.

Prepending a saved program from `data/` changes later display positions but
does not rename existing instance keys. Using the same source twice creates
two keys. This is the identity that prevents two occurrences of an identical
compiled program from being confused.

### 4.3 ModuleInstanceKey

A stable lexical occurrence inside the program instance's expanded module
tree. It distinguishes two `instantiate` occurrences of the same source and
provides the namespace/provenance component of rule identity. It does not
create another temporal pipeline position.

### 4.4 StratumKey and StratumExecutionId

`StratumKey` identifies the canonical qualified rule/member set compiled as a
runtime stratum. It can be content-addressed. It describes code, not an
execution.

`StratumExecutionId` identifies one execution occurrence and should derive
from at least:

```text
(EvaluationId, ProgramInstanceKey, StratumKey, re-entry generation)
```

Pipeline position and local dependency level remain columns for ordering and
display. They are not uniqueness constraints.

### 4.5 RuleKey

A stable source-rule occurrence plus its module instance. Two instances of
the same source line therefore have distinct keys; all generated variants of
one instantiated source rule share the key. Location and normalized rule text
are metadata, not identity.

### 4.6 VersionKey

Relation sizes and maintenance work should name the exact materialized
relation version already modeled by the incremental runtime's `VersionKey`,
not merely the latest spelling `R`. Rename aliases can share one version, and
the same qualified name can have several pipeline versions.

### 4.7 BoundaryKey, TypeKey, and runtime IDs

A qualified display name is meaningful only at a `BoundaryKey`. Statistics
that record a name should therefore also record the observation boundary; the
`VersionKey` remains the absolute relation-slot identity. This lets a report
say that one version appeared as `X.edge` at an earlier boundary and `Y.edge`
after a rename without inventing two relation identities.

When type/interner statistics are added, they should key nominal struct types
by `TypeKey`. The daemon's 14-bit SID and numeric `VersionId` are
evaluation-local payloads useful for low-level debugging, never durable keys.
See [modules.md](modules.md) and [repl.md](repl.md).

These keys solve the `stratum3` problem without deduplication tricks. If a
prefix program is inserted, positions change. If a program is genuinely
replicated, instance/execution keys differ. If an old stratum is re-entered,
the generation differs while its original binding position remains visible.

## 5. Target schemas

Exact column encodings can evolve, but the relational shape should be close
to the following. `exec` abbreviates `StratumExecutionId` and `eval`
abbreviates `EvaluationId`.

| relation | key columns | payload |
|---|---|---|
| `stats.fixpoint` | `eval`, `exec` | program instance, input/proposed-output boundary, final status, stratum key, pipeline position, local level, generation, iterations, microseconds |
| `stats.fires` | `exec`, `rule`, `variant` | instantiation count |
| `stats.iter` | `exec`, `iteration` | delta tuples, microseconds |
| `stats.size` | `eval`, `boundary`, `version` | qualified display name, tuple count |
| `stats.work` | `exec`, `rule`, `variant` | fires, net-new tuples |
| `stats.probes` | `exec`, `rule`, `variant` | rows probed, rows matched |
| `stats.phase` | `exec`, `iteration`, `phase` | microseconds |
| `stats.memory` | `eval`, `exec` | peak RSS, tuple/interner/arena counts |
| `stats.index` | `eval`, `version`, `index-spec` | indexed tuples and storage metadata |

Rule, program-instance, stratum, and relation-version metadata should be
available through introspection tables or API records so fact tables do not
repeat long paths and source text.

The namespace has policy:

- `stats.*` is runtime-owned and reserved;
- it is ephemeral and excluded from settled BIN databases and ordinary
  goldens;
- deterministic counter payloads remain audit-testable after normalizing
  execution IDs;
- resource measurements remain nondeterministic diagnostics;
- active Slog rules cannot read it. A future post-fixpoint query program may
  read a frozen snapshot, which is a new pipeline stage rather than feedback
  into the observed execution.

## 6. Cost tiers

The original tiering idea remains useful, but identity should be fixed before
adding many tables.

`SLOG_STATS=off|basic|full` is the intended control, with
`SLOG_NO_STATS=1` retained as an alias for `off`.

- **off:** publish nothing. Whether task-local audit counters are completely
  compiled out is a separate build/cache choice.
- **basic:** fixpoints, fires, iteration delta sizes/times, final relation
  sizes, and cheap daemon-side memory/interner/index inventories.
- **full:** code-generated net-new and probe counters plus phase timing.

Daemon-side metrics do not require different generated plugins. Codegen-side
instrumentation must participate in the plugin cache key. Deterministic
counts and nondeterministic resource measurements remain separate test
classes regardless of tier.

## 7. Migration sequence

1. Add stable execution, rule, and version identities to the current rows
   while retaining `$stat_*` compatibility views.
2. Introduce the reserved `stats` namespace and namespace policy in the
   runtime/API/persistence layers.
3. Publish `stats.iter`; the runtime already computes iteration completion,
   delta magnitude, and elapsed time.
4. Move the fire audit to `RuleKey` and `StratumExecutionId`; normalize only
   `EvaluationId` in goldens.  *(Step 4's substance shipped 2026-08-11 on
   the W5′ runtime arc, scoped to where the identities exist: the two
   executors' fire identity is UNIFIED — the interpreter keys normal rules
   by source loc + base tag exactly as native and flavored rounds always
   did, which made the `SLOG_OPT=interp` stats legs pass their
   hand-verified goldens for the first time and lets a mixed-executor
   restarted read land its fires under one key (t6-restart's swap gate now
   asserts per-key equality); and sessions expose the durable view — the
   `(fires)` verb streams every tally with its loc resolved to a RuleKey
   through the T0(c) rule-meta registry.  Batch goldens keep loc+tag keys
   deliberately: RuleKeys are recipe-layer identities, and a one-shot batch
   run has none by design.  The full stats.* golden migration remains this
   step's later half.)*
5. Add daemon-side memory/interner/index inventories.
6. Add `full` codegen instrumentation and include its mode in the compile
   cache key.
7. Only after snapshot semantics exist, consider a separate post-run Slog
   query stage over `stats.*`.

The migration should not expose current push ordinals as durable IDs. Doing
so would turn a temporary implementation detail into the exact global-name
problem that namespaced modules are meant to remove.
