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

}  // namespace protocol
}  // namespace slog
