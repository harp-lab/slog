# 3. Functions, collections, and lattices

Relations are enough for many programs. Slog also has three tools for making
larger programs clearer: demand-driven functions, first-class collections,
and lattice-valued relations.

## A relation that acts like a function

A `demand` declaration separates inputs from answers:

```slog
demand (fib int) int

rule (fib 0 0)
rule (fib 1 1)
rule (> N 1)
     (= A (fib (- N 1)))
     (= B (fib (- N 2)))
  --> (fib N (+ A B))

table (wanted int)
table (answer int int)

rule (wanted 10) (wanted 20)
rule (wanted N) (= F (fib N)) --> (answer N F)
```

`fib` still has ordinary relational rules: its full shape is `(fib input
answer)`. The value-position call `(fib N)` is convenient syntax for asking
for its answer. Slog evaluates only the inputs reached from a call and stores
answers as facts, so repeated calls reuse earlier work.

A demand may have no answer, one answer, or several answers. If it declares
more than one answer column, call it in full relational form:

```slog
demand (divide int int) int int
rule (divide N D Q R) <-- (= Q (/ N D)) (= R (% N D))

table (piece int int)
rule (divide 17 5 Q R) --> (piece Q R)
```

Demands are not Java methods. They are memoized relations with a useful call
syntax.

## Functions over lists

Demand calls can be nested inside structured values. This makes direct
recursive definitions compact:

```slog
demand (sum (list int)) int
rule (sum [] 0)
rule (sum [X XS ...] (+ X (sum XS)))

demand (map2 clo list) list
rule (map2 F [] [])
rule (map2 F [X XS ...] [(F X) (map2 F XS) ...])

table (scaled list)
rule (= R (map2 (lambda (N) (* N 10)) [1 2 3])) --> (scaled R)
```

The last result is `[10 20 30]`. A lambda is compiled to a closure value and
may capture variables from the rule that creates it. This feature is useful,
but ordinary named demands are easier to debug when a function will be reused.

## Sets and maps as values

Braces construct canonical immutable collections:

```slog
table (tags cset)
table (prices cmap)

rule (tags {"logic" "analysis"})
rule (prices {"tea":3 "coffee":4})
```

Native collection operations return updated values rather than modifying the
old value:

```slog
table (set_demo cset)
table (map_demo cmap)
table (collection_demo cset cmap)

rule (= S (cins {1 2} 3)) --> (set_demo S)
rule (= M (cput {"a":10} "b" 20)) --> (map_demo M)
rule (set_demo S) (map_demo M) --> (collection_demo S M)
```

`cmem S X` and `chas M K` return `1` or `0`. `cget M K` is partial: if the key
is absent, the current rule match stops without producing a row. Guard it with
`chas` when absence is expected.

Lists, sets, and maps are canonical. Two collections with equal contents are
the same Slog value even if they were built in different orders. See the
[collection guide](../user/collections.md) for every operation and the older
rule-based `pset` and `pmap` libraries.

## Keep the best result with a lattice

A normal relation keeps every distinct row. Sometimes a key should keep a
single summary. This shortest-path program keeps the smallest distance for
each pair of nodes:

```slog
lattice (cost (min int #:floor 0))

table (edge str str int)
table (distance str str cost)

rule
(edge "a" "b" 4)
(edge "a" "c" 10)
(edge "b" "c" 3)
(edge "c" "d" 2)

rule (edge X Y W) --> (distance X Y W)
rule (distance X Y A) (distance Y Z B)
  --> (distance X Z (+ A B))
```

For a given `(X, Z)` key, `distance` joins all proposed values with `min`.
The row for `("a", "c")` settles at `7`, not `10`.

The floor clamps every smaller proposal to zero. That gives this integer
lattice a finite range of improvements even if the input accidentally contains
a negative cycle. Separately, Slog rejects rules that inspect an unfinished
lattice value in a way that could invalidate an earlier result.

Other lattice value specifications are `max`, `count`, `flat`, `set`, and
recursive `map`. The [lattice guide](../user/functions-and-lattices.md) covers
their order, joins, limits, and the compiler's checks.

## A useful combination

The pieces compose. A program analysis can:

- represent source syntax with unions and nested values;
- follow control flow with recursive relations;
- call a demand-driven evaluator only for expressions that become reachable;
- accumulate possible values in a set lattice;
- ask the SMT library whether a path condition is possible;
- save the result and run a small follow-up query over it.

You do not need all of those features in one program. Start with plain tables
and rules, then add a demand or lattice when it expresses the result more
directly.

Next: [files, databases, and follow-up queries](04-projects-and-queries.md).
