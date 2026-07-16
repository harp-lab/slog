#!/usr/bin/env bash
#
# Tiered-compilation tests (docs/fast-compile.md).  Two trust properties:
#
#   1. Byte-identical across optimization regimes: a program run at SLOG_OPT=2
#      (-O2 only), SLOG_OPT=0 (-O0 only), and tiered (-O0 then a background -O2
#      hot swap) must produce byte-for-byte the same CSVs -- the swap changes
#      machine code, never results.  A float program is included so the shared
#      -ffp-contract=off across the daemon and both tiers is exercised.
#
#   2. The hot swap actually happens and stays correct: a stratum is compiled at
#      both -O0 and -O2, and a daemon session is driven -O0 -> boundary -> swap
#      -O2 -> fixpoint (tests/api/swap-drive.rkt), producing output identical to
#      an unbudgeted run.
#
#   tests/tiered-tests.sh          (builds its own fixtures; ~1-2 min)

set -u
cd "$(dirname "$0")/.."
mkdir -p build out
export SLOG_NO_MEM_CAP=1
# These tests assert on a fixed stratum structure (a facts stratum at level 0
# and a recursive stratum at level 1).  Ground-fact freezing (docs/freeze.md)
# would peel the >512-node edge facts into a static DB and collapse that
# structure, so disable it here -- freeze is exercised by its own suite.
export SLOG_NO_FREEZE=1

PASS=0; FAIL=0
ok()  { echo "PASS $1"; PASS=$((PASS+1)); }
bad() { echo "FAIL $1"; FAIL=$((FAIL+1)); }

# identical set of sorted CSVs between two debug-dirs?  The $stat_* relations
# are per-run diagnostics (fixpoint timings, fire counts) that legitimately
# differ across optimization regimes, so they are excluded -- exactly as the
# golden suite does (tests/run-tests.sh, docs/stats.md).
same_csvs() {
  local a="$1" b="$2"
  diff <(cd "$a" && ls *.csv 2>/dev/null | grep -v '^\$stat_' | sort) \
       <(cd "$b" && ls *.csv 2>/dev/null | grep -v '^\$stat_' | sort) >/dev/null 2>&1 || return 1
  local f
  for f in "$a"/*.csv; do
    [ -e "$f" ] || continue
    case "$(basename "$f")" in '$stat_'*) continue ;; esac
    diff <(LC_ALL=C sort "$f") <(LC_ALL=C sort "$b/$(basename "$f")") >/dev/null 2>&1 || return 1
  done
  return 0
}

# --- 1. byte-identical across -O2 / -O0 / tiered ----------------------------
CHAIN=out/tiered_chain.slog
{
  echo "table (edge int int)"; echo "table (path int int)"; echo "rule"
  for i in $(seq 1 400); do echo "(edge $i $((i+1)))"; done
  echo "rule (edge X Y) --> (path X Y)"
  echo "rule (path X Y) (edge Y Z) --> (path X Z)"
} > "$CHAIN"

# a float program (homogeneous float arithmetic + a comparison guard)
FLT=out/tiered_flt.slog
{
  echo "table (fin float)"
  echo "table (fsq float float)"
  echo "table (big float)"
  echo "rule (fin 1.5) (fin 2.25) (fin 3.125) (fin 10.5) (fin 0.5)"
  echo "rule (fin X) --> (fsq X (* X X))"
  echo "rule (fsq X Y) (> Y 5.0) --> (big Y)"
} > "$FLT"

for prog in "$CHAIN" "$FLT"; do
  base="$(basename "$prog" .slog)"
  rm -rf "build" "out/$base-o2" "out/$base-o0" "out/$base-ti"; mkdir -p build
  SLOG_OPT=2 racket compiler/run.rkt --no-banner --debug-dir "out/$base-o2" "$prog" >/dev/null 2>&1
  rm -rf build; mkdir -p build
  SLOG_OPT=0 racket compiler/run.rkt --no-banner --debug-dir "out/$base-o0" "$prog" >/dev/null 2>&1
  rm -rf build; mkdir -p build
  racket compiler/run.rkt --no-banner --debug-dir "out/$base-ti" "$prog" >/dev/null 2>&1   # tiered (default)
  if same_csvs "out/$base-o2" "out/$base-o0" && same_csvs "out/$base-o2" "out/$base-ti"
  then ok "byte-identical-o2-o0-tiered-$base"
  else bad "byte-identical-o2-o0-tiered-$base"; fi
done

# --- 2. deterministic -O0 -> -O2 hot swap ----------------------------------
# Compile the chain, find the recursive stratum (scc-id 1), build it at both
# optimization levels, and drive a session that swaps mid-fixpoint.
rm -rf build out/swap-ref out/swap-got; mkdir -p build
SLOG_OPT=0 racket compiler/run.rkt --no-banner --debug-dir out/swap-ref "$CHAIN" > out/swap-compile.log 2>&1
FACTS_HASH="$(grep -oE '\(fixpoint 0 "[a-f0-9]+"' out/swap-compile.log | grep -oE '[a-f0-9]{6,}' | head -1)"
REC_HASH="$(grep -oE '\(fixpoint 1 "[a-f0-9]+"' out/swap-compile.log | grep -oE '[a-f0-9]{6,}' | head -1)"

if [ -z "$FACTS_HASH" ] || [ -z "$REC_HASH" ] || [ ! -f "build/$REC_HASH.cpp" ]; then
  bad "swap-setup (facts=$FACTS_HASH rec=$REC_HASH)"
else
  FACTS_SO="build/$FACTS_HASH.O0.so"
  [ -f "$FACTS_SO" ] || FACTS_SO="build/$FACTS_HASH.so"
  CXX_FLAGS="-std=c++20 -fPIC -Idaemon -fopenmp -ffp-contract=off -shared"
  clang++ build/$REC_HASH.cpp $CXX_FLAGS -O0 -o build/$REC_HASH.swapO0.so -lz 2>/dev/null
  clang++ build/$REC_HASH.cpp $CXX_FLAGS -O2 -o build/$REC_HASH.swapO2.so -lz 2>/dev/null
  if [ -f "build/$REC_HASH.swapO0.so" ] && [ -f "build/$REC_HASH.swapO2.so" ]; then
    SLOG_MAX_MS=1 racket tests/api/swap-drive.rkt out/swap-got \
      "plain:$FACTS_SO" "swap:build/$REC_HASH.swapO0.so,build/$REC_HASH.swapO2.so" \
      > out/swap-drive.log 2>&1
    if grep -q '^SWAPPED' out/swap-drive.log; then ok "swap-fired"; else bad "swap-fired"; fi
    if grep -q '(fixpoint ' out/swap-drive.log; then ok "swap-reached-fixpoint"; else bad "swap-reached-fixpoint"; fi
    if same_csvs out/swap-ref out/swap-got; then ok "swap-byte-identical"; else bad "swap-byte-identical"; fi
  else
    bad "swap-setup (could not build O0/O2 plugins)"
  fi
fi

# --- 3. hot swap of a COLLECTION-LATTICE stratum (LAT_EXTERN) ---------------
# Exercises the setLattice-idempotence fix: re-running the lattice plugin on the
# live relation during a swap must NOT free the LatSpec tree under the live
# payload-map buckets (would be a use-after-free on the next merge).  A recursive
# (set int) reachability lattice over a chain gives a multi-iteration LAT_EXTERN
# stratum to swap mid-fixpoint.
LSET=out/tiered_lset.slog
{
  echo "lattice (rset (set int))"
  echo "table (edge int int)"
  echo "table (reach int rset)"
  echo "table (sz int int)"
  echo -n "rule"; for i in $(seq 1 120); do echo -n " (edge $i $((i+1)))"; done; echo
  echo "rule (edge a b) (= s (cins (cmap) b)) --> (reach a s)"
  echo "rule (edge a b) (reach b s) --> (reach a s)"
  echo "rule (reach a s) (= n (csize s)) --> (sz a n)"
} > "$LSET"
rm -rf build out/lset-ref out/lset-got; mkdir -p build
SLOG_OPT=0 racket compiler/run.rkt --no-banner --debug-dir out/lset-ref "$LSET" > out/lset-compile.log 2>&1
# the recursive lattice stratum is the one that iterates > 2 times
LREC="$(grep -oE '\(fixpoint [0-9]+ "[a-f0-9]+" [0-9]+' out/lset-compile.log \
        | awk '$4 > 2 {print $3}' | tr -d '"' | head -1)"
# drive every stratum in pipeline order, swapping the recursive lattice one
if [ -n "$LREC" ] && [ -f "build/$LREC.cpp" ]; then
  clang++ build/$LREC.cpp $CXX_FLAGS -O0 -o build/$LREC.lsO0.so -lz 2>/dev/null
  clang++ build/$LREC.cpp $CXX_FLAGS -O2 -o build/$LREC.lsO2.so -lz 2>/dev/null
  # ordered stratum plugins from the reference run
  TOKENS=()
  for h in $(grep -oE '\(fixpoint [0-9]+ "[a-f0-9]+"' out/lset-compile.log | grep -oE '[a-f0-9]{6,}'); do
    if [ "$h" = "$LREC" ]; then
      TOKENS+=("swap:build/$LREC.lsO0.so,build/$LREC.lsO2.so")
    else
      so="build/$h.O0.so"; [ -f "$so" ] || so="build/$h.so"
      TOKENS+=("plain:$so")
    fi
  done
  if [ -f "build/$LREC.lsO0.so" ] && [ -f "build/$LREC.lsO2.so" ]; then
    SLOG_MAX_MS=1 racket tests/api/swap-drive.rkt out/lset-got "${TOKENS[@]}" \
      > out/lset-drive.log 2>&1
    if grep -q '^SWAPPED' out/lset-drive.log; then ok "lattice-swap-fired"; else bad "lattice-swap-fired"; fi
    if same_csvs out/lset-ref out/lset-got; then ok "lattice-swap-byte-identical"; else bad "lattice-swap-byte-identical"; fi
  else
    bad "lattice-swap-setup (could not build O0/O2 plugins)"
  fi
else
  bad "lattice-swap-setup (rec stratum=$LREC)"
fi

# --- 4. tiered reuses a cached -O0 (no recompile) + claim suppresses -O2 ----
# docs/fast-compile.md §13: a prior run that left only <hash>.O0.so must, in
# tiered mode, run that -O0 as-is (no re-emit, no rebuild) rather than fall
# through to a fresh -O0 build; and a live claim marker must stop the run from
# spawning a background -O2.
REUSE=out/tiered_reuse.slog
{
  echo "table (a int)"; echo "table (b int)"
  echo "rule (a 1) (a 2) (a 3)"
  echo "rule (a X) --> (b X)"
} > "$REUSE"
rm -rf build out/reuse-o0 out/reuse-ti; mkdir -p build
# prior run leaving only <hash>.O0.so (SLOG_OPT=0 never builds <hash>.so)
SLOG_OPT=0 racket compiler/run.rkt --no-banner --debug-dir out/reuse-o0 "$REUSE" >/dev/null 2>&1
# pre-claim every -O2 (fresh marker) so the tiered run cannot spawn a background
# build, and stamp a reference mtime -- a rebuilt .O0.so would be newer than it.
for f in build/*.O0.so; do [ -e "$f" ] && touch "${f%.O0.so}.so.building"; done
sleep 1; touch out/reuse-stamp; sleep 1
racket compiler/run.rkt --no-banner --debug-dir out/reuse-ti "$REUSE" > out/reuse-ti.log 2>&1   # tiered
reuse_ok=1
# Check ONLY this program's own stratum hashes (from its fixpoint lines; stable
# across opt levels).  build/ is shared and durably-detached -O2 builds from
# earlier fixtures keep landing unrelated <hash>.so/.O0.so, so a build-wide glob
# would false-fail.
RHASHES="$(grep -oE '\(fixpoint [0-9]+ "[a-f0-9]+"' out/reuse-ti.log | grep -oE '[a-f0-9]{6,}' | sort -u)"
[ -z "$RHASHES" ] && reuse_ok=0
for h in $RHASHES; do
  # -O0 reused, not rebuilt after the stamp
  [ -n "$(find build -name "$h.O0.so" -newer out/reuse-stamp -print -quit)" ] && reuse_ok=0
  # claim marker suppressed OUR -O2 for this stratum (no canonical <hash>.so)
  [ -e "build/$h.so" ] && reuse_ok=0
done
if [ "$reuse_ok" = 1 ] && same_csvs out/reuse-o0 out/reuse-ti
then ok "tiered-reuses-cached-O0-and-claim-suppresses-O2"
else bad "tiered-reuses-cached-O0-and-claim-suppresses-O2"; fi

# --- 5. claim marker: single-flight + stale reclaim (unit) -----------------
# try-claim-o2! is the cross-process mutex: a fresh claim wins, a second (live)
# claim is refused, and a marker older than the reclaim window is reclaimed.
cat > out/o2-claim-test.rkt <<'EOF'
#lang racket
(require "../compiler/tools.rkt")
(define p (fullpath "build/claimtest.so"))
(define marker (string-append p ".building"))
(when (file-exists? marker) (delete-file marker))
(define r1 (try-claim-o2! p))                 ; fresh -> claimed
(define r2 (try-claim-o2! p))                 ; still fresh -> refused
(file-or-directory-modify-seconds marker (- (current-seconds) 100000)) ; backdate past 900s
(define r3 (try-claim-o2! p))                 ; stale -> reclaimed
(define held (file-exists? marker))
(clear-o2-marker! p)
(exit (if (and r1 (not r2) r3 held (not (file-exists? marker))) 0 1))
EOF
if racket out/o2-claim-test.rkt >/dev/null 2>&1
then ok "o2-claim-single-flight-and-stale-reclaim"
else bad "o2-claim-single-flight-and-stale-reclaim"; fi

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
