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
  # T4 slice 3b: per-instance stats attribution (the fires table keys on
  # instance-qualified locs) ...
  if grep -q '"a#0@n1_graph_lib' "$WORK/sym-n/\$stat_fires.csv" 2>/dev/null \
     && grep -q '"b#1@n1_graph_lib' "$WORK/sym-n/\$stat_fires.csv" 2>/dev/null; then
    echo "PASS per-instance-fire-attribution"
    PASS=$((PASS+1))
  else
    echo "FAIL per-instance-fire-attribution (missing instance-qualified fires)"
    FAIL=$((FAIL+1))
  fi
  # ... and the attachment records: replay the native pipeline through the
  # raw driver and ask (attachments) -- two records must share ONE exec key
  # while carrying DIFFERENT write maps: one artifact, attached twice, with
  # disaggregated identity (execution-tiers §2.2's ladder, live).
  sos="$(grep -oE '\(fixpoint [0-9]+ "[a-f0-9_]+"' "$WORK/sym-n.log" \
         | grep -oE '[a-f0-9_]{6,}' \
         | while read -r h; do so="build/$h.O0.so"; [ -f "$so" ] || so="build/$h.so"; echo "$so"; done)"
  # shellcheck disable=SC2086
  racket tests/api/drive.rkt $sos "(attachments)" \
    "(catalog artifacts)" "(catalog attachments)" \
    > "$WORK/sym-att.log" 2>&1
  if python3 - "$WORK/sym-att.log" <<'PYEOF'
import re, sys
recs = {}
for line in open(sys.argv[1]):
    m = re.match(r'\(attachment \(stratum "[^"]*"\) \(key "([0-9a-f]+)"\) \(writes (.*?)\) \(reads', line)
    if m: recs.setdefault(m.group(1), set()).add(m.group(2))
sys.exit(0 if any(len(w) > 1 for w in recs.values()) else 1)
PYEOF
  then
    echo "PASS attachment-records-disaggregate"
    PASS=$((PASS+1))
  else
    echo "FAIL attachment-records-disaggregate (no shared key with distinct writes)"
    FAIL=$((FAIL+1))
  fi
  if racket tests/api/catalog-check.rkt < "$WORK/sym-att.log" \
     && grep -qE '^\(catalog-native-artifact .*\(state ready\).*\(attachments [1-9][0-9]*\)' "$WORK/sym-att.log" \
     && grep -qE '^\(catalog-executor-attachment .*\(tier native\).*\(native \([0-9]' "$WORK/sym-att.log"; then
    echo "PASS rf4-native-artifact-and-attachment-catalog"
    PASS=$((PASS+1))
  else
    echo "FAIL rf4-native-artifact-and-attachment-catalog (see $WORK/sym-att.log)"
    FAIL=$((FAIL+1))
  fi
  # RF4 paths are volatile hints. Load a copied descriptor, wait for its
  # successful attach, unlink only that temporary .so while the daemon keeps
  # its dlopen handle, then query the registry: semantic execution survives
  # and the artifact becomes a rebuildable cache miss.
  first_so="$(printf '%s\n' $sos | head -n 1)"
  first_file="${first_so##*/}"
  first_stem="${first_file%%.*}"
  cp "$first_so" "$WORK/rf4-miss.so"
  cp "build/$first_stem.plan" "$WORK/rf4-miss.plan"
  if python3 - "$WORK/rf4-miss.so" "$WORK/rf4-miss.log" <<'PYEOF'
import os, subprocess, sys
so, log = sys.argv[1:]
env = os.environ.copy()
env["SLOG_NO_MEM_CAP"] = "1"
p = subprocess.Popen(["daemon/slogd", "-t", "2"], stdin=subprocess.PIPE,
                     stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                     text=True, env=env)
p.stdin.write(so + "\n")
p.stdin.flush()
first = p.stdout.readline()
os.unlink(so)
p.stdin.write("(catalog artifacts)\n")
p.stdin.flush()
lines = [first]
while True:
    line = p.stdout.readline()
    if not line:
        break
    lines.append(line)
    if line.startswith("(catalog-end "):
        break
# Stdin mode shuts down on EOF.  `(close)` is not a command verb (and is
# correctly refused as unknown), so sending it while retaining the pipe keeps
# the daemon alive until this test's timeout instead of testing cleanup.
p.stdin.close()
p.wait(timeout=30)
open(log, "w").writelines(lines)
sys.exit(0 if any("(state miss)" in line for line in lines) else 1)
PYEOF
  then
    echo "PASS rf4-missing-artifact-is-rebuildable-miss"
    PASS=$((PASS+1))
  else
    echo "FAIL rf4-missing-artifact-is-rebuildable-miss (see $WORK/rf4-miss.log)"
    FAIL=$((FAIL+1))
  fi
  # ... and the recount half of the slice-3 exit, two ways: a SECOND forced
  # recount over the shared kernel must reproduce the first's countrows per
  # attachment (recount agrees with the sidecar it established), and the
  # fixture's symmetry means a.path's and b.path's count multisets must be
  # IDENTICAL modulo the name -- a cross-attachment mixup (one instance's
  # counts landing on the other) breaks that immediately.
  rm -rf build config/cache; mkdir -p build
  timeout 900 racket tests/api/session-drive.rkt run:tests/n1_symmetric.slog \
    batch+:seed,3,4 flush recount-force \
    dump-counts:a.path dump-counts:b.path recount-force \
    dump-counts:a.path dump-counts:b.path > "$WORK/sym-recount.log" 2>&1
  # the run itself may emit an initial (recount ...) marker, so anchor on
  # the LAST two markers: the dumps after each forced recount
  nrec="$(grep -c '^(recount' "$WORK/sym-recount.log")"
  pre="$(awk -v k="$((nrec-1))" '/^\(recount/{n++} n==k && /^\(countrow/' \
         "$WORK/sym-recount.log" | LC_ALL=C sort)"
  post="$(awk -v k="$nrec" '/^\(recount/{n++} n==k && /^\(countrow/' \
          "$WORK/sym-recount.log" | LC_ALL=C sort)"
  a_rows="$(echo "$post" | grep ' a\.path ' | sed 's/ a\.path / R /' | LC_ALL=C sort)"
  b_rows="$(echo "$post" | grep ' b\.path ' | sed 's/ b\.path / R /' | LC_ALL=C sort)"
  if [ "$nrec" -ge 2 ] && [ -n "$pre" ] && [ "$pre" = "$post" ] \
     && [ -n "$a_rows" ] && [ "$a_rows" = "$b_rows" ]; then
    echo "PASS per-attachment-recount-agreement"
    PASS=$((PASS+1))
  else
    echo "FAIL per-attachment-recount-agreement (see $WORK/sym-recount.log)"
    FAIL=$((FAIL+1))
  fi
else
  echo "FAIL symmetric-double-attach (compile/run failed; see $WORK)"
  FAIL=$((FAIL+1))
fi

# T4 slice 4: mixed-tier equivalence -- the slice's exit.  Under each
# coverage mode the descriptor's kernels split between native tasks and
# the daemon-attached interpreted complement; results must match the
# recorded goldens (which the pure interpreter produced) byte-for-byte.
# `none` is the degenerate case: descriptor artifacts, zero clusters,
# every rule interpreted.
for cov in even odd none; do
  rm -rf build config/cache
  if SLOG_NATIVE_COVERAGE=$cov SLOG_OPT=0 timeout 1800 bash tests/run-tests.sh \
       tests/n1_symmetric.slog tests/tycheck_basic.slog tests/dem_lambda.slog \
       > "$WORK/cov-$cov.log" 2>&1; then
    echo "PASS mixed-tier-$cov"
    PASS=$((PASS+1))
  else
    echo "FAIL mixed-tier-$cov (see $WORK/cov-$cov.log)"
    FAIL=$((FAIL+1))
  fi
done

# RF4 observes the exact partition T4 executes. A focused native replay under
# partial coverage must expose a mixed attachment with both lists nonempty;
# unrelated kernels retain their own independently keyed rows.
rm -rf build config/cache; mkdir -p build
if SLOG_NATIVE_COVERAGE=even SLOG_OPT=0 \
     SLOG_EMIT_PROGRAM_IMAGES="$WORK/rf4-images" \
     timeout 900 racket compiler/run.rkt \
     --no-banner --debug-dir "$WORK/rf4-mixed" tests/n1_symmetric.slog \
     > "$WORK/rf4-mixed.log" 2>&1; then
  mixed_sos="$(grep -oE '\(fixpoint [0-9]+ "[a-f0-9_]+"' "$WORK/rf4-mixed.log" \
    | grep -oE '[a-f0-9_]{6,}' \
    | while read -r h; do so="build/$h.O0.so"; [ -f "$so" ] || so="build/$h.so"; echo "$so"; done)"
  mixed_image="$(find "$WORK/rf4-images" -maxdepth 1 -type f -name '*.pimg' -print -quit)"
  mixed_image_file="${mixed_image##*/}"
  mixed_image_key="${mixed_image_file%.pimg}"
  # shellcheck disable=SC2086
  racket tests/api/drive.rkt $mixed_sos \
    "(mount-program-image \"$mixed_image\")" \
    "(catalog attachments)" \
    "(catalog program \"$mixed_image_key\" materializations)" \
    > "$WORK/rf4-mixed-catalog.log" 2>&1
  if racket tests/api/catalog-check.rkt < "$WORK/rf4-mixed-catalog.log" \
     && grep -qE '^\(catalog-executor-attachment .*\(tier mixed\).*\(native \([0-9].*\) \(interpreted \([0-9]' "$WORK/rf4-mixed-catalog.log" \
     && grep -qE '^\(catalog-program-materialization .*\(cache-state ready\).*\(native \([0-9].*\) \(interpreted \([0-9]' "$WORK/rf4-mixed-catalog.log"; then
    echo "PASS rf4-mixed-coverage-observed"
    PASS=$((PASS+1))
  else
    echo "FAIL rf4-mixed-coverage-observed (see $WORK/rf4-mixed-catalog.log)"
    FAIL=$((FAIL+1))
  fi
else
  echo "FAIL rf4-mixed-coverage-setup (see $WORK/rf4-mixed.log)"
  FAIL=$((FAIL+1))
fi

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
