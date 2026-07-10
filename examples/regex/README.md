# Regex matching by partial derivatives

A regular-expression engine in ~20 clauses — matcher *and* automaton —
built on Antimirov's partial derivatives. The derivative of a regex by a
character is "what remains to be matched"; Antimirov's version returns a
*set* of residuals, which keeps the state space finite with no
canonicalization. The example's point is that in Slog those sets never
get built: a demand relation already *is* a set of answers.

| Antimirov's construction | in Slog |
|---|---|
| set union `∂(r) ∪ ∂(s)` | two clauses answering the same call |
| the empty set `∂_c(c′) = {}` | a clause that doesn't match — silence |
| "for each residual…" | asking |
| dedup / canonical terms | hash-consing (equal regexes are one value) |
| the memo/transition table | the demand relation itself, in `deriv_ans.csv` |

## Running

```
racket slog.rkt --no-banner --debug-dir out/regex examples/regex/antimirov.slog
```

- `match.csv` — which subjects each named regex accepts.
- `nfa.csv` / `state.csv` / `accepting.csv` — the automaton, from three
  rules that iterate `deriv` over the alphabet. States are regexes, so the
  transition table is *readable*: each state says what remains to match.
  For `(a|b)*abb` note the start state's two `"a"` rows — nondeterminism
  is just two answers — one of which loops back to the start state
  *itself*, because interning collapsed the residual with the original.
- `run_ans.csv` — the matcher's memo table: NFA simulation keyed by
  (state, entire remaining input). Keying on whole suffixes is free
  because sequences are canonical interned values. `"aababb"` appears
  with both a `0` and a `1` answer — two speculative paths, one dead,
  one accepting; `match` just asks whether *some* answer is `1`.

## Where it could go

This is the core of a lexer generator (tag the accepting states), of
regex *equivalence* checking (derive two regexes in lockstep and compare
nullability — bisimulation over interned states), and of the lazy-DFA
trick grep/RE2 use at runtime: build only the states the input actually
reaches. That last one isn't an extension — it's what `demand` already
did here.

The example is a golden test: `tests/run-tests.sh examples/regex/antimirov.slog`.
