
#include "../daemon/daemon.h"
#include <algorithm>
#include <string>
#include <utility>
#include <vector>

// action: (begin-segment $sup15869x25x0x0x0 $sup15869x25x0x0x1 $sup15869x33x0x0x0 error eval eval_ans malformed_deduction result store)
extern "C" void slog_plugin(slog::Daemon* d)
{
  d->beginSegment(std::vector<std::string>{"$sup15869x25x0x0x0", "$sup15869x25x0x0x1", "$sup15869x33x0x0x0", "error", "eval", "eval_ans", "malformed_deduction", "result", "store"});
}
