// Hints: what the form at the cursor is and the few keys that matter
// there. They show only on request: while Alt+H is held (a peek), or from a
// tap until the next tap or Esc (locked). They sit in one card at the
// editor's bottom edge, out of the code, so nothing on screen moves.
// Elsewhere they only reveal the placeholders and notes of the region that
// has focus: the region gets `data-hinting`, which studio.css keys on.
//
//   createHints({ editor, element, keysAt, onChange })
//     element    where the card goes (the editor's container)
//     keysAt     line -> [key hints], most useful first
//     onChange   (shown, locked), after every change
//   returns { toggle(), shown, locked }

export const TAP_MS = 300; // a press shorter than this is a tap
const MAX_KEYS = 3;
// The regions a hint can be "near": the one holding focus.
const REGIONS = "#editor, #repl, #drawer, header, #files";

// The Alt+H key as state: a press shows the hints, its release hides them
// again unless it came quickly (a tap), which locks them on; the next press,
// or Esc, unlocks. Times are in milliseconds.
export function hintKey() {
  let locked = false;
  let held = null; // when the press began
  return {
    get shown() { return locked || held !== null; },
    get locked() { return locked; },
    press(now) {
      if (locked) locked = false;
      else held = now;
    },
    release(now) {
      if (held === null) return;
      if (now - held < TAP_MS) locked = true;
      held = null;
    },
    // Whether anything was showing.
    escape() {
      const shown = this.shown;
      locked = false;
      held = null;
      return shown;
    },
    blur() { held = null; },
    toggle() {
      locked = !locked;
      held = null;
    },
  };
}

// The note of the form holding `line`, and its neighbours': `notes` are
// { line, text } sorted by line, each at its form's first line.
export function proximate(notes, line) {
  const i = notes.findLastIndex((note) => note.line <= line);
  return {
    before: i > 0 ? notes[i - 1] : null,
    here: i >= 0 ? notes[i] : null,
    after: notes[i + 1] ?? null,
  };
}

export function createHints({ editor, element, keysAt, onChange }) {
  const key = hintKey();
  const card = element.appendChild(Object.assign(document.createElement("div"), { className: "hint-card", hidden: true }));
  const row = (className) => card.appendChild(Object.assign(document.createElement("div"), { className }));
  const before = row("hint-near");
  const here = row("hint-here");
  const after = row("hint-near");
  const keys = row("hint-keys");
  let region = null;

  function render() {
    const shown = key.shown;
    const near = shown ? document.activeElement?.closest(REGIONS) ?? element : null;
    if (near !== region) {
      region?.removeAttribute("data-hinting");
      near?.setAttribute("data-hinting", "");
      region = near;
    }
    card.hidden = region !== element;
    if (!card.hidden) fill();
    onChange?.(shown, key.locked);
  }

  function fill() {
    const { line, notes } = editor.context();
    const near = proximate(notes, line);
    for (const [node, note] of [[before, near.before], [here, near.here], [after, near.after]]) {
      node.textContent = note?.text ?? "";
      node.hidden = !note;
    }
    keys.replaceChildren(...keysAt(line).slice(0, MAX_KEYS).map((text) => Object.assign(document.createElement("span"), { textContent: text })));
    if (key.locked) keys.append(Object.assign(document.createElement("span"), { className: "hint-lock", textContent: "locked · Esc" }));
    // At the bottom edge, unless the cursor's line is under it.
    card.classList.remove("top");
    const top = editor.cursorTop();
    if (top !== null && top + 24 > element.clientHeight - card.offsetHeight - 16) card.classList.add("top");
  }

  // `code`, not `key`: on a Mac, Option+H types a character.
  const isHintKey = (event) => event.altKey && !event.ctrlKey && !event.metaKey && event.code === "KeyH";
  addEventListener("keydown", (event) => {
    // Esc unlocks, unless it closes the palette.
    if (event.key === "Escape" && !event.target.closest?.(".palette") && key.escape()) render();
    if (!isHintKey(event)) return;
    event.preventDefault();
    event.stopPropagation();
    if (event.repeat) return;
    key.press(performance.now());
    render();
  }, true);
  addEventListener("keyup", (event) => {
    if (event.code !== "KeyH" && event.key !== "Alt") return;
    key.release(performance.now());
    render();
  }, true);
  addEventListener("blur", () => { key.blur(); render(); });
  addEventListener("focusin", () => { if (key.shown) render(); });
  editor.onMove(() => { if (!card.hidden) fill(); });
  render();

  return {
    toggle() { key.toggle(); render(); },
    get shown() { return key.shown; },
    get locked() { return key.locked; },
  };
}
