//! Canonical shell input shared by the terminal, generated gestures, and
//! co-author connections.
//!
//! Classification is intentionally shallow. Rust identifies the interaction
//! register and a few client-owned commands; Racket remains authoritative for
//! Slog syntax and semantic command validation.

#[derive(Clone, Copy, Debug, Eq, PartialEq)]
pub enum CommandKind {
    Meta,
    Observation,
    Mutation,
    Source,
    Comment,
    /// Compatibility command whose final semantics still belong to Racket.
    Legacy,
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub enum CommandOrigin {
    Local,
    Generated,
    Coauthor(String),
}

impl CommandOrigin {
    pub fn actor(&self) -> Option<&str> {
        match self {
            Self::Coauthor(actor) => Some(actor),
            Self::Local | Self::Generated => None,
        }
    }
}

#[derive(Clone, Copy, Debug, Eq, PartialEq)]
pub enum CommandVisibility {
    Shared,
    Private,
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct ShellCommand {
    text: String,
    kind: CommandKind,
    origin: CommandOrigin,
    visibility: CommandVisibility,
}

impl ShellCommand {
    pub fn local(source: impl Into<String>) -> Option<Self> {
        Self::new(source, CommandOrigin::Local, CommandVisibility::Shared)
    }

    pub fn generated(source: impl Into<String>) -> Option<Self> {
        Self::new(source, CommandOrigin::Generated, CommandVisibility::Shared)
    }

    pub fn coauthor(actor: impl Into<String>, source: impl Into<String>) -> Option<Self> {
        Self::new(
            source,
            CommandOrigin::Coauthor(actor.into()),
            CommandVisibility::Shared,
        )
    }

    pub fn private(actor: impl Into<String>, source: impl Into<String>) -> Option<Self> {
        Self::new(
            source,
            CommandOrigin::Coauthor(actor.into()),
            CommandVisibility::Private,
        )
    }

    fn new(
        source: impl Into<String>,
        origin: CommandOrigin,
        visibility: CommandVisibility,
    ) -> Option<Self> {
        let source = source.into();
        let text = source.trim();
        if text.is_empty() {
            return None;
        }
        Some(Self {
            kind: classify(text),
            text: text.to_owned(),
            origin,
            visibility,
        })
    }

    pub fn text(&self) -> &str {
        &self.text
    }

    pub fn into_text(self) -> String {
        self.text
    }

    pub fn kind(&self) -> CommandKind {
        self.kind
    }

    pub fn origin(&self) -> &CommandOrigin {
        &self.origin
    }

    pub fn visibility(&self) -> CommandVisibility {
        self.visibility
    }

    pub fn verb(&self) -> &str {
        self.text.split_whitespace().next().unwrap_or("")
    }

    pub fn argument(&self) -> &str {
        self.text
            .split_once(char::is_whitespace)
            .map(|(_, argument)| argument.trim())
            .unwrap_or("")
    }

    pub fn is_comment(&self) -> bool {
        self.kind == CommandKind::Comment
    }

    pub fn is_view_command(&self) -> bool {
        self.text == "library close" || self.text.starts_with("library select ")
    }

    pub fn database_to_open(&self) -> Option<&str> {
        matches!(self.verb(), "open" | "use" | ":open")
            .then(|| self.argument())
            .filter(|argument| !argument.is_empty())
    }

    /// Private co-author commands may observe but never mutate shared state.
    /// Client-local meta commands are intentionally listed rather than
    /// granting every future `:` command by default.
    pub fn private_allowed(&self) -> bool {
        if self.visibility != CommandVisibility::Private {
            return false;
        }
        if self.kind == CommandKind::Observation {
            return true;
        }
        matches!(
            self.verb().to_ascii_lowercase().as_str(),
            ":help"
                | ":ping"
                | ":status"
                | "help"
                | "?"
                | "ping"
                | "status"
                | "library"
                | "current"
                | "database"
                | "resident"
                | "sessions"
                | "tables"
                | "rels"
                | "relations"
                | "state"
                | "states"
                | "count"
                | "show"
                | "query"
                | "has"
                | "schema"
                | "pipeline"
        )
    }
}

fn classify(text: &str) -> CommandKind {
    if text.starts_with(';') {
        return CommandKind::Comment;
    }
    if text == "?" {
        // Compatibility alias for :help until the query register claims it.
        return CommandKind::Meta;
    }
    if text.starts_with(':') {
        return CommandKind::Meta;
    }
    if text.starts_with('?') {
        return CommandKind::Observation;
    }
    if text.starts_with('!') {
        return CommandKind::Mutation;
    }

    // Most `image` forms only inspect the connection-scoped control catalog,
    // but RF3 activation appends executable strata and therefore belongs in
    // the mutation lane (including its read-only/private-lane protections).
    let words: Vec<_> = text.split_whitespace().collect();
    if words.len() == 3
        && words[0].eq_ignore_ascii_case("image")
        && words[2].eq_ignore_ascii_case("activate")
    {
        return CommandKind::Mutation;
    }

    match text
        .split_whitespace()
        .next()
        .unwrap_or("")
        .to_ascii_lowercase()
        .as_str()
    {
        "rule" | "table" | "struct" | "lattice" | "enum" | "union" | "module" | "import"
        | "include" => CommandKind::Source,
        "tables" | "rels" | "relations" | "state" | "states" | "count" | "show" | "query"
        | "has" | "images" => CommandKind::Observation,
        "run" | "add" | "del" | "rename" | "drop" | "save" | "csv-import" => CommandKind::Mutation,
        "help" | "ping" | "status" | "quit" | "exit" | "library" | "open" | "use" | "current"
        | "database" | "resident" | "sessions" | "discard" | "mode" | "schema" | "pipeline"
        | "image" | "expand" | "collapse" | "card" | "search" | "search-next"
        | "search-previous" | "search-clear" => CommandKind::Meta,
        _ => CommandKind::Legacy,
    }
}

#[cfg(test)]
mod tests {
    use super::{CommandKind, CommandOrigin, CommandVisibility, ShellCommand};

    #[test]
    fn classifies_the_five_shell_registers_without_parsing_slog() {
        let cases = [
            (":status", CommandKind::Meta),
            ("expand it.change", CommandKind::Meta),
            ("card it.change", CommandKind::Meta),
            ("search edge", CommandKind::Meta),
            ("?(edge X _)", CommandKind::Observation),
            ("!run s45", CommandKind::Mutation),
            ("image abc123 activate", CommandKind::Mutation),
            ("csv-import examples/edges", CommandKind::Mutation),
            ("rule (edge X Y) --> (path X Y)", CommandKind::Source),
            ("; inspect edge next", CommandKind::Comment),
            ("future-server-verb x", CommandKind::Legacy),
        ];
        for (source, expected) in cases {
            assert_eq!(
                ShellCommand::local(source).expect("command").kind(),
                expected
            );
        }
    }

    #[test]
    fn retains_origin_visibility_and_canonical_text() {
        let command = ShellCommand::private("codex", "  ?count edge  ").expect("command");
        assert_eq!(command.text(), "?count edge");
        assert_eq!(command.visibility(), CommandVisibility::Private);
        assert_eq!(
            command.origin(),
            &CommandOrigin::Coauthor("codex".to_owned())
        );
        assert!(command.private_allowed());
    }

    #[test]
    fn private_lane_is_allowlisted_and_never_accepts_mutation() {
        assert!(
            ShellCommand::private("codex", "tables edge")
                .expect("command")
                .private_allowed()
        );
        assert!(
            ShellCommand::private("codex", ":status")
                .expect("command")
                .private_allowed()
        );
        assert!(
            !ShellCommand::private("codex", ":quit")
                .expect("command")
                .private_allowed()
        );
        assert!(
            !ShellCommand::private("codex", "!run s45")
                .expect("command")
                .private_allowed()
        );
    }

    #[test]
    fn recognizes_database_and_view_commands_for_ui_adapters() {
        let open = ShellCommand::generated("open example").expect("command");
        assert_eq!(open.database_to_open(), Some("example"));
        assert!(
            ShellCommand::coauthor("codex", "library select beta")
                .expect("command")
                .is_view_command()
        );
    }
}
