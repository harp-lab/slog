// The result table's pure logic: which rows render, values as trees, the
// export formats, and filters and sorts as refinements.

import {
  columnWidth, compareCells, csvField, filterRefinement, parseValue, plainValue,
  sortedOrder, toCSV, toFacts, toTSV, tsvField, windowOf,
} from "../table.js";
import { equal, ok } from "./check.js";

// ---- the virtual window ---------------------------------------------------

equal("the first screen renders its rows and the overscan below",
  windowOf(0, 240, 24, 45150, 12), { first: 0, last: 22 });
equal("mid-scroll renders the rows in view and the overscan on each side",
  windowOf(24 * 30000 + 5, 240, 24, 45150, 12), { first: 29988, last: 30023 });
equal("the end stops at the last row", windowOf(24 * 45145, 240, 24, 45150, 12), { first: 45133, last: 45150 });
equal("no rows, nothing", windowOf(0, 500, 24, 0), { first: 0, last: 0 });
equal("scrolled past a set that shrank renders nothing", windowOf(24 * 9000, 240, 24, 100, 12), { first: 100, last: 100 });
// a 10k-row scroll touches a bounded DOM: never more than the view and overscan
let widest = 0;
for (let top = 0; top < 24 * 10000; top += 997) {
  const { first, last } = windowOf(top, 800, 24, 10000, 12);
  widest = Math.max(widest, last - first);
}
ok("the window never outgrows the view and its overscan", widest <= Math.ceil(800 / 24) + 1 + 24);

// ---- values as trees ------------------------------------------------------

const term = parseValue("(add (num 1) (mul (var \"x\") (num 2)))");
equal("a constructor term reads as its head and arguments", [term.kind, term.head, term.args.length], ["term", "add", 2]);
equal("terms nest", term.args[1].args.map((arg) => [arg.head, arg.args[0].kind, arg.args[0].text]),
  [["var", "string", "\"x\""], ["num", "number", "2"]]);
equal("leaves are typed", ["-3", "2.5e3", "#t", "#12", "foo", "…", "\"a b\""].map((text) => parseValue(text).kind),
  ["number", "number", "bool", "handle", "symbol", "more", "string"]);
const list = parseValue("[1 \"two\" (pt 3 4)]");
equal("a list holds its items", [list.kind, list.items.map((item) => item.kind)], ["list", ["number", "string", "term"]]);
equal("a tuple without a constructor", parseValue("(1 2)").kind, "tuple");
equal("brackets inside strings are text", parseValue("(say \"a (b] c\" \"q\\\"(\")").args.map((arg) => arg.text),
  ["\"a (b] c\"", "\"q\\\"(\""]);
equal("an unbalanced value is one text leaf", parseValue("(add (num 1)"), { kind: "text", text: "(add (num 1)" });
equal("mismatched brackets are text", parseValue("(a ]").kind, "text");
equal("a string with a bare quote inside (audit Q-14) is text", parseValue("\"5\" tall\"").kind, "text");
equal("the empty term", parseValue("()").kind, "tuple");

// ---- export -----------------------------------------------------------------

equal("a string exports without its quotes and escapes", plainValue("\"say \\\"hi\\\"\\n\""), "say \"hi\"\n");
equal("other values export as printed", plainValue("(pt 1 2)"), "(pt 1 2)");
equal("plain CSV fields stay bare", csvField("abc 1"), "abc 1");
equal("CSV quotes commas, quotes and line breaks", ["a,b", "say \"hi\"", "x\ny", " lead"].map(csvField),
  ["\"a,b\"", "\"say \"\"hi\"\"\"", "\"x\ny\"", "\" lead\""]);
equal("TSV escapes what would break its lines", tsvField("a\tb\nc\\d"), "a\\tb\\nc\\\\d");
const rows = [
  [{ text: "1" }, { text: "\"node, one\"" }],
  [{ text: "2" }, { text: "(add (num 1) (num 2))" }],
];
equal("CSV has a header and CRLF lines", toCSV(["X", "S"], rows), "X,S\r\n1,\"node, one\"\r\n2,(add (num 1) (num 2))\r\n");
equal("TSV likewise, tab-separated", toTSV(["X", "S"], rows), "X\tS\n1\tnode, one\n2\t(add (num 1) (num 2))\n");
equal("facts keep values as Slog", toFacts("r1", rows), "(r1 1 \"node, one\")\n(r1 2 (add (num 1) (num 2)))\n");

// ---- filters and sorts --------------------------------------------------------

equal("a bare value is an equality", filterRefinement(0, "7", "int"), { op: "filter", column: 0, guard: "=", value: "7" });
equal("a guard leads the value", filterRefinement(1, ">= 10", "int"), { op: "filter", column: 1, guard: ">=", value: "10" });
equal("!= is the query's /=", filterRefinement(1, "!=3").guard, "/=");
equal("a string column's bare word is quoted", filterRefinement(2, "node 7", "str").value, "\"node 7\"");
equal("a quoted string is left as typed", filterRefinement(2, "= \"x\"", "str").value, "\"x\"");
equal("a handle is left as typed", filterRefinement(2, "#4", "str").value, "#4");
equal("nothing to filter by", filterRefinement(0, "  >  "), null);

const cell = (text) => ({ text });
ok("numbers order by value", compareCells(cell("9"), cell("10")) < 0);
ok("numbers come before text", compareCells(cell("100"), cell("\"a\"")) < 0);
ok("text orders by its characters", compareCells(cell("(add)"), cell("(mul)")) < 0);
const unsorted = [["b", "10"], ["a", "9"], ["c", "\"x\""], ["d", "-2.5"], ["e", "9"]].map((row) => row.map(cell));
equal("a sort is stable", sortedOrder(unsorted, 1, false), [3, 1, 4, 0, 2]);
equal("descending reverses, ties still in order", sortedOrder(unsorted, 1, true), [2, 0, 1, 4, 3]);

ok("a column is at least as wide as its header", columnWidth({ name: "a-long-column-name", type: "int" }, [], 0) > 150);
equal("and at most so wide", columnWidth({ name: "v" }, [[{ text: "x".repeat(500) }]], 0), 420);
