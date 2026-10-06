//! Result sets: every `?` query typed at the REPL becomes an object Studio
//! can page through, count, and refine with more Slog
//! (docs/REPL-exploration-kris/notes/studio-design.md §7).
//!
//! The session server makes every query a result set, r1, r2, ...
//! (compiler/repl.rkt): it counts it, shows its first page, names its
//! columns, and re-counts it after each committed change while it is live.
//! Studio names the set it opens (`?QUERY as rN`, so its numbering holds
//! across lanes and restarts), and its own reads make none (`as _`).
//!
//! The server answers with a page of rows as text and, while rows remain,
//! holds the connection's one query cursor: `more` continues it, and
//! almost any other command discards it (audit Q-10). So a set keeps a
//! bounded cache of its pages; only the most recently browsed set holds
//! the main lane's cursor, the others are *parked*; and rows past a parked
//! set's cache are reached by reading the set again (`show rN`) and
//! skipping ahead.
//!
//! A query's answers are also kept as a relation of the session, named
//! after the set: `keep rN` has the server join a scratch definition
//! `table (rN T...) rule (rN V...) <-- BODY` to the session's scratch
//! layer, computed over the live database without running the program
//! again, and the set reads that relation back. Later queries and
//! refinements can name it, and its rows are a set, not the query's bag
//! (audit Q-02). A count is of matches, and stays the query's.
//!
//! This module is the bookkeeping, with no I/O: it reads the server's
//! answers and says which command to send next. `Studio` sends them.

use serde::{Deserialize, Serialize};
use serde_json::Value;
use crate::states::Stamp;
use std::collections::BTreeMap;
use std::fmt;

/// The most rows one browser request may ask for.
pub const MAX_REQUEST_ROWS: u64 = 1000;
/// Rows cached across all sets; the least recently used pages go first.
const CACHE_ROWS: usize = 200_000;
/// The most rows Studio reads to sort a set (queries have no order).
pub const SORT_ROWS: usize = 100_000;
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

#[derive(Clone, Copy, Debug, Eq, PartialEq, Serialize, Deserialize)]
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

#[derive(Clone, Debug, Eq, PartialEq, Serialize, Deserialize)]
pub struct Column {
    pub name: String,
    /// The query variable the column shows; a constant column has none.
    pub var: Option<String>,
    /// The declared type of the relation column the values come from.
    #[serde(rename = "type")]
    pub kind: Option<String>,
}

/// How a set was made from another.
#[derive(Clone, Debug, Serialize, Deserialize)]
pub struct Lineage {
    pub parent: SetId,
    pub refinement: String,
}

/// The order Studio sorted a set's rows in.
#[derive(Clone, Copy, Debug, Eq, PartialEq, Serialize)]
pub struct Order {
    pub column: usize,
    pub descending: bool,
}

/// A gesture on a set, made into a new query.
#[derive(Clone, Debug, Deserialize)]
#[serde(tag = "op", rename_all = "lowercase")]
pub enum Refinement {
    /// Keep the rows whose `column` holds `value`: a guard `(= VAR value)`,
    /// or another of the query's guard operators.
    Filter {
        column: usize,
        value: String,
        #[serde(default)]
        guard: Option<String>,
    },
    /// Stop showing `column`: a projection of the others.
    Drop { column: usize },
    /// The query, as edited by hand.
    Edit { line: String },
    /// The rows in the order of `column`'s values. Queries have no order
    /// (studio-design.md §7.4), so Studio reads every row and sorts them:
    /// `Studio::sort`, not a query.
    Sort {
        column: usize,
        #[serde(default)]
        descending: bool,
    },
}

/// Everything a tab shows about a set except its rows.
#[derive(Clone, Debug, Serialize)]
pub struct View {
    pub id: SetId,
    pub query: String,
    pub columns: Vec<Column>,
    pub total: Total,
    pub cursor: Cursor,
    /// The work budget ended the query before its last row.
    pub budget: bool,
    /// Rows known to exist: as far as any run of the query has read.
    pub seen: u64,
    /// The projection hides variables, so rows can repeat (audit Q-02).
    pub duplicates: bool,
    /// The database changed since the query ran; only cached rows remain.
    pub stale: bool,
    /// Advanced whenever the server re-counted the set after a change: its
    /// rows may differ, and are read again.
    pub revision: u64,
    /// What the server is doing for this set, while it does it.
    pub loading: Option<String>,
    pub parent: Option<Lineage>,
    /// The session relation holding the set's rows.
    pub relation: Option<String>,
    /// Why the answers are not kept as a relation, when they are not.
    pub unkept: Option<String>,
    /// Studio sorted the rows; they are the parent's, in this order.
    pub sorted: Option<Order>,
    /// The session state the query ran at (states.rs).
    pub state: Option<Stamp>,
}

/// A query's answers kept as a relation (`keep rN`).
#[derive(Clone, Debug)]
pub struct Kept {
    pub relation: String,
    /// The scratch definition that keeps them, to define it again where
    /// the set is read at a past state (states.rs).
    pub definition: String,
}

impl Kept {
    /// What a `keep rN` answer says is kept: the relation, and the `?`
    /// line and columns it is read back with.
    pub fn of(result: &Value) -> Option<(Kept, String, Vec<Column>)> {
        let kept = Kept {
            relation: result["set"]["relation"].as_str()?.to_owned(),
            definition: result["definition"].as_str()?.to_owned(),
        };
        let read = result["set"]["read"].as_str()?.to_owned();
        Some((kept, read, columns_of(result)))
    }
}

/// A set answer's columns, as the server names and types them.
pub fn columns_of(result: &Value) -> Vec<Column> {
    serde_json::from_value(result["columns"].clone()).unwrap_or_default()
}

/// The size a set answer says its set has.
pub fn total_of(result: &Value) -> Total {
    let set = &result["set"];
    match (set["count"].as_u64(), set["exact"].as_bool()) {
        (Some(n), Some(true)) => Total::Exact(n),
        (Some(n), _) => Total::AtLeast(n),
        _ => Total::Unknown,
    }
}

/// What a set opens with besides its first page.
pub struct Opening {
    /// The name the set was made with (`Results::reserve`).
    pub id: SetId,
    /// The query as typed: shown, and edited.
    pub query: String,
    /// The `?` line whose pages the set shows: a kept relation read back,
    /// or the query's rows.
    pub read: String,
    /// As the server names and types them.
    pub columns: Vec<Column>,
    pub kept: Result<Kept, String>,
    pub parent: Option<Lineage>,
    /// The session state the query ran at (states.rs).
    pub state: Option<Stamp>,
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
    clock: u64,
    cached: usize,
}

struct Set {
    query: String,
    read: String,
    /// `read`, as clauses.
    parsed: Option<Query>,
    columns: Vec<Column>,
    duplicates: bool,
    total: Total,
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
    kept: Result<String, String>,
    /// The scratch definition of the kept relation.
    definition: Option<String>,
    /// The rows were sorted by Studio: they cannot be read again, only
    /// sorted again.
    sorted: Option<Order>,
    state: Option<Stamp>,
    revision: u64,
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

    /// Advanced whenever the database queries see may have changed.
    pub fn epoch(&self) -> u64 {
        self.epoch
    }

    /// The name the next set opens with, taken: the query is sent naming
    /// it, so the session's set is the studio's, on any lane.
    pub fn reserve(&mut self) -> SetId {
        self.next += 1;
        SetId(self.next - 1)
    }

    /// The session re-counted its live sets after a committed change
    /// (`change.sets`): each that still reads is current again, at state
    /// `state` and its new size; its cached rows are dropped, to be read
    /// again when asked, as a count does not see rows that change in place.
    /// Returns the sets whose views changed.
    pub fn settled(&mut self, records: &Value, state: Stamp) -> Vec<SetId> {
        let mut touched = Vec::new();
        for record in records.as_array().into_iter().flatten() {
            let Some(id) = record["name"].as_str().and_then(|name| SetId::try_from(name.to_owned()).ok()) else {
                continue;
            };
            let (Some(after), Some(set)) = (record["after"].as_u64(), self.sets.get_mut(&id)) else {
                continue;
            };
            if set.sorted.is_some() {
                continue;
            }
            self.cached -= set.pages.values().map(|page| page.rows.len()).sum::<usize>();
            set.pages.clear();
            set.total = if record["exact"] == true { Total::Exact(after) } else { Total::AtLeast(after) };
            set.cursor = Cursor::Parked;
            set.at = 0;
            set.seen = 0;
            set.budget = false;
            set.epoch = self.epoch;
            set.state = Some(state);
            set.revision += 1;
            touched.push(id);
        }
        touched
    }

    /// Open a set on the first page of its `read` query; an answer that is
    /// not a rows page opens none.
    pub fn open(&mut self, opening: Opening, result: &Value) -> Result<Option<SetId>, String> {
        let Opening { id, query, read, columns, kept, parent, state } = opening;
        if result["query-mode"] != "rows" || !read.trim_start().starts_with('?') {
            return Ok(None);
        }
        self.next = self.next.max(id.0 + 1);
        let parsed = Query::parse(&read);
        let (duplicates, kept, definition) = match kept {
            Ok(Kept { relation, definition }) => (false, Ok(relation), Some(definition)),
            Err(why) => {
                let projected = projection_of(result["title"].as_str().unwrap_or(""));
                let duplicates = match (&parsed, &projected) {
                    (Some(query), Some(vars)) => query.hides_variables(vars),
                    _ => false,
                };
                (duplicates, Err(why), None)
            }
        };
        self.sets.insert(
            id,
            Set {
                query,
                read,
                parsed,
                columns,
                duplicates,
                total: total_of(result),
                cursor: Cursor::Parked,
                budget: false,
                at: 0,
                seen: 0,
                pages: BTreeMap::new(),
                epoch: self.epoch,
                loading: None,
                parent,
                kept,
                definition,
                sorted: None,
                state,
                revision: 0,
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
        if set.sorted.is_some() {
            let parent = set.parent.as_ref().map_or(id, |lineage| lineage.parent);
            return Plan::Fail(format!("{id}'s sorted rows left the cache; sort {parent} again"));
        }
        if set.epoch != epoch && set.state.is_none() {
            return Plan::Fail(format!(
                "the database changed since {id} ran, so only its cached rows remain; run its query again"
            ));
        }
        if set.cursor == Cursor::Live && missing >= set.at {
            Plan::More
        } else {
            Plan::Rerun(set.read.clone())
        }
    }

    /// Where `id`'s rows are read: `None` on the main lane, which still
    /// holds the database it ran at; else the state it ran at, re-derived
    /// (states.rs). `current` is the session's state.
    pub fn past(&self, id: SetId, current: u64) -> Option<u64> {
        let set = self.sets.get(&id)?;
        let state = set.state?.id;
        (set.epoch != self.epoch || state != current).then_some(state)
    }

    /// Take in a page of `id`'s rows read on a lane of a past state, whose
    /// cursor is not the main lane's.
    pub fn absorb_past(&mut self, id: SetId, result: &Value) -> Result<(), String> {
        let live = self.live;
        let absorbed = self.absorb(id, result);
        self.live = live.filter(|live| *live != id);
        absorbed
    }

    /// The `?` line `id` reads its rows with, and the query as typed.
    pub fn read_line(&self, id: SetId) -> Option<String> {
        self.sets.get(&id).map(|set| set.read.clone())
    }

    pub fn query_line(&self, id: SetId) -> Option<String> {
        self.sets.get(&id).map(|set| set.query.clone())
    }

    /// Open a set, as `open` does, on a lane of a past state, whose cursor
    /// is not the main lane's.
    pub fn open_past(&mut self, opening: Opening, result: &Value) -> Result<Option<SetId>, String> {
        let live = self.live;
        let opened = self.open(opening, result);
        if let Ok(Some(id)) = opened {
            // read where it ran, never on the main lane
            if let Some(set) = self.sets.get_mut(&id) {
                set.epoch = u64::MAX;
            }
        }
        self.live = live;
        opened
    }

    /// The definition of the kept relation `relation`, if a set keeps it.
    pub fn definition(&self, relation: &str) -> Option<&str> {
        self.sets
            .values()
            .find(|set| set.kept.as_deref() == Ok(relation))
            .and_then(|set| set.definition.as_deref())
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
            Refinement::Filter { column: index, value, guard } => {
                let column = column(*index)?;
                let var = column.var.as_ref().ok_or_else(|| {
                    format!("{} is a constant of the query: every row has the same value", column.name)
                })?;
                let guard = guard.as_deref().unwrap_or("=");
                if !GUARDS.contains(&guard) {
                    return Err(format!("{guard} is not a guard; the guards are {}", GUARDS.join(" ")));
                }
                if value.trim().is_empty() {
                    return Err(format!("{} {guard} what?", column.name));
                }
                let mut query = parsed()?.clone();
                query.clauses.push(format!("({guard} {var} {})", value.trim()));
                (query.text(), format!("{} {guard} {}", column.name, value.trim()))
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
            Refinement::Sort { .. } => return Err("a sort orders rows; it runs no query".to_owned()),
        };
        Ok((line, Lineage { parent: id, refinement: label }))
    }

    /// The name of `id`'s `column` and the lineage label of sorting by it,
    /// before any row is read.
    pub fn sorting(&self, id: SetId, column: usize, descending: bool) -> Result<Lineage, String> {
        let set = self.sets.get(&id).ok_or_else(|| format!("{id} is no longer kept"))?;
        let name = match set.columns.get(column) {
            Some(column) => column.name.clone(),
            None if set.columns.is_empty() => (column + 1).to_string(),
            None => return Err(format!("{id} has no column {}", column + 1)),
        };
        let order = if descending { "descending" } else { "ascending" };
        Ok(Lineage { parent: id, refinement: format!("sort by {name}, {order}") })
    }

    /// Open a set of `rows`, all of `lineage.parent`'s rows, sorted by
    /// `column`. It shows the parent's query, and its rows are the parent's
    /// relation's; they are held in the cache, as the one page of a set no
    /// query can read again.
    pub fn sorted(
        &mut self,
        lineage: Lineage,
        column: usize,
        descending: bool,
        mut rows: Vec<Row>,
    ) -> Result<SetId, String> {
        let parent = self
            .sets
            .get(&lineage.parent)
            .ok_or_else(|| format!("{} is no longer kept", lineage.parent))?;
        sort_rows(&mut rows, column, descending);
        let n = rows.len() as u64;
        let set = Set {
            query: parent.query.clone(),
            read: parent.read.clone(),
            parsed: parent.parsed.clone(),
            columns: parent.columns.clone(),
            duplicates: parent.duplicates,
            total: if parent.budget { Total::AtLeast(n) } else { Total::Exact(n) },
            cursor: Cursor::Exhausted,
            budget: parent.budget,
            at: n,
            seen: n,
            pages: BTreeMap::new(),
            epoch: parent.epoch,
            loading: None,
            parent: Some(lineage),
            kept: parent.kept.clone(),
            definition: parent.definition.clone(),
            sorted: Some(Order { column, descending }),
            state: parent.state,
            revision: 0,
        };
        let id = self.reserve();
        self.sets.insert(id, set);
        while self.sets.len() > MAX_SETS {
            let oldest = *self.sets.keys().next().expect("more than MAX_SETS sets");
            self.forget(oldest);
        }
        if n > 0 {
            self.clock += 1;
            let set = self.sets.get_mut(&id).expect("just opened");
            set.pages.insert(0, Page { rows, used: self.clock });
            self.cached += n as usize;
            self.evict();
        }
        Ok(id)
    }

    pub fn view(&self, id: SetId) -> Option<View> {
        let set = self.sets.get(&id)?;
        Some(View {
            id,
            query: set.query.clone(),
            columns: set.columns.clone(),
            total: set.total,
            cursor: set.cursor,
            budget: set.budget,
            seen: set.seen,
            duplicates: set.duplicates,
            stale: set.epoch != self.epoch,
            revision: set.revision,
            loading: set.loading.clone(),
            parent: set.parent.clone(),
            relation: set.kept.as_ref().ok().cloned(),
            unkept: set.kept.as_ref().err().filter(|why| !why.is_empty()).cloned(),
            sorted: set.sorted,
            state: set.state,
        })
    }

    /// Drop `id`'s cached rows, as the cache's bound would.
    #[cfg(test)]
    fn forget_rows(&mut self, id: SetId) {
        let set = self.sets.get_mut(&id).expect("a kept set");
        self.cached -= set.pages.values().map(|page| page.rows.len()).sum::<usize>();
        set.pages.clear();
    }

    pub fn views(&self) -> Vec<View> {
        self.sets.keys().filter_map(|id| self.view(*id)).collect()
    }

    /// What is kept of the sets across a restart: each bound to a state,
    /// and not sorted here, without its rows, which are read again at its
    /// state.
    pub fn record(&self) -> Record {
        let sets = self
            .sets
            .iter()
            .filter(|(_, set)| set.state.is_some() && set.sorted.is_none())
            .map(|(id, set)| SetRecord {
                id: *id,
                query: set.query.clone(),
                read: set.read.clone(),
                columns: set.columns.clone(),
                duplicates: set.duplicates,
                total: set.total,
                complete: set.cursor == Cursor::Exhausted,
                budget: set.budget,
                seen: set.seen,
                parent: set.parent.clone(),
                kept: set.kept.clone(),
                definition: set.definition.clone(),
                state: set.state,
            })
            .collect();
        Record { next: self.next, sets }
    }

    /// The sets of `record`, each of a past state: none is the main lane's.
    pub fn restore(record: Record) -> Self {
        let mut results = Results {
            next: record.next,
            ..Results::default()
        };
        for kept in record.sets {
            let set = Set {
                parsed: Query::parse(&kept.read),
                query: kept.query,
                read: kept.read,
                columns: kept.columns,
                duplicates: kept.duplicates,
                total: kept.total,
                cursor: if kept.complete { Cursor::Exhausted } else { Cursor::Parked },
                budget: kept.budget,
                at: 0,
                seen: kept.seen,
                pages: BTreeMap::new(),
                epoch: u64::MAX,
                loading: None,
                parent: kept.parent,
                kept: kept.kept,
                definition: kept.definition,
                sorted: None,
                state: kept.state,
                revision: 0,
            };
            results.sets.insert(kept.id, set);
        }
        results
    }
}

/// The sets kept across a restart (`Results::record`).
#[derive(Debug, Default, Serialize, Deserialize)]
pub struct Record {
    next: u32,
    sets: Vec<SetRecord>,
}

#[derive(Debug, Serialize, Deserialize)]
struct SetRecord {
    id: SetId,
    query: String,
    read: String,
    columns: Vec<Column>,
    duplicates: bool,
    total: Total,
    complete: bool,
    budget: bool,
    seen: u64,
    parent: Option<Lineage>,
    kept: Result<String, String>,
    definition: Option<String>,
    state: Option<Stamp>,
}

/// Sort rows by one column's values, stably: numbers by value, before
/// everything else, which sorts by its printed text (strings, symbols, and
/// compound values by their constructor first).
pub fn sort_rows(rows: &mut [Row], column: usize, descending: bool) {
    fn text(row: &Row, column: usize) -> &str {
        row.get(column).map_or("", |cell| cell.text.as_str())
    }
    // not `inf` or `nan`, which are symbols
    let number = |row: &Row| {
        let text = text(row, column);
        let numeral = text
            .trim_start_matches(['+', '-'])
            .starts_with(|c: char| c.is_ascii_digit() || c == '.');
        text.parse::<f64>().ok().filter(|_| numeral)
    };
    rows.sort_by(|a, b| {
        let order = match (number(a), number(b)) {
            (Some(x), Some(y)) => x.total_cmp(&y),
            (Some(_), None) => std::cmp::Ordering::Less,
            (None, Some(_)) => std::cmp::Ordering::Greater,
            (None, None) => text(a, column).cmp(text(b, column)),
        };
        if descending { order.reverse() } else { order }
    });
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

#[derive(Clone, Copy, Debug, Eq, PartialEq)]
pub enum Status {
    /// Rows remain: the cursor is open.
    Open,
    Complete,
    /// The work budget ended the query.
    Budget,
}

/// A rows page's rows, as cells, and how the query stands after it: for
/// reads apart from any set (peek.rs).
pub fn page_rows(result: &Value) -> Result<(Vec<Row>, Status), String> {
    let page = parse_page(result)?;
    let fact = projection_of(result["title"].as_str().unwrap_or("")).is_none();
    Ok((page.tuples.iter().map(|tuple| row(tuple, fact)).collect(), page.status))
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

    /// Whether a variable of the atoms is not shown, or `_` matches
    /// anything: rows then repeat once per hidden binding (audit Q-02).
    fn hides_variables(&self, shown: &[String]) -> bool {
        self.atoms().iter().flat_map(|(_, terms)| terms).any(|term| {
            *term == "_" || (is_variable(term) && !shown.iter().any(|var| var == term))
        })
    }
}

/// `line` as sent to the session: a query names the set it makes `id`, or,
/// with none, makes no set (`as _`); a query already naming one, and any
/// other line, as typed.
pub fn naming(line: &str, id: Option<SetId>) -> String {
    let line = line.trim();
    let named = line.rsplit_once(" as ").is_some_and(|(_, name)| {
        let name = name.trim();
        name == "_" || SetId::try_from(name.to_owned()).is_ok()
    });
    if !line.starts_with('?') || line == "?" || named {
        return line.to_owned();
    }
    match id {
        Some(id) => format!("{line} as {id}"),
        None => format!("{line} as _"),
    }
}

/// The rows form of a `?` or `?exists` line, which a set reads: `?exists
/// BODY` asks whether `? BODY` has rows. None for `?count` and other lines.
pub fn rows_line(line: &str) -> Option<String> {
    let body = line.trim().strip_prefix('?')?;
    if let Some(rest) = body
        .strip_prefix("exists")
        .filter(|rest| !rest.starts_with(|c: char| c.is_alphanumeric()))
    {
        return Some(format!("? {}", rest.trim()));
    }
    Query::parse(line).map(|_| line.trim().to_owned())
}

/// The `?count` of a rows query, which totals the set it opens; None for
/// any other line.
pub fn count_line(line: &str) -> Option<String> {
    Query::parse(line)?;
    let body = line.trim().strip_prefix('?')?;
    Some(format!("?count {body}"))
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
    use super::{CACHE_ROWS, Cell, Cursor, Opening, Plan, Refinement, Results, Row, SetId, Total, columns_of, naming, row, sort_rows};
    use crate::states::Stamp;
    use serde_json::{Value, json};

    /// A rows page as compiler/repl.rkt's render-query-page prints it.
    fn page(title: &str, start: u64, tuples: &[String], status: &str) -> Value {
        let shown = start + tuples.len() as u64;
        let mut lines = vec![format!("rows {}–{shown}", start + 1)];
        lines.extend(tuples.iter().enumerate().map(|(i, t)| format!("{}  {t}", start + i as u64 + 1)));
        json!({"kind": "query", "title": title, "lines": lines, "query-mode": "rows",
               "query-status": status, "query-matched": shown, "query-shown": shown})
    }

    /// Set `rN` reading `line` itself, its answers not kept as a relation,
    /// its columns as the server names them: `X`, a variable's; `edge.1`,
    /// a constant's; `edge.2:Y`, a fact's column holding variable Y.
    fn as_typed(n: u32, line: &str, columns: &[&str]) -> Opening {
        let columns = columns
            .iter()
            .map(|column| {
                let (name, var) = column.split_once(':').unwrap_or((column, column));
                super::Column { name: name.to_owned(), var: (!var.contains('.')).then(|| var.to_owned()), kind: None }
            })
            .collect();
        Opening {
            id: SetId(n),
            query: line.to_owned(),
            read: line.to_owned(),
            columns,
            kept: Err(String::new()),
            parent: None,
            state: None,
        }
    }

    fn texts(rows: &[Row]) -> Vec<Vec<&str>> {
        rows.iter().map(|row| row.iter().map(|cell| cell.text.as_str()).collect()).collect()
    }

    /// Answers as a session on reach.slog gives them: a one-atom query and a
    /// projected join, each a set, named and counted, its columns typed by
    /// the server.
    #[test]
    fn captured_pages_read_as_typed_columns_and_cells() {
        let fact = json!({"kind": "query", "lines": ["r1 · 3 rows", "1  (path 1 2)", "2  (path 1 3)", "3  (path 1 4)"],
            "query-matched": 3, "query-mode": "rows", "query-shown": 3, "query-status": "complete", "title": "Query",
            "set": {"name": "r1", "count": 3, "exact": true},
            "columns": [{"name": "path.1", "var": null, "type": "int"}, {"name": "path.2", "var": "Y", "type": "int"}]});
        let join = json!({"kind": "query", "lines": ["r2 · 2 rows", "1  (2 4)", "2  (1 3)"], "query-matched": 2,
            "query-mode": "rows", "query-shown": 2, "query-status": "complete", "title": "Query · (X Z)",
            "set": {"name": "r2", "count": 2, "exact": true},
            "columns": [{"name": "X", "var": "X", "type": "int"}, {"name": "Z", "var": "Z", "type": "int"}]});
        let mut results = Results::default();
        let typed = |n, line: &str, answer: &serde_json::Value| Opening { columns: columns_of(answer), ..as_typed(n, line, &[]) };

        let id = results.open(typed(1, "?(path 1 Y)", &fact), &fact).unwrap().unwrap();
        let view = results.view(id).unwrap();
        let columns: Vec<_> = view.columns.iter().map(|c| (c.name.as_str(), c.var.as_deref(), c.kind.as_deref())).collect();
        assert_eq!(columns, [("path.1", None, Some("int")), ("path.2", Some("Y"), Some("int"))]);
        assert_eq!((view.total, view.cursor, view.duplicates), (Total::Exact(3), Cursor::Exhausted, false));
        let Plan::Serve(rows) = results.plan(id, 0, 10) else { panic!("the page is cached") };
        assert_eq!(texts(&rows), [["1", "2"], ["1", "3"], ["1", "4"]]);

        let id = results.open(typed(2, "? (edge X Y) (edge Y Z) -> (X Z)", &join), &join).unwrap().unwrap();
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

    /// A count the budget cut short is a lower bound, whatever the rows
    /// read so far; only a complete count or reading every row is exact.
    #[test]
    fn a_total_is_exact_only_when_nothing_cut_it_short() {
        let count = |line: &str, n: u64| json!({"query-mode": "count", "query-matched": n, "lines": [line]});
        assert_eq!(Total::of_count(&count("6 rows", 6)), Some(Total::Exact(6)));
        assert_eq!(Total::of_count(&count("2157385+ rows", 2157385)), Some(Total::AtLeast(2157385)));

        let tuples = |range: std::ops::Range<u64>| range.map(|i| format!("({i})")).collect::<Vec<_>>();
        let mut results = Results::default();
        let mut first = page("Query · (X)", 0, &tuples(0..50), "open");
        first["set"] = json!({"name": "r1", "count": 70, "exact": false});
        let id = results.open(as_typed(1, "?(n X)", &["X"]), &first).unwrap().unwrap();
        assert_eq!(results.view(id).unwrap().total, Total::AtLeast(70));
        // the work budget stops the rows at 80: still only a lower bound
        results.absorb(id, &page("Query · (X)", 50, &tuples(50..80), "budget")).unwrap();
        let view = results.view(id).unwrap();
        assert_eq!((view.total, view.budget, view.cursor), (Total::AtLeast(80), true, Cursor::Exhausted));
    }

    /// After a committed change the session re-counts its live sets; each
    /// it names is current again at the new state, at its new size, its
    /// cached rows dropped to be read again. A set it does not name goes
    /// stale, keeping its rows.
    #[test]
    fn a_settled_set_is_current_again_and_reads_its_rows_again() {
        let tuples = |range: std::ops::Range<u64>| range.map(|i| format!("({i})")).collect::<Vec<_>>();
        let mut results = Results::default();
        let live = results.open(as_typed(1, "?(n X)", &["X"]), &page("Query · (X)", 0, &tuples(0..3), "complete")).unwrap().unwrap();
        let other = results.open(as_typed(2, "?(m X)", &["X"]), &page("Query · (X)", 0, &tuples(0..2), "complete")).unwrap().unwrap();
        results.changed();
        let state = Stamp { id: 4, pred: Some(3) };
        let records = json!([{"name": "r1", "before": 3, "after": 5, "exact": true, "stale": null},
                             {"name": "r9", "before": 1, "after": 2, "exact": true, "stale": null}]);
        assert_eq!(results.settled(&records, state), [live]);
        let view = results.view(live).unwrap();
        assert_eq!((view.total, view.stale, view.revision, view.state), (Total::Exact(5), false, 1, Some(state)));
        assert!(matches!(results.plan(live, 0, 5), Plan::Rerun(query) if query == "?(n X)"));
        let view = results.view(other).unwrap();
        assert!(view.stale);
        assert!(matches!(results.plan(other, 0, 2), Plan::Serve(rows) if rows.len() == 2));
    }

    /// A query names the set it makes; a read of Studio's own makes none.
    #[test]
    fn a_query_is_sent_naming_its_set() {
        assert_eq!(naming("?(path X Y)", Some(SetId(3))), "?(path X Y) as r3");
        assert_eq!(naming(" ?count (path X _) ", None), "?count (path X _) as _");
        assert_eq!(naming("?(path X Y) as r7", Some(SetId(3))), "?(path X Y) as r7");
        assert_eq!(naming("? (label X \"a as b\")", None), "? (label X \"a as b\") as _");
        assert_eq!(naming("tables", Some(SetId(3))), "tables");
        assert_eq!(naming("?", None), "?");
    }

    #[test]
    fn refinements_are_queries_over_the_columns_variables() {
        let fact = page("Query", 0, &["(path 1 2)".to_owned()], "complete");
        let join = page("Query · (X Z)", 0, &["(1 3)".to_owned()], "complete");
        let mut results = Results::default();
        let sugar = results.open(as_typed(1, "?(path 1 Y)", &["path.1", "path.2:Y"]), &fact).unwrap().unwrap();
        let projected = results
            .open(as_typed(2, "? (path X Y) ~(edge X Y) (edge Y Z) -> (X Z)", &["X", "Z"]), &join)
            .unwrap()
            .unwrap();
        let refine = |id: SetId, refinement: Refinement| {
            results.refine(id, &refinement).map(|(line, lineage)| (line, lineage.refinement))
        };
        let filter = |column, value: &str| Refinement::Filter { column, value: value.to_owned(), guard: None };
        let guarded = |guard: &str, value: &str| Refinement::Filter {
            column: 1,
            value: value.to_owned(),
            guard: Some(guard.to_owned()),
        };

        assert_eq!(refine(sugar, filter(1, "2")).unwrap(), ("? (path 1 Y) (= Y 2)".to_owned(), "path.2 = 2".to_owned()));
        assert!(refine(sugar, filter(0, "1")).unwrap_err().contains("constant"));
        // a column's filter is any of the query's guards
        assert_eq!(refine(sugar, guarded(">=", " 10 ")).unwrap(), ("? (path 1 Y) (>= Y 10)".to_owned(), "path.2 >= 10".to_owned()));
        assert_eq!(refine(sugar, guarded("/=", "\"a b\"")).unwrap().0, "? (path 1 Y) (/= Y \"a b\")");
        assert!(refine(sugar, guarded("like", "3")).unwrap_err().contains("not a guard"));
        assert!(refine(sugar, guarded("<", "")).is_err());
        assert!(refine(sugar, Refinement::Sort { column: 1, descending: false }).is_err());
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

    /// Studio sorts a set's rows itself: numbers by value and first, then
    /// the rest by their text, stably; the sorted set holds every row, and
    /// cannot read them again.
    #[test]
    fn a_sorted_set_holds_its_rows_in_order() {
        let cells = |texts: &[&str]| texts.iter().map(|t| Cell { text: (*t).to_owned(), handle: None }).collect::<Row>();
        let mut rows: Vec<Row> = [["b", "10"], ["a", "9"], ["c", "\"x\""], ["d", "-2.5"], ["e", "9"]]
            .iter()
            .map(|row| cells(row))
            .collect();
        sort_rows(&mut rows, 1, false);
        assert_eq!(texts(&rows).iter().map(|row| row[0]).collect::<String>(), "daebc");
        sort_rows(&mut rows, 1, true);
        assert_eq!(texts(&rows).iter().map(|row| row[1]).collect::<Vec<_>>(), ["\"x\"", "10", "9", "9", "-2.5"]);

        let tuples: Vec<String> = (0..120).map(|i| format!("({i} {})", 1000 - i)).collect();
        let mut results = Results::default();
        let parent = results.open(as_typed(1, "?(n X Y)", &["X", "Y"]), &page("Query · (X Y)", 0, &tuples[..50], "complete")).unwrap().unwrap();
        let Plan::Serve(rows) = results.plan(parent, 0, 50) else { panic!("cached") };
        let lineage = results.sorting(parent, 1, false).unwrap();
        assert_eq!(lineage.refinement, "sort by Y, ascending");
        assert!(results.sorting(parent, 2, false).is_err());
        let id = results.sorted(lineage, 1, false, rows).unwrap();
        let view = results.view(id).unwrap();
        assert_eq!((view.total, view.cursor, view.seen), (Total::Exact(50), Cursor::Exhausted, 50));
        assert_eq!(view.parent.map(|lineage| lineage.parent), Some(parent));
        let Plan::Serve(rows) = results.plan(id, 0, 3) else { panic!("cached") };
        assert_eq!(texts(&rows), [["49", "951"], ["48", "952"], ["47", "953"]]);
        // rows past the end are none, as for any exhausted set
        assert_eq!(results.plan(id, 50, 60), Plan::Serve(vec![]));
        results.forget_rows(id);
        assert!(matches!(results.plan(id, 0, 1), Plan::Fail(why) if why.contains("sort r1 again")));
    }

    /// Pages beyond the cache's bound are dropped least recently used
    /// first; a dropped row is read again by running the query.
    #[test]
    fn the_cache_is_bounded_and_dropped_rows_are_read_again() {
        let tuples = |start: u64| (start..start + 50).map(|i| format!("({i})")).collect::<Vec<_>>();
        let mut results = Results::default();
        let id = results.open(as_typed(1, "?(n X)", &["X"]), &page("Query · (X)", 0, &tuples(0), "open")).unwrap().unwrap();
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
    use super::{Cursor, Order, Refinement, Row, SetId, Total, View};
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

        /// Run a REPL line; the answer its transcript entry shows, and the
        /// set it opened.
        async fn entry(&self, line: &str) -> (serde_json::Value, Option<SetId>) {
            let mut events = self.studio.subscribe();
            self.studio.command(line).await;
            std::iter::from_fn(|| events.try_recv().ok())
                .find_map(|event| match event {
                    Event::Entry { set, outcome, .. } => Some((outcome.result.expect("an answer"), set)),
                    _ => None,
                })
                .expect("an entry")
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

        let filtered = refine(Refinement::Filter { column: 0, value: x.clone(), guard: None }).await;
        assert_eq!(filtered.parent.as_ref().map(|lineage| lineage.parent), Some(path));
        let x: u64 = x.parse().unwrap();
        let expected: BTreeSet<(u64, u64)> = closure().into_iter().filter(|&(from, _)| from == x).collect();
        assert_eq!(filtered.total, Total::Exact(expected.len() as u64));
        let read = pairs(&fixture.all_rows(filtered.id).await);
        assert_eq!(read.into_iter().collect::<BTreeSet<_>>(), expected);

        // a `?` projection keeps one row per hidden binding (audit Q-02);
        // the relation it is kept as holds each row once
        let dropped = refine(Refinement::Drop { column: 1 }).await;
        assert_eq!(dropped.query, "? (r1 X Y) -> (X)");
        assert!(!dropped.duplicates);
        let firsts: Vec<u64> = fixture.all_rows(dropped.id).await.iter().map(|row| row[0].text.parse().unwrap()).collect();
        assert_eq!(firsts.into_iter().collect::<BTreeSet<_>>(), (1..N).collect());
        assert_eq!(dropped.total, Total::Exact(N - 1));

        // a column's filter, as a guard
        let guard = Some(">".to_owned());
        let guarded = refine(Refinement::Filter { column: 1, value: "15".to_owned(), guard }).await;
        let expected: BTreeSet<(u64, u64)> = closure().into_iter().filter(|&(_, y)| y > 15).collect();
        assert_eq!(pairs(&fixture.all_rows(guarded.id).await).into_iter().collect::<BTreeSet<_>>(), expected);

        // a sort is Studio's, over every row: a new set, in order
        fixture.studio.sort(path, 1, true).await.expect("sorted");
        let sorted = fixture.views().await.pop().expect("the sort opened a set");
        assert_eq!(sorted.sorted, Some(Order { column: 1, descending: true }));
        assert_eq!(sorted.parent.map(|lineage| lineage.parent), Some(path));
        assert_eq!(sorted.total, Total::Exact(closure().len() as u64));
        let read = pairs(&fixture.all_rows(sorted.id).await);
        assert!(read.windows(2).all(|pair| pair[0].1 >= pair[1].1), "not in order");
        assert_eq!(read.len(), closure().len());
        assert_eq!(read.into_iter().collect::<BTreeSet<_>>(), closure());
        fixture.finish().await;
    }

    /// A query's answers become a relation named for its set, which later
    /// queries read; an existence question answers with its witnesses, a
    /// ground one with its fact, never a bare yes or no; answers that
    /// cannot be kept are read as typed.
    #[tokio::test]
    async fn answers_are_kept_as_relations_named_for_their_sets() {
        let fixture = Fixture::new("kept").await;
        let path = fixture.query("?(path X Y)").await;
        let view = fixture.view(path).await;
        assert_eq!((view.relation.as_deref(), view.unkept), (Some("r1"), None));
        // the relation is a relation like any other
        let next = fixture.query("? (r1 X Y) (edge Y Z) -> (X Z)").await;
        let expected: BTreeSet<(u64, u64)> = closure().into_iter().filter(|&(_, y)| y < N).map(|(x, y)| (x, y + 1)).collect();
        assert_eq!(pairs(&fixture.all_rows(next).await).into_iter().collect::<BTreeSet<_>>(), expected);
        assert_eq!(fixture.view(next).await.relation.as_deref(), Some("r2"));

        let (answer, set) = fixture.entry("?(edge 1 2)").await;
        assert_eq!(answer["lines"][0], "r3 · 1 row");
        let rows = fixture.studio.rows(set.expect("a set"), 0, 10).await.unwrap();
        assert_eq!(pairs(&rows), [(1, 2)]);
        let (answer, set) = fixture.entry("?(edge 2 1)").await;
        assert_eq!(answer["lines"][0], "r4 · no rows");
        assert_eq!(fixture.view(set.expect("a set")).await.total, Total::Exact(0));
        let (answer, set) = fixture.entry("?exists (path 3 Y)").await;
        assert_eq!(answer["lines"][0], format!("r5 · {} rows", N - 3));
        let rows = fixture.studio.rows(set.expect("a set"), 0, 100).await.unwrap();
        let from_3: BTreeSet<(u64, u64)> = closure().into_iter().filter(|&(x, _)| x == 3).collect();
        assert_eq!(pairs(&rows).into_iter().collect::<BTreeSet<_>>(), from_3);

        // a handle splices into a query, never into a rule
        let at = fixture.query("?(at X P)").await;
        let handle = fixture.studio.rows(at, 0, 1).await.unwrap()[0][1].handle.clone().expect("a handle");
        let unkept = fixture.query(&format!("? (at X P) (= P {handle})")).await;
        let view = fixture.view(unkept).await;
        assert_eq!(view.relation, None);
        assert!(view.unkept.is_some());
        assert_eq!(fixture.studio.rows(unkept, 0, 10).await.unwrap().len(), 1);

        // a nested pattern reads through a scratch rule, kept from the start
        let nested = fixture.query("?(at X (pt 1 2))").await;
        assert_eq!(fixture.view(nested).await.relation, Some(nested.to_string()));
        let row = &fixture.studio.rows(nested, 0, 10).await.unwrap()[0];
        assert_eq!((row[0].text.as_str(), row[1].text.as_str()), ("1", "(pt 1 2)"));
        fixture.finish().await;
    }

    /// A set is watched for the session: a committed change re-counts it
    /// in the session, and the studio's set is current again, at the new
    /// state and size, its rows read again. A count is a set too, of the
    /// query's matches. A fresh Run leaves the sets of the old session
    /// stale, their rows and sizes as they were.
    #[tokio::test]
    async fn a_set_follows_the_sessions_changes() {
        let fixture = Fixture::new("live").await;
        let from_1 = fixture.query("?(path 1 Y)").await;
        assert_eq!(fixture.view(from_1).await.total, Total::Exact(N - 1));
        assert_eq!(fixture.studio.rows(from_1, 0, 100).await.unwrap().len() as u64, N - 1);
        let (answer, count) = fixture.entry("?count (path X _)").await;
        assert_eq!(answer["lines"][0], format!("r2 · {} rows", closure().len()));
        let count = count.expect("a count is a set");
        assert_eq!(fixture.view(count).await.relation, None);

        let before = fixture.view(from_1).await;
        let (answer, _) = fixture.entry(&format!("add edge {N} {}", N + 1)).await;
        let said: Vec<&str> = answer["brief-lines"].as_array().unwrap().iter().filter_map(|line| line.as_str()).collect();
        assert!(said.contains(&"r1: +1 row (now 21)"), "{said:?}");
        let view = fixture.view(from_1).await;
        assert_eq!((view.total, view.stale, view.revision), (Total::Exact(N), false, before.revision + 1));
        assert_ne!(view.state.map(|state| state.id), before.state.map(|state| state.id));
        let ends: BTreeSet<u64> = fixture.all_rows(from_1).await.iter().map(|row| row[1].text.parse().unwrap()).collect();
        assert_eq!(ends, (2..=N + 1).collect());
        assert_eq!(fixture.view(count).await.total, Total::Exact(closure().len() as u64 + N));

        fixture.studio.evaluate().await;
        let view = fixture.view(from_1).await;
        assert!(view.stale);
        assert_eq!(view.total, Total::Exact(N));
        fixture.finish().await;
    }
}
