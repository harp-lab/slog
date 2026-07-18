/** Slog canonical sidecar decode, seal, bind, and interpreted read task.
 *
 * This is the production meeting point between the canonical plan producer
 * and the daemon interpreter.  Parsing is bounded and happens before worker
 * tasks exist. The narrow admitted execution vocabulary is deliberate:
 * normal set relations, delta-scan/full-prefix drivers, full/old/new set-view
 * body probes, existence/absence filters, straight-line primitive/guard ops,
 * type checks, one fire, and ordinary set heads. Unsupported constructs fail
 * at seal time; workers receive bound cursor, primitive, type, and sink ports.
 */

#pragma once

#include "interp.h"
#include "operators.h"

#include <algorithm>
#include <limits>
#include <memory>
#include <map>
#include <set>
#include <stdexcept>
#include <string_view>
#include <variant>

namespace slog
{
namespace interp
{

enum class RelationK : u8 { plain, struct_, lattice };

struct RelationShape
{
  u16 arity = 0;
  std::vector<std::vector<u16>> full_orders;
  RelationK kind = RelationK::plain;
  std::vector<std::vector<u16>> delta_orders;
  // A per-rule staging temp (no requisitioned indices; nominal-order
  // emission with no dedup; scanned by the follow-up rule's delta driver).
  bool temp = false;
};

// `once` fires a single empty driver row (ground/fact rules); `seeded` is the
// count flavor's all-full fire-once shape -- also one empty row, with the
// enumeration carried entirely by K=0 body scans over FULL views.  Both are
// currently admitted for counted plans only (thread 0); the normal-flavor
// once/seeded conformance group remains a trunk chore.
enum class DriverK : u8 { scan_delta, probe_full, once, seeded };

struct DriverPlan
{
  DriverK kind = DriverK::scan_delta;
  u16 relation = 0;
  std::vector<u16> order; // empty for nominal delta scan
  u16 bound = 0;
  std::vector<u16> regs;  // nominal for scan, index order for probe
};

struct ProbePlan
{
  u16 relation = 0;
  std::vector<u16> order;
  u16 bound = 0;
  std::vector<u16> regs; // index order: bound prefix, fresh suffix
  enum class View : u8 { full, old, new_ } view = View::full;
  std::vector<u16> delta_order;
  // join-lat uses a BTreeMapIndex whose final ordered column is the payload.
  bool lattice = false;
  // Counted plans probe struct masters directly: content->id resolution
  // joins over the content-first/id-last ordering (thread 0).
  bool struct_ = false;
  // Count-flavor mkstruct lowering: at a settled fixpoint the instance is
  // already interned, so the head construction becomes this pre-fire
  // resolution probe (binding the id register) whose zero-match exhaustion
  // is a loud fatal, mirroring emit_struct_count's closure stance.
  bool resolve = false;
};

enum class FilterK : u8 { exists, absent };

struct FilterPlan
{
  FilterK kind = FilterK::exists;
  u16 relation = 0;
  std::vector<u16> order;
  u16 bound = 0;
  std::vector<u16> regs; // bound prefix only; filters assign no registers
  // absent-lat tests a lattice payload map's key prefix.
  bool lattice = false;
};

struct NeqPlan { u16 left = 0, right = 0; };
struct EqPlan { u16 left = 0, right = 0; };
struct CopyPlan { u16 output = 0, input = 0; };

enum class PrimK : u8 { total, partial, guard };

struct PrimPlan
{
  PrimK kind = PrimK::total;
  std::string name;
  u16 output = 0; // unused by guard
  std::vector<u16> args;
};

enum class TypeK : u8 { primitive, struct_ };

struct TypePlan
{
  TypeK kind = TypeK::primitive;
  std::string name;
};

struct TycheckPlan
{
  u16 value = 0;
  std::vector<TypePlan> accepts;
  u16 rule = 0, relation = 0, column = 0;
  std::vector<u16> order;
  // Resolved from the canonical relation binding named
  // `malformed_deduction` before ordinary rule sealing.
  u16 malformed_relation = std::numeric_limits<u16>::max();
};

struct Join3ArmPlan
{
  u16 relation = 0;
  std::vector<u16> order;
  u16 bound = 0;
  std::vector<u16> regs; // bound prefix followed by the shared cycle register
  ProbePlan::View view = ProbePlan::View::full;
  std::vector<u16> delta_order; // empty for full, exact order for old/new
};

struct Join3Plan
{
  u16 cycle = 0;
  Join3ArmPlan left;
  Join3ArmPlan right;
};

using CursorPlan = std::variant<ProbePlan, FilterPlan, Join3Plan>;
using StraightPlan = std::variant<FilterPlan, NeqPlan, EqPlan, CopyPlan, PrimPlan>;
using BodyPlan = std::variant<ProbePlan, FilterPlan, NeqPlan, EqPlan,
                              CopyPlan, PrimPlan, Join3Plan>;
using HeadPrefixPlan = std::variant<CopyPlan, PrimPlan, TycheckPlan>;

// Head sink families.  `set` is the ordinary indexed emit; the other three
// are decoded for counted plans (thread 0): `temp` stages nominal-order rows
// with no dedup (emit_temp), `lattice` preserves every contribution row
// (emit_lattice_count), and `struct_` is a canonical mkstruct head whose id
// column (nominal 0, listed first in regs) is bound by the lowered pre-fire
// resolution probe.
enum class HeadK : u8 { set, temp, lattice, struct_ };

struct EmitPlan
{
  u16 relation = 0;
  std::vector<u16> order;
  std::vector<u16> regs; // values in head-index order (nominal for
                         // temp/lattice/struct_ heads)
  HeadK head_kind = HeadK::set;
};

struct RulePlan
{
  u32 rule_id = 0;
  u32 variant_ordinal = 0;
  // Canonical identity is (rule_id, variant).  The trailing #ordinal is also
  // decoded into variant_ordinal for compact VM events.
  std::string variant;
  u16 nregs = 0;
  std::vector<std::pair<u16, u64>> preloads;
  DriverPlan driver;
  std::vector<BodyPlan> body;
  std::vector<EmitPlan> heads;
  // Canonical pre filters run after constant preloads and before the driver.
  std::vector<FilterPlan> prefilters;
  // Appended T2-B fields keep the T2-A direct-builder aggregates compatible.
  std::vector<HeadPrefixPlan> head_prefix;
  // Parsed canonical pre ops retain their semantic order.
  std::vector<StraightPlan> preops;
  // Count flavor: the rule's prov-keyed contribution kind (cnt_kind_nonrec /
  // cnt_kind_rec), decoded from the variant tag's "/<kind>" suffix under the
  // ABI-1 interim (counted-interp-contract.md); cnt_kind_none otherwise.
  u8 fold_kind = 0;
};

enum class SealErrorK : u8
{
  abi,
  flavor,
  capability,
  register_bounds,
  dataflow,
  relation_slot,
  relation_kind,
  relation_arity,
  constant_slot,
  ordering,
  index_requisition,
  bound_prefix,
  head_coverage,
  variant_identity,
  factory,
  binding
};

const char* seal_error_class(SealErrorK kind);

struct SealError : std::runtime_error
{
  SealErrorK error_kind;

  explicit SealError(const std::string& message)
    : std::runtime_error(message), error_kind(SealErrorK::capability) {}
  SealError(SealErrorK kind, const std::string& message)
    : std::runtime_error(message), error_kind(kind) {}

  SealErrorK kind() const { return error_kind; }
};

enum class ParseErrorK : u8 { syntax, limit, io };

const char* parse_error_class(ParseErrorK kind);

struct PlanParseError : std::runtime_error
{
  ParseErrorK error_kind;
  size_t byte_offset;

  PlanParseError(ParseErrorK kind, size_t offset, const std::string& message)
    : std::runtime_error(message), error_kind(kind), byte_offset(offset) {}

  ParseErrorK kind() const { return error_kind; }
  size_t offset() const { return byte_offset; }
};

enum class ConstantK : u8 { integer, real, string, boolean, symbol, compound };

struct ConstantPlan
{
  u32 slot = 0;
  std::string name;
  ConstantK kind = ConstantK::compound;
  std::string text;
};

struct RelationBinding
{
  u16 slot = 0;
  std::string name;
  RelationShape shape;
};

struct DecodedRule
{
  RulePlan plan;
  std::vector<std::pair<u16, u32>> constant_preloads;
  std::vector<std::string> unsupported;
};

// Immutable-by-convention output of the bounded ABI reader.  Constants remain
// storage-neutral until seal, while RulePlan stays the T2 decoded execution
// interface used by direct C++ builders.
struct DecodedKernelPlan
{
  u32 abi = 0;
  std::string flavor;
  std::vector<RelationBinding> bindings;
  std::vector<ConstantPlan> constants;
  std::vector<std::string> primitives;
  std::vector<DecodedRule> rules;
  std::map<u32, std::string> sources;
  size_t attachment_count = 0;
  // The plan's (dynamic ...) names, retained for the counted installer's
  // addDynamicRel mirroring (thread 0).
  std::vector<std::string> dynamic_names;
};

struct SealedRule
{
  Program program;
  DriverPlan driver;
  std::vector<CursorPlan> cursors;
  std::vector<EmitPlan> heads;
  std::vector<StraightPlan> preops;
  std::vector<std::string> primitive_names;
  std::vector<TycheckPlan> tychecks;
  // Each failed tycheck emits four fields into a malformed_deduction struct
  // sink. Ports follow the ordinary head ports in program order.
  std::vector<EmitPlan> effects;
  std::vector<RelationShape> relations;
  u16 max_depth = 0;
  // Compatibility view for the original T2-A seal fixtures.
  std::vector<FilterPlan> prefilters;
  // Count flavor (thread 0): sinks fold this prov-keyed kind through the
  // shared cnt_* folds; false/none for the normal flavor.
  bool counted = false;
  u8 fold_kind = 0;
};

// Resolve the canonical primitive name to its exact shared daemon function
// and ABI. Unknown names never reach a worker.
BoundPrim resolve_primitive(std::string_view name);

struct SealedKernelPlan
{
  u32 abi = 0;
  std::string flavor;
  std::vector<RelationBinding> bindings;
  std::vector<SealedRule> rules;
  std::map<u32, std::string> sources;
  std::vector<std::string> dynamic_names;
};

inline void seal_check(bool ok, SealErrorK kind,
                       const std::string& message)
{
  if (!ok) throw SealError(kind, message);
}

inline void seal_check(bool ok, const std::string& message)
{
  if (!ok) throw SealError(message);
}

inline void validate_reg(u16 reg, u16 nregs, const char* where)
{
  seal_check(reg < nregs, SealErrorK::register_bounds,
             std::string(where) + ": register out of range");
}

inline const RelationShape& relation_shape(
  const std::vector<RelationShape>& rels, u16 slot, const char* where)
{
  seal_check(slot < rels.size(), SealErrorK::relation_slot,
             std::string(where) +
             ": relation slot out of range");
  const RelationShape& shape = rels[slot];
  seal_check(shape.kind == RelationK::plain, SealErrorK::relation_kind,
             std::string(where) + ": operation requires an ordinary set relation");
  seal_check(shape.arity > 0 && shape.arity <= max_daemon_arity,
             SealErrorK::relation_arity,
             std::string(where) + ": unsupported relation arity");
  return shape;
}

inline const RelationShape& lattice_shape(
  const std::vector<RelationShape>& rels, u16 slot, const char* where)
{
  seal_check(slot < rels.size(), SealErrorK::relation_slot,
             std::string(where) + ": relation slot out of range");
  const RelationShape& shape = rels[slot];
  seal_check(shape.kind == RelationK::lattice, SealErrorK::relation_kind,
             std::string(where) + ": operation requires a lattice relation");
  seal_check(shape.arity >= 2 && shape.arity <= max_daemon_arity,
             SealErrorK::relation_arity,
             std::string(where) + ": unsupported lattice arity");
  return shape;
}

inline const RelationShape& struct_shape(
  const std::vector<RelationShape>& rels, u16 slot, const char* where)
{
  seal_check(slot < rels.size(), SealErrorK::relation_slot,
             std::string(where) + ": relation slot out of range");
  const RelationShape& shape = rels[slot];
  seal_check(shape.kind == RelationK::struct_, SealErrorK::relation_kind,
             std::string(where) + ": operation requires a struct relation");
  seal_check(shape.arity >= 2 && shape.arity <= max_daemon_arity,
             SealErrorK::relation_arity,
             std::string(where) + ": unsupported struct arity");
  return shape;
}

inline void validate_order(const RelationShape& shape,
                           const std::vector<u16>& order,
                           const char* where, bool delta = false)
{
  seal_check(order.size() == shape.arity, SealErrorK::ordering,
             std::string(where) + ": ordering width mismatch");
  std::vector<bool> seen(shape.arity, false);
  for (u16 column : order)
  {
    seal_check(column < shape.arity, SealErrorK::ordering,
               std::string(where) + ": ordering column out of range");
    seal_check(!seen[column], SealErrorK::ordering,
               std::string(where) + ": ordering is not a permutation");
    seen[column] = true;
  }
  const auto& requisitions = delta ? shape.delta_orders : shape.full_orders;
  seal_check(std::find(requisitions.begin(), requisitions.end(), order)
               != requisitions.end(), SealErrorK::index_requisition,
             std::string(where) + ": ordering was not requisitioned");
}

inline bool supports_set_probe(u16 arity, u16 bound)
{
  return arity >= 1 && arity <= max_daemon_arity
      && bound <= arity;
}

inline bool supports_set_probe_driver(u16 arity, u16 bound)
{
  // A K=0 full scan is a body cursor. Outer full scans are represented by
  // scan-delta for rules and ScanFullPlan for queries, never a probe driver.
  return bound >= 1 && supports_set_probe(arity, bound);
}

inline bool supports_view_probe(u16 arity, u16 bound)
{
  return arity >= 1 && arity <= max_daemon_arity && bound <= arity;
}

inline bool supports_set_filter(FilterK kind, u16 arity, u16 bound)
{
  return arity >= 1 && arity <= max_daemon_arity && bound <= arity
      && (kind == FilterK::absent || bound != 0);
}

inline bool supports_join3_arm(u16 arity, u16 bound)
{
  return arity >= 2 && arity <= max_daemon_arity
      && bound > 0 && bound + 1 == arity;
}

inline bool supports_map_probe(u16 arity, u16 bound)
{
  return arity >= 2 && arity <= max_daemon_arity && bound < arity;
}

inline bool supports_map_filter(FilterK kind, u16 arity, u16 bound)
{
  return kind == FilterK::absent && supports_map_probe(arity, bound);
}

inline SealedRule seal_rule(const RulePlan& plan,
                            const std::vector<RelationShape>& relations,
                            bool counted = false)
{
  seal_check(plan.nregs != 0, SealErrorK::register_bounds,
             "rule: empty register file");
  seal_check(!plan.heads.empty(), SealErrorK::head_coverage, "rule: no head");
  seal_check(plan.heads.size() <= std::numeric_limits<u16>::max(),
             SealErrorK::factory,
             "rule: too many head sinks");

  SealedRule out;
  out.program.rule_id = plan.rule_id;
  out.program.variant_ordinal = plan.variant_ordinal;
  out.program.variant = plan.variant;
  out.program.nregs = plan.nregs;
  out.program.driver_regs = plan.driver.regs;
  out.program.preloads = plan.preloads;
  out.driver = plan.driver;
  out.heads = plan.heads;
  out.relations = relations;
  out.preops = plan.preops;
  out.counted = counted;
  out.fold_kind = plan.fold_kind;
  if (out.preops.empty())
    for (const FilterPlan& filter : plan.prefilters)
      out.preops.emplace_back(filter);
  for (const StraightPlan& op : out.preops)
    if (const auto* filter = std::get_if<FilterPlan>(&op))
      out.prefilters.push_back(*filter);

  std::vector<bool> assigned(plan.nregs, false);
  for (const auto& [reg, _] : plan.preloads)
  {
    validate_reg(reg, plan.nregs, "preload");
    seal_check(!assigned[reg], SealErrorK::dataflow,
               "preload: register assigned twice");
    assigned[reg] = true;
  }

  const auto validate_filter = [&](const FilterPlan& filter,
                                   const char* where) {
    const RelationShape& rel = filter.lattice
      ? lattice_shape(relations, filter.relation, where)
      : relation_shape(relations, filter.relation, where);
    validate_order(rel, filter.order, where);
    if (filter.lattice)
      seal_check(filter.order.back() == rel.arity - 1,
                 SealErrorK::ordering,
                 std::string(where) + ": lattice payload is not last");
    seal_check(filter.regs.size() == filter.bound,
               SealErrorK::bound_prefix,
               std::string(where) + ": key register width mismatch");
    seal_check(filter.lattice
                 ? supports_map_filter(filter.kind, rel.arity, filter.bound)
                 : supports_set_filter(filter.kind, rel.arity, filter.bound),
               SealErrorK::factory,
               std::string(where) + ": no daemon cursor capability");
    for (u16 reg : filter.regs)
    {
      validate_reg(reg, plan.nregs, where);
      seal_check(assigned[reg], SealErrorK::dataflow,
                 std::string(where) + ": read of unassigned register");
    }
  };

  const auto validate_primitive = [&](const PrimPlan& prim,
                                      const char* where,
                                      bool assign_output) {
    const BoundPrim signature = resolve_primitive(prim.name);
    seal_check(signature.arity == prim.args.size(), SealErrorK::capability,
               std::string(where) + ": primitive arity mismatch");
    seal_check((prim.kind == PrimK::partial) == signature.partial,
               SealErrorK::capability,
               std::string(where) + ": primitive total/partial mismatch");
    seal_check(prim.kind != PrimK::guard || !signature.partial,
               SealErrorK::capability,
               std::string(where) + ": partial primitive cannot guard cmp");
    seal_check((prim.kind == PrimK::guard) == signature.comparison,
               SealErrorK::capability,
               std::string(where) + ": primitive/comparison role mismatch");
    for (u16 reg : prim.args)
    {
      validate_reg(reg, plan.nregs, where);
      seal_check(assigned[reg], SealErrorK::dataflow,
                 std::string(where) + ": read of unassigned register");
    }
    if (assign_output)
    {
      validate_reg(prim.output, plan.nregs, where);
      seal_check(!assigned[prim.output], SealErrorK::dataflow,
                 std::string(where) + ": output register already assigned");
      assigned[prim.output] = true;
    }
  };

  const auto validate_straight = [&](const StraightPlan& straight,
                                     const char* where) {
    if (const auto* filter = std::get_if<FilterPlan>(&straight))
      validate_filter(*filter, where);
    else if (const auto* neq = std::get_if<NeqPlan>(&straight))
    {
      validate_reg(neq->left, plan.nregs, where);
      validate_reg(neq->right, plan.nregs, where);
      seal_check(assigned[neq->left] && assigned[neq->right],
                 SealErrorK::dataflow,
                 std::string(where) + ": read of unassigned register");
    }
    else if (const auto* eq = std::get_if<EqPlan>(&straight))
    {
      validate_reg(eq->left, plan.nregs, where);
      validate_reg(eq->right, plan.nregs, where);
      seal_check(assigned[eq->left] && assigned[eq->right],
                 SealErrorK::dataflow,
                 std::string(where) + ": read of unassigned register");
    }
    else if (const auto* copy = std::get_if<CopyPlan>(&straight))
    {
      validate_reg(copy->input, plan.nregs, where);
      validate_reg(copy->output, plan.nregs, where);
      seal_check(assigned[copy->input], SealErrorK::dataflow,
                 std::string(where) + ": read of unassigned register");
      seal_check(!assigned[copy->output], SealErrorK::dataflow,
                 std::string(where) + ": output register already assigned");
      assigned[copy->output] = true;
    }
    else
    {
      const PrimPlan& prim = std::get<PrimPlan>(straight);
      validate_primitive(prim, where, prim.kind != PrimK::guard);
    }
  };

  for (const StraightPlan& straight : out.preops)
    validate_straight(straight, "pre op");

  if (plan.driver.kind == DriverK::once
      || plan.driver.kind == DriverK::seeded)
  {
    // One empty driver row; the enumeration is carried by K=0 body scans
    // over FULL views (the count flavor's fire-once shape).
    seal_check(counted, SealErrorK::capability,
               "driver: once/seeded drivers are admitted for counted "
               "plans only");
    seal_check(plan.driver.order.empty(), SealErrorK::ordering,
               "driver: once/seeded driver has an unexpected ordering");
    seal_check(plan.driver.bound == 0, SealErrorK::bound_prefix,
               "driver: once/seeded driver has an unexpected bound prefix");
    seal_check(plan.driver.regs.empty(), SealErrorK::dataflow,
               "driver: once/seeded driver assigns no registers");
  }
  else
  {
  const RelationShape& driver_rel =
    relation_shape(relations, plan.driver.relation, "driver");
  seal_check(plan.driver.regs.size() == driver_rel.arity,
             SealErrorK::relation_arity,
             "driver: register width mismatch");
  if (plan.driver.kind == DriverK::scan_delta)
  {
    seal_check(plan.driver.order.empty(), SealErrorK::ordering,
               "scan driver: unexpected ordering");
    seal_check(plan.driver.bound == 0, SealErrorK::bound_prefix,
               "scan driver: unexpected bound prefix");
    for (u16 reg : plan.driver.regs)
    {
      validate_reg(reg, plan.nregs, "scan driver");
      seal_check(!assigned[reg], SealErrorK::dataflow,
                 "scan driver: output register already assigned");
      assigned[reg] = true;
    }
  }
  else
  {
    validate_order(driver_rel, plan.driver.order, "probe driver");
    seal_check(supports_set_probe_driver(driver_rel.arity,
                                         plan.driver.bound),
               SealErrorK::factory,
               "probe driver: no daemon factory capability");
    for (u16 i = 0; i < driver_rel.arity; ++i)
    {
      const u16 reg = plan.driver.regs[i];
      validate_reg(reg, plan.nregs, "probe driver");
      if (i < plan.driver.bound)
        seal_check(assigned[reg], SealErrorK::bound_prefix,
                   "probe driver: unbound prefix register");
      else
      {
        seal_check(!assigned[reg], SealErrorK::dataflow,
                   "probe driver: suffix register already assigned");
        assigned[reg] = true;
      }
    }
  }
  }

  for (const BodyPlan& body : plan.body)
  {
    if (const auto* probe_in = std::get_if<ProbePlan>(&body))
    {
      ProbePlan probe = *probe_in;
      // Counted plans resolve struct content->id through ordinary probes of
      // the struct master (the M4S resolution-join shape at a settled
      // fixpoint); the normal flavor keeps refusing struct probes.
      seal_check(probe.relation < relations.size(), SealErrorK::relation_slot,
                 "probe: relation slot out of range");
      probe.struct_ = !probe.lattice
        && relations[probe.relation].kind == RelationK::struct_;
      seal_check(!probe.struct_ || counted, SealErrorK::relation_kind,
                 "probe: struct relation probes are admitted for counted "
                 "plans only");
      const RelationShape& rel = probe.lattice
        ? lattice_shape(relations, probe.relation, "lattice probe")
        : probe.struct_
          ? struct_shape(relations, probe.relation, "struct probe")
          : relation_shape(relations, probe.relation, "probe");
      validate_order(rel, probe.order, "probe");
      seal_check(probe.regs.size() == rel.arity, SealErrorK::relation_arity,
                 "probe: register width mismatch");
      const bool viewed = probe.view != ProbePlan::View::full;
      seal_check(!probe.struct_ || !viewed, SealErrorK::capability,
                 "struct probe: relation views are unsupported");
      seal_check(probe.lattice
                   ? supports_map_probe(rel.arity, probe.bound)
                   : (viewed ? supports_view_probe(rel.arity, probe.bound)
                             : supports_set_probe(rel.arity, probe.bound)),
                 SealErrorK::factory,
                 "probe: no daemon cursor capability");
      if (probe.lattice)
      {
        seal_check(!viewed && probe.delta_order.empty(),
                   SealErrorK::capability,
                   "lattice probe: relation views are unsupported");
        seal_check(probe.order.back() == rel.arity - 1,
                   SealErrorK::ordering,
                   "lattice probe: payload column is not last");
      }
      else if (viewed)
      {
        validate_order(rel, probe.delta_order, "probe delta", true);
        // The native old/new membership test compares physically ordered
        // tuples.  Canonical operationalization currently requisitions the
        // same order for both views; reject a mismatched pair explicitly.
        seal_check(probe.delta_order == probe.order, SealErrorK::ordering,
                   "probe: full and delta orderings differ");
      }
      for (u16 i = 0; i < rel.arity; ++i)
      {
        const u16 reg = probe.regs[i];
        validate_reg(reg, plan.nregs, "probe");
        if (i < probe.bound)
          seal_check(assigned[reg], SealErrorK::bound_prefix,
                     "probe: unbound prefix register");
        else
        {
          seal_check(!assigned[reg], SealErrorK::dataflow,
                     "probe: suffix register already assigned");
          assigned[reg] = true;
        }
      }
      const size_t cursor = out.cursors.size();
      seal_check(cursor < std::numeric_limits<u16>::max(), SealErrorK::factory,
                 "probe: too many cursor ports");
      out.cursors.push_back(std::move(probe));
      out.program.ops.push_back({OpK::probe, static_cast<u16>(cursor)});
      ++out.max_depth;
    }
    else if (const auto* filter = std::get_if<FilterPlan>(&body))
    {
      validate_filter(*filter, "filter");
      const size_t cursor = out.cursors.size();
      seal_check(cursor < std::numeric_limits<u16>::max(), SealErrorK::factory,
                 "filter: too many cursor ports");
      out.cursors.push_back(*filter);
      out.program.ops.push_back({OpK::probe, static_cast<u16>(cursor)});
      ++out.max_depth;
    }
    else if (const auto* join3 = std::get_if<Join3Plan>(&body))
    {
      validate_reg(join3->cycle, plan.nregs, "join3 cycle");
      seal_check(!assigned[join3->cycle], SealErrorK::dataflow,
                 "join3: cycle register already assigned");
      const auto validate_arm = [&](const Join3ArmPlan& arm,
                                    const char* where) {
        const RelationShape& rel = relation_shape(
          relations, arm.relation, where);
        seal_check(arm.view == ProbePlan::View::full
                     || arm.view == ProbePlan::View::old
                     || arm.view == ProbePlan::View::new_,
                   SealErrorK::capability,
                   std::string(where) + ": unknown relation view");
        validate_order(rel, arm.order, where);
        seal_check(supports_join3_arm(rel.arity, arm.bound),
                   SealErrorK::factory,
                   std::string(where) + ": not a key-simple join3 arm");
        seal_check(arm.regs.size() == rel.arity,
                   SealErrorK::relation_arity,
                   std::string(where) + ": register width mismatch");
        const bool viewed = arm.view != ProbePlan::View::full;
        if (viewed)
        {
          validate_order(rel, arm.delta_order, where, true);
          seal_check(arm.delta_order == arm.order, SealErrorK::ordering,
                     std::string(where)
                       + ": full and delta orderings differ");
        }
        else
          seal_check(arm.delta_order.empty(), SealErrorK::ordering,
                     std::string(where)
                       + ": full arm has an unexpected delta ordering");
        for (u16 i = 0; i < arm.bound; ++i)
        {
          const u16 reg = arm.regs[i];
          validate_reg(reg, plan.nregs, where);
          seal_check(assigned[reg], SealErrorK::bound_prefix,
                     std::string(where)
                       + ": unbound prefix register");
        }
        validate_reg(arm.regs.back(), plan.nregs, where);
        seal_check(arm.regs.back() == join3->cycle,
                   SealErrorK::dataflow,
                   std::string(where)
                     + ": suffix is not the shared cycle register");
      };
      validate_arm(join3->left, "join3 left");
      validate_arm(join3->right, "join3 right");
      assigned[join3->cycle] = true;
      const size_t cursor = out.cursors.size();
      seal_check(cursor < std::numeric_limits<u16>::max(),
                 SealErrorK::factory,
                 "join3: too many cursor ports");
      out.cursors.push_back(*join3);
      out.program.ops.push_back({OpK::probe, static_cast<u16>(cursor)});
      ++out.max_depth;
    }
    else if (const auto* neq = std::get_if<NeqPlan>(&body))
    {
      validate_reg(neq->left, plan.nregs, "neq");
      validate_reg(neq->right, plan.nregs, "neq");
      seal_check(assigned[neq->left] && assigned[neq->right],
                 SealErrorK::dataflow,
                 "neq: read of unassigned register");
      out.program.ops.push_back({OpK::guard_neq, 0, neq->left, neq->right});
    }
    else if (const auto* eq = std::get_if<EqPlan>(&body))
    {
      validate_reg(eq->left, plan.nregs, "eq");
      validate_reg(eq->right, plan.nregs, "eq");
      seal_check(assigned[eq->left] && assigned[eq->right],
                 SealErrorK::dataflow,
                 "eq: read of unassigned register");
      out.program.ops.push_back({OpK::guard_eq, 0, eq->left, eq->right});
    }
    else if (const auto* copy = std::get_if<CopyPlan>(&body))
    {
      validate_reg(copy->input, plan.nregs, "copy");
      validate_reg(copy->output, plan.nregs, "copy");
      seal_check(assigned[copy->input], SealErrorK::dataflow,
                 "copy: read of unassigned register");
      seal_check(!assigned[copy->output], SealErrorK::dataflow,
                 "copy: output register already assigned");
      assigned[copy->output] = true;
      out.program.ops.push_back({OpK::copy, 0, copy->output, copy->input});
    }
    else
    {
      const PrimPlan& prim = std::get<PrimPlan>(body);
      validate_primitive(prim, "primitive", prim.kind != PrimK::guard);
      seal_check(out.program.operands.size() + prim.args.size()
                   <= std::numeric_limits<u16>::max(),
                 SealErrorK::factory, "primitive: operand bank overflow");
      seal_check(out.primitive_names.size()
                   < std::numeric_limits<u16>::max(),
                 SealErrorK::factory, "primitive: too many bound call sites");
      const u16 slot = static_cast<u16>(out.primitive_names.size());
      const u16 offset = static_cast<u16>(out.program.operands.size());
      out.primitive_names.push_back(prim.name);
      out.program.operands.insert(out.program.operands.end(),
                                  prim.args.begin(), prim.args.end());
      const OpK kind = prim.kind == PrimK::total ? OpK::prim
                     : prim.kind == PrimK::partial ? OpK::prim_partial
                     : OpK::guard_cmp;
      out.program.ops.push_back({kind, slot, prim.output, offset,
                                 static_cast<u16>(prim.args.size())});
    }
  }

  // Count-flavor mkstruct heads lower to pre-fire resolution probes: at a
  // settled fixpoint the constructed instance is already interned, so the
  // content-bound probe binds the id register (nominal column 0, suffix of
  // the id-last master ordering) and a zero-match exhaustion is a loud
  // fatal in the bound cursor -- the emit_struct_count closure stance.
  // Chained constructions compose as ordinary nested cursor levels.
  for (const EmitPlan& head : plan.heads)
  {
    if (head.head_kind != HeadK::struct_) continue;
    seal_check(counted, SealErrorK::capability,
               "mkstruct: struct construction heads are admitted for "
               "counted plans only");
    const RelationShape& rel =
      struct_shape(relations, head.relation, "mkstruct");
    validate_order(rel, head.order, "mkstruct");
    seal_check(head.order.back() == 0, SealErrorK::ordering,
               "mkstruct: master ordering must end in the id column");
    seal_check(head.regs.size() == rel.arity, SealErrorK::relation_arity,
               "mkstruct: register width mismatch");
    ProbePlan resolve;
    resolve.relation = head.relation;
    resolve.order = head.order;
    resolve.bound = static_cast<u16>(rel.arity - 1);
    resolve.struct_ = true;
    resolve.resolve = true;
    for (u16 column : head.order)
      resolve.regs.push_back(head.regs[column]);
    for (u16 i = 0; i + 1 < rel.arity; ++i)
    {
      const u16 reg = resolve.regs[i];
      validate_reg(reg, plan.nregs, "mkstruct");
      seal_check(assigned[reg], SealErrorK::bound_prefix,
                 "mkstruct: unbound content register");
    }
    const u16 id_reg = resolve.regs.back();
    validate_reg(id_reg, plan.nregs, "mkstruct");
    seal_check(!assigned[id_reg], SealErrorK::dataflow,
               "mkstruct: id register already assigned");
    assigned[id_reg] = true;
    const size_t cursor = out.cursors.size();
    seal_check(cursor < std::numeric_limits<u16>::max(), SealErrorK::factory,
               "mkstruct: too many cursor ports");
    out.cursors.push_back(std::move(resolve));
    out.program.ops.push_back({OpK::probe, static_cast<u16>(cursor)});
    ++out.max_depth;
  }

  out.program.ops.push_back({OpK::fire});
  for (const HeadPrefixPlan& prefix : plan.head_prefix)
  {
    if (const auto* copy = std::get_if<CopyPlan>(&prefix))
    {
      validate_reg(copy->input, plan.nregs, "head copy");
      validate_reg(copy->output, plan.nregs, "head copy");
      seal_check(assigned[copy->input], SealErrorK::dataflow,
                 "head copy: read of unassigned register");
      seal_check(!assigned[copy->output], SealErrorK::dataflow,
                 "head copy: output register already assigned");
      assigned[copy->output] = true;
      out.program.ops.push_back({OpK::copy, 0, copy->output, copy->input});
    }
    else if (const auto* prim = std::get_if<PrimPlan>(&prefix))
    {
      validate_primitive(*prim, "head primitive", prim->kind != PrimK::guard);
      seal_check(prim->kind != PrimK::guard, SealErrorK::capability,
                 "head primitive: comparison guard is not canonical");
      seal_check(out.program.operands.size() + prim->args.size()
                   <= std::numeric_limits<u16>::max(),
                 SealErrorK::factory,
                 "head primitive: operand bank overflow");
      seal_check(out.primitive_names.size()
                   < std::numeric_limits<u16>::max(),
                 SealErrorK::factory,
                 "head primitive: too many bound call sites");
      const u16 slot = static_cast<u16>(out.primitive_names.size());
      const u16 offset = static_cast<u16>(out.program.operands.size());
      out.primitive_names.push_back(prim->name);
      out.program.operands.insert(out.program.operands.end(),
                                  prim->args.begin(), prim->args.end());
      out.program.ops.push_back({prim->kind == PrimK::total
                                   ? OpK::prim : OpK::prim_partial,
                                 slot, prim->output, offset,
                                 static_cast<u16>(prim->args.size())});
    }
    else
    {
      const TycheckPlan& check = std::get<TycheckPlan>(prefix);
      validate_reg(check.value, plan.nregs, "tycheck");
      validate_reg(check.rule, plan.nregs, "tycheck");
      validate_reg(check.relation, plan.nregs, "tycheck");
      validate_reg(check.column, plan.nregs, "tycheck");
      seal_check(assigned[check.value] && assigned[check.rule]
                   && assigned[check.relation] && assigned[check.column],
                 SealErrorK::dataflow,
                 "tycheck: read of unassigned register");
      seal_check(!check.accepts.empty(), SealErrorK::capability,
                 "tycheck: empty accept set");
      for (const TypePlan& type : check.accepts)
      {
        if (type.kind == TypeK::primitive)
          seal_check(type.name == "int" || type.name == "float"
                       || type.name == "str" || type.name == "cnode"
                       || type.name == "seq",
                     SealErrorK::capability,
                     "tycheck: unsupported primitive accept type");
        else
          seal_check(!type.name.empty(), SealErrorK::capability,
                     "tycheck: empty struct accept name");
      }
      seal_check(check.malformed_relation < relations.size(),
                 SealErrorK::relation_slot,
                 "tycheck: malformed_deduction relation is absent");
      const RelationShape& malformed = relations[check.malformed_relation];
      seal_check(malformed.kind == RelationK::struct_, SealErrorK::relation_kind,
                 "tycheck: malformed_deduction is not a struct relation");
      seal_check(malformed.arity == 5, SealErrorK::relation_arity,
                 "tycheck: malformed_deduction arity is not five");
      validate_order(malformed, check.order, "tycheck malformed sink");
      seal_check(out.program.operands.size() + 3
                   <= std::numeric_limits<u16>::max(),
                 SealErrorK::factory, "tycheck: operand bank overflow");
      seal_check(out.tychecks.size() < std::numeric_limits<u16>::max(),
                 SealErrorK::factory, "tycheck: too many bound checks");
      seal_check(plan.heads.size() + out.effects.size()
                   < std::numeric_limits<u16>::max(),
                 SealErrorK::factory, "tycheck: too many sink ports");
      const u16 operands = static_cast<u16>(out.program.operands.size());
      out.program.operands.push_back(check.rule);
      out.program.operands.push_back(check.relation);
      out.program.operands.push_back(check.column);
      const u16 check_slot = static_cast<u16>(out.tychecks.size());
      const u16 sink = static_cast<u16>(plan.heads.size() + out.effects.size());
      out.tychecks.push_back(check);
      out.effects.push_back(EmitPlan{check.malformed_relation, check.order,
                                     {check.rule, check.relation,
                                      check.column, check.value}});
      out.program.ops.push_back({OpK::tycheck, check_slot, check.value,
                                 operands, sink});
    }
  }
  for (size_t sink = 0; sink < plan.heads.size(); ++sink)
  {
    const EmitPlan& head = plan.heads[sink];
    const RelationShape* shape = nullptr;
    switch (head.head_kind)
    {
      case HeadK::set:
        shape = &relation_shape(relations, head.relation, "emit");
        validate_order(*shape, head.order, "emit");
        break;
      case HeadK::temp:
        // Temps have no requisitioned orderings; rows stage in nominal
        // order with no dedup (emit_temp), counted plans only.
        seal_check(counted, SealErrorK::capability,
                   "emit-temp: temp heads are admitted for counted "
                   "plans only");
        seal_check(head.relation < relations.size(),
                   SealErrorK::relation_slot,
                   "emit-temp: relation slot out of range");
        shape = &relations[head.relation];
        seal_check(shape->kind == RelationK::plain && shape->temp,
                   SealErrorK::relation_kind,
                   "emit-temp: not a temp relation");
        seal_check(shape->arity > 0 && shape->arity <= max_daemon_arity,
                   SealErrorK::relation_arity,
                   "emit-temp: unsupported relation arity");
        break;
      case HeadK::lattice:
        // Every contribution row is preserved in nominal storage order
        // (emit_lattice_count); counted plans only.
        seal_check(counted, SealErrorK::capability,
                   "emit-lat: lattice heads are admitted for counted "
                   "plans only");
        shape = &lattice_shape(relations, head.relation, "emit-lat");
        break;
      case HeadK::struct_:
        // Validated by the mkstruct pre-pass above; the emit stages the
        // full nominal-order row with the resolved id in place.
        shape = &struct_shape(relations, head.relation, "mkstruct emit");
        break;
    }
    const RelationShape& rel = *shape;
    seal_check(head.regs.size() == rel.arity, SealErrorK::relation_arity,
               "emit: register width mismatch");
    for (u16 reg : head.regs)
    {
      validate_reg(reg, plan.nregs, "emit");
      seal_check(assigned[reg], SealErrorK::dataflow,
                 "emit: read of unassigned register");
    }
    if (rel.arity == 2)
      out.program.ops.push_back({OpK::emit2, static_cast<u16>(sink),
                                 head.regs[0], head.regs[1], 0});
    else if (rel.arity == 3)
      out.program.ops.push_back({OpK::emit3, static_cast<u16>(sink),
                                 head.regs[0], head.regs[1], head.regs[2]});
    else
    {
      seal_check(out.program.operands.size() + head.regs.size()
                   <= std::numeric_limits<u16>::max(),
                 SealErrorK::factory,
                 "emit: operand bank overflow");
      const u16 offset = static_cast<u16>(out.program.operands.size());
      out.program.operands.insert(out.program.operands.end(),
                                  head.regs.begin(), head.regs.end());
      out.program.ops.push_back({OpK::emitn, static_cast<u16>(sink),
                                 offset, rel.arity, 0});
    }
  }
  return out;
}

inline std::vector<SealedRule> seal_rules(
  const std::vector<RulePlan>& plans,
  const std::vector<RelationShape>& relations,
  bool counted = false)
{
  std::set<std::pair<u32, std::string>> variants;
  std::vector<SealedRule> out;
  out.reserve(plans.size());
  for (const RulePlan& plan : plans)
  {
    seal_check(variants.insert({plan.rule_id, plan.variant}).second,
               SealErrorK::variant_identity,
               "rule: duplicate RuleVariant identity");
    out.push_back(seal_rule(plan, relations, counted));
  }
  return out;
}

DecodedKernelPlan parse_kernel_plan(std::string_view input);
DecodedKernelPlan parse_kernel_plan_file(const std::string& path);
u64 materialize_constant(Database& db, const ConstantPlan& constant);
SealedKernelPlan seal_kernel_plan(const DecodedKernelPlan& decoded,
                                  Database* constant_store = nullptr);

// Out-of-line full-arity factories (plan.cpp): the daemon binary pays for the
// storage templates once, and seal capability is exactly the domain below.
std::unique_ptr<PrefixCursor> make_set_probe_cursor(
  u16 arity, Index** index, const std::vector<u16>& regs, u16 bound);
std::unique_ptr<PrefixCursor> make_set_view_cursor(
  u16 arity, Index** full, Index** delta,
  const std::vector<u16>& regs, u16 bound, ProbePlan::View view);
std::unique_ptr<PrefixCursor> make_set_filter_cursor(
  u16 arity, Index** index, const std::vector<u16>& regs,
  u16 bound, FilterK kind);
std::unique_ptr<PrefixCursor> make_map_probe_cursor(
  u16 arity, Index** index, const std::vector<u16>& regs, u16 bound);
std::unique_ptr<PrefixCursor> make_map_filter_cursor(
  u16 arity, Index** index, const std::vector<u16>& regs,
  u16 bound, FilterK kind);
std::unique_ptr<PrefixCursor> make_join3_cursor(
  u16 left_arity, Index** left_full, Index** left_delta,
  const std::vector<u16>& left_regs, ProbePlan::View left_view,
  u16 right_arity, Index** right_full, Index** right_delta,
  const std::vector<u16>& right_regs, ProbePlan::View right_view,
  u16 cycle_reg);
std::unique_ptr<DriverCursor> make_delta_driver(
  Relation* relation, u16 bucket, u32 thread_count);
std::unique_ptr<DriverCursor> make_set_probe_driver(
  u16 arity, Index** index, const std::vector<u64>& prefix,
  u16 bound, u16 bucket);
std::unique_ptr<BoundSink> make_set_sink(
  u16 arity, Relation* relation, Index** index,
  const std::vector<u16>& order);
std::unique_ptr<BoundSink> make_struct_sink(
  u16 arity, Relation* relation, const std::vector<u16>& order);

// --- Thread-0 flavored factories (plan-count.cpp; interp-core-contract.md
// extension seams).  Count sinks batch kind-tagged contribution rows for
// the unchanged CountTask/CountStructTask folds; they never insert and
// never dedup (docs/incremental.md 8B.1).
std::unique_ptr<BoundSink> make_count_sink(
  u16 arity, Relation* relation, Index** index,
  const std::vector<u16>& order, u8 kind);
std::unique_ptr<BoundSink> make_temp_sink(u16 arity, Relation* relation);
std::unique_ptr<BoundSink> make_kind_batch_sink(
  u16 arity, Relation* relation, u8 kind);
std::unique_ptr<BoundSink> make_struct_count_sink(
  u16 arity, Relation* relation, Index** master,
  const std::vector<u16>& order, u8 kind);
// The mkstruct resolution cursor: an ordinary content-bound master probe
// whose zero-match exhaustion is a loud fatal (settled-fixpoint closure).
std::unique_ptr<PrefixCursor> make_struct_resolve_cursor(
  u16 arity, Index** index, const std::vector<u16>& regs, u16 bound,
  const std::string& relation_name);
// Counted rules bind these in place of emit_pending_error: a primitive
// fault's error-arm row is a kind-tagged contribution
// (emit_pending_error_count, docs/incremental.md 8B.4) folded by
// CountStructTask -- never a set-semantics insert, whose kind-less batch
// would invalidate and FREE the count sidecars mid-round at finalize.
void emit_pending_error_count_nonrec(Database* db, const char* loc);
void emit_pending_error_count_rec(Database* db, const char* loc);

struct BoundExecution
{
  std::vector<std::unique_ptr<BoundSink>> sinks;
  std::unique_ptr<Machine> machine;

  void flush()
  {
    for (auto& sink : sinks) sink->flush();
  }
};

class InterpReadTask;

class BoundRule
{
  SealedRule sealed;
  std::shared_ptr<const Program> pinned;
  std::vector<Relation*> frame;
  Database* database = nullptr;
  std::string stats_rule_variant_key;
  std::string stats_loc;
  std::string stats_tag;
  void (*error_fn)(Database*, const char*) = &emit_pending_error;
  std::vector<std::shared_ptr<const PrefixCursor>> cursor_prototypes;
  std::vector<std::shared_ptr<const PrefixCursor>> prefilter_prototypes;
  std::vector<BoundPrim> primitives;
  std::vector<BoundPrim> pre_primitives;
  std::vector<BoundTycheck> tychecks;

  std::vector<std::unique_ptr<PrefixCursor>> make_cursors() const
  {
    std::vector<std::unique_ptr<PrefixCursor>> cursors;
    cursors.reserve(cursor_prototypes.size());
    for (const auto& prototype : cursor_prototypes)
      cursors.push_back(prototype->clone());
    return cursors;
  }

  std::pair<std::vector<u64>, bool> initial_frame() const
  {
    std::vector<u64> regs(sealed.program.nregs, 0);
    for (const auto& [reg, value] : sealed.program.preloads)
      regs[reg] = value;
    size_t filter_slot = 0;
    size_t prim_slot = 0;
    for (const StraightPlan& op : sealed.preops)
    {
      if (std::holds_alternative<FilterPlan>(op))
      {
        auto cursor = prefilter_prototypes[filter_slot++]->clone();
        cursor->open(regs.data());
        WorkBudget budget{std::numeric_limits<u64>::max()};
        if (cursor->next(regs.data(), budget) != CursorResult::match)
          return {std::move(regs), false};
      }
      else if (const auto* neq = std::get_if<NeqPlan>(&op))
      {
        if (regs[neq->left] == regs[neq->right])
          return {std::move(regs), false};
      }
      else if (const auto* eq = std::get_if<EqPlan>(&op))
      {
        if (regs[eq->left] != regs[eq->right])
          return {std::move(regs), false};
      }
      else if (const auto* copy = std::get_if<CopyPlan>(&op))
        regs[copy->output] = regs[copy->input];
      else
      {
        const PrimPlan& prim = std::get<PrimPlan>(op);
        const BoundPrim& binding = pre_primitives[prim_slot++];
        std::array<u64, max_daemon_arity> args{};
        for (size_t i = 0; i < prim.args.size(); ++i)
          args[i] = regs[prim.args[i]];
        bool ok = true;
        const u64 value = binding.invoke(database, args.data(), &ok);
        if (value == slog_error)
        {
          error_fn(database, sealed.program.source.empty()
            ? "<interpreted>" : sealed.program.source.c_str());
          return {std::move(regs), false};
        }
        if (!ok || (prim.kind == PrimK::guard && value == 0))
          return {std::move(regs), false};
        if (prim.kind != PrimK::guard) regs[prim.output] = value;
      }
    }
    return {std::move(regs), true};
  }

  std::unique_ptr<BoundSink> make_effect_sink(const EmitPlan& effect) const
  {
    Relation* rel = frame[effect.relation];
    if (sealed.counted)
      // The counted tycheck diversion: malformed rows pre-exist at a
      // settled fixpoint, so the sink resolves by content probe and folds
      // a kind-tagged contribution (emit_struct_count).
      return make_struct_count_sink(rel->getArity(), rel,
        rel->getIndex(effect.order, false), effect.order, sealed.fold_kind);
    return make_struct_sink(rel->getArity(), rel, effect.order);
  }

  std::unique_ptr<BoundSink> make_head_sink(const EmitPlan& head) const
  {
    Relation* rel = frame[head.relation];
    switch (head.head_kind)
    {
      case HeadK::temp:
        return make_temp_sink(rel->getArity(), rel);
      case HeadK::lattice:
      case HeadK::struct_:
        // Nominal-order kind-tagged batching: lattice contributions are
        // preserved verbatim (emit_lattice_count), and struct rows arrive
        // with their id already bound by the resolution cursor.
        return make_kind_batch_sink(rel->getArity(), rel, sealed.fold_kind);
      case HeadK::set:
        break;
    }
    if (sealed.counted)
      return make_count_sink(rel->getArity(), rel,
        rel->getIndex(head.order, false), head.order, sealed.fold_kind);
    return make_set_sink(rel->getArity(), rel,
      rel->getIndex(head.order, false), head.order);
  }

public:
  BoundRule(SealedRule rule, std::vector<Relation*> binding,
            Database* db = nullptr)
    : sealed(std::move(rule)),
      pinned(std::make_shared<const Program>(sealed.program)),
      frame(std::move(binding)), database(db)
  {
    stats_rule_variant_key = "<interp-rule:"
      + std::to_string(sealed.program.rule_id) + ":variant:"
      + std::to_string(sealed.program.variant_ordinal) + ">";
    if (sealed.counted)
    {
      // Counted rounds keep the native $stat_fires identity -- source
      // location plus the base driver tag (no "/<kind>" suffix, no
      // "#<ordinal>") -- so cross-executor comparison stays at the
      // aggregated-golden level the exact-once audit pins.
      stats_loc = sealed.program.source.empty()
        ? stats_rule_variant_key : sealed.program.source;
      const size_t cut = sealed.program.variant.find_first_of("/#");
      stats_tag = cut == std::string::npos
        ? sealed.program.variant : sealed.program.variant.substr(0, cut);
    }
    else
    {
      stats_loc = stats_rule_variant_key;
      stats_tag = sealed.program.variant;
    }
    // A counted rule's primitive faults contribute kind-tagged error-arm
    // rows exactly like native counted code (emit_pending_error_count).
    if (sealed.counted)
      error_fn = sealed.fold_kind == cnt_kind_rec
        ? &emit_pending_error_count_rec
        : &emit_pending_error_count_nonrec;
    seal_check(frame.size() == sealed.relations.size(),
               SealErrorK::binding,
               "bind: relation frame width mismatch");

    // Canonical plans always contain the service-struct prelude.  It belongs
    // in the binding schema, but a normal-set rule neither resolves nor
    // validates an unused service slot.  Only operator requisitions are
    // binding requirements.
    const auto relation = [&](u16 slot) -> Relation* {
      seal_check(slot < frame.size() && frame[slot] != nullptr,
                 SealErrorK::binding, "bind: referenced relation is absent");
      Relation* rel = frame[slot];
      seal_check(rel->getArity() == sealed.relations[slot].arity,
                 SealErrorK::binding, "bind: relation arity mismatch");
      seal_check(rel->getStructId() == 0 && !rel->isLattice(),
                 SealErrorK::binding, "bind: relation kind mismatch");
      return rel;
    };
    const auto lattice_relation = [&](u16 slot) -> Relation* {
      seal_check(slot < frame.size() && frame[slot] != nullptr,
                 SealErrorK::binding, "bind: referenced lattice is absent");
      Relation* rel = frame[slot];
      seal_check(rel->getArity() == sealed.relations[slot].arity,
                 SealErrorK::binding, "bind: lattice arity mismatch");
      seal_check(rel->getStructId() == 0 && rel->isLattice(),
                 SealErrorK::binding, "bind: lattice kind mismatch");
      return rel;
    };
    const auto struct_relation = [&](u16 slot) -> Relation* {
      seal_check(slot < frame.size() && frame[slot] != nullptr,
                 SealErrorK::binding, "bind: referenced struct is absent");
      Relation* rel = frame[slot];
      seal_check(rel->getArity() == sealed.relations[slot].arity,
                 SealErrorK::binding, "bind: struct arity mismatch");
      seal_check(rel->getStructId() != 0 && !rel->isLattice(),
                 SealErrorK::binding, "bind: struct kind mismatch");
      return rel;
    };
    const auto index = [&](u16 slot, const std::vector<u16>& order) {
      seal_check(relation(slot)->hasIndex(order, false),
                 SealErrorK::binding,
                 "bind: requisitioned full index is absent");
    };
    const auto map_index = [&](u16 slot, const std::vector<u16>& order) {
      seal_check(lattice_relation(slot)->hasIndex(order, false),
                 SealErrorK::binding,
                 "bind: requisitioned lattice map index is absent");
    };
    const auto struct_index = [&](u16 slot, const std::vector<u16>& order) {
      seal_check(struct_relation(slot)->hasIndex(order, false),
                 SealErrorK::binding,
                 "bind: requisitioned struct master index is absent");
    };

    if (sealed.driver.kind == DriverK::scan_delta
        || sealed.driver.kind == DriverK::probe_full)
    {
      (void)relation(sealed.driver.relation);
      if (sealed.driver.kind == DriverK::probe_full)
        index(sealed.driver.relation, sealed.driver.order);
    }
    for (const StraightPlan& op : sealed.preops)
      if (const auto* filter = std::get_if<FilterPlan>(&op))
      {
        if (filter->lattice) map_index(filter->relation, filter->order);
        else index(filter->relation, filter->order);
      }
    for (const CursorPlan& cursor : sealed.cursors)
    {
      if (const auto* probe = std::get_if<ProbePlan>(&cursor))
      {
        if (probe->lattice)
          map_index(probe->relation, probe->order);
        else if (probe->struct_)
          struct_index(probe->relation, probe->order);
        else
          index(probe->relation, probe->order);
        if (!probe->lattice && !probe->struct_
            && probe->view != ProbePlan::View::full)
          seal_check(relation(probe->relation)->hasIndex(
                       probe->delta_order, true), SealErrorK::binding,
                     "bind: requisitioned delta index is absent");
      }
      else if (const auto* filter = std::get_if<FilterPlan>(&cursor))
      {
        if (filter->lattice) map_index(filter->relation, filter->order);
        else index(filter->relation, filter->order);
      }
      else
      {
        const Join3Plan& join3 = std::get<Join3Plan>(cursor);
        const auto arm = [&](const Join3ArmPlan& a) {
          index(a.relation, a.order);
          if (a.view != ProbePlan::View::full)
            seal_check(relation(a.relation)->hasIndex(
                         a.delta_order, true), SealErrorK::binding,
                       "bind: requisitioned join3 delta index is absent");
        };
        arm(join3.left);
        arm(join3.right);
      }
    }
    for (const EmitPlan& head : sealed.heads)
      switch (head.head_kind)
      {
        case HeadK::set:
          index(head.relation, head.order);
          break;
        case HeadK::temp:
          // Temps carry no indices; the sink appends nominal-order rows.
          (void)relation(head.relation);
          break;
        case HeadK::lattice:
          (void)lattice_relation(head.relation);
          break;
        case HeadK::struct_:
          // The resolution cursor above already requisitioned the master.
          (void)struct_relation(head.relation);
          break;
      }
    for (const EmitPlan& effect : sealed.effects)
    {
      seal_check(effect.relation < frame.size()
                   && frame[effect.relation] != nullptr,
                 SealErrorK::binding,
                 "bind: malformed_deduction relation is absent");
      Relation* rel = frame[effect.relation];
      seal_check(rel->getArity() == 5 && rel->getStructId() != 0
                   && !rel->isLattice(),
                 SealErrorK::binding,
                 "bind: malformed_deduction relation shape mismatch");
      seal_check(rel->hasIndex(effect.order, false), SealErrorK::binding,
                 "bind: malformed_deduction index is absent");
    }

    bool has_pre_primitive = false;
    for (const StraightPlan& op : sealed.preops)
      has_pre_primitive = has_pre_primitive
        || std::holds_alternative<PrimPlan>(op);
    seal_check(database != nullptr
                 || (sealed.primitive_names.empty() && !has_pre_primitive
                     && sealed.tychecks.empty()),
               SealErrorK::binding,
               "bind: database is required for primitive/type operations");

    primitives.reserve(sealed.primitive_names.size());
    for (const std::string& name : sealed.primitive_names)
      primitives.push_back(resolve_primitive(name));
    for (const StraightPlan& op : sealed.preops)
      if (const auto* prim = std::get_if<PrimPlan>(&op))
        pre_primitives.push_back(resolve_primitive(prim->name));

    tychecks.reserve(sealed.tychecks.size());
    for (const TycheckPlan& check : sealed.tychecks)
    {
      BoundTycheck bound;
      for (const TypePlan& type : check.accepts)
      {
        if (type.kind == TypeK::primitive)
        {
          if (type.name == "int") bound.primitive_mask |= type_accept_int;
          else if (type.name == "float") bound.primitive_mask |= type_accept_float;
          else if (type.name == "str") bound.primitive_mask |= type_accept_str;
          else if (type.name == "cnode") bound.primitive_mask |= type_accept_cnode;
          else if (type.name == "seq") bound.primitive_mask |= type_accept_seq;
        }
        else
        {
          Relation* accepted = database->getRelation(type.name);
          seal_check(accepted != nullptr && accepted->getStructId() != 0,
                     SealErrorK::binding,
                     "bind: accepted struct type is absent: " + type.name);
          bound.struct_ids.push_back(accepted->getStructId());
        }
      }
      std::sort(bound.struct_ids.begin(), bound.struct_ids.end());
      bound.struct_ids.erase(
        std::unique(bound.struct_ids.begin(), bound.struct_ids.end()),
        bound.struct_ids.end());
      tychecks.push_back(std::move(bound));
    }

    // Resolve the arity/factory ladders once at bind.  Worker tasks only
    // clone immutable, storage-bound cursor prototypes and open them.
    for (const StraightPlan& op : sealed.preops)
      if (const auto* filter = std::get_if<FilterPlan>(&op))
      {
        Relation* rel = filter->lattice
          ? lattice_relation(filter->relation) : relation(filter->relation);
        if (filter->lattice)
          prefilter_prototypes.push_back(make_map_filter_cursor(
            rel->getArity(), rel->getIndex(filter->order, false),
            filter->regs, filter->bound, filter->kind));
        else
          prefilter_prototypes.push_back(make_set_filter_cursor(
            rel->getArity(), rel->getIndex(filter->order, false),
            filter->regs, filter->bound, filter->kind));
      }
    cursor_prototypes.reserve(sealed.cursors.size());
    for (const CursorPlan& cursor : sealed.cursors)
    {
      if (const auto* probe = std::get_if<ProbePlan>(&cursor))
      {
        Relation* rel = probe->lattice ? lattice_relation(probe->relation)
          : probe->struct_ ? struct_relation(probe->relation)
          : relation(probe->relation);
        if (probe->lattice)
          cursor_prototypes.push_back(make_map_probe_cursor(
            rel->getArity(), rel->getIndex(probe->order, false),
            probe->regs, probe->bound));
        else if (probe->resolve)
          cursor_prototypes.push_back(make_struct_resolve_cursor(
            rel->getArity(), rel->getIndex(probe->order, false),
            probe->regs, probe->bound, rel->getName()));
        else if (probe->view == ProbePlan::View::full)
          cursor_prototypes.push_back(make_set_probe_cursor(
            rel->getArity(), rel->getIndex(probe->order, false),
            probe->regs, probe->bound));
        else
          cursor_prototypes.push_back(make_set_view_cursor(
            rel->getArity(), rel->getIndex(probe->order, false),
            rel->getIndex(probe->delta_order, true), probe->regs,
            probe->bound, probe->view));
      }
      else if (const auto* filter = std::get_if<FilterPlan>(&cursor))
      {
        Relation* rel = filter->lattice
          ? lattice_relation(filter->relation) : relation(filter->relation);
        if (filter->lattice)
          cursor_prototypes.push_back(make_map_filter_cursor(
            rel->getArity(), rel->getIndex(filter->order, false),
            filter->regs, filter->bound, filter->kind));
        else
          cursor_prototypes.push_back(make_set_filter_cursor(
            rel->getArity(), rel->getIndex(filter->order, false),
            filter->regs, filter->bound, filter->kind));
      }
      else
      {
        const Join3Plan& join3 = std::get<Join3Plan>(cursor);
        Relation* left = relation(join3.left.relation);
        Relation* right = relation(join3.right.relation);
        Index** left_delta = join3.left.view == ProbePlan::View::full
          ? left->getIndex(join3.left.order, false)
          : left->getIndex(join3.left.delta_order, true);
        Index** right_delta = join3.right.view == ProbePlan::View::full
          ? right->getIndex(join3.right.order, false)
          : right->getIndex(join3.right.delta_order, true);
        cursor_prototypes.push_back(make_join3_cursor(
          left->getArity(), left->getIndex(join3.left.order, false),
          left_delta, join3.left.regs, join3.left.view,
          right->getArity(), right->getIndex(join3.right.order, false),
          right_delta, join3.right.regs, join3.right.view, join3.cycle));
      }
    }
  }

  u16 task_count() const
  {
    if (sealed.driver.kind == DriverK::once
        || sealed.driver.kind == DriverK::seeded)
      return 1;
    if (sealed.driver.kind == DriverK::scan_delta) return bucket_count;
    return sealed.driver.bound == frame[sealed.driver.relation]->getArity()
         ? 1 : bucket_count;
  }

  // One empty driver row: the once/seeded fire-once dispatch.
  static std::unique_ptr<DriverCursor> make_unit_driver()
  {
    return std::make_unique<VectorDriverCursor>(
      std::make_shared<const std::vector<std::vector<u64>>>(1));
  }

  std::unique_ptr<Machine> make_task(u16 bucket, DebugSink* debug = nullptr,
                                     bool capture_outputs = true) const
  {
    auto [initial, pre_pass] = initial_frame();
    std::unique_ptr<DriverCursor> driver;
    if (!pre_pass)
      driver = std::make_unique<VectorDriverCursor>(
        std::make_shared<const std::vector<std::vector<u64>>>());
    else if (sealed.driver.kind == DriverK::once
             || sealed.driver.kind == DriverK::seeded)
      driver = make_unit_driver();
    else if (sealed.driver.kind == DriverK::scan_delta)
      driver = make_delta_driver(frame[sealed.driver.relation], bucket, 1);
    else
    {
      Relation* rel = frame[sealed.driver.relation];
      std::vector<u64> prefix;
      for (u16 i = 0; i < sealed.driver.bound; ++i)
        prefix.push_back(initial[sealed.driver.regs[i]]);
      driver = make_set_probe_driver(rel->getArity(),
        rel->getIndex(sealed.driver.order, false), prefix,
        sealed.driver.bound, bucket);
    }
    return std::make_unique<Machine>(pinned, std::move(driver), make_cursors(),
                                     std::vector<BoundSink*>{}, debug,
                                     capture_outputs, database, primitives,
                                     tychecks, error_fn,
                                     std::move(initial));
  }

  std::unique_ptr<BoundExecution> make_execution(Database* db, u16 bucket) const
  {
    seal_check(db != nullptr && (database == nullptr || database == db),
               SealErrorK::binding,
               "bind: execution database does not match bound database");
    auto execution = std::make_unique<BoundExecution>();
    execution->sinks.reserve(sealed.heads.size() + sealed.effects.size());
    for (const EmitPlan& head : sealed.heads)
      execution->sinks.push_back(make_head_sink(head));
    for (const EmitPlan& effect : sealed.effects)
      execution->sinks.push_back(make_effect_sink(effect));
    std::vector<BoundSink*> ports;
    for (auto& sink : execution->sinks) ports.push_back(sink.get());

    auto [initial, pre_pass] = initial_frame();
    std::unique_ptr<DriverCursor> driver;
    if (!pre_pass)
      driver = std::make_unique<VectorDriverCursor>(
        std::make_shared<const std::vector<std::vector<u64>>>());
    else if (sealed.driver.kind == DriverK::once
             || sealed.driver.kind == DriverK::seeded)
      driver = make_unit_driver();
    else if (sealed.driver.kind == DriverK::scan_delta)
      driver = make_delta_driver(frame[sealed.driver.relation], bucket,
                                 db->getThreadCount());
    else
    {
      Relation* rel = frame[sealed.driver.relation];
      std::vector<u64> prefix;
      for (u16 i = 0; i < sealed.driver.bound; ++i)
        prefix.push_back(initial[sealed.driver.regs[i]]);
      driver = make_set_probe_driver(rel->getArity(),
        rel->getIndex(sealed.driver.order, false), prefix,
        sealed.driver.bound, bucket);
    }
    execution->machine = std::make_unique<Machine>(
      pinned, std::move(driver), make_cursors(), std::move(ports), nullptr,
      false, db, primitives, tychecks, error_fn,
      std::move(initial));
    return execution;
  }

  void apply(const Attempt& attempt) const
  {
    std::vector<std::unique_ptr<BoundSink>> sinks;
    for (const EmitPlan& head : sealed.heads)
      sinks.push_back(make_head_sink(head));
    for (const EmitPlan& effect : sealed.effects)
      sinks.push_back(make_effect_sink(effect));
    seal_check(attempt.outputs.size() == attempt.output_sinks.size(),
               SealErrorK::binding,
               "commit: candidate/sink count mismatch");
    for (size_t i = 0; i < attempt.outputs.size(); ++i)
    {
      const u16 port = attempt.output_sinks[i];
      seal_check(port < sinks.size(), SealErrorK::binding,
                 "commit: sink port out of range");
      sinks[port]->stage(TupleView{attempt.outputs[i].data(),
                                   static_cast<u16>(attempt.outputs[i].size())});
    }
    for (auto& sink : sinks) sink->flush();
  }

  const SealedRule& definition() const { return sealed; }
  const std::string& statsKey() const { return stats_rule_variant_key; }
  const std::string& statsLoc() const { return stats_loc; }
  const std::string& statsTag() const { return stats_tag; }
  void attach(Database* db, Stratum* stratum, bool once_only = false) const;
};

std::vector<std::shared_ptr<BoundRule>> bind_kernel_plan(
  const SealedKernelPlan& plan, Database& db);

class InterpReadTask final : public Task
{
  Database* db;
  std::shared_ptr<const BoundRule> rule;
  u16 bucket;
  std::unique_ptr<BoundExecution> parked;

public:
  InterpReadTask(Database* database, std::shared_ptr<const BoundRule> bound,
                 u16 task_bucket,
                 std::unique_ptr<BoundExecution> continuation = nullptr)
    : db(database), rule(std::move(bound)), bucket(task_bucket),
      parked(std::move(continuation)) {}

  bool work() override
  {
    std::unique_ptr<BoundExecution> execution = parked
      ? std::move(parked) : rule->make_execution(db, bucket);
    const auto deadline = std::min(
      db->runDeadline(), std::chrono::steady_clock::now()
        + std::chrono::milliseconds(db->runSliceMs()));

    for (;;)
    {
      const StopReason why = execution->machine->run_fast(128, 128);
      if (why == StopReason::complete)
      {
        execution->flush();
        const Attempt& result = execution->machine->result();
        if (result.fires)
          db->bumpFires(rule->statsLoc().c_str(),
                        rule->statsTag().c_str(),
                        result.fires);
        return true;
      }
      if (db->runStopFlag().load(std::memory_order_relaxed)
          || std::chrono::steady_clock::now() >= deadline)
      {
        execution->flush();
        db->pushPaused(phase_read,
          new InterpReadTask(db, rule, bucket, std::move(execution)));
        return false;
      }
    }
  }
};

inline void BoundRule::attach(Database* db, Stratum* stratum,
                              bool once_only) const
{
  auto owned = std::make_shared<const BoundRule>(*this);
  for (u16 bucket = 0; bucket < task_count(); ++bucket)
    stratum->addTask(phase_read,
      new InterpReadTask(db, owned, bucket), once_only);
}

} // namespace interp
} // namespace slog
