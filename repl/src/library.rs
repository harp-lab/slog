use serde::Deserialize;

#[derive(Clone, Debug, Deserialize)]
pub struct RelationSummary {
    pub name: String,
    pub kind: String,
    pub arity: u64,
    pub detail: Option<String>,
    pub facts: u64,
    pub stored_facts: u64,
    pub count_source: String,
}

#[derive(Clone, Debug, Deserialize)]
pub struct DatabaseSummary {
    pub name: String,
    pub kind: String,
    pub managed: bool,
    pub facts: u64,
    pub stored_facts: u64,
    pub bytes: u64,
    pub size: String,
    pub relation_count: usize,
    pub table_count: usize,
    pub struct_count: usize,
    pub lattice_count: usize,
    pub inputs: Vec<String>,
    pub stale: Vec<String>,
    pub per: Option<f64>,
    pub relations: Vec<RelationSummary>,
}

#[derive(Debug)]
pub struct LibraryView {
    pub databases: Vec<DatabaseSummary>,
    pub selected: usize,
}

impl LibraryView {
    pub fn new(databases: Vec<DatabaseSummary>) -> Self {
        Self {
            databases,
            selected: 0,
        }
    }

    pub fn current(&self) -> Option<&DatabaseSummary> {
        self.databases.get(self.selected)
    }

    pub fn select(&mut self, index: usize) {
        if !self.databases.is_empty() {
            self.selected = index.min(self.databases.len() - 1);
        }
    }

    pub fn previous(&mut self, amount: usize) {
        self.selected = self.selected.saturating_sub(amount);
    }

    pub fn next(&mut self, amount: usize) {
        if !self.databases.is_empty() {
            self.selected = self
                .selected
                .saturating_add(amount)
                .min(self.databases.len() - 1);
        }
    }

    pub fn visible_offset(&self, visible_rows: usize) -> usize {
        if visible_rows == 0 || self.databases.len() <= visible_rows {
            return 0;
        }
        self.selected
            .saturating_sub(visible_rows / 2)
            .min(self.databases.len() - visible_rows)
    }

    pub fn hit_test(
        &self,
        column: u16,
        row: u16,
        terminal_width: u16,
        terminal_height: u16,
    ) -> Option<usize> {
        let list_width = if terminal_width >= 76 {
            terminal_width * 72 / 100
        } else {
            terminal_width
        };
        if column >= list_width || row < 2 || row >= terminal_height.saturating_sub(2) {
            return None;
        }
        let visible_rows = terminal_height.saturating_sub(4) as usize;
        let index = self.visible_offset(visible_rows) + usize::from(row - 2);
        (index < self.databases.len()).then_some(index)
    }
}

#[cfg(test)]
mod tests {
    use super::{DatabaseSummary, LibraryView};

    fn database(name: &str) -> DatabaseSummary {
        DatabaseSummary {
            name: name.to_owned(),
            kind: "plain".to_owned(),
            managed: false,
            facts: 0,
            stored_facts: 0,
            bytes: 0,
            size: "0B".to_owned(),
            relation_count: 0,
            table_count: 0,
            struct_count: 0,
            lattice_count: 0,
            inputs: Vec::new(),
            stale: Vec::new(),
            per: None,
            relations: Vec::new(),
        }
    }

    #[test]
    fn navigation_clamps_and_keeps_a_visible_window() {
        let mut view = LibraryView::new((0..30).map(|i| database(&i.to_string())).collect());
        view.next(25);
        assert_eq!(view.selected, 25);
        assert_eq!(view.visible_offset(10), 20);
        view.next(100);
        assert_eq!(view.selected, 29);
        view.previous(100);
        assert_eq!(view.selected, 0);
    }

    #[test]
    fn hit_testing_tracks_the_scrolled_window() {
        let mut view = LibraryView::new((0..30).map(|i| database(&i.to_string())).collect());
        view.next(25);
        assert_eq!(view.hit_test(4, 2, 100, 14), Some(20));
        assert_eq!(view.hit_test(90, 2, 100, 14), None);
    }
}
