//! Presentation-neutral state for the native Slog REPL.
//!
//! The terminal binary owns rendering and its event loop. These modules stay
//! independently testable and free of Ratatui, so other frontends (Slog
//! Studio) share them: `server` launches the Racket session server and
//! `protocol` speaks to it.

pub mod command;
pub mod completion;
pub mod operation;
pub mod present;
pub mod protocol;
pub mod response;
pub mod runtime;
pub mod server;
pub mod transcript;
pub mod tutorial;
pub mod workspace;
