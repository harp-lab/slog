# Slog versions

The repository-root `.version` file is the single source of truth for Slog's
product version. Racket and Rust read that file; product version strings must
not be hard-coded in either implementation.

Each released or development-line version has a matching Markdown file here.
That note records the user-visible reason for the bump, not an exhaustive
commit log.

Versioning habit:

- A substantial user-visible feature or architectural milestone bumps at
  least the minor version in the same commit (`3.0.0` → `3.1.0`).
- A compatibility-breaking release boundary bumps the major version.
- Focused compatible corrections may bump the patch version when released.
- Every bump updates `.version` and adds its corresponding note before commit.

The Rust crate's Cargo package version describes the private frontend package;
the Slog product version shown by the application always comes from `.version`.
