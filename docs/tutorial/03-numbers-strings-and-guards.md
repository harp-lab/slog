# 3. Numbers, strings, and guards

So far rules only rearranged values that already existed. This chapter
adds computation: arithmetic, string operations, and conditions.

## Computing a value: `(= x expr)`

Inside a rule body, `(= C2 (+ C W))` computes `C + W` and names the
result `C2`. Weighted graph, path costs:

```
table (edge int int int)     ;; from, to, weight
table (dist int int)         ;; node, cost of some path from node 1

rule
(edge 1 2 4)
(edge 1 3 1)
(edge 3 2 2)
(edge 2 4 5)

rule (dist 1 0)
rule (dist X C) (edge X Y W) (= C2 (+ C W)) --> (dist Y C2)
```

Run it and look at `dist`:

```
$ racket slog.rkt --debug-dir out/dist dist.slog
$ sort -n out/dist/dist.csv
1   0
2   3
2   4
3   1
4   8
4   9
```

Node 2 appears **twice** — once at cost 4 (directly) and once at cost 3
(via node 3). A relation is a set of rows, and `(dist 2 4)` and
`(dist 2 3)` are different rows. Slog derived *every* path cost, not
the best one. Hold that thought: it becomes a one-line fix in the
lattices chapter. (Also note what would happen with a cycle in the
graph: ever-growing costs, forever. Guards, next, are the blunt fix;
lattices are the elegant one.)

## Guards: conditions that filter

A **guard** is a test in a rule body. If it fails, that match simply
doesn't fire:

```
table (cheap int)
rule (dist X C) (< C 4) --> (cheap X)
```

The comparison guards are `<`, `<=`, `>`, `>=`, and `/=` (not-equal).
They filter; they never create values.

Two details that surprise newcomers:

- **There are no negative literals.** `(f -3)` doesn't parse; compute
  negatives with `(neg 3)` or subtraction.
- **Arithmetic doesn't mix types.** `(+ 1 2.5)` is a type error;
  convert explicitly with `(tofloat 1)` or `(toint 2.5)`. Floats print
  with a decimal point (`2.0`) so you can tell them apart in output.

## Strings

Strings support `+` (concatenation), `(size s)` (length), and
`(substr s start end)` (the slice from `start` up to but not including
`end`):

```
table (name str)
table (greeting str)

rule (name "ada") (name "vera")

rule (name N) (= G (+ "hello, " N)) --> (greeting G)
```

```
$ cat out/hello/greeting.csv
"hello, ada"
"hello, vera"
```

## Computed values as filters

If the variable on the left of `=` is *already bound*, the `=` becomes
a test — "does the computed value equal what we have?":

```
rule (dist X C) (dist Y C2) (= C2 (+ C 1)) --> (one_apart X Y)
```

Here `C2` is bound by the second pattern, so `(= C2 (+ C 1))` checks
whether the two costs differ by exactly one, rather than defining
anything. One form, two readings, chosen by what's already known — this
falls out of the way rules work rather than being a special feature.

## Negation: `~(pattern)`

A body atom prefixed with `~` matches when **no** fact matches the
pattern — set difference, "unless", "is missing":

```
table (person str)
table (parent str str)
table (childless str)

rule (person P) ~(parent P _) --> (childless P)
```

`~(parent P _)` reads "P is the parent of nobody": the `_` wildcard
leaves that column unconstrained, and constants are fine too
(`~(flag X "on")`). Two rules keep negation meaningful:

- **Every variable under `~` must be bound by a positive pattern.** A
  negated atom can only *check* values, never produce them — "some X
  that isn't in `q`" is not a well-defined set on its own.
- **No negation through recursion.** A rule can't negate a relation it
  (directly or transitively) helps derive — the compiler stratifies the
  program so a negated relation is always *finished* before any rule
  reads its absence, and rejects programs where that's impossible
  ("negation through recursion — not stratified").

Only whole relation atoms can be negated: to ask about structured data,
bind it positively first and negate over the variable
(`(= P (pair X Y)) ~(seen P)`), and negate each alternative separately
(`~A ~B`, never `~(A | B)` — which would mean "neither" anyway).
For a lattice (map) relation, negate on its key columns: `~(best K)`
means "no value at key K".

## Cheat sheet

| Form | Example | Meaning |
|---|---|---|
| compute | `(= y (+ x 1))` | evaluate, name the result (or filter, if `y` is already bound) |
| int/float arithmetic | `+ - * / % neg abs min max pow` | homogeneous: int with int, float with float |
| float functions | `sqrt sin cos tan exp log floor ceil round` | operate on floats |
| conversions | `(tofloat i)`, `(toint f)` | cross the int/float divide explicitly |
| bitwise (int) | `band bor bxor bnot shl shr` | e.g. `(shl 1 4)` = 16 |
| string ops | `(+ s1 s2)`, `(size s)`, `(substr s 0 3)` | concat, length, slice `[start,end)` |
| comparison guards | `(< x y) (<= x y) (> x y) (>= x y)` | filter matches |
| not-equal | `(/= x y)` | filter; the only disequality |
| negation | `~(parent P _)` | filter: no matching fact exists (vars must be bound positively) |
| negatives | `(neg 3)` | there are no negative literals |
