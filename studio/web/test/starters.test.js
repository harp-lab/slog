// What the strip above the editor offers (starters.js): the starter a
// project was just made from, else the first starter on an empty project.

import { offer } from "../starters.js";
import { equal } from "./check.js";

const starters = [
  { id: "getting-started", title: "Getting started", about: "Paths." },
  { id: "kcfa", title: "k-CFA", about: "Closures." },
];
const empty = [{ path: "main.slog", text: "  \n" }];
const written = [{ path: "main.slog", text: "table (t int)\n" }];

equal("a project just made from a starter names it", offer(starters, written, "kcfa"), { made: starters[1] });
equal("an empty project offers the first starter", offer(starters, empty, null), { first: starters[0] });
equal("a project with a program offers nothing", offer(starters, written, null), null);
equal("an unknown starter is no starter", offer(starters, written, "gone"), null);
equal("no starters, no offer", offer([], empty, null), null);
