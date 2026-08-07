#!/usr/bin/env bash
#
# T4 slice 2a: TU-text determinism (docs/t4-contract.md §3 slice (2a)).
#
# Two clean compiles of one program must emit byte-identical generated C++
# after stripping full-line // comments -- the same normalization the
# content-addressed .o cache keys on (docs/fast-compile.md §14), so this
# gate certifies exactly the property that cache reuse and (2b)'s
# cross-instance sharing stand on.  Raw bytes are NOT compared: the
# `// <crule>` debug comments render raw IR with gensym'd variable
# spellings, which are harmless to the object and excluded from the hash.
#
# History: 2026-08-03 measured 18 of 42 artifacts PERMUTED between two runs
# of the unmodified compiler (rule emission followed set-iteration order).
# Slice 2a made emission follow the plan's canonical (kernel, rule) order,
# which is what makes this gateable at all.
#
# Fixtures: the four plan-goldens programs + structs + n1_instances, plus
# examples/kcfa (the one program here whose strata exceed chunk-size, so
# the split spine+parts path is exercised, 17 part TUs).
#
#   bash tests/tu-determinism.sh

set -u
cd "$(dirname "$0")/.."

PROGRAMS=(tests/deep_fact.slog tests/lat_run_base.slog tests/dem_lambda.slog
          tests/sj_tri.slog tests/structs.slog tests/n1_instances.slog
          examples/kcfa/kcfa.slog)
WORK="$(mktemp -d)"
trap 'rm -rf "$WORK"' EXIT
PASS=0; FAIL=0

compile_tus() { # <program> <outdir>
  rm -rf build config/cache
  # SLOG_OPT=interp: no clang launches, so nothing races the next wipe;
  # write-cpp runs unconditionally, so the TU text is fully exercised.
  if ! SLOG_OPT=interp timeout 900 racket compiler/run.rkt --no-banner \
       "$1" > "$WORK/$(basename "$1").compile.log" 2>&1; then
    echo "FAIL $(basename "$1") (compile/run failed; see $WORK)"
    return 1
  fi
  mkdir -p "$2"
  cp build/*.cpp "$2"/ 2>/dev/null
}

strip_compare() { # <dir1> <dir2>  -> prints per-file diffs, returns nonzero on any
  python3 - "$1" "$2" <<'PYEOF'
import glob, os, sys
d1, d2 = sys.argv[1], sys.argv[2]
strip = lambda t: "\n".join(l for l in t.split("\n")
                            if not l.lstrip().startswith("//"))
f1 = {os.path.basename(f) for f in glob.glob(d1 + "/*.cpp")}
f2 = {os.path.basename(f) for f in glob.glob(d2 + "/*.cpp")}
bad = 0
if f1 != f2:
    print("  filename sets differ:", sorted(f1 ^ f2)); bad = 1
for b in sorted(f1 & f2):
    if strip(open(os.path.join(d1, b)).read()) \
       != strip(open(os.path.join(d2, b)).read()):
        print("  stripped text differs:", b); bad = 1
sys.exit(bad)
PYEOF
}

for p in "${PROGRAMS[@]}"; do
  name="$(basename "$p" .slog)"
  if ! compile_tus "$p" "$WORK/$name.1"; then FAIL=$((FAIL+1)); continue; fi
  if ! compile_tus "$p" "$WORK/$name.2"; then FAIL=$((FAIL+1)); continue; fi
  n="$(ls "$WORK/$name.1"/*.cpp 2>/dev/null | wc -l)"
  if strip_compare "$WORK/$name.1" "$WORK/$name.2"; then
    echo "PASS $name ($n TUs)"
    PASS=$((PASS+1))
  else
    echo "FAIL $name (TU text not reproducible; dirs kept under $WORK)"
    FAIL=$((FAIL+1))
  fi
done

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
