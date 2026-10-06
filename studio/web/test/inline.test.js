// Which answers become tables in the transcript, and their rows.

import { shownFacts } from "../inline.js";
import { equal } from "./check.js";

const shown = shownFacts({
  kind: "query",
  title: "Rows · subst",
  lines: ["(subst (subst (ix 0) 0 (ix 1)) #7 (ix 0) #8 0 (ix 1) #9)", "… 57 more; use `show subst all`"],
});
equal("a show answer is its relation's facts, and how many more there are",
  [shown.name, shown.rows.length, shown.rows[0].length, shown.rows[0][0].handle, shown.more], ["subst", 1, 4, "#7", 57]);
equal("an empty relation shows no rows", shownFacts({ kind: "query", title: "Rows · edge", lines: ["0 rows"] }).rows, []);
equal("rows sent as data are taken as they are",
  shownFacts({ kind: "query", title: "Rows · at", relation: "at", "rows-total": 3,
    rows: [[{ text: "1", handle: null }, { text: "(pt 1 2)", handle: "#4" }]] }),
  { name: "at", rows: [[{ text: "1" }, { text: "(pt 1 2)", handle: "#4" }]], more: 2 });
equal("other answers are not facts", shownFacts({ kind: "query", title: "Query · (X Z)", lines: [] }), null);
equal("nor are other kinds", shownFacts({ kind: "value", title: "Value · #3", lines: ["(pt 1 2)"] }), null);
