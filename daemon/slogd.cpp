/** Slog Daemon
 *
 * A multi-threaded backend for the deductive database and language Slog.
 *
 * The client protocol is one line per message, dispatched dual-stack
 * (docs/t0-contract.md, "One protocol, two stacks"):
 *
 *   - a line beginning `(` is an S-expression COMMAND (protocol.h reader;
 *     dispatch below) -- typed replies, typed refusals
 *     (refused <class> <generation> <detail>...), and record streams ending
 *     in a sentinel;
 *   - anything else is a PATH to a plugin shared object.  Each plugin is
 *     dlopen'd and its
 *
 *         extern "C" void slog_plugin(slog::Daemon*)
 *
 *     called with the daemon object (daemon.h) -- the API through which
 *     plugins push strata of rules, run the pipeline, read/write the
 *     database on disk, inspect relations, and send results back over the
 *     connection.  Anything the command layer does not yet express, a
 *     client obtains by compiling a (tiny, cached) plugin and sending its
 *     path.
 *
 * Two transports sharing ONE dispatch:
 *
 *   slogd [-t N]           lines from stdin, responses to stdout (used by
 *                          the compiler driver, compiler/runslog.rkt)
 *   slogd [-t N] -p PORT   connect back to a TCP parent on PORT (used by
 *                          the interactive console, daemon/slogd.rkt).  A 2s
 *                          idle heartbeat emits (pending); the
 *                          transport-level (close) line is answered with
 *                          (bye <unixtime>) before exiting.
 *
 * -t N sets the worker thread count (default 6).
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2023-2025
 * Some rights reserved. See License.md for details.
 *
 ******************************/

#include "daemon.h"
#include "plan-count.h"
#include "protocol.h"
#include "query.h"

#include <dlfcn.h>
#include <algorithm>
#include <cctype>
#include <charconv>
#include <initializer_list>
#include <limits>
#include <string>
#include <string_view>
#include <vector>
#include <map>
#include <memory>
#include <cstring>
#include <chrono>
#include <functional>
#include <filesystem>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <poll.h>
#include <cerrno>

// Constants
namespace {
    constexpr u32 MIN_THREADS = 1;
    constexpr u32 MAX_THREADS = 256;
    // Dynamic default worker-thread count: one fewer than the machine's
    // processor count, leaving headroom for the OS (and, when the compiler
    // driver launches us, the concurrent Racket build pool).  Overridable with
    // -t, and -- via the front end's slog config system -- SLOG_THREADS, which
    // the driver turns into an explicit -t (compiler/tools.rkt slogd-argv).
    // omp_get_num_procs() returns the processor count OpenMP will actually use.
    u32 default_num_threads() {
        int np = omp_get_num_procs();
        u32 d = (np > 1) ? (u32)(np - 1) : 1u;
        return std::min(std::max(d, MIN_THREADS), MAX_THREADS);
    }
}

static void send_msg(int sock, const std::string& msg)
{
    send(sock, msg.c_str(), msg.length(), 0);
}

// Acknowledge a graceful shutdown with the current unix time.
static void send_bye(int sock)
{
    auto now = std::chrono::system_clock::now();
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();
    send_msg(sock, "(bye " + std::to_string(seconds) + ")");
}

// Load and invoke one plugin.  The dlopen handle is retained (vtables of
// objects the plugin created live in the .so, so it must outlive them).
static void run_plugin(slog::Daemon* d,
                       const std::string& path,
                       std::vector<void*>& so_handles)
{
    // SLOG_OPT=interp sends the canonical normal/delta `.plan` itself. Its
    // installer owns declarations and tasks, so intercept before the shared
    // object's existence check and dlopen path.
    if (slog::interp::maybe_interp_plan_plugin(d, path))
        return;
    // Flavored interpreter routing (counted-interp-contract.md slice 4):
    // by default every flavored plugin (`_count`, `_maint*`) installs its
    // sealed sidecar plan through the production interpreter seam instead
    // of dlopen; SLOG_FLAVORED_NATIVE restores the native artifact as the
    // differential's second executor.
    if (slog::interp::maybe_interp_count_plugin(d, path))
        return;
    if (!std::filesystem::is_regular_file(path))
    {
        d->emit("(error \"no such plugin: " + path + "\")");
        return;
    }
    void* h = dlopen(path.c_str(), RTLD_LAZY);
    if (h == 0)
    {
        d->emit(std::string("(error \"failed to load plugin: ") + dlerror() + "\")");
        return;
    }
    so_handles.push_back(h);
    auto entry = (void (*)(slog::Daemon*))dlsym(h, "slog_plugin");
    if (entry == 0)
    {
        d->emit("(error \"no slog_plugin() in " + path + "\")");
        return;
    }
    entry(d);
}

// ===================  T0 command layer (docs/t0-contract.md)  ===============
//
// Every command answers with exactly one structured reply, or a record stream
// ending in a sentinel.  Refusals are typed --
//     (refused <class> <generation> <detail>...)
// -- including dispatcher parse/routing, provisional builder state, exact
// plan parse/seal classes, and Daemon-owned entry/suspension admission.
// <generation> is the unified generation token (Daemon::commandGeneration;
// execution-tiers §2.2).

static void refuse(slog::Daemon* d, const char* cls, const std::string& details)
{
    d->refuseCommand(cls, details);
}

static bool symbol_safe(const std::string& s)
{
    if (s.empty()) return false;
    for (const char c : s)
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
              || (c >= '0' && c <= '9')
              || std::strchr("-_+*/<=>!?.:$%&^~@", c)))
            return false;
    return true;
}

// T0(b)'s builder store is connection-scoped, beside (not inside) the
// database.  EOF/connection loss therefore destroys every unsealed object,
// while sealed SCC plans may be referenced by more than one later stratum in
// the same session.  ABI 1 begins an SCC from one canonical sidecar; T0(c)'s
// rule-meta/rule-def assembly can become another kernel-plan source without
// changing this stratum lifecycle.
struct ProvisionalScc
{
    std::string sidecar;
};

struct ProvisionalStratum
{
    slog::EntryMode entry;
    std::vector<std::string> sccs;
};

struct ActiveCommandQuery
{
    std::string id;
    std::string boundary_key;
    // R2 cell previews: render row values to this nesting budget (0 =
    // unlimited); a cut subtree prints as "..." and the client keeps the
    // cell's word to ask deeper.
    u32 render_depth = 0;
    std::unique_ptr<slog::query::Context> context;
};

struct CommandBuilders
{
    std::map<std::string, ProvisionalScc> provisional_sccs;
    std::map<std::string,
             std::shared_ptr<const slog::interp::SealedKernelPlan>> sealed_sccs;
    std::map<std::string, ProvisionalStratum> provisional_strata;
    // Q1 v1 admits one read-only cursor per database.  Keeping its client id
    // and continuation here makes the cursor connection-scoped just like the
    // T0 builders: EOF/cable loss discards it rather than leaking server state.
    std::unique_ptr<ActiveCommandQuery> active_query;
};

using CommandFields =
    std::map<std::string, const slog::sexp::SExp*>;

static bool collect_fields(const slog::sexp::SExp& form, size_t first,
                           std::initializer_list<const char*> allowed,
                           CommandFields& fields, std::string& error)
{
    for (size_t i = first; i < form.children.size(); ++i)
    {
        const auto& field = form.children[i];
        if (field.kind != slog::sexp::SExp::K::list
            || field.children.empty()
            || field.children[0].kind != slog::sexp::SExp::K::atom)
        {
            error = "builder fields must be nonempty keyed lists";
            return false;
        }
        const std::string& key = field.children[0].text;
        bool admitted = false;
        for (const char* candidate : allowed)
            if (key == candidate) { admitted = true; break; }
        if (!admitted)
        {
            error = "unexpected builder field: " + key;
            return false;
        }
        if (!fields.emplace(key, &field).second)
        {
            error = "duplicate builder field: " + key;
            return false;
        }
    }
    return true;
}

static bool parse_u64_atom(const slog::sexp::SExp& value, u64& out)
{
    if (value.kind != slog::sexp::SExp::K::atom || value.text.empty())
        return false;
    const char* begin = value.text.data();
    const char* end = begin + value.text.size();
    const auto result = std::from_chars(begin, end, out);
    return result.ec == std::errc() && result.ptr == end;
}

static bool parse_generation(const CommandFields& fields, u64& generation)
{
    auto it = fields.find("generation");
    if (it == fields.end()) return false;
    const auto& field = *it->second;
    return field.children.size() == 2
        && parse_u64_atom(field.children[1], generation);
}

static bool parse_object_id(const slog::sexp::SExp& value, std::string& id)
{
    if (value.kind != slog::sexp::SExp::K::atom
        || !symbol_safe(value.text))
        return false;
    id = value.text;
    return true;
}

static bool parse_string_value(const slog::sexp::SExp& value,
                               std::string& out)
{
    if (value.kind != slog::sexp::SExp::K::string || value.text.empty())
        return false;
    out = value.text;
    return true;
}

static bool parse_optional_string(const slog::sexp::SExp& value,
                                  std::string& out)
{
    if (value.kind == slog::sexp::SExp::K::atom && value.text == "#f")
    {
        out.clear();
        return true;
    }
    return parse_string_value(value, out);
}

static bool qname_component_safe(const std::string& component)
{
    if (component.empty()
        || !((component[0] >= 'A' && component[0] <= 'Z')
             || (component[0] >= 'a' && component[0] <= 'z')
             || (component[0] >= '0' && component[0] <= '9')
             || component[0] == '_'))
        return false;
    for (char c : component)
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
              || (c >= '0' && c <= '9') || c == '_' || c == '\''))
            return false;
    return true;
}

// The wire retains QName components structurally.  Lowering joins them once
// after validation; no daemon path splits dotted names.
static bool parse_qname(const slog::sexp::SExp& value, std::string& out)
{
    if (value.kind != slog::sexp::SExp::K::list
        || value.children.size() < 2
        || value.children[0].kind != slog::sexp::SExp::K::atom
        || value.children[0].text != "qname")
        return false;
    out.clear();
    for (size_t i = 1; i < value.children.size(); ++i)
    {
        const auto& component = value.children[i];
        if (component.kind != slog::sexp::SExp::K::string
            || !qname_component_safe(component.text))
            return false;
        if (!out.empty()) out.push_back('.');
        out += component.text;
    }
    return true;
}

namespace {
constexpr u64 QUERY_MAX_PAGE_SIZE = 10000;
constexpr u64 QUERY_STEP_BUDGET = 100000;
constexpr u64 QUERY_CURSOR_WORK_BUDGET = 4096;
}

static void refuse_query_parse(slog::Daemon* d, const std::string& verb,
                               const std::string& detail)
{
    refuse(d, "parse", "(verb " + verb + ") (detail "
           + slog::protocol::quoteString(detail) + ")");
}

static void refuse_query_state(slog::Daemon* d, const std::string& verb,
                               const std::string& id,
                               const std::string& detail)
{
    refuse(d, "query-state", "(verb " + verb + ") (query " + id
           + ") (detail " + slog::protocol::quoteString(detail) + ")");
}

static bool parse_query_id(slog::Daemon* d, const std::string& verb,
                           const slog::sexp::SExp& value, std::string& id)
{
    if (parse_object_id(value, id)) return true;
    refuse_query_parse(d, verb, "query id must be a protocol-safe symbol");
    return false;
}

static bool parse_query_page(slog::Daemon* d, const std::string& verb,
                             const slog::sexp::SExp& field, u64& page_size)
{
    if (field.kind != slog::sexp::SExp::K::list
        || field.children.size() != 2
        || field.children[0].kind != slog::sexp::SExp::K::atom
        || field.children[0].text != "page"
        || !parse_u64_atom(field.children[1], page_size))
    {
        refuse_query_parse(d, verb, "expected (page N)");
        return false;
    }
    if (page_size == 0 || page_size > QUERY_MAX_PAGE_SIZE)
    {
        refuse(d, "query-pagination", "(verb " + verb + ") (page "
               + std::to_string(page_size) + ") (maximum "
               + std::to_string(QUERY_MAX_PAGE_SIZE) + ")");
        return false;
    }
    return true;
}

// Optional (depth D) field on query/query-page: 1..4096 (the render guard's
// bound); omitted keeps the query's current budget, and a query that never
// names one renders unbudgeted.
static bool parse_query_depth(slog::Daemon* d, const std::string& verb,
                              const slog::sexp::SExp& field, u32& depth)
{
    u64 value = 0;
    if (field.kind != slog::sexp::SExp::K::list
        || field.children.size() != 2
        || field.children[0].kind != slog::sexp::SExp::K::atom
        || field.children[0].text != "depth"
        || !parse_u64_atom(field.children[1], value)
        || value == 0 || value > 4096)
    {
        refuse_query_parse(d, verb, "expected (depth N) with N in 1..4096");
        return false;
    }
    depth = (u32)value;
    return true;
}

static const char* query_status_name(slog::query::Status status)
{
    switch (status)
    {
        case slog::query::Status::page:      return "page";
        case slog::query::Status::paused:    return "paused";
        case slog::query::Status::complete:  return "complete";
        case slog::query::Status::cancelled: return "cancelled";
    }
    return "cancelled";
}

static slog::query::Admission query_admission(slog::Database* db)
{
    // Commands are dispatched synchronously between continue calls, so the
    // live RunState observations are idle, the two parked read snapshots,
    // and (T5) the pre-commit gate park -- masters immutable in all four
    // (execution-tiers §6.3).  The write_or_intern refusal label remains
    // unreachable from this dispatcher by design; do not fabricate it.
    if (!db->isSuspended()) return slog::query::Admission::idle;
    if (db->suspendPosition() == slog::RUN_READ_COMPLETE)
        return slog::query::Admission::read_complete;
    return db->suspendPosition() == slog::RUN_MID_READ
         ? slog::query::Admission::mid_read
         : slog::query::Admission::boundary;
}

static std::string_view query_payload(const std::string& line,
                                      const slog::sexp::SExp& form)
{
    const size_t begin = form.children[2].offset;
    size_t end = form.children[3].offset;
    while (end > begin
           && std::isspace(static_cast<unsigned char>(line[end - 1])))
        --end;
    return std::string_view(line).substr(begin, end - begin);
}

static void emit_query_page(slog::Daemon* d, CommandBuilders& state,
                            slog::query::Page page)
{
    const std::string id = state.active_query->id;
    for (const auto& row : page.rows)
    {
        // One CELL record per projected column (the repl.md §1 value
        // adapter): the encoded word is the value's identity inside this
        // evaluation, so the client can mint a checked #N handle; the text
        // is the ordinary N3-C boundary-aware rendering, cut to the
        // requested preview depth.  Plain strings alone would strand the
        // client at whatever depth we happened to print.
        std::string record = "(query-row " + id + " (cells";
        for (u64 value : row)
            record += " " + d->db()->describeValue(
                value, state.active_query->boundary_key,
                state.active_query->render_depth);
        d->emit(record + "))");
    }
    d->emit("(query-end " + id + " " + query_status_name(page.status)
            + " (rows " + std::to_string(page.rows.size()) + ") (matched "
            + std::to_string(page.matched) + "))");
    if (page.status == slog::query::Status::complete
        || page.status == slog::query::Status::cancelled)
        state.active_query.reset();
}

static void emit_next_query_page(slog::Daemon* d, CommandBuilders& state,
                                 u64 page_size)
{
    slog::query::Page page = state.active_query->context->next(
        page_size, QUERY_STEP_BUDGET, QUERY_CURSOR_WORK_BUDGET);
    emit_query_page(d, state, std::move(page));
}

static bool dispatch_query_command(slog::Daemon* d, CommandBuilders& state,
                                   const slog::sexp::SExp& form,
                                   const std::string& line,
                                   const std::string& verb)
{
    if (verb != "query" && verb != "query-page" && verb != "query-cancel")
        return false;

    const size_t argc = form.children.size() - 1;
    const size_t expected = verb == "query" ? 3
                          : verb == "query-page" ? 2 : 1;
    const bool depth_allowed = verb != "query-cancel";
    if (argc != expected && !(depth_allowed && argc == expected + 1))
    {
        refuse_query_parse(d, verb,
            verb == "query"
              ? "expected (query ID QUERY_PLAN (page N) [(depth N)])"
              : verb == "query-page"
                  ? "expected (query-page ID (page N) [(depth N)])"
                  : "expected (query-cancel ID)");
        return true;
    }

    std::string id;
    if (!parse_query_id(d, verb, form.children[1], id))
        return true;

    if (verb == "query-cancel")
    {
        if (!state.active_query || state.active_query->id != id)
        {
            refuse_query_state(d, verb, id, "no active query with this id");
            return true;
        }
        const u64 matched = state.active_query->context->matched();
        state.active_query->context->cancel();
        d->emit("(query-end " + id
                + " cancelled (rows 0) (matched "
                + std::to_string(matched) + "))");
        state.active_query.reset();
        return true;
    }

    u64 page_size = 0;
    const size_t page_field = verb == "query" ? 3 : 2;
    if (!parse_query_page(d, verb, form.children[page_field], page_size))
        return true;
    u32 render_depth = 0;
    const bool depth_given = argc == expected + 1;
    if (depth_given
        && !parse_query_depth(d, verb, form.children[page_field + 1],
                              render_depth))
        return true;

    if (verb == "query-page")
    {
        if (!state.active_query || state.active_query->id != id)
        {
            refuse_query_state(d, verb, id, "no active query with this id");
            return true;
        }
        if (depth_given)
            state.active_query->render_depth = render_depth;
        try
        {
            emit_next_query_page(d, state, page_size);
        }
        catch (const slog::query::Error& exception)
        {
            state.active_query.reset();
            refuse(d, slog::query::error_class(exception.kind()),
                   "(verb query-page) (query " + id + ") (detail "
                   + slog::protocol::quoteString(exception.what()) + ")");
        }
        return true;
    }

    if (state.active_query)
    {
        refuse(d, "query-admission", "(verb query) (query " + id
               + ") (active " + state.active_query->id + ")");
        return true;
    }

    try
    {
        const slog::query::DecodedPlan decoded =
            slog::query::parse_plan(query_payload(line, form));
        if (!d->checkCommandGeneration(decoded.generation, "query"))
            return true;
        slog::query::SealedRequest sealed = slog::query::seal(decoded);
        auto bound = slog::query::bind(sealed, *d->db());
        auto active = std::make_unique<ActiveCommandQuery>();
        active->id = id;
        active->boundary_key = sealed.boundary_key;
        active->render_depth = render_depth;
        active->context = std::make_unique<slog::query::Context>(
            *d->db(), std::move(bound), query_admission(d->db()));
        state.active_query = std::move(active);
        emit_next_query_page(d, state, page_size);
    }
    catch (const slog::query::Error& exception)
    {
        state.active_query.reset();
        refuse(d, slog::query::error_class(exception.kind()),
               "(verb query) (query " + id + ") (detail "
               + slog::protocol::quoteString(exception.what()) + ")");
    }
    return true;
}

static void refuse_builder_parse(slog::Daemon* d, const std::string& verb,
                                 const std::string& detail)
{
    refuse(d, "parse", "(verb " + verb + ") (detail "
           + slog::protocol::quoteString(detail) + ")");
}

static void refuse_builder_state(slog::Daemon* d, const std::string& verb,
                                 const std::string& detail)
{
    refuse(d, "builder-state", "(verb " + verb + ") (detail "
           + slog::protocol::quoteString(detail) + ")");
}

static void accept_builder(slog::Daemon* d, const std::string& verb,
                           const std::string& details)
{
    d->emit("(accepted " + verb + " "
            + std::to_string(d->commandGeneration()) + " " + details + ")");
}

static bool parse_entry_field(slog::Daemon* d,
                              const slog::sexp::SExp& field,
                              slog::EntryMode& entry)
{
    if (field.children.size() < 2
        || field.children[1].kind != slog::sexp::SExp::K::atom)
    {
        refuse_builder_parse(d, "stratum-begin",
                             "entry must name an entry mode");
        return false;
    }
    const std::string& mode = field.children[1].text;
    auto refuse_mode = [&](const std::string& detail) {
        refuse(d, "entry-mode", "(entry "
               + (symbol_safe(mode) ? mode
                                    : slog::protocol::quoteString(mode))
               + ") (detail " + slog::protocol::quoteString(detail) + ")");
        return false;
    };
    if (mode == "fresh" || mode == "resident-delta" || mode == "upgrade")
    {
        if (field.children.size() != 2)
            return refuse_mode("only resident-count accepts (at <pipeline-pos>)");
        entry = mode == "fresh" ? slog::EntryMode::fresh()
              : mode == "resident-delta" ? slog::EntryMode::residentDelta()
                                           : slog::EntryMode::upgrade();
        return true;
    }
    if (mode == "resident-count")
    {
        if (field.children.size() != 3)
            return refuse_mode("resident-count requires (at <pipeline-pos>)");
        const auto& at = field.children[2];
        u64 position = 0;
        if (at.kind != slog::sexp::SExp::K::list || at.children.size() != 2
            || at.children[0].kind != slog::sexp::SExp::K::atom
            || at.children[0].text != "at"
            || !parse_u64_atom(at.children[1], position)
            || position > std::numeric_limits<u32>::max())
            return refuse_mode("resident-count requires an unsigned 32-bit (at <pipeline-pos>)");
        entry = slog::EntryMode::residentCount(static_cast<u32>(position));
        return true;
    }
    return refuse_mode("unknown entry mode");
}

// Return true iff `verb` belongs to the active builder surface (including a
// refused invocation).  This keeps the main dispatcher single-reply: a
// runtime entry refusal is emitted by Daemon, parse/seal/state refusals here,
// and only a fully installed stratum receives an acknowledgement.
static bool dispatch_builder_command(slog::Daemon* d, CommandBuilders& state,
                                     const slog::sexp::SExp& form,
                                     const std::string& verb)
{
    const bool known = verb == "scc-begin" || verb == "scc-seal"
                    || verb == "stratum-begin"
                    || verb == "stratum-add-scc"
                    || verb == "stratum-seal";
    if (!known) return false;

    const size_t argc = form.children.size() - 1;
    const bool begin = verb == "scc-begin" || verb == "stratum-begin";
    const size_t expected_argc = begin ? 3
                               : verb == "stratum-add-scc" ? 3 : 2;
    if (argc != expected_argc)
    {
        refuse_builder_parse(d, verb, "wrong builder command arity");
        return true;
    }

    std::string id;
    if (!parse_object_id(form.children[1], id))
    {
        refuse_builder_parse(d, verb, "object id must be a protocol symbol");
        return true;
    }

    if (verb == "scc-begin")
    {
        CommandFields fields;
        std::string error;
        if (!collect_fields(form, 2, {"generation", "kernel-plan"},
                            fields, error)
            || fields.size() != 2)
        {
            refuse_builder_parse(d, verb,
                error.empty() ? "requires generation and kernel-plan fields"
                              : error);
            return true;
        }
        u64 generation = 0;
        if (!parse_generation(fields, generation))
        {
            refuse_builder_parse(d, verb,
                                 "generation must be one unsigned integer");
            return true;
        }
        const auto& kernel = *fields.at("kernel-plan");
        if (kernel.children.size() != 2
            || kernel.children[1].kind != slog::sexp::SExp::K::list
            || kernel.children[1].children.size() != 2
            || kernel.children[1].children[0].kind
                 != slog::sexp::SExp::K::atom
            || kernel.children[1].children[0].text != "sidecar"
            || kernel.children[1].children[1].kind
                 != slog::sexp::SExp::K::string
            || kernel.children[1].children[1].text.empty())
        {
            refuse_builder_parse(d, verb,
                "kernel-plan must be (kernel-plan (sidecar \"PATH\"))");
            return true;
        }
        if (!d->checkCommandGeneration(generation, verb.c_str())) return true;
        if (state.provisional_sccs.count(id) || state.sealed_sccs.count(id))
        {
            refuse_builder_state(d, verb, "SCC id already exists");
            return true;
        }
        state.provisional_sccs.emplace(
            id, ProvisionalScc{kernel.children[1].children[1].text});
        accept_builder(d, verb, "(scc " + id + ")");
        return true;
    }

    if (verb == "scc-seal")
    {
        CommandFields fields;
        std::string error;
        if (!collect_fields(form, 2, {"generation"}, fields, error)
            || fields.size() != 1)
        {
            refuse_builder_parse(d, verb,
                error.empty() ? "requires one generation field" : error);
            return true;
        }
        u64 generation = 0;
        if (!parse_generation(fields, generation))
        {
            refuse_builder_parse(d, verb,
                                 "generation must be one unsigned integer");
            return true;
        }
        if (!d->checkCommandGeneration(generation, verb.c_str())) return true;
        auto pending = state.provisional_sccs.find(id);
        if (pending == state.provisional_sccs.end())
        {
            refuse_builder_state(d, verb,
                state.sealed_sccs.count(id) ? "SCC is already sealed"
                                            : "unknown provisional SCC");
            return true;
        }
        try
        {
            const auto decoded = slog::interp::parse_kernel_plan_file(
                pending->second.sidecar);
            auto sealed = std::make_shared<const slog::interp::SealedKernelPlan>(
                slog::interp::seal_kernel_plan(decoded, d->db()));
            state.sealed_sccs.emplace(id, std::move(sealed));
            state.provisional_sccs.erase(pending);
            accept_builder(d, verb, "(scc " + id + ")");
        }
        catch (const slog::interp::PlanParseError& exception)
        {
            refuse(d, slog::interp::parse_error_class(exception.kind()),
                   "(verb scc-seal) (scc " + id + ") (offset "
                   + std::to_string(exception.offset()) + ") (detail "
                   + slog::protocol::quoteString(exception.what()) + ")");
        }
        catch (const slog::interp::SealError& exception)
        {
            refuse(d, slog::interp::seal_error_class(exception.kind()),
                   "(verb scc-seal) (scc " + id + ") (detail "
                   + slog::protocol::quoteString(exception.what()) + ")");
        }
        return true;
    }

    if (verb == "stratum-begin")
    {
        CommandFields fields;
        std::string error;
        if (!collect_fields(form, 2, {"generation", "entry"}, fields, error)
            || fields.size() != 2)
        {
            refuse_builder_parse(d, verb,
                error.empty() ? "requires generation and entry fields" : error);
            return true;
        }
        u64 generation = 0;
        if (!parse_generation(fields, generation))
        {
            refuse_builder_parse(d, verb,
                                 "generation must be one unsigned integer");
            return true;
        }
        if (!d->checkCommandGeneration(generation, verb.c_str())) return true;
        const auto& entry_field = *fields.at("entry");
        slog::EntryMode entry;
        if (!parse_entry_field(d, entry_field, entry)) return true;
        if (state.provisional_strata.count(id))
        {
            refuse_builder_state(d, verb, "stratum id already exists");
            return true;
        }
        state.provisional_strata.emplace(id, ProvisionalStratum{entry, {}});
        accept_builder(d, verb, "(stratum " + id + ")");
        return true;
    }

    if (verb == "stratum-add-scc")
    {
        std::string scc;
        if (!parse_object_id(form.children[2], scc))
        {
            refuse_builder_parse(d, verb, "SCC id must be a protocol symbol");
            return true;
        }
        CommandFields fields;
        std::string error;
        if (!collect_fields(form, 3, {"generation"}, fields, error)
            || fields.size() != 1)
        {
            refuse_builder_parse(d, verb,
                error.empty() ? "requires one generation field" : error);
            return true;
        }
        u64 generation = 0;
        if (!parse_generation(fields, generation))
        {
            refuse_builder_parse(d, verb,
                                 "generation must be one unsigned integer");
            return true;
        }
        if (!d->checkCommandGeneration(generation, verb.c_str())) return true;
        auto stratum = state.provisional_strata.find(id);
        if (stratum == state.provisional_strata.end())
        {
            refuse_builder_state(d, verb, "unknown provisional stratum");
            return true;
        }
        if (!state.sealed_sccs.count(scc))
        {
            refuse_builder_state(d, verb,
                state.provisional_sccs.count(scc) ? "SCC is not sealed"
                                                  : "unknown sealed SCC");
            return true;
        }
        if (std::find(stratum->second.sccs.begin(), stratum->second.sccs.end(),
                      scc) != stratum->second.sccs.end())
        {
            refuse_builder_state(d, verb, "SCC is already attached");
            return true;
        }
        stratum->second.sccs.push_back(scc);
        accept_builder(d, verb,
                       "(stratum " + id + ") (scc " + scc + ")");
        return true;
    }

    CommandFields fields;
    std::string error;
    if (!collect_fields(form, 2, {"generation"}, fields, error)
        || fields.size() != 1)
    {
        refuse_builder_parse(d, verb,
            error.empty() ? "requires one generation field" : error);
        return true;
    }
    u64 generation = 0;
    if (!parse_generation(fields, generation))
    {
        refuse_builder_parse(d, verb, "generation must be one unsigned integer");
        return true;
    }
    if (!d->checkCommandGeneration(generation, verb.c_str())) return true;
    auto stratum = state.provisional_strata.find(id);
    if (stratum == state.provisional_strata.end())
    {
        refuse_builder_state(d, verb, "unknown provisional stratum");
        return true;
    }
    if (stratum->second.sccs.empty())
    {
        refuse_builder_state(d, verb, "stratum has no sealed SCC");
        return true;
    }
    if (stratum->second.sccs.size() != 1)
    {
        refuse(d, "capability", "(verb stratum-seal) (detail "
               + slog::protocol::quoteString(
                   "ABI 1 sidecar strata contain exactly one SCC") + ")");
        return true;
    }
    const std::string scc = stratum->second.sccs.front();
    try
    {
        const auto sealed = state.sealed_sccs.at(scc);
        if (!slog::interp::install_command_stratum(
                d, id, stratum->second.entry, *sealed))
            return true;
        state.provisional_strata.erase(stratum);
        accept_builder(d, verb,
                       "(stratum " + id + ") (scc " + scc + ")");
    }
    catch (const slog::interp::SealError& exception)
    {
        refuse(d, slog::interp::seal_error_class(exception.kind()),
               "(verb stratum-seal) (stratum " + id + ") (detail "
               + slog::protocol::quoteString(exception.what()) + ")");
    }
    return true;
}

static void refuse_boundary_parse(slog::Daemon* d, const std::string& verb,
                                  const std::string& detail)
{
    refuse(d, "parse", "(verb " + verb + ") (detail "
           + slog::protocol::quoteString(detail) + ")");
}

static bool singleton_field(const CommandFields& fields, const char* key,
                            const slog::sexp::SExp*& value)
{
    auto it = fields.find(key);
    if (it == fields.end() || it->second->children.size() != 2)
        return false;
    value = &it->second->children[1];
    return true;
}

static bool parse_boundary_declaration(
    const slog::sexp::SExp& form, slog::BoundaryCatalogDecl& out,
    std::string& error)
{
    if (form.kind != slog::sexp::SExp::K::list
        || form.children.empty()
        || form.children[0].kind != slog::sexp::SExp::K::atom
        || form.children[0].text != "declare")
    {
        error = "declarations must contain (declare ...) records";
        return false;
    }
    CommandFields fields;
    if (!collect_fields(form, 1,
          {"qname", "kind", "arity", "type-key", "lat-spec", "shape"},
          fields, error)
        || fields.size() != 6)
    {
        if (error.empty()) error = "declare requires six keyed fields";
        return false;
    }
    const slog::sexp::SExp* value = nullptr;
    // the qname field IS the structured name -- multi-component paths make
    // it wider than a singleton field (N3-D qualified declarations)
    if (!parse_qname(*fields.at("qname"), out.name))
    {
        error = "declare requires a structured (qname \"component\" ...)";
        return false;
    }
    if (!singleton_field(fields, "kind", value)
        || value->kind != slog::sexp::SExp::K::atom
        || (value->text != "table" && value->text != "struct"
            && value->text != "enum" && value->text != "union"
            && value->text != "lattice" && value->text != "list"
            && value->text != "map"))
    {
        error = "declare kind is not in the N3 catalog vocabulary";
        return false;
    }
    out.kind = value->text;
    out.storage = out.kind == "table" || out.kind == "struct";

    if (!singleton_field(fields, "arity", value))
    {
        error = "declare requires one arity value";
        return false;
    }
    u64 arity = 0;
    if (value->kind == slog::sexp::SExp::K::atom && value->text == "#f")
    {
        if (out.storage)
        {
            error = "storage declaration arity cannot be #f";
            return false;
        }
    }
    else if (!parse_u64_atom(*value, arity)
             || arity > std::numeric_limits<u16>::max())
    {
        error = "declare arity must be #f or an unsigned 16-bit integer";
        return false;
    }
    out.arity = (u16)arity;
    if (!singleton_field(fields, "type-key", value)
        || !parse_optional_string(*value, out.type_key)
        || !singleton_field(fields, "lat-spec", value)
        || !parse_optional_string(*value, out.lat_spec)
        || !singleton_field(fields, "shape", value)
        || !parse_string_value(*value, out.shape))
    {
        error = "declare TypeKey/lat-spec/shape fields are malformed";
        return false;
    }
    return true;
}

static bool parse_boundary_action(
    const slog::sexp::SExp& form, slog::BoundaryRelationAction& out,
    std::string& error)
{
    if (form.kind != slog::sexp::SExp::K::list
        || form.children.empty()
        || form.children[0].kind != slog::sexp::SExp::K::atom)
    {
        error = "actions must be nonempty records";
        return false;
    }
    const std::string& kind = form.children[0].text;
    CommandFields fields;
    if (kind == "internal-create")
    {
        if (!collect_fields(form, 1, {"name", "version-key"}, fields, error)
            || fields.size() != 2)
        {
            if (error.empty())
                error = "internal-create requires name and VersionKey";
            return false;
        }
        const slog::sexp::SExp* value = nullptr;
        if (!singleton_field(fields, "name", value)
            || !parse_string_value(*value, out.name)
            || !singleton_field(fields, "version-key", value)
            || !parse_string_value(*value, out.version_key))
        {
            error = "internal-create fields are malformed";
            return false;
        }
        out.kind = slog::BoundaryActionK::internal_create;
        return true;
    }
    if (kind != "retain" && kind != "create")
    {
        error = "action kind must be retain, create, or internal-create";
        return false;
    }
    if (!collect_fields(form, 1,
          {"qname", "version-key", "predecessor", "type-key"},
          fields, error)
        || fields.size() != 4)
    {
        if (error.empty()) error = "relation action requires four keyed fields";
        return false;
    }
    const slog::sexp::SExp* value = nullptr;
    // as with declare: a qualified action name is not a singleton field
    if (!parse_qname(*fields.at("qname"), out.name)
        || !singleton_field(fields, "version-key", value)
        || !parse_string_value(*value, out.version_key)
        || !singleton_field(fields, "predecessor", value)
        || !parse_optional_string(*value, out.predecessor)
        || !singleton_field(fields, "type-key", value)
        || !parse_optional_string(*value, out.type_key))
    {
        error = "relation action fields are malformed";
        return false;
    }
    out.kind = kind == "retain"
      ? slog::BoundaryActionK::retain : slog::BoundaryActionK::create;
    return true;
}

static bool dispatch_boundary_command(slog::Daemon* d,
                                      const slog::sexp::SExp& form,
                                      const std::string& verb)
{
    if (verb != "prepare-boundary" && verb != "commit-boundary"
        && verb != "abort-boundary")
        return false;

    if (verb == "prepare-boundary")
    {
        CommandFields fields;
        std::string error;
        if (!collect_fields(form, 1,
              {"generation", "boundary", "program", "declarations",
               "memberships", "actions"},
              fields, error)
            || fields.size() != 6)
        {
            refuse_boundary_parse(
              d, verb, error.empty()
                ? "requires generation, boundary, program, declarations, "
                  "memberships, and actions"
                : error);
            return true;
        }
        u64 generation = 0;
        if (!parse_generation(fields, generation))
        {
            refuse_boundary_parse(d, verb,
                                   "generation must be one unsigned integer");
            return true;
        }
        if (!d->checkCommandGeneration(generation, verb.c_str())) return true;

        const slog::sexp::SExp* value = nullptr;
        std::string boundary, program;
        if (!singleton_field(fields, "boundary", value)
            || !parse_string_value(*value, boundary)
            || !singleton_field(fields, "program", value)
            || !parse_string_value(*value, program))
        {
            refuse_boundary_parse(
              d, verb, "boundary and program keys must be nonempty strings");
            return true;
        }

        std::vector<slog::BoundaryCatalogDecl> declarations;
        const auto& declaration_field = *fields.at("declarations");
        for (size_t i = 1; i < declaration_field.children.size(); ++i)
        {
            slog::BoundaryCatalogDecl declaration;
            if (!parse_boundary_declaration(
                    declaration_field.children[i], declaration, error))
            {
                refuse_boundary_parse(d, verb, error);
                return true;
            }
            declarations.push_back(std::move(declaration));
        }

        std::set<std::pair<std::string, std::string>> memberships;
        const auto& membership_field = *fields.at("memberships");
        for (size_t i = 1; i < membership_field.children.size(); ++i)
        {
            const auto& member = membership_field.children[i];
            std::string child, parent;
            if (member.kind != slog::sexp::SExp::K::list
                || member.children.size() != 3
                || member.children[0].kind != slog::sexp::SExp::K::atom
                || member.children[0].text != "member"
                || !parse_qname(member.children[1], child)
                || !parse_qname(member.children[2], parent)
                || !memberships.insert({child, parent}).second)
            {
                refuse_boundary_parse(
                  d, verb, "memberships contain a malformed or duplicate member");
                return true;
            }
        }

        std::vector<slog::BoundaryRelationAction> actions;
        const auto& action_field = *fields.at("actions");
        for (size_t i = 1; i < action_field.children.size(); ++i)
        {
            slog::BoundaryRelationAction action;
            if (!parse_boundary_action(action_field.children[i], action, error))
            {
                refuse_boundary_parse(d, verb, error);
                return true;
            }
            actions.push_back(std::move(action));
        }

        const slog::BoundaryAdmission result = d->prepareBoundary(
          boundary, program, declarations, memberships, actions);
        if (!result.ok)
            refuse(d, result.refusal_class.c_str(),
                   "(verb prepare-boundary) (boundary "
                   + slog::protocol::quoteString(boundary) + ") (detail "
                   + slog::protocol::quoteString(result.detail) + ")");
        else
            d->emit("(boundary-prepared " + std::to_string(generation)
                    + " (boundary " + slog::protocol::quoteString(boundary)
                    + ") (program " + slog::protocol::quoteString(program)
                    + ") (position " + std::to_string(result.position)
                    + ") (created " + std::to_string(result.created) + "))");
        return true;
    }

    CommandFields fields;
    std::string error;
    if (!collect_fields(form, 1, {"generation", "boundary"}, fields, error)
        || fields.size() != 2)
    {
        refuse_boundary_parse(
          d, verb, error.empty()
            ? "requires generation and boundary fields" : error);
        return true;
    }
    u64 generation = 0;
    const slog::sexp::SExp* value = nullptr;
    std::string boundary;
    if (!parse_generation(fields, generation)
        || !singleton_field(fields, "boundary", value)
        || !parse_string_value(*value, boundary))
    {
        refuse_boundary_parse(
          d, verb, "generation/boundary fields are malformed");
        return true;
    }
    if (!d->checkCommandGeneration(generation, verb.c_str())) return true;
    const slog::BoundaryAdmission result =
      verb == "commit-boundary"
        ? d->commitBoundary(boundary) : d->abortBoundary(boundary);
    if (!result.ok)
        refuse(d, result.refusal_class.c_str(),
               "(verb " + verb + ") (boundary "
               + slog::protocol::quoteString(boundary) + ") (detail "
               + slog::protocol::quoteString(result.detail) + ")");
    else if (verb == "commit-boundary")
        d->emit("(boundary-committed "
                + std::to_string(d->commandGeneration()) + " (boundary "
                + slog::protocol::quoteString(boundary) + ") (position "
                + std::to_string(result.position) + ") (created "
                + std::to_string(result.created) + "))");
    else
        d->emit("(boundary-aborted " + std::to_string(d->commandGeneration())
                + " (boundary " + slog::protocol::quoteString(boundary)
                + ") (position " + std::to_string(result.position)
                + ") (discarded " + std::to_string(result.created) + "))");
    return true;
}

// N3-D path transforms (modules.md §5.3): rename-path / drop-path are
// single-shot atomic environment events over ONE structured path syntax --
// the current environment decides leaf vs namespace.  The session supplies
// the complete post-transform catalog; the daemon verifies it is exactly
// the mechanical rewrite of the current one and applies env rebinds,
// catalog replacement, and the successor BoundarySnapshot atomically.
static bool dispatch_transform_command(slog::Daemon* d,
                                       const slog::sexp::SExp& form,
                                       const std::string& verb)
{
    const bool rename = verb == "rename-path";
    if (!rename && verb != "drop-path") return false;

    CommandFields fields;
    std::string error;
    const bool shaped = rename
      ? (collect_fields(form, 1,
           {"generation", "boundary", "from", "to",
            "declarations", "memberships"}, fields, error)
         && fields.size() == 6)
      : (collect_fields(form, 1,
           {"generation", "boundary", "path",
            "declarations", "memberships"}, fields, error)
         && fields.size() == 5);
    if (!shaped)
    {
        refuse_boundary_parse(
          d, verb, !error.empty() ? error
            : rename
              ? "requires generation, boundary, from, to, declarations, "
                "and memberships"
              : "requires generation, boundary, path, declarations, "
                "and memberships");
        return true;
    }
    u64 generation = 0;
    if (!parse_generation(fields, generation))
    {
        refuse_boundary_parse(d, verb,
                              "generation must be one unsigned integer");
        return true;
    }
    const slog::sexp::SExp* value = nullptr;
    std::string boundary;
    if (!singleton_field(fields, "boundary", value)
        || !parse_string_value(*value, boundary))
    {
        refuse_boundary_parse(d, verb, "boundary must be one BoundaryKey");
        return true;
    }
    std::string from, to, path;
    if (rename)
    {
        if (!singleton_field(fields, "from", value)
            || !parse_qname(*value, from)
            || !singleton_field(fields, "to", value)
            || !parse_qname(*value, to))
        {
            refuse_boundary_parse(
              d, verb, "from/to must be structured (qname \"component\" ...)");
            return true;
        }
    }
    else if (!singleton_field(fields, "path", value)
             || !parse_qname(*value, path))
    {
        refuse_boundary_parse(
          d, verb, "path must be a structured (qname \"component\" ...)");
        return true;
    }

    std::vector<slog::BoundaryCatalogDecl> declarations;
    const auto& declaration_field = *fields.at("declarations");
    for (size_t i = 1; i < declaration_field.children.size(); ++i)
    {
        slog::BoundaryCatalogDecl decl;
        if (!parse_boundary_declaration(declaration_field.children[i],
                                        decl, error))
        {
            refuse_boundary_parse(d, verb, error);
            return true;
        }
        declarations.push_back(std::move(decl));
    }
    std::set<std::pair<std::string, std::string>> memberships;
    const auto& membership_field = *fields.at("memberships");
    for (size_t i = 1; i < membership_field.children.size(); ++i)
    {
        const auto& member = membership_field.children[i];
        std::string child, parent;
        if (member.kind != slog::sexp::SExp::K::list
            || member.children.size() != 3
            || member.children[0].kind != slog::sexp::SExp::K::atom
            || member.children[0].text != "member"
            || !parse_qname(member.children[1], child)
            || !parse_qname(member.children[2], parent)
            || !memberships.insert({child, parent}).second)
        {
            refuse_boundary_parse(
              d, verb, "memberships contain a malformed or duplicate member");
            return true;
        }
    }
    if (!d->checkCommandGeneration(generation, verb.c_str())) return true;

    const slog::BoundaryAdmission result = rename
      ? d->renamePath(from, to, boundary, declarations, memberships)
      : d->dropPath(path, boundary, declarations, memberships);
    if (!result.ok)
    {
        refuse(d, result.refusal_class.c_str(),
               "(verb " + verb + ") (boundary "
               + slog::protocol::quoteString(boundary) + ") (detail "
               + slog::protocol::quoteString(result.detail) + ")");
        return true;
    }
    if (rename)
        d->emit("(path-renamed " + std::to_string(d->commandGeneration())
                + " (from " + slog::protocol::quoteString(from)
                + ") (to " + slog::protocol::quoteString(to)
                + ") (boundary " + slog::protocol::quoteString(boundary)
                + ") (position " + std::to_string(result.position)
                + ") (rebound " + std::to_string(result.created) + "))");
    else
        d->emit("(path-dropped " + std::to_string(d->commandGeneration())
                + " (path " + slog::protocol::quoteString(path)
                + ") (boundary " + slog::protocol::quoteString(boundary)
                + ") (position " + std::to_string(result.position)
                + ") (unbound " + std::to_string(result.created) + "))");
    return true;
}

// Reserved verb families: the parser recognizes them and answers
// `reserved-verb` -- distinct from `unknown-verb`, so a client can tell
// "not yet" from "never" (contract, "Reply and refusal doctrine").
static const char* reserved_family(const std::string& verb)
{
    struct ReservedVerb { const char* verb; const char* family; };
    // Watch management (repl.md §6 spellings, ratified 2026-07-15 -- deferred past
    // T0, slice (d) tees up the pause machinery they ride); T5 debugger
    // stepping (execution-tiers §9 sketch). Q1's canonical payload dispatcher
    // is active below; friendly R2 parsing still waits for N2/N3 identity.
    static const ReservedVerb reserved[] = {
        // `watch`/`unwatch` are live below.  `subscribe` -- the event-kind
        // filter, a separate concept from a WatchSpec -- stays reserved.
        { "subscribe",        "watch"    },
        // `replay` is LIVE below (T5 slice (c)); `resume` stays reserved --
        // the t0-ratified commit spelling is the bare (continue).
        { "resume",           "debugger" },
        { "why-not-add",      "debugger" },
        { "debug-on",         "debugger" },
        { "debug-off",        "debugger" },
    };
    for (const auto& rv : reserved)
        if (verb == rv.verb) return rv.family;
    return nullptr;
}

// The materialization facts the Q1 planner needs beside the declaration:
// one list of full-index orderings, e.g. ((0 1) (1 0)), () when index-free.
// A single-value field so assq-style readers see one datum.
static std::string catalog_orders_field(slog::Relation* r)
{
    std::string orders;
    for (const std::vector<u16>& ord : r->fullOrders())
        orders += (orders.empty() ? "(" : " (")
            + slog::Relation::ordString(ord) + ")";
    return "(" + orders + ")";
}

static std::string catalog_relation_record(
    const std::string& name, slog::Relation* r,
    const std::string& boundary_key)
{
    using slog::protocol::quoteString;
    const char* kind = r->getStructId() > 0 ? "struct"
                     : r->isLattice()       ? "lat"
                                            : "table";
    return "(catalog-rel (name " + quoteString(name) + ")"
        + " (kind " + kind + ")"
        + " (arity " + std::to_string(r->getArity()) + ")"
        + " (version-id " + std::to_string(r->getVersionId()) + ")"
        + " (version-key "
        + (r->getVersionKey().empty() ? "#f" : quoteString(r->getVersionKey())) + ")"
        + " (boundary "
        + (boundary_key.empty() ? "#f" : quoteString(boundary_key)) + ")"
        + " (evaluation "
        + (r->getEvaluationId().empty() ? "#f" : quoteString(r->getEvaluationId())) + ")"
        + " (predecessor "
        + (r->getPredecessorVersionId() == 0
             ? "#f" : std::to_string(r->getPredecessorVersionId())) + ")"
        + " (struct-id "
        + (r->getStructId() == 0 ? "#f" : std::to_string(r->getStructId())) + ")"
        + " (type-key "
        + (r->getTypeKey().empty()
             ? "#f" : quoteString(r->getTypeKey())) + ")"
        + " (lat-spec "
        + (r->isLattice() ? quoteString(r->latticeSpec()) : "#f") + ")"
        + " (size "
        + (r->getAnyIndex() ? std::to_string(r->tupleCount()) : "#f") + ")"
        + " (orders " + catalog_orders_field(r) + ")"
        + " (temp " + (r->isCompilerTemporary() ? "#t" : "#f") + "))";
}

// T5 slice (c3): the step stop's join stack.  One (frame ...) record per
// level -- the driving delta tuple first, then one per open cursor level,
// innermost last -- followed by the position record and a sentinel.  Rows
// render through the ordinary value writer, so structs, sequences and
// collections read the same here as anywhere else.
static void emit_step_frames(slog::Daemon* d)
{
    using slog::protocol::quoteString;
    slog::Database* db = d->db();
    const slog::Database::StepStop& stop = db->stepStop();
    const auto row_text = [&](const std::vector<u64>& row) {
        std::string text;
        for (u64 v : row) text += (text.empty() ? "" : " ") + db->writeValCSV(v);
        return text;
    };
    d->emit("(step-at (port " + stop.port + ") (rule "
            + std::to_string(stop.rule_id) + ") (variant "
            + std::to_string(stop.variant) + ") (op "
            + std::to_string(stop.op_index) + ") (source "
            + quoteString(stop.rule_loc) + ") (tag "
            + quoteString(stop.rule_tag) + ") (tuple "
            + quoteString(row_text(stop.tuple)) + "))");
    size_t level = 0;
    d->emit("(frame (level " + std::to_string(level++) + ") (kind drive) (row "
            + quoteString(row_text(stop.driver)) + "))");
    for (const std::vector<u64>& premise : stop.premises)
        d->emit("(frame (level " + std::to_string(level++)
                + ") (kind premise) (row " + quoteString(row_text(premise))
                + "))");
    d->emit("(frames-end " + std::to_string(level) + ")");
}

// T5 slices (d1)/(d3): one row vocabulary for the debugger verbs -- the
// QUERY payload's literal kinds plus `(word N)` for a value the client
// already holds, plus `_` where a pattern admits wildcards.  A literal the
// interner has never seen resolves false: it cannot appear in any fact, and
// that is an answer, not a parse error.
static bool parse_row_terms(slog::Daemon* d, const char* verb,
                            const slog::sexp::SExp& field, bool wildcards,
                            std::vector<u64>& row, std::vector<bool>& wild)
{
    const auto bad = [&](const char* detail) {
        refuse(d, "parse", std::string("(verb ") + verb + ") (detail "
               + slog::protocol::quoteString(detail) + ")");
        return false;
    };
    for (size_t j = 1; j < field.children.size(); ++j)
    {
        const slog::sexp::SExp& term = field.children[j];
        if (wildcards && term.kind == slog::sexp::SExp::K::atom
            && term.text == "_")
        {
            row.push_back(0);
            wild.push_back(true);
            continue;
        }
        if (term.kind != slog::sexp::SExp::K::list
            || term.children.size() != 2
            || term.children[0].kind != slog::sexp::SExp::K::atom)
            return bad(wildcards
                         ? "terms are (integer|real|string \"text\"), "
                           "(word N), or _"
                         : "terms are (integer|real|string \"text\") "
                           "or (word N)");
        const std::string& kind = term.children[0].text;
        u64 word = 0;
        if (kind == "word")
        {
            if (!parse_u64_atom(term.children[1], word))
                return bad("word takes an encoded value");
            row.push_back(word);
            wild.push_back(false);
            continue;
        }
        slog::query::Literal literal;
        if (kind == "integer") literal.kind = slog::query::LiteralK::integer;
        else if (kind == "real") literal.kind = slog::query::LiteralK::real;
        else if (kind == "string") literal.kind = slog::query::LiteralK::string;
        else return bad("unknown row term kind");
        literal.text = term.children[1].text;
        try
        {
            if (!slog::query::resolve_literal(*d->db(), literal, word))
            {
                refuse(d, "value-lookup",
                       std::string("(verb ") + verb + ") (detail "
                       + slog::protocol::quoteString(
                           "no value in this evaluation matches "
                           + literal.text)
                       + ")");
                return false;
            }
        }
        catch (const slog::query::Error& exception)
        {
            refuse(d, slog::query::error_class(exception.kind()),
                   std::string("(verb ") + verb + ") (detail "
                   + slog::protocol::quoteString(exception.what()) + ")");
            return false;
        }
        row.push_back(word);
        wild.push_back(false);
    }
    return true;
}

// T5 slice (d1): the proof tree (contract §4(d1), execution-tiers §7.4).
// One `(proof-node ...)` record per node, parented by id so the client
// renders a tree without a second grammar, then a sentinel that ECHOES the
// budgets -- §9.4's "both echo their budgets so a deeper look is one
// recall-and-edit away".  A `fact` node names what is being explained, each
// `derivation` under it names the rule variant that produced it, and its
// `premise` children are the rows that satisfied the body.  A premise with
// `(derivations 0)` is a LEAF, and honestly so: EDB, derived before the
// arming, or past a budget -- the journal knows nothing further.
struct ProofBudget
{
    u32 depth = 4;
    u32 nodes = 64;
};

static std::string proof_row_text(slog::Database* db,
                                  const std::vector<u64>& row)
{
    std::string text;
    for (u64 v : row)
        text += (text.empty() ? "" : " ") + db->writeValCSV(v);
    return text;
}

// Depth-first, budget-bounded, cycle-guarded by the ancestor path: a
// recursive rule can support a fact with a row whose own support cites it
// back, and a debugger that hangs on that is worse than one that says so.
static void emit_proof_subtree(slog::Daemon* d, const std::string& relation,
                               const std::vector<u64>& row,
                               int parent, u32 depth, const ProofBudget& budget,
                               std::vector<std::string>& path, u32& next_id,
                               bool& truncated)
{
    using slog::protocol::quoteString;
    slog::Database* db = d->db();
    const std::vector<u32> records = db->proofsFor(relation, row);
    const std::string key = slog::Database::proofKey(relation, row.data(),
                                                     row.size());
    const bool cyclic =
        std::find(path.begin(), path.end(), key) != path.end();
    if (next_id >= budget.nodes) { truncated = true; return; }
    const int self = static_cast<int>(next_id++);
    d->emit("(proof-node (id " + std::to_string(self) + ") (parent "
            + std::to_string(parent) + ") (kind "
            + (cyclic ? "cycle" : (parent < 0 ? "fact" : "premise"))
            + ") (relation " + quoteString(relation) + ") (row "
            + quoteString(proof_row_text(db, row)) + ") (derivations "
            + std::to_string(records.size()) + "))");
    if (cyclic || records.empty()) return;
    if (depth == 0) { truncated = !records.empty(); return; }
    path.push_back(key);
    for (u32 index : records)
    {
        if (next_id >= budget.nodes) { truncated = true; break; }
        const slog::Database::ProofRecord& record = db->proofRecord(index);
        const int step = static_cast<int>(next_id++);
        d->emit("(proof-node (id " + std::to_string(step) + ") (parent "
                + std::to_string(self) + ") (kind derivation) (rule "
                + std::to_string(record.rule_id) + ") (variant "
                + std::to_string(record.variant) + ") (source "
                + quoteString(record.rule_loc) + ") (tag "
                + quoteString(record.rule_tag) + "))");
        // The DRIVING row is a premise like any other -- it is half the body
        // of a delta-driven rule, and a rule whose only body position is its
        // driver would otherwise have a proof with no premises at all.  It
        // comes first, which is also the order the ports fire in.
        if (!record.driver_relation.empty() && !record.driver.empty())
          emit_proof_subtree(d, record.driver_relation, record.driver, step,
                             depth - 1, budget, path, next_id, truncated);
        for (const slog::Database::ProofPremise& premise : record.premises)
        {
            if (premise.relation.empty())
            {
                // An unlabelled row still belongs in the proof: the schema
                // could not name it, and hiding it would misrepresent the
                // body that fired.
                if (next_id >= budget.nodes) { truncated = true; break; }
                const int leaf = static_cast<int>(next_id++);
                d->emit("(proof-node (id " + std::to_string(leaf)
                        + ") (parent " + std::to_string(step)
                        + ") (kind premise) (relation \"\") (row "
                        + quoteString(proof_row_text(db, premise.row))
                        + ") (derivations 0))");
                continue;
            }
            emit_proof_subtree(d, premise.relation, premise.row, step,
                               depth - 1, budget, path, next_id, truncated);
        }
    }
    path.pop_back();
}

static void emit_proof_end(slog::Daemon* d, u32 nodes,
                           const ProofBudget& budget, bool truncated)
{
    d->emit("(proof-end " + std::to_string(nodes) + " (records "
            + std::to_string(d->db()->proofCount()) + ") (dropped "
            + std::to_string(d->db()->proofsDropped()) + ") (depth "
            + std::to_string(budget.depth) + ") (truncated "
            + (truncated ? "#t" : "#f") + "))");
}

// (catalog) / (catalog relations): one (catalog-rel ...) record per LATEST
// relation binding plus one (catalog-planned ...) record per announced-but-
// unregistered version key, name-sorted, then the (catalog-end <n>) sentinel.
// Unlike the compiled (schema) action -- which describes nonempty
// materialization -- the catalog is declaration truth: empty and index-free
// relations appear (repl.md §7).  N3-B adds the selected committed
// BoundaryKey, or #f after a legacy environment event.
// `path` empty selects everything; otherwise the record stream is the §5.3
// subtree selection -- exact member or nested under the path.
static bool catalog_path_selects(const std::string& name,
                                 const std::string& path)
{
    return path.empty() || name == path
        || slog::Database::pathInside(name, path);
}

static void emit_catalog_relations(slog::Daemon* d,
                                   const std::string& path = "")
{
    using slog::protocol::quoteString;
    std::map<std::string, slog::Relation*> sorted(
        d->db()->getRelations().begin(), d->db()->getRelations().end());
    const std::string current_boundary = d->db()->currentBoundaryKey();
    u64 n = 0;
    for (auto& kv : sorted)
    {
        slog::Relation* r = kv.second;
        if (r == nullptr || !catalog_path_selects(kv.first, path)) continue;
        const std::string boundary =
            !current_boundary.empty()
            && d->db()->getRelationAtBoundary(kv.first, current_boundary) == r
              ? current_boundary : "";
        d->emit(catalog_relation_record(kv.first, r, boundary));
        ++n;
    }
    std::map<std::string, std::string> planned(
        d->db()->plannedVersionKeys().begin(),
        d->db()->plannedVersionKeys().end());
    for (const auto& kv : planned)
    {
        if (!catalog_path_selects(kv.first, path)) continue;
        d->emit("(catalog-planned (name " + quoteString(kv.first)
                + ") (version-key " + quoteString(kv.second) + "))");
        ++n;
    }
    d->emit("(catalog-end " + std::to_string(n) + ")");
}

// N3-B direct history lookup. `(catalog boundaries)` enumerates committed
// handles in commit order; `(catalog boundary KEY)` projects the exact
// historical materialization snapshot rather than reconstructing it from
// pipeline positions.
static void emit_catalog_boundaries(slog::Daemon* d)
{
    using slog::protocol::quoteString;
    u64 n = 0;
    for (const std::string& key : d->db()->boundaryHistory())
    {
        const slog::BoundarySnapshot* boundary = d->db()->getBoundary(key);
        if (boundary == nullptr) continue;
        d->emit("(catalog-boundary (boundary " + quoteString(boundary->key)
                + ") (program " + quoteString(boundary->program_key)
                + ") (evaluation " + quoteString(boundary->evaluation_id)
                + ") (position " + std::to_string(boundary->position)
                + ") (generation " + std::to_string(boundary->generation)
                + ") (relations "
                + std::to_string(boundary->environment.size()) + "))");
        ++n;
    }
    d->emit("(catalog-end " + std::to_string(n) + ")");
}

static bool emit_catalog_boundary(slog::Daemon* d, const std::string& key,
                                  const std::string& path = "")
{
    const slog::BoundarySnapshot* boundary = d->db()->getBoundary(key);
    if (boundary == nullptr) return false;
    std::map<std::string, slog::Relation*> sorted(
        boundary->environment.begin(), boundary->environment.end());
    u64 n = 0;
    for (const auto& item : sorted)
    {
        if (item.second == nullptr
            || !catalog_path_selects(item.first, path)) continue;
        d->emit(catalog_relation_record(item.first, item.second, key));
        ++n;
    }
    d->emit("(catalog-end " + std::to_string(n) + ")");
    return true;
}

// (catalog types): the independent TypeDescriptor registry, SID-ordered.
// `name` is a projection of the current binding environment and is #f after a
// drop; the descriptor and canonical intern store remain directly reachable.
static void emit_catalog_types(slog::Daemon* d)
{
    using slog::protocol::quoteString;
    std::map<u32, slog::TypeDescriptor*> by_sid(
        d->db()->getTypeDescriptors().begin(),
        d->db()->getTypeDescriptors().end());
    u64 n = 0;
    for (const auto& kv : by_sid)
    {
        const slog::TypeDescriptor* descriptor = kv.second;
        const std::string name = d->db()->currentTypeName(*descriptor);
        d->emit("(catalog-type (sid " + std::to_string(kv.first) + ")"
                + " (name " + (name.empty() ? "#f" : quoteString(name)) + ")"
                + " (arity "
                + std::to_string(descriptor->stored_arity) + ")"
                + " (type-key "
                + (descriptor->type_key.empty()
                     ? "#f"
                     : quoteString(descriptor->type_key)) + "))");
        ++n;
    }
    d->emit("(catalog-end " + std::to_string(n) + ")");
}

// Dispatch one '('-line on the command stack.
static void dispatch_command(slog::Daemon* d, CommandBuilders& builders,
                             const std::string& line)
{
    slog::sexp::SExp form;
    std::string err;
    if (!slog::protocol::parseLine(line, form, err))
    {
        d->markCommandProtocol();
        refuse(d, "parse", "(detail " + slog::protocol::quoteString(err) + ")");
        return;
    }
    // The dispatcher routed on '(' so the form is a list.  The verb must be
    // an atom in plain symbol spelling -- anything else (a string, a list, a
    // token with reader-syntax characters) could not be echoed verbatim into
    // a (verb ...) detail that datum readers consume, so it is refused here
    // once and every downstream emission stays clean.
    const bool head_is_atom =
        !form.children.empty()
        && form.children[0].kind == slog::sexp::SExp::K::atom;
    if (form.children.empty() || !head_is_atom
        || !symbol_safe(form.children[0].text))
    {
        d->markCommandProtocol();
        refuse(d, "parse", form.children.empty()
                             ? "(detail \"empty command\")"
                             : "(detail \"verb must be a symbol\")");
        return;
    }
    const std::string& verb = form.children[0].text;
    const size_t argc = form.children.size() - 1;

    // A saved Q1 cursor owns a snapshot lease across command lines.  Until it
    // completes or is cancelled, no other command may reach a path/plugin or
    // mutation seam and change an index underneath that cursor.  Query-page
    // and query-cancel are the only legal interleavings; a second query gets
    // the more specific active-id refusal in dispatch_query_command.
    const bool query_verb =
        verb == "query" || verb == "query-page" || verb == "query-cancel";
    if (builders.active_query && !query_verb)
    {
        d->markCommandProtocol();
        refuse(d, "query-admission", "(verb " + verb + ") (active "
               + builders.active_query->id + ")");
        return;
    }

    // The pre-T0 literals (docs/pausing.md §5), now the command layer's first
    // two verbs with byte-identical replies.  They do NOT mark the session as
    // command-speaking: every legacy driver (runslog.rkt, slogd.rkt's
    // auto-continue, pause-tests) sends the bare literals, and the
    // protocol-mode seam exists precisely so slice (d) can keep the 8-field
    // (paused ...) bytes for those sessions.
    if (verb == "continue" && argc == 0)          { d->continueRun();        return; }
    if (verb == "continue-boundary" && argc == 0) { d->continueToBoundary(); return; }

    // (protocol-mode): observe the session's protocol mode without changing
    // it -- exempt from marking so a test (or slice (d)) can see the mode a
    // pause WOULD be scoped by.
    if (verb == "protocol-mode" && argc == 0)
    {
        d->emit(std::string("(protocol-mode ")
                + (d->commandProtocolSpoken() ? "command" : "path") + ")");
        return;
    }

    d->markCommandProtocol();

    // A prepared boundary is a private execution lease.  Its own lifecycle,
    // bounded continue, and command-stratum construction may proceed; every
    // ordinary catalog/query/mutation command is refused until commit/abort.
    // Path plugins are admitted by the shared line dispatcher because native
    // strata and frozen-input actions still ride that stack; their relation
    // resolution is through Database's private overlay.
    const bool boundary_verb =
        verb == "prepare-boundary" || verb == "commit-boundary"
        || verb == "abort-boundary";
    const bool builder_verb =
        verb == "scc-begin" || verb == "scc-seal"
        || verb == "stratum-begin" || verb == "stratum-add-scc"
        || verb == "stratum-seal";
    // T5: watches are session debugging state (repl.md §6 -- never saved,
    // never part of any hash, never a catalog read), and prepare-time
    // registration is what lets a level-1 watch observe the run that
    // creates its successor version (t5-contract §1).  Queries -- and the
    // catalog read their planner binds against -- are additionally
    // admitted while the run is PARKED AT THE PRE-COMMIT GATE: that park
    // is exactly the "remain paused and inspect" state (execution-tiers
    // §7.2), masters are immutable, and both the catalog snapshot and the
    // bound keys are COMMITTED truth (the private boundary replaces the
    // catalog only at commit).  Every other ordinary command stays
    // refused until commit/abort, exactly as before.
    // T5 slice (d3): breaks are session debugging state exactly as watches
    // are -- never saved, never hashed, and armable while a run of theirs
    // is held mid-event.
    const bool watch_verb = verb == "watch" || verb == "unwatch"
        || verb == "break" || verb == "unbreak" || verb == "breaks";
    // T5 slice (c): `replay` is a debugger continuation over a PARKED epoch,
    // so the lease admits it whenever the run is suspended -- including at
    // parks it will refuse, because `level-1-unwatchable` is the honest
    // answer there and a boundary-admission refusal would hide it.
    // T5 slice (d1): `why` joins them -- it reads the journal and the
    // parked epoch's retained candidates, moves nothing, and a
    // boundary-admission refusal would hide the honest answer.
    const bool parked_debug_verb =
        (verb == "replay" || verb == "step" || verb == "frames"
         || verb == "why")
        && d->db()->isSuspended();
    // T5 slice (c3) widens this by exactly one park: a STEP STOP is the
    // same "remain paused and inspect" state one transition earlier -- the
    // read is mid-flight, so no master, sidecar or intern allocator has
    // moved either, and the query layer already admits `mid_read`.  A
    // budget-driven mid-read park stays outside: nobody is sitting at it.
    const bool gate_parked_read =
        (verb == "query" || verb == "query-page" || verb == "query-cancel"
         || verb == "catalog")
        && d->db()->isSuspended()
        && (d->db()->suspendPosition() == slog::RUN_READ_COMPLETE
            || (d->db()->suspendPosition() == slog::RUN_MID_READ
                && d->db()->stepStopPending()));
    if (d->boundaryPrepared() && !boundary_verb && !builder_verb
        && !watch_verb && !gate_parked_read && !parked_debug_verb)
    {
        refuse(d, "boundary-admission", "(verb " + verb + ") (boundary "
               + slog::protocol::quoteString(d->preparedBoundaryKey()) + ")");
        return;
    }

    if (dispatch_boundary_command(d, form, verb))
        return;

    if (dispatch_transform_command(d, form, verb))
        return;

    if (dispatch_builder_command(d, builders, form, verb))
        return;

    if (dispatch_query_command(d, builders, form, line, verb))
        return;

    if (verb == "continue" || verb == "continue-boundary")
    {
        refuse(d, "parse", "(verb " + verb + ") (detail \"T0 takes the bare "
               "form; parameterized budgets ride the compiled action until "
               "the verb grows arguments\")");
        return;
    }

    // T5 slice (c): `replay` leaves reserved-verb parking through the T0
    // dispatcher (contract §0.5 -- no second grammar).  At a pre-commit gate
    // park it discards the read's send shards and runs the SAME read again
    // from its origin; against a non-monotone epoch it refuses as
    // `level-1-unwatchable` naming that epoch's flavor (§0.1's ratified
    // firing point: replay is a level-1-only continuation); at any other
    // park -- or none -- it refuses structurally with the position.
    if (verb == "replay")
    {
        if (argc != 0)
        {
            refuse(d, "parse", "(verb replay) (detail \"T5 takes the bare "
                   "form; the rerun uses the session's continue budget\")");
            return;
        }
        const char* obstacle = d->db()->replayObstacle();
        if (obstacle == nullptr)
        {
            d->replayRead();
            return;
        }
        if (std::strcmp(obstacle, "flavor") == 0)
            refuse(d, "level-1-unwatchable",
                   "(verb replay) (flavor "
                   + slog::protocol::quoteString(d->db()->currentFlavor())
                   + ") (position "
                   + d->db()->currentPositionName() + ")");
        else
            refuse(d, "replay-unavailable",
                   std::string("(verb replay) (detail ") + obstacle
                   + ") (position " + d->db()->currentPositionName() + ")");
        return;
    }

    // T5 slice (c3): `step` and `frames` (contract §3, repl-ux §9.3).  A
    // step is a level-1-only continuation like replay, so it refuses the
    // same way and in the same order: flavor first, then position.  From a
    // gate park it replays the completed read and stops at the first
    // matching port; from a step stop it carries on to the next one.
    if (verb == "step")
    {
        slog::Database::StepGrain grain = slog::Database::step_any;
        u32 filter = UINT32_MAX;
        bool parsed = argc == 0;
        if (argc >= 1 && form.children[1].kind == slog::sexp::SExp::K::atom)
        {
            const std::string& what = form.children[1].text;
            parsed = true;
            if (what == "match")      grain = slog::Database::step_match;
            else if (what == "fire")  grain = slog::Database::step_fire;
            else if (what == "emit")  grain = slog::Database::step_emit;
            else if (what == "tuple") grain = slog::Database::step_tuple;
            else if (what == "rule" && argc == 2
                     && form.children[2].kind == slog::sexp::SExp::K::atom)
                filter = (u32)std::strtoul(form.children[2].text.c_str(),
                                           nullptr, 10);
            else parsed = false;
            if (what != "rule" && argc != 1) parsed = false;
        }
        if (!parsed)
        {
            refuse(d, "parse", "(verb step) (detail \"step [match|fire|emit"
                   "|tuple] | step rule N\")");
            return;
        }
        const char* obstacle = d->db()->stepObstacle();
        if (obstacle == nullptr)
        {
            d->stepRun(grain, filter);
            return;
        }
        if (std::strcmp(obstacle, "flavor") == 0)
            refuse(d, "level-1-unwatchable",
                   "(verb step) (flavor "
                   + slog::protocol::quoteString(d->db()->currentFlavor())
                   + ") (position "
                   + d->db()->currentPositionName() + ")");
        else
            refuse(d, "step-unavailable",
                   std::string("(verb step) (detail ") + obstacle
                   + ") (position " + d->db()->currentPositionName() + ")");
        return;
    }

    // (frames): the join stack of the CURRENT step stop, innermost premise
    // last.  Structural only -- rule id, variant, op index and rows -- so
    // the client renders SOURCE variable names from the canonical plan it
    // already holds (execution-tiers §4.2's rule meta), not from a second
    // daemon-side name table.
    if (verb == "frames")
    {
        if (argc != 0)
        {
            refuse(d, "parse", "(verb frames) (detail \"frames takes no "
                   "arguments\")");
            return;
        }
        if (!d->db()->stepStopPending())
        {
            refuse(d, "step-unavailable",
                   std::string("(verb frames) (detail no-stop) (position ")
                   + d->db()->currentPositionName() + ")");
            return;
        }
        emit_step_frames(d);
        return;
    }

    // T5 slice (d3): standing breakpoints (repl-ux §9.1, contract §4(d3)).
    //
    //   (break (id "b1") [(relation "R")] [(rule N)] [(position K)]
    //                    [(pattern TERM ...)])     TERM ::= word | _
    //   (unbreak (id "b1"))
    //   (breaks)
    //
    // Unlike `step`, arming needs no park -- that is the whole point: this
    // is how the ports become reachable before a run rather than only from
    // a gate the operator had to trip first.
    if (verb == "break")
    {
        slog::Database::BreakSpec spec;
        bool have_id = false;
        for (size_t i = 1; i < form.children.size(); ++i)
        {
            const slog::sexp::SExp& field = form.children[i];
            if (field.kind != slog::sexp::SExp::K::list
                || field.children.empty()
                || field.children[0].kind != slog::sexp::SExp::K::atom)
            {
                refuse(d, "parse", "(verb break) (detail \"expected (break "
                       "(id \\\"b1\\\") [(relation \\\"R\\\")] [(rule N)] "
                       "[(position K)] [(pattern TERM ...)])\")");
                return;
            }
            const std::string& tag = field.children[0].text;
            u64 value = 0;
            if (tag == "id" && field.children.size() == 2
                && field.children[1].kind == slog::sexp::SExp::K::string)
            {
                spec.id = field.children[1].text;
                have_id = !spec.id.empty();
            }
            else if (tag == "relation" && field.children.size() == 2
                     && field.children[1].kind == slog::sexp::SExp::K::string)
                spec.relation = field.children[1].text;
            else if (tag == "rule" && field.children.size() == 2
                     && parse_u64_atom(field.children[1], value)
                     && value < UINT32_MAX)
                spec.rule_id = static_cast<u32>(value);
            else if (tag == "position" && field.children.size() == 2
                     && parse_u64_atom(field.children[1], value)
                     && value < 0xffff)
                spec.position = static_cast<u16>(value);
            else if (tag == "pattern")
            {
                if (!parse_row_terms(d, "break", field, true, spec.pattern,
                                     spec.wild))
                    return;
                if (spec.pattern.empty())
                {
                    refuse(d, "parse", "(verb break) (detail \"an empty "
                           "pattern matches nothing; omit the field\")");
                    return;
                }
            }
            else
            {
                refuse(d, "parse",
                       "(verb break) (detail \"unknown or malformed field "
                       + tag + "\")");
                return;
            }
        }
        if (!have_id)
        {
            refuse(d, "parse",
                   "(verb break) (detail \"requires (id \\\"b1\\\")\")");
            return;
        }
        if (spec.relation.empty() && spec.rule_id == UINT32_MAX
            && spec.position == 0xffff && spec.pattern.empty())
        {
            // "stop at every port of every rule" is `step`, not a break.
            refuse(d, "parse", "(verb break) (detail \"a break needs a "
                   "relation, a rule, or a position to narrow it\")");
            return;
        }
        if (spec.position != 0xffff && spec.rule_id == UINT32_MAX)
        {
            // A body position without a rule is a different position in
            // every rule -- an accident, not an intent.
            refuse(d, "parse", "(verb break) (detail \"a body position "
                   "belongs to a rule; give (rule N) too\")");
            return;
        }
        const std::string id = spec.id;
        if (!d->db()->addBreak(std::move(spec)))
        {
            refuse(d, "break-binding", "(verb break) (detail "
                   + slog::protocol::quoteString("break id " + id
                                                 + " is already in use")
                   + ")");
            return;
        }
        d->emit("(break-added (id " + slog::protocol::quoteString(id)
                + ") (breaks "
                + std::to_string(d->db()->breakSpecs().size()) + "))");
        return;
    }

    if (verb == "unbreak")
    {
        std::string id;
        if (argc != 1 || form.children[1].kind != slog::sexp::SExp::K::list
            || form.children[1].children.size() != 2
            || form.children[1].children[0].text != "id"
            || form.children[1].children[1].kind
                 != slog::sexp::SExp::K::string)
        {
            refuse(d, "parse",
                   "(verb unbreak) (detail \"expected (unbreak (id "
                   "\\\"b1\\\"))\")");
            return;
        }
        id = form.children[1].children[1].text;
        if (!d->db()->removeBreak(id))
        {
            refuse(d, "break-binding", "(verb unbreak) (detail "
                   + slog::protocol::quoteString("no break with id " + id)
                   + ")");
            return;
        }
        d->emit("(break-removed (id " + slog::protocol::quoteString(id)
                + ") (breaks "
                + std::to_string(d->db()->breakSpecs().size()) + "))");
        return;
    }

    if (verb == "breaks")
    {
        if (argc != 0)
        {
            refuse(d, "parse", "(verb breaks) (detail \"breaks takes no "
                   "arguments\")");
            return;
        }
        for (const slog::Database::BreakSpec& b : d->db()->breakSpecs())
        {
            std::string pattern;
            for (size_t i = 0; i < b.pattern.size(); ++i)
                pattern += (i == 0 ? "" : " ")
                  + (b.wild[i] ? std::string("_")
                               : d->db()->writeValCSV(b.pattern[i]));
            d->emit("(break (id " + slog::protocol::quoteString(b.id)
                    + ") (relation " + slog::protocol::quoteString(b.relation)
                    + ") (rule "
                    + (b.rule_id == UINT32_MAX ? "#f"
                                               : std::to_string(b.rule_id))
                    + ") (position "
                    + (b.position == 0xffff ? "#f"
                                            : std::to_string(b.position))
                    + ") (pattern " + slog::protocol::quoteString(pattern)
                    + ") (hits " + std::to_string(b.hits) + "))");
        }
        d->emit("(breaks-end "
                + std::to_string(d->db()->breakSpecs().size()) + ")");
        return;
    }

    // T5 slice (d1): `why` (repl-ux §9.4, contract §4(d1)).
    //
    //   (why [(depth N)])                     the gate's accepted candidates
    //   (why (relation "R") (row TERM ...) [(depth N)])
    //     TERM ::= (integer "99") | (real "1.5") | (string "s") | (word 1234)
    //   -- the query payload's literal vocabulary, not a second one.
    //
    // The bare form is the one that can name a change that is NOT committed
    // truth -- at a gate park the candidate exists only in the send shards,
    // so no query could hand the client its words.  Both forms read the
    // journal only; nothing about the parked run moves.
    if (verb == "why")
    {
        ProofBudget budget;
        std::string relation;
        std::vector<u64> row;
        bool have_relation = false, have_row = false;
        for (size_t i = 1; i < form.children.size(); ++i)
        {
            const slog::sexp::SExp& field = form.children[i];
            if (field.kind != slog::sexp::SExp::K::list
                || field.children.empty()
                || field.children[0].kind != slog::sexp::SExp::K::atom)
            {
                refuse(d, "parse", "(verb why) (detail \"expected (why "
                       "[(relation \\\"R\\\") (row TERM ...)] "
                       "[(depth N)])\")");
                return;
            }
            const std::string& tag = field.children[0].text;
            if (tag == "depth")
            {
                u64 value = 0;
                if (field.children.size() != 2
                    || !parse_u64_atom(field.children[1], value) || value == 0
                    || value > 16)
                {
                    refuse(d, "parse",
                           "(verb why) (detail \"depth is 1..16\")");
                    return;
                }
                budget.depth = static_cast<u32>(value);
            }
            else if (tag == "relation")
            {
                if (field.children.size() != 2
                    || field.children[1].kind != slog::sexp::SExp::K::string)
                {
                    refuse(d, "parse",
                           "(verb why) (detail \"relation takes one name\")");
                    return;
                }
                relation = field.children[1].text;
                have_relation = true;
            }
            else if (tag == "row")
            {
                have_row = true;
                std::vector<bool> wild;
                if (!parse_row_terms(d, "why", field, false, row, wild))
                    return;
            }
            else
            {
                refuse(d, "parse", "(verb why) (detail \"unknown field "
                       + tag + "\")");
                return;
            }
        }
        if (have_relation != have_row)
        {
            refuse(d, "parse", "(verb why) (detail \"relation and row go "
                   "together\")");
            return;
        }
        u32 nodes = 0;
        bool truncated = false;
        std::vector<std::string> path;
        if (have_relation)
        {
            if (d->db()->proofCount() == 0)
            {
                // Two different silences, and the operator deserves to know
                // which: nothing armed, or armed over an epoch capture does
                // not cover (contract §0.1 is monotone-only, so a counted or
                // maintenance round journals nothing by construction).
                refuse(d, "provenance-unavailable",
                       d->db()->provenanceArmed()
                         ? "(verb why) (detail \"this event captured no "
                           "derivations; capture covers MONOTONE epochs, and "
                           "counted or maintenance rounds are "
                           "level-1-unwatchable\")"
                         : "(verb why) (detail \"no derivations were "
                           "captured; arm a level-1 watch with (provenance "
                           "#t) before the run\")");
                return;
            }
            emit_proof_subtree(d, relation, row, -1, budget.depth, budget,
                               path, nodes, truncated);
        }
        else
        {
            const std::vector<slog::Database::GateCandidate>& candidates =
                d->db()->gateCandidates();
            if (candidates.empty())
            {
                refuse(d, "provenance-unavailable",
                       std::string("(verb why) (detail \"no gate candidates "
                       "here; name a fact, or ask at a pre-commit gate "
                       "park\") (position ")
                       + d->db()->currentPositionName() + ")");
                return;
            }
            for (const slog::Database::GateCandidate& candidate : candidates)
                emit_proof_subtree(d, candidate.relation, candidate.tuple, -1,
                                   budget.depth, budget, path, nodes,
                                   truncated);
        }
        emit_proof_end(d, nodes, budget, truncated);
        return;
    }

    if (const char* family = reserved_family(verb))
    {
        refuse(d, "reserved-verb",
               "(verb " + verb + ") (family " + family + ")");
        return;
    }

    if (verb == "catalog")
    {
        if (argc == 0) { emit_catalog_relations(d); return; }
        if (argc == 1 && form.children[1].kind == slog::sexp::SExp::K::atom)
        {
            const std::string& what = form.children[1].text;
            if (what == "relations") { emit_catalog_relations(d); return; }
            if (what == "types")     { emit_catalog_types(d);     return; }
            if (what == "boundaries"){ emit_catalog_boundaries(d); return; }
        }
        // N3-D §5.3 subtree selection: a trailing structured qname narrows
        // the record stream to the exact member or nested descendants.
        if (argc == 2
            && form.children[1].kind == slog::sexp::SExp::K::atom
            && form.children[1].text == "relations")
        {
            std::string path;
            if (!parse_qname(form.children[2], path))
            {
                refuse(d, "parse", "(verb catalog) (detail \"subtree filter "
                       "must be a structured (qname \\\"component\\\" ...)\")");
                return;
            }
            emit_catalog_relations(d, path);
            return;
        }
        if ((argc == 2 || argc == 3)
            && form.children[1].kind == slog::sexp::SExp::K::atom
            && form.children[1].text == "boundary"
            && form.children[2].kind == slog::sexp::SExp::K::string)
        {
            const std::string& key = form.children[2].text;
            std::string path;
            if (argc == 3 && !parse_qname(form.children[3], path))
            {
                refuse(d, "parse", "(verb catalog) (detail \"subtree filter "
                       "must be a structured (qname \\\"component\\\" ...)\")");
                return;
            }
            if (emit_catalog_boundary(d, key, path)) return;
            refuse(d, "boundary-lookup",
                   "(verb catalog) (boundary "
                   + slog::protocol::quoteString(key) + ")");
            return;
        }
        refuse(d, "parse", "(verb catalog) (detail \"expected (catalog), "
               "(catalog relations), (catalog relations (qname ...)), "
               "(catalog types), (catalog boundaries), "
               "or (catalog boundary \\\"KEY\\\" [(qname ...)])\")");
        return;
    }

    if (verb == "protocol-mode")
    {
        refuse(d, "parse",
               "(verb protocol-mode) (detail \"takes no arguments\")");
        return;
    }

    // ---- R2 deep value view ---------------------------------------------
    //
    //   (describe-value WORD [(depth N)])
    //
    // Re-render one evaluation-local value word as a cell record, the text
    // cut at the requested preview depth (omitted = unbudgeted).  This is
    // how a client iterates deeper into a value whose earlier preview was
    // cut: the word never changes, only how much text is materialized.
    // The word must be one this evaluation handed out; unrecognized words
    // and dead struct ids refuse as value-lookup.
    if (verb == "describe-value")
    {
        u64 word = 0;
        if ((argc != 1 && argc != 2)
            || !parse_u64_atom(form.children[1], word))
        {
            refuse(d, "parse", "(verb describe-value) (detail \"expected "
                   "(describe-value WORD [(depth N)])\")");
            return;
        }
        u32 depth = 0;
        if (argc == 2
            && !parse_query_depth(d, verb, form.children[2], depth))
            return;
        if (!d->db()->canDescribeWord(word))
        {
            refuse(d, "value-lookup", "(verb describe-value) (word "
                   + std::to_string(word) + ")");
            return;
        }
        d->emit(d->db()->describeValue(
            word, d->db()->currentBoundaryKey(), depth));
        return;
    }

    // ---- R2 value search -------------------------------------------------
    //
    //   (uses (word W))
    //   (uses (string "TEXT")) | (uses (integer "42")) | (uses (real "2.5"))
    //
    // Which relations contain this value?  A word is one this evaluation
    // handed out (validated like describe-value); a typed literal resolves
    // probe-only, so a value the interner has never seen honestly appears
    // nowhere.  The scan walks each latest non-temporary relation's master
    // index once, counting rows with the word in ANY column: one
    // (uses-rel ...) per nonzero relation, name-sorted, then
    // (uses-end (relations N) (rows TOTAL)).
    if (verb == "uses")
    {
        using slog::protocol::quoteString;
        u64 word = 0;
        bool resolved = false;
        const slog::sexp::SExp* spec =
            argc == 1 && form.children[1].kind == slog::sexp::SExp::K::list
                && form.children[1].children.size() == 2
                && form.children[1].children[0].kind
                       == slog::sexp::SExp::K::atom
            ? &form.children[1] : nullptr;
        const std::string kind = spec ? spec->children[0].text : "";
        if (spec != nullptr && kind == "word")
        {
            if (!parse_u64_atom(spec->children[1], word)) spec = nullptr;
            else if (!d->db()->canDescribeWord(word))
            {
                refuse(d, "value-lookup", "(verb uses) (word "
                       + std::to_string(word) + ")");
                return;
            }
            else resolved = true;
        }
        else if (spec != nullptr
                 && (kind == "string" || kind == "integer" || kind == "real"))
        {
            if (spec->children[1].kind != slog::sexp::SExp::K::string)
                spec = nullptr;
            else
            {
                slog::query::Literal literal;
                literal.kind = kind == "string"  ? slog::query::LiteralK::string
                             : kind == "integer" ? slog::query::LiteralK::integer
                                                 : slog::query::LiteralK::real;
                literal.text = spec->children[1].text;
                try
                {
                    resolved = slog::query::resolve_literal(
                        *d->db(), literal, word);
                }
                catch (const slog::query::Error& exception)
                {
                    refuse(d, slog::query::error_class(exception.kind()),
                           "(verb uses) (detail "
                           + quoteString(exception.what()) + ")");
                    return;
                }
            }
        }
        else spec = nullptr;
        if (spec == nullptr)
        {
            refuse(d, "parse", "(verb uses) (detail \"expected (uses (word W)"
                   " | (string \\\"...\\\") | (integer \\\"...\\\")"
                   " | (real \\\"...\\\"))\")");
            return;
        }
        u64 total = 0, nrels = 0;
        if (resolved)
        {
            std::map<std::string, slog::Relation*> sorted(
                d->db()->getRelations().begin(),
                d->db()->getRelations().end());
            for (auto& kv : sorted)
            {
                slog::Relation* r = kv.second;
                // compiler-reserved $... machinery (stats, supplementary
                // relations) is execution metadata, not user data
                if (r == nullptr || r->isCompilerTemporary()
                    || kv.first.find('$') != std::string::npos) continue;
                const u64 count = r->countWordUses(word);
                if (count == 0) continue;
                d->emit("(uses-rel (name " + quoteString(kv.first)
                        + ") (version-key "
                        + (r->getVersionKey().empty()
                             ? "#f" : quoteString(r->getVersionKey()))
                        + ") (count " + std::to_string(count) + "))");
                ++nrels;
                total += count;
            }
        }
        d->emit("(uses-end (relations " + std::to_string(nrels)
                + ") (rows " + std::to_string(total) + "))");
        return;
    }

    // ---- level-0 watches (repl.md §6) ----------------------------------
    //
    //   (watch (id "w1") (version-key "v1:...") [(tuple V ...)])
    //   (unwatch (id "w1"))
    //
    // A watch names an EXACT VersionKey.  The daemon never resolves a QName
    // or follows a latest binding: a client that wants "this relation through
    // the next run" keeps that intent and re-registers against the successor
    // key when it prepares that boundary.
    if (verb == "watch")
    {
        CommandFields fields;
        std::string error;
        if (!collect_fields(form, 1,
                            {"id", "version-key", "tuple", "level",
                             "provenance"},
                            fields, error)
            || fields.find("id") == fields.end()
            || fields.find("version-key") == fields.end())
        {
            refuse_boundary_parse(
              d, verb, error.empty()
                ? "requires (id \"...\") and (version-key \"...\"), with an "
                  "optional (tuple V ...), (level 0|1) and (provenance #t)"
                : error);
            return;
        }
        const slog::sexp::SExp* value = nullptr;
        std::string id, version_key;
        if (!singleton_field(fields, "id", value)
            || !parse_string_value(*value, id)
            || !singleton_field(fields, "version-key", value)
            || !parse_string_value(*value, version_key))
        {
            refuse_boundary_parse(
              d, verb, "id and version-key must be nonempty strings");
            return;
        }
        std::vector<u64> tuple;
        bool tuple_mode = false;
        auto tit = fields.find("tuple");
        if (tit != fields.end())
        {
            tuple_mode = true;
            const auto& field = *tit->second;
            for (size_t i = 1; i < field.children.size(); ++i)
            {
                u64 word = 0;
                if (!parse_u64_atom(field.children[i], word))
                {
                    refuse_boundary_parse(
                      d, verb, "tuple takes encoded value words");
                    return;
                }
                tuple.push_back(word);
            }
            if (tuple.empty())
            {
                refuse_boundary_parse(d, verb, "tuple watch needs a tuple");
                return;
            }
        }
        // T5 slice (a): (level 1) records the pre-commit-gate intent
        // (docs/t5-contract.md).  Registration is the only difference at
        // this slice; hits report identically until the gate lands.
        u64 level = 0;
        auto lit = fields.find("level");
        if (lit != fields.end())
        {
            const auto& field = *lit->second;
            if (field.children.size() != 2
                || !parse_u64_atom(field.children[1], level)
                || level > 1)
            {
                refuse_boundary_parse(d, verb, "level must be 0 or 1");
                return;
            }
        }
        // T5 slice (d1): (provenance #t) additionally captures this event's
        // derivations for `why` while the watch is armed -- opt-in, because
        // it is what puts the interpreter on its observed loop.
        bool provenance = false;
        auto pit = fields.find("provenance");
        if (pit != fields.end())
        {
            const auto& field = *pit->second;
            if (field.children.size() != 2
                || field.children[1].kind != slog::sexp::SExp::K::atom
                || (field.children[1].text != "#t"
                    && field.children[1].text != "#f"))
            {
                refuse_boundary_parse(d, verb, "provenance must be #t or #f");
                return;
            }
            provenance = field.children[1].text == "#t";
        }
        if (provenance && level != 1)
        {
            refuse_boundary_parse(
              d, verb, "provenance capture is a level-1 watch's observation");
            return;
        }
        // watchTarget also resolves a PREPARED successor key (T5: the
        // registration that lets the gate observe the creating run)
        if (d->db()->watchTarget(version_key) == nullptr)
        {
            refuse(d, "watch-binding",
                   "(verb watch) (detail "
                   + slog::protocol::quoteString(
                       "no relation is bound to " + version_key) + ")");
            return;
        }
        if (!d->db()->addWatch(id, version_key, tuple_mode, std::move(tuple),
                               static_cast<u32>(level), provenance))
        {
            refuse(d, "watch-binding",
                   "(verb watch) (detail "
                   + slog::protocol::quoteString(
                       "watch id " + id + " is already in use") + ")");
            return;
        }
        // T5 slice (d4): with every storage kind now settling by its own
        // identity, the only relation the gate cannot preview is one with no
        // full index yet.  Say so AT REGISTRATION rather than accepting the
        // level and quietly never engaging -- the silent downgrade was the
        // last of them.  Additive and negative-only, so a settleable level-1
        // line stays byte-identical to the shipped one.
        slog::Relation* bound = d->db()->watchTarget(version_key);
        const bool settleable = level != 1 || (bound != nullptr
                                               && bound->level1Settleable());
        d->emit("(watch-added (id " + slog::protocol::quoteString(id)
                + ") (version-key " + slog::protocol::quoteString(version_key)
                + ") (watches " + std::to_string(d->db()->watchCount()) + ")"
                + (level == 1 ? " (level 1)" : "")
                + (provenance ? " (provenance #t)" : "")
                + (settleable ? "" : " (settleable #f)") + ")");
        return;
    }

    if (verb == "unwatch")
    {
        CommandFields fields;
        std::string error;
        const slog::sexp::SExp* value = nullptr;
        std::string id;
        if (!collect_fields(form, 1, {"id"}, fields, error)
            || !singleton_field(fields, "id", value)
            || !parse_string_value(*value, id))
        {
            refuse_boundary_parse(d, verb, "requires (id \"...\")");
            return;
        }
        if (!d->db()->removeWatch(id))
        {
            refuse(d, "watch-binding",
                   "(verb unwatch) (detail "
                   + slog::protocol::quoteString("no watch with id " + id)
                   + ")");
            return;
        }
        d->emit("(watch-removed (id " + slog::protocol::quoteString(id)
                + ") (watches " + std::to_string(d->db()->watchCount()) + "))");
        return;
    }

    refuse(d, "unknown-verb", "(verb " + verb + ")");
}

// One per-line dispatch shared byte-identically by both transports
// (docs/t0-contract.md, "One protocol, two stacks"): a line beginning '('
// routes to the command layer; anything else stays a plugin path.  The TCP
// twin handles its transport-level (close) BEFORE this dispatch, exactly as
// before.
static void dispatch_line(slog::Daemon* d,
                          CommandBuilders& builders,
                          const std::string& line,
                          std::vector<void*>& so_handles)
{
    if (line.empty())
        return;
    if (line[0] == '(')
        dispatch_command(d, builders, line);
    else if (builders.active_query)
        refuse(d, "query-admission", "(verb plugin-path) (active "
               + builders.active_query->id + ")");
    else
        run_plugin(d, line, so_handles);
}

// stdin transport: one plugin path per line, responses to stdout.
static int run_stdin(u32 num_threads)
{
    std::vector<void*> so_handles;
    CommandBuilders builders;
    auto* daemon = new slog::Daemon(num_threads,
        [](const std::string& s) { std::cout << s << std::endl; });

    std::string line;
    while (std::getline(std::cin, line))
    {
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        dispatch_line(daemon, builders, line, so_handles);
    }

    // A connection-scoped query owns a Database lease. Release it before the
    // Database, then delete the daemon BEFORE dlclosing: index objects
    // (BTreeIndex<A>) are instantiated in the .so's, so their vtables and
    // destructors live there.
    builders.active_query.reset();
    delete daemon;
    for (void* h : so_handles) if (h) dlclose(h);
    return 0;
}

// TCP transport: connect back to a parent on `port`; plugin paths arrive as
// lines, responses are sent back as s-expressions.
static int run_tcp(u32 num_threads, int port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
        return 1;

    sockaddr_in serv_addr;
    std::memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
        return 1;

    std::vector<void*> so_handles;
    CommandBuilders builders;
    auto* daemon = new slog::Daemon(num_threads,
        [sock](const std::string& s) { send_msg(sock, s); });

    pollfd pfd;
    pfd.fd = sock;
    pfd.events = POLLIN;

    char buffer[4096];
    std::string inbuf;          // accumulates bytes until full lines arrive
    bool done = false;

    while (!done)
    {
        int ret = poll(&pfd, 1, 2000);

        if (ret == 0)
        {
            send_msg(sock, "(pending)");
            continue;
        }
        else if (ret < 0)
        {
            if (errno == EINTR) continue;   // interrupted by a signal; retry
            break;
        }

        int valread = read(sock, buffer, sizeof(buffer));

        if (valread < 0 && errno == EINTR)
            continue;                        // interrupted by a signal; retry
        if (valread <= 0)
            break;

        inbuf.append(buffer, valread);

        // Dispatch complete, newline-terminated lines in order; the
        // transport-level (close) is handled in sequence so any queued
        // plugins still run.
        size_t nl;
        while ((nl = inbuf.find('\n')) != std::string::npos)
        {
            std::string line = inbuf.substr(0, nl);
            inbuf.erase(0, nl + 1);
            if (!line.empty() && line.back() == '\r')
                line.pop_back();

            if (line == "(close)")
            {
                send_bye(sock);
                done = true;
                break;
            }
            dispatch_line(daemon, builders, line, so_handles);
        }
        if (done)
            break;

        // The console's EOF path may send a bare (close) with no trailing
        // newline.  Match only when the ENTIRE residual buffer is exactly
        // (close) (trimmed) -- a substring find would let any data payload
        // containing "(close)" (e.g. an over-long line) tear down the session.
        {
            size_t a = inbuf.find_first_not_of(" \t\r\n");
            size_t b = inbuf.find_last_not_of(" \t\r\n");
            std::string trimmed = (a == std::string::npos)
                                    ? std::string() : inbuf.substr(a, b - a + 1);
            if (trimmed == "(close)")
            {
                send_bye(sock);
                break;
            }
        }
    }

    // Release a connection-scoped query lease before its Database, then
    // delete the daemon BEFORE dlclosing (vtables live in the .so's).
    builders.active_query.reset();
    delete daemon;
    for (void* h : so_handles) if (h) dlclose(h);
    close(sock);
    return 0;
}

int main(int argc, char* argv[])
{
    u32 num_threads = default_num_threads();
    int port = -1;

    for (int i = 1; i < argc; ++i)
    {
        if (std::strcmp(argv[i], "-t") == 0 && i + 1 < argc)
            num_threads = std::min(std::max((u32)std::atoi(argv[++i]), MIN_THREADS),
                                   MAX_THREADS);
        else if (std::strcmp(argv[i], "-p") == 0 && i + 1 < argc)
            port = std::atoi(argv[++i]);
    }

    // Honor the requested team size exactly: the fixpoint's std::barrier is
    // sized to thread_count, so a runtime that silently hands back fewer
    // threads (OMP_DYNAMIC=true) would deadlock at the first barrier.
    omp_set_dynamic(0);

    if (port >= 0)
        return run_tcp(num_threads, port);
    return run_stdin(num_threads);
}
