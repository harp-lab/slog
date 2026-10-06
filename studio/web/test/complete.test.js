// Completion: Slog atoms and queries (complete.js), and REPL commands
// (commands.js), from a catalog like the one `tables` reports.

import { complete, expand, placeholders } from "../complete.js";
import { completeCommand, observe } from "../commands.js";
import { equal, marked } from "./check.js";

const CATALOG = [
  { name: "edge", arity: 2, detail: ["int", "int"] },
  { name: "path", arity: 2, detail: ["int", "int"] },
  { name: "store", arity: 3, detail: ["int", "list", "val"] },
  { name: "label", arity: 2, detail: ["int", "str"] },
  { name: "$internal", arity: 1, detail: ["int"] },
];
const LIVE = {
  catalog: CATALOG,
  databases: ["reach", "kcfa"],
  locations: [{ location: "reach.slog:10", about: "rule (edge X Y) --> (path X Y)" }],
  breaks: [{ id: "b1", about: "path · 0 hits" }],
  watches: [{ id: "w2", about: "path @ v1" }],
};

// The items offered at the cursor, as [label, insert], and the range they
// replace, as the text it holds.
function offered(source, using = (t, p) => complete(t, p, CATALOG)) {
  const { text, selection } = marked(source);
  const { from, to, items } = using(text, selection.start);
  return { replaces: text.slice(from, to), items: items.map((i) => [i.label, i.insert]) };
}
const command = (source) => offered(source, (t, p) => completeCommand(t, p, LIVE));

// Placeholders --------------------------------------------------------------

equal("placeholders: one type throughout, letters", placeholders(CATALOG[1]), ["${1:X}", "${2:Y}"]);
equal("placeholders: named by type", placeholders(CATALOG[2]), ["${1:Int}", "${2:List}", "${3:Val}"]);
equal("placeholders: a repeated type numbered",
  placeholders({ arity: 3, detail: ["str", "str", "int"] }), ["${1:Str1}", "${2:Str2}", "${3:Int}"]);
equal("placeholders: untyped past six, numbered", placeholders({ arity: 7 }).at(-1), "${7:X7}");

equal("expand: stops in order, then the final cursor", expand("(path ${2:Y} ${1:X})$0"), {
  text: "(path Y X)",
  stops: [{ start: 8, end: 9 }, { start: 6, end: 7 }, { start: 10, end: 10 }],
});

// Atoms and queries -----------------------------------------------------------

equal("a relation at a list's head, with its columns", offered("?(pa|)"), {
  replaces: "pa", items: [["path", "path ${1:X} ${2:Y}"]],
});
equal("at a head already holding arguments, the name alone", offered("?(pa| X Y)").items, [["path", "path"]]);
equal("internal relations are not offered", offered("?(|)").items.map(([label]) => label), ["edge", "path", "store", "label"]);
equal("in a rule's body, variables of the rule and then atoms", offered("rule (path X Y) (edge Y Z) --> (path X (st|))").items, [
  ["store", "store ${1:Int} ${2:List} ${3:Val}"],
]);
equal("an argument: the rule's variables, then atoms", offered("rule (path X Yonder) (edge Yonder Z) --> (path X Y|)").items, [
  ["Yonder", "Yonder"],
]);
equal("variables come from this rule only", offered("rule (p Alpha)\nrule (q A|)").items, []);
equal("a whole atom at the top level of a rule", offered("rule (path X Y) la|").items, [["label", "(label ${1:Int} ${2:Str})"]]);
equal("the start of a query offers its shapes", offered("?c|"), { replaces: "?c", items: [["?count", "?count ($0)"]] });
equal("an arrow offers the projection of the query's variables", offered("? (path X Y) (edge Y Z) ->|"), {
  replaces: "->", items: [["-> (X Y Z)", "-> (X Y Z)"]],
});
equal("no projection for a count", offered("?count (path X Y) ->|").items, []);
equal("nothing inside a string", offered("?(label X \"pa|\")").items, []);

// REPL commands ---------------------------------------------------------------

equal("commands by prefix, a space after those taking arguments", command("wh|").items, [
  ["why", "why"], ["whynot", "whynot"], ["whatif", "whatif "],
]);
equal("a relation after show", command("show p|").items, [["path", "path"]]);
equal("a tuple's typed columns after add", command("add st|").items, [["store", "store ${1:int} ${2:list} ${3:val}"]]);
equal("whatif takes add or del, then a tuple", [command("whatif |").items, command("whatif del e|").items], [
  [["add", "add "], ["del", "del "]],
  [["edge", "edge ${1:int} ${2:int}"]],
]);
equal("databases after open and library select", [command("open k|").items, command("library select |").items], [
  [["kcfa", "kcfa"]],
  [["reach", "reach"], ["kcfa", "kcfa"]],
]);
equal("break offers relations and rule locations", command("break |").items.map(([label]) => label), [
  "edge", "path", "store", "label", "reach.slog:10",
]);
equal("unbreak and unwatch offer the listed ids", [command("unbreak |").items, command("unwatch |").items], [
  [["b1", "b1"]], [["w2", "w2"]],
]);
equal("fixed words", [command("mode |").items, command("step f|").items, command("keep scratch |").items], [
  [["readonly", "readonly "], ["mutable", "mutable "]],
  [["fire", "fire "]],
  [["as", "as "]],
]);
equal("watch: a relation, then its level", [command("watch c|").items, command("watch path |").items], [
  [["cone", "cone "]], [["level", "level "]],
]);
equal("nothing after a tuple's values begin", command("add edge 1 |").items, []);
equal("a query at the prompt is Slog", command("why (pa|)").items, [["path", "path ${1:X} ${2:Y}"]]);
equal("a definition at the prompt is Slog", command("rule (path X Y) (ed|)").items, [["edge", "edge ${1:X} ${2:Y}"]]);

equal("observe: an unfiltered tables result is the catalog",
  observe({ kind: "tables", "relations-filter": "", relations: CATALOG }), { catalog: CATALOG });
equal("observe: a filtered one is not", observe({ kind: "tables", "relations-filter": "pa", relations: [] }), null);
equal("observe: the breaks listed", observe({ kind: "break", title: "Breaks", lines: ["b1  path · 2 hits", "b3  reach.slog:10 · 0 hits"] }), {
  breaks: [{ id: "b1", about: "path · 2 hits" }, { id: "b3", about: "reach.slog:10 · 0 hits" }],
});
