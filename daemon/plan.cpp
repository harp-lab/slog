#include "plan.h"
#include "sexp.h"

#include <algorithm>
#include <charconv>
#include <cctype>
#include <fstream>
#include <mutex>

namespace slog
{
namespace interp
{

namespace
{

constexpr sexp::Limits plan_reader_limits{
  16 * 1024 * 1024,
  1 * 1024 * 1024,
  256
};

using SExp = sexp::SExp;

[[noreturn]] void syntax(const SExp& x, const std::string& message)
{
  throw PlanParseError(ParseErrorK::syntax, x.offset,
                       "plan: byte " + std::to_string(x.offset)
                         + ": " + message);
}

const std::string& atom(const SExp& x, const char* where)
{
  if (x.kind != SExp::K::atom) syntax(x, std::string(where) + ": expected atom");
  return x.text;
}

const std::string& string_value(const SExp& x, const char* where)
{
  if (x.kind != SExp::K::string)
    syntax(x, std::string(where) + ": expected string");
  return x.text;
}

const std::vector<SExp>& list(const SExp& x, const char* where)
{
  if (x.kind != SExp::K::list) syntax(x, std::string(where) + ": expected list");
  return x.children;
}

const std::vector<SExp>& tagged(const SExp& x, const char* tag,
                                size_t exact = std::numeric_limits<size_t>::max())
{
  const auto& xs = list(x, tag);
  if (xs.empty() || atom(xs[0], tag) != tag)
    syntax(x, std::string("expected (") + tag + " ...)");
  if (exact != std::numeric_limits<size_t>::max() && xs.size() != exact)
    syntax(x, std::string(tag) + ": wrong field count");
  return xs;
}

u64 natural(const SExp& x, u64 maximum, const char* where)
{
  const std::string& s = atom(x, where);
  if (s.empty() || !std::all_of(s.begin(), s.end(),
                                [](unsigned char c) { return std::isdigit(c); }))
    syntax(x, std::string(where) + ": expected natural number");
  u64 out = 0;
  const auto parsed = std::from_chars(s.data(), s.data() + s.size(), out);
  if (parsed.ec != std::errc{} || parsed.ptr != s.data() + s.size()
      || out > maximum)
    syntax(x, std::string(where) + ": number out of range");
  return out;
}

u16 small(const SExp& x, const char* where)
{
  return static_cast<u16>(natural(x, std::numeric_limits<u16>::max(), where));
}

u32 medium(const SExp& x, const char* where)
{
  return static_cast<u32>(natural(x, std::numeric_limits<u32>::max(), where));
}

std::vector<u16> order(const SExp& x, const char* where)
{
  std::vector<u16> out;
  for (const SExp& column : list(x, where)) out.push_back(small(column, where));
  return out;
}

u16 ref(const SExp& x, const char* kind, const char* where)
{
  const auto& xs = tagged(x, kind, 2);
  return small(xs[1], where);
}

u32 constant_ref(const SExp& x, const char* where)
{
  const auto& xs = tagged(x, "k", 2);
  return medium(xs[1], where);
}

std::string form_name(const SExp& x)
{
  if (x.kind != SExp::K::list || x.children.empty()
      || x.children[0].kind != SExp::K::atom)
    return "<malformed>";
  return x.children[0].text;
}

bool signed_integer(const std::string& s)
{
  size_t i = (!s.empty() && (s[0] == '+' || s[0] == '-')) ? 1 : 0;
  return i < s.size()
      && std::all_of(s.begin() + i, s.end(),
                     [](unsigned char c) { return std::isdigit(c); });
}

std::string lattice_spec_token(const SExp& spec)
{
  std::vector<std::string> parts;
  const auto flatten = [&](const auto& self, const SExp& part) -> void {
    if (part.kind == SExp::K::list)
      for (const SExp& child : part.children) self(self, child);
    else
      parts.push_back(atom(part, "lattice spec token"));
  };
  flatten(flatten, spec);
  if (parts.empty()) syntax(spec, "empty lattice spec");
  std::string token;
  for (const std::string& part : parts)
  {
    if (!token.empty()) token += '-';
    token += part;
  }
  return token;
}

u32 variant_ordinal(const std::string& tag)
{
  const size_t hash = tag.rfind('#');
  if (hash == std::string::npos || hash + 1 == tag.size()) return 0;
  const std::string_view suffix(tag.data() + hash + 1, tag.size() - hash - 1);
  if (!std::all_of(suffix.begin(), suffix.end(),
                   [](unsigned char c) { return std::isdigit(c); })) return 0;
  u32 out = 0;
  const auto parsed = std::from_chars(suffix.data(), suffix.data() + suffix.size(), out);
  return parsed.ec == std::errc{} ? out : 0;
}

// ABI-1 interim (counted-interp-contract.md): a counted rule's prov-keyed
// fold kind rides as the variant tag's "/<kind>" suffix (before any
// "#<ordinal>"), the same discrimination the ABI-2 fold-kind attribute will
// carry.  Returns cnt_kind_none when no kind suffix is present.
u8 variant_fold_kind(const std::string& tag)
{
  const size_t hash = tag.rfind('#');
  const std::string_view base(tag.data(),
    hash == std::string::npos ? tag.size() : hash);
  const size_t slash = base.rfind('/');
  if (slash == std::string_view::npos) return cnt_kind_none;
  const std::string_view kind = base.substr(slash + 1);
  if (kind == "nonrec") return cnt_kind_nonrec;
  if (kind == "rec") return cnt_kind_rec;
  return cnt_kind_none;
}

RelationBinding decode_relation(const SExp& x, u16 expected_slot)
{
  const auto& entry = tagged(x, "rel", 3);
  const u16 slot = small(entry[1], "relation slot");
  if (slot != expected_slot) syntax(entry[1], "relation slots must be dense");
  const auto& decl = list(entry[2], "relation declaration");
  if (decl.size() < 3) syntax(entry[2], "relation declaration is too short");
  const std::string& kind = atom(decl[0], "relation kind");
  RelationK relation_kind;
  if (kind == "relation" || kind == "temp") relation_kind = RelationK::plain;
  else if (kind == "struct") relation_kind = RelationK::struct_;
  else if (kind == "lattice") relation_kind = RelationK::lattice;
  else syntax(decl[0], "unknown storage declaration kind");
  const std::string name = atom(decl[1], "relation name");
  const u16 arity = small(decl[2], "relation arity");
  RelationShape shape{arity, {}, relation_kind};
  shape.temp = kind == "temp";
  size_t first_order = 3;
  if (relation_kind == RelationK::lattice)
  {
    if (decl.size() < 6)
      syntax(entry[2], "lattice declaration lacks spec/decomp/index");
    shape.lattice_spec = lattice_spec_token(decl[3]);
    if (decl[4].kind == SExp::K::list)
    {
      const auto& decomp = tagged(decl[4], "decomp", 3);
      shape.lattice_decomp_relation =
        atom(decomp[1], "lattice decomposition relation");
      const std::string& decomp_kind =
        atom(decomp[2], "lattice decomposition kind");
      if (decomp_kind != "set" && decomp_kind != "map")
        syntax(decomp[2], "unknown lattice decomposition kind");
      shape.lattice_decomp_map = decomp_kind == "map";
    }
    else if (atom(decl[4], "lattice decomposition") != "#f")
      syntax(decl[4], "malformed lattice decomposition");
    first_order = 5;
  }
  for (size_t i = first_order; i < decl.size(); ++i)
  {
    if (decl[i].kind != SExp::K::list) continue;
    if (decl[i].children.size() == static_cast<size_t>(arity) + 1
        && decl[i].children[0].kind == SExp::K::atom
        && decl[i].children[0].text == "delta")
    {
      std::vector<u16> delta_order;
      for (size_t j = 1; j < decl[i].children.size(); ++j)
        delta_order.push_back(small(decl[i].children[j],
                                    "delta relation ordering"));
      shape.delta_orders.push_back(std::move(delta_order));
      continue;
    }
    if (decl[i].children.size() == static_cast<size_t>(arity) + 1
        && decl[i].children[0].kind == SExp::K::atom
        && decl[i].children[0].text == "seeded-only")
    {
      std::vector<u16> seeded_order;
      for (size_t j = 1; j < decl[i].children.size(); ++j)
        seeded_order.push_back(small(decl[i].children[j],
                                     "seeded-only relation ordering"));
      shape.full_orders.push_back(seeded_order);
      shape.seeded_only_orders.push_back(std::move(seeded_order));
      continue;
    }
    if (decl[i].children.size() != arity) continue;
    bool numeric = true;
    for (const SExp& column : decl[i].children)
      numeric = numeric && column.kind == SExp::K::atom
        && !column.text.empty()
        && std::all_of(column.text.begin(), column.text.end(),
                       [](unsigned char c) { return std::isdigit(c); });
    if (numeric) shape.full_orders.push_back(order(decl[i], "relation ordering"));
  }
  return {slot, name, std::move(shape)};
}

AttachmentPlan decode_attachment(const SExp& x)
{
  const auto& xs = list(x, "attachment");
  if (xs.empty()) syntax(x, "empty attachment");
  const std::string& kind = atom(xs[0], "attachment kind");
  AttachmentPlan out;
  if (kind == "oracle")
  {
    if (xs.size() != 4) syntax(x, "oracle attachment arity mismatch");
    out.kind = AttachmentK::oracle;
    out.a = atom(xs[1], "oracle name");
    out.b = atom(xs[2], "oracle demand relation");
    out.c = atom(xs[3], "oracle answer relation");
  }
  else if (kind == "seqindex")
  {
    if (xs.size() != 3) syntax(x, "seqindex attachment arity mismatch");
    out.kind = AttachmentK::seqindex;
    out.a = atom(xs[1], "seqindex base relation");
    const auto& columns = list(xs[2], "seqindex columns");
    if (columns.empty()) syntax(xs[2], "seqindex columns are empty");
    for (const SExp& column : columns)
      out.columns.push_back(small(column, "seqindex column"));
  }
  else
  {
    out.kind = AttachmentK::unsupported;
    out.a = kind;
  }
  return out;
}

FilterPlan decode_filter(const SExp& op, FilterK kind, bool lattice = false)
{
  const char* where = lattice ? "absent-lat"
    : (kind == FilterK::exists ? "exists" : "absent");
  const auto& xs = list(op, where);
  if (xs.size() < 4)
    syntax(op, kind == FilterK::exists
      ? "exists is too short" : "absent is too short");
  FilterPlan filter;
  filter.kind = kind;
  filter.lattice = lattice;
  filter.relation = ref(xs[1], "rel", "filter relation");
  filter.order = order(xs[2], "filter ordering");
  filter.bound = small(xs[3], "filter bound prefix");
  for (size_t i = 4; i < xs.size(); ++i)
    filter.regs.push_back(ref(xs[i], "r", "filter register"));
  return filter;
}

// (absent-old (rel n) (ord...) K (dord...) (r ...) ...) and the absent-new
// twin (M4N pin 4): pre/post-state absence over a final stratum, carrying
// the delta ordering exactly as join-old/join-new do.
FilterPlan decode_absent_view(const SExp& op, AbsentView view)
{
  const char* where = view == AbsentView::pre    ? "absent-old"
                    : view == AbsentView::post   ? "absent-new"
                                                 : "absent-ever";
  const auto& xs = list(op, where);
  if (xs.size() < 5)
    syntax(op, std::string(where) + " is too short");
  FilterPlan filter;
  filter.kind = FilterK::absent;
  filter.view = view;
  filter.relation = ref(xs[1], "rel", "filter relation");
  filter.order = order(xs[2], "filter ordering");
  filter.bound = small(xs[3], "filter bound prefix");
  filter.delta_order = order(xs[4], "filter delta ordering");
  for (size_t i = 5; i < xs.size(); ++i)
    filter.regs.push_back(ref(xs[i], "r", "filter register"));
  return filter;
}

PrimPlan decode_primitive(const SExp& op, PrimK kind)
{
  const char* where = kind == PrimK::partial ? "letp" : "let";
  const auto& xs = tagged(op, where, 3);
  const auto& call = tagged(xs[2], "prim");
  if (call.size() < 2) syntax(xs[2], "primitive call is too short");
  PrimPlan out;
  out.kind = kind;
  out.output = ref(xs[1], "r", "primitive output register");
  out.name = atom(call[1], "primitive name");
  for (size_t i = 2; i < call.size(); ++i)
    out.args.push_back(ref(call[i], "r", "primitive argument register"));
  return out;
}

PrimPlan decode_cjoin(const SExp& op)
{
  const auto& xs = tagged(op, "cjoin", 5);
  PrimPlan out;
  out.kind = PrimK::total;
  out.name = "$cjoin:" + lattice_spec_token(xs[2]);
  out.output = ref(xs[1], "r", "cjoin output register");
  out.args.push_back(ref(xs[3], "r", "cjoin left register"));
  out.args.push_back(ref(xs[4], "r", "cjoin right register"));
  return out;
}

CopyPlan decode_copy(const SExp& op)
{
  const auto& xs = tagged(op, "let", 3);
  return {ref(xs[1], "r", "copy output register"),
          ref(xs[2], "r", "copy input register")};
}

PrimPlan decode_comparison(const SExp& op)
{
  const auto& xs = tagged(op, "cmp", 4);
  PrimPlan out;
  out.kind = PrimK::guard;
  out.name = atom(xs[1], "comparison primitive");
  out.args = {ref(xs[2], "r", "comparison left register"),
              ref(xs[3], "r", "comparison right register")};
  return out;
}

TycheckPlan decode_tycheck(const SExp& op)
{
  const auto& xs = tagged(op, "tycheck", 7);
  const auto& accepts = tagged(xs[2], "accept");
  if (accepts.size() < 2) syntax(xs[2], "tycheck accept set is empty");
  TycheckPlan out;
  out.value = ref(xs[1], "r", "tycheck value register");
  for (size_t i = 1; i < accepts.size(); ++i)
  {
    if (accepts[i].kind == SExp::K::atom)
      out.accepts.push_back({TypeK::primitive,
                             atom(accepts[i], "tycheck accept type")});
    else
    {
      const auto& type = tagged(accepts[i], "struct", 2);
      out.accepts.push_back({TypeK::struct_,
                             atom(type[1], "tycheck struct type")});
    }
  }
  out.rule = ref(xs[3], "r", "tycheck rule register");
  out.relation = ref(xs[4], "r", "tycheck relation register");
  out.column = ref(xs[5], "r", "tycheck column register");
  out.order = order(xs[6], "tycheck malformed ordering");
  return out;
}

Join3ArmPlan decode_join3_arm(const SExp& arm)
{
  const auto& xs = list(arm, "join3 arm");
  if (xs.size() < 6) syntax(arm, "join3 arm is too short");
  Join3ArmPlan out;
  const std::string& view = atom(xs[0], "join3 arm view");
  if (view == "full") out.view = ProbePlan::View::full;
  else if (view == "old") out.view = ProbePlan::View::old;
  else if (view == "new") out.view = ProbePlan::View::new_;
  else syntax(xs[0], "unknown join3 arm view");
  out.relation = ref(xs[1], "rel", "join3 arm relation");
  out.order = order(xs[2], "join3 arm ordering");
  out.bound = small(xs[3], "join3 arm bound prefix");
  out.delta_order = order(xs[4], "join3 arm delta ordering");
  for (size_t i = 5; i < xs.size(); ++i)
    out.regs.push_back(ref(xs[i], "r", "join3 arm register"));
  return out;
}

Join3Plan decode_join3(const SExp& op)
{
  const auto& xs = tagged(op, "join3", 4);
  return {ref(xs[1], "r", "join3 cycle register"),
          decode_join3_arm(xs[2]), decode_join3_arm(xs[3])};
}

ConstantPlan decode_constant(const SExp& x, u32 expected_slot)
{
  const auto& entry = tagged(x, "k", 4);
  const u32 slot = medium(entry[1], "constant slot");
  if (slot != expected_slot) syntax(entry[1], "constant slots must be dense");
  ConstantPlan out;
  out.slot = slot;
  out.name = atom(entry[2], "constant name");
  const SExp& value = entry[3];
  if (value.kind == SExp::K::string)
  {
    out.kind = ConstantK::string;
    out.text = value.text;
  }
  else if (value.kind == SExp::K::list)
  {
    out.kind = ConstantK::compound;
  }
  else if (value.text == "#t" || value.text == "#f")
  {
    out.kind = ConstantK::boolean;
    out.text = value.text;
  }
  else if (signed_integer(value.text))
  {
    out.kind = ConstantK::integer;
    out.text = value.text;
  }
  else if (value.text.find_first_of(".eE") != std::string::npos)
  {
    out.kind = ConstantK::real;
    out.text = value.text;
  }
  else
  {
    out.kind = ConstantK::symbol;
    out.text = value.text;
  }
  return out;
}

DecodedRule decode_rule(const SExp& x)
{
  const auto& fields = tagged(x, "rule-def", 8);
  const auto& rid = tagged(fields[1], "rid", 2);
  const auto& variant = tagged(fields[2], "variant", 2);
  const auto& nregs = tagged(fields[3], "nregs", 2);

  DecodedRule out;
  out.plan.rule_id = medium(rid[1], "rule id");
  out.plan.variant = string_value(variant[1], "variant");
  out.plan.variant_ordinal = variant_ordinal(out.plan.variant);
  out.plan.nregs = small(nregs[1], "register count");

  const auto& pre = tagged(fields[4], "pre");
  for (size_t i = 1; i < pre.size(); ++i)
  {
    const SExp& op = pre[i];
    if (form_name(op) == "let" && op.kind == SExp::K::list
        && op.children.size() == 3 && form_name(op.children[1]) == "r"
        && form_name(op.children[2]) == "k")
      out.constant_preloads.push_back(
        {ref(op.children[1], "r", "preload register"),
         constant_ref(op.children[2], "preload constant")});
    else if (form_name(op) == "exists")
    {
      FilterPlan filter = decode_filter(op, FilterK::exists);
      out.plan.prefilters.push_back(filter);
      out.plan.preops.emplace_back(std::move(filter));
    }
    else if (form_name(op) == "absent")
    {
      FilterPlan filter = decode_filter(op, FilterK::absent);
      out.plan.prefilters.push_back(filter);
      out.plan.preops.emplace_back(std::move(filter));
    }
    else if (form_name(op) == "absent-lat")
    {
      FilterPlan filter = decode_filter(op, FilterK::absent, true);
      out.plan.prefilters.push_back(filter);
      out.plan.preops.emplace_back(std::move(filter));
    }
    else if (form_name(op) == "absent-old" || form_name(op) == "absent-new"
             || form_name(op) == "absent-ever")
    {
      FilterPlan filter = decode_absent_view(op,
        form_name(op) == "absent-old" ? AbsentView::pre
        : form_name(op) == "absent-new" ? AbsentView::post
                                        : AbsentView::ever);
      out.plan.prefilters.push_back(filter);
      out.plan.preops.emplace_back(std::move(filter));
    }
    else if (form_name(op) == "let")
    {
      const auto& xs = tagged(op, "let", 3);
      if (form_name(xs[2]) == "prim")
        out.plan.preops.emplace_back(decode_primitive(op, PrimK::total));
      else
        out.plan.preops.emplace_back(decode_copy(op));
    }
    else if (form_name(op) == "letp")
      out.plan.preops.emplace_back(decode_primitive(op, PrimK::partial));
    else if (form_name(op) == "cjoin")
      out.plan.preops.emplace_back(decode_cjoin(op));
    else if (form_name(op) == "eq")
    {
      const auto& xs = tagged(op, "eq", 3);
      out.plan.preops.emplace_back(EqPlan{
        ref(xs[1], "r", "eq left register"),
        ref(xs[2], "r", "eq right register")});
    }
    else if (form_name(op) == "neq")
    {
      const auto& xs = tagged(op, "neq", 3);
      out.plan.preops.emplace_back(NeqPlan{
        ref(xs[1], "r", "neq left register"),
        ref(xs[2], "r", "neq right register")});
    }
    else if (form_name(op) == "cmp")
      out.plan.preops.emplace_back(decode_comparison(op));
    else
      out.unsupported.push_back("pre:" + form_name(op));
  }

  const auto& driver_field = tagged(fields[5], "driver", 2);
  const SExp& driver = driver_field[1];
  const std::string driver_name = form_name(driver);
  if (driver_name == "scan")
  {
    const auto& ds = list(driver, "scan driver");
    if (ds.size() < 3) syntax(driver, "scan driver is too short");
    out.plan.driver.kind = DriverK::scan_delta;
    out.plan.driver.relation = ref(ds[1], "rel", "scan relation");
    for (size_t i = 2; i < ds.size(); ++i)
      out.plan.driver.regs.push_back(ref(ds[i], "r", "scan register"));
  }
  else if (driver_name == "probe")
  {
    const auto& ds = list(driver, "probe driver");
    if (ds.size() < 5) syntax(driver, "probe driver is too short");
    out.plan.driver.kind = DriverK::probe_delta;
    out.plan.driver.relation = ref(ds[1], "rel", "probe relation");
    out.plan.driver.order = order(ds[2], "probe ordering");
    out.plan.driver.bound = small(ds[3], "probe bound prefix");
    for (size_t i = 4; i < ds.size(); ++i)
      out.plan.driver.regs.push_back(ref(ds[i], "r", "probe register"));
  }
  else if (driver_name == "once" || driver_name == "seeded")
  {
    // One empty driver row; admitted at seal for counted plans only.
    if (list(driver, driver_name.c_str()).size() != 1)
      syntax(driver, driver_name + " driver takes no arguments");
    out.plan.driver.kind = driver_name == "once"
      ? DriverK::once : DriverK::seeded;
  }
  else
  {
    out.unsupported.push_back("driver:" + driver_name);
  }

  const auto& body = tagged(fields[6], "body");
  for (size_t i = 1; i < body.size(); ++i)
  {
    const SExp& op = body[i];
    const std::string name = form_name(op);
    if (name == "join" || name == "join-old" || name == "join-new")
    {
      const auto& xs = list(op, "join");
      const bool viewed = name != "join";
      if (xs.size() < (viewed ? 6u : 5u))
        syntax(op, name + " is too short");
      ProbePlan probe;
      probe.relation = ref(xs[1], "rel", "join relation");
      probe.order = order(xs[2], "join ordering");
      probe.bound = small(xs[3], "join bound prefix");
      size_t first_reg = 4;
      if (viewed)
      {
        probe.view = name == "join-old"
          ? ProbePlan::View::old : ProbePlan::View::new_;
        probe.delta_order = order(xs[4], "join delta ordering");
        first_reg = 5;
      }
      for (size_t j = first_reg; j < xs.size(); ++j)
        probe.regs.push_back(ref(xs[j], "r", "join register"));
      out.plan.body.push_back(std::move(probe));
    }
    else if (name == "join-tomb")
    {
      // (join-tomb (rel n) (ord...) K (r ...) ...): full-content struct
      // resolution through the live master then the tombstone dictionary
      // (negative maintenance; K is always arity-1, no delta ordering).
      const auto& xs = list(op, "join-tomb");
      if (xs.size() < 5) syntax(op, "join-tomb is too short");
      ProbePlan probe;
      probe.tomb = true;
      probe.relation = ref(xs[1], "rel", "join-tomb relation");
      probe.order = order(xs[2], "join-tomb ordering");
      probe.bound = small(xs[3], "join-tomb bound prefix");
      for (size_t j = 4; j < xs.size(); ++j)
        probe.regs.push_back(ref(xs[j], "r", "join-tomb register"));
      out.plan.body.push_back(std::move(probe));
    }
    else if (name == "join-lat")
    {
      const auto& xs = list(op, "join-lat");
      if (xs.size() < 5) syntax(op, "join-lat is too short");
      ProbePlan probe;
      probe.lattice = true;
      probe.relation = ref(xs[1], "rel", "join-lat relation");
      probe.order = order(xs[2], "join-lat ordering");
      probe.bound = small(xs[3], "join-lat bound prefix");
      for (size_t j = 4; j < xs.size(); ++j)
        probe.regs.push_back(ref(xs[j], "r", "join-lat register"));
      out.plan.body.push_back(std::move(probe));
    }
    else if (name == "exists")
      out.plan.body.push_back(decode_filter(op, FilterK::exists));
    else if (name == "absent")
      out.plan.body.push_back(decode_filter(op, FilterK::absent));
    else if (name == "absent-lat")
      out.plan.body.push_back(decode_filter(op, FilterK::absent, true));
    else if (name == "absent-old")
      out.plan.body.push_back(decode_absent_view(op, AbsentView::pre));
    else if (name == "absent-new")
      out.plan.body.push_back(decode_absent_view(op, AbsentView::post));
    else if (name == "absent-ever")
      out.plan.body.push_back(decode_absent_view(op, AbsentView::ever));
    else if (name == "join3")
      out.plan.body.emplace_back(decode_join3(op));
    else if (name == "neq")
    {
      const auto& xs = tagged(op, "neq", 3);
      out.plan.body.push_back(NeqPlan{
        ref(xs[1], "r", "neq left register"),
        ref(xs[2], "r", "neq right register")});
    }
    else if (name == "eq")
    {
      const auto& xs = tagged(op, "eq", 3);
      out.plan.body.push_back(EqPlan{
        ref(xs[1], "r", "eq left register"),
        ref(xs[2], "r", "eq right register")});
    }
    else if (name == "let")
    {
      const auto& xs = tagged(op, "let", 3);
      if (form_name(xs[2]) == "prim")
        out.plan.body.emplace_back(decode_primitive(op, PrimK::total));
      else
        out.plan.body.emplace_back(decode_copy(op));
    }
    else if (name == "letp")
      out.plan.body.emplace_back(decode_primitive(op, PrimK::partial));
    else if (name == "cjoin")
      out.plan.body.emplace_back(decode_cjoin(op));
    else if (name == "cmp")
      out.plan.body.emplace_back(decode_comparison(op));
    else
      out.unsupported.push_back("body:" + name);
  }

  const auto& head = tagged(fields[7], "head");
  bool saw_emit = false;
  for (size_t i = 1; i < head.size(); ++i)
  {
    const SExp& op = head[i];
    const std::string name = form_name(op);
    if (name == "emit")
    {
      saw_emit = true;
      const auto& xs = list(op, "emit");
      if (xs.size() < 4) syntax(op, "emit is too short");
      EmitPlan emit;
      emit.relation = ref(xs[1], "rel", "emit relation");
      emit.order = order(xs[2], "emit ordering");
      for (size_t j = 3; j < xs.size(); ++j)
        emit.regs.push_back(ref(xs[j], "r", "emit register"));
      out.plan.heads.push_back(std::move(emit));
    }
    else if (name == "let" || name == "letp")
    {
      if (saw_emit) out.unsupported.push_back("head:non-prefix-" + name);
      else if (name == "letp")
        out.plan.head_prefix.emplace_back(
          decode_primitive(op, PrimK::partial));
      else
      {
        const auto& xs = tagged(op, "let", 3);
        if (form_name(xs[2]) == "prim")
          out.plan.head_prefix.emplace_back(
            decode_primitive(op, PrimK::total));
        else
          out.plan.head_prefix.emplace_back(decode_copy(op));
      }
    }
    else if (name == "cjoin")
    {
      if (saw_emit) out.unsupported.push_back("head:non-prefix-cjoin");
      else out.plan.head_prefix.emplace_back(decode_cjoin(op));
    }
    else if (name == "tycheck")
    {
      if (saw_emit) out.unsupported.push_back("head:non-prefix-tycheck");
      else out.plan.head_prefix.emplace_back(decode_tycheck(op));
    }
    else if (name == "emit-temp")
    {
      // (emit-temp (rel n) (r ...) ...): nominal-order staging into a
      // per-rule temp; no ordering field (temps carry no indices).
      saw_emit = true;
      const auto& xs = list(op, "emit-temp");
      if (xs.size() < 3) syntax(op, "emit-temp is too short");
      EmitPlan emit;
      emit.head_kind = HeadK::temp;
      emit.relation = ref(xs[1], "rel", "emit-temp relation");
      for (size_t j = 2; j < xs.size(); ++j)
        emit.regs.push_back(ref(xs[j], "r", "emit-temp register"));
      for (u16 j = 0; j + 2 < xs.size(); ++j)
        emit.order.push_back(j);
      out.plan.heads.push_back(std::move(emit));
    }
    else if (name == "emit-lat")
    {
      // (emit-lat (rel n) (r ...) ...): nominal-order contribution rows.
      saw_emit = true;
      const auto& xs = list(op, "emit-lat");
      if (xs.size() < 3) syntax(op, "emit-lat is too short");
      EmitPlan emit;
      emit.head_kind = HeadK::lattice;
      emit.relation = ref(xs[1], "rel", "emit-lat relation");
      for (size_t j = 2; j < xs.size(); ++j)
        emit.regs.push_back(ref(xs[j], "r", "emit-lat register"));
      for (u16 j = 0; j + 2 < xs.size(); ++j)
        emit.order.push_back(j);
      out.plan.heads.push_back(std::move(emit));
    }
    else if (name == "mkstruct")
    {
      // (mkstruct (rel n) (ord...) (r id) (r field) ...): registers in
      // nominal order, the id column (nominal 0) listed first; the master
      // ordering is content-first, id-last.
      saw_emit = true;
      const auto& xs = list(op, "mkstruct");
      if (xs.size() < 5) syntax(op, "mkstruct is too short");
      EmitPlan emit;
      emit.head_kind = HeadK::struct_;
      emit.relation = ref(xs[1], "rel", "mkstruct relation");
      emit.order = order(xs[2], "mkstruct ordering");
      for (size_t j = 3; j < xs.size(); ++j)
        emit.regs.push_back(ref(xs[j], "r", "mkstruct register"));
      out.plan.heads.push_back(std::move(emit));
    }
    else
      out.unsupported.push_back("head:" + name);
  }
  return out;
}

} // namespace

namespace
{

template <u64 (*Fn)(Database*)>
u64 invoke0(Database* db, const u64*, bool*) { return Fn(db); }
template <u64 (*Fn)(Database*, u64)>
u64 invoke1(Database* db, const u64* a, bool*) { return Fn(db, a[0]); }
template <u64 (*Fn)(Database*, u64, u64)>
u64 invoke2(Database* db, const u64* a, bool*)
{ return Fn(db, a[0], a[1]); }
template <u64 (*Fn)(Database*, u64, u64, u64)>
u64 invoke3(Database* db, const u64* a, bool*)
{ return Fn(db, a[0], a[1], a[2]); }
template <u64 (*Fn)(Database*, u64, bool*)>
u64 invoke_partial1(Database* db, const u64* a, bool* ok)
{ return Fn(db, a[0], ok); }
template <u64 (*Fn)(Database*, u64, u64, bool*)>
u64 invoke_partial2(Database* db, const u64* a, bool* ok)
{ return Fn(db, a[0], a[1], ok); }
template <u64 (*Fn)(Database*, u64, u64, u64, bool*)>
u64 invoke_partial3(Database* db, const u64* a, bool* ok)
{ return Fn(db, a[0], a[1], a[2], ok); }

struct PrimitiveEntry
{
  std::string_view name;
  BoundPrim binding;
};

u64 invoke_cjoin(Database* db, const u64* args, bool*)
{
  const auto* spec = reinterpret_cast<const LatSpec*>(
    static_cast<uintptr_t>(args[2]));
  if (spec == nullptr) fatal("cjoin: missing sealed lattice spec");
  return db->collections()->merge_spec(args[0], args[1], spec);
}

#define TOTAL0(n) PrimitiveEntry{#n, {invoke0<&::_prim_##n>, 0, false, false}}
#define TOTAL1(n) PrimitiveEntry{#n, {invoke1<&::_prim_##n>, 1, false, false}}
#define TOTAL2(n) PrimitiveEntry{#n, {invoke2<&::_prim_##n>, 2, false, false}}
#define TOTAL3(n) PrimitiveEntry{#n, {invoke3<&::_prim_##n>, 3, false, false}}
#define COMPARE2(n) PrimitiveEntry{#n, {invoke2<&::_prim_##n>, 2, false, true}}
#define PARTIAL1(n) PrimitiveEntry{#n, {invoke_partial1<&::_prim_##n>, 1, true, false}}
#define PARTIAL2(n) PrimitiveEntry{#n, {invoke_partial2<&::_prim_##n>, 2, true, false}}
#define PARTIAL3(n) PrimitiveEntry{#n, {invoke_partial3<&::_prim_##n>, 3, true, false}}

const std::vector<PrimitiveEntry>& primitive_registry()
{
  static const std::vector<PrimitiveEntry> entries{
    PrimitiveEntry{"$cjoin", {invoke_cjoin, 3, false, false}},
    TOTAL2(_0002b), TOTAL2(_0002d), TOTAL2(_0002a), TOTAL2(_0002f),
    TOTAL2(_00025), TOTAL1(neg), TOTAL1(abs), TOTAL2(min), TOTAL2(max),
    TOTAL2(pow), TOTAL2(band), TOTAL2(bor), TOTAL2(bxor), TOTAL1(bnot),
    TOTAL2(shl), TOTAL2(shr), TOTAL1(sqrt), TOTAL1(sin), TOTAL1(cos),
    TOTAL1(tan), TOTAL1(exp), TOTAL1(log), TOTAL1(floor), TOTAL1(ceil),
    TOTAL1(round), TOTAL1(tofloat), TOTAL1(toint), TOTAL1(size),
    TOTAL3(substr), PARTIAL2(sidx), TOTAL2(shas), PARTIAL2(schar),
    TOTAL2(ssplit), TOTAL2(sjoin), PARTIAL1(s2i), PARTIAL1(s2f),
    TOTAL1(i2s), TOTAL1(f2s), TOTAL0(cmap), TOTAL3(cput), PARTIAL2(cget),
    TOTAL2(chas), TOTAL2(cmerge), TOTAL2(cdel), TOTAL2(cdiff), TOTAL1(csize),
    TOTAL2(cins), TOTAL2(cmem), TOTAL0(lempty), TOTAL2(lpush),
    PARTIAL1(aslst), TOTAL1(llen), PARTIAL2(lref), PARTIAL3(lset),
    PARTIAL3(lins), PARTIAL2(ldel), TOTAL2(lcat), TOTAL3(lslice),
    TOTAL1(lrev), PARTIAL2(lidx), TOTAL2(lmem), TOTAL1(lsort),
    TOTAL1(lst2set), TOTAL1(set2lst), TOTAL1(ckeys), TOTAL1(cvals),
    TOTAL0(one), TOTAL0(inf), TOTAL2(cplus), TOTAL0(top),
    COMPARE2(lt), COMPARE2(le), COMPARE2(gt), COMPARE2(ge)
  };
  return entries;
}

#undef TOTAL0
#undef TOTAL1
#undef TOTAL2
#undef TOTAL3
#undef COMPARE2
#undef PARTIAL1
#undef PARTIAL2
#undef PARTIAL3

} // namespace

u64 intern_cjoin_spec(std::string_view token)
{
  static_assert(sizeof(uintptr_t) <= sizeof(u64));
  static std::mutex lock;
  static std::map<std::string, std::unique_ptr<LatSpec>> specs;
  std::lock_guard<std::mutex> guard(lock);
  const std::string key(token);
  auto found = specs.find(key);
  if (found == specs.end())
  {
    std::unique_ptr<LatSpec> parsed(parseLatSpecToken(key));
    if (!parsed)
      throw SealError(SealErrorK::capability,
                      "cjoin: malformed lattice spec token: " + key);
    found = specs.emplace(key, std::move(parsed)).first;
  }
  return static_cast<u64>(reinterpret_cast<uintptr_t>(found->second.get()));
}

BoundPrim resolve_primitive(std::string_view name)
{
  for (const PrimitiveEntry& entry : primitive_registry())
    if (entry.name == name) return entry.binding;
  throw SealError(SealErrorK::capability,
                  "primitive: unsupported canonical name "
                    + std::string(name));
}

const char* seal_error_class(SealErrorK kind)
{
  switch (kind)
  {
    case SealErrorK::abi: return "abi";
    case SealErrorK::flavor: return "flavor";
    case SealErrorK::capability: return "capability";
    case SealErrorK::register_bounds: return "register-bounds";
    case SealErrorK::dataflow: return "dataflow";
    case SealErrorK::relation_slot: return "relation-slot";
    case SealErrorK::relation_kind: return "relation-kind";
    case SealErrorK::relation_arity: return "relation-arity";
    case SealErrorK::constant_slot: return "constant-slot";
    case SealErrorK::ordering: return "ordering";
    case SealErrorK::index_requisition: return "index-requisition";
    case SealErrorK::bound_prefix: return "bound-prefix";
    case SealErrorK::head_coverage: return "head-coverage";
    case SealErrorK::variant_identity: return "variant-identity";
    case SealErrorK::factory: return "factory";
    case SealErrorK::binding: return "binding";
  }
  return "capability";
}

const char* parse_error_class(ParseErrorK kind)
{
  switch (kind)
  {
    case ParseErrorK::syntax: return "parse";
    case ParseErrorK::limit: return "parse-limit";
    case ParseErrorK::io: return "plan-io";
  }
  return "parse";
}

DecodedKernelPlan parse_kernel_plan(std::string_view input)
{
  SExp root;
  try { root = sexp::read_one(input, plan_reader_limits); }
  catch (const sexp::ReaderError& error)
  {
    throw PlanParseError(
      error.kind() == sexp::ReaderErrorK::limit
        ? ParseErrorK::limit : ParseErrorK::syntax,
      error.offset(), "plan: " + std::string(error.what()));
  }
  const auto& fields = tagged(root, "kernel-plan", 10);
  const auto& abi = tagged(fields[1], "abi", 2);
  const auto& flavor = tagged(fields[2], "flavor", 2);
  const auto& relations = tagged(fields[3], "relations");
  const auto& attachments = tagged(fields[4], "attachments");
  const auto& constants = tagged(fields[5], "constants");
  const auto& prims = tagged(fields[6], "prims");
  const auto& dynamic = tagged(fields[7], "dynamic");
  const auto& rules = tagged(fields[8], "rules");
  const auto& meta = tagged(fields[9], "meta");

  DecodedKernelPlan out;
  out.abi = medium(abi[1], "plan ABI");
  out.flavor = atom(flavor[1], "plan flavor");
  out.attachment_count = attachments.size() - 1;
  for (size_t i = 1; i < attachments.size(); ++i)
    out.attachments.push_back(decode_attachment(attachments[i]));
  for (size_t i = 1; i < relations.size(); ++i)
  {
    if (i - 1 > std::numeric_limits<u16>::max())
      syntax(relations[i], "too many relation slots");
    out.bindings.push_back(decode_relation(
      relations[i], static_cast<u16>(i - 1)));
  }
  for (size_t i = 1; i < constants.size(); ++i)
    out.constants.push_back(decode_constant(constants[i],
      static_cast<u32>(i - 1)));
  for (size_t i = 1; i < prims.size(); ++i)
    out.primitives.push_back(atom(prims[i], "primitive name"));
  for (size_t i = 1; i < dynamic.size(); ++i)
    out.dynamic_names.push_back(atom(dynamic[i], "dynamic relation name"));
  for (size_t i = 1; i < rules.size(); ++i)
    out.rules.push_back(decode_rule(rules[i]));
  for (size_t i = 1; i < meta.size(); ++i)
  {
    const auto& record = tagged(meta[i], "rule-meta", 3);
    const auto& rid = tagged(record[1], "rid", 2);
    const auto& source = tagged(record[2], "source", 2);
    const u32 id = medium(rid[1], "metadata rule id");
    const std::string& location = source[1].kind == SExp::K::string
      ? string_value(source[1], "source") : atom(source[1], "source");
    const auto [_, inserted] = out.sources.emplace(id, location);
    if (!inserted && out.sources[id] != location)
      syntax(meta[i], "conflicting source metadata for rule id");
  }
  return out;
}

DecodedKernelPlan parse_kernel_plan_file(const std::string& path)
{
  std::ifstream input(path, std::ios::binary | std::ios::ate);
  if (!input)
    throw PlanParseError(ParseErrorK::io, 0, "plan: cannot open " + path);
  const std::streamoff end = input.tellg();
  if (end < 0)
    throw PlanParseError(ParseErrorK::io, 0, "plan: cannot size " + path);
  if (static_cast<u64>(end) > plan_reader_limits.max_bytes)
    throw PlanParseError(ParseErrorK::limit, 0,
                         "plan: sidecar byte limit exceeded");
  std::string bytes(static_cast<size_t>(end), '\0');
  input.seekg(0);
  if (!bytes.empty() && !input.read(bytes.data(), end))
    throw PlanParseError(ParseErrorK::io, 0, "plan: cannot read " + path);
  return parse_kernel_plan(bytes);
}

u64 materialize_constant(Database& db, const ConstantPlan& constant)
{
  switch (constant.kind)
  {
    case ConstantK::integer:
    {
      const u64 value = db.encodeIntLiteral(constant.text, "plan-constant");
      if (value == slog_error)
        throw SealError(SealErrorK::capability,
                        "constant: integer cannot be materialized");
      return value;
    }
    case ConstantK::real:
    {
      size_t used = 0;
      double value;
      try { value = std::stod(constant.text, &used); }
      catch (...) {
        throw SealError(SealErrorK::capability,
                        "constant: malformed real literal");
      }
      if (used != constant.text.size())
        throw SealError(SealErrorK::capability,
                        "constant: malformed real literal");
      return float_encode(value);
    }
    case ConstantK::string:
      return db.encodeString(constant.text);
    case ConstantK::boolean:
      throw SealError(SealErrorK::capability,
                      "constant: boolean materialization is not admitted");
    case ConstantK::symbol:
      throw SealError(SealErrorK::capability,
                      "constant: symbolic materialization is not admitted");
    case ConstantK::compound:
      throw SealError(SealErrorK::capability,
                      "constant: compound materialization is not admitted");
  }
  throw SealError(SealErrorK::capability, "constant: unknown kind");
}

SealedKernelPlan seal_kernel_plan(const DecodedKernelPlan& decoded,
                                  Database* constant_store)
{
  seal_check(decoded.abi == 1, SealErrorK::abi,
             "plan: unsupported canonical ABI");
  // Counted-interp slices 1-3: the count flavor and all three maintenance
  // flavors are admitted; the sign is flavor-static (+1 maint1,
  // -1 maint3neg/maint4neg) and the dred distinction is the installer's.
  const bool counted = decoded.flavor == "count";
  const bool maint_positive = decoded.flavor == "maint1";
  const bool maint_negative = decoded.flavor == "maint3neg"
                           || decoded.flavor == "maint4neg";
  const bool maint = maint_positive || maint_negative;
  seal_check(decoded.flavor == "normal" || decoded.flavor == "delta"
               || counted || maint,
             SealErrorK::flavor,
             "plan: admitted flavors are normal, delta, count, maint1, "
             "maint3neg, and maint4neg");
  const FlavoredSeal flavor{counted, maint,
                            static_cast<s8>(maint_negative ? -1 : 1)};
  seal_check(decoded.attachment_count == decoded.attachments.size(),
             SealErrorK::capability,
             "plan: attachment table was not decoded completely");
  for (const AttachmentPlan& attachment : decoded.attachments)
  {
    seal_check(attachment.kind != AttachmentK::unsupported,
               SealErrorK::capability,
               "plan: unsupported attachment " + attachment.a);
    if (attachment.kind == AttachmentK::seqindex)
      seal_check(!attachment.columns.empty(), SealErrorK::capability,
                 "plan: seqindex attachment has no columns");
  }
  seal_check(std::is_sorted(decoded.primitives.begin(), decoded.primitives.end())
               && std::adjacent_find(decoded.primitives.begin(),
                                     decoded.primitives.end())
                    == decoded.primitives.end(),
             SealErrorK::capability,
             "plan: primitive table must be sorted and unique");
  for (const std::string& primitive : decoded.primitives)
    (void)resolve_primitive(primitive);

  std::vector<RelationShape> shapes;
  shapes.reserve(decoded.bindings.size());
  for (size_t i = 0; i < decoded.bindings.size(); ++i)
  {
    seal_check(decoded.bindings[i].slot == i, SealErrorK::relation_slot,
               "plan: relation binding slots are not dense");
    shapes.push_back(decoded.bindings[i].shape);
  }

  std::vector<RulePlan> plans;
  plans.reserve(decoded.rules.size());
  for (const DecodedRule& decoded_rule : decoded.rules)
  {
    seal_check(decoded_rule.unsupported.empty(), SealErrorK::capability,
               "plan: unsupported canonical form "
                 + (decoded_rule.unsupported.empty()
                      ? std::string("<unknown>")
                      : decoded_rule.unsupported.front()));
    RulePlan plan = decoded_rule.plan;
    if (flavor.flavored())
    {
      // Every flavored rule must carry its prov-keyed fold kind (the ABI-1
      // "/<kind>" variant suffix); the sinks fold it through the cnt_*
      // family.
      plan.fold_kind = variant_fold_kind(plan.variant);
      seal_check(plan.fold_kind == cnt_kind_nonrec
                   || plan.fold_kind == cnt_kind_rec,
                 SealErrorK::variant_identity,
                 "plan: flavored rule variant carries no fold kind: "
                   + plan.variant);
      // Plan-attribute 1 (counted-interp-contract.md): counted plans and
      // the negative maintenance flavors carry no semijoin filters,
      // enforced as a seal CHECK rather than trusted as a convention (a
      // stale sidecar can trip this; the compiler regenerates it with the
      // flavored artifacts).  maint1 keeps semijoin lookahead enabled at
      // planning: its FULL-only probe over-approximates both the full and
      // old (FULL-minus-delta) views, pruning only zero-instantiation
      // prefixes, so any exists op that appears executes verbatim.
      if (counted || maint_negative)
      {
        const auto no_exists = [](const FilterPlan& filter) {
          seal_check(filter.kind != FilterK::exists, SealErrorK::capability,
                     "plan: flavored plan carries a semijoin exists filter "
                     "(regenerate the flavored sidecar)");
        };
        for (const StraightPlan& op : plan.preops)
          if (const auto* filter = std::get_if<FilterPlan>(&op))
            no_exists(*filter);
        for (const BodyPlan& op : plan.body)
          if (const auto* filter = std::get_if<FilterPlan>(&op))
            no_exists(*filter);
      }
    }
    for (const auto& [reg, slot] : decoded_rule.constant_preloads)
    {
      seal_check(slot < decoded.constants.size(), SealErrorK::constant_slot,
                 "preload: constant slot out of range");
      seal_check(constant_store != nullptr, SealErrorK::capability,
                 "preload: constant store is required");
      plan.preloads.push_back(
        {reg, materialize_constant(*constant_store, decoded.constants[slot])});
    }
    u16 malformed_slot = std::numeric_limits<u16>::max();
    for (const RelationBinding& binding : decoded.bindings)
      if (binding.name == "malformed_deduction")
      {
        seal_check(malformed_slot == std::numeric_limits<u16>::max(),
                   SealErrorK::relation_slot,
                   "plan: duplicate malformed_deduction binding");
        malformed_slot = binding.slot;
      }
    const auto declared_primitive = [&](const std::string& name) {
      if (name.starts_with("$cjoin:")) return;
      seal_check(std::binary_search(decoded.primitives.begin(),
                                    decoded.primitives.end(), name),
                 SealErrorK::capability,
                 "plan: primitive is absent from declared table: " + name);
    };
    for (const StraightPlan& op : plan.preops)
      if (const auto* prim = std::get_if<PrimPlan>(&op))
        declared_primitive(prim->name);
    for (const BodyPlan& op : plan.body)
      if (const auto* prim = std::get_if<PrimPlan>(&op))
        declared_primitive(prim->name);
    for (HeadPrefixPlan& op : plan.head_prefix)
    {
      if (const auto* prim = std::get_if<PrimPlan>(&op))
        declared_primitive(prim->name);
      else if (auto* check = std::get_if<TycheckPlan>(&op))
        check->malformed_relation = malformed_slot;
    }
    plans.push_back(std::move(plan));
  }

  SealedKernelPlan out;
  out.abi = decoded.abi;
  out.flavor = decoded.flavor;
  out.bindings = decoded.bindings;
  out.rules = seal_rules(plans, shapes, flavor);
  out.sources = decoded.sources;
  out.dynamic_names = decoded.dynamic_names;
  out.attachments = decoded.attachments;
  for (SealedRule& rule : out.rules)
  {
    const auto source = out.sources.find(rule.program.rule_id);
    if (source != out.sources.end()) rule.program.source = source->second;
  }
  return out;
}

namespace
{

class DeltaDriver final : public DriverCursor
{
  Relation* relation;
  u16 bucket;
  u32 thread_count;
  u32 thread = 0;
  u32 row = 0;

public:
  DeltaDriver(Relation* rel, u16 b, u32 threads)
    : relation(rel), bucket(b), thread_count(threads) {}

  std::unique_ptr<DriverCursor> clone() const override
  {
    return std::make_unique<DeltaDriver>(*this);
  }

  bool next(std::vector<u64>& out) override
  {
    while (thread < thread_count)
    {
      RefVec& refs = relation->getReadBucket(thread, bucket);
      if (row < refs.size())
      {
        const TupleRef ref = refs[row++];
        // View-only staged rows (M4N pin 3) populate delta indices for
        // pre-state views; they never drive a read version.
        if (ref.batch->kind == cnt_kind_view) continue;
        const u64* tuple = ref.batch->data + ref.offset;
        out.assign(tuple, tuple + relation->getArity());
        return true;
      }
      ++thread;
      row = 0;
    }
    return false;
  }
};

template <u16 A>
class ProbeDriver final : public DriverCursor
{
  using Tree = BTreeIndex<A>;
  using Iter = typename Tree::iterator;

  std::array<u64, A> key{};
  u16 bound;
  u16 bucket;
  Tree* tree;
  Iter it, end;

public:
  ProbeDriver(Index** index, const std::vector<u64>& prefix,
              u16 k, u16 b)
    : bound(k), bucket(b)
  {
    for (u16 i = 0; i < bound; ++i) key[i] = prefix[i];
    tree = static_cast<Tree*>(index[buckethash(key[0])]);
    it = tree->lower_bound(key);
    end = tree->end();
  }

  std::unique_ptr<DriverCursor> clone() const override
  {
    return std::make_unique<ProbeDriver>(*this);
  }

  bool next(std::vector<u64>& out) override
  {
    while (it != end)
    {
      const auto& candidate = *it++;
      bool same = true;
      for (u16 i = 0; i < bound; ++i)
        if (candidate[i] != key[i]) { same = false; break; }
      if (!same) return false;
      if (bound < A && buckethash(candidate[bound]) != bucket) continue;
      out.assign(candidate.begin(), candidate.end());
      return true;
    }
    return false;
  }
};

template <u16 A>
class SetSink final : public BoundSink
{
  Relation* relation;
  Index** index;
  InsertBatch* batch = new InsertBatch();
  std::array<u16, A> order{};

public:
  SetSink(Relation* rel, Index** idx, const std::vector<u16>& ord)
    : relation(rel), index(idx)
  {
    std::copy(ord.begin(), ord.end(), order.begin());
  }

  ~SetSink() override { delete batch; }

  void stage(TupleView tuple) override
  {
    if (tuple.size() != A) fatal("interpreted sink arity mismatch");
    std::array<u64, A> values{};
    std::copy(tuple.begin(), tuple.end(), values.begin());
    emit<A>(relation, index, batch, values, order);
  }

  void flush() override
  {
    relation->sendBatch(batch);
    batch = new InsertBatch();
  }
};

template <u16 A>
class StructSink final : public BoundSink
{
  Relation* relation;
  Index** master;
  InsertBatch* batch = new InsertBatch();
  std::array<u16, A> order{};

public:
  StructSink(Relation* rel, const std::vector<u16>& ord, Index** master_index)
    : relation(rel), master(master_index)
  {
    std::copy(ord.begin(), ord.end(), order.begin());
  }

  ~StructSink() override { delete batch; }

  void stage(TupleView tuple) override
  {
    if (tuple.size() != A - 1)
      fatal("interpreted struct sink arity mismatch");
    std::array<u64, A - 1> fields{};
    std::copy(tuple.begin(), tuple.end(), fields.begin());
    if (master != nullptr)
      emit_struct_checked<A>(relation, master, batch, fields, order);
    else
      emit_struct<A>(relation, batch, fields, order);
  }

  void flush() override
  {
    relation->sendBatch(batch);
    batch = new InsertBatch();
  }
};

// View-aware body cursor.  It preserves the frozen positioned-until-next
// contract while implementing the exact native set-view definitions:
//   old = full - delta
//   new = full union (delta - full)
// A zero-width prefix walks all buckets; nonzero prefixes touch one bucket.
template <u16 A>
class ViewProbeCursor final : public PrefixCursor
{
  using Tree = BTreeIndex<A>;
  using Iter = typename Tree::iterator;
  enum class Phase : u8 { full, delta, done };

  Index** full;
  Index** delta;
  std::vector<u16> regs_map;
  u16 bound;
  ProbePlan::View view;
  std::array<u64, A> key{};
  Phase phase = Phase::done;
  u16 first_bucket = 0, last_bucket = 0, bucket = 0;
  Iter it, end;
  bool positioned = false;

  Index** active() const { return phase == Phase::full ? full : delta; }

  void open_bucket()
  {
    auto* tree = static_cast<Tree*>(active()[bucket]);
    it = bound == 0 ? tree->begin() : tree->lower_bound(key);
    end = tree->end();
  }

  void next_phase()
  {
    if (phase == Phase::full && view == ProbePlan::View::new_)
    {
      phase = Phase::delta;
      bucket = first_bucket;
      open_bucket();
    }
    else
      phase = Phase::done;
  }

  bool ensure_candidate()
  {
    while (phase != Phase::done && it == end)
    {
      ++bucket;
      if (bucket == last_bucket) next_phase();
      else open_bucket();
    }
    return phase != Phase::done;
  }

  bool same_prefix(const std::array<u64, A>& row) const
  {
    for (u16 i = 0; i < bound; ++i)
      if (row[i] != key[i]) return false;
    return true;
  }

  bool excluded(const std::array<u64, A>& row) const
  {
    if (view == ProbePlan::View::old)
      return static_cast<Tree*>(delta[buckethash(row[0])])->contains(row);
    return phase == Phase::delta
        && static_cast<Tree*>(full[buckethash(row[0])])->contains(row);
  }

public:
  ViewProbeCursor(Index** f, Index** d, std::vector<u16> regs,
                  u16 k, ProbePlan::View v)
    : full(f), delta(d), regs_map(std::move(regs)), bound(k), view(v) {}

  std::unique_ptr<PrefixCursor> clone() const override
  {
    return std::make_unique<ViewProbeCursor>(*this);
  }

  void open(const u64* regs) override
  {
    for (u16 i = 0; i < bound; ++i) key[i] = regs[regs_map[i]];
    for (u16 i = bound; i < A; ++i) key[i] = 0;
    first_bucket = bound == 0 ? 0 : buckethash(key[0]);
    last_bucket = bound == 0 ? bucket_count : first_bucket + 1;
    bucket = first_bucket;
    phase = Phase::full;
    positioned = false;
    open_bucket();
  }

  CursorResult next(u64* regs, WorkBudget& budget) override
  {
    if (positioned)
    {
      ++it;
      positioned = false;
    }
    while (ensure_candidate())
    {
      const auto& row = *it;
      if (!same_prefix(row))
      {
        next_phase();
        continue;
      }
      if (!budget.tick()) return CursorResult::paused;
      if (excluded(row))
      {
        ++it;
        continue;
      }
      for (u16 i = bound; i < A; ++i) regs[regs_map[i]] = row[i];
      positioned = true;
      return CursorResult::match;
    }
    return CursorResult::exhausted;
  }

  TupleView current() const override
  {
    return positioned ? TupleView{it->data(), A} : TupleView{};
  }
};

template <u16 A>
class SetFilterCursor final : public PrefixCursor
{
  using Tree = BTreeIndex<A>;

  Index** index;
  std::vector<u16> keyreg;
  u16 bound;
  FilterK kind;
  std::array<u64, A> key{};
  typename Tree::iterator it, end;
  bool allowed = false;
  bool completed = false;
  bool positioned = false;

public:
  SetFilterCursor(Index** i, std::vector<u16> regs, u16 k, FilterK filter_kind)
    : index(i), keyreg(std::move(regs)), bound(k), kind(filter_kind) {}

  std::unique_ptr<PrefixCursor> clone() const override
  {
    return std::make_unique<SetFilterCursor>(*this);
  }

  void open(const u64* regs) override
  {
    for (u16 i = 0; i < bound; ++i) key[i] = regs[keyreg[i]];
    for (u16 i = bound; i < A; ++i) key[i] = 0;
    bool present = false;
    if (bound == 0)
    {
      for (u16 bucket = 0; bucket < bucket_count && !present; ++bucket)
        present = !index[bucket]->empty();
    }
    else
    {
      auto* tree = static_cast<Tree*>(index[buckethash(key[0])]);
      it = tree->lower_bound(key);
      end = tree->end();
      if (it != end)
      {
        present = true;
        for (u16 i = 0; i < bound; ++i)
          if ((*it)[i] != key[i]) { present = false; break; }
      }
    }
    allowed = kind == FilterK::exists ? present : !present;
    completed = false;
    positioned = false;
  }

  CursorResult next(u64*, WorkBudget& budget) override
  {
    if (completed)
    {
      positioned = false;
      return CursorResult::exhausted;
    }
    if (!budget.tick()) return CursorResult::paused;
    completed = true;
    positioned = allowed;
    return allowed ? CursorResult::match : CursorResult::exhausted;
  }

  TupleView current() const override
  {
    return positioned && kind == FilterK::exists
      ? TupleView{it->data(), A} : TupleView{};
  }
};

// Arity-erased lattice payload-map cursor. A BTreeMapIndex stores the ordered
// key and merged payload separately; register writes read them in place, while
// current() assembles the physical key+payload proof row only when observation
// asks for it. Thus map erasure does not add an unobserved-path tuple copy.
template <u16 KA>
class MapCursor final : public PrefixCursor
{
  using Tree = BTreeMapIndex<KA>;
  using Key = std::array<u64, KA>;
  using Iter = typename Tree::iterator;

  Index** index;
  std::vector<u16> regs_map;
  u16 bound;
  bool absent_filter;
  Key key{};
  u16 first_bucket = 0, last_bucket = 0, bucket = 0;
  Iter it, end;
  bool allowed = false;
  bool completed = false;
  bool positioned = false;
  mutable std::array<u64, KA + 1> proof_row{};

  void open_bucket()
  {
    auto* tree = static_cast<Tree*>(index[bucket]);
    it = bound == 0 ? tree->begin() : tree->lower_bound(key);
    end = tree->end();
  }

  bool ensure_candidate()
  {
    while (it == end)
    {
      ++bucket;
      if (bucket == last_bucket) return false;
      open_bucket();
    }
    return true;
  }

  bool same_prefix(const Key& candidate) const
  {
    for (u16 i = 0; i < bound; ++i)
      if (candidate[i] != key[i]) return false;
    return true;
  }

public:
  MapCursor(Index** idx, std::vector<u16> regs, u16 k, bool filter)
    : index(idx), regs_map(std::move(regs)), bound(k), absent_filter(filter)
  {
    for (u16 bucket = 0; bucket < bucket_count; ++bucket)
      seal_check(dynamic_cast<Tree*>(index[bucket]) != nullptr,
                 SealErrorK::binding,
                 "bind: lattice ordering is not a payload-map index");
  }

  std::unique_ptr<PrefixCursor> clone() const override
  {
    return std::make_unique<MapCursor>(*this);
  }

  void open(const u64* regs) override
  {
    for (u16 i = 0; i < bound; ++i) key[i] = regs[regs_map[i]];
    for (u16 i = bound; i < KA; ++i) key[i] = 0;
    positioned = false;
    completed = false;
    if (absent_filter)
    {
      bool present = false;
      if (bound == 0)
      {
        for (u16 b = 0; b < bucket_count && !present; ++b)
          present = !index[b]->empty();
      }
      else
      {
        auto* tree = static_cast<Tree*>(index[buckethash(key[0])]);
        it = tree->lower_bound(key);
        end = tree->end();
        present = it != end && same_prefix(it->first);
      }
      allowed = !present;
      return;
    }

    first_bucket = bound == 0 ? 0 : buckethash(key[0]);
    last_bucket = bound == 0 ? bucket_count : first_bucket + 1;
    bucket = first_bucket;
    open_bucket();
  }

  CursorResult next(u64* regs, WorkBudget& budget) override
  {
    if (absent_filter)
    {
      if (completed)
      {
        positioned = false;
        return CursorResult::exhausted;
      }
      if (!budget.tick()) return CursorResult::paused;
      completed = true;
      positioned = allowed;
      return allowed ? CursorResult::match : CursorResult::exhausted;
    }

    if (positioned)
    {
      ++it;
      positioned = false;
    }
    while (ensure_candidate())
    {
      if (!same_prefix(it->first)) return CursorResult::exhausted;
      if (!budget.tick()) return CursorResult::paused;
      for (u16 i = bound; i < KA; ++i)
        regs[regs_map[i]] = it->first[i];
      regs[regs_map[KA]] = it->second;
      positioned = true;
      return CursorResult::match;
    }
    return CursorResult::exhausted;
  }

  TupleView current() const override
  {
    if (absent_filter || !positioned) return {};
    std::copy(it->first.begin(), it->first.end(), proof_row.begin());
    proof_row[KA] = it->second;
    return TupleView{proof_row.data(), KA + 1};
  }

  u16 premise_count() const override
  {
    return !absent_filter && positioned ? 1 : 0;
  }

  TupleView premise(u16 premise_index) const override
  {
    return premise_index == 0 ? current() : TupleView{};
  }
};

// Type-erased arm of the native Join3PrefixCursor. Each arm is instantiated
// independently by arity, avoiding a quadratic left-arity x right-arity
// factory. FULL/OLD/NEW is already-erased runtime data within that arm, so
// the daemon pays for one arity ladder rather than three while retaining the
// exact shared native seek semantics.
struct Join3ArmCursor
{
  virtual ~Join3ArmCursor() = default;
  virtual std::unique_ptr<Join3ArmCursor> clone() const = 0;
  virtual void open(const u64* regs) = 0;
  virtual bool valid() const = 0;
  virtual u64 value() const = 0;
  virtual void advance_past(u64 value) = 0;
  virtual void seek(u64 value) = 0;
  virtual TupleView current() const = 0;
};

template <u16 A>
class NativeJoin3Arm final : public Join3ArmCursor
{
  using Key = std::array<u64, A>;
  using Tree = BTreeIndex<A>;
  using Iter = typename Tree::iterator;

  Index** full_indices;
  Index** delta_indices;
  std::vector<u16> regs_map;
  ProbePlan::View view;
  Tree* full = nullptr;
  Tree* delta = nullptr;
  Key prefix{};
  Iter fit;
  Iter dit;
  bool fok = false;
  bool dok = false;

  bool same_prefix(const Key& row) const
  {
    for (u16 c = 0; c + 1 < A; ++c)
      if (row[c] != prefix[c]) return false;
    return true;
  }

  void normalize_full()
  {
    while (fit != full->end())
    {
      if (!same_prefix(*fit)) { fok = false; return; }
      if (view == ProbePlan::View::old && delta->contains(*fit))
      {
        ++fit;
        continue;
      }
      fok = true;
      return;
    }
    fok = false;
  }

  void normalize_delta()
  {
    dok = view == ProbePlan::View::new_
       && dit != delta->end() && same_prefix(*dit);
  }

public:
  NativeJoin3Arm(Index** f, Index** d, std::vector<u16> regs,
                 ProbePlan::View v)
    : full_indices(f), delta_indices(d), regs_map(std::move(regs)), view(v) {}

  std::unique_ptr<Join3ArmCursor> clone() const override
  {
    return std::make_unique<NativeJoin3Arm>(*this);
  }

  void open(const u64* regs) override
  {
    for (u16 i = 0; i + 1 < A; ++i) prefix[i] = regs[regs_map[i]];
    prefix[A - 1] = 0;
    const u16 bucket = buckethash(prefix[0]);
    full = static_cast<Tree*>(full_indices[bucket]);
    delta = static_cast<Tree*>(delta_indices[bucket]);
    fit = full->lower_bound(prefix);
    dit = view == ProbePlan::View::new_
      ? delta->lower_bound(prefix) : delta->end();
    normalize_full();
    normalize_delta();
  }

  bool valid() const override
  {
    return view == ProbePlan::View::new_ ? fok || dok : fok;
  }

  u64 value() const override
  {
    if (view == ProbePlan::View::new_)
    {
      if (!fok) return (*dit)[A - 1];
      if (!dok) return (*fit)[A - 1];
      return std::min((*fit)[A - 1], (*dit)[A - 1]);
    }
    return (*fit)[A - 1];
  }

  void advance_past(u64 current) override
  {
    if (fok && (*fit)[A - 1] == current)
    {
      ++fit;
      normalize_full();
    }
    if (view == ProbePlan::View::new_
        && dok && (*dit)[A - 1] == current)
    {
      ++dit;
      normalize_delta();
    }
  }

  void seek(u64 target) override
  {
    // Keep this byte-for-byte algorithmic shape aligned with the generated
    // Join3PrefixCursor: eight nearby steps, then a B-tree lower_bound for a
    // real gap. The view is runtime data here solely to avoid three full
    // template ladders in the daemon's erased factory.
    for (u16 step = 0; step < 8 && valid() && value() < target; ++step)
    {
      const u64 current = value();
      advance_past(current);
    }
    if (!valid() || value() >= target) return;

    Key key = prefix;
    key[A - 1] = target;
    if (fok && (*fit)[A - 1] < target)
    {
      fit = full->lower_bound(key);
      normalize_full();
    }
    if (view == ProbePlan::View::new_
        && dok && (*dit)[A - 1] < target)
    {
      dit = delta->lower_bound(key);
      normalize_delta();
    }
  }

  TupleView current() const override
  {
    if (!valid()) return {};
    const Key& row = view == ProbePlan::View::new_
      ? (!fok ? *dit : (!dok ? *fit
                             : ((*fit)[A - 1] <= (*dit)[A - 1]
                                  ? *fit : *dit)))
      : *fit;
    return TupleView{row.data(), A};
  }
};

class ErasedJoin3Cursor final : public PrefixCursor
{
  std::unique_ptr<Join3ArmCursor> left;
  std::unique_ptr<Join3ArmCursor> right;
  u16 cycle_reg;
  bool positioned = false;

public:
  ErasedJoin3Cursor(std::unique_ptr<Join3ArmCursor> l,
                    std::unique_ptr<Join3ArmCursor> r, u16 cycle)
    : left(std::move(l)), right(std::move(r)), cycle_reg(cycle) {}

  ErasedJoin3Cursor(const ErasedJoin3Cursor& other)
    : left(other.left->clone()), right(other.right->clone()),
      cycle_reg(other.cycle_reg), positioned(other.positioned) {}

  std::unique_ptr<PrefixCursor> clone() const override
  {
    return std::make_unique<ErasedJoin3Cursor>(*this);
  }

  void open(const u64* regs) override
  {
    left->open(regs);
    right->open(regs);
    positioned = false;
  }

  CursorResult next(u64* regs, WorkBudget& budget) override
  {
    if (positioned)
    {
      const u64 matched = left->value();
      left->advance_past(matched);
      right->advance_past(matched);
      positioned = false;
    }
    while (left->valid() && right->valid())
    {
      if (!budget.tick()) return CursorResult::paused;
      const u64 l = left->value();
      const u64 r = right->value();
      if (l < r) left->seek(r);
      else if (r < l) right->seek(l);
      else
      {
        regs[cycle_reg] = l;
        positioned = true;
        return CursorResult::match;
      }
    }
    return CursorResult::exhausted;
  }

  TupleView current() const override
  {
    return positioned ? left->current() : TupleView{};
  }

  u16 premise_count() const override { return positioned ? 2 : 0; }
  TupleView premise(u16 index) const override
  {
    if (!positioned) return {};
    if (index == 0) return left->current();
    if (index == 1) return right->current();
    return {};
  }
};

template <u16 A>
std::unique_ptr<PrefixCursor> probe_cursor_ladder(
  u16 arity, Index** index, const std::vector<u16>& regs, u16 bound)
{
  if constexpr (A == 0)
  {
    (void)arity; (void)index; (void)regs; (void)bound;
    return nullptr;
  }
  else
  {
    if (arity == A)
      return std::make_unique<DynamicProbeCursor<A>>(
        index,
        std::vector<u16>(regs.begin(), regs.begin() + bound),
        std::vector<u16>(regs.begin() + bound, regs.end()));
    return probe_cursor_ladder<A - 1>(arity, index, regs, bound);
  }
}

template <u16 A>
std::unique_ptr<PrefixCursor> view_cursor_ladder(
  u16 arity, Index** full, Index** delta, const std::vector<u16>& regs,
  u16 bound, ProbePlan::View view)
{
  if constexpr (A == 0)
  {
    (void)arity; (void)full; (void)delta; (void)regs; (void)bound; (void)view;
    return nullptr;
  }
  else
  {
    if (arity == A)
      return std::make_unique<ViewProbeCursor<A>>(
        full, delta, regs, bound, view);
    return view_cursor_ladder<A - 1>(
      arity, full, delta, regs, bound, view);
  }
}

template <u16 A>
std::unique_ptr<PrefixCursor> filter_cursor_ladder(
  u16 arity, Index** index, const std::vector<u16>& regs,
  u16 bound, FilterK kind)
{
  if constexpr (A == 0)
  {
    (void)arity; (void)index; (void)regs; (void)bound; (void)kind;
    return nullptr;
  }
  else
  {
    if (arity == A)
      return std::make_unique<SetFilterCursor<A>>(index, regs, bound, kind);
    return filter_cursor_ladder<A - 1>(arity, index, regs, bound, kind);
  }
}

template <u16 KA>
std::unique_ptr<PrefixCursor> map_cursor_ladder(
  u16 arity, Index** index, const std::vector<u16>& regs,
  u16 bound, bool absent_filter)
{
  if constexpr (KA == 0)
  {
    (void)arity; (void)index; (void)regs; (void)bound;
    (void)absent_filter;
    return nullptr;
  }
  else
  {
    if (arity == KA + 1)
      return std::make_unique<MapCursor<KA>>(
        index, regs, bound, absent_filter);
    return map_cursor_ladder<KA - 1>(
      arity, index, regs, bound, absent_filter);
  }
}

template <u16 A>
std::unique_ptr<Join3ArmCursor> join3_arm_ladder(
  u16 arity, Index** full, Index** delta,
  const std::vector<u16>& regs, ProbePlan::View view)
{
  if constexpr (A < 2)
  {
    (void)arity; (void)full; (void)delta; (void)regs; (void)view;
    return nullptr;
  }
  else
  {
    if (arity == A)
      return std::make_unique<NativeJoin3Arm<A>>(
        full, view == ProbePlan::View::full ? full : delta, regs, view);
    return join3_arm_ladder<A - 1>(arity, full, delta, regs, view);
  }
}

template <u16 A>
std::unique_ptr<DriverCursor> probe_driver_ladder(
  u16 arity, Index** index, const std::vector<u64>& prefix,
  u16 bound, u16 bucket)
{
  if constexpr (A == 0)
  {
    (void)arity; (void)index; (void)prefix; (void)bound; (void)bucket;
    return nullptr;
  }
  else
  {
    if (arity == A)
      return std::make_unique<ProbeDriver<A>>(index, prefix, bound, bucket);
    return probe_driver_ladder<A - 1>(arity, index, prefix, bound, bucket);
  }
}

template <u16 A>
std::unique_ptr<BoundSink> set_sink_ladder(
  u16 arity, Relation* relation, Index** index,
  const std::vector<u16>& order)
{
  if constexpr (A == 0)
  {
    (void)arity; (void)relation; (void)index; (void)order;
    return nullptr;
  }
  else
  {
    if (arity == A)
      return std::make_unique<SetSink<A>>(relation, index, order);
    return set_sink_ladder<A - 1>(arity, relation, index, order);
  }
}

template <u16 A>
std::unique_ptr<BoundSink> struct_sink_ladder(
  u16 arity, Relation* relation, const std::vector<u16>& order,
  Index** master)
{
  if constexpr (A <= 1)
  {
    (void)arity; (void)relation; (void)order; (void)master;
    return nullptr;
  }
  else
  {
    if (arity == A)
      return std::make_unique<StructSink<A>>(relation, order, master);
    return struct_sink_ladder<A - 1>(arity, relation, order, master);
  }
}

} // namespace

std::unique_ptr<PrefixCursor> make_set_probe_cursor(
  u16 arity, Index** index, const std::vector<u16>& regs, u16 bound)
{
  if (!supports_set_probe(arity, bound) || regs.size() != arity)
    throw SealError(SealErrorK::factory,
                    "bind: cursor factory capability miss");
  auto result = probe_cursor_ladder<max_daemon_arity>(arity, index, regs, bound);
  if (!result) throw SealError(SealErrorK::factory,
                               "bind: cursor factory ladder miss");
  return result;
}

std::unique_ptr<PrefixCursor> make_set_view_cursor(
  u16 arity, Index** full, Index** delta,
  const std::vector<u16>& regs, u16 bound, ProbePlan::View view)
{
  if (!supports_view_probe(arity, bound) || regs.size() != arity
      || full == nullptr || delta == nullptr
      || view == ProbePlan::View::full)
    throw SealError(SealErrorK::factory,
                    "bind: view-cursor factory capability miss");
  auto result = view_cursor_ladder<max_daemon_arity>(
    arity, full, delta, regs, bound, view);
  if (!result) throw SealError(SealErrorK::factory,
                               "bind: view-cursor factory ladder miss");
  return result;
}

std::unique_ptr<PrefixCursor> make_set_filter_cursor(
  u16 arity, Index** index, const std::vector<u16>& regs,
  u16 bound, FilterK kind)
{
  if (!supports_set_filter(kind, arity, bound) || regs.size() != bound
      || index == nullptr)
    throw SealError(SealErrorK::factory,
                    "bind: filter-cursor factory capability miss");
  auto result = filter_cursor_ladder<max_daemon_arity>(
    arity, index, regs, bound, kind);
  if (!result) throw SealError(SealErrorK::factory,
                               "bind: filter-cursor factory ladder miss");
  return result;
}

std::unique_ptr<PrefixCursor> make_map_probe_cursor(
  u16 arity, Index** index, const std::vector<u16>& regs, u16 bound)
{
  if (!supports_map_probe(arity, bound) || regs.size() != arity
      || index == nullptr)
    throw SealError(SealErrorK::factory,
                    "bind: lattice probe factory capability miss");
  auto result = map_cursor_ladder<max_daemon_arity - 1>(
    arity, index, regs, bound, false);
  if (!result) throw SealError(SealErrorK::factory,
                               "bind: lattice probe factory ladder miss");
  return result;
}

std::unique_ptr<PrefixCursor> make_map_filter_cursor(
  u16 arity, Index** index, const std::vector<u16>& regs,
  u16 bound, FilterK kind)
{
  if (!supports_map_filter(kind, arity, bound) || regs.size() != bound
      || index == nullptr)
    throw SealError(SealErrorK::factory,
                    "bind: lattice filter factory capability miss");
  auto result = map_cursor_ladder<max_daemon_arity - 1>(
    arity, index, regs, bound, true);
  if (!result) throw SealError(SealErrorK::factory,
                               "bind: lattice filter factory ladder miss");
  return result;
}

std::unique_ptr<PrefixCursor> make_join3_cursor(
  u16 left_arity, Index** left_full, Index** left_delta,
  const std::vector<u16>& left_regs, ProbePlan::View left_view,
  u16 right_arity, Index** right_full, Index** right_delta,
  const std::vector<u16>& right_regs, ProbePlan::View right_view,
  u16 cycle_reg)
{
  const auto valid_view = [](ProbePlan::View view) {
    return view == ProbePlan::View::full || view == ProbePlan::View::old
        || view == ProbePlan::View::new_;
  };
  if (left_arity < 2 || right_arity < 2
      || !supports_join3_arm(left_arity, left_arity - 1)
      || !supports_join3_arm(right_arity, right_arity - 1)
      || !valid_view(left_view) || !valid_view(right_view)
      || left_regs.size() != left_arity
      || right_regs.size() != right_arity
      || left_full == nullptr || right_full == nullptr
      || (left_view != ProbePlan::View::full && left_delta == nullptr)
      || (right_view != ProbePlan::View::full && right_delta == nullptr))
    throw SealError(SealErrorK::factory,
                    "bind: join3 cursor factory capability miss");
  auto left = join3_arm_ladder<max_daemon_arity>(
    left_arity, left_full, left_delta, left_regs, left_view);
  auto right = join3_arm_ladder<max_daemon_arity>(
    right_arity, right_full, right_delta, right_regs, right_view);
  if (!left || !right)
    throw SealError(SealErrorK::factory,
                    "bind: join3 arm factory ladder miss");
  return std::make_unique<ErasedJoin3Cursor>(
    std::move(left), std::move(right), cycle_reg);
}

std::unique_ptr<DriverCursor> make_delta_driver(
  Relation* relation, u16 bucket, u32 thread_count)
{
  if (relation == nullptr || bucket >= bucket_count || thread_count == 0)
    throw SealError(SealErrorK::binding, "bind: invalid delta driver");
  return std::make_unique<DeltaDriver>(relation, bucket, thread_count);
}

std::unique_ptr<DriverCursor> make_set_probe_driver(
  u16 arity, Index** index, const std::vector<u64>& prefix,
  u16 bound, u16 bucket)
{
  if (!supports_set_probe_driver(arity, bound) || prefix.size() != bound
      || bucket >= bucket_count)
    throw SealError(SealErrorK::factory,
                    "bind: probe-driver factory capability miss");
  auto result = probe_driver_ladder<max_daemon_arity>(
    arity, index, prefix, bound, bucket);
  if (!result) throw SealError(SealErrorK::factory,
                               "bind: driver factory ladder miss");
  return result;
}

std::unique_ptr<BoundSink> make_set_sink(
  u16 arity, Relation* relation, Index** index,
  const std::vector<u16>& order)
{
  if (arity == 0 || arity > max_daemon_arity || relation == nullptr
      || order.size() != arity)
    throw SealError(SealErrorK::factory,
                    "bind: sink factory capability miss");
  auto result = set_sink_ladder<max_daemon_arity>(
    arity, relation, index, order);
  if (!result) throw SealError(SealErrorK::factory,
                               "bind: sink factory ladder miss");
  return result;
}

std::unique_ptr<BoundSink> make_struct_sink(
  u16 arity, Relation* relation, const std::vector<u16>& order,
  Index** master)
{
  if (arity < 2 || arity > max_daemon_arity || relation == nullptr
      || relation->getStructId() == 0 || order.size() != arity)
    throw SealError(SealErrorK::factory,
                    "bind: struct sink factory capability miss");
  auto result = struct_sink_ladder<max_daemon_arity>(
    arity, relation, order, master);
  if (!result) throw SealError(SealErrorK::factory,
                               "bind: struct sink factory ladder miss");
  return result;
}

std::vector<std::shared_ptr<BoundRule>> bind_kernel_plan(
  const SealedKernelPlan& plan, Database& db)
{
  std::vector<Relation*> frame(plan.bindings.size(), nullptr);
  for (size_t i = 0; i < plan.bindings.size(); ++i)
  {
    seal_check(plan.bindings[i].slot == i, SealErrorK::binding,
               "bind: relation binding slots are not dense");
    frame[i] = db.getRelation(plan.bindings[i].name);
  }

  std::vector<std::shared_ptr<BoundRule>> out;
  out.reserve(plan.rules.size());
  for (const SealedRule& rule : plan.rules)
    out.push_back(std::make_shared<BoundRule>(rule, frame, &db));
  return out;
}

} // namespace interp
} // namespace slog
