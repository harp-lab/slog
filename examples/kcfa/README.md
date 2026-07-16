# kcfa — true k-CFA with higher-order environments

A demand-driven, big-step **k-CFA** over a small Scheme, built on the new
finite-map facility (`lib/map.slog`). Unlike the flat-environment m-CFA in
`examples/schemecfa`, this is Shivers' original **higher-order
environments**: a closure captures a whole environment map, and free
variables are resolved through it — there is no free-variable re-binding.

```
racket compiler/run.rkt --no-banner --debug-dir out/kcfa examples/kcfa/kcfa.slog
```

The context depth is a fact: edit `(klimit 1)` and rerun. `k = 0` is 0CFA;
each increment keeps one more call site in every environment address.

## The representation the task asked for

- **Contexts are lists** of the youngest `k` call sites (`tick` via
  `lst_take`), exactly as in the m-CFA.
- **Environments are finite maps** `Var → Ctx` (`pmap` from `lib/map.slog`):
  each variable is mapped to the context at which it was bound. A
  variable's *address* is that `(var, ctx)` pair; the store
  `(store var ctx val)` maps addresses to values.
- **Closures carry their environment**: `val = (closure lambda pmap)`.
  Applying a closure extends *its captured map* with the parameters at the
  new time (`extend_env`), then runs the body — the definition of
  higher-order environments.

Because finite-map keys must be non-negative ints, **variables are integer
labels** (the standard k-CFA formalization); each program has a legend in
its comment. Primitives are a distinct form (`primref`) so they never
occupy the variable space.

## Files

| file | contents |
|---|---|
| `syntax.slog` | the `expr` / `bool` unions (int-labelled variables) |
| `context.slog` | `klimit` + the `tick` demand function |
| `interp.slog` | the interpreter: `eval`, `lookup`, `eval_args`, `extend_env`, `delta` |
| `counting.slog` | frame/binding/flow counts, must-values, closure counts |
| `kcfa.slog` | `(klimit 1)` + five worked programs |

`interp.slog` needs no `freevars.slog` — that is the payoff of
higher-order environments over the flat-env m-CFA.

## What the worked programs show

- **P1** is the flagship: the K-combinator `λx.λy.x` applied to two
  distinct symbols yields two closures over the *same* inner lambda with
  *different captured environments* (visible in `eval_ans`), so `(eq? r1 r2)`
  is precisely `#f` at `k = 1`.
- **P2** is the precision knob: `(eq? (id "P") (id "Q"))` is `#f` at
  `k = 1` but blurs to `{#t, #f}` at `k = 0`.
- **P3** is `letrec` factorial — recursion resolved through the captured
  environment; the self-looping frame is `summarized_binding` while the
  first unwinding is `unique_binding`.
- **P4** is branch sensitivity (the dead branch is never demanded).
- **P5** is a two-parameter (k-ary) primitive wrapper.

## Client-queryable relations

`store`, `eval_ans`/`lookup_ans`, `frame_count`/`binding_count`,
`unique_binding`/`must_value`, `unique_closure`/`summarized_closure`,
`reachable_expr`. The counting layer reads only the call/binding events, so
it composes with higher-order environments unchanged.
