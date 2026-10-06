// Looking around a held stop without moving it: the Variables tab (the
// stopped rule's scope, watches, the matched row, the stack), a popup on
// hovering a variable or a relation in the stopped rule, and the elided
// one-line form of the bindings shown beside the clause.
//
// Everything here reads the stop through observing REPL lines (`frames`,
// `p`, `peek`, `?`), which the server answers without stepping, continuing
// or committing.  The model functions are pure; web/test runs them.

import { parseValue } from "./table.js";
import { renderSexp } from "./sexpview.js";

// ---- The model --------------------------------------------------------------

// A value tree as one line, terms past `depth` levels cut to `…`: the
// constructor heads of the top levels survive, which say the most.
export function elide(tree, depth) {
  if (tree.kind === "term") {
    if (!tree.args.length) return `(${tree.head})`;
    if (depth <= 0) return `(${tree.head} …)`;
    return `(${tree.head} ${tree.args.map((a) => elide(a, depth - 1)).join(" ")})`;
  }
  const brackets = { tuple: ["(", ")"], list: ["[", "]"], set: ["{", "}"] }[tree.kind];
  if (brackets) {
    if (!tree.items.length) return brackets.join("");
    if (depth <= 0) return `${brackets[0]}…${brackets[1]}`;
    return `${brackets[0]}${tree.items.map((a) => elide(a, depth - 1)).join(" ")}${brackets[1]}`;
  }
  return tree.text;
}

const depthOf = (tree) => {
  const items = tree.kind === "term" ? tree.args : tree.items;
  return items?.length ? 1 + Math.max(...items.map(depthOf)) : 0;
};

// The bindings [[name, text]] as one line of at most `width` characters:
// whole when they fit, else the longest binding cut a level at a time,
// then -- were that still too long -- the line itself cut.  `elided` says
// whether anything was cut.
export function fitBindings(bindings, width) {
  const parts = bindings.map(([name, text]) => {
    const tree = parseValue(text);
    return { name, tree, depth: depthOf(tree), text };
  });
  const line = () => parts.map((p) => `${p.name} = ${p.text}`).join(" · ");
  let elided = false;
  while (line().length > width) {
    const longest = parts.filter((p) => p.depth > 0).sort((a, b) => b.text.length - a.text.length)[0];
    if (!longest) break;
    longest.depth -= 1;
    longest.text = elide(longest.tree, longest.depth);
    elided = true;
  }
  let text = line();
  if (text.length > width) {
    text = `${text.slice(0, Math.max(1, width - 1))}…`;
    elided = true;
  }
  return { text, elided };
}

// The identifier at `column` (1-based) of `lineText`, with where it starts
// and whether it heads an atom (a relation's name).
export function wordAt(lineText, column) {
  const at = column - 1;
  const ident = /[A-Za-z0-9_']/;
  if (!ident.test(lineText[at] ?? "")) return null;
  let start = at;
  while (start > 0 && ident.test(lineText[start - 1])) start--;
  let end = at;
  while (end < lineText.length && ident.test(lineText[end])) end++;
  const word = lineText.slice(start, end);
  if (!/^[A-Za-z_]/.test(word)) return null;
  return { word, start: start + 1, head: lineText[start - 1] === "(" };
}

// ---- The view -------------------------------------------------------------------

const node = (tag, className, text) => {
  const element = document.createElement(tag);
  if (className) element.className = className;
  if (text !== undefined) element.textContent = text;
  return element;
};

// A value as Slog text, cut to what `columns` holds on a line, each `…`
// opening in place (sexpview.js).
const pretty = (text, columns) => renderSexp(text, { columns });
// characters a panel or popup of `pixels` holds, in the 12px mono
const columnsOf = (pixels) => Math.max(24, Math.floor(pixels / 7.3));

// How long the mouse rests on a word before its popup: long enough not to
// flash while passing over the rule.
const HOVER_MS = 150;
// characters a popup holds
const POP = 56;

// `editor` is editor.js's; `quiet(line)` answers an observing REPL line;
// `reveal(loc)` shows a rule; `tabs`, `transcript` and `results` are the
// result area, as calls.js takes them. Returns { held(stop, frames, calls),
// released(), show() }.
export function createInspector({ editor, quiet, reveal, tabs, transcript, results }) {
  const state = {
    stop: null,      // { line, file, port, source } of the held stop
    scope: null,     // the frames result: bindings, unbound, clause, at
    stack: [],       // the demand stack from the pause record
    watches: [],     // [{ expr, answer }]
    relations: new Map(), // name -> peek answers at this stop
  };
  const panel = node("div", "inspect-panel");
  panel.hidden = true;
  transcript.after(panel);
  const tab = node("button", "rs-tab", "Variables");
  tab.title = "The held stop's variables, watches and stack";
  tab.hidden = true;
  tabs.firstElementChild.after(tab);
  tab.addEventListener("click", () => {
    transcript.hidden = true;
    results.hidden = true;
    for (const other of tabs.querySelectorAll(".rs-tab")) other.setAttribute("aria-selected", String(other === tab));
    for (const sibling of panel.parentElement.children) {
      if (sibling !== panel && (sibling.classList.contains("execution") || sibling.classList.contains("calls-panel"))) sibling.hidden = true;
    }
    panel.hidden = false;
    render();
  });
  new MutationObserver(() => {
    if (panel.hidden || (transcript.hidden && results.hidden)) return;
    panel.hidden = true;
    tab.setAttribute("aria-selected", "false");
  }).observe(transcript, { attributes: true, attributeFilter: ["hidden"] });
  for (const sibling of panel.parentElement.children) {
    if (sibling === panel || !(sibling.classList.contains("execution") || sibling.classList.contains("calls-panel"))) continue;
    new MutationObserver(() => {
      if (!sibling.hidden && !panel.hidden) { panel.hidden = true; tab.setAttribute("aria-selected", "false"); }
    }).observe(sibling, { attributes: true, attributeFilter: ["hidden"] });
  }

  // ---- watches ----
  async function evaluate(watch) {
    const line = watch.expr.startsWith("?") ? watch.expr : `p ${watch.expr}`;
    const outcome = await quiet(line);
    watch.answer = outcome.error ? { error: outcome.error.message }
      : { lines: outcome.result?.lines ?? [], value: outcome.result?.value ?? null };
  }
  async function pin(expr) {
    if (state.watches.some((w) => w.expr === expr)) return;
    const watch = { expr, answer: null };
    state.watches.push(watch);
    await evaluate(watch);
    render();
  }

  // the Variables panel's width in characters
  const wide = () => columnsOf((panel.clientWidth || 900) - 160);

  function section(title) {
    const box = panel.appendChild(node("section", "inspect-section"));
    box.append(node("h4", null, title));
    return box;
  }

  function render() {
    if (panel.hidden) return;
    panel.replaceChildren();
    if (!state.scope) {
      panel.append(node("p", "hint", "Debug the program and stop at a breakpoint: the rule's variables appear here."));
      return;
    }
    const where = section("Stopped");
    const at = where.appendChild(node("a", "inspect-where",
      `${state.scope.at?.port ?? "?"} · ${state.scope.at?.source ?? "?"}`));
    at.addEventListener("click", () => reveal(state.scope.at?.source));
    if (state.scope.clause && state.scope.clause !== "null") {
      const row = where.appendChild(node("div", "inspect-row"));
      row.append(node("span", "inspect-note", "matched"));
      row.append(pretty(`(${state.scope.clause.relation} ${state.scope.clause.row})`, wide()));
    }

    const locals = section("Variables");
    for (const [name, value] of state.scope.bindings ?? []) {
      const row = locals.appendChild(node("div", "inspect-row"));
      row.append(node("span", "inspect-name", name), node("span", "inspect-eq", "="));
      row.append(pretty(value, wide() - name.length - 3));
      const pinIt = row.appendChild(node("button", "inspect-pin", "pin"));
      pinIt.title = "Watch it at every stop";
      pinIt.addEventListener("click", () => pin(name));
    }
    for (const name of state.scope.unbound ?? []) {
      const row = locals.appendChild(node("div", "inspect-row unbound"));
      row.append(node("span", "inspect-name", name), node("span", "inspect-note", "not yet bound at this clause"));
    }
    if (!(state.scope.bindings ?? []).length && !(state.scope.unbound ?? []).length) {
      locals.append(node("p", "hint", "No named variables at this port."));
    }

    const watches = section("Watches");
    for (const watch of state.watches) {
      const row = watches.appendChild(node("div", "inspect-row"));
      row.append(node("span", "inspect-name", watch.expr));
      if (!watch.answer) row.append(node("span", "inspect-note", "…"));
      else if (watch.answer.error) row.append(node("span", "inspect-error", watch.answer.error));
      else if (watch.answer.value) row.append(pretty(watch.answer.value, wide() - watch.expr.length - 3));
      else row.append(node("span", "inspect-note", watch.answer.lines.join(" · ")));
      const remove = row.appendChild(node("button", "inspect-pin", "×"));
      remove.addEventListener("click", () => { state.watches = state.watches.filter((w) => w !== watch); render(); });
    }
    const add = watches.appendChild(node("input", "inspect-add"));
    add.placeholder = "add a watch: a variable, or ?(rel X Y) over the stop";
    add.addEventListener("keydown", (event) => {
      if (event.key === "Enter" && add.value.trim()) pin(add.value.trim());
    });

    if (state.stack.length) {
      const stack = section("Demand calls, latest first");
      state.stack.forEach((frame, i) => {
        const row = stack.appendChild(node("div", "inspect-row"));
        row.append(node("span", "inspect-note", String(i)), pretty(frame.node.call, wide() - 24));
        if (frame.node.asked?.source) {
          const link = row.appendChild(node("a", "inspect-where", frame.node.asked.source));
          link.addEventListener("click", () => reveal(frame.node.asked.source));
        }
      });
    }
  }

  // ---- hover --------------------------------------------------------------------

  const parts = editor.raw;
  let pop = null;
  let timer = null;
  const hide = () => { clearTimeout(timer); pop?.remove(); pop = null; };
  addEventListener("keydown", (event) => { if (event.key === "Escape") hide(); });
  addEventListener("mousedown", (event) => { if (pop && !pop.contains(event.target)) hide(); }, true);

  function place(box, x, y) {
    box.style.left = `${Math.min(x + 12, innerWidth - 440)}px`;
    box.style.top = `${y + 16}px`;
  }

  // Every binding of the stop, whole.
  function bindingsPopup(x, y) {
    hide();
    pop = document.body.appendChild(node("div", "inspect-pop"));
    for (const [name, value] of state.scope.bindings ?? []) {
      const row = pop.appendChild(node("div", "inspect-row"));
      row.append(node("span", "inspect-name", name), node("span", "inspect-eq", "="), pretty(value, POP - name.length - 3));
    }
    place(pop, x, y);
  }

  function variablePopup(name, x, y) {
    const binding = (state.scope.bindings ?? []).find(([n]) => n === name);
    const unbound = (state.scope.unbound ?? []).includes(name);
    if (!binding && !unbound) return;
    hide();
    pop = document.body.appendChild(node("div", "inspect-pop"));
    const head = pop.appendChild(node("div", "inspect-pop-head"));
    head.append(node("span", "inspect-name", name));
    if (!binding) {
      pop.append(node("div", "inspect-note", "not yet bound at this clause"));
    } else {
      pop.append(pretty(binding[1], POP));
      const copy = head.appendChild(node("button", "inspect-pin", "copy"));
      copy.addEventListener("click", () => navigator.clipboard?.writeText(binding[1]));
      const pinIt = head.appendChild(node("button", "inspect-pin", "pin to watches"));
      pinIt.addEventListener("click", () => { pin(name); hide(); });
    }
    place(pop, x, y);
  }

  async function relationPopup(name, x, y) {
    let peeks = state.relations.get(name);
    if (!peeks) {
      const [delta, fresh] = await Promise.all([quiet(`peek ${name} 5 delta`), quiet(`peek ${name} 5 new`)]);
      peeks = { delta: delta.result, fresh: fresh.result, error: delta.error?.message };
      state.relations.set(name, peeks);
    }
    if (peeks.error) return;
    hide();
    pop = document.body.appendChild(node("div", "inspect-pop"));
    const head = pop.appendChild(node("div", "inspect-pop-head"));
    head.append(node("span", "inspect-name", name));
    const size = peeks.delta?.size;
    head.append(node("span", "inspect-note", size === null || size === undefined ? "" : `${size} rows so far`));
    for (const [label, answer] of [["delta driving this iteration", peeks.delta], ["new this iteration, not yet deduplicated", peeks.fresh]]) {
      const rows = answer?.rows ?? [];
      pop.append(node("div", "inspect-pop-label", `${label} · ${rows.length}${rows.length === 5 ? "+" : ""}`));
      for (const [sign, row] of rows) {
        const line = pop.appendChild(node("div", "inspect-pop-row"));
        line.append(node("span", "inspect-note", sign), pretty(`(${name} ${row})`, POP - 2));
      }
    }
    place(pop, x, y);
  }

  if (parts) {
    const { editor: ed } = parts;
    ed.onMouseMove((event) => {
      clearTimeout(timer);
      const position = event.target.position;
      if (!state.scope || !state.stop || !position || event.target.type !== parts.monaco.editor.MouseTargetType.CONTENT_TEXT) return;
      if (pop?.matches(":hover")) return;
      const model = ed.getModel();
      if (position.lineNumber < state.stop.from || position.lineNumber > state.stop.to) return;
      const found = wordAt(model.getLineContent(position.lineNumber), position.column);
      if (!found) return;
      const { clientX, clientY } = event.event.browserEvent;
      timer = setTimeout(async () => {
        const t0 = performance.now();
        if (found.head) await relationPopup(found.word, clientX, clientY);
        else variablePopup(found.word, clientX, clientY);
        if (pop) requestAnimationFrame(() => { window.inspectLatency = Math.round(performance.now() - t0); });
      }, HOVER_MS);
    });
    ed.onMouseLeave(() => clearTimeout(timer));
  }

  return {
    // A run held at `stop` ({ from, to } the stopped rule's lines), with its
    // frames result and the demand stack.
    async held(stop, scope, stack) {
      state.stop = stop;
      state.scope = scope;
      state.stack = stack ?? [];
      state.relations.clear();
      tab.hidden = false;
      await Promise.all(state.watches.map(evaluate));
      render();
    },
    released() {
      state.stop = null;
      hide();
      render();
    },
    show: () => tab.click(),
    bindingsPopup: (x, y) => state.scope && bindingsPopup(x, y),
  };
}
