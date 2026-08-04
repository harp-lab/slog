#!/usr/bin/env bash
#
# RF1 slice 2's airtightness gate (docs/rf1-contract.md Slices item 2): the
# whole point of splitting the plan is that a KernelPlanKey identifies a
# COMPUTATION, so it must be immune to everything that is not one.
#
#   (a) a DebugMap-only edit -- moving a rule to a different line -- changes
#       no kernel key;
#   (b) a rename changes the BINDING SCHEMA only, not any kernel key;
#   (c) two instances of one library SHARE a kernel key (the payoff);
#   (d) every crule lands in exactly one kernel or the prelude.
#
# Tested end to end over real compiles rather than synthetic cprogs, because
# the property has to hold of what the compiler actually emits.  Emission is
# still ABI-1 by default; this drives the ABI-2 audit instrument
# (SLOG_DUMP_ABI2), which is what makes the property testable before the
# daemon can read the new shape.
#
#   bash tests/abi2-airtight.sh

set -u
cd "$(dirname "$0")/.."
WORK="$(mktemp -d)"
trap 'rm -rf "$WORK"' EXIT
PASS=0; FAIL=0
ok()   { echo "PASS $1"; PASS=$((PASS+1)); }
bad()  { echo "FAIL $1 ($2)"; FAIL=$((FAIL+1)); }

# keys of every kernel in a dump directory, sorted
keys_of() { grep -ho '(key "[0-9a-f]*")' "$1"/*.abi2 2>/dev/null | LC_ALL=C sort; }
# the SET of names bound by every kernel.  A grep for a prefix of the
# `(binding ...)` form silently stopped discriminating once the service
# prelude took the leading slots -- it compared the prelude and nothing else,
# so a rename looked like no change at all.  Parse the form instead.
bindings_of() {
  python3 - "$1" <<'PYEOF'
import glob, re, sys
names = set()
for f in sorted(glob.glob(sys.argv[1] + '/*.abi2')):
    t = open(f).read()
    for m in re.finditer(r'\(binding (.*?)\) \(dynamic', t, re.S):
        names.update(re.findall(r'\(slot \d+ ([^)]+)\)', m.group(1)))
print("\n".join(sorted(names)))
PYEOF
}

compile_dump() { # <program> <dumpdir>
  rm -rf build config/cache "$2" "$2.abi1"
  SLOG_DUMP_ABI2="$2" timeout 900 racket compiler/run.rkt "$1" \
    > "$WORK/$(basename "$2").log" 2>&1
  # snapshot THIS compile's ABI-1 plans beside its ABI-2 dump: build/ is
  # wiped by the next fixture, so a later cross-check would otherwise
  # compare two different programs and pass for the wrong reason
  mkdir -p "$2.abi1"
  cp build/*.plan "$2.abi1"/ 2>/dev/null || true
}

# --- the fixture, generated so the repo gains no single-use .slog ----------
cat > "$WORK/base.slog" <<'EOF'
table (edge int int)
table (path int int)

rule
(edge 1 2)
(edge 2 3)

rule (edge X Y) --> (path X Y)
rule (path X Y) (edge Y Z) --> (path X Z)
EOF

# (a) DebugMap-only edit: the same rules, moved down two lines
{ echo ";; a comment"; echo ";; and another"; cat "$WORK/base.slog"; } \
  > "$WORK/moved.slog"

# (b) rename: path -> reach throughout (a pure binding-schema change)
sed 's/\bpath\b/reach/g' "$WORK/base.slog" > "$WORK/renamed.slog"

compile_dump tests/structs.slog   "$WORK/d-consts"   # ground facts => constants
compile_dump "$WORK/base.slog"    "$WORK/d-base"
compile_dump "$WORK/moved.slog"   "$WORK/d-moved"
compile_dump "$WORK/renamed.slog" "$WORK/d-renamed"

if [ -z "$(keys_of "$WORK/d-base")" ]; then
  bad "abi2-dump-produced" "no .abi2 files; see $WORK"
else
  ok "abi2-dump-produced"
fi

if diff <(keys_of "$WORK/d-base") <(keys_of "$WORK/d-moved") > "$WORK/a.diff"; then
  ok "debugmap-edit-changes-no-key"
else
  bad "debugmap-edit-changes-no-key" "$(head -4 "$WORK/a.diff" | tr '\n' ' ')"
fi

if diff <(keys_of "$WORK/d-base") <(keys_of "$WORK/d-renamed") > "$WORK/b.diff"; then
  ok "rename-changes-no-key"
else
  bad "rename-changes-no-key" "$(head -4 "$WORK/b.diff" | tr '\n' ' ')"
fi

if diff <(bindings_of "$WORK/d-base") <(bindings_of "$WORK/d-renamed") \
     > /dev/null; then
  bad "rename-changes-the-binding" "binding schemas identical after a rename"
else
  ok "rename-changes-the-binding"
fi

# (e) SEMANTIC cross-check against the shipped ABI-1 plan.  The key/binding
# assertions above are blind to meaning: they passed while the emitter was
# silently degrading every constant into a register (const-slot keyed by
# value, but the IR hands it a globalized NAME, so the lookup missed and
# canonicalize-crule fell through to its register branch).  Constants are
# content-addressed -- `const<sha24>` OF THE VALUE -- so the same compile's
# ABI-1 plans and ABI-2 cohorts must name exactly the same constant set.
# `(k N)` with nothing after the number is a REFERENCE from an op; the
# 4-field `(k N name value)` is a table entry.  Count the references.
refs_abi1="$(grep -ho '(k [0-9]*)' "$WORK/d-consts.abi1"/*.plan 2>/dev/null | wc -l)"
refs_abi2="$(grep -ho '(k [0-9]*)' "$WORK/d-consts"/*.abi2 2>/dev/null | wc -l)"
if [ "$refs_abi1" -eq 0 ]; then
  bad "constants-survive-the-split" "fixture produced no constant references"
elif [ "$refs_abi1" -eq "$refs_abi2" ]; then
  ok "constants-survive-the-split"
else
  bad "constants-survive-the-split" \
      "abi1 makes $refs_abi1 constant references, abi2 makes $refs_abi2"
fi

# (c) the payoff: two instances of one library share a kernel key
compile_dump tests/n1_instances.slog "$WORK/d-n1"
shared="$(keys_of "$WORK/d-n1" | uniq -d | wc -l)"
if [ "$shared" -ge 1 ]; then
  ok "two-instances-share-a-kernel-key"
else
  bad "two-instances-share-a-kernel-key" "no key appears twice"
fi

# (d) partition coverage: kernels' rule counts plus prelude entries account
# for every rule-def emitted, per cohort
covered=0
for f in "$WORK"/d-n1/*.abi2; do
  declared="$(grep -o '(rules [0-9]*)' "$f" | grep -o '[0-9]*' \
              | awk '{s+=$1} END {print s+0}')"
  emitted="$(grep -o '(rule-def ' "$f" | wc -l)"
  if [ "$declared" -ne "$emitted" ]; then
    bad "partition-covers-every-crule" "$(basename "$f"): manifest says $declared, kernels emit $emitted"
    covered=1
  fi
done
[ "$covered" -eq 0 ] && ok "partition-covers-every-crule"

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
