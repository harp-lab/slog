// The top-level forms of Slog source, found the way compiler/parser.rkt
// finds them: forms are not parenthesized, a form starts at a top-level
// keyword appearing at bracket depth 0 and runs to the next one
// (parser.rkt `top-level-keywords`, lexer.js for the token rules).

import { tokens } from "./lexer.js";

export const KEYWORDS = new Set([
  "def", "rule", "enum", "table", "struct", "union", "demand", "extern",
  "lattice", "include", "instantiate", "run", "let", "import", "export",
]);

// [{ keyword, line, column, endLine, start, end }]: lines and columns
// 1-based, `start` and `end` offsets into the text. `line` and `column` are
// the keyword's, which is where the compiler locates the form
// (rule-location-string); the form's text runs from `start`, the keyword,
// to `end`, the next form's keyword or the end of the text.
export function forms(text) {
  const lineAt = lineIndex(text);
  const found = [];
  let depth = 0;
  for (const token of tokens(text)) {
    if (token.kind === "open") depth++;
    else if (token.kind === "close") depth = Math.max(0, depth - 1);
    else if (token.kind === "word" && depth === 0 && KEYWORDS.has(text.slice(token.start, token.end))) {
      const { line, column } = lineAt(token.start);
      const previous = found.at(-1);
      if (previous) {
        previous.end = token.start;
        previous.endLine = endOfPrevious(previous, line);
      }
      found.push({ keyword: text.slice(token.start, token.end), line, column, endLine: line, start: token.start, end: text.length });
    }
  }
  if (found.length) {
    const last = lineAt(text.length).line - (text.endsWith("\n") ? 1 : 0);
    found.at(-1).endLine = Math.max(found.at(-1).line, last);
  }
  return found;
}

// A form ends on the line before the next form starts, or on that line if
// both share it.
function endOfPrevious(form, nextLine) {
  return Math.max(form.line, nextLine - 1);
}

// The form whose lines include `line`, or null.
export function formAt(found, line) {
  return found.find((form) => form.line <= line && line <= form.endLine) ?? null;
}

// offset -> { line, column }, both 1-based.
export function lineIndex(text) {
  const starts = [0];
  for (let i = 0; i < text.length; i++) if (text[i] === "\n") starts.push(i + 1);
  return (offset) => {
    let low = 0;
    let high = starts.length - 1;
    while (low < high) {
      const mid = (low + high + 1) >> 1;
      if (starts[mid] <= offset) low = mid; else high = mid - 1;
    }
    return { line: low + 1, column: offset - starts[low] + 1 };
  };
}
