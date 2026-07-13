# Extending Slog

There are two relatively small extension seams:

- A primitive is a synchronous value operation called directly by generated
  rule code.
- An oracle is an asynchronous daemon service behind an `extern` demand
  relation.

Use a Slog library before either when rules and existing primitives express
the operation well. Libraries remain portable, inspectable, and testable in
the language. Add a primitive for a cheap hot operation over existing runtime
values. Add an oracle for work that is slow, blocking, process-backed, or
better memoized as external answers.

This guide describes the implementation as it exists now. Both seams are
internal source extensions: they require rebuilding Slog and have no dynamic
plugin registration file.

## Before changing the runtime

Decide which category the feature belongs to:

| Need | Best fit |
|---|---|
| relational traversal, recursion, memoization | a `demand` library |
| a new immutable data shape | `struct`, `union`, or native collections |
| a cheap operation on existing encoded values | primitive |
| filesystem/process/network/solver work | oracle, with an explicit persistence policy |
| new syntax | parser plus several compiler passes; not just a primitive |
| a new primitive runtime type/tag | value encoding, I/O, type system, persistence, and migration work |

A “small” primitive that returns a new kind of boxed C++ object is not small.
Slog values must be comparable, internable, printable, persistent, reloadable,
and safe across parallel phases. Prefer an existing value type or an ordinary
Slog struct.

## Add a primitive

We will use a total integer clamp as a running example:

```slog
(clamp X Low High)
```

It returns `Low` when `X < Low`, `High` when `X > High`, and `X` otherwise.

### 1. Add the compiler signature

Primitive signatures live in `compiler/primitives.rkt` in `prim-fun-env`:

```racket
clamp (fun int int int -> int)
```

Available signature types include concrete names such as `int`, `float`,
`str`, `cseq`, `cset`, `cmap`, and `coll`, plus the compiler's polymorphic
variables such as `A`. Read nearby signatures before using a polymorphic
variable: it is the existing `any`-style escape hatch, not a full Java-like
generic constraint system.

Adding an alphanumeric value primitive needs no parser change. The parser
already accepts `(clamp A B C)` as a call, and the later passes recognize it
from `prim-fun-env`.

Comparisons are different. `<`, `<=`, `>`, and `>=` are body-only guards
recognized by `primitive-cmp?` and emitted on specialized paths. A new guard
operator needs changes beyond `prim-fun-env`.

### 2. Implement the C++ entry point

Generated code calls:

```cpp
_prim_NAME(db, arguments...)
```

For the example, add a function reachable through `daemon/prims.h`:

```cpp
inline u64 _prim_clamp(slog::Database* db, u64 x, u64 lo, u64 hi)
{
  if (!is_int(x) || !is_int(lo) || !is_int(hi))
  {
    db->setPendingError(slog::ERR_TYPE, "clamp", x, lo);
    return slog_error;
  }
  if (db->cmpInt(x, lo) < 0) return lo;
  if (db->cmpInt(x, hi) > 0) return hi;
  return x;
}
```

An alphanumeric name is unchanged. Operator symbols are escaped by the
compiler: for example, `+` currently calls `_prim__0002b`. Use an ordinary
identifier for a new primitive unless it truly extends surface operator
syntax.

Keep a small dispatcher in `prims.h` and put substantial kernels in a focused
header, following `int_prims.h`, `seq_prims.h`, and `str_prims.h`. Include that
header from `prims.h` at a point where the needed `Database` definition is
available.

The daemon headers are part of the generated-plugin fingerprint. Changing or
adding an included header invalidates relevant compiled plugins. The launcher
also rebuilds a daemon older than any daemon `.h` or `.cpp` file.

### 3. Use value tags and encoders correctly

Primitive arguments and results are encoded `u64` Slog words. Common checks
are:

```cpp
is_s32(v)    // compact integer only
is_mpz(v)    // bignum integer only
is_int(v)    // either integer representation
is_float(v)
is_str(v)    // small string or rope string
is_struct(v)
is_cnode(v)  // native set/map collection
is_seq(v)    // native list
```

Do not assume every `int` is a 32-bit immediate. Use `Database::cmpInt` for
comparison and existing integer kernels or GMP views for arithmetic. Normalize
new integer results through `Database::encodeInt`, `encodeMpz`, or
`encodeIntLiteral`; do not leave a value in a noncanonical large/small form.

Use `db->encodeString` for arbitrary user string content. The lower-level
`str_encode` helper is intended for known short internal strings such as
operation names and locations; it does not normalize a long rope value.

`float_encode` returns `slog_error` for NaN. If your operation can produce NaN,
set `ERR_NAN` before returning that sentinel, following the floating dispatch
macros.

Use `db->collections()` and `db->sequences()` for native values. Read the
existing kernels for canonical construction and bounds behavior. Never return
a pointer, process-local address, or arbitrary arena index as a Slog word.

### 4. Choose total, partial, or erroneous behavior

A total primitive returns one result for every valid typed input.

A partial primitive treats ordinary absence as a failed rule match. Add its
name to `prim-partial-set` in `compiler/primitives.rkt` and give the C++
function a final `bool* ok` parameter:

```cpp
inline u64 _prim_find_something(slog::Database* db,
                                u64 input,
                                bool* ok)
{
  if (/* expected value is absent */)
  {
    *ok = false;
    return 0;
  }
  return /* encoded result */;
}
```

The lowerer emits a `letp` call and abandons the current row when `ok` becomes
false. Do not set `ok = false` for a wrong runtime type. Partiality is for a
normal no-result case such as an absent key, invalid index, or failed parse.

For bad dynamic data, prefer a recoverable error when an existing error kind
fits:

```cpp
db->setPendingError(slog::ERR_TYPE, "clamp", x, lo);
return slog_error;
```

The compiler currently treats every recognized primitive call as potentially
fallible and emits a sentinel check after it. A stratum containing primitives
wires all built-in primitive error arms, so returning `slog_error` with a
pending kind produces the matching `(error E)` fact and abandons the
deduction.

Available pending kinds are:

```text
ERR_DIV0 ERR_MOD0 ERR_INT_OVF ERR_NAN ERR_TOINT ERR_TYPE
ERR_MPZ_OVF ERR_MPZ_TABLE
```

Use `fatal` for a violated internal invariant or corrupt state, not for a
normal property of user input. Some older collection dispatchers still use
fatal type contracts; new work should follow the recoverable path when it can
report a useful existing error.

Adding a new error kind is cross-cutting. Update at least:

- `ErrorKind` and pending error production in `daemon/database.h`;
- arm materialization in both normal and count versions of
  `daemon/operators.h`;
- the arm struct and `error_spec` union in `compiler/modules.rkt`;
- field arity and `prim-error-arms` in `compiler/type-system.rkt`;
- tests and the built-in reference.

If the new failure does not need a distinct public shape, use an existing
`type_mismatch`, `nan_result`, or cap error instead of expanding the protocol.

### 5. Decide whether a lattice may use it while ascending

The safe default is no. `compiler/lattice-check.rkt` has a small explicit
whitelist of monotone transfer operations for each lattice kind.

If `clamp` consumes a still-changing minimum, its monotonicity depends on
bounds and argument positions. Do not add it to the whitelist just because one
program happens to work. State the lattice order, prove monotonicity in every
tainted position, define the output specification, and add positive and
negative checker tests.

If a primitive only runs after its lattice input is closed, it needs no
whitelist entry. Splitting an analysis into a later stratum is often the
clearest choice.

Collection operations need extra care. `cjoin` is spec-aware and lowered
specially because a runtime collection word does not carry its child lattice
join. A new operation with the same need cannot be implemented as a plain
`_prim_NAME` dispatcher alone.

### 6. Consider persistence and parallel safety

Primitive code runs inside generated read tasks on OpenMP workers.

- Do not use unsynchronized mutable global state.
- Do not retain pointers into a temporary row or batch.
- Use database-owned thread-safe interners and arenas in phases where existing
  primitives use them.
- Return canonical content so equality and binary replay remain valid.
- Respect bignum, list, collection, and string caps/normalization.
- Make behavior deterministic from arguments and database content. A primitive
  whose result changes with clock, random state, filesystem, or network breaks
  replay and fixpoint reasoning; use an oracle with recorded answers instead.

No database format change is needed when a primitive only produces existing
value kinds. A new tag, arena, or relation kind needs an encoding-version bump
and a migration story.

### 7. Test the primitive

Add tests at the levels its behavior crosses:

1. Type/checker unit tests for accepted and rejected signatures.
2. A small `.slog` golden test covering normal results.
3. Boundary tests: small/big integers, mixed types if allowed, Unicode,
   empty collections, or index edges as relevant.
4. Partial tests proving no row and no error on an ordinary miss.
5. Runtime-error tests proving the exact `(error E)` shape.
6. Lattice checker tests for every newly allowed transfer position.
7. Exact save/load and compressed replay if it builds persistent values in a
   new way.
8. Direct C++ unit tests for a substantial kernel.

During development, run a focused golden without clearing the cache:

```console
$ tests/run-tests.sh --keep-cache tests/clamp.slog
```

Then run the relevant named harnesses and finally `tests/run-all.sh` before
landing a cross-runtime change.

Update [built-in operations](builtins.md) in the same change. The complete
primitive checklist there makes omissions visible.

## Add an oracle

An oracle is an externally answered demand. The surface and daemon halves meet
by a symbolic registry name.

We will sketch an oracle named `parity` that returns integer code `0` for even
and `1` for odd. This work is intentionally overkill for parity; a primitive
would be better. The small example makes the interface visible.

### 1. Design a raw extern and a user wrapper

Current `extern` syntax is:

```slog
extern ORACLE-NAME (DEMAND-NAME INPUT-TYPE) ANSWER-TYPE
```

The v1 boundary requires exactly one input and exactly one answer. The answer
type must be `int`, `cmap`, or `cset`.

For parity:

```slog
extern parity (parity_raw int) int

enum (parity_result even odd)
demand (parity_of int) parity_result

table (parity_code int parity_result)
rule
(parity_code 0 (even))
(parity_code 1 (odd))

rule (= Code (parity_raw N))
     (parity_code Code Result)
  --> (parity_of N Result)
```

Keep the extern raw and narrow. A Slog wrapper can translate integer status
codes into enums, split a collection envelope, expose several convenient
views, and give unknown/failure behavior a clear policy. `lib/smt.slog`
follows this pattern.

Rules may not write `parity_raw_ans`; the compiler rejects user heads targeting
an oracle-owned answer table.

### 2. Implement `Oracle`

Add a header under `daemon/` with a class derived from `slog::Oracle`:

```cpp
class ParityOracle : public slog::Oracle
{
public:
  bool serialize(slog::Database* db,
                 u64 value,
                 std::string& out,
                 std::string& err) override
  {
    if (!is_int(value))
    {
      err = "parity expects an integer";
      return false;
    }
    out = db->writeValCSV(value);
    return true;
  }

  slog::OracleResult solve(const std::string& request) override
  {
    slog::OracleResult result;
    for (auto it = request.rbegin(); it != request.rend(); ++it)
      if (*it >= '0' && *it <= '9')
      {
        result.code = (*it - '0') & 1;
        return result;
      }
    return unknownResult();
  }
};
```

This is only a shape example. Production serialization should define a stable
unambiguous request grammar and parse it rigorously.

The contract is:

```cpp
virtual bool serialize(Database*, u64 value,
                       std::string& request, std::string& error) = 0;
virtual bool solveEager(Database*, u64 value, OracleResult& out);
virtual OracleResult solve(const std::string& request) = 0;
virtual OracleResult unknownResult();
```

`serialize` runs in a stratum read phase with safe read access to the database.
It must turn the one input value into a self-contained request. Do every
database lookup here.

`solve` runs on an oracle pool thread. It must not touch `Database`, relation
indexes, interners, or arenas. It may call a process or library using only the
serialized request. The registry catches escaping exceptions and substitutes
`unknownResult`, but the implementation should handle and report its own
failures when possible.

`solveEager` is optional for a cheap deterministic backend that can answer in
the database read phase. SMT's mock solver uses it. Even eager oracles are
passed through serialization first so validation behavior is consistent.

### 3. Choose an answer recipe

`OracleResult` can carry:

```cpp
s32 code;
bool is_map;
std::vector<std::pair<std::string, std::string>> entries;
std::vector<std::pair<u64, s64>> word_entries;
```

With `is_map == false`, harvest emits `code` as a small integer answer.

With `is_map == true`, harvest builds a native collection containing:

- string key `"@status"` mapped to `code`;
- each string entry parsed as an exact decimal integer;
- each raw-word key mapped to its small integer value.

This is a recipe because the pool thread cannot intern strings or collection
nodes. Harvest materializes it later with the database in hand.

The current collection result shape is inherited from SMT and always includes
`@status`. The usual surface is therefore a raw `cmap` extern plus Slog rules
that read and remove the status key:

```slog
extern service (raw_query request) cmap
demand (query request) verdict cmap

rule (= Envelope (raw_query Request))
     (= Code (cget Envelope "@status"))
     (= Payload (cdel Envelope "@status"))
     (code_verdict Code Verdict)
  --> (query Request Verdict Payload)
```

Although `extern` accepts `cset`, there is no separate set recipe flag. A
collection is the same runtime representation, and the wrapper must still
account for the status entry. If a new oracle needs strings, floats,
structures, multiple answer columns, or arbitrary nested values, extend the
result recipe and harvester deliberately rather than smuggling process-local
IDs through `u64`.

### 4. Register the implementation

Make the class definition visible to `daemon/daemon.h`, normally by including
its header from the daemon include spine. In the `Daemon` constructor, add:

```cpp
oracle_registry->registerOracle("parity", new ParityOracle());
```

The registry takes ownership and deletes the instance at shutdown. Duplicate
names are fatal. If generated code binds an unknown name, the daemon fails
when the stratum is registered.

The string must match the first symbol of the Slog declaration:

```slog
extern parity (parity_raw int) int
```

No compiler registry list needs updating. The compiler carries that symbol
into generated `bindOracle` calls.

### 5. Understand dispatch, harvest, and fixpoint

For every stratum that can create the extern's request struct, generated code
registers two read-phase tasks.

Dispatch scans request delta and answer delta. Persisted answer rows mark their
request IDs answered. A new unanswered request is serialized and either solved
eagerly or submitted to the pool.

Harvest drains completed `(request-id, recipe)` pairs, materializes their Slog
values, and sends rows to the ordinary answer relation. Normal intern and
deduplication phases finish the insertion.

The registry tracks outstanding and completed work. A stratum cannot report
fixpoint while requests are in flight. When rules have no work left, the
fixpoint barrier waits for an oracle completion and gives harvest another
iteration.

One binding and its answered set persist across strata and plugin hot swaps.
An answer relation's reload delta re-seeds it, so opening a saved database does
not call the service again.

### 6. Failure and error policy

Define what each external failure means in the raw code space. For SMT, code 0
means unknown and wrappers preserve a sound “act only on proof” policy. A
network oracle might need distinct unavailable, malformed-response, and
negative-answer codes.

`unknownResult` must have the right shape. A collection oracle should override
it to set `is_map = true`, as `SmtOracle` does, or its wrapper will receive an
integer word where it expects a collection.

There is one current genericity leak: `serialize` returning false records
`(error (smt_bad_formula Reason Payload))` before supplying the unknown result.
That error name is SMT-specific even for another oracle. For a production new
oracle, either accept and document that temporary surface or generalize the
error arm and dispatcher together. Do not silently skip the failure, because
then a user cannot distinguish service unknown from malformed input.

Process timeout, crash, and stderr handling belong in the oracle
implementation. Never block an OpenMP rule task on the external call; only the
oracle pool should wait for it. Bound concurrency, wall time, memory, response
size, and child cleanup.

### 7. Persistence semantics

All extern answer relations are classified as pinned oracle relations for
compressed saves. Their rows survive sampling and replay. This is necessary
for a nondeterministic or stateful service, but it creates a contract:

- An answer is stable for the database lineage once recorded.
- Loading does not refresh it just because service configuration changed.
- A saved answer must be self-contained Slog data, not a handle to live
  external state.
- A model-like arbitrary choice is replayed exactly even if another valid
  choice would be returned today.

If freshness matters, design an explicit version or policy fingerprint into
the demand input. A request such as `(lookup service-version key)` naturally
creates a new memo key when policy changes. Do not make `solve` consult hidden
mutable state while pretending the same input has timeless meaning.

### 8. Thread-safety rules

Oracle instances are shared across bindings and worker threads.

- Treat configuration parsed in the constructor as immutable.
- Protect shared caches and process pools, or make them thread-local as SMT's
  persistent solver processes are.
- Do not access `Database` from `solve`.
- Do not return Slog intern IDs created outside harvest.
- Catch library exceptions and convert them to a documented result.
- Ensure shutdown can wake and join workers and reap child processes.
- Avoid unbounded queues; the global pool size alone does not cap response
  memory.

The registry protects its job and completion queues and uses atomic counts.
That does not make mutable fields inside your `Oracle` implementation safe.

### 9. Test the oracle

Cover at least:

1. Serialization of every supported input shape and rejection of malformed
   `any` data.
2. Direct solver/service unit tests without the fixpoint engine.
3. A Slog golden for value-position and full-arity calls.
4. More than one request, repeated requests, and calls from multiple strata.
5. Recursive/in-SCC demand use when supported.
6. Timeout, unknown, exception, malformed response, and serialize failure.
7. Collection materialization, exact large integers, and empty payloads.
8. Exact save/load proving no repeat call.
9. Compressed replay with the backend disabled, proving pinned answers suffice.
10. Shutdown with jobs in flight and the configured worker pool greater than
    one.

For a subprocess backend, add gated integration tests that skip cleanly when
the executable is unavailable, plus a deterministic fake executable for
timeout/race/protocol tests. Do not make the golden suite depend on the timing
or version of an installed external service.

Update the relevant library guide and [architecture](architecture.md) when the
new oracle changes the generic result or failure contract.

## Extension review checklist

Before calling an extension complete, check:

- Is the feature better expressed in Slog itself?
- Is its source signature precise, including partiality and answer count?
- Does every runtime result use an existing canonical encoder?
- Are expected absence, bad user data, and internal corruption separated?
- Is same-fixpoint lattice use rejected or proved monotone?
- Is behavior deterministic, or recorded through an oracle answer?
- Does the code obey OpenMP/oracle thread boundaries?
- Do exact load and compressed replay preserve the result?
- Are focused, boundary, failure, and full-suite tests present?
- Does the user reference list the new public name and exact behavior?
