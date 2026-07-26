#include "query.h"
#include "sexp.h"

#include <algorithm>
#include <array>
#include <charconv>
#include <cctype>
#include <cmath>
#include <limits>
#include <sstream>
#include <unordered_set>

namespace slog
{
namespace query
{

using namespace interp;

namespace
{

constexpr sexp::Limits query_plan_reader_limits{
  4 * 1024 * 1024,
  250000,
  128
};

using SExp = sexp::SExp;

void require(bool condition, ErrorK kind, const std::string& message)
{
  if (!condition) throw Error(kind, message);
}

[[noreturn]] void query_syntax(const SExp& x, const std::string& message)
{
  throw Error(ErrorK::parse,
              "query plan: byte " + std::to_string(x.offset)
                + ": " + message);
}

const std::string& query_atom(const SExp& x, const char* where)
{
  if (x.kind != SExp::K::atom)
    query_syntax(x, std::string(where) + ": expected atom");
  return x.text;
}

const std::string& query_string(const SExp& x, const char* where)
{
  if (x.kind != SExp::K::string)
    query_syntax(x, std::string(where) + ": expected string");
  return x.text;
}

const std::vector<SExp>& query_list(const SExp& x, const char* where)
{
  if (x.kind != SExp::K::list)
    query_syntax(x, std::string(where) + ": expected list");
  return x.children;
}

const std::vector<SExp>& query_tagged(
  const SExp& x, const char* tag,
  size_t exact = std::numeric_limits<size_t>::max())
{
  const auto& xs = query_list(x, tag);
  if (xs.empty() || query_atom(xs[0], tag) != tag)
    query_syntax(x, std::string("expected (") + tag + " ...)");
  if (exact != std::numeric_limits<size_t>::max() && xs.size() != exact)
    query_syntax(x, std::string(tag) + ": wrong field count");
  return xs;
}

u64 query_natural(const SExp& x, u64 maximum, const char* where)
{
  const std::string& value = query_atom(x, where);
  if (value.empty()
      || !std::all_of(value.begin(), value.end(), [](unsigned char c) {
           return std::isdigit(c);
         }))
    query_syntax(x, std::string(where) + ": expected natural number");
  u64 out = 0;
  const auto parsed = std::from_chars(
    value.data(), value.data() + value.size(), out);
  if (parsed.ec != std::errc{}
      || parsed.ptr != value.data() + value.size() || out > maximum)
    query_syntax(x, std::string(where) + ": number out of range");
  return out;
}

u16 query_small(const SExp& x, const char* where)
{
  return static_cast<u16>(query_natural(
    x, std::numeric_limits<u16>::max(), where));
}

u32 query_medium(const SExp& x, const char* where)
{
  return static_cast<u32>(query_natural(
    x, std::numeric_limits<u32>::max(), where));
}

std::vector<u16> query_order(const SExp& x, const char* where)
{
  std::vector<u16> out;
  for (const SExp& column : query_list(x, where))
    out.push_back(query_small(column, where));
  return out;
}

u16 query_ref(const SExp& x, const char* where)
{
  const auto& xs = query_tagged(x, "r", 2);
  return query_small(xs[1], where);
}

u16 query_relation_ref(const SExp& x, const char* where)
{
  const auto& xs = query_tagged(x, "rel", 2);
  return query_small(xs[1], where);
}

std::string query_form_name(const SExp& x)
{
  if (x.kind != SExp::K::list || x.children.empty()
      || x.children[0].kind != SExp::K::atom)
    return "<malformed>";
  return x.children[0].text;
}

CatalogBinding decode_query_binding(const SExp& x, u16 expected_slot)
{
  const auto& entry = query_tagged(x, "rel", 4);
  const u16 slot = query_small(entry[1], "relation slot");
  if (slot != expected_slot)
    query_syntax(entry[1], "relation slots must be dense");

  const auto& binding = query_tagged(entry[2], "binding", 4);
  const auto& declaration = query_list(entry[3], "relation declaration");
  if (declaration.size() < 2)
    query_syntax(entry[3], "relation declaration is too short");
  if (query_atom(declaration[0], "relation kind") != "relation")
    query_syntax(declaration[0], "Q1 v1 only admits ordinary relations");

  CatalogBinding out;
  out.name = query_string(binding[1], "relation name");
  out.version_key = query_string(binding[2], "relation VersionKey");
  out.tuple_count = query_natural(
    binding[3], std::numeric_limits<u64>::max(), "relation tuple count");
  out.shape.arity = query_small(declaration[1], "relation arity");
  out.shape.kind = RelationK::plain;
  for (size_t i = 2; i < declaration.size(); ++i)
    out.shape.full_orders.push_back(
      query_order(declaration[i], "relation ordering"));
  return out;
}

PrimK decode_query_primitive_kind(const SExp& x)
{
  const std::string& kind = query_atom(x, "primitive kind");
  if (kind == "total") return PrimK::total;
  if (kind == "partial") return PrimK::partial;
  if (kind == "guard") return PrimK::guard;
  query_syntax(x, "unknown primitive kind");
}

BodyPlan decode_query_body_op(const SExp& op)
{
  const std::string name = query_form_name(op);
  const auto& xs = query_list(op, "query operation");
  if (name == "probe")
  {
    if (xs.size() < 4) query_syntax(op, "probe is too short");
    ProbePlan out;
    out.relation = query_relation_ref(xs[1], "probe relation");
    out.order = query_order(xs[2], "probe ordering");
    out.bound = query_small(xs[3], "probe bound prefix");
    for (size_t i = 4; i < xs.size(); ++i)
      out.regs.push_back(query_ref(xs[i], "probe register"));
    return out;
  }
  if (name == "filter")
  {
    if (xs.size() < 5) query_syntax(op, "filter is too short");
    FilterPlan out;
    const std::string& kind = query_atom(xs[1], "filter kind");
    if (kind == "exists") out.kind = FilterK::exists;
    else if (kind == "absent") out.kind = FilterK::absent;
    else query_syntax(xs[1], "unknown filter kind");
    out.relation = query_relation_ref(xs[2], "filter relation");
    out.order = query_order(xs[3], "filter ordering");
    out.bound = query_small(xs[4], "filter bound prefix");
    for (size_t i = 5; i < xs.size(); ++i)
      out.regs.push_back(query_ref(xs[i], "filter register"));
    return out;
  }
  if (name == "eq" || name == "neq")
  {
    const auto& comparison = query_tagged(op, name.c_str(), 3);
    const u16 left = query_ref(comparison[1], "comparison left register");
    const u16 right = query_ref(comparison[2], "comparison right register");
    if (name == "eq") return EqPlan{left, right};
    return NeqPlan{left, right};
  }
  if (name == "primitive")
  {
    const auto& primitive = query_tagged(op, "primitive", 5);
    const auto& output = query_tagged(primitive[3], "output", 2);
    const auto& args = query_tagged(primitive[4], "args");
    PrimPlan out;
    out.kind = decode_query_primitive_kind(primitive[1]);
    out.name = query_string(primitive[2], "primitive name");
    out.output = query_ref(output[1], "primitive output register");
    for (size_t i = 1; i < args.size(); ++i)
      out.args.push_back(query_ref(args[i], "primitive argument register"));
    return out;
  }
  query_syntax(op, "unsupported operation " + name);
}

StraightPlan decode_query_straight_op(const SExp& op)
{
  BodyPlan body = decode_query_body_op(op);
  if (const auto* filter = std::get_if<FilterPlan>(&body)) return *filter;
  if (const auto* neq = std::get_if<NeqPlan>(&body)) return *neq;
  if (const auto* eq = std::get_if<EqPlan>(&body)) return *eq;
  if (const auto* primitive = std::get_if<PrimPlan>(&body)) return *primitive;
  query_syntax(op, "probe is not a straight-line pre operation");
}

template <u16 A>
class ScanFullDriver final : public DriverCursor
{
  using Tree = BTreeIndex<A>;
  using Iter = typename Tree::iterator;

  Tree* tree;
  Iter it, end;

public:
  ScanFullDriver(Index** index, u16 bucket)
  {
    require(index != nullptr && bucket < bucket_count, ErrorK::binding,
            "query bind: invalid scan-full index");
    tree = dynamic_cast<Tree*>(index[bucket]);
    require(tree != nullptr, ErrorK::binding,
            "query bind: scan-full index has the wrong concrete arity");
    it = tree->begin();
    end = tree->end();
  }

  std::unique_ptr<DriverCursor> clone() const override
  {
    return std::make_unique<ScanFullDriver>(*this);
  }

  bool next(std::vector<u64>& row) override
  {
    if (it == end) return false;
    const auto& tuple = *it++;
    row.assign(tuple.begin(), tuple.end());
    return true;
  }
};

template <u16 A>
std::unique_ptr<DriverCursor> scan_driver_ladder(
  u16 arity, Index** index, u16 bucket)
{
  if constexpr (A == 0)
  {
    (void)arity; (void)index; (void)bucket;
    return nullptr;
  }
  else
  {
    if (arity == A)
      return std::make_unique<ScanFullDriver<A>>(index, bucket);
    return scan_driver_ladder<A - 1>(arity, index, bucket);
  }
}

bool resolve_literal(Database& db, const Literal& literal, u64& word)
{
  switch (literal.kind)
  {
    case LiteralK::string:
      require(literal.text.size() <= SEQ_BLEAF_MAX, ErrorK::literal,
              "query literal: strings longer than SEQ_BLEAF_MAX are not admitted");
      return db.probeString(literal.text, word);

    case LiteralK::real:
    {
      size_t used = 0;
      double value = 0;
      try { value = std::stod(literal.text, &used); }
      catch (...) {
        throw Error(ErrorK::literal, "query literal: malformed real");
      }
      require(used == literal.text.size() && !std::isnan(value),
              ErrorK::literal, "query literal: malformed real");
      word = float_encode(value);
      return true;
    }

    case LiteralK::integer:
    {
      mpz_t value;
      if (mpz_init_set_str(value, literal.text.c_str(), 10) != 0)
      {
        mpz_clear(value);
        throw Error(ErrorK::literal, "query literal: malformed integer");
      }
      if (mpz_cmp_si(value, (long)INT32_MIN) >= 0
          && mpz_cmp_si(value, (long)INT32_MAX) <= 0)
      {
        word = s32_encode((s32)mpz_get_si(value));
        mpz_clear(value);
        return true;
      }
      const bool found = db.probeMpz(value, word);
      mpz_clear(value);
      return found;
    }
  }
  throw Error(ErrorK::literal, "query literal: unknown kind");
}

const char* mode_name(Mode mode)
{
  switch (mode)
  {
    case Mode::rows: return "rows";
    case Mode::count: return "count";
    case Mode::exists: return "exists";
  }
  return "unknown";
}

// Query computes bind through checked adapters rather than directly through
// the rule primitive registry.  The ordinary rule path records type failures
// in Database::PendingError so a later effect can materialize them. A query
// has no effect relation, and its stronger hygiene contract forbids even that
// scratch mutation, so an ill-typed input is simply a non-matching row.
template <u64 (*Fn)(Database*, u64, u64)>
u64 query_numeric_comparison(Database* db, const u64* args, bool* ok)
{
  if (!is_num(args[0]) || !is_num(args[1]))
  {
    *ok = false;
    return 0;
  }
  return Fn(db, args[0], args[1]);
}

u64 query_tofloat(Database* db, const u64* args, bool* ok)
{
  if (!is_num(args[0])) { *ok = false; return 0; }
  return _prim_tofloat(db, args[0]);
}

u64 query_size(Database* db, const u64* args, bool* ok)
{
  if (!is_str(args[0]) && !is_seq(args[0])) { *ok = false; return 0; }
  return _prim_size(db, args[0]);
}

u64 query_sidx(Database* db, const u64* args, bool* ok)
{
  if (!is_str(args[0]) || !is_str(args[1]))
  { *ok = false; return 0; }
  return _prim_sidx(db, args[0], args[1], ok);
}

u64 query_shas(Database* db, const u64* args, bool* ok)
{
  if (!is_str(args[0]) || !is_str(args[1]))
  { *ok = false; return 0; }
  return _prim_shas(db, args[0], args[1]);
}

u64 query_aslst(Database* db, const u64* args, bool* ok)
{
  return _prim_aslst(db, args[0], ok);
}

u64 query_llen(Database* db, const u64* args, bool* ok)
{
  if (!is_seq(args[0])) { *ok = false; return 0; }
  return _prim_llen(db, args[0]);
}

u64 query_lref(Database* db, const u64* args, bool* ok)
{
  if (!is_seq(args[0]) || !is_int(args[1]))
  { *ok = false; return 0; }
  return _prim_lref(db, args[0], args[1], ok);
}

u64 query_lidx(Database* db, const u64* args, bool* ok)
{
  if (!is_seq(args[0])) { *ok = false; return 0; }
  return _prim_lidx(db, args[0], args[1], ok);
}

u64 query_lmem(Database* db, const u64* args, bool* ok)
{
  if (!is_seq(args[0])) { *ok = false; return 0; }
  return _prim_lmem(db, args[0], args[1]);
}

struct QueryPrimitiveEntry
{
  std::string_view name;
  PrimK kind;
  BoundPrim binding;
};

const std::array<QueryPrimitiveEntry, 13>& query_primitive_registry()
{
  static const std::array<QueryPrimitiveEntry, 13> entries{{
    {"lt", PrimK::guard,
      {query_numeric_comparison<&::_prim_lt>, 2, false, true}},
    {"le", PrimK::guard,
      {query_numeric_comparison<&::_prim_le>, 2, false, true}},
    {"gt", PrimK::guard,
      {query_numeric_comparison<&::_prim_gt>, 2, false, true}},
    {"ge", PrimK::guard,
      {query_numeric_comparison<&::_prim_ge>, 2, false, true}},
    {"tofloat", PrimK::total, {query_tofloat, 1, false, false}},
    {"size", PrimK::total, {query_size, 1, false, false}},
    {"sidx", PrimK::partial, {query_sidx, 2, true, false}},
    {"shas", PrimK::total, {query_shas, 2, false, false}},
    {"aslst", PrimK::partial, {query_aslst, 1, true, false}},
    {"llen", PrimK::total, {query_llen, 1, false, false}},
    {"lref", PrimK::partial, {query_lref, 2, true, false}},
    {"lidx", PrimK::partial, {query_lidx, 2, true, false}},
    {"lmem", PrimK::total, {query_lmem, 2, false, false}},
  }};
  return entries;
}

const QueryPrimitiveEntry* query_primitive(std::string_view name)
{
  for (const QueryPrimitiveEntry& entry : query_primitive_registry())
    if (entry.name == name) return &entry;
  return nullptr;
}

BoundPrim bind_query_primitive(std::string_view name)
{
  const QueryPrimitiveEntry* entry = query_primitive(name);
  require(entry != nullptr, ErrorK::unsafe_compute,
          "query bind: unsafe primitive escaped seal");
  return entry->binding;
}

[[noreturn]] void query_primitive_error(Database*, const char*)
{
  throw Error(ErrorK::unsafe_compute,
              "query execution: admitted primitive returned a storage error");
}

} // namespace

bool admits_primitive(const PrimPlan& primitive)
{
  const QueryPrimitiveEntry* entry = query_primitive(primitive.name);
  return entry != nullptr && entry->kind == primitive.kind
      && entry->binding.arity == primitive.args.size();
}

const char* error_class(ErrorK kind)
{
  switch (kind)
  {
    case ErrorK::parse: return "query-parse";
    case ErrorK::plan: return "query-plan";
    case ErrorK::unsafe_compute: return "query-unsafe-compute";
    case ErrorK::literal: return "query-literal";
    case ErrorK::binding: return "query-binding";
    case ErrorK::admission: return "query-admission";
    case ErrorK::pagination: return "query-pagination";
  }
  return "query-plan";
}

DecodedPlan parse_plan(std::string_view input)
{
  SExp root;
  try { root = sexp::read_one(input, query_plan_reader_limits); }
  catch (const sexp::ReaderError& error)
  {
    throw Error(ErrorK::parse,
                "query plan: byte " + std::to_string(error.offset())
                  + ": " + error.what());
  }

  const auto& fields = query_tagged(root, "query-plan", 12);
  const auto& abi = query_tagged(fields[1], "abi", 2);
  const auto& at = query_tagged(fields[2], "at", 3);
  const auto& boundary = query_tagged(at[1], "boundary", 2);
  const auto& generation = query_tagged(at[2], "generation", 2);
  const auto& relations = query_tagged(fields[3], "relations");
  const auto& registers = query_tagged(fields[4], "registers", 2);
  const auto& preloads = query_tagged(fields[5], "preloads");
  const auto& literals = query_tagged(fields[6], "literals");
  const auto& pre = query_tagged(fields[7], "pre");
  const auto& driver_field = query_tagged(fields[8], "driver", 2);
  const auto& body = query_tagged(fields[9], "body");
  const auto& project = query_tagged(fields[10], "project");
  const auto& mode = query_tagged(fields[11], "mode", 2);

  DecodedPlan out;
  out.abi = query_medium(abi[1], "query ABI");
  out.boundary_key = query_string(boundary[1], "BoundaryKey");
  out.generation = query_natural(
    generation[1], std::numeric_limits<u64>::max(), "boundary generation");
  out.plan.nregs = query_small(registers[1], "register count");

  for (size_t i = 1; i < relations.size(); ++i)
  {
    if (i - 1 > std::numeric_limits<u16>::max())
      query_syntax(relations[i], "too many relation slots");
    out.bindings.push_back(decode_query_binding(
      relations[i], static_cast<u16>(i - 1)));
  }

  for (size_t i = 1; i < preloads.size(); ++i)
  {
    const auto& preload = query_tagged(preloads[i], "set", 3);
    out.plan.preloads.push_back({
      query_ref(preload[1], "preload register"),
      query_natural(preload[2], std::numeric_limits<u64>::max(),
                    "preload value")});
  }

  for (size_t i = 1; i < literals.size(); ++i)
  {
    const auto& literal = query_tagged(literals[i], "literal", 4);
    Literal value;
    value.reg = query_ref(literal[1], "literal register");
    const std::string& kind = query_atom(literal[2], "literal kind");
    if (kind == "integer") value.kind = LiteralK::integer;
    else if (kind == "real") value.kind = LiteralK::real;
    else if (kind == "string") value.kind = LiteralK::string;
    else query_syntax(literal[2], "unknown literal kind");
    value.text = query_string(literal[3], "literal text");
    out.plan.literals.push_back(std::move(value));
  }

  for (size_t i = 1; i < pre.size(); ++i)
    out.plan.preops.push_back(decode_query_straight_op(pre[i]));

  const auto& driver = query_tagged(driver_field[1], "scan-full");
  if (driver.size() < 3)
    query_syntax(driver_field[1], "scan-full is too short");
  out.plan.driver.relation = query_relation_ref(
    driver[1], "scan-full relation");
  out.plan.driver.order = query_order(driver[2], "scan-full ordering");
  for (size_t i = 3; i < driver.size(); ++i)
    out.plan.driver.regs.push_back(
      query_ref(driver[i], "scan-full register"));

  for (size_t i = 1; i < body.size(); ++i)
    out.plan.body.push_back(decode_query_body_op(body[i]));
  for (size_t i = 1; i < project.size(); ++i)
    out.plan.project.push_back(query_ref(project[i], "project register"));

  const std::string& result_mode = query_atom(mode[1], "result mode");
  if (result_mode == "rows") out.plan.mode = Mode::rows;
  else if (result_mode == "count") out.plan.mode = Mode::count;
  else if (result_mode == "exists") out.plan.mode = Mode::exists;
  else query_syntax(mode[1], "unknown result mode");
  return out;
}

SealedRequest seal(const DecodedPlan& decoded)
{
  require(decoded.abi == 1, ErrorK::plan,
          "query seal: unsupported payload ABI");
  require(!decoded.boundary_key.empty(), ErrorK::plan,
          "query seal: BoundaryKey is empty");
  require(decoded.bindings.size() < std::numeric_limits<u16>::max(),
          ErrorK::plan, "query seal: too many catalog bindings");

  std::unordered_set<std::string> names;
  std::vector<RelationShape> shapes;
  shapes.reserve(decoded.bindings.size());
  for (const CatalogBinding& binding : decoded.bindings)
  {
    require(!binding.name.empty(), ErrorK::plan,
            "query seal: relation name is empty");
    require(!binding.version_key.empty(), ErrorK::plan,
            "query seal: relation VersionKey is empty");
    require(names.insert(binding.name).second, ErrorK::plan,
            "query seal: duplicate relation name");
    require(binding.shape.kind == RelationK::plain, ErrorK::plan,
            "query seal: Q1 v1 only admits ordinary relations");
    shapes.push_back(binding.shape);
  }

  SealedRequest out;
  out.boundary_key = decoded.boundary_key;
  out.generation = decoded.generation;
  out.bindings = decoded.bindings;
  out.plan = seal(decoded.plan, shapes);
  return out;
}

SealedPlan seal(const Plan& plan, const std::vector<RelationShape>& relations)
{
  require(plan.mode == Mode::rows || plan.mode == Mode::count
            || plan.mode == Mode::exists,
          ErrorK::plan, "query seal: unknown result mode");
  require(relations.size() < std::numeric_limits<u16>::max(),
          ErrorK::plan, "query seal: too many relation slots");
  require(plan.driver.relation < relations.size(), ErrorK::plan,
          "query seal: scan-full relation slot out of range");
  const RelationShape* driver_ptr = nullptr;
  try
  {
    driver_ptr = &relation_shape(
      relations, plan.driver.relation, "query scan-full");
    if (plan.driver.order.empty())
    {
      require(!driver_ptr->full_orders.empty(), ErrorK::plan,
              "query seal: scan-plus-filter has no existing full index");
      // Treat the catalog as untrusted input at this boundary. Every order
      // eligible for fallback must be a full permutation, not merely a key
      // that binding happens to find on Relation.
      for (const std::vector<u16>& order : driver_ptr->full_orders)
        validate_order(*driver_ptr, order, "query scan-full fallback");
    }
    else
      validate_order(*driver_ptr, plan.driver.order, "query scan-full");
  }
  catch (const SealError& error)
  {
    throw Error(ErrorK::plan,
                "query seal [" + std::string(seal_error_class(error.kind()))
                  + "]: " + error.what());
  }
  const RelationShape& driver = *driver_ptr;
  require(driver.arity > 0, ErrorK::plan,
          "query seal: scan-full relation has zero arity");
  require(plan.driver.regs.size() == driver.arity, ErrorK::plan,
          "query seal: scan-full register width mismatch");
  require(plan.mode != Mode::rows || !plan.project.empty(), ErrorK::plan,
          "query seal: row mode has an empty projection");
  require(plan.project.size() <= max_daemon_arity, ErrorK::plan,
          "query seal: projection is wider than the daemon ABI");

  for (const StraightPlan& op : plan.preops)
    if (const auto* primitive = std::get_if<PrimPlan>(&op))
      require(admits_primitive(*primitive), ErrorK::unsafe_compute,
              "query seal: primitive is outside the read-only whitelist");
  for (const BodyPlan& op : plan.body)
  {
    if (const auto* primitive = std::get_if<PrimPlan>(&op))
      require(admits_primitive(*primitive), ErrorK::unsafe_compute,
              "query seal: primitive is outside the read-only whitelist");
    else if (const auto* probe = std::get_if<ProbePlan>(&op))
      require(probe->view == ProbePlan::View::full
                && probe->delta_order.empty(),
              ErrorK::plan,
              "query seal: delta/old/new relation views are not snapshot queries");
    else if (const auto* join3 = std::get_if<Join3Plan>(&op))
      require(join3->left.view == ProbePlan::View::full
                && join3->right.view == ProbePlan::View::full
                && join3->left.delta_order.empty()
                && join3->right.delta_order.empty(),
              ErrorK::plan,
              "query seal: join3 delta views are not snapshot queries");
  }
  for (const Literal& literal : plan.literals)
    if (literal.kind == LiteralK::string)
      require(literal.text.size() <= SEQ_BLEAF_MAX, ErrorK::literal,
              "query seal: long string literals are not admitted by Q1 v1");

  std::vector<u16> emitted = plan.project;
  if (emitted.empty()) emitted.push_back(plan.driver.regs.front());

  RulePlan lowered;
  lowered.rule_id = 0;
  lowered.variant_ordinal = 0;
  lowered.variant = "query#0";
  lowered.nregs = plan.nregs;
  lowered.preloads = plan.preloads;
  for (const Literal& literal : plan.literals)
    lowered.preloads.push_back({literal.reg, 0});
  lowered.preops = plan.preops;
  // The core sealer's delta scan performs exactly the dataflow proof needed
  // by scan-full.  Binding replaces it with the thread-1 master-index driver.
  lowered.driver = {DriverK::scan_delta, plan.driver.relation, {}, 0,
                    plan.driver.regs};
  lowered.body = plan.body;

  std::vector<RelationShape> shapes = relations;
  RelationShape yield_shape;
  yield_shape.arity = static_cast<u16>(emitted.size());
  yield_shape.kind = RelationK::plain;
  std::vector<u16> yield_order(emitted.size());
  for (u16 i = 0; i < yield_order.size(); ++i) yield_order[i] = i;
  yield_shape.full_orders.push_back(yield_order);
  const u16 yield_slot = static_cast<u16>(shapes.size());
  shapes.push_back(yield_shape);
  lowered.heads.push_back({yield_slot, yield_order, emitted});

  SealedPlan out;
  try { out.core = seal_rule(lowered, shapes); }
  catch (const SealError& error)
  {
    throw Error(ErrorK::plan,
                "query seal [" + std::string(seal_error_class(error.kind()))
                  + "]: " + error.what());
  }
  out.driver = plan.driver;
  out.literals = plan.literals;
  out.mode = plan.mode;
  out.storage_relations = static_cast<u16>(relations.size());
  return out;
}

std::unique_ptr<DriverCursor> make_scan_full_driver(
  u16 arity, Index** index, u16 bucket)
{
  require(arity > 0 && arity <= max_daemon_arity && index != nullptr
            && bucket < bucket_count,
          ErrorK::binding, "query bind: scan-full factory capability miss");
  auto result = scan_driver_ladder<max_daemon_arity>(arity, index, bucket);
  require(result != nullptr, ErrorK::binding,
          "query bind: scan-full factory ladder miss");
  return result;
}

BoundPlan::BoundPlan(SealedPlan plan, std::vector<Relation*> binding,
                     Database& db)
  : sealed(std::move(plan)), frame(std::move(binding)), database(&db)
{
  require(frame.size() == sealed.storage_relations, ErrorK::binding,
          "query bind: relation frame width mismatch");

  const auto plain = [&](u16 slot) -> Relation* {
    require(slot < frame.size() && frame[slot] != nullptr, ErrorK::binding,
            "query bind: referenced relation is absent");
    Relation* rel = frame[slot];
    const RelationShape& shape = sealed.core.relations[slot];
    require(shape.kind == RelationK::plain && rel->getStructId() == 0
              && !rel->isLattice(),
            ErrorK::binding, "query bind: ordinary relation kind mismatch");
    require(rel->getArity() == shape.arity, ErrorK::binding,
            "query bind: relation arity mismatch");
    return rel;
  };
  const auto lattice = [&](u16 slot) -> Relation* {
    require(slot < frame.size() && frame[slot] != nullptr, ErrorK::binding,
            "query bind: referenced lattice is absent");
    Relation* rel = frame[slot];
    const RelationShape& shape = sealed.core.relations[slot];
    require(shape.kind == RelationK::lattice && rel->getStructId() == 0
              && rel->isLattice(),
            ErrorK::binding, "query bind: lattice kind mismatch");
    require(rel->getArity() == shape.arity, ErrorK::binding,
            "query bind: lattice arity mismatch");
    return rel;
  };
  const auto full_index = [&](u16 slot, const std::vector<u16>& order,
                              bool is_lattice) -> Index** {
    Relation* rel = is_lattice ? lattice(slot) : plain(slot);
    require(rel->hasIndex(order, false), ErrorK::binding,
            "query bind: selected existing index is absent");
    return rel->getIndex(order, false);
  };

  Relation* driver_relation = plain(sealed.driver.relation);
  if (!sealed.driver.order.empty())
  {
    driver_order = sealed.driver.order;
    (void)full_index(sealed.driver.relation, driver_order, false);
  }
  else
  {
    std::vector<std::vector<u16>> candidates =
      sealed.core.relations[sealed.driver.relation].full_orders;
    std::sort(candidates.begin(), candidates.end());
    candidates.erase(std::unique(candidates.begin(), candidates.end()),
                     candidates.end());
    const auto found = std::find_if(
      candidates.begin(), candidates.end(), [&](const auto& order) {
        return driver_relation->hasIndex(order, false);
      });
    require(found != candidates.end(), ErrorK::binding,
            "query bind: scan-plus-filter found no existing full index");
    driver_order = *found;
    degraded = true;
  }

  Program resolved = sealed.core.program;
  resolved.driver_regs.clear();
  resolved.driver_regs.reserve(driver_order.size());
  for (u16 nominal_column : driver_order)
  {
    require(nominal_column < sealed.driver.regs.size(), ErrorK::binding,
            "query bind: selected driver order is not a permutation");
    resolved.driver_regs.push_back(sealed.driver.regs[nominal_column]);
  }
  for (const Literal& literal : sealed.literals)
  {
    u64 value = 0;
    const bool found = resolve_literal(db, literal, value);
    auto preload = std::find_if(
      resolved.preloads.begin(), resolved.preloads.end(),
      [&](const auto& item) { return item.first == literal.reg; });
    require(preload != resolved.preloads.end(), ErrorK::binding,
            "query bind: literal preload register is absent");
    if (found) preload->second = value;
    else satisfiable = false;
  }

  for (const StraightPlan& op : sealed.core.preops)
    if (const auto* filter = std::get_if<FilterPlan>(&op))
    {
      Relation* rel = filter->lattice
        ? lattice(filter->relation) : plain(filter->relation);
      Index** index = full_index(
        filter->relation, filter->order, filter->lattice);
      if (filter->lattice)
        prefilter_prototypes.push_back(std::shared_ptr<const PrefixCursor>(
          make_map_filter_cursor(rel->getArity(), index, filter->regs,
                                 filter->bound, filter->kind).release()));
      else
        prefilter_prototypes.push_back(std::shared_ptr<const PrefixCursor>(
          make_set_filter_cursor(rel->getArity(), index, filter->regs,
                                 filter->bound, filter->kind).release()));
    }

  for (const CursorPlan& cursor : sealed.core.cursors)
  {
    if (const auto* probe = std::get_if<ProbePlan>(&cursor))
    {
      if (!probe->lattice && probe->view == ProbePlan::View::full
          && probe->bound == 0)
        degraded = true;
      Relation* rel = probe->lattice
        ? lattice(probe->relation) : plain(probe->relation);
      Index** index = full_index(probe->relation, probe->order, probe->lattice);
      std::unique_ptr<PrefixCursor> prototype = probe->lattice
        ? make_map_probe_cursor(rel->getArity(), index,
                                probe->regs, probe->bound)
        : make_set_probe_cursor(rel->getArity(), index,
                                probe->regs, probe->bound);
      cursor_prototypes.push_back(
        std::shared_ptr<const PrefixCursor>(prototype.release()));
    }
    else if (const auto* filter = std::get_if<FilterPlan>(&cursor))
    {
      Relation* rel = filter->lattice
        ? lattice(filter->relation) : plain(filter->relation);
      Index** index = full_index(
        filter->relation, filter->order, filter->lattice);
      std::unique_ptr<PrefixCursor> prototype = filter->lattice
        ? make_map_filter_cursor(rel->getArity(), index, filter->regs,
                                 filter->bound, filter->kind)
        : make_set_filter_cursor(rel->getArity(), index, filter->regs,
                                 filter->bound, filter->kind);
      cursor_prototypes.push_back(
        std::shared_ptr<const PrefixCursor>(prototype.release()));
    }
    else
    {
      const Join3Plan& join3 = std::get<Join3Plan>(cursor);
      Relation* left = plain(join3.left.relation);
      Relation* right = plain(join3.right.relation);
      Index** left_index = full_index(
        join3.left.relation, join3.left.order, false);
      Index** right_index = full_index(
        join3.right.relation, join3.right.order, false);
      auto prototype = make_join3_cursor(
        left->getArity(), left_index, left_index,
        join3.left.regs, ProbePlan::View::full,
        right->getArity(), right_index, right_index,
        join3.right.regs, ProbePlan::View::full, join3.cycle);
      cursor_prototypes.push_back(
        std::shared_ptr<const PrefixCursor>(prototype.release()));
    }
  }

  primitives.reserve(sealed.core.primitive_names.size());
  for (const std::string& name : sealed.core.primitive_names)
    primitives.push_back(bind_query_primitive(name));
  for (const StraightPlan& op : sealed.core.preops)
    if (const auto* primitive = std::get_if<PrimPlan>(&op))
      pre_primitives.push_back(bind_query_primitive(primitive->name));

  initial.assign(resolved.nregs, 0);
  for (const auto& [reg, value] : resolved.preloads) initial[reg] = value;
  size_t prefilter = 0;
  size_t pre_primitive = 0;
  for (const StraightPlan& op : sealed.core.preops)
  {
    if (std::holds_alternative<FilterPlan>(op))
    {
      auto cursor = prefilter_prototypes[prefilter++]->clone();
      cursor->open(initial.data());
      WorkBudget budget{std::numeric_limits<u64>::max()};
      if (cursor->next(initial.data(), budget) != CursorResult::match)
        satisfiable = false;
    }
    else if (const auto* neq = std::get_if<NeqPlan>(&op))
      satisfiable = satisfiable && initial[neq->left] != initial[neq->right];
    else if (const auto* eq = std::get_if<EqPlan>(&op))
      satisfiable = satisfiable && initial[eq->left] == initial[eq->right];
    else if (const auto* copy = std::get_if<CopyPlan>(&op))
      initial[copy->output] = initial[copy->input];
    else
    {
      const PrimPlan& primitive = std::get<PrimPlan>(op);
      const BoundPrim& binding = pre_primitives[pre_primitive++];
      std::array<u64, max_daemon_arity> args{};
      for (size_t i = 0; i < primitive.args.size(); ++i)
        args[i] = initial[primitive.args[i]];
      bool ok = true;
      const u64 value = binding.invoke(database, args.data(), &ok);
      if (value == slog_error) query_primitive_error(database, "<query>");
      if (!ok || (primitive.kind == PrimK::guard && value == 0))
        satisfiable = false;
      else if (primitive.kind != PrimK::guard)
        initial[primitive.output] = value;
    }
  }

  program = std::make_shared<const Program>(std::move(resolved));
}

std::vector<std::unique_ptr<PrefixCursor>> BoundPlan::make_cursors() const
{
  std::vector<std::unique_ptr<PrefixCursor>> cursors;
  cursors.reserve(cursor_prototypes.size());
  for (const auto& prototype : cursor_prototypes)
    cursors.push_back(prototype->clone());
  return cursors;
}

std::unique_ptr<Machine> BoundPlan::make_machine(
  u16 bucket_number, BoundSink* sink) const
{
  std::unique_ptr<DriverCursor> driver;
  if (!satisfiable)
    driver = std::make_unique<VectorDriverCursor>(
      std::make_shared<const std::vector<std::vector<u64>>>());
  else
  {
    Relation* rel = frame[sealed.driver.relation];
    driver = make_scan_full_driver(
      rel->getArity(), rel->getIndex(driver_order, false), bucket_number);
  }
  return std::make_unique<Machine>(
    program, std::move(driver), make_cursors(),
    std::vector<BoundSink*>{sink}, nullptr, false, database,
    primitives, std::vector<BoundTycheck>{}, &query_primitive_error, initial);
}

std::string BoundPlan::explain() const
{
  std::ostringstream out;
  out << "(query-plan (mode " << mode_name(sealed.mode)
      << ") (driver scan-full (rel " << sealed.driver.relation
      << ") (order";
  for (u16 column : driver_order) out << ' ' << column;
  out << ") (index existing)) (body-cursors "
      << sealed.core.cursors.size()
      << ") (safe-computes " << primitives.size() + pre_primitives.size()
      << ") (sink yield) (degraded "
      << (degraded ? "scan-plus-filter" : "no") << "))";
  return out.str();
}

std::shared_ptr<const BoundPlan> bind(
  const SealedPlan& plan, Database& db, std::vector<Relation*> binding)
{
  try
  {
    return std::make_shared<const BoundPlan>(
      plan, std::move(binding), db);
  }
  catch (const SealError& error)
  {
    throw Error(ErrorK::binding,
                "query bind [" + std::string(seal_error_class(error.kind()))
                  + "]: " + error.what());
  }
}

std::shared_ptr<const BoundPlan> bind(
  const SealedRequest& request, Database& db)
{
  require(request.bindings.size() == request.plan.storage_relations,
          ErrorK::binding,
          "query bind: catalog frame width changed after seal");
  const BoundarySnapshot* boundary = db.getBoundary(request.boundary_key);
  require(boundary != nullptr, ErrorK::binding,
          "query bind: BoundaryKey is not committed in this evaluation: "
            + request.boundary_key);
  std::vector<Relation*> frame;
  frame.reserve(request.bindings.size());
  for (const CatalogBinding& binding : request.bindings)
  {
    Relation* relation =
      db.getRelationAtBoundary(binding.name, request.boundary_key);
    require(relation != nullptr, ErrorK::binding,
            "query bind: relation is absent from selected boundary: "
              + binding.name);
    require(relation->getVersionKey() == binding.version_key,
            ErrorK::binding,
            "query bind: VersionKey does not match selected boundary: "
              + binding.name);
    frame.push_back(relation);
  }
  return bind(request.plan, db, std::move(frame));
}

class Context::YieldSink final : public BoundSink
{
  Mode result_mode;
  u64 limit = 0;
  u64 total = 0;
  std::vector<std::vector<u64>> current;

public:
  explicit YieldSink(Mode mode) : result_mode(mode) {}

  void begin_page(u64 page_size)
  {
    limit = page_size;
    current.clear();
  }

  void stage(TupleView tuple) override
  {
    if (result_mode == Mode::exists)
    {
      total = 1;
      return;
    }
    ++total;
    if (result_mode == Mode::rows)
    {
      require(current.size() < limit, ErrorK::pagination,
              "query yield: page overflow");
      current.emplace_back(tuple.begin(), tuple.end());
    }
  }

  void flush() override {}

  bool full() const
  {
    return result_mode == Mode::rows && current.size() == limit;
  }

  bool found() const { return total != 0; }
  u64 matched() const { return total; }

  std::vector<std::vector<u64>> take()
  {
    return std::move(current);
  }
};

Context::Context(Database& db, std::shared_ptr<const BoundPlan> bound,
                 Admission admission)
  : database(&db), plan(std::move(bound))
{
  require(plan != nullptr && plan->database == &db, ErrorK::binding,
          "query context: bound plan belongs to another database");
  require(admission == Admission::idle || admission == Admission::boundary
            || admission == Admission::mid_read
            || admission == Admission::read_complete,
          ErrorK::admission,
          "query context: master indices are mutable in this daemon phase");
  // Finish all potentially throwing local allocation before acquiring the
  // database lease, so even allocation failure cannot strand query_active.
  sink = std::make_unique<YieldSink>(plan->mode());
  require(db.tryBeginReadOnlyQuery(), ErrorK::admission,
          "query context: another query is already active");
  owns_admission = true;
  if (!plan->satisfiable)
  {
    terminal = Status::complete;
    release_admission();
  }
}

Context::~Context()
{
  release_admission();
}

void Context::release_admission()
{
  if (owns_admission)
  {
    database->endReadOnlyQuery();
    owns_admission = false;
  }
}

bool Context::ensure_machine()
{
  if (machine) return true;
  if (bucket == bucket_count)
  {
    terminal = Status::complete;
    release_admission();
    return false;
  }
  machine = plan->make_machine(bucket, sink.get());
  return true;
}

Page Context::next(u64 page_size, u64 step_budget, u64 cursor_work_budget)
{
  try
  {
    if (terminal == Status::complete || terminal == Status::cancelled)
      return {terminal, {}, sink->matched()};
    require(plan->mode() != Mode::rows || page_size != 0,
            ErrorK::pagination, "query page: row page size must be positive");

    sink->begin_page(page_size);
    terminal = Status::paused;
    for (u64 step = 0; step < step_budget; ++step)
    {
      if (!ensure_machine())
        return {terminal, sink->take(), sink->matched()};

      const StopReason why = machine->run_fast(1, cursor_work_budget);
      if (plan->mode() == Mode::exists && sink->found())
      {
        machine.reset();
        terminal = Status::complete;
        release_admission();
        return {terminal, {}, 1};
      }
      if (sink->full())
      {
        terminal = Status::page;
        return {terminal, sink->take(), sink->matched()};
      }
      if (why == StopReason::complete)
      {
        machine.reset();
        ++bucket;
      }
    }
    return {Status::paused, sink->take(), sink->matched()};
  }
  catch (...)
  {
    machine.reset();
    terminal = Status::cancelled;
    release_admission();
    throw;
  }
}

void Context::cancel()
{
  if (terminal == Status::complete || terminal == Status::cancelled) return;
  machine.reset();
  terminal = Status::cancelled;
  release_admission();
}

u64 Context::matched() const
{
  return sink->matched();
}

} // namespace query
} // namespace slog
