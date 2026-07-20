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

#include <dlfcn.h>
#include <string>
#include <vector>
#include <map>
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
// -- with classes `parse`, `unknown-verb`, and `reserved-verb` implemented
// here; the seal / entry-mode / stale-generation / suspended classes arrive
// with slices (b) and (c).  <generation> is the unified generation token
// (Daemon::commandGeneration; execution-tiers §2.2).

static void refuse(slog::Daemon* d, const char* cls, const std::string& details)
{
    d->emit("(refused " + std::string(cls) + " "
            + std::to_string(d->commandGeneration())
            + (details.empty() ? "" : " " + details) + ")");
}

// Reserved verb families: the parser recognizes them and answers
// `reserved-verb` -- distinct from `unknown-verb`, so a client can tell
// "not yet" from "never" (contract, "Reply and refusal doctrine").
static const char* reserved_family(const std::string& verb)
{
    struct ReservedVerb { const char* verb; const char* family; };
    // N3 transactional boundaries (roadmap P3; modules.md §10 N3); Q1 paged
    // queries (execution-tiers §6.4); watch management (repl.md §6 spellings,
    // ratified 2026-07-15 -- deferred past T0, slice (d) tees up the pause
    // machinery they ride); T5 debugger stepping (execution-tiers §9 sketch).
    static const ReservedVerb reserved[] = {
        { "prepare-boundary", "boundary" },
        { "commit-boundary",  "boundary" },
        { "abort-boundary",   "boundary" },
        { "query",            "query"    },
        { "query-page",       "query"    },
        { "query-cancel",     "query"    },
        { "watch",            "watch"    },
        { "unwatch",          "watch"    },
        { "subscribe",        "watch"    },
        { "resume",           "debugger" },
        { "replay",           "debugger" },
        { "why-not-add",      "debugger" },
        { "debug-on",         "debugger" },
        { "debug-off",        "debugger" },
    };
    for (const auto& rv : reserved)
        if (verb == rv.verb) return rv.family;
    return nullptr;
}

// (catalog) / (catalog relations): one (catalog-rel ...) record per LATEST
// relation binding plus one (catalog-planned ...) record per announced-but-
// unregistered version key, name-sorted, then the (catalog-end <n>) sentinel.
// Unlike the compiled (schema) action -- which describes nonempty
// materialization -- the catalog is declaration truth: empty and index-free
// relations appear (repl.md §7).  Every record carries the full pinned field
// set, with an explicit #f where a value is not yet resolvable daemon-side
// (the schema is the pin; N3 fills the values).
static void emit_catalog_relations(slog::Daemon* d)
{
    using slog::protocol::quoteString;
    std::map<std::string, slog::Relation*> sorted(
        d->db()->getRelations().begin(), d->db()->getRelations().end());
    u64 n = 0;
    for (auto& kv : sorted)
    {
        slog::Relation* r = kv.second;
        if (r == nullptr) continue;
        const char* kind = r->getStructId() > 0 ? "struct"
                         : r->isLattice()       ? "lat"
                                                : "table";
        std::string rec = "(catalog-rel (name " + quoteString(kv.first) + ")"
            + " (kind " + kind + ")"
            + " (arity " + std::to_string(r->getArity()) + ")"
            + " (version-id " + std::to_string(r->getVersionId()) + ")"
            + " (version-key "
            + (r->getVersionKey().empty() ? "#f" : quoteString(r->getVersionKey())) + ")"
            + " (evaluation "
            + (r->getEvaluationId().empty() ? "#f" : quoteString(r->getEvaluationId())) + ")"
            + " (predecessor "
            + (r->getPredecessorVersionId() == 0
                 ? "#f" : std::to_string(r->getPredecessorVersionId())) + ")"
            + " (struct-id "
            + (r->getStructId() == 0 ? "#f" : std::to_string(r->getStructId())) + ")"
            + " (type-key #f)"
            + " (lat-spec "
            + (r->isLattice() ? quoteString(r->latticeSpec()) : "#f") + ")"
            + " (size "
            + (r->getAnyIndex() ? std::to_string(r->tupleCount()) : "#f") + ")"
            + " (temp " + (r->isCompilerTemporary() ? "#t" : "#f") + "))";
        d->emit(rec);
        ++n;
    }
    std::map<std::string, std::string> planned(
        d->db()->plannedVersionKeys().begin(),
        d->db()->plannedVersionKeys().end());
    for (const auto& kv : planned)
    {
        d->emit("(catalog-planned (name " + quoteString(kv.first)
                + ") (version-key " + quoteString(kv.second) + "))");
        ++n;
    }
    d->emit("(catalog-end " + std::to_string(n) + ")");
}

// (catalog types): the struct type registry -- one (catalog-type ...) record
// per struct relation, SID-ordered, then (catalog-end <n>).  The durable
// TypeKey is pinned as a field and explicitly #f until N3 resolves it
// (modules.md §8.5.3); the SID is evaluation-local truth today.
static void emit_catalog_types(slog::Daemon* d)
{
    using slog::protocol::quoteString;
    std::map<u32, std::pair<std::string, slog::Relation*>> by_sid;
    for (const auto& kv : d->db()->getRelations())
        if (kv.second != nullptr && kv.second->getStructId() > 0)
            by_sid[kv.second->getStructId()] = { kv.first, kv.second };
    u64 n = 0;
    for (const auto& kv : by_sid)
    {
        d->emit("(catalog-type (sid " + std::to_string(kv.first) + ")"
                + " (name " + quoteString(kv.second.first) + ")"
                + " (arity " + std::to_string(kv.second.second->getArity()) + ")"
                + " (type-key #f))");
        ++n;
    }
    d->emit("(catalog-end " + std::to_string(n) + ")");
}

// Dispatch one '('-line on the command stack.
static void dispatch_command(slog::Daemon* d, const std::string& line)
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
    auto symbol_safe = [](const std::string& s) {
        if (s.empty()) return false;
        for (const char c : s)
            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
                  || (c >= '0' && c <= '9') || std::strchr("-_+*/<=>!?.:$%&^~@", c)))
                return false;
        return true;
    };
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

    if (verb == "continue" || verb == "continue-boundary")
    {
        refuse(d, "parse", "(verb " + verb + ") (detail \"T0 takes the bare "
               "form; parameterized budgets ride the compiled action until "
               "the verb grows arguments\")");
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
        }
        refuse(d, "parse", "(verb catalog) (detail \"expected (catalog), "
               "(catalog relations), or (catalog types)\")");
        return;
    }

    if (verb == "protocol-mode")
    {
        refuse(d, "parse",
               "(verb protocol-mode) (detail \"takes no arguments\")");
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
                          const std::string& line,
                          std::vector<void*>& so_handles)
{
    if (line.empty())
        return;
    if (line[0] == '(')
        dispatch_command(d, line);
    else
        run_plugin(d, line, so_handles);
}

// stdin transport: one plugin path per line, responses to stdout.
static int run_stdin(u32 num_threads)
{
    std::vector<void*> so_handles;
    auto* daemon = new slog::Daemon(num_threads,
        [](const std::string& s) { std::cout << s << std::endl; });

    std::string line;
    while (std::getline(std::cin, line))
    {
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        dispatch_line(daemon, line, so_handles);
    }

    // Delete the daemon (and its database) BEFORE dlclosing: index objects
    // (BTreeIndex<A>) are instantiated in the .so's, so their vtables and
    // destructors live there.
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
            dispatch_line(daemon, line, so_handles);
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

    // Delete the daemon BEFORE dlclosing (vtables live in the .so's).
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
