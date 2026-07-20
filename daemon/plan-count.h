/** Thread-0 counted-interpreter installer (counted-interp-contract.md).
 *
 * The two entry points the daemon dispatch uses to route a `_count` flavored
 * stratum through the sealed-plan interpreter instead of its native `.so`:
 * `install_count_stratum` mirrors the native counted plugin's effects
 * (relations/indices, CountTask/CountStructTask registration, VM read tasks,
 * read/dynamic manifests, push + continueRun), and `maybe_interp_count_plugin`
 * is the default-on hook run_plugin consults before dlopen
 * (SLOG_FLAVORED_NATIVE restores the native artifact).
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

// Install one sealed maintenance plan (`maint1`/`maint3neg`/`maint4neg`) as
// a resident maintenance-epoch stratum: full write/intern machinery for
// non-maintained relations, serial Maintain*Task folds for the maintained
// heads (dred for maint4neg), and delta-driven interpreted reads over the
// staged signed transitions.
void install_maint_stratum(Daemon* daemon, const std::string& name,
                           const SealedKernelPlan& plan);

// Install one normal or delta-entry plan with declaration-built indices and
// write/intern/lattice tasks, then attach its interpreted read rules.
void install_normal_stratum(Daemon* daemon, const std::string& name,
                            const SealedKernelPlan& plan);

// When `path` is a flavored plugin whose flavor the interpreter admits,
// parse/seal/install its sidecar plan through the production reader and
// return true (the caller skips dlopen); under SLOG_FLAVORED_NATIVE it
// declines so the native artifact runs instead.  Any parse/seal/bind
// failure is a loud fatal: a silent native fallback would invalidate the
// dual-executor comparison.
bool maybe_interp_count_plugin(Daemon* daemon, const std::string& path);

// A compiler-driven normal/delta interpreter artifact is the `.plan` itself;
// intercept it before run_plugin's regular-file/dlopen path.
bool maybe_interp_plan_plugin(Daemon* daemon, const std::string& path);

// Registration ladders (plan-flavored-tasks.cpp, built -O0): the per-arity
// index/task boilerplate the native flavored plugins carry, driven from a
// sealed plan's structural facts.
void add_flavored_index(u16 arity, Relation* relation,
                        const std::vector<u16>& order, bool map, bool delta,
                        bool seeded_only = false);
void add_flavored_count_task(u16 arity, Database* db, Stratum* stratum,
                             Relation* relation, bool is_struct);
void add_flavored_write_task(u16 arity, Database* db, Stratum* stratum,
                             Relation* relation,
                             const std::vector<u16>& order, bool delta,
                             bool once_only);
void add_flavored_seeded_write_task(
  u16 arity, Database* db, Stratum* stratum, Relation* relation,
  const std::vector<u16>& order, bool delta);
void add_flavored_map_write_task(
  u16 arity, Database* db, Stratum* stratum, Relation* relation,
  const std::vector<u16>& order, Relation* decomp, bool decomp_map,
  bool once_only);
void add_flavored_intern_task(u16 arity, Database* db, Stratum* stratum,
                              Relation* relation,
                              const std::vector<u16>& order, bool is_struct);
void add_flavored_lattice_intern_task(
  u16 arity, Database* db, Stratum* stratum, Relation* relation,
  const std::vector<u16>& order, Relation* decomp, bool decomp_map);
void add_flavored_maintain_task(u16 arity, Database* db, Stratum* stratum,
                                Relation* relation,
                                const std::vector<u16>& order,
                                bool is_struct, bool dred);
void add_flavored_lattice_maintain_task(u16 arity, Database* db,
                                        Stratum* stratum,
                                        Relation* relation);

} // namespace interp
} // namespace slog
