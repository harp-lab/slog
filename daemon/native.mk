# Shared native toolchain for the daemon, freezer, generated plugins and tests.
# Export CXX/CPPFLAGS/OMPFLAGS/LDFLAGS/LDLIBS when overriding these so the
# compiler driver and make use the same ABI and OpenMP runtime.
# Match the driver's literal whitespace-separated argv, including quotes in
# macro definitions. Do not let the recipe shell reinterpret flag contents.
native-quote = '$(subst ','"'"',$(1))'
native-argv = $(foreach arg,$(1),$(call native-quote,$(arg)))

NATIVE_OS := $(shell uname -s)
ifeq ($(NATIVE_OS),Darwin)
# Homebrew is optional dependency discovery. Set BREW_PREFIX= to disable it
# and supply conventional CPPFLAGS/LDFLAGS/LDLIBS for another installation.
ifeq ($(origin BREW_PREFIX),undefined)
BREW_PREFIX := $(shell brew --prefix 2>/dev/null)
endif
OMP_PREFIX ?= $(if $(BREW_PREFIX),$(BREW_PREFIX)/opt/libomp)
OPENSSL_PREFIX ?= $(if $(BREW_PREFIX),$(BREW_PREFIX)/opt/openssl@3)
ifeq ($(filter default undefined,$(origin CXX)), $(origin CXX))
CXX := $(if $(LLVM_PREFIX),$(LLVM_PREFIX)/bin/clang++,/usr/bin/clang++)
endif
NATIVE_CPPFLAGS = $(addprefix -I,$(addsuffix /include,$(OMP_PREFIX) $(OPENSSL_PREFIX) $(BREW_PREFIX)))
NATIVE_LDFLAGS = $(addprefix -L,$(addsuffix /lib,$(OMP_PREFIX) $(OPENSSL_PREFIX) $(BREW_PREFIX))) $(foreach prefix,$(OMP_PREFIX),-Wl,-rpath,$(prefix)/lib)
NATIVE_LIBS =
# An explicit LLVM installation can provide its own libc++ and unwinder.
# These paths match Homebrew LLVM; no replacement C++ runtime is used by default.
ifneq ($(strip $(LLVM_PREFIX)),)
NATIVE_LDFLAGS += -L$(LLVM_PREFIX)/lib/c++ -Wl,-rpath,$(LLVM_PREFIX)/lib/c++ -L$(LLVM_PREFIX)/lib/unwind -Wl,-rpath,$(LLVM_PREFIX)/lib/unwind
# Exception cleanup must use the same unwinder as that installation's libc++abi.
NATIVE_LIBS += -lunwind
endif
# Apple Clang accepts OpenMP through its frontend, but needs an external libomp.
ifneq ($(findstring Apple,$(shell $(call native-quote,$(CXX)) --version 2>/dev/null)),)
OMPFLAGS ?= -Xclang -fopenmp
NATIVE_LIBS += -lomp
endif
PLUGIN_LDFLAGS = -bundle -Wl,-undefined,dynamic_lookup
EXPORT_LDFLAGS = -Wl,-export_dynamic
else
ifeq ($(filter default undefined,$(origin CXX)), $(origin CXX))
CXX = clang++
endif
PLUGIN_LDFLAGS = -shared
EXPORT_LDFLAGS = -rdynamic
NATIVE_LIBS = -ldl
endif
OMPFLAGS ?= -fopenmp
LDLIBS ?= -lz -lgmp -lcrypto $(strip $(NATIVE_LIBS))

# One field per line, consumed without shell evaluation by tools.rkt and the
# test harness. CXX is a single executable; flag variables are whitespace lists.
.PHONY: print-toolchain
print-toolchain:
	@printf '%s\n' $(call native-quote,$(CXX)) $(call native-quote,$(CPPFLAGS) $(NATIVE_CPPFLAGS)) $(call native-quote,$(OMPFLAGS)) $(call native-quote,$(LDFLAGS) $(NATIVE_LDFLAGS)) $(call native-quote,$(PLUGIN_LDFLAGS)) $(call native-quote,$(LDLIBS)) $(call native-quote,$(SDKROOT)) $(call native-quote,$(MACOSX_DEPLOYMENT_TARGET))
