/** Slog SMT Oracle (docs/smt.md)
 *
 * The first Oracle instance (oracle.h): answers `extern smt (f formula) int`
 * demands by rendering the interned formula DAG to SMT-LIB 2 and running a
 * configured chain of solvers over it.  Answer codes: 0 unknown (timeout,
 * solver "unknown", crash, unserializable), 1 sat, 2 unsat; lib/smt.slog
 * translates codes to the verdict enum in-language.
 *
 * Vocabulary (lib/smt.slog): integer terms  (iv "x") (ic 5) (ladd/lsub/lmul
 * a b) (lite c a b);  formulas  (bv "p") (ltrue) (lfalse) (llt/lle/lgt/lge/
 * leq/lne a b) (land/lor/limplies f g) (lnot f), plus the path-condition
 * idiom (lall S)/(lany S): a canonical cset of formulas rendered as an n-ary
 * conjunction/disjunction.  Nullary members arrive as _enum constants (a
 * struct whose single field is the name string).  The emitted logic is
 * inferred: QF_LIA, or QF_NIA when two non-constant terms are multiplied.
 *
 * Rendering is DAG-aware: interned formulas are hash-consed DAGs, and a
 * naive tree print is exponential on shared subterms, so every compound node
 * is emitted once as (define-fun tN () Sort ...) in dependency (postorder)
 * order, with leaves inlined.  Variables are collected into declare-consts,
 * name-mangled per sort (i_x / b_x) so (iv "x") and (bv "x") cannot collide.
 *
 * Solver chain: SLOG_SMT_SOLVERS, e.g. "z3:500,cvc5:2000" (name:timeout_ms)
 * or the default "mock".  Real solvers run as one subprocess per query
 * speaking SMT-LIB 2 over pipes with a wall-clock kill (persistent solver
 * pools are a later optimization); a solver's sat/unsat wins, anything else
 * falls through to the next entry, an exhausted chain answers unknown.  The
 * mock backend answers at dispatch time by evaluating GROUND formulas
 * (variables => unknown) -- deterministic, no install needed, used by the
 * golden tests.
 *
 * Copyright (C) Thomas Gilray, et al., 2026
 * Some rights reserved. See License.md for details.
 *
 ******************************/

#pragma once

#include "oracle.h"

#include <csignal>
#include <cstring>
#include <fcntl.h>
#include <poll.h>
#include <sys/wait.h>
#include <unistd.h>

#include <map>
#include <optional>
#include <set>
#include <sstream>

namespace slog
{

// ---------------------------------------------------------------------------
// Struct-instance decoding (the writeStructCSV pattern, database.h): fetch a
// struct value's constructor name and field values through its relation's
// lookup (id-first) index.  Read-phase-safe: indices are immutable there.

inline bool smtStructFields(Database* db, u64 v,
                            std::string& name, std::vector<u64>& fields)
{
  Relation* rel = db->getStructById((u32)decode_struct_id(v));
  if (rel == nullptr) return false;
  name = rel->getName();
  const std::vector<u16>& ord = rel->getLookupIndex();   // leads with id (col 0)
  const u16 n = (u16)ord.size();
  Index* node = rel->getIndex(ord, false)[buckethash(v)];
  std::vector<u64> storage(n, 0);
  bool found = false;
  node->forEach([&](const u64* t)
  {
    if (t[0] == v && !found)
    {
      found = true;
      for (u16 i = 0; i < n; ++i)
        storage[ord[i]] = t[i];             // t is in index order
    }
  });
  if (!found) return false;
  fields.assign(storage.begin() + 1, storage.end());     // storage col 0 = id
  return true;
}

// ---------------------------------------------------------------------------
// The SMT-LIB 2 renderer.

enum SmtSort { SMT_INT, SMT_BOOL };

// The three query shapes one SmtOracle class serves (docs/smt.md §14/§15):
// verdict codes, satisfying models, unsat cores.
enum SmtMode { SMT_MODE_CHECK, SMT_MODE_MODEL, SMT_MODE_CORE };

struct SmtPrinter
{
  // A rendered node: its inline text (a literal/var name or the define-fun
  // alias), its sort, and whether it is a compile-time constant -- the
  // const bit feeds logic inference (a product of two non-constants makes
  // the query nonlinear).
  struct Node { std::string text; SmtSort sort; bool is_const; };

  Database* db;
  std::ostringstream defs;                   // define-funs, dependency order
  std::set<std::string> declares;            // rendered declare-const lines
  std::map<u64, Node> memo;
  // (mangled, original) variable names in first-render order -- the model
  // query's get-value list and the reverse map baked into the request as
  // `; slogvar` comments (solve() has no Database to unmangle with).
  std::vector<std::pair<std::string, std::string>> vars;
  std::set<std::string> vars_seen;
  u32 next_id = 0;
  bool saw_nonlinear = false;
  std::string err;

  explicit SmtPrinter(Database* _db) : db(_db) {}

  static std::string mangle(const char* prefix, const std::string& s)
  {
    std::string out = prefix;
    for (char c : s)
      out += (isalnum((unsigned char)c) || c == '_') ? c : '_';
    return out;
  }

  bool fail(const std::string& e) { if (err.empty()) err = e; return false; }

  static std::string intLit(s32 x)
  {
    return (x < 0) ? "(- " + std::to_string(-(s64)x) + ")" : std::to_string(x);
  }

  // Wrap a rendered compound body in a define-fun alias (one per distinct
  // node: linear output on hash-consed DAGs) and memoize.
  bool defineNode(u64 v, const std::string& body, SmtSort sort, bool is_const,
                  Node& out)
  {
    const std::string tname = "t" + std::to_string(next_id++);
    defs << "(define-fun " << tname << " () "
         << (sort == SMT_INT ? "Int" : "Bool") << " " << body << ")\n";
    out = Node{tname, sort, is_const};
    memo[v] = out;
    return true;
  }

  // Render one node; memoized so shared subterms emit one define-fun.
  bool render(u64 v, Node& out, u32 depth)
  {
    if (depth > 4096)
      return fail("formula nesting deeper than 4096");
    auto hit = memo.find(v);
    if (hit != memo.end())
    {
      out = hit->second;
      return true;
    }

    if (is_s32(v))     // a raw int reaching a term position (any-typed hole)
    {
      out = Node{intLit(s32_decode(v)), SMT_INT, true};
      memo[v] = out;
      return true;
    }
    if (!is_struct(v))
      return fail("non-struct, non-integer value in a formula");

    std::string name;
    std::vector<u64> fields;
    if (!smtStructFields(db, v, name, fields))
      return fail("dangling struct reference in a formula");

    // Leaves.
    if (name == "_enum" && fields.size() == 1 && is_str(fields[0]))
    {
      const std::string e = db->decodeString(fields[0]);
      if (e == "ltrue")       out = Node{"true", SMT_BOOL, true};
      else if (e == "lfalse") out = Node{"false", SMT_BOOL, true};
      else return fail("unknown constant (" + e + ") in a formula");
      memo[v] = out;
      return true;
    }
    if (name == "ic")
    {
      if (fields.size() != 1 || !is_s32(fields[0]))
        return fail("(ic ...) expects one integer field");
      out = Node{intLit(s32_decode(fields[0])), SMT_INT, true};
      memo[v] = out;
      return true;
    }
    if (name == "iv" || name == "bv")
    {
      if (fields.size() != 1 || !is_str(fields[0]))
        return fail("(" + name + " ...) expects one string field (the variable name)");
      const bool isInt = (name == "iv");
      const std::string orig = db->decodeString(fields[0]);
      const std::string vn = mangle(isInt ? "i_" : "b_", orig);
      declares.insert("(declare-const " + vn + (isInt ? " Int)" : " Bool)"));
      if (vars_seen.insert(vn).second)
        vars.emplace_back(vn, orig);
      out = Node{vn, isInt ? SMT_INT : SMT_BOOL, false};
      memo[v] = out;
      return true;
    }

    // (lite c a b): ITE on integer terms -- per-position sorts.
    if (name == "lite")
    {
      if (fields.size() != 3)
        return fail("(lite ...) expects three fields (condition, then, else)");
      Node c, a, b;
      if (!render(fields[0], c, depth + 1) || !render(fields[1], a, depth + 1)
          || !render(fields[2], b, depth + 1))
        return false;
      if (c.sort != SMT_BOOL || a.sort != SMT_INT || b.sort != SMT_INT)
        return fail("ill-sorted argument of (lite ...)");
      return defineNode(v, "(ite " + c.text + " " + a.text + " " + b.text + ")",
                        SMT_INT, c.is_const && a.is_const && b.is_const, out);
    }

    // (lall S) / (lany S): S is a canonical cset of formulas, rendered as an
    // n-ary conjunction/disjunction.  This is THE path-condition idiom
    // (docs/smt.md §3.3): sets are order-insensitive and deduped, so one
    // semantic condition is one interned query however it was accumulated.
    // Arena in-order traversal is content-determined => deterministic text.
    if (name == "lall" || name == "lany")
    {
      const bool conj = (name == "lall");
      if (fields.size() != 1 || !is_cnode(fields[0]))
        return fail("(" + name + " ...) expects one collection field (a set of formulas)");
      std::vector<std::string> members;
      bool all_const = true;
      bool ok = true;
      db->collections()->foreach(fields[0], [&](u64 k, u64 val)
      {
        if (!ok) return;
        if (val != s32_encode(1))
        {
          ok = fail("(" + name + " ...) expects a SET (built with cins/braces), not a map");
          return;
        }
        Node m;
        if (!render(k, m, depth + 1)) { ok = false; return; }
        if (m.sort != SMT_BOOL)
        {
          ok = fail("non-boolean member of (" + name + " ...)");
          return;
        }
        members.push_back(m.text);
        all_const = all_const && m.is_const;
      });
      if (!ok) return false;
      if (members.empty())      // vacuous: empty conjunction/disjunction
      {
        out = Node{conj ? "true" : "false", SMT_BOOL, true};
        memo[v] = out;
        return true;
      }
      std::string body;
      if (members.size() == 1)
        body = members[0];
      else
      {
        body = conj ? "(and" : "(or";
        for (const std::string& m : members) body += " " + m;
        body += ")";
      }
      return defineNode(v, body, SMT_BOOL, all_const, out);
    }

    // Compound operators: (smt-lib symbol, argument sort, result sort, arity).
    struct Op { const char* sym; SmtSort arg; SmtSort res; u16 arity; };
    static const std::map<std::string, Op> ops = {
      {"ladd",     {"+",        SMT_INT,  SMT_INT,  2}},
      {"lsub",     {"-",        SMT_INT,  SMT_INT,  2}},
      {"lmul",     {"*",        SMT_INT,  SMT_INT,  2}},
      {"llt",      {"<",        SMT_INT,  SMT_BOOL, 2}},
      {"lle",      {"<=",       SMT_INT,  SMT_BOOL, 2}},
      {"lgt",      {">",        SMT_INT,  SMT_BOOL, 2}},
      {"lge",      {">=",       SMT_INT,  SMT_BOOL, 2}},
      {"leq",      {"=",        SMT_INT,  SMT_BOOL, 2}},
      {"lne",      {"distinct", SMT_INT,  SMT_BOOL, 2}},
      {"land",     {"and",      SMT_BOOL, SMT_BOOL, 2}},
      {"lor",      {"or",       SMT_BOOL, SMT_BOOL, 2}},
      {"limplies", {"=>",       SMT_BOOL, SMT_BOOL, 2}},
      {"lnot",     {"not",      SMT_BOOL, SMT_BOOL, 1}},
    };
    auto oit = ops.find(name);
    if (oit == ops.end())
      return fail("unknown formula constructor (" + name + " ...)");
    const Op& op = oit->second;
    if (fields.size() != op.arity)
      return fail("(" + name + " ...) expects " + std::to_string(op.arity) + " fields");

    std::string body = "(";
    body += op.sym;
    std::vector<Node> args;
    for (u64 f : fields)
    {
      Node sub;
      if (!render(f, sub, depth + 1)) return false;
      if (sub.sort != op.arg)
        return fail("ill-sorted argument of (" + name + " ...)");
      body += " " + sub.text;
      args.push_back(sub);
    }
    body += ")";

    // A product of two non-constant terms leaves linear arithmetic.
    if (name == "lmul" && !args[0].is_const && !args[1].is_const)
      saw_nonlinear = true;

    bool is_const = true;
    for (const Node& a : args) is_const = is_const && a.is_const;
    return defineNode(v, body, op.res, is_const, out);
  }

  // A CORE query's assertable conjuncts: the members of a root (lall S) --
  // each named separately so get-unsat-core can blame them individually --
  // or the root itself as the single conjunct.  (word, rendered text).
  bool coreMembers(u64 root, std::vector<std::pair<u64, std::string>>& members)
  {
    std::string name;
    std::vector<u64> fields;
    if (is_struct(root) && smtStructFields(db, root, name, fields)
        && name == "lall" && fields.size() == 1 && is_cnode(fields[0]))
    {
      bool ok = true;
      db->collections()->foreach(fields[0], [&](u64 k, u64 val)
      {
        if (!ok) return;
        if (val != s32_encode(1))
        {
          ok = fail("(lall ...) expects a SET (built with cins/braces), not a map");
          return;
        }
        Node m;
        if (!render(k, m, 0)) { ok = false; return; }
        if (m.sort != SMT_BOOL)
        {
          ok = fail("non-boolean member of (lall ...)");
          return;
        }
        members.emplace_back(k, m.text);
      });
      return ok;
    }
    Node top;
    if (!render(root, top, 0)) return false;
    if (top.sort != SMT_BOOL)
      return fail("formula root is not boolean");
    members.emplace_back(root, top.text);
    return true;
  }

  // The whole query: inferred logic + declares + defines + assert(s) +
  // check-sat.  A MODEL query additionally requests values for every
  // variable after the check (harmless on unsat: the solver's get-value
  // error lines are ignored, the verdict has already been read) and bakes
  // the mangled->original name map into `; slogvar` comment lines that
  // solve() reads back.  A CORE query asserts each conjunct of a root
  // (lall S) separately under names sc0..scN (`; slogcore scK <word>`
  // comments carry the member formula's raw word back) and requests the
  // unsat core after the check.  Requests stay fully self-contained.
  bool print(u64 root, std::string& request, SmtMode mode = SMT_MODE_CHECK)
  {
    std::vector<std::pair<u64, std::string>> members;   // core mode only
    Node top;
    if (mode == SMT_MODE_CORE)
    {
      if (!coreMembers(root, members)) return false;
    }
    else
    {
      if (!render(root, top, 0)) return false;
      if (top.sort != SMT_BOOL)
        return fail("formula root is not boolean");
    }

    std::ostringstream q;
    if (mode == SMT_MODE_MODEL) q << "(set-option :produce-models true)\n";
    if (mode == SMT_MODE_CORE)  q << "(set-option :produce-unsat-cores true)\n";
    q << "(set-logic " << (saw_nonlinear ? "QF_NIA" : "QF_LIA") << ")\n";
    if (mode == SMT_MODE_MODEL)
      for (const auto& v : vars)
      {
        std::string orig = v.second;
        for (char& c : orig)
          if (c == '\n' || c == '\r') c = ' ';
        q << "; slogvar " << v.first << " " << orig << "\n";
      }
    if (mode == SMT_MODE_CORE)
      for (size_t i = 0; i < members.size(); ++i)
        q << "; slogcore sc" << i << " " << members[i].first << "\n";
    for (const std::string& d : declares) q << d << "\n";
    q << defs.str();
    if (mode == SMT_MODE_CORE)
      for (size_t i = 0; i < members.size(); ++i)
        q << "(assert (! " << members[i].second << " :named sc" << i << "))\n";
    else
      q << "(assert " << top.text << ")\n";
    q << "(check-sat)\n";
    if (mode == SMT_MODE_MODEL && !vars.empty())
    {
      q << "(get-value (";
      for (size_t i = 0; i < vars.size(); ++i)
        q << (i ? " " : "") << vars[i].first;
      q << "))\n";
    }
    if (mode == SMT_MODE_CORE)
      q << "(get-unsat-core)\n";
    request = q.str();
    return true;
  }
};

// ---------------------------------------------------------------------------
// The mock backend: deterministic ground evaluation at dispatch time.
// A ground formula is sat iff it evaluates true (an existential over zero
// variables); anything containing a variable answers unknown.

struct SmtGroundEval
{
  Database* db;
  std::map<u64, std::optional<s64>> memo;   // value; nullopt = not ground

  explicit SmtGroundEval(Database* _db) : db(_db) {}

  // Integers as themselves, booleans as 0/1; nullopt when not ground (or not
  // in the vocabulary -- the mock has no error channel, it answers unknown).
  std::optional<s64> eval(u64 v, bool& is_bool, u32 depth)
  {
    is_bool = false;
    if (depth > 4096) return std::nullopt;
    if (is_s32(v)) return (s64)s32_decode(v);
    if (!is_struct(v)) return std::nullopt;
    std::string name;
    std::vector<u64> fields;
    if (!smtStructFields(db, v, name, fields)) return std::nullopt;

    if (name == "_enum" && fields.size() == 1 && is_str(fields[0]))
    {
      const std::string e = db->decodeString(fields[0]);
      is_bool = true;
      if (e == "ltrue") return 1;
      if (e == "lfalse") return 0;
      return std::nullopt;
    }
    if (name == "ic" && fields.size() == 1 && is_s32(fields[0]))
      return (s64)s32_decode(fields[0]);
    if (name == "iv" || name == "bv")
      return std::nullopt;                                  // free variable

    auto num = [&](u64 f) -> std::optional<s64>
    {
      bool b = false;
      auto r = eval(f, b, depth + 1);
      return (r && !b) ? r : std::nullopt;
    };
    auto boo = [&](u64 f) -> std::optional<s64>
    {
      bool b = false;
      auto r = eval(f, b, depth + 1);
      return (r && b) ? r : std::nullopt;
    };

    // (lall S)/(lany S) over a canonical set of formulas, with sound
    // short-circuiting: one ground-FALSE conjunct refutes the whole
    // conjunction (and one ground-TRUE disjunct satisfies the disjunction)
    // for EVERY assignment, so symbolic siblings don't force unknown.
    if ((name == "lall" || name == "lany") && fields.size() == 1
        && is_cnode(fields[0]))
    {
      const bool conj = (name == "lall");
      bool any_unknown = false;
      bool decided = false;                 // short-circuited by a member
      db->collections()->foreach(fields[0], [&](u64 k, u64 val)
      {
        if (decided) return;
        if (val != s32_encode(1)) { any_unknown = true; return; }  // not a set
        auto m = boo(k);
        if (!m) { any_unknown = true; return; }
        if (conj ? (*m == 0) : (*m != 0)) decided = true;
      });
      is_bool = true;
      if (decided) return conj ? 0 : 1;
      if (any_unknown) return std::nullopt;
      return conj ? 1 : 0;                  // vacuous/all-pass
    }

    if (name == "lite" && fields.size() == 3)
    {
      auto c = boo(fields[0]);
      if (!c) return std::nullopt;
      return num(*c ? fields[1] : fields[2]);
    }

    if (fields.size() == 2)
    {
      if (name == "ladd" || name == "lsub" || name == "lmul")
      {
        auto a = num(fields[0]), b = num(fields[1]);
        if (!a || !b) return std::nullopt;
        return name == "ladd" ? *a + *b : name == "lsub" ? *a - *b : *a * *b;
      }
      if (name == "llt" || name == "lle" || name == "lgt" || name == "lge"
          || name == "leq" || name == "lne")
      {
        auto a = num(fields[0]), b = num(fields[1]);
        if (!a || !b) return std::nullopt;
        is_bool = true;
        return name == "llt" ? (*a < *b)
             : name == "lle" ? (*a <= *b)
             : name == "lgt" ? (*a > *b)
             : name == "lge" ? (*a >= *b)
             : name == "leq" ? (*a == *b)
             : (*a != *b);
      }
      if (name == "land" || name == "lor" || name == "limplies")
      {
        auto a = boo(fields[0]), b = boo(fields[1]);
        if (!a || !b) return std::nullopt;
        is_bool = true;
        return name == "land" ? (*a && *b)
             : name == "lor"  ? (*a || *b)
             : (!*a || *b);
      }
    }
    if (name == "lnot" && fields.size() == 1)
    {
      auto a = boo(fields[0]);
      if (!a) return std::nullopt;
      is_bool = true;
      return !*a;
    }
    return std::nullopt;
  }
};

// ---------------------------------------------------------------------------
// Subprocess plumbing: run one solver over one query, wall-clock-bounded.

// Write all of `input` to fd, tolerating EINTR; false on EPIPE etc. (a dead
// solver is a respawn/fallthrough, not an error).  SIGPIPE is blocked for
// the calling (pool) thread so a broken pipe surfaces as EPIPE.
inline bool smtWriteAll(int fd, const std::string& input)
{
  size_t off = 0;
  while (off < input.size())
  {
    const ssize_t w = write(fd, input.data() + off, input.size() - off);
    if (w > 0) { off += (size_t)w; continue; }
    if (w < 0 && errno == EINTR) continue;
    return false;                              // EPIPE etc.: caller respawns
  }
  return true;
}

// Spawn argv with pipes on stdin/stdout (stderr -> /dev/null).  Only
// async-signal-safe calls between fork and exec.  The pipes are O_CLOEXEC:
// pool threads spawn racing children CONCURRENTLY, and without it a sibling
// child forked between our pipe() and close() inherits this child's stdout
// write-end -- holding EOF hostage until the sibling exits, which made a
// slow race loser "win" by delaying the fast winner's completion.  dup2 in
// the child clears the flag on the two ends it actually uses.
inline bool smtSpawn(const std::vector<std::string>& argv,
                     pid_t& pid, int& in_fd, int& out_fd)
{
  int inpipe[2], outpipe[2];
  if (pipe2(inpipe, O_CLOEXEC) != 0) return false;
  if (pipe2(outpipe, O_CLOEXEC) != 0) { close(inpipe[0]); close(inpipe[1]); return false; }
  pid = fork();
  if (pid < 0)
  {
    close(inpipe[0]); close(inpipe[1]);
    close(outpipe[0]); close(outpipe[1]);
    return false;
  }
  if (pid == 0)
  {
    dup2(inpipe[0], 0);
    dup2(outpipe[1], 1);
    const int devnull = open("/dev/null", O_WRONLY);
    if (devnull >= 0) dup2(devnull, 2);
    close(inpipe[0]); close(inpipe[1]);
    close(outpipe[0]); close(outpipe[1]);
    std::vector<char*> cargv;
    for (const std::string& a : argv) cargv.push_back(const_cast<char*>(a.c_str()));
    cargv.push_back(nullptr);
    execvp(cargv[0], cargv.data());
    _exit(127);
  }
  close(inpipe[0]);
  close(outpipe[1]);
  in_fd = inpipe[1];
  out_fd = outpipe[0];
  return true;
}

static bool smtEndsWith(const std::string& s, const std::string& suf)
{
  return s.size() >= suf.size()
         && s.compare(s.size() - suf.size(), suf.size(), suf) == 0;
}

// z3 and cvc5 support incremental SMT-LIB on stdin: one PERSISTENT process
// per (pool thread, solver) pays the spawn cost once, with (reset) between
// queries and an (echo ...) marker bounding each response.  Anything else
// (e.g. a script solver) is one-shot: spawn per query, EOF bounds the
// response.
inline bool smtPersistentCapable(const std::string& name)
{
  return name == "z3" || smtEndsWith(name, "/z3")
      || name == "cvc5" || smtEndsWith(name, "/cvc5");
}

inline std::vector<std::string> smtSolverArgv(const std::string& name)
{
  if (name == "z3" || smtEndsWith(name, "/z3"))
    return {name, "-in", "-smt2"};
  if (name == "cvc5" || smtEndsWith(name, "/cvc5"))
    return {name, "--lang", "smt2", "--incremental"};
  return {name};
}

#define SMT_DONE_MARKER "@@slogdone@@"

// A persistent solver process (thread-local per pool worker; the map's
// destructor reaps them at thread exit).
struct SolverProc
{
  pid_t pid = -1;
  int in = -1, out = -1;
  void killProc()
  {
    if (pid > 0)
    {
      ::kill(pid, SIGKILL);
      int st = 0;
      waitpid(pid, &st, 0);
    }
    if (in >= 0) close(in);
    if (out >= 0) close(out);
    pid = -1;
    in = out = -1;
  }
  ~SolverProc() { killProc(); }
};

// One round member's in-flight query.
struct SmtAttempt
{
  std::string name;
  SolverProc* proc = nullptr;    // persistent home (null: one-shot)
  pid_t pid = -1;                // one-shot child
  int out_fd = -1;
  bool done = false;
  s32 verdict = 0;               // 1|2 definitive; 0 unknown-so-far
  std::string buf;               // accumulated output
  size_t scanned = 0;            // line-scan cursor into buf
};

// Race one ROUND of solvers over one request: first member to COMPLETE with
// a definitive verdict wins (completion = marker for persistent members,
// EOF for one-shot ones -- a model query's values follow the verdict, so
// the winner's full response must be in hand).  Losers still running are
// killed (a mid-solve persistent process cannot take another query;
// respawning is cheaper than draining).  Returns 1|2 with the winner's
// output in `out`, or 0 (every member unknown/dead/timed out).
inline s32 smtRunRound(const std::vector<std::string>& names,
                       const std::string& request, u64 timeout_ms,
                       std::map<std::string, SolverProc>& procs,
                       std::string& out)
{
  sigset_t pipeset;
  sigemptyset(&pipeset);
  sigaddset(&pipeset, SIGPIPE);
  pthread_sigmask(SIG_BLOCK, &pipeset, nullptr);

  std::vector<SmtAttempt> atts;
  for (const std::string& name : names)
  {
    SmtAttempt a;
    a.name = name;
    if (smtPersistentCapable(name))
    {
      SolverProc& p = procs[name];
      for (int attempt = 0; attempt < 2 && a.out_fd < 0; ++attempt)
      {
        if (p.pid <= 0)
          if (!smtSpawn(smtSolverArgv(name), p.pid, p.in, p.out))
            break;
        // A dead child surfaces as EPIPE here; respawn once and retry.
        const std::string payload =
          "(reset)\n" + request + "(echo \"" SMT_DONE_MARKER "\")\n";
        if (smtWriteAll(p.in, payload))
        {
          a.proc = &p;
          a.out_fd = p.out;
        }
        else
          p.killProc();
      }
    }
    else
    {
      int in_fd = -1;
      if (smtSpawn(smtSolverArgv(name), a.pid, in_fd, a.out_fd))
      {
        smtWriteAll(in_fd, request);
        close(in_fd);                          // EOF: one-shot exits after answering
      }
    }
    if (a.out_fd < 0) { a.done = true; }       // spawn/write failure: no answer
    atts.push_back(a);
  }

  const auto deadline = std::chrono::steady_clock::now()
                        + std::chrono::milliseconds(timeout_ms + 500);
  const SmtAttempt* winner = nullptr;
  char buf[4096];
  for (;;)
  {
    // A finished member with a definitive verdict wins the round.
    for (const SmtAttempt& a : atts)
      if (a.done && (a.verdict == 1 || a.verdict == 2)) { winner = &a; break; }
    if (winner) break;
    bool all_done = true;
    for (const SmtAttempt& a : atts) all_done = all_done && a.done;
    if (all_done) break;
    const auto now = std::chrono::steady_clock::now();
    if (now >= deadline) break;

    std::vector<struct pollfd> pfds;
    std::vector<size_t> idx;
    for (size_t i = 0; i < atts.size(); ++i)
      if (!atts[i].done)
      {
        pfds.push_back({atts[i].out_fd, POLLIN, 0});
        idx.push_back(i);
      }
    const int pr = poll(pfds.data(), (nfds_t)pfds.size(), 20);
    if (pr < 0 && errno != EINTR) break;
    if (pr <= 0) continue;
    for (size_t k = 0; k < pfds.size(); ++k)
    {
      if (!(pfds[k].revents & (POLLIN | POLLHUP | POLLERR))) continue;
      SmtAttempt& a = atts[idx[k]];
      const ssize_t r = read(a.out_fd, buf, sizeof(buf));
      if (r > 0)
        a.buf.append(buf, (size_t)r);
      else if (r == 0 || (r < 0 && errno != EINTR && errno != EAGAIN))
      {
        a.done = true;                         // EOF: one-shot finished / child died
        if (a.proc) a.proc->killProc();        // a dead persistent proc respawns later
      }
      // Scan complete new lines for the verdict / end marker.
      for (;;)
      {
        const size_t nl = a.buf.find('\n', a.scanned);
        if (nl == std::string::npos) break;
        std::string line = a.buf.substr(a.scanned, nl - a.scanned);
        a.scanned = nl + 1;
        while (!line.empty() && (line.back() == '\r' || line.back() == ' '))
          line.pop_back();
        if (line == "sat") a.verdict = 1;
        else if (line == "unsat") a.verdict = 2;
        else if (line.find(SMT_DONE_MARKER) != std::string::npos)
          a.done = true;                       // persistent response complete
      }
    }
  }

  // Reap: one-shot children always; still-running members are killed (a
  // mid-solve persistent process is not reusable -- drop it for respawn).
  for (SmtAttempt& a : atts)
  {
    if (a.proc == nullptr && a.pid > 0)
    {
      if (!a.done) ::kill(a.pid, SIGKILL);
      int st = 0;
      waitpid(a.pid, &st, 0);
      if (a.out_fd >= 0) close(a.out_fd);
    }
    else if (a.proc != nullptr && !a.done)
      a.proc->killProc();
  }

  if (winner)
  {
    out = winner->buf;
    return winner->verdict;
  }
  return 0;
}

// Parse a model query's (get-value ...) response: for each `; slogvar
// <mangled> <original>` line of the REQUEST, find "(<mangled> <value>)" in
// the response and record (original, value); values are integers, (- n),
// or true/false (as 1/0).  Free function so the unit battery can feed it
// canned solver output.
inline void smtParseModel(const std::string& request, const std::string& response,
                          std::vector<std::pair<std::string, s64>>& entries)
{
  std::stringstream ls(request);
  std::string line;
  while (std::getline(ls, line))
  {
    const std::string tag = "; slogvar ";
    if (line.rfind(tag, 0) != 0) continue;
    const size_t sp = line.find(' ', tag.size());
    if (sp == std::string::npos) continue;
    const std::string mangled = line.substr(tag.size(), sp - tag.size());
    std::string original = line.substr(sp + 1);
    while (!original.empty() && original.back() == '\r') original.pop_back();

    const size_t at = response.find("(" + mangled + " ");
    if (at == std::string::npos) continue;
    size_t p = at + mangled.size() + 2;
    while (p < response.size() && response[p] == ' ') ++p;
    bool neg = false;
    if (p + 1 < response.size() && response[p] == '(' && response[p + 1] == '-')
    {
      neg = true;
      p += 2;
      while (p < response.size() && response[p] == ' ') ++p;
    }
    if (response.compare(p, 4, "true") == 0)
      entries.emplace_back(original, 1);
    else if (response.compare(p, 5, "false") == 0)
      entries.emplace_back(original, 0);
    else
    {
      size_t q = p;
      while (q < response.size() && isdigit((unsigned char)response[q])) ++q;
      if (q > p)
      {
        const s64 v = (s64)std::strtoll(response.c_str() + p, nullptr, 10);
        entries.emplace_back(original, neg ? -v : v);
      }
    }
  }
}

// Parse an unsat-core response: for each `; slogcore <name> <word>` line of
// the REQUEST, look for <name> as a delimited token in the response's core
// listing (e.g. "(sc0 sc2)") and record (word, 1).  Token-delimited so sc1
// never matches inside sc12.  Free function for the unit battery.
inline void smtParseCore(const std::string& request, const std::string& response,
                         std::vector<std::pair<u64, s64>>& word_entries)
{
  std::stringstream ls(request);
  std::string line;
  while (std::getline(ls, line))
  {
    const std::string tag = "; slogcore ";
    if (line.rfind(tag, 0) != 0) continue;
    const size_t sp = line.find(' ', tag.size());
    if (sp == std::string::npos) continue;
    const std::string name = line.substr(tag.size(), sp - tag.size());
    const u64 word = std::strtoull(line.c_str() + sp + 1, nullptr, 10);
    size_t at = 0;
    bool found = false;
    while (!found && (at = response.find(name, at)) != std::string::npos)
    {
      const char before = (at == 0) ? '(' : response[at - 1];
      const size_t end = at + name.size();
      const char after = (end >= response.size()) ? ')' : response[end];
      if (!isalnum((unsigned char)before) && before != '_'
          && !isalnum((unsigned char)after) && after != '_')
        found = true;
      at = end;
    }
    if (found)
      word_entries.emplace_back(word, 1);
  }
}

// ---------------------------------------------------------------------------
// The oracle.  Three registered instances share this class: "smt" answers
// int verdict codes, "smtmodel" answers maps ({"@status": code} plus, on
// sat, one satisfying value per variable under its ORIGINAL name), and
// "smtcore" answers maps ({"@status": code} plus, on unsat, the blamed
// conjuncts of a (lall S) root as raw-word keys -> a cset after the lib
// wrapper strips "@status").

class SmtOracle : public Oracle
{
  // A chain of racing rounds: "z3|cvc5:500,z3:5000" = race both at 500ms,
  // then z3 alone at 5s; the first definitive verdict anywhere wins.
  struct Round { std::vector<std::string> names; u64 timeout_ms; };
  std::vector<Round> chain;
  bool mock = false;
  SmtMode mode;

public:
  explicit SmtOracle(SmtMode _mode = SMT_MODE_CHECK) : mode(_mode)
  {
    const char* env = std::getenv("SLOG_SMT_SOLVERS");
    std::string spec = (env && env[0]) ? env : "mock";
    std::stringstream ss(spec);
    std::string item;
    while (std::getline(ss, item, ','))
    {
      if (item.empty()) continue;
      Round r;
      r.timeout_ms = 2000;
      const size_t colon = item.rfind(':');
      if (colon != std::string::npos && colon > 0
          && item.find_first_not_of("0123456789", colon + 1) == std::string::npos
          && colon + 1 < item.size())
      {
        r.timeout_ms = std::strtoull(item.c_str() + colon + 1, nullptr, 10);
        item = item.substr(0, colon);
      }
      std::stringstream ms(item);
      std::string name;
      while (std::getline(ms, name, '|'))
        if (!name.empty()) r.names.push_back(name);
      if (!r.names.empty()) chain.push_back(r);
    }
    if (chain.empty()) chain.push_back(Round{{"mock"}, 0});
    mock = (chain.size() == 1 && chain[0].names.size() == 1
            && chain[0].names[0] == "mock");
  }

  bool serialize(Database* db, u64 value, std::string& out, std::string& err) override
  {
    SmtPrinter p(db);
    if (p.print(value, out, mode)) return true;
    err = p.err;
    return false;
  }

  OracleResult unknownResult() override
  {
    OracleResult r;
    r.code = 0;
    r.is_map = (mode != SMT_MODE_CHECK);
    return r;
  }

  // Mock mode answers everything at dispatch time: ground formulas evaluate
  // to sat/unsat, anything with a variable is unknown.  Deterministic and
  // database-safe (read phase), so golden tests need no solver install.
  // Model-mode mock: ground formulas have no variables, so a sat model is
  // the empty assignment.  Core-mode mock: every ground-FALSE conjunct of a
  // (lall S) root is blamed (each alone refutes the conjunction).
  bool solveEager(Database* db, u64 value, OracleResult& out) override
  {
    if (!mock) return false;
    SmtGroundEval ev(db);
    out = OracleResult{};
    out.is_map = (mode != SMT_MODE_CHECK);
    if (mode == SMT_MODE_CORE)
    {
      mockCore(db, ev, value, out);
      return true;
    }
    bool is_bool = false;
    const auto r = ev.eval(value, is_bool, 0);
    out.code = (r.has_value() && is_bool) ? (*r ? 1 : 2) : 0;
    return true;
  }

  OracleResult solve(const std::string& request) override
  {
    // Each pool thread owns its persistent solver processes; reaped by the
    // map destructor at thread exit (daemon shutdown joins the pool).
    thread_local std::map<std::string, SolverProc> procs;
    for (const Round& round : chain)
    {
      std::vector<std::string> names;
      for (const std::string& n : round.names)
        if (n != "mock") names.push_back(n);   // mock is eager-only
      if (names.empty()) continue;
      std::string out;
      const s32 v = smtRunRound(names, request, round.timeout_ms, procs, out);
      if (v == 1 || v == 2)
      {
        OracleResult res;
        res.code = v;
        res.is_map = (mode != SMT_MODE_CHECK);
        if (mode == SMT_MODE_MODEL && v == 1)
          smtParseModel(request, out, res.entries);
        if (mode == SMT_MODE_CORE && v == 2)
          smtParseCore(request, out, res.word_entries);
        return res;
      }
      // unknown / timeout / dead: fall through to the next round
    }
    return unknownResult();
  }

private:
  // Ground core evaluation: blame every ground-false conjunct of a (lall S)
  // root (or the root itself); sat when all conjuncts are ground-true,
  // unknown when nothing ground-false exists but symbolic members remain.
  void mockCore(Database* db, SmtGroundEval& ev, u64 root, OracleResult& out)
  {
    auto evalOne = [&](u64 f) -> std::optional<s64>
    {
      bool is_bool = false;
      auto r = ev.eval(f, is_bool, 0);
      return (r && is_bool) ? r : std::nullopt;
    };
    std::string name;
    std::vector<u64> fields;
    if (is_struct(root) && smtStructFields(db, root, name, fields)
        && name == "lall" && fields.size() == 1 && is_cnode(fields[0]))
    {
      bool any_unknown = false;
      db->collections()->foreach(fields[0], [&](u64 k, u64 val)
      {
        if (val != s32_encode(1)) { any_unknown = true; return; }
        const auto r = evalOne(k);
        if (!r) any_unknown = true;
        else if (*r == 0) out.word_entries.emplace_back(k, 1);
      });
      out.code = !out.word_entries.empty() ? 2 : (any_unknown ? 0 : 1);
      return;
    }
    const auto r = evalOne(root);
    if (r && *r == 0) { out.code = 2; out.word_entries.emplace_back(root, 1); }
    else out.code = (r && *r != 0) ? 1 : 0;
  }
};

}
