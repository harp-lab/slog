// Proposals and version differences as hunks on the text shown: what goes,
// what comes in where, and which proposals can be placed at all.

import { apply, fork, groupHunk, hunks, lineDiff, place } from "../hunks.js";
import { equal } from "./check.js";

const PROGRAM = [
  "table (edge int int)",
  "table (path int int)",
  "rule (edge 1 2) (edge 2 3)",
  "rule (edge X Y) --> (path X Y)",
  "",
].join("\n");

equal("a line diff keeps the common lines", lineDiff(["a", "b", "c"], ["a", "x", "c", "d"]).map((d) => `${d.kind} ${d.text}`),
  ["same a", "del b", "add x", "same c", "add d"]);

equal("a replaced line marks only what differs", hunks("a\nrule (edge 1 2)\nb", "a\nrule (edge 1 3)\nb"), [{
  first: 2, last: 2,
  removed: [{ line: 2, from: 14, to: 15 }],
  added: [{ after: 2, lines: [{ text: "rule (edge 1 3)", from: 14, to: 15 }] }],
}]);

equal("inserted lines follow the line before them", hunks("a\nb", "a\nx\ny\nb", 10), [{
  first: 11, last: 11, removed: [], added: [{ after: 10, lines: [{ text: "x" }, { text: "y" }] }],
}]);

equal("separate changes are separate hunks", hunks("a\nb\nc\nd", "A\nb\nc").map((h) => [h.first, h.last]), [[1, 1], [4, 4]]);

const op = (id, thread, change) => ({ id, thread, changeset: thread, status: "pending", ...change });
const edit = (old, text) => ({ kind: "edit", old, new: text });
const append = (source) => ({ kind: "append", source });

{
  const ops = [
    op(1, 1, edit("(edge 2 3)", "(edge 2 4)")),
    op(2, 1, append("table (reach int)")),
    // built on op 2: its old text exists only once that is made
    op(3, 1, edit("table (reach int)", "table (reach int)\nrule (path 1 X) --> (reach X)")),
    op(4, 2, edit("rule (edge 1 2)", "rule (edge 1 5)")),
    op(5, 2, edit("(nowhere)", "x")),
    { ...op(6, 2, edit("table (edge int int)", "")), status: "accepted" },
  ];
  const { groups, unplaced } = place(PROGRAM, ops);
  equal("ops are placed, and one built on another joins it",
    groups.map((g) => [g.thread, g.ids, PROGRAM.slice(g.start, g.end)]),
    [[1, [1], "(edge 2 3)"], [1, [2, 3], ""], [2, [4], "rule (edge 1 2)"]]);
  equal("an op whose old text is gone cannot be placed", unplaced, [5]);

  equal("an edit's hunk is its whole lines", groupHunk(PROGRAM, groups[0]), {
    first: 3, last: 3,
    removed: [{ line: 3, from: 25, to: 26 }],
    added: [{ after: 3, lines: [{ text: "rule (edge 1 2) (edge 2 4)", from: 25, to: 26 }] }],
  });
  equal("an append comes after the last line, set off by a blank one", groupHunk(PROGRAM, groups[1]), {
    first: 5, last: 5, removed: [],
    added: [{ after: 4, lines: ["", "table (reach int)", "rule (path 1 X) --> (reach X)"].map((text) => ({ text })) }],
  });

  equal("a thread's fork is what accepting its ops in order gives",
    fork(PROGRAM, groups, 1),
    [1, 2, 3].reduce((text, id) => apply(text, ops[id - 1]), PROGRAM));
}

{
  // an old text ending in a newline, and one removed outright
  const text = "rule (a)\nrule (b)\nrule (c)\n";
  const { groups } = place(text, [op(1, 1, edit("rule (b)\n", ""))]);
  equal("a whole line removed", groupHunk(text, groups[0]), { first: 2, last: 2, removed: [{ line: 2 }], added: [] });
  equal("an old text occurring twice cannot be placed", place("x x", [op(1, 1, edit("x", "y"))]).unplaced, [1]);
}
