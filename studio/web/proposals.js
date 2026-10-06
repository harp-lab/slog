// What the agents propose, reviewed where it would land: in the editor, on
// the main file's text (inline-diff.js), each change with its own Accept and
// Reject, coloured by the thread that proposed it. Around that:
// - the proposal bar over the editor, shown only while something is
//   pending: how many changes, stepping between them (F7), Accept all and
//   Reject all of the current one's changeset, and the change graph;
// - the Review tab, a slim list of changesets whose rows jump to their
//   change;
// - the chip an Ask thread shows for a turn's proposals.
// Accepting goes through the studio's accept, which records a version.

import { node } from "./thread.js";
import { fork, groupHunk, place } from "./hunks.js";
import { forms } from "./forms.js";
import { relations } from "./graph.js";
import { createInlineDiff } from "./inline-diff.js";

const TONES = 5;
export const toneOf = (thread) => `tone-${(thread - 1) % TONES}`;

export function createProposals({ editor, files, send, bar, list, changes, history }) {
  const state = {
    view: { threads: [], changesets: [], ops: [] },
    text: "",
    groups: [],
    unplaced: [],
    current: null, // the key (first op id) of the change last stepped to
    graph: null, // { thread, baseline: { id, files } | null } while the change graph shows
  };
  const inline = editor.raw && createInlineDiff(editor.raw, {
    onMove(hunk) {
      state.current = hunk.key;
      renderBar();
    },
  });
  if (editor.raw) {
    let timer = null;
    editor.raw.editor.onDidChangeModelContent(() => {
      clearTimeout(timer);
      timer = setTimeout(refresh, 120);
    });
    editor.raw.editor.onDidChangeModel(refresh);
  }

  const opOf = (id) => state.view.ops.find((op) => op.id === id);
  const threadOf = (id) => state.view.threads.find((t) => t.id === id);
  const changesetOf = (id) => state.view.changesets.find((c) => c.id === id);
  const mainShown = () => files.active() === files.main();
  const mainText = () => mainShown() ? editor.get() : files.texts()[files.main()] ?? "";
  const currentGroup = () => state.groups.find((g) => g.ids[0] === state.current) ?? state.groups[0] ?? null;

  function refresh() {
    state.text = mainText();
    ({ groups: state.groups, unplaced: state.unplaced } = place(state.text, state.view.ops));
    draw();
    renderBar();
    renderList();
    if (state.graph && changes.shown()) showGraph();
  }

  // ---- In the editor ----------------------------------------------------

  function draw() {
    if (!inline) return;
    if (!mainShown()) return inline.clear();
    const found = forms(state.text);
    inline.show(state.groups.map((group) => {
      const hunk = groupHunk(state.text, group);
      const lines = hunk.removed.map((r) => r.line);
      return {
        ...hunk,
        key: group.ids[0],
        tone: toneOf(group.thread),
        forms: found.filter((f) => lines.some((l) => f.line <= l && l <= f.endLine)).map((f) => [f.line, f.endLine]),
        header: () => header(group),
      };
    }));
  }

  // The slim line over a change: whose it is, what for, and its controls.
  function header(group) {
    const ops = group.ids.map(opOf);
    const line = node("div", `ip-head ${toneOf(group.thread)}`);
    line.append(node("span", "ip-dot"));
    const title = threadOf(group.thread)?.title ?? `thread ${group.thread}`;
    line.append(node("span", "ip-who", `${title} · ${group.ids.map((id) => `#${id}`).join(" ")}`));
    const note = ops.map((op) => op?.note).filter(Boolean).join("; ");
    if (note) line.append(node("span", "ip-note", note));
    const rivals = conflictsOf(group);
    if (rivals.length) line.append(node("span", "ip-flag", `conflicts with ${rivals.join(", ")}`));
    const accept = line.appendChild(node("button", "ip-accept", "Accept"));
    accept.disabled = rivals.length > 0;
    accept.title = rivals.length ? "Reject one side of the conflict first" : "Make this change, as a new version";
    accept.addEventListener("click", () => acceptGroup(group));
    const reject = line.appendChild(node("button", "ip-reject", "Reject"));
    reject.addEventListener("click", () => rejectGroup(group));
    return line;
  }

  // The other threads' changes this one overlaps, by thread title.
  function conflictsOf(group) {
    const ids = new Set(group.ids.flatMap((id) => opOf(id)?.conflicts ?? []));
    const threads = new Set([...ids].map((id) => opOf(id)?.thread));
    return [...threads].map((t) => `“${threadOf(t)?.title ?? `thread ${t}`}”`);
  }

  function acceptGroup(group) {
    files.flush(); // the studio applies it to the text as typed
    for (const id of group.ids) send({ t: "accept", op: id });
  }

  function rejectGroup(group) {
    for (const id of [...group.ids].reverse()) send({ t: "reject", op: id });
  }

  // Show a change in the editor, opening the main file for it.
  function focus(group) {
    if (!group) return;
    if (!mainShown()) files.open(files.main());
    state.current = group.ids[0];
    inline?.reveal(group.ids[0]);
    editor.raw?.editor.focus();
    renderBar();
  }

  function step(direction) {
    if (!mainShown()) return focus(currentGroup());
    inline?.next(direction);
  }

  // ---- The bar ----------------------------------------------------------

  function renderBar() {
    const groups = state.groups;
    bar.hidden = !groups.length && !state.unplaced.length;
    if (bar.hidden) {
      if (state.graph) changes.hide();
      return;
    }
    bar.replaceChildren();
    const threads = [...new Set(groups.map((g) => g.thread))];
    for (const t of threads) {
      const dot = bar.appendChild(node("span", `ip-dot ${toneOf(t)}`));
      dot.title = threadOf(t)?.title ?? "";
    }
    const group = currentGroup();
    const count = `${groups.length} proposed change${groups.length === 1 ? "" : "s"}`;
    const what = bar.appendChild(node("span", "ip-what", count));
    if (group) what.append(node("span", "ip-of", ` · ${changesetOf(group.changeset)?.title ?? ""}`));
    if (state.unplaced.length) {
      const gone = bar.appendChild(node("button", "quiet small", `${state.unplaced.length} no longer applies`));
      gone.title = "Their text has changed since; see Review";
      gone.addEventListener("click", () => document.querySelector('.panel-toggle[data-tab="review"]')?.click());
    }
    if (groups.length && !mainShown()) {
      const show = bar.appendChild(node("button", "secondary small", `Show in ${files.main()}`));
      show.addEventListener("click", () => focus(group));
    }
    if (groups.length) {
      const nav = bar.appendChild(node("span", "ip-nav"));
      const previous = nav.appendChild(node("button", "quiet small", "‹"));
      previous.title = "Previous change (Shift+F7)";
      previous.addEventListener("click", () => step(-1));
      nav.append(node("span", "ip-index", `${groups.indexOf(group) + 1}/${groups.length}`));
      const next = nav.appendChild(node("button", "quiet small", "›"));
      next.title = "Next change (F7)";
      next.addEventListener("click", () => step(1));
      const graph = bar.appendChild(node("button", `secondary small${state.graph ? " on" : ""}`, "Change graph"));
      graph.title = "What the proposal does to the relations and rules";
      graph.addEventListener("click", () => {
        if (state.graph) return changes.hide();
        state.graph = { thread: group.thread, baseline: null };
        showGraph();
        renderBar();
      });
      const pending = state.view.ops.filter((op) => op.changeset === group.changeset && op.status === "pending");
      const title = changesetOf(group.changeset)?.title ?? "";
      const all = bar.appendChild(node("button", "primary small", "Accept all"));
      all.title = `Accept every change of “${title}”`;
      all.addEventListener("click", () => {
        files.flush();
        send({ t: "accept-changeset", changeset: group.changeset });
      });
      const none = bar.appendChild(node("button", "secondary small", "Reject all"));
      none.title = `Reject every change of “${title}”`;
      none.addEventListener("click", () => {
        for (const op of [...pending].reverse()) send({ t: "reject", op: op.id });
      });
    }
  }

  // ---- The change graph -------------------------------------------------

  // The program's files as they stand, the main file as `main`.
  function program(main) {
    return Object.values({ ...files.texts(), [files.main()]: main });
  }

  function showGraph() {
    const { thread, baseline } = state.graph;
    const threads = [...new Set(state.groups.map((g) => g.thread))];
    const tools = threads.length > 1 ? threads.map((t) => {
      const chip = node("button", `ip-thread ${toneOf(t)}${t === thread ? " on" : ""}`, threadOf(t)?.title ?? `thread ${t}`);
      chip.addEventListener("click", () => { state.graph.thread = t; showGraph(); });
      return chip;
    }) : [];
    const against = node("button", "quiet small", baseline ? `against v${baseline.id} ×` : "against the working text ▾");
    against.title = baseline ? "Compare with the working text again" : "Compare with an earlier version instead";
    against.addEventListener("click", () => {
      if (baseline) {
        state.graph.baseline = null;
        history.mark(null);
        return showGraph();
      }
      history.pick("Pick the version to compare the proposal with", async (id) => {
        const kept = await history.filesOf(id);
        if (!state.graph) return;
        state.graph.baseline = { id, files: kept };
        history.mark(id);
        showGraph();
      });
    });
    tools.push(against);
    changes.show({
      owner: "proposals",
      heading: `Proposed by “${threadOf(thread)?.title ?? ""}”`,
      before: baseline ? Object.values(baseline.files) : program(state.text),
      after: program(fork(state.text, state.groups, thread)),
      tools,
      onNode: (name) => revealRelation(name, thread),
      onClose() {
        if (state.graph?.baseline) history.mark(null);
        state.graph = null;
        renderBar();
      },
    });
  }

  // A relation's change, or else its first form in the text.
  function revealRelation(name, thread) {
    const mentions = (text) => relations(text).some((r) => r.name === name || r.heads?.includes(name) || r.body?.includes(name));
    const group = state.groups.find((g) => g.thread === thread && mentions(g.replacement));
    if (group) return focus(group);
    const form = relations(state.text).find((r) => r.name === name || r.heads?.includes(name));
    if (!form) return;
    if (!mainShown()) files.open(files.main());
    editor.reveal({ line: form.line, col: 1 });
  }

  // ---- The Review tab ---------------------------------------------------

  function renderList() {
    list.replaceChildren();
    if (!state.view.ops.length) {
      list.append(node("p", "hint", "Nothing proposed yet. What an agent proposes shows in the editor, where you accept or reject it."));
      return;
    }
    for (const changeset of [...state.view.changesets].reverse()) {
      const ops = state.view.ops.filter((op) => op.changeset === changeset.id);
      if (!ops.length) continue;
      const section = list.appendChild(node("section", "review-set"));
      const head = section.appendChild(node("div", "review-head"));
      head.append(node("span", `ip-dot ${toneOf(changeset.thread)}`), node("span", "review-title", changeset.title));
      const decided = ["accepted", "rejected"].map((status) => [status, ops.filter((op) => op.status === status).length])
        .filter(([, n]) => n).map(([status, n]) => `${n} ${status}`).join(" · ");
      if (decided) head.append(node("span", "review-decided", decided));
      for (const group of state.groups.filter((g) => g.changeset === changeset.id)) {
        const row = section.appendChild(node("button", `review-row ${toneOf(group.thread)}`));
        row.append(node("span", "review-ids", group.ids.map((id) => `#${id}`).join(" ")));
        row.append(node("span", "review-what", describe(group)));
        if (conflictsOf(group).length) row.append(node("span", "ip-flag", "conflict"));
        row.title = "Show it in the editor";
        row.addEventListener("click", () => focus(group));
      }
      for (const id of state.unplaced.filter((id) => opOf(id).changeset === changeset.id)) {
        const row = section.appendChild(node("div", "review-row gone"));
        row.append(node("span", "review-ids", `#${id}`), node("span", "review-what", opOf(id).note || "an edit"));
        row.append(node("span", "ip-flag", "no longer applies"));
        const reject = row.appendChild(node("button", "quiet small", "Reject"));
        reject.addEventListener("click", () => send({ t: "reject", op: id }));
      }
    }
  }

  // A change in a few words: its note, else its first new line.
  function describe(group) {
    const note = group.ids.map((id) => opOf(id)?.note).find(Boolean);
    return note || group.replacement.split("\n").find((line) => line.trim())?.trim() || "removes text";
  }

  // ---- The chip in an Ask thread ----------------------------------------

  // "Proposed 3 changes · view" for the ops a turn proposed.
  function chip(ids) {
    const ops = ids.map(opOf).filter(Boolean);
    if (!ops.length) return null;
    const pending = ops.filter((op) => op.status === "pending");
    const counts = ["accepted", "rejected"].map((status) => [status, ops.filter((op) => op.status === status).length])
      .filter(([, n]) => n).map(([status, n]) => (n === ops.length ? status : `${n} ${status}`));
    const words = [`Proposed ${ops.length} change${ops.length === 1 ? "" : "s"}`, ...counts];
    const button = node("button", `proposal-chip ${toneOf(ops[0].thread)}${pending.length ? "" : " done"}`);
    button.append(node("span", "ip-dot"), node("span", "", words.join(" · ")));
    if (pending.length) button.append(node("span", "chip-view", "view"));
    button.title = pending.length ? "Show them in the editor" : "";
    button.addEventListener("click", () => {
      const group = state.groups.find((g) => g.ids.some((id) => ids.includes(id)));
      if (group) focus(group);
    });
    return button;
  }

  return {
    update(view) {
      state.view = view;
      refresh();
    },
    refresh,
    chip,
  };
}
