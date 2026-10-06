// The command palette: every action of the studio by name, from Cmd+K or
// Cmd/Ctrl+Shift+P, or the header's ⋯. It is the home of the controls that
// are not always on screen (modes, panels, restart, structured editing).
//
//   createPalette(commands)   commands() lists { title, keys?, note?, about?, run }
//   returns { open(query = "") }
// A command's `note` says its state ("current", "on"); `keys`, its shortcut;
// `about`, a line under the title on what it does.

// The commands whose title (or note, or about) holds every word of `query`,
// those whose title starts with it first; otherwise in their own order.
export function rank(commands, query) {
  const words = query.toLowerCase().split(/\s+/).filter(Boolean);
  const q = words.join(" ");
  const matching = commands.filter((command) => {
    const text = `${command.title} ${command.note ?? ""} ${command.about ?? ""}`.toLowerCase();
    return words.every((word) => text.includes(word));
  });
  const starts = (command) => (q && command.title.toLowerCase().startsWith(q) ? 0 : 1);
  return matching.map((command, i) => [starts(command), i, command])
    .sort((a, b) => a[0] - b[0] || a[1] - b[1])
    .map(([, , command]) => command);
}

export function createPalette(commands) {
  const backdrop = document.body.appendChild(Object.assign(document.createElement("div"), { className: "palette-backdrop", hidden: true }));
  const box = backdrop.appendChild(Object.assign(document.createElement("div"), { className: "palette" }));
  box.setAttribute("role", "dialog");
  box.setAttribute("aria-label", "Commands");
  const input = box.appendChild(Object.assign(document.createElement("input"), {
    type: "text", spellcheck: false, autocomplete: "off", placeholder: "Type a command",
  }));
  const list = box.appendChild(Object.assign(document.createElement("ul"), { className: "palette-list" }));
  let shown = [];
  let index = 0;
  let returnTo = null; // where focus was, to go back to

  function render() {
    shown = rank(commands(), input.value);
    index = Math.min(index, Math.max(0, shown.length - 1));
    list.replaceChildren(...shown.map((command, i) => {
      const item = document.createElement("li");
      item.className = i === index ? "chosen" : "";
      item.append(Object.assign(document.createElement("span"), { className: "title", textContent: command.title }));
      if (command.note) item.append(Object.assign(document.createElement("span"), { className: "note", textContent: command.note }));
      if (command.keys) item.append(Object.assign(document.createElement("kbd"), { textContent: command.keys }));
      if (command.about) item.append(Object.assign(document.createElement("span"), { className: "about", textContent: command.about }));
      item.addEventListener("mousedown", (event) => { event.preventDefault(); choose(i); });
      return item;
    }));
    if (!shown.length) list.append(Object.assign(document.createElement("li"), { className: "empty", textContent: "No command matches" }));
    list.children[index]?.scrollIntoView({ block: "nearest" });
  }

  function close(refocus = true) {
    if (backdrop.hidden) return;
    backdrop.hidden = true;
    if (refocus) returnTo?.focus?.();
  }

  function choose(i) {
    const command = shown[i];
    if (!command) return;
    close();
    command.run();
  }

  input.addEventListener("input", () => { index = 0; render(); });
  input.addEventListener("keydown", (event) => {
    const move = { ArrowDown: 1, ArrowUp: -1 }[event.key];
    if (move && shown.length) {
      event.preventDefault();
      index = (index + move + shown.length) % shown.length;
      render();
    } else if (event.key === "Enter") {
      event.preventDefault();
      choose(index);
    } else if (event.key === "Escape") {
      event.preventDefault();
      event.stopPropagation();
      close();
    }
  });
  input.addEventListener("blur", () => close(false));
  backdrop.addEventListener("mousedown", (event) => { if (event.target === backdrop) close(); });

  return {
    open(query = "") {
      if (backdrop.hidden) returnTo = document.activeElement;
      backdrop.hidden = false;
      input.value = query;
      index = 0;
      render();
      input.focus();
      input.select();
    },
  };
}
