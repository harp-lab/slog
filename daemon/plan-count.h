/** Thread-0 counted-interpreter installer (counted-interp-contract.md).
 *
 * The two entry points the daemon dispatch uses to route a `_count` flavored
 * stratum through the sealed-plan interpreter instead of its native `.so`:
 * `install_count_stratum` mirrors the native counted plugin's effects
 * (relations/indices, CountTask/CountStructTask registration, VM read tasks,
 * read/dynamic manifests, push + continueRun), and `maybe_interp_count_plugin`
 * is the SLOG_COUNT_INTERP-gated hook run_plugin consults before dlopen.
 * Flavored sinks, the mkstruct resolution cursor, and the arity ladders live
 * in plan-count.cpp -- the thread-0 extension regions of the factory tables
 * (interp-core-contract.md, extension seams).
 */

#pragma once

#include "plan.h"

namespace slog
{

class Daemon;

namespace interp
{

// Install one sealed `(flavor count)` plan as a resident count-round stratum
// under `name` (the `<hash>_count` stem beginStratumDelta expects), then push
// and continue the run -- the exact effect sequence of the native flavored
// plugin's slog_plugin.
void install_count_stratum(Daemon* daemon, const std::string& name,
                           const SealedKernelPlan& plan);

// When SLOG_COUNT_INTERP is set and `path` is a `_count` flavored plugin,
// parse/seal/install its sidecar plan through the production reader and
// return true (the caller skips dlopen).  Any parse/seal/bind failure is a
// loud fatal: in differential routing a silent native fallback would
// invalidate the comparison.
bool maybe_interp_count_plugin(Daemon* daemon, const std::string& path);

} // namespace interp
} // namespace slog
