
#include "../daemon/daemon.h"
#include <algorithm>
#include <string>
#include <utility>
#include <vector>

// action: (import-path "build/frozen/b8e46c6243ad")
extern "C" void slog_plugin(slog::Daemon* d)
{
  d->importPath("build/frozen/b8e46c6243ad");
}
