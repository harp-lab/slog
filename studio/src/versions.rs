//! A project's versions: a DAG of snapshots of its whole file tree, and the
//! branches that point into it (studio-design.md §4.2).
//!
//! A version is created when
//! - **Auto**: the working files' normalized text changed (a form was
//!   edited, added or removed, or a file appeared or went) and editing then
//!   paused; reformatting alone never makes one (`settle`);
//! - **Checkpoint**: the program was saved or evaluated (`checkpoint`);
//! - **Revert**: an earlier version was restored onto the current branch;
//! - **Branch**: a new branch was started from an earlier version;
//! - **Disk**: the files on disk changed outside the studio;
//! - **Accept**: an agent's proposal was accepted (`record`).
//!
//! Each version names the forms that differ from its first parent, as
//! `file:key` (`forms.rs`), so history can say what changed.
//!
//! Persistence (`store.rs`): versions are appended to `versions.log`,
//! branch heads live in `refs.json`, and the working files of each branch,
//! saved or not, in `drafts/<branch>.json`.

use crate::forms;
use crate::hash::Hash;
use crate::store::{Files, Store};
use serde::{Deserialize, Serialize};
use std::collections::{BTreeMap, BTreeSet};
use std::io::{self, ErrorKind};
use std::time::{SystemTime, UNIX_EPOCH};

#[derive(Clone, Debug, Deserialize, Eq, PartialEq, Serialize)]
pub struct Version {
    /// 1, 2, 3, … in the order versions were made.
    pub id: u64,
    /// The first parent is the version this one was made from; none for
    /// the first version.
    pub parents: Vec<u64>,
    pub tree: Hash,
    /// Milliseconds since the Unix epoch.
    pub created: u64,
    pub origin: Origin,
    #[serde(default, skip_serializing_if = "Option::is_none")]
    pub label: Option<String>,
    /// `file:key` of each form that differs from the first parent.
    pub forms_changed: Vec<String>,
}

#[derive(Clone, Debug, Deserialize, Eq, PartialEq, Serialize)]
#[serde(tag = "kind", rename_all = "kebab-case")]
pub enum Origin {
    Auto,
    Checkpoint,
    Revert {
        to: u64,
    },
    Branch {
        from: u64,
    },
    Disk,
    /// An accepted proposal; its label says what was asked. (The review
    /// model will add the changeset and thread it came from.)
    Accept,
}

/// The branches, and the one new versions go on.
#[derive(Clone, Debug, Deserialize, Eq, PartialEq, Serialize)]
pub struct Refs {
    pub current: String,
    /// Branch name -> its newest version.
    pub branches: BTreeMap<String, u64>,
}

pub struct History {
    store: Store,
    versions: Vec<Version>,
    refs: Refs,
}

const LOG: &str = "versions";
const REFS: &str = "refs";
const FIRST_BRANCH: &str = "main";

impl History {
    pub fn open(store: Store) -> io::Result<Self> {
        let versions: Vec<Version> = store.load_log(LOG)?;
        if let Some((at, version)) = versions
            .iter()
            .enumerate()
            .find(|(at, v)| v.id != *at as u64 + 1)
        {
            return Err(invalid(format!(
                "version {} is record {} of the log",
                version.id,
                at + 1
            )));
        }
        let refs = store.read(REFS)?.unwrap_or_else(|| Refs {
            current: FIRST_BRANCH.to_owned(),
            branches: BTreeMap::new(),
        });
        // A version is logged before any branch points at it.
        if let Some((branch, id)) = refs
            .branches
            .iter()
            .find(|(_, id)| **id as usize > versions.len())
        {
            return Err(invalid(format!(
                "branch {branch} names version {id}, which is not logged"
            )));
        }
        Ok(Self {
            store,
            versions,
            refs,
        })
    }

    pub fn versions(&self) -> &[Version] {
        &self.versions
    }

    pub fn refs(&self) -> &Refs {
        &self.refs
    }

    /// The newest version on the current branch.
    pub fn head(&self) -> Option<&Version> {
        let id = *self.refs.branches.get(&self.refs.current)?;
        Some(&self.versions[id as usize - 1])
    }

    pub fn files(&self, id: u64) -> io::Result<Files> {
        let version = self.version(id)?;
        self.store.get_files(version.tree)
    }

    /// Record `files` as a new version on the current branch, after its
    /// head. Every other way to make a version comes through here; it is
    /// also the one for callers outside this module, such as accepting an
    /// agent's proposal (`Origin::Accept`, with the request as `label`).
    pub fn record(
        &mut self,
        origin: Origin,
        files: &Files,
        label: Option<String>,
    ) -> io::Result<Version> {
        let parent = self.head_files()?;
        let version = Version {
            id: self.versions.len() as u64 + 1,
            parents: self.head().map(|head| head.id).into_iter().collect(),
            tree: self.store.put_files(files)?,
            created: SystemTime::now()
                .duration_since(UNIX_EPOCH)
                .map_or(0, |since| since.as_millis() as u64),
            origin,
            label,
            forms_changed: forms_changed(&parent, files),
        };
        self.store.append_log(LOG, &version)?;
        self.versions.push(version.clone());
        self.refs
            .branches
            .insert(self.refs.current.clone(), version.id);
        self.store.write(REFS, &self.refs)?;
        Ok(version)
    }

    /// An Auto version of `files`, if their normalized text differs from
    /// the head's: called when editing pauses.
    pub fn settle(&mut self, files: &Files) -> io::Result<Option<Version>> {
        if normalized(files) == normalized(&self.head_files()?) {
            return Ok(None);
        }
        self.record(Origin::Auto, files, None).map(Some)
    }

    /// A Checkpoint of `files`, called when they are saved or evaluated,
    /// unless the head already is one of exactly these files. A checkpoint
    /// over an Auto head of the same files still marks the point.
    pub fn checkpoint(&mut self, files: &Files, label: &str) -> io::Result<Option<Version>> {
        if let Some(head) = self.head()
            && head.origin != Origin::Auto
            && head.tree == self.store.put_files(files)?
        {
            return Ok(None);
        }
        self.record(Origin::Checkpoint, files, Some(label.to_owned()))
            .map(Some)
    }

    /// Restore version `to`'s files as a new version on the current branch.
    pub fn revert(&mut self, to: u64) -> io::Result<(Version, Files)> {
        let files = self.files(to)?;
        let version = self.record(Origin::Revert { to }, &files, None)?;
        Ok((version, files))
    }

    /// Start a new branch at version `from` and make it current; its first
    /// version restores `from`'s files.
    pub fn branch(&mut self, from: u64) -> io::Result<(Version, Files)> {
        let files = self.files(from)?;
        let name = (2..)
            .map(|n| format!("branch-{n}"))
            .find(|name| !self.refs.branches.contains_key(name))
            .expect("some branch name is free");
        self.refs.branches.insert(name.clone(), from);
        self.refs.current = name;
        let version = self.record(Origin::Branch { from }, &files, None)?;
        Ok((version, files))
    }

    /// The current branch's working files as last saved by `save_draft`.
    pub fn draft(&self) -> io::Result<Option<Files>> {
        self.store.read(&draft_name(&self.refs.current))
    }

    pub fn save_draft(&self, files: &Files) -> io::Result<()> {
        self.store.write(&draft_name(&self.refs.current), files)
    }

    fn version(&self, id: u64) -> io::Result<&Version> {
        id.checked_sub(1)
            .and_then(|at| self.versions.get(at as usize))
            .ok_or_else(|| io::Error::new(ErrorKind::NotFound, format!("no version {id}")))
    }

    fn head_files(&self) -> io::Result<Files> {
        match self.head() {
            Some(head) => self.store.get_files(head.tree),
            None => Ok(Files::new()),
        }
    }
}

fn draft_name(branch: &str) -> String {
    format!("drafts/{branch}")
}

fn normalized(files: &Files) -> BTreeMap<&str, String> {
    files
        .iter()
        .map(|(path, text)| (path.as_str(), forms::normalize(text)))
        .collect()
}

/// `file:key` of each form that differs between two trees; a file present
/// in only one counts as empty in the other.
fn forms_changed<'a>(before: &'a Files, after: &'a Files) -> Vec<String> {
    let paths: BTreeSet<&String> = before.keys().chain(after.keys()).collect();
    paths
        .into_iter()
        .flat_map(|path| {
            let text = |files: &'a Files| files.get(path).map_or("", String::as_str);
            forms::changed(text(before), text(after))
                .into_iter()
                .map(move |key| format!("{path}:{key}"))
        })
        .collect()
}

fn invalid(message: String) -> io::Error {
    io::Error::new(ErrorKind::InvalidData, message)
}

#[cfg(test)]
mod tests {
    use super::{History, Origin};
    use crate::store::tests::Scratch;
    use crate::store::{Files, Store};

    const PROGRAM: &str = "table (edge int int)\ntable (path int int)\n\
        rule (edge 1 2) (edge 2 3)\nrule (edge X Y) --> (path X Y)\n";

    fn main(text: &str) -> Files {
        Files::from([("main.slog".to_owned(), text.to_owned())])
    }

    fn history(scratch: &Scratch) -> History {
        History::open(Store::open(scratch.path()).unwrap()).unwrap()
    }

    /// The current branch's first-parent chain, oldest first, as (id, origin).
    fn chain(history: &History) -> Vec<(u64, Origin)> {
        let mut chain = Vec::new();
        let mut next = history.head().map(|head| head.id);
        while let Some(id) = next {
            let version = &history.versions()[id as usize - 1];
            chain.push((id, version.origin.clone()));
            next = version.parents.first().copied();
        }
        chain.reverse();
        chain
    }

    #[test]
    fn only_a_change_to_a_form_makes_an_auto_version() {
        let scratch = Scratch::new("auto");
        let mut history = history(&scratch);
        let first = history
            .settle(&main(PROGRAM))
            .unwrap()
            .expect("a first version");
        assert_eq!(first.parents, Vec::<u64>::new());
        assert_eq!(
            first.forms_changed,
            [
                "main.slog:table:edge",
                "main.slog:table:path",
                "main.slog:rule→edge",
                "main.slog:rule→path"
            ]
        );

        let reformatted = PROGRAM
            .replace(" --> ", "\n    -->  ")
            .replace('\n', "\n;; a comment\n\n");
        assert_eq!(history.settle(&main(&reformatted)).unwrap(), None);

        let edited = reformatted.replace("(edge 2 3)", "(edge 2 4)");
        let second = history
            .settle(&main(&edited))
            .unwrap()
            .expect("a form changed");
        assert_eq!(
            (second.parents.as_slice(), second.origin.clone()),
            (&[1][..], Origin::Auto)
        );
        assert_eq!(second.forms_changed, ["main.slog:rule→edge"]);
        // the version keeps the text as written, layout and all
        assert_eq!(history.files(2).unwrap(), main(&edited));
        assert_eq!(history.settle(&main(&edited)).unwrap(), None);

        // a new file is a change even while it is empty
        let mut two = main(&edited);
        two.insert("lib.slog".to_owned(), String::new());
        assert!(history.settle(&two).unwrap().is_some());
    }

    #[test]
    fn a_checkpoint_marks_new_files_or_an_auto_head_once() {
        let scratch = Scratch::new("checkpoint");
        let mut history = history(&scratch);
        history.settle(&main(PROGRAM)).unwrap();
        // the same files as an Auto head: marked
        let run = history
            .checkpoint(&main(PROGRAM), "run")
            .unwrap()
            .expect("marked");
        assert_eq!(run.forms_changed, Vec::<String>::new());
        assert_eq!(run.label.as_deref(), Some("run"));
        assert_eq!(history.checkpoint(&main(PROGRAM), "run").unwrap(), None);
        // a checkpoint keeps the exact text, so layout alone counts here
        let spaced = format!("{PROGRAM}\n\n");
        assert!(
            history
                .checkpoint(&main(&spaced), "save")
                .unwrap()
                .is_some()
        );
        assert_eq!(history.files(3).unwrap(), main(&spaced));
    }

    #[test]
    fn a_revert_restores_old_files_as_a_new_version_on_the_branch() {
        let scratch = Scratch::new("revert");
        let mut history = history(&scratch);
        history.settle(&main(PROGRAM)).unwrap();
        let edited = PROGRAM.replace("(edge 2 3)", "(edge 2 4)");
        history.settle(&main(&edited)).unwrap();

        let (revert, files) = history.revert(1).unwrap();
        assert_eq!(files, main(PROGRAM));
        assert_eq!((revert.id, revert.parents.clone()), (3, vec![2]));
        assert_eq!(revert.origin, Origin::Revert { to: 1 });
        assert_eq!(revert.forms_changed, ["main.slog:rule→edge"]);
        assert_eq!(
            chain(&history),
            [
                (1, Origin::Auto),
                (2, Origin::Auto),
                (3, Origin::Revert { to: 1 })
            ]
        );
        assert!(history.revert(9).is_err());
    }

    #[test]
    fn a_branch_starts_from_an_old_version_and_leaves_the_old_branch_alone() {
        let scratch = Scratch::new("branch");
        let mut history = history(&scratch);
        history.settle(&main(PROGRAM)).unwrap();
        let edited = PROGRAM.replace("(edge 2 3)", "(edge 2 4)");
        history.settle(&main(&edited)).unwrap();

        let (branch, files) = history.branch(1).unwrap();
        assert_eq!(files, main(PROGRAM));
        assert_eq!(
            (branch.parents.clone(), branch.origin.clone()),
            (vec![1], Origin::Branch { from: 1 })
        );
        assert_eq!(
            branch.forms_changed,
            Vec::<String>::new(),
            "it changes nothing from where it starts"
        );
        assert_eq!(history.refs().current, "branch-2");
        assert_eq!(history.refs().branches["main"], 2);

        let grown = format!("{PROGRAM}table (reach int)\n");
        history.settle(&main(&grown)).unwrap();
        assert_eq!(
            chain(&history),
            [
                (1, Origin::Auto),
                (3, Origin::Branch { from: 1 }),
                (4, Origin::Auto)
            ]
        );
        assert_eq!(history.refs().branches["main"], 2);

        // drafts are per branch
        history.save_draft(&main(&grown)).unwrap();
        let reopened = History::open(Store::open(scratch.path()).unwrap()).unwrap();
        assert_eq!(reopened.versions(), history.versions());
        assert_eq!(reopened.refs(), history.refs());
        assert_eq!(reopened.draft().unwrap(), Some(main(&grown)));
    }
}
