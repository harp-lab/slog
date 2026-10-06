// A relation's time: the names, the past, and the hover card of states.

import { cardLines, idOf, isPast, madeBy, noteSet, setState, setStates, stampedText, stateName } from "../stamp.js";
import { equal, ok } from "./check.js";

const state = (id, pred, kind, line, more = {}) => ({ id, pred, kind, line, prompts: [], deltas: [], ...more });
setStates({
  current: 3,
  exploring: 1,
  states: [
    state(0, null, "start", ""),
    state(1, 0, "run", "run /tmp/x/v3-abc/main.slog", {
      version: 3, strata: 2, ms: 120, name: "baseline",
      deltas: [{ relation: "path", net: 6 }, { relation: "edge", net: 3 }],
    }),
    state(2, 1, "change", "add (edge 3 4)", { ms: 15, deltas: [{ relation: "path", net: 3 }],
      prompts: [{ line: "?(path 1 X)", ok: true }, { line: "?(nope)", ok: false }] }),
    state(3, 1, "branch", "branch from t1"),
  ],
});
noteSet({ id: "r2", state: { id: 2, pred: 1 } });

equal("a state's id, from either spelling", [idOf(2), idOf({ id: 2, pred: 1 }), idOf(null)], [2, 2, null]);
equal("a named state goes by its name", [stateName(1), stateName(2)], ["baseline", "t2"]);
ok("an older state is past", isPast(2) && isPast({ id: 1 }) && !isPast(3) && !isPast(null));
equal("as text, where only text goes", [stampedText("r2", 2), stampedText("r2", null)], ["r2 @t2", "r2"]);
equal("a set's state is known by its name", [setState("r2"), setState("r9")], [2, null]);

equal("a Run says its file, version, strata, time and sizes", madeBy(madeState(1)),
  "Run main.slog v3 · 2 strata · 120 ms · path +6, edge +3");
equal("a change, its time and sizes", madeBy(madeState(2)), "add (edge 3 4) · 15 ms · path +3");
equal("a branch names what it came from", madeBy(madeState(3)), "branch from baseline");

equal("the card: name, what made it, where from, what was asked, its sets", cardLines(2), [
  "t2",
  "add (edge 3 4) · 15 ms · path +3",
  "from baseline",
  "asked here:",
  "  › ?(path 1 X)",
  "  ✗ ?(nope)",
  "sets: r2",
]);
equal("the card of a named, explored state", cardLines(1).slice(0, 2),
  ["baseline · t1 (exploring)", "Run main.slog v3 · 2 strata · 120 ms · path +6, edge +3"]);
equal("an unknown state has no card", cardLines(9), []);

function madeState(id) {
  return { 1: { id: 1, kind: "run", line: "run /tmp/x/v3-abc/main.slog", version: 3, strata: 2, ms: 120,
    deltas: [{ relation: "path", net: 6 }, { relation: "edge", net: 3 }] },
  2: { id: 2, kind: "change", line: "add (edge 3 4)", ms: 15, deltas: [{ relation: "path", net: 3 }] },
  3: { id: 3, kind: "branch", line: "branch from t1" } }[id];
}
