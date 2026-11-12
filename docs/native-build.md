# Native builds on Linux and macOS

Run builds and Slog from the repository root. macOS supports native arm64 and
x86_64 builds; use a Homebrew installation matching the architecture of your
terminal, Racket, and compiler. Installation commands are in the root Readme.

## One toolchain

`daemon/native.mk` supplies compiler, include paths, OpenMP flags, link paths,
and libraries to the daemon Makefile, `compiler/native-toolchain.rkt`, and the
C++ test harnesses. macOS defaults to `/usr/bin/clang++` (Apple Clang) and the
system libc++. Apple Clang uses `-Xclang -fopenmp` with an external OpenMP
runtime; Apple does not ship that runtime or officially support this OpenMP
configuration. Use a compatible libomp when upgrading Xcode. Apple Clang 15
with libomp 22 on macOS 14 is tested. Linux defaults to `clang++` on PATH.

Homebrew is a convenience for discovering dependency paths, not a requirement
of the runtime. Dependency installation is a separate, manual step; the build
only queries `brew --prefix` to locate an existing installation.
Set `BREW_PREFIX=` to disable discovery entirely and provide
`CPPFLAGS`, `LDFLAGS`, and `LDLIBS` for dependencies installed elsewhere.
Explicit include and link flags precede the discovered dependency paths.

macOS plugins are Mach-O bundles with unresolved host symbols looked up when
loaded. They retain the `.so` cache suffix used throughout the compiler and
protocol. Both foreground and background links use these flags. The daemon
exports the runtime factories those bundles reference. Linux continues to use
ELF shared objects and `-rdynamic`.

Export overrides in the environment so on-demand builds and generated plugins
receive them too, for example:

```sh
export CXX=/path/to/clang++
export CPPFLAGS='-I/path/to/include'
export LDFLAGS='-L/path/to/lib -Wl,-rpath,/path/to/lib'
```

`CXX` names a single executable. Flag variables are whitespace-separated argument
lists on one line (quotes are literal characters, not argument grouping).
For example, `export CPPFLAGS='-DNAME="value"'` preserves the C string literal
in both Make and generated-plugin builds. Paths containing whitespace are not
supported in flag lists. `OMPFLAGS`
and `LDLIBS` may also be overridden. On macOS, `BREW_PREFIX`, `OMP_PREFIX`, and
`OPENSSL_PREFIX` supply optional dependency installation prefixes. Use matching
compiler, libc++, and OpenMP installations. Passing
`CXX=...` only to a standalone make invocation does not configure later Racket
invocations; export it instead.

`CXXFLAGS` retains its Makefile meaning: it replaces the daemon/freezer's
default compilation flags, while generated code selects its own optimization
level and required flags. Put shared ABI options (for example, preprocessor
definitions or target architecture flags) in exported `CPPFLAGS`, not
`CXXFLAGS`, so the daemon and every plugin agree. Use `LDFLAGS` as well when an
option is required during linking.

To use Homebrew LLVM instead of Apple Clang, install it and explicitly select
its prefix (leave `CXX` unset so it follows that prefix):

```sh
brew install llvm
export LLVM_PREFIX="$(brew --prefix llvm)"
```

`LLVM_PREFIX` supplies the compiler and its `lib/c++` and `lib/unwind` search
paths. This optional layout matches Homebrew LLVM. Its libc++abi must use the
matching LLVM unwinder for exception cleanup; the build links both together.
Runtime search paths are embedded, so no `DYLD_LIBRARY_PATH` is needed. Unset
`LLVM_PREFIX` to return to Apple Clang and the system C++ runtime.

For another toolchain layout, use `CXX` and the conventional flag variables
instead of `LLVM_PREFIX`. `OMPFLAGS` defaults to `-Xclang -fopenmp` for Apple
Clang and `-fopenmp` for other Clang installations. `CXX` selects the compiler;
it does not override an explicitly configured `LLVM_PREFIX` runtime layout.

Inspect the resolved settings with `make -s -C daemon print-toolchain`.
Compiler identity, architecture, and effective flags enter native artifact cache
keys, including actions, objects, and precompiled headers. The daemon's
`.toolchain` stamp also rebuilds its binaries and template object when settings
change. On-demand builds are serialized across driver processes with an OS file
lock, preventing concurrent makes from replacing the same binaries or logs.
`make -C daemon clean` removes the build products.

## Memory and solvers

Linux reads current RSS from `/proc/self/statm`; macOS uses Mach task info.
Both support `SLOG_MEM_BYTES` and graceful `memory` pauses. The macOS path has
no systemd/cgroup hard limit. Physical RAM detection uses `sysctl hw.memsize`
on macOS when generating `config/system.slog`.

External SMT solvers run natively on both systems. macOS uses `posix_spawn`
with `POSIX_SPAWN_CLOEXEC_DEFAULT` so concurrently launched solver children
cannot inherit each other's pipe ends. Linux retains atomic `pipe2(O_CLOEXEC)`.

## Tests

The shell suites require Bash 4.4 or later, GNU coreutils, Python 3, and the
normal native dependencies. On macOS:

```sh
brew install bash coreutils python
export PATH="$(brew --prefix)/bin:$(brew --prefix coreutils)/libexec/gnubin:$PATH"
tests/run-all.sh --quick
tests/run-all.sh golden tiered pause api protocol smt-solver
```

The `platform` harness specifically checks actual resident memory growth and
concurrent solver pipe EOF. It is included in both quick and full suites.
The `tiered` harness exercises O0/O2 plugin replacement; `pause` checks graceful
memory limits; `api` covers persistent database operations. Optional real-solver
coverage uses Z3 when installed (`brew install z3`). Run `tests/run-all.sh` for
the complete regression suite.

The existing frontend transcript tests use the legacy `sess_w2.edb` database
fixture normally created by the session suite. Before running `repl` alone in
a fresh checkout, generate it with:

```sh
SLOG_OPT=0 racket compiler/run.rkt --no-banner --out-db-compressed sess_w2 --per 100 tests/session/base.slog
tests/run-all.sh repl
```
