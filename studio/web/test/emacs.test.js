// The Emacs keys' operations (emacs.js).

import { EMACS, noteKill, ring } from "../emacs.js";
import { equal, mark, marked } from "./check.js";

const press = (name, source) => {
  const { text, selection } = marked(source);
  const result = EMACS[name](text, selection);
  return result && mark(result);
};

// words are letters, digits and _; motion skips what lies between them
equal("M-f", press("forwardWord", "(path| X_1 Y)"), "(path X_1| Y)");
equal("M-b", press("backwardWord", "(path X_1 |Y)"), "(path |X_1 Y)");
equal("M-c", press("capitalizeWord", "rule |(edge x y)"), "rule (Edge| x y)");
// C-k takes the rest of the line, or the line break when nothing is left
equal("C-k", press("killLine", "a|bc\nd"), "a|\nd");
equal("C-k at the end", press("killLine", "abc|\nd"), "abc|d");

// kills in a row add to one entry, in the order of the text; anything
// between them starts a new one
ring.entries = [];
ring.after = null;
const step = (name, source) => mark(EMACS[name](...Object.values(marked(source))));
step("killWord", "|edge path node");
step("killWord", "| path node");
equal("chained kills", ring.entries[0], "edge path");
step("backwardKillWord", "a b|");
equal("a kill elsewhere starts afresh", ring.entries.slice(0, 2), ["b", "edge path"]);

// C-y yanks the newest; M-y right after cycles through older entries, and
// does nothing once anything else happened
const yanked = step("yank", "x |y");
equal("C-y", yanked, "x b|y");
const popped = step("yankPop", yanked);
equal("M-y", popped, "x edge path|y");
equal("M-y cycles round", step("yankPop", popped), "x b|y");
equal("M-y needs a yank", press("yankPop", "x b|zy"), null);

// paredit's kill is a kill: C-y brings it back
noteKill("(a b c)", { start: 3, end: 3 }, { text: "(a )", selection: { start: 3, end: 3 } });
equal("noteKill", ring.entries[0], "b c");
