//! Presentation-neutral decoding of successful compiler/session responses.
//!
//! The Racket server owns command semantics. Both the full-screen canvas and
//! `--plain` consume this small projection instead of independently scraping
//! title, line, kind, and lifecycle fields from JSON.

use crate::transcript::TranscriptEntry;
use serde_json::Value;
use unicode_width::{UnicodeWidthChar, UnicodeWidthStr};

#[derive(Clone, Debug)]
pub struct CommandResult {
    raw: Value,
    kind: String,
    title: String,
    lines: Vec<String>,
    closes: bool,
}

impl CommandResult {
    pub fn from_value(raw: Value) -> Self {
        let kind = raw
            .get("kind")
            .and_then(Value::as_str)
            .unwrap_or("result")
            .to_owned();
        let title = raw
            .get("title")
            .and_then(Value::as_str)
            .unwrap_or("Result")
            .to_owned();
        // Keep diagnostic lines on the wire while preferring the server's
        // compact user-facing projection. Structured detail stays available
        // to the expandable live canvas through `raw`.
        let lines: Vec<String> = raw
            .get("brief-lines")
            .or_else(|| raw.get("lines"))
            .and_then(Value::as_array)
            .map(|values| {
                values
                    .iter()
                    .filter_map(Value::as_str)
                    .map(str::to_owned)
                    .collect()
            })
            .unwrap_or_default();
        // A result set's rows read as a table.
        let lines = match set_table(&raw) {
            Some(table) => with_table(&lines, table),
            None => lines,
        };
        let closes = raw.get("close").and_then(Value::as_bool).unwrap_or(false);
        Self {
            raw,
            kind,
            title,
            lines,
            closes,
        }
    }

    pub fn raw(&self) -> &Value {
        &self.raw
    }

    pub fn kind(&self) -> &str {
        &self.kind
    }

    pub fn title(&self) -> &str {
        &self.title
    }

    pub fn lines(&self) -> &[String] {
        &self.lines
    }

    pub fn closes(&self) -> bool {
        self.closes
    }

    pub fn transcript_entry(&self) -> TranscriptEntry {
        self.transcript_entry_with_title(self.title.clone())
    }

    pub fn transcript_entry_with_title(&self, title: impl Into<String>) -> TranscriptEntry {
        TranscriptEntry::result(title, self.lines.clone())
    }
}

/// The widest a table cell is drawn; longer values end in `…`.
const CELL_WIDTH: usize = 32;

/// A result set's page as a table: its columns, each named by its variable
/// or else its place (`edge.1`), over its rows' values, aligned. None when
/// the result carries no page of rows (a count, or a ground query, whose
/// one row is its fact).
fn set_table(raw: &Value) -> Option<Vec<String>> {
    raw.get("set")?;
    let columns: Vec<String> = raw
        .get("columns")?
        .as_array()?
        .iter()
        .map(|column| cell(column["var"].as_str().or(column["name"].as_str()).unwrap_or("")))
        .collect();
    let text = |values: &Value| -> Vec<String> {
        values
            .as_array()
            .into_iter()
            .flatten()
            .map(|value| cell(value.as_str().unwrap_or("")))
            .collect()
    };
    let rows: Vec<Vec<String>> = raw.get("rows")?.as_array()?.iter().map(text).collect();
    if columns.is_empty() {
        return None;
    }
    let mut widths: Vec<usize> = columns.iter().map(|name| name.width()).collect();
    for row in &rows {
        for (width, value) in widths.iter_mut().zip(row) {
            *width = (*width).max(value.width());
        }
    }
    let line = |values: &[String]| {
        let padded: Vec<String> = values
            .iter()
            .zip(&widths)
            .map(|(value, width)| format!("{value}{}", " ".repeat(width - value.width())))
            .collect();
        padded.join("  ").trim_end().to_owned()
    };
    Some(std::iter::once(line(&columns)).chain(rows.iter().map(|row| line(row))).collect())
}

fn cell(text: &str) -> String {
    if text.width() <= CELL_WIDTH {
        return text.to_owned();
    }
    let mut cut = String::new();
    for c in text.chars() {
        if cut.width() + c.width().unwrap_or(0) >= CELL_WIDTH {
            break;
        }
        cut.push(c);
    }
    cut + "…"
}

/// `lines` with its numbered rows (`N  (…)`) replaced by `table`.
fn with_table(lines: &[String], table: Vec<String>) -> Vec<String> {
    let row = |line: &String| {
        let digits = line.len() - line.trim_start_matches(|c: char| c.is_ascii_digit()).len();
        digits > 0 && line[digits..].starts_with("  (")
    };
    let Some(first) = lines.iter().position(row) else {
        return lines.to_vec();
    };
    let end = first + lines[first..].iter().take_while(|line| row(line)).count();
    lines[..first].iter().cloned().chain(table).chain(lines[end..].iter().cloned()).collect()
}

#[cfg(test)]
mod tests {
    use super::CommandResult;

    #[test]
    fn a_result_sets_rows_are_a_table_under_its_name_and_size() {
        let result = CommandResult::from_value(serde_json::json!({
            "kind": "query",
            "title": "Query · (X Name)",
            "lines": ["r3 · 2 rows", "1  (1 \"a\")", "2  (10 \"bb\")", "r1 is no longer watched"],
            "set": {"name": "r3", "count": 2},
            "columns": [{"name": "X", "var": "X"}, {"name": "Name", "var": "Name"}],
            "rows": [["1", "\"a\""], ["10", "\"bb\""]]
        }));
        assert_eq!(
            result.lines(),
            ["r3 · 2 rows", "X   Name", "1   \"a\"", "10  \"bb\"", "r1 is no longer watched"]
        );
    }

    #[test]
    fn a_ground_set_keeps_its_fact_and_a_long_value_is_cut() {
        let ground = CommandResult::from_value(serde_json::json!({
            "lines": ["r1 · 1 row", "1  (edge 1 2)"],
            "set": {"name": "r1"},
            "columns": [{"name": "edge.1", "var": null}, {"name": "edge.2", "var": null}]
        }));
        assert_eq!(ground.lines(), ["r1 · 1 row", "1  (edge 1 2)"]);
        let long = "x".repeat(40);
        let cut = CommandResult::from_value(serde_json::json!({
            "lines": ["r2 · 1 row", format!("1  ({long})")],
            "set": {"name": "r2"}, "columns": [{"name": "s.1", "var": "S"}], "rows": [[long]]
        }));
        assert_eq!(cut.lines(), ["r2 · 1 row".to_owned(), "S".to_owned(), format!("{}…", "x".repeat(31))]);
    }

    #[test]
    fn projects_presentation_and_lifecycle_without_losing_raw_metadata() {
        let result = CommandResult::from_value(serde_json::json!({
            "kind": "mutation",
            "title": "Add · edge",
            "lines": ["(edge 1 2)", "settled", "size changes: edge +1"],
            "brief-lines": ["(edge 1 2)", "committed"],
            "close": true,
            "change": {
                "operation": "add",
                "target": "scratch",
                "status": "settled"
            },
            "future-field": 17
        }));
        assert_eq!(result.kind(), "mutation");
        assert_eq!(result.title(), "Add · edge");
        assert_eq!(result.lines(), ["(edge 1 2)", "committed"]);
        assert!(result.closes());
        assert_eq!(result.raw()["future-field"], 17);
        assert_eq!(
            result.transcript_entry().plain(),
            "◆ Add · edge\n  (edge 1 2)\n  committed"
        );
    }

    #[test]
    fn defaults_are_stable_for_additive_or_partial_results() {
        let result = CommandResult::from_value(serde_json::json!({
            "lines": ["kept", 12, null]
        }));
        assert_eq!(result.kind(), "result");
        assert_eq!(result.title(), "Result");
        assert_eq!(result.lines(), ["kept"]);
        assert!(!result.closes());
    }
}
