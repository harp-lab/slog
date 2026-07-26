# Namespaced module instances and schema bundles

2026-07-13. **Design proposal; not implemented.** This document proposes a
small surface feature with broad consequences:

*2026-07-14: [execution-tiers.md](execution-tiers.md) designs its
KernelPlanKey/BindingFrame identity model so that §8.4's alpha-normalized
instance-path code reuse is achievable when instantiation ships; that reuse
remains optional here and becomes a correctness gate there only once
instantiation exists.*

```slog
instantiate "module.slog" as mod
```

The file is expanded into the current program under the fresh namespace
`mod`. A declaration or rule occurrence named `rel` inside the file becomes
`mod.rel`, and the client may freely read it or add facts and rules whose
heads are `mod.rel`.

This is intentionally more like a generative, namespaced sub-database than a
sealed ML module. The first version has no private members, export lists, or
relation-by-relation parameter syntax.

No `module` declaration is required. Every `.slog` source closure is already
a module template; `include` contributes to that template, while
`instantiate` creates a lexical module occurrence and `run` or a top-level
CLI/session run creates a temporal program occurrence containing a module
tree. A future declaration header is justified by type/schema parameters, not
by the mere fact that a file is a module.

## 1. The core proposal

Suppose an SCC library declares `edge`, `vertex`, `reachable`, and `scc`.
A client can write:

```slog
instantiate "scc-lib.slog" as cfg_scc

rule (cfg_edge x y) --> (cfg_scc.edge x y)
rule (cfg_scc.scc x component) --> (cfg_component x component)
```

Or, when the client is itself the graph producer, it can write directly into
the instance:

```slog
rule (call_site f g) --> (cfg_scc.edge f g)
```

Two occurrences are distinct even when they use the same source:

```slog
instantiate "scc-lib.slog" as call_scc
instantiate "scc-lib.slog" as heap_scc
```

`call_scc.edge` and `heap_scc.edge` are different relations. Their rules do
not meet merely because the module source is identical. Cross-instance rules
can connect them intentionally.

This directly solves the important generic-library problem that `include`
does not: an `any`-typed SCC implementation can be used twice without an
extra graph-id column and without implicit merging. It does **not** by itself
make `any` statically type-specialized. Type parameters are a possible later
feature, not a prerequisite for safe reuse.

## 2. Meaning of an instance

Lexical instantiation is a compile-time operation with three effects:

1. It allocates a fresh **module-instance identity** at that occurrence.
2. It qualifies every module-owned declaration and reference with the
   instance path.
3. It copies the module's rules and facts into the current program under
   those qualified names.

It does not imply a runtime process, a fixpoint boundary, a database copy, or
a new stratum. Stratification runs after expansion over the actual qualified
dependency graph.

Consequently:

- independent instances normally remain independent graph components;
- a client rule that connects them adds the corresponding dependency edge;
- a real cycle across namespaces still forms one SCC;
- an instance can span several strata, and a runtime stratum can contain
  rules from several instances;
- current compilation may group independent SCCs at one dependency level
  into one emitted runtime stratum. Namespaces do not promise physical
  scheduling isolation.

### 2.1 Templates, module instances, program instances, and homes

Four objects must not be collapsed into one:

- A **module template** is a source file plus the files it includes.
- A **module instance** is one lexical occurrence of a template in an
  expanded program. It has a stable `ModuleInstanceKey`, a home namespace,
  and namespace bindings. `instantiate` creates one; `include` does not.
- A **program instance** is one temporal execution of a whole expanded module
  tree. It has a stable `ProgramInstanceKey`, an input namespace/version
  environment, and a pipeline position. `run` and the CLI/session driver
  create these.
- A **database namespace** is a path in the materialized database containing
  relation versions and type/constructor declarations.

Every module instance has a **home namespace**. Its unqualified declarations
live there. It may also read or write other namespaces through qualified
references or explicit namespace bindings. A program instance contains a root
module instance and every lexical child it instantiates.

The top-level CLI/session program normally has the database root as its home.
An `include` stays in the same template and home. `instantiate ... as a`
creates a child home `a` in the same program segment. `run` creates a new
temporal program instance; it may operate at the current home or be given a
child home with `as`.

The root is a real namespace even though it has no source-level prefix. A REPL
or API gives a completed database snapshot an external handle such as `db0`,
so root relation `rel` is displayed as `db0.rel` and nested relation
`syn.app` as `db0.syn.app`. `db0` is not part of the compiled relation name.

An explicit lexical module occurrence is fresh, but a later program instance
may deliberately target an inherited namespace path. In that case compatible
declarations describe the same logical namespace and writes create successor
relation versions. Thus `a.edge` and `b.edge` are separate stores, while two
successive program instances intentionally operating on `model.edge` form one
version chain. Their `ProgramInstanceKey`s remain distinct even though their
home path is the same.

### 2.2 What is qualified

Qualification must be uniform. It applies to:

- tables, structs, enums, unions, and union members;
- lattice type declarations;
- demands, externs, and their synthesized demand/answer relations;
- relation references in rule heads and bodies;
- struct constructors and named types in patterns and value expressions;
- module-local generated names such as collection decomposition relations,
  supplementary demand relations, sequence occurrence helpers, and anonymous
  generated types;
- source rule identity and diagnostics.

Variables, literals, primitives, and language builtins remain lexical or
global as they are today. Runtime-reserved roots such as `stats` are not legal
instance aliases.

The compiler should treat a qualified name as a path, not as a user-chosen
string prefix. `a.bc.r` and `ab.c.r` must never collide through concatenation,
and namespace policy must inspect components rather than `starts_with` text.

### 2.3 Client extension and visibility

All members are public in the first design. The client may:

- read `mod.rel`;
- put facts or additional rules into `mod.rel`;
- construct or match `mod.Node` values;
- use `mod.Type` in its own declarations;
- expose selected results through its own relations.

The instance's declaration remains authoritative. A client can add rules to
`mod.rel`, but cannot redeclare it with a conflicting arity, kind, lattice
specification, or field types.

This openness is useful in a relational language: a library input is often
best represented by allowing its client to derive the input relations. A
privacy/export system can be added later for API discipline, but it should
not be entangled with the first implementation.

### 2.4 Nested composition

An `include` inside an instantiated file is textual composition within that
same instance. Its local declarations receive the outer prefix. Include
deduplication is scoped to the module occurrence, so it prevents diamonds
within one instance but does not erase a second explicit instantiation.

An `instantiate` inside a module composes paths. If `analysis.slog`
instantiates `syntax.slog` as `syn`, then:

```slog
instantiate "analysis.slog" as a
```

creates `a.syn.Exp`, `a.syn.Const`, and so on.

A `run` inside a module is the temporal counterpart: it creates a separately
keyed program instance and pipeline boundary while inheriting the enclosing
namespace environment. If its source is itself nested under outer instance
`a`, relative home and formal namespace paths begin at `a` unless explicitly
bound elsewhere. A conservative first implementation may reject this nesting
until `ProgramInstanceKey` and binding metadata survive recipe replay.

## 3. `include`, `instantiate`, `run`, and database attachment

These operations answer different questions and should remain distinct.

| operation | names | execution | typical use |
|---|---|---|---|
| `include "m.slog"` | open/flat merge | same program | split one program across files; legacy libraries |
| `instantiate "m.slog" as n` | fresh `n.*` namespace | same program | reusable analysis, schema, or algorithm instance |
| `run "m.slog"` | current home | new program segment/fixpoint pipeline | modify or extend the current database over time |
| `run "m.slog" as n` | child home `n.*` | new program segment/fixpoint pipeline | retain a named stage result beside other instances |
| attach/import a saved namespace | mapped qualified names | no source rerun unless requested | connect a persisted sub-database to another pipeline |

`instantiate` should resolve local paths and the standard library like
`include`. Unlike `include`, the same canonical file may appear any number of
times under different instance aliases.

There is no need to reuse the parser's experimental `import ... as ...` form
for source modules. `import` is overloaded between lexical loading and
database ingestion in many languages. The single explicit verb
`instantiate` says the important thing: make a fresh occurrence here.

Database attachment may still deserve a separate action because it consumes
data plus a schema rather than source rules.

Source order among `include` directives or rules does not create time. All
rules in one expanded program are stratified together. To say “operate on the
settled result here, then modify it,” the user creates another `run`/session
segment. Lexical composition chooses names; pipeline composition chooses
time.

A source-level `run` remains a prerequisite: it reaches fixpoint before the
containing program instance. Sibling prerequisites run in source order because
they may intentionally advance the same relation versions. An interactive or
session `run` appends a program instance after the currently selected database
boundary. These are two ways of constructing the same ordered recipe.

### 3.1 Operational model of a run

A logical pipeline boundary has a stable `BoundaryKey` and two related maps:

```text
C_k.decls   : QName -> DeclarationDescriptor
C_k.members : set (member-QName, union-or-enum-QName)
C_k.nominal : struct-QName -> TypeKey
E_k         : QName -> VersionKey
```

`C_k` is the logical catalog: it includes empty tables and structs, union and
lattice declarations, and the field-type graph. `E_k` is the materialized
relation environment: every table, struct-intern relation, or lattice member
in `C_k` has an initial or inherited relation slot in `E_k`, even when that
slot contains no tuples. A local REPL name such as `db7.model.edge` means
"resolve `model.edge` in the boundary named by `db7`"; it is not a daemon
relation name with `db7.` prepended.

In a live session a database handle denotes `(EvaluationId, BoundaryKey)`, so
the same recipe boundary can materialize independently in two descendant
evaluations without sharing mutable relation state.

This separation is necessary because the current daemon `(schema)` action and
BIN relation directories describe materialized relations and omit empty
members. They cannot be the source of truth for a declared sub-database. The
session must retain and persist `C_k`; daemon schema introspection is an ABI
and consistency check, not a replacement for the catalog.

A normalized catalog contains exact node descriptors and additive edges:

```text
RelationDecl(QName, table|struct, field TypeRef*, lattice-spec?)
TypeDecl(QName, lattice/alias metadata)
MemberOf(member-QName, union-or-enum-QName)
```

`TypeRef` is a primitive, `any`, a qualified nominal name, or a normalized
collection/lattice type expression. Runtime-only fields—VersionKey, TypeKey,
SID, indexes, and tuple counts—are not part of declaration compatibility.
Because prefix substitution fixes every nominal QName, comparing recursive
declaration graphs needs no general graph-isomorphism search.

A program instance is conceptually:

```text
(ProgramInstanceKey, module-instance tree, home H, bindings B,
 input BoundaryKey, C_k, E_k)
```

Name resolution first places a local name under its module home, then applies
the instance's non-overlapping formal-prefix bindings. For example:

```text
home             = p
binding          = p.model -> X
local model.edge = p.model.edge -> X.edge
local answer     = p.answer
```

Qualification and binding first produce a complete set of actual declaration
paths and an actual read/write set. The session then plans one atomic boundary
transition:

| member at `C_k` | declared by program | written by program | result at `k+1` |
|---|---|---|---|
| absent | yes | either | add declaration and an initial `VersionKey` |
| compatible | yes | no | retain its `VersionKey` |
| compatible | yes | yes | create one successor `VersionKey` |
| incompatible | yes | either | reject the whole transition |
| present | no | no | retain it; omission is not a drop |

Missing declarations are therefore created even if they remain empty. If a
new relation is written in the same segment, the segment fills its initial
slot rather than creating an empty slot followed immediately by a successor.
All reads bind to the input versions in `E_k`; ordinary same-segment recursive
rules still see the segment's output slot in the normal semi-naive way.

Planning, schema validation, key allocation, and daemon declaration happen
before any user stratum runs. The daemon receives one checked declaration
batch and prepares all members in a private boundary overlay or prepares
none. The program's plugins resolve through that overlay while it is active.
Only fixpoint publishes `(C_k+1, E_k+1)` and makes a new REPL handle; cancel or
failure aborts the overlay and leaves the prior boundary public.

There is deliberately no independently mutable “namespace version.” A
database boundary is a coherent environment of per-relation versions, and a
REPL database handle names that environment. This retains the existing
incremental semantics while letting a schema bundle be selected as one unit.

### 3.2 Additive completion, not schema versions

Suppose `X` contains `a` and `b`, and a later program declares
`X.{a,b,c,d,e}`. If `a` and `b` are compatible, the program adds empty initial
slots for `c`, `d`, and `e` and proceeds. No separately named "schema v2" is
created, and no meta-schema object is needed to assert that the two shapes are
related. The two boundary catalogs simply differ by three compatible entries.

The completion rule is open-world and atomic:

- validate every overlapping declaration after namespace substitution;
- add every missing declaration in the required closure;
- tolerate actual members that the program does not mention;
- reject a changed kind, arity, lattice specification, constructor shape, or
  field-type graph at an already established public QName; and
- never infer deletion from a source file ceasing to declare a member.

The catalog should normalize extensible type declarations into atomic facts.
A relation or constructor has one exact shape, while `union U contains T` and
named-enum membership are additive edges. A later program may add a new
constructor plus a membership edge without redefining the existing union
node. Removing an edge from source does nothing; an explicit incompatible
migration is required to narrow a live type contract.

An incompatible change uses a new member name plus an explicit migration.
Removing a live member uses `drop`. Dropping and later redeclaring the same
qualified name starts a fresh relation chain and, for a struct constructor, a
fresh nominal type identity. This keeps old database handles meaningful.

## 4. A namespace is also a schema bundle

The deeper value is not merely avoiding collisions. A namespace groups a
small database whose relations and types are meaningful together.

Examples:

- `syn.*`: expression variants, source spans, identifiers, declarations, and
  source-level control-flow facts.
- `cfg.*`: nodes, edges, entry/exit nodes, labels, exceptional edges, and
  call/return matching.
- `model.*`: functions, allocation sites, bind/use facts, call graph, heap
  abstraction, and inferred value facts.
- `tune.*`: per-function context depth, per-allocation-site heap precision,
  interval-domain bits, widening thresholds, and forced summaries.
- `diag.*`: diagnostics, source locations, explanation/provenance edges, and
  suppression decisions.
- `proof.*`: claims, assumptions, witnesses, counterexamples, and solver
  results.
- `test.*`: inputs, expected facts, allowed imprecision, and comparison
  results.

A single relation is often not a sufficient interface. A CFG consumer needs
to agree with its producer about node identity, entries, exceptional edges,
and source mapping. Passing only `cfg.edge` loses that contract. The namespace
is the natural unit of schema compatibility, persistence, attachment,
inspection, and documentation.

A useful module may therefore contain declarations only. For example,
`schemas/syntax.slog` can define the `Exp` union, constructors, spans, and
top-level source relations without choosing a parser or interpreter. A
combined program instantiates that schema once as `syn`; producer and consumer
rules both name `syn.*`. Separately compiled pipeline stages instantiate the
same schema contract under their chosen local path, and a checked namespace
attachment maps the producer's instance to the consumer's. This keeps “which
relations belong together?” in source control rather than in a long command
line or an informal naming convention.

### 4.1 Syntax and abstract values

The existing syntax/interpreter examples show the naming benefit clearly.
`examples/r7rs-small/syntax.slog` defines `Pr`, `Bool`, `ConstVal`, `Exp`,
`Lam`, `Ref`, and `Const`. Under:

```slog
instantiate "syntax.slog" as syn
```

their names become `syn.Pr`, `syn.Exp`, `syn.Lam`, `syn.Ref`, and
`syn.Const`. An interpreter can independently use `(const ...)` or
`abs.const` for an abstract value representing a propagated constant without
confusing it with the source AST constructor `syn.Const`.

The same improvement applies to the Scheme CFA examples. Today syntax
constructors such as `num`, `ref`, `lambda`, and `app` share one flat space
with abstract-value constructors such as `numval`, `closure`, and `prim`.
With namespaces, rules visibly cross the representation boundary:

```slog
rule (eval (syn.num n) c (abs.num))
rule (eval (syn.lambda xs body) c (abs.closure (syn.lambda xs body) c))
```

Parser, pretty-printer, interpreter, CFA, optimizer, and verifier can all
agree on the `syn.*` schema while owning distinct result namespaces.

### 4.2 Analysis/refinement feedback

An analysis can produce `model.*`. A refinement stage reads that bundle and
produces `tune.*`, for example:

```text
tune.per_fun_ctx_depth
tune.per_addr_interval_domain_bits
tune.widen_after
```

The next analysis occurrence consumes the tuning bundle and produces a new
model occurrence. These are separate pipeline/session instances:

```text
analysis₀(inputs, tune₀) -> model₀
refine(model₀)           -> tune₁
analysis₁(inputs, tune₁) -> model₁
```

Namespacing makes each multi-relation boundary explicit. It does not make the
outer feedback loop monotone or force all three steps into one Datalog SCC.
The session recipe owns the occurrences and version links. If the feedback is
instead written as ordinary in-program rules that read and write one another,
the normal dependency graph decides whether they merge or are illegal.

With modules written against local children `syntax`, `tuning`, `input`, and
`output`, one concrete recipe could be:

```slog
run "frontend.slog" as front
  with output = syn

run "analyze.slog" as a0
  with syntax = syn, tuning = tune0, output = model0

run "refine.slog" as r0
  with input = model0, output = tune1

run "analyze.slog" as a1
  with syntax = syn, tuning = tune1, output = model1
```

An absent `syn`, `model0`, `tune1`, or `model1` is created from the
corresponding formal schema. Existing inputs are checked as compatible
supersets. Private/unbound declarations remain under `front.*`, `a0.*`,
`r0.*`, and `a1.*`. Nothing is renamed or copied, and each line records one
program instance plus the exact relation-version environment it consumed.

### 4.3 Other strong examples

1. **CFG algorithms.** Dominators, SCCs, loop discovery, liveness, and
   reachability all consume the same `cfg.*` bundle and produce separate
   namespaces. The SCC library need not own or reinterpret node metadata.
2. **Frontend IR handoff.** A parser produces `ast.*`; desugaring produces
   `core.*`; closure conversion produces `cc.*`. Each schema includes types,
   nodes, binding edges, provenance, and entry points.
3. **Points-to model handoff.** A CFA produces `pt.value`, `pt.store`,
   `pt.call_target`, and `pt.escape`; an optimizer or security analysis needs
   the set as one versioned contract.
4. **Diagnostics with explanations.** A pass emits both `diag.issue` and a
   graph of `diag.because` edges plus locations. Downstream formatting,
   suppression, and testing share the schema without sharing analysis rules.
5. **Differential checking.** Instantiate an analysis twice at different
   precisions, retain `coarse.*` and `fine.*`, then write explicit containment
   rules. Instance separation is the property being tested.

## 5. Declaration compatibility is not relation-instance identity

This distinction is load-bearing.

- A **relation namespace/version instance** is generative by qualified path
  and pipeline event. `a.edge` and `b.edge` are different stores even when
  both came from the same module declaration; a later write to `a.edge`
  creates its successor version rather than `b.edge`.
- A **declaration shape** must be comparable across producer and consumer
  databases so that a saved `model.*` can be attached and validated.

Treating the display prefix as both identities fails in opposite directions:
making it global merges independent instances, while making every type tag
fresh prevents two programs from exchanging values of a shared schema.

There is no `SchemaMemberKey` and no identity for "the schema through all of
its versions." The target metadata records concrete things instead:

1. normalized `DeclarationDescriptor`s and an optional diagnostic hash over a
   declaration closure;
2. a fresh `ModuleInstanceKey` for each lexical occurrence;
3. a `ProgramInstanceKey` and `BoundaryKey` for each temporal occurrence;
4. relation `VersionKey`s for materialized pipeline slots; and
5. a `TypeKey` for each concrete nominal struct-constructor instance.

A declaration hash accelerates comparison and improves diagnostics, but it is
not nominal identity. Adding `c` changes the closure hash without invalidating
compatible existing members `a` and `b`.

Within one program, qualified constructor and type names remain nominal:
`a.syn.Const` is not silently accepted as `b.syn.Const`. When a persisted
namespace is explicitly attached under a new prefix, the loader maps the
whole declaration graph, remaps struct type and instance IDs, and then imports
the rows. Attaching into an existing compatible destination reuses its
`TypeKey`s. Attaching as a fresh independent namespace mints destination
`TypeKey`s even if the source came from the same module. Reloading the same
recipe lineage preserves its keys. This is analogous to the current database
merge's content-aware struct remapping, extended from a map of individual
relation names to a checked namespace map.

The result is **generative data, compatible schemas**. Compatibility never
implies that two live relation stores should union automatically.

### 5.1 One adaptation mechanism: namespace binding

A program that literally names `X.rel` knows the input is called `X`. That is
appropriate for one application. A reusable program should be written against
a local formal namespace and have that entire namespace bound by its caller.

For example, `consumer.slog` can instantiate a declaration-only model schema
as local child `model` and write all its rules against `model.*`. The proposed
composition syntax is:

```slog
instantiate "consumer.slog" as c with model = X
```

and at a temporal boundary:

```slog
run "consumer.slog" as c with model = X
```

The left path is relative to the new root module's home; the right path is
resolved in the caller's database namespace. Internally, `c.model.*` denotes
the existing `X.*` relations. Other unqualified consumer declarations still
land under `c.*`.

This is a static, zero-copy name-environment mapping. It applies atomically to
relations, struct constructors, types, and nested child namespaces. The
compiler validates the formal schema against `X` before compiling any rules.
The binding is scoped to this program instance, so `X` keeps its public name
and another consumer can bind the same formal name to `Z`.

Every explicitly instantiated child namespace is eligible as a formal; no
separate port/module declaration is needed. Its canonical declarations form
the required interface. Rules and facts in that child are still instantiated
and operate on the actual namespace after binding, so declaration-only schema
modules are a convention for interfaces rather than a new language kind.

Binding uses structural interface satisfaction, not equality of source-file
digests. After substituting the formal prefix with the actual prefix, every
required table, lattice, struct, union member, constructor, and field type must
be compatible when present. The actual namespace may contain additional
direct members and child namespaces. This lets a small `graph.*` interface
bind to a richer `cfg.*` bundle. A newer actual can therefore satisfy an older
consumer when it only adds members; changing an existing declaration remains
incompatible.

Interface compatibility has one intentional specialization rule: formal
`any` is a wildcard for an actual field type, recursively inside supported
value/lattice type expressions. Thus formal `graph.edge(any, any)` can bind to
actual `cfg.edge(cfg.Node, cfg.Node)`. After prefix substitution, the compiler
discards the formal relation shape for code checking and type-checks every
instantiated rule against the actual declaration. A generic module fact or
write that is not valid for `cfg.Node` is therefore rejected. The reverse is
not accepted: a formal rule that requires `cfg.Node` cannot bind to an actual
`any` column and assume every runtime value is a node.

This wildcard is part of namespace-interface satisfaction only. It does not
permit a later pipeline stage to change an established public relation from
`any` to `cfg.Node`, or vice versa. Such a catalog evolution remains an
incompatible field-type change. Future explicit type parameters can express
correlations such as “both endpoints have the same type”; they need not invent
another namespace adaptation mechanism.

The same mechanism serves producers. If the actual path exists, its schema is
validated and writes create the appropriate successor versions. If it is
unbound, the formal declarations create a new namespace at that caller-chosen
path. If it is partially present, compatible members are reused and missing
members are added in the same atomic declaration batch. An incompatible
actual rejects the batch before any relation is created or advanced. There is
therefore no separate output-prefix or post-run-rename feature.

Bindings are prefix substitutions, not a series of relation aliases. Formal
paths in one binding list may not overlap (`model` and `model.cfg` cannot both
be mapped). Two distinct compatible formals may explicitly target the same
actual; after rewriting, ordinary dependency analysis exposes any resulting
cycles or shared writes, and diagnostics should call out the aliasing.

A binding is read-write in the first design. If the consumer derives
`model.edge`, it writes the actual `X.edge`; in a later pipeline segment this
creates the normal successor version of `X.edge`. Read-only ports and
capability annotations would add another way to do the same basic composition
and should wait for a demonstrated safety need.

When formal and actual paths are naturally identical at the current home, no
`with model = model` is needed: ordinary relative resolution already reaches
the inherited namespace. This is not implicit search or basename matching.
Moving the program under home `c` changes the relative path to `c.model`, so a
binding is then required to reach root `model` or differently named `X`.

### 5.2 Why database rename is not module adaptation

The session's existing rename operation is a durable database-history event:
it rebinds a public name, unbinds the source spelling, affects later programs,
and is recorded in the replay recipe. It is useful when the database's public
schema should actually change.

Adapting `consumer.model` to `X` should not require an `X -> model` rename
stage. That would hide `X` from other consumers, create ordering concerns, and
make two differently named uses cumbersome. Namespace binding is lexical and
scoped; database rename is temporal and public. Keeping that division gives
one normal module workflow and one genuinely different database operation.

Crossing a persisted database boundary still requires attach/import because
data and interned values must be loaded or remapped. That operation chooses a
live destination namespace once. Programs then use the same namespace-binding
mechanism whether the data originated locally or on disk.

### 5.3 Namespace-wide database operations

The database schema already tells whether a qualified path names a leaf
relation or a child namespace, and the design forbids one path from being
both. Environment operations can therefore accept one path syntax instead of
growing `rename-namespace`, `drop-namespace`, and similar variants.

- Renaming leaf `X.edge` rebinds that relation as today.
- Renaming namespace `X` to `Y` atomically rebinds the entire subtree,
  including constructor/type mappings, without copying tuples. The catalog
  transform also rewrites every nominal QName reference to that subtree,
  including field types declared outside `X`.
- Dropping `X` unbinds the subtree at the new boundary but does not destroy
  historical relation versions or old REPL handles.
- Attaching/importing a saved subtree at `X` validates every required schema
  mapping and interned type before creating any member.
- Saving or inspecting `X` selects the subtree as a schema/data bundle.

These are environment transforms recorded as single recipe events, not loops
whose semantics happen to depend on a string prefix. A program instance that
captured old actual `VersionKey`s continues to re-enter against those versions
after a later public rename or drop.

The first implementation should preserve catalog referential integrity:
`drop X` is rejected if a declaration outside the dropped subtree has a field
type or membership edge that requires a declaration inside `X`. The user must
drop/migrate that dependent declaration in the same atomic catalog event.
Values stored in an `any` column do not create such a static edge; they may
continue to contain an old TypeKey, which remains decodable even with no
current public constructor name. This conservative rule avoids inventing a
second hidden namespace or a general compile-time type-node identity merely to
make dangling schemas appear valid.

## 6. Stable identities in pipelines

Names such as `stratum3` must not become global module prefixes. Prepending a
program from `data/`, inserting a facts stratum, or re-entering an old segment
changes numeric positions. Deduplicating two `stratum3` strings after the fact
cannot recover which execution they meant.

Pipeline metadata needs several deliberately different notions:

- **ModuleInstanceKey:** stable lexical occurrence for source/rule identity.
- **ProgramInstanceKey:** stable recipe node for this occurrence of a root or
  `run` program.
- **BoundaryKey:** stable identity of the logical catalog/version environment
  before or after a recipe event. A REPL handle such as `db7` is a
  session-local label for `(EvaluationId, BoundaryKey)`.
- **VersionKey:** stable identity of one logical relation slot in the recipe.
  It is not a name and is not a content hash.
- **TypeKey:** stable identity of one concrete nominal struct-constructor
  instance in a recipe lineage.
- **StratumKey:** content identity of the qualified compiled rule/member set.
- **pipeline position:** evaluation-local ordering label.

The current incremental design already separates relation `VersionId` and
`VersionKey` from pipeline position. Modules should follow that model. A
program prepended to the pipeline gets its own instance keys; later positions
shift but existing logical nodes and relation versions remain identifiable.
Using the same saved program twice creates two program instances even if its
compiled stratum keys are equal.

Runtime stats then use these identities as columns in one `stats.*` schema;
they do not mint a `stratum7.*` namespace. See [stats.md](stats.md).

### 6.1 Qualified names are boundary-relative

A qualified database path by itself identifies a binding, not an object for
all time. At two boundaries the same spelling may select different versions;
after a rename, two spellings at different boundaries may select the same
version:

```text
Boundary b3: X.Const -> VersionKey v17 -> TypeKey t4
Boundary b8: Y.Const -> VersionKey v17 -> TypeKey t4   ; rename
Boundary b9: Y.Const -> VersionKey v18 -> TypeKey t4   ; successor
```

`db3.X.Const` and `db8.Y.Const` are complete human-facing references because
the handle supplies the boundary. The stable logical-slot reference is
`VersionKey v17`. Within one session/recipe evaluation that is sufficient; a
reference to materialized contents across possible descendant evaluations is
`(EvaluationId, VersionKey)`. A UI may display a friendly form such as
`Y.Const@analysis0`, but recipe events, debugger bookmarks, and APIs use the
key underneath; source names and numeric positions are allowed to change.

A namespace binding is another scoped name environment, not another public
database alias. If program instance `c` records `c.model -> X`, introspection
shows that binding, while public database completion continues to show
`X.edge`, not a duplicate `c.model.edge`.

### 6.2 `TypeKey` and the daemon SID

`TypeKey` applies only where the runtime has nominal identity: principally a
struct constructor and its intern relation. Plain tables need only a
`VersionKey`; compiler-only unions retain declaration metadata but no SID.

Within one live daemon database, a `TypeKey` maps to one nonzero 14-bit struct
ID (SID). All relation versions of that struct type carry the SID verbatim,
and namespace rename/drop never rewrites value words:

```text
(EvaluationId, TypeKey) -> SID
SID -> TypeDescriptor
```

The SID is global to that database evaluation, not relative to a pipeline
position. Making it position-relative would require recursively retagging
every struct, collection, lattice payload, and containing tuple at every
boundary. It would also make zero-copy rename and inherited versions
impossible.

The SID is not a durable semantic key. A root load may preserve stored SIDs as
a fast path, but an independent import already remaps the complete imported
value graph into the destination SID space. Reload may therefore map the same
`TypeKey` to another SID. Persisted metadata and REPL bookmarks name the
`TypeKey`, never the number.

Fresh namespace instantiation, attach-as-new, and redeclaration after drop
mint fresh `TypeKey`s and consume fresh SIDs. Binding to an existing actual,
renaming it, or creating a successor relation version preserves its TypeKey
and SID. Two compatible declaration shapes do not thereby become the same
nominal type.

### 6.3 Allocate SIDs from genuine gaps

The current monotone `struct_id_max++` allocator should become a 16K occupancy
bitmap or ordered free set. Allocation chooses the lowest unused SID in
`1..0x3ffe` before reporting exhaustion. This is especially natural during
import: source SIDs are being remapped anyway, so every fresh destination
TypeKey can take any free destination SID.

“Unused” is semantic, not merely absent from the latest name map. An SID stays
occupied while its TypeDescriptor, any retained relation version, or any live
REPL value handle can refer to a word carrying it. Rename and drop therefore
do not free it automatically. Root load marks every restored SID occupied;
import reuses existing destination TypeKeys first and fills real gaps for new
ones. Aborting a provisional boundary can free its SIDs after invalidating any
provisional value handles, because no committed value can contain them.

Filling a free gap is not compaction and moves no values. Defragmenting a live
SID assignment would require recursively rewriting every referent and is not
worth designing now. If all 16,382 slots are genuinely live, the honest
answers are to reject the allocation or widen/change the runtime tag—not to
silently reuse one.

### 6.4 Persistent key construction

Use the incremental recipe's existing content-neutral `LayerId` and explicit
event/slot tables rather than hashes of names or declarations:

```text
ProgramInstanceKey = (LayerId, program-event)
BoundaryKey        = (LayerId, boundary-event)
VersionKey         = (LayerId, boundary-event, relation-slot)
TypeKey            = (LayerId, type-creation-event, type-slot)
ModuleInstanceKey  = (ProgramInstanceKey, lexical-occurrence path)
```

The serialized representation can be opaque because the REPL assigns short
`@vN` and `@tN` aliases and exposes the backing key only on request. Slot
tables are assigned once and stored in the recipe, in sorted QName order for
deterministic creation but never recomputed after publication. Declaration
hashes, source paths, aliases, and pipeline positions are metadata on these
keys, not ingredients in their identity. A replay of the same immutable layer
preserves the keys; a modified clone gets a fresh LayerId.

## 7. Name resolution

The language needs an explicit rule for relative paths before it grows
namespace ports. A workable first slice is:

- source-level unqualified module-owned names are relative to the current
  module instance;
- an instance alias introduced in that module is a relative child namespace;
- builtins and reserved runtime roots resolve globally;
- the client sees the instance through the alias it declared;
- a `with formal = actual` binding rewrites the formal subtree before type
  checking and stratification;
- no implicit search through parents or sibling instances occurs.

Thus internal `edge` becomes `cfg_scc.edge`, and internal child `syn.Const`
becomes `analysis.syn.Const`. Avoiding implicit parent lookup keeps expansion
deterministic and makes a later explicit namespace binding meaningful.

Aliases are path components, not relation declarations. A scope should reject
ambiguous use of the same component as both a leaf declaration and a child
namespace until the implementation has a compelling reason to support it.

## 8. Compiler and runtime repercussions

The surface parser change is small. Correct end-to-end support touches every
place where a relation or type name is currently assumed to be one flat
symbol.

The change should be interposed at four existing seams rather than spread as
ad-hoc prefix handling:

| seam | current owner | new responsibility |
|---|---|---|
| source composition | `compiler/parser.rkt`, `compiler/modules.rkt` | build occurrence trees, structured names, homes, and bindings |
| program planning | `compiler/compile.rkt`, `compiler/session.rkt` | reconcile the qualified declaration catalog and allocate boundary/version/type keys |
| runtime registration | `daemon/database.h`, `daemon/daemon.h` | atomically apply a declaration/version plan and maintain the global type registry |
| persistence and interaction | `compiler/dbmeta.rkt`, `compiler/runslog.rkt`, `compiler/session.rkt`, `compiler/run.rkt` | persist catalogs and keys; resolve boundary-relative REPL names |

The compiler remains the declaration/type authority, the session remains the
recipe/name-history authority, and the daemon remains the materialization and
runtime-ID authority. The REPL consumes their explicit metadata; it should not
become a fourth authority.

### 8.1 Lexer and parser

Add the top-level form:

```text
instantiate <string-literal> as <identifier>
```

Extend both lexical and temporal occurrence forms with the same binding
clause:

```text
instantiate <string> as <identifier> [with <formal-path> = <actual-path>, ...]
run         <string> [as <identifier>] [with <formal-path> = <actual-path>, ...]
```

`as` introduces one child component; arbitrary nesting arises by nesting
module instances. Formal and actual sides of a binding are qualified paths.

Qualified names should parse as one name-path AST. The current lexer emits
`.` as an operator and the expression parser has a binary dot operator
(the tightest-binding entry in the operator table — see
[n0-seam-map.md](n0-seam-map.md) Seam 1), so merely allowing dots in the
identifier regular expression would create avoidable ambiguities. Parse
`id(.id)+` explicitly in name positions, then preserve path components
through module expansion.

Add one `compiler/names.rkt` authority with a `QName` value (a nonempty vector
or list of validated components), prefix substitution, ordering, display,
wire encoding, and C++ mangling. For the first slice, module expansion may
lower a `QName` to a collision-free encoded symbol before the existing
symbol-keyed middle end. No other pass may join or split components itself.
That containment makes the first implementation tractable without declaring
dotted strings to be the permanent IR.

### 8.2 Module resolver and expansion

The current loader set-unions included modules and deduplicates them by path.
Instantiation needs an occurrence tree instead:

- `include` dedup remains local to one occurrence;
- each explicit `instantiate` is retained even for the same canonical file;
- instance aliases are checked for collisions;
- formal namespace paths are resolved inside the occurrence and actual paths
  against its caller, then captured as a binding environment;
- cycles through instantiate/include/run are diagnosed with occurrence paths;
- source capture stores the source closure, while the saved recipe separately
  stores every occurrence and alias.

A qualification pass should run before type extraction, demand expansion,
decomposition synthesis, and stratification. It must distinguish top-level
names from variables and primitives using the module's declarations.

For a first implementation, the front end can carry structured paths through
resolution and lower them to a canonical escaped symbol before the existing
middle end. Long term, structured names in the IR are safer. Either approach
must use one centralized mangler for generated C++ identifiers and one
reversible serializer for user-visible names.

Concretely, the pass belongs between `include-module`/source resolution and
`organize-module`/`lift-type-envs` in `compiler/modules.rkt`. The current
`(program reqs mods)` and later five-field program s-expressions should become
named transparent structs carrying the module occurrence tree, home,
bindings, declaration catalog, and provenance. Extending positional tuples
again would make replay metadata too easy to discard accidentally.

### 8.3 Type system and generated relations

Type-environment keys, union member sets, field types, demand signatures, and
lattice specs can all contain qualified names. Anonymous union/list/map/
lattice names must be generated within the owning namespace.

Generated companions stay with their owner. For example, a decomposition of
`m.reach` belongs to `m` rather than to a global spelling derived by prefix
text. Reserved implementation namespaces such as sequence and supplementary
machinery should be explicit path components or internal IDs, not `$` string
conventions.

Rule metadata must include module-instance identity. Source line alone is not
unique after double instantiation.

### 8.4 Stratification and code cache

After qualification, the existing dependency analysis mostly operates on
distinct keys. Cross-namespace rules naturally create cross-namespace edges.

The expanded qualified program participates in the semantic compile hash.
Initially, `a = M` and `b = M` may compile separately because emitted names
differ. A later optimization can alpha-normalize instance paths in the code
cache and bind runtime relation environments per occurrence, but cache reuse
must never collapse semantic instance identity.

### 8.5 Runtime, persistence, and database merge

The daemon already stores relation names as strings, and binary relation
directory parsing splits on the last `.arity.`, so dotted display names are
not fundamentally incompatible with the current format. That is useful but
not a complete namespace implementation.

Required work includes:

- reversible escaping/validation for name components in filenames, manifests,
  actions, and CSV names;
- qualified catalogs in inspection, sizes, lookup, rename, drop, batch, and
  version-chain introspection;
- complete declaration descriptors, occurrence paths, and instance keys in
  saved metadata/source recipes, including declarations with no rows;
- namespace binding environments and their exact input `VersionKey`s in
  program-instance and replay metadata;
- namespace-prefix mapping expanded atomically to all relations and struct
  constructors before import mutates the destination;
- use of existing content-aware struct remapping after destination type names
  are chosen;
- preservation of relation `VersionKey` and program-instance identity across
  save, open, link, replay, and re-entry;
- namespace policy based on path ownership (`stats.*` ephemeral), not a raw
  string-prefix test.

Dotted serialization is a display format. The internal identity should not
depend on splitting arbitrary strings on dots.

#### 8.5.1 Catalog planning in the session

`compiler/modules.rkt` should emit a `CatalogDelta` for each program after
qualification and binding. `compiler/session.rkt` should replace
`session-schema-manifest` as the semantic authority with a persistent
`session-catalog`; the existing manifest remains the codegen ABI view.

Before `allocate-version-event!`, a new planner should:

1. substitute every formal path with its actual path;
2. normalize the complete declaration graph;
3. compare all overlaps against the selected input boundary catalog;
4. collect all missing members as one addition set;
5. combine additions with the actual program write set;
6. allocate one `BoundaryKey`, initial/successor `VersionKey`s, and new
   `TypeKey`s; and
7. produce an immutable `BoundaryPlan` used both for recipe recording and the
   daemon request.

The current `update-manifest` already performs a weaker kind/arity check while
threading `run` prerequisites. It should become a projection of this planner,
not a second compatibility implementation. Field types, unions, and nominal
constructor references live only in the richer catalog.

The live `(schema)` action currently skips empty relations to mirror BIN data
directories. Keep that action for low-level materialization diagnostics. Add a
catalog/introspection action that reports every logical relation, including
empty ones, together with VersionKey, TypeKey if any, and runtime SID. The
session still supplies the source-level field graph because the daemon need
not become a Slog type checker.

The front-end API should consequently move from:

```text
load-program-list(path, flat-manifest) -> positional program tuples
```

to roughly:

```text
load-program-plans(path, input-catalog) -> ProgramPlan*

ProgramPlan = {
  qualified program IR,
  module tree and bindings,
  input/output catalog,
  CatalogDelta,
  actual read/write sets,
  key-allocation requests
}
```

`compile-strata` consumes the qualified IR but returns the plan metadata with
each existing program group. `session-run!` prepares, runs, and commits one
group at a time. This preserves the present dependencies-first semantics of
source-level `run` while removing the need to rediscover a group's declarations
from emitted strata.

#### 8.5.2 One transactional daemon boundary plan

Add daemon requests conceptually shaped as:

```text
(prepare-boundary BoundaryKey ProgramInstanceKey
  (declare QName kind stored-arity TypeKey-or-none lattice-spec-or-none)*
  (retain  QName VersionKey)*
  (create  QName VersionKey predecessor-or-none TypeKey-or-none)*)
(commit-boundary BoundaryKey)
(abort-boundary BoundaryKey)
```

The wire encoding can be compact, but prepare must first validate the complete
plan against the live latest environment, TypeKey/SID registry, and duplicate
names. It then constructs initial/successor relations in a working environment
visible to this program's plugins but not to ordinary latest-boundary queries.
Commit atomically installs its catalog/name bindings; abort discards them.
Allocated SID numbers may remain tombstoned after abort rather than risk reuse.

This replaces the current split where `begin-segment/keyed` versions known
writes and generated plugins lazily create absent declarations. Generated
plugins may keep their defensive lookups, but they must no longer be
responsible for semantic schema creation. A paused run retains its prepared
overlay and has no completed `dbN` handle until resumed to fixpoint.

`Database::newVersion` already preserves a struct SID verbatim, and
`rel_bindings` already records point-relative names. Retain both. Add direct
maps for `(EvaluationId, VersionKey) -> Relation*`/`VersionId` rather than the
current registry scan, and store the supplied BoundaryKey with binding events
while retaining `pipeline_pos` as a fast evaluation-local ordinal.

#### 8.5.3 Split type identity from the latest relation map

The current `structs_by_id` memo points from SID to a `Relation*`, follows the
latest version in `newVersion`, and lazily scans only currently named
relations. That is too dependent on the latest name environment for dropped
types and historical REPL values. Replace it conceptually with:

```text
struct TypeDescriptor {
  std::string type_key;
  u32 sid;
  u16 stored_arity;
  Relation* canonical_relation; // first slice: latest complete intern store
};

std::unordered_map<u32, TypeDescriptor*> types_by_sid;
std::unordered_map<std::string, TypeDescriptor*> types_by_key;
```

This is an ordinary daemon-owned C++ record, not a Slog-visible schema object
or a versioned meta-schema. Store descriptors in pointer-stable owned storage
and let both maps index them. The first refactor need not redesign struct
interning: the descriptor may
delegate to the same latest struct relation that `structs_by_id` uses today.
The important invariant is that the descriptor survives rename/drop and is
not discovered by scanning the current name map. A later cleanup can move the
canonical intern pool fully out of relation-version storage if branching or
GC requires it.

*As built (N3-C, 2026-07-25):* `Database` owns pointer-stable
`TypeDescriptor`s indexed directly by SID and TypeKey. A 16,383-bit occupancy
map reserves SID 0 and allocates the lowest free member of `1..0x3ffe`; root
BIN loads reserve their exact sparse assignments, committed history keeps an
SID occupied after drop, and provisional SIDs remain conservatively burned
after abort. The public descriptor advances to successor storage only at
boundary commit. Prepared plugins instead resolve through a private
SID-to-storage overlay, so abort cannot expose a TypeKey or replace the
canonical intern relation.

`(catalog types)` now enumerates the registry rather than current relation
names. Its `name` projection is `#f` for a retained descriptor with no current
binding. Struct rendering decodes SID through the descriptor, selects storage
and constructor spelling from an explicit historical BoundaryKey when one is
available, and prints an explicit `<type TypeKey>` constructor when no public
name exists. N4 still owns persisted TypeKeys/catalogs and explicit
source-TypeKey-to-destination-TypeKey import mapping; N3-C makes both load and
import SID allocation gap-correct underneath that future metadata.

#### 8.5.4 Persistence and import

Add a catalog table to META (or a separately checksummed catalog file) with
BoundaryKey, QName components, normalized declaration descriptors,
VersionKeys, TypeKeys, and predecessor/event information. Tuple directories
remain a materialization format and may continue omitting empty relations.
On load, restore the catalog and declare every logical member before loading
rows.

Root replay preserves recipe keys but may choose new runtime SIDs. Independent
namespace import performs one source-TypeKey to destination-TypeKey/SID map:
reuse the destination TypeKey for compatible existing members, or mint a new
one for a fresh destination namespace. Then reuse the shipped transitive word
remapper. Import must never equate nominal types merely because declaration
hashes match.

The target N4 format has no permanent compatibility mode for catalog-less
databases: it requires the complete catalog and rejects an input that lacks
it. N2-B has a narrower transition bridge while old roots still exist: before
the first planned program it may adopt only currently live storage reachable
from that program's exact declaration graph, using the daemon's current
VersionKeys, and must reject a referenced storage declaration without a live
key. This is not a kind/arity shadow catalog and is removed once N4 catalog
persistence is the required input format.

### 8.6 API and diagnostics

All relation-taking actions must accept qualified names. Errors should print
the full name and the instance chain that introduced it. Useful
introspection includes:

- module instance tree and source fingerprints;
- declared schema members under each namespace;
- formal-to-actual namespace bindings for each program instance;
- program/stratum instance keys and current pipeline positions;
- relation version chains with qualified display names;
- boundary catalogs and their catalog/name deltas;
- TypeKey-to-SID mappings and SID-space usage;
- whole-namespace attachment mappings.

This makes the feature understandable when a database is built from several
programs rather than only when reading one source file.

## 9. Relationship to generic SCCs

For the SCC example, the first slice is already valuable:

- declare vertex positions as `any`;
- instantiate the module once per logical graph;
- derive each instance's `edge` relation from anywhere;
- consume its qualified `scc` relation;
- rely on fresh namespaces instead of adding a graph-id column.

A reusable SCC module can make its graph a formal child schema. It then has
both natural workflows:

```slog
;; Own a private graph and let client rules fill it.
instantiate "scc.slog" as loops
rule (call_edge f g) --> (loops.graph.edge f g)

;; Or operate directly on the graph portion of a richer CFG database.
instantiate "scc.slog" as cfg_loops with graph = cfg
```

The second binding requires the SCC module's graph members but preserves all
other `cfg.*` members. SCC results not explicitly bound remain isolated under
`cfg_loops.*`.

`any` supports integers, strings, and struct values at runtime, so this is a
real generic library even without static type parameters. Separate instances
also avoid the memory and join cost of batching unrelated graphs behind an
extra key.

A future type binding such as “vertex is `syn.Exp`” could improve static
checking, but it should specialize only the declaration schema. It must not be
the mechanism that creates instance identity. The namespace occurrence
already does that.

## 10. Implementation sequence

The implementation should land in dependency order rather than as one parser
patch followed by a long tail of special cases.

### N0: qualified-name substrate

1. Add a structured qualified-name representation and parse `id(.id)*` in
   name positions without changing numeric literals or the existing dot
   operator accidentally.
2. Centralize comparison, display, C++ mangling, action serialization, and
   reversible database filename encoding.
3. Move type environments, manifests, rule relation sets, and version-chain
   metadata onto the representation while keeping every old root-level
   program byte-for-byte equivalent at the language level.

### N1: lexical module instances

1. Parse `instantiate "..." as name [with ...]` and build a module-instance
   occurrence tree rather than set-unioning every source path globally.
2. Qualify declarations, types, rules, facts, demands, lattices, and generated
   helper names before the existing compiler passes.
3. Assign `ModuleInstanceKey`s and qualify rule provenance.
4. Allow client rules to read and write qualified members and support two
   isolated instances of one source.

### N2: catalog and temporal planning

1. Extend `run` with `as` and the same `with formal = actual, ...` clause;
   leave bare `run` at the current home.
2. Apply structural interface validation and formal-prefix substitution before
   type checking and stratification.
3. Introduce `DeclarationDescriptor`, `CatalogDelta`, `BoundaryPlan`, and a
   session catalog that includes empty members.
4. Plan compatible overlap, additive completion, initial slots, successor
   slots, and failure atomically from the rewritten actual write set.
5. Assign `ProgramInstanceKey`, `BoundaryKey`, `VersionKey`, and `TypeKey`
   slot tables; capture bindings and exact input VersionKeys in the recipe.

**Checkpoint 2026-07-24 (N2-A — immutable catalog/boundary producer):**
`compiler/catalog.rkt` is now the transport-free authority for normalized
`TypeRef`, lattice, `DeclarationDescriptor`, `CatalogDelta`, catalog,
boundary, and `BoundaryPlan` values. It consumes the existing N0 QName
representation and a program's type environment, preserving exact field
references, lattice/collection descriptors, union membership closure, and
empty storage declarations. Boundary planning is a pure operation over an
explicit input `C_k`/`E_k`: it validates the complete overlap and reference
graph first, retains omitted/compatible members, adds missing members, gives
new storage an initial slot, gives written existing storage one successor,
and allocates new struct `TypeKey`s. Program, boundary, version, and type
keys use caller-supplied LayerId/event inputs; every created relation/type
slot is assigned once in sorted QName order and returned as an immutable slot
table.

`compiler/modules.rkt` now exports that normalized `CatalogDelta` producer and
derives its legacy flat manifest from the same descriptors. The manifest is
therefore a one-way code-generation ABI projection, not a second public
declaration-shape implementation. Today's compiler-reserved `$...`
supplementary relations remain an explicitly execution-only manifest appendix
until N1 replaces that convention with internal IDs/path components, as
required by §8.3. Anonymous lattice clamp names now encode non-QName
characters deterministically (notably a negative/exponent sign) before
entering the catalog. Eight focused cases plus the 266-case
compiler unit suite pin empty initial members, retain/create/successor
semantics, the new-and-written single-slot rule, additive membership,
deterministic qualified slots, TypeKey retention, atomic incompatibility, and
the public/internal legacy projection boundary.

This is N2-A, not N2 completion: the current positional program tuples and
live session still use the flat manifest ABI. N2-B must carry each program
group's `CatalogDelta` and actual write set into this producer and retain the
selected boundary in session/recipe state. N2-A deliberately does not add a
shadow session head. If N2-B records a logical post-fixpoint head before N3,
that bridge must remain explicitly non-atomic: only N3's prepared daemon
overlay can couple logical and physical publication. N1 will later feed
multi-instance qualified declarations into the same producer without
changing its key allocation rules.

**Checkpoint 2026-07-24 (N2-B — compile/session boundary bridge):**
`compile-strata` now returns one `compile-group` per dependency-ordered
program. The named value carries its stratum count, frozen imports,
`CatalogDelta`, complete execution write set, and public catalog write set.
Actual writes come from the same emitted-stratum sidecars and frozen relation
directories used by execution. A write enters the public set only when its
QName names storage in that group's delta, keeping `$...` support relations
strictly outside the logical catalog. A declaration-only program therefore
survives compilation as a zero-stratum group rather than disappearing.

The session pure-plans the whole group chain before issuing a daemon request.
Each immutable `BoundaryPlan` now carries its LayerId and program, boundary,
and type events in addition to complete normalized delta, retain/create
actions, exact predecessor VersionKeys, and deterministic slot tables.
Recipes persist one plan beside each exact daemon VersionKey table. On replay,
the source is compiled again and `replay-boundary-plan` reconstructs the plan
from the selected input boundary; any mismatch in the persisted semantic
datum is a typed `recipe-plan-mismatch` refusal. The older bare and
version-events-only run recipe forms remain readable.

After each group reaches fixpoint, `session-run!` publishes its logical
output `C_k`/`E_k` and records the plan in boundary history. Open clears the
old head and rebuilds it through recipe replay. Rename, drop, import/link, and
input injection invalidate the head because N2 has no catalog transaction for
those operations; the next run re-adopts the live environment. For an older
catalog-less root, that adoption is intentionally narrow: start from storage
which is actually live and present in the next delta, close through its
declaration references, retain the daemon's exact VersionKeys, and refuse a
referenced storage type which has no live key. It neither reconstructs nor
invents declarations absent from the next program.

This bridge preserves the N3 boundary rather than claiming it. The logical
head advances only after successful fixpoint, but the legacy
`begin-segment/keyed` mutation is not private or atomic; declaration-only
initial slots are planned logically but are not materialized until a plugin
registers them; and transition TypeKeys for adopted structs are not durable
SID descriptors. N3 must replace those gaps with prepare/commit/abort, eager
declaration of every planned empty member, direct VersionKey/BoundaryKey
indexes, and durable TypeKey/SID records. N4 then persists the complete
catalog independently of recipe source and removes transition adoption.

Coverage now includes nine pure catalog cases, two compile-group cases, the
269-test compiler unit tier, fresh and catalog-less save/replay probes, a
declaration-only session boundary assertion, and all 605 session checks.

### N3: daemon boundary and type registry

1. Add preflighted prepare/commit/abort boundary requests that declare missing
   members and open all planned initial/successor relation slots privately
   until fixpoint. **Landed as N3-A (2026-07-25):** complete preflight, eager
   empty slots, private plugin environment, terminal-fixpoint commit,
   suspended-run abort/rollback, session integration, and durable TypeKey
   re-adoption across legacy environment events.
2. Index VersionKey directly and attach BoundaryKeys to binding events while
   retaining numeric pipeline positions as runtime ordinals. **Landed as
   N3-B (2026-07-25):** committed bindings carry BoundaryKey, each evaluation
   owns a direct immutable boundary index plus ordered conservatively retained
   history, and Q1 binds through the selected boundary before checking the
   exact VersionKey. Numeric positions remain evaluation-local execution and
   maintenance ordinals.
3. Replace name-discovered `structs_by_id` with durable SID/TypeKey
   descriptors and a lowest-free SID bitmap; keep current struct relation
   storage behind the descriptor.
4. Teach lookup, sizes, batch, rename, drop, and version-chain actions
   structured qualified paths; make subtree operations atomic.

### N4: persistence and the first REPL

1. Round-trip catalogs, keys, qualified tables, lattices, structs, and nested
   values through save, open, import, and compressed replay; restore empty
   declarations before tuple data.
2. Extend import preflight from flat name maps to namespace maps and perform
   explicit source-TypeKey to destination-TypeKey/SID mapping.
3. Expose boundary catalogs, module/program instances, bindings, homes,
   version chains, and type registries through structured introspection.
4. Implement boundary handles, completion, relative lookup, absolute
   VersionKey lookup, and history display in `compiler/run.rkt`.

### N5: internal namespaces and observability

1. Give stats `RuleKey`s their `ModuleInstanceKey` component immediately.
2. Once namespace policy exists, migrate `$stat_*`, `$seq_*`, and `$sup*`
   prefix conventions deliberately rather than by blind string replacement.
3. Add the small daemon event/watch/breakpoint protocol from [repl.md](repl.md)
   at iteration, stratum, and program safe points.
4. Consider user lifecycle monitors only after ordinary relation/tuple watches
   demonstrate a need beyond the built-in stats and debugger protocol.

N0-N3 are the smallest coherent in-memory module slice; N4 makes it durable
and interactive. Privacy, export lists, type parameters, generalized
cross-database attachment syntax, and the N5 lifecycle-monitor
surface remain later work. The early metadata must nevertheless distinguish
declaration shape, module instance, program instance, boundary, binding,
relation version, nominal type, and execution identities so those additions
do not require another naming redesign.

## 11. Tests that pin the semantics

The initial suite should include:

1. instantiate a reachability/SCC module twice and prove no cross-instance
   path or component appears;
2. add client facts and rules directly to an instance's input relation;
3. use `syn.Const` beside a distinct local `const`/`abs.const` constructor;
4. qualify struct values nested inside other structs, sequences, sets, maps,
   and lattices;
5. exercise nested include and nested instantiate with a diamond include;
6. reject duplicate aliases and conflicting client redeclarations;
7. save, reload, and database-merge a qualified schema containing structs;
8. map one persisted namespace to another prefix, atomically complete a
   compatible partial schema, and reject an incompatible schema before
   mutation;
9. bind a small graph interface to a richer CFG namespace and preserve the
   CFG-only members;
10. instantiate the same source rule twice and verify distinct `RuleKey`s and
   unambiguous stats rows;
11. prepend a pipeline program and verify stable instance/version keys while
    display positions change.
12. run two programs successively at the unnamed current home and verify the
    second reads the first's versions while each has a distinct
    `ProgramInstanceKey`;
13. run twice `as p` and verify that `p.*` advances rather than allocating a
    second same-path namespace;
14. preserve source order among sibling `run` prerequisites that write the
    same relation.
15. atomically rename and drop a nested namespace while old database handles
    and captured program bindings continue to resolve their historical
    `VersionKey`s.
16. retain empty declared members across a boundary, save/reload, completion,
    and namespace attachment;
17. preserve TypeKey and SID across rename and successor versions, allocate a
    fresh pair after drop/redeclare, and allow replay to change SID while
    preserving TypeKey;
18. decode and pretty-print a struct value whose constructor has no current
    public name by using its TypeKey and the selected historical boundary.
19. rename a namespace referenced by an outside relation's field type and
    update that TypeRef without changing TypeKey; reject a drop that would
    leave the outside declaration dangling.
20. load or import sparse SID assignments, allocate new TypeKeys into the
    lowest genuine gaps, and never reuse an SID retained only by history or a
    REPL value handle.

## 12. Decisions made and details still to pin down

The design now commits to these principles:

- every source closure is a module template without requiring a declaration;
- the database is an arbitrarily nested namespace tree;
- every lexical module occurrence has a `ModuleInstanceKey` and home
  namespace;
- every temporal run has a distinct `ProgramInstanceKey`, even when it reuses
  the current home namespace;
- `include` is open lexical composition, `instantiate` is namespaced lexical
  composition, and `run` is temporal instantiation;
- unnamed `run` uses the caller's current home as both input and output,
  preserving today's behavior;
- `as` introduces one child home component and `with formal = actual, ...`
  is the common binding grammar for `run` and `instantiate`;
- every explicitly instantiated child is bindable without a separate port
  declaration;
- an actual namespace satisfies a formal structural schema when every
  overlapping declaration is compatible after prefix substitution; missing
  declarations are added atomically and extra actual members are allowed;
- one whole-namespace binding mechanism adapts reusable programs to existing
  sub-databases;
- binding is not implemented as database rename or tuple copying;
- ordinary rules may read and write a bound namespace, with pipeline versions
  preserving the temporal history;
- relation and namespace environment operations share one structured-path
  syntax and apply atomically to a subtree when the path names one;
- qualified names are boundary-relative, VersionKeys are absolute relation
  slot identities, TypeKeys are nominal struct identities, and SIDs are
  evaluation-local encodings;
- schema growth is a catalog/environment transition, not a separately
  versioned meta-schema;
- root namespaces receive external database handles in interactive tooling,
  not compiler-visible `db0.` prefixes.

Before implementation, one policy still needs experience from the REPL:

1. **History retention.** Pin when an unreferenced BoundaryKey and its
   relation materializations may be garbage collected. The initial policy is
   conservative retention. SID allocation itself does not wait on this
   decision: it fills every genuinely unused gap and never moves a live type.

Two possible later capabilities do not need syntax now. A **type parameter**
would be a compile-time hole used to state correlations such as
`edge(Vertex, Vertex)` and `scc(Vertex, int)` more precisely than `any`; it
would not be a runtime TypeKey. A **lifecycle monitor** would run user code at
committed iteration/stratum/program events to consume runtime observations; it
is a stats feature, not a module initializer/destructor. The current wildcard
interface and built-in stats require neither feature.

The central language promise is simple: **every program occurrence has fresh
identity; a newly named namespace is isolated; and an inherited namespace is
reused only by choosing the same path or by an explicit checked binding.**
