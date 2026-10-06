// A finding's derivation told in words, and as a tree without the
// compiler's temp relations and the values' constructor relations.

import { details, explain, parseRow } from "../lint-why.js";
import { equal } from "./check.js";

equal("a row reads as values", parseRow(`3 "a \\"b\\"" (loc 1 73 25) [(var "x" (loc 1 2 3)) 4]`), [
  3, `a "b"`, { c: "loc", a: [1, 73, 25] },
  [{ c: "var", a: ["x", { c: "loc", a: [1, 2, 3] }] }, 4],
]);

// a singleton in a request's input, as `why` gave it (trimmed)
let id = 0;
const NODES = [];
const fact = (parent, relation, row, kind = "premise") => {
  NODES.push({ id: id, parent, kind, relation, row });
  return id++;
};
const derived = (parent, source) => {
  NODES.push({ id: id, parent, kind: "derivation", source });
  return id++;
};
const finding = fact(-1, "finding", `"hint" "main.slog" 73 25 "singleton" "rest is used only once"`, "fact");
let d = derived(finding, "lint-local.slog:19:1");
fact(d, "loc", "(loc 1 73 25) 1 73 25");
const report = fact(d, "report", `"hint" (loc 1 73 25) "singleton" "rest is used only once"`);
const temp = fact(derived(report, "lint-local.slog:185:1"), "temp11x36", `"hint" (loc 1 73 25) "rest"`);
const issue = fact(derived(temp, "lint-local.slog:185:1"), "issue", `"hint" (loc 1 73 25) "singleton" ["rest"]`);
const documents = fact(derived(issue, "lint-local.slog:184:1"), "documents", `3 "rest" (loc 1 73 25)`);
d = derived(documents, "lint-local.slog:180:1");
fact(d, "request_of", `(request_of "lookup") "lookup"`);
const pattern = fact(d, "pattern", `3 (var "rest" (loc 1 73 25)) (request_of "lookup")`);
const outer = fact(derived(pattern, "lint-local.slog:122:1"), "pattern", `3 (splice (var "rest" (loc 1 73 25))) (request_of "lookup")`);
fact(derived(outer, "lint-local.slog:116:1"), "head", `3 0 "lookup" [(var "rest" (loc 1 73 25))] (loc 1 73 7)`);

equal("the chain in words: the claim, then its evidence, the innermost pattern once", explain(NODES), [
  "rest occurs once in the rule at line 73",
  "rest names a value the rule ignores",
  "rest is matched against the input of a request to lookup",
  "the head (lookup …) at line 73",
]);

const tree = details(NODES).join("\n");
equal("the tree keeps the analysis's relations", ["issue", "documents", "pattern", "head"].every((r) => tree.includes(`(${r} `)), true);
equal("and drops temps and constructor relations", /temp11x36|\(loc \(loc|\(request_of \(request_of/.test(tree), false);
