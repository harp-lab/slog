// The cells column, at the right of the studio: tables broken out of the
// transcript, of a peek, or of a break-out, kept while the author works.
// Each cell is a view of explorer.js, read at one state of the session and
// stamped with it; when the database moves on, the cell says which state
// it shows ("from t5") and reads the new one only when asked. Cells stack;
// each folds, moves by dragging its head, or goes (×). The column tucks
// away to a thin edge, and back, with a click on its edge or Alt+C.

const element = (tag, className, text) => {
  const node = document.createElement(tag);
  if (className) node.className = className;
  if (text !== undefined) node.textContent = text;
  return node;
};

// `host` is the column. Returns { add(view) }.
export function createCells(host) {
  host.classList.add("cells");
  host.hidden = true;
  let dragged = null;
  const edge = host.appendChild(element("button", "cells-edge", "⟩"));
  edge.title = "Tuck the cells away, or bring them back (Alt+C)";
  const tuck = (on = !host.classList.contains("tucked")) => {
    host.classList.toggle("tucked", on);
    edge.textContent = on ? "⟨" : "⟩";
  };
  edge.addEventListener("click", () => tuck());
  addEventListener("keydown", (event) => {
    if (!(event.altKey && event.code === "KeyC" && !event.metaKey && !event.ctrlKey) || host.hidden) return;
    event.preventDefault();
    tuck();
  }, true);
  const count = () => host.querySelectorAll(".cell").length;

  // `view` is an explorer view; its head becomes the cell's head.
  function add(view) {
    const cell = element("section", "cell");
    const head = view.el.querySelector(".pk-head");
    head.draggable = true;
    cell.append(view.el);
    edge.after(cell);
    host.hidden = false;
    tuck(false);

    view.buttons.replaceChildren();
    const button = (label, title, act) => {
      const node = view.buttons.appendChild(element("button", "pk-button", label));
      node.title = title;
      node.addEventListener("click", (event) => { event.stopPropagation(); act(node); });
      return node;
    };
    view.refreshButton = button("⟳", "Read it again, as the session is now", () => view.refresh());
    button("▾", "Fold or unfold", (node) => {
      const folded = cell.classList.toggle("folded");
      node.textContent = folded ? "▸" : "▾";
      if (!folded) view.table.refresh();
    });
    button("×", "Throw this cell away", () => {
      view.close();
      cell.remove();
      host.hidden = !count();
    });

    head.addEventListener("dragstart", (event) => {
      dragged = cell;
      event.dataTransfer.effectAllowed = "move";
      event.dataTransfer.setData("text/plain", "");
    });
    head.addEventListener("dragend", () => { dragged = null; });
    cell.addEventListener("dragover", (event) => {
      if (!dragged || dragged === cell) return;
      event.preventDefault();
      const box = cell.getBoundingClientRect();
      cell.classList.toggle("drop-before", event.clientY < box.top + box.height / 2);
      cell.classList.toggle("drop-after", event.clientY >= box.top + box.height / 2);
    });
    cell.addEventListener("dragleave", () => cell.classList.remove("drop-before", "drop-after"));
    cell.addEventListener("drop", (event) => {
      event.preventDefault();
      const after = cell.classList.contains("drop-after");
      cell.classList.remove("drop-before", "drop-after");
      if (dragged && dragged !== cell) cell[after ? "after" : "before"](dragged);
    });
    host.scrollTop = 0;
    return cell;
  }

  return { add };
}
