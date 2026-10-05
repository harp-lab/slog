// Slog Studio in the browser: the program editor, the REPL transcript and
// prompt, and the status strip, all fed by one WebSocket to the studio.

import { createEditor } from "./editor.js";
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
};

let socket = null;
const send = (message) => {
  if (socket?.readyState === WebSocket.OPEN) socket.send(JSON.stringify(message));
};

const editor = await createEditor($("editor"), {
  onChange: scheduleEdit,
  onEvaluate: evaluate,
  onSave: save,
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

// Messages from the studio -------------------------------------------------

const receive = {
  init(snapshot) {
    state.file = snapshot.file;
    state.version = snapshot.version;
    state.savedVersion = snapshot.saved ? snapshot.version : -1;
    state.lane = snapshot.lane;
    state.session = snapshot.session;
    $("file").textContent = snapshot.file;
    document.title = `${snapshot.file.split("/").pop()} — Slog Studio`;
    editor.set(snapshot.text);
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
    else note(ok ? `evaluated in ${(ms / 1000).toFixed(1)} s` : "evaluation failed", "evaluation");
    renderStatus();
  },
  notice({ message }) {
    note(message);
  },
};

function connect() {
  socket = new WebSocket(`ws://${location.host}/ws?token=${encodeURIComponent(token)}`);
  socket.onopen = renderStatus;
  socket.onmessage = (message) => {
    const data = JSON.parse(message.data);
    receive[data.t]?.(data);
  };
  socket.onclose = () => {
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
  $("saved").textContent = dirty ? "unsaved" : "saved";
}

function renderStatus() {
  const online = socket?.readyState === WebSocket.OPEN;
  const connection = $("connection");
  connection.textContent = online ? "connected" : "reconnecting…";
  connection.className = `dot ${online ? "ok" : "bad"}`;

  const { state: lane, detail, starts } = state.lane;
  const laneNode = $("lane");
  const restarts = starts > 1 ? ` · restarted ${starts - 1}×` : "";
  laneNode.textContent = `session server ${lane}${restarts}${detail ? ` — ${detail}` : ""}`;
  laneNode.className = `dot ${{ ready: "ok", idle: "ok", busy: "busy", starting: "busy" }[lane] ?? "bad"}`;

  const { current, held } = state.session;
  const sessionNode = $("session");
  sessionNode.textContent = held ? `${current ?? "session"} · run held — continue, commit, or abort`
    : current ? `database ${current}` : "no session";
  sessionNode.className = held ? "held" : "";

  $("evaluation").textContent = state.evaluating ? "evaluating…" : "";
  $("stop").hidden = lane !== "busy";
  $("evaluate").disabled = state.evaluating;
}

// Layout -----------------------------------------------------------------

$("evaluate").addEventListener("click", evaluate);
$("stop").addEventListener("click", () => send({ t: "interrupt" }));
$("restart").addEventListener("click", () => send({ t: "restart" }));

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
