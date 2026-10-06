// The usual Emacs keys, for the editor and the REPL prompt, as operations
// `(text, selection) -> { text, selection }` like sexp.js's paredit ones;
// paredit.js binds both. The structural keys (C-M-f and the like, and C-k
// in structured mode) are paredit's.
//
// C-a, C-e, C-f, C-b, C-n, C-p, C-d, C-h and C-t need nothing here: the
// Mac binds them in Monaco and in every textarea.
//
// Kills go to a one-entry kill ring shared by every editor on the page, and
// to the clipboard; kills in a row (nothing typed or moved between them)
// add to the entry, as in Emacs, and C-y yanks it.

const word = (c) => /[\p{L}\p{N}_]/u.test(c);

export function forwardWord(text, at) {
  while (at < text.length && !word(text[at])) at++;
  while (at < text.length && word(text[at])) at++;
  return at;
}

export function backwardWord(text, at) {
  while (at > 0 && !word(text[at - 1])) at--;
  while (at > 0 && word(text[at - 1])) at--;
  return at;
}

const lineEnd = (text, at) => (text.indexOf("\n", at) + 1 || text.length + 1) - 1;
const caret = (at) => ({ start: at, end: at });
const moved = (text, at) => ({ text, selection: caret(at) });

// The kill ring. `after` is the text and caret the last kill left: a kill
// from exactly there continues it.
export const ring = { text: "", after: null, copy: (text) => {} };

function kill(text, from, to, backward) {
  if (from === to) return null;
  const piece = text.slice(from, to);
  const chained = ring.after?.text === text && ring.after.at === (backward ? to : from);
  ring.text = !chained ? piece : backward ? piece + ring.text : ring.text + piece;
  const result = moved(text.slice(0, from) + text.slice(to), from);
  ring.after = { text: result.text, at: from };
  ring.copy(ring.text);
  return result;
}

function replaceWord(text, at, change) {
  const end = forwardWord(text, at);
  return moved(text.slice(0, at) + change(text.slice(at, end)) + text.slice(end), end);
}

// Each takes the text and selection and gives the result, or null to leave
// the key to the editor. A selection counts from its end, the caret.
export const EMACS = {
  backwardWord: (text, { end }) => moved(text, backwardWord(text, end)),
  forwardWord: (text, { end }) => moved(text, forwardWord(text, end)),
  beginningOfBuffer: (text) => moved(text, 0),
  endOfBuffer: (text) => moved(text, text.length),
  killWord: (text, { end }) => kill(text, end, forwardWord(text, end), false),
  backwardKillWord: (text, { end }) => kill(text, backwardWord(text, end), end, true),
  // to the end of the line, or the line break itself at the end
  killLine: (text, { end }) => {
    const to = lineEnd(text, end);
    return kill(text, end, to === end ? Math.min(end + 1, text.length) : to, false);
  },
  killRegion: (text, { start, end }) => (start === end ? null : kill(text, start, end, false)),
  copyRegion: (text, { start, end }) => {
    if (start === end) return null;
    ring.text = text.slice(start, end);
    ring.after = null;
    ring.copy(ring.text);
    return moved(text, end);
  },
  yank: (text, { start, end }) => {
    if (!ring.text) return null;
    ring.after = null;
    return moved(text.slice(0, start) + ring.text + text.slice(end), start + ring.text.length);
  },
  upcaseWord: (text, { end }) => replaceWord(text, end, (w) => w.toUpperCase()),
  downcaseWord: (text, { end }) => replaceWord(text, end, (w) => w.toLowerCase()),
  capitalizeWord: (text, { end }) => replaceWord(text, end, (w) => {
    const first = w.search(/[\p{L}\p{N}_]/u);
    return first < 0 ? w : w.slice(0, first) + w[first].toUpperCase() + w.slice(first + 1).toLowerCase();
  }),
  // a line break after the caret, which stays
  openLine: (text, { start, end }) => moved(text.slice(0, start) + "\n" + text.slice(end), start),
  deleteHorizontalSpace: (text, { end }) => {
    let from = end;
    let to = end;
    while (from > 0 && " \t".includes(text[from - 1])) from--;
    while (to < text.length && " \t".includes(text[to])) to++;
    return from === to ? null : moved(text.slice(0, from) + text.slice(to), from);
  },
};

// The keys, by position (event.code), as in paredit.js. Ctrl is Control;
// those keys are bound only on a Mac, where Control is free of the
// system's own shortcuts (elsewhere Ctrl-A selects all, Ctrl-W closes the
// tab). `structured: false` gives a key to paredit in structured mode.
// The editor-only keys name a Monaco action instead of an operation.
export const EMACS_KEYS = [
  ["backwardWord", ["Alt-B"]],
  ["forwardWord", ["Alt-F"]],
  ["beginningOfBuffer", ["Alt-Shift-Comma"]],
  ["endOfBuffer", ["Alt-Shift-Period"]],
  ["killWord", ["Alt-D"]],
  ["backwardKillWord", ["Alt-Backspace"]],
  ["upcaseWord", ["Alt-U"]],
  ["downcaseWord", ["Alt-L"]],
  ["capitalizeWord", ["Alt-C"]],
  ["copyRegion", ["Alt-W"]],
  ["deleteHorizontalSpace", ["Alt-Backslash"]],
  ["killLine", ["Ctrl-K"], { mac: true, structured: false }],
  ["killRegion", ["Ctrl-W"], { mac: true }],
  ["yank", ["Ctrl-Y"], { mac: true }],
  ["openLine", ["Ctrl-O"], { mac: true }],
  // Monaco's own actions, in the program editor
  ["undo", ["Ctrl-/", "Ctrl-Shift-Minus"], { mac: true, monaco: "undo" }],
  ["find", ["Ctrl-S"], { mac: true, monaco: "actions.find" }],
  ["findBackward", ["Ctrl-R"], { mac: true, monaco: "actions.find" }],
  ["pageDown", ["Ctrl-V"], { mac: true, monaco: "cursorPageDown" }],
  ["pageUp", ["Alt-V"], { monaco: "cursorPageUp" }],
  ["keyboardQuit", ["Ctrl-G"], { mac: true, monaco: ["hideSuggestWidget", "closeFindWidget", "cancelSelection"] }],
];
