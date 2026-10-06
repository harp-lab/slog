// The open project's files: the project switcher, the file list, the editor
// tabs, and the edits each file sends to the studio.
//
// The studio owns every file's text. This tab sends a file's whole text with
// the version it was edited from, and the studio takes it or refuses it with
// the current text. One edit is in flight at a time, and every message sent
// through `send` waits behind it, so each edit's base is a version the studio
// named, and a Run sent after typing sees the typing.

const $ = (id) => document.getElementById(id);
const EDIT_DELAY = 150;

// `onOpen(path)` is called when a file is shown in the editor, and
// `onSaved()` when what is saved or unsent may have changed.
export function createFiles({ editor, transmit, note, onOpen, onSaved }) {
  const state = {
    project: "",
    projects: [],
    main: "",
    directory: "",
    // path -> { text, version, local, saved }: `text` is the studio's at
    // `version`; `local` is this tab's, which runs ahead while edits are unsent.
    files: new Map(),
    breakpoints: new Map(), // path -> lines
    tabs: [], // open paths, in order
    active: null,
    editTimer: null,
    inFlight: null, // { path, text } of the unanswered edit
    held: [], // messages waiting behind it
  };

  // Sending ------------------------------------------------------------------

  function send(message) {
    if (state.inFlight) state.held.push(message);
    else transmit(message);
  }

  // Send the first unsent edit, else whatever was held behind the last one.
  function pump() {
    while (!state.inFlight) {
      const unsent = [...state.files].find(([, file]) => file.local !== file.text);
      if (unsent) {
        const [path, file] = unsent;
        state.inFlight = { path, text: file.local };
        transmit({ t: "edit", file: path, base: file.version, text: file.local });
      } else if (state.held.length) {
        transmit(state.held.shift());
      } else {
        break;
      }
    }
    render();
  }

  function changed() {
    clearTimeout(state.editTimer);
    state.editTimer = setTimeout(flush, EDIT_DELAY);
    renderSaved();
  }

  // Take the shown file's text now rather than after the edit delay.
  function flush() {
    if (state.editTimer === null) return;
    clearTimeout(state.editTimer);
    state.editTimer = null;
    const file = state.files.get(state.active);
    if (file) file.local = editor.get();
    pump();
  }

  // The answer to the edit in flight.
  function answered() {
    state.inFlight = null;
    pump();
  }

  // Showing ------------------------------------------------------------------

  function open(path) {
    const file = state.files.get(path);
    if (!file) return;
    flush();
    if (!state.tabs.includes(path)) state.tabs.push(path);
    state.active = path;
    editor.show(path, file.local);
    editor.setBreakpoints(state.breakpoints.get(path) ?? []);
    onOpen(path);
    render();
  }

  function close(path) {
    if (state.tabs.length === 1) return;
    state.tabs = state.tabs.filter((tab) => tab !== path);
    if (state.active === path) open(state.tabs.at(-1));
    else render();
  }

  // Take the studio's files. A file the studio still has at the version this
  // tab knows keeps this tab's unsent text.
  function load(main, files) {
    state.main = main;
    const known = state.files;
    state.files = new Map(files.map(({ path, text, version, saved }) => {
      const mine = known.get(path);
      const local = mine?.version === version ? mine.local : text;
      return [path, { text, version, local, saved }];
    }));
    for (const path of known.keys()) if (!state.files.has(path)) editor.forget(path);
    state.tabs = state.tabs.filter((path) => state.files.has(path));
    if (!state.tabs.length) state.tabs = [main];
    const active = state.files.has(state.active) ? state.active : state.tabs[0];
    state.active = null;
    clearTimeout(state.editTimer);
    state.editTimer = null;
    open(active);
    pump();
  }

  // The file of the project at an absolute path, or null.
  function pathOf(file) {
    const prefix = `${state.directory}/`;
    const path = file?.startsWith(prefix) ? file.slice(prefix.length) : null;
    return state.files.has(path) ? path : null;
  }

  // Rendering ----------------------------------------------------------------

  function render() {
    renderSaved();
    renderTabs();
    renderList();
  }

  const unsaved = (path, file) =>
    !file.saved || file.local !== file.text || (path === state.active && state.editTimer !== null);

  function renderSaved() {
    const dirty = [...state.files].some(([path, file]) => unsaved(path, file));
    const badge = $("saved");
    badge.textContent = dirty ? "unsaved" : "saved";
    badge.className = `badge${dirty ? " dirty" : ""}`;
    onSaved();
  }

  function renderTabs() {
    const tabs = $("tabs");
    tabs.replaceChildren(...state.tabs.map((path) => {
      const tab = button(`file-tab${path === state.active ? " active" : ""}`, path, () => open(path));
      tab.title = path === state.main ? `${path} — the main file, which Run evaluates` : path;
      if (unsaved(path, state.files.get(path))) tab.append(span("unsaved-dot", "●"));
      if (state.tabs.length > 1) {
        const x = tab.appendChild(span("close", "×"));
        x.title = "Close";
        x.addEventListener("click", (event) => { event.stopPropagation(); close(path); });
      }
      return tab;
    }));
  }

  function renderList() {
    const list = $("file-list");
    list.replaceChildren(...[...state.files.keys()].map((path) => {
      const row = button(`file-row${path === state.active ? " active" : ""}`, "", () => open(path));
      row.append(span("name", path));
      if (path === state.main) {
        row.append(span("main-mark", "main"));
      } else {
        row.append(action("main", "Make this the main file, which Run evaluates",
          () => send({ t: "set-main", path })));
      }
      row.append(action("rename", "Rename", () => {
        const to = window.prompt(`Rename ${path} to`, path);
        if (to && to !== path) send({ t: "rename-file", from: path, to: withSuffix(to) });
      }));
      if (path !== state.main) {
        row.append(action("delete", "Delete (it stays in the project's history)", () => {
          if (window.confirm(`Delete ${path}?`)) send({ t: "delete-file", path });
        }));
      }
      return row;
    }));
  }

  function renderProjects() {
    const select = $("project");
    select.replaceChildren(
      ...state.projects.map((name) => new Option(name, name, false, name === state.project)),
      new Option("New project…", ""),
    );
    select.title = `Project ${state.project}: ${state.directory}`;
  }

  // A project is its own page, `?project=NAME`; opening a name that does
  // not exist yet makes the project, holding an empty main.slog.
  $("project").addEventListener("change", (event) => {
    const name = event.target.value || window.prompt("Name the new project (letters, digits, - _ . @)");
    renderProjects(); // shown again if the choice is abandoned
    if (!name || name === state.project) return;
    const query = new URLSearchParams(location.search);
    query.set("project", name);
    location.search = query.toString(); // keeps the hash: local mode's token
  });

  $("new-file").addEventListener("click", () => {
    const path = window.prompt("Name the new file");
    if (path) send({ t: "new-file", path: withSuffix(path) });
  });

  // Messages from the studio -------------------------------------------------

  const receive = {
    init(snapshot) {
      // Whatever was in flight on a previous connection is answered by the
      // snapshot itself.
      state.inFlight = null;
      state.held = [];
      state.project = snapshot.project;
      state.projects = snapshot.projects;
      state.directory = snapshot.directory;
      state.breakpoints = new Map(Object.entries(snapshot.breakpoints));
      document.title = `${snapshot.project} — Slog Studio`;
      renderProjects();
      load(snapshot.main, snapshot.files);
    },
    files({ main, files }) {
      load(main, files);
    },
    ack({ file, version }) {
      const known = state.files.get(file);
      if (known && state.inFlight?.path === file) {
        Object.assign(known, { text: state.inFlight.text, version, saved: false });
      }
      answered();
    },
    // Our edit lost a race with another tab or a restore; theirs stands.
    reset({ file, version, text }) {
      const known = state.files.get(file);
      if (known) Object.assign(known, { text, version, local: text });
      if (file === state.active) editor.set(text);
      note(`${file} changed elsewhere; showing that version`);
      answered();
    },
    gone({ file }) {
      note(`${file} is no longer in the project; the edit was not kept`);
      answered();
    },
    text({ file, version, text }) {
      const known = state.files.get(file);
      if (!known) return;
      Object.assign(known, { text, version, local: text, saved: false });
      if (file === state.active) editor.set(text);
      render();
    },
    saved({ files }) {
      for (const [path, version] of Object.entries(files)) {
        const known = state.files.get(path);
        if (known?.version === version) known.saved = true;
      }
      render();
    },
    breakpoints({ file, lines }) {
      state.breakpoints.set(file, lines);
      if (file === state.active) editor.setBreakpoints(lines);
    },
  };

  return {
    send,
    changed,
    flush,
    receive,
    pathOf,
    active: () => state.active,
    // The main file's version, whether this tab has edits to it the studio
    // has not taken, and whether it is the file shown.
    mainState() {
      const main = state.files.get(state.main);
      const shown = state.active === state.main;
      return {
        version: main?.version,
        dirty: !main || main.local !== main.text || (shown && state.editTimer !== null),
        shown,
      };
    },
    project: () => state.project,
    setBreakpoints(lines) {
      state.breakpoints.set(state.active, lines);
      send({ t: "breakpoints", file: state.active, lines });
    },
    // Show a position in a project file, or do nothing for one elsewhere.
    reveal(span) {
      const path = pathOf(span.file);
      if (!path) return;
      open(path);
      editor.reveal(span);
    },
    mark(span, message) {
      const path = pathOf(span.file);
      if (!path) return;
      open(path);
      editor.mark(span, message);
    },
  };
}

function withSuffix(path) {
  return path.endsWith(".slog") ? path : `${path}.slog`;
}

function span(className, text) {
  return Object.assign(document.createElement("span"), { className, textContent: text });
}

function button(className, text, onClick) {
  const node = Object.assign(document.createElement("button"), { className, textContent: text });
  node.addEventListener("click", onClick);
  return node;
}

function action(text, title, onClick) {
  const node = span("file-action", text);
  node.title = title;
  node.addEventListener("click", (event) => { event.stopPropagation(); onClick(); });
  return node;
}
