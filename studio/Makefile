.PHONY: all debug release check test test-web clean

all: debug

debug:
	cargo build
	cp target/debug/slog-studio ../.slog-studio.new
	mv ../.slog-studio.new ../slog-studio

release:
	cargo build --release
	cp target/release/slog-studio ../.slog-studio.new
	mv ../.slog-studio.new ../slog-studio

check:
	cargo check

test:
	cargo test

# The browser modules' pure logic, under macOS's JavaScriptCore shell. The
# .slog files are a corpus for the invariant checks, which try every cursor
# position; CORPUS=... runs them over other programs.
JSC = /System/Library/Frameworks/JavaScriptCore.framework/Versions/Current/Helpers/jsc
CORPUS = examples/reach/reach.slog ../examples/kcfa/syntax.slog ../examples/tinycfa/0cfa.slog
test-web:
	$(JSC) -m web/test/run.js -- $(CORPUS)

clean:
	cargo clean
	rm -f ../slog-studio ../.slog-studio.new

test-web:
	/System/Library/Frameworks/JavaScriptCore.framework/Versions/Current/Helpers/jsc -m web/tests/trace.test.mjs
