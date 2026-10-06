// The token rules of compiler/lexer.rkt, as far as the studio needs them:
// where comments, strings, refs and brackets are, so that a bracket inside a
// string or comment is never taken for structure.
//
//   ;;…            a comment, to the end of the line
//   "…"            a string; it may span lines, a backslash escapes the next
//                  character
//   '…'            a ref; single line, and only at a token start: inside an
//                  identifier (x') the quote is part of the identifier
//   ( ) [ ] { }    brackets
//   a word         any other run of non-space characters: an identifier
//                  [A-Za-z0-9_][A-Za-z0-9_']*, a number, or an operator
//                  such as --> or #:floor
//
// The lexer splits a word like `#1` or `?count` into several tokens; for
// editing it is one unit, so here it is one word.
//
// A string or ref with no closing quote runs to the end of the text (or of
// the line, for a ref) and is marked `open`, so a half-typed program still
// tokenizes.

const IDENT = /[A-Za-z0-9_']/;
const SPACE = /\s/;

export const OPENERS = "([{";
export const CLOSERS = ")]}";
export const closerOf = (open) => CLOSERS[OPENERS.indexOf(open)];

// [{ kind, start, end, open? }], kind one of "comment", "string", "ref",
// "open", "close" and "word"; whitespace is not a token.
export function tokens(text) {
  const found = [];
  let i = 0;
  while (i < text.length) {
    const c = text[i];
    const start = i;
    if (SPACE.test(c)) {
      i++;
      continue;
    }
    if (c === ";" && text[i + 1] === ";") {
      while (i < text.length && text[i] !== "\n") i++;
      found.push({ kind: "comment", start, end: i });
    } else if (c === "\"") {
      const { end, closed } = quoted(text, i, "\"", false);
      found.push({ kind: "string", start, end, open: !closed });
      i = end;
    } else if (c === "'") {
      const { end, closed } = quoted(text, i, "'", true);
      found.push({ kind: "ref", start, end, open: !closed });
      i = end;
    } else if (OPENERS.includes(c)) {
      found.push({ kind: "open", start, end: ++i });
    } else if (CLOSERS.includes(c)) {
      found.push({ kind: "close", start, end: ++i });
    } else {
      i = wordEnd(text, i);
      found.push({ kind: "word", start, end: i });
    }
  }
  return found;
}

// The end of the string or ref whose opening quote is at `i`, and whether
// a closing quote ends it.
function quoted(text, i, quote, singleLine) {
  for (i++; i < text.length && text[i] !== quote; i += text[i] === "\\" ? 2 : 1) {
    if (singleLine && text[i] === "\n") return { end: i, closed: false };
  }
  return i < text.length ? { end: i + 1, closed: true } : { end: text.length, closed: false };
}

// A word stops at space, a bracket, a quote, a comment, or a ' that starts a
// ref (one not preceded by an identifier character).
function wordEnd(text, i) {
  for (; i < text.length; i++) {
    const c = text[i];
    if (SPACE.test(c) || OPENERS.includes(c) || CLOSERS.includes(c) || c === "\"") break;
    if (c === ";" && text[i + 1] === ";") break;
    if (c === "'" && !IDENT.test(text[i - 1])) break;
  }
  return i;
}

// Whether a word is a name: an identifier that is not a number. Variables,
// relations and keywords are names.
export const isName = (word) => /^[A-Za-z_][A-Za-z0-9_']*$/.test(word);
