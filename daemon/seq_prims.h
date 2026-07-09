/** Slog Sequence Prims
 *
 * Runtime kernels for the [T] sequence primitives (docs/sequences.md §3.1):
 * canonical chunked-Merkle lists in the per-Database sequence arena
 * (daemon/seq.h).  A sequence value is one NaN-boxed word (is_seq); elements
 * are arbitrary slog words.  Included by prims.h AFTER the Database
 * definition (the kernels call db->sequences() / db->collections()).
 *
 * Point ops (lref/lset/lins/ldel) and lidx are PARTIAL (compiler/
 * primitives.rkt prim-partial?): an out-of-range position or an absent
 * element is missing *data*, not a bug -- set *ok = false and the generated
 * letp check abandons the row.  A non-sequence argument STAYS fatal:
 * partiality is for absent data, not for type errors (D5).  lslice CLAMPS,
 * matching substr.
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2026
 * Some rights reserved. See License.md for details.
 *
 ******************************/


#pragma once

#include "slogd.h"

#include <format>
#include <algorithm>


#define SLOG_SEQ_ARG(v, OPSTR)                                                  \
  if (!is_seq(v))                                                               \
    slog::fatal(std::format("Function '" OPSTR "' requires a sequence, got: {}", \
                            get_type_name(v)));
#define SLOG_SEQ_INT(v, OPSTR)                                                  \
  if (!is_s32(v))                                                               \
    slog::fatal(std::format("Function '" OPSTR "' requires an int index, got: {}", \
                            get_type_name(v)));
#define SLOG_SEQ_CNODE(v, OPSTR)                                                \
  if (!is_cnode(v))                                                             \
    slog::fatal(std::format("Function '" OPSTR "' requires a collection, got: {}", \
                            get_type_name(v)));

//  (lempty) -- the empty sequence (one distinguished interned node)
inline u64 _prim_lempty(slog::Database* db)
{
  return db->sequences()->empty();
}

//  (lpush l v) -- l with v appended (the desugar's construction kernel;
//  bracket literals/heads lower to lempty/lpush/lcat chains)
inline u64 _prim_lpush(slog::Database* db, u64 l, u64 v)
{
  SLOG_SEQ_ARG(l, "lpush");
  return db->sequences()->ins(l, db->sequences()->len(l), v);
}

//  (aslst v) -- v as a sequence.  PARTIAL: a non-sequence word abandons
//  the row -- bracket patterns MATCH-FAIL on non-lists (an `any` column's
//  int, a flat lattice's (top)) exactly as a cons-struct join used to.
//  This is the §5.2 chain's entry point: every downstream op consumes its
//  OUTPUT, so the planner orders it first and no fatal-on-type kernel ever
//  sees a non-sequence word from a pattern.
inline u64 _prim_aslst(slog::Database* db, u64 v, bool* ok)
{
  (void)db;
  if (!is_seq(v))
  {
    *ok = false;
    return 0;
  }
  return v;
}

//  (llen l) -- element count, O(1)
inline u64 _prim_llen(slog::Database* db, u64 l)
{
  SLOG_SEQ_ARG(l, "llen");
  return s32_encode((s32)db->sequences()->len(l));
}

//  (lref l i) -- the element at i.  PARTIAL: out-of-range abandons the row.
inline u64 _prim_lref(slog::Database* db, u64 l, u64 i, bool* ok)
{
  SLOG_SEQ_ARG(l, "lref");
  SLOG_SEQ_INT(i, "lref");
  const s32 n = s32_decode(i);
  if (n < 0 || (u64)n >= db->sequences()->len(l))
  {
    *ok = false;
    return 0;
  }
  return db->sequences()->ref(l, (u64)n);
}

//  (lset l i v) -- l with position i replaced.  PARTIAL on range.
inline u64 _prim_lset(slog::Database* db, u64 l, u64 i, u64 v, bool* ok)
{
  SLOG_SEQ_ARG(l, "lset");
  SLOG_SEQ_INT(i, "lset");
  const s32 n = s32_decode(i);
  if (n < 0 || (u64)n >= db->sequences()->len(l))
  {
    *ok = false;
    return 0;
  }
  return db->sequences()->set(l, (u64)n, v);
}

//  (lins l i v) -- l with v inserted at i (valid positions 0..len).  PARTIAL.
inline u64 _prim_lins(slog::Database* db, u64 l, u64 i, u64 v, bool* ok)
{
  SLOG_SEQ_ARG(l, "lins");
  SLOG_SEQ_INT(i, "lins");
  const s32 n = s32_decode(i);
  if (n < 0 || (u64)n > db->sequences()->len(l))
  {
    *ok = false;
    return 0;
  }
  return db->sequences()->ins(l, (u64)n, v);
}

//  (ldel l i) -- l without position i.  PARTIAL on range.
inline u64 _prim_ldel(slog::Database* db, u64 l, u64 i, bool* ok)
{
  SLOG_SEQ_ARG(l, "ldel");
  SLOG_SEQ_INT(i, "ldel");
  const s32 n = s32_decode(i);
  if (n < 0 || (u64)n >= db->sequences()->len(l))
  {
    *ok = false;
    return 0;
  }
  return db->sequences()->del(l, (u64)n);
}

//  (lcat a b) -- concatenation, O(log n) seam work
inline u64 _prim_lcat(slog::Database* db, u64 a, u64 b)
{
  SLOG_SEQ_ARG(a, "lcat");
  SLOG_SEQ_ARG(b, "lcat");
  return db->sequences()->cat(a, b);
}

//  (lslice l i j) -- elements [i, j), bounds CLAMPED to [0, len] (substr
//  precedent, D5: clamping composes with computed bounds).
inline u64 _prim_lslice(slog::Database* db, u64 l, u64 i, u64 j)
{
  SLOG_SEQ_ARG(l, "lslice");
  SLOG_SEQ_INT(i, "lslice");
  SLOG_SEQ_INT(j, "lslice");
  const u64 n = db->sequences()->len(l);
  const s32 si = s32_decode(i), sj = s32_decode(j);
  const u64 lo = (si < 0) ? 0 : std::min((u64)si, n);
  const u64 hi = (sj < 0) ? 0 : std::min((u64)sj, n);
  return db->sequences()->slice(l, lo, hi);
}

//  (lrev l) -- reversal, O(n) by necessity
inline u64 _prim_lrev(slog::Database* db, u64 l)
{
  SLOG_SEQ_ARG(l, "lrev");
  return db->sequences()->rev(l);
}

//  (lidx l v) -- first index of element v.  PARTIAL: absent abandons the row.
inline u64 _prim_lidx(slog::Database* db, u64 l, u64 v, bool* ok)
{
  SLOG_SEQ_ARG(l, "lidx");
  const u64 pos = db->sequences()->find(l, &v, 1, 0);
  if (pos == SEQ_NPOS)
  {
    *ok = false;
    return 0;
  }
  return s32_encode((s32)pos);
}

//  (lmem l v) -- 1 if v occurs in l, else 0 (guard-friendly)
inline u64 _prim_lmem(slog::Database* db, u64 l, u64 v)
{
  SLOG_SEQ_ARG(l, "lmem");
  return s32_encode(db->sequences()->find(l, &v, 1, 0) == SEQ_NPOS ? 0 : 1);
}

//  (lsort l) -- ascending unsigned word order: canonical and deterministic,
//  but NOT a semantic ordering of the decoded values
inline u64 _prim_lsort(slog::Database* db, u64 l)
{
  SLOG_SEQ_ARG(l, "lsort");
  std::vector<u64> xs;
  db->sequences()->to_vector(l, xs);
  std::sort(xs.begin(), xs.end());
  return db->sequences()->build(xs.data(), xs.size());
}

//  (lst2set l) -- the set of l's elements
inline u64 _prim_lst2set(slog::Database* db, u64 l)
{
  SLOG_SEQ_ARG(l, "lst2set");
  u64 s = db->collections()->empty();
  db->sequences()->foreach(l, [&](u64 w)
  {
    s = db->collections()->put(s, w, s32_encode(1));
  });
  return s;
}

//  (set2lst s) -- the elements of s as a list, ascending word order (the
//  trie's in-order traversal: canonical)
inline u64 _prim_set2lst(slog::Database* db, u64 s)
{
  SLOG_SEQ_CNODE(s, "set2lst");
  std::vector<u64> xs;
  db->collections()->foreach(s, [&](u64 k, u64) { xs.push_back(k); });
  return db->sequences()->build(xs.data(), xs.size());
}

//  (ckeys m) -- m's keys as a list, ascending word order
inline u64 _prim_ckeys(slog::Database* db, u64 m)
{
  SLOG_SEQ_CNODE(m, "ckeys");
  std::vector<u64> xs;
  db->collections()->foreach(m, [&](u64 k, u64) { xs.push_back(k); });
  return db->sequences()->build(xs.data(), xs.size());
}

//  (cvals m) -- m's values as a list, in ascending-key order
inline u64 _prim_cvals(slog::Database* db, u64 m)
{
  SLOG_SEQ_CNODE(m, "cvals");
  std::vector<u64> xs;
  db->collections()->foreach(m, [&](u64, u64 v) { xs.push_back(v); });
  return db->sequences()->build(xs.data(), xs.size());
}

// ---------------------------------------------------------------------------
// Rope-string prims (docs/sequences.md §6, S2).  A string is monolithic
// (tag 0, <= SEQ_BLEAF_MAX bytes) or a rope (tag 4, a byte tree); every
// producer normalizes through Database::encodeString.  Surface indexing is
// in CODEPOINTS (the historic substr/size semantics); slices clamp,
// point/parse ops are PARTIAL (absence is data; type errors stay fatal).

#define SLOG_STR_ARG(v, OPSTR)                                                  \
  if (!is_str(v))                                                               \
    slog::fatal(std::format("Function '" OPSTR "' requires a string, got: {}",  \
                            get_type_name(v)));
#define SLOG_STR_INT(v, OPSTR)                                                  \
  if (!is_s32(v))                                                               \
    slog::fatal(std::format("Function '" OPSTR "' requires an int, got: {}",    \
                            get_type_name(v)));

//  string concatenation (the str arm of +): O(log n) seam work when either
//  side is a rope; small results stay monolithic (normalization)
inline u64 _prim_str_concat(slog::Database* db, u64 x, u64 y)
{
  slog::SequenceArena* ar = db->sequences();
  if (is_mono_str(x) && is_mono_str(y))
    return db->encodeString(db->decodeString(x) + db->decodeString(y));
  // at least one side is a rope; an empty mono side is the identity (and
  // must not reach build_bytes, whose streams are nonempty by contract)
  std::string sx, sy;
  if (is_mono_str(x))
  {
    sx = db->decodeString(x);
    if (sx.empty()) return y;
  }
  if (is_mono_str(y))
  {
    sy = db->decodeString(y);
    if (sy.empty()) return x;
  }
  const u64 tx = is_rope(x) ? x : ar->build_bytes((const u8*)sx.data(),
                                                  sx.size());
  const u64 ty = is_rope(y) ? y : ar->build_bytes((const u8*)sy.data(),
                                                  sy.size());
  return intern_encode(strrope_intern_tag,
                       decode_val(ar->cat_bytes(tx, ty)));
}

//  (substr s i j) -- codepoints [i, j), clamped (D5)
inline u64 _prim_substr(slog::Database* db, u64 s, u64 i, u64 e)
{
  SLOG_STR_ARG(s, "substr");
  SLOG_STR_INT(i, "substr");
  SLOG_STR_INT(e, "substr");
  s32 start = s32_decode(i);
  s32 end = s32_decode(e);
  if (start < 0) start = 0;
  if (end < start) end = start;
  if (is_mono_str(s))
    return str_encode(db, str_decode(db, s)->substr(start, end - start));
  slog::SequenceArena* ar = db->sequences();
  const u64 n = ar->cp_len(s);
  const u64 lo = std::min((u64)start, n);
  const u64 hi = std::min((u64)end, n);
  if (lo >= hi) return db->encodeString("");
  const u64 sl = ar->slice_cp(s, lo, hi);
  if (ar->byte_len(sl) <= SEQ_BLEAF_MAX)
  {
    std::string out;
    ar->materialize(sl, out);
    return db->encodeString(out);   // normalization: small results go mono
  }
  return intern_encode(strrope_intern_tag, decode_val(sl));
}

//  (schar s i) -- codepoint i as a 1-codepoint string.  PARTIAL on range.
inline u64 _prim_schar(slog::Database* db, u64 s, u64 i, bool* ok)
{
  SLOG_STR_ARG(s, "schar");
  SLOG_STR_INT(i, "schar");
  const s32 idx = s32_decode(i);
  if (idx < 0)
  {
    *ok = false;
    return 0;
  }
  if (is_rope(s))
  {
    slog::SequenceArena* ar = db->sequences();
    if ((u64)idx >= ar->cp_len(s))
    {
      *ok = false;
      return 0;
    }
    u8 buf[4];
    const u32 nb = ar->ref_cp(s, (u64)idx, buf);
    return db->encodeString(std::string((const char*)buf, nb));
  }
  slog::utf8string* u = str_decode(db, s);
  if ((u64)idx >= u->size())
  {
    *ok = false;
    return 0;
  }
  return str_encode(db, u->substr(idx, 1));
}

// byte-level search over either representation; returns byte pos or
// SEQ_NPOS, with *cp_at = the codepoint index of the match
inline u64 seq_str_find(slog::Database* db, u64 hay, const std::string& pat,
                        u64* cp_at)
{
  if (pat.empty())
  {
    if (cp_at) *cp_at = 0;
    return 0;
  }
  if (is_rope(hay))
    return db->sequences()->find_bytes(hay, (const u8*)pat.data(),
                                       (u32)pat.size(), cp_at);
  const std::string h = db->decodeString(hay);
  const size_t p = h.find(pat);
  if (p == std::string::npos) return SEQ_NPOS;
  if (cp_at)
  {
    u64 cps = 0;
    for (size_t b = 0; b < p; ++b)
      if (SEQ_CP_START((u8)h[b])) ++cps;
    *cp_at = cps;
  }
  return p;
}

//  (sidx s needle) -- codepoint index of the first occurrence.  PARTIAL:
//  absent is data.
inline u64 _prim_sidx(slog::Database* db, u64 s, u64 needle, bool* ok)
{
  SLOG_STR_ARG(s, "sidx");
  SLOG_STR_ARG(needle, "sidx");
  u64 cp = 0;
  if (seq_str_find(db, s, db->decodeString(needle), &cp) == SEQ_NPOS)
  {
    *ok = false;
    return 0;
  }
  return s32_encode((s32)cp);
}

//  (shas s needle) -- 1/0, guard-friendly
inline u64 _prim_shas(slog::Database* db, u64 s, u64 needle)
{
  SLOG_STR_ARG(s, "shas");
  SLOG_STR_ARG(needle, "shas");
  return s32_encode(
      seq_str_find(db, s, db->decodeString(needle), nullptr) == SEQ_NPOS
          ? 0 : 1);
}

//  (ssplit s sep) -- the pieces of s between occurrences of sep, as a
//  LIST of strings ([str]); an empty sep splits into single codepoints.
//  Standard split semantics: adjacent/edge separators yield empty pieces.
inline u64 _prim_ssplit(slog::Database* db, u64 s, u64 sep)
{
  SLOG_STR_ARG(s, "ssplit");
  SLOG_STR_ARG(sep, "ssplit");
  const std::string h = db->decodeString(s);
  const std::string p = db->decodeString(sep);
  std::vector<u64> pieces;
  if (p.empty())
  {
    size_t i = 0;
    while (i < h.size())
    {
      size_t j = i + 1;
      while (j < h.size() && !SEQ_CP_START((u8)h[j])) ++j;
      pieces.push_back(db->encodeString(h.substr(i, j - i)));
      i = j;
    }
  }
  else
  {
    size_t from = 0;
    while (true)
    {
      const size_t at = h.find(p, from);
      if (at == std::string::npos)
      {
        pieces.push_back(db->encodeString(h.substr(from)));
        break;
      }
      pieces.push_back(db->encodeString(h.substr(from, at - from)));
      from = at + p.size();
    }
  }
  return db->sequences()->build(pieces.data(), pieces.size());
}

//  (sjoin lst sep) -- concatenate a list of strings with sep between
inline u64 _prim_sjoin(slog::Database* db, u64 lst, u64 sep)
{
  if (!is_seq(lst))
    slog::fatal(std::format("Function 'sjoin' requires a list, got: {}",
                            get_type_name(lst)));
  SLOG_STR_ARG(sep, "sjoin");
  const std::string p = db->decodeString(sep);
  std::string out;
  bool first = true;
  db->sequences()->foreach(lst, [&](u64 w)
  {
    if (!is_str(w))
      slog::fatal(std::format(
          "Function 'sjoin' requires a list of strings, got element: {}",
          get_type_name(w)));
    if (!first) out += p;
    first = false;
    out += db->decodeString(w);
  });
  return db->encodeString(out);
}

//  (s2i s) -- strict decimal parse to s32.  PARTIAL: unparsable is data.
inline u64 _prim_s2i(slog::Database* db, u64 s, bool* ok)
{
  SLOG_STR_ARG(s, "s2i");
  const std::string t = db->decodeString(s);
  if (t.empty())
  {
    *ok = false;
    return 0;
  }
  errno = 0;
  char* end = nullptr;
  const long long v = strtoll(t.c_str(), &end, 10);
  if (errno != 0 || end != t.c_str() + t.size()
      || v < INT32_MIN || v > INT32_MAX)
  {
    *ok = false;
    return 0;
  }
  return s32_encode((s32)v);
}

//  (s2f s) -- parse to float.  PARTIAL (a NaN literal is unrepresentable
//  in the NaN-box, so it abandons too).
inline u64 _prim_s2f(slog::Database* db, u64 s, bool* ok)
{
  SLOG_STR_ARG(s, "s2f");
  const std::string t = db->decodeString(s);
  if (t.empty())
  {
    *ok = false;
    return 0;
  }
  errno = 0;
  char* end = nullptr;
  const double v = strtod(t.c_str(), &end);
  if (errno != 0 || end != t.c_str() + t.size())
  {
    *ok = false;
    return 0;
  }
  const u64 w = float_encode(v);
  if (w == slog_error)
  {
    *ok = false;
    return 0;
  }
  return w;
}

//  (i2s n) / (f2s x) -- total renderings; f2s matches the CSV float form
//  (shortest round-trippable, ".0" suffix on integer-valued doubles)
inline u64 _prim_i2s(slog::Database* db, u64 n)
{
  SLOG_STR_INT(n, "i2s");
  return db->encodeString(std::to_string(s32_decode(n)));
}

inline u64 _prim_f2s(slog::Database* db, u64 x)
{
  if (!is_float(x))
    slog::fatal(std::format("Function 'f2s' requires a float, got: {}",
                            get_type_name(x)));
  std::string s = std::format("{}", float_decode(x));
  if (s.find_first_of(".eEnN") == std::string::npos) s += ".0";
  return db->encodeString(s);
}

#undef SLOG_STR_ARG
#undef SLOG_STR_INT
#undef SLOG_SEQ_ARG
#undef SLOG_SEQ_INT
#undef SLOG_SEQ_CNODE
