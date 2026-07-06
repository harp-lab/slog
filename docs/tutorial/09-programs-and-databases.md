# 9. Programs and databases

Everything so far was one file, run once, results to CSV. Real projects
split logic across files and keep data around between runs. Slog has
two composition forms and a persistent database format.

## `include`: splice a file in

`include "file.slog"` textually merges another file's declarations,
facts, and rules into the current program — one program, assembled from
parts. You've used it already for the libraries:

```
include "lib/list.slog"
include "lib/set.slog"
```

Paths are relative to the including file. A typical layout keeps type
declarations in one file and imports them everywhere:

```
;; types.slog
union (expr (lambda str expr) (app expr expr) (ref str))
table (program expr)
```

```
;; analysis.slog
include "types.slog"
rule (program e) --> ...
```

## `run`: a prerequisite program

`run "file.slog"` is different: it names a whole program that must
execute **to fixpoint first**, on the same database, before this one
starts. Where `include` merges texts, `run` sequences *stages* —
the earlier program's results are simply present when the later one
begins.

```
;; main.slog
run "load-graph.slog"       ;; stage 1: build the graph
table (edge int int)        ;; declare what we inherit
table (reach int int)
rule (edge X Y) --> (reach X Y)
rule (reach X Y) (edge Y Z) --> (reach X Z)
```

This is how the bundled analyses are organized: one stage parses or
loads the subject program, the next analyzes it. Declaring a relation
in the later file (without new facts) is how you refer to inherited
data.

## Saving and loading databases

`--out-db NAME` writes the final database — every relation, in a
compact binary format — under `data/NAME/`. `-d NAME` starts a later
run *from* it:

```
$ racket slog.rkt --out-db graph load-graph.slog
$ ls data/graph
table.edge.arity.2  value.strings

$ racket slog.rkt -d graph --sizes reach.slog
(relation_size edge 3)
(relation_size reach 6)
```

The second run never re-parsed the data — it opened the saved database
and ran only the new rules against it. Chain `--out-db` onto that run
too and you have a pipeline of programs, each building on the last.
This is the right way to work with *large* inputs generally: loading a
binary database is far faster than compiling a huge `facts` block
(inline facts are compiled into the program itself, which is fine for
hundreds of rows and unwise for hundreds of thousands).

CSV output (`--debug-dir`) is for eyeballing; binary databases
(`--out-db`/`-d`) are for data.

## Cheat sheet

| Form | Example | Meaning |
|---|---|---|
| splice | `include "types.slog"` | merge a file's decls/facts/rules; relative path |
| stage | `run "load.slog"` | run that whole program to fixpoint first, same database |
| inherit | redeclare `table (edge int int)` after a `run` | name what the earlier stage produced |
| save | `racket slog.rkt --out-db mydb prog.slog` | write `data/mydb/` |
| load | `racket slog.rkt -d mydb next.slog` | start from a saved database |
| inspect | `--debug-dir out/d` / `--sizes` | CSVs per relation / row counts |
| big data | — | prefer binary databases over giant inline `facts` blocks |
