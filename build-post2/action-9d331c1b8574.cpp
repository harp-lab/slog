
#include "../daemon/daemon.h"
#include <algorithm>
#include <string>
#include <utility>
#include <vector>

// action: (write-csv "out/test-shape_constguard")
extern "C" void slog_plugin(slog::Daemon* d)
{
  d->db()->writeDatabaseCSV("out/test-shape_constguard");
}
