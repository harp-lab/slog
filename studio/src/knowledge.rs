//! What the agent knows about Slog: the curated reference its system prompt
//! carries, and the repository's docs and example programs, which the
//! `search_docs`, `read_doc`, and `list_examples` tools open to it.

use serde_json::{Value, json};
use std::path::{Path, PathBuf};

/// The language reference appended to the agent's system prompt. Every
/// `slog` block in it runs (see the test below).
pub const REFERENCE: &str = include_str!("../agent/slog-reference.md");

/// The files the tools may read, relative to the repository root: user and
/// design docs, the standard library, examples, and the test programs.
pub fn corpus(root: &Path) -> Vec<PathBuf> {
    let mut files = Vec::new();
    for (directory, extensions) in [
        ("docs/user", &["md"][..]),
        ("docs/tutorial", &["md"]),
        ("lib", &["slog"]),
        ("tests", &["slog"]),
    ] {
        files.extend(listing(root, Path::new(directory), extensions, false));
    }
    for doc in [
        "lattices",
        "primitives",
        "demand",
        "modules",
        "sequences",
        "smt",
    ] {
        files.push(PathBuf::from(format!("docs/{doc}.md")));
    }
    files.extend(listing(root, Path::new("examples"), &["slog", "md"], true));
    files.retain(|file| root.join(file).is_file());
    files
}

fn listing(root: &Path, directory: &Path, extensions: &[&str], recurse: bool) -> Vec<PathBuf> {
    let Ok(entries) = std::fs::read_dir(root.join(directory)) else {
        return Vec::new();
    };
    let mut files: Vec<PathBuf> = Vec::new();
    for entry in entries.flatten() {
        let path = directory.join(entry.file_name());
        if entry.path().is_dir() {
            if recurse {
                files.extend(listing(root, &path, extensions, true));
            }
        } else if path
            .extension()
            .is_some_and(|ext| extensions.iter().any(|e| ext == *e))
        {
            files.push(path);
        }
    }
    files.sort();
    files
}

/// The paragraphs of the corpus that best match `query`'s terms: most
/// distinct terms first, then the whole query as a phrase, then the user
/// guides before design notes and programs, then frequency.
pub fn search(root: &Path, query: &str, limit: usize) -> Value {
    let query = query.to_lowercase();
    let terms: Vec<&str> = query.split_whitespace().collect();
    let mut hits = Vec::new();
    for file in corpus(root) {
        let Ok(text) = std::fs::read_to_string(root.join(&file)) else {
            continue;
        };
        let lines: Vec<&str> = text.lines().collect();
        let mut heading = "";
        let mut start = 0;
        while start < lines.len() {
            if lines[start].trim().is_empty() {
                start += 1;
                continue;
            }
            let end = (start..lines.len())
                .find(|&i| lines[i].trim().is_empty())
                .unwrap_or(lines.len());
            let paragraph = lines[start..end].join("\n");
            let lower = paragraph.to_lowercase();
            let matched = terms.iter().filter(|term| lower.contains(*term)).count();
            if matched > 0 {
                let phrase = lower.contains(query.trim());
                let count: usize = terms.iter().map(|term| lower.matches(term).count()).sum();
                let guide = file.starts_with("docs/user") || file.starts_with("docs/tutorial");
                hits.push((
                    (matched, phrase, guide, count),
                    file.clone(),
                    start + 1,
                    heading.to_owned(),
                    paragraph,
                ));
            }
            if let Some(line) = lines[start..end]
                .iter()
                .rev()
                .find(|line| line.starts_with('#') && file.extension().is_some_and(|e| e == "md"))
            {
                heading = line;
            }
            start = end;
        }
    }
    hits.sort_by(|a, b| b.0.cmp(&a.0));
    let results: Vec<Value> = hits
        .into_iter()
        .take(limit)
        .map(|(_, file, line, heading, paragraph)| {
            let text: Vec<&str> = paragraph.lines().take(16).collect();
            json!({ "path": file, "line": line, "section": heading, "text": text.join("\n") })
        })
        .collect();
    json!({ "results": results })
}

/// Lines of one corpus file, numbered from `start` (1-based).
pub fn read(root: &Path, path: &str, start: usize, count: usize) -> Result<Value, String> {
    let wanted = Path::new(path.trim_start_matches("./"));
    if !corpus(root).iter().any(|file| file == wanted) {
        return Err(format!(
            "{path} is not readable: read_doc opens docs/user/*.md, docs/tutorial/*.md, the core language docs, lib/*.slog, tests/*.slog, and examples/; search_docs and list_examples name them"
        ));
    }
    let text = std::fs::read_to_string(root.join(wanted))
        .map_err(|error| format!("cannot read {path}: {error}"))?;
    let lines: Vec<&str> = text.lines().collect();
    let first = start.max(1);
    let last = (first + count.clamp(1, 400) - 1).min(lines.len());
    let numbered: Vec<String> = (first..=last)
        .map(|n| format!("{n:5}  {}", lines[n - 1]))
        .collect();
    Ok(
        json!({ "path": path, "lines": format!("{first}-{last} of {}", lines.len()), "text": numbered.join("\n") }),
    )
}

/// Every example and test program with a line saying what it shows: an
/// example directory's README title, else a program's first comment.
pub fn examples(root: &Path) -> Value {
    let describe = |file: &Path| -> String {
        let text = std::fs::read_to_string(root.join(file)).unwrap_or_default();
        text.lines()
            .map(str::trim)
            .find_map(|line| {
                line.strip_prefix("# ")
                    .or_else(|| line.strip_prefix(";;"))
                    .map(str::trim)
                    .filter(|l| !l.is_empty())
            })
            .unwrap_or("")
            .to_owned()
    };
    let entries: Vec<Value> = corpus(root)
        .into_iter()
        .filter(|file| file.starts_with("examples") || file.starts_with("tests"))
        .filter(|file| file.extension().is_some_and(|e| e == "slog") || file.ends_with("README.md"))
        .map(|file| json!({ "path": file, "about": describe(&file) }))
        .collect();
    json!({ "programs": entries, "note": "read one with read_doc; examples/*/README.md explains its directory" })
}

#[cfg(test)]
mod tests {
    use super::{REFERENCE, read, search};
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
            let line = REFERENCE[..REFERENCE.len() - rest.len() + open]
                .lines()
                .count()
                + 1;
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
        let directory =
            std::env::temp_dir().join(format!("studio-reference-{}", std::process::id()));
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
                        .evaluate(&lane, &file, &[], &mut |outcome| {
                            errors.extend(outcome.error.clone().map(|e| e.message))
                        })
                        .await
                        .done();
                    let error = errors.join("\n");
                    if language == "slog" && !evaluated {
                        failures.push(format!("line {line}: does not evaluate: {error}"));
                    } else if language == "slog-error" {
                        let expected = body
                            .lines()
                            .next()
                            .and_then(|first| first.strip_prefix(";; error: "));
                        match expected {
                            None => failures
                                .push(format!("line {line}: starts with no `;; error: TEXT`")),
                            Some(_) if evaluated => {
                                failures.push(format!("line {line}: evaluates, but should fail"))
                            }
                            Some(text) if !error.contains(text) => failures
                                .push(format!("line {line}: fails without {text:?}: {error}")),
                            Some(_) => {}
                        }
                        evaluated = false;
                    }
                }
                "query" => {
                    let lines: Vec<&str> = body.lines().collect();
                    for (at, query) in lines
                        .iter()
                        .enumerate()
                        .filter(|(_, query)| query.starts_with('?'))
                    {
                        if !evaluated {
                            failures
                                .push(format!("line {line}: {query} follows no evaluated program"));
                            continue;
                        }
                        let outcome = session.execute(&lane, query).await;
                        let expected = lines
                            .get(at + 1)
                            .and_then(|next| next.strip_prefix(";; => "));
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
                        let holds =
                            match expected.map(|text| text.strip_prefix("error: ").ok_or(text)) {
                                Some(Ok(text)) => refused && answer.contains(text),
                                Some(Err(text)) => !refused && answer.contains(text),
                                None => !refused,
                            };
                        if !holds {
                            let wanted = expected.unwrap_or("an answer");
                            failures.push(format!(
                                "line {line}: {query}: wanted {wanted:?}, got {answer}"
                            ));
                        }
                    }
                }
                _ => {}
            }
        }
        lane.shutdown().await;
        std::fs::remove_dir_all(&directory).expect("cleanup");
        assert!(
            failures.is_empty(),
            "the reference has drifted:\n{}",
            failures.join("\n")
        );
    }

    /// read_doc opens the corpus and nothing else: not the studio's own
    /// source, nor anything up and out of the repository.
    #[test]
    fn read_doc_opens_only_docs_and_programs() {
        let root = project_root().expect("repository root");
        assert!(read(&root, "docs/user/language.md", 1, 5).is_ok());
        assert!(read(&root, "./examples/domtree/domtree.slog", 10, 5).is_ok());
        for path in [
            "studio/src/auth.rs",
            "docs/user/../../studio/src/auth.rs",
            "../slog/Readme.md",
            "/etc/passwd",
        ] {
            assert!(read(&root, path, 1, 5).is_err(), "{path} was readable");
        }
    }

    /// A search for a primitive's behaviour finds the paragraph defining it.
    #[test]
    fn search_ranks_the_defining_paragraph_first() {
        let root = project_root().expect("repository root");
        let found = search(&root, "cget partial", 3);
        let first = &found["results"][0];
        assert!(first["text"].as_str().unwrap().contains("cget"), "{found}");
        assert!(
            first["path"].as_str().unwrap().starts_with("docs/user/"),
            "{found}"
        );
    }
}
