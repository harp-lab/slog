#!/usr/bin/env bash
#
# T0 command-protocol tests (docs/t0-contract.md, slice (a)).  The daemon's
# per-line dispatch is dual-stack: a line beginning `(` routes to the command
# parser, anything else stays a plugin path.  Covered here:
#
#   - routing: path lines behave exactly as before; `(`-lines are commands
#   - typed refusals: (refused <class> <generation> <detail>...) for the
#     implemented classes parse / unknown-verb / reserved-verb plus Q1's
#     query parse/bind/admission/pagination/state refusals
#   - every still-reserved verb family answers reserved-verb (never unknown);
#     N3-A's boundary family exercises live prepare/commit/abort instead
#   - canonical Q1 payload admission, exact-VersionKey bind, row pagination,
#     cancellation, stale generation, and non-mutating literal misses
#   - TCP/stdin parity: one dispatch, two transports, byte-identical replies
#     (the TCP (pending) heartbeat and (bye ...) handshake unchanged)
#   - catalog record round-trip: structured records a client consumes with
#     datum read + keyed field access, no string splitting (F criterion 4)
#   - (continue)/(continue-boundary) as the command layer's first verbs with
#     byte-identical legacy replies
#   - the protocol-mode seam: legacy literals do NOT flip a session into
#     command mode; any other command verb does (slice (d) keys the uniform
#     pause record off this)
#   - T0(b)'s connection-scoped SCC/stratum begin-add-seal lifecycle,
#     generation admission, D16 refusal mapping, entry/flavor policy, and an
#     explicit continue after command installation
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
CXX="${CXX:-clang++}"

PASS=0; FAIL=0
ok()  { echo "PASS $1"; PASS=$((PASS+1)); }
bad() { echo "FAIL $1"; FAIL=$((FAIL+1)); }
expect()    { if grep -qF "$2" "$3"; then ok "$1"; else echo "  (missing '$2' in $3)"; bad "$1"; fi; }
expect_rx() { if grep -qE "$2" "$3"; then ok "$1"; else echo "  (no match /$2/ in $3)"; bad "$1"; fi; }
expect_not() { if grep -qF "$2" "$3"; then echo "  (unexpected '$2' in $3)"; bad "$1"; else ok "$1"; fi; }
expect_not_rx() { if grep -qE "$2" "$3"; then echo "  (unexpected match /$2/ in $3)"; bad "$1"; else ok "$1"; fi; }

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
# watch/unwatch are LIVE (level-0 watches).  `subscribe` -- the event-kind
# filter, a separate concept from a WatchSpec -- is still reserved.
# `replay` is LIVE as of T5 slice (c) and is pinned in 3y below.
RESERVED=(subscribe
          resume why-not-add debug-on debug-off)
ARGS=(); for v in "${RESERVED[@]}"; do ARGS+=("($v x y)"); done
racket tests/api/drive.rkt "${ARGS[@]}" > out/proto-reserved.log 2>&1
for v in "${RESERVED[@]}"; do
  expect_rx "reserved-$v" "\\(refused reserved-verb [0-9]+ \\(verb $v\\) \\(family (boundary|query|watch|debugger)\\)\\)" out/proto-reserved.log
done
if [ "$(grep -c '(refused reserved-verb ' out/proto-reserved.log)" -eq "${#RESERVED[@]}" ]; then
  ok "reserved-count-exact"; else bad "reserved-count-exact"; fi
expect_not "reserved-never-unknown" '(refused unknown-verb' out/proto-reserved.log

# --- 3z. level-0 watch registration (repl.md §6) ----------------------------
# A watch names an EXACT VersionKey: the daemon never resolves a QName or
# follows a latest binding, so an unbound key is refused rather than guessed.
# Ids belong to the client, so a duplicate is refused rather than rebound.
# (Firing is behaviour over a running stratum and is gated in the session
# battery, where a real program iterates.)
W_DECL='(declare (qname "edge") (kind table) (arity 2) (type-key #f) (lat-spec #f) (shape "(declaration (qname \"edge\") table (fields int int))")) (declare (qname "empty") (kind table) (arity 2) (type-key #f) (lat-spec #f) (shape "(declaration (qname \"empty\") table (fields int int))"))'
W_PREPARE="(prepare-boundary (generation 0) (boundary \"w.b0\") (program \"w.p0\") (declarations $W_DECL) (memberships) (actions (create (qname \"edge\") (version-key \"w.edge.0\") (predecessor #f) (type-key #f)) (create (qname \"empty\") (version-key \"w.empty.0\") (predecessor #f) (type-key #f))))"
racket tests/api/drive.rkt \
  "$W_PREPARE" \
  '(commit-boundary (generation 0) (boundary "w.b0"))' \
  '(watch (id "w1") (version-key "w.edge.0"))' \
  '(watch (id "w1") (version-key "w.edge.0"))' \
  '(watch (id "w2") (version-key "w.edge.missing"))' \
  '(watch (id "w3"))' \
  '(unwatch (id "nope"))' \
  '(unwatch (id "w1"))' \
  '(watch (id "w4") (version-key "w.edge.0") (level 1))' \
  '(watch (id "w5") (version-key "w.edge.0") (level 0))' \
  '(watch (id "w6") (version-key "w.edge.0") (level 2))' \
  '(watch (id "w7") (version-key "w.edge.0") (level 1) (provenance #t))' \
  '(watch (id "w8") (version-key "w.edge.0") (provenance #t))' \
  '(watch (id "w9") (version-key "w.edge.0") (level 1) (provenance yes))' \
  '(watch (id "w10") (version-key "w.empty.0") (level 1))' \
  > out/proto-watch.log 2>&1
expect    "watch-added" '(watch-added (id "w1") (version-key "w.edge.0") (watches 1))' out/proto-watch.log
expect_rx "watch-duplicate-id" '\(refused watch-binding [0-9]+ \(verb watch\) \(detail "watch id w1 is already in use"\)\)' out/proto-watch.log
expect_rx "watch-unbound-key" '\(refused watch-binding [0-9]+ \(verb watch\) \(detail "no relation is bound to w\.edge\.missing"\)\)' out/proto-watch.log
expect_rx "watch-needs-key" '\(refused parse [0-9]+ \(verb watch\)' out/proto-watch.log
expect_rx "unwatch-unknown" '\(refused watch-binding [0-9]+ \(verb unwatch\) \(detail "no watch with id nope"\)\)' out/proto-watch.log
expect    "watch-removed" '(watch-removed (id "w1") (watches 0))' out/proto-watch.log
# T5 slice (a): (level 1) registers the pre-commit-gate intent and echoes;
# an explicit (level 0) stays byte-identical to the unlevelled reply; any
# other level is a parse refusal (docs/t5-contract.md)
expect    "watch-level1-added" '(watch-added (id "w4") (version-key "w.edge.0") (watches 1) (level 1))' out/proto-watch.log
expect    "watch-level0-explicit" '(watch-added (id "w5") (version-key "w.edge.0") (watches 2))' out/proto-watch.log
expect_rx "watch-level-refused" '\(refused parse [0-9]+ \(verb watch\) \(detail "level must be 0 or 1"\)\)' out/proto-watch.log
# T5 slice (d1): (provenance #t) is the capture opt-in -- echoed like the
# level, refused at level 0 (there is no gate there to explain), and only
# ever a boolean.  Level-0 and level-1-without-capture lines stay identical.
expect    "watch-provenance-added" '(watch-added (id "w7") (version-key "w.edge.0") (watches 3) (level 1) (provenance #t))' out/proto-watch.log
expect_rx "watch-provenance-level" '\(refused parse [0-9]+ \(verb watch\) \(detail "provenance capture is a level-1 watch.s observation"\)\)' out/proto-watch.log
expect_rx "watch-provenance-bool" '\(refused parse [0-9]+ \(verb watch\) \(detail "provenance must be #t or #f"\)\)' out/proto-watch.log
# T5 slice (d4): with struct and lattice settles landed, registration reports
# whether the gate can actually preview this binding, instead of accepting
# the level and silently never engaging.  The field is negative-only, so a
# settleable level-1 line stays byte-identical (watch-level1-added above) --
# and an EMPTY relation is still settleable, because a declared table carries
# a full index from the moment it exists.  `(settleable #f)` therefore names
# a genuinely index-free binding, which is the safety net, not the norm.
expect    "watch-empty-still-settles" '(watch-added (id "w10") (version-key "w.empty.0") (watches 4) (level 1))' out/proto-watch.log
expect_not "watch-no-false-unsettleable" '(settleable #f)' out/proto-watch.log

# T5 slice (b): prepare-time registration -- a watch binds a PREPARED
# successor key through the private overlay, and watch verbs are exempt
# from the boundary lease (session debugging state); ordinary catalog
# access under the lease stays refused exactly as before.
racket tests/api/drive.rkt \
  "$W_PREPARE" \
  '(watch (id "g1") (version-key "w.edge.0") (level 1))' \
  '(catalog)' \
  '(commit-boundary (generation 0) (boundary "w.b0"))' \
  '(unwatch (id "g1"))' \
  > out/proto-watch-lease.log 2>&1
expect    "watch-under-lease" '(watch-added (id "g1") (version-key "w.edge.0") (watches 1) (level 1))' out/proto-watch-lease.log
expect_rx "catalog-still-leased" '\(refused boundary-admission [0-9]+ \(verb catalog\) \(boundary "w\.b0"\)\)' out/proto-watch-lease.log
expect    "watch-lease-unwatch" '(watch-removed (id "g1") (watches 0))' out/proto-watch-lease.log

# --- 3y. T5 slice (c): `replay` leaves reserved-verb parking ----------------
# The verb is live, so it must answer STRUCTURALLY rather than as a family
# placeholder: bare form only, and with nothing parked it says so and names
# the position it found.  (Honouring a replay needs a pre-commit gate park,
# which the REPL battery drives over a real program; the refusal against a
# non-monotone epoch -- `level-1-unwatchable` -- is pinned there too, where
# a maintenance epoch actually exists to park.)
racket tests/api/drive.rkt \
  '(replay)' \
  '(replay now)' \
  > out/proto-replay.log 2>&1
expect_rx "replay-not-reserved" '\(refused replay-unavailable [0-9]+ \(verb replay\) \(detail not-parked\) \(position none\)\)' out/proto-replay.log
expect_rx "replay-bare-only"    '\(refused parse [0-9]+ \(verb replay\) \(detail "T5 takes the bare form' out/proto-replay.log
expect_not "replay-still-reserved" '(refused reserved-verb' out/proto-replay.log

# --- 3x. T5 slice (c3): step and frames ------------------------------------
# Both are debugger continuations over a PARKED epoch, so with nothing
# parked they refuse structurally and name the position; a granularity that
# is not one of the five is a parse refusal, not a silent "step".  (Stepping
# a live read is pinned in the REPL battery, where a program is running.)
racket tests/api/drive.rkt \
  '(step)' \
  '(step sideways)' \
  '(frames)' \
  '(frames now)' \
  > out/proto-step.log 2>&1
expect_rx "step-not-parked"  '\(refused step-unavailable [0-9]+ \(verb step\) \(detail not-parked\) \(position none\)\)' out/proto-step.log
expect_rx "step-grain-parse" '\(refused parse [0-9]+ \(verb step\) \(detail "step \[match\|fire\|emit\|tuple\]' out/proto-step.log
expect_rx "frames-no-stop"   '\(refused step-unavailable [0-9]+ \(verb frames\) \(detail no-stop\) \(position none\)\)' out/proto-step.log
expect_rx "frames-bare-only" '\(refused parse [0-9]+ \(verb frames\) \(detail "frames takes no arguments"\)\)' out/proto-step.log

# --- 3w. T5 slice (d1): `why` reads the provenance journal ------------------
# The journal is opt-in and event-scoped, so with nothing armed every form
# refuses honestly rather than answering an empty tree; the row vocabulary
# is the QUERY payload's literal vocabulary, and a value this evaluation
# never interned cannot appear in a fact.  (A real proof tree needs a run,
# so the tree itself is pinned in the REPL battery.)
racket tests/api/drive.rkt \
  '(why)' \
  '(why (relation "edge") (row (integer "1") (integer "2")))' \
  '(why (relation "edge"))' \
  '(why (relation "edge") (row (bogus "1")))' \
  '(why (relation "edge") (row (integer "1")) (depth 99))' \
  > out/proto-why.log 2>&1
expect_rx "why-no-candidates" '\(refused provenance-unavailable [0-9]+ \(verb why\) \(detail "no gate candidates here' out/proto-why.log
expect_rx "why-unarmed"       '\(refused provenance-unavailable [0-9]+ \(verb why\) \(detail "no derivations were captured' out/proto-why.log
expect_rx "why-row-pairing"   '\(refused parse [0-9]+ \(verb why\) \(detail "relation and row go together"\)\)' out/proto-why.log
expect_rx "why-term-kind"     '\(refused parse [0-9]+ \(verb why\) \(detail "unknown row term kind"\)\)' out/proto-why.log
expect_rx "why-depth-range"   '\(refused parse [0-9]+ \(verb why\) \(detail "depth is 1\.\.16"\)\)' out/proto-why.log
expect_not "why-still-reserved" '(refused reserved-verb' out/proto-why.log

# --- 3v. T5 slice (d3): standing breakpoints --------------------------------
# A break needs NO park to arm -- that is the point of the slice -- so what
# the protocol pins is the shape: an id, at least one filter, a body position
# that belongs to a rule, and the listing/removal round trip.
racket tests/api/drive.rkt \
  '(break (id "b1") (relation "edge"))' \
  '(break (id "b1") (relation "edge"))' \
  '(break (id "b2"))' \
  '(break (relation "edge"))' \
  '(break (id "b3") (position 2))' \
  '(break (id "b4") (rule 7) (position 1))' \
  '(breaks)' \
  '(unbreak (id "b9"))' \
  '(unbreak (id "b1"))' \
  > out/proto-break.log 2>&1
expect    "break-added"       '(break-added (id "b1") (breaks 1))' out/proto-break.log
expect_rx "break-duplicate"   '\(refused break-binding [0-9]+ \(verb break\) \(detail "break id b1 is already in use"\)\)' out/proto-break.log
expect_rx "break-needs-filter" '\(refused parse [0-9]+ \(verb break\) \(detail "a break needs a relation, a rule, or a position to narrow it"\)\)' out/proto-break.log
expect_rx "break-needs-id"    '\(refused parse [0-9]+ \(verb break\) \(detail "requires \(id .*b1.*\)"\)\)' out/proto-break.log
expect_rx "break-position-rule" '\(refused parse [0-9]+ \(verb break\) \(detail "a body position belongs to a rule; give \(rule N\) too"\)\)' out/proto-break.log
expect    "break-rule-position" '(break-added (id "b4") (breaks 2))' out/proto-break.log
expect    "breaks-listed"     '(break (id "b1") (relation "edge") (rule #f) (position #f) (pattern "") (hits 0))' out/proto-break.log
expect    "breaks-end"        '(breaks-end 2)' out/proto-break.log
expect_rx "unbreak-unknown"   '\(refused break-binding [0-9]+ \(verb unbreak\) \(detail "no break with id b9"\)\)' out/proto-break.log
expect    "break-removed"     '(break-removed (id "b1") (breaks 1))' out/proto-break.log

# --- 3a. N3-A transaction + N3-B durable boundary history -------------------
# Prepare eagerly constructs an empty slot but keeps both its VersionKey and
# latest binding private. Ordinary catalog access is refused under the lease;
# commit publishes and advances generation. A successor can then be prepared
# and aborted without changing the committed key. N3-B indexes the committed
# boundary directly, retains it across abort/refusal, and attaches its key to
# catalog and binding-history records.
N3_DECL='(declare (qname "edge") (kind table) (arity 2) (type-key #f) (lat-spec #f) (shape "(declaration (qname \"edge\") table (fields int int))"))'
N3_PREPARE_0="(prepare-boundary (generation 0) (boundary \"n3.b0\") (program \"n3.p0\") (declarations $N3_DECL) (memberships) (actions (create (qname \"edge\") (version-key \"n3.edge.0\") (predecessor #f) (type-key #f))))"
N3_PREPARE_1="(prepare-boundary (generation 1) (boundary \"n3.b1\") (program \"n3.p1\") (declarations $N3_DECL) (memberships) (actions (create (qname \"edge\") (version-key \"n3.edge.1\") (predecessor \"n3.edge.0\") (type-key #f))))"
N3_PREPARE_2="(prepare-boundary (generation 1) (boundary \"n3.b2\") (program \"n3.p2\") (declarations $N3_DECL) (memberships) (actions (create (qname \"edge\") (version-key \"n3.edge.2\") (predecessor \"n3.edge.0\") (type-key #f))))"
N3_BAD="(prepare-boundary (generation 1) (boundary \"n3.bad\") (program \"n3.bad\") (declarations $N3_DECL) (memberships) (actions (create (qname \"edge\") (version-key \"n3.edge.bad\") (predecessor \"wrong\") (type-key #f))))"
N3_DUPLICATE="(prepare-boundary (generation 1) (boundary \"n3.b0\") (program \"n3.retry\") (declarations $N3_DECL) (memberships) (actions (retain (qname \"edge\") (version-key \"n3.edge.0\") (predecessor #f) (type-key #f))))"
QUERY_ROWS_SO=$(racket -e \
  '(require (file "compiler/actions.rkt"))
   (displayln
    (action-so
     (quote (add-batch edge -1
                       ((1 2) (2 2) (3 4) (4 2) (5 7) (6 2))))))')
racket tests/api/drive.rkt \
  "$N3_PREPARE_0" \
  '(catalog)' \
  '(commit-boundary (generation 0) (boundary "n3.b0"))' \
  '(catalog)' \
  '(catalog boundaries)' \
  '(catalog boundary "n3.b0")' \
  "$N3_PREPARE_1" \
  "$QUERY_ROWS_SO" \
  '(catalog types)' \
  '(abort-boundary (generation 1) (boundary "n3.b1"))' \
  '(catalog)' \
  '(catalog boundaries)' \
  "$N3_BAD" \
  "$N3_DUPLICATE" \
  '(catalog boundary "missing")' \
  '(catalog)' \
  "$N3_PREPARE_2" \
  "$QUERY_ROWS_SO" \
  '(commit-boundary (generation 1) (boundary "n3.b2"))' \
  '(catalog)' \
  '(catalog boundaries)' \
  '(catalog boundary "n3.b0")' \
  '(catalog boundary "n3.b2")' \
  > out/proto-n3-boundary.log 2>&1
expect_rx "n3-prepare-eager" '\(boundary-prepared 0 \(boundary "n3\.b0"\).* \(created 1\)\)' out/proto-n3-boundary.log
expect_rx "n3-private-admission" '\(refused boundary-admission 0 \(verb catalog\) \(boundary "n3\.b0"\)\)' out/proto-n3-boundary.log
expect_rx "n3-commit-generation" '\(boundary-committed 1 \(boundary "n3\.b0"\) \(position 0\) \(created 1\)\)' out/proto-n3-boundary.log
expect_rx "n3-commit-empty-slot" '\(catalog-rel \(name "edge"\).* \(version-key "n3\.edge\.0"\) \(boundary "n3\.b0"\).* \(size 0\)' out/proto-n3-boundary.log
expect "n3-boundary-history" '(catalog-boundary (boundary "n3.b0") (program "n3.p0") (evaluation "runtime-evaluation") (position 0) (generation 1) (relations 1))' out/proto-n3-boundary.log
expect_rx "n3-second-private-admission" '\(refused boundary-admission 1 \(verb catalog\) \(boundary "n3\.b1"\)\)' out/proto-n3-boundary.log
expect "n3-private-slot-mutable" '(added edge 6)' out/proto-n3-boundary.log
expect_rx "n3-abort" '\(boundary-aborted 1 \(boundary "n3\.b1"\).* \(discarded 1\)\)' out/proto-n3-boundary.log
if [ "$(grep -cE '\(catalog-rel \(name "edge"\).*\(version-key "n3.edge.0"\).*\(size 0\)' out/proto-n3-boundary.log)" -eq 5 ]; then
  ok "n3-abort-discards-private-content"; else bad "n3-abort-discards-private-content"; fi
expect_not "n3-abort-hides-successor" '(version-key "n3.edge.1")' out/proto-n3-boundary.log
expect_rx "n3-preflight-refusal" '\(refused boundary-binding 1 \(verb prepare-boundary\).*create predecessor does not match latest binding' out/proto-n3-boundary.log
expect_rx "n3-duplicate-boundary-refusal" '\(refused boundary-plan 1 \(verb prepare-boundary\).*BoundaryKey is already committed: n3\.b0' out/proto-n3-boundary.log
expect_rx "n3-unknown-boundary-refusal" '\(refused boundary-lookup 1 \(verb catalog\) \(boundary "missing"\)\)' out/proto-n3-boundary.log
if [ "$(grep -cF '(catalog-boundary (boundary "n3.b0")' out/proto-n3-boundary.log)" -eq 3 ]; then
  ok "n3-abort-preserves-history"; else bad "n3-abort-preserves-history"; fi
expect "n3-successor-history" '(catalog-boundary (boundary "n3.b2") (program "n3.p2") (evaluation "runtime-evaluation") (position 1) (generation 2) (relations 1))' out/proto-n3-boundary.log
expect_rx "n3-current-successor" '\(catalog-rel \(name "edge"\).*\(version-key "n3\.edge\.2"\) \(boundary "n3\.b2"\).*\(size 6\)' out/proto-n3-boundary.log
# R2: the catalog reports each relation's materialized full-index orders --
# the runtime fact the Q1 planner schedules over (t0-contract.md).
expect_rx "n3-catalog-orders" '\(catalog-rel \(name "edge"\).*\(version-key "n3\.edge\.2"\).*\(orders \(\(0 1\)\)\) \(temp #f\)\)' out/proto-n3-boundary.log
expect_rx "n3-direct-historical-lookup" '\(catalog-rel \(name "edge"\).*\(version-key "n3\.edge\.0"\) \(boundary "n3\.b0"\).*\(size 0\)' out/proto-n3-boundary.log
if [ "$(grep -c '(catalog-end ' out/proto-n3-boundary.log)" -eq 10 ]; then
  ok "n3-refusal-leaves-no-lease"; else bad "n3-refusal-leaves-no-lease"; fi
if racket tests/api/catalog-check.rkt rel=edge,table,2 \
     < out/proto-n3-boundary.log; then
  ok "n3-boundary-stream-round-trip"
else
  bad "n3-boundary-stream-round-trip"
fi

# --- 3a. N3-C durable type descriptors and lowest-free SIDs ----------------
N3C_OLD_DECL='(declare (qname "old_const") (kind struct) (arity 2) (type-key "type:n3c:old") (lat-spec #f) (shape "(declaration old_const struct int)"))'
N3C_OLD_0="(prepare-boundary (generation 0) (boundary \"n3c.old.0\") (program \"n3c.old.p0\") (declarations $N3C_OLD_DECL) (memberships) (actions (create (qname \"old_const\") (version-key \"n3c.old.v0\") (predecessor #f) (type-key \"type:n3c:old\"))))"
N3C_OLD_1="(prepare-boundary (generation 1) (boundary \"n3c.old.1\") (program \"n3c.old.p1\") (declarations $N3C_OLD_DECL) (memberships) (actions (create (qname \"old_const\") (version-key \"n3c.old.v1\") (predecessor \"n3c.old.v0\") (type-key \"type:n3c:old\"))))"
N3C_FRESH_DECL='(declare (qname "fresh_const") (kind struct) (arity 2) (type-key "type:n3c:fresh") (lat-spec #f) (shape "(declaration fresh_const struct int)"))'
N3C_FRESH="(prepare-boundary (generation 2) (boundary \"n3c.fresh\") (program \"n3c.fresh.p\") (declarations $N3C_FRESH_DECL) (memberships) (actions (create (qname \"fresh_const\") (version-key \"n3c.fresh.v0\") (predecessor #f) (type-key \"type:n3c:fresh\"))))"
N3C_ABORT_DECL='(declare (qname "abort_const") (kind struct) (arity 2) (type-key "type:n3c:abort") (lat-spec #f) (shape "(declaration abort_const struct int)"))'
N3C_ABORT="(prepare-boundary (generation 3) (boundary \"n3c.abort\") (program \"n3c.abort.p\") (declarations $N3C_FRESH_DECL $N3C_ABORT_DECL) (memberships) (actions (retain (qname \"fresh_const\") (version-key \"n3c.fresh.v0\") (predecessor #f) (type-key \"type:n3c:fresh\")) (create (qname \"abort_const\") (version-key \"n3c.abort.v0\") (predecessor #f) (type-key \"type:n3c:abort\"))))"
N3C_FINAL_DECL='(declare (qname "final_const") (kind struct) (arity 2) (type-key "type:n3c:final") (lat-spec #f) (shape "(declaration final_const struct int)"))'
N3C_FINAL="(prepare-boundary (generation 3) (boundary \"n3c.final\") (program \"n3c.final.p\") (declarations $N3C_FRESH_DECL $N3C_FINAL_DECL) (memberships) (actions (retain (qname \"fresh_const\") (version-key \"n3c.fresh.v0\") (predecessor #f) (type-key \"type:n3c:fresh\")) (create (qname \"final_const\") (version-key \"n3c.final.v0\") (predecessor #f) (type-key \"type:n3c:final\"))))"
N3C_RENAME_SO=$(racket -e \
  '(require (file "compiler/actions.rkt"))
   (displayln (action-so (quote (rename-rel old_const renamed_const))))')
N3C_DROP_SO=$(racket -e \
  '(require (file "compiler/actions.rkt"))
   (displayln (action-so (quote (drop-rel renamed_const))))')
racket tests/api/drive.rkt \
  "$N3C_OLD_0" \
  '(commit-boundary (generation 0) (boundary "n3c.old.0"))' \
  '(catalog types)' \
  "$N3C_OLD_1" \
  '(commit-boundary (generation 1) (boundary "n3c.old.1"))' \
  '(catalog types)' \
  "$N3C_RENAME_SO" \
  '(catalog types)' \
  "$N3C_DROP_SO" \
  '(catalog types)' \
  "$N3C_FRESH" \
  '(commit-boundary (generation 2) (boundary "n3c.fresh"))' \
  '(catalog types)' \
  "$N3C_ABORT" \
  '(abort-boundary (generation 3) (boundary "n3c.abort"))' \
  '(catalog types)' \
  "$N3C_FINAL" \
  '(commit-boundary (generation 3) (boundary "n3c.final"))' \
  '(catalog types)' \
  > out/proto-n3c-types.log 2>&1
expect "n3c-initial-descriptor" \
  '(catalog-type (sid 1) (name "old_const") (arity 2) (type-key "type:n3c:old"))' \
  out/proto-n3c-types.log
expect "n3c-rename-preserves-descriptor" \
  '(catalog-type (sid 1) (name "renamed_const") (arity 2) (type-key "type:n3c:old"))' \
  out/proto-n3c-types.log
expect "n3c-drop-retains-unnamed-descriptor" \
  '(catalog-type (sid 1) (name #f) (arity 2) (type-key "type:n3c:old"))' \
  out/proto-n3c-types.log
expect "n3c-drop-redeclare-fresh-sid" \
  '(catalog-type (sid 2) (name "fresh_const") (arity 2) (type-key "type:n3c:fresh"))' \
  out/proto-n3c-types.log
expect_not "n3c-abort-hides-typekey" 'type:n3c:abort' out/proto-n3c-types.log
expect "n3c-abort-burns-sid" \
  '(catalog-type (sid 4) (name "final_const") (arity 2) (type-key "type:n3c:final"))' \
  out/proto-n3c-types.log
if racket tests/api/catalog-check.rkt types'>='3 \
     < out/proto-n3c-types.log; then
  ok "n3c-type-stream-round-trip"
else
  bad "n3c-type-stream-round-trip"
fi

# --- 3a'. N3-D qualified-path transforms ------------------------------------
# rename-path / drop-path are single-shot atomic environment events over ONE
# structured path syntax (modules.md §5.3): the environment decides leaf vs
# namespace, the whole subtree rebinds at one position under a fresh
# successor BoundaryKey, VersionKeys and physical storage never move, and
# committed snapshots keep resolving the old names.  The daemon verifies the
# sent catalog is exactly the mechanical rewrite of the current one.
ND_DECL_X="(declare (qname \"x\" \"edge\") (kind table) (arity 2) (type-key #f) (lat-spec #f) (shape \"s\")) (declare (qname \"x\" \"aux\") (kind table) (arity 1) (type-key #f) (lat-spec #f) (shape \"s\")) (declare (qname \"keep\") (kind table) (arity 1) (type-key #f) (lat-spec #f) (shape \"s\"))"
ND_DECL_Y="(declare (qname \"y\" \"edge\") (kind table) (arity 2) (type-key #f) (lat-spec #f) (shape \"s\")) (declare (qname \"y\" \"aux\") (kind table) (arity 1) (type-key #f) (lat-spec #f) (shape \"s\")) (declare (qname \"keep\") (kind table) (arity 1) (type-key #f) (lat-spec #f) (shape \"s\"))"
ND_DECL_KEEP="(declare (qname \"keep\") (kind table) (arity 1) (type-key #f) (lat-spec #f) (shape \"s\"))"
ND_PREPARE="(prepare-boundary (generation 0) (boundary \"nd.b0\") (program \"nd.p0\") (declarations $ND_DECL_X) (memberships) (actions (create (qname \"x\" \"edge\") (version-key \"nd.v.edge\") (predecessor #f) (type-key #f)) (create (qname \"x\" \"aux\") (version-key \"nd.v.aux\") (predecessor #f) (type-key #f)) (create (qname \"keep\") (version-key \"nd.v.keep\") (predecessor #f) (type-key #f))))"
ND_RENAME="(rename-path (generation 1) (boundary \"nd.r1\") (from (qname \"x\")) (to (qname \"y\")) (declarations $ND_DECL_Y) (memberships))"
ND_DROP="(drop-path (generation 2) (boundary \"nd.d2\") (path (qname \"y\")) (declarations $ND_DECL_KEEP) (memberships))"
ND_REDECLARE="(prepare-boundary (generation 3) (boundary \"nd.b3\") (program \"nd.p3\") (declarations (declare (qname \"x\" \"edge\") (kind table) (arity 2) (type-key #f) (lat-spec #f) (shape \"s\")) $ND_DECL_KEEP) (memberships) (actions (create (qname \"x\" \"edge\") (version-key \"nd.v.edge2\") (predecessor #f) (type-key #f)) (retain (qname \"keep\") (version-key \"nd.v.keep\") (predecessor #f) (type-key #f))))"
racket tests/api/drive.rkt \
  "$ND_PREPARE" \
  '(commit-boundary (generation 0) (boundary "nd.b0"))' \
  "$ND_RENAME" \
  '(catalog)' \
  '(catalog boundaries)' \
  '(catalog boundary "nd.b0")' \
  "$ND_DROP" \
  '(catalog)' \
  '(catalog boundary "nd.r1")' \
  "$ND_REDECLARE" \
  '(commit-boundary (generation 3) (boundary "nd.b3"))' \
  '(catalog)' \
  > out/proto-nd-transform.log 2>&1
expect "nd-rename-atomic" \
  '(path-renamed 2 (from "x") (to "y") (boundary "nd.r1") (position 1) (rebound 2))' \
  out/proto-nd-transform.log
expect_rx "nd-rename-versionkey-stable" \
  '\(catalog-rel \(name "y\.edge"\).*\(version-key "nd\.v\.edge"\) \(boundary "nd\.r1"\)' \
  out/proto-nd-transform.log
expect_rx "nd-rename-untouched-binding" \
  '\(catalog-rel \(name "keep"\).*\(version-key "nd\.v\.keep"\) \(boundary "nd\.b0"\)' \
  out/proto-nd-transform.log
expect_rx "nd-history-resolves-old-name" \
  '\(catalog-rel \(name "x\.edge"\).*\(version-key "nd\.v\.edge"\)' \
  out/proto-nd-transform.log
expect "nd-drop-atomic" \
  '(path-dropped 3 (path "y") (boundary "nd.d2") (position 2) (unbound 2))' \
  out/proto-nd-transform.log
expect_rx "nd-drop-redeclare-fresh-chain" \
  '\(catalog-rel \(name "x\.edge"\).*\(version-key "nd\.v\.edge2"\) \(boundary "nd\.b3"\)' \
  out/proto-nd-transform.log
if [ "$(grep -cE '\(catalog-boundary \(boundary "nd\.(b0|r1)"\)' out/proto-nd-transform.log)" -ge 2 ]; then
  ok "nd-transform-boundaries-listed"
else
  bad "nd-transform-boundaries-listed"
fi

# History coherence (sub-slice (d)): Q1 binds through transform-minted
# boundaries exactly as through committed program boundaries -- the renamed
# name resolves in the successor snapshot, the OLD name resolves in the
# historical snapshot under the SAME VersionKey, and the old name inside the
# successor snapshot refuses.  A struct's SID and TypeKey survive the
# subtree rename (§11.17), and a key freed by an aborted prepare is reusable
# by a transform (N3-A key doctrine).
NDQ_DECL="(declare (qname \"x\" \"edge\") (kind table) (arity 2) (type-key #f) (lat-spec #f) (shape \"s\")) (declare (qname \"x\" \"pt\") (kind struct) (arity 2) (type-key \"type:ndq:pt\") (lat-spec #f) (shape \"s\"))"
NDQ_DECL_Y="(declare (qname \"y\" \"edge\") (kind table) (arity 2) (type-key #f) (lat-spec #f) (shape \"s\")) (declare (qname \"y\" \"pt\") (kind struct) (arity 2) (type-key \"type:ndq:pt\") (lat-spec #f) (shape \"s\"))"
NDQ_PREPARE="(prepare-boundary (generation 0) (boundary \"ndq.b0\") (program \"ndq.p0\") (declarations $NDQ_DECL) (memberships) (actions (create (qname \"x\" \"edge\") (version-key \"ndq.v.edge\") (predecessor #f) (type-key #f)) (create (qname \"x\" \"pt\") (version-key \"ndq.v.pt\") (predecessor #f) (type-key \"type:ndq:pt\"))))"
NDQ_ROWS_SO=$(racket -e \
  '(require (file "compiler/actions.rkt"))
   (displayln
    (action-so
     (quote (add-batch x.edge -1
                       ((1 2) (2 2) (3 4) (4 2) (5 7) (6 2))))))')
NDQ_LEASE="(prepare-boundary (generation 1) (boundary \"ndq.freed\") (program \"ndq.lp\") (declarations $NDQ_DECL) (memberships) (actions (retain (qname \"x\" \"edge\") (version-key \"ndq.v.edge\") (predecessor #f) (type-key #f)) (retain (qname \"x\" \"pt\") (version-key \"ndq.v.pt\") (predecessor #f) (type-key \"type:ndq:pt\"))))"
NDQ_RENAME="(rename-path (generation 1) (boundary \"ndq.freed\") (from (qname \"x\")) (to (qname \"y\")) (declarations $NDQ_DECL_Y) (memberships))"
NDQ_NEW_PLAN='(query-plan (abi 1) (at (boundary "ndq.freed") (generation 2)) (relations (rel 0 (binding "y.edge" "ndq.v.edge" 6) (relation 2 (0 1)))) (registers 3) (preloads) (literals (literal (r 1) integer "2")) (pre) (driver (scan-full (rel 0) (0 1) (r 0) (r 2))) (body (eq (r 2) (r 1))) (project (r 0)) (mode count))'
NDQ_OLD_PLAN='(query-plan (abi 1) (at (boundary "ndq.b0") (generation 2)) (relations (rel 0 (binding "x.edge" "ndq.v.edge" 6) (relation 2 (0 1)))) (registers 3) (preloads) (literals (literal (r 1) integer "2")) (pre) (driver (scan-full (rel 0) (0 1) (r 0) (r 2))) (body (eq (r 2) (r 1))) (project (r 0)) (mode count))'
NDQ_STALE_NAME_PLAN='(query-plan (abi 1) (at (boundary "ndq.freed") (generation 2)) (relations (rel 0 (binding "x.edge" "ndq.v.edge" 6) (relation 2 (0 1)))) (registers 3) (preloads) (literals (literal (r 1) integer "2")) (pre) (driver (scan-full (rel 0) (0 1) (r 0) (r 2))) (body (eq (r 2) (r 1))) (project (r 0)) (mode count))'
racket tests/api/drive.rkt \
  "$NDQ_PREPARE" \
  "$NDQ_ROWS_SO" \
  '(commit-boundary (generation 0) (boundary "ndq.b0"))' \
  "$NDQ_LEASE" \
  '(abort-boundary (generation 1) (boundary "ndq.freed"))' \
  "$NDQ_RENAME" \
  "(query q1 $NDQ_NEW_PLAN (page 100))" \
  "(query q2 $NDQ_OLD_PLAN (page 100))" \
  "(query q3 $NDQ_STALE_NAME_PLAN (page 100))" \
  '(catalog types)' \
  > out/proto-nd-q1.log 2>&1
expect_rx "nd-q1-abort-frees-transform-key" \
  '\(path-renamed 2 \(from "x"\) \(to "y"\) \(boundary "ndq\.freed"\)' \
  out/proto-nd-q1.log
expect_rx "nd-q1-new-name-binds" \
  '\(query-end q1 .*\(matched 4\)' out/proto-nd-q1.log
expect_rx "nd-q1-old-boundary-old-name-binds" \
  '\(query-end q2 .*\(matched 4\)' out/proto-nd-q1.log
expect_rx "nd-q1-stale-name-refused" \
  '\(refused query-binding [0-9]+ \(verb query\) \(query q3\)' out/proto-nd-q1.log
expect "nd-typekey-survives-rename" \
  '(catalog-type (sid 1) (name "y.pt") (arity 2) (type-key "type:ndq:pt"))' \
  out/proto-nd-q1.log

# Subtree selection (§5.3 "inspecting X selects the subtree"): a trailing
# structured qname narrows the current and historical catalog streams to the
# exact member or its nested descendants.  Counts are exact, so the filtered
# record totals pin both inclusion and exclusion.
NDC_PREPARE="(prepare-boundary (generation 0) (boundary \"ndc.b0\") (program \"ndc.p0\") (declarations $ND_DECL_X) (memberships) (actions (create (qname \"x\" \"edge\") (version-key \"ndc.v.edge\") (predecessor #f) (type-key #f)) (create (qname \"x\" \"aux\") (version-key \"ndc.v.aux\") (predecessor #f) (type-key #f)) (create (qname \"keep\") (version-key \"ndc.v.keep\") (predecessor #f) (type-key #f))))"
racket tests/api/drive.rkt \
  "$NDC_PREPARE" \
  '(commit-boundary (generation 0) (boundary "ndc.b0"))' \
  '(catalog relations (qname "x"))' \
  '(catalog boundary "ndc.b0" (qname "x"))' \
  '(catalog relations (qname "keep"))' \
  '(catalog relations bogus)' \
  > out/proto-nd-filter.log 2>&1
if [ "$(grep -c '(catalog-rel (name "x\.' out/proto-nd-filter.log)" -eq 4 ] \
   && [ "$(grep -c '(catalog-rel (name "keep")' out/proto-nd-filter.log)" -eq 1 ]; then
  ok "nd-filter-subtree-selects"
else
  bad "nd-filter-subtree-selects"
fi
if [ "$(grep -o '(catalog-end [0-9]*)' out/proto-nd-filter.log | tr -d '\n')" \
     = "(catalog-end 2)(catalog-end 2)(catalog-end 1)" ]; then
  ok "nd-filter-exact-counts"
else
  bad "nd-filter-exact-counts"
fi
expect_rx "nd-filter-malformed" \
  '\(refused parse [0-9]+ \(verb catalog\) \(detail "subtree filter' \
  out/proto-nd-filter.log

# Refusal side: nothing may mutate on a refused transform, referential
# integrity holds for memberships, and the lease/generation gates apply.
NDB_DECL="(declare (qname \"x\" \"edge\") (kind table) (arity 2) (type-key #f) (lat-spec #f) (shape \"s\")) (declare (qname \"keep\") (kind table) (arity 1) (type-key #f) (lat-spec #f) (shape \"s\")) (declare (qname \"hull\") (kind union) (arity #f) (type-key #f) (lat-spec #f) (shape \"s\"))"
NDB_DECL_Y="(declare (qname \"y\" \"edge\") (kind table) (arity 2) (type-key #f) (lat-spec #f) (shape \"s\")) (declare (qname \"keep\") (kind table) (arity 1) (type-key #f) (lat-spec #f) (shape \"s\")) (declare (qname \"hull\") (kind union) (arity #f) (type-key #f) (lat-spec #f) (shape \"s\"))"
NDB_DECL_Y_BAD="(declare (qname \"y\" \"edge\") (kind table) (arity 3) (type-key #f) (lat-spec #f) (shape \"s\")) (declare (qname \"keep\") (kind table) (arity 1) (type-key #f) (lat-spec #f) (shape \"s\")) (declare (qname \"hull\") (kind union) (arity #f) (type-key #f) (lat-spec #f) (shape \"s\"))"
NDB_MEMBER='(member (qname "x" "edge") (qname "hull"))'
NDB_MEMBER_Y='(member (qname "y" "edge") (qname "hull"))'
NDB_PREPARE="(prepare-boundary (generation 0) (boundary \"ndb.b0\") (program \"ndb.p0\") (declarations $NDB_DECL) (memberships $NDB_MEMBER) (actions (create (qname \"x\" \"edge\") (version-key \"ndb.v.edge\") (predecessor #f) (type-key #f)) (create (qname \"keep\") (version-key \"ndb.v.keep\") (predecessor #f) (type-key #f))))"
NDB_LEASE="(prepare-boundary (generation 2) (boundary \"ndb.lease\") (program \"ndb.lp\") (declarations $NDB_DECL_Y) (memberships $NDB_MEMBER_Y) (actions (retain (qname \"y\" \"edge\") (version-key \"ndb.v.edge\") (predecessor #f) (type-key #f)) (retain (qname \"keep\") (version-key \"ndb.v.keep\") (predecessor #f) (type-key #f))))"
racket tests/api/drive.rkt \
  "$NDB_PREPARE" \
  '(commit-boundary (generation 0) (boundary "ndb.b0"))' \
  "(rename-path (generation 0) (boundary \"ndb.stale\") (from (qname \"x\")) (to (qname \"y\")) (declarations $NDB_DECL_Y) (memberships $NDB_MEMBER_Y))" \
  "(rename-path (generation 1) (boundary \"ndb.r\") (from (qname \"z\")) (to (qname \"w\")) (declarations $NDB_DECL) (memberships $NDB_MEMBER))" \
  "(rename-path (generation 1) (boundary \"ndb.r\") (from (qname \"x\")) (to (qname \"keep\")) (declarations $NDB_DECL) (memberships $NDB_MEMBER))" \
  "(rename-path (generation 1) (boundary \"ndb.r\") (from (qname \"x\")) (to (qname \"x\" \"sub\")) (declarations $NDB_DECL) (memberships $NDB_MEMBER))" \
  "(rename-path (generation 1) (boundary \"ndb.r\") (from (qname \"x\")) (to (qname \"y\")) (declarations $NDB_DECL_Y_BAD) (memberships $NDB_MEMBER_Y))" \
  "(rename-path (generation 1) (boundary \"ndb.r\") (from (qname \"x\")) (to (qname \"y\")) (declarations $NDB_DECL_Y) (memberships $NDB_MEMBER))" \
  "(drop-path (generation 1) (boundary \"ndb.d\") (path (qname \"x\")) (declarations (declare (qname \"keep\") (kind table) (arity 1) (type-key #f) (lat-spec #f) (shape \"s\")) (declare (qname \"hull\") (kind union) (arity #f) (type-key #f) (lat-spec #f) (shape \"s\"))) (memberships))" \
  '(catalog)' \
  "(rename-path (generation 1) (boundary \"ndb.r1\") (from (qname \"x\")) (to (qname \"y\")) (declarations $NDB_DECL_Y) (memberships $NDB_MEMBER_Y))" \
  "$NDB_LEASE" \
  "(rename-path (generation 2) (boundary \"ndb.r2\") (from (qname \"y\")) (to (qname \"z\")) (declarations $NDB_DECL) (memberships $NDB_MEMBER))" \
  '(abort-boundary (generation 2) (boundary "ndb.lease"))' \
  > out/proto-nd-refuse.log 2>&1
expect_rx "nd-refuse-stale-generation" \
  '\(refused stale-generation .*rename-path' out/proto-nd-refuse.log
expect_rx "nd-refuse-unknown-path" \
  '\(refused transform-plan .*path is unbound: z' out/proto-nd-refuse.log
expect_rx "nd-refuse-target-bound" \
  '\(refused transform-plan .*already bound: keep' out/proto-nd-refuse.log
expect_rx "nd-refuse-self-capture" \
  '\(refused transform-plan .*inside the renamed subtree' out/proto-nd-refuse.log
expect_rx "nd-refuse-abi-drift" \
  '\(refused transform-plan .*ABI changed across the transform: y\.edge' \
  out/proto-nd-refuse.log
expect_rx "nd-refuse-unrewritten-membership" \
  '\(refused transform-plan .*memberships do not match' out/proto-nd-refuse.log
expect_rx "nd-refuse-dangling-membership" \
  '\(refused transform-plan .*hull retains a membership' out/proto-nd-refuse.log
expect_rx "nd-refusals-left-env-intact" \
  '\(catalog-rel \(name "x\.edge"\).*\(version-key "ndb\.v\.edge"\) \(boundary "ndb\.b0"\)' \
  out/proto-nd-refuse.log
expect "nd-membership-rewrites" \
  '(path-renamed 2 (from "x") (to "y") (boundary "ndb.r1") (position 1) (rebound 1))' \
  out/proto-nd-refuse.log
expect_rx "nd-refuse-under-lease" \
  '\(refused boundary-admission [0-9]+ \(verb rename-path\)' \
  out/proto-nd-refuse.log

# --- 3b. Q1 canonical payload dispatcher ------------------------------------
# The canonical payload now resolves through a real committed BoundaryKey.
# QName selects one binding within that immutable snapshot and its supplied
# VersionKey must match; neither an unknown key nor a cross-boundary key can
# fall back to the latest name map.
QUERY_PREPARE="(prepare-boundary (generation 0) (boundary \"query.boundary\") (program \"query.program\") (declarations $N3_DECL) (memberships) (actions (create (qname \"edge\") (version-key \"protocol.edge\") (predecessor #f) (type-key #f))))"
QUERY_SETUP=(
  "$QUERY_PREPARE"
  "$QUERY_ROWS_SO"
  '(commit-boundary (generation 0) (boundary "query.boundary"))'
)
QUERY_ROWS_PLAN='(query-plan (abi 1) (at (boundary "query.boundary") (generation 1)) (relations (rel 0 (binding "edge" "protocol.edge" 6) (relation 2 (0 1)))) (registers 3) (preloads) (literals (literal (r 1) integer "2")) (pre) (driver (scan-full (rel 0) (0 1) (r 0) (r 2))) (body (eq (r 2) (r 1))) (project (r 0)) (mode rows))'
QUERY_MISS_PLAN='(query-plan (abi 1) (at (boundary "query.boundary") (generation 1)) (relations (rel 0 (binding "edge" "protocol.edge" 6) (relation 2 (0 1)))) (registers 3) (preloads) (literals (literal (r 1) string "not-in-heap")) (pre) (driver (scan-full (rel 0) (0 1) (r 0) (r 2))) (body (eq (r 2) (r 1))) (project (r 0)) (mode rows))'
QUERY_COUNT_PLAN="${QUERY_ROWS_PLAN/(project (r 0)) (mode rows)/(project) (mode count)}"
QUERY_EXISTS_PLAN="${QUERY_ROWS_PLAN/(project (r 0)) (mode rows)/(project) (mode exists)}"
QUERY_BUILDER=(
  '(scc-begin qs0 (generation 1) (kernel-plan (sidecar "tests/data/t0-normal-set.plan")))'
  '(scc-seal qs0 (generation 1))'
  '(stratum-begin qst0 (generation 1) (entry fresh))'
  '(stratum-add-scc qst0 qs0 (generation 1))'
  '(stratum-seal qst0 (generation 1))'
  '(continue)'
)

if racket tests/api/drive.rkt "${QUERY_SETUP[@]}" "${QUERY_BUILDER[@]}" \
  "(query q1 $QUERY_ROWS_PLAN (page 2))" \
  '(query-page q1 (page 2))' \
  '(query-page q1 (page 2))' \
  '(query-page q1 (page 2))' \
  "(query q2 $QUERY_ROWS_PLAN (page 1))" \
  "(query q3 $QUERY_ROWS_PLAN (page 1))" \
  '(continue)' \
  "$QUERY_ROWS_SO" \
  '(catalog)' \
  '(query-cancel q2)' \
  '(query-page q2 (page 1))' \
  "(query q3 $QUERY_MISS_PLAN (page 5))" \
  "(query q4 $QUERY_ROWS_PLAN (page 10))" \
  "(query qcount $QUERY_COUNT_PLAN (page 1))" \
  "(query qexists $QUERY_EXISTS_PLAN (page 1))" \
  "(query stale ${QUERY_ROWS_PLAN/(generation 1)/(generation 2)} (page 1))" \
  "(query wrong ${QUERY_ROWS_PLAN/protocol.edge/protocol.wrong} (page 1))" \
  "(query unknown ${QUERY_ROWS_PLAN/query.boundary/query.missing} (page 1))" \
  '(query malformed (not-a-query-plan) (page 1))' \
  "(query badpage $QUERY_ROWS_PLAN (page 0))" \
  '(query-cancel absent)' \
  "(query qdeep $QUERY_ROWS_PLAN (page 10) (depth 1))" \
  "(query baddepth $QUERY_ROWS_PLAN (page 1) (depth 0))" \
  '(describe-value 9218868471587143682)' \
  '(describe-value)' \
  '(uses (word 9218868471587143682))' \
  '(uses (string "not-in-heap"))' \
  '(uses (frob 1))' \
  "(query q5 $QUERY_ROWS_PLAN (page 1))" \
  > out/proto-query.log 2>&1; then
  ok "query-eof-releases-lease"
else
  bad "query-eof-releases-lease"
fi

if racket tests/api/query-check.rkt < out/proto-query.log; then
  ok "query-structured-pagination"; else bad "query-structured-pagination"; fi
# R2 cells: each projected column is one value-adapter cell record -- word,
# kind, sid, type-key, and the boundary-aware text preview -- never a bare
# string the client would have to re-parse.
expect_rx "query-cells-shape" \
  '\(query-row q1 \(cells \(cell \(word [0-9]+\) \(kind int\) \(sid #f\) \(type-key #f\) \(text "1"\)\)\)\)' \
  out/proto-query.log
expect_rx "query-depth-refusal" \
  '\(refused parse 1 \(verb query\) \(detail "expected \(depth N\) with N in 1\.\.4096"\)\)' \
  out/proto-query.log
# R2 deep view: (describe-value WORD [(depth N)]) re-renders one
# evaluation-local word as a bare cell record (line-anchored: query rows
# embed the same cell inside (query-row ...)).
expect_rx "describe-value-cell" \
  '^\(cell \(word 9218868471587143682\) \(kind int\) \(sid #f\) \(type-key #f\) \(text "2"\)\)' \
  out/proto-query.log
expect_rx "describe-value-parse" \
  '\(refused parse 1 \(verb describe-value\) \(detail "expected \(describe-value WORD \[\(depth N\)\]\)"\)\)' \
  out/proto-query.log
# R2 value search: (uses SPEC) walks every latest user relation's master
# index for one probe-resolved value; a probe miss appears nowhere.
expect_rx "uses-known-value" \
  '\(uses-rel \(name "edge"\) \(version-key "protocol.edge"\) \(count [1-9][0-9]*\)\)' \
  out/proto-query.log
expect_rx "uses-probe-miss" \
  '\(uses-end \(relations 0\) \(rows 0\)\)' \
  out/proto-query.log
expect_rx "uses-parse" \
  '\(refused parse 1 \(verb uses\)' \
  out/proto-query.log
expect_rx "query-active-admission" \
  '\(refused query-admission 1 \(verb query\) \(query q3\) \(active q2\)\)' \
  out/proto-query.log
expect_rx "query-blocks-continue-mutation" \
  '\(refused query-admission 1 \(verb continue\) \(active q2\)\)' \
  out/proto-query.log
expect_rx "query-blocks-path-mutation" \
  '\(refused query-admission 1 \(verb plugin-path\) \(active q2\)\)' \
  out/proto-query.log
expect_rx "query-blocks-command-interleave" \
  '\(refused query-admission 1 \(verb catalog\) \(active q2\)\)' \
  out/proto-query.log
if [ "$(grep -cF '(refused query-state ' out/proto-query.log)" -eq 3 ]; then
  ok "query-terminal-state-count"; else bad "query-terminal-state-count"; fi
expect_rx "query-stale-generation" \
  '\(refused stale-generation 1 \(verb query\) \(expected 2\)\)' \
  out/proto-query.log
expect_rx "query-exact-version-binding" \
  '\(refused query-binding 1 \(verb query\) \(query wrong\)' \
  out/proto-query.log
expect_rx "query-boundary-binding" \
  '\(refused query-binding 1 \(verb query\) \(query unknown\).*BoundaryKey is not committed' \
  out/proto-query.log
expect_rx "query-payload-parse" \
  '\(refused query-parse 1 \(verb query\) \(query malformed\)' \
  out/proto-query.log
expect_rx "query-page-policy" \
  '\(refused query-pagination 1 \(verb query\) \(page 0\)' \
  out/proto-query.log
expect_rx "query-eof-page-before-release" \
  '\(query-end q5 page \(rows 1\) \(matched 1\)\)' \
  out/proto-query.log
expect_not "query-no-reserved-fallback" '(family query)' out/proto-query.log

# The active record stream crosses the same byte-level dispatcher on stdin and
# TCP, not merely the query refusal branch exercised by the broader parity
# script below.
QUERY_PARITY=(
  "${QUERY_SETUP[@]}"
  "${QUERY_BUILDER[@]}"
  "(query qp $QUERY_ROWS_PLAN (page 10))"
)
racket tests/api/drive.rkt     "${QUERY_PARITY[@]}" > out/proto-query-stdin.log 2>&1
racket tests/api/tcp-drive.rkt "${QUERY_PARITY[@]}" > out/proto-query-tcp.log   2>&1
grep -v -e '^(fixpoint ' out/proto-query-stdin.log \
  > out/proto-query-stdin-normal.log
grep -v -e '^(pending)$' -e '^(bye ' out/proto-query-tcp.log \
  | grep -v -e '^(fixpoint ' > out/proto-query-tcp-normal.log
if diff -u out/proto-query-stdin-normal.log out/proto-query-tcp-normal.log \
     > out/proto-query-parity.diff; then
  ok "query-tcp-stdin-stream-parity"
else
  cat out/proto-query-parity.diff
  bad "query-tcp-stdin-stream-parity"
fi

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

# --- 5b. T0(d) uniform command-stack pause record ----------------------------
# The pure wire formatter has one checked-in transcript corpus covering budget,
# requested-boundary, terminal-prepared, and future watch-citation causes. The
# test binary reparses every rendered record through the shared bounded reader
# and also refuses an empty watch citation.
if "$CXX" -O2 -Wall -std=c++20 -Idaemon tests/protocol-record-tests.cpp \
     daemon/sexp.cpp -o build/protocol-record-tests \
   && build/protocol-record-tests > out/proto-pause-records.log \
   && diff -u tests/data/t0-pause-records.txt out/proto-pause-records.log \
        > out/proto-pause-records.diff; then
  ok "pause-record-cause-goldens"
else
  cat out/proto-pause-records.diff 2>/dev/null || true
  bad "pause-record-cause-goldens"
fi

# --- 5c. T0(b) provisional SCC/stratum lifecycle ----------------------------
# ABI 1 adapts one canonical sidecar into one sealed SCC. The stratum object
# is separately begun, populated, and sealed; sealing installs but never runs
# it, so the following (continue) is an observable client-owned transition.
BUILDER=(
  '(scc-begin s0 (generation 0) (kernel-plan (sidecar "tests/data/t0-normal-set.plan")))'
  '(scc-seal s0 (generation 0))'
  '(stratum-begin st0 (generation 0) (entry fresh))'
  '(stratum-add-scc st0 s0 (generation 0))'
  '(stratum-seal st0 (generation 0))'
)
racket tests/api/drive.rkt "${BUILDER[@]}" > out/proto-builder-no-run.log 2>&1
if [ "$(grep -cF '(accepted ' out/proto-builder-no-run.log)" -eq 5 ]; then
  ok "builder-every-mutation-acked"; else bad "builder-every-mutation-acked"; fi
expect_not "builder-seal-does-not-continue" '(fixpoint ' out/proto-builder-no-run.log

# A new connection can reuse every object id: connection loss discarded the
# prior session's builder store. This run then crosses the real installer,
# continue loop, and catalog through commands only.
racket tests/api/drive.rkt "${BUILDER[@]}" '(continue)' '(catalog)' \
  > out/proto-builder-run.log 2>&1
expect "builder-scc-begin-ack" '(accepted scc-begin 0 (scc s0))' out/proto-builder-run.log
expect "builder-stratum-seal-ack" '(accepted stratum-seal 0 (stratum st0) (scc s0))' out/proto-builder-run.log
expect_rx "builder-run-fixpoint" '^\(fixpoint ' out/proto-builder-run.log
expect_rx "builder-run-catalog" '^\(catalog-rel \(name "node"\)' out/proto-builder-run.log
expect_not "builder-run-no-error" '(error' out/proto-builder-run.log

# Every builder mutation is generation-gated before object-state admission.
GEN_SCRIPT=(
  '(scc-begin stale (generation 1) (kernel-plan (sidecar "tests/data/t0-normal-set.plan")))'
  '(scc-begin sg (generation 0) (kernel-plan (sidecar "tests/data/t0-normal-set.plan")))'
  '(scc-seal sg (generation 1))'
  '(scc-seal sg (generation 0))'
  '(stratum-begin stale-st (generation 1) (entry fresh))'
  '(stratum-begin gst (generation 0) (entry fresh))'
  '(stratum-add-scc gst sg (generation 1))'
  '(stratum-add-scc gst sg (generation 0))'
  '(stratum-seal gst (generation 1))'
)
racket tests/api/drive.rkt "${GEN_SCRIPT[@]}" > out/proto-builder-generation.log 2>&1
for v in scc-begin scc-seal stratum-begin stratum-add-scc stratum-seal; do
  expect_rx "builder-stale-$v" "\\(refused stale-generation 0 \\(verb $v\\) \\(expected 1\\)\\)" \
    out/proto-builder-generation.log
done
if [ "$(grep -cF '(refused stale-generation ' out/proto-builder-generation.log)" -eq 5 ]; then
  ok "builder-stale-count-exact"; else bad "builder-stale-count-exact"; fi

# Parse/IO/seal and lifecycle-state failures retain their exact typed class.
sed 's/(abi 1)/(abi 2)/' tests/data/t0-normal-set.plan \
  > out/proto-invalid-abi.plan
racket tests/api/drive.rkt \
  '(scc-begin missing (generation 0) (kernel-plan (sidecar "out/no-such.plan")))' \
  '(scc-seal missing (generation 0))' \
  '(scc-begin badabi (generation 0) (kernel-plan (sidecar "out/proto-invalid-abi.plan")))' \
  '(scc-seal badabi (generation 0))' \
  '(stratum-begin empty (generation 0) (entry fresh))' \
  '(stratum-seal empty (generation 0))' \
  > out/proto-builder-refuse.log 2>&1
expect_rx "builder-plan-io" '\(refused plan-io 0 \(verb scc-seal\)' out/proto-builder-refuse.log
expect_rx "builder-seal-class" '\(refused abi 0 \(verb scc-seal\)' out/proto-builder-refuse.log
expect_rx "builder-state-class" '\(refused builder-state 0 \(verb stratum-seal\)' out/proto-builder-refuse.log

# Structural entry errors are entry-mode refusals. The valid resident-count
# spelling reaches seal policy, where a normal SCC is a forbidden count-tier
# swap; count plans requested as fresh/upgrade are covered in the C++ gate.
ENTRY_SCRIPT=(
  '(stratum-begin missing-at (generation 0) (entry resident-count))'
  '(stratum-begin spurious-at (generation 0) (entry fresh (at 0)))'
  '(scc-begin es (generation 0) (kernel-plan (sidecar "tests/data/t0-normal-set.plan")))'
  '(scc-seal es (generation 0))'
  '(stratum-begin count-swap (generation 0) (entry resident-count (at 0)))'
  '(stratum-add-scc count-swap es (generation 0))'
  '(stratum-seal count-swap (generation 0))'
  '(stratum-begin no-live-upgrade (generation 0) (entry upgrade))'
  '(stratum-add-scc no-live-upgrade es (generation 0))'
  '(stratum-seal no-live-upgrade (generation 0))'
)
racket tests/api/drive.rkt "${ENTRY_SCRIPT[@]}" > out/proto-builder-entry.log 2>&1
if [ "$(grep -cF '(refused entry-mode ' out/proto-builder-entry.log)" -eq 3 ]; then
  ok "builder-entry-mode-count-exact"; else bad "builder-entry-mode-count-exact"; fi
expect_rx "builder-resident-count-swap-refused" \
  '\(refused capability 0 \(verb stratum-seal\).*resident-count strata cannot be restarted or tier-swapped' \
  out/proto-builder-entry.log

# --- 6. TCP/stdin parity ------------------------------------------------------
# One dispatch, two transports: the same command script produces byte-identical
# reply lines.  (pending)/(bye ...) are transport chatter, filtered from the
# diff but asserted separately -- the heartbeat and close handshake are frozen.
# The fixpoint elapsed-ms field is intrinsically run-specific, so normalize that
# one numeric field while retaining the generation/name/iteration tuple.
SCRIPT=("${BUILDER[@]}" "(continue)" "(protocol-mode)" "(frobnicate 1 2)" "(watch v94)"
        "(query q7)" "(catalog)" "(protocol-mode)" "(foo" "(catalog types)"
        "no/such.so")
racket tests/api/drive.rkt     "${SCRIPT[@]}" > out/proto-stdin.log 2>&1
racket tests/api/tcp-drive.rkt "${SCRIPT[@]}" > out/proto-tcp.log   2>&1
normalize_parity() {
  grep -v -e '^(pending)$' -e '^(bye ' "$1" \
    | sed -E 's/ [0-9]+\.[0-9]+\)$/ <elapsed-ms>)/'
}
if diff <(normalize_parity out/proto-tcp.log) \
        <(normalize_parity out/proto-stdin.log) \
     > out/proto-parity.diff 2>&1
then ok "tcp-stdin-parity"; else cat out/proto-parity.diff; bad "tcp-stdin-parity"; fi
expect_rx "tcp-builder-fixpoint" '^\(fixpoint 0 "st0" ' out/proto-tcp.log
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
# SLOG_OPT=0 pins the eager -O0 path: under the default tiered regime T3a
# cold-starts interpreted, so on a cold .so cache the log can complete
# without ever naming a stratum .so -- and section 8 below scrapes those
# paths from this log (the run-replay-setup flake, diagnosed 2026-07-28).
if SLOG_OPT=0 timeout 600 racket compiler/run.rkt --no-banner --out-db protocoldb \
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

# --- 9. live pause scoping: command keyed, path byte-compatible ---------------
# A broad Cartesian read reliably outlives a 1ms slice. Marking command mode
# before loading its strata must produce the keyed T0(d) shape; an otherwise
# identical fresh daemon must retain the frozen positional path-stack bytes.
PF=out/proto_pause.slog
{
  echo "table (r int)"
  echo "table (pair int int)"
  echo "rule"
  for i in $(seq 1 350); do echo "(r $i)"; done
  echo "rule (r X) (r Y) --> (pair X Y)"
} > "$PF"
rm -rf out/proto-pause-build
if SLOG_OPT=0 racket compiler/run.rkt --no-banner --debug-dir out/proto-pause-build \
     "$PF" > out/proto-pause-build.log 2>&1; then
  mapfile -t PSOS < <(grep -oE 'build/[a-f0-9]+(\.O0)?\.so' \
    out/proto-pause-build.log | grep -v 'action-' | awk '!seen[$0]++')
  if [ "${#PSOS[@]}" -ge 1 ]; then
    CMD_ARGS=("(catalog)"); PATH_ARGS=()
    for so in "${PSOS[@]}"; do
      CMD_ARGS+=("$so"); PATH_ARGS+=("$so")
      for _ in $(seq 1 80); do
        CMD_ARGS+=("(continue-boundary)")
        PATH_ARGS+=("(continue-boundary)")
      done
    done
    SLOG_THREADS=1 SLOG_MAX_MS=1 racket tests/api/drive.rkt "${CMD_ARGS[@]}" \
      > out/proto-pause-command.log 2>&1
    SLOG_THREADS=1 SLOG_MAX_MS=1 racket tests/api/drive.rkt "${PATH_ARGS[@]}" \
      > out/proto-pause-path.log 2>&1
    expect_rx "pause-command-keyed" '^\(paused \(generation [0-9]+' \
      out/proto-pause-command.log
    expect_rx "pause-command-budget-cause" '\(cause \(budget time\)\)\)$' \
      out/proto-pause-command.log
    expect_rx "pause-command-boundary-cause" \
      '\(cause \(boundary requested\)\)\)$' out/proto-pause-command.log
    expect_not_rx "pause-command-no-positional" '^\(paused [0-9]+ ' \
      out/proto-pause-command.log
    expect_rx "pause-path-positional-bytes" '^\(paused [0-9]+ "[^"]+" [0-9]+ (read|iter) ' \
      out/proto-pause-path.log
    expect_not "pause-path-no-keyed" '(paused (generation ' \
      out/proto-pause-path.log
  else
    bad "pause-live-setup (no stratum paths)"
  fi
else
  bad "pause-live-build (see out/proto-pause-build.log)"
fi

# --- 10. RF2-B sealed ProgramImage mounts -----------------------------------
# Images are connection-scoped immutable catalog objects, not Database
# relations or executable strata.  The daemon independently verifies the
# compiler's content seal and embedded source/rule/plan digests before the
# first row is published.  Repeating a key is a decoded-cache hit; unmounting
# leaves the artifact itself untouched.
RF2_IMAGE=tests/image-expected/rf2-basic.pimg
RF2_KEY=98db03c33027946f1fa293f105845043bf23643b43ced43926747b7396871bd8
racket tests/api/drive.rkt \
  "(catalog)" \
  "(mount-program-image \"$RF2_IMAGE\")" \
  "(catalog programs)" \
  "(catalog program \"$RF2_KEY\" sources)" \
  "(catalog program \"$RF2_KEY\" rules)" \
  "(catalog program \"$RF2_KEY\" kernels)" \
  "(catalog program \"$RF2_KEY\" plans)" \
  "(mount-program-image \"$RF2_IMAGE\")" \
  "(catalog)" \
  "(unmount-program-image \"$RF2_KEY\")" \
  "(catalog programs)" \
  > out/proto-program-image.log 2>&1
expect "image-mounted" '(program-image-mounted (image-key "98db03c33027946f1fa293f105845043bf23643b43ced43926747b7396871bd8") (cache-hit #f) (rules 2) (kernels 2) (plans 1))' out/proto-program-image.log
expect "image-cache-hit" '(cache-hit #t)' out/proto-program-image.log
expect "image-program-catalog" '(catalog-program (image-key "98db03c33027946f1fa293f105845043bf23643b43ced43926747b7396871bd8")' out/proto-program-image.log
expect "image-source-map-catalog" '(catalog-program-source ' out/proto-program-image.log
expect "image-rule-catalog" '(catalog-program-rule ' out/proto-program-image.log
expect "image-kernel-catalog" '(catalog-program-kernel ' out/proto-program-image.log
expect "image-plan-catalog" '(catalog-program-plan ' out/proto-program-image.log
expect "image-unmounted" '(program-image-unmounted ' out/proto-program-image.log
if racket tests/api/catalog-check.rkt images'>='1 < out/proto-program-image.log; then
  ok "image-catalog-round-trip"; else bad "image-catalog-round-trip"; fi
# Both ordinary relation catalogs are empty: mounting never creates a user
# relation, and unmount cannot remove one.
if [ "$(grep -cF '(catalog-end 0)' out/proto-program-image.log)" -eq 3 ]; then
  ok "image-read-only-catalog-isolation"; else bad "image-read-only-catalog-isolation"; fi

RF2_BAD_KEY=out/rf2-bad-key.pimg
RF2_BAD_FORMAT=out/rf2-bad-format.pimg
sed 's/(key "[0-9a-f]*")/(key "0000000000000000000000000000000000000000000000000000000000000000")/' \
  "$RF2_IMAGE" > "$RF2_BAD_KEY"
sed 's/(format 1)/(format 9)/' "$RF2_IMAGE" > "$RF2_BAD_FORMAT"
racket tests/api/drive.rkt \
  '(mount-program-image "out/no-such-program-image.pimg")' \
  "(mount-program-image \"$RF2_BAD_KEY\")" \
  "(mount-program-image \"$RF2_BAD_FORMAT\")" \
  > out/proto-program-image-refuse.log 2>&1
expect_rx "image-missing-cache-is-a-miss" '\(refused image-io [0-9]+' out/proto-program-image-refuse.log
expect_rx "image-tampered-seal-refused" '\(refused image-seal [0-9]+' out/proto-program-image-refuse.log
expect_rx "image-unknown-format-refused" '\(refused image-format [0-9]+' out/proto-program-image-refuse.log

# RF4 control observations are empty but structurally complete before any
# descriptor artifact or executable kernel is attached. Unknown content keys
# refuse as lookups, not filesystem/path errors: paths are only cache hints.
racket tests/api/drive.rkt \
  '(catalog artifacts)' \
  '(catalog attachments)' \
  '(catalog artifact "0000000000000000000000000000000000000000000000000000000000000000")' \
  > out/proto-native-materializations-empty.log 2>&1
if [ "$(grep -cF '(catalog-end 0)' out/proto-native-materializations-empty.log)" -eq 2 ]; then
  ok "native-materialization-catalogs-start-empty"
else
  bad "native-materialization-catalogs-start-empty"
fi
expect_rx "native-artifact-lookup-typed" \
  '\(refused artifact-lookup [0-9]+ \(verb catalog\) \(artifact-key "0{64}"\)\)' \
  out/proto-native-materializations-empty.log

# RF3 activation is generation-gated and cross-seals the executable manifests
# against the outer ProgramModel before installing a task.  RF2's intentionally
# introspection-only golden has two model SCCs and an empty manifest, making it
# a compact negative fixture: stale generation wins first, then exact coverage
# is refused and no activation row is published.
racket tests/api/drive.rkt \
  "(mount-program-image \"$RF2_IMAGE\")" \
  "(activate-program-image \"$RF2_KEY\" (generation 1))" \
  "(activate-program-image \"$RF2_KEY\" (generation 0))" \
  "(catalog program \"$RF2_KEY\" activation)" \
  "(unmount-program-image \"$RF2_KEY\")" \
  > out/proto-program-image-activation-refuse.log 2>&1
expect_rx "image-activation-generation-gated" \
  '\(refused stale-generation 0 \(verb activate-program-image\)' \
  out/proto-program-image-activation-refuse.log
expect_rx "image-activation-model-manifest-cross-seal" \
  '\(refused binding 0 \(verb activate-program-image\).*manifests do not match the ProgramModel' \
  out/proto-program-image-activation-refuse.log
expect "image-refused-activation-not-published" '(catalog-end 0)' \
  out/proto-program-image-activation-refuse.log
expect "image-refused-activation-still-unmountable" '(program-image-unmounted ' \
  out/proto-program-image-activation-refuse.log

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
