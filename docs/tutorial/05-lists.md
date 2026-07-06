# 5. Lists

You could build lists yourself with a union — `(cons 1 (cons 2 (nil)))`
— and everything in the last chapter would apply. Lists are common
enough that Slog builds them in, with bracket syntax.

## Literals, heads, and tails

```
table (input list)
table (heads int)
table (tails list)
table (extended list)

facts (input [1 2 3])

rule (input [x xs ...]) --> (heads x) (tails xs)
rule (input l) --> (extended [0 l ...])
```

Three forms in play:

- `[1 2 3]` is a **list literal**. `[]` is the empty list.
- In a body, `[x xs ...]` is a **pattern**: it matches a non-empty
  list, binding `x` to the first element and `xs` to the rest. The
  trailing `...` marks the final name as "the rest of the list".
- In a head, `[0 l ...]` **builds**: the list that is `0` followed by
  everything in `l`.

```
$ racket slog.rkt --debug-dir out/lists lists.slog
$ cat out/lists/heads.csv
1
$ cat out/lists/tails.csv
(cons 2 (cons 3 (_enum "nil")))
$ cat out/lists/extended.csv
(cons 0 (cons 1 (cons 2 (cons 3 (_enum "nil")))))
```

The CSV output reveals the representation: brackets are sugar for the
builtin `cons`/`nil` constructors, ordinary structured values like
chapter 4's trees. (For that reason `list`, `cons`, and `nil` are
reserved names.) You can put more than one element before the `...` —
`[a b t ...]` is `a`, then `b`, then all of `t` — and lists nest:
`[[1 2] [3 4]]` is a list of lists.

Columns can also state their element type: `table (input (list int))`
declares a list of ints.

## The list library

`lib/list.slog` ships the standard operations. Pull it in with
`include` (chapter 9 has more on includes) and call them with the
`(= result (fn args))` shape you already know from arithmetic:

```
include "lib/list.slog"

table (out list)
table (n int)
table (third int)

rule (= r (lst_append [1 2] [3 4])) --> (out r)
rule (= r (lst_rev [1 2 3]))        --> (out r)
rule (= k (lst_len [7 7 7]))        --> (n k)
rule (= x (lst_ref [10 20 30] 2))   --> (third x)
```

The library provides:

| function | example | result |
|---|---|---|
| `lst_append` | `(lst_append [1 2] [3])` | `[1 2 3]` |
| `lst_ref` | `(lst_ref [10 20 30] 1)` | `20` (zero-based; no answer if out of range) |
| `lst_member` | `(lst_member [5 6] 6)` | `1` if present; *no answer* otherwise |
| `lst_absent` | `(lst_absent [5 6] 9)` | `1` if **not** present |
| `lst_len` | `(lst_len [4 4 4])` | `3` |
| `lst_take` | `(lst_take [1 2 3] 2)` | `[1 2]` |
| `lst_rev` | `(lst_rev [1 2 3])` | `[3 2 1]` |

Note `lst_member`'s contract: it answers `1` when the element is there
and *answers nothing* otherwise — "no" is expressed as silence, not as
`0`. That's characteristic of Slog (rules only ever add facts), and
it's why `lst_absent` exists as a separate positive statement.

These library functions are recursive functions written *in Slog* — a
handful of rules each. How that works is the next chapter; you can use
them without knowing.

## Recursion over lists, forward

Plain rules can already walk a list that exists, exactly like the tree
walks of chapter 4:

```
table (elem int)
rule (input [x xs ...]) --> (elem x) (input xs)
```

Every element of every input list ends up in `elem`. (Note the trick
and its cost: the rule re-asserts each *tail* back into `input` to keep
walking — so `input` ends up holding every suffix, not just your
original lists. Use a separate work relation if that matters.) What
plain rules cannot do is *return* a value computed from a whole list on
request — for that, read on.

## Cheat sheet

| Form | Example | Meaning |
|---|---|---|
| literal | `[1 2 3]`, `[]`, `[[1 2] [3]]` | build a list; nesting fine |
| extend | `[x t ...]`, `[a b t ...]` | new elements in front of list `t` (build or match) |
| pattern | `rule (input [x xs ...]) --> ...` | first element + rest; `[]` matches empty |
| typed column | `table (r (list int))` | element-typed list column |
| library | `include "lib/list.slog"` | `lst_append` `lst_ref` `lst_member` `lst_absent` `lst_len` `lst_take` `lst_rev` |
| calling | `(= r (lst_append a b))` | library functions compose like arithmetic |
| absence | `lst_member` answers or stays silent | "no" is silence; use `lst_absent` for a positive no |
