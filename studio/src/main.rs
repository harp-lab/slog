//! Slog Studio: a browser workbench for a Slog program — the program above,
//! a REPL over its evaluation below — served from loopback like a local
//! notebook. `./slog studio FILE` runs it.

mod lane;
mod studio;
mod web;

use lane::Lane;
use slog_repl::server::{private_token, project_root};
use std::path::PathBuf;
use std::process::ExitCode;
use std::sync::Arc;
use studio::Studio;

const USAGE: &str = "usage: slog studio [--port N] [--no-open] [--compiled] [FILE]

Edit and evaluate FILE (default ~/.slog-studio/scratch.slog) in the browser.
--port N     listen on 127.0.0.1:N (default: any free port)
--no-open    print the address without opening a browser
--compiled   evaluate with native compilation instead of the interpreter";

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
        None => {
            let home = std::env::var_os("SLOG_STUDIO_HOME")
                .map(PathBuf::from)
                .or_else(|| std::env::var_os("HOME").map(|home| PathBuf::from(home).join(".slog-studio")))
                .ok_or("set HOME or SLOG_STUDIO_HOME")?;
            std::fs::create_dir_all(&home)
                .map_err(|error| format!("cannot create {}: {error}", home.display()))?;
            home.join("scratch.slog")
        }
    };
    std::path::absolute(&file).map_err(|error| format!("{}: {error}", file.display()))
}

#[tokio::main]
async fn main() -> ExitCode {
    match run().await {
        Ok(()) => ExitCode::SUCCESS,
        Err(message) => {
            eprintln!("slog studio: {message}");
            ExitCode::FAILURE
        }
    }
}

async fn run() -> Result<(), String> {
    let Some(options) = options(std::env::args().skip(1))? else {
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
    let env = if options.compiled {
        Vec::new()
    } else {
        vec![("SLOG_OPT", "interp")]
    };
    let studio = Arc::new(Studio::new(file, text, Lane::new(root, env)));
    studio.relay_lane();
    // Start the session server now so the first evaluation does not wait.
    let warm = studio.clone();
    tokio::spawn(async move { warm.lane.command(":ping").await });

    let listener = tokio::net::TcpListener::bind(("127.0.0.1", options.port))
        .await
        .map_err(|error| format!("cannot listen on 127.0.0.1:{}: {error}", options.port))?;
    let address = listener.local_addr().map_err(|error| error.to_string())?;
    let token = private_token().map_err(|error| format!("cannot create a token: {error}"))?;
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
