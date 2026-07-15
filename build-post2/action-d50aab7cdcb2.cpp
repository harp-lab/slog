
#include "../daemon/daemon.h"
#include <algorithm>
#include <string>
#include <utility>
#include <vector>

// action: (begin-segment _enum ar eval fn kaddr kstore result ret store)
extern "C" void slog_plugin(slog::Daemon* d)
{
  d->beginSegment(std::vector<std::string>{"_enum", "ar", "eval", "fn", "kaddr", "kstore", "result", "ret", "store"});
}
