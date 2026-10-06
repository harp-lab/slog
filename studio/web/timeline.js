// The session's states, by logical timestamp: t0 is the session before
// anything, and each Run or committed change (`add`, `del`, `flush`, a
// scratch rule, …) makes the next, derived from the one before. Queries
// make none; each is attached, as a prompt, to the state it ran at
// (states.rs keeps them).
//
// At the prompt: the current stamp, and the one it was derived from.
// Clicking a past stamp opens the state tree over the transcript (graph.js
// lays it out); clicking a state there explores it, read-only, or branches
// a new state from it.

import { layout } from "./graph.js";
import { setStates } from "./stamp.js";

const SVG = "http://www.w3.org/2000/svg";

export const stamp = (id) => `t${id}`;

// A state as the author knows it in `view`: its name, else its stamp.
const named = (view, id) => view.states.find((s) => s.id === id)?.name || stamp(id);

// What the prompt shows of `view` ({ states, current, exploring }):
// { now, pred, exploring, home } stamps, `exploring` set while a past
// state is explored; then `now` is that state and `home` the current one.
export function promptStamp(view) {
  const byId = new Map((view?.states ?? []).map((s) => [s.id, s]));
  const shown = view?.exploring ?? view?.current;
  if (shown == null || !byId.has(shown)) return null;
  const pred = byId.get(shown).pred;
  return {
    now: named(view, shown),
    pred: pred == null ? null : named(view, pred),
    exploring: view.exploring != null,
    home: named(view, view.current),
    ids: { now: shown, pred, home: view.current },
  };
}

// Whether `next` made a new state from `before`'s current one: the moment
// the prompt animates the new stamp out of the old.
export const derived = (before, next) =>
  before?.current != null && next.current !== before.current
  && next.states.some((s) => s.id === next.current && s.pred === before.current);

// The states from `id` back to the first.
export function ancestry(view, id) {
  const byId = new Map(view.states.map((s) => [s.id, s]));
  const path = [];
  for (let at = id; at != null && byId.has(at) && !path.includes(at); at = byId.get(at).pred) path.push(at);
  return path;
}

// A state's label in the tree: its stamp and what made it, shortened.
export function label(state, max = 22) {
  // a Run names the file it ran; its directory says little
  const what = state.kind === "start" ? state.line || "start"
    : state.kind === "run" ? state.line.replace(/^run \S*\//, "run ")
    : state.line.replace(/\s+/g, " ");
  const short = what.length > max ? `${what.slice(0, max - 1)}…` : what;
  return state.name ? `${stamp(state.id)} ${state.name}` : `${stamp(state.id)} ${short}`;
}

// The tree for graph.js's layout: { nodes, edges }, each node a state with
// its label and marks — `current`, `explored`, `path` (on the current
// state's ancestry) — and its prompts' count.
export function stateGraph(view) {
  const path = new Set(ancestry(view, view.current));
  const nodes = view.states.map((s) => ({
    id: label(s),
    state: s.id,
    kind: s.kind,
    prompts: s.prompts?.length ?? 0,
    current: s.id === view.current,
    explored: s.id === view.exploring,
    path: path.has(s.id),
  }));
  const ids = new Map(nodes.map((n) => [n.state, n.id]));
  const edges = view.states.filter((s) => ids.has(s.pred)).map((s) => ({ from: ids.get(s.pred), to: ids.get(s.id) }));
  return { nodes, edges };
}

// The tree drawn as SVG; `onPick(id)` is called with a state's id.
export function drawTree(view, onPick) {
  const laid = layout(stateGraph(view), (text) => 6.4 * text.length + 22);
  const svg = svgNode("svg", { width: laid.width, height: laid.height, class: "state-tree" });
  for (const edge of laid.edges) svg.append(svgNode("path", { d: edge.path, class: "sedge" }));
  const byId = new Map(view.states.map((s) => [s.id, s]));
  for (const node of laid.nodes) {
    const classes = ["snode", node.kind, node.current && "current", node.explored && "explored", node.path && "path"];
    const group = svg.appendChild(svgNode("g", {
      class: classes.filter(Boolean).join(" "), transform: `translate(${node.x},${node.y})`, "data-at": node.state,
    }));
    group.append(svgNode("rect", { width: node.w, height: node.h, rx: node.h / 2 }));
    group.appendChild(svgNode("text", { x: node.w / 2, y: node.h / 2 + 4 })).textContent = node.id;
    const state = byId.get(node.state);
    if (node.prompts) {
      // the prompts asked at this state: a badge, listed in its card (stamp.js)
      const badge = group.appendChild(svgNode("g", { class: "prompts", transform: `translate(${node.w - 4},-3)` }));
      badge.append(svgNode("circle", { r: 7 }));
      badge.appendChild(svgNode("text", { y: 3.5 })).textContent = node.prompts > 9 ? "9+" : node.prompts;
    }
    group.addEventListener("click", () => onPick(state.id));
  }
  return svg;
}

// ---- In the page ----------------------------------------------------------------

// `at` is the prompt's stamp, `panel` the tree's place over the transcript;
// `send` reaches the studio. Returns { states(view), entry(entry, node) }:
// the states as they change, and each transcript entry, to stamp.
export function initTimeline({ at, panel, send }) {
  let view = null;
  let pending = null; // a state asked to be explored, not yet re-derived
  const reduced = matchMedia("(prefers-reduced-motion: reduce)");

  const head = panel.appendChild(element("div", "state-tree-head"));
  const body = panel.appendChild(element("div", "state-tree-body"));
  panel.hidden = true;
  addEventListener("keydown", (event) => {
    if (event.key === "Escape" && !panel.hidden) panel.hidden = true;
  });

  // Explore `id`, or, for the current state, come back to it.
  function pick(id) {
    if (!view) return;
    const back = id === view.current;
    if (!back && id === view.exploring) return;
    pending = back ? null : id;
    send({ t: "explore", id: back ? null : id });
    render();
  }

  function branch(id) {
    pending = null;
    panel.hidden = true;
    send({ t: "branch-state", id });
  }

  function toggle() {
    panel.hidden = !panel.hidden;
    render();
  }

  function render() {
    renderPrompt();
    if (!panel.hidden) renderTree();
  }

  function renderPrompt() {
    const shown = promptStamp(view);
    at.replaceChildren();
    at.classList.toggle("exploring", Boolean(shown?.exploring));
    if (!shown) return;
    if (pending != null) {
      at.append(element("span", "now", named(view, pending)), element("span", "quiet", " re-deriving…"));
      return;
    }
    if (shown.exploring) {
      at.append(element("span", "quiet", "exploring"));
      const now = at.appendChild(button("now", shown.now, shown.ids.now));
      now.addEventListener("click", toggle);
      at.append(element("span", "quiet", "(read-only) ·"));
      const back = at.appendChild(button("link", `return to ${shown.home}`));
      back.addEventListener("click", () => pick(view.current));
      at.append(element("span", "quiet", "·"));
      const fork = at.appendChild(button("link", "branch from here"));
      fork.title = `Continue from ${shown.now}: re-derive it as a new state`;
      fork.addEventListener("click", () => branch(view.exploring));
      return;
    }
    const now = at.appendChild(button("now", shown.now, shown.ids.now));
    now.addEventListener("click", toggle);
    if (shown.pred) {
      at.append(element("span", "from", "⟵"));
      const pred = at.appendChild(button("pred", shown.pred, shown.ids.pred));
      pred.addEventListener("click", () => {
        panel.hidden = false;
        render();
      });
    }
  }

  function renderTree() {
    head.replaceChildren(element("span", "state-tree-title", "Session states"));
    head.append(element("span", "hint", view?.exploring != null
      ? `exploring ${named(view, view.exploring)}, read-only`
      : "click a state to explore it, read-only · double-click to name it"));
    if (view?.exploring != null) {
      const fork = head.appendChild(button("secondary small", `Branch from ${named(view, view.exploring)}`));
      fork.title = "Continue from the explored state";
      fork.addEventListener("click", () => branch(view.exploring));
    }
    const close = head.appendChild(button("quiet small", "×"));
    close.title = "Close (Esc)";
    close.addEventListener("click", toggle);
    if (!view) return body.replaceChildren();
    body.replaceChildren(drawTree(view, pick));
    // the state the prompt stands at, in view
    const focus = body.querySelector(".snode.explored") ?? body.querySelector(".snode.current");
    focus?.scrollIntoView?.({ block: "nearest", inline: "center" });
  }

  function states(next) {
    const grew = derived(view, next);
    if (next.exploring === pending || next.exploring == null) pending = null;
    view = { states: next.states, current: next.current, exploring: next.exploring };
    setStates(view);
    render();
    // the new stamp sprouts from the one it was derived from
    if (grew && !reduced.matches) {
      at.classList.remove("derive");
      void at.offsetWidth;
      at.classList.add("derive");
    }
  }

  // A quiet stamp in the entry's gutter; a click opens the tree.
  function entry(entry, node) {
    if (!entry.state) return;
    node.classList.toggle("explored", Boolean(entry.exploring));
    const mark = button("tstamp state-name", view ? named(view, entry.state.id) : stamp(entry.state.id), entry.state.id);
    mark.addEventListener("click", () => {
      panel.hidden = false;
      render();
    });
    node.prepend(mark);
  }

  return {
    states,
    entry,
    // open the tree
    show() {
      panel.hidden = false;
      render();
    },
  };
}

function element(tag, className, text) {
  const node = document.createElement(tag);
  if (className) node.className = className;
  if (text !== undefined) node.textContent = text;
  return node;
}

// A button; with `at`, a state's stamp, whose card and rename stamp.js
// gives every `data-at`.
function button(className, text, at = null) {
  const node = element("button", className, text);
  node.type = "button";
  if (at !== null) node.dataset.at = at;
  return node;
}

function svgNode(tag, attributes = {}) {
  const node = document.createElementNS(SVG, tag);
  for (const [name, value] of Object.entries(attributes)) node.setAttribute(name, value);
  return node;
}
