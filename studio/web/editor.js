// The program editor: Monaco when its loader is reachable, else a textarea.
// Both offer the same small interface:
//   show(key, text)         switch to document `key` (made on first use) holding `text`;
//                           each document keeps its own undo, cursor and scroll
//   forget(key)             drop document `key`
//   get() / set(text)       the shown text; set keeps the cursor and does not fire onChange
//   mark(span, message)     underline a 1-based position, or clear every mark with null
//   reveal(span)            put the cursor at a position
//   onReplaced(listener)    call listener after set() replaced the text
//   replacing()             whether set() is replacing the text now
//   notes(notes)            hold each { line, text }, a hint for its line
//   context()               { line, notes }: the cursor's line, and the notes
//                           at the lines they have moved to (hints.js shows them)
//   cursorTop()             the cursor line's top in pixels from the editor's, or null
//   onMove(listener)        call listener when the cursor, the scroll or the notes change
//   focus()                 put the keyboard here
//   findings(findings)      mark each { line, severity, message } (analyzer)
//   diagnostics(key, list)  mark document `key`'s static-check diagnostics,
//                           each { line, col, severity, message, located }
//   keyOf(model), keyOfUri(uri), uriOf(key)
//                           a document's key and its model's URI, for the
//                           providers that point into documents (check.js)
//   markers(key, owner, list)  set `owner`'s markers on document `key` (lint.js)
//   highlight(ranges)       shade these [{ from, to }] line ranges (trace.js:
//                           the rules that fired), or none
// `readOnly: true` makes an editor for looking only. `raw` is { monaco,
// editor } for Monaco, else null.

import { bindMonaco, bindTextarea } from "./paredit.js";

const MONACO = "https://cdnjs.cloudflare.com/ajax/libs/monaco-editor/0.45.0/min/vs";

export async function createEditor(element, handlers) {
  const monaco = await loadMonaco();
  return monaco ? monacoEditor(monaco, element, handlers) : textareaEditor(element, handlers);
}

function loadMonaco() {
  return new Promise((resolve) => {
    if (typeof window.require !== "function") return resolve(null);
    const timer = setTimeout(() => resolve(null), 10000);
    window.require.config({ paths: { vs: MONACO } });
    window.require(
      ["vs/editor/editor.main"],
      () => { clearTimeout(timer); resolve(window.monaco); },
      () => { clearTimeout(timer); resolve(null); },
    );
  });
}

// Top-level keywords (compiler/parser.rkt `top-level-keywords`) and the
// words that structure their bodies.
const KEYWORDS = [
  "def", "rule", "enum", "table", "struct", "union", "demand", "extern", "lattice",
  "include", "instantiate", "run", "let", "import", "export", "as", "with", "when",
];

const SLOG = {
  keywords: KEYWORDS,
  tokenizer: {
    root: [
      [/;;.*$/, "comment"],
      [/"/, "string", "@string"],
      [/-->|<--|~/, "operator"],
      // the head of an atom: a relation or constructor name
      [/(\()(\s*)([A-Za-z_][\w'.]*)/, ["@brackets", "", { cases: { "@keywords": "keyword", "@default": "type" } }]],
      [/-?\d+(\.\d+)?/, "number"],
      [/[A-Za-z_][\w']*/, { cases: { "@keywords": "keyword", "@default": "identifier" } }],
      [/[()[\]{}]/, "@brackets"],
    ],
    string: [
      [/[^\\"]+/, "string"],
      [/\\./, "string.escape"],
      [/"/, "string", "@pop"],
    ],
  },
};

function monacoEditor(monaco, element, { onChange, onEvaluate, onSave, readOnly = false }) {
  monaco.languages.register({ id: "slog" });
  monaco.languages.setMonarchTokensProvider("slog", SLOG);
  monaco.languages.setLanguageConfiguration("slog", {
    comments: { lineComment: ";;" },
    brackets: [["(", ")"], ["[", "]"], ["{", "}"]],
    autoClosingPairs: [{ open: "(", close: ")" }, { open: "[", close: "]" }, { open: "\"", close: "\"" }],
  });
  monaco.editor.defineTheme("slog-light", {
    base: "vs",
    inherit: true,
    rules: [
      { token: "keyword", foreground: "859900" },
      { token: "type", foreground: "b58900" },
      { token: "operator", foreground: "cb4b16" },
      { token: "string", foreground: "2aa198" },
      { token: "number", foreground: "d33682" },
      { token: "comment", foreground: "93a1a1", fontStyle: "italic" },
    ],
    colors: {
      "editor.background": "#fdf6e3",
      "editor.foreground": "#657b83",
      "editor.lineHighlightBackground": "#eee8d5",
      "editorLineNumber.foreground": "#93a1a1",
    },
  });
  const editor = monaco.editor.create(element, {
    language: "slog",
    theme: "slog-light",
    automaticLayout: true,
    minimap: { enabled: false },
    folding: false,
    quickSuggestions: false,
    scrollBeyondLastLine: false,
    wordWrap: "bounded",
    wordWrapColumn: 100,
    fontFamily: "\"JetBrains Mono\", \"SF Mono\", Menlo, Consolas, monospace",
    fontSize: 14,
    glyphMargin: true,
    readOnly,
  });
  const current = () => editor.getModel();
  const documents = new Map(); // key -> { model, view }
  let shown = null;
  let quiet = false;
  // The summary's one-liner per form, as decorations that show nothing but
  // move with the text; hints.js shows them, out of the code.
  const notes = editor.createDecorationsCollection([]);
  let noteTexts = [];
  const movers = new Set();
  const moved = () => { for (const listener of movers) listener(); };
  editor.onDidChangeCursorPosition(moved);
  editor.onDidScrollChange(moved);

  const fired = editor.createDecorationsCollection([]);
  const replaced = new Set();
  // A document's model is named by its key, so a definition can point
  // into another file. (Only the program's editor: a model's name is
  // global, and a viewer shows the same files.)
  const uriOf = (key) => (readOnly ? undefined : monaco.Uri.from({ scheme: "studio", path: `/${key}` }));
  const keyOfUri = (uri) => (uri?.scheme === "studio" ? uri.path.slice(1) : null);

  editor.onDidChangeModelContent(() => {
    if (quiet) return;
    onChange();
  });
  editor.addCommand(monaco.KeyMod.CtrlCmd | monaco.KeyCode.Enter, onEvaluate);
  editor.addCommand(monaco.KeyMod.CtrlCmd | monaco.KeyCode.KeyS, onSave);
  bindMonaco(monaco, editor); // structured editing and completion (paredit.js)
  return {
    // Hook: the Monaco editor itself, for what draws over it (inline-diff.js).
    raw: { monaco, editor },
    show(key, text) {
      if (key !== shown) {
        if (documents.has(shown)) documents.get(shown).view = editor.saveViewState();
        if (!documents.has(key)) documents.set(key, { model: monaco.editor.createModel(text, "slog", uriOf(key)), view: null });
        const { model, view } = documents.get(key);
        quiet = true;
        editor.setModel(model);
        quiet = false;
        if (view) editor.restoreViewState(view);
        shown = key;
      }
      this.set(text);
    },
    forget(key) {
      documents.get(key)?.model.dispose();
      documents.delete(key);
      if (shown === key) shown = null;
    },
    get: () => current().getValue(),
    set(text) {
      if (current().getValue() === text) return;
      const selection = editor.getSelection();
      quiet = true;
      // An edit operation, not setValue, so undo can step back over it.
      current().pushEditOperations([], [{ range: current().getFullModelRange(), text }], () => null);
      // Notes and findings cannot be mapped onto a replaced text.
      notes.clear();
      noteTexts = [];
      monaco.editor.setModelMarkers(current(), "analyzer", []);
      quiet = false;
      if (selection) editor.setSelection(selection);
      // Replacing the whole text collapses every decoration onto its
      // start: whoever keeps some puts them back.
      for (const listener of replaced) listener();
    },
    mark(span, message) {
      if (!span) {
        for (const { model } of documents.values()) monaco.editor.setModelMarkers(model, "slog", []);
        monaco.editor.setModelMarkers(current(), "slog", []);
        return;
      }
      monaco.editor.setModelMarkers(current(), "slog", [{
        startLineNumber: span.line,
        startColumn: span.col,
        endLineNumber: span.line,
        endColumn: (current().getWordAtPosition({ lineNumber: span.line, column: span.col })?.endColumn) ?? span.col + 1,
        message,
        severity: monaco.MarkerSeverity.Error,
      }]);
    },
    reveal(span) {
      editor.revealLineInCenter(span.line);
      editor.setPosition({ lineNumber: span.line, column: span.col });
      editor.focus();
    },
    onReplaced: (listener) => replaced.add(listener),
    replacing: () => quiet,
    notes(list) {
      const kept = list.filter(({ line }) => line <= current().getLineCount()).sort((a, b) => a.line - b.line);
      noteTexts = kept.map(({ text }) => text);
      // The whole line, not an empty range at its end: a collapsed
      // decoration shows no injected text.
      notes.set(kept.map(({ line }) => ({ range: new monaco.Range(line, 1, line, current().getLineMaxColumn(line)), options: {} })));
      moved();
    },
    context: () => ({
      line: editor.getPosition()?.lineNumber ?? 1,
      notes: notes.getRanges().map((range, i) => ({ line: range.startLineNumber, text: noteTexts[i] })),
    }),
    cursorTop() {
      const at = editor.getPosition();
      return at && (editor.getScrolledVisiblePosition(at)?.top ?? null);
    },
    onMove: (listener) => movers.add(listener),
    focus: () => editor.focus(),
    findings(list) {
      const severity = { error: "Error", warning: "Warning", info: "Info" };
      monaco.editor.setModelMarkers(current(), "analyzer", list
        .filter(({ line }) => line <= current().getLineCount())
        .map(({ line, severity: level, message }) => ({
          startLineNumber: line,
          startColumn: current().getLineFirstNonWhitespaceColumn(line) || 1,
          endLineNumber: line,
          endColumn: current().getLineMaxColumn(line),
          message,
          severity: monaco.MarkerSeverity[severity[level]],
          source: "analyzer",
        })));
    },
    diagnostics(key, list) {
      const model = documents.get(key)?.model;
      if (!model) return;
      const severity = { error: "Error", warning: "Warning" };
      const lines = model.getLineCount();
      monaco.editor.setModelMarkers(model, "check", list.map(({ line, col, severity: level, message, located }) => {
        const at = Math.min(Math.max(line, 1), lines);
        const word = located && model.getWordAtPosition({ lineNumber: at, column: col });
        return {
          startLineNumber: at,
          startColumn: located ? col : 1,
          endLineNumber: at,
          // the word there, else the bracket or character there
          endColumn: located ? (word?.endColumn ?? col + 1) : model.getLineMaxColumn(at),
          message,
          severity: monaco.MarkerSeverity[severity[level] ?? "Error"],
          source: "check",
        };
      }));
    },
    keyOf: (model) => keyOfUri(model?.uri),
    keyOfUri,
    uriOf,
    // Markers of `owner` on document `key`, each { line, col, severity,
    // message, code, source }: an underline of the word at its column.
    markers(key, owner, list) {
      const model = documents.get(key)?.model;
      if (!model) return;
      monaco.editor.setModelMarkers(model, owner, list
        .filter(({ line }) => line >= 1 && line <= model.getLineCount())
        .map(({ line, col, severity: level, message, code, source }) => {
          const column = Math.min(Math.max(1, col), model.getLineMaxColumn(line));
          const word = model.getWordAtPosition({ lineNumber: line, column });
          return {
            startLineNumber: line,
            startColumn: word?.startColumn ?? column,
            endLineNumber: line,
            endColumn: word?.endColumn ?? Math.min(column + 1, model.getLineMaxColumn(line)),
            message,
            code,
            source,
            severity: monaco.MarkerSeverity[level],
          };
        }));
    },
    highlight(ranges) {
      fired.set(ranges.map(({ from, to }) => ({
        range: new monaco.Range(from, 1, to, 1),
        options: { isWholeLine: true, className: "fired-rule", linesDecorationsClassName: "fired-rule-margin" },
      })));
      if (ranges.length) editor.revealLinesInCenterIfOutsideViewport(ranges[0].from, ranges[0].to);
    },
  };
}

// The fallback has no margin: breakpoints, notes and findings need the
// Monaco editor. Nor does it keep undo per document.
function textareaEditor(element, { onChange, onEvaluate, onSave, readOnly = false }) {
  const area = document.createElement("textarea");
  area.spellcheck = false;
  area.readOnly = readOnly;
  let shown = null;
  element.append(area);
  area.addEventListener("input", onChange);
  bindTextarea(area); // structured editing (paredit.js)
  area.addEventListener("keydown", (event) => {
    if (!(event.metaKey || event.ctrlKey)) return;
    if (event.key === "Enter") { event.preventDefault(); onEvaluate(); }
    if (event.key === "s") { event.preventDefault(); onSave(); }
  });
  const offset = ({ line, col }) => {
    const lines = area.value.split("\n");
    return lines.slice(0, line - 1).reduce((sum, text) => sum + text.length + 1, 0) + col - 1;
  };
  return {
    raw: null, // nothing draws over a textarea
    show(key, text) {
      if (key !== shown) {
        area.value = text;
        area.setSelectionRange(0, 0);
        shown = key;
      }
      this.set(text);
    },
    forget(key) {
      if (shown === key) shown = null;
    },
    get: () => area.value,
    set(text) {
      if (area.value === text) return;
      const { selectionStart, selectionEnd } = area;
      area.value = text;
      area.setSelectionRange(selectionStart, selectionEnd);
    },
    mark(span, message) { area.title = span ? `${span.line}:${span.col}: ${message}` : ""; },
    reveal(span) {
      area.focus();
      area.setSelectionRange(offset(span), offset(span) + 1);
    },
    onReplaced() {},
    replacing: () => false,
    notes() {},
    context: () => ({ line: area.value.slice(0, area.selectionStart).split("\n").length, notes: [] }),
    cursorTop: () => null,
    onMove(listener) {
      for (const type of ["keyup", "click"]) area.addEventListener(type, listener);
    },
    focus: () => area.focus(),
    findings() {},
    markers() {},
    keyOf: () => undefined,
    highlight() {},
  };
}
