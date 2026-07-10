# 4. Structured data

Rows of ints and strings only go so far. Real programs deal in
*shapes*: a syntax tree, a geometric figure, a machine state. In Slog,
structured values are ordinary column values — built in rules, matched
in rules, nested as deep as you like.

## Three declarations

**`struct`** declares a value with one fixed shape, like a tiny
immutable object with no methods:

```
struct (point int int)
```

Now `(point 3 4)` is a value — usable anywhere an `int` or `str` was.

**`union`** declares a choice of shapes under one type name — if you
know Java 17's sealed interfaces, it's that; otherwise think "one of
the following, each tagged with its name":

```
union (expr (num int)
            (add expr expr)
            (mul expr expr))
```

An `expr` is a number, a sum, or a product — and sums and products
contain `expr`s, so the type is recursive: these are trees.

**`enum`** declares plain named constants:

```
enum (color red green blue)
```

`(red)` is a value of type `color`.

## Building and matching

Watch both directions at once. We assert one tree, then take it apart:

```
table (term expr)
table (sub expr)
table (hasmul int)

rule (term (add (num 1) (mul (num 2) (num 3))))

rule (term e) --> (sub e)
rule (sub (add a b)) --> (sub a) (sub b)
rule (sub (mul a b)) --> (sub a) (sub b)
rule (sub (mul _ _)) --> (hasmul 1)
```

In the body-less rule, `(add (num 1) (mul (num 2) (num 3)))` **builds**
the tree `1 + 2×3`. In the rule bodies, the same syntax **matches**: the
pattern `(add a b)` fires only on `sub` rows holding an `add`, binding
`a` and `b` to its two children. Construction and destruction are the
same notation, told apart by which side of the arrow you're on.

```
$ racket slog.rkt --debug-dir out/expr expr.slog
$ cat out/expr/sub.csv
(add (num 1) (mul (num 2) (num 3)))
(num 1)
(mul (num 2) (num 3))
(num 2)
(num 3)
$ cat out/expr/hasmul.csv
1
```

Structured values print readably in CSVs, nesting and all.

## Computing over trees

Sizes, per subterm — note how the recursive cases *join on the
children's* already-computed sizes:

```
table (tsize expr int)

rule (sub (num k)) --> (tsize (num k) 1)
rule (sub (add a b)) (tsize a n) (tsize b m) (= s (+ 1 (+ n m)))
 --> (tsize (add a b) s)
rule (sub (mul a b)) (tsize a n) (tsize b m) (= s (+ 1 (+ n m)))
 --> (tsize (mul a b) s)
```

Leaves get size 1; a node's size appears once both children's sizes
have — the fixpoint takes care of the ordering, leaves upward, without
you scheduling anything.

## Stored once

One fact worth internalizing early: every distinct structured value is
stored **exactly once**, no matter how many rows mention it. Slog keeps
a single copy of `(mul (num 2) (num 3))` and every occurrence refers to
it. Consequences you get for free: comparing two trees for equality is
instant (they're equal if they're the *same* stored value), a value can
serve as a key column with no cost, and deeply shared structures — a
thousand rows all containing the same subtree — cost one subtree. The
technical name is *interning*; you mostly notice it as "big values are
cheap, use them freely."

## Cheat sheet

| Form | Example | Meaning |
|---|---|---|
| fixed shape | `struct (point int int)` | one constructor, typed fields |
| tagged choice | `union (expr (num int) (add expr expr))` | one of several constructors; recursive types allowed |
| named constants | `enum (color red green blue)` | `(red)` etc.; usable as a column type |
| nullary members | `union (stack (halt) (frame expr stack))` | a union arm with no fields is a constant |
| build | `--> (out (point 3 4))` | constructors in heads (body-less or not) create values |
| match | `rule (in (point x _)) --> ...` | constructors in bodies destructure; wildcards fine |
| nest | `(add (num 1) (num 2))` | values nest arbitrarily; each distinct value stored once |
