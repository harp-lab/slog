// The Execution tab's run view (trace.js shows it): the latest run as the
// session server reports it while it runs (docs/pausing.md §16), drawn as a
// time strip of its strata, a convergence curve per stratum, a growth bar
// per relation and the flow of relations from stratum to stratum; and, when
// the run fails or holds, where and why.
//
// Progress arrives as the studio's `progress` messages (trace.rs), each the
// session server's live state (repl.rkt `run-progress`) with only the
// strata the studio had not yet sent: `strata` from index `from` on, the
// stratum running in `current`. A traced change replays through the same
// view (`replay`), one recorded iteration at a time.
//
// The model functions are pure; web/test/live.test.js runs them.

import { forms } from "./forms.js";
import { tokens } from "./lexer.js";

// ---- The model ------------------------------------------------------------

// The most points a convergence curve keeps; past it every other one goes.
const CURVE_POINTS = 240;

const stratum = (st) => ({
  scc: st.scc,
  hash: st.hash,
  flavor: st.flavor,
  iterations: st.iterations ?? st.iteration ?? 0,
  ms: st.ms ?? 0,
  tuples: st.tuples ?? null,
  sizes: st.sizes ?? [],
  reads: st.reads ?? [],
});

function addPoint(curves, index, point) {
  const curve = curves[index] ?? (curves[index] = []);
  const last = curve.at(-1);
  if (last && last.iteration === point.iteration && last.tuples === point.tuples) return;
  curve.push(point);
  if (curve.length > CURVE_POINTS) curves[index] = curve.filter((_, i) => i % 2 === 0 || i === curve.length - 1);
}

// The live run after `delta`, a `progress` message, arrives: a new run when
// its number moved, else the same run further on. (A curve the last model
// holds may grow in place: the last model is done with.)
export function absorb(live, delta) {
  const fresh = !live || delta.run !== live.run;
  const strata = fresh ? [] : live.strata.slice(0, delta.from ?? 0);
  const from = strata.length;
  strata.push(...(delta.strata ?? []).map(stratum));
  const curves = fresh ? [] : live.curves.slice(0, strata.length + 1);
  (delta.strata ?? []).forEach((st, k) => {
    if (st.tuples !== null && st.tuples !== undefined) {
      addPoint(curves, from + k, { iteration: st.iterations, tuples: st.tuples, ms: st.ms });
    }
  });
  const current = delta.current ? stratum(delta.current) : null;
  // a pause names the iteration it holds in, which the last report may trail
  if (current && delta.paused && delta.paused.scc === current.scc) {
    current.iterations = Math.max(current.iterations, delta.paused.iteration ?? 0);
  }
  if (current) addPoint(curves, strata.length, { iteration: current.iterations, tuples: current.tuples, ms: current.ms });
  return {
    run: delta.run,
    command: delta.command ?? "",
    running: Boolean(delta.running),
    // a command is in flight that has run no stratum yet
    compiling: Boolean(delta.compiling),
    elapsed: delta.elapsed ?? 0,
    strata,
    current,
    paused: delta.paused ?? null,
    error: delta.error ?? null,
    curves,
  };
}

// Every stratum shown, finished ones first, the running one last, each with
// its position, and whether it is running still or stopped where the run
// stopped (held, failed or aborted).
export function shown(live) {
  const all = live.strata.map((st, index) => ({ ...st, index, active: false, stopped: false }));
  if (live.current) all.push({ ...live.current, index: all.length, active: live.running, stopped: !live.running });
  return all;
}

// Strata, iterations, rows derived and time, over the whole run.
export function totals(live) {
  const all = shown(live);
  return {
    strata: all.length,
    iterations: all.reduce((sum, st) => sum + st.iterations, 0),
    rows: all.reduce((sum, st) => sum + (st.tuples ?? 0), 0),
    ms: all.reduce((sum, st) => sum + st.ms, 0),
  };
}

// The time strip: one segment per stratum, as wide as its share of the
// run's time, with runs of strata too narrow to see merged into one.
// [{ first, last, flavor, ms, share, active, stopped }]
export function segments(live, narrowest = 0.006) {
  const all = shown(live);
  const total = all.reduce((sum, st) => sum + st.ms, 0) || 1;
  const out = [];
  for (const st of all) {
    const share = st.ms / total;
    const previous = out.at(-1);
    if (previous && !st.active && !st.stopped && !previous.active && !previous.stopped
      && share < narrowest && previous.share < narrowest * 2) {
      previous.last = st.index;
      previous.ms += st.ms;
      previous.share += share;
      if (previous.flavor !== st.flavor) previous.flavor = "mixed";
      continue;
    }
    out.push({ first: st.index, last: st.index, flavor: st.flavor, ms: st.ms, share, active: st.active, stopped: st.stopped });
  }
  return out;
}

// Each relation's size, as the latest stratum that writes it last said:
// [{ relation, size, stratum, share }], largest first; `share` of the
// largest.
export function bars(live) {
  const sizes = new Map();
  for (const st of shown(live)) {
    for (const [relation, size] of st.sizes) sizes.set(relation, { relation, size, stratum: st.index });
  }
  const list = [...sizes.values()].sort((a, b) => b.size - a.size || a.relation.localeCompare(b.relation));
  const largest = Math.max(1, ...list.map((bar) => bar.size));
  return list.map((bar) => ({ ...bar, share: bar.size / largest }));
}

// The relations each stratum hands on: an edge from the latest earlier
// stratum that writes a relation to each stratum that reads it.
// [{ from, to, relations }]
export function flows(live) {
  const all = shown(live);
  const writer = new Map();
  const edges = new Map();
  for (const st of all) {
    for (const relation of st.reads) {
      const from = writer.get(relation);
      if (from === undefined || from === st.index) continue;
      const key = `${from}>${st.index}`;
      const edge = edges.get(key) ?? { from, to: st.index, relations: [] };
      edge.relations.push(relation);
      edges.set(key, edge);
    }
    for (const [relation] of st.sizes) writer.set(relation, st.index);
  }
  return [...edges.values()];
}

// A convergence curve as an SVG path `width` × `height`: rows derived
// against iteration, rising to the fixpoint.
export function sparkline(points, width, height) {
  if (!points?.length) return "";
  const last = points.at(-1);
  const xs = Math.max(1, last.iteration);
  const ys = Math.max(1, ...points.map((p) => Math.abs(p.tuples)));
  const at = (p) => `${((p.iteration / xs) * width).toFixed(1)} ${(height - (Math.abs(p.tuples) / ys) * (height - 1) - 0.5).toFixed(1)}`;
  const start = { iteration: 0, tuples: 0 };
  return `M${[start, ...points].map(at).join(" L")}`;
}

// Relations a finished run left empty that the program names: worth a
// quiet word, since a relation that stayed empty is often a rule that
// never matched. Relations the program does not name (the runtime's
// error relations) are not its business.
export function stayedEmpty(live, text) {
  if (live.running || live.error || live.current) return [];
  const named = new Set();
  for (const token of tokens(text ?? "")) {
    if (token.kind === "word") named.add(text.slice(token.start, token.end));
  }
  return bars(live).filter((bar) => bar.size === 0 && named.has(bar.relation)).map((bar) => bar.relation);
}

// The lines of the rules in `text` whose heads are among `relations`, as
// { from, to } ranges for the editor to shade.
export function rulesWriting(text, relations) {
  const wanted = new Set(relations);
  const ranges = [];
  for (const form of forms(text)) {
    if (form.keyword !== "rule" || !wanted.size) continue;
    const clauses = [];
    let depth = 0;
    let arrow = null;
    let head = false;
    for (const token of tokens(text.slice(form.start, form.end))) {
      const word = token.kind === "word" ? text.slice(form.start + token.start, form.start + token.end) : null;
      if (token.kind === "open") {
        depth++;
        head = depth === 1;
      } else if (token.kind === "close") {
        depth = Math.max(0, depth - 1);
      } else if (word !== null) {
        if (depth === 0 && (word === "-->" || word === "<--")) arrow = { word, at: clauses.length };
        else if (head) clauses.push(word);
        head = false;
      }
    }
    const heads = !arrow ? clauses : arrow.word === "-->" ? clauses.slice(arrow.at) : clauses.slice(0, arrow.at);
    if (heads.some((name) => wanted.has(name))) ranges.push({ from: form.line, to: form.endLine });
  }
  return ranges;
}

// "file.slog:12:3: …", a message's leading location.
export function locate(message) {
  const match = /^(\S+?):(\d+):(\d+):/.exec(message ?? "");
  return match && { file: match[1], line: Number(match[2]), col: Number(match[3]) };
}

// What became of the run `entry` answered, for the failure card:
//   { kind: "compile", message, span }   nothing ran
//   { kind: "runtime", message, at }     it died in a stratum
//   { kind: "held", title, at }          it stopped at a pause
//   { kind: "aborted", title }           the held run was discarded
//   { kind: "error", message }           it failed otherwise
// or null when it finished. `live` is the progress so far; `parked` where a
// held run stands (trace.js parkedAt).
export function outcome(entry, live, parked = null) {
  if (!entry) return null;
  const result = entry.result;
  if (/^Aborted/.test(result?.title ?? "")) return { kind: "aborted", title: result.title };
  if (result?.kind === "paused") {
    return { kind: "held", title: result.title ?? "Paused", at: parked, interrupted: /interrupt/i.test(result.title ?? "") };
  }
  const error = entry.error;
  if (!error) return null;
  const message = error.message ?? "";
  const span = error.span ?? locate(message);
  if (span && !(live?.error === message)) return { kind: "compile", message, span };
  const died = live && (live.error === message || /daemon|fatal|out of memory|EOF/i.test(message));
  if (died) {
    const st = live.current ?? live.strata.at(-1) ?? null;
    return {
      kind: "runtime",
      message,
      at: st && { index: live.current ? live.strata.length : live.strata.length - 1, ...st },
    };
  }
  return { kind: "error", message };
}

// The live model of a traced change as it stood after `step` (trace.js
// `steps`): the strata before it finished, its own running at that
// iteration, sizes and curves from the recorded counts. The run view shows
// a traced change this way, so the scrubber replays it.
export function replay(model, [s, i]) {
  const strata = [];
  const curves = [];
  let current = null;
  model.strata.forEach((st, index) => {
    if (index > s) return;
    const upto = index < s ? st.iterations.length : i + 1;
    const sizes = new Map();
    let tuples = 0;
    const curve = [];
    st.iterations.slice(0, upto).forEach((it, k) => {
      for (const r of it.relations) {
        sizes.set(r.relation, r.sizeAfter);
        tuples += r.plus - r.minus;
      }
      curve.push({ iteration: k + 1, tuples, ms: 0 });
    });
    for (const relation of st.writes) if (!sizes.has(relation)) sizes.set(relation, 0);
    const ms = st.ms === null ? 0 : st.ms * (upto / Math.max(1, st.iterations.length));
    const entry = { scc: index, hash: st.name, flavor: st.flavor, iterations: upto, ms, tuples, sizes: [...sizes], reads: [] };
    curves[index] = curve;
    if (index < s) strata.push(entry);
    else current = entry;
  });
  return { run: -1, command: model.line, running: true, replaying: true, elapsed: 0, strata, current, paused: null, error: null, curves };
}

// ---- Numbers --------------------------------------------------------------

export function count(n) {
  if (n === null || n === undefined) return "";
  const size = Math.abs(n);
  if (size >= 1e9) return `${(n / 1e9).toFixed(1)}B`;
  if (size >= 1e6) return `${(n / 1e6).toFixed(size >= 1e7 ? 0 : 1)}M`;
  return String(Math.round(n)).replace(/\B(?=(\d{3})+(?!\d))/g, ",");
}

export function duration(ms) {
  if (ms < 1) return `${ms.toFixed(2)} ms`;
  if (ms < 1000) return `${Math.round(ms)} ms`;
  if (ms < 60000) return `${(ms / 1000).toFixed(ms < 10000 ? 2 : 1)} s`;
  const s = Math.round(ms / 1000);
  return `${Math.floor(s / 60)} m ${String(s % 60).padStart(2, "0")} s`;
}

const plural = (n, word, many = `${word}s`) => `${count(n)} ${n === 1 ? word : many}`;

// ---- The view -------------------------------------------------------------

// Strata the list shows at most: the earliest are folded into one line.
const LIST = 40;
// Relations the bars show at most.
const BARS = 24;
// Strata the flow graph draws at most: the latest.
const FLOW = 24;

const SVG = "http://www.w3.org/2000/svg";
const reduced = () => globalThis.matchMedia?.("(prefers-reduced-motion: reduce)").matches ?? false;

const node = (tag, className, text) => {
  const element = document.createElement(tag);
  if (className) element.className = className;
  if (text !== undefined) element.textContent = text;
  return element;
};
const svg = (tag, attributes = {}) => {
  const element = document.createElementNS(SVG, tag);
  for (const [name, value] of Object.entries(attributes)) element.setAttribute(name, value);
  return element;
};

// An element's entrance plays once: once over (or cut short), it is gone.
function settle(element) {
  const done = () => element.classList.remove("entering");
  element.addEventListener("animationend", done, { once: true });
  element.addEventListener("animationcancel", done, { once: true });
}

// Numbers that tick to their new value rather than jump, all driven by one
// animation frame loop.
const tweens = new Map(); // element -> { from, to, start, format }
let ticking = 0;
function setNumber(element, to, format) {
  const before = element.dataset.value === undefined ? null : Number(element.dataset.value);
  element.dataset.value = String(to);
  if (before === null || before === to || reduced() || !element.isConnected) {
    tweens.delete(element);
    element.textContent = format(to);
    return;
  }
  tweens.set(element, { from: tweens.get(element)?.current ?? before, to, start: performance.now(), format });
  if (!ticking) ticking = requestAnimationFrame(tick);
}
function tick(now) {
  ticking = 0;
  for (const [element, tween] of tweens) {
    const t = Math.min(1, (now - tween.start) / 280);
    tween.current = tween.from + (tween.to - tween.from) * (1 - (1 - t) ** 3);
    element.textContent = tween.format(t === 1 ? tween.to : tween.current);
    if (t === 1) tweens.delete(element);
  }
  if (tweens.size) ticking = requestAnimationFrame(tick);
}

// The run view. `select(stratum)` follows a click on a stratum (null to
// clear); `reveal(span)` shows an error's place in the editor; `ask()`
// opens the assistant about the failure; `command(line)` runs a REPL line.
// Returns { element, show(live, failure, extras) }, where `extras` says
// what the program text is and which stratum is selected.
export function createRunView({ select, reveal, ask, command }) {
  const element = node("section", "run-view");
  const head = element.appendChild(node("div", "run-head"));
  const badge = head.appendChild(node("span", "run-state"));
  badge.append(node("span", "dot"), node("span", "label"));
  const what = head.appendChild(node("span", "run-command"));
  const stats = head.appendChild(node("span", "run-stats"));
  const numbers = {};
  const words = {};
  for (const key of ["strata", "iterations", "rows", "ms"]) {
    const item = stats.appendChild(node("span", "stat"));
    numbers[key] = item.appendChild(node("b"));
    words[key] = item.appendChild(node("span"));
  }
  const card = element.appendChild(node("div", "run-card"));
  const strip = element.appendChild(node("div", "run-strip"));
  strip.title = "Each stratum, as wide as its share of the run's time";
  const body = element.appendChild(node("div", "run-body"));
  const main = body.appendChild(node("div", "run-main"));
  const list = main.appendChild(node("div", "run-strata"));
  const flowCaption = main.appendChild(node("div", "run-caption", "relations flowing between strata"));
  const flowBox = main.appendChild(svg("svg", { class: "run-flow", height: "86" }));
  const side = body.appendChild(node("div", "run-side"));
  side.append(node("div", "run-caption", "relations"));
  const barBox = side.appendChild(node("div", "run-bars"));
  const empty = element.appendChild(node("div", "run-empty"));

  const rows = new Map(); // stratum index -> its row's parts
  const barRows = new Map(); // relation -> its bar's parts
  let selected = null;
  let shownRun = null;

  // A stratum by what it writes, the largest relations first.
  function stratumLabel(st) {
    const writes = [...st.sizes].sort((a, b) => b[1] - a[1]).map(([relation]) => relation);
    if (!writes.length) return st.hash;
    return writes.length > 3 ? `${writes.slice(0, 3).join(" ")} +${writes.length - 3}` : writes.join(" ");
  }

  function row(st, curve) {
    let parts = rows.get(st.index);
    if (!parts) {
      const line = node("div", "st-row entering");
      settle(line);
      line.append(node("span", "st-dot"));
      const name = line.appendChild(node("span", "st-name"));
      const flavor = line.appendChild(node("span", "st-flavor"));
      const iterations = line.appendChild(node("span", "st-n"));
      const tuples = line.appendChild(node("span", "st-n rows"));
      const time = line.appendChild(node("span", "st-n time"));
      const spark = line.appendChild(svg("svg", { class: "st-spark", viewBox: "0 0 80 18", preserveAspectRatio: "none" }));
      const path = spark.appendChild(svg("path"));
      const tip = spark.appendChild(svg("circle", { r: "2" }));
      line.addEventListener("click", () => select(selected === st.index ? null : st.index));
      parts = { line, name, flavor, iterations, tuples, time, path, tip };
      rows.set(st.index, parts);
    }
    parts.line.classList.toggle("active", st.active);
    parts.line.classList.toggle("stopped", st.stopped);
    parts.line.classList.toggle("selected", selected === st.index);
    parts.line.title = `stratum ${st.index + 1} · ${st.hash}${st.flavor === "normal" ? "" : `_${st.flavor}`}`
      + (st.reads.length ? `\nreads ${st.reads.join(" ")}` : "");
    parts.name.textContent = stratumLabel(st);
    parts.flavor.textContent = st.flavor === "normal" ? "" : st.flavor;
    setNumber(parts.iterations, st.iterations, (n) => `${Math.round(n)} it`);
    if (st.tuples === null) parts.tuples.textContent = "";
    else setNumber(parts.tuples, st.tuples, (n) => `${count(n)} rows`);
    parts.time.textContent = duration(st.ms);
    const d = sparkline(curve, 80, 18);
    if (parts.path.getAttribute("d") !== d) parts.path.setAttribute("d", d);
    const last = curve?.at(-1);
    parts.tip.style.display = last ? "" : "none";
    if (last) {
      const [x, y] = d.split(" L").at(-1).replace(/^M/, "").split(" ");
      parts.tip.setAttribute("cx", x);
      parts.tip.setAttribute("cy", y);
    }
    return parts.line;
  }

  function renderList(live) {
    const all = shown(live);
    const folded = Math.max(0, all.length - LIST);
    const lines = [];
    if (folded) lines.push(node("div", "st-folded", `${plural(folded, "earlier stratum", "earlier strata")} — ${duration(all.slice(0, folded).reduce((sum, st) => sum + st.ms, 0))}`));
    for (const st of all.slice(folded)) lines.push(row(st, live.curves[st.index]));
    for (const index of rows.keys()) if (index < folded) rows.delete(index);
    // Only what changed moves: rows already in place stay put.
    const same = lines.length === list.childElementCount && lines.every((line, k) => list.children[k] === line);
    if (!same) list.replaceChildren(...lines);
  }

  function renderStrip(live) {
    const parts = segments(live);
    while (strip.childElementCount > parts.length) strip.lastElementChild.remove();
    parts.forEach((part, k) => {
      const segment = strip.children[k] ?? strip.appendChild(node("span", "seg"));
      segment.dataset.flavor = part.flavor;
      segment.classList.toggle("active", part.active);
      segment.classList.toggle("stopped", part.stopped);
      segment.classList.toggle("selected", selected !== null && selected >= part.first && selected <= part.last);
      // a share of the strip, never less than a sliver
      segment.style.flexGrow = String(Math.max(part.share, 0.004));
      const strata = part.first === part.last ? `stratum ${part.first + 1}` : `strata ${part.first + 1}–${part.last + 1}`;
      segment.title = `${strata} · ${duration(part.ms)}${part.active ? " · running" : part.stopped ? " · stopped here" : ""}`;
      segment.textContent = part.share > 0.08 && part.first === part.last
        ? stratumLabel(shown(live)[part.first]) : "";
      segment.onclick = () => select(part.first);
    });
  }

  function renderBars(live) {
    const all = bars(live);
    const top = all.slice(0, BARS);
    const keep = new Set(top.map((bar) => bar.relation));
    for (const [relation, parts] of barRows) {
      if (!keep.has(relation)) {
        parts.line.remove();
        barRows.delete(relation);
      }
    }
    top.forEach((bar, k) => {
      let parts = barRows.get(bar.relation);
      if (!parts) {
        const line = node("div", "bar entering");
        settle(line);
        const name = line.appendChild(node("span", "bar-name", bar.relation));
        const track = line.appendChild(node("span", "bar-track"));
        const fill = track.appendChild(node("span", "bar-fill"));
        const size = line.appendChild(node("span", "bar-size"));
        parts = { line, name, fill, size };
        barRows.set(bar.relation, parts);
      }
      parts.line.classList.toggle("zero", bar.size === 0);
      parts.line.classList.toggle("growing", live.current !== null && bar.stratum === live.strata.length);
      parts.line.classList.toggle("selected", selected === bar.stratum);
      parts.fill.style.transform = `scaleX(${bar.share})`;
      setNumber(parts.size, bar.size, count);
      if (barBox.children[k] !== parts.line) barBox.insertBefore(parts.line, barBox.children[k] ?? null);
    });
    if (all.length > BARS) {
      const more = barBox.querySelector(".bar-more") ?? node("div", "bar-more");
      more.textContent = `${all.length - BARS} more`;
      barBox.append(more);
    } else barBox.querySelector(".bar-more")?.remove();
  }

  function renderFlow(live) {
    const all = shown(live);
    const first = Math.max(0, all.length - FLOW);
    const window = all.slice(first);
    const edges = flows(live).filter((edge) => edge.from >= first);
    flowCaption.hidden = window.length < 2;
    flowBox.style.display = window.length < 2 ? "none" : "";
    if (window.length < 2) return;
    const width = Math.max(120, flowBox.clientWidth || 260);
    const step = width / window.length;
    const x = (index) => (index - first + 0.5) * step;
    const base = 66;
    const key = [live.run, first, edges.length, selected, width, ...window.map((st) => `${st.active}${st.stopped}${stratumLabel(st)}`)].join(":");
    if (flowBox.dataset.key === key) return;
    flowBox.dataset.key = key;
    flowBox.setAttribute("viewBox", `0 0 ${width} 86`);
    const drawn = new Set([...flowBox.querySelectorAll("path")].map((path) => path.dataset.key));
    const parts = [];
    for (const edge of edges) {
      const [a, b] = [x(edge.from), x(edge.to)];
      const lift = Math.min(base - 8, 14 + (b - a) * 0.35);
      const path = svg("path", {
        d: `M${a.toFixed(1)} ${base} Q${((a + b) / 2).toFixed(1)} ${(base - lift * 2).toFixed(1)} ${b.toFixed(1)} ${base}`,
        class: `flow-edge${selected === edge.from || selected === edge.to ? " selected" : ""}`,
      });
      path.dataset.key = `${edge.from}>${edge.to}`;
      if (!drawn.has(path.dataset.key) && !reduced()) path.classList.add("drawing");
      const title = path.appendChild(svg("title"));
      title.textContent = `${edge.relations.join(" ")}: stratum ${edge.from + 1} → ${edge.to + 1}`;
      parts.push(path);
    }
    for (const st of window) {
      const circle = svg("circle", {
        cx: x(st.index).toFixed(1), cy: base, r: st.active ? 5 : 4,
        class: `flow-node${st.active ? " active" : ""}${st.stopped ? " stopped" : ""}${selected === st.index ? " selected" : ""}`,
      });
      circle.dataset.flavor = st.flavor;
      const title = circle.appendChild(svg("title"));
      title.textContent = `stratum ${st.index + 1}: ${stratumLabel(st)}`;
      circle.addEventListener("click", () => select(st.index));
      parts.push(circle);
      if (step >= 34) {
        const label = svg("text", { x: x(st.index).toFixed(1), y: base + 16, class: "flow-label" });
        label.textContent = stratumLabel(st).slice(0, Math.floor(step / 6.5));
        parts.push(label);
      }
    }
    flowBox.replaceChildren(...parts);
  }

  function renderCard(live, failure) {
    card.replaceChildren();
    card.className = "run-card";
    if (!failure) return;
    card.classList.add(failure.kind);
    const title = card.appendChild(node("div", "card-title"));
    const actions = node("div", "card-actions");
    if (failure.kind === "compile") {
      // the static check refuses a program before Run starts a session
      title.textContent = /^does not check/.test(failure.message)
        ? "Nothing ran: the program does not check" : "Nothing ran: the program did not compile";
      card.append(node("pre", "card-message", failure.message));
      const where = failure.span;
      const link = actions.appendChild(node("a", "card-link", `${where.file.split("/").pop()}:${where.line}:${where.col}`));
      link.title = "Show the error in the editor";
      link.addEventListener("click", () => reveal(where));
    } else if (failure.kind === "runtime") {
      const at = failure.at;
      title.textContent = at
        ? `The run died in stratum ${at.index + 1} (${stratumLabel(at)}), iteration ${at.iterations}`
        : "The run died before its first stratum";
      card.append(node("pre", "card-message", failure.message.replace(/^session: /, "")));
      if (/EOF/.test(failure.message)) card.append(node("div", "card-note", "The daemon stopped answering in the middle of the run: it crashed, or was killed."));
      if (at) {
        const sums = totals(live);
        card.append(node("div", "card-note",
          `Last seen ${duration(sums.ms)} in: ${plural(sums.rows, "row")} derived across ${plural(sums.strata, "stratum", "strata")}. `
          + "The sizes below are what it had derived when it stopped; nothing was committed."));
      }
    } else if (failure.kind === "held") {
      const at = failure.at;
      const st = at && shown(live).find((one) => one.hash === at.name.replace(/_.*$/, ""));
      const which = st ? `stratum ${st.index + 1} (${stratumLabel(st)})` : at && `stratum ${at.name}`;
      title.textContent = `${failure.title}${at ? ` — ${which}, iteration ${at.iteration}, ${at.phase === "iter" ? "between iterations" : "inside a read"}` : ""}`;
      card.append(node("div", "card-note", "The run is held: its relations so far can be queried. Continue runs it on; Abort discards it."));
      for (const [label, line] of [["Continue", "continue"], ["Abort", "abort"]]) {
        const button = actions.appendChild(node("button", line === "continue" ? "small" : "secondary small", label));
        button.addEventListener("click", () => command(line));
      }
    } else if (failure.kind === "aborted") {
      title.textContent = `${failure.title}: the held run was discarded, and nothing was committed`;
    } else {
      title.textContent = "The command failed";
      card.append(node("pre", "card-message", failure.message));
    }
    if (failure.kind !== "held" && failure.kind !== "aborted") {
      const why = actions.appendChild(node("button", "secondary small", "✦ Ask why"));
      why.title = "Ask the REPL assistant why, and how to fix it";
      why.addEventListener("click", () => ask());
    }
    card.append(actions);
  }

  return {
    element,
    // `extras`: { text, selected, failure }
    show(live, { text = "", failure = null, selected: chosen = null } = {}) {
      selected = chosen;
      if (live && live.run !== shownRun) {
        rows.clear();
        barRows.clear();
        list.replaceChildren();
        barBox.replaceChildren();
        strip.replaceChildren();
        flowBox.replaceChildren();
        flowBox.dataset.key = "";
        // a new run's numbers start from nothing, not from the last run's
        for (const number of Object.values(numbers)) delete number.dataset.value;
        shownRun = live.run;
      }
      const nothing = !live || failure?.kind === "compile";
      element.classList.toggle("idle", nothing);
      renderCard(live, failure);
      const state = live?.replaying ? "replay"
        : live?.compiling ? "compiling"
          : failure?.kind === "held" ? "held"
            : failure?.kind === "aborted" ? "aborted"
              : failure ? "failed"
                : live?.running ? "running" : live ? "done" : "idle";
      badge.dataset.state = state;
      element.dataset.tone = state;
      badge.lastElementChild.textContent = {
        replay: "Replaying the trace", compiling: "Compiling", held: "Held", aborted: "Aborted",
        failed: failure?.kind !== "compile" ? "Failed"
          : /^does not check/.test(failure.message) ? "Does not check" : "Did not compile",
        running: "Running", done: "Done", idle: "No run yet",
      }[state];
      // the run on screen is the last one while the next compiles
      element.classList.toggle("stale", Boolean(live?.compiling));
      what.textContent = nothing ? "" : (live.command ?? "").replace(/\S*\//g, "");
      stats.hidden = body.hidden = strip.hidden = nothing;
      empty.hidden = true;
      if (nothing) return;
      const sums = totals(live);
      setNumber(numbers.strata, sums.strata, (n) => count(n));
      setNumber(numbers.iterations, sums.iterations, (n) => count(n));
      setNumber(numbers.rows, sums.rows, (n) => count(n));
      words.strata.textContent = sums.strata === 1 ? " stratum" : " strata";
      words.iterations.textContent = sums.iterations === 1 ? " iteration" : " iterations";
      words.rows.textContent = sums.rows === 1 ? " row" : " rows";
      numbers.ms.textContent = duration(sums.ms);
      numbers.ms.parentElement.title = live.running || live.replaying ? "time in its strata so far"
        : `time in its strata; the command took ${duration(live.elapsed)}, compiling included`;
      renderStrip(live);
      renderList(live);
      renderBars(live);
      renderFlow(live);
      const zero = live.replaying ? [] : stayedEmpty(live, text);
      if (zero.length) {
        empty.hidden = false;
        empty.textContent = `Stayed empty: ${zero.join(", ")}`;
        empty.title = "Relations the program names that the run left with no rows";
      }
    },
  };
}
