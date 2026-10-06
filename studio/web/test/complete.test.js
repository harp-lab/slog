// Completion of Slog atoms and queries (complete.js), from a catalog like
// the one `tables` reports. commands.test.js has the REPL's commands.

import { complete, expand, placeholders } from "../complete.js";
import { equal, marked } from "./check.js";

const CATALOG = [
  { name: "edge", arity: 2, detail: ["int", "int"] },
  { name: "path", arity: 2, detail: ["int", "int"] },
  { name: "store", arity: 3, detail: ["int", "list", "val"] },
  { name: "label", arity: 2, detail: ["int", "str"] },
  { name: "$internal", arity: 1, detail: ["int"] },
];
// The items offered at the cursor, as [label, insert], and the range they
// replace, as the text it holds.
function offered(source, using = (t, p) => complete(t, p, CATALOG)) {
  const { text, selection } = marked(source);
  const { from, to, items } = using(text, selection.start);
  return { replaces: text.slice(from, to), items: items.map((i) => [i.label, i.insert]) };
}

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
