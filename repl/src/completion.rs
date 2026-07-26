//! Terminal-independent command completion for the native REPL.
//!
//! Candidates come only from command grammar and structured client state.
//! Relation and namespace names deliberately remain absent until the server
//! publishes the selected boundary catalog; size observations and saved
//! relation directories are not substitutes for that catalog.

use std::collections::BTreeSet;

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct CompletionCandidate {
    pub label: String,
    pub replacement: String,
    pub detail: String,
}

impl CompletionCandidate {
    fn new(
        label: impl Into<String>,
        replacement: impl Into<String>,
        detail: impl Into<String>,
    ) -> Self {
        Self {
            label: label.into(),
            replacement: replacement.into(),
            detail: detail.into(),
        }
    }
}

#[derive(Clone, Debug, Default, Eq, PartialEq)]
pub struct CompletionInventory {
    pub databases: Vec<String>,
    pub expand_positions: Vec<String>,
    pub collapse_positions: Vec<String>,
    pub card_positions: Vec<String>,
    pub card_open: bool,
    pub page_targets: Vec<(String, usize)>,
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct CompletionMenu {
    candidates: Vec<CompletionCandidate>,
    selected: usize,
    start: usize,
    end: usize,
}

impl CompletionMenu {
    pub fn candidates(&self) -> &[CompletionCandidate] {
        &self.candidates
    }

    pub fn selected(&self) -> usize {
        self.selected
    }

    pub fn selected_candidate(&self) -> &CompletionCandidate {
        &self.candidates[self.selected]
    }

    pub fn next(&mut self) {
        self.selected = (self.selected + 1) % self.candidates.len();
    }

    pub fn previous(&mut self) {
        self.selected = self
            .selected
            .checked_sub(1)
            .unwrap_or(self.candidates.len() - 1);
    }

    pub fn replacement_range(&self) -> (usize, usize) {
        (self.start, self.end)
    }
}

struct CommandSpec {
    label: &'static str,
    takes_argument: bool,
    detail: &'static str,
}

const COMMANDS: &[CommandSpec] = &[
    CommandSpec {
        label: ":clear",
        takes_argument: false,
        detail: "clear the visible transcript",
    },
    CommandSpec {
        label: ":help",
        takes_argument: false,
        detail: "show the command reference",
    },
    CommandSpec {
        label: ":ping",
        takes_argument: false,
        detail: "test the private backend connection",
    },
    CommandSpec {
        label: ":quit",
        takes_argument: false,
        detail: "close the REPL",
    },
    CommandSpec {
        label: ":share",
        takes_argument: false,
        detail: "show co-author connection details",
    },
    CommandSpec {
        label: ":status",
        takes_argument: false,
        detail: "show REPL and database state",
    },
    CommandSpec {
        label: "add",
        takes_argument: true,
        detail: "add an input tuple",
    },
    CommandSpec {
        label: "card",
        takes_argument: true,
        detail: "open a live-canvas card",
    },
    CommandSpec {
        label: "collapse",
        takes_argument: true,
        detail: "collapse a live-canvas node",
    },
    CommandSpec {
        label: "count",
        takes_argument: true,
        detail: "count a live relation",
    },
    CommandSpec {
        label: "current",
        takes_argument: false,
        detail: "describe the current database",
    },
    CommandSpec {
        label: "del",
        takes_argument: true,
        detail: "retract an input tuple",
    },
    CommandSpec {
        label: "drop",
        takes_argument: true,
        detail: "remove a live relation name",
    },
    CommandSpec {
        label: "expand",
        takes_argument: true,
        detail: "expand a live-canvas node",
    },
    CommandSpec {
        label: "library",
        takes_argument: true,
        detail: "browse or control saved databases",
    },
    CommandSpec {
        label: "mode",
        takes_argument: true,
        detail: "change database access",
    },
    CommandSpec {
        label: "open",
        takes_argument: true,
        detail: "open or switch database",
    },
    CommandSpec {
        label: "page",
        takes_argument: true,
        detail: "select an absolute page in a buffered canvas collection",
    },
    CommandSpec {
        label: "pipeline",
        takes_argument: false,
        detail: "show the raw versioned pipeline",
    },
    CommandSpec {
        label: "query",
        takes_argument: true,
        detail: "test a relation value prefix",
    },
    CommandSpec {
        label: "rename",
        takes_argument: true,
        detail: "rename a live relation",
    },
    CommandSpec {
        label: "resident",
        takes_argument: false,
        detail: "list resident databases",
    },
    CommandSpec {
        label: "run",
        takes_argument: true,
        detail: "compile and run a Slog file",
    },
    CommandSpec {
        label: "save",
        takes_argument: true,
        detail: "save the current database",
    },
    CommandSpec {
        label: "schema",
        takes_argument: false,
        detail: "show the raw live schema",
    },
    CommandSpec {
        label: "search",
        takes_argument: true,
        detail: "search the visible live canvas",
    },
    CommandSpec {
        label: "search-clear",
        takes_argument: false,
        detail: "clear the live-canvas search",
    },
    CommandSpec {
        label: "search-next",
        takes_argument: false,
        detail: "select the next visible search match",
    },
    CommandSpec {
        label: "search-previous",
        takes_argument: false,
        detail: "select the previous visible search match",
    },
    CommandSpec {
        label: "show",
        takes_argument: true,
        detail: "show rows from a live relation",
    },
    CommandSpec {
        label: "state",
        takes_argument: true,
        detail: "show pipeline or relation state",
    },
    CommandSpec {
        label: "tables",
        takes_argument: true,
        detail: "list live relations",
    },
];

pub fn complete(
    source: &str,
    cursor: usize,
    inventory: &CompletionInventory,
) -> Option<CompletionMenu> {
    if cursor > source.len() || !source.is_char_boundary(cursor) {
        return None;
    }
    let line_start = source[..cursor].rfind('\n').map_or(0, |index| index + 1);
    if line_start > 0 {
        return None;
    }
    let line_end = source[cursor..]
        .find('\n')
        .map_or(source.len(), |index| cursor + index);
    let start = source[line_start..cursor]
        .char_indices()
        .rev()
        .find(|(_, character)| character.is_whitespace())
        .map_or(line_start, |(index, character)| {
            line_start + index + character.len_utf8()
        });
    let end = source[cursor..line_end]
        .char_indices()
        .find(|(_, character)| character.is_whitespace())
        .map_or(line_end, |(index, _)| cursor + index);
    let prefix = &source[start..cursor];
    let head = source[line_start..start]
        .split_whitespace()
        .collect::<Vec<_>>();

    let candidates = match head.as_slice() {
        [] => command_candidates(prefix),
        [verb] if verb.eq_ignore_ascii_case("mode") => word_candidates(
            prefix,
            [
                ("readonly", "protect from mutations"),
                ("mutable", "allow extensions"),
            ],
        ),
        [verb] if matches_lower(verb, &["open", "use"]) => {
            dynamic_candidates(prefix, &inventory.databases, "database")
        }
        [verb] if verb.eq_ignore_ascii_case("library") => word_candidates(
            prefix,
            [
                ("select ", "focus a saved database"),
                ("close", "return to the shell"),
            ],
        ),
        [verb, subcommand]
            if verb.eq_ignore_ascii_case("library")
                && subcommand.eq_ignore_ascii_case("select") =>
        {
            dynamic_candidates(prefix, &inventory.databases, "database")
        }
        [verb] if verb.eq_ignore_ascii_case("expand") => dynamic_candidates(
            prefix,
            &inventory.expand_positions,
            "expandable canvas position",
        ),
        [verb] if verb.eq_ignore_ascii_case("collapse") => dynamic_candidates(
            prefix,
            &inventory.collapse_positions,
            "collapsible canvas position",
        ),
        [verb] if verb.eq_ignore_ascii_case("card") => {
            let mut positions = inventory.card_positions.clone();
            if inventory.card_open {
                positions.push("close".to_owned());
            }
            dynamic_candidates(prefix, &positions, "canvas card position")
        }
        [verb] if verb.eq_ignore_ascii_case("page") => {
            let positions = inventory
                .page_targets
                .iter()
                .map(|(path, _)| path.clone())
                .collect::<Vec<_>>();
            dynamic_candidates(prefix, &positions, "paged canvas collection")
        }
        [verb, position] if verb.eq_ignore_ascii_case("page") => inventory
            .page_targets
            .iter()
            .find_map(|(path, pages)| {
                (path == position).then(|| {
                    dynamic_candidates(
                        prefix,
                        &(1..=*pages)
                            .map(|page| page.to_string())
                            .collect::<Vec<_>>(),
                        "absolute buffered page",
                    )
                })
            })
            .unwrap_or_default(),
        _ => Vec::new(),
    };
    let candidates = sorted_unique(candidates);
    (!candidates.is_empty()).then_some(CompletionMenu {
        candidates,
        selected: 0,
        start,
        end,
    })
}

fn command_candidates(prefix: &str) -> Vec<CompletionCandidate> {
    let prefix = prefix.to_ascii_lowercase();
    COMMANDS
        .iter()
        .filter(|command| command.label.starts_with(&prefix))
        .map(|command| {
            CompletionCandidate::new(
                command.label,
                if command.takes_argument {
                    format!("{} ", command.label)
                } else {
                    command.label.to_owned()
                },
                command.detail,
            )
        })
        .collect()
}

fn word_candidates<const N: usize>(
    prefix: &str,
    words: [(&str, &str); N],
) -> Vec<CompletionCandidate> {
    let prefix = prefix.to_ascii_lowercase();
    words
        .into_iter()
        .filter(|(word, _)| word.trim_end().starts_with(&prefix))
        .map(|(word, detail)| CompletionCandidate::new(word.trim_end(), word, detail))
        .collect()
}

fn dynamic_candidates(prefix: &str, values: &[String], detail: &str) -> Vec<CompletionCandidate> {
    values
        .iter()
        .filter(|value| value.starts_with(prefix))
        .map(|value| CompletionCandidate::new(value, value, detail))
        .collect()
}

fn sorted_unique(candidates: Vec<CompletionCandidate>) -> Vec<CompletionCandidate> {
    let mut seen = BTreeSet::new();
    let mut candidates = candidates
        .into_iter()
        .filter(|candidate| seen.insert(candidate.replacement.clone()))
        .collect::<Vec<_>>();
    candidates.sort_by(|left, right| left.label.cmp(&right.label));
    candidates
}

fn matches_lower(value: &str, choices: &[&str]) -> bool {
    choices
        .iter()
        .any(|choice| value.eq_ignore_ascii_case(choice))
}

#[cfg(test)]
mod tests {
    use super::{CompletionInventory, complete};

    #[test]
    fn completes_a_unique_command_and_preserves_argument_spacing() {
        let menu = complete("ta", 2, &CompletionInventory::default()).expect("completion");
        assert_eq!(menu.candidates().len(), 1);
        assert_eq!(menu.selected_candidate().label, "tables");
        assert_eq!(menu.selected_candidate().replacement, "tables ");
        assert_eq!(menu.replacement_range(), (0, 2));
    }

    #[test]
    fn completes_grammar_arguments_and_structured_database_names() {
        let inventory = CompletionInventory {
            databases: vec!["alpha".to_owned(), "alpine".to_owned(), "beta".to_owned()],
            ..CompletionInventory::default()
        };
        let mode = complete("mode ", 5, &inventory).expect("mode completion");
        assert_eq!(mode.candidates().len(), 2);
        let database = complete("open al", 7, &inventory).expect("database completion");
        assert_eq!(
            database
                .candidates()
                .iter()
                .map(|candidate| candidate.label.as_str())
                .collect::<Vec<_>>(),
            ["alpha", "alpine"]
        );
    }

    #[test]
    fn completes_only_actions_valid_for_the_live_canvas() {
        let inventory = CompletionInventory {
            expand_positions: vec!["it.change".to_owned()],
            collapse_positions: vec!["it.change.requested".to_owned()],
            card_positions: vec!["it.change".to_owned()],
            card_open: true,
            page_targets: vec![("it".to_owned(), 3), ("it.change.requested".to_owned(), 2)],
            ..CompletionInventory::default()
        };
        assert_eq!(
            complete("expand it.", 10, &inventory)
                .expect("expand")
                .selected_candidate()
                .replacement,
            "it.change"
        );
        let cards = complete("card ", 5, &inventory).expect("cards");
        assert_eq!(cards.candidates().len(), 2);
        assert!(
            cards
                .candidates()
                .iter()
                .any(|candidate| candidate.label == "close")
        );
        assert_eq!(
            complete("page it.ch", 10, &inventory)
                .expect("page target")
                .selected_candidate()
                .replacement,
            "it.change.requested"
        );
        assert_eq!(
            complete("page it 2", 9, &inventory)
                .expect("page number")
                .selected_candidate()
                .replacement,
            "2"
        );
    }

    #[test]
    fn refuses_to_infer_relation_or_multiline_source_completion() {
        let inventory = CompletionInventory::default();
        assert!(complete("count ed", 8, &inventory).is_none());
        assert!(complete("rule (edge X Y)\n  ", 18, &inventory).is_none());
    }
}
