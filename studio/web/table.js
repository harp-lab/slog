// The result table, one component for both of its homes: the Results area
// under the REPL (compact) and a result set's own window (results-page.js,
// full). Only the rows in view are in the DOM; the header's columns are
// named and typed, and resize, reorder and hide; cells show Slog values as
// structure; a cursor and a row selection move by mouse and keys.
//
// The table holds no rows. Its `source` says how many rows there are and
// hands out each one it has; the owner (results.js) fetches the rest and
// calls `refresh()`. The pure logic is exported for web/test/table.test.js.

const NUMBER = /^[-+]?(\d+\.?\d*|\.\d+)([eE][-+]?\d+)?$/;
const OVERSCAN = 12; // rows rendered beyond those in view, each side
const MIN_WIDTH = 48;
const CHAR = 7.6; // px per character of the table's monospace font

// ---- pure logic -----------------------------------------------------------

// The rows [first, last) to render when `height` px of rows show from
// `scrollTop`.
export function windowOf(scrollTop, height, rowHeight, count, overscan = OVERSCAN) {
  const first = Math.max(0, Math.floor(scrollTop / rowHeight) - overscan);
  const last = Math.min(count, Math.ceil((scrollTop + height) / rowHeight) + overscan);
  return { first: Math.min(first, last), last };
}

// A value as the server prints it, as a tree: a constructor term
// `(add (num 1) …)` is { kind: "term", head, args }; `(…)` without a
// constructor a "tuple", `[…]` a "list", `{…}` a "set"; leaves are
// "string", "number", "bool", "handle" (#N), "more" (a preview's cut) and
// "symbol". Text that does not read is one "text" leaf.
export function parseValue(text) {
  let i = 0;
  const space = () => { while (i < text.length && /\s/.test(text[i])) i++; };
  const value = () => {
    space();
    const c = text[i];
    const close = { "(": ")", "[": "]", "{": "}" }[c];
    if (close) {
      const start = i++;
      const items = [];
      for (;;) {
        space();
        if (i >= text.length || ")]}".includes(text[i]) && text[i] !== close) throw new SyntaxError(text);
        if (text[i] === close) break;
        items.push(value());
      }
      i++;
      const source = text.slice(start, i);
      if (c === "(" && items[0]?.kind === "symbol") return { kind: "term", head: items[0].text, args: items.slice(1), text: source };
      return { kind: { "(": "tuple", "[": "list", "{": "set" }[c], items, text: source };
    }
    const start = i;
    if (c === "\"") {
      for (i++; text[i] !== "\""; i++) {
        if (i >= text.length) throw new SyntaxError(text);
        if (text[i] === "\\") i++;
      }
      i++;
      return { kind: "string", text: text.slice(start, i) };
    }
    while (i < text.length && !/[\s()[\]{}"]/.test(text[i])) i++;
    if (i === start) throw new SyntaxError(text);
    const word = text.slice(start, i);
    const kind = NUMBER.test(word) ? "number" : /^#\d+$/.test(word) ? "handle"
      : /^#[tf]$/.test(word) ? "bool" : /^(…|\.\.\.)$/.test(word) ? "more" : "symbol";
    return { kind, text: word };
  };
  try {
    const tree = value();
    space();
    if (i === text.length) return tree;
  } catch (error) {
    if (!(error instanceof SyntaxError)) throw error;
  }
  return { kind: "text", text };
}

// A cell's value as plain text, for CSV and TSV: a string without its
// quotes and escapes, anything else as printed.
export function plainValue(text) {
  if (!/^".*"$/s.test(text)) return text;
  return text.slice(1, -1).replace(/\\(.)/gs, (_, c) => ({ n: "\n", t: "\t", r: "\r" })[c] ?? c);
}

export function csvField(text) {
  return /[",\r\n]|^\s|\s$/.test(text) ? `"${text.replace(/"/g, "\"\"")}"` : text;
}

// TSV has no quoting: tabs and line breaks inside a value are escaped.
export function tsvField(text) {
  return text.replace(/\\/g, "\\\\").replace(/\t/g, "\\t").replace(/\n/g, "\\n").replace(/\r/g, "\\r");
}

// Rows (arrays of cells { text }) under a header of column names.
export function toCSV(names, rows) {
  return [names, ...rows.map((row) => row.map((cell) => plainValue(cell.text)))]
    .map((fields) => fields.map(csvField).join(",")).join("\r\n") + "\r\n";
}

export function toTSV(names, rows) {
  return [names, ...rows.map((row) => row.map((cell) => plainValue(cell.text)))]
    .map((fields) => fields.map(tsvField).join("\t")).join("\n") + "\n";
}

// Rows as Slog facts of `relation`, values as printed.
export function toFacts(relation, rows) {
  return rows.map((row) => `(${[relation, ...row.map((cell) => cell.text)].join(" ")})`).join("\n") + "\n";
}

// A column filter as typed, `> 3`, `= "a b"`, or just a value (`=`), as a
// refinement of the set; a string column's bare word is quoted. Null when
// there is nothing to filter by.
export function filterRefinement(column, typed, type) {
  const match = typed.trim().match(/^(<=|>=|\/=|!=|<|>|=)?\s*(.*)$/s);
  const value = match[2].trim();
  if (!value) return null;
  const guard = match[1] === "!=" ? "/=" : match[1] ?? "=";
  const quote = type === "str" && !/^["#(]/.test(value) && !/^[A-Z_]/.test(value);
  return { op: "filter", column, guard, value: quote ? JSON.stringify(value) : value };
}

// How two cells order: numbers by value and first, the rest by their text
// (as Studio's own sort does, results.rs `sort_rows`).
export function compareCells(a, b) {
  const x = NUMBER.test(a?.text ?? "") ? Number(a.text) : null;
  const y = NUMBER.test(b?.text ?? "") ? Number(b.text) : null;
  if (x !== null && y !== null) return x - y;
  if (x !== null || y !== null) return x !== null ? -1 : 1;
  const s = a?.text ?? "";
  const t = b?.text ?? "";
  return s < t ? -1 : s > t ? 1 : 0;
}

// The row numbers of `rows` in the order of `column`, stably.
export function sortedOrder(rows, column, descending) {
  const order = rows.map((_, i) => i);
  order.sort((i, j) => (descending ? -1 : 1) * compareCells(rows[i][column], rows[j][column]) || i - j);
  return order;
}

// A column's starting width: its header, or its widest value among `sample`,
// each term's pill a little wider than its text.
export function columnWidth(column, sample, index) {
  const width = (text) => (text.length + 1) * CHAR + (text.match(/[([{]/g)?.length ?? 0) * 8;
  const widest = Math.max((column.name.length + (column.type?.length ?? 0) + 4) * CHAR,
    ...sample.map((row) => width(row[index]?.text ?? "")));
  return Math.round(Math.min(420, Math.max(MIN_WIDTH, widest + 20)));
}

// ---- values as DOM --------------------------------------------------------

const element = (tag, className, text) => {
  const node = document.createElement(tag);
  if (className) node.className = className;
  if (text !== undefined) node.textContent = text;
  return node;
};

const parsed = new WeakMap(); // cell -> its tree, parsed once
export const treeOf = (cell) => {
  if (!parsed.has(cell)) parsed.set(cell, parseValue(cell.text));
  return parsed.get(cell);
};

const BRACKETS = { tuple: ["(", ")"], list: ["[", "]"], set: ["{", "}"] };

// One line of a value: constructor names stand out, terms nest as pills.
export function renderInline(tree, depth = 0) {
  if (tree.kind === "term" || BRACKETS[tree.kind]) {
    const node = element("span", `v-${tree.kind} d${depth % 3}`);
    const [open, close] = BRACKETS[tree.kind] ?? ["(", ")"];
    if (tree.kind === "term") node.append(element("span", "v-ctor", tree.head));
    else node.append(element("span", "v-bracket", open));
    const items = tree.kind === "term" ? tree.args : tree.items;
    items.forEach((item, i) => {
      if (tree.kind === "term" || i > 0) node.append(" ");
      node.append(renderInline(item, depth + 1));
    });
    if (tree.kind !== "term") node.append(element("span", "v-bracket", close));
    return node;
  }
  return element("span", `v-${tree.kind}`, tree.text);
}

// A value as a tree that folds: each term or collection a <details>, open
// to `open` levels.
export function renderTree(tree, open = 3) {
  const items = tree.kind === "term" ? tree.args : tree.items;
  if (!items?.length) return renderInline(tree);
  const node = element("details", "v-tree");
  node.open = open > 0;
  const summary = node.appendChild(element("summary"));
  if (tree.kind === "term") summary.append(element("span", "v-ctor", tree.head));
  else summary.append(element("span", "v-bracket", `${BRACKETS[tree.kind][0]} ${items.length} ${tree.kind === "list" ? "items" : "elements"} ${BRACKETS[tree.kind][1]}`));
  // folded, the summary previews the rest on one line
  const preview = summary.appendChild(element("span", "v-preview"));
  if (tree.kind === "term") items.forEach((item) => preview.append(" ", renderInline(item)));
  const children = node.appendChild(element("div", "v-children"));
  for (const item of items) children.append(renderTree(item, open - 1));
  return node;
}

// A menu of [label, act] items under the element `event` came from; a
// click elsewhere closes it.
let menu = null;
export function openMenu(event, items) {
  event.stopPropagation();
  closeMenu();
  menu = document.body.appendChild(element("div", "tb-menu"));
  for (const [label, act] of items) {
    const item = menu.appendChild(element("button", null, label));
    item.addEventListener("click", () => { closeMenu(); act(); });
  }
  const box = event.currentTarget.getBoundingClientRect();
  menu.style.left = `${Math.max(4, Math.min(box.left, innerWidth - menu.offsetWidth - 4))}px`;
  menu.style.top = `${box.bottom + 2}px`;
}

function closeMenu() {
  menu?.remove();
  menu = null;
}

if (globalThis.document) {
  document.addEventListener("pointerdown", (event) => {
    if (menu && !menu.contains(event.target)) closeMenu();
  });
}

// ---- the table ------------------------------------------------------------

// `host` receives the table. `source` is { count(), row(i), label(i),
// want(first, last) }: rows are display positions, `label` the row number
// shown. `on` holds the owner's handlers: select(cursor), open(cursor),
// sort(column), filter(column, text), copy(from, to), menu(column) ->
// [[label, act]], change(state), the last for anything a twin view mirrors.
export function createTable(host, { source, on, compact = true }) {
  let columns = [];
  let layout = { order: [], hidden: [], widths: [] };
  let sort = null; // { column, descending }
  let cursor = null; // { row, column }: a display row and a data column
  let selection = null; // { anchor, from, to }: display rows
  let rowHeight = compact ? 24 : 28;
  const rendered = new Map(); // display row -> its node

  const scroller = host.appendChild(element("div", "tb"));
  scroller.tabIndex = 0;
  scroller.setAttribute("role", "grid");
  const head = scroller.appendChild(element("div", "tb-head"));
  const filters = scroller.appendChild(element("div", "tb-filters"));
  const body = scroller.appendChild(element("div", "tb-body"));
  scroller.classList.toggle("full", !compact);
  scroller.classList.toggle("filtering", !compact);

  // A change made here, not one mirrored from the twin view, is announced.
  let quiet = false;
  const changed = () => { if (!quiet) on.change?.(state()); };

  // A scroll to where the twin view put us is not announced back to it.
  let mirrored = null;
  let frame = 0;
  scroller.addEventListener("scroll", () => {
    cancelAnimationFrame(frame);
    frame = requestAnimationFrame(() => {
      render();
      if (scroller.scrollTop !== mirrored) changed();
      mirrored = null;
    });
  });
  new ResizeObserver(() => render()).observe(scroller);
  scroller.addEventListener("keydown", keydown);

  const visible = () => layout.order.filter((i) => !layout.hidden.includes(i));
  // The row numbers' column fits the largest; an empty last track takes
  // what width is left over.
  let indexWidth = 0;
  function sizeColumns() {
    indexWidth = Math.max(4, source.count().toLocaleString("en-US").length + 1) * CHAR + 20;
    const shown = visible();
    scroller.style.setProperty("--tb-cols", `${indexWidth}px ${shown.map((i) => `${layout.widths[i]}px`).join(" ")} 1fr`);
    const width = indexWidth + shown.reduce((sum, i) => sum + layout.widths[i], 0);
    for (const part of [head, filters, body]) part.style.width = `max(100%, ${width}px)`;
  }

  // New columns, laid out as `saved` or measured afresh from the rows
  // the source has.
  function setColumns(next, saved) {
    columns = next;
    if (saved?.order.length === columns.length) layout = structuredClone(saved);
    else {
      const sample = [];
      for (let i = 0; i < Math.min(source.count(), 200); i++) {
        const row = source.row(i);
        if (row) sample.push(row);
      }
      layout = {
        order: columns.map((_, i) => i),
        hidden: [],
        widths: columns.map((column, i) => columnWidth(column, sample, i)),
      };
    }
    renderHead();
    clear();
    render();
  }

  // ---- header ---------------------------------------------------------

  function renderHead() {
    sizeColumns();
    const index = element("div", "tb-hcell tb-index");
    const hidden = layout.hidden.length;
    index.append(element("span", null, "#"));
    if (hidden) index.append(element("span", "tb-hidden", `+${hidden}`));
    index.title = "Columns: show or hide";
    index.addEventListener("click", (event) => openMenu(event, columns.map((column, i) => [
      `${layout.hidden.includes(i) ? "☐" : "☑"} ${column.name}`, () => toggleHidden(i)])));
    head.replaceChildren(index);
    filters.replaceChildren(element("div", "tb-fcell tb-index", "where"));
    for (const i of visible()) {
      const column = columns[i];
      const cell = head.appendChild(element("div", `tb-hcell${column.numeric ? " n" : ""}`));
      cell.dataset.column = i;
      cell.draggable = true;
      cell.append(element("span", "tb-name", column.name));
      if (column.type) cell.append(element("span", "tb-type", column.type));
      if (sort?.column === i) cell.append(element("span", "tb-sort", sort.descending ? "↓" : "↑"));
      cell.title = `${column.name}${column.type ? ` : ${column.type}` : ""} — click to sort; drag to move; ▾ for more`;
      cell.addEventListener("click", (event) => {
        if (!event.target.closest(".tb-grip, .tb-more")) on.sort?.(i);
      });
      const more = cell.appendChild(element("button", "tb-more", "▾"));
      more.title = "Column actions";
      more.addEventListener("click", (event) => openMenu(event, [
        ["Sort ascending", () => on.sort?.(i, false)],
        ["Sort descending", () => on.sort?.(i, true)],
        ["Filter…", () => { showFilters(true); filters.querySelector(`[data-column="${i}"] input`)?.focus(); }],
        ["Hide column", () => toggleHidden(i)],
        ...(on.menu?.(i) ?? []),
      ]));
      const grip = cell.appendChild(element("span", "tb-grip"));
      grip.addEventListener("pointerdown", (event) => resize(event, i));
      cell.addEventListener("dragstart", (event) => event.dataTransfer.setData("text/x-column", String(i)));
      cell.addEventListener("dragover", (event) => event.preventDefault());
      cell.addEventListener("drop", (event) => {
        event.preventDefault();
        const from = Number(event.dataTransfer.getData("text/x-column"));
        if (Number.isInteger(from) && from !== i) move(from, i);
      });
      const filter = filters.appendChild(element("div", "tb-fcell"));
      filter.dataset.column = i;
      const input = filter.appendChild(element("input"));
      input.placeholder = column.var === null ? "constant" : "= value, > 3, /= x";
      input.disabled = column.var === null;
      input.spellcheck = false;
      input.title = "Enter keeps the rows whose value passes this guard, as a new set";
      input.addEventListener("keydown", (event) => {
        event.stopPropagation();
        if (event.key === "Enter") on.filter?.(i, input.value);
        if (event.key === "Escape") { input.value = ""; scroller.focus(); }
      });
    }
  }

  function toggleHidden(i) {
    const at = layout.hidden.indexOf(i);
    if (at >= 0) layout.hidden.splice(at, 1);
    else if (visible().length > 1) layout.hidden.push(i);
    relayout();
  }

  function move(from, to) {
    const order = layout.order.filter((i) => i !== from);
    order.splice(order.indexOf(to) + (layout.order.indexOf(from) < layout.order.indexOf(to) ? 1 : 0), 0, from);
    layout.order = order;
    relayout();
  }

  function resize(event, i) {
    event.preventDefault();
    event.stopPropagation();
    const start = event.clientX;
    const width = layout.widths[i];
    const moved = (e) => {
      layout.widths[i] = Math.max(MIN_WIDTH, Math.round(width + e.clientX - start));
      sizeColumns();
    };
    const done = () => {
      removeEventListener("pointermove", moved);
      removeEventListener("pointerup", done);
      changed();
    };
    addEventListener("pointermove", moved);
    addEventListener("pointerup", done);
  }

  function relayout() {
    renderHead();
    clear();
    render();
    changed();
  }

  function showFilters(on) {
    scroller.classList.toggle("filtering", on);
  }

  // ---- rows -----------------------------------------------------------

  function clear() {
    for (const node of rendered.values()) node.remove();
    rendered.clear();
  }

  // Bring the rows in view into the DOM, and only them; rows still to come
  // render as placeholders and fill in on `refresh`.
  function render() {
    const count = source.count();
    body.style.height = `${count * rowHeight}px`;
    if (count.toLocaleString("en-US").length + 1 > (indexWidth - 20) / CHAR) sizeColumns();
    const top = Math.max(0, scroller.scrollTop);
    const shown = scroller.clientHeight - head.offsetHeight - filters.offsetHeight;
    const { first, last } = windowOf(top, shown, rowHeight, count);
    for (const [index, node] of rendered) {
      if (index < first || index >= last) {
        node.remove();
        rendered.delete(index);
      }
    }
    for (let index = first; index < last; index++) {
      let node = rendered.get(index);
      if (!node) {
        node = body.appendChild(element("div", "tb-row"));
        node.style.transform = `translateY(${index * rowHeight}px)`;
        node.dataset.row = index;
        rendered.set(index, node);
        fill(node, index);
      } else if (node.classList.contains("missing") && source.row(index)) {
        fill(node, index);
      }
    }
    paint();
    source.want(first, last);
  }

  function fill(node, index) {
    const row = source.row(index);
    node.classList.toggle("missing", !row);
    const cells = [element("div", "tb-cell tb-index", source.label(index))];
    for (const i of visible()) {
      const cell = element("div", `tb-cell${columns[i].numeric ? " n" : ""}`);
      cell.dataset.column = i;
      if (row && row[i]) {
        cell.append(renderInline(treeOf(row[i])));
        if (row[i].handle) cell.append(element("span", "v-handle", row[i].handle));
      } else {
        cell.textContent = row ? "" : "…";
      }
      cells.push(cell);
    }
    node.replaceChildren(...cells);
  }

  function paint() {
    for (const [index, node] of rendered) {
      const picked = selection && index >= selection.from && index <= selection.to;
      node.classList.toggle("selected", Boolean(picked));
      for (const cell of node.children) {
        cell.classList.toggle("cursor", cursor?.row === index && String(cursor.column) === cell.dataset.column);
      }
    }
  }

  body.addEventListener("click", (event) => {
    const cell = event.target.closest(".tb-cell");
    if (!cell) return;
    const row = Number(cell.parentElement.dataset.row);
    const column = cell.dataset.column === undefined ? cursor?.column ?? visible()[0] : Number(cell.dataset.column);
    scroller.focus({ preventScroll: true });
    moveTo(row, column, event.shiftKey);
  });
  body.addEventListener("dblclick", () => cursor && on.open?.(cursor));

  // Put the cursor at (row, column); `extend` grows the selection to it.
  function moveTo(row, column, extend = false) {
    const count = source.count();
    if (!count) return;
    row = Math.max(0, Math.min(count - 1, row));
    cursor = { row, column };
    const anchor = extend && selection ? selection.anchor : row;
    selection = { anchor, from: Math.min(anchor, row), to: Math.max(anchor, row) };
    reveal(row, column);
    paint();
    on.select?.(cursor);
    changed();
  }

  function reveal(row, column) {
    const shown = scroller.clientHeight - head.offsetHeight - filters.offsetHeight;
    const top = row * rowHeight;
    if (top < scroller.scrollTop) scroller.scrollTop = top;
    else if (top + rowHeight > scroller.scrollTop + shown) scroller.scrollTop = top + rowHeight - shown;
    const cell = head.querySelector(`[data-column="${column}"]`);
    if (cell) {
      if (cell.offsetLeft < scroller.scrollLeft) scroller.scrollLeft = cell.offsetLeft;
      else if (cell.offsetLeft + cell.offsetWidth > scroller.scrollLeft + scroller.clientWidth) {
        scroller.scrollLeft = cell.offsetLeft + cell.offsetWidth - scroller.clientWidth;
      }
    }
  }

  function keydown(event) {
    const page = Math.max(1, Math.floor((scroller.clientHeight - head.offsetHeight) / rowHeight) - 1);
    const order = visible();
    const row = cursor?.row ?? -1;
    const at = Math.max(0, order.indexOf(cursor?.column ?? order[0]));
    const mod = event.metaKey || event.ctrlKey;
    const go = (r, c = at) => { event.preventDefault(); moveTo(r, order[Math.max(0, Math.min(order.length - 1, c))], event.shiftKey); };
    switch (event.key) {
      case "ArrowDown": return go(row + 1);
      case "ArrowUp": return go(row - 1);
      case "ArrowRight": return go(Math.max(row, 0), at + 1);
      case "ArrowLeft": return go(Math.max(row, 0), at - 1);
      case "PageDown": return go(row + page);
      case "PageUp": return go(row - page);
      case "Home": return mod ? go(0) : go(Math.max(row, 0), 0);
      case "End": return mod ? go(source.count() - 1) : go(Math.max(row, 0), order.length - 1);
      case "Enter":
        if (cursor) { event.preventDefault(); on.open?.(cursor); }
        return;
      case "Escape":
        if (!cursor && !selection) return;
        event.preventDefault();
        selection = null;
        cursor = null;
        paint();
        on.select?.(null);
        return changed();
    }
    if (mod && event.key === "a") {
      event.preventDefault();
      selection = { anchor: 0, from: 0, to: source.count() - 1 };
      paint();
      return changed();
    }
    if (mod && event.key === "c" && selection) {
      event.preventDefault();
      on.copy?.(selection.from, selection.to + 1);
    }
  }

  // What a twin view of the same set mirrors, and the owner keeps per set.
  function state() {
    return { top: Math.floor(scroller.scrollTop / rowHeight), layout: structuredClone(layout), sort, cursor, selection };
  }

  return {
    element: scroller,
    setColumns,
    // Rows arrived, or the count changed: fill in what is in view.
    refresh: render,
    state,
    // The rows in view, [first, last).
    range() {
      const shown = scroller.clientHeight - head.offsetHeight - filters.offsetHeight;
      return windowOf(scroller.scrollTop, shown, rowHeight, source.count(), 0);
    },
    // Mirror `saved`, without announcing it back.
    restore(saved) {
      quiet = true;
      try {
        // a new layout or order draws every row again
        if (saved.layout && JSON.stringify(saved.layout) !== JSON.stringify(layout)) {
          layout = structuredClone(saved.layout);
          clear();
        }
        if (JSON.stringify(saved.sort ?? null) !== JSON.stringify(sort)) clear();
        sort = saved.sort ?? null;
        cursor = saved.cursor ?? null;
        selection = saved.selection ?? null;
        renderHead();
        if (saved.top !== undefined && saved.top !== Math.floor(scroller.scrollTop / rowHeight)) {
          scroller.scrollTop = saved.top * rowHeight;
          mirrored = scroller.scrollTop;
        }
        render();
      } finally {
        quiet = false;
      }
    },
    // The rows are in a new order: draw them all again.
    setSort(next) {
      sort = next;
      renderHead();
      clear();
      render();
    },
    setCompact(on) {
      rowHeight = on ? 24 : 28;
      scroller.classList.toggle("full", !on);
      showFilters(!on);
      const top = Math.floor(scroller.scrollTop / (on ? 28 : 24));
      clear();
      scroller.scrollTop = top * rowHeight;
      render();
    },
    showFilters,
    focus: () => scroller.focus(),
  };
}
