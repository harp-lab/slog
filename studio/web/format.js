// Pretty printing Slog: a conservative, idempotent re-layout that changes
// only the space between tokens.
//
// - Line breaks stay where they are, blank lines included, and so does the
//   space between tokens on a line (columns lined up by hand stay lined
//   up), except that none is left after an opener or before a closer.
// - The lines of a top-level form (a rule's heads and bodies) line up at
//   the column of the item after the keyword, wherever that item is; after
//   an arrow (-->, <--, ->), at the column of the item after the arrow, if
//   it shares the arrow's line. An arrow or a comment on a line of its own
//   keeps its column.
// - Inside a list, a line keeps its indentation relative to the list's
//   opener, at least one column in, and moves with the opener.
// - A closer moves up to the line it ends, unless a comment ends that line.
// - A form or list written on one line that runs past `width` is broken:
//   each item after the head and its first argument goes on its own line,
//   at that argument's column (just inside the opener for a list headed by
//   a list, `[…]` or `{…}`). The item after an arrow stays on its line.
//
// Text with a fault (lexer.js, sexp.js) is left alone.

import { KEYWORDS, forms } from "./forms.js";
import { parse } from "./sexp.js";

const ARROWS = new Set(["-->", "<--", "->"]);

// The formatted text, or null if it has a fault.
export function format(text, width = 80) {
  const root = parse(text);
  if (root.faults) return null;
  const source = (node) => text.slice(node.start, node.end);
  const newlines = (from, to) => text.slice(from, to).split("\n").length - 1;
  // the column of an offset in the source, a tab reaching the next
  // multiple of 8
  const sourceColumn = (offset) => [...text.slice(text.lastIndexOf("\n", offset - 1) + 1, offset)]
    .reduce((col, c) => (c === "\t" ? col + 8 - (col % 8) : col + 1), 0);
  const isComment = (node) => node.kind === "comment";
  const isArrow = (node) => ARROWS.has(source(node));
  let out = "";
  const column = () => out.length - out.lastIndexOf("\n") - 1;
  const lineBreak = (count, indent) => {
    out = out.replace(/[ \t]+$/, "") + "\n".repeat(count) + " ".repeat(Math.max(0, indent));
  };

  // Whether `nodes`, trailing comments aside, sit on one source line and
  // run past the width from here.
  const tooLong = (nodes) => {
    const code = nodes.filter((n) => !isComment(n));
    const span = code.length ? text.slice(code[0].start, code.at(-1).end) : "";
    return !span.includes("\n") && column() + span.length > width;
  };

  // The space before `node`, which follows source offset `from`: the line
  // breaks there, indented to `kept`, or a `force`d one, indented to
  // `indent`; else the space as it is, but none after an opener.
  function gap(from, node, { kept, indent, force }) {
    const breaks = newlines(from, node.start);
    if (breaks) lineBreak(breaks, kept);
    else if (force && !isComment(node)) lineBreak(1, indent);
    else if (isComment(node) || !/[([{]$/.test(out)) out += text.slice(from, node.start);
  }

  // A list may be broken if it is an item of a form, starts a line, or is
  // inside a list that was broken: not when it sits in the middle of a line
  // laid out by hand.
  const startsLine = () => /(^|\n)[ \t]*$/.test(out);

  function emit(node, breakable) {
    if (node.kind !== "list") {
      out += source(node);
      return;
    }
    const open = column();
    const items = node.children;
    const call = text[node.start] === "(" && items[0]?.kind === "word";
    const force = breakable && items.length > 0 && tooLong([node]);
    let indent = open + 1;
    out += text[node.start];
    items.forEach((item, k) => {
      gap(k ? items[k - 1].end : node.start + 1, item, {
        kept: open + Math.max(1, sourceColumn(item.start) - sourceColumn(node.start)),
        indent,
        force: force && k >= (call ? 2 : 1),
      });
      if (k === 1 && call) indent = column();
      emit(item, force || startsLine());
    });
    if (items.length && isComment(items.at(-1))) lineBreak(1, indent);
    out += text[node.end - 1];
  }

  // A top-level form: a keyword and the items up to the next one; or the
  // items before the first keyword, such as a query.
  function form(items) {
    const force = tooLong(items);
    let indent = column();
    items.forEach((item, k) => {
      const after = items[k - 1];
      if (after) {
        const outdent = indent - (item.end - item.start) - 1;
        gap(after.end, item, {
          kept: k === 1 || isComment(item) || isArrow(item) ? sourceColumn(item.start) : indent,
          indent: isArrow(item) ? outdent : indent,
          force: force && k > 1 && !isArrow(after),
        });
        if (k === 1 || (isArrow(after) && !newlines(after.end, item.start))) indent = column();
      }
      emit(item, true);
    });
  }

  const groups = [];
  for (const node of root.children) {
    if (!groups.length || (node.kind === "word" && KEYWORDS.has(source(node)))) groups.push([]);
    groups.at(-1).push(node);
  }
  groups.forEach((items, k) => {
    const from = k ? groups[k - 1].at(-1).end : 0;
    if (k || newlines(0, items[0].start)) gap(from, items[0], { kept: 0, indent: 0, force: false });
    form(items);
  });
  lineBreak(newlines(groups.at(-1)?.at(-1).end ?? 0, text.length), 0);
  return out;
}

// format, keeping the selection on the same characters.
export function formatSelection(text, selection, width) {
  const formatted = format(text, width);
  if (formatted === null) return null;
  return { text: formatted, selection: { start: carry(text, formatted, selection.start), end: carry(text, formatted, selection.end) } };
}

// The top-level form at `pos` formatted, the rest of the text as it is; or
// null if there is no form there or it has a fault.
export function formatForm(text, selection, width) {
  const form = forms(text).find((f) => f.start <= selection.start && selection.start <= f.end);
  if (!form) return null;
  const start = text.lastIndexOf("\n", form.start - 1) + 1;
  const from = /^[ \t]*$/.test(text.slice(start, form.start)) ? start : form.start;
  const formatted = formatSelection(text.slice(from, form.end), { start: selection.start - from, end: selection.end - from }, width);
  if (!formatted) return null;
  return {
    text: text.slice(0, from) + formatted.text + text.slice(form.end),
    selection: { start: formatted.selection.start + from, end: formatted.selection.end + from },
  };
}

// The offset in `after` of the character at `pos` in `before`, the two
// differing only in space: the same count of other characters precede it.
function carry(before, after, pos) {
  let count = before.slice(0, pos).replace(/\s/g, "").length;
  let i = 0;
  for (; i < after.length && count > 0; i++) if (!/\s/.test(after[i])) count--;
  return i;
}
