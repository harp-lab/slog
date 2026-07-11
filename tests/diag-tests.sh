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

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
