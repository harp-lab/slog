// The program editor: Monaco when its loader is reachable, else a textarea.
// Both offer the same small interface:
//   show(key, text)         switch to document `key` (made on first use) holding `text`;
//                           each document keeps its own undo, cursor and scroll
//   forget(key)             drop document `key`
//   get() / set(text)       the shown text; set keeps the cursor and does not fire onChange
//   mark(span, message)     underline a 1-based position, or clear every mark with null
//   reveal(span)            put the cursor at a position
//   setBreakpoints(lines)   show breakpoint dots on these 1-based lines
//   breakpoints()           the lines with a dot
//   notes(notes)            hold each { line, text }, a hint for its line
//   context()               { line, notes }: the cursor's line, and the notes
//                           at the lines they have moved to (hints.js shows them)
//   cursorTop()             the cursor line's top in pixels from the editor's, or null
//   onMove(listener)        call listener when the cursor, the scroll or the notes change
//   focus()                 put the keyboard here
//   findings(findings)      mark each { line, severity, message } (analyzer)
//   highlight(ranges)       shade these [{ from, to }] line ranges (trace.js:
//                           the rules that fired), or none
// `onBreakpoints(lines)` fires when a margin click or an edit changes them;
// `snapBreakpoint(line)` says which line a click on `line` marks, or null;
// `readOnly: true` makes an editor for looking only.

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

function monacoEditor(monaco, element, { onChange, onEvaluate, onSave, onBreakpoints, snapBreakpoint, readOnly = false }) {
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

  // Breakpoints are decorations, so they move with the text they mark.
  const dots = editor.createDecorationsCollection([]);
  const fired = editor.createDecorationsCollection([]);
  const dotLines = () => [...new Set(dots.getRanges().map((range) => range.startLineNumber))].sort((a, b) => a - b);
  const showDots = (lines) => dots.set(lines.map((line) => ({
    range: new monaco.Range(line, 1, line, 1),
    options: {
      glyphMarginClassName: "breakpoint",
      glyphMarginHoverMessage: { value: "breakpoint: a debug run stops in the rule on this line" },
      stickiness: monaco.editor.TrackedRangeStickiness.NeverGrowsWhenTypingAtEdges,
    },
  })));
  let reported = "[]";
  const reportDots = () => {
    const lines = dotLines();
    if (JSON.stringify(lines) === reported) return;
    reported = JSON.stringify(lines);
    onBreakpoints(lines);
  };
  editor.onMouseDown((event) => {
    if (event.target.type !== monaco.editor.MouseTargetType.GUTTER_GLYPH_MARGIN) return;
    const line = snapBreakpoint(event.target.position.lineNumber);
    if (line === null) return;
    const lines = dotLines();
    showDots(lines.includes(line) ? lines.filter((l) => l !== line) : [...lines, line]);
    reportDots();
  });

  editor.onDidChangeModelContent(() => {
    if (quiet) return;
    onChange();
    reportDots();
  });
  editor.addCommand(monaco.KeyMod.CtrlCmd | monaco.KeyCode.Enter, onEvaluate);
  editor.addCommand(monaco.KeyMod.CtrlCmd | monaco.KeyCode.KeyS, onSave);
  bindMonaco(monaco, editor); // structured editing and completion (paredit.js)
  return {
    show(key, text) {
      if (key !== shown) {
        if (documents.has(shown)) documents.get(shown).view = editor.saveViewState();
        if (!documents.has(key)) documents.set(key, { model: monaco.editor.createModel(text, "slog"), view: null });
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
      // Replacing the whole text would collapse every breakpoint onto its
      // start, so they are kept by line number instead.
      const lines = dotLines();
      quiet = true;
      // An edit operation, not setValue, so undo can step back over it.
      current().pushEditOperations([], [{ range: current().getFullModelRange(), text }], () => null);
      showDots(lines.filter((line) => line <= current().getLineCount()));
      // Notes and findings cannot be mapped onto a replaced text.
      notes.clear();
      noteTexts = [];
      monaco.editor.setModelMarkers(current(), "analyzer", []);
      quiet = false;
      if (selection) editor.setSelection(selection);
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
    breakpoints: dotLines,
    setBreakpoints(lines) {
      reported = JSON.stringify([...lines].sort((a, b) => a - b));
      showDots(lines);
    },
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
    setBreakpoints() {},
    breakpoints: () => [],
    notes() {},
    context: () => ({ line: area.value.slice(0, area.selectionStart).split("\n").length, notes: [] }),
    cursorTop: () => null,
    onMove(listener) {
      for (const type of ["keyup", "click"]) area.addEventListener(type, listener);
    },
    focus: () => area.focus(),
    findings() {},
    highlight() {},
  };
}
