mod app;
mod backend;
mod editor;
mod protocol;
mod ui;

use app::{App, Effect};
use backend::{Backend, project_root};
use crossterm::event::EventStream;
use futures_util::StreamExt;
use std::error::Error;

#[tokio::main]
async fn main() -> Result<(), Box<dyn Error>> {
    let root = project_root().map_err(|error| format!("slog: {error}"))?;
    let mut backend = Backend::start(&root)
        .await
        .map_err(|error| format!("slog: {error}"))?;

    let mut terminal = ratatui::init();
    let result = run_repl(&mut terminal, &mut backend).await;
    ratatui::restore();
    backend.shutdown().await;
    result.map_err(Into::into)
}

async fn run_repl(
    terminal: &mut ratatui::DefaultTerminal,
    backend: &mut Backend,
) -> Result<(), String> {
    let mut app = App::new();
    let mut terminal_events = EventStream::new();

    loop {
        terminal
            .draw(|frame| ui::draw(frame, &app))
            .map_err(|error| format!("terminal draw failed: {error}"))?;
        if app.should_quit {
            break;
        }

        let effect = tokio::select! {
            event = terminal_events.next() => {
                match event {
                    Some(Ok(event)) => app.on_terminal(event),
                    Some(Err(error)) => return Err(format!("terminal input failed: {error}")),
                    None => Effect::Shutdown,
                }
            }
            event = backend.events.recv() => {
                match event {
                    Some(event) => app.on_backend(event),
                    None => app.should_quit = true,
                }
                Effect::None
            }
        };

        match effect {
            Effect::None => {}
            Effect::Execute(line) => {
                backend.execute(line).await?;
            }
            Effect::Shutdown => {
                app.should_quit = true;
            }
        }
    }
    Ok(())
}
