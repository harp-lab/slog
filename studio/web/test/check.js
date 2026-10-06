// A minimal harness for the browser modules' pure logic, run under
// JavaScriptCore's shell (`make -C studio test-web`), which has no console
// but `print`, `readFile`, `arguments` and `quit`.

let failed = 0;
let passed = 0;

export function equal(name, actual, expected) {
  const a = JSON.stringify(actual);
  const e = JSON.stringify(expected);
  if (a === e) {
    passed++;
  } else {
    failed++;
    print(`FAIL ${name}\n  expected ${e}\n  actual   ${a}`);
  }
}

export const ok = (name, value) => equal(name, Boolean(value), true);

export function finish() {
  print(`${passed} passed, ${failed} failed`);
  if (failed) quit(1);
}

// Text with a cursor `|`, or a selection `«…»`, as { text, selection }.
export function marked(source) {
  const at = source.indexOf("|");
  if (at >= 0) return { text: source.slice(0, at) + source.slice(at + 1), selection: { start: at, end: at } };
  const start = source.indexOf("«");
  const end = source.indexOf("»") - 1;
  if (start < 0) throw new Error(`no cursor in ${source}`);
  return { text: source.replace("«", "").replace("»", ""), selection: { start, end } };
}

// The inverse of `marked`.
export function mark({ text, selection: { start, end } }) {
  if (start === end) return text.slice(0, start) + "|" + text.slice(start);
  return text.slice(0, start) + "«" + text.slice(start, end) + "»" + text.slice(end);
}

// The .slog files named on the command line (after `--`), as
// [{ name, text }].
export const corpusFiles = () => (globalThis.arguments ?? []).map((name) => ({ name, text: readFile(name) }));
