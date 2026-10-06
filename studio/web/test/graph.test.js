// The change graph (relations and rule dependencies, marked against a
// baseline), its layered layout, and the version graph's lanes.

import { changeGraph, layout, relations, versionGraph } from "../graph.js";
import { corpusFiles, equal, ok } from "./check.js";

const BASE = [
  "table (edge int int)",
  "table (path int int)",
  "table (unrelated int)",
  "rule (edge 1 2) (edge 2 3)",
  "rule (edge X Y) --> (path X Y)",
  "rule (path X Z) <-- (path X Y) (edge Y Z) ;; extend",
].join("\n");

equal("rules read as heads and bodies, either way round", relations(BASE).filter((r) => r.keyword === "rule")
  .map(({ heads, body }) => [heads, body]), [[["edge"], []], [["path"], ["edge"]], [["path"], ["path", "edge"]]]);

const summary = (graph) => [
  graph.nodes.map((n) => `${n.id}:${n.status}`).sort(),
  graph.edges.map((e) => `${e.from}>${e.to}:${e.status}`).sort(),
];

equal("nothing changed, nothing shown", summary(changeGraph([BASE], [BASE.replace(" ;; extend", "\n")])), [[], []]);

equal("a new relation and rule, with their neighbours as context", summary(changeGraph([BASE],
  [`${BASE}\ntable (reach int)\nrule (path 1 X) --> (reach X)`])), [
  ["edge:same", "path:same", "reach:added"],
  ["edge>path:same", "path>path:same", "path>reach:added"],
]);

equal("an edited rule changes what it derives; a dropped body atom removes its edge", summary(changeGraph([BASE],
  [BASE.replace("(path X Y) (edge Y Z)", "(edge X Z)")])), [
  ["edge:same", "path:changed"],
  ["edge>path:same", "path>path:removed"],
]);

{
  // a cycle, a self-loop and a chain
  const graph = {
    nodes: ["a", "b", "c", "d"].map((id) => ({ id })),
    edges: [["a", "b"], ["b", "c"], ["c", "a"], ["c", "d"], ["d", "d"]].map(([from, to]) => ({ from, to })),
  };
  const laid = layout(graph);
  const at = new Map(laid.nodes.map((n) => [n.id, n]));
  ok("edges not breaking a cycle run left to right", laid.edges.filter((e) => !e.back && e.from !== e.to)
    .every((e) => at.get(e.from).x + at.get(e.from).w < at.get(e.to).x));
  equal("the cycle is broken once", laid.edges.filter((e) => e.back).map((e) => `${e.from}>${e.to}`), ["c>a"]);
  ok("every path is drawn", laid.edges.every((e) => /^M[\d.]+,[\d.]+ C/.test(e.path)));
}

for (const { name, text } of corpusFiles()) {
  const empty = changeGraph([""], [text]);
  ok(`${name}: every relation of a new program is added`, empty.nodes.length && empty.nodes.every((n) => n.status === "added"));
  const laid = layout(empty);
  ok(`${name}: no two nodes overlap`, laid.nodes.every((a, i) => laid.nodes.slice(i + 1)
    .every((b) => a.x + a.w <= b.x || b.x + b.w <= a.x || a.y + a.h <= b.y || b.y + b.h <= a.y)));
}

{
  const version = (id, parents, kind = "auto") => ({ id, parents, origin: { kind } });
  // main: edits 1-6 and a checkpoint, 7; branch-2 starts from 2: 8, then 9
  const versions = [
    version(1, []), version(2, [1]), version(3, [2]), version(4, [3]), version(5, [4]), version(6, [5]),
    version(7, [6], "checkpoint"), version(8, [2], "branch"), version(9, [8]),
  ];
  const refs = { current: "main", branches: { main: 7, "branch-2": 9 } };
  const graph = versionGraph(versions, refs);
  equal("the current branch takes the first lane", graph.lanes, ["main", "branch-2"]);
  equal("a run of edits collapses; the branch point stays apart",
    graph.nodes.map((n) => `${n.key}:${n.ids.join(",")}@${n.lane}`),
    ["v1:1@0", "v2:2@0", "r3:3,4,5,6@0", "v7:7@0", "v8:8@1", "v9:9@1"]);
  equal("edges join the nodes holding parent and child", graph.edges.map((e) => `${e.from}>${e.to}`),
    ["v1>v2", "v2>r3", "r3>v7", "v2>v8", "v8>v9"]);
  equal("an expanded run shows each edit", versionGraph(versions, refs, new Set([6])).nodes.length, 9);
}
