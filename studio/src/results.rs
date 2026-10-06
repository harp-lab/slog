//! Result sets: every `?` query typed at the REPL becomes an object Studio
//! can page through, count, and refine with more Slog
//! (docs/REPL-exploration-kris/notes/studio-design.md §7).
//!
//! The session server answers `?` with a page of rows as text and, while
//! rows remain, holds the connection's one query cursor: `more` continues
//! it, and almost any other command discards it (audit Q-10). So a set
//! keeps a bounded cache of its pages; only the most recently browsed set
//! holds the main lane's cursor, the others are *parked*; and rows past a
//! parked set's cache are reached by running its query again and skipping
//! ahead. A set's total comes from a `?count` of the same query, sent just
//! before the query opens its cursor, so counting never costs the cursor.
//!
//! This module is the bookkeeping, with no I/O: it reads the server's
//! answers and says which command to send next. `Studio` sends them.

use serde::{Deserialize, Serialize};
use serde_json::Value;
use std::collections::{BTreeMap, HashMap};
use std::fmt;

/// The most rows one browser request may ask for.
pub const MAX_REQUEST_ROWS: u64 = 1000;
/// Rows cached across all sets; the least recently used pages go first.
const CACHE_ROWS: usize = 50_000;
/// Sets kept; the oldest is forgotten when another opens.
const MAX_SETS: usize = 100;
/// The query register's guard operators (compiler/query-front.rkt).
const GUARDS: [&str; 6] = ["<", "<=", ">", ">=", "/=", "="];

/// `r1`, `r2`, …: numbered in the order sets open.
#[derive(Clone, Copy, Debug, Eq, Hash, Ord, PartialEq, PartialOrd, Serialize, Deserialize)]
#[serde(into = "String", try_from = "String")]
pub struct SetId(u32);

impl fmt::Display for SetId {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "r{}", self.0)
    }
}

impl From<SetId> for String {
    fn from(id: SetId) -> String {
        id.to_string()
    }
}

impl TryFrom<String> for SetId {
    type Error = String;
    fn try_from(text: String) -> Result<Self, String> {
        text.strip_prefix('r')
            .and_then(|n| n.parse().ok())
            .map(SetId)
            .ok_or_else(|| format!("not a result set: {text}"))
    }
}

/// One value of a row, as the server printed it.
#[derive(Clone, Debug, PartialEq, Serialize)]
pub struct Cell {
    pub text: String,
    /// `#N`, naming a compound value whose `text` is a preview cut at a
    /// depth; `show #N` prints it whole, and `#N` splices into a query.
    #[serde(skip_serializing_if = "Option::is_none")]
    pub handle: Option<String>,
}

pub type Row = Vec<Cell>;

#[derive(Clone, Copy, Debug, Eq, PartialEq, Serialize)]
#[serde(tag = "kind", content = "n", rename_all = "kebab-case")]
pub enum Total {
    Exact(u64),
    /// The work budget stopped counting at this many (audit Q-16).
    AtLeast(u64),
    Unknown,
}

impl Total {
    /// The answer to a `?count`. A count the work budget cut short is
    /// marked only in its text, `2157385+ rows match`.
    pub fn of_count(result: &Value) -> Option<Total> {
        if result["query-mode"] != "count" {
            return None;
        }
        let n = result["query-matched"].as_u64()?;
        let line = result["lines"][0].as_str()?;
        Some(if line.starts_with(&format!("{n}+")) {
            Total::AtLeast(n)
        } else {
            Total::Exact(n)
        })
    }

    /// What two observations of one set's size say together.
    fn and(self, other: Total) -> Total {
        match (self, other) {
            (Total::Exact(n), _) | (_, Total::Exact(n)) => Total::Exact(n),
            (Total::AtLeast(a), Total::AtLeast(b)) => Total::AtLeast(a.max(b)),
            (Total::AtLeast(n), Total::Unknown) | (Total::Unknown, Total::AtLeast(n)) => Total::AtLeast(n),
            (Total::Unknown, Total::Unknown) => Total::Unknown,
        }
    }
}

#[derive(Clone, Copy, Debug, Eq, PartialEq, Serialize)]
#[serde(rename_all = "lowercase")]
pub enum Cursor {
    /// Holds the main lane's cursor: `more` continues it.
    Live,
    /// Rows remain, but reaching them past the cache means running the
    /// query again.
    Parked,
    /// Every row has been read, or the work budget ended the query.
    Exhausted,
}

#[derive(Clone, Debug, Eq, PartialEq, Serialize)]
pub struct Column {
    pub name: String,
    /// The query variable the column shows; a constant column has none.
    pub var: Option<String>,
    /// The declared type of the relation column the values come from.
    #[serde(rename = "type")]
    pub kind: Option<String>,
}

/// How a set was made from another.
#[derive(Clone, Debug, Serialize)]
pub struct Lineage {
    pub parent: SetId,
    pub refinement: String,
}

/// A gesture on a set, made into a new query.
#[derive(Clone, Debug, Deserialize)]
#[serde(tag = "op", rename_all = "lowercase")]
pub enum Refinement {
    /// Keep the rows whose `column` holds `value`: a guard `(= VAR value)`.
    Filter { column: usize, value: String },
    /// Stop showing `column`: a projection of the others.
    Drop { column: usize },
    /// The query, as edited by hand.
    Edit { line: String },
}

/// Everything a tab shows about a set except its rows.
#[derive(Clone, Debug, Serialize)]
pub struct View {
    pub id: SetId,
    pub query: String,
    pub columns: Vec<Column>,
    pub total: Total,
    /// Why the total is unknown or still coming.
    pub total_note: Option<String>,
    pub cursor: Cursor,
    /// The work budget ended the query before its last row.
    pub budget: bool,
    /// Rows known to exist: as far as any run of the query has read.
    pub seen: u64,
    /// The projection hides variables, so rows can repeat (audit Q-02).
    pub duplicates: bool,
    /// The database changed since the query ran; only cached rows remain.
    pub stale: bool,
    /// What the server is doing for this set, while it does it.
    pub loading: Option<String>,
    pub parent: Option<Lineage>,
}

/// What to do to serve a range of rows.
#[derive(Debug, PartialEq)]
pub enum Plan {
    Serve(Vec<Row>),
    /// Continue the live cursor.
    More,
    /// Run the query again from its first row.
    Rerun(String),
    Fail(String),
}

pub struct Results {
    sets: BTreeMap<SetId, Set>,
    next: u32,
    live: Option<SetId>,
    /// Advanced whenever the database the main lane queries may change.
    epoch: u64,
    /// Declared column types by relation, from `tables`.
    catalog: HashMap<String, Vec<String>>,
    clock: u64,
    cached: usize,
}

struct Set {
    query: String,
    parsed: Option<Query>,
    columns: Vec<Column>,
    duplicates: bool,
    total: Total,
    total_note: Option<String>,
    cursor: Cursor,
    budget: bool,
    /// Rows the live cursor has delivered since the query last ran.
    at: u64,
    seen: u64,
    /// Cached pages by their first row (0-based).
    pages: BTreeMap<u64, Page>,
    epoch: u64,
    loading: Option<String>,
    parent: Option<Lineage>,
}

struct Page {
    rows: Vec<Row>,
    used: u64,
}

impl Default for Results {
    fn default() -> Self {
        Self {
            sets: BTreeMap::new(),
            next: 1,
            live: None,
            epoch: 0,
            catalog: HashMap::new(),
            clock: 0,
            cached: 0,
        }
    }
}

impl Results {
    /// The database may have changed: nothing holds a cursor any more, and
    /// every set so far is stale. Returns the sets whose views changed.
    pub fn changed(&mut self) -> Vec<SetId> {
        self.epoch += 1;
        self.live = None;
        for set in self.sets.values_mut() {
            if set.cursor == Cursor::Live {
                set.cursor = Cursor::Parked;
            }
        }
        self.sets.keys().copied().collect()
    }

    /// A command that is not this module's discarded the cursor (any
    /// command may, Q-10). Returns the set that held it.
    pub fn park(&mut self) -> Option<SetId> {
        let id = self.live.take()?;
        self.sets.get_mut(&id)?.cursor = Cursor::Parked;
        Some(id)
    }

    /// Learn the declared column types from a `tables` answer.
    pub fn learn(&mut self, result: &Value) {
        if result["kind"] != "tables" {
            return;
        }
        for relation in result["relations"].as_array().into_iter().flatten() {
            if let (Some(name), Some(detail)) = (relation["name"].as_str(), relation["detail"].as_array()) {
                let types = detail.iter().map(|t| t.as_str().unwrap_or("").to_owned()).collect();
                self.catalog.insert(name.to_owned(), types);
            }
        }
    }

    pub fn forget_catalog(&mut self) {
        self.catalog.clear();
    }

    /// Open a set for a `?` query's first page; other answers open none,
    /// `more` typed at the prompt included.
    pub fn open(&mut self, line: &str, result: &Value, parent: Option<Lineage>) -> Result<Option<SetId>, String> {
        if result["query-mode"] != "rows" || !line.trim_start().starts_with('?') {
            return Ok(None);
        }
        let parsed = Query::parse(line);
        let title = result["title"].as_str().unwrap_or("");
        let projected = projection_of(title);
        let columns = parsed.as_ref().map_or_else(Vec::new, |query| match &projected {
            Some(vars) => query.projected_columns(vars, &self.catalog),
            None => query.atom_columns(&self.catalog),
        });
        let duplicates = match (&parsed, &projected) {
            (Some(query), Some(vars)) => query.hides_variables(vars),
            _ => false,
        };
        let id = SetId(self.next);
        self.next += 1;
        self.sets.insert(
            id,
            Set {
                query: line.to_owned(),
                parsed,
                columns,
                duplicates,
                total: Total::Unknown,
                total_note: None,
                cursor: Cursor::Parked,
                budget: false,
                at: 0,
                seen: 0,
                pages: BTreeMap::new(),
                epoch: self.epoch,
                loading: None,
                parent,
            },
        );
        while self.sets.len() > MAX_SETS {
            let oldest = *self.sets.keys().next().expect("more than MAX_SETS sets");
            self.forget(oldest);
        }
        if let Err(error) = self.absorb(id, result) {
            self.forget(id);
            return Err(error);
        }
        Ok(Some(id))
    }

    fn forget(&mut self, id: SetId) {
        if let Some(set) = self.sets.remove(&id) {
            self.cached -= set.pages.values().map(|page| page.rows.len()).sum::<usize>();
        }
        if self.live == Some(id) {
            self.live = None;
        }
    }

    /// Take in a page of `id`'s rows: the answer to its query, run afresh,
    /// or to `more`.
    pub fn absorb(&mut self, id: SetId, result: &Value) -> Result<(), String> {
        let page = parse_page(result)?;
        let set = self.sets.get_mut(&id).ok_or_else(|| format!("{id} is no longer kept"))?;
        if page.start == 0 {
            set.at = 0;
        }
        if page.start != set.at {
            return Err(format!(
                "{id}: a page starting at row {} arrived when the cursor was at row {}",
                page.start + 1,
                set.at + 1
            ));
        }
        let fact = projection_of(result["title"].as_str().unwrap_or("")).is_none();
        let rows: Vec<Row> = page.tuples.iter().map(|tuple| row(tuple, fact)).collect();
        let count = rows.len();
        set.at += count as u64;
        set.seen = set.seen.max(set.at);
        match page.status {
            Status::Open => set.cursor = Cursor::Live,
            Status::Complete => {
                set.cursor = Cursor::Exhausted;
                set.total = Total::Exact(set.at);
            }
            Status::Budget => {
                set.cursor = Cursor::Exhausted;
                set.budget = true;
                set.total = set.total.and(Total::AtLeast(set.at));
            }
        }
        if set.cursor == Cursor::Live {
            self.live = Some(id);
        } else if self.live == Some(id) {
            self.live = None;
        }
        if count > 0 {
            self.clock += 1;
            if let Some(old) = set.pages.insert(page.start, Page { rows, used: self.clock }) {
                self.cached -= old.rows.len();
            }
            self.cached += count;
            self.evict();
        }
        Ok(())
    }

    /// Drop the least recently used pages until the cache fits.
    fn evict(&mut self) {
        while self.cached > CACHE_ROWS {
            let Some((id, start)) = self
                .sets
                .iter()
                .flat_map(|(id, set)| set.pages.iter().map(move |(start, page)| (page.used, *id, *start)))
                .min()
                .map(|(_, id, start)| (id, start))
            else {
                return;
            };
            let page = self.sets.get_mut(&id).and_then(|set| set.pages.remove(&start));
            self.cached -= page.map_or(0, |page| page.rows.len());
        }
    }

    /// How to serve rows `start..end` (0-based) of `id`: from the cache, or
    /// by reading more of the query first.
    pub fn plan(&mut self, id: SetId, start: u64, end: u64) -> Plan {
        let epoch = self.epoch;
        let Some(set) = self.sets.get_mut(&id) else {
            return Plan::Fail(format!("{id} is no longer kept"));
        };
        let end = match set.cursor {
            Cursor::Exhausted => end.min(set.seen),
            Cursor::Live | Cursor::Parked => end,
        };
        let missing = (start..end).find(|&row| !set.cached(row));
        let Some(missing) = missing else {
            self.clock += 1;
            return Plan::Serve(set.take(start, end, self.clock));
        };
        if set.epoch != epoch {
            return Plan::Fail(format!(
                "the database changed since {id} ran, so only its cached rows remain; run its query again"
            ));
        }
        if set.cursor == Cursor::Live && missing >= set.at {
            Plan::More
        } else {
            Plan::Rerun(set.query.clone())
        }
    }

    pub fn counted(&mut self, id: SetId, total: Result<Total, String>) {
        if let Some(set) = self.sets.get_mut(&id) {
            match total {
                Ok(total) => {
                    set.total = set.total.and(total);
                    set.total_note = None;
                }
                Err(why) => set.total_note = Some(format!("not counted: {why}")),
            }
        }
    }

    pub fn set_loading(&mut self, id: SetId, loading: Option<String>) {
        if let Some(set) = self.sets.get_mut(&id) {
            set.loading = loading;
        }
    }

    /// The query a refinement of `id` runs, and the lineage of its set.
    pub fn refine(&self, id: SetId, refinement: &Refinement) -> Result<(String, Lineage), String> {
        let set = self.sets.get(&id).ok_or_else(|| format!("{id} is no longer kept"))?;
        let column = |index: usize| {
            set.columns
                .get(index)
                .ok_or_else(|| format!("{id} has no column {}", index + 1))
        };
        let parsed = || {
            set.parsed
                .as_ref()
                .ok_or_else(|| format!("cannot read {id}'s query to refine it; edit it instead"))
        };
        let (line, label) = match refinement {
            Refinement::Filter { column: index, value } => {
                let column = column(*index)?;
                let var = column.var.as_ref().ok_or_else(|| {
                    format!("{} is a constant of the query: every row has the same value", column.name)
                })?;
                let mut query = parsed()?.clone();
                query.clauses.push(format!("(= {var} {value})"));
                (query.text(), format!("{} = {value}", column.name))
            }
            Refinement::Drop { column: index } => {
                let dropped = column(*index)?;
                let mut kept: Vec<String> = Vec::new();
                for (i, column) in set.columns.iter().enumerate() {
                    if let Some(var) = &column.var
                        && i != *index
                        && !kept.contains(var)
                    {
                        kept.push(var.clone());
                    }
                }
                if kept.is_empty() {
                    return Err(format!("dropping {} leaves no variable to show", dropped.name));
                }
                let mut query = parsed()?.clone();
                query.projection = Some(kept);
                (query.text(), format!("drop {}", dropped.name))
            }
            Refinement::Edit { line } => {
                if !line.trim().starts_with('?') {
                    return Err("a result set's query starts with ?".to_owned());
                }
                let label = if line.trim() == set.query.trim() { "re-run" } else { "edited" };
                (line.trim().to_owned(), label.to_owned())
            }
        };
        Ok((line, Lineage { parent: id, refinement: label }))
    }

    pub fn view(&self, id: SetId) -> Option<View> {
        let set = self.sets.get(&id)?;
        Some(View {
            id,
            query: set.query.clone(),
            columns: set.columns.clone(),
            total: set.total,
            total_note: set.total_note.clone(),
            cursor: set.cursor,
            budget: set.budget,
            seen: set.seen,
            duplicates: set.duplicates,
            stale: set.epoch != self.epoch,
            loading: set.loading.clone(),
            parent: set.parent.clone(),
        })
    }

    pub fn views(&self) -> Vec<View> {
        self.sets.keys().filter_map(|id| self.view(*id)).collect()
    }
}

impl Set {
    fn page_of(&self, row: u64) -> Option<(&u64, &Page)> {
        self.pages
            .range(..=row)
            .next_back()
            .filter(|(start, page)| row < **start + page.rows.len() as u64)
    }

    fn cached(&self, row: u64) -> bool {
        self.page_of(row).is_some()
    }

    /// Rows `start..end`, all cached, marking their pages used at `now`.
    fn take(&mut self, start: u64, end: u64, now: u64) -> Vec<Row> {
        let mut rows = Vec::new();
        let mut row = start;
        while row < end {
            let first = *self.page_of(row).expect("every row was checked cached").0;
            let page = self.pages.get_mut(&first).expect("the page was just found");
            page.used = now;
            let from = (row - first) as usize;
            let to = page.rows.len().min((end - first) as usize);
            rows.extend_from_slice(&page.rows[from..to]);
            row = first + to as u64;
        }
        rows
    }
}

// ---- The server's text ----------------------------------------------------

enum Status {
    Open,
    Complete,
    Budget,
}

struct ParsedPage<'a> {
    /// The 0-based number of the page's first row.
    start: u64,
    tuples: Vec<&'a str>,
    status: Status,
}

/// A rows page (`render-query-page` in compiler/repl.rkt): a header such as
/// `3 rows`, then a line `N  (…)` per row, numbered from 1 across pages.
fn parse_page(result: &Value) -> Result<ParsedPage<'_>, String> {
    let status = match result["query-status"].as_str() {
        Some("open") => Status::Open,
        Some("complete") => Status::Complete,
        Some("budget") => Status::Budget,
        other => return Err(format!("a rows page with status {other:?}")),
    };
    let numbered: Vec<(u64, &str)> = result["lines"]
        .as_array()
        .into_iter()
        .flatten()
        .filter_map(Value::as_str)
        .filter_map(row_line)
        .collect();
    let shown = result["query-shown"]
        .as_u64()
        .ok_or("a rows page without query-shown")?;
    let start = shown
        .checked_sub(numbered.len() as u64)
        .ok_or("a rows page with more rows than it says it shows")?;
    for (offset, (number, _)) in numbered.iter().enumerate() {
        if *number != start + offset as u64 + 1 {
            return Err(format!("row {number} where row {} belongs", start + offset as u64 + 1));
        }
    }
    Ok(ParsedPage {
        start,
        tuples: numbered.into_iter().map(|(_, tuple)| tuple).collect(),
        status,
    })
}

/// A page line `N  (…)`: the row's number and its tuple's text. The header
/// (`3 rows`) also starts with a number, but no tuple follows it.
pub fn row_line(line: &str) -> Option<(u64, &str)> {
    let line = line.trim();
    let rest = line.trim_start_matches(|c: char| c.is_ascii_digit());
    let number = line[..line.len() - rest.len()].parse().ok()?;
    let tuple = rest.trim_start();
    (tuple.len() < rest.len() && tuple.starts_with('(')).then_some((number, tuple))
}

/// A row's cells. A fact `(rel v …)`, as a one-atom query prints its rows,
/// loses its relation name. A tuple that does not read as one (a string
/// printed with a bare quote inside, audit Q-14) is kept whole as one cell
/// rather than lost.
fn row(tuple: &str, fact: bool) -> Row {
    let Some(items) = elements(tuple) else {
        return vec![Cell { text: tuple.to_owned(), handle: None }];
    };
    let mut cells: Row = Vec::new();
    for item in items.into_iter().skip(usize::from(fact)) {
        match cells.last_mut() {
            // A handle follows the compound value it names; a scalar
            // never has one, so a `#N` after a scalar is a value itself.
            Some(cell) if is_handle(item) && cell.handle.is_none() && cell.text.starts_with(['(', '[', '{']) => {
                cell.handle = Some(item.to_owned());
            }
            _ => cells.push(Cell { text: item.to_owned(), handle: None }),
        }
    }
    cells
}

fn is_handle(text: &str) -> bool {
    text.strip_prefix('#')
        .is_some_and(|digits| !digits.is_empty() && digits.bytes().all(|b| b.is_ascii_digit()))
}

/// The elements of one parenthesized tuple, in source form.
fn elements(text: &str) -> Option<Vec<&str>> {
    data(text.strip_prefix('(')?.strip_suffix(')')?)
}

/// The top-level data of `text` in source form: `1 "a b" (f x) #3` gives
/// `1`, `"a b"`, `(f x)`, `#3`. None when brackets or strings do not
/// balance.
fn data(text: &str) -> Option<Vec<&str>> {
    let mut items = Vec::new();
    let mut start = None;
    let mut depth = 0u32;
    let mut chars = text.char_indices();
    while let Some((i, c)) = chars.next() {
        if depth == 0 && c.is_whitespace() {
            items.extend(start.take().map(|s| &text[s..i]));
            continue;
        }
        start.get_or_insert(i);
        match c {
            '"' => loop {
                match chars.next()?.1 {
                    '\\' => {
                        chars.next()?;
                    }
                    '"' => break,
                    _ => {}
                }
            },
            '(' | '[' | '{' => depth += 1,
            ')' | ']' | '}' => depth = depth.checked_sub(1)?,
            _ => {}
        }
    }
    if depth != 0 {
        return None;
    }
    items.extend(start.map(|s| &text[s..]));
    Some(items)
}

/// The variables a projected page names in its title, `Query · (X Z)`; a
/// one-atom query's page is titled `Query` and prints whole facts.
fn projection_of(title: &str) -> Option<Vec<String>> {
    let (_, vars) = title.split_once('·')?;
    Some(elements(vars.trim())?.into_iter().map(str::to_owned).collect())
}

// ---- Queries as Slog --------------------------------------------------------

/// A rows query, `? CLAUSE… [-> (VAR…)]`, as clauses of source text
/// (compiler/query-front.rkt has the grammar).
#[derive(Clone, Debug, PartialEq)]
struct Query {
    clauses: Vec<String>,
    projection: Option<Vec<String>>,
}

impl Query {
    /// None for `?count`, `?exists`, and text that does not read as a query.
    fn parse(line: &str) -> Option<Query> {
        let body = line.trim().strip_prefix('?')?;
        let aggregate = ["count", "exists"].iter().any(|mode| {
            body.strip_prefix(mode)
                .is_some_and(|rest| !rest.starts_with(|c: char| c.is_alphanumeric()))
        });
        if aggregate {
            return None;
        }
        let items = data(body)?;
        let (clauses, projection) = match items.iter().position(|item| *item == "->") {
            None => (&items[..], None),
            Some(arrow) if arrow + 2 == items.len() => (
                &items[..arrow],
                Some(elements(items[arrow + 1])?.into_iter().map(str::to_owned).collect()),
            ),
            Some(_) => return None,
        };
        Some(Query {
            clauses: clauses.iter().map(|clause| (*clause).to_owned()).collect(),
            projection,
        })
    }

    fn text(&self) -> String {
        let mut text = format!("? {}", self.clauses.join(" "));
        if let Some(vars) = &self.projection {
            text.push_str(&format!(" -> ({})", vars.join(" ")));
        }
        text
    }

    /// The positive atoms, as relation name and terms: not guards, not
    /// computes, not `~` absences (spelled `~(…)` or `~ (…)`).
    fn atoms(&self) -> Vec<(&str, Vec<&str>)> {
        let mut atoms = Vec::new();
        let mut negated = false;
        for clause in &self.clauses {
            if clause == "~" {
                negated = true;
                continue;
            }
            let absent = std::mem::take(&mut negated) || clause.starts_with('~');
            if let Some([head, terms @ ..]) = elements(clause).as_deref()
                && !absent
                && !GUARDS.contains(head)
            {
                atoms.push((*head, terms.to_vec()));
            }
        }
        atoms
    }

    /// The columns of a one-atom query's facts: `rel.1`, `rel.2`, ….
    fn atom_columns(&self, catalog: &HashMap<String, Vec<String>>) -> Vec<Column> {
        let atoms = self.atoms();
        let Some((relation, terms)) = atoms.first() else {
            return Vec::new();
        };
        terms
            .iter()
            .enumerate()
            .map(|(i, term)| Column {
                name: format!("{relation}.{}", i + 1),
                var: is_variable(term).then(|| (*term).to_owned()),
                kind: declared(catalog, relation, i),
            })
            .collect()
    }

    /// The columns of a projection: one per variable, typed by the first
    /// atom column it is drawn from.
    fn projected_columns(&self, vars: &[String], catalog: &HashMap<String, Vec<String>>) -> Vec<Column> {
        let atoms = self.atoms();
        vars.iter()
            .map(|var| Column {
                name: var.clone(),
                var: Some(var.clone()),
                kind: atoms.iter().find_map(|(relation, terms)| {
                    let position = terms.iter().position(|term| term == var)?;
                    declared(catalog, relation, position)
                }),
            })
            .collect()
    }

    /// Whether a variable of the atoms is not shown, or `_` matches
    /// anything: rows then repeat once per hidden binding (audit Q-02).
    fn hides_variables(&self, shown: &[String]) -> bool {
        self.atoms().iter().flat_map(|(_, terms)| terms).any(|term| {
            *term == "_" || (is_variable(term) && !shown.iter().any(|var| var == term))
        })
    }
}

/// The `?count` of a rows query, which totals the set it opens; None for
/// any other line.
pub fn count_line(line: &str) -> Option<String> {
    Query::parse(line)?;
    let body = line.trim().strip_prefix('?')?;
    Some(format!("?count {body}"))
}

fn declared(catalog: &HashMap<String, Vec<String>>, relation: &str, position: usize) -> Option<String> {
    catalog.get(relation)?.get(position).filter(|t| !t.is_empty()).cloned()
}

/// Symbols are variables in a query, except `_`; literals are numbers,
/// strings, `#t`/`#f`, and `#N` handles.
fn is_variable(term: &str) -> bool {
    let number = term
        .trim_start_matches(['+', '-'])
        .starts_with(|c: char| c.is_ascii_digit() || c == '.');
    !term.is_empty() && term != "_" && !number && !term.starts_with(['"', '#', '(', '[', '{'])
}

#[cfg(test)]
mod tests {
    use super::{CACHE_ROWS, Cursor, Plan, Refinement, Results, Row, SetId, Total, row};
    use serde_json::{Value, json};

    /// A rows page as compiler/repl.rkt's render-query-page prints it.
    fn page(title: &str, start: u64, tuples: &[String], status: &str) -> Value {
        let shown = start + tuples.len() as u64;
        let mut lines = vec![format!("rows {}–{shown}", start + 1)];
        lines.extend(tuples.iter().enumerate().map(|(i, t)| format!("{}  {t}", start + i as u64 + 1)));
        json!({"kind": "query", "title": title, "lines": lines, "query-mode": "rows",
               "query-status": status, "query-matched": shown, "query-shown": shown})
    }

    fn texts(rows: &[Row]) -> Vec<Vec<&str>> {
        rows.iter().map(|row| row.iter().map(|cell| cell.text.as_str()).collect()).collect()
    }

    /// Real answers from a session on reach.slog
    /// (docs/REPL-exploration-kris/prototype/captures/session-reach.jsonl):
    /// `tables`, a one-atom query, and a projected join.
    #[test]
    fn captured_pages_read_as_typed_columns_and_cells() {
        let tables = json!({"kind": "tables", "relations": [
            {"arity": 2, "detail": ["int", "int"], "kind": "table", "name": "edge", "rows": 3},
            {"arity": 2, "detail": ["int", "int"], "kind": "table", "name": "path", "rows": 6}]});
        let fact = json!({"kind": "query", "lines": ["3 rows", "1  (path 1 2)", "2  (path 1 3)", "3  (path 1 4)"],
            "query-matched": 3, "query-mode": "rows", "query-shown": 3, "query-status": "complete", "title": "Query"});
        let join = json!({"kind": "query", "lines": ["2 rows", "1  (2 4)", "2  (1 3)"], "query-matched": 2,
            "query-mode": "rows", "query-shown": 2, "query-status": "complete", "title": "Query · (X Z)"});
        let mut results = Results::default();
        results.learn(&tables);

        let id = results.open("?(path 1 Y)", &fact, None).unwrap().unwrap();
        let view = results.view(id).unwrap();
        let columns: Vec<_> = view.columns.iter().map(|c| (c.name.as_str(), c.var.as_deref(), c.kind.as_deref())).collect();
        assert_eq!(columns, [("path.1", None, Some("int")), ("path.2", Some("Y"), Some("int"))]);
        assert_eq!((view.total, view.cursor, view.duplicates), (Total::Exact(3), Cursor::Exhausted, false));
        let Plan::Serve(rows) = results.plan(id, 0, 10) else { panic!("the page is cached") };
        assert_eq!(texts(&rows), [["1", "2"], ["1", "3"], ["1", "4"]]);

        let id = results.open("? (edge X Y) (edge Y Z) -> (X Z)", &join, None).unwrap().unwrap();
        let view = results.view(id).unwrap();
        let columns: Vec<_> = view.columns.iter().map(|c| (c.name.as_str(), c.kind.as_deref())).collect();
        assert_eq!(columns, [("X", Some("int")), ("Z", Some("int"))]);
        // Y is projected away, so a row repeats once per Y (audit Q-02)
        assert!(view.duplicates);
        let Plan::Serve(rows) = results.plan(id, 0, 10) else { panic!("the page is cached") };
        assert_eq!(texts(&rows), [["2", "4"], ["1", "3"]]);
    }

    #[test]
    fn cells_keep_strings_and_compound_values_whole() {
        let cells = row(r#"(rel "a (b) c" (pt [1 2] "x)") #4 #5 -3)"#, true);
        let cells: Vec<_> = cells.iter().map(|c| (c.text.as_str(), c.handle.as_deref())).collect();
        // `#5` follows a value that already has its handle: it is a spliced
        // handle, printed as a value of its own
        assert_eq!(cells, [(r#""a (b) c""#, None), (r#"(pt [1 2] "x)")"#, Some("#4")), ("#5", None), ("-3", None)]);
        // strings print with bare quotes inside (audit Q-14): an even number
        // still reads, glued into one cell; an odd one does not read as a
        // tuple, and the row survives as one cell
        let texts = |tuple| row(tuple, true).into_iter().map(|c| c.text).collect::<Vec<_>>();
        assert_eq!(texts(r#"(word "say "hi"" 3)"#), [r#""say "hi"""#, "3"]);
        assert_eq!(texts(r#"(word "5" tall" 3)"#), [r#"(word "5" tall" 3)"#]);
    }

    /// A `?count` the budget cut short is a lower bound, whatever the rows
    /// read so far; only a complete count or reading every row is exact.
    #[test]
    fn a_total_is_exact_only_when_nothing_cut_it_short() {
        let count = |line: &str, n: u64| json!({"query-mode": "count", "query-matched": n, "lines": [line]});
        assert_eq!(Total::of_count(&count("6 rows match", 6)), Some(Total::Exact(6)));
        assert_eq!(Total::of_count(&count("2157385+ rows match", 2157385)), Some(Total::AtLeast(2157385)));

        let tuples = |range: std::ops::Range<u64>| range.map(|i| format!("({i})")).collect::<Vec<_>>();
        let mut results = Results::default();
        let id = results.open("?(n X)", &page("Query · (X)", 0, &tuples(0..50), "open"), None).unwrap().unwrap();
        assert_eq!(results.view(id).unwrap().total, Total::Unknown);
        results.counted(id, Ok(Total::AtLeast(70)));
        assert_eq!(results.view(id).unwrap().total, Total::AtLeast(70));
        // the work budget stops the rows at 80: still only a lower bound
        results.absorb(id, &page("Query · (X)", 50, &tuples(50..80), "budget")).unwrap();
        let view = results.view(id).unwrap();
        assert_eq!((view.total, view.budget, view.cursor), (Total::AtLeast(80), true, Cursor::Exhausted));
        // an exact count settles it
        results.counted(id, Ok(Total::Exact(1000)));
        assert_eq!(results.view(id).unwrap().total, Total::Exact(1000));
    }

    #[test]
    fn refinements_are_queries_over_the_columns_variables() {
        let fact = page("Query", 0, &["(path 1 2)".to_owned()], "complete");
        let join = page("Query · (X Z)", 0, &["(1 3)".to_owned()], "complete");
        let mut results = Results::default();
        let sugar = results.open("?(path 1 Y)", &fact, None).unwrap().unwrap();
        let projected = results
            .open("? (path X Y) ~(edge X Y) (edge Y Z) -> (X Z)", &join, None)
            .unwrap()
            .unwrap();
        let refine = |id: SetId, refinement: Refinement| {
            results.refine(id, &refinement).map(|(line, lineage)| (line, lineage.refinement))
        };
        let filter = |column, value: &str| Refinement::Filter { column, value: value.to_owned() };

        assert_eq!(refine(sugar, filter(1, "2")).unwrap(), ("? (path 1 Y) (= Y 2)".to_owned(), "path.2 = 2".to_owned()));
        assert!(refine(sugar, filter(0, "1")).unwrap_err().contains("constant"));
        assert_eq!(refine(sugar, Refinement::Drop { column: 0 }).unwrap().0, "? (path 1 Y) -> (Y)");
        assert!(refine(sugar, Refinement::Drop { column: 1 }).unwrap_err().contains("no variable"));
        assert_eq!(
            refine(projected, filter(0, "#7")).unwrap().0,
            "? (path X Y) ~(edge X Y) (edge Y Z) (= X #7) -> (X Z)"
        );
        assert_eq!(
            refine(projected, Refinement::Drop { column: 1 }).unwrap().0,
            "? (path X Y) ~(edge X Y) (edge Y Z) -> (X)"
        );
        let edit = |line: &str| Refinement::Edit { line: line.to_owned() };
        assert_eq!(refine(sugar, edit("?(path 1 Y)")).unwrap().1, "re-run");
        assert!(refine(sugar, edit("tables")).is_err());
    }

    /// Pages beyond the cache's bound are dropped least recently used
    /// first; a dropped row is read again by running the query.
    #[test]
    fn the_cache_is_bounded_and_dropped_rows_are_read_again() {
        let tuples = |start: u64| (start..start + 50).map(|i| format!("({i})")).collect::<Vec<_>>();
        let mut results = Results::default();
        let id = results.open("?(n X)", &page("Query · (X)", 0, &tuples(0), "open"), None).unwrap().unwrap();
        let mut at = 50;
        while at < CACHE_ROWS as u64 + 100 {
            assert_eq!(results.plan(id, at, at + 50), Plan::More);
            results.absorb(id, &page("Query · (X)", at, &tuples(at), "open")).unwrap();
            at += 50;
        }
        assert!(matches!(results.plan(id, 0, 1), Plan::Rerun(query) if query == "?(n X)"));
        let Plan::Serve(rows) = results.plan(id, at - 120, at) else { panic!("recent rows are cached") };
        let expected: Vec<String> = (at - 120..at).map(|i| i.to_string()).collect();
        assert_eq!(texts(&rows).concat(), expected);
        // a page that does not continue the cursor is refused, not cached
        assert!(results.absorb(id, &page("Query · (X)", at + 50, &tuples(at + 50), "open")).is_err());
    }
}

/// Result sets over a real session server, through `Studio`.
#[cfg(test)]
mod served {
    use super::{Cursor, Refinement, Row, SetId, Total, View};
    use crate::lane::Mode;
    use crate::store::tests::Scratch;
    use crate::studio::{Event, Studio, tests};
    use std::collections::BTreeSet;

    /// Nodes in the test chain: its closure has N(N-1)/2 = 210 rows, over
    /// five 50-row pages.
    const N: u64 = 21;

    /// A chain 1 → 2 → … → N and its closure, a struct column and a string
    /// column.
    fn program() -> String {
        let edges: Vec<String> = (1..N).map(|i| format!("(edge {i} {})", i + 1)).collect();
        format!(
            "table (edge int int)\ntable (path int int)\nstruct (pt int int)\n\
             table (at int pt)\ntable (label int str)\n\
             rule {}\nrule (edge X Y) --> (path X Y)\nrule (path X Y) (edge Y Z) --> (path X Z)\n\
             rule (at 1 (pt 1 2)) (label 1 \"one (1) two\")\n",
            edges.join(" ")
        )
    }

    fn closure() -> BTreeSet<(u64, u64)> {
        (1..=N).flat_map(|x| (x + 1..=N).map(move |y| (x, y))).collect()
    }

    struct Fixture {
        studio: Studio,
        _scratch: Scratch,
    }

    impl Fixture {
        async fn new(name: &str) -> Self {
            let scratch = Scratch::new(name);
            let studio = tests::studio(&scratch, Mode::Fast, &program());
            studio.evaluate().await;
            Self { studio, _scratch: scratch }
        }

        /// Run a `?` query at the REPL; the set it opened.
        async fn query(&self, line: &str) -> SetId {
            self.studio.command(line).await;
            self.views().await.last().expect("the query opened a set").id
        }

        async fn views(&self) -> Vec<View> {
            self.studio.snapshot().await.results
        }

        async fn view(&self, id: SetId) -> View {
            self.views().await.into_iter().find(|view| view.id == id).expect("a kept set")
        }

        /// Every row, asked for in windows that straddle pages.
        async fn all_rows(&self, id: SetId) -> Vec<Row> {
            let mut rows = Vec::new();
            loop {
                let start = rows.len() as u64;
                let window = self.studio.rows(id, start, start + 37).await.expect("rows");
                if window.is_empty() {
                    return rows;
                }
                rows.extend(window);
            }
        }

        async fn finish(self) {
            self.studio.lane.shutdown().await;
        }
    }

    fn pairs(rows: &[Row]) -> Vec<(u64, u64)> {
        rows.iter()
            .map(|row| (row[0].text.parse().unwrap(), row[1].text.parse().unwrap()))
            .collect()
    }

    /// The count runs before the query opens its cursor, so the set is
    /// totalled while the cursor is live, and paging continues with `more`:
    /// every row once, the query never run twice.
    #[tokio::test]
    async fn paging_reads_every_row_exactly_once() {
        let fixture = Fixture::new("paging").await;
        let mut events = fixture.studio.subscribe();
        let id = fixture.query("?(path X Y)").await;
        let view = fixture.view(id).await;
        assert_eq!((view.cursor, view.seen), (Cursor::Live, 50));
        assert_eq!(view.total, Total::Exact(closure().len() as u64));

        let rows = fixture.all_rows(id).await;
        let read = pairs(&rows);
        assert_eq!(read.len(), closure().len(), "a row read twice or missed");
        assert_eq!(read.into_iter().collect::<BTreeSet<_>>(), closure());
        assert_eq!(fixture.view(id).await.cursor, Cursor::Exhausted);
        let reran = std::iter::from_fn(|| events.try_recv().ok())
            .any(|event| matches!(event, Event::ResultSet(view) if view.loading.is_some()));
        assert!(!reran, "the cursor was lost and the query run again");

        // compound values carry their handles; strings stay whole
        let at = fixture.query("?(at X P)").await;
        let row = &fixture.studio.rows(at, 0, 1).await.unwrap()[0];
        assert_eq!(row[1].text, "(pt 1 2)");
        assert!(row[1].handle.as_deref().is_some_and(|handle| handle.starts_with('#')));
        let label = fixture.query("?(label X S)").await;
        assert_eq!(fixture.studio.rows(label, 0, 1).await.unwrap()[0][1].text, "\"one (1) two\"");
        fixture.finish().await;
    }

    /// Only the most recently browsed set holds the cursor. A parked set
    /// serves its cache as is, and runs its query again to go past it.
    #[tokio::test]
    async fn a_parked_set_runs_its_query_again_to_go_past_its_cache() {
        let fixture = Fixture::new("parking").await;
        let path = fixture.query("?(path X Y)").await;
        let next = fixture.query("? (path X Y) (edge Y Z) -> (X Z)").await;
        let cursors = |views: Vec<View>| views.into_iter().map(|view| view.cursor).collect::<Vec<_>>();
        assert_eq!(cursors(fixture.views().await), [Cursor::Parked, Cursor::Live]);

        let cached = fixture.studio.rows(path, 0, 50).await.unwrap();
        assert_eq!(cursors(fixture.views().await), [Cursor::Parked, Cursor::Live]);
        let mut events = fixture.studio.subscribe();
        let beyond = fixture.studio.rows(path, 120, 160).await.unwrap();
        assert_eq!(cursors(fixture.views().await), [Cursor::Live, Cursor::Parked]);
        let said = std::iter::from_fn(|| events.try_recv().ok()).any(|event| {
            matches!(event, Event::ResultSet(view) if view.id == path
                && view.loading.as_deref() == Some("running the query again to reach row 121"))
        });
        assert!(said, "the re-run was not announced");

        // the re-run's rows agree with one reading of the whole set
        let all = fixture.all_rows(path).await;
        assert_eq!(pairs(&all[..50]), pairs(&cached));
        assert_eq!(pairs(&all[120..160]), pairs(&beyond));
        let read = pairs(&all);
        assert_eq!(read.len(), closure().len());
        assert_eq!(read.into_iter().collect::<BTreeSet<_>>(), closure());

        // the other set, parked after one page, likewise
        let expected: BTreeSet<(u64, u64)> = closure().into_iter().filter(|&(_, y)| y < N).map(|(x, y)| (x, y + 1)).collect();
        let read = pairs(&fixture.all_rows(next).await);
        assert_eq!(read.len(), expected.len());
        assert_eq!(read.into_iter().collect::<BTreeSet<_>>(), expected);
        assert_eq!(fixture.view(next).await.total, Total::Exact(expected.len() as u64));
        fixture.finish().await;
    }

    /// The query text a gesture makes is Slog the server runs, and it means
    /// what the gesture says.
    #[tokio::test]
    async fn refinements_run_as_queries_with_lineage() {
        let fixture = Fixture::new("refine").await;
        let path = fixture.query("?(path X Y)").await;
        let x = fixture.studio.rows(path, 0, 1).await.unwrap()[0][0].text.clone();
        let refine = async |refinement: Refinement| {
            let (line, lineage) = fixture.studio.refinement(path, &refinement).expect("a refinement");
            fixture.studio.run(&line, Some(lineage)).await;
            fixture.views().await.pop().expect("the refinement opened a set")
        };

        let filtered = refine(Refinement::Filter { column: 0, value: x.clone() }).await;
        assert_eq!(filtered.parent.as_ref().map(|lineage| lineage.parent), Some(path));
        let x: u64 = x.parse().unwrap();
        let expected: BTreeSet<(u64, u64)> = closure().into_iter().filter(|&(from, _)| from == x).collect();
        assert_eq!(filtered.total, Total::Exact(expected.len() as u64));
        let read = pairs(&fixture.all_rows(filtered.id).await);
        assert_eq!(read.into_iter().collect::<BTreeSet<_>>(), expected);

        // projection keeps one row per hidden binding (audit Q-02)
        let dropped = refine(Refinement::Drop { column: 1 }).await;
        assert!(dropped.duplicates);
        let rows = fixture.all_rows(dropped.id).await;
        assert_eq!(rows.len(), closure().len());
        let firsts = rows.iter().filter(|row| row[0].text == "1").count() as u64;
        assert_eq!(firsts, N - 1);
        fixture.finish().await;
    }
}
