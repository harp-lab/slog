/** T0 command-protocol S-expression reader (docs/t0-contract.md, slice (a))
 *
 * Line-framed S-expressions per decision D6 (docs/execution-tiers-impl.md):
 * one write-printed form per line over the existing line framing, no length
 * prefixes.  This header owns ONLY the reader and its wire-quoting inverse;
 * verb dispatch lives with the transport loops (slogd.cpp) and, from slice
 * (b), plan parse/seal lives in plan.h -- both reuse THIS reader, so it stays
 * small and dependency-light (std only, no daemon headers).
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2023-2026
 * Some rights reserved. See License.md for details.
 *
 ******************************/

#pragma once

#include <string>
#include <vector>

namespace slog {
namespace protocol {

// One parsed node: an atom (bare token), a quoted string (decoded), or a
// list.  Atoms keep their raw spelling -- numbers, booleans (#t/#f), and
// symbols are all atoms; the consumer interprets them (a command layer wants
// verbs as raw tokens, a plan parser wants typed accessors on top).
struct Sexp
{
  enum class Kind { Atom, String, List };
  Kind kind = Kind::Atom;
  std::string text;         // Atom: the raw token; String: decoded characters
  std::vector<Sexp> items;  // List: children, in order

  bool isAtom()   const { return kind == Kind::Atom; }
  bool isString() const { return kind == Kind::String; }
  bool isList()   const { return kind == Kind::List; }
  size_t size()   const { return items.size(); }
  const Sexp& operator[](size_t i) const { return items[i]; }
};

namespace detail {

inline void skipSpace(const char*& p, const char* end)
{
  while (p != end && (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n'))
    ++p;
}

// Recursive-descent over one node.  Nesting is capped: input arrives one
// line at a time, so a pathological all-'(' line must not turn into an
// unbounded recursion.
inline bool parseNode(const char*& p, const char* end, Sexp& out,
                      std::string& err, int depth)
{
  if (depth > 200) { err = "form nests deeper than 200"; return false; }
  skipSpace(p, end);
  if (p == end) { err = "unexpected end of line"; return false; }
  if (*p == ')') { err = "unexpected ')'"; return false; }

  if (*p == '(')
  {
    ++p;
    out.kind = Sexp::Kind::List;
    out.items.clear();
    for (;;)
    {
      skipSpace(p, end);
      if (p == end) { err = "unterminated list"; return false; }
      if (*p == ')') { ++p; return true; }
      out.items.emplace_back();
      if (!parseNode(p, end, out.items.back(), err, depth + 1)) return false;
    }
  }

  if (*p == '"')
  {
    ++p;
    out.kind = Sexp::Kind::String;
    out.text.clear();
    while (p != end && *p != '"')
    {
      char c = *p++;
      if (c == '\\')
      {
        if (p == end) { err = "unterminated string escape"; return false; }
        const char e = *p++;
        switch (e)
        {
          case 'n':  c = '\n'; break;
          case 't':  c = '\t'; break;
          case 'r':  c = '\r'; break;
          case '"': case '\\': c = e; break;
          default:
            err = std::string("unknown string escape '\\") + e + "'";
            return false;
        }
      }
      out.text.push_back(c);
    }
    if (p == end) { err = "unterminated string"; return false; }
    ++p;  // closing quote
    return true;
  }

  // A bare atom: everything up to whitespace or a structural character.
  out.kind = Sexp::Kind::Atom;
  out.text.clear();
  while (p != end && *p != ' ' && *p != '\t' && *p != '\r' && *p != '\n'
         && *p != '(' && *p != ')' && *p != '"')
    out.text.push_back(*p++);
  return true;  // non-empty: the guards above consumed nothing
}

}  // namespace detail

// Parse exactly ONE write-printed form from `line` (D6: one form per line).
// True on success; false with a one-line reason in `err` -- trailing content
// after the form is an error, so a client cannot smuggle a second command
// onto the same line.
inline bool parseLine(const std::string& line, Sexp& out, std::string& err)
{
  const char* p = line.data();
  const char* end = p + line.size();
  if (!detail::parseNode(p, end, out, err, 0)) return false;
  detail::skipSpace(p, end);
  if (p != end)
  {
    err = "trailing content after the form (one form per line)";
    return false;
  }
  return true;
}

// Quote a string for wire emission: the exact inverse of the reader's string
// decoding, so every payload field round-trips through a datum reader with
// no string splitting (docs/t0-contract.md, reply doctrine).
inline std::string quoteString(const std::string& s)
{
  std::string q;
  q.reserve(s.size() + 2);
  q.push_back('"');
  for (const char c : s)
    switch (c)
    {
      case '"':  q += "\\\""; break;
      case '\\': q += "\\\\"; break;
      case '\n': q += "\\n";  break;
      case '\t': q += "\\t";  break;
      case '\r': q += "\\r";  break;
      default:   q.push_back(c);
    }
  q.push_back('"');
  return q;
}

}  // namespace protocol
}  // namespace slog
