//! Server mode's accounts: who may log in, and who is logged in. Both live in
//! the data directory, so a restart keeps every login.
//!
//! `users.toml` holds each user's Argon2id password hash as a PHC string:
//!
//! ```toml
//! [alice]
//! password = "$argon2id$v=19$m=19456,t=2,p=1$…"
//! ```
//!
//! A login session is a file `sessions/<digest>` naming its user and when it
//! expires. The digest is BLAKE2s of the secret in the browser's cookie, so
//! the directory, and any backup of it, holds nothing that logs anyone in.
//!
//! Both are read on every use, never cached: a user added while the server
//! runs can log in at once, and deleting a user's entry from `users.toml`
//! ends their sessions.

use crate::registry::valid_name;
use argon2::{Argon2, PasswordHash, PasswordHasher, PasswordVerifier};
use blake2::{Blake2s256, Digest};
use serde::{Deserialize, Serialize};
use slog_repl::server::private_token;
use std::collections::BTreeMap;
use std::fs;
use std::io::{BufRead, Write};
use std::os::unix::fs::{DirBuilderExt, OpenOptionsExt};
use std::path::{Path, PathBuf};
use std::sync::OnceLock;
use std::time::{Duration, SystemTime, UNIX_EPOCH};

/// How long a login lasts; the cookie says the same.
pub const SESSION_LIFETIME: Duration = Duration::from_secs(30 * 24 * 60 * 60);

pub struct Accounts {
    data: PathBuf,
}

#[derive(Deserialize, Serialize)]
struct User {
    password: String,
}

#[derive(Deserialize, Serialize)]
struct Session {
    user: String,
    /// Seconds since the Unix epoch.
    expires: u64,
}

impl Accounts {
    /// The accounts kept in the data directory `data`.
    pub fn new(data: PathBuf) -> Self {
        Self { data }
    }

    /// Whether nobody can log in yet.
    pub fn is_empty(&self) -> Result<bool, String> {
        Ok(self.users()?.is_empty())
    }

    pub fn add_user(&self, name: &str, password: &str) -> Result<(), String> {
        if !valid_name(name) {
            return Err(format!(
                "{name:?} cannot be a user name: use letters, digits and _ . @ -, not starting with ."
            ));
        }
        if password.is_empty() {
            return Err("the password is empty".to_owned());
        }
        let mut users = self.users()?;
        if users.contains_key(name) {
            return Err(format!("{name} already exists"));
        }
        users.insert(
            name.to_owned(),
            User {
                password: hash(password)?,
            },
        );
        let text = toml::to_string(&users).map_err(|error| error.to_string())?;
        write_private(&self.data.join("users.toml"), text.as_bytes())
    }

    /// Whether `password` is `name`'s. Slow by design (Argon2), so callers
    /// run it off the async threads. An unknown name costs as much as a known
    /// one, so the time taken does not say which names exist.
    pub fn verify(&self, name: &str, password: &str) -> bool {
        let stored = self
            .users()
            .ok()
            .and_then(|mut users| users.remove(name))
            .map(|user| user.password);
        let known = stored.is_some();
        let stored = stored.unwrap_or_else(|| decoy().to_owned());
        let matches = PasswordHash::new(&stored).is_ok_and(|hash| {
            Argon2::default()
                .verify_password(password.as_bytes(), &hash)
                .is_ok()
        });
        known && matches
    }

    /// Log `user` in, returning the secret for their cookie.
    pub fn start_session(&self, user: &str) -> Result<String, String> {
        let secret =
            private_token().map_err(|error| format!("cannot create a session: {error}"))?;
        let session = Session {
            user: user.to_owned(),
            expires: now() + SESSION_LIFETIME.as_secs(),
        };
        private_dir(&self.data.join("sessions"))?;
        let text = toml::to_string(&session).map_err(|error| error.to_string())?;
        write_private(&self.session_file(&secret), text.as_bytes())?;
        Ok(secret)
    }

    /// The user logged in with `secret`, while the session lasts and the
    /// user still exists.
    pub fn session_user(&self, secret: &str) -> Option<String> {
        let file = self.session_file(secret);
        let session: Session = toml::from_str(&fs::read_to_string(&file).ok()?).ok()?;
        if session.expires <= now() {
            let _ = fs::remove_file(&file);
            return None;
        }
        self.users()
            .ok()?
            .contains_key(&session.user)
            .then_some(session.user)
    }

    pub fn end_session(&self, secret: &str) {
        let _ = fs::remove_file(self.session_file(secret));
    }

    /// Delete expired sessions, and files that are not sessions at all (a
    /// write cut short).
    pub fn prune_sessions(&self) {
        let entries = fs::read_dir(self.data.join("sessions"));
        for path in entries
            .into_iter()
            .flatten()
            .flatten()
            .map(|entry| entry.path())
        {
            let live = fs::read_to_string(&path)
                .ok()
                .and_then(|text| toml::from_str::<Session>(&text).ok())
                .is_some_and(|session| session.expires > now());
            if !live {
                let _ = fs::remove_file(&path);
            }
        }
    }

    /// The users file; a missing one has no users.
    fn users(&self) -> Result<BTreeMap<String, User>, String> {
        let path = self.data.join("users.toml");
        match fs::read_to_string(&path) {
            Ok(text) => {
                toml::from_str(&text).map_err(|error| format!("{}: {error}", path.display()))
            }
            Err(error) if error.kind() == std::io::ErrorKind::NotFound => Ok(BTreeMap::new()),
            Err(error) => Err(format!("cannot read {}: {error}", path.display())),
        }
    }

    fn session_file(&self, secret: &str) -> PathBuf {
        let digest = Blake2s256::digest(secret.as_bytes());
        let name: String = digest.iter().map(|byte| format!("{byte:02x}")).collect();
        self.data.join("sessions").join(name)
    }
}

/// An Argon2id PHC string for `password`, with a fresh random salt and the
/// crate's default cost (19 MiB, two passes: OWASP's recommendation).
fn hash(password: &str) -> Result<String, String> {
    Argon2::default()
        .hash_password(password.as_bytes())
        .map(|hash| hash.to_string())
        .map_err(|error| format!("cannot hash the password: {error}"))
}

/// A hash to verify unknown names against, for the time it takes. What it
/// hashes does not matter: an unknown name never verifies.
fn decoy() -> &'static str {
    static DECOY: OnceLock<String> = OnceLock::new();
    DECOY.get_or_init(|| hash("decoy").expect("hashing a constant"))
}

fn now() -> u64 {
    SystemTime::now()
        .duration_since(UNIX_EPOCH)
        .map_or(0, |since| since.as_secs())
}

/// Create `path` and its missing parents, each readable only by this user.
pub fn private_dir(path: &Path) -> Result<(), String> {
    fs::DirBuilder::new()
        .recursive(true)
        .mode(0o700)
        .create(path)
        .map_err(|error| format!("cannot create {}: {error}", path.display()))
}

/// Replace `path` with `bytes` atomically, readable only by this user.
fn write_private(path: &Path, bytes: &[u8]) -> Result<(), String> {
    let partial = path.with_extension("partial");
    fs::OpenOptions::new()
        .write(true)
        .create(true)
        .truncate(true)
        .mode(0o600)
        .open(&partial)
        .and_then(|mut file| {
            file.write_all(bytes)?;
            file.sync_all()
        })
        .and_then(|()| fs::rename(&partial, path))
        .map_err(|error| format!("cannot write {}: {error}", path.display()))
}

const USER_USAGE: &str = "usage: slog-studio user add NAME --data DIR

Add a user who can log in to `slog-studio serve --data DIR`. The password is
read from the terminal without echo, or as one line from standard input.";

/// `slog-studio user add NAME --data DIR`.
pub fn user_command(mut args: impl Iterator<Item = String>) -> Result<(), String> {
    if args.next().as_deref() != Some("add") {
        return Err(USER_USAGE.to_owned());
    }
    let (mut name, mut data) = (None, None);
    while let Some(arg) = args.next() {
        match arg.as_str() {
            "--data" => data = Some(args.next().ok_or(USER_USAGE)?),
            "-h" | "--help" => return Err(USER_USAGE.to_owned()),
            _ if name.is_none() && !arg.starts_with('-') => name = Some(arg),
            _ => return Err(USER_USAGE.to_owned()),
        }
    }
    let (Some(name), Some(data)) = (name, data) else {
        return Err(USER_USAGE.to_owned());
    };
    let data = PathBuf::from(data);
    private_dir(&data)?;
    let password = new_password().map_err(|error| format!("cannot read the password: {error}"))?;
    Accounts::new(data.clone()).add_user(&name, &password)?;
    eprintln!("added {name} to {}", data.join("users.toml").display());
    Ok(())
}

/// Ask twice at a terminal; otherwise take one line from standard input.
fn new_password() -> std::io::Result<String> {
    let stdin = std::io::stdin();
    if !rustix::termios::isatty(&stdin) {
        let mut line = String::new();
        stdin.lock().read_line(&mut line)?;
        return Ok(line.trim_end_matches(['\r', '\n']).to_owned());
    }
    let password = read_quietly("Password: ")?;
    if read_quietly("Again: ")? != password {
        return Err(std::io::Error::other("the passwords differ"));
    }
    Ok(password)
}

/// Read a line from the terminal on standard input with echo off.
fn read_quietly(prompt: &str) -> std::io::Result<String> {
    use rustix::termios::{LocalModes, OptionalActions, tcgetattr, tcsetattr};
    let stdin = std::io::stdin();
    eprint!("{prompt}");
    let saved = tcgetattr(&stdin)?;
    let mut quiet = saved.clone();
    quiet.local_modes.remove(LocalModes::ECHO);
    // Still echo the newline, so the next prompt starts on its own line.
    quiet.local_modes.insert(LocalModes::ECHONL);
    tcsetattr(&stdin, OptionalActions::Flush, &quiet)?;
    let mut line = String::new();
    let read = stdin.lock().read_line(&mut line);
    tcsetattr(&stdin, OptionalActions::Now, &saved)?;
    read?;
    Ok(line.trim_end_matches(['\r', '\n']).to_owned())
}

#[cfg(test)]
mod tests {
    use super::{Accounts, Session, now, private_dir, write_private};
    use std::os::unix::fs::PermissionsExt;
    use std::path::PathBuf;

    fn data(name: &str) -> PathBuf {
        let data = std::env::temp_dir().join(format!("studio-{name}-{}", std::process::id()));
        let _ = std::fs::remove_dir_all(&data);
        private_dir(&data).expect("data directory");
        data
    }

    #[test]
    fn a_password_verifies_only_for_its_own_user() {
        let data = data("passwords");
        let accounts = Accounts::new(data.clone());
        accounts
            .add_user("alice", "correct horse")
            .expect("add alice");
        accounts.add_user("bob", "battery staple").expect("add bob");

        assert!(accounts.verify("alice", "correct horse"));
        assert!(!accounts.verify("alice", "correct hors"));
        assert!(!accounts.verify("alice", "battery staple"));
        assert!(!accounts.verify("carol", "correct horse"));
        assert!(accounts.add_user("alice", "again").is_err());
        assert!(accounts.add_user("../alice", "x").is_err());

        // The file holds salted hashes, readable by this user alone.
        let file = data.join("users.toml");
        let text = std::fs::read_to_string(&file).expect("users file");
        assert!(!text.contains("correct horse") && text.contains("$argon2id$"));
        let mode = std::fs::metadata(&file)
            .expect("metadata")
            .permissions()
            .mode();
        assert_eq!(mode & 0o777, 0o600);
        std::fs::remove_dir_all(data).expect("cleanup");
    }

    /// A login survives a restart (a fresh `Accounts` over the same data),
    /// is stored only as a digest, and ends at logout, at expiry, or when its
    /// user is deleted.
    #[test]
    fn a_session_outlives_a_restart_until_it_ends() {
        let data = data("sessions");
        Accounts::new(data.clone())
            .add_user("alice", "pw")
            .expect("add alice");
        let secret = Accounts::new(data.clone())
            .start_session("alice")
            .expect("login");

        let restarted = Accounts::new(data.clone());
        assert_eq!(restarted.session_user(&secret).as_deref(), Some("alice"));
        assert_eq!(restarted.session_user(&secret[1..]), None);
        let stored: Vec<String> = std::fs::read_dir(data.join("sessions"))
            .expect("sessions")
            .map(|entry| std::fs::read_to_string(entry.expect("entry").path()).expect("session"))
            .collect();
        assert_eq!(stored.len(), 1);
        assert!(!stored[0].contains(&secret));

        restarted.end_session(&secret);
        assert_eq!(restarted.session_user(&secret), None);

        // An expired session is refused and pruned.
        let expired = restarted.start_session("alice").expect("login");
        let session = Session {
            user: "alice".to_owned(),
            expires: now() - 1,
        };
        let text = toml::to_string(&session).expect("session");
        write_private(&restarted.session_file(&expired), text.as_bytes()).expect("expire");
        let live = restarted.start_session("alice").expect("login");
        restarted.prune_sessions();
        assert_eq!(
            std::fs::read_dir(data.join("sessions"))
                .expect("sessions")
                .count(),
            1
        );
        assert_eq!(restarted.session_user(&expired), None);

        // Deleting the user from users.toml logs them out everywhere.
        std::fs::write(data.join("users.toml"), "").expect("remove users");
        assert_eq!(restarted.session_user(&live), None);
        std::fs::remove_dir_all(data).expect("cleanup");
    }
}
