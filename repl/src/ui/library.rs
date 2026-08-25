use crate::app::SessionSummary;
use crate::library::{DatabaseSummary, LibraryView};
use crate::theme::Theme;
use ratatui::Frame;
use ratatui::layout::{Constraint, Layout, Rect};
use ratatui::style::{Modifier, Style};
use ratatui::text::{Line, Span};
use ratatui::widgets::{Block, Borders, Cell, Paragraph, Row, Table, Wrap};

pub fn render(
    frame: &mut Frame<'_>,
    area: Rect,
    library: &LibraryView,
    sessions: &[SessionSummary],
    theme: &Theme,
) {
    if area.width >= 76 {
        let columns = Layout::horizontal([Constraint::Percentage(72), Constraint::Percentage(28)])
            .split(area);
        render_list(frame, columns[0], library, sessions, theme);
        render_summary(frame, columns[1], library.current(), sessions, theme);
    } else {
        render_list(frame, area, library, sessions, theme);
    }
}

fn render_list(
    frame: &mut Frame<'_>,
    area: Rect,
    library: &LibraryView,
    sessions: &[SessionSummary],
    theme: &Theme,
) {
    let visible_rows = area.height.saturating_sub(3) as usize;
    let offset = library.visible_offset(visible_rows);
    let detailed = area.width >= 72;
    let rows = library
        .databases
        .iter()
        .enumerate()
        .skip(offset)
        .take(visible_rows)
        .map(|(index, database)| {
            let selected = index == library.selected;
            let session = session_for(sessions, &database.name);
            let mut cells = vec![
                Cell::from(if selected { "›" } else { "" }),
                Cell::from(Line::from(vec![
                    Span::styled(
                        match session {
                            Some(session) if session.current => "● ",
                            Some(_) => "○ ",
                            None => "  ",
                        },
                        Style::default().fg(if session.is_some() {
                            theme.success
                        } else {
                            theme.muted
                        }),
                    ),
                    Span::raw(database.name.clone()),
                ])),
                Cell::from(format_count(database.facts)),
                Cell::from(database.size.clone()),
            ];
            if detailed {
                cells.insert(2, Cell::from(database.kind.clone()));
                cells.push(Cell::from(database.relation_count.to_string()));
            }
            Row::new(cells).style(if selected {
                Style::default()
                    .fg(theme.on_accent)
                    .bg(theme.accent)
                    .add_modifier(Modifier::BOLD)
            } else {
                Style::default().fg(theme.body)
            })
        });
    let (headings, widths) = if detailed {
        (
            vec!["", "database", "kind", "facts", "disk", "schema"],
            vec![
                Constraint::Length(2),
                Constraint::Min(18),
                Constraint::Length(12),
                Constraint::Length(10),
                Constraint::Length(9),
                Constraint::Length(6),
            ],
        )
    } else {
        (
            vec!["", "database", "facts", "disk"],
            vec![
                Constraint::Length(2),
                Constraint::Min(16),
                Constraint::Length(10),
                Constraint::Length(8),
            ],
        )
    };
    let table = Table::new(rows, widths)
        .header(
            Row::new(headings).style(
                Style::default()
                    .fg(theme.highlight)
                    .add_modifier(Modifier::BOLD),
            ),
        )
        .column_spacing(1)
        .block(
            Block::default()
                .borders(Borders::ALL)
                .border_style(Style::default().fg(theme.panel))
                .title(format!(
                    " Library · data/ · {} databases ",
                    library.databases.len()
                )),
        );
    frame.render_widget(table, area);
}

fn render_summary(
    frame: &mut Frame<'_>,
    area: Rect,
    database: Option<&DatabaseSummary>,
    sessions: &[SessionSummary],
    theme: &Theme,
) {
    let Some(database) = database else {
        frame.render_widget(
            Paragraph::new("No databases under data/").block(
                Block::default()
                    .borders(Borders::ALL)
                    .border_style(Style::default().fg(theme.panel))
                    .title(" Database "),
            ),
            area,
        );
        return;
    };

    let compact = area.width < 30;
    let session = session_for(sessions, &database.name);
    let mut lines = vec![Line::styled(
        database.name.clone(),
        Style::default()
            .fg(theme.accent)
            .add_modifier(Modifier::BOLD),
    )];
    if let Some(session) = session {
        lines.push(Line::styled(
            format!(
                "{} · {} · {}",
                if session.current {
                    "current"
                } else {
                    "in memory"
                },
                session.mode,
                if session.changed { "extended" } else { "clean" }
            ),
            Style::default().fg(theme.success),
        ));
    } else {
        lines.push(Line::styled(
            "Enter opens a new in-memory workspace",
            Style::default().fg(theme.muted),
        ));
    }
    if compact {
        lines.extend([
            Line::from(vec![
                Span::raw(&database.kind),
                Span::styled(
                    if database.managed {
                        " · managed"
                    } else {
                        " · plain"
                    },
                    Style::default().fg(theme.muted),
                ),
            ]),
            Line::from(format!(
                "{} facts · {}",
                format_count(database.facts),
                database.size
            )),
            Line::from(format!(
                "{}T · {}S · {}L",
                database.table_count, database.struct_count, database.lattice_count
            )),
        ]);
        if database.stored_facts != database.facts {
            lines.push(Line::styled(
                format!("{} stored", format_count(database.stored_facts)),
                Style::default().fg(theme.muted),
            ));
        }
    } else {
        lines.extend([
            Line::from(vec![
                Span::styled("kind     ", Style::default().fg(theme.muted)),
                Span::raw(&database.kind),
                Span::styled(
                    if database.managed {
                        " · managed"
                    } else {
                        " · plain"
                    },
                    Style::default().fg(theme.muted),
                ),
            ]),
            stat_line(theme, "facts", format_count(database.facts)),
            stat_line(theme, "stored", format_count(database.stored_facts)),
            stat_line(
                theme,
                "disk",
                format!("{} · {} bytes", database.size, database.bytes),
            ),
            stat_line(
                theme,
                "schema",
                format!(
                    "{} table · {} struct · {} lattice",
                    database.table_count, database.struct_count, database.lattice_count
                ),
            ),
        ]);
    }
    if let Some(per) = database.per {
        lines.push(stat_line(theme, "retain", format!("{:.0}%", per * 100.0)));
    }
    if !database.inputs.is_empty() {
        lines.push(stat_line(theme, "inputs", database.inputs.join(", ")));
    }
    for stale in &database.stale {
        lines.push(Line::styled(
            format!("! {stale}"),
            Style::default().fg(theme.error),
        ));
    }
    lines.push(Line::from(""));
    lines.push(Line::styled(
        "SCHEMA",
        Style::default()
            .fg(theme.highlight)
            .add_modifier(Modifier::BOLD),
    ));

    let room = area
        .height
        .saturating_sub(lines.len() as u16)
        .saturating_sub(2) as usize;
    // Reserve the final available line for a truncation marker when needed.
    // That keeps a very short terminal from painting past the panel border.
    let relation_lines = if database.relations.len() > room {
        room.saturating_sub(1)
    } else {
        room
    };
    for relation in database.relations.iter().take(relation_lines) {
        let marker = match relation.kind.as_str() {
            "struct" => "S",
            "lattice" => "L",
            _ => "T",
        };
        let detail = relation
            .detail
            .as_deref()
            .map(|value| format!(" · {value}"))
            .unwrap_or_default();
        let stored = if relation.stored_facts != relation.facts {
            format!(" · {} stored", format_count(relation.stored_facts))
        } else {
            String::new()
        };
        if compact {
            lines.push(Line::from(vec![
                Span::styled(format!("{marker} "), Style::default().fg(theme.success)),
                Span::styled(
                    format!("{}/{}", relation.name, relation.arity),
                    Style::default().fg(theme.text),
                ),
                Span::styled(
                    format!("  {}", format_count(relation.facts)),
                    Style::default().fg(theme.muted),
                ),
            ]));
        } else {
            lines.push(Line::from(vec![
                Span::styled(format!("{marker} "), Style::default().fg(theme.success)),
                Span::styled(
                    format!("{}/{}", relation.name, relation.arity),
                    Style::default().fg(theme.text),
                ),
                Span::styled(
                    format!(
                        "  {} facts{stored}{detail} · {}",
                        format_count(relation.facts),
                        relation.count_source
                    ),
                    Style::default().fg(theme.muted),
                ),
            ]));
        }
    }
    if database.relations.len() > relation_lines {
        lines.push(Line::styled(
            format!("… {} more", database.relations.len() - relation_lines),
            Style::default().fg(theme.muted),
        ));
    }

    frame.render_widget(
        Paragraph::new(lines).wrap(Wrap { trim: false }).block(
            Block::default()
                .borders(Borders::ALL)
                .border_style(Style::default().fg(theme.panel))
                .title(" Database summary "),
        ),
        area,
    );
}

fn session_for<'a>(sessions: &'a [SessionSummary], database: &str) -> Option<&'a SessionSummary> {
    sessions
        .iter()
        .find(|session| session.database.as_deref() == Some(database))
}

fn stat_line(theme: &Theme, label: &'static str, value: String) -> Line<'static> {
    Line::from(vec![
        Span::styled(format!("{label:<9}"), Style::default().fg(theme.muted)),
        Span::raw(value),
    ])
}

fn format_count(number: u64) -> String {
    let digits = number.to_string();
    let mut formatted = String::with_capacity(digits.len() + digits.len() / 3);
    for (index, character) in digits.chars().enumerate() {
        if index > 0 && (digits.len() - index).is_multiple_of(3) {
            formatted.push(',');
        }
        formatted.push(character);
    }
    formatted
}
