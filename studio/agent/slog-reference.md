# Slog language reference (for the Studio agent)

Slog is a Datalog-family language with first-class structured facts. A program
declares relations and types, then gives rules; the compiler type-checks the
whole program, splits it into strata, generates native code, and runs each
stratum to a fixpoint. This reference is the working subset you need. Every
`slog` block below is a complete program that compiles and runs as written;
every `slog-error` block fails with the error its first line names; every
`query` block answers as shown against the program before it. When you
need something not covered here, use `search_docs` / `read_doc` /
`list_examples` rather than guessing.

## 0. The rules that prevent most mistakes

1. **Comments are `;;`.** A single `;` is an infix operator, not a comment:
   `; note` inside a rule silently changes its meaning or fails to parse.
2. **Declare every relation** with `table` (or `demand`) before relying on it.
   Every relation needs at least one column; there are no zero-arity relations
   (use a one-column marker such as `table (done int)`).
3. **Every head variable must be bound by the body** (or computed with `=`).
   Never put `_` in a head. Facts must be ground.
4. **Negation `~(rel ...)` needs every variable already bound** by an earlier
   positive clause, and cannot be part of a recursive cycle.
5. **Arithmetic is prefix:** `(+ A B)`, never `A + B`. Bind results with
   `(= V (+ A B))` or nest the call where a value goes.
6. **Comparisons are guards**: `(< A B)`, `(/= A B)` filter; they never bind.
   `<`, `<=`, `>`, `>=` compare numbers only; `=`/`/=` work on any values.
7. **Nullary constructors and enum members keep their parentheses**: `(halt)`,
   `(red)`. Only `true` and `false` are bare. **Never name a constructor
   after a primitive** (`neg`, `min`, `max`, `size`, `top`, ...; section 4):
   it is silently called as the primitive.
8. **Types are checked statically**; an `int` and a `float` never mix without
   `(tofloat I)`; there is no `bool` type (use an `enum` or `any`).
9. **A lattice column is the last column** of its table, and the earlier
   columns are its key.
10. **Variables are any lowercase or uppercase identifiers**; capitalization is
    only convention. A bare name is a variable unless it is `true`/`false`.
11. **Queries (`?`) only see ordinary tables**, use only variables/numbers/
    strings as terms (no constructor patterns), and return duplicate rows
    under projection. See section 11.
12. After every change: evaluate, read the row counts, query a sample. An
    empty relation you expected to fill usually means a join mismatch, not a
    crash.

## 1. Lexical syntax and program shape

- Whitespace separates tokens; newlines carry no meaning. A top-level form
  runs until the next top-level keyword (`table`, `rule`, `struct`, `union`,
  `enum`, `lattice`, `demand`, `extern`, `include`, `run`, `instantiate`), so
  a rule can span many lines.
- Identifiers: letters, digits, `_`, and `'` (not first). Case sensitive.
  **No hyphens**: `on-cycle` is a compile error ("not a valid name");
  write `on_cycle`. Dotted names `g.edge` are qualified names
  (modules, section 9).
- Negation is `~`; there is no `!`, `not`, or `\+`.
- Literals: integers (`42`, `-17`, arbitrary precision), floats (`3.5`,
  `-0.25`; IEEE double), strings in double quotes with backslash escapes
  (`"a\nb"`), `true`, `false`. A `-` directly followed by digits is part of a
  number; `(- A B)` with a space is subtraction.
- `[a b c]` is a list; `{a b}` is a set; `{k:v k2:v2}` is a map.
- `X ...` (postfix) splices a list into a list literal or matches a rest.
- `;;` to end of line is a comment. Nothing else is a comment.
- Infix operators exist (`=` and `/=` can be written infix, `e = (lit n)`),
  but write prefix forms: `(= e (lit n))`.

A program in one file:

```slog
;; Declarations first, then facts and rules (order of forms does not matter
;; for meaning, but declare before use for readability).
table (edge int int)
table (path int int)

rule (edge 1 2) (edge 2 3) (edge 3 4)

rule (edge X Y) --> (path X Y)
rule (path X Y) (edge Y Z) --> (path X Z)
```

## 2. Declarations and types

### table

`table (name type ...)` declares a relation: an unordered **set** of rows.
Re-deriving a row has no effect.

```slog
table (edge str str)
table (weight str str int)
table (payload str any)
table (scores str (list int))
rule (edge "a" "b") (weight "a" "b" 5) (payload "a" 3.5) (scores "a" [1 2 3])
```

### Types

| Type | Values |
|---|---|
| `int` | exact integers (bignums, no overflow) |
| `float` | IEEE binary64 |
| `str` | Unicode strings (indexes count code points) |
| `any` | any value; checked at runtime when an operation needs a narrower type |
| `list`, `(list T)`, `[T]` | native immutable sequences |
| `cset` | native set; `cmap` native map; `(map K V)` typed map; `coll` either |
| `clo` | closure made by `lambda` |
| a declared `struct`/`union`/`enum`/`lattice`/`demand` name | that type |

There is **no `bool` type**. `true`/`false` are built-in nullary constants;
store them in `any` columns, or declare `enum (flag yes no)` / a `union` for a
statically checked choice.

Reserved names: do not declare `list`, `cons`, `nil`, `cset`, `cmap`, `coll`,
`cseq`, `error`, or the error variant names (section 10).

### struct

One constructor, one type. Construction and pattern use the same syntax.

```slog
struct (point int int)
table (location str point)
table (xcoord str int)
rule (location "origin" (point 0 0)) (location "p" (point 3 4))
rule (location Name (point X _)) --> (xcoord Name X)
```

### union

A closed family of constructors; arms may be nullary, and arms may recurse.
All arms must be in one declaration.

```slog
union (expr (num int)
            (var str)
            (add expr expr)
            (mul expr expr))

table (program expr)
rule (program (add (num 1) (mul (var "x") (num 3))))
```

A union arm may name an existing struct or union to include it:

```slog
struct (lambda str str)
union (value lambda (number int))
table (v value)
rule (v (lambda "x" "x")) (v (number 3))
```

### enum

Named nullary constructors; always written with parentheses.

```slog
enum (color red green blue)
table (paint str color)
table (warm str)
rule (paint "door" (red)) (paint "sky" (blue))
rule (paint Thing (red)) --> (warm Thing)
```

### Values are interned (hash-consed)

Structured values are content-interned: two equal terms are the same value, so
equality on trees, lists, sets, and maps is O(1) after construction, and any
structured value can be a key, a join column, or a set element.

Every constructor is also a relation of all values built so far. A body clause
`(= E (add A B))` with `E` unbound **enumerates every interned `add` node**;
that is how bottom-up evaluators visit every subterm (section 13.2).

## 3. Rules

### Forms

```slog
table (edge int int)
table (two_hop int int)
table (node int)

;; facts: a rule with no arrow; several facts may share one `rule`
rule (edge 1 2)
     (edge 2 3)

;; body --> heads
rule (edge X Y) (edge Y Z) --> (two_hop X Z)

;; head <-- body (same meaning)
rule (two_hop X Z) <-- (edge X Y) (edge Y Z)

;; several heads from one match
rule (edge X Y) --> (node X) (node Y)
```

- All body clauses must match for the heads to be derived (conjunction).
- `|` separates body alternatives; each alternative must bind everything the
  head uses:

```slog
table (left_child str str)
table (right_child str str)
table (child str str)
rule (left_child "r" "a") (right_child "r" "b")
rule (child P C) <-- (left_child P C) | (right_child P C)
```

### Variables, constants, joins, wildcards

- A repeated variable in one rule must have one value: that is the join.
- `_` matches anything; each `_` is independent; never in a head.
- Literals in a clause filter: `(edge 1 Y)`.
- Constructor patterns destructure in bodies and construct in heads, nested
  to any depth.

```slog
union (tree (leaf int) (node tree tree))
table (t str tree)
table (left_leaf str int)
table (mirror str tree)
rule (t "a" (node (leaf 1) (node (leaf 2) (leaf 3))))
rule (t Name (node (leaf N) _)) --> (left_leaf Name N)
rule (t Name (node L R)) --> (mirror Name (node R L))
```

### Equality, guards, and computed values

- `(= V expr)` binds `V` to a computed value, or tests when both sides are
  bound, or destructures when one side is a pattern.
- `(/= A B)` requires two bound values to differ (any type).
- `(< A B)`, `(<= A B)`, `(> A B)`, `(>= A B)` are numeric guards on bound
  values. They do not produce values.
- A primitive call may appear wherever a value goes, including heads.

```slog
table (weight str int)
table (doubled str int)
table (heavy str)
table (pair_sum int)
rule (weight "a" 3) (weight "b" 10)
rule (weight N W) (= W2 (* W 2)) --> (doubled N W2)
rule (weight N W) (>= W 5) --> (heavy N)
rule (weight N A) (weight M B) (/= N M) --> (pair_sum (+ A B))
```

A partial operation (`cget` on a missing key, `s2i` on a non-number, `lref`
out of range, ...) simply fails that match: no row, no error.

### Rule order and evaluation

Rules are a set; their order in the file does not matter. Evaluation is
bottom-up and set based: no row order, no duplicates, no "first match". A
program that keeps generating fresh values (e.g. `(n X) --> (n (+ X 1))`)
does not terminate; bound such recursion with a guard such as `(< X 100)`.

```slog
table (n int)
rule (n 0)
rule (n X) (< X 10) --> (n (+ X 1))
```

## 4. Built-in operations

All are prefix calls. Two-operand numeric operations need both operands of
the same static type (`int` with `int`, `float` with `float`).

| Operation | Meaning |
|---|---|
| `(+ A B)` | add numbers, or concatenate two strings |
| `(- A B)` `(* A B)` | subtract, multiply |
| `(/ A B)` | int division truncates toward zero; float division |
| `(% A B)` | remainder (sign of dividend) |
| `(neg A)` `(abs A)` | negation, absolute value |
| `(min A B)` `(max A B)` | smaller / larger |
| `(pow A B)` | power (exact for ints) |
| `(band A B)` `(bor A B)` `(bxor A B)` `(bnot A)` `(shl A N)` `(shr A N)` | integer bit operations |
| `(sqrt X)` `(sin X)` `(cos X)` `(tan X)` `(exp X)` `(log X)` | float math (int or float in, float out) |
| `(floor X)` `(ceil X)` `(round X)` | float out |
| `(tofloat X)` `(toint X)` | conversions (`toint` truncates) |
| `(size S)` | string length in code points (also list length) |
| `(substr S I J)` | code points `[I, J)` -- **J is an end index, not a length** |
| `(sidx S Needle)` | first index of `Needle`; partial |
| `(shas S Needle)` | `1` or `0` |
| `(schar S I)` | one-character string; partial |
| `(ssplit S Sep)` | list of strings |
| `(sjoin Parts Sep)` | join a list of strings |
| `(s2i S)` `(s2f S)` | parse int / float strictly; partial |
| `(i2s I)` `(f2s F)` | render to string |
| `(cmap)` | empty set/map |
| `(cins S X)` `(cmem S X)` | set insert; membership `1`/`0` |
| `(cput M K V)` `(cget M K)` `(chas M K)` | map insert/replace; lookup (partial); presence `1`/`0` |
| `(cdel C K)` `(cdiff A B)` `(cmerge A B)` `(csize C)` | delete; difference; left-biased union; size |
| `(cjoin A B)` | lattice join of two collections (needs a known lattice spec) |
| `(ckeys M)` `(cvals M)` `(set2lst S)` `(lst2set L)` | conversions |
| `(lempty)` `(lpush L X)` `(lcat A B)` | empty list; append one element **at the end**; concatenate |
| `(llen L)` `(lref L I)` `(lset L I X)` `(lins L I X)` `(ldel L I)` | length; index (partial); update; insert; delete |
| `(lslice L I J)` `(lrev L)` `(lidx L X)` `(lmem L X)` `(lsort L)` `(aslst X)` | slice `[I,J)`; reverse; index of (partial); member `1`/`0`; sort (raw order); view `any` as list (partial) |
| `(one)` `(inf)` `(cplus A B)` | count-lattice values |
| `(top)` | flat-lattice conflict value |

Partial operations (no answer, the match just fails): `cget aslst lref lset
lins ldel lidx sidx schar s2i s2f`.

Membership tests return integers, so test them explicitly: `(= 1 (cmem S X))`.

```slog
table (word str)
table (info str int str int)
rule (word "hello") (word "slog")
rule (word W)
     (= N (size W))
     (= Up (+ W "!"))
     (= Third (substr W 2 3))
     (= HasL (shas W "l"))
  --> (info W N (+ Up Third) HasL)
```

Mixed int/float needs an explicit conversion:

```slog
table (count_of str int)
table (ratio str float)
rule (count_of "a" 3)
rule (count_of K N) --> (ratio K (/ (tofloat N) 4.0))
```

## 5. Negation and stratification

`~(rel args...)` succeeds when no row matches. Every variable in it must be
bound by an earlier positive clause (`_` is allowed for "any value").

```slog
table (node int)
table (edge int int)
table (has_parent int)
table (root int)
rule (edge 1 2) (edge 1 3) (edge 3 4)
rule (edge X Y) --> (node X) (node Y) (has_parent Y)
rule (node X) ~(has_parent X) --> (root X)
```

Negation is **stratified**: the negated relation is computed completely in an
earlier stratum before the negating rule runs. Therefore a relation may not
depend negatively on itself through any cycle (`p` uses `~q` and `q` depends
on `p`). Negation inside a recursive rule is fine when the negated relation is
not in that recursion:

```slog
table (edge int int)
table (blocked int)
table (reach int int)
rule (edge 1 2) (edge 2 3) (edge 3 4) (edge 2 5) (blocked 3)
rule (edge X Y) ~(blocked Y) --> (reach X Y)
rule (reach X Y) (edge Y Z) ~(blocked Z) --> (reach X Z)
```

Universal statements ("every predecessor ...", "no path avoids ...") become
negation of an existential computed in a lower stratum, or a closed lattice
read (section 7).

## 6. Lists, sets, and maps

All collections are immutable, canonical (content-equal values are the same
value), usable as columns, keys, and set elements.

### Lists

```slog
table (row (list int))
table (ends int int)
table (tail (list int))
table (padded (list int))
table (stats int int)
rule (row [1 2 3 4]) (row [7])
;; patterns: [Head Rest ...], [First Middle ... Last], [] for empty
rule (row [X XS ...]) --> (tail XS)
rule (row [F M ... L]) --> (ends F L)
;; construction with splices
rule (row L) --> (padded [0 L ... 9])
rule (padded L) (= N (llen L)) (= X (lref L 1)) --> (stats N X)
```

`list` alone means a list of `any`. Prefer `(list T)` when elements are
uniform. Several variable-length splices in one pattern match **one**
deterministic split, not every split.

Known compiler bug: binding a spliced list literal with `=` and then calling
list operations on it in the same rule (`(= L2 [0 L ... 9]) (= N (llen L2))`)
fails with `plan-stratum: circular let dependencies`. Build the list in one
rule's head and measure it in another, as above.

### Sets

```slog
table (perm str cset)
table (can_write str)
table (perm_count str int)
rule (perm "ada" {"read" "write"}) (perm "bob" {"read"})
rule (perm U S) (= 1 (cmem S "write")) --> (can_write U)
rule (perm U S) (= N (csize S)) --> (perm_count U N)
```

The empty set/map is `(cmap)`; build singletons with `(cins (cmap) X)`.

### Maps

```slog
table (scores cmap)
table (lookup str int)
table (missing str)
rule (scores {"ada":92 "grace":88})
rule (scores M) (= V (cget M "ada")) --> (lookup "ada" V)
rule (scores M) (= 0 (chas M "linus")) --> (missing "linus")
rule (scores M) (= M2 (cput M "linus" 70)) (= V (cget M2 "linus")) --> (lookup "linus" V)
```

`cget` is partial: a missing key makes the match fail silently. Use `chas`
when both outcomes matter. `cmerge A B` is left-biased (A wins).

The library `include "list.slog"` provides demand wrappers (`lst_append`,
`lst_take`, `lst_rev`, `lst_ref`, ...); native primitives are usually better.
Do not `include "set.slog"`/`"map.slog"` in new code: they switch brace
literals to an older integer-keyed representation.

## 7. Lattices and aggregation

A lattice declaration names a value spec; a table whose **last** column has
that type keeps **one joined value per key** (the other columns).

```text
(min int)  (min int #:floor 0)  (min float)
(max int)  (max float #:ceiling 1.0)
(count)                 ;; absent < (one) < (inf)
(flat T)                ;; absent < one value < (top) on conflict
(set T)                 ;; union
(map K SPEC)            ;; pointwise join of child lattice SPEC
```

`#:floor`/`#:ceiling` are allowed only on top-level `min`/`max`, not inside
`map`.

### Min / max (shortest paths, best scores)

```slog
lattice (cost (min int #:floor 0))
table (edge str str int)
table (dist str str cost)
rule (edge "a" "b" 4) (edge "b" "c" 1) (edge "a" "c" 9) (edge "c" "d" 2)
rule (edge X Y W) --> (dist X Y W)
rule (dist X Y D) (edge Y Z W) --> (dist X Z (+ D W))
```

`dist "a" "c"` ends as `5`, not `9`: proposals for one key are joined with
`min`. With non-negative weights and a floor the descent is finite.

### Monotonicity: what you may do with a lattice value while it grows

Inside the recursive component that produces a lattice, its value is still
changing. Only these uses are allowed there:

- `min`/`max`: pass it through, `+`/`-` with a non-lattice operand (minuend
  only for `-`), `min`/`max`, multiplication by a non-negative literal.
- `count`: `cplus`. `flat`: only pass through.
- `set`: `cins` into it, `cmerge`, `cjoin`, and the `R_has` view.
- `map`: `cput` into it, `cget` to descend, `cjoin`, and the `R_at` view.

Anything else (copying into a plain table, `=` tests, comparison guards,
`csize`, using it as a key) is **rejected inside the recursion** but is fine
in a rule that only *reads* the finished lattice: the compiler schedules such
rules in a later stratum automatically.

```slog
lattice (cost (min int #:floor 0))
table (edge int int int)
table (dist int int cost)
table (cheap int int)
table (to4 int int)
rule (edge 1 2 10) (edge 2 3 5) (edge 1 3 100) (edge 3 4 1)
rule (edge X Y W) --> (dist X Y W)
rule (dist X Y D) (edge Y Z W) --> (dist X Z (+ D W))
;; these only read dist, so they run after it is closed
rule (dist X Y D) (< D 12) --> (cheap X Y)
rule (dist X 4 D) --> (to4 X D)
```

### Count

```slog
lattice (card (count))
table (defines str str)
table (definitions str card)
table (multiply_defined str)
table (unique_def str)
rule (defines "s1" "x") (defines "s2" "x") (defines "s3" "y")
rule (defines Site Name) --> (definitions Name (one))
;; joining (one) with (one) stays (one): only evidence of two distinct
;; contributions, or cplus, reaches (inf)
rule (defines S1 Name) (defines S2 Name) (/= S1 S2) --> (definitions Name (inf))
;; later stratum: definitions is closed, so = tests are allowed
rule (definitions Name C) (= C (inf)) --> (multiply_defined Name)
rule (definitions Name C) (= C (one)) --> (unique_def Name)
```

`count` is an abstract cardinality (one vs. many), not a count of derivations:
re-deriving `(one)` from another rule changes nothing. `(cplus A B)` adds
counts along a rule (`one + one = inf`). For an exact count of a closed
relation, collect into a set and take `csize` (below).

### Exact counts and sums (aggregation)

Slog has no `count`/`sum` aggregate syntax. Aggregate by collecting into a set
lattice, then measure the closed set in a later stratum:

```slog
lattice (strs (set str))
table (enrolled str str)
table (roster str strs)
table (class_size str int)
rule (enrolled "cs101" "ada") (enrolled "cs101" "bob") (enrolled "ma201" "ada")
rule (enrolled C S) (= One (cins (cmap) S)) --> (roster C One)
rule (roster C Set) (= N (csize Set)) --> (class_size C N)
```

For a sum, collect the elements into a list with `set2lst` and fold it with a
recursive demand (section 8), or keep a `max`/`min` when that is the
question.

### Flat (constant propagation)

```slog
union (value (vnum int) (vstr str))
lattice (fv (flat value))
table (assign int int value)
table (flow int int)
table (regval int int fv)
table (nonconst int int)
table (constant int int int)
rule (assign 1 10 (vnum 5)) (assign 2 11 (vnum 1)) (assign 3 11 (vstr "two"))
rule (flow 1 2) (flow 1 3) (flow 2 4) (flow 3 4)
rule (assign L R K) --> (regval L R K)
rule (flow L L2) (regval L R V) --> (regval L2 R V)
;; later stratum: regval is closed, so = tests are allowed
rule (regval L R V) (= V (top)) --> (nonconst L R)
rule (regval L R (vnum N)) --> (constant L R N)
```

### Set and map lattices; the R_has / R_at views

```slog
lattice (iset (set int))
table (edge int int)
table (src int)
table (reach int iset)
table (reach_size int int)
rule (src 1) (edge 1 2) (edge 2 3) (edge 5 6)
rule (src S) (= R (cins (cmap) S)) --> (reach S R)
;; reach_has is synthesized: one row per (key, element), usable in recursion
rule (reach_has S A) (edge A B) (= R (cins (cmap) B)) --> (reach S R)
rule (reach S R) (= N (csize R)) --> (reach_size S N)
```

For a table `R` whose last column is `(set T)`, Slog synthesizes `R_has
key... element`; for `(map K SPEC)` it synthesizes `R_at key... mapkey value`.
Do not declare those names yourself.

```slog
lattice (best (map str (min int)))
table (measure str str int)
table (summary str best)
table (best_of str str int)
rule (measure "g" "a" 5) (measure "g" "a" 3) (measure "g" "b" 7)
rule (measure G N C) (= M (cput (cmap) N C)) --> (summary G M)
rule (summary_at G N C) --> (best_of G N C)
```

Negating a lattice relation names only its key columns: `~(dist X Y)` means
"no value for key (X, Y)".

## 8. Demand functions (memoized, top-down calls)

`demand (f in-type ...) out-type ...` declares a relation computed only for
inputs that some rule asks for. Its relational shape is inputs then answers.

```slog
demand (fib int) int
rule (fib N N) <-- (< N 2)
rule (fib N (+ (fib (- N 1)) (fib (- N 2)))) <-- (>= N 2)

table (answer int)
rule (answer (fib 30))
```

- **Call** in value position `(fib 30)` (single-answer demands only): asks,
  then resumes once per answer. No answer means the rule does not fire.
- **Judgment** `(f in... out...)` in a body asks and binds the answers; in a
  head (or as an arrowless rule) it answers demands.
- **Enumeration** `(f in...)` as a whole body clause (answers omitted) lists the
  inputs that have been asked; as a head it asks without waiting.
- Answers are a set: several rules may answer the same input (nondeterminism).
- Demand needs at least one input and one answer column.
- Prefer one arrowless rule per answer case; grouping several judgment heads
  in one `rule` makes them gate jointly.

A multi-answer demand is used in full form:

```slog
demand (divmod int int) int int
rule (divmod N D (/ N D) (% N D)) <-- (/= D 0)
table (digits int int)
rule (divmod 47 10 Q R) --> (digits Q R)
```

Recursive list folding with demand (sum of a list):

```slog
demand (sum (list int)) int
rule (sum [] 0)
rule (sum [X XS ...] (+ X (sum XS)))
table (total int)
rule (total (sum [1 2 3 4]))
```

Lambdas make closures (`clo`); a closure variable is called like a function:

```slog
demand (map2 clo list) list
rule (map2 F [] [])
rule (map2 F [X XS ...] [(F X) (map2 F XS) ...])
table (factor int)
table (scaled list)
rule (factor 10)
rule (factor K) (= R (map2 (lambda (N) (* N K)) [1 2 3])) --> (scaled R)
```

For demand `f`, the compiler creates request values `(f in...)` and the answer
table `f_ans`; `(f_ans (f A B) C)` enumerates answers already demanded,
without asking.

Use demand for evaluators, parsers, type checkers, and lookups over a narrow
set of inputs. Use lattices when many derivations join into one summary.

## 9. Files and modules

Put these forms first in a file:

- `include "file.slog"`: textual combination into this program; relative to
  the including file, falling back to the repository `lib/` directory. A
  missing include only warns.
- `run "file.slog"`: run another program to fixpoint first and use its
  relations as inputs (a settled stage).
- `instantiate "lib.slog" as g`: a fresh namespaced copy; its relations are
  `g.edge`, `g.path`, ...; two instances never share relations.

```text
instantiate "graph-lib.slog" as left
rule (seed X Y) --> (left.edge X Y)
rule (left.path X Y) --> (answer X Y)
```

`import`, `export`, `def`, and `let` exist in the parser but are not part of
the supported language. Do not use them.

`extern` declares an oracle-backed demand answered by the runtime (used by
`lib/smt.slog`); user programs normally use the SMT library rather than
writing `extern` (search the docs for "smt" when needed).

## 10. Runtime error facts

Well-typed programs can still hit bad data. Such a deduction is abandoned and
an `(error E)` fact is recorded instead; the run continues and the driver
warns. Variants: `(div_by_zero Loc N)`, `(modulo_by_zero Loc N)`,
`(nan_result Loc Op X)`, `(toint_range Loc X)`, `(type_mismatch Loc Op A B)`,
`(malformed_deduction Loc Rel Col Value)`, `(mpz_overflow ...)`,
`(int_overflow ...)`, `(mpz_table_overflow ...)`, `(smt_bad_formula ...)`.

```slog
table (pair int int)
table (quot int)
table (bad_division int)
rule (pair 10 2) (pair 7 0)
rule (pair A B) --> (quot (/ A B))
rule (error (div_by_zero Loc N)) --> (bad_division N)
```

`malformed_deduction` usually means an `any` (or overlapping union) value was
written into a column of a narrower type: fix the column types.

## 11. The REPL query language (`?`), used by the `query` tool

Queries run against the evaluated program. One line:

```text
?(rel T ...)                         one relation
? (rel ...) (rel ...) ... -> (X Y)   join, then project
?count (rel ...) ...                 number of matches
?exists (rel ...) ...                yes / no
```

- `?(atom)` single relation; `? atom atom ... -> (Vars)` join with projection;
  without `->` every variable projects in first-appearance order.
- Guards: `< <= > >= = /=` on bound values. `~(rel ...)` absence filter.
- Computes `(= V (op ...))` only for `tofloat size sidx shas aslst llen lref
  lidx lmem`. Everything else (`+`, `cget`, ...) is rejected: add a rule to
  the program instead and query its relation.
- `?count` counts matches; `?exists` stops at the first.
- `#N` splices a value handle shown in an earlier answer (`?(prog #3)`).

Known pitfalls (do not misread the answers):

- **Duplicates:** projection and `_` keep one row per match (bag semantics).
  `?(path _ Y)` may list a `Y` several times, and `?count` counts duplicates.
- **Unknown string literals:** a string that appears nowhere in the database
  makes the *whole* query empty, even in `/=` or `~`. Do not use string
  constants that may be absent as negative tests.
- **Negation needs every variable bound, and `_` counts as unbound**, so
  "nodes with no out-edge" cannot be asked as `~(edge X _)`: add a rule
  that derives `has_out` and query `~(has_out X)`.
- **`=` does not bind:** `(= Z 3)` is only a post-filter; write the constant in
  the atom instead (`(p Y 3)`), or a large join may exhaust its work budget
  and report 0 rows.
- **Not queryable:** lattice relations ("unknown relation"; add a rule that
  copies the closed values into a plain table), struct/constructor relations,
  constructor patterns like `?(prog (num X))` (only variables, numbers,
  strings, and `#N` are terms), and `true`/`false` (read as variables). To
  find rows holding a structured value, add a rule such as
  `rule (prog (num N)) --> (prog_num N)` and query `prog_num`.
- **`?count` stops at a work budget** on big joins and reports `N+`.

The examples below run against this program; a `;; =>` line shows (part of)
the answer to the query above it and is not part of the query.

```slog
table (edge int int)
table (path int int)
table (node int)
table (has_out int)
table (name int str)
lattice (cost (min int #:floor 0))
table (dist int int cost)
table (dist_plain int int int)
union (expr (num int) (negate expr))
table (prog expr)
rule (edge 1 2) (edge 2 3) (edge 3 4) (edge 1 3)
rule (name 1 "one") (name 2 "two")
rule (edge X Y) --> (path X Y) (node X) (node Y) (has_out X)
rule (path X Y) (edge Y Z) --> (path X Z)
rule (edge X Y) --> (dist X Y 1)
rule (dist X Y D) (edge Y Z) --> (dist X Z (+ D 1))
rule (dist X Y D) --> (dist_plain X Y D)
rule (prog (negate (num 3))) (prog (num 4))
```

```query
?(path 1 Y)
;; => 3 rows
? (path X Y) (edge Y Z) -> (X Z)
;; => 3 rows
?count (path X _)
;; => 6 rows match
?exists (path 1 4)
;; => yes
? (path X Y) (< X Y) (/= Y 3) -> (X Y)
;; => 4 rows
? (node X) ~(has_out X)
;; => 1 row
? (edge X Y) (= N (tofloat Y)) -> (X N)
;; => (3 4.0)
?(path _ Y)
;; => 6 rows
? (name X N) (/= N "zzz")
;; => 0 rows
? (name X N) (/= N "one")
;; => 1 row
? (node X) ~(edge X _)
;; => error: unsafe-negation
? (edge X Y) (= Z (+ X Y)) -> (Z)
;; => error: not in the audited query-compute whitelist
?(dist X Y D)
;; => error: unknown relation "dist"
?(dist_plain 1 Y D)
;; => 3 rows
?(prog E)
;; => (prog (negate (num 3)) #1)
?(prog #1)
;; => yes
?(prog (num X))
;; => error: unsupported query term
?(path 1 "a")
;; => error: incompatible with int
?(path X)
;; => error: expects 2 terms
```

`#1` refers to the value an earlier answer printed with that handle.

## 12. Compile errors: what they mean and how to fix them

Most errors carry `file:line:col` (the line in the program text); some do
not, so search the program for the names the message mentions. Each block
below fails with the message on its first line.

### Undeclared relation, constructor, or column count

```slog-error
;; error: Table b in (b 2) is not defined
table (a int)
rule (a 1)
rule (b 2) <-- (a X)
```

Declare it (`table (b int)`) or fix the spelling. The constructor forms read
`Struct sub in (sub ...) is not defined` and `Struct num takes 1 fields but
is used with 2`.

```slog-error
;; error: edge takes 2 columns but is used with 3
table (edge int int)
rule (edge 1 2 3)
```

### Type mismatch

```slog-error
;; error: does not match type 'str'
table (age str int)
rule (age "ada" "thirty-six")
```

The wording is `VALUE : TYPE does not match type 'OTHER'`, with the two types
in either order; read it as "these two types meet here and differ". A
constructor from the wrong union reads `_t... : expr does not match type
'tint'`. Mixing `int` and `float` in arithmetic has no location:

```slog-error
;; error: : float and X : int do not match
table (a int)
table (b float)
rule (a 1)
rule (a X) --> (b (+ X 1.5))
```

Fix with `(+ (tofloat X) 1.5)`.

### Unbound variable

```slog-error
;; error: this is often an unbound variable
table (a int)
table (b int)
rule (a 1)
rule (b Y) <-- (a X)
```

The message is `internal error while compiling the rule at FILE:LINE -- this
is often an unbound variable ... key: 'Y`; the key names the variable. Every
head variable must come from the body or a `(= V ...)`. The same error with a
key such as `'red` means an enum member or nullary constructor was written
without parentheses (`red` instead of `(red)`), so it was read as a variable.
An arrowless rule with variables (`rule (a X) (b X)`) fails the same way: it
is a set of facts, and facts must be ground; add the arrow.

An unbound variable inside a computation fails differently:

```slog-error
;; error: circular let dependencies
table (a int)
table (b int)
rule (a 1)
rule (a X) --> (b (+ X Y))
```

### Wildcard in a head

```slog-error
;; error: wildcard in a head
table (a int)
table (b int int)
rule (a 1)
rule (b _ N) <-- (a N)
```

### Unsafe negation (unbound variable under `~`)

```slog-error
;; error: unsafe negation
table (node int)
table (edge int int)
table (sink int)
rule (node 1) (edge 1 2)
rule (node X) ~(edge Y Z) --> (sink X)
```

Bind the variables first, or use `_` for "any value": in a rule,
`~(edge X _)` is accepted (in a `?` query it is not).

### Negation through recursion

```slog-error
;; error: negation through recursion
table (node int)
table (p int)
table (q int)
rule (node 1) (node 2)
rule (node X) ~(q X) --> (p X)
rule (p X) --> (q X)
```

The message names the cycle: `the rule at FILE:LINE negates q, but q and p
are mutually recursive (cycle: p q)`. No stratification exists; restructure
so the negated relation is computed only from relations that do not depend
on the negating rule.

### Lattice read too early

```slog-error
;; error: still-ascending lattice value D cannot be emitted into seen
lattice (cost (min int))
table (edge int int int)
table (dist int int cost)
table (seen int int int)
rule (edge 1 2 3) (edge 2 3 4)
rule (edge X Y W) --> (dist X Y W)
rule (dist X Y D) (edge Y Z W) --> (dist X Z (+ D W))
rule (dist X Y D) --> (seen X Y D)
rule (seen X Y D) (edge Y Z W) --> (dist X Z D)
```

A plain table copied from a growing lattice and fed back into it cannot be
retracted when the value improves. Keep the recursion inside the lattice
table; read the value into plain tables only from rules that do not feed back.

### Declaration errors

```slog-error
;; error: must be the last column
lattice (cost (min int))
table (dist cost int)
rule (dist 1 2)
```

Others: `map relation component needs at least one key column` (a lattice
table with no key: give it a key column, or make the column a plain `cset`),
`Table or struct done must have at least one column` (zero-arity
table: add a column), `Type declarations for a conflict: (table int) vs
(table str)` (declared twice), `Demand relation f must declare at least one
answer column`.

### Hyphenated names and `const`

```slog-error
;; error: on-cycle is not a valid name
table (edge int int)
table (on-cycle int)
rule (edge 1 1)
rule (edge X X) --> (on-cycle X)
```

Names may not contain `-`: write `on_cycle` (subtraction is `(- a b)`).
`const` is reserved too (it is the compiler's spelling of a literal): name
such a constructor `lit`.

### Parse errors and the single `;`

```slog-error
;; error: Table ; in (b X) ; copy is not defined
table (a int)
table (b int)
rule (a 1)
rule (a X) --> (b X) ; copy
```

A single `;` is an operator, so `; copy` became part of the head. Use `;;`.
Unbalanced parentheses give `Expected an atom---literal, variable, s-expr,
etc.` (or `expected ')'`) at the token where parsing stopped; look a line or
two before it.

### Mistakes that compile but go wrong at runtime

These evaluate without a compile error. Look for an `error` relation with rows
in the evaluation and query it with `?(error E)`.

- **A constructor named like a primitive** is called as the primitive. With
  `union (expr (num int) (neg expr))`, the fact `(prog (neg (num 3)))`
  computes arithmetic negation of a struct: a `type_mismatch` error, and every
  head of that rule is lost. Never name constructors `neg`, `abs`, `min`,
  `max`, `pow`, `log`, `exp`, `floor`, `ceil`, `round`, `size`, `top`, `one`,
  `inf`, or any other name in section 4.
- **Ordering guards on strings** (`(< S "b")`) are numeric only: each match
  produces a `type_mismatch` error instead of a comparison.
- **An `any` value written into a narrower column** keeps the rows that fit
  and records `malformed_deduction` for the others.
- **A missing `include`** only prints a warning; the declarations it should
  have provided are then missing.

```slog
table (a any)
table (b int)
rule (a "x") (a 3)
rule (a X) --> (b X)
```

```query
?(b X)
;; => 1 row
?(error E)
;; => malformed_deduction
```

## 13. Idioms and worked examples

### 13.1 Transitive closure, reachability from a source, and cycles

```slog
table (edge str str)
table (path str str)
table (reach str)
table (start str)
table (on_cycle str)
rule (edge "a" "b") (edge "b" "c") (edge "c" "a") (edge "c" "d")
rule (start "a")
rule (edge X Y) --> (path X Y)
rule (path X Y) (edge Y Z) --> (path X Z)
rule (start S) --> (reach S)
rule (reach X) (edge X Y) --> (reach Y)
rule (path X X) --> (on_cycle X)
```

Prefer the left-linear form `(path X Y) (edge Y Z)`; it is cheaper than
`(path X Y) (path Y Z)`. Same-component test: `(path X Y) (path Y X)`.

### 13.2 An arithmetic language: an ADT, an environment, two evaluators

A demand-driven evaluator with a map environment:

```slog
union (expr (num int)
            (var str)
            (add expr expr)
            (mul expr expr)
            (let str expr expr))

demand (eval expr cmap) int
rule (eval (num N) Env N)
rule (eval (var X) Env (cget Env X))
rule (eval (add A B) Env (+ (eval A Env) (eval B Env)))
rule (eval (mul A B) Env (* (eval A Env) (eval B Env)))
rule (eval (let X E B) Env (eval B (cput Env X (eval E Env))))

table (prog str expr)
table (result str int)
rule (prog "p1" (add (num 1) (mul (num 2) (num 3))))
rule (prog "p2" (let "x" (num 5) (add (var "x") (var "x"))))
rule (prog "p3" (add (var "unbound") (num 1)))
rule (prog Name E) --> (result Name (eval E (cmap)))
```

`p3` produces no result: `cget` of a missing variable fails silently. To
report it, add a rule over the demanded inputs:

```slog
union (expr (num int) (var str) (add expr expr))
demand (eval expr cmap) int
rule (eval (num N) Env N)
rule (eval (var X) Env (cget Env X))
rule (eval (add A B) Env (+ (eval A Env) (eval B Env)))
table (prog expr)
table (value int)
table (unbound_var str)
rule (prog (add (var "y") (num 1)))
rule (prog E) --> (value (eval E (cmap)))
;; (eval E Env) without the answer enumerates the requests that were made
rule (eval (var X) Env) (= 0 (chas Env X)) --> (unbound_var X)
```

A bottom-up evaluator for closed terms visits every interned subterm by
enumerating constructors:

```slog
union (expr (lit int) (plus expr expr) (times expr expr))
table (prog str expr)
table (val expr int)
table (answer str int)
rule (prog "e1" (plus (lit 2) (times (lit 3) (lit 4))))
rule (= E (lit N)) --> (val E N)
rule (= E (plus A B)) (val A X) (val B Y) --> (val E (+ X Y))
rule (= E (times A B)) (val A X) (val B Y) --> (val E (* X Y))
rule (prog Name E) (val E V) --> (answer Name V)
```

### 13.3 Shortest paths with a min lattice, and path extraction

```slog
lattice (cost (min int #:floor 0))
table (edge str str int)
table (dist str cost)
table (source str)
table (final_dist str int)
table (tight_edge str str)
rule (source "s")
rule (edge "s" "a" 4) (edge "s" "b" 1) (edge "b" "a" 2) (edge "a" "t" 5) (edge "b" "t" 9)
rule (source S) --> (dist S 0)
rule (dist X D) (edge X Y W) --> (dist Y (+ D W))
;; later stratum: dist is closed; copy to a plain (queryable) table
rule (dist X D) --> (final_dist X D)
;; edges on some shortest path
rule (dist X DX) (edge X Y W) (dist Y DY) (= DY (+ DX W)) --> (tight_edge X Y)
```

`final_dist` exists because the `query` tool cannot read lattice relations.

### 13.4 Dataflow analyses over a CFG

Reaching definitions (forward, may): a definition reaches a point unless the
variable is redefined on the way. `kill` is a plain relation computed from
the input, so negating it inside the recursion is stratified.

```slog
table (edge str str)          ;; CFG edge
table (defs str str)          ;; (defs Node Var): Node assigns Var
table (uses str str)          ;; (uses Node Var)
table (reach_in str str str)  ;; (reach_in Node DefNode Var)
table (reach_out str str str)
table (kills str str)         ;; Node redefines Var
table (def_use str str str)   ;; (def_use DefNode UseNode Var)
rule (edge "n1" "n2") (edge "n2" "n3") (edge "n3" "n2") (edge "n2" "n4")
rule (defs "n1" "x") (defs "n1" "y") (defs "n3" "x")
rule (uses "n2" "x") (uses "n4" "y") (uses "n3" "x")
rule (defs N V) --> (kills N V)
rule (defs N V) --> (reach_out N N V)
rule (reach_in N D V) ~(kills N V) --> (reach_out N D V)
rule (reach_out P D V) (edge P N) --> (reach_in N D V)
rule (reach_in N D V) (uses N V) --> (def_use D N V)
```

Liveness (backward, may):

```slog
table (edge str str)
table (defs str str)
table (uses str str)
table (live_in str str)
table (live_out str str)
rule (edge "n1" "n2") (edge "n2" "n3") (edge "n3" "n2") (edge "n2" "n4")
rule (defs "n1" "x") (defs "n3" "x") (defs "n2" "y")
rule (uses "n2" "x") (uses "n4" "y") (uses "n3" "x")
rule (uses N V) --> (live_in N V)
rule (live_out N V) ~(defs N V) --> (live_in N V)
rule (edge N S) (live_in S V) --> (live_out N V)
```

Must-analyses (available expressions, dominators) need "on every path". Grow
the complement as a may-relation and negate it in a later stratum, or collect
witnesses into a set lattice and test membership after it closes. Dominators
(see `examples/domtree/domtree.slog`):

```slog
table (edge str str)
table (entry str)
table (node str)
table (nd str str)            ;; (nd D N): entry reaches N avoiding D
table (dom str str)
rule (entry "e")
rule (edge "e" "a") (edge "a" "b") (edge "a" "c") (edge "b" "d") (edge "c" "d")
rule (edge A B) --> (node A) (node B)
rule (entry E) (node D) (/= D E) --> (nd D E)
rule (nd D P) (edge P N) (/= N D) --> (nd D N)
rule (node D) (node N) ~(nd D N) --> (dom D N)
```

Interval or constant domains go in `flat`, `min`/`max`, or `map` lattices
keyed by program point (section 7, flat example).

### 13.5 A 0-CFA abstract interpreter (small CPS-free lambda calculus)

From `examples/tinycfa/0cfa.slog`: an abstract machine whose states are facts.
Continuations are a union; the store maps variables to abstract values.

```slog
union (expr (lambda str expr) (app expr expr) (ref str))
union (val lambda)
union (stack (halt) (kaddr expr) (ar expr stack) (fn val stack))

table (program expr)
table (eval expr stack)
table (ret val stack)
table (store str val)
table (kstore stack stack)
table (result val)

rule (program (app (lambda "x" (app (ref "x") (ref "x")))
                   (lambda "y" (ref "y"))))

rule (program E) --> (eval E (halt))
rule (eval (ref X) K) (store X V) --> (ret V K)
rule (eval (app Ef Ea) K) --> (eval Ef (ar Ea K))
rule (eval (lambda X Eb) K) --> (ret (lambda X Eb) K)
rule (ret V (ar Ea K)) --> (eval Ea (fn V K))
rule (ret V (fn (lambda X Eb) K))
  --> (eval Eb (kaddr Eb)) (store X V) (kstore (kaddr Eb) K)
rule (ret V (kaddr Eb)) (kstore (kaddr Eb) K) --> (ret V K)
rule (ret V (halt)) --> (result V)
```

Note `union (val lambda)`: the `val` type admits exactly the `lambda` arm of
`expr`. For k-CFA, add a context (a list of call sites, truncated with
`lst_take` from `list.slog`) to `eval`, `store`, and the continuation address;
see `examples/schemecfa/` and `examples/kcfa/` (read them with `read_doc`).

### 13.6 Type checking with demand

```slog
union (ty (tint) (tbool) (tarrow ty ty))
union (term (lit int) (bool_lit any) (tvar str) (lam str ty term) (ap term term))
demand (typeof term cmap) ty
rule (typeof (lit N) G (tint))
rule (typeof (bool_lit B) G (tbool))
rule (typeof (tvar X) G (cget G X))
rule (typeof (lam X T B) G (tarrow T (typeof B (cput G X T))))
rule (typeof (ap F A) G R) <-- (typeof F G (tarrow P R)) (typeof A G P)
table (prog str term)
table (has_type str ty)
rule (prog "id_app" (ap (lam "x" (tint) (tvar "x")) (lit 3)))
rule (prog "bad" (ap (lit 1) (lit 2)))
rule (prog N T) --> (has_type N (typeof T (cmap)))
```

`"bad"` has no type: no rule answers it. An ill-typed term is the absence of
an answer, so report it with negation in a later stratum if needed.

### 13.7 Points-to analysis (Andersen, flow-insensitive)

Statements are a union; each rule is one inclusion constraint.

```slog
;; Andersen-style points-to for a tiny pointer language.
union (stmt (addr str str)      ;; p = &x
            (copy str str)      ;; p = q
            (load str str)      ;; p = *q
            (store str str))    ;; *p = q
table (code stmt)
table (pts str str)             ;; (pts P X): P may point to X
table (alias str str)
rule (code (addr "p" "x")) (code (addr "q" "y")) (code (copy "r" "p"))
     (code (store "r" "q")) (code (load "s" "x"))
rule (code (addr P X)) --> (pts P X)
rule (code (copy P Q)) (pts Q X) --> (pts P X)
rule (code (load P Q)) (pts Q R) (pts R X) --> (pts P X)
rule (code (store P Q)) (pts P R) (pts Q X) --> (pts R X)
rule (pts P X) (pts Q X) (/= P Q) --> (alias P Q)
```

### 13.8 Call graph, recursion, and strongly connected components

Walk an AST with a relation that collects every subterm of each body, then
close the call relation:

```slog
union (expr (call str) (seq expr expr) (skip))
table (fundef str expr)
table (calls str str)
table (reach_fn str str)
table (recursive str)
table (body_of str expr)
rule (fundef "main" (seq (call "f") (call "g")))
     (fundef "f" (call "g")) (fundef "g" (seq (skip) (call "f"))) (fundef "h" (skip))
rule (fundef F B) --> (body_of F B)
rule (body_of F (seq A B)) --> (body_of F A) (body_of F B)
rule (body_of F (call G)) --> (calls F G)
rule (calls F G) --> (reach_fn F G)
rule (reach_fn F G) (calls G H) --> (reach_fn F H)
rule (reach_fn F F) --> (recursive F)
```

Strongly connected components as canonical sets: every vertex of a component
gets the same interned set, which then names the component.

```slog
table (edge int int)
table (vertex int)
table (reachable int int)
lattice (iset (set int))
table (scc int iset)
table (component cset)
rule (edge 1 2) (edge 2 1) (edge 2 3) (edge 3 4) (edge 4 3)
rule (edge X Y) --> (vertex X) (vertex Y)
rule (vertex X) --> (reachable X X)
rule (reachable X Y) (edge Y Z) --> (reachable X Z)
rule (reachable X Y) (reachable Y X) (= S (cins (cmap) Y)) --> (scc X S)
rule (scc X S) --> (component S)
```

`component` is a plain `cset` column: a lattice-typed table needs at least one
key column besides the lattice value.

### 13.9 Abstract interpretation with a powerset domain

A finite powerset domain needs no lattice at all: "X may have sign S" is a
plain relation, and the fixpoint is the least solution. Use a `flat` or
`min`/`max` lattice only when you need one joined value per key, and then
case on that value in a later stratum (section 7, flat example).

```slog
;; Sign analysis: a powerset abstract domain is just a relation.
union (sign (pos) (zero) (negative))
union (aexp (lit int) (var str) (plus aexp aexp))
table (assign int str aexp)      ;; (assign L X E): at label L, X := E
table (flow int int)
table (sign_at int str sign)     ;; before label L, X may have sign S
table (aval int aexp sign)       ;; at L, E may evaluate to a value of sign S
table (subexp int aexp)
table (add_sign sign sign sign)
table (maybe_zero int str)
rule (assign 1 "x" (lit 5)) (assign 2 "y" (lit 0))
     (assign 3 "x" (plus (var "x") (var "y"))) (assign 4 "y" (plus (var "x") (lit -7)))
rule (flow 1 2) (flow 2 3) (flow 3 4) (flow 4 3) (flow 4 5)
rule (add_sign (pos) (pos) (pos)) (add_sign (negative) (negative) (negative))
     (add_sign (zero) (pos) (pos)) (add_sign (pos) (zero) (pos))
     (add_sign (zero) (negative) (negative)) (add_sign (negative) (zero) (negative))
     (add_sign (zero) (zero) (zero))
     (add_sign (pos) (negative) (pos)) (add_sign (pos) (negative) (zero)) (add_sign (pos) (negative) (negative))
     (add_sign (negative) (pos) (pos)) (add_sign (negative) (pos) (zero)) (add_sign (negative) (pos) (negative))
;; the expressions to evaluate at each label
rule (assign L _ E) --> (subexp L E)
rule (subexp L (plus A B)) --> (subexp L A) (subexp L B)
rule (subexp L (lit N)) (> N 0) --> (aval L (lit N) (pos))
rule (subexp L (lit 0)) --> (aval L (lit 0) (zero))
rule (subexp L (lit N)) (< N 0) --> (aval L (lit N) (negative))
rule (subexp L (var X)) (sign_at L X S) --> (aval L (var X) S)
rule (subexp L (plus A B)) (aval L A SA) (aval L B SB) (add_sign SA SB S)
  --> (aval L (plus A B) S)
;; transfer along flow edges: the assigned variable gets the new signs,
;; the others keep theirs
rule (flow L L2) (assign L X E) (aval L E S) --> (sign_at L2 X S)
rule (flow L L2) (sign_at L Y S) (assign L X _) (/= X Y) --> (sign_at L2 Y S)
rule (sign_at L X (zero)) --> (maybe_zero L X)
```

### 13.10 Context sensitivity with list contexts (k-CFA style)

Contexts are lists of the most recent `k` call sites; `lst_take` from
`list.slog` truncates them. A demand computes the next context.

```slog
;; Context-sensitive (k = 1) call-site sensitivity sketch with list contexts.
include "list.slog"
table (klimit int)
table (call str str str)        ;; (call Site Caller Callee)
table (entry str)
table (reach str (list str))    ;; (reach Fn Context)
demand (tick str (list str)) (list str)
rule (klimit 1) (entry "main")
rule (call "c1" "main" "f") (call "c2" "main" "f") (call "c3" "f" "g")
rule (tick Site Ctx (lst_take [Site Ctx ...] K)) <-- (klimit K)
rule (entry F) --> (reach F [])
rule (reach F Ctx) (call Site F G) --> (reach G (tick Site Ctx))
```

The full analyses are `examples/schemecfa/` (m-CFA with abstract counting)
and `examples/kcfa/` (k-CFA with environment maps). Read `interp.slog` and
`context.slog` there before writing one.

### 13.11 Sums over a closed set

```slog
;; sum a closed set of numbers
lattice (ints (set int))
table (sale str int)
table (sales_of str ints)
table (total str int)
demand (sum_list (list int)) int
rule (sale "ada" 3) (sale "ada" 4) (sale "bob" 10)
rule (sale P N) (= S (cins (cmap) N)) --> (sales_of P S)
rule (sum_list [] 0)
rule (sum_list [X XS ...] (+ X (sum_list XS)))
rule (sales_of P S) --> (total P (sum_list (set2lst S)))
```

### 13.12 Strings: splitting and parsing

```slog
table (line str)
table (field str int str)
table (num_field str int int)
rule (line "3,alpha,42") (line "7,beta,x")
rule (line L) (= Parts (ssplit L ",")) (= F (lref Parts 0)) --> (field L 0 F)
rule (line L) (= Parts (ssplit L ",")) (= F (lref Parts 2)) --> (field L 2 F)
rule (field L I S) (= N (s2i S)) --> (num_field L I N)
```

`s2i` is partial: `"x"` produces no `num_field` row and no error.

### 13.13 Alternatives inside one clause list

```slog
table (a int)
table (b int)
table (c int)
rule (a 1) (b 2)
rule ((a X) | (b X)) --> (c X)
```

### 13.14 The SMT library

`include "smt.slog"` (found in `lib/`) gives formula constructors (`ic`, `iv`,
`ladd`, `llt`, `land`, `lor`, `lnot`, ...) and demands `smt_check`,
`smt_model`, `smt_core`. Without an external solver configured, ground
formulas are decided and symbolic ones answer `(unknown)`. Search the docs
for "smt" before using it.

```slog
include "smt.slog"
table (probe str verdict)
rule (= V (smt_check (land (llt (ic 1) (ic 3)) (lgt (ic 7) (ic 5))))) --> (probe "true_ground" V)
rule (= V (smt_check (llt (ic 4) (ic 3)))) --> (probe "false_ground" V)
```


### 13.15 Cookbook: common questions and their Slog shape

**Which row achieves the minimum (argmin / argmax)?** Keep the extreme in a
`min`/`max` lattice, then join it back against the rows in a later stratum.

```slog
lattice (low (min int))
table (bid str str int)          ;; (bid Item Bidder Price)
table (best_price str low)
table (winner str str int)
rule (bid "lamp" "ada" 30) (bid "lamp" "bob" 25) (bid "desk" "ada" 90)
rule (bid I _ P) --> (best_price I P)
;; later stratum: join the closed minimum back to the rows achieving it
rule (best_price I P) (bid I B P) --> (winner I B P)
```

```slog
lattice (high (max int))
table (score str str int)        ;; (score Team Player Points)
table (top_score str high)
table (mvp str str)
rule (score "red" "ada" 12) (score "red" "bob" 7) (score "blue" "cy" 9)
rule (score T _ P) --> (top_score T P)
rule (top_score T P) (score T Who P) --> (mvp T Who)
```

**"For all" conditions.** Derive the counterexample relation, then negate it.

```slog
;; "every prerequisite of C is done": negate "some prerequisite is not done"
table (course str)
table (prereq str str)           ;; (prereq C P): P must come before C
table (done str)
table (blocked str)
table (ready str)
rule (course "intro") (course "algo") (course "pl") (course "compilers")
rule (prereq "algo" "intro") (prereq "pl" "intro") (prereq "compilers" "algo")
     (prereq "compilers" "pl")
rule (done "intro") (done "algo")
rule (prereq C P) ~(done P) --> (blocked C)
rule (course C) ~(done C) ~(blocked C) --> (ready C)
```

**A default when no value exists.**

```slog
;; a default for keys with no explicit value
table (user str)
table (setting str int)
table (effective str int)
rule (user "ada") (user "bob") (setting "ada" 3)
rule (setting U V) --> (effective U V)
rule (user U) ~(setting U _) --> (effective U 10)
```

**Set difference, intersection, union.**

```slog
table (a int)
table (b int)
table (only_a int)
table (both int)
table (either int)
rule (a 1) (a 2) (a 3) (b 2) (b 4)
rule (a X) ~(b X) --> (only_a X)
rule (a X) (b X) --> (both X)
rule (a X) --> (either X)
rule (b X) --> (either X)
```

**Symmetric, transitive relations (undirected connectivity).**

```slog
table (link str str)
table (connected str str)
rule (link "a" "b") (link "b" "c") (link "d" "e")
rule (link X Y) --> (connected X Y) (connected Y X)
rule (connected X Y) (connected Y Z) (/= X Z) --> (connected X Z)
```

**Shortest hop counts on a cyclic graph.** Plain recursion on a depth column
(`(depth Y (+ D 1))` in an ordinary table) never terminates on a cycle; a
`min` lattice keeps one value per node and converges.

```slog
;; shortest hop count from a root, without a lattice: BFS layers are a
;; min lattice; plain recursion on depth would not terminate on cycles
lattice (hops (min int #:floor 0))
table (edge str str)
table (depth str hops)
rule (edge "r" "a") (edge "a" "b") (edge "b" "r") (edge "r" "b")
rule (depth "r" 0)
rule (depth X D) (edge X Y) --> (depth Y (+ D 1))
```

**Identifiers.** Do not allocate integer ids. A struct or constructor value is
its own identity (interned), and can be a key, a set element, or a join
column.

```slog
;; structured keys need no id allocation: the term itself is the id
struct (site str int)            ;; file, line
table (call_at site str)
table (callee_count str int)
lattice (sites (set site))
table (sites_of str sites)
rule (call_at (site "a.c" 10) "f") (call_at (site "a.c" 22) "f") (call_at (site "b.c" 3) "g")
rule (call_at S F) (= One (cins (cmap) S)) --> (sites_of F One)
rule (sites_of F S) --> (callee_count F (csize S))
```

**Ordering and ranking.** Relations are unordered and there is no `ORDER BY`
or `LIMIT`. Get the extreme with a `min`/`max` lattice; get "the next one"
with a successor relation (`(next X Y)` derived from the data); `lsort`,
`set2lst`, and `ckeys` order by an internal word order that is not numeric or
alphabetical.

## 14. Working habits in the Studio

- Read the program once (`get_program`), then propose form-sized changes.
- After proposing, `evaluate_proposal`: it reports each relation's row count
  or the first error with its line. Fix and re-evaluate before replying.
  Constructors appear among the relations too (`num`, `add`, ...): their
  counts are the distinct values built.
- Check the counts against what the request implies (a 4-node chain has 6
  paths) and query a few rows. Remember section 11's limits: copy lattice
  values and structured matches into plain helper tables when you must
  inspect them.
- An `error` relation with rows means runtime errors: query `?(error E)`.
- When a relation is unexpectedly empty, find the first relation in the
  chain that is empty and look at the rule feeding it:
  - a misspelled *variable* silently breaks a join (`(edge X Y) (path Y2 Z)`);
  - a constant of the wrong kind never matches (`"1"` vs `1`, `(red)` vs
    `"red"`);
  - a constructor pattern with the wrong shape or arm never matches;
  - a partial operation (`cget`, `lref`, `s2i`, ...) failed silently;
  - a demand was never asked, or no rule answers that input;
  - a negated relation is larger than you think.
- Keep facts that describe inputs separate from rules, one fact per line or
  a few per `rule`, so the author can edit the data.
- When unsure of syntax or a primitive, `search_docs` (e.g. `cget partial`,
  `lattice soundness`) and `read_doc` an example before proposing.
