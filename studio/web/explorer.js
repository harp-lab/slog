// Looking at parts of relations, anywhere, without opening a result set:
//
//   - the Relations panel (a drawer tab): every relation with its count and
//     column types, counts that changed flagged +N/−N, and the one picked
//     shown as a paged prefix;
//   - peeks: hovering a relation's name in the transcript, the Calls tree
//     or a table (Alt+hover in the editor) shows its count, types and first
//     rows; a click keeps the peek as a cell (cells.js), to page, or open
//     as a result set;
//   - break-outs: from a cell of any table, its column's distinct values
//     with counts, the rows where the column holds it, the subterms of a
//     structured value, and where else the value appears.
//
// Every view reads with `peek` (studio/src/peek.rs), apart from the
// transcript and the result sets, and is live: when the database changes
// (`database` events) each view marks itself stale, reads again in place,
// keeps its scroll, and flags the rows added and removed -- except a cell,
// which keeps the state it was read at until asked. Tables are table.js's,
// compact.

import { splitTuple } from "./render.js";
import { createTable, parseValue, treeOf } from "./table.js";
import { onStates, stamped, stateName, states } from "./stamp.js";

const PAGE = 100; // rows read at a time as a view scrolls
const CARD_ROWS = 8; // rows a hover shows
const MAX_ROWS = 5000; // the furthest a view reads (PEEK_ROWS)
const DIFF_CAP = 5000; // rows compared when a view refreshes
const HOVER_MS = 350; // a pause on a name before its peek shows

const element = (tag, className, text) => {
  const node = document.createElement(tag);
  if (className) node.className = className;
  if (text !== undefined) node.textContent = text;
  return node;
};
const number = (n) => n.toLocaleString("en-US");

// ---- pure logic -------------------------------------------------------------

// A relation's rows as a query, one variable per column.
export const relationLine = (name, arity) =>
  `?(${[name, ...Array.from({ length: arity }, (_, i) => `V${i + 1}`)].join(" ")})`;

export const relationColumns = (name, types) => types.map((type, i) =>
  ({ name: `${name}.${i + 1}`, var: `V${i + 1}`, type: type || null, numeric: /^(int|float)$/.test(type) }));

// `line` keeping only the rows whose `variable` is `value`: a guard, before
// any projection.
export function whereLine(line, variable, value) {
  const guard = `(= ${variable} ${value})`;
  const arrow = line.lastIndexOf(" -> (");
  const body = line.trim().startsWith("?(") ? `? ${line.trim().slice(1)}` : line.trim();
  if (arrow < 0) return `${body} ${guard}`;
  const at = body.lastIndexOf(" -> (");
  return `${body.slice(0, at)} ${guard}${body.slice(at)}`;
}

// A fact as `show` prints it, `(rel v #N w …)`, as a row of cells: a
// handle stays with the value it names. Null for any other line.
export function factCells(line) {
  const items = splitTuple(line.trim());
  if (!items || items.length < 2) return null;
  return items.slice(1).map((item) => {
    const handle = item.match(/^(.*) (#\d+)$/s);
    return handle ? { text: handle[1], handle: handle[2] } : { text: item };
  });
}

// A row's identity across reads: its values' text (handles are minted
// afresh by every read).
export const rowKey = (row) => row.map((cell) => cell.text).join("\u0001");

// What changed between two reads of a view's rows, comparing at most `cap`
// of each: the keys of rows new to `after`, and the rows `before` had that
// `after` lacks.
export function diffRows(before, after, cap = DIFF_CAP) {
  const old = new Set(before.slice(0, cap).map(rowKey));
  const now = new Set(after.slice(0, cap).map(rowKey));
  return {
    added: new Set([...now].filter((key) => !old.has(key))),
    removed: before.slice(0, cap).filter((row) => !now.has(rowKey(row))),
  };
}

// The constructor terms inside a value, itself included, each once with
// how often it occurs: grouped by constructor, the most frequent first.
export function subterms(tree) {
  const found = new Map();
  const walk = (node) => {
    if (node.kind === "term") {
      const seen = found.get(node.text);
      if (seen) seen.count++;
      else found.set(node.text, { head: node.head, text: node.text, count: 1 });
    }
    for (const child of node.args ?? node.items ?? []) walk(child);
  };
  walk(tree);
  return [...found.values()].sort((a, b) => a.head.localeCompare(b.head) || b.count - a.count || a.text.localeCompare(b.text));
}

// The word around `offset` of `text`, as a relation's name would be
// written: "(path X" at 3 gives "path".
export function wordAt(text, offset) {
  const part = /[A-Za-z0-9_\-?!*'/.]/;
  let start = offset;
  let end = offset;
  while (start > 0 && part.test(text[start - 1])) start--;
  while (end < text.length && part.test(text[end])) end++;
  const word = text.slice(start, end).replace(/\.+$/, "");
  return /^[A-Za-z_]/.test(word) ? { word, start, end: start + word.length } : null;
}

// How each relation's count moved between two `tables` reads.
export function countDeltas(before, relations) {
  const deltas = new Map();
  for (const { name, rows } of relations) {
    const was = before.get(name);
    if (was !== undefined && rows !== was) deltas.set(name, rows - was);
  }
  return deltas;
}

// A cell's value as `uses` takes it: a handle, a number or a string.
export function usesValue(cell) {
  if (cell.handle) return cell.handle;
  const kind = parseValue(cell.text).kind;
  return kind === "number" || kind === "string" ? cell.text : null;
}

const totalText = (total) => !total ? null
  : total.kind === "exact" ? number(total.n)
  : total.kind === "at-least" ? `≥ ${number(total.n)}` : "?";

// ---- the explorer -------------------------------------------------------------

// `send` writes to the studio; `panel`, if given, receives the Relations
// panel and `openPanel` shows it; `run` runs a REPL line; `cells` (cells.js)
// keeps pinned views.
export function createExplorer({ send, panel = null, openPanel = () => {}, run, openSet = run, cells = null }) {
  const catalog = new Map(); // name -> { name, kind, types, rows }
  const views = new Set(); // every live view
  let epoch = -1; // the database's, as last announced
  let tablesRead = -1; // the epoch the catalog was read at
  // Cells are behind once the session's current state moves past theirs.
  onStates(() => {
    for (const view of views) if (view.pinned) view.render();
  });

  // ---- reads ----------------------------------------------------------------

  let seq = 0;
  const waiting = new Map();
  const ask = (request) => new Promise((resolve) => {
    seq += 1;
    waiting.set(seq, resolve);
    send({ t: "peek", seq, ...request });
  });

  async function loadTables() {
    const reply = await ask({ line: "tables", wait: true });
    const relations = reply.result?.relations;
    if (!relations) return;
    tablesRead = reply.epoch;
    epoch = Math.max(epoch, reply.epoch);
    const before = new Map([...catalog].map(([name, r]) => [name, r.rows]));
    const deltas = countDeltas(before, relations);
    catalog.clear();
    for (const r of relations) {
      catalog.set(r.name, { name: r.name, kind: r.kind, types: r.detail ?? [], rows: r.rows });
    }
    relationsPanel?.render(deltas);
  }

  // ---- a view of part of a relation ----------------------------------------
  //
  // spec: { kind: "relation", name } | { kind: "query", line, columns, title }
  //     | { kind: "facet", line, column, columns, title }
  //     | { kind: "subterms", cell, title } | { kind: "uses", value, type }

  function createView(spec, { rows: limit = MAX_ROWS } = {}) {
    const view = {
      spec, rows: [], total: null, more: false, loading: false, epoch: -1,
      stale: false, error: null, added: new Set(), removed: [], limit,
    };
    const source = describe(spec);
    view.el = element("div", "pk");
    const head = view.el.appendChild(element("div", "pk-head"));
    const title = head.appendChild(element("span", "pk-title"));
    title.title = source.line ?? source.title;
    const meta = head.appendChild(element("span", "pk-meta"));
    view.buttons = head.appendChild(element("span", "pk-buttons"));
    const grid = view.el.appendChild(element("div", "pk-grid"));
    const foot = view.el.appendChild(element("div", "pk-foot"));

    const shown = () => Math.min(view.rows.length + (view.more && view.rows.length < view.limit ? PAGE : 0), view.limit);
    view.table = createTable(grid, {
      compact: true,
      source: {
        count: shown,
        row: (i) => view.rows[i],
        label: (i) => number(i + 1),
        rowClass: (i) => (view.added.has(rowKey(view.rows[i])) ? "added" : ""),
        want(first, last) {
          // a cell keeps to the state it was read at: no rows of a later one
          if (frozen()) return;
          if (last > view.rows.length && view.more && view.rows.length < view.limit) read(view.rows.length, view.rows.length + PAGE);
        },
      },
      on: {
        cellMenu: ({ row, column }) => menu(source.context(view.rows[row], column)),
        dig: (row, column) => digCell(view, row, column),
        open: ({ row, column }) => {
          const items = menu(source.context(view.rows[row], column));
          items[0]?.[1]();
        },
      },
    });
    view.table.setColumns(source.columns, null);

    async function read(start, end, refreshing = false) {
      if (view.loading && !refreshing) return;
      view.loading = true;
      render();
      const reply = await source.read(start, end, refreshing || !view.hover);
      view.loading = false;
      if (reply.busy || reply.error) {
        view.error = reply.busy ? "the session is busy; this view reads again when it is free" : reply.error;
        return render();
      }
      view.error = null;
      const first = view.epoch < 0;
      if (refreshing) {
        const { added, removed } = diffRows(view.rows, reply.rows);
        // the first read of a view flags nothing
        view.added = first ? new Set() : added;
        view.removed = first ? [] : removed;
        view.rows = reply.rows;
      } else {
        view.rows.splice(start, reply.rows.length, ...reply.rows);
      }
      view.total = reply.total ?? source.total() ?? view.total;
      view.more = reply.more;
      view.epoch = reply.epoch;
      view.state = states().current;
      view.stale = view.epoch < epoch;
      // the first rows read size the columns
      if (first) view.table.setColumns(source.columns, null);
      else if (refreshing) view.table.redraw();
      else view.table.refresh();
      render();
    }

    // A cell is behind once the session moves past the state it was read at,
    // and stays there unless it follows the session.
    const behind = () => view.state != null && states().current != null && view.state !== states().current;
    const frozen = () => view.pinned && !view.follows && behind();

    function render() {
      title.replaceChildren(stamped(source.title, view.state));
      meta.replaceChildren();
      const total = totalText(view.total) ?? (view.more ? `${number(view.rows.length)}+` : number(view.rows.length));
      meta.append(element("span", "pk-count", `${total} ${source.unit}`));
      if (source.types) meta.append(element("span", "pk-types", source.types));
      if (view.added.size) meta.append(element("span", "pk-delta plus", `+${number(view.added.size)}`));
      if (view.removed.length) {
        const removed = meta.appendChild(element("span", "pk-delta minus", `−${number(view.removed.length)}`));
        removed.title = `Gone since the last read:\n${view.removed.slice(0, 12).map((row) => row.map((c) => c.text).join("  ")).join("\n")}`;
      }
      // A cell shows the state it was read at; any other view, that it is
      // behind while it reads again.
      if (frozen()) {
        const stale = meta.appendChild(element("span", "pk-stamp stale", `from ${stateName(view.state)}`));
        stale.title = `Read at ${stateName(view.state)}; the session is at ${stateName(states().current)} now. ⟳ reads it again.`;
      } else if (view.stale) {
        meta.append(element("span", "pk-stale", view.loading ? "stale · reading again…" : "stale"));
      }
      if (view.loading) meta.append(element("span", "pk-loading", "reading…"));
      view.refreshButton?.classList.toggle("wanted", view.pinned && !view.follows ? behind() : view.stale);
      foot.textContent = view.error ?? source.note?.(view) ?? "";
      foot.classList.toggle("error", Boolean(view.error));
    }

    view.load = () => read(0, Math.min(view.limit, PAGE));
    // The database changed: read the rows shown again, in place.
    view.refresh = () => {
      if (!source.live) return;
      view.stale = view.epoch < epoch;
      render();
      read(0, Math.max(Math.min(view.limit, PAGE), view.rows.length), true);
    };
    // Cells are read again only when asked (cells.js).
    view.markStale = () => {
      if (!source.live || view.epoch >= epoch) return;
      view.stale = true;
      render();
    };
    view.close = () => {
      views.delete(view);
      view.el.remove();
    };
    view.source = source;
    view.render = render;
    views.add(view);
    render();
    return view;
  }

  // What a spec reads and shows.
  function describe(spec) {
    if (spec.kind === "relation" && catalog.get(spec.name)?.kind === "struct") {
      // Queries do not read a struct's relation; `show` does, each fact
      // led by the value it is.
      const { types } = catalog.get(spec.name);
      const columns = [{ name: spec.name, var: null, type: spec.name }, ...relationColumns(spec.name, types).map((c) => ({ ...c, var: null }))];
      return {
        live: true, columns, title: spec.name, unit: "rows", types: `struct ${types.join(" ")}`,
        total: () => ({ kind: "exact", n: catalog.get(spec.name)?.rows ?? 0 }),
        async read(start, end, wait) {
          const reply = await ask({ line: `show ${spec.name} ${Math.max(1, end)}`, wait });
          if (!reply.result) return reply;
          const lines = reply.result.lines ?? [];
          const rows = lines.map(factCells).filter(Boolean);
          return { ...reply, rows: rows.slice(start, end), more: lines.some((l) => l.startsWith("…")) };
        },
        context: (row, column) => ({ line: null, columns, row, column, title: spec.name }),
      };
    }
    if (spec.kind === "relation") {
      const relation = catalog.get(spec.name) ?? { types: [], rows: null };
      const line = relationLine(spec.name, relation.types.length);
      const columns = relationColumns(spec.name, relation.types);
      return {
        live: true, line, columns, title: spec.name, unit: "rows",
        types: relation.types.join(" "),
        total: () => (catalog.get(spec.name)?.rows ?? null) === null ? null : { kind: "exact", n: catalog.get(spec.name).rows },
        read: (start, end, wait) => ask({ line, start, end, wait }),
        context: (row, column) => ({ line, columns, row, column, title: spec.name }),
        note: (view) => view.rows.length >= MAX_ROWS ? `the first ${number(MAX_ROWS)}; ⤢ opens every row` : null,
      };
    }
    if (spec.kind === "query") {
      return {
        live: true, line: spec.line, columns: spec.columns, title: spec.title, unit: "rows",
        types: spec.columns.map((c) => c.type ?? "?").join(" "),
        total: () => null,
        read: (start, end, wait) => ask({ line: spec.line, start, end, wait, count: true }),
        context: (row, column) => ({ line: spec.line, columns: spec.columns, row, column, title: spec.title }),
      };
    }
    if (spec.kind === "facet") {
      const base = spec.columns[spec.column];
      const columns = [base, { name: "rows", var: null, type: "int", numeric: true }];
      return {
        live: true, line: spec.line, columns, title: `${spec.title} · ${base.name}, by value`, unit: "values",
        total: () => null,
        read: (start, end, wait) => ask({ line: spec.line, start, end, wait, facet: spec.column }),
        // a value's row stands for the rows holding it
        context: (row) => ({
          line: spec.line, columns: spec.columns, facet: true, column: spec.column, title: spec.title,
          row: spec.columns.map((_, i) => (i === spec.column ? row?.[0] : null)),
        }),
        note: (view) => view.total?.kind === "at-least" ? "counted over the first 50,000 rows" : null,
      };
    }
    if (spec.kind === "uses") {
      const columns = [{ name: "relation", var: null, type: null }, { name: "rows", var: null, type: "int", numeric: true }];
      return {
        live: true, columns, title: `where ${spec.value} appears`, unit: "relations",
        total: () => null,
        async read(start, end, wait) {
          const reply = await ask({ line: `uses ${spec.value}`, wait });
          if (!reply.result) return reply;
          const rows = (reply.result["uses-relations"] ?? []).map((r) => [{ text: r.name }, { text: String(r.rows) }]);
          return { ...reply, rows, more: false, total: { kind: "exact", n: rows.length } };
        },
        context: (row) => ({ uses: { relation: row?.[0]?.text, value: spec.value, type: spec.type } }),
      };
    }
    // subterms: a value does not change
    const columns = [
      { name: "constructor", var: null, type: null },
      { name: "subterm", var: null, type: null },
      { name: "times", var: null, type: "int", numeric: true },
    ];
    return {
      live: false, columns, title: `${spec.title} · subterms`, unit: "subterms", total: () => null,
      async read() {
        const cell = await dig(spec.cell, 4);
        const rows = subterms(treeOf(cell)).map(({ head, text, count }) => [{ text: head }, { text }, { text: String(count) }]);
        return { rows, more: false, total: { kind: "exact", n: rows.length }, epoch };
      },
      context: (row, column) => ({ row, column, columns, title: "subterm" }),
    };
  }

  // ---- break-outs -------------------------------------------------------------

  // The slices a cell can be broken out into, as menu items.
  function menu(context) {
    const items = [];
    if (context.uses) {
      const { relation, value, type } = context.uses;
      const known = relation && catalog.get(relation);
      if (known) {
        const at = known.types.map((t, i) => (!type || !t || t === type ? i : -1)).filter((i) => i >= 0);
        items.push([`Rows of ${relation} holding ${value}`, () => {
          for (const i of at) {
            const columns = relationColumns(relation, known.types);
            const line = whereLine(relationLine(relation, known.types.length), columns[i].var, value);
            pin(createView({ kind: "query", line, columns, title: `${relation} · ${columns[i].name} = ${value}` }));
          }
        }]);
        items.push([`Peek at ${relation}`, () => pin(createView({ kind: "relation", name: relation }))]);
      }
      return items;
    }
    const { line, columns, row, column, title, facet } = context;
    const cell = row?.[column];
    const named = columns[column];
    if (!cell || !named) return items;
    const value = cell.handle ?? cell.text;
    if (line && named.var) {
      items.push([`Rows where ${named.name} = this`, () => pin(createView({
        kind: "query", line: whereLine(line, named.var, value), columns,
        title: `${title} · ${named.name} = ${short(cell.text)}`,
      }))]);
    }
    if (line && !facet) {
      items.push([`Distinct values of ${named.name}`, () => pin(createView({ kind: "facet", line, column, columns, title }))]);
    }
    if (["term", "tuple", "list", "set"].includes(treeOf(cell).kind)) {
      items.push(["Subterms of this value", () => pin(createView({ kind: "subterms", cell, title: short(cell.text) }))]);
    }
    const uses = usesValue(cell);
    if (uses) items.push(["Where else does this value appear?", () => pin(createView({ kind: "uses", value: uses, type: named.type }))]);
    return items;
  }

  const short = (text) => (text.length > 28 ? `${text.slice(0, 26)}…` : text);

  // A cell whose preview was cut short (`...`), read `levels` deeper; the
  // deeper cell remembers the one it opened (`shallow`), to close again.
  async function dig(cell, levels = 1) {
    let deeper = cell;
    for (let i = 0; i < levels && deeper.handle && /\.\.\./.test(deeper.text); i++) {
      const reply = await ask({ line: `show ${deeper.handle}`, wait: true });
      const text = reply.result?.lines?.[0];
      if (!text) break;
      deeper = { text, handle: deeper.handle };
    }
    return deeper === cell ? cell : { ...deeper, shallow: cell.shallow ?? cell };
  }

  // A cell's value opened in place, as deep as `show` goes, or closed
  // again: what a click on its handle does. Long values stay folded
  // (table.js FOLD); their pills open a level at a time.
  async function toggle(cell) {
    if (cell.shallow) return cell.shallow;
    const deeper = await dig(cell, 4);
    return deeper === cell ? { ...cell, shallow: cell } : deeper;
  }

  async function digCell(view, row, column) {
    const cell = view.rows[row]?.[column];
    if (!cell) return;
    const next = await toggle(cell);
    view.rows[row] = view.rows[row].map((c, i) => (i === column ? next : c));
    view.table.redraw();
  }

  // ---- cells: pinned views ---------------------------------------------------

  // Keep `view` as a cell, beside the transcript; it reads now if it has
  // not read yet, and from then on only when asked.
  function pin(view) {
    if (!cells) return;
    view.pinned = true;
    view.hover = false;
    view.limit = MAX_ROWS;
    cells.add(view);
    if (view.source.line) {
      const out = view.buttons.insertBefore(element("button", "pk-button", "⤢"), view.buttons.firstChild);
      out.title = "Open the whole query as a result set, in the Results sheet";
      out.addEventListener("click", () => openWhole(view.source.line));
    }
    if (view.epoch < 0 && !view.loading) view.load();
    else view.table.refresh();
    view.render();
    return view;
  }

  // The whole of a view's query, as a result set in the Results sheet.
  const openWhole = (line) => openSet(line);

  // ---- hovering a relation's name ----------------------------------------------

  let card = null; // { name, view, frame }
  let timer = 0;
  let leaving = 0;
  let pointer = null;

  const relationNamed = (word) => {
    const relation = catalog.get(word);
    return relation && relation.types.length > 0 ? relation : null;
  };

  // Where a hover peeks: names in text, and in the editor with Alt held.
  const zone = (target) => target.closest?.("#editor") ? "editor"
    : target.closest?.("#transcript, .calls-panel, #results, .pk, .rs-panel") ? "text" : null;

  function nameUnder(x, y) {
    const range = document.caretRangeFromPoint?.(x, y);
    const text = range?.startContainer;
    if (!text || text.nodeType !== Node.TEXT_NODE) return null;
    const found = wordAt(text.data, range.startOffset);
    if (!found) return null;
    const word = document.createRange();
    word.setStart(text, found.start);
    word.setEnd(text, found.end);
    const box = word.getBoundingClientRect();
    const inside = x >= box.left - 1 && x <= box.right + 1 && y >= box.top - 1 && y <= box.bottom + 1;
    return inside ? { name: found.word, box } : null;
  }

  let frameRequested = false;
  document.addEventListener("mousemove", (event) => {
    pointer = event;
    if (frameRequested) return;
    frameRequested = true;
    requestAnimationFrame(() => {
      frameRequested = false;
      hover(pointer);
    });
  }, { capture: true, passive: true });
  document.addEventListener("keydown", (event) => {
    if (event.key === "Escape" && card) hideCard();
    // Alt over a name in the editor peeks at once
    if (event.key === "Alt" && pointer) hover({ ...pointerFields(pointer), altKey: true });
  }, true);
  const pointerFields = (e) => ({ target: e.target, clientX: e.clientX, clientY: e.clientY });

  function hover(event) {
    if (card?.frame.contains(event.target)) {
      clearTimeout(leaving);
      leaving = 0;
      return;
    }
    const where = zone(event.target);
    const found = where && (where === "text" || event.altKey) ? nameUnder(event.clientX, event.clientY) : null;
    const relation = found && relationNamed(found.name);
    if (!relation) {
      clearTimeout(timer);
      timer = 0;
      if (card && !leaving) leaving = setTimeout(hideCard, 300);
      return;
    }
    if (card?.name === relation.name) {
      clearTimeout(leaving);
      leaving = 0;
      return;
    }
    clearTimeout(timer);
    timer = setTimeout(() => showCard(relation.name, found.box), event.altKey ? 0 : HOVER_MS);
  }

  function showCard(name, box) {
    hideCard();
    const view = createView({ kind: "relation", name }, { rows: CARD_ROWS });
    view.hover = true;
    const frame = element("div", "pk-card");
    frame.append(view.el);
    const hint = view.buttons.appendChild(element("button", "pk-button", "pin"));
    hint.title = "Keep this peek as a cell, beside the transcript";
    frame.addEventListener("click", (event) => {
      if (event.target.closest(".tb-body")) return;
      pinCard();
    });
    document.body.append(frame);
    const left = Math.min(box.left, innerWidth - frame.offsetWidth - 8);
    const below = box.bottom + 6 + frame.offsetHeight < innerHeight;
    Object.assign(frame.style, { left: `${Math.max(4, left)}px`, top: `${below ? box.bottom + 6 : Math.max(4, box.top - frame.offsetHeight - 6)}px` });
    card = { name, view, frame };
    view.load();
  }

  function hideCard() {
    clearTimeout(leaving);
    leaving = 0;
    if (!card) return;
    card.view.close();
    card.frame.remove();
    card = null;
  }

  // The card becomes a cell, that pages.
  function pinCard() {
    if (!card) return;
    const { view, frame } = card;
    card = null;
    frame.remove();
    pin(view);
  }

  // ---- the Relations panel -------------------------------------------------------

  const relationsPanel = panel && createRelationsPanel(panel);

  function createRelationsPanel(host) {
    host.classList.add("rel-panel");
    const head = host.appendChild(element("div", "rel-head"));
    const filter = head.appendChild(element("input", "rel-filter"));
    filter.placeholder = "Filter relations";
    filter.spellcheck = false;
    const summary = head.appendChild(element("span", "rel-summary"));
    const list = host.appendChild(element("div", "rel-list"));
    const slot = host.appendChild(element("div", "rel-view"));
    let picked = null; // { name, view }
    let deltas = new Map();
    filter.addEventListener("input", () => render());

    function render(changed) {
      if (changed) deltas = changed;
      const words = filter.value.trim().toLowerCase();
      const relations = [...catalog.values()].filter((r) => r.types.length && r.name.toLowerCase().includes(words));
      summary.textContent = `${relations.length} relations`;
      list.replaceChildren(...relations.map((r) => {
        const item = element("button", `rel-item ${r.kind ?? ""}${picked?.name === r.name ? " picked" : ""}`);
        item.title = `${r.kind ?? "relation"} ${r.name}: click to look at its rows`;
        item.append(element("span", "rel-name", r.name), element("span", "rel-types", r.types.join(" ")));
        const delta = deltas.get(r.name);
        if (delta && changed) item.append(element("span", `pk-delta ${delta > 0 ? "plus" : "minus"} flash`, `${delta > 0 ? "+" : "−"}${number(Math.abs(delta))}`));
        item.append(element("span", "rel-count", r.rows === null || r.rows === undefined ? "" : number(r.rows)));
        item.addEventListener("click", () => pick(r.name));
        return item;
      }));
      if (picked && !catalog.has(picked.name)) pick(null);
    }

    function pick(name) {
      picked?.view.close();
      picked = null;
      slot.replaceChildren();
      if (name) {
        const view = createView({ kind: "relation", name });
        view.buttons.append(Object.assign(element("button", "pk-button", "pin"), { title: "Keep as a cell, beside the transcript" }));
        view.buttons.lastChild.addEventListener("click", () => {
          picked = null;
          slot.replaceChildren();
          pin(view);
          render();
        });
        const out = view.buttons.appendChild(element("button", "pk-button", "⤢"));
        out.title = "Open the whole query as a result set, in the Results sheet";
        out.addEventListener("click", () => openWhole(view.source.line));
        slot.append(view.el);
        picked = { name, view };
        view.load();
      }
      render();
    }

    return { render, pick };
  }

  // ---- the database changed ---------------------------------------------------------

  let refreshTimer = 0;
  function changed(next) {
    if (next <= epoch) return;
    epoch = next;
    for (const view of views) view.markStale();
    clearTimeout(refreshTimer);
    // Changes come in bursts (a Run announces one as it starts); the reads
    // wait for the command that holds the session.
    refreshTimer = setTimeout(refreshAll, 120);
  }

  async function refreshAll() {
    if (tablesRead < epoch) await loadTables();
    // stale views, and those a busy session kept from reading; not cells,
    // but those that follow the session
    for (const view of views) {
      if ((!view.pinned || view.follows) && (view.error || (view.epoch >= 0 && view.epoch < epoch))) view.refresh();
    }
  }

  return {
    init() {
      loadTables();
    },
    // A finished Run: whatever is still stale reads again.
    evaluated: () => refreshAll(),
    // The studio's messages for the explorer.
    receive: {
      database: ({ epoch: next }) => changed(next),
      peeked(reply) {
        const resolve = waiting.get(reply.seq);
        waiting.delete(reply.seq);
        resolve?.(reply);
      },
    },
    menu,
    dig,
    toggle,
    // The database's epoch, as last heard of.
    epoch: () => epoch,
    // A relation's columns, from the catalog; positional when unknown.
    columnsFor(name, arity) {
      const relation = catalog.get(name);
      if (!relation) return Array.from({ length: arity }, (_, i) => ({ name: `${name}.${i + 1}`, var: null, type: null }));
      const columns = relationColumns(name, relation.types).map((c) => ({ ...c, var: null }));
      return relation.kind === "struct" ? [{ name, var: null, type: name }, ...columns] : columns;
    },
    // Keep a query, or a relation, as a cell. A query's cell that `follows`
    // reads again as the session changes, as a live result set does; else
    // it keeps to the state it was read at.
    pinQuery(line, columns, title, follows = false) {
      const named = columns.map((c) => ({ ...c, numeric: /^(int|float)$/.test(c.type ?? "") }));
      const view = createView({ kind: "query", line, columns: named, title });
      view.follows = follows;
      pin(view);
    },
    pinRelation: (name) => pin(createView({ kind: "relation", name })),
    show(name) {
      openPanel();
      relationsPanel?.pick(name);
    },
    // For the panel's opener: the catalog read last.
    relations: () => [...catalog.values()],
  };
}

