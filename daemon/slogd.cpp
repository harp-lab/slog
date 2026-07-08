/** Slog Daemon
 *
 * A multi-threaded backend for the deductive database and language Slog.
 *
 * The entire client protocol is one line per message, each line a path to
 * a plugin shared object.  Each plugin is dlopen'd and its
 *
 *     extern "C" void slog_plugin(slog::Daemon*)
 *
 * called with the daemon object (daemon.h) -- the API through which plugins
 * push strata of rules, run the pipeline, read/write the database on disk,
 * inspect relations, and send results back over the connection.  Anything a
 * client wants of the database -- including one-off queries like a relation
 * count -- it expresses by compiling a (tiny, cached) plugin and sending
 * its path.
 *
 * Two transports:
 *
 *   slogd [-t N]           read plugin paths from stdin, responses to
 *                          stdout (used by the compiler driver,
 *                          compiler/runslog.rkt)
 *   slogd [-t N] -p PORT   connect back to a TCP parent on PORT; plugin
 *                          paths arrive as lines, responses are sent as
 *                          s-expressions (used by the interactive console,
 *                          daemon/slogd.rkt).  A 2s idle heartbeat emits
 *                          (pending); the transport-level (close) line is
 *                          answered with (bye <unixtime>) before exiting.
 *
 * -t N sets the worker thread count (default 6).
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2023-2025
 * Some rights reserved. See License.md for details.
 *
 ******************************/

#include "daemon.h"

#include <dlfcn.h>
#include <string>
#include <vector>
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

// Out-of-line definitions of the runtime index factories (declared in index.h).
// Keeping the 1..32 arity dispatch ladders here means they are instantiated
// exactly once -- in this daemon binary -- instead of in every generated plugin
// .so (which otherwise paid to instantiate BTreeIndex<1..32> and
// BTreeMapIndex<1..32> even though it only ever uses a handful of arities).
// Plugins resolve these through slogd's exported dynamic symbols (the Makefile
// links slogd with -rdynamic).  See docs/fast-compile.md §7.1.
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
        // The literal (continue) does one bounded unit of work (docs/pausing.md
        // §5) without a plugin, so a driver/console can resume a suspended
        // stratum with no clang build.  The (continue [ms] [mem]) action .so
        // still exists for parameterized budgets.
        if (line == "(continue)")
            daemon->continueRun();
        else if (line == "(continue-boundary)")
            daemon->continueToBoundary();
        else if (!line.empty())
            run_plugin(daemon, line, so_handles);
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
            // (continue): one bounded unit of work, no plugin (docs/pausing.md §5).
            // (continue-boundary): the same but stop at the next iteration
            // boundary (docs/fast-compile.md §4), the hot-swap-safe stop point.
            if (line == "(continue)")
                daemon->continueRun();
            else if (line == "(continue-boundary)")
                daemon->continueToBoundary();
            else if (!line.empty())
                run_plugin(daemon, line, so_handles);
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
