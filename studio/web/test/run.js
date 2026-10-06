// jsc -m run.js -- [FILE.slog ...]: every test module, then the summary.
// The .slog files named are a corpus for the invariant checks.

import "./sexp.test.js";
import "./format.test.js";
import "./complete.test.js";
import "./commands.test.js";
import "./emacs.test.js";
import "./trace.test.js";
import "./live.test.js";
import "./markdown.test.js";
import "./hints.test.js";
import "./hunks.test.js";
import "./graph.test.js";
import "./assist.test.js";
import "./table.test.js";
import "./breakpoints.test.js";
import "./timeline.test.js";
import "./static-check.test.js";
import "./inspect.test.js";
import "./stamp.test.js";
import "./lint.test.js";
import { finish } from "./check.js";

finish();
