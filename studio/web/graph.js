// Two small graphs, worked out here and drawn as SVG by their callers:
// - the change graph: what a change does to the program's relations and
//   rules, against a baseline. Nodes are relations and declarations, edges
//   run from a rule's body relations to its heads (the form scanner's view of
//   a program), each marked added, removed, changed or same;
// - the version graph: the project's versions in lanes, one per branch.
// Both are laid out by hand: a layered layout for the first, lanes by time
// for the second.

import { forms } from "./forms.js";
import { isName, tokens } from "./lexer.js";

const DECLARES = new Set(["table", "struct", "union", "enum", "lattice", "demand", "extern"]);

// ---- What a program declares and derives -----------------------------------

// Each declaration and rule of `text`: { keyword, name, normal, line } or { keyword:
// "rule", heads, body, normal, line }, `normal` being its tokens without comments
// or layout, to tell whether it changed.
export function relations(text) {
  const out = [];
  for (const form of forms(text)) {
    const source = text.slice(form.start, form.end);
    const words = tokens(source).filter((token) => token.kind !== "comment")
      .map((token) => ({ kind: token.kind, text: source.slice(token.start, token.end) }));
    const normal = words.map((word) => word.text).join(" ");
    if (DECLARES.has(form.keyword)) {
      const at = words.findIndex((word) => word.text === "(");
      const name = words[at + 1];
      if (at >= 0 && name?.kind === "word" && isName(name.text)) out.push({ keyword: form.keyword, name: name.text, normal, line: form.line });
    } else if (form.keyword === "rule") {
      out.push({ keyword: "rule", ...atoms(words), normal, line: form.line });
    }
  }
  return out;
}

// A rule's heads and body relations: the atoms after its last `-->` or
// before its first `<--` are heads, as are all of a rule with neither (facts).
// forms.rs `heads`, which keys versions by the same reading.
function atoms(words) {
  const found = [];
  let forward = -1;
  let backward = -1;
  let depth = 0;
  words.forEach((word, at) => {
    if (word.kind === "open") {
      const next = words[at + 1];
      if (depth === 0 && word.text === "(" && next?.kind === "word" && isName(next.text)) found.push({ at, name: next.text });
      depth++;
    } else if (word.kind === "close") depth = Math.max(0, depth - 1);
    else if (depth === 0 && word.text === "-->") forward = at;
    else if (depth === 0 && word.text === "<--" && backward < 0) backward = at;
  });
  const head = ({ at }) => forward >= 0 ? at > forward : backward >= 0 ? at < backward : true;
  const names = (list) => [...new Set(list.map(({ name }) => name))];
  return { heads: names(found.filter(head)), body: names(found.filter((atom) => !head(atom))) };
}

function graphOf(texts) {
  const nodes = new Map(); // name -> { kind, forms: [normal] }
  const edges = new Set(); // "from\nto"
  const node = (name) => {
    if (!nodes.has(name)) nodes.set(name, { kind: "relation", forms: [] });
    return nodes.get(name);
  };
  for (const item of texts.flatMap(relations)) {
    if (item.keyword !== "rule") {
      Object.assign(node(item.name), { kind: item.keyword }).forms.push(item.normal);
      continue;
    }
    for (const head of item.heads) {
      node(head).forms.push(item.normal);
      for (const body of item.body) {
        node(body);
        edges.add(`${body}\n${head}`);
      }
    }
  }
  return { nodes, edges };
}

// What changed from the program `before` to `after` (each a list of file
// texts), as { nodes: [{ id, kind, status }], edges: [{ from, to, status }] }
// with status "added", "removed", "changed" or "same". Only the changes and
// their neighbours are kept; a relation changed when a declaration of it or
// a rule deriving it did.
export function changeGraph(before, after) {
  const a = graphOf(before);
  const b = graphOf(after);
  const sameForms = (x, y) => JSON.stringify([...x.forms].sort()) === JSON.stringify([...y.forms].sort());
  const nodes = new Map();
  for (const id of new Set([...a.nodes.keys(), ...b.nodes.keys()])) {
    const x = a.nodes.get(id);
    const y = b.nodes.get(id);
    const status = !x ? "added" : !y ? "removed" : sameForms(x, y) ? "same" : "changed";
    nodes.set(id, { id, kind: (y ?? x).kind, status });
  }
  const edges = [...new Set([...a.edges, ...b.edges])].map((key) => {
    const [from, to] = key.split("\n");
    return { from, to, status: !a.edges.has(key) ? "added" : !b.edges.has(key) ? "removed" : "same" };
  });
  const focus = new Set([...nodes.values()].filter((n) => n.status !== "same").map((n) => n.id));
  for (const edge of edges) if (edge.status !== "same") focus.add(edge.from).add(edge.to);
  const kept = new Set(focus);
  for (const { from, to } of edges) {
    if (focus.has(from)) kept.add(to);
    if (focus.has(to)) kept.add(from);
  }
  return {
    nodes: [...nodes.values()].filter((n) => kept.has(n.id)),
    edges: edges.filter((e) => kept.has(e.from) && kept.has(e.to)),
  };
}

// ---- A layered layout ---------------------------------------------------------

// Positions for `graph`'s nodes, left to right by layer: each node one
// column past the furthest of its predecessors, cycles broken where a
// depth-first walk meets them, and each column ordered by its neighbours'
// places. Nodes gain { x, y, w, h, layer }; edges gain `path`, an SVG path,
// and `back` when they run against the layers.
export function layout(graph, width = (text) => 7 * text.length + 20) {
  const H = 22;
  const ROW = 34;
  const GAP = 56;
  const ids = graph.nodes.map((n) => n.id);
  const out = new Map(ids.map((id) => [id, []]));
  for (const { from, to } of graph.edges) if (from !== to) out.get(from).push(to);
  // back edges: those reaching a node still being walked
  const back = new Set();
  const state = new Map();
  const walk = (id) => {
    state.set(id, "open");
    for (const next of out.get(id)) {
      if (state.get(next) === "open") back.add(`${id}\n${next}`);
      else if (!state.has(next)) walk(next);
    }
    state.set(id, "done");
  };
  for (const id of ids) if (!state.has(id)) walk(id);
  const forward = graph.edges.filter((e) => e.from !== e.to && !back.has(`${e.from}\n${e.to}`));
  const layer = new Map(ids.map((id) => [id, 0]));
  // longest path; at most |nodes| rounds on a DAG
  for (let round = 0, moved = true; moved && round < ids.length; round++) {
    moved = false;
    for (const { from, to } of forward) {
      if (layer.get(to) < layer.get(from) + 1) { layer.set(to, layer.get(from) + 1); moved = true; }
    }
  }
  const columns = [];
  for (const id of ids) (columns[layer.get(id)] ??= []).push(id);
  const place = new Map();
  const index = () => columns.forEach((column) => column.forEach((id, i) => place.set(id, i)));
  index();
  const mean = (list) => list.length ? list.reduce((sum, id) => sum + place.get(id), 0) / list.length : null;
  for (let sweep = 0; sweep < 4; sweep++) {
    const order = sweep % 2 ? [...columns.keys()].reverse() : [...columns.keys()];
    for (const c of order) {
      const near = (id) => forward.filter((e) => sweep % 2 ? e.from === id : e.to === id).map((e) => sweep % 2 ? e.to : e.from);
      const key = new Map(columns[c].map((id) => [id, mean(near(id)) ?? place.get(id)]));
      columns[c].sort((p, q) => key.get(p) - key.get(q));
      index();
    }
  }
  const tallest = Math.max(1, ...columns.map((column) => column.length));
  const nodes = new Map();
  let x = 12;
  for (const [c, column] of columns.entries()) {
    const w = Math.max(...column.map((id) => width(id)));
    const top = 16 + ((tallest - column.length) * ROW) / 2;
    column.forEach((id, i) => nodes.set(id, { w: width(id), h: H, x: x + (w - width(id)) / 2, y: top + i * ROW, layer: c }));
    x += w + GAP;
  }
  const edges = graph.edges.map((edge) => {
    const a = nodes.get(edge.from);
    const b = nodes.get(edge.to);
    if (edge.from === edge.to) {
      const m = a.x + a.w / 2;
      return { ...edge, path: `M${m - 6},${a.y} C${m - 16},${a.y - 16} ${m + 16},${a.y - 16} ${m + 6},${a.y}` };
    }
    if (b.layer <= a.layer) {
      const [sx, tx] = [a.x + a.w / 2, b.x + b.w / 2];
      const low = Math.max(a.y, b.y) + H + 18;
      return { ...edge, back: true, path: `M${sx},${a.y + H} C${sx},${low} ${tx},${low} ${tx},${b.y + H}` };
    }
    const [sx, sy, tx, ty] = [a.x + a.w, a.y + H / 2, b.x, b.y + H / 2];
    const bend = (tx - sx) / 2;
    return { ...edge, path: `M${sx},${sy} C${sx + bend},${sy} ${tx - bend},${ty} ${tx},${ty}` };
  });
  return {
    nodes: graph.nodes.map((n) => ({ ...n, ...nodes.get(n.id) })),
    edges,
    width: x - GAP + 12,
    height: 16 + tallest * ROW + 24,
  };
}

// ---- The version graph --------------------------------------------------------

// The versions as nodes in lanes, one lane per branch (the current one
// first), and columns in the order they were made. Runs of three or more
// edits one after another collapse into one node unless their newest id is
// in `expanded`. Nodes: { key, ids, lane, col }, the newest of `ids` the
// one they show; edges: { from, to } keys, parent to child.
export function versionGraph(versions, refs, expanded = new Set()) {
  const byId = new Map(versions.map((v) => [v.id, v]));
  const branches = Object.entries(refs.branches ?? {})
    .sort(([a, x], [b, y]) => (a === refs.current) - (b === refs.current) || x - y)
    .reverse();
  const lane = new Map();
  branches.forEach(([, head], n) => {
    for (let id = head; id != null && !lane.has(id); id = byId.get(id)?.parents[0]) lane.set(id, n);
  });
  const children = new Map();
  for (const v of versions) for (const p of v.parents) children.set(p, (children.get(p) ?? 0) + 1);
  const heads = new Set(branches.map(([, head]) => head));
  // an edit that only leads on to the next edit, in its lane
  const plain = (v) => v.origin.kind === "auto" && !heads.has(v.id) && children.get(v.id) === 1;
  const nodes = [];
  const keyOf = new Map();
  const ordered = [...versions].sort((a, b) => a.id - b.id);
  for (let i = 0; i < ordered.length; ) {
    const run = [ordered[i++]];
    while (plain(run.at(-1)) && ordered[i] && plain(ordered[i]) && ordered[i].parents[0] === run.at(-1).id
      && lane.get(ordered[i].id) === lane.get(run[0].id)) run.push(ordered[i++]);
    const groups = run.length >= 3 && !expanded.has(run.at(-1).id) ? [run] : run.map((v) => [v]);
    for (const group of groups) {
      const key = group.length > 1 ? `r${group[0].id}` : `v${group[0].id}`;
      for (const v of group) keyOf.set(v.id, key);
      nodes.push({ key, ids: group.map((v) => v.id), lane: lane.get(group[0].id) ?? branches.length, col: nodes.length });
    }
  }
  const edges = [];
  for (const node of nodes) {
    for (const parent of byId.get(node.ids[0]).parents) {
      if (keyOf.has(parent)) edges.push({ from: keyOf.get(parent), to: node.key });
    }
  }
  return { nodes, edges, lanes: branches.map(([name]) => name) };
}
