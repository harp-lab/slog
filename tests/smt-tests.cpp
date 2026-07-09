/** SMT oracle unit tests (docs/smt.md).
 *
 * Standalone binary; not part of the golden suite.  Build + run:
 *   clang++ -O2 -Wall -std=c++20 -pthread -fopenmp -Idaemon \
 *       tests/smt-tests.cpp -o build/smt-tests -lz
 *   ./build/smt-tests
 *
 * Covers, over hand-interned formula values in a fresh Database:
 *   - SMT-LIB rendering: sorts, declare-consts, name mangling, negative
 *     literals, boolean enum constants, ill-sorted / unknown-constructor /
 *     non-boolean-root failures;
 *   - DAG awareness: a shared subterm emits exactly one define-fun;
 *   - the mock backend's ground evaluation (sat / unsat / unknown);
 *   - solver-chain spec parsing via env (mock default);
 *   - optionally, a real z3 end-to-end solve when SMT_TEST_Z3 names a
 *     binary (the golden suite never requires one).
 */

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#include "slogd.h"

using namespace slog;

static u32 pass_count = 0;

#define CHECK(what, cond)                                        \
  do {                                                           \
    if (cond) { ++pass_count; }                                  \
    else {                                                       \
      std::cerr << "FAIL: " << what << std::endl;                \
      std::exit(1);                                              \
    }                                                            \
  } while (0)

// Count non-overlapping occurrences of `needle` in `hay`.
static u32 countOccur(const std::string& hay, const std::string& needle)
{
  u32 n = 0;
  size_t at = 0;
  while ((at = hay.find(needle, at)) != std::string::npos)
  {
    ++n;
    at += needle.size();
  }
  return n;
}


// Interface adapters for the OracleResult-based API (docs/smt.md §14).
static s32 eagerCode(SmtOracle& o, Database* db, u64 f)
{
  OracleResult r;
  if (!o.solveEager(db, f, r)) return -99;
  return r.code;
}

// A tiny by-hand interner over a Database: declare each constructor as a
// struct relation with master + lookup indices, then insert instances with
// sequential per-relation ids (content dedup is irrelevant at test scale).
struct TestHeap
{
  Database db{1};
  std::unordered_map<std::string, u64> next_id;

  TestHeap()
  {
    declare("_enum", 1);
    declare("iv", 1);
    declare("bv", 1);
    declare("ic", 1);
    for (const char* n : {"ladd", "lsub", "lmul", "llt", "lle", "lgt",
                          "lge", "leq", "lne"})
      declare(n, 2);
    for (const char* n : {"land", "lor", "limplies"})
      declare(n, 2);
    declare("lnot", 1);
    declare("lite", 3);
    declare("lall", 1);
    declare("lany", 1);
    declare("bogus", 1);      // deliberately outside the vocabulary
  }

  void declare(const std::string& name, u16 fields)
  {
    const u16 arity = fields + 1;                     // + id column
    db.addStruct(name, arity);
    Relation* r = db.getRelation(name);
    std::vector<u16> master, lookup;
    for (u16 c = 1; c < arity; ++c) master.push_back(c);
    master.push_back(0);
    for (u16 c = 0; c < arity; ++c) lookup.push_back(c);
    switch (arity)
    {
      case 2: r->addIndex<2>(master, false); r->addIndex<2>(lookup, false); break;
      case 3: r->addIndex<3>(master, false); r->addIndex<3>(lookup, false); break;
      case 4: r->addIndex<4>(master, false); r->addIndex<4>(lookup, false); break;
      default: fatal("unexpected test arity");
    }
  }

  // A canonical cset of the given member words (the arena cins kernel).
  u64 set(std::initializer_list<u64> members)
  {
    u64 s = db.collections()->empty();
    for (u64 m : members) s = _prim_cins(&db, s, m);
    return s;
  }

  u64 mk(const std::string& name, const std::vector<u64>& fields)
  {
    Relation* r = db.getRelation(name);
    const u64 k = next_id[name]++;
    const u64 id = struct_encode(r->getStructId(), (k << bucket_bits) | 0);
    std::vector<u64> t;
    t.push_back(id);
    for (u64 f : fields) t.push_back(f);
    r->insertTupleAllIndices(t.data());
    return id;
  }

  u64 str(const std::string& s) { return str_encode(&db, s); }
  u64 num(s32 v) { return s32_encode(v); }
  u64 ic(s32 v) { return mk("ic", {num(v)}); }
  u64 iv(const std::string& n) { return mk("iv", {str(n)}); }
  u64 bv(const std::string& n) { return mk("bv", {str(n)}); }
  u64 enumc(const std::string& n) { return mk("_enum", {str(n)}); }
};

int main()
{
  setenv("SLOG_SMT_SOLVERS", "mock", 1);
  TestHeap h;
  SmtOracle oracle;

  // ---- rendering basics ----
  {
    // (land (l< (ic 1) (ic -2)) (lor ltrue (bv "p?q")))
    const u64 cmp = h.mk("llt", {h.ic(1), h.ic(-2)});
    const u64 disj = h.mk("lor", {h.enumc("ltrue"), h.bv("p?q")});
    const u64 root = h.mk("land", {cmp, disj});
    std::string out, err;
    CHECK("render basic formula", oracle.serialize(&h.db, root, out, err));
    CHECK("declares mangled bool var", out.find("(declare-const b_p_q Bool)") != std::string::npos);
    CHECK("negative literal form", out.find("(- 2)") != std::string::npos);
    CHECK("boolean enum constant", out.find("true") != std::string::npos);
    CHECK("check-sat present", out.find("(check-sat)") != std::string::npos);
    CHECK("assert present", out.find("(assert t") != std::string::npos);
    CHECK("three compound nodes", countOccur(out, "define-fun") == 3);
  }

  // ---- DAG sharing: one define-fun per distinct compound node ----
  {
    const u64 x = h.iv("x");
    const u64 shared = h.mk("llt", {x, h.ic(10)});
    const u64 both = h.mk("land", {shared, shared});
    std::string out, err;
    CHECK("render shared formula", oracle.serialize(&h.db, both, out, err));
    CHECK("shared subterm emits once", countOccur(out, "define-fun") == 2);
    CHECK("declares int var", out.find("(declare-const i_x Int)") != std::string::npos);
  }

  // ---- rendering failures ----
  {
    std::string out, err;
    CHECK("int root fails", !oracle.serialize(&h.db, h.ic(5), out, err));
    CHECK("int root reason", err.find("not boolean") != std::string::npos);
  }
  {
    std::string out, err;
    const u64 bad = h.mk("bogus", {h.num(1)});
    CHECK("unknown constructor fails", !oracle.serialize(&h.db, bad, out, err));
    CHECK("unknown constructor reason", err.find("bogus") != std::string::npos);
  }
  {
    std::string out, err;
    const u64 ill = h.mk("land", {h.ic(1), h.enumc("ltrue")});
    CHECK("ill-sorted land fails", !oracle.serialize(&h.db, ill, out, err));
    CHECK("ill-sorted reason", err.find("ill-sorted") != std::string::npos);
  }

  // ---- mock ground evaluation ----
  {
    s32 code = -1;
    // (land (l< 1 2) (lnot lfalse)) -- true => sat
    const u64 f = h.mk("land", {h.mk("llt", {h.ic(1), h.ic(2)}),
                                h.mk("lnot", {h.enumc("lfalse")})});
    code = eagerCode(oracle, &h.db, f);
    CHECK("mock answers eagerly", code != -99);
    CHECK("ground true is sat", code == 1);
  }
  {
    s32 code = -1;
    // (l= (l+ 2 2) 5) -- false => unsat
    const u64 f = h.mk("leq", {h.mk("ladd", {h.ic(2), h.ic(2)}), h.ic(5)});
    code = eagerCode(oracle, &h.db, f);
    CHECK("ground false is unsat", code == 2);
  }
  {
    s32 code = -1;
    // (l< x 3) -- free variable => unknown under mock
    const u64 f = h.mk("llt", {h.iv("free"), h.ic(3)});
    code = eagerCode(oracle, &h.db, f);
    CHECK("variable is unknown under mock", code == 0);
  }
  {
    s32 code = -1;
    code = eagerCode(oracle, &h.db, h.ic(7));
    CHECK("non-boolean root is unknown under mock", code == 0);
  }

  // ---- extended comparisons + lite ----
  {
    const u64 f = h.mk("lne", {h.mk("lgt", {h.ic(5), h.ic(3)}) /*bool!*/, h.ic(1)});
    std::string out, err;
    CHECK("lne over a bool arg fails", !oracle.serialize(&h.db, f, out, err));
  }
  {
    // (lge (lite (lgt x 0) x (lsub 0 x)) 0): |x| >= 0, symbolic
    const u64 x = h.iv("absx");
    const u64 f = h.mk("lge", {h.mk("lite", {h.mk("lgt", {x, h.ic(0)}),
                                             x, h.mk("lsub", {h.ic(0), x})}),
                               h.ic(0)});
    std::string out, err;
    CHECK("lite renders", oracle.serialize(&h.db, f, out, err));
    CHECK("ite in output", out.find("(ite ") != std::string::npos);
    CHECK("ge in output", out.find("(>= ") != std::string::npos);
    CHECK("linear logic inferred", out.find("(set-logic QF_LIA)") != std::string::npos);
  }
  {
    s32 code = -1;
    // (lne 4 5) ground => sat; (lge 4 5) => unsat; lite picks the then-branch
    code = eagerCode(oracle, &h.db, h.mk("lne", {h.ic(4), h.ic(5)}));
    CHECK("mock lne", code == 1);
    code = eagerCode(oracle, &h.db, h.mk("lge", {h.ic(4), h.ic(5)}));
    CHECK("mock lge", code == 2);
    code = eagerCode(oracle, &h.db, h.mk("leq", {h.mk("lite", {h.mk("llt", {h.ic(1), h.ic(2)}), h.ic(10), h.ic(20)}),
                   h.ic(10)}));
    CHECK("mock lite", code == 1);
  }

  // ---- logic inference: nonlinear multiplication => QF_NIA ----
  {
    const u64 x = h.iv("nlx");
    const u64 f = h.mk("lgt", {h.mk("lmul", {x, x}), h.ic(4)});
    std::string out, err;
    CHECK("nonlinear renders", oracle.serialize(&h.db, f, out, err));
    CHECK("nonlinear logic inferred", out.find("(set-logic QF_NIA)") != std::string::npos);
  }
  {
    const u64 f = h.mk("lgt", {h.mk("lmul", {h.ic(3), h.iv("linx")}), h.ic(4)});
    std::string out, err;
    CHECK("const-scaled renders", oracle.serialize(&h.db, f, out, err));
    CHECK("const-scaled stays linear", out.find("(set-logic QF_LIA)") != std::string::npos);
  }

  // ---- lall/lany: csets as n-ary conjunction/disjunction ----
  {
    const u64 a = h.mk("llt", {h.iv("s1"), h.ic(3)});
    const u64 b = h.mk("llt", {h.ic(0), h.iv("s1")});
    const u64 f = h.mk("lall", {h.set({a, b})});
    std::string out, err;
    CHECK("lall renders", oracle.serialize(&h.db, f, out, err));
    CHECK("lall is an and", out.find("(and ") != std::string::npos);
  }
  {
    const u64 f = h.mk("lall", {h.set({})});
    std::string out, err;
    CHECK("empty lall renders", oracle.serialize(&h.db, f, out, err));
    CHECK("empty lall is true", out.find("(assert true)") != std::string::npos);
    s32 code = -1;
    code = eagerCode(oracle, &h.db, f);
    CHECK("empty lall sat under mock", code == 1);
    code = eagerCode(oracle, &h.db, h.mk("lany", {h.set({})}));
    CHECK("empty lany unsat under mock", code == 2);
  }
  {
    // sound short-circuit: one ground-false conjunct refutes the set even
    // with a symbolic sibling; one ground-true disjunct satisfies it
    const u64 sym = h.mk("llt", {h.iv("scx"), h.ic(9)});
    const u64 f0 = h.mk("llt", {h.ic(5), h.ic(3)});   // false
    const u64 t0 = h.mk("llt", {h.ic(3), h.ic(5)});   // true
    s32 code = -1;
    code = eagerCode(oracle, &h.db, h.mk("lall", {h.set({f0, sym})}));
    CHECK("lall short-circuits on false", code == 2);
    code = eagerCode(oracle, &h.db, h.mk("lany", {h.set({t0, sym})}));
    CHECK("lany short-circuits on true", code == 1);
    code = eagerCode(oracle, &h.db, h.mk("lall", {h.set({t0, sym})}));
    CHECK("lall with symbolic member unknown", code == 0);
  }
  {
    // a MAP in formula position is rejected (sets only)
    const u64 m = _prim_cput(&h.db, h.db.collections()->empty(),
                             h.num(1), h.num(7));
    const u64 f = h.mk("lall", {m});
    std::string out, err;
    CHECK("lall over a map fails", !oracle.serialize(&h.db, f, out, err));
    CHECK("map reason", err.find("SET") != std::string::npos);
  }
  {
    const u64 f = h.mk("lany", {h.set({h.ic(3)})});   // non-boolean member
    std::string out, err;
    CHECK("non-bool member fails", !oracle.serialize(&h.db, f, out, err));
    CHECK("member reason", err.find("non-boolean member") != std::string::npos);
  }

  // ---- model machinery (docs/smt.md §14) ----
  {
    // canned response parsing: ints, negatives, booleans, name unmangling
    const std::string req =
      "; slogvar i_x x\n; slogvar i_y y\n; slogvar b_p p?q\n(check-sat)\n";
    const std::string resp = "sat\n((i_x 5)\n (i_y (- 3))\n (b_p true))\n";
    std::vector<std::pair<std::string, s64>> entries;
    smtParseModel(req, resp, entries);
    CHECK("model parses three vars", entries.size() == 3);
    CHECK("model int", entries[0].first == "x" && entries[0].second == 5);
    CHECK("model negative", entries[1].first == "y" && entries[1].second == -3);
    CHECK("model bool as 1 under original name",
          entries[2].first == "p?q" && entries[2].second == 1);
  }
  {
    // model-mode rendering: produce-models, slogvar reverse map, get-value
    SmtOracle model_oracle(SMT_MODE_MODEL);
    const u64 f = h.mk("lle", {h.iv("mx"), h.ic(5)});
    std::string out, err;
    CHECK("model request renders", model_oracle.serialize(&h.db, f, out, err));
    CHECK("produce-models set", out.find("(set-option :produce-models true)") != std::string::npos);
    CHECK("slogvar comment", out.find("; slogvar i_mx mx") != std::string::npos);
    CHECK("get-value present", out.find("(get-value (i_mx))") != std::string::npos);
  }
  {
    // model-mode mock: ground => sat with the empty assignment, map-shaped
    SmtOracle model_oracle(SMT_MODE_MODEL);
    OracleResult r;
    CHECK("model mock eager", model_oracle.solveEager(&h.db, h.mk("llt", {h.ic(1), h.ic(2)}), r));
    CHECK("model mock sat", r.code == 1 && r.is_map && r.entries.empty());
    CHECK("model mock unknown shape",
          model_oracle.unknownResult().is_map && model_oracle.unknownResult().code == 0);
  }

  // ---- core machinery (docs/smt.md §15) ----
  {
    // core request rendering: named asserts + slogcore reverse map
    SmtOracle core_oracle(SMT_MODE_CORE);
    const u64 a = h.mk("llt", {h.iv("ca"), h.ic(3)});
    const u64 b = h.mk("lgt", {h.iv("ca"), h.ic(5)});
    const u64 f = h.mk("lall", {h.set({a, b})});
    std::string out, err;
    CHECK("core request renders", core_oracle.serialize(&h.db, f, out, err));
    CHECK("produce-unsat-cores set",
          out.find("(set-option :produce-unsat-cores true)") != std::string::npos);
    CHECK("two named asserts", countOccur(out, ":named sc") == 2);
    CHECK("two slogcore lines", countOccur(out, "; slogcore sc") == 2);
    CHECK("get-unsat-core present", out.find("(get-unsat-core)") != std::string::npos);
  }
  {
    // canned core-response parsing (token-delimited: sc1 must not match sc12)
    std::string req = "; slogcore sc1 111\n; slogcore sc12 222\n; slogcore sc2 333\n";
    const std::string resp = "unsat\n(sc12 sc2)\n";
    std::vector<std::pair<u64, s64>> words;
    smtParseCore(req, resp, words);
    CHECK("core parses two members", words.size() == 2);
    CHECK("core words correct",
          words[0].first == 222 && words[1].first == 333);
  }
  {
    // mock core: every ground-false conjunct is blamed; symbolic ones are not
    SmtOracle core_oracle(SMT_MODE_CORE);
    const u64 f1 = h.mk("llt", {h.ic(5), h.ic(3)});    // false
    const u64 f2 = h.mk("lgt", {h.ic(1), h.ic(2)});    // false
    const u64 t1 = h.mk("llt", {h.ic(1), h.ic(2)});    // true
    const u64 sym = h.mk("llt", {h.iv("cs"), h.ic(9)});
    OracleResult r;
    CHECK("mock core eager",
          core_oracle.solveEager(&h.db, h.mk("lall", {h.set({f1, f2, t1, sym})}), r));
    CHECK("mock core unsat", r.code == 2 && r.is_map);
    CHECK("mock core blames both falses", r.word_entries.size() == 2);
    bool has1 = false, has2 = false;
    for (const auto& e : r.word_entries)
    {
      if (e.first == f1) has1 = true;
      if (e.first == f2) has2 = true;
    }
    CHECK("mock core members exact", has1 && has2);
    OracleResult r2;
    core_oracle.solveEager(&h.db, h.mk("lall", {h.set({t1, sym})}), r2);
    CHECK("mock core unknown without a false", r2.code == 0 && r2.word_entries.empty());
    OracleResult r3;
    core_oracle.solveEager(&h.db, h.mk("lall", {h.set({t1})}), r3);
    CHECK("mock core sat when all true", r3.code == 1 && r3.word_entries.empty());
  }

  // ---- optional real-solver end-to-end (SMT_TEST_Z3=/path/to/z3) ----
  if (const char* z3 = std::getenv("SMT_TEST_Z3"))
  {
    setenv("SLOG_SMT_SOLVERS", (std::string(z3) + ":4000").c_str(), 1);
    SmtOracle real;
    {
      // x < 3 && 5 < x: unsat over the SAME variable
      const u64 x = h.iv("z3x");
      const u64 f = h.mk("land", {h.mk("llt", {x, h.ic(3)}),
                                  h.mk("llt", {h.ic(5), x})});
      std::string out, err;
      CHECK("z3 render", real.serialize(&h.db, f, out, err));
      CHECK("z3 unsat", real.solve(out).code == 2);
    }
    {
      // x < 3 && 1 < x: sat
      const u64 x = h.iv("z3y");
      const u64 f = h.mk("land", {h.mk("llt", {x, h.ic(3)}),
                                  h.mk("llt", {h.ic(1), x})});
      std::string out, err;
      CHECK("z3 render sat", real.serialize(&h.db, f, out, err));
      CHECK("z3 sat", real.solve(out).code == 1);
    }
    {
      // solver-chain fallthrough: a nonexistent solver, then z3
      setenv("SLOG_SMT_SOLVERS",
             (std::string("no-such-solver:100,") + z3 + ":4000").c_str(), 1);
      SmtOracle chained;
      const u64 f = h.mk("llt", {h.iv("z3z"), h.ic(3)});
      std::string out, err;
      chained.serialize(&h.db, f, out, err);
      CHECK("chain falls through to z3", chained.solve(out).code == 1);
    }
    {
      // persistent process reuse: several queries through ONE oracle
      // exercise the (reset) + end-marker protocol on the same z3
      setenv("SLOG_SMT_SOLVERS", (std::string(z3) + ":4000").c_str(), 1);
      SmtOracle persist;
      const u64 fsat = h.mk("llt", {h.iv("pq1"), h.ic(3)});
      const u64 funsat = h.mk("land", {h.mk("llt", {h.iv("pq2"), h.ic(3)}),
                                       h.mk("llt", {h.ic(5), h.iv("pq2")})});
      std::string s1, s2, err;
      persist.serialize(&h.db, fsat, s1, err);
      persist.serialize(&h.db, funsat, s2, err);
      CHECK("persistent q1 sat", persist.solve(s1).code == 1);
      CHECK("persistent q2 unsat", persist.solve(s2).code == 2);
      CHECK("persistent q3 sat again", persist.solve(s1).code == 1);
    }
    {
      // racing: a nonexistent member must not stop the round's z3 winning
      setenv("SLOG_SMT_SOLVERS",
             (std::string("no-such-solver|") + z3 + ":4000").c_str(), 1);
      SmtOracle race;
      const u64 f = h.mk("llt", {h.iv("rc1"), h.ic(3)});
      std::string out, err;
      race.serialize(&h.db, f, out, err);
      CHECK("race round won by z3", race.solve(out).code == 1);
    }
    {
      // a real model: x <= 5 && x >= 5 && p forces {x: 5, p: 1}
      setenv("SLOG_SMT_SOLVERS", (std::string(z3) + ":4000").c_str(), 1);
      SmtOracle model_oracle(SMT_MODE_MODEL);
      const u64 x = h.iv("modx");
      const u64 f = h.mk("land",
        {h.mk("land", {h.mk("lle", {x, h.ic(5)}), h.mk("lge", {x, h.ic(5)})}),
         h.bv("modp")});
      std::string out, err;
      CHECK("z3 model render", model_oracle.serialize(&h.db, f, out, err));
      OracleResult r = model_oracle.solve(out);
      CHECK("z3 model sat", r.code == 1 && r.is_map);
      s64 vx = -1, vp = -1;
      for (const auto& e : r.entries)
      {
        if (e.first == "modx") vx = e.second;
        if (e.first == "modp") vp = e.second;
      }
      CHECK("z3 model values", vx == 5 && vp == 1);
    }
    {
      // a real unsat core: {x<3, x>5, p} blames the two arithmetic
      // conjuncts and not the innocent boolean
      setenv("SLOG_SMT_SOLVERS", (std::string(z3) + ":4000").c_str(), 1);
      SmtOracle core_oracle(SMT_MODE_CORE);
      const u64 x = h.iv("corex");
      const u64 lo = h.mk("llt", {x, h.ic(3)});
      const u64 hi = h.mk("lgt", {x, h.ic(5)});
      const u64 p = h.bv("corep");
      const u64 f = h.mk("lall", {h.set({lo, hi, p})});
      std::string out, err;
      CHECK("z3 core render", core_oracle.serialize(&h.db, f, out, err));
      OracleResult r = core_oracle.solve(out);
      CHECK("z3 core unsat", r.code == 2);
      bool has_lo = false, has_hi = false, has_p = false;
      for (const auto& e : r.word_entries)
      {
        if (e.first == lo) has_lo = true;
        if (e.first == hi) has_hi = true;
        if (e.first == p) has_p = true;
      }
      CHECK("z3 core blames the contradiction", has_lo && has_hi && !has_p);
    }
    std::cout << "(z3 end-to-end cases included)" << std::endl;
  }
  else
    std::cout << "(SMT_TEST_Z3 unset: skipping real-solver cases)" << std::endl;

  std::cout << "smt-tests: all " << pass_count << " checks passed" << std::endl;
  return 0;
}
