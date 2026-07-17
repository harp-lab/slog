/** Bounded S-expression reader shared by T0 command and plan decoders. */

#pragma once

#include <cstddef>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace slog
{
namespace sexp
{

struct Limits
{
  size_t max_bytes;
  size_t max_nodes;
  size_t max_depth;
};

enum class ReaderErrorK { syntax, limit };

struct ReaderError : std::runtime_error
{
  ReaderErrorK error_kind;
  size_t byte_offset;

  ReaderError(ReaderErrorK kind, size_t offset, const std::string& message)
    : std::runtime_error(message), error_kind(kind), byte_offset(offset) {}

  ReaderErrorK kind() const { return error_kind; }
  size_t offset() const { return byte_offset; }
};

struct SExp
{
  enum class K { atom, string, list } kind = K::atom;
  size_t offset = 0;
  std::string text;
  std::vector<SExp> children;
};

SExp read_one(std::string_view input, Limits limits);

} // namespace sexp
} // namespace slog
