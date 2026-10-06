// Completion at the REPL prompt: its commands and their arguments, from
// what the studio knows live. The commands are compiler/repl.rkt's
// (`dispatch-command*`, `help-lines`); a query, a scratch definition or a
// list being typed falls to complete.js.
//
// completeCommand(text, pos, live) -> { from, to, items }, `live` being
//   { catalog: [{ name, arity, detail }], databases: [name],
//     locations: [{ location, about }], breaks: [{ id, about }],
//     watches: [{ id, about }] }
// and each item { label, kind, insert, detail }, `insert` a snippet in
// complete.js's syntax.

import { complete, offerable } from "./complete.js";
import { enclosing, parse } from "./sexp.js";

// [names, about, forms]: each form is the sequence of a command's
// arguments, a slot being a list of the words allowed there or one of
//   "relation"   a relation of the catalog
//   "tuple"      a relation, then a value per column (the rest of the line)
//   "database"   a saved database
//   "breakable"  a relation, or the FILE:LINE of a rule of the program
//   "break", "watch"  a standing break or watch, by id
// A command with no forms takes no arguments, or ones nothing can offer.
const COMMANDS = [
  [["library"], "browse saved databases", [[], [["select"], "database"], [["close"]]]],
  [["open", "use"], "load a database, or switch to its resident copy", [["database"]]],
  [["csv-import"], "infer rows from a folder of CSV into a database"],
  [["current"], "describe the current database"],
  [["resident"], "list databases held in memory"],
  [["discard"], "close the current in-memory session without saving", [[["session"]]]],
  [["mode"], "protect the database from mutation, or allow it", [[["readonly", "mutable"]]]],
  [["tables"], "list live relations, schemas and row counts"],
  [["state"], "summarize the pipeline or one relation's versions", [[], ["relation"]]],
  [["count"], "count a relation's current version", [["relation"]]],
  [["show"], "show a small relation's rows", [["relation"]]],
  [["query", "has"], "whether any row matches a value prefix", [["tuple"]]],
  [["more"], "pull the held query cursor's next page"],
  [["cancel"], "discard the held query cursor"],
  [["dump"], "stream a query's rows into a CSV file: dump ?QUERY to F"],
  [["uses", "find"], "which relations contain a value"],
  [["watch"], "observe a relation or a query's count", [["relation"], ["relation", ["level"], ["1"], ["why"]], [["cone"], "relation"]]],
  [["watches"], "list the watches"],
  [["unwatch"], "remove a watch", [["watch"]]],
  [["why"], "the proof tree for a fact: why (REL t …)"],
  [["whynot"], "why a fact is not there: whynot (REL t …)"],
  [["break"], "stop the run when a rule writes a relation, or fires", [["breakable"]]],
  [["breaks"], "list the standing breaks"],
  [["unbreak"], "remove a break", [["break"]]],
  [["continue"], "resume the held run"],
  [["commit"], "take the change held at the pre-commit gate"],
  [["replay"], "rerun the held read"],
  [["abort"], "discard the held run; nothing is committed"],
  [["step"], "walk the held read one interpreter port at a time", [[], [["match", "fire", "emit", "tuple", "iter", "rule"]]]],
  [["finish"], "run to the next iteration boundary"],
  [["frames"], "the join stack at the current stop"],
  [["peek"], "a relation's delta where the run is parked", [["relation"]]],
  [["trace"], "record each change's strata and iterations, or stop", [[["on", "off"]]]],
  [["explain"], "show a query's plan without running it: explain ?QUERY"],
  [["tiers"], "each stratum's execution rung"],
  [["code"], "one stratum's rung, artifacts and plan shape: code sN"],
  [["images"], "list mounted program images"],
  [["image"], "inspect, mount, activate or unmount a program image"],
  [["catalog"], "the selected boundary, history and types"],
  [["schema"], "the daemon's raw live schema"],
  [["pipeline"], "the daemon's raw versioned pipeline"],
  [["run"], "compile and run a .slog program: run PATH"],
  [["scratch"], "the scratch layer's accumulated program"],
  [["keep"], "export the scratch layer to a file and promote it", [[["scratch"], ["as"]]]],
  [["clear"], "retract the whole scratch layer", [[["scratch"]]]],
  [["add"], "add one input tuple and propagate it", [["tuple"]]],
  [["del"], "retract one input tuple and propagate it", [["tuple"]]],
  [["whatif"], "preview an edit's cone without mutating", [[["add", "del"], "tuple"]]],
  [["stage"], "queue signed edits: stage +(REL v …) -(…)"],
  [["unstage"], "withdraw staged edits: unstage +(REL v …)"],
  [["flush"], "commit everything staged as one update"],
  [["recount"], "re-establish, or force-rebuild, the count cache", [[], [["force"]]]],
  [["counts"], "dump a relation's count sidecar rows", [["relation"]]],
  [["rename"], "rename a live relation: rename FROM TO", [["relation"]]],
  [["drop"], "remove a relation name at the next boundary", [["relation"]]],
  [["attach"], "import a saved database: attach DB as DEST", [["database", ["as"]]]],
  [["save"], "save the current database as data/NAME"],
  [["replace"], "seal a program replacement: replace instance A with \"F\""],
  [["preview"], "the pending proposal's diffs"],
  [["activate"], "run the pending proposal's activation"],
  [[":status", "status"], "the REPL, the database and the daemon"],
  [[":ping"], "round-trip to the session server"],
  [[":help", "help"], "list the commands"],
];

const DEFINITIONS = ["rule", "table", "struct", "union", "enum", "lattice", "demand", "extern", "def"];

const byName = new Map(COMMANDS.flatMap(([names, about, forms = []]) => names.map((name) => [name, { about, forms }])));

// Whether `pos` is in Slog rather than a command's words: a query, a
// definition, or a list.
export function slogAt(text, pos) {
  const trimmed = text.trimStart();
  return trimmed.startsWith("?") || DEFINITIONS.includes(trimmed.match(/^\S*/)[0])
    || enclosing(parse(text), pos).kind === "list";
}

export function completeCommand(text, pos, live) {
  if (slogAt(text, pos)) return complete(text, pos, live.catalog);
  let from = pos;
  let to = pos;
  while (from > 0 && /\S/.test(text[from - 1])) from--;
  while (to < text.length && /\S/.test(text[to])) to++;
  const prefix = text.slice(from, pos);
  const words = text.slice(0, from).trim().split(/\s+/).filter(Boolean);
  const matches = (label) => label.startsWith(prefix);

  if (!words.length) {
    const verbs = [
      ...[...byName].map(([name, { about, forms }]) => ({
        label: name, kind: "command", detail: about, insert: forms.some((f) => f.length) ? `${name} ` : name,
      })),
      ...DEFINITIONS.map((name) => ({ label: name, kind: "command", detail: "a scratch definition", insert: `${name} ` })),
    ];
    return { from, to, items: verbs.filter((v) => matches(v.label)) };
  }

  const command = byName.get(words[0]);
  const args = words.slice(1);
  const offered = new Map();
  for (const form of command?.forms ?? []) {
    const fits = args.every((word, i) => i < form.length && (!Array.isArray(form[i]) || form[i].includes(word)));
    if (!fits || args.length >= form.length) continue;
    for (const item of slot(form[args.length], live)) if (matches(item.label)) offered.set(item.label, item);
  }
  return { from, to, items: [...offered.values()] };
}

// The words a slot allows.
function slot(kind, live) {
  if (Array.isArray(kind)) return kind.map((word) => ({ label: word, kind: "word", insert: `${word} `, detail: "" }));
  const relations = (insert) => offerable(live.catalog).map((r) => ({
    label: r.name, kind: "relation", insert: insert(r), detail: `${r.name}/${r.arity}${r.detail?.length ? ` · ${r.detail.join(" ")}` : ""}`,
  }));
  switch (kind) {
    case "relation": return relations((r) => r.name);
    case "tuple": return relations((r) => [r.name, ...columns(r)].join(" "));
    case "database": return live.databases.map((name) => ({ label: name, kind: "database", insert: name, detail: "saved database" }));
    case "breakable": return [
      ...relations((r) => r.name),
      ...live.locations.map(({ location, about }) => ({ label: location, kind: "location", insert: location, detail: about })),
    ];
    case "break": return live.breaks.map(({ id, about }) => ({ label: id, kind: "id", insert: id, detail: about }));
    case "watch": return live.watches.map(({ id, about }) => ({ label: id, kind: "id", insert: id, detail: about }));
    default: return [];
  }
}

// A tab stop per column of a tuple, named by its type: ${1:int} ${2:str}.
function columns({ arity, detail = [] }) {
  return Array.from({ length: arity ?? detail.length }, (_, i) => `\${${i + 1}:${detail[i] ?? `v${i + 1}`}}`);
}

// What a REPL result says about live state the prompt can offer:
// { catalog } from an unfiltered `tables`, { breaks } or { watches } from
// their listings; null for anything else.
export function observe(result) {
  if (result?.kind === "tables" && ["", "all"].includes(result["relations-filter"] ?? "")) {
    return { catalog: result.relations ?? [] };
  }
  const listed = (pattern) => (result.lines ?? []).flatMap((line) => {
    const match = line.match(pattern);
    return match ? [{ id: match[1], about: match[2] }] : [];
  });
  if (result?.kind === "break" && result.title === "Breaks") return { breaks: listed(/^(b\d+)\s+(.*)$/) };
  if (result?.kind === "watch" && result.title === "Watches") return { watches: listed(/^(w\d+)\s+(.*)$/) };
  return null;
}
