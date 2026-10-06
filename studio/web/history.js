// The project's versions, shown only when they matter. By default there is
// just the version chip beside the file tabs. The history strip under the
// editor -- the version graph, one lane per branch, and the time slider over
// the current branch -- opens when the chip is clicked, when an old version
// is viewed, for a moment after a restore or a new branch, and when a
// version is being picked (to compare with, or as a proposal's baseline).
//
// Viewing a version shows it read-only in place of the editor, with what
// differs from it to the working text (or to a version chosen with
// "Compare with…") drawn in place as proposals are: red lines gone since,
// green lines come since.
//
// A version is { id, parents, tree, created, origin: { kind, … }, label?,
// forms_changed: ["file:key"] }; the studio sends them all once, then each
// new one as it is made.

import { createEditor } from "./editor.js";
import { relations, versionGraph } from "./graph.js";
import { hunks } from "./hunks.js";
import { createInlineDiff } from "./inline-diff.js";

const $ = (id) => document.getElementById(id);
const SVG = "http://www.w3.org/2000/svg";
const COLUMN = 24;
const LANE = 20;
const AUTO_CLOSE_MS = 6000;

export function createHistory({ send, files, changes }) {
  const state = {
    main: "",
    current: "",
    branches: {},
    versions: new Map(), // id -> version
    viewing: null, // { id, files, path } shown read-only, or null at the head
    against: null, // { id, files } the viewed version is compared with, else the working text
    picking: null, // { prompt, done(id) } while a version is being picked
    marked: null, // a proposal's baseline, ringed
    hovered: null,
    expanded: new Set(), // newest ids of runs of edits shown one by one
    fetched: new Map(), // id -> promise of its files
    asked: new Map(), // id -> resolve, for files asked of the studio
  };
  let viewer = null; // the read-only editor and what draws on it, made on first use
  let closeTimer = null;
  const strip = $("timeline");

  const head = () => state.branches[state.current] ?? null;

  // The current branch's first-parent chain, oldest first.
  function chain() {
    const ids = [];
    for (let id = head(); id != null; id = state.versions.get(id)?.parents[0]) ids.push(id);
    return ids.reverse();
  }

  // A version's files, asked of the studio once.
  function filesOf(id) {
    if (!state.fetched.has(id)) {
      state.fetched.set(id, new Promise((resolve) => {
        state.asked.set(id, resolve);
        send({ t: "view-version", id });
      }));
    }
    return state.fetched.get(id);
  }

  // The strip ---------------------------------------------------------------

  // Open the strip; `briefly`, it closes again unless used.
  function open(briefly = false) {
    clearTimeout(closeTimer);
    strip.hidden = false;
    render();
    if (briefly) closeTimer = setTimeout(() => { if (!busy()) close(); }, AUTO_CLOSE_MS);
  }

  const busy = () => state.viewing || state.picking || state.marked || strip.matches(":hover");

  function close() {
    clearTimeout(closeTimer);
    if (state.viewing) back();
    state.picking = null;
    strip.hidden = true;
    renderChip();
  }
  strip.addEventListener("pointerenter", () => clearTimeout(closeTimer));

  // Viewing -----------------------------------------------------------------

  async function view(id) {
    if (id === head() && !state.against) return back();
    const versionFiles = await filesOf(id);
    viewer ??= await makeViewer();
    state.viewing = { id, files: versionFiles };
    $("editor").hidden = true;
    document.body.classList.add("viewing-version");
    $("viewer").hidden = false;
    showFile();
    open();
  }

  async function makeViewer() {
    const made = await createEditor($("viewer"), {
      readOnly: true,
      onChange() {},
      onEvaluate() {},
      onSave() {},
      onBreakpoints() {},
      snapBreakpoint: () => null,
      keysAt: () => "",
    });
    return { editor: made, inline: made.raw && createInlineDiff(made.raw) };
  }

  // Show the version's copy of the file open in the editor, or its main
  // file, marked with what differs from it to the text compared with.
  function showFile() {
    if (!state.viewing || !viewer) return;
    const { files: versionFiles } = state.viewing;
    const path = files.active() in versionFiles ? files.active() : state.main;
    state.viewing.path = path;
    const text = versionFiles[path] ?? "";
    viewer.editor.set(text);
    const target = (state.against?.files ?? files.texts())[path] ?? "";
    viewer.inline?.show(hunks(text, target).map((hunk) => ({ ...hunk, key: hunk.first, tone: "history" })));
  }

  function back() {
    state.viewing = null;
    state.against = null;
    changes.hide();
    $("viewer").hidden = true;
    $("editor").hidden = false;
    document.body.classList.remove("viewing-version");
    render();
  }

  // Pick a version for `done`, from the version graph.
  function pick(prompt, done) {
    state.picking = { prompt, done };
    open();
  }

  function clicked(node) {
    const id = node.ids.at(-1);
    if (node.ids.length > 1) {
      state.expanded.add(id);
      return render();
    }
    if (state.picking) {
      const { done } = state.picking;
      state.picking = null;
      render();
      return done(id);
    }
    view(id);
  }

  // Rendering -------------------------------------------------------------

  function render() {
    renderChip();
    if (strip.hidden) return;
    renderGraph();
    renderSlider();
    renderBanner();
  }

  function renderChip() {
    const chip = $("history-chip");
    const version = state.versions.get(state.viewing?.id ?? head());
    chip.hidden = !version;
    if (!version) return;
    const branch = Object.keys(state.branches).length > 1 || state.current !== "main" ? ` · ${state.current}` : "";
    chip.textContent = state.viewing ? `viewing v${version.id}` : `v${version.id}${branch}`;
    chip.title = `History: ${describe(version)}${version.forms_changed.length ? ` — ${summarize(version.forms_changed, 4)}` : ""}`;
    chip.setAttribute("aria-pressed", String(!strip.hidden));
  }

  function renderGraph() {
    const graph = versionGraph([...state.versions.values()], { current: state.current, branches: state.branches }, state.expanded);
    const box = $("version-graph");
    const width = 2 * 14 + Math.max(0, graph.nodes.length - 1) * COLUMN + 90;
    const height = 2 * 12 + Math.max(0, graph.lanes.length - 1) * LANE;
    const svg = svgNode("svg", { width, height });
    const at = new Map(graph.nodes.map((n) => [n.key, { x: 14 + n.col * COLUMN, y: 12 + n.lane * LANE }]));
    for (const { from, to } of graph.edges) {
      const a = at.get(from);
      const b = at.get(to);
      const d = a.y === b.y ? `M${a.x},${a.y} L${b.x},${b.y}`
        : `M${a.x},${a.y} C${a.x + COLUMN / 2},${a.y} ${b.x - COLUMN / 2},${b.y} ${b.x},${b.y}`;
      svg.append(svgNode("path", { d, class: "vedge" }));
    }
    const onChain = new Set(chain());
    const heads = new Map(Object.entries(state.branches).map(([name, id]) => [id, name]));
    for (const node of graph.nodes) {
      const id = node.ids.at(-1);
      const version = state.versions.get(id);
      const { x, y } = at.get(node.key);
      const classes = ["vnode", version.origin.kind];
      if (!onChain.has(id)) classes.push("off");
      if (state.viewing?.id === id || (!state.viewing && id === head())) classes.push("viewing");
      if (state.against?.id === id) classes.push("against");
      if (state.marked === id) classes.push("marked");
      const group = svg.appendChild(svgNode("g", { class: classes.join(" "), transform: `translate(${x},${y})` }));
      if (node.ids.length > 1) {
        group.append(svgNode("rect", { x: -9, y: -6, width: 18, height: 12, rx: 6 }));
        group.appendChild(svgNode("text", { y: 3.5 })).textContent = node.ids.length;
      } else {
        group.append(svgNode("circle", { r: version.origin.kind === "auto" ? 3.5 : 5 }));
      }
      group.appendChild(svgNode("title")).textContent = node.ids.length > 1
        ? `${node.ids.length} edits, v${node.ids[0]}–v${id}: ${summarize(node.ids.flatMap((i) => state.versions.get(i).forms_changed), 6)}. Click to show each.`
        : `v${id} · ${describe(version)} · ${formsOf(version)}`;
      if (heads.has(id)) {
        const name = heads.get(id);
        group.appendChild(svgNode("text", { x: 10, y: 4, class: `lane-name${name === state.current ? " current" : ""}` })).textContent = name;
      }
      group.addEventListener("click", () => clicked(node));
      group.addEventListener("pointerenter", () => { state.hovered = id; renderSlider(); });
      group.addEventListener("pointerleave", () => { state.hovered = null; renderSlider(); });
    }
    box.replaceChildren(svg);
    // the newest versions are where things happen
    if (!state.viewing) box.scrollLeft = box.scrollWidth;
  }

  function renderSlider() {
    const ids = chain();
    const slider = $("timeline-slider");
    slider.max = Math.max(0, ids.length - 1);
    const at = state.viewing ? ids.indexOf(state.viewing.id) : ids.length - 1;
    slider.value = at < 0 ? slider.max : at;
    slider.disabled = ids.length < 2;
    const shown = state.versions.get(state.hovered ?? state.viewing?.id ?? head());
    $("timeline-label").textContent = shown
      ? `${!state.hovered && !state.viewing ? "head · " : ""}v${shown.id} · ${describe(shown)} · ${formsOf(shown)} · ${ago(shown.created)}`
      : "";
  }

  function renderBanner() {
    $("picking").hidden = !state.picking;
    if (state.picking) $("picking-title").textContent = state.picking.prompt;
    const banner = $("viewing");
    banner.hidden = !state.viewing;
    if (!state.viewing) return;
    const { id, path } = state.viewing;
    const offChain = !chain().includes(id) ? " (not on this branch)" : "";
    const target = state.against ? `v${state.against.id}` : "the working text";
    $("viewing-title").textContent = `v${id}${offChain} · ${path}, read-only · marked: what changed from it to ${target}`;
    $("viewing-compare").textContent = state.against ? "Compare with the working text" : "Compare with…";
  }

  function formsOf(version) {
    return summarize(version.forms_changed, 4) || "no form changed";
  }

  // "rule→path, table:edge +3", naming forms of the main file without it.
  function summarize(keys, limit) {
    const prefix = `${state.main}:`;
    const names = [...new Set(keys.map((key) => key.startsWith(prefix) ? key.slice(prefix.length) : key))];
    const more = names.length - limit;
    return names.slice(0, limit).join(", ") + (more > 0 ? ` +${more}` : "");
  }

  // The change graph from the viewed version to what it is compared with.
  function showChanges() {
    const { id, files: before } = state.viewing;
    const after = state.against?.files ?? files.texts();
    changes.show({
      owner: "history",
      heading: `v${id} → ${state.against ? `v${state.against.id}` : "working text"}`,
      before: Object.values(before),
      after: Object.values(after),
      onNode(name) {
        const text = before[state.viewing?.path] ?? "";
        const form = relations(text).find((r) => r.name === name || r.heads?.includes(name));
        if (form) viewer.editor.reveal({ line: form.line, col: 1 });
      },
    });
  }

  // Controls ----------------------------------------------------------------

  $("history-chip").addEventListener("click", () => (strip.hidden ? open() : close()));
  $("timeline-close").addEventListener("click", close);
  $("timeline-slider").addEventListener("input", (event) => view(chain()[Number(event.target.value)]));
  $("viewing-restore").addEventListener("click", () => send({ t: "restore", id: state.viewing.id }));
  $("viewing-branch").addEventListener("click", () => send({ t: "branch", id: state.viewing.id }));
  $("viewing-back").addEventListener("click", back);
  $("viewing-graph").addEventListener("click", showChanges);
  $("viewing-compare").addEventListener("click", () => {
    if (state.against) {
      state.against = null;
      showFile();
      return render();
    }
    const id = state.viewing.id;
    pick(`Pick a version to compare v${id} with`, async (other) => {
      const otherFiles = await filesOf(other);
      if (state.viewing?.id !== id) return;
      state.against = { id: other, files: otherFiles };
      showFile();
      render();
      if (changes.shown()) showChanges();
    });
  });
  $("picking-cancel").addEventListener("click", () => {
    state.picking = null;
    render();
  });

  // Messages from the studio -----------------------------------------------

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
      // A restore or a new branch replaces what the editor shows, and is
      // worth a look at where it left the history.
      if (["revert", "branch"].includes(version.origin.kind)) {
        if (state.viewing) back();
        open(true);
      } else {
        render();
      }
    },
    "version-files"({ id, files: versionFiles }) {
      state.asked.get(id)?.(versionFiles);
      state.asked.delete(id);
    },
    files({ main }) {
      state.main = main;
      render();
    },
  };

  return {
    receive,
    open: () => open(),
    opened: showFile,
    filesOf,
    pick,
    // Ring a proposal's baseline in the graph, or none.
    mark(id) {
      state.marked = id;
      if (id != null) open();
      else if (!state.viewing) close();
    },
  };
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

function svgNode(tag, attributes = {}) {
  const node = document.createElementNS(SVG, tag);
  for (const [name, value] of Object.entries(attributes)) node.setAttribute(name, value);
  return node;
}
