// The dialog that appears when a debug action cannot stop because the run
// already reached its fixpoint (studio/src/rewind.rs): it says so, and asks
// where to go back to -- rerun from scratch under the breakpoints (the
// default), branch from a state of the session's tree, or nothing.  Either
// way the rerun is a branch: the line the author was on stays whole.

const node = (tag, className, text) => {
  const element = document.createElement(tag);
  if (className) element.className = className;
  if (text !== undefined) element.textContent = text;
  return element;
};

// `send` reaches the studio. Returns { open({ message, default, choices }) }.
export function createRewind({ send, onBranch = () => {} }) {
  let backdrop = null;
  const close = () => {
    backdrop?.remove();
    backdrop = null;
  };
  addEventListener("keydown", (event) => {
    if (backdrop && event.key === "Escape") {
      event.preventDefault();
      close();
    }
  }, true);

  function go(from) {
    close();
    send({ t: "debug-from", from });
    onBranch();
  }

  function open({ message, default: before, choices }) {
    close();
    backdrop = document.body.appendChild(node("div", "rewind-backdrop"));
    const box = backdrop.appendChild(node("div", "rewind"));
    box.setAttribute("role", "dialog");
    box.setAttribute("aria-label", "Go back to see the breakpoints fire");
    box.append(node("h3", null, "Nothing will run again"));
    box.append(node("p", null, message));
    const actions = box.appendChild(node("div", "rewind-actions"));
    const rerun = actions.appendChild(node("button", "primary", "Rerun from scratch under the breakpoints"));
    rerun.title = before == null ? "A fresh session, the breakpoints armed"
      : `A fresh session, the breakpoints armed, recorded as a branch from t${before}`;
    rerun.addEventListener("click", () => go(null));
    const pickButton = actions.appendChild(node("button", "secondary", "Pick a state…"));
    const cancel = actions.appendChild(node("button", "secondary", "Cancel"));
    cancel.addEventListener("click", close);

    const list = box.appendChild(node("div", "rewind-states"));
    list.hidden = true;
    pickButton.addEventListener("click", () => {
      list.hidden = !list.hidden;
      pickButton.setAttribute("aria-pressed", String(!list.hidden));
    });
    list.append(node("p", "hint", "Branch from a state and re-derive it with the breakpoints armed: a Run among its steps stops there."));
    for (const choice of choices) {
      const row = list.appendChild(node("button", "rewind-state"));
      row.append(node("span", "rewind-label", choice.label), node("span", "rewind-line", choice.line || "the session before anything"));
      if (choice.id === before) row.append(node("span", "rewind-note", "before the run"));
      row.addEventListener("click", () => go(choice.id));
    }
    backdrop.addEventListener("mousedown", (event) => { if (event.target === backdrop) close(); });
    rerun.focus();
  }

  return { open };
}
