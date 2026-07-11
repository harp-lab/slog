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
run() { racket slog.rkt --no-banner --debug-dir "$D/out-$1" "$D/$1.slog" 2>&1; }

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
if echo "$o" | grep -q 'unsafe negation at neg_unsafe\.slog:5: variable Y'; then
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

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
