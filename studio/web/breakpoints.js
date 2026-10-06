// Breakpoints in the editor, set where they mean something.
//
// A click in the margin of a rule breaks on the rule (it fires). Hovering
// a rule shows a faint dot before each of its clauses that can stop on its
// own -- a body atom it matches, a head it writes, a demand it asks or
// answers -- and a click on a dot arms it. Each kind has its own glyph;
// a condition, a logpoint, a disabled or an unbound breakpoint shows as
// such. Double-click or right-click a breakpoint to edit it in place:
// pattern, condition, ignore count, logpoint, enabled; the popover says
// what it compiled to, its hits, or why it cannot stop.
//
// Changes apply here at once and go to the studio, which keeps them with
// the project and re-arms a held run's breaks (studio/src/breakpoints.rs).
// The model functions are pure; web/test runs them.
//
// A breakpoint is { id, line, at, clause, condition, ignore, log, enabled }:
// `line` is its rule's `rule` keyword line (where the compiler locates the
// rule), `at` the [line, column] of its clause, `clause` how `break` spells
// the clause (`demand (nf _)`), or null and null for the whole rule.

import { forms, formAt, lineIndex } from "./forms.js";
import { parse } from "./sexp.js";
import { isName } from "./lexer.js";

// ---- The model ------------------------------------------------------------

const sexps = (list) => list.children.filter((c) => c.kind !== "comment" && c.kind !== "stray");
const textOf = (text, node) => text.slice(node.start, node.end);
const headOf = (text, list) => {
  const first = sexps(list)[0];
  return first?.kind === "word" ? textOf(text, first) : null;
};
// The pattern for the first `n` arguments of the atom `list`, as written:
// a variable is the rule's own (the break matches that very clause), a
// literal itself, and anything computed `_`.
function patternOf(text, list, n) {
  const args = sexps(list).slice(1, 1 + n).map((arg) => {
    const word = textOf(text, arg);
    if (arg.kind === "string") return word;
    if (arg.kind === "word" && (isName(word) || /^-?\d+(\.\d+)?$/.test(word))) return word;
    return "_";
  });
  return `(${[headOf(text, list), ...args].join(" ")})`;
}

// name -> { inputs, answers } for each `demand (f t ...) a ...` of `text`.
export function demandsOf(text) {
  const found = new Map();
  for (const form of forms(text)) {
    if (form.keyword !== "demand") continue;
    const body = form.start + "demand".length;
    const items = sexps(parse(text.slice(body, form.end)));
    const call = items[0];
    if (call?.kind !== "list") continue;
    const local = text.slice(body, form.end);
    const name = headOf(local, call);
    if (name) found.set(name, { inputs: sexps(call).length - 1, answers: items.length - 1 });
  }
  return found;
}

// The clauses of the rule `form` a break can stop on: [{ kind, clause,
// relation, at: [line, column], end: [line, column], label }] in text
// order.  Guards and negations cannot stop on their own; nested calls of a
// demand can (the rule asks them).
export function breakables(text, form, demands) {
  if (form?.keyword !== "rule") return [];
  const local = text.slice(form.start, form.end);
  const lineAt = lineIndex(text);
  const items = sexps(parse(local)).slice(1); // past `rule`
  const arrow = items.findIndex((n) => n.kind === "word" && /^(-->|<--)$/.test(textOf(local, n)));
  const forward = arrow >= 0 && textOf(local, items[arrow]) === "-->";
  const found = [];
  const position = (node) => {
    const at = lineAt(form.start + node.start);
    const end = lineAt(form.start + node.end);
    return { at: [at.line, at.column], end: [end.line, end.column] };
  };
  const add = (node, kind, name, n) => {
    const label = { demand: "asks", answer: "answers", match: "matches", emit: "writes" }[kind];
    found.push({ kind, relation: name, clause: `${kind} ${patternOf(local, node, n)}`, label: `${label} ${name}`, ...position(node) });
  };
  // calls in value position: `(nf (subst b 0 vx))` asks subst
  const calls = (node) => {
    for (const child of sexps(node)) {
      if (child.kind !== "list") continue;
      const name = headOf(local, child);
      const demand = name && demands.get(name);
      if (demand && sexps(child).length - 1 === demand.inputs) add(child, "demand", name, demand.inputs);
      calls(child);
    }
  };
  items.forEach((node, i) => {
    if (node.kind !== "list" || i === arrow) return;
    const previous = items[i - 1];
    if (previous?.kind === "word" && textOf(local, previous) === "~") return; // a negation
    const name = headOf(local, node);
    if (!name || !isName(name)) return calls(node); // a guard or a binding asks what it calls
    const n = sexps(node).length - 1;
    const head = arrow < 0 || (forward ? i > arrow : i < arrow);
    const demand = demands.get(name);
    if (demand && n === demand.inputs + demand.answers) add(node, head ? "answer" : "demand", name, head ? n : demand.inputs);
    else if (demand && n === demand.inputs && head) add(node, "demand", name, n);
    else add(node, head ? "emit" : "match", name, n);
    calls(node);
  });
  return found.sort((a, b) => a.at[0] - b.at[0] || a.at[1] - b.at[1]);
}

// The variables of the rule `form`: every name in argument position.
export function ruleVariables(text, form) {
  const local = text.slice(form.start, form.end);
  const names = new Set();
  const walk = (list) => {
    sexps(list).forEach((child, i) => {
      if (child.kind === "list") walk(child);
      else if (child.kind === "word" && (i > 0 || list.kind === "root")) {
        const word = textOf(local, child);
        if (isName(word) && word !== "_" && word !== "rule") names.add(word);
      }
    });
  };
  walk(parse(local));
  return names;
}

const OPS = new Set(["=", "/=", "!=", "<", "<=", ">", ">="]);
const KINDS = new Set(["demand", "answer", "match", "emit"]);

// The variables a clause pattern binds: `demand (nf T)` binds T.
export function patternVariables(clause) {
  const names = new Set();
  if (!clause) return names;
  const walk = (list, text) => sexps(list).forEach((child, i) => {
    if (child.kind === "list") walk(child, text);
    else if (child.kind === "word" && i > 0) {
      const word = textOf(text, child);
      if (isName(word) && word !== "_") names.add(word);
    }
  });
  walk(parse(clause), clause);
  return names;
}

// Why `clause` would not arm, or null: `KIND (R t ...)`, with the arity
// a demand declares.
export function clauseError(clause, demands) {
  const items = sexps(parse(clause));
  const kind = items[0]?.kind === "word" ? textOf(clause, items[0]) : "";
  if (!KINDS.has(kind)) return "starts demand, answer, match or emit";
  const call = items[1];
  if (items.length !== 2 || call.kind !== "list" || !call.closed) return `is ${kind} (R t ...): one atom`;
  const name = headOf(clause, call);
  if (!name || !isName(name)) return "names a relation first";
  const n = sexps(call).length - 1;
  const demand = demands.get(name);
  if ((kind === "demand" || kind === "answer") && !demand) return `${name} is not a demand`;
  if (kind === "demand" && n !== demand.inputs) return `${name} is asked with ${demand.inputs} input${demand.inputs === 1 ? "" : "s"}`;
  if (kind === "answer" && n !== demand.inputs + demand.answers) {
    return `an answer of ${name} has ${demand.inputs + demand.answers} terms: its inputs, then its answers`;
  }
  return null;
}

// Why `condition` would not arm, or null: each guard is (OP a b), and its
// names are variables the rule or the pattern binds.
export function conditionError(condition, bound) {
  if (!condition.trim()) return null;
  const root = parse(condition);
  if (root.faults) return "the brackets do not balance";
  for (const guard of sexps(root)) {
    if (guard.kind !== "list") return `${textOf(condition, guard)} is not a guard: write (OP a b)`;
    const [op, ...args] = sexps(guard);
    const name = op && textOf(condition, op);
    if (!OPS.has(name)) return `${name ?? "()"} is not one of = /= < <= > >=`;
    if (args.length !== 2) return `(${name} …) compares two terms`;
    for (const arg of args) {
      const walk = (node, top) => {
        if (node.kind === "list") return sexps(node).slice(1).map((n) => walk(n, false)).find(Boolean) ?? null;
        const word = textOf(condition, node);
        if (node.kind !== "word" || !isName(word) || word === "_") return null;
        // a constructor's own name is not a variable; a bare word is
        return top || node !== node.parent.children[0] ? (bound.has(word) ? null : `${word} is not a variable here`) : null;
      };
      const error = walk(arg, true);
      if (error) return error;
    }
  }
  return null;
}

// The glyph classes of a breakpoint given its status.
export function glyphClass(point, status) {
  const kind = point.clause ? point.clause.split(" ")[0] : "rule";
  return [
    "bpg", `k-${kind}`,
    point.condition.trim() ? "cond" : "",
    point.log ? "log" : "",
    !point.enabled ? "off" : "",
    status?.status === "unbound" || status?.status === "error" ? "unbound" : "",
  ].filter(Boolean).join(" ");
}

// "stops when the rule asks nf", the plain words for a breakpoint.
export function describe(point) {
  if (!point.clause) return "when the rule fires";
  const [kind, ...rest] = point.clause.split(" ");
  const what = rest.join(" ");
  return {
    demand: `when the rule asks ${what}`,
    answer: `when the rule answers ${what}`,
    match: `when the rule matches ${what}`,
    emit: `when the rule writes ${what}`,
  }[kind] ?? point.clause;
}

// A held stop's position from its pause result: { id, file, line }.
export function stopOf(result) {
  const port = (result?.lines ?? []).find((l) => l.startsWith("port "));
  const match = /^port (?:([\w-]+):)?(\w[\w-]*)@([^:]+):(\d+):\d+/.exec(port ?? "");
  return match && { id: match[1] ?? null, port: match[2], file: match[3], line: Number(match[4]) };
}

// ---- The editor ---------------------------------------------------------

let serial = 0;
const fresh = () => `p${Date.now().toString(36)}${(serial++).toString(36)}`;

const node = (tag, className, text) => {
  const element = document.createElement(tag);
  if (className) element.className = className;
  if (text !== undefined) element.textContent = text;
  return element;
};

// `editor` is editor.js's (its Monaco parts, `editor.raw`);
// `onChange(file, points)` sends a file's breakpoints; `file()` is the path
// shown; `texts()` every file's text, for the demands they declare.
export function createBreakpoints({ editor, onChange, file, texts }) {
  const parts = editor.raw;
  const state = {
    points: new Map(), // path -> [breakpoint]
    status: new Map(), // id -> { status, why, hits, compiled, server }
    hover: null,       // the rule form the mouse is over
    stop: null,        // { line, at, end } of a held stop in the file shown
    bindings: [],
  };
  if (!parts) {
    return { show() {}, receive() {}, status() {}, held() {}, list: () => [], remove() {}, toggle() {}, reveal() {}, open() {} };
  }
  const { monaco, editor: ed } = parts;
  const model = () => ed.getModel();
  const glyphs = ed.createDecorationsCollection([]);
  const candidates = ed.createDecorationsCollection([]);
  const stopping = ed.createDecorationsCollection([]);
  const points = () => state.points.get(file()) ?? [];

  // Demands are read from every file; a rule's clauses from the one shown.
  let demandsKey = "";
  let demands = new Map();
  const currentDemands = () => {
    const all = texts();
    const key = all.join("\u0000");
    if (key !== demandsKey) {
      demandsKey = key;
      demands = new Map(all.flatMap((text) => [...demandsOf(text)]));
    }
    return demands;
  };

  // Decorations carry each breakpoint's position as the text moves: one
  // per breakpoint, keyed by index into the file's list.
  let tracked = []; // ids, parallel to glyphs' decorations
  function render() {
    const list = points();
    tracked = list.map((p) => p.id);
    glyphs.set(list.map((point) => {
      const status = state.status.get(point.id);
      const [line, column] = point.at ?? [point.line, 1];
      const hits = status?.hits ? ` ${status.hits}×` : "";
      const why = status?.status === "unbound" || status?.status === "error" ? `\n\ncannot stop: ${status.why}` : "";
      return {
        // a rule's spans its line, so its hit count can follow the text
        // (a collapsed decoration shows no injected text)
        range: new monaco.Range(line, column, line, point.at ? column + 1 : Math.max(2, model().getLineMaxColumn(line))),
        options: {
          glyphMarginClassName: glyphClass(point, status),
          glyphMarginHoverMessage: { value: `breakpoint: stops ${describe(point)}${hits ? ` · hit${hits}` : ""}${why}\n\ndouble-click to edit` },
          stickiness: monaco.editor.TrackedRangeStickiness.NeverGrowsWhenTypingAtEdges,
          ...(point.at ? { inlineClassName: `bp-inline ${glyphClass(point, status)}` } : {}),
          ...(hits && !point.at ? { after: { content: hits, inlineClassName: "bp-hits" } } : {}),
        },
      };
    }));
  }

  // After an edit, read each breakpoint's position back from its
  // decoration; a clause breakpoint whose clause is gone goes with it.
  function follow() {
    const list = points();
    if (!list.length) return;
    const ranges = glyphs.getRanges();
    const text = model().getValue();
    const found = forms(text);
    let changed = false;
    const kept = [];
    list.forEach((point, i) => {
      const range = ranges[tracked.indexOf(point.id)] ?? null;
      if (!range) { kept.push(point); return; }
      const at = point.at ? [range.startLineNumber, range.startColumn] : null;
      const rule = formAt(found, range.startLineNumber);
      if (rule?.keyword !== "rule") { changed = true; return; }
      const moved = { ...point, line: rule.line, at };
      if (moved.line !== point.line || String(moved.at) !== String(point.at)) changed = true;
      kept.push(moved);
    });
    if (changed) set(kept);
  }

  function set(list) {
    state.points.set(file(), list);
    render();
    onChange(file(), list);
  }

  // Hover: the rule under the mouse shows its breakable clauses.
  function showCandidates(form) {
    if (form === state.hover || (form && state.hover && form.start === state.hover.start)) return;
    state.hover = form;
    if (!form) { candidates.clear(); return; }
    const armed = new Set(points().filter((p) => p.at).map((p) => String(p.at)));
    candidates.set(breakables(model().getValue(), form, currentDemands())
      .filter((b) => !armed.has(String(b.at)))
      .map((b) => ({
        range: new monaco.Range(b.at[0], b.at[1], b.at[0], b.at[1] + 1),
        options: { inlineClassName: `bp-candidate k-${b.kind}`, hoverMessage: { value: `click the dot to break ${b.label.replace(/^\w+/, (w) => `when the rule ${w}`)}` } },
      })));
  }

  // The dot a click landed on, as the [line, column] of its clause: a dot
  // sits just left of its clause's bracket, over the space before it.
  const dotAt = (event) => {
    const line = event.target.position?.lineNumber;
    if (!line) return null;
    const columns = [
      ...points().filter((p) => p.at?.[0] === line).map((p) => p.at[1]),
      ...(state.hover ? breakables(model().getValue(), state.hover, currentDemands())
        .filter((b) => b.at[0] === line).map((b) => b.at[1]) : []),
    ];
    const x = event.event.browserEvent.clientX - ed.getDomNode().getBoundingClientRect().left;
    const column = columns.find((c) => {
      const left = ed.getScrolledVisiblePosition({ lineNumber: line, column: c })?.left;
      return left !== undefined && x >= left - 9 && x <= left + 1;
    });
    return column ? { lineNumber: line, column } : null;
  };

  function toggleRule(line) {
    const form = formAt(currentForms(), line);
    if (form?.keyword !== "rule") return;
    const list = points();
    const existing = list.find((p) => !p.at && p.line === form.line);
    set(existing ? list.filter((p) => p !== existing) : [...list, blank(form.line, null, null)]);
  }

  function toggleClause(position) {
    const text = model().getValue();
    const form = formAt(currentForms(), position.lineNumber);
    const list = points();
    const at = [position.lineNumber, position.column];
    const existing = list.find((p) => p.at && p.at[0] === at[0] && p.at[1] === at[1]);
    if (existing) return set(list.filter((p) => p !== existing));
    const target = breakables(text, form, currentDemands()).find((b) => b.at[0] === at[0] && b.at[1] === at[1]);
    if (!target) return;
    set([...list, blank(form.line, target.at, target.clause)]);
    state.hover = null;
    showCandidates(form);
  }

  const blank = (line, at, clause) => ({ id: fresh(), line, at, clause, condition: "", ignore: 0, log: false, enabled: true });

  // The forms of the text shown, read once per edit.
  let formsOf = { version: -1, found: [] };
  const currentForms = () => {
    const version = model().getVersionId();
    if (version !== formsOf.version) formsOf = { version, found: forms(model().getValue()) };
    return formsOf.found;
  };

  ed.onMouseMove((event) => {
    const line = event.target.position?.lineNumber;
    const form = line ? formAt(currentForms(), line) : null;
    showCandidates(form?.keyword === "rule" ? form : null);
  });
  ed.onMouseLeave(() => showCandidates(null));
  // A click removes a breakpoint at once; a double-click's second press
  // puts it back and opens it, so editing never waits on a timer.
  let removed = null; // { point, at: when }
  const unclick = (line) => {
    if (!removed || performance.now() - removed.at > 500) return null;
    const point = removed.point;
    removed = null;
    if ((point.at ? point.at[0] : point.line) !== line) return null;
    set([...points(), point]);
    return point;
  };
  const remove = (point) => {
    removed = { point, at: performance.now() };
    set(points().filter((p) => p !== point));
  };
  ed.onMouseDown((event) => {
    const { MouseTargetType } = monaco.editor;
    const glyph = event.target.type === MouseTargetType.GUTTER_GLYPH_MARGIN;
    const line = event.target.position?.lineNumber;
    const editing = event.event.rightButton || event.event.detail === 2;
    if (glyph && line) {
      event.event.preventDefault();
      const point = points().find((p) => (p.at ? p.at[0] : p.line) === line)
        ?? (event.event.detail === 2 ? unclick(line) : null);
      if (editing) {
        if (point) open(point.id);
        return;
      }
      if (point) remove(point);
      else toggleRule(line);
      return;
    }
    const at = dotAt(event);
    if (!at) return;
    event.event.preventDefault();
    event.event.stopPropagation();
    const point = points().find((p) => p.at && p.at[0] === at.lineNumber && p.at[1] === at.column)
      ?? (event.event.detail === 2 ? unclick(at.lineNumber) : null);
    if (editing) {
      if (point) open(point.id);
    } else if (point) remove(point);
    else toggleClause(at);
  });
  ed.onDidChangeModelContent(() => {
    state.hover = null;
    candidates.clear();
    if (!editor.replacing()) follow();
  });
  editor.onReplaced(render);

  // ---- The popover --------------------------------------------------------

  let popover = null;
  function close() {
    popover?.remove();
    popover = null;
  }
  addEventListener("mousedown", (event) => {
    if (popover && !popover.contains(event.target)) close();
  }, true);
  addEventListener("keydown", (event) => { if (event.key === "Escape") close(); });

  function open(id) {
    close();
    const point = points().find((p) => p.id === id);
    if (!point) return;
    const [line, column] = point.at ?? [point.line, 1];
    ed.revealLineInCenterIfOutsideViewport(line);
    const where = ed.getScrolledVisiblePosition({ lineNumber: line, column });
    const box = ed.getDomNode().getBoundingClientRect();
    popover = document.body.appendChild(node("div", "bp-popover"));
    popover.style.left = `${box.left + (where?.left ?? 0) + 8}px`;
    popover.style.top = `${box.top + (where?.top ?? 0) + (where?.height ?? 18) + 4}px`;
    const text = model().getValue();
    const form = formAt(forms(text), point.line);
    const bound = new Set([...(form ? ruleVariables(text, form) : []), ...patternVariables(point.clause?.replace(/^\w+\s*/, "") ?? "")]);

    const head = popover.appendChild(node("div", "bp-head"));
    head.append(node("span", glyphClass(point, state.status.get(point.id))), node("span", "bp-title", `Stops ${describe(point)}`));
    head.append(node("span", "bp-where", `${file()}:${point.line}`));

    const field = (label, input, hint) => {
      const row = popover.appendChild(node("label", "bp-field"));
      row.append(node("span", "bp-label", label), input);
      const error = row.appendChild(node("span", "bp-error"));
      if (hint) input.placeholder = hint;
      return error;
    };
    const update = (change) => {
      const list = points().map((p) => (p.id === id ? { ...p, ...change } : p));
      set(list);
      head.firstChild.className = glyphClass(list.find((p) => p.id === id), state.status.get(id));
    };
    const debounce = (f) => { let t; return (...a) => { clearTimeout(t); t = setTimeout(() => f(...a), 200); }; };

    if (point.clause) {
      const input = node("input", "bp-input");
      input.value = point.clause;
      const error = field("Clause", input, "demand (nf _)");
      const check = debounce(() => {
        const why = clauseError(input.value, currentDemands());
        error.textContent = why ? `✗ ${why}` : "";
        input.classList.toggle("bad", Boolean(why));
        if (!why) update({ clause: input.value.trim() });
      });
      input.addEventListener("input", check);
    }
    const condition = node("input", "bp-input");
    condition.value = point.condition;
    const conditionError_ = field("Condition", condition, "(< n 3) (/= T V)");
    const checkCondition = debounce(() => {
      const why = conditionError(condition.value, bound);
      conditionError_.textContent = why ? `✗ ${why}` : "";
      condition.classList.toggle("bad", Boolean(why));
      if (!why) update({ condition: condition.value.trim() });
    });
    condition.addEventListener("input", checkCondition);

    const ignore = node("input", "bp-input short");
    ignore.type = "number";
    ignore.min = "0";
    ignore.value = String(point.ignore);
    field("Ignore", ignore, "0").textContent = "";
    ignore.addEventListener("input", debounce(() => update({ ignore: Math.max(0, Number(ignore.value) || 0) })));

    const toggles = popover.appendChild(node("div", "bp-toggles"));
    const check = (label, value, change) => {
      const box = node("input");
      box.type = "checkbox";
      box.checked = value;
      box.addEventListener("change", () => update(change(box.checked)));
      const wrap = toggles.appendChild(node("label", "bp-check"));
      wrap.append(box, node("span", null, label));
    };
    check("Log, don't stop", point.log, (log) => ({ log }));
    check("Enabled", point.enabled, (enabled) => ({ enabled }));
    const remove = toggles.appendChild(node("button", "danger small", "Delete"));
    remove.addEventListener("click", () => { set(points().filter((p) => p.id !== id)); close(); });

    const status = state.status.get(id);
    const footer = popover.appendChild(node("div", "bp-status"));
    footer.textContent = statusText(point, status);
    condition.focus();
  }

  function statusText(point, status) {
    if (!status) return "Not armed yet: Debug arms it.";
    if (status.status === "off") return "Disabled: not armed.";
    if (status.status === "error" || status.status === "unbound") return `Cannot stop: ${status.why}`;
    if (status.status === "pending") return `Armed; ${status.why}.`;
    const hits = `${status.hits} hit${status.hits === 1 ? "" : "s"}`;
    return `${status.server ?? ""} · ${status.compiled || "armed"} · ${hits}`;
  }

  // ---- A held stop --------------------------------------------------------

  function showStop() {
    const stop = state.stop;
    if (!stop) { stopping.clear(); return; }
    const [line, column] = stop.at ?? [stop.line, 1];
    const end = stop.end ?? [line, model().getLineMaxColumn(line)];
    const bindings = state.bindings.map(([name, value]) => `${name} = ${value}`).join(" · ");
    stopping.set([
      { range: new monaco.Range(line, 1, line, 1), options: { glyphMarginClassName: "bp-stop", isWholeLine: true, className: "stop-line" } },
      { range: new monaco.Range(line, column, end[0], end[1]), options: { className: "stop-clause" } },
      ...(bindings ? [{
        range: new monaco.Range(end[0], Math.max(1, model().getLineMaxColumn(end[0]) - 1), end[0], model().getLineMaxColumn(end[0])),
        options: { after: { content: `   ${bindings}`, inlineClassName: "stop-bindings" } },
      }] : []),
    ]);
    ed.revealLineInCenterIfOutsideViewport(line);
  }

  return {
    // `path` is now shown: its breakpoints, and a stop in it.
    show(path) {
      close();
      state.hover = null;
      candidates.clear();
      render();
      showStop();
    },
    // The studio's breakpoints for `file` (another tab, or the snapshot).
    receive(path, list) {
      state.points.set(path, list);
      if (path === file()) render();
    },
    status(statuses) {
      state.status = new Map(statuses.map((s) => [s.id, s]));
      render();
    },
    // The run held at `stop` ({ id, file, line } from stopOf), with
    // `bindings` [[name, value]]; null when nothing is held.
    held(stop, bindings = []) {
      if (!stop) {
        state.stop = null;
        state.bindings = [];
        showStop();
        return;
      }
      const server = stop.id;
      const point = server && [...state.status.values()].find((s) => s.server === server);
      const armed = point && points().find((p) => p.id === point.id);
      let at = armed?.at ?? null;
      let end = null;
      if (at) {
        const form = formAt(forms(model().getValue()), stop.line);
        end = breakables(model().getValue(), form, currentDemands()).find((b) => String(b.at) === String(at))?.end ?? null;
      }
      state.stop = { line: stop.line, at, end };
      state.bindings = bindings.map(([name, value]) => [name, value.replace(/\(_enum "([^"]*)"\)/g, "($1)")]);
      showStop();
    },
    // Every breakpoint, for the panel: [{ path, point, status }].
    list: () => [...state.points].flatMap(([path, list]) => list.map((point) => ({ path, point, status: state.status.get(point.id) }))),
    remove(path, id) {
      const list = (state.points.get(path) ?? []).filter((p) => p.id !== id);
      state.points.set(path, list);
      if (path === file()) render();
      onChange(path, list);
    },
    toggle(path, id) {
      const list = (state.points.get(path) ?? []).map((p) => (p.id === id ? { ...p, enabled: !p.enabled } : p));
      state.points.set(path, list);
      if (path === file()) render();
      onChange(path, list);
    },
    open,
  };
}
