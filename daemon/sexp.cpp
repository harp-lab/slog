#include "sexp.h"

#include <cctype>

namespace slog
{
namespace sexp
{

namespace
{

class Reader
{
  std::string_view input;
  Limits limits;
  size_t pos = 0;
  size_t nodes = 0;

  [[noreturn]] void fail(ReaderErrorK kind, size_t at,
                         const std::string& message) const
  {
    throw ReaderError(kind, at, "S-expression: byte " + std::to_string(at)
                                  + ": " + message);
  }

  void count_node(size_t at)
  {
    if (++nodes > limits.max_nodes)
      fail(ReaderErrorK::limit, at, "node limit exceeded");
  }

  void space()
  {
    for (;;)
    {
      while (pos < input.size()
             && std::isspace(static_cast<unsigned char>(input[pos]))) ++pos;
      if (pos == input.size() || input[pos] != ';') return;
      while (pos < input.size() && input[pos] != '\n') ++pos;
    }
  }

  SExp string()
  {
    const size_t at = pos++;
    SExp out;
    out.kind = SExp::K::string;
    out.offset = at;
    while (pos < input.size())
    {
      char c = input[pos++];
      if (c == '"') return out;
      if (c != '\\')
      {
        out.text.push_back(c);
        continue;
      }
      if (pos == input.size())
        fail(ReaderErrorK::syntax, at, "unterminated string escape");
      const char e = input[pos++];
      switch (e)
      {
        case '\\': out.text.push_back('\\'); break;
        case '"': out.text.push_back('"'); break;
        case 'a': out.text.push_back('\a'); break;
        case 'b': out.text.push_back('\b'); break;
        case 't': out.text.push_back('\t'); break;
        case 'n': out.text.push_back('\n'); break;
        case 'v': out.text.push_back('\v'); break;
        case 'f': out.text.push_back('\f'); break;
        case 'r': out.text.push_back('\r'); break;
        default:
          fail(ReaderErrorK::syntax, pos - 1,
               std::string("unsupported string escape \\") + e);
      }
    }
    fail(ReaderErrorK::syntax, at, "unterminated string");
  }

  SExp quoted_symbol()
  {
    const size_t at = pos++;
    SExp out;
    out.kind = SExp::K::atom;
    out.offset = at;
    while (pos < input.size())
    {
      char c = input[pos++];
      if (c == '|') return out;
      if (c == '\\')
      {
        if (pos == input.size())
          fail(ReaderErrorK::syntax, at, "unterminated quoted symbol");
        c = input[pos++];
      }
      out.text.push_back(c);
    }
    fail(ReaderErrorK::syntax, at, "unterminated quoted symbol");
  }

  SExp value(size_t depth)
  {
    space();
    if (pos == input.size())
      fail(ReaderErrorK::syntax, pos, "expected a value");
    if (depth > limits.max_depth)
      fail(ReaderErrorK::limit, pos, "nesting limit exceeded");
    count_node(pos);
    if (input[pos] == '"') return string();
    if (input[pos] == '|') return quoted_symbol();
    if (input[pos] == ')')
      fail(ReaderErrorK::syntax, pos, "unexpected closing parenthesis");
    if (input[pos] == '(')
    {
      const size_t at = pos++;
      SExp out;
      out.kind = SExp::K::list;
      out.offset = at;
      for (;;)
      {
        space();
        if (pos == input.size())
          fail(ReaderErrorK::syntax, at, "unterminated list");
        if (input[pos] == ')') { ++pos; return out; }
        out.children.push_back(value(depth + 1));
      }
    }

    const size_t at = pos;
    while (pos < input.size())
    {
      const unsigned char c = static_cast<unsigned char>(input[pos]);
      if (std::isspace(c) || c == '(' || c == ')' || c == ';') break;
      ++pos;
    }
    if (pos == at) fail(ReaderErrorK::syntax, at, "empty atom");
    return {SExp::K::atom, at, std::string(input.substr(at, pos - at)), {}};
  }

public:
  Reader(std::string_view source, Limits reader_limits)
    : input(source), limits(reader_limits)
  {
    if (input.size() > limits.max_bytes)
      fail(ReaderErrorK::limit, 0, "byte limit exceeded");
  }

  SExp one()
  {
    SExp out = value(0);
    space();
    if (pos != input.size())
      fail(ReaderErrorK::syntax, pos, "trailing value");
    return out;
  }
};

} // namespace

SExp read_one(std::string_view input, Limits limits)
{
  return Reader(input, limits).one();
}

} // namespace sexp
} // namespace slog
