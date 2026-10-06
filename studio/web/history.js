// The project's versions: a time slider under the editor over the current
// branch, the History pane listing every version, and a read-only view of
// any one of them with restore and branch.
//
// A version is { id, parents, tree, created, origin: { kind, … }, label?,
// forms_changed: ["file:key"] }; the studio sends them all once, then each
// new one as it is made.

import { createEditor } from "./editor.js";

const $ = (id) => document.getElementById(id);

export function createHistory({ send, files }) {
  const state = {
    main: "",
    current: "",
    branches: {},
    versions: new Map(), // id -> version
    viewing: null, // { id, files } shown read-only, or null at the head
    asked: null, // the id whose files were last asked for
    expanded: new Set(), // newest ids of expanded runs of edits
  };
  let viewer = null; // the read-only editor, made on first use

  const head = () => state.branches[state.current] ?? null;

  // The current branch's first-parent chain, oldest first.
  function chain() {
    const ids = [];
    for (let id = head(); id != null; id = state.versions.get(id)?.parents[0]) ids.push(id);
    return ids.reverse();
  }

  // Viewing ------------------------------------------------------------------

  function view(id) {
    if (id === head()) return back();
    state.asked = id;
    send({ t: "view-version", id });
  }

  async function show(id, versionFiles) {
    state.viewing = { id, files: versionFiles };
    viewer ??= await createEditor($("viewer"), {
      readOnly: true,
      onChange() {},
      onEvaluate() {},
      onSave() {},
      onBreakpoints() {},
      snapBreakpoint: () => null,
    });
    $("editor").hidden = true;
    $("viewer").hidden = false;
    showFile();
    render();
  }

  // Show the version's copy of the file open in the editor, or its main file.
  function showFile() {
    if (!state.viewing || !viewer) return;
    const { files: versionFiles } = state.viewing;
    const path = files.active() in versionFiles ? files.active() : state.main;
    state.viewing.path = path;
    viewer.set(versionFiles[path] ?? "");
  }

  function back() {
    state.viewing = null;
    state.asked = null;
    $("viewer").hidden = true;
    $("editor").hidden = false;
    render();
  }

  // Rendering ----------------------------------------------------------------

  function render() {
    renderTimeline();
    renderList();
  }

  function renderTimeline() {
    const ids = chain();
    const slider = $("timeline-slider");
    slider.max = Math.max(0, ids.length - 1);
    const at = state.viewing ? ids.indexOf(state.viewing.id) : ids.length - 1;
    slider.value = at < 0 ? slider.max : at;
    slider.disabled = ids.length < 2;
    const shown = state.versions.get(state.viewing?.id ?? head());
    $("timeline-label").textContent = shown
      ? `${state.viewing ? "" : "head · "}v${shown.id} · ${describe(shown)} · ${ago(shown.created)}`
      : "";
    $("timeline-label").title = shown ? changes(shown, Infinity) : "";

    const banner = $("viewing");
    banner.hidden = !state.viewing;
    if (state.viewing) {
      const offChain = !ids.includes(state.viewing.id) ? " (not on this branch)" : "";
      $("viewing-title").textContent =
        `Viewing v${state.viewing.id}${offChain}, read-only — ${state.viewing.path}`;
    }
  }

  function renderList() {
    const list = $("history-list");
    const onChain = new Set(chain());
    const rows = [];
    const newestFirst = [...state.versions.values()].sort((a, b) => b.id - a.id);
    for (let i = 0; i < newestFirst.length; ) {
      // a run of edits, each made from the one after it
      const run = [newestFirst[i++]];
      while (run[0].origin.kind === "auto" && newestFirst[i]?.origin.kind === "auto"
        && run.at(-1).parents[0] === newestFirst[i].id) {
        run.push(newestFirst[i++]);
      }
      const older = newestFirst[i];
      if (run.length === 1) {
        rows.push(row(run[0], onChain, older));
        continue;
      }
      const open = state.expanded.has(run[0].id);
      const summary = element("button", `history-run${onChain.has(run[0].id) ? "" : " off"}`);
      rows.push(summary);
      summary.append(
        element("span", "chevron", open ? "▾" : "▸"),
        element("span", "what", `${run.length} edits`),
        element("span", "forms", summarize(run.flatMap((version) => version.forms_changed), 3)),
        element("span", "when", ago(run[0].created)),
      );
      summary.title = `v${run.at(-1).id}–v${run[0].id}`;
      summary.addEventListener("click", () => {
        if (open) state.expanded.delete(run[0].id);
        else state.expanded.add(run[0].id);
        renderList();
      });
      if (open) rows.push(...run.map((version, k) => row(version, onChain, run[k + 1] ?? older, "nested")));
    }
    if (!rows.length) rows.push(element("p", "hint", "No versions yet."));
    list.replaceChildren(...rows);
  }

  // One version; `older` is the row below it, to tell when it was made from
  // something else.
  function row(version, onChain, older, extra = "") {
    const viewing = state.viewing?.id === version.id || (!state.viewing && version.id === head());
    const node = element("button",
      `history-row ${version.origin.kind} ${extra}${onChain.has(version.id) ? "" : " off"}${viewing ? " viewing" : ""}`);
    node.append(element("span", "id", `v${version.id}`), element("span", "what", describe(version)));
    for (const [branch, id] of Object.entries(state.branches)) {
      if (id === version.id) node.append(element("span", `ref${branch === state.current ? " current" : ""}`, branch));
    }
    const parent = version.parents[0];
    if (parent != null && parent !== older?.id) node.append(element("span", "from", `from v${parent}`));
    node.append(element("span", "when", ago(version.created)));
    const forms = summarize(version.forms_changed, 4);
    if (forms) node.append(element("span", "forms", forms));
    node.title = changes(version, Infinity);
    node.addEventListener("click", () => view(version.id));
    return node;
  }

  function changes(version, limit) {
    return summarize(version.forms_changed, limit) || "no form changed";
  }

  // "rule→path, table:edge +3", naming forms of the main file without it.
  function summarize(keys, limit) {
    const prefix = `${state.main}:`;
    const names = [...new Set(keys.map((key) => key.startsWith(prefix) ? key.slice(prefix.length) : key))];
    const more = names.length - limit;
    return names.slice(0, limit).join(", ") + (more > 0 ? ` +${more}` : "");
  }

  // Controls -----------------------------------------------------------------

  $("timeline-slider").addEventListener("input", (event) => view(chain()[Number(event.target.value)]));
  $("viewing-restore").addEventListener("click", () => send({ t: "restore", id: state.viewing.id }));
  $("viewing-branch").addEventListener("click", () => send({ t: "branch", id: state.viewing.id }));
  $("viewing-back").addEventListener("click", back);

  // Messages from the studio -------------------------------------------------

  const receive = {
    init() {
      if (state.viewing) back();
      send({ t: "history" });
    },
    history({ main, current, branches, versions }) {
      Object.assign(state, { main, current, branches, versions: new Map(versions.map((v) => [v.id, v])) });
      render();
    },
    version({ version, current, branches }) {
      Object.assign(state, { current, branches });
      state.versions.set(version.id, version);
      // A restore or a new branch replaces what the editor shows.
      if (state.viewing && ["revert", "branch"].includes(version.origin.kind)) back();
      else render();
    },
    "version-files"({ id, files: versionFiles }) {
      if (id === state.asked) show(id, versionFiles);
    },
    files({ main }) {
      state.main = main;
      render();
    },
  };

  return { receive, render, opened: showFile };
}

function describe({ origin, label }) {
  switch (origin.kind) {
    case "auto": return "edit";
    case "checkpoint": return label ? `checkpoint · ${label}` : "checkpoint";
    case "revert": return `restored v${origin.to}`;
    case "branch": return `branched from v${origin.from}`;
    case "disk": return "changed on disk";
    case "accept": return label ? `accepted · ${label}` : "accepted";
    default: return label ?? origin.kind;
  }
}

function ago(ms) {
  const seconds = Math.max(0, (Date.now() - ms) / 1000);
  if (seconds < 60) return "just now";
  const [unit, size] = seconds < 3600 ? ["min", 60] : seconds < 86400 ? ["h", 3600] : ["d", 86400];
  return `${Math.floor(seconds / size)} ${unit} ago`;
}

function element(tag, className, text) {
  return Object.assign(document.createElement(tag), { className, ...(text != null && { textContent: text }) });
}
