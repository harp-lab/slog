# Compiler is parametric; defaults to clang.  Override with e.g. `make CXX=g++`.
# NOTE: we pin clang++-18 because the installed libomp/omp.h is the v18 package
# (the default clang++ is v20, whose -fopenmp can't find omp.h or link -lomp).
# The generated .so (compiler/tools.rkt) must use the SAME compiler so it shares
# one OpenMP runtime -- omp_get_thread_num() in the .so depends on that.
# Plain '=' (not '?=') because make pre-defines CXX=g++ as a built-in, which
# '?=' would NOT override -- that mismatch links the daemon against libgomp
# while the .so uses libomp.  A command-line `make CXX=...` still overrides this.
# The generated .so (compiler/tools.rkt) must use the SAME compiler so the two
# share one OpenMP runtime (the .so calls omp_get_thread_num()).  On another
# machine, ensure the matching libomp-<ver>-dev for your clang is installed.
CXX = clang++
OMPFLAGS ?= -fopenmp
# -ffp-contract=off: match the flag generated plugin .so's are built with
# (compiler/tools.rkt) so float primitives contract FMA identically across the
# daemon and every plugin -- and, critically, identically between an -O0 plugin
# and its -O2 hot-swap replacement (docs/fast-compile.md §7.5).
CXXFLAGS ?= -O2 -Wall -std=c++20 -pthread -I. -ffp-contract=off
# -rdynamic exports the daemon's symbols (notably slog::makeIndex/makeMapIndex,
# now defined out-of-line in slogd.cpp) into the dynamic symbol table so dlopen'd
# plugins resolve them instead of instantiating the arity ladders themselves.
LDFLAGS ?= -rdynamic
LDLIBS = -lz -ldl -lgmp

HEADERS = $(wildcard *.h)

slogd: slogd.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OMPFLAGS) $(LDFLAGS) -o slogd slogd.cpp $(LDLIBS)

# The freezer: a fact stream on stdin -> a static .bin database (freeze.cpp).
# Links the same headers as slogd so every value encodes through the one
# canonical implementation (strings/ints/sequences/struct interning).  Built
# on demand by the compiler driver (tools.rkt), not by the default target.
slog-freeze: freeze.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OMPFLAGS) -o slog-freeze freeze.cpp $(LDLIBS)

test: slogd
	printf '(close)\n' | racket slogd.rkt

clean:
	rm -f slogd slog-freeze

.PHONY: test clean
