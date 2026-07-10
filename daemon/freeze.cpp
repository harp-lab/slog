/** slog-freeze: a fact stream on stdin -> a static .bin database on disk.
 *
 *     slog-freeze <out-db-dir> < stream
 *
 * The stream is pure DATA -- ground s-expression facts -- preceded by the
 * declarations the freezer needs to intern them.  It is the producer
 * contract for both the compiler's peeled ground rules (build/frozen/,
 * content-addressed) and external front ends dumping program IRs; it never
 * contains rules or variables.
 *
 *   ;; comments run to end of line
 *   (struct <name> <field-count>)     an interned constructor
 *   (table <name> <arity>)            a relation facts assert into
 *   (enum <name>)                     (<name>) abbreviates (_enum "<name>")
 *   (<name> <term> ...)               a fact: a table row, or a struct
 *                                     instance to intern (a ground ask)
 *
 *   term := int | float | "string" | [term ...] | (<struct> term ...)
 *           | (<enum>)
 *
 * Every value encodes through the SAME Database entry points the runtime
 * uses -- encodeIntLiteral / float_encode / encodeString / the sequence
 * kernels / import's struct-intern pattern -- so frozen values are
 * bit-compatible with rule-derived ones and merge by content
 * (importDatabaseBIN).  Strings admit exactly the escapes \\ \" \n \t \r;
 * the compiler-side emitter produces only these.
 */

#include "daemon.h"
#include "operators.h"

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

// Out-of-line runtime index factories: one definition per binary (slogd
// defines its own; plugins resolve slogd's through -rdynamic, but the
// freezer is a standalone executable).
namespace slog {
Index* makeIndex(u16 arity)
{
  if (arity == 0 || arity > max_daemon_arity)
    fatal("Relation arity beyond daemon-side index support ("
          + std::to_string(arity) + ")");
  return makeIndexRec<max_daemon_arity>(arity);
}
Index* makeMapIndex(u16 keyarity, u32 kind,
                    bool hf, u64 fw, bool hc, u64 cw,
                    const LatSpec* spec, CollectionArena* arena)
{
  if (keyarity == 0 || keyarity > max_daemon_arity)
    fatal("Lattice key arity beyond daemon-side index support ("
          + std::to_string(keyarity) + ")");
  return makeMapIndexRec<max_daemon_arity>(keyarity, kind, hf, fw, hc, cw,
                                           spec, arena);
}
}

namespace {

// ---------------------------------------------------------------------
// Tokenizer: parens, brackets, strings, atoms; ;; comments.

struct Tok
{
  enum Kind { LP, RP, LB, RB, ATOM, STR, END } kind;
  std::string text;
};

class Lexer
{
  std::istream& in;
  int line = 1;
  bool has_peek = false;
  Tok peeked;

  int get()
  {
    int c = in.get();
    if (c == '\n') ++line;
    return c;
  }

  Tok lex()
  {
    for (;;)
    {
      int c = get();
      if (c == EOF) return {Tok::END, ""};
      if (c == ' ' || c == '\t' || c == '\r' || c == '\n') continue;
      if (c == ';')
      {
        while (c != EOF && c != '\n') c = get();
        continue;
      }
      if (c == '(') return {Tok::LP, "("};
      if (c == ')') return {Tok::RP, ")"};
      if (c == '[') return {Tok::LB, "["};
      if (c == ']') return {Tok::RB, "]"};
      if (c == '"')
      {
        std::string s;
        for (;;)
        {
          c = get();
          if (c == EOF) die("unterminated string");
          if (c == '"') break;
          if (c == '\\')
          {
            int e = get();
            switch (e)
            {
              case '\\': s += '\\'; break;
              case '"':  s += '"';  break;
              case 'n':  s += '\n'; break;
              case 't':  s += '\t'; break;
              case 'r':  s += '\r'; break;
              default: die("unsupported string escape \\" +
                           std::string(1, (char)e));
            }
          }
          else s += (char)c;
        }
        return {Tok::STR, s};
      }
      std::string a(1, (char)c);
      for (;;)
      {
        int p = in.peek();
        if (p == EOF || p == ' ' || p == '\t' || p == '\r' || p == '\n' ||
            p == '(' || p == ')' || p == '[' || p == ']' || p == ';' ||
            p == '"')
          break;
        a += (char)get();
      }
      return {Tok::ATOM, a};
    }
  }

public:
  explicit Lexer(std::istream& s) : in(s) {}

  [[noreturn]] void die(const std::string& msg)
  {
    slog::fatal("slog-freeze: line " + std::to_string(line) + ": " + msg);
  }

  const Tok& peek()
  {
    if (!has_peek) { peeked = lex(); has_peek = true; }
    return peeked;
  }

  Tok next()
  {
    if (has_peek) { has_peek = false; return peeked; }
    return lex();
  }
};

// ---------------------------------------------------------------------
// Declarations and the freezer core.

enum class DeclKind { Struct, Table, Enum };
struct Decl
{
  DeclKind kind;
  u16 n;  // struct: field count; table: arity
};

class Freezer
{
  slog::Database db{1};
  Lexer lx;
  std::string out_dir;
  std::unordered_map<std::string, Decl> decls;
  // dest-side content-dedup per struct relation, exactly the key
  // InternStructTask and importDatabaseBIN dedup by
  std::unordered_map<slog::Relation*,
    std::unordered_map<std::vector<u64>, u64,
                       boost::hash<std::vector<u64>>>> content;
  u64 fact_count = 0;

  slog::Relation* declare(const std::string& name, DeclKind kind, u16 n)
  {
    auto it = decls.find(name);
    if (it != decls.end())
    {
      if (it->second.kind != kind || it->second.n != n)
        lx.die("conflicting redeclaration of " + name);
      return db.getRelation(name);
    }
    decls[name] = {kind, n};
    if (kind == DeclKind::Enum)
      return nullptr;
    if (kind == DeclKind::Struct)
      db.addStruct(name, n + 1);  // fields + id column
    else
      db.addRelation(name, n);
    slog::Relation* rel = db.getRelation(name);
    rel->ensureDefaultIndex();
    return rel;
  }

  // The freezer's only enum machinery: (name) with an enum decl interns
  // the _enum struct instance the compiler's desugar would.
  slog::Relation* enumRelation()
  {
    if (!decls.count("_enum"))
      declare("_enum", DeclKind::Struct, 1);
    return db.getRelation("_enum");
  }

  // Intern one struct instance by content (importDatabaseBIN's pattern:
  // dedup map, bucket-routed id from the bucket's allocator).
  u64 internStructRow(slog::Relation* dst, const std::vector<u64>& fields)
  {
    auto& cm = content[dst];
    auto hit = cm.find(fields);
    if (hit != cm.end())
      return hit->second;
    const u16 bucket = buckethash(fields[0]);
    u64* alloc = dst->getInternAlloc(bucket);
    const u64 idw = struct_encode(dst->getStructId(),
                                  (*alloc << bucket_bits) | bucket);
    ++(*alloc);
    u64 row[slog::max_daemon_arity + 1];
    row[0] = idw;
    for (size_t c = 0; c < fields.size(); ++c)
      row[c + 1] = fields[c];
    dst->insertTupleAllIndices(row);
    cm.emplace(fields, idw);
    return idw;
  }

  u64 atomWord(const std::string& a)
  {
    bool floaty = false;
    for (char c : a)
      if (c == '.' || c == 'e' || c == 'E') { floaty = true; break; }
    if (floaty)
    {
      size_t used = 0;
      double d;
      try { d = std::stod(a, &used); }
      catch (...) { lx.die("malformed number " + a); }
      if (used != a.size()) lx.die("malformed number " + a);
      return float_encode(d);
    }
    u64 w = db.encodeIntLiteral(a, "freeze");
    if (w == slog_error) lx.die("malformed integer " + a);
    return w;
  }

  // One ground term, from a just-consumed opening token.
  u64 term(Tok t)
  {
    switch (t.kind)
    {
      case Tok::STR:  return db.encodeString(t.text);
      case Tok::ATOM: return atomWord(t.text);
      case Tok::LB:
      {
        u64 l = _prim_lempty(&db);
        while (lx.peek().kind != Tok::RB)
        {
          if (lx.peek().kind == Tok::END) lx.die("unterminated [");
          l = _prim_lpush(&db, l, term(lx.next()));
        }
        lx.next();  // ]
        return l;
      }
      case Tok::LP:
      {
        Tok head = lx.next();
        if (head.kind != Tok::ATOM) lx.die("expected a constructor name");
        std::vector<u64> fields;
        while (lx.peek().kind != Tok::RP)
        {
          if (lx.peek().kind == Tok::END) lx.die("unterminated (");
          fields.push_back(term(lx.next()));
        }
        lx.next();  // )
        auto it = decls.find(head.text);
        if (it == decls.end())
          lx.die("undeclared constructor " + head.text);
        if (it->second.kind == DeclKind::Enum)
        {
          if (!fields.empty()) lx.die("enum " + head.text + " takes no fields");
          return internStructRow(enumRelation(),
                                 {db.encodeString(head.text)});
        }
        if (it->second.kind != DeclKind::Struct)
          lx.die(head.text + " is a table, not a constructor");
        if (fields.size() != it->second.n)
          lx.die("constructor " + head.text + " takes "
                 + std::to_string(it->second.n) + " fields, got "
                 + std::to_string(fields.size()));
        return internStructRow(db.getRelation(head.text), fields);
      }
      default:
        lx.die("unexpected token in term");
    }
  }

  void fact()
  {
    Tok head = lx.next();
    if (head.kind != Tok::ATOM) lx.die("expected a relation name");
    // declarations
    if (head.text == "struct" || head.text == "table" ||
        head.text == "enum")
    {
      Tok name = lx.next();
      if (name.kind != Tok::ATOM) lx.die("expected a name to declare");
      u16 n = 0;
      if (head.text != "enum")
      {
        Tok num = lx.next();
        if (num.kind != Tok::ATOM) lx.die("expected an arity");
        n = (u16)std::stoul(num.text);
        if (n == 0 || n >= slog::max_daemon_arity)
          lx.die("arity out of range for " + name.text);
      }
      if (lx.next().kind != Tok::RP) lx.die("malformed declaration");
      declare(name.text,
              head.text == "struct" ? DeclKind::Struct
              : head.text == "table" ? DeclKind::Table
                                     : DeclKind::Enum,
              n);
      return;
    }
    // a fact
    auto it = decls.find(head.text);
    if (it == decls.end())
      lx.die("undeclared relation " + head.text);
    std::vector<u64> cols;
    while (lx.peek().kind != Tok::RP)
    {
      if (lx.peek().kind == Tok::END) lx.die("unterminated fact");
      cols.push_back(term(lx.next()));
    }
    lx.next();  // )
    if (it->second.kind == DeclKind::Enum)
      lx.die("cannot assert into enum " + head.text);
    if (it->second.kind == DeclKind::Struct)
    {
      // a ground ask: intern the instance, id discarded
      if (cols.size() != it->second.n)
        lx.die("struct " + head.text + " takes "
               + std::to_string(it->second.n) + " fields, got "
               + std::to_string(cols.size()));
      internStructRow(db.getRelation(head.text), cols);
    }
    else
    {
      if (cols.size() != it->second.n)
        lx.die("relation " + head.text + " has arity "
               + std::to_string(it->second.n) + ", got "
               + std::to_string(cols.size()));
      u64 row[slog::max_daemon_arity + 1];
      for (size_t c = 0; c < cols.size(); ++c)
        row[c] = cols[c];
      db.getRelation(head.text)->insertTupleAllIndices(row);
    }
    ++fact_count;
  }

public:
  Freezer(std::istream& in, std::string out) : lx(in), out_dir(std::move(out)) {}

  int run()
  {
    for (;;)
    {
      Tok t = lx.next();
      if (t.kind == Tok::END) break;
      if (t.kind != Tok::LP) lx.die("expected ( at top level");
      fact();
    }
    db.writeDatabaseSerialBINDir(out_dir);
    std::cout << "(frozen " << fact_count << " " << out_dir << ")"
              << std::endl;
    return 0;
  }
};

}  // namespace

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cerr << "usage: slog-freeze <out-db-dir> < stream" << std::endl;
    return 2;
  }
  Freezer f(std::cin, argv[1]);
  return f.run();
}
