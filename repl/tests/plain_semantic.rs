use std::fs;
use std::io::Write;
use std::path::Path;
use std::process::{Command, Stdio};

const SEMANTIC_COMMANDS: &str = "\
open sess_w2.edb
add edge 1 2
add edge 4 5
del edge 4 5
table (deg2 int int) rule (deg2 X Z) <-- (edge X Y) (edge Y Z)
scratch
rename edge input_edge
drop path
:quit
";

#[test]
fn plain_executable_matches_the_semantic_session_golden() {
    let manifest = Path::new(env!("CARGO_MANIFEST_DIR"));
    let root = manifest
        .parent()
        .expect("repl crate lives below repository");
    let golden = fs::read_to_string(root.join("tests/expected/repl/semantic-session.txt"))
        .expect("semantic session golden");

    let mut child = Command::new(env!("CARGO_BIN_EXE_slog"))
        .arg("--plain")
        .current_dir(root)
        .env("SLOG_ROOT", root)
        .env("SLOG_NO_MEM_CAP", "1")
        .stdin(Stdio::piped())
        .stdout(Stdio::piped())
        .stderr(Stdio::piped())
        .spawn()
        .expect("start the real plain REPL executable");
    child
        .stdin
        .take()
        .expect("plain input pipe")
        .write_all(SEMANTIC_COMMANDS.as_bytes())
        .expect("write semantic command stream");
    let output = child.wait_with_output().expect("wait for plain REPL");

    assert!(
        output.status.success(),
        "plain REPL failed with {}\nstdout:\n{}\nstderr:\n{}",
        output.status,
        String::from_utf8_lossy(&output.stdout),
        String::from_utf8_lossy(&output.stderr)
    );
    assert_eq!(
        String::from_utf8(output.stdout).expect("plain output is UTF-8"),
        golden
    );
}

#[test]
fn help_is_headless_and_does_not_require_a_project_or_terminal() {
    let output = Command::new(env!("CARGO_BIN_EXE_slog"))
        .arg("--help")
        .current_dir(std::env::temp_dir())
        .output()
        .expect("run plain CLI help");
    assert!(output.status.success());
    let stdout = String::from_utf8(output.stdout).expect("help is UTF-8");
    assert!(stdout.starts_with("usage: slog [--plain]\n"));
    assert!(stdout.contains("--plain  read one command per input line"));
    assert!(output.stderr.is_empty());
}

#[test]
fn redirected_stdout_selects_plain_mode_and_eof_shuts_down() {
    let manifest = Path::new(env!("CARGO_MANIFEST_DIR"));
    let root = manifest
        .parent()
        .expect("repl crate lives below repository");
    let mut child = Command::new(env!("CARGO_BIN_EXE_slog"))
        .current_dir(root)
        .env("SLOG_ROOT", root)
        .env("SLOG_NO_MEM_CAP", "1")
        .stdin(Stdio::piped())
        .stdout(Stdio::piped())
        .stderr(Stdio::piped())
        .spawn()
        .expect("start redirected REPL executable");
    child
        .stdin
        .take()
        .expect("redirected input pipe")
        .write_all(b":status\n")
        .expect("write status command");
    let output = child.wait_with_output().expect("wait for redirected REPL");
    assert!(
        output.status.success(),
        "redirected REPL failed: {}",
        String::from_utf8_lossy(&output.stderr)
    );
    let stdout = String::from_utf8(output.stdout).expect("plain output is UTF-8");
    assert!(stdout.starts_with("› :status\n◆ REPL status\n"));
    assert!(stdout.contains("\n  current: none\n"));
    assert!(stdout.ends_with("  resident databases: 0\n"));
    assert!(!stdout.contains('\u{1b}'));
}
