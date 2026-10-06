//! The execution trace (docs/pausing.md §15) in Studio: what arms it for a
//! run, and the agent's debugging tools over its proposed program (mcp.rs
//! lists them). `trace_run` evaluates on the preview lane, as
//! `evaluate_proposal` does; a debug run holds its run on a debug lane of its
//! own, where breaks stop wherever their rule is.
//!
//! A trace is a change record's `trace` field as compiler/session.rkt groups
//! it: strata in run order, each with its iterations, each with the
//! relations that iteration changed (signed counts and a sample of rows)
//! and the rules that fired in it.

use crate::ask::fork_report;
use crate::lane::{Lane, Mode};
use crate::session::{Outcome, Session, run_argument};
use crate::studio::Studio;
use serde_json::{Value, json};
use std::collections::{BTreeMap, BTreeSet, HashMap};
use std::path::Path;
use tokio::sync::Mutex;

/// Arms the trace for the next change at the decided defaults
/// (studio-design §8.2): counts for every relation, 8 sampled rows per
/// relation, iteration and sign, and fires per rule.
const ARM: &str = "trace on rules";

/// The command that makes a run in `mode` record its trace, if `wanted`:
/// tracing costs a Run noticeably, so only Debug and an author who asked
/// for it record one. Compiled runs are for performance work and never do.
pub fn arm(mode: Mode, wanted: bool) -> Option<String> {
    (wanted && mode != Mode::Compiled).then(|| ARM.to_owned())
}

/// The agent's debugging state, shared by its threads.
pub struct Debugger {
    /// Debug mode: the interpreter on one thread. A break stops only where
    /// its rule runs interpreted, which fast mode's tiering does not promise,
    /// and stops at the same place every run (audit D-07, D-14).
    pub(crate) lane: Lane,
    /// The lane's session, and the (thread, text hash) of the proposed
    /// program whose run it holds.
    session: Mutex<(Session, Option<(u32, u64)>)>,
    /// Per thread: lines of its proposed program where `debug_run` stops,
    /// and the trace of its latest completed traced run.
    breakpoints: std::sync::Mutex<HashMap<u32, BTreeSet<AgentBreak>>>,
    traces: std::sync::Mutex<HashMap<u32, Value>>,
}

impl Debugger {
    /// Its server starts on the first debug run.
    pub fn new(root: &Path) -> Self {
        let lane = Lane::new(root.to_path_buf(), Mode::Debug);
        Self {
            session: Mutex::new((Session::new(&lane), None)),
            lane,
            breakpoints: Default::default(),
            traces: Default::default(),
        }
    }

    fn keep(&self, thread: u32, trace: &Value) {
        self.traces.lock().expect("traces lock").insert(thread, trace.clone());
    }
}

/// One of an agent's breakpoints: a line of its proposed program, a clause
/// (`demand (infer _ (app _ _))`), or both, with what narrows it.
#[derive(Clone, Debug, Eq, Ord, PartialEq, PartialOrd)]
struct AgentBreak {
    line: Option<u32>,
    /// `demand (f t ...) when (OP a b) ignore N log`, or empty
    rest: String,
}

impl AgentBreak {
    fn command(&self, path: &str) -> String {
        match self.line {
            Some(line) if self.rest.is_empty() => format!("break {path}:{line}"),
            Some(line) => format!("break {path}:{line} {}", self.rest),
            None => format!("break {}", self.rest),
        }
    }
}

const LEGEND: &str = "One `deltas` entry per iteration, in order; the empty iteration is the fixpoint. \
`+n` rows inserted, `-n` retracted, `~n` derivations of rows already present (support changed, membership did not).";

impl Studio {
    /// Run the trace tool `name` for `thread`, or `None` when no trace tool
    /// has that name.
    pub(crate) async fn trace_tool(&self, thread: u32, name: &str, arguments: &Value) -> Option<Result<Value, String>> {
        let text = |key: &str| arguments[key].as_str().map(str::trim).filter(|value| !value.is_empty());
        let result = match name {
            "trace_run" => self.trace_fork(thread).await,
            "debug_run" => self.debug_fork(thread).await,
            "get_trace" => self.get_trace(thread, arguments),
            "set_breakpoint" => self.agent_breakpoint(thread, arguments, true),
            "clear_breakpoint" => self.agent_breakpoint(thread, arguments, false),
            "step" => match text("grain") {
                None => self.held_command(thread, "step").await,
                Some(grain @ ("match" | "fire" | "emit" | "tuple" | "into" | "over" | "out")) => {
                    self.held_command(thread, &format!("step {grain}")).await
                }
                Some(other) => Err(format!("grain {other:?} is not one of match, fire, emit, tuple, into, over, out")),
            },
            "calls" => {
                let line = match (text("call"), text("view")) {
                    (Some(call), _) => format!("calls {call} depth {}", arguments["depth"].as_u64().unwrap_or(2)),
                    (None, Some(view @ ("stack" | "failed"))) => format!("calls {view}"),
                    (None, Some(other)) => return Some(Err(format!("view {other:?} is not stack or failed"))),
                    (None, None) => "calls".to_owned(),
                };
                self.inspect(thread, &line).await
            }
            "logs" => self.inspect(thread, "logs").await,
            "continue" => self.held_command(thread, "continue").await,
            "frames" => self.held_command(thread, "frames").await,
            "abort" => self.held_command(thread, "abort").await,
            "peek" => match text("relation") {
                Some(relation) if !relation.contains(char::is_whitespace) => {
                    let limit = arguments["limit"].as_u64().unwrap_or(50);
                    self.held_command(thread, &format!("peek {relation} {limit}")).await
                }
                _ => Err("peek names one relation, e.g. `path`".to_owned()),
            },
            "why" => match text("fact") {
                None => self.inspect(thread, "why").await,
                Some(fact) if fact.starts_with('(') => self.inspect(thread, &format!("why {fact}")).await,
                Some(_) => Err("a fact is written `(path 1 4)`".to_owned()),
            },
            "whynot" => match text("fact") {
                Some(fact) if fact.starts_with('(') => self.inspect(thread, &format!("whynot {fact}")).await,
                _ => Err("whynot names a fact, e.g. `(path 1 4)`".to_owned()),
            },
            _ => return None,
        };
        Some(result.map(|value| self.unhide(value)))
    }

    /// Evaluate `thread`'s proposed program on the preview lane with its
    /// trace armed: its relations, and its trace's summary.
    async fn trace_fork(&self, thread: u32) -> Result<Value, String> {
        let mut preview = self.preview_session.lock().await;
        let (session, loaded) = &mut *preview;
        let (outcomes, ok, hash) = self.evaluate_fork_in(&self.preview, session, thread, &[ARM.to_owned()]).await;
        *loaded = ok.then_some((thread, hash));
        let mut report = fork_report(&outcomes, ok);
        if let Some(trace) = outcomes.iter().find(|outcome| outcome.line.starts_with("run ")).and_then(trace_of) {
            report["trace"] = summary(trace);
            self.debugger.keep(thread, trace);
        }
        Ok(report)
    }

    /// Evaluate `thread`'s proposed program on the debug lane, traced, with a
    /// break at each of its breakpoints: where it stopped, or, when it ran
    /// to the end, what trace_run reports.
    async fn debug_fork(&self, thread: u32) -> Result<Value, String> {
        let lines = self.debugger.breakpoints.lock().expect("breakpoints lock").get(&thread).cloned().unwrap_or_default();
        if lines.is_empty() {
            return Err("no breakpoints: set_breakpoint first (trace_run traces a run without stopping)".to_owned());
        }
        let path = self.preview_path();
        let path = run_argument(&path).ok_or("the program's directory cannot be named by `break`")?;
        let prepare: Vec<String> = [ARM.to_owned(), "calls on".to_owned()]
            .into_iter()
            .chain(lines.iter().map(|point| point.command(path)))
            .collect();
        let mut debug = self.debugger.session.lock().await;
        let (session, loaded) = &mut *debug;
        let (outcomes, ok, hash) = self.evaluate_fork_in(&self.debugger.lane, session, thread, &prepare).await;
        *loaded = ok.then_some((thread, hash));
        if !ok {
            return Ok(fork_report(&outcomes, false));
        }
        let run = outcomes.iter().find(|outcome| outcome.line.starts_with("run "));
        let breaks: Vec<Value> = outcomes
            .iter()
            .filter(|outcome| outcome.line.starts_with("break "))
            .filter_map(|outcome| outcome.result.as_ref().map(said))
            .collect();
        if session.view().held {
            return Ok(json!({
                "ok": true,
                "held": true,
                "stopped": run.and_then(|run| run.result.as_ref()).map(said),
                "breaks": breaks,
                "next": "frames, peek, why, whynot inspect the stop; step, continue or abort move on",
            }));
        }
        let mut report = fork_report(&outcomes, true);
        report["breaks"] = json!(breaks);
        report["note"] = json!("the run completed without reaching a breakpoint");
        if let Some(trace) = run.and_then(trace_of) {
            report["trace"] = summary(trace);
            self.debugger.keep(thread, trace);
        }
        Ok(report)
    }

    /// Send `line` to `thread`'s held debug run.
    async fn held_command(&self, thread: u32, line: &str) -> Result<Value, String> {
        let mut debug = self.debugger.session.lock().await;
        let (session, loaded) = &mut *debug;
        if !session.view().held || !loaded.is_some_and(|(holder, _)| holder == thread) {
            return Err("no run of yours is held: debug_run stops one at your breakpoints".to_owned());
        }
        let outcome = session.execute(&self.debugger.lane, line).await;
        let result = match (outcome.result, outcome.error) {
            (Some(result), _) => result,
            (None, Some(error)) => return Err(error.message),
            (None, None) => return Err("no answer".to_owned()),
        };
        if line == "abort" {
            // The run is gone, and the program with it.
            *loaded = None;
        }
        let mut answer = said(&result);
        answer["held"] = json!(session.view().held);
        if let Some(trace) = result.get("change").and_then(|change| change.get("trace")) {
            answer["trace"] = summary(trace);
            self.debugger.keep(thread, trace);
        }
        Ok(answer)
    }

    /// `why` or `whynot` against `thread`'s debug run when the debug lane
    /// holds its program as it stands, else against the preview lane's
    /// evaluation of it.
    async fn inspect(&self, thread: u32, line: &str) -> Result<Value, String> {
        let mut debug = self.debugger.session.lock().await;
        let (session, loaded) = &mut *debug;
        if *loaded != Some((thread, self.fork_hash(thread))) {
            drop(debug);
            return self.preview_line(thread, line).await;
        }
        let outcome = session.execute(&self.debugger.lane, line).await;
        match (outcome.result, outcome.error) {
            (Some(result), _) => Ok(said(&result)),
            (None, Some(error)) => Err(error.message),
            (None, None) => Err("no answer".to_owned()),
        }
    }

    /// Set or clear a breakpoint: at `at` (`LINE` or `FILE:LINE` of the
    /// proposed program), on a `clause`, or both, narrowed by `condition`,
    /// `ignore` and `log`.
    fn agent_breakpoint(&self, thread: u32, arguments: &Value, set: bool) -> Result<Value, String> {
        let program = self.main_name();
        let text = |key: &str| arguments[key].as_str().map(str::trim).filter(|value| !value.is_empty());
        let line = match text("at") {
            None => None,
            Some(at) => {
                let line = match at.rsplit_once(':') {
                    Some((file, line)) if file == program => line,
                    Some((file, _)) => return Err(format!("{file} is not the program; its file is {program}")),
                    None => at,
                };
                Some(line.parse().ok().filter(|&line: &u32| line > 0).ok_or_else(|| format!("{at:?} names no line"))?)
            }
        };
        let mut rest = text("clause").unwrap_or("").to_owned();
        if line.is_none() && rest.is_empty() {
            return Err("give `at` (a rule's line), `clause` (e.g. \"demand (infer _ (app _ _))\"), or both".to_owned());
        }
        if let Some(condition) = text("condition") {
            rest += &format!(" when {condition}");
        }
        if let Some(ignore) = arguments["ignore"].as_u64().filter(|&n| n > 0) {
            rest += &format!(" ignore {ignore}");
        }
        if arguments["log"].as_bool() == Some(true) {
            rest += " log";
        }
        let point = AgentBreak { line, rest: rest.trim().to_owned() };
        let mut breakpoints = self.debugger.breakpoints.lock().expect("breakpoints lock");
        let points = breakpoints.entry(thread).or_default();
        if set {
            points.insert(point);
        } else {
            points.retain(|p| p.line != point.line || (!point.rest.is_empty() && p.rest != point.rest));
        }
        Ok(json!({
            "breakpoints": points.iter().map(|p| p.command(&program).trim_start_matches("break ").to_owned()).collect::<Vec<_>>(),
            "note": "a debug_run stops at the first of these a rule reaches; a breakpoint that cannot stop says why after the run (`breaks` in its result)",
        }))
    }

    /// Drill into the thread's latest trace: the strata, iterations and
    /// relations the filters select, with their sampled rows and fired rules.
    fn get_trace(&self, thread: u32, arguments: &Value) -> Result<Value, String> {
        let traces = self.debugger.traces.lock().expect("traces lock");
        let trace = traces.get(&thread).ok_or("no trace yet: trace_run records one")?;
        let stratum = arguments["stratum"].as_u64();
        let iteration = arguments["iteration"].as_u64();
        let relation = arguments["relation"].as_str();
        let strata: Vec<Value> = strata(trace)
            .iter()
            .enumerate()
            .filter(|(index, _)| stratum.is_none_or(|wanted| wanted == *index as u64 + 1))
            .filter_map(|(index, st)| {
                let iterations: Vec<Value> = list(&st["iterations"])
                    .iter()
                    .filter(|it| iteration.is_none_or(|wanted| it["iteration"].as_u64() == Some(wanted)))
                    .map(|it| iteration_detail(it, relation))
                    .filter(|it| relation.is_none() || !it["relations"].as_array().is_none_or(Vec::is_empty))
                    .collect();
                (!iterations.is_empty()).then(|| {
                    json!({ "stratum": index + 1, "name": st["stratum"], "flavor": st["flavor"], "iterations": iterations })
                })
            })
            .collect();
        if strata.is_empty() {
            return Err(format!("nothing in the trace matches; it has {} strata", self::strata(trace).len()));
        }
        Ok(json!({ "strata": strata, "dropped": trace["dropped"] }))
    }

    /// The preview copy's hidden file name, wherever a result mentions it,
    /// read as the program's own, whose lines it shares.
    fn unhide(&self, value: Value) -> Value {
        let program = self.main_name();
        let hidden = self.preview_path().file_name().map(|name| name.to_string_lossy().into_owned()).unwrap_or_default();
        fn walk(value: Value, hidden: &str, program: &str) -> Value {
            match value {
                Value::String(text) => Value::String(text.replace(hidden, program)),
                Value::Array(items) => items.into_iter().map(|item| walk(item, hidden, program)).collect(),
                Value::Object(fields) => {
                    Value::Object(fields.into_iter().map(|(key, item)| (key, walk(item, hidden, program))).collect())
                }
                other => other,
            }
        }
        walk(value, &hidden, &program)
    }
}

/// A result's title and text lines.
fn said(result: &Value) -> Value {
    json!({ "title": result["title"], "lines": result["lines"] })
}

/// The trace a run's change record carries.
fn trace_of(outcome: &Outcome) -> Option<&Value> {
    outcome.result.as_ref()?.get("change")?.get("trace")
}

fn list(value: &Value) -> &[Value] {
    value.as_array().map(Vec::as_slice).unwrap_or_default()
}

fn strata(trace: &Value) -> &[Value] {
    list(&trace["strata"])
}

fn count(value: &Value, key: &str) -> u64 {
    value[key].as_u64().unwrap_or(0)
}

/// Compiler temporaries and bookkeeping relations: counted, never sampled,
/// and left out unless asked for (repl.rkt `internal-relation?`).
fn internal(name: &str) -> bool {
    name.starts_with('$') || name.starts_with("temp") || name == "_enum"
}

/// "path +3 -1 ~2": one relation's signed change in one iteration.
fn delta_text(relation: &Value) -> String {
    let mut text = relation["relation"].as_str().unwrap_or("?").to_owned();
    for (key, sign) in [("plus", "+"), ("minus", "-"), ("dups", "~")] {
        let n = count(relation, key);
        if n > 0 {
            text += &format!(" {sign}{n}");
        }
    }
    text
}

/// What an agent first needs of a trace: each stratum's iterations as
/// signed deltas, the relations it wrote, and the rules that fired most.
pub fn summary(trace: &Value) -> Value {
    let mut hot: BTreeMap<&str, (u64, u64)> = BTreeMap::new();
    let strata: Vec<Value> = strata(trace)
        .iter()
        .enumerate()
        .map(|(index, st)| {
            let mut writes = BTreeSet::new();
            let deltas: Vec<String> = list(&st["iterations"])
                .iter()
                .map(|it| {
                    for rule in list(&it["rules"]) {
                        let entry = hot.entry(rule["loc"].as_str().unwrap_or("?")).or_default();
                        entry.0 += count(rule, "fires");
                        entry.1 += count(rule, "work");
                    }
                    let parts: Vec<String> = list(&it["relations"])
                        .iter()
                        .filter(|relation| !relation["relation"].as_str().is_some_and(internal))
                        .inspect(|relation| {
                            writes.insert(relation["relation"].as_str().unwrap_or("?"));
                        })
                        .map(delta_text)
                        .collect();
                    if parts.is_empty() { "no change".to_owned() } else { parts.join(", ") }
                })
                .collect();
            json!({
                "stratum": index + 1,
                "name": st["stratum"],
                "flavor": st["flavor"],
                "ms": st["fixpoint"]["ms"],
                "writes": writes,
                "deltas": deltas,
            })
        })
        .collect();
    let mut hot: Vec<(&str, (u64, u64))> = hot.into_iter().filter(|(_, (fires, _))| *fires > 0).collect();
    hot.sort_by(|a, b| b.1.cmp(&a.1));
    let hot_rules: Vec<Value> =
        hot.iter().take(5).map(|(loc, (fires, work))| json!({ "rule": loc, "fires": fires, "work": work })).collect();
    json!({
        "strata": strata,
        "hot_rules": hot_rules,
        "dropped_samples": trace["dropped"],
        "legend": LEGEND,
        "more": "get_trace {stratum, iteration, relation} shows sampled rows and fires per rule",
    })
}

/// One iteration: its relations (only `relation` if named, else the
/// program's own) with their sampled rows, and the rules that fired.
fn iteration_detail(iteration: &Value, relation: Option<&str>) -> Value {
    let relations: Vec<Value> = list(&iteration["relations"])
        .iter()
        .filter(|r| {
            let name = r["relation"].as_str().unwrap_or("");
            relation.map_or(!internal(name), |wanted| wanted == name)
        })
        .map(|r| {
            let name = r["relation"].as_str().unwrap_or("?");
            let sample: Vec<String> = list(&r["sample"])
                .iter()
                .map(|row| {
                    let kind = row["kind"].as_str().unwrap_or("none");
                    let sign = row["sign"].as_str().unwrap_or("?");
                    let row = row["row"].as_str().unwrap_or("");
                    // as `peek` spells a delta row
                    if kind == "none" { format!("{sign}({name} {row})") } else { format!("{sign}({name} {row}) · {kind}") }
                })
                .collect();
            json!({
                "relation": name,
                "delta": delta_text(r),
                "size_after": r["size-after"],
                "kinds": r["kinds"],
                "sample": sample,
                "sample_omitted": r["sample-omitted"],
            })
        })
        .collect();
    let rules: Vec<Value> = list(&iteration["rules"])
        .iter()
        .filter(|rule| count(rule, "fires") > 0 || count(rule, "work") > 0)
        .map(|rule| json!({ "rule": rule["loc"], "variant": rule["tag"], "fires": rule["fires"], "work": rule["work"] }))
        .collect();
    json!({ "iteration": iteration["iteration"], "relations": relations, "rules": rules })
}

/// The trace tools' MCP descriptions.
pub fn tools() -> Vec<Value> {
    let object = |properties: Value, required: &[&str]| {
        json!({ "type": "object", "properties": properties, "required": required })
    };
    let none = || object(json!({}), &[]);
    let fact = |what: &str| json!({ "type": "string", "description": what });
    let at = json!({ "type": "string", "description": "A line of get_program's text where a rule starts, as \"14\" or \"FILE:14\"." });
    vec![
        json!({
            "name": "trace_run",
            "description": "Evaluate your proposed program, as evaluate_proposal does, recording its execution: each stratum (flavor, ms, the relations it writes) and each iteration's signed delta per relation, plus the rules that fired most. Use it when something derives wrongly or not at all, before guessing.",
            "inputSchema": none(),
        }),
        json!({
            "name": "get_trace",
            "description": "Drill into the latest trace from trace_run (or a debug run that completed): sampled rows with their sign and kind (input, nonrec, rec) and the rules that fired, for the strata, iterations and relation you name. Strata are numbered as trace_run lists them.",
            "inputSchema": object(json!({
                "stratum": { "type": "integer", "description": "The stratum's number in trace_run's list." },
                "iteration": { "type": "integer", "description": "The iteration, from 1." },
                "relation": { "type": "string", "description": "One relation's name." },
            }), &[]),
        }),
        json!({
            "name": "set_breakpoint",
            "description": "Stop debug_run where a rule of your proposed program fires (`at` its line), or at one clause: `clause` is `demand (f t ...)` (f is asked of a matching call), `answer (f t ... a ...)` (such a call is answered), `match (R t ...)` or `emit (R t ...)`. Patterns are Slog terms: `_`, variables, constructors `(app _ _)`, lists `[a g ...]`; with `at`, a variable the rule binds means the rule's value. `condition` is guards `(OP a b)` over the pattern's and the rule's variables; `ignore` skips that many hits; `log` records hits (the `logs` tool) without stopping.",
            "inputSchema": object(json!({
                "at": at,
                "clause": { "type": "string", "description": "e.g. \"demand (infer _ (app _ _))\" or \"answer (nf T T)\"" },
                "condition": { "type": "string", "description": "e.g. \"(/= T V) (< n 3)\"" },
                "ignore": { "type": "integer" },
                "log": { "type": "boolean" },
            }), &[]),
        }),
        json!({
            "name": "clear_breakpoint",
            "description": "Remove breakpoints set_breakpoint set: every one at `at`, or the one with this `clause` there.",
            "inputSchema": object(json!({ "at": at, "clause": { "type": "string" } }), &[]),
        }),
        json!({
            "name": "calls",
            "description": "A debug run's demand calls (it records them): with nothing, the calls no rule asked and where failure starts (calls without an answer whose subcalls all have one -- failure is absence); `call` (\"#3\" or the call written out) for one call's answers, the stratum and iteration they were found in, and its subcalls to `depth`; `view` \"stack\" for the chain of calls a held run is in, \"failed\" for the failures.",
            "inputSchema": object(json!({
                "call": { "type": "string" },
                "depth": { "type": "integer" },
                "view": { "type": "string", "enum": ["stack", "failed"] },
            }), &[]),
        }),
        json!({
            "name": "logs",
            "description": "What the logpoints (set_breakpoint with log) recorded in the latest debug run.",
            "inputSchema": none(),
        }),
        json!({
            "name": "debug_run",
            "description": "Evaluate your proposed program from nothing and stop at the first breakpoint a rule reaches. The run stays held: inspect it with frames, peek, why and whynot, then step, continue or abort. A run that completes reports its trace as trace_run does.",
            "inputSchema": none(),
        }),
        json!({
            "name": "step",
            "description": "Move the held run to its next interpreter port, or to the next port of one kind.",
            "inputSchema": object(json!({
                "grain": { "type": "string", "enum": ["match", "fire", "emit", "tuple", "into", "over", "out"], "description": "Which port to stop at; any port if omitted. At a demand call: into it, over it to its answer, or out to the answer of the call the run is inside." },
            }), &[]),
        }),
        json!({
            "name": "continue",
            "description": "Resume the held run until the next breakpoint or the end; at the end its trace summary is returned.",
            "inputSchema": none(),
        }),
        json!({
            "name": "peek",
            "description": "A relation's delta at the held run's stop: the iteration's signed change, or at a rule's port the read's pending candidates.",
            "inputSchema": object(json!({
                "relation": { "type": "string" },
                "limit": { "type": "integer", "description": "Rows to show (default 50)." },
            }), &["relation"]),
        }),
        json!({
            "name": "frames",
            "description": "The held run's join stack at its stop: the rule, its variable bindings, and the rows matched at each body position.",
            "inputSchema": none(),
        }),
        json!({
            "name": "why",
            "description": "The proof tree for a fact of your proposed program's evaluation; with no fact, at a held run's stop, for the candidates there.",
            "inputSchema": object(json!({ "fact": fact("A fact, e.g. `(path 1 4)`.") }), &[]),
        }),
        json!({
            "name": "whynot",
            "description": "Why a fact is NOT derived: for each rule that could derive it, the first body position with nothing to match.",
            "inputSchema": object(json!({ "fact": fact("A fact, e.g. `(path 1 5)`.") }), &["fact"]),
        }),
        json!({
            "name": "abort",
            "description": "Discard the held run; nothing of it is kept.",
            "inputSchema": none(),
        }),
    ]
}

#[cfg(test)]
mod tests {
    use crate::lane::Mode;
    use crate::registry::{LOCAL_USER, Registry};
    use axum::http::{HeaderMap, HeaderValue, header};
    use serde_json::{Value, json};
    use slog_repl::server::project_root;

    /// The agent traces and debugs its proposed program through `/mcp`, on a
    /// real session server. reach.slog's chain 1-2-3-4 grows `path` by 3, 2
    /// and 1, then reaches its fixpoint in an empty fourth iteration.
    #[tokio::test]
    async fn an_agent_traces_and_debugs_through_mcp() {
        let data = std::env::temp_dir().join(format!("studio-trace-{}", std::process::id()));
        std::fs::create_dir_all(&data).expect("temporary directory");
        let root = project_root().expect("repository root");
        let file = data.join("reach.slog");
        std::fs::copy(root.join("tests/reach.slog"), &file).expect("the program");
        let registry = Registry::new(root, data.clone(), Mode::Fast, Some(file), None);
        let studio = registry.open(LOCAL_USER, "").expect("the studio");
        let thread = studio.review.lock().expect("review lock").new_thread("why".into());
        let call = async |name: &str, arguments: Value| -> Value {
            let mut headers = HeaderMap::new();
            let bearer = format!("Bearer {}", studio.agent.mcp_token);
            headers.insert(header::AUTHORIZATION, HeaderValue::from_str(&bearer).unwrap());
            headers.insert(crate::agent::THREAD_HEADER, HeaderValue::from(thread));
            let body = json!({ "jsonrpc": "2.0", "id": 1, "method": "tools/call",
                               "params": { "name": name, "arguments": arguments } });
            let response = crate::mcp::handle(&registry, headers, body.to_string()).await;
            let bytes = axum::body::to_bytes(response.into_body(), usize::MAX).await.expect("a body");
            let answer: Value = serde_json::from_slice(&bytes).expect("JSON-RPC");
            let result = &answer["result"];
            assert_eq!(result["isError"], false, "{name}: {}", result["content"][0]["text"]);
            result["structuredContent"].clone()
        };

        let run = call("trace_run", json!({})).await;
        let strata = run["trace"]["strata"].as_array().expect("strata");
        let path = strata.iter().find(|st| st["writes"] == json!(["path"])).expect("path's stratum");
        assert_eq!(path["deltas"], json!(["path +3", "path +2", "path +1", "no change"]));
        // the base rule fires once per edge; the recursive one 2 + 1 times
        assert_eq!(
            run["trace"]["hot_rules"],
            json!([{ "rule": "reach.slog:14:1", "fires": 3, "work": 3 },
                   { "rule": "reach.slog:9:1", "fires": 3, "work": 0 },
                   { "rule": "reach.slog:4:1", "fires": 1, "work": 0 }])
        );

        let detail = call("get_trace", json!({ "stratum": path["stratum"], "iteration": 2, "relation": "path" })).await;
        let iteration = &detail["strata"][0]["iterations"][0];
        let mut sample: Vec<&str> =
            iteration["relations"][0]["sample"].as_array().unwrap().iter().filter_map(Value::as_str).collect();
        sample.sort();
        assert_eq!(sample, ["+(path 1 3)", "+(path 2 4)"]);
        assert_eq!(iteration["rules"][0]["rule"], "reach.slog:14:1");

        // stop in the recursive rule; locations name the program, not the
        // hidden copy the debug lane runs
        call("set_breakpoint", json!({ "at": "reach.slog:14" })).await;
        let stop = call("debug_run", json!({})).await;
        assert_eq!(stop["held"], true, "{stop}");
        assert!(stop["stopped"]["lines"].to_string().contains("fire@reach.slog:14:1"), "{stop}");
        let frames = call("frames", json!({})).await;
        assert!(frames["lines"].to_string().contains("reach.slog:14:1"), "{frames}");
        call("clear_breakpoint", json!({ "at": "14" })).await;
        let aborted = call("abort", json!({})).await;
        assert_eq!(aborted["held"], false);

        studio.preview.shutdown().await;
        studio.debugger.lane.shutdown().await;
        studio.lane.shutdown().await;
        std::fs::remove_dir_all(data).expect("cleanup");
    }

    /// The agent debugs a demand program a call at a time: a pattern
    /// breakpoint on a call that does not exist until the run builds it,
    /// the stack it stops in, a step into it, and the call tree with the
    /// ill-typed program's missing answer.
    #[tokio::test]
    async fn an_agent_debugs_demand_calls_through_mcp() {
        let data = std::env::temp_dir().join(format!("studio-calls-{}", std::process::id()));
        std::fs::create_dir_all(&data).expect("temporary directory");
        let root = project_root().expect("repository root");
        let file = data.join("stlc.slog");
        std::fs::copy(root.join("tests/dem_stlc.slog"), &file).expect("the program");
        let registry = Registry::new(root, data.clone(), Mode::Fast, Some(file), None);
        let studio = registry.open(LOCAL_USER, "").expect("the studio");
        let thread = studio.review.lock().expect("review lock").new_thread("calls".into());
        let call = async |name: &str, arguments: Value| -> Value {
            let mut headers = HeaderMap::new();
            let bearer = format!("Bearer {}", studio.agent.mcp_token);
            headers.insert(header::AUTHORIZATION, HeaderValue::from_str(&bearer).unwrap());
            headers.insert(crate::agent::THREAD_HEADER, HeaderValue::from(thread));
            let body = json!({ "jsonrpc": "2.0", "id": 1, "method": "tools/call",
                               "params": { "name": name, "arguments": arguments } });
            let response = crate::mcp::handle(&registry, headers, body.to_string()).await;
            let bytes = axum::body::to_bytes(response.into_body(), usize::MAX).await.expect("a body");
            let answer: Value = serde_json::from_slice(&bytes).expect("JSON-RPC");
            let result = &answer["result"];
            assert_eq!(result["isError"], false, "{name}: {}", result["content"][0]["text"]);
            result["structuredContent"].clone()
        };

        call("set_breakpoint", json!({ "clause": "demand (ck _ (app (num 3) _))" })).await;
        let stop = call("debug_run", json!({})).await;
        assert_eq!(stop["held"], true, "{stop}");
        let stack = call("calls", json!({ "view": "stack" })).await;
        assert!(stack["lines"].to_string().contains("(ck (mt) (app (num 3) (num 4)))"), "{stack}");
        let into = call("step", json!({ "grain": "into" })).await;
        assert!(into["lines"].to_string().contains("demand ask of (ck (mt) (num 3))"), "{into}");
        call("clear_breakpoint", json!({ "clause": "demand (ck _ (app (num 3) _))" })).await;
        call("continue", json!({})).await;
        let tree = call("calls", json!({})).await;
        let lines = tree["lines"].to_string();
        assert!(lines.contains("where failure starts"), "{tree}");
        assert!(lines.contains("(ck (mt) (app (num 3) (num 4)))  · no answer"), "{tree}");

        studio.preview.shutdown().await;
        studio.debugger.lane.shutdown().await;
        studio.lane.shutdown().await;
        std::fs::remove_dir_all(data).expect("cleanup");
    }
}
