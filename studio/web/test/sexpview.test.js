// sexpview.js's model: a value cut to a depth, opened and cut again a
// subterm at a time, and wrapped at subterm boundaries when it is long.

import { fittingDepth, layout, layoutText, newView, repeated, toggle } from "../sexpview.js";
import { parseValue } from "../table.js";
import { equal as check } from "./check.js";

const K = parseValue('(letk "a" (letx "b" (app (ref "id") (lam "y" (ref "y"))) (app (ref "b") (ref "a"))) (halt "imprecise"))');
const show = (view, columns = 200) => layoutText(layout(K, view, columns));

check("cut: two levels keep the heads", show(newView(2)),
  '(letk "a" (letx "b" (app …) (app …)) (halt "imprecise"))');
check("cut: one level", show(newView(1)), '(letk "a" (letx …) (halt …))');
check("cut: whole", show(newView(9)),
  '(letk "a" (letx "b" (app (ref "id") (lam "y" (ref "y"))) (app (ref "b") (ref "a"))) (halt "imprecise"))');
// opening one … shows its arguments, theirs still cut
let view = toggle(newView(1), "1", 1);
check("open: one subterm", show(view), '(letk "a" (letx "b" (app …) (app …)) (halt …))');
view = toggle(view, "1.1", 2);
check("open: deeper, one at a time", show(view), '(letk "a" (letx "b" (app (ref …) (lam …)) (app …)) (halt …))');
// cutting an opened term again; a term open by depth can be cut too
check("cut again: the opened one", show(toggle(view, "1", 1)), '(letk "a" (letx …) (halt …))');
check("cut again: open by depth", show(toggle(newView(2), "1", 1)), '(letk "a" (letx …) (halt "imprecise"))');

// too wide: break after the head and its leaf arguments, the rest below
check("wrap: at subterm boundaries", show(newView(9), 40), [
  '(letk "a"',
  '  (letx "b"',
  '    (app (ref "id") (lam "y" (ref "y")))',
  '    (app (ref "b") (ref "a")))',
  '  (halt "imprecise"))',
].join("\n"));
check("wrap: a list", layoutText(layout(parseValue("[(a 1) (b 2) (c 3)]"), newView(9), 10)),
  "[\n  (a 1)\n  (b 2)\n  (c 3)]");

check("fit: the deepest one line holds", fittingDepth(K, 60), 2);
check("fit: at least the head's arguments", fittingDepth(K, 5), 1);
check("same: repeated subterms", [...repeated(parseValue('(pair (ref "y") (lam "y" (ref "y")))'))], ['(ref "y")']);
