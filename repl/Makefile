.PHONY: all debug release check test clean

all: debug

debug:
	cargo build
	cp target/debug/slog ../slog

release:
	cargo build --release
	cp target/release/slog ../slog

check:
	cargo check

test:
	cargo test

clean:
	cargo clean
	rm -f ../slog

