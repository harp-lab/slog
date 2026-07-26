//! Budgeted, terminal-independent presentation trees and live-canvas state.
//!
//! The server returns semantic records plus bounded human-readable lines.
//! This module turns those records into one expandable tree without teaching
//! Ratatui or the command loop how to scrape display text.

use crate::response::CommandResult;
use serde_json::Value;
use std::collections::{BTreeMap, BTreeSet};

#[derive(Clone, Copy, Debug, Eq, PartialEq)]
pub struct PresentationBudget {
    pub depth: usize,
    pub nodes: usize,
    pub items: usize,
    pub string_chars: usize,
}

impl Default for PresentationBudget {
    fn default() -> Self {
        Self {
            depth: 4,
            nodes: 200,
            items: 20,
            string_chars: 240,
        }
    }
}

#[derive(Clone, Debug)]
struct PresentationNode {
    text: String,
    path: String,
    children: Vec<PresentationNode>,
    card: Option<PresentationCard>,
}

impl PresentationNode {
    fn leaf(path: impl Into<String>, text: impl Into<String>) -> Self {
        Self {
            text: text.into(),
            path: path.into(),
            children: Vec::new(),
            card: None,
        }
    }

    fn leaf_with_card(
        path: impl Into<String>,
        text: impl Into<String>,
        card: PresentationCard,
    ) -> Self {
        Self {
            text: text.into(),
            path: path.into(),
            children: Vec::new(),
            card: Some(card),
        }
    }

    fn branch_with_card(
        path: impl Into<String>,
        text: impl Into<String>,
        children: Vec<PresentationNode>,
        card: PresentationCard,
    ) -> Self {
        Self {
            text: text.into(),
            path: path.into(),
            children,
            card: Some(card),
        }
    }
}

#[derive(Clone, Copy, Debug, Eq, PartialEq)]
pub enum ExpansionAction {
    Expand,
    Collapse,
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct PresentedLine {
    pub text: String,
    pub path: String,
    pub action: Option<ExpansionAction>,
    pub page_action: Option<PresentationPageAction>,
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct PresentationPageAction {
    pub parent: String,
    pub page: usize,
    pub total_pages: usize,
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct CardField {
    pub label: String,
    pub value: String,
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct PresentationCard {
    pub path: String,
    pub title: String,
    pub kind: String,
    pub fields: Vec<CardField>,
    pub actions: Vec<String>,
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct PresentationSearchSummary {
    pub query: String,
    pub current: Option<usize>,
    pub total: usize,
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct PresentationSearchSnapshot {
    query: Option<String>,
    path: Option<String>,
    selected: usize,
}

impl PresentationCard {
    fn new(path: impl Into<String>, title: impl Into<String>, kind: impl Into<String>) -> Self {
        Self {
            path: path.into(),
            title: title.into(),
            kind: kind.into(),
            fields: Vec::new(),
            actions: Vec::new(),
        }
    }

    fn field(mut self, label: impl Into<String>, value: impl Into<String>) -> Self {
        self.fields.push(CardField {
            label: label.into(),
            value: value.into(),
        });
        self
    }

    fn action(mut self, command: impl Into<String>) -> Self {
        self.actions.push(command.into());
        self
    }
}

#[derive(Debug)]
pub struct PresentationCanvas {
    nodes: Vec<PresentationNode>,
    budget: PresentationBudget,
    expanded: BTreeSet<String>,
    pages: BTreeMap<String, usize>,
    selected: usize,
    navigating: bool,
    card_path: Option<String>,
    search_query: Option<String>,
    search_path: Option<String>,
}

impl PresentationCanvas {
    pub fn for_result(result: &CommandResult) -> Self {
        Self::for_result_with_budget(result, PresentationBudget::default())
    }

    pub fn for_result_with_budget(result: &CommandResult, budget: PresentationBudget) -> Self {
        let mut nodes = result
            .lines()
            .iter()
            .enumerate()
            .map(|(index, line)| {
                PresentationNode::leaf(format!("it.lines.{}", index + 1), line.clone())
            })
            .collect::<Vec<_>>();
        if let Some(relations) = relations_node(result.raw()) {
            nodes.push(relations);
        }
        if let Some(change) = result.raw().get("change")
            && let Some(change_node) = change_node(change)
        {
            nodes.push(change_node);
        }
        Self {
            nodes,
            budget,
            expanded: BTreeSet::new(),
            pages: BTreeMap::new(),
            selected: 0,
            navigating: false,
            card_path: None,
            search_query: None,
            search_path: None,
        }
    }

    pub fn has_content(&self) -> bool {
        !self.nodes.is_empty()
    }

    pub fn navigating(&self) -> bool {
        self.navigating
    }

    pub fn enter_navigation(&mut self) -> bool {
        if self.rendered_lines().is_empty() {
            return false;
        }
        self.navigating = true;
        self.clamp_selection();
        true
    }

    pub fn leave_navigation(&mut self) {
        self.navigating = false;
    }

    pub fn select_previous(&mut self) {
        self.selected = self.selected.saturating_sub(1);
    }

    pub fn select_next(&mut self) {
        let last = self.rendered_lines().len().saturating_sub(1);
        self.selected = self.selected.saturating_add(1).min(last);
    }

    pub fn select_first(&mut self) {
        self.selected = 0;
    }

    pub fn select_last(&mut self) {
        self.selected = self.rendered_lines().len().saturating_sub(1);
    }

    pub fn selected_line(&self) -> Option<usize> {
        self.navigating.then(|| {
            self.selected
                .min(self.rendered_lines().len().saturating_sub(1))
        })
    }

    pub fn card(&self) -> Option<PresentationCard> {
        let path = self.card_path.as_deref()?;
        let node = find_node(&self.nodes, path)?;
        let mut card = node.card.clone()?;
        if let Some(line) = self.rendered_lines().iter().find(|line| line.path == path)
            && let Some(action) = line.action
        {
            card.actions.push(format!(
                "{} {path}",
                match action {
                    ExpansionAction::Expand => "expand",
                    ExpansionAction::Collapse => "collapse",
                }
            ));
        }
        card.actions.push("card close".to_owned());
        Some(card)
    }

    pub fn visible_card_positions(&self) -> Vec<String> {
        self.rendered_lines()
            .into_iter()
            .filter(|line| {
                find_node(&self.nodes, &line.path).is_some_and(|node| node.card.is_some())
            })
            .map(|line| line.path)
            .collect()
    }

    pub fn visible_page_targets(&self) -> Vec<(String, usize)> {
        self.rendered_lines()
            .into_iter()
            .filter_map(|line| {
                line.page_action
                    .map(|action| (action.parent, action.total_pages))
            })
            .collect::<BTreeMap<_, _>>()
            .into_iter()
            .collect()
    }

    pub fn search(&mut self, query: &str) -> usize {
        let query = query.trim();
        if query.is_empty() {
            self.clear_search();
            return 0;
        }
        let matches = self.matching_lines(query);
        let selected = matches
            .iter()
            .find(|(index, _)| *index >= self.selected)
            .or_else(|| matches.first())
            .cloned();
        self.search_query = Some(query.to_owned());
        self.search_path = selected.as_ref().map(|(_, path)| path.clone());
        if let Some((index, _)) = selected {
            self.selected = index;
        }
        self.navigating = true;
        matches.len()
    }

    pub fn search_next(&mut self) -> bool {
        self.move_search(true)
    }

    pub fn search_previous(&mut self) -> bool {
        self.move_search(false)
    }

    pub fn clear_search(&mut self) -> bool {
        let changed = self.search_query.take().is_some() || self.search_path.take().is_some();
        self.search_path = None;
        changed
    }

    pub fn search_summary(&self) -> Option<PresentationSearchSummary> {
        let query = self.search_query.as_ref()?;
        let matches = self.matching_lines(query);
        let current = self
            .search_path
            .as_ref()
            .and_then(|path| matches.iter().position(|(_, candidate)| candidate == path))
            .map(|index| index + 1);
        Some(PresentationSearchSummary {
            query: query.clone(),
            current,
            total: matches.len(),
        })
    }

    pub fn search_match_lines(&self) -> Vec<usize> {
        self.search_query
            .as_ref()
            .map(|query| {
                self.matching_lines(query)
                    .into_iter()
                    .map(|(index, _)| index)
                    .collect()
            })
            .unwrap_or_default()
    }

    pub fn search_snapshot(&self) -> PresentationSearchSnapshot {
        PresentationSearchSnapshot {
            query: self.search_query.clone(),
            path: self.search_path.clone(),
            selected: self.selected,
        }
    }

    pub fn restore_search(&mut self, snapshot: PresentationSearchSnapshot) {
        self.search_query = snapshot.query;
        self.search_path = snapshot.path;
        self.selected = snapshot
            .selected
            .min(self.rendered_lines().len().saturating_sub(1));
    }

    pub fn toggle_selected_card(&mut self) -> Option<String> {
        let path = self.rendered_lines().get(self.selected)?.path.clone();
        find_node(&self.nodes, &path)?.card.as_ref()?;
        if self.card_path.as_deref() == Some(path.as_str()) {
            self.card_path = None;
            Some("card close".to_owned())
        } else {
            self.card_path = Some(path.clone());
            Some(format!("card {path}"))
        }
    }

    pub fn toggle_selected(&mut self) -> Option<String> {
        let line = self.rendered_lines().get(self.selected)?.clone();
        if let Some(action) = line.page_action {
            let command = format!("page {} {}", action.parent, action.page);
            self.apply_page(&action.parent, action.page);
            return Some(command);
        }
        let action = line.action?;
        let verb = match action {
            ExpansionAction::Expand => "expand",
            ExpansionAction::Collapse => "collapse",
        };
        self.apply_expansion(action, &line.path);
        Some(format!("{verb} {}", line.path))
    }

    pub fn expand_selected(&mut self) -> Option<String> {
        let line = self.rendered_lines().get(self.selected)?.clone();
        (line.action == Some(ExpansionAction::Expand)).then(|| {
            self.apply_expansion(ExpansionAction::Expand, &line.path);
            format!("expand {}", line.path)
        })
    }

    pub fn collapse_selected(&mut self) -> Option<String> {
        let line = self.rendered_lines().get(self.selected)?.clone();
        (line.action == Some(ExpansionAction::Collapse)).then(|| {
            self.apply_expansion(ExpansionAction::Collapse, &line.path);
            format!("collapse {}", line.path)
        })
    }

    pub fn apply_command(&mut self, source: &str) -> Result<bool, String> {
        let mut words = source.splitn(2, char::is_whitespace);
        let verb = words.next().unwrap_or("").to_ascii_lowercase();
        if !matches!(
            verb.as_str(),
            "expand"
                | "collapse"
                | "card"
                | "search"
                | "search-next"
                | "search-previous"
                | "search-clear"
                | "page"
        ) {
            return Ok(false);
        }
        let path = words.next().unwrap_or("").trim();
        match verb.as_str() {
            "page" => {
                let arguments = path.split_whitespace().collect::<Vec<_>>();
                let [parent, page] = arguments.as_slice() else {
                    return Err("expected: page POSITION NUMBER".to_owned());
                };
                let page = page
                    .parse::<usize>()
                    .ok()
                    .filter(|page| *page > 0)
                    .ok_or_else(|| "page number must be a positive integer".to_owned())?;
                let total_pages = self
                    .visible_page_targets()
                    .into_iter()
                    .find_map(|(candidate, total)| (candidate == *parent).then_some(total))
                    .ok_or_else(|| format!("canvas position `{parent}` is not visibly paged"))?;
                if page > total_pages {
                    return Err(format!(
                        "page {page} is outside 1–{total_pages} for `{parent}`"
                    ));
                }
                if self.pages.get(*parent).copied().unwrap_or(1) == page {
                    return Err(format!("`{parent}` is already on page {page}"));
                }
                self.apply_page(parent, page);
                return Ok(true);
            }
            "search" => {
                if path.is_empty() {
                    return Err("expected: search TEXT".to_owned());
                }
                self.search(path);
                return Ok(true);
            }
            "search-next" => {
                if !path.is_empty() {
                    return Err("expected: search-next".to_owned());
                }
                return self
                    .search_next()
                    .then_some(true)
                    .ok_or_else(|| "there is no visible search match".to_owned());
            }
            "search-previous" => {
                if !path.is_empty() {
                    return Err("expected: search-previous".to_owned());
                }
                return self
                    .search_previous()
                    .then_some(true)
                    .ok_or_else(|| "there is no visible search match".to_owned());
            }
            "search-clear" => {
                if !path.is_empty() {
                    return Err("expected: search-clear".to_owned());
                }
                self.clear_search();
                return Ok(true);
            }
            _ => {}
        }
        if path.is_empty() {
            return Err(format!("expected: {verb} POSITION"));
        }
        if verb == "card" {
            if path == "close" {
                if self.card_path.take().is_some() {
                    return Ok(true);
                }
                return Err("there is no open canvas card".to_owned());
            }
            if !self.rendered_lines().iter().any(|line| line.path == path) {
                return Err(format!("no visible canvas position `{path}`"));
            }
            let node = find_node(&self.nodes, path)
                .ok_or_else(|| format!("no live canvas position `{path}`"))?;
            if node.card.is_none() {
                return Err(format!("canvas position `{path}` has no card"));
            }
            self.card_path = Some(path.to_owned());
            return Ok(true);
        }
        let expected = if verb == "expand" {
            ExpansionAction::Expand
        } else {
            ExpansionAction::Collapse
        };
        let line = self
            .rendered_lines()
            .into_iter()
            .find(|line| line.path == path)
            .ok_or_else(|| format!("no live canvas position `{path}`"))?;
        match line.action {
            Some(action) if action == expected => {
                self.apply_expansion(action, path);
                Ok(true)
            }
            Some(_) => Err(format!(
                "`{path}` is already {}",
                if verb == "expand" {
                    "expanded"
                } else {
                    "collapsed"
                }
            )),
            None => Err(format!("canvas position `{path}` is not expandable")),
        }
    }

    pub fn rendered_lines(&self) -> Vec<PresentedLine> {
        let mut state = RenderState {
            budget: self.budget,
            expanded: &self.expanded,
            pages: &self.pages,
            lines: Vec::new(),
            visible_nodes: 0,
            node_marker_emitted: false,
        };
        state.render_children(&self.nodes, "it", 0);
        state.lines
    }

    pub fn plain_lines(&self) -> Vec<String> {
        self.rendered_lines()
            .into_iter()
            .map(|line| line.text)
            .collect()
    }

    fn apply_expansion(&mut self, action: ExpansionAction, path: &str) {
        match action {
            ExpansionAction::Expand => {
                self.expanded.insert(path.to_owned());
            }
            ExpansionAction::Collapse => {
                self.expanded.retain(|expanded| {
                    expanded != path && !expanded.starts_with(&format!("{path}."))
                });
                self.pages
                    .retain(|parent, _| parent != path && !parent.starts_with(&format!("{path}.")));
            }
        }
        if self
            .card_path
            .as_ref()
            .is_some_and(|card| !self.rendered_lines().iter().any(|line| line.path == *card))
        {
            self.card_path = None;
        }
        self.reselect(path);
        self.refresh_search();
    }

    fn apply_page(&mut self, parent: &str, page: usize) {
        self.pages.insert(parent.to_owned(), page);
        let first_path = self
            .children_for_parent(parent)
            .and_then(|children| {
                let start = page
                    .saturating_sub(1)
                    .saturating_mul(self.budget.items.max(1));
                children.get(start)
            })
            .map(|node| node.path.clone());
        if self
            .card_path
            .as_ref()
            .is_some_and(|card| !self.rendered_lines().iter().any(|line| line.path == *card))
        {
            self.card_path = None;
        }
        if let Some(path) = first_path {
            self.reselect(&path);
        } else {
            self.clamp_selection();
        }
        self.refresh_search();
    }

    fn children_for_parent(&self, parent: &str) -> Option<&[PresentationNode]> {
        if parent == "it" {
            Some(&self.nodes)
        } else {
            find_node(&self.nodes, parent).map(|node| node.children.as_slice())
        }
    }

    fn reselect(&mut self, path: &str) {
        let lines = self.rendered_lines();
        if let Some(index) = lines.iter().position(|line| line.path == path) {
            self.selected = index;
        } else {
            self.selected = self.selected.min(lines.len().saturating_sub(1));
        }
    }

    fn clamp_selection(&mut self) {
        self.selected = self
            .selected
            .min(self.rendered_lines().len().saturating_sub(1));
    }

    fn move_search(&mut self, forward: bool) -> bool {
        let Some(query) = self.search_query.as_ref() else {
            return false;
        };
        let matches = self.matching_lines(query);
        if matches.is_empty() {
            self.search_path = None;
            return false;
        }
        let current = self
            .search_path
            .as_ref()
            .and_then(|path| matches.iter().position(|(_, candidate)| candidate == path));
        let next = if forward {
            current.map_or(0, |index| (index + 1) % matches.len())
        } else {
            current
                .and_then(|index| index.checked_sub(1))
                .unwrap_or(matches.len() - 1)
        };
        self.selected = matches[next].0;
        self.search_path = Some(matches[next].1.clone());
        self.navigating = true;
        true
    }

    fn matching_lines(&self, query: &str) -> Vec<(usize, String)> {
        let query = query.to_lowercase();
        self.rendered_lines()
            .into_iter()
            .enumerate()
            .filter(|(_, line)| line.text.to_lowercase().contains(&query))
            .map(|(index, line)| (index, line.path))
            .collect()
    }

    fn refresh_search(&mut self) {
        let Some(query) = self.search_query.as_ref() else {
            return;
        };
        let matches = self.matching_lines(query);
        if matches.is_empty() {
            self.search_path = None;
            return;
        }
        if self
            .search_path
            .as_ref()
            .is_some_and(|path| matches.iter().any(|(_, candidate)| candidate == path))
        {
            return;
        }
        let selected = matches
            .iter()
            .find(|(index, _)| *index >= self.selected)
            .unwrap_or(&matches[0]);
        self.selected = selected.0;
        self.search_path = Some(selected.1.clone());
    }
}

struct RenderState<'a> {
    budget: PresentationBudget,
    expanded: &'a BTreeSet<String>,
    pages: &'a BTreeMap<String, usize>,
    lines: Vec<PresentedLine>,
    visible_nodes: usize,
    node_marker_emitted: bool,
}

impl RenderState<'_> {
    fn render_children(&mut self, nodes: &[PresentationNode], parent: &str, depth: usize) -> bool {
        let item_limit = self.budget.items.max(1);
        let total_pages = nodes.len().div_ceil(item_limit);
        let page = self
            .pages
            .get(parent)
            .copied()
            .unwrap_or(1)
            .clamp(1, total_pages.max(1));
        let start = page.saturating_sub(1).saturating_mul(item_limit);
        let end = start.saturating_add(item_limit).min(nodes.len());
        if page > 1 {
            let previous = page - 1;
            if !self.push_line(PresentedLine {
                text: format!(
                    "{}◂ {start} before · page {page}/{total_pages}",
                    indent(depth),
                ),
                path: format!("{parent}.__page.previous"),
                action: None,
                page_action: Some(PresentationPageAction {
                    parent: parent.to_owned(),
                    page: previous,
                    total_pages,
                }),
            }) {
                return false;
            }
        }
        for node in &nodes[start..end] {
            if !self.render_node(node, depth) {
                return false;
            }
        }
        if end < nodes.len() {
            let more = nodes.len() - end;
            if !self.push_line(PresentedLine {
                text: format!(
                    "{}▸ … {more} more · page {page}/{total_pages}",
                    indent(depth),
                ),
                path: format!("{parent}.__page.next"),
                action: None,
                page_action: Some(PresentationPageAction {
                    parent: parent.to_owned(),
                    page: page + 1,
                    total_pages,
                }),
            }) {
                return false;
            }
        }
        true
    }

    fn render_node(&mut self, node: &PresentationNode, depth: usize) -> bool {
        if !self.reserve_node() {
            return false;
        }
        if node.children.is_empty() {
            let full = self.expanded.contains(&node.path);
            let truncated = truncate_chars(&node.text, self.budget.string_chars.max(1));
            let was_truncated = truncated != node.text;
            return self.push_line_unbudgeted(PresentedLine {
                text: format!(
                    "{}{}{}",
                    indent(depth),
                    if full { node.text.as_str() } else { &truncated },
                    if was_truncated && !full {
                        " … ▸[..]"
                    } else {
                        ""
                    }
                ),
                path: node.path.clone(),
                action: was_truncated.then_some(if full {
                    ExpansionAction::Collapse
                } else {
                    ExpansionAction::Expand
                }),
                page_action: None,
            });
        }

        let open = self.expanded.contains(&node.path);
        if !self.push_line_unbudgeted(PresentedLine {
            text: format!(
                "{}{} {}",
                indent(depth),
                if open { "▾" } else { "▸" },
                node.text
            ),
            path: node.path.clone(),
            action: Some(if open {
                ExpansionAction::Collapse
            } else {
                ExpansionAction::Expand
            }),
            page_action: None,
        }) {
            return false;
        }
        if open {
            let child_depth = depth.saturating_add(1);
            if child_depth > self.budget.depth {
                let path = format!("{}.__depth", node.path);
                let deepen = self.expanded.contains(&path);
                if !self.push_line(PresentedLine {
                    text: format!(
                        "{}{} deeper nodes",
                        indent(child_depth),
                        if deepen { "▾" } else { "▸" }
                    ),
                    path,
                    action: Some(if deepen {
                        ExpansionAction::Collapse
                    } else {
                        ExpansionAction::Expand
                    }),
                    page_action: None,
                }) {
                    return false;
                }
                if !deepen {
                    return true;
                }
            }
            return self.render_children(&node.children, &node.path, child_depth);
        }
        true
    }

    fn reserve_node(&mut self) -> bool {
        if self.visible_nodes < self.budget.nodes.max(1) {
            self.visible_nodes += 1;
            return true;
        }
        let path = "it.__nodes".to_owned();
        let open = self.expanded.contains(&path);
        if !self.node_marker_emitted {
            self.node_marker_emitted = true;
            self.lines.push(PresentedLine {
                text: format!(
                    "{} continue beyond node budget",
                    if open { "▾" } else { "▸" }
                ),
                path,
                action: Some(if open {
                    ExpansionAction::Collapse
                } else {
                    ExpansionAction::Expand
                }),
                page_action: None,
            });
        }
        open
    }

    fn push_line(&mut self, line: PresentedLine) -> bool {
        if !self.reserve_node() {
            return false;
        }
        self.push_line_unbudgeted(line)
    }

    fn push_line_unbudgeted(&mut self, line: PresentedLine) -> bool {
        self.lines.push(line);
        true
    }
}

fn find_node<'a>(nodes: &'a [PresentationNode], path: &str) -> Option<&'a PresentationNode> {
    nodes.iter().find_map(|node| {
        if node.path == path {
            Some(node)
        } else {
            find_node(&node.children, path)
        }
    })
}

fn relations_node(result: &Value) -> Option<PresentationNode> {
    let values = result.get("relations")?.as_array()?;
    let children = values
        .iter()
        .enumerate()
        .filter_map(|(index, value)| relation_node(index, value))
        .collect::<Vec<_>>();
    let path = "it.relations";
    let visible = children.len();
    let total = result
        .get("relations-total")
        .and_then(Value::as_u64)
        .map_or_else(|| visible.to_string(), |total| total.to_string());
    let filter = result
        .get("relations-filter")
        .and_then(Value::as_str)
        .filter(|filter| !filter.is_empty())
        .unwrap_or("default user-visible view");
    let scope = result
        .get("relations-scope")
        .and_then(Value::as_str)
        .unwrap_or("current live session");
    let identity = result
        .get("boundary-key")
        .and_then(Value::as_str)
        .map_or_else(
            || "current live names; no committed BoundaryKey is selected".to_owned(),
            |key| format!("selected BoundaryKey {key}"),
        );
    let card = PresentationCard::new(path, "Live relation observations", "schema observation")
        .field("visible relations", visible.to_string())
        .field("total live relations", total)
        .field("filter", filter)
        .field("scope", scope)
        .field("identity", identity)
        .action("tables all");
    let text = format!("Live relation observations ({visible})");
    if children.is_empty() {
        Some(PresentationNode::leaf_with_card(path, text, card))
    } else {
        Some(PresentationNode::branch_with_card(
            path, text, children, card,
        ))
    }
}

fn relation_node(index: usize, value: &Value) -> Option<PresentationNode> {
    let object = value.as_object()?;
    let name = object.get("name")?.as_str()?;
    let kind = object
        .get("kind")
        .and_then(Value::as_str)
        .unwrap_or("relation");
    let arity = object
        .get("arity")
        .map(scalar)
        .unwrap_or_else(|| "?".to_owned());
    let rows = object
        .get("rows")
        .map(scalar)
        .unwrap_or_else(|| "?".to_owned());
    let detail = object
        .get("detail")
        .and_then(Value::as_array)
        .into_iter()
        .flatten()
        .map(scalar)
        .collect::<Vec<_>>()
        .join(" ");
    let version_key = object.get("version-key").and_then(Value::as_str);
    let boundary_key = object.get("boundary-key").and_then(Value::as_str);
    let identity = match (boundary_key, version_key) {
        (Some(boundary), Some(version)) => {
            format!("BoundaryKey {boundary} · VersionKey {version}")
        }
        (Some(boundary), None) => format!("BoundaryKey {boundary} · no VersionKey published"),
        (None, Some(version)) => {
            format!("no committed BoundaryKey · VersionKey {version}")
        }
        (None, None) => "current live name only; no BoundaryKey or VersionKey is published".into(),
    };
    let path = format!("it.relations.{}", index + 1);
    let mut children = vec![
        PresentationNode::leaf(format!("{path}.kind"), format!("kind: {kind}")),
        PresentationNode::leaf(format!("{path}.arity"), format!("arity: {arity}")),
        PresentationNode::leaf(format!("{path}.rows"), format!("rows: {rows}")),
    ];
    if !detail.is_empty() {
        children.push(PresentationNode::leaf(
            format!("{path}.detail"),
            format!("schema detail: {detail}"),
        ));
    }
    let card = PresentationCard::new(&path, name, "live relation observation")
        .field("name", name)
        .field("kind", kind)
        .field("arity", &arity)
        .field("rows", &rows)
        .field(
            "schema detail",
            if detail.is_empty() {
                "not published"
            } else {
                detail.as_str()
            },
        )
        .field("identity", identity)
        .action(format!("count {name}"))
        .action(format!("show {name}"))
        .action(format!("state {name}"));
    Some(PresentationNode::branch_with_card(
        path,
        format!(
            "{name}/{arity} · {kind} · {rows} row{}",
            if rows == "1" { "" } else { "s" }
        ),
        children,
        card,
    ))
}

fn change_node(change: &Value) -> Option<PresentationNode> {
    let object = change.as_object()?;
    let mut children = Vec::new();
    let mut change_card = PresentationCard::new("it.change", "Change details", "semantic change");
    for (key, label) in [
        ("operation", "operation"),
        ("target", "target"),
        ("status", "status"),
        ("update-revision", "update revision"),
        ("counts", "counts"),
        ("sizes-observed", "sizes observed"),
        ("size-deltas-omitted", "size observations omitted"),
    ] {
        if let Some(value) = object.get(key) {
            let value = scalar(value);
            children.push(PresentationNode::leaf(
                format!("it.change.{}", key.replace('-', "_")),
                format!("{label}: {value}"),
            ));
            change_card = change_card.field(label, value);
        }
    }
    if let Some(values) = object.get("requested").and_then(Value::as_array)
        && !values.is_empty()
    {
        change_card = change_card.field("requested edits", values.len().to_string());
        let path = "it.change.requested";
        children.push(PresentationNode::branch_with_card(
            path,
            format!("requested tuple edits ({})", values.len()),
            values
                .iter()
                .enumerate()
                .map(|(index, value)| {
                    let relation = value.get("relation").and_then(Value::as_str).unwrap_or("?");
                    let added = value.get("added").and_then(Value::as_u64).unwrap_or(0);
                    let removed = value.get("removed").and_then(Value::as_u64).unwrap_or(0);
                    let path = format!("it.change.requested.{}", index + 1);
                    let card = PresentationCard::new(&path, relation, "requested tuple edit")
                        .field("relation", relation)
                        .field("requested add", added.to_string())
                        .field("requested remove", removed.to_string())
                        .field(
                            "meaning",
                            "request only; normalization determines the settled effect",
                        );
                    PresentationNode::leaf_with_card(
                        path,
                        format!("{relation}: +{added} -{removed} requested"),
                        card,
                    )
                })
                .collect(),
            PresentationCard::new(path, "Requested tuple edits", "change evidence")
                .field("entries", values.len().to_string())
                .field(
                    "meaning",
                    "requested direct edits; not a claim that stored tuples changed",
                ),
        ));
    }
    if let Some(values) = object.get("size-deltas").and_then(Value::as_array)
        && !values.is_empty()
    {
        change_card = change_card.field("size observations", values.len().to_string());
        let path = "it.change.sizes";
        children.push(PresentationNode::branch_with_card(
            path,
            format!("relation size observations ({})", values.len()),
            values
                .iter()
                .enumerate()
                .map(|(index, value)| {
                    let relation = value.get("relation").and_then(Value::as_str).unwrap_or("?");
                    let before = endpoint(value.get("before"));
                    let after = endpoint(value.get("after"));
                    let net = value.get("net").and_then(Value::as_i64).unwrap_or(0);
                    let path = format!("it.change.sizes.{}", index + 1);
                    let card = PresentationCard::new(&path, relation, "relation size observation")
                        .field("relation", relation)
                        .field("before", &before)
                        .field("after", &after)
                        .field("net", format!("{net:+}"))
                        .field(
                            "meaning",
                            "cardinality evidence; not a tuple diff or provenance proof",
                        );
                    PresentationNode::leaf_with_card(
                        path,
                        format!("{relation}: {before} → {after} · net {net:+}"),
                        card,
                    )
                })
                .collect(),
            PresentationCard::new(path, "Relation size observations", "change evidence")
                .field("entries", values.len().to_string())
                .field(
                    "meaning",
                    "best-effort cardinality observations after the settled operation",
                ),
        ));
    }
    if let Some(values) = object.get("routes").and_then(Value::as_array)
        && !values.is_empty()
    {
        change_card = change_card.field("maintenance routes", values.len().to_string());
        let path = "it.change.routes";
        children.push(PresentationNode::branch_with_card(
            path,
            format!("maintenance routes ({})", values.len()),
            values
                .iter()
                .enumerate()
                .map(|(index, value)| {
                    let kind = value.get("kind").and_then(Value::as_str).unwrap_or("?");
                    let detail = value
                        .get("detail")
                        .and_then(Value::as_array)
                        .into_iter()
                        .flatten()
                        .map(scalar)
                        .collect::<Vec<_>>()
                        .join(" ");
                    let path = format!("it.change.routes.{}", index + 1);
                    let card = PresentationCard::new(&path, kind, "maintenance route")
                        .field("kind", kind)
                        .field(
                            "detail",
                            if detail.is_empty() {
                                "none"
                            } else {
                                detail.as_str()
                            },
                        );
                    PresentationNode::leaf_with_card(
                        path,
                        if detail.is_empty() {
                            kind.to_owned()
                        } else {
                            format!("{kind}: {detail}")
                        },
                        card,
                    )
                })
                .collect(),
            PresentationCard::new(path, "Maintenance routes", "change evidence")
                .field("entries", values.len().to_string()),
        ));
    }
    Some(PresentationNode::branch_with_card(
        "it.change",
        "Change details",
        children,
        change_card,
    ))
}

fn scalar(value: &Value) -> String {
    match value {
        Value::Null => "unknown".to_owned(),
        Value::String(value) => value.clone(),
        Value::Bool(value) => value.to_string(),
        Value::Number(value) => value.to_string(),
        other => other.to_string(),
    }
}

fn endpoint(value: Option<&Value>) -> String {
    match value {
        None | Some(Value::Null) => "none".to_owned(),
        Some(value) => scalar(value),
    }
}

fn indent(depth: usize) -> String {
    "  ".repeat(depth)
}

fn truncate_chars(text: &str, limit: usize) -> String {
    let mut chars = text.chars();
    let prefix = chars.by_ref().take(limit).collect::<String>();
    if chars.next().is_some() {
        prefix
    } else {
        text.to_owned()
    }
}

#[cfg(test)]
mod tests {
    use super::{ExpansionAction, PresentationBudget, PresentationCanvas};
    use crate::response::CommandResult;

    fn result() -> CommandResult {
        CommandResult::from_value(serde_json::json!({
            "title": "Add · edge",
            "lines": ["(edge 4 5)", "settled"],
            "change": {
                "operation": "add",
                "target": "example",
                "status": "settled",
                "update-revision": 7,
                "counts": "valid",
                "requested": [{"relation": "edge", "added": 1, "removed": 0}],
                "size-deltas": [
                    {"relation": "edge", "before": 3, "after": 4, "net": 1}
                ],
                "routes": [{"kind": "maintain", "detail": ["0"]}]
            }
        }))
    }

    fn relations_result() -> CommandResult {
        CommandResult::from_value(serde_json::json!({
            "kind": "tables",
            "title": "Live relations",
            "lines": [
                "edge/2  table · Int Int  3 rows",
                "empty/1  relation · Int  0 rows"
            ],
            "relations": [
                {
                    "name": "edge",
                    "kind": "table",
                    "arity": 2,
                    "detail": ["Int", "Int"],
                    "rows": 3,
                    "version-key": "v1:edge",
                    "boundary-key": "b1:root:1"
                },
                {
                    "name": "empty",
                    "kind": "relation",
                    "arity": 1,
                    "detail": ["Int"],
                    "rows": 0
                }
            ],
            "relations-total": 4,
            "relations-filter": "",
            "relations-scope": "committed boundary b1:root:1",
            "boundary-key": "b1:root:1"
        }))
    }

    #[test]
    fn structured_change_is_a_collapsed_tree_without_scraping_lines() {
        let mut canvas = PresentationCanvas::for_result(&result());
        assert_eq!(
            canvas.plain_lines(),
            ["(edge 4 5)", "settled", "▸ Change details"]
        );
        canvas.select_last();
        assert_eq!(
            canvas.toggle_selected().as_deref(),
            Some("expand it.change")
        );
        let lines = canvas.plain_lines();
        assert!(lines.contains(&"▾ Change details".to_owned()));
        assert!(lines.contains(&"  operation: add".to_owned()));
        assert!(lines.contains(&"  target: example".to_owned()));
        assert!(lines.contains(&"  ▸ requested tuple edits (1)".to_owned()));
    }

    #[test]
    fn typed_expansion_and_gesture_expansion_are_the_same_state_change() {
        let mut canvas = PresentationCanvas::for_result(&result());
        assert!(canvas.apply_command("expand it.change").expect("expand"));
        assert_eq!(
            canvas
                .rendered_lines()
                .iter()
                .find(|line| line.path == "it.change")
                .and_then(|line| line.action),
            Some(ExpansionAction::Collapse)
        );
        assert!(
            canvas
                .apply_command("collapse it.change")
                .expect("collapse")
        );
        assert!(
            canvas
                .plain_lines()
                .contains(&"▸ Change details".to_owned())
        );
        assert_eq!(
            canvas
                .apply_command("expand")
                .expect_err("missing position"),
            "expected: expand POSITION"
        );
    }

    #[test]
    fn cards_preserve_semantic_evidence_and_publish_typed_actions() {
        let mut canvas = PresentationCanvas::for_result(&result());
        canvas.select_last();
        assert_eq!(
            canvas.toggle_selected_card().as_deref(),
            Some("card it.change")
        );
        let card = canvas.card().expect("change card");
        assert_eq!(card.title, "Change details");
        assert_eq!(card.kind, "semantic change");
        assert!(
            card.fields
                .iter()
                .any(|field| field.label == "operation" && field.value == "add")
        );
        assert!(card.actions.contains(&"expand it.change".to_owned()));
        assert!(card.actions.contains(&"card close".to_owned()));

        assert!(canvas.apply_command("expand it.change").expect("change"));
        assert!(
            canvas
                .apply_command("expand it.change.requested")
                .expect("requested")
        );
        assert!(
            canvas
                .apply_command("card it.change.requested.1")
                .expect("request card")
        );
        let card = canvas.card().expect("request card");
        assert_eq!(card.kind, "requested tuple edit");
        assert!(card.fields.iter().any(|field| {
            field.label == "meaning"
                && field
                    .value
                    .contains("normalization determines the settled effect")
        }));

        assert!(
            canvas
                .apply_command("collapse it.change.requested")
                .expect("collapse requested")
        );
        assert!(canvas.card().is_none());
    }

    #[test]
    fn search_visits_only_visible_tree_lines_and_wraps_with_typed_commands() {
        let mut canvas = PresentationCanvas::for_result(&result());
        assert_eq!(canvas.search("operation"), 0);
        assert_eq!(
            canvas.search_summary().expect("empty search").total,
            0,
            "collapsed children are not searched"
        );

        assert!(canvas.apply_command("expand it.change").expect("change"));
        assert_eq!(canvas.search("OPERATION"), 1);
        let summary = canvas.search_summary().expect("operation search");
        assert_eq!(summary.current, Some(1));
        assert_eq!(summary.total, 1);

        assert!(
            canvas
                .apply_command("expand it.change.requested")
                .expect("requested")
        );
        assert!(canvas.apply_command("search edge").expect("search"));
        assert_eq!(canvas.search_summary().expect("edge search").total, 2);
        let first = canvas.selected_line().expect("first edge");
        assert!(canvas.apply_command("search-next").expect("next"));
        assert_ne!(canvas.selected_line(), Some(first));
        assert!(canvas.apply_command("search-next").expect("wrap"));
        assert_eq!(canvas.selected_line(), Some(first));
        assert!(canvas.apply_command("search-clear").expect("clear"));
        assert!(canvas.search_summary().is_none());
    }

    #[test]
    fn live_relation_records_become_budgeted_trees_and_truthful_cards() {
        let mut canvas = PresentationCanvas::for_result(&relations_result());
        assert_eq!(
            canvas.plain_lines(),
            [
                "edge/2  table · Int Int  3 rows",
                "empty/1  relation · Int  0 rows",
                "▸ Live relation observations (2)"
            ]
        );
        assert!(
            canvas
                .apply_command("card it.relations")
                .expect("root card")
        );
        let card = canvas.card().expect("relations card");
        assert_eq!(card.kind, "schema observation");
        assert!(card.actions.contains(&"tables all".to_owned()));
        assert!(
            card.fields
                .iter()
                .any(|field| { field.label == "total live relations" && field.value == "4" })
        );

        assert!(
            canvas
                .apply_command("expand it.relations")
                .expect("relations")
        );
        assert!(
            canvas
                .apply_command("expand it.relations.1")
                .expect("edge relation")
        );
        assert!(
            canvas
                .plain_lines()
                .contains(&"    schema detail: Int Int".to_owned())
        );
        assert!(
            canvas
                .apply_command("card it.relations.1")
                .expect("edge card")
        );
        let card = canvas.card().expect("relation card");
        assert_eq!(card.title, "edge");
        assert_eq!(card.kind, "live relation observation");
        assert!(card.actions.contains(&"count edge".to_owned()));
        assert!(card.actions.contains(&"show edge".to_owned()));
        assert!(card.actions.contains(&"state edge".to_owned()));
        assert!(card.fields.iter().any(|field| {
            field.label == "identity" && field.value == "BoundaryKey b1:root:1 · VersionKey v1:edge"
        }));
    }

    #[test]
    fn item_budgets_use_absolute_buffered_pages_without_expanding_floods() {
        let result = CommandResult::from_value(serde_json::json!({
            "title": "Wide",
            "lines": ["abcdefgh", "two", "three", "four"]
        }));
        let mut canvas = PresentationCanvas::for_result_with_budget(
            &result,
            PresentationBudget {
                depth: 1,
                nodes: 20,
                items: 2,
                string_chars: 4,
            },
        );
        let lines = canvas.rendered_lines();
        assert_eq!(lines[0].text, "abcd … ▸[..]");
        assert_eq!(lines[0].action, Some(ExpansionAction::Expand));
        assert_eq!(lines[2].text, "▸ … 2 more · page 1/2");
        assert_eq!(
            lines[2]
                .page_action
                .as_ref()
                .map(|action| (action.parent.as_str(), action.page)),
            Some(("it", 2))
        );
        assert!(canvas.apply_command("expand it.lines.1").expect("string"));
        canvas.select_last();
        assert_eq!(canvas.toggle_selected().as_deref(), Some("page it 2"));
        assert!(canvas.apply_command("expand it.lines.3").expect("string"));
        assert_eq!(
            canvas.plain_lines(),
            ["◂ 2 before · page 2/2", "three", "four"]
        );
        assert!(canvas.apply_command("page it 1").expect("first page"));
        assert_eq!(
            canvas.plain_lines(),
            ["abcdefgh", "two", "▸ … 2 more · page 1/2"]
        );
        assert_eq!(
            canvas
                .apply_command("page it 3")
                .expect_err("out-of-range page"),
            "page 3 is outside 1–2 for `it`"
        );
        assert_eq!(
            canvas.apply_command("page it 1").expect_err("current page"),
            "`it` is already on page 1"
        );
    }

    #[test]
    fn search_observes_only_the_current_buffered_page() {
        let result = CommandResult::from_value(serde_json::json!({
            "title": "Paged",
            "lines": ["alpha", "beta", "needle"]
        }));
        let mut canvas = PresentationCanvas::for_result_with_budget(
            &result,
            PresentationBudget {
                depth: 1,
                nodes: 20,
                items: 2,
                string_chars: 20,
            },
        );
        assert_eq!(canvas.search("needle"), 0);
        assert!(canvas.apply_command("page it 2").expect("second page"));
        assert_eq!(canvas.search("needle"), 1);
        assert!(canvas.apply_command("page it 1").expect("first page"));
        assert_eq!(
            canvas.search_summary().expect("active search").total,
            0,
            "off-page buffered rows must not leak into visible search"
        );
    }

    #[test]
    fn total_node_budget_can_be_deepened_without_losing_its_marker() {
        let result = CommandResult::from_value(serde_json::json!({
            "lines": ["one", "two", "three", "four"]
        }));
        let mut canvas = PresentationCanvas::for_result_with_budget(
            &result,
            PresentationBudget {
                depth: 1,
                nodes: 2,
                items: 10,
                string_chars: 20,
            },
        );
        assert_eq!(
            canvas.plain_lines(),
            ["one", "two", "▸ continue beyond node budget"]
        );
        assert!(canvas.apply_command("expand it.__nodes").expect("nodes"));
        assert_eq!(
            canvas.plain_lines(),
            [
                "one",
                "two",
                "▾ continue beyond node budget",
                "three",
                "four"
            ]
        );
        assert!(
            canvas
                .apply_command("collapse it.__nodes")
                .expect("collapse nodes")
        );
        assert_eq!(
            canvas.plain_lines(),
            ["one", "two", "▸ continue beyond node budget"]
        );
    }
}
