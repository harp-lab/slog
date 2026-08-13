//! Presentation-neutral decoding of successful compiler/session responses.
//!
//! The Racket server owns command semantics. Both the full-screen canvas and
//! `--plain` consume this small projection instead of independently scraping
//! title, line, kind, and lifecycle fields from JSON.

use crate::transcript::TranscriptEntry;
use serde_json::Value;

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
        let lines = raw
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

#[cfg(test)]
mod tests {
    use super::CommandResult;

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
