# 2. Rules and recursion

Chapter 1 ended with a rule that combined two rows into one new fact.
This chapter is about what makes rules genuinely powerful: they can
build on their *own* results.

## Reachability

Course prerequisites make a good example. Say your department's catalog
looks like this:

```
table (prereq str str)

facts
(prereq "cs1" "cs2")
(prereq "cs2" "algorithms")
(prereq "cs2" "systems")
(prereq "algorithms" "compilers")
(prereq "systems" "compilers")
```

`(prereq "cs1" "cs2")` means cs1 must be taken before cs2. Now the
question every student actually has: what are *all* the courses I need
before I can take compilers — not just the direct ones, but the
prerequisites of the prerequisites?

In Java you'd write a graph traversal: a work-list, a visited set, a
loop. In Slog, you state what "must come before" means:

```
table (before str str)

rule (prereq X Y) --> (before X Y)
rule (before X Y) (prereq Y Z) --> (before X Z)
```

The first rule: every direct prerequisite comes before. The second:
if X comes before Y, and Y is a direct prerequisite of Z, then X comes
before Z. Notice the second rule *uses `before` to derive more
`before`* — it is recursive.

```
$ racket slog.rkt --debug-dir out/courses courses.slog
$ sort out/courses/before.csv | grep compilers
"algorithms"   "compilers"
"cs1"   "compilers"
"cs2"   "compilers"
"systems"   "compilers"
```

Everything before compilers, at every distance. Here is the mental
model for how the engine gets there:

1. Start with the facts you asserted.
2. Find every way any rule's left side matches the current facts; add
   each rule's right side as a new fact.
3. New facts may enable new matches — so repeat step 2.
4. Stop when a full pass adds nothing. Done.

Step 4 is why recursion here cannot loop forever the way a buggy Java
`while` can: relations are *sets*, deriving a fact that's already
present adds nothing, and there are only finitely many facts to derive.
The stable end state is called the **fixpoint**, and it contains
everything derivable — no more, no less. (The engine is much cleverer
than this naive loop — it only re-examines *new* facts each round — but
the result is identical, and the naive model is the right one to reason
with.)

## Rules are more flexible than they look

**Several patterns, several conclusions.** A rule's left side may have
any number of patterns (they all must match, sharing variables), and
its right side may assert several facts at once:

```
rule (before X "compilers") --> (needed X) (workload X 1)
```

**Both arrow directions.** `head <-- body` means the same as
`body --> head`; use whichever reads better. This is handy when the
conclusion is the interesting part:

```
rule (needed X) <-- (before X "compilers")
```

**Alternatives with `|`.** Two bodies that differ in one spot can share
a rule:

```
rule ((prereq X Y) | (coreq X Y)) --> (linked X Y)
```

**Wildcards.** `_` matches anything without naming it. "Which courses
have at least one prerequisite?"

```
rule (prereq _ Y) --> (has_prereq Y)
```

Each `_` is independent — two wildcards in one rule may match two
different values.

## A thing you cannot say (yet)

Try to express: "a course is *ready* if you've passed all its
prerequisites." That "all" is a genuinely different kind of statement —
it asks about the *absence* of an unmet prerequisite, and Slog rules
only ever conclude from facts that are *present*. Everything in
chapters 1–9 is monotone: more facts in, more facts out. It's a real
limitation with real benefits (it's why recursion is always safe and
parallel), and chapter 8 shows how lattices recover many of the
patterns you'd miss — including, eventually, this one.

## Cheat sheet

| Form | Example | Meaning |
|---|---|---|
| recursion | `rule (before X Y) (prereq Y Z) --> (before X Z)` | rules may mention their own conclusions; the engine runs to the fixpoint |
| multiple heads | `rule (p X) --> (q X) (r X 1)` | one match asserts several facts |
| reversed arrow | `rule (q X) <-- (p X)` | same as `(p X) --> (q X)` |
| alternatives | `rule ((p X) \| (q X)) --> (r X)` | either body derives the head |
| wildcard | `rule (prereq _ Y) --> (has_prereq Y)` | match anything, bind nothing; each `_` independent |
| the model | — | keep applying rules until nothing new appears; sets deduplicate; termination follows |
