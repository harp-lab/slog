// Slog Studio in the browser: the project's files and editor, the REPL
// transcript and prompt, and the status strip, all fed by one WebSocket to
// the studio.

import { createEditor } from "./editor.js";
import { createFiles } from "./files.js";
import { formAt, forms } from "./forms.js";
import { initAgent } from "./agent.js";
import { createHistory } from "./history.js";
import { renderEntry } from "./render.js";
import { createSummary } from "./summary.js";
import * as structure from "./paredit.js";

const $ = (id) => document.getElementById(id);
// Local mode's launch token; a server's login rides in a cookie instead.
const token = location.hash.slice(1);
// The project the page was opened on (`/?project=NAME`); none is the default.
const project = new URLSearchParams(location.search).get("project") ?? "";

const state = {
  lane: { state: "idle", detail: "", starts: 0 },
  session: { current: null, held: false },
  evaluating: false,
  log: null, // the <pre> collecting consecutive server output lines
  heldTitle: "", // where the held run stopped, from its pause result
  scenarios: new Map(), // name -> { running, report, error }
};

let socket = null;
const transmit = (message) => {
  if (socket?.readyState === WebSocket.OPEN) socket.send(JSON.stringify(message));
};

const editor = await createEditor($("editor"), {
  onChange: () => files.changed(),
  onEvaluate: evaluate,
  onSave: save,
  onBreakpoints: (lines) => files.setBreakpoints(lines),
  // A break names the line of a rule's `rule` keyword, which is where the
  // compiler locates it; a click anywhere in the rule marks that line.
  snapBreakpoint: (line) => {
    const form = formAt(forms(editor.get()), line);
    return form?.keyword === "rule" ? form.line : null;
  },
  keysAt: (line) => {
    const form = formAt(forms(editor.get()), line);
    const keys = ["⌘↵ run", "⌘S save"];
    if (form?.keyword === "rule") {
      keys.push(editor.breakpoints().includes(form.line) ? "Debug stops here" : "click the margin to break here");
    }
    keys.push(structure.keysAt(editor.get(), line)); // paredit and completion
    return keys.join(" · ");
  },
});

const summary = createSummary($("summary"), {
  editor,
  current: () => files.mainState(),
});
const files = createFiles({
  editor,
  transmit,
  note,
  onOpen() {
    // The summary's notes and findings belong on the main file.
    summary.show();
    versions.opened();
  },
  onSaved: () => summary.refresh(),
});
// Every message goes behind the edits already made, so it sees them.
const send = files.send;
const versions = createHistory({ send, files });

function save() {
  files.flush();
  send({ t: "save" });
}

function evaluate() {
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
    agent.snapshot(snapshot);
    summary.show(snapshot.summary);
    history.load();
    renderStatus();
  },
  lane(status) {
    state.lane = status;
    renderStatus();
  },
  session(view) {
    state.session = view;
    renderStatus();
  },
  log({ line }) {
    if (!state.log) state.log = append(document.createElement("pre"), "log");
    state.log.textContent += (state.log.textContent ? "\n" : "") + line;
    scrollTranscript();
  },
  entry(entry) {
    state.log = null;
    structure.observe(entry.result); // completion's catalog, breaks, watches
    if (entry.result?.kind === "paused") {
      state.heldTitle = entry.result.title;
      renderStatus();
    }
    append(renderEntry(entry, {
      inProject: (span) => files.pathOf(span.file) !== null,
      onSpan: (span) => files.reveal(span),
    }));
    const span = entry.error?.span;
    if (entry.origin === "evaluate" && span) {
      files.mark(span, entry.error.message);
      files.reveal(span);
    }
  },
  evaluation({ phase, ok, ms }) {
    state.evaluating = phase === "start";
    if (phase === "start") editor.mark(null);
    else note(ok ? `✓ ran in ${(ms / 1000).toFixed(1)} s` : "✗ run failed", ok ? "evaluation" : "evaluation failed");
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
};

// Consecutive connection attempts that never opened. A refused handshake
// (a link from another launch's token) and a stopped server look the same
// from here, so after a few the status says which to check.
let failedAttempts = 0;

function connect() {
  const scheme = location.protocol === "https:" ? "wss" : "ws";
  const query = `token=${encodeURIComponent(token)}&project=${encodeURIComponent(project)}`;
  socket = new WebSocket(`${scheme}://${location.host}/ws?${query}`);
  socket.onopen = () => {
    failedAttempts = 0;
    renderStatus();
  };
  socket.onmessage = (message) => {
    const data = JSON.parse(message.data);
    for (const handlers of [files.receive, receive, versions.receive]) handlers[data.t]?.(data);
  };
  socket.onclose = () => {
    failedAttempts += 1;
    renderStatus();
    setTimeout(connect, 1000);
  };
}

// The REPL prompt --------------------------------------------------------

const prompt = $("prompt");
// Structured editing and completion, ahead of the prompt's own keys; the
// rules `break` can name are those of the file shown.
structure.bindPrompt(prompt, { program: () => ({ file: files.active() ?? "", text: editor.get() }) });
prompt.addEventListener("focus", () => send({ t: "databases" }));
structure.mountControls(document.querySelector("header .controls"));
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

function renderStatus() {
  const online = socket?.readyState === WebSocket.OPEN;
  pill("connection",
    online ? "connected"
      : failedAttempts >= 3 ? ($("account")
        ? "not connected — is the studio running? If your login ended, reload to log in again"
        : "not connected — is the studio running? A link from an earlier launch needs the address it printed")
      : "reconnecting…",
    online ? "ok" : "bad");

  const { state: lane, detail, starts, mode } = state.lane;
  const restarts = starts > 1 ? ` · restarted ${starts - 1}×` : "";
  const laneDot = { ready: "ok", idle: "ok", busy: "busy", starting: "busy" }[lane] ?? "bad";
  pill("lane", `session server ${lane}${restarts}${detail ? ` — ${detail}` : ""}`, laneDot);

  const { current, held } = state.session;
  pill("session",
    held ? "run held" : current ? `database ${current}` : "no session",
    null, held ? "held" : "");
  pill("evaluation", state.evaluating ? "running…" : "", state.evaluating ? "busy" : null);

  $("held").hidden = !held;
  $("held-title").textContent = `run held — ${state.heldTitle || "paused"}`;
  for (const button of $("mode").querySelectorAll("button")) {
    button.setAttribute("aria-checked", String(button.dataset.mode === mode));
  }
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

// The drawer shows one tab; its header button toggles it.
function showTab(tab) {
  const drawer = $("drawer");
  const open = !(drawer.hidden === false && drawer.dataset.tab === tab);
  drawer.hidden = !open;
  drawer.dataset.tab = tab;
  for (const pane of drawer.querySelectorAll(".tab")) pane.hidden = pane.dataset.tab !== tab;
  for (const button of document.querySelectorAll(".panel-toggle")) {
    button.setAttribute("aria-pressed", String(open && button.dataset.tab === tab));
  }
  if (open && tab === "scenarios") send({ t: "scenarios" });
  if (open && tab === "history") versions.render();
}
for (const button of document.querySelectorAll(".panel-toggle")) {
  button.addEventListener("click", () => showTab(button.dataset.tab));
}

const agent = initAgent({
  send,
  onPending(count) {
    $("pending").hidden = count === 0;
    $("pending").textContent = String(count);
  },
});

// Hints (key bindings, placeholders, empty-panel notes, the summary's note
// for the form at the cursor) show only while Alt+H is held. A tap locks
// them on, like caps lock, and the next tap releases them.
const TAP_MS = 300;
const hints = { locked: false, held: null };  // held: when the press began
function renderHints() {
  const on = hints.locked || hints.held !== null;
  document.body.classList.toggle("hints", on);
  editor.hints(on);
  $("hints").textContent = hints.locked ? "hints locked · Alt+H" : "Alt+H for hints";
}
function release() {
  if (hints.held === null) return;
  if (performance.now() - hints.held < TAP_MS) hints.locked = true;
  hints.held = null;
  renderHints();
}
// `code`, not `key`: on a Mac, Option+H types a character.
const isHintKey = (event) => event.altKey && !event.ctrlKey && !event.metaKey && event.code === "KeyH";
addEventListener("keydown", (event) => {
  if (!isHintKey(event)) return;
  event.preventDefault();
  event.stopPropagation();
  if (event.repeat) return;
  if (hints.locked) hints.locked = false;
  else hints.held = performance.now();
  renderHints();
}, true);
addEventListener("keyup", (event) => {
  if (event.code === "KeyH" || event.key === "Alt") release();
}, true);
addEventListener("blur", () => { hints.held = null; renderHints(); });
$("hints").addEventListener("click", () => { hints.locked = !hints.locked; renderHints(); });
renderHints();

// Layout -----------------------------------------------------------------

$("evaluate").addEventListener("click", evaluate);
$("debug").addEventListener("click", debug);
$("stop").addEventListener("click", () => send({ t: "interrupt" }));
$("restart").addEventListener("click", () => send({ t: "restart" }));
for (const button of $("mode").querySelectorAll("button")) {
  button.addEventListener("click", () => send({ t: "mode", mode: button.dataset.mode }));
}
for (const button of $("held").querySelectorAll("button")) {
  button.addEventListener("click", () => send({ t: "command", line: button.dataset.command }));
}

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
