mod library;

use crate::app::{App, EntryKind};
use crate::completion::CompletionMenu;
use crate::present::PresentationCard;
use crate::version;
use ratatui::Frame;
use ratatui::layout::{Alignment, Constraint, Layout, Rect};
use ratatui::style::{Color, Modifier, Style};
use ratatui::text::{Line, Span, Text};
use ratatui::widgets::{Block, Borders, Padding, Paragraph, Wrap};

const CYAN: Color = Color::Rgb(62, 207, 227);
const PINK: Color = Color::Rgb(244, 114, 182);
const GREEN: Color = Color::Rgb(74, 222, 128);
const MUTED: Color = Color::Rgb(124, 139, 161);
const PANEL: Color = Color::Rgb(30, 36, 50);

pub fn draw(frame: &mut Frame<'_>, app: &App) {
    let area = frame.area();
    if let Some(library) = &app.library {
        let sections = Layout::vertical([Constraint::Min(8), Constraint::Length(1)]).split(area);
        library::render(frame, sections[0], library, &app.sessions);
        render_library_footer(frame, sections[1]);
        return;
    }
    if let Some(completion) = app.completion() {
        let completion_height = (completion.candidates().len().min(5) as u16).saturating_add(2);
        let sections = Layout::vertical([
            Constraint::Min(5),
            Constraint::Length(completion_height),
            Constraint::Length(5),
        ])
        .split(area);
        render_body(frame, sections[0], app);
        render_completion(frame, sections[1], completion);
        render_editor(frame, sections[2], app);
        return;
    }
    let sections = Layout::vertical([Constraint::Min(8), Constraint::Length(5)]).split(area);
    render_body(frame, sections[0], app);
    render_editor(frame, sections[1], app);
}

fn render_body(frame: &mut Frame<'_>, area: Rect, app: &App) {
    if area.width >= 80
        && let Some(card) = app.canvas_card()
    {
        let card_width = (area.width * 30 / 100).clamp(28, 42);
        let columns =
            Layout::horizontal([Constraint::Min(40), Constraint::Length(card_width)]).split(area);
        render_primary(frame, columns[0], app);
        render_canvas_card(frame, columns[1], &card);
    } else {
        render_primary(frame, area, app);
    }
}

fn render_primary(frame: &mut Frame<'_>, area: Rect, app: &App) {
    if app.transcript.len() <= 1 {
        render_splash(frame, area, app);
    } else {
        render_transcript(frame, area, app);
    }
}

fn render_splash(frame: &mut Frame<'_>, area: Rect, app: &App) {
    let version_line = format!("                 /____/  v{}", version::current());
    // Ratatui centers each line independently. Pad the whole logo to the
    // version line's width so the descender of the `g` stays aligned.
    let art_width = version_line.len();
    let mut art = [
        "       _____ __".to_owned(),
        "      / ___// /___  ____ _".to_owned(),
        "      \\__ \\/ / __ \\/ __ `/".to_owned(),
        "     ___/ / / /_/ / /_/ /".to_owned(),
        "    /____/_/\\____/\\__, /".to_owned(),
        version_line,
    ];
    for line in &mut art {
        *line = format!("{line:<art_width$}");
    }
    let mut lines = vec![Line::from("")];
    for (index, line) in art.iter().enumerate() {
        let color = Color::Rgb(45 + index as u8 * 16, 180 + index as u8 * 8, 230);
        lines.push(Line::styled(line.as_str(), Style::default().fg(color)));
    }
    lines.extend([
        Line::from(""),
        Line::styled(
            "Symbolic-expression logic programming",
            Style::default()
                .fg(Color::White)
                .add_modifier(Modifier::BOLD),
        ),
        Line::from(""),
        Line::from(vec![
            Span::styled(":help", Style::default().fg(CYAN)),
            Span::raw(" for commands"),
        ]),
    ]);
    if let Some(endpoint) = &app.coauthor_endpoint {
        let suggestion = lines.last_mut().expect("splash has suggestion line");
        suggestion.spans.extend([
            Span::raw("  ·  "),
            Span::styled("co-author", Style::default().fg(MUTED)),
            Span::raw("  "),
            Span::styled(endpoint, Style::default().fg(CYAN)),
            Span::raw("  ·  "),
            Span::styled(":share", Style::default().fg(PINK)),
            Span::raw(" connection details"),
        ]);
    }
    let paragraph = Paragraph::new(lines).alignment(Alignment::Center).block(
        Block::default()
            .borders(Borders::ALL)
            .border_style(Style::default().fg(PANEL))
            .title(" Welcome "),
    );
    frame.render_widget(paragraph, area);
}

fn render_transcript(frame: &mut Frame<'_>, area: Rect, app: &App) {
    let mut lines = Vec::new();
    for (entry_index, entry) in app.transcript.iter().enumerate() {
        if entry.kind == EntryKind::Comment {
            for (index, line) in entry.lines.iter().enumerate() {
                let mut spans = vec![Span::styled(
                    format!("  {line}"),
                    Style::default().fg(Color::DarkGray),
                )];
                if index == 0 && entry.title != "local" {
                    spans.push(Span::styled(
                        format!("  — {}", entry.title),
                        Style::default().fg(MUTED),
                    ));
                }
                lines.push(Line::from(spans));
            }
            lines.push(Line::from(""));
            continue;
        }
        if entry.kind == EntryKind::Presence {
            lines.push(Line::styled(
                format!("  · {}", entry.title),
                Style::default().fg(Color::DarkGray),
            ));
            continue;
        }
        if matches!(entry.kind, EntryKind::Command | EntryKind::GeneratedCommand) {
            let color = if entry.kind == EntryKind::GeneratedCommand {
                Color::DarkGray
            } else {
                CYAN
            };
            for (index, command_line) in entry.lines.iter().enumerate() {
                let mut spans = vec![Span::styled(
                    if index == 0 {
                        format!("› {command_line}")
                    } else {
                        format!("  {command_line}")
                    },
                    Style::default().fg(color),
                )];
                if index == 0
                    && let Some(actor) = &entry.actor
                {
                    spans.push(Span::styled(
                        format!("  — {actor}"),
                        Style::default().fg(MUTED),
                    ));
                }
                lines.push(Line::from(spans));
            }
            lines.push(Line::from(""));
            continue;
        }
        let (prefix, color) = match entry.kind {
            EntryKind::Command | EntryKind::GeneratedCommand => {
                unreachable!("commands render above")
            }
            EntryKind::Comment => unreachable!("comments render above"),
            EntryKind::Presence => unreachable!("presence renders above"),
            EntryKind::Result => ("◆", GREEN),
            EntryKind::Error => ("!", Color::LightRed),
            EntryKind::System => ("•", MUTED),
        };
        lines.push(Line::from(vec![
            Span::styled(format!("{prefix} "), Style::default().fg(color)),
            Span::styled(
                &entry.title,
                Style::default().fg(color).add_modifier(Modifier::BOLD),
            ),
        ]));
        let selected_line = app.canvas_selected_line(entry_index);
        let search_matches = app.canvas_search_match_lines(entry_index);
        for (line_index, line) in entry.lines.iter().enumerate() {
            let selected = selected_line == Some(line_index);
            let search_match = search_matches.contains(&line_index);
            lines.push(Line::styled(
                format!("{}{line}", if selected { "› " } else { "  " }),
                if selected {
                    Style::default()
                        .fg(Color::White)
                        .bg(PANEL)
                        .add_modifier(Modifier::BOLD)
                } else if search_match {
                    Style::default().fg(PINK).add_modifier(Modifier::BOLD)
                } else {
                    Style::default().fg(Color::Gray)
                },
            ));
        }
        lines.push(Line::from(""));
    }
    for entry in app.operations.active() {
        lines.push(Line::styled(
            format!("  {}", entry.animated_label()),
            Style::default().fg(Color::Gray),
        ));
        lines.push(Line::from(""));
    }
    let visible = area.height.saturating_sub(2) as usize;
    let bottom = lines.len().saturating_sub(visible) as u16;
    let scroll = bottom.saturating_sub(app.transcript_scroll.min(bottom));
    let transcript = Paragraph::new(Text::from(lines))
        .scroll((scroll, 0))
        .wrap(Wrap { trim: false })
        .block(
            Block::default()
                .borders(Borders::ALL)
                .border_style(Style::default().fg(PANEL))
                .title(" Shared transcript "),
        );
    frame.render_widget(transcript, area);
}

fn render_editor(frame: &mut Frame<'_>, area: Rect, app: &App) {
    if let Some(search) = app.canvas_search_editor() {
        let status = match app.canvas_search_summary() {
            Some(summary) if summary.total > 0 => format!(
                "{} of {} matches",
                summary.current.unwrap_or(0),
                summary.total
            ),
            Some(_) => "0 matches".to_owned(),
            None => "type to search visible lines".to_owned(),
        };
        let block = Block::default()
            .borders(Borders::TOP)
            .border_style(Style::default().fg(PINK))
            .padding(Padding::horizontal(1))
            .title(format!(" Search › {status} · Enter keep · Esc cancel "));
        let inner = block.inner(area);
        frame.render_widget(
            Paragraph::new(format!("/{}", search.text()))
                .style(Style::default().fg(Color::White))
                .wrap(Wrap { trim: false })
                .block(block),
            area,
        );
        let (column, row) = search.visual_cursor(inner.width.saturating_sub(1) as usize);
        let cursor_x = inner
            .x
            .saturating_add(1)
            .saturating_add(column.min(inner.width.saturating_sub(2)));
        let cursor_y = inner
            .y
            .saturating_add(row.min(inner.height.saturating_sub(1)));
        frame.set_cursor_position((cursor_x, cursor_y));
        return;
    }
    if app.canvas_navigating() {
        let block = Block::default()
            .borders(Borders::TOP)
            .border_style(Style::default().fg(PINK))
            .padding(Padding::horizontal(1))
            .title(
                " Navigate › ↑/↓ j/k select · Enter expand/page · o card · / search · n/N matches · ←/→ collapse/expand · Esc/q prompt ",
            );
        frame.render_widget(
            Paragraph::new(app.editor.text())
                .style(Style::default().fg(MUTED))
                .wrap(Wrap { trim: false })
                .block(block),
            area,
        );
        return;
    }
    let block = Block::default()
        .borders(Borders::TOP)
        .border_style(Style::default().fg(CYAN))
        .padding(Padding::horizontal(1))
        .title(format!(
            " {} ›  {} ",
            app.prompt_label(),
            if app.completion().is_some() {
                "Completion · Tab/↓ next · Shift-Tab/↑ previous · Enter accept · Esc close"
            } else {
                "Enter send · Alt+Enter newline · Ctrl-D exit"
            }
        ));
    let inner = block.inner(area);
    frame.render_widget(
        Paragraph::new(app.editor.text())
            .style(Style::default().fg(Color::White))
            .wrap(Wrap { trim: false })
            .block(block),
        area,
    );
    let (column, row) = app.editor.visual_cursor(inner.width as usize);
    let cursor_x = inner
        .x
        .saturating_add(column.min(inner.width.saturating_sub(1)));
    let cursor_y = inner
        .y
        .saturating_add(row.min(inner.height.saturating_sub(1)));
    frame.set_cursor_position((cursor_x, cursor_y));
}

fn render_completion(frame: &mut Frame<'_>, area: Rect, completion: &CompletionMenu) {
    let visible = area.height.saturating_sub(2) as usize;
    let offset = completion
        .selected()
        .saturating_sub(visible.saturating_sub(1))
        .min(completion.candidates().len().saturating_sub(visible));
    let lines = completion
        .candidates()
        .iter()
        .enumerate()
        .skip(offset)
        .take(visible)
        .map(|(index, candidate)| {
            let selected = index == completion.selected();
            Line::from(vec![
                Span::styled(
                    if selected { "› " } else { "  " },
                    Style::default().fg(if selected { PINK } else { MUTED }),
                ),
                Span::styled(
                    &candidate.label,
                    if selected {
                        Style::default()
                            .fg(Color::White)
                            .bg(PANEL)
                            .add_modifier(Modifier::BOLD)
                    } else {
                        Style::default().fg(CYAN)
                    },
                ),
                Span::styled(
                    format!("  {}", candidate.detail),
                    Style::default().fg(MUTED),
                ),
            ])
        })
        .collect::<Vec<_>>();
    frame.render_widget(
        Paragraph::new(lines).block(
            Block::default()
                .borders(Borders::ALL)
                .border_style(Style::default().fg(PANEL))
                .title(format!(
                    " Completion · {} match{} ",
                    completion.candidates().len(),
                    if completion.candidates().len() == 1 {
                        ""
                    } else {
                        "es"
                    }
                )),
        ),
        area,
    );
}

fn render_canvas_card(frame: &mut Frame<'_>, area: Rect, card: &PresentationCard) {
    let mut lines = vec![
        Line::styled(
            &card.title,
            Style::default()
                .fg(Color::White)
                .add_modifier(Modifier::BOLD),
        ),
        Line::styled(&card.kind, Style::default().fg(MUTED)),
        Line::styled(&card.path, Style::default().fg(CYAN)),
        Line::from(""),
    ];
    for field in &card.fields {
        lines.push(Line::from(vec![
            Span::styled(
                format!("{}: ", field.label),
                Style::default().fg(PINK).add_modifier(Modifier::BOLD),
            ),
            Span::styled(&field.value, Style::default().fg(Color::Gray)),
        ]));
    }
    if !card.actions.is_empty() {
        lines.push(Line::from(""));
        lines.push(Line::styled(
            "Actions",
            Style::default()
                .fg(Color::White)
                .add_modifier(Modifier::BOLD),
        ));
        for action in &card.actions {
            lines.push(Line::styled(
                format!("  {action}"),
                Style::default().fg(CYAN),
            ));
        }
    }
    frame.render_widget(
        Paragraph::new(lines).wrap(Wrap { trim: false }).block(
            Block::default()
                .borders(Borders::ALL)
                .border_style(Style::default().fg(PANEL))
                .title(" Card "),
        ),
        area,
    );
}

fn render_library_footer(frame: &mut Frame<'_>, area: Rect) {
    frame.render_widget(
        Paragraph::new(Line::from(vec![
            Span::styled(" ↑/↓", Style::default().fg(CYAN)),
            Span::raw(" select  "),
            Span::styled("Enter", Style::default().fg(CYAN)),
            Span::raw(" open/switch  "),
            Span::styled("wheel/click", Style::default().fg(CYAN)),
            Span::raw(" browse  "),
            Span::styled("PgUp/PgDn", Style::default().fg(CYAN)),
            Span::raw(" jump  "),
            Span::styled("Esc/q", Style::default().fg(CYAN)),
            Span::raw(" shell"),
        ]))
        .alignment(Alignment::Center),
        area,
    );
}

#[cfg(test)]
mod tests {
    use super::{GREEN, PANEL, PINK, draw};
    use crate::app::{App, TranscriptEntry};
    use crate::backend::BackendEvent;
    use crate::command::ShellCommand;
    use crate::library::{DatabaseSummary, LibraryView, RelationSummary};
    use crate::protocol::Response;
    use crossterm::event::{Event, KeyCode, KeyEvent, KeyModifiers};
    use ratatui::Terminal;
    use ratatui::backend::TestBackend;
    use ratatui::style::Color;

    fn find_text(terminal: &Terminal<TestBackend>, needle: &str) -> Option<(u16, u16)> {
        let buffer = terminal.backend().buffer();
        for y in 0..buffer.area.height {
            for x in 0..buffer.area.width {
                let tail = (x..buffer.area.width)
                    .map(|column| buffer.cell((column, y)).expect("buffer cell").symbol())
                    .collect::<String>();
                if tail.starts_with(needle) {
                    return Some((x, y));
                }
            }
        }
        None
    }

    #[test]
    fn welcome_renders_to_a_test_buffer() {
        let backend = TestBackend::new(100, 30);
        let mut terminal = Terminal::new(backend).expect("test terminal");
        let mut app = App::new();
        app.set_coauthor_info(
            "127.0.0.1:3210".to_owned(),
            "/tmp/slog-repl/example.json".to_owned(),
        );
        terminal
            .draw(|frame| draw(frame, &app))
            .expect("draw welcome");
        let rendered = terminal.backend().to_string();
        assert!(rendered.contains("Symbolic-expression logic programming"));
        assert!(rendered.contains("Enter send · Alt+Enter newline · Ctrl-D exit"));
        assert!(!rendered.contains("Shift"));
        assert!(!rendered.contains(":demo"));
        assert!(!rendered.contains("F1"));
        assert!(!rendered.contains("PgUp/PgDn"));
        assert!(!rendered.contains("private TCP"));
        assert!(!rendered.contains("ratatui/crossterm"));

        let (_, help_y) = find_text(&terminal, ":help for commands").expect("help suggestion");
        let (_, endpoint_y) = find_text(&terminal, "127.0.0.1:3210").expect("endpoint");
        let (_, share_y) = find_text(&terminal, ":share").expect("share command");
        assert_eq!(help_y, endpoint_y);
        assert_eq!(help_y, share_y);

        let (body_x, _) = find_text(&terminal, "/____/_/").expect("logo body");
        let (descender_x, _) = find_text(&terminal, "/____/  v").expect("logo descender");
        assert_eq!(descender_x, body_x + 13);
        let (_, editor_y) = find_text(&terminal, "slog ›").expect("editor title");
        assert_eq!(editor_y, 25, "the five-row editor starts at row 25");
    }

    #[test]
    fn completion_menu_renders_candidates_and_editor_controls() {
        let backend = TestBackend::new(100, 28);
        let mut terminal = Terminal::new(backend).expect("test terminal");
        let mut app = App::new();
        app.editor.insert("mode ");
        app.on_terminal(Event::Key(KeyEvent::new(KeyCode::Tab, KeyModifiers::NONE)));
        terminal
            .draw(|frame| draw(frame, &app))
            .expect("draw completion");

        let rendered = terminal.backend().to_string();
        assert!(rendered.contains("Completion · 2 matches"));
        assert!(rendered.contains("mutable"));
        assert!(rendered.contains("readonly"));
        assert!(rendered.contains("Tab/↓ next"));
        assert!(rendered.contains("Enter accept"));
        assert!(!rendered.contains("Enter send · Alt+Enter"));
        let (selected_x, selected_y) =
            find_text(&terminal, "mutable").expect("selected completion");
        assert_eq!(
            terminal
                .backend()
                .buffer()
                .cell((selected_x, selected_y))
                .expect("selected candidate")
                .bg,
            PANEL
        );
    }

    #[test]
    fn incremental_search_renders_match_status_and_visible_highlights() {
        let backend = TestBackend::new(110, 30);
        let mut terminal = Terminal::new(backend).expect("test terminal");
        let mut app = App::new();
        app.on_backend(BackendEvent::Response {
            command: "add edge 4 5".to_owned(),
            response: Response {
                id: 9,
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
        for key in [
            KeyCode::Tab,
            KeyCode::End,
            KeyCode::Enter,
            KeyCode::Char('/'),
        ] {
            app.on_terminal(Event::Key(KeyEvent::new(key, KeyModifiers::NONE)));
        }
        for character in "settled".chars() {
            app.on_terminal(Event::Key(KeyEvent::new(
                KeyCode::Char(character),
                KeyModifiers::NONE,
            )));
        }
        terminal
            .draw(|frame| draw(frame, &app))
            .expect("draw search");

        let rendered = terminal.backend().to_string();
        assert!(rendered.contains("Search › 2 of 2 matches"));
        assert!(rendered.contains("/settled"));
        assert!(rendered.contains("Enter keep"));
        assert!(rendered.contains("Esc cancel"));
        assert!(!rendered.contains("Navigate ›"));
        let (match_x, match_y) = find_text(&terminal, "settled").expect("visible match");
        assert_eq!(
            terminal
                .backend()
                .buffer()
                .cell((match_x, match_y))
                .expect("highlighted match")
                .fg,
            PINK
        );
    }

    #[test]
    fn live_relation_card_renders_schema_observation_and_actions() {
        let backend = TestBackend::new(110, 30);
        let mut terminal = Terminal::new(backend).expect("test terminal");
        let mut app = App::new();
        app.on_backend(BackendEvent::Response {
            command: "tables".to_owned(),
            response: Response {
                id: 10,
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
        for key in [
            KeyCode::Tab,
            KeyCode::End,
            KeyCode::Enter,
            KeyCode::Down,
            KeyCode::Char('o'),
        ] {
            app.on_terminal(Event::Key(KeyEvent::new(key, KeyModifiers::NONE)));
        }
        terminal
            .draw(|frame| draw(frame, &app))
            .expect("draw relation card");

        let rendered = terminal.backend().to_string();
        assert!(rendered.contains("live relation observation"));
        assert!(rendered.contains("name: edge"));
        assert!(rendered.contains("schema detail: Int Int"));
        assert!(rendered.contains("BoundaryKey"));
        assert!(rendered.contains("count edge"));
        assert!(rendered.contains("show edge"));
        assert!(rendered.contains("state edge"));
    }

    #[test]
    fn buffered_page_markers_render_honest_ranges_and_navigation_help() {
        let backend = TestBackend::new(100, 32);
        let mut terminal = Terminal::new(backend).expect("test terminal");
        let mut app = App::new();
        let lines = (1..=22).map(|row| format!("row {row}")).collect::<Vec<_>>();
        app.on_backend(BackendEvent::Response {
            command: "show edge all".to_owned(),
            response: Response {
                id: 12,
                ok: true,
                result: Some(serde_json::json!({
                    "kind": "query",
                    "title": "Rows · edge",
                    "lines": lines
                })),
                error: None,
            },
        });
        app.on_terminal(Event::Key(KeyEvent::new(KeyCode::Tab, KeyModifiers::NONE)));
        terminal
            .draw(|frame| draw(frame, &app))
            .expect("draw first page");
        let rendered = terminal.backend().to_string();
        assert!(rendered.contains("▸ … 2 more · page 1/2"));
        assert!(rendered.contains("Enter expand/page"));

        app.on_terminal(Event::Key(KeyEvent::new(KeyCode::End, KeyModifiers::NONE)));
        app.on_terminal(Event::Key(KeyEvent::new(
            KeyCode::Enter,
            KeyModifiers::NONE,
        )));
        terminal
            .draw(|frame| draw(frame, &app))
            .expect("draw second page");
        let rendered = terminal.backend().to_string();
        assert!(rendered.contains("◂ 20 before · page 2/2"));
        assert!(rendered.contains("row 21"));
        assert!(rendered.contains("row 22"));
        assert!(rendered.contains("page it 2"));
    }

    #[test]
    fn library_opens_a_contextual_database_summary() {
        let backend = TestBackend::new(120, 32);
        let mut terminal = Terminal::new(backend).expect("test terminal");
        let mut app = App::new();
        app.library = Some(LibraryView::new(vec![DatabaseSummary {
            name: "example".to_owned(),
            kind: "plain".to_owned(),
            managed: false,
            facts: 3,
            stored_facts: 3,
            bytes: 48,
            size: "48B".to_owned(),
            relation_count: 1,
            table_count: 1,
            struct_count: 0,
            lattice_count: 0,
            inputs: Vec::new(),
            stale: Vec::new(),
            per: None,
            relations: vec![RelationSummary {
                name: "edge".to_owned(),
                kind: "table".to_owned(),
                arity: 2,
                detail: None,
                facts: 3,
                stored_facts: 3,
                count_source: "stored".to_owned(),
            }],
        }]));
        terminal
            .draw(|frame| draw(frame, &app))
            .expect("draw library");
        let rendered = terminal.backend().to_string();
        assert!(rendered.contains("Library · data/"));
        assert!(rendered.contains("Database summary"));
        assert!(rendered.contains("edge/2"));
    }

    #[test]
    fn generated_library_command_is_rendered_dim() {
        let backend = TestBackend::new(80, 24);
        let mut terminal = Terminal::new(backend).expect("test terminal");
        let mut app = App::new();
        app.transcript.push(TranscriptEntry::command(
            ShellCommand::coauthor("codex", "open example").expect("command"),
            "b0smoke",
        ));
        terminal
            .draw(|frame| draw(frame, &app))
            .expect("draw generated command");

        let buffer = terminal.backend().buffer();
        let mut found = false;
        for y in 0..buffer.area.height {
            let row = (0..buffer.area.width)
                .map(|x| buffer.cell((x, y)).expect("buffer cell").symbol())
                .collect::<String>();
            if let Some(x) = row.find("open example") {
                assert_eq!(
                    buffer.cell((x as u16, y)).expect("command cell").fg,
                    Color::DarkGray
                );
                found = true;
                break;
            }
        }
        assert!(found, "generated command was not rendered");
        let rendered = terminal.backend().to_string();
        assert!(rendered.contains("open example  — codex"));
        assert!(!rendered.contains("b0smoke · codex"));
    }

    #[test]
    fn database_workflow_animates_then_commits_as_a_green_result() {
        let backend = TestBackend::new(80, 24);
        let mut terminal = Terminal::new(backend).expect("test terminal");
        let mut app = App::new();
        app.transcript.push(TranscriptEntry::command(
            ShellCommand::generated("open example").expect("command"),
            "slog",
        ));
        let command = ShellCommand::generated("open example").expect("command");
        app.begin_operation(&command, false);
        terminal
            .draw(|frame| draw(frame, &app))
            .expect("draw loading workflow");

        let (loading_x, loading_y) =
            find_text(&terminal, "Loading database `example`.").expect("loading label");
        assert_eq!(
            terminal
                .backend()
                .buffer()
                .cell((loading_x.saturating_sub(1), loading_y))
                .expect("loading indent")
                .symbol(),
            " "
        );
        assert_eq!(
            terminal
                .backend()
                .buffer()
                .cell((loading_x, loading_y))
                .expect("loading cell")
                .fg,
            Color::Gray
        );

        app.on_backend(BackendEvent::Response {
            command: "open example".to_owned(),
            response: Response {
                id: 1,
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
        terminal
            .draw(|frame| draw(frame, &app))
            .expect("draw committed workflow");
        assert!(find_text(&terminal, "Loading database").is_none());
        let (loaded_x, loaded_y) =
            find_text(&terminal, "Loaded database `example`").expect("committed label");
        assert_eq!(
            terminal
                .backend()
                .buffer()
                .cell((loaded_x, loaded_y))
                .expect("loaded cell")
                .fg,
            GREEN
        );
    }

    #[test]
    fn navigate_mode_highlights_the_live_canvas_and_replaces_the_editor_footer() {
        let backend = TestBackend::new(100, 28);
        let mut terminal = Terminal::new(backend).expect("test terminal");
        let mut app = App::new();
        app.on_backend(BackendEvent::Response {
            command: "add edge 4 5".to_owned(),
            response: Response {
                id: 8,
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
        app.on_terminal(Event::Key(KeyEvent::new(KeyCode::Tab, KeyModifiers::NONE)));
        app.on_terminal(Event::Key(KeyEvent::new(KeyCode::End, KeyModifiers::NONE)));
        app.on_terminal(Event::Key(KeyEvent::new(
            KeyCode::Char('o'),
            KeyModifiers::NONE,
        )));
        terminal
            .draw(|frame| draw(frame, &app))
            .expect("draw navigate mode");

        let rendered = terminal.backend().to_string();
        assert!(rendered.contains("Navigate ›"));
        assert!(rendered.contains("Enter expand/page"));
        assert!(rendered.contains("o card"));
        assert!(!rendered.contains("Enter send"));
        assert!(rendered.contains("semantic change"));
        assert!(rendered.contains("operation: add"));
        assert!(rendered.contains("expand it.change"));
        assert!(rendered.contains("card close"));
        let (marker_x, marker_y) = find_text(&terminal, "▸ Change details").expect("change marker");
        assert_eq!(
            terminal
                .backend()
                .buffer()
                .cell((marker_x, marker_y))
                .expect("selected marker")
                .bg,
            PANEL
        );
        assert_eq!(
            terminal
                .backend()
                .buffer()
                .cell((marker_x.saturating_sub(2), marker_y))
                .expect("selection cursor")
                .symbol(),
            "›"
        );
    }
}
