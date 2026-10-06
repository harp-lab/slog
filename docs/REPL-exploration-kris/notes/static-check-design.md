# A static check for Slog, and how Studio gates on it

Design note, 2026-10-06, for discussion before the Slog-level part goes to master. Branch
`studio/static-check` (off `web-repl`). The Racket changes are drafts until this is agreed. The
Studio side is built on top of them.

## Why

Agent-written code reached the author without passing even a parse. In `arithm.slog`:

- #13 appended a `numlib` term with 7 unclosed parens, and its evaluation failed.
- #14 tried to fix it and also failed.
- #15 fixed the parens.
- The author could accept #13 without #15, and nothing checked the text that accepting produced.
- #16 was appended without being evaluated, and it put a constructor under `~`.

All of these are *static* errors. Run reported the paren error as `arithm.slog:300:1: Expected
an atom---literal, variable, s-expr, etc.`, at the end of the file instead of at the `(` that
was never closed.

Evaluating a program can take a long time. Rejecting it statically takes milliseconds. So it
should be checked up front, every time.

## What the check covers

The check is the compiler's own front end, stopped before planning. It reuses the same passes, so
a program passes the check exactly when compiling it would get past the front end.

| stage | pass (file) | catches |
|---|---|---|
| lex | `lexer.rkt` | hyphenated names, bad tokens |
| brackets | **new**, `parser.rkt` (`check-brackets`) | an unclosed `(`/`[`/`{` reported at its opener; an extra or mismatched closer reported where it is |
| parse | `parser.rkt` | malformed forms, reserved words |
| includes, `run`, `instantiate` | `modules.rkt` (`load-program-list`) | a missing include (warning today), bad namespace bindings, include cycles |
| demand | `demand.rkt` (inside `load-program-list`) | demand declarations and judgment uses |
| collections, enums, structs | `collections.rkt`, `modules.rkt` | declaration shape, arity |
| simplify | `simplification.rkt` | head wildcards, misplaced `~` (nested, in heads), constructors under `~` |
| lattice declarations | `lattice-check.rkt` | misplaced lattice types |
| seq expansion, fragment factoring | `seq-expand.rkt`, `fragment-factor.rkt` | sequence patterns |
| typecheck | `type-system.rkt` | undeclared relations and structs, arity, type clashes, unsafe negation, enum members used as variables |
| stratify | `stratify.rkt` | negation and aggregation through recursion |
| lattice strata | `lattice-check.rkt` | non-monotone use of a still-ascending lattice value |

The check stops before join planning, lowering, canonicalization and C++ emission. It also
computes no cache key, peels no ground facts, touches no daemon, session or database, and writes
nothing to disk.

### What it cannot catch without running

- **Runtime errors.** Division by zero, `malformed_deduction` rows (they become `(error e)`
  facts), and oracle and SMT failures.
- **Termination and blow-up.** A rule that builds terms forever, or a quadratic sequence index.
  The front end already warns about that last one (`docs/sequences.md` §5.3), and the check
  passes the warning through.
- **Meaning.** A program that compiles but derives the wrong thing. That is what
  `evaluate_proposal`, queries and scenarios are for.
- **Back-end failures.** Planner contract failures and C++ toolchain errors. These are compiler
  bugs, not user errors, and are rare under the interpreter that Studio's Fast mode uses.
- **Input databases.** A program run with `-d DB` may read relations that only the database
  declares. The check takes an empty input manifest, so such a relation reads as undeclared.
  Studio always evaluates from nothing, so this does not arise there. The CLI could take `-d`
  later (see open questions).

## Where it lives: no duplicated passes

`compile.rkt`'s `program->jobs` mixed two things: the semantic front end, and the cache key
plus peeling and job assembly. The front end moves out, unchanged, into one function:

```racket
;; compile.rkt
(define (program-front-end mods type-env decomps)   ; simplify .. lattice strata
  ...
  (values typed type-env+ extra-edges extra-edge-kinds full-strata full-model))

(define (check-program prog)                        ; exported
  (program-front-end (program-ir-modules prog) (program-ir-type-env prog)
                     (program-ir-decomps prog))
  (void))
```

`program->jobs` calls `program-front-end` and then does what it always did. The check calls it
alone, on the *unpeeled* modules, so a large block of ground facts is typechecked too.
(`program->jobs` peels big fact blocks into a frozen stream before the front end runs.)

A new `compiler/check.rkt` drives the check. It parses with `parse-errors-raise?` set, so a
syntax error raises a located `exn:fail:slog-parse` instead of printing it and exiting. Unsaved
text comes in through the existing `current-source-override` hook (source-key → text), the one
the recompute-on-load replay uses. An editor's buffers can therefore be checked where they sit,
and includes resolve against them. `check.rkt` turns what it catches into diagnostics.

## The error format

A diagnostic is one record:

```json
{"severity": "error", "file": "/abs/arithm.slog", "line": 259, "col": 3,
 "message": "the ( at 259:3 opening (source \"numlib\" (app (lam … is never closed (7 open at end of file)"}
```

- **Lines and columns are 1-based**, as in `rule-location-string` and editors.
- **Where a location comes from:**
  - the fields of `exn:fail:slog-parse`;
  - otherwise the first `NAME.slog:LINE:COL` in the message whose file name is one of the
    program's sources. The typechecker, simplifier, stratifier and lattice checks already spell
    locations this way, through `rule-location-string`.
  - An error with no location (a few declaration errors, such as `Table or struct pos must
    have at least one column`) is reported at line 1 of the main file and marked `"located":
    false`. Locating those is follow-up work in the pass that raises them.
- **Warnings** (a missing include, the sequence blow-up warning) are captured from the front
  end's stderr while the check runs, and become `"severity": "warning"` diagnostics.

### Many errors, or the first

- **Parse:** the first error only. The parser does not recover. The bracket pass runs first,
  though, so an unbalanced program gets the bracket diagnostic, which is the useful one.
- **Typecheck:** every rule's error. `typecheck-rules` already checks one rule at a time inside
  `with-rule-context`. When the check sets the new parameter `current-rule-errors`, a failing
  rule's error is recorded and the rule skipped, and the pass then fails as a whole, so no later
  pass sees a half-checked program. This changes nothing when the parameter is unset (compiles,
  the REPL).
- **Stratify and lattice strata:** the first error. They are whole-program analyses, and their
  first error is usually the only one.
- **Recovery after a parse error** (re-syncing at the next column-0 `rule`/`table`/…) is
  possible, because top-level forms are keyword-delimited. It is not in this cut (see open
  questions).

### Unbalanced brackets

A pass over the token stream runs before parsing. Strings, `'refs'` and comments are already
single tokens, so their brackets don't count. It keeps a stack of openers:

- **A closer with an empty stack:** `the ) at 12:18 has no ( to close` (and likewise `]` and
  `}`).
- **A closer that does not match the top:** `the ] at 4:9 does not close the ( at 4:2`.
- **Openers left at end of file:** the culprit is the **outermost** unclosed opener. That is the
  form that never ended. There is one refinement: if a top-level keyword (`rule`, `table`, …)
  appears at column 1 while openers are still open, the culprit is the outermost opener open at
  that point. The form before the keyword is the one missing its parens, even though the error
  only shows at end of file. The message quotes the form's first tokens:

  `the ( at 259:3 opening (source "numlib" (app … is never closed (7 open at end of file)`

The error is raised through `parse-error`, so it is located, and the command-line printer shows
the source from the opener. Tests are in `tests/diag-tests.sh`.

## Interfaces

**CLI.**

- `racket compiler/check.rkt [--json] FILE …` and `racket compiler/run.rkt --check FILE`.
- Human output is `FILE:LINE:COL: error: message`, one per line.
- `--json` prints `{"ok": bool, "ms": n, "diagnostics": [...]}`.
- The exit status is 0 when the program is clean and 1 when there are errors. Warnings alone
  exit 0.

**Serve mode, for Studio.** `racket compiler/check.rkt --serve` reads one JSON request per line
and writes one JSON response per line:

```json
{"id": 1, "path": "/abs/main.slog", "sources": {"/abs/main.slog": "...", "/abs/lib.slog": "..."}}
```

Paying Racket's module load once matters (next section). The checker is a separate process from
every lane: it holds no session and no daemon, so a check never waits behind a run or disturbs
one.

**REPL.** `check PATH` answers a `kind: "check"` result: the diagnostics, `ok`, and `ms`. It
reads no session and changes none, so it is safe while a run is held.

## Performance

The budget is well under 100 ms for a typical program. Below are the full check with the
editor's info (`check-file/info`), median of 7 in a warm process, CPU and wall, measured with a
load average around 50. Earlier, with the load near 150, wall times ran 2–3× the CPU times.

| program | lines | CPU | wall |
|---|---|---|---|
| `tests/reach.slog` | 18 | 2 ms | 2 ms |
| `tests/tycheck_basic.slog` | 26 | 3 ms | 3 ms |
| `examples/domtree/domtree.slog` | 131 | 13 ms | 16 ms |
| `examples/scc/tarjan.slog` | 224 | 77 ms | 101 ms |
| `arithm.slog` (Kris's) | 501 | 108 ms | 136 ms |
| `examples/schemecfa/schemecfa.slog` (+ 6 includes) | 77 + ~700 | 103 ms | 134 ms |
| `examples/kcfa/kcfa.slog` (+ 4 includes) | 76 + ~800 | 185 ms | 252 ms |

How that splits for `arithm.slog`:

- parsing and resolving: 39 ms;
- the front end: about 50 ms;
- the editor's info: about 20 ms.

Small and medium programs are well inside the budget. The 500–900-line programs are at
100–190 ms, which is still below one debounce interval plus a keystroke, and is what incremental
checking (below) would buy back.

For comparison, `program->jobs` on `arithm.slog` takes about 520 ms. Most of that is printing the
cache key.

Two fixes in the shared code paid for the budget. Both are behaviour-preserving:

- **`emit-expr`** (parser) found an expression's last token by walking with `equal?` and
  `first`. It now walks with `eq?` on the shared token list. Parsing `arithm.slog` went from
  66 ms to 39 ms. All 344 `.slog` files under `tests/`, `examples/` and `lib/` parse to
  `equal?` ASTs before and after.
- **`gensymb`** shuffled a 186-character list to draw 12 characters, about a tenth of the front
  end. It now draws each character directly. The counter suffix still guarantees uniqueness.

What remains is mostly `equal?`-hashing of provenance-carrying rules into sets. It is spread
across the passes and not worth chasing yet.

A **cold** CLI process spends about 0.7 s CPU (about 1.3 s wall) loading the compiler's modules.
Hence serve mode for anything interactive. Studio also memoizes results by the hash of the
checked sources, so re-checking unchanged text (a re-render, a second tab) is free.

## Incremental checking of one edited form

Not in this cut. A typical program checks faster than a debounce interval, so the editor gains
little from it. When large programs need it, the shape would be:

1. Split the text at top-level keywords. That split is the parser's own form boundary.
2. Cache each form's parse by text, keyed with its starting line so locations stay right.
3. Re-run `load-program-list` from the cached forms.
4. Re-typecheck only the rules whose text changed, plus rules over relations whose declaration
   changed.
5. Stratification is global but takes about 5 ms; re-run it whole.

The cost of steps 2–4 is a cache keyed on positions, because provenance tokens carry absolute
line numbers. That is the main design question if this is wanted.

## How Studio uses it

- **Live diagnostics.** About 400 ms after the author stops typing, the tab sends its texts of
  all project files on the websocket (`{t: "check", tag, texts}`). Studio passes them to its
  checker process (`studio/src/check.rs`), which answers `{t: "checked", tag, ...report}`.
  The diagnostics become Monaco markers under their own owner (`check`): squiggles, the gutter,
  and the overview ruler. A diagnostic in an included file marks that file's model. An answer
  that arrives after newer typing is dropped by its tag.
- **Run pre-check.** Run and Debug check the program first. (Scenarios, on their own lane, do
  not yet.) A failing check
  refuses fast, with the located error, as an evaluation entry, and marks and reveals it. No
  session is started or discarded.
- **Proposal gating.** There are four layers, and together they guarantee that **whatever the
  author can accept leaves a program that checks**:
  1. *Propose-time.* `propose_edit`, `propose_append`, and the new `propose_changes` (a batch
     applied atomically, for edits that are only consistent together) check the thread's fork as
     the proposal would leave it. A failure refuses the proposal, and the tool result carries the
     located errors, with lines in the fork's text, for the agent to fix and re-propose.
  2. *Corrections fold.* An edit whose `old_text` lies inside an earlier pending proposal of the
     same thread rewrites that proposal instead of stacking a corrective op. The author reviews
     final text, not the agent's history.
  3. *Accept-time.* Accepting an op checks the text that accepting produces.
     - If the op alone does not apply or does not check, but it does together with the earlier
       pending ops of its thread that it builds on, Accept takes those too and names them ("with
       #13").
     - Otherwise Accept is disabled, with the located error and the reason.
     - The server enforces this too: `accept` refuses a failing result, whatever the UI showed.
     - Accept changeset checks the final text once.
  4. *Turn end.* A turn may not end with the fork failing the check, or with proposals made after
     the last `evaluate_proposal`. If it would, the runner resumes the agent with the errors or a
     request to evaluate, for at most 2 rounds.
- **The REPL assistant.**
  - It gets `propose_edit` and `propose_append`. Its fixes become ordinary inline proposals, gated
    the same way, with a chip in its answer ("Proposed a fix · view · accept").
  - The ```slog blocks and scratch definitions it suggests are checked against the program, and
    a block that does not check shows its error and is not offered as runnable.

## What the check learns, for the editor (hovers, hints, navigation)

The typechecker already infers every variable's type in each rule. It now
hands them out: a new `current-rule-types` parameter in `type-system.rkt`,
set only by the check, receives each rule with its local type environment.
`check.rkt` adds an `info` object to every report that got past parsing:

```json
{"rules":   [{"file", "line", "col", "end_line", "end_col",
              "vars": [{"name": "x", "type": "int", "line", "col"}]}],
 "symbols": [{"name": "eval", "kind": "table", "signature": "(table str expr list list kont)",
              "decl": "table (eval str expr list list kont)", "doc": "(eval p e env t k)",
              "def": {"file", "line", "col"},
              "refs": [{"file", "line", "col", "role": "def|write|read|use"}]}]}
```

- **Vars.** The vars are those the typechecker typed, each at its first
  occurrence in the rule's span. Compiler names such as `_tconst…` never
  appear in the source, so they are never listed.
- **Symbols.** Symbols are every declared relation, struct, union member and
  lattice, read from the module tokens the loader already keeps:
  - `decl` is the declaration as written. That covers demand signatures,
    since `demand (lookup list str) addr` is shown as written.
  - `doc` is the comment beside the declaration, or the comment block above
    it.
  - `refs` are every occurrence. A head atom counts as a write, a body atom
    as a read, and anything else as a use: a nested constructor, or a
    column type.
- **Cost.** The extra work is about 20 ms on `arithm.slog`. Identifier tokens
  are indexed by line, and file names are memoized.

Studio (`web/check.js`) registers Monaco providers fed from the last report
that got past parsing. They never wait on a check, and they survive a
half-typed form:

- **Hover:** a variable's inferred type; a relation's declaration, its
  comment, and how often it is written and read.
- **Inlay hints:** each variable's type after its first occurrence. They are
  off by default, toggled from the palette ("Inferred types inline").
- **Go to definition (F12) and find references (Shift+F12).** Models are
  named `studio:/PATH`, so a definition can point into another project file.
  An editor opener opens that file.

### One hover for two analyses

The `studio/slog-in-slog` branch adds semantic hover content: who derives a
relation, whether it is recursive, and its row count at the last Run. Both
analyses use Monaco's own merge, so there is no shared endpoint:

- **Separate providers.** Each analysis registers its own
  `registerHoverProvider("slog", …)` and `registerInlayHintsProvider("slog",
  …)`. Monaco shows every provider's hover part in one hover, in
  registration order. The check registers at editor creation, so its part
  (the signature and type) comes first and the semantic part follows.
- **Shared key.** Hover content about a relation is keyed by its name: the
  word under the cursor, as the check's `symbols[].name` spells it. Models
  are `studio:/PATH`, and positions are 1-based.
- **Hints.** Each analysis owns its inlay hints and its own palette toggle.
  Both are off by default.
- **Cost.** Providers answer from cached results only, and never request
  anything while a hover is open.

## Open questions

1. **Missing include.** It is a warning today, because a stale include should not block a run.
   Should the check make it an error? Studio shows it as a warning squiggle, which seems right.
2. **Parse recovery.** Re-sync at the next column-1 top-level keyword, and report one error per
   broken form? It is cheap, and it would let the editor show every broken form at once. The
   risk is cascades from a single unclosed bracket, though the bracket pass catches those first.
3. **Spans.** Diagnostics carry a start position only. The rule's provenance has its last token
   too, so located rule errors could carry the whole rule as a range. Is that worth threading
   through the error messages, or should errors carry the form instead of a string (a structured
   `exn:fail:slog` with a `syn`)? The latter is the cleaner long-term answer, and it would
   retire the location regex.
4. **`-d` programs.** Should `--check` accept `-d DB` to read the input manifest, so programs
   over a saved database check as they compile?
5. **More errors per check.** Simplify and stratify could collect per-rule errors like the
   typechecker. Is that wanted, or is first-error plus the per-rule typecheck enough?
6. **Warnings in the check.** The sequence blow-up warning is runtime-flavoured. Keep it as a
   warning diagnostic, or leave it to Run?
