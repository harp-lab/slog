// T0 slice (d): the cause-variant validator (docs/t0-contract.md).  A
// watch citation must parse and render as a CAUSE VARIANT of the one
// uniform pause record -- never a new message kind.  This drives
// protocol.h's validators over every class and both cause variants,
// including the refusal edges, and proves shape-stability: the record
// with a watch citation still begins (pause (class ...) (cause ...).

#include "protocol.h"

#include <cstdio>
#include <string>

using slog::sexp::SExp;

static SExp parse(const std::string& text)
{
  return slog::sexp::read_one(text, slog::protocol::command_reader_limits);
}

static int failures = 0;
static void check(bool ok, const char* what)
{
  if (!ok)
  {
    std::printf("FAIL %s\n", what);
    ++failures;
  }
}

int main()
{
  std::string why;

  // the arbitrary variant, every live and future class
  for (const char* cls : {"budget", "boundary", "suspension", "terminal"})
  {
    const std::string rec =
      std::string("(pause (class ") + cls + ") (cause (arbitrary)) "
      "(stratum \"s\") (scc 1) (iteration 2) (phase iter) "
      "(new-tuples 3) (slice-ms 1.0) (total-ms 2.0) (reason time))";
    SExp record = parse(rec);
    check(slog::protocol::validatePauseRecord(record, why),
          (std::string("arbitrary/") + cls + ": " + why).c_str());
  }

  // the watch citation: a cause VARIANT, not a message kind
  const std::string cited =
    "(pause (class terminal) "
    "(cause (watch (key 7) (relation \"edge\") (kind error))) "
    "(stratum \"s\") (scc 1) (iteration 2) (phase read) "
    "(new-tuples 0) (slice-ms 0.1) (total-ms 0.2) (reason time))";
  SExp record = parse(cited);
  check(slog::protocol::validatePauseRecord(record, why),
        (std::string("watch-citation: ") + why).c_str());
  // shape stability: the cited record is STILL a (pause (class ...) ...)
  check(record.children[0].text == "pause"
          && record.children[1].children[0].text == "class",
        "watch citation changed the message shape");

  // every watch kind admitted
  for (const char* kind : {"size", "delta", "error"})
  {
    const std::string rec =
      std::string("(pause (class budget) (cause (watch (key 1) "
                  "(relation \"r\") (kind ") + kind + "))))";
    SExp r = parse(rec);
    check(slog::protocol::validatePauseRecord(r, why),
          (std::string("watch-kind/") + kind + ": " + why).c_str());
  }

  // refusal edges
  const char* bad[] = {
    "(pause (class nap) (cause (arbitrary)))",                // unknown class
    "(pause (cause (arbitrary)) (class budget))",             // order matters
    "(pause (class budget) (cause (arbitrary extra)))",       // arbitrary+field
    "(pause (class budget) (cause (whim)))",                  // unknown variant
    "(pause (class budget) (cause (watch (key 1))))",         // missing fields
    "(pause (class budget) (cause (watch (key 1) (relation \"r\") "
    "(kind vibe))))",                                         // unknown kind
  };
  for (const char* text : bad)
  {
    SExp r = parse(text);
    check(!slog::protocol::validatePauseRecord(r, why),
          (std::string("accepted invalid: ") + text).c_str());
  }

  if (failures == 0) std::printf("pause-record-validator: all checks passed\n");
  return failures == 0 ? 0 : 1;
}
