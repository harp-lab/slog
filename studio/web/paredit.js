// Structured editing and completion in the browser: sexp.js's paredit
// operations bound to keys, format.js's formatter, and completion from
// complete.js and commands.js, in the Monaco program editor and in plain
// textareas (the REPL prompt, and the editor's fallback).
//
// The hooks, from editor.js and main.js:
//   bindMonaco(monaco, editor)     the program editor
//   bindTextarea(area)             a textarea's keys (the fallback editor)
//   bindPrompt(area, { files })    the REPL prompt, with completion;
//                                  `files()` the project's, path -> text
//   observe(entry)                 keep what a transcript entry, or the
//                                  snapshot's `tables`, says about live
//                                  state (the catalog after every Run)
//   setDatabases(names)            the saved databases, from the studio
//   mountControls()                structured mode and the key help, for
//                                  the command palette
//   keysAt(text, line)             the keys the Alt+H hints name there
//
// The same adapters bind emacs.js's Emacs keys, in structured mode or not.
//
// Structured mode (balanced typing and the paredit keys) is on unless
// turned off, and remembered in localStorage. Completion is always on.

import { paredit } from "./sexp.js";
import { format, formatForm } from "./format.js";
import { complete, expand } from "./complete.js";
import { catalogOf, completeCommand, declared, locations, observe as observed, signature, slogAt } from "./commands.js";
import { EMACS, EMACS_KEYS, noteKill, ring } from "./emacs.js";

// The bindings: [operation, chords, what it does]. A chord names keys by
// their position (event.code), so Alt does not change them on a Mac;
// Ctrl is the Control key on every platform.
const BINDINGS = [
  ["slurpForward", ["Ctrl-Shift-0", "Ctrl-Right"], "slurp: take the next expression into this list"],
  ["barfForward", ["Ctrl-Shift-]", "Ctrl-Left"], "barf: push this list's last expression out"],
  ["slurpBackward", ["Ctrl-Shift-9", "Ctrl-Alt-Left"], "slurp the previous expression in"],
  ["barfBackward", ["Ctrl-Shift-[", "Ctrl-Alt-Right"], "barf the first expression out"],
  ["splice", ["Alt-S"], "splice: remove this list's brackets"],
  ["raise", ["Alt-R"], "raise: replace this list with the expression here"],
  ["wrap", ["Alt-Shift-9"], "wrap the expression or selection in ( )"],
  ["wrapSquare", ["Alt-["], "wrap the expression or selection in [ ]"],
  ["split", ["Alt-Shift-S"], "split this list or string in two here"],
  ["join", ["Alt-Shift-J"], "join the lists or strings either side"],
  ["kill", ["Ctrl-K"], "delete to the end of this list"],
  ["expandSelection", ["Alt-Up"], "select the enclosing expression"],
  ["contractSelection", ["Alt-Down"], "select back down"],
  ["forwardSexp", ["Ctrl-Alt-F"], "forward over an expression"],
  ["backwardSexp", ["Ctrl-Alt-B"], "backward over an expression"],
  ["upList", ["Ctrl-Alt-U"], "out to this list's opener"],
  ["forwardUpList", ["Ctrl-Alt-N"], "out past this list's closer"],
  ["downList", ["Ctrl-Alt-D"], "into the next list"],
  ["formatForm", ["Ctrl-Alt-Q"], "format this form (Shift-Alt-F: the whole program)"],
];

// The operations the keys run, by name; each (text, selection) -> result.
const COMMANDS = {
  ...paredit,
  wrapSquare: (text, selection) => paredit.wrap(text, selection, "["),
  formatForm: (text, selection) => formatForm(text, selection) ?? { text, selection },
};

// Typing, in structured mode: key -> (text, selection) -> result or null.
const TYPING = {
  "(": (t, s) => paredit.insertOpen(t, s, "("),
  "[": (t, s) => paredit.insertOpen(t, s, "["),
  "{": (t, s) => paredit.insertOpen(t, s, "{"),
  ")": paredit.insertClose,
  "]": paredit.insertClose,
  "}": paredit.insertClose,
  "\"": (t, s) => paredit.insertQuote(t, s, "\""),
  "'": (t, s) => paredit.insertQuote(t, s, "'"),
  ";": paredit.insertSemicolon,
  Backspace: paredit.deleteBackward,
  Delete: paredit.deleteForward,
};

// The keys the Alt+H hints name, most useful first, with a word each: on a
// line with a list, the structural ones; anywhere, completion.
const HINTED = [["expandSelection", "select"], ["slurpForward", "slurp"], ["barfForward", "barf"], ["formatForm", "format"]];

// The hints for `line` (1-based) of `text`, most useful first.
export function keysAt(text, line) {
  const listy = /[([{]/.test(text.split("\n")[line - 1] ?? "");
  const chords = Object.fromEntries(BINDINGS.map(([name, keys]) => [name, keys.at(-1)]));
  const keys = structured.on && listy ? HINTED.map(([name, word]) => `${symbols(chords[name])} ${word}`) : [];
  return [...keys, `${symbols("Alt-/")} complete`];
}

// "Ctrl-Alt-Right" as ⌃⌥→ on a Mac, as it is elsewhere.
const symbols = (chord) => (MAC
  ? chord.replace(/Ctrl-/, "⌃").replace(/Alt-/, "⌥").replace(/Shift-/, "⇧")
    .replace(/Right$/, "→").replace(/Left$/, "←").replace(/Up$/, "↑").replace(/Down$/, "↓")
  : chord);

// Structured mode ------------------------------------------------------------

const STORED = "slog-studio.structured";
const structured = {
  on: (() => { try { return localStorage.getItem(STORED) !== "off"; } catch { return true; } })(),
  listeners: new Set(),
  set(on) {
    this.on = on;
    try { localStorage.setItem(STORED, on ? "on" : "off"); } catch { /* private mode */ }
    for (const listener of this.listeners) listener(on);
  },
};

// Live state ------------------------------------------------------------

// What the prompt can offer: the relations of each source catalogOf
// merges (`tables` the session's, `program` the project's declarations,
// `scratch` definitions typed at the prompt, `kept` result sets), and the
// rest completeCommand reads.
const live = {
  tables: [], program: [], scratch: [], kept: [], catalog: [],
  databases: [], locations: [], breaks: [], watches: [],
};

// The project's files, path -> text, from bindPrompt's caller.
let projectFiles = () => ({});

// The catalog, the program's declarations and rules read again when its
// text changed.
let read = null;
function refresh() {
  const files = projectFiles();
  const key = Object.entries(files).flat().join("\0");
  if (read !== key) {
    read = key;
    live.program = Object.entries(files).filter(([path]) => path.endsWith(".slog")).flatMap(([, text]) => declared(text));
    live.locations = locations(files);
  }
  return (live.catalog = catalogOf(live));
}

// A transcript entry, { result, line }: the session's relations, a
// scratch definition, the breaks and watches.
export function observe(entry) {
  const update = observed(entry, live);
  // the session's own listing holds the results it kept
  if (update?.tables) live.kept = [];
  Object.assign(live, update ?? {});
  live.catalog = catalogOf(live);
}

export function setDatabases(names) {
  live.databases = names;
}

// A relation the session gained since its last `tables`: a query's answers
// kept as r1, r2, … ({ name, arity, detail }). The next Run's catalog
// replaces it, as it replaces the session.
export function addRelation(relation) {
  live.kept = [...live.kept.filter((known) => known.name !== relation.name), { ...relation, kind: "result" }];
  live.catalog = catalogOf(live);
}

// Chords ---------------------------------------------------------------

export const MAC = /Mac|iPhone|iPad/.test(navigator.platform);

// The kill ring's text also goes to the clipboard, for Cmd-V and other apps.
ring.copy = (text) => navigator.clipboard?.writeText(text).catch(() => {});

// The Emacs keys this platform binds (emacs.js), with their options.
const EMACS_BOUND = EMACS_KEYS
  .map(([name, chords, options = {}]) => ({ name, chords, ...options }))
  .filter((key) => !key.mac || MAC);

// "Ctrl-Alt-F" for a keydown, naming the key by its position.
const PUNCTUATION = { BracketLeft: "[", BracketRight: "]", Slash: "/" };
function chord(event) {
  const key = PUNCTUATION[event.code] ?? event.code.replace(/^Key|^Digit|^Arrow/, "");
  return [event.ctrlKey && "Ctrl", event.altKey && "Alt", event.shiftKey && "Shift", event.metaKey && "Meta", key]
    .filter(Boolean).join("-");
}

// A chord as a Monaco keybinding.
function keybinding(monaco, text) {
  const { KeyMod, KeyCode } = monaco;
  const parts = text.split("-");
  const key = parts.pop();
  const modifiers = { Ctrl: MAC ? KeyMod.WinCtrl : KeyMod.CtrlCmd, Alt: KeyMod.Alt, Shift: KeyMod.Shift };
  const code = /^\d$/.test(key) ? KeyCode[`Digit${key}`]
    : /^[A-Z]$/.test(key) ? KeyCode[`Key${key}`]
      : { "[": KeyCode.BracketLeft, "]": KeyCode.BracketRight, "/": KeyCode.Slash }[key] ?? KeyCode[key] ?? KeyCode[`${key}Arrow`];
  return parts.reduce((binding, part) => binding | modifiers[part], code);
}

// The one replacement turning `before` into `after`: { start, end, insert }.
function difference(before, after) {
  let start = 0;
  while (start < before.length && start < after.length && before[start] === after[start]) start++;
  let tail = 0;
  while (tail < before.length - start && tail < after.length - start
    && before[before.length - 1 - tail] === after[after.length - 1 - tail]) tail++;
  return { start, end: before.length - tail, insert: after.slice(start, after.length - tail) };
}

// Monaco ---------------------------------------------------------------

export function bindMonaco(monaco, editor) {
  // the model shown: the editor switches between one per file
  const model = () => editor.getModel();
  const offset = (position) => model().getOffsetAt(position);
  const position = (at) => model().getPositionAt(at);
  const current = () => {
    const s = editor.getSelection();
    return { text: model().getValue(), selection: { start: offset(s.getStartPosition()), end: offset(s.getEndPosition()) } };
  };
  const readOnly = () => editor.getOption(monaco.editor.EditorOption.readOnly);
  const apply = (before, result) => {
    if (result.text !== before) {
      if (readOnly()) return;
      const { start, end, insert } = difference(before, result.text);
      editor.pushUndoStop();
      editor.executeEdits("paredit", [{ range: monaco.Range.fromPositions(position(start), position(end)), text: insert }]);
      editor.pushUndoStop();
    }
    editor.setSelection(monaco.Selection.fromPositions(position(result.selection.start), position(result.selection.end)));
    editor.revealPosition(position(result.selection.end));
  };
  const run = (operation) => {
    const { text, selection } = current();
    const result = operation(text, selection);
    if (result) apply(text, result);
    return result;
  };

  const on = editor.createContextKey("slogStructured", structured.on);
  structured.listeners.add((value) => on.set(value));

  // Growing the selection keeps a history, so shrinking retraces it.
  const grown = [];
  for (const [name, chords, about] of BINDINGS) {
    editor.addAction({
      id: `slog.${name}`,
      label: `Structure: ${about}`,
      keybindings: chords.map((text) => keybinding(monaco, text)),
      precondition: "slogStructured",
      run() {
        const { text, selection } = current();
        if (name === "contractSelection" && grown.length && same(grown.at(-1).after, selection)) {
          apply(text, { text, selection: grown.pop().before });
          return;
        }
        const result = COMMANDS[name](text, selection);
        if (name === "kill" && result) noteKill(text, selection, result);
        if (name === "expandSelection") grown.push({ before: selection, after: result.selection });
        else if (name !== "contractSelection") grown.length = 0;
        apply(text, result);
      },
    });
  }

  for (const key of EMACS_BOUND) {
    editor.addAction({
      id: `emacs.${key.name}`,
      label: `Emacs: ${key.name.replace(/[A-Z]/g, (c) => ` ${c.toLowerCase()}`)}`,
      keybindings: key.chords.map((text) => keybinding(monaco, text)),
      precondition: key.structured === false ? "!slogStructured" : undefined,
      run() {
        if (key.monaco) for (const id of [key.monaco].flat()) editor.trigger("emacs", id, {});
        else run(EMACS[key.name]);
      },
    });
  }

  editor.onKeyDown((event) => {
    const typing = TYPING[event.browserEvent.key];
    if (!structured.on || !typing || event.ctrlKey || event.metaKey || event.altKey
      || event.browserEvent.isComposing || editor.getSelections().length > 1 || readOnly()) return;
    if (!run(typing)) return;
    event.preventDefault();
    event.stopPropagation();
    // an opened list asks for a relation
    if ("([".includes(event.browserEvent.key) && complete(model().getValue(), offset(editor.getPosition()), refresh()).items.length) {
      editor.trigger("paredit", "editor.action.triggerSuggest", {});
    }
  });

  editor.updateOptions({ quickSuggestions: { other: true, comments: false, strings: false }, wordBasedSuggestions: "off" });
  // Ctrl-Space is Monaco's, and on a Mac often the input source switch
  editor.addCommand(monaco.KeyMod.Alt | monaco.KeyCode.Slash, () => editor.trigger("paredit", "editor.action.triggerSuggest", {}));
  registerLanguage(monaco);
}

// Completion and formatting serve every Slog model, so they are registered
// once however many editors there are.
let registered = false;
function registerLanguage(monaco) {
  if (registered) return;
  registered = true;
  const kinds = monaco.languages.CompletionItemKind;
  monaco.languages.registerCompletionItemProvider("slog", {
    triggerCharacters: ["(", "?", ">"],
    provideCompletionItems(model, at) {
      const { from, to, items } = complete(model.getValue(), model.getOffsetAt(at), refresh());
      const range = monaco.Range.fromPositions(model.getPositionAt(from), model.getPositionAt(to));
      return {
        suggestions: items.map((item, i) => ({
          label: item.label,
          detail: item.detail,
          kind: { relation: kinds.Function, variable: kinds.Variable, shape: kinds.Keyword, projection: kinds.Snippet }[item.kind],
          insertText: item.insert,
          insertTextRules: monaco.languages.CompletionItemInsertTextRule.InsertAsSnippet,
          sortText: String(i).padStart(4, "0"),
          range,
        })),
      };
    },
  });
  monaco.languages.registerDocumentFormattingEditProvider("slog", {
    provideDocumentFormattingEdits(model) {
      const text = model.getValue();
      const formatted = format(text);
      return formatted === null || formatted === text ? [] : [{ range: model.getFullModelRange(), text: formatted }];
    },
  });
}

const same = (a, b) => a.start === b.start && a.end === b.end;

// Textareas ------------------------------------------------------------

// Replace the textarea's text with `result`, as one edit undo can take
// back where the browser allows it.
function applyTo(area, result) {
  const before = area.value;
  if (result.text !== before) {
    const { start, end, insert } = difference(before, result.text);
    area.setSelectionRange(start, end);
    const done = insert ? document.execCommand("insertText", false, insert) : document.execCommand("delete");
    if (!done || area.value !== result.text) {
      area.value = result.text;
      area.dispatchEvent(new Event("input"));
    }
  }
  area.setSelectionRange(result.selection.start, result.selection.end);
}

export function bindTextarea(area) {
  area.addEventListener("keydown", structureKeys(area));
}

// A keydown handler for a textarea's paredit and Emacs keys, which says
// whether it took the key.
function structureKeys(area) {
  const commands = new Map(BINDINGS.flatMap(([name, chords]) => chords.map((text) => [text, name])));
  const emacs = new Map(EMACS_BOUND.filter((key) => !key.monaco).flatMap((key) => key.chords.map((text) => [text, key])));
  const grown = [];
  const keydown = (event) => {
    if (event.isComposing) return false;
    const text = area.value;
    const selection = { start: area.selectionStart, end: area.selectionEnd };
    const key = emacs.get(chord(event));
    if (key && (key.structured !== false || !structured.on)) {
      const result = EMACS[key.name](text, selection);
      if (!result) return false;
      event.preventDefault();
      applyTo(area, result);
      return true;
    }
    if (!structured.on) return false;
    const name = commands.get(chord(event));
    let result;
    if (name === "contractSelection" && grown.length && same(grown.at(-1).after, selection)) {
      result = { text, selection: grown.pop().before };
    } else if (name) {
      result = COMMANDS[name](text, selection);
      if (name === "kill" && result) noteKill(text, selection, result);
      if (name === "expandSelection") grown.push({ before: selection, after: result.selection });
    } else if (TYPING[event.key] && !event.ctrlKey && !event.metaKey && !event.altKey) {
      result = TYPING[event.key](text, selection);
    }
    if (!result) return false;
    event.preventDefault();
    applyTo(area, result);
    return true;
  };
  return keydown;
}

// The REPL prompt ----------------------------------------------------------

export function bindPrompt(area, { files }) {
  projectFiles = files;
  const menu = document.body.appendChild(Object.assign(document.createElement("ul"), { className: "completions", hidden: true }));
  const usage = document.body.appendChild(Object.assign(document.createElement("div"), { className: "signature", hidden: true }));
  let shown = null; // { from, to, items, index }
  let stops = null; // { at: [{ start, end }], index, length }: the snippet's tab stops
  let accepting = false;

  const close = () => { shown = null; menu.hidden = true; };
  const open = (explicit) => {
    refresh();
    const offer = completeCommand(area.value, area.selectionStart, live);
    const typed = area.value.slice(offer.from, area.selectionStart);
    // an exact, lone match has nothing more to say
    if (!offer.items.length || (!explicit && offer.items.length === 1 && offer.items[0].label === typed)) return close();
    shown = { ...offer, index: 0 };
    render();
  };
  const render = () => {
    menu.replaceChildren(...shown.items.map((item, i) => {
      const row = document.createElement("li");
      row.className = i === shown.index ? "chosen" : "";
      row.append(Object.assign(document.createElement("span"), { className: "label", textContent: item.label }));
      if (item.detail) row.append(Object.assign(document.createElement("span"), { className: "detail", textContent: item.detail }));
      row.addEventListener("mousedown", (event) => { event.preventDefault(); accept(i); });
      return row;
    }));
    menu.hidden = false;
    // above the prompt, at the word being completed
    const box = area.getBoundingClientRect();
    const style = getComputedStyle(area);
    const measure = document.createElement("canvas").getContext("2d");
    measure.font = style.font;
    const line = area.value.slice(area.value.lastIndexOf("\n", shown.from - 1) + 1, shown.from);
    menu.style.left = `${Math.min(box.left + parseFloat(style.paddingLeft) + measure.measureText(line).width, innerWidth - 320)}px`;
    menu.style.bottom = `${innerHeight - box.top + 4 + (usage.hidden ? 0 : usage.offsetHeight + 2)}px`;
    menu.children[shown.index]?.scrollIntoView({ block: "nearest" });
  };
  const accept = (i) => {
    const { from, to, items } = shown;
    const snippet = expand(items[i].insert);
    const text = area.value.slice(0, from) + snippet.text + area.value.slice(to);
    const at = snippet.stops.map(({ start, end }) => ({ start: start + from, end: end + from }));
    close();
    accepting = true;
    applyTo(area, { text, selection: at[0] });
    accepting = false;
    stops = at.length > 1 ? { at, index: 0, length: text.length } : null;
    // a command's word chosen, its arguments come next
    if (!stops && snippet.text.endsWith(" ")) open(false);
  };
  // The command's usage above the prompt, the argument at the cursor in bold.
  const describe = () => {
    const found = area.dataset.mode !== "ask" && document.activeElement === area
      ? signature(area.value, area.selectionStart) : null;
    usage.hidden = !found;
    if (!found) return;
    const bold = (text) => Object.assign(document.createElement("b"), { textContent: text });
    usage.replaceChildren(
      ...found.forms.flatMap(({ text, current }, i) => [
        ...(i ? ["  |  "] : []),
        ...(current ? [text.slice(0, current[0]), bold(text.slice(...current)), text.slice(current[1])] : [text]),
      ]),
      Object.assign(document.createElement("span"), { className: "about", textContent: `  —  ${found.about}` }),
    );
    const box = area.getBoundingClientRect();
    usage.style.left = `${box.left}px`;
    usage.style.maxWidth = `${box.width}px`;
    usage.style.bottom = `${innerHeight - box.top + 4}px`;
  };

  // Tab through a snippet's stops: typing in one moves those after it.
  const nextStop = () => {
    const shift = area.value.length - stops.length;
    stops.at = stops.at.map((stop, i) => (i > stops.index ? { start: stop.start + shift, end: stop.end + shift } : stop));
    stops.index++;
    stops.length = area.value.length;
    area.setSelectionRange(stops.at[stops.index].start, stops.at[stops.index].end);
    if (stops.index === stops.at.length - 1) stops = null;
  };

  const structure = structureKeys(area);
  area.addEventListener("keydown", (event) => {
    if (area.dataset.mode === "ask") return; // a question to the assistant (assist.js)
    const quit = event.ctrlKey && event.code === "KeyG"; // Emacs's C-g
    const keys = shown && quit ? close : shown && {
      ArrowDown: () => { shown.index = (shown.index + 1) % shown.items.length; render(); },
      ArrowUp: () => { shown.index = (shown.index + shown.items.length - 1) % shown.items.length; render(); },
      Enter: () => accept(shown.index),
      Tab: () => accept(shown.index),
      Escape: close,
    }[event.key];
    const snippet = !shown && stops && { Tab: nextStop, Escape: () => { stops = null; } }[event.key];
    const asked = (event.key === " " && event.ctrlKey) || (event.code === "Slash" && event.altKey);
    const handle = keys ?? snippet ?? (asked ? () => open(true) : null);
    if (handle && !event.shiftKey) {
      event.preventDefault();
      event.stopImmediatePropagation();
      handle();
      return;
    }
    if (event.key === "Enter") stops = null;
    // the paredit keys; the prompt's own (Enter, history) see the rest
    if (structure(event)) event.stopImmediatePropagation();
  }, { capture: true });

  // Typing a word, an opener, `?`, `->`, or the space after a command's
  // word opens the list; typing with it open narrows it. The usage follows
  // the cursor.
  area.addEventListener("input", (event) => {
    describe();
    if (area.dataset.mode === "ask") return close();
    if (accepting) return;
    const typed = event.data ?? "";
    const prompts = /[A-Za-z0-9_'.?>-]$/.test(typed) || typed.includes("(")
      || (typed === " " && !slogAt(area.value, area.selectionStart));
    // typing in a snippet's blank is not asking for completion
    if (shown || (event.inputType === "insertText" && prompts && !stops)) open(false);
  });
  for (const type of ["focus", "click", "keyup"]) area.addEventListener(type, describe);
  area.addEventListener("blur", () => { close(); usage.hidden = true; });
}

// Controls -------------------------------------------------------------

// Structured mode and the key help, for the command palette:
// { structured(), setStructured(on), showKeys() }.
export function mountControls() {
  const link = document.head.appendChild(document.createElement("link"));
  Object.assign(link, { rel: "stylesheet", href: "/static/structure.css" });
  const popover = document.body.appendChild(Object.assign(document.createElement("div"), { className: "key-help", hidden: true }));
  const rows = [
    ...BINDINGS.map(([, chords, about]) => [chords.join("  ·  "), about]),
    ["( [ { \"", "typed, a balanced pair; a closer moves past the list's end"],
    ["Backspace, Delete", "never unbalance: they step over a closer, or take an empty pair"],
    ["Ctrl-Space  ·  Alt-/", "complete; Tab or Enter takes it, then Tab moves between its blanks"],
    ["Shift-Alt-F", "format the whole program"],
  ];
  popover.append(Object.assign(document.createElement("h3"), { textContent: "Structured editing" }));
  const table = popover.appendChild(document.createElement("table"));
  for (const [keys, about] of rows) {
    const tr = table.appendChild(document.createElement("tr"));
    tr.append(Object.assign(document.createElement("td"), { className: "keys", textContent: keys }));
    tr.append(Object.assign(document.createElement("td"), { textContent: about }));
  }
  document.addEventListener("pointerdown", (event) => { if (!popover.contains(event.target)) popover.hidden = true; });
  document.addEventListener("keydown", (event) => { if (event.key === "Escape") popover.hidden = true; });
  return {
    structured: () => structured.on,
    setStructured: (on) => structured.set(on),
    showKeys() { popover.hidden = false; },
  };
}
