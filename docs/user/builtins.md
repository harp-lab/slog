# Built-in operations

This page lists the complete public primitive surface defined by the compiler.
It also records the comparison clauses, built-in constants and types, partial
operations, and runtime error relations that are easy to miss when reading
only examples.

Primitive calls produce values:

```slog
rule (input X) (= Y (abs X)) --> (output Y)
```

`<`, `<=`, `>`, `>=`, and `/=` are body guards rather than value-producing
calls. Equality is the special matching and binding form.

## Numeric behavior

Slog integers are mathematical integers, not fixed-width Java `int` values.
Small integers use a compact representation; larger results use GMP bignums.
They do not wrap. Per-value and total bignum limits protect the process from
accidental growth.

When both arithmetic operands are integers, the result stays exact and
integer-valued. The runtime promotes a mixed integer/float pair to binary64,
and a large integer may round during that conversion. The static type checker
currently requires two operands whose known types agree, so write
`(+ (tofloat I) F)` when one side is statically `int` and the other is
`float`. Mixed values arriving through `any` still use the runtime promotion.
Numeric comparisons between an integer and a float use an exact GMP-to-double
comparison path rather than first rounding the integer.

NaN cannot be represented in Slog's value encoding. A floating operation that
would produce NaN emits a `nan_result` error fact instead. Positive and
negative infinity are representable floats, although `toint` rejects them.

## Arithmetic

| Operation | Accepted arguments | Result and notes |
|---|---|---|
| `(+ A B)` | two numbers, or two strings | numeric addition; string concatenation for two `str` values |
| `(- A B)` | two numbers | subtraction |
| `(* A B)` | two numbers | multiplication |
| `(/ A B)` | two numbers | integer division truncates toward zero; float division follows binary64 |
| `(% A B)` | two numbers | integer remainder has the dividend's sign; float uses `fmod` |
| `(neg A)` | number | arithmetic negation |
| `(abs A)` | number | absolute value |
| `(min A B)` | two numbers | smaller value; promotes mixed operands to float |
| `(max A B)` | two numbers | larger value; promotes mixed operands to float |
| `(pow A B)` | two numbers | exact integer power for two integers; floating power otherwise |

Integer `pow` returns `0` for a negative exponent. `0^0` returns `1`. A result
that would exceed the bignum cap produces `mpz_overflow`.

Integer division or remainder by zero produces `div_by_zero` or
`modulo_by_zero`. Floating division by zero follows binary64: for example a
nonzero finite number divided by `0.0` is an infinity, while `0.0 / 0.0`
produces a `nan_result` fact.

## Integer bit operations

| Operation | Meaning |
|---|---|
| `(band A B)` | bitwise and |
| `(bor A B)` | bitwise or |
| `(bxor A B)` | bitwise exclusive or |
| `(bnot A)` | bitwise complement, equivalent to `-A-1` |
| `(shl A N)` | exact left shift, `A * 2^N` |
| `(shr A N)` | arithmetic right shift, `floor(A / 2^N)` |

All arguments must be integers. Operations extend to bignums with GMP's
infinite two's-complement semantics. Shift counts must be nonnegative. A very
large left shift can produce `mpz_overflow`; a very large right shift settles
at `0` for nonnegative inputs or `-1` for negative inputs.

## Floating math

| Operation | Meaning |
|---|---|
| `(sqrt X)` | square root |
| `(sin X)` | sine, radians |
| `(cos X)` | cosine, radians |
| `(tan X)` | tangent, radians |
| `(exp X)` | base-e exponential |
| `(log X)` | natural logarithm |
| `(floor X)` | greatest integral float not above `X` |
| `(ceil X)` | least integral float not below `X` |
| `(round X)` | nearest integral float, halfway cases away from zero |

Each accepts an integer or float and returns a float. A result that is NaN
produces `nan_result`.

## Numeric conversions

| Operation | Meaning |
|---|---|
| `(tofloat X)` | convert a number to float; identity on floats, possibly rounds a bignum |
| `(toint X)` | convert a number to integer; identity on integers, truncates a finite float toward zero |

`toint` can produce a bignum. It emits `toint_range` only for a non-finite
float.

## Comparisons, equality, and truth tests

The numeric body guards are:

```slog
(< A B)
(<= A B)
(> A B)
(>= A B)
```

They accept integers and floats, including mixed pairs. A false comparison
fails the current rule match. These forms do not return `1` or `0` at the
language level.

`(= A B)` unifies, binds, destructures, or tests depending on which values are
known. It is also the normal way to bind a primitive result:

```slog
(= Total (+ A B))
(= Tree (node Left Right))
```

`(/= A B)` succeeds when two already determined values differ. Equality of
structured and collection values is content equality; canonical interning
makes the runtime comparison constant time after construction.

Many membership operations return integer `1` or `0`. Test them explicitly:

```slog
table (items cset)
table (ready int)
rule (items S) (= 1 (cmem S "ready")) --> (ready 1)
```

There is no general Boolean coercion of arbitrary values.

## Strings

String positions and lengths count Unicode code points. Strings may be stored
as one small value or as a rope; the representation does not change the
surface behavior.

| Operation | Result |
|---|---|
| `(size S)` | code-point count of a string; also accepts a list and returns its element count |
| `(substr S I J)` | code points in half-open range `[I, J)`; both bounds clamp to the string |
| `(sidx S Needle)` | code-point position of the first occurrence; partial if absent |
| `(shas S Needle)` | `1` if `Needle` occurs in `S`, else `0` |
| `(schar S I)` | the code point at `I` as a one-character string; partial out of range |
| `(ssplit S Sep)` | a list of strings split at `Sep` |
| `(sjoin Parts Sep)` | join a list of strings with `Sep` between them |
| `(s2i S)` | strict decimal integer parse; partial on malformed input |
| `(s2f S)` | strict full-string float parse; partial on malformed input or NaN |
| `(i2s I)` | exact decimal rendering of an integer |
| `(f2s F)` | shortest round-trippable float rendering, with `.0` on integral floats |

`substr`'s third argument is an end index, not a length. Negative bounds clamp
to zero. If the end is before the start, the result is empty.

An empty separator makes `ssplit` return one string per code point. Adjacent or
edge separators produce empty pieces. `s2i` accepts an optional leading minus
and decimal digits only: no whitespace, plus sign, or base prefix.

## Native maps and sets

Native maps and sets share one canonical collection representation. Static
types distinguish their intended operations.

| Operation | Result |
|---|---|
| `(cmap)` | empty collection seed |
| `(cput M K V)` | map `M` with `K` mapped to `V`, replacing any old value |
| `(cget M K)` | value at `K`; partial if absent |
| `(chas M K)` | `1` if `M` contains key `K`, else `0` |
| `(cmerge A B)` | left-biased union; an entry from `A` wins on a key collision |
| `(cjoin A B)` | pointwise lattice join for maps or sets whose lattice value specification is known |
| `(cdel C K)` | collection without key or element `K` |
| `(cdiff A B)` | entries of `A` whose keys do not occur in `B` |
| `(csize C)` | number of entries or elements |
| `(cins S X)` | set `S` with element `X` |
| `(cmem S X)` | `1` if set `S` contains `X`, else `0` |

`cjoin` is not a general map merge. The compiler must know the enclosing
`(set T)` or `(map K VALUESPEC)` lattice specification so it can join values
correctly. Use `cmerge` for ordinary left-biased map union.

Collection operations are explained with literals and examples in
[lists, sets, and maps](collections.md).

## Native lists

`cseq` is the native immutable sequence representation used by `list`,
`(list T)`, and bracket literals.

| Operation | Result |
|---|---|
| `(lempty)` | empty list |
| `(lpush L X)` | append `X` to the end of `L` |
| `(aslst X)` | `X` viewed as a list; partial when it is not a list |
| `(llen L)` | element count |
| `(lref L I)` | element at zero-based index `I`; partial out of range |
| `(lset L I X)` | copy with position `I` replaced; partial out of range |
| `(lins L I X)` | copy with `X` inserted at `I`; valid for `0` through `llen` |
| `(ldel L I)` | copy without position `I`; partial out of range |
| `(lcat A B)` | concatenation |
| `(lslice L I J)` | half-open slice `[I, J)` with both bounds clamped |
| `(lrev L)` | reversal |
| `(lidx L X)` | first index of `X`; partial if absent |
| `(lmem L X)` | `1` if `X` occurs, else `0` |
| `(lsort L)` | list in ascending raw Slog-word order |
| `(lst2set L)` | native set of the elements in `L` |
| `(set2lst S)` | elements of `S` in canonical raw-word order |
| `(ckeys M)` | map keys in canonical raw-word order |
| `(cvals M)` | map values ordered by their corresponding keys |

Despite its name, `lpush` appends. `lins` accepts `I == llen L`; `lref`,
`lset`, and `ldel` do not.

The order used by `lsort`, `set2lst`, and `ckeys` is deterministic, but it is
the unsigned encoded-word order. It is not numeric, lexicographic, or
constructor order and should not be given semantic meaning. `cvals` follows
that key order.

## Lattice constants and transfers

| Operation | Meaning |
|---|---|
| `(one)` | the `1` value of the count lattice |
| `(inf)` | the saturated “two or more” value of the count lattice |
| `(cplus A B)` | count addition: `one + one` and any sum involving `inf` become `inf` |
| `(top)` | conflict value of a flat lattice |

Count lattice values are not ordinary integers even though output may look
numeric. Use `one`, `inf`, and `cplus`, not integer arithmetic. `top` is useful
inside a `(flat T)` lattice and is restricted by the lattice soundness checker.

## Partial operations

The complete partial set is:

```text
cget  aslst  lref  lset  lins  ldel  lidx
sidx  schar  s2i   s2f
```

A normal partial miss abandons only the current rule match. It produces no
value and no error fact:

```slog
table (text str)
table (parsed int)
rule (text S) (= N (s2i S)) --> (parsed N)
```

Rows of `text` that are not strict integers simply produce no `parsed` row.
When you need an explicit yes/no result, prefer the total companion where one
exists: `chas`, `cmem`, `lmem`, or `shas`.

Partiality covers expected absence, not a value with the wrong runtime type.
Some modern arithmetic and conversion paths turn dynamic type mismatches into
`error` facts. Several low-level collection and sequence dispatchers still
treat a wrong runtime tag as a fatal contract violation. Keep precise column
types when using them.

## Errors and partial operations

The built-in relation has one `any` column:

```text
error : any
```

Its values are members of the built-in `error_spec` union. Exact shapes are:

```slog
(malformed_deduction Location Relation Column BadValue)
(div_by_zero Location Numerator)
(modulo_by_zero Location Numerator)
(int_overflow Location Left Right)
(nan_result Location Operation Operand)
(toint_range Location Value)
(type_mismatch Location Operation Left Right)
(mpz_overflow Location Operation Left Right)
(mpz_table_overflow Location Operation)
(smt_bad_formula Reason Formula)
```

`Location` is usually a stable `filename:line` string. The operation name is a
string. Unary operations use a placeholder in their internal second operand;
the public error arm keeps the shape shown above.

`malformed_deduction` means a value accepted through `any` or overlapping
union types did not fit a concrete head column at runtime. `mpz_overflow`
means one result exceeded `SLOG_MPZ_MAX_BITS`; `mpz_table_overflow` means the
whole bignum table exceeded `SLOG_MPZ_TABLE_BYTES`. `int_overflow` remains a
reserved compatibility arm, but ordinary integer arithmetic now grows into
bignums rather than overflowing a fixed machine integer.

The normal command-line driver warns when new error facts appear and continues
the fixpoint. Rules may match `(error E)` and respond in the language. Internal
invariant failures, corrupt database data, and some low-level dynamic type
mistakes still stop the daemon.

## Built-in values, types, and system relations

Built-in literal or nullary values are:

- `true` and `false`
- `(one)` and `(inf)` for count lattices
- `(top)` for flat lattices
- `(cmap)` and `(lempty)` for empty native collections and lists

User-facing built-in types are `int`, `float`, `str`, `any`, `list`,
`(list T)`, `cseq`, `cset`, `cmap`, `(map K V)`, `coll`, `clo`, and
`error_spec`. Each built-in error constructor also names one arm type of
`error_spec`. The runtime has internal backing types for enum values and the
count lattice; user code normally reaches them through declared enums,
`true`/`false`, or a `(count)` lattice. There is no separate `bool` type. See
the [language type table](language.md#types).

The daemon also publishes diagnostic CSV relations when statistics are
enabled:

| Relation | Columns |
|---|---|
| `$stat_fires` | rule location, generated variant, firing count |
| `$stat_fixpoint` | SCC number, stratum name, iteration count, microseconds |
| `$stat_size` | relation name, tuple count at CSV dump |

These are daemon-owned. Slog source cannot declare or join them, and binary
database saves exclude them. They appear under `--debug-dir` and are available
to low-level lookup actions. Set `SLOG_NO_STATS=1` to suppress publication.

## Complete primitive name checklist

For audits and extension work, these are all value-producing primitive names
in `compiler/primitives.rkt`:

```text
+ - * / % neg abs min max pow
band bor bxor bnot shl shr
sqrt sin cos tan exp log floor ceil round
tofloat toint
size substr sidx shas schar ssplit sjoin s2i s2f i2s f2s
cmap cput cget chas cmerge cjoin cdel cdiff csize cins cmem
lempty lpush aslst llen lref lset lins ldel lcat lslice lrev lidx lmem
lsort lst2set set2lst ckeys cvals
one inf cplus top
```

Body-only built-ins add `=`, `/=`, `<`, `<=`, `>`, and `>=`.
