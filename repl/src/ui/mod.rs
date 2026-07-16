use crate::app::{App, Demo, EntryKind};
use ratatui::Frame;
use ratatui::layout::{Alignment, Constraint, Layout, Rect};
use ratatui::style::{Color, Modifier, Style};
use ratatui::text::{Line, Span, Text};
use ratatui::widgets::{Block, Borders, Gauge, Paragraph, Row, Table, Wrap};

const CYAN: Color = Color::Rgb(62, 207, 227);
const BLUE: Color = Color::Rgb(80, 120, 255);
const PINK: Color = Color::Rgb(244, 114, 182);
const GREEN: Color = Color::Rgb(74, 222, 128);
const AMBER: Color = Color::Rgb(251, 191, 36);
const MUTED: Color = Color::Rgb(124, 139, 161);
const PANEL: Color = Color::Rgb(30, 36, 50);

pub fn draw(frame: &mut Frame<'_>, app: &App) {
    let area = frame.area();
    let sections = Layout::vertical([
        Constraint::Length(3),
        Constraint::Min(8),
        Constraint::Length(5),
        Constraint::Length(1),
    ])
    .split(area);
    render_header(frame, sections[0], app);
    render_body(frame, sections[1], app);
    render_editor(frame, sections[2], app);
    render_footer(frame, sections[3]);
}

fn render_header(frame: &mut Frame<'_>, area: Rect, app: &App) {
    let busy = if app.busy == 0 {
        Span::styled("● ready", Style::default().fg(GREEN))
    } else {
        Span::styled(
            format!("◌ {} request(s)", app.busy),
            Style::default().fg(AMBER),
        )
    };
    let header = Paragraph::new(Line::from(vec![
        Span::styled(
            " SLOG ",
            Style::default()
                .fg(Color::Black)
                .bg(CYAN)
                .add_modifier(Modifier::BOLD),
        ),
        Span::styled(
            "  native logic workbench  ",
            Style::default().fg(Color::White),
        ),
        busy,
    ]))
    .block(
        Block::default()
            .borders(Borders::ALL)
            .border_style(Style::default().fg(BLUE))
            .title(" Rust ↔ private TCP ↔ Racket ↔ slogd "),
    );
    frame.render_widget(header, area);
}

fn render_body(frame: &mut Frame<'_>, area: Rect, app: &App) {
    if area.width >= 84 {
        let columns = Layout::horizontal([Constraint::Percentage(72), Constraint::Percentage(28)])
            .split(area);
        render_primary(frame, columns[0], app);
        render_sidebar(frame, columns[1], app);
    } else {
        render_primary(frame, area, app);
    }
}

fn render_primary(frame: &mut Frame<'_>, area: Rect, app: &App) {
    match app.demo {
        Demo::Welcome if app.transcript.len() <= 1 => render_splash(frame, area),
        Demo::Welcome => render_transcript(frame, area, app),
        Demo::Colors => render_colors(frame, area),
        Demo::Layout => render_layout_demo(frame, area),
        Demo::Unicode => render_unicode(frame, area),
    }
}

fn render_splash(frame: &mut Frame<'_>, area: Rect) {
    let art = [
        "       _____ __           ",
        "      / ___// /___  ____ _",
        "      \\__ \\/ / __ \\/ __ `/",
        "     ___/ / / /_/ / /_/ / ",
        "    /____/_/\\____/\\__, /  ",
        "                 /____/  v2.0.0",
    ];
    let mut lines = vec![Line::from("")];
    for (index, line) in art.iter().enumerate() {
        let color = Color::Rgb(45 + index as u8 * 16, 180 + index as u8 * 8, 230);
        lines.push(Line::styled(*line, Style::default().fg(color)));
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
        let (prefix, color) = match entry.kind {
            EntryKind::Command => ("›", CYAN),
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
                .title(" Session transcript "),
        );
    frame.render_widget(transcript, area);
}

fn render_sidebar(frame: &mut Frame<'_>, area: Rect, app: &App) {
    let lines = vec![
        Line::from(vec![
            Span::styled("daemon  ", Style::default().fg(MUTED)),
            Span::styled(
                &app.daemon,
                Style::default().fg(if app.daemon == "ready" { GREEN } else { AMBER }),
            ),
        ]),
        Line::from(vec![
            Span::styled("client  ", Style::default().fg(MUTED)),
            Span::styled("ratatui/crossterm", Style::default().fg(CYAN)),
        ]),
        Line::from(""),
        Line::styled(
            "SERVER",
            Style::default().fg(PINK).add_modifier(Modifier::BOLD),
        ),
        Line::from("help · status · ping"),
        Line::from("run · open · schema"),
        Line::from("pipeline · save · quit"),
        Line::from(""),
        Line::styled(
            "CLIENT",
            Style::default().fg(PINK).add_modifier(Modifier::BOLD),
        ),
        Line::from(":demo colors"),
        Line::from(":demo layout"),
        Line::from(":demo unicode"),
        Line::from(":clear"),
        Line::from(""),
        Line::styled("The first semantic command", Style::default().fg(MUTED)),
        Line::styled("starts the persistent daemon.", Style::default().fg(MUTED)),
    ];
    frame.render_widget(
        Paragraph::new(lines).wrap(Wrap { trim: false }).block(
            Block::default()
                .borders(Borders::ALL)
                .border_style(Style::default().fg(PANEL))
                .title(" Session "),
        ),
        area,
    );
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
        .borders(Borders::ALL)
        .border_style(Style::default().fg(CYAN))
        .title(" slog ›  Enter send · Shift/Alt+Enter newline ");
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

#[cfg(test)]
mod tests {
    use super::draw;
    use crate::app::App;
    use ratatui::Terminal;
    use ratatui::backend::TestBackend;

    #[test]
    fn welcome_renders_to_a_test_buffer() {
        let backend = TestBackend::new(100, 30);
        let mut terminal = Terminal::new(backend).expect("test terminal");
        terminal
            .draw(|frame| draw(frame, &App::new()))
            .expect("draw welcome");
        let rendered = terminal.backend().to_string();
        assert!(rendered.contains("SLOG"));
        assert!(rendered.contains("native logic workbench"));
    }
}
