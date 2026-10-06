// Completion at the REPL prompt: its commands and their arguments, from
// what the studio knows live. A query, a scratch definition, or a fact's
// arguments being typed fall to complete.js.
//
// completeCommand(text, pos, live) -> { from, to, items }, `live` being
//   { catalog: [{ name, arity, detail, rows?, kind?, inputs? }],
//     databases: [name], locations: [{ location, about }],
//     breaks: [{ id, about }], watches: [{ id, about }] }
// and each item { label, kind, insert, detail }, `insert` a snippet in
// complete.js's syntax.
//
// signature(text, pos) -> the usage of the command being typed, with the
// argument at `pos` marked, for the line above the prompt.

import { complete, offerable } from "./complete.js";
import { forms } from "./forms.js";
import { parse } from "./sexp.js";

// The commands, as compiler/repl.rkt's `command-inventory` has them:
// [names, forms, about], the verb first, then its aliases; each form one
// spelling of the arguments. Its comment says how a form is spelled. The
// studio's tests compare this copy with the one `:help` answers, so it is
// written as JSON.
export const INVENTORY = [
  [["library"], ["", "select DB", "close"], "browse saved databases"],
  [["open", "use"], ["DB"], "load a database, or switch to its resident copy"],
  [["csv-import"], ["FOLDER [as NAME]"], "infer rows from a folder of CSV into a database"],
  [["current", "database"], [""], "describe the current database"],
  [["resident", "sessions"], [""], "list databases held in memory"],
  [["discard"], ["session"], "close the current in-memory session without saving"],
  [["mode"], ["readonly|mutable"], "protect the database from mutation, or allow it"],
  [["tables", "rels", "relations"], ["[all|FILTER]"], "list live relations, schemas and row counts"],
  [["state", "states"], ["[REL]"], "summarize the pipeline or one relation's versions"],
  [["count"], ["REL"], "count a relation's current version"],
  [["show"], ["REL [LIMIT|all]"], "show a small relation's rows"],
  [["query", "has"], ["REL V ..."], "whether any row matches a value prefix"],
  [["more"], [""], "pull the held query cursor's next page"],
  [["cancel"], [""], "discard the held query cursor"],
  [["dump"], ["?QUERY to PATH.csv"], "stream a query's rows into a CSV file"],
  [["uses", "find"], ["#N|VALUE"], "which relations contain a value"],
  [["explain"], ["?QUERY"], "show a query's plan without running it"],
  [["why"], ["[(REL t ...) [depth N]]"], "the proof tree for a fact, or the gate's candidates"],
  [["whynot"], ["(REL t ...)"], "why a fact is not there: each rule's frontier"],
  [["break"], [
    "REL [when (REL t ...) COND ...] [ignore N] [log]",
    "FILE:LINE[@k] [when COND ...] [ignore N] [log]",
    "rN[@k] [when COND ...] [ignore N] [log]",
    "[FILE:LINE] demand|answer (DEMAND t ...) [when COND ...] [ignore N] [log]",
    "[FILE:LINE] match|emit (REL t ...) [when COND ...] [ignore N] [log]"
  ], "stop the run where a rule writes, fires, asks or answers"],
  [["breaks"], [""], "list the standing breaks"],
  [["unbreak"], ["bN"], "remove a break"],
  [["enable"], ["bN"], "put a break back in the run"],
  [["disable"], ["bN"], "keep a break, out of the run"],
  [["logs"], ["[bN]"], "what the logpoints recorded"],
  [["calls"], ["", "on|off|stack|failed", "#N [depth N]", "(DEMAND t ...) [depth N]"],
    "the demand calls: record them, the roots, one call's subtree, the stack"],
  [["step"], ["[match|fire|emit|tuple|iter|into|over|out]", "rule rN"],
    "walk the held run one port, or one demand call, at a time"],
  [["finish"], [""], "leave the ports; run to the next iteration boundary"],
  [["frames"], [""], "the join stack at the current stop"],
  [["continue"], [""], "resume the held run"],
  [["commit"], [""], "take the change held at the pre-commit gate"],
  [["replay"], [""], "rerun the held read"],
  [["abort"], [""], "discard the held run; nothing is committed"],
  [["peek"], ["REL [LIMIT] [delta|new]"], "a relation's delta where the run is parked"],
  [["p", "print"], ["VAR"], "a variable of the rule a held run is stopped in"],
  [["trace"], ["on [sample K] [focus REL ...] [rules]", "off"], "record each change's strata and iterations, or stop"],
  [["watch"], ["REL [level 1 [why]]", "?QUERY", "cone REL [image KEY]"], "observe a relation or a query's count"],
  [["watches"], [""], "list the watches"],
  [["unwatch"], ["wN"], "remove a watch"],
  [["tiers"], [""], "each stratum's execution rung"],
  [["code"], ["sN|HASH"], "one stratum's rung, artifacts and plan shape"],
  [["images"], [""], "list mounted program images"],
  [["image"], [
    "mount PATH",
    "unmount KEY",
    "KEY [activate|rules|sources|kernels|plans|activation|materializations]"
  ], "inspect, mount, activate or unmount a program image"],
  [["catalog"], [""], "the selected boundary, history and types"],
  [["schema"], [""], "the daemon's raw live schema"],
  [["pipeline"], [""], "the daemon's raw versioned pipeline"],
  [["run"], ["PATH"], "compile and run a .slog program"],
  [["rerun"], [""], "the program last run, from scratch, with the breaks armed"],
  [["check"], ["PATH"], "check a program statically, without running it"],
  [["scratch"], [""], "the scratch layer's accumulated program"],
  [["keep"], ["scratch as FILE.slog"], "export the scratch layer to a file and promote it"],
  [["clear"], ["scratch"], "retract the whole scratch layer"],
  [["add"], ["REL V ...", "(REL V ...)"], "add one input tuple and propagate it"],
  [["del"], ["REL V ...", "(REL V ...)"], "retract one input tuple and propagate it"],
  [["whatif"], ["add|del REL V ...", "del (REL V ...)"], "preview an edit's cone without mutating"],
  [["stage"], ["±(REL V ...) ..."], "queue signed edits for one flush"],
  [["unstage"], ["±(REL V ...) ..."], "withdraw staged edits"],
  [["flush"], [""], "commit everything staged as one update"],
  [["recount"], ["[force]"], "re-establish, or force-rebuild, the count cache"],
  [["counts"], ["REL"], "dump a relation's count sidecar rows"],
  [["rename"], ["REL NAME"], "rename a live relation without moving its data"],
  [["drop"], ["REL"], "remove a relation name at the next boundary"],
  [["attach"], ["DB as DEST", "DB SOURCE as DEST"], "import a saved database under one namespace"],
  [["save"], ["NAME [with scratch]"], "save the current database as data/NAME"],
  [["replace"], ["instance ALIAS with \"LIB.slog\""], "seal a program replacement from the last run"],
  [["preview"], [""], "the pending proposal's diffs"],
  [["activate"], [""], "run the pending proposal's activation"],
  [[":status", "status"], [""], "the REPL, the database and the daemon"],
  [[":ping", "ping"], [""], "round-trip to the session server"],
  [[":help", "help"], [""], "list the commands"]
];

const DEFINITIONS = ["rule", "table", "struct", "union", "enum", "lattice", "demand", "extern", "def"];

// What a form's capitals ask for; any other is typed freely, offered nothing.
const SLOTS = {
  "REL": "relation",
  "(REL t ...)": "fact",
  "(REL V ...)": "fact",
  "±(REL V ...)": "signed",
  "(DEMAND t ...)": "call",
  "?QUERY": "query",
  "DB": "database",
  "bN": "break",
  "wN": "watch",
  "FILE:LINE": "location",
  "FILE:LINE[@k]": "location",
};

// A form as a list of nodes, each { start, end } in the form's text and
// either { optional: [nodes] } or { choices: [{ word } | { slot }] }, and
// `repeats` when `...` follows it. A relation followed by its values is a
// "tuple": REL V ....
function nodesOf(text) {
  let i = 0;
  const sequence = () => {
    const nodes = [];
    while (i < text.length && text[i] !== "]") {
      const start = i;
      if (text[i] === " ") {
        i++;
      } else if (text[i] === "[") {
        i++;
        nodes.push({ optional: sequence(), start, end: ++i });
      } else {
        for (let depth = 0; i < text.length && (depth > 0 || !" ]".includes(text[i])); i++) {
          if ("([".includes(text[i])) depth++;
          else if (")]".includes(text[i])) depth--;
        }
        const word = text.slice(start, i);
        if (word === "...") nodes.at(-1).repeats = true;
        else nodes.push({ choices: word.split(/\|(?![^(]*\))/).map(choice), start, end: i });
      }
    }
    return nodes;
  };
  const nodes = sequence();
  nodes.forEach((node, k) => {
    if (node.choices?.[0].slot === "relation" && nodes[k + 1]?.choices?.[0].free === "V") node.choices = [{ slot: "tuple" }];
  });
  return nodes;
}

const choice = (word) => (SLOTS[word] ? { slot: SLOTS[word] }
  : /^[a-z0-9:-]+$/.test(word) ? { word } : { free: word });

// A command's forms share its keywords: a word one form spells out is not
// a value in another (`watch cone` is never a relation named cone).
const COMMANDS = INVENTORY.map(([names, spellings, about]) => {
  const forms = spellings.map((text) => ({ text, nodes: nodesOf(text) }));
  const words = (nodes) => nodes.flatMap((node) => (node.optional ? words(node.optional) : node.choices.map((c) => c.word)));
  const keywords = new Set(forms.flatMap((form) => words(form.nodes)).filter(Boolean));
  return { names, about, forms: forms.map((form) => ({ ...form, keywords })) };
});
const byName = new Map(COMMANDS.flatMap((command) => command.names.map((name) => [name, command])));

// Whether a typed word can stand where `c` asks.
function accepts(c, word, keywords) {
  if (c.word) return c.word === word;
  if (keywords.has(word)) return false;
  if (c.slot === "signed") return /^[+-]\(/.test(word);
  if (["fact", "call"].includes(c.slot)) return word.startsWith("(");
  return Boolean(c.free) || !word.startsWith("(");
}

// What can come after `words` in a form: { next: [node], done }, `done`
// when the form can end there.
function follow({ nodes, keywords }, words) {
  const next = new Set();
  let done = false;
  const walk = (list, k) => {
    if (!list.length) {
      if (k === words.length) done = true;
      return;
    }
    const [node, ...rest] = list;
    if (node.optional) {
      walk([...node.optional, ...rest], k);
      walk(rest, k);
    } else if (k === words.length) {
      next.add(node);
    } else if (node.choices.some((c) => accepts(c, words[k], keywords))) {
      if (node.repeats) walk(list, k + 1);
      walk(rest, k + 1);
    }
  };
  walk(nodes, 0);
  return { next: [...next], done };
}

// The line's top-level words, a bracketed group one word with whatever it
// touches (`+(edge 1 2)`), before `pos`, and the one `pos` is in or at the
// end of: { words: [text], current: { start, end } | null }.
function wordsBefore(text, pos) {
  const groups = [];
  for (const node of parse(text).children.filter((c) => c.kind !== "comment")) {
    const last = groups.at(-1);
    if (last && last.end === node.start) last.end = node.end;
    else groups.push({ start: node.start, end: node.end });
  }
  const current = groups.find((g) => g.start < pos && pos <= g.end) ?? null;
  const words = groups.filter((g) => g.end <= (current ? current.start : pos)).map((g) => text.slice(g.start, g.end));
  return { words, current };
}

// Whether `pos` is in Slog rather than a command's words: a query, a
// definition, or inside a list.
export function slogAt(text, pos) {
  const trimmed = text.trimStart();
  if (trimmed.startsWith("?") || DEFINITIONS.includes(trimmed.match(/^\S*/)[0])) return true;
  const { current } = wordsBefore(text, pos);
  return Boolean(current) && /[([{]/.test(text.slice(current.start, pos));
}

export function completeCommand(text, pos, live) {
  const trimmed = text.trimStart();
  if (trimmed.startsWith("?") || DEFINITIONS.includes(trimmed.match(/^\S*/)[0])) return complete(text, pos, live.catalog);
  const { words, current } = wordsBefore(text, pos);
  const typed = current ? text.slice(current.start, pos) : "";
  if (/[([{]/.test(typed)) return inList(text, pos, live, words, typed);
  const from = current ? current.start : pos;
  const to = current ? current.end : pos;
  const matches = (label) => label.startsWith(typed);

  if (!words.length) {
    const verbs = COMMANDS.flatMap(({ names, about, forms: spellings }) => {
      const name = names.find(matches);
      const takes = spellings.some((form) => form.text);
      return name ? [{ label: name, kind: "command", detail: about, insert: takes ? `${name} ` : name }] : [];
    });
    const definitions = DEFINITIONS.filter(matches)
      .map((name) => ({ label: name, kind: "command", detail: "a scratch definition", insert: `${name} ` }));
    return { from, to, items: [...verbs, ...definitions] };
  }

  const offered = new Map();
  for (const form of byName.get(words[0])?.forms ?? []) {
    for (const node of follow(form, words.slice(1)).next) {
      for (const c of node.choices) {
        for (const item of offer(c, live, typed)) if (matches(item.label) && !offered.has(item.label)) offered.set(item.label, item);
      }
    }
  }
  return { from, to, items: [...offered.values()] };
}

// At the head of a fact being typed as an argument, `why (pa|`, its
// relation with a tab stop per column, named by its type; elsewhere in a
// list, complete.js's variables and atoms.
function inList(text, pos, live, words, typed) {
  const head = typed.match(/^([+-]?)\((\S*)$/);
  const slots = new Set((byName.get(words[0])?.forms ?? [])
    .flatMap((form) => follow(form, words.slice(1)).next)
    .flatMap((node) => node.choices.map((c) => c.slot)));
  if (!head || !["fact", "signed", "call"].some((slot) => slots.has(slot))) return complete(text, pos, live.catalog);
  let to = pos;
  while (to < text.length && /[^\s()[\]{}]/.test(text[to])) to++;
  const alone = /^\s*[)\]}]?\s*$/.test(text.slice(to));
  const relations = slots.has("call") && !slots.has("fact") && !slots.has("signed")
    ? offerable(live.catalog).filter((r) => r.inputs !== undefined).map((r) => ({ ...r, arity: r.inputs }))
    : offerable(live.catalog);
  const items = relations.filter((r) => r.name.startsWith(head[2])).map((r) => ({
    label: r.name, kind: "relation", insert: alone ? [r.name, ...stops(r)].join(" ") : r.name, detail: about(r),
  }));
  return { from: pos - head[2].length, to, items };
}

// The items one choice of a form offers; `typed` is the word so far.
function offer(c, live, typed) {
  if (c.word) return [{ label: c.word, kind: "word", insert: `${c.word} `, detail: "" }];
  const relations = (insert, label = (r) => r.name) => offerable(live.catalog)
    .map((r) => ({ label: label(r), kind: "relation", insert: insert(r), detail: about(r) }));
  const sign = typed.startsWith("-") ? "-" : "+";
  switch (c.slot) {
    case "relation": return relations((r) => r.name);
    case "tuple": return relations((r) => [r.name, ...stops(r)].join(" "));
    case "fact": return relations((r) => `(${[r.name, ...stops(r)].join(" ")})`);
    case "signed": return relations((r) => `${sign}(${[r.name, ...stops(r)].join(" ")})`, (r) => `${sign}${r.name}`);
    case "call": return offerable(live.catalog).filter((r) => r.inputs !== undefined).map((r) => ({
      label: r.name, kind: "relation", insert: `(${[r.name, ...stops({ ...r, arity: r.inputs })].join(" ")})`, detail: about(r),
    }));
    case "query": return [
      { label: "?(", insert: "?($0)", detail: "the matching rows" },
      { label: "?count", insert: "?count ($0)", detail: "count the matches" },
      { label: "?exists", insert: "?exists ($0)", detail: "whether anything matches" },
    ].map((shape) => ({ ...shape, kind: "shape" }));
    case "database": return live.databases.map((name) => ({ label: name, kind: "database", insert: name, detail: "saved database" }));
    case "location": return live.locations.map(({ location, about: rule }) => ({ label: location, kind: "location", insert: location, detail: rule }));
    case "break": return live.breaks.map(({ id, about: what }) => ({ label: id, kind: "id", insert: id, detail: what }));
    case "watch": return live.watches.map(({ id, about: what }) => ({ label: id, kind: "id", insert: id, detail: what }));
    default: return [];
  }
}

// A relation in one line: edge/2 · int int · 3 rows.
function about(r) {
  const columns = r.inputs !== undefined
    ? `${r.detail.slice(0, r.inputs).join(" ")} → ${r.detail.slice(r.inputs).join(" ")}`
    : (r.detail ?? []).join(" ");
  const where = r.rows !== undefined && r.rows !== null ? `${r.rows} row${r.rows === 1 ? "" : "s"}`
    : { demand: "demand", result: "kept result", scratch: "scratch", declared: "declared" }[r.kind] ?? "";
  return [`${r.name}/${r.arity}`, columns, where].filter(Boolean).join(" · ");
}

// A tab stop per column, named by its type: ${1:int} ${2:str}.
function stops({ arity, detail = [] }) {
  return Array.from({ length: arity ?? detail.length }, (_, i) => `\${${i + 1}:${detail[i] || `v${i + 1}`}}`);
}

// The usage of the command being typed: { name, about, forms: [{ text,
// current: [start, end] | null }] }, `current` the argument at `pos` in
// each form that fits what is typed; null outside a command.
export function signature(text, pos) {
  const trimmed = text.trimStart();
  if (!trimmed || trimmed.startsWith("?") || DEFINITIONS.includes(trimmed.match(/^\S*/)[0])) return null;
  const { words, current } = wordsBefore(text, pos);
  const name = words[0] ?? (current && text.slice(current.start, pos));
  const command = byName.get(name);
  if (!command) return null;
  const args = words.slice(1);
  const fitting = command.forms.flatMap((form) => {
    const usage = `${name} ${form.text}`.trim();
    if (!words.length) return [{ text: usage, current: null }];
    const { next, done } = follow(form, args);
    if (!next.length && !done) return [];
    const at = next[0];
    return [{ text: usage, current: at ? [at.start + name.length + 1, at.end + name.length + 1] : null }];
  });
  return fitting.length ? { name, about: command.about, forms: fitting } : null;
}

// The relations a program declares: [{ name, arity, detail, kind }], a
// table's columns its types, a demand's its inputs then its answers, with
// `inputs` their number.
export function declared(text) {
  const found = [];
  for (const form of forms(text)) {
    if (!["table", "demand"].includes(form.keyword)) continue;
    const body = text.slice(form.start + form.keyword.length, form.end);
    const items = parse(body).children.filter((c) => c.kind !== "comment");
    const atom = items[0];
    if (atom?.kind !== "list") continue;
    const [head, ...columns] = atom.children.filter((c) => c.kind !== "comment").map((c) => body.slice(c.start, c.end));
    if (!head || !/^[A-Za-z_][A-Za-z0-9_']*$/.test(head)) continue;
    const answers = form.keyword === "demand" ? items.slice(1).map((c) => body.slice(c.start, c.end)) : [];
    const relation = { name: head, arity: columns.length + answers.length, detail: [...columns, ...answers], kind: form.keyword === "demand" ? "demand" : "declared" };
    found.push(form.keyword === "demand" ? { ...relation, inputs: columns.length } : relation);
  }
  return found;
}

// The `break FILE:LINE` locations of the rules of `files` (path -> text),
// each with its rule on one line.
export function locations(files) {
  return Object.entries(files).filter(([path]) => path.endsWith(".slog")).flatMap(([path, text]) => {
    const base = path.split("/").pop();
    return forms(text).filter((f) => f.keyword === "rule").map((f) => {
      const rule = text.slice(f.start, f.end).replace(/;;.*$/gm, "").replace(/\s+/g, " ").trim();
      return { location: `${base}:${f.line}`, about: rule.length > 72 ? `${rule.slice(0, 71)}…` : rule };
    });
  });
}

// The relations the prompt can name, each once: the live session's first
// (they carry counts), then the program's, scratch definitions, and kept
// results. A demand's columns are as declared, its inputs then answers.
export function catalogOf({ tables = [], program = [], scratch = [], kept = [] }) {
  const merged = new Map();
  for (const relation of [...tables, ...program, ...scratch, ...kept]) {
    const known = merged.get(relation.name);
    if (!known) merged.set(relation.name, relation);
    else if (relation.inputs !== undefined) {
      const { arity, detail, inputs, kind } = relation;
      merged.set(relation.name, { ...known, arity, detail, inputs, kind });
    }
  }
  return [...merged.values()];
}

// What a transcript entry says about live state the prompt can offer, as
// changes to `known` ({ tables, scratch, breaks, watches }): the relations
// of an unfiltered `tables`, a scratch definition's, the breaks and watches
// listed, armed or removed; null for anything else.
export function observe({ result, line = "" }, known = {}) {
  if (!result) return null;
  if (result.kind === "tables" && ["", "all"].includes(result["relations-filter"] ?? "")) {
    return { tables: result.relations ?? [] };
  }
  if (["table", "demand"].includes(line.trim().match(/^\S*/)[0])) {
    const defined = declared(line.trim()).map((r) => ({ ...r, kind: r.kind === "demand" ? "demand" : "scratch" }));
    return defined.length ? { scratch: [...(known.scratch ?? []), ...defined] } : null;
  }
  const listed = (pattern) => (result.lines ?? []).flatMap((text) => {
    const match = text.match(pattern);
    return match ? [{ id: match[1], about: match[2] }] : [];
  });
  const changed = (ids, prefix) => {
    const id = result.title?.match(new RegExp(`^\\S+ (${prefix}\\d+)$`))?.[1];
    if (!id) return null;
    const rest = (ids ?? []).filter((known) => known.id !== id);
    return /^removed\b/.test(result.lines?.[0] ?? "") ? rest : [...rest, { id, about: result.lines?.[0] ?? "" }];
  };
  if (result.kind === "break") {
    if (result.title === "Breaks") return { breaks: listed(/^(b\d+)\s+(.*)$/) };
    if (/ removed$/.test(result.title ?? "")) {
      return { breaks: (known.breaks ?? []).filter((b) => b.id !== result.title.split(" ")[1]) };
    }
    const breaks = /^(Break|Logpoint) b\d+$/.test(result.title ?? "") ? changed(known.breaks, "b") : null;
    return breaks && { breaks };
  }
  if (result.kind === "watch") {
    if (result.title === "Watches") return { watches: listed(/^(w\d+)\s+(.*)$/) };
    const watches = changed(known.watches, "w");
    return watches && { watches };
  }
  return null;
}
