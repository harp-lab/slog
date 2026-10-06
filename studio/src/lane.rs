//! A lane: one Racket session server (`compiler/repl.rkt`) and Studio's
//! connections to it.
//!
//! The daemon admits one live query cursor per connection, and that cursor's
//! snapshot lease refuses every other command until it finishes
//! (daemon/slogd.cpp, `active_query`), so a lane does one thing at a time:
//! commands are serialized here. Interrupt and kill work out of band while a
//! command is in flight. The server starts on first use and again after it
//! dies or is killed.

use serde::{Deserialize, Serialize};
use slog_repl::protocol::{Response, SessionConnection};
use slog_repl::server::{self, ServerProcess};
use std::path::PathBuf;
use std::sync::Arc;
use std::sync::atomic::{AtomicU64, Ordering};
use tokio::io::{AsyncBufReadExt, BufReader};
use tokio::process::Child;
use tokio::sync::{Mutex, broadcast, watch};
use tokio::time::{Duration, timeout};

#[derive(Clone, Copy, Debug, Default, Deserialize, Eq, PartialEq, Serialize)]
#[serde(rename_all = "lowercase")]
pub enum Mode {
    /// The interpreter on every thread, so a program never waits for the C++
    /// toolchain. (Slog's default tiering, which promotes long strata to
    /// native code mid-run, can crash the daemon at the promotion; fast mode
    /// returns to it once that is fixed.)
    #[default]
    Fast,
    /// Native code (-O2) from the start, for performance work.
    Compiled,
    /// The interpreter on one thread: breakpoints, stepping and provenance
    /// stop at the same places every run (audit D-07, D-14).
    Debug,
}

impl Mode {
    pub fn env(self) -> Vec<(&'static str, &'static str)> {
        match self {
            Mode::Fast => vec![("SLOG_OPT", "interp")],
            Mode::Compiled => vec![("SLOG_OPT", "2")],
            Mode::Debug => vec![("SLOG_OPT", "interp"), ("SLOG_THREADS", "1")],
        }
    }
}

#[derive(Clone, Copy, Debug, Eq, PartialEq, Serialize)]
#[serde(rename_all = "lowercase")]
pub enum LaneState {
    /// No server yet; the first command starts one.
    Idle,
    Starting,
    Ready,
    Busy,
    /// The server exited, failed to start, or was killed; the next command
    /// starts a fresh one.
    Dead,
}

#[derive(Clone, Debug, Serialize)]
pub struct LaneStatus {
    pub state: LaneState,
    /// Why the lane is dead, or empty.
    pub detail: String,
    /// Servers started so far; more than one means the lane has restarted.
    pub starts: u32,
    pub mode: Mode,
}

pub struct Lane {
    root: PathBuf,
    mode: std::sync::Mutex<Mode>,
    /// Set for every server, beside the mode's own settings.
    env: Vec<(&'static str, &'static str)>,
    /// The command connection, held for the whole of each command.
    connection: Mutex<Option<Live>>,
    /// The interrupt-only connection (serve-control in repl.rkt).
    control: Mutex<Option<SessionConnection>>,
    child: std::sync::Mutex<Option<Child>>,
    /// Advanced by every start and kill, so a connection or exit notice from
    /// an earlier server is recognised as stale.
    generation: Arc<AtomicU64>,
    status: Arc<watch::Sender<LaneStatus>>,
    log: broadcast::Sender<String>,
}

struct Live {
    connection: SessionConnection,
    generation: u64,
}

impl Lane {
    /// A lane over the repository at `root`, its servers run in `mode`.
    pub fn new(root: PathBuf, mode: Mode) -> Self {
        Self::with_env(root, mode, Vec::new())
    }

    /// The same, its servers also given `env`.
    pub fn with_env(root: PathBuf, mode: Mode, env: Vec<(&'static str, &'static str)>) -> Self {
        let (status, _) = watch::channel(LaneStatus {
            state: LaneState::Idle,
            detail: String::new(),
            starts: 0,
            mode,
        });
        Self {
            root,
            mode: std::sync::Mutex::new(mode),
            env,
            connection: Mutex::new(None),
            control: Mutex::new(None),
            child: std::sync::Mutex::new(None),
            generation: Arc::new(AtomicU64::new(0)),
            status: Arc::new(status),
            log: broadcast::channel(256).0,
        }
    }

    /// The repository the lane's servers run in.
    pub fn root(&self) -> &std::path::Path {
        &self.root
    }

    pub fn status(&self) -> watch::Receiver<LaneStatus> {
        self.status.subscribe()
    }

    /// The server's stderr, a line at a time: compiler warnings, daemon
    /// diagnostics, build output.
    pub fn log(&self) -> broadcast::Receiver<String> {
        self.log.subscribe()
    }

    /// Identifies the running server; it changes whenever the server does.
    pub fn generation(&self) -> u64 {
        self.generation.load(Ordering::SeqCst)
    }

    /// Run one REPL command line, starting a server first if none is live.
    pub async fn command(&self, line: &str) -> Result<Response, String> {
        let mut live = self.connection.lock().await;
        let stale = live.as_ref().is_none_or(|live| {
            live.generation != self.generation() || self.status.borrow().state == LaneState::Dead
        });
        if stale {
            *live = None;
            *live = Some(self.start().await?);
        }
        let current = live.as_mut().expect("a live connection was just ensured");
        self.set(LaneState::Busy, "");
        match current.connection.command(line.to_owned()).await {
            Ok(response) => {
                self.set(LaneState::Ready, "");
                Ok(response)
            }
            Err(error) => {
                let message = format!("the session server stopped answering: {error}");
                // A kill already explained itself and moved the generation on.
                if current.generation == self.generation() {
                    self.set(LaneState::Dead, &message);
                }
                *live = None;
                Err(message)
            }
        }
    }

    /// Ask the run in flight to pause at its next slice boundary; the pause
    /// arrives as that command's own response.
    pub async fn interrupt(&self) -> Result<Response, String> {
        let mut control = self.control.lock().await;
        let connection = control
            .as_mut()
            .ok_or_else(|| "no server is running".to_owned())?;
        connection
            .interrupt()
            .await
            .map_err(|error| format!("cannot reach the control connection: {error}"))
    }

    /// How far the run in flight has got: its strata from index `from` on
    /// (docs/pausing.md §16). Asked on the control connection, beside the
    /// command it watches.
    pub async fn progress(&self, from: usize) -> Result<Response, String> {
        let mut control = self.control.lock().await;
        let connection = control
            .as_mut()
            .ok_or_else(|| "no server is running".to_owned())?;
        connection
            .progress(from)
            .await
            .map_err(|error| format!("cannot reach the control connection: {error}"))
    }

    /// Run later servers in `mode`. The current one is killed, so the next
    /// command already runs in the new mode; its session is gone.
    pub fn set_mode(&self, mode: Mode) {
        *self.mode.lock().expect("lane mode lock") = mode;
        self.status.send_modify(|status| status.mode = mode);
        self.kill();
    }

    /// Kill the server, in flight or not. The next command starts a new one.
    pub fn kill(&self) {
        self.generation.fetch_add(1, Ordering::SeqCst);
        self.kill_child();
        self.set(LaneState::Dead, "killed; the next command starts a fresh server");
    }

    /// Close the server's sessions cleanly if it is idle, then stop it.
    pub async fn shutdown(&self) {
        if let Ok(mut live) = self.connection.try_lock()
            && let Some(live) = live.as_mut()
        {
            let _ = timeout(Duration::from_secs(5), live.connection.shutdown()).await;
        }
        self.kill();
    }

    async fn start(&self) -> Result<Live, String> {
        self.kill_child();
        self.set(LaneState::Starting, "");
        let mode = *self.mode.lock().expect("lane mode lock");
        let env = [mode.env(), self.env.clone()].concat();
        let ServerProcess {
            mut child,
            address,
            token,
        } = server::launch(&self.root, &env)
            .await
            .inspect_err(|error| self.set(LaneState::Dead, error))?;
        let generation = self.generation.fetch_add(1, Ordering::SeqCst) + 1;
        if let Some(stderr) = child.stderr.take() {
            let log = self.log.clone();
            let current = self.generation.clone();
            let status = self.status.clone();
            tokio::spawn(async move {
                let mut lines = BufReader::new(stderr).lines();
                while let Ok(Some(line)) = lines.next_line().await {
                    let _ = log.send(line);
                }
                // stderr closes when the server exits; only the current
                // server's exit makes the lane dead.
                if current.load(Ordering::SeqCst) == generation {
                    status.send_modify(|status| {
                        status.state = LaneState::Dead;
                        status.detail = "the session server exited".to_owned();
                    });
                }
            });
        }
        *self.child.lock().expect("lane child lock") = Some(child);
        let connection = SessionConnection::connect(&address, &token)
            .await
            .map_err(|error| format!("cannot connect to the session server: {error}"))
            .inspect_err(|error| self.set(LaneState::Dead, error))?;
        // Interrupts need a second wire because the first is blocked on the
        // command in flight; a server without one is merely uninterruptible.
        *self.control.lock().await = SessionConnection::connect(&address, &token).await.ok();
        self.status.send_modify(|status| {
            status.state = LaneState::Ready;
            status.detail.clear();
            status.starts += 1;
        });
        Ok(Live {
            connection,
            generation,
        })
    }

    fn kill_child(&self) {
        if let Some(mut child) = self.child.lock().expect("lane child lock").take() {
            let _ = child.start_kill();
        }
    }

    fn set(&self, state: LaneState, detail: &str) {
        self.status.send_modify(|status| {
            status.state = state;
            status.detail = detail.to_owned();
        });
    }
}

#[cfg(test)]
mod tests {
    use super::{Lane, LaneState, Mode};
    use slog_repl::server::project_root;

    /// A killed server is replaced by the next command, transparently.
    #[tokio::test]
    async fn a_killed_lane_restarts_on_the_next_command() {
        let lane = Lane::new(project_root().expect("repository root"), Mode::Fast);
        assert!(lane.command(":ping").await.expect("first server").ok);
        lane.kill();
        assert_eq!(lane.status().borrow().state, LaneState::Dead);
        assert!(lane.command(":ping").await.expect("second server").ok);
        let status = lane.status().borrow().clone();
        assert_eq!((status.state, status.starts), (LaneState::Ready, 2));
        lane.shutdown().await;
    }
}
