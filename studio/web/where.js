// "You are here" for a held run: where the run stands, from the run down
// to the row it drives, as a breadcrumb over the prompt that changes with
// every step (the changed part pulses), and as the badge over the stopped
// rule in the editor.
//
// A held run's pause result carries its position (`at`, repl.rkt
// `held-position`): the stratum's hash and flavor, the iteration and phase,
// and at an interpreter port the port, the rule's location, the relation of
// the clause at the port, the driving row's place among the delta's rows
// and the rule's bindings. The rest comes from the page: the stratum's
// place in the run (the Execution tab's progress) and the rule's clauses
// (the editor's text).
//
// The model functions are pure; web/test/where.test.js runs them.

import { formAt, forms } from "./forms.js";
import { tokens } from "./lexer.js";

// ---- The model ------------------------------------------------------------

// The clauses of the rule at `line` of `text`, in source order: each body
// atom, guard and head as { text, name, head, from: [line, col], to: [line,
// col] }, `name` its first word (a relation, or a guard's operator).
export function ruleClauses(text, line) {
  const form = formAt(forms(text), line);
  if (!form || form.keyword !== "rule") return [];
  const source = text.slice(form.start, form.end);
  const at = lineStarts(text);
  const place = (offset) => {
    const absolute = form.start + offset;
    let l = 0;
    while (l + 1 < at.length && at[l + 1] <= absolute) l++;
    return [l + 1, absolute - at[l] + 1];
  };
  const found = [];
  let depth = 0;
  let open = null;
  let arrow = null;
  for (const token of tokens(source)) {
    const word = token.kind === "word" ? source.slice(token.start, token.end) : null;
    if (token.kind === "open") {
      if (depth === 0) open = { start: token.start, name: null };
      depth++;
    } else if (token.kind === "close") {
      depth = Math.max(0, depth - 1);
      if (depth === 0 && open) {
        found.push({ ...open, end: token.end });
        open = null;
      }
    } else if (word !== null) {
      if (depth === 0 && (word === "-->" || word === "<--")) arrow = { word, at: found.length };
      else if (depth === 1 && open && open.name === null) open.name = word;
    }
  }
  const isHead = (k) => !arrow ? true : arrow.word === "-->" ? k >= arrow.at : k < arrow.at;
  return found.map((clause, k) => ({
    text: source.slice(clause.start, clause.end).replace(/\s+/g, " "),
    name: clause.name ?? "",
    head: isHead(k),
    from: place(clause.start),
    to: place(clause.end),
  }));
}

function lineStarts(text) {
  const starts = [0];
  for (let i = 0; i < text.length; i++) if (text[i] === "\n") starts.push(i + 1);
  return starts;
}

// The clause a port stands at: a body clause naming the relation for the
// drive port and the probes (the relation may be a constructor inside it,
// `ar` of `(ret V (ar A K))`), a head writing it for an emit, a guard for a
// guard; null for a fire, which is the whole body at once.
export function clauseAt(clauses, at) {
  const names = (clause) => new RegExp(`\\(\\s*${escape(at.relation ?? "")}[\\s)]`).test(clause.text);
  const body = clauses.filter((c) => !c.head);
  const heads = clauses.filter((c) => c.head);
  switch (at.port) {
    case "drive":
      return (at.relation && (body.find((c) => c.name === at.relation) ?? body.find(names))) || body[0] || null;
    case "match":
    case "miss":
    case "exhausted":
      return (at.relation && (body.find((c) => c.name === at.relation) ?? body.find(names))) || null;
    case "emit":
      return (at.relation && heads.find((c) => c.name === at.relation)) || heads[0] || null;
    case "guard":
    case "guard-fail":
      return body.find((c) => !/^[A-Za-z_]/.test(c.name)) ?? null;
    default:
      return null;
  }
}

const escape = (text) => text.replace(/[.*+?^${}()|[\]\\]/g, "\\$&");

// The driving row as the source writes it, `(ret …)`: its relation is the
// variant's delta driver, `delta:ret`.
export function drivingRow(at) {
  const relation = /^delta:(.+)$/.exec(at?.tag ?? "")?.[1];
  return at?.row ? `(${relation ? `${relation} ` : ""}${at.row})` : "";
}

// A rule location "main.slog:72:1" as { file, line, col }.
export function ruleAt(source) {
  const match = /^(.*):(\d+):(\d+)$/.exec(source ?? "");
  return match && { file: match[1], line: Number(match[2]), col: Number(match[3]) };
}

const PORTS = {
  drive: "drives", match: "matches", miss: "misses", exhausted: "is exhausted at",
  guard: "tests", "guard-fail": "fails", fire: "fires", emit: "writes",
};

const short = (text, max) => (text.length > max ? `${text.slice(0, max - 1)}…` : text);

// The breadcrumb: [{ key, text, title }], from the run down. `context`:
// `run`, the stamp of the state the run started from; `stratum`, its {
// index, label } in the run, when the progress knows it; `text`, the
// stopped rule's file as the editor has it.
export function crumbs(at, { run = null, stratum = null, text = "" } = {}) {
  if (!at) return [];
  const out = [{ key: "run", text: run ? `Run from ${run}` : "Run", title: "The held run: its stops hang off this state in the state tree" }];
  const flavor = at.flavor && at.flavor !== "normal" ? ` ${at.flavor}` : "";
  out.push({
    key: "stratum",
    text: stratum ? `stratum ${stratum.index + 1}${flavor} (${short(stratum.label, 28)})` : `stratum ${at.stratum}${flavor}`,
    title: `${at.stratum}${flavor}: show it in the Execution tab`,
  });
  if (at.iteration !== null && at.iteration !== undefined) {
    out.push({ key: "iteration", text: `iteration ${at.iteration}`, title: "The iteration of the stratum's fixpoint the run is in" });
  }
  const rule = ruleAt(at.source);
  if (!rule) {
    out.push({ key: "phase", text: at.phase === "iter" ? "between iterations" : "inside the read", title: "The run holds at this point of the iteration" });
    return out;
  }
  out.push({ key: "rule", text: `rule ${rule.file.split("/").pop()}:${rule.line}`, title: `${at.tag ?? ""}: show the rule` });
  const clauses = ruleClauses(text, rule.line);
  const clause = clauseAt(clauses, at);
  const port = PORTS[at.port] ?? at.port;
  out.push({
    key: "clause",
    text: clause
      ? `clause ${clauses.indexOf(clause) + 1} of ${clauses.length} (${at.port} ${short(clause.text, 36)})`
      : at.port === "fire" ? "fires: every clause matched"
        : at.relation ? `${port} ${at.relation}` : `${port} a value nested in a clause`,
    title: `The ${at.port} port${at.relation ? ` of ${at.relation}` : ""}: show the clause`,
    clause,
  });
  if (at["driver-rows"] > 0) {
    out.push({
      key: "row",
      text: `row ${at["driver-row"]} of ${at["driver-rows"]} in the delta`,
      title: `The driving row: ${drivingRow(at)}`,
    });
  }
  return out;
}

// The editor's badge over the stopped rule: "iter 19 · delta 412/980".
export function badge(at) {
  if (!at) return "";
  return [
    at.iteration !== null && at.iteration !== undefined && `iter ${at.iteration}`,
    at["driver-rows"] > 0 && `delta ${at["driver-row"]}/${at["driver-rows"]}`,
    at.port && `${at.port}${at.relation ? ` ${at.relation}` : ""}`,
  ].filter(Boolean).join(" · ");
}

// The crumbs that differ from `before`'s: the parts a step moved.
export function moved(before, after) {
  const was = new Map((before ?? []).map((c) => [c.key, c.text]));
  return after.filter((c) => was.size && was.get(c.key) !== c.text).map((c) => c.key);
}

// ---- The view -------------------------------------------------------------

const node = (tag, className, text) => {
  const element = document.createElement(tag);
  if (className) element.className = className;
  if (text !== undefined) element.textContent = text;
  return element;
};

// The strip, in `element`; `pick(crumb, at)` follows a click on a part.
// Returns { show(at, context), clear() }. A step changes only the parts
// that moved, and those pulse.
export function createStrip(element, pick) {
  element.classList.add("where");
  element.replaceChildren();
  const parts = new Map(); // key -> button
  let shown = [];
  let current = null;
  let layout = "";

  function show(at, context) {
    const stepped = current !== null && at !== current;
    current = at;
    const next = crumbs(at, context);
    const changed = new Set(moved(shown, next));
    // a step that lands on a place that reads the same (an emit after an
    // emit) still moved: the clause says so
    if (stepped && !changed.size && next.some((c) => c.key === "clause")) changed.add("clause");
    // the parts in order, laid out again only when which parts there are
    // changes; a step otherwise rewrites the texts that moved
    const keys = next.map((crumb) => crumb.key).join(" ");
    if (keys !== layout) {
      layout = keys;
      element.replaceChildren();
      next.forEach((crumb, k) => {
        if (k) element.append(node("span", "sep", "›"));
        element.append(parts.get(crumb.key) ?? part(crumb.key));
      });
    }
    for (const crumb of next) {
      const button = parts.get(crumb.key);
      if (button.textContent !== crumb.text) button.textContent = crumb.text;
      button.title = crumb.title;
      if (changed.has(crumb.key)) {
        button.classList.remove("moved");
        void button.offsetWidth;
        button.classList.add("moved");
      }
    }
    shown = next;
  }

  function part(key) {
    const button = node("button", `crumb ${key}`);
    button.type = "button";
    button.addEventListener("click", () => pick(shown.find((c) => c.key === key), current));
    button.addEventListener("animationend", () => button.classList.remove("moved"));
    parts.set(key, button);
    return button;
  }

  return {
    show,
    clear() {
      element.replaceChildren();
      layout = "";
      shown = [];
      current = null;
    },
  };
}
