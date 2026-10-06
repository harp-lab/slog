// live.js's model of a run as it goes: progress messages as trace.rs sends
// them (deltas of repl.rkt's `run-progress`), and what the run view draws
// of them.

import {
  absorb, bars, count, duration, flows, locate, outcome, replay, rulesWriting, segments,
  shown, sparkline, stayedEmpty, totals,
} from "../live.js";
import { steps, traceModel } from "../trace.js";
import { reach } from "./fixtures.js";
import { equal as check } from "./check.js";

const stratum = (scc, hash, iterations, ms, tuples, sizes, reads = []) =>
  ({ scc, hash, flavor: "normal", iterations, ms, tuples, sizes, reads });

// reach.slog as its progress arrives: the edge facts finish before the
// first poll, path runs, then path finishes too.
const polls = [
  { seq: 3, run: 1, command: "run reach.slog", running: true, elapsed: 120, from: 0,
    strata: [stratum(0, "7f89b299", 2, 0.4, 3, [["edge", 3]])],
    current: { scc: 1, hash: "3978c1a7", flavor: "normal", iteration: 2, ms: 0.3, tuples: 5, sizes: [["path", 5]], reads: ["edge", "path"] } },
  { seq: 5, run: 1, command: "run reach.slog", running: false, elapsed: 200, from: 1,
    strata: [stratum(1, "3978c1a7", 4, 0.6, 6, [["path", 6]], ["edge", "path"])], current: null },
];

{
  const mid = absorb(null, polls[0]);
  check("absorb: finished strata, and the one running", shown(mid).map((st) => [st.hash, st.iterations, st.active]),
    [["7f89b299", 2, false], ["3978c1a7", 2, true]]);
  check("totals: running", totals(mid), { strata: 2, iterations: 4, rows: 8, ms: 0.7 });
  check("bars: largest first, the running stratum's latest", bars(mid).map((b) => [b.relation, b.size, b.stratum]),
    [["path", 5, 1], ["edge", 3, 0]]);
  const done = absorb(mid, polls[1]);
  check("absorb: a later poll appends from its `from`", shown(done).map((st) => [st.hash, st.iterations, st.active]),
    [["7f89b299", 2, false], ["3978c1a7", 4, false]]);
  check("absorb: a curve per stratum, rising to the fixpoint", done.curves.map((curve) => curve.map((p) => [p.iteration, p.tuples])),
    [[[2, 3]], [[2, 5], [4, 6]]]);
  check("flows: path's stratum reads the edge stratum's relation", flows(done), [{ from: 0, to: 1, relations: ["edge"] }]);
  check("bars: shares of the largest", bars(done).map((b) => b.share), [1, 0.5]);
  const again = absorb(done, { seq: 9, run: 2, from: 0, strata: [], current: null, running: true, compiling: true });
  check("absorb: a new run starts over", [again.strata.length, again.curves.length, again.compiling], [0, 0, true]);
  check("absorb: a resent poll changes nothing", shown(absorb(done, polls[1])).length, 2);
}

// The time strip merges runs of strata too narrow to see.
{
  const live = absorb(null, {
    seq: 1, run: 1, from: 0, running: false, current: null,
    strata: [stratum(0, "a", 1, 100, 1, []), stratum(1, "b", 1, 0.1, 1, []), stratum(2, "c", 1, 0.1, 1, []), stratum(3, "d", 1, 50, 1, [])],
  });
  check("segments: tiny neighbours merge", segments(live).map((s) => [s.first, s.last]), [[0, 0], [1, 2], [3, 3]]);
}

check("sparkline: from the origin to each point", sparkline([{ iteration: 1, tuples: 2 }, { iteration: 2, tuples: 4 }], 10, 5),
  "M0.0 4.5 L5.0 2.5 L10.0 0.5");
check("sparkline: nothing to draw", sparkline([], 10, 5), "");

{
  const program = "table (edge int int)\ntable (path int int)\ntable (loop int)\n\nrule (edge 1 2)\nrule (edge X Y) --> (path X Y)\nrule (path X X) --> (loop X)\nrule (loop X) <-- (path X X)\n";
  const live = absorb(null, {
    seq: 1, run: 1, from: 0, running: false, current: null,
    strata: [stratum(0, "a", 2, 1, 1, [["edge", 1], ["div_by_zero", 0]]), stratum(1, "b", 2, 1, 1, [["path", 1]]), stratum(2, "c", 1, 1, 0, [["loop", 0]])],
  });
  check("stayed empty: only what the program names", stayedEmpty(live, program), ["loop"]);
  check("stayed empty: not while running", stayedEmpty({ ...live, running: true }, program), []);
  check("rules writing: heads after --> and before <--, and facts", rulesWriting(program, ["loop"]).map((r) => r.from), [7, 8]);
  check("rules writing: facts", rulesWriting(program, ["edge"]).map((r) => r.from), [5]);
}

check("locate: a message's leading place", locate("typeerr.slog:4:1: \"two\" : int does not match"), { file: "typeerr.slog", line: 4, col: 1 });
check("locate: none", locate("daemon error: (error \"fatal: x\")"), null);

// Where and why: a located error ran nothing; a failure the run's progress
// carries died in its stratum; a pause holds; an abort discarded it.
{
  const running = absorb(null, polls[0]);
  const compile = { line: "run main.slog", error: { message: "main.slog:5:16: Expected an atom", span: { file: "/p/main.slog", line: 5, col: 16 } } };
  check("outcome: compile", outcome(compile, running).kind, "compile");
  const message = "session: daemon error: (error \"fatal: count overflow\")";
  const died = { ...running, running: false, error: message };
  const failed = outcome({ line: "run main.slog", error: { message } }, died);
  check("outcome: runtime, in the stratum running", [failed.kind, failed.at.index, failed.at.hash, failed.at.iterations], ["runtime", 1, "3978c1a7", 2]);
  check("outcome: held", outcome({ line: "run x", result: { kind: "paused", title: "Paused · interrupt" } }, running, { name: "3978c1a7", iteration: 2, phase: "iter" }),
    { kind: "held", title: "Paused · interrupt", at: { name: "3978c1a7", iteration: 2, phase: "iter" }, interrupted: true });
  check("outcome: aborted", outcome({ line: "abort", result: { kind: "text", title: "Aborted · interrupt" } }, running).kind, "aborted");
  check("outcome: a finished run", outcome({ line: "run x", result: { kind: "change" } }, running), null);
}

// A traced change replays through the same model, a step at a time.
{
  const model = traceModel(reach.find((e) => e.line.endsWith("reach.slog")), "/work/reach.slog");
  const all = steps(model);
  const at = replay(model, all[3]);
  check("replay: the strata before finished, this one at its iteration",
    shown(at).map((st) => [st.iterations, st.active, st.sizes]), [[2, false, [["edge", 3]]], [2, true, [["path", 5]]]]);
  check("replay: its curve from the recorded counts", at.curves[1].map((p) => p.tuples), [3, 5]);
}

check("count", [count(7), count(45150), count(2500000), count(-3)], ["7", "45,150", "2.5M", "-3"]);
check("duration", [duration(0.5), duration(120), duration(2400), duration(125000)], ["0.50 ms", "120 ms", "2.40 s", "2 m 05 s"]);
