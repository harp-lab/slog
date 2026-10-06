// A value as Slog text: one line of real syntax while it fits, cut to `…`
// past a depth, and wrapped at subterm boundaries, indented, when it does
// not.  Each `…` opens just that subterm, whose own deeper parts stay cut
// until clicked; Alt-click a term (or click its open paren) to cut it
// again.  The debugger's values render this way (inspect.js).
//
// The model functions are pure; web/test runs them.  A value is parsed
// once (table.js `parseValue`); a view is { depth, open, closed }: terms
// above `depth` show their arguments, and the paths ("0.2") in `open` and
// `closed` override that one term at a time.

import { parseValue } from "./table.js";

// ---- The model ------------------------------------------------------------------

const BRACKETS = { term: ["(", ")"], tuple: ["(", ")"], list: ["[", "]"], set: ["{", "}"] };
const childrenOf = (tree) => (tree.kind === "term" ? tree.args : tree.items) ?? null;

export const newView = (depth) => ({ depth, open: new Set(), closed: new Set() });

// Whether the term at `path`, `depth` levels down, shows its arguments.
export function expanded(view, path, depth) {
  if (view.open.has(path)) return true;
  if (view.closed.has(path)) return false;
  return depth < view.depth;
}

// Open the cut term at `path`, or cut the open one again.
export function toggle(view, path, depth) {
  const open = new Set(view.open);
  const closed = new Set(view.closed);
  if (expanded(view, path, depth)) {
    open.delete(path);
    if (depth < view.depth) closed.add(path);
  } else {
    closed.delete(path);
    if (depth >= view.depth) open.add(path);
  }
  return { depth: view.depth, open, closed };
}

const leafClass = (tree) => ({ string: "str", number: "num", bool: "num", symbol: "sym" }[tree.kind] ?? "sym");

// The tokens of `tree` on one line: { text, cls, path, depth, role }.
function flat(tree, path, depth, view, out) {
  const kids = childrenOf(tree);
  if (!kids) {
    out.push({ text: tree.text, cls: leafClass(tree), path, depth });
    return out;
  }
  const [open, close] = BRACKETS[tree.kind];
  out.push({ text: open, cls: "paren", path, depth, role: "open" });
  if (tree.kind === "term") out.push({ text: tree.head, cls: "ctor", path, depth, role: "head" });
  if (kids.length && !expanded(view, path, depth)) {
    if (tree.kind === "term") out.push({ text: " ", cls: "sp" });
    out.push({ text: "…", cls: "more", path, depth, role: "more" });
  } else {
    kids.forEach((kid, i) => {
      if (tree.kind === "term" || i > 0) out.push({ text: " ", cls: "sp" });
      flat(kid, path ? `${path}.${i}` : String(i), depth + 1, view, out);
    });
  }
  out.push({ text: close, cls: "paren", path, depth, role: "close" });
  return out;
}

const width = (tokens) => tokens.reduce((n, t) => n + t.text.length, 0);

// The value as lines of { indent, tokens }, each at most `columns` wide
// where it can be: a term too wide for its line breaks after its head (and
// a leading leaf argument), its arguments below it, indented two.
export function layout(tree, view, columns) {
  const block = (node, path, depth, indent) => {
    const tokens = flat(node, path, depth, view, []);
    const kids = childrenOf(node);
    if (indent + width(tokens) <= columns || !kids?.length || !expanded(view, path, depth)) {
      return [{ indent, tokens }];
    }
    const [open, close] = BRACKETS[node.kind];
    const head = [{ text: open, cls: "paren", path, depth, role: "open" }];
    let rest = kids.map((kid, i) => [kid, path ? `${path}.${i}` : String(i)]);
    if (node.kind === "term") {
      head.push({ text: node.head, cls: "ctor", path, depth, role: "head" });
      // a leaf right after the head stays on its line: (letk "a"
      while (rest.length && !childrenOf(rest[0][0])) {
        const [leaf, at] = rest.shift();
        head.push({ text: " ", cls: "sp" }, ...flat(leaf, at, depth + 1, view, []));
      }
    }
    const lines = [{ indent, tokens: head }];
    for (const [kid, at] of rest) lines.push(...block(kid, at, depth + 1, indent + 2));
    lines.at(-1).tokens.push({ text: close, cls: "paren", path, depth, role: "close" });
    return lines;
  };
  return block(tree, "", 0, 0);
}

// The text a layout shows, for tests and copying what is shown.
export const layoutText = (lines) => lines.map((line) => " ".repeat(line.indent) + line.tokens.map((t) => t.text).join("")).join("\n");

// The deepest cut (up to `most`) whose one line fits `columns`, at least 1:
// the most a value says before it has to wrap.
export function fittingDepth(tree, columns, most = 4) {
  for (let depth = most; depth > 1; depth--) {
    if (width(flat(tree, "", 0, newView(depth), [])) <= columns) return depth;
  }
  return 1;
}

// Compound subterms that appear more than once: interned, so equal text
// is the same value.
export function repeated(tree) {
  const count = new Map();
  const walk = (node) => {
    const kids = childrenOf(node);
    if (!kids?.length) return;
    count.set(node.text, (count.get(node.text) ?? 0) + 1);
    kids.forEach(walk);
  };
  walk(tree);
  return new Set([...count].filter(([text, n]) => n > 1 && text.length > 6).map(([text]) => text));
}

// ---- The view ----------------------------------------------------------------------

const span = (className, text) => {
  const element = document.createElement("span");
  element.className = className;
  element.textContent = text;
  return element;
};

// The subterm of `tree` at `path`.
const at = (tree, path) => (path ? path.split(".") : []).reduce((node, i) => childrenOf(node)?.[Number(i)] ?? node, tree);

// `text` as an S-expression element `columns` characters wide; `depth`
// cuts it (default: as deep as one line allows).
export function renderSexp(text, { columns = 80, depth } = {}) {
  const tree = parseValue(text);
  let view = newView(depth ?? fittingDepth(tree, columns));
  const same = repeated(tree);
  const box = document.createElement("div");
  box.className = "sx";
  box.title = "";

  const draw = () => {
    box.replaceChildren();
    for (const line of layout(tree, view, columns)) {
      const row = box.appendChild(document.createElement("div"));
      row.className = "sx-line";
      row.style.paddingLeft = `${line.indent}ch`;
      for (const token of line.tokens) {
        const node = row.appendChild(span(`sx-${token.cls}`, token.text));
        if (token.path === undefined) continue;
        node.dataset.path = token.path;
        node.dataset.depth = token.depth;
        if (token.role) node.dataset.role = token.role;
        if (token.role === "more") node.title = "show this part";
        if (token.role === "open" && same.has(at(tree, token.path).text)) {
          node.classList.add("sx-same");
          node.title = "this value appears more than once here: interned, they are the same value";
        }
      }
    }
  };

  box.addEventListener("click", (event) => {
    const token = event.target.closest("[data-path]");
    if (!token) return;
    const { role, path, depth: d } = token.dataset;
    const depthOf = Number(d);
    // `…` opens; Alt-click a term, or its open paren, cuts it again
    if (role === "more" || ((role === "open" || event.altKey) && expanded(view, path, depthOf) && childrenOf(at(tree, path))?.length)) {
      event.preventDefault();
      view = toggle(view, path, depthOf);
      draw();
    }
  });
  // the parens of the term under the mouse
  let lit = [];
  box.addEventListener("mouseover", (event) => {
    for (const node of lit) node.classList.remove("sx-lit");
    const token = event.target.closest("[data-path]");
    if (!token) return;
    const path = token.dataset.role === "open" || token.dataset.role === "close" || token.dataset.role === "head" || token.dataset.role === "more"
      ? token.dataset.path : token.dataset.path.split(".").slice(0, -1).join(".");
    lit = [...box.querySelectorAll(`[data-path="${path}"][data-role="open"], [data-path="${path}"][data-role="close"]`)];
    for (const node of lit) node.classList.add("sx-lit");
  });
  box.addEventListener("mouseleave", () => {
    for (const node of lit) node.classList.remove("sx-lit");
    lit = [];
  });
  // a copy is the whole value, however much is shown
  box.addEventListener("copy", (event) => {
    event.clipboardData?.setData("text/plain", tree.text);
    event.preventDefault();
  });
  box.fullText = tree.text;
  draw();
  return box;
}
