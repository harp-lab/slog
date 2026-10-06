//! Peeks: quick looks at part of a relation or a query from anywhere in
//! the studio -- a hover over a relation's name, the Relations panel, a
//! slice broken out of a table -- without opening a result set or making
//! a transcript entry (web/explorer.js).
//!
//! A peek reads through `Studio::aside`, as the REPL assistant's reads do:
//! it never holds the query cursor past the read (it counts or cancels
//! what it opened), so `more` stays the author's. The rows it read are
//! kept by query while the database stands, so paging a prefix, or
//! another view of the same query, costs no read; past what is kept, the
//! query runs again to reach further rows, up to PEEK_ROWS. A facet -- a
//! column's distinct values with their counts -- reads up to FACET_ROWS.

use crate::assist::{self, BUSY};
use crate::results::{self, Cell, Row, Status, Total};
use crate::studio::Studio;
use serde::{Deserialize, Serialize};
use serde_json::Value;
use std::collections::HashMap;
use std::time::Duration;

/// The furthest row a peek reads to.
pub const PEEK_ROWS: u64 = 5_000;
/// The rows a facet counts.
pub const FACET_ROWS: u64 = 50_000;
/// Queries whose rows are kept, and the rows kept across them.
const ENTRIES: usize = 64;
const KEPT_ROWS: usize = 200_000;
/// How long a peek that may wait waits for the author's command.
const PATIENCE: Duration = Duration::from_secs(30);

/// What a tab asks to see.
#[derive(Debug, Deserialize)]
pub struct Ask {
    /// A `?` query, or another read (`tables`, `show #N`, `uses V`).
    pub line: String,
    #[serde(default)]
    pub start: u64,
    #[serde(default)]
    pub end: u64,
    /// Count the query's rows when they do not all fit (a relation's
    /// count is known from `tables`, so its peek need not).
    #[serde(default)]
    pub count: bool,
    /// The distinct values of this column, with their counts, in place of
    /// the rows.
    #[serde(default)]
    pub facet: Option<usize>,
    /// Wait for a command holding the session, rather than answer busy:
    /// a hover never waits, a refresh after a Run does.
    #[serde(default)]
    pub wait: bool,
}

/// What a peek found: rows `start..` of the query (or of its facet), or a
/// read's whole answer.
#[derive(Debug, Default, Serialize)]
pub struct Peeked {
    pub line: String,
    pub start: u64,
    pub rows: Vec<Row>,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub total: Option<Total>,
    /// Rows remain past those sent.
    pub more: bool,
    /// The query page's title, naming a projection's columns.
    pub title: String,
    /// The database these rows are of (`Event::Database`).
    pub epoch: u64,
    /// A read other than a rows query: its answer.
    #[serde(skip_serializing_if = "Option::is_none")]
    pub result: Option<Value>,
}

#[derive(Default)]
pub struct Peeks {
    epoch: u64,
    clock: u64,
    entries: HashMap<String, Entry>,
}

struct Entry {
    rows: Vec<Row>,
    status: Status,
    total: Option<Total>,
    title: String,
    used: u64,
}

impl Peeks {
    /// The entry for `line` if it can answer rows `..end`, counted if asked.
    fn fresh(&mut self, epoch: u64, line: &str, end: u64, count: bool) -> Option<&Entry> {
        if self.epoch != epoch {
            self.entries.clear();
            self.epoch = epoch;
        }
        self.clock += 1;
        let entry = self.entries.get_mut(line)?;
        entry.used = self.clock;
        let read = entry.rows.len() as u64 >= end || entry.status != Status::Open;
        (read && (!count || entry.total.is_some())).then_some(&*entry)
    }

    fn keep(&mut self, line: &str, entry: Entry) {
        self.entries.insert(line.to_owned(), entry);
        while self.entries.len() > ENTRIES || self.entries.values().map(|e| e.rows.len()).sum::<usize>() > KEPT_ROWS {
            let Some(oldest) = self.entries.iter().min_by_key(|(_, e)| e.used).map(|(k, _)| k.clone()) else { break };
            self.entries.remove(&oldest);
        }
    }
}

impl Studio {
    pub async fn peek(&self, ask: Ask) -> Result<Peeked, String> {
        let line = ask.line.trim();
        let patience = if ask.wait { PATIENCE } else { Duration::ZERO };
        if results::rows_line(line).as_deref() != Some(line) {
            return self.peek_read(line, patience).await;
        }
        let end = match ask.facet {
            Some(_) => FACET_ROWS,
            None => ask.end.min(PEEK_ROWS),
        };
        let epoch = self.epoch();
        let served = {
            let mut peeks = self.peeks.lock().expect("peeks lock");
            peeks.fresh(epoch, line, end, ask.count).map(|entry| serve(entry, &ask, epoch))
        };
        if let Some(peeked) = served {
            return Ok(peeked);
        }
        // Reaching further means running the query again from its first
        // row, so read well past what was asked: twice what is kept.
        let kept = self.peeks.lock().expect("peeks lock").entries.get(line).map_or(0, |entry| entry.rows.len() as u64);
        let end = if ask.facet.is_some() || end <= 50 { end } else { end.max(kept * 2).max(500).min(PEEK_ROWS) };
        let mut session = self.aside(patience).await.ok_or(BUSY)?;
        let epoch = self.epoch();
        let mut outcome = session.execute(&self.lane, line).await;
        let mut rows = Vec::new();
        let (status, title) = loop {
            let result = outcome.result.ok_or_else(|| {
                outcome.error.map_or_else(|| "no answer".to_owned(), |error| error.message)
            })?;
            if result["query-mode"] != "rows" {
                // a ground query answers whether its facts hold
                return Ok(Peeked { line: line.to_owned(), epoch, result: Some(result), ..Peeked::default() });
            }
            let (page, status) = results::page_rows(&result)?;
            rows.extend(page);
            if status != Status::Open || rows.len() as u64 >= end {
                break (status, result["title"].as_str().unwrap_or("").to_owned());
            }
            outcome = session.execute(&self.lane, "more").await;
        };
        // Leave no cursor open: counting the query discards it.
        let total = match status {
            Status::Complete => Some(Total::Exact(rows.len() as u64)),
            Status::Budget => Some(Total::AtLeast(rows.len() as u64)),
            Status::Open if ask.count => Some(assist::count(&mut session, self, line).await),
            Status::Open => {
                let _ = session.execute(&self.lane, "cancel").await;
                None
            }
        };
        drop(session);
        let entry = Entry { rows, status, total, title, used: 0 };
        let peeked = serve(&entry, &ask, epoch);
        let mut peeks = self.peeks.lock().expect("peeks lock");
        if peeks.epoch == epoch {
            peeks.keep(line, entry);
        }
        Ok(peeked)
    }

    /// A read other than a rows query, answered whole.
    async fn peek_read(&self, line: &str, patience: Duration) -> Result<Peeked, String> {
        assist::read_only(line)?;
        let mut session = self.aside(patience).await.ok_or(BUSY)?;
        let epoch = self.epoch();
        let outcome = session.execute(&self.lane, line).await;
        let result = outcome.result.ok_or_else(|| {
            outcome.error.map_or_else(|| "no answer".to_owned(), |error| error.message)
        })?;
        Ok(Peeked { line: line.to_owned(), epoch, result: Some(result), ..Peeked::default() })
    }
}

/// Rows `ask.start..ask.end` of what `entry` read, or of its facet.
fn serve(entry: &Entry, ask: &Ask, epoch: u64) -> Peeked {
    let (rows, total, complete) = match ask.facet {
        Some(column) => {
            let rows = facet(&entry.rows, column);
            let n = rows.len() as u64;
            let complete = entry.status == Status::Complete;
            (rows, Some(if complete { Total::Exact(n) } else { Total::AtLeast(n) }), true)
        }
        None => (entry.rows.clone(), entry.total, entry.status != Status::Open),
    };
    let start = (ask.start as usize).min(rows.len());
    let end = (ask.end as usize).clamp(start, rows.len());
    Peeked {
        line: ask.line.trim().to_owned(),
        start: start as u64,
        rows: rows[start..end].to_vec(),
        total,
        more: end < rows.len() || !complete,
        title: entry.title.clone(),
        epoch,
        result: None,
    }
}

/// `column`'s distinct values, each with how many rows hold it: the most
/// frequent first, then by value.
pub fn facet(rows: &[Row], column: usize) -> Vec<Row> {
    let mut counts: HashMap<&str, (usize, &Cell)> = HashMap::new();
    for cell in rows.iter().filter_map(|row| row.get(column)) {
        counts.entry(cell.text.as_str()).or_insert((0, cell)).0 += 1;
    }
    let mut values: Vec<(usize, &Cell)> = counts.into_values().collect();
    values.sort_by(|a, b| b.0.cmp(&a.0).then_with(|| a.1.text.cmp(&b.1.text)));
    values
        .into_iter()
        .map(|(n, cell)| vec![cell.clone(), Cell { text: n.to_string(), handle: None }])
        .collect()
}

#[cfg(test)]
mod tests {
    use super::{Entry, Peeks, facet};
    use crate::results::{Cell, Row, Status};

    fn row(texts: &[&str]) -> Row {
        texts.iter().map(|t| Cell { text: (*t).to_owned(), handle: None }).collect()
    }

    #[test]
    fn a_facet_counts_each_value_most_frequent_first() {
        let rows = [row(&["1", "a"]), row(&["2", "b"]), row(&["3", "a"]), row(&["4", "c"]), row(&["5", "b"]), row(&["6", "a"])];
        let counted: Vec<(String, String)> = facet(&rows, 1).into_iter().map(|r| (r[0].text.clone(), r[1].text.clone())).collect();
        let pairs = |list: &[(&str, &str)]| list.iter().map(|(a, b)| (a.to_string(), b.to_string())).collect::<Vec<_>>();
        assert_eq!(counted, pairs(&[("a", "3"), ("b", "2"), ("c", "1")]));
        assert!(facet(&rows, 7).is_empty());
    }

    /// Kept rows answer while the database stands and they reach far
    /// enough; a new database forgets them all.
    #[test]
    fn kept_rows_last_as_long_as_the_database() {
        let mut peeks = Peeks::default();
        let entry = |n: usize, status| Entry { rows: vec![row(&["x"]); n], status, total: None, title: String::new(), used: 0 };
        assert!(peeks.fresh(1, "?(r X)", 10, false).is_none());
        peeks.keep("?(r X)", entry(50, Status::Open));
        assert!(peeks.fresh(1, "?(r X)", 50, false).is_some());
        assert!(peeks.fresh(1, "?(r X)", 51, false).is_none(), "rows past those read");
        assert!(peeks.fresh(1, "?(r X)", 10, true).is_none(), "not counted");
        peeks.keep("?(s X)", entry(3, Status::Complete));
        assert!(peeks.fresh(1, "?(s X)", 5000, false).is_some(), "every row read");
        assert!(peeks.fresh(2, "?(r X)", 10, false).is_none(), "a new database");
        assert!(peeks.entries.is_empty());
    }
}

/// Peeks over a real session server, through `Studio`.
#[cfg(test)]
mod served {
    use super::Ask;
    use crate::lane::Mode;
    use crate::results::Total;
    use crate::store::tests::Scratch;
    use crate::studio::tests;

    fn ask(line: &str, start: u64, end: u64) -> Ask {
        Ask { line: line.to_owned(), start, end, count: false, facet: None, wait: true }
    }

    /// A prefix pages past the server's 50-row page from rows kept; a
    /// facet counts every row; no peek opens a set; a change to the
    /// database is a new epoch, and what is read then is of it.
    #[tokio::test]
    async fn peeks_read_prefixes_and_facets_apart_from_the_sets() {
        let scratch = Scratch::new("peek");
        // a chain 1 → … → 30: its closure has 435 rows
        let edges: Vec<String> = (1..30).map(|i| format!("(edge {i} {})", i + 1)).collect();
        let program = format!(
            "table (edge int int)\ntable (path int int)\nrule {}\n\
             rule (edge X Y) --> (path X Y)\nrule (path X Y) (edge Y Z) --> (path X Z)\n",
            edges.join(" ")
        );
        let studio = tests::studio(&scratch, Mode::Fast, &program);
        studio.evaluate().await;

        let first = studio.peek(ask("?(path A B)", 0, 8)).await.unwrap();
        assert_eq!((first.rows.len(), first.more, first.total), (8, true, None));
        let later = studio.peek(ask("?(path A B)", 120, 140)).await.unwrap();
        assert_eq!((later.start, later.rows.len()), (120, 20));
        let counted = studio.peek(Ask { count: true, ..ask("?(path A B)", 0, 8) }).await.unwrap();
        assert_eq!(counted.total, Some(Total::Exact(435)));
        let all = studio.peek(ask("?(path A B)", 0, 1000)).await.unwrap();
        assert_eq!((all.rows.len(), all.more), (435, false));

        let facet = studio.peek(Ask { facet: Some(0), ..ask("?(path A B)", 0, 3) }).await.unwrap();
        let top: Vec<(&str, &str)> = facet.rows.iter().map(|r| (r[0].text.as_str(), r[1].text.as_str())).collect();
        assert_eq!(top, [("1", "29"), ("2", "28"), ("3", "27")]);
        assert_eq!(facet.total, Some(Total::Exact(29)));
        assert!(studio.snapshot().await.results.is_empty(), "a peek opened a set");

        let epoch = all.epoch;
        studio.command("add edge 30 31").await;
        let after = studio.peek(Ask { count: true, ..ask("?(path A B)", 0, 8) }).await.unwrap();
        assert!(after.epoch > epoch);
        assert_eq!(after.total, Some(Total::Exact(465)));
        let tables = studio.peek(ask("tables", 0, 0)).await.unwrap();
        assert_eq!(tables.result.expect("an answer")["kind"], "tables");
        studio.lane.shutdown().await;
    }
}
