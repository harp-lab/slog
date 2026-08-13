/** RF2-B/RF3 sealed ProgramImage loading and catalog/activation projection.
 *
 * Program images are compiler artifacts, not live Database relations.  The
 * daemon owns immutable decoded mounts used by the RF2 catalog; RF3 may
 * cross-seal their embedded ABI-2 cohorts and materialize ordinary interpreted
 * tasks, while the mount itself remains read-only and outside save files.
 */

#pragma once

#include <cstdint>
#include <optional>
#include <stdexcept>
#include <string>
#include <vector>

namespace slog
{
namespace image
{

enum class ErrorK { io, parse, format, seal };

struct Error : std::runtime_error
{
  ErrorK error_kind;

  Error(ErrorK kind, const std::string& message)
    : std::runtime_error(message), error_kind(kind) {}

  ErrorK kind() const { return error_kind; }
};

const char* error_class(ErrorK kind);

struct Source
{
  std::uint32_t slot = 0;
  std::uint32_t module = 0;
  std::string path;
  std::string digest;
  std::uint32_t tokens = 0;
};

struct Rule
{
  std::uint32_t slot = 0;
  std::uint32_t source_id = 0;
  std::optional<std::uint32_t> module;
  std::optional<std::uint32_t> source;
  std::string origin;
  std::string fingerprint;
  std::string normalized;
  std::vector<std::string> heads;
  std::vector<std::string> positive;
  std::vector<std::string> negative;
  std::vector<std::string> negative_wildcard;
};

struct Kernel
{
  std::uint32_t slot = 0;
  std::uint32_t level = 0;
  std::vector<std::string> members;
};

struct Plan
{
  struct Kernel
  {
    std::uint32_t ordinal = 0;
    std::string exec_key;
    std::vector<std::string> members;
    bool prelude = false;
    std::uint32_t rules = 0;
  };

  std::uint32_t slot = 0;
  std::string digest;
  std::string datum;
  std::vector<Kernel> kernels;
};

struct ProgramImage
{
  std::string key;
  std::uint32_t format = 0;
  std::string compiler_key;
  std::uint32_t plan_abi = 0;
  std::string model_key;
  std::uint32_t root_module = 0;
  std::uint32_t declarations = 0;
  std::uint32_t modules = 0;
  std::vector<Source> sources;
  std::vector<Rule> rules;
  std::vector<Kernel> kernels;
  std::vector<Plan> plans;
};

ProgramImage load(const std::string& path);

} // namespace image
} // namespace slog
