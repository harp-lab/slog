// Result sets (studio/src/results.rs): a tab per `?` query, each shown in
// the result table (table.js), which renders only the rows in view and asks
// for rows as they scroll into it. The studio pages them from the session
// server; this module never holds more than a window of them.
//
// It runs in two places: over the transcript under the REPL, compact, with
// buttons to expand the set over the page or pop it out; and as a set's own
// window (results-page.js), `full`. Both are clients of the same studio, so
// sets, their rows and refinements are the same in each; what one view of a
// set does besides (scrolling, the cursor, column layout, a sort of its
// cached rows) it tells the other over a BroadcastChannel.

import { isPast, onStates, stamped, stateName, states } from "./stamp.js";
import { createTable, filterRefinement, openMenu, renderTree, sortedOrder, toCSV, toFacts, toTSV, treeOf } from "./table.js";

const REQUEST = 200; // rows asked for at once while scrolling
const BULK = 1000; // rows asked for at once to copy or export (MAX_REQUEST_ROWS)
// Rows the table extends past those read so far. Reaching row N reads every
// row before it on the main lane, which nothing else can use meanwhile, so
// the scrollbar never offers all of a huge set at once.
const AHEAD = 2000;
const KEEP = 4000; // rows kept per set; farther ones are asked for again
const NUMBER = /^[-+]?\.?\d/;

const element = (tag, className, text) => {
  const node = document.createElement(tag);
  if (className) node.className = className;
  if (text !== undefined) node.textContent = text;
  return node;
};
const number = (n) => n.toLocaleString("en-US");

// The launch token and project, to open a set's window on the same studio.
const token = location.hash.slice(1);
const project = new URLSearchParams(location.search).get("project") ?? "";

// `tabs` holds the tab strip, `panel` the set shown; `transcript`, if
// given, is what the Transcript tab shows. `send` writes to the studio;
// `run` runs a REPL line.
export function createResults({ tabs, panel, transcript, send, run, full = false }) {
  // id -> { view, rows: Map(index -> row), pending, error, state, order, busy }
  // `state` is the table's (scroll, layout, sort, cursor, selection), and
  // `order` the rows' order when they are sorted here.
  const sets = new Map();
  const closed = new Set();
  let shown = null;
  let popup = null;
  const channel = globalThis.BroadcastChannel ? new BroadcastChannel(`slog-results:${project}`) : null;

  const transcriptTab = transcript && tabs.appendChild(element("button", "rs-tab", "Transcript"));
  transcriptTab?.addEventListener("click", () => show(null));

  // One panel, filled with whichever set is shown.
  panel.classList.add("rs-panel");
  panel.classList.toggle("rs-full", full);
  const bar = panel.appendChild(element("div", "rs-bar"));
  const lineage = bar.appendChild(element("div", "rs-lineage"));
  const query = bar.appendChild(element("input", "rs-query"));
  query.spellcheck = false;
  query.title = "The set's query. Edit it and press Enter to run it as a new set.";
  const buttons = bar.appendChild(element("div", "rs-buttons"));
  const button = (label, title, act) => {
    const node = buttons.appendChild(element("button", "secondary small", label));
    node.title = title;
    node.addEventListener("click", act);
    return node;
  };
  button("Export ▾", "Copy the selected rows, or download the whole set", (event) => openMenu(event, [
    ["Copy selection as TSV", () => copySelection("tsv")],
    ["Copy selection as CSV", () => copySelection("csv")],
    ["Copy selection as Slog facts", () => copySelection("facts")],
    ["Download the set as CSV", download],
  ]));
  // A set of a past state reads there; this runs its query at the session's.
  const nowButton = button("Show now", "Run the query again at the session's current state, as a new set",
    () => shown && send({ t: "show-now", set: shown }));
  const expandButton = full ? null : button("Expand", "Show the set over the whole page", () => expand(!expanded));
  if (!full) button("Pop out ⧉", "Open the set in a window of its own, beside the studio", popOut);
  const status = panel.appendChild(element("div", "rs-status"));
  // What a gesture did, or why it could not, for a few seconds.
  const flash = element("span", "rs-flash");
  let flashTimer = 0;
  const note = (message) => {
    flash.textContent = message;
    clearTimeout(flashTimer);
    flashTimer = setTimeout(() => { flash.textContent = ""; flash.remove(); }, 6000);
    status.append(flash);
  };
  const main = panel.appendChild(element("div", "rs-main"));
  const grid = main.appendChild(element("div", "rs-grid"));
  const detail = main.appendChild(element("div", "rs-detail"));
  detail.hidden = true;
  let expanded = false;

  const current = () => sets.get(shown);
  const table = createTable(grid, {
    compact: !full,
    source: {
      count: () => (current() ? extent(current().view) : 0),
      row: (i) => current()?.rows.get(indexOf(current(), i)),
      label: (i) => number(indexOf(current(), i) + 1),
      want(first, last) {
        const set = current();
        if (set && !set.order) request(set, first, last);
        if (set) renderStatus(set);
      },
    },
    on: {
      select: () => renderDetail(current()),
      open: () => { detail.hidden = false; renderDetail(current()); },
      sort: (column, descending) => sortBy(column, descending),
      filter(column, typed) {
        const set = current();
        const refinement = filterRefinement(column, typed, set.view.columns[column]?.type);
        if (refinement) send({ t: "refine", set: set.view.id, refinement });
      },
      copy: () => copySelection("tsv"),
      menu: (column) => {
        const set = current();
        return set.view.columns.length > 1
          ? [["Drop column (a new set)", () => send({ t: "refine", set: set.view.id, refinement: { op: "drop", column } })]]
          : [];
      },
      change(state) {
        const set = current();
        if (!set) return;
        set.state = state;
        renderStatus(set);
        channel?.postMessage({ set: set.view.id, state });
      },
    },
  });

  query.addEventListener("keydown", (event) => {
    if (event.key !== "Enter" || shown === null) return;
    event.preventDefault();
    send({ t: "refine", set: shown, refinement: { op: "edit", line: query.value } });
  });
  // Escape collapses an expanded set, once the table has nothing selected.
  panel.addEventListener("keydown", (event) => {
    if (event.key === "Escape" && expanded && !event.defaultPrevented) expand(false);
  });

  // ---- the twin view --------------------------------------------------

  if (channel) {
    channel.onmessage = ({ data }) => {
      if (data.hello) {
        // a window opening asks how each set was left
        const states = [...sets].filter(([, set]) => set.state).map(([id, set]) => [id, set.state]);
        channel.postMessage({ states, shown });
      } else if (data.states && full) {
        for (const [id, state] of data.states) mirror(id, state);
      } else if (data.show && full) {
        show(data.show);
      } else if (data.set) {
        mirror(data.set, data.state);
      }
    };
  }

  function mirror(id, state) {
    const set = sets.get(id);
    if (!set) return;
    const sorted = JSON.stringify(state.sort) !== JSON.stringify(set.state?.sort);
    set.state = state;
    if (sorted && !set.view.sorted) sortHere(set, state.sort, false);
    if (id === shown) {
      table.restore(state);
      renderStatus(set);
      renderDetail(set);
    }
  }

  // ---- views of the set -----------------------------------------------

  function show(id) {
    shown = sets.has(id) ? id : full ? sets.keys().next().value ?? null : null;
    if (transcript) transcript.hidden = shown !== null;
    panel.hidden = shown === null && Boolean(transcript);
    renderTabs();
    if (full) history.replaceState(null, "", `?${new URLSearchParams({ project, set: shown ?? "" })}${location.hash}`);
    if (full) document.title = shown ? `${shown} · Slog results` : "Slog results";
    if (shown === null) {
      if (expanded) expand(false);
      return;
    }
    const set = current();
    query.value = set.view.query;
    renderLineage(set);
    // columns are measured once there are rows to measure
    table.setColumns(columnsOf(set), set.measured ? set.state?.layout : null);
    set.measured = set.rows.size > 0;
    const state = set.state ?? { top: 0 };
    table.restore({ ...state, sort: set.view.sorted ?? state.sort ?? null });
    set.state = table.state();
    renderStatus(set);
    renderDetail(set);
  }

  function expand(on) {
    expanded = on;
    panel.classList.toggle("rs-expanded", on);
    expandButton.textContent = on ? "Collapse" : "Expand";
    table.setCompact(!on);
  }

  // A window of its own, or, where popups are blocked, the page.
  function popOut() {
    if (popup && !popup.closed) {
      channel?.postMessage({ show: shown });
      popup.focus();
      return;
    }
    const url = `/results?${new URLSearchParams({ project, set: shown ?? "" })}#${token}`;
    popup = window.open(url, `slog-results-${project}`, "popup,width=1280,height=820");
    if (!popup) {
      expand(true);
      note("This browser blocked the window, so the set is expanded over the page instead.");
    }
  }

  function update(view) {
    if (closed.has(view.id)) return;
    const set = sets.get(view.id);
    if (!set) {
      sets.set(view.id, { view, rows: new Map(), pending: null, error: null, state: null, order: null });
      renderTabs();
      if (full && shown === null) show(view.id);
      return;
    }
    const columnsChanged = JSON.stringify(set.view.columns) !== JSON.stringify(view.columns);
    set.view = view;
    renderTabs();
    if (view.id !== shown) return;
    if (columnsChanged) table.setColumns(columnsOf(set), null);
    if (document.activeElement !== query) query.value = view.query;
    renderStatus(set);
    table.refresh();
  }

  // Rows arrived: those the table asked for, or a range read whole.
  const waiting = new Map(); // `${set}:${start}` -> resolve
  function receive(reply) {
    const { set: id, start, rows, error } = reply;
    waiting.get(`${id}:${start}`)?.(reply);
    waiting.delete(`${id}:${start}`);
    const set = sets.get(id);
    if (!set) return;
    if (set.pending?.start === start) {
      set.pending = null;
      set.error = error;
    }
    rows.forEach((row, i) => set.rows.set(start + i, row));
    if (set.rows.size > KEEP && !set.order) prune(set);
    if (id === shown) {
      // the first rows read size the columns
      if (!set.measured && rows.length) {
        table.setColumns(columnsOf(set), null);
        set.measured = true;
        set.state = table.state();
      }
      renderStatus(set);
      table.refresh();
    }
  }

  // Forget the rows farthest from the window in view.
  function prune(set) {
    const middle = (set.view.id === shown ? table.state().top : set.state?.top) ?? 0;
    for (const index of set.rows.keys()) {
      if (Math.abs(index - middle) > KEEP / 2) set.rows.delete(index);
    }
  }

  // Rows the table offers: those read, and up to AHEAD more while the query
  // may have them. Rows past the end show as missing until reading finds it.
  function extent({ total, seen, cursor }) {
    if (cursor === "exhausted") return seen;
    return Math.min(total.kind === "exact" ? total.n : Infinity, seen + AHEAD);
  }

  // The row a display position shows: itself, unless sorted here.
  const indexOf = (set, i) => (set?.order ? set.order[i] : i);

  // An exhausted set's total is always exact, or a lower bound when the
  // work budget ended it.
  function totalText({ total }) {
    if (total.kind === "exact") return number(total.n);
    if (total.kind === "at-least") return `≥ ${number(total.n)}`;
    return "?";
  }

  // The view's columns, or, for rows of no known columns, one per value.
  function columnsOf(set) {
    const { view } = set;
    const sample = indexOf(set, 0);
    const first = set.rows.get(sample) ?? set.rows.values().next().value ?? [];
    const named = view.columns.length
      ? view.columns
      : first.map((_, i) => ({ name: String(i + 1), type: null, var: null }));
    // Numbers align right: by declared type, else by the first value read.
    return named.map((column, i) => ({
      ...column,
      numeric: /^(int|float)$/.test(column.type ?? "") || (!column.type && NUMBER.test(first[i]?.text ?? "")),
    }));
  }

  // ---- sorting ----------------------------------------------------------

  // Sort by `column`: a click cycles ascending, descending, unsorted. A set
  // whose rows all fit here sorts here; a larger one becomes a new set the
  // studio sorts (results.rs `sort_rows`), as a refinement.
  async function sortBy(column, descending) {
    const set = current();
    if (!set) return;
    const now = set.state?.sort ?? set.view.sorted;
    if (descending === undefined) {
      descending = now?.column !== column ? false : now.descending ? null : true;
    }
    const sort = descending === null ? null : { column, descending };
    const { total } = set.view;
    // unsorting a set the studio sorted goes back to the set it sorted
    if (!sort && set.view.sorted) return show(set.view.parent.parent);
    if (sort && (total.kind !== "exact" || total.n > KEEP)) {
      send({ t: "refine", set: set.view.id, refinement: { op: "sort", column, descending } });
      return;
    }
    if (sort && total.n) {
      try {
        await readRange(set, 0, total.n, "reading the rows to sort them");
      } catch (error) {
        return note(String(error.message ?? error));
      }
    }
    sortHere(set, sort, true);
  }

  // Order the set's rows, all cached, by `sort` (null: as they came).
  function sortHere(set, sort, announce) {
    const { total, seen } = set.view;
    const rows = Array.from({ length: total.kind === "exact" ? total.n : seen }, (_, i) => set.rows.get(i));
    if (sort && rows.some((row) => !row)) return; // not all here: the twin view sorts
    set.order = sort ? sortedOrder(rows, sort.column, sort.descending) : null;
    set.state = { ...set.state, sort };
    if (set.view.id !== shown) return;
    table.setSort(sort);
    table.refresh();
    renderStatus(set);
    if (announce) {
      set.state = table.state();
      channel?.postMessage({ set: set.view.id, state: set.state });
    }
  }

  // ---- reading ranges whole: copy and export -----------------------------

  // Rows [start, end) of the set's own order, read BULK at a time.
  async function readRange(set, start, end, why) {
    const rows = [];
    let at = start;
    while (at < end) {
      if (set.rows.has(at)) {
        rows.push(set.rows.get(at++));
        continue;
      }
      set.busy = `${why}: ${number(at)} of ${number(end)}`;
      if (set.view.id === shown) renderStatus(set);
      const reply = await new Promise((resolve) => {
        waiting.set(`${set.view.id}:${at}`, resolve);
        send({ t: "rows", set: set.view.id, start: at, end: Math.min(end, at + BULK) });
      });
      if (reply.error) {
        set.busy = null;
        throw new Error(reply.error);
      }
      if (!reply.rows.length) break;
      rows.push(...reply.rows);
      at += reply.rows.length;
    }
    set.busy = null;
    if (set.view.id === shown) renderStatus(set);
    return rows;
  }

  // Display rows [from, to), in the order shown.
  async function displayed(set, from, to, why) {
    if (set.order) return set.order.slice(from, to).map((i) => set.rows.get(i));
    return readRange(set, from, to, why);
  }

  const names = (set) => columnsOf(set).map((column) => column.name);

  async function copySelection(format) {
    const set = current();
    const selection = set && table.state().selection;
    if (!selection) return note("Select rows to copy: click one, Shift+click or Shift+arrows for more, ⌘A for all.");
    try {
      const rows = await displayed(set, selection.from, selection.to + 1, "reading the rows to copy");
      const text = format === "csv" ? toCSV(names(set), rows)
        : format === "facts" ? toFacts(set.view.relation ?? set.view.id, rows)
        : toTSV(names(set), rows);
      await navigator.clipboard.writeText(text);
      note(`Copied ${number(rows.length)} row${rows.length === 1 ? "" : "s"} as ${format === "facts" ? "Slog facts" : format.toUpperCase()}.`);
    } catch (error) {
      note(`Not copied: ${error.message ?? error}`);
    }
  }

  async function download() {
    const set = current();
    if (!set) return;
    try {
      const n = set.view.cursor === "exhausted" ? set.view.seen
        : set.view.total.kind === "exact" ? set.view.total.n : Infinity;
      const rows = await displayed(set, 0, n, "reading the rows to export");
      const link = element("a");
      link.href = URL.createObjectURL(new Blob([toCSV(names(set), rows)], { type: "text/csv" }));
      link.download = `${set.view.id}.csv`;
      link.click();
      setTimeout(() => URL.revokeObjectURL(link.href), 10_000);
    } catch (error) {
      note(`Not exported: ${error.message ?? error}`);
    }
  }

  // ---- rendering ----------------------------------------------------------

  // A new current state makes sets past.
  onStates(() => {
    renderTabs();
    renderStatus(sets.get(shown));
  });

  function renderTabs() {
    transcriptTab?.setAttribute("aria-selected", String(shown === null));
    const existing = new Map([...tabs.querySelectorAll(".rs-tab[data-set]")].map((tab) => [tab.dataset.set, tab]));
    for (const [id, { view }] of sets) {
      let tab = existing.get(id);
      existing.delete(id);
      if (!tab) {
        tab = tabs.appendChild(element("button", "rs-tab"));
        tab.dataset.set = id;
        tab.append(element("span", "rs-dot"), stamped(id, view.state, { className: "rs-name" }));
        const close = tab.appendChild(element("span", "rs-close", "×"));
        close.title = "Close this tab";
        close.addEventListener("click", (event) => {
          event.stopPropagation();
          sets.delete(id);
          closed.add(id);
          if (shown === id) show(null);
          else renderTabs();
        });
        tab.addEventListener("click", () => show(id));
      }
      tab.title = view.parent ? `${view.query}\n${view.parent.parent} · ${view.parent.refinement}` : view.query;
      tab.setAttribute("aria-selected", String(id === shown));
      tab.classList.toggle("live", view.cursor === "live");
      tab.classList.toggle("stale", view.stale && !view.state);
      tab.classList.toggle("past", isPast(view.state));
    }
    for (const tab of existing.values()) tab.remove();
  }

  // The set's ancestry, oldest first: r1 › X = 3 › r2 › sort by Y › r3.
  function renderLineage({ view }) {
    lineage.replaceChildren();
    const chain = [];
    for (let at = view; at?.parent; at = sets.get(at.parent.parent)?.view) {
      chain.unshift(at.parent);
      if (chain.length > 8) break;
    }
    for (const { parent, refinement } of chain) {
      const link = lineage.appendChild(element("a", null, parent));
      link.title = sets.get(parent)?.view.query ?? "closed";
      link.addEventListener("click", () => show(parent));
      lineage.append(element("span", "rs-step", ` › ${refinement} › `));
    }
    if (chain.length) lineage.append(element("b", null, view.id));
  }

  function renderStatus(set) {
    if (!set || set.view.id !== shown) return;
    const { view } = set;
    status.replaceChildren();
    const { first, last } = table.range();
    const range = last > first ? `rows ${number(first + 1)}–${number(last)}` : "no rows";
    status.append(element("span", "rs-range", `${range} of ${totalText(view)}`));
    const past = isPast(view.state);
    nowButton.hidden = !past;
    nowButton.textContent = `Show at ${stateName(states().current)}`;
    const cursor = past
      ? ["past", `read at ${stateName(view.state)}, read-only: rows past the cache re-derive it`]
      : view.stale
      ? ["stale", "stale: the database changed since this ran; press Enter in the query to run it again"]
      : view.cursor === "live" ? ["live", "holds the query cursor"]
      : view.cursor === "parked" ? ["parked", "parked: rows past the cache run the query again"]
      : view.budget ? ["budget", "the work budget ended the query here"]
      : ["complete", "complete"];
    status.append(element("span", `rs-state ${cursor[0]}`, cursor[1]));
    const sort = set.state?.sort;
    if (sort && set.order) {
      status.append(element("span", "rs-note", `sorted here by ${columnsOf(set)[sort.column]?.name}`));
    }
    const busy = set.busy ?? view.loading
      ?? (set.pending ? `loading rows ${number(set.pending.start + 1)}–${number(set.pending.end)}…` : null);
    if (busy) status.append(element("span", "rs-loading", busy));
    if (view.total_note) status.append(element("span", "rs-note", view.total_note));
    if (view.relation) {
      const kept = status.appendChild(element("span", "rs-relation", `relation ${view.relation}`));
      kept.title = `The answers are kept as ${view.relation}; later queries can read it, as ?(${view.relation} …)`;
    } else if (view.unkept) {
      status.append(element("span", "rs-note", `not kept as a relation: ${view.unkept}`));
    }
    if (view.duplicates) {
      status.append(element("span", "rs-caution",
        "rows can repeat: the projection hides variables, and keeps one row per binding (audit Q-02)"));
    }
    // A stale set's refusal to read past its cache repeats its state.
    if (set.error && (!view.stale || view.state)) status.append(element("span", "rs-error", set.error));
    if (flash.textContent) status.append(flash);
  }

  // Ask for the first run of rows in [first, last) not yet here, one
  // request per set at a time; the reply renders, which asks for the next.
  function request(set, first, last) {
    if (set.pending || set.error) return;
    let start = first;
    while (start < last && set.rows.has(start)) start++;
    if (start >= last) return;
    set.pending = { start, end: Math.min(last, start + REQUEST) };
    send({ t: "rows", set: set.view.id, start, end: set.pending.end });
  }

  // ---- the row at the cursor, and what can be done with it ----------------

  function renderDetail(set) {
    const at = set && table.state().cursor;
    const row = at && set.rows.get(indexOf(set, at.row));
    // compact, the panel opens with a click; full, it stays open beside
    detail.hidden = !row;
    if (!row) return;
    detail.replaceChildren();
    const columns = columnsOf(set);
    const heading = detail.appendChild(element("div", "rs-detail-head", `row ${number(indexOf(set, at.row) + 1)}`));
    const dismiss = heading.appendChild(element("button", "icon small", "×"));
    dismiss.title = "Close (Esc)";
    dismiss.addEventListener("click", () => { detail.hidden = true; });
    const fields = detail.appendChild(element("div", "rs-fields"));
    row.forEach((cell, i) => {
      const field = fields.appendChild(element("div", `rs-field${i === at.column ? " focused" : ""}`));
      const label = field.appendChild(element("div", "rs-field-name", columns[i]?.name ?? String(i + 1)));
      if (columns[i]?.type) label.append(element("span", "tb-type", columns[i].type));
      if (cell.handle) label.append(element("span", "v-handle", cell.handle));
      field.append(renderTree(treeOf(cell)));
      field.addEventListener("click", () => {
        table.restore({ ...table.state(), cursor: { row: at.row, column: i } });
        renderDetail(set);
      });
    });
    const cell = row[at.column];
    const column = set.view.columns[at.column];
    if (!cell) return;
    const name = columns[at.column]?.name;
    const actions = detail.appendChild(element("div", "rs-actions"));
    const action = (label, title, act, enabled = true) => {
      const node = actions.appendChild(element("button", "secondary small", label));
      node.title = title;
      node.disabled = !enabled;
      node.addEventListener("click", act);
    };
    const id = set.view.id;
    const value = cell.handle ?? cell.text;
    action(`Rows where ${name} = this`, column?.var
      ? `A new set: the query with the guard (= ${column.var} ${value})`
      : `${name} is a constant of the query`,
    () => send({ t: "refine", set: id, refinement: { op: "filter", column: at.column, value } }),
    Boolean(column?.var));
    action("Where else?", `Which relations hold this value: uses ${value}`, () => run(`uses ${value}`));
    if (cell.handle) action(`Show ${cell.handle}`, "Print the whole value", () => run(`show ${cell.handle}`));
    action("Copy value", "Copy the value as Slog", () => navigator.clipboard.writeText(cell.text).then(() => note("Copied.")));
  }

  return {
    // Every set the studio keeps, as a tab opens.
    init(views) {
      sets.clear();
      closed.clear();
      for (const tab of tabs.querySelectorAll(".rs-tab[data-set]")) tab.remove();
      views.forEach(update);
      show(sets.has(shown) ? shown : null);
      if (full) channel?.postMessage({ hello: true });
    },
    update,
    rows: receive,
    show,
  };
}
