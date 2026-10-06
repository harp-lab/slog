//! What the agent knows about Slog: the curated reference its system prompt
//! carries.

/// The language reference appended to the agent's system prompt. Every
/// `slog` block in it runs (see the test below).
pub const REFERENCE: &str = include_str!("../agent/slog-reference.md");

#[cfg(test)]
mod tests {
    use super::REFERENCE;
    use crate::lane::{Lane, Mode};
    use crate::session::Session;
    use slog_repl::server::project_root;

    /// The reference's fenced blocks: (language, 1-based line, body).
    fn blocks() -> Vec<(&'static str, usize, &'static str)> {
        let mut blocks = Vec::new();
        let mut rest = REFERENCE;
        while let Some(open) = rest.find("```") {
            let after = &rest[open + 3..];
            let newline = after.find('\n').expect("a fence line");
            let close = after[newline..].find("\n```").expect("a closing fence") + newline;
            let line = REFERENCE[..REFERENCE.len() - rest.len() + open].lines().count() + 1;
            blocks.push((&after[..newline], line, &after[newline + 1..close + 1]));
            rest = &after[close + 4..];
        }
        blocks
    }

    /// The reference's guarantee: every `slog` block evaluates, every
    /// `slog-error` block fails with the message its first line quotes
    /// (`;; error: TEXT`), and every `?` line of a `query` block answers
    /// against the `slog` program just before it -- with what the line after
    /// it claims, when that is `;; => TEXT` (`;; => error: TEXT` for a
    /// refusal). Each runs as the agent's would: a file evaluated from
    /// nothing, then `?` lines, in a session server.
    #[tokio::test]
    async fn every_program_and_query_in_the_reference_runs() {
        let directory = std::env::temp_dir().join(format!("studio-reference-{}", std::process::id()));
        std::fs::create_dir_all(&directory).expect("scratch directory");
        let lane = Lane::new(project_root().expect("repository root"), Mode::Fast);
        let mut session = Session::new(&lane);
        let mut failures = Vec::new();
        let mut evaluated = false;
        for (language, line, body) in blocks() {
            match language {
                "slog" | "slog-error" => {
                    let file = directory.join(format!("line{line}.slog"));
                    std::fs::write(&file, body).expect("program file");
                    let mut errors = Vec::new();
                    evaluated = session
                        .evaluate(&lane, &file, &[], &mut |outcome| errors.extend(outcome.error.clone().map(|e| e.message)))
                        .await;
                    let error = errors.join("\n");
                    if language == "slog" && !evaluated {
                        failures.push(format!("line {line}: does not evaluate: {error}"));
                    } else if language == "slog-error" {
                        let expected = body.lines().next().and_then(|first| first.strip_prefix(";; error: "));
                        match expected {
                            None => failures.push(format!("line {line}: starts with no `;; error: TEXT`")),
                            Some(_) if evaluated => failures.push(format!("line {line}: evaluates, but should fail")),
                            Some(text) if !error.contains(text) => {
                                failures.push(format!("line {line}: fails without {text:?}: {error}"))
                            }
                            Some(_) => {}
                        }
                        evaluated = false;
                    }
                }
                "query" => {
                    let lines: Vec<&str> = body.lines().collect();
                    for (at, query) in lines.iter().enumerate().filter(|(_, query)| query.starts_with('?')) {
                        if !evaluated {
                            failures.push(format!("line {line}: {query} follows no evaluated program"));
                            continue;
                        }
                        let outcome = session.execute(&lane, query).await;
                        let expected = lines.get(at + 1).and_then(|next| next.strip_prefix(";; => "));
                        let answer = match (outcome.result, outcome.error) {
                            (_, Some(error)) => format!("error: {}", error.message),
                            (Some(result), None) => std::iter::once(&result["title"])
                                .chain(result["lines"].as_array().into_iter().flatten())
                                .filter_map(|text| text.as_str())
                                .collect::<Vec<_>>()
                                .join("\n"),
                            (None, None) => String::new(),
                        };
                        let refused = answer.starts_with("error: ");
                        let holds = match expected.map(|text| text.strip_prefix("error: ").ok_or(text)) {
                            Some(Ok(text)) => refused && answer.contains(text),
                            Some(Err(text)) => !refused && answer.contains(text),
                            None => !refused,
                        };
                        if !holds {
                            let wanted = expected.unwrap_or("an answer");
                            failures.push(format!("line {line}: {query}: wanted {wanted:?}, got {answer}"));
                        }
                    }
                }
                _ => {}
            }
        }
        lane.shutdown().await;
        std::fs::remove_dir_all(&directory).expect("cleanup");
        assert!(failures.is_empty(), "the reference has drifted:\n{}", failures.join("\n"));
    }
}
