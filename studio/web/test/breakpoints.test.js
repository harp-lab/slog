// breakpoints.js's model: which clauses of a rule can stop on their own,
// how they are spelled for `break`, and the live checks of a breakpoint's
// clause and condition.

import { breakables, constructorsOf, clauseError, conditionError, demandsOf, ruleVariables, stopOf } from "../breakpoints.js";
import { forms, formAt } from "../forms.js";
import { equal as check } from "./check.js";

const STLC = `demand (lookup tenv str) ty
rule (lookup (ext env y _) x t) <-- (/= x y) (lookup env x t)
demand (ck tenv tm) ty
rule (ck env (var x) (lookup env x))
rule (ck env (app e1 e2) t2)
 <--
     (ck env e1 (arrow t1 t2))
     (ck env e2 t1)
table (seen tm)
rule (prog e) ~(seen e) (= t (ck (mt) e)) --> (typed e t) (ck (mt) e)
`;
const demands = demandsOf(STLC);
const rule = (line) => formAt(forms(STLC), line);
const at = (line) => breakables(STLC, rule(line), demands).map((b) => [b.at.join(":"), b.clause]);

check("demands: inputs and answers", [...demands], [["lookup", { inputs: 2, answers: 1 }], ["ck", { inputs: 2, answers: 1 }]]);
// a judgment head answers; a body judgment asks, with its inputs as written;
// a guard cannot stop on its own
check("clauses: recursion through a guard", at(2), [
  ["2:6", "answer (lookup _ x t)"],
  ["2:46", "demand (lookup env x)"],
]);
// a call in value position is asked by the rule
check("clauses: a call in an answer", at(4), [["4:6", "answer (ck env _ _)"], ["4:22", "demand (lookup env x)"]]);
// the two asks of rule 5 are told apart by their variables
check("clauses: two asks of one relation", at(5), [
  ["5:6", "answer (ck env _ t2)"],
  ["7:6", "demand (ck env e1)"],
  ["8:6", "demand (ck env e2)"],
]);
// a negation does not stop; a nested call does; a plain atom matches; a
// head of the demand's input arity asks; a computed argument is _
check("clauses: match, negation, binding, emit, ask", at(10), [
  ["10:6", "match (prog e)"],
  ["10:30", "demand (ck _ e)"],
  ["10:47", "emit (typed e t)"],
  ["10:59", "demand (ck _ e)"],
]);
check("clauses: only rules", breakables(STLC, rule(1), demands), []);

check("clause: fine", clauseError("demand (ck _ (app _ _))", demands), null);
check("clause: arity of an ask", clauseError("demand (ck _)", demands), "ck is asked with 2 inputs");
check("clause: arity of an answer", clauseError("answer (ck _ _)", demands),
  "an answer of ck has 3 terms: its inputs, then its answers");
check("clause: not a demand", clauseError("demand (seen _)", demands), "seen is not a demand");
check("clause: a kind first", clauseError("(ck _ _)", demands), "starts demand, answer, match or emit");

const bound = ruleVariables(STLC, rule(5));
check("variables: the rule's", [...bound].sort(), ["e1", "e2", "env", "t1", "t2"]);
check("condition: fine", conditionError("(= e1 (lam _ _ _)) (/= t1 t2)", bound), null);
check("condition: a constructor's name is not a variable", conditionError("(= e1 (var x))", bound), "x is not a variable here");
check("condition: unknown variable", conditionError("(< n 3)", bound), "n is not a variable here");
check("condition: operator", conditionError("(~ e1 e2)", bound), "~ is not one of = /= < <= > >=");
check("condition: two terms", conditionError("(= e1)", bound), "(= …) compares two terms");
check("condition: brackets", conditionError("(= e1 (lam", bound), "the brackets do not balance");

check("stop: a break's port", stopOf({ lines: ["7d · iteration 3 · phase read", "port b2:emit@stlc.slog:17:1:delta:ck#2"] }),
  { id: "b2", port: "emit", file: "stlc.slog", line: 17 });
check("stop: a step's port", stopOf({ lines: ["port fire@reach.slog:14:1:all:edge"] }),
  { id: null, port: "fire", file: "reach.slog", line: 14 });

// a clause keeps its constructor terms and their variables, so the stop
// has every variable the clause binds; a call or a primitive is `_`
const CEK = `union (kont (halt str) (ar expr kont) (fn val kont))
union (val (clo str expr) (zero))
table (ret val kont)
table (eval expr kont)
rule (ret V (ar A K)) --> (eval A (fn V K))
rule (ret V (fn (clo X B) K)) (= n (+ 1 2)) --> (eval B (halt "x"))
`;
const ctors = constructorsOf(CEK);
check("constructors: union members", [...ctors].sort(), ["ar", "clo", "fn", "halt", "zero"]);
const cek = (line) => breakables(CEK, formAt(forms(CEK), line), new Map(), ctors).map((b) => b.clause);
check("clauses: nested terms keep their variables", cek(5), ["match (ret V (ar A K))", "emit (eval A (fn V K))"]);
check("clauses: deeper, with a literal", cek(6), ["match (ret V (fn (clo X B) K))", "emit (eval B (halt \"x\"))"]);
