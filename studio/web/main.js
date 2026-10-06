// Slog Studio in the browser: the project's files and editor, the REPL
// transcript and prompt, and the status strip, all fed by one WebSocket to
// the studio.

import { createEditor } from "./editor.js";
import { createFiles } from "./files.js";
import { formAt, forms } from "./forms.js";
import { initAgent } from "./agent.js";
import { createHistory } from "./history.js";
import { createHints } from "./hints.js";
import { createPalette } from "./palette.js";
import { createStarters } from "./starters.js";
import { createChangePanel } from "./changes.js";
import { createProposals } from "./proposals.js";
import { renderEntry } from "./render.js";
import { createSummary } from "./summary.js";
import { createLint } from "./lint.js";
import * as structure from "./paredit.js";
import { createResults } from "./results.js";
import { createExplorer } from "./explorer.js";
import { createCells } from "./cells.js";
import { createInline } from "./inline.js";
import { initTrace } from "./trace.js";
import { locate } from "./live.js";
import { initAssist } from "./assist.js";
import { createBreakpoints, glyphClass, describe, stopOf } from "./breakpoints.js";
import { initCalls } from "./calls.js";
import { initTimeline } from "./timeline.js";
import { createRewind } from "./rewind.js";
import { createCheck } from "./check.js";
import { createInspector } from "./inspect.js";
import { installStamps, noteSet, stateName } from "./stamp.js";

const $ = (id) => document.getElementById(id);
// Local mode's launch token; a server's login rides in a cookie instead.
const token = location.hash.slice(1);
// The project the page was opened on (`/?project=NAME`); none is the default.
// connect() asks for the project the first connection named, so a page opened
// on the default stays on that project when it reconnects, though the
// default (the project opened last) may since have moved to another.
const project = new URLSearchParams(location.search).get("project") ?? "";

const state = {
  lane: { state: "idle", detail: "", starts: 0 },
  session: { current: null, held: false },
  evaluating: false,
  log: null, // the <pre> collecting consecutive server output lines
  heldTitle: "", // where the held run stopped, from its pause result
  scenarios: new Map(), // name -> { running, report, error }
  directory: "", // where the project's files are evaluated
};

let socket = null;
const transmit = (message) => {
  if (socket?.readyState === WebSocket.OPEN) socket.send(JSON.stringify(message));
};

const editor = await createEditor($("editor"), {
  onChange: () => {
    starters.hide();
    files.changed();
    check.changed();
    lint.changed();
  },
  onEvaluate: evaluate,
  onSave: save,
});

const summary = createSummary($("summary"), {
  editor,
  current: () => files.mainState(),
});
const files = createFiles({
  editor,
  transmit,
  note,
  onOpen(path) {
    // The summary's notes and findings belong on the main file.
    summary.show();
    lint.show();
    versions.opened();
    proposals.refresh();
    breakpoints.show(path);
  },
  onSaved: () => summary.refresh(),
  onBreakpoints: (path, points) => {
    breakpoints.receive(path, points);
    renderBreakpoints();
  },
  onExamples: () => palette.open("New from example"),
});
// Every message goes behind the edits already made, so it sees them.
const send = files.send;
// New projects from the examples, and the strip that offers them.
const starters = createStarters({ send, run: evaluate, browse: () => palette.open("New from example") });
// Proposals are reviewed in the editor; the change graph and the history
// strip show only when asked for or when they matter.
const changes = createChangePanel($("work"));
// What the analysis of Slog in Slog finds as the author edits (lint.js).
// Monaco shows the most recently registered hover provider's part first,
// so this registers before the check, whose part leads.
const lint = createLint($("lint"), { editor, files, send, changes });
// The static check, live as the author types, and the hovers it feeds.
const check = createCheck({ editor, files, send });
const versions = createHistory({ send, files, changes });
const proposals = createProposals({
  editor, files, send, changes, history: versions, bar: $("proposals"), list: $("review-tab"),
});
// Set in the editor, kept with the project, armed by Debug (breakpoints.js).
const breakpoints = createBreakpoints({
  editor,
  file: () => files.active() ?? "",
  texts: () => files.texts(),
  onChange(file, points) {
    send({ t: "breakpoints", file, points });
    renderBreakpoints();
  },
  onBindings: (x, y) => inspector.bindingsPopup(x, y),
});
// A REPL line answered to this tab only, kept out of the transcript.
const asked = new Map();
let quietTag = 0;
function quiet(line) {
  const tag = ++quietTag;
  return new Promise((resolve) => {
    asked.set(tag, resolve);
    send({ t: "quiet", line, tag });
  });
}
// A rule's location "main.slog:12:1", shown in the editor.
function revealSource(loc) {
  const match = /^(.*):(\d+):(\d+)$/.exec(loc ?? "");
  const path = match && files.paths().find((p) => p.split("/").pop() === match[1].split("/").pop());
  if (!path) return;
  files.open(path);
  editor.reveal({ line: Number(match[2]), col: Number(match[3]) });
}
// Peeks, break-outs and the Relations panel (explorer.js), kept as cells
// in a column beside the transcript (cells.js).
const cellsColumn = $("drawer").insertAdjacentElement("beforebegin", document.createElement("aside"));
const explorer = createExplorer({
  send,
  panel: $("relations-tab"),
  openPanel: () => isOpen("relations") || showTab("relations"),
  run: (line) => send({ t: "command", line }),
  openSet: (line) => results.openQuery(line),
  cells: createCells(cellsColumn),
});
const results = createResults({
  tabs: $("result-tabs"),
  panel: $("results"),
  transcript: $("transcript"),
  send,
  run: (line) => send({ t: "command", line }),
  explorer,
});
// Answers of rows as tables in the transcript (inline.js).
const inline = createInline({ results, explorer, root: $("transcript") });
// The Execution tab: the latest run as it goes, and each change's trace,
// fed every entry and the run's progress (trace.js).
const trace = initTrace({
  editor,
  send,
  file: () => files.active() ?? "",
  tabs: $("result-tabs"),
  transcript: $("transcript"),
  results: $("results"),
  reveal: (span) => files.reveal(projectSpan(span) ?? span),
  ask: (entry) => assist.ask(entry, "Why did this fail, and how do I fix it?"),
});
// The session's states, by logical timestamp, at the prompt and in each
// entry's gutter; a click explores a past one (timeline.js).
const timeline = initTimeline({ at: $("stamp"), panel: $("state-tree"), send });
// Where to go back to when a breakpoint cannot stop (rewind.js); the tree
// opens to show the branch the rerun makes.
const rewind = createRewind({ send, onBranch: () => timeline.show() });
installStamps({ send }); // every stamp's card, and its rename

// An error's place as the files panel names it: a compiler message that
// names its file by base name ("main.slog:4:1: …") names the project's.
function projectSpan(span) {
  if (!span || files.pathOf(span.file) !== null) return span;
  const path = files.paths().find((p) => p.split("/").pop() === span.file.split("/").pop());
  return path ? { ...span, file: `${state.directory}/${path}` } : null;
}

// The Calls tab: the run's demand calls (calls.js).
const calls = initCalls({
  quiet,
  reveal: revealSource,
  tabs: $("result-tabs"),
  transcript: $("transcript"),
  results: $("results"),
});
// The Variables tab and hovers over a held stop (inspect.js).
const inspector = createInspector({
  editor,
  quiet,
  reveal: revealSource,
  tabs: $("result-tabs"),
  transcript: $("transcript"),
  results: $("results"),
});

function save() {
  files.flush();
  send({ t: "save" });
}

function evaluate() {
  starters.hide();
  files.flush();
  send({ t: "evaluate" });
}

function debug() {
  files.flush();
  send({ t: "debug" });
}

// Messages from the studio -------------------------------------------------

const receive = {
  init(snapshot) {
    state.lane = snapshot.lane;
    state.session = snapshot.session;
    state.directory = snapshot.directory;
    if (snapshot.progress) trace.progress(snapshot.progress);
    agent.snapshot(snapshot);
    summary.show(snapshot.summary);
    snapshot.results.forEach(noteSet);
    timeline.states(snapshot.states); // before anything stamped
    lint.show(snapshot.lint);
    results.init(snapshot.results);
    explorer.init();
    trace.tracing(snapshot.tracing);
    structure.observe({ result: snapshot.tables }); // completion: the session's relations, after a reload
    snapshot.results.forEach(offerRelation);
    history.load();
    renderStatus();
    check.changed();
    starters.init(snapshot);
  },
  // another tab's edit, an accepted proposal, a restored version
  text() {
    check.changed();
    lint.changed();
  },
  files() {
    check.changed();
    lint.changed();
  },
  rewind(choice) {
    rewind.open(choice);
  },
  states(view) {
    timeline.states(view);
  },
  tracing({ on }) {
    trace.tracing(on);
  },
  progress(delta) {
    trace.progress(delta);
  },
  lane(status) {
    state.lane = status;
    renderStatus();
  },
  session(view) {
    state.session = view;
    // nothing held: no stop to show
    if (!view.held) {
      state.callsHeld = false;
      state.stopAt = null;
      stops++;
      breakpoints.held(null);
      inspector.released();
    }
    renderStatus();
  },
  log({ line }) {
    if (!state.log) state.log = append(document.createElement("pre"), "log");
    state.log.textContent += (state.log.textContent ? "\n" : "") + line;
    scrollTranscript();
  },
  entry(entry) {
    state.log = null;
    structure.observe(entry); // completion's catalog, breaks, watches
    if (entry.result?.kind === "paused") {
      state.heldTitle = entry.result.title;
      state.callsHeld = Boolean(entry.result.calls?.stack?.length);
      showStop(entry.result);
      renderStatus();
    } else if (entry.result?.held === false) {
      state.callsHeld = false;
      state.stopAt = null;
      stops++;
      breakpoints.held(null);
      inspector.released();
      renderStatus();
    }
    measured(entry);
    lint.entry(entry);
    const node = append(renderEntry(entry, {
      inProject: (span) => files.pathOf(span.file) !== null,
      onSpan: (span) => files.reveal(span),
      onSet: results.show,
      table: inline.table,
    }));
    assist.entry(entry, node); // "explain", "Ask why", and the assistant's context
    timeline.entry(entry, node); // its state's stamp
    // The area follows the newest output: a query's set, else the
    // transcript, unless the Execution tab shows what it was about.
    const executing = trace.entry(entry);
    calls.entry(entry);
    // A query's rows show in the transcript; the Results area follows only
    // while it is open.
    if (entry.set && !$("results").hidden) results.show(entry.set);
    else if (entry.origin === "repl" && !executing) results.show(null);
    // a compile error located only by its message is marked all the same
    const span = entry.error?.span ?? projectSpan(locate(entry.error?.message));
    if (entry.origin === "evaluate" && span) {
      files.mark(span, entry.error.message);
      files.reveal(span);
    }
  },
  evaluation({ phase, ok, held, ms }) {
    state.evaluating = phase === "start";
    if (phase === "start") {
      editor.mark(null);
      trace.started();
    } else {
      explorer.evaluated(); // stale peeks read again
      // A held run has not failed: it waits for continue, commit or abort.
      if (held) note(`⏸ run held after ${(ms / 1000).toFixed(1)} s`, "evaluation");
      else note(ok ? `✓ ran in ${(ms / 1000).toFixed(1)} s` : "✗ run failed", ok ? "evaluation" : "evaluation failed");
    }
    renderStatus();
  },
  notice({ message }) {
    note(message);
  },
  review(view) {
    agent.review(view);
  },
  agent(event) {
    agent.agent(event);
  },
  asked(reply) {
    agent.asked(reply);
  },
  databases({ names }) {
    structure.setDatabases(names);
  },
  "result-set": (view) => {
    noteSet(view);
    results.update(view);
    offerRelation(view);
  },
  rows: (reply) => results.rows(reply),
  scenarios({ names }) {
    const known = state.scenarios;
    state.scenarios = new Map(names.map((name) => [name, known.get(name) ?? {}]));
    renderScenarios();
  },
  scenario({ name, running, report, error }) {
    state.scenarios.set(name, { running, report, error });
    renderScenarios();
  },
  summary(view) {
    summary.show(view);
  },
  lint(view) {
    lint.show(view);
  },
  "lint-why": (reply) => lint.why(reply),
  // "Edit the analysis": the analysis's own project, in a tab of its own
  "open-project": ({ name }) => {
    window.open(`/?project=${encodeURIComponent(name)}${location.hash}`, "_blank");
  },
  "breakpoint-status": ({ statuses }) => {
    breakpoints.status(statuses);
    renderBreakpoints();
  },
  quiet(reply) {
    asked.get(reply.tag)?.(reply);
    asked.delete(reply.tag);
  },
};

// A held stop, shown in the editor at its clause, with its bindings
// beside it; another file's stop opens that file.
let stops = 0; // counts stops and resumes, so a late answer is dropped
async function showStop(result) {
  const serial = ++stops;
  const stop = stopOf(result);
  if (!stop) return breakpoints.held(null);
  const path = files.paths().find((p) => p.split("/").pop() === stop.file);
  if (path && path !== files.active()) files.open(path);
  breakpoints.held(path ? stop : null);
  const frames = await quiet("frames");
  if (serial !== stops) return;
  breakpoints.held(path ? stop : null, frames.result?.bindings ?? []);
  const where = /iteration (\d+)/.exec(result.lines?.[0] ?? "");
  state.stopAt = `${stop.port} ${stop.file}:${stop.line}${where ? ` · iteration ${where[1]}` : ""}`;
  renderStatus();
  await inspector.held(breakpoints.stopRange(), frames.result, result.calls?.stack);
  // a first stop shows its variables; later ones keep the tab chosen
  if (!state.inspected) {
    state.inspected = true;
    inspector.show();
  }
}

// The Breakpoints panel and the header's count.
function renderBreakpoints() {
  const all = breakpoints.list();
  $("bp-badge").hidden = all.length === 0;
  $("bp-count").textContent = String(all.length);
  const list = $("bp-list");
  list.replaceChildren();
  if (!all.length) list.append(Object.assign(document.createElement("p"), { className: "hint", textContent: "No breakpoints yet." }));
  for (const { path, point, status } of all) {
    const row = list.appendChild(document.createElement("div"));
    row.className = `bp-row${point.enabled ? "" : " off"}`;
    const toggle = row.appendChild(Object.assign(document.createElement("input"), { type: "checkbox", checked: point.enabled, title: "Enabled" }));
    toggle.addEventListener("click", (event) => { event.stopPropagation(); breakpoints.toggle(path, point.id); });
    row.append(Object.assign(document.createElement("span"), { className: glyphClass(point, status) }));
    const at = point.at ?? [point.line, 1];
    row.append(Object.assign(document.createElement("span"), { className: "where", textContent: `${path}:${at[0]}` }));
    const what = [describe(point), point.condition && `when ${point.condition}`, point.ignore && `ignore ${point.ignore}`, point.log && "log"].filter(Boolean).join(" · ");
    row.append(Object.assign(document.createElement("span"), { className: "what", textContent: what, title: what }));
    if (status?.hits) row.append(Object.assign(document.createElement("span"), { className: "hits", textContent: `${status.hits}×` }));
    if (status?.status === "unbound" || status?.status === "error") {
      row.append(Object.assign(document.createElement("span"), { className: "why", textContent: "cannot stop", title: status.why }));
    }
    const remove = row.appendChild(Object.assign(document.createElement("button"), { className: "remove", textContent: "×", title: "Delete" }));
    remove.addEventListener("click", (event) => { event.stopPropagation(); breakpoints.remove(path, point.id); });
    row.addEventListener("click", () => {
      files.open(path);
      editor.reveal({ line: at[0], col: at[1] });
    });
    row.addEventListener("dblclick", () => { files.open(path); breakpoints.open(point.id); });
  }
}

// Latency, click to rendered result, for the debugger's own commands:
// window.debugLatency holds { line, server, total } in milliseconds.
const clicked = new Map(); // line -> when it was sent
window.debugLatency = [];
// The analysis's view and placement, for tests and the console.
window.slogLint = lint;
function measured(entry) {
  const sent = clicked.get(entry.line);
  if (sent === undefined) return;
  clicked.delete(entry.line);
  requestAnimationFrame(() => window.debugLatency.push({
    line: entry.line,
    server: entry.ms,
    total: Math.round(performance.now() - sent),
  }));
}
function command(line) {
  clicked.set(line, performance.now());
  send({ t: "command", line });
}

// Consecutive connection attempts that never opened. A refused handshake
// (a link from another launch's token) and a stopped server look the same
// from here, so after a few the status says which to check.
let failedAttempts = 0;

// Completion offers a query's kept relation, as `?(r1 …`, while the session
// that holds it lasts.
function offerRelation(view) {
  if (!view.relation || view.stale) return;
  structure.addRelation({
    name: view.relation,
    arity: view.columns.length,
    detail: view.columns.map((column) => column.type ?? ""),
    at: view.state ? stateName(view.state) : null,
  });
}

function connect() {
  const scheme = location.protocol === "https:" ? "wss" : "ws";
  const named = files.project() || project;
  const query = `token=${encodeURIComponent(token)}&project=${encodeURIComponent(named)}`;
  socket = new WebSocket(`${scheme}://${location.host}/ws?${query}`);
  socket.onopen = () => {
    failedAttempts = 0;
    renderStatus();
  };
  socket.onmessage = (message) => {
    const data = JSON.parse(message.data);
    for (const handlers of [files.receive, receive, versions.receive, assist.receive, check.receive, explorer.receive, starters.receive]) handlers[data.t]?.(data);
  };
  socket.onclose = () => {
    failedAttempts += 1;
    renderStatus();
    setTimeout(connect, 1000);
  };
}

// The REPL prompt --------------------------------------------------------

const prompt = $("prompt");
// Structured editing and completion, ahead of the prompt's own keys, from
// every project file: the relations it declares, the rules `break` names.
structure.bindPrompt(prompt, {
  files() {
    const texts = files.texts();
    return Object.fromEntries(files.paths().map((path, i) => [path, texts[i]]));
  },
});
// Completion offers the saved databases, and the session's breaks and
// watches as they stand when the prompt is first used.
let listed = false;
prompt.addEventListener("focus", () => {
  send({ t: "databases" });
  if (listed || !state.session.current) return;
  listed = true;
  for (const line of ["breaks", "watches"]) quiet(line).then(structure.observe);
});
const controls = structure.mountControls();
const historyKey = () => `slog-studio.history:${files.project()}`;
const history = {
  lines: [],
  index: 0,
  load() {
    try { this.lines = JSON.parse(localStorage.getItem(historyKey())) ?? []; } catch { this.lines = []; }
    this.index = this.lines.length;
  },
  push(line) {
    if (this.lines.at(-1) !== line) this.lines.push(line);
    this.lines = this.lines.slice(-500);
    this.index = this.lines.length;
    try { localStorage.setItem(historyKey(), JSON.stringify(this.lines)); } catch { /* private mode */ }
  },
};

// The arrows walk the history, as do C-p and C-n, as in a shell.
const previous = (event) => event.key === "ArrowUp" || (event.ctrlKey && !event.altKey && event.code === "KeyP");
const next = (event) => event.key === "ArrowDown" || (event.ctrlKey && !event.altKey && event.code === "KeyN");
prompt.addEventListener("keydown", (event) => {
  const text = prompt.value;
  if (event.key === "Enter" && !event.shiftKey && balanced(text)) {
    event.preventDefault();
    const line = text.trim();
    if (!line) return;
    history.push(line);
    send({ t: "command", line });
    prompt.value = "";
    fitPrompt();
  } else if (previous(event) && !text.slice(0, prompt.selectionStart).includes("\n")) {
    if (history.index === 0) return;
    event.preventDefault();
    prompt.value = history.lines[--history.index];
    fitPrompt();
  } else if (next(event) && !text.slice(prompt.selectionEnd).includes("\n")) {
    if (history.index >= history.lines.length) return;
    event.preventDefault();
    prompt.value = history.lines[++history.index] ?? "";
    fitPrompt();
  }
});
prompt.addEventListener("input", fitPrompt);

// The REPL's assistant (`??`, or Tab on an empty prompt) and the live
// preview of a query being typed; its keys come before the prompt's own.
const assist = initAssist({
  prompt,
  transcript: $("transcript"),
  send,
  proposalChip: (ids) => proposals.chip(ids, { accept: true }),
  check: check.request,
  showTranscript: () => results.show(null),
  openThread(thread) {
    agent.asked({ thread });
    if ($("drawer").hidden || $("drawer").dataset.tab !== "ask") showTab("ask");
  },
});

function fitPrompt() {
  prompt.rows = Math.min(12, prompt.value.split("\n").length);
}

// Brackets outside strings and `;;` comments all close: the line is a
// complete command, so Enter runs it rather than starting a new line.
function balanced(text) {
  let depth = 0;
  for (let i = 0; i < text.length; i++) {
    const c = text[i];
    if (c === "\"") {
      for (i++; i < text.length && text[i] !== "\""; i++) if (text[i] === "\\") i++;
    } else if (c === ";" && text[i + 1] === ";") {
      while (i < text.length && text[i] !== "\n") i++;
    } else if ("([{".includes(c)) depth++;
    else if (")]}".includes(c)) depth--;
  }
  return depth <= 0;
}

// Transcript and status --------------------------------------------------

const transcript = $("transcript");
const MAX_TRANSCRIPT = 500;

function append(node, className) {
  if (className) node.className = className;
  const atBottom = transcript.scrollHeight - transcript.scrollTop - transcript.clientHeight < 40;
  transcript.append(node);
  while (transcript.childElementCount > MAX_TRANSCRIPT) transcript.firstElementChild.remove();
  if (atBottom) scrollTranscript();
  return node;
}

function scrollTranscript() {
  transcript.scrollTop = transcript.scrollHeight;
}

function note(text, className = "entry note") {
  state.log = null;
  const node = document.createElement("div");
  node.textContent = text;
  append(node, className);
}

// A status pill: a state dot ("ok", "busy", "bad", or none) and its text.
function pill(id, text, dot = null, className = "") {
  const node = $(id);
  node.className = `pill ${className}`.trim();
  node.replaceChildren();
  if (dot) node.append(Object.assign(document.createElement("span"), { className: `state ${dot}` }));
  node.append(text);
}

// The status strip says little while all is well: the mode and a dot, the
// session's database. Trouble (no connection, a dead session server) says
// more, and offers what helps.
function renderStatus() {
  const online = socket?.readyState === WebSocket.OPEN;
  pill("connection",
    online ? ""
      : failedAttempts >= 3 ? ($("account")
        ? "not connected — is the studio running? If your login ended, reload to log in again"
        : "not connected — is the studio running? A link from an earlier launch needs the address it printed")
      : "reconnecting…",
    online ? null : "bad");

  const { state: lane, detail, starts, mode } = state.lane;
  const restarts = starts > 1 ? ` · restarted ${starts - 1}×` : "";
  const laneDot = { ready: "ok", idle: "ok", busy: "busy", starting: "busy" }[lane] ?? "bad";
  const well = lane === "ready" || lane === "idle";
  pill("lane", [mode, well ? "ready" : `session server ${lane}${restarts}${detail ? ` — ${detail}` : ""}`]
    .filter(Boolean).join(" · "), laneDot);
  $("restart").hidden = laneDot !== "bad";
  for (const button of $("mode").querySelectorAll("button")) {
    button.setAttribute("aria-checked", String(button.dataset.mode === mode));
  }

  const { current, held } = state.session;
  pill("session",
    held ? "run held" : current ? `database ${current}` : "",
    null, held ? "held" : "");
  pill("evaluation", state.evaluating ? "running…" : "", state.evaluating ? "busy" : null);

  $("held").hidden = !held;
  // the prompt reads the paused state, and says so
  prompt.placeholder = held && state.stopAt
    ? `held at ${state.stopAt} (paused) — p VAR, ?(rel …) and peek REL read this stop without moving it`
    : "?(relation X Y)   tables   :help        Enter runs once brackets balance · Shift+Enter for a new line";
  prompt.classList.toggle("held", Boolean(held && state.stopAt));
  for (const button of document.querySelectorAll(".calls-step")) button.hidden = !state.callsHeld;
  $("held-title").textContent = `run held — ${state.heldTitle || "paused"}`;
  $("stop").disabled = lane !== "busy";
  $("evaluate").disabled = state.evaluating;
  $("debug").disabled = state.evaluating;
}

// Scenarios --------------------------------------------------------------

function renderScenarios() {
  const list = $("scenario-list");
  list.replaceChildren();
  if (!state.scenarios.size) {
    list.append(Object.assign(document.createElement("p"), { className: "hint", textContent: "No scenarios yet." }));
  }
  for (const [name, { running, report, error }] of state.scenarios) {
    const card = list.appendChild(document.createElement("div"));
    card.className = "scenario";
    const head = card.appendChild(document.createElement("div"));
    head.className = "scenario-head";
    head.append(Object.assign(document.createElement("span"), { className: "scenario-name", textContent: name }));
    const verdict = running ? "running…" : error ? "error" : report ? (passed(report) ? "PASS" : "FAIL") : "";
    head.append(Object.assign(document.createElement("span"), {
      className: `verdict ${verdict === "PASS" ? "pass" : verdict === "FAIL" || verdict === "error" ? "fail" : ""}`,
      textContent: verdict,
    }));
    const run = head.appendChild(Object.assign(document.createElement("button"), {
      className: "secondary small", textContent: "Run", disabled: running,
    }));
    run.addEventListener("click", () => send({ t: "run-scenario", name }));
    if (error) card.append(line("fail", error));
    if (report && !running) card.append(renderReport(report));
  }
}

function passed(report) {
  return !report.setup && [...report.checks, ...report.steps].every((judged) => judged.verdict !== "fail");
}

function renderReport(report) {
  const node = document.createElement("div");
  node.className = "result";
  if (report.setup) node.append(line("fail", `✗ ${report.setup}`));
  const mark = { pass: "✓", fail: "✗", xfail: "~" };
  for (const [prefix, judged] of [
    ...report.checks.map((check) => ["check ", check]),
    ...report.steps.map((step) => ["", step]),
  ]) {
    node.append(line(judged.verdict, `${mark[judged.verdict]} ${prefix}${judged.what}`));
    if (judged.why) node.append(line("why", judged.why));
  }
  return node;
}

function line(className, text) {
  return Object.assign(document.createElement("div"), { className, textContent: text });
}

// The drawer shows one tab; its header button, or the palette, toggles it.
function showTab(tab) {
  const drawer = $("drawer");
  const open = !(drawer.hidden === false && drawer.dataset.tab === tab);
  drawer.hidden = !open;
  drawer.dataset.tab = tab;
  for (const pane of drawer.querySelectorAll(".tab")) pane.hidden = pane.dataset.tab !== tab;
  for (const button of document.querySelectorAll(".panel-toggle")) {
    button.setAttribute("aria-pressed", String(open && button.dataset.tab === tab));
  }
  renderReview();
  if (open && tab === "scenarios") send({ t: "scenarios" });
}
for (const button of document.querySelectorAll(".panel-toggle")) {
  button.addEventListener("click", () => showTab(button.dataset.tab));
}

const isOpen = (tab) => $("drawer").hidden === false && $("drawer").dataset.tab === tab;

// Review earns its place in the header while proposals wait, or while open.
let pending = 0;
function renderReview() {
  $("review-toggle").hidden = pending === 0 && !isOpen("review");
  $("pending").hidden = pending === 0;
  $("pending").textContent = String(pending);
}

const agent = initAgent({
  send,
  proposals,
  onPending(count) {
    pending = count;
    renderReview();
  },
});

// Hints, Commands and focus ------------------------------------------------

// The keys worth naming at `line`, most useful first; the hint card shows
// the first few (hints.js).
const RUN_KEY = structure.MAC ? "⌘↵" : "Ctrl+Enter";
const hints = createHints({
  editor,
  element: $("editor"),
  keysAt(line) {
    const form = formAt(forms(editor.get()), line);
    const rule = form?.keyword === "rule"
      ? ["click the margin to break on the rule, a dot to break on a clause"]
      : [];
    return [...rule, ...structure.keysAt(editor.get(), line), `${RUN_KEY} run`];
  },
  onChange(shown, locked) {
    $("hints").textContent = locked ? "hints locked · Esc" : `${structure.MAC ? "⌥H" : "Alt+H"} hints`;
    $("hints").classList.toggle("locked", locked);
  },
});
$("hints").addEventListener("click", () => hints.toggle());

// Every action by name: the home of what the header and the status strip
// do not show (palette.js).
const palette = createPalette(() => {
  const mode = state.lane.mode;
  const panel = (tab, title) => ({ title, note: isOpen(tab) ? "open" : "", run: () => showTab(tab) });
  return [
    { title: "Run", keys: RUN_KEY, run: evaluate },
    { title: "Debug: run, stopping at the breakpoints", run: debug },
    panel("breakpoints", "Breakpoints: every one, with its hits"),
    { title: "Calls: the run's demand calls", run: () => calls.show() },
    ...(state.session.held ? [
      { title: "Continue the held run", run: () => command("continue") },
      ...(state.callsHeld ? [
        { title: "Step into the call", run: () => command("step into") },
        { title: "Step over the call", run: () => command("step over") },
        { title: "Step out of the call", run: () => command("step out") },
      ] : []),
      { title: "Step to the next port", run: () => command("step") },
      { title: "Abort the held run", run: () => command("abort") },
    ] : []),
    { title: "Stop the running command", note: state.lane.state === "busy" ? "" : "nothing running", run: () => send({ t: "interrupt" }) },
    { title: "Save", keys: structure.MAC ? "⌘S" : "Ctrl+S", run: save },
    ...check.commands(),
    ...[
      ["fast", "tiering: interpreted, then native code for long strata"],
      ["debug", "one thread: breakpoints and steps stop at the same place"],
      ["compiled", "native code (-O2), for performance work"],
    ].map(([name, about]) => ({
      title: `Mode: ${name} — ${about}`,
      note: name === mode ? "current" : "",
      run: () => send({ t: "mode", mode: name }),
    })),
    { title: "Restart the session server", run: () => send({ t: "restart" }) },
    panel("ask", "Ask the agent"),
    panel("review", "Review proposals"),
    panel("scenarios", "Scenarios"),
    panel("relations", "Relations: every relation, its count and rows"),
    { title: "History: every version of the project, and its branches", run: versions.open },
    { title: "Edit the analysis: slog-lint, over this program's facts", run: lint.edit },
    { title: "New file", run: () => $("new-file").click() },
    ...starters.commands(),
    { title: "Focus the editor", keys: "Esc", run: () => editor.focus() },
    { title: "Focus the REPL prompt", keys: "Ctrl+`", run: () => prompt.focus() },
    { title: "Structured editing", note: controls.structured() ? "on" : "off", run: () => controls.setStructured(!controls.structured()) },
    { title: "Structured editing keys", run: controls.showKeys },
    { title: "Hints", keys: structure.MAC ? "⌥H" : "Alt+H", note: hints.locked ? "locked" : "", run: hints.toggle },
  ];
});
const PALETTE_KEY = structure.MAC ? "⌘K" : "Ctrl+Shift+P";
$("commands").title = `Commands: modes, panels, history, restart (${PALETTE_KEY})`;
$("commands").addEventListener("click", () => palette.open());
$("palette-key").textContent = `${PALETTE_KEY} commands`;
$("palette-key").addEventListener("click", () => palette.open());
$("lane").addEventListener("click", () => palette.open("mode"));

addEventListener("keydown", (event) => {
  const command = event.metaKey || event.ctrlKey;
  // Cmd+K on a Mac (Ctrl+K kills to the end of the list), and
  // Cmd/Ctrl+Shift+P everywhere.
  if ((command && event.shiftKey && event.code === "KeyP") || (structure.MAC && event.metaKey && !event.shiftKey && event.code === "KeyK")) {
    event.preventDefault();
    event.stopPropagation();
    palette.open();
  } else if (event.ctrlKey && event.code === "Backquote") {
    // between the editor and the prompt
    event.preventDefault();
    event.stopPropagation();
    if (document.activeElement === prompt) editor.focus();
    else prompt.focus();
  }
}, true);
// Esc, unclaimed, goes back to the editor.
addEventListener("keydown", (event) => {
  if (event.key !== "Escape" || event.defaultPrevented || $("editor").contains(document.activeElement)) return;
  editor.focus();
});

// Layout -----------------------------------------------------------------

$("evaluate").addEventListener("click", evaluate);
$("debug").addEventListener("click", debug);
for (const button of $("mode").querySelectorAll("button")) {
  button.addEventListener("click", () => send({ t: "mode", mode: button.dataset.mode }));
}
$("stop").addEventListener("click", () => send({ t: "interrupt" }));
$("restart").addEventListener("click", () => send({ t: "restart" }));
for (const button of $("held").querySelectorAll("button")) {
  button.addEventListener("click", () => command(button.dataset.command));
}
$("bp-badge").addEventListener("click", () => showTab("breakpoints"));

$("divider").addEventListener("pointerdown", (event) => {
  const divider = event.currentTarget;
  divider.setPointerCapture(event.pointerId);
  const top = $("editor").getBoundingClientRect().top;
  const move = (e) => document.documentElement.style.setProperty(
    "--editor-height", `${Math.max(80, e.clientY - top)}px`);
  divider.addEventListener("pointermove", move);
  divider.addEventListener("pointerup", () => divider.removeEventListener("pointermove", move), { once: true });
});

connect();
