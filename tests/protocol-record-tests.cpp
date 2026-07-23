#include "protocol.h"

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace slog::protocol;

namespace
{

void print_checked(const PauseRecord& record)
{
  const std::string rendered = renderPauseRecord(record);
  slog::sexp::SExp parsed;
  std::string error;
  if (!parseLine(rendered, parsed, error))
    throw std::runtime_error("rendered pause record did not parse: " + error);
  if (parsed.children.empty() || parsed.children[0].text != "paused")
    throw std::runtime_error("rendered pause record has the wrong tag");
  std::cout << rendered << '\n';
}

} // namespace

int main()
{
  print_checked({9, 3, "alpha", 7, "read", false, 42, false,
                 1.25, 9.5,
                 {PauseCauseKind::budget, "time", {}}});
  print_checked({9, 3, "alpha", 8, "iter", true, 51, true,
                 0.5, 10.0,
                 {PauseCauseKind::boundary, "requested", {}}});
  print_checked({10, 4, "omega", 12, "terminal", true, 99, true,
                 2.0, 12.0,
                 {PauseCauseKind::terminal, "prepared", {}}});
  print_checked({10, 4, "omega", 11, "iter", true, 97, true,
                 1.0, 10.0,
                 {PauseCauseKind::watch, "", {"w2", "w5"}}});

  bool refused = false;
  try
  {
    (void)renderPauseCause({PauseCauseKind::watch, "", {}});
  }
  catch (const std::invalid_argument&)
  {
    refused = true;
  }
  if (!refused)
    throw std::runtime_error("empty watch citation was not refused");
  return 0;
}
