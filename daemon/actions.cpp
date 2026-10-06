/** Client actions on the command layer.
 *
 * Every database verb a driver sends besides strata -- opening and writing
 * databases, edits, staging, counting, introspection -- arrives as one
 * command whose shape is the action spec compiler/actions.rkt writes:
 *
 *     (VERB ARG ...)
 *
 * Names and string values travel as strings, numbers as atoms; a tuple is a
 * list of values.  These were once generated plugins, one per spec, with the
 * spec's data baked into the C++ source -- so every new tuple, relation
 * name or epoch number cost a clang build.  Each verb here calls the Daemon
 * method its plugin called and answers with exactly that plugin's reply, so
 * no reader changed.  Malformed arguments refuse as `parse`.
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2023-2026
 * Some rights reserved. See License.md for details.
 ******************************/

#include "actions.h"
#include "daemon.h"

#include <algorithm>
#include <charconv>
#include <cstdio>
#include <format>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

namespace slog
{
namespace actions
{
namespace
{

using SExp = sexp::SExp;

// Thrown by the argument readers; dispatch turns it into one refusal.
struct Malformed {};

bool is_integer_text(const std::string& t)
{
    const size_t start = (!t.empty() && t[0] == '-') ? 1 : 0;
    return t.size() > start
        && std::all_of(t.begin() + start, t.end(),
                       [](char c) { return c >= '0' && c <= '9'; });
}

// The arguments after the verb, read left to right.
struct Args
{
    Daemon* d;
    const std::vector<SExp>& items;
    size_t next = 1;

    size_t left() const { return items.size() - next; }
    const SExp& item()
    {
        if (next >= items.size()) throw Malformed{};
        return items[next++];
    }
    void done() const { if (next != items.size()) throw Malformed{}; }

    static std::string name_of(const SExp& v)
    {
        if ((v.kind != SExp::K::string && v.kind != SExp::K::atom)
            || v.text.empty())
            throw Malformed{};
        return v.text;
    }
    std::string name() { return name_of(item()); }
    std::vector<std::string> rest_names()
    {
        std::vector<std::string> out;
        while (left() > 0) out.push_back(name());
        return out;
    }

    static s64 s64_of(const SExp& v)
    {
        s64 out = 0;
        if (v.kind != SExp::K::atom) throw Malformed{};
        const char* end = v.text.data() + v.text.size();
        const auto parsed = std::from_chars(v.text.data(), end, out);
        if (parsed.ec != std::errc() || parsed.ptr != end) throw Malformed{};
        return out;
    }
    static u64 u64_of(const SExp& v)
    {
        u64 out = 0;
        if (v.kind != SExp::K::atom) throw Malformed{};
        const char* end = v.text.data() + v.text.size();
        const auto parsed = std::from_chars(v.text.data(), end, out);
        if (parsed.ec != std::errc() || parsed.ptr != end) throw Malformed{};
        return out;
    }
    s64 integer() { return s64_of(item()); }
    u64 natural() { return u64_of(item()); }
    u32 position()
    {
        const u64 p = natural();
        if (p > UINT32_MAX) throw Malformed{};
        return (u32)p;
    }
    s8 sign()
    {
        const s64 s = integer();
        if (s != 1 && s != -1) throw Malformed{};
        return (s8)s;
    }
    double real()
    {
        const SExp& v = item();
        if (v.kind != SExp::K::atom || v.text.empty()) throw Malformed{};
        char* used = nullptr;
        const double out = std::strtod(v.text.c_str(), &used);
        if (used != v.text.c_str() + v.text.size()) throw Malformed{};
        return out;
    }
    // A literal tag (`signed`, `boosted`, ...), in either spelling.
    void tag(const char* expected)
    {
        if (name() != expected) throw Malformed{};
    }

    // One value, encoded as the plugin's generated C++ encoded it: a string
    // interns, an integer is an s32 word when it fits and an mpz otherwise,
    // a real is a float word.
    u64 value_of(const SExp& v)
    {
        Database* db = d->db();
        if (v.kind == SExp::K::string) return str_encode(db, v.text);
        if (v.kind != SExp::K::atom || v.text.empty()) throw Malformed{};
        if (is_integer_text(v.text))
        {
            s64 small = 0;
            const char* end = v.text.data() + v.text.size();
            const auto parsed = std::from_chars(v.text.data(), end, small);
            if (parsed.ec == std::errc() && small >= INT32_MIN
                && small <= INT32_MAX)
            {
                const int narrow = (int)small;
                return s32_encode(narrow);
            }
            return db->encodeIntLiteral(v.text);
        }
        char* used = nullptr;
        const double real = std::strtod(v.text.c_str(), &used);
        if (used != v.text.c_str() + v.text.size()) throw Malformed{};
        return float_encode(real);
    }
    std::vector<u64> rest_values()
    {
        std::vector<u64> out;
        while (left() > 0) out.push_back(value_of(item()));
        return out;
    }
    std::vector<u64> tuple_of(const SExp& t)
    {
        if (t.kind != SExp::K::list) throw Malformed{};
        std::vector<u64> out;
        for (const SExp& v : t.children) out.push_back(value_of(v));
        return out;
    }
    std::vector<std::vector<u64>> tuples()
    {
        const SExp& ts = item();
        if (ts.kind != SExp::K::list) throw Malformed{};
        std::vector<std::vector<u64>> out;
        for (const SExp& t : ts.children) out.push_back(tuple_of(t));
        return out;
    }
    // A list: (TAG name ...) when `tag` is given, else (name ...).
    std::vector<std::string> name_list(const char* tag = nullptr)
    {
        const SExp& l = item();
        if (l.kind != SExp::K::list) throw Malformed{};
        size_t i = 0;
        if (tag && (l.children.empty() || name_of(l.children[i++]) != tag))
            throw Malformed{};
        std::vector<std::string> out;
        for (; i < l.children.size(); ++i) out.push_back(name_of(l.children[i]));
        return out;
    }
    // ((A B) ...): a list of name pairs.
    std::vector<std::pair<std::string, std::string>> name_pairs()
    {
        const SExp& l = item();
        if (l.kind != SExp::K::list) throw Malformed{};
        std::vector<std::pair<std::string, std::string>> out;
        for (const SExp& p : l.children)
        {
            if (p.kind != SExp::K::list || p.children.size() != 2)
                throw Malformed{};
            out.emplace_back(name_of(p.children[0]), name_of(p.children[1]));
        }
        return out;
    }
};

template <class Set>
Set set_of(const std::vector<std::string>& names)
{
    return Set(names.begin(), names.end());
}

// The relation `rel`, or its version current at the optional position.
Relation* relation(Daemon* d, Args& a, const std::string& rel)
{
    return a.left() > 0 ? d->db()->getRelationAt(rel, a.position())
                        : d->db()->getRelation(rel);
}

// (dumprow V0) per tuple, then (dumpdone N): column 0 only, for the error
// watcher.
void dump_rel(Daemon* d, Relation* r)
{
    Database* db = d->db();
    size_t n = 0;
    if (r) Database::forEachNominal(r, [&](const u64* row) {
        d->emit("(dumprow " + db->writeValCSV(row[0]) + ")");
        ++n;
    });
    d->emit("(dumpdone " + std::to_string(n) + ")");
}

// One relation's count sidecar (docs/incremental.md §8B): (countrow REL
// key.. IN NR RC) per counted key, then (countdone REL N); -1 uncounted.
void dump_counts(Daemon* d, const std::string& rel, Relation* r)
{
    Database* db = d->db();
    if (!r || !r->getCountSidecar())
    {
        d->emit("(countdone " + rel + " -1)");
        return;
    }
    Index** side = r->getCountSidecar();
    const u16 ka = r->countKeyArity();
    size_t n = 0;
    for (u16 b = 0; b < bucket_count; ++b)
        side[b]->forEach([&](const u64* row) {
            std::string line = "(countrow " + rel;
            for (u16 c = 0; c < ka; ++c) line += " " + db->writeValCSV(row[c]);
            const u64 w = row[ka];
            line += std::string(" ") + (cnt_input(w) ? "1" : "0") + " "
                  + std::to_string(cnt_nonrec(w)) + " "
                  + std::to_string(cnt_rec(w)) + ")";
            d->emit(line);
            ++n;
        });
    d->emit("(countdone " + rel + " " + std::to_string(n) + ")");
}

// M7 rank witnesses: (rankrow REL key.. ROUND) per key, then (rankdone REL
// N); -1 without a rank sidecar.
void dump_ranks(Daemon* d, const std::string& rel, Relation* r)
{
    Database* db = d->db();
    if (!r || !r->getRankSidecar())
    {
        d->emit("(rankdone " + rel + " -1)");
        return;
    }
    Index** side = r->getRankSidecar();
    const u16 ka = r->countKeyArity();
    size_t n = 0;
    for (u16 b = 0; b < bucket_count; ++b)
        side[b]->forEach([&](const u64* row) {
            std::string line = "(rankrow " + rel;
            for (u16 c = 0; c < ka; ++c) line += " " + db->writeValCSV(row[c]);
            d->emit(line + " " + std::to_string(row[ka]) + ")");
            ++n;
        });
    d->emit("(rankdone " + rel + " " + std::to_string(n) + ")");
}

// Does any nominal row of `r` start with `prefix`?
bool has_prefix(Relation* r, const std::vector<u64>& prefix)
{
    bool found = false;
    if (r) Database::forEachNominal(r, [&](const u64* row) {
        if (std::equal(prefix.begin(), prefix.end(), row)) found = true;
    });
    return found;
}

// Relations sorted by name, as the sizes/schema replies list them.
std::vector<std::pair<std::string, Relation*>> sorted_relations(Daemon* d)
{
    std::vector<std::pair<std::string, Relation*>> rels(
        d->db()->getRelations().begin(), d->db()->getRelations().end());
    std::sort(rels.begin(), rels.end());
    return rels;
}

bool run(Daemon* d, const std::string& verb, Args& a)
{
    Database* db = d->db();

    // ---- databases on disk -------------------------------------------------
    if (verb == "open") { const auto n = a.name(); a.done(); d->open(n); }
    else if (verb == "import") { const auto n = a.name(); a.done(); d->import(n); }
    // Merge a database by path (no data/ prefix): a program's frozen ground
    // facts under build/frozen/<hash>/ (freeze.rkt).
    else if (verb == "import-path")
    {
        const auto dir = a.name(); a.done();
        if (d->refuseIfSuspended("import")) return true;
        d->importPath(dir);
        d->emit("(imported)");
    }
    // A compressed layer, passing trimmed same-lineage struct refs through
    // (docs/db-compression.md §4.2).
    else if (verb == "import-layer")
    { const auto n = a.name(); a.done(); d->importLayer(n); }
    else if (verb == "write-db")
    { const auto n = a.name(); a.done(); d->writeDatabaseBIN(n); }
    // Only the named relations (non-empty: empty means "all" to the daemon).
    else if (verb == "write-db-subset")
    {
        const auto n = a.name();
        const auto rels = a.rest_names();
        if (rels.empty()) throw Malformed{};
        d->writeDatabaseSubsetBIN(n, set_of<std::unordered_set<std::string>>(rels));
    }
    // (save-compressed DB PER SEED BOOST (boosted R..) (pinned R..)
    //                  (rels R..1) (accel 0|1)): the sampled IDB-layer write
    // (docs/db-compression.md P1.2/P2.4, docs/smt.md §15).
    else if (verb == "save-compressed")
    {
        const auto n = a.name();
        const double per = a.real();
        const u64 seed = a.natural();
        const double boost = a.real();
        const auto boosted = a.name_list("boosted");
        const auto pinned = a.name_list("pinned");
        const auto rels = a.name_list("rels");
        const SExp& accel = a.item();
        a.done();
        if (rels.empty() || accel.kind != SExp::K::list
            || accel.children.size() != 2
            || Args::name_of(accel.children[0]) != "accel")
            throw Malformed{};
        using Names = std::unordered_set<std::string>;
        d->writeDatabaseSampledBIN(n, set_of<Names>(rels), per, seed,
                                   set_of<Names>(boosted), boost,
                                   set_of<Names>(pinned),
                                   Args::u64_of(accel.children[1]) != 0);
    }
    else if (verb == "write-csv")
    { const auto dir = a.name(); a.done(); db->writeDatabaseCSV(dir); }
    // Serial checkpoint of the current, possibly paused, db (§P2.3).
    else if (verb == "checkpoint")
    { const auto n = a.name(); a.done(); d->checkpointBIN(n); }
    // Snapshot the EDB struct heap so the next layer write dedups against it.
    else if (verb == "capture-edb-heap") { a.done(); d->captureEDBHeap(); }
    else if (verb == "write-rel")
    {
        const auto n = a.name(); const auto rel = a.name(); a.done();
        d->writeRelationBIN(n, rel);
    }
    else if (verb == "write-rel-csv")
    {
        const auto dir = a.name(); const auto rel = a.name(); a.done();
        db->writeRelationCSV(dir, rel);
    }
    else if (verb == "load-rel")
    {
        const auto n = a.name(); const auto rel = a.name(); a.done();
        d->loadRelation(n, rel);
    }
    else if (verb == "refresh-rel")
    {
        const auto n = a.name(); const auto rel = a.name(); a.done();
        d->refreshRelation(n, rel);
    }

    // ---- edits and staging -------------------------------------------------
    // One tuple, storage order (edit-and-propagate, docs/db-compression §12;
    // retraction, docs/incremental.md §0.6; exact-once staging, 0.B5).
    else if (verb == "add-tuple" || verb == "del-tuple" || verb == "stage-tuple")
    {
        const auto rel = a.name();
        const auto t = a.rest_values();
        if (verb == "add-tuple") d->addTuple(rel, t);
        else if (verb == "del-tuple") d->delTuple(rel, t);
        else d->stageTuple(rel, t);
    }
    else if (verb == "clear-rel") { const auto r = a.name(); a.done(); d->clearRelation(r); }
    // Multi-tuple batches anchored at POS (-1 = the tip), §0.3 transport 1.
    else if (verb == "add-batch" || verb == "del-batch")
    {
        const auto rel = a.name(); const s64 pos = a.integer();
        const auto ts = a.tuples(); a.done();
        if (verb == "add-batch") d->addBatchAt(rel, pos, ts);
        else d->delBatchAt(rel, pos, ts);
    }
    else if (verb == "stage-batch")
    {
        const auto rel = a.name(); const auto ts = a.tuples(); a.done();
        d->stageBatch(rel, ts);
    }
    else if (verb == "input-state")
    {
        const auto rel = a.name(); const s64 pos = a.integer();
        const auto ts = a.tuples(); a.done();
        d->emitInputStates(rel, pos, ts);
    }
    // (set-overlay REL POS ((none|direct|mask TUPLE) ...))
    else if (verb == "set-overlay")
    {
        const auto rel = a.name(); const s64 pos = a.integer();
        const SExp& rows = a.item(); a.done();
        if (rows.kind != SExp::K::list) throw Malformed{};
        std::vector<std::pair<u8, std::vector<u64>>> out;
        for (const SExp& row : rows.children)
        {
            if (row.kind != SExp::K::list || row.children.size() != 2)
                throw Malformed{};
            const std::string state = Args::name_of(row.children[0]);
            const u8 code = state == "none" ? 0 : state == "direct" ? 1
                          : state == "mask" ? 2 : 3;
            if (code == 3) throw Malformed{};
            out.emplace_back(code, a.tuple_of(row.children[1]));
        }
        d->setOverlayAt(rel, pos, out);
    }
    // Test/oracle bulk loader: whitespace-separated signed integers from a
    // file, ARITY per row, installed as direct overlay support.
    else if (verb == "set-overlay-int-file")
    {
        const auto rel = a.name(); const auto path = a.name();
        const u64 arity = a.natural(); a.done();
        if (arity == 0) throw Malformed{};
        FILE* f = std::fopen(path.c_str(), "r");
        if (!f)
        {
            d->emit("(error set-overlay-int-file " + rel + ")");
            return true;
        }
        std::vector<std::pair<u8, std::vector<u64>>> rows;
        std::vector<u64> row;
        long long v = 0;
        while (std::fscanf(f, "%lld", &v) == 1)
        {
            row.push_back(s32_encode((s32)v));
            if (row.size() == arity)
            {
                rows.push_back({1, std::move(row)});
                row.clear();
            }
        }
        std::fclose(f);
        d->setOverlayAt(rel, -1, rows);
    }
    else if (verb == "set-overlay-positive" || verb == "set-overlay-negative"
             || verb == "set-overlay-negative-dred")
    {
        const auto rel = a.name(); const auto ts = a.tuples(); a.done();
        if (verb == "set-overlay-positive") d->setOverlayPositive(rel, ts);
        else if (verb == "set-overlay-negative") d->setOverlayNegative(rel, ts);
        else d->setOverlayNegativeDred(rel, ts);
    }
    // (stage-*-transitions signed SIGN REL ...), and the lattice replacements.
    else if (verb == "stage-update-transitions" || verb == "stage-view-transitions"
             || verb == "stage-lattice-replacements"
             || verb == "stage-lattice-replacements-repair")
    {
        a.tag("signed");
        const s8 sign = a.sign();
        const auto rels = a.rest_names();
        if (verb == "stage-update-transitions") d->stageUpdateTransitions(rels, sign);
        else if (verb == "stage-view-transitions") d->stageViewTransitions(rels, sign);
        else d->stageLatticeReplacements(rels, sign,
                                         verb == "stage-lattice-replacements-repair");
    }
    else if (verb == "journal-signs") d->journalSigns(a.rest_names());
    // M4T reseed (docs/m4t-contract.md): reply (dred-reseeded R D).
    else if (verb == "dred-reseed") d->dredReseed(a.rest_names());
    else if (verb == "begin-update")
    { const u64 n = a.natural(); a.done(); d->beginUpdateEpoch(n); }
    else if (verb == "commit-update") { a.done(); d->commitUpdateEpoch(); }
    else if (verb == "abort-update") { a.done(); d->abortUpdateEpoch(); }
    else if (verb == "update-epoch") { a.done(); d->emitUpdateEpoch(); }
    else if (verb == "update-counts-valid") { a.done(); d->emitUpdateCountsValid(); }
    // M4S slice 3: chain-reconstruct the struct tombstone dictionaries.
    else if (verb == "reconstruct-tombstones") { a.done(); d->reconstructStructTombstones(); }
    else if (verb == "exercise-signed-underflow") { a.done(); d->exerciseSignedUnderflow(); }

    // ---- pipeline positions and versions ---------------------------------
    // Positional re-entry (0.C): the next stratum push binds the
    // P-environment, or an explicit ((REL VERSION-ID) ...) instance.
    else if (verb == "bind-at") { const u32 p = a.position(); a.done(); d->bindAt(p); }
    else if (verb == "bind-instance")
    {
        const u32 pos = a.position();
        const SExp& l = a.item(); a.done();
        if (l.kind != SExp::K::list) throw Malformed{};
        std::vector<std::pair<std::string, u64>> bindings;
        for (const SExp& b : l.children)
        {
            if (b.kind != SExp::K::list || b.children.size() != 2)
                throw Malformed{};
            bindings.emplace_back(Args::name_of(b.children[0]),
                                  Args::u64_of(b.children[1]));
        }
        d->bindInstance(pos, bindings);
    }
    else if (verb == "transient-stratum") { a.done(); d->armTransientStratum(); }
    else if (verb == "maintenance-stratum") { a.done(); d->armMaintenanceStratum(); }
    else if (verb == "clear-rel-at")
    {
        const auto rel = a.name(); const u32 p = a.position(); a.done();
        d->clearRelationAt(rel, p);
    }
    else if (verb == "refresh-version")
    {
        const auto rel = a.name(); const u32 ord = a.position(); a.done();
        d->refreshVersion(rel, ord);
    }
    // (import-delta DIR ((SRC DEST) ...) [POS]): a mini database as a bulk
    // batch, renamed, at the tip or anchored at POS (§0.3 transport 2).
    else if (verb == "import-delta")
    {
        const auto dir = a.name();
        const auto renames = a.name_pairs();
        const s64 pos = a.left() > 0 ? a.integer() : -1;
        a.done();
        d->importDelta(dir,
                       std::unordered_map<std::string, std::string>(
                           renames.begin(), renames.end()),
                       pos);
    }
    // Environment operations between segments (§0.7): replies (renamed R S
    // 0|1) / (dropped R 0|1).
    else if (verb == "rename-rel")
    {
        const auto from = a.name(); const auto to = a.name(); a.done();
        d->renameRel(from, to);
    }
    else if (verb == "drop-rel") { const auto r = a.name(); a.done(); d->dropRel(r); }
    // Segment boundary (§0.4-§0.5): rebind each written, already-bound name
    // to a new version.  Replies (segment P N).
    else if (verb == "begin-segment") d->beginSegment(a.rest_names());
    else if (verb == "begin-segment/keyed")
    {
        const auto pairs = a.name_pairs(); a.done();
        d->beginSegment(pairs);
    }
    // An input-only successor version at the tip, keyed VERSION-KEY.
    else if (verb == "inject-version")
    {
        const auto rel = a.name(); const auto key = a.name(); a.done();
        d->injectVersion(rel, key);
    }

    // ---- introspection (read-only; safe while suspended) -------------------
    else if (verb == "pipeline") { a.done(); d->emitPipeline(); }
    else if (verb == "sizes-at") { const u32 p = a.position(); a.done(); d->emitSizesAt(p); }
    // A point query: does a row of REL match the storage-order prefix?
    else if (verb == "lookup")
    {
        const auto rel = a.name();
        const auto q = a.rest_values();
        d->emit("(found " + rel + " "
                + (has_prefix(db->getRelation(rel), q) ? "1" : "0") + ")");
    }
    else if (verb == "lookup-at")
    {
        const auto rel = a.name(); const u32 pos = a.position();
        const auto q = a.rest_values();
        d->emit("(found-at " + rel + " " + std::to_string(pos) + " "
                + (has_prefix(db->getRelationAt(rel, pos), q) ? "1" : "0") + ")");
    }
    // (dump-rel REL [POS]): column 0 per tuple, for the error watcher.
    else if (verb == "dump-rel")
    {
        const auto rel = a.name();
        Relation* r = relation(d, a, rel);
        a.done();
        dump_rel(d, r);
    }
    // Full nominal rows, including a lattice's visible payload.
    else if (verb == "dump-tuples")
    {
        const auto rel = a.name(); a.done();
        Relation* r = db->getRelation(rel);
        size_t n = 0;
        if (r) Database::forEachNominal(r, [&](const u64* row) {
            std::string line = "(tuplerow";
            for (u16 c = 0; c < r->getArity(); ++c)
                line += " " + db->writeValCSV(row[c]);
            d->emit(line + ")");
            ++n;
        });
        d->emit("(tupledone " + std::to_string(n) + ")");
    }
    // The value adapter (repl.md §1): rows as structured cell records
    // (encoded word, kind, struct id, TypeKey, rendering), so a client can
    // mint a checked #N handle without parsing display text.
    else if (verb == "dump-cells")
    {
        const auto rel = a.name(); a.done();
        Relation* r = db->getRelation(rel);
        size_t n = 0;
        if (r) Database::forEachNominal(r, [&](const u64* row) {
            std::string line = "(cellrow";
            for (u16 c = 0; c < r->getArity(); ++c)
                line += " " + db->describeValue(row[c]);
            d->emit(line + ")");
            ++n;
        });
        d->emit("(cellsdone " + std::to_string(n) + ")");
    }
    // M5 diagnostics: a struct relation's raw live ids and tombstone count.
    else if (verb == "dump-ids")
    {
        const auto rel = a.name(); a.done();
        Relation* r = db->getRelation(rel);
        size_t n = 0;
        if (r) Database::forEachNominal(r, [&](const u64* row) {
            d->emit("(idrow " + std::to_string(row[0]) + ")");
            ++n;
        });
        d->emit("(idsdone " + std::to_string(n) + " "
                + std::to_string(r ? r->tombstoneCount() : 0) + ")");
    }
    // Per-relation id-free content signature (docs/db-compression.md P1.3).
    else if (verb == "signature")
    {
        const auto rels = a.rest_names();
        if (rels.empty()) throw Malformed{};
        for (const auto& name : rels)
        {
            Relation* r = db->getRelation(name);
            if (!r) continue;
            const auto sg = db->signatureOf(r);
            d->emit("(sig " + name + " " + std::to_string(sg.first) + " "
                    + std::format("{:016x}", sg.second) + ")");
        }
        d->emit("(sig-end)");
    }
    else if (verb == "sizes")
    {
        a.done();
        size_t n = 0;
        for (const auto& kv : sorted_relations(d))
            if (kv.second->getAnyIndex())
            {
                d->emit("(relation_size " + kv.first + " "
                        + std::to_string(kv.second->tupleCount()) + ")");
                ++n;
            }
        d->emit("(sizes-end " + std::to_string(n) + ")");
    }
    // Schema truth from the live db (docs/finish-collections.md §B): what
    // writeDatabaseBIN would persist -- indexed, non-empty relations.
    else if (verb == "schema")
    {
        a.done();
        for (const auto& kv : sorted_relations(d))
        {
            Relation* r = kv.second;
            if (!r->getAnyIndex() || r->isEmpty()) continue;
            const std::string arity = std::to_string(r->getArity());
            if (r->getStructId() > 0)
                d->emit("(schema-rel struct " + kv.first + " " + arity + " "
                        + std::to_string(r->getStructId()) + ")");
            else if (r->isLattice())
                d->emit("(schema-rel lat " + kv.first + " " + arity + " "
                        + r->latticeSpec() + ")");
            else
                d->emit("(schema-rel table " + kv.first + " " + arity + ")");
        }
        d->emit("(schema-end)");
    }

    // ---- counts (docs/incremental.md §8B) ---------------------------------
    // Counts are recomputable cache: dropping all of them is the cheap
    // "uncounted" transition.
    else if (verb == "clear-counts")
    {
        a.done();
        for (Relation* r : db->allVersions())
            if (r) r->clearCounts();
        d->emit("(counts-cleared)");
    }
    else if (verb == "begin-count-epoch" || verb == "commit-count-epoch"
             || verb == "abort-count-epoch")
    {
        std::vector<u64> vids;
        while (a.left() > 0) vids.push_back(a.natural());
        if (verb == "begin-count-epoch") d->beginCountEpoch(vids);
        else if (verb == "commit-count-epoch") d->commitCountEpoch(vids);
        else d->abortCountEpoch(vids);
    }
    else if (verb == "cover-count-writer")
    { const u32 scc = a.position(); a.done(); d->coverCountWriter(scc); }
    // Close one count-round walk (M0.3): the named relations' versions
    // become counted; other touched sidecars are dropped.
    else if (verb == "mark-counted")
    {
        db->markCounted(set_of<std::set<std::string>>(a.rest_names()));
        d->emit("(marked-counted)");
    }
    else if (verb == "count-state") { a.done(); d->emit(db->countStateSexpr()); }
    else if (verb == "lattice-contributor-state")
    { a.done(); d->emit(db->latticeContributorStateSexpr()); }
    else if (verb == "rank-witness-state") { a.done(); d->emit(db->rankWitnessStateSexpr()); }
    else if (verb == "count-capabilities") { a.done(); d->emit(db->countCapabilitiesSexpr()); }
    else if (verb == "count-test-max")
    {
        const u64 n = a.natural(); a.done();
        for (Relation* r : db->allVersions())
            if (r) r->setCountTestMax(n);
        d->emit("(count-test-max " + std::to_string(n) + ")");
    }
    else if (verb == "input-ledger")
    {
        a.done();
        size_t n = 0;
        for (Relation* r : db->allVersions())
        {
            if (!r || r->isCompilerTemporary()) continue;
            const auto ledger = [&](const char* kind, const auto& rows) {
                for (const auto& row : rows)
                {
                    std::string line = std::string("(inputledger ") + kind + " "
                        + std::to_string(r->getVersionId()) + " " + r->getName();
                    for (u64 v : row) line += " " + db->writeValCSV(v);
                    d->emit(line + ")");
                    ++n;
                }
            };
            ledger("direct", r->directInputRows());
            ledger("mask", r->inheritanceMaskRows());
        }
        d->emit("(inputledger-done " + std::to_string(n) + ")");
    }
    else if (verb == "dump-all-counts")
    {
        a.done();
        size_t n = 0;
        for (Relation* r : db->allVersions())
        {
            if (!r || r->isCompilerTemporary() || !r->isCounted()
                || !r->getCountSidecar())
                continue;
            Index** side = r->getCountSidecar();
            const u16 ka = r->countKeyArity();
            for (u16 b = 0; b < bucket_count; ++b)
                side[b]->forEach([&](const u64* row) {
                    std::string line = "(vcountrow "
                        + std::to_string(r->getVersionId());
                    for (u16 c = 0; c < ka; ++c)
                        line += " " + db->writeValCSV(row[c]);
                    const u64 w = row[ka];
                    line += " " + std::to_string(cnt_input(w) ? 1 : 0) + " "
                          + std::to_string(cnt_nonrec(w)) + " "
                          + std::to_string(cnt_rec(w)) + ")";
                    d->emit(line);
                    ++n;
                });
        }
        d->emit("(vcountdone " + std::to_string(n) + ")");
    }
    // (dump-counts REL [POS]) / (dump-ranks REL [POS])
    else if (verb == "dump-counts" || verb == "dump-ranks")
    {
        const auto rel = a.name();
        Relation* r = relation(d, a, rel);
        a.done();
        if (verb == "dump-counts") dump_counts(d, rel, r);
        else dump_ranks(d, rel, r);
    }
    else
        return false;
    return true;
}

} // namespace

bool dispatch(Daemon* d, const sexp::SExp& form, const std::string& verb)
{
    Args args{d, form.children};
    try
    {
        return run(d, verb, args);
    }
    catch (const Malformed&)
    {
        d->refuseCommand("parse", "(verb " + verb + ") (detail \"malformed "
                         "arguments\")");
        return true;
    }
}

} // namespace actions
} // namespace slog
