//! Named projects: each a tree of `.slog` files, one of them the main file
//! that evaluation runs, with its versions (studio-design.md §4.1).
//!
//! ```text
//! <data>/users/<user>/        (the studio home's users/local/ in local mode)
//!   last                  the name of the project opened last
//!   projects/<name>/
//!     project.toml        main = "x.slog"; link = "/dir" if linked
//!     files/              an unlinked project's files, as last saved
//!     synced.json         the tree last written to or read from the files
//!     objects/ versions.log refs.json drafts/      (versions.rs, store.rs)
//! ```
//!
//! A project's files live in its **directory**: the directory it is linked
//! to (`./slog studio dir/x.slog` links `dir`), or its own `files/`. Saving
//! writes the tree there, so the main file is evaluated where it lies and
//! `include "y.slog"` resolves among the project's files. Files that change
//! there behind the studio's back are noticed on open and recorded as a
//! Disk version; unsaved work is recorded first, so nothing is lost.

use crate::hash::Hash;
use crate::registry::valid_name;
use crate::store::{Files, Store, write_atomic};
use crate::versions::{History, Origin, Version};
use serde::{Deserialize, Serialize};
use std::fs;
use std::io::{self, ErrorKind};
use std::path::{Path, PathBuf};

/// One user's projects.
pub struct Projects {
    root: PathBuf,
}

#[derive(Deserialize, Serialize)]
struct Config {
    main: String,
    #[serde(default, skip_serializing_if = "Option::is_none")]
    link: Option<PathBuf>,
}

pub struct Project {
    name: String,
    dir: PathBuf,
    config: Config,
    store: Store,
    pub history: History,
}

const NEW_MAIN: &str = "main.slog";
const SYNCED: &str = "synced";

impl Projects {
    /// The projects in `user`, a user's directory.
    pub fn new(user: &Path) -> Self {
        Self {
            root: user.to_owned(),
        }
    }

    pub fn names(&self) -> io::Result<Vec<String>> {
        let mut names: Vec<String> = match fs::read_dir(self.root.join("projects")) {
            Ok(entries) => entries
                .filter_map(|entry| entry.ok()?.file_name().into_string().ok())
                .filter(|name| valid_name(name))
                .collect(),
            Err(error) if error.kind() == ErrorKind::NotFound => Vec::new(),
            Err(error) => return Err(error),
        };
        names.sort();
        Ok(names)
    }

    /// The project opened last, if it still exists.
    pub fn last(&self) -> Option<String> {
        let name = fs::read_to_string(self.root.join("last")).ok()?;
        self.dir(&name)
            .join("project.toml")
            .exists()
            .then_some(name)
    }

    /// A new unlinked project holding an empty `main.slog`.
    pub fn create(&self, name: &str) -> io::Result<()> {
        if !valid_name(name) {
            return Err(io::Error::new(
                ErrorKind::InvalidInput,
                format!("{name:?} is not a project name: use letters, digits and - _ . @"),
            ));
        }
        let dir = self.dir(name);
        fs::create_dir_all(self.root.join("projects"))?;
        fs::create_dir(&dir).map_err(|error| match error.kind() {
            ErrorKind::AlreadyExists => {
                io::Error::new(error.kind(), format!("project {name} exists"))
            }
            _ => error,
        })?;
        fs::create_dir(dir.join("files"))?;
        write_atomic(&dir.join("files").join(NEW_MAIN), b"")?;
        write_config(
            &dir,
            &Config {
                main: NEW_MAIN.to_owned(),
                link: None,
            },
        )
    }

    /// The project linked to `file`'s directory, with `file` as its main
    /// file: found, or else created and named after the directory.
    pub fn linked(&self, file: &Path) -> io::Result<String> {
        let (Some(directory), Some(main)) = (
            file.parent(),
            file.file_name().and_then(|name| name.to_str()),
        ) else {
            return Err(io::Error::new(
                ErrorKind::InvalidInput,
                format!("{} is not a file", file.display()),
            ));
        };
        let directory = fs::canonicalize(directory)?;
        for name in self.names()? {
            // A project that cannot be read is not this one; opening it
            // by name reports why.
            let Ok(mut config) = read_config(&self.dir(&name)) else { continue };
            if config.link.as_deref() == Some(&directory) {
                if config.main != main {
                    config.main = main.to_owned();
                    write_config(&self.dir(&name), &config)?;
                }
                return Ok(name);
            }
        }
        let stem: String = directory
            .file_name()
            .map(|name| name.to_string_lossy())
            .unwrap_or_default()
            .chars()
            .map(|c| if valid_name(&c.to_string()) { c } else { '-' })
            .collect();
        let stem = if valid_name(&stem) {
            stem
        } else {
            "project".to_owned()
        };
        let names = self.names()?;
        let name = std::iter::once(stem.clone())
            .chain((2..).map(|n| format!("{stem}-{n}")))
            .find(|name| !names.contains(name))
            .expect("some name is free");
        fs::create_dir_all(self.dir(&name))?;
        write_config(
            &self.dir(&name),
            &Config {
                main: main.to_owned(),
                link: Some(directory),
            },
        )?;
        Ok(name)
    }

    /// Open project `name`, and remember it as the last one. Returns the
    /// working files: the current branch's draft, or the files on disk when
    /// they changed outside the studio.
    pub fn open(&self, name: &str) -> io::Result<(Project, Files)> {
        if !valid_name(name) {
            return Err(io::Error::new(
                ErrorKind::NotFound,
                format!("no project {name:?}"),
            ));
        }
        let dir = self.dir(name);
        let config = read_config(&dir)?;
        let store = Store::open(&dir)?;
        let mut project = Project {
            name: name.to_owned(),
            history: History::open(Store::open(&dir)?)?,
            dir,
            config,
            store,
        };
        let disk = project.read_directory()?;
        let disk_tree = project.store.put_files(&disk)?;
        let synced: Option<Hash> = project.store.read(SYNCED)?;
        let mut files = match project.history.head() {
            Some(head) if synced == Some(disk_tree) => match project.history.draft()? {
                Some(draft) => draft,
                None => project.history.files(head.id)?,
            },
            head => {
                if head.is_some()
                    && let Some(draft) = project.history.draft()?
                {
                    project.history.settle(&draft)?;
                }
                project.history.record(Origin::Disk, &disk, None)?;
                project.store.write(SYNCED, &disk_tree)?;
                disk
            }
        };
        files.entry(project.config.main.clone()).or_default();
        project.history.save_draft(&files)?;
        write_atomic(&self.root.join("last"), name.as_bytes())?;
        Ok((project, files))
    }

    fn dir(&self, name: &str) -> PathBuf {
        self.root.join("projects").join(name)
    }
}

impl Project {
    pub fn name(&self) -> &str {
        &self.name
    }

    /// The project's store, for records kept beside its versions.
    pub fn store(&self) -> &Store {
        &self.store
    }

    /// The path, within the project, of the file evaluation runs.
    pub fn main(&self) -> &str {
        &self.config.main
    }

    pub fn set_main(&mut self, path: &str) -> io::Result<()> {
        let previous = std::mem::replace(&mut self.config.main, path.to_owned());
        write_config(&self.dir, &self.config).inspect_err(|_| self.config.main = previous)
    }

    /// Where the files are written, and evaluated.
    pub fn directory(&self) -> PathBuf {
        self.config
            .link
            .clone()
            .unwrap_or_else(|| self.dir.join("files"))
    }

    /// Write `files` to the project's directory and checkpoint them.
    /// Only files that differ from the last write are written, and only
    /// files the studio wrote or read are removed.
    pub fn save(&mut self, files: &Files, label: &str) -> io::Result<Option<Version>> {
        let directory = self.directory();
        let synced = self.saved()?;
        fs::create_dir_all(&directory)?;
        for (path, text) in files {
            let target = directory.join(path);
            if synced.get(path) != Some(text) || !target.exists() {
                write_atomic(&target, text.as_bytes())?;
            }
        }
        for path in synced.keys().filter(|path| !files.contains_key(*path)) {
            match fs::remove_file(directory.join(path)) {
                Err(error) if error.kind() != ErrorKind::NotFound => return Err(error),
                _ => {}
            }
        }
        self.store.write(SYNCED, &self.store.put_files(files)?)?;
        self.history.checkpoint(files, label)
    }

    /// The files as the studio last wrote them to, or read them from, the
    /// project's directory.
    pub fn saved(&self) -> io::Result<Files> {
        match self.store.read::<Hash>(SYNCED)? {
            Some(tree) => self.store.get_files(tree),
            None => Ok(Files::new()),
        }
    }

    /// The `.slog` files directly in the project's directory, under names a
    /// project file can have: hidden ones are the studio's own, such as an
    /// agent's preview.
    fn read_directory(&self) -> io::Result<Files> {
        let entries = match fs::read_dir(self.directory()) {
            Ok(entries) => entries,
            Err(error) if error.kind() == ErrorKind::NotFound => return Ok(Files::new()),
            Err(error) => return Err(error),
        };
        let mut files = Files::new();
        for entry in entries {
            let entry = entry?;
            let Ok(name) = entry.file_name().into_string() else {
                continue;
            };
            if !valid_file(&name) || !entry.file_type()?.is_file() {
                continue;
            }
            // A file that is not UTF-8 is not a program the studio can edit.
            if let Ok(text) = fs::read_to_string(entry.path()) {
                files.insert(name, text);
            }
        }
        Ok(files)
    }
}

/// A file name within a project: one that could name a project, ending in
/// `.slog`.
pub fn valid_file(path: &str) -> bool {
    valid_name(path) && path.len() > ".slog".len() && path.ends_with(".slog")
}

fn read_config(dir: &Path) -> io::Result<Config> {
    let text = fs::read_to_string(dir.join("project.toml"))?;
    toml::from_str(&text).map_err(|error| io::Error::new(ErrorKind::InvalidData, error.to_string()))
}

fn write_config(dir: &Path, config: &Config) -> io::Result<()> {
    let text = toml::to_string(config).map_err(|error| io::Error::other(error.to_string()))?;
    write_atomic(&dir.join("project.toml"), text.as_bytes())
}

#[cfg(test)]
mod tests {
    use super::{Projects, valid_file};
    use crate::store::Files;
    use crate::store::tests::Scratch;
    use crate::versions::Origin;
    use std::fs;

    fn origins(projects: &Projects, name: &str) -> Vec<Origin> {
        let (project, _) = projects.open(name).unwrap();
        project
            .history
            .versions()
            .iter()
            .map(|v| v.origin.clone())
            .collect()
    }

    #[test]
    fn a_file_opens_the_project_linked_to_its_directory() {
        let scratch = Scratch::new("linked");
        let dir = scratch.path().join("tinycfa");
        fs::create_dir(&dir).unwrap();
        fs::write(dir.join("0cfa.slog"), "include \"lib.slog\"\n").unwrap();
        fs::write(dir.join("lib.slog"), "table (t int)\n").unwrap();
        fs::write(dir.join("notes.txt"), "not a program").unwrap();
        let projects = Projects::new(&scratch.path().join("home"));

        let name = projects.linked(&dir.join("0cfa.slog")).unwrap();
        assert_eq!(name, "tinycfa");
        let (project, files) = projects.open(&name).unwrap();
        assert_eq!(
            (project.main(), project.directory()),
            ("0cfa.slog", fs::canonicalize(&dir).unwrap())
        );
        assert_eq!(files.keys().collect::<Vec<_>>(), ["0cfa.slog", "lib.slog"]);
        assert_eq!(project.history.versions()[0].origin, Origin::Disk);

        // the same directory is the same project; its other file becomes main
        assert_eq!(projects.linked(&dir.join("lib.slog")).unwrap(), "tinycfa");
        let (project, _) = projects.open("tinycfa").unwrap();
        assert_eq!(
            (project.main(), project.history.versions().len()),
            ("lib.slog", 1)
        );
        // another directory of the same name is another project
        let other = scratch.path().join("elsewhere").join("tinycfa");
        fs::create_dir_all(&other).unwrap();
        assert_eq!(
            projects.linked(&other.join("new.slog")).unwrap(),
            "tinycfa-2"
        );
        let (_, files) = projects.open("tinycfa-2").unwrap();
        assert_eq!(files, Files::from([("new.slog".to_owned(), String::new())]));
        assert_eq!(projects.names().unwrap(), ["tinycfa", "tinycfa-2"]);
        assert_eq!(projects.last().as_deref(), Some("tinycfa-2"));
    }

    /// Saving writes changed files through and removes deleted ones, but
    /// never touches a file the studio did not know.
    #[test]
    fn saving_writes_the_tree_to_the_directory() {
        let scratch = Scratch::new("save");
        let projects = Projects::new(scratch.path());
        projects.create("demo").unwrap();
        assert!(projects.create("demo").is_err());
        assert!(projects.create("../escape").is_err());
        let (mut project, mut files) = projects.open("demo").unwrap();
        assert_eq!(
            files,
            Files::from([("main.slog".to_owned(), String::new())])
        );
        let directory = project.directory();
        fs::write(directory.join("stray.slog"), "rule (s 1)\n").unwrap();

        files.insert("main.slog".into(), "include \"lib.slog\"\n".into());
        files.insert("lib.slog".into(), "table (t int)\n".into());
        let saved = project.save(&files, "save").unwrap().expect("a checkpoint");
        assert_eq!(
            saved.forms_changed,
            ["lib.slog:table:t", "main.slog:include:lib.slog"]
        );
        assert_eq!(
            fs::read_to_string(directory.join("lib.slog")).unwrap(),
            "table (t int)\n"
        );

        files.remove("lib.slog");
        project.save(&files, "save").unwrap();
        assert!(!directory.join("lib.slog").exists());
        assert!(directory.join("stray.slog").exists());
    }

    /// A file changed behind the studio's back becomes a Disk version on
    /// open, after an Auto version of the unsaved draft, which it replaces.
    #[test]
    fn a_change_on_disk_is_recorded_without_losing_unsaved_work() {
        let scratch = Scratch::new("disk");
        let dir = scratch.path().join("p");
        fs::create_dir(&dir).unwrap();
        fs::write(dir.join("p.slog"), "table (t int)\n").unwrap();
        let projects = Projects::new(&scratch.path().join("home"));
        let name = projects.linked(&dir.join("p.slog")).unwrap();
        let (project, _) = projects.open(&name).unwrap();
        let unsaved = Files::from([(
            "p.slog".to_owned(),
            "table (t int)\nrule (t 1)\n".to_owned(),
        )]);
        project.history.save_draft(&unsaved).unwrap();
        drop(project);

        // reopening without outside changes resumes the draft
        let (project, files) = projects.open(&name).unwrap();
        assert_eq!(files, unsaved);
        drop(project);

        fs::write(dir.join("p.slog"), "table (t int)\nrule (t 2)\n").unwrap();
        let (project, files) = projects.open(&name).unwrap();
        assert_eq!(files["p.slog"], "table (t int)\nrule (t 2)\n");
        assert_eq!(
            origins(&projects, &name),
            [Origin::Disk, Origin::Auto, Origin::Disk]
        );
        assert_eq!(project.history.files(2).unwrap(), unsaved);
    }

    #[test]
    fn file_names_are_plain_slog_names() {
        assert!(valid_file("lib.slog") && valid_file("a-b_c.d.slog"));
        assert!(!valid_file(".slog") && !valid_file("lib") && !valid_file("../x.slog"));
        assert!(
            !valid_file("dir/x.slog") && !valid_file(".hidden.slog") && !valid_file("a b.slog")
        );
    }
}
