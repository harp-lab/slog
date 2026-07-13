# Lists, sets, and maps

Slog has native immutable lists, sets, and maps. Each collection is canonical:
its identity depends on its contents, not on the order of updates used to build
it. That gives content equality and lets a whole collection serve as a relation
column, struct field, key, or lattice value.

The repository also contains older rule-based Patricia set and map libraries.
They remain useful for studying a data structure written in Slog and for
compatibility with older programs, but native collections are more general and
usually the better default.

## Lists

Write a list with square brackets:

```slog
struct (point int int)
table (ints (list int))
table (mixed list)

rule
(ints [])
(ints [1 2 3])
(mixed ["name" 4 (point 2 3)])
```

`list` means a list of `any`. `(list int)` gives the element type. `[int]` is
also accepted in type position. All of these use the native `cseq`
representation.

Lists are persistent values. An operation returns a new list and leaves the
old one unchanged:

```slog
table (versions list)
rule (= A [10 20 30])
     (= B (lset A 1 99))
  --> (versions A) (versions B)
```

The relation contains both `[10 20 30]` and `[10 99 30]`.

## List construction and splicing

An expression followed by `...` contributes all elements of that expression:

```slog
table (joined list)
rule (= Middle [2 3]) --> (joined [1 Middle ... 4])
```

The result is `[1 2 3 4]`. More than one splice is allowed:

```slog
rule (= A [1 2]) (= B [3 4]) --> (joined [A ... B ...])
```

At the primitive level, `(lempty)` returns `[]`, `(lpush L X)` appends one
element, and `(lcat A B)` concatenates lists. Bracket construction lowers to
these native operations.

## List patterns

Brackets in a matching position describe the required shape:

```slog
table (input list)
table (head any)
table (tail list)

rule (input [X XS ...]) --> (head X) (tail XS)
```

The rule matches only nonempty lists. `[]` matches only the empty list. Fixed
elements may surround a splice:

```slog
rule (input [First Middle ... Last]) --> (ends First Last)
rule (input [_ ... 7 Next _ ...]) --> (after_seven Next)
```

A bound variable in a pattern must have the same value:

```slog
rule (wanted K) (input [K Rest ...]) --> (starts_with K Rest)
```

List patterns use the partial `aslst` operation internally. If an `any` column
contains a non-list, the pattern simply does not match.

When a pattern has several variable-length splices, there can be several
mathematical partitions. Slog uses a deterministic split policy. It does not
emit every possible partition. Use explicit indexes or a recursive demand when
all partitions are part of the result.

## Native list operations

The native operations are:

```text
lempty lpush aslst llen lref lset lins ldel lcat lslice lrev
lidx lmem lsort lst2set set2lst ckeys cvals
```

Common examples:

```slog
rule (= L [10 20 30])
     (= N (llen L))
     (= X (lref L 1))
     (= I (lidx L 30))
     (= S (lslice L 1 3))
  --> (summary N X I S)
```

This produces `(summary 3 20 2 [20 30])`.

Index rules:

- `lref`, `lset`, and `ldel` accept `0 <= I < length`.
- `lins` accepts `0 <= I <= length`.
- Those four operations are partial outside their range.
- `lslice L I J` clamps both bounds and returns the half-open range `[I, J)`.
- `lidx` returns the first occurrence and is partial when the item is absent.
- `lmem` is total and returns `1` or `0`.

`lsort`, `set2lst`, and `ckeys` use the runtime's unsigned encoded-word order.
It is stable and canonical, but not a user-level numeric or lexicographic
order. If semantic ordering matters, derive it relationally or implement the
comparison you need.

See [the built-in reference](builtins.md#native-lists) for one-line semantics
of every operation.

## The list library

Include the standard wrapper library with either path style:

```slog
include "list.slog"
```

```slog
include "../lib/list.slog"
```

The first form works because unresolved includes fall back to `lib/`. The
library provides demand-shaped names that older programs used. They are now
thin memoized wrappers over native operations:

| Demand | Meaning |
|---|---|
| `(lst_append A B)` | concatenate lists |
| `(lst_ref L I)` | zero-based lookup; no answer out of range |
| `(lst_member L X)` | answer `1` when present; no answer when absent |
| `(lst_len L)` | length |
| `(lst_take L N)` | first `N` elements; clamps to the list |
| `(lst_absent L X)` | answer `1` when absent |
| `(lst_rev L)` | reverse |
| `(lst_rev_acc L Acc)` | reverse `L`, then append `Acc`; compatibility helper |

For new code, a native primitive is usually clearer when it has the behavior
you need. The wrappers are useful when a value-position demand composes better
with other demand calls.

## Native sets

A set literal has values separated by whitespace:

```slog
table (permissions cset)
rule (permissions {"read" "write"})
```

Duplicate elements collapse. The empty native seed is `(cmap)`; type context
turns it into the set role when passed to `cins` or stored in a `cset` column:

```slog
rule (= Empty (cmap))
     (= One (cins Empty "read"))
     (= Two (cins One "write"))
  --> (permissions Two)
```

Brace extension is shorter:

```slog
rule (permissions P) --> (permissions {"admin" P ...})
```

Be careful with that exact rule: because it always inserts the same value, it
reaches a fixpoint after at most one new set. A rule that keeps inserting fresh
integers may not terminate.

The set operations are:

- `cins S X`: insert `X`.
- `cmem S X`: return `1` or `0`.
- `cdel S X`: remove `X`.
- `cmerge A B`: union.
- `cdiff A B`: set difference `A - B`.
- `csize S`: number of elements.
- `set2lst S`: canonical-order list of elements.
- `lst2set L`: set of list elements.

Native set elements may be any Slog value, including strings, structures,
lists, and other collections.

## Native maps

A map literal uses `key:value` entries:

```slog
table (scores cmap)
rule (scores {"Ada":92 "Grace":88})
```

Keys and values may be arbitrary Slog values. `cput` replaces an existing
binding and returns a new map:

```slog
rule (scores M)
     (= M2 (cput M "Grace" 95))
     (= Ada (cget M2 "Ada"))
  --> (updated M2 Ada)
```

`cget` is partial. If a key may be absent, test it explicitly when both paths
matter:

```slog
rule (scores M) (= 1 (chas M "Ada")) (= V (cget M "Ada"))
  --> (known_score "Ada" V)

rule (scores M) (= 0 (chas M "Linus"))
  --> (missing_score "Linus")
```

The map operations are:

- `cput M K V`: insert or replace.
- `cget M K`: partial lookup.
- `chas M K`: total presence test.
- `cdel M K`: remove a key.
- `cmerge A B`: left-biased union; `A` wins collisions.
- `cdiff A B`: keep bindings from `A` whose keys are absent from `B`.
- `csize M`: binding count.
- `ckeys M`: keys in canonical order.
- `cvals M`: values in the matching key order.

Brace extension can update and extend a map:

```slog
rule (scores M) (= M2 {"Grace":95 M ...}) --> (updated_scores M2)
```

An explicit entry earlier in the literal takes the intended update role. For
code where collision policy matters, `cput` or `cmerge` states it more plainly.

## Collections as lattice values

A set lattice unions every proposal for one key:

```slog
lattice (nameset (set str))
table (reachable_names str nameset)
table (edge str str)

rule (edge X Y) (= S (cins (cmap) Y)) --> (reachable_names X S)
rule (reachable_names X S) (edge X Y)
  --> (reachable_names Y S)
```

A map lattice gives each key its own child lattice:

```slog
lattice (best_by_name (map str (min int)))
table (summary str best_by_name)
```

Use `cjoin` only when the compiler can see such a lattice specification. It
performs set union or pointwise child joins. `cmerge` is not a lattice join for
maps because its left-biased collision behavior depends on argument order.

For a table with a set or map lattice in its last column, Slog synthesizes
relational views:

- `R_has key-columns... element` for `(set T)`
- `R_at key-columns... map-key child-value` for `(map K CHILD)`

For example:

```slog
lattice (nameset (set str))
table (members str nameset)
table (seen str str)

rule (members_has Group Name) --> (seen Group Name)
```

These views make collection contents joinable without first converting them
to lists. They follow the producing lattice relation's closure rules. Nested
map views descend one child level at a time.

See [the lattice guide](functions-and-lattices.md#collection-lattice-views) for
sound recursive use.

## Rule-based Patricia sets

`lib/set.slog` defines:

```slog
union (pset (pempty)
            (pleaf int)
            (pbranch int int pset pset))
```

Its keys must be nonnegative integers below `2^30`. Include it and use `pset`
columns:

```slog
include "set.slog"

table (old_set pset)
rule (= S {1 5 8}) --> (old_set S)
```

In a module that includes this library, set brace literals lower to the
`pset` representation rather than native `cset`. Do not pass that value to
`cins`, `cmem`, or other native operations.

The public operations are:

| Demand | Meaning |
|---|---|
| `st_ins` | insert |
| `st_mem` | partial membership: answers `1` only when present |
| `st_mem0` | total membership: `1` or `0` |
| `st_del` | delete |
| `st_union` | union |
| `st_diff` | difference |
| `st_size` | element count |
| `st_fromlist` | build from a list |

The library also defines structural helpers `st_hsb`, `st_msk`, `st_join`, and
`st_bld`. They are ordinary demand relations and therefore visible, but they
are implementation details of the Patricia trie.

## Rule-based Patricia maps

`lib/map.slog` defines maps with nonnegative integer keys below `2^30` and
arbitrary values:

```slog
union (pmap (mempty)
            (mleaf int any)
            (mbranch int int pmap pmap))
```

Including the library makes map brace literals lower to `pmap`:

```slog
include "map.slog"

table (old_map pmap)
rule (= M {1:"one" 2:"two"}) --> (old_map M)
```

Its public operations are:

| Demand | Meaning |
|---|---|
| `mp_put` | insert or replace |
| `mp_get` | partial lookup |
| `mp_has0` | total key presence: `1` or `0` |
| `mp_put_soft` | insert only when absent |
| `mp_del` | delete |
| `mp_union` | left-biased union |
| `mp_size` | binding count |
| `mp_fromlist` | build from a list of `[key value]` pairs; leftmost duplicate wins |

Structural helpers are `mp_hsb`, `mp_msk`, `mp_join`, and `mp_bld`.

## Choosing a representation

Use native `cset` and `cmap` for new programs. They support arbitrary keys,
have direct runtime operations, work with collection lattices, and do not
spend rule iterations walking a user-level trie.

Use `pset` or `pmap` when maintaining an older program, when its constructor
shape is part of an experiment, or when you specifically want to study a
Patricia trie implemented in Slog itself.

Because include changes brace desugaring, avoid including `set.slog` or
`map.slog` merely for a helper name in a module that otherwise expects native
braces. Keep compatibility representations behind a clear module boundary.
