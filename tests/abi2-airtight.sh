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
#   (d) every crule lands in exactly one kernel or the prelude;
#   (g) T4 slice 1a: an unrelated same-level rule requisitioning a NEW
#       ordering on a shared relation changes no existing kernel's key
#       (slot payloads are kernel-local, not stratum-union);
#   (h) T4 slice 1a's cross-program payoff: a program that consumes a
#       library's exports differently (an extra ordering on left.edge)
#       still shares the library kernel's key with one that does not.
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
  # PIN the shipped artifact to ABI 1: since the flip the default is the
  # cohort, and the constants cross-check below is only a cross-SHAPE check
  # while the shipped plan and the dump genuinely differ in shape
  SLOG_PLAN_ABI=1 SLOG_DUMP_ABI2="$2" timeout 900 racket compiler/run.rkt "$1" \
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

# (f) the SERVICE PRELUDE is identical across unrelated programs.  Kernel
# slot numbering starts with the same language-level service list everywhere
# (canonical-plan.rkt service-names); a program missing one service would
# shift every later slot and silently forfeit cross-program kernel sharing.
# This is the empirical pin for the "identical in every program" claim that
# claim (c) below rests on.
service_prefix_of() {
  python3 - "$1" <<'PYEOF'
import glob, re, sys
services = {'malformed_deduction', '_enum', 'error', 'div_by_zero',
            'modulo_by_zero', 'int_overflow', 'nan_result', 'toint_range',
            'type_mismatch', 'mpz_overflow', 'mpz_table_overflow'}
prefixes = set()
for f in sorted(glob.glob(sys.argv[1] + '/*.abi2')):
    t = open(f).read()
    for m in re.finditer(r'\(binding (.*?)\) \(dynamic', t, re.S):
        slots = re.findall(r'\(slot (\d+) ([^)]+)\)', m.group(1))
        names = [n for _, n in sorted(slots, key=lambda s: int(s[0]))]
        k = 0
        while k < len(names) and names[k] in services:
            k += 1
        prefixes.add('|'.join(names[:k]))
print('\n'.join(sorted(prefixes)))
PYEOF
}
base_prefix="$(service_prefix_of "$WORK/d-base")"
consts_prefix="$(service_prefix_of "$WORK/d-consts")"
if [ -z "$base_prefix" ]; then
  bad "service-prelude-shared" "no binding prefixes extracted"
elif [ "$(printf '%s\n%s\n' "$base_prefix" "$consts_prefix" | sort -u | wc -l)" -eq 1 ]; then
  ok "service-prelude-shared"
else
  bad "service-prelude-shared" \
      "prefixes differ across programs or kernels: [$base_prefix] vs [$consts_prefix]"
fi

# (c) the payoff: two instances of one library share a kernel key
compile_dump tests/n1_instances.slog "$WORK/d-n1"
shared="$(keys_of "$WORK/d-n1" | uniq -d | wc -l)"
if [ "$shared" -ge 1 ]; then
  ok "two-instances-share-a-kernel-key"
else
  bad "two-instances-share-a-kernel-key" "no key appears twice"
fi

# (i) T4 slice 3a: a STRUCT-USING library shares too.  Its kernel carries a
# tycheck whose accept set names an instance-qualified struct (a.wrap vs
# b.wrap); those names rode the hashed exec bytes until 3a made them slot
# references -- the gap recorded at (2b) entry, closed here.
cat > "$WORK/ty_lib.slog" <<'EOF'
union (box (wrap int))
table (raw any)
table (unwrapped box)

rule (raw X) --> (unwrapped X)
EOF
cat > "$WORK/ty_twice.slog" <<'EOF'
instantiate "ty_lib.slog" as a
instantiate "ty_lib.slog" as b

table (feed int)

rule
(feed 1)
(feed 2)

rule (feed X) --> (a.raw X)
rule (feed X) --> (b.raw X)
EOF
compile_dump "$WORK/ty_twice.slog" "$WORK/d-ty"
ty_shared="$(keys_of "$WORK/d-ty" | uniq -d | wc -l)"
ty_accepts="$(grep -ho '(accept (struct (rel [0-9]*))' "$WORK/d-ty"/*.abi2 | wc -l)"
if [ "$ty_accepts" -eq 0 ]; then
  bad "struct-library-shares-a-kernel-key" "fixture produced no slot-relative accepts"
elif [ "$ty_shared" -ge 1 ]; then
  ok "struct-library-shares-a-kernel-key"
else
  bad "struct-library-shares-a-kernel-key" "no key appears twice despite tycheck kernels"
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

# (g) T4 slice 1a's exit property (t4-contract §3 slice 1): kernel slot
# payloads carry only the kernel's OWN orderings, so an unrelated rule at
# the same stratification level that requisitions a NEW ordering on a
# shared relation must move no existing kernel's bytes.  The added rule's
# selection ({1}) is deliberately NOT subset-related to the base rule's
# ({0,2}): the greedy index packer serves subset-CHAINS with one ordering,
# so a subset-related addition can legitimately re-pack an existing probe
# assignment -- that deeper, packer-level sibling dependence is a separate
# (recorded) phenomenon this check must not conflate with slot payloads.
# This check REFUTED the slice's first draft (keep each decl's leading
# index as "identity"): a plain relation's master is the packer's
# EMPTY-selection assignment, and the empty selection chains with
# everything, so the sibling's {1} re-homed edge's master (0 2 1)->(1 0 2)
# and re-keyed the path kernel through an ordering it never uses.  Slot
# payloads are therefore PURE own-use; nothing rides as identity.
cat > "$WORK/inv-base.slog" <<'EOF'
table (edge int int int)
table (path int int int)

rule
(edge 1 2 7)
(edge 2 3 7)

rule (edge X Y Z) --> (path X Y Z)
rule (path X Y Z) (edge Y W Z) --> (path X W Z)
EOF
{ cat "$WORK/inv-base.slog"; cat <<'EOF'

table (query int)
table (hit int int)

rule (query B) (edge X B Y) --> (hit X Y)
EOF
} > "$WORK/inv-sibling.slog"

compile_dump "$WORK/inv-base.slog"    "$WORK/d-inv-base"
compile_dump "$WORK/inv-sibling.slog" "$WORK/d-inv-sibling"
if [ -z "$(keys_of "$WORK/d-inv-base")" ]; then
  bad "sibling-requisition-changes-no-key" "no base keys extracted; see $WORK"
elif comm -23 <(keys_of "$WORK/d-inv-base" | uniq) \
              <(keys_of "$WORK/d-inv-sibling" | uniq) \
       | grep -q .; then
  bad "sibling-requisition-changes-no-key" \
      "a base kernel's key is absent from the sibling compile: $(comm -23 <(keys_of "$WORK/d-inv-base" | uniq) <(keys_of "$WORK/d-inv-sibling" | uniq) | tr '\n' ' ')"
else
  ok "sibling-requisition-changes-no-key"
fi

# (h) the cross-program half: asymmetric consumption of a library's exports
# no longer forfeits sharing.  Program B probes left.edge on a selection the
# library never uses; the library kernel (members left.path) must keep the
# SAME key in both programs.
key_of_members() { # <dumpdir> <member-name>
  python3 - "$1" "$2" <<'PYEOF'
import glob, re, sys
for f in sorted(glob.glob(sys.argv[1] + '/*.abi2')):
    t = open(f).read()
    for m in re.finditer(r'\(kernel \(ord \d+\) \(key "([0-9a-f]+)"\) \(members ([^)]*)\)', t):
        if sys.argv[2] in m.group(2).split():
            print(m.group(1))
PYEOF
}
cat > "$WORK/asym-a.slog" <<'EOF'
instantiate "n1_graph_lib.slog" as left

table (seed int int)
table (answer int int)

rule
(seed 1 2)
(seed 2 3)

rule (seed X Y) --> (left.edge X Y)
rule (left.path X Y) --> (answer X Y)
EOF
{ cat "$WORK/asym-a.slog"; cat <<'EOF'

table (meet int int)

rule (left.edge X Y) (left.edge Z Y) --> (meet X Z)
EOF
} > "$WORK/asym-b.slog"
# instantiate resolves the library path relative to the program file
cp tests/n1_graph_lib.slog "$WORK/"

compile_dump "$WORK/asym-a.slog" "$WORK/d-asym-a"
compile_dump "$WORK/asym-b.slog" "$WORK/d-asym-b"
lib_a="$(key_of_members "$WORK/d-asym-a" left.path)"
lib_b="$(key_of_members "$WORK/d-asym-b" left.path)"
if [ -z "$lib_a" ] || [ -z "$lib_b" ]; then
  bad "asymmetric-consumption-shares-the-kernel" \
      "library kernel not found (a=[$lib_a] b=[$lib_b])"
elif [ "$lib_a" = "$lib_b" ]; then
  ok "asymmetric-consumption-shares-the-kernel"
else
  bad "asymmetric-consumption-shares-the-kernel" \
      "library kernel re-keyed by a consumer's requisition: $lib_a vs $lib_b"
fi

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
