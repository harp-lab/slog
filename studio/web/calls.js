// The Calls tab beside the REPL transcript: a run's demand calls as a tree
// (compiler/demand-debug.rkt), and, while a run is held, the stack of calls
// it stands in.
//
// The tree is read lazily: the calls no rule asked come first, and a call's
// subcalls are asked for (`calls #N`) only when it is opened, a page at a
// time. Each call shows its arguments, its answers and the stratum and
// iteration each was found in, or that it has none -- where a relation
// fails. Its source link shows the rule that asked it.

const PAGE = 100;

const node = (tag, className, text) => {
  const element = document.createElement(tag);
  if (className) element.className = className;
  if (text !== undefined) element.textContent = text;
  return element;
};

// "main.slog:12:1" -> { file: "main.slog", line: 12 }
export function sourceOf(loc) {
  const match = /^(.*):(\d+):(\d+)$/.exec(loc ?? "");
  return match && { file: match[1], line: Number(match[2]), col: Number(match[3]) };
}

// The badge a call's status earns.
export function badge(call) {
  if (call.status === "answered") {
    const first = call.answers[0];
    return { className: "answered", text: `⇒ ${first.value}${call.answers.length > 1 ? ` (+${call.answers.length - 1})` : ""}` };
  }
  return call.status === "pending"
    ? { className: "pending", text: "no answer yet" }
    : { className: "failed", text: "no answer" };
}

// `quiet(line)` answers a REPL line's outcome without a transcript entry;
// `reveal(source)` shows a rule; `tabs`, `transcript` and `results` are the
// result area, as trace.js takes them. Returns { entry(entry) }.
export function initCalls({ quiet, reveal, tabs, transcript, results }) {
  const state = {
    stack: null,      // the held run's stack, from its pause result
    roots: null,      // the latest `calls` answer
    children: new Map(), // id -> [call] once opened
    open: new Set(),  // ids shown open
    stale: true,      // a run happened since roots were read
    recording: false, // a debug run recorded calls
    error: null,
  };
  const panel = node("div", "calls-panel");
  panel.hidden = true;
  transcript.after(panel);
  const tab = node("button", "rs-tab", "Calls");
  tab.title = "The run's demand calls: who asked what, the answers, and where they fail";
  tab.hidden = true;
  tabs.firstElementChild.after(tab);
  const fresh = tab.appendChild(node("span", "fresh"));
  fresh.hidden = true;
  tab.addEventListener("click", () => {
    transcript.hidden = true;
    results.hidden = true;
    for (const other of tabs.querySelectorAll(".rs-tab")) other.setAttribute("aria-selected", String(other === tab));
    panel.hidden = false;
    for (const sibling of panel.parentElement.children) {
      if (sibling !== panel && sibling.classList.contains("execution")) sibling.hidden = true;
    }
    refresh();
  });
  const yielded = new MutationObserver(() => {
    if (panel.hidden || (transcript.hidden && results.hidden)) return;
    panel.hidden = true;
    tab.setAttribute("aria-selected", "false");
  });
  for (const other of [transcript, results]) yielded.observe(other, { attributes: true, attributeFilter: ["hidden"] });
  // the Execution tab (trace.js) takes the area the same way
  const execution = panel.parentElement.querySelector(".execution");
  if (execution) {
    new MutationObserver(() => {
      if (!execution.hidden && !panel.hidden) {
        panel.hidden = true;
        tab.setAttribute("aria-selected", "false");
      }
    }).observe(execution, { attributes: true, attributeFilter: ["hidden"] });
  }

  async function refresh() {
    if (panel.hidden) return;
    fresh.hidden = true;
    if (state.stale) {
      state.stale = false;
      state.children.clear();
      const outcome = await quiet("calls");
      state.roots = outcome.result?.calls ?? null;
      state.error = outcome.error?.message ?? null;
      // calls the user had open stay open, read afresh
      await Promise.all([...state.open].map(load));
    }
    render();
  }

  async function load(id) {
    const outcome = await quiet(`calls #${id}`);
    const nodes = outcome.result?.calls?.nodes;
    if (nodes) state.children.set(id, nodes.slice(1));
  }

  async function toggle(id) {
    if (state.open.has(id)) state.open.delete(id);
    else {
      state.open.add(id);
      if (!state.children.has(id)) await load(id);
    }
    render();
  }

  function callRow(call, depth, place) {
    const row = node("div", `call ${call.status}`);
    row.style.paddingLeft = `${8 + depth * 16}px`;
    const twist = row.appendChild(node("span", "twist", call.subcalls ? (state.open.has(call.id) ? "▾" : "▸") : "·"));
    if (call.subcalls) {
      twist.title = `${call.subcalls} subcall${call.subcalls === 1 ? "" : "s"}`;
      twist.addEventListener("click", () => toggle(call.id));
      row.addEventListener("dblclick", () => toggle(call.id));
    }
    row.append(node("span", "call-id", `#${call.id}`));
    const text = row.appendChild(node("span", "call-text", call.call));
    text.title = call.call;
    const { className, text: said } = badge(call);
    const answer = row.appendChild(node("span", `call-badge ${className}`, said));
    answer.title = call.answers.map((a) => `${a.value} · stratum ${a.scc} iteration ${a.iteration} · ${a.source}`).join("\n")
      || (call.status === "failed" ? "No rule derived an answer: failure is absence" : "");
    if (call.asked) {
      const where = row.appendChild(node("a", "call-where", `s${call.asked.scc} i${call.asked.iteration}`));
      where.title = `asked at stratum ${call.asked.scc}, iteration ${call.asked.iteration}, by ${call.asked.source}${call.asks > 1 ? ` (asked ${call.asks}×)` : ""}`;
      where.addEventListener("click", () => reveal(call.asked.source));
    }
    if (place === "frontier") row.classList.add("frontier");
    return row;
  }

  function subtree(box, call, depth, seen) {
    box.append(callRow(call, depth));
    if (!state.open.has(call.id) || seen.has(call.id)) return;
    const kids = state.children.get(call.id) ?? [];
    const shown = state.open.has(`more:${call.id}`) ? kids.length : Math.min(kids.length, PAGE);
    const next = new Set(seen).add(call.id);
    for (const kid of kids.slice(0, shown)) subtree(box, kid, depth + 1, next);
    if (shown < kids.length) {
      const more = box.appendChild(node("button", "secondary small more", `${kids.length - shown} more`));
      more.style.marginLeft = `${8 + (depth + 1) * 16}px`;
      more.addEventListener("click", () => { state.open.add(`more:${call.id}`); render(); });
    }
  }

  function render() {
    if (panel.hidden) return;
    panel.replaceChildren();
    if (state.stack?.length) {
      const box = panel.appendChild(node("section", "call-stack"));
      box.append(node("h4", null, "Held in"));
      state.stack.forEach((frame, i) => {
        const row = box.appendChild(callRow(frame.node, 0));
        row.prepend(node("span", "frame-n", String(i)));
        if (frame.bindings.length) {
          row.append(node("span", "frame-bindings",
            frame.bindings.map(([name, value]) => `${name} = ${value}`).join(" · ")));
        }
      });
    }
    if (state.error) {
      panel.append(node("p", "hint", state.recording ? state.error : "Debug the program to record its demand calls."));
      return;
    }
    const roots = state.roots;
    if (!roots) {
      panel.append(node("p", "hint", "Debug the program: its demand calls appear here."));
      return;
    }
    const summary = roots.summary;
    panel.append(node("div", "calls-summary",
      `${summary.calls} calls · ${summary.answered} answered${summary.dropped ? ` · ${summary.dropped} log records dropped` : ""}`));
    if (roots.frontier?.length) {
      const failing = panel.appendChild(node("section", "call-frontier"));
      failing.append(node("h4", null, "Where it fails: no answer, every subcall answered"));
      for (const id of roots.frontier) {
        const call = roots.nodes.find((n) => n.id === id);
        const row = node("div", "call failed frontier");
        row.append(node("span", "call-id", `#${id}`), node("span", "call-text", call?.call ?? "(asked by another call)"));
        row.addEventListener("click", () => locate(id));
        failing.append(row);
      }
    }
    const tree = panel.appendChild(node("section", "call-tree"));
    for (const call of roots.nodes) subtree(tree, call, 0, new Set());
  }

  // Open the path from a root down to call `id`: read its stack.
  async function locate(id) {
    const outcome = await quiet(`calls #${id}`);
    const call = outcome.result?.calls?.nodes?.[0];
    if (call?.asked?.source) reveal(call.asked.source);
    if (call && !state.roots.nodes.some((n) => n.id === id)) {
      // shown as a root of its own, opened
      state.roots.nodes = [...state.roots.nodes, call];
    }
    state.children.set(id, outcome.result?.calls?.nodes?.slice(1) ?? []);
    state.open.add(id);
    render();
  }

  return {
    entry(entry) {
      const result = entry.result;
      if (!result) return;
      if (result.kind === "paused") {
        state.stack = result.calls?.stack ?? null;
        state.recording = true;
        state.stale = true;
      } else if (result.held === false && state.stack) {
        state.stack = null;
        state.stale = true;
      }
      if (result.change && entry.origin === "evaluate") state.stale = true;
      if (/^calls on/.test(entry.line ?? "")) state.recording = true;
      tab.hidden = !state.recording;
      if (state.stale && panel.hidden) fresh.hidden = !state.recording;
      refresh();
    },
    show: () => tab.click(),
  };
}
