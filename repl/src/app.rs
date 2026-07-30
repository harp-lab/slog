use crate::backend::BackendEvent;
use crate::command::ShellCommand;
use crate::completion::{CompletionInventory, CompletionMenu, complete};
use crate::editor::Editor;
use crate::library::{DatabaseSummary, LibraryView};
use crate::operation::OperationTable;
use crate::present::{
    ExpansionAction, PresentationCanvas, PresentationCard, PresentationSearchSnapshot,
    PresentationSearchSummary,
};
use crate::response::CommandResult;
use crate::runtime::RuntimeLedger;
pub use crate::transcript::{EntryKind, SharedAction, TranscriptEntry};
use crate::workspace::Workspace;
use crossterm::event::{
    Event, KeyCode, KeyEvent, KeyEventKind, KeyModifiers, ModifierKeyCode, MouseButton, MouseEvent,
    MouseEventKind,
};
use std::collections::BTreeSet;

#[derive(Clone, Debug, serde::Deserialize)]
pub struct SessionSummary {
    pub name: String,
    pub database: Option<String>,
    pub current: bool,
    pub mode: String,
    pub changed: bool,
}

#[derive(Debug)]
struct CanvasSearchDraft {
    editor: Editor,
    snapshot: PresentationSearchSnapshot,
}

#[derive(Debug)]
pub enum Effect {
    Ignore,
    None,
    Execute(ShellCommand),
    Shutdown,
}

#[derive(Debug)]
pub struct App {
    pub editor: Editor,
    completion: Option<CompletionMenu>,
    completion_databases: BTreeSet<String>,
    /// Relation and namespace paths harvested from the boundary projection
    /// (N4-A work order 6), so completion offers what the catalog declares.
    completion_relations: BTreeSet<String>,
    completion_namespaces: BTreeSet<String>,
    pub transcript: Vec<TranscriptEntry>,
    /// In-flight UI workflows are rendered after the durable transcript but
    /// are not part of it until the backend commits a response.
    pub operations: OperationTable,
    /// Number of transcript rows to keep below the viewport. Zero follows
    /// the newest output.
    pub transcript_scroll: u16,
    pub library: Option<LibraryView>,
    /// The newest successful result remains a live, client-owned canvas.
    /// Older result entries retain their last rendered lines in the transcript.
    pub canvas: Option<PresentationCanvas>,
    canvas_entry: Option<usize>,
    canvas_search: Option<CanvasSearchDraft>,
    pub current_database: Option<String>,
    pub sessions: Vec<SessionSummary>,
    /// Structured, best-effort projections of semantic server results. This
    /// augments transcript presentation; it never decides whether a command
    /// itself succeeded.
    pub runtime: RuntimeLedger,
    /// Editable Slog snippets awaiting future compiler/session integration.
    pub workspace: Workspace,
    pub coauthor_endpoint: Option<String>,
    pub coauthor_discovery: Option<String>,
    /// Canonical commands produced by transient UI gestures. They are shared
    /// with co-authors but do not become durable shell transcript entries.
    shared_actions: Vec<SharedAction>,
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
            completion: None,
            completion_databases: BTreeSet::new(),
            completion_relations: BTreeSet::new(),
            completion_namespaces: BTreeSet::new(),
            transcript: vec![TranscriptEntry::system(
                "Connected",
                vec![
                    "Rust terminal client ↔ Racket database control plane".to_owned(),
                    "Type :help for commands; :share shows co-author connection details".to_owned(),
                ],
            )],
            operations: OperationTable::default(),
            transcript_scroll: 0,
            library: None,
            canvas: None,
            canvas_entry: None,
            canvas_search: None,
            current_database: None,
            sessions: Vec::new(),
            runtime: RuntimeLedger::default(),
            workspace: Workspace::default(),
            coauthor_endpoint: None,
            coauthor_discovery: None,
            shared_actions: Vec::new(),
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
                self.completion = None;
                if let Some(search) = self.canvas_search.as_mut() {
                    search.editor.insert(&text.replace(['\r', '\n'], " "));
                    self.update_canvas_search_preview();
                } else {
                    self.editor.insert(&text);
                }
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
                self.transcript
                    .push(TranscriptEntry::system("Racket", vec![line]));
            }
            BackendEvent::Disconnected(message) => {
                self.operations.clear();
                self.transcript
                    .push(TranscriptEntry::error("Server disconnected", vec![message]));
                self.should_quit = true;
            }
            BackendEvent::Response { command, response } => {
                self.completion = None;
                self.cancel_canvas_search();
                let workflow = self.finish_operation(&command);
                if !response.ok {
                    let error = response.error.unwrap_or(crate::protocol::ServerError {
                        kind: "server".to_owned(),
                        message: "unknown server failure".to_owned(),
                    });
                    self.transcript.push(TranscriptEntry::error(
                        failure_title(&error.kind),
                        vec![error.message],
                    ));
                    return;
                }
                let result = CommandResult::from_value(response.result.unwrap_or_default());
                let observation_warning = self.runtime.observe_result(result.raw()).err();
                self.update_session_context(result.raw());
                self.harvest_completion_paths(result.raw());
                let title = workflow
                    .and_then(|workflow| workflow.completed_label())
                    .unwrap_or_else(|| result.title().to_owned());
                if result.kind() == "library" {
                    match result
                        .raw()
                        .get("databases")
                        .cloned()
                        .map(serde_json::from_value::<Vec<DatabaseSummary>>)
                    {
                        Some(Ok(databases)) => {
                            self.completion_databases = databases
                                .iter()
                                .map(|database| database.name.clone())
                                .collect();
                            let mut library = LibraryView::new(databases);
                            if let Some(selected) = result
                                .raw()
                                .get("selected")
                                .and_then(|value| value.as_str())
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
                            self.transcript.push(TranscriptEntry::error(
                                "Library response",
                                vec![error.to_string()],
                            ));
                        }
                        None => {
                            self.transcript.push(TranscriptEntry::error(
                                "Library response",
                                vec!["server omitted the database list".to_owned()],
                            ));
                        }
                    }
                    return;
                }
                let canvas = PresentationCanvas::for_result(&result);
                self.transcript
                    .push(result.transcript_entry_with_title(title));
                self.install_canvas(canvas);
                if let Some(warning) = observation_warning {
                    self.transcript.push(TranscriptEntry::system(
                        "Runtime observation",
                        vec![format!(
                            "command succeeded, but the client could not record its structured state: {warning}"
                        )],
                    ));
                }
                if result.closes() || matches!(command.as_str(), ":quit" | "quit" | "exit") {
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
                    self.completion = None;
                    self.editor.clear();
                    return Effect::None;
                }
                KeyCode::Char('d') if self.editor.is_empty() => return Effect::Shutdown,
                KeyCode::Char('a') => {
                    self.completion = None;
                    self.editor.move_home();
                    return Effect::None;
                }
                KeyCode::Char('e') => {
                    self.completion = None;
                    self.editor.move_end();
                    return Effect::None;
                }
                _ => {}
            }
        }
        if self.library.is_some() {
            return self.on_library_key(key);
        }
        if self.canvas_search.is_some() {
            return self.on_canvas_search_key(key);
        }
        if self
            .canvas
            .as_ref()
            .is_some_and(|canvas| canvas.navigating())
        {
            return self.on_canvas_key(key);
        }
        if self.completion.is_some() {
            return self.on_completion_key(key);
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
                if self.editor.is_empty()
                    && self
                        .canvas
                        .as_mut()
                        .is_some_and(PresentationCanvas::enter_navigation)
                {
                    self.transcript_scroll = 0;
                } else if !self.begin_completion() {
                    self.editor.insert("  ");
                }
                Effect::None
            }
            KeyCode::F(1) => self.issue(
                ShellCommand::generated(":help").expect("generated help command is non-empty"),
            ),
            _ => Effect::None,
        }
    }

    fn on_completion_key(&mut self, key: KeyEvent) -> Effect {
        if key.code == KeyCode::BackTab
            || (key.code == KeyCode::Tab && key.modifiers.contains(KeyModifiers::SHIFT))
        {
            if let Some(completion) = self.completion.as_mut() {
                completion.previous();
            }
            return Effect::None;
        }
        match key.code {
            KeyCode::Tab | KeyCode::Down => {
                if let Some(completion) = self.completion.as_mut() {
                    completion.next();
                }
                Effect::None
            }
            KeyCode::Up => {
                if let Some(completion) = self.completion.as_mut() {
                    completion.previous();
                }
                Effect::None
            }
            KeyCode::Enter => {
                self.accept_completion();
                Effect::None
            }
            KeyCode::Esc => {
                self.completion = None;
                Effect::None
            }
            _ => {
                self.completion = None;
                self.on_key(key)
            }
        }
    }

    fn begin_completion(&mut self) -> bool {
        let inventory = self.completion_inventory();
        let Some(completion) = complete(self.editor.text(), self.editor.cursor(), &inventory)
        else {
            return false;
        };
        if completion.candidates().len() == 1 {
            self.apply_completion(completion);
        } else {
            self.completion = Some(completion);
        }
        true
    }

    fn accept_completion(&mut self) {
        if let Some(completion) = self.completion.take() {
            self.apply_completion(completion);
        }
    }

    fn apply_completion(&mut self, completion: CompletionMenu) {
        let (start, end) = completion.replacement_range();
        let replacement = completion.selected_candidate().replacement.clone();
        self.editor.replace_range(start, end, &replacement);
    }

    /// Relation and namespace paths from any result that carries the boundary
    /// projection (N4-A work order 6): `tables` reports the relations it
    /// listed, `catalog` reports the full declared set plus its namespaces.
    /// A declared-but-empty relation is in the projection, so it completes
    /// like any other.
    fn harvest_completion_paths(&mut self, raw: &serde_json::Value) {
        if let Some(relations) = raw.get("relations").and_then(|value| value.as_array()) {
            for relation in relations {
                if let Some(name) = relation.get("name").and_then(|value| value.as_str()) {
                    self.completion_relations.insert(name.to_owned());
                    let parts: Vec<&str> = name.split('.').collect();
                    for depth in 1..parts.len() {
                        self.completion_namespaces.insert(parts[..depth].join("."));
                    }
                }
            }
        }
        if let Some(namespaces) = raw.get("namespaces").and_then(|value| value.as_array()) {
            for namespace in namespaces {
                if let Some(path) = namespace.as_str() {
                    self.completion_namespaces.insert(path.to_owned());
                }
            }
        }
    }

    fn completion_inventory(&self) -> CompletionInventory {
        let mut databases = self.completion_databases.clone();
        databases.extend(
            self.sessions
                .iter()
                .filter_map(|session| session.database.clone()),
        );
        let mut inventory = CompletionInventory {
            databases: databases.into_iter().collect(),
            relations: self.completion_relations.iter().cloned().collect(),
            namespaces: self.completion_namespaces.iter().cloned().collect(),
            ..CompletionInventory::default()
        };
        if let Some(canvas) = &self.canvas {
            for line in canvas.rendered_lines() {
                match line.action {
                    Some(ExpansionAction::Expand) => inventory.expand_positions.push(line.path),
                    Some(ExpansionAction::Collapse) => inventory.collapse_positions.push(line.path),
                    None => {}
                }
            }
            inventory.card_positions = canvas.visible_card_positions();
            inventory.card_open = canvas.card().is_some();
            inventory.page_targets = canvas.visible_page_targets();
        }
        inventory
    }

    pub fn completion(&self) -> Option<&CompletionMenu> {
        self.completion.as_ref()
    }

    fn on_canvas_key(&mut self, key: KeyEvent) -> Effect {
        match key.code {
            KeyCode::Esc | KeyCode::Char('q') => {
                if let Some(canvas) = self.canvas.as_mut() {
                    canvas.leave_navigation();
                }
            }
            KeyCode::Up | KeyCode::Char('k') => {
                if let Some(canvas) = self.canvas.as_mut() {
                    canvas.select_previous();
                }
            }
            KeyCode::Down | KeyCode::Char('j') => {
                if let Some(canvas) = self.canvas.as_mut() {
                    canvas.select_next();
                }
            }
            KeyCode::Home => {
                if let Some(canvas) = self.canvas.as_mut() {
                    canvas.select_first();
                }
            }
            KeyCode::End => {
                if let Some(canvas) = self.canvas.as_mut() {
                    canvas.select_last();
                }
            }
            KeyCode::PageUp => {
                if let Some(canvas) = self.canvas.as_mut() {
                    for _ in 0..8 {
                        canvas.select_previous();
                    }
                }
            }
            KeyCode::PageDown => {
                if let Some(canvas) = self.canvas.as_mut() {
                    for _ in 0..8 {
                        canvas.select_next();
                    }
                }
            }
            KeyCode::Enter => {
                let command = self
                    .canvas
                    .as_mut()
                    .and_then(PresentationCanvas::toggle_selected);
                self.commit_canvas_gesture(command);
            }
            KeyCode::Char('o') => {
                let command = self
                    .canvas
                    .as_mut()
                    .and_then(PresentationCanvas::toggle_selected_card);
                self.commit_canvas_gesture(command);
            }
            KeyCode::Char('/') => {
                self.begin_canvas_search();
            }
            KeyCode::Char('n') if key.modifiers.contains(KeyModifiers::SHIFT) => {
                let command = self.canvas.as_mut().and_then(|canvas| {
                    canvas
                        .search_previous()
                        .then(|| "search-previous".to_owned())
                });
                self.commit_canvas_gesture(command);
            }
            KeyCode::Char('N') => {
                let command = self.canvas.as_mut().and_then(|canvas| {
                    canvas
                        .search_previous()
                        .then(|| "search-previous".to_owned())
                });
                self.commit_canvas_gesture(command);
            }
            KeyCode::Char('n') => {
                let command = self
                    .canvas
                    .as_mut()
                    .and_then(|canvas| canvas.search_next().then(|| "search-next".to_owned()));
                self.commit_canvas_gesture(command);
            }
            KeyCode::Right | KeyCode::Char('l') => {
                let command = self
                    .canvas
                    .as_mut()
                    .and_then(PresentationCanvas::expand_selected);
                self.commit_canvas_gesture(command);
            }
            KeyCode::Left | KeyCode::Char('h') | KeyCode::Backspace => {
                let command = self
                    .canvas
                    .as_mut()
                    .and_then(PresentationCanvas::collapse_selected);
                self.commit_canvas_gesture(command);
            }
            _ => return Effect::Ignore,
        }
        self.sync_canvas_entry();
        Effect::None
    }

    fn begin_canvas_search(&mut self) {
        let Some(canvas) = self.canvas.as_mut() else {
            return;
        };
        let snapshot = canvas.search_snapshot();
        canvas.clear_search();
        self.canvas_search = Some(CanvasSearchDraft {
            editor: Editor::default(),
            snapshot,
        });
    }

    fn on_canvas_search_key(&mut self, key: KeyEvent) -> Effect {
        if key.modifiers.contains(KeyModifiers::CONTROL) && matches!(key.code, KeyCode::Char('c')) {
            self.cancel_canvas_search();
            return Effect::None;
        }
        match key.code {
            KeyCode::Esc => self.cancel_canvas_search(),
            KeyCode::Enter => self.commit_canvas_search(),
            KeyCode::Char(character)
                if !key
                    .modifiers
                    .intersects(KeyModifiers::CONTROL | KeyModifiers::SUPER) =>
            {
                if let Some(search) = self.canvas_search.as_mut() {
                    search.editor.insert(&character.to_string());
                }
                self.update_canvas_search_preview();
            }
            KeyCode::Backspace => {
                if let Some(search) = self.canvas_search.as_mut() {
                    search.editor.backspace();
                }
                self.update_canvas_search_preview();
            }
            KeyCode::Delete => {
                if let Some(search) = self.canvas_search.as_mut() {
                    search.editor.delete();
                }
                self.update_canvas_search_preview();
            }
            KeyCode::Left => {
                if let Some(search) = self.canvas_search.as_mut() {
                    search.editor.move_left();
                }
            }
            KeyCode::Right => {
                if let Some(search) = self.canvas_search.as_mut() {
                    search.editor.move_right();
                }
            }
            KeyCode::Home => {
                if let Some(search) = self.canvas_search.as_mut() {
                    search.editor.move_home();
                }
            }
            KeyCode::End => {
                if let Some(search) = self.canvas_search.as_mut() {
                    search.editor.move_end();
                }
            }
            _ => return Effect::Ignore,
        }
        Effect::None
    }

    fn update_canvas_search_preview(&mut self) {
        let Some(query) = self
            .canvas_search
            .as_ref()
            .map(|search| search.editor.text().to_owned())
        else {
            return;
        };
        if let Some(canvas) = self.canvas.as_mut() {
            if query.trim().is_empty() {
                canvas.clear_search();
            } else {
                canvas.search(&query);
            }
        }
    }

    fn cancel_canvas_search(&mut self) {
        let Some(search) = self.canvas_search.take() else {
            return;
        };
        if let Some(canvas) = self.canvas.as_mut() {
            canvas.restore_search(search.snapshot);
        }
    }

    fn commit_canvas_search(&mut self) {
        let Some(search) = self.canvas_search.take() else {
            return;
        };
        let query = search.editor.text().trim().to_owned();
        let command = if query.is_empty() {
            if let Some(canvas) = self.canvas.as_mut() {
                canvas.clear_search();
            }
            "search-clear".to_owned()
        } else {
            if let Some(canvas) = self.canvas.as_mut() {
                canvas.search(&query);
            }
            format!("search {query}")
        };
        self.commit_canvas_gesture(Some(command));
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
                    self.issue(
                        ShellCommand::generated(command)
                            .expect("generated open command is non-empty"),
                    )
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
        if let Some(completion) = self.completion.as_mut() {
            return match mouse.kind {
                MouseEventKind::ScrollUp => {
                    completion.previous();
                    Effect::None
                }
                MouseEventKind::ScrollDown => {
                    completion.next();
                    Effect::None
                }
                _ => {
                    self.completion = None;
                    Effect::Ignore
                }
            };
        }
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
        self.completion = None;
        let source = self.editor.take();
        let Some(command) = ShellCommand::local(source.clone()) else {
            return Effect::None;
        };
        self.history.push(source.clone());
        self.history_position = None;
        if command.is_comment() {
            self.comment(command, "local");
            return Effect::None;
        }
        if command.text() == ":clear" {
            self.transcript.clear();
            self.canvas = None;
            self.canvas_entry = None;
            self.canvas_search = None;
            return Effect::None;
        }
        if command.text() == ":share" {
            self.show_coauthor_info();
            return Effect::None;
        }
        if Self::is_canvas_command(&command) {
            self.commit_typed_canvas_command(command);
            return Effect::None;
        }
        if command.text() == "library close" {
            self.close_library(None);
            return Effect::None;
        }
        if let Some(name) = command.text().strip_prefix("library select ")
            && self.library.is_some()
        {
            if !self.select_library_name(name.trim(), None) {
                self.transcript.push(TranscriptEntry::error(
                    "Library selection",
                    vec![format!("no database named {}", name.trim())],
                ));
            }
            return Effect::None;
        }
        self.issue(command)
    }

    fn issue(&mut self, command: ShellCommand) -> Effect {
        let title = self.prompt_label().to_owned();
        self.issue_as(command, title)
    }

    fn issue_as(&mut self, command: ShellCommand, title: String) -> Effect {
        self.transcript
            .push(TranscriptEntry::command(command.clone(), title));
        self.transcript_scroll = 0;
        Effect::Execute(command)
    }

    fn is_canvas_command(command: &ShellCommand) -> bool {
        matches!(
            command.verb().to_ascii_lowercase().as_str(),
            "expand"
                | "collapse"
                | "card"
                | "search"
                | "search-next"
                | "search-previous"
                | "search-clear"
                | "page"
        )
    }

    fn commit_typed_canvas_command(&mut self, command: ShellCommand) {
        let title = self.prompt_label().to_owned();
        let outcome = self
            .canvas
            .as_mut()
            .ok_or_else(|| "there is no live result canvas".to_owned())
            .and_then(|canvas| canvas.apply_command(command.text()));
        self.transcript
            .push(TranscriptEntry::command(command, title));
        match outcome {
            Ok(true) => self.sync_canvas_entry(),
            Ok(false) => unreachable!("canvas command was classified before dispatch"),
            Err(message) => self
                .transcript
                .push(TranscriptEntry::error("Canvas", vec![message])),
        }
        self.transcript_scroll = 0;
    }

    fn commit_canvas_gesture(&mut self, command: Option<String>) {
        let Some(command) = command.and_then(ShellCommand::generated) else {
            return;
        };
        let title = self.prompt_label().to_owned();
        self.transcript
            .push(TranscriptEntry::command(command, title));
        self.transcript_scroll = 0;
    }

    fn install_canvas(&mut self, canvas: PresentationCanvas) {
        self.cancel_canvas_search();
        if !canvas.has_content() {
            self.canvas = None;
            self.canvas_entry = None;
            return;
        }
        self.canvas_entry = self.transcript.len().checked_sub(1);
        self.canvas = Some(canvas);
        self.sync_canvas_entry();
    }

    fn sync_canvas_entry(&mut self) {
        let Some(index) = self.canvas_entry else {
            return;
        };
        let Some(lines) = self.canvas.as_ref().map(PresentationCanvas::plain_lines) else {
            return;
        };
        if let Some(entry) = self.transcript.get_mut(index) {
            entry.lines = lines;
        }
    }

    pub fn canvas_selected_line(&self, entry: usize) -> Option<usize> {
        (self.canvas_entry == Some(entry))
            .then(|| {
                self.canvas
                    .as_ref()
                    .and_then(PresentationCanvas::selected_line)
            })
            .flatten()
    }

    pub fn canvas_navigating(&self) -> bool {
        self.canvas
            .as_ref()
            .is_some_and(PresentationCanvas::navigating)
    }

    pub fn canvas_card(&self) -> Option<PresentationCard> {
        self.canvas.as_ref().and_then(PresentationCanvas::card)
    }

    pub fn canvas_search_editor(&self) -> Option<&Editor> {
        self.canvas_search.as_ref().map(|search| &search.editor)
    }

    pub fn canvas_search_summary(&self) -> Option<PresentationSearchSummary> {
        self.canvas
            .as_ref()
            .and_then(PresentationCanvas::search_summary)
    }

    pub fn canvas_search_match_lines(&self, entry: usize) -> Vec<usize> {
        if self.canvas_entry != Some(entry) || !self.canvas_navigating() {
            return Vec::new();
        }
        self.canvas
            .as_ref()
            .map(PresentationCanvas::search_match_lines)
            .unwrap_or_default()
    }

    fn comment(&mut self, command: ShellCommand, title: &str) {
        self.transcript
            .push(TranscriptEntry::comment(command, title));
        self.transcript_scroll = 0;
    }

    fn record_shared_action(&mut self, command: String, actor: Option<String>) {
        let action = match actor {
            Some(actor) => SharedAction::coauthor(actor, command),
            None => SharedAction::generated(command),
        };
        if let Some(action) = action {
            self.shared_actions.push(action);
        }
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
        action.plain()
    }

    pub fn on_coauthor(&mut self, source: &str, text: String) -> Effect {
        let Some(command) = ShellCommand::coauthor(source, text) else {
            return Effect::None;
        };
        self.completion = None;
        self.cancel_canvas_search();
        if command.is_comment() {
            self.comment(command, source);
            return Effect::None;
        }
        if Self::is_canvas_command(&command) {
            self.commit_typed_canvas_command(command);
            return Effect::None;
        }
        if command.text() == "library close" {
            self.close_library(Some(source.to_owned()));
            return Effect::None;
        }
        if let Some(name) = command.text().strip_prefix("library select ")
            && self.library.is_some()
        {
            let name = name.trim().to_owned();
            if !self.select_library_name(&name, Some(source.to_owned())) {
                self.record_shared_action(command.text().to_owned(), Some(source.to_owned()));
                self.transcript.push(TranscriptEntry::error(
                    "Library selection",
                    vec![format!("no database named {name}")],
                ));
            }
            return Effect::None;
        }
        // A semantic shell command is also the escape hatch from a visual
        // mode. Headless peers can always act directly on the data they saw.
        if command.database_to_open().is_some() {
            self.library = None;
        } else {
            self.close_library(Some(source.to_owned()));
        }
        let title = self.prompt_label().to_owned();
        self.issue_as(command, title)
    }

    pub fn coauthor_input_is_view_command(text: &str) -> bool {
        ShellCommand::coauthor("coauthor", text).is_some_and(|command| command.is_view_command())
    }

    pub fn private_command_allowed(command: &str) -> bool {
        ShellCommand::private("coauthor", command).is_some_and(|command| command.private_allowed())
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
                    return format!("! {}\n  {}", failure_title(&error.kind), error.message);
                }
                let result = CommandResult::from_value(response.result.unwrap_or_default());
                self.update_session_context(result.raw());
                self.harvest_completion_paths(result.raw());
                if result.kind() == "library" {
                    return match result
                        .raw()
                        .get("databases")
                        .cloned()
                        .map(serde_json::from_value::<Vec<DatabaseSummary>>)
                    {
                        Some(Ok(databases)) => {
                            let mut library = LibraryView::new(databases);
                            if let Some(selected) = result
                                .raw()
                                .get("selected")
                                .and_then(|value| value.as_str())
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
                Self::plain_entry(&result.transcript_entry())
            }
        }
    }

    pub fn add_system_entry(&mut self, title: impl Into<String>, lines: Vec<String>) {
        self.transcript.push(TranscriptEntry::system(title, lines));
    }

    pub fn add_presence(&mut self, message: impl Into<String>) {
        self.transcript.push(TranscriptEntry::presence(message));
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
        command: &ShellCommand,
        daemon_rebuild_pending: bool,
    ) -> Option<String> {
        let fixed = self
            .operations
            .begin_for_command(command, daemon_rebuild_pending)?;
        self.transcript_scroll = 0;
        Some(fixed)
    }

    pub fn tick(&mut self) -> bool {
        self.operations.tick()
    }

    pub fn take_progress_updates(&mut self) -> Vec<String> {
        self.operations.take_progress_updates()
    }

    fn finish_operation(&mut self, command: &str) -> Option<crate::operation::Operation> {
        self.operations.finish(command)
    }

    pub fn plain_entry(entry: &TranscriptEntry) -> String {
        entry.plain()
    }

    pub fn plain_share_snapshot(&self) -> String {
        let mut entries = Vec::new();
        let transcript = crate::transcript::render_plain(&self.transcript);
        if !transcript.is_empty() {
            entries.push(transcript);
        }
        entries.extend(
            self.operations
                .active()
                .iter()
                .map(crate::operation::Operation::fixed_label),
        );
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
                "shell:{}:{}:{}:{}",
                self.current_database.as_deref().unwrap_or("none"),
                self.sessions.len(),
                self.workspace
                    .active()
                    .map(|draft| draft.id().get().to_string())
                    .unwrap_or_else(|| "none".to_owned()),
                self.workspace
                    .active()
                    .map(|draft| draft.revision().get().to_string())
                    .unwrap_or_else(|| "none".to_owned())
            ),
        }
    }

    pub fn plain_shared_view(&self, full: bool) -> String {
        match &self.library {
            Some(library) => self.plain_library_view(library, full),
            None => {
                let resident = self.sessions.len();
                let runtime = self
                    .current_database
                    .as_deref()
                    .and_then(|target| self.runtime.session(target))
                    .map(|state| format!(" · {}", state.plain_summary()))
                    .unwrap_or_default();
                format!(
                    "◇ View · shell · database {} · {resident} resident database{}{runtime}",
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
                Err(error) => self.transcript.push(TranscriptEntry::error(
                    "Resident database response",
                    vec![error.to_string()],
                )),
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

/// A failed server response's transcript title.  Matches the Racket
/// `--plain` harness rendering ("Command failed") so the shared
/// semantic-session golden pins one rendering across both clients.
pub fn failure_title(kind: &str) -> String {
    let mut chars = kind.chars();
    match chars.next() {
        Some(first) => format!("{}{} failed", first.to_uppercase(), chars.as_str()),
        None => "Failed".to_owned(),
    }
}

#[cfg(test)]
mod tests {
    use super::{App, Effect, EntryKind};
    use crate::backend::BackendEvent;
    use crate::command::ShellCommand;
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
    fn tab_completes_unique_verbs_and_cycles_grammar_arguments() {
        let mut app = App::new();
        app.editor.insert("ta");
        app.on_terminal(Event::Key(KeyEvent::new(KeyCode::Tab, KeyModifiers::NONE)));
        assert_eq!(app.editor.text(), "tables ");
        assert!(app.completion().is_none());

        app.editor.replace("mode ".to_owned());
        app.on_terminal(Event::Key(KeyEvent::new(KeyCode::Tab, KeyModifiers::NONE)));
        assert_eq!(
            app.completion()
                .expect("mode candidates")
                .selected_candidate()
                .label,
            "mutable"
        );
        app.on_terminal(Event::Key(KeyEvent::new(KeyCode::Down, KeyModifiers::NONE)));
        app.on_terminal(Event::Key(KeyEvent::new(
            KeyCode::Enter,
            KeyModifiers::NONE,
        )));
        assert_eq!(app.editor.text(), "mode readonly");
        assert!(app.completion().is_none());
        assert_eq!(app.transcript.len(), 1);
    }

    #[test]
    fn completion_uses_only_structured_database_and_live_canvas_state() {
        let mut app = App::new();
        app.on_backend(BackendEvent::Response {
            command: ":status".to_owned(),
            response: Response {
                id: 3,
                ok: true,
                result: Some(serde_json::json!({
                    "kind": "status",
                    "title": "Status",
                    "lines": [],
                    "current": "alpha",
                    "sessions": [{
                        "name": "alpha",
                        "database": "alpha",
                        "current": true,
                        "mode": "mutable",
                        "changed": false
                    }]
                })),
                error: None,
            },
        });
        app.editor.insert("open al");
        app.on_terminal(Event::Key(KeyEvent::new(KeyCode::Tab, KeyModifiers::NONE)));
        assert_eq!(app.editor.text(), "open alpha");

        app.editor.replace("count ed".to_owned());
        app.on_terminal(Event::Key(KeyEvent::new(KeyCode::Tab, KeyModifiers::NONE)));
        assert_eq!(
            app.editor.text(),
            "count ed  ",
            "relation names are not inferred without a boundary catalog"
        );

        app.on_backend(BackendEvent::Response {
            command: "add edge 4 5".to_owned(),
            response: Response {
                id: 4,
                ok: true,
                result: Some(serde_json::json!({
                    "kind": "mutation",
                    "title": "Add · edge",
                    "lines": ["settled"],
                    "change": {
                        "operation": "add",
                        "target": "alpha",
                        "status": "settled"
                    }
                })),
                error: None,
            },
        });
        app.editor.replace("expand it.c".to_owned());
        app.on_terminal(Event::Key(KeyEvent::new(KeyCode::Tab, KeyModifiers::NONE)));
        assert_eq!(app.editor.text(), "expand it.change");
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
        assert!(matches!(effect, Effect::Execute(ref command) if command.text() == "open example"));
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
    fn semantic_response_updates_the_runtime_projection() {
        let mut app = App::new();
        app.on_backend(BackendEvent::Response {
            command: "add edge 4 5".to_owned(),
            response: Response {
                id: 3,
                ok: true,
                result: Some(serde_json::json!({
                    "kind": "mutation",
                    "title": "Add · edge",
                    "lines": ["settled"],
                    "current": "example",
                    "sessions": [],
                    "change": {
                        "operation": "add",
                        "target": "example",
                        "status": "settled",
                        "update-revision": 7,
                        "counts": "valid",
                        "requested": [{"relation": "edge", "added": 1, "removed": 0}],
                        "size-deltas": [
                            {"relation": "edge", "before": 3, "after": 4, "net": 1}
                        ],
                        "size-deltas-omitted": 0,
                        "sizes-observed": true,
                        "routes": [{"kind": "maintain", "detail": ["0"]}]
                    }
                })),
                error: None,
            },
        });

        let state = app.runtime.session("example").expect("runtime projection");
        assert_eq!(
            state.update_revision,
            Some(crate::runtime::UpdateRevision(7))
        );
        assert_eq!(state.observed_relation_sizes["edge"], 4);
        assert_eq!(
            state.last_change.as_ref().expect("change").routes[0].kind,
            "maintain"
        );
        assert!(
            app.plain_shared_view(false)
                .contains("update revision 7 · counts valid")
        );
    }

    #[test]
    fn latest_semantic_result_is_a_navigable_canvas_with_gesture_echo() {
        let mut app = App::new();
        app.on_backend(BackendEvent::Response {
            command: "add edge 4 5".to_owned(),
            response: Response {
                id: 4,
                ok: true,
                result: Some(serde_json::json!({
                    "kind": "mutation",
                    "title": "Add · edge",
                    "lines": ["settled"],
                    "change": {
                        "operation": "add",
                        "target": "example",
                        "status": "settled",
                        "update-revision": 7,
                        "counts": "valid",
                        "requested": [{"relation": "edge", "added": 1, "removed": 0}],
                        "size-deltas": [],
                        "size-deltas-omitted": 0,
                        "sizes-observed": true,
                        "routes": []
                    }
                })),
                error: None,
            },
        });
        let result_index = app.transcript.len() - 1;
        assert_eq!(
            app.transcript[result_index].lines,
            ["settled", "▸ Change details"]
        );

        assert!(matches!(
            app.on_terminal(Event::Key(KeyEvent::new(KeyCode::Tab, KeyModifiers::NONE))),
            Effect::None
        ));
        assert!(app.canvas_navigating());
        app.on_terminal(Event::Key(KeyEvent::new(KeyCode::End, KeyModifiers::NONE)));
        let effect = app.on_terminal(Event::Key(KeyEvent::new(
            KeyCode::Enter,
            KeyModifiers::NONE,
        )));
        assert!(matches!(effect, Effect::None));
        assert!(
            app.transcript[result_index]
                .lines
                .contains(&"▾ Change details".to_owned())
        );
        assert!(
            app.transcript[result_index]
                .lines
                .contains(&"  operation: add".to_owned())
        );
        let echo = app.transcript.last().expect("gesture echo");
        assert_eq!(echo.kind, EntryKind::GeneratedCommand);
        assert_eq!(echo.lines, ["expand it.change"]);

        app.on_terminal(Event::Key(KeyEvent::new(
            KeyCode::Enter,
            KeyModifiers::NONE,
        )));
        assert!(
            app.transcript[result_index]
                .lines
                .contains(&"▸ Change details".to_owned())
        );
        assert_eq!(
            app.transcript.last().expect("collapse echo").lines,
            ["collapse it.change"]
        );
        app.on_terminal(Event::Key(KeyEvent::new(
            KeyCode::Char('o'),
            KeyModifiers::NONE,
        )));
        assert_eq!(
            app.transcript.last().expect("card echo").lines,
            ["card it.change"]
        );
        let card = app.canvas_card().expect("change card");
        assert_eq!(card.title, "Change details");
        assert!(card.actions.contains(&"expand it.change".to_owned()));
        app.on_terminal(Event::Key(KeyEvent::new(
            KeyCode::Char('o'),
            KeyModifiers::NONE,
        )));
        assert!(app.canvas_card().is_none());
        assert_eq!(
            app.transcript.last().expect("card close echo").lines,
            ["card close"]
        );
        app.on_terminal(Event::Key(KeyEvent::new(KeyCode::Esc, KeyModifiers::NONE)));
        assert!(!app.canvas_navigating());
    }

    #[test]
    fn typed_canvas_commands_use_the_same_expansion_path_and_stay_client_side() {
        let mut app = App::new();
        app.on_backend(BackendEvent::Response {
            command: "add edge 4 5".to_owned(),
            response: Response {
                id: 5,
                ok: true,
                result: Some(serde_json::json!({
                    "kind": "mutation",
                    "title": "Add · edge",
                    "lines": ["settled"],
                    "change": {
                        "operation": "add",
                        "target": "example",
                        "status": "settled"
                    }
                })),
                error: None,
            },
        });
        let result_index = app.transcript.len() - 1;
        app.editor.insert("expand it.change");
        let effect = app.on_terminal(Event::Key(KeyEvent::new(
            KeyCode::Enter,
            KeyModifiers::NONE,
        )));
        assert!(matches!(effect, Effect::None));
        assert!(
            app.transcript[result_index]
                .lines
                .contains(&"  operation: add".to_owned())
        );
        let echo = app.transcript.last().expect("typed echo");
        assert_eq!(echo.kind, EntryKind::Command);
        assert_eq!(echo.lines, ["expand it.change"]);

        let effect = app.on_coauthor("codex", "collapse it.change".to_owned());
        assert!(matches!(effect, Effect::None));
        assert!(
            app.transcript[result_index]
                .lines
                .contains(&"▸ Change details".to_owned())
        );
        let echo = app.transcript.last().expect("coauthor echo");
        assert_eq!(echo.actor.as_deref(), Some("codex"));
        assert_eq!(echo.lines, ["collapse it.change"]);

        app.editor.insert("card it.change");
        let effect = app.on_terminal(Event::Key(KeyEvent::new(
            KeyCode::Enter,
            KeyModifiers::NONE,
        )));
        assert!(matches!(effect, Effect::None));
        assert_eq!(
            app.canvas_card().expect("typed card").kind,
            "semantic change"
        );
    }

    #[test]
    fn incremental_canvas_search_commits_canonical_commands_and_can_cancel() {
        let mut app = App::new();
        app.on_backend(BackendEvent::Response {
            command: "add edge 4 5".to_owned(),
            response: Response {
                id: 6,
                ok: true,
                result: Some(serde_json::json!({
                    "kind": "mutation",
                    "title": "Add · edge",
                    "lines": ["settled", "edge ready"],
                    "change": {
                        "operation": "add",
                        "target": "example",
                        "status": "settled"
                    }
                })),
                error: None,
            },
        });
        app.on_terminal(Event::Key(KeyEvent::new(KeyCode::Tab, KeyModifiers::NONE)));
        app.on_terminal(Event::Key(KeyEvent::new(KeyCode::End, KeyModifiers::NONE)));
        app.on_terminal(Event::Key(KeyEvent::new(
            KeyCode::Enter,
            KeyModifiers::NONE,
        )));
        app.on_terminal(Event::Key(KeyEvent::new(
            KeyCode::Char('/'),
            KeyModifiers::NONE,
        )));
        for character in "operation".chars() {
            app.on_terminal(Event::Key(KeyEvent::new(
                KeyCode::Char(character),
                KeyModifiers::NONE,
            )));
        }
        assert_eq!(
            app.canvas_search_editor().expect("search editor").text(),
            "operation"
        );
        assert_eq!(app.canvas_search_summary().expect("preview").total, 1);

        app.on_terminal(Event::Key(KeyEvent::new(
            KeyCode::Enter,
            KeyModifiers::NONE,
        )));
        assert!(app.canvas_search_editor().is_none());
        assert_eq!(
            app.transcript.last().expect("search echo").lines,
            ["search operation"]
        );
        app.on_terminal(Event::Key(KeyEvent::new(
            KeyCode::Char('n'),
            KeyModifiers::NONE,
        )));
        assert_eq!(
            app.transcript.last().expect("next echo").lines,
            ["search-next"]
        );
        app.on_terminal(Event::Key(KeyEvent::new(
            KeyCode::Char('N'),
            KeyModifiers::SHIFT,
        )));
        assert_eq!(
            app.transcript.last().expect("previous echo").lines,
            ["search-previous"]
        );

        let before_cancel = app.transcript.len();
        app.on_terminal(Event::Key(KeyEvent::new(
            KeyCode::Char('/'),
            KeyModifiers::NONE,
        )));
        for character in "missing".chars() {
            app.on_terminal(Event::Key(KeyEvent::new(
                KeyCode::Char(character),
                KeyModifiers::NONE,
            )));
        }
        assert_eq!(app.canvas_search_summary().expect("no matches").total, 0);
        app.on_terminal(Event::Key(KeyEvent::new(KeyCode::Esc, KeyModifiers::NONE)));
        assert_eq!(app.transcript.len(), before_cancel);
        assert_eq!(
            app.canvas_search_summary().expect("restored search").query,
            "operation"
        );

        app.on_terminal(Event::Key(KeyEvent::new(KeyCode::Esc, KeyModifiers::NONE)));
        app.editor.insert("search settled");
        let effect = app.on_terminal(Event::Key(KeyEvent::new(
            KeyCode::Enter,
            KeyModifiers::NONE,
        )));
        assert!(matches!(effect, Effect::None));
        assert!(app.canvas_navigating());
        assert_eq!(
            app.canvas_search_summary().expect("typed search").query,
            "settled"
        );
        let effect = app.on_coauthor("codex", "search-next".to_owned());
        assert!(matches!(effect, Effect::None));
        assert_eq!(
            app.transcript
                .last()
                .expect("coauthor search")
                .actor
                .as_deref(),
            Some("codex")
        );
    }

    #[test]
    fn structured_live_relations_join_canvas_navigation_and_cards() {
        let mut app = App::new();
        app.on_backend(BackendEvent::Response {
            command: "tables".to_owned(),
            response: Response {
                id: 7,
                ok: true,
                result: Some(serde_json::json!({
                    "kind": "tables",
                    "title": "Live relations",
                    "lines": ["edge/2  table · Int Int  3 rows"],
                    "relations": [{
                        "name": "edge",
                        "kind": "table",
                        "arity": 2,
                        "detail": ["Int", "Int"],
                        "rows": 3
                    }],
                    "relations-total": 1,
                    "relations-filter": "",
                    "relations-scope": "current live session"
                })),
                error: None,
            },
        });
        let result_index = app.transcript.len() - 1;
        assert_eq!(
            app.transcript[result_index].lines,
            [
                "edge/2  table · Int Int  3 rows",
                "▸ Live relation observations (1)"
            ]
        );
        app.on_terminal(Event::Key(KeyEvent::new(KeyCode::Tab, KeyModifiers::NONE)));
        app.on_terminal(Event::Key(KeyEvent::new(KeyCode::End, KeyModifiers::NONE)));
        app.on_terminal(Event::Key(KeyEvent::new(
            KeyCode::Enter,
            KeyModifiers::NONE,
        )));
        assert_eq!(
            app.transcript.last().expect("relation expansion").lines,
            ["expand it.relations"]
        );
        app.on_terminal(Event::Key(KeyEvent::new(KeyCode::Down, KeyModifiers::NONE)));
        app.on_terminal(Event::Key(KeyEvent::new(
            KeyCode::Char('o'),
            KeyModifiers::NONE,
        )));
        let card = app.canvas_card().expect("edge relation card");
        assert_eq!(card.title, "edge");
        assert_eq!(card.kind, "live relation observation");
        assert!(card.actions.contains(&"count edge".to_owned()));
        assert!(
            card.fields.iter().any(|field| {
                field.label == "identity" && field.value.contains("no BoundaryKey")
            })
        );
    }

    #[test]
    fn buffered_canvas_pages_use_the_same_absolute_command_for_gestures_and_coauthors() {
        let mut app = App::new();
        let lines = (1..=22).map(|row| format!("row {row}")).collect::<Vec<_>>();
        app.on_backend(BackendEvent::Response {
            command: "show edge all".to_owned(),
            response: Response {
                id: 11,
                ok: true,
                result: Some(serde_json::json!({
                    "kind": "query",
                    "title": "Rows · edge",
                    "lines": lines
                })),
                error: None,
            },
        });
        let result_index = app.transcript.len() - 1;
        assert_eq!(
            app.transcript[result_index]
                .lines
                .last()
                .map(String::as_str),
            Some("▸ … 2 more · page 1/2")
        );

        app.on_terminal(Event::Key(KeyEvent::new(KeyCode::Tab, KeyModifiers::NONE)));
        app.on_terminal(Event::Key(KeyEvent::new(KeyCode::End, KeyModifiers::NONE)));
        app.on_terminal(Event::Key(KeyEvent::new(
            KeyCode::Enter,
            KeyModifiers::NONE,
        )));
        assert_eq!(
            app.transcript.last().expect("page gesture").lines,
            ["page it 2"]
        );
        assert_eq!(
            app.transcript[result_index].lines,
            ["◂ 20 before · page 2/2", "row 21", "row 22"]
        );

        app.on_terminal(Event::Key(KeyEvent::new(KeyCode::Esc, KeyModifiers::NONE)));
        app.editor.insert("page it 1");
        assert!(matches!(
            app.on_terminal(Event::Key(KeyEvent::new(
                KeyCode::Enter,
                KeyModifiers::NONE
            ))),
            Effect::None
        ));
        assert_eq!(
            app.transcript[result_index]
                .lines
                .last()
                .map(String::as_str),
            Some("▸ … 2 more · page 1/2")
        );

        assert!(matches!(
            app.on_coauthor("codex", "page it 2".to_owned()),
            Effect::None
        ));
        assert_eq!(
            app.transcript[result_index].lines,
            ["◂ 20 before · page 2/2", "row 21", "row 22"]
        );
        let echo = app.transcript.last().expect("coauthor page");
        assert_eq!(echo.actor.as_deref(), Some("codex"));
        assert_eq!(echo.lines, ["page it 2"]);
    }

    #[test]
    fn database_load_is_transient_until_the_response_commits() {
        let mut app = App::new();
        let durable = app.transcript.len();
        let command = ShellCommand::generated("open example").expect("command");
        assert_eq!(
            app.begin_operation(&command, false).as_deref(),
            Some("Loading database `example`... · request sent to the session server")
        );
        assert_eq!(app.transcript.len(), durable);
        assert!(
            app.plain_share_snapshot()
                .contains("Loading database `example`... · request sent to the session server")
        );
        assert!(!app.plain_share_snapshot().contains('◌'));
        assert_eq!(
            app.operations.active()[0].animated_label(),
            "Loading database `example`.   · request sent to the session server"
        );
        app.tick();
        assert_eq!(
            app.operations.active()[0].animated_label(),
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
        assert!(app.operations.is_empty());
        let committed = app.transcript.last().expect("committed response");
        assert_eq!(committed.kind, EntryKind::Result);
        assert_eq!(committed.title, "Loaded database `example`");
    }

    #[test]
    fn database_load_explains_a_pending_daemon_rebuild() {
        let mut app = App::new();
        let command = ShellCommand::generated("open example").expect("command");
        assert_eq!(
            app.begin_operation(&command, true).as_deref(),
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
    fn help_shortcut_emits_the_canonical_workbench_command() {
        let mut app = App::new();
        let effect = app.on_terminal(Event::Key(KeyEvent::new(KeyCode::F(1), KeyModifiers::NONE)));
        assert!(matches!(effect, Effect::Execute(ref command) if command.text() == ":help"));
        let command = app.transcript.last().expect("generated help command");
        assert_eq!(command.kind, EntryKind::GeneratedCommand);
        assert_eq!(command.lines, vec![":help"]);
    }

    #[test]
    fn coauthor_input_is_dim_generated_shell_input() {
        let mut app = App::new();
        let effect = app.on_coauthor("codex", "tables edge".to_owned());
        assert!(matches!(effect, Effect::Execute(ref command) if command.text() == "tables edge"));
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
        assert!(matches!(effect, Effect::Execute(ref command) if command.text() == "open beta"));
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
        assert!(App::private_command_allowed(":help"));
        assert!(App::private_command_allowed(":status"));
        assert!(!App::private_command_allowed("add edge 1 2"));
        assert!(!App::private_command_allowed(":quit"));
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
