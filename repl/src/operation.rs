//! In-flight shell workflows.
//!
//! Operations are presentation-neutral, temporary events. The terminal may
//! animate them; plain co-author clients only receive stable stage changes.
//! A completed operation is removed and its final label is committed with the
//! backend response.

use crate::command::ShellCommand;

#[derive(Clone, Copy, Debug, Eq, PartialEq)]
pub struct OperationId(u64);

#[derive(Debug)]
pub struct OperationSpec {
    command: String,
    label: String,
    completed_label: Option<String>,
    details: Vec<String>,
}

impl OperationSpec {
    pub fn new(
        command: impl Into<String>,
        label: impl Into<String>,
        completed_label: Option<String>,
        details: impl IntoIterator<Item = impl Into<String>>,
    ) -> Self {
        Self {
            command: command.into(),
            label: label.into(),
            completed_label,
            details: details.into_iter().map(Into::into).collect(),
        }
    }

    fn database_load(command: &ShellCommand, daemon_rebuild_pending: bool) -> Option<Self> {
        let database = command.database_to_open()?;
        let details = if daemon_rebuild_pending {
            [
                "daemon sources changed; rebuilding the database runtime",
                "waiting for the database runtime rebuild",
                "runtime rebuild or database load is still active",
                "still working; measured compiler/load progress is not exposed yet",
            ]
        } else {
            [
                "request sent to the session server",
                "waiting for the database runtime",
                "still loading; compressed databases may be replaying layers",
                "still waiting; relation and tuple progress is not exposed yet",
            ]
        };
        Some(Self::new(
            command.text(),
            format!("Loading database `{database}`"),
            Some(format!("Loaded database `{database}`")),
            details,
        ))
    }
}

#[derive(Debug)]
pub struct Operation {
    id: OperationId,
    command: String,
    label: String,
    completed_label: Option<String>,
    details: Vec<String>,
    frame: usize,
    ticks: u64,
}

impl Operation {
    pub fn id(&self) -> OperationId {
        self.id
    }

    fn animated_dots(&self) -> &'static str {
        // Every frame occupies three cells so the detail never shifts.
        const FRAMES: [&str; 3] = [".  ", ".. ", "..."];
        FRAMES[self.frame % FRAMES.len()]
    }

    pub fn animated_label(&self) -> String {
        format!("{}{} · {}", self.label, self.animated_dots(), self.detail())
    }

    pub fn fixed_label(&self) -> String {
        format!("{}... · {}", self.label, self.detail())
    }

    pub fn completed_label(self) -> Option<String> {
        self.completed_label
    }

    fn detail_stage(&self) -> usize {
        let stage = match self.ticks {
            0..=7 => 0,
            8..=39 => 1,
            40..=119 => 2,
            _ => 3,
        };
        stage.min(self.details.len().saturating_sub(1))
    }

    pub fn detail(&self) -> &str {
        self.details
            .get(self.detail_stage())
            .map(String::as_str)
            .unwrap_or("working")
    }

    fn tick(&mut self) -> bool {
        let previous_stage = self.detail_stage();
        self.frame = self.frame.wrapping_add(1);
        self.ticks = self.ticks.saturating_add(1);
        self.detail_stage() != previous_stage
    }
}

#[derive(Debug, Default)]
pub struct OperationTable {
    next_id: u64,
    active: Vec<Operation>,
    progress_updates: Vec<String>,
}

impl OperationTable {
    pub fn active(&self) -> &[Operation] {
        &self.active
    }

    pub fn is_empty(&self) -> bool {
        self.active.is_empty()
    }

    pub fn clear(&mut self) {
        self.active.clear();
        self.progress_updates.clear();
    }

    pub fn begin_for_command(
        &mut self,
        command: &ShellCommand,
        daemon_rebuild_pending: bool,
    ) -> Option<String> {
        let spec = OperationSpec::database_load(command, daemon_rebuild_pending)?;
        Some(self.begin(spec))
    }

    pub fn begin(&mut self, spec: OperationSpec) -> String {
        let id = OperationId(self.next_id);
        self.next_id = self.next_id.wrapping_add(1);
        let operation = Operation {
            id,
            command: spec.command,
            label: spec.label,
            completed_label: spec.completed_label,
            details: spec.details,
            frame: 0,
            ticks: 0,
        };
        let fixed = operation.fixed_label();
        self.active.push(operation);
        fixed
    }

    pub fn finish(&mut self, command: &str) -> Option<Operation> {
        let index = self
            .active
            .iter()
            .position(|operation| operation.command == command)?;
        Some(self.active.remove(index))
    }

    pub fn tick(&mut self) -> bool {
        if self.active.is_empty() {
            return false;
        }
        for operation in &mut self.active {
            if operation.tick() {
                self.progress_updates.push(operation.fixed_label());
            }
        }
        true
    }

    pub fn take_progress_updates(&mut self) -> Vec<String> {
        std::mem::take(&mut self.progress_updates)
    }
}

#[cfg(test)]
mod tests {
    use super::{OperationSpec, OperationTable};
    use crate::command::ShellCommand;

    #[test]
    fn database_load_is_discovered_from_the_canonical_command() {
        let command = ShellCommand::generated("open example").expect("command");
        let mut operations = OperationTable::default();
        assert_eq!(
            operations.begin_for_command(&command, false).as_deref(),
            Some("Loading database `example`... · request sent to the session server")
        );
        assert_eq!(operations.active().len(), 1);
        assert_eq!(operations.active()[0].id().0, 0);
        assert_eq!(
            operations
                .finish(command.text())
                .and_then(|operation| operation.completed_label())
                .as_deref(),
            Some("Loaded database `example`")
        );
        assert!(operations.is_empty());
    }

    #[test]
    fn custom_workflows_share_the_same_lifecycle() {
        let mut operations = OperationTable::default();
        operations.begin(OperationSpec::new(
            ":compile draft-1",
            "Compiling `draft-1`",
            Some("Compiled `draft-1`".to_owned()),
            ["request sent", "still compiling"],
        ));
        assert_eq!(
            operations.active()[0].animated_label(),
            "Compiling `draft-1`.   · request sent"
        );
        for _ in 0..8 {
            operations.tick();
        }
        assert_eq!(
            operations.take_progress_updates(),
            vec!["Compiling `draft-1`... · still compiling"]
        );
    }
}
