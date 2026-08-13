#include "program-image.h"

#include "sexp.h"

#include <openssl/sha.h>

#include <algorithm>
#include <charconv>
#include <cctype>
#include <fstream>
#include <functional>
#include <iterator>
#include <limits>
#include <map>
#include <set>
#include <sstream>
#include <tuple>
#include <unordered_map>

namespace slog
{
namespace image
{

using SExp = sexp::SExp;

namespace
{

constexpr sexp::Limits image_reader_limits{
  64 * 1024 * 1024,
  4 * 1024 * 1024,
  512
};

[[noreturn]] void fail(ErrorK kind, const SExp& x,
                       const std::string& message)
{
  throw Error(kind, "program image: byte " + std::to_string(x.offset)
                    + ": " + message);
}

const std::vector<SExp>& list(const SExp& x, const char* where)
{
  if (x.kind != SExp::K::list)
    fail(ErrorK::format, x, std::string(where) + ": expected list");
  return x.children;
}

const std::string& atom(const SExp& x, const char* where)
{
  if (x.kind != SExp::K::atom)
    fail(ErrorK::format, x, std::string(where) + ": expected atom");
  return x.text;
}

const std::string& string_value(const SExp& x, const char* where)
{
  if (x.kind != SExp::K::string)
    fail(ErrorK::format, x, std::string(where) + ": expected string");
  return x.text;
}

const std::vector<SExp>& tagged(const SExp& x, const char* tag,
                                size_t exact = std::numeric_limits<size_t>::max())
{
  const auto& xs = list(x, tag);
  if (xs.empty() || xs[0].kind != SExp::K::atom || xs[0].text != tag)
    fail(ErrorK::format, x, std::string("expected (") + tag + " ...)");
  if (exact != std::numeric_limits<size_t>::max() && xs.size() != exact)
    fail(ErrorK::format, x, std::string(tag) + ": wrong field count");
  return xs;
}

std::uint32_t natural(const SExp& x, const char* where)
{
  const std::string& text = atom(x, where);
  if (text.empty()
      || !std::all_of(text.begin(), text.end(), [](unsigned char c) {
           return std::isdigit(c);
         }))
    fail(ErrorK::format, x, std::string(where) + ": expected natural number");
  std::uint32_t out = 0;
  const auto parsed = std::from_chars(text.data(), text.data() + text.size(), out);
  if (parsed.ec != std::errc{} || parsed.ptr != text.data() + text.size())
    fail(ErrorK::format, x, std::string(where) + ": number out of range");
  return out;
}

std::optional<std::uint32_t> optional_ref(const SExp& x, const char* where)
{
  if (x.kind == SExp::K::atom && x.text == "#f") return std::nullopt;
  return natural(x, where);
}

void write_sexp(const SExp& x, std::string& out)
{
  switch (x.kind)
  {
    case SExp::K::atom:
      out += x.text;
      return;
    case SExp::K::string:
      out.push_back('"');
      for (const unsigned char c : x.text)
      {
        switch (c)
        {
          case '"':  out += "\\\""; break;
          case '\\': out += "\\\\"; break;
          case '\a': out += "\\a";  break;
          case '\b': out += "\\b";  break;
          case '\t': out += "\\t";  break;
          case '\n': out += "\\n";  break;
          case '\v': out += "\\v";  break;
          case '\f': out += "\\f";  break;
          case '\r': out += "\\r";  break;
          default: out.push_back(static_cast<char>(c)); break;
        }
      }
      out.push_back('"');
      return;
    case SExp::K::list:
      out.push_back('(');
      for (size_t i = 0; i < x.children.size(); ++i)
      {
        if (i != 0) out.push_back(' ');
        write_sexp(x.children[i], out);
      }
      out.push_back(')');
      return;
  }
}

std::string sexp_text(const SExp& x)
{
  std::string out;
  write_sexp(x, out);
  return out;
}

std::string sha256_hex(const std::string& bytes)
{
  unsigned char digest[SHA256_DIGEST_LENGTH];
  SHA256(reinterpret_cast<const unsigned char*>(bytes.data()), bytes.size(),
         digest);
  static constexpr char hex[] = "0123456789abcdef";
  std::string out(SHA256_DIGEST_LENGTH * 2, '0');
  for (size_t i = 0; i < SHA256_DIGEST_LENGTH; ++i)
  {
    out[i * 2] = hex[digest[i] >> 4];
    out[i * 2 + 1] = hex[digest[i] & 15];
  }
  return out;
}

bool digest_string(const std::string& value)
{
  return value.size() == SHA256_DIGEST_LENGTH * 2
      && std::all_of(value.begin(), value.end(), [](unsigned char c) {
           return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f');
         });
}

void require_digest(const std::string& value, const SExp& at,
                    const char* where)
{
  if (!digest_string(value))
    fail(ErrorK::format, at, std::string(where) + ": expected SHA-256 hex");
}

const std::vector<SExp>& root_field(const std::vector<SExp>& root,
                                    size_t index, const char* tag)
{
  if (index >= root.size())
    fail(ErrorK::format, root.front(), std::string("missing ") + tag + " field");
  return tagged(root[index], tag);
}

std::vector<std::string> atom_tail(const SExp& field, const char* tag)
{
  const auto& xs = tagged(field, tag);
  std::vector<std::string> out;
  out.reserve(xs.size() - 1);
  for (size_t i = 1; i < xs.size(); ++i) out.push_back(atom(xs[i], tag));
  return out;
}

const SExp* tagged_field(const SExp& form, const char* tag)
{
  if (form.kind != SExp::K::list) return nullptr;
  const SExp* found = nullptr;
  for (size_t i = 1; i < form.children.size(); ++i)
  {
    const SExp& field = form.children[i];
    if (field.kind == SExp::K::list && !field.children.empty()
        && field.children[0].kind == SExp::K::atom
        && field.children[0].text == tag)
    {
      if (found != nullptr)
        fail(ErrorK::format, field, std::string("duplicate ") + tag + " field");
      found = &field;
    }
  }
  return found;
}

struct Module
{
  std::optional<std::uint32_t> parent;
  std::uint32_t ordinal = 0;
  std::uint32_t entry_source = 0;
  std::vector<std::uint32_t> sources;
};

struct Dependency
{
  std::string from;
  std::string to;
  std::string kind;
  std::optional<std::uint32_t> rule;
};

SExp atom_sexp(const std::string& value)
{
  return {SExp::K::atom, 0, value, {}};
}

SExp string_sexp(const std::string& value)
{
  return {SExp::K::string, 0, value, {}};
}

SExp list_sexp(std::vector<SExp> values)
{
  SExp out;
  out.kind = SExp::K::list;
  out.children = std::move(values);
  return out;
}

bool canonical_atoms(const std::vector<std::string>& values)
{
  return std::is_sorted(values.begin(), values.end())
      && std::adjacent_find(values.begin(), values.end()) == values.end();
}

void check_dense(std::uint32_t actual, size_t expected, const SExp& at,
                 const char* what)
{
  if (actual != expected)
    fail(ErrorK::format, at, std::string(what) + " slots are not dense");
}

ProgramImage decode(const SExp& datum)
{
  const auto& root = tagged(datum, "program-image", 16);
  static constexpr const char* fields[] = {
    "state", "key", "format", "compiler-key", "plan-abi", "model-key",
    "root-module", "declarations", "modules", "sources", "rules",
    "dependencies", "components", "component-edges", "cohorts"
  };
  // The tag itself occupies root[0]; fields[0] begins at root[1].  Exact
  // field order makes the on-disk grammar closed and prevents ignored data.
  for (size_t i = 1; i < root.size(); ++i)
    tagged(root[i], fields[i - 1]);

  const auto& state = root_field(root, 1, "state");
  if (state.size() != 2 || atom(state[1], "image state") != "sealed")
    fail(ErrorK::format, root[1], "image state must be sealed");

  ProgramImage out;
  const auto& key = root_field(root, 2, "key");
  const auto& format = root_field(root, 3, "format");
  const auto& compiler = root_field(root, 4, "compiler-key");
  const auto& abi = root_field(root, 5, "plan-abi");
  const auto& model = root_field(root, 6, "model-key");
  const auto& root_module = root_field(root, 7, "root-module");
  if (key.size() != 2 || format.size() != 2 || compiler.size() != 2
      || abi.size() != 2 || model.size() != 2 || root_module.size() != 2)
    fail(ErrorK::format, datum, "scalar header field has wrong arity");
  out.key = string_value(key[1], "image key");
  out.format = natural(format[1], "image format");
  out.compiler_key = string_value(compiler[1], "compiler key");
  out.plan_abi = natural(abi[1], "Plan ABI");
  out.model_key = string_value(model[1], "model key");
  out.root_module = natural(root_module[1], "root module");
  require_digest(out.key, key[1], "image key");
  require_digest(out.model_key, model[1], "model key");
  if (out.format != 1)
    fail(ErrorK::format, format[1], "unsupported image format");
  if (out.plan_abi != 2)
    fail(ErrorK::format, abi[1], "unsupported Plan ABI");
  if (out.compiler_key.empty())
    fail(ErrorK::format, compiler[1], "compiler key is empty");

  // The outer key is SHA-256(write(program-image-content ...)).  Rebuild that
  // exact logical datum, independent of pretty-print whitespace in the file.
  SExp content = datum;
  content.children[0].text = "program-image-content";
  content.children.erase(content.children.begin() + 1,
                         content.children.begin() + 3);
  if (sha256_hex(sexp_text(content)) != out.key)
    fail(ErrorK::seal, key[1], "image key does not match sealed content");

  const auto& declaration_records = root_field(root, 8, "declarations");
  std::string previous_declaration;
  std::set<std::pair<std::string, std::string>> declaration_keys;
  for (size_t i = 1; i < declaration_records.size(); ++i)
  {
    const auto& record = tagged(declaration_records[i], "declaration", 5);
    check_dense(natural(record[1], "declaration slot"), i - 1,
                declaration_records[i], "declaration");
    const std::string& space = atom(record[2], "declaration namespace");
    const std::string& name = atom(record[3], "declaration name");
    if (space != "alias" && space != "relation" && space != "function")
      fail(ErrorK::format, record[2], "unknown declaration namespace");
    if (!declaration_keys.emplace(space, name).second)
      fail(ErrorK::format, declaration_records[i],
           "duplicate declaration key");
    const std::string declaration = sexp_text(list_sexp(
      {record[2], record[3], record[4]}));
    if (!previous_declaration.empty()
        && !(previous_declaration < declaration))
      fail(ErrorK::format, declaration_records[i],
           "declarations are not in canonical order");
    previous_declaration = declaration;
  }
  out.declarations = static_cast<std::uint32_t>(declaration_records.size() - 1);

  const auto& module_records = root_field(root, 9, "modules");
  std::vector<Module> modules;
  modules.reserve(module_records.size() - 1);
  for (size_t i = 1; i < module_records.size(); ++i)
  {
    const auto& record = tagged(module_records[i], "module", 9);
    check_dense(natural(record[1], "module slot"), i - 1,
                module_records[i], "module");
    const auto& parent = tagged(record[2], "parent", 2);
    const auto& ordinal = tagged(record[3], "ordinal", 2);
    const auto& entry = tagged(record[4], "entry-source", 2);
    tagged(record[5], "home");
    tagged(record[6], "lexical-path");
    tagged(record[7], "bindings");
    const auto& source_refs = tagged(record[8], "sources");
    Module module;
    module.parent = optional_ref(parent[1], "module parent");
    module.ordinal = natural(ordinal[1], "module ordinal");
    module.entry_source = natural(entry[1], "module entry source");
    for (size_t j = 1; j < source_refs.size(); ++j)
      module.sources.push_back(natural(source_refs[j], "module source"));
    if (module.sources.empty())
      fail(ErrorK::format, record[8], "module source closure is empty");
    modules.push_back(std::move(module));
  }
  out.modules = static_cast<std::uint32_t>(modules.size());
  if (modules.empty() || out.root_module >= modules.size())
    fail(ErrorK::format, root_module[1], "root module is out of range");
  for (size_t i = 0; i < modules.size(); ++i)
  {
    const Module& module = modules[i];
    if ((i == out.root_module) != !module.parent.has_value())
      fail(ErrorK::format, module_records[i + 1],
           "exactly the root module must have parent #f");
    if (module.parent && (*module.parent >= modules.size() || *module.parent >= i))
      fail(ErrorK::format, module_records[i + 1],
           "module parent must precede its child");
    if (i == out.root_module && module.ordinal != 0)
      fail(ErrorK::format, module_records[i + 1], "root ordinal must be zero");
  }
  std::map<std::uint32_t, std::vector<std::pair<std::uint32_t, std::uint32_t>>>
    children;
  for (size_t i = 0; i < modules.size(); ++i)
    if (modules[i].parent)
      children[*modules[i].parent].push_back(
        {modules[i].ordinal, static_cast<std::uint32_t>(i)});
  for (auto& [parent, entries] : children)
  {
    std::sort(entries.begin(), entries.end());
    for (size_t i = 0; i < entries.size(); ++i)
      if (entries[i].first != i)
        fail(ErrorK::format, module_records[parent + 1],
             "module child ordinals are not dense");
  }
  std::vector<std::uint32_t> preorder;
  std::function<void(std::uint32_t)> visit_module =
    [&](std::uint32_t slot) {
      preorder.push_back(slot);
      for (const auto& child : children[slot]) visit_module(child.second);
    };
  visit_module(out.root_module);
  for (size_t i = 0; i < preorder.size(); ++i)
    if (preorder[i] != i)
      fail(ErrorK::format, module_records[preorder[i] + 1],
           "module slots are not in canonical preorder");

  const auto& source_records = root_field(root, 10, "sources");
  out.sources.reserve(source_records.size() - 1);
  for (size_t i = 1; i < source_records.size(); ++i)
  {
    const auto& record = tagged(source_records[i], "source", 6);
    Source source;
    source.slot = natural(record[1], "source slot");
    check_dense(source.slot, i - 1, source_records[i], "source");
    const auto& module = tagged(record[2], "module", 2);
    const auto& path = tagged(record[3], "path", 2);
    const auto& digest = tagged(record[4], "digest", 2);
    const auto& tokens = tagged(record[5], "tokens");
    source.module = natural(module[1], "source module");
    source.path = string_value(path[1], "source path");
    source.digest = string_value(digest[1], "source digest");
    require_digest(source.digest, digest[1], "source digest");
    if (source.module >= modules.size())
      fail(ErrorK::format, module[1], "source module is out of range");
    SExp token_content;
    token_content.kind = SExp::K::list;
    token_content.children.push_back(
      {SExp::K::atom, record[5].offset, "source-tokens", {}});
    for (size_t j = 1; j < tokens.size(); ++j)
    {
      const auto& token = tagged(tokens[j], "token", 4);
      atom(token[1], "token kind");
      const auto& span = tagged(token[2], "span", 5);
      for (size_t k = 1; k < span.size(); ++k) natural(span[k], "token span");
      string_value(token[3], "token text");
      token_content.children.push_back(tokens[j]);
    }
    if (sha256_hex(sexp_text(token_content)) != source.digest)
      fail(ErrorK::seal, digest[1], "source token digest mismatch");
    source.tokens = static_cast<std::uint32_t>(tokens.size() - 1);
    out.sources.push_back(std::move(source));
  }
  for (size_t i = 0; i < modules.size(); ++i)
  {
    const Module& module = modules[i];
    if (module.entry_source >= out.sources.size()
        || std::find(module.sources.begin(), module.sources.end(),
                     module.entry_source) == module.sources.end())
      fail(ErrorK::format, module_records[i + 1],
           "module entry source is outside its source closure");
    for (std::uint32_t source : module.sources)
      if (source >= out.sources.size() || out.sources[source].module != i)
        fail(ErrorK::format, module_records[i + 1],
             "module source closure has a foreign or invalid source");
  }
  std::uint32_t expected_source = 0;
  for (const Module& module : modules)
    for (std::uint32_t source : module.sources)
      if (source != expected_source++)
        fail(ErrorK::format, source_records.front(),
             "source slots do not follow canonical module/source order");
  if (expected_source != out.sources.size())
    fail(ErrorK::format, source_records.front(),
         "module source closures do not cover every source");

  const auto& rule_records = root_field(root, 11, "rules");
  out.rules.reserve(rule_records.size() - 1);
  for (size_t i = 1; i < rule_records.size(); ++i)
  {
    const auto& record = tagged(rule_records[i], "rule", 12);
    Rule rule;
    rule.slot = natural(record[1], "rule slot");
    check_dense(rule.slot, i - 1, rule_records[i], "rule");
    const auto& source_id = tagged(record[2], "source-id", 2);
    const auto& module = tagged(record[3], "module", 2);
    const auto& source = tagged(record[4], "source", 2);
    const auto& origin = tagged(record[5], "origin", 2);
    const auto& fingerprint = tagged(record[6], "fingerprint", 2);
    const auto& normalized = tagged(record[7], "normalized", 2);
    rule.source_id = natural(source_id[1], "rule source id");
    rule.module = optional_ref(module[1], "rule module");
    rule.source = optional_ref(source[1], "rule source");
    rule.origin = sexp_text(origin[1]);
    rule.fingerprint = string_value(fingerprint[1], "rule fingerprint");
    rule.normalized = string_value(normalized[1], "normalized rule");
    require_digest(rule.fingerprint, fingerprint[1], "rule fingerprint");
    if (sha256_hex(rule.normalized) != rule.fingerprint)
      fail(ErrorK::seal, fingerprint[1], "rule fingerprint mismatch");
    if (rule.module.has_value() != rule.source.has_value())
      fail(ErrorK::format, record[3], "rule has a partial source binding");
    if (rule.module && (*rule.module >= modules.size()
                        || *rule.source >= out.sources.size()
                        || out.sources[*rule.source].module != *rule.module))
      fail(ErrorK::format, record[3], "rule source/module binding is invalid");
    rule.heads = atom_tail(record[8], "heads");
    rule.positive = atom_tail(record[9], "positive");
    rule.negative = atom_tail(record[10], "negative");
    rule.negative_wildcard = atom_tail(record[11], "negative-wildcard");
    if (rule.heads.empty())
      fail(ErrorK::format, record[8], "rule has no head relation");
    if (!canonical_atoms(rule.heads) || !canonical_atoms(rule.positive)
        || !canonical_atoms(rule.negative)
        || !canonical_atoms(rule.negative_wildcard))
      fail(ErrorK::format, record[8],
           "rule relation sets are not canonical");
    out.rules.push_back(std::move(rule));
  }
  for (size_t i = 1; i < out.rules.size(); ++i)
  {
    const Rule& previous = out.rules[i - 1];
    const Rule& current = out.rules[i];
    if (!(previous.normalized < current.normalized
          || (previous.normalized == current.normalized
              && previous.source_id < current.source_id)))
      fail(ErrorK::format, rule_records[i + 1],
           "rules are not in canonical semantic order");
  }

  const auto& component_records = root_field(root, 13, "components");
  std::unordered_map<std::string, std::uint32_t> component_of;
  out.kernels.reserve(component_records.size() - 1);
  for (size_t i = 1; i < component_records.size(); ++i)
  {
    const auto& record = tagged(component_records[i], "component", 4);
    Kernel kernel;
    kernel.slot = natural(record[1], "component slot");
    check_dense(kernel.slot, i - 1, component_records[i], "component");
    const auto& level = tagged(record[2], "level", 2);
    kernel.level = natural(level[1], "component level");
    kernel.members = atom_tail(record[3], "members");
    if (kernel.members.empty())
      fail(ErrorK::format, record[3], "component member set is empty");
    if (!std::is_sorted(kernel.members.begin(), kernel.members.end())
        || std::adjacent_find(kernel.members.begin(), kernel.members.end())
             != kernel.members.end())
      fail(ErrorK::format, record[3], "component members are not canonical");
    for (const std::string& member : kernel.members)
      if (!component_of.emplace(member, kernel.slot).second)
        fail(ErrorK::format, record[3], "relation belongs to two components");
    out.kernels.push_back(std::move(kernel));
  }
  for (size_t i = 1; i < out.kernels.size(); ++i)
    if (!std::lexicographical_compare(
          out.kernels[i - 1].members.begin(), out.kernels[i - 1].members.end(),
          out.kernels[i].members.begin(), out.kernels[i].members.end()))
      fail(ErrorK::format, component_records[i + 1],
           "components are not in canonical member order");

  const auto& dependency_records = root_field(root, 12, "dependencies");
  static const std::set<std::string> dependency_kinds{
    "positive", "negative", "negative-wildcard", "co-head", "derived",
    "oracle"
  };
  std::vector<Dependency> dependencies;
  std::set<std::tuple<std::string, std::string, std::string,
                      std::optional<std::uint32_t>>> dependency_set;
  for (size_t i = 1; i < dependency_records.size(); ++i)
  {
    const auto& record = tagged(dependency_records[i], "dependency", 5);
    const std::string& from = atom(record[1], "dependency source");
    const std::string& to = atom(record[2], "dependency destination");
    const std::string& kind = atom(record[3], "dependency kind");
    const auto rule = optional_ref(record[4], "dependency rule");
    if (!component_of.contains(from) || !component_of.contains(to))
      fail(ErrorK::format, dependency_records[i],
           "dependency endpoint is outside the component partition");
    if (!dependency_kinds.contains(kind))
      fail(ErrorK::format, record[3], "unknown dependency kind");
    if (((kind == "derived" || kind == "oracle")) != !rule.has_value())
      fail(ErrorK::format, record[4],
           "only side-channel dependencies may omit a rule slot");
    if (rule && *rule >= out.rules.size())
      fail(ErrorK::format, record[4], "dependency rule is out of range");
    if (rule)
    {
      const Rule& cause = out.rules[*rule];
      const auto has = [](const std::vector<std::string>& values,
                          const std::string& value) {
        return std::find(values.begin(), values.end(), value) != values.end();
      };
      const bool agrees =
          kind == "positive"
            ? has(cause.positive, from) && has(cause.heads, to)
          : kind == "negative"
            ? has(cause.negative, from)
                && !has(cause.negative_wildcard, from) && has(cause.heads, to)
          : kind == "negative-wildcard"
            ? has(cause.negative_wildcard, from) && has(cause.heads, to)
          : kind == "co-head"
            ? from != to && has(cause.heads, from) && has(cause.heads, to)
          : false;
      if (!agrees)
        fail(ErrorK::format, dependency_records[i],
             "dependency does not agree with its cause rule");
    }
    const auto identity = std::make_tuple(from, to, kind, rule);
    if (!dependency_set.insert(identity).second)
      fail(ErrorK::format, dependency_records[i], "duplicate dependency");
    dependencies.push_back({from, to, kind, rule});
  }
  for (size_t i = 1; i < dependencies.size(); ++i)
  {
    const Dependency& a = dependencies[i - 1];
    const Dependency& b = dependencies[i];
    if (!(std::tie(a.from, a.to, a.kind, a.rule)
          < std::tie(b.from, b.to, b.kind, b.rule)))
      fail(ErrorK::format, dependency_records[i + 1],
           "dependencies are not in canonical order");
  }

  // ProgramModel identity is semantic content, not a caller assertion.  The
  // outer image key only proves the bytes agree with themselves, so rebuild
  // the same normalized model datum as compiler/program-model.rkt.
  std::vector<SExp> normalized_rules{atom_sexp("rules")};
  for (const Rule& rule : out.rules)
    normalized_rules.push_back(string_sexp(rule.normalized));
  std::vector<std::tuple<std::string, std::string, std::string>> derived_pairs;
  for (const Dependency& dependency : dependencies)
    if (dependency.kind == "derived" || dependency.kind == "oracle")
      derived_pairs.push_back(
        {dependency.from, dependency.to, dependency.kind});
  std::sort(derived_pairs.begin(), derived_pairs.end(),
    [](const auto& left, const auto& right) {
      const auto edge_sexp = [](const auto& edge) {
        std::vector<SExp> fields{
          atom_sexp(std::get<0>(edge)), atom_sexp(std::get<1>(edge))};
        if (std::get<2>(edge) != "derived")
          fields.push_back(atom_sexp(std::get<2>(edge)));
        return list_sexp(std::move(fields));
      };
      return sexp_text(edge_sexp(left)) < sexp_text(edge_sexp(right));
    });
  std::vector<SExp> derived_edges{atom_sexp("derived-edges")};
  for (const auto& edge : derived_pairs)
  {
    std::vector<SExp> fields{
      atom_sexp(std::get<0>(edge)), atom_sexp(std::get<1>(edge))};
    if (std::get<2>(edge) != "derived")
      fields.push_back(atom_sexp(std::get<2>(edge)));
    derived_edges.push_back(list_sexp(std::move(fields)));
  }
  const SExp model_content = list_sexp({
    atom_sexp("program-model-v1"),
    list_sexp(std::move(normalized_rules)),
    list_sexp(std::move(derived_edges))
  });
  if (sha256_hex(sexp_text(model_content)) != out.model_key)
    fail(ErrorK::seal, model[1], "ProgramModel fingerprint mismatch");

  // Independently recompute the SCC partition.  The outer digest proves
  // content identity, not semantic truth: a party can hash malformed content,
  // so a read-only mount still verifies the graph it promises to expose.
  std::map<std::string, std::vector<std::string>> adjacency;
  for (const auto& item : component_of) adjacency[item.first] = {};
  for (const Dependency& dependency : dependencies)
    adjacency[dependency.from].push_back(dependency.to);
  for (auto& item : adjacency)
  {
    auto& targets = item.second;
    std::sort(targets.begin(), targets.end());
    targets.erase(std::unique(targets.begin(), targets.end()), targets.end());
  }
  std::map<std::string, std::uint32_t> index;
  std::map<std::string, std::uint32_t> lowlink;
  std::set<std::string> on_stack;
  std::vector<std::string> stack;
  std::uint32_t next_index = 0;
  std::vector<std::vector<std::string>> recomputed;
  std::function<void(const std::string&)> visit = [&](const std::string& node) {
    index[node] = next_index;
    lowlink[node] = next_index++;
    stack.push_back(node);
    on_stack.insert(node);
    for (const std::string& target : adjacency[node])
    {
      if (!index.contains(target))
      {
        visit(target);
        lowlink[node] = std::min(lowlink[node], lowlink[target]);
      }
      else if (on_stack.contains(target))
        lowlink[node] = std::min(lowlink[node], index[target]);
    }
    if (lowlink[node] != index[node]) return;
    std::vector<std::string> component;
    for (;;)
    {
      const std::string member = stack.back();
      stack.pop_back();
      on_stack.erase(member);
      component.push_back(member);
      if (member == node) break;
    }
    std::sort(component.begin(), component.end());
    recomputed.push_back(std::move(component));
  };
  for (const auto& item : adjacency)
    if (!index.contains(item.first)) visit(item.first);
  std::sort(recomputed.begin(), recomputed.end());
  std::vector<std::vector<std::string>> declared;
  for (const Kernel& kernel : out.kernels) declared.push_back(kernel.members);
  if (recomputed != declared)
    fail(ErrorK::format, component_records.front(),
         "component partition does not match the dependency graph");

  const auto& edge_records = root_field(root, 14, "component-edges");
  using ComponentPair = std::pair<std::uint32_t, std::uint32_t>;
  std::map<ComponentPair, std::set<std::string>> declared_edges;
  std::optional<ComponentPair> previous_component_pair;
  for (size_t i = 1; i < edge_records.size(); ++i)
  {
    const auto& record = tagged(edge_records[i], "component-edge");
    if (record.size() < 4)
      fail(ErrorK::format, edge_records[i], "component edge has no kind");
    const std::uint32_t from = natural(record[1], "component edge source");
    const std::uint32_t to = natural(record[2], "component edge destination");
    if (from >= out.kernels.size() || to >= out.kernels.size() || from == to)
      fail(ErrorK::format, edge_records[i], "component edge slot is invalid");
    const ComponentPair pair{from, to};
    if (previous_component_pair && !(*previous_component_pair < pair))
      fail(ErrorK::format, edge_records[i],
           "component edges are not in canonical numeric order");
    previous_component_pair = pair;
    std::set<std::string> kinds;
    std::string previous_kind;
    for (size_t j = 3; j < record.size(); ++j)
    {
      const std::string& kind = atom(record[j], "component edge kind");
      if (!dependency_kinds.contains(kind))
        fail(ErrorK::format, record[j], "unknown component edge kind");
      if (!previous_kind.empty() && !(previous_kind < kind))
        fail(ErrorK::format, record[j],
             "component edge kinds are not in canonical order");
      if (!kinds.insert(kind).second)
        fail(ErrorK::format, record[j], "duplicate component edge kind");
      previous_kind = kind;
    }
    if (!declared_edges.emplace(pair, std::move(kinds)).second)
      fail(ErrorK::format, edge_records[i], "duplicate component edge");
  }
  std::map<ComponentPair, std::set<std::string>> recomputed_edges;
  for (const Dependency& dependency : dependencies)
  {
    const std::uint32_t from = component_of.at(dependency.from);
    const std::uint32_t to = component_of.at(dependency.to);
    if (from != to) recomputed_edges[{from, to}].insert(dependency.kind);
  }
  if (declared_edges != recomputed_edges)
    fail(ErrorK::format, edge_records.front(),
         "component edges do not match dependencies");

  std::map<std::uint32_t, std::set<std::uint32_t>> predecessors;
  for (const auto& edge : declared_edges)
    predecessors[edge.first.second].insert(edge.first.first);
  std::map<std::uint32_t, std::uint32_t> levels;
  std::set<std::uint32_t> level_stack;
  std::function<std::uint32_t(std::uint32_t)> level_of =
    [&](std::uint32_t slot) -> std::uint32_t {
      const auto known = levels.find(slot);
      if (known != levels.end()) return known->second;
      if (!level_stack.insert(slot).second)
        fail(ErrorK::format, component_records[slot + 1],
             "component graph contains a cycle");
      std::uint32_t level = 0;
      for (std::uint32_t predecessor : predecessors[slot])
        level = std::max(level, level_of(predecessor) + 1);
      level_stack.erase(slot);
      levels[slot] = level;
      return level;
    };
  for (const Kernel& kernel : out.kernels)
    if (level_of(kernel.slot) != kernel.level)
      fail(ErrorK::format, component_records[kernel.slot + 1],
           "component level does not match condensation predecessors");

  const auto& cohort_records = root_field(root, 15, "cohorts");
  out.plans.reserve(cohort_records.size() - 1);
  for (size_t i = 1; i < cohort_records.size(); ++i)
  {
    const auto& record = tagged(cohort_records[i], "cohort", 4);
    Plan plan;
    plan.slot = natural(record[1], "cohort slot");
    check_dense(plan.slot, i - 1, cohort_records[i], "cohort");
    const auto& digest = tagged(record[2], "digest", 2);
    const auto& plan_field = tagged(record[3], "plan", 2);
    plan.digest = string_value(digest[1], "cohort digest");
    require_digest(plan.digest, digest[1], "cohort digest");
    plan.datum = sexp_text(plan_field[1]);
    if (sha256_hex(plan.datum) != plan.digest)
      fail(ErrorK::seal, digest[1], "cohort plan digest mismatch");
    const auto& cohort = tagged(plan_field[1], "kernel-cohort");
    bool abi_seen = false;
    for (size_t j = 1; j < cohort.size(); ++j)
      if (cohort[j].kind == SExp::K::list && !cohort[j].children.empty()
          && cohort[j].children[0].kind == SExp::K::atom
          && cohort[j].children[0].text == "abi")
      {
        const auto& plan_abi = tagged(cohort[j], "abi", 2);
        if (natural(plan_abi[1], "cohort Plan ABI") != out.plan_abi)
          fail(ErrorK::format, plan_abi[1], "cohort Plan ABI mismatch");
        abi_seen = true;
      }
    if (!abi_seen)
      fail(ErrorK::format, plan_field[1], "kernel cohort has no ABI field");

    // RF3's executable cross-seal starts here, while the parsed S-expression
    // is still available: retain the manifest's logical component membership
    // and independently verify that every claimed exec key hashes the exact
    // `(exec ...)` bytes it identifies.  The full operator grammar is decoded
    // and sealed by plan.cpp only when activation is requested.
    const SExp* manifest = tagged_field(plan_field[1], "manifest");
    if (manifest == nullptr)
      fail(ErrorK::format, plan_field[1], "kernel cohort has no manifest");
    const auto& manifest_fields = tagged(*manifest, "manifest");
    std::map<std::uint32_t, const SExp*> execs;
    for (size_t j = 1; j < cohort.size(); ++j)
    {
      const SExp& child = cohort[j];
      if (child.kind != SExp::K::list || child.children.empty()
          || child.children[0].kind != SExp::K::atom
          || child.children[0].text != "kernel")
        continue;
      const SExp* ord = tagged_field(child, "ord");
      const SExp* exec = tagged_field(child, "exec");
      if (ord == nullptr || exec == nullptr)
        fail(ErrorK::format, child, "cohort kernel requires ord and exec");
      const auto& ord_field = tagged(*ord, "ord", 2);
      const std::uint32_t ordinal = natural(ord_field[1], "kernel ordinal");
      if (!execs.emplace(ordinal, exec).second)
        fail(ErrorK::format, child, "duplicate cohort kernel ordinal");
    }
    plan.kernels.reserve(manifest_fields.size() - 1);
    for (size_t j = 1; j < manifest_fields.size(); ++j)
    {
      const auto& kernel = tagged(manifest_fields[j], "kernel");
      if (kernel.size() != 5 && kernel.size() != 6)
        fail(ErrorK::format, manifest_fields[j],
             "manifest kernel has wrong field count");
      const auto& ord = tagged(kernel[1], "ord", 2);
      const auto& exec_key = tagged(kernel[2], "key", 2);
      const auto& members = tagged(kernel[3], "members");
      Plan::Kernel decoded;
      size_t rules_index = 4;
      if (kernel.size() == 6)
      {
        const auto& prelude = tagged(kernel[4], "prelude", 2);
        if (atom(prelude[1], "prelude flag") != "#t")
          fail(ErrorK::format, prelude[1], "prelude flag must be #t");
        decoded.prelude = true;
        rules_index = 5;
      }
      const auto& rules = tagged(kernel[rules_index], "rules", 2);
      decoded.ordinal = natural(ord[1], "manifest kernel ordinal");
      check_dense(decoded.ordinal, j - 1, manifest_fields[j],
                  "manifest kernel");
      decoded.exec_key = string_value(exec_key[1], "kernel exec key");
      require_digest(decoded.exec_key, exec_key[1], "kernel exec key");
      decoded.rules = natural(rules[1], "manifest rule count");
      for (size_t k = 1; k < members.size(); ++k)
        decoded.members.push_back(atom(members[k], "kernel member"));
      if ((!decoded.prelude && decoded.members.empty())
          || (decoded.prelude && !decoded.members.empty())
          || !std::is_sorted(decoded.members.begin(), decoded.members.end())
          || std::adjacent_find(decoded.members.begin(), decoded.members.end())
               != decoded.members.end())
        fail(ErrorK::format, kernel[3],
             "manifest members disagree with prelude or are not canonical");
      const auto executable = execs.find(decoded.ordinal);
      if (executable == execs.end())
        fail(ErrorK::format, manifest_fields[j],
             "manifest kernel has no executable body");
      if (sha256_hex(sexp_text(*executable->second)) != decoded.exec_key)
        fail(ErrorK::seal, exec_key[1], "kernel exec key mismatch");
      const SExp* rule_section = tagged_field(*executable->second, "rules");
      if (rule_section == nullptr
          || tagged(*rule_section, "rules").size() - 1 != decoded.rules)
        fail(ErrorK::format, manifest_fields[j],
             "manifest rule count does not match executable body");
      plan.kernels.push_back(std::move(decoded));
    }
    if (execs.size() != plan.kernels.size())
      fail(ErrorK::format, plan_field[1],
           "cohort executable bodies do not match the manifest");
    out.plans.push_back(std::move(plan));
  }

  bool executable_manifest = false;
  std::vector<std::vector<std::string>> executable_components;
  for (const Plan& plan : out.plans)
    for (const Plan::Kernel& kernel : plan.kernels)
    {
      executable_manifest = true;
      if (!kernel.prelude) executable_components.push_back(kernel.members);
    }
  if (executable_manifest)
  {
    std::sort(executable_components.begin(), executable_components.end());
    std::vector<std::vector<std::string>> semantic_components;
    std::set<std::string> written_relations;
    for (const Rule& rule : out.rules)
      written_relations.insert(rule.heads.begin(), rule.heads.end());
    for (const Kernel& kernel : out.kernels)
      if (std::any_of(kernel.members.begin(), kernel.members.end(),
                      [&](const std::string& member) {
                        return written_relations.contains(member);
                      }))
        semantic_components.push_back(kernel.members);
    std::sort(semantic_components.begin(), semantic_components.end());
    if (executable_components != semantic_components)
      fail(ErrorK::format, root_field(root, 15, "cohorts").front(),
           "executable manifests do not match ProgramModel components");
  }

  return out;
}

} // namespace

const char* error_class(ErrorK kind)
{
  switch (kind)
  {
    case ErrorK::io:     return "image-io";
    case ErrorK::parse:  return "image-parse";
    case ErrorK::format: return "image-format";
    case ErrorK::seal:   return "image-seal";
  }
  return "image-error";
}

ProgramImage load(const std::string& path)
{
  std::ifstream input(path, std::ios::binary | std::ios::ate);
  if (!input)
    throw Error(ErrorK::io, "cannot open ProgramImage: " + path);
  const std::streampos end = input.tellg();
  if (end < 0)
    throw Error(ErrorK::io, "cannot size ProgramImage: " + path);
  if (static_cast<std::uint64_t>(end) > image_reader_limits.max_bytes)
    throw Error(ErrorK::parse, "ProgramImage exceeds the 64 MiB mount limit");
  input.seekg(0);
  std::string bytes((std::istreambuf_iterator<char>(input)),
                    std::istreambuf_iterator<char>());
  if (!input && !input.eof())
    throw Error(ErrorK::io, "cannot read ProgramImage: " + path);
  try
  {
    return decode(sexp::read_one(bytes, image_reader_limits));
  }
  catch (const sexp::ReaderError& error)
  {
    throw Error(ErrorK::parse, std::string("program image: ") + error.what());
  }
}

} // namespace image
} // namespace slog
