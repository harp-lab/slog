//! The top-level forms of Slog source, and which of them an edit changed.
//!
//! Forms are not parenthesized: a form starts at a top-level keyword
//! appearing at bracket depth 0 and runs to the next one (compiler/parser.rkt
//! `top-level-keywords`, lexer.rkt for the token rules). `forms` is a port of
//! `web/forms.js`, which the editor runs at keystroke rate; a test runs both
//! on the same sources and requires the same answer.
//!
//! On top of the split, each form gets a key naming it for a person
//! (`table:edge`, `rule→path`, `include:lib.slog`) and a normalized text with
//! comments dropped and whitespace collapsed, so that reformatting changes
//! nothing and editing a form changes exactly that form
//! (studio-design.md §5.2).

use std::collections::HashMap;

const KEYWORDS: [&str; 15] = [
    "def",
    "rule",
    "enum",
    "table",
    "struct",
    "union",
    "demand",
    "extern",
    "lattice",
    "include",
    "instantiate",
    "run",
    "let",
    "import",
    "export",
];

/// A top-level form, located by its keyword, which is where the compiler
/// locates it. Lines and columns are 1-based; columns count UTF-16 units, as
/// the editor does.
#[derive(Clone, Debug, Eq, PartialEq)]
pub struct Form {
    pub keyword: &'static str,
    pub line: u32,
    pub column: u32,
    /// The form ends on the line before the next form starts, or on that
    /// line if both share it.
    pub end_line: u32,
    /// Byte offset of the keyword.
    pub start: usize,
}

pub fn forms(text: &str) -> Vec<Form> {
    let mut lexer = Lexer::new(text);
    let mut depth = 0usize;
    let mut found: Vec<Form> = Vec::new();
    while let Some(token) = lexer.next() {
        match token.kind {
            Kind::Open => depth += 1,
            Kind::Close => depth = depth.saturating_sub(1),
            Kind::Word if depth == 0 => {
                let word = &text[token.start..token.end];
                let Some(keyword) = KEYWORDS.into_iter().find(|keyword| *keyword == word) else {
                    continue;
                };
                if let Some(previous) = found.last_mut() {
                    previous.end_line = previous.line.max(token.line - 1);
                }
                found.push(Form {
                    keyword,
                    line: token.line,
                    column: token.column,
                    end_line: token.line,
                    start: token.start,
                });
            }
            _ => {}
        }
    }
    if let Some(last) = found.last_mut() {
        last.end_line = last.line.max(lexer.line - u32::from(text.ends_with('\n')));
    }
    found
}

/// The form keys whose content differs between two texts of one file: forms
/// edited, added or removed. Forms are compared by normalized text, so
/// moving a form or reformatting it is not a change. Keys appear once each,
/// those of `after` first.
pub fn changed(before: &str, after: &str) -> Vec<String> {
    let before = anchors(before);
    let after = anchors(after);
    let mut unmatched: HashMap<(&str, &str), usize> = HashMap::new();
    for anchor in &before {
        *unmatched.entry((&anchor.key, &anchor.normal)).or_default() += 1;
    }
    let mut keys: Vec<&str> = Vec::new();
    for anchor in &after {
        match unmatched.get_mut(&(anchor.key.as_str(), anchor.normal.as_str())) {
            Some(count) if *count > 0 => *count -= 1,
            _ => keys.push(&anchor.key),
        }
    }
    for anchor in &before {
        if let Some(count) = unmatched.get_mut(&(anchor.key.as_str(), anchor.normal.as_str()))
            && *count > 0
        {
            *count -= 1;
            keys.push(&anchor.key);
        }
    }
    let mut seen = std::collections::HashSet::new();
    keys.into_iter()
        .filter(|key| seen.insert(*key))
        .map(str::to_owned)
        .collect()
}

/// `text` with comments dropped and each run of whitespace collapsed to one
/// space, or to nothing beside a bracket or at either end. Strings and refs
/// are kept as written.
pub fn normalize(text: &str) -> String {
    let mut normal = String::with_capacity(text.len());
    let mut previous: Option<Kind> = None;
    let mut space = false;
    for token in Lexer::new(text) {
        let source = &text[token.start..token.end];
        if token.kind == Kind::Comment || (token.kind == Kind::Other && source.trim().is_empty()) {
            space = true;
            continue;
        }
        let bracket = |kind| matches!(kind, Kind::Open | Kind::Close);
        if space && previous.is_some_and(|kind| !bracket(kind)) && !bracket(token.kind) {
            normal.push(' ');
        }
        normal.push_str(source);
        previous = Some(token.kind);
        space = false;
    }
    normal
}

/// A form's name for a person, and its content for comparison.
struct Anchor {
    key: String,
    normal: String,
}

fn anchors(text: &str) -> Vec<Anchor> {
    let found = forms(text);
    let ends = found
        .iter()
        .skip(1)
        .map(|form| form.start)
        .chain([text.len()]);
    found
        .iter()
        .zip(ends)
        .map(|(form, end)| {
            let source = &text[form.start..end];
            Anchor {
                key: key(form.keyword, source),
                normal: normalize(source),
            }
        })
        .collect()
}

/// `kind:name` for a declaration, `kind:path` (with ` as alias`) for a form
/// naming a file, `rule→heads` for a rule, else the keyword.
fn key(keyword: &str, source: &str) -> String {
    let tokens: Vec<(Kind, &str)> = Lexer::new(source)
        .map(|token| (token.kind, &source[token.start..token.end]))
        .filter(|(kind, text)| {
            *kind != Kind::Comment && !(*kind == Kind::Other && text.trim().is_empty())
        })
        .collect();
    match keyword {
        "table" | "struct" | "union" | "enum" | "lattice" | "demand" | "extern" => {
            match tokens.windows(2).find(|pair| pair[0] == (Kind::Open, "(")) {
                Some([_, (Kind::Word, name)]) => format!("{keyword}:{name}"),
                _ => keyword.to_owned(),
            }
        }
        "include" | "run" | "instantiate" => {
            let Some(at) = tokens.iter().position(|(kind, _)| *kind == Kind::Str) else {
                return keyword.to_owned();
            };
            let path = tokens[at].1.trim_matches('"');
            match tokens.get(at + 1..at + 3) {
                Some([(Kind::Word, "as"), (Kind::Word, alias)]) => {
                    format!("{keyword}:{path} as {alias}")
                }
                _ => format!("{keyword}:{path}"),
            }
        }
        "rule" => {
            let heads = heads(&tokens);
            if heads.is_empty() {
                keyword.to_owned()
            } else {
                format!("rule→{}", heads.join(","))
            }
        }
        _ => keyword.to_owned(),
    }
}

/// The relations a rule derives: the atoms after its last `-->`, before its
/// first `<--`, or all of them in a rule with neither (a fact block). Each
/// once, in order.
fn heads<'a>(tokens: &[(Kind, &'a str)]) -> Vec<&'a str> {
    let mut atoms: Vec<(usize, &str)> = Vec::new();
    let mut forward = None;
    let mut backward = None;
    let mut depth = 0usize;
    for (at, (kind, text)) in tokens.iter().enumerate() {
        match kind {
            Kind::Open => {
                if depth == 0
                    && *text == "("
                    && let Some((Kind::Word, name)) = tokens.get(at + 1)
                {
                    atoms.push((at, name));
                }
                depth += 1;
            }
            Kind::Close => depth = depth.saturating_sub(1),
            Kind::Other if depth == 0 => {
                let arrow = |a: &str, b: &str, c: &str| {
                    tokens
                        .get(at..at + 3)
                        .is_some_and(|run| run.iter().map(|(_, text)| *text).eq([a, b, c]))
                };
                if arrow("-", "-", ">") {
                    forward = Some(at);
                } else if arrow("<", "-", "-") && backward.is_none() {
                    backward = Some(at);
                }
            }
            _ => {}
        }
    }
    let mut heads: Vec<&str> = Vec::new();
    for (at, name) in atoms {
        let head = match (forward, backward) {
            (Some(arrow), _) => at > arrow,
            (None, Some(arrow)) => at < arrow,
            (None, None) => true,
        };
        if head && !heads.contains(&name) {
            heads.push(name);
        }
    }
    heads
}

#[derive(Clone, Copy, Debug, Eq, PartialEq)]
enum Kind {
    /// `;;` to the end of the line.
    Comment,
    /// `"…"`, which may span lines; a backslash escapes the next character.
    Str,
    /// `'…'` at a token start, on one line.
    Ref,
    Open,
    Close,
    /// An identifier, which may contain `'` after its first character.
    Word,
    /// Any other single character, whitespace included.
    Other,
}

struct Token {
    kind: Kind,
    start: usize,
    end: usize,
    line: u32,
    column: u32,
}

/// Slog's tokens as far as finding forms needs them: the character rules of
/// `web/forms.js`, which follow lexer.rkt.
struct Lexer<'a> {
    text: &'a str,
    at: usize,
    line: u32,
    column: u32,
}

impl<'a> Lexer<'a> {
    fn new(text: &'a str) -> Self {
        Self {
            text,
            at: 0,
            line: 1,
            column: 1,
        }
    }

    fn peek(&self) -> Option<char> {
        self.text[self.at..].chars().next()
    }

    fn advance(&mut self) {
        let Some(c) = self.peek() else { return };
        self.at += c.len_utf8();
        if c == '\n' {
            self.line += 1;
            self.column = 1;
        } else {
            self.column += c.len_utf16() as u32;
        }
    }

    /// Advance up to (not over) the first character `stop` accepts, or the
    /// end; a backslash takes the character after it along.
    fn advance_escaped_until(&mut self, stop: impl Fn(char) -> bool) {
        while let Some(c) = self.peek()
            && !stop(c)
        {
            self.advance();
            if c == '\\' {
                self.advance();
            }
        }
    }
}

impl Iterator for Lexer<'_> {
    type Item = Token;

    fn next(&mut self) -> Option<Token> {
        let c = self.peek()?;
        let (start, line, column) = (self.at, self.line, self.column);
        let word = |c: char| c.is_ascii_alphanumeric() || c == '_';
        let kind = if self.text[start..].starts_with(";;") {
            while self.peek().is_some_and(|c| c != '\n') {
                self.advance();
            }
            Kind::Comment
        } else if c == '"' {
            self.advance();
            self.advance_escaped_until(|c| c == '"');
            self.advance();
            Kind::Str
        } else if c == '\'' {
            // An unclosed ref ends at, and takes, its line's newline.
            self.advance();
            self.advance_escaped_until(|c| c == '\'' || c == '\n');
            self.advance();
            Kind::Ref
        } else if word(c) {
            while self.peek().is_some_and(|c| word(c) || c == '\'') {
                self.advance();
            }
            Kind::Word
        } else {
            self.advance();
            match c {
                '(' | '[' | '{' => Kind::Open,
                ')' | ']' | '}' => Kind::Close,
                _ => Kind::Other,
            }
        };
        Some(Token {
            kind,
            start,
            end: self.at,
            line,
            column,
        })
    }
}

#[cfg(test)]
mod tests {
    use super::{changed, forms, key, normalize};
    use serde_json::{Value, json};
    use std::io::Write;
    use std::path::Path;
    use std::process::{Command, Stdio};

    /// Sources that exercise each rule of the scanner.
    const CASES: &[&str] = &[
        "",
        "table (edge int int)\nrule (edge 1 2)\n",
        "table (edge int int)\nrule (edge 1 2)",
        "\n\n;; a header comment naming rule and table\n\ntable (t int)\n\n\n",
        "rule (p X) --> (q X) rule (q 1)\n",
        "rule (p \"a string with\nrule inside and \\\" an escape\") --> (q 1)\ntable (q int)\n",
        "rule (p 'a ref with rule') --> (q 1)\ntable (q int)\n",
        "rule (p 'unclosed ref rule\ntable (q int)\n",
        "rule (x' y'') --> (rule' 1)\ntable (rule' int)\n",
        "rule (p [table x] {run y}) --> (q 1)\n",
        ")) ] table (t int)\nrule (t 1)\n",
        "(((\ntable (t int)\n",
        ";; é ü ✓\n  rule (é 1) 𝔸 rule (b 2)\n\"𝔸\\𝔸\" table (t int)",
        "def x let y import z export w lattice (l (max int)) demand (d int) int\n",
        "include \"lib.slog\"\ninstantiate \"g.slog\" as left\nrun \"p.slog\"\n",
        "rule\n",
        "  \n\t rule (a)\n\n\n\nrule (b)\n\n",
        "\"unterminated string\nrule (a)\n",
        "rule (a) ;; trailing rule comment\n;; table\nrule (b)",
        "3rule rule_x rule",
    ];

    fn rust_forms(text: &str) -> Value {
        forms(text)
            .into_iter()
            .map(|form| {
                json!({
                    "keyword": form.keyword,
                    "line": form.line,
                    "column": form.column,
                    "endLine": form.end_line,
                })
            })
            .collect()
    }

    /// Every `.slog` file in the repository, outside build output.
    fn repository_sources() -> Vec<String> {
        fn walk(dir: &Path, sources: &mut Vec<String>) {
            let Ok(entries) = std::fs::read_dir(dir) else {
                return;
            };
            for entry in entries.flatten() {
                let path = entry.path();
                let name = entry.file_name();
                let name = name.to_string_lossy();
                if path.is_dir() {
                    if !name.starts_with('.')
                        && !matches!(name.as_ref(), "target" | "build" | "out" | "compiled")
                    {
                        walk(&path, sources);
                    }
                } else if name.ends_with(".slog")
                    && let Ok(text) = std::fs::read_to_string(&path)
                {
                    sources.push(text);
                }
            }
        }
        let mut sources = Vec::new();
        walk(
            &slog_repl::server::project_root().expect("repository root"),
            &mut sources,
        );
        sources
    }

    /// The scanner splits every source exactly as `web/forms.js` does. Needs
    /// `node`; without it the test says so and passes.
    #[test]
    fn splits_exactly_as_the_editor_does() {
        let mut sources: Vec<String> = CASES.iter().map(|case| case.to_string()).collect();
        sources.extend(repository_sources());
        assert!(
            sources.len() > 100,
            "the repository's programs are part of the corpus"
        );

        // By its file URL, so its own imports (lexer.js) resolve; and only
        // the fields both sides have (its offsets count UTF-16 units).
        let script = "import { readFileSync } from 'node:fs';\n\
            import { pathToFileURL } from 'node:url';\n\
            const { forms } = await import(pathToFileURL(process.argv[1]));\n\
            const inputs = JSON.parse(readFileSync(0, 'utf8'));\n\
            const shared = ({ keyword, line, column, endLine }) => ({ keyword, line, column, endLine });\n\
            process.stdout.write(JSON.stringify(inputs.map((text) => forms(text).map(shared))));";
        let forms_js = Path::new(env!("CARGO_MANIFEST_DIR")).join("web/forms.js");
        let child = Command::new("node")
            .args(["--input-type=module", "-e", script])
            .arg(&forms_js)
            .stdin(Stdio::piped())
            .stdout(Stdio::piped())
            .spawn();
        let Ok(mut child) = child else {
            eprintln!("node is not installed: skipping the comparison with web/forms.js");
            return;
        };
        child
            .stdin
            .take()
            .unwrap()
            .write_all(serde_json::to_string(&sources).unwrap().as_bytes())
            .unwrap();
        let output = child.wait_with_output().unwrap();
        assert!(output.status.success(), "node failed");
        let expected: Vec<Value> = serde_json::from_slice(&output.stdout).unwrap();
        assert_eq!(expected.len(), sources.len());
        for (source, expected) in sources.iter().zip(expected) {
            assert_eq!(rust_forms(source), expected, "source:\n{source}");
        }
    }

    #[test]
    fn normalizing_ignores_layout_and_comments_but_not_content() {
        let text = "rule (path X Y) (edge Y Z) --> (path X Z)";
        assert_eq!(normalize(text), "rule(path X Y)(edge Y Z)-->(path X Z)");
        assert_eq!(
            normalize("rule ( path X Y )\n    (edge Y Z) ;; extend\n  -->  (path X Z)\n"),
            normalize(text)
        );
        // inside a string, layout is content
        assert_ne!(
            normalize("rule (p \"a  b\")"),
            normalize("rule (p \"a b\")")
        );
        assert_ne!(
            normalize("rule (p \"a ;; b\")"),
            normalize("rule (p \"a\")")
        );
        // so is the space between two tokens
        assert_ne!(normalize("(p X --> Y)"), normalize("(p X - -> Y)"));
        assert_ne!(normalize("(p a b)"), normalize("(p ab)"));
    }

    #[test]
    fn forms_are_keyed_by_what_they_declare_derive_or_name() {
        let cases = [
            ("table", "table (edge int int)", "table:edge"),
            (
                "union",
                "union (expr (Var int) (App expr expr))",
                "union:expr",
            ),
            (
                "extern",
                "extern smt (smt_qsat formula) int",
                "extern:smt_qsat",
            ),
            (
                "include",
                "include \"../lib/list.slog\"",
                "include:../lib/list.slog",
            ),
            (
                "instantiate",
                "instantiate \"g.slog\" as left with x = y",
                "instantiate:g.slog as left",
            ),
            ("rule", "rule (edge X Y) --> (path X Y)", "rule→path"),
            (
                "rule",
                "rule (path X Z) <-- (path X Y) (edge Y Z)",
                "rule→path",
            ),
            (
                "rule",
                "rule (edge 1 2) (edge 2 3) (node 1)",
                "rule→edge,node",
            ),
            ("rule", "rule (a X) --> (b X) (c X) (b 1)", "rule→b,c"),
            ("rule", "rule ;; empty\n", "rule"),
            ("def", "def (f x) = x", "def"),
        ];
        for (keyword, source, expected) in cases {
            assert_eq!(key(keyword, source), expected, "{source}");
        }
    }

    #[test]
    fn only_forms_whose_content_changed_are_reported() {
        let program = "table (edge int int)\ntable (path int int)\n\
            rule (edge 1 2) (edge 2 3)\n\
            rule (edge X Y) --> (path X Y)\n\
            rule (path X Y) (edge Y Z) --> (path X Z)\n";
        assert_eq!(changed(program, program), Vec::<String>::new());

        let reformatted = program
            .replace(" --> ", "\n  --> ")
            .replace('\n', "\n\n;; note\n");
        assert_eq!(changed(program, &reformatted), Vec::<String>::new());

        // the order of forms does not matter in Datalog
        let mut lines: Vec<&str> = program.lines().collect();
        lines.reverse();
        assert_eq!(changed(program, &lines.join("\n")), Vec::<String>::new());

        let edited = program.replace("(edge 2 3)", "(edge 2 4)");
        assert_eq!(changed(program, &edited), ["rule→edge"]);

        let grown = format!("{program}table (reach int)\nrule (path 1 X) --> (reach X)\n");
        assert_eq!(changed(program, &grown), ["table:reach", "rule→reach"]);
        assert_eq!(changed(&grown, program), ["table:reach", "rule→reach"]);

        // two rules for one relation: editing either names the relation once
        let both = program
            .replace("(path X Y)\n", "(path Y X)\n")
            .replace("(path X Z)", "(path Z X)");
        assert_eq!(changed(program, &both), ["rule→path"]);
    }
}
