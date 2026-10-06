//! Which Studio serves a request: one per (user, project), created on first
//! use, each with its own lane.
//!
//! A project is a directory `users/<user>/projects/<name>/` under the data
//! directory, evaluated from its `main.slog`; the empty name is the user's
//! default project. In local mode the default is instead the file named on
//! the command line. A user can reach only their own directory: the user
//! comes from the login, never from the request, and a name is one path
//! segment.
//!
//! On a shared server, `Limits` bound what each user's lanes hold: past the
//! cap the user's least recently used lane stops, and a lane idle too long
//! stops. A stopped lane's Studio stays, text and all; its next command
//! starts a fresh server.

use crate::lane::{Lane, LaneState, Mode};
use crate::studio::Studio;
use std::collections::HashMap;
use std::path::PathBuf;
use std::sync::{Arc, Mutex};
use std::time::{Duration, Instant};

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

pub struct Limits {
    /// Live lanes per user.
    pub lanes: usize,
    /// How long a lane may sit unused before it stops.
    pub idle: Duration,
}

pub struct Registry {
    /// The repository lanes run in.
    root: PathBuf,
    data: PathBuf,
    mode: Mode,
    /// Local mode's default project: the file named on the command line.
    linked: Option<PathBuf>,
    limits: Option<Limits>,
    /// By program file, so no two Studios ever hold one file.
    open: Mutex<HashMap<PathBuf, Entry>>,
}

struct Entry {
    user: String,
    studio: Arc<Studio>,
    /// When its lane was last asked to work, or seen working.
    active: Instant,
}

impl Registry {
    pub fn new(
        root: PathBuf,
        data: PathBuf,
        mode: Mode,
        linked: Option<PathBuf>,
        limits: Option<Limits>,
    ) -> Self {
        Self {
            root,
            data,
            mode,
            linked,
            limits,
            open: Mutex::new(HashMap::new()),
        }
    }

    /// `user`'s Studio for `project`, created on first use.
    pub fn open(&self, user: &str, project: &str) -> Result<Arc<Studio>, String> {
        let file = self.program(user, project)?;
        let mut open = self.open.lock().expect("registry lock");
        if let Some(entry) = open.get(&file) {
            return Ok(entry.studio.clone());
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
        let entry = Entry {
            user: user.to_owned(),
            studio: studio.clone(),
            active: Instant::now(),
        };
        open.insert(file, entry);
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

    /// Called before `studio`'s lane is asked to work. Marks it active and,
    /// if a server starting there would put its user over the cap, stops
    /// that user's least recently active lanes.
    pub fn admit(&self, studio: &Arc<Studio>) {
        let mut open = self.open.lock().expect("registry lock");
        let Some(entry) = open.values_mut().find(|entry| Arc::ptr_eq(&entry.studio, studio))
        else {
            return;
        };
        entry.active = Instant::now();
        let user = entry.user.clone();
        let Some(limits) = &self.limits else { return };
        let mut others: Vec<&Entry> = open
            .values()
            .filter(|entry| entry.user == user && !Arc::ptr_eq(&entry.studio, studio))
            .filter(|entry| live(&entry.studio.lane))
            .collect();
        let excess = (others.len() + 1).saturating_sub(limits.lanes);
        others.sort_by_key(|entry| entry.active);
        for entry in &others[..excess] {
            entry.studio.lane.kill();
        }
    }

    /// Stop every lane unused for the idle limit as of `now`. A lane at work
    /// counts as used.
    pub async fn sweep(&self, now: Instant) {
        let Some(limits) = &self.limits else { return };
        let mut idle = Vec::new();
        for entry in self.open.lock().expect("registry lock").values_mut() {
            let state = entry.studio.lane.status().borrow().state;
            match state {
                LaneState::Starting | LaneState::Busy => entry.active = now,
                LaneState::Ready if now.duration_since(entry.active) >= limits.idle => {
                    idle.push(entry.studio.clone());
                }
                LaneState::Ready | LaneState::Idle | LaneState::Dead => {}
            }
        }
        for studio in idle {
            studio.lane.shutdown().await;
        }
    }

    /// Sweep for idle lanes for as long as the server runs, often enough
    /// that none outlives the idle limit by more than a quarter.
    pub fn stop_idle_lanes(self: &Arc<Self>) {
        let Some(limits) = &self.limits else { return };
        let period = (limits.idle / 4).max(Duration::from_secs(1));
        let registry = self.clone();
        tokio::spawn(async move {
            let mut ticks = tokio::time::interval(period);
            loop {
                ticks.tick().await;
                registry.sweep(Instant::now()).await;
            }
        });
    }

    /// Stop every lane, for the server's exit.
    pub async fn shutdown(&self) {
        let studios: Vec<Arc<Studio>> = {
            let open = self.open.lock().expect("registry lock");
            open.values().map(|entry| entry.studio.clone()).collect()
        };
        for studio in studios {
            studio.lane.shutdown().await;
        }
    }
}

/// Whether a lane holds a server, or is starting one.
fn live(lane: &Lane) -> bool {
    matches!(lane.status().borrow().state, LaneState::Starting | LaneState::Ready | LaneState::Busy)
}

#[cfg(test)]
mod tests {
    use super::{Limits, Registry, valid_name};
    use crate::lane::{LaneState, Mode};
    use crate::studio::Studio;
    use slog_repl::server::project_root;
    use std::path::PathBuf;
    use std::sync::Arc;
    use std::time::{Duration, Instant};

    fn registry(name: &str, limits: Option<Limits>) -> (Registry, PathBuf) {
        let data = std::env::temp_dir().join(format!("studio-{name}-{}", std::process::id()));
        let _ = std::fs::remove_dir_all(&data);
        let root = project_root().expect("repository root");
        (Registry::new(root, data.clone(), Mode::Fast, None, limits), data)
    }

    fn state(studio: &Studio) -> LaneState {
        studio.lane.status().borrow().state
    }

    /// Two users' projects of one name are two files and two Studios, and no
    /// project name reaches outside its user's directory.
    #[tokio::test]
    async fn a_user_cannot_open_another_users_project() {
        let (registry, data) = registry("isolation", None);
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

    /// A lane unused for the idle limit stops; a recently used one does not.
    /// Its Studio stays open, and the next command starts a fresh server.
    #[tokio::test]
    async fn an_idle_lane_stops() {
        let idle = Duration::from_secs(60);
        let (registry, data) = registry("idle", Some(Limits { lanes: 4, idle }));
        let studio = registry.open("alice", "").expect("open");
        registry.admit(&studio);
        assert!(studio.lane.command(":ping").await.expect("server").ok);

        registry.sweep(Instant::now() + idle / 2).await;
        assert_eq!(state(&studio), LaneState::Ready);
        registry.sweep(Instant::now() + idle).await;
        assert_eq!(state(&studio), LaneState::Dead);

        assert!(Arc::ptr_eq(&studio, &registry.open("alice", "").expect("open")));
        assert!(studio.lane.command(":ping").await.expect("a fresh server").ok);
        registry.shutdown().await;
        std::fs::remove_dir_all(data).expect("cleanup");
    }

    /// At the cap, starting another lane stops the user's least recently
    /// used one, and only that user's.
    #[tokio::test]
    async fn past_the_cap_the_least_recently_used_lane_stops() {
        let limits = Limits { lanes: 1, idle: Duration::MAX };
        let (registry, data) = registry("cap", Some(limits));
        let [first, second, theirs] = [("alice", "a"), ("alice", "b"), ("bob", "a")]
            .map(|(user, project)| registry.open(user, project).expect("open"));
        for studio in [&first, &theirs] {
            registry.admit(studio);
            assert!(studio.lane.command(":ping").await.expect("server").ok);
        }
        registry.admit(&second);
        assert_eq!(state(&first), LaneState::Dead);
        assert_eq!(state(&theirs), LaneState::Ready);
        registry.shutdown().await;
        std::fs::remove_dir_all(data).expect("cleanup");
    }
}
