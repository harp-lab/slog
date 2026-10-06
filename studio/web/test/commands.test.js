// Completion at the REPL prompt (commands.js): every command's arguments,
// the usage line, and the catalog read from real programs.

import { INVENTORY, catalogOf, completeCommand, declared, locations, observe, signature } from "../commands.js";
import { equal, marked, ok } from "./check.js";

const CATALOG = [
  { name: "edge", arity: 2, detail: ["int", "int"], rows: 3 },
  { name: "path", arity: 2, detail: ["int", "int"], rows: 6 },
  { name: "label", arity: 2, detail: ["int", "str"] },
  { name: "lookup", arity: 3, detail: ["str", "list", "val"], inputs: 2, kind: "demand" },
  { name: "$internal", arity: 1, detail: ["int"] },
];
const LIVE = {
  catalog: CATALOG,
  databases: ["reach", "kcfa"],
  locations: [{ location: "reach.slog:10", about: "rule (edge X Y) --> (path X Y)" }],
  breaks: [{ id: "b1", about: "path · 0 hits" }],
  watches: [{ id: "w2", about: "path @ v1" }],
};

// The items offered at the cursor, as [label, insert], and the text they
// replace.
function offered(source) {
  const { text, selection } = marked(source);
  const { from, to, items } = completeCommand(text, selection.start, LIVE);
  return { replaces: text.slice(from, to), items: items.map((i) => [i.label, i.insert]) };
}
const labels = (source) => offered(source).items.map(([label]) => label);
const RELATIONS = ["edge", "path", "label", "lookup"];

// Each command's arguments --------------------------------------------------

// [line with its cursor, the labels offered]; a command with no arguments
// is offered as a word with no space after it.
const ARGUMENTS = [
  ["library |", ["select", "close"]],
  ["library select |", ["reach", "kcfa"]],
  ["open k|", ["kcfa"]],
  ["csv-import data |", ["as"]],
  ["discard |", ["session"]],
  ["mode |", ["readonly", "mutable"]],
  ["tables |", ["all"]],
  ["state |", RELATIONS],
  ["count p|", ["path"]],
  ["show edge |", ["all"]],
  ["query |", RELATIONS],
  ["dump |", ["?(", "?count", "?exists"]],
  ["dump ?(path X Y) |", ["to"]],
  ["uses |", []],
  ["explain ?c|", ["?count"]],
  ["why |", RELATIONS],
  ["why (path 1 2) |", ["depth"]],
  ["whynot l|", ["label", "lookup"]],
  ["break |", [...RELATIONS, "reach.slog:10", "demand", "answer", "match", "emit"]],
  ["break reach.slog:10 |", ["when", "ignore", "log", "demand", "answer", "match", "emit"]],
  ["break demand |", ["lookup"]],
  ["break edge when (edge X Y) |", ["ignore", "log"]],
  ["unbreak |", ["b1"]],
  ["enable |", ["b1"]],
  ["disable |", ["b1"]],
  ["logs |", ["b1"]],
  ["calls |", ["on", "off", "stack", "failed", "lookup"]],
  ["calls (lookup \"x\" []) |", ["depth"]],
  ["step |", ["match", "fire", "emit", "tuple", "iter", "into", "over", "out", "rule"]],
  ["peek |", RELATIONS],
  ["trace |", ["on", "off"]],
  ["trace on |", ["sample", "focus", "rules"]],
  ["trace on focus edge |", [...RELATIONS, "rules"]],
  ["watch |", [...RELATIONS, "?(", "?count", "?exists", "cone"]],
  ["watch path |", ["level"]],
  ["watch path level |", ["1"]],
  ["watch path level 1 |", ["why"]],
  ["watch cone |", RELATIONS],
  ["unwatch |", ["w2"]],
  ["code |", []],
  ["image |", ["mount", "unmount"]],
  ["image k1 a|", ["activate", "activation"]],
  ["run |", []],
  ["check |", []],
  ["keep |", ["scratch"]],
  ["keep scratch |", ["as"]],
  ["clear |", ["scratch"]],
  ["add |", RELATIONS],
  ["del e|", ["edge"]],
  ["whatif |", ["add", "del"]],
  ["stage |", ["+edge", "+path", "+label", "+lookup"]],
  ["unstage -p|", ["-path"]],
  ["recount |", ["force"]],
  ["counts |", RELATIONS],
  ["rename |", RELATIONS],
  ["rename edge |", []],
  ["drop |", RELATIONS],
  ["attach |", ["reach", "kcfa"]],
  ["attach reach |", ["as"]],
  ["save kept |", ["with"]],
  ["replace |", ["instance"]],
];
for (const [line, expected] of ARGUMENTS) equal(`arguments: ${line}`, labels(line), expected);
for (const [[name], forms] of INVENTORY) {
  const takes = forms.some(Boolean);
  if (!takes) equal(`a command with no arguments: ${name}`, offered(`${name}|`).items.find(([label]) => label === name), [name, name]);
  else ok(`a command with arguments is checked: ${name}`, ARGUMENTS.some(([line]) => line.split(" ")[0] === name));
}

// What is inserted --------------------------------------------------------------

equal("commands by prefix, a space after those taking arguments", offered("wh|").items, [
  ["why", "why "], ["whynot", "whynot "], ["whatif", "whatif "],
]);
equal("an alias, when the verb does not match", offered("rel|").items, [["rels", "rels "]]);
equal("a definition keyword", offered("tab|").items, [["tables", "tables "], ["table", "table "]]);
equal("a fact, its columns typed blanks", offered("why pa|"), {
  replaces: "pa", items: [["path", "(path ${1:int} ${2:int})"]],
});
equal("the head of a fact being typed", offered("whynot (lab|)"), {
  replaces: "lab", items: [["label", "label ${1:int} ${2:str}"]],
});
equal("a tuple's values follow its relation", offered("add lab|").items, [["label", "label ${1:int} ${2:str}"]]);
equal("a signed edit", offered("stage +(ed|)").items, [["edge", "edge ${1:int} ${2:int}"]]);
equal("a demand's call, its inputs only", [offered("break demand |").items, offered("calls (lo|").items], [
  [["lookup", "(lookup ${1:str} ${2:list})"]],
  [["lookup", "lookup ${1:str} ${2:list}"]],
]);
equal("the arguments of a fact are Slog", labels("why (path 1 e|"), ["edge"]);
equal("nothing after a tuple's values begin", labels("add edge 1 |"), []);
equal("nothing for an unknown command", labels("frobnicate |"), []);
equal("a query at the prompt is Slog", offered("?(pa|)").items, [["path", "path ${1:X} ${2:Y}"]]);
equal("a definition at the prompt is Slog", offered("rule (path X Y) (ed|)").items, [["edge", "edge ${1:X} ${2:Y}"]]);
equal("internal relations are not offered", labels("state $|"), []);
equal("a relation's detail: arity, types, rows", completeCommand("count ed", 8, LIVE).items[0].detail, "edge/2 · int int · 3 rows");
equal("a demand's detail: inputs → answer", completeCommand("count lo", 8, LIVE).items[0].detail, "lookup/3 · str list → val · demand");

// The usage line --------------------------------------------------------------

// Each fitting form, its current argument in brackets.
function usage(source) {
  const { text, selection } = marked(source);
  const found = signature(text, selection.start);
  return found && found.forms.map(({ text: form, current }) => (current
    ? `${form.slice(0, current[0])}«${form.slice(...current)}»${form.slice(current[1])}` : form));
}
equal("usage: the argument to type", usage("state |"), ["state [«REL»]"]);
equal("usage: about the command", signature("state ", 6).about, "summarize the pipeline or one relation's versions");
equal("usage: the command word typed, every form", usage("watch|"), ["watch REL [level 1 [why]]", "watch ?QUERY", "watch cone REL [image KEY]"]);
equal("usage: only the forms that fit", usage("watch cone |"), ["watch cone «REL» [image KEY]"]);
equal("usage: inside a fact, the fact", usage("why (path 1|"), ["why [«(REL t ...)» [depth N]]"]);
equal("usage: past the end of a form", usage("count edge |"), ["count REL"]);
equal("usage: none for a query, a definition or nonsense", [usage("?(path X Y)|"), usage("table (a int)|"), usage("frob |")], [null, null, null]);

// The catalog from a program ----------------------------------------------------

const read = (path) => readFile(path);
equal("declared: reach's tables", declared(read("examples/reach/reach.slog")), [
  { name: "edge", arity: 2, detail: ["int", "int"], kind: "declared" },
  { name: "path", arity: 2, detail: ["int", "int"], kind: "declared" },
]);
const cfa = declared(read("../examples/tinycfa/0cfa.slog"));
equal("declared: a compound column type stays one column",
  cfa.find((r) => r.name === "kstore"), { name: "kstore", arity: 2, detail: ["(kaddr expr)", "stack"], kind: "declared" });
equal("declared: unions and runs are not relations", cfa.map((r) => r.name), ["result", "eval", "ret", "store", "kstore"]);
const regex = declared(read("../examples/regex/antimirov.slog"));
equal("declared: a demand, its inputs then its answer",
  regex.find((r) => r.name === "run"), { name: "run", arity: 3, detail: ["re", "(list str)", "int"], kind: "demand", inputs: 2 });
equal("declared: comments after a table are not columns",
  regex.find((r) => r.name === "query"), { name: "query", arity: 2, detail: ["str", "re"], kind: "declared" });
equal("locations: each rule's line, as break names it",
  locations({ "examples/reach/reach.slog": read("examples/reach/reach.slog") }), [
    { location: "reach.slog:5", about: "rule (edge 1 2) (edge 2 3) (edge 3 4)" },
    { location: "reach.slog:10", about: "rule (edge X Y) --> (path X Y)" },
    { location: "reach.slog:11", about: "rule (path X Y) (edge Y Z) --> (path X Z)" },
  ]);
equal("locations: only .slog files", locations({ "notes.md": "rule (a)" }), []);

// Before any Run, the program's declarations are the catalog; after one,
// the session's relations come first and keep what declarations add.
const program = [...declared(read("examples/reach/reach.slog")), { name: "f", arity: 2, detail: ["int", "int"], inputs: 1, kind: "demand" }];
equal("catalog: the program alone", catalogOf({ program }).map((r) => r.name), ["edge", "path", "f"]);
const merged = catalogOf({
  tables: [{ name: "path", arity: 2, detail: ["int", "int"], rows: 6 }, { name: "f", arity: 2, detail: ["int"], kind: "struct", rows: 2 }],
  program,
  kept: [{ name: "r1", arity: 1, detail: ["int"], kind: "result" }],
});
equal("catalog: the session's first, then the program's, then kept results", merged.map((r) => r.name), ["path", "f", "edge", "r1"]);
equal("catalog: a demand's columns are as declared, its rows the session's", merged[1],
  { name: "f", arity: 2, detail: ["int", "int"], kind: "demand", rows: 2, inputs: 1 });

// What entries say ------------------------------------------------------------

equal("observe: an unfiltered tables result", observe({ result: { kind: "tables", "relations-filter": "", relations: CATALOG } }), { tables: CATALOG });
equal("observe: a filtered one is not", observe({ result: { kind: "tables", "relations-filter": "pa", relations: [] } }), null);
equal("observe: a scratch definition", observe({ line: "table (seen int str)", result: { kind: "scratch" } }, { scratch: [] }), {
  scratch: [{ name: "seen", arity: 2, detail: ["int", "str"], kind: "scratch" }],
});
equal("observe: a refused definition is not", observe({ line: "table (seen int str)", result: null }), null);
equal("observe: the breaks listed", observe({ result: { kind: "break", title: "Breaks", lines: ["b1  path · 2 hits", "b3  reach.slog:10 · 0 hits"] } }), {
  breaks: [{ id: "b1", about: "path · 2 hits" }, { id: "b3", about: "reach.slog:10 · 0 hits" }],
});
const known = { breaks: [{ id: "b1", about: "path" }], watches: [{ id: "w2", about: "path" }] };
equal("observe: a break armed, then removed", [
  observe({ result: { kind: "break", title: "Logpoint b2", lines: ["emit (path X Y) — records each match"] } }, known),
  observe({ result: { kind: "break", title: "Break b1 removed", lines: ["0 breaks armed"] } }, known),
], [
  { breaks: [{ id: "b1", about: "path" }, { id: "b2", about: "emit (path X Y) — records each match" }] },
  { breaks: [] },
]);
equal("observe: a watch added, then removed", [
  observe({ result: { kind: "watch", title: "Watch w3", lines: ["edge @ v1"] } }, known),
  observe({ result: { kind: "watch", title: "Watch w2", lines: ["removed (path)"] } }, known),
], [
  { watches: [{ id: "w2", about: "path" }, { id: "w3", about: "edge @ v1" }] },
  { watches: [] },
]);
