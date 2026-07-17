# Slog user documentation

These pages describe the language and the system as they work now. They are
written for readers who know an ordinary programming language and already
understand the basic idea of facts and rules.

If you have not run a Slog program yet, start with the
[short tutorial](../tutorial/01-getting-started.md). Then use these guides as
needed:

1. [Language reference](language.md) — declarations, rules, patterns, types,
   recursion, negation, modules, and errors
2. [Built-in operations](builtins.md) — every value primitive, comparison,
   partial operation, built-in type, and reserved runtime relation
3. [Lists, sets, and maps](collections.md) — literals, patterns, native
   operations, and the rule-based compatibility libraries
4. [Demand functions and lattices](functions-and-lattices.md) — memoized
   relational calls, closures, converging summaries, and soundness checks
5. [SMT library](smt.md) — formulas, solver setup, verdicts, models, unsat
   cores, persistence, and failure behavior
6. [Running Slog](running.md) — native REPL, batch command-line options,
   configuration, output, errors, statistics, and tests
7. [Persistent databases](databases.md) — exact and compressed saves, replay,
   database commands, edits, verification, and follow-up queries
8. [Racket APIs](api.md) — live sessions, batches, incremental updates,
   versioned program segments, and the low-level action protocol
9. [How Slog runs](architecture.md) — compiler passes, generated plugins,
   fixpoint execution, storage, demand transformation, and persistence
10. [Extending Slog](extending.md) — adding a primitive or a daemon oracle,
    including type, error, lattice, and test work

The main [README](../../Readme.md) is the project overview and install path.

## Reference or design record?

Files in this directory are user-facing reference material. Files directly
under `docs/` record the design and implementation of individual subsystems.
The latter are useful when changing Slog, but some read like development
journals and preserve old milestones for context. When the two disagree about
the current public interface, use this guide and the code.

The extension guide links to the relevant implementation records where their
extra detail is useful.

## Conventions used here

Code blocks marked `slog` are Slog source. Commands assume the repository root;
`./slog` enters the REPL and this form performs a batch run:

```console
$ racket compiler/run.rkt --no-banner program.slog
```

Relation signatures show column types after the relation name:

```slog
table (edge str str)
```

Examples use lowercase names when a variable plays a local role and uppercase
names when it makes joins easier to see. Slog does not use capitalization to
distinguish variables from constants. A bare identifier in a rule is a
variable unless it names a constructor or built-in constant in that context.

## Current boundaries worth knowing

- Run the command-line tool from the repository root.
- Relations need at least one column. Zero-arity relations are not supported;
  use a one-column marker table instead.
- Rule evaluation is set based. There is no row order and no duplicate count
  unless a lattice records one.
- Ordinary positive recursion runs until a fixpoint, but a program that keeps
  generating fresh values need not terminate.
- Negation is stratified. It reads a completed lower stratum rather than
  temporary absence inside a recursive fixpoint.
- `extern` is an internal-facing oracle boundary with a narrow v1 signature,
  not a general foreign-function interface.

## Examples in the repository

The `examples/` directory contains complete analyses:

- `examples/regex/` uses demand-driven derivatives for regular expressions.
- `examples/domtree/` computes dominators, a dominator tree, and natural loops
  with set lattices.
- `examples/verify/` combines program verification rules with the SMT library.
- `examples/tinycfa/`, `examples/schemecfa/`, and `examples/kcfa/` build
  progressively richer control-flow analyses.
- `examples/sudoku/` shows a different style of relational search and
  propagation.

The `tests/*.slog` files are also useful small examples. Each normally isolates
one language or runtime behavior.
