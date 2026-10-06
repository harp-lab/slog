// The agent in the drawer: the Ask tab (threads, each a claude session the
// author converses with) and the Review tab (what the agents propose, held
// until the author accepts). Fed by `review` and `agent` events; a thread's
// transcript is drawn by thread.js.

import { markdown } from "./markdown.js";
import { activity, ago, duration, node, transcript } from "./thread.js";

export function initAgent({ send, onPending }) {
  const state = {
    view: { threads: [], changesets: [], ops: [] },
    open: null,          // the thread shown, or null for the inbox
    // thread -> { phase, draft, thinking: { text } | null, queue: [messages] }
    live: new Map(),
    expanded: new Map(), // "thread:index" or "thread:gindex" -> open
    unavailable: null,
  };
  const ask = document.getElementById("ask-tab");
  const review = document.getElementById("review-tab");

  // ---- Ask --------------------------------------------------------------

  const head = ask.appendChild(node("div", "thread-head"));
  const list = ask.appendChild(node("div", "threads"));
  const composer = ask.appendChild(node("form", "composer"));
  const input = composer.appendChild(node("textarea"));
  input.rows = 1;
  input.placeholder = "Ask for a change. Enter sends, Shift+Enter for a new line.";
  const row = composer.appendChild(node("div", "composer-row"));
  const where = row.appendChild(node("span", "where"));
  const settings = row.appendChild(node("span", "settings"));
  const submit = row.appendChild(node("button", "primary small", "Send"));
  submit.type = "submit";

  composer.addEventListener("submit", (event) => {
    event.preventDefault();
    const message = input.value.trim();
    if (!message) return;
    const thread = state.view.threads.find((t) => t.id === state.open);
    // a running thread takes the message when its turn is done
    if (thread?.running) live(thread.id).queue.push(message);
    else send({ t: "ask", thread: state.open, message });
    input.value = "";
    grow();
    renderAsk();
  });
  input.addEventListener("keydown", (event) => {
    if (event.key === "Enter" && !event.shiftKey) {
      event.preventDefault();
      composer.requestSubmit();
    }
  });
  // The prompt grows with what is typed, up to a third of the drawer.
  function grow() {
    input.style.height = "auto";
    input.style.height = `${Math.min(input.scrollHeight + 2, ask.clientHeight / 3)}px`;
  }
  input.addEventListener("input", grow);
  new ResizeObserver(grow).observe(ask);

  // Copying a code block from a reply.
  list.addEventListener("click", (event) => {
    const copy = event.target.closest("button.copy");
    if (!copy) return;
    navigator.clipboard?.writeText(copy.parentElement.querySelector("pre").textContent);
    copy.textContent = "Copied";
    setTimeout(() => { copy.textContent = "Copy"; }, 1200);
  });

  function live(thread) {
    if (!state.live.has(thread)) state.live.set(thread, { phase: "", draft: "", thinking: null, queue: [] });
    return state.live.get(thread);
  }

  const threadOf = (id) => state.view.threads.find((t) => t.id === id);

  function renderAsk() {
    const atBottom = list.scrollHeight - list.scrollTop - list.clientHeight < 48;
    const scroll = list.scrollTop;
    head.replaceChildren();
    list.replaceChildren();
    const thread = threadOf(state.open);
    if (state.unavailable) list.append(node("p", "notice", state.unavailable));
    if (thread) {
      const back = head.appendChild(node("button", "back small", "‹ Threads"));
      back.title = "All threads";
      back.addEventListener("click", () => { state.open = null; renderAsk(); });
      const title = head.appendChild(node("span", "thread-title", thread.title));
      title.title = thread.title;
      if (thread.running) {
        const stop = head.appendChild(node("button", "quiet small", "Stop"));
        stop.title = "Stop this turn";
        stop.addEventListener("click", () => send({ t: "stop-thread", thread: thread.id }));
      }
      list.append(...transcript(thread, {
        live: live(thread.id),
        opCard,
        open: state.expanded,
        now: Date.now(),
      }));
      for (const message of live(thread.id).queue) {
        const queued = list.appendChild(node("div", "msg user queued", message));
        queued.title = "Sent when this turn is done";
      }
      where.textContent = thread.running ? "queues a follow-up" : "follow-up";
      submit.textContent = thread.running ? "Queue" : "Send";
      submit.className = thread.running ? "secondary small" : "primary small";
      submit.title = thread.running ? "Send when this turn is done" : "";
      list.scrollTop = atBottom ? list.scrollHeight : scroll;
    } else {
      head.append(node("span", "thread-title", "Threads"));
      if (!state.view.threads.length && !state.unavailable) {
        list.append(node("p", "empty",
          "Ask for something to build — a data type, a rule, an evaluator. Each request starts a thread; " +
          "its changes arrive in Review for you to accept."));
      }
      const now = Date.now();
      for (const t of [...state.view.threads].sort((a, b) => lastAt(b) - lastAt(a))) list.append(threadItem(t, now));
      where.textContent = "new thread";
      submit.textContent = "Send";
      submit.className = "primary small";
      submit.title = "";
    }
    settings.textContent = lastSettings();
  }

  function threadItem(t, now) {
    const item = node("button", `thread-item${t.running ? " running" : ""}`);
    const title = item.appendChild(node("span", "thread-title", t.title));
    title.title = t.title;
    item.append(node("span", "when", ago(lastAt(t), now)));
    const status = item.appendChild(node("span", "thread-status"));
    if (t.running) status.append(node("span", "status running"), activity(t, live(t.id)));
    else status.textContent = lastWords(t);
    const pending = pendingOf(t.id);
    if (pending) {
      const count = item.appendChild(node("span", "count", `${pending}`));
      count.title = `${pending} proposal${pending === 1 ? "" : "s"} waiting in Review`;
    }
    item.addEventListener("click", () => { state.open = t.id; renderAsk(); });
    return item;
  }

  const lastAt = (thread) => thread.messages.at(-1)?.at ?? 0;

  function lastWords(thread) {
    const last = [...thread.messages].reverse().find((m) => m.role === "assistant" || m.role === "error");
    return last ? last.text.replace(/[#*`_>]/g, "").split("\n").find((line) => line.trim()) ?? "" : "";
  }

  // The model and effort of the latest turn, as its closing line names them.
  function lastSettings() {
    const turns = state.view.threads.flatMap((t) => t.messages).filter((m) => m.role === "turn");
    const latest = turns.sort((a, b) => a.at - b.at).at(-1)?.data ?? {};
    return [latest.model?.replace(/^claude-/, ""), latest.effort].filter(Boolean).join(" · ");
  }

  // Parts of the running thread that change between entries.
  function renderLive(thread) {
    if (thread !== state.open) return renderAsk();
    const entry = live(thread);
    const t = threadOf(thread);
    const line = list.querySelector(".running-line .activity");
    if (!t || !line) return renderAsk();
    const draft = list.querySelector(".msg.draft");
    const thinking = list.querySelector(".thought.live");
    // a new draft or thought needs its node made: redraw
    if ((entry.draft && !draft) || (entry.thinking && !thinking) || (!entry.thinking && thinking)) return renderAsk();
    const atBottom = list.scrollHeight - list.scrollTop - list.clientHeight < 48;
    // markdown() escapes all of the model's text
    if (draft) draft.innerHTML = markdown(entry.draft);
    const thought = thinking?.querySelector(".thought-text");
    if (thought) thought.innerHTML = markdown(entry.thinking.text);
    else if (entry.thinking?.text) return renderAsk();
    line.textContent = activity(t, entry);
    if (atBottom) list.scrollTop = list.scrollHeight;
  }

  // The elapsed time of a running turn, and the thread list's times.
  setInterval(() => {
    const t = threadOf(state.open);
    const elapsed = list.querySelector(".running-line .elapsed");
    if (t?.running && elapsed) {
      const start = [...t.messages].reverse().find((m) => m.role === "user")?.at ?? Date.now();
      elapsed.textContent = duration(Date.now() - start);
    }
  }, 1000);
  setInterval(() => { if (state.open === null) renderAsk(); }, 30000);

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

  // An op's card in the transcript of the thread that proposed it.
  function opCard(id) {
    const op = state.view.ops.find((op) => op.id === id);
    return op ? renderOp(op, true) : null;
  }

  function renderOp(op, inline = false) {
    const card = node("div", `op ${op.status}${inline ? " inline" : ""}`);
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

  function changed(view) {
    state.view = view;
    renderAsk();
    renderReview();
    onPending(view.ops.filter((op) => op.status === "pending").length);
  }

  return {
    snapshot({ review: view, agent_unavailable }) {
      state.unavailable = agent_unavailable;
      changed(view);
    },
    review: changed,
    asked({ thread }) {
      state.open = thread;
      renderAsk();
    },
    agent({ thread, kind, text = "", index, entry }) {
      const now = live(thread);
      if (kind === "start") Object.assign(now, { phase: "starting", draft: "", thinking: null });
      else if (kind === "phase") {
        now.phase = text;
        if (text === "thinking") now.thinking = { text: "" };
        else now.thinking = null;
      } else if (kind === "thinking" && now.thinking) now.thinking.text += text;
      else if (kind === "delta") now.draft += text;
      else if (kind === "entry") {
        const t = threadOf(thread);
        if (t) t.messages[index] = entry;
        if (entry.role === "assistant") now.draft = "";
        if (entry.role === "thinking") now.thinking = null;
        if (thread === state.open || state.open === null) renderAsk();
        return;
      } else if (kind === "done") {
        Object.assign(now, { phase: "", draft: "", thinking: null });
        // the follow-ups queued while it ran, as one message
        if (now.queue.length) send({ t: "ask", thread, message: now.queue.splice(0).join("\n\n") });
      }
      if (kind === "delta" || kind === "thinking") return renderLive(thread);
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
