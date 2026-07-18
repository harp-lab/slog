#!/usr/bin/env bash
#
# T0 command-protocol tests (docs/t0-contract.md, slice (a)).  The daemon's
# per-line dispatch is dual-stack: a line beginning `(` routes to the command
# parser, anything else stays a plugin path.  Covered here:
#
#   - routing: path lines behave exactly as before; `(`-lines are commands
#   - typed refusals: (refused <class> <generation> <detail>...) for the
#     implemented classes parse / unknown-verb / reserved-verb
#   - every reserved verb family answers reserved-verb (never unknown-verb)
#   - TCP/stdin parity: one dispatch, two transports, byte-identical replies
#     (the TCP (pending) heartbeat and (bye ...) handshake unchanged)
#   - catalog record round-trip: structured records a client consumes with
#     datum read + keyed field access, no string splitting (F criterion 4)
#   - (continue)/(continue-boundary) as the command layer's first verbs with
#     byte-identical legacy replies
#   - the protocol-mode seam: legacy literals do NOT flip a session into
#     command mode; any other command verb does (slice (d) keys the uniform
#     pause record off this)
#
#   tests/protocol-tests.sh        (expects a warm build/ cache; run after
#                                   tests/run-tests.sh, or budget compile time)
#
# Drivers send lines verbatim: tests/api/drive.rkt (stdin transport) and
# tests/api/tcp-drive.rkt (TCP transport).  Direct launch (no systemd wrap)
# so the environment reaches the daemon.

set -u
cd "$(dirname "$0")/.."
mkdir -p build out data
export SLOG_NO_MEM_CAP=1

PASS=0; FAIL=0
ok()  { echo "PASS $1"; PASS=$((PASS+1)); }
bad() { echo "FAIL $1"; FAIL=$((FAIL+1)); }
expect()    { if grep -qF "$2" "$3"; then ok "$1"; else echo "  (missing '$2' in $3)"; bad "$1"; fi; }
expect_rx() { if grep -qE "$2" "$3"; then ok "$1"; else echo "  (no match /$2/ in $3)"; bad "$1"; fi; }
expect_not() { if grep -qF "$2" "$3"; then echo "  (unexpected '$2' in $3)"; bad "$1"; else ok "$1"; fi; }

# --- 1. routing: the one-character route ------------------------------------
# A non-`(` line stays a plugin path with the byte-identical legacy error; a
# `(`-line is a command and never reaches the plugin loader.
racket tests/api/drive.rkt "no/such.so" "(no-such-verb)" > out/proto-route.log 2>&1
expect     "route-path-unchanged"   '(error "no such plugin: no/such.so")' out/proto-route.log
expect     "route-command"          '(refused unknown-verb'                out/proto-route.log
expect_not "route-command-no-plugin" 'no such plugin: (no-such-verb)'      out/proto-route.log

# --- 2. refusal classes ------------------------------------------------------
# parse: unbalanced form, trailing content (D6: one form per line), empty
# command, non-symbol verb.  unknown-verb: an unrecognized verb.  Every
# refusal carries the generation token field.  Reader details come from the
# ONE shared bounded reader (daemon/sexp.cpp, byte-offset prefixed); the
# refusal CLASS is the contract pin, the detail text is informative.
racket tests/api/drive.rkt "(foo" "(foo) (bar)" "()" '(("x") 1)' "(frobnicate 1 2)" \
  > out/proto-refuse.log 2>&1
expect_rx "refuse-parse-unbalanced" '\(refused parse [0-9]+ \(detail "[^"]*unterminated list"\)\)' out/proto-refuse.log
expect_rx "refuse-parse-trailing"   '\(refused parse [0-9]+ \(detail "[^"]*trailing value' out/proto-refuse.log
expect_rx "refuse-parse-empty"      '\(refused parse [0-9]+ \(detail "empty command"\)\)' out/proto-refuse.log
expect_rx "refuse-parse-nonsymbol"  '\(refused parse [0-9]+ \(detail "verb must be a symbol"\)\)' out/proto-refuse.log
expect_rx "refuse-unknown-verb"     '\(refused unknown-verb [0-9]+ \(verb frobnicate\)\)' out/proto-refuse.log
if [ "$(grep -c '(refused ' out/proto-refuse.log)" -eq 5 ]; then ok "refuse-one-reply-per-line"
else bad "refuse-one-reply-per-line"; fi

# --- 3. every reserved verb answers reserved-verb ----------------------------
RESERVED=(prepare-boundary commit-boundary abort-boundary
          query query-page query-cancel
          watch unwatch subscribe
          resume replay why-not-add debug-on debug-off)
ARGS=(); for v in "${RESERVED[@]}"; do ARGS+=("($v x y)"); done
racket tests/api/drive.rkt "${ARGS[@]}" > out/proto-reserved.log 2>&1
for v in "${RESERVED[@]}"; do
  expect_rx "reserved-$v" "\\(refused reserved-verb [0-9]+ \\(verb $v\\) \\(family (boundary|query|watch|debugger)\\)\\)" out/proto-reserved.log
done
if [ "$(grep -c '(refused reserved-verb ' out/proto-reserved.log)" -eq "${#RESERVED[@]}" ]; then
  ok "reserved-count-exact"; else bad "reserved-count-exact"; fi
expect_not "reserved-never-unknown" '(refused unknown-verb' out/proto-reserved.log

# --- 4. (continue)/(continue-boundary): first verbs, byte-identical replies --
racket tests/api/drive.rkt "(continue)" > out/proto-idle.log 2>&1
expect "continue-idle-bytes" "(idle)" out/proto-idle.log
racket tests/api/drive.rkt "(continue-boundary)" > out/proto-idleb.log 2>&1
expect "continue-boundary-idle-bytes" "(idle)" out/proto-idleb.log
# an argful literal is command-grammar, not a plugin path (budgeted continues
# still ride the compiled action in T0)
racket tests/api/drive.rkt "(continue 5)" > out/proto-contarg.log 2>&1
expect_rx "continue-args-refused" '\(refused parse [0-9]+ \(verb continue\)' out/proto-contarg.log

# --- 5. protocol-mode seam ----------------------------------------------------
# Legacy literals must NOT flip the session into command mode (every pre-T0
# driver sends them); any other command verb -- even a refused one -- does.
racket tests/api/drive.rkt "(protocol-mode)" "(continue)" "(continue-boundary)" \
  "(protocol-mode)" "(catalog)" "(protocol-mode)" > out/proto-mode.log 2>&1
if [ "$(grep -c '(protocol-mode path)' out/proto-mode.log)" -eq 2 ] \
   && grep -qF '(protocol-mode command)' out/proto-mode.log; then
  ok "mode-legacy-literals-stay-path"; else bad "mode-legacy-literals-stay-path"; fi
racket tests/api/drive.rkt "(bogus)" "(protocol-mode)" > out/proto-mode2.log 2>&1
expect "mode-refusal-marks-command" "(protocol-mode command)" out/proto-mode2.log

# --- 6. TCP/stdin parity ------------------------------------------------------
# One dispatch, two transports: the same command script produces byte-identical
# reply lines.  (pending)/(bye ...) are transport chatter, filtered from the
# diff but asserted separately -- the heartbeat and close handshake are frozen.
SCRIPT=("(continue)" "(protocol-mode)" "(frobnicate 1 2)" "(watch v94)"
        "(query q7)" "(catalog)" "(protocol-mode)" "(foo" "(catalog types)"
        "no/such.so")
racket tests/api/drive.rkt     "${SCRIPT[@]}" > out/proto-stdin.log 2>&1
racket tests/api/tcp-drive.rkt "${SCRIPT[@]}" > out/proto-tcp.log   2>&1
if diff <(grep -v -e '^(pending)$' -e '^(bye ' out/proto-tcp.log) out/proto-stdin.log \
     > out/proto-parity.diff 2>&1
then ok "tcp-stdin-parity"; else cat out/proto-parity.diff; bad "tcp-stdin-parity"; fi
expect_rx "tcp-bye-handshake" '^\(bye [0-9]+\)$' out/proto-tcp.log

# --- 7. catalog record round-trip ----------------------------------------------
# Empty daemon: a bare sentinel.
racket tests/api/drive.rkt "(catalog)" "(catalog relations)" "(catalog types)" \
  > out/proto-cat0.log 2>&1
if [ "$(grep -cF '(catalog-end 0)' out/proto-cat0.log)" -eq 3 ]; then
  ok "catalog-empty-sentinels"; else bad "catalog-empty-sentinels"; fi
# Bad selector: parse refusal, not a half stream.
racket tests/api/drive.rkt "(catalog frobs)" > out/proto-catbad.log 2>&1
expect_rx  "catalog-bad-selector" '\(refused parse [0-9]+ \(verb catalog\)' out/proto-catbad.log
expect_not "catalog-bad-no-stream" '(catalog-end' out/proto-catbad.log
# Populated daemon: build a struct+table fixture db, open it, and consume the
# records exactly as a client must -- datum read + keyed fields, no string
# splitting (tests/api/catalog-check.rkt), including the pinned #f fields.
rm -rf data/protocoldb
if timeout 600 racket compiler/run.rkt --no-banner --out-db protocoldb \
     tests/api/structdb.slog > out/proto-fixture.log 2>&1; then
  OPEN_SO=$(racket -e '(require (file "'"$PWD"'/compiler/actions.rkt")) (displayln (action-so (list (quote open) "protocoldb")))' 2>/dev/null)
  racket tests/api/drive.rkt "$OPEN_SO" "(catalog)" "(catalog types)" \
    > out/proto-catalog.log 2>&1
  if racket tests/api/catalog-check.rkt rel=mk,struct,3 rel=keep,table,1 \
       rel=seed,table,1 type=mk rels'>='3 types'>='1 < out/proto-catalog.log; then
    ok "catalog-round-trip"; else bad "catalog-round-trip"; fi
  expect_rx "catalog-version-keys-materialize" '\(version-key "[^"]+"\)' out/proto-catalog.log
  expect_rx "catalog-struct-sid" '\(catalog-type \(sid [1-9][0-9]*\) \(name "mk"\) \(arity 3\) \(type-key #f\)\)' out/proto-catalog.log
else
  bad "catalog-fixture-build (see out/proto-fixture.log)"
fi
rm -rf data/protocoldb

# --- 8. command replies interleave with a real run ---------------------------
# Replay the fixture's compiled strata through the dual-stack dispatcher and
# drive them with literal (continue) lines: fixpoints arrive as before, extra
# continues re-confirm idempotently, and a catalog verb afterwards sees the
# populated database.
mapfile -t SOS < <(grep -oE 'build/[a-f0-9]+(\.O0)?\.so' out/proto-fixture.log | grep -v 'action-' | awk '!seen[$0]++')
if [ "${#SOS[@]}" -ge 1 ]; then
  CONT=(); for i in $(seq 1 30); do CONT+=("(continue)"); done
  racket tests/api/drive.rkt "${SOS[@]}" "${CONT[@]}" "(catalog)" \
    > out/proto-run.log 2>&1
  expect_rx  "run-fixpoint-reached"  '\(fixpoint ' out/proto-run.log
  expect_not "run-no-error"          '(error'      out/proto-run.log
  expect_rx  "run-catalog-populated" '\(catalog-rel \(name "mk"\) \(kind struct\)' out/proto-run.log
else
  bad "run-replay-setup (no stratum .so paths in out/proto-fixture.log)"
fi

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
