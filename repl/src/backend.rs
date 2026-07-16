use crate::protocol::{Announcement, PROTOCOL_VERSION, Response, SessionConnection};
use std::env;
use std::fs::File;
use std::io::{self, Read};
use std::path::{Path, PathBuf};
use std::process::Stdio;
use tokio::io::{AsyncBufReadExt, BufReader};
use tokio::process::{Child, Command};
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
    Disconnected(String),
}

pub struct Backend {
    commands: mpsc::Sender<BackendCommand>,
    pub events: mpsc::Receiver<BackendEvent>,
    task: JoinHandle<()>,
}

impl Backend {
    pub async fn start(project_root: &Path) -> Result<Self, String> {
        let token =
            private_token().map_err(|error| format!("cannot create REPL token: {error}"))?;
        let (child, announcement) = launch_server(project_root, &token).await?;
        if announcement.protocol != PROTOCOL_VERSION {
            return Err(format!(
                "Racket protocol {} does not match Rust protocol {}",
                announcement.protocol, PROTOCOL_VERSION
            ));
        }
        let address = format!("{}:{}", announcement.host, announcement.port);
        let connection = SessionConnection::connect(&address, &token)
            .await
            .map_err(|error| format!("cannot connect to Racket REPL server: {error}"))?;

        let (command_tx, command_rx) = mpsc::channel(32);
        let (event_tx, event_rx) = mpsc::channel(32);
        let task = tokio::spawn(run_backend(child, connection, command_rx, event_tx));
        Ok(Self {
            commands: command_tx,
            events: event_rx,
            task,
        })
    }

    pub async fn execute(&self, line: String) -> Result<(), String> {
        self.commands
            .send(BackendCommand::Execute(line))
            .await
            .map_err(|_| "Racket session task has stopped".to_owned())
    }

    pub async fn shutdown(self) {
        let _ = self.commands.send(BackendCommand::Shutdown).await;
        let _ = self.task.await;
    }
}

async fn run_backend(
    mut child: Child,
    mut connection: SessionConnection,
    mut commands: mpsc::Receiver<BackendCommand>,
    events: mpsc::Sender<BackendEvent>,
) {
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
}

async fn launch_server(project_root: &Path, token: &str) -> Result<(Child, Announcement), String> {
    let mut child = Command::new("racket")
        .arg("compiler/repl.rkt")
        .current_dir(project_root)
        .env("SLOG_REPL_TOKEN", token)
        .stdin(Stdio::null())
        .stdout(Stdio::piped())
        .stderr(Stdio::inherit())
        .kill_on_drop(true)
        .spawn()
        .map_err(|error| format!("cannot start racket compiler/repl.rkt: {error}"))?;
    let stdout = child
        .stdout
        .take()
        .ok_or_else(|| "Racket server did not expose its bootstrap pipe".to_owned())?;
    let mut reader = BufReader::new(stdout);
    let mut line = String::new();
    let read = timeout(Duration::from_secs(15), reader.read_line(&mut line))
        .await
        .map_err(|_| "Racket REPL server did not announce a port within 15 seconds".to_owned())?
        .map_err(|error| format!("cannot read Racket REPL announcement: {error}"))?;
    if read == 0 {
        return Err("Racket REPL server exited before announcing a port".to_owned());
    }
    let announcement = serde_json::from_str(&line)
        .map_err(|error| format!("invalid Racket REPL announcement: {error}: {line:?}"))?;
    Ok((child, announcement))
}

fn private_token() -> io::Result<String> {
    let mut random = [0_u8; 32];
    File::open("/dev/urandom")?.read_exact(&mut random)?;
    Ok(random.iter().map(|byte| format!("{byte:02x}")).collect())
}

pub fn project_root() -> Result<PathBuf, String> {
    if let Some(root) = env::var_os("SLOG_ROOT") {
        let root = PathBuf::from(root);
        if is_project_root(&root) {
            return Ok(root);
        }
        return Err(format!(
            "SLOG_ROOT={} does not contain compiler/repl.rkt",
            root.display()
        ));
    }

    if let Ok(cwd) = env::current_dir()
        && let Some(root) = find_root(cwd)
    {
        return Ok(root);
    }
    if let Ok(executable) = env::current_exe()
        && let Some(parent) = executable.parent()
        && let Some(root) = find_root(parent.to_path_buf())
    {
        return Ok(root);
    }
    Err("cannot find the Slog repository; run the copied ./slog or set SLOG_ROOT".to_owned())
}

fn find_root(start: PathBuf) -> Option<PathBuf> {
    start
        .ancestors()
        .find(|candidate| is_project_root(candidate))
        .map(Path::to_path_buf)
}

fn is_project_root(path: &Path) -> bool {
    path.join("compiler/repl.rkt").is_file() && path.join("daemon").is_dir()
}
