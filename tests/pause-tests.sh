#!/usr/bin/env bash
#
# Pausable-fixpoint tests (docs/pausing.md).  The trust-establishing one is the
# byte-identical check: the SAME program under a pathological budget (forcing
# dozens of mid-read and iteration-boundary suspends) must produce byte-for-byte
# the same CSVs as an unbudgeted run.  Plus API checks: a paused-then-fixpoint
# sequence is observed, read-only actions work while suspended, mutating actions
# are refused, the memory budget trips a blowup, and continue is idempotent.
#
#   tests/pause-tests.sh          (expects a warm build/ cache; run after
#                                  tests/run-tests.sh, or budget compile time)
#
# Budgets reach the daemon via env (SLOG_MAX_MS / SLOG_MEM_BYTES), so these use
# SLOG_NO_MEM_CAP=1 (direct launch) -- systemd-run would not forward the env.

set -u
cd "$(dirname "$0")/.."
mkdir -p build out data
export SLOG_NO_MEM_CAP=1
# Pin the -O0 tier: pause coverage is TIMING-based (a read task must outlive
# its slice), and a warm -O2 cache makes these tiny fixtures finish inside
# one budget unit -- no mid-read pause, and the guardrail section's replay
# then never suspends at all.  SLOG_OPT=0 alone doesn't suffice (a cached
# plain build/<hash>.so is preferred in every mode), so drop_o2 below also
# removes the fixtures' plain .so's, forcing the .O0 artifacts.
export SLOG_OPT=0
drop_o2() {  # drop_o2 <log>: remove the plain -O2 .so of every stratum in log
  grep -oE 'build/[a-f0-9]+' "$1" 2>/dev/null | sort -u \
    | while read -r h; do rm -f "$h.so"; done
}

PASS=0; FAIL=0
ok()   { echo "PASS $1"; PASS=$((PASS+1)); }
bad()  { echo "FAIL $1"; FAIL=$((FAIL+1)); }
expect()     { if grep -qF "$2" "$3"; then ok "$1"; else echo "  (missing '$2' in $3)"; bad "$1"; fi; }
expect_rx()  { if grep -qE "$2" "$3"; then ok "$1"; else echo "  (no match /$2/ in $3)"; bad "$1"; fi; }
# negated fixed-string check (was USED at the memory-cap section but never
# defined -- so `memory-no-oomcrash` silently did nothing, 2026-07-11)
expect_not() { if grep -qF "$2" "$3"; then echo "  (unexpected '$2' in $3)"; bad "$1"; else ok "$1"; fi; }

# A chain of 250 edges -> ~63000 transitive paths: the recursive `path` rule's
# scan driver iterates far past the 128-tuple slice check, so a small time
# budget forces many mid-read suspends and a small memory budget trips fast.
FX=out/pause_chain.slog
{
  echo "table (edge int int)"
  echo "table (path int int)"
  echo "rule"
  for i in $(seq 1 250); do echo "(edge $i $((i+1)))"; done
  echo "rule (edge X Y) --> (path X Y)"
  echo "rule (path X Y) (edge Y Z) --> (path X Z)"
} > "$FX"

# --- 1. byte-identical: unbudgeted vs a pathological time budget ------------
rm -rf out/pause-unb out/pause-bud
racket slog.rkt --no-banner --debug-dir out/pause-unb "$FX" > out/pause-unb.log 2>&1
drop_o2 out/pause-unb.log   # re-run on the .O0 tier (see header)
racket slog.rkt --no-banner --debug-dir out/pause-unb "$FX" > out/pause-unb.log 2>&1
SLOG_MAX_MS=3 racket slog.rkt --no-banner --debug-dir out/pause-bud "$FX" > out/pause-bud.log 2>&1

expect_rx "pause-observed"    '\(paused ' out/pause-bud.log
expect_rx "fixpoint-observed" '\(fixpoint ' out/pause-bud.log
# both a mid-read (read) and a boundary (iter) suspend should occur on 63k paths
expect_rx "mid-read-suspend"  '\(paused .* read ' out/pause-bud.log
expect_rx "boundary-suspend"  '\(paused .* iter ' out/pause-bud.log

BI=1
for f in out/pause-unb/*.csv; do
  b="$(basename "$f")"
  # $stat_fixpoint carries wall-clock microseconds -- inherently different
  # between an unbudgeted and a budgeted run; excluded here exactly as the
  # stats tables are excluded from goldens (docs/stats.md).  This was the
  # section's long-standing intermittent failure (previously misread as a
  # concurrent-build flake; verified 2026-07-11 on stock master).
  case "$b" in \$stat_*) continue ;; esac
  diff <(LC_ALL=C sort "$f") <(LC_ALL=C sort "out/pause-bud/$b") >/dev/null 2>&1 || BI=0
done
diff <(ls out/pause-unb | grep -v '^\$stat_') \
     <(ls out/pause-bud | grep -v '^\$stat_') >/dev/null 2>&1 || BI=0
if [ "$BI" -eq 1 ]; then ok "byte-identical-under-pathological-budget"
else bad "byte-identical-under-pathological-budget"; fi

# --- 2. probe-driver slicing: byte-identical under a pathological budget -----
# A constant-bound driver (r 5 X) fans out over an inner (r 5 W) -> 250k pairs,
# so the OUTER probe loop pauses and resumes from its last match key.  (500,
# not 200: at 200/40k-pairs the join sometimes finishes within the 2ms budget
# below on a fast machine, so the pause was observed only ~40% of the time --
# a flaky test.  250k pairs reliably exceeds 2ms.)
PFX=out/pause_probe.slog
{
  echo "table (r int int)"
  echo "table (pair int int)"
  echo "rule"
  for i in $(seq 1 500); do echo "(r 5 $i)"; done
  echo "rule (r 5 X) (r 5 W) --> (pair X W)"
} > "$PFX"
rm -rf out/pp-u out/pp-b
racket slog.rkt --no-banner --debug-dir out/pp-u "$PFX" > out/pp-u.log 2>&1
drop_o2 out/pp-u.log
SLOG_MAX_MS=2 racket slog.rkt --no-banner --debug-dir out/pp-b "$PFX" > out/pp-b.log 2>&1
expect_rx "probe-pause-observed" '\(paused ' out/pp-b.log
if diff <(LC_ALL=C sort out/pp-u/pair.csv) <(LC_ALL=C sort out/pp-b/pair.csv) >/dev/null 2>&1
then ok "probe-driver-byte-identical"; else bad "probe-driver-byte-identical"; fi

# --- 3. memory cap enforced GRACEFULLY (pause + clean abort, not an OOM crash)
# A cap below the daemon's own resident size trips at the first iteration
# boundary; the front end must abort cleanly (non-zero exit, clear message),
# never leave a SIGKILL/segfault.
rm -rf out/pause-mem
SLOG_MEM_BYTES=1 racket slog.rkt --no-banner --debug-dir out/pause-mem "$FX" \
  > out/pause-mem.log 2>&1
MEMEXIT=$?
expect_rx  "memory-pause"        '\(paused .* memory\)' out/pause-mem.log
expect     "memory-graceful"     "out of memory"        out/pause-mem.log
expect_not "memory-no-oomcrash"  "Killed"               out/pause-mem.log
if [ "$MEMEXIT" -ne 0 ]; then ok "memory-nonzero-exit"; else bad "memory-nonzero-exit"; fi
# and a run UNDER the default cap completes normally (test 1 already showed the
# unbudgeted CSVs; here just confirm a plain default-budget run succeeds)
rm -rf out/pause-defmem
if racket slog.rkt --no-banner --debug-dir out/pause-defmem "$FX" >/dev/null 2>&1 \
   && diff <(LC_ALL=C sort out/pause-unb/path.csv) \
           <(LC_ALL=C sort out/pause-defmem/path.csv) >/dev/null 2>&1
then ok "under-cap-completes"; else bad "under-cap-completes"; fi

# --- 3. idempotent continue on an empty pipeline answers (idle) -------------
racket tests/api/drive.rkt "(continue)" > out/pause-idle.log 2>&1
expect "idle-idempotent" "(idle)" out/pause-idle.log

# --- 4. guardrail + read-only action while suspended ------------------------
# Capture the compiled stratum .so paths from a normal run's log, then replay
# them under SLOG_MAX_MS=1 (every stratum suspends on its first unit) WITHOUT
# continuing, followed by a mutating (open) -- refused -- and a read-only
# (lookup) -- allowed against the suspended snapshot.
# Stratum plugins the driver sent: in tiered mode these are the -O0 artifacts
# (build/<hash>.O0.so); a cached run sends the plain build/<hash>.so.  Either
# form is a valid stratum plugin to replay.
# PIPELINE order, first appearance (sort -u orders by hash text -- replaying
# strata out of order gives trivial fixpoints that never suspend)
mapfile -t SOS < <(grep -oE 'build/[a-f0-9]+(\.O0)?\.so' out/pause-unb.log | grep -v 'action-' | awk '!seen[$0]++')
OPEN_SO=$(racket -e '(require (file "'"$PWD"'/compiler/actions.rkt")) (displayln (action-so (list (quote open) "pause_nodb")))' 2>/dev/null)
LOOKUP_SO=$(racket -e '(require (file "'"$PWD"'/compiler/actions.rkt")) (displayln (action-so (list (quote lookup) (quote path) 1 2)))' 2>/dev/null)
if [ "${#SOS[@]}" -ge 1 ] && [ -n "$OPEN_SO" ] && [ -n "$LOOKUP_SO" ]; then
  SLOG_MAX_MS=1 racket tests/api/drive.rkt "${SOS[@]}" "$OPEN_SO" "$LOOKUP_SO" \
    > out/pause-susp.log 2>&1
  expect_rx "suspend-observed"        '\(paused ' out/pause-susp.log
  expect_rx "mutating-refused"        '\(error suspended' out/pause-susp.log
  expect_rx "readonly-lookup-allowed" '\(found path (0|1)\)' out/pause-susp.log
else
  bad "guardrail-setup (could not build .so paths)"
fi

# --- 5. pausing x compression-replay (docs/incremental.md W2/§6.5/§8A) -------
# Incremental "load & stream" (W2) resumes a fixpoint from a compressed DB's
# prog.sexpr REPLAY.  Reloading under a pathological time budget forces mid-read
# / boundary suspends DURING that replay; because pausing is exact, the
# reconstructed content must be byte-identical to an unbudgeted reload -- the
# invariant a resumable incremental load leans on.  (per=60 so replay actually
# regenerates dropped tuples; the 63k-path chain reliably outlives a 3ms slice.)
rm -rf data/pause_c data/pause_c.edb out/pcr-unb out/pcr-bud
racket slog.rkt --no-banner --out-db-compressed pause_c --per 60 "$FX" > out/pause-csave.log 2>&1
drop_o2 out/pause-csave.log
CLOADER=out/pause_loader.slog; printf ';; empty replay loader\n' > "$CLOADER"
# unbudgeted reload (oracle); prime then drop -O2 so the budgeted reload is -O0
racket slog.rkt --no-banner -d pause_c --debug-dir out/pcr-unb "$CLOADER" > out/pcr-unb.log 2>&1
drop_o2 out/pcr-unb.log
racket slog.rkt --no-banner -d pause_c --debug-dir out/pcr-unb "$CLOADER" > out/pcr-unb.log 2>&1
SLOG_MAX_MS=3 racket slog.rkt --no-banner -d pause_c --debug-dir out/pcr-bud "$CLOADER" > out/pcr-bud.log 2>&1
expect_rx "creplay-pause-observed" '\(paused ' out/pcr-bud.log
CRBI=1
for f in out/pcr-unb/*.csv; do
  b="$(basename "$f")"; case "$b" in '$stat_'*) continue ;; esac
  diff <(LC_ALL=C sort "$f") <(LC_ALL=C sort "out/pcr-bud/$b") >/dev/null 2>&1 || CRBI=0
done
diff <(ls out/pcr-unb | grep -v '^\$stat_') <(ls out/pcr-bud | grep -v '^\$stat_') >/dev/null 2>&1 || CRBI=0
if [ "$CRBI" -eq 1 ]; then ok "compression-replay-pause-byte-identical"
else bad "compression-replay-pause-byte-identical"; fi
rm -rf data/pause_c data/pause_c.edb

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
