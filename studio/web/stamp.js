// A relation's time: every view of rows was read at a session state
// (states.rs), and says which, as a superscript on its name: r2ᵗ¹, or the
// state's name once it has one (r2^baseline). A view of an older state than
// the session's is tinted "past". Hovering a stamp shows its state's card;
// double-clicking one names the state.
//
// One module keeps the states as last told (`setStates`), so a stamp is
// rendered from a state's id alone and follows a rename: every stamp in the
// page carries `data-at`, and `refresh` renders them again.
//
//   stamped(name, at)    the name with its superscript, an element
//   stampedText(name, at) the same as text ("r2 @t1"), where only text goes
//   stateName(at)        "baseline", else "t1"
//   isPast(at)           at is not the session's current state
//   cardLines(at)        the hover card's lines
// `at` is a state's id or a stamp { id, pred }; null renders no stamp.

let view = { states: [], current: null, exploring: null };
const sets = new Map(); // result set id -> the state id it was read at
const listeners = new Set();

export const idOf = (at) => (at !== null && typeof at === "object" ? at.id : at) ?? null;
const stateOf = (at) => view.states[idOf(at)] ?? null;

export function setStates(next) {
  view = { states: next.states ?? [], current: next.current ?? null, exploring: next.exploring ?? null };
  for (const listener of listeners) listener(view);
  if (globalThis.document) refresh();
}

export const states = () => view;

// Called with the states on every change; returns the unsubscribe.
export function onStates(listener) {
  listeners.add(listener);
  return () => listeners.delete(listener);
}

// A result set's view, so the stamps of queries naming it, and its state's
// card, know it.
export function noteSet(setView) {
  if (setView?.state) sets.set(setView.id, setView.state.id);
}

export const setState = (id) => sets.get(id) ?? null;

export function stateName(at) {
  const id = idOf(at);
  if (id === null) return "";
  return stateOf(id)?.name || `t${id}`;
}

export const isPast = (at) => idOf(at) !== null && view.current !== null && idOf(at) !== view.current;

export function stampedText(name, at) {
  return idOf(at) === null ? name : `${name} @${stateName(at)}`;
}

// What made a state, in a line: "Run main.slog v3 · 2 strata · 120 ms ·
// path +6, edge +3", "add (edge 3 4) · path +3", "branch from t3".
export function madeBy(state) {
  if (!state) return "";
  const what = state.kind === "start" ? (state.line || "the session before anything")
    : state.kind === "run" ? `Run ${state.line.replace(/^run \S*\//, "").replace(/^run /, "")}${state.version != null ? ` v${state.version}` : ""}`
    : state.kind === "branch" ? state.line.replace(/t(\d+)$/, (_, id) => stateName(Number(id)))
    : state.line;
  const signed = (n) => (n > 0 ? `+${n}` : `${n}`);
  return [
    what,
    state.strata != null && state.kind === "run" ? `${state.strata} strat${state.strata === 1 ? "um" : "a"}` : null,
    state.ms != null ? `${state.ms} ms` : null,
    state.deltas?.length ? state.deltas.map((d) => `${d.relation} ${signed(d.net)}`).join(", ") : null,
  ].filter(Boolean).join(" · ");
}

// The hover card of a state: its name and stamp, what made it, where it
// came from, what was asked there, and the result sets read at it.
export function cardLines(at) {
  const state = stateOf(at);
  if (!state) return [];
  const id = state.id;
  const head = state.name ? `${state.name} · t${id}` : `t${id}`;
  const marks = [id === view.current ? "current" : null, id === view.exploring ? "exploring" : null].filter(Boolean);
  const read = [...sets].filter(([, at]) => at === id).map(([set]) => set);
  const asked = (state.prompts ?? []).slice(-3).map((p) => `${p.ok ? "›" : "✗"} ${p.line}`);
  return [
    marks.length ? `${head} (${marks.join(", ")})` : head,
    madeBy(state),
    state.pred != null ? `from ${stateName(state.pred)}` : null,
    ...(asked.length ? [`asked here${state.prompts.length > 3 ? ` (last 3 of ${state.prompts.length})` : ""}:`, ...asked.map((a) => `  ${a}`)] : []),
    read.length ? `sets: ${read.join(", ")}` : null,
  ].filter(Boolean);
}

// ---- In the page ----------------------------------------------------------------

// `name` with its state as a superscript; `className` is added to the
// wrapper. The wrapper is tinted when the state is past.
export function stamped(name, at, { tag = "span", className = "" } = {}) {
  const node = document.createElement(tag);
  node.className = `stamped ${className}`.trim();
  node.append(name);
  const id = idOf(at);
  if (id === null) return node;
  node.appendChild(document.createElement("sup")).className = "at";
  node.dataset.at = id;
  paint(node);
  return node;
}

// `text` with each result set it names (r1, r2, …) stamped.
export function stampNames(text) {
  const out = document.createDocumentFragment();
  let last = 0;
  for (const match of text.matchAll(/\br(\d+)\b/g)) {
    const at = setState(match[0]);
    if (at === null) continue;
    out.append(text.slice(last, match.index), stamped(match[0], at));
    last = match.index + match[0].length;
  }
  out.append(text.slice(last));
  return out;
}

function paint(node) {
  const id = Number(node.dataset.at);
  node.querySelector(":scope > sup.at").textContent = stateName(id);
  node.classList.toggle("past", isPast(id));
}

// Render every stamp in `root` again: after a rename, or a new state. An
// element of class `state-name` is its state's name alone.
export function refresh(root = document) {
  for (const node of root.querySelectorAll(".stamped[data-at]")) paint(node);
  for (const node of root.querySelectorAll(".state-name[data-at]")) node.textContent = stateName(Number(node.dataset.at));
}

// The hover card and the rename, for every element with `data-at` in the
// page; `send` reaches the studio.
export function installStamps({ send }) {
  const card = document.body.appendChild(document.createElement("div"));
  card.className = "state-card";
  card.hidden = true;
  let over = null;
  document.addEventListener("pointerover", (event) => {
    const target = event.target.closest?.("[data-at]");
    if (target === over) return;
    over = target;
    if (!target) return void (card.hidden = true);
    const lines = cardLines(Number(target.dataset.at));
    if (!lines.length) return void (card.hidden = true);
    card.replaceChildren(...lines.map((line, i) => {
      const row = document.createElement("div");
      row.className = i === 0 ? "head" : line.startsWith("  ") ? "asked" : "";
      row.textContent = line.trim();
      return row;
    }));
    const hint = card.appendChild(document.createElement("div"));
    hint.className = "how";
    hint.textContent = "double-click to name it";
    card.hidden = false;
    const box = target.getBoundingClientRect();
    const width = card.offsetWidth;
    card.style.left = `${Math.max(8, Math.min(innerWidth - width - 8, box.left))}px`;
    const below = box.bottom + 6 + card.offsetHeight < innerHeight;
    card.style.top = `${below ? box.bottom + 6 : box.top - card.offsetHeight - 6}px`;
  });
  document.addEventListener("dblclick", (event) => {
    const target = event.target.closest?.("[data-at]");
    if (!target) return;
    event.preventDefault();
    event.stopPropagation();
    card.hidden = true;
    rename(Number(target.dataset.at), target.getBoundingClientRect(), send);
  }, true);
}

// A small field over the stamp: Enter names the state, Escape leaves it.
function rename(id, box, send) {
  const input = document.body.appendChild(document.createElement("input"));
  input.className = "state-rename";
  input.value = stateOf(id)?.name ?? "";
  input.placeholder = `name t${id}`;
  input.style.left = `${Math.max(8, box.left - 4)}px`;
  input.style.top = `${box.top - 3}px`;
  input.focus();
  input.select();
  let done = false;
  const finish = (keep) => {
    if (done) return;
    done = true;
    if (keep) send({ t: "name-state", id, name: input.value });
    input.remove();
  };
  input.addEventListener("keydown", (event) => {
    event.stopPropagation();
    if (event.key === "Enter") finish(true);
    else if (event.key === "Escape") finish(false);
  });
  input.addEventListener("blur", () => finish(true));
}
