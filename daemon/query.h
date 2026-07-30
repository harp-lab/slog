/** Slog read-only interpreted queries (Q1 / R2 engine seam).
 *
 * Query plans reuse the frozen monotone Machine and its bound-sink seam, but
 * own their full-index driver, pagination, cancellation, and literal probes.
 * No query task enters RunState and no query sink can reach Relation::sendBatch.
 */

#pragma once

#include "plan.h"

#include <memory>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace slog
{
namespace query
{

enum class Mode : u8 { rows, count, exists };
enum class Status : u8 { page, paused, complete, cancelled };

// The dispatcher supplies the daemon phase in which it admitted the query.
// All four states have immutable master indices; write/intern is refused.
enum class Admission : u8
{
  idle,
  boundary,
  mid_read,
  read_complete,
  write_or_intern
};

enum class ErrorK : u8
{
  parse,
  plan,
  unsafe_compute,
  literal,
  binding,
  admission,
  pagination
};

const char* error_class(ErrorK kind);

struct Error : std::runtime_error
{
  ErrorK error_kind;

  Error(ErrorK kind, const std::string& message)
    : std::runtime_error(message), error_kind(kind) {}

  ErrorK kind() const { return error_kind; }
};

enum class LiteralK : u8 { integer, real, string };

struct Literal
{
  u16 reg = 0;
  LiteralK kind = LiteralK::integer;
  std::string text;
};

// Probe-only literal resolution (query.cpp): true + the encoded word when
// the value exists (inline scalars always do), false when the interner has
// never seen it, and a typed Error for malformed text.  Shared with the R2
// `uses` value-search verb so one resolution semantics serves both.
bool resolve_literal(Database& db, const Literal& literal, u64& word);

struct ScanFullPlan
{
  u16 relation = 0;
  // An exact existing physical order, or empty to request the deterministic
  // scan-plus-filter fallback over any catalogued existing full index.
  std::vector<u16> order;
  // Register for each nominal storage column. Binding remaps this vector to
  // the selected physical index order before the frozen Machine sees it.
  std::vector<u16> regs;
};

// Client-neutral R2 register shape.  rows backs `?`, count backs `?count`,
// and exists backs `?exists`; all three share one sealed body.
struct Plan
{
  u16 nregs = 0;
  std::vector<std::pair<u16, u64>> preloads;
  std::vector<Literal> literals;
  std::vector<interp::StraightPlan> preops;
  ScanFullPlan driver;
  std::vector<interp::BodyPlan> body;
  std::vector<u16> project;
  Mode mode = Mode::rows;
};

// The canonical query payload carries exact boundary/catalog bindings beside
// the executable plan. N3-B resolves BoundaryKey to an immutable environment,
// then QName selects its slot and VersionKey proves the expected physical
// identity. Runtime shape/count facts are the materialization overlay
// projected by compiler/query-plan.rkt, never index requisitions.
struct CatalogBinding
{
  std::string name;
  std::string version_key;
  u64 tuple_count = 0;
  interp::RelationShape shape;
};

struct DecodedPlan
{
  u32 abi = 0;
  std::string boundary_key;
  u64 generation = 0;
  std::vector<CatalogBinding> bindings;
  Plan plan;
};

struct SealedPlan
{
  interp::SealedRule core;
  ScanFullPlan driver;
  std::vector<Literal> literals;
  Mode mode = Mode::rows;
  u16 storage_relations = 0;
};

struct SealedRequest
{
  std::string boundary_key;
  u64 generation = 0;
  std::vector<CatalogBinding> bindings;
  SealedPlan plan;
};

// T0 typed builder boundary. The generic dispatcher embeds this payload in a
// `(query ID ... (page N))` command; it must not reinterpret the plan grammar.
DecodedPlan parse_plan(std::string_view input);
SealedRequest seal(const DecodedPlan& decoded);

// Seal against the exact catalog snapshot.  RelationShape::full_orders lists
// indices that already exist; Q1 never requisitions or builds one.
SealedPlan seal(const Plan& plan,
                const std::vector<interp::RelationShape>& relations);

// The deliberately small Q1 v1 compute boundary. The returned binding uses
// checked query adapters: unsupported runtime types abandon a row and never
// write Database::PendingError; admitted functions do not intern or mutate.
bool admits_primitive(const interp::PrimPlan& primitive);

std::unique_ptr<interp::DriverCursor> make_scan_full_driver(
  u16 arity, Index** index, u16 bucket);

class Context;

class BoundPlan
{
  SealedPlan sealed;
  std::shared_ptr<const interp::Program> program;
  std::vector<Relation*> frame;
  Database* database = nullptr;
  std::vector<std::shared_ptr<const interp::PrefixCursor>> cursor_prototypes;
  std::vector<std::shared_ptr<const interp::PrefixCursor>> prefilter_prototypes;
  std::vector<interp::BoundPrim> primitives;
  std::vector<interp::BoundPrim> pre_primitives;
  std::vector<u16> driver_order;
  std::vector<u64> initial;
  bool degraded = false;
  bool satisfiable = true;

  std::vector<std::unique_ptr<interp::PrefixCursor>> make_cursors() const;
  std::unique_ptr<interp::Machine> make_machine(
    u16 bucket, interp::BoundSink* sink) const;

  friend class Context;

public:
  BoundPlan(SealedPlan plan, std::vector<Relation*> binding, Database& db);

  Mode mode() const { return sealed.mode; }
  bool has_matches_possible() const { return satisfiable; }
  std::string explain() const;
};

std::shared_ptr<const BoundPlan> bind(
  const SealedPlan& plan, Database& db, std::vector<Relation*> binding);
std::shared_ptr<const BoundPlan> bind(
  const SealedRequest& request, Database& db);

struct Page
{
  Status status = Status::complete;
  std::vector<std::vector<u64>> rows;
  // Cumulative satisfying-instantiation count.  For exists this is 0 or 1.
  u64 matched = 0;
};

class Context
{
  class YieldSink;

  Database* database = nullptr;
  std::shared_ptr<const BoundPlan> plan;
  std::unique_ptr<YieldSink> sink;
  std::unique_ptr<interp::Machine> machine;
  u16 bucket = 0;
  Status terminal = Status::paused;
  bool owns_admission = false;

  void release_admission();
  bool ensure_machine();

public:
  Context(Database& db, std::shared_ptr<const BoundPlan> bound,
          Admission admission = Admission::idle);
  ~Context();

  Context(const Context&) = delete;
  Context& operator=(const Context&) = delete;
  Context(Context&&) = delete;
  Context& operator=(Context&&) = delete;

  // `step_budget` bounds resumable VM calls; every call runs at most one
  // committed transition, while cursor_work_budget bounds each internal
  // seek.  A row page never exceeds page_size.
  Page next(u64 page_size, u64 step_budget, u64 cursor_work_budget);
  void cancel();
  Status status() const { return terminal; }
  // Cumulative satisfying-instantiation count, including rows returned by
  // earlier pages.  The command dispatcher uses this for a cancellation
  // sentinel without advancing the cursor.
  u64 matched() const;
};

} // namespace query
} // namespace slog
