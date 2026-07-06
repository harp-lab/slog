# 7. Sets and maps

A relation already *is* a set — of rows. But sometimes you want a set
as a single **value**: one thing you can put in a column, pass to a
function, compare, and update. Slog provides finite sets and finite
maps with brace syntax, backed by a library of operations.

Both live in the standard library — `include "lib/set.slog"` and/or
`include "lib/map.slog"`. Elements and keys are non-negative ints in
this version.

## Sets

```
include "lib/set.slog"

table (s pset)
table (bigger pset)
table (present int)
table (n int)

facts (s {5 2 8})

rule (s x) --> (bigger {7 x ...})
rule (s x) (= a (st_mem0 x 5)) --> (present a)
rule (s x) (= k (st_size x))   --> (n k)
```

- `{5 2 8}` is a **set literal** (type `pset`). `(pempty)` is the empty
  set — a bare `{}` is an error, since it could equally mean an empty
  map.
- `{7 x ...}` builds **the set `x` with `7` added** — the same trailing
  `...` you know from lists, meaning "everything in x".
- `st_mem0` is the membership test: `1` if present, `0` if not.

The library: `st_ins` (insert), `st_del` (remove), `st_union`,
`st_diff` (difference), `st_mem0` (membership as 1/0), `st_size`, and
`st_fromlist` (build from a list).

## One set, one value — always

Run this and look closely:

```
table (canon pset)
rule (= r {5 2 8 1})                        --> (canon r)
rule (= r (st_fromlist [1 8 2 5]))          --> (canon r)
rule (= a {8 5}) (= b {1 2})
     (= r (st_union a b))                   --> (canon r)
```

```
$ racket slog.rkt --sizes sets.slog
(relation_size canon 1)
```

Three different constructions — different orders, even a union of two
halves — and `canon` holds **one row**. Equal sets are *the same
value*, no matter how they were built. (Under the hood the elements are
arranged into a tree whose shape depends only on which elements are in
the set — never on insertion order — and chapter 4's stored-once rule
does the rest.) This is what makes set-valued columns trustworthy: you
can join on them, key by them, and count them, and "same contents"
always means "same value".

## The trick worth knowing: asking "not in"

Chapter 2 noted that rules can't conclude from absence. Sets thread
that needle: `st_mem0` always answers — `1` *or* `0` — because a set
value is a complete, finished object that can be inspected
structurally. So "x is not in s" is an ordinary positive fact:

```
rule (s x) (st_mem0 x 3 0) --> (lacks_three 1)
```

This is more useful than it first looks; set-difference is built on it,
and analyses that need "definitely not present" lean on it heavily.

## Maps

Maps associate int keys with *any* values, with the same brace syntax
plus `:`:

```
include "lib/map.slog"

table (m pmap)
table (v int)

facts (m {1:10 3:30})

rule (m x) --> (updated {1:99 x ...})
rule (m x) (= w (mp_get x 3)) --> (v w)
table (updated pmap)
```

- `{1:10 3:30}` is a map literal; `(mempty)` the empty map.
- `{1:99 x ...}` is **functional update**: the map `x` with key `1` now
  bound to `99`. The original `x` is unchanged — these are values, not
  mutable objects.
- `mp_get` looks up (answers nothing for a missing key); `mp_has0`
  tests presence as 1/0; `mp_del` removes; `mp_union` merges with the
  *left* argument winning on shared keys; `mp_size` counts;
  `mp_fromlist` builds from a list of `[key value]` pairs.

Maps enjoy the same canonicity guarantee: equal contents, same value.

## Cheat sheet

| Form | Example | Meaning |
|---|---|---|
| set literal | `{5 2 8}` | a `pset` value; `include "lib/set.slog"` |
| set extend | `{7 s ...}` | s with 7 added (s unchanged) |
| empty set / map | `(pempty)` / `(mempty)` | `{}` alone is ambiguous and errors |
| set ops | `st_ins st_del st_union st_diff st_size st_fromlist` | `(= r (st_union a b))` |
| membership | `(st_mem0 s 5 a)` → a ∈ {0,1} | total: answers 0 for absent — usable as "not in" |
| map literal | `{1:10 3:30}` | a `pmap` value; `include "lib/map.slog"` |
| map update | `{k:v m ...}` | m with k↦v (replacing any old binding) |
| map ops | `mp_get mp_has0 mp_del mp_union mp_size mp_fromlist` | `mp_union` is left-biased |
| canonicity | — | equal contents ⇒ the very same value, however built |
