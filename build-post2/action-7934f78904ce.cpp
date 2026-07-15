
#include "../daemon/daemon.h"
#include <algorithm>
#include <string>
#include <utility>
#include <vector>

// action: (begin-segment freevar)
extern "C" void slog_plugin(slog::Daemon* d)
{
  d->beginSegment(std::vector<std::string>{"freevar"});
}
