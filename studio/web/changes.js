// The change graph as a small panel over the editor: what a change does to
// the program's relations and rules against a baseline (graph.js), drawn
// as SVG. It opens only when asked for, from the proposal bar or from a
// version being compared, and closes with Escape or its ×.

import { changeGraph, layout } from "./graph.js";

const SVG = "http://www.w3.org/2000/svg";

export function createChangePanel(host) {
  const panel = host.appendChild(element("div", "changes"));
  panel.hidden = true;
  const head = panel.appendChild(element("div", "changes-head"));
  const title = head.appendChild(element("span", "changes-title"));
  const controls = head.appendChild(element("span", "changes-controls"));
  const close = head.appendChild(element("button", "quiet small", "×"));
  close.title = "Close (Esc)";
  const body = panel.appendChild(element("div", "changes-body"));
  const legend = panel.appendChild(element("div", "changes-legend"));
  for (const [status, text] of [["added", "added"], ["removed", "removed"], ["changed", "changed"], ["same", "context"]]) {
    legend.append(element("span", `key ${status}`, text));
  }
  let current = null;

  close.addEventListener("click", hide);
  addEventListener("keydown", (event) => {
    if (event.key === "Escape" && !panel.hidden) hide();
  });

  function hide() {
    panel.hidden = true;
    current?.onClose?.();
    current = null;
  }

  // `before` and `after`: the file texts of each program; `onNode(id)`
  // shows a relation's forms; `tools`, nodes for the head. `owner` names
  // who shows it: another owner's graph is closed (`onClose`) first.
  function show({ owner, heading, before, after, onNode, tools = [], onClose }) {
    if (current && current.owner !== owner) hide();
    current = { owner, onClose };
    title.textContent = heading;
    controls.replaceChildren(...tools);
    const graph = changeGraph(before, after);
    body.replaceChildren(graph.nodes.length
      ? draw(layout(graph), onNode)
      : element("p", "hint", "No relation or rule changes: only layout or comments differ."));
    panel.hidden = false;
  }

  return { show, hide, shown: () => !panel.hidden };
}

function draw(laid, onNode) {
  const svg = svgNode("svg", { width: laid.width, height: laid.height, class: "change-graph" });
  const defs = svg.appendChild(svgNode("defs"));
  for (const status of ["added", "removed", "same"]) {
    const marker = defs.appendChild(svgNode("marker", {
      id: `arrow-${status}`, viewBox: "0 0 8 8", refX: 7, refY: 4, markerWidth: 7, markerHeight: 7, orient: "auto",
    }));
    marker.append(svgNode("path", { d: "M0,0 L8,4 L0,8 z", class: `arrow ${status}` }));
  }
  for (const edge of laid.edges) {
    svg.append(svgNode("path", { d: edge.path, class: `edge ${edge.status}`, "marker-end": `url(#arrow-${edge.status})` }));
  }
  for (const node of laid.nodes) {
    const group = svg.appendChild(svgNode("g", { class: `node ${node.status} ${node.kind}`, transform: `translate(${node.x},${node.y})` }));
    // a declared relation is a box, one only used or derived a pill
    group.append(svgNode("rect", { width: node.w, height: node.h, rx: node.kind === "relation" ? node.h / 2 : 4 }));
    const label = group.appendChild(svgNode("text", { x: node.w / 2, y: node.h / 2 + 4 }));
    label.textContent = node.id;
    const tip = group.appendChild(svgNode("title"));
    tip.textContent = `${node.kind === "relation" ? "" : `${node.kind} `}${node.id}: ${node.status === "same" ? "unchanged" : node.status}`;
    group.addEventListener("click", () => onNode?.(node.id));
  }
  return svg;
}

function svgNode(tag, attributes = {}) {
  const node = document.createElementNS(SVG, tag);
  for (const [name, value] of Object.entries(attributes)) node.setAttribute(name, value);
  return node;
}

function element(tag, className, text) {
  const node = document.createElement(tag);
  node.className = className;
  if (text !== undefined) node.textContent = text;
  return node;
}
