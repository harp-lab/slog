// A finding's derivation, as the REPL's `why` gives it (a proof tree over
// the analysis's own relations), told two ways:
//   explain(nodes)  the human chain: a few lines saying why, in words
//   details(nodes)  the tree itself, without the plumbing
// Plumbing is what the compiler made up (temp relations staging a rule's
// computations) and the constructor relations every interned value has;
// a plumbing fact is skipped and its own premises take its place.
//
// `nodes` is the why result's `nodes`: { id, parent, kind, relation, row }
// for a fact, { id, parent, kind: "derivation", source } for the rule
// that derived the fact above it.

// ---- reading a row ------------------------------------------------------------

// A row as printed, `3 "rest" (loc 1 73 25) [(var "x" ...)]`, as values:
// strings, numbers, { c: name, a: [args] } for a constructor, arrays for
// lists.
export function parseRow(text) {
  const tokens = text.match(/"(?:[^"\\]|\\.)*"|[()[\]]|[^\s()[\]"]+/g) ?? [];
  let at = 0;
  const value = () => {
    const token = tokens[at++];
    if (token === "(") {
      const c = tokens[at++];
      const a = [];
      while (tokens[at] !== ")" && at < tokens.length) a.push(value());
      at++;
      return { c, a };
    }
    if (token === "[") {
      const list = [];
      while (tokens[at] !== "]" && at < tokens.length) list.push(value());
      at++;
      return list;
    }
    if (token.startsWith("\"")) return JSON.parse(token);
    return /^-?\d+(\.\d+)?$/.test(token) ? Number(token) : token;
  };
  const values = [];
  while (at < tokens.length) values.push(value());
  return values;
}

// ---- the tree, without the plumbing --------------------------------------------

const plumbing = (node) =>
  /^temp\d+x\d+$/.test(node.relation) || node.row?.startsWith(`(${node.relation} `);

// The tree as { fact, args, derivations: [{ source, premises: [...] }] },
// a plumbing fact replaced by its premises.
export function tree(nodes) {
  const children = new Map();
  for (const node of nodes) {
    if (!children.has(node.parent)) children.set(node.parent, []);
    children.get(node.parent).push(node);
  }
  const build = (fact) => ({
    fact,
    args: parseRow(fact.row ?? ""),
    derivations: (children.get(fact.id) ?? []).map((derivation) => ({
      source: derivation.source,
      premises: premises(derivation),
    })),
  });
  const premises = (derivation) => (children.get(derivation.id) ?? []).flatMap((fact) =>
    plumbing(fact)
      ? (children.get(fact.id) ?? []).flatMap(premises)
      : [build(fact)]);
  const root = nodes.find((node) => node.parent < 0);
  return root ? build(root) : null;
}

// ---- in words -----------------------------------------------------------------

const line = (loc) => (loc?.c === "loc" ? loc.a[1] : "?");

function term(t) {
  if (typeof t === "string") return JSON.stringify(t);
  if (Array.isArray(t)) return "[…]";
  if (!t?.c) return String(t);
  if (t.c === "var") return t.a[0];
  if (t.c === "wild") return "_";
  if (t.c === "splice") return `${term(t.a[0])} ...`;
  if (t.c === "lst") return "[…]";
  if (t.c === "call") return `(${t.a[0]} …)`;
  if (/_lit$/.test(t.c)) return String(t.a[0]);
  return `(${t.c} …)`;
}

function origin(o) {
  if (o?.c === "argument_of") return `an argument of ${o.a[0]}`;
  if (o?.c === "request_of") return `the input of a request to ${o.a[0]}`;
  return "an equation";
}

// relation -> its fact in words, or nothing to say
const SAY = {
  issue: ([, at, code, subject]) =>
    code === "singleton" ? `${subject[0]} occurs once in the rule at line ${line(at)}` : null,
  singleton: ([, x, at]) => `${x} occurs once in the rule at line ${line(at)}`,
  occurs: ([, x, at]) => `${x} occurs at line ${line(at)}`,
  documents: ([, x]) => `${x} names a value the rule ignores`,
  names_column: ([owner, i, x, , at]) => `${x} names argument ${i + 1} of ${owner} at line ${line(at)} too`,
  bound: ([, x]) => `${x} is bound`,
  pattern: ([, t, o]) => `${term(t)} is matched against ${origin(o)}`,
  in_head: ([, x, at]) => `${x} is in the head at line ${line(at)}`,
  head: ([, , rel, , at]) => `the head (${rel} …) at line ${line(at)}`,
  body: ([, , rel, , at]) => `the body atom (${rel} …) at line ${line(at)}`,
  negated: ([, , rel, , at]) => `~(${rel} …) at line ${line(at)}`,
  binds: ([, , , , at]) => `the equation at line ${line(at)}`,
  atom: ([, rel, , at]) => `(${rel} …) at line ${line(at)}`,
  writes: ([, rel, at]) => `the rule at line ${line(at)} derives ${rel}`,
  reads: ([, rel, sign, at]) => `the rule at line ${line(at)} reads ${rel}${sign === "-" ? " under ~" : ""}`,
  dep: ([from, to, sign]) => `${to} reads ${from}${sign === "-" ? " under ~" : ""}`,
  reaches: ([from, to]) => `${to} depends on ${from}`,
  asks: ([, f, at]) => `${f} is asked at line ${line(at)}`,
  input: ([rel]) => `${rel} is read but never written: an input`,
  inhabited: ([rel]) => `${rel} can hold rows`,
  blocked_at: ([, i]) => `body clause ${i + 1} can never match`,
  lattice_value: ([, rel, x]) => `${x} is the value of the lattice ${rel}`,
  is_lattice: ([rel]) => `${rel} is a lattice`,
  relation: ([name, kind, , at]) => `${kind} ${name}, declared at line ${line(at)}`,
  constructor: ([name, , at]) => `the constructor ${name}, declared at line ${line(at)}`,
  slot: ([owner, i, type]) => `argument ${i + 1} of ${owner} holds ${type}`,
};
// the program's own facts: where an explanation bottoms out
const SOURCE = new Set(["head", "body", "negated", "binds", "relation", "constructor"]);

// The human chain: the finding's evidence, nearest first, each in words,
// at most `limit` lines.  Each relation is told once (a pattern nested in
// patterns is the innermost one), and the chain stops at the program.
export function explain(nodes, limit = 6) {
  const root = tree(nodes);
  if (!root) return [];
  const said = [];
  const told = new Set();
  const walk = (node) => {
    if (said.length >= limit) return;
    const { relation } = node.fact;
    const text = !told.has(relation) && SAY[relation]?.(node.args);
    if (text && !said.includes(text)) {
      said.push(text);
      told.add(relation);
    }
    if (SOURCE.has(relation)) return;
    for (const derivation of node.derivations) for (const premise of derivation.premises) walk(premise);
  };
  walk(root);
  return said;
}

// The tree as indented lines: each fact as the REPL prints it, under the
// rule that derived it.
export function details(nodes) {
  const root = tree(nodes);
  const lines = [];
  const walk = (node, depth) => {
    lines.push(`${"  ".repeat(depth)}(${node.fact.relation}${node.fact.row ? ` ${node.fact.row}` : ""})`);
    for (const derivation of node.derivations) {
      lines.push(`${"  ".repeat(depth + 1)}← ${derivation.source}`);
      for (const premise of derivation.premises) walk(premise, depth + 2);
    }
  };
  if (root) walk(root, 0);
  return lines;
}
