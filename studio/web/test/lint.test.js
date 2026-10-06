// slog-lint's findings follow their forms across edits made since the
// analysis ran: moved with their form, dropped when it changed.

import { place } from "../lint.js";
import { equal } from "./check.js";

const TEXT = [
  "table (edge int int)",
  "table (out int)",
  "rule (edge 1 2)",
  "rule (edge X Y)",
  "  --> (out X)",
  ";; a note",
  "",
  "rule (edge X _) --> (out X)",
].join("\n");

// as lint.rs makes it: the form's first line and its text, trailing
// comments and blank lines left out
const FINDING = {
  file: "main.slog", line: 4, col: 14, code: "singleton", message: "Y is used only once",
  form_line: 4, form: "rule (edge X Y)\n  --> (out X)",
};
const lines = (found) => found.map((f) => [f.line, f.col]);

equal("on the text it describes, a finding stays where it is", lines(place([FINDING], "main.slog", TEXT)), [[4, 14]]);
equal("another file's findings are not this one's", place([FINDING], "other.slog", TEXT), []);
equal("lines added above move it with its form",
  lines(place([FINDING], "main.slog", `table (a int)\n\n${TEXT}`)), [[6, 14]]);
equal("a comment edited after its form does not disturb it",
  lines(place([FINDING], "main.slog", TEXT.replace(";; a note", ";; a longer note"))), [[4, 14]]);
equal("an edit to its form drops it until the next analysis",
  place([FINDING], "main.slog", TEXT.replace("(edge X Y)", "(edge X Z)")), []);
