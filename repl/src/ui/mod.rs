mod library;

use crate::app::{App, Demo, EntryKind};
use crate::version;
use ratatui::Frame;
use ratatui::layout::{Alignment, Constraint, Layout, Rect};
use ratatui::style::{Color, Modifier, Style};
use ratatui::text::{Line, Span, Text};
use ratatui::widgets::{Block, Borders, Gauge, Padding, Paragraph, Row, Table, Wrap};

const CYAN: Color = Color::Rgb(62, 207, 227);
const PINK: Color = Color::Rgb(244, 114, 182);
const GREEN: Color = Color::Rgb(74, 222, 128);
const AMBER: Color = Color::Rgb(251, 191, 36);
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
    let sections = Layout::vertical([
        Constraint::Min(8),
        Constraint::Length(4),
        Constraint::Length(1),
    ])
    .split(area);
    render_body(frame, sections[0], app);
    render_editor(frame, sections[1], app);
    render_footer(frame, sections[2]);
}

fn render_body(frame: &mut Frame<'_>, area: Rect, app: &App) {
    render_primary(frame, area, app);
}

fn render_primary(frame: &mut Frame<'_>, area: Rect, app: &App) {
    match app.demo {
        Demo::Welcome if app.transcript.len() <= 1 => render_splash(frame, area, app),
        Demo::Welcome => render_transcript(frame, area, app),
        Demo::Colors => render_colors(frame, area),
        Demo::Layout => render_layout_demo(frame, area),
        Demo::Unicode => render_unicode(frame, area),
    }
}

fn render_splash(frame: &mut Frame<'_>, area: Rect, app: &App) {
    let art = [
        "       _____ __           ".to_owned(),
        "      / ___// /___  ____ _".to_owned(),
        "      \\__ \\/ / __ \\/ __ `/".to_owned(),
        "     ___/ / / /_/ / /_/ / ".to_owned(),
        "    /____/_/\\____/\\__, /  ".to_owned(),
        format!("                 /____/  v{}", version::current()),
    ];
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
            Span::styled("help", Style::default().fg(CYAN)),
            Span::raw(" for server commands  ·  "),
            Span::styled(":demo colors", Style::default().fg(PINK)),
            Span::raw(" for the UI gallery"),
        ]),
    ]);
    if let Some(endpoint) = &app.coauthor_endpoint {
        lines.extend([
            Line::from(""),
            Line::from(vec![
                Span::styled("co-author", Style::default().fg(MUTED)),
                Span::raw("  "),
                Span::styled(endpoint, Style::default().fg(CYAN)),
                Span::raw("  ·  "),
                Span::styled(":share", Style::default().fg(PINK)),
                Span::raw(" for connection details"),
            ]),
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
    for entry in &app.transcript {
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
        for line in &entry.lines {
            lines.push(Line::styled(
                format!("  {line}"),
                Style::default().fg(Color::Gray),
            ));
        }
        lines.push(Line::from(""));
    }
    for entry in &app.transient {
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

fn render_colors(frame: &mut Frame<'_>, area: Rect) {
    let colors = [
        ("compiler", Color::Rgb(62, 207, 227)),
        ("daemon", Color::Rgb(74, 222, 128)),
        ("warning", Color::Rgb(251, 191, 36)),
        ("error", Color::Rgb(248, 113, 113)),
        ("handle", Color::Rgb(192, 132, 252)),
        ("value", Color::Rgb(244, 114, 182)),
    ];
    let mut lines = vec![Line::styled(
        "True-color semantic palette",
        Style::default().add_modifier(Modifier::BOLD),
    )];
    lines.push(Line::from(""));
    for (name, color) in colors {
        lines.push(Line::from(vec![
            Span::styled("      ", Style::default().bg(color)),
            Span::raw("  "),
            Span::styled(format!("{name:<12}"), Style::default().fg(color)),
            Span::styled(
                " bold ",
                Style::default().fg(color).add_modifier(Modifier::BOLD),
            ),
            Span::styled(
                " underline ",
                Style::default()
                    .fg(color)
                    .add_modifier(Modifier::UNDERLINED),
            ),
        ]));
    }
    lines.extend([
        Line::from(""),
        Line::from(vec![
            Span::styled("●", Style::default().fg(GREEN)),
            Span::raw(" ready   "),
            Span::styled("◌", Style::default().fg(AMBER)),
            Span::raw(" compiling   "),
            Span::styled("◆", Style::default().fg(CYAN)),
            Span::raw(" committed"),
        ]),
    ]);
    frame.render_widget(
        Paragraph::new(lines).block(
            Block::default()
                .borders(Borders::ALL)
                .border_style(Style::default().fg(PINK))
                .title(" :demo colors "),
        ),
        area,
    );
}

fn render_layout_demo(frame: &mut Frame<'_>, area: Rect) {
    let rows = Layout::vertical([
        Constraint::Length(5),
        Constraint::Length(5),
        Constraint::Min(5),
    ])
    .split(area);
    frame.render_widget(
        Gauge::default()
            .block(
                Block::default()
                    .borders(Borders::ALL)
                    .title(" Compile cache "),
            )
            .gauge_style(Style::default().fg(CYAN).bg(PANEL))
            .percent(72)
            .label("72% warm"),
        rows[0],
    );
    frame.render_widget(
        Gauge::default()
            .block(Block::default().borders(Borders::ALL).title(" Fixpoint "))
            .gauge_style(Style::default().fg(GREEN).bg(PANEL))
            .ratio(0.43)
            .label("stratum 3 · iteration 12"),
        rows[1],
    );
    let table = Table::new(
        [
            Row::new(["edge", "table", "3", "db1"]),
            Row::new(["path", "table", "6", "db2"]),
            Row::new(["distance", "min lattice", "4", "db2"]),
        ],
        [
            Constraint::Percentage(30),
            Constraint::Percentage(30),
            Constraint::Percentage(20),
            Constraint::Percentage(20),
        ],
    )
    .header(
        Row::new(["relation", "kind", "rows", "boundary"])
            .style(Style::default().fg(PINK).add_modifier(Modifier::BOLD)),
    )
    .block(
        Block::default()
            .borders(Borders::ALL)
            .title(" Catalog table "),
    );
    frame.render_widget(table, rows[2]);
}

fn render_unicode(frame: &mut Frame<'_>, area: Rect) {
    let lines = vec![
        Line::styled(
            "Grapheme-aware editor and cell-width samples",
            Style::default().add_modifier(Modifier::BOLD),
        ),
        Line::from(""),
        Line::from("ASCII fallback       ->  [run] [pause] [commit]"),
        Line::from("Unicode markers      →   ▸ run  ⏸ pause  ◆ commit"),
        Line::from("Combining grapheme   →   e\u{301}  a\u{30a}  n\u{303}"),
        Line::from("Wide cells           →   測試  解析  論理"),
        Line::from("Emoji cluster        →   👩‍💻  🧑🏽‍🔬  🦀"),
        Line::from("Box drawing          →   ┌────┬────┐  ╭────╮"),
        Line::from(""),
        Line::styled(
            "Backspace in the editor removes one extended grapheme cluster.",
            Style::default().fg(MUTED),
        ),
        Line::styled(
            "Display width is measured independently from UTF-8 byte length.",
            Style::default().fg(MUTED),
        ),
    ];
    frame.render_widget(
        Paragraph::new(lines).wrap(Wrap { trim: false }).block(
            Block::default()
                .borders(Borders::ALL)
                .border_style(Style::default().fg(CYAN))
                .title(" :demo unicode "),
        ),
        area,
    );
}

fn render_editor(frame: &mut Frame<'_>, area: Rect, app: &App) {
    let block = Block::default()
        .borders(Borders::TOP)
        .border_style(Style::default().fg(CYAN))
        .padding(Padding::horizontal(1))
        .title(format!(
            " {} ›  Enter send · Shift/Alt+Enter newline ",
            app.prompt_label()
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

fn render_footer(frame: &mut Frame<'_>, area: Rect) {
    frame.render_widget(
        Paragraph::new(Line::from(vec![
            Span::styled(" F1", Style::default().fg(CYAN)),
            Span::raw(" help  "),
            Span::styled("F2", Style::default().fg(CYAN)),
            Span::raw(" cycle demos  "),
            Span::styled("PgUp/PgDn", Style::default().fg(CYAN)),
            Span::raw(" transcript  "),
            Span::styled("Esc", Style::default().fg(CYAN)),
            Span::raw(" welcome  "),
            Span::styled("Ctrl-C/D", Style::default().fg(CYAN)),
            Span::raw(" exit"),
        ]))
        .alignment(Alignment::Center),
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
    use super::{GREEN, draw};
    use crate::app::{App, EntryKind, TranscriptEntry};
    use crate::backend::BackendEvent;
    use crate::library::{DatabaseSummary, LibraryView, RelationSummary};
    use crate::protocol::Response;
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
        terminal
            .draw(|frame| draw(frame, &App::new()))
            .expect("draw welcome");
        let rendered = terminal.backend().to_string();
        assert!(rendered.contains("Symbolic-expression logic programming"));
        assert!(rendered.contains("Enter send"));
        assert!(!rendered.contains("private TCP"));
        assert!(!rendered.contains("ratatui/crossterm"));
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
        app.transcript.push(TranscriptEntry {
            kind: EntryKind::GeneratedCommand,
            title: "b0smoke".to_owned(),
            lines: vec!["open example".to_owned()],
            actor: Some("codex".to_owned()),
        });
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
        app.transcript.push(TranscriptEntry {
            kind: EntryKind::GeneratedCommand,
            title: "slog".to_owned(),
            lines: vec!["open example".to_owned()],
            actor: None,
        });
        app.begin_operation("open example", false);
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
}
