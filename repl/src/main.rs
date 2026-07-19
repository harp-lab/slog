mod app;
mod backend;
mod editor;
mod library;
mod protocol;
mod share;
mod ui;
mod version;

use app::{App, Effect};
use backend::{Backend, BackendEvent, project_root};
use crossterm::event::{
    DisableMouseCapture, EnableMouseCapture, EventStream, KeyboardEnhancementFlags,
    PopKeyboardEnhancementFlags, PushKeyboardEnhancementFlags,
};
use crossterm::execute;
use futures_util::StreamExt;
use share::{DirectReply, ShareEvent, ShareServer};
use std::collections::VecDeque;
use std::error::Error;
use std::io;

struct TerminalFeatures {
    keyboard_enhancement: bool,
    mouse_capture: bool,
}

enum PendingCommand {
    /// The application already committed the command echo to its transcript.
    SharedReady(String),
    /// Remote burst input is not echoed until it actually begins execution.
    RemoteShared { peer: String, text: String },
    Private {
        peer: String,
        line: String,
        reply: DirectReply,
    },
}

enum InFlight {
    Shared,
    Private { peer: String, reply: DirectReply },
}

async fn launch_pending(
    pending: PendingCommand,
    app: &mut App,
    backend: &Backend,
) -> Result<(Option<InFlight>, Option<String>), String> {
    let (line, flight) = match pending {
        PendingCommand::SharedReady(line) => (line, InFlight::Shared),
        PendingCommand::RemoteShared { peer, text } => match app.on_coauthor(&peer, text) {
            Effect::Execute(line) => (line, InFlight::Shared),
            Effect::Shutdown => {
                app.should_quit = true;
                return Ok((None, None));
            }
            Effect::Ignore | Effect::None => return Ok((None, None)),
        },
        PendingCommand::Private { peer, line, reply } => {
            let _ = reply.send(format!("› {line}  [private]"));
            (line, InFlight::Private { peer, reply })
        }
    };
    let operation = app.begin_operation(&line, backend.daemon_rebuild_pending());
    backend.execute(line).await?;
    Ok((Some(flight), operation))
}

impl TerminalFeatures {
    fn enable() -> Self {
        let mut stdout = io::stdout();
        // The CSI-u push is safe to send optimistically: terminals without
        // progressive keyboard support ignore it. Some compatible terminals
        // do not answer Crossterm's capability query, so gating the push on
        // that query made modifier-bearing Enter unnecessarily ambiguous there.
        let keyboard_enhancement = execute!(
            stdout,
            PushKeyboardEnhancementFlags(
                KeyboardEnhancementFlags::DISAMBIGUATE_ESCAPE_CODES
                    | KeyboardEnhancementFlags::REPORT_ALL_KEYS_AS_ESCAPE_CODES
                    | KeyboardEnhancementFlags::REPORT_ALTERNATE_KEYS
                    | KeyboardEnhancementFlags::REPORT_EVENT_TYPES
            )
        )
        .is_ok();
        let mouse_capture = execute!(stdout, EnableMouseCapture).is_ok();
        Self {
            keyboard_enhancement,
            mouse_capture,
        }
    }
}

impl Drop for TerminalFeatures {
    fn drop(&mut self) {
        let mut stdout = io::stdout();
        if self.mouse_capture {
            let _ = execute!(stdout, DisableMouseCapture);
        }
        if self.keyboard_enhancement {
            let _ = execute!(stdout, PopKeyboardEnhancementFlags);
        }
    }
}

#[tokio::main]
async fn main() -> Result<(), Box<dyn Error>> {
    let root = project_root().map_err(|error| format!("slog: {error}"))?;
    let mut backend = Backend::start(&root)
        .await
        .map_err(|error| format!("slog: {error}"))?;
    let mut share = ShareServer::start(&root)
        .await
        .map_err(|error| format!("slog: {error}"))?;

    let mut terminal = ratatui::init();
    let terminal_features = TerminalFeatures::enable();
    let result = run_repl(&mut terminal, &mut backend, &mut share).await;
    drop(terminal_features);
    ratatui::restore();
    backend.shutdown().await;
    result.map_err(Into::into)
}

async fn run_repl(
    terminal: &mut ratatui::DefaultTerminal,
    backend: &mut Backend,
    share: &mut ShareServer,
) -> Result<(), String> {
    let mut app = App::new();
    app.set_coauthor_info(
        share.endpoint().to_owned(),
        share.registry_path().display().to_string(),
    );
    share.set_current(app.current_database.as_deref())?;
    share.set_snapshot(app.plain_share_snapshot());
    let area = terminal
        .size()
        .map_err(|error| format!("cannot read terminal size: {error}"))?;
    app.set_terminal_size(area.width, area.height);
    let mut terminal_events = EventStream::new();
    let mut animation = tokio::time::interval(tokio::time::Duration::from_millis(120));
    animation.set_missed_tick_behavior(tokio::time::MissedTickBehavior::Skip);
    let mut pending_commands = VecDeque::new();
    let mut in_flight: Option<InFlight> = None;

    loop {
        terminal
            .draw(|frame| ui::draw(frame, &app))
            .map_err(|error| format!("terminal draw failed: {error}"))?;
        if app.should_quit {
            break;
        }

        let transcript_start = app.transcript.len();
        let view_mode_before = app.shared_view_mode();
        let view_key_before = app.shared_view_key();
        let (effect, requested) = tokio::select! {
            event = terminal_events.next() => {
                let effect = match event {
                    Some(Ok(event)) => app.on_terminal(event),
                    Some(Err(error)) => return Err(format!("terminal input failed: {error}")),
                    None => Effect::Shutdown,
                };
                (effect, None)
            }
            event = backend.events.recv() => {
                match event {
                    Some(BackendEvent::Log(line)) => {
                        app.on_backend(BackendEvent::Log(line));
                    }
                    Some(event @ BackendEvent::Response { .. }) => {
                        match in_flight.take() {
                            Some(InFlight::Private { peer, reply }) => {
                                let output = app.on_private_backend(event);
                                let _ = reply.send(format!("{output}\n· private response complete · {peer}"));
                            }
                            Some(InFlight::Shared) | None => app.on_backend(event),
                        }
                    }
                    Some(BackendEvent::Disconnected(message)) => {
                        if let Some(InFlight::Private { reply, .. }) = in_flight.take() {
                            let _ = reply.send(format!("! Server disconnected\n  {message}"));
                        }
                        app.on_backend(BackendEvent::Disconnected(message));
                    }
                    None => app.should_quit = true,
                }
                (Effect::None, None)
            }
            event = share.events.recv() => {
                match event {
                    Some(ShareEvent::Connected { peer, .. }) => {
                        app.add_presence(format!("{peer} connected"));
                        (Effect::None, None)
                    }
                    Some(ShareEvent::Disconnected { peer, .. }) => {
                        app.add_presence(format!("{peer} disconnected"));
                        (Effect::None, None)
                    }
                    Some(ShareEvent::Input { peer, text, reply, .. }) => {
                        let trimmed = text.trim();
                        if trimmed == "/private" {
                            let _ = reply.send("! expected: /private COMMAND".to_owned());
                            (Effect::None, None)
                        } else if let Some(line) = trimmed.strip_prefix("/private ") {
                            let line = line.trim();
                            if line.is_empty() {
                                let _ = reply.send("! expected: /private COMMAND".to_owned());
                                (Effect::None, None)
                            } else if !App::private_command_allowed(line) {
                                let _ = reply.send(
                                    "! private commands are limited to non-mutating observations"
                                        .to_owned(),
                                );
                                (Effect::None, None)
                            } else {
                                let request = PendingCommand::Private {
                                    peer,
                                    line: line.to_owned(),
                                    reply: reply.clone(),
                                };
                                if in_flight.is_some() {
                                    let _ = reply.send(format!(
                                        "… private observation queued at position {}",
                                        pending_commands.len() + 1
                                    ));
                                    pending_commands.push_back(request);
                                    (Effect::None, None)
                                } else {
                                    (Effect::None, Some(request))
                                }
                            }
                        } else if in_flight.is_some()
                            && !trimmed.starts_with(';')
                            && !(app.library.is_some()
                                && App::coauthor_input_is_view_command(trimmed))
                        {
                            let _ = reply.send(format!(
                                "… shared command queued at position {}",
                                pending_commands.len() + 1
                            ));
                            pending_commands.push_back(PendingCommand::RemoteShared { peer, text });
                            (Effect::None, None)
                        } else {
                            (app.on_coauthor(&peer, text), None)
                        }
                    }
                    None => (Effect::Ignore, None),
                }
            }
            _ = animation.tick(), if !app.transient.is_empty() => {
                app.tick();
                (Effect::None, None)
            }
            _ = std::future::ready(()), if in_flight.is_none() && !pending_commands.is_empty() => {
                (Effect::None, pending_commands.pop_front())
            }
        };

        let mut launch = requested;
        let mut started_operation = None;
        match effect {
            Effect::Ignore => {}
            Effect::None => {}
            Effect::Execute(line) => {
                let command = PendingCommand::SharedReady(line);
                if in_flight.is_some() || launch.is_some() {
                    pending_commands.push_back(command);
                } else {
                    launch = Some(command);
                }
            }
            Effect::Shutdown => {
                backend.cancel_in_flight();
                app.should_quit = true;
            }
        }

        if in_flight.is_none() {
            if let Some(command) = launch {
                let (flight, operation) = launch_pending(command, &mut app, backend).await?;
                in_flight = flight;
                started_operation = operation;
            }
        } else if let Some(command) = launch {
            pending_commands.push_back(command);
        }

        for action in app.take_shared_actions() {
            share.publish(App::plain_shared_action(&action));
        }
        for entry in &app.transcript[transcript_start..] {
            share.publish(App::plain_entry(entry));
        }
        if let Some(label) = started_operation {
            share.publish(label);
        }
        for label in app.take_progress_updates() {
            share.publish(label);
        }
        let view_mode_after = app.shared_view_mode();
        let view_key_after = app.shared_view_key();
        if view_mode_after != view_mode_before {
            share.publish(app.plain_shared_view(true));
        } else if view_key_after != view_key_before {
            share.publish(app.plain_shared_view(false));
        }
        share.set_current(app.current_database.as_deref())?;
        share.set_snapshot(app.plain_share_snapshot());
    }
    Ok(())
}
