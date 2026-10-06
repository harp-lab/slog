//! Starters: the repository's example programs, each offered as a new
//! project ("New from example…"), as `examples/starters.toml` lists them.
//!
//! A starter names a main program. Its project is a copy of that file and
//! of every file it includes or runs, the library's (`lib/`) too, side by
//! side: a project is one directory of files, so a directive naming a file
//! elsewhere is rewritten to name the file's copy. The project never links
//! to the examples, so editing it cannot change them.
//!
//! Each starter's scenario, `<main>.scenario.toml` beside its main file,
//! pins what the example shows; `slog studio starters` runs them all, on
//! copies made as a project's are.

use crate::forms::forms;
use crate::projects::valid_file;
use crate::registry::valid_name;
use crate::store::Files;
use serde::{Deserialize, Serialize};
use std::collections::{BTreeMap, BTreeSet};
use std::ops::Range;
use std::path::{Path, PathBuf};

/// The catalog, relative to the repository.
const CATALOG: &str = "examples/starters.toml";

#[derive(Debug, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct Catalog {
    /// The repository.
    #[serde(skip)]
    root: PathBuf,
    pub starters: Vec<Starter>,
    #[serde(default)]
    pub skipped: Vec<Skipped>,
}

/// One example, as the catalog lists it and the page offers it.
#[derive(Clone, Debug, Deserialize, Serialize)]
#[serde(deny_unknown_fields)]
pub struct Starter {
    /// The name its project gets, unless that is taken.
    pub id: String,
    pub title: String,
    /// The main file, relative to the catalog.
    #[serde(skip_serializing)]
    pub main: String,
    /// One line on what it shows.
    pub about: String,
    /// Its scenario runs only when asked for (`starters --slow`).
    #[serde(default, skip_serializing)]
    pub slow: bool,
}

/// An example that is not a starter, and why.
#[derive(Debug, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct Skipped {
    pub file: String,
    pub why: String,
}

/// A starter's project: the file names it gets, and their texts.
pub struct Copy {
    pub main: String,
    pub files: Files,
    /// The files copied, by where they are in the repository.
    sources: Vec<PathBuf>,
}

impl Catalog {
    /// The catalog of the repository at `root`.
    pub fn load(root: &Path) -> Result<Self, String> {
        let path = root.join(CATALOG);
        let text = std::fs::read_to_string(&path)
            .map_err(|error| format!("cannot read {}: {error}", path.display()))?;
        let mut catalog: Catalog =
            toml::from_str(&text).map_err(|error| format!("{}: {error}", path.display()))?;
        catalog.root = root.to_owned();
        Ok(catalog)
    }

    pub fn get(&self, id: &str) -> Option<&Starter> {
        self.starters.iter().find(|starter| starter.id == id)
    }

    fn dir(&self) -> PathBuf {
        self.root.join("examples")
    }

    /// The scenario beside `starter`'s main file.
    pub fn scenario(&self, starter: &Starter) -> PathBuf {
        self.dir().join(&starter.main).with_extension("scenario.toml")
    }

    /// `starter`'s project: its main file and every file that one includes
    /// or runs, transitively, each named by its own file name.
    pub fn copy(&self, starter: &Starter) -> Result<Copy, String> {
        let main = canonical(&self.dir().join(&starter.main))?;
        let mut names = BTreeMap::from([(main.clone(), file_name(&main)?)]);
        let mut todo = vec![main.clone()];
        let mut files = Files::new();
        while let Some(path) = todo.pop() {
            let mut text = std::fs::read_to_string(&path)
                .map_err(|error| format!("cannot read {}: {error}", path.display()))?;
            // Last first, so each range still points at its literal.
            for (range, source) in directives(&text).into_iter().rev() {
                let target = self.resolve(&path, &source)?;
                let name = match names.get(&target) {
                    Some(name) => name.clone(),
                    None => {
                        let name = file_name(&target)?;
                        if let Some((other, _)) = names.iter().find(|(_, taken)| **taken == name) {
                            return Err(format!(
                                "{} and {} would both be {name} in the project",
                                other.display(),
                                target.display()
                            ));
                        }
                        names.insert(target.clone(), name.clone());
                        todo.push(target);
                        name
                    }
                };
                if source != name {
                    text.replace_range(range, &format!("{name:?}"));
                }
            }
            files.insert(names[&path].clone(), text);
        }
        Ok(Copy { main: names[&main].clone(), files, sources: names.into_keys().collect() })
    }

    /// The file a directive in `from` names, as the compiler finds it:
    /// beside `from`, else in the library (compiler/modules.rkt).
    fn resolve(&self, from: &Path, source: &str) -> Result<PathBuf, String> {
        let beside = from.parent().unwrap_or(Path::new("")).join(source);
        let library = self.root.join("lib").join(source);
        match [beside, library].into_iter().find(|path| path.is_file()) {
            Some(path) => canonical(&path),
            None => Err(format!("{} names {source:?}, which does not exist", from.display())),
        }
    }

    /// Whatever keeps the catalog from describing every example: a starter
    /// that cannot be copied or has no scenario, an id that cannot name a
    /// project or repeats, a skipped file that is gone, and an example
    /// (a `.slog` file under examples/) that is neither a starter, nor a
    /// file one copies, nor skipped.
    pub fn problems(&self) -> Vec<String> {
        let mut problems = Vec::new();
        let mut covered = BTreeSet::new();
        let mut ids = BTreeSet::new();
        for starter in &self.starters {
            if !valid_name(&starter.id) || !ids.insert(&starter.id) {
                problems.push(format!("{:?} cannot be a starter's id: one per starter, a project name", starter.id));
            }
            match self.copy(starter) {
                Ok(copy) => covered.extend(copy.sources),
                Err(error) => problems.push(format!("starter {}: {error}", starter.id)),
            }
            if !self.scenario(starter).is_file() {
                problems.push(format!("starter {} has no scenario {}", starter.id, self.scenario(starter).display()));
            }
        }
        for skipped in &self.skipped {
            match canonical(&self.dir().join(&skipped.file)) {
                Ok(path) => {
                    covered.insert(path);
                }
                Err(error) => problems.push(format!("skipped {}: {error}", skipped.file)),
            }
        }
        let mut examples = Vec::new();
        slog_files(&self.dir(), &mut examples);
        for path in examples {
            if canonical(&path).is_ok_and(|path| !covered.contains(&path)) {
                let shown = path.strip_prefix(&self.dir()).unwrap_or(&path);
                problems.push(format!(
                    "examples/{} is in no starter: add it to {CATALOG}, as a starter or skipped",
                    shown.display()
                ));
            }
        }
        problems
    }
}

/// The sources `include`, `run` and `instantiate` directives name: each
/// string literal's place in `text`, and its contents.
fn directives(text: &str) -> Vec<(Range<usize>, String)> {
    forms(text)
        .into_iter()
        .filter(|form| matches!(form.keyword, "include" | "run" | "instantiate"))
        .filter_map(|form| {
            let after = form.start + form.keyword.len();
            let open = after + text[after..].find(|c: char| !c.is_whitespace())?;
            let rest = text[open..].strip_prefix('"')?;
            let close = rest.find('"')?;
            Some((open..open + close + 2, rest[..close].to_owned()))
        })
        .collect()
}

fn canonical(path: &Path) -> Result<PathBuf, String> {
    std::fs::canonicalize(path).map_err(|error| format!("{}: {error}", path.display()))
}

/// The name `path` gets in a project.
fn file_name(path: &Path) -> Result<String, String> {
    path.file_name()
        .and_then(|name| name.to_str())
        .filter(|name| valid_file(name))
        .map(str::to_owned)
        .ok_or_else(|| format!("{} cannot be a project's file", path.display()))
}

/// The `.slog` files under `dir`, at any depth.
fn slog_files(dir: &Path, found: &mut Vec<PathBuf>) {
    for entry in std::fs::read_dir(dir).into_iter().flatten().flatten() {
        let path = entry.path();
        if path.is_dir() {
            slog_files(&path, found);
        } else if path.extension().is_some_and(|extension| extension == "slog") {
            found.push(path);
        }
    }
}

#[cfg(test)]
mod tests {
    use super::{Catalog, directives};
    use crate::store::tests::Scratch;
    use slog_repl::server::project_root;
    use std::fs;

    /// Every example is a starter, part of one, or skipped with a reason;
    /// every starter copies and has a scenario. A new example fails here
    /// until the catalog lists it.
    #[test]
    fn the_catalog_describes_every_example() {
        let catalog = Catalog::load(&project_root().expect("repository root")).expect("the catalog");
        let problems = catalog.problems();
        assert!(problems.is_empty(), "{problems:#?}");
        assert!(catalog.get("getting-started").is_some());
    }

    #[test]
    fn directives_are_found_with_their_literals() {
        let text = "include \"a.slog\"\n;; include \"no.slog\"\nrun  \"../b.slog\"\nrule (run x)\n";
        let found: Vec<_> = directives(text)
            .into_iter()
            .map(|(range, source)| (text[range].to_owned(), source))
            .collect();
        assert_eq!(found, [("\"a.slog\"".into(), "a.slog".into()), ("\"../b.slog\"".into(), "../b.slog".into())]);
    }

    /// A copy holds the main file and what it includes and runs, from
    /// beside it, above it and the library, each under its own name with
    /// the directives naming it rewritten; nothing else is copied.
    #[test]
    fn a_copy_is_self_contained() {
        let scratch = Scratch::new("starter");
        let root = scratch.path();
        for dir in ["examples/demo", "examples/shared", "lib"] {
            fs::create_dir_all(root.join(dir)).unwrap();
        }
        let file = |path: &str, text: &str| fs::write(root.join(path), text).unwrap();
        file("examples/starters.toml", "[[starters]]\nid = \"demo\"\ntitle = \"Demo\"\nmain = \"demo/main.slog\"\nabout = \"A demo.\"\n");
        file("examples/demo/main.slog", "include \"types.slog\"\ninclude \"../shared/util.slog\"\nrun \"data.slog\"\nrule (t 1)\n");
        file("examples/demo/types.slog", "table (t int)\ninclude \"list.slog\"\n");
        file("examples/demo/data.slog", "include \"types.slog\"\n");
        file("examples/demo/unused.slog", "table (u int)\n");
        file("examples/shared/util.slog", "table (v int)\n");
        file("lib/list.slog", "table (l int)\n");

        let catalog = Catalog::load(root).unwrap();
        let copy = catalog.copy(catalog.get("demo").unwrap()).unwrap();
        assert_eq!(copy.main, "main.slog");
        assert_eq!(
            copy.files.keys().collect::<Vec<_>>(),
            ["data.slog", "list.slog", "main.slog", "types.slog", "util.slog"]
        );
        assert_eq!(
            copy.files["main.slog"],
            "include \"types.slog\"\ninclude \"util.slog\"\nrun \"data.slog\"\nrule (t 1)\n"
        );
        assert_eq!(copy.files["types.slog"], "table (t int)\ninclude \"list.slog\"\n");
        assert_eq!(copy.files["list.slog"], "table (l int)\n");

        // the unused file is in no starter, and the starter has no scenario
        let problems = catalog.problems();
        assert_eq!(problems.len(), 2, "{problems:#?}");
        assert!(problems[0].contains("has no scenario"));
        assert!(problems[1].contains("examples/demo/unused.slog is in no starter"));

        // two files that would share a name in the project
        file("examples/demo/util.slog", "table (w int)\n");
        file("examples/demo/types.slog", "include \"util.slog\"\n");
        let error = catalog.copy(catalog.get("demo").unwrap()).err().unwrap();
        assert!(error.contains("would both be util.slog"), "{error}");
    }
}
