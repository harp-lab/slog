// The program summary strip above the editor: the model's summary of the
// program, the analyzer's summary and findings, and whether they are being
// computed, describe an older text ("stale"), or are unavailable. Per-form
// one-liners and findings go into the editor, but only when they describe
// the text on screen: once shown they move with edits, while lines from an
// older text would land on the wrong forms.
//
// `current()` is { version, dirty, shown }: the main file's version, whether
// an edit to it is not yet sent, and whether it is the file in the editor.

export function createSummary(element, { editor, current }) {
  let view = null;
  let open = false;

  const head = element.appendChild(document.createElement("div"));
  head.className = "summary-head";
  const badge = head.appendChild(Object.assign(document.createElement("span"), { className: "summary-state" }));
  const text = head.appendChild(Object.assign(document.createElement("span"), { className: "summary-text" }));
  const toggle = head.appendChild(Object.assign(document.createElement("button"), {
    className: "icon small", title: "Show the whole summary and the analyzer's findings",
  }));
  toggle.setAttribute("aria-expanded", "false");
  const body = element.appendChild(Object.assign(document.createElement("div"), { className: "summary-body", hidden: true }));
  toggle.addEventListener("click", () => {
    open = !open;
    render();
  });

  const describes = (part) => {
    const { version, dirty } = current();
    return part && !dirty && part.version === version;
  };

  function render() {
    // The strip earns its space only with something to say: a summary, an
    // analysis, or why one failed. Nothing yet, or no way to make one, shows
    // nothing.
    const { unavailable, analyzer, working, summary, analysis, errors } = view ?? {};
    element.hidden = !(summary || analysis || errors?.length);
    if (element.hidden) return;
    const stale = [summary, analysis].some((part) => part && !describes(part));
    // Nothing at all can be computed: the strip only says why.
    const off = unavailable && !analyzer;
    const [dot, state] =
      off ? [null, "unavailable"]
        : working ? ["busy", "summarizing…"]
        : errors.length ? ["bad", "failed"]
        : stale ? [null, "stale"]
        : summary || analysis ? ["ok", ""]
        : [null, ""];
    badge.replaceChildren();
    if (dot) badge.append(Object.assign(document.createElement("span"), { className: `state ${dot}` }));
    badge.append(state);
    badge.classList.toggle("stale", state === "stale");
    text.textContent = summary?.summary ?? analysis?.summary ?? errors[0] ?? "";
    text.title = text.textContent;

    toggle.hidden = off;
    toggle.textContent = open ? "▴" : "▾";
    toggle.setAttribute("aria-expanded", String(open));
    element.classList.toggle("open", open);
    body.hidden = !open;
    body.replaceChildren();
    const line = (className, content) => body.appendChild(Object.assign(document.createElement("div"), { className, textContent: content }));
    if (unavailable && !off) line("summary-note", unavailable);
    for (const error of errors) line("summary-error", error);
    if (analysis) {
      // Without a model summary, the analyzer's already heads the strip.
      if (analysis.summary && summary) line("summary-analysis", `Analyzer: ${analysis.summary}`);
      for (const finding of analysis.findings) {
        const row = body.appendChild(document.createElement("div"));
        row.className = `finding ${finding.severity}`;
        const at = row.appendChild(Object.assign(document.createElement("a"), { textContent: `line ${finding.line}` }));
        at.addEventListener("click", () => editor.reveal({ line: finding.line, col: 1 }));
        row.append(` ${finding.severity}: ${finding.message}`);
      }
    }
  }

  return {
    // With no view, show the last one again: the main file is back in the
    // editor.
    show(next = view) {
      view = next;
      const shown = current().shown;
      if (shown && describes(view?.summary)) editor.notes(view.summary.forms);
      if (shown && describes(view?.analysis)) editor.findings(view.analysis.findings);
      render();
    },
    // The text or its version changed: the parts may have gone stale.
    refresh: render,
  };
}
