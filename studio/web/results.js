// Result sets (studio/src/results.rs): a tab per `?` query over the
// transcript area, each a table that renders only the rows in view and asks
// the studio for rows as they scroll into it. The studio pages them from the
// session server; this module never holds more than a window of them.

const ROW = 22; // px, the height of a row in results.css
const OVERSCAN = 40; // rows rendered beyond the visible ones, each side
const REQUEST = 200; // rows asked for at once
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

// `tabs` holds the tab strip, `panel` the table; `transcript` is what the
// Transcript tab shows. `send` writes to the studio; `run` runs a REPL line.
export function createResults({ tabs, panel, transcript, send, run }) {
  // id -> { view, rows: Map(index -> row), pending, error, scroll, selected }
  const sets = new Map();
  const closed = new Set();
  let shown = null;

  const transcriptTab = tabs.appendChild(element("button", "rs-tab", "Transcript"));
  transcriptTab.addEventListener("click", () => show(null));

  // One panel, filled with whichever set is shown.
  const lineage = panel.appendChild(element("div", "rs-lineage"));
  const query = panel.appendChild(element("input", "rs-query"));
  query.spellcheck = false;
  query.title = "The set's query. Edit it and press Enter to run it as a new set.";
  const status = panel.appendChild(element("div", "rs-status"));
  const scroller = panel.appendChild(element("div", "rs-scroll"));
  const table = scroller.appendChild(element("table", "rs-table"));
  const columns = table.appendChild(element("colgroup"));
  const head = table.appendChild(element("thead")).appendChild(element("tr"));
  const body = table.appendChild(element("tbody"));
  const detail = panel.appendChild(element("div", "rs-detail"));
  detail.hidden = true;

  query.addEventListener("keydown", (event) => {
    if (event.key !== "Enter" || shown === null) return;
    event.preventDefault();
    send({ t: "refine", set: shown, refinement: { op: "edit", line: query.value } });
  });
  let frame = 0;
  scroller.addEventListener("scroll", () => {
    const set = sets.get(shown);
    if (set) set.error = null;
    cancelAnimationFrame(frame);
    frame = requestAnimationFrame(renderRows);
  });
  panel.addEventListener("keydown", (event) => {
    if (event.key === "Escape") select(null);
  });

  function show(id) {
    if (shown !== null && sets.has(shown)) sets.get(shown).scroll = scroller.scrollTop;
    shown = sets.has(id) ? id : null;
    transcript.hidden = shown !== null;
    panel.hidden = shown === null;
    renderTabs();
    if (shown === null) return;
    const set = sets.get(shown);
    query.value = set.view.query;
    renderHead(set);
    renderStatus(set);
    renderDetail(set);
    scroller.scrollTop = set.scroll ?? 0;
    renderRows();
  }

  function update(view) {
    if (closed.has(view.id)) return;
    const set = sets.get(view.id);
    if (!set) {
      sets.set(view.id, { view, rows: new Map(), pending: null, error: null, scroll: 0, selected: null });
      renderTabs();
      return;
    }
    const columnsChanged = JSON.stringify(set.view.columns) !== JSON.stringify(view.columns);
    set.view = view;
    renderTabs();
    if (view.id !== shown) return;
    if (columnsChanged) renderHead(set);
    if (document.activeElement !== query) query.value = view.query;
    renderStatus(set);
    renderRows();
  }

  function receive({ set: id, start, rows, error }) {
    const set = sets.get(id);
    if (!set) return;
    set.pending = null;
    set.error = error;
    rows.forEach((row, i) => set.rows.set(start + i, row));
    if (set.rows.size > KEEP) prune(set);
    if (id === shown) {
      if (!set.measured) renderHead(set);
      renderStatus(set);
      renderRows();
    }
  }

  // Forget the rows farthest from the window in view.
  function prune(set) {
    const middle = Math.floor((set.view.id === shown ? scroller.scrollTop : set.scroll) / ROW);
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

  // An exhausted set's total is always exact, or a lower bound when the
  // work budget ended it.
  function totalText({ total }) {
    if (total.kind === "exact") return number(total.n);
    if (total.kind === "at-least") return `≥ ${number(total.n)}`;
    return "?";
  }

  // ---- rendering ----------------------------------------------------------

  function renderTabs() {
    transcriptTab.setAttribute("aria-selected", String(shown === null));
    const existing = new Map([...tabs.querySelectorAll(".rs-tab[data-set]")].map((tab) => [tab.dataset.set, tab]));
    for (const [id, { view }] of sets) {
      let tab = existing.get(id);
      existing.delete(id);
      if (!tab) {
        tab = tabs.appendChild(element("button", "rs-tab"));
        tab.dataset.set = id;
        tab.append(element("span", "rs-dot"), element("span", "rs-name", id));
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
      tab.title = view.query;
      tab.setAttribute("aria-selected", String(id === shown));
      tab.classList.toggle("live", view.cursor === "live");
      tab.classList.toggle("stale", view.stale);
    }
    for (const tab of existing.values()) tab.remove();
  }

  function renderHead(set) {
    const { view } = set;
    lineage.replaceChildren();
    if (view.parent) {
      const parent = lineage.appendChild(element("a", null, view.parent.parent));
      parent.addEventListener("click", () => show(view.parent.parent));
      lineage.append(` · ${view.parent.refinement}`);
    }
    const names = view.columns.length
      ? view.columns
      : (set.rows.values().next().value ?? []).map((_, i) => ({ name: String(i + 1), type: null }));
    const sample = [...set.rows.values()].slice(0, 200);
    set.widths = widths(sample, names);
    set.measured = sample.length > 0;
    // Numbers align right: by declared type, else by the first value read.
    set.numeric = names.map((column, i) =>
      /^(int|float)$/.test(column.type ?? "") || (!column.type && NUMBER.test(sample[0]?.[i]?.text ?? "")));
    columns.replaceChildren(element("col"));
    head.replaceChildren(element("th", "rs-index", "#"));
    names.forEach((column, i) => {
      columns.append(Object.assign(element("col"), { style: `width:${set.widths[i]}ch` }));
      const th = head.appendChild(element("th", set.numeric[i] ? "n" : null, column.name));
      if (column.type) th.append(element("span", "rs-type", column.type));
      th.title = column.var ? `${column.name} — click for actions` : `${column.name} is a constant of the query`;
      th.addEventListener("click", () => select({ row: null, column: i }));
    });
    sizeIndex(set);
  }

  // The row-number column fits the largest number the set may show.
  function sizeIndex({ view, widths }) {
    const digits = number(Math.max(extent(view), view.total.n ?? 0)).length;
    const index = Math.max(4, digits) + 3;
    columns.firstElementChild.style.width = `${index}ch`;
    table.style.width = `${index + widths.reduce((sum, width) => sum + width, 0)}ch`;
  }

  // Each column as wide as its header and its widest value among the first
  // rows read (none yet: its header), within bounds; longer values are cut,
  // and expand on click.
  function widths(sample, names) {
    return names.map((column, i) => {
      const widest = Math.max(column.name.length + (column.type?.length ?? 0) + 2,
        ...sample.map((row) => (row[i]?.text.length ?? 0) + (row[i]?.handle ? row[i].handle.length + 1 : 0)));
      return Math.min(48, Math.max(6, widest + 3));
    });
  }

  function renderStatus(set) {
    const { view } = set;
    status.replaceChildren();
    const first = Math.floor(scroller.scrollTop / ROW);
    const last = Math.min(extent(view), first + Math.ceil(scroller.clientHeight / ROW));
    const range = last > first ? `rows ${number(first + 1)}–${number(last)}` : "no rows";
    status.append(element("span", "rs-range", `${range} of ${totalText(view)}`));
    const cursor = view.stale
      ? ["stale", "stale: the database changed since this ran; press Enter in the query to run it again"]
      : view.cursor === "live" ? ["live", "holds the query cursor"]
      : view.cursor === "parked" ? ["parked", "parked: rows past the cache run the query again"]
      : view.budget ? ["budget", "the work budget ended the query here"]
      : ["complete", "complete"];
    status.append(element("span", `rs-state ${cursor[0]}`, cursor[1]));
    const busy = view.loading ?? (set.pending ? `loading rows ${number(set.pending.start + 1)}–${number(set.pending.end)}…` : null);
    if (busy) status.append(element("span", "rs-loading", busy));
    if (view.total_note) status.append(element("span", "rs-note", view.total_note));
    if (view.duplicates) {
      status.append(element("span", "rs-caution",
        "rows can repeat: the projection hides variables, and keeps one row per binding (audit Q-02)"));
    }
    // A stale set's refusal to read past its cache repeats its state.
    if (set.error && !view.stale) status.append(element("span", "rs-error", set.error));
  }

  function renderRows() {
    const set = sets.get(shown);
    if (!set) return;
    const total = extent(set.view);
    const first = Math.max(0, Math.floor(scroller.scrollTop / ROW) - OVERSCAN);
    const last = Math.min(total, Math.ceil((scroller.scrollTop + scroller.clientHeight) / ROW) + OVERSCAN);
    const width = head.childElementCount;
    const spacer = (rows) => {
      const tr = element("tr", "rs-spacer");
      const td = tr.appendChild(element("td"));
      td.colSpan = width;
      td.style.height = `${rows * ROW}px`;
      return tr;
    };
    const rows = [spacer(first)];
    for (let index = first; index < last; index++) rows.push(renderRow(set, index, width));
    rows.push(spacer(Math.max(0, total - last)));
    body.replaceChildren(...rows);
    sizeIndex(set);
    request(set, first, last);
    renderStatus(set);
  }

  function renderRow(set, index, width) {
    const tr = element("tr");
    tr.append(element("td", "rs-index", number(index + 1)));
    const row = set.rows.get(index);
    if (!row) {
      tr.className = "rs-missing";
      for (let i = 1; i < width; i++) tr.append(element("td", null, "…"));
      return tr;
    }
    row.forEach((cell, column) => {
      const kind = /^[([{]/.test(cell.text) ? "compound" : set.numeric[column] ? "n" : null;
      const td = tr.appendChild(element("td", kind, cell.text));
      td.title = cell.handle ? `${cell.text}  ${cell.handle}` : cell.text;
      const selected = set.selected;
      if (selected && selected.row === index && selected.column === column) td.classList.add("selected");
      td.addEventListener("click", () => select({ row: index, column }));
    });
    return tr;
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

  // ---- a selected cell or column, and what can be done with it ------------

  function select(selection) {
    const set = sets.get(shown);
    if (!set) return;
    set.selected = selection;
    renderDetail(set);
    renderRows();
  }

  function renderDetail(set) {
    const selection = set.selected;
    detail.hidden = !selection;
    if (!selection) return;
    detail.replaceChildren();
    const column = set.view.columns[selection.column];
    const name = column?.name ?? String(selection.column + 1);
    const cell = selection.row === null ? null : set.rows.get(selection.row)?.[selection.column];
    const heading = detail.appendChild(element("div", "rs-detail-head",
      cell ? `row ${number(selection.row + 1)} · ${name}` : `column ${name}`));
    const dismiss = heading.appendChild(element("button", "icon small", "×"));
    dismiss.title = "Close (Esc)";
    dismiss.addEventListener("click", () => select(null));
    if (cell) {
      const value = detail.appendChild(element("pre", "rs-value", cell.text));
      if (cell.handle) value.append(element("span", "rs-handle", `  ${cell.handle}`));
    }
    const actions = detail.appendChild(element("div", "rs-actions"));
    const action = (label, title, act, enabled = true) => {
      const button = actions.appendChild(element("button", "secondary small", label));
      button.title = title;
      button.disabled = !enabled;
      button.addEventListener("click", act);
    };
    const id = set.view.id;
    if (cell) {
      const value = cell.handle ?? cell.text;
      action(`Rows where ${name} = this`, column?.var
        ? `A new set: the query with the guard (= ${column.var} ${value})`
        : `${name} is a constant of the query`,
      () => send({ t: "refine", set: id, refinement: { op: "filter", column: selection.column, value } }),
      Boolean(column?.var));
      action("Where else?", `Which relations hold this value: uses ${value}`, () => run(`uses ${value}`));
      if (cell.handle) action(`Show ${cell.handle}`, "Print the whole value", () => run(`show ${cell.handle}`));
    }
    action(`Drop ${name}`, "A new set: the query projected without this column",
      () => send({ t: "refine", set: id, refinement: { op: "drop", column: selection.column } }));
  }

  return {
    // Every set the studio keeps, as a tab opens.
    init(views) {
      sets.clear();
      closed.clear();
      for (const tab of tabs.querySelectorAll(".rs-tab[data-set]")) tab.remove();
      views.forEach(update);
      show(sets.has(shown) ? shown : null);
    },
    update,
    rows: receive,
    show,
  };
}
