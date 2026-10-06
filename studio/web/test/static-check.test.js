// The static check's hovers (check.js) over a report's info, and which
// lines the REPL assistant suggests are definitions to check (assist.js).

import { hover, index, ruleAt } from "../check.js";
import { definition } from "../assist.js";
import { equal } from "./check.js";

const DIR = "/p";
const pathOf = (file) => (file.startsWith(`${DIR}/`) ? file.slice(DIR.length + 1) : null);
// table (name int str) ;; a node's label
// rule (edge x y) (name x s) --> (name y s)     (line 4)
const info = index({
  rules: [{
    file: "/p/main.slog", line: 4, col: 1, end_line: 4, end_col: 42,
    vars: [{ name: "x", type: "int", line: 4, col: 12 }, { name: "s", type: "str", line: 4, col: 25 }],
  }, { file: "/elsewhere/lib.slog", line: 1, col: 1, end_line: 1, end_col: 9, vars: [] }],
  symbols: [{
    name: "name", kind: "table", signature: "(table int str)", decl: "table (name int str)", doc: "a node's label",
    def: { file: "/p/main.slog", line: 2, col: 8 },
    refs: [{ role: "def" }, { role: "read" }, { role: "write" }, { role: "write" }],
  }],
}, pathOf);

equal("rules are kept by project path; others' are not", [...info.rules.keys()], ["main.slog"]);
equal("the rule around a position", ruleAt(info.rules.get("main.slog"), 4, 20)?.line, 4);
equal("none past its end", ruleAt(info.rules.get("main.slog"), 4, 42), null);
equal("a variable's hover is its inferred type", hover(info, "main.slog", "s", 4, 40), "`s : str` · inferred in this rule");
equal("a relation's hover is its declaration, comment and uses", hover(info, "main.slog", "name", 4, 18),
  "```slog\ntable (name int str)\n```\n\na node's label\n\ntable · written 2× · read 1×");
equal("a word outside any rule and declaration has none", hover(info, "main.slog", "x", 9, 1), null);
equal("nothing to say before a check", hover(null, "main.slog", "name", 1, 1), null);

equal("definitions are checked; commands and queries are not",
  ["rule (a 1)", "  table (b int)", "?(a X)", "add a 1", "tables", "rules"].map(definition),
  [true, true, false, false, false, false]);
