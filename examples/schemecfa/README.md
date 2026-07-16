# schemecfa — parametric m-CFA with abstract counting for a small Scheme

A demand-driven, big-step m-CFA over a nine-form Scheme subset, with
Might–Shivers abstract counting layered on top. The context depth is a
plain fact: edit `(mlimit m)` in `schemecfa.slog` and rerun — `m = 0` is
0CFA, each increment buys one more frame of call history.

```
racket compiler/run.rkt --no-banner --debug-dir out/schemecfa examples/schemecfa/schemecfa.slog
```

## The language

`num`, `boolean` (`true`/`false`), `sym`, `ref`, `lambda` (list of
params), `app` (operator + list of argument exprs, so k-ary calls),
`if`, `let`, `letrec`, and a handful of primitives (`+ - * < <= = eq?
not`). No `cons` yet. Binder names must be globally distinct — the AST
is interned, so a shared subterm would stand for two evaluation events
and skew the counts.

## The files

| file | contents |
|---|---|
| `syntax.slog` | the `expr` union and the `bool` union |
| `freevars.slog` | free variables of every subterm (drives m-CFA re-binding) |
| `context.slog` | `mlimit` and the `tick` demand function that advances a context |
| `interp.slog` | the abstract interpreter: `eval`, `lookup`, `eval_args`, `delta` |
| `counting.slog` | frame/binding counts, must-values, unique/summarized closures |
| `schemecfa.slog` | `(mlimit 2)` + six worked test programs |

`interp.slog`, `freevars.slog`, and `context.slog` are the reusable
core; a client analysis includes `counting.slog` (or just `interp.slog`)
and reads the relations below.

## What a client can query

- `eval_ans (eval e c) v` — the value(s) of expression `e` in context `c`.
- `lookup_ans (lookup x c) v` — what variable `x` holds in frame `c`.
- `binding x c v` — the store, as a plain relation.
- `frame_count c k` / `binding_count x c k` — how many concrete frames a
  context, or concrete bindings an address, stands for (`one`/`inf`).
- `unique_binding x c` — exactly one concrete binding ever (licenses
  must-alias / strong update); `must_value x c v` — that binding's value
  is known exactly.
- `unique_closure v` / `summarized_closure v` — whether an abstract
  closure denotes one concrete object or many.
- `reachable_expr e` — the demanded (flow-reachable) subexpressions;
  `if` only demands the branch its test selects.

See the comments in `schemecfa.slog` for what each test program is
meant to exhibit and how `m` changes the answer (P4 is the clean
knob-turning demo: precise at `m = 2`, blurred at `m ≤ 1`).
