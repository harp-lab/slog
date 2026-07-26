//! Typed observations of the compiler/session runtime.
//!
//! The Racket server owns compiler sessions and their daemon connections. The
//! Rust client keeps a projection for navigation and rendering; it must not
//! infer semantic state by parsing human-readable transcript lines.

use serde::Deserialize;
use serde_json::Value;
use std::collections::BTreeMap;

/// The daemon's fact-update counter. This is intentionally not named a
/// boundary: rename/drop do not advance it, while N3's BoundaryKey is the
/// durable environment identity that read-only queries and previews use.
#[derive(Clone, Copy, Debug, Eq, Ord, PartialEq, PartialOrd)]
pub struct UpdateRevision(pub u64);

#[derive(Clone, Debug, Default, Eq, PartialEq)]
pub enum CountsValidity {
    Valid,
    Invalid,
    #[default]
    Unknown,
    Other(String),
}

impl<'de> Deserialize<'de> for CountsValidity {
    fn deserialize<D>(deserializer: D) -> Result<Self, D::Error>
    where
        D: serde::Deserializer<'de>,
    {
        let value = String::deserialize(deserializer)?;
        Ok(match value.as_str() {
            "valid" => Self::Valid,
            "invalid" => Self::Invalid,
            "unknown" => Self::Unknown,
            _ => Self::Other(value),
        })
    }
}

impl CountsValidity {
    pub fn label(&self) -> &str {
        match self {
            Self::Valid => "valid",
            Self::Invalid => "invalid",
            Self::Unknown => "unknown",
            Self::Other(value) => value,
        }
    }
}

#[derive(Clone, Debug, Deserialize, Eq, PartialEq)]
pub struct RequestedRelationChange {
    pub relation: String,
    #[serde(default)]
    pub added: u64,
    #[serde(default)]
    pub removed: u64,
}

#[derive(Clone, Debug, Deserialize, Eq, PartialEq)]
pub struct RelationSizeDelta {
    pub relation: String,
    pub before: Option<u64>,
    pub after: Option<u64>,
    pub net: i64,
}

#[derive(Clone, Debug, Deserialize, Eq, PartialEq)]
pub struct RuntimeRoute {
    pub kind: String,
    #[serde(default)]
    pub detail: Vec<String>,
}

/// Structured evidence attached to a successful semantic command.
///
/// Unknown fields are deliberately accepted so the Racket contract can grow
/// additively. Required identity/state fields remain strict: silently dropping
/// a malformed change would make later UI state look authoritative when it is
/// not.
#[derive(Clone, Debug, Deserialize, Eq, PartialEq)]
#[serde(rename_all = "kebab-case")]
pub struct SemanticChange {
    pub operation: String,
    pub target: String,
    pub status: String,
    #[serde(default)]
    pub update_revision: Option<u64>,
    #[serde(default)]
    pub counts: CountsValidity,
    #[serde(default)]
    pub requested: Vec<RequestedRelationChange>,
    #[serde(default)]
    pub size_deltas: Vec<RelationSizeDelta>,
    #[serde(default)]
    pub size_deltas_omitted: usize,
    #[serde(default)]
    pub sizes_observed: bool,
    #[serde(default)]
    pub routes: Vec<RuntimeRoute>,
}

#[derive(Clone, Debug, Default)]
pub struct RuntimeSessionState {
    pub update_revision: Option<UpdateRevision>,
    pub counts: CountsValidity,
    /// Sizes learned from structured snapshots/deltas. This is a cache, not
    /// the relation catalog; the tables observation carries N3's relation and
    /// boundary identity separately.
    pub observed_relation_sizes: BTreeMap<String, u64>,
    pub sizes_complete: bool,
    pub last_change: Option<SemanticChange>,
}

impl RuntimeSessionState {
    fn apply(&mut self, change: SemanticChange) {
        self.update_revision = change.update_revision.map(UpdateRevision);
        self.counts = change.counts.clone();
        if change.sizes_observed {
            for delta in &change.size_deltas {
                match delta.after {
                    Some(size) => {
                        self.observed_relation_sizes
                            .insert(delta.relation.clone(), size);
                    }
                    None => {
                        self.observed_relation_sizes.remove(&delta.relation);
                    }
                }
            }
            if change.size_deltas_omitted > 0 {
                self.sizes_complete = false;
            } else if change.operation == "open"
                && change
                    .size_deltas
                    .iter()
                    .all(|delta| delta.before.is_none())
            {
                // An open compares an empty pre-session catalog with the
                // fully loaded one. With no omitted rows this seeds a complete
                // size projection, including zero-row relations.
                self.sizes_complete = true;
            }
        }
        self.last_change = Some(change);
    }

    pub fn plain_summary(&self) -> String {
        format!(
            "update revision {} · counts {}",
            self.update_revision
                .map(|revision| revision.0.to_string())
                .unwrap_or_else(|| "unknown".to_owned()),
            self.counts.label()
        )
    }
}

/// Client-side projections keyed by the server's current target spelling.
///
/// Database names and `scratch` are only compatibility keys. Once the server
/// publishes stable SessionKeys, this table can be re-keyed without changing
/// the semantic-change decoder or UI consumers.
#[derive(Debug, Default)]
pub struct RuntimeLedger {
    sessions: BTreeMap<String, RuntimeSessionState>,
}

impl RuntimeLedger {
    pub fn session(&self, target: &str) -> Option<&RuntimeSessionState> {
        self.sessions.get(target)
    }

    /// Observe optional `change` metadata from a successful result.
    ///
    /// A decoding error is returned to the presentation layer, but the
    /// command's successful result remains successful. This mirrors the
    /// server rule that failed post-commit observation cannot undo a mutation.
    pub fn observe_result(&mut self, result: &Value) -> Result<bool, String> {
        let Some(value) = result.get("change") else {
            return Ok(false);
        };
        let change = serde_json::from_value::<SemanticChange>(value.clone())
            .map_err(|error| format!("invalid semantic change metadata: {error}"))?;
        self.sessions
            .entry(change.target.clone())
            .or_default()
            .apply(change);
        Ok(true)
    }
}

#[cfg(test)]
mod tests {
    use super::{CountsValidity, RuntimeLedger, UpdateRevision};

    #[test]
    fn applies_structured_changes_without_parsing_transcript_lines() {
        let mut ledger = RuntimeLedger::default();
        ledger
            .observe_result(&serde_json::json!({
                "title": "words are presentation only",
                "lines": ["this line intentionally contains no state"],
                "change": {
                    "operation": "open",
                    "target": "example",
                    "status": "settled",
                    "update-revision": 0,
                    "counts": "valid",
                    "requested": [],
                    "size-deltas": [
                        {"relation": "edge", "before": null, "after": 3, "net": 3},
                        {"relation": "empty", "before": null, "after": 0, "net": 0}
                    ],
                    "size-deltas-omitted": 0,
                    "sizes-observed": true,
                    "routes": []
                }
            }))
            .expect("valid change");

        let state = ledger.session("example").expect("runtime target");
        assert_eq!(state.update_revision, Some(UpdateRevision(0)));
        assert_eq!(state.counts, CountsValidity::Valid);
        assert_eq!(state.observed_relation_sizes["edge"], 3);
        assert_eq!(state.observed_relation_sizes["empty"], 0);
        assert!(state.sizes_complete);
    }

    #[test]
    fn tracks_noop_updates_and_environment_rebindings_honestly() {
        let mut ledger = RuntimeLedger::default();
        for change in [
            serde_json::json!({
                "operation": "add",
                "target": "example",
                "status": "settled",
                "update-revision": 0,
                "counts": "valid",
                "requested": [{"relation": "edge", "added": 1, "removed": 0}],
                "size-deltas": [],
                "size-deltas-omitted": 0,
                "sizes-observed": true,
                "routes": []
            }),
            serde_json::json!({
                "operation": "rename",
                "target": "example",
                "status": "settled",
                "update-revision": 0,
                "counts": "valid",
                "requested": [],
                "size-deltas": [
                    {"relation": "edge", "before": 3, "after": null, "net": -3},
                    {"relation": "input_edge", "before": null, "after": 3, "net": 3}
                ],
                "size-deltas-omitted": 0,
                "sizes-observed": true,
                "routes": []
            }),
        ] {
            ledger
                .observe_result(&serde_json::json!({"change": change}))
                .expect("valid change");
        }

        let state = ledger.session("example").expect("runtime target");
        assert_eq!(state.update_revision, Some(UpdateRevision(0)));
        assert!(!state.observed_relation_sizes.contains_key("edge"));
        assert_eq!(state.observed_relation_sizes["input_edge"], 3);
        assert_eq!(
            state
                .last_change
                .as_ref()
                .map(|change| change.operation.as_str()),
            Some("rename")
        );
    }

    #[test]
    fn malformed_metadata_does_not_mutate_the_ledger() {
        let mut ledger = RuntimeLedger::default();
        let error = ledger
            .observe_result(&serde_json::json!({
                "change": {"operation": "add", "target": 12}
            }))
            .expect_err("malformed change");
        assert!(error.contains("invalid semantic change metadata"));
        assert!(ledger.session("12").is_none());
    }
}
