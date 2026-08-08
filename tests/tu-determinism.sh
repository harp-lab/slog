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
# T4 slice 2b adds two checks over the n1_instances TUs: kernel cluster
# text is name-free (no getRelation literals), and the two instances'
# library kernels collapse to one cluster across different stems.
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

# T4 slice 2b: kernel cluster TUs are NAME-FREE (relation access is a frame
# slot; stats keys and the binding frame arrive from the spine), so two
# instances of one library emit ONE cluster function.  Checked on the
# n1_instances TUs already produced above:
#   (a) no part TU contains a getRelation string literal;
#   (b) the left.path and right.path kernels' clusters collapse -- at least
#       one identical comment-stripped part pair under two DIFFERENT stems.
if [ -d "$WORK/n1_instances.1" ]; then
  if grep -l 'getRelation("' "$WORK/n1_instances.1"/*.p*.cpp > /dev/null 2>&1; then
    echo "FAIL cluster-name-freedom ($(grep -l 'getRelation(\"' "$WORK/n1_instances.1"/*.p*.cpp | tr '\n' ' '))"
    FAIL=$((FAIL+1))
  else
    echo "PASS cluster-name-freedom"
    PASS=$((PASS+1))
  fi
  if python3 - "$WORK/n1_instances.1" <<'PYEOF'
import glob, hashlib, sys
strip = lambda t: "\n".join(l for l in t.split("\n")
                            if not l.lstrip().startswith("//"))
seen = {}
for f in glob.glob(sys.argv[1] + "/*.p*.cpp"):
    stem = f.split("/")[-1].split(".")[0]
    h = hashlib.sha256(strip(open(f).read()).encode()).hexdigest()
    seen.setdefault(h, set()).add(stem)
sys.exit(0 if any(len(s) > 1 for s in seen.values()) else 1)
PYEOF
  then
    echo "PASS cross-instance-cluster-collapse"
    PASS=$((PASS+1))
  else
    echo "FAIL cross-instance-cluster-collapse (no shared cluster across stems)"
    FAIL=$((FAIL+1))
  fi
fi

# T4 slice 2c: the slice-2 exit case -- one .so attached twice.  In
# n1_symmetric both instances' path kernels sit at the same level, so ONE
# stratum carries two kernels with the SAME exec key, its descriptor
# declares both, and the daemon attaches one cluster function twice with
# distinct frames.  Checked structurally (a plan with two identical
# manifest keys) and behaviorally (native answers == interp answers).
rm -rf build config/cache "$WORK/sym-i" "$WORK/sym-n"
if SLOG_OPT=interp timeout 900 racket compiler/run.rkt --no-banner \
     --debug-dir "$WORK/sym-i" tests/n1_symmetric.slog \
     > "$WORK/sym-i.log" 2>&1 \
   && { rm -rf build config/cache; \
        SLOG_OPT=0 timeout 900 racket compiler/run.rkt --no-banner \
          --debug-dir "$WORK/sym-n" tests/n1_symmetric.slog \
          > "$WORK/sym-n.log" 2>&1; }; then
  if grep -ho '(key "[0-9a-f]*")' build/*.plan | sort | uniq -d | grep -q .; then
    echo "PASS symmetric-shared-kernel-in-one-cohort"
    PASS=$((PASS+1))
  else
    echo "FAIL symmetric-shared-kernel-in-one-cohort (no duplicated manifest key)"
    FAIL=$((FAIL+1))
  fi
  if diff <(LC_ALL=C sort "$WORK/sym-i/answer.csv") \
          <(LC_ALL=C sort "$WORK/sym-n/answer.csv") > /dev/null 2>&1 \
     && [ -s "$WORK/sym-n/answer.csv" ]; then
    echo "PASS double-attach-byte-identical"
    PASS=$((PASS+1))
  else
    echo "FAIL double-attach-byte-identical (native vs interp answer.csv)"
    FAIL=$((FAIL+1))
  fi
else
  echo "FAIL symmetric-double-attach (compile/run failed; see $WORK)"
  FAIL=$((FAIL+1))
fi

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
