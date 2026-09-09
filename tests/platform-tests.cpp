// Native OS seams: current RSS and concurrent solver pipe ownership.
// Run through tests/run-all.sh platform to use the production toolchain.
#include "slogd.h"
#include <cassert>
#include <iostream>

int main()
{
  const auto before = slog::readRSSbytes();
  assert(before > 0);
  // Touch each page so this measures resident memory, not a virtual reservation.
  constexpr size_t bytes = 32 * 1024 * 1024;
  auto memory = std::make_unique<volatile char[]>(bytes);
  for (size_t i = 0; i < bytes; i += 4096) memory[i] = 1;
  assert(slog::readRSSbytes() >= before + bytes / 2);

  // Keep slow children alive while short children finish. An inherited pipe
  // write end delays the short child's EOF until a sibling exits. Bound every
  // read so a regression fails rather than hanging the test harness.
  std::atomic<bool> ok{true};
  std::vector<std::thread> workers;
  for (int t = 0; t < 8; ++t)
    workers.emplace_back([&] {
      for (int i = 0; i < 8; ++i)
      {
        pid_t slow = -1, fast = -1;
        int slow_in = -1, slow_out = -1, in = -1, out = -1;
        assert(slog::smtSpawn({"/bin/sleep", "5"}, slow, slow_in, slow_out));
        assert(slog::smtSpawn({"/bin/cat"}, fast, in, out));
        assert(slog::smtWriteAll(in, "native\n"));
        close(in);
        std::string result;
        bool eof = false;
        const auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(3);
        while (std::chrono::steady_clock::now() < deadline)
        {
          pollfd p{out, POLLIN | POLLHUP, 0};
          if (poll(&p, 1, 100) <= 0) continue;
          char buffer[64];
          auto n = read(out, buffer, sizeof(buffer));
          if (n == 0) { eof = true; break; }
          if (n < 0) { if (errno == EINTR) continue; break; }
          result.append(buffer, static_cast<size_t>(n));
        }
        if (!eof || result != "native\n") ok = false;
        close(out); close(slow_in); close(slow_out);
        kill(slow, SIGKILL);
        if (!eof) kill(fast, SIGKILL);
        while (waitpid(slow, nullptr, 0) < 0 && errno == EINTR) {}
        while (waitpid(fast, nullptr, 0) < 0 && errno == EINTR) {}
      }
    });
  for (auto& worker : workers) worker.join();
  assert(ok);
  std::cout << "PASS current RSS and concurrent solver pipes\n";
}
