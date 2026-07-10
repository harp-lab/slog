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

PASS=0; FAIL=0
ok()  { echo "PASS $1"; PASS=$((PASS+1)); }
bad() { echo "FAIL $1"; FAIL=$((FAIL+1)); }

# identical set of sorted CSVs between two debug-dirs?
same_csvs() {
  local a="$1" b="$2"
  diff <(cd "$a" && ls *.csv 2>/dev/null | sort) \
       <(cd "$b" && ls *.csv 2>/dev/null | sort) >/dev/null 2>&1 || return 1
  local f
  for f in "$a"/*.csv; do
    [ -e "$f" ] || continue
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
  SLOG_OPT=2 racket slog.rkt --no-banner --debug-dir "out/$base-o2" "$prog" >/dev/null 2>&1
  rm -rf build; mkdir -p build
  SLOG_OPT=0 racket slog.rkt --no-banner --debug-dir "out/$base-o0" "$prog" >/dev/null 2>&1
  rm -rf build; mkdir -p build
  racket slog.rkt --no-banner --debug-dir "out/$base-ti" "$prog" >/dev/null 2>&1   # tiered (default)
  if same_csvs "out/$base-o2" "out/$base-o0" && same_csvs "out/$base-o2" "out/$base-ti"
  then ok "byte-identical-o2-o0-tiered-$base"
  else bad "byte-identical-o2-o0-tiered-$base"; fi
done

# --- 2. deterministic -O0 -> -O2 hot swap ----------------------------------
# Compile the chain, find the recursive stratum (scc-id 1), build it at both
# optimization levels, and drive a session that swaps mid-fixpoint.
rm -rf build out/swap-ref out/swap-got; mkdir -p build
SLOG_OPT=0 racket slog.rkt --no-banner --debug-dir out/swap-ref "$CHAIN" > out/swap-compile.log 2>&1
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
SLOG_OPT=0 racket slog.rkt --no-banner --debug-dir out/lset-ref "$LSET" > out/lset-compile.log 2>&1
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

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
