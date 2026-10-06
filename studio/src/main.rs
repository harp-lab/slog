//! Slog Studio: a browser workbench for a Slog program — the program above,
//! a REPL over its evaluation below — served from loopback like a local
//! notebook. `./slog studio FILE` runs it.

mod agent;
mod ask;
mod lane;
mod mcp;
mod review;
mod scenario;
mod session;
mod studio;
mod web;

use lane::{Lane, Mode};
use slog_repl::server::{private_token, project_root};
use std::path::PathBuf;
use std::process::ExitCode;
use std::sync::Arc;
use studio::Studio;

const USAGE: &str = "usage: slog studio [--port N] [--no-open] [--compiled] [FILE]
       slog studio scenario [--json] FILE.scenario.toml...

Edit and evaluate FILE (default ~/.slog-studio/scratch.slog) in the browser.
--port N     listen on 127.0.0.1:N (default: any free port)
--no-open    print the address without opening a browser
--compiled   evaluate with native compilation instead of the interpreter

`scenario` runs scenario files headless and reports each check and step;
it exits non-zero if any fails. --json prints the reports as JSON.";

struct Options {
    file: Option<PathBuf>,
    port: u16,
    open: bool,
    compiled: bool,
}

/// `Ok(None)` asks for the usage text.
fn options(args: impl IntoIterator<Item = String>) -> Result<Option<Options>, String> {
    let mut options = Options {
        file: None,
        port: 0,
        open: true,
        compiled: false,
    };
    let mut args = args.into_iter();
    while let Some(arg) = args.next() {
        match arg.as_str() {
            "--port" => {
                options.port = args
                    .next()
                    .and_then(|port| port.parse().ok())
                    .ok_or("--port needs a port number")?;
            }
            "--no-open" => options.open = false,
            "--compiled" => options.compiled = true,
            "-h" | "--help" => return Ok(None),
            flag if flag.starts_with('-') => return Err(format!("unknown option {flag}\n{USAGE}")),
            file if options.file.is_none() => options.file = Some(PathBuf::from(file)),
            _ => return Err(USAGE.to_owned()),
        }
    }
    Ok(Some(options))
}

/// The program to edit, made absolute: `run` resolves relative paths against
/// the repository, not the directory Studio was started from.
fn program_file(file: Option<PathBuf>) -> Result<PathBuf, String> {
    let file = match file {
        Some(file) => file,
        None => studio_home()?.join("scratch.slog"),
    };
    std::path::absolute(&file).map_err(|error| format!("{}: {error}", file.display()))
}

/// Studio's own directory: `SLOG_STUDIO_HOME`, else `~/.slog-studio`.
fn studio_home() -> Result<PathBuf, String> {
    let home = std::env::var_os("SLOG_STUDIO_HOME")
        .map(PathBuf::from)
        .or_else(|| std::env::var_os("HOME").map(|home| PathBuf::from(home).join(".slog-studio")))
        .ok_or("set HOME or SLOG_STUDIO_HOME")?;
    std::fs::create_dir_all(&home)
        .map_err(|error| format!("cannot create {}: {error}", home.display()))?;
    Ok(home)
}

/// The token that admits a browser tab. It is kept (readable only by this
/// user) and reused, so a restarted studio keeps its address and an open
/// tab simply reconnects.
fn launch_token(home: &std::path::Path) -> Result<String, String> {
    use std::io::Write;
    use std::os::unix::fs::OpenOptionsExt;
    let path = home.join("token");
    if let Ok(token) = std::fs::read_to_string(&path)
        && token.len() == 64
        && token.bytes().all(|byte| byte.is_ascii_hexdigit())
    {
        return Ok(token);
    }
    let token = private_token().map_err(|error| format!("cannot create a token: {error}"))?;
    std::fs::OpenOptions::new()
        .write(true)
        .create(true)
        .truncate(true)
        .mode(0o600)
        .open(&path)
        .and_then(|mut file| file.write_all(token.as_bytes()))
        .map_err(|error| format!("cannot write {}: {error}", path.display()))?;
    Ok(token)
}

#[tokio::main]
async fn main() -> ExitCode {
    let mut args = std::env::args().skip(1).peekable();
    let outcome = if args.peek().map(String::as_str) == Some("scenario") {
        scenarios(args.skip(1)).await
    } else {
        serve(args).await.map(|()| true)
    };
    match outcome {
        Ok(true) => ExitCode::SUCCESS,
        // The reports already said what failed.
        Ok(false) => ExitCode::FAILURE,
        Err(message) => {
            eprintln!("slog studio: {message}");
            ExitCode::FAILURE
        }
    }
}

/// Run scenario files; true when every one passed.
async fn scenarios(args: impl Iterator<Item = String>) -> Result<bool, String> {
    let (flags, files): (Vec<String>, Vec<String>) = args.partition(|arg| arg.starts_with('-'));
    let json = match flags.as_slice() {
        [] => false,
        [flag] if flag == "--json" => true,
        _ => return Err(USAGE.to_owned()),
    };
    if files.is_empty() {
        return Err(USAGE.to_owned());
    }
    let root = project_root()?;
    let mut reports = Vec::new();
    for file in &files {
        let report = scenario::run(&root, std::path::Path::new(file)).await?;
        if !json {
            print_report(&report);
        }
        reports.push(report);
    }
    if json {
        println!("{}", serde_json::to_string_pretty(&reports).map_err(|error| error.to_string())?);
    }
    Ok(reports.iter().all(scenario::Report::passed))
}

fn print_report(report: &scenario::Report) {
    println!("{} — {}", report.id, report.title);
    if let Some(setup) = &report.setup {
        println!("  ✗ {setup}");
    }
    let judged = report
        .checks
        .iter()
        .map(|check| (format!("check {}", check.what), &check.verdict))
        .chain(report.steps.iter().map(|step| (step.what.clone(), &step.verdict)));
    for (what, verdict) in judged {
        match verdict {
            scenario::Verdict::Pass => println!("  ✓ {what}"),
            scenario::Verdict::Xfail(why) => println!("  ~ {what}   (expected failure: {why})"),
            scenario::Verdict::Fail(why) => println!("  ✗ {what}\n      {why}"),
        }
    }
    let count = |n: usize, noun: &str| format!("{n} {noun}{}", if n == 1 { "" } else { "s" });
    println!(
        "  {} ({}, {})\n",
        if report.passed() { "PASS" } else { "FAIL" },
        count(report.checks.len(), "check"),
        count(report.steps.len(), "step")
    );
}

async fn serve(args: impl Iterator<Item = String>) -> Result<(), String> {
    let Some(options) = options(args)? else {
        println!("{USAGE}");
        return Ok(());
    };
    let root = project_root()?;
    let file = program_file(options.file)?;
    let text = match std::fs::read_to_string(&file) {
        Ok(text) => text,
        Err(error) if error.kind() == std::io::ErrorKind::NotFound => String::new(),
        Err(error) => return Err(format!("cannot read {}: {error}", file.display())),
    };
    // The interpreter skips the C++ toolchain, which is what an edit-evaluate
    // loop wants; it is also what breakpoints and stepping need.
    let mode = if options.compiled { Mode::Compiled } else { Mode::Fast };
    // Admits this launch's agent runs to /mcp; they get it in a 0600 file.
    let mcp_token = private_token().map_err(|error| format!("cannot create a token: {error}"))?;
    let studio = Arc::new(Studio::new(file, text, Lane::new(root, mode), mcp_token));
    studio.relay_lane();
    // Start the session server now so the first evaluation does not wait.
    web::warm(studio.clone());

    let listener = tokio::net::TcpListener::bind(("127.0.0.1", options.port))
        .await
        .map_err(|error| format!("cannot listen on 127.0.0.1:{}: {error}", options.port))?;
    let address = listener.local_addr().map_err(|error| error.to_string())?;
    studio.set_port(address.port());
    let token = launch_token(&studio_home()?)?;
    let url = format!("http://{address}/#{token}");
    println!("Slog Studio: {url}");
    if options.open {
        open_browser(&url);
    }

    let app = web::router(studio.clone(), token);
    let served = axum::serve(listener, app)
        .with_graceful_shutdown(async {
            let _ = tokio::signal::ctrl_c().await;
        })
        .await;
    studio.lane.shutdown().await;
    served.map_err(|error| error.to_string())
}

/// Best effort: the address is printed either way.
fn open_browser(url: &str) {
    let opener = if cfg!(target_os = "macos") { "open" } else { "xdg-open" };
    let _ = std::process::Command::new(opener)
        .arg(url)
        .stdout(std::process::Stdio::null())
        .stderr(std::process::Stdio::null())
        .spawn();
}
