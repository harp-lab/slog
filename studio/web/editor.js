// The program editor: Monaco when its loader is reachable, else a textarea.
// Both offer the same small interface:
//   get() / set(text)       the text; set keeps the cursor and does not fire onChange
//   mark(span, message)     underline a 1-based position, or clear with null
//   reveal(span)            put the cursor at a position
//   setBreakpoints(lines)   show breakpoint dots on these 1-based lines
// `onBreakpoints(lines)` fires when a margin click or an edit changes them;
// `snapBreakpoint(line)` says which line a click on `line` marks, or null.

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

function monacoEditor(monaco, element, { onChange, onEvaluate, onSave, onBreakpoints, snapBreakpoint }) {
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
  });
  const model = editor.getModel();
  let quiet = false;

  // Breakpoints are decorations, so they move with the text they mark.
  const dots = editor.createDecorationsCollection([]);
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
  return {
    get: () => model.getValue(),
    set(text) {
      if (model.getValue() === text) return;
      const selection = editor.getSelection();
      // Replacing the whole text would collapse every breakpoint onto its
      // start, so they are kept by line number instead.
      const lines = dotLines();
      quiet = true;
      // An edit operation, not setValue, so undo can step back over it.
      model.pushEditOperations([], [{ range: model.getFullModelRange(), text }], () => null);
      showDots(lines.filter((line) => line <= model.getLineCount()));
      quiet = false;
      if (selection) editor.setSelection(selection);
    },
    mark(span, message) {
      const markers = span ? [{
        startLineNumber: span.line,
        startColumn: span.col,
        endLineNumber: span.line,
        endColumn: (model.getWordAtPosition({ lineNumber: span.line, column: span.col })?.endColumn) ?? span.col + 1,
        message,
        severity: monaco.MarkerSeverity.Error,
      }] : [];
      monaco.editor.setModelMarkers(model, "slog", markers);
    },
    reveal(span) {
      editor.revealLineInCenter(span.line);
      editor.setPosition({ lineNumber: span.line, column: span.col });
      editor.focus();
    },
    setBreakpoints(lines) {
      reported = JSON.stringify([...lines].sort((a, b) => a - b));
      showDots(lines);
    },
  };
}

// The fallback has no margin: breakpoints need the Monaco editor.
function textareaEditor(element, { onChange, onEvaluate, onSave }) {
  const area = document.createElement("textarea");
  area.spellcheck = false;
  element.append(area);
  area.addEventListener("input", onChange);
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
  };
}
