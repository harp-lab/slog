
#include "../daemon/daemon.h"
#include <algorithm>
#include <string>
#include <utility>
#include <vector>

// action: (write-csv "out/test-prim_float")
extern "C" void slog_plugin(slog::Daemon* d)
{
  d->db()->writeDatabaseCSV("out/test-prim_float");
}
