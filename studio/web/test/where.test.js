// where.js's model of a held run's position, over positions as repl.rkt's
// `held-position` reports them.

import { badge, clauseAt, crumbs, drivingRow, moved, ruleAt, ruleClauses } from "../where.js";
import { equal as check } from "./check.js";

const program = [
  "table (ret val kont)",
  "rule (eval (app F A) K) --> (eval F (ar A K))",
  "rule (ret V (ar A K)) --> (eval A (fn V K))",
  "rule (ret V (fn (clo X B) K))",
  "  --> (store X V) (eval B (kaddr B)) (kstore (kaddr B) K)",
  "rule (eval (num N) K) (> N 0) --> (ret (pos) K)",
  "rule (delta \"+\" (zero) V V) <-- (sign V)",
].join("\n");

{
  const clauses = ruleClauses(program, 3);
  check("clauses: body then head, in source order", clauses.map((c) => [c.name, c.head]), [["ret", false], ["eval", true]]);
  check("clauses: where each is", clauses.map((c) => [c.from, c.to]), [[[3, 6], [3, 22]], [[3, 27], [3, 44]]]);
  check("clauses: a rule over lines", ruleClauses(program, 4).map((c) => [c.name, c.head, c.from[0]]),
    [["ret", false, 4], ["store", true, 5], ["eval", true, 5], ["kstore", true, 5]]);
  check("clauses: <-- puts the heads first", ruleClauses(program, 7).map((c) => [c.name, c.head]), [["delta", true], ["sign", false]]);
  check("clauses: not a rule", ruleClauses(program, 1), []);

  const guarded = ruleClauses(program, 6);
  check("clause at: the drive port's delta", clauseAt(clauses, { port: "drive", relation: "ret" })?.name, "ret");
  check("clause at: a constructor inside a clause", clauseAt(clauses, { port: "match", relation: "ar" })?.text, "(ret V (ar A K))");
  check("clause at: an emit's head", clauseAt(ruleClauses(program, 4), { port: "emit", relation: "kstore" })?.name, "kstore");
  check("clause at: a guard", clauseAt(guarded, { port: "guard" })?.text, "(> N 0)");
  check("clause at: a fire is the whole body", clauseAt(clauses, { port: "fire", relation: "" }), null);
}

check("rule at", ruleAt("main.slog:72:1"), { file: "main.slog", line: 72, col: 1 });

const at = {
  stratum: "1227cdad", flavor: "normal", iteration: 19, phase: "read", port: "drive", relation: "ret",
  source: "main.slog:3:1", tag: "delta:ret", "driver-row": 412, "driver-rows": 980, row: "(pos) (halt \"arith\")",
};
{
  const parts = crumbs(at, { run: "t6", stratum: { index: 1, label: "eval ret store" }, text: program });
  check("crumbs: the run down to the row", parts.map((c) => c.text), [
    "Run from t6", "stratum 2 (eval ret store)", "iteration 19", "rule main.slog:3",
    "clause 1 of 2 (drive (ret V (ar A K)))", "row 412 of 980 in the delta",
  ]);
  const unplaced = crumbs({ ...at, port: undefined, source: undefined, phase: "iter", flavor: "maint1" });
  check("crumbs: a pause between iterations, stratum by hash", unplaced.map((c) => c.text),
    ["Run", "stratum 1227cdad maint1", "iteration 19", "between iterations"]);
  const stepped = crumbs({ ...at, port: "match", relation: "ar", "driver-row": 412 }, { run: "t6", stratum: { index: 1, label: "eval ret store" }, text: program });
  check("moved: a step to the next port moves the clause", moved(parts, stepped), ["clause"]);
  const next = crumbs({ ...at, "driver-row": 413, iteration: 20 }, { run: "t6", stratum: { index: 1, label: "eval ret store" }, text: program });
  check("moved: the next row and iteration", moved(parts, next), ["iteration", "row"]);
  check("moved: nothing before", moved([], parts), []);
}

check("badge", badge(at), "iter 19 · delta 412/980 · drive ret");
check("driving row: its relation from the variant's driver", drivingRow({ tag: "delta:ret", row: "(pos) (halt \"a\")" }), "(ret (pos) (halt \"a\"))");
check("driving row: none", drivingRow({ tag: "once" }), "");
check("badge: no delta order", badge({ iteration: 3, port: "fire", relation: "", "driver-rows": 0 }), "iter 3 · fire");
