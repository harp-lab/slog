// A result set in a window of its own (/results?set=rN#TOKEN): the same
// sets as the studio's Results area, in the full table, over a WebSocket of
// its own to the same studio. Sets opened here, by a query or a refinement,
// open in the studio too; closing the window loses nothing.

import { createResults } from "./results.js";

const $ = (id) => document.getElementById(id);
const token = location.hash.slice(1);
const params = new URLSearchParams(location.search);
const project = params.get("project") ?? "";
let wanted = params.get("set"); // the set to show once the studio says it exists

let socket = null;
const send = (message) => {
  if (socket?.readyState === WebSocket.OPEN) socket.send(JSON.stringify(message));
};

const pageNote = $("page-note");
let noteTimer = 0;
function note(message, error = false) {
  pageNote.textContent = message;
  pageNote.classList.toggle("error", error);
  clearTimeout(noteTimer);
  noteTimer = setTimeout(() => { pageNote.textContent = ""; }, 6000);
}

const results = createResults({
  tabs: $("result-tabs"),
  panel: $("results"),
  send,
  run: (line) => send({ t: "command", line }),
  full: true,
});

const ask = $("ask");
ask.addEventListener("keydown", (event) => {
  if (event.key !== "Enter" || !ask.value.trim()) return;
  send({ t: "command", line: ask.value.trim() });
  ask.select();
});

const receive = {
  init({ results: views }) {
    results.init(views);
    if (wanted) results.show(wanted);
    wanted = null;
  },
  "result-set": (view) => results.update(view),
  rows: (reply) => results.rows(reply),
  // The newest set opened, from here or from the studio, is shown.
  entry(entry) {
    if (entry.set) results.show(entry.set);
    else if (entry.error && entry.origin === "repl") note(entry.error.message, true);
  },
  notice: ({ message }) => note(message, true),
};

function connect() {
  const scheme = location.protocol === "https:" ? "wss" : "ws";
  const query = `token=${encodeURIComponent(token)}&project=${encodeURIComponent(project)}`;
  socket = new WebSocket(`${scheme}://${location.host}/ws?${query}`);
  socket.onmessage = (message) => {
    const data = JSON.parse(message.data);
    receive[data.t]?.(data);
  };
  socket.onclose = () => {
    note("disconnected from the studio; reconnecting…", true);
    setTimeout(connect, 1000);
  };
}

connect();
