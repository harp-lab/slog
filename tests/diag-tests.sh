#!/usr/bin/env bash
#
# Diagnostics regression tests (docs/build-issues-notes.md §5).  Distinct user
# mistakes must produce a LOCATED, actionable compile error instead of an opaque
# internal failure -- and genuine user type errors must keep their own clear
# messages (not be relabelled as an "internal error").
#
#   tests/diag-tests.sh          (self-contained; a few seconds)

set -u
cd "$(dirname "$0")/.."
mkdir -p build out
export SLOG_NO_MEM_CAP=1

PASS=0; FAIL=0
ok()  { echo "PASS $1"; PASS=$((PASS+1)); }
bad() { echo "FAIL $1"; FAIL=$((FAIL+1)); echo "  --- output ---"; echo "$2" | sed 's/^/  /' | head -8; }

D=out/diag
rm -rf "$D"; mkdir -p "$D"
run() { racket compiler/run.rkt --no-banner --debug-dir "$D/out-$1" "$D/$1.slog" 2>&1; }

# 1. `_` wildcard in a head is rejected at simplify time with a located message
#    (was: locationless `hash-ref '__gNNN`).
cat > "$D/head_wild.slog" <<'EOF'
table (a int)
table (b int int)
rule (a 1)
rule (b _ n) <-- (a n)
EOF
o="$(run head_wild)"
if echo "$o" | grep -qiE 'wildcard in a head'; then ok head-wildcard-rejected
else bad head-wildcard-rejected "$o"; fi

# 2. an unbound NAMED variable surfaces with the offending rule's location (was:
#    a bare `hash-ref: no value found for key: 'y`).
cat > "$D/unbound.slog" <<'EOF'
table (a int)
table (b int)
rule (a 1)
rule (b y) <-- (a x)
EOF
o="$(run unbound)"
if echo "$o" | grep -qE 'internal error while compiling the rule at unbound\.slog:4'; then
  ok unbound-var-located
else bad unbound-var-located "$o"; fi

# 3. a genuine user type error (undeclared relation) keeps its OWN clear message
#    and is NOT relabelled "internal error" (the wrapper catches only contract
#    failures, not intentional `error` calls).
cat > "$D/undeclared.slog" <<'EOF'
table (a int)
rule (a 1)
rule (b 2) <-- (a x)
EOF
o="$(run undeclared)"
if echo "$o" | grep -qiE 'is not defined' && ! echo "$o" | grep -qi 'internal error'; then
  ok user-type-error-preserved
else bad user-type-error-preserved "$o"; fi

# 4. a missing include WARNS instead of silently dropping its declarations.
cat > "$D/badinc.slog" <<'EOF'
include "does-not-exist-xyz.slog"
table (a int)
rule (a 1)
EOF
o="$(run badinc)"
if echo "$o" | grep -qiE 'include .*not found'; then ok missing-include-warned
else bad missing-include-warned "$o"; fi

# 5. control: a valid program (head constructors + a BODY wildcard) still
#    compiles and runs -- the head-wildcard check must not be a false positive.
cat > "$D/valid.slog" <<'EOF'
struct (Pair int int)
table (p Pair)
table (q int)
rule (p (Pair 1 2))
rule (q x) <-- (p (Pair _ x))
EOF
o="$(run valid)"
if echo "$o" | grep -qE '\(fixpoint '; then ok valid-program-compiles
else bad valid-program-compiles "$o"; fi

# --- stratified negation rejections (docs/incremental.md 0.8, sub-phase 0.A) ---

# 6. negation through recursion is a stratification error naming the rule
#    and the cycle.
cat > "$D/neg_scc.slog" <<'EOF'
table (p int)
table (q int)
rule (p 1)
rule (q X) <-- (p X) ~(q X)
EOF
o="$(run neg_scc)"
if echo "$o" | grep -q 'negation through recursion -- not stratified'; then
  ok negation-in-scc-rejected
else bad negation-in-scc-rejected "$o"; fi

# 6b. ... including through a MUTUAL cycle (r reads ~q, q derives from r).
cat > "$D/neg_scc2.slog" <<'EOF'
table (p int)
table (q int)
table (r int)
rule (p 1)
rule (r X) <-- (p X) ~(q X)
rule (q X) <-- (r X)
EOF
o="$(run neg_scc2)"
if echo "$o" | grep -q 'negation through recursion -- not stratified' \
   && echo "$o" | grep -q 'cycle: q r'; then
  ok negation-in-mutual-scc-rejected
else bad negation-in-mutual-scc-rejected "$o"; fi

# 7. an unsafe negated variable (bound by no positive body clause) is a
#    located error naming the variable.
cat > "$D/neg_unsafe.slog" <<'EOF'
table (p int)
table (q int int)
table (out int)
rule (p 1)
rule (out X) <-- (p X) ~(q X Y)
EOF
o="$(run neg_unsafe)"
if echo "$o" | grep -q 'unsafe negation at neg_unsafe\.slog:5:[0-9]*: variable Y'; then
  ok unsafe-negated-var-rejected
else bad unsafe-negated-var-rejected "$o"; fi

# 8. no head negation.
cat > "$D/neg_head.slog" <<'EOF'
table (p int)
table (q int)
rule (p 1)
rule ~(q X) <-- (p X)
EOF
o="$(run neg_head)"
if echo "$o" | grep -q 'negation (~) is not permitted in a rule head'; then
  ok head-negation-rejected
else bad head-negation-rejected "$o"; fi

# 9. nested patterns under ~ are rejected (bind positively first).
cat > "$D/neg_nested.slog" <<'EOF'
table (p int)
struct (s int)
table (q s)
table (out int)
rule (p 1)
rule (out X) <-- (p X) ~(q (s X))
EOF
o="$(run neg_nested)"
if echo "$o" | grep -q 'bind a nested pattern positively first'; then
  ok nested-pattern-under-neg-rejected
else bad nested-pattern-under-neg-rejected "$o"; fi

# 10. | alternatives under ~ are rejected (would violate De Morgan).
cat > "$D/neg_or.slog" <<'EOF'
table (a int)
table (b int)
table (p int)
table (out int)
rule (p 1)
rule (out X) <-- (p X) ~((a X) | (b X))
EOF
o="$(run neg_or)"
if echo "$o" | grep -q 'alternatives cannot appear under ~'; then
  ok or-under-neg-rejected
else bad or-under-neg-rejected "$o"; fi

# 11. negating a struct pattern (even flat) is rejected with the id-based
#     alternative suggested.
cat > "$D/neg_struct.slog" <<'EOF'
table (p int)
struct (s int)
table (out int)
rule (p 1)
rule (out X) <-- (p X) ~(s X)
EOF
o="$(run neg_struct)"
if echo "$o" | grep -q 'cannot be negated: interned existence is an evaluation artifact'; then
  ok struct-negation-rejected
else bad struct-negation-rejected "$o"; fi

# 12. a negated lattice atom takes the KEY columns only.
cat > "$D/neg_lat_arity.slog" <<'EOF'
lattice (low (min int))
table (best int low)
table (k int)
table (out int)
rule (k 1)
rule (out X) <-- (k X) (k V) ~(best X V)
EOF
o="$(run neg_lat_arity)"
if echo "$o" | grep -q 'negated atom over best takes 1 key column'; then
  ok lattice-negation-keys-only
else bad lattice-negation-keys-only "$o"; fi

# 13. control: a valid negation still compiles and runs (the checks above
#     must not be false positives), and negation composes with wildcards.
cat > "$D/neg_valid.slog" <<'EOF'
table (a int int)
table (b int)
table (out int)
rule (a 1 10) (a 2 20)
rule (b 2)
rule (out X) <-- (a X _) ~(b X)
EOF
o="$(run neg_valid)"
if echo "$o" | grep -qE '\(fixpoint '; then ok valid-negation-compiles
else bad valid-negation-compiles "$o"; fi

# 14. errors quote the rule as written, not its desugared form: a constant
#     argument and a nested constructor are lifted into gensyms (was:
#     `_tconst6jUh7 : int does not match ...` and `Table expr in
#     (expr _t5whY28) is not defined.`).
cat > "$D/quote_const.slog" <<'EOF'
table (edge int int)
table (path int int)
rule (edge 1 2)
rule (edge X Y) --> (path X "s")
EOF
cat > "$D/quote_nested.slog" <<'EOF'
union (expr (num int) (add expr expr))
rule (expr (num 3))
EOF
o="$(run quote_const; run quote_nested)"
if echo "$o" | grep -qF 'quote_const.slog:4:1: "s" : int' \
   && echo "$o" | grep -qF 'rule (edge X Y) --> (path X "s")' \
   && echo "$o" | grep -qF 'quote_nested.slog:2:6: Table expr in (expr (num 3)) is not defined' \
   && ! echo "$o" | grep -qE '_t[A-Za-z]*[0-9]'; then
  ok errors-quote-source
else bad errors-quote-source "$o"; fi

# 15. a constructor named like a primitive is a located compile error at its
#     declaration (was: (neg X) silently evaluated as the primitive, every
#     binding surfaced a runtime type_mismatch fact, and the rule's heads were
#     lost).  A TABLE may still take such a name: atoms are not expressions.
cat > "$D/ctor_prim.slog" <<'EOF'
union (expr (lit int) (neg expr))
table (e expr)
table (out expr)
rule (e (lit 3))
rule (e X) --> (out (neg X))
EOF
cat > "$D/table_prim.slog" <<'EOF'
table (min int int)
table (out int)
rule (min 1 2)
rule (min X Y) --> (out X)
EOF
o="$(run ctor_prim)"
o2="$(run table_prim)"
if echo "$o" | grep -qF 'ctor_prim.slog:1:23: The constructor neg has the name of a builtin primitive' \
   && echo "$o2" | grep -qE '\(fixpoint '; then
  ok constructor-named-like-primitive-rejected
else bad constructor-named-like-primitive-rejected "$o
$o2"; fi

# 16. an int/float mix in a polymorphic prim names the rule's location and
#     quotes it, like every other type error (was: a bare
#     `Arguments X : int and _tconst... : float do not match`).
cat > "$D/numeric_mix.slog" <<'EOF'
table (a int)
table (b float)
rule (a 1)
rule (a X) --> (b (+ X 1.5))
EOF
o="$(run numeric_mix)"
if echo "$o" | grep -qE 'numeric_mix\.slog:4:1: Arguments .* do not match' \
   && echo "$o" | grep -qF 'rule (a X) --> (b (+ X 1.5))' \
   && ! echo "$o" | grep -qE '_t[A-Za-z]*[0-9]'; then
  ok numeric-mismatch-located
else bad numeric-mismatch-located "$o"; fi

# 17. an ordering comparison on a string is a located compile error (was: it
#     compiled, then every binding surfaced a runtime type_mismatch fact and
#     the rule derived nothing).
cat > "$D/str_order.slog" <<'EOF'
table (s str)
table (out str)
rule (s "a") (s "c")
rule (s S) (< S "b") --> (out S)
EOF
o="$(run str_order)"
if echo "$o" | grep -qF 'str_order.slog:4:1: S : str cannot be compared with <' \
   && echo "$o" | grep -qF 'rule (s S) (< S "b") --> (out S)'; then
  ok string-order-rejected
else bad string-order-rejected "$o"; fi

# 99. a hyphenated name is rejected where it is written, naming it (was: the
#     lexer split `on-cycle` into the subtraction `on - cycle`, and
#     simplify-all broke its own contract on the resulting rule).
cat > "$D/name_hyphen.slog" <<'EOF'
table (edge int int)
table (on-cycle int)
rule (edge 1 2)
rule (on-cycle X) <-- (edge X X)
EOF
cat > "$D/name_hyphen_ctor.slog" <<'EOF'
union (term (my-var int) (lam term))
table (t term)
rule (t (my-var 1))
EOF
o="$(run name_hyphen; run name_hyphen_ctor)"
if echo "$o" | grep -qF "name_hyphen.slog:2:8: on-cycle is not a valid name" \
   && echo "$o" | grep -qF "name_hyphen_ctor.slog:1:14: my-var is not a valid name" \
   && echo "$o" | grep -qF "write on_cycle" \
   && ! echo "$o" | grep -qi 'contract'; then
  ok hyphenated-name-rejected
else bad hyphenated-name-rejected "$o"; fi

# 16. `const` is reserved: the parser spells every literal (const v), so a
#     constructor named const read as a malformed literal (was: the same
#     simplify-all contract failure).
cat > "$D/name_const.slog" <<'EOF'
union (term (const int) (lam term))
table (t term)
rule (t (const 1))
EOF
o="$(run name_const)"
if echo "$o" | grep -qF "name_const.slog:1:14: const is a reserved word" \
   && ! echo "$o" | grep -qi 'contract'; then
  ok const-name-reserved
else bad const-name-reserved "$o"; fi

# 99. an enum member written without parentheses is a located error saying
#     how to write it (was: in a head, `internal error ... key: 'red`; in a
#     body, a variable silently matching every value).
cat > "$D/enum_bare_head.slog" <<'EOF'
enum (color red green)
table (c color)
rule (c red)
EOF
cat > "$D/enum_bare_body.slog" <<'EOF'
enum (color red green)
table (c color)
table (out int)
rule (c (red))
rule (out 1) <-- (c green)
EOF
o="$(run enum_bare_head; run enum_bare_body)"
if echo "$o" | grep -qF 'enum_bare_head.slog:3:6: red is an enum member, not a variable: write it with parentheses, (red)' \
   && echo "$o" | grep -qF 'enum_bare_body.slog:5:18: green is an enum member' \
   && ! echo "$o" | grep -qi 'internal error'; then
  ok enum-member-needs-parens
else bad enum-member-needs-parens "$o"; fi

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
