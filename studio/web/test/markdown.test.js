// The Markdown renderer: the shapes agent replies take, and that nothing in
// the source reaches the page as markup.

import { highlight, inline, markdown } from "../markdown.js";
import { equal, ok } from "./check.js";

const lines = (...all) => all.join("\n");

equal("paragraphs split at blank lines; soft breaks are spaces",
  markdown("one\ntwo\n\nthree"), "<p>one two</p><p>three</p>");

equal("inline code, emphasis and links",
  inline("**bold** and *it* and _it_ with `a*b*c` and [docs](https://x.org/a_b?q=1&r=2)"),
  "<strong>bold</strong> and <em>it</em> and <em>it</em> with <code>a*b*c</code> and " +
  "<a href=\"https://x.org/a_b?q=1&amp;r=2\" target=\"_blank\" rel=\"noopener noreferrer\">docs</a>");

equal("emphasis spans a link", inline("**see [x](https://a.b)**"),
  "<strong>see <a href=\"https://a.b\" target=\"_blank\" rel=\"noopener noreferrer\">x</a></strong>");

equal("snake_case names stay as written", inline("path_to_x and a * b * c"), "path_to_x and a * b * c");

equal("bare URLs link, without trailing punctuation", inline("see https://a.org/x."),
  "see <a href=\"https://a.org/x\" target=\"_blank\" rel=\"noopener noreferrer\">https://a.org/x</a>.");

equal("only web and mail links are links", inline("[x](javascript:alert(1))"), "[x](javascript:alert(1))");

equal("HTML in the source is text", markdown("<img src=x onerror=alert(1)> & `<b>`"),
  "<p>&lt;img src=x onerror=alert(1)&gt; &amp; <code>&lt;b&gt;</code></p>");

ok("HTML in a code block is text", !markdown("```\n<script>x</script>\n```").includes("<script>"));

equal("headings", markdown("## Plan\ntext"), "<h2>Plan</h2><p>text</p>");

equal("a nested list", markdown(lines(
  "- first",
  "  - inner `a`",
  "  - inner b",
  "- second",
  "",
  "after",
)), "<ul><li>first<ul><li>inner <code>a</code></li><li>inner b</li></ul></li><li>second</li></ul><p>after</p>");

equal("an ordered list keeps its start", markdown("3. c\n4. d"), "<ol start=\"3\"><li>c</li><li>d</li></ol>");

equal("a list right after a paragraph", markdown("Changes:\n1. one\n2. two"),
  "<p>Changes:</p><ol><li>one</li><li>two</li></ol>");

equal("a list item with a code block under it", markdown(lines(
  "1. Add the rule:",
  "   ```slog",
  "   rule (p X)",
  "   ```",
  "2. Done",
)), "<ol><li>Add the rule:<div class=\"code-block\"><span class=\"code-lang\">slog</span>" +
  "<button type=\"button\" class=\"copy\" title=\"Copy\">Copy</button><pre><code>" +
  "<span class=\"tok-keyword\">rule</span> (<span class=\"tok-type\">p</span> X)</code></pre></div></li><li>Done</li></ol>");

equal("a table, with alignment and inline markup", markdown(lines(
  "| relation | rows |",
  "|---|--:|",
  "| `path` | 12 |",
  "| a \\| b | 3 |",
)), "<div class=\"md-table\"><table><thead><tr><th>relation</th><th style=\"text-align:right\">rows</th></tr></thead>" +
  "<tbody><tr><td><code>path</code></td><td style=\"text-align:right\">12</td></tr>" +
  "<tr><td>a | b</td><td style=\"text-align:right\">3</td></tr></tbody></table></div>");

ok("an unclosed fence is code to the end, as a reply streams",
  markdown("text\n```slog\nrule (p 1)").includes("<pre><code><span class=\"tok-keyword\">rule</span>"));

equal("Slog colouring: keywords, heads, arrows, numbers, strings, comments",
  highlight("rule (path X Z) <-- (edge X \"y\") ;; c\n(t -1)"),
  "<span class=\"tok-keyword\">rule</span> (<span class=\"tok-type\">path</span> X Z) " +
  "<span class=\"tok-operator\">&lt;--</span> (<span class=\"tok-type\">edge</span> X <span class=\"tok-string\">&quot;y&quot;</span>) " +
  "<span class=\"tok-comment\">;; c</span>\n(<span class=\"tok-type\">t</span> <span class=\"tok-number\">-1</span>)");

equal("block quotes and rules", markdown("> quoted **x**\n\n---"),
  "<blockquote><p>quoted <strong>x</strong></p></blockquote><hr>");
