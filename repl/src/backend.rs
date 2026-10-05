use crate::protocol::{Response, SessionConnection};
use crate::server::{self, ServerProcess};
use std::path::{Path, PathBuf};
use tokio::io::{AsyncBufReadExt, BufReader};
use tokio::process::Child;
use tokio::sync::mpsc;
use tokio::task::JoinHandle;
use tokio::time::{Duration, timeout};

#[derive(Debug)]
enum BackendCommand {
    Execute(String),
    Shutdown,
}

#[derive(Debug)]
pub enum BackendEvent {
    Response { command: String, response: Response },
    Log(String),
    Disconnected(String),
    /// The server's answer to a stage-2 interrupt (or the control channel's
    /// failure).  The paused run itself comes back as the ordinary Response
    /// of the command that was in flight.
    Interrupt(Result<Response, String>),
}

pub struct Backend {
    commands: mpsc::Sender<BackendCommand>,
    pub events: mpsc::Receiver<BackendEvent>,
    task: JoinHandle<()>,
    project_root: PathBuf,
    /// Stage-2 Ctrl-C: the control-only connection's request queue, None
    /// when the server offered no second connection.
    interrupts: Option<mpsc::Sender<()>>,
    control_task: Option<JoinHandle<()>>,
}

impl Backend {
    pub async fn start(project_root: &Path) -> Result<Self, String> {
        let ServerProcess {
            child,
            address,
            token,
        } = server::launch(project_root, &[]).await?;
        let connection = SessionConnection::connect(&address, &token)
            .await
            .map_err(|error| format!("cannot connect to Racket REPL server: {error}"))?;

        let (command_tx, command_rx) = mpsc::channel(32);
        let (event_tx, event_rx) = mpsc::channel(32);
        // Stage-2 Ctrl-C (repl-ux.md §9.2): a SECOND, control-only connection
        // to the same server.  The primary connection blocks on each
        // in-flight response, so an interrupt needs its own wire; serve-repl
        // keeps its listener open for exactly this.  A server without it
        // (connect refused) leaves interrupts unavailable, never broken.
        let control = SessionConnection::connect(&address, &token).await.ok();
        let (interrupt_tx, interrupt_rx) = mpsc::channel(4);
        let control_task = control.map(|control| {
            tokio::spawn(run_control(control, interrupt_rx, event_tx.clone()))
        });
        let interrupts = control_task.as_ref().map(|_| interrupt_tx);
        let task = tokio::spawn(run_backend(child, connection, command_rx, event_tx));
        Ok(Self {
            commands: command_tx,
            events: event_rx,
            task,
            project_root: project_root.to_owned(),
            interrupts,
            control_task,
        })
    }

    /// Mirrors compiler/tools.rkt's `slogd-stale?` check without changing the
    /// daemon. The first database session will synchronously rebuild a stale
    /// runtime, so the REPL can label that wait honestly before sending open.
    pub fn daemon_rebuild_pending(&self) -> bool {
        server::daemon_rebuild_pending(&self.project_root)
    }

    pub async fn execute(&self, line: String) -> Result<(), String> {
        self.commands
            .send(BackendCommand::Execute(line))
            .await
            .map_err(|_| "Racket session task has stopped".to_owned())
    }

    /// Replace this REPL's private control-plane process with a fresh one.
    ///
    /// The replacement is started before the old process is closed, so a
    /// startup failure leaves the user's current session available.  Once the
    /// replacement is ready, graceful shutdown closes every old resident
    /// compiler session and daemon without touching saved databases on disk.
    pub async fn reset(&mut self) -> Result<(), String> {
        let replacement = Self::start(&self.project_root).await?;
        if let Some(task) = self.control_task.take() {
            task.abort();
        }
        let _ = self.commands.send(BackendCommand::Shutdown).await;
        if timeout(Duration::from_secs(1), &mut self.task)
            .await
            .is_err()
        {
            self.task.abort();
            let _ = (&mut self.task).await;
        }
        *self = replacement;
        Ok(())
    }

    pub fn cancel_in_flight(&self) {
        if let Some(task) = &self.control_task {
            task.abort();
        }
        self.task.abort();
    }
    /// Stage-2 Ctrl-C: queue one interrupt on the control connection.  The
    /// server pauses the in-flight run at its next slice boundary and answers
    /// the in-flight command with a `paused` result; this call only confirms
    /// the request was taken (BackendEvent::Interrupt).
    pub async fn interrupt(&self) -> Result<(), String> {
        match &self.interrupts {
            Some(interrupts) => interrupts
                .send(())
                .await
                .map_err(|_| "the control channel has stopped".to_owned()),
            None => Err("no control channel: this server offers no interrupts".to_owned()),
        }
    }

    pub async fn shutdown(self) {
        if let Some(task) = &self.control_task {
            task.abort();
        }
        let _ = self.commands.send(BackendCommand::Shutdown).await;
        let mut task = self.task;
        if timeout(Duration::from_secs(1), &mut task).await.is_err() {
            task.abort();
            let _ = task.await;
        }
    }
}

/// The control connection's pump: one `interrupt` request per queued
/// Ctrl-C, its answer surfaced as BackendEvent::Interrupt.
async fn run_control(
    mut control: SessionConnection,
    mut interrupts: mpsc::Receiver<()>,
    events: mpsc::Sender<BackendEvent>,
) {
    while interrupts.recv().await.is_some() {
        let outcome = control
            .interrupt()
            .await
            .map_err(|error| error.to_string());
        if events.send(BackendEvent::Interrupt(outcome)).await.is_err() {
            break;
        }
    }
}

async fn run_backend(
    mut child: Child,
    mut connection: SessionConnection,
    mut commands: mpsc::Receiver<BackendCommand>,
    events: mpsc::Sender<BackendEvent>,
) {
    let stderr_task = child.stderr.take().map(|stderr| {
        let events = events.clone();
        tokio::spawn(async move {
            let mut lines = BufReader::new(stderr).lines();
            while let Ok(Some(line)) = lines.next_line().await {
                // Diagnostic floods must not block session shutdown.
                let _ = events.try_send(BackendEvent::Log(line));
            }
        })
    });
    while let Some(command) = commands.recv().await {
        match command {
            BackendCommand::Execute(line) => match connection.command(line.clone()).await {
                Ok(response) => {
                    let closes = response
                        .result
                        .as_ref()
                        .and_then(|value| value.get("close"))
                        .and_then(|value| value.as_bool())
                        .unwrap_or(false);
                    if events
                        .send(BackendEvent::Response {
                            command: line,
                            response,
                        })
                        .await
                        .is_err()
                    {
                        break;
                    }
                    if closes {
                        break;
                    }
                }
                Err(error) => {
                    let _ = events
                        .send(BackendEvent::Disconnected(error.to_string()))
                        .await;
                    break;
                }
            },
            BackendCommand::Shutdown => {
                let _ = connection.shutdown().await;
                break;
            }
        }
    }
    drop(connection);
    if timeout(Duration::from_secs(5), child.wait()).await.is_err() {
        let _ = child.kill().await;
        let _ = child.wait().await;
    }
    if let Some(task) = stderr_task {
        let _ = task.await;
    }
}
