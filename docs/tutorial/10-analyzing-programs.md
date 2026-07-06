# 10. Analyzing programs

This chapter is the payoff. Everything you've learned — structured
values, demand, sets-as-relations — was quietly aimed at one of Slog's
main callings: **program analysis**, programs that read other programs
and prove things about them.

## Programs as data

An analyzer's input is a program, so first we need programs as values.
Chapter 4 already showed the move; here is the lambda calculus — the
minimal functional language — as a union:

```
union (expr (lambda str expr) (app expr expr) (ref str))
union (val lambda)
table (program expr)

facts (program (app (lambda "id" (ref "id")) (lambda "y" (ref "y"))))
```

Our test subject is `(λid. id)(λy. y)`: apply the identity function to
`λy. y`.

## An analyzer in six rules

The question a *control-flow analysis* answers: which functions can
show up where? Which values can `id` be bound to? What can the whole
program evaluate to? Here is a complete analyzer, written as a
demand-driven evaluator:

```
demand (eval expr) val
table (store str val)
table (result val)

facts (eval (lambda x eb) (lambda x eb))
rule (eval (ref x) v) <-- (store x v)
rule (eval (app ef ea) v) <-- (eval ef (lambda x eb)) (eval ea va) (eval eb v)
rule (eval (app ef ea)) (eval ef (lambda x eb)) (eval ea va) --> (store x va)

rule (program e) --> (eval e)
rule (program e) (eval e v) --> (result v)
```

Walk it slowly — every line uses something you know:

- A lambda evaluates to itself (a pattern-fact, answering any demanded
  lambda).
- A reference evaluates to whatever the store says its variable can
  hold.
- An application evaluates its function and argument, and once the
  callee is known, its body — the body's value is the application's
  value.
- The fourth rule flows argument values into the parameter's store
  entry, as soon as callee and argument are known.
- Demand the whole program; collect what comes back.

```
$ racket slog.rkt --debug-dir out/cfa cfa.slog
$ cat out/cfa/result.csv
(lambda "y" (ref "y"))
$ cat out/cfa/store.csv
"id"   (lambda "y" (ref "y"))
```

The program evaluates to `λy. y`, and the analysis also reports
everything `id` could ever be bound to — for free, in the `store`
relation.

## Why this terminates on programs that don't

Here's the quietly remarkable part. Feed this analyzer a program that
loops forever, like `(λx. x x)(λx. x x)`, and the *analysis*
terminates anyway. Two ingredients you already have conspire to
guarantee it:

- `store` is a relation, so a variable maps to a **set** of possible
  values — bindings accumulate rather than overwrite.
- `eval` is a demand over *subexpressions of the program*, and a finite
  program has finitely many subexpressions. Finitely many demands,
  finitely many answers: the fixpoint arrives.

You've built what the literature calls a monovariant control-flow
analysis (0CFA) — a sound over-approximation of everything the program
could do, computed by exhaustive honest bookkeeping. The
over-approximation is visible in the output: the store answers "what
*could* `id` be bound to", possibly a set, rather than simulating one
actual execution.

## Where to go from here

- The Readme's front-page example is the same analysis written as a
  small-step **abstract machine** — states and transitions as data —
  which is the shape the research literature calls an *abstracted
  abstract machine* (AAM). Both styles live in `examples/tinycfa/`,
  producing identical results.
- `examples/schemecfa/` scales the idea to a real slice of Scheme:
  a parametric context-sensitive analysis (m-CFA) with abstract
  counting, factored across files with `include`/`run` exactly as in
  chapter 9, plus a query layer over the results (call graphs, purity).
- The lattices of chapter 8 slot straight in: add a `(count)` measure
  to certify which variables are bound exactly once
  (`examples/tinycfa/0cfa-counting.slog`), or `(flat T)` values for
  constant propagation over your own IR.

## Cheat sheet

| Idea | Example | Meaning |
|---|---|---|
| programs as data | `union (expr (lambda str expr) ...)` | the subject language is a value type |
| the store | `table (store str val)` | variable ⟼ *set* of possible values; sets are what relations are |
| demand-driven eval | `demand (eval expr) val` | analyze only reachable subexpressions; memoized |
| asking is asserting | `rule (eval (app ef ea)) ... --> (store x va)` | a demand with no answer yet is still a fact rules can use |
| termination | — | finite subexpressions × accumulating sets ⇒ fixpoint |
| worked examples | `examples/tinycfa/`, `examples/schemecfa/` | machine-style and demand-style, small and scaled |
