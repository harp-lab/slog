# Language reference

Slog source uses parenthesized expressions, but its evaluation model is not
Lisp's. A file declares types and relations, then gives rules that populate
those relations. The compiler type-checks the whole program, divides rules
into dependency strata, generates native code, and evaluates each stratum to a
fixpoint.

## Lexical form

Whitespace separates tokens. `;;` begins a comment that runs to the end of the
line.

Identifiers normally contain letters, digits, underscores, and apostrophes.
Identifiers are case sensitive. In rules, names such as `X`, `node`, and
`next_value` are variables; uppercase is only a convention.

Literals are:

```slog
42
-17
3.5
"a string\nwith an escape"
true
false
```

Integers are exact and grow to arbitrary precision within configured safety
caps. Floats are IEEE binary64. Strings are UTF-8 values; string indexes count
Unicode code points, not bytes. `true` and `false` are built-in constants.

## Tables and facts

A table declaration names a relation and gives one type per column:

```slog
table (edge str str)
table (weight str str int)
table (payload str any)
```

A relation is an unordered set of rows. Re-deriving the same row has no effect.
Tables and structs must have at least one column.

A body-less rule states facts:

```slog
rule
(edge "a" "b")
(edge "b" "c")
(weight "a" "b" 5)
```

A fact should be ground after its expressions are evaluated: it cannot leave
an unbound variable in a relation row.

## Rules

The usual rule form is:

```slog
rule body-clause ... --> head-clause ...
```

All body clauses must match for the heads to be derived:

```slog
rule (edge X Y) (edge Y Z) --> (two_hop X Z)
```

One rule may have several heads. They are derived from the same match:

```slog
rule (edge X Y) --> (node X) (node Y)
```

The arrow may point left when that reads more naturally:

```slog
rule (two_hop X Z) <-- (edge X Y) (edge Y Z)
```

This means the same thing as the right-pointing form.

`|` separates body alternatives. The common use is a compact pair of rules:

```slog
rule (child E X) <--
     (left_child E X) | (right_child E X)
```

Each alternative must still bind everything used by the head and by later
clauses.

## Variables, joins, and wildcards

Every repeated variable in one rule match has one value. That gives Slog's
basic join:

```slog
rule (uses Function Variable)
     (defined_at Variable Line)
  --> (use_site Function Variable Line)
```

Use `_` for a value that does not matter:

```slog
rule (weight X Y _) --> (edge X Y)
```

Each `_` is independent. Do not use `_` in a head; a head value must come from
the body or a computation.

Equality has two related jobs. It can bind a computed value:

```slog
rule (weight X Y W) (= W2 (* W 2)) --> (double_weight X Y W2)
```

It can also match or test a value:

```slog
rule (item X) (= X 0) --> (zero_item X)
rule (tree T) (= T (node L R)) --> (children L R)
```

`/=` requires two values to differ. `<`, `<=`, `>`, and `>=` are numeric body
guards. They do not produce values and belong in rule bodies.

## Expression evaluation

Built-in value operations appear as parenthesized calls:

```slog
(+ A B)
(substr Text Start End)
(lref Items Index)
```

They may be bound with equality or nested where a value is expected:

```slog
rule (pair A B) (= Sum (+ A B)) --> (sum Sum)
rule (pair A B) --> (sum (+ A B))
```

Some operations are partial. For example, `cget` has no result for a missing
key and `s2i` has no result for a malformed integer. A partial failure abandons
the current rule match; it is not a default value and not an `error` fact.

Invalid arithmetic or invalid dynamically typed data can instead produce a
built-in `(error E)` fact and abandon the deduction. See
[errors](#runtime-error-facts) and the [built-in reference](builtins.md).

## Structs, unions, and enums

A struct defines one constructor and one structured value type:

```slog
struct (point int int)
table (location str point)
rule (location "origin" (point 0 0))
```

A union defines a closed family of constructors:

```slog
union (expr (num int)
            (var str)
            (add expr expr)
            (ifzero expr expr expr))

table (program expr)
rule (program (add (num 1) (var "x")))
```

A constructor can name an existing struct, as `lambda` does in this example:

```slog
struct (lambda str expr)
union (value lambda (number int))
```

More often, declaring `(lambda str expr)` inside the union is enough.

Pattern matching uses the same constructor syntax as construction:

```slog
demand (free_var expr) str
rule (free_var (var X) X)
rule (free_var (add A B) X) <--
     (free_var A X) | (free_var B X)
```

An enum is a named group of nullary constructors:

```slog
enum (color red green blue)
table (paint str color)
rule (paint "door" (blue))
```

Nullary constructors still use parentheses. The internal `_enum` struct backs
enums, but user programs should work through the declared constructor names.

Declarations do not support extending a union from another file. Put all arms
of a union in one declaration.

## Types

The primitive user-facing types are:

| Type | Values |
|---|---|
| `int` | exact integers, including bignums |
| `float` | IEEE binary64 numbers |
| `str` | Unicode strings |
| `any` | any Slog word value; checked dynamically when an operation needs a narrower type |
| `list` | a sequence with elements of any type |
| `(list T)` | a sequence whose elements have type `T` |
| `[T]` | shorthand accepted in type position for `(list T)` |
| `cseq` | the native sequence representation; normally spell a column as `list` or `(list T)` |
| `cset` | a native set value |
| `cmap` | a native map value |
| `(map K V)` | a native map whose keys have type `K` and values have type `V` |
| `coll` | the shared supertype of `cset` and `cmap` |
| `clo` | a closure produced by `lambda`; mainly used in higher-order demand signatures |
| `error_spec` | the built-in union of recoverable runtime error values |

Struct, union, enum, demand, and lattice declarations add named types.

There is no separate `bool` column type. `true` and `false` are built-in
nullary values; use `any` when storing them directly, or declare an `enum` when
a field needs a named, statically checked choice type.

Types are checked across relation columns, constructors, and primitive calls.
`any` is an escape hatch for heterogeneous data, not a separate boxed object
type. An operation on an `any` value still checks its runtime tag.

Lists and collections have richer parameterized type roles in declarations
and lattice specifications. Their runtime values are still the canonical
`cseq`, `cset`, and `cmap` representations. See
[collections](collections.md).

## Lists

Square brackets construct a native sequence:

```slog
table (row (list int))
rule (row [])
rule (row [1 2 3])
```

An element followed by `...` splices a list:

```slog
rule (= A [1 2]) (= B [A ... 3 4]) --> (row B)
```

The same notation patterns on a list. `[Head Tail ...]` matches a nonempty
list. More general split patterns are supported:

```slog
rule (row [First Middle ... Last]) --> (ends First Last)
rule (row [_ ... 2 After ...]) --> (after_two After)
```

When several splice variables can take different lengths, Slog chooses its
defined deterministic split. Do not use an ambiguous split as a way to
enumerate every partition; it produces a match, not a relation of all splits.

The [collection guide](collections.md) describes the full pattern and
operation surface.

## Set and map literals

Brace literals construct native canonical collections when no compatibility
library has claimed their desugaring:

```slog
table (names cset)
table (ages cmap)

rule (names {"Ada" "Grace"})
rule (ages {"Ada":36 "Grace":85})
```

`X ...` inside braces extends a value, and `K:V` gives a map entry. For
unambiguous empty native collections, use `(cmap)`, then let the consuming
operation or column supply the set/map role.

Including `lib/set.slog` or `lib/map.slog` activates the older `pset` or `pmap`
literal expansion in that module. Do not mix those rule-based representations
with native collection operations. See [collections](collections.md).

## Demand declarations

A demand declares input types in parentheses and one or more answer types
afterward:

```slog
demand (lookup str int) any
demand (split int) int int
```

Each demand needs at least one input and one answer. Its ordinary relational
shape puts answers after inputs:

```slog
rule (lookup "x" 0 42)
rule (split N Q R) <-- (= Q (/ N 10)) (= R (% N 10))
```

A one-answer demand can be called in value position:

```slog
rule (= V (lookup "x" 0)) --> (result V)
```

The full-arity form works for one or many answers:

```slog
rule (split 47 Q R) --> (digits Q R)
```

Internally, demand `f` uses a structured request value `f` and an answer table
`f_ans`. The escape hatch `(f_ans (f inputs...) answers...)` can enumerate
answers that have already been asked for. It does not create a demand by
itself.

See [demand functions and lattices](functions-and-lattices.md) for recursion,
closures, multiple answers, and evaluation details.

## Lattice-valued relations

A lattice declaration names a value specification:

```slog
lattice (cost (min int #:floor 0))
table (distance str str cost)
```

The lattice column must be the last column of a table. Earlier columns form
the key. All proposals for one key are joined into one current value.

Supported value specifications are:

```slog
(min int)
(min float #:floor 0.0)
(max int)
(max float #:ceiling 100.0)
(count)
(flat T)
(set T)
(map K VALUESPEC)
```

Map value specifications can nest. Lattice values may only be read in ways
that are sound while they are still ascending. The compiler checks these uses
and moves unrestricted reads after the producing fixpoint when dependencies
permit it. A floor or ceiling may appear only on a top-level `min` or `max`,
not inside a `map` specification. See
[the full lattice guide](functions-and-lattices.md#lattices).

## Negation and strata

A negated relation clause begins with `~`:

```slog
rule (node X) ~(has_parent X) --> (root X)
```

All variables in the negated clause must already be bound. The test succeeds
only if no row matches.

Negation is stratified. If `root` depends negatively on `has_parent`, Slog
finishes the stratum that can produce `has_parent` before running `root`.
Cycles through a negative edge are rejected. This prevents a fact from being
derived only because another fact has not appeared yet.

Lattice closure can create similar stratum boundaries. A rule may safely
propagate an ascending value during recursion, but an operation such as set
size or arbitrary equality usually waits until the lattice is closed.

## Files, `include`, and `run`

Place `include` and `run` forms at the beginning of a file.

```slog
include "types.slog"
include "list.slog"
run "base-analysis.slog"
```

`include` combines the target with the current module. Relative paths resolve
from the including file; if no file is found there, the loader also tries the
repository `lib/` directory. A missing include currently warns and is ignored,
so treat warnings as errors in automated work.

`run` executes another program to fixpoint as a prerequisite and threads its
manifest and relations into the current program. Its path is relative to the
current file. Run cycles are rejected.

Use `include` for declarations and rules that are part of one compilation.
Use `run` to create an explicit settled stage. Saved databases give a third,
persistent boundary; see [persistent databases](databases.md).

The parser contains some experimental forms from earlier designs. `import`,
`export`, and general `def` forms are not part of the supported user language
and should not be used.

## Runtime error facts

Recoverable failures in an otherwise well-typed primitive deduction are
represented as facts in the built-in relation:

```slog
table (caught str)
rule (error E) --> (caught (i2s 1))
```

Usually you pattern-match the error arm instead:

```slog
table (bad_division any)
rule (error (div_by_zero Location Numerator))
  --> (bad_division Numerator)
```

The built-in error variants are:

- `malformed_deduction`
- `div_by_zero`
- `modulo_by_zero`
- `int_overflow`
- `nan_result`
- `toint_range`
- `type_mismatch`
- `mpz_overflow`
- `mpz_table_overflow`
- `smt_bad_formula`

An error fact is added in place of the failed deduction and participates in
the same fixpoint, so other rules can react to it. A partial operation's
ordinary absence is different: it simply fails the rule match and produces no
error.

Some compiler errors and low-level invariant failures still stop the run.
Check the [built-in reference](builtins.md#errors-and-partial-operations) for
the exact error shapes.

## Names reserved by the system

Do not declare relations or constructors named `list`, `cons`, `nil`, `cset`,
`cmap`, `coll`, or `cseq`. The error relation, its variant names, the internal
`_enum` backing struct, and names beginning with internal `$seq_` prefixes are
also reserved.

Primitive operation names and comparison operators have their built-in
meaning in expression or guard position. The complete inventory is in
[built-in operations](builtins.md).
