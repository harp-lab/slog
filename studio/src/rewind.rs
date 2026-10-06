//! Debugging after the fixpoint. A breakpoint stops a run, and once the
//! program has reached its fixpoint nothing runs again: incremental
//! maintenance (`add`, `del`) never stops at a breakpoint either. So when
//! a debug action could not stop because the work already happened,
//! Studio goes back to a point before it ran instead -- as a branch, so
//! the line the author was on stays whole in the state tree.
//!
//! - Debug, on a program unchanged since its last Run and with nothing
//!   changed since, reruns it from scratch as a branch from the state
//!   before that Run, and says so quietly.
//! - When there were changes after the Run, where to go back to is the
//!   author's choice: a dialog offers the rerun from scratch, a state to
//!   branch from, or nothing.
//! - A breakpoint set once the program reached its fixpoint gets the same
//!   dialog.

use crate::states::Kind;
use crate::studio::{Event, Studio};
use serde::Serialize;

/// A state the dialog offers to go back to.
#[derive(Clone, Debug, Serialize)]
pub struct Choice {
    pub id: u64,
    pub label: String,
    pub line: String,
}

/// Where Debug goes when the program it would run already ran.
#[derive(Debug, Eq, PartialEq)]
pub(crate) enum Rewind {
    /// Nothing ran yet on this line, or the program changed: run as usual.
    Run,
    /// Rerun from scratch as a branch from this state, the one before the
    /// Run.
    Rerun(u64),
    /// Changes followed the Run: ask.
    Ask,
}

impl Studio {
    /// What Debug should do, given the head version it would run.
    pub(crate) fn rewind(&self, head: Option<u64>) -> Rewind {
        let states = self.states();
        let (run, changes) = states.replay(states.current);
        match run {
            Some(run) if run.version == head && head.is_some() => {
                if changes.is_empty() {
                    Rewind::Rerun(run.pred.unwrap_or(0))
                } else {
                    Rewind::Ask
                }
            }
            _ => Rewind::Run,
        }
    }

    /// The states the author can go back to on the current line, newest
    /// first: each Run and change, and where it began.
    fn choices(&self) -> Vec<Choice> {
        let states = self.states();
        let mut out = Vec::new();
        let mut at = states.get(states.current);
        while let Some(state) = at {
            if matches!(state.kind, Kind::Run | Kind::Change | Kind::Start | Kind::Branch) {
                out.push(Choice { id: state.id, label: states.label(state.id), line: state.line.clone() });
            }
            if state.kind == Kind::Start {
                break;
            }
            at = state.pred.and_then(|pred| states.get(pred));
        }
        out
    }

    /// Ask where to go back to: `why` says what cannot stop, and the
    /// default is the state before the last Run.
    pub(crate) fn ask_rewind(&self, why: String) {
        let default = {
            let states = self.states();
            states.replay(states.current).0.and_then(|run| run.pred)
        };
        self.publish(Event::Rewind { message: why, default, choices: self.choices() });
    }

    /// Debug from state `from`: none reruns the program from scratch as a
    /// branch from the state before its last Run; a state branches from it,
    /// re-deriving it with the breaks armed, so a Run among its steps stops
    /// there.
    pub async fn debug_from(&self, from: Option<u64>) {
        match from {
            None => {
                let pred = {
                    let states = self.states();
                    states.replay(states.current).0.and_then(|run| run.pred).unwrap_or(0)
                };
                self.debug_rerun(pred).await;
            }
            Some(id) => {
                let breaks = self.break_lines();
                let prepare: Vec<String> =
                    std::iter::once("calls on".to_owned()).chain(breaks.iter().map(|(_, line)| line.clone())).collect();
                let outcomes = self.branch_state_with(id, &prepare).await;
                let mut session = self.session_lock().await;
                self.note_armed(&breaks, &outcomes);
                self.publish_status(&mut session).await;
            }
        }
    }

    /// The breakpoints of a file changed: one was added after the program
    /// reached its fixpoint, so it cannot stop until the program runs
    /// again. Say so; when the database changed since the Run, where to go
    /// back to is a choice, so ask.
    pub(crate) fn breakpoint_added(&self, file: &str, line: u32) {
        let settled = {
            let states = self.states();
            states.replay(states.current).0.is_some()
        };
        if !settled || self.session_view().held {
            return;
        }
        let already = format!(
            "The run already reached its fixpoint, so nothing will execute again and the breakpoint at {file}:{line} can't stop."
        );
        match self.rewind(self.program().0) {
            Rewind::Ask => self.ask_rewind(format!("{already} To see it fire, go back to a point before it ran.")),
            _ => self.publish(Event::Log { line: format!("{already} Debug reruns the program from scratch to stop there.") }),
        }
    }
}

#[cfg(test)]
mod tests {
    use super::Rewind;
    use crate::lane::Mode;
    use crate::states::Kind;
    use crate::studio::tests::studio;
    use crate::store::tests::Scratch;

    /// Debug after a Run reruns from scratch, as a branch from before the
    /// Run, when nothing changed since; after a change it asks.
    #[test]
    fn debug_after_the_fixpoint_goes_back_before_the_run() {
        let scratch = Scratch::new("rewind");
        let studio = studio(&scratch, Mode::Debug, "table (edge int int)\n");
        assert_eq!(studio.rewind(Some(1)), Rewind::Run);
        {
            let mut states = studio.states();
            states.derive(Kind::Run, "run main.slog", Some(1), None);
        }
        assert_eq!(studio.rewind(Some(1)), Rewind::Rerun(0));
        // an edited program is a new Run, not a rerun
        assert_eq!(studio.rewind(Some(2)), Rewind::Run);
        {
            let mut states = studio.states();
            states.derive(Kind::Change, "add edge 1 2", None, None);
        }
        assert_eq!(studio.rewind(Some(1)), Rewind::Ask);
        let choices: Vec<u64> = studio.choices().iter().map(|choice| choice.id).collect();
        assert_eq!(choices, [2, 1, 0]);
    }

    /// Run to the fixpoint, then Debug: the program reruns from scratch
    /// under the breakpoint and stops there, recorded as a branch from the
    /// state before the Run, which stays whole.
    #[tokio::test]
    async fn debug_after_a_run_stops_as_a_branch() {
        let scratch = Scratch::new("rewind-run");
        let studio = studio(
            &scratch,
            Mode::Debug,
            "table (edge int int)\ntable (path int int)\nrule (edge 1 2) (edge 2 3)\n\
             rule (edge X Y) --> (path X Y)\nrule (path X Y) (edge Y Z) --> (path X Z)\n",
        );
        studio.evaluate().await;
        let run = studio.states().current;
        assert_eq!(studio.states().get(run).map(|state| state.kind.clone()), Some(Kind::Run));
        studio.set_breakpoints(
            "main.slog".to_owned(),
            vec![crate::breakpoints::Breakpoint {
                id: "p1".into(),
                line: 5,
                at: None,
                clause: None,
                condition: String::new(),
                ignore: 0,
                log: false,
                enabled: true,
            }],
        );
        studio.debug().await;
        assert!(studio.session_view().held, "Debug after the fixpoint stops at the breakpoint");
        // the stop commits as a Run whose predecessor is the state before
        // the first Run: a branch, beside it
        studio.command("continue").await;
        let states = studio.states();
        let rerun = states.get(states.current).expect("the rerun's state");
        assert_eq!(rerun.kind, Kind::Run);
        assert_eq!(rerun.pred, states.get(run).and_then(|state| state.pred));
        assert_ne!(rerun.id, run);
        drop(states);
        studio.lane.shutdown().await;
    }
}
