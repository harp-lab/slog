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
import { drivingRow } from "./where.js";

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

// Stops of a debug session the tree draws, the newest; earlier ones fold
// into one node.
const STOPS = 6;

// A debug stop's label in the tree: its iteration, port and rule line.
export function stopLabel(stop) {
  const at = stop.at ?? {};
  const where = at.port ? `${at.port}${at.relation ? ` ${at.relation}` : ""}` : at.phase === "iter" ? "boundary" : "read";
  const line = /:(\d+):\d+$/.exec(at.source ?? "")?.[1];
  return `⏸ it ${at.iteration ?? "?"} · ${where}${line ? ` :${line}` : ""}`;
}

// The tree for graph.js's layout: { nodes, edges }, each node a state with
// its label and marks — `current`, `explored`, `path` (on the current
// state's ancestry) — and its prompts' count. A run held at stops (a debug
// session, states.rs `Debug`) hangs off the state it started from as a
// chain of its stops, `stop` nodes; once it commits it folds into the
// state it made, which counts its stops (`debug`), unless `expanded` names
// it. A rewind's rerun hangs off the state it branched from.
export function stateGraph(view, expanded = new Set()) {
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
  const byState = new Map(nodes.map((n) => [n.state, n]));
  for (const debug of view.debugs ?? []) {
    if (!ids.has(debug.from) || !debug.stops.length) continue;
    const folded = debug.into != null && ids.has(debug.into) && !expanded.has(debug.id);
    if (folded) {
      byState.get(debug.into).debug = { id: debug.id, stops: debug.stops.length + (debug.dropped ?? 0) };
      continue;
    }
    const first = Math.max(0, debug.stops.length - STOPS);
    let previous = ids.get(debug.from);
    const hidden = first + (debug.dropped ?? 0);
    if (hidden) {
      const id = `d${debug.id}.earlier`;
      nodes.push({ id, text: `⏸ ${hidden} earlier stop${hidden === 1 ? "" : "s"}`, kind: "stop earlier", debug: debug.id });
      edges.push({ from: previous, to: id, debug: true });
      previous = id;
    }
    debug.stops.forEach((stop, k) => {
      if (k < first) return;
      const id = `d${debug.id}.${k}`;
      const last = k === debug.stops.length - 1;
      nodes.push({
        id, text: stopLabel(stop), kind: "stop", debug: debug.id, stop: k,
        held: last && !debug.ended, aborted: last && debug.ended === "aborted",
      });
      edges.push({ from: previous, to: id, debug: true });
      previous = id;
    });
    if (debug.into != null && ids.has(debug.into)) edges.push({ from: previous, to: ids.get(debug.into), debug: true, fold: true });
  }
  return { nodes, edges };
}

// The tree drawn as SVG; `onPick(id)` is called with a state's id,
// `onStop(debug, stop)` with a debug stop's, `onFold(debug)` with a debug
// session to unfold or fold again; `expanded` names the unfolded ones.
export function drawTree(view, onPick, { onStop = () => {}, onFold = () => {}, expanded = new Set() } = {}) {
  const graph = stateGraph(view, expanded);
  const texts = new Map(graph.nodes.map((n) => [n.id, n.text ?? n.id]));
  const laid = layout(graph, (id) => 6.4 * (texts.get(id) ?? id).length + 22);
  const svg = svgNode("svg", { width: laid.width, height: laid.height, class: "state-tree" });
  for (const edge of laid.edges) {
    const classes = ["sedge", edge.debug && "debug", edge.fold && "fold"];
    svg.append(svgNode("path", { d: edge.path, class: classes.filter(Boolean).join(" ") }));
  }
  const byId = new Map(view.states.map((s) => [s.id, s]));
  for (const node of laid.nodes) {
    if (node.state === undefined) {
      // a debug session's stop: its recorded place, read-only
      const classes = ["snode", ...node.kind.split(" "), node.held && "held", node.aborted && "aborted"];
      const group = svg.appendChild(svgNode("g", {
        class: classes.filter(Boolean).join(" "), transform: `translate(${node.x},${node.y})`,
      }));
      group.append(svgNode("rect", { width: node.w, height: node.h, rx: 5 }));
      group.appendChild(svgNode("text", { x: node.w / 2, y: node.h / 2 + 4 })).textContent = node.text;
      group.addEventListener("click", () => (node.stop === undefined ? onFold(node.debug) : onStop(node.debug, node.stop)));
      continue;
    }
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
    if (node.debug) {
      // the debug session it committed from, folded: a click unfolds it
      const fold = group.appendChild(svgNode("g", { class: "folded-stops", transform: `translate(${node.w - 2},${node.h + 2})` }));
      fold.append(svgNode("rect", { x: -30, y: -7, width: 34, height: 14, rx: 7 }));
      fold.appendChild(svgNode("text", { x: -13, y: 3.5 })).textContent = `⏸${node.debug.stops}`;
      fold.appendChild(svgNode("title")).textContent = `committed from a run held at ${node.debug.stops} stop${node.debug.stops === 1 ? "" : "s"}: click to unfold them`;
      fold.addEventListener("click", (event) => {
        event.stopPropagation();
        onFold(node.debug.id);
      });
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
  const expanded = new Set(); // debug sessions unfolded from their state
  let card = null; // { debug, stop }: a stop shown, read-only
  const reduced = matchMedia("(prefers-reduced-motion: reduce)");

  const head = panel.appendChild(element("div", "state-tree-head"));
  const body = panel.appendChild(element("div", "state-tree-body"));
  const stopCard = panel.appendChild(element("div", "stop-card"));
  stopCard.hidden = true;
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
    body.replaceChildren(drawTree(view, pick, {
      expanded,
      onFold(debug) {
        if (expanded.has(debug)) expanded.delete(debug);
        else expanded.add(debug);
        renderTree();
      },
      onStop(debug, stop) {
        card = { debug, stop };
        renderCard();
      },
    }));
    renderCard();
    // the state the prompt stands at, in view
    const focus = body.querySelector(".snode.stop.held") ?? body.querySelector(".snode.explored") ?? body.querySelector(".snode.current");
    focus?.scrollIntoView?.({ block: "nearest", inline: "center" });
  }

  // A stop revisited: where the run stood and its bindings, as recorded
  // then. The run cannot go back there, so this is read-only.
  function renderCard() {
    const debug = card && view?.debugs?.find((d) => d.id === card.debug);
    const stop = debug?.stops[card.stop];
    stopCard.hidden = !stop;
    if (!stop) return;
    const at = stop.at ?? {};
    stopCard.replaceChildren(
      element("div", "stop-card-title", `${stopLabel(stop)} — ${stop.title}`),
      element("div", "stop-card-where", [
        `stop ${card.stop + 1 + (debug.dropped ?? 0)} of the run held from ${named(view, debug.from)}`,
        at.stratum && `stratum ${at.stratum}${at.flavor && at.flavor !== "normal" ? ` ${at.flavor}` : ""}`,
        at.iteration != null && `iteration ${at.iteration}`,
        at.source && `rule ${at.source}`,
        at["driver-rows"] > 0 && `row ${at["driver-row"]} of ${at["driver-rows"]}`,
        `after ${stop.line.replace(/^run \S*\//, "run ")}`,
      ].filter(Boolean).join(" · ")),
    );
    if (at.row) stopCard.append(element("div", "stop-card-row", drivingRow(at)));
    for (const [name, value] of at.bindings ?? []) {
      stopCard.append(element("div", "stop-card-binding", `${name} = ${value}`));
    }
    stopCard.append(element("div", "hint", "recorded at the stop: the run has moved on, so this is read-only"));
    const close = stopCard.appendChild(button("quiet small", "×"));
    close.addEventListener("click", () => {
      card = null;
      renderCard();
    });
  }

  function states(next) {
    const grew = derived(view, next);
    if (next.exploring === pending || next.exploring == null) pending = null;
    view = { states: next.states, current: next.current, exploring: next.exploring, debugs: next.debugs ?? [] };
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
    // Open the tree, where the held run's stops are.
    open() {
      panel.hidden = false;
      render();
    },
    // The state the held run started from, as the author knows it.
    heldFrom() {
      const debug = view?.debugs?.at(-1);
      return debug && !debug.ended ? named(view, debug.from) : view ? named(view, view.current) : null;
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
