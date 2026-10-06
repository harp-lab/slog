// One Ask thread's transcript, as the drawer shows it: the author's
// requests, the agent's replies (Markdown), its thoughts, its tool calls as
// quiet rows grouped when consecutive, its proposals as cards, its notes,
// its plan as a checklist, and each turn's closing line.
//
// Entries come from the server (`review.rs` Message); a running turn adds
// what is still streaming: the thought in progress, the reply's draft, and
// a line saying what the agent is doing.

import { markdown } from "./markdown.js";

export const node = (tag, className, text) => {
  const element = document.createElement(tag);
  if (className) element.className = className;
  if (text !== undefined) element.textContent = text;
  return element;
};

// Model text as HTML: markdown.js escapes all of it.
function prose(className, text) {
  const element = node("div", `md ${className}`);
  element.innerHTML = markdown(text);
  return element;
}

// ---- Tool calls as words --------------------------------------------------

// What a call did, past tense, and what it was about: { label, detail }.
export function describe(data) {
  const input = data.input ?? {};
  const name = data.name ?? "tool";
  const first = Object.values(input).find((value) => typeof value === "string") ?? "";
  switch (name) {
    case "get_program": return { label: "Read the program", detail: "" };
    case "propose_edit": return { label: `Proposed an edit${opId(data)}`, detail: input.note ?? "" };
    case "propose_append": return { label: `Proposed new forms${opId(data)}`, detail: input.note ?? "" };
    case "evaluate_proposal": return { label: "Evaluated the proposal", detail: evaluation(data) };
    case "query": return { label: "Queried", detail: input.q ?? "" };
    case "get_proposals": return { label: "Checked its proposals", detail: "" };
    case "get_notes": return { label: "Read the notes", detail: "" };
    case "Read": return { label: "Read", detail: shortPath(input.file_path) };
    case "Grep": return { label: "Searched code", detail: [input.pattern, shortPath(input.path)].filter(Boolean).join(" in ") };
    case "Glob": return { label: "Found files", detail: input.pattern ?? "" };
    case "WebSearch": return { label: "Searched the web", detail: input.query ?? "" };
    case "WebFetch": return { label: "Fetched", detail: (input.url ?? "").replace(/^https?:\/\/(www\.)?/, "") };
    case "Task": case "Agent": return { label: "Ran a subagent", detail: input.description ?? "" };
    default: return { label: humanize(name), detail: first };
  }
}

// What a call is doing, for the running line.
const ACTIVE = {
  get_program: "Reading the program", propose_edit: "Proposing an edit", propose_append: "Proposing new forms",
  evaluate_proposal: "Evaluating the proposal", query: "Querying", get_proposals: "Checking its proposals",
  record_note: "Recording a note", get_notes: "Reading the notes", Read: "Reading", Grep: "Searching code",
  Glob: "Finding files", WebSearch: "Searching the web", WebFetch: "Fetching", Task: "Running a subagent",
  Agent: "Running a subagent", TodoWrite: "Planning", TaskCreate: "Planning", TaskUpdate: "Planning",
};

const humanize = (name) => {
  const words = name.replace(/([a-z])([A-Z])/g, "$1 $2").replace(/_/g, " ").toLowerCase();
  return words.charAt(0).toUpperCase() + words.slice(1);
};
const opId = (data) => data.op ? ` #${data.op}` : "";

// The last few segments of a path: enough to know the file.
function shortPath(path) {
  if (!path) return "";
  const parts = path.split("/").filter(Boolean);
  return parts.length > 3 ? `…/${parts.slice(-3).join("/")}` : path;
}

function evaluation(data) {
  if (data.status === "error") return "failed";
  const report = evaluated(data);
  if (report?.ok === false) return `failed${report.line ? ` at line ${report.line}` : ""}: ${report.error ?? ""}`;
  if (Array.isArray(report?.relations)) return `${report.relations.length} relations`;
  return "";
}

// An evaluation's report, unless clipped or not JSON.
function evaluated(data) {
  try {
    return data.name === "evaluate_proposal" ? JSON.parse(data.result ?? "") : null;
  } catch {
    return null;
  }
}

// A call's status, counting an evaluation that failed as failed.
const statusOf = (data) => evaluated(data)?.ok === false ? "error" : data.status;

// What a running thread is doing now, in words.
export function activity(thread, live) {
  const phase = live.phase ?? "";
  if (phase === "thinking") return "Thinking";
  if (phase === "replying") return "Writing";
  const running = [...thread.messages].reverse().find((m) => m.role === "tool" && m.data?.status === "running");
  if (running) {
    const { detail } = describe(running.data);
    const verb = ACTIVE[running.data.name] ?? humanize(running.data.name ?? "working");
    return detail ? `${verb}: ${detail}` : verb;
  }
  if (phase.startsWith("tool ")) {
    const name = phase.slice(5);
    return ACTIVE[name] ?? humanize(name);
  }
  return phase === "starting" ? "Starting" : "Working";
}

// ---- Times and sizes ----------------------------------------------------------

export function duration(ms) {
  const s = Math.round(ms / 1000);
  return s < 60 ? `${s}s` : `${Math.floor(s / 60)}m ${String(s % 60).padStart(2, "0")}s`;
}

const tokens = (n) => n >= 1e6 ? `${(n / 1e6).toFixed(1)}M` : n >= 1e3 ? `${(n / 1e3).toFixed(1)}k` : `${n}`;

// "now", "5m", "3h", "Mon", "Oct 3": when something last happened.
export function ago(at, now) {
  const s = (now - at) / 1000;
  if (s < 60) return "now";
  if (s < 3600) return `${Math.floor(s / 60)}m`;
  if (s < 86400) return `${Math.floor(s / 3600)}h`;
  const date = new Date(at);
  if (s < 6 * 86400) return date.toLocaleDateString(undefined, { weekday: "short" });
  return date.toLocaleDateString(undefined, { month: "short", day: "numeric" });
}

// ---- The transcript ---------------------------------------------------------

const PLAN_MARK = { completed: "✓", in_progress: "›", pending: "" };
const SPECIAL = new Set(["propose_edit", "propose_append", "record_note"]);

// The transcript of `thread` as nodes. `ctx`: { live, opCard(id) -> node or
// null, open: Map key -> whether a row or group is expanded, now }.
export function transcript(thread, ctx) {
  const out = [];
  const turns = [];
  for (const [index, message] of thread.messages.entries()) {
    if (message.role === "user" || !turns.length) turns.push([]);
    turns[turns.length - 1].push({ index, message });
  }
  turns.forEach((entries, n) => {
    const last = n === turns.length - 1;
    out.push(turn(thread, entries, ctx, last && thread.running));
  });
  return out;
}

function turn(thread, entries, ctx, running) {
  const section = node("section", `turn${running ? " running" : ""}`);
  // the request, then the plan, kept in view while the turn runs
  let rest = entries;
  if (entries[0].message.role === "user") {
    section.append(entryNode(thread, entries[0], ctx, running));
    rest = entries.slice(1);
  }
  const plan = entries.find(({ message }) => message.role === "plan");
  if (plan) section.append(planList(plan.message.data?.items ?? [], running));
  const flow = [];   // runs of activity (tools, thoughts) and everything else
  for (const entry of rest) {
    const { role, data } = entry.message;
    if (role === "plan") continue;
    const isActivity = role === "thinking" || (role === "tool" && !SPECIAL.has(data?.name));
    const run = flow[flow.length - 1];
    if (isActivity && Array.isArray(run)) run.push(entry);
    else if (isActivity) flow.push([entry]);
    else flow.push(entry);
  }
  flow.forEach((item, i) => {
    if (Array.isArray(item)) section.append(...activityRun(thread, item, ctx, running && i === flow.length - 1));
    else section.append(entryNode(thread, item, ctx, running));
  });
  if (running) section.append(...liveNodes(thread, ctx));
  return section;
}

// A run of tool calls and thoughts: one collapsible group when it holds
// several calls, open while it is where a running turn is at.
function activityRun(thread, run, ctx, tail) {
  const calls = run.filter(({ message }) => message.role === "tool");
  const rows = run.map((entry) => entryNode(thread, entry, ctx, tail));
  if (calls.length < 2) return rows;
  const key = `${thread.id}:g${run[0].index}`;
  const group = node("details", "tool-group");
  group.open = ctx.open.get(key) ?? tail;
  group.addEventListener("toggle", () => ctx.open.set(key, group.open));
  const summary = group.appendChild(node("summary"));
  const failed = calls.filter(({ message }) => statusOf(message.data ?? {}) === "error").length;
  const going = tail && calls.some(({ message }) => message.data?.status === "running");
  summary.append(statusIcon(going ? "running" : failed ? "error" : "ok", tail));
  summary.append(node("span", "tool-label", `Used ${calls.length} tools`));
  const thought = run.filter(({ message }) => message.role === "thinking")
    .reduce((sum, { message }) => sum + (message.data?.ms ?? 0), 0);
  const names = [...new Set(calls.map(({ message }) => describe(message.data).label))];
  summary.append(node("span", "tool-detail",
    [names.join(", "), thought >= 1000 ? `thought ${duration(thought)}` : ""].filter(Boolean).join(" · ")));
  const body = group.appendChild(node("div", "tool-group-body"));
  body.append(...rows);
  return [group];
}

function entryNode(thread, { index, message }, ctx, running) {
  const { role, text, data } = message;
  switch (role) {
    case "user": return node("div", "msg user", text);
    case "assistant": return prose("msg assistant", text);
    case "thinking": return thought(text, data?.ms ?? 0, `${thread.id}:${index}`, ctx);
    case "tool":
      if (data?.name === "record_note") return noteCard(data.input ?? {});
      if (data?.op) return ctx.opCard(data.op) ?? toolRow(thread, index, data, ctx, running);
      return toolRow(thread, index, data ?? {}, ctx, running);
    case "error": return node("div", "msg error", text);
    case "notice": return node("div", "msg notice", text);
    case "turn": return footer(data ?? {}, sessionCost(thread, index));
    default: return node("div", "msg notice", text);
  }
}

function statusIcon(status, running) {
  // a call left running when its turn ended never finished
  const shown = status === "running" && !running ? "lost" : status;
  return node("span", `status ${shown}`);
}

function toolRow(thread, index, data, ctx, running) {
  const key = `${thread.id}:${index}`;
  const { label, detail } = describe(data);
  const row = node("details", `tool ${statusOf(data) ?? ""}`);
  row.open = ctx.open.get(key) ?? false;
  row.addEventListener("toggle", () => {
    ctx.open.set(key, row.open);
    if (row.open && !row.querySelector(".tool-body")) row.append(toolBody(data));
  });
  if (row.open) row.append(toolBody(data));
  const summary = node("summary");
  summary.append(statusIcon(statusOf(data), running), node("span", "tool-label", label));
  if (detail) summary.append(node("span", "tool-detail", detail));
  row.prepend(summary);
  return row;
}

function toolBody(data) {
  const body = node("div", "tool-body");
  const input = data.input ?? {};
  if (Object.keys(input).length) {
    body.append(node("div", "tool-section", "Input"));
    const lines = Object.entries(input).map(([key, value]) =>
      `${key}: ${typeof value === "string" ? value : JSON.stringify(value, null, 2)}`);
    body.append(node("pre", "", lines.join("\n")));
  }
  if (data.result !== undefined) {
    body.append(node("div", "tool-section", data.status === "error" ? "Error" : "Result"));
    body.append(node("pre", data.status === "error" ? "error" : "", pretty(data.result)));
  }
  return body;
}

// A result as the agent read it, JSON laid out when it parses.
function pretty(text) {
  try {
    return JSON.stringify(JSON.parse(text), null, 2);
  } catch {
    return text;
  }
}

function thought(text, ms, key, ctx) {
  const label = `Thought for ${duration(Math.max(ms, 1000))}`;
  if (!text) return node("div", "thought", label);
  const block = node("details", "thought");
  block.open = ctx.open.get(key) ?? false;
  block.addEventListener("toggle", () => ctx.open.set(key, block.open));
  block.append(node("summary", "", label), prose("thought-text", text));
  return block;
}

function noteCard({ title = "", text = "" }) {
  const card = node("div", "note-card");
  card.append(node("div", "note-title", title), prose("note-text", text));
  return card;
}

function planList(items, running) {
  const plan = node("div", `plan${running ? " pinned" : ""}`);
  const done = items.filter((item) => item.status === "completed").length;
  plan.append(node("div", "plan-head", `Plan · ${done}/${items.length}`));
  const list = plan.appendChild(node("ul"));
  for (const item of items) {
    const li = list.appendChild(node("li", item.status));
    li.append(node("span", "mark", PLAN_MARK[item.status] ?? ""));
    li.append(node("span", "", item.status === "in_progress" && item.active ? item.active : item.text));
  }
  return plan;
}

// What the thread's session had cost before the turn ending at `index`.
function sessionCost(thread, index) {
  const before = thread.messages.slice(0, index).findLast((m) => m.role === "turn");
  return before?.data?.cost ?? 0;
}

function footer({ ms, cost, input, output, model, effort }, before) {
  const parts = [];
  if (ms) parts.push(duration(ms));
  if (input || output) parts.push(`${tokens(input ?? 0)} in · ${tokens(output ?? 0)} out`);
  // claude reports what the session has cost so far; the turn cost the difference
  if (typeof cost === "number") parts.push(`$${(cost >= before ? cost - before : cost).toFixed(2)}`);
  const settings = [model?.replace(/^claude-/, ""), effort].filter(Boolean).join(" ");
  if (settings) parts.push(settings);
  return node("div", "turn-foot", parts.join(" · "));
}

// What only the live stream has: the thought in progress, the reply's
// draft, and the running line, whose `.activity` and `.elapsed` the caller
// updates in place.
function liveNodes(thread, { live, now }) {
  const out = [];
  if (live.thinking) {
    const block = node("div", "thought live");
    block.append(node("span", "", "Thinking…"));
    if (live.thinking.text) block.append(prose("thought-text", live.thinking.text));
    out.push(block);
  }
  if (live.draft) out.push(prose("msg assistant draft", live.draft));
  const line = node("div", "running-line");
  line.append(node("span", "status running"), node("span", "activity", activity(thread, live)));
  const start = [...thread.messages].reverse().find((m) => m.role === "user")?.at ?? now;
  line.append(node("span", "elapsed", duration(Math.max(0, now - start))));
  out.push(line);
  return out;
}
