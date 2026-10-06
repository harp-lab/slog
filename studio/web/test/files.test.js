// The project's files as a tab holds them: what it sends when the studio's
// snapshot arrives. Two projects each with a main.slog count their versions
// from the start alike, so a tab that reconnects to another project (its
// default moved; the server restarted) must not take its own text for the
// other project's file.

import { carried, createFiles } from "../files.js";
import { equal } from "./check.js";

// Just enough of a DOM for createFiles: every element takes anything.
const element = () => new Proxy(function () {}, {
  get: (target, key) => (key === Symbol.toPrimitive ? () => "" : element()),
  set: () => true,
  apply: () => element(),
});
globalThis.document = { getElementById: element, createElement: element, title: "" };
globalThis.window = { prompt: () => null, confirm: () => false };
// Timers never fire here: the tests flush by hand.
globalThis.setTimeout ??= () => 1;
globalThis.clearTimeout ??= () => {};
globalThis.Option ??= function Option() {};

function tab() {
  const sent = [];
  let current = "";
  const editor = {
    show(path, text) { current = text; },
    set(text) { current = text; },
    get: () => current,
    forget() {},
    reveal() {},
    mark() {},
  };
  const files = createFiles({
    editor,
    transmit: (message) => sent.push(message),
    note() {},
    onOpen() {},
    onSaved() {},
    onBreakpoints() {},
  });
  const snapshot = (project, text, version = 1) => ({
    project, projects: ["one", "two"], directory: `/p/${project}`, breakpoints: {}, main: "main.slog",
    files: [{ path: "main.slog", text, version, saved: true }],
  });
  return { files, sent, snapshot, editor };
}

// Type `text` into the shown file and send it.
function type(files, editor, text) {
  editor.set(text);
  files.changed();
  files.flush();
}

{
  const { files, sent, snapshot } = tab();
  files.receive.init(snapshot("one", "rule (one)\n"));
  // the server restarts or the default moves: the tab reconnects to "two",
  // whose main.slog is also at version 1
  files.receive.init(snapshot("two", "rule (two)\n"));
  equal("another project's snapshot sends nothing", sent, []);
  equal("and shows that project's text", files.texts(), ["rule (two)\n"]);
  equal("of that project", files.project(), "two");
}

{
  const { files, sent, snapshot, editor } = tab();
  files.receive.init(snapshot("one", "rule (one)\n"));
  type(files, editor, "rule (one)\nrule (typed)\n");
  equal("an edit names its project", sent.map(({ t, project, file }) => [t, project, file]),
    [["edit", "one", "main.slog"]]);
  // the connection drops before the answer; it comes back on "two"
  sent.length = 0;
  files.receive.init(snapshot("two", "rule (one)\n"));
  equal("unsent typing is not carried to another project, even onto equal text", sent, []);
}

{
  const { files, sent, snapshot, editor } = tab();
  files.receive.init(snapshot("one", "rule (one)\n"));
  type(files, editor, "rule (one)\nrule (typed)\n");
  sent.length = 0;
  // the same project again, its text unchanged, at another version (a restart)
  files.receive.init(snapshot("one", "rule (one)\n", 7));
  equal("unsent typing over the same text of the same project is sent again",
    sent.map(({ project, base, text }) => [project, base, text]), [["one", 7, "rule (one)\nrule (typed)\n"]]);
}

{
  const { files, sent, snapshot } = tab();
  files.receive.init(snapshot("one", "rule (one)\n", 3));
  // the same project, the same version number, another text (a restart, then
  // another tab's edits): the studio's text stands
  files.receive.init(snapshot("one", "rule (theirs)\n", 3));
  equal("a matching version alone keeps nothing", sent, []);
  equal("the studio's text is shown", files.texts(), ["rule (theirs)\n"]);
}

equal("carried: no knowledge", carried(undefined, "t"), "t");
equal("carried: unsent over the same text", carried({ text: "t", local: "t+" }, "t"), "t+");
equal("carried: over another text", carried({ text: "s", local: "s+" }, "t"), "t");
