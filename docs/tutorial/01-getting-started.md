# 1. Getting started

Suppose you know a language like Java or Python. You are used to
telling the computer *what to do*: create a variable, loop over a
list, call a function, return. A Slog program contains none of those
things. It contains statements about *what is true*, and running it
means the computer works out everything else that must be true.

That probably sounds abstract, so let's make it concrete immediately.

## A program that is only data

Here is a complete Slog program describing part of a family:

```
table (parent str str)

facts
(parent "vera" "ada")
(parent "ada" "haskell")
(parent "ada" "miranda")
```

Two things are happening:

- `table (parent str str)` **declares a relation** — think of it as a
  table in a spreadsheet, named `parent`, with two columns, both
  holding strings. A relation is a *set of rows*: no duplicates, no
  order.
- The `facts` block **asserts rows**: Vera is a parent of Ada; Ada is a
  parent of Haskell and of Miranda.

That's the whole program. No `main`, no statements. Save it as
`family.slog` and run it from the repository root:

```
$ racket slog.rkt --debug-dir out/family family.slog
```

The first run takes a little while — Slog compiles your program to
native code (and caches it, so the second run is instant). The
`--debug-dir` flag asks for the final contents of every relation as a
`.csv` file in that directory:

```
$ cat out/family/parent.csv
"vera"   "ada"
"ada"   "haskell"
"ada"   "miranda"
```

The output is just what we put in. Fair enough — we haven't asked for
anything to be *computed* yet.

## The first rule

Add two lines to the program:

```
table (grandparent str str)

rule (parent X Y) (parent Y Z) --> (grandparent X Z)
```

Read the rule aloud, right to left around the arrow: *whenever
everything on the left holds, the thing on the right holds too*. On the
left there are two **patterns**: `(parent X Y)` and `(parent Y Z)`.
`X`, `Y`, and `Z` are **variables**, and one variable used twice must
stand for the same value both times. So the rule says: if X is a parent
of Y, and *that same* Y is a parent of Z, then X is a grandparent of Z.

```
$ racket slog.rkt --debug-dir out/family family.slog
$ cat out/family/grandparent.csv
"vera"   "haskell"
"vera"   "miranda"
```

Slog found every pair of rows in `parent` that line up through a shared
middle person, and derived a `grandparent` row for each. You didn't
write a loop over the rows; you described the *shape* of the situation,
and the engine found every instance of it.

That inversion — describing shapes instead of writing loops — is the
whole game. The next chapter is about how far it goes.

## What just happened, honestly

A fair question from a Java programmer: "so it ran my rule once over
the data?" Almost. It ran your rule until **nothing new appeared**. With
one non-recursive rule that's a single pass, but rules are allowed to
build on each other's results — and on their own. When rules feed each
other, Slog keeps going until the set of facts stops growing. That
final, stable set of facts is the program's result. (The technical name
is a *fixpoint*, and you'll see in the next chapter why it's so
useful.)

Two more useful flags before moving on. `--sizes` prints how many rows
each relation ended with — the quickest sanity check there is:

```
$ racket slog.rkt --sizes family.slog
(relation_size grandparent 2)
(relation_size parent 3)
```

And `--no-banner` suppresses the startup banner, which you'll want when
scripting.

## Cheat sheet

| Form | Example | Meaning |
|---|---|---|
| declare a relation | `table (parent str str)` | a named set of rows; columns are typed (`str`, `int`, `float`, ...) |
| assert facts | `facts (parent "a" "b") (parent "b" "c")` | add rows; one `facts` block can hold many |
| a rule | `rule (parent X Y) (parent Y Z) --> (grandparent X Z)` | left patterns all match ⇒ right holds |
| variables | `X`, `y`, `thing` | any name in a rule; repeated = same value |
| comments | `;; like this` | to end of line |
| run a program | `racket slog.rkt --debug-dir out/d prog.slog` | compile (cached), run to fixpoint, write CSVs |
| row counts | `racket slog.rkt --sizes prog.slog` | print `(relation_size name n)` per relation |
| quiet | `--no-banner` | suppress the banner |
