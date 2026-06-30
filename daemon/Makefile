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
CXXFLAGS ?= -O2 -Wall -std=c++20 -pthread -I.
LDLIBS = -lz -ldl

HEADERS = $(wildcard *.h)

slogd: slogd.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OMPFLAGS) -o slogd slogd.cpp $(LDLIBS)

test: slogd
	printf '(close)\n' | racket slogd.rkt

clean:
	rm -f slogd

.PHONY: test clean
