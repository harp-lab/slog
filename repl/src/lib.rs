//! Presentation-neutral state for the native Slog REPL.
//!
//! The terminal binary owns processes, sockets, and rendering. These modules
//! stay independently testable so later compiler/session integration does not
//! become coupled to Ratatui or the event loop.

pub mod command;
pub mod completion;
pub mod operation;
pub mod present;
pub mod response;
pub mod runtime;
pub mod transcript;
pub mod workspace;
