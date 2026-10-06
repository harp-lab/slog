// jsc -m run.js -- [FILE.slog ...]: every test module, then the summary.
// The .slog files named are a corpus for the invariant checks.

import "./sexp.test.js";
import { finish } from "./check.js";

finish();
