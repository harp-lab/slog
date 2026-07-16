use crate::backend::BackendEvent;
use crate::editor::Editor;
use crossterm::event::{Event, KeyCode, KeyEvent, KeyEventKind, KeyModifiers};

#[derive(Clone, Copy, Debug, Default, Eq, PartialEq)]
pub enum Demo {
    #[default]
    Welcome,
    Colors,
    Layout,
    Unicode,
}

#[derive(Clone, Copy, Debug, Eq, PartialEq)]
pub enum EntryKind {
    Command,
    Result,
    Error,
    System,
}

#[derive(Debug)]
pub struct TranscriptEntry {
    pub kind: EntryKind,
    pub title: String,
    pub lines: Vec<String>,
}

#[derive(Debug)]
pub enum Effect {
    None,
    Execute(String),
    Shutdown,
}

#[derive(Debug)]
pub struct App {
    pub editor: Editor,
    pub transcript: Vec<TranscriptEntry>,
    /// Number of transcript rows to keep below the viewport. Zero follows
    /// the newest output.
    pub transcript_scroll: u16,
    pub demo: Demo,
    pub daemon: String,
    pub busy: usize,
    pub should_quit: bool,
    history: Vec<String>,
    history_position: Option<usize>,
}

impl App {
    pub fn new() -> Self {
        Self {
            editor: Editor::default(),
            transcript: vec![TranscriptEntry {
                kind: EntryKind::System,
                title: "Connected".to_owned(),
                lines: vec![
                    "Rust terminal client ↔ Racket compiler/session server".to_owned(),
                    "Type help, or try :demo colors | layout | unicode".to_owned(),
                ],
            }],
            transcript_scroll: 0,
            demo: Demo::Welcome,
            daemon: "cold".to_owned(),
            busy: 0,
            should_quit: false,
            history: Vec::new(),
            history_position: None,
        }
    }

    pub fn on_terminal(&mut self, event: Event) -> Effect {
        match event {
            Event::Key(key) if matches!(key.kind, KeyEventKind::Press | KeyEventKind::Repeat) => {
                self.on_key(key)
            }
            Event::Paste(text) => {
                self.editor.insert(&text);
                Effect::None
            }
            _ => Effect::None,
        }
    }

    pub fn on_backend(&mut self, event: BackendEvent) {
        self.busy = self.busy.saturating_sub(1);
        match event {
            BackendEvent::Disconnected(message) => {
                self.transcript.push(TranscriptEntry {
                    kind: EntryKind::Error,
                    title: "Server disconnected".to_owned(),
                    lines: vec![message],
                });
                self.should_quit = true;
            }
            BackendEvent::Response { command, response } => {
                if !response.ok {
                    let error = response.error.unwrap_or(crate::protocol::ServerError {
                        kind: "server".to_owned(),
                        message: "unknown server failure".to_owned(),
                    });
                    self.transcript.push(TranscriptEntry {
                        kind: EntryKind::Error,
                        title: error.kind,
                        lines: vec![error.message],
                    });
                    return;
                }
                let result = response.result.unwrap_or_default();
                let title = result
                    .get("title")
                    .and_then(|value| value.as_str())
                    .unwrap_or("Result")
                    .to_owned();
                let lines = result
                    .get("lines")
                    .and_then(|value| value.as_array())
                    .map(|values| {
                        values
                            .iter()
                            .filter_map(|value| value.as_str().map(str::to_owned))
                            .collect::<Vec<_>>()
                    })
                    .unwrap_or_default();
                let kind = result
                    .get("kind")
                    .and_then(|value| value.as_str())
                    .unwrap_or("result");
                if matches!(kind, "run" | "open" | "schema" | "pipeline" | "save") {
                    self.daemon = "ready".to_owned();
                }
                self.transcript.push(TranscriptEntry {
                    kind: EntryKind::Result,
                    title,
                    lines,
                });
                if result
                    .get("close")
                    .and_then(|value| value.as_bool())
                    .unwrap_or(false)
                    || matches!(command.as_str(), "quit" | "exit")
                {
                    self.should_quit = true;
                }
            }
        }
    }

    fn on_key(&mut self, key: KeyEvent) -> Effect {
        if key.modifiers.contains(KeyModifiers::CONTROL) {
            match key.code {
                KeyCode::Char('c') => {
                    if self.editor.is_empty() {
                        return Effect::Shutdown;
                    }
                    self.editor.clear();
                    return Effect::None;
                }
                KeyCode::Char('d') if self.editor.is_empty() => return Effect::Shutdown,
                KeyCode::Char('a') => {
                    self.editor.move_home();
                    return Effect::None;
                }
                KeyCode::Char('e') => {
                    self.editor.move_end();
                    return Effect::None;
                }
                _ => {}
            }
        }
        match key.code {
            KeyCode::Enter
                if key
                    .modifiers
                    .intersects(KeyModifiers::SHIFT | KeyModifiers::ALT) =>
            {
                self.editor.insert("\n");
                Effect::None
            }
            KeyCode::Enter => self.submit(),
            KeyCode::Char(character)
                if !key
                    .modifiers
                    .intersects(KeyModifiers::CONTROL | KeyModifiers::SUPER) =>
            {
                self.editor.insert(&character.to_string());
                Effect::None
            }
            KeyCode::Backspace => {
                self.editor.backspace();
                Effect::None
            }
            KeyCode::Delete => {
                self.editor.delete();
                Effect::None
            }
            KeyCode::Left => {
                self.editor.move_left();
                Effect::None
            }
            KeyCode::Right => {
                self.editor.move_right();
                Effect::None
            }
            KeyCode::Home => {
                self.editor.move_home();
                Effect::None
            }
            KeyCode::End => {
                self.editor.move_end();
                Effect::None
            }
            KeyCode::Up => {
                self.previous_history();
                Effect::None
            }
            KeyCode::Down => {
                self.next_history();
                Effect::None
            }
            KeyCode::PageUp => {
                self.transcript_scroll = self.transcript_scroll.saturating_add(8);
                Effect::None
            }
            KeyCode::PageDown => {
                self.transcript_scroll = self.transcript_scroll.saturating_sub(8);
                Effect::None
            }
            KeyCode::Tab => {
                self.editor.insert("  ");
                Effect::None
            }
            KeyCode::F(1) => Effect::Execute("help".to_owned()),
            KeyCode::F(2) => {
                self.demo = match self.demo {
                    Demo::Welcome => Demo::Colors,
                    Demo::Colors => Demo::Layout,
                    Demo::Layout => Demo::Unicode,
                    Demo::Unicode => Demo::Welcome,
                };
                Effect::None
            }
            KeyCode::Esc => {
                self.demo = Demo::Welcome;
                Effect::None
            }
            _ => Effect::None,
        }
    }

    fn submit(&mut self) -> Effect {
        let source = self.editor.take();
        let line = source.trim().to_owned();
        if line.is_empty() {
            return Effect::None;
        }
        self.history.push(source.clone());
        self.history_position = None;
        if line == ":clear" {
            self.transcript.clear();
            return Effect::None;
        }
        if let Some(name) = line.strip_prefix(":demo ") {
            self.demo = match name.trim() {
                "colors" => Demo::Colors,
                "layout" => Demo::Layout,
                "unicode" => Demo::Unicode,
                "off" | "welcome" => Demo::Welcome,
                other => {
                    self.transcript.push(TranscriptEntry {
                        kind: EntryKind::Error,
                        title: "UI command".to_owned(),
                        lines: vec![format!("unknown demo {other:?}")],
                    });
                    return Effect::None;
                }
            };
            return Effect::None;
        }
        self.transcript.push(TranscriptEntry {
            kind: EntryKind::Command,
            title: "slog".to_owned(),
            lines: source.lines().map(str::to_owned).collect(),
        });
        self.transcript_scroll = 0;
        self.busy += 1;
        Effect::Execute(source)
    }

    fn previous_history(&mut self) {
        if self.history.is_empty() {
            return;
        }
        let position = self
            .history_position
            .map(|position| position.saturating_sub(1))
            .unwrap_or(self.history.len() - 1);
        self.history_position = Some(position);
        self.editor.replace(self.history[position].clone());
    }

    fn next_history(&mut self) {
        let Some(position) = self.history_position else {
            return;
        };
        if position + 1 < self.history.len() {
            self.history_position = Some(position + 1);
            self.editor.replace(self.history[position + 1].clone());
        } else {
            self.history_position = None;
            self.editor.clear();
        }
    }
}
