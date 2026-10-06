// The agent in the drawer: the Ask tab (threads, each a claude session the
// author converses with) and the Review tab (what the agents propose, held
// until the author accepts). Fed by `review` and `agent` events.

const node = (tag, className, text) => {
  const element = document.createElement(tag);
  if (className) element.className = className;
  if (text !== undefined) element.textContent = text;
  return element;
};

export function initAgent({ send, onPending }) {
  const state = {
    view: { threads: [], changesets: [], ops: [] },
    open: null,          // the thread shown, or null for the inbox
    live: new Map(),     // thread -> { phase, draft, extra: [messages since the last view] }
    unavailable: null,
  };
  const ask = document.getElementById("ask-tab");
  const review = document.getElementById("review-tab");

  // ---- Ask --------------------------------------------------------------

  const head = ask.appendChild(node("div", "thread-head"));
  const list = ask.appendChild(node("div", "threads"));
  const composer = ask.appendChild(node("form", "composer"));
  const input = composer.appendChild(node("textarea"));
  input.rows = 3;
  input.placeholder = "Ask for a change — dictate freely. Enter sends, Shift+Enter for a new line.";
  const row = composer.appendChild(node("div", "composer-row"));
  const where = row.appendChild(node("span", "where"));
  const submit = row.appendChild(node("button", "primary small", "Send"));
  submit.type = "submit";

  composer.addEventListener("submit", (event) => {
    event.preventDefault();
    const message = input.value.trim();
    if (!message) return;
    send({ t: "ask", thread: state.open, message });
    input.value = "";
  });
  input.addEventListener("keydown", (event) => {
    if (event.key === "Enter" && !event.shiftKey) {
      event.preventDefault();
      composer.requestSubmit();
    }
  });

  function live(thread) {
    if (!state.live.has(thread)) state.live.set(thread, { phase: "", draft: "", extra: [] });
    return state.live.get(thread);
  }

  function renderAsk() {
    head.replaceChildren();
    list.replaceChildren();
    const thread = state.view.threads.find((t) => t.id === state.open);
    if (state.unavailable) {
      list.append(node("p", "hint", state.unavailable));
    }
    if (thread) {
      const back = head.appendChild(node("button", "icon small", "‹ all threads"));
      back.addEventListener("click", () => { state.open = null; renderAsk(); });
      head.append(node("span", "thread-title", thread.title));
      if (thread.running) {
        const stop = head.appendChild(node("button", "danger small", "Stop"));
        stop.addEventListener("click", () => send({ t: "stop-thread", thread: thread.id }));
      }
      renderTranscript(thread);
      where.textContent = thread.running ? "working…" : `follow up in “${thread.title}”`;
      submit.disabled = thread.running;
    } else {
      head.append(node("span", "thread-title", "Threads"));
      if (!state.view.threads.length && !state.unavailable) {
        list.append(node("p", "hint",
          "Ask for something to build — a data type, a rule, an evaluator. Each request is a thread; " +
          "its changes arrive in Review for you to accept."));
      }
      for (const t of [...state.view.threads].reverse()) {
        const item = list.appendChild(node("button", "thread-item"));
        item.append(node("span", "thread-title", t.title));
        const pending = pendingOf(t.id);
        if (pending) item.append(node("span", "count", `${pending}`));
        const status = live(t.id).phase;
        item.append(node("span", `thread-status${t.running ? " running" : ""}`,
          t.running ? status || "working…" : lastWords(t)));
        item.addEventListener("click", () => { state.open = t.id; renderAsk(); });
      }
      where.textContent = "new thread";
      submit.disabled = false;
    }
  }

  function renderTranscript(thread) {
    const { phase, draft, extra } = live(thread.id);
    for (const message of [...thread.messages, ...extra]) {
      list.append(node("div", `message ${message.role}`, message.text));
    }
    if (thread.running && draft) list.append(node("div", "message assistant draft", draft));
    if (thread.running) list.append(node("div", "phase", phase || "working…"));
    list.scrollTop = list.scrollHeight;
  }

  function lastWords(thread) {
    const last = [...thread.messages].reverse().find((m) => m.role === "assistant" || m.role === "error");
    return last ? last.text.split("\n")[0] : "";
  }

  // ---- Review -----------------------------------------------------------

  function pendingOf(thread) {
    return state.view.ops.filter((op) => op.thread === thread && op.status === "pending").length;
  }

  function renderReview() {
    review.replaceChildren();
    const ops = state.view.ops;
    if (!ops.length) {
      review.append(node("p", "hint", "Nothing proposed yet. What the agent proposes appears here for you to accept or reject."));
    }
    for (const changeset of [...state.view.changesets].reverse()) {
      const mine = ops.filter((op) => op.changeset === changeset.id);
      if (!mine.length) continue;
      const section = review.appendChild(node("section", "changeset"));
      const top = section.appendChild(node("div", "changeset-head"));
      top.append(node("span", "changeset-title", changeset.title));
      const pending = mine.filter((op) => op.status === "pending" && !op.stale && !op.conflicts.length);
      if (pending.length > 1) {
        const all = top.appendChild(node("button", "primary small", `Accept all ${pending.length}`));
        all.addEventListener("click", () => send({ t: "accept-changeset", changeset: changeset.id }));
      }
      for (const op of mine) section.append(renderOp(op));
    }
  }

  function renderOp(op) {
    const card = node("div", `op ${op.status}`);
    const top = card.appendChild(node("div", "op-head"));
    top.append(node("span", "op-kind", op.kind === "append" ? "add forms" : "edit"));
    top.append(node("span", "op-id", `#${op.id}`));
    const flag = op.status !== "pending" ? op.status
      : op.conflicts.length ? `conflicts with ${op.conflicts.map((id) => `#${id}`).join(", ")}`
      : op.stale ? "no longer applies" : "";
    if (flag) top.append(node("span", `op-flag ${op.status === "pending" ? "warn" : op.status}`, flag));
    if (op.note) card.append(node("div", "op-note", op.note));
    card.append(renderDiff(op.kind === "append" ? "" : op.old, op.kind === "append" ? op.source : op.new));
    if (op.status === "pending") {
      const actions = card.appendChild(node("div", "op-actions"));
      const accept = actions.appendChild(node("button", "primary small", "Accept"));
      accept.disabled = op.stale || op.conflicts.length > 0;
      accept.addEventListener("click", () => send({ t: "accept", op: op.id }));
      const reject = actions.appendChild(node("button", "secondary small", "Reject"));
      reject.addEventListener("click", () => send({ t: "reject", op: op.id }));
    }
    return card;
  }

  return {
    snapshot({ review: view, agent_unavailable }) {
      state.view = view;
      state.unavailable = agent_unavailable;
      renderAsk();
      renderReview();
      onPending(view.ops.filter((op) => op.status === "pending").length);
    },
    review(view) {
      state.view = view;
      // the view's transcripts now hold what streamed in
      for (const thread of view.threads) live(thread.id).extra = [];
      renderAsk();
      renderReview();
      onPending(view.ops.filter((op) => op.status === "pending").length);
    },
    asked({ thread }) {
      state.open = thread;
      renderAsk();
    },
    agent({ thread, kind, text }) {
      const entry = live(thread);
      if (kind === "phase") entry.phase = text;
      else if (kind === "delta") entry.draft += text;
      else if (kind === "text" || kind === "tool" || kind === "error") {
        entry.extra.push({ role: kind === "text" ? "assistant" : kind, text });
        entry.draft = "";
      } else if (kind === "start") { entry.phase = "starting…"; entry.draft = ""; }
      else if (kind === "done") entry.phase = "";
      renderAsk();
    },
  };
}

// A line diff of two texts: the longest common subsequence of lines, with
// removed lines marked `-` and added ones `+`. Proposals are form-sized,
// so the quadratic table stays small.
function renderDiff(before, after) {
  const a = before ? before.split("\n") : [];
  const b = after.split("\n");
  const lengths = Array.from({ length: a.length + 1 }, () => new Array(b.length + 1).fill(0));
  for (let i = a.length - 1; i >= 0; i--) {
    for (let j = b.length - 1; j >= 0; j--) {
      lengths[i][j] = a[i] === b[j] ? lengths[i + 1][j + 1] + 1 : Math.max(lengths[i + 1][j], lengths[i][j + 1]);
    }
  }
  const out = node("pre", "diff");
  const line = (className, prefix, text) => out.append(node("div", className, `${prefix} ${text}`));
  let i = 0;
  let j = 0;
  while (i < a.length || j < b.length) {
    if (i < a.length && j < b.length && a[i] === b[j]) { line("same", " ", a[i]); i++; j++; }
    else if (j < b.length && (i === a.length || lengths[i][j + 1] >= lengths[i + 1][j])) { line("add", "+", b[j]); j++; }
    else { line("del", "-", a[i]); i++; }
  }
  return out;
}
