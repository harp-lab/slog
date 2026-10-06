// The Alt+H key's states and the notes a hint picks (hints.js), and the
// command palette's ranking (palette.js).

import { TAP_MS, hintKey, proximate } from "../hints.js";
import { rank } from "../palette.js";
import { equal } from "./check.js";

const states = (key) => ({ shown: key.shown, locked: key.locked });

// held: shown from the press, gone at the release
let key = hintKey();
key.press(0);
equal("a press shows", states(key), { shown: true, locked: false });
key.release(TAP_MS + 200);
equal("a hold's release hides", states(key), { shown: false, locked: false });

// a tap locks; the next press unlocks, and its release changes nothing
key.press(0);
key.release(TAP_MS - 100);
equal("a tap locks", states(key), { shown: true, locked: true });
key.press(1000);
equal("a press unlocks", states(key), { shown: false, locked: false });
key.release(1050);
equal("its release stays unlocked", states(key), { shown: false, locked: false });

// Esc unlocks, and says whether anything was showing
key = hintKey();
equal("Esc with nothing shown", key.escape(), false);
key.press(0);
key.release(10);
equal("Esc while locked", key.escape(), true);
equal("Esc unlocks", states(key), { shown: false, locked: false });

// losing focus mid-hold hides, but keeps a lock
key = hintKey();
key.press(0);
key.blur();
equal("blur ends a hold", states(key), { shown: false, locked: false });
key.toggle();
key.blur();
equal("blur keeps a lock", states(key), { shown: true, locked: true });

// the form holding the line, and its neighbours
const notes = [{ line: 3, text: "a" }, { line: 7, text: "b" }, { line: 12, text: "c" }];
const texts = ({ before, here, after }) => [before?.text ?? null, here?.text ?? null, after?.text ?? null];
equal("inside a middle form", texts(proximate(notes, 9)), ["a", "b", "c"]);
equal("on a form's first line", texts(proximate(notes, 7)), ["a", "b", "c"]);
equal("before the first form", texts(proximate(notes, 1)), [null, null, "a"]);
equal("in the last form", texts(proximate(notes, 40)), ["b", "c", null]);
equal("no notes", texts(proximate([], 5)), [null, null, null]);

// the palette: every word must match; titles starting with the query first
const commands = [
  { title: "Run" },
  { title: "Mode: fast", note: "current" },
  { title: "Mode: debug" },
  { title: "Debug: run at the breakpoints" },
  { title: "Restart the session server" },
];
const titles = (query) => rank(commands, query).map((command) => command.title);
equal("no query keeps the order", titles("").length, commands.length);
equal("a word anywhere", titles("server"), ["Restart the session server"]);
equal("a prefix first", titles("debug"), ["Debug: run at the breakpoints", "Mode: debug"]);
equal("every word", titles("mode fast"), ["Mode: fast"]);
equal("notes match too", titles("current"), ["Mode: fast"]);
equal("case does not matter", titles("RUN"), ["Run", "Debug: run at the breakpoints"]);
equal("nothing matches", titles("zzz"), []);
