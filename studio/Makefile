.PHONY: all debug release check test clean

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

clean:
	cargo clean
	rm -f ../slog-studio ../.slog-studio.new
