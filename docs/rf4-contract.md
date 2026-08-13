# RF4 native materialization and coverage contract

**Status:** complete 2026-08-09. Execution equivalence was already shipped by
T4; RF4 makes that boundary observable and pins cache-miss behavior.

RF4 closes the native side of the program-image experiment. A sealed
`ProgramImage` and its `KernelExecPlan`s remain semantic truth. Native code is
a content-addressed, optional materialization of selected kernel variant
slots; the decoded interpreter is the always-available complement.

## 1. Identities

- `ArtifactKey` is SHA-256 of the exact descriptor `.so` bytes. A pathname is
  only an availability hint and never participates in program semantics.
- A descriptor kernel-table index is its `native-slot`. Its existing `key`
  field is the sealed `KernelExecPlan` key. No relation name, `RuleId`, or live
  pointer is recovered from a filename.
- A variant slot is the dense kernel-local `rule-def (ord N)` ordinal already
  carried by Plan ABI 2. Descriptor `covered` is exactly the native slot set;
  its complement is interpreted.
- A live attachment is identified observationally by `(scc,
  attachment-slot)` within one daemon evaluation. It records the plan key,
  optional artifact/native slot, complete variant partition, and the
  attachment-local read/write bindings. RF5 may later give published program
  instances a durable attachment identity; RF4 does not mint one early.

The descriptor ABI does not change for RF4. T4 interface 3 already names the
kernel plan and variant slots exactly; RF4 copies those values into the
control plane after the production attach path has validated them.

## 2. Control-catalog records

The daemon exposes three additive views:

```text
(catalog artifacts)
  -> catalog-native-artifact ... state ready|miss ...

(catalog artifact "ARTIFACT-KEY")
  -> catalog-native-artifact-kernel
       artifact-key native-slot plan-key frame-width variants
       native interpreted attachments

(catalog attachments)
  -> catalog-executor-attachment
       scc attachment-slot stratum plan-key artifact-key native-slot tier
       variants native interpreted writes reads
```

The image-local join is:

```text
(catalog program "IMAGE-KEY" materializations)
  -> catalog-program-materialization
       image-key plan-slot kernel-ordinal plan-key artifact-key cache-state
       variants native interpreted artifact-attachments
       interpreted-attachments
```

It joins immutable image plans to nondeterministic artifact observations by
`(KernelExecPlan key, native-slot)`. If no artifact is known, the catalog
still emits one row with `artifact-key #f`, `cache-state miss`, no native
variants, and the whole variant set interpreted. Thus absence of code is an
explicit cache observation, never absence of program semantics.

These rows are control/observation-plane data. Application rules cannot name
them, database saves omit them, and replay does not depend on them.

## 3. Availability and deletion

Loading a descriptor copies its content identity and slot tables into the
daemon registry. Catalog reads re-check all observed paths:

- at least one regular path whose current bytes still hash to the recorded
  `ArtifactKey`: `state ready` / `cache-state ready`;
- no regular path: `state miss` / `cache-state miss`.

A loaded task remains safe after its file is removed because the process
retains the `dlopen` handle. Future materialization treats the vanished file
as a cache miss and may rebuild the same content. It never invalidates the
program image, removes interpreted coverage, or turns a cache claim into a
durable path promise.

## 4. Coverage invariants

For every attached kernel:

1. `native` and `interpreted` are disjoint, ordered variant-slot lists;
2. their union is exactly `[0, variants)`;
3. `tier` is `interpreted`, `native`, or `mixed` from that partition;
4. partial coverage attaches the interpreted complement from the same sealed
   plan and does not rebuild any unrelated kernel; and
5. artifact observations are published only after the ordinary T4 descriptor
   key/frame/rule-count/coverage checks and attach complete.

T4's `SLOG_NATIVE_COVERAGE=even|odd|none` equivalence gates remain the
execution proof. RF4 adds catalog gates over the same runs so partial coverage
and shared attachments are visible through structured records rather than
inferred from mangled filenames. The RF4 gate also unlinks a copied cache
artifact after attachment and observes `state miss`, and mounts the matching
ProgramImage to prove the image-slot/materialization join.

## 5. Non-goals

RF4 does not add asynchronous compile requests, compiler queues, tier swaps,
durable cache retention policy, or program replacement. RF5-B owns the live
program transaction; a later compiler-service slice may add request/progress
records without changing these materialization identities.
