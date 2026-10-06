// Starting from an example: the starters the studio offers (starters.rs), as
// palette commands, and the strip above the editor that offers the first one
// on an empty project and, on a project just made from one, says what it is
// with its Run one click away.
//
//   createStarters({ send, run, browse })
//     returns { init(snapshot), commands(), receive, hide() }
// `run()` evaluates the program; `browse()` lists every starter.

const $ = (id) => document.getElementById(id);

// What the strip offers on a project of `files` ([{ path, text }]) opened
// just after it was made from the starter `id`, if it was: that starter,
// else the first starter when every file is empty, else nothing.
export function offer(starters, files, id) {
  const made = starters.find((starter) => starter.id === id);
  if (made) return { made };
  if (starters.length && files.every((file) => !file.text.trim())) return { first: starters[0] };
  return null;
}

export function createStarters({ send, run, browse }) {
  let starters = [];
  const strip = $("welcome");

  const start = (starter) => send({ t: "new-from-starter", id: starter.id });

  function button(text, className, onClick) {
    const node = Object.assign(document.createElement("button"), { textContent: text, className });
    node.addEventListener("click", onClick);
    return node;
  }

  function show(offered) {
    strip.hidden = !offered;
    if (!offered) return;
    const text = document.createElement("span");
    text.className = "welcome-text";
    const actions = [];
    if (offered.made) {
      text.append(Object.assign(document.createElement("strong"), { textContent: offered.made.title }), ` · ${offered.made.about}`);
      actions.push(button("Run", "primary small", () => { hide(); run(); }));
    } else {
      text.textContent = "An empty project. Start from an example:";
      actions.push(
        button(offered.first.title, "primary small", () => start(offered.first)),
        button("Browse examples…", "secondary small", browse),
      );
    }
    const close = button("×", "icon", hide);
    close.title = "Dismiss";
    strip.replaceChildren(text, ...actions, close);
  }

  function hide() {
    strip.hidden = true;
  }

  return {
    init(snapshot) {
      starters = snapshot.starters ?? [];
      // A project just made from a starter is opened with ?starter=ID, once.
      const query = new URLSearchParams(location.search);
      const id = query.get("starter");
      if (id) {
        query.delete("starter");
        history.replaceState(null, "", `?${query}${location.hash}`);
      }
      show(offer(starters, snapshot.files, id));
    },
    commands: () => starters.map((starter) => ({
      title: `New from example: ${starter.title}`,
      about: starter.about,
      run: () => start(starter),
    })),
    receive: {
      // the project made from a starter, opened in this tab
      "new-project": ({ name, starter }) => {
        const query = new URLSearchParams(location.search);
        query.set("project", name);
        query.set("starter", starter);
        location.search = query.toString(); // keeps the hash: local mode's token
      },
    },
    hide,
  };
}
