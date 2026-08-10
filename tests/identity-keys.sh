#!/usr/bin/env bash
#
# T0(c) slice c1 gate: key stability, end to end
# (docs/t0-contract.md slice (c): "same layer replay preserves keys;
# modified clone gets a fresh LayerId and fresh keys; degenerate module
# component round-trips; repo-relative source paths asserted").
#
#   1. REPLAY STABILITY -- run a two-instance program in a session, save it,
#      load the save in a fresh session: the reloaded identity ledger is
#      BYTE-IDENTICAL (the recipe replays the same program keys and slot
#      tables, so every RuleKey/SccInstanceKey re-mints exactly).
#   2. FRESH KEYS -- the same program run as a NEW session (fresh
#      layer/event) shares no key with the original: immutable-image
#      semantics, RF5 §2's "a replacement never reuses those keys".
#   3. INSTANCE DISTINCTION -- two instantiations of one library file mint
#      DISTINCT ModuleInstanceKey-rooted RuleKeys (the case the first
#      implementation got wrong: a source-path-keyed join merged them).
#   4. NO ABSOLUTE PATHS -- finding 6: locs are module-relative, never
#      checkout paths.
#
#   bash tests/identity-keys.sh

set -u
cd "$(dirname "$0")/.."

WORK="$(mktemp -d)"
trap 'rm -rf "$WORK"' EXIT
PASS=0; FAIL=0
pass() { echo "PASS $1"; PASS=$((PASS+1)); }
fail() { echo "FAIL $1"; FAIL=$((FAIL+1)); }

export SLOG_OPT=0            # identity is executor-independent; fast + quiet
export SLOG_SMT_SOLVERS=mock
mkdir -p build out data

keys_of() { # <log> -- the identity records, program keys normalized away
  grep -E '^\(scc-record|^\(rule-record' "$1"
}

# ---- 1+3+4: run, inspect, save ----------------------------------------------
rm -rf data/idkeys-save
if ! timeout 600 racket tests/api/session-drive.rkt \
     run:tests/n1_instances.slog rule-keys daemon-rule-meta save:idkeys-save \
     > "$WORK/orig.log" 2>&1; then
  echo "  (original session failed; see $WORK/orig.log)"; fail "orig-run"
  echo "$PASS passed, $((FAIL+1)) failed"; exit 1
fi
keys_of "$WORK/orig.log" > "$WORK/orig.keys"
n_keys=$(wc -l < "$WORK/orig.keys")
[ "$n_keys" -ge 10 ] && pass "ledger-populated ($n_keys records)" \
                     || fail "ledger-populated (got $n_keys records)"

# two instances of one library -> two distinct module-instance components,
# each with its own rule slots
if grep -q '(rule-record r1:m1:[^ ]*:0:0\.0 ' "$WORK/orig.keys" \
   && grep -q '(rule-record r1:m1:[^ ]*:1:0\.0 ' "$WORK/orig.keys"; then
  pass "instances-distinct"
else
  fail "instances-distinct (occurrence slots 0 and 1 not both present)"
fi

# the root (degenerate) module component round-trips as :root
grep -q 'm1:[^ ]*:root' "$WORK/orig.keys" \
  && pass "root-component" || fail "root-component"

# repo-relative locs: no absolute path anywhere in the ledger
if grep -E '\(loc "?/' "$WORK/orig.keys" > /dev/null; then
  fail "relative-locs (absolute path in a loc)"
else
  pass "relative-locs"
fi

# ---- c2: the daemon-side registry ------------------------------------------
# every registered rid resolves through the session's join; the two library
# instances register the SAME kernel exec key with DIFFERENT RuleKeys -- the
# per-attachment disaggregation T4's attachment identity promised
n_reg=$(grep -c '^(rule-meta-record .* (key "r1:' "$WORK/orig.log" || true)
[ "$n_reg" -ge 8 ] && pass "registry-populated ($n_reg keyed rids)" \
                   || fail "registry-populated (got $n_reg)"
lib4=$(grep '^(rule-meta-record' "$WORK/orig.log" | grep 'n1_graph_lib.slog:4' \
         | grep -o '(key "[^"]*"' | sort -u | wc -l)
[ "$lib4" -eq 2 ] && pass "registry-per-attachment-keys" \
                  || fail "registry-per-attachment-keys (got $lib4 distinct)"

# ---- 1: the reload re-mints byte-identical ----------------------------------
if ! timeout 600 racket tests/api/session-drive.rkt \
     open:idkeys-save rule-keys > "$WORK/reload.log" 2>&1; then
  echo "  (reload session failed; see $WORK/reload.log)"; fail "reload-run"
else
  keys_of "$WORK/reload.log" > "$WORK/reload.keys"
  if diff -q "$WORK/orig.keys" "$WORK/reload.keys" > /dev/null; then
    pass "replay-preserves-keys"
  else
    diff "$WORK/orig.keys" "$WORK/reload.keys" | head -6 | sed 's/^/  /'
    fail "replay-preserves-keys"
  fi
fi

# ---- 2: a fresh session mints entirely fresh keys ----------------------------
if ! timeout 600 racket tests/api/session-drive.rkt \
     run:tests/n1_instances.slog rule-keys > "$WORK/fresh.log" 2>&1; then
  echo "  (fresh session failed; see $WORK/fresh.log)"; fail "fresh-run"
else
  keys_of "$WORK/fresh.log" > "$WORK/fresh.keys"
  shared=$(comm -12 <(sort "$WORK/orig.keys") <(sort "$WORK/fresh.keys") | wc -l)
  if [ "$shared" -eq 0 ]; then
    pass "fresh-layer-fresh-keys"
  else
    fail "fresh-layer-fresh-keys ($shared records shared across layers)"
  fi
  # ...while the SHAPE is identical: same record count, same slots, same
  # locs -- only the program-key component moved
  norm() { sed -E 's/(p1|layer)[-:][0-9a-f:-]*//g' "$1" | LC_ALL=C sort; }
  if diff -q <(norm "$WORK/orig.keys") <(norm "$WORK/fresh.keys") > /dev/null; then
    pass "fresh-keys-same-shape"
  else
    fail "fresh-keys-same-shape"
  fi
fi

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
