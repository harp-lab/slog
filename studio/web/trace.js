// The Execution tab beside the REPL transcript: the latest run as it goes,
// and where it failed or holds (live.js's run view); then each traced change
// (a run, an add or del) as its strata and iterations, the signed rows
// behind each iteration, and a scrubber that steps through them, and
// replays them through the run view, while the editor highlights the rules
// that fired.
//
// A trace is the change record's `trace` field (docs/pausing.md §15, as
// compiler/session.rkt groups it): strata in run order, each with its
// iterations, each with the relations that iteration changed and the rules
// that fired in it. The model functions are pure; web/tests/trace.test.mjs
// runs them over captured payloads.

import { formAt, forms } from "./forms.js";
import { stamped } from "./stamp.js";
import { absorb, createRunView, outcome, replay as replayed, rulesWriting, shown } from "./live.js";

// ---- The model ------------------------------------------------------------

// Compiler temporaries and bookkeeping relations: counted, never sampled, and
// not shown (repl.rkt `internal-relation?`).
const internal = (name) => name.startsWith("$") || name.startsWith("temp") || name === "_enum";

const baseName = (path) => path.split("/").pop();

// The line a rule's location "reach.slog:14:1" names in `file`, or null when
// it is another file's.
export function ruleLine(loc, file) {
  const match = /^(.*):(\d+):\d+$/.exec(loc ?? "");
  return match && baseName(match[1]) === baseName(file) ? Number(match[2]) : null;
}

// The view model of one entry's trace, or null when its result carries none.
export function traceModel(entry, file) {
  const change = entry.result?.change;
  if (!change?.trace) return null;
  const strata = change.trace.strata.map((st, index) => {
    const iterations = st.iterations.map((it) => ({
      iteration: it.iteration,
      // an iteration that changed nothing has no relations: the fixpoint
      empty: it.relations.length === 0,
      relations: it.relations.filter((r) => !internal(r.relation)).map((r) => ({
        relation: r.relation,
        plus: r.plus,
        minus: r.minus,
        // derivations of rows already present: support moved, membership did not
        dups: r.dups,
        sizeAfter: r["size-after"],
        sample: r.sample,
        omitted: r["sample-omitted"],
      })),
      fired: it.rules.filter((rule) => rule.fires > 0).map((rule) => ({
        loc: rule.loc,
        line: ruleLine(rule.loc, file),
        tag: rule.tag,
        fires: rule.fires,
      })),
      parked: st.parks.some((park) => park.iteration === it.iteration),
    }));
    return {
      index,
      name: st.stratum,
      flavor: st.flavor,
      ms: st.fixpoint?.ms ?? null,
      iterations,
      // the relations it changed; the trace does not list unchanged writes
      writes: [...new Set(iterations.flatMap((it) => it.relations.map((r) => r.relation)))],
    };
  });
  return {
    line: entry.line,
    operation: change.operation,
    strata,
    dropped: change.trace.dropped,
    maintenance: maintenance(change, strata),
  };
}

// Strata × iterations. A cell is null past its stratum's last iteration;
// the fixpoint is each stratum's first empty iteration.
export function grid(model) {
  const width = Math.max(0, ...model.strata.map((st) => st.iterations.length));
  return {
    width,
    rows: model.strata.map((st) => {
      const fixpoint = st.iterations.findIndex((it) => it.empty);
      return Array.from({ length: width }, (_, i) => {
        const it = st.iterations[i];
        return it && {
          deltas: it.relations.map(({ relation, plus, minus, dups }) => ({ relation, plus, minus, dups })),
          fixpoint: i === fixpoint,
          parked: it.parked,
        };
      });
    }),
  };
}

// Every recorded iteration in run order, as [stratum, iteration] indices:
// the positions the scrubber steps through.
export function steps(model) {
  return model.strata.flatMap((st, s) => st.iterations.map((_, i) => [s, i]));
}

// For an add or del: the lazy count round, the maintenance flavors, each
// relation's signed change across them, and where a deletion's maintenance
// re-derived rows (DRed re-founding, or support re-established for a row
// that stays).
export function maintenance(change, strata) {
  if (change.operation !== "add" && change.operation !== "del") return null;
  const totals = (list) => {
    const sums = new Map();
    for (const st of list) {
      for (const it of st.iterations) {
        for (const r of it.relations) {
          const sum = sums.get(r.relation) ?? { relation: r.relation, plus: 0, minus: 0, dups: 0 };
          sum.plus += r.plus;
          sum.minus += r.minus;
          sum.dups += r.dups;
          sums.set(r.relation, sum);
        }
      }
    }
    return [...sums.values()];
  };
  const counting = strata.filter((st) => st.flavor === "count");
  const maintaining = strata.filter((st) => st.flavor !== "count");
  const rederived = maintaining
    .filter((st) => /neg$/.test(st.flavor))
    .flatMap((st) => st.iterations.flatMap((it) => it.relations
      .filter((r) => r.plus > 0 || r.dups > 0)
      .map((r) => ({ stratum: st.index, iteration: it.iteration, relation: r.relation, plus: r.plus, dups: r.dups }))));
  return {
    requested: (change.requested ?? []).map((r) => ({ relation: r.relation, added: r.added, removed: r.removed })),
    routes: (change.routes ?? []).map((route) => [route.kind, ...route.detail].join(" ")),
    // `_count` strata re-count rows already there; they change nothing
    counted: totals(counting).map(({ relation, plus }) => ({ relation, rows: plus })),
    flavors: [...new Set(maintaining.map((st) => st.flavor))],
    changes: totals(maintaining),
    rederived,
  };
}

// "+3 −1 ~2", or "" when nothing moved.
export function signed({ plus, minus, dups }) {
  return [plus && `+${plus}`, minus && `−${minus}`, dups && `~${dups}`].filter(Boolean).join(" ");
}

// "717a6082 · iteration 2 · phase read", a paused result's first line, as
// the stratum and iteration it names.
export function parkedAt(lines) {
  const match = /^(\S+) · iteration (\d+) · phase (\S+)/.exec(lines?.[0] ?? "");
  return match && { name: match[1], iteration: Number(match[2]), phase: match[3] };
}

// ---- The view -------------------------------------------------------------

const RECORDS = 20;
// The scrubber's replay takes about this long, however many steps.
const REPLAY_MS = 4000;

const node = (tag, className, text) => {
  const element = document.createElement(tag);
  if (className) element.className = className;
  if (text !== undefined) element.textContent = text;
  return element;
};

// `editor` is editor.js's; `send` sends a request to the studio; `file()`
// is the path of the file the editor shows, whose rules it can shade.
// `tabs`, `transcript` and `results` are the result tab strip and the two
// panels it switches between (results.js). `reveal(span)` shows a place in
// the project's files, and `ask(entry)` opens the REPL assistant about a
// failed entry. Returns `entry(entry)`, fed every REPL entry, which says
// whether the Execution tab, shown, is what the entry was about: a run, a
// traced change, a pause, a peek; `progress(delta)`, fed the studio's
// progress messages; `started()`, when a Run or Debug starts; and
// `tracing(on)`.
export function initTrace({ editor, send, file, tabs, transcript, results, reveal, ask }) {
  // Whether plain Runs record a trace; Debug always does. Tracing costs a
  // Run noticeably, so it is the author's choice.
  const recording = node("label", "trace-toggle");
  const box = recording.appendChild(node("input"));
  box.type = "checkbox";
  recording.append(" Trace every Run");
  recording.title = "Debug always records a trace; tracing every Run makes Run slower";
  box.addEventListener("change", () => send({ t: "trace", on: box.checked }));
  const state = {
    records: [],   // [{ model, steps }], newest first
    shown: 0,      // the record on screen
    step: 0,       // its scrubber position
    parked: null,  // where the session's held run stands, from its pause
    peek: null,    // the last peek at it: { title, lines }
    live: null,    // the latest run's progress (live.js absorb)
    run: null,     // the entry that answered the latest run, held or not
    selected: null, // the stratum clicked in the run view
    replaying: false, // the run view shows the record at the scrubber
    timer: 0,      // the scrubber's replay, while it plays
    starting: false, // a Run or Debug started, and has run nothing yet
  };
  const view = createRunView({
    select(index) {
      state.selected = index;
      paint();
      shade();
    },
    reveal: (span) => reveal(span),
    ask: () => state.run && ask(state.run),
    command: (line) => send({ t: "command", line }),
  });

  // A tab after Transcript in the strip results.js keeps, and the panel it
  // shows in place of the transcript or a result set. Whichever of those
  // shows itself again hides the panel.
  const panel = node("div", "execution");
  panel.hidden = true;
  panel.tabIndex = 0;
  transcript.after(panel);
  const executionTab = node("button", "rs-tab", "Execution");
  executionTab.title = "The latest run as it goes, where it failed, and each traced change's iterations";
  tabs.firstElementChild.after(executionTab);
  // the run's state at a glance from any tab: running, failed, held, or a
  // trace not yet seen
  const fresh = executionTab.appendChild(node("span", "fresh"));
  fresh.hidden = true;
  executionTab.addEventListener("click", () => {
    transcript.hidden = true;
    results.hidden = true;
    panel.hidden = false;
    for (const tab of tabs.querySelectorAll(".rs-tab")) tab.setAttribute("aria-selected", String(tab === executionTab));
    render();
  });
  const yielded = new MutationObserver(() => {
    if (panel.hidden || (transcript.hidden && results.hidden)) return;
    panel.hidden = true;
    executionTab.setAttribute("aria-selected", "false");
    stopReplay();
    editor.highlight([]);
  });
  for (const other of [transcript, results]) yielded.observe(other, { attributes: true, attributeFilter: ["hidden"] });

  panel.addEventListener("keydown", (event) => {
    if (event.key === "ArrowLeft") move(-1);
    else if (event.key === "ArrowRight") move(1);
    else return;
    event.preventDefault();
  });

  function move(by) {
    const record = state.records[state.shown];
    if (!record) return;
    stopReplay();
    state.step = Math.max(0, Math.min(record.steps.length - 1, state.step + by));
    state.replaying = true;
    render();
  }

  function select(s, i) {
    const record = state.records[state.shown];
    stopReplay();
    state.step = record.steps.findIndex(([a, b]) => a === s && b === i);
    state.replaying = true;
    render();
  }

  // Play the shown record's steps from the first, through the run view.
  function replay() {
    const record = state.records[state.shown];
    if (!record?.steps.length) return;
    stopReplay();
    state.step = 0;
    state.replaying = true;
    const every = Math.max(60, Math.min(400, REPLAY_MS / record.steps.length));
    const advance = () => {
      const more = state.step < record.steps.length - 1;
      state.timer = more ? setTimeout(() => {
        state.step++;
        advance();
      }, every) : 0;
      render();
    };
    advance();
  }

  function stopReplay() {
    clearTimeout(state.timer);
    state.timer = 0;
  }

  // The rules that fired in the selected iteration, as editor forms less
  // the blank lines that end them.
  function highlight(iteration) {
    const text = editor.get();
    const lines = text.split("\n");
    const found = forms(text);
    const fired = iteration?.fired.map((rule) => rule.line).filter((line) => line !== null) ?? [];
    editor.highlight([...new Set(fired)].map((line) => formAt(found, line)).filter(Boolean).map((form) => {
      let to = form.endLine;
      while (to > form.line && !lines[to - 1]?.trim()) to--;
      return { from: form.line, to };
    }));
  }

  // The form a compile error is in, when it is the shown file's.
  function shadeError(span) {
    const text = editor.get();
    const form = span.file.split("/").pop() === file().split("/").pop() && formAt(forms(text), span.line);
    if (!form) return highlight(null);
    const lines = text.split("\n");
    let to = form.endLine;
    while (to > form.line && !lines[to - 1]?.trim()) to--;
    editor.highlight([{ from: form.line, to, tone: "error" }]);
  }

  // The rules of the stratum clicked in the run view: those that write its
  // relations.
  function shade() {
    const model = runModel();
    const st = model && state.selected !== null ? shown(model)[state.selected] : null;
    if (!st) return highlight(null);
    const text = editor.get();
    const lines = text.split("\n");
    editor.highlight(rulesWriting(text, st.sizes.map(([relation]) => relation)).map(({ from, to }) => {
      while (to > from && !lines[to - 1]?.trim()) to--;
      return { from, to };
    }));
  }

  // What the run view shows: the shown record at the scrubber while
  // replaying, else the latest run.
  function runModel() {
    const record = state.records[state.shown];
    if (state.replaying && record?.steps.length) return replayed(record.model, record.steps[state.step]);
    return latest();
  }

  // The latest run. Every command is in flight a while, a query too: the
  // run is running only once a stratum of the command has run, and
  // compiling only while a Run or Debug has run none yet.
  function latest() {
    const live = state.live;
    return live && { ...live, running: live.running && !live.compiling, compiling: live.compiling && state.starting };
  }

  // The run view repaints at most once a frame, and only while shown.
  let painting = 0;
  function paint() {
    badge();
    if (panel.hidden || painting) return;
    painting = requestAnimationFrame(() => {
      painting = 0;
      view.show(runModel(), {
        text: editor.get(),
        selected: state.selected,
        failure: state.replaying ? null : outcome(state.run, latest(), state.parked),
      });
    });
  }

  // The tab's dot: the run's state while another tab is shown.
  function badge() {
    const live = latest();
    const failure = outcome(state.run, live, state.parked);
    const running = (live?.running || live?.compiling) && !failure;
    const tone = running ? "running" : failure?.kind === "held" ? "held"
      : failure && failure.kind !== "aborted" ? "failed" : fresh.dataset.tone === "trace" ? "trace" : "";
    fresh.dataset.tone = tone;
    fresh.hidden = !tone || (!panel.hidden && tone === "trace");
  }

  function render() {
    if (panel.hidden) return paint(); // the tab's dot, at least
    if (fresh.dataset.tone === "trace") fresh.dataset.tone = "";
    const record = state.records[state.shown];
    if (state.replaying && !record) state.replaying = false;
    // the run view stays put, so its animations run on
    if (panel.firstChild !== recording || recording.nextSibling !== view.element) panel.replaceChildren(recording, view.element);
    else while (view.element.nextSibling) view.element.nextSibling.remove();
    paint();
    if (state.peek && state.parked) panel.append(renderParked());
    const failure = state.replaying ? null : outcome(state.run, latest(), state.parked);
    if (failure?.kind === "compile") shadeError(failure.span);
    if (!record) {
      if (!state.live && !state.run) {
        panel.append(node("p", "hint", "Run the program: its strata appear here as they run. Debug it, or Run with tracing on, to step through each iteration's rows."));
      }
      if (state.selected === null && failure?.kind !== "compile") highlight(null);
      return;
    }
    panel.append(renderHead(record));
    const { model } = record;
    if (model.maintenance) panel.append(renderMaintenance(model));
    const [s, i] = record.steps[state.step] ?? [];
    panel.append(renderGrid(model, s, i));
    if (s !== undefined) {
      const stratum = model.strata[s];
      panel.append(renderZset(stratum, stratum.iterations[i], record.at));
      if (state.replaying || (state.selected === null && failure?.kind !== "compile")) highlight(stratum.iterations[i]);
    }
  }

  function renderHead(record) {
    const head = node("div", "trace-head");
    head.append(node("span", "trace-caption", "Traced changes"));
    const choose = head.appendChild(node("select"));
    choose.title = "The traced changes of this session, newest first";
    state.records.forEach(({ model }, index) => {
      // a command names files by their paths; the base name is enough here
      const option = choose.appendChild(node("option", null, model.line.replace(/\S*\//g, "")));
      option.value = String(index);
      option.selected = index === state.shown;
    });
    choose.addEventListener("change", () => {
      stopReplay();
      state.shown = Number(choose.value);
      state.step = 0;
      render();
    });
    const back = head.appendChild(node("button", "secondary small", "◀"));
    back.title = "The previous iteration (←)";
    back.disabled = state.step === 0;
    back.addEventListener("click", () => move(-1));
    const [s, i] = record.steps[state.step] ?? [];
    const where = s === undefined ? "no iterations"
      : `stratum ${s + 1} of ${record.model.strata.length} · iteration ${i + 1} of ${record.model.strata[s].iterations.length}`;
    head.append(node("span", "where", where));
    const forward = head.appendChild(node("button", "secondary small", "▶"));
    forward.title = "The next iteration (→)";
    forward.disabled = state.step >= record.steps.length - 1;
    forward.addEventListener("click", () => move(1));
    const play = head.appendChild(node("button", "secondary small", state.timer ? "■ stop" : "⟲ replay"));
    play.title = "Play the change's iterations through the run view above";
    play.disabled = !record.steps.length;
    play.addEventListener("click", () => {
      if (state.timer) {
        stopReplay();
        render();
      } else replay();
    });
    if (state.replaying && !state.timer) {
      const latest = head.appendChild(node("button", "secondary small", "latest run"));
      latest.title = "Show the latest run above again";
      latest.addEventListener("click", () => {
        state.replaying = false;
        render();
      });
    }
    if (record.model.dropped > 0) {
      head.append(node("span", "warn", `${record.model.dropped} sample rows dropped at the 16 MB cap`));
    }
    return head;
  }

  // The stratum list and its iteration grid, one row per stratum.
  function renderGrid(model, selectedStratum, selectedIteration) {
    const { width, rows } = grid(model);
    const scroll = node("div", "grid-scroll");
    const table = scroll.appendChild(node("table", "grid"));
    const head = table.appendChild(node("tr"));
    for (const heading of ["stratum", "flavor", "ms", "changes"]) head.append(node("th", null, heading));
    for (let i = 1; i <= width; i++) head.append(node("th", "n", String(i)));
    model.strata.forEach((st, s) => {
      const tr = table.appendChild(node("tr"));
      tr.append(node("td", "name", st.name ?? `s${s + 1}`));
      const flavor = tr.appendChild(node("td", "flavor", st.flavor));
      flavor.dataset.flavor = st.flavor;
      tr.append(node("td", "n", st.ms === null ? "" : st.ms.toFixed(1)));
      tr.append(node("td", "writes", st.writes.join(" ")));
      rows[s].forEach((cell, i) => {
        const td = tr.appendChild(node("td", "cell"));
        if (!cell) return;
        td.classList.toggle("selected", s === selectedStratum && i === selectedIteration);
        td.classList.toggle("fixpoint", cell.fixpoint);
        td.classList.toggle("parked", cell.parked);
        if (cell.fixpoint) td.title = "fixpoint: nothing changed";
        if (cell.parked) td.title = "the run paused in this iteration";
        for (const delta of cell.deltas) {
          const text = signed(delta) || "±0";
          td.append(node("div", delta.minus > 0 ? "minus" : delta.plus > 0 ? "plus" : "support",
            st.writes.length > 1 ? `${delta.relation} ${text}` : text));
        }
        td.addEventListener("click", () => select(s, i));
      });
    });
    return scroll;
  }

  // The selected iteration's signed rows, per relation, and its fired rules.
  function renderZset(stratum, iteration, at) {
    const box = node("div", "zset");
    box.append(node("div", "zset-title",
      `${stratum.name ?? `stratum ${stratum.index + 1}`} · ${stratum.flavor} · iteration ${iteration.iteration}`));
    if (iteration.empty) box.append(node("div", "note", "Nothing changed: the stratum's fixpoint."));
    const parkedHere = state.parked && state.parked.name === stratum.name && state.parked.iteration === iteration.iteration;
    for (const r of iteration.relations) {
      const head = box.appendChild(node("div", "zset-relation"));
      head.append(stamped(r.relation, at, { className: "relation" }), node("span", "counts", signed(r) || "±0"));
      head.append(node("span", "note", `size ${r.sizeAfter}`));
      if (parkedHere) {
        const all = head.appendChild(node("button", "secondary small", "show all"));
        all.title = `peek ${r.relation}: the held run's delta here`;
        all.addEventListener("click", () => send({ t: "command", line: `peek ${r.relation} 1000` }));
      }
      for (const row of r.sample) {
        const line = box.appendChild(node("div", "zset-row"));
        line.append(node("span", `sign ${row.sign === "+" ? "plus" : "minus"}`, row.sign === "+" ? "+" : "−"));
        line.append(node("span", "row", `(${r.relation} ${row.row})`));
        if (row.kind !== "none") line.append(node("span", `kind ${row.kind}`, row.kind));
      }
      const unsampled = r.plus + r.minus - r.sample.length;
      if (unsampled > 0) box.append(node("div", "note", `${unsampled} more not sampled`));
      if (r.dups > 0) {
        box.append(node("div", "note", `${r.dups} derivation${r.dups === 1 ? "" : "s"} of rows already present: support changed, membership did not`));
      }
    }
    if (iteration.fired.length) {
      const fired = box.appendChild(node("div", "fired"));
      fired.append(node("span", "note", "fired:"));
      for (const rule of iteration.fired) {
        const link = fired.appendChild(node("a", null, `${rule.loc} ×${rule.fires}`));
        link.title = rule.tag;
        if (rule.line !== null) link.addEventListener("click", () => editor.reveal({ line: rule.line, col: 1 }));
      }
    }
    return box;
  }

  function renderMaintenance(model) {
    const m = model.maintenance;
    const box = node("div", "maintenance");
    const facts = [
      ["requested", m.requested.map((r) => `${r.relation} ${signed({ plus: r.added, minus: r.removed }) || "±0"}`).join(", ")],
      ["route", m.routes.join(", ") || "none"],
      ["count round", m.counted.length
        ? m.counted.map((c) => `${c.relation} ${c.rows}`).join(", ") + " rows counted"
        : "none: counts were already established"],
      ["maintenance", m.flavors.join(", ") || "none"],
      ["changes", m.changes.map((c) => `${c.relation} ${signed(c) || "±0"}`).join(", ") || "none"],
    ];
    if (m.rederived.length) {
      facts.push(["re-derived", m.rederived.map((r) =>
        `${r.relation} ${signed({ plus: r.plus, minus: 0, dups: r.dups })} in iteration ${r.iteration}`).join(", ")]);
    }
    for (const [label, text] of facts) {
      box.append(node("span", "label", label), node("span", null, text));
    }
    return box;
  }

  // A peek at the held run (the run view's card says where it holds).
  function renderParked() {
    const box = node("div", "parked-card");
    box.append(node("div", "note", state.parked.phase === "iter"
      ? "Its delta is final here: show all lists every row."
      : "Inside a read, peek shows the pending candidates, not yet deduplicated."));
    if (state.peek) box.append(node("pre", "lines", [state.peek.title, ...state.peek.lines].join("\n")));
    return box;
  }

  return {
    tracing(on) {
      box.checked = on;
    },
    // A Run or Debug started: the run view follows it from here.
    started() {
      stopReplay();
      if (!panel.hidden) editor.highlight([]);
      state.starting = true;
      state.run = null;
      state.selected = null;
      state.replaying = false;
      paint();
    },
    progress(delta) {
      const before = state.live;
      state.live = absorb(before, delta);
      if (before && state.live.run !== before.run) {
        // a new run: what was said of the last no longer holds
        state.starting = false;
        state.selected = null;
        if (!state.timer) state.replaying = false;
        // another command's answer is the last run's (this run's own may
        // have come first)
        if (state.run && state.run.line !== state.live.command) state.run = null;
      }
      paint();
    },
    entry(entry) {
      const result = entry.result;
      // the entry that answered a run, or moved a held one on
      const ran = entry.line === state.live?.command || result?.change || result?.kind === "paused"
        || /^(run|check|save|add|del|continue|commit|abort|finish|step)\b/.test(entry.line);
      if (ran && (entry.origin === "evaluate" || result?.change || result?.kind === "paused" || entry.error
        || /^Aborted/.test(result?.title ?? ""))) {
        state.run = entry;
        state.starting = false;
      }
      if (!result) {
        render();
        return !panel.hidden && state.run === entry;
      }
      if (result.kind === "paused") {
        state.parked = parkedAt(result.lines);
        state.peek = null;
        // An earlier trace of the same strata (content-hashed, so the same
        // program) shows the iteration the run holds in.
        const at = state.parked ? state.records.findIndex(({ model }) =>
          model.strata.some((st) => st.name === state.parked.name)) : -1;
        if (at >= 0) {
          const { model, steps } = state.records[at];
          const step = steps.findIndex(([s, i]) => model.strata[s].name === state.parked.name
            && model.strata[s].iterations[i].iteration === state.parked.iteration);
          if (step >= 0) [state.shown, state.step] = [at, step];
        }
      } else if (result.held === false) {
        state.parked = null;
        state.peek = null;
      }
      if (result.kind === "peek") state.peek = { title: result.title, lines: result.lines };
      const model = traceModel(entry, file());
      if (model) {
        state.records = [{ model, steps: steps(model), at: entry.state }, ...state.records].slice(0, RECORDS);
        state.shown = 0;
        state.step = 0;
        if (panel.hidden) fresh.dataset.tone = "trace";
      }
      render();
      return !panel.hidden && (model !== null || result.kind === "paused" || result.kind === "peek" || state.run === entry);
    },
  };
}
