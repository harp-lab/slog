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

#include <cstdint>
#include <cstdio>
#include <stdexcept>
#include <string>
#include <vector>

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

// T0(d)'s command-stack pause record. The legacy path stack keeps its frozen
// positional `(paused ...)` bytes; command-speaking sessions receive this
// keyed shape for every pause class. Future watches and breakpoints extend
// only PauseCause, never the outer record.
enum class PauseCauseKind
{
  budget,
  boundary,
  terminal,
  suspension,
  watch,
  breakpoint,
  error_watch
};

struct PauseCause
{
  PauseCauseKind kind = PauseCauseKind::budget;
  // budget: time|memory; boundary: requested; terminal: prepared;
  // suspension/breakpoint: a stable reason or id. Empty for watch variants.
  std::string detail;
  // Stable watch ids for watch/error-watch citations. They are quoted on the
  // wire, so future durable key spellings do not widen the command grammar.
  std::vector<std::string> citations;
};

struct PauseRecord
{
  std::uint64_t generation = 0;
  std::uint32_t scc = 0;
  std::string stratum;
  std::uint32_t iteration = 0;
  // read | iter | terminal
  std::string phase;
  // True only at a coherent iteration/terminal barrier. Mid-read progress is
  // explicitly inexact rather than masquerading as a finalized delta count.
  bool settled = false;
  std::uint64_t tuples = 0;
  bool progress_exact = false;
  double ms_call = 0;
  double ms_total = 0;
  PauseCause cause;
};

inline void validatePauseCause(const PauseCause& cause)
{
  const auto no_citations = [&] {
    if (!cause.citations.empty())
      throw std::invalid_argument("pause cause carries unexpected citations");
  };
  const auto cited = [&] {
    if (cause.detail.size() != 0 || cause.citations.empty())
      throw std::invalid_argument("watch pause cause requires citations only");
    for (const std::string& id : cause.citations)
      if (id.empty())
        throw std::invalid_argument("watch pause citation is empty");
  };
  switch (cause.kind)
  {
    case PauseCauseKind::budget:
      no_citations();
      if (cause.detail != "time" && cause.detail != "memory")
        throw std::invalid_argument("budget pause cause must be time or memory");
      break;
    case PauseCauseKind::boundary:
      no_citations();
      if (cause.detail != "requested")
        throw std::invalid_argument("boundary pause cause must be requested");
      break;
    case PauseCauseKind::terminal:
      no_citations();
      if (cause.detail != "prepared")
        throw std::invalid_argument("terminal pause cause must be prepared");
      break;
    case PauseCauseKind::suspension:
    case PauseCauseKind::breakpoint:
      no_citations();
      if (cause.detail.empty())
        throw std::invalid_argument("named pause cause requires a detail");
      break;
    case PauseCauseKind::watch:
    case PauseCauseKind::error_watch:
      cited();
      break;
  }
}

inline std::string renderPauseCause(const PauseCause& cause)
{
  validatePauseCause(cause);
  switch (cause.kind)
  {
    case PauseCauseKind::budget:
      return "(budget " + cause.detail + ")";
    case PauseCauseKind::boundary:
      return "(boundary requested)";
    case PauseCauseKind::terminal:
      return "(terminal prepared)";
    case PauseCauseKind::suspension:
      return "(suspension " + quoteString(cause.detail) + ")";
    case PauseCauseKind::breakpoint:
      return "(breakpoint " + quoteString(cause.detail) + ")";
    case PauseCauseKind::watch:
    case PauseCauseKind::error_watch:
    {
      std::string out = cause.kind == PauseCauseKind::watch
        ? "(watch" : "(error-watch";
      for (const std::string& id : cause.citations)
        out += " (watch-id " + quoteString(id) + ")";
      return out + ")";
    }
  }
  throw std::invalid_argument("unknown pause cause");
}

inline std::string renderPauseRecord(const PauseRecord& record)
{
  if (record.phase != "read" && record.phase != "iter"
      && record.phase != "terminal")
    throw std::invalid_argument("pause record carries an unknown phase");
  if (record.settled != record.progress_exact)
    throw std::invalid_argument("pause settled/exact fields disagree");
  if ((record.phase == "read") == record.settled)
    throw std::invalid_argument("pause phase/settled fields disagree");
  char timing[96];
  std::snprintf(timing, sizeof(timing),
                "(timing (call-ms %.3f) (total-ms %.3f))",
                record.ms_call, record.ms_total);
  return "(paused (generation " + std::to_string(record.generation) + ")"
    + " (scc " + std::to_string(record.scc) + ")"
    + " (stratum " + quoteString(record.stratum) + ")"
    + " (iteration " + std::to_string(record.iteration) + ")"
    + " (phase " + record.phase + ")"
    + " (settled " + (record.settled ? "#t" : "#f") + ")"
    + " (progress (tuples " + std::to_string(record.tuples) + ") (exact "
    + (record.progress_exact ? "#t" : "#f") + ")) " + timing
    + " (cause " + renderPauseCause(record.cause) + "))";
}

}  // namespace protocol
}  // namespace slog
