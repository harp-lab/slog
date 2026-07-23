//! Durable shell events and presentation-neutral plain rendering.

use crate::command::{CommandOrigin, ShellCommand};

#[derive(Clone, Copy, Debug, Eq, PartialEq)]
pub enum EntryKind {
    Command,
    GeneratedCommand,
    Comment,
    Presence,
    Result,
    Error,
    System,
}

#[derive(Debug)]
pub struct TranscriptEntry {
    pub kind: EntryKind,
    pub title: String,
    pub lines: Vec<String>,
    /// Human or tool responsible for generated input. Command context stays
    /// in `title`; presentation can keep authorship compact and independent.
    pub actor: Option<String>,
    /// Canonical input for command/comment events. Result and lifecycle events
    /// deliberately have no command of their own.
    pub command: Option<ShellCommand>,
}

impl TranscriptEntry {
    pub fn command(command: ShellCommand, title: impl Into<String>) -> Self {
        let kind = match command.origin() {
            CommandOrigin::Local => EntryKind::Command,
            CommandOrigin::Generated | CommandOrigin::Coauthor(_) => EntryKind::GeneratedCommand,
        };
        let actor = command.origin().actor().map(str::to_owned);
        let lines = command.text().lines().map(str::to_owned).collect();
        Self {
            kind,
            title: title.into(),
            lines,
            actor,
            command: Some(command),
        }
    }

    pub fn comment(command: ShellCommand, title: impl Into<String>) -> Self {
        let actor = command.origin().actor().map(str::to_owned);
        let lines = command.text().lines().map(str::to_owned).collect();
        Self {
            kind: EntryKind::Comment,
            title: title.into(),
            lines,
            actor,
            command: Some(command),
        }
    }

    pub fn result(title: impl Into<String>, lines: Vec<String>) -> Self {
        Self::message(EntryKind::Result, title, lines)
    }

    pub fn error(title: impl Into<String>, lines: Vec<String>) -> Self {
        Self::message(EntryKind::Error, title, lines)
    }

    pub fn system(title: impl Into<String>, lines: Vec<String>) -> Self {
        Self::message(EntryKind::System, title, lines)
    }

    pub fn presence(message: impl Into<String>) -> Self {
        Self::message(EntryKind::Presence, message, Vec::new())
    }

    fn message(kind: EntryKind, title: impl Into<String>, lines: Vec<String>) -> Self {
        Self {
            kind,
            title: title.into(),
            lines,
            actor: None,
            command: None,
        }
    }

    pub fn plain(&self) -> String {
        match self.kind {
            EntryKind::Comment => self.lines.join("\n"),
            EntryKind::Command | EntryKind::GeneratedCommand => format!(
                "› {}{}",
                self.command
                    .as_ref()
                    .map(|command| command.text().replace('\n', "\n  "))
                    .unwrap_or_else(|| self.lines.join("\n  ")),
                self.actor
                    .as_deref()
                    .map(|actor| format!("  — {actor}"))
                    .unwrap_or_default()
            ),
            EntryKind::Presence => format!("· {}", self.title),
            EntryKind::Result => {
                let body = self.lines.join("\n  ");
                if body.is_empty() {
                    format!("◆ {}", self.title)
                } else {
                    format!("◆ {}\n  {body}", self.title)
                }
            }
            EntryKind::Error => format!("! {}\n  {}", self.title, self.lines.join("\n  ")),
            EntryKind::System => format!("• {}\n  {}", self.title, self.lines.join("\n  ")),
        }
    }
}

#[derive(Debug)]
pub struct SharedAction {
    pub command: ShellCommand,
}

impl SharedAction {
    pub fn generated(source: impl Into<String>) -> Option<Self> {
        ShellCommand::generated(source).map(|command| Self { command })
    }

    pub fn coauthor(actor: impl Into<String>, source: impl Into<String>) -> Option<Self> {
        ShellCommand::coauthor(actor, source).map(|command| Self { command })
    }
}

impl SharedAction {
    pub fn plain(&self) -> String {
        format!(
            "› {}{}",
            self.command.text(),
            self.command
                .origin()
                .actor()
                .map(|actor| format!("  — {actor}"))
                .unwrap_or_default()
        )
    }
}

pub fn render_plain<'a>(entries: impl IntoIterator<Item = &'a TranscriptEntry>) -> String {
    entries
        .into_iter()
        .map(TranscriptEntry::plain)
        .collect::<Vec<_>>()
        .join("\n")
}

#[cfg(test)]
mod tests {
    use super::{TranscriptEntry, render_plain};
    use crate::command::ShellCommand;

    #[test]
    fn one_event_stream_renders_commands_comments_and_results_plainly() {
        let events = [
            TranscriptEntry::command(
                ShellCommand::coauthor("codex", "tables edge").expect("command"),
                "example",
            ),
            TranscriptEntry::comment(
                ShellCommand::coauthor("codex", "; edge is sparse").expect("comment"),
                "codex",
            ),
            TranscriptEntry::result("Live relations", vec!["edge/2 · 3 rows".to_owned()]),
        ];
        assert_eq!(
            render_plain(&events),
            "› tables edge  — codex\n; edge is sparse\n◆ Live relations\n  edge/2 · 3 rows"
        );
    }

    #[test]
    fn multiline_commands_have_one_canonical_plain_projection() {
        let event = TranscriptEntry::command(
            ShellCommand::local("rule (edge X Y)\n  --> (path X Y)").expect("command"),
            "scratch",
        );
        assert_eq!(event.plain(), "› rule (edge X Y)\n    --> (path X Y)");
    }
}
