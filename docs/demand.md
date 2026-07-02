# Demand-moded relations (design notes)

Status: design sketch, not implemented. 2026-07.

Origin: revisiting the `!`/`?` clause annotations from the Slog paper
(*Higher-Order, Data-Parallel Structured Deduction*, arXiv:2211.11573)
against the current compiler, and asking what the modern replacement
should look like. The follow-up paper (*Datalog with First-Class Facts*,
arXiv:2411.14330) dropped `!`/`?` and kept only fact identity (∃!-Skolem)
and subfact closure — evidence the durable core was the semantics, and
the sigils were separable surface.

## 1. Background: what `!` and `?` did

In the 2022 paper, `?` and `!` were per-occurrence *polarity flips* over
subfact-closed terms:

- `?(f args)` in head position: "this looks like a head clause but is a
  body clause" — a premise written inline in the conclusion.
  `(free ?(ref x) x)` desugared to `[(= e-id (ref x)) --> (free e-id x)]`.
- `!(f args)` in body position: "this will be deduced as the rule
  evaluates" — a conclusion written inline in a premise. The rule splits:
  a subrule derives the `!`-fact from the body clauses it depends on,
  emits a *midpoint* fact carrying live variables, and a second rule
  joins the midpoint against the eventually-derived result. Multiple
  independent `!`s emit in parallel, nonblocking.

Together they encode demand-driven evaluation: `!` is a call (demand
assertion + suspension), `?` is a definition head (demand match), the
midpoint relation is a defunctionalized continuation. This is what let
the paper write big-step interpreters and STLC/LF checkers — direct
(non-tail) recursion, promoted to relations.

The critique: `!`/`?` encode a *global* protocol (demand → suspend →
resume) with *local* sigils. The reader reconstructs split points by
dataflow analysis; the writer can misplace markers; `!`'s meaning depends
on the polarity of its enclosing clause; midpoint relations leak into the
model unnamed. It is the assembly language of demand, exposed as surface
syntax.

## 2. Where the current compiler stands

No trace of either marker survives (the only `?` left is a vestigial
`(bin "?")` in the Tinkr precedence table, consumed by no pass). Nested
terms desugar with *fixed* polarity: `simplification.rkt` flattens every
nested clause to `(= id (name ...))` and position alone decides
construct-vs-match.

But the substrate is unusually ready:

1. **Structs are already demand tokens.** A struct declaration yields a
   relation of all constructed instances, content-interned with identity.
   The paper's `?(ck Γ e)` is, in today's slog, just the body pattern
   `(ck Γ e)` — matching a demand struct someone constructed. The `?`
   half already fell out of the design.
2. **`stage-rule` is already the continuation transform**
   (`join-planning.rkt`): residual heads split into a follow-up rule, a
   temp carries live variables, the follow-up is driven by the temp's
   delta. It currently only waits for *interning* of ids the rule itself
   constructs — never for facts derived later — but it is the same shape,
   and its replay/carried-variable computation is exactly the
   continuation-environment computation this feature needs.
3. **The manual encoding already runs.** `examples/tinycfa/0cfa.slog` is
   a hand-defunctionalized interpreter: `(eval ef (ar ea k))` constructs
   continuation structs, apply-rules dispatch on them. That is precisely
   the code this desugaring would generate — proof the target encoding
   works, and a measure of the boilerplate to remove.

Consequence: the whole feature is a **front-end desugaring to plain slog**.
No new IR, no new runtime, no backend changes required for an MVP.

## 3. Proposal: relation-level demand declarations

Demand-drivenness is a property of a *relation*, not of an occurrence. A
judgment like `ck` or a function-like relation like `parse` is always
demanded on its inputs; per-occurrence mixing is the rare case, not the
default. So declare the mode once:

```
demand (parse sym int) int
```

Read: "`parse` is computed on demand; a demand is the interned struct
`(parse sym int)`; each demand relates to zero or more `int` answers."
Rules are then written as plain logic, sigil-free — conclusion `<--`
premises reads as the inference rule it is:

```
rule (ck Γ (lam x T1 e) (arrow T1 T2))
 <--
     (ck (ext Γ x T1) e T2)
```

That is T-Abs, verbatim. The compiler, knowing `ck`'s mode, supplies the
choreography (see §5).

### Not functions — relations

These are deliberately **not** functions. A demand may have zero answers
(failure is just absence — no error machinery), one, or many
(nondeterminism: ambiguous parses, abstract values, multiple typings).
"fun" is a misnomer; these are relations between a demand struct (the
call/question) and answer tuples. That framing also settles multiple
return positions:

```
demand (f w x) y z        ;; answers are (y, z) pairs
demand (reach g v)        ;; zero answer columns: "holds" / checked
```

Zero-answer judgments are checking judgments — the answer relation
degenerates to "this demand is satisfied," useful for type *checking*
(as opposed to inference) and reachability-style properties.

### Backing relations

`demand (ck env expr) type` generates exactly two ordinary relations:

- **`ck`** — the demand struct itself, `struct (ck env expr)`. There is
  no separate `ck-call`: *asking is constructing*. The struct's interned
  extent IS the call set. Seeding a computation is just a fact:
  `facts (ck Γ0 e0)`.
- **`ck-ans`** — the answer table, `table (ck-ans ck type)`: first column
  is the demand (i.e. its interned id, since struct values are their
  ids), remaining columns are the answers.

Both are nameable by the user — that is the escape hatch, replacing
per-occurrence sigils. Arity disambiguates naturally:

- `(ck Γ e T)` (full arity) — the judgment, transformed per §5.
- `(ck Γ e)` in a head — a bare ask, fire-and-forget.
- `(ck Γ e)` in a body — "is demanded," metalevel enumeration of calls.
- `(ck-ans d T)` — direct access to answers by demand id.

### Why not a polymorphic `ret`

A single generic `(ret d v)` over all demand types is tempting (one
relation, generic meta-rules) but wrong for this system: answer arities
differ per judgment; column types differ; storage layout, index
selection, and DRed^c counting all want locality. Per-judgment `-ans`
tables keep every one of those concerns local and typed. The one use
case that seems to need generic `ret` — "apply any closure" — is handled
by defunctionalization *into a single apply judgment per arrow type*
(§6): the union column absorbs the polymorphism, not the answer table.
If parametric judgments arrive later, monomorphize them to per-instance
tables at stratum-compile time, consistent with the type-system
direction.

### Value-position sugar (restricted)

Nested-call notation — writing `(parse T j1)` in an argument position to
mean "an answer of it" — is sugar available **only for single-answer
judgments**. Multi-answer judgments have no single value to substitute;
they must appear as explicit clauses. Note that nondeterminism itself is
fine in value position (the enclosing rule instantiates once per answer);
only answer arity ≠ 1 is excluded. Keep the core n-ary and relational;
add the sugar later if wanted.

## 4. Keyword bikeshed

| keyword | verdict |
|---|---|
| `fun` | misnomer — nondeterministic, multi-answer, partial |
| `rel` | too generic; everything is a relation, the keyword should name the *mode* |
| `query` | decent, but reserve for REPL/external one-shot queries |
| `judgment` | lovely for ND rules, wrong flavor for `parse`/`map`, long |
| `goal` | Prolog baggage; implies backward chaining only |
| `ask` | great verb; better as (optional) seeding sugar than as the declaration |
| `->` inside `table` decl | no new keyword, but modes deserve a headline form |
| `demand` | **recommended** — mechanism-honest, literature-anchored (demand transformation / magic sets), and the noun works everywhere: *a demand*, *the demand struct*, *demanded columns* |

## 5. The desugaring

For a rule over demand-moded `f` with demand columns x̄ and answer
columns ȳ:

- **Head occurrence** `(f x̄ ȳ)`: move the demand pattern to the body as
  a struct match — `(= d (f x̄))` — and make the head `(f-ans d ȳ)`. The
  rule fires only for demanded x̄ (the old `?`), and the demand match
  grounds x̄ for the body.
- **Body occurrence** `(f x̄' ȳ')` with x̄' ground (from the head's
  demand match and/or earlier clauses): split —
  1. an **ask** rule constructing the demand `(f x̄')` in its head
     (the old `!`), fired as soon as x̄' is ground;
  2. a **resume** rule joining `(f-ans (f x̄') ȳ')` to continue.
- **Mode check**: a body occurrence whose demand columns cannot be
  grounded is an error ("unmoded use of demanded relation f; name
  `f`/`f-ans` directly if enumeration is intended").

Chained asks order themselves by variable dependence (an ask whose
inputs need an earlier answer waits for it); independent asks fire in
parallel — the paper's nonblocking-`!` property, recovered with zero
sigils, as a scheduling fact rather than a syntax fact.

**Continuations as interned structs, not temps.** When the resume rule's
live variables are recoverable *by content* from the demand structs
themselves, no continuation is needed at all — the resume rule simply
re-matches the structs (content interning makes reconstruction a lookup
of the same id). When live variables are not recoverable, materialize a
continuation struct `(kN v ...)` carrying them — an ordinary interned
struct, not a stratum-local temp. Reasons:

- temps are index-free and delta-drive their follow-up alone; a resume
  must be driven by *both* the continuation's delta and the answer's
  delta (the answer may arrive many iterations later). Ordinary structs
  get multi-driver semi-naive versions from the existing planner for free.
- continuations become first-class facts: pending computation is
  queryable, has provenance, and DRed^c counting applies to suspended
  work uniformly (deleting an input retracts in-flight computations
  correctly).
- it is ideologically consistent: the defunctionalized continuation is
  itself a fact, in the spirit of the language.

Example. Given `demand (parse sym int) int`, the rule

```
rule (parse E i j) <-- (parse T i j)
```

desugars to plain current-slog:

```
;; ask: when (parse E i) is demanded, demand (parse T i)
rule (parse E i)
 -->
     (parse T i)

;; resume: forward T's answer as E's answer
rule (parse E i)
     (parse-ans (parse T i) j)
 -->
     (parse-ans (parse E i) j)
```

Both rules are legal today (nested struct match in body = content
lookup; nested struct in head = construction). No continuation struct is
needed because `i` is content-recoverable. `stage-rule`'s existing
carried-variable logic decides exactly when one is.

## 6. Lambdas and defunctionalization

First-class functions come out as sugar over the same mechanism, with no
new semantics:

- each `lambda` site defunctionalizes to a fresh closure struct capturing
  its free variables;
- all closures of a given arrow type join a union;
- one `apply` judgment per arrow type dispatches on the closure tag.

```
union (clo (addk int) ...)          ;; grows per lambda site
demand (apply clo int) int
rule (apply (addk k) n r) <-- (let r (+ n k))
```

The head `(apply (addk k) n r)` is a head occurrence: its demand pattern
`(apply (addk k) n)` destructures the closure (subfact closure at work),
`r` is the answer. Higher-order code is then ordinary rules:

```
struct (nil)
struct (cons int list)
union (list nil cons)

demand (map clo list) list
rule (map f (nil) (nil))
rule (map f (cons x xs) (cons y ys))
 <--
     (apply f x y)
     (map f xs ys)
```

The recursive case demand-matches `(map f (cons x xs))` — grounding `f`,
`x`, `xs` — fires *both* asks in parallel (their inputs are independent),
and the resume joins both answers and constructs `(cons y ys)`, which
itself flows through the existing head-staging/interning machinery.
Non-tail recursion, higher-order, parallel subcalls: no sigils, and
`0cfa.slog`'s hand-written `ar`/`fn` continuation structs are exactly
what this generates. Collapse the closure structs to finite abstractions
and the same rules *are* a CFA — nondeterministic answers become flow
sets, which is precisely why these must be relations, not functions.

## 7. Worked example: a grammar is a parser (Earley for free)

The crispest demonstration of the transform's power. Write a grammar as
naive recursive-descent-style rules; the demand transform yields Earley's
algorithm; interning yields packrat memoization and shared parse forests;
DRed^c (when it lands) yields incremental reparsing. All from ~six rules.

```
enum (sym E T F)
table (tok int str)              ;; input: token at position i
demand (parse sym int) int       ;; demand: parse sym at i; answers: end positions

;; E → E + T | T        (left recursion is fine — it's a fixpoint)
rule (parse E i k) <-- (parse E i j) (tok j "+") (let j1 (+ j 1)) (parse T j1 k)
rule (parse E i j) <-- (parse T i j)

;; T → T * F | F
rule (parse T i k) <-- (parse T i j) (tok j "*") (let j1 (+ j 1)) (parse F j1 k)
rule (parse T i j) <-- (parse F i j)

;; F → num | ( E )
rule (parse F i j) <-- (tok i n) (num n) (let j (+ i 1))
rule (parse F i k) <-- (tok i "(") (let i1 (+ i 1)) (parse E i1 j) (tok j ")") (let k (+ j 1))

facts (parse E 0)                ;; seed: constructing the demand struct IS asking
rule (parse E 0 n) (input-len n) --> (accepted n)
```

What the transform produces, and what it *is*:

- Asserting `(parse E 0)` triggers the head-occurrence matches for `E`
  rules, whose ask rules assert `(parse T 0)`, then `(parse F 0)` — this
  cascade is exactly Earley **prediction**.
- `tok` joins are **scanning**.
- `parse-ans` facts flowing back through resume rules are **completion**.
- The continuation structs (where needed) correspond to **dotted items**:
  a suspension sitting after `(parse E i j)` waiting at `"+"` is the item
  `E → E · + T` with origin `i`.
- Left recursion, fatal to recursive descent, is just a fixpoint here:
  the demand `(parse E i)` exists once (interned), the base rule `E → T`
  supplies the first answer, and the left-recursive rule extends it.
- Memoization is free: each distinct `(parse N i)` demand is one interned
  fact, computed once, shared by every asker. Only demanded (reachable)
  positions are explored — this is the demand/magic-set advantage over
  bottom-up CYK, which fills all O(n²) cells.

Then make it nondeterministic and structured — add a tree answer column:

```
demand (parse sym int) int tree
rule (parse E i k (plus a b))
 <--
     (parse E i j a) (tok j "+") (let j1 (+ j 1)) (parse T j1 k b)
```

An ambiguous grammar gives multiple `(end, tree)` answers per demand;
because trees are interned structs, shared subtrees are stored once —
a shared packed parse forest (SPPF), for free, from hash-consing.
Failure needs no machinery: an unparseable span simply has no answer
facts. And once input facts are retractable (docs/incremental.md),
editing one token retracts and rederives exactly the affected spans:
incremental parsing as the composition of two orthogonal features.

## 8. Semantics and caveats

- **Stratification.** A judgment's demand struct and answer table are
  mutually recursive with their callers' asks/resumes; SCC formation
  groups mutually-calling judgments into one stratum. Fine for positive
  rules; negation over a demanded relation obeys the usual
  stratification discipline.
- **Termination.** Distinct demands are processed once (interning =
  memoization), so evaluation terminates iff finitely many demands are
  reachable. `parse` terminates (positions are finite) even with left
  recursion. A concrete interpreter diverges exactly when the program
  does — as it should; abstract the value domain (CFA-style) for
  guaranteed termination.
- **Planning freedom.** With sigils gone, chain-vs-fanout for
  multi-premise bodies, ask scheduling, and continuation factoring
  become planner decisions (extensions of the existing greedy body
  scheduler and `stage-rule`), i.e. optimizations — not user syntax.
- **Incrementality.** Demands, answers, and continuations are ordinary
  facts, so DRed^c counting applies uniformly; suspended computation
  participates in deletion propagation with no special cases.

## 9. Implementation sketch

A new front-end pass, after module resolution (declarations known),
adjacent to simplification:

1. `demand` declaration → emit `struct (f x̄)` + `table (f-ans f ȳ)`
   into the rel-env/type-env.
2. Rewrite each rule mentioning full-arity occurrences of demand-moded
   relations per §5, generating ask/resume rules and (when live
   variables are not content-recoverable) continuation structs — reusing
   the carried-variable analysis pattern from `stage-rule`.
3. Mode-check: demand columns ground at asks; direct backing-relation
   uses pass through untouched.

Output is plain slog; every downstream pass (typecheck, stratify, plan,
lower, emit) is unchanged. Later phases: value-position sugar for
single-answer judgments; `lambda` sugar (closure structs + per-arrow
`apply`); exhaustiveness checking of demand patterns against the
scrutinee's union (pairs with the enum/union coverage direction);
planner heuristics for ask fanout and continuation factoring.
