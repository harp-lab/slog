// The Emacs keys' operations (emacs.js).

import { EMACS, ring } from "../emacs.js";
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
ring.after = null;
const step = (name, source) => mark(EMACS[name](...Object.values(marked(source))));
step("killWord", "|edge path node");
step("killWord", "| path node");
equal("chained kills", ring.text, "edge path");
step("backwardKillWord", "a b|");
equal("a kill elsewhere starts afresh", ring.text, "b");
equal("C-y", press("yank", "x |y"), "x b|y");
