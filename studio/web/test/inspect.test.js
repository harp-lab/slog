// inspect.js's model: the one-line form of a held stop's bindings, and the
// word under the mouse.

import { elide, fitBindings, wordAt } from "../inspect.js";
import { parseValue } from "../table.js";
import { equal as check } from "./check.js";

const K = '(letk "a" (letx "b" (app (ref "id") (lam "y" (ref "y"))) (app (ref "b") (ref "a"))) (halt "imprecise"))';
const tree = parseValue(K);
check("elide: whole at its depth", elide(tree, 9), K);
check("elide: two levels keep the heads", elide(tree, 2),
  '(letk "a" (letx "b" (app …) (app …)) (halt "imprecise"))');
check("elide: one level", elide(tree, 1), '(letk "a" (letx …) (halt …))');
check("elide: the head alone", elide(tree, 0), "(letk …)");
check("elide: a list", elide(parseValue("[(a 1) (b 2)]"), 0), "[…]");
check("elide: a leaf", elide(parseValue('"x"'), 0), '"x"');

const bindings = [["V", '(clo "x" (ref "x"))'], ["A", "(num 1)"], ["K", K]];
check("fit: whole when it fits", fitBindings(bindings, 200),
  { text: `V = (clo "x" (ref "x")) · A = (num 1) · K = ${K}`, elided: false });
// the longest binding gives way first, a level at a time
check("fit: the longest is cut", fitBindings(bindings, 80),
  { text: 'V = (clo "x" (ref "x")) · A = (num 1) · K = (letk "a" (letx …) (halt …))', elided: true });
check("fit: never longer than the room", fitBindings(bindings, 30).text.length <= 30, true);
check("fit: cut at last", fitBindings(bindings, 30).elided, true);

check("word: a variable", wordAt("rule (ret V (ar A K)) --> (eval A (fn V K))", 17), { word: "A", start: 17, head: false });
check("word: a relation heads its atom", wordAt("rule (ret V (ar A K))", 8), { word: "ret", start: 7, head: true });
check("word: none in a bracket", wordAt("rule (ret V)", 6), null);
check("word: not a number", wordAt("(num 12)", 7), null);
