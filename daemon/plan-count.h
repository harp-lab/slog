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
struct EntryMode;
struct NativeCodeDescriptor;   // daemon.h (T4 2c)

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

// RF1 slice 2: the cohort forms.  A runtime stratum is the SCHEDULING
// container and a kernel is the code unit, so one stratum is populated from
// every kernel of an ABI-2 cohort, in manifest order; the populate step is
// additive per kernel (relations, indices, write/intern tasks and reads all
// accumulate), which is what keeps the grouping exactly what it was while the
// compiled unit shrinks to the module-SCC.  The *_stratum entries above are
// now the single-kernel case of these.
void install_normal_cohort(Daemon* daemon, const std::string& name,
                           const std::vector<SealedKernelPlan>& kernels);
void install_count_cohort(Daemon* daemon, const std::string& name,
                          const std::vector<SealedKernelPlan>& kernels);
void install_maint_cohort(Daemon* daemon, const std::string& name,
                          const std::vector<SealedKernelPlan>& kernels);

// T0(b) command-builder installation.  The caller has already generation-
// gated `stratum-seal`; this path validates the explicit entry/flavor pair,
// installs through Daemon::installStratum, pushes the stratum, and deliberately
// does NOT continue it.  A false return means the entry state machine emitted
// the one typed refusal; structural/install failures remain SealError so the
// command dispatcher can preserve the D16 refusal class.
bool install_command_stratum(Daemon* daemon, const std::string& name,
                             const EntryMode& entry,
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

// T4 slice (2c): attach a name-free native artifact through its exported
// descriptor (daemon.h NativeCodeDescriptor).  The caller (run_plugin) has
// already dlopen'd the .so and resolved the `slog_code_descriptor` symbol;
// this derives the sibling .plan (first-dot stem + ".plan"), installs the
// cohort's declarations plan (the same mechanism as the interp path), builds
// each kernel's binding frame and loc/tag tables from the plan, validates
// the descriptor structurally (abi, kernel count, exec keys, rule counts,
// frame widths -- refusal, never a null dereference), calls the per-kernel
// attach factories, and pushes + continues.  Any failure is a loud fatal.
void attach_native_descriptor(Daemon* daemon, const std::string& path,
                              const NativeCodeDescriptor* desc);

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
                                        Relation* relation, bool dred,
                                        bool recursive);

} // namespace interp
} // namespace slog
