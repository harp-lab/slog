// The formatter: what it re-lays out, what it leaves, and that it is
// idempotent and changes only space, over a corpus.

import { format, formatForm, formatSelection } from "../format.js";
import { corpusFiles, equal, mark, marked } from "./check.js";
import { SNIPPETS } from "./sexp.test.js";

const lines = (...all) => all.join("\n");

equal("a rule's body lines up after its arrow", format(lines(
  "rule (path X Z) <-- (path X Y)",
  "   (edge Y Z)",
)), lines(
  "rule (path X Z) <-- (path X Y)",
  "                    (edge Y Z)",
));

equal("the first line after a lone keyword sets the column", format(lines(
  "rule",
  "  (edge 1 2) (edge 2 3)",
  "(edge 3 4)",
)), lines(
  "rule",
  "  (edge 1 2) (edge 2 3)",
  "  (edge 3 4)",
));

equal("arrows and comments on their own lines keep their columns", format(lines(
  "rule (eval (app ef es) rho t v)",
  " <--",
  "  ;; the operator first",
  "        (eval ef rho t (closure (lambda xs eb) rhoc))",
)), lines(
  "rule (eval (app ef es) rho t v)",
  " <--",
  "  ;; the operator first",
  "     (eval ef rho t (closure (lambda xs eb) rhoc))",
));

equal("a list's lines keep their place relative to its opener", format(lines(
  "rule (program X) <--",
  "        (let 0 (lambda [1] (ref 1))",
  "          (app (ref 0) [(num 1)]))",
)), lines(
  "rule (program X) <--",
  "     (let 0 (lambda [1] (ref 1))",
  "       (app (ref 0) [(num 1)]))",
));

equal("closers move up, padding inside brackets goes, lined-up spaces stay", format(lines(
  "rule (a I X 0)   <-- ( iter I )",
  "rule (b1 X M 0)  <-- (iter I",
  "  )",
)), lines(
  "rule (a I X 0)   <-- (iter I)",
  "rule (b1 X M 0)  <-- (iter I)",
));

equal("a closer after a comment stays on its own line", format("table (p int ;; the key\n)"), "table (p int ;; the key\n         )");

equal("a long one-line rule breaks into heads, arrow and bodies", format(
  "rule (walk J) <-- (walk I) (< I 199) (a I X P) (b1 X M R) (= J (+ I 1))", 40,
), lines(
  "rule (walk J)",
  " <-- (walk I)",
  "     (< I 199)",
  "     (a I X P)",
  "     (b1 X M R)",
  "     (= J (+ I 1))",
));

equal("a long atom breaks after its first argument", format(
  "rule (eval (if e1 e2 e3) rho t (eval (select_branch (eval e1 rho t) e2 e3) rho t))", 64,
), lines(
  "rule (eval (if e1 e2 e3)",
  "           rho",
  "           t",
  "           (eval (select_branch (eval e1 rho t) e2 e3) rho t))",
));

equal("a long query breaks, the projection on the arrow's line", format(
  "? (path X Y) (edge Y Z) (label Z L) -> (X L)", 30,
), lines(
  "? (path X Y)",
  "  (edge Y Z)",
  "  (label Z L)",
  "-> (X L)",
));

equal("glued tokens stay glued", format("?(path  X Y)"), "?(path  X Y)");
equal("text with a fault is left alone", format("rule (path X"), null);

equal("formatSelection keeps the cursor on its character",
  mark(formatSelection(...Object.values(marked("rule (p ( q| X ) )")))),
  "rule (p (q| X))");

equal("formatForm formats the form at the cursor and nothing else",
  mark(formatForm(...Object.values(marked("rule (a  ( b ) )\nrule (c ( d| ) )\nrule (e ( f ) )")))),
  "rule (a  ( b ) )\nrule (c (d|))\nrule (e ( f ) )");

// Over the corpus: formatting twice is formatting once, and only space
// changes.
const corpus = [...SNIPPETS, ...corpusFiles().map((file) => file.text)];
const unstable = [];
const changed = [];
for (const text of corpus) {
  for (const width of [80, 30]) {
    const once = format(text, width);
    if (format(once, width) !== once) unstable.push(`${width}: ${text.slice(0, 40)}`);
    if (once.replace(/\s/g, "") !== text.replace(/\s/g, "")) changed.push(text.slice(0, 40));
  }
}
equal("format is idempotent", unstable, []);
equal("format changes only space", changed, []);
