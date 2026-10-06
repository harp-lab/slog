// Slog Studio in the browser: the program editor, the REPL transcript and
// prompt, and the status strip, all fed by one WebSocket to the studio.

import { createEditor } from "./editor.js";
import { formAt, forms } from "./forms.js";
import { initAgent } from "./agent.js";
import { renderEntry } from "./render.js";

const $ = (id) => document.getElementById(id);
const token = location.hash.slice(1);

const state = {
  file: "",
  // The version the studio will hold once every edit sent so far is applied.
  // The server applies messages in order, so an edit or an evaluate sent
  // after an edit always sees it.
  version: 0,
  savedVersion: 0,
  editTimer: null,
  lane: { state: "idle", detail: "", starts: 0 },
  session: { current: null, held: false },
  evaluating: false,
  log: null, // the <pre> collecting consecutive server output lines
  heldTitle: "", // where the held run stopped, from its pause result
  scenarios: new Map(), // name -> { running, report, error }
};

let socket = null;
const send = (message) => {
  if (socket?.readyState === WebSocket.OPEN) socket.send(JSON.stringify(message));
};

const editor = await createEditor($("editor"), {
  onChange: scheduleEdit,
  onEvaluate: evaluate,
  onSave: save,
  onBreakpoints: (lines) => send({ t: "breakpoints", lines }),
  // A break names the line of a rule's `rule` keyword, which is where the
  // compiler locates it; a click anywhere in the rule marks that line.
  snapBreakpoint: (line) => {
    const form = formAt(forms(editor.get()), line);
    return form?.keyword === "rule" ? form.line : null;
  },
});

// Edits ------------------------------------------------------------------

function scheduleEdit() {
  clearTimeout(state.editTimer);
  state.editTimer = setTimeout(flushEdit, 150);
  renderSaved();
}

function flushEdit() {
  if (state.editTimer === null) return;
  clearTimeout(state.editTimer);
  state.editTimer = null;
  send({ t: "edit", base: state.version, text: editor.get() });
  state.version += 1;
}

function save() {
  flushEdit();
  send({ t: "save" });
}

function evaluate() {
  flushEdit();
  send({ t: "evaluate" });
}

function debug() {
  flushEdit();
  send({ t: "debug" });
}

// Messages from the studio -------------------------------------------------

const receive = {
  init(snapshot) {
    state.file = snapshot.file;
    state.version = snapshot.version;
    state.savedVersion = snapshot.saved ? snapshot.version : -1;
    state.lane = snapshot.lane;
    state.session = snapshot.session;
    $("file").textContent = snapshot.file.split("/").pop();
    $("file").title = snapshot.file;
    document.title = `${snapshot.file.split("/").pop()} — Slog Studio`;
    editor.set(snapshot.text);
    editor.setBreakpoints(snapshot.breakpoints);
    agent.snapshot(snapshot);
    history.load();
    renderSaved();
    renderStatus();
  },
  ack() {},
  // Our edit lost a race with another tab; theirs stands.
  reset({ version, text }) {
    state.version = version;
    editor.set(text);
    note("another tab changed the program; showing its version");
    renderSaved();
  },
  text({ version, text }) {
    state.version = version;
    editor.set(text);
    renderSaved();
  },
  breakpoints({ lines }) {
    editor.setBreakpoints(lines);
  },
  saved({ version }) {
    state.savedVersion = version;
    renderSaved();
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
    if (entry.result?.kind === "paused") {
      state.heldTitle = entry.result.title;
      renderStatus();
    }
    append(renderEntry(entry, { file: state.file, onSpan: (span) => editor.reveal(span) }));
    if (entry.origin === "evaluate") {
      const span = entry.error?.span;
      if (span && span.file === state.file) {
        editor.mark(span, entry.error.message);
        editor.reveal(span);
      }
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
  scenarios({ names }) {
    const known = state.scenarios;
    state.scenarios = new Map(names.map((name) => [name, known.get(name) ?? {}]));
    renderScenarios();
  },
  scenario({ name, running, report, error }) {
    state.scenarios.set(name, { running, report, error });
    renderScenarios();
  },
};

// Consecutive connection attempts that never opened. A refused handshake
// (a link from another launch's token) and a stopped server look the same
// from here, so after a few the status says which to check.
let failedAttempts = 0;

function connect() {
  socket = new WebSocket(`ws://${location.host}/ws?token=${encodeURIComponent(token)}`);
  socket.onopen = () => {
    failedAttempts = 0;
    renderStatus();
  };
  socket.onmessage = (message) => {
    const data = JSON.parse(message.data);
    receive[data.t]?.(data);
  };
  socket.onclose = () => {
    failedAttempts += 1;
    renderStatus();
    setTimeout(connect, 1000);
  };
}

// The REPL prompt --------------------------------------------------------

const prompt = $("prompt");
const historyKey = () => `slog-studio.history:${state.file}`;
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
  } else if (event.key === "ArrowUp" && !text.slice(0, prompt.selectionStart).includes("\n")) {
    if (history.index === 0) return;
    event.preventDefault();
    prompt.value = history.lines[--history.index];
    fitPrompt();
  } else if (event.key === "ArrowDown" && !text.slice(prompt.selectionEnd).includes("\n")) {
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

function renderSaved() {
  const dirty = state.editTimer !== null || state.savedVersion !== state.version;
  const badge = $("saved");
  badge.textContent = dirty ? "unsaved" : "saved";
  badge.className = `badge${dirty ? " dirty" : ""}`;
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
      : failedAttempts >= 3 ? "not connected — is the studio running? A link from an earlier launch needs the address it printed"
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
