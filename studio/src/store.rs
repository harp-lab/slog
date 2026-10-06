//! A plain content-addressed file store, with no database engine
//! (studio-design.md §4.3). One store holds one project:
//!
//! ```text
//! objects/ab/cdef…   blobs (file contents) and trees (JSON path -> blob),
//!                    named by hash, written once
//! <name>.log         append-only JSONL, one fsync per record
//! <name>.json        small mutable records, replaced atomically
//! ```
//!
//! Crash safety rests on three rules. An object is written to a temporary
//! file, fsynced, and renamed into place, so it is either whole or absent.
//! A log record is one `write` of a line ending in `\n`, so a crash can only
//! leave an unterminated last line, which loading ignores and cuts off. A
//! mutable record is replaced by rename, never rewritten in place.
//!
//! Every file is plain JSON or text, so any copy tool makes a consistent
//! backup: objects never change, and logs only grow.

use crate::hash::Hash;
use serde::Serialize;
use serde::de::DeserializeOwned;
use std::collections::BTreeMap;
use std::fs::{self, File, OpenOptions};
use std::io::{self, ErrorKind, Write};
use std::path::{Path, PathBuf};
use std::sync::atomic::{AtomicU64, Ordering};

/// A file tree: path within the project -> blob.
pub type Tree = BTreeMap<String, Hash>;

/// A file tree with its contents: path within the project -> text.
pub type Files = BTreeMap<String, String>;

pub struct Store {
    dir: PathBuf,
}

impl Store {
    pub fn open(dir: &Path) -> io::Result<Self> {
        fs::create_dir_all(dir.join("objects"))?;
        Ok(Self {
            dir: dir.to_owned(),
        })
    }

    /// Store `bytes` once; storing them again is a no-op that returns the
    /// same hash.
    pub fn put(&self, bytes: &[u8]) -> io::Result<Hash> {
        let hash = Hash::of(bytes);
        let path = self.object(hash);
        match fs::read(&path) {
            Ok(existing) if existing == bytes => return Ok(hash),
            Ok(_) => {
                return Err(io::Error::other(format!(
                    "{} holds other content than its hash names",
                    path.display()
                )));
            }
            Err(error) if error.kind() == ErrorKind::NotFound => {}
            Err(error) => return Err(error),
        }
        fs::create_dir_all(path.parent().expect("objects have a directory"))?;
        write_atomic(&path, bytes)?;
        Ok(hash)
    }

    pub fn get(&self, hash: Hash) -> io::Result<Vec<u8>> {
        fs::read(self.object(hash))
    }

    /// Store each file's text and the tree naming them; returns the tree.
    pub fn put_files(&self, files: &Files) -> io::Result<Hash> {
        let tree = files
            .iter()
            .map(|(path, text)| Ok((path.clone(), self.put(text.as_bytes())?)))
            .collect::<io::Result<Tree>>()?;
        self.put(&to_json(&tree))
    }

    pub fn get_files(&self, tree: Hash) -> io::Result<Files> {
        let tree: Tree = from_json(&self.get(tree)?)?;
        tree.into_iter()
            .map(|(path, blob)| {
                let text = String::from_utf8(self.get(blob)?)
                    .map_err(|error| io::Error::new(ErrorKind::InvalidData, error))?;
                Ok((path, text))
            })
            .collect()
    }

    /// The records of log `name`, oldest first. An unterminated last line is
    /// what a crash mid-append leaves; it is ignored, and cut off so the next
    /// append starts a line of its own.
    pub fn load_log<T: DeserializeOwned>(&self, name: &str) -> io::Result<Vec<T>> {
        let path = self.dir.join(format!("{name}.log"));
        let bytes = match fs::read(&path) {
            Ok(bytes) => bytes,
            Err(error) if error.kind() == ErrorKind::NotFound => return Ok(Vec::new()),
            Err(error) => return Err(error),
        };
        let whole = bytes
            .iter()
            .rposition(|&b| b == b'\n')
            .map_or(0, |end| end + 1);
        let records = bytes[..whole]
            .split(|&b| b == b'\n')
            .filter(|line| !line.is_empty())
            .map(from_json)
            .collect::<io::Result<Vec<T>>>()?;
        if whole < bytes.len() {
            let file = OpenOptions::new().write(true).open(&path)?;
            file.set_len(whole as u64)?;
            file.sync_all()?;
        }
        Ok(records)
    }

    /// Append one record to log `name`, durably.
    pub fn append_log<T: Serialize>(&self, name: &str, record: &T) -> io::Result<()> {
        let mut line = to_json(record);
        line.push(b'\n');
        let mut file = OpenOptions::new()
            .create(true)
            .append(true)
            .open(self.dir.join(format!("{name}.log")))?;
        file.write_all(&line)?;
        file.sync_data()
    }

    /// Mutable record `name` (a path relative to the store, without
    /// `.json`), or `None` if it was never written.
    pub fn read<T: DeserializeOwned>(&self, name: &str) -> io::Result<Option<T>> {
        match fs::read(self.dir.join(format!("{name}.json"))) {
            Ok(bytes) => from_json(&bytes).map(Some),
            Err(error) if error.kind() == ErrorKind::NotFound => Ok(None),
            Err(error) => Err(error),
        }
    }

    pub fn write<T: Serialize>(&self, name: &str, record: &T) -> io::Result<()> {
        let path = self.dir.join(format!("{name}.json"));
        fs::create_dir_all(path.parent().expect("records live in the store"))?;
        write_atomic(&path, &to_json(record))
    }

    fn object(&self, hash: Hash) -> PathBuf {
        let hex = hash.to_string();
        self.dir.join("objects").join(&hex[..2]).join(&hex[2..])
    }
}

/// Replace `path` with `bytes` so that a crash leaves the old content or the
/// new, never a mixture: write a temporary file beside it, fsync, rename, and
/// fsync the directory so the rename itself is durable.
pub fn write_atomic(path: &Path, bytes: &[u8]) -> io::Result<()> {
    static TEMPORARIES: AtomicU64 = AtomicU64::new(0);
    let directory = path.parent().expect("a file has a directory");
    let name = path
        .file_name()
        .expect("a file has a name")
        .to_string_lossy();
    let temporary = directory.join(format!(
        ".{name}.{}.{}.tmp",
        std::process::id(),
        TEMPORARIES.fetch_add(1, Ordering::Relaxed)
    ));
    let written = (|| {
        let mut file = File::create(&temporary)?;
        file.write_all(bytes)?;
        file.sync_all()?;
        fs::rename(&temporary, path)
    })();
    if written.is_err() {
        let _ = fs::remove_file(&temporary);
    }
    written?;
    File::open(directory)?.sync_all()
}

fn to_json<T: Serialize>(value: &T) -> Vec<u8> {
    serde_json::to_vec(value).expect("store records serialize")
}

fn from_json<T: DeserializeOwned>(bytes: &[u8]) -> io::Result<T> {
    serde_json::from_slice(bytes).map_err(|error| io::Error::new(ErrorKind::InvalidData, error))
}

#[cfg(test)]
pub mod tests {
    use super::{Files, Store};
    use std::path::{Path, PathBuf};

    /// A fresh directory under the system's temporary directory, removed
    /// when dropped.
    pub struct Scratch(pub PathBuf);

    impl Scratch {
        pub fn new(label: &str) -> Self {
            use std::sync::atomic::{AtomicU64, Ordering};
            static NEXT: AtomicU64 = AtomicU64::new(0);
            let dir = std::env::temp_dir().join(format!(
                "slog-studio-{label}-{}-{}",
                std::process::id(),
                NEXT.fetch_add(1, Ordering::Relaxed)
            ));
            let _ = std::fs::remove_dir_all(&dir);
            std::fs::create_dir_all(&dir).expect("scratch directory");
            Self(dir)
        }

        pub fn path(&self) -> &Path {
            &self.0
        }
    }

    impl Drop for Scratch {
        fn drop(&mut self) {
            let _ = std::fs::remove_dir_all(&self.0);
        }
    }

    fn objects(dir: &Path) -> usize {
        walk(&dir.join("objects"))
    }

    fn walk(dir: &Path) -> usize {
        std::fs::read_dir(dir)
            .unwrap()
            .map(|entry| {
                let path = entry.unwrap().path();
                if path.is_dir() { walk(&path) } else { 1 }
            })
            .sum()
    }

    #[test]
    fn identical_content_is_stored_once() {
        let scratch = Scratch::new("dedup");
        let store = Store::open(scratch.path()).unwrap();
        let files = |main: &str| {
            Files::from([
                ("main.slog".into(), main.into()),
                ("lib.slog".into(), "table (t int)\n".into()),
            ])
        };

        let first = store.put_files(&files("rule (t 1)\n")).unwrap();
        assert_eq!(objects(scratch.path()), 3, "two blobs and a tree");
        assert_eq!(store.put_files(&files("rule (t 1)\n")).unwrap(), first);
        assert_eq!(objects(scratch.path()), 3);

        // a changed file adds its blob and a tree; the unchanged one is shared
        let second = store.put_files(&files("rule (t 2)\n")).unwrap();
        assert_ne!(second, first);
        assert_eq!(objects(scratch.path()), 5);
        assert_eq!(store.get_files(first).unwrap(), files("rule (t 1)\n"));
    }

    #[test]
    fn an_object_whose_content_does_not_match_its_name_is_refused() {
        let scratch = Scratch::new("collision");
        let store = Store::open(scratch.path()).unwrap();
        let hash = store.put(b"rule (t 1)").unwrap();
        std::fs::write(store.object(hash), b"something else").unwrap();
        assert!(store.put(b"rule (t 1)").is_err());
    }

    /// A crash mid-append leaves an unterminated line: loading skips it and
    /// cuts it off, so the next record lands on a line of its own.
    #[test]
    fn a_torn_last_log_line_is_ignored_and_repaired() {
        let scratch = Scratch::new("torn");
        let store = Store::open(scratch.path()).unwrap();
        store.append_log("versions", &1).unwrap();
        store.append_log("versions", &2).unwrap();
        let log = scratch.path().join("versions.log");
        let mut bytes = std::fs::read(&log).unwrap();
        bytes.extend_from_slice(b"{\"id\":3,\"par");
        std::fs::write(&log, bytes).unwrap();

        assert_eq!(store.load_log::<u32>("versions").unwrap(), vec![1, 2]);
        store.append_log("versions", &3).unwrap();
        assert_eq!(store.load_log::<u32>("versions").unwrap(), vec![1, 2, 3]);
    }

    /// Damage anywhere but the tail is not a torn append; it is reported
    /// rather than skipped, so no history is silently lost.
    #[test]
    fn a_damaged_complete_log_line_is_an_error() {
        let scratch = Scratch::new("damaged");
        let store = Store::open(scratch.path()).unwrap();
        std::fs::write(scratch.path().join("versions.log"), "1\n{oops\n3\n").unwrap();
        assert!(store.load_log::<u32>("versions").is_err());
    }
}
