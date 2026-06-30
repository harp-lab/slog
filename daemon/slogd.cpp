/** Slog Daemon
 *
 * A multi-threaded backend for the deductive database and language Slog.
 *
 * Accepts line-delimited commands in one of two modes:
 *
 *   slogd            read commands from stdin, results to stdout
 *                    (used by the compiler driver, compiler/runslog.rkt)
 *   slogd -p PORT    connect back to a TCP parent on PORT and exchange
 *                    commands/results as s-expressions (used by the
 *                    interactive console, daemon/slogd.rkt).  A 2s idle
 *                    heartbeat emits (pending); (close) is answered with
 *                    (bye <unixtime>) before exiting.
 *
 * In both modes a command that reaches a fixpoint emits (fixpoint).
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2023-2025
 * Some rights reserved. See License.md for details.
 *
 ******************************/

#include "slogd.h"

#include <dlfcn.h>
#include <string>
#include <vector>
#include <cstring>
#include <chrono>
#include <functional>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <poll.h>

// Constants
namespace {
    constexpr u32 DEFAULT_NUM_THREADS = 6;
    constexpr u32 MIN_THREADS = 1;
    constexpr u32 MAX_THREADS = 256;
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

// Execute a single line-delimited command.  Any user-facing output is
// emitted as an s-expression through `emit` (to the socket or to stdout
// depending on mode); diagnostic chatter has been removed (see debug.h).
using Emit = std::function<void(const std::string&)>;

static void process_command(const Emit& emit,
                            const std::string& line,
                            slog::Database*& db,
                            std::vector<void*>& so_handles,
                            u32& num_threads)
{
    std::string cmd = line;

    if (cmd.substr(0,4) == "run:")
    {
        cmd = cmd.substr(4);
        if (db == 0) slog::fatal("No database to run a program on!");
        db->runProgram();
        emit("(fixpoint)");
    }
    else if (cmd.substr(0,5) == "load:")
    {
        cmd = cmd.substr(5);
        if (db == 0) slog::fatal("No database to load a program for!");
        so_handles.push_back(dlopen(cmd.c_str(), RTLD_LAZY));
        if (so_handles[so_handles.size()-1] == 0)
            slog::fatal(std::string("Failed to load ")+cmd);
        auto loadP = (void (*)(slog::Database*))dlsym(so_handles[so_handles.size()-1], "loadProgram");
        if (loadP == 0) slog::fatal(std::string("Could not load loadProgram() for ") + cmd);
        loadP(db);
    }
    else if (cmd.substr(0,6) == "write:")
    {
        cmd = cmd.substr(6);
        if (db == 0) slog::fatal("No database to write!");
        db->writeDatabaseBIN(cmd);
    }
    else if (cmd.substr(0,9) == "writeCSV:")
    {
        cmd = cmd.substr(9);
        if (db == 0) slog::fatal("No database to write!");
        db->writeDatabaseCSV(cmd);
    }
    else if (cmd.substr(0,5) == "open:")
    {
        cmd = cmd.substr(5);
        db = new slog::Database(cmd, num_threads);
    }
    else if (cmd.substr(0,4) == "new:")
    {
        db = new slog::Database(num_threads);
    }
    else if (cmd.substr(0,7) == "reload:")
    {
        db->reloadInsertBatches();
    }
    else if (cmd.substr(0,8) == "threads:")
    {
        cmd = cmd.substr(8);
        num_threads = std::min(std::max(static_cast<u32>(std::atoi(cmd.c_str())), MIN_THREADS), MAX_THREADS);
    }
}

// Legacy mode: read newline-delimited commands from stdin, results to
// stdout.  This is what the compiler driver (compiler/runslog.rkt) uses.
static int run_stdin()
{
    slog::Database* db = 0;
    std::vector<void*> so_handles;
    u32 num_threads = DEFAULT_NUM_THREADS;

    auto emit = [](const std::string& s) { std::cout << s << std::endl; };

    std::string line;
    while (std::getline(std::cin, line))
    {
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        if (!line.empty())
            process_command(emit, line, db, so_handles, num_threads);
    }

    // Delete the database BEFORE dlclosing: index objects (BTreeIndex<A>)
    // are instantiated in the .so, so their vtables/destructors live there.
    if (db) delete db;
    for (void* h : so_handles) if (h) dlclose(h);
    return 0;
}

// TCP mode: connect back to a parent on `port` and exchange s-expressions.
static int run_tcp(int port)
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

    // Daemon state, owned by this connection.
    slog::Database* db = 0;
    std::vector<void*> so_handles;
    u32 num_threads = DEFAULT_NUM_THREADS;

    auto emit = [sock](const std::string& s) { send_msg(sock, s); };

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
            break;

        int valread = read(sock, buffer, sizeof(buffer));

        if (valread <= 0)
            break;

        inbuf.append(buffer, valread);

        // Dispatch complete, newline-terminated commands in order; a
        // (close) is handled in sequence so any queued commands still run.
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
            if (!line.empty())
                process_command(emit, line, db, so_handles, num_threads);
        }
        if (done)
            break;

        // The driver's EOF path sends a bare (close) with no newline.
        if (inbuf.find("(close)") != std::string::npos)
        {
            send_bye(sock);
            break;
        }
    }

    // Close shared-object handles, delete the database, and exit.
    // Delete the database BEFORE dlclosing: index objects (BTreeIndex<A>)
    // are instantiated in the .so, so their vtables/destructors live there.
    if (db) delete db;
    for (void* h : so_handles) if (h) dlclose(h);
    close(sock);
    return 0;
}

int main(int argc, char* argv[])
{
    if (argc >= 3 && std::strcmp(argv[1], "-p") == 0)
        return run_tcp(std::stoi(argv[2]));

    // No -p: legacy stdin command mode (used by the compiler driver).
    return run_stdin();
}
