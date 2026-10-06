// Answers as tables in the transcript: a query's result set, or the facts
// `show` prints, in table.js's compact table, a fixed few rows high however
// many rows there are, scrolled in place. A table is in the DOM only while
// it is near the transcript's view, so a long transcript of them stays
// light. One click keeps a table as a cell, beside the transcript.

import { createTable } from "./table.js";
import { factCells } from "./explorer.js";
import { isPast, stamped } from "./stamp.js";

const ROW = 24; // a compact row, table.css
const HEAD = 31; // the table's header and its border
const SHOWN = 10; // rows in view at most

const element = (tag, className, text) => {
  const node = document.createElement(tag);
  if (className) node.className = className;
  if (text !== undefined) node.textContent = text;
  return node;
};
const number = (n) => n.toLocaleString("en-US");

// The facts of a `show REL` answer, the relation's name, and how many
// more there are than it printed; null for any other answer.
export function shownFacts(result) {
  const name = result?.title?.match(/^Rows · (\S+)$/)?.[1];
  if (!name || result.kind !== "query") return null;
  // the rows as data, where the session server sends them; else its text
  if (Array.isArray(result.rows)) {
    const rows = result.rows.map((row) => row.map(({ text, handle }) => (handle ? { text, handle } : { text })));
    return { name, rows, more: (result["rows-total"] ?? rows.length) - rows.length };
  }
  const lines = result.lines ?? [];
  const more = Number(lines.map((line) => line.match(/^… (\d+) more/)?.[1]).find(Boolean) ?? 0);
  return { name, rows: lines.map(factCells).filter(Boolean), more };
}

// A result set's view as a cell: its query's rows, and whether the cell
// follows the session, as a live set does, or keeps to the state the set
// was read at.
export function cellOf({ query, stale, state }) {
  return { line: query.replace(/^\?(exists|count)\b/, "?"), follows: !stale && !isPast(state) };
}

// `results` (results.js) serves sets' rows; `explorer` (explorer.js) keeps
// cells and breaks slices out; `root` is the transcript, which scrolls.
export function createInline({ results, explorer, root }) {
  const observer = new IntersectionObserver((seen) => {
    for (const { target, isIntersecting } of seen) target.near?.(isIntersecting);
  }, { root, rootMargin: "600px 0px" });

  // The table for `entry`'s answer, or null when it is not rows.
  function table(entry) {
    if (entry.set) return setTable(entry.set);
    const shown = shownFacts(entry.result);
    return shown && factsTable(shown, entry.state ?? null);
  }

  function setTable(id) {
    let parts = null;
    const source = results.attach(id, (redraw) => parts?.changed(redraw));
    if (!source) return null;
    parts = frame({
      source,
      columns: source.columns,
      title: () => stamped(id, source.view().state),
      meta() {
        const { total, stale, cursor, seen } = source.view();
        const n = total.kind === "exact" ? number(total.n)
          : total.kind === "at-least" ? `≥ ${number(total.n)}`
          : cursor === "exhausted" ? number(seen) : `${number(seen)}+`;
        return [`${n} rows`, stale ? "from an earlier state" : null, source.error()];
      },
      rows: () => {
        const { total, cursor, seen } = source.view();
        return total.kind === "exact" ? total.n : cursor === "exhausted" ? seen : SHOWN;
      },
      menu: source.menu,
      toggle: source.toggle,
      buttons: [
        ["⤢", "Open in the Results sheet, to refine, sort and export (Alt+R)", () => results.open(id)],
        ["→ cell", "Keep beside the transcript, as a cell", () => {
          const { line, follows } = cellOf(source.view());
          explorer.pinQuery(line, source.view().columns, id, follows);
        }],
      ],
    });
    return parts.node;
  }

  function factsTable({ name, rows, more }, state) {
    const source = { count: () => rows.length, row: (i) => rows[i], label: (i) => number(i + 1), want() {} };
    const columns = () => explorer.columnsFor(name, rows[0]?.length ?? 0);
    const parts = frame({
      source,
      columns,
      title: () => stamped(name, state),
      meta: () => [more ? `the first ${number(rows.length)} of ${number(rows.length + more)}` : `${number(rows.length)} rows`],
      rows: () => rows.length,
      menu: (row, column) => explorer.menu({ line: null, columns: columns(), row: rows[row], column, title: name }),
      async toggle(row, column) {
        const next = await explorer.toggle(rows[row][column]);
        rows[row] = rows[row].map((cell, i) => (i === column ? next : cell));
        parts.changed(true);
      },
      buttons: [["→ cell", "Keep beside the transcript, as a cell that pages through every row", () => explorer.pinRelation(name)]],
    });
    return parts.node;
  }

  // The frame every inline table shares: a one-line head, and a body a
  // fixed few rows high that holds the table while it is near the view.
  function frame({ source, columns, title, meta, rows, menu, toggle, buttons }) {
    const node = element("div", "it");
    const head = node.appendChild(element("div", "it-head"));
    const named = head.appendChild(element("span", "it-title"));
    named.title = "The answer, and the state of the session it was read at";
    const about = head.appendChild(element("span", "it-meta"));
    for (const [label, hint, act] of buttons) {
      const button = head.appendChild(element("button", "it-button", label));
      button.title = hint;
      button.addEventListener("click", act);
    }
    const body = node.appendChild(element("div", "it-body"));
    let table = null;
    let top = 0;
    let measured = false;

    const size = () => {
      body.style.height = `${HEAD + Math.max(1, Math.min(SHOWN, rows())) * ROW + 2}px`;
    };
    const describe = () => {
      named.replaceChildren(title());
      about.textContent = meta().filter(Boolean).join(" · ");
    };
    function mount() {
      table = createTable(body, {
        compact: true,
        source,
        on: {
          cellMenu: ({ row, column }) => menu(row, column),
          open: ({ row, column }) => menu(row, column)[0]?.[1](),
          dig: (row, column) => toggle?.(row, column),
        },
      });
      table.setColumns(columns(), null);
      measured = source.count() > 0 && Boolean(source.row(0));
      table.element.scrollTop = top;
    }
    function unmount() {
      top = table.element.scrollTop;
      body.replaceChildren();
      table = null;
    }
    node.near = (near) => {
      if (near && !table) mount();
      else if (!near && table) unmount();
    };
    size();
    describe();
    observer.observe(node);
    return {
      node,
      // `redraw`: rows already shown changed in place
      changed(redraw = false) {
        describe();
        size();
        if (!table) return;
        if (redraw) return table.redraw();
        // the first rows read size the columns
        if (!measured && source.row(0)) {
          measured = true;
          table.setColumns(columns(), null);
        } else {
          table.refresh();
        }
      },
    };
  }

  return { table };
}
