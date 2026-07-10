# 6. Functions on demand

Rules run *forward*: from facts to consequences, everything derivable.
That's perfect for reachability and analysis, and exactly wrong for
functions. If you write forward rules for Fibonacci, you get... every
Fibonacci number, forever. What you want is `fib(10)` — and only what
that call needs.

The `demand` declaration gives you that.

## fib, directly

```
demand (fib int) int

rule (fib n n) <-- (< n 2)
rule (fib n (+ (fib (- n 1)) (fib (- n 2)))) <-- (< 1 n)

table (answer int)
rule (= r (fib 10)) --> (answer r)
```

Line by line:

- `demand (fib int) int` declares that `fib` relates one int **input**
  to int **answers** — and that it is computed *on demand*: nothing
  runs until someone asks.
- The two rules are written conclusion-first (`head <-- body`), which
  reads like the function definition it is: a demanded `(fib n)` with
  `n < 2` answers `n`; otherwise it answers `fib(n-1) + fib(n-2)`.
  Nested calls like `(fib (- n 1))` mean *the answer of that call* —
  exactly as `(+ ...)` means the sum. Direct, non-tail recursion.
- The last rule asks: `(= r (fib 10))` calls `fib` and binds the
  answer, the same calling shape the list library used.

```
$ racket slog.rkt --debug-dir out/fib fib.slog
$ cat out/fib/answer.csv
55
$ sort out/fib/fib_ans.csv | head -3
(fib 0)   0
(fib 1)   1
(fib 10)   55
```

That `fib_ans` output is the window into how this works: **a call is
itself a fact**. Asking for `(fib 10)` asserts the structured value
`(fib 10)`; rules fire on demands that exist; answers land in a
generated table keyed by the demand. Three consequences fall out with
no extra machinery:

- **Memoization for free.** Each distinct call is a distinct stored
  value, computed once. `fib` is automatically the fast tree-less fib.
- **Only what's needed.** Exactly the demands `(fib 0)`…`(fib 10)`
  exist — nothing you didn't ask for.
- **It's a relation, not a function.** A call may have one answer,
  several (nondeterminism is fine), or none — failure is silence, like
  `lst_member`. No exceptions, no error plumbing.

## Functions over structures

Demand + pattern matching is how the list library is written. Here is
list-sum, in full:

```
demand (sum list) int

rule (sum [] 0)
rule (sum [x xs ...] (+ (sum xs) x))
```

Two clauses: the sum of the empty list is 0; the sum of `[x xs ...]`
is `x` plus the sum of the rest. (Base cases with variables in them are
written as body-less rules — patterns to be answered when a matching
demand appears.) That's the entire implementation; memoization included.

## Passing functions around

Slog programs can contain `lambda` terms, which become ordinary values:

```
demand (map2 clo list) list
rule (map2 f [] [])
rule (map2 f [x xs ...] [(f x) (map2 f xs) ...])

table (out list)
rule (= r (map2 (lambda (n) (* n 10)) [1 2 3])) --> (out r)
```

`(f x)` — calling a value held in a variable — dispatches to whatever
closure `f` is. `out` gets `[10 20 30]`. Under the hood, lambdas are
just structured values and calling is just another demand; see
`tests/dem_lambda.slog` and `tests/dem_stlc.slog` (a type checker whose
rules are the textbook inference rules) for how far this goes.

## Cheat sheet

| Form | Example | Meaning |
|---|---|---|
| declare | `demand (fib int) int` | inputs, then answer type; computed only when asked |
| define | `rule (fib n (+ (fib (- n 1)) (fib (- n 2)))) <-- (< 1 n)` | conclusion-first reads like a definition; nested calls = their answers |
| base case | `rule (sum [] 0)` | body-less rules answer matching demands |
| call | `(= r (fib 10))` in any rule body | ask + bind the answer |
| multiple answers | — | a demand may answer zero, one, or many times; absence = failure |
| memoization | — | each distinct call computed once, automatically |
| lambdas | `(= r (map2 (lambda (n) (* n 10)) l))` | functions as values; variable-call `(f x)` dispatches |
| inspect | `out/<dir>/fib_ans.csv` | demands and answers are ordinary relations you can look at |
