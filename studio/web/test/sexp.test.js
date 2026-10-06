// The structural core: the tree, each paredit operation on representative
// Slog, and the invariants every operation keeps over a corpus.

import * as sexp from "../sexp.js";
import { corpusFiles, equal, mark, marked, ok } from "./check.js";

// Programs in the shapes Slog takes: nested constructors, `[…]` lists with
// ellipses, strings and comments holding brackets, refs, primed names.
export const SNIPPETS = [
  `;; A four-node chain and its transitive closure.
table (edge int int)
rule (edge X Y) --> (path X Y)
rule (path X Y) (edge Y Z) --> (path X Z)
`,
  `union (val (closure lambda pmap)    ;; code + captured environment (a "map")
           (prim str))
rule (eval_args [e es ...] rho t [(eval e rho t) (eval_args es rho t) ...])
rule (eval (app ef es) rho t v)
 <--
     (eval ef rho t (closure (lambda xs eb) rhoc))
     (= t2 (tick (app ef es) t))
`,
  `rule (label X "a (b] \\"c\\"") (x' X) --> (seen 'ref')
;; (unbalanced [ in a comment
rule (p "multi
line (string") --> (q {1 2})
`,
  `? (path X Y) (edge Y Z) (< Z 9) -> (X Z)`,
];

// The operation `name` on text marked with a cursor or selection; null when
// it leaves the keystroke to the editor.
const run = (name, source, ...args) => {
  const { text, selection } = marked(source);
  const result = sexp.paredit[name](text, selection, ...args);
  return result && mark(result);
};
const examples = (name, cases, ...args) => {
  for (const [before, after] of cases) equal(`${name} ${before}`, run(name, before, ...args), after);
};

// The tree ---------------------------------------------------------------

equal("faults: balanced", sexp.parse(SNIPPETS[2]).faults, 0);
equal("faults: unclosed, stray, mismatched, unterminated",
  ["(a (b", "a)", "(a]", "\"ab", "'ab\nc'"].map((t) => sexp.parse(t).faults), [2, 1, 1, 1, 1]);
{
  const root = sexp.parse(`(p "x)" ;; )\n 'r' x')`);
  const kinds = root.children[0].children.map((n) => n.kind);
  equal("strings, comments and refs hide brackets", kinds, ["word", "string", "comment", "ref", "word"]);
}
{
  const { text, selection } = marked(`rule (p "a(|b") --> (q)`);
  equal("leafAt: in a string", sexp.leafAt(sexp.parse(text), selection.start).kind, "string");
  equal("leafAt: before a string", sexp.leafAt(sexp.parse(text), text.indexOf("\"")), null);
}

// Typing -------------------------------------------------------------------

examples("insertOpen", [
  ["rule |", "rule (|)"],
  ["?|", "?(|)"],
  ["(edge X|)", "(edge X (|))"],
  ["(edge |X)", "(edge (|) X)"],
  ["(p \"a|\")", null],
  ["(p) ;; a|", null],
  ["(edge «X Y»)", "(edge («X Y»))"],
  ["(edge «X Y)» Z)", "(edge «X Y)» Z)"],
], "(");
equal("insertOpen: square", run("insertOpen", "(eval_args |)", "["), "(eval_args [|])");

examples("insertClose", [
  ["(path X Y|)", "(path X Y)|"],
  ["(path X Y   |)", "(path X Y)|"],
  ["(path X| Y)", "(path X Y)|"],
  ["(path X ;; c\n|)", "(path X ;; c\n)|"],
  ["(path (edge X| Y", "(path (edge X)| Y"],
  ["rule |", "rule |"],
  ["(p \"a|\")", null],
]);

examples("insertQuote", [
  ["(label X |)", "(label X \"|\")"],
  ["(label X \"ab|\")", "(label X \"ab\"|)"],
  ["(label X \"a|b\")", "(label X \"a\\\"|b\")"],
  ["(label X «ab»)", "(label X \"«ab»\")"],
  ["(label X «a\"b»)", "(label X «a\"b»)"],
  ["(p) ;; it|", null],
], "\"");
examples("insertQuote", [["(x| X)", null], ["(seen |)", "(seen '|')"]], "'");

examples("insertSemicolon", [
  ["rule (p X) ;|", null],
  ["(p X ;|Y)", "(p X ;;|\nY)"],
]);

// Deleting -----------------------------------------------------------------

examples("deleteBackward", [
  ["(path X Y)|", "(path X Y|)"],
  ["(path X ()|)", "(path X |)"],
  ["(path X (|))", "(path X |)"],
  ["(|path X Y)", "(|path X Y)"],
  ["(label \"\"|)", "(label |)"],
  ["(label \"a\"|)", "(label \"a|\")"],
  ["(label \"|a\")", "(label \"|a\")"],
  ["(label \"a\\\"|\")", "(label \"a|\")"],
  ["(path X|)", null],
  ["(p X) ;|; (q", "(p X) ;|; (q"],
  ["(p X) ;; (q|", null],
  ["(a (b|", null],
  ["(a «b) (c»)", "(a «b) (c»)"],
  ["(a «(b) (c)»)", null],
]);
examples("deleteForward", [
  ["|(path X Y)", "(|path X Y)"],
  ["(path X |())", "(path X |)"],
  ["(path X Y|)", "(path X Y|)"],
  ["(label \"a|\")", "(label \"a|\")"],
  ["(label |\"a\")", "(label \"|a\")"],
  ["(label \"|\")", "(label |)"],
]);

// Slurp and barf -----------------------------------------------------------

examples("slurpForward", [
  ["rule (path X| Y) (edge Y Z)", "rule (path X| Y (edge Y Z))"],
  ["(a ((b|)) c)", "(a ((b|) c))"],
  ["(|) X", "(|X)"],
  ["(path X| Y)", "(path X| Y)"],
  ["(a|) ;; note\n b", "(a| ;; note\n b)"],
]);
examples("barfForward", [
  ["rule (path X| Y (edge Y Z))", "rule (path X| Y) (edge Y Z)"],
  ["(|X)", "(|) X"],
  ["(|)", "(|)"],
]);
examples("slurpBackward", [
  ["(edge X Y) (path| Z)", "((edge X Y) path| Z)"],
  ["X (|)", "(X|)"],
]);
examples("barfBackward", [
  ["((edge X Y) path| Z)", "(edge X Y) (path| Z)"],
  ["(X|)", "X (|)"],
]);

// Splice, raise, wrap, split, join, kill -----------------------------------

examples("splice", [
  ["(eval (app| ef es) rho)", "(eval app| ef es rho)"],
  ["rule |(p)", "rule |(p)"],
]);
examples("raise", [
  ["(eval (closure (lambda| xs eb) rhoc))", "(eval (closure lambda| rhoc))"],
  ["(= t2 (tick |(app ef es) t))", "(= t2 |(app ef es))"],
  ["(label X \"a|b\")", "\"a|b\""],
]);
examples("wrap", [
  ["(eval |ef rho)", "(eval (|ef) rho)"],
  ["(eval «ef rho»)", "(eval («ef rho»))"],
  ["(eval ef| rho)", "(eval (|ef) rho)"],
]);
examples("split", [
  ["(path X| Y)", "(path X)| (Y)"],
  ["(path X | Y)", "(path X)| (Y)"],
  ["(label \"ab|c\")", "(label \"ab\"| \"c\")"],
  ["rule |(p)", "rule |(p)"],
]);
examples("join", [
  ["(path X)| (Y)", "(path X| Y)"],
  ["(a)|(b)", "(a| b)"],
  ["(label \"ab\" |\"c\")", "(label \"ab|c\")"],
  ["(a) |[b]", "(a) |[b]"],
]);
examples("kill", [
  ["(path X| Y (edge Y Z))", "(path X|)"],
  ["(label \"a|bc\")", "(label \"a|\")"],
  ["rule (p X) |(q\n  Y) (r)\nrule (s)", "rule (p X) | (r)\nrule (s)"],
  ["(p) ;; a |note\n(q)", "(p) ;; a |\n(q)"],
  ["(a (b| c", "(a (b| c"],
]);

// Selection and motion -----------------------------------------------------

{
  let state = marked("rule (path X Y) (edge Y| Z) --> (path X Z)\nrule (q)");
  const seen = [];
  for (let i = 0; i < 5; i++) {
    state = sexp.paredit.expandSelection(state.text, state.selection);
    seen.push(mark(state));
  }
  equal("expandSelection: word, list inside, list, form, text", seen, [
    "rule (path X Y) (edge «Y» Z) --> (path X Z)\nrule (q)",
    "rule (path X Y) («edge Y Z») --> (path X Z)\nrule (q)",
    "rule (path X Y) «(edge Y Z)» --> (path X Z)\nrule (q)",
    "«rule (path X Y) (edge Y Z) --> (path X Z)»\nrule (q)",
    "«rule (path X Y) (edge Y Z) --> (path X Z)\nrule (q)»",
  ]);
  const back = [];
  state = marked("rule (path X Y) «(edge Y Z)» --> (path X Z)");
  for (let i = 0; i < 3; i++) {
    state = sexp.paredit.contractSelection(state.text, state.selection);
    back.push(mark(state));
  }
  equal("contractSelection: list, inside, first, cursor", back, [
    "rule (path X Y) («edge Y Z») --> (path X Z)",
    "rule (path X Y) («edge» Y Z) --> (path X Z)",
    "rule (path X Y) (|edge Y Z) --> (path X Z)",
  ]);
}

examples("forwardSexp", [["rule| (p X) (q)", "rule (p X)| (q)"], ["(p X|)", "(p X)|"], ["(p \"a b|\")", "(p \"a b\"|)"]]);
examples("backwardSexp", [["rule (p X) |(q)", "rule |(p X) (q)"], ["(|p X)", "|(p X)"]]);
examples("upList", [["(eval (app ef| es))", "(eval |(app ef es))"]]);
examples("forwardUpList", [["(eval (app ef| es))", "(eval (app ef es)|)"]]);
examples("downList", [["(eval| (app ef es))", "(eval (|app ef es))"], ["rule| X", "rule| X"]]);

// Invariants over a corpus -------------------------------------------------

const corpus = [...SNIPPETS, ...corpusFiles().map((file) => file.text)];
const cursor = (pos) => ({ start: pos, end: pos });
const EDITS = ["insertOpen", "insertClose", "insertQuote", "insertSemicolon", "deleteBackward", "deleteForward",
  "slurpForward", "slurpBackward", "barfForward", "barfBackward", "splice", "raise", "wrap", "split", "join", "kill"];
const KEY = { insertOpen: "(", insertClose: ")", insertQuote: "\"", insertSemicolon: ";" };

// What the editor does with a keystroke an operation leaves to it (null).
function plainKeystroke(text, pos, name) {
  if (name === "deleteBackward") return pos > 0 ? text.slice(0, pos - 1) + text.slice(pos) : text;
  if (name === "deleteForward") return text.slice(0, pos) + text.slice(pos + 1);
  return text.slice(0, pos) + KEY[name] + text.slice(pos);
}

// At every cursor position of every program, no edit adds a fault: not the
// operation (unguarded, so the guard is a backstop and not what passes
// this), nor a keystroke it leaves to the editor.
for (const name of EDITS) {
  let broken = null;
  for (const text of corpus) {
    const before = sexp.parse(text).faults;
    for (let pos = 0; pos <= text.length && !broken; pos++) {
      const result = sexp.unguarded[name](text, cursor(pos), KEY[name]);
      const after = result ? result.text : plainKeystroke(text, pos, name);
      if (sexp.parse(after).faults > before) broken = mark({ text, selection: cursor(pos) });
    }
  }
  equal(`${name} never adds a fault`, broken, null);
}

// Round trips: barf undoes slurp, splice undoes wrap, join undoes split.
const tried = { slurpBarf: 0, slurpBarfBackward: 0, wrapSplice: 0, splitJoin: 0 };
const broken = [];
for (const text of corpus) {
  const root = sexp.parse(text);
  for (let pos = 0; pos <= text.length; pos++) {
    const at = cursor(pos);
    const check = (name, there, back) => {
      if (there.text === text) return;
      tried[name]++;
      if (sexp.paredit[back](there.text, there.selection).text !== text) broken.push(`${name} ${mark({ text, selection: at })}`);
    };
    const inText = sexp.leafAt(root, pos);
    if (!inText) check("wrapSplice", sexp.paredit.wrap(text, at), "splice");
    const list = sexp.enclosing(root, pos);
    if (inText || list === root || !list.closed || !list.children.length) continue;
    // a list with a neighbour to take, so slurp does not climb
    const siblings = list.parent.children.filter((c) => c.kind !== "comment");
    const index = siblings.indexOf(list);
    if (siblings[index + 1]) check("slurpBarf", sexp.paredit.slurpForward(text, at), "barfForward");
    if (index > 0) check("slurpBarfBackward", sexp.paredit.slurpBackward(text, at), "barfBackward");
    // one space between two S-expressions, which split replaces
    if (text[pos] === " " && /\S/.test(text[pos - 1]) && /[^\s;]/.test(text[pos + 1] ?? "")) {
      check("splitJoin", sexp.paredit.split(text, at), "join");
    }
  }
}
equal("round trips restore the text", broken.slice(0, 5), []);
ok("every round trip was tried", Object.values(tried).every((n) => n > 0));

