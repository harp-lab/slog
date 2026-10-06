// The REPL assistant's pure logic: entering ask mode, which queries the
// prompt previews, a ```repl block as runnable steps, and matching them to
// what the assistant tried.

import { asking, normal, previewable, reads, rows, steps, summarize } from "../assist.js";
import { equal } from "./check.js";

equal("?? opens a question, and the rest is it", asking("?? which nodes can't reach 5"), "which nodes can't reach 5");
equal("?? alone opens an empty one", asking("??"), "");
equal("a query is not a question", asking("?(path X Y)"), null);

equal("whole queries preview",
  ["?(path 1 Y)", "? (edge X Y) (edge Y Z) -> (X Z)", "?count (path X _)", "?exists (edge 1 _)"].map(previewable),
  [true, true, true, true]);
equal("unfinished ones do not",
  ["?(path 1 Y", "?(", "? (edge X Y) ->", "?(a \"x)\"", "tables", "?count", "path(1 2)"].map(previewable),
  [false, false, false, false, false, false, false]);

equal("a plan's steps: one a line, each with its note", steps([
  "whynot (path 1 5)            ;; which premise is missing",
  "",
  "?(edge 1 Y)",
  "?(note \"a;;b\" X)  ;; a string keeps its semicolons",
].join("\n")), [
  { command: "whynot (path 1 5)", note: "which premise is missing" },
  { command: "?(edge 1 Y)", note: "" },
  { command: "?(note \"a;;b\" X)", note: "a string keeps its semicolons" },
]);
equal("a command runs on over indented lines",
  steps("? (edge X Y)\n  (edge Y Z) ;; two steps\n  -> (X Z)\ntables"),
  [{ command: "? (edge X Y)\n  (edge Y Z)\n  -> (X Z)", note: "two steps" }, { command: "tables", note: "" }]);
equal("and while its brackets are open",
  steps("?(edge X\n Y)\n?(a 1)"), [{ command: "?(edge X\n Y)", note: "" }, { command: "?(a 1)", note: "" }]);

equal("spacing does not tell commands apart", normal("? (path  1 Y)"), normal("?(path 1 Y)"));

const found = reads([
  { name: "repl", input: { line: "?(path 1 Y)" }, status: "ok", result: "{\"total\":{\"kind\":\"exact\",\"n\":1770},\"rows\":[\"(1 2)\"]}" },
  { name: "repl", input: { line: "?(pth X)" }, status: "error", result: "no relation pth" },
  { name: "repl", input: { line: "tables" }, status: "running" },
  { name: "search_docs", input: { query: "x" }, status: "ok", result: "[]" },
]);
equal("what the assistant tried, by command", [...found.keys()], ["?(path 1 Y)", "?(pth X)"]);
equal("a read's total", rows(found.get(normal("? (path 1 Y)")).total), "1,770 rows");
equal("a failed read", found.get("?(pth X)").error, "no relation pth");
equal("totals in words",
  [{ kind: "exact", n: 1 }, { kind: "exact", n: 0 }, { kind: "at-least", n: 2000 }, { kind: "unknown" }, undefined].map(rows),
  ["1 row", "no rows", "2,000+ rows", "", ""]);

equal("an entry for the assistant: its error",
  summarize({ line: "?(pth X)", error: { message: "no relation pth" } }), { line: "?(pth X)", error: "no relation pth" });
equal("or what it said, briefly",
  summarize({ line: "tables", result: { title: "Tables", relations: [{}, {}] } }), { line: "tables", output: "Tables\n2 relations" });
