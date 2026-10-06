// slog-lint in the editor: what the static analysis of Slog written in
// Slog (analysis/, studio/src/lint.rs) finds in the program being edited.
//
// - Markers of owner "slog-lint", a step milder than the check's errors:
//   a lint error shows as a Monaco warning, a warning as info; notes and
//   hints only as faint dots.
// - One quiet line under the summary: what is worth attention ("2
//   warnings", hints muted beside it) and whether deeper tiers are still
//   to come. A click drops the Problems list over the editor, grouped by
//   kind; Esc or a click elsewhere puts it away. A problem jumps to its
//   place; "why?" tells the analysis's own derivation of it (the REPL's
//   `why`, on the analysis lane; lint-why.js), "related" draws its
//   relation's dependencies in the change-graph panel.
// - A hover part for the relation under the cursor, after the check's
//   (Monaco shows the latest registered provider's part first, so main.js
//   creates this before the check),
//   answered from the last view alone: who writes and reads it, whether it
//   is recursive, negated or a demand, whether it can hold a row, and its
//   rows in the last Run.
//
// Findings name the top-level form they are in. A finding is shown on the
// current text only where that form still stands, word for word, moved by
// as many lines as the form moved: markers stay put while the author types
// elsewhere, and a changed form's wait for the next analysis.

import { forms } from "./forms.js";
import { details, explain } from "./lint-why.js";

const SEVERITY = { error: "Warning", warning: "Info", info: "Hint", hint: "Hint" };
const RANK = { error: 0, warning: 1, info: 2, hint: 3 };
const WORD = { error: "error", warning: "warning", info: "note", hint: "hint" };
const TIER_NAMES = ["rules", "dependencies", "demands and constructors"];

export function createLint(element, { editor, files, send, changes }) {
  let view = null;
  let open = false;
  const expanded = new Set(); // the groups opened by hand, "severity code"
  let rows = new Map(); // relation -> rows in the last Run
  const whys = new Map(); // tag -> the element to show it in
  let whyTag = 0;

  const head = element.appendChild(Object.assign(document.createElement("button"), {
    className: "lint-head", title: "The analysis's findings (slog-lint)",
  }));
  const pop = element.appendChild(Object.assign(div("lint-pop"), { hidden: true }));
  const setOpen = (value) => {
    open = value;
    render();
  };
  head.addEventListener("click", () => setOpen(!open));
  addEventListener("keydown", (event) => {
    if (open && event.key === "Escape") {
      event.preventDefault();
      setOpen(false);
    }
  });
  addEventListener("mousedown", (event) => {
    if (open && !element.contains(event.target)) setOpen(false);
  });

  const placed = (path, text) => place(view?.findings ?? [], path, text);

  // Every file's text as this tab has it (the shown one from the editor).
  const textOf = (path) => files.texts()[files.paths().indexOf(path)] ?? "";

  function mark() {
    for (const path of files.paths()) {
      editor.markers(path, "slog-lint", placed(path, textOf(path)).map((f) => ({
        line: f.line,
        col: f.col,
        severity: SEVERITY[f.severity] ?? "Hint",
        message: `${f.message}${f.stale ? " (from an earlier analysis)" : ""}`,
        code: f.code,
        source: "slog-lint",
      })));
    }
  }

  // ---- the line, and the Problems list -------------------------------------

  // "2 warnings", the counts worth attention, and the hints apart
  function counts(findings) {
    const by = (level) => findings.filter((f) => f.severity === level).length;
    const say = (level) => {
      const n = by(level);
      return n ? `${n} ${WORD[level]}${n === 1 ? "" : "s"}` : null;
    };
    return {
      attention: ["error", "warning", "info"].map(say).filter(Boolean).join(" · "),
      hints: say("hint"),
    };
  }

  function render() {
    element.hidden = !view;
    if (!view) return;
    const { working, tier, tiers, findings, error, ms } = view;
    const { attention, hints } = counts(findings.filter((f) => !f.stale));
    const deeper = tier < tiers;
    head.replaceChildren(span("lint-label", "analysis"));
    const part = (className, text) => head.append(span("lint-sep", "·"), span(className, text));
    if (error) part("lint-bad", "failed");
    else if (tier === 0 && !findings.length) part("lint-quiet", "checking…");
    else {
      part(attention ? "lint-attention" : "lint-quiet", attention || "nothing to note");
      if (hints) part("lint-quiet", hints);
    }
    if (!error && (deeper || working)) {
      part("lint-quiet", deeper && tier > 0 ? `tier ${tier}/${tiers} · ${TIER_NAMES[tier]} coming` : "rechecking");
    }
    head.title = ms.length
      ? `slog-lint: reify ${ms[0]} ms; ${ms.slice(1).map((t, i) => `${TIER_NAMES[i]} ${t} ms`).join(", ")}`
      : "slog-lint";
    head.setAttribute("aria-expanded", String(open));
    element.classList.toggle("open", open);
    pop.hidden = !open;
    if (open) list(findings, error);
  }

  // The findings grouped by severity and kind, the most pressing first; a
  // small group shows its findings, a large one or a group of hints is one
  // line until opened.
  function list(findings, error) {
    pop.replaceChildren();
    if (error) pop.append(div("lint-error", error));
    if (!findings.length && !error) pop.append(div("lint-none", "Nothing to note."));
    const groups = new Map();
    for (const f of findings) {
      const key = `${f.severity} ${f.code}`;
      if (!groups.has(key)) groups.set(key, []);
      groups.get(key).push(f);
    }
    const ordered = [...groups].sort(([a, x], [b, y]) =>
      RANK[a.split(" ")[0]] - RANK[b.split(" ")[0]] || y.length - x.length);
    for (const [key, members] of ordered) {
      const [severity, code] = key.split(" ");
      const shown = expanded.has(key) || (severity !== "hint" && members.length <= 5);
      const group = pop.appendChild(div(`lint-group ${severity}`));
      const title = group.appendChild(Object.assign(document.createElement("button"), { className: "lint-group-head" }));
      title.append(span("lint-twist", shown ? "▾" : "▸"), span("lint-code", code),
        span("lint-quiet", `${members.length} ${WORD[severity]}${members.length === 1 ? "" : "s"}`));
      if (!shown) title.append(span("lint-sample", members[0].message));
      title.addEventListener("click", () => {
        if (shown) expanded.delete(key);
        else expanded.add(key);
        render();
      });
      if (!shown) continue;
      const sorted = [...members].sort((a, b) => a.file.localeCompare(b.file) || a.line - b.line || a.col - b.col);
      for (const finding of sorted) group.append(problem(finding));
    }
  }

  function problem(finding) {
    const row = div(`lint-row${finding.stale ? " stale" : ""}`);
    const line = row.appendChild(div("lint-line"));
    const at = line.appendChild(Object.assign(document.createElement("a"), {
      textContent: `${finding.file}:${finding.line}:${finding.col}`,
    }));
    at.addEventListener("click", () => {
      setOpen(false);
      reveal(finding);
    });
    line.append(Object.assign(span("lint-message", finding.message), { title: finding.message }));
    const why = line.appendChild(button("why?", "Why the analysis says this: its derivation, in its own rules"));
    const related = line.appendChild(button("related", "What this relation depends on, and what depends on it"));
    why.addEventListener("click", () => {
      const tag = ++whyTag;
      row.querySelector(".lint-why")?.remove();
      const out = row.appendChild(div("lint-why"));
      out.append(div("lint-quiet", "rerunning the analysis, recording its derivations…"));
      whys.set(tag, out);
      send({ t: "lint-why", tag, finding });
    });
    related.addEventListener("click", () => {
      setOpen(false);
      neighbourhood(relationOf(finding));
    });
    return row;
  }

  // A derivation: the chain in words, the tree behind "details".
  function showWhy(out, nodes) {
    const chain = explain(nodes);
    out.replaceChildren();
    const words = out.appendChild(div("lint-chain"));
    chain.forEach((text, i) => words.append(div(i ? "lint-step" : "lint-claim", i ? `← ${text}` : text)));
    if (!chain.length) words.append(div("lint-quiet", "No derivation was recorded for this finding."));
    const more = out.appendChild(document.createElement("details"));
    more.append(Object.assign(document.createElement("summary"), { textContent: "details" }));
    more.append(Object.assign(document.createElement("pre"), { textContent: details(nodes).join("\n") }));
  }

  // Jump to a finding where it stands now.
  function reveal(finding) {
    files.open(finding.file);
    const here = placed(finding.file, editor.get()).find((f) => f.col === finding.col && f.code === finding.code && f.message === finding.message);
    editor.reveal({ line: (here ?? finding).line, col: finding.col });
  }

  // ---- relations: the hover, and the dependency graph --------------------

  const fact = (name) => view?.facts?.[name] ?? [];
  const relations = () => new Set([...fact("writer"), ...fact("reader")].map(([rel]) => rel));

  // The relation a finding is about: the word at it, else what its line writes.
  function relationOf(finding) {
    const line = textOf(finding.file).split("\n")[finding.line - 1] ?? "";
    const word = /^[A-Za-z_][\w'.]*/.exec(line.slice(finding.col - 1))?.[0];
    const known = relations();
    if (word && known.has(word)) return word;
    return fact("writer").find(([, file, at]) => file === finding.file && Number(at) === finding.line)?.[0] ?? word;
  }

  function neighbourhood(relation) {
    if (!relation) return;
    const edges = fact("dep")
      .filter(([from, to]) => from === relation || to === relation)
      .map(([from, to, sign]) => ({ from, to, status: sign === "-" ? "removed" : "same" }));
    const ids = new Set([relation, ...edges.flatMap(({ from, to }) => [from, to])]);
    const nodes = [...ids].map((id) => ({ id, kind: "relation", status: id === relation ? "changed" : "same" }));
    changes.show({
      owner: "lint",
      heading: `${relation}: what it depends on, and what depends on it`,
      graph: { nodes, edges },
      legend: [["changed", relation], ["same", "a dependency"], ["removed", "read under ~"]],
      onNode: (id) => id !== relation && neighbourhood(id),
    });
  }

  function hover(word, path, line) {
    if (!view) return null;
    const writers = fact("writer").filter(([rel]) => rel === word);
    const readers = fact("reader").filter(([rel]) => rel === word);
    const lines = [];
    const where = (list) => [...new Set(list.map(([, file, at]) => `${file === path ? "" : `${file}:`}${at}`))].join(", ");
    if (writers.length || readers.length) {
      lines.push(`**${word}** · slog-lint`);
      lines.push(writers.length ? `derived by the rules at line ${where(writers)}` : "derived by no rule: an input");
      if (readers.length) lines.push(`read at line ${where(readers)}`);
      const negated = readers.filter(([, , , sign]) => sign === "-");
      if (negated.length) lines.push(`read under ~ at line ${where(negated)}`);
      if (fact("recursive").some(([rel]) => rel === word)) {
        const cycle = fact("cycle_with").filter(([a]) => a === word).map(([, b]) => b);
        lines.push(`recursive${cycle.length ? `, in a cycle with ${cycle.join(", ")}` : ""}`);
      }
      const asks = fact("demand_calls").filter(([, g]) => g === word).map(([f]) => f);
      if (asks.length) lines.push(`a demand, asked by ${[...new Set(asks)].join(", ")}`);
      if (view.tier >= 2) lines.push(fact("inhabited").some(([rel]) => rel === word) ? "can hold rows" : "**can never hold a row**");
    }
    if (rows.has(word)) lines.push(`${rows.get(word)} row${rows.get(word) === 1 ? "" : "s"} in the last Run`);
    if (fact("never_fires").some(([file, at]) => file === path && Number(at) === line)) {
      lines.push("**the rule here can never fire**");
    }
    return lines.length ? lines.join("  \n") : null;
  }

  // the hover provider, once Monaco is there
  const monaco = editor.raw?.monaco;
  monaco?.languages.registerHoverProvider("slog", {
    provideHover(model, position) {
      const path = editor.keyOf(model);
      const word = model.getWordAtPosition(position);
      if (!path || !word) return null;
      const text = hover(word.word, path, position.lineNumber);
      if (!text) return null;
      return {
        range: new monaco.Range(position.lineNumber, word.startColumn, position.lineNumber, word.endColumn),
        contents: [{ value: text }],
      };
    },
  });

  let pending = null;
  return {
    // For tests and the console: the findings of `path` placed on `text`.
    placed,
    view: () => view,
    show(next) {
      view = next ?? view;
      mark();
      render();
    },
    // The text changed: place the findings again, once typing pauses.
    changed() {
      clearTimeout(pending);
      pending = setTimeout(mark, 300);
    },
    // A command's answer: the last Run's relation sizes.
    entry(entry) {
      const relations = entry.result?.relations;
      if (entry.line === "tables" && Array.isArray(relations)) {
        rows = new Map(relations.map(({ name, rows: n }) => [name, n]));
      }
    },
    why({ tag, nodes, error }) {
      const out = whys.get(tag);
      whys.delete(tag);
      if (!out) return;
      if (error) out.replaceChildren(div("lint-error", error));
      else showWhy(out, nodes);
    },
    // "Edit the analysis"
    edit: () => send({ t: "edit-analysis" }),
  };
}

// ---- placing findings on the text as it is now -----------------------------

// Each form's text (its lines, without the blank and comment lines that
// trail it, as lint.rs `form_of` reads them) -> the lines it starts on.
function formIndex(text) {
  const lines = text.split("\n");
  const index = new Map();
  for (const form of forms(text)) {
    let end = form.endLine;
    while (end > form.line && /^\s*(;;.*)?$/.test(lines[end - 1] ?? "")) end--;
    const body = lines.slice(form.line - 1, end).join("\n").trimEnd();
    if (!index.has(body)) index.set(body, []);
    index.get(body).push(form.line);
  }
  return index;
}

// The `findings` of `path`, at their lines in `text`; those whose form
// changed are left out.
export function place(findings, path, text) {
  const index = formIndex(text);
  return findings.filter((f) => f.file === path).flatMap((f) => {
    if (!f.form) return [f];
    const starts = index.get(f.form);
    if (!starts) return [];
    const start = starts.includes(f.form_line) ? f.form_line : starts[0];
    return [{ ...f, line: f.line - f.form_line + start }];
  });
}

function div(className, text) {
  return Object.assign(document.createElement("div"), { className, textContent: text ?? "" });
}

function span(className, text) {
  return Object.assign(document.createElement("span"), { className, textContent: text ?? "" });
}

function button(text, title) {
  return Object.assign(document.createElement("button"), { className: "quiet small", textContent: text, title });
}
