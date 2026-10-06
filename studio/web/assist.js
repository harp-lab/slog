// The REPL's assistant (studio/src/assist.rs) and query crafting at the
// prompt.
//
// Ask mode: `??` at the start of the prompt, or Tab on an empty one, turns
// the prompt into a question for the assistant; Esc turns it back. Answers
// stream into the transcript, where the commands they suggest (```repl
// blocks) become chips to run or to insert into the prompt for editing,
// and a plan of steps (```plan) a checklist. A query the assistant tried
// shows what it found. Each question is a thread, so questions asked
// before leaving ask mode follow up on it; the Ask drawer lists them too.
//
// Every transcript entry offers "explain" and "next?", and an error "Ask
// why", each opening ask mode about that entry.
//
// What the assistant changes in the program it proposes, as the Ask agent
// does: its answer carries the proposal's chip (view, accept). Slog it only
// shows -- a ```slog block, a definition in a ```repl block -- is
// statically checked against the program first: a definition becomes
// runnable only once it checks, and either shows why it does not.
//
// Live preview: while a `?` query being typed is complete, the studio runs
// it aside (no entry, no result set) and its total and first rows show
// above the prompt.
//
// The hooks, from main.js:
//   initAssist({ prompt, transcript, send, openThread, showTranscript,
//                proposalChip, check }) -> { receive, entry }
//   proposalChip(ids)  the chip for proposals (proposals.js)
//   check(payload)     a static check's report (check.js `request`)
//   receive    the studio's messages: agent, assisted, preview, session
//   entry(entry, node)   a REPL entry just shown, and its node

import { markdown } from "./markdown.js";
import { observe } from "./commands.js";

// ---- Pure logic (tested in web/test/assist.test.js) -------------------------

// The question, when `text` asks for ask mode: `??` and what follows.
export function asking(text) {
  const match = text.match(/^\s*\?\?\s?([\s\S]*)$/);
  return match ? match[1] : null;
}

// Brackets outside strings and `;;` comments all close.
export function balanced(text) {
  let depth = 0;
  for (let i = 0; i < text.length; i++) {
    const c = text[i];
    if (c === "\"") {
      for (i++; i < text.length && text[i] !== "\""; i++) if (text[i] === "\\") i++;
      if (i >= text.length) return false;
    } else if (c === ";" && text[i + 1] === ";") {
      while (i < text.length && text[i] !== "\n") i++;
    } else if ("([{".includes(c)) depth++;
    else if (")]}".includes(c) && --depth < 0) return false;
  }
  return depth === 0;
}

// Whether `text` is a query complete enough to preview: `?`, `?count` or
// `?exists`, at least one whole clause, every bracket closed, and not
// ending in a projection's arrow.
export function previewable(text) {
  const line = text.trim();
  return /^\?(count\b|exists\b)?\s*\(/.test(line) && /\)$/.test(line) && balanced(line) && !/->\s*$/.test(line);
}

// The `;;` comment ending a line, outside strings: [command, comment].
function comment(line) {
  for (let i = 0; i < line.length; i++) {
    if (line[i] === "\"") {
      for (i++; i < line.length && line[i] !== "\""; i++) if (line[i] === "\\") i++;
    } else if (line[i] === ";" && line[i + 1] === ";") {
      return [line.slice(0, i).trimEnd(), line.slice(i + 2).trim()];
    }
  }
  return [line.trimEnd(), ""];
}

// A ```repl block's commands: one a line, or several lines while brackets
// stay open or the lines after the first are indented, each with its `;;`
// note. [{ command, note }]
export function steps(text) {
  const out = [];
  let open = null;
  for (const raw of text.split("\n")) {
    const [command, note] = comment(raw);
    if (!open && out.length && /^\s+\S/.test(command)) open = out.pop();
    if (open) {
      open.command += `\n${command}`;
      if (note) open.note = [open.note, note].filter(Boolean).join(" ");
    } else if (command.trim()) {
      open = { command: command.trim(), note };
    } else {
      continue;
    }
    if (balanced(open.command)) {
      out.push(open);
      open = null;
    }
  }
  if (open) out.push(open);
  return out;
}

// A command as compared with another: `? (a X)` and `?(a  X)` are one.
export const normal = (command) => command.trim().replace(/\s+/g, " ").replace(/^\?\s+\(/, "?(");

// What the assistant's reads found, by normal command, from its `repl` tool
// calls: { total, rows, error } each.
export function reads(calls) {
  const found = new Map();
  for (const data of calls) {
    if (data?.name !== "repl" || typeof data.input?.line !== "string" || data.status === "running") continue;
    let read = {};
    if (data.status === "error") read = { error: data.result ?? "error" };
    else {
      try { read = JSON.parse(data.result ?? "{}"); } catch { read = {}; }
    }
    found.set(normal(data.input.line), read);
  }
  return found;
}

const number = (n) => n.toLocaleString("en-US");

// A total as words: "1,770 rows", "2,000+ rows", "no rows".
export function rows(total) {
  if (!total || total.kind === "unknown") return "";
  const n = total.n;
  if (n === 0) return "no rows";
  return `${number(n)}${total.kind === "at-least" ? "+" : ""} row${n === 1 && total.kind === "exact" ? "" : "s"}`;
}

// What a REPL entry said, briefly: { line, error?, output? } for the
// assistant's context.
export function summarize(entry) {
  const out = { line: entry.line };
  if (entry.error) return { ...out, error: entry.error.message };
  const result = entry.result ?? {};
  const lines = [];
  if (result.title) lines.push(result.title);
  if (Array.isArray(result.relations)) lines.push(`${result.relations.length} relations`);
  else lines.push(...(result["brief-lines"] ?? result.lines ?? []).slice(0, 8));
  const text = lines.join("\n");
  return text ? { ...out, output: text.length > 600 ? `${text.slice(0, 600)}…` : text } : out;
}

// ---- The prompt, the transcript and the preview -------------------------------

const element = (tag, className, text) => {
  const node = document.createElement(tag);
  if (className) node.className = className;
  if (text !== undefined) node.textContent = text;
  return node;
};

const RECENT = 8;          // REPL entries a question carries
const PREVIEW_MS = 350;    // typing pause before a preview runs
const PREVIEW_RETRIES = 30; // tries while the lane is busy

// A REPL line that defines Slog for the scratch layer (repl.rkt's
// scratch-definition-heads), as opposed to a command.
export const definition = (command) => /^(rule|table|struct|union|enum|lattice|demand|extern|def|let)\b/.test(command.trim());

// A failed check's errors, without their positions (they are positions in
// the program with the suggestion appended).
const reasons = (report) => report.diagnostics.filter((d) => d.severity === "error").map((d) => d.message).join("\n");

export function initAssist({ prompt, transcript, send, openThread, showTranscript, proposalChip, check }) {
  const row = prompt.closest(".prompt-row");
  const caret = row.querySelector(".caret");
  const slogPlaceholder = prompt.placeholder;
  const tag = row.appendChild(element("button", "assist-tag"));
  tag.type = "button";
  const preview = row.appendChild(element("div", "assist-preview"));
  preview.hidden = true;

  const state = {
    mode: "slog",
    thread: null,         // the thread a question follows up on
    focus: null,          // the entry a question is about
    recent: [],           // the latest REPL entries, summarized
    relations: [],        // the last `tables`
    breaks: [],
    watches: [],
    held: null,           // where a held run stopped
    pending: [],          // questions sent, their threads not yet named
    early: new Map(),     // thread -> agent events before its block was
    turns: new Map(),     // thread -> its running turn's block
    titles: new Map(),    // thread -> title
    asked: [],            // questions, for the arrows
    askedIndex: 0,
    seq: 0,               // the latest preview asked for
    previewing: null,     // its { line, tries }
    previewed: "",        // the line the preview shows
    timer: 0,
  };

  // ---- Modes ----------------------------------------------------------------

  function setMode(mode, { keepThread = false } = {}) {
    state.mode = mode;
    prompt.dataset.mode = mode === "ask" ? "ask" : "";
    row.classList.toggle("ask", mode === "ask");
    caret.textContent = mode === "ask" ? "✦" : "›";
    prompt.placeholder = mode === "ask"
      ? "Ask about this session: a query in words, an error, a bug to chase. Enter asks · Esc back to Slog"
      : slogPlaceholder;
    if (mode === "slog" && !keepThread) {
      state.thread = null;
      state.focus = null;
    }
    renderTag();
    hidePreview();
  }

  function renderTag() {
    tag.hidden = state.mode !== "ask";
    const about = state.focus ? `about › ${state.focus.line}` : "";
    const following = state.thread ? `follow-up: ${state.titles.get(state.thread) ?? "this thread"}` : "";
    tag.textContent = `${[following, about].filter(Boolean).join(" · ") || "new question"}${state.thread || state.focus ? " ×" : ""}`;
    tag.title = state.thread || state.focus ? "Ask a new question instead" : "Esc returns to Slog";
  }
  tag.addEventListener("click", () => {
    state.thread = null;
    state.focus = null;
    renderTag();
    prompt.focus();
  });

  // The prompt's text, sized to it (main.js's input listener).
  function setPrompt(text) {
    prompt.value = text;
    prompt.dispatchEvent(new Event("input"));
  }

  // Open ask mode, about `entry` when given, with `text` to send.
  function ask({ entry = null, text = "", thread = null } = {}) {
    setMode("ask");
    state.thread = thread;
    state.focus = entry ? summarize(entry) : null;
    renderTag();
    setPrompt(text);
    prompt.focus();
    prompt.setSelectionRange(0, text.length);
  }

  // `??` switches; the question is what follows it. (A capture listener,
  // so completion, which listens after it, sees ask mode.)
  prompt.addEventListener("input", () => {
    if (state.mode === "slog") {
      const question = asking(prompt.value);
      if (question !== null) {
        setMode("ask", { keepThread: true });
        prompt.value = question;
        return;
      }
      schedulePreview();
    }
  }, { capture: true });

  prompt.addEventListener("keydown", (event) => {
    if (event.isComposing) return;
    const empty = !prompt.value.trim();
    if (event.key === "Tab" && !event.shiftKey && empty && !event.ctrlKey && !event.altKey && !event.metaKey) {
      event.preventDefault();
      event.stopImmediatePropagation();
      setMode(state.mode === "ask" ? "slog" : "ask", { keepThread: true });
      return;
    }
    if (state.mode === "slog") {
      if (event.key === "Enter" || event.key === "Escape") hidePreview();
      return;
    }
    // ask mode: the prompt's Slog keys stand aside
    event.stopImmediatePropagation();
    if (event.key === "Escape") {
      event.preventDefault();
      setMode("slog");
    } else if (event.key === "Enter" && !event.shiftKey) {
      event.preventDefault();
      submit();
    } else if (event.key === "ArrowUp" && !prompt.value.slice(0, prompt.selectionStart).includes("\n") && state.askedIndex > 0) {
      event.preventDefault();
      setPrompt(state.asked[--state.askedIndex]);
    } else if (event.key === "ArrowDown" && !prompt.value.slice(prompt.selectionEnd).includes("\n") && state.askedIndex < state.asked.length) {
      event.preventDefault();
      setPrompt(state.asked[++state.askedIndex] ?? "");
    }
  }, { capture: true });
  prompt.addEventListener("blur", hidePreview);

  function submit() {
    const message = prompt.value.trim();
    if (!message) return;
    state.asked = [...state.asked.filter((asked) => asked !== message), message].slice(-100);
    state.askedIndex = state.asked.length;
    showTranscript();
    const block = turnBlock(message, state.thread !== null);
    state.pending.push({ message, block });
    send({ t: "assist", thread: state.thread, message, context: context() });
    state.focus = null;
    setPrompt("");
    renderTag();
  }

  function context() {
    return {
      recent: state.recent,
      relations: state.relations,
      breaks: state.breaks,
      watches: state.watches,
      held: state.held,
      focus: state.focus,
    };
  }

  // ---- Answers in the transcript ----------------------------------------------

  function turnBlock(message, following) {
    const block = element("div", `entry assist${following ? " follow" : ""}`);
    block.append(element("div", "line", message));
    const body = block.appendChild(element("div", "md assist-body"));
    const activity = block.appendChild(element("div", "assist-activity", "Asking…"));
    const foot = block.appendChild(element("div", "assist-foot"));
    const atBottom = transcript.scrollHeight - transcript.scrollTop - transcript.clientHeight < 40;
    transcript.append(block);
    if (atBottom) transcript.scrollTop = transcript.scrollHeight;
    return { block, body, activity, foot, texts: [], draft: "", calls: [], error: "", ms: 0, thread: null };
  }

  function bind(thread, turn) {
    turn.thread = thread;
    state.turns.set(thread, turn);
    const stop = turn.foot.appendChild(element("a", "", "Stop"));
    stop.addEventListener("click", () => send({ t: "stop-thread", thread }));
    for (const event of state.early.get(thread) ?? []) agentEvent(event);
    state.early.delete(thread);
  }

  function agentEvent(event) {
    const { thread, kind, text = "", entry } = event;
    const turn = state.turns.get(thread);
    if (!turn) {
      // a question's first events can outrun the reply naming its thread
      if (state.pending.length) state.early.set(thread, [...(state.early.get(thread) ?? []), event]);
      return;
    }
    if (kind === "delta") turn.draft += text;
    else if (kind === "phase") turn.activity.textContent = phase(text);
    else if (kind === "entry" && entry) {
      if (entry.role === "assistant") {
        turn.texts.push(entry.text);
        turn.draft = "";
      } else if (entry.role === "tool") {
        const at = turn.calls.findIndex((call) => call.id === entry.data?.id);
        if (at >= 0) turn.calls[at] = entry.data;
        else turn.calls.push(entry.data);
        if (entry.data?.status === "running") turn.activity.textContent = trying(entry.data);
      } else if (entry.role === "error") turn.error = entry.text;
      else if (entry.role === "turn") turn.ms = entry.data?.ms ?? 0;
    } else if (kind === "done") {
      state.turns.delete(thread);
      return finish(turn);
    } else return;
    renderTurn(turn, false);
  }

  const phase = (text) => text === "thinking" ? "Thinking…" : text === "replying" ? "Writing…"
    : text.startsWith("tool ") ? "Checking…" : "Working…";
  const trying = (data) => data.name === "repl" ? `Trying ${data.input?.line ?? ""}` : "Looking it up…";

  function renderTurn(turn, done) {
    const atBottom = transcript.scrollHeight - transcript.scrollTop - transcript.clientHeight < 40;
    // markdown() escapes all of the model's text
    turn.body.innerHTML = markdown([...turn.texts, turn.draft].filter(Boolean).join("\n\n"));
    if (done) chips(turn);
    if (atBottom) transcript.scrollTop = transcript.scrollHeight;
  }

  function finish(turn) {
    renderTurn(turn, true);
    turn.activity.remove();
    // its proposals, to view and accept where they land
    const proposed = turn.calls.filter((call) => call.op && call.status === "ok").map((call) => call.op);
    const proposal = proposed.length && proposalChip?.([...new Set(proposed)]);
    if (proposal) turn.body.append(proposal);
    if (turn.error) turn.body.append(element("div", "error", turn.error));
    turn.foot.replaceChildren();
    const tried = turn.calls.filter((call) => call.name === "repl").length;
    const parts = [tried ? `tried ${tried} command${tried === 1 ? "" : "s"}` : "", turn.ms ? `${(turn.ms / 1000).toFixed(1)} s` : ""];
    turn.foot.append(element("span", "", parts.filter(Boolean).join(" · ")));
    const follow = turn.foot.appendChild(element("a", "", "Follow up"));
    follow.addEventListener("click", () => ask({ thread: turn.thread }));
    const open = turn.foot.appendChild(element("a", "", "Open in Ask"));
    open.addEventListener("click", () => openThread(turn.thread));
  }

  // An answer's ```repl blocks as chips, and its ```plan blocks as
  // checklists of them; its ```slog blocks, checked.
  function chips(turn) {
    const found = reads(turn.calls);
    for (const block of turn.body.querySelectorAll(".code-block")) {
      const lang = block.querySelector(".code-lang")?.textContent;
      if (lang === "slog") checked(block, block.querySelector("pre").textContent);
      if (lang !== "repl" && lang !== "plan") continue;
      const list = steps(block.querySelector("pre").textContent);
      if (!list.length) continue;
      const plan = element("div", lang === "plan" ? "assist-plan" : "assist-chips");
      const head = lang === "plan" ? plan.appendChild(element("div", "assist-plan-head")) : null;
      const items = list.map((step) => plan.appendChild(chip(step, found.get(normal(step.command)), () => progress())));
      const next = head && element("a", "", "Run next");
      function progress() {
        if (!head) return;
        const done = items.filter((item) => item.classList.contains("done")).length;
        head.replaceChildren(element("span", "", `Plan · ${done}/${items.length}`));
        if (done < items.length) head.append(next);
      }
      next?.addEventListener("click", () => items.find((item) => !item.classList.contains("done"))?.run());
      progress();
      block.replaceWith(plan);
    }
  }

  function chip(step, read, ran) {
    const item = element("div", "assist-step");
    item.append(element("span", "mark"));
    const code = item.appendChild(element("code", "", step.command));
    code.title = "Insert into the prompt to edit";
    code.addEventListener("click", () => insert(step.command));
    const badge = read && (read.error ? "failed when tried" : rows(read.total) ? `≈ ${rows(read.total)}` : "tried");
    if (badge) {
      const span = item.appendChild(element("span", `badge${read.error ? " failed" : ""}`, badge));
      span.title = read.error ?? (read.rows?.length ? read.rows.join("\n") : "the assistant ran it");
    }
    const run = item.appendChild(element("button", "small primary", "Run"));
    run.title = "Run it now";
    // a definition runs once it checks against the program
    if (definition(step.command) && check) {
      run.disabled = true;
      run.title = "Checking it against the program…";
      check({ append: step.command }).then((report) => {
        const failed = !report.ok;
        const span = item.insertBefore(element("span", `badge${failed ? " failed" : ""}`, failed ? "does not check" : "✓ checks"), run);
        span.title = failed ? reasons(report) : "it passes the static check with the program";
        run.disabled = failed;
        run.title = failed ? `It does not check:\n${reasons(report)}` : "Run it now";
      });
    }
    const edit = item.appendChild(element("button", "small secondary", "Insert"));
    edit.title = "Put it in the prompt to edit";
    if (step.note) item.append(element("div", "note", step.note));
    item.run = () => {
      send({ t: "command", line: step.command });
      item.classList.add("done");
      ran();
    };
    run.addEventListener("click", item.run);
    edit.addEventListener("click", () => insert(step.command));
    return item;
  }

  // A ```slog block, with whether it checks added to the program.
  function checked(block, source) {
    if (!check || !source.trim()) return;
    const status = block.appendChild(element("div", "assist-checked", "checking…"));
    check({ append: source }).then((report) => {
      status.classList.toggle("failed", !report.ok);
      status.textContent = report.ok ? "✓ checks with the program" : `does not check: ${reasons(report)}`;
    });
  }

  // Into the prompt, in Slog mode: a follow-up question stays possible.
  function insert(command) {
    setMode("slog", { keepThread: true });
    setPrompt(command);
    prompt.focus();
    prompt.setSelectionRange(command.length, command.length);
  }

  // ---- Entries: what the session holds, and "explain" ----------------------

  function entry(entry, node) {
    const live = entry.result && observe(entry.result);
    if (live?.catalog) state.relations = live.catalog.map(({ name, detail, rows }) => ({ name, detail, rows }));
    if (live?.breaks) state.breaks = live.breaks.map(({ id, about }) => `${id} ${about}`);
    if (live?.watches) state.watches = live.watches.map(({ id, about }) => `${id} ${about}`);
    if (entry.result?.kind === "paused") state.held = entry.result.title;
    if (entry.origin !== "repl" && !entry.error) return;
    state.recent = [...state.recent, summarize(entry)].slice(-RECENT);
    const actions = node.appendChild(element("span", "assist-actions"));
    const offer = (label, text, title) => {
      const link = actions.appendChild(element("a", "", label));
      link.title = title;
      link.addEventListener("click", () => ask({ entry, text }));
    };
    if (entry.error) {
      const why = element("a", "assist-why", "Ask why");
      why.title = "Ask the assistant why this failed";
      why.addEventListener("click", () => ask({ entry, text: "Why did this fail, and what should I run instead?" }));
      node.querySelector(".error")?.append(why);
    } else {
      offer("✦ explain", "Explain this.", "Ask the assistant what this shows");
    }
    offer("✦ next?", "What could I run next?", "Ask the assistant what to try next");
  }

  // ---- Live preview ------------------------------------------------------------

  function schedulePreview() {
    clearTimeout(state.timer);
    const text = prompt.value;
    if (state.mode !== "slog" || state.held || !previewable(text)) return hidePreview();
    if (text.trim() === state.previewed && !preview.hidden) return;
    state.timer = setTimeout(() => requestPreview(text.trim(), 0), PREVIEW_MS);
  }

  function requestPreview(line, tries) {
    state.seq += 1;
    state.previewing = { line, tries };
    send({ t: "preview", line, seq: state.seq });
  }

  function hidePreview() {
    clearTimeout(state.timer);
    state.seq += 1; // answers on their way are stale
    state.previewed = "";
    preview.hidden = true;
  }

  function showPreview(reply) {
    if (reply.seq !== state.seq || state.mode !== "slog" || prompt.value.trim() !== state.previewing?.line) return;
    if (reply.busy) {
      const { line, tries } = state.previewing;
      if (tries < PREVIEW_RETRIES) state.timer = setTimeout(() => requestPreview(line, tries + 1), PREVIEW_MS);
      return;
    }
    state.previewed = state.previewing.line;
    preview.replaceChildren();
    preview.classList.toggle("failed", Boolean(reply.error));
    if (reply.error) {
      preview.append(element("div", "", reply.error));
    } else {
      preview.append(element("div", "total", rows(reply.total) || reply.title || "ran"));
      const tuples = reply.rows ?? [];
      for (const tuple of tuples.slice(0, 4)) preview.append(element("div", "row", tuple));
      if (tuples.length > 4 || (tuples.length && (reply.total?.n ?? 0) > tuples.length)) preview.append(element("div", "row more", "…"));
    }
    preview.hidden = false;
  }

  return {
    entry,
    receive: {
      agent: agentEvent,
      assisted({ thread, message, error }) {
        const at = state.pending.findIndex((pending) => pending.message === message);
        const [pending] = state.pending.splice(at >= 0 ? at : 0, 1);
        if (pending && error) {
          // refused: claude missing, or the thread still answering
          pending.block.activity.remove();
          pending.block.body.append(element("div", "error", error));
        } else if (pending) {
          state.titles.set(thread, state.titles.get(thread) ?? message.split("\n")[0].slice(0, 60));
          if (state.mode === "ask" && state.thread === null) state.thread = thread;
          renderTag();
          bind(thread, pending.block);
        }
        if (!state.pending.length) state.early.clear();
      },
      preview: showPreview,
      session({ held }) {
        if (!held) state.held = null;
      },
    },
  };
}
