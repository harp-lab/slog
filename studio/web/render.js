// Rendering one REPL command and its outcome. Structured fields of the result
// (`change`, `relations`, query pager metadata) render as tables; anything
// else falls back to the server's own text lines.

const element = (tag, className, text) => {
  const node = document.createElement(tag);
  if (className) node.className = className;
  if (text !== undefined) node.textContent = text;
  return node;
};

// `entry` is a studio Entry: { origin, line, ms, result, error }.
// `onSpan(span)` is called when a source position is clicked.
export function renderEntry(entry, { file, onSpan }) {
  const node = element("div", `entry ${entry.origin}`);
  const line = node.appendChild(element("div", "line", entry.line));
  if (entry.ms >= 100) line.append(element("span", "ms", `${(entry.ms / 1000).toFixed(1)} s`));
  if (entry.error) {
    node.append(renderError(entry.error, file, onSpan));
  } else if (entry.result) {
    node.append(...renderResult(entry.result));
  }
  return node;
}

function renderError({ kind, message, span }, file, onSpan) {
  const node = element("div", "error");
  if (span && span.file === file) {
    // The message repeats the position as BASENAME:LINE:COL; make it the link.
    const prefix = message.match(/^[^:\s]+:\d+:\d+: /);
    const link = node.appendChild(element("a", "span", `${span.line}:${span.col}`));
    link.addEventListener("click", () => onSpan(span));
    node.append(` ${prefix ? message.slice(prefix[0].length) : message}`);
  } else {
    node.textContent = kind === "lane" ? `session server: ${message}` : message;
  }
  return node;
}

function renderResult(result) {
  const parts = [];
  if (result.title) parts.push(element("div", "title", result.title));
  const lines = result["brief-lines"] ?? result.lines ?? [];
  if (result.kind === "query" && result["query-mode"] === "rows") {
    parts.push(...renderRows(result.title ?? "", lines));
  } else if (Array.isArray(result.relations) && result.relations.every((r) => "rows" in r)) {
    parts.push(renderRelations(result.relations));
  } else if (lines.length) {
    parts.push(element("pre", "lines", lines.join("\n")));
  }
  if (result.change) parts.push(...renderChange(result.change));
  return parts;
}

function renderRelations(relations) {
  return table(
    ["relation", "kind", "columns", "rows"],
    relations.map((r) => [r.name, r.kind, (r.detail ?? []).join(" "), { n: r.rows }]),
  );
}

// The relations whose size moved; unchanged ones (often empty built-ins) are
// only counted.
function renderChange(change) {
  const deltas = change["size-deltas"] ?? [];
  const moved = deltas.filter((d) => d.net !== 0);
  const quiet = deltas.length - moved.length + (change["size-deltas-omitted"] ?? 0);
  const parts = [];
  if (moved.length) {
    parts.push(table(
      ["relation", "before", "after", "change"],
      moved.map((d) => [
        d.relation,
        { n: d.before ?? "—" },
        { n: d.after ?? "removed" },
        { n: `${d.net > 0 ? "+" : ""}${d.net}`, className: d.net > 0 ? "plus" : "minus" },
      ]),
    ));
  }
  if (quiet) parts.push(element("div", "note", `${quiet} other relation${quiet === 1 ? "" : "s"} unchanged`));
  return parts;
}

// Query pages arrive as text: a header ("3 rows", "rows 1–50 — `more`
// continues…") and then "N  ROW" lines, ROW being a fact `(rel v …)` or, for
// a projection titled "Query · (X Z)", a tuple `(v …)`.
function renderRows(title, lines) {
  const projection = title.match(/·\s*(\(.*\))\s*$/);
  const rows = [];
  const notes = [];
  for (const text of lines) {
    const match = text.match(/^\s*(\d+)\s+(\(.*\))\s*$/);
    const cells = match && splitTuple(match[2]);
    if (cells) rows.push({ index: match[1], cells: projection ? cells : cells.slice(1), relation: cells[0] });
    else notes.push(text);
  }
  const parts = notes.map((text) => element("div", "note", text));
  if (!rows.length) return parts;
  const width = Math.max(...rows.map((row) => row.cells.length));
  const names = projection
    ? splitTuple(projection[1]) ?? []
    : Array.from({ length: width }, (_, i) => `${rows[0].relation}.${i + 1}`);
  parts.push(table(["", ...names], rows.map((row) => [{ n: row.index }, ...row.cells])));
  return parts;
}

// The top-level elements of "(a "b c" (d e) #1 f)" as source text:
// ["a", "\"b c\"", "(d e) #1", "f"]. A value handle `#N` stays with the value
// it names. Returns null for text that is not one balanced tuple.
export function splitTuple(text) {
  if (!text.startsWith("(") || !text.endsWith(")")) return null;
  const body = text.slice(1, -1);
  const cells = [];
  let start = -1;
  let depth = 0;
  let inString = false;
  const close = (end) => {
    if (start < 0) return;
    const cell = body.slice(start, end);
    if (/^#\d+$/.test(cell) && cells.length) cells[cells.length - 1] += ` ${cell}`;
    else cells.push(cell);
    start = -1;
  };
  for (let i = 0; i < body.length; i++) {
    const c = body[i];
    if (inString) {
      if (c === "\\") i++;
      else if (c === "\"") inString = false;
      continue;
    }
    if (depth === 0 && /\s/.test(c)) { close(i); continue; }
    if (start < 0) start = i;
    if (c === "\"") inString = true;
    else if ("([{".includes(c)) depth++;
    else if (")]}".includes(c) && --depth < 0) return null;
  }
  if (inString || depth !== 0) return null;
  close(body.length);
  return cells;
}

// A cell is text, or { n, className } for a right-aligned number-like value.
function table(headings, rows) {
  const node = element("table");
  const head = node.appendChild(element("tr"));
  for (const heading of headings) head.append(element("th", null, heading));
  for (const row of rows) {
    const tr = node.appendChild(element("tr"));
    for (const cell of row) {
      if (cell && typeof cell === "object") {
        tr.append(element("td", `n ${cell.className ?? ""}`, String(cell.n)));
      } else {
        tr.append(element("td", null, String(cell)));
      }
    }
  }
  return node;
}
