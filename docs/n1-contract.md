# N1 contract: lexical module instances

2026-07-26. **Implemented.** This contract turns the N1 design in
[modules.md](modules.md) into three reviewable slices against the shipped
N0/N2/N3 substrate. N1 is a compiler-front-end feature: it does not create a
runtime module object, fixpoint boundary, scheduler, or database copy.

## 1. User-visible contract

```slog
instantiate "graph.slog" as left
instantiate "graph.slog" as right
```

creates two lexical occurrences. An unqualified declaration `edge` in the
first source closure denotes `left.edge`; in the second it denotes
`right.edge`. Rules from the two occurrences meet only when a rule explicitly
connects their qualified members.

`include` remains open composition in the current occurrence. Include
deduplication is local to that occurrence. Two explicit `instantiate`
directives are never deduplicated merely because they resolve to the same
canonical source path.

All first-version members are public. Module instances do not imply physical
stratum or scheduling isolation.

## 2. Representation and ownership

The resolver builds one immutable occurrence tree per temporal program. Each
node records:

- canonical source entry path and captured source closure;
- home QName path;
- lexical occurrence path;
- formal-to-actual namespace bindings;
- included source units; and
- explicitly instantiated child occurrences.

The final program IR uses named transparent records for its modules and
occurrence tree. The existing symbol-keyed middle end remains unchanged:
qualification lowers paths through `compiler/names.rkt` before
simplification, typechecking, and stratification.

The root occurrence has lexical path `()`. A child lexical path appends one
deterministic occurrence slot and its source alias. A `ModuleInstanceKey` is
formed from the enclosing `ProgramInstanceKey` plus that lexical path; it is
never derived from an absolute filesystem path, source text, a QName, or a
pipeline position.

## 3. Qualification

Qualification runs after one occurrence's include closure is resolved and
organized, but before program-level type environments are merged and before
demand/collection expansion.

- unqualified module-owned declarations and references are relative to the
  current home;
- a path beginning with a child alias is relative to the current home;
- a path beginning with a bound formal is prefix-substituted with the captured
  actual path;
- builtins, primitives, variables, and literals are unchanged;
- there is no implicit parent or sibling search;
- declaration keys, field TypeRefs, union/enum members, lattices, demands,
  rules, facts, and generated owner-scoped names are transformed together; and
- rule provenance records the lexical occurrence separately from the source
  location so double instantiation cannot merge source-rule identity.

Root programs without `instantiate`, `as`, or `with` retain their existing
lowered names and semantic compile inputs.

## 4. Binding

Both occurrence forms use the same grammar:

```text
instantiate <string> as <id> [with <formal-path> = <actual-path>, ...]
run <string> [as <id>] [with <formal-path> = <actual-path>, ...]
```

Formal paths are relative to the new occurrence's home. Actual paths are
resolved in the caller's namespace. Formal prefixes may not overlap. Each
formal must name an explicitly instantiated child namespace.

Binding is a zero-copy QName rewrite, not a database rename or relation alias.
After rewriting, the actual namespace may contain extra declarations and may
atomically gain compatible missing declarations. Formal `any` is a recursive
wildcard only for interface satisfaction; the rewritten rules are checked
against the selected actual declarations. Ordinary unbound catalog overlap
continues to require exact equality.

The compiler therefore receives the selected input boundary catalog for a
bound program. It must not reconstruct field types from the flat codegen
manifest. The resulting rewritten `CatalogDelta`, actual read/write sets, and
captured binding map ride the existing `compile-group`/`BoundaryPlan` path.

## 5. Slices and gates

### N1-A — occurrence tree and plain instantiation

- parse plain `instantiate`;
- retain repeated occurrences of one source;
- scope include deduplication per occurrence;
- qualify complete declarations/rules and owner-scoped generated names;
- prove two SCC instances are isolated and client rules can feed one.

### N1-B — identity and provenance

- carry occurrence/home metadata in named program/module records;
- mint `ModuleInstanceKey`s from persisted ProgramInstanceKeys plus lexical
  paths;
- distinguish two copies of one source rule in diagnostics and rule metadata;
- preserve root-only program behavior and cache inputs.

### N1-C — namespace binding

- parse shared `as`/`with` syntax;
- implement centralized QName prefix substitution;
- carry the input catalog into compilation;
- validate wildcard structural interfaces before mutation;
- typecheck against actual declarations and publish one rewritten delta.

N1 exits when focused compiler/session tests cover double instantiation,
nested include/instantiate, alias collisions, client extension, qualified
structs/collections/lattices, distinct occurrence identity, binding to a
richer actual namespace, compatible completion, and atomic incompatibility;
the existing unit, compiler, protocol, and session gates remain green.

The landed focused gates are `tests/unit/n1-module-tests.rkt`,
`tests/n1_instances.slog`, and the two-segment live-catalog fixtures under
`tests/session/n1_*.slog`. N4 is intentionally outside this contract and was
not designed or implemented as part of N1.
