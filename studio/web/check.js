// The static check in the editor (compiler/check.rkt, run aside from the
// REPL's session by studio/src/check.rs). As the author types, the program
// is checked -- parse, includes, types, negation, strata -- and what fails
// is marked where it is, before Run. What the check learned feeds the
// editor's hovers (a variable's inferred type, a relation's declaration and
// comment), its inlay hints (types, off by default), go to definition and
// find references. Those read the last report that got past parsing, so
// they never wait on a check, and survive a half-typed form.
//
// Other analyses add their own hover and inlay providers for "slog";
// Monaco shows every provider's part of a hover together, this one's first.
//
//   createCheck({ editor, files, send })
//     -> { receive, changed(), request(payload), commands() }
//   request({ texts?, append? })  a check of the program as the working
//                                 files have it, with these texts in place,
//                                 or `append` added to the main file:
//                                 a promise of its report

const DELAY = 400; // typing pause before a check

export function createCheck({ editor, files, send }) {
  const state = {
    tag: 0,
    waiting: new Map(), // tag -> resolve
    latest: 0, // the tag of the newest typing check
    timer: 0,
    info: null, // the last report's info, by project path (see index)
    hints: false, // inlay type hints shown
  };
  const hintsChanged = new Set();

  function request(payload) {
    const tag = ++state.tag;
    return new Promise((resolve) => {
      state.waiting.set(tag, resolve);
      send({ t: "check", tag, ...payload });
    });
  }

  function changed() {
    clearTimeout(state.timer);
    state.timer = setTimeout(run, DELAY);
  }

  async function run() {
    const paths = files.paths();
    const texts = files.texts();
    const promise = request({ texts: Object.fromEntries(paths.map((path, i) => [path, texts[i]])) });
    state.latest = state.tag;
    const report = await promise;
    if (report.tag !== state.latest) return; // typing moved on
    show(report);
  }

  function show(report) {
    const byPath = new Map(files.paths().map((path) => [path, []]));
    for (const diagnostic of report.diagnostics) {
      // a warning that names no place (the sequence blow-up warning) is
      // not this text's to mark
      if (diagnostic.severity === "warning" && !diagnostic.located) continue;
      const path = files.pathOf(diagnostic.file) ?? files.main();
      byPath.get(path)?.push(diagnostic);
    }
    for (const [path, list] of byPath) editor.diagnostics?.(path, list);
    // a Run's error mark was about a text that is gone
    if (report.ok) editor.mark(null);
    if (report.info) {
      state.info = index(report.info, files.pathOf);
      for (const listener of hintsChanged) listener();
    }
  }

  if (editor.raw) providers(editor.raw.monaco, editor, files, state, hintsChanged);

  return {
    receive: {
      checked(report) {
        state.waiting.get(report.tag)?.(report);
        state.waiting.delete(report.tag);
      },
    },
    changed,
    request,
    commands: () => editor.raw ? [{
      title: "Inferred types inline: show each variable's type in the editor",
      note: state.hints ? "on" : "",
      run() {
        state.hints = !state.hints;
        // Monaco asks the providers again when hints are switched on
        // (their change events alone did not redraw them)
        editor.raw.editor.updateOptions({ inlayHints: { enabled: "off" } });
        editor.raw.editor.updateOptions({ inlayHints: { enabled: "on" } });
      },
    }] : [],
  };
}

// The check's info by project path: { rules: path -> [rule], symbols: name
// -> symbol }, positions as they came (1-based).
export function index(info, pathOf) {
  const rules = new Map();
  for (const rule of info.rules ?? []) {
    const path = pathOf(rule.file);
    if (path === null) continue;
    if (!rules.has(path)) rules.set(path, []);
    rules.get(path).push(rule);
  }
  const symbols = new Map((info.symbols ?? []).map((symbol) => [symbol.name, symbol]));
  return { rules, symbols };
}

// The rule of `rules` around a 1-based position, or null.
export function ruleAt(rules, line, col) {
  const after = (l, c, L, C) => l > L || (l === L && c >= C);
  return rules?.find((rule) => after(line, col, rule.line, rule.col) && !after(line, col, rule.end_line, rule.end_col)) ?? null;
}

// What a hover over `word` at a position says: a markdown string, or null.
export function hover(info, path, word, line, col) {
  if (!info) return null;
  const symbol = info.symbols.get(word);
  if (symbol) {
    const count = (role) => symbol.refs.filter((ref) => ref.role === role).length;
    const uses = [["write", "written"], ["read", "read"], ["use", "used"]]
      .map(([role, what]) => [count(role), what]).filter(([n]) => n).map(([n, what]) => `${what} ${n}×`);
    return [
      `\`\`\`slog\n${symbol.decl ?? symbol.signature}\n\`\`\``,
      symbol.doc ?? "",
      [symbol.kind, ...uses].join(" · "),
    ].filter(Boolean).join("\n\n");
  }
  const rule = ruleAt(info.rules.get(path), line, col);
  const variable = rule?.vars.find((v) => v.name === word);
  return variable ? `\`${variable.name} : ${variable.type}\` · inferred in this rule` : null;
}

function providers(monaco, editor, files, state, hintsChanged) {
  const pathOfModel = (model) => editor.keyOf?.(model) ?? null;
  const uriOf = (file) => editor.uriOf?.(files.pathOf(file) ?? "") ?? null;
  const range = ({ line, col }, name) => new monaco.Range(line, col, line, col + name.length);

  monaco.languages.registerHoverProvider("slog", {
    provideHover(model, position) {
      const word = model.getWordAtPosition(position);
      const text = word && hover(state.info, pathOfModel(model), word.word, position.lineNumber, position.column);
      if (!text) return null;
      return {
        range: new monaco.Range(position.lineNumber, word.startColumn, position.lineNumber, word.endColumn),
        contents: [{ value: text }],
      };
    },
  });

  const changes = new monaco.Emitter();
  hintsChanged.add(() => changes.fire());
  monaco.languages.registerInlayHintsProvider("slog", {
    onDidChangeInlayHints: changes.event,
    provideInlayHints(model) {
      if (!state.hints || !state.info) return { hints: [], dispose() {} };
      const rules = state.info.rules.get(pathOfModel(model)) ?? [];
      const hints = rules.flatMap((rule) => rule.vars)
        .filter((v) => v.line <= model.getLineCount())
        .map((v) => ({
          position: { lineNumber: v.line, column: v.col + v.name.length },
          label: `: ${v.type}`,
          kind: monaco.languages.InlayHintKind.Type,
          paddingLeft: false,
        }));
      return { hints, dispose() {} };
    },
  });

  const symbolAt = (model, position) => {
    const word = model.getWordAtPosition(position);
    return word && state.info?.symbols.get(word.word);
  };
  monaco.languages.registerDefinitionProvider("slog", {
    provideDefinition(model, position) {
      const symbol = symbolAt(model, position);
      const uri = symbol?.def && uriOf(symbol.def.file);
      return uri ? [{ uri, range: range(symbol.def, symbol.name) }] : null;
    },
  });
  monaco.languages.registerReferenceProvider("slog", {
    provideReferences(model, position) {
      const symbol = symbolAt(model, position);
      if (!symbol) return null;
      return symbol.refs
        .map((ref) => ({ uri: uriOf(ref.file), range: range(ref, symbol.name) }))
        .filter((location) => location.uri);
    },
  });
  // A definition in another file opens it.
  monaco.editor.registerEditorOpener?.({
    openCodeEditor(_source, resource, selection) {
      const path = editor.keyOfUri?.(resource);
      if (path === null || path === undefined) return false;
      const at = selection?.startLineNumber ? { line: selection.startLineNumber, col: selection.startColumn } : { line: 1, col: 1 };
      files.open(path);
      editor.reveal(at);
      return true;
    },
  });
}
