# 2. Rules and data

The first chapter used relations as graph edges. Relations can also hold
numbers, strings, lists, and values that look more like Java records or class
hierarchies.

## Compute and filter

Here is a small grade report:

```slog
table (score str int int)
table (total str int)
table (passed str)

rule
(score "Ada" 40 52)
(score "Grace" 35 41)
(score "Edsger" 48 49)

rule (score Name A B) (= Sum (+ A B)) --> (total Name Sum)
rule (total Name Sum) (>= Sum 80) --> (passed Name)
```

`(+ A B)` is a built-in operation. The equality clause binds its result to
`Sum`. `>=` is a guard: the rule continues only when the comparison is true.

You can usually write the computed value directly in the conclusion:

```slog
rule (score Name A B) --> (total Name (+ A B))
```

The longer form is handy when another clause also needs `Sum`.

Slog has integers of arbitrary size, binary64 floats, and strings. Integer
division truncates toward zero. Use `tofloat` when statically known integer and
float values need to take part in the same operation. `+` also concatenates
two strings.

```slog
table (demo any)
rule
(demo (- 3 10))
(demo (/ 7 2))
(demo (+ (tofloat 2) 0.5))
(demo (+ "s" "log"))
```

The complete operation list is in the
[built-in reference](../user/builtins.md).

## Trees as values

Suppose we want to represent arithmetic expressions. A `union` declares a
closed set of constructors:

```slog
union (expr (num int)
            (add expr expr)
            (mul expr expr)
            (var str))

table (input expr)
table (subexpr expr expr)

rule (input (add (num 1) (mul (var "x") (num 2))))

rule (input E) --> (subexpr E E)
rule (subexpr Root (add A B)) --> (subexpr Root A) (subexpr Root B)
rule (subexpr Root (mul A B)) --> (subexpr Root A) (subexpr Root B)
```

`(add A B)` in a rule body is a pattern. It matches only an `add` value and
binds its two fields. Values can nest to any depth. Equal values are interned,
so comparing two whole trees is cheap.

Use a `struct` when there is one constructor rather than several:

```slog
struct (point int int)
table (origin point)
rule (origin (point 0 0))
```

Use an `enum` for a fixed group of named choices:

```slog
enum (color red green blue)
table (favorite str color)
rule (favorite "Ada" (green))
```

Constructor names include parentheses, even when they have no fields.

## Lists and patterns

Lists are immutable sequence values:

```slog
table (words (list str))
table (first_word str)
table (tail (list str))

rule (words ["logic" "rules" "graphs"])
rule (words [First Rest ...]) --> (first_word First) (tail Rest)
```

`[First Rest ...]` matches a nonempty list. `First` is one element and
`Rest` is the list left over. A literal list can splice another list with the
same syntax:

```slog
table (again (list str))
rule (tail Rest) --> (again ["start" Rest ... "end"])
```

`[]` is the empty list. A failed list pattern simply means the rule does not
match that row.

## Alternatives, inequality, and absence

`|` gives alternatives in a rule body. These two rules are equivalent:

```slog
rule (subexpr Root (add A B)) (subexpr A X) --> (subexpr Root X)
rule (subexpr Root (add A B)) (subexpr B X) --> (subexpr Root X)
```

```slog
rule (subexpr Root (add A B))
     (subexpr A X) | (subexpr B X)
  --> (subexpr Root X)
```

Use `/=` for values that must differ. Use `_` for a value you do not need:

```slog
rule (edge X Y) (/= X Y) --> (nonself_edge X Y)
rule (score Name _ _) --> (student Name)
```

Slog also supports stratified negation. `~(blocked X Y)` means there is no
matching `blocked` fact after that relation has reached its fixpoint:

```slog
table (candidate str str)
table (blocked str str)
table (allowed str str)

rule (candidate X Y) ~(blocked X Y) --> (allowed X Y)
```

Variables in a negated clause must already be bound by positive clauses.
Negation cannot take part in a negative recursion cycle. The compiler orders
valid cases into strata and rejects invalid ones.

## What to remember

- Compute a value with `(= X (operation ...))` or place the operation directly
  where its result is needed.
- Guards such as `<`, `>=`, and `/=` filter matches.
- `struct`, `union`, and `enum` define structured value types.
- Rules pattern-match structures and lists by shape.
- `~(relation ...)` tests settled absence, not temporary absence during a
  fixpoint.

Next: [functions, collections, and lattices](03-combining-features.md).
