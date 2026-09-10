.DEFAULT_GOAL := slogd
include native.mk

# -ffp-contract=off: match the flag generated plugin .so's are built with
# (compiler/tools.rkt) so float primitives contract FMA identically across the
# daemon and every plugin -- and, critically, identically between an -O0 plugin
# and its -O2 hot-swap replacement (docs/fast-compile.md §7.5).
CXXFLAGS ?= -O2 -Wall -std=c++20 -pthread -I. -ffp-contract=off
HEADERS = $(wildcard *.h)
NATIVE_COMPILE = $(call native-quote,$(CXX)) $(call native-argv,$(CPPFLAGS) $(NATIVE_CPPFLAGS))
NATIVE_LINK = $(call native-argv,$(LDFLAGS) $(NATIVE_LDFLAGS))

# Registration is cold, but constructing tasks also instantiates their hot
# virtual work() methods and storage operations across the full arity range.
# Use normal daemon optimization: mixed-O0/O2 template definitions can select
# an unoptimized lookup at link time (observed on macOS). Keep this expensive
# compilation in its own cached object for unrelated daemon source edits.
plan-flavored-tasks.o: plan-flavored-tasks.cpp $(HEADERS) .toolchain
	$(NATIVE_COMPILE) $(call native-argv,$(CXXFLAGS) $(OMPFLAGS)) -c plan-flavored-tasks.cpp -o plan-flavored-tasks.o

slogd: slogd.cpp plan.cpp plan-count.cpp program-image.cpp query.cpp sexp.cpp runtime.cpp plan-flavored-tasks.o $(HEADERS) .toolchain
	$(NATIVE_COMPILE) $(call native-argv,$(CXXFLAGS) $(OMPFLAGS)) $(NATIVE_LINK) $(call native-argv,$(EXPORT_LDFLAGS)) -o slogd slogd.cpp plan.cpp plan-count.cpp program-image.cpp query.cpp sexp.cpp runtime.cpp plan-flavored-tasks.o $(call native-argv,$(LDLIBS))

# The freezer: a fact stream on stdin -> a static .bin database (freeze.cpp).
# Links the same headers as slogd so every value encodes through the one
# canonical implementation (strings/ints/sequences/struct interning).  Built
# on demand by the compiler driver (tools.rkt), not by the default target.
slog-freeze: freeze.cpp $(HEADERS) .toolchain
	$(NATIVE_COMPILE) $(call native-argv,$(CXXFLAGS) $(OMPFLAGS)) $(NATIVE_LINK) -o slog-freeze freeze.cpp $(call native-argv,$(LDLIBS))

test: slogd
	printf '(close)\n' | racket slogd.rkt

# Compile-only check that the production-neutral T2 interpreter core remains
# independently includable even though slogd now also links the A2/A3 plan,
# factory, and scheduler integration.
interp-check:
	$(NATIVE_COMPILE) $(call native-argv,$(CXXFLAGS) $(OMPFLAGS)) -Wno-pragma-once-outside-header -fsyntax-only -x c++ interp.h

clean:
	rm -f slogd slog-freeze plan-flavored-tasks.o .toolchain

.PHONY: test interp-check clean

# Flag/compiler changes must rebuild binaries and the task template object.
# Preserve the stamp's mtime when unchanged, so a warm invocation is a no-op.
.PHONY: FORCE
.toolchain: FORCE
	@tmp=$$(mktemp .toolchain.XXXXXX) && \
	  { $(MAKE) --no-print-directory -s print-toolchain; printf '%s\n' $(call native-quote,$(CXXFLAGS)) $(call native-quote,$(EXPORT_LDFLAGS)); $(call native-quote,$(CXX)) --version; } > "$$tmp" && \
	  { if cmp -s "$$tmp" $@; then rm -f "$$tmp"; else mv -f "$$tmp" $@; fi; }
