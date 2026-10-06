// Which answers become tables in the transcript, and their rows.

import { cellOf, shownFacts } from "../inline.js";
import { setStates } from "../stamp.js";
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

// A cell of a result set reads its rows; it follows the session while the
// set is live, and keeps to a past state's.
setStates({ states: [], current: 3 });
equal("a live set's cell follows the session",
  cellOf({ query: "?exists (path 1 Y)", stale: false, state: { id: 3, pred: 2 } }),
  { line: "? (path 1 Y)", follows: true });
equal("a count's cell reads its rows",
  cellOf({ query: "?count (path X _)", stale: false, state: { id: 3, pred: 2 } }).line, "? (path X _)");
equal("a set of a past state stays there",
  cellOf({ query: "?(path X Y)", stale: false, state: { id: 1, pred: 0 } }).follows, false);
equal("so does a stale set", cellOf({ query: "?(path X Y)", stale: true, state: { id: 3, pred: 2 } }).follows, false);
