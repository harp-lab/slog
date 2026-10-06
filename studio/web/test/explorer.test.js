// The explorer's pure logic: the queries a peek and a break-out read, what
// a refresh flags, a value's subterms, and the name under the pointer.

import { factCells, countDeltas, diffRows, relationColumns, relationLine, rowKey, subterms, usesValue, whereLine, wordAt } from "../explorer.js";
import { parseValue, isMap } from "../table.js";
import { equal, ok } from "./check.js";

const cells = (...texts) => texts.map((text) => ({ text }));

equal("a relation reads as one variable per column", relationLine("path", 2), "?(path V1 V2)");
equal("columns are named for the relation, typed, numbers aligned",
  relationColumns("label", ["int", "str"]).map((c) => [c.name, c.var, c.type, c.numeric]),
  [["label.1", "V1", "int", true], ["label.2", "V2", "str", false]]);

equal("rows where a column holds a value: a guard", whereLine("?(path V1 V2)", "V1", "5"), "? (path V1 V2) (= V1 5)");
equal("a handle splices in", whereLine("? (edge X Y) (edge Y Z)", "Z", "#12"), "? (edge X Y) (edge Y Z) (= Z #12)");
equal("the guard goes before a projection", whereLine("? (edge X Y) (edge Y Z) -> (X Z)", "X", "\"a b\""),
  "? (edge X Y) (edge Y Z) (= X \"a b\") -> (X Z)");

// a refresh flags rows by their values, never by their handles
const before = [cells("1", "2"), cells("1", "3"), cells("2", "3")];
const after = [cells("1", "2"), cells("2", "3"), cells("3", "4"), cells("4", "5")];
const { added, removed } = diffRows(before, after);
equal("rows new to the read are added", [...added], [rowKey(cells("3", "4")), rowKey(cells("4", "5"))]);
equal("rows gone from it are removed", removed.map(rowKey), [rowKey(cells("1", "3"))]);
equal("a handle is not part of a row's identity",
  diffRows([[{ text: "(pt 1 2)", handle: "#1" }]], [[{ text: "(pt 1 2)", handle: "#9" }]]).added.size, 0);
ok("the comparison is capped", diffRows(before, after, 1).added.size === 0);

const found = subterms(parseValue("(add (num 1) (mul (num 1) (var \"x\")))"));
equal("subterms, each once with its count, grouped by constructor",
  found.map(({ head, text, count }) => [head, text, count]),
  [["add", "(add (num 1) (mul (num 1) (var \"x\")))", 1], ["mul", "(mul (num 1) (var \"x\"))", 1],
    ["num", "(num 1)", 2], ["var", "(var \"x\")", 1]]);
equal("terms inside lists count too", subterms(parseValue("[(pt 1 2) (pt 1 2) 3]")).map((s) => s.count), [2]);

equal("the name around the pointer", wordAt("rule (path X Y) <--", 8), { word: "path", start: 6, end: 10 });
equal("a name with dashes and a question mark", wordAt("(edge-of? A)", 3).word, "edge-of?");
equal("not a number", wordAt("(edge 12 3)", 7), null);
equal("a sentence's period is not part of a name", wordAt("in path.", 5).word, "path");

equal("counts that moved, and only those",
  [...countDeltas(new Map([["path", 435], ["edge", 29]]), [{ name: "path", rows: 465 }, { name: "edge", rows: 29 }, { name: "new", rows: 1 }])],
  [["path", 30]]);

equal("a fact as show prints it, handles kept with their values",
  factCells("(subst (subst (suc (_enum \"zero\")) 0 (ix 0)) #7 (suc (_enum \"zero\")) #8 0 (ix 0) #9)"),
  [{ text: "(subst (suc (_enum \"zero\")) 0 (ix 0))", handle: "#7" }, { text: "(suc (_enum \"zero\"))", handle: "#8" },
    { text: "0" }, { text: "(ix 0)", handle: "#9" }]);
equal("not a fact", factCells("… 57 more; use `show subst all`"), null);

equal("uses takes a handle, a number or a string",
  [{ text: "(pt 1 2)", handle: "#3" }, { text: "12" }, { text: "\"a\"" }, { text: "foo" }].map(usesValue),
  ["#3", "12", "\"a\"", null]);

ok("a set of pairs reads as a map", isMap(parseValue("{(1 \"a\") (2 \"b\")}")));
ok("a set of numbers does not", !isMap(parseValue("{1 2 3}")));
