// The agent in the drawer: the Ask tab, threads, each a claude session the
// author converses with. Fed by `review` and `agent` events; a thread's
// transcript is drawn by thread.js, and what the agents propose is reviewed
// in the editor (proposals.js), a turn's proposals showing here as a chip.

import { markdown } from "./markdown.js";
import { activity, ago, duration, node, transcript } from "./thread.js";

export function initAgent({ send, onPending, proposals }) {
  const state = {
    view: { threads: [], changesets: [], ops: [] },
    open: null,          // the thread shown, or null for the inbox
    // thread -> { phase, draft, thinking: { text } | null, queue: [messages] }
    live: new Map(),
    expanded: new Map(), // "thread:index" or "thread:gindex" -> open
    unavailable: null,
  };
  const ask = document.getElementById("ask-tab");

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
        proposals: proposals.chip,
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
          "its changes show in the editor for you to accept or reject."));
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
      count.title = `${pending} proposal${pending === 1 ? "" : "s"} waiting in the editor`;
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

  function pendingOf(thread) {
    return state.view.ops.filter((op) => op.thread === thread && op.status === "pending").length;
  }

  function changed(view) {
    state.view = view;
    proposals.update(view);
    renderAsk();
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
