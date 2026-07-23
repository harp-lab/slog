/** T0 command-protocol reader adapter (docs/t0-contract.md, slice (a))
 *
 * Line-framed S-expressions per decision D6 (docs/execution-tiers-impl.md):
 * one write-printed form per line over the existing line framing, no length
 * prefixes.  There is ONE S-expression grammar in the daemon -- the bounded
 * reader in sexp.h/sexp.cpp shared with the plan and query-plan decoders
 * (t0-contract.md slice (b) as-built: "the future command dispatcher
 * consumes this same reader with its own limits rather than growing a
 * second grammar").  This header owns only the command layer's limits, the
 * line-entry wrapper, and the wire-quoting inverse; verb dispatch lives
 * with the transport loops (slogd.cpp).
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2023-2026
 * Some rights reserved. See License.md for details.
 *
 ******************************/

#pragma once

#include "sexp.h"

#include <string>

namespace slog {
namespace protocol {

// Command-layer limits: sized to the plan sidecar's (plan.cpp), not to
// today's tiny verbs, so a slice-(b) builder or Q1 (query ...) line that
// embeds a canonical plan payload unchanged can never be refused by the
// command framing while the standalone sidecar path would accept it.
constexpr sexp::Limits command_reader_limits{
  16 * 1024 * 1024,
  1 * 1024 * 1024,
  256
};

// Parse exactly ONE write-printed form from `line` (D6: one form per line).
// True on success; false with a one-line reason in `err`.  read_one already
// refuses trailing content after the form ("trailing value"), so a client
// cannot smuggle a second command onto the same line.
inline bool parseLine(const std::string& line, sexp::SExp& out,
                      std::string& err)
{
  try
  {
    out = sexp::read_one(line, command_reader_limits);
    return true;
  }
  catch (const sexp::ReaderError& e)
  {
    err = e.what();
    return false;
  }
}

// Quote a string for wire emission: an exact inverse of the shared reader's
// string decoding (it emits only escapes sexp.cpp decodes), so every payload
// field round-trips through a datum reader with no string splitting
// (docs/t0-contract.md, reply doctrine).
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

// T0 slice (d): the uniform pause record's cause grammar.  A cause is
// either (arbitrary) or a for-cause citation -- today's designed variant
// is (watch (key K) (relation "R") (kind size|delta|error)) -- and
// watches later ADD VARIANTS here, never a new message kind.  The
// validator is what the slice's tests drive: a watch citation must parse
// and render without changing the record's shape.
inline bool validatePauseCause(const sexp::SExp& cause, std::string& why)
{
  if (cause.kind != sexp::SExp::K::list || cause.children.empty()
      || cause.children[0].kind != sexp::SExp::K::atom
      || cause.children[0].text != "cause")
  { why = "expected (cause ...)"; return false; }
  if (cause.children.size() != 2
      || cause.children[1].kind != sexp::SExp::K::list
      || cause.children[1].children.empty()
      || cause.children[1].children[0].kind != sexp::SExp::K::atom)
  { why = "expected one variant payload"; return false; }
  const sexp::SExp& variant = cause.children[1];
  const std::string& tag = variant.children[0].text;
  if (tag == "arbitrary")
  {
    if (variant.children.size() != 1)
    { why = "(arbitrary) takes no fields"; return false; }
    return true;
  }
  if (tag == "watch")
  {
    bool have_key = false, have_rel = false, have_kind = false;
    for (size_t i = 1; i < variant.children.size(); ++i)
    {
      const sexp::SExp& field = variant.children[i];
      if (field.kind != sexp::SExp::K::list || field.children.size() != 2
          || field.children[0].kind != sexp::SExp::K::atom)
      { why = "watch fields are (key value) pairs"; return false; }
      const std::string& key = field.children[0].text;
      const sexp::SExp& val = field.children[1];
      if (key == "key" && val.kind == sexp::SExp::K::atom) have_key = true;
      else if (key == "relation" && val.kind == sexp::SExp::K::string)
        have_rel = true;
      else if (key == "kind" && val.kind == sexp::SExp::K::atom
               && (val.text == "size" || val.text == "delta"
                   || val.text == "error"))
        have_kind = true;
      else { why = "unknown watch field " + key; return false; }
    }
    if (!(have_key && have_rel && have_kind))
    { why = "watch citation needs (key K) (relation \"R\") (kind size|delta|error)"; return false; }
    return true;
  }
  why = "unknown cause variant " + tag;
  return false;
}

// Validate a full uniform pause record (the message shape the command
// stack emits): (pause (class C) (cause V) (stratum "S") ...).  Field
// ORDER is part of the golden contract; unknown trailing fields are
// permitted so the record can grow without a message-kind change.
inline bool validatePauseRecord(const sexp::SExp& record, std::string& why)
{
  if (record.kind != sexp::SExp::K::list || record.children.empty()
      || record.children[0].kind != sexp::SExp::K::atom
      || record.children[0].text != "pause")
  { why = "expected (pause ...)"; return false; }
  if (record.children.size() < 3)
  { why = "pause record needs (class ...) and (cause ...)"; return false; }
  const sexp::SExp& cls = record.children[1];
  if (cls.kind != sexp::SExp::K::list || cls.children.size() != 2
      || cls.children[0].kind != sexp::SExp::K::atom
      || cls.children[0].text != "class"
      || cls.children[1].kind != sexp::SExp::K::atom
      || !(cls.children[1].text == "budget" || cls.children[1].text == "boundary"
           || cls.children[1].text == "suspension"
           || cls.children[1].text == "terminal"))
  { why = "expected (class budget|boundary|suspension|terminal)"; return false; }
  return validatePauseCause(record.children[2], why);
}

}  // namespace protocol
}  // namespace slog
