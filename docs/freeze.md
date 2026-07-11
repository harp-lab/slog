# Freezing ground facts to static databases

*2026-07-09.  Implemented: daemon/freeze.cpp (`slog-freeze`), compiler/freeze.rkt
(the peel pass), Daemon::importPath + the `(import-path ...)` action, driver
wiring in runslog.rkt.  Golden: tests/frozen_fact.slog.*

## 1. Why

A head-only rule whose heads are entirely ground asserts pure data.  Compiled
as a rule, a large one (an AST literal, a dumped program IR) pays staged
codegen and a clang invocation proportional to its size — and the emitted
read phases nest one brace scope per join, which overflows clang's own stack
around 400–500 deep even under `-fbracket-depth` (a ~500-node tree in one
fact is fatal; measured 2026-07-09).  Chained-replay staging
(join-planning.rkt) keeps any *modest* ground tree correct with zero-width
temps, but data at scale should never be compiled as code at all.

The freeze path renders such rules to a static `.bin` database at compile
time and links it in at run time.  A 16,383-node tree freezes and runs
end-to-end in seconds; its fixpoint work is milliseconds.

## 2. Placement model

- A frozen database lives in `build/frozen/<hash>/`, content-addressed by
  its fact stream plus the daemon-headers fingerprint (the value-encoding
  version).  The stream itself sits alongside as `<hash>.facts` for
  debugging.  Like every build artifact it is disposable: a wiped build/
  re-freezes from source on the next compile.
- The driver imports it (importDatabaseBIN's 4-id-space content remap)
  after the input DB's load steps and **before stratum 0**; the deferred
  reload hands the first stratum its rows as iteration-zero delta, exactly
  as a `-d` input's facts arrive.
- Saving to data/ needs nothing new: the imported rows are ordinary rows,
  so a saved database materializes them like any others, and everything
  downstream of data/ keeps the ordinary saving model.  Deleting data/
  entirely and rerunning re-links the build/ copy (or re-freezes it).

## 3. The fact stream (the producer contract)

`slog-freeze <out-db-dir> < stream` — the freezer takes **only data**: it
never parses .slog, never sees rules or variables.  Extracting freezable
content from a .slog is the compiler's job (§4).  The same stream format is
the direct door for external producers (a front end dumping IR):

    ;; comments run to end of line
    (struct <name> <field-count>)     an interned constructor
    (table <name> <arity>)            a relation facts assert into
    (enum <name>)                     (<name>) abbreviates (_enum "<name>")
    (<name> <term> ...)               a fact: a table row, or a struct
                                      instance to intern (a ground ask)

    term := int | float | "string" | [term ...] | (<struct> term ...)
            | (<enum>)

String escapes are exactly `\\ \" \n \t \r`; the compiler-side emitter
produces only those, everything else as raw UTF-8.  Integers of any size
(the mpz path), floats, nested sequences, and collections-through-structs
all encode through the *same* Database entry points the runtime uses —
`encodeIntLiteral`, `float_encode`, `encodeString`, the sequence kernels,
and import's struct-intern pattern — so frozen values are bit-compatible
with rule-derived ones and merge by content.  That single-implementation
property is why the freezer is C++ linking the daemon headers: a second
encoder implementation would eventually drift and silently break content
identity (the encodeString-normalization lesson).

Note "freezing a live database" is not this mechanism and needs none: a
live database already *is* the on-disk format — saving it is `write-db`.
Freeze is text→DB only.

## 4. The peel pass (compiler/freeze.rkt)

After module/type-env merging and the demand transform, a rule is peelable
when it is head-only and every head is a ground assertion into a plain
(non-lattice) table or a struct — the latter is a ground *ask*, since a
demand is its struct.  Gated judgment facts never qualify (their pattern
variables are gate-bound); neither does anything containing a variable,
a primitive computation, or a lattice-valued column (v1).  One "primitive
computation" is treated as data: a **ground sequence literal** — a `[e …]`
bracket lowers (before peel) to a nested `lempty`/`lpush`/`lcat` chain
(collections.rkt), which `seq-ctor?`/`seq->elem-strings` recognize and render
back to the `[e …]` stream form, so dumped ASTs full of lists freeze instead of
falling to the rule path (docs/freeze-list-peel-gap.md).

When a program's peelable rules total at least `SLOG_FREEZE_MIN` term
nodes (default 512; `SLOG_NO_FREEZE` disables), they are all removed from
the program and emitted as one stream (facts sorted for a deterministic
hash), frozen once, and imported at run time.  Below the threshold nothing
changes — small fact sets keep the zero-dependency rule path, and the two
routes are interchangeable because they intern identically.

Peeling is disabled under a source-override (a compression replay: the
recipe re-derives facts through the rule path — equivalent rows, just
slower) and for `--out-db-compressed` runs (the EDB-boundary split owns
iteration-0 facts there).  The peel happens before the stratum cache key
is computed, so peeled and unpeeled builds never share a .so.

## 5. Deferred

- Ground *subterms* of variable rules (peel the subtree, content-join the
  residual — chained replay against the frozen DB).
- Compile-time folding of ground primitive computations.
- Flat (non-nested) probe emission in emit-cpp, which would lift the
  rule path's ~400-deep nesting ceiling independently of freezing.
- A richer preamble for external streams (full column types, stricter
  checking); today's shape checks catch arity and undeclared names.
