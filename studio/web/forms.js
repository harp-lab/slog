// The top-level forms of Slog source, found the way compiler/parser.rkt
// finds them: forms are not parenthesized, a form starts at a top-level
// keyword appearing at bracket depth 0 and runs to the next one
// (parser.rkt `top-level-keywords`, lexer.rkt for the token rules).

const KEYWORDS = new Set([
  "def", "rule", "enum", "table", "struct", "union", "demand", "extern",
  "lattice", "include", "instantiate", "run", "let", "import", "export",
]);

// [{ keyword, line, column, endLine }], lines and columns 1-based; `line`
// and `column` are the keyword's, which is where the compiler locates the
// form (rule-location-string).
export function forms(text) {
  const found = [];
  let line = 1;
  let column = 1;
  let depth = 0;
  let i = 0;
  const advance = (n = 1) => {
    for (let k = 0; k < n && i < text.length; k++, i++) {
      if (text[i] === "\n") { line++; column = 1; } else column++;
    }
  };
  while (i < text.length) {
    const c = text[i];
    if (c === ";" && text[i + 1] === ";") {
      while (i < text.length && text[i] !== "\n") advance();
    } else if (c === "\"") {
      // strings may span lines; a backslash escapes the next character
      advance();
      while (i < text.length && text[i] !== "\"") advance(text[i] === "\\" ? 2 : 1);
      advance();
    } else if (c === "'") {
      // a ref token: quoted, single line, at a token start
      advance();
      while (i < text.length && text[i] !== "'" && text[i] !== "\n") advance(text[i] === "\\" ? 2 : 1);
      advance();
    } else if ("([{".includes(c)) {
      depth++;
      advance();
    } else if (")]}".includes(c)) {
      depth = Math.max(0, depth - 1);
      advance();
    } else if (/[A-Za-z0-9_]/.test(c)) {
      // an identifier, which may contain ' after its first character
      const start = { line, column };
      let word = "";
      while (i < text.length && /[A-Za-z0-9_']/.test(text[i])) { word += text[i]; advance(); }
      if (depth === 0 && KEYWORDS.has(word)) {
        if (found.length) found.at(-1).endLine = endOfPrevious(found.at(-1), start.line);
        found.push({ keyword: word, line: start.line, column: start.column, endLine: start.line });
      }
    } else {
      advance();
    }
  }
  if (found.length) found.at(-1).endLine = Math.max(found.at(-1).line, line - (text.endsWith("\n") ? 1 : 0));
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
