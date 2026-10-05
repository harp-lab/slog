//! Launching the Racket session server (`compiler/repl.rkt`) and finding the
//! repository it belongs to: the process half of every frontend. The terminal
//! REPL and Slog Studio both start servers here and then speak
//! `protocol::SessionConnection` to them.

use crate::protocol::{Announcement, PROTOCOL_VERSION};
use std::env;
use std::fs::File;
use std::io::{self, Read};
use std::path::{Path, PathBuf};
use std::process::Stdio;
use tokio::io::{AsyncBufReadExt, BufReader};
use tokio::process::{Child, Command};
use tokio::time::{Duration, timeout};

/// A running session server: the child process and the private loopback
/// endpoint it announced. Connections authenticate with `token`.
pub struct ServerProcess {
    pub child: Child,
    pub address: String,
    pub token: String,
}

/// Start `racket compiler/repl.rkt` in `project_root` with `env` added to the
/// inherited environment (for example `SLOG_OPT=interp`), and wait for its
/// port announcement.
///
/// After the announcement the server's stdout is never read again and its
/// pipe is closed; a stray write there fails instead of filling a buffer.
/// Stderr stays piped for the caller to drain.
pub async fn launch(project_root: &Path, env: &[(&str, &str)]) -> Result<ServerProcess, String> {
    let token = private_token().map_err(|error| format!("cannot create REPL token: {error}"))?;
    let mut child = Command::new("racket")
        .arg("compiler/repl.rkt")
        .current_dir(project_root)
        .env("SLOG_REPL_TOKEN", &token)
        .envs(env.iter().copied())
        .stdin(Stdio::null())
        .stdout(Stdio::piped())
        .stderr(Stdio::piped())
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
    let announcement: Announcement = serde_json::from_str(&line)
        .map_err(|error| format!("invalid Racket REPL announcement: {error}: {line:?}"))?;
    if announcement.protocol != PROTOCOL_VERSION {
        return Err(format!(
            "Racket protocol {} does not match Rust protocol {}",
            announcement.protocol, PROTOCOL_VERSION
        ));
    }
    Ok(ServerProcess {
        child,
        address: format!("{}:{}", announcement.host, announcement.port),
        token,
    })
}

/// 32 random bytes, hex encoded.
pub fn private_token() -> io::Result<String> {
    let mut random = [0_u8; 32];
    File::open("/dev/urandom")?.read_exact(&mut random)?;
    Ok(random.iter().map(|byte| format!("{byte:02x}")).collect())
}

/// Mirrors compiler/tools.rkt's `slogd-stale?` check without changing the
/// daemon. The first database session will synchronously rebuild a stale
/// runtime, so a frontend can label that wait honestly before sending open.
pub fn daemon_rebuild_pending(project_root: &Path) -> bool {
    let daemon = project_root.join("daemon");
    let executable_modified =
        match std::fs::metadata(daemon.join("slogd")).and_then(|metadata| metadata.modified()) {
            Ok(modified) => modified,
            Err(_) => return true,
        };
    let Ok(entries) = std::fs::read_dir(daemon) else {
        return false;
    };
    entries.filter_map(Result::ok).any(|entry| {
        let source = entry.path();
        let relevant = matches!(
            source.extension().and_then(|extension| extension.to_str()),
            Some("h" | "cpp")
        );
        relevant
            && std::fs::metadata(source)
                .and_then(|metadata| metadata.modified())
                .is_ok_and(|modified| modified > executable_modified)
    })
}

/// The Slog repository: `SLOG_ROOT`, else the first ancestor of the working
/// directory, else of the executable, that holds the compiler and daemon.
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
