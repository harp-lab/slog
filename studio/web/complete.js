// Completion for Slog rules and queries, from the live catalog: the
// relations of the last `tables` result, [{ name, arity, detail }], detail
// being the column types.
//
// complete(text, pos, catalog) -> { from, to, items } offers, for the word
// being typed at `pos` (replacing text[from, to)):
//   - at the head of a list, `(pa|`, a relation name, with a placeholder
//     for each column when the list holds nothing else: path ${1:X} ${2:Y};
//   - elsewhere in a rule or query, the variables already used in it, then
//     whole atoms: (path ${1:X} ${2:Y});
//   - at the start of a query, its shapes: ?(…), ?count, ?exists;
//   - after a query's atoms, its projection: -> (X Y …).
// An item is { label, kind, insert, detail }: `kind` one of "relation",
// "variable", "shape" and "projection", and `insert` a snippet in Monaco's
// syntax, which `expand` reads for an editor without snippets.

import { isName } from "./lexer.js";
import { KEYWORDS, forms } from "./forms.js";
import { enclosing, leafAt, parse } from "./sexp.js";

const WORD = /[A-Za-z0-9_'.]/;

export function complete(text, pos, catalog) {
  let from = pos;
  let to = pos;
  while (from > 0 && WORD.test(text[from - 1])) from--;
  while (to < text.length && WORD.test(text[to])) to++;
  const prefix = text.slice(from, pos);
  const root = parse(text);
  const none = { from, to, items: [] };
  if (leafAt(root, pos)) return none;

  const form = formAround(text, pos);
  const before = text.slice(form.start, from);
  const query = /^\s*\?/.test(before);
  const matches = (label) => label.toLowerCase().startsWith(prefix.toLowerCase());

  // the start of a query: ?|, ?co|
  if (/^\s*\?$/.test(before)) {
    const shapes = [
      { label: "?count", insert: "?count ($0)", detail: "count the matches" },
      { label: "?exists", insert: "?exists ($0)", detail: "whether anything matches" },
      { label: "?(", insert: "?($0)", detail: "the matching rows" },
    ].filter((shape) => matches(shape.label.slice(1)));
    return { from: from - 1, to, items: shapes.map((shape) => ({ ...shape, kind: "shape" })) };
  }

  const list = enclosing(root, pos);
  const siblings = list.children.filter((c) => c.kind !== "comment" && c.end <= from);
  const head = list !== root && siblings.length === 0;
  const relations = offerable(catalog).filter((r) => matches(r.name));

  if (head) {
    const alone = !list.children.some((c) => c.start >= to && c.kind !== "comment");
    return {
      from,
      to,
      items: relations.map((r) => relation(r, alone ? `${r.name} ${placeholders(r).join(" ")}`.trimEnd() : r.name)),
    };
  }

  // a projection: `-|`, `->|`, or nothing typed after a query's atoms
  const arrow = text.slice(0, pos).match(/(^|\s)(->?)$/)?.[2] ?? "";
  const projected = query && list === root && !/^\?(count|exists)\b/.test(before.trim())
    && siblings.some((c) => c.kind === "list") ? variables(text, form, -1, -1) : [];
  const shown = `-> (${projected.join(" ")})`;
  const projection = projected.length ? { label: shown, kind: "projection", insert: shown, detail: "project these variables" } : null;
  if (arrow) return projection ? { from: pos - arrow.length, to, items: [projection] } : none;

  const scoped = query || form.keyword === "rule" || form.keyword === null;
  const vars = scoped && list !== root ? variables(text, form, from, to).filter(matches) : [];
  return {
    from,
    to,
    items: [
      ...(projection && !prefix ? [projection] : []),
      ...vars.map((name) => ({ label: name, kind: "variable", insert: name, detail: "variable" })),
      ...relations.map((r) => relation(r, atom(r))),
    ],
  };
}

// The relations of a catalog that can be offered: not the internal ones
// (`$…`, from `tables all`), which cannot be typed.
export const offerable = (catalog) => catalog.filter((r) => [...r.name].every((c) => WORD.test(c)));

const relation = (r, insert) => ({
  label: r.name,
  kind: "relation",
  insert,
  detail: `${r.name}/${r.arity}${r.detail?.length ? ` · ${r.detail.join(" ")}` : ""}${r.at ? ` · at ${r.at}` : ""}`,
});

const atom = (r) => `(${`${r.name} ${placeholders(r).join(" ")}`.trimEnd()})`;

// One tab stop per column, named from its type: (store ${1:Int} ${2:List}
// ${3:Val}). A type that repeats is numbered (Int1, Int2); columns that all
// share a type, or have none, are X, Y, Z, W, V, U, or X1, X2, … past six.
export function placeholders({ arity, detail = [] }) {
  const types = detail.map((type) => {
    const word = type.match(/[A-Za-z_][A-Za-z0-9_]*(?=[^A-Za-z0-9_]*$)/)?.[0] ?? "";
    return word && word[0].toUpperCase() + word.slice(1);
  });
  const count = arity ?? types.length;
  const named = types.length === count && types.every(Boolean) && new Set(types).size > 1;
  const names = Array.from({ length: count }, (_, i) => {
    if (!named) return count <= 6 ? "XYZWVU"[i] : `X${i + 1}`;
    const same = types.filter((t) => t === types[i]).length;
    return same > 1 ? `${types[i]}${types.slice(0, i + 1).filter((t) => t === types[i]).length}` : types[i];
  });
  return names.map((name, i) => `\${${i + 1}:${name}}`);
}

// The form around `pos`: { start, end, keyword }, keyword null for text
// before any form, such as a REPL command.
function formAround(text, pos) {
  const all = forms(text);
  const form = all.find((f) => f.start <= pos && pos <= f.end);
  if (form) return form;
  return { start: 0, end: all[0]?.start ?? text.length, keyword: null };
}

// The variables of the form, in order of first use: names that are not a
// list's head, a keyword or `_`, other than the word at [skipFrom, skipTo).
function variables(text, form, skipFrom, skipTo) {
  const found = new Set();
  const walk = (list) => list.children.forEach((child, k) => {
    if (child.end <= form.start || child.start >= form.end) return;
    if (child.kind === "list") walk(child);
    const word = text.slice(child.start, child.end);
    const isHead = list.kind === "list" && k === list.children.findIndex((c) => c.kind !== "comment");
    if (child.kind === "word" && !isHead && isName(word) && word !== "_" && !KEYWORDS.has(word)
      && !(child.start === skipFrom && child.end === skipTo)) {
      found.add(word);
    }
  });
  walk(parse(text));
  return [...found];
}

// A snippet as plain text and its tab stops, in order, then the final
// cursor ($0, or the end): { text, stops: [{ start, end }] }.
export function expand(snippet) {
  let text = "";
  const stops = [];
  let final = null;
  const pattern = /\$\{(\d+):([^}]*)\}|\$0/g;
  let last = 0;
  for (let match; (match = pattern.exec(snippet));) {
    text += snippet.slice(last, match.index);
    if (match[0] === "$0") {
      final = text.length;
    } else {
      stops.push({ index: Number(match[1]), start: text.length, end: text.length + match[2].length });
      text += match[2];
    }
    last = pattern.lastIndex;
  }
  text += snippet.slice(last);
  stops.sort((a, b) => a.index - b.index);
  const end = final ?? text.length;
  return { text, stops: [...stops.map(({ start, end: e }) => ({ start, end: e })), { start: end, end }] };
}
