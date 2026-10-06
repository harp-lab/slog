// The session's states: the prompt's stamp, the moment a state is derived,
// and the state tree for the layout.

import { ancestry, derived, label, promptStamp, stateGraph } from "../timeline.js";
import { layout } from "../graph.js";
import { equal, ok } from "./check.js";

const state = (id, pred, line, kind = "change", prompts = []) => ({ id, pred, line, kind, prompts });
// t0 -> t1 (run) -> t2 (add) -> t3 (del); t4 branched from t2, then t5
const states = [
  state(0, null, "", "start"),
  state(1, 0, "run main.slog", "run"),
  state(2, 1, "add (edge 3 4)", "change", [{ line: "?(path 1 X)", ok: true }]),
  state(3, 2, "del (edge 1 2)"),
  state(4, 2, "branch from t2", "branch"),
  state(5, 4, "add (edge 9 9)"),
];
const view = { states, current: 5, exploring: null };

equal("the prompt shows the current state and the one it came from", promptStamp(view),
  { now: "t5", pred: "t4", exploring: false, home: "t5", ids: { now: 5, pred: 4, home: 5 } });
equal("exploring shows the explored state, and where to return", promptStamp({ ...view, exploring: 3 }),
  { now: "t3", pred: "t2", exploring: true, home: "t5", ids: { now: 3, pred: 2, home: 5 } });
{
  const renamed = { ...view, states: states.map((s) => (s.id === 4 ? { ...s, name: "baseline" } : s)) };
  equal("a named state shows its name", promptStamp(renamed).pred, "baseline");
  equal("and the tree says both", label(renamed.states[4]), "t4 baseline");
}
equal("the first state has no predecessor", promptStamp({ states, current: 0, exploring: null }).pred, null);
equal("no states, no stamp", promptStamp({ states: [], current: null }), null);

ok("a new state from the current one is derived", derived({ current: 4 }, view));
ok("the same state is not", !derived({ current: 5 }, view));
ok("nor a jump to an unrelated state", !derived({ current: 3 }, view));
ok("nor the first view", !derived(null, view));

equal("ancestry runs back to the start", ancestry(view, 5), [5, 4, 2, 1, 0]);
equal("a long command is shortened", label(state(9, 8, "add (edge 1 2) (edge 2 3) (edge 3 4)"), 12), "t9 add (edge 1…");
equal("the start says so", label(states[0]), "t0 start");
equal("a Run names its file, not its directory", label(state(1, 0, "run /tmp/x/v3/main.slog", "run")), "t1 run main.slog");

{
  const graph = stateGraph({ ...view, exploring: 3 });
  equal("edges join each state to its predecessor", graph.edges.map((e) => `${e.from.split(" ")[0]}>${e.to.split(" ")[0]}`),
    ["t0>t1", "t1>t2", "t2>t3", "t2>t4", "t4>t5"]);
  equal("marks: current, explored, on the current path",
    graph.nodes.map((n) => `${n.state}${n.current ? "c" : ""}${n.explored ? "e" : ""}${n.path ? "p" : ""}`),
    ["0p", "1p", "2p", "3e", "4p", "5cp"]);
  equal("prompts are counted on their state", graph.nodes.map((n) => n.prompts), [0, 0, 1, 0, 0, 0]);
  const laid = layout(graph);
  const at = new Map(laid.nodes.map((n) => [n.state, n]));
  ok("a branch's two children share a column", at.get(3).x === at.get(4).x && at.get(3).y !== at.get(4).y);
  ok("states run left to right", laid.edges.every((e) => !e.back));
}
