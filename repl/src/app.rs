use crate::backend::BackendEvent;
use crate::editor::Editor;
use crate::library::{DatabaseSummary, LibraryView};
use crossterm::event::{
    Event, KeyCode, KeyEvent, KeyEventKind, KeyModifiers, ModifierKeyCode, MouseButton, MouseEvent,
    MouseEventKind,
};

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

#[derive(Clone, Debug, serde::Deserialize)]
pub struct SessionSummary {
    pub name: String,
    pub database: Option<String>,
    pub current: bool,
    pub mode: String,
    pub changed: bool,
}

#[derive(Debug)]
pub struct TranscriptEntry {
    pub kind: EntryKind,
    pub title: String,
    pub lines: Vec<String>,
    /// Human or tool responsible for generated input. Command context stays
    /// in `title`; presentation can keep authorship compact and independent.
    pub actor: Option<String>,
}

#[derive(Debug)]
pub struct SharedAction {
    pub command: String,
    pub actor: Option<String>,
}

#[derive(Debug)]
pub struct TransientEntry {
    pub command: String,
    pub label: String,
    pub completed_label: Option<String>,
    pub frame: usize,
    pub ticks: u64,
    pub daemon_rebuild_pending: bool,
}

impl TransientEntry {
    fn animated_dots(&self) -> &'static str {
        // Every frame occupies three cells so the detail never shifts.
        const FRAMES: [&str; 3] = [".  ", ".. ", "..."];
        FRAMES[self.frame % FRAMES.len()]
    }

    pub fn animated_label(&self) -> String {
        format!("{}{} · {}", self.label, self.animated_dots(), self.detail())
    }

    pub fn fixed_label(&self) -> String {
        format!("{}... · {}", self.label, self.detail())
    }

    fn detail_stage(&self) -> u8 {
        match self.ticks {
            0..=7 => 0,
            8..=39 => 1,
            40..=119 => 2,
            _ => 3,
        }
    }

    pub fn detail(&self) -> &'static str {
        if self.daemon_rebuild_pending {
            return match self.detail_stage() {
                0 => "daemon sources changed; rebuilding the database runtime",
                1 => "waiting for the database runtime rebuild",
                2 => "runtime rebuild or database load is still active",
                _ => "still working; measured compiler/load progress is not exposed yet",
            };
        }
        match self.detail_stage() {
            0 => "request sent to the session server",
            1 => "waiting for the database runtime",
            2 => "still loading; compressed databases may be replaying layers",
            _ => "still waiting; relation and tuple progress is not exposed yet",
        }
    }
}

#[derive(Debug)]
pub enum Effect {
    Ignore,
    None,
    Execute(String),
    Shutdown,
}

#[derive(Debug)]
pub struct App {
    pub editor: Editor,
    pub transcript: Vec<TranscriptEntry>,
    /// In-flight UI workflows are rendered after the durable transcript but
    /// are not part of it until the backend commits a response.
    pub transient: Vec<TransientEntry>,
    /// Number of transcript rows to keep below the viewport. Zero follows
    /// the newest output.
    pub transcript_scroll: u16,
    pub library: Option<LibraryView>,
    pub current_database: Option<String>,
    pub sessions: Vec<SessionSummary>,
    pub coauthor_endpoint: Option<String>,
    pub coauthor_discovery: Option<String>,
    /// Canonical commands produced by transient UI gestures. They are shared
    /// with co-authors but do not become durable shell transcript entries.
    shared_actions: Vec<SharedAction>,
    /// Stable progress-stage changes for plain co-author clients. Animation
    /// frames stay terminal-local; only meaningful detail changes are shared.
    progress_updates: Vec<String>,
    pub should_quit: bool,
    history: Vec<String>,
    history_position: Option<usize>,
    terminal_width: u16,
    terminal_height: u16,
    physical_shift_held: bool,
}

impl App {
    pub fn new() -> Self {
        Self {
            editor: Editor::default(),
            transcript: vec![TranscriptEntry {
                kind: EntryKind::System,
                title: "Connected".to_owned(),
                lines: vec![
                    "Rust terminal client ↔ Racket database control plane".to_owned(),
                    "Type help for commands; :share shows co-author connection details".to_owned(),
                ],
                actor: None,
            }],
            transient: Vec::new(),
            transcript_scroll: 0,
            library: None,
            current_database: None,
            sessions: Vec::new(),
            coauthor_endpoint: None,
            coauthor_discovery: None,
            shared_actions: Vec::new(),
            progress_updates: Vec::new(),
            should_quit: false,
            history: Vec::new(),
            history_position: None,
            terminal_width: 80,
            terminal_height: 24,
            physical_shift_held: false,
        }
    }

    pub fn set_terminal_size(&mut self, width: u16, height: u16) {
        self.terminal_width = width;
        self.terminal_height = height;
    }

    pub fn on_terminal(&mut self, event: Event) -> Effect {
        match event {
            Event::Key(key) if Self::is_shift_key(key.code) => {
                self.physical_shift_held = !matches!(key.kind, KeyEventKind::Release);
                Effect::None
            }
            Event::Key(mut key)
                if matches!(key.kind, KeyEventKind::Press | KeyEventKind::Repeat) =>
            {
                if self.physical_shift_held {
                    key.modifiers.insert(KeyModifiers::SHIFT);
                }
                self.on_key(key)
            }
            Event::Paste(text) if self.library.is_none() => {
                self.editor.insert(&text);
                Effect::None
            }
            Event::Mouse(mouse) => self.on_mouse(mouse),
            Event::Resize(width, height) => {
                self.set_terminal_size(width, height);
                Effect::None
            }
            _ => Effect::Ignore,
        }
    }

    fn is_shift_key(code: KeyCode) -> bool {
        matches!(
            code,
            KeyCode::Modifier(ModifierKeyCode::LeftShift | ModifierKeyCode::RightShift)
        )
    }

    pub fn on_backend(&mut self, event: BackendEvent) {
        match event {
            BackendEvent::Log(line) => {
                self.transcript.push(TranscriptEntry {
                    kind: EntryKind::System,
                    title: "Racket".to_owned(),
                    lines: vec![line],
                    actor: None,
                });
            }
            BackendEvent::Disconnected(message) => {
                self.transient.clear();
                self.transcript.push(TranscriptEntry {
                    kind: EntryKind::Error,
                    title: "Server disconnected".to_owned(),
                    lines: vec![message],
                    actor: None,
                });
                self.should_quit = true;
            }
            BackendEvent::Response { command, response } => {
                let workflow = self.finish_operation(&command);
                if !response.ok {
                    let error = response.error.unwrap_or(crate::protocol::ServerError {
                        kind: "server".to_owned(),
                        message: "unknown server failure".to_owned(),
                    });
                    self.transcript.push(TranscriptEntry {
                        kind: EntryKind::Error,
                        title: error.kind,
                        lines: vec![error.message],
                        actor: None,
                    });
                    return;
                }
                let result = response.result.unwrap_or_default();
                self.update_session_context(&result);
                let title = workflow
                    .and_then(|workflow| workflow.completed_label)
                    .or_else(|| {
                        result
                            .get("title")
                            .and_then(|value| value.as_str())
                            .map(str::to_owned)
                    })
                    .unwrap_or_else(|| "Result".to_owned());
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
                if kind == "library" {
                    match result
                        .get("databases")
                        .cloned()
                        .map(serde_json::from_value::<Vec<DatabaseSummary>>)
                    {
                        Some(Ok(databases)) => {
                            let mut library = LibraryView::new(databases);
                            if let Some(selected) =
                                result.get("selected").and_then(|value| value.as_str())
                                && let Some(index) = library
                                    .databases
                                    .iter()
                                    .position(|database| database.name == selected)
                            {
                                library.select(index);
                            }
                            self.library = Some(library);
                        }
                        Some(Err(error)) => {
                            self.transcript.push(TranscriptEntry {
                                kind: EntryKind::Error,
                                title: "Library response".to_owned(),
                                lines: vec![error.to_string()],
                                actor: None,
                            });
                        }
                        None => {
                            self.transcript.push(TranscriptEntry {
                                kind: EntryKind::Error,
                                title: "Library response".to_owned(),
                                lines: vec!["server omitted the database list".to_owned()],
                                actor: None,
                            });
                        }
                    }
                    return;
                }
                self.transcript.push(TranscriptEntry {
                    kind: EntryKind::Result,
                    title,
                    lines,
                    actor: None,
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
        if self.library.is_some() {
            return self.on_library_key(key);
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
            // Some terminals map their multiline shortcut to LF rather than
            // reporting a modified Enter. In raw mode Crossterm preserves LF
            // as a character; accept it as a newline. This also makes Ctrl+J
            // a portable fallback when modified Enter is not distinguishable.
            KeyCode::Char('\n') => {
                self.editor.insert("\n");
                Effect::None
            }
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
            _ => Effect::None,
        }
    }

    fn on_library_key(&mut self, key: KeyEvent) -> Effect {
        if matches!(key.code, KeyCode::Esc | KeyCode::Char('q')) {
            self.close_library(None);
            return Effect::None;
        }
        let Some(library) = self.library.as_mut() else {
            return Effect::Ignore;
        };
        match key.code {
            KeyCode::Enter => {
                let command = library
                    .current()
                    .map(|database| format!("open {}", database.name));
                if let Some(command) = command {
                    self.library = None;
                    self.issue(command, EntryKind::GeneratedCommand)
                } else {
                    Effect::None
                }
            }
            KeyCode::Up | KeyCode::Char('k') => {
                let _ = library;
                self.update_library_selection(None, |library| library.previous(1));
                Effect::None
            }
            KeyCode::Down | KeyCode::Char('j') => {
                let _ = library;
                self.update_library_selection(None, |library| library.next(1));
                Effect::None
            }
            KeyCode::PageUp => {
                let _ = library;
                self.update_library_selection(None, |library| library.previous(8));
                Effect::None
            }
            KeyCode::PageDown => {
                let _ = library;
                self.update_library_selection(None, |library| library.next(8));
                Effect::None
            }
            KeyCode::Home => {
                let _ = library;
                self.update_library_selection(None, |library| library.select(0));
                Effect::None
            }
            KeyCode::End => {
                let _ = library;
                self.update_library_selection(None, |library| library.select(usize::MAX));
                Effect::None
            }
            _ => Effect::Ignore,
        }
    }

    fn on_mouse(&mut self, mouse: MouseEvent) -> Effect {
        if let Some(library) = self.library.as_mut() {
            return match mouse.kind {
                MouseEventKind::ScrollUp => {
                    let _ = library;
                    self.update_library_selection(None, |library| library.previous(1));
                    Effect::None
                }
                MouseEventKind::ScrollDown => {
                    let _ = library;
                    self.update_library_selection(None, |library| library.next(1));
                    Effect::None
                }
                MouseEventKind::Down(MouseButton::Left) => {
                    if let Some(index) = library.hit_test(
                        mouse.column,
                        mouse.row,
                        self.terminal_width,
                        self.terminal_height,
                    ) {
                        let _ = library;
                        self.update_library_selection(None, |library| library.select(index));
                        Effect::None
                    } else {
                        Effect::Ignore
                    }
                }
                _ => Effect::Ignore,
            };
        }
        match mouse.kind {
            MouseEventKind::ScrollUp => {
                self.transcript_scroll = self.transcript_scroll.saturating_add(3);
                Effect::None
            }
            MouseEventKind::ScrollDown => {
                self.transcript_scroll = self.transcript_scroll.saturating_sub(3);
                Effect::None
            }
            _ => Effect::Ignore,
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
        if line.starts_with(';') {
            self.comment(source, "local");
            return Effect::None;
        }
        if line == ":clear" {
            self.transcript.clear();
            return Effect::None;
        }
        if line == ":share" {
            self.show_coauthor_info();
            return Effect::None;
        }
        if line == "library close" {
            self.close_library(None);
            return Effect::None;
        }
        if let Some(name) = line.strip_prefix("library select ")
            && self.library.is_some()
        {
            if !self.select_library_name(name.trim(), None) {
                self.transcript.push(TranscriptEntry {
                    kind: EntryKind::Error,
                    title: "Library selection".to_owned(),
                    lines: vec![format!("no database named {}", name.trim())],
                    actor: None,
                });
            }
            return Effect::None;
        }
        self.issue(source, EntryKind::Command)
    }

    fn issue(&mut self, source: String, kind: EntryKind) -> Effect {
        let title = self.prompt_label().to_owned();
        self.issue_as(source, kind, title, None)
    }

    fn issue_as(
        &mut self,
        source: String,
        kind: EntryKind,
        title: String,
        actor: Option<String>,
    ) -> Effect {
        self.transcript.push(TranscriptEntry {
            kind,
            title,
            lines: source.lines().map(str::to_owned).collect(),
            actor,
        });
        self.transcript_scroll = 0;
        Effect::Execute(source)
    }

    fn comment(&mut self, source: String, title: &str) {
        self.transcript.push(TranscriptEntry {
            kind: EntryKind::Comment,
            title: title.to_owned(),
            lines: source.lines().map(str::to_owned).collect(),
            actor: None,
        });
        self.transcript_scroll = 0;
    }

    fn record_shared_action(&mut self, command: String, actor: Option<String>) {
        self.shared_actions.push(SharedAction { command, actor });
    }

    fn update_library_selection(
        &mut self,
        actor: Option<String>,
        update: impl FnOnce(&mut LibraryView),
    ) {
        let command = self.library.as_mut().and_then(|library| {
            update(library);
            library
                .current()
                .map(|database| format!("library select {}", database.name))
        });
        if let Some(command) = command {
            self.record_shared_action(command, actor);
        }
    }

    fn select_library_name(&mut self, name: &str, actor: Option<String>) -> bool {
        let index = self.library.as_ref().and_then(|library| {
            library
                .databases
                .iter()
                .position(|database| database.name == name)
        });
        let Some(index) = index else {
            return false;
        };
        if let Some(library) = self.library.as_mut() {
            library.select(index);
        }
        self.record_shared_action(format!("library select {name}"), actor);
        true
    }

    fn close_library(&mut self, actor: Option<String>) {
        if self.library.take().is_some() {
            self.record_shared_action("library close".to_owned(), actor);
        }
    }

    pub fn take_shared_actions(&mut self) -> Vec<SharedAction> {
        std::mem::take(&mut self.shared_actions)
    }

    pub fn plain_shared_action(action: &SharedAction) -> String {
        format!(
            "› {}{}",
            action.command,
            action
                .actor
                .as_deref()
                .map(|actor| format!("  — {actor}"))
                .unwrap_or_default()
        )
    }

    pub fn on_coauthor(&mut self, source: &str, text: String) -> Effect {
        let line = text.trim().to_owned();
        if line.is_empty() {
            return Effect::None;
        }
        if line.starts_with(';') {
            self.comment(text, source);
            return Effect::None;
        }
        if line == "library close" {
            self.close_library(Some(source.to_owned()));
            return Effect::None;
        }
        if let Some(name) = line.strip_prefix("library select ")
            && self.library.is_some()
        {
            let name = name.trim().to_owned();
            if !self.select_library_name(&name, Some(source.to_owned())) {
                self.record_shared_action(line, Some(source.to_owned()));
                self.transcript.push(TranscriptEntry {
                    kind: EntryKind::Error,
                    title: "Library selection".to_owned(),
                    lines: vec![format!("no database named {name}")],
                    actor: None,
                });
            }
            return Effect::None;
        }
        // A semantic shell command is also the escape hatch from a visual
        // mode. Headless peers can always act directly on the data they saw.
        if matches!(line.split_whitespace().next(), Some("open" | "use")) {
            self.library = None;
        } else {
            self.close_library(Some(source.to_owned()));
        }
        let title = self.prompt_label().to_owned();
        self.issue_as(
            text,
            EntryKind::GeneratedCommand,
            title,
            Some(source.to_owned()),
        )
    }

    pub fn coauthor_input_is_view_command(text: &str) -> bool {
        let text = text.trim();
        text == "library close" || text.starts_with("library select ")
    }

    pub fn private_command_allowed(command: &str) -> bool {
        let verb = command
            .split_whitespace()
            .next()
            .unwrap_or("")
            .to_ascii_lowercase();
        matches!(
            verb.as_str(),
            "help"
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

    pub fn on_private_backend(&mut self, event: BackendEvent) -> String {
        match event {
            BackendEvent::Log(line) => format!("• Racket\n  {line}"),
            BackendEvent::Disconnected(message) => format!("! Server disconnected\n  {message}"),
            BackendEvent::Response { response, .. } => {
                if !response.ok {
                    let error = response.error.unwrap_or(crate::protocol::ServerError {
                        kind: "server".to_owned(),
                        message: "unknown server failure".to_owned(),
                    });
                    return format!("! {}\n  {}", error.kind, error.message);
                }
                let result = response.result.unwrap_or_default();
                self.update_session_context(&result);
                if result.get("kind").and_then(|value| value.as_str()) == Some("library") {
                    return match result
                        .get("databases")
                        .cloned()
                        .map(serde_json::from_value::<Vec<DatabaseSummary>>)
                    {
                        Some(Ok(databases)) => {
                            let mut library = LibraryView::new(databases);
                            if let Some(selected) =
                                result.get("selected").and_then(|value| value.as_str())
                                && let Some(index) = library
                                    .databases
                                    .iter()
                                    .position(|database| database.name == selected)
                            {
                                library.select(index);
                            }
                            self.plain_library_view(&library, true)
                        }
                        Some(Err(error)) => format!("! Library response\n  {error}"),
                        None => "! Library response\n  server omitted the database list".to_owned(),
                    };
                }
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
                Self::plain_entry(&TranscriptEntry {
                    kind: EntryKind::Result,
                    title,
                    lines,
                    actor: None,
                })
            }
        }
    }

    pub fn add_system_entry(&mut self, title: impl Into<String>, lines: Vec<String>) {
        self.transcript.push(TranscriptEntry {
            kind: EntryKind::System,
            title: title.into(),
            lines,
            actor: None,
        });
    }

    pub fn add_presence(&mut self, message: impl Into<String>) {
        self.transcript.push(TranscriptEntry {
            kind: EntryKind::Presence,
            title: message.into(),
            lines: Vec::new(),
            actor: None,
        });
    }

    pub fn set_coauthor_info(&mut self, endpoint: String, discovery: String) {
        self.coauthor_endpoint = Some(endpoint);
        self.coauthor_discovery = Some(discovery);
    }

    fn show_coauthor_info(&mut self) {
        let Some(endpoint) = self.coauthor_endpoint.clone() else {
            return;
        };
        let connect = endpoint
            .rsplit_once(':')
            .map(|(host, port)| format!("connect: nc {host} {port}"))
            .unwrap_or_else(|| format!("connect: nc {endpoint}"));
        self.add_system_entry(
            "Co-author socket",
            vec![
                connect,
                format!(
                    "discovery: {}",
                    self.coauthor_discovery.as_deref().unwrap_or("unavailable")
                ),
                "wire: shared COMMAND · /private COMMAND · ; comment".to_owned(),
            ],
        );
    }

    pub fn begin_operation(
        &mut self,
        command: &str,
        daemon_rebuild_pending: bool,
    ) -> Option<String> {
        let (verb, argument) = command
            .trim()
            .split_once(char::is_whitespace)
            .map(|(verb, argument)| (verb.to_ascii_lowercase(), argument.trim()))
            .unwrap_or_else(|| (command.trim().to_ascii_lowercase(), ""));
        if verb != "open" || argument.is_empty() {
            return None;
        }
        let entry = TransientEntry {
            command: command.to_owned(),
            label: format!("Loading database `{argument}`"),
            completed_label: Some(format!("Loaded database `{argument}`")),
            frame: 0,
            ticks: 0,
            daemon_rebuild_pending,
        };
        let fixed = entry.fixed_label();
        self.transient.push(entry);
        self.transcript_scroll = 0;
        Some(fixed)
    }

    pub fn tick(&mut self) -> bool {
        if self.transient.is_empty() {
            return false;
        }
        for entry in &mut self.transient {
            let previous_stage = entry.detail_stage();
            entry.frame = entry.frame.wrapping_add(1);
            entry.ticks = entry.ticks.saturating_add(1);
            if entry.detail_stage() != previous_stage {
                self.progress_updates.push(entry.fixed_label());
            }
        }
        true
    }

    pub fn take_progress_updates(&mut self) -> Vec<String> {
        std::mem::take(&mut self.progress_updates)
    }

    fn finish_operation(&mut self, command: &str) -> Option<TransientEntry> {
        let index = self
            .transient
            .iter()
            .position(|entry| entry.command == command)?;
        Some(self.transient.remove(index))
    }

    pub fn plain_entry(entry: &TranscriptEntry) -> String {
        match entry.kind {
            EntryKind::Comment => entry.lines.join("\n"),
            EntryKind::Command | EntryKind::GeneratedCommand => format!(
                "› {}{}",
                entry.lines.join("\n  "),
                entry
                    .actor
                    .as_deref()
                    .map(|actor| format!("  — {actor}"))
                    .unwrap_or_default()
            ),
            EntryKind::Presence => format!("· {}", entry.title),
            EntryKind::Result => {
                let body = entry.lines.join("\n  ");
                if body.is_empty() {
                    format!("◆ {}", entry.title)
                } else {
                    format!("◆ {}\n  {body}", entry.title)
                }
            }
            EntryKind::Error => format!("! {}\n  {}", entry.title, entry.lines.join("\n  ")),
            EntryKind::System => format!("• {}\n  {}", entry.title, entry.lines.join("\n  ")),
        }
    }

    pub fn plain_share_snapshot(&self) -> String {
        let mut entries = self
            .transcript
            .iter()
            .map(Self::plain_entry)
            .collect::<Vec<_>>();
        entries.extend(self.transient.iter().map(TransientEntry::fixed_label));
        entries.push(self.plain_shared_view(true));
        entries.join("\n")
    }

    pub fn shared_view_mode(&self) -> &'static str {
        if self.library.is_some() {
            "library"
        } else {
            "shell"
        }
    }

    pub fn shared_view_key(&self) -> String {
        match &self.library {
            Some(library) => format!("library:{}:{}", library.selected, library.databases.len()),
            None => format!(
                "shell:{}:{}",
                self.current_database.as_deref().unwrap_or("none"),
                self.sessions.len()
            ),
        }
    }

    pub fn plain_shared_view(&self, full: bool) -> String {
        match &self.library {
            Some(library) => self.plain_library_view(library, full),
            None => {
                let resident = self.sessions.len();
                format!(
                    "◇ View · shell · database {} · {resident} resident database{}",
                    self.current_database.as_deref().unwrap_or("none"),
                    if resident == 1 { "" } else { "s" }
                )
            }
        }
    }

    fn plain_library_view(&self, library: &LibraryView, full: bool) -> String {
        let mut lines = vec![format!(
            "◇ View · library · {} database{}",
            library.databases.len(),
            if library.databases.len() == 1 {
                ""
            } else {
                "s"
            }
        )];
        if full {
            for (index, database) in library.databases.iter().take(200).enumerate() {
                let resident = self
                    .sessions
                    .iter()
                    .find(|resident| resident.database.as_deref() == Some(&database.name));
                let marker = if index == library.selected { ">" } else { " " };
                let residency = match resident {
                    Some(resident) if resident.current => " · current",
                    Some(_) => " · resident",
                    None => "",
                };
                lines.push(format!(
                    "  {marker} {} · {} · {} fact{} · {} relation{} · {}{residency}",
                    database.name,
                    database.kind,
                    database.facts,
                    if database.facts == 1 { "" } else { "s" },
                    database.relation_count,
                    if database.relation_count == 1 {
                        ""
                    } else {
                        "s"
                    },
                    database.size
                ));
            }
            if library.databases.len() > 200 {
                lines.push(format!(
                    "  … {} more databases omitted from this view",
                    library.databases.len() - 200
                ));
            }
        }
        if let Some(database) = library.current() {
            lines.push(format!(
                "  selected {}/{} · {} · {} table{} · {} struct{} · {} lattice{}",
                library.selected + 1,
                library.databases.len(),
                database.name,
                database.table_count,
                if database.table_count == 1 { "" } else { "s" },
                database.struct_count,
                if database.struct_count == 1 { "" } else { "s" },
                database.lattice_count,
                if database.lattice_count == 1 { "" } else { "s" }
            ));
            if !database.relations.is_empty() {
                let relation_limit = if full { 20 } else { 5 };
                let relations = database
                    .relations
                    .iter()
                    .take(relation_limit)
                    .map(|relation| {
                        format!(
                            "{}/{} {} ({} fact{})",
                            relation.name,
                            relation.arity,
                            relation.kind,
                            relation.facts,
                            if relation.facts == 1 { "" } else { "s" }
                        )
                    })
                    .collect::<Vec<_>>()
                    .join(", ");
                lines.push(format!(
                    "  relations: {relations}{}",
                    if database.relations.len() > relation_limit {
                        format!(" · … {} more", database.relations.len() - relation_limit)
                    } else {
                        String::new()
                    }
                ));
            }
        }
        lines.push("  commands: library select NAME | open NAME | library close".to_owned());
        lines.join("\n")
    }

    fn update_session_context(&mut self, result: &serde_json::Value) {
        if let Some(current) = result.get("current") {
            self.current_database = current.as_str().map(str::to_owned);
        }
        if let Some(sessions) = result.get("sessions").cloned() {
            match serde_json::from_value::<Vec<SessionSummary>>(sessions) {
                Ok(sessions) => self.sessions = sessions,
                Err(error) => self.transcript.push(TranscriptEntry {
                    kind: EntryKind::Error,
                    title: "Resident database response".to_owned(),
                    lines: vec![error.to_string()],
                    actor: None,
                }),
            }
        }
    }

    pub fn prompt_label(&self) -> &str {
        self.sessions
            .iter()
            .find(|session| session.current)
            .map(|session| session.name.as_str())
            .or(self.current_database.as_deref())
            .unwrap_or("slog")
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

#[cfg(test)]
mod tests {
    use super::{App, Effect, EntryKind};
    use crate::backend::BackendEvent;
    use crate::protocol::Response;
    use crossterm::event::{
        Event, KeyCode, KeyEvent, KeyEventKind, KeyEventState, KeyModifiers, ModifierKeyCode,
        MouseEvent, MouseEventKind,
    };

    #[test]
    fn page_keys_navigate_transcript_from_the_bottom() {
        let mut app = App::new();
        app.on_terminal(Event::Key(KeyEvent::new(
            KeyCode::PageUp,
            KeyModifiers::NONE,
        )));
        assert_eq!(app.transcript_scroll, 8);
        app.on_terminal(Event::Key(KeyEvent::new(
            KeyCode::PageDown,
            KeyModifiers::NONE,
        )));
        assert_eq!(app.transcript_scroll, 0);
    }

    #[test]
    fn mouse_wheel_navigates_transcript() {
        let mut app = App::new();
        app.on_terminal(Event::Mouse(MouseEvent {
            kind: MouseEventKind::ScrollUp,
            column: 10,
            row: 5,
            modifiers: KeyModifiers::NONE,
        }));
        assert_eq!(app.transcript_scroll, 3);
        app.on_terminal(Event::Mouse(MouseEvent {
            kind: MouseEventKind::ScrollDown,
            column: 10,
            row: 5,
            modifiers: KeyModifiers::NONE,
        }));
        assert_eq!(app.transcript_scroll, 0);
    }

    #[test]
    fn shifted_enter_inserts_a_newline() {
        let mut app = App::new();
        app.editor.insert("first line");
        app.on_terminal(Event::Key(KeyEvent::new(
            KeyCode::Enter,
            KeyModifiers::SHIFT,
        )));
        assert_eq!(app.editor.text(), "first line\n");
    }

    #[test]
    fn physical_shift_events_make_enter_multiline() {
        let mut app = App::new();
        app.editor.insert("first line");
        app.on_terminal(Event::Key(KeyEvent::new_with_kind_and_state(
            KeyCode::Modifier(ModifierKeyCode::LeftShift),
            KeyModifiers::SHIFT,
            KeyEventKind::Press,
            KeyEventState::NONE,
        )));
        app.on_terminal(Event::Key(KeyEvent::new(
            KeyCode::Enter,
            KeyModifiers::NONE,
        )));
        app.on_terminal(Event::Key(KeyEvent::new_with_kind_and_state(
            KeyCode::Modifier(ModifierKeyCode::LeftShift),
            KeyModifiers::SHIFT,
            KeyEventKind::Release,
            KeyEventState::NONE,
        )));
        assert_eq!(app.editor.text(), "first line\n");
    }

    #[test]
    fn line_feed_is_a_portable_multiline_fallback() {
        let mut app = App::new();
        app.editor.insert("first line");
        app.on_terminal(Event::Key(KeyEvent::new(
            KeyCode::Char('\n'),
            KeyModifiers::CONTROL,
        )));
        assert_eq!(app.editor.text(), "first line\n");
    }

    #[test]
    fn library_response_enters_the_contextual_view() {
        let mut app = App::new();
        app.on_backend(BackendEvent::Response {
            command: "library".to_owned(),
            response: Response {
                id: 1,
                ok: true,
                result: Some(serde_json::json!({
                    "kind": "library",
                    "databases": [{
                        "name": "example",
                        "kind": "plain",
                        "managed": false,
                        "facts": 3,
                        "stored_facts": 3,
                        "bytes": 24,
                        "size": "24B",
                        "relation_count": 1,
                        "table_count": 1,
                        "struct_count": 0,
                        "lattice_count": 0,
                        "inputs": [],
                        "stale": [],
                        "per": null,
                        "relations": [{
                            "name": "edge",
                            "kind": "table",
                            "arity": 2,
                            "detail": null,
                            "facts": 3,
                            "stored_facts": 3,
                            "count_source": "stored"
                        }]
                    }]
                })),
                error: None,
            },
        });
        assert_eq!(
            app.library
                .as_ref()
                .and_then(|library| library.current())
                .map(|database| database.name.as_str()),
            Some("example")
        );
    }

    #[test]
    fn enter_on_a_library_database_echoes_and_executes_open() {
        let mut app = App::new();
        app.on_backend(BackendEvent::Response {
            command: "library".to_owned(),
            response: Response {
                id: 1,
                ok: true,
                result: Some(serde_json::json!({
                    "kind": "library",
                    "current": null,
                    "sessions": [],
                    "databases": [{
                        "name": "example",
                        "kind": "plain",
                        "managed": false,
                        "facts": 3,
                        "stored_facts": 3,
                        "bytes": 24,
                        "size": "24B",
                        "relation_count": 1,
                        "table_count": 1,
                        "struct_count": 0,
                        "lattice_count": 0,
                        "inputs": [],
                        "stale": [],
                        "per": null,
                        "relations": []
                    }]
                })),
                error: None,
            },
        });

        let effect = app.on_terminal(Event::Key(KeyEvent::new(
            KeyCode::Enter,
            KeyModifiers::NONE,
        )));
        assert!(matches!(effect, Effect::Execute(ref line) if line == "open example"));
        assert!(app.library.is_none());
        let entry = app.transcript.last().expect("generated command echo");
        assert_eq!(entry.kind, EntryKind::GeneratedCommand);
        assert_eq!(entry.lines, vec!["open example"]);
    }

    #[test]
    fn response_context_changes_the_prompt_and_preserves_session_metadata() {
        let mut app = App::new();
        app.on_backend(BackendEvent::Response {
            command: "open example".to_owned(),
            response: Response {
                id: 2,
                ok: true,
                result: Some(serde_json::json!({
                    "kind": "open",
                    "title": "Opened example",
                    "lines": [],
                    "current": "example",
                    "sessions": [{
                        "name": "example",
                        "database": "example",
                        "current": true,
                        "mode": "mutable",
                        "changed": false
                    }]
                })),
                error: None,
            },
        });

        assert_eq!(app.prompt_label(), "example");
        assert_eq!(app.current_database.as_deref(), Some("example"));
        assert_eq!(app.sessions.len(), 1);
        assert_eq!(app.sessions[0].mode, "mutable");
    }

    #[test]
    fn database_load_is_transient_until_the_response_commits() {
        let mut app = App::new();
        let durable = app.transcript.len();
        assert_eq!(
            app.begin_operation("open example", false).as_deref(),
            Some("Loading database `example`... · request sent to the session server")
        );
        assert_eq!(app.transcript.len(), durable);
        assert!(
            app.plain_share_snapshot()
                .contains("Loading database `example`... · request sent to the session server")
        );
        assert!(!app.plain_share_snapshot().contains('◌'));
        assert_eq!(
            app.transient[0].animated_label(),
            "Loading database `example`.   · request sent to the session server"
        );
        app.tick();
        assert_eq!(
            app.transient[0].animated_label(),
            "Loading database `example`..  · request sent to the session server"
        );
        for _ in 0..7 {
            app.tick();
        }
        assert_eq!(
            app.take_progress_updates(),
            vec!["Loading database `example`... · waiting for the database runtime"]
        );

        app.on_backend(BackendEvent::Response {
            command: "open example".to_owned(),
            response: Response {
                id: 3,
                ok: true,
                result: Some(serde_json::json!({
                    "kind": "open",
                    "title": "Opened example",
                    "lines": ["database opened"],
                    "current": "example",
                    "sessions": []
                })),
                error: None,
            },
        });
        assert!(app.transient.is_empty());
        let committed = app.transcript.last().expect("committed response");
        assert_eq!(committed.kind, EntryKind::Result);
        assert_eq!(committed.title, "Loaded database `example`");
    }

    #[test]
    fn database_load_explains_a_pending_daemon_rebuild() {
        let mut app = App::new();
        assert_eq!(
            app.begin_operation("open example", true).as_deref(),
            Some(
                "Loading database `example`... · daemon sources changed; rebuilding the database runtime"
            )
        );
        for _ in 0..8 {
            app.tick();
        }
        assert_eq!(
            app.take_progress_updates(),
            vec!["Loading database `example`... · waiting for the database runtime rebuild"]
        );
    }

    #[test]
    fn semicolon_is_a_local_transcript_comment() {
        let mut app = App::new();
        app.editor.insert("; ask codex to inspect edge");
        let effect = app.on_terminal(Event::Key(KeyEvent::new(
            KeyCode::Enter,
            KeyModifiers::NONE,
        )));
        assert!(matches!(effect, Effect::None));
        let comment = app.transcript.last().expect("comment");
        assert_eq!(comment.kind, EntryKind::Comment);
        assert_eq!(comment.lines, vec!["; ask codex to inspect edge"]);
    }

    #[test]
    fn coauthor_input_is_dim_generated_shell_input() {
        let mut app = App::new();
        let effect = app.on_coauthor("codex", "tables edge".to_owned());
        assert!(matches!(effect, Effect::Execute(ref line) if line == "tables edge"));
        let command = app.transcript.last().expect("coauthor command");
        assert_eq!(command.kind, EntryKind::GeneratedCommand);
        assert_eq!(command.actor.as_deref(), Some("codex"));
        assert_eq!(App::plain_entry(command), "› tables edge  — codex");
        assert!(!App::plain_entry(command).contains("slog ·"));

        let effect = app.on_coauthor("codex", "; edge looks sparse".to_owned());
        assert!(matches!(effect, Effect::None));
        let comment = app.transcript.last().expect("coauthor comment");
        assert_eq!(comment.kind, EntryKind::Comment);
        assert_eq!(App::plain_entry(comment), "; edge looks sparse");
    }

    #[test]
    fn share_command_prints_a_directly_usable_connection_recipe() {
        let mut app = App::new();
        app.set_coauthor_info(
            "127.0.0.1:45678".to_owned(),
            "/tmp/slog-repl.42.45678.json".to_owned(),
        );
        app.editor.insert(":share");
        let effect = app.on_terminal(Event::Key(KeyEvent::new(
            KeyCode::Enter,
            KeyModifiers::NONE,
        )));
        assert!(matches!(effect, Effect::None));
        let entry = app.transcript.last().expect("share instructions");
        assert_eq!(entry.kind, EntryKind::System);
        assert_eq!(entry.lines[0], "connect: nc 127.0.0.1 45678");
        assert_eq!(entry.lines[1], "discovery: /tmp/slog-repl.42.45678.json");
    }

    #[test]
    fn library_has_a_headless_view_and_semantic_remote_controls() {
        let mut app = App::new();
        app.on_backend(BackendEvent::Response {
            command: "library".to_owned(),
            response: Response {
                id: 4,
                ok: true,
                result: Some(serde_json::json!({
                    "kind": "library",
                    "current": null,
                    "sessions": [],
                    "databases": [
                        {
                            "name": "alpha", "kind": "plain", "managed": false,
                            "facts": 3, "stored_facts": 3, "bytes": 24, "size": "24B",
                            "relation_count": 1, "table_count": 1, "struct_count": 0,
                            "lattice_count": 0, "inputs": [], "stale": [], "per": null,
                            "relations": [{
                                "name": "edge", "kind": "table", "arity": 2,
                                "detail": null, "facts": 3, "stored_facts": 3,
                                "count_source": "stored"
                            }]
                        },
                        {
                            "name": "beta", "kind": "compressed", "managed": true,
                            "facts": 8, "stored_facts": 5, "bytes": 80, "size": "80B",
                            "relation_count": 2, "table_count": 2, "struct_count": 0,
                            "lattice_count": 0, "inputs": [], "stale": [], "per": 0.625,
                            "relations": []
                        }
                    ]
                })),
                error: None,
            },
        });

        let full = app.plain_shared_view(true);
        assert!(full.contains("◇ View · library · 2 databases"));
        assert!(full.contains("> alpha · plain · 3 facts"));
        assert!(full.contains("beta · compressed · 8 facts"));
        assert!(full.contains("library select NAME | open NAME | library close"));

        assert!(matches!(
            app.on_coauthor("codex", "library select beta".to_owned()),
            Effect::None
        ));
        let actions = app.take_shared_actions();
        assert_eq!(actions.len(), 1);
        assert_eq!(
            App::plain_shared_action(&actions[0]),
            "› library select beta  — codex"
        );
        assert!(app.plain_shared_view(false).contains("selected 2/2 · beta"));
        let effect = app.on_coauthor("codex", "open beta".to_owned());
        assert!(matches!(effect, Effect::Execute(ref line) if line == "open beta"));
        assert!(app.library.is_none());
        let command = app.transcript.last().expect("semantic open echo");
        assert_eq!(command.actor.as_deref(), Some("codex"));
    }

    #[test]
    fn library_gestures_emit_the_same_commands_available_to_people() {
        let mut app = App::new();
        app.on_backend(BackendEvent::Response {
            command: "library".to_owned(),
            response: Response {
                id: 6,
                ok: true,
                result: Some(serde_json::json!({
                    "kind": "library",
                    "current": null,
                    "sessions": [],
                    "databases": [
                        {
                            "name": "alpha", "kind": "plain", "managed": false,
                            "facts": 3, "stored_facts": 3, "bytes": 24, "size": "24B",
                            "relation_count": 1, "table_count": 1, "struct_count": 0,
                            "lattice_count": 0, "inputs": [], "stale": [], "per": null,
                            "relations": []
                        },
                        {
                            "name": "beta", "kind": "plain", "managed": false,
                            "facts": 5, "stored_facts": 5, "bytes": 40, "size": "40B",
                            "relation_count": 1, "table_count": 1, "struct_count": 0,
                            "lattice_count": 0, "inputs": [], "stale": [], "per": null,
                            "relations": []
                        }
                    ]
                })),
                error: None,
            },
        });

        assert!(matches!(
            app.on_terminal(Event::Key(KeyEvent::new(KeyCode::Down, KeyModifiers::NONE))),
            Effect::None
        ));
        let actions = app.take_shared_actions();
        assert_eq!(actions.len(), 1);
        assert_eq!(
            App::plain_shared_action(&actions[0]),
            "› library select beta"
        );

        assert!(matches!(
            app.on_terminal(Event::Key(KeyEvent::new(KeyCode::Esc, KeyModifiers::NONE))),
            Effect::None
        ));
        let actions = app.take_shared_actions();
        assert_eq!(actions.len(), 1);
        assert_eq!(App::plain_shared_action(&actions[0]), "› library close");
    }

    #[test]
    fn private_lane_accepts_observations_without_touching_the_transcript() {
        assert!(App::private_command_allowed("tables edge"));
        assert!(App::private_command_allowed("library"));
        assert!(!App::private_command_allowed("add edge 1 2"));
        assert!(!App::private_command_allowed("quit"));

        let mut app = App::new();
        let durable = app.transcript.len();
        let output = app.on_private_backend(BackendEvent::Response {
            command: "count edge".to_owned(),
            response: Response {
                id: 5,
                ok: true,
                result: Some(serde_json::json!({
                    "kind": "query",
                    "title": "Count edge",
                    "lines": ["3 rows"],
                    "current": "alpha",
                    "sessions": []
                })),
                error: None,
            },
        });
        assert_eq!(output, "◆ Count edge\n  3 rows");
        assert_eq!(app.transcript.len(), durable);
        assert_eq!(app.current_database.as_deref(), Some("alpha"));
    }
}
