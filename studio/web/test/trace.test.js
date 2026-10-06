// trace.js's model over traces a real session server sent (fixtures.js).

import { grid, parkedAt, ruleLine, signed, steps, traceModel } from "../trace.js";
import { dred, reach } from "./fixtures.js";
import { equal as check } from "./check.js";

const entry = (entries, line) => entries.find((e) => e.line === line || e.line.endsWith(` ${line}`));
const model = (entries, line, file) => traceModel(entry(entries, line), file);

// A cold run of reach.slog: `edge`'s facts in one stratum, then `path`
// grows by 3, 2 and 1 rows before the empty iteration that is fixpoint.
{
  const run = model(reach, "/work/reach.slog", "/work/reach.slog");
  check("run: no trace on entries without one", traceModel(entry(reach, "tables"), "/work/reach.slog"), null);
  check("run: strata", run.strata.map((st) => [st.flavor, st.writes, st.iterations.length]),
    [["normal", ["edge"], 2], ["normal", ["path"], 4]]);
  const path = run.strata[1];
  check("run: path's signed counts", path.iterations.map((it) => it.relations.map(signed)),
    [["+3"], ["+2"], ["+1"], []]);
  check("run: path's samples", path.iterations.map((it) => it.relations.flatMap((r) =>
    r.sample.map((row) => `${row.sign}${row.row}`).sort())),
    [["+1 2", "+2 3", "+3 4"], ["+1 3", "+2 4"], ["+1 4"], []]);
  check("run: rules that fired, as editor lines", path.iterations.map((it) => it.fired.map((rule) => [rule.line, rule.fires])),
    [[[9, 3]], [[14, 2]], [[14, 1]], []]);
  check("run: sizes after", path.iterations.map((it) => it.relations.map((r) => r.sizeAfter)), [[3], [5], [6], []]);
  check("run: a run is no maintenance", run.maintenance, null);

  const { width, rows } = grid(run);
  check("grid: as wide as the longest stratum", width, 4);
  check("grid: edge's row", rows[0].map((cell) => cell && [cell.deltas.map(signed), cell.fixpoint]),
    [[["+3"], false], [[], true], null, null]);
  check("grid: fixpoint is the first empty column", rows[1].map((cell) => cell.fixpoint), [false, false, false, true]);
  check("steps: every iteration in run order", steps(run), [[0, 0], [0, 1], [1, 0], [1, 1], [1, 2], [1, 3]]);
}

// `add edge 4 5`: the lazy count round over both strata, then _maint1
// derives (4 5) non-recursively and (1..3 5) recursively.
{
  const add = model(reach, "add edge 4 5", "/work/reach.slog");
  check("add: strata", add.strata.map((st) => [st.flavor, st.iterations.length]),
    [["count", 2], ["count", 2], ["maint1", 2]]);
  check("add: kinds", add.strata[2].iterations[0].relations[0].sample.map((row) => `${row.row} ${row.kind}`).sort(),
    ["1 5 rec", "2 5 rec", "3 5 rec", "4 5 nonrec"]);
  check("add: maintenance", add.maintenance, {
    requested: [{ relation: "edge", added: 1, removed: 0 }],
    routes: ["maintain 1"],
    counted: [{ relation: "edge", rows: 3 }, { relation: "path", rows: 6 }],
    flavors: ["maint1"],
    changes: [{ relation: "path", plus: 4, minus: 0, dups: 0 }],
    rederived: [],
  });
}

// dred.slog: with edges 1-2-3 and the shortcut 1-3, adding the shortcut
// only supports (1 3) again; deleting 1-2 retracts (1 2), and maintenance
// re-derives the (1 3) it still has from the shortcut.
{
  const file = "/work/dred.slog";
  const shortcut = model(dred, "add edge 1 3", file);
  check("support only: no membership change", grid(shortcut).rows[0].map((cell) => cell.deltas.map(signed)), [["~1"], []]);
  const del = model(dred, "del edge 1 2", file);
  check("del: rows", del.strata[0].iterations.map((it) => it.relations.map((r) =>
    [signed(r), r.sample.map((row) => `${row.sign}${row.row} ${row.kind}`)])),
    [[["−1", ["-1 2 nonrec"]]], [["~1", []]], []]);
  check("del: maintenance", del.maintenance, {
    requested: [{ relation: "edge", added: 0, removed: 1 }],
    routes: ["maintain-recursive-negative 1"],
    counted: [],
    flavors: ["maint4neg"],
    changes: [{ relation: "path", plus: 0, minus: 1, dups: 1 }],
    rederived: [{ stratum: 0, iteration: 2, relation: "path", plus: 0, dups: 1 }],
  });
}

check("ruleLine: this file", ruleLine("reach.slog:14:1", "/work/reach.slog"), 14);
check("ruleLine: another file", ruleLine("lib.slog:14:1", "/work/reach.slog"), null);
check("parkedAt", parkedAt(["717a6082 · iteration 2 · phase read", "port b1:fire@reach.slog:14:1:delta:path"]),
  { name: "717a6082", iteration: 2, phase: "read" });
