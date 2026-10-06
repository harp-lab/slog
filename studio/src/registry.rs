//! Which Studio serves a request: one per (user, project), created on first
//! use, each with its own lane.
//!
//! A project is a directory `users/<user>/projects/<name>/` under the data
//! directory, evaluated from its `main.slog`; the empty name is the user's
//! default project. In local mode the default is instead the file named on
//! the command line. A user can reach only their own directory: the user
//! comes from the login, never from the request, and a name is one path
//! segment.

use crate::lane::{Lane, Mode};
use crate::studio::Studio;
use std::collections::HashMap;
use std::path::PathBuf;
use std::sync::{Arc, Mutex};

/// The one user of local mode.
pub const LOCAL_USER: &str = "local";

/// The project a user gets when they name none.
const DEFAULT_PROJECT: &str = "scratch";

/// Whether `name` can name a user or a project: one path segment of
/// letters, digits and `_ . @ -`, not starting with `.`.
pub fn valid_name(name: &str) -> bool {
    !name.is_empty()
        && name.len() <= 64
        && !name.starts_with('.')
        && name.bytes().all(|byte| byte.is_ascii_alphanumeric() || b"_.@-".contains(&byte))
}

pub struct Registry {
    /// The repository lanes run in.
    root: PathBuf,
    data: PathBuf,
    mode: Mode,
    /// Local mode's default project: the file named on the command line.
    linked: Option<PathBuf>,
    /// By program file, so no two Studios ever hold one file.
    open: Mutex<HashMap<PathBuf, Arc<Studio>>>,
}

impl Registry {
    pub fn new(root: PathBuf, data: PathBuf, mode: Mode, linked: Option<PathBuf>) -> Self {
        Self {
            root,
            data,
            mode,
            linked,
            open: Mutex::new(HashMap::new()),
        }
    }

    /// `user`'s Studio for `project`, created on first use.
    pub fn open(&self, user: &str, project: &str) -> Result<Arc<Studio>, String> {
        let file = self.program(user, project)?;
        let mut open = self.open.lock().expect("registry lock");
        if let Some(studio) = open.get(&file) {
            return Ok(studio.clone());
        }
        let directory = file.parent().expect("a program file has a directory");
        std::fs::create_dir_all(directory)
            .map_err(|error| format!("cannot create {}: {error}", directory.display()))?;
        let text = match std::fs::read_to_string(&file) {
            Ok(text) => text,
            Err(error) if error.kind() == std::io::ErrorKind::NotFound => String::new(),
            Err(error) => return Err(format!("cannot read {}: {error}", file.display())),
        };
        let lane = Lane::new(self.root.clone(), self.mode);
        let studio = Arc::new(Studio::new(file.clone(), text, lane));
        studio.relay_lane();
        open.insert(file, studio.clone());
        Ok(studio)
    }

    /// The program file of `user`'s `project`.
    fn program(&self, user: &str, project: &str) -> Result<PathBuf, String> {
        if !valid_name(user) {
            return Err(format!("{user:?} cannot be a user name"));
        }
        if let ("", Some(linked)) = (project, &self.linked) {
            return Ok(linked.clone());
        }
        let project = if project.is_empty() { DEFAULT_PROJECT } else { project };
        if !valid_name(project) {
            return Err(format!("{project:?} cannot be a project name"));
        }
        let projects = self.data.join("users").join(user).join("projects");
        Ok(projects.join(project).join("main.slog"))
    }

    /// Stop every lane, for the server's exit.
    pub async fn shutdown(&self) {
        let studios: Vec<Arc<Studio>> =
            self.open.lock().expect("registry lock").values().cloned().collect();
        for studio in studios {
            studio.lane.shutdown().await;
        }
    }
}

#[cfg(test)]
mod tests {
    use super::{Registry, valid_name};
    use crate::lane::Mode;
    use slog_repl::server::project_root;
    use std::path::PathBuf;
    use std::sync::Arc;

    fn registry(name: &str) -> (Registry, PathBuf) {
        let data = std::env::temp_dir().join(format!("studio-{name}-{}", std::process::id()));
        let _ = std::fs::remove_dir_all(&data);
        let root = project_root().expect("repository root");
        (Registry::new(root, data.clone(), Mode::Fast, None), data)
    }

    /// Two users' projects of one name are two files and two Studios, and no
    /// project name reaches outside its user's directory.
    #[tokio::test]
    async fn a_user_cannot_open_another_users_project() {
        let (registry, data) = registry("isolation");
        let alice = registry.open("alice", "notes").expect("alice's notes");
        let bob = registry.open("bob", "notes").expect("bob's notes");
        assert!(!Arc::ptr_eq(&alice, &bob));
        assert!(Arc::ptr_eq(&alice, &registry.open("alice", "notes").expect("again")));
        let program = |user| data.join(format!("users/{user}/projects/notes/main.slog"));
        assert_eq!(alice.snapshot().await.file, program("alice").display().to_string());
        assert_eq!(bob.snapshot().await.file, program("bob").display().to_string());

        for project in ["../../bob/projects/notes", "..", ".", "a/b", "/etc", ".hidden"] {
            assert!(registry.open("alice", project).is_err(), "{project}");
        }
        assert!(registry.open("../bob", "notes").is_err());
        assert!(valid_name("alice@example.org") && valid_name("v1.2_x-y"));
        std::fs::remove_dir_all(data).expect("cleanup");
    }
}
