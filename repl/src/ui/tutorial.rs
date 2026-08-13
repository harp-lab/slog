use super::{CYAN, MUTED, PANEL, PINK};
use crate::tutorial::{TutorialMenu, TutorialOverlay};
use ratatui::Frame;
use ratatui::layout::{Alignment, Constraint, Layout, Rect};
use ratatui::style::{Color, Modifier, Style};
use ratatui::text::{Line, Span};
use ratatui::widgets::{Block, Borders, Cell, Paragraph, Row, Table, Wrap};

pub fn render(frame: &mut Frame<'_>, area: Rect, overlay: &TutorialOverlay) {
    match overlay {
        TutorialOverlay::Menu(menu) => render_menu(frame, area, menu),
        TutorialOverlay::Confirm {
            tutorial,
            resident,
            extended,
        } => render_confirmation(frame, area, tutorial.title.as_str(), *resident, *extended),
    }
}

pub fn render_footer(frame: &mut Frame<'_>, area: Rect, overlay: &TutorialOverlay) {
    let text = match overlay {
        TutorialOverlay::Menu(_) => " ↑/↓ or j/k select · Enter start · Esc/q close ",
        TutorialOverlay::Confirm { .. } => {
            " Enter/y discard in-memory sessions and start · n/Esc cancel "
        }
    };
    frame.render_widget(
        Paragraph::new(text)
            .alignment(Alignment::Center)
            .style(Style::default().fg(MUTED)),
        area,
    );
}

fn render_menu(frame: &mut Frame<'_>, area: Rect, menu: &TutorialMenu) {
    let visible_rows = area.height.saturating_sub(3) as usize;
    let offset = menu.visible_offset(visible_rows);
    let rows = menu
        .tutorials
        .iter()
        .enumerate()
        .skip(offset)
        .take(visible_rows)
        .map(|(index, tutorial)| {
            let selected = index == menu.selected;
            Row::new(vec![
                Cell::from(if selected { "›" } else { "" }),
                Cell::from(tutorial.title.clone()),
                Cell::from(tutorial.summary.clone()),
            ])
            .style(if selected {
                Style::default()
                    .fg(Color::Black)
                    .bg(CYAN)
                    .add_modifier(Modifier::BOLD)
            } else {
                Style::default().fg(Color::Gray)
            })
        });
    let title = format!(
        " Tutorials · {} available{} ",
        menu.tutorials.len(),
        if menu.load_errors == 0 {
            String::new()
        } else {
            format!(" · {} invalid", menu.load_errors)
        }
    );
    frame.render_widget(
        Table::new(
            rows,
            [
                Constraint::Length(2),
                Constraint::Length(30),
                Constraint::Min(24),
            ],
        )
        .header(
            Row::new(["", "tutorial", "what you will do"])
                .style(Style::default().fg(PINK).add_modifier(Modifier::BOLD)),
        )
        .column_spacing(1)
        .block(
            Block::default()
                .borders(Borders::ALL)
                .border_style(Style::default().fg(PANEL))
                .title(title),
        ),
        area,
    );
}

fn render_confirmation(
    frame: &mut Frame<'_>,
    area: Rect,
    title: &str,
    resident: usize,
    extended: usize,
) {
    let vertical = Layout::vertical([
        Constraint::Fill(1),
        Constraint::Length(11.min(area.height)),
        Constraint::Fill(1),
    ])
    .split(area);
    let horizontal = Layout::horizontal([
        Constraint::Fill(1),
        Constraint::Length(68.min(area.width)),
        Constraint::Fill(1),
    ])
    .split(vertical[1]);
    let lines = vec![
        Line::from(""),
        Line::from(vec![
            Span::raw("Starting "),
            Span::styled(
                title,
                Style::default().fg(CYAN).add_modifier(Modifier::BOLD),
            ),
            Span::raw(" needs a fresh session."),
        ]),
        Line::from(""),
        Line::from(format!(
            "This closes {resident} resident in-memory workspace{}{}.",
            if resident == 1 { "" } else { "s" },
            if extended == 0 {
                String::new()
            } else {
                format!(
                    ", including {extended} extended workspace{}",
                    if extended == 1 { "" } else { "s" }
                )
            }
        )),
        Line::styled(
            "Saved databases on disk are not deleted. The old transcript is retained.",
            Style::default().fg(MUTED),
        ),
        Line::from(""),
        Line::styled(
            "Continue?",
            Style::default().fg(PINK).add_modifier(Modifier::BOLD),
        ),
    ];
    frame.render_widget(
        Paragraph::new(lines)
            .alignment(Alignment::Center)
            .wrap(Wrap { trim: false })
            .block(
                Block::default()
                    .borders(Borders::ALL)
                    .border_style(Style::default().fg(PINK))
                    .title(" Fresh tutorial session "),
            ),
        horizontal[1],
    );
}
