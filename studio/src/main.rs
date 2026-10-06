//! Slog Studio: a browser workbench for a Slog program — the program above,
//! a REPL over its evaluation below — served from loopback like a local
//! notebook. `./slog studio FILE` runs it.
//!
//! `slog-studio serve` runs the same studio for many users, who log in and
//! each get their own projects. Local mode is that server with one user,
//! `local`, admitted by the launch token, and its data in the studio home.

mod accounts;
mod agent;
mod ask;
mod auth;
mod forms;
mod hash;
mod lane;
mod mcp;
mod projects;
mod registry;
mod review;
mod results;
mod scenario;
mod session;
mod store;
mod studio;
mod summary;
mod trace;
mod versions;
mod web;

use accounts::Accounts;
use auth::Gate;
use lane::Mode;
use registry::{LOCAL_USER, Limits, Registry};
use slog_repl::server::{private_token, project_root};
use std::path::PathBuf;
use std::process::ExitCode;
use std::sync::Arc;
use std::time::Duration;

const USAGE: &str = "usage: slog studio [--port N] [--no-open] [--compiled] [FILE]
       slog studio scenario [--json] FILE.scenario.toml...
       slog-studio serve --data DIR [--bind ADDRESS] [--max-lanes N] [--idle-minutes N]
       slog-studio user add NAME --data DIR

Edit and evaluate a project of Slog files in the browser. FILE opens the
project of FILE's directory, with FILE as the main file; without it, the
project opened last. Projects and their versions live in SLOG_STUDIO_HOME
(default ~/.slog-studio).
--port N     listen on 127.0.0.1:N (default: any free port)
--no-open    print the address without opening a browser
--compiled   evaluate with native code (-O2) from the start

Each save and run is summarized in the background by `claude -p` when it is
on PATH (STUDIO_SUMMARY_MODEL picks its model), and by STUDIO_ANALYZER, a
command run as `CMD analyze --program FILE --eval EVAL.json`, when set.

`scenario` runs scenario files headless and reports each check and step;
it exits non-zero if any fails. --json prints the reports as JSON.

`serve` runs the studio for many users, on ADDRESS (default 127.0.0.1:7200).
Each logs in as a user added by `user add` and has their own projects under
DIR/users/; a page's ?project=NAME picks one. With TRUST_PROXY_AUTH=1 a
reverse proxy logs users in instead and names them in the Remote-User
header. Each user runs at most --max-lanes session servers (default 4),
and a server unused for --idle-minutes (default 30) stops.";

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

/// The program named on the command line, made absolute: `run` resolves
/// relative paths against the repository, not the directory Studio was
/// started from.
fn program_file(file: &std::path::Path) -> Result<PathBuf, String> {
    std::path::absolute(file).map_err(|error| format!("{}: {error}", file.display()))
}

/// Studio's own directory: `SLOG_STUDIO_HOME`, else `~/.slog-studio`, made
/// absolute for the same reason, since projects are evaluated in it.
fn studio_home() -> Result<PathBuf, String> {
    let home = std::env::var_os("SLOG_STUDIO_HOME")
        .map(PathBuf::from)
        .or_else(|| std::env::var_os("HOME").map(|home| PathBuf::from(home).join(".slog-studio")))
        .ok_or("set HOME or SLOG_STUDIO_HOME")?;
    std::fs::create_dir_all(&home)
        .map_err(|error| format!("cannot create {}: {error}", home.display()))?;
    std::path::absolute(&home).map_err(|error| format!("{}: {error}", home.display()))
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
    let outcome = match args.peek().map(String::as_str) {
        Some("scenario") => scenarios(args.skip(1)).await,
        Some("serve") => serve_shared(args.skip(1)).await.map(|()| true),
        Some("user") => accounts::user_command(args.skip(1)).map(|()| true),
        _ => serve_local(args).await.map(|()| true),
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

async fn serve_local(args: impl Iterator<Item = String>) -> Result<(), String> {
    let Some(options) = options(args)? else {
        println!("{USAGE}");
        return Ok(());
    };
    let home = studio_home()?;
    let file = options.file.map(|file| program_file(&file)).transpose()?;
    let mode = if options.compiled { Mode::Compiled } else { Mode::Fast };
    // One user, no limits, and FILE's project as the default.
    let registry = Arc::new(Registry::new(project_root()?, home.clone(), mode, file, None));
    // Start the session server now so the first evaluation does not wait.
    web::warm(registry.open(LOCAL_USER, "")?);

    let listener = tokio::net::TcpListener::bind(("127.0.0.1", options.port))
        .await
        .map_err(|error| format!("cannot listen on 127.0.0.1:{}: {error}", options.port))?;
    let address = listener.local_addr().map_err(|error| error.to_string())?;
    let token = launch_token(&home)?;
    let url = format!("http://{address}/#{token}");
    println!("Slog Studio: {url}");
    if options.open {
        open_browser(&url);
    }
    run(listener, registry, Gate::Token(token)).await
}

struct ServeOptions {
    bind: String,
    data: PathBuf,
    limits: Limits,
}

/// `Ok(None)` asks for the usage text.
fn serve_options(args: impl IntoIterator<Item = String>) -> Result<Option<ServeOptions>, String> {
    let mut options = ServeOptions {
        bind: "127.0.0.1:7200".to_owned(),
        data: PathBuf::new(),
        limits: Limits {
            lanes: 4,
            idle: Duration::from_secs(30 * 60),
        },
    };
    let count = |flag: &str, value: Option<String>| {
        value
            .and_then(|value| value.parse::<u64>().ok())
            .filter(|&n| n > 0)
            .ok_or(format!("{flag} needs a positive number"))
    };
    let mut args = args.into_iter();
    while let Some(arg) = args.next() {
        match arg.as_str() {
            "--bind" => options.bind = args.next().ok_or("--bind needs an address")?,
            "--data" => options.data = args.next().ok_or("--data needs a directory")?.into(),
            "--max-lanes" => options.limits.lanes = count(&arg, args.next())? as usize,
            "--idle-minutes" => {
                options.limits.idle = Duration::from_secs(60 * count(&arg, args.next())?);
            }
            "-h" | "--help" => return Ok(None),
            _ => return Err(format!("unexpected {arg}\n{USAGE}")),
        }
    }
    if options.data.as_os_str().is_empty() {
        return Err(format!("serve needs --data DIR\n{USAGE}"));
    }
    Ok(Some(options))
}

async fn serve_shared(args: impl Iterator<Item = String>) -> Result<(), String> {
    let Some(options) = serve_options(args)? else {
        println!("{USAGE}");
        return Ok(());
    };
    let data = std::path::absolute(&options.data)
        .map_err(|error| format!("{}: {error}", options.data.display()))?;
    accounts::private_dir(&data)?;
    let listener = tokio::net::TcpListener::bind(&options.bind)
        .await
        .map_err(|error| format!("cannot listen on {}: {error}", options.bind))?;
    let address = listener.local_addr().map_err(|error| error.to_string())?;
    let proxy = matches!(std::env::var("TRUST_PROXY_AUTH").as_deref(), Ok("1" | "true"));
    let gate = if proxy {
        if !address.ip().is_loopback() {
            eprintln!(
                "slog studio: warning: TRUST_PROXY_AUTH believes any Remote-User header; \
                 {address} must be reachable only through the proxy"
            );
        }
        Gate::Proxy
    } else {
        let accounts = Accounts::new(data.clone());
        accounts.prune_sessions();
        if accounts.is_empty()? {
            eprintln!(
                "slog studio: nobody can log in yet; add a user with \
                 `slog-studio user add NAME --data {}`",
                data.display()
            );
        }
        Gate::Login(Arc::new(accounts))
    };
    let limits = Some(options.limits);
    let registry = Arc::new(Registry::new(project_root()?, data, Mode::Fast, None, limits));
    registry.stop_idle_lanes();
    println!("Slog Studio: http://{address}/");
    run(listener, registry, gate).await
}

/// Serve until Ctrl-C, then stop every lane.
async fn run(
    listener: tokio::net::TcpListener,
    registry: Arc<Registry>,
    gate: Gate,
) -> Result<(), String> {
    let port = listener.local_addr().map_err(|error| error.to_string())?.port();
    // Agent runs connect back to this port.
    registry.set_port(port);
    let served = axum::serve(listener, web::router(registry.clone(), gate))
        .with_graceful_shutdown(async {
            let _ = tokio::signal::ctrl_c().await;
        })
        .await;
    registry.shutdown().await;
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
